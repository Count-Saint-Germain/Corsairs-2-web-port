#include "recomp.h"

void f_00965c74(CPU *c) { /* PTR_00965c74 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965c7c(CPU *c) { /* PTR_00965c7c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965c84(CPU *c) { /* PTR_00965c84 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965c8c(CPU *c) { /* PTR_00965c8c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965c94(CPU *c) { /* PTR_00965c94 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965c9c(CPU *c) { /* PTR_00965c9c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965caf(CPU *c) { /* PTR_00965caf */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965cb8u)); switch (t_) { case 0x00965cc8u: goto L_00965cc8; case 0x00965cd0u: goto L_00965cd0; case 0x00965cdcu: goto L_00965cdc; case 0x00965cf0u: goto L_00965cf0; default: jump_indirect(c, t_, 0x00965cafu); return; } } /* jmp dword ptr [edx*4 + 0x10005cb8] */
L_00965cc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cd0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cdc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965cf0:;
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

void f_00965cc8(CPU *c) { /* PTR_00965cc8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00965cd0(CPU *c) { /* PTR_00965cd0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00965cdc(CPU *c) { /* PTR_00965cdc */
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

void f_00965cf0(CPU *c) { /* PTR_00965cf0 */
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

void f_00965d30(CPU *c) { /* PTR_00965d30 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x965e00u)); switch (t_) { case 0x00965e47u: goto L_00965e47; default: jump_indirect(c, t_, 0x00965d32u); return; } } /* jmp dword ptr [ecx*4 + 0x10005e00] */
L_00965e47:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965d68(CPU *c) { /* PTR_00965d68 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00965d30(c); return; } /* jb 0x965d30 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965d7eu); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965d88(CPU *c) { /* PTR_00965d88 */
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
    if (c->cf) { f_00965d30(c); return; } /* jb 0x965d30 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965da8u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965db0(CPU *c) { /* PTR_00965db0 */
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
    if (c->cf) { f_00965d30(c); return; } /* jb 0x965d30 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965ddau); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e04(CPU *c) { /* PTR_00965e04 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e0c(CPU *c) { /* PTR_00965e0c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e14(CPU *c) { /* PTR_00965e14 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e1c(CPU *c) { /* PTR_00965e1c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e24(CPU *c) { /* PTR_00965e24 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e2c(CPU *c) { /* PTR_00965e2c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e34(CPU *c) { /* PTR_00965e34 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e47(CPU *c) { /* PTR_00965e47 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x965e50u)); switch (t_) { case 0x00965e60u: goto L_00965e60; case 0x00965e68u: goto L_00965e68; case 0x00965e78u: goto L_00965e78; case 0x00965e8cu: goto L_00965e8c; default: jump_indirect(c, t_, 0x00965e47u); return; } } /* jmp dword ptr [edx*4 + 0x10005e50] */
L_00965e60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00965e8c:;
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

void f_00965e60(CPU *c) { /* PTR_00965e60 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00965e68(CPU *c) { /* PTR_00965e68 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00965e78(CPU *c) { /* PTR_00965e78 */
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

void f_00965e8c(CPU *c) { /* PTR_00965e8c */
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

void f_00965ea5(CPU *c) { /* FUN_10005ea5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffcu), c->fpu_cw); /* fnstcw word ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00965eb6u); f_00965ef0(c); /* call 0x965ef0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)~c->eax); /* not eax */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & c->eax))); /* and esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->eax))); /* or esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00965ecdu); f_00965f82(c); /* call 0x965f82 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00965eda(CPU *c) { /* FUN_10005eda */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfff7ffffu))); /* and eax, 0xfff7ffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00965eedu); f_00965ea5(c); /* call 0x965ea5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00965ef0(CPU *c) { /* FUN_10005ef0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00965f01; /* je 0x965f01 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00965f01:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00965f08; /* je 0x965f08 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00965f08:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00965f0f; /* je 0x965f0f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00965f0f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00965f16; /* je 0x965f16 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00965f16:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x20u)); /* test bl, 0x20 */
    if (c->zf) goto L_00965f1d; /* je 0x965f1d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1u))); /* or al, 1 */
L_00965f1d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00965f27; /* je 0x965f27 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x80000u))); /* or eax, 0x80000 */
L_00965f27:;
    c->ecx = (uint32_t)((uint32_t)((uint16_t)c->ebx)); /* movzx ecx, bx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)((uint32_t)0xc00u); /* mov esi, 0xc00 */
    c->edi = (uint32_t)((uint32_t)0x300u); /* mov edi, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->esi))); /* and edx, esi */
    c->ebp = (uint32_t)((uint32_t)0x200u); /* mov ebp, 0x200 */
    if (c->zf) goto L_00965f5f; /* je 0x965f5f */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (c->zf) goto L_00965f5c; /* je 0x965f5c */
    (void)sub32(c, c->edx, (uint32_t)0x800u); /* cmp edx, 0x800 */
    if (c->zf) goto L_00965f58; /* je 0x965f58 */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if (!c->zf) goto L_00965f5f; /* jne 0x965f5f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    goto L_00965f5f; /* jmp 0x965f5f */
L_00965f58:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ebp))); /* or eax, ebp */
    goto L_00965f5f; /* jmp 0x965f5f */
L_00965f5c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x1u))) << 8); /* or ah, 1 */
L_00965f5f:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00965f6f; /* je 0x965f6f */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (!c->zf) goto L_00965f74; /* jne 0x965f74 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x10000u))); /* or eax, 0x10000 */
    goto L_00965f74; /* jmp 0x965f74 */
L_00965f6f:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x20000u))); /* or eax, 0x20000 */
L_00965f74:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x10u)); /* test bh, 0x10 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00965f81; /* je 0x965f81 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x40000u))); /* or eax, 0x40000 */
L_00965f81:;
    c->esp += 4; return; /* ret  */
}

void f_00965f82(CPU *c) { /* FUN_10005f82 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00965f92; /* je 0x965f92 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00965f92:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00965f99; /* je 0x965f99 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00965f99:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00965fa0; /* je 0x965fa0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00965fa0:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00965fa7; /* je 0x965fa7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
L_00965fa7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00965fae; /* je 0x965fae */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
L_00965fae:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000u)); /* test ebx, 0x80000 */
    if (c->zf) goto L_00965fb8; /* je 0x965fb8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00965fb8:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)((uint32_t)0x300u); /* mov edx, 0x300 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->esi = (uint32_t)((uint32_t)0x200u); /* mov esi, 0x200 */
    if (c->zf) goto L_00965fe5; /* je 0x965fe5 */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (c->zf) goto L_00965fe2; /* je 0x965fe2 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (c->zf) goto L_00965fdd; /* je 0x965fdd */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00965fe5; /* jne 0x965fe5 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0xcu))) << 8); /* or ah, 0xc */
    goto L_00965fe5; /* jmp 0x965fe5 */
L_00965fdd:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x8u))) << 8); /* or ah, 8 */
    goto L_00965fe5; /* jmp 0x965fe5 */
L_00965fe2:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x4u))) << 8); /* or ah, 4 */
L_00965fe5:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x30000u))); /* and ecx, 0x30000 */
    if (c->zf) goto L_00965ffb; /* je 0x965ffb */
    (void)sub32(c, c->ecx, (uint32_t)0x10000u); /* cmp ecx, 0x10000 */
    if (!c->zf) goto L_00965ffd; /* jne 0x965ffd */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    goto L_00965ffd; /* jmp 0x965ffd */
L_00965ffb:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
L_00965ffd:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x40000u)); /* test ebx, 0x40000 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_0096600a; /* je 0x96600a */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x10u))) << 8); /* or ah, 0x10 */
L_0096600a:;
    c->esp += 4; return; /* ret  */
}

void f_0096600b(CPU *c) { /* FUN_1000600b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_00966029; /* ja 0x966029 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_0096607b; /* jmp 0x96607b */
L_00966029:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov esi, dword ptr [0x1000c34c] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_0096604e; /* je 0x96604e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00966057; /* jmp 0x966057 */
L_0096604e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00966057:;
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
    PUSH32(c, 0x0096606eu); f_0096742d(c); /* call 0x96742d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00966077; /* jne 0x966077 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00966077:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_0096607b:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966080(CPU *c) { /* FUN_10006080 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x96d028u)), c->ebx); /* cmp dword ptr [0x1000d028], ebx */
    if (!c->zf) goto L_0096609e; /* jne 0x96609e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_009660ed; /* jl 0x9660ed */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_009660ed; /* jg 0x9660ed */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_0096609e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x96d184u); /* mov esi, 0x1000d184 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x9690b4u)); PUSH32(c, 0x009660acu); call_indirect(c, t_); } /* call dword ptr [0x100090b4] */
    (void)sub32(c, R32((uint32_t)(0x96d180u)), c->ebx); /* cmp dword ptr [0x1000d180], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0x9690b0u))); /* mov edi, dword ptr [0x100090b0] */
    if (c->zf) goto L_009660c8; /* je 0x9660c8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009660bdu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009660c4u); f_009647c7(c); /* call 0x9647c7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_009660c8:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x009660d1u); f_009660ef(c); /* call 0x9660ef */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_009660e4; /* je 0x9660e4 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009660e1u); f_00964828(c); /* call 0x964828 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009660e7; /* jmp 0x9660e7 */
L_009660e4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x009660e7u); call_indirect(c, t_); } /* call edi */
L_009660e7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_009660ed:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_009660ef(CPU *c) { /* FUN_100060ef */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x96d028u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d028], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_0096611c; /* jne 0x96611c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_009661b5; /* jl 0x9661b5 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_009661b5; /* jg 0x9661b5 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_009661b5; /* jmp 0x9661b5 */
L_0096611c:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_00966150; /* jge 0x966150 */
    (void)sub32(c, R32((uint32_t)(0x96c340u)), c->esi); /* cmp dword ptr [0x1000c340], esi */
    if ((c->zf || c->sf != c->of)) goto L_0096613e; /* jle 0x96613e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0096613au); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00966148; /* jmp 0x966148 */
L_0096613e:;
    c->eax = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov eax, dword ptr [0x1000c34c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00966148:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00966150; /* jne 0x966150 */
L_0096614c:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_009661b5; /* jmp 0x9661b5 */
L_00966150:;
    c->edx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov edx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00966174; /* je 0x966174 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_0096617d; /* jmp 0x96617d */
L_00966174:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_0096617d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x96d028u)); PUSH32(c, v_); } /* push dword ptr [0x1000d028] */
    PUSH32(c, 0x00966197u); f_00967576(c); /* call 0x967576 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0096614c; /* je 0x96614c */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_009661a8; /* jne 0x9661a8 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_009661b5; /* jmp 0x9661b5 */
L_009661a8:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_009661b5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009661ba(CPU *c) { /* FUN_100061ba */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x009661c3u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x009661ceu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4)) & c->edx)); /* test dword ptr [eax + esi*4], edx */
    if (!c->zf) goto L_009661ff; /* jne 0x9661ff */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf == c->of)) goto L_009661fa; /* jge 0x9661fa */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi * 4)); /* lea eax, [eax + esi*4] */
L_009661ec:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_009661ff; /* jne 0x9661ff */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf != c->of)) goto L_009661ec; /* jl 0x9661ec */
L_009661fa:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_009661ff:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00966203(CPU *c) { /* FUN_10006203 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00966212u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0096621bu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
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
    PUSH32(c, 0x00966233u); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00966255; /* js 0x966255 */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->esi * 4)); /* lea edi, [ebx + esi*4] */
L_0096623c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00966255; /* je 0x966255 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    PUSH32(c, 0x0096624au); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x4u)); /* sub edi, 4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_0096623c; /* jge 0x96623c */
L_00966255:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00966259(CPU *c) { /* FUN_10006259 */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00966277u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00966280u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
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
    if (c->zf) goto L_009662bd; /* je 0x9662bd */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009662a6u); f_009661ba(c); /* call 0x9661ba */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009662ba; /* jne 0x9662ba */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009662b5u); f_00966203(c); /* call 0x966203 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009662ba:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_009662bd:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_009662dd; /* jge 0x9662dd */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 4)); /* lea edi, [edx + eax*4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_009662dd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009662e5(CPU *c) { /* FUN_100062e5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_009662f3:;
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)(c->esi)); /* mov dword ptr [ecx + eax], esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_009662f3; /* jne 0x9662f3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00966300(CPU *c) { /* FUN_10006300 */
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

void f_0096630c(CPU *c) { /* FUN_1000630c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00966312:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00966324; /* jne 0x966324 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    if ((c->sf != c->of)) goto L_00966312; /* jl 0x966312 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00966324:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00966327(CPU *c) { /* FUN_10006327 */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00966346u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0096634fu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, (c->ecx & 0xff))); /* shl esi, cl */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edx)); /* sub ebx, edx */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
L_0096635d:;
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
    if (!c->zf) goto L_0096635d; /* jne 0x96635d */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edi, dword ptr [ebp - 0xc] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
L_0096638f:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->sf != c->of)) goto L_009663a2; /* jl 0x9663a2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov eax, dword ptr [eax + edx] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    goto L_009663a9; /* jmp 0x9663a9 */
L_009663a2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + eax], 0 */
L_009663a9:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (!c->sf) goto L_0096638f; /* jns 0x96638f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009663b4(CPU *c) { /* FUN_100063b4 */
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
    if (!c->zf) goto L_00966421; /* jne 0x966421 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966406u); f_0096630c(c); /* call 0x96630c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009664e0; /* jne 0x9664e0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966418u); f_00966300(c); /* call 0x966300 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00966419:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
L_0096641b:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009664e2; /* jmp 0x9664e2 */
L_00966421:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0096642eu); f_009662e5(c); /* call 0x9662e5 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0096643au); f_00966259(c); /* call 0x966259 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00966442; /* je 0x966442 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00966442:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u)))); /* sub ecx, dword ptr [edi + 8] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf == c->of)) goto L_0096645a; /* jge 0x96645a */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966457u); f_00966300(c); /* call 0x966300 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00966496; /* jmp 0x966496 */
L_0096645a:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_0096649d; /* jg 0x96649d */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0096646fu); f_009662e5(c); /* call 0x9662e5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966479u); f_00966327(c); /* call 0x966327 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966485u); f_00966259(c); /* call 0x966259 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966493u); f_00966327(c); /* call 0x966327 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00966496:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00966419; /* jmp 0x966419 */
L_0096649d:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi))); /* cmp ebx, dword ptr [edi] */
    if ((c->sf != c->of)) goto L_009664c9; /* jl 0x9664c9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009664aau); f_00966300(c); /* call 0x966300 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009664bau); f_00966327(c); /* call 0x966327 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->edi)))); /* add esi, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_0096641b; /* jmp 0x96641b */
L_009664c9:;
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x7fu)))); } /* and byte ptr [ebp - 9], 0x7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebx)); /* add esi, ebx */
    PUSH32(c, 0x009664deu); f_00966327(c); /* call 0x966327 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009664e0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009664e2:;
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
    if (!c->zf) goto L_00966511; /* jne 0x966511 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    goto L_0096651b; /* jmp 0x96651b */
L_00966511:;
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if (!c->zf) goto L_0096651b; /* jne 0x96651b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_0096651b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966520(CPU *c) { /* FUN_10006520 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x96c558u; PUSH32(c, v_); } /* push 0x1000c558 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00966532u); f_009663b4(c); /* call 0x9663b4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00966536(CPU *c) { /* FUN_10006536 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x96c570u; PUSH32(c, v_); } /* push 0x1000c570 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00966548u); f_009663b4(c); /* call 0x9663b4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0096654c(CPU *c) { /* FUN_1000654c */
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
    PUSH32(c, 0x00966568u); f_00967966(c); /* call 0x967966 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966574u); f_00966520(c); /* call 0x966520 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966579(CPU *c) { /* FUN_10006579 */
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
    PUSH32(c, 0x00966595u); f_00967966(c); /* call 0x967966 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009665a1u); f_00966536(c); /* call 0x966536 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009665a6(CPU *c) { /* FUN_100065a6 */
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
    if ((c->zf || c->sf != c->of)) goto L_009665e3; /* jle 0x9665e3 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_009665c9:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_009665d5; /* je 0x9665d5 */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->edx)); /* movsx edx, dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_009665d8; /* jmp 0x9665d8 */
L_009665d5:;
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_009665d8:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (!c->zf) goto L_009665c9; /* jne 0x9665c9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_009665e3:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_009665fc; /* jl 0x9665fc */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x35u); /* cmp byte ptr [ecx], 0x35 */
    if ((c->sf != c->of)) goto L_009665fc; /* jl 0x9665fc */
L_009665ef:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_009665fa; /* jne 0x9665fa */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    goto L_009665ef; /* jmp 0x9665ef */
L_009665fa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_009665fc:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x31u); /* cmp byte ptr [esi], 0x31 */
    if (!c->zf) goto L_00966606; /* jne 0x966606 */
    { uint32_t a_ = (uint32_t)(c->edx + 0x4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx + 4] */
    goto L_00966618; /* jmp 0x966618 */
L_00966606:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0096660cu); f_00966880(c); /* call 0x966880 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00966615u); f_009642c0(c); /* call 0x9642c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00966618:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0096661d(CPU *c) { /* FUN_1000661d */
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
    PUSH32(c, 0x00966632u); f_00966679(c); /* call 0x966679 */
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
    PUSH32(c, 0x0096664du); f_00967e37(c); /* call 0x967e37 */
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
    PUSH32(c, 0x0096666du); f_00966730(c); /* call 0x966730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966679(CPU *c) { /* FUN_10006679 */
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
    if (c->zf) goto L_009666c7; /* je 0x9666c7 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_009666c0; /* je 0x9666c0 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c00u)); /* lea edi, [ecx + 0x3c00] */
    goto L_009666e8; /* jmp 0x9666e8 */
L_009666c0:;
    c->edi = (uint32_t)((uint32_t)0x7fffu); /* mov edi, 0x7fff */
    goto L_009666e8; /* jmp 0x9666e8 */
L_009666c7:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_009666df; /* jne 0x9666df */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (!c->zf) goto L_009666df; /* jne 0x9666df */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [eax + 8], bx */
    goto L_0096672a; /* jmp 0x96672a */
L_009666df:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c01u)); /* lea edi, [ecx + 0x3c01] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
L_009666e8:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 21)); /* shr ecx, 0x15 */
    c->eax = (uint32_t)(shl32(c, c->eax, 11)); /* shl eax, 0xb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* or ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(shl32(c, c->edx, 11)); /* shl edx, 0xb */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_00966700:;
    (void)logic32(c, (uint32_t)(c->esi & c->ecx)); /* test esi, ecx */
    if (!c->zf) goto L_00966721; /* jne 0x966721 */
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
    goto L_00966700; /* jmp 0x966700 */
L_00966721:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax + 8], cx */
L_0096672a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966730(CPU *c) { /* FUN_10006730 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    { f_009667a1(c); return; } /* jmp 0x9667a1 */
}

void f_00966740(CPU *c) { /* FUN_10006740 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_0096675c; /* je 0x96675c */
L_0096674d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0096678f; /* je 0x96678f */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_0096674d; /* jne 0x96674d */
L_0096675c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_0096675c; /* je 0x96675c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0096679e; /* je 0x96679e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00966799; /* je 0x966799 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_00966794; /* je 0x966794 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_0096678f; /* je 0x96678f */
    goto L_0096675c; /* jmp 0x96675c */
L_0096678f:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea edi, [ecx - 1] */
    goto L_009667a1; /* jmp 0x9667a1 */
L_00966794:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea edi, [ecx - 2] */
    goto L_009667a1; /* jmp 0x9667a1 */
L_00966799:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea edi, [ecx - 3] */
    goto L_009667a1; /* jmp 0x9667a1 */
L_0096679e:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea edi, [ecx - 4] */
L_009667a1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009667c6; /* je 0x9667c6 */
L_009667ad:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00966818; /* je 0x966818 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_009667ad; /* jne 0x9667ad */
    goto L_009667c6; /* jmp 0x9667c6 */
L_009667c1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_009667c6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009667c1; /* je 0x9667c1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00966818; /* je 0x966818 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_0096680f; /* je 0x96680f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00966802; /* je 0x966802 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_009667fa; /* je 0x9667fa */
    goto L_009667c1; /* jmp 0x9667c1 */
L_009667fa:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00966802:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0096680f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00966818:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_009667a1(CPU *c) { /* PTR_009667a1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009667c6; /* je 0x9667c6 */
L_009667ad:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00966818; /* je 0x966818 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_009667ad; /* jne 0x9667ad */
    goto L_009667c6; /* jmp 0x9667c6 */
L_009667c1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_009667c6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009667c1; /* je 0x9667c1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00966818; /* je 0x966818 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_0096680f; /* je 0x96680f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00966802; /* je 0x966802 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_009667fa; /* je 0x9667fa */
    goto L_009667c1; /* jmp 0x9667c1 */
L_009667fa:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00966802:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0096680f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00966818:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00966820(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00966873; /* je 0x966873 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_00966867; /* jb 0x966867 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_00966849; /* je 0x966849 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_00966843:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00966843; /* jne 0x966843 */
L_00966849:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_00966867; /* je 0x966867 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0096686d; /* je 0x96686d */
L_00966867:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00966867; /* jne 0x966867 */
L_0096686d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00966873:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00966880(CPU *c) { /* _strlen */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_009668a0; /* je 0x9668a0 */
L_0096688c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009668d3; /* je 0x9668d3 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_0096688c; /* jne 0x96688c */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x0u)); /* add eax, 0 */
L_009668a0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009668a0; /* je 0x9668a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009668f1; /* je 0x9668f1 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_009668e7; /* je 0x9668e7 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_009668dd; /* je 0x9668dd */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_009668d3; /* je 0x9668d3 */
    goto L_009668a0; /* jmp 0x9668a0 */
L_009668d3:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea eax, [ecx - 1] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_009668dd:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea eax, [ecx - 2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_009668e7:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea eax, [ecx - 3] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
L_009668f1:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea eax, [ecx - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_009668fb(CPU *c) { /* PTR_009668fb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x00966902u); f_00962055(c); /* call 0x962055 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00966904(CPU *c) { /* FUN_10006904 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00966914u); f_009647c7(c); /* call 0x9647c7 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0096691cu); f_00966ab1(c); /* call 0x966ab1 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x96d188u))); /* cmp ebx, dword ptr [0x1000d188] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->zf) goto L_00966932; /* jne 0x966932 */
L_0096692b:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00966aa2; /* jmp 0x966aa2 */
L_00966932:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00966a90; /* je 0x966a90 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0x96c598u); /* mov eax, 0x1000c598 */
L_00966941:;
    (void)sub32(c, R32((uint32_t)(c->eax)), c->ebx); /* cmp dword ptr [eax], ebx */
    if (c->zf) goto L_009669b9; /* je 0x9669b9 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x30u)); /* add eax, 0x30 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0x96c688u); /* cmp eax, 0x1000c688 */
    if ((c->sf != c->of)) goto L_00966941; /* jl 0x966941 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x9690b8u)); PUSH32(c, 0x0096695bu); call_indirect(c, t_); } /* call dword ptr [0x100090b8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00966a87; /* jne 0x966a87 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t a_ = (uint32_t)(0x96d3a4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d3a4], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x96d2a0u); /* mov edi, 0x1000d2a0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->esi); /* cmp dword ptr [ebp - 0x18], esi */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    W32((uint32_t)(0x96d188u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000d188], ebx */
    if ((c->cf || c->zf)) goto L_00966a74; /* jbe 0x966a74 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffeeu)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x12], 0 */
    if (c->zf) goto L_00966a4f; /* je 0x966a4f */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffefu)); /* lea ecx, [ebp - 0x11] */
L_00966996:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00966a4f; /* je 0x966a4f */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + 0xffffffffu))); /* movzx eax, byte ptr [ecx - 1] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
L_009669a7:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((!c->cf && !c->zf)) goto L_00966a43; /* ja 0x966a43 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x4u)))); } /* or byte ptr [eax + 0x1000d2a1], 4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_009669a7; /* jmp 0x9669a7 */
L_009669b9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x96d2a0u); /* mov edi, 0x1000d2a0 */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea esi, [edx + edx*2] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x96c5a8u)); /* lea ebx, [esi + 0x1000c5a8] */
L_009669d6:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if (c->zf) goto L_00966a09; /* je 0x966a09 */
L_009669dd:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00966a09; /* je 0x966a09 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx eax, byte ptr [ecx] */
    c->edi = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edi, dl */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((!c->cf && !c->zf)) goto L_00966a02; /* ja 0x966a02 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x96c590u))); /* mov dl, byte ptr [edx + 0x1000c590] */
L_009669f7:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->edx))))); } /* or byte ptr [eax + 0x1000d2a1], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_009669f7; /* jbe 0x9669f7 */
L_00966a02:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (!c->zf) goto L_009669dd; /* jne 0x9669dd */
L_00966a09:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x4u); /* cmp dword ptr [ebp - 4], 4 */
    if (c->cf) goto L_009669d6; /* jb 0x9669d6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0x96d19cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d19c], 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x96d188u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d188], eax */
    PUSH32(c, 0x00966a2du); f_00966afb(c); /* call 0x966afb */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x96c59cu)); /* lea esi, [esi + 0x1000c59c] */
    c->edi = (uint32_t)((uint32_t)0x96d190u); /* mov edi, 0x1000d190 */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x96d3a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d3a4], eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_00966a95; /* jmp 0x966a95 */
L_00966a43:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0xffffffffu)), (uint8_t)0x0u); /* cmp byte ptr [ecx - 1], 0 */
    if (!c->zf) goto L_00966996; /* jne 0x966996 */
L_00966a4f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00966a51:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [eax + 0x1000d2a1], 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xffu); /* cmp eax, 0xff */
    if (c->cf) goto L_00966a51; /* jb 0x966a51 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00966a66u); f_00966afb(c); /* call 0x966afb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x96d3a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d3a4], eax */
    W32((uint32_t)(0x96d19cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000d19c], esi */
    goto L_00966a7b; /* jmp 0x966a7b */
L_00966a74:;
    { uint32_t a_ = (uint32_t)(0x96d19cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000d19c], 0 */
L_00966a7b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x96d190u); /* mov edi, 0x1000d190 */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    goto L_00966a95; /* jmp 0x966a95 */
L_00966a87:;
    (void)sub32(c, R32((uint32_t)(0x96cfecu)), (uint32_t)0x0u); /* cmp dword ptr [0x1000cfec], 0 */
    if (c->zf) goto L_00966a9f; /* je 0x966a9f */
L_00966a90:;
    PUSH32(c, 0x00966a95u); f_00966b2e(c); /* call 0x966b2e */
L_00966a95:;
    PUSH32(c, 0x00966a9au); f_00966b57(c); /* call 0x966b57 */
    goto L_0096692b; /* jmp 0x96692b */
L_00966a9f:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_00966aa2:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00966aa9u); f_00964828(c); /* call 0x964828 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966ab1(CPU *c) { /* FUN_10006ab1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0x96cfecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000cfec], 0 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (!c->zf) goto L_00966ad1; /* jne 0x966ad1 */
    W32((uint32_t)(0x96cfecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000cfec], 1 */
    { uint32_t t_ = R32((uint32_t)(0x9690c0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00966acbu); return; } } /* jmp dword ptr [0x100090c0] */
L_00966ad1:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_00966ae6; /* jne 0x966ae6 */
    W32((uint32_t)(0x96cfecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000cfec], 1 */
    { uint32_t t_ = R32((uint32_t)(0x9690bcu)); switch (t_) {  default: jump_indirect(c, t_, 0x00966ae0u); return; } } /* jmp dword ptr [0x100090bc] */
L_00966ae6:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if (!c->zf) goto L_00966afa; /* jne 0x966afa */
    c->eax = (uint32_t)(R32((uint32_t)(0x96d038u))); /* mov eax, dword ptr [0x1000d038] */
    W32((uint32_t)(0x96cfecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000cfec], 1 */
L_00966afa:;
    c->esp += 4; return; /* ret  */
}

void f_00966afb(CPU *c) { /* FUN_10006afb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3a4u)); /* sub eax, 0x3a4 */
    if (c->zf) goto L_00966b28; /* je 0x966b28 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00966b22; /* je 0x966b22 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xdu)); /* sub eax, 0xd */
    if (c->zf) goto L_00966b1c; /* je 0x966b1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00966b16; /* je 0x966b16 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00966b16:;
    c->eax = (uint32_t)((uint32_t)0x404u); /* mov eax, 0x404 */
    c->esp += 4; return; /* ret  */
L_00966b1c:;
    c->eax = (uint32_t)((uint32_t)0x412u); /* mov eax, 0x412 */
    c->esp += 4; return; /* ret  */
L_00966b22:;
    c->eax = (uint32_t)((uint32_t)0x804u); /* mov eax, 0x804 */
    c->esp += 4; return; /* ret  */
L_00966b28:;
    c->eax = (uint32_t)((uint32_t)0x411u); /* mov eax, 0x411 */
    c->esp += 4; return; /* ret  */
}

void f_00966b2e(CPU *c) { /* FUN_10006b2e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x96d2a0u); /* mov edi, 0x1000d2a0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x96d190u); /* mov edi, 0x1000d190 */
    W32((uint32_t)(0x96d188u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d188], eax */
    W32((uint32_t)(0x96d19cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d19c], eax */
    W32((uint32_t)(0x96d3a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d3a4], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00966b57(CPU *c) { /* FUN_10006b57 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x514u)); /* sub esp, 0x514 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x96d188u)); PUSH32(c, v_); } /* push dword ptr [0x1000d188] */
    { uint32_t t_ = R32((uint32_t)(0x9690b8u)); PUSH32(c, 0x00966b71u); call_indirect(c, t_); } /* call dword ptr [0x100090b8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00966c90; /* jne 0x966c90 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00966b81:;
    W8((uint32_t)(c->ebp + c->eax + 0xfffffeecu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + eax - 0x114], al */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00966b81; /* jb 0x966b81 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff2u))); /* mov al, byte ptr [ebp - 0xe] */
    W8((uint32_t)(c->ebp + 0xfffffeecu), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x114], 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00966bd2; /* je 0x966bd2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff3u)); /* lea edx, [ebp - 0xd] */
L_00966ba0:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((!c->cf && !c->zf)) goto L_00966bc7; /* ja 0x966bc7 */
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
L_00966bc7:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffffu))); /* mov al, byte ptr [edx - 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00966ba0; /* jne 0x966ba0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00966bd2:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea eax, [ebp - 0x514] */
    { uint32_t v_ = R32((uint32_t)(0x96d3a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d3a4] */
    { uint32_t v_ = R32((uint32_t)(0x96d188u)); PUSH32(c, v_); } /* push dword ptr [0x1000d188] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00966bf6u); f_0096742d(c); /* call 0x96742d */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdecu)); /* lea eax, [ebp - 0x214] */
    { uint32_t v_ = R32((uint32_t)(0x96d188u)); PUSH32(c, v_); } /* push dword ptr [0x1000d188] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x96d3a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d3a4] */
    PUSH32(c, 0x00966c1au); f_00967576(c); /* call 0x967576 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffcecu)); /* lea eax, [ebp - 0x314] */
    { uint32_t v_ = R32((uint32_t)(0x96d188u)); PUSH32(c, v_); } /* push dword ptr [0x1000d188] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0x96d3a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000d3a4] */
    PUSH32(c, 0x00966c42u); f_00967576(c); /* call 0x967576 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea ecx, [ebp - 0x514] */
L_00966c4d:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx))); /* mov dx, word ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    if (c->zf) goto L_00966c6b; /* je 0x966c6b */
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x1000d2a1], 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffdecu))); /* mov dl, byte ptr [ebp + eax - 0x214] */
L_00966c63:;
    W8((uint32_t)(c->eax + 0x96d1a0u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x1000d1a0], dl */
    goto L_00966c87; /* jmp 0x966c87 */
L_00966c6b:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x2u)); /* test dl, 2 */
    if (c->zf) goto L_00966c80; /* je 0x966c80 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x1000d2a1], 0x20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffcecu))); /* mov dl, byte ptr [ebp + eax - 0x314] */
    goto L_00966c63; /* jmp 0x966c63 */
L_00966c80:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d1a0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x1000d1a0], 0 */
L_00966c87:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00966c4d; /* jb 0x966c4d */
    goto L_00966cd9; /* jmp 0x966cd9 */
L_00966c90:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00966c97:;
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if (c->cf) goto L_00966cb5; /* jb 0x966cb5 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->cf && !c->zf)) goto L_00966cb5; /* ja 0x966cb5 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x1000d2a1], 0x10 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_00966cad:;
    W8((uint32_t)(c->eax + 0x96d1a0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x1000d1a0], cl */
    goto L_00966cd4; /* jmp 0x966cd4 */
L_00966cb5:;
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if (c->cf) goto L_00966ccd; /* jb 0x966ccd */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->cf && !c->zf)) goto L_00966ccd; /* ja 0x966ccd */
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d2a1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x1000d2a1], 0x20 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    goto L_00966cad; /* jmp 0x966cad */
L_00966ccd:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x96d1a0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x1000d1a0], 0 */
L_00966cd4:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00966c97; /* jb 0x966c97 */
L_00966cd9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966cdc(CPU *c) { /* FUN_10006cdc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x96d4e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d4e8], 0 */
    if (!c->zf) goto L_00966cf7; /* jne 0x966cf7 */
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    PUSH32(c, 0x00966cecu); f_00966904(c); /* call 0x966904 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x96d4e8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1000d4e8], 1 */
L_00966cf7:;
    c->esp += 4; return; /* ret  */
}

void f_00966cf8(CPU *c) { /* FUN_10006cf8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00966d0bu); f_00966d0f(c); /* call 0x966d0f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00966d0f(CPU *c) { /* FUN_10006d0f */
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
L_00966d27:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000c340], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00966d3f; /* jle 0x966d3f */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966d3bu); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00966d4e; /* jmp 0x966d4e */
L_00966d3f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00966d4e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00966d57; /* je 0x966d57 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00966d27; /* jmp 0x966d27 */
L_00966d57:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    if (!c->zf) goto L_00966d65; /* jne 0x966d65 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp + 0x14], 2 */
    goto L_00966d6a; /* jmp 0x966d6a */
L_00966d65:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (!c->zf) goto L_00966d70; /* jne 0x966d70 */
L_00966d6a:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00966d70:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00966f04; /* jl 0x966f04 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00966f04; /* je 0x966f04 */
    (void)sub32(c, c->eax, (uint32_t)0x24u); /* cmp eax, 0x24 */
    if ((!c->zf && c->sf == c->of)) goto L_00966f04; /* jg 0x966f04 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00966db8; /* jne 0x966db8 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00966da2; /* je 0x966da2 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp + 0x10], 0xa */
    goto L_00966dd4; /* jmp 0x966dd4 */
L_00966da2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00966db5; /* je 0x966db5 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (c->zf) goto L_00966db5; /* je 0x966db5 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x10], 8 */
    goto L_00966dd4; /* jmp 0x966dd4 */
L_00966db5:;
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
L_00966db8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00966dd4; /* jne 0x966dd4 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00966dd4; /* jne 0x966dd4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00966dcc; /* je 0x966dcc */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (!c->zf) goto L_00966dd4; /* jne 0x966dd4 */
L_00966dcc:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov bl, byte ptr [esi + 1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00966dd4:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00966dd9u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)0x103u); /* mov edi, 0x103 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00966de4:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000c340], 1 */
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    if ((c->zf || c->sf != c->of)) goto L_00966dfc; /* jle 0x966dfc */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00966df8u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00966e07; /* jmp 0x966e07 */
L_00966dfc:;
    c->eax = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov eax, dword ptr [0x1000c34c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00966e07:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00966e13; /* je 0x966e13 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x30u)); /* sub ecx, 0x30 */
    goto L_00966e45; /* jmp 0x966e45 */
L_00966e13:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000c340], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00966e27; /* jle 0x966e27 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00966e23u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00966e32; /* jmp 0x966e32 */
L_00966e27:;
    c->eax = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov eax, dword ptr [0x1000c34c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + c->esi * 2))); /* mov ax, word ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edi))); /* and eax, edi */
L_00966e32:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00966e80; /* je 0x966e80 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00966e3fu); f_009680d3(c); /* call 0x9680d3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x37u)); /* sub ecx, 0x37 */
L_00966e45:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_00966e80; /* jae 0x966e80 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp + 0x14], 8 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u))); /* cmp esi, dword ptr [ebp - 0xc] */
    if (c->cf) goto L_00966e6a; /* jb 0x966e6a */
    if (!c->zf) goto L_00966e64; /* jne 0x966e64 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00966e5du, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->cf || c->zf)) goto L_00966e6a; /* jbe 0x966e6a */
L_00966e64:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp + 0x14], 4 */
    goto L_00966e73; /* jmp 0x966e73 */
L_00966e6a:;
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
L_00966e73:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    goto L_00966de4; /* jmp 0x966de4 */
L_00966e80:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00966e9d; /* jne 0x966e9d */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00966e97; /* je 0x966e97 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00966e97:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    goto L_00966ee8; /* jmp 0x966ee8 */
L_00966e9d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
    if (!c->zf) goto L_00966ec1; /* jne 0x966ec1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (!c->zf) goto L_00966ee8; /* jne 0x966ee8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    if (c->zf) goto L_00966eb8; /* je 0x966eb8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x80000000u); /* cmp dword ptr [ebp - 8], 0x80000000 */
    if ((!c->cf && !c->zf)) goto L_00966ec1; /* ja 0x966ec1 */
L_00966eb8:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00966ee8; /* jne 0x966ee8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->esi); /* cmp dword ptr [ebp - 8], esi */
    if ((c->cf || c->zf)) goto L_00966ee8; /* jbe 0x966ee8 */
L_00966ec1:;
    PUSH32(c, 0x00966ec6u); f_009680ca(c); /* call 0x9680ca */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x14], 1 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    if (c->zf) goto L_00966ed8; /* je 0x966ed8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    goto L_00966ee8; /* jmp 0x966ee8 */
L_00966ed8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u))); /* and al, 2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(neg8(c, ((uint8_t)c->eax))); /* neg al */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00966ee8:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00966ef1; /* je 0x966ef1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00966ef1:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x2u)); /* test byte ptr [ebp + 0x14], 2 */
    if (c->zf) goto L_00966eff; /* je 0x966eff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00966eff:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    goto L_00966f0f; /* jmp 0x966f0f */
L_00966f04:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00966f0d; /* je 0x966f0d */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
L_00966f0d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00966f0f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00966f20(CPU *c) { /* PTR_00966f20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00966f30(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_00966f30;
L_00966f20:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966f30:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00966f5b; /* je 0x966f5b */
L_00966f48:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_00966f20; /* je 0x966f20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00966fa4; /* je 0x966fa4 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00966f48; /* jne 0x966f48 */
L_00966f5b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00966f66:;
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
    if (!c->zf) goto L_00966fa8; /* jne 0x966fa8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00966f66; /* je 0x966f66 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00966fa2; /* jne 0x966fa2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00966f66; /* jne 0x966f66 */
L_00966fa2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00966fa4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00966fa8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00966fe5; /* je 0x966fe5 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00966fde; /* je 0x966fde */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00966fd7; /* je 0x966fd7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00966fd0; /* je 0x966fd0 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    goto L_00966f66; /* jmp 0x966f66 */
L_00966fd0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966fd7:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966fde:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966fe5:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00966f36(CPU *c) { /* PTR_00966f36 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00966f5b; /* je 0x966f5b */
L_00966f48:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_00966f20(c); return; } /* je 0x966f20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00966fa4; /* je 0x966fa4 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00966f48; /* jne 0x966f48 */
L_00966f5b:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00966f66:;
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
    if (!c->zf) goto L_00966fa8; /* jne 0x966fa8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00966f66; /* je 0x966f66 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00966fa2; /* jne 0x966fa2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00966f66; /* jne 0x966f66 */
L_00966fa2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00966fa4:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00966fa8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00966fe5; /* je 0x966fe5 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00966fde; /* je 0x966fde */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00966fd7; /* je 0x966fd7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00966fd0; /* je 0x966fd0 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00966fa2; /* je 0x966fa2 */
    goto L_00966f66; /* jmp 0x966f66 */
L_00966fd0:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966fd7:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966fde:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00966fe5:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00966ff0(CPU *c) { /* _strstr */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0096706a; /* je 0x96706a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00967057; /* je 0x967057 */
L_00967008:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_0096702a; /* je 0x96702a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00967024; /* je 0x967024 */
L_00967019:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_0096701c:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_0096702a; /* je 0x96702a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00967019; /* jne 0x967019 */
L_00967024:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_0096702a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_0096701c; /* jne 0x96701c */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_00967034:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00967063; /* je 0x967063 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_00967008; /* jne 0x967008 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00967063; /* je 0x967063 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_00967034; /* je 0x967034 */
    goto L_00967008; /* jmp 0x967008 */
L_00967057:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_00966f36(c); return; } /* jmp 0x966f36 */
L_00967063:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0096706a:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00967070(CPU *c) { /* _strncmp */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    if (c->ecx == 0) goto L_009670a1; /* jecxz 0x9670a1 */
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
    if ((!c->cf && !c->zf)) goto L_0096709f; /* ja 0x96709f */
    if (c->zf) goto L_009670a1; /* je 0x9670a1 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_0096709f:;
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
L_009670a1:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009670b0(CPU *c) { /* FUN_100070b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_009670d0; /* jb 0x9670d0 */
L_009670bc:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_009670bc; /* jae 0x9670bc */
L_009670d0:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_009670df(CPU *c) { /* FUN_100070df */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x96cff0u)), c->ebx); /* cmp dword ptr [0x1000cff0], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_0096712e; /* jne 0x96712e */
    { uint32_t v_ = 0x969600u; PUSH32(c, v_); } /* push 0x10009600 */
    { uint32_t t_ = R32((uint32_t)(0x9690c4u)); PUSH32(c, 0x009670f7u); call_indirect(c, t_); } /* call dword ptr [0x100090c4] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00967164; /* je 0x967164 */
    c->esi = (uint32_t)(R32((uint32_t)(0x969040u))); /* mov esi, dword ptr [0x10009040] */
    { uint32_t v_ = 0x9695f4u; PUSH32(c, v_); } /* push 0x100095f4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x0096710bu); call_indirect(c, t_); } /* call esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x96cff0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000cff0], eax */
    if (c->zf) goto L_00967164; /* je 0x967164 */
    { uint32_t v_ = 0x9695e4u; PUSH32(c, v_); } /* push 0x100095e4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x0096711cu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = 0x9695d0u; PUSH32(c, v_); } /* push 0x100095d0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0x96cff4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000cff4], eax */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00967129u); call_indirect(c, t_); } /* call esi */
    W32((uint32_t)(0x96cff8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000cff8], eax */
L_0096712e:;
    c->eax = (uint32_t)(R32((uint32_t)(0x96cff4u))); /* mov eax, dword ptr [0x1000cff4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0096714d; /* je 0x96714d */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00967139u); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_0096714d; /* je 0x96714d */
    c->eax = (uint32_t)(R32((uint32_t)(0x96cff8u))); /* mov eax, dword ptr [0x1000cff8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0096714d; /* je 0x96714d */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x0096714bu); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_0096714d:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x96cff0u)); PUSH32(c, 0x00967160u); call_indirect(c, t_); } /* call dword ptr [0x1000cff0] */
L_00967160:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00967164:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00967160; /* jmp 0x967160 */
}

void f_00967170(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_009671f3; /* je 0x9671f3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00967194; /* jne 0x967194 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00967201; /* jne 0x967201 */
    goto L_009671b5; /* jmp 0x9671b5 */
L_00967194:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_009671c2; /* je 0x9671c2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009671ca; /* je 0x9671ca */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00967194; /* jne 0x967194 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00967201; /* jne 0x967201 */
L_009671b0:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_009671c2; /* je 0x9671c2 */
L_009671b5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_009671ee; /* je 0x9671ee */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_009671b5; /* jne 0x9671b5 */
L_009671c2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009671ca:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_009671e4; /* je 0x9671e4 */
L_009671d2:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00967266; /* je 0x967266 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_009671d2; /* jne 0x9671d2 */
L_009671e4:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00967257; /* jne 0x967257 */
L_009671eb:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_009671ee:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_009671eb; /* jne 0x9671eb */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_009671f3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_009671f9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_009671b0; /* je 0x9671b0 */
L_00967201:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_009671f9; /* je 0x9671f9 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0096724b; /* je 0x96724b */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00967241; /* je 0x967241 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00967237; /* je 0x967237 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_009671f9; /* jne 0x9671f9 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_0096724f; /* jmp 0x96724f */
L_00967237:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_0096724f; /* jmp 0x96724f */
L_00967241:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_0096724f; /* jmp 0x96724f */
L_0096724b:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_0096724f:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00967261; /* je 0x967261 */
L_00967257:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00967259:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00967259; /* jne 0x967259 */
L_00967261:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_009671eb; /* jne 0x9671eb */
L_00967266:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_0096726e(CPU *c) { /* FUN_1000726e */
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
    if (c->zf) goto L_009672e9; /* je 0x9672e9 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009672cc; /* je 0x9672cc */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_009672cc; /* je 0x9672cc */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_009672cc; /* je 0x9672cc */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_009672bf; /* je 0x9672bf */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_009672b2; /* je 0x9672b2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_009672a5; /* je 0x9672a5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_009673eb; /* jmp 0x9673eb */
L_009672a5:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x96d004u))); /* mov ebx, dword ptr [0x1000d004] */
    c->edi = (uint32_t)((uint32_t)0x96d004u); /* mov edi, 0x1000d004 */
    goto L_009672f4; /* jmp 0x9672f4 */
L_009672b2:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x96d000u))); /* mov ebx, dword ptr [0x1000d000] */
    c->edi = (uint32_t)((uint32_t)0x96d000u); /* mov edi, 0x1000d000 */
    goto L_009672f4; /* jmp 0x9672f4 */
L_009672bf:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x96d008u))); /* mov ebx, dword ptr [0x1000d008] */
    c->edi = (uint32_t)((uint32_t)0x96d008u); /* mov edi, 0x1000d008 */
    goto L_009672f4; /* jmp 0x9672f4 */
L_009672cc:;
    PUSH32(c, 0x009672d1u); f_00962971(c); /* call 0x962971 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x50u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x50] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x009672deu); f_009673f0(c); /* call 0x9673f0 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    goto L_00967306; /* jmp 0x967306 */
L_009672e9:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x96cffcu))); /* mov ebx, dword ptr [0x1000cffc] */
    c->edi = (uint32_t)((uint32_t)0x96cffcu); /* mov edi, 0x1000cffc */
L_009672f4:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00967302u); f_009647c7(c); /* call 0x9647c7 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00967306:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (!c->zf) goto L_00967321; /* jne 0x967321 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_009673e9; /* je 0x9673e9 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0096731bu); f_00964828(c); /* call 0x964828 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009673e9; /* jmp 0x9673e9 */
L_00967321:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (!c->zf) goto L_0096733b; /* jne 0x96733b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ecx); /* cmp dword ptr [ebp - 4], ecx */
    if (c->zf) goto L_00967334; /* je 0x967334 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00967333u); f_00964828(c); /* call 0x964828 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00967334:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x0096733bu); f_00962b5c(c); /* call 0x962b5c */
L_0096733b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (c->zf) goto L_0096734d; /* je 0x96734d */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if (c->zf) goto L_0096734d; /* je 0x96734d */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_00967368; /* jne 0x967368 */
L_0096734d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if (!c->zf) goto L_009673a4; /* jne 0x9673a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [esi + 0x58], 0x8c */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_00967368:;
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (!c->zf) goto L_009673a4; /* jne 0x9673a4 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x96a308u))); /* mov ecx, dword ptr [0x1000a308] */
    c->eax = (uint32_t)(R32((uint32_t)(0x96a30cu))); /* mov eax, dword ptr [0x1000a30c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_009673a6; /* jge 0x9673a6 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
L_00967384:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx + eax - 4], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0x96a308u))); /* mov edx, dword ptr [0x1000a308] */
    c->edi = (uint32_t)(R32((uint32_t)(0x96a30cu))); /* mov edi, dword ptr [0x1000a30c] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if ((c->sf != c->of)) goto L_00967384; /* jl 0x967384 */
    goto L_009673a6; /* jmp 0x9673a6 */
L_009673a4:;
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
L_009673a6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_009673b4; /* je 0x9673b4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x009673b3u); f_00964828(c); /* call 0x964828 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_009673b4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    if (!c->zf) goto L_009673c5; /* jne 0x9673c5 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x58] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x009673c1u); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_009673d7; /* jmp 0x9673d7 */
L_009673c5:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x009673cau); call_indirect(c, t_); } /* call ebx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0xbu); /* cmp dword ptr [ebp + 8], 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_009673d7; /* je 0x9673d7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x4u); /* cmp dword ptr [ebp + 8], 4 */
    if (!c->zf) goto L_009673e9; /* jne 0x9673e9 */
L_009673d7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if (!c->zf) goto L_009673e9; /* jne 0x9673e9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_009673e9:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_009673eb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009673f0(CPU *c) { /* FUN_100073f0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x96a314u))); /* mov ecx, dword ptr [0x1000a314] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    if (c->zf) goto L_00967419; /* je 0x967419 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edi, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->edi * 4)); /* lea edi, [edx + edi*4] */
L_0096740d:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_00967419; /* jae 0x967419 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (!c->zf) goto L_0096740d; /* jne 0x96740d */
L_00967419:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea ecx, [edx + ecx*4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00967428; /* jae 0x967428 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (c->zf) goto L_0096742a; /* je 0x96742a */
L_00967428:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0096742a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0096742d(CPU *c) { /* FUN_1000742d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x969618u; PUSH32(c, v_); } /* push 0x10009618 */
    { uint32_t v_ = 0x9641dcu; PUSH32(c, v_); } /* push 0x100041dc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(0x96d010u))); /* mov eax, dword ptr [0x1000d010] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_0096749c; /* jne 0x96749c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x969610u; PUSH32(c, v_); } /* push 0x10009610 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x9690d0u)); PUSH32(c, 0x00967472u); call_indirect(c, t_); } /* call dword ptr [0x100090d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0096747a; /* je 0x96747a */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00967497; /* jmp 0x967497 */
L_0096747a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x96960cu; PUSH32(c, v_); } /* push 0x1000960c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x9690ccu)); PUSH32(c, 0x0096748cu); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967562; /* je 0x967562 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00967497:;
    W32((uint32_t)(0x96d010u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d010], eax */
L_0096749c:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_009674c5; /* jne 0x9674c5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_009674ad; /* jne 0x9674ad */
    c->eax = (uint32_t)(R32((uint32_t)(0x96d028u))); /* mov eax, dword ptr [0x1000d028] */
L_009674ad:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9690ccu)); PUSH32(c, 0x009674c0u); call_indirect(c, t_); } /* call dword ptr [0x100090cc] */
    goto L_00967564; /* jmp 0x967564 */
L_009674c5:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00967562; /* jne 0x967562 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->ebx); /* cmp dword ptr [ebp + 0x18], ebx */
    if (!c->zf) goto L_009674db; /* jne 0x9674db */
    c->eax = (uint32_t)(R32((uint32_t)(0x96d038u))); /* mov eax, dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
L_009674db:;
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
    { uint32_t t_ = R32((uint32_t)(0x9690c8u)); PUSH32(c, 0x009674f8u); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00967562; /* je 0x967562 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax)); /* lea edi, [eax + eax] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00967511u); f_009670b0(c); /* call 0x9670b0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(c->esp); /* mov esi, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00967521u); f_00966820(c); /* call 0x966820 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00967531; /* jmp 0x967531 */
L_00967531:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00967562; /* je 0x967562 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0x9690c8u)); PUSH32(c, 0x0096754eu); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00967562; /* je 0x967562 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d0u)); PUSH32(c, 0x00967560u); call_indirect(c, t_); } /* call dword ptr [0x100090d0] */
    goto L_00967564; /* jmp 0x967564 */
L_00967562:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00967564:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00967526(CPU *c) { /* PTR_00967526 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0096752a(CPU *c) { /* PTR_0096752a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00967562; /* je 0x967562 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0x9690c8u)); PUSH32(c, 0x0096754eu); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00967562; /* je 0x967562 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d0u)); PUSH32(c, 0x00967560u); call_indirect(c, t_); } /* call dword ptr [0x100090d0] */
    goto L_00967564; /* jmp 0x967564 */
L_00967562:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00967564:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00967576(CPU *c) { /* FUN_10007576 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x969628u; PUSH32(c, v_); } /* push 0x10009628 */
    { uint32_t v_ = 0x9641dcu; PUSH32(c, v_); } /* push 0x100041dc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0x96d040u)), c->edi); /* cmp dword ptr [0x1000d040], edi */
    if (!c->zf) goto L_009675ec; /* jne 0x9675ec */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x969610u; PUSH32(c, v_); } /* push 0x10009610 */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x009675beu); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009675ca; /* je 0x9675ca */
    W32((uint32_t)(0x96d040u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000d040], ebx */
    goto L_009675ec; /* jmp 0x9675ec */
L_009675ca:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x96960cu; PUSH32(c, v_); } /* push 0x1000960c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x9690d4u)); PUSH32(c, 0x009675dau); call_indirect(c, t_); } /* call dword ptr [0x100090d4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    W32((uint32_t)(0x96d040u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x1000d040], 2 */
L_009675ec:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->edi); /* cmp dword ptr [ebp + 0x14], edi */
    if ((c->zf || c->sf != c->of)) goto L_00967601; /* jle 0x967601 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x009675fcu); f_0096779a(c); /* call 0x96779a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_00967601:;
    c->eax = (uint32_t)(R32((uint32_t)(0x96d040u))); /* mov eax, dword ptr [0x1000d040] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00967628; /* jne 0x967628 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d4u)); PUSH32(c, 0x00967623u); call_indirect(c, t_); } /* call dword ptr [0x100090d4] */
    goto L_00967706; /* jmp 0x967706 */
L_00967628:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00967704; /* jne 0x967704 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), c->edi); /* cmp dword ptr [ebp + 0x20], edi */
    if (!c->zf) goto L_0096763e; /* jne 0x96763e */
    c->eax = (uint32_t)(R32((uint32_t)(0x96d038u))); /* mov eax, dword ptr [0x1000d038] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
L_0096763e:;
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
    { uint32_t t_ = R32((uint32_t)(0x9690c8u)); PUSH32(c, 0x0096765bu); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x1c], ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea eax, [ebx + ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00967678u); f_009670b0(c); /* call 0x9670b0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00967699; /* jmp 0x967699 */
L_00967699:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9690c8u)); PUSH32(c, 0x009676b3u); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x009676c9u); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00967718; /* je 0x967718 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00967793; /* je 0x967793 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00967704; /* jg 0x967704 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x009676fcu); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00967793; /* jne 0x967793 */
L_00967704:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00967706:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00967718:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x0096772cu); f_009670b0(c); /* call 0x9670b0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_0096774c; /* jmp 0x96774c */
L_0096774c:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x00967764u); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00967773; /* jne 0x967773 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00967779; /* jmp 0x967779 */
L_00967773:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00967779:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x969068u)); PUSH32(c, 0x00967789u); call_indirect(c, t_); } /* call dword ptr [0x10009068] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
L_00967793:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00967706; /* jmp 0x967706 */
}

void f_00967686(CPU *c) { /* PTR_00967686 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0096768a(CPU *c) { /* PTR_0096768a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ebx, dword ptr [ebp - 0x1c] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x9690c8u)); PUSH32(c, 0x009676b3u); call_indirect(c, t_); } /* call dword ptr [0x100090c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x009676c9u); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00967718; /* je 0x967718 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00967793; /* je 0x967793 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00967704; /* jg 0x967704 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x009676fcu); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00967793; /* jne 0x967793 */
L_00967704:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00967706:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00967718:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x0096772cu); f_009670b0(c); /* call 0x9670b0 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_0096774c; /* jmp 0x96774c */
L_0096774c:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x00967764u); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967704; /* je 0x967704 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00967773; /* jne 0x967773 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00967779; /* jmp 0x967779 */
L_00967773:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00967779:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x969068u)); PUSH32(c, 0x00967789u); call_indirect(c, t_); } /* call dword ptr [0x10009068] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00967704; /* je 0x967704 */
L_00967793:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00967706; /* jmp 0x967706 */
}

void f_00967704(CPU *c) { /* PTR_00967704 */
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

void f_0096773a(CPU *c) { /* PTR_0096773a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0096773e(CPU *c) { /* PTR_0096773e */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) { f_00967704(c); return; } /* je 0x967704 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x9690d8u)); PUSH32(c, 0x00967764u); call_indirect(c, t_); } /* call dword ptr [0x100090d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00967704(c); return; } /* je 0x967704 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00967773; /* jne 0x967773 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00967779; /* jmp 0x967779 */
L_00967773:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00967779:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x969068u)); PUSH32(c, 0x00967789u); call_indirect(c, t_); } /* call dword ptr [0x10009068] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) { f_00967704(c); return; } /* je 0x967704 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { jump_indirect(c, 0x00967706u, 0x00967795u); return; } /* jmp 0x967706 */
}

void f_0096779a(CPU *c) { /* FUN_1000779a */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea ecx, [edx - 1] */
    if (c->zf) goto L_009677b7; /* je 0x9677b7 */
L_009677aa:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_009677b7; /* je 0x9677b7 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_009677aa; /* jne 0x9677aa */
L_009677b7:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_009677c2; /* jne 0x9677c2 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
L_009677c2:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esp += 4; return; /* ret  */
}

void f_009677c5(CPU *c) { /* FUN_100077c5 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi)); /* lea ecx, [edx + esi] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->cf) goto L_009677db; /* jb 0x9677db */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (!c->cf) goto L_009677de; /* jae 0x9677de */
L_009677db:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_009677de:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->esp += 4; return; /* ret  */
}

void f_009677e6(CPU *c) { /* ___add_12 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x009677fau); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967818; /* je 0x967818 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x0096780eu); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967818; /* je 0x967818 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00967818:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [edi + 4] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00967826u); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967830; /* je 0x967830 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00967830:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x0096783eu); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00967844(CPU *c) { /* FUN_10007844 */
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

void f_00967872(CPU *c) { /* FUN_10007872 */
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

void f_0096789f(CPU *c) { /* FUN_1000789f */
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
    if ((c->cf || c->zf)) goto L_00967913; /* jbe 0x967913 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
L_009678c6:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea edi, [ebp - 0x10] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x009678d4u); f_00967844(c); /* call 0x967844 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009678dau); f_00967844(c); /* call 0x967844 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009678e4u); f_009677e6(c); /* call 0x9677e6 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009678eau); f_00967844(c); /* call 0x967844 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx eax, byte ptr [eax] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00967905u); f_009677e6(c); /* call 0x9677e6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_009678c6; /* jne 0x9678c6 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00967913:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->edx); /* cmp dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00967940; /* jne 0x967940 */
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
    goto L_00967913; /* jmp 0x967913 */
L_00967940:;
    c->esi = (uint32_t)((uint32_t)0x8000u); /* mov esi, 0x8000 */
L_00967945:;
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->esi)); /* test dword ptr [ebx + 8], esi */
    if (!c->zf) goto L_0096795a; /* jne 0x96795a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00967950u); f_00967844(c); /* call 0x967844 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp - 4], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00967945; /* jmp 0x967945 */
L_0096795a:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ax, word ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ebx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebx + 0xa], ax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00967966(CPU *c) { /* FUN_10007966 */
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
L_009679a1:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov cl, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u); /* cmp cl, 0x20 */
    if (c->zf) goto L_009679b7; /* je 0x9679b7 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x9u); /* cmp cl, 9 */
    if (c->zf) goto L_009679b7; /* je 0x9679b7 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xau); /* cmp cl, 0xa */
    if (c->zf) goto L_009679b7; /* je 0x9679b7 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xdu); /* cmp cl, 0xd */
    if (!c->zf) goto L_009679ba; /* jne 0x9679ba */
L_009679b7:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_009679a1; /* jmp 0x9679a1 */
L_009679ba:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_009679bd:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if ((!c->cf && !c->zf)) goto L_00967c40; /* ja 0x967c40 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x967e07u)); switch (t_) { case 0x009679d0u: goto L_009679d0; case 0x00967a1fu: goto L_00967a1f; case 0x00967a76u: goto L_00967a76; case 0x00967aa0u: goto L_00967aa0; case 0x00967afbu: goto L_00967afb; case 0x00967b72u: goto L_00967b72; case 0x00967ba8u: goto L_00967ba8; case 0x00967bd1u: goto L_00967bd1; case 0x00967bf2u: goto L_00967bf2; case 0x00967c0cu: goto L_00967c0c; case 0x00967c40u: goto L_00967c40; case 0x00967c56u: goto L_00967c56; default: jump_indirect(c, t_, 0x009679c9u); return; } } /* jmp dword ptr [eax*4 + 0x10007e07] */
L_009679d0:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_009679e1; /* jl 0x9679e1 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_009679e1; /* jg 0x9679e1 */
L_009679da:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00967bfe; /* jmp 0x967bfe */
L_009679e1:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0x96c344u))); /* cmp bl, byte ptr [0x1000c344] */
    if (!c->zf) goto L_009679f0; /* jne 0x9679f0 */
L_009679e9:;
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00967c36; /* jmp 0x967c36 */
L_009679f0:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00967a16; /* je 0x967a16 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00967a0a; /* je 0x967a0a */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00967cd9; /* jne 0x967cd9 */
    goto L_00967a99; /* jmp 0x967a99 */
L_00967a0a:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967a16:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967a1f:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    if ((c->sf != c->of)) goto L_00967a2c; /* jl 0x967a2c */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_009679da; /* jle 0x9679da */
L_00967a2c:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0x96c344u))); /* cmp bl, byte ptr [0x1000c344] */
    if (c->zf) goto L_00967af4; /* je 0x967af4 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00967a6e; /* je 0x967a6e */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00967a6e; /* je 0x967a6e */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00967a99; /* je 0x967a99 */
L_00967a47:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x43u); /* cmp bl, 0x43 */
    if ((c->zf || c->sf != c->of)) goto L_00967cd9; /* jle 0x967cd9 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x45u); /* cmp bl, 0x45 */
    if ((c->zf || c->sf != c->of)) goto L_00967a67; /* jle 0x967a67 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x63u); /* cmp bl, 0x63 */
    if ((c->zf || c->sf != c->of)) goto L_00967cd9; /* jle 0x967cd9 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x65u); /* cmp bl, 0x65 */
    if ((!c->zf && c->sf == c->of)) goto L_00967cd9; /* jg 0x967cd9 */
L_00967a67:;
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    goto L_00967c36; /* jmp 0x967c36 */
L_00967a6e:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    goto L_00967c36; /* jmp 0x967c36 */
L_00967a76:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00967a84; /* jl 0x967a84 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_009679da; /* jle 0x9679da */
L_00967a84:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0x96c344u))); /* cmp bl, byte ptr [0x1000c344] */
    if (c->zf) goto L_009679e9; /* je 0x9679e9 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00967c4e; /* jne 0x967c4e */
L_00967a99:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967aa0:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
L_00967aa3:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), c->edx); /* cmp dword ptr [0x1000c340], edx */
    if ((c->zf || c->sf != c->of)) goto L_00967abc; /* jle 0x967abc */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967ab5u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00967aca; /* jmp 0x967aca */
L_00967abc:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00967aca:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967aec; /* je 0x967aec */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00967ae4; /* jae 0x967ae4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00967ae7; /* jmp 0x967ae7 */
L_00967ae4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
L_00967ae7:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00967aa3; /* jmp 0x967aa3 */
L_00967aec:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0x96c344u))); /* cmp bl, byte ptr [0x1000c344] */
    if (!c->zf) goto L_00967b5b; /* jne 0x967b5b */
L_00967af4:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967afb:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if (!c->zf) goto L_00967b14; /* jne 0x967b14 */
L_00967b07:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00967b14; /* jne 0x967b14 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00967b07; /* jmp 0x967b07 */
L_00967b14:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), c->edx); /* cmp dword ptr [0x1000c340], edx */
    if ((c->zf || c->sf != c->of)) goto L_00967b2d; /* jle 0x967b2d */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967b26u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00967b3b; /* jmp 0x967b3b */
L_00967b2d:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00967b3b:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967b5b; /* je 0x967b5b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00967b56; /* jae 0x967b56 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
L_00967b56:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00967b14; /* jmp 0x967b14 */
L_00967b5b:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00967a6e; /* je 0x967a6e */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00967a6e; /* je 0x967a6e */
    goto L_00967a47; /* jmp 0x967a47 */
L_00967b72:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), c->edx); /* cmp dword ptr [0x1000c340], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if ((c->zf || c->sf != c->of)) goto L_00967b8e; /* jle 0x967b8e */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967b87u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00967b9c; /* jmp 0x967b9c */
L_00967b8e:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00967b9c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967c4e; /* je 0x967c4e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00967bff; /* jmp 0x967bff */
L_00967ba8:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xfffffffeu)); /* lea ecx, [edi - 2] */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if ((c->sf != c->of)) goto L_00967bb8; /* jl 0x967bb8 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00967bfc; /* jle 0x967bfc */
L_00967bb8:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00967c34; /* je 0x967c34 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00967c28; /* je 0x967c28 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00967cdc; /* jne 0x967cdc */
L_00967bcd:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_00967c36; /* jmp 0x967c36 */
L_00967bd1:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
L_00967bd4:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00967bde; /* jne 0x967bde */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00967bd4; /* jmp 0x967bd4 */
L_00967bde:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00967cd9; /* jl 0x967cd9 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00967cd9; /* jg 0x967cd9 */
    goto L_00967bfc; /* jmp 0x967bfc */
L_00967bf2:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00967c05; /* jl 0x967c05 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00967c05; /* jg 0x967c05 */
L_00967bfc:;
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
L_00967bfe:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00967bff:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967c05:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00967c4e; /* jne 0x967c4e */
    goto L_00967bcd; /* jmp 0x967bcd */
L_00967c0c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    if (c->zf) goto L_00967c3c; /* je 0x967c3c */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if (c->zf) goto L_00967c34; /* je 0x967c34 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00967cdc; /* jne 0x967cdc */
L_00967c28:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x18], 0xffffffff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967c34:;
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
L_00967c36:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967c3c:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00967c40:;
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if (c->zf) goto L_00967cde; /* je 0x967cde */
    goto L_009679bd; /* jmp 0x9679bd */
L_00967c4e:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00967cde; /* jmp 0x967cde */
L_00967c56:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00967c5f:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000c340], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00967c77; /* jle 0x967c77 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967c73u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00967c86; /* jmp 0x967c86 */
L_00967c77:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00967c86:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967ca6; /* je 0x967ca6 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea esi, [ecx + eax*2 - 0x30] */
    (void)sub32(c, c->esi, (uint32_t)0x1450u); /* cmp esi, 0x1450 */
    if ((!c->zf && c->sf == c->of)) goto L_00967ca1; /* jg 0x967ca1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00967c5f; /* jmp 0x967c5f */
L_00967ca1:;
    c->esi = (uint32_t)((uint32_t)0x1451u); /* mov esi, 0x1451 */
L_00967ca6:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
L_00967ca9:;
    (void)sub32(c, R32((uint32_t)(0x96c340u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000c340], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00967cc1; /* jle 0x967cc1 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967cbdu); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00967cd0; /* jmp 0x967cd0 */
L_00967cc1:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov ecx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00967cd0:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00967cd9; /* je 0x967cd9 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00967ca9; /* jmp 0x967ca9 */
L_00967cd9:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00967cde; /* jmp 0x967cde */
L_00967cdc:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00967cde:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00967dc6; /* je 0x967dc6 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00967d0a; /* jbe 0x967d0a */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00967cfe; /* jl 0x967cfe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00967cfe:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00967d0d; /* jmp 0x967d0d */
L_00967d0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00967d0d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00967dbc; /* jbe 0x967dbc */
L_00967d17:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00967d25; /* jne 0x967d25 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00967d17; /* jmp 0x967d17 */
L_00967d25:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967d35u); f_0096789f(c); /* call 0x96789f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00967d44; /* jge 0x967d44 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00967d44:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00967d4f; /* jne 0x967d4f */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00967d4f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00967d57; /* jne 0x967d57 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00967d57:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00967d8e; /* jle 0x967d8e */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00967d65:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00967d71:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00967dd7; /* je 0x967dd7 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00967dec; /* jmp 0x967dec */
L_00967d8e:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00967d9e; /* jge 0x967d9e */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00967d65; /* jmp 0x967d65 */
L_00967d9e:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967dabu); f_009684aa(c); /* call 0x9684aa */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00967d71; /* jmp 0x967d71 */
L_00967dbc:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00967d71; /* jmp 0x967d71 */
L_00967dc6:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00967dec; /* jmp 0x967dec */
L_00967dd7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00967dec; /* je 0x967dec */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00967dec:;
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

void f_009679d0(CPU *c) { /* PTR_009679d0 */
    PREEMPT_POLL(c);
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_009679e1; /* jl 0x9679e1 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_009679e1; /* jg 0x9679e1 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00967bfe; /* jmp 0x967bfe */
L_009679e1:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0x96c344u))); /* cmp bl, byte ptr [0x1000c344] */
    if (!c->zf) goto L_009679f0; /* jne 0x9679f0 */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00967c36; /* jmp 0x967c36 */
L_009679f0:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00967a16; /* je 0x967a16 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00967a0a; /* je 0x967a0a */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00967cd9; /* jne 0x967cd9 */
    goto L_00967a99; /* jmp 0x967a99 */
L_00967a0a:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x009679bdu, 0x00967a14u); return; } /* jmp 0x9679bd */
L_00967a16:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x009679bdu, 0x00967a1du); return; } /* jmp 0x9679bd */
L_00967a99:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { jump_indirect(c, 0x009679bdu, 0x00967a9bu); return; } /* jmp 0x9679bd */
L_00967bfe:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { jump_indirect(c, 0x009679bdu, 0x00967c00u); return; } /* jmp 0x9679bd */
L_00967c36:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x009679bdu, 0x00967c37u); return; } /* jmp 0x9679bd */
L_00967cd9:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00967cde; /* jmp 0x967cde */
L_00967cde:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00967dc6; /* je 0x967dc6 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00967d0a; /* jbe 0x967d0a */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00967cfe; /* jl 0x967cfe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00967cfe:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00967d0d; /* jmp 0x967d0d */
L_00967d0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00967d0d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00967dbc; /* jbe 0x967dbc */
L_00967d17:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00967d25; /* jne 0x967d25 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00967d17; /* jmp 0x967d17 */
L_00967d25:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967d35u); f_0096789f(c); /* call 0x96789f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00967d44; /* jge 0x967d44 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00967d44:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00967d4f; /* jne 0x967d4f */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00967d4f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00967d57; /* jne 0x967d57 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00967d57:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00967d8e; /* jle 0x967d8e */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00967d65:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00967d71:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00967dd7; /* je 0x967dd7 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00967dec; /* jmp 0x967dec */
L_00967d8e:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00967d9e; /* jge 0x967d9e */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00967d65; /* jmp 0x967d65 */
L_00967d9e:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967dabu); f_009684aa(c); /* call 0x9684aa */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00967d71; /* jmp 0x967d71 */
L_00967dbc:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00967d71; /* jmp 0x967d71 */
L_00967dc6:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00967dec; /* jmp 0x967dec */
L_00967dd7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00967dec; /* je 0x967dec */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00967dec:;
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

void f_00967c4e(CPU *c) { /* PTR_00967c4e */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00967cde; /* jmp 0x967cde */
L_00967cde:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00967dc6; /* je 0x967dc6 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00967d0a; /* jbe 0x967d0a */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00967cfe; /* jl 0x967cfe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00967cfe:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00967d0d; /* jmp 0x967d0d */
L_00967d0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00967d0d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00967dbc; /* jbe 0x967dbc */
L_00967d17:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00967d25; /* jne 0x967d25 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00967d17; /* jmp 0x967d17 */
L_00967d25:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967d35u); f_0096789f(c); /* call 0x96789f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00967d44; /* jge 0x967d44 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00967d44:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00967d4f; /* jne 0x967d4f */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00967d4f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00967d57; /* jne 0x967d57 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00967d57:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00967d8e; /* jle 0x967d8e */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00967d65:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00967d71:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00967dd7; /* je 0x967dd7 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00967dec; /* jmp 0x967dec */
L_00967d8e:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00967d9e; /* jge 0x967d9e */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00967d65; /* jmp 0x967d65 */
L_00967d9e:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967dabu); f_009684aa(c); /* call 0x9684aa */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00967d71; /* jmp 0x967d71 */
L_00967dbc:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00967d71; /* jmp 0x967d71 */
L_00967dc6:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00967dec; /* jmp 0x967dec */
L_00967dd7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00967dec; /* je 0x967dec */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00967dec:;
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

void f_00967e07(CPU *c) { /* PTR_00967e07 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(sar8(c, R8(a_), 1))); } /* sar byte ptr [ecx], 1 */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ebx)))); } /* adc byte ptr [edi], bl */
    if (PF(c)) goto L_00967e0e; /* jp 0x967e0e */
L_00967e0e:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x7au); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->edx >> 8))))); } /* adc byte ptr [esi + 0x7a], dh */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xfb10007au))); /* mov al, byte ptr [0xfb10007a] */
    if (PF(c)) goto L_00967e1a; /* jp 0x967e1a */
L_00967e1a:;
    { uint32_t a_ = (uint32_t)(c->edx + 0x7bu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->edx >> 8))))); } /* adc byte ptr [edx + 0x7b], dh */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x7bu)); /* test al, 0x7b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x00967e23u, "unsupported: bnd jnp 0x967e26"); /* bnd jnp 0x967e26 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(adc8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx))); /* adc cl, dl */
    if (!PF(c)) goto L_00967e2a; /* jnp 0x967e2a */
L_00967e2a:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x7cu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->edx)))); } /* adc byte ptr [esi + 0x7c], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    if ((c->sf != c->of)) goto L_00967e32; /* jl 0x967e32 */
L_00967e32:;
    { uint32_t a_ = (uint32_t)(c->esp + c->edi * 2); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ecx)))); } /* adc byte ptr [esp + edi*2], cl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { f_00967e37(c); return; }
}

void f_00967e37(CPU *c) { /* FUN_10007e37 */
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
    if (c->zf) goto L_00967e99; /* je 0x967e99 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx + 2], 0x2d */
    goto L_00967e9d; /* jmp 0x967e9d */
L_00967e99:;
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
L_00967e9d:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    if (!c->zf) goto L_00967ec3; /* jne 0x967ec3 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00967ec3; /* jne 0x967ec3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (!c->zf) goto L_00967ec3; /* jne 0x967ec3 */
L_00967eae:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ebx + 0x4u), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebx + 4], 0x30 */
    goto L_009680c1; /* jmp 0x9680c1 */
L_00967ec3:;
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->esi)); /* cmp dx, si */
    if (!c->zf) goto L_00967f42; /* jne 0x967f42 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    W16((uint32_t)(c->ebx), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [ebx], 1 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00967edc; /* jne 0x967edc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00967eeb; /* je 0x967eeb */
L_00967edc:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x40000000u)); /* test edi, 0x40000000 */
    if (!c->zf) goto L_00967eeb; /* jne 0x967eeb */
    { uint32_t v_ = 0x969658u; PUSH32(c, v_); } /* push 0x10009658 */
    goto L_00967f31; /* jmp 0x967f31 */
L_00967eeb:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->ecx) & ((uint16_t)c->ecx))); /* test cx, cx */
    if (c->zf) goto L_00967f05; /* je 0x967f05 */
    (void)sub32(c, c->edi, (uint32_t)0xc0000000u); /* cmp edi, 0xc0000000 */
    if (!c->zf) goto L_00967f05; /* jne 0x967f05 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00967f2c; /* jne 0x967f2c */
    { uint32_t v_ = 0x969650u; PUSH32(c, v_); } /* push 0x10009650 */
    goto L_00967f14; /* jmp 0x967f14 */
L_00967f05:;
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00967f2c; /* jne 0x967f2c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00967f2c; /* jne 0x967f2c */
    { uint32_t v_ = 0x969648u; PUSH32(c, v_); } /* push 0x10009648 */
L_00967f14:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967f1du); f_00966730(c); /* call 0x966730 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [ebx + 3], 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00967f23:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    goto L_0096809a; /* jmp 0x96809a */
L_00967f2c:;
    { uint32_t v_ = 0x969640u; PUSH32(c, v_); } /* push 0x10009640 */
L_00967f31:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967f3au); f_00966730(c); /* call 0x966730 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [ebx + 3], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00967f23; /* jmp 0x967f23 */
L_00967f42:;
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
    PUSH32(c, 0x00967f88u); f_009684aa(c); /* call 0x9684aa */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xfffffffau)), (uint16_t)0x3fffu); /* cmp word ptr [ebp - 6], 0x3fff */
    if (c->cf) goto L_00967fa3; /* jb 0x967fa3 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967fa1u); f_0096828a(c); /* call 0x96828a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00967fa3:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x18u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x18], 1 */
    W16((uint32_t)(c->ebx), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [ebx], si */
    if (c->zf) goto L_00967fbd; /* je 0x967fbd */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->esi)); /* movsx eax, si */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((!c->zf && c->sf == c->of)) goto L_00967fc0; /* jg 0x967fc0 */
    goto L_00967eae; /* jmp 0x967eae */
L_00967fbd:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
L_00967fc0:;
    (void)sub32(c, c->edi, (uint32_t)0x15u); /* cmp edi, 0x15 */
    if ((c->zf || c->sf != c->of)) goto L_00967fc8; /* jle 0x967fc8 */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00967fc8:;
    c->esi = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xfffffffau))); /* movzx esi, word ptr [ebp - 6] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3ffeu)); /* sub esi, 0x3ffe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffau); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebp - 6], 0 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x1c], 8 */
L_00967fde:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00967fe7u); f_00967844(c); /* call 0x967844 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00967fde; /* jne 0x967fde */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00968008; /* jge 0x968008 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffu))); /* and esi, 0xff */
    if ((c->zf || c->sf != c->of)) goto L_00968008; /* jle 0x968008 */
L_00967ffb:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00968004u); f_00967872(c); /* call 0x967872 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00967ffb; /* jne 0x967ffb */
L_00968008:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea ecx, [edi + 1] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
    if ((c->zf || c->sf != c->of)) goto L_00968065; /* jle 0x968065 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x14], ecx */
L_00968018:;
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea esi, [ebp - 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea edi, [ebp + 8] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x0096802au); f_00967844(c); /* call 0x967844 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00968033u); f_00967844(c); /* call 0x967844 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00968040u); f_009677e6(c); /* call 0x9677e6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00968049u); f_00967844(c); /* call 0x967844 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffbu))); /* mov al, byte ptr [ebp - 5] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffbu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 5], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x30u)); /* add al, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x14] */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    if (!c->zf) goto L_00968018; /* jne 0x968018 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
L_00968065:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xffffffffu))); /* mov cl, byte ptr [eax - 1] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x35u); /* cmp cl, 0x35 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ecx, [ebx + 4] */
    if ((c->sf != c->of)) goto L_009680a2; /* jl 0x9680a2 */
L_00968072:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00968085; /* jb 0x968085 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00968081; /* jne 0x968081 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00968072; /* jmp 0x968072 */
L_00968081:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00968089; /* jae 0x968089 */
L_00968085:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebx] */
L_00968089:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_0096808b:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx))); /* sub al, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x3u)); /* sub al, 3 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebx + 3], al */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ebx + 4], 0 */
L_0096809a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_0096809d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_009680a2:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_009680b2; /* jb 0x9680b2 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (!c->zf) goto L_009680ae; /* jne 0x9680ae */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_009680a2; /* jmp 0x9680a2 */
L_009680ae:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_0096808b; /* jae 0x96808b */
L_009680b2:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_009680c1:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x5u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebx + 5], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_0096809d; /* jmp 0x96809d */
}

void f_009680ca(CPU *c) { /* FUN_100080ca */
    PREEMPT_POLL(c);
    PUSH32(c, 0x009680cfu); f_00962971(c); /* call 0x962971 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_009680d3(CPU *c) { /* FUN_100080d3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x96d028u)), c->ebx); /* cmp dword ptr [0x1000d028], ebx */
    if (!c->zf) goto L_009680f1; /* jne 0x9680f1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00968140; /* jl 0x968140 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00968140; /* jg 0x968140 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_009680f1:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x96d184u); /* mov esi, 0x1000d184 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x9690b4u)); PUSH32(c, 0x009680ffu); call_indirect(c, t_); } /* call dword ptr [0x100090b4] */
    (void)sub32(c, R32((uint32_t)(0x96d180u)), c->ebx); /* cmp dword ptr [0x1000d180], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0x9690b0u))); /* mov edi, dword ptr [0x100090b0] */
    if (c->zf) goto L_0096811b; /* je 0x96811b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00968110u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00968117u); f_009647c7(c); /* call 0x9647c7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_0096811b:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00968124u); f_00968142(c); /* call 0x968142 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00968137; /* je 0x968137 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00968134u); f_00964828(c); /* call 0x964828 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0096813a; /* jmp 0x96813a */
L_00968137:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x0096813au); call_indirect(c, t_); } /* call edi */
L_0096813a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00968140:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00968142(CPU *c) { /* FUN_10008142 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x96d028u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d028], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_0096816d; /* jne 0x96816d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_0096820b; /* jl 0x96820b */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_0096820b; /* jg 0x96820b */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_0096820b; /* jmp 0x96820b */
L_0096816d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_009681a0; /* jge 0x9681a0 */
    (void)sub32(c, R32((uint32_t)(0x96c340u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000c340], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0096818d; /* jle 0x96818d */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00968189u); f_0096600b(c); /* call 0x96600b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00968198; /* jmp 0x968198 */
L_0096818d:;
    c->eax = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov eax, dword ptr [0x1000c34c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_00968198:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009681a0; /* jne 0x9681a0 */
L_0096819c:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_0096820b; /* jmp 0x96820b */
L_009681a0:;
    c->edx = (uint32_t)(R32((uint32_t)(0x96c34cu))); /* mov edx, dword ptr [0x1000c34c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_009681c3; /* je 0x9681c3 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_009681cc; /* jmp 0x9681cc */
L_009681c3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_009681cc:;
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
    { uint32_t v_ = R32((uint32_t)(0x96d028u)); PUSH32(c, v_); } /* push dword ptr [0x1000d028] */
    PUSH32(c, 0x009681ecu); f_00967576(c); /* call 0x967576 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0096819c; /* je 0x96819c */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009681fe; /* jne 0x9681fe */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_0096820b; /* jmp 0x96820b */
L_009681fe:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_0096820b:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00968210(CPU *c) { /* FUN_10008210 */
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
L_00968224:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00968231; /* je 0x968231 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00968224; /* jmp 0x968224 */
L_00968231:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_00968238:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00968246; /* je 0x968246 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00968238; /* jae 0x968238 */
L_00968246:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00968250(CPU *c) { /* FUN_10008250 */
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
L_00968264:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00968271; /* je 0x968271 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00968264; /* jmp 0x968264 */
L_00968271:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00968274:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00968284; /* je 0x968284 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00968274; /* jae 0x968274 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00968284:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0096828a(CPU *c) { /* FUN_1000828a */
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
    if (!c->cf) goto L_0096848a; /* jae 0x96848a */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7fffu); /* cmp cx, 0x7fff */
    if (!c->cf) goto L_0096848a; /* jae 0x96848a */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xbffdu); /* cmp dx, 0xbffd */
    if ((!c->cf && !c->zf)) goto L_0096848a; /* ja 0x96848a */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x3fbfu); /* cmp dx, 0x3fbf */
    if ((!c->cf && !c->zf)) goto L_009682f3; /* ja 0x9682f3 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0096832d; /* jmp 0x96832d */
L_009682f3:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    c->edx = (uint32_t)((uint32_t)0x7fffffffu); /* mov edx, 0x7fffffff */
    if (!c->zf) goto L_00968315; /* jne 0x968315 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + 0x8u)) & c->edx)); /* test dword ptr [esi + 8], edx */
    if (!c->zf) goto L_00968315; /* jne 0x968315 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), c->eax); /* cmp dword ptr [esi + 4], eax */
    if (!c->zf) goto L_00968317; /* jne 0x968317 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_00968317; /* jne 0x968317 */
    goto L_00968484; /* jmp 0x968484 */
L_00968315:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00968317:;
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_0096833a; /* jne 0x96833a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->edx)); /* test dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_0096833a; /* jne 0x96833a */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x4u)), c->eax); /* cmp dword ptr [ebx + 4], eax */
    if (!c->zf) goto L_0096833a; /* jne 0x96833a */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (!c->zf) goto L_0096833a; /* jne 0x96833a */
L_0096832d:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_009684a5; /* jmp 0x9684a5 */
L_0096833a:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [ebp + 0xc], 5 */
L_0096834a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_0096839e; /* jle 0x96839e */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea ecx, [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
L_00968366:;
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
    PUSH32(c, 0x00968384u); f_009677c5(c); /* call 0x9677c5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00968391; /* je 0x968391 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [eax] */
L_00968391:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 8], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x2u))); } /* sub dword ptr [ebp - 0xc], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_00968366; /* jne 0x968366 */
L_0096839e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 4], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0096834a; /* jg 0x96834a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xc002u))); } /* add dword ptr [ebp + 8], 0xc002 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->zf || c->sf != c->of)) goto L_009683e1; /* jle 0x9683e1 */
L_009683bc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffe7u)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 0x19], 0x80 */
    if (!c->zf) goto L_009683da; /* jne 0x9683da */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009683cbu); f_00967844(c); /* call 0x967844 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_009683bc; /* jg 0x9683bc */
L_009683da:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0096841a; /* jg 0x96841a */
L_009683e1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->sf == c->of)) goto L_0096841a; /* jge 0x96841a */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0x8u))); /* movsx eax, word ptr [ebp + 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_009683fa:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffdcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x24], 1 */
    if (c->zf) goto L_00968403; /* je 0x968403 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x14] */
L_00968403:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0096840cu); f_00967872(c); /* call 0x967872 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_009683fa; /* jne 0x9683fa */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_0096841a; /* je 0x96841a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x24], 1 */
L_0096841a:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffdcu)), (uint16_t)0x8000u); /* cmp word ptr [ebp - 0x24], 0x8000 */
    if ((!c->cf && !c->zf)) goto L_00968431; /* ja 0x968431 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1ffffu))); /* and eax, 0x1ffff */
    (void)sub32(c, c->eax, (uint32_t)0x18000u); /* cmp eax, 0x18000 */
    if (!c->zf) goto L_00968466; /* jne 0x968466 */
L_00968431:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdeu)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x22], -1 */
    if (!c->zf) goto L_00968463; /* jne 0x968463 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x22], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe2u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x1e], -1 */
    if (!c->zf) goto L_0096845e; /* jne 0x96845e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1e], 0 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffe6u)), (uint16_t)0xffffu); /* cmp word ptr [ebp - 0x1a], 0xffff */
    if (!c->zf) goto L_00968458; /* jne 0x968458 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    W16((uint32_t)(c->ebp + 0xffffffe6u), (uint16_t)((uint16_t)0x8000u)); /* mov word ptr [ebp - 0x1a], 0x8000 */
    goto L_00968466; /* jmp 0x968466 */
L_00968458:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe6u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebp - 0x1a] */
    goto L_00968466; /* jmp 0x968466 */
L_0096845e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1e] */
    goto L_00968466; /* jmp 0x968466 */
L_00968463:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x22] */
L_00968466:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    if (!c->cf) goto L_0096848a; /* jae 0x96848a */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffdeu))); /* mov cx, word ptr [ebp - 0x22] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [esi], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->esi + 0x2u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 2], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->esi + 0x6u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 6], ecx */
L_00968484:;
    W16((uint32_t)(c->esi + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xa], ax */
    goto L_009684a5; /* jmp 0x9684a5 */
L_0096848a:;
    c->edi = (c->edi & 0xffff0000u) | (uint16_t)(neg16(c, ((uint16_t)c->edi))); /* neg di */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edi)); /* sbb edi, edi */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x80000000u))); /* and edi, 0x80000000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7fff8000u)); /* add edi, 0x7fff8000 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
L_009684a5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_009684aa(CPU *c) { /* FUN_100084aa */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)0x96ca10u); /* mov ebx, 0x1000ca10 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00968523; /* je 0x968523 */
    if ((c->sf == c->of)) goto L_009684d2; /* jge 0x9684d2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x96cb70u); /* mov ebx, 0x1000cb70 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
L_009684d2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_009684dd; /* jne 0x9684dd */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
L_009684dd:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00968523; /* je 0x968523 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_009684e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x54u)); /* add ebx, 0x54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sar32(c, R32(a_), 3))); } /* sar dword ptr [ebp + 0xc], 3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_0096851c; /* je 0x96851c */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)sub16(c, R16((uint32_t)(c->ebx + c->eax * 4)), (uint16_t)0x8000u); /* cmp word ptr [ebx + eax*4], 0x8000 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea esi, [ebx + eax*4] */
    if (c->cf) goto L_0096850f; /* jb 0x96850f */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff6u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xa] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
L_0096850f:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00968518u); f_0096828a(c); /* call 0x96828a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_0096851c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_009684e4; /* jne 0x9684e4 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00968523:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00968530(CPU *c) { /* FUN_10008530 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0x96d020u)); /* lea eax, [0x1000d020] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00968583; /* jne 0x968583 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_0096854c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0096857e; /* je 0x96857e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_0096854c; /* je 0x96854c */
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
    if (c->zf) goto L_0096854c; /* je 0x96854c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_0096857e:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_009685fb; /* jmp 0x9685fb */
L_00968583:;
    { guest_lock(); guest_trap(c, 0x00968583u, "unsupported: lock inc dword ptr [0x1000d184]"); guest_unlock(); } /* lock inc dword ptr [0x1000d184] */
    (void)sub32(c, R32((uint32_t)(0x96d180u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d180], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00968597; /* jg 0x968597 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_009685ac; /* jmp 0x9685ac */
L_00968597:;
    { guest_lock(); guest_trap(c, 0x00968597u, "unsupported: lock dec dword ptr [0x1000d184]"); guest_unlock(); } /* lock dec dword ptr [0x1000d184] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009685a5u); f_009647c7(c); /* call 0x9647c7 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_009685ac:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_009685b4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_009685df; /* je 0x9685df */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_009685b4; /* je 0x9685b4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009685c9u); f_009660ef(c); /* call 0x9660ef */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x009685d3u); f_009660ef(c); /* call 0x9660ef */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_009685b4; /* je 0x9685b4 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_009685df:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009685ef; /* jne 0x9685ef */
    { guest_lock(); guest_trap(c, 0x009685e6u, "unsupported: lock dec dword ptr [0x1000d184]"); guest_unlock(); } /* lock dec dword ptr [0x1000d184] */
    goto L_009685f9; /* jmp 0x9685f9 */
L_009685ef:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009685f6u); f_00964828(c); /* call 0x964828 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_009685f9:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_009685fb:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00968600(CPU *c) { /* FUN_10008600 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_009686fa; /* je 0x9686fa */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0x96d020u)); /* lea eax, [0x1000d020] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00968671; /* jne 0x968671 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_0096862c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_00968655; /* je 0x968655 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00968655; /* je 0x968655 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_00968644; /* jb 0x968644 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_00968644; /* ja 0x968644 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_00968644:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_0096864e; /* jb 0x96864e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_0096864e; /* ja 0x96864e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_0096864e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_0096865f; /* jne 0x96865f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0096862c; /* jne 0x96862c */
L_00968655:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_009686fa; /* je 0x9686fa */
L_0096865f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_009686fa; /* jb 0x9686fa */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_009686fa; /* jmp 0x9686fa */
L_00968671:;
    { guest_lock(); guest_trap(c, 0x00968671u, "unsupported: lock inc dword ptr [0x1000d184]"); guest_unlock(); } /* lock inc dword ptr [0x1000d184] */
    (void)sub32(c, R32((uint32_t)(0x96d180u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d180], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00968685; /* jg 0x968685 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_0096869e; /* jmp 0x96869e */
L_00968685:;
    { guest_lock(); guest_trap(c, 0x00968685u, "unsupported: lock dec dword ptr [0x1000d184]"); guest_unlock(); } /* lock dec dword ptr [0x1000d184] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00968695u); f_009647c7(c); /* call 0x9647c7 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_0096869e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_009686a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_009686cf; /* je 0x9686cf */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_009686cf; /* je 0x9686cf */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x009686bau); f_009660ef(c); /* call 0x9660ef */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x009686c4u); f_009660ef(c); /* call 0x9660ef */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_009686d5; /* jne 0x9686d5 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_009686a4; /* jne 0x9686a4 */
L_009686cf:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_009686de; /* je 0x9686de */
L_009686d5:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_009686de; /* jb 0x9686de */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_009686de:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009686ec; /* jne 0x9686ec */
    { guest_lock(); guest_trap(c, 0x009686e3u, "unsupported: lock dec dword ptr [0x1000d184]"); guest_unlock(); } /* lock dec dword ptr [0x1000d184] */
    goto L_009686fa; /* jmp 0x9686fa */
L_009686ec:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x009686f5u); f_00964828(c); /* call 0x964828 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_009686fa:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00968710(CPU *c) { /* PTR_00968710 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00968732; /* jne 0x968732 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00968724u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0096872cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00968773; /* jmp 0x968773 */
L_00968732:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_00968740:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00968740; /* jne 0x968740 */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0096874cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x18u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint64_t r_ = (uint64_t)c->eax * c->esi; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul esi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_0096876e; /* jb 0x96876e */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x10u))); /* cmp edx, dword ptr [esp + 0x10] */
    if ((!c->cf && !c->zf)) goto L_0096876e; /* ja 0x96876e */
    if (c->cf) goto L_0096876f; /* jb 0x96876f */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0xcu))); /* cmp eax, dword ptr [esp + 0xc] */
    if ((c->cf || c->zf)) goto L_0096876f; /* jbe 0x96876f */
L_0096876e:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
L_0096876f:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00968773:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00968780(CPU *c) { /* PTR_00968780 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_009687a1; /* jne 0x9687a1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00968793u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00968799u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_009687f1; /* jmp 0x9687f1 */
L_009687a1:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
L_009687af:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_009687af; /* jne 0x9687af */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x009687bbu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_009687da; /* jb 0x9687da */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0xcu))); /* cmp edx, dword ptr [esp + 0xc] */
    if ((!c->cf && !c->zf)) goto L_009687da; /* ja 0x9687da */
    if (c->cf) goto L_009687e2; /* jb 0x9687e2 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u))); /* cmp eax, dword ptr [esp + 8] */
    if ((c->cf || c->zf)) goto L_009687e2; /* jbe 0x9687e2 */
L_009687da:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x10u)))); /* sub eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0x14u)))); /* sbb edx, dword ptr [esp + 0x14] */
L_009687e2:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0xcu)))); /* sbb edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(sbb32(c, c->edx, (uint32_t)0x0u)); /* sbb edx, 0 */
L_009687f1:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00968800(CPU *c) { /* PTR_00968800 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_00968819; /* jne 0x968819 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_00968819:;
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

void f_00968834(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x969000u)); switch (t_) {  default: jump_indirect(c, t_, 0x00968834u); return; } } /* jmp dword ptr [0x10009000] */
}

void f_00968840(CPU *c) { /* Unwind@10008840 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    { uint32_t v_ = 0x96a048u; PUSH32(c, v_); } /* push 0x1000a048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00968850u); f_00961050(c); /* call 0x961050 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00968854(CPU *c) { /* PTR_00968854 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x9697ccu); /* mov eax, 0x100097cc */
    { f_00961a61(c); return; } /* jmp 0x961a61 */
}
