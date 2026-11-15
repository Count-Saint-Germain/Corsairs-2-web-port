#include "recomp.h"

void f_00a556db(CPU *c) { /* FUN_100056db */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x140u; PUSH32(c, v_); } /* push 0x140 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa59044u)); PUSH32(c, 0x00a556eeu); call_indirect(c, t_); } /* call dword ptr [0x10009044] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xa5d4bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4bc], eax */
    if (!c->zf) goto L_00a556f8; /* jne 0xa556f8 */
    c->esp += 4; return; /* ret  */
L_00a556f8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xa5d4b4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d4b4], 0 */
    { uint32_t a_ = (uint32_t)(0xa5d4b8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d4b8], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xa5d4b0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4b0], eax */
    W32((uint32_t)(0xa5d4c0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000d4c0], ecx */
    W32((uint32_t)(0xa5d4a8u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [0x1000d4a8], 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a55723(CPU *c) { /* FUN_10005723 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b8u))); /* mov eax, dword ptr [0x1000d4b8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4bcu))); /* mov eax, dword ptr [0x1000d4bc] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
L_00a55733:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00a5574b; /* jae 0xa5574b */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->eax + 0xcu)))); /* sub edx, dword ptr [eax + 0xc] */
    (void)sub32(c, c->edx, (uint32_t)0x100000u); /* cmp edx, 0x100000 */
    if (c->cf) goto L_00a5574d; /* jb 0xa5574d */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x14u)); /* add eax, 0x14 */
    goto L_00a55733; /* jmp 0xa55733 */
L_00a5574b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a5574d:;
    c->esp += 4; return; /* ret  */
}

void f_00a5574e(CPU *c) { /* FUN_1000574e */
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
    if (!c->zf) goto L_00a55a72; /* jne 0xa55a72 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi))); /* mov edx, dword ptr [ecx + esi] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea ebx, [ecx + esi] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov edx, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0xc], ebx */
    if (!c->zf) goto L_00a55824; /* jne 0xa55824 */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00a557b2; /* jbe 0xa557b2 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00a557b2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx + 0x8u))); /* cmp ecx, dword ptr [ebx + 8] */
    if (!c->zf) goto L_00a55806; /* jne 0xa55806 */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    if (!c->cf) goto L_00a557dd; /* jae 0xa557dd */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00a557fe; /* jne 0xa557fe */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00a557fe; /* jmp 0xa557fe */
L_00a557dd:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00a557fe; /* jne 0xa557fe */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00a557fe:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    goto L_00a55809; /* jmp 0xa55809 */
L_00a55806:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
L_00a55809:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edx, dword ptr [ebx + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebx, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* add ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
L_00a55824:;
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00a55832; /* jbe 0xa55832 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00a55832:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x1u))); /* and ebx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xc], ebx */
    if (!c->zf) goto L_00a558d5; /* jne 0xa558d5 */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(sar32(c, c->ebx, 4)); /* sar ebx, 4 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->cf || c->zf)) goto L_00a55857; /* jbe 0xa55857 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_00a55857:;
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if ((c->cf || c->zf)) goto L_00a55869; /* jbe 0xa55869 */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
L_00a55869:;
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00a558d0; /* je 0xa558d0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ecx + 0x8u))); /* cmp esi, dword ptr [ecx + 8] */
    if (!c->zf) goto L_00a558b8; /* jne 0xa558b8 */
    (void)sub32(c, c->ebx, (uint32_t)0x20u); /* cmp ebx, 0x20 */
    if (!c->cf) goto L_00a55899; /* jae 0xa55899 */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0x44], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00a558b8; /* jne 0xa558b8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx], esi */
    goto L_00a558b8; /* jmp 0xa558b8 */
L_00a55899:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0xffffffe0u)); /* lea ecx, [ebx - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0xc4], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00a558b8; /* jne 0xa558b8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx + 4], esi */
L_00a558b8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
L_00a558d0:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    goto L_00a558d8; /* jmp 0xa558d8 */
L_00a558d5:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a558d8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_00a558e6; /* jne 0xa558e6 */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00a55967; /* je 0xa55967 */
L_00a558e6:;
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
    if (!c->zf) goto L_00a55967; /* jne 0xa55967 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + c->eax + 0x4u))); /* mov cl, byte ptr [edx + eax + 4] */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edx + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax + 4], cl */
    if (!c->cf) goto L_00a5593e; /* jae 0xa5593e */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00a5592d; /* jne 0xa5592d */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00a5592d:;
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0x44u)); /* lea eax, [eax + edi*4 + 0x44] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax], ebx */
    goto L_00a55967; /* jmp 0xa55967 */
L_00a5593e:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00a55954; /* jne 0xa55954 */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00a55954:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0xc4u)); /* lea eax, [eax + edi*4 + 0xc4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00a55967:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->eax + c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax] */
    if (!c->zf) goto L_00a55a72; /* jne 0xa55a72 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a55a64; /* je 0xa55a64 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5d4acu))); /* mov ecx, dword ptr [0x1000d4ac] */
    c->esi = (uint32_t)(R32((uint32_t)(0xa5909cu))); /* mov esi, dword ptr [0x1000909c] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 15)); /* shl ecx, 0xf */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->eax + 0xcu)))); /* add ecx, dword ptr [eax + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x8000u); /* mov ebx, 0x8000 */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a559a8u); call_indirect(c, t_); } /* call esi */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5d4acu))); /* mov ecx, dword ptr [0x1000d4ac] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5d4acu))); /* mov ecx, dword ptr [0x1000d4ac] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + ecx*4 + 0xc4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x43u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [eax + 0x43] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x43u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 0x43], 0 */
    if (!c->zf) goto L_00a559f5; /* jne 0xa559f5 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [eax + 4], 0xfffffffe */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
L_00a559f5:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + 8], -1 */
    if (!c->zf) goto L_00a55a64; /* jne 0xa55a64 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a55a03u); call_indirect(c, t_); } /* call esi */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa5905cu)); PUSH32(c, 0x00a55a19u); call_indirect(c, t_); } /* call dword ptr [0x1000905c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b8u))); /* mov eax, dword ptr [0x1000d4b8] */
    c->edx = (uint32_t)(R32((uint32_t)(0xa5d4bcu))); /* mov edx, dword ptr [0x1000d4bc] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b4u))); /* mov eax, dword ptr [0x1000d4b4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffffecu)); /* lea ecx, [ecx + edx - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x14u)); /* lea ecx, [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a55a42u); f_00a551d0(c); /* call 0xa551d0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(0xa5d4b8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x1000d4b8] */
    (void)sub32(c, c->eax, R32((uint32_t)(0xa5d4b4u))); /* cmp eax, dword ptr [0x1000d4b4] */
    if ((c->cf || c->zf)) goto L_00a55a5a; /* jbe 0xa55a5a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x14u))); } /* sub dword ptr [ebp + 8], 0x14 */
L_00a55a5a:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4bcu))); /* mov eax, dword ptr [0x1000d4bc] */
    W32((uint32_t)(0xa5d4b0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4b0], eax */
L_00a55a64:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xa5d4acu), (uint32_t)(c->edi)); /* mov dword ptr [0x1000d4ac], edi */
    W32((uint32_t)(0xa5d4b4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4b4], eax */
L_00a55a72:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a55a77(CPU *c) { /* FUN_10005a77 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b8u))); /* mov eax, dword ptr [0x1000d4b8] */
    c->edx = (uint32_t)(R32((uint32_t)(0xa5d4bcu))); /* mov edx, dword ptr [0x1000d4bc] */
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
    if ((c->sf == c->of)) goto L_00a55ab7; /* jge 0xa55ab7 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    goto L_00a55ac7; /* jmp 0xa55ac7 */
L_00a55ab7:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00a55ac7:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b0u))); /* mov eax, dword ptr [0x1000d4b0] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00a55aee; /* jae 0xa55aee */
L_00a55ad5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00a55aee; /* jne 0xa55aee */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->cf) goto L_00a55ad5; /* jb 0xa55ad5 */
L_00a55aee:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00a55b6c; /* jne 0xa55b6c */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00a55af5:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00a55b11; /* jae 0xa55b11 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00a55b0f; /* jne 0xa55b0f */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00a55af5; /* jmp 0xa55af5 */
L_00a55b0f:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00a55b11:;
    if (!c->zf) goto L_00a55b6c; /* jne 0xa55b6c */
L_00a55b13:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->cf) goto L_00a55b29; /* jae 0xa55b29 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00a55b26; /* jne 0xa55b26 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    goto L_00a55b13; /* jmp 0xa55b13 */
L_00a55b26:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
L_00a55b29:;
    if (!c->zf) goto L_00a55b51; /* jne 0xa55b51 */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00a55b2d:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00a55b41; /* jae 0xa55b41 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00a55b3f; /* jne 0xa55b3f */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00a55b2d; /* jmp 0xa55b2d */
L_00a55b3f:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00a55b41:;
    if (!c->zf) goto L_00a55b51; /* jne 0xa55b51 */
    PUSH32(c, 0x00a55b48u); f_00a55d80(c); /* call 0xa55d80 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->zf) goto L_00a55b65; /* je 0xa55b65 */
L_00a55b51:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a55b57u); f_00a55e31(c); /* call 0xa55e31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00a55b6c; /* jne 0xa55b6c */
L_00a55b65:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a55d7b; /* jmp 0xa55d7b */
L_00a55b6c:;
    W32((uint32_t)(0xa5d4b0u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000d4b0], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    if (c->zf) goto L_00a55b93; /* je 0xa55b93 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov edi, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00a55bca; /* jne 0xa55bca */
L_00a55b93:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xc4u))); /* mov edx, dword ptr [eax + 0xc4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov esi, dword ptr [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & R32((uint32_t)(c->ebp + 0xfffffff4u))))); /* and esi, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x44u)); /* lea ecx, [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->esi))); /* or edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    if (!c->zf) goto L_00a55bc7; /* jne 0xa55bc7 */
L_00a55bb0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edx, dword ptr [ecx + 0x84] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & R32((uint32_t)(c->ecx))))); /* and edi, dword ptr [ecx] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->edi))); /* or edx, edi */
    if (c->zf) goto L_00a55bb0; /* je 0xa55bb0 */
L_00a55bc7:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
L_00a55bca:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov ecx, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->esi))); /* and ecx, esi */
    if (!c->zf) goto L_00a55bf3; /* jne 0xa55bf3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a55bf3:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf != c->of)) goto L_00a55bfc; /* jl 0xa55bfc */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a55bf3; /* jmp 0xa55bf3 */
L_00a55bfc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [ecx + edi*8 + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_00a55c19; /* jle 0xa55c19 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a55c19:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00a55d2e; /* je 0xa55d2e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x8u))); /* cmp ecx, dword ptr [edx + 8] */
    if (!c->zf) goto L_00a55c8a; /* jne 0xa55c8a */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if ((c->sf == c->of)) goto L_00a55c59; /* jge 0xa55c59 */
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
    if (!c->zf) goto L_00a55c87; /* jne 0xa55c87 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx], ecx */
    goto L_00a55c8a; /* jmp 0xa55c8a */
L_00a55c59:;
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
    if (!c->zf) goto L_00a55c87; /* jne 0xa55c87 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx + 4], ecx */
    goto L_00a55c8a; /* jmp 0xa55c8a */
L_00a55c87:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a55c8a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ecx, dword ptr [edx + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    if (c->zf) goto L_00a55d3a; /* je 0xa55d3a */
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
    if (!c->zf) goto L_00a55d2b; /* jne 0xa55d2b */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xbu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xb], cl */
    if ((c->sf == c->of)) goto L_00a55cfc; /* jge 0xa55cfc */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00a55cea; /* jne 0xa55cea */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx], edi */
L_00a55cea:;
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + ecx*4 + 0x44], edi */
    goto L_00a55d2b; /* jmp 0xa55d2b */
L_00a55cfc:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00a55d15; /* jne 0xa55d15 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx + 4], edi */
L_00a55d15:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx * 4 + 0xc4u)); /* lea edi, [eax + ecx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->esi)))); } /* or dword ptr [edi], esi */
L_00a55d2b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00a55d2e:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a55d3d; /* je 0xa55d3d */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->ecx + c->edx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + edx - 4], ecx */
    goto L_00a55d3d; /* jmp 0xa55d3d */
L_00a55d3a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00a55d3d:;
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
    if (!c->zf) goto L_00a55d73; /* jne 0xa55d73 */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xa5d4b4u))); /* cmp ebx, dword ptr [0x1000d4b4] */
    if (!c->zf) goto L_00a55d73; /* jne 0xa55d73 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0xa5d4acu))); /* cmp ecx, dword ptr [0x1000d4ac] */
    if (!c->zf) goto L_00a55d73; /* jne 0xa55d73 */
    { uint32_t a_ = (uint32_t)(0xa5d4b4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d4b4], 0 */
L_00a55d73:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea eax, [edx + 4] */
L_00a55d7b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a55d80(CPU *c) { /* FUN_10005d80 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b8u))); /* mov eax, dword ptr [0x1000d4b8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5d4a8u))); /* mov ecx, dword ptr [0x1000d4a8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00a55dc3; /* jne 0xa55dc3 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4 + 0x50u)); /* lea eax, [ecx + ecx*4 + 0x50] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xa5d4bcu)); PUSH32(c, v_); } /* push dword ptr [0x1000d4bc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa59040u)); PUSH32(c, 0x00a55daeu); call_indirect(c, t_); } /* call dword ptr [0x10009040] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00a55e13; /* je 0xa55e13 */
    { uint32_t a_ = (uint32_t)(0xa5d4a8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [0x1000d4a8], 0x10 */
    W32((uint32_t)(0xa5d4bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4bc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d4b8u))); /* mov eax, dword ptr [0x1000d4b8] */
L_00a55dc3:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5d4bcu))); /* mov ecx, dword ptr [0x1000d4bc] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    { uint32_t t_ = R32((uint32_t)(0xa59044u)); PUSH32(c, 0x00a55de2u); call_indirect(c, t_); } /* call dword ptr [0x10009044] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    if (c->zf) goto L_00a55e13; /* je 0xa55e13 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa590b8u)); PUSH32(c, 0x00a55dfcu); call_indirect(c, t_); } /* call dword ptr [0x100090b8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_00a55e17; /* jne 0xa55e17 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa5905cu)); PUSH32(c, 0x00a55e13u); call_indirect(c, t_); } /* call dword ptr [0x1000905c] */
L_00a55e13:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a55e2e; /* jmp 0xa55e2e */
L_00a55e17:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 8], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t a_ = (uint32_t)(0xa5d4b8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000d4b8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a55e2e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a55e31(CPU *c) { /* FUN_10005e31 */
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
L_00a55e43:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a55e4c; /* jl 0xa55e4c */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00a55e43; /* jmp 0xa55e43 */
L_00a55e4c:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x204u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x204 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi + 0x144u)); /* lea eax, [eax + esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00a55e61:;
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 8], eax */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 4], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00a55e61; /* jne 0xa55e61 */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edi = (uint32_t)(shl32(c, c->edi, 15)); /* shl edi, 0xf */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ecx + 0xcu)))); /* add edi, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa590b8u)); PUSH32(c, 0x00a55e88u); call_indirect(c, t_); } /* call dword ptr [0x100090b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a55e94; /* jne 0xa55e94 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00a55f27; /* jmp 0xa55f27 */
L_00a55e94:;
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x7000u)); /* lea edx, [edi + 0x7000] */
    (void)sub32(c, c->edi, c->edx); /* cmp edi, edx */
    if ((!c->cf && !c->zf)) goto L_00a55eda; /* ja 0xa55eda */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea eax, [edi + 0x10] */
L_00a55ea1:;
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
    if ((c->cf || c->zf)) goto L_00a55ea1; /* jbe 0xa55ea1 */
L_00a55eda:;
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
    if (!c->zf) goto L_00a55f17; /* jne 0xa55f17 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + 4], edi */
L_00a55f17:;
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00a55f27:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a55f2c(CPU *c) { /* FUN_10005f2c */
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
    if ((c->zf || c->sf != c->of)) goto L_00a560da; /* jle 0xa560da */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00a560d3; /* jne 0xa560d3 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ecx)); /* add ebx, ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_00a560d3; /* jg 0xa560d3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if ((c->cf || c->zf)) goto L_00a55fa3; /* jbe 0xa55fa3 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00a55fa3:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ebx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00a55ff3; /* jne 0xa55ff3 */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if (!c->cf) goto L_00a55fcf; /* jae 0xa55fcf */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00a55ff3; /* jne 0xa55ff3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00a55ff3; /* jmp 0xa55ff3 */
L_00a55fcf:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00a55ff3; /* jne 0xa55ff3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00a55ff3:;
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
    if ((c->zf || c->sf != c->of)) goto L_00a560c1; /* jle 0xa560c1 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(sar32(c, c->edi, 4)); /* sar edi, 4 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea ecx, [ecx + esi - 4] */
    (void)sub32(c, c->edi, (uint32_t)0x3fu); /* cmp edi, 0x3f */
    if ((c->cf || c->zf)) goto L_00a5602d; /* jbe 0xa5602d */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a5602d:;
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
    if (!c->zf) goto L_00a560af; /* jne 0xa560af */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + c->eax + 0x4u))); /* mov cl, byte ptr [edi + eax + 4] */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    W8((uint32_t)(c->ebp + 0x13u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0x13], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edi + eax + 4], cl */
    if (!c->cf) goto L_00a56086; /* jae 0xa56086 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00a56079; /* jne 0xa56079 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00a56079:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    goto L_00a560ab; /* jmp 0xa560ab */
L_00a56086:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00a5609c; /* jne 0xa5609c */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00a5609c:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00a560ab:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00a560af:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->esi + 0xfffffffcu)); /* lea eax, [edx + esi - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->ecx + c->eax + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + eax - 4], ecx */
    goto L_00a560c4; /* jmp 0xa560c4 */
L_00a560c1:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
L_00a560c4:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    W32((uint32_t)(c->edx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edx - 4], eax */
    W32((uint32_t)(c->edx + c->esi + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + esi - 8], eax */
    goto L_00a5621a; /* jmp 0xa5621a */
L_00a560d3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a5621d; /* jmp 0xa5621d */
L_00a560da:;
    if ((c->sf == c->of)) goto L_00a5621a; /* jge 0xa5621a */
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
    if ((c->cf || c->zf)) goto L_00a56105; /* jbe 0xa56105 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a56105:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 4], 1 */
    if (!c->zf) goto L_00a56194; /* jne 0xa56194 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00a5611e; /* jbe 0xa5611e */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a5611e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ecx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00a5616d; /* jne 0xa5616d */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    if (!c->cf) goto L_00a56149; /* jae 0xa56149 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea esi, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esi] */
    if (!c->zf) goto L_00a5616a; /* jne 0xa5616a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00a5616a; /* jmp 0xa5616a */
L_00a56149:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea ecx, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00a5616a; /* jne 0xa5616a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00a5616a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
L_00a5616d:;
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
    if ((c->cf || c->zf)) goto L_00a56194; /* jbe 0xa56194 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a56194:;
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
    if (!c->zf) goto L_00a56211; /* jne 0xa56211 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->cf) goto L_00a561e8; /* jae 0xa561e8 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00a561db; /* jne 0xa561db */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx], edi */
L_00a561db:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    goto L_00a5620d; /* jmp 0xa5620d */
L_00a561e8:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00a561fe; /* jne 0xa561fe */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 4], edi */
L_00a561fe:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00a5620d:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00a56211:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(c->eax + c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + ebx - 4], eax */
L_00a5621a:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a5621d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56222(CPU *c) { /* FUN_10006222 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xa5a660u)), (uint32_t)0xffffffffu); /* cmp dword ptr [0x1000a660], -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a56236; /* jne 0xa56236 */
    c->esi = (uint32_t)((uint32_t)0xa5a650u); /* mov esi, 0x1000a650 */
    goto L_00a56253; /* jmp 0xa56253 */
L_00a56236:;
    { uint32_t v_ = 0x2020u; PUSH32(c, v_); } /* push 0x2020 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa59044u)); PUSH32(c, 0x00a56249u); call_indirect(c, t_); } /* call dword ptr [0x10009044] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a5635f; /* je 0xa5635f */
L_00a56253:;
    c->ebp = (uint32_t)(R32((uint32_t)(0xa590b8u))); /* mov ebp, dword ptr [0x100090b8] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x400000u; PUSH32(c, v_); } /* push 0x400000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00a56269u); call_indirect(c, t_); } /* call ebp */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a56348; /* je 0xa56348 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->ebx = (uint32_t)((uint32_t)0x10000u); /* mov ebx, 0x10000 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00a56283u); call_indirect(c, t_); } /* call ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a5633a; /* je 0xa5633a */
    c->eax = (uint32_t)((uint32_t)0xa5a650u); /* mov eax, 0x1000a650 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->zf) goto L_00a562b2; /* jne 0xa562b2 */
    (void)sub32(c, R32((uint32_t)(0xa5a650u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000a650], 0 */
    if (!c->zf) goto L_00a562a2; /* jne 0xa562a2 */
    W32((uint32_t)(0xa5a650u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000a650], eax */
L_00a562a2:;
    (void)sub32(c, R32((uint32_t)(0xa5a654u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000a654], 0 */
    if (!c->zf) goto L_00a562c7; /* jne 0xa562c7 */
    W32((uint32_t)(0xa5a654u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000a654], eax */
    goto L_00a562c7; /* jmp 0xa562c7 */
L_00a562b2:;
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5a654u))); /* mov eax, dword ptr [0x1000a654] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(0xa5a654u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000a654], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_00a562c7:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x400000u)); /* lea eax, [edi + 0x400000] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x98u)); /* lea ecx, [esi + 0x98] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea eax, [esi + 0x18] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)((uint32_t)0xf1u); /* mov ecx, 0xf1 */
L_00a562e9:;
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
    if ((c->sf != c->of)) goto L_00a562e9; /* jl 0xa562e9 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a5630fu); f_00a55170(c); /* call 0xa55170 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00a56312:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00a56336; /* jae 0xa56336 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xf8u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xffu)))); } /* or byte ptr [edi + 0xf8], 0xff */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf0u)); /* mov dword ptr [edi + 4], 0xf0 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x1000u)); /* add edi, 0x1000 */
    goto L_00a56312; /* jmp 0xa56312 */
L_00a56336:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a56361; /* jmp 0xa56361 */
L_00a5633a:;
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa5909cu)); PUSH32(c, 0x00a56348u); call_indirect(c, t_); } /* call dword ptr [0x1000909c] */
L_00a56348:;
    (void)sub32(c, c->esi, (uint32_t)0xa5a650u); /* cmp esi, 0x1000a650 */
    if (c->zf) goto L_00a5635f; /* je 0xa5635f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa5905cu)); PUSH32(c, 0x00a5635fu); call_indirect(c, t_); } /* call dword ptr [0x1000905c] */
L_00a5635f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a56361:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a56366(CPU *c) { /* FUN_10006366 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xa5909cu)); PUSH32(c, 0x00a5637bu); call_indirect(c, t_); } /* call dword ptr [0x1000909c] */
    (void)sub32(c, R32((uint32_t)(0xa5c670u)), c->esi); /* cmp dword ptr [0x1000c670], esi */
    if (!c->zf) goto L_00a5638b; /* jne 0xa5638b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(0xa5c670u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c670], eax */
L_00a5638b:;
    (void)sub32(c, c->esi, (uint32_t)0xa5a650u); /* cmp esi, 0x1000a650 */
    if (c->zf) goto L_00a563b3; /* je 0xa563b3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    { uint32_t v_ = R32((uint32_t)(0xa5d4c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4c4] */
    { uint32_t t_ = R32((uint32_t)(0xa5905cu)); PUSH32(c, 0x00a563b1u); call_indirect(c, t_); } /* call dword ptr [0x1000905c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00a563b3:;
    { uint32_t a_ = (uint32_t)(0xa5a660u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000a660], 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a563bc(CPU *c) { /* FUN_100063bc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xa5a654u))); /* mov esi, dword ptr [0x1000a654] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00a563c9:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi + 0x10], -1 */
    if (c->zf) goto L_00a56467; /* je 0xa56467 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2010u)); /* lea edi, [esi + 0x2010] */
    c->ebx = (uint32_t)((uint32_t)0x3ff000u); /* mov ebx, 0x3ff000 */
L_00a563e2:;
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xf0u); /* cmp dword ptr [edi], 0xf0 */
    if (!c->zf) goto L_00a56423; /* jne 0xa56423 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->esi + 0x10u)))); /* add eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa5909cu)); PUSH32(c, 0x00a56400u); call_indirect(c, t_); } /* call dword ptr [0x1000909c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a56423; /* je 0xa56423 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(0xa5d0d0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x1000d0d0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a56418; /* je 0xa56418 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00a5641b; /* jbe 0xa5641b */
L_00a56418:;
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
L_00a5641b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (c->zf) goto L_00a56430; /* je 0xa56430 */
L_00a56423:;
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x1000u)); /* sub ebx, 0x1000 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x8u)); /* sub edi, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_00a563e2; /* jge 0xa563e2 */
L_00a56430:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    if (c->zf) goto L_00a56467; /* je 0xa56467 */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x18u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + 0x18], -1 */
    if (!c->zf) goto L_00a56467; /* jne 0xa56467 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea eax, [ecx + 0x20] */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00a56447:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00a56458; /* jne 0xa56458 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if ((c->sf != c->of)) goto L_00a56447; /* jl 0xa56447 */
L_00a56458:;
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (!c->zf) goto L_00a56467; /* jne 0xa56467 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00a56466u); f_00a56366(c); /* call 0xa56366 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a56467:;
    (void)sub32(c, c->esi, R32((uint32_t)(0xa5a654u))); /* cmp esi, dword ptr [0x1000a654] */
    if (c->zf) goto L_00a56479; /* je 0xa56479 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a563c9; /* jg 0xa563c9 */
L_00a56479:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a5647e(CPU *c) { /* FUN_1000647e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0xa5a650u); /* mov edx, 0x1000a650 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
L_00a5648a:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x10u))); /* cmp eax, dword ptr [ecx + 0x10] */
    if ((c->cf || c->zf)) goto L_00a56494; /* jbe 0xa56494 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x14u))); /* cmp eax, dword ptr [ecx + 0x14] */
    if (c->cf) goto L_00a5649c; /* jb 0xa5649c */
L_00a56494:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_00a564d1; /* je 0xa564d1 */
    goto L_00a5648a; /* jmp 0xa5648a */
L_00a5649c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu)); /* test al, 0xf */
    if (!c->zf) goto L_00a564d1; /* jne 0xa564d1 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)((uint32_t)0x100u); /* mov edx, 0x100 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffu))); /* and esi, 0xfff */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_00a564d1; /* jb 0xa564d1 */
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
L_00a564d1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a564d5(CPU *c) { /* FUN_100064d5 */
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
    if (!c->zf) goto L_00a56519; /* jne 0xa56519 */
    { uint32_t a_ = (uint32_t)(0xa5d0d0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000d0d0] */
    (void)sub32(c, R32((uint32_t)(0xa5d0d0u)), (uint32_t)0x20u); /* cmp dword ptr [0x1000d0d0], 0x20 */
    if (!c->zf) goto L_00a56519; /* jne 0xa56519 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00a56518u); f_00a563bc(c); /* call 0xa563bc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a56519:;
    c->esp += 4; return; /* ret  */
}

void f_00a5651a(CPU *c) { /* FUN_1000651a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xa5c670u))); /* mov esi, dword ptr [0x1000c670] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00a56528:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (c->zf) goto L_00a565d3; /* je 0xa565d3 */
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
    if (!c->cf) goto L_00a5658d; /* jae 0xa5658d */
L_00a56553:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00a56576; /* jl 0xa56576 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00a56576; /* jbe 0xa56576 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a56569u); f_00a56722(c); /* call 0xa56722 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a565e5; /* jne 0xa565e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00a56576:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2018u)); /* lea ecx, [esi + 0x2018] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (c->cf) goto L_00a56553; /* jb 0xa56553 */
    goto L_00a56590; /* jmp 0xa56590 */
L_00a5658d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a56590:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    if (!c->cf) goto L_00a565d6; /* jae 0xa565d6 */
L_00a565a3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf != c->of)) goto L_00a565c2; /* jl 0xa565c2 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00a565c2; /* jbe 0xa565c2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00a565b8u); f_00a56722(c); /* call 0xa56722 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a565e5; /* jne 0xa565e5 */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00a565c2:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x1000u))); } /* add dword ptr [ebp - 4], 0x1000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp edi, dword ptr [ebp - 8] */
    if (c->cf) goto L_00a565a3; /* jb 0xa565a3 */
    goto L_00a565d6; /* jmp 0xa565d6 */
L_00a565d3:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a565d6:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa5c670u))); /* cmp esi, dword ptr [0x1000c670] */
    if (c->zf) goto L_00a565f5; /* je 0xa565f5 */
    goto L_00a56528; /* jmp 0xa56528 */
L_00a565e5:;
    W32((uint32_t)(0xa5c670u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000c670], esi */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(sub32(c, R32(a_), c->ebx))); } /* sub dword ptr [edi], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    goto L_00a5671d; /* jmp 0xa5671d */
L_00a565f5:;
    c->eax = (uint32_t)((uint32_t)0xa5a650u); /* mov eax, 0x1000a650 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00a565fc:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi + 0x10], -1 */
    if (c->zf) goto L_00a56608; /* je 0xa56608 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [edi + 0xc], 0 */
    if (!c->zf) goto L_00a56614; /* jne 0xa56614 */
L_00a56608:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->zf) goto L_00a566e9; /* je 0xa566e9 */
    goto L_00a565fc; /* jmp 0xa565fc */
L_00a56614:;
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
    if (!c->zf) goto L_00a56643; /* jne 0xa56643 */
L_00a56632:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x10u); /* cmp dword ptr [ebp - 4], 0x10 */
    if ((c->sf == c->of)) goto L_00a56643; /* jge 0xa56643 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (c->zf) goto L_00a56632; /* je 0xa56632 */
L_00a56643:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(shl32(c, c->eax, 12)); /* shl eax, 0xc */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t t_ = R32((uint32_t)(0xa590b8u)); PUSH32(c, 0x00a5665bu); call_indirect(c, t_); } /* call dword ptr [0x100090b8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00a5671b; /* jne 0xa5671b */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a5666eu); f_00a55170(c); /* call 0xa55170 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00a566aa; /* jle 0xa566aa */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
L_00a56680:;
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
    if (!c->zf) goto L_00a56680; /* jne 0xa56680 */
L_00a566aa:;
    W32((uint32_t)(0xa5c670u), (uint32_t)(c->edi)); /* mov dword ptr [0x1000c670], edi */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2018u)); /* lea eax, [edi + 0x2018] */
L_00a566b6:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->cf) goto L_00a566c6; /* jae 0xa566c6 */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx], -1 */
    if (c->zf) goto L_00a566c4; /* je 0xa566c4 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    goto L_00a566b6; /* jmp 0xa566b6 */
L_00a566c4:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
L_00a566c6:;
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
    goto L_00a5671d; /* jmp 0xa5671d */
L_00a566e9:;
    PUSH32(c, 0x00a566eeu); f_00a56222(c); /* call 0xa56222 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a5671b; /* je 0xa5671b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    W8((uint32_t)(c->ecx + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx + 8], bl */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ebx + 0x8u)); /* lea edx, [ecx + ebx + 8] */
    W32((uint32_t)(0xa5c670u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c670], eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)((uint32_t)0xf0u); /* mov edx, 0xf0 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx edx, bl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x18u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [eax + 0x18], edx */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x100u)); /* lea eax, [ecx + 0x100] */
    goto L_00a5671d; /* jmp 0xa5671d */
L_00a5671b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a5671d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56722(CPU *c) { /* FUN_10006722 */
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
    if (c->cf) goto L_00a56767; /* jb 0xa56767 */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->cf) goto L_00a56756; /* jae 0xa56756 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [ecx], edx */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [ecx + 4], edx */
    goto L_00a5675f; /* jmp 0xa5675f */
L_00a56756:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00a5675f:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    goto L_00a56835; /* jmp 0xa56835 */
L_00a56767:;
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_00a56770; /* je 0xa56770 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a56770:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->cf) goto L_00a567ba; /* jae 0xa567ba */
L_00a56777:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (!c->zf) goto L_00a567ad; /* jne 0xa567ad */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ebx, [eax + 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a56783:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00a5678c; /* jne 0xa5678c */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00a56783; /* jmp 0xa56783 */
L_00a5678c:;
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (!c->cf) goto L_00a567de; /* jae 0xa567de */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp eax, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00a5679a; /* jne 0xa5679a */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00a567a6; /* jmp 0xa567a6 */
L_00a5679a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 0xc], esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00a5683f; /* jb 0xa5683f */
L_00a567a6:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00a567b2; /* jmp 0xa567b2 */
L_00a567ad:;
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
L_00a567b2:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x8u))); /* cmp esi, dword ptr [ebp + 8] */
    if (c->cf) goto L_00a56777; /* jb 0xa56777 */
L_00a567ba:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
L_00a567bd:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->cf) goto L_00a5683f; /* jae 0xa5683f */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea eax, [esi + edx] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u))); /* cmp eax, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00a5683f; /* jae 0xa5683f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00a5680f; /* jne 0xa5680f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ebx, [esi + 1] */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a567d5:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00a567ff; /* jne 0xa567ff */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a567d5; /* jmp 0xa567d5 */
L_00a567de:;
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea ebx, [eax + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00a567ef; /* jae 0xa567ef */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00a567f8; /* jmp 0xa567f8 */
L_00a567ef:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00a567f8:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    goto L_00a56835; /* jmp 0xa56835 */
L_00a567ff:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->cf) goto L_00a56816; /* jae 0xa56816 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [ebp + 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00a5683f; /* jb 0xa5683f */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    goto L_00a567bd; /* jmp 0xa567bd */
L_00a5680f:;
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    goto L_00a567bd; /* jmp 0xa567bd */
L_00a56816:;
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea ebx, [esi + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00a56827; /* jae 0xa56827 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    goto L_00a56830; /* jmp 0xa56830 */
L_00a56827:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00a56830:;
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
L_00a56835:;
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0xfu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0xf */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00a56841; /* jmp 0xa56841 */
L_00a5683f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a56841:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56846(CPU *c) { /* FUN_10006846 */
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
    if ((c->cf || c->zf)) goto L_00a56880; /* jbe 0xa56880 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [edi + 4], 0xf1 */
    goto L_00a568e0; /* jmp 0xa568e0 */
L_00a56880:;
    if (!c->cf) goto L_00a568e7; /* jae 0xa568e7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->eax)); /* lea esi, [edx + eax] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a568e7; /* jb 0xa568e7 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea eax, [ecx + edx] */
L_00a56895:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00a568a3; /* jae 0xa568a3 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00a568a1; /* jne 0xa568a1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a56895; /* jmp 0xa56895 */
L_00a568a1:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
L_00a568a3:;
    if (!c->zf) goto L_00a568e7; /* jne 0xa568e7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x14u))); /* mov al, byte ptr [ebp + 0x14] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if ((!c->cf && !c->zf)) goto L_00a568db; /* ja 0xa568db */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00a568db; /* jbe 0xa568db */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00a568d2; /* jae 0xa568d2 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebx), (uint32_t)(c->esi)); /* mov dword ptr [ebx], esi */
    (void)sub8(c, R8((uint32_t)(c->esi)), ((uint8_t)c->eax)); /* cmp byte ptr [esi], al */
    if (!c->zf) goto L_00a568cd; /* jne 0xa568cd */
L_00a568c6:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->esi + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [esi + eax], 0 */
    if (c->zf) goto L_00a568c6; /* je 0xa568c6 */
L_00a568cd:;
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    goto L_00a568db; /* jmp 0xa568db */
L_00a568d2:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea eax, [ebx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00a568db:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x14u)))); /* sub ecx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
L_00a568e0:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
L_00a568e7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a568ef(CPU *c) { /* FUN_100068ef */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d0d4u))); /* mov eax, dword ptr [0x1000d0d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a56907; /* je 0xa56907 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a568feu); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a56907; /* je 0xa56907 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00a56907:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00a56910(CPU *c) { /* FUN_10006910 */
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
    if ((c->cf || c->zf)) goto L_00a56930; /* jbe 0xa56930 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00a56aa8; /* jb 0xa56aa8 */
L_00a56930:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00a5694c; /* jne 0xa5694c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00a5696c; /* jb 0xa5696c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56945u); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a5694c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00a56964; /* jb 0xa56964 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xa56970u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a5695du); return; } } /* jmp dword ptr [eax*4 + 0x10006970] */
L_00a56964:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa56a68u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a56964u); return; } } /* jmp dword ptr [ecx*4 + 0x10006a68] */
L_00a5696c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa569ecu)); switch (t_) { case 0x00a56a0cu: goto L_00a56a0c; case 0x00a56a14u: goto L_00a56a14; case 0x00a56a1cu: goto L_00a56a1c; case 0x00a56a24u: goto L_00a56a24; case 0x00a56a2cu: goto L_00a56a2c; case 0x00a56a34u: goto L_00a56a34; case 0x00a56a3cu: goto L_00a56a3c; case 0x00a56a4fu: goto L_00a56a4f; default: jump_indirect(c, t_, 0x00a5696cu); return; } } /* jmp dword ptr [ecx*4 + 0x100069ec] */
L_00a56a0c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00a56a14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00a56a1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00a56a24:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00a56a2c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00a56a34:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00a56a3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00a56a4f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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
L_00a56aa8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00a56adc; /* jne 0xa56adc */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00a56ad0; /* jb 0xa56ad0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56ac7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56ad0:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa56ba0u)); switch (t_) { case 0x00a56be7u: goto L_00a56be7; default: jump_indirect(c, t_, 0x00a56ad2u); return; } } /* jmp dword ptr [ecx*4 + 0x10006ba0] */
L_00a56adc:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00a56af4; /* jb 0xa56af4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xa56af8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a56aedu); return; } } /* jmp dword ptr [eax*4 + 0x10006af8] */
L_00a56af4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56af4u); return; } } /* jmp dword ptr [ecx*4 + 0x10006bf0] */
L_00a56be7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a5696c(CPU *c) { /* PTR_00a5696c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa569ecu)); switch (t_) { case 0x00a56a0cu: goto L_00a56a0c; case 0x00a56a14u: goto L_00a56a14; case 0x00a56a1cu: goto L_00a56a1c; case 0x00a56a24u: goto L_00a56a24; case 0x00a56a2cu: goto L_00a56a2c; case 0x00a56a34u: goto L_00a56a34; case 0x00a56a3cu: goto L_00a56a3c; case 0x00a56a4fu: goto L_00a56a4f; default: jump_indirect(c, t_, 0x00a5696cu); return; } } /* jmp dword ptr [ecx*4 + 0x100069ec] */
L_00a56a0c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00a56a14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00a56a1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00a56a24:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00a56a2c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00a56a34:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00a56a3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00a56a4f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56980(CPU *c) { /* PTR_00a56980 */
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
    if (c->cf) { f_00a5696c(c); return; } /* jb 0xa5696c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a569a2u); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a569a0(CPU *c) { /* PTR_00a569a0 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a569a2u); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a569ac(CPU *c) { /* PTR_00a569ac */
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
    if (c->cf) { f_00a5696c(c); return; } /* jb 0xa5696c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a569c8u); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a569d0(CPU *c) { /* PTR_00a569d0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00a5696c(c); return; } /* jb 0xa5696c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a569e2u); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a0c(CPU *c) { /* PTR_00a56a0c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a14(CPU *c) { /* PTR_00a56a14 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a1c(CPU *c) { /* PTR_00a56a1c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a24(CPU *c) { /* PTR_00a56a24 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a2c(CPU *c) { /* PTR_00a56a2c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a34(CPU *c) { /* PTR_00a56a34 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a3c(CPU *c) { /* PTR_00a56a3c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a4f(CPU *c) { /* PTR_00a56a4f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56a58u)); switch (t_) { case 0x00a56a68u: goto L_00a56a68; case 0x00a56a70u: goto L_00a56a70; case 0x00a56a7cu: goto L_00a56a7c; case 0x00a56a90u: goto L_00a56a90; default: jump_indirect(c, t_, 0x00a56a4fu); return; } } /* jmp dword ptr [edx*4 + 0x10006a58] */
L_00a56a68:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a70:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a7c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56a90:;
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

void f_00a56a68(CPU *c) { /* PTR_00a56a68 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56a70(CPU *c) { /* PTR_00a56a70 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56a7c(CPU *c) { /* PTR_00a56a7c */
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

void f_00a56a90(CPU *c) { /* PTR_00a56a90 */
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

void f_00a56ad0(CPU *c) { /* PTR_00a56ad0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa56ba0u)); switch (t_) { case 0x00a56be7u: goto L_00a56be7; default: jump_indirect(c, t_, 0x00a56ad2u); return; } } /* jmp dword ptr [ecx*4 + 0x10006ba0] */
L_00a56be7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56b08(CPU *c) { /* PTR_00a56b08 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00a56ad0(c); return; } /* jb 0xa56ad0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56b1eu); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56b28(CPU *c) { /* PTR_00a56b28 */
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
    if (c->cf) { f_00a56ad0(c); return; } /* jb 0xa56ad0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56b48u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56b50(CPU *c) { /* PTR_00a56b50 */
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
    if (c->cf) { f_00a56ad0(c); return; } /* jb 0xa56ad0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56b7au); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56ba4(CPU *c) { /* PTR_00a56ba4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56bac(CPU *c) { /* PTR_00a56bac */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56bb4(CPU *c) { /* PTR_00a56bb4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56bbc(CPU *c) { /* PTR_00a56bbc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56bc4(CPU *c) { /* PTR_00a56bc4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56bcc(CPU *c) { /* PTR_00a56bcc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56bd4(CPU *c) { /* PTR_00a56bd4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56be7(CPU *c) { /* PTR_00a56be7 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa56bf0u)); switch (t_) { case 0x00a56c00u: goto L_00a56c00; case 0x00a56c08u: goto L_00a56c08; case 0x00a56c18u: goto L_00a56c18; case 0x00a56c2cu: goto L_00a56c2c; default: jump_indirect(c, t_, 0x00a56be7u); return; } } /* jmp dword ptr [edx*4 + 0x10006bf0] */
L_00a56c00:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a56c2c:;
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

void f_00a56c00(CPU *c) { /* PTR_00a56c00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56c08(CPU *c) { /* PTR_00a56c08 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56c18(CPU *c) { /* PTR_00a56c18 */
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

void f_00a56c2c(CPU *c) { /* PTR_00a56c2c */
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

void f_00a56c45(CPU *c) { /* FUN_10006c45 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00a56c55u); f_00a53a0d(c); /* call 0xa53a0d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a56c5du); f_00a56df2(c); /* call 0xa56df2 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xa5d278u))); /* cmp ebx, dword ptr [0x1000d278] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->zf) goto L_00a56c73; /* jne 0xa56c73 */
L_00a56c6c:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00a56de3; /* jmp 0xa56de3 */
L_00a56c73:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00a56dd1; /* je 0xa56dd1 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0xa5c688u); /* mov eax, 0x1000c688 */
L_00a56c82:;
    (void)sub32(c, R32((uint32_t)(c->eax)), c->ebx); /* cmp dword ptr [eax], ebx */
    if (c->zf) goto L_00a56cfa; /* je 0xa56cfa */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x30u)); /* add eax, 0x30 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0xa5c778u); /* cmp eax, 0x1000c778 */
    if ((c->sf != c->of)) goto L_00a56c82; /* jl 0xa56c82 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xa590bcu)); PUSH32(c, 0x00a56c9cu); call_indirect(c, t_); } /* call dword ptr [0x100090bc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00a56dc8; /* jne 0xa56dc8 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t a_ = (uint32_t)(0xa5d4a4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d4a4], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xa5d3a0u); /* mov edi, 0x1000d3a0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->esi); /* cmp dword ptr [ebp - 0x18], esi */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    W32((uint32_t)(0xa5d278u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000d278], ebx */
    if ((c->cf || c->zf)) goto L_00a56db5; /* jbe 0xa56db5 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffeeu)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x12], 0 */
    if (c->zf) goto L_00a56d90; /* je 0xa56d90 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffefu)); /* lea ecx, [ebp - 0x11] */
L_00a56cd7:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a56d90; /* je 0xa56d90 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + 0xffffffffu))); /* movzx eax, byte ptr [ecx - 1] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
L_00a56ce8:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((!c->cf && !c->zf)) goto L_00a56d84; /* ja 0xa56d84 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x4u)))); } /* or byte ptr [eax + 0x1000d3a1], 4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a56ce8; /* jmp 0xa56ce8 */
L_00a56cfa:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xa5d3a0u); /* mov edi, 0x1000d3a0 */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea esi, [edx + edx*2] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0xa5c698u)); /* lea ebx, [esi + 0x1000c698] */
L_00a56d17:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if (c->zf) goto L_00a56d4a; /* je 0xa56d4a */
L_00a56d1e:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a56d4a; /* je 0xa56d4a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx eax, byte ptr [ecx] */
    c->edi = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edi, dl */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((!c->cf && !c->zf)) goto L_00a56d43; /* ja 0xa56d43 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xa5c680u))); /* mov dl, byte ptr [edx + 0x1000c680] */
L_00a56d38:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->edx))))); } /* or byte ptr [eax + 0x1000d3a1], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00a56d38; /* jbe 0xa56d38 */
L_00a56d43:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (!c->zf) goto L_00a56d1e; /* jne 0xa56d1e */
L_00a56d4a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x4u); /* cmp dword ptr [ebp - 4], 4 */
    if (c->cf) goto L_00a56d17; /* jb 0xa56d17 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xa5d28cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d28c], 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0xa5d278u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d278], eax */
    PUSH32(c, 0x00a56d6eu); f_00a56e3c(c); /* call 0xa56e3c */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xa5c68cu)); /* lea esi, [esi + 0x1000c68c] */
    c->edi = (uint32_t)((uint32_t)0xa5d280u); /* mov edi, 0x1000d280 */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xa5d4a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4a4], eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_00a56dd6; /* jmp 0xa56dd6 */
L_00a56d84:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0xffffffffu)), (uint8_t)0x0u); /* cmp byte ptr [ecx - 1], 0 */
    if (!c->zf) goto L_00a56cd7; /* jne 0xa56cd7 */
L_00a56d90:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a56d92:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [eax + 0x1000d3a1], 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xffu); /* cmp eax, 0xff */
    if (c->cf) goto L_00a56d92; /* jb 0xa56d92 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a56da7u); f_00a56e3c(c); /* call 0xa56e3c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xa5d4a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4a4], eax */
    W32((uint32_t)(0xa5d28cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000d28c], esi */
    goto L_00a56dbc; /* jmp 0xa56dbc */
L_00a56db5:;
    { uint32_t a_ = (uint32_t)(0xa5d28cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d28c], 0 */
L_00a56dbc:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xa5d280u); /* mov edi, 0x1000d280 */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    goto L_00a56dd6; /* jmp 0xa56dd6 */
L_00a56dc8:;
    (void)sub32(c, R32((uint32_t)(0xa5d0dcu)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d0dc], 0 */
    if (c->zf) goto L_00a56de0; /* je 0xa56de0 */
L_00a56dd1:;
    PUSH32(c, 0x00a56dd6u); f_00a56e6f(c); /* call 0xa56e6f */
L_00a56dd6:;
    PUSH32(c, 0x00a56ddbu); f_00a56e98(c); /* call 0xa56e98 */
    goto L_00a56c6c; /* jmp 0xa56c6c */
L_00a56de0:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_00a56de3:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00a56deau); f_00a53a6e(c); /* call 0xa53a6e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a56df2(CPU *c) { /* FUN_10006df2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xa5d0dcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d0dc], 0 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (!c->zf) goto L_00a56e12; /* jne 0xa56e12 */
    W32((uint32_t)(0xa5d0dcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d0dc], 1 */
    { uint32_t t_ = R32((uint32_t)(0xa590c4u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a56e0cu); return; } } /* jmp dword ptr [0x100090c4] */
L_00a56e12:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_00a56e27; /* jne 0xa56e27 */
    W32((uint32_t)(0xa5d0dcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d0dc], 1 */
    { uint32_t t_ = R32((uint32_t)(0xa590c0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a56e21u); return; } } /* jmp dword ptr [0x100090c0] */
L_00a56e27:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if (!c->zf) goto L_00a56e3b; /* jne 0xa56e3b */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d128u))); /* mov eax, dword ptr [0x1000d128] */
    W32((uint32_t)(0xa5d0dcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d0dc], 1 */
L_00a56e3b:;
    c->esp += 4; return; /* ret  */
}

void f_00a56e3c(CPU *c) { /* FUN_10006e3c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3a4u)); /* sub eax, 0x3a4 */
    if (c->zf) goto L_00a56e69; /* je 0xa56e69 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00a56e63; /* je 0xa56e63 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xdu)); /* sub eax, 0xd */
    if (c->zf) goto L_00a56e5d; /* je 0xa56e5d */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00a56e57; /* je 0xa56e57 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a56e57:;
    c->eax = (uint32_t)((uint32_t)0x404u); /* mov eax, 0x404 */
    c->esp += 4; return; /* ret  */
L_00a56e5d:;
    c->eax = (uint32_t)((uint32_t)0x412u); /* mov eax, 0x412 */
    c->esp += 4; return; /* ret  */
L_00a56e63:;
    c->eax = (uint32_t)((uint32_t)0x804u); /* mov eax, 0x804 */
    c->esp += 4; return; /* ret  */
L_00a56e69:;
    c->eax = (uint32_t)((uint32_t)0x411u); /* mov eax, 0x411 */
    c->esp += 4; return; /* ret  */
}

void f_00a56e6f(CPU *c) { /* FUN_10006e6f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xa5d3a0u); /* mov edi, 0x1000d3a0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xa5d280u); /* mov edi, 0x1000d280 */
    W32((uint32_t)(0xa5d278u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d278], eax */
    W32((uint32_t)(0xa5d28cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d28c], eax */
    W32((uint32_t)(0xa5d4a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d4a4], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a56e98(CPU *c) { /* FUN_10006e98 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x514u)); /* sub esp, 0x514 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xa5d278u)); PUSH32(c, v_); } /* push dword ptr [0x1000d278] */
    { uint32_t t_ = R32((uint32_t)(0xa590bcu)); PUSH32(c, 0x00a56eb2u); call_indirect(c, t_); } /* call dword ptr [0x100090bc] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00a56fd1; /* jne 0xa56fd1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00a56ec2:;
    W8((uint32_t)(c->ebp + c->eax + 0xfffffeecu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + eax - 0x114], al */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a56ec2; /* jb 0xa56ec2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff2u))); /* mov al, byte ptr [ebp - 0xe] */
    W8((uint32_t)(c->ebp + 0xfffffeecu), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x114], 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a56f13; /* je 0xa56f13 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff3u)); /* lea edx, [ebp - 0xd] */
L_00a56ee1:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((!c->cf && !c->zf)) goto L_00a56f08; /* ja 0xa56f08 */
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
L_00a56f08:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffffu))); /* mov al, byte ptr [edx - 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00a56ee1; /* jne 0xa56ee1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00a56f13:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea eax, [ebp - 0x514] */
    { uint32_t v_ = R32((uint32_t)(0xa5d4a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4a4] */
    { uint32_t v_ = R32((uint32_t)(0xa5d278u)); PUSH32(c, v_); } /* push dword ptr [0x1000d278] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00a56f37u); f_00a5776d(c); /* call 0xa5776d */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdecu)); /* lea eax, [ebp - 0x214] */
    { uint32_t v_ = R32((uint32_t)(0xa5d278u)); PUSH32(c, v_); } /* push dword ptr [0x1000d278] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xa5d4a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4a4] */
    PUSH32(c, 0x00a56f5bu); f_00a578b6(c); /* call 0xa578b6 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffcecu)); /* lea eax, [ebp - 0x314] */
    { uint32_t v_ = R32((uint32_t)(0xa5d278u)); PUSH32(c, v_); } /* push dword ptr [0x1000d278] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0xa5d4a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d4a4] */
    PUSH32(c, 0x00a56f83u); f_00a578b6(c); /* call 0xa578b6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea ecx, [ebp - 0x514] */
L_00a56f8e:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx))); /* mov dx, word ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    if (c->zf) goto L_00a56fac; /* je 0xa56fac */
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x1000d3a1], 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffdecu))); /* mov dl, byte ptr [ebp + eax - 0x214] */
L_00a56fa4:;
    W8((uint32_t)(c->eax + 0xa5d2a0u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x1000d2a0], dl */
    goto L_00a56fc8; /* jmp 0xa56fc8 */
L_00a56fac:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x2u)); /* test dl, 2 */
    if (c->zf) goto L_00a56fc1; /* je 0xa56fc1 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x1000d3a1], 0x20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffcecu))); /* mov dl, byte ptr [ebp + eax - 0x314] */
    goto L_00a56fa4; /* jmp 0xa56fa4 */
L_00a56fc1:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d2a0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x1000d2a0], 0 */
L_00a56fc8:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a56f8e; /* jb 0xa56f8e */
    goto L_00a5701a; /* jmp 0xa5701a */
L_00a56fd1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00a56fd8:;
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if (c->cf) goto L_00a56ff6; /* jb 0xa56ff6 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->cf && !c->zf)) goto L_00a56ff6; /* ja 0xa56ff6 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x1000d3a1], 0x10 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_00a56fee:;
    W8((uint32_t)(c->eax + 0xa5d2a0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x1000d2a0], cl */
    goto L_00a57015; /* jmp 0xa57015 */
L_00a56ff6:;
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if (c->cf) goto L_00a5700e; /* jb 0xa5700e */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->cf && !c->zf)) goto L_00a5700e; /* ja 0xa5700e */
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d3a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x1000d3a1], 0x20 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    goto L_00a56fee; /* jmp 0xa56fee */
L_00a5700e:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xa5d2a0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x1000d2a0], 0 */
L_00a57015:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a56fd8; /* jb 0xa56fd8 */
L_00a5701a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a5701d(CPU *c) { /* FUN_1000701d */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xa5d5e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d5e8], 0 */
    if (!c->zf) goto L_00a57038; /* jne 0xa57038 */
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    PUSH32(c, 0x00a5702du); f_00a56c45(c); /* call 0xa56c45 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xa5d5e8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d5e8], 1 */
L_00a57038:;
    c->esp += 4; return; /* ret  */
}

void f_00a57039(CPU *c) { /* FUN_10007039 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00a5704cu); f_00a57050(c); /* call 0xa57050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00a57050(CPU *c) { /* FUN_10007050 */
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
L_00a57068:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000a400], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00a57080; /* jle 0xa57080 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a5707cu); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a5708f; /* jmp 0xa5708f */
L_00a57080:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov ecx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00a5708f:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57098; /* je 0xa57098 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00a57068; /* jmp 0xa57068 */
L_00a57098:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    if (!c->zf) goto L_00a570a6; /* jne 0xa570a6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp + 0x14], 2 */
    goto L_00a570ab; /* jmp 0xa570ab */
L_00a570a6:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (!c->zf) goto L_00a570b1; /* jne 0xa570b1 */
L_00a570ab:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00a570b1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a57245; /* jl 0xa57245 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00a57245; /* je 0xa57245 */
    (void)sub32(c, c->eax, (uint32_t)0x24u); /* cmp eax, 0x24 */
    if ((!c->zf && c->sf == c->of)) goto L_00a57245; /* jg 0xa57245 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a570f9; /* jne 0xa570f9 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00a570e3; /* je 0xa570e3 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp + 0x10], 0xa */
    goto L_00a57115; /* jmp 0xa57115 */
L_00a570e3:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00a570f6; /* je 0xa570f6 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (c->zf) goto L_00a570f6; /* je 0xa570f6 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x10], 8 */
    goto L_00a57115; /* jmp 0xa57115 */
L_00a570f6:;
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
L_00a570f9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00a57115; /* jne 0xa57115 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00a57115; /* jne 0xa57115 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00a5710d; /* je 0xa5710d */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (!c->zf) goto L_00a57115; /* jne 0xa57115 */
L_00a5710d:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov bl, byte ptr [esi + 1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00a57115:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a5711au, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)0x103u); /* mov edi, 0x103 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00a57125:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000a400], 1 */
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    if ((c->zf || c->sf != c->of)) goto L_00a5713d; /* jle 0xa5713d */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a57139u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a57148; /* jmp 0xa57148 */
L_00a5713d:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov eax, dword ptr [0x1000a40c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00a57148:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57154; /* je 0xa57154 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x30u)); /* sub ecx, 0x30 */
    goto L_00a57186; /* jmp 0xa57186 */
L_00a57154:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000a400], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00a57168; /* jle 0xa57168 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a57164u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a57173; /* jmp 0xa57173 */
L_00a57168:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov eax, dword ptr [0x1000a40c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + c->esi * 2))); /* mov ax, word ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edi))); /* and eax, edi */
L_00a57173:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a571c1; /* je 0xa571c1 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a57180u); f_00a58413(c); /* call 0xa58413 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x37u)); /* sub ecx, 0x37 */
L_00a57186:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_00a571c1; /* jae 0xa571c1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp + 0x14], 8 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u))); /* cmp esi, dword ptr [ebp - 0xc] */
    if (c->cf) goto L_00a571ab; /* jb 0xa571ab */
    if (!c->zf) goto L_00a571a5; /* jne 0xa571a5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a5719eu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->cf || c->zf)) goto L_00a571ab; /* jbe 0xa571ab */
L_00a571a5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp + 0x14], 4 */
    goto L_00a571b4; /* jmp 0xa571b4 */
L_00a571ab:;
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
L_00a571b4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    goto L_00a57125; /* jmp 0xa57125 */
L_00a571c1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00a571de; /* jne 0xa571de */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00a571d8; /* je 0xa571d8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00a571d8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    goto L_00a57229; /* jmp 0xa57229 */
L_00a571de:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
    if (!c->zf) goto L_00a57202; /* jne 0xa57202 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (!c->zf) goto L_00a57229; /* jne 0xa57229 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    if (c->zf) goto L_00a571f9; /* je 0xa571f9 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x80000000u); /* cmp dword ptr [ebp - 8], 0x80000000 */
    if ((!c->cf && !c->zf)) goto L_00a57202; /* ja 0xa57202 */
L_00a571f9:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a57229; /* jne 0xa57229 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->esi); /* cmp dword ptr [ebp - 8], esi */
    if ((c->cf || c->zf)) goto L_00a57229; /* jbe 0xa57229 */
L_00a57202:;
    PUSH32(c, 0x00a57207u); f_00a5840a(c); /* call 0xa5840a */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x14], 1 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    if (c->zf) goto L_00a57219; /* je 0xa57219 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    goto L_00a57229; /* jmp 0xa57229 */
L_00a57219:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u))); /* and al, 2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(neg8(c, ((uint8_t)c->eax))); /* neg al */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00a57229:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00a57232; /* je 0xa57232 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00a57232:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x2u)); /* test byte ptr [ebp + 0x14], 2 */
    if (c->zf) goto L_00a57240; /* je 0xa57240 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00a57240:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    goto L_00a57250; /* jmp 0xa57250 */
L_00a57245:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a5724e; /* je 0xa5724e */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
L_00a5724e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a57250:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a57260(CPU *c) { /* PTR_00a57260 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a57270(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_00a57270;
L_00a57260:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a57270:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00a5729b; /* je 0xa5729b */
L_00a57288:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_00a57260; /* je 0xa57260 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00a572e4; /* je 0xa572e4 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00a57288; /* jne 0xa57288 */
L_00a5729b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00a572a6:;
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
    if (!c->zf) goto L_00a572e8; /* jne 0xa572e8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00a572a6; /* je 0xa572a6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00a572e2; /* jne 0xa572e2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00a572a6; /* jne 0xa572a6 */
L_00a572e2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a572e4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a572e8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a57325; /* je 0xa57325 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00a5731e; /* je 0xa5731e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a57317; /* je 0xa57317 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00a57310; /* je 0xa57310 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    goto L_00a572a6; /* jmp 0xa572a6 */
L_00a57310:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a57317:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a5731e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a57325:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a57276(CPU *c) { /* PTR_00a57276 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00a5729b; /* je 0xa5729b */
L_00a57288:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_00a57260(c); return; } /* je 0xa57260 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00a572e4; /* je 0xa572e4 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00a57288; /* jne 0xa57288 */
L_00a5729b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00a572a6:;
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
    if (!c->zf) goto L_00a572e8; /* jne 0xa572e8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00a572a6; /* je 0xa572a6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00a572e2; /* jne 0xa572e2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00a572a6; /* jne 0xa572a6 */
L_00a572e2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a572e4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a572e8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a57325; /* je 0xa57325 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00a5731e; /* je 0xa5731e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a57317; /* je 0xa57317 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00a57310; /* je 0xa57310 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00a572e2; /* je 0xa572e2 */
    goto L_00a572a6; /* jmp 0xa572a6 */
L_00a57310:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a57317:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a5731e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a57325:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a57330(CPU *c) { /* _strstr */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a573aa; /* je 0xa573aa */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00a57397; /* je 0xa57397 */
L_00a57348:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_00a5736a; /* je 0xa5736a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a57364; /* je 0xa57364 */
L_00a57359:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a5735c:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_00a5736a; /* je 0xa5736a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00a57359; /* jne 0xa57359 */
L_00a57364:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a5736a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_00a5735c; /* jne 0xa5735c */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_00a57374:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00a573a3; /* je 0xa573a3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_00a57348; /* jne 0xa57348 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a573a3; /* je 0xa573a3 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_00a57374; /* je 0xa57374 */
    goto L_00a57348; /* jmp 0xa57348 */
L_00a57397:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_00a57276(c); return; } /* jmp 0xa57276 */
L_00a573a3:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a573aa:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a573b0(CPU *c) { /* _strncmp */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    if (c->ecx == 0) goto L_00a573e1; /* jecxz 0xa573e1 */
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
    if ((!c->cf && !c->zf)) goto L_00a573df; /* ja 0xa573df */
    if (c->zf) goto L_00a573e1; /* je 0xa573e1 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_00a573df:;
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
L_00a573e1:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a573f0(CPU *c) { /* FUN_100073f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_00a57410; /* jb 0xa57410 */
L_00a573fc:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_00a573fc; /* jae 0xa573fc */
L_00a57410:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_00a5741f(CPU *c) { /* FUN_1000741f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xa5d0e0u)), c->ebx); /* cmp dword ptr [0x1000d0e0], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a5746e; /* jne 0xa5746e */
    { uint32_t v_ = 0xa59658u; PUSH32(c, v_); } /* push 0x10009658 */
    { uint32_t t_ = R32((uint32_t)(0xa590c8u)); PUSH32(c, 0x00a57437u); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00a574a4; /* je 0xa574a4 */
    c->esi = (uint32_t)(R32((uint32_t)(0xa5902cu))); /* mov esi, dword ptr [0x1000902c] */
    { uint32_t v_ = 0xa5964cu; PUSH32(c, v_); } /* push 0x1000964c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a5744bu); call_indirect(c, t_); } /* call esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xa5d0e0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d0e0], eax */
    if (c->zf) goto L_00a574a4; /* je 0xa574a4 */
    { uint32_t v_ = 0xa5963cu; PUSH32(c, v_); } /* push 0x1000963c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a5745cu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = 0xa59628u; PUSH32(c, v_); } /* push 0x10009628 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0xa5d0e4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d0e4], eax */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a57469u); call_indirect(c, t_); } /* call esi */
    W32((uint32_t)(0xa5d0e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d0e8], eax */
L_00a5746e:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d0e4u))); /* mov eax, dword ptr [0x1000d0e4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a5748d; /* je 0xa5748d */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a57479u); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00a5748d; /* je 0xa5748d */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d0e8u))); /* mov eax, dword ptr [0x1000d0e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a5748d; /* je 0xa5748d */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a5748bu); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00a5748d:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xa5d0e0u)); PUSH32(c, 0x00a574a0u); call_indirect(c, t_); } /* call dword ptr [0x1000d0e0] */
L_00a574a0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a574a4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a574a0; /* jmp 0xa574a0 */
}

void f_00a574b0(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a57533; /* je 0xa57533 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00a574d4; /* jne 0xa574d4 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00a57541; /* jne 0xa57541 */
    goto L_00a574f5; /* jmp 0xa574f5 */
L_00a574d4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00a57502; /* je 0xa57502 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a5750a; /* je 0xa5750a */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00a574d4; /* jne 0xa574d4 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00a57541; /* jne 0xa57541 */
L_00a574f0:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_00a57502; /* je 0xa57502 */
L_00a574f5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a5752e; /* je 0xa5752e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00a574f5; /* jne 0xa574f5 */
L_00a57502:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a5750a:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_00a57524; /* je 0xa57524 */
L_00a57512:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00a575a6; /* je 0xa575a6 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00a57512; /* jne 0xa57512 */
L_00a57524:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00a57597; /* jne 0xa57597 */
L_00a5752b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00a5752e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00a5752b; /* jne 0xa5752b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a57533:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a57539:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00a574f0; /* je 0xa574f0 */
L_00a57541:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00a57539; /* je 0xa57539 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a5758b; /* je 0xa5758b */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00a57581; /* je 0xa57581 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00a57577; /* je 0xa57577 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_00a57539; /* jne 0xa57539 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00a5758f; /* jmp 0xa5758f */
L_00a57577:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00a5758f; /* jmp 0xa5758f */
L_00a57581:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00a5758f; /* jmp 0xa5758f */
L_00a5758b:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00a5758f:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00a575a1; /* je 0xa575a1 */
L_00a57597:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a57599:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00a57599; /* jne 0xa57599 */
L_00a575a1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_00a5752b; /* jne 0xa5752b */
L_00a575a6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a575ae(CPU *c) { /* FUN_100075ae */
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
    if (c->zf) goto L_00a57629; /* je 0xa57629 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00a5760c; /* je 0xa5760c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00a5760c; /* je 0xa5760c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00a5760c; /* je 0xa5760c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00a575ff; /* je 0xa575ff */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_00a575f2; /* je 0xa575f2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00a575e5; /* je 0xa575e5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00a5772b; /* jmp 0xa5772b */
L_00a575e5:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xa5d0f4u))); /* mov ebx, dword ptr [0x1000d0f4] */
    c->edi = (uint32_t)((uint32_t)0xa5d0f4u); /* mov edi, 0x1000d0f4 */
    goto L_00a57634; /* jmp 0xa57634 */
L_00a575f2:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xa5d0f0u))); /* mov ebx, dword ptr [0x1000d0f0] */
    c->edi = (uint32_t)((uint32_t)0xa5d0f0u); /* mov edi, 0x1000d0f0 */
    goto L_00a57634; /* jmp 0xa57634 */
L_00a575ff:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xa5d0f8u))); /* mov ebx, dword ptr [0x1000d0f8] */
    c->edi = (uint32_t)((uint32_t)0xa5d0f8u); /* mov edi, 0x1000d0f8 */
    goto L_00a57634; /* jmp 0xa57634 */
L_00a5760c:;
    PUSH32(c, 0x00a57611u); f_00a52439(c); /* call 0xa52439 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x50u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x50] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a5761eu); f_00a57730(c); /* call 0xa57730 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    goto L_00a57646; /* jmp 0xa57646 */
L_00a57629:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xa5d0ecu))); /* mov ebx, dword ptr [0x1000d0ec] */
    c->edi = (uint32_t)((uint32_t)0xa5d0ecu); /* mov edi, 0x1000d0ec */
L_00a57634:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00a57642u); f_00a53a0d(c); /* call 0xa53a0d */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a57646:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (!c->zf) goto L_00a57661; /* jne 0xa57661 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00a57729; /* je 0xa57729 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a5765bu); f_00a53a6e(c); /* call 0xa53a6e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a57729; /* jmp 0xa57729 */
L_00a57661:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (!c->zf) goto L_00a5767b; /* jne 0xa5767b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ecx); /* cmp dword ptr [ebp - 4], ecx */
    if (c->zf) goto L_00a57674; /* je 0xa57674 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00a57673u); f_00a53a6e(c); /* call 0xa53a6e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a57674:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00a5767bu); f_00a53330(c); /* call 0xa53330 */
L_00a5767b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (c->zf) goto L_00a5768d; /* je 0xa5768d */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if (c->zf) goto L_00a5768d; /* je 0xa5768d */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_00a576a8; /* jne 0xa576a8 */
L_00a5768d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if (!c->zf) goto L_00a576e4; /* jne 0xa576e4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [esi + 0x58], 0x8c */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_00a576a8:;
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (!c->zf) goto L_00a576e4; /* jne 0xa576e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a3f0u))); /* mov ecx, dword ptr [0x1000a3f0] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5a3f4u))); /* mov eax, dword ptr [0x1000a3f4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00a576e6; /* jge 0xa576e6 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
L_00a576c4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx + eax - 4], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0xa5a3f0u))); /* mov edx, dword ptr [0x1000a3f0] */
    c->edi = (uint32_t)(R32((uint32_t)(0xa5a3f4u))); /* mov edi, dword ptr [0x1000a3f4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if ((c->sf != c->of)) goto L_00a576c4; /* jl 0xa576c4 */
    goto L_00a576e6; /* jmp 0xa576e6 */
L_00a576e4:;
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
L_00a576e6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00a576f4; /* je 0xa576f4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00a576f3u); f_00a53a6e(c); /* call 0xa53a6e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a576f4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    if (!c->zf) goto L_00a57705; /* jne 0xa57705 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x58] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00a57701u); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a57717; /* jmp 0xa57717 */
L_00a57705:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00a5770au); call_indirect(c, t_); } /* call ebx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0xbu); /* cmp dword ptr [ebp + 8], 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a57717; /* je 0xa57717 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x4u); /* cmp dword ptr [ebp + 8], 4 */
    if (!c->zf) goto L_00a57729; /* jne 0xa57729 */
L_00a57717:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if (!c->zf) goto L_00a57729; /* jne 0xa57729 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_00a57729:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a5772b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a57730(CPU *c) { /* FUN_10007730 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a3fcu))); /* mov ecx, dword ptr [0x1000a3fc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    if (c->zf) goto L_00a57759; /* je 0xa57759 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edi, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->edi * 4)); /* lea edi, [edx + edi*4] */
L_00a5774d:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_00a57759; /* jae 0xa57759 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (!c->zf) goto L_00a5774d; /* jne 0xa5774d */
L_00a57759:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea ecx, [edx + ecx*4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00a57768; /* jae 0xa57768 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (c->zf) goto L_00a5776a; /* je 0xa5776a */
L_00a57768:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a5776a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a5776d(CPU *c) { /* FUN_1000776d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa59670u; PUSH32(c, v_); } /* push 0x10009670 */
    { uint32_t v_ = 0xa555ecu; PUSH32(c, v_); } /* push 0x100055ec */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d100u))); /* mov eax, dword ptr [0x1000d100] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00a577dc; /* jne 0xa577dc */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xa59668u; PUSH32(c, v_); } /* push 0x10009668 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xa590d4u)); PUSH32(c, 0x00a577b2u); call_indirect(c, t_); } /* call dword ptr [0x100090d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a577ba; /* je 0xa577ba */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a577d7; /* jmp 0xa577d7 */
L_00a577ba:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xa59664u; PUSH32(c, v_); } /* push 0x10009664 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xa590d0u)); PUSH32(c, 0x00a577ccu); call_indirect(c, t_); } /* call dword ptr [0x100090d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a578a2; /* je 0xa578a2 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a577d7:;
    W32((uint32_t)(0xa5d100u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d100], eax */
L_00a577dc:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a57805; /* jne 0xa57805 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00a577ed; /* jne 0xa577ed */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d118u))); /* mov eax, dword ptr [0x1000d118] */
L_00a577ed:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa590d0u)); PUSH32(c, 0x00a57800u); call_indirect(c, t_); } /* call dword ptr [0x100090d0] */
    goto L_00a578a4; /* jmp 0xa578a4 */
L_00a57805:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00a578a2; /* jne 0xa578a2 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->ebx); /* cmp dword ptr [ebp + 0x18], ebx */
    if (!c->zf) goto L_00a5781b; /* jne 0xa5781b */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d128u))); /* mov eax, dword ptr [0x1000d128] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
L_00a5781b:;
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
    { uint32_t t_ = R32((uint32_t)(0xa590ccu)); PUSH32(c, 0x00a57838u); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00a578a2; /* je 0xa578a2 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax)); /* lea edi, [eax + eax] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00a57851u); f_00a573f0(c); /* call 0xa573f0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(c->esp); /* mov esi, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a57861u); f_00a55170(c); /* call 0xa55170 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00a57871; /* jmp 0xa57871 */
L_00a57871:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00a578a2; /* je 0xa578a2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xa590ccu)); PUSH32(c, 0x00a5788eu); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00a578a2; /* je 0xa578a2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590d4u)); PUSH32(c, 0x00a578a0u); call_indirect(c, t_); } /* call dword ptr [0x100090d4] */
    goto L_00a578a4; /* jmp 0xa578a4 */
L_00a578a2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a578a4:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a57866(CPU *c) { /* PTR_00a57866 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a5786a(CPU *c) { /* PTR_00a5786a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00a578a2; /* je 0xa578a2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xa590ccu)); PUSH32(c, 0x00a5788eu); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00a578a2; /* je 0xa578a2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590d4u)); PUSH32(c, 0x00a578a0u); call_indirect(c, t_); } /* call dword ptr [0x100090d4] */
    goto L_00a578a4; /* jmp 0xa578a4 */
L_00a578a2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a578a4:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a578b6(CPU *c) { /* FUN_100078b6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa59680u; PUSH32(c, v_); } /* push 0x10009680 */
    { uint32_t v_ = 0xa555ecu; PUSH32(c, v_); } /* push 0x100055ec */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0xa5d130u)), c->edi); /* cmp dword ptr [0x1000d130], edi */
    if (!c->zf) goto L_00a5792c; /* jne 0xa5792c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xa59668u; PUSH32(c, v_); } /* push 0x10009668 */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a578feu); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a5790a; /* je 0xa5790a */
    W32((uint32_t)(0xa5d130u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000d130], ebx */
    goto L_00a5792c; /* jmp 0xa5792c */
L_00a5790a:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xa59664u; PUSH32(c, v_); } /* push 0x10009664 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa590d8u)); PUSH32(c, 0x00a5791au); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    W32((uint32_t)(0xa5d130u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x1000d130], 2 */
L_00a5792c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->edi); /* cmp dword ptr [ebp + 0x14], edi */
    if ((c->zf || c->sf != c->of)) goto L_00a57941; /* jle 0xa57941 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00a5793cu); f_00a57ada(c); /* call 0xa57ada */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_00a57941:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d130u))); /* mov eax, dword ptr [0x1000d130] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a57968; /* jne 0xa57968 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590d8u)); PUSH32(c, 0x00a57963u); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    goto L_00a57a46; /* jmp 0xa57a46 */
L_00a57968:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00a57a44; /* jne 0xa57a44 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), c->edi); /* cmp dword ptr [ebp + 0x20], edi */
    if (!c->zf) goto L_00a5797e; /* jne 0xa5797e */
    c->eax = (uint32_t)(R32((uint32_t)(0xa5d128u))); /* mov eax, dword ptr [0x1000d128] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
L_00a5797e:;
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
    { uint32_t t_ = R32((uint32_t)(0xa590ccu)); PUSH32(c, 0x00a5799bu); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x1c], ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea eax, [ebx + ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00a579b8u); f_00a573f0(c); /* call 0xa573f0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00a579d9; /* jmp 0xa579d9 */
L_00a579d9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xa590ccu)); PUSH32(c, 0x00a579f3u); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57a09u); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00a57a58; /* je 0xa57a58 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00a57ad3; /* je 0xa57ad3 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00a57a44; /* jg 0xa57a44 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57a3cu); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a57ad3; /* jne 0xa57ad3 */
L_00a57a44:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a57a46:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a57a58:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00a57a6cu); f_00a573f0(c); /* call 0xa573f0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00a57a8c; /* jmp 0xa57a8c */
L_00a57a8c:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57aa4u); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a57ab3; /* jne 0xa57ab3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00a57ab9; /* jmp 0xa57ab9 */
L_00a57ab3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00a57ab9:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xa59080u)); PUSH32(c, 0x00a57ac9u); call_indirect(c, t_); } /* call dword ptr [0x10009080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
L_00a57ad3:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a57a46; /* jmp 0xa57a46 */
}

void f_00a579c6(CPU *c) { /* PTR_00a579c6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a579ca(CPU *c) { /* PTR_00a579ca */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ebx, dword ptr [ebp - 0x1c] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xa590ccu)); PUSH32(c, 0x00a579f3u); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57a09u); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00a57a58; /* je 0xa57a58 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00a57ad3; /* je 0xa57ad3 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00a57a44; /* jg 0xa57a44 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57a3cu); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a57ad3; /* jne 0xa57ad3 */
L_00a57a44:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a57a46:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a57a58:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00a57a6cu); f_00a573f0(c); /* call 0xa573f0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00a57a8c; /* jmp 0xa57a8c */
L_00a57a8c:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57aa4u); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a57ab3; /* jne 0xa57ab3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00a57ab9; /* jmp 0xa57ab9 */
L_00a57ab3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00a57ab9:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xa59080u)); PUSH32(c, 0x00a57ac9u); call_indirect(c, t_); } /* call dword ptr [0x10009080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00a57a44; /* je 0xa57a44 */
L_00a57ad3:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a57a46; /* jmp 0xa57a46 */
}

void f_00a57a44(CPU *c) { /* PTR_00a57a44 */
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

void f_00a57a7a(CPU *c) { /* PTR_00a57a7a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a57a7e(CPU *c) { /* PTR_00a57a7e */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) { f_00a57a44(c); return; } /* je 0xa57a44 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa590dcu)); PUSH32(c, 0x00a57aa4u); call_indirect(c, t_); } /* call dword ptr [0x100090dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00a57a44(c); return; } /* je 0xa57a44 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a57ab3; /* jne 0xa57ab3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00a57ab9; /* jmp 0xa57ab9 */
L_00a57ab3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00a57ab9:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xa59080u)); PUSH32(c, 0x00a57ac9u); call_indirect(c, t_); } /* call dword ptr [0x10009080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) { f_00a57a44(c); return; } /* je 0xa57a44 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { jump_indirect(c, 0x00a57a46u, 0x00a57ad5u); return; } /* jmp 0xa57a46 */
}

void f_00a57ada(CPU *c) { /* FUN_10007ada */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea ecx, [edx - 1] */
    if (c->zf) goto L_00a57af7; /* je 0xa57af7 */
L_00a57aea:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00a57af7; /* je 0xa57af7 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00a57aea; /* jne 0xa57aea */
L_00a57af7:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_00a57b02; /* jne 0xa57b02 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
L_00a57b02:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esp += 4; return; /* ret  */
}

void f_00a57b05(CPU *c) { /* FUN_10007b05 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi)); /* lea ecx, [edx + esi] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->cf) goto L_00a57b1b; /* jb 0xa57b1b */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (!c->cf) goto L_00a57b1e; /* jae 0xa57b1e */
L_00a57b1b:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a57b1e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a57b26(CPU *c) { /* ___add_12 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00a57b3au); f_00a57b05(c); /* call 0xa57b05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57b58; /* je 0xa57b58 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00a57b4eu); f_00a57b05(c); /* call 0xa57b05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57b58; /* je 0xa57b58 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00a57b58:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [edi + 4] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00a57b66u); f_00a57b05(c); /* call 0xa57b05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57b70; /* je 0xa57b70 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00a57b70:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00a57b7eu); f_00a57b05(c); /* call 0xa57b05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a57b84(CPU *c) { /* FUN_10007b84 */
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

void f_00a57bb2(CPU *c) { /* FUN_10007bb2 */
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

void f_00a57bdf(CPU *c) { /* FUN_10007bdf */
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
    if ((c->cf || c->zf)) goto L_00a57c53; /* jbe 0xa57c53 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
L_00a57c06:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea edi, [ebp - 0x10] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00a57c14u); f_00a57b84(c); /* call 0xa57b84 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a57c1au); f_00a57b84(c); /* call 0xa57b84 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a57c24u); f_00a57b26(c); /* call 0xa57b26 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a57c2au); f_00a57b84(c); /* call 0xa57b84 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx eax, byte ptr [eax] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a57c45u); f_00a57b26(c); /* call 0xa57b26 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_00a57c06; /* jne 0xa57c06 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a57c53:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->edx); /* cmp dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00a57c80; /* jne 0xa57c80 */
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
    goto L_00a57c53; /* jmp 0xa57c53 */
L_00a57c80:;
    c->esi = (uint32_t)((uint32_t)0x8000u); /* mov esi, 0x8000 */
L_00a57c85:;
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->esi)); /* test dword ptr [ebx + 8], esi */
    if (!c->zf) goto L_00a57c9a; /* jne 0xa57c9a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a57c90u); f_00a57b84(c); /* call 0xa57b84 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp - 4], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a57c85; /* jmp 0xa57c85 */
L_00a57c9a:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ax, word ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ebx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebx + 0xa], ax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a57ca6(CPU *c) { /* FUN_10007ca6 */
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
L_00a57ce1:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov cl, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u); /* cmp cl, 0x20 */
    if (c->zf) goto L_00a57cf7; /* je 0xa57cf7 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x9u); /* cmp cl, 9 */
    if (c->zf) goto L_00a57cf7; /* je 0xa57cf7 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xau); /* cmp cl, 0xa */
    if (c->zf) goto L_00a57cf7; /* je 0xa57cf7 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xdu); /* cmp cl, 0xd */
    if (!c->zf) goto L_00a57cfa; /* jne 0xa57cfa */
L_00a57cf7:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57ce1; /* jmp 0xa57ce1 */
L_00a57cfa:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a57cfd:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if ((!c->cf && !c->zf)) goto L_00a57f80; /* ja 0xa57f80 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xa58147u)); switch (t_) { case 0x00a57d10u: goto L_00a57d10; case 0x00a57d5fu: goto L_00a57d5f; case 0x00a57db6u: goto L_00a57db6; case 0x00a57de0u: goto L_00a57de0; case 0x00a57e3bu: goto L_00a57e3b; case 0x00a57eb2u: goto L_00a57eb2; case 0x00a57ee8u: goto L_00a57ee8; case 0x00a57f11u: goto L_00a57f11; case 0x00a57f32u: goto L_00a57f32; case 0x00a57f4cu: goto L_00a57f4c; case 0x00a57f80u: goto L_00a57f80; case 0x00a57f96u: goto L_00a57f96; default: jump_indirect(c, t_, 0x00a57d09u); return; } } /* jmp dword ptr [eax*4 + 0x10008147] */
L_00a57d10:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00a57d21; /* jl 0xa57d21 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00a57d21; /* jg 0xa57d21 */
L_00a57d1a:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00a57f3e; /* jmp 0xa57f3e */
L_00a57d21:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xa5a404u))); /* cmp bl, byte ptr [0x1000a404] */
    if (!c->zf) goto L_00a57d30; /* jne 0xa57d30 */
L_00a57d29:;
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00a57f76; /* jmp 0xa57f76 */
L_00a57d30:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00a57d56; /* je 0xa57d56 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00a57d4a; /* je 0xa57d4a */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00a58019; /* jne 0xa58019 */
    goto L_00a57dd9; /* jmp 0xa57dd9 */
L_00a57d4a:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57d56:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57d5f:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    if ((c->sf != c->of)) goto L_00a57d6c; /* jl 0xa57d6c */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00a57d1a; /* jle 0xa57d1a */
L_00a57d6c:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xa5a404u))); /* cmp bl, byte ptr [0x1000a404] */
    if (c->zf) goto L_00a57e34; /* je 0xa57e34 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00a57dae; /* je 0xa57dae */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00a57dae; /* je 0xa57dae */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00a57dd9; /* je 0xa57dd9 */
L_00a57d87:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x43u); /* cmp bl, 0x43 */
    if ((c->zf || c->sf != c->of)) goto L_00a58019; /* jle 0xa58019 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x45u); /* cmp bl, 0x45 */
    if ((c->zf || c->sf != c->of)) goto L_00a57da7; /* jle 0xa57da7 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x63u); /* cmp bl, 0x63 */
    if ((c->zf || c->sf != c->of)) goto L_00a58019; /* jle 0xa58019 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x65u); /* cmp bl, 0x65 */
    if ((!c->zf && c->sf == c->of)) goto L_00a58019; /* jg 0xa58019 */
L_00a57da7:;
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    goto L_00a57f76; /* jmp 0xa57f76 */
L_00a57dae:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    goto L_00a57f76; /* jmp 0xa57f76 */
L_00a57db6:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00a57dc4; /* jl 0xa57dc4 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00a57d1a; /* jle 0xa57d1a */
L_00a57dc4:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xa5a404u))); /* cmp bl, byte ptr [0x1000a404] */
    if (c->zf) goto L_00a57d29; /* je 0xa57d29 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00a57f8e; /* jne 0xa57f8e */
L_00a57dd9:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57de0:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
L_00a57de3:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), c->edx); /* cmp dword ptr [0x1000a400], edx */
    if ((c->zf || c->sf != c->of)) goto L_00a57dfc; /* jle 0xa57dfc */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a57df5u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00a57e0a; /* jmp 0xa57e0a */
L_00a57dfc:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov ecx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00a57e0a:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57e2c; /* je 0xa57e2c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00a57e24; /* jae 0xa57e24 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00a57e27; /* jmp 0xa57e27 */
L_00a57e24:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
L_00a57e27:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57de3; /* jmp 0xa57de3 */
L_00a57e2c:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xa5a404u))); /* cmp bl, byte ptr [0x1000a404] */
    if (!c->zf) goto L_00a57e9b; /* jne 0xa57e9b */
L_00a57e34:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57e3b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if (!c->zf) goto L_00a57e54; /* jne 0xa57e54 */
L_00a57e47:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00a57e54; /* jne 0xa57e54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57e47; /* jmp 0xa57e47 */
L_00a57e54:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), c->edx); /* cmp dword ptr [0x1000a400], edx */
    if ((c->zf || c->sf != c->of)) goto L_00a57e6d; /* jle 0xa57e6d */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a57e66u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00a57e7b; /* jmp 0xa57e7b */
L_00a57e6d:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov ecx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00a57e7b:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57e9b; /* je 0xa57e9b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00a57e96; /* jae 0xa57e96 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
L_00a57e96:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57e54; /* jmp 0xa57e54 */
L_00a57e9b:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00a57dae; /* je 0xa57dae */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00a57dae; /* je 0xa57dae */
    goto L_00a57d87; /* jmp 0xa57d87 */
L_00a57eb2:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), c->edx); /* cmp dword ptr [0x1000a400], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if ((c->zf || c->sf != c->of)) goto L_00a57ece; /* jle 0xa57ece */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a57ec7u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00a57edc; /* jmp 0xa57edc */
L_00a57ece:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov ecx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00a57edc:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57f8e; /* je 0xa57f8e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a57f3f; /* jmp 0xa57f3f */
L_00a57ee8:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xfffffffeu)); /* lea ecx, [edi - 2] */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if ((c->sf != c->of)) goto L_00a57ef8; /* jl 0xa57ef8 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00a57f3c; /* jle 0xa57f3c */
L_00a57ef8:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00a57f74; /* je 0xa57f74 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00a57f68; /* je 0xa57f68 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00a5801c; /* jne 0xa5801c */
L_00a57f0d:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_00a57f76; /* jmp 0xa57f76 */
L_00a57f11:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
L_00a57f14:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00a57f1e; /* jne 0xa57f1e */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57f14; /* jmp 0xa57f14 */
L_00a57f1e:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00a58019; /* jl 0xa58019 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00a58019; /* jg 0xa58019 */
    goto L_00a57f3c; /* jmp 0xa57f3c */
L_00a57f32:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00a57f45; /* jl 0xa57f45 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00a57f45; /* jg 0xa57f45 */
L_00a57f3c:;
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
L_00a57f3e:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a57f3f:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57f45:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00a57f8e; /* jne 0xa57f8e */
    goto L_00a57f0d; /* jmp 0xa57f0d */
L_00a57f4c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    if (c->zf) goto L_00a57f7c; /* je 0xa57f7c */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if (c->zf) goto L_00a57f74; /* je 0xa57f74 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00a5801c; /* jne 0xa5801c */
L_00a57f68:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x18], 0xffffffff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57f74:;
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
L_00a57f76:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57f7c:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a57f80:;
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if (c->zf) goto L_00a5801e; /* je 0xa5801e */
    goto L_00a57cfd; /* jmp 0xa57cfd */
L_00a57f8e:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00a5801e; /* jmp 0xa5801e */
L_00a57f96:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00a57f9f:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000a400], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00a57fb7; /* jle 0xa57fb7 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a57fb3u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a57fc6; /* jmp 0xa57fc6 */
L_00a57fb7:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov ecx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00a57fc6:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a57fe6; /* je 0xa57fe6 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea esi, [ecx + eax*2 - 0x30] */
    (void)sub32(c, c->esi, (uint32_t)0x1450u); /* cmp esi, 0x1450 */
    if ((!c->zf && c->sf == c->of)) goto L_00a57fe1; /* jg 0xa57fe1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57f9f; /* jmp 0xa57f9f */
L_00a57fe1:;
    c->esi = (uint32_t)((uint32_t)0x1451u); /* mov esi, 0x1451 */
L_00a57fe6:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
L_00a57fe9:;
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000a400], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00a58001; /* jle 0xa58001 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a57ffdu); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a58010; /* jmp 0xa58010 */
L_00a58001:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov ecx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00a58010:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a58019; /* je 0xa58019 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a57fe9; /* jmp 0xa57fe9 */
L_00a58019:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00a5801e; /* jmp 0xa5801e */
L_00a5801c:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00a5801e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00a58106; /* je 0xa58106 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00a5804a; /* jbe 0xa5804a */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00a5803e; /* jl 0xa5803e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00a5803e:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00a5804d; /* jmp 0xa5804d */
L_00a5804a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00a5804d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00a580fc; /* jbe 0xa580fc */
L_00a58057:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00a58065; /* jne 0xa58065 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00a58057; /* jmp 0xa58057 */
L_00a58065:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58075u); f_00a57bdf(c); /* call 0xa57bdf */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00a58084; /* jge 0xa58084 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00a58084:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00a5808f; /* jne 0xa5808f */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00a5808f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00a58097; /* jne 0xa58097 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00a58097:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00a580ce; /* jle 0xa580ce */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00a580a5:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00a580b1:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00a58117; /* je 0xa58117 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00a5812c; /* jmp 0xa5812c */
L_00a580ce:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00a580de; /* jge 0xa580de */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00a580a5; /* jmp 0xa580a5 */
L_00a580de:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a580ebu); f_00a587ea(c); /* call 0xa587ea */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00a580b1; /* jmp 0xa580b1 */
L_00a580fc:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00a580b1; /* jmp 0xa580b1 */
L_00a58106:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00a5812c; /* jmp 0xa5812c */
L_00a58117:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00a5812c; /* je 0xa5812c */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00a5812c:;
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

void f_00a57d10(CPU *c) { /* PTR_00a57d10 */
    PREEMPT_POLL(c);
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00a57d21; /* jl 0xa57d21 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00a57d21; /* jg 0xa57d21 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00a57f3e; /* jmp 0xa57f3e */
L_00a57d21:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xa5a404u))); /* cmp bl, byte ptr [0x1000a404] */
    if (!c->zf) goto L_00a57d30; /* jne 0xa57d30 */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00a57f76; /* jmp 0xa57f76 */
L_00a57d30:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00a57d56; /* je 0xa57d56 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00a57d4a; /* je 0xa57d4a */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00a58019; /* jne 0xa58019 */
    goto L_00a57dd9; /* jmp 0xa57dd9 */
L_00a57d4a:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00a57cfdu, 0x00a57d54u); return; } /* jmp 0xa57cfd */
L_00a57d56:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00a57cfdu, 0x00a57d5du); return; } /* jmp 0xa57cfd */
L_00a57dd9:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { jump_indirect(c, 0x00a57cfdu, 0x00a57ddbu); return; } /* jmp 0xa57cfd */
L_00a57f3e:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { jump_indirect(c, 0x00a57cfdu, 0x00a57f40u); return; } /* jmp 0xa57cfd */
L_00a57f76:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00a57cfdu, 0x00a57f77u); return; } /* jmp 0xa57cfd */
L_00a58019:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00a5801e; /* jmp 0xa5801e */
L_00a5801e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00a58106; /* je 0xa58106 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00a5804a; /* jbe 0xa5804a */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00a5803e; /* jl 0xa5803e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00a5803e:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00a5804d; /* jmp 0xa5804d */
L_00a5804a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00a5804d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00a580fc; /* jbe 0xa580fc */
L_00a58057:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00a58065; /* jne 0xa58065 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00a58057; /* jmp 0xa58057 */
L_00a58065:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58075u); f_00a57bdf(c); /* call 0xa57bdf */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00a58084; /* jge 0xa58084 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00a58084:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00a5808f; /* jne 0xa5808f */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00a5808f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00a58097; /* jne 0xa58097 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00a58097:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00a580ce; /* jle 0xa580ce */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00a580a5:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00a580b1:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00a58117; /* je 0xa58117 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00a5812c; /* jmp 0xa5812c */
L_00a580ce:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00a580de; /* jge 0xa580de */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00a580a5; /* jmp 0xa580a5 */
L_00a580de:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a580ebu); f_00a587ea(c); /* call 0xa587ea */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00a580b1; /* jmp 0xa580b1 */
L_00a580fc:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00a580b1; /* jmp 0xa580b1 */
L_00a58106:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00a5812c; /* jmp 0xa5812c */
L_00a58117:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00a5812c; /* je 0xa5812c */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00a5812c:;
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

void f_00a57f8e(CPU *c) { /* PTR_00a57f8e */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00a5801e; /* jmp 0xa5801e */
L_00a5801e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00a58106; /* je 0xa58106 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00a5804a; /* jbe 0xa5804a */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00a5803e; /* jl 0xa5803e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00a5803e:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00a5804d; /* jmp 0xa5804d */
L_00a5804a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00a5804d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00a580fc; /* jbe 0xa580fc */
L_00a58057:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00a58065; /* jne 0xa58065 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00a58057; /* jmp 0xa58057 */
L_00a58065:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58075u); f_00a57bdf(c); /* call 0xa57bdf */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00a58084; /* jge 0xa58084 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00a58084:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00a5808f; /* jne 0xa5808f */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00a5808f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00a58097; /* jne 0xa58097 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00a58097:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00a580ce; /* jle 0xa580ce */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00a580a5:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00a580b1:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00a58117; /* je 0xa58117 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00a5812c; /* jmp 0xa5812c */
L_00a580ce:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00a580de; /* jge 0xa580de */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00a580a5; /* jmp 0xa580a5 */
L_00a580de:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a580ebu); f_00a587ea(c); /* call 0xa587ea */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00a580b1; /* jmp 0xa580b1 */
L_00a580fc:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00a580b1; /* jmp 0xa580b1 */
L_00a58106:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00a5812c; /* jmp 0xa5812c */
L_00a58117:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00a5812c; /* je 0xa5812c */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00a5812c:;
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

void f_00a58147(CPU *c) { /* PTR_00a58147 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ebx >> 8))))); } /* adc byte ptr [ebp], bh */
    { uint32_t a_ = (uint32_t)(c->edi + 0x7du); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ebx)))); } /* adc byte ptr [edi + 0x7d], bl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x7du) << 8); /* mov dh, 0x7d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x00a58153u, "unsupported: loopne 0xa581d2"); /* loopne 0xa581d2 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->edx + 0xe810007eu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->edx >> 8))))); } /* adc byte ptr [edx - 0x17efff82], dh */
    if ((c->zf || c->sf != c->of)) goto L_00a58162; /* jle 0xa58162 */
L_00a58162:;
    { uint32_t a_ = (uint32_t)(c->edx); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->edx >> 8))))); } /* adc byte ptr [edx], dh */
    if ((!c->zf && c->sf == c->of)) goto L_00a58166; /* jg 0xa58166 */
L_00a58166:;
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [ecx], dl */
    if ((!c->zf && c->sf == c->of)) goto L_00a5816a; /* jg 0xa5816a */
L_00a5816a:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x8010007fu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [esi - 0x7fefff81], dl */
    if ((!c->zf && c->sf == c->of)) goto L_00a58172; /* jg 0xa58172 */
L_00a58172:;
    { uint32_t a_ = (uint32_t)(c->edi + c->edi * 2); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ecx)))); } /* adc byte ptr [edi + edi*2], cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffff8bu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [ebp - 0x75], dl */
    { jump_indirect(c, 0x00a58179u, 0x00a58176u); return; }
}

void f_00a58177(CPU *c) { /* FUN_10008177 */
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
    if (c->zf) goto L_00a581d9; /* je 0xa581d9 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx + 2], 0x2d */
    goto L_00a581dd; /* jmp 0xa581dd */
L_00a581d9:;
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
L_00a581dd:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    if (!c->zf) goto L_00a58203; /* jne 0xa58203 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00a58203; /* jne 0xa58203 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (!c->zf) goto L_00a58203; /* jne 0xa58203 */
L_00a581ee:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ebx + 0x4u), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebx + 4], 0x30 */
    goto L_00a58401; /* jmp 0xa58401 */
L_00a58203:;
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->esi)); /* cmp dx, si */
    if (!c->zf) goto L_00a58282; /* jne 0xa58282 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    W16((uint32_t)(c->ebx), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [ebx], 1 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00a5821c; /* jne 0xa5821c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00a5822b; /* je 0xa5822b */
L_00a5821c:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x40000000u)); /* test edi, 0x40000000 */
    if (!c->zf) goto L_00a5822b; /* jne 0xa5822b */
    { uint32_t v_ = 0xa596b0u; PUSH32(c, v_); } /* push 0x100096b0 */
    goto L_00a58271; /* jmp 0xa58271 */
L_00a5822b:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->ecx) & ((uint16_t)c->ecx))); /* test cx, cx */
    if (c->zf) goto L_00a58245; /* je 0xa58245 */
    (void)sub32(c, c->edi, (uint32_t)0xc0000000u); /* cmp edi, 0xc0000000 */
    if (!c->zf) goto L_00a58245; /* jne 0xa58245 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00a5826c; /* jne 0xa5826c */
    { uint32_t v_ = 0xa596a8u; PUSH32(c, v_); } /* push 0x100096a8 */
    goto L_00a58254; /* jmp 0xa58254 */
L_00a58245:;
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00a5826c; /* jne 0xa5826c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00a5826c; /* jne 0xa5826c */
    { uint32_t v_ = 0xa596a0u; PUSH32(c, v_); } /* push 0x100096a0 */
L_00a58254:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a5825du); f_00a55080(c); /* call 0xa55080 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [ebx + 3], 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a58263:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    goto L_00a583da; /* jmp 0xa583da */
L_00a5826c:;
    { uint32_t v_ = 0xa59698u; PUSH32(c, v_); } /* push 0x10009698 */
L_00a58271:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a5827au); f_00a55080(c); /* call 0xa55080 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [ebx + 3], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a58263; /* jmp 0xa58263 */
L_00a58282:;
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
    PUSH32(c, 0x00a582c8u); f_00a587ea(c); /* call 0xa587ea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xfffffffau)), (uint16_t)0x3fffu); /* cmp word ptr [ebp - 6], 0x3fff */
    if (c->cf) goto L_00a582e3; /* jb 0xa582e3 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a582e1u); f_00a585ca(c); /* call 0xa585ca */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a582e3:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x18u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x18], 1 */
    W16((uint32_t)(c->ebx), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [ebx], si */
    if (c->zf) goto L_00a582fd; /* je 0xa582fd */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->esi)); /* movsx eax, si */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((!c->zf && c->sf == c->of)) goto L_00a58300; /* jg 0xa58300 */
    goto L_00a581ee; /* jmp 0xa581ee */
L_00a582fd:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
L_00a58300:;
    (void)sub32(c, c->edi, (uint32_t)0x15u); /* cmp edi, 0x15 */
    if ((c->zf || c->sf != c->of)) goto L_00a58308; /* jle 0xa58308 */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a58308:;
    c->esi = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xfffffffau))); /* movzx esi, word ptr [ebp - 6] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3ffeu)); /* sub esi, 0x3ffe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffau); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebp - 6], 0 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x1c], 8 */
L_00a5831e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58327u); f_00a57b84(c); /* call 0xa57b84 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a5831e; /* jne 0xa5831e */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00a58348; /* jge 0xa58348 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffu))); /* and esi, 0xff */
    if ((c->zf || c->sf != c->of)) goto L_00a58348; /* jle 0xa58348 */
L_00a5833b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58344u); f_00a57bb2(c); /* call 0xa57bb2 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a5833b; /* jne 0xa5833b */
L_00a58348:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea ecx, [edi + 1] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
    if ((c->zf || c->sf != c->of)) goto L_00a583a5; /* jle 0xa583a5 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x14], ecx */
L_00a58358:;
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea esi, [ebp - 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea edi, [ebp + 8] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00a5836au); f_00a57b84(c); /* call 0xa57b84 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58373u); f_00a57b84(c); /* call 0xa57b84 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58380u); f_00a57b26(c); /* call 0xa57b26 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58389u); f_00a57b84(c); /* call 0xa57b84 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffbu))); /* mov al, byte ptr [ebp - 5] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffbu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 5], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x30u)); /* add al, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x14] */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    if (!c->zf) goto L_00a58358; /* jne 0xa58358 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
L_00a583a5:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xffffffffu))); /* mov cl, byte ptr [eax - 1] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x35u); /* cmp cl, 0x35 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ecx, [ebx + 4] */
    if ((c->sf != c->of)) goto L_00a583e2; /* jl 0xa583e2 */
L_00a583b2:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00a583c5; /* jb 0xa583c5 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00a583c1; /* jne 0xa583c1 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00a583b2; /* jmp 0xa583b2 */
L_00a583c1:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00a583c9; /* jae 0xa583c9 */
L_00a583c5:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebx] */
L_00a583c9:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00a583cb:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx))); /* sub al, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x3u)); /* sub al, 3 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebx + 3], al */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ebx + 4], 0 */
L_00a583da:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00a583dd:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a583e2:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00a583f2; /* jb 0xa583f2 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (!c->zf) goto L_00a583ee; /* jne 0xa583ee */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00a583e2; /* jmp 0xa583e2 */
L_00a583ee:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00a583cb; /* jae 0xa583cb */
L_00a583f2:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00a58401:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x5u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebx + 5], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a583dd; /* jmp 0xa583dd */
}

void f_00a5840a(CPU *c) { /* FUN_1000840a */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00a5840fu); f_00a52439(c); /* call 0xa52439 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00a58413(CPU *c) { /* FUN_10008413 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xa5d118u)), c->ebx); /* cmp dword ptr [0x1000d118], ebx */
    if (!c->zf) goto L_00a58431; /* jne 0xa58431 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00a58480; /* jl 0xa58480 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00a58480; /* jg 0xa58480 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a58431:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xa5d274u); /* mov esi, 0x1000d274 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xa590a8u)); PUSH32(c, 0x00a5843fu); call_indirect(c, t_); } /* call dword ptr [0x100090a8] */
    (void)sub32(c, R32((uint32_t)(0xa5d270u)), c->ebx); /* cmp dword ptr [0x1000d270], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0xa590a4u))); /* mov edi, dword ptr [0x100090a4] */
    if (c->zf) goto L_00a5845b; /* je 0xa5845b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a58450u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a58457u); f_00a53a0d(c); /* call 0xa53a0d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00a5845b:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00a58464u); f_00a58482(c); /* call 0xa58482 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00a58477; /* je 0xa58477 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a58474u); f_00a53a6e(c); /* call 0xa53a6e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a5847a; /* jmp 0xa5847a */
L_00a58477:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a5847au); call_indirect(c, t_); } /* call edi */
L_00a5847a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a58480:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a58482(CPU *c) { /* FUN_10008482 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xa5d118u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d118], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_00a584ad; /* jne 0xa584ad */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00a5854b; /* jl 0xa5854b */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00a5854b; /* jg 0xa5854b */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_00a5854b; /* jmp 0xa5854b */
L_00a584ad:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_00a584e0; /* jge 0xa584e0 */
    (void)sub32(c, R32((uint32_t)(0xa5a400u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000a400], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00a584cd; /* jle 0xa584cd */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a584c9u); f_00a5494f(c); /* call 0xa5494f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a584d8; /* jmp 0xa584d8 */
L_00a584cd:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov eax, dword ptr [0x1000a40c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_00a584d8:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a584e0; /* jne 0xa584e0 */
L_00a584dc:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00a5854b; /* jmp 0xa5854b */
L_00a584e0:;
    c->edx = (uint32_t)(R32((uint32_t)(0xa5a40cu))); /* mov edx, dword ptr [0x1000a40c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00a58503; /* je 0xa58503 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00a5850c; /* jmp 0xa5850c */
L_00a58503:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00a5850c:;
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
    { uint32_t v_ = R32((uint32_t)(0xa5d118u)); PUSH32(c, v_); } /* push dword ptr [0x1000d118] */
    PUSH32(c, 0x00a5852cu); f_00a578b6(c); /* call 0xa578b6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a584dc; /* je 0xa584dc */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00a5853e; /* jne 0xa5853e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00a5854b; /* jmp 0xa5854b */
L_00a5853e:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00a5854b:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a58550(CPU *c) { /* FUN_10008550 */
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
L_00a58564:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a58571; /* je 0xa58571 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00a58564; /* jmp 0xa58564 */
L_00a58571:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_00a58578:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a58586; /* je 0xa58586 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00a58578; /* jae 0xa58578 */
L_00a58586:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a58590(CPU *c) { /* FUN_10008590 */
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
L_00a585a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a585b1; /* je 0xa585b1 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00a585a4; /* jmp 0xa585a4 */
L_00a585b1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00a585b4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a585c4; /* je 0xa585c4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00a585b4; /* jae 0xa585b4 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00a585c4:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a585ca(CPU *c) { /* FUN_100085ca */
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
    if (!c->cf) goto L_00a587ca; /* jae 0xa587ca */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7fffu); /* cmp cx, 0x7fff */
    if (!c->cf) goto L_00a587ca; /* jae 0xa587ca */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xbffdu); /* cmp dx, 0xbffd */
    if ((!c->cf && !c->zf)) goto L_00a587ca; /* ja 0xa587ca */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x3fbfu); /* cmp dx, 0x3fbf */
    if ((!c->cf && !c->zf)) goto L_00a58633; /* ja 0xa58633 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a5866d; /* jmp 0xa5866d */
L_00a58633:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    c->edx = (uint32_t)((uint32_t)0x7fffffffu); /* mov edx, 0x7fffffff */
    if (!c->zf) goto L_00a58655; /* jne 0xa58655 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + 0x8u)) & c->edx)); /* test dword ptr [esi + 8], edx */
    if (!c->zf) goto L_00a58655; /* jne 0xa58655 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), c->eax); /* cmp dword ptr [esi + 4], eax */
    if (!c->zf) goto L_00a58657; /* jne 0xa58657 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_00a58657; /* jne 0xa58657 */
    goto L_00a587c4; /* jmp 0xa587c4 */
L_00a58655:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a58657:;
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_00a5867a; /* jne 0xa5867a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->edx)); /* test dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00a5867a; /* jne 0xa5867a */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x4u)), c->eax); /* cmp dword ptr [ebx + 4], eax */
    if (!c->zf) goto L_00a5867a; /* jne 0xa5867a */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (!c->zf) goto L_00a5867a; /* jne 0xa5867a */
L_00a5866d:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00a587e5; /* jmp 0xa587e5 */
L_00a5867a:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [ebp + 0xc], 5 */
L_00a5868a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00a586de; /* jle 0xa586de */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea ecx, [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
L_00a586a6:;
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
    PUSH32(c, 0x00a586c4u); f_00a57b05(c); /* call 0xa57b05 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a586d1; /* je 0xa586d1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [eax] */
L_00a586d1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 8], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x2u))); } /* sub dword ptr [ebp - 0xc], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_00a586a6; /* jne 0xa586a6 */
L_00a586de:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 4], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a5868a; /* jg 0xa5868a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xc002u))); } /* add dword ptr [ebp + 8], 0xc002 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00a58721; /* jle 0xa58721 */
L_00a586fc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffe7u)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 0x19], 0x80 */
    if (!c->zf) goto L_00a5871a; /* jne 0xa5871a */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a5870bu); f_00a57b84(c); /* call 0xa57b84 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a586fc; /* jg 0xa586fc */
L_00a5871a:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a5875a; /* jg 0xa5875a */
L_00a58721:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->sf == c->of)) goto L_00a5875a; /* jge 0xa5875a */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0x8u))); /* movsx eax, word ptr [ebp + 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00a5873a:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffdcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x24], 1 */
    if (c->zf) goto L_00a58743; /* je 0xa58743 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x14] */
L_00a58743:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a5874cu); f_00a57bb2(c); /* call 0xa57bb2 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a5873a; /* jne 0xa5873a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_00a5875a; /* je 0xa5875a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x24], 1 */
L_00a5875a:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffdcu)), (uint16_t)0x8000u); /* cmp word ptr [ebp - 0x24], 0x8000 */
    if ((!c->cf && !c->zf)) goto L_00a58771; /* ja 0xa58771 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1ffffu))); /* and eax, 0x1ffff */
    (void)sub32(c, c->eax, (uint32_t)0x18000u); /* cmp eax, 0x18000 */
    if (!c->zf) goto L_00a587a6; /* jne 0xa587a6 */
L_00a58771:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdeu)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x22], -1 */
    if (!c->zf) goto L_00a587a3; /* jne 0xa587a3 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x22], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe2u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x1e], -1 */
    if (!c->zf) goto L_00a5879e; /* jne 0xa5879e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1e], 0 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffe6u)), (uint16_t)0xffffu); /* cmp word ptr [ebp - 0x1a], 0xffff */
    if (!c->zf) goto L_00a58798; /* jne 0xa58798 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    W16((uint32_t)(c->ebp + 0xffffffe6u), (uint16_t)((uint16_t)0x8000u)); /* mov word ptr [ebp - 0x1a], 0x8000 */
    goto L_00a587a6; /* jmp 0xa587a6 */
L_00a58798:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe6u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebp - 0x1a] */
    goto L_00a587a6; /* jmp 0xa587a6 */
L_00a5879e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1e] */
    goto L_00a587a6; /* jmp 0xa587a6 */
L_00a587a3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x22] */
L_00a587a6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    if (!c->cf) goto L_00a587ca; /* jae 0xa587ca */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffdeu))); /* mov cx, word ptr [ebp - 0x22] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [esi], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->esi + 0x2u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 2], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->esi + 0x6u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 6], ecx */
L_00a587c4:;
    W16((uint32_t)(c->esi + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xa], ax */
    goto L_00a587e5; /* jmp 0xa587e5 */
L_00a587ca:;
    c->edi = (c->edi & 0xffff0000u) | (uint16_t)(neg16(c, ((uint16_t)c->edi))); /* neg di */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edi)); /* sbb edi, edi */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x80000000u))); /* and edi, 0x80000000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7fff8000u)); /* add edi, 0x7fff8000 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
L_00a587e5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a587ea(CPU *c) { /* FUN_100087ea */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)0xa5cb00u); /* mov ebx, 0x1000cb00 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00a58863; /* je 0xa58863 */
    if ((c->sf == c->of)) goto L_00a58812; /* jge 0xa58812 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0xa5cc60u); /* mov ebx, 0x1000cc60 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
L_00a58812:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00a5881d; /* jne 0xa5881d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
L_00a5881d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00a58863; /* je 0xa58863 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00a58824:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x54u)); /* add ebx, 0x54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sar32(c, R32(a_), 3))); } /* sar dword ptr [ebp + 0xc], 3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00a5885c; /* je 0xa5885c */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)sub16(c, R16((uint32_t)(c->ebx + c->eax * 4)), (uint16_t)0x8000u); /* cmp word ptr [ebx + eax*4], 0x8000 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea esi, [ebx + eax*4] */
    if (c->cf) goto L_00a5884f; /* jb 0xa5884f */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff6u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xa] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
L_00a5884f:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a58858u); f_00a585ca(c); /* call 0xa585ca */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00a5885c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_00a58824; /* jne 0xa58824 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a58863:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a58870(CPU *c) { /* FUN_10008870 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0xa5d110u)); /* lea eax, [0x1000d110] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00a588c3; /* jne 0xa588c3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00a5888c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a588be; /* je 0xa588be */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00a5888c; /* je 0xa5888c */
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
    if (c->zf) goto L_00a5888c; /* je 0xa5888c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_00a588be:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_00a5893b; /* jmp 0xa5893b */
L_00a588c3:;
    { guest_lock(); guest_trap(c, 0x00a588c3u, "unsupported: lock inc dword ptr [0x1000d274]"); guest_unlock(); } /* lock inc dword ptr [0x1000d274] */
    (void)sub32(c, R32((uint32_t)(0xa5d270u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d270], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a588d7; /* jg 0xa588d7 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00a588ec; /* jmp 0xa588ec */
L_00a588d7:;
    { guest_lock(); guest_trap(c, 0x00a588d7u, "unsupported: lock dec dword ptr [0x1000d274]"); guest_unlock(); } /* lock dec dword ptr [0x1000d274] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a588e5u); f_00a53a0d(c); /* call 0xa53a0d */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_00a588ec:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_00a588f4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a5891f; /* je 0xa5891f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a588f4; /* je 0xa588f4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a58909u); f_00a54a33(c); /* call 0xa54a33 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00a58913u); f_00a54a33(c); /* call 0xa54a33 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_00a588f4; /* je 0xa588f4 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_00a5891f:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00a5892f; /* jne 0xa5892f */
    { guest_lock(); guest_trap(c, 0x00a58926u, "unsupported: lock dec dword ptr [0x1000d274]"); guest_unlock(); } /* lock dec dword ptr [0x1000d274] */
    goto L_00a58939; /* jmp 0xa58939 */
L_00a5892f:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a58936u); f_00a53a6e(c); /* call 0xa53a6e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a58939:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00a5893b:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a58940(CPU *c) { /* FUN_10008940 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_00a58a3a; /* je 0xa58a3a */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0xa5d110u)); /* lea eax, [0x1000d110] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00a589b1; /* jne 0xa589b1 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_00a5896c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_00a58995; /* je 0xa58995 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a58995; /* je 0xa58995 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_00a58984; /* jb 0xa58984 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_00a58984; /* ja 0xa58984 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_00a58984:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_00a5898e; /* jb 0xa5898e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_00a5898e; /* ja 0xa5898e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_00a5898e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_00a5899f; /* jne 0xa5899f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00a5896c; /* jne 0xa5896c */
L_00a58995:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00a58a3a; /* je 0xa58a3a */
L_00a5899f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00a58a3a; /* jb 0xa58a3a */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_00a58a3a; /* jmp 0xa58a3a */
L_00a589b1:;
    { guest_lock(); guest_trap(c, 0x00a589b1u, "unsupported: lock inc dword ptr [0x1000d274]"); guest_unlock(); } /* lock inc dword ptr [0x1000d274] */
    (void)sub32(c, R32((uint32_t)(0xa5d270u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d270], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a589c5; /* jg 0xa589c5 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00a589de; /* jmp 0xa589de */
L_00a589c5:;
    { guest_lock(); guest_trap(c, 0x00a589c5u, "unsupported: lock dec dword ptr [0x1000d274]"); guest_unlock(); } /* lock dec dword ptr [0x1000d274] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a589d5u); f_00a53a0d(c); /* call 0xa53a0d */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00a589de:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00a589e4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_00a58a0f; /* je 0xa58a0f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_00a58a0f; /* je 0xa58a0f */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a589fau); f_00a54a33(c); /* call 0xa54a33 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00a58a04u); f_00a54a33(c); /* call 0xa54a33 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00a58a15; /* jne 0xa58a15 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00a589e4; /* jne 0xa589e4 */
L_00a58a0f:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00a58a1e; /* je 0xa58a1e */
L_00a58a15:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00a58a1e; /* jb 0xa58a1e */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_00a58a1e:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00a58a2c; /* jne 0xa58a2c */
    { guest_lock(); guest_trap(c, 0x00a58a23u, "unsupported: lock dec dword ptr [0x1000d274]"); guest_unlock(); } /* lock dec dword ptr [0x1000d274] */
    goto L_00a58a3a; /* jmp 0xa58a3a */
L_00a58a2c:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a58a35u); f_00a53a6e(c); /* call 0xa53a6e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00a58a3a:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a58a50(CPU *c) { /* PTR_00a58a50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00a58a72; /* jne 0xa58a72 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a58a64u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a58a6cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00a58ab3; /* jmp 0xa58ab3 */
L_00a58a72:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_00a58a80:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00a58a80; /* jne 0xa58a80 */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a58a8cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x18u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint64_t r_ = (uint64_t)c->eax * c->esi; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul esi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_00a58aae; /* jb 0xa58aae */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x10u))); /* cmp edx, dword ptr [esp + 0x10] */
    if ((!c->cf && !c->zf)) goto L_00a58aae; /* ja 0xa58aae */
    if (c->cf) goto L_00a58aaf; /* jb 0xa58aaf */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0xcu))); /* cmp eax, dword ptr [esp + 0xc] */
    if ((c->cf || c->zf)) goto L_00a58aaf; /* jbe 0xa58aaf */
L_00a58aae:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
L_00a58aaf:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a58ab3:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00a58ac0(CPU *c) { /* PTR_00a58ac0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00a58ae1; /* jne 0xa58ae1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a58ad3u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a58ad9u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_00a58b31; /* jmp 0xa58b31 */
L_00a58ae1:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
L_00a58aef:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00a58aef; /* jne 0xa58aef */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00a58afbu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_00a58b1a; /* jb 0xa58b1a */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0xcu))); /* cmp edx, dword ptr [esp + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00a58b1a; /* ja 0xa58b1a */
    if (c->cf) goto L_00a58b22; /* jb 0xa58b22 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u))); /* cmp eax, dword ptr [esp + 8] */
    if ((c->cf || c->zf)) goto L_00a58b22; /* jbe 0xa58b22 */
L_00a58b1a:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x10u)))); /* sub eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0x14u)))); /* sbb edx, dword ptr [esp + 0x14] */
L_00a58b22:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0xcu)))); /* sbb edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(sbb32(c, c->edx, (uint32_t)0x0u)); /* sbb edx, 0 */
L_00a58b31:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00a58b40(CPU *c) { /* PTR_00a58b40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_00a58b59; /* jne 0xa58b59 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00a58b59:;
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

void f_00a58b74(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xa59000u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a58b74u); return; } } /* jmp dword ptr [0x10009000] */
}

void f_00a58b80(CPU *c) { /* Unwind@10008b80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = 0xa5a084u; PUSH32(c, v_); } /* push 0x1000a084 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58b90u); f_00a51310(c); /* call 0xa51310 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00a58b94(CPU *c) { /* PTR_00a58b94 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa5986cu); /* mov eax, 0x1000986c */
    { f_00a51d63(c); return; } /* jmp 0xa51d63 */
}

void f_00a58ba0(CPU *c) { /* Unwind@10008ba0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00a51b40(c); return; } /* jmp 0xa51b40 */
}

void f_00a58ba8(CPU *c) { /* PTR_00a58ba8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa59890u); /* mov eax, 0x10009890 */
    { f_00a51d63(c); return; } /* jmp 0xa51d63 */
}

void f_00a58bc0(CPU *c) { /* Unwind@10008bc0 */
    PREEMPT_POLL(c);
    goto L_00a58bc0;
L_00a51be0:;
    c->esp += 4; return; /* ret  */
L_00a58bc0:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    goto L_00a51be0; /* jmp 0xa51be0 */
}

void f_00a58bcb(CPU *c) { /* Unwind@10008bcb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    { uint32_t v_ = 0xa5a084u; PUSH32(c, v_); } /* push 0x1000a084 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffda0u))); /* mov eax, dword ptr [ebp - 0x260] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a58bdeu); f_00a51310(c); /* call 0xa51310 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00a58be2(CPU *c) { /* PTR_00a58be2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa598f0u); /* mov eax, 0x100098f0 */
    { f_00a51d63(c); return; } /* jmp 0xa51d63 */
}
