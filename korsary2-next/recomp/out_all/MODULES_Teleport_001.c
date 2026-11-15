#include "recomp.h"

void f_009e723c(CPU *c) { /* PTR_009e723c */
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
    if (c->cf) { f_009e71fc(c); return; } /* jb 0x9e71fc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e7258u); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e7260(CPU *c) { /* PTR_009e7260 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_009e71fc(c); return; } /* jb 0x9e71fc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e7272u); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e729c(CPU *c) { /* PTR_009e729c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72a4(CPU *c) { /* PTR_009e72a4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72ac(CPU *c) { /* PTR_009e72ac */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72b4(CPU *c) { /* PTR_009e72b4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72bc(CPU *c) { /* PTR_009e72bc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72c4(CPU *c) { /* PTR_009e72c4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72cc(CPU *c) { /* PTR_009e72cc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72df(CPU *c) { /* PTR_009e72df */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e72e8u)); switch (t_) { case 0x009e72f8u: goto L_009e72f8; case 0x009e7300u: goto L_009e7300; case 0x009e730cu: goto L_009e730c; case 0x009e7320u: goto L_009e7320; default: jump_indirect(c, t_, 0x009e72dfu); return; } } /* jmp dword ptr [edx*4 + 0x100072e8] */
L_009e72f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7300:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e730c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7320:;
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

void f_009e72f8(CPU *c) { /* PTR_009e72f8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e7300(CPU *c) { /* PTR_009e7300 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e730c(CPU *c) { /* PTR_009e730c */
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

void f_009e7320(CPU *c) { /* PTR_009e7320 */
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

void f_009e7360(CPU *c) { /* PTR_009e7360 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x9e7430u)); switch (t_) { case 0x009e7477u: goto L_009e7477; default: jump_indirect(c, t_, 0x009e7362u); return; } } /* jmp dword ptr [ecx*4 + 0x10007430] */
L_009e7477:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7398(CPU *c) { /* PTR_009e7398 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_009e7360(c); return; } /* jb 0x9e7360 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e73aeu); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e73b8(CPU *c) { /* PTR_009e73b8 */
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
    if (c->cf) { f_009e7360(c); return; } /* jb 0x9e7360 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e73d8u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e73e0(CPU *c) { /* PTR_009e73e0 */
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
    if (c->cf) { f_009e7360(c); return; } /* jb 0x9e7360 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e740au); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7434(CPU *c) { /* PTR_009e7434 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e743c(CPU *c) { /* PTR_009e743c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7444(CPU *c) { /* PTR_009e7444 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e744c(CPU *c) { /* PTR_009e744c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7454(CPU *c) { /* PTR_009e7454 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e745c(CPU *c) { /* PTR_009e745c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7464(CPU *c) { /* PTR_009e7464 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7477(CPU *c) { /* PTR_009e7477 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x9e7480u)); switch (t_) { case 0x009e7490u: goto L_009e7490; case 0x009e7498u: goto L_009e7498; case 0x009e74a8u: goto L_009e74a8; case 0x009e74bcu: goto L_009e74bc; default: jump_indirect(c, t_, 0x009e7477u); return; } } /* jmp dword ptr [edx*4 + 0x10007480] */
L_009e7490:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e7498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e74bc:;
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

void f_009e7490(CPU *c) { /* PTR_009e7490 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e7498(CPU *c) { /* PTR_009e7498 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e74a8(CPU *c) { /* PTR_009e74a8 */
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

void f_009e74bc(CPU *c) { /* PTR_009e74bc */
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

void f_009e74d5(CPU *c) { /* FUN_100074d5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x9ef720u))); /* cmp esi, dword ptr [0x1000f720] */
    if (!c->cf) goto L_009e7522; /* jae 0x9e7522 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 4 + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [ecx + eax*4 + 4], 1 */
    if (c->zf) goto L_009e7522; /* je 0x9e7522 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e7504u); f_009e884d(c); /* call 0x9e884d */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e7512u); f_009e753a(c); /* call 0x9e753a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x009e751au); f_009e88ac(c); /* call 0x9e88ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009e7522:;
    PUSH32(c, 0x009e7527u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x009e7532u); f_009e8783(c); /* call 0x9e8783 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e753a(CPU *c) { /* FUN_1000753a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e7546u); f_009e880b(c); /* call 0x9e880b */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009e7559; /* jne 0x9e7559 */
    PUSH32(c, 0x009e7551u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    goto L_009e7586; /* jmp 0x9e7586 */
L_009e7559:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea0b0u)); PUSH32(c, 0x009e756au); call_indirect(c, t_); } /* call dword ptr [0x1000a0b0] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (!c->zf) goto L_009e7579; /* jne 0x9e7579 */
    { uint32_t t_ = R32((uint32_t)(0x9ea02cu)); PUSH32(c, 0x009e7577u); call_indirect(c, t_); } /* call dword ptr [0x1000a02c] */
    goto L_009e757b; /* jmp 0x9e757b */
L_009e7579:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e757b:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e758b; /* je 0x9e758b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e7585u); f_009e8707(c); /* call 0x9e8707 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e7586:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_009e75aa; /* jmp 0x9e75aa */
L_009e758b:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x1fu))); /* and esi, 0x1f */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax * 4 + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0xfdu)))); } /* and byte ptr [ecx + eax*4 + 4], 0xfd */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4 + 0x4u)); /* lea eax, [ecx + eax*4 + 4] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_009e75aa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e75ad(CPU *c) { /* FUN_100075ad */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x9ef720u))); /* cmp esi, dword ptr [0x1000f720] */
    if (!c->cf) goto L_009e75fa; /* jae 0x9e75fa */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 4 + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [ecx + eax*4 + 4], 1 */
    if (c->zf) goto L_009e75fa; /* je 0x9e75fa */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e75dcu); f_009e884d(c); /* call 0x9e884d */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e75eau); f_009e7612(c); /* call 0x9e7612 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x009e75f2u); f_009e88ac(c); /* call 0x9e88ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009e75fa:;
    PUSH32(c, 0x009e75ffu); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x009e760au); f_009e8783(c); /* call 0x9e8783 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e7612(CPU *c) { /* FUN_10007612 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x414u)); /* sub esp, 0x414 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edi); /* cmp dword ptr [ebp + 0x10], edi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x10], edi */
    if (!c->zf) goto L_009e7632; /* jne 0x9e7632 */
L_009e762b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_009e7798; /* jmp 0x9e7798 */
L_009e7632:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ebx = (uint32_t)((uint32_t)(c->eax * 4 + 0x9ef620u)); /* lea ebx, [eax*4 + 0x1000f620] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea esi, [eax + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x20u)); /* test byte ptr [eax + esi + 4], 0x20 */
    if (c->zf) goto L_009e7662; /* je 0x9e7662 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009e765fu); f_009e753a(c); /* call 0x9e753a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_009e7662:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x80u)); /* test byte ptr [eax + 4], 0x80 */
    if (c->zf) goto L_009e7731; /* je 0x9e7731 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edi); /* cmp dword ptr [ebp + 0x10], edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
    if ((c->cf || c->zf)) goto L_009e776c; /* jbe 0x9e776c */
L_009e7682:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffbecu)); /* lea eax, [ebp - 0x414] */
L_009e7688:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_009e76bc; /* jae 0x9e76bc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov cl, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xau); /* cmp cl, 0xa */
    if (!c->zf) goto L_009e76a7; /* jne 0x9e76a7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0xdu)); /* mov byte ptr [eax], 0xd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_009e76a7:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffbecu)); /* lea edx, [ebp - 0x414] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if ((c->sf != c->of)) goto L_009e7688; /* jl 0x9e7688 */
L_009e76bc:;
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffbecu)); /* lea eax, [ebp - 0x414] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffbecu)); /* lea eax, [ebp - 0x414] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = R32((uint32_t)(c->eax + c->esi)); PUSH32(c, v_); } /* push dword ptr [eax + esi] */
    { uint32_t t_ = R32((uint32_t)(0x9ea09cu)); PUSH32(c, 0x009e76dfu); call_indirect(c, t_); } /* call dword ptr [0x1000a09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e7726; /* je 0x9e7726 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp - 8], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->sf != c->of)) goto L_009e76f8; /* jl 0x9e76f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu)))); /* sub eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if (c->cf) goto L_009e7682; /* jb 0x9e7682 */
L_009e76f8:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_009e76fa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_009e7795; /* jne 0x9e7795 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (c->zf) goto L_009e776c; /* je 0x9e776c */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->esi); /* cmp dword ptr [ebp + 8], esi */
    if (!c->zf) goto L_009e775e; /* jne 0x9e775e */
    PUSH32(c, 0x009e7717u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x009e7722u); f_009e8783(c); /* call 0x9e8783 */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    goto L_009e7767; /* jmp 0x9e7767 */
L_009e7726:;
    { uint32_t t_ = R32((uint32_t)(0x9ea02cu)); PUSH32(c, 0x009e772cu); call_indirect(c, t_); } /* call dword ptr [0x1000a02c] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    goto L_009e76f8; /* jmp 0x9e76f8 */
L_009e7731:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea ecx, [ebp - 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(0x9ea09cu)); PUSH32(c, 0x009e7744u); call_indirect(c, t_); } /* call dword ptr [0x1000a09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e7753; /* je 0x9e7753 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_009e76fa; /* jmp 0x9e76fa */
L_009e7753:;
    { uint32_t t_ = R32((uint32_t)(0x9ea02cu)); PUSH32(c, 0x009e7759u); call_indirect(c, t_); } /* call dword ptr [0x1000a02c] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    goto L_009e76fa; /* jmp 0x9e76fa */
L_009e775e:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009e7766u); f_009e8707(c); /* call 0x9e8707 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e7767:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_009e7798; /* jmp 0x9e7798 */
L_009e776c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x40u)); /* test byte ptr [eax + esi + 4], 0x40 */
    if (c->zf) goto L_009e7781; /* je 0x9e7781 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x1au); /* cmp byte ptr [eax], 0x1a */
    if (c->zf) goto L_009e762b; /* je 0x9e762b */
L_009e7781:;
    PUSH32(c, 0x009e7786u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x1cu)); /* mov dword ptr [eax], 0x1c */
    PUSH32(c, 0x009e7791u); f_009e8783(c); /* call 0x9e8783 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    goto L_009e7767; /* jmp 0x9e7767 */
L_009e7795:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub eax, dword ptr [ebp - 0x10] */
L_009e7798:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e779d(CPU *c) { /* FUN_1000779d */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(0x9ee1f4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000e1f4] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    PUSH32(c, 0x009e77adu); f_009e421a(c); /* call 0x9e421a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    if (c->zf) goto L_009e77c6; /* je 0x9e77c6 */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ecx + 0xc], 8 */
    W32((uint32_t)(c->ecx + 0x18u), (uint32_t)((uint32_t)0x1000u)); /* mov dword ptr [ecx + 0x18], 0x1000 */
    goto L_009e77d7; /* jmp 0x9e77d7 */
L_009e77c6:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ecx + 0xc], 4 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x14u)); /* lea eax, [ecx + 0x14] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    W32((uint32_t)(c->ecx + 0x18u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ecx + 0x18], 2 */
L_009e77d7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 4; return; /* ret  */
}

void f_009e77e1(CPU *c) { /* FUN_100077e1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9ef720u))); /* cmp eax, dword ptr [0x1000f720] */
    if (c->cf) goto L_009e77f0; /* jb 0x9e77f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_009e77f0:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 4 + 0x4u))); /* mov al, byte ptr [ecx + eax*4 + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x40u))); /* and eax, 0x40 */
    c->esp += 4; return; /* ret  */
}

void f_009e780a(CPU *c) { /* PTR_009e780a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x9ef5e0u))); /* mov eax, dword ptr [0x1000f5e0] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_009e781e; /* jne 0x9e781e */
    c->eax = (uint32_t)((uint32_t)0x200u); /* mov eax, 0x200 */
    goto L_009e7824; /* jmp 0x9e7824 */
L_009e781e:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf == c->of)) goto L_009e7829; /* jge 0x9e7829 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_009e7824:;
    W32((uint32_t)(0x9ef5e0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f5e0], eax */
L_009e7829:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e7831u); f_009e5e15(c); /* call 0x9e5e15 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x9ee5c8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e5c8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009e785d; /* jne 0x9e785d */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(0x9ef5e0u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000f5e0], esi */
    PUSH32(c, 0x009e784au); f_009e5e15(c); /* call 0x9e5e15 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x9ee5c8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e5c8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009e785d; /* jne 0x9e785d */
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    PUSH32(c, 0x009e785cu); f_009e3205(c); /* call 0x9e3205 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e785d:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x9ed580u); /* mov eax, 0x1000d580 */
L_009e7864:;
    c->edx = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov edx, dword ptr [0x1000e5c8] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x9ed800u); /* cmp eax, 0x1000d800 */
    if ((c->sf != c->of)) goto L_009e7864; /* jl 0x9e7864 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)((uint32_t)0x9ed590u); /* mov edx, 0x1000d590 */
L_009e7881:;
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 5)); /* sar esi, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi * 4 + 0x9ef620u))); /* mov esi, dword ptr [esi*4 + 0x1000f620] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4))); /* mov eax, dword ptr [esi + eax*4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_009e78a1; /* je 0x9e78a1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e78a4; /* jne 0x9e78a4 */
L_009e78a1:;
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edx], 0xffffffff */
L_009e78a4:;
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x20u)); /* add edx, 0x20 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->edx, (uint32_t)0x9ed5f0u); /* cmp edx, 0x1000d5f0 */
    if ((c->sf != c->of)) goto L_009e7881; /* jl 0x9e7881 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e78b2(CPU *c) { /* PTR_009e78b2 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x009e78b7u); f_009e89d9(c); /* call 0x9e89d9 */
    (void)sub8(c, R8((uint32_t)(0x9ee06cu)), (uint8_t)0x0u); /* cmp byte ptr [0x1000e06c], 0 */
    if (c->zf) goto L_009e78c5; /* je 0x9e78c5 */
    { f_009e88ce(c); return; } /* jmp 0x9e88ce */
L_009e78c5:;
    c->esp += 4; return; /* ret  */
}

void f_009e78c6(CPU *c) { /* FUN_100078c6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)((uint32_t)0x9ed580u); /* mov ecx, 0x1000d580 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_009e78ea; /* jb 0x9e78ea */
    (void)sub32(c, c->eax, (uint32_t)0x9ed7e0u); /* cmp eax, 0x1000d7e0 */
    if ((!c->cf && !c->zf)) goto L_009e78ea; /* ja 0x9e78ea */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e78e8u); f_009e43e9(c); /* call 0x9e43e9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_009e78ea:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea050u)); PUSH32(c, 0x009e78f4u); call_indirect(c, t_); } /* call dword ptr [0x1000a050] */
    c->esp += 4; return; /* ret  */
}

void f_009e78f5(CPU *c) { /* FUN_100078f5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x14u); /* cmp eax, 0x14 */
    if ((c->sf == c->of)) goto L_009e7909; /* jge 0x9e7909 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e7907u); f_009e43e9(c); /* call 0x9e43e9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_009e7909:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea050u)); PUSH32(c, 0x009e7917u); call_indirect(c, t_); } /* call dword ptr [0x1000a050] */
    c->esp += 4; return; /* ret  */
}

void f_009e7918(CPU *c) { /* FUN_10007918 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)((uint32_t)0x9ed580u); /* mov ecx, 0x1000d580 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_009e793c; /* jb 0x9e793c */
    (void)sub32(c, c->eax, (uint32_t)0x9ed7e0u); /* cmp eax, 0x1000d7e0 */
    if ((!c->cf && !c->zf)) goto L_009e793c; /* ja 0x9e793c */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e793au); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_009e793c:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea054u)); PUSH32(c, 0x009e7946u); call_indirect(c, t_); } /* call dword ptr [0x1000a054] */
    c->esp += 4; return; /* ret  */
}

void f_009e7947(CPU *c) { /* FUN_10007947 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x14u); /* cmp eax, 0x14 */
    if ((c->sf == c->of)) goto L_009e795b; /* jge 0x9e795b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e7959u); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_009e795b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea054u)); PUSH32(c, 0x009e7969u); call_indirect(c, t_); } /* call dword ptr [0x1000a054] */
    c->esp += 4; return; /* ret  */
}

void f_009e7970(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009e7990; /* je 0x9e7990 */
L_009e797c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e79c3; /* je 0x9e79c3 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_009e797c; /* jne 0x9e797c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_009e7990:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009e7990; /* je 0x9e7990 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e79e1; /* je 0x9e79e1 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e79d7; /* je 0x9e79d7 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_009e79cd; /* je 0x9e79cd */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_009e79c3; /* je 0x9e79c3 */
    goto L_009e7990; /* jmp 0x9e7990 */
L_009e79c3:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_009e79cd:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_009e79d7:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_009e79e1:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_009e79eb(CPU *c) { /* FUN_100079eb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x9ee394u); /* mov esi, 0x1000e394 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x9ea0b8u)); PUSH32(c, 0x009e79fdu); call_indirect(c, t_); } /* call dword ptr [0x1000a0b8] */
    c->edi = (uint32_t)(R32((uint32_t)(0x9ea0b4u))); /* mov edi, dword ptr [0x1000a0b4] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x9ee390u)), c->ebx); /* cmp dword ptr [0x1000e390], ebx */
    if (c->zf) goto L_009e7a1b; /* je 0x9e7a1b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009e7a10u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e7a17u); f_009e43e9(c); /* call 0x9e43e9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_009e7a1b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009e7a26u); f_009e7a44(c); /* call 0x9e7a44 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e7a39; /* je 0x9e7a39 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e7a36u); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e7a3c; /* jmp 0x9e7a3c */
L_009e7a39:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009e7a3cu); call_indirect(c, t_); } /* call edi */
L_009e7a3c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009e7a44(CPU *c) { /* FUN_10007a44 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e7a50; /* jne 0x9e7a50 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_009e7a50:;
    (void)sub32(c, R32((uint32_t)(0x9ee230u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000e230], 0 */
    if (!c->zf) goto L_009e7a6b; /* jne 0x9e7a6b */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xcu))); /* mov cx, word ptr [ebp + 0xc] */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0xffu); /* cmp cx, 0xff */
    if ((!c->cf && !c->zf)) goto L_009e7a9d; /* ja 0x9e7a9d */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_009e7a6b:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea ecx, [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 8], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x9edda4u)); PUSH32(c, v_); } /* push dword ptr [0x1000dda4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea eax, [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(0x9ee240u)); PUSH32(c, v_); } /* push dword ptr [0x1000e240] */
    { uint32_t t_ = R32((uint32_t)(0x9ea07cu)); PUSH32(c, 0x009e7a93u); call_indirect(c, t_); } /* call dword ptr [0x1000a07c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e7a9d; /* je 0x9e7a9d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_009e7aab; /* je 0x9e7aab */
L_009e7a9d:;
    PUSH32(c, 0x009e7aa2u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x2au)); /* mov dword ptr [eax], 0x2a */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_009e7aab:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009e7ab0(CPU *c) { /* PTR_009e7ab0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009e7ad2; /* jne 0x9e7ad2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e7ac4u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e7accu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_009e7b13; /* jmp 0x9e7b13 */
L_009e7ad2:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_009e7ae0:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_009e7ae0; /* jne 0x9e7ae0 */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e7aecu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x18u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint64_t r_ = (uint64_t)c->eax * c->esi; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul esi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_009e7b0e; /* jb 0x9e7b0e */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x10u))); /* cmp edx, dword ptr [esp + 0x10] */
    if ((!c->cf && !c->zf)) goto L_009e7b0e; /* ja 0x9e7b0e */
    if (c->cf) goto L_009e7b0f; /* jb 0x9e7b0f */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0xcu))); /* cmp eax, dword ptr [esp + 0xc] */
    if ((c->cf || c->zf)) goto L_009e7b0f; /* jbe 0x9e7b0f */
L_009e7b0e:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
L_009e7b0f:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_009e7b13:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_009e7b20(CPU *c) { /* PTR_009e7b20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009e7b41; /* jne 0x9e7b41 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e7b33u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e7b39u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_009e7b91; /* jmp 0x9e7b91 */
L_009e7b41:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
L_009e7b4f:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_009e7b4f; /* jne 0x9e7b4f */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e7b5bu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_009e7b7a; /* jb 0x9e7b7a */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0xcu))); /* cmp edx, dword ptr [esp + 0xc] */
    if ((!c->cf && !c->zf)) goto L_009e7b7a; /* ja 0x9e7b7a */
    if (c->cf) goto L_009e7b82; /* jb 0x9e7b82 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u))); /* cmp eax, dword ptr [esp + 8] */
    if ((c->cf || c->zf)) goto L_009e7b82; /* jbe 0x9e7b82 */
L_009e7b7a:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x10u)))); /* sub eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0x14u)))); /* sbb edx, dword ptr [esp + 0x14] */
L_009e7b82:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0xcu)))); /* sbb edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(sbb32(c, c->edx, (uint32_t)0x0u)); /* sbb edx, 0 */
L_009e7b91:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_009e7ba0(CPU *c) { /* FUN_10007ba0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    { f_009e7c11(c); return; } /* jmp 0x9e7c11 */
}

void f_009e7bb0(CPU *c) { /* FUN_10007bb0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009e7bcc; /* je 0x9e7bcc */
L_009e7bbd:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e7bff; /* je 0x9e7bff */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_009e7bbd; /* jne 0x9e7bbd */
L_009e7bcc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009e7bcc; /* je 0x9e7bcc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e7c0e; /* je 0x9e7c0e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e7c09; /* je 0x9e7c09 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_009e7c04; /* je 0x9e7c04 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_009e7bff; /* je 0x9e7bff */
    goto L_009e7bcc; /* jmp 0x9e7bcc */
L_009e7bff:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea edi, [ecx - 1] */
    goto L_009e7c11; /* jmp 0x9e7c11 */
L_009e7c04:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea edi, [ecx - 2] */
    goto L_009e7c11; /* jmp 0x9e7c11 */
L_009e7c09:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea edi, [ecx - 3] */
    goto L_009e7c11; /* jmp 0x9e7c11 */
L_009e7c0e:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea edi, [ecx - 4] */
L_009e7c11:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009e7c36; /* je 0x9e7c36 */
L_009e7c1d:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e7c88; /* je 0x9e7c88 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_009e7c1d; /* jne 0x9e7c1d */
    goto L_009e7c36; /* jmp 0x9e7c36 */
L_009e7c31:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_009e7c36:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009e7c31; /* je 0x9e7c31 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e7c88; /* je 0x9e7c88 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_009e7c7f; /* je 0x9e7c7f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_009e7c72; /* je 0x9e7c72 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_009e7c6a; /* je 0x9e7c6a */
    goto L_009e7c31; /* jmp 0x9e7c31 */
L_009e7c6a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e7c72:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e7c7f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e7c88:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_009e7c11(CPU *c) { /* PTR_009e7c11 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009e7c36; /* je 0x9e7c36 */
L_009e7c1d:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e7c88; /* je 0x9e7c88 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_009e7c1d; /* jne 0x9e7c1d */
    goto L_009e7c36; /* jmp 0x9e7c36 */
L_009e7c31:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_009e7c36:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009e7c31; /* je 0x9e7c31 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e7c88; /* je 0x9e7c88 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_009e7c7f; /* je 0x9e7c7f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_009e7c72; /* je 0x9e7c72 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_009e7c6a; /* je 0x9e7c6a */
    goto L_009e7c31; /* jmp 0x9e7c31 */
L_009e7c6a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e7c72:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e7c7f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e7c88:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_009e7c90(CPU *c) { /* FUN_10007c90 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x009e7ca0u); f_009e43e9(c); /* call 0x9e43e9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009e7ca8u); f_009e7e3d(c); /* call 0x9e7e3d */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x9ee398u))); /* cmp ebx, dword ptr [0x1000e398] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->zf) goto L_009e7cbe; /* jne 0x9e7cbe */
L_009e7cb7:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_009e7e2e; /* jmp 0x9e7e2e */
L_009e7cbe:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_009e7e1c; /* je 0x9e7e1c */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0x9eda38u); /* mov eax, 0x1000da38 */
L_009e7ccd:;
    (void)sub32(c, R32((uint32_t)(c->eax)), c->ebx); /* cmp dword ptr [eax], ebx */
    if (c->zf) goto L_009e7d45; /* je 0x9e7d45 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x30u)); /* add eax, 0x30 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0x9edb28u); /* cmp eax, 0x1000db28 */
    if ((c->sf != c->of)) goto L_009e7ccd; /* jl 0x9e7ccd */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x9ea0bcu)); PUSH32(c, 0x009e7ce7u); call_indirect(c, t_); } /* call dword ptr [0x1000a0bc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_009e7e13; /* jne 0x9e7e13 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t a_ = (uint32_t)(0x9ee5c4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000e5c4], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x9ee4c0u); /* mov edi, 0x1000e4c0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->esi); /* cmp dword ptr [ebp - 0x18], esi */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    W32((uint32_t)(0x9ee398u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000e398], ebx */
    if ((c->cf || c->zf)) goto L_009e7e00; /* jbe 0x9e7e00 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffeeu)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x12], 0 */
    if (c->zf) goto L_009e7ddb; /* je 0x9e7ddb */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffefu)); /* lea ecx, [ebp - 0x11] */
L_009e7d22:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e7ddb; /* je 0x9e7ddb */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + 0xffffffffu))); /* movzx eax, byte ptr [ecx - 1] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
L_009e7d33:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((!c->cf && !c->zf)) goto L_009e7dcf; /* ja 0x9e7dcf */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x4u)))); } /* or byte ptr [eax + 0x1000e4c1], 4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_009e7d33; /* jmp 0x9e7d33 */
L_009e7d45:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x9ee4c0u); /* mov edi, 0x1000e4c0 */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea esi, [edx + edx*2] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x9eda48u)); /* lea ebx, [esi + 0x1000da48] */
L_009e7d62:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if (c->zf) goto L_009e7d95; /* je 0x9e7d95 */
L_009e7d69:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e7d95; /* je 0x9e7d95 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx eax, byte ptr [ecx] */
    c->edi = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edi, dl */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((!c->cf && !c->zf)) goto L_009e7d8e; /* ja 0x9e7d8e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x9eda30u))); /* mov dl, byte ptr [edx + 0x1000da30] */
L_009e7d83:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->edx))))); } /* or byte ptr [eax + 0x1000e4c1], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_009e7d83; /* jbe 0x9e7d83 */
L_009e7d8e:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (!c->zf) goto L_009e7d69; /* jne 0x9e7d69 */
L_009e7d95:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x4u); /* cmp dword ptr [ebp - 4], 4 */
    if (c->cf) goto L_009e7d62; /* jb 0x9e7d62 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0x9ee3acu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000e3ac], 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x9ee398u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e398], eax */
    PUSH32(c, 0x009e7db9u); f_009e7e87(c); /* call 0x9e7e87 */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x9eda3cu)); /* lea esi, [esi + 0x1000da3c] */
    c->edi = (uint32_t)((uint32_t)0x9ee3a0u); /* mov edi, 0x1000e3a0 */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x9ee5c4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e5c4], eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_009e7e21; /* jmp 0x9e7e21 */
L_009e7dcf:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0xffffffffu)), (uint8_t)0x0u); /* cmp byte ptr [ecx - 1], 0 */
    if (!c->zf) goto L_009e7d22; /* jne 0x9e7d22 */
L_009e7ddb:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_009e7ddd:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [eax + 0x1000e4c1], 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xffu); /* cmp eax, 0xff */
    if (c->cf) goto L_009e7ddd; /* jb 0x9e7ddd */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e7df2u); f_009e7e87(c); /* call 0x9e7e87 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x9ee5c4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e5c4], eax */
    W32((uint32_t)(0x9ee3acu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000e3ac], esi */
    goto L_009e7e07; /* jmp 0x9e7e07 */
L_009e7e00:;
    { uint32_t a_ = (uint32_t)(0x9ee3acu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000e3ac], 0 */
L_009e7e07:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x9ee3a0u); /* mov edi, 0x1000e3a0 */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    goto L_009e7e21; /* jmp 0x9e7e21 */
L_009e7e13:;
    (void)sub32(c, R32((uint32_t)(0x9ee1f8u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000e1f8], 0 */
    if (c->zf) goto L_009e7e2b; /* je 0x9e7e2b */
L_009e7e1c:;
    PUSH32(c, 0x009e7e21u); f_009e7eba(c); /* call 0x9e7eba */
L_009e7e21:;
    PUSH32(c, 0x009e7e26u); f_009e7ee3(c); /* call 0x9e7ee3 */
    goto L_009e7cb7; /* jmp 0x9e7cb7 */
L_009e7e2b:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_009e7e2e:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x009e7e35u); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e7e3d(CPU *c) { /* FUN_10007e3d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0x9ee1f8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000e1f8], 0 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (!c->zf) goto L_009e7e5d; /* jne 0x9e7e5d */
    W32((uint32_t)(0x9ee1f8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000e1f8], 1 */
    { uint32_t t_ = R32((uint32_t)(0x9ea0c4u)); switch (t_) {  default: jump_indirect(c, t_, 0x009e7e57u); return; } } /* jmp dword ptr [0x1000a0c4] */
L_009e7e5d:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_009e7e72; /* jne 0x9e7e72 */
    W32((uint32_t)(0x9ee1f8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000e1f8], 1 */
    { uint32_t t_ = R32((uint32_t)(0x9ea0c0u)); switch (t_) {  default: jump_indirect(c, t_, 0x009e7e6cu); return; } } /* jmp dword ptr [0x1000a0c0] */
L_009e7e72:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if (!c->zf) goto L_009e7e86; /* jne 0x9e7e86 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee240u))); /* mov eax, dword ptr [0x1000e240] */
    W32((uint32_t)(0x9ee1f8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000e1f8], 1 */
L_009e7e86:;
    c->esp += 4; return; /* ret  */
}

void f_009e7e87(CPU *c) { /* FUN_10007e87 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3a4u)); /* sub eax, 0x3a4 */
    if (c->zf) goto L_009e7eb4; /* je 0x9e7eb4 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_009e7eae; /* je 0x9e7eae */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xdu)); /* sub eax, 0xd */
    if (c->zf) goto L_009e7ea8; /* je 0x9e7ea8 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009e7ea2; /* je 0x9e7ea2 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_009e7ea2:;
    c->eax = (uint32_t)((uint32_t)0x404u); /* mov eax, 0x404 */
    c->esp += 4; return; /* ret  */
L_009e7ea8:;
    c->eax = (uint32_t)((uint32_t)0x412u); /* mov eax, 0x412 */
    c->esp += 4; return; /* ret  */
L_009e7eae:;
    c->eax = (uint32_t)((uint32_t)0x804u); /* mov eax, 0x804 */
    c->esp += 4; return; /* ret  */
L_009e7eb4:;
    c->eax = (uint32_t)((uint32_t)0x411u); /* mov eax, 0x411 */
    c->esp += 4; return; /* ret  */
}

void f_009e7eba(CPU *c) { /* FUN_10007eba */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x9ee4c0u); /* mov edi, 0x1000e4c0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x9ee3a0u); /* mov edi, 0x1000e3a0 */
    W32((uint32_t)(0x9ee398u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e398], eax */
    W32((uint32_t)(0x9ee3acu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e3ac], eax */
    W32((uint32_t)(0x9ee5c4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e5c4], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_009e7ee3(CPU *c) { /* FUN_10007ee3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x514u)); /* sub esp, 0x514 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x9ee398u)); PUSH32(c, v_); } /* push dword ptr [0x1000e398] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0bcu)); PUSH32(c, 0x009e7efdu); call_indirect(c, t_); } /* call dword ptr [0x1000a0bc] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009e801c; /* jne 0x9e801c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_009e7f0d:;
    W8((uint32_t)(c->ebp + c->eax + 0xfffffeecu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + eax - 0x114], al */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_009e7f0d; /* jb 0x9e7f0d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff2u))); /* mov al, byte ptr [ebp - 0xe] */
    W8((uint32_t)(c->ebp + 0xfffffeecu), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x114], 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e7f5e; /* je 0x9e7f5e */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff3u)); /* lea edx, [ebp - 0xd] */
L_009e7f2c:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((!c->cf && !c->zf)) goto L_009e7f53; /* ja 0x9e7f53 */
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
L_009e7f53:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffffu))); /* mov al, byte ptr [edx - 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009e7f2c; /* jne 0x9e7f2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_009e7f5e:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea eax, [ebp - 0x514] */
    { uint32_t v_ = R32((uint32_t)(0x9ee5c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000e5c4] */
    { uint32_t v_ = R32((uint32_t)(0x9ee398u)); PUSH32(c, v_); } /* push dword ptr [0x1000e398] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x009e7f82u); f_009e8cde(c); /* call 0x9e8cde */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdecu)); /* lea eax, [ebp - 0x214] */
    { uint32_t v_ = R32((uint32_t)(0x9ee398u)); PUSH32(c, v_); } /* push dword ptr [0x1000e398] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x9ee5c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000e5c4] */
    PUSH32(c, 0x009e7fa6u); f_009e8a8f(c); /* call 0x9e8a8f */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffcecu)); /* lea eax, [ebp - 0x314] */
    { uint32_t v_ = R32((uint32_t)(0x9ee398u)); PUSH32(c, v_); } /* push dword ptr [0x1000e398] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0x9ee5c4u)); PUSH32(c, v_); } /* push dword ptr [0x1000e5c4] */
    PUSH32(c, 0x009e7fceu); f_009e8a8f(c); /* call 0x9e8a8f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea ecx, [ebp - 0x514] */
L_009e7fd9:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx))); /* mov dx, word ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    if (c->zf) goto L_009e7ff7; /* je 0x9e7ff7 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x1000e4c1], 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffdecu))); /* mov dl, byte ptr [ebp + eax - 0x214] */
L_009e7fef:;
    W8((uint32_t)(c->eax + 0x9ee3c0u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x1000e3c0], dl */
    goto L_009e8013; /* jmp 0x9e8013 */
L_009e7ff7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x2u)); /* test dl, 2 */
    if (c->zf) goto L_009e800c; /* je 0x9e800c */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x1000e4c1], 0x20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffcecu))); /* mov dl, byte ptr [ebp + eax - 0x314] */
    goto L_009e7fef; /* jmp 0x9e7fef */
L_009e800c:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee3c0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x1000e3c0], 0 */
L_009e8013:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_009e7fd9; /* jb 0x9e7fd9 */
    goto L_009e8065; /* jmp 0x9e8065 */
L_009e801c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_009e8023:;
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if (c->cf) goto L_009e8041; /* jb 0x9e8041 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->cf && !c->zf)) goto L_009e8041; /* ja 0x9e8041 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x1000e4c1], 0x10 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_009e8039:;
    W8((uint32_t)(c->eax + 0x9ee3c0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x1000e3c0], cl */
    goto L_009e8060; /* jmp 0x9e8060 */
L_009e8041:;
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if (c->cf) goto L_009e8059; /* jb 0x9e8059 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->cf && !c->zf)) goto L_009e8059; /* ja 0x9e8059 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee4c1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x1000e4c1], 0x20 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    goto L_009e8039; /* jmp 0x9e8039 */
L_009e8059:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x9ee3c0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x1000e3c0], 0 */
L_009e8060:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_009e8023; /* jb 0x9e8023 */
L_009e8065:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e8068(CPU *c) { /* FUN_10008068 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x9ef728u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000f728], 0 */
    if (!c->zf) goto L_009e8083; /* jne 0x9e8083 */
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    PUSH32(c, 0x009e8078u); f_009e7c90(c); /* call 0x9e7c90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x9ef728u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000f728], 1 */
L_009e8083:;
    c->esp += 4; return; /* ret  */
}

void f_009e8084(CPU *c) { /* FUN_10008084 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x009e8097u); f_009e809b(c); /* call 0x9e809b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_009e809b(CPU *c) { /* FUN_1000809b */
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
L_009e80b3:;
    (void)sub32(c, R32((uint32_t)(0x9edda4u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000dda4], 1 */
    if ((c->zf || c->sf != c->of)) goto L_009e80cb; /* jle 0x9e80cb */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e80c7u); f_009e8f62(c); /* call 0x9e8f62 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e80da; /* jmp 0x9e80da */
L_009e80cb:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov ecx, dword ptr [0x1000d818] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_009e80da:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e80e3; /* je 0x9e80e3 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_009e80b3; /* jmp 0x9e80b3 */
L_009e80e3:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    if (!c->zf) goto L_009e80f1; /* jne 0x9e80f1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp + 0x14], 2 */
    goto L_009e80f6; /* jmp 0x9e80f6 */
L_009e80f1:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (!c->zf) goto L_009e80fc; /* jne 0x9e80fc */
L_009e80f6:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_009e80fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_009e8290; /* jl 0x9e8290 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_009e8290; /* je 0x9e8290 */
    (void)sub32(c, c->eax, (uint32_t)0x24u); /* cmp eax, 0x24 */
    if ((!c->zf && c->sf == c->of)) goto L_009e8290; /* jg 0x9e8290 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009e8144; /* jne 0x9e8144 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_009e812e; /* je 0x9e812e */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp + 0x10], 0xa */
    goto L_009e8160; /* jmp 0x9e8160 */
L_009e812e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_009e8141; /* je 0x9e8141 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (c->zf) goto L_009e8141; /* je 0x9e8141 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x10], 8 */
    goto L_009e8160; /* jmp 0x9e8160 */
L_009e8141:;
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
L_009e8144:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_009e8160; /* jne 0x9e8160 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_009e8160; /* jne 0x9e8160 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_009e8158; /* je 0x9e8158 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (!c->zf) goto L_009e8160; /* jne 0x9e8160 */
L_009e8158:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov bl, byte ptr [esi + 1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_009e8160:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e8165u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)0x103u); /* mov edi, 0x103 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_009e8170:;
    (void)sub32(c, R32((uint32_t)(0x9edda4u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000dda4], 1 */
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    if ((c->zf || c->sf != c->of)) goto L_009e8188; /* jle 0x9e8188 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e8184u); f_009e8f62(c); /* call 0x9e8f62 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e8193; /* jmp 0x9e8193 */
L_009e8188:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov eax, dword ptr [0x1000d818] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_009e8193:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e819f; /* je 0x9e819f */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x30u)); /* sub ecx, 0x30 */
    goto L_009e81d1; /* jmp 0x9e81d1 */
L_009e819f:;
    (void)sub32(c, R32((uint32_t)(0x9edda4u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000dda4], 1 */
    if ((c->zf || c->sf != c->of)) goto L_009e81b3; /* jle 0x9e81b3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e81afu); f_009e8f62(c); /* call 0x9e8f62 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e81be; /* jmp 0x9e81be */
L_009e81b3:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov eax, dword ptr [0x1000d818] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + c->esi * 2))); /* mov ax, word ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edi))); /* and eax, edi */
L_009e81be:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e820c; /* je 0x9e820c */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e81cbu); f_009e8e27(c); /* call 0x9e8e27 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x37u)); /* sub ecx, 0x37 */
L_009e81d1:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_009e820c; /* jae 0x9e820c */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp + 0x14], 8 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u))); /* cmp esi, dword ptr [ebp - 0xc] */
    if (c->cf) goto L_009e81f6; /* jb 0x9e81f6 */
    if (!c->zf) goto L_009e81f0; /* jne 0x9e81f0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009e81e9u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->cf || c->zf)) goto L_009e81f6; /* jbe 0x9e81f6 */
L_009e81f0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp + 0x14], 4 */
    goto L_009e81ff; /* jmp 0x9e81ff */
L_009e81f6:;
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
L_009e81ff:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    goto L_009e8170; /* jmp 0x9e8170 */
L_009e820c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_009e8229; /* jne 0x9e8229 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_009e8223; /* je 0x9e8223 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_009e8223:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    goto L_009e8274; /* jmp 0x9e8274 */
L_009e8229:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
    if (!c->zf) goto L_009e824d; /* jne 0x9e824d */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (!c->zf) goto L_009e8274; /* jne 0x9e8274 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    if (c->zf) goto L_009e8244; /* je 0x9e8244 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x80000000u); /* cmp dword ptr [ebp - 8], 0x80000000 */
    if ((!c->cf && !c->zf)) goto L_009e824d; /* ja 0x9e824d */
L_009e8244:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e8274; /* jne 0x9e8274 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->esi); /* cmp dword ptr [ebp - 8], esi */
    if ((c->cf || c->zf)) goto L_009e8274; /* jbe 0x9e8274 */
L_009e824d:;
    PUSH32(c, 0x009e8252u); f_009e877a(c); /* call 0x9e877a */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x14], 1 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    if (c->zf) goto L_009e8264; /* je 0x9e8264 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    goto L_009e8274; /* jmp 0x9e8274 */
L_009e8264:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u))); /* and al, 2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(neg8(c, ((uint8_t)c->eax))); /* neg al */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_009e8274:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_009e827d; /* je 0x9e827d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_009e827d:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x2u)); /* test byte ptr [ebp + 0x14], 2 */
    if (c->zf) goto L_009e828b; /* je 0x9e828b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_009e828b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    goto L_009e829b; /* jmp 0x9e829b */
L_009e8290:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8299; /* je 0x9e8299 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
L_009e8299:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e829b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e82a0(CPU *c) { /* PTR_009e82a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e82b0(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_009e82b0;
L_009e82a0:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e82b0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_009e82db; /* je 0x9e82db */
L_009e82c8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_009e82a0; /* je 0x9e82a0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_009e8324; /* je 0x9e8324 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_009e82c8; /* jne 0x9e82c8 */
L_009e82db:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_009e82e6:;
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
    if (!c->zf) goto L_009e8328; /* jne 0x9e8328 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_009e82e6; /* je 0x9e82e6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_009e8322; /* jne 0x9e8322 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_009e82e6; /* jne 0x9e82e6 */
L_009e8322:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_009e8324:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_009e8328:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009e8365; /* je 0x9e8365 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009e835e; /* je 0x9e835e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009e8357; /* je 0x9e8357 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009e8350; /* je 0x9e8350 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    goto L_009e82e6; /* jmp 0x9e82e6 */
L_009e8350:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e8357:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e835e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e8365:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e82b6(CPU *c) { /* PTR_009e82b6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_009e82db; /* je 0x9e82db */
L_009e82c8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_009e82a0(c); return; } /* je 0x9e82a0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_009e8324; /* je 0x9e8324 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_009e82c8; /* jne 0x9e82c8 */
L_009e82db:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_009e82e6:;
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
    if (!c->zf) goto L_009e8328; /* jne 0x9e8328 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_009e82e6; /* je 0x9e82e6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_009e8322; /* jne 0x9e8322 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_009e82e6; /* jne 0x9e82e6 */
L_009e8322:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_009e8324:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_009e8328:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009e8365; /* je 0x9e8365 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009e835e; /* je 0x9e835e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009e8357; /* je 0x9e8357 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_009e8350; /* je 0x9e8350 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e8322; /* je 0x9e8322 */
    goto L_009e82e6; /* jmp 0x9e82e6 */
L_009e8350:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e8357:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e835e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e8365:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e8370(CPU *c) { /* _strstr */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009e83ea; /* je 0x9e83ea */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_009e83d7; /* je 0x9e83d7 */
L_009e8388:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_009e83aa; /* je 0x9e83aa */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e83a4; /* je 0x9e83a4 */
L_009e8399:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_009e839c:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_009e83aa; /* je 0x9e83aa */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_009e8399; /* jne 0x9e8399 */
L_009e83a4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_009e83aa:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_009e839c; /* jne 0x9e839c */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_009e83b4:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009e83e3; /* je 0x9e83e3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_009e8388; /* jne 0x9e8388 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009e83e3; /* je 0x9e83e3 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_009e83b4; /* je 0x9e83b4 */
    goto L_009e8388; /* jmp 0x9e8388 */
L_009e83d7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_009e82b6(c); return; } /* jmp 0x9e82b6 */
L_009e83e3:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e83ea:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_009e83f0(CPU *c) { /* _strncmp */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    if (c->ecx == 0) goto L_009e8421; /* jecxz 0x9e8421 */
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
    if ((!c->cf && !c->zf)) goto L_009e841f; /* ja 0x9e841f */
    if (c->zf) goto L_009e8421; /* je 0x9e8421 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_009e841f:;
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
L_009e8421:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e8430(CPU *c) { /* FUN_10008430 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_009e8450; /* jb 0x9e8450 */
L_009e843c:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_009e843c; /* jae 0x9e843c */
L_009e8450:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_009e845f(CPU *c) { /* FUN_1000845f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x9ee1fcu)), c->ebx); /* cmp dword ptr [0x1000e1fc], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_009e84ae; /* jne 0x9e84ae */
    { uint32_t v_ = 0x9ea6f0u; PUSH32(c, v_); } /* push 0x1000a6f0 */
    { uint32_t t_ = R32((uint32_t)(0x9ea0ccu)); PUSH32(c, 0x009e8477u); call_indirect(c, t_); } /* call dword ptr [0x1000a0cc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_009e84e4; /* je 0x9e84e4 */
    c->esi = (uint32_t)(R32((uint32_t)(0x9ea0c8u))); /* mov esi, dword ptr [0x1000a0c8] */
    { uint32_t v_ = 0x9ea6e4u; PUSH32(c, v_); } /* push 0x1000a6e4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x009e848bu); call_indirect(c, t_); } /* call esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x9ee1fcu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e1fc], eax */
    if (c->zf) goto L_009e84e4; /* je 0x9e84e4 */
    { uint32_t v_ = 0x9ea6d4u; PUSH32(c, v_); } /* push 0x1000a6d4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x009e849cu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = 0x9ea6c0u; PUSH32(c, v_); } /* push 0x1000a6c0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0x9ee200u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e200], eax */
    { uint32_t t_ = c->esi; PUSH32(c, 0x009e84a9u); call_indirect(c, t_); } /* call esi */
    W32((uint32_t)(0x9ee204u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e204], eax */
L_009e84ae:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee200u))); /* mov eax, dword ptr [0x1000e200] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e84cd; /* je 0x9e84cd */
    { uint32_t t_ = c->eax; PUSH32(c, 0x009e84b9u); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_009e84cd; /* je 0x9e84cd */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee204u))); /* mov eax, dword ptr [0x1000e204] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e84cd; /* je 0x9e84cd */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x009e84cbu); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_009e84cd:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x9ee1fcu)); PUSH32(c, 0x009e84e0u); call_indirect(c, t_); } /* call dword ptr [0x1000e1fc] */
L_009e84e0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e84e4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_009e84e0; /* jmp 0x9e84e0 */
}

void f_009e84f0(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_009e8543; /* je 0x9e8543 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_009e8537; /* jb 0x9e8537 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_009e8519; /* je 0x9e8519 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_009e8513:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_009e8513; /* jne 0x9e8513 */
L_009e8519:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_009e8537; /* je 0x9e8537 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_009e853d; /* je 0x9e853d */
L_009e8537:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_009e8537; /* jne 0x9e8537 */
L_009e853d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009e8543:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_009e8548(CPU *c) { /* FUN_10008548 */
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
    if (c->zf) goto L_009e85c3; /* je 0x9e85c3 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009e85a6; /* je 0x9e85a6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_009e85a6; /* je 0x9e85a6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_009e85a6; /* je 0x9e85a6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_009e8599; /* je 0x9e8599 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_009e858c; /* je 0x9e858c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009e857f; /* je 0x9e857f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_009e86c5; /* jmp 0x9e86c5 */
L_009e857f:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x9ee210u))); /* mov ebx, dword ptr [0x1000e210] */
    c->edi = (uint32_t)((uint32_t)0x9ee210u); /* mov edi, 0x1000e210 */
    goto L_009e85ce; /* jmp 0x9e85ce */
L_009e858c:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x9ee20cu))); /* mov ebx, dword ptr [0x1000e20c] */
    c->edi = (uint32_t)((uint32_t)0x9ee20cu); /* mov edi, 0x1000e20c */
    goto L_009e85ce; /* jmp 0x9e85ce */
L_009e8599:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x9ee214u))); /* mov ebx, dword ptr [0x1000e214] */
    c->edi = (uint32_t)((uint32_t)0x9ee214u); /* mov edi, 0x1000e214 */
    goto L_009e85ce; /* jmp 0x9e85ce */
L_009e85a6:;
    PUSH32(c, 0x009e85abu); f_009e3b21(c); /* call 0x9e3b21 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x50u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x50] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009e85b8u); f_009e86ca(c); /* call 0x9e86ca */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    goto L_009e85e0; /* jmp 0x9e85e0 */
L_009e85c3:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x9ee208u))); /* mov ebx, dword ptr [0x1000e208] */
    c->edi = (uint32_t)((uint32_t)0x9ee208u); /* mov edi, 0x1000e208 */
L_009e85ce:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x009e85dcu); f_009e43e9(c); /* call 0x9e43e9 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e85e0:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (!c->zf) goto L_009e85fb; /* jne 0x9e85fb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_009e86c3; /* je 0x9e86c3 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e85f5u); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e86c3; /* jmp 0x9e86c3 */
L_009e85fb:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (!c->zf) goto L_009e8615; /* jne 0x9e8615 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ecx); /* cmp dword ptr [ebp - 4], ecx */
    if (c->zf) goto L_009e860e; /* je 0x9e860e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x009e860du); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e860e:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x009e8615u); f_009e3d0c(c); /* call 0x9e3d0c */
L_009e8615:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (c->zf) goto L_009e8627; /* je 0x9e8627 */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if (c->zf) goto L_009e8627; /* je 0x9e8627 */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_009e8642; /* jne 0x9e8642 */
L_009e8627:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if (!c->zf) goto L_009e867e; /* jne 0x9e867e */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [esi + 0x58], 0x8c */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_009e8642:;
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (!c->zf) goto L_009e867e; /* jne 0x9e867e */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9eb548u))); /* mov ecx, dword ptr [0x1000b548] */
    c->eax = (uint32_t)(R32((uint32_t)(0x9eb54cu))); /* mov eax, dword ptr [0x1000b54c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_009e8680; /* jge 0x9e8680 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
L_009e865e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx + eax - 4], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0x9eb548u))); /* mov edx, dword ptr [0x1000b548] */
    c->edi = (uint32_t)(R32((uint32_t)(0x9eb54cu))); /* mov edi, dword ptr [0x1000b54c] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if ((c->sf != c->of)) goto L_009e865e; /* jl 0x9e865e */
    goto L_009e8680; /* jmp 0x9e8680 */
L_009e867e:;
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
L_009e8680:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_009e868e; /* je 0x9e868e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x009e868du); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e868e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    if (!c->zf) goto L_009e869f; /* jne 0x9e869f */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x58] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x009e869bu); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e86b1; /* jmp 0x9e86b1 */
L_009e869f:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x009e86a4u); call_indirect(c, t_); } /* call ebx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0xbu); /* cmp dword ptr [ebp + 8], 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e86b1; /* je 0x9e86b1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x4u); /* cmp dword ptr [ebp + 8], 4 */
    if (!c->zf) goto L_009e86c3; /* jne 0x9e86c3 */
L_009e86b1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if (!c->zf) goto L_009e86c3; /* jne 0x9e86c3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_009e86c3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e86c5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e86ca(CPU *c) { /* FUN_100086ca */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9eb554u))); /* mov ecx, dword ptr [0x1000b554] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    if (c->zf) goto L_009e86f3; /* je 0x9e86f3 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edi, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->edi * 4)); /* lea edi, [edx + edi*4] */
L_009e86e7:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_009e86f3; /* jae 0x9e86f3 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (!c->zf) goto L_009e86e7; /* jne 0x9e86e7 */
L_009e86f3:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea ecx, [edx + ecx*4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_009e8702; /* jae 0x9e8702 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (c->zf) goto L_009e8704; /* je 0x9e8704 */
L_009e8702:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e8704:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e8707(CPU *c) { /* FUN_10008707 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e870du); f_009e8783(c); /* call 0x9e8783 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)0x9edb30u); /* mov eax, 0x1000db30 */
L_009e871a:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax))); /* cmp ecx, dword ptr [eax] */
    if (c->zf) goto L_009e8740; /* je 0x9e8740 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->eax, (uint32_t)0x9edc98u); /* cmp eax, 0x1000dc98 */
    if ((c->sf != c->of)) goto L_009e871a; /* jl 0x9e871a */
    (void)sub32(c, c->ecx, (uint32_t)0x13u); /* cmp ecx, 0x13 */
    if (c->cf) goto L_009e8750; /* jb 0x9e8750 */
    (void)sub32(c, c->ecx, (uint32_t)0x24u); /* cmp ecx, 0x24 */
    if ((!c->cf && !c->zf)) goto L_009e8750; /* ja 0x9e8750 */
    PUSH32(c, 0x009e8738u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xdu)); /* mov dword ptr [eax], 0xd */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009e8740:;
    PUSH32(c, 0x009e8745u); f_009e877a(c); /* call 0x9e877a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi * 8 + 0x9edb34u))); /* mov ecx, dword ptr [esi*8 + 0x1000db34] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp += 4; return; /* ret  */
L_009e8750:;
    (void)sub32(c, c->ecx, (uint32_t)0xbcu); /* cmp ecx, 0xbc */
    if (c->cf) goto L_009e876d; /* jb 0x9e876d */
    (void)sub32(c, c->ecx, (uint32_t)0xcau); /* cmp ecx, 0xca */
    if ((!c->cf && !c->zf)) goto L_009e876d; /* ja 0x9e876d */
    PUSH32(c, 0x009e8765u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [eax], 8 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009e876d:;
    PUSH32(c, 0x009e8772u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x16u)); /* mov dword ptr [eax], 0x16 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e877a(CPU *c) { /* FUN_1000877a */
    PREEMPT_POLL(c);
    PUSH32(c, 0x009e877fu); f_009e3b21(c); /* call 0x9e3b21 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_009e8783(CPU *c) { /* FUN_10008783 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x009e8788u); f_009e3b21(c); /* call 0x9e3b21 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009e878c(CPU *c) { /* FUN_1000878c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x9ef720u))); /* cmp ecx, dword ptr [0x1000f720] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->cf) goto L_009e87f2; /* jae 0x9e87f2 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->edi = (uint32_t)((uint32_t)(c->eax * 4 + 0x9ef620u)); /* lea edi, [eax*4 + 0x1000f620] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea esi, [eax + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [eax + 4], 1 */
    if (c->zf) goto L_009e87f2; /* je 0x9e87f2 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (c->zf) goto L_009e87f2; /* je 0x9e87f2 */
    (void)sub32(c, R32((uint32_t)(0x9ee030u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000e030], 1 */
    if (!c->zf) goto L_009e87e8; /* jne 0x9e87e8 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    if (c->zf) goto L_009e87df; /* je 0x9e87df */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_009e87da; /* je 0x9e87da */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_009e87e8; /* jne 0x9e87e8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    goto L_009e87e2; /* jmp 0x9e87e2 */
L_009e87da:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffff5u; PUSH32(c, v_); } /* push -0xb */
    goto L_009e87e2; /* jmp 0x9e87e2 */
L_009e87df:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
L_009e87e2:;
    { uint32_t t_ = R32((uint32_t)(0x9ea0d0u)); PUSH32(c, 0x009e87e8u); call_indirect(c, t_); } /* call dword ptr [0x1000a0d0] */
L_009e87e8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t a_ = (uint32_t)(c->eax + c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax + esi], 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_009e8808; /* jmp 0x9e8808 */
L_009e87f2:;
    PUSH32(c, 0x009e87f7u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x009e8802u); f_009e8783(c); /* call 0x9e8783 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_009e8808:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e880b(CPU *c) { /* FUN_1000880b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9ef720u))); /* cmp eax, dword ptr [0x1000f720] */
    if (!c->cf) goto L_009e8836; /* jae 0x9e8836 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 4 + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [ecx + eax*4 + 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    if (c->zf) goto L_009e8836; /* je 0x9e8836 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->esp += 4; return; /* ret  */
L_009e8836:;
    PUSH32(c, 0x009e883bu); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x009e8846u); f_009e8783(c); /* call 0x9e8783 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esp += 4; return; /* ret  */
}

void f_009e884d(CPU *c) { /* FUN_1000884d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov esi, dword ptr [ecx*4 + 0x1000f620] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx * 4 + 0x9ef620u)); /* lea ebx, [ecx*4 + 0x1000f620] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea edi, [eax + eax*8] */
    c->edi = (uint32_t)(shl32(c, c->edi, 2)); /* shl edi, 2 */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 8], 0 */
    if (!c->zf) goto L_009e889b; /* jne 0x9e889b */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x009e887fu); f_009e43e9(c); /* call 0x9e43e9 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 8], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009e8893; /* jne 0x9e8893 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea eax, [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea048u)); PUSH32(c, 0x009e8890u); call_indirect(c, t_); } /* call dword ptr [0x1000a048] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_009e8893:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x009e889au); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e889b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi + 0xcu)); /* lea eax, [eax + edi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea050u)); PUSH32(c, 0x009e88a8u); call_indirect(c, t_); } /* call dword ptr [0x1000a050] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e88ac(CPU *c) { /* FUN_100088ac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4 + 0xcu)); /* lea eax, [ecx + eax*4 + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea054u)); PUSH32(c, 0x009e88cdu); call_indirect(c, t_); } /* call dword ptr [0x1000a054] */
    c->esp += 4; return; /* ret  */
}

void f_009e88ce(CPU *c) { /* PTR_009e88ce */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    PUSH32(c, 0x009e88d9u); f_009e43e9(c); /* call 0x9e43e9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x9ef5e0u)), c->edi); /* cmp dword ptr [0x1000f5e0], edi */
    if ((c->zf || c->sf != c->of)) goto L_009e8942; /* jle 0x9e8942 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_009e88e6:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov eax, dword ptr [esi + eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8938; /* je 0x9e8938 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [eax + 0xc], 0x83 */
    if (c->zf) goto L_009e890a; /* je 0x9e890a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e8903u); f_009e8fd7(c); /* call 0x9e8fd7 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e890a; /* je 0x9e890a */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_009e890a:;
    (void)sub32(c, c->edi, (uint32_t)0x14u); /* cmp edi, 0x14 */
    if ((c->sf != c->of)) goto L_009e8938; /* jl 0x9e8938 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov eax, dword ptr [esi + eax] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea04cu)); PUSH32(c, 0x009e8921u); call_indirect(c, t_); } /* call dword ptr [0x1000a04c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    { uint32_t v_ = R32((uint32_t)(c->esi + c->eax)); PUSH32(c, v_); } /* push dword ptr [esi + eax] */
    PUSH32(c, 0x009e892eu); f_009e445f(c); /* call 0x9e445f */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->esi + c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + eax], 0 */
L_009e8938:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, R32((uint32_t)(0x9ef5e0u))); /* cmp edi, dword ptr [0x1000f5e0] */
    if ((c->sf != c->of)) goto L_009e88e6; /* jl 0x9e88e6 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_009e8942:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x009e8949u); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e894f(CPU *c) { /* FUN_1000894f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e895au); f_009e897d(c); /* call 0x9e897d */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e8964; /* je 0x9e8964 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009e8964:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xdu)) & (uint8_t)0x40u)); /* test byte ptr [esi + 0xd], 0x40 */
    if (c->zf) goto L_009e8979; /* je 0x9e8979 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x009e8972u); f_009e9054(c); /* call 0x9e9054 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->esp += 4; return; /* ret  */
L_009e8979:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e897d(CPU *c) { /* FUN_1000897d */
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
    if (!c->zf) goto L_009e89ca; /* jne 0x9e89ca */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x108u)); /* test ax, 0x108 */
    if (c->zf) goto L_009e89ca; /* je 0x9e89ca */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_009e89ca; /* jle 0x9e89ca */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x009e89aeu); f_009e75ad(c); /* call 0x9e75ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_009e89c3; /* jne 0x9e89c3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x80u)); /* test al, 0x80 */
    if (c->zf) goto L_009e89ca; /* je 0x9e89ca */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    goto L_009e89ca; /* jmp 0x9e89ca */
L_009e89c3:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | (uint32_t)0xffffffffu))); /* or ebx, 0xffffffff */
L_009e89ca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e89d9(CPU *c) { /* PTR_009e89d9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x009e89e0u); f_009e89e2(c); /* call 0x9e89e2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_009e89e2(CPU *c) { /* FUN_100089e2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    PUSH32(c, 0x009e89f0u); f_009e43e9(c); /* call 0x9e43e9 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, R32((uint32_t)(0x9ef5e0u)), c->esi); /* cmp dword ptr [0x1000f5e0], esi */
    if ((c->zf || c->sf != c->of)) goto L_009e8a6f; /* jle 0x9e8a6f */
L_009e89fb:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8a66; /* je 0x9e8a66 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [eax + 0xc], 0x83 */
    if (c->zf) goto L_009e8a66; /* je 0x9e8a66 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e8a14u); f_009e78f5(c); /* call 0x9e78f5 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x83u)); /* test cl, 0x83 */
    if (c->zf) goto L_009e8a56; /* je 0x9e8a56 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0x10], 1 */
    if (!c->zf) goto L_009e8a3c; /* jne 0x9e8a3c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e8a33u); f_009e894f(c); /* call 0x9e894f */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e8a56; /* je 0x9e8a56 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_009e8a56; /* jmp 0x9e8a56 */
L_009e8a3c:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0x10], 0 */
    if (!c->zf) goto L_009e8a56; /* jne 0x9e8a56 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_009e8a56; /* je 0x9e8a56 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e8a4eu); f_009e894f(c); /* call 0x9e894f */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009e8a56; /* jne 0x9e8a56 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->eax))); /* or edi, eax */
L_009e8a56:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee5c8u))); /* mov eax, dword ptr [0x1000e5c8] */
    { uint32_t v_ = R32((uint32_t)(c->eax + c->esi * 4)); PUSH32(c, v_); } /* push dword ptr [eax + esi*4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e8a64u); f_009e7947(c); /* call 0x9e7947 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e8a66:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x9ef5e0u))); /* cmp esi, dword ptr [0x1000f5e0] */
    if ((c->sf != c->of)) goto L_009e89fb; /* jl 0x9e89fb */
L_009e8a6f:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x009e8a76u); f_009e444a(c); /* call 0x9e444a */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x14u)), (uint32_t)0x1u); /* cmp dword ptr [esp + 0x14], 1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (c->zf) goto L_009e8a82; /* je 0x9e8a82 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
L_009e8a82:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e8a86(CPU *c) { /* PTR_009e8a86 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x009e8a8du); f_009e3205(c); /* call 0x9e3205 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_009e8a8f(CPU *c) { /* FUN_10008a8f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9ea708u; PUSH32(c, v_); } /* push 0x1000a708 */
    { uint32_t v_ = 0x9e5a08u; PUSH32(c, v_); } /* push 0x10005a08 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0x9ee248u)), c->edi); /* cmp dword ptr [0x1000e248], edi */
    if (!c->zf) goto L_009e8b05; /* jne 0x9e8b05 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x9ea700u; PUSH32(c, v_); } /* push 0x1000a700 */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8ad7u); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8ae3; /* je 0x9e8ae3 */
    W32((uint32_t)(0x9ee248u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000e248], ebx */
    goto L_009e8b05; /* jmp 0x9e8b05 */
L_009e8ae3:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x9ea6fcu; PUSH32(c, v_); } /* push 0x1000a6fc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9ea0d8u)); PUSH32(c, 0x009e8af3u); call_indirect(c, t_); } /* call dword ptr [0x1000a0d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    W32((uint32_t)(0x9ee248u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x1000e248], 2 */
L_009e8b05:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->edi); /* cmp dword ptr [ebp + 0x14], edi */
    if ((c->zf || c->sf != c->of)) goto L_009e8b1a; /* jle 0x9e8b1a */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x009e8b15u); f_009e8cb3(c); /* call 0x9e8cb3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_009e8b1a:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee248u))); /* mov eax, dword ptr [0x1000e248] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_009e8b41; /* jne 0x9e8b41 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0d8u)); PUSH32(c, 0x009e8b3cu); call_indirect(c, t_); } /* call dword ptr [0x1000a0d8] */
    goto L_009e8c1f; /* jmp 0x9e8c1f */
L_009e8b41:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009e8c1d; /* jne 0x9e8c1d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), c->edi); /* cmp dword ptr [ebp + 0x20], edi */
    if (!c->zf) goto L_009e8b57; /* jne 0x9e8b57 */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee240u))); /* mov eax, dword ptr [0x1000e240] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
L_009e8b57:;
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
    { uint32_t t_ = R32((uint32_t)(0x9ea0d4u)); PUSH32(c, 0x009e8b74u); call_indirect(c, t_); } /* call dword ptr [0x1000a0d4] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x1c], ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea eax, [ebx + ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x009e8b91u); f_009e8430(c); /* call 0x9e8430 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_009e8bb2; /* jmp 0x9e8bb2 */
L_009e8bb2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0d4u)); PUSH32(c, 0x009e8bccu); call_indirect(c, t_); } /* call dword ptr [0x1000a0d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8be2u); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_009e8c31; /* je 0x9e8c31 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_009e8cac; /* je 0x9e8cac */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_009e8c1d; /* jg 0x9e8c1d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8c15u); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e8cac; /* jne 0x9e8cac */
L_009e8c1d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e8c1f:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e8c31:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x009e8c45u); f_009e8430(c); /* call 0x9e8430 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_009e8c65; /* jmp 0x9e8c65 */
L_009e8c65:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8c7du); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_009e8c8c; /* jne 0x9e8c8c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_009e8c92; /* jmp 0x9e8c92 */
L_009e8c8c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_009e8c92:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9ea07cu)); PUSH32(c, 0x009e8ca2u); call_indirect(c, t_); } /* call dword ptr [0x1000a07c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
L_009e8cac:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_009e8c1f; /* jmp 0x9e8c1f */
}

void f_009e8b9f(CPU *c) { /* PTR_009e8b9f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_009e8ba3(CPU *c) { /* PTR_009e8ba3 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ebx, dword ptr [ebp - 0x1c] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0d4u)); PUSH32(c, 0x009e8bccu); call_indirect(c, t_); } /* call dword ptr [0x1000a0d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8be2u); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_009e8c31; /* je 0x9e8c31 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_009e8cac; /* je 0x9e8cac */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_009e8c1d; /* jg 0x9e8c1d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8c15u); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e8cac; /* jne 0x9e8cac */
L_009e8c1d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e8c1f:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e8c31:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x009e8c45u); f_009e8430(c); /* call 0x9e8430 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_009e8c65; /* jmp 0x9e8c65 */
L_009e8c65:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8c7du); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_009e8c8c; /* jne 0x9e8c8c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_009e8c92; /* jmp 0x9e8c92 */
L_009e8c8c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_009e8c92:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9ea07cu)); PUSH32(c, 0x009e8ca2u); call_indirect(c, t_); } /* call dword ptr [0x1000a07c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_009e8c1d; /* je 0x9e8c1d */
L_009e8cac:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_009e8c1f; /* jmp 0x9e8c1f */
}

void f_009e8c1d(CPU *c) { /* PTR_009e8c1d */
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

void f_009e8c53(CPU *c) { /* PTR_009e8c53 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_009e8c57(CPU *c) { /* PTR_009e8c57 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) { f_009e8c1d(c); return; } /* je 0x9e8c1d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0dcu)); PUSH32(c, 0x009e8c7du); call_indirect(c, t_); } /* call dword ptr [0x1000a0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_009e8c1d(c); return; } /* je 0x9e8c1d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_009e8c8c; /* jne 0x9e8c8c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_009e8c92; /* jmp 0x9e8c92 */
L_009e8c8c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_009e8c92:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9ea07cu)); PUSH32(c, 0x009e8ca2u); call_indirect(c, t_); } /* call dword ptr [0x1000a07c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) { f_009e8c1d(c); return; } /* je 0x9e8c1d */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { jump_indirect(c, 0x009e8c1fu, 0x009e8caeu); return; } /* jmp 0x9e8c1f */
}

void f_009e8cb3(CPU *c) { /* FUN_10008cb3 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea ecx, [edx - 1] */
    if (c->zf) goto L_009e8cd0; /* je 0x9e8cd0 */
L_009e8cc3:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_009e8cd0; /* je 0x9e8cd0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_009e8cc3; /* jne 0x9e8cc3 */
L_009e8cd0:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_009e8cdb; /* jne 0x9e8cdb */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
L_009e8cdb:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esp += 4; return; /* ret  */
}

void f_009e8cde(CPU *c) { /* FUN_10008cde */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x9ea720u; PUSH32(c, v_); } /* push 0x1000a720 */
    { uint32_t v_ = 0x9e5a08u; PUSH32(c, v_); } /* push 0x10005a08 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee24cu))); /* mov eax, dword ptr [0x1000e24c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_009e8d4d; /* jne 0x9e8d4d */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x9ea700u; PUSH32(c, v_); } /* push 0x1000a700 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x9ea0e4u)); PUSH32(c, 0x009e8d23u); call_indirect(c, t_); } /* call dword ptr [0x1000a0e4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8d2b; /* je 0x9e8d2b */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_009e8d48; /* jmp 0x9e8d48 */
L_009e8d2b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x9ea6fcu; PUSH32(c, v_); } /* push 0x1000a6fc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x9ea0e0u)); PUSH32(c, 0x009e8d3du); call_indirect(c, t_); } /* call dword ptr [0x1000a0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8e13; /* je 0x9e8e13 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_009e8d48:;
    W32((uint32_t)(0x9ee24cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000e24c], eax */
L_009e8d4d:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_009e8d76; /* jne 0x9e8d76 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_009e8d5e; /* jne 0x9e8d5e */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee230u))); /* mov eax, dword ptr [0x1000e230] */
L_009e8d5e:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea0e0u)); PUSH32(c, 0x009e8d71u); call_indirect(c, t_); } /* call dword ptr [0x1000a0e0] */
    goto L_009e8e15; /* jmp 0x9e8e15 */
L_009e8d76:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009e8e13; /* jne 0x9e8e13 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->ebx); /* cmp dword ptr [ebp + 0x18], ebx */
    if (!c->zf) goto L_009e8d8c; /* jne 0x9e8d8c */
    c->eax = (uint32_t)(R32((uint32_t)(0x9ee240u))); /* mov eax, dword ptr [0x1000e240] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
L_009e8d8c:;
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
    { uint32_t t_ = R32((uint32_t)(0x9ea0d4u)); PUSH32(c, 0x009e8da9u); call_indirect(c, t_); } /* call dword ptr [0x1000a0d4] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_009e8e13; /* je 0x9e8e13 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax)); /* lea edi, [eax + eax] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x009e8dc2u); f_009e8430(c); /* call 0x9e8430 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(c->esp); /* mov esi, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e8dd2u); f_009e84f0(c); /* call 0x9e84f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_009e8de2; /* jmp 0x9e8de2 */
L_009e8de2:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_009e8e13; /* je 0x9e8e13 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0d4u)); PUSH32(c, 0x009e8dffu); call_indirect(c, t_); } /* call dword ptr [0x1000a0d4] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_009e8e13; /* je 0x9e8e13 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0e4u)); PUSH32(c, 0x009e8e11u); call_indirect(c, t_); } /* call dword ptr [0x1000a0e4] */
    goto L_009e8e15; /* jmp 0x9e8e15 */
L_009e8e13:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e8e15:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e8dd7(CPU *c) { /* PTR_009e8dd7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_009e8ddb(CPU *c) { /* PTR_009e8ddb */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_009e8e13; /* je 0x9e8e13 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0d4u)); PUSH32(c, 0x009e8dffu); call_indirect(c, t_); } /* call dword ptr [0x1000a0d4] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_009e8e13; /* je 0x9e8e13 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9ea0e4u)); PUSH32(c, 0x009e8e11u); call_indirect(c, t_); } /* call dword ptr [0x1000a0e4] */
    goto L_009e8e15; /* jmp 0x9e8e15 */
L_009e8e13:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e8e15:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e8e27(CPU *c) { /* FUN_10008e27 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x9ee230u)), c->ebx); /* cmp dword ptr [0x1000e230], ebx */
    if (!c->zf) goto L_009e8e45; /* jne 0x9e8e45 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_009e8e94; /* jl 0x9e8e94 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_009e8e94; /* jg 0x9e8e94 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009e8e45:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x9ee394u); /* mov esi, 0x1000e394 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x9ea0b8u)); PUSH32(c, 0x009e8e53u); call_indirect(c, t_); } /* call dword ptr [0x1000a0b8] */
    (void)sub32(c, R32((uint32_t)(0x9ee390u)), c->ebx); /* cmp dword ptr [0x1000e390], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0x9ea0b4u))); /* mov edi, dword ptr [0x1000a0b4] */
    if (c->zf) goto L_009e8e6f; /* je 0x9e8e6f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009e8e64u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e8e6bu); f_009e43e9(c); /* call 0x9e43e9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_009e8e6f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x009e8e78u); f_009e8e96(c); /* call 0x9e8e96 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_009e8e8b; /* je 0x9e8e8b */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e8e88u); f_009e444a(c); /* call 0x9e444a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e8e8e; /* jmp 0x9e8e8e */
L_009e8e8b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009e8e8eu); call_indirect(c, t_); } /* call edi */
L_009e8e8e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_009e8e94:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e8e96(CPU *c) { /* FUN_10008e96 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x9ee230u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000e230], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_009e8ec1; /* jne 0x9e8ec1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_009e8f5f; /* jl 0x9e8f5f */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_009e8f5f; /* jg 0x9e8f5f */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_009e8f5f; /* jmp 0x9e8f5f */
L_009e8ec1:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_009e8ef4; /* jge 0x9e8ef4 */
    (void)sub32(c, R32((uint32_t)(0x9edda4u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000dda4], 1 */
    if ((c->zf || c->sf != c->of)) goto L_009e8ee1; /* jle 0x9e8ee1 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e8eddu); f_009e8f62(c); /* call 0x9e8f62 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e8eec; /* jmp 0x9e8eec */
L_009e8ee1:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov eax, dword ptr [0x1000d818] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_009e8eec:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e8ef4; /* jne 0x9e8ef4 */
L_009e8ef0:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_009e8f5f; /* jmp 0x9e8f5f */
L_009e8ef4:;
    c->edx = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov edx, dword ptr [0x1000d818] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_009e8f17; /* je 0x9e8f17 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_009e8f20; /* jmp 0x9e8f20 */
L_009e8f17:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_009e8f20:;
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
    { uint32_t v_ = R32((uint32_t)(0x9ee230u)); PUSH32(c, v_); } /* push dword ptr [0x1000e230] */
    PUSH32(c, 0x009e8f40u); f_009e8a8f(c); /* call 0x9e8a8f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e8ef0; /* je 0x9e8ef0 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009e8f52; /* jne 0x9e8f52 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_009e8f5f; /* jmp 0x9e8f5f */
L_009e8f52:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_009e8f5f:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e8f62(CPU *c) { /* FUN_10008f62 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_009e8f80; /* ja 0x9e8f80 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov ecx, dword ptr [0x1000d818] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_009e8fd2; /* jmp 0x9e8fd2 */
L_009e8f80:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov esi, dword ptr [0x1000d818] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_009e8fa5; /* je 0x9e8fa5 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_009e8fae; /* jmp 0x9e8fae */
L_009e8fa5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_009e8fae:;
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
    PUSH32(c, 0x009e8fc5u); f_009e8cde(c); /* call 0x9e8cde */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e8fce; /* jne 0x9e8fce */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009e8fce:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_009e8fd2:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e8fd7(CPU *c) { /* FUN_10008fd7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xcu)) & (uint8_t)0x40u)); /* test byte ptr [esi + 0xc], 0x40 */
    if (c->zf) goto L_009e8fec; /* je 0x9e8fec */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0xc], 0 */
    goto L_009e9003; /* jmp 0x9e9003 */
L_009e8fec:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e8ff2u); f_009e78c6(c); /* call 0x9e78c6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e8ff8u); f_009e9008(c); /* call 0x9e9008 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x009e9000u); f_009e7918(c); /* call 0x9e7918 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_009e9003:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e9008(CPU *c) { /* __fclose_lk */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [esi + 0xc], 0x83 */
    if (c->zf) goto L_009e904b; /* je 0x9e904b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e901du); f_009e897d(c); /* call 0x9e897d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x009e9025u); f_009e924a(c); /* call 0x9e924a */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    PUSH32(c, 0x009e902du); f_009e916a(c); /* call 0x9e916a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_009e9039; /* jge 0x9e9039 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xffffffffu))); /* or edi, 0xffffffff */
    goto L_009e904b; /* jmp 0x9e904b */
L_009e9039:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e904b; /* je 0x9e904b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e9046u); f_009e445f(c); /* call 0x9e445f */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0x1c], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009e904b:;
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 0xc], 0 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e9054(CPU *c) { /* FUN_10009054 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x9ef720u))); /* cmp ebx, dword ptr [0x1000f720] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->cf) goto L_009e90d5; /* jae 0x9e90d5 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->edi = (uint32_t)((uint32_t)(c->eax * 4 + 0x9ef620u)); /* lea edi, [eax*4 + 0x1000f620] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea esi, [eax + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [eax + esi + 4], 1 */
    if (c->zf) goto L_009e90d5; /* je 0x9e90d5 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e9089u); f_009e884d(c); /* call 0x9e884d */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [eax + esi + 4], 1 */
    if (c->zf) goto L_009e90bc; /* je 0x9e90bc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e9099u); f_009e880b(c); /* call 0x9e880b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea0e8u)); PUSH32(c, 0x009e90a1u); call_indirect(c, t_); } /* call dword ptr [0x1000a0e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e90af; /* jne 0x9e90af */
    { uint32_t t_ = R32((uint32_t)(0x9ea02cu)); PUSH32(c, 0x009e90abu); call_indirect(c, t_); } /* call dword ptr [0x1000a02c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_009e90b1; /* jmp 0x9e90b1 */
L_009e90af:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_009e90b1:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_009e90ca; /* je 0x9e90ca */
    PUSH32(c, 0x009e90bau); f_009e8783(c); /* call 0x9e8783 */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_009e90bc:;
    PUSH32(c, 0x009e90c1u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_009e90ca:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e90d0u); f_009e88ac(c); /* call 0x9e88ac */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_009e90e3; /* jmp 0x9e90e3 */
L_009e90d5:;
    PUSH32(c, 0x009e90dau); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_009e90e3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009e90f0(CPU *c) { /* FUN_100090f0 */
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
L_009e9104:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e9111; /* je 0x9e9111 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_009e9104; /* jmp 0x9e9104 */
L_009e9111:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_009e9118:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e9126; /* je 0x9e9126 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_009e9118; /* jae 0x9e9118 */
L_009e9126:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e9130(CPU *c) { /* FUN_10009130 */
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
L_009e9144:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e9151; /* je 0x9e9151 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_009e9144; /* jmp 0x9e9144 */
L_009e9151:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_009e9154:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e9164; /* je 0x9e9164 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_009e9154; /* jae 0x9e9154 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_009e9164:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e916a(CPU *c) { /* FUN_1000916a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x9ef720u))); /* cmp esi, dword ptr [0x1000f720] */
    if (!c->cf) goto L_009e91af; /* jae 0x9e91af */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9ef620u))); /* mov ecx, dword ptr [ecx*4 + 0x1000f620] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 4 + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [ecx + eax*4 + 4], 1 */
    if (c->zf) goto L_009e91af; /* je 0x9e91af */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e9199u); f_009e884d(c); /* call 0x9e884d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e919fu); f_009e91c7(c); /* call 0x9e91c7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x009e91a7u); f_009e88ac(c); /* call 0x9e88ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009e91af:;
    PUSH32(c, 0x009e91b4u); f_009e877a(c); /* call 0x9e877a */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x009e91bfu); f_009e8783(c); /* call 0x9e8783 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e91c7(CPU *c) { /* FUN_100091c7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e91d3u); f_009e880b(c); /* call 0x9e880b */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e9215; /* je 0x9e9215 */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_009e91e3; /* je 0x9e91e3 */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_009e91f9; /* jne 0x9e91f9 */
L_009e91e3:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x009e91eau); f_009e880b(c); /* call 0x9e880b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x009e91f3u); f_009e880b(c); /* call 0x9e880b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009e9215; /* je 0x9e9215 */
L_009e91f9:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e91ffu); f_009e880b(c); /* call 0x9e880b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9ea0ecu)); PUSH32(c, 0x009e9207u); call_indirect(c, t_); } /* call dword ptr [0x1000a0ec] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e9215; /* jne 0x9e9215 */
    { uint32_t t_ = R32((uint32_t)(0x9ea02cu)); PUSH32(c, 0x009e9211u); call_indirect(c, t_); } /* call dword ptr [0x1000a02c] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    goto L_009e9217; /* jmp 0x9e9217 */
L_009e9215:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_009e9217:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x009e921du); f_009e878c(c); /* call 0x9e878c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x1fu))); /* and esi, 0x1f */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9ef620u))); /* mov eax, dword ptr [eax*4 + 0x1000f620] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 8)); /* lea ecx, [esi + esi*8] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ecx*4 + 4], 0 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_009e9245; /* je 0x9e9245 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x009e923fu); f_009e8707(c); /* call 0x9e8707 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_009e9247; /* jmp 0x9e9247 */
L_009e9245:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009e9247:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e924a(CPU *c) { /* __freebuf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x83u)); /* test al, 0x83 */
    if (c->zf) goto L_009e9273; /* je 0x9e9273 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_009e9273; /* je 0x9e9273 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esi + 8] */
    PUSH32(c, 0x009e9262u); f_009e445f(c); /* call 0x9e445f */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0xfbf7u)))); } /* and word ptr [esi + 0xc], 0xfbf7 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
L_009e9273:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_009e9280(CPU *c) { /* FUN_10009280 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0x9ee228u)); /* lea eax, [0x1000e228] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_009e92d3; /* jne 0x9e92d3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_009e929c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e92ce; /* je 0x9e92ce */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_009e929c; /* je 0x9e929c */
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
    if (c->zf) goto L_009e929c; /* je 0x9e929c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_009e92ce:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_009e934b; /* jmp 0x9e934b */
L_009e92d3:;
    { guest_lock(); guest_trap(c, 0x009e92d3u, "unsupported: lock inc dword ptr [0x1000e394]"); guest_unlock(); } /* lock inc dword ptr [0x1000e394] */
    (void)sub32(c, R32((uint32_t)(0x9ee390u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000e390], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_009e92e7; /* jg 0x9e92e7 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_009e92fc; /* jmp 0x9e92fc */
L_009e92e7:;
    { guest_lock(); guest_trap(c, 0x009e92e7u, "unsupported: lock dec dword ptr [0x1000e394]"); guest_unlock(); } /* lock dec dword ptr [0x1000e394] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e92f5u); f_009e43e9(c); /* call 0x9e43e9 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_009e92fc:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_009e9304:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e932f; /* je 0x9e932f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009e9304; /* je 0x9e9304 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e9319u); f_009e9451(c); /* call 0x9e9451 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x009e9323u); f_009e9451(c); /* call 0x9e9451 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_009e9304; /* je 0x9e9304 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_009e932f:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009e933f; /* jne 0x9e933f */
    { guest_lock(); guest_trap(c, 0x009e9336u, "unsupported: lock dec dword ptr [0x1000e394]"); guest_unlock(); } /* lock dec dword ptr [0x1000e394] */
    goto L_009e9349; /* jmp 0x9e9349 */
L_009e933f:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e9346u); f_009e444a(c); /* call 0x9e444a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009e9349:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_009e934b:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e9350(CPU *c) { /* FUN_10009350 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_009e944a; /* je 0x9e944a */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0x9ee228u)); /* lea eax, [0x1000e228] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_009e93c1; /* jne 0x9e93c1 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_009e937c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_009e93a5; /* je 0x9e93a5 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009e93a5; /* je 0x9e93a5 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_009e9394; /* jb 0x9e9394 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_009e9394; /* ja 0x9e9394 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_009e9394:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_009e939e; /* jb 0x9e939e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_009e939e; /* ja 0x9e939e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_009e939e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_009e93af; /* jne 0x9e93af */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_009e937c; /* jne 0x9e937c */
L_009e93a5:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_009e944a; /* je 0x9e944a */
L_009e93af:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_009e944a; /* jb 0x9e944a */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_009e944a; /* jmp 0x9e944a */
L_009e93c1:;
    { guest_lock(); guest_trap(c, 0x009e93c1u, "unsupported: lock inc dword ptr [0x1000e394]"); guest_unlock(); } /* lock inc dword ptr [0x1000e394] */
    (void)sub32(c, R32((uint32_t)(0x9ee390u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000e390], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_009e93d5; /* jg 0x9e93d5 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_009e93ee; /* jmp 0x9e93ee */
L_009e93d5:;
    { guest_lock(); guest_trap(c, 0x009e93d5u, "unsupported: lock dec dword ptr [0x1000e394]"); guest_unlock(); } /* lock dec dword ptr [0x1000e394] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e93e5u); f_009e43e9(c); /* call 0x9e43e9 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_009e93ee:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_009e93f4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_009e941f; /* je 0x9e941f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_009e941f; /* je 0x9e941f */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e940au); f_009e9451(c); /* call 0x9e9451 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x009e9414u); f_009e9451(c); /* call 0x9e9451 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_009e9425; /* jne 0x9e9425 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_009e93f4; /* jne 0x9e93f4 */
L_009e941f:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_009e942e; /* je 0x9e942e */
L_009e9425:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_009e942e; /* jb 0x9e942e */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_009e942e:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009e943c; /* jne 0x9e943c */
    { guest_lock(); guest_trap(c, 0x009e9433u, "unsupported: lock dec dword ptr [0x1000e394]"); guest_unlock(); } /* lock dec dword ptr [0x1000e394] */
    goto L_009e944a; /* jmp 0x9e944a */
L_009e943c:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009e9445u); f_009e444a(c); /* call 0x9e444a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_009e944a:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e9451(CPU *c) { /* FUN_10009451 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x9ee230u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000e230], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_009e947e; /* jne 0x9e947e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_009e9517; /* jl 0x9e9517 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_009e9517; /* jg 0x9e9517 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_009e9517; /* jmp 0x9e9517 */
L_009e947e:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_009e94b2; /* jge 0x9e94b2 */
    (void)sub32(c, R32((uint32_t)(0x9edda4u)), c->esi); /* cmp dword ptr [0x1000dda4], esi */
    if ((c->zf || c->sf != c->of)) goto L_009e94a0; /* jle 0x9e94a0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009e949cu); f_009e8f62(c); /* call 0x9e8f62 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009e94aa; /* jmp 0x9e94aa */
L_009e94a0:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov eax, dword ptr [0x1000d818] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_009e94aa:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009e94b2; /* jne 0x9e94b2 */
L_009e94ae:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_009e9517; /* jmp 0x9e9517 */
L_009e94b2:;
    c->edx = (uint32_t)(R32((uint32_t)(0x9ed818u))); /* mov edx, dword ptr [0x1000d818] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_009e94d6; /* je 0x9e94d6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009e94df; /* jmp 0x9e94df */
L_009e94d6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_009e94df:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x9ee230u)); PUSH32(c, v_); } /* push dword ptr [0x1000e230] */
    PUSH32(c, 0x009e94f9u); f_009e8a8f(c); /* call 0x9e8a8f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009e94ae; /* je 0x9e94ae */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_009e950a; /* jne 0x9e950a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_009e9517; /* jmp 0x9e9517 */
L_009e950a:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_009e9517:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009e9520(CPU *c) { /* PTR_009e9520 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_009e9539; /* jne 0x9e9539 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_009e9539:;
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

void f_009e9560(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x9ea004u)); switch (t_) {  default: jump_indirect(c, t_, 0x009e9560u); return; } } /* jmp dword ptr [0x1000a004] */
}

void f_009e9570(CPU *c) { /* Unwind@10009570 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = 0x9eb05cu; PUSH32(c, v_); } /* push 0x1000b05c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e9580u); f_009e1050(c); /* call 0x9e1050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009e9584(CPU *c) { /* PTR_009e9584 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea8dcu); /* mov eax, 0x1000a8dc */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}

void f_009e9590(CPU *c) { /* Unwind@10009590 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = 0x9eb05cu; PUSH32(c, v_); } /* push 0x1000b05c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e95a0u); f_009e1050(c); /* call 0x9e1050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009e95a4(CPU *c) { /* PTR_009e95a4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea900u); /* mov eax, 0x1000a900 */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}

void f_009e95b0(CPU *c) { /* Unwind@100095b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    { uint32_t v_ = 0x9eb05cu; PUSH32(c, v_); } /* push 0x1000b05c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e95c0u); f_009e1050(c); /* call 0x9e1050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009e95c4(CPU *c) { /* PTR_009e95c4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea924u); /* mov eax, 0x1000a924 */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}

void f_009e95d0(CPU *c) { /* Unwind@100095d0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_009e29e0(c); return; } /* jmp 0x9e29e0 */
}

void f_009e95d8(CPU *c) { /* PTR_009e95d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea948u); /* mov eax, 0x1000a948 */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}

void f_009e95f0(CPU *c) { /* Unwind@100095f0 */
    PREEMPT_POLL(c);
    goto L_009e95f0;
L_009e2960:;
    c->esp += 4; return; /* ret  */
L_009e95f0:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    goto L_009e2960; /* jmp 0x9e2960 */
}

void f_009e95fb(CPU *c) { /* PTR_009e95fb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea9a0u); /* mov eax, 0x1000a9a0 */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}

void f_009e9610(CPU *c) { /* Unwind@10009610 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_009e2960(c); return; } /* jmp 0x9e2960 */
}

void f_009e961b(CPU *c) { /* Unwind@1000961b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffda4u)); /* lea ecx, [ebp - 0x25c] */
    { f_009e2960(c); return; } /* jmp 0x9e2960 */
}

void f_009e9626(CPU *c) { /* PTR_009e9626 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea9ccu); /* mov eax, 0x1000a9cc */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}

void f_009e9630(CPU *c) { /* Unwind@10009630 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1d6u; PUSH32(c, v_); } /* push 0x1d6 */
    { uint32_t v_ = 0x9eb1ccu; PUSH32(c, v_); } /* push 0x1000b1cc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009e9643u); f_009e1050(c); /* call 0x9e1050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_009e9647(CPU *c) { /* PTR_009e9647 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9ea9f0u); /* mov eax, 0x1000a9f0 */
    { f_009e2ab1(c); return; } /* jmp 0x9e2ab1 */
}
