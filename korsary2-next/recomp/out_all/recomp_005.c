#include "recomp.h"

void f_0044e08c(CPU *c) { /* PTR_0044e08c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e0c8u)); switch (t_) { case 0x0044e0d8u: goto L_0044e0d8; case 0x0044e0e0u: goto L_0044e0e0; case 0x0044e0ecu: goto L_0044e0ec; case 0x0044e100u: goto L_0044e100; default: jump_indirect(c, t_, 0x0044e0bfu); return; } } /* jmp dword ptr [edx*4 + 0x44e0c8] */
L_0044e0d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0e0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0ec:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e100:;
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

void f_0044e094(CPU *c) { /* PTR_0044e094 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e0c8u)); switch (t_) { case 0x0044e0d8u: goto L_0044e0d8; case 0x0044e0e0u: goto L_0044e0e0; case 0x0044e0ecu: goto L_0044e0ec; case 0x0044e100u: goto L_0044e100; default: jump_indirect(c, t_, 0x0044e0bfu); return; } } /* jmp dword ptr [edx*4 + 0x44e0c8] */
L_0044e0d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0e0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0ec:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e100:;
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

void f_0044e09c(CPU *c) { /* PTR_0044e09c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e0c8u)); switch (t_) { case 0x0044e0d8u: goto L_0044e0d8; case 0x0044e0e0u: goto L_0044e0e0; case 0x0044e0ecu: goto L_0044e0ec; case 0x0044e100u: goto L_0044e100; default: jump_indirect(c, t_, 0x0044e0bfu); return; } } /* jmp dword ptr [edx*4 + 0x44e0c8] */
L_0044e0d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0e0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0ec:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e100:;
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

void f_0044e0a4(CPU *c) { /* PTR_0044e0a4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e0c8u)); switch (t_) { case 0x0044e0d8u: goto L_0044e0d8; case 0x0044e0e0u: goto L_0044e0e0; case 0x0044e0ecu: goto L_0044e0ec; case 0x0044e100u: goto L_0044e100; default: jump_indirect(c, t_, 0x0044e0bfu); return; } } /* jmp dword ptr [edx*4 + 0x44e0c8] */
L_0044e0d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0e0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0ec:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e100:;
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

void f_0044e0ac(CPU *c) { /* PTR_0044e0ac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e0c8u)); switch (t_) { case 0x0044e0d8u: goto L_0044e0d8; case 0x0044e0e0u: goto L_0044e0e0; case 0x0044e0ecu: goto L_0044e0ec; case 0x0044e100u: goto L_0044e100; default: jump_indirect(c, t_, 0x0044e0bfu); return; } } /* jmp dword ptr [edx*4 + 0x44e0c8] */
L_0044e0d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0e0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0ec:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e100:;
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

void f_0044e0bf(CPU *c) { /* PTR_0044e0bf */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e0c8u)); switch (t_) { case 0x0044e0d8u: goto L_0044e0d8; case 0x0044e0e0u: goto L_0044e0e0; case 0x0044e0ecu: goto L_0044e0ec; case 0x0044e100u: goto L_0044e100; default: jump_indirect(c, t_, 0x0044e0bfu); return; } } /* jmp dword ptr [edx*4 + 0x44e0c8] */
L_0044e0d8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0e0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e0ec:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e100:;
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

void f_0044e0d8(CPU *c) { /* PTR_0044e0d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e0e0(CPU *c) { /* PTR_0044e0e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e0ec(CPU *c) { /* PTR_0044e0ec */
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

void f_0044e100(CPU *c) { /* PTR_0044e100 */
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

void f_0044e140(CPU *c) { /* PTR_0044e140 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x44e210u)); switch (t_) { case 0x0044e257u: goto L_0044e257; default: jump_indirect(c, t_, 0x0044e142u); return; } } /* jmp dword ptr [ecx*4 + 0x44e210] */
L_0044e257:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e178(CPU *c) { /* PTR_0044e178 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_0044e140(c); return; } /* jb 0x44e140 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e18eu); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e198(CPU *c) { /* PTR_0044e198 */
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
    if (c->cf) { f_0044e140(c); return; } /* jb 0x44e140 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e1b8u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e1c0(CPU *c) { /* PTR_0044e1c0 */
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
    if (c->cf) { f_0044e140(c); return; } /* jb 0x44e140 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e1eau); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e214(CPU *c) { /* PTR_0044e214 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e21c(CPU *c) { /* PTR_0044e21c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e224(CPU *c) { /* PTR_0044e224 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e22c(CPU *c) { /* PTR_0044e22c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e234(CPU *c) { /* PTR_0044e234 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e23c(CPU *c) { /* PTR_0044e23c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e244(CPU *c) { /* PTR_0044e244 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e257(CPU *c) { /* PTR_0044e257 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x44e260u)); switch (t_) { case 0x0044e270u: goto L_0044e270; case 0x0044e278u: goto L_0044e278; case 0x0044e288u: goto L_0044e288; case 0x0044e29cu: goto L_0044e29c; default: jump_indirect(c, t_, 0x0044e257u); return; } } /* jmp dword ptr [edx*4 + 0x44e260] */
L_0044e270:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044e29c:;
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

void f_0044e270(CPU *c) { /* PTR_0044e270 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e278(CPU *c) { /* PTR_0044e278 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e288(CPU *c) { /* PTR_0044e288 */
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

void f_0044e29c(CPU *c) { /* PTR_0044e29c */
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

void f_0044e2c0(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_0044e30c; /* jne 0x44e30c */
L_0044e2d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0044e300; /* je 0x44e300 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_0044e300; /* je 0x44e300 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0044e300; /* je 0x44e300 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_0044e2d0; /* jne 0x44e2d0 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_0044e300:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_0044e304:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_0044e30c:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_0044e328; /* je 0x44e328 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0044e300; /* je 0x44e300 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_0044e2d0; /* je 0x44e2d0 */
L_0044e328:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0044e300; /* je 0x44e300 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_0044e304; /* jne 0x44e304 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_0044e300; /* je 0x44e300 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_0044e2d0; /* jmp 0x44e2d0 */
}

void f_0044e344(CPU *c) { /* FUN_0044e344 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044e358u); f_0044dd70(c); /* call 0x44dd70 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->cf) goto L_0044e37f; /* jb 0x44e37f */
    (void)sub8(c, R8((uint32_t)(c->ebx + 0x1u)), (uint8_t)0x3au); /* cmp byte ptr [ebx + 1], 0x3a */
    if (!c->zf) goto L_0044e37f; /* jne 0x44e37f */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0044e37b; /* je 0x44e37b */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044e374u); f_00451408(c); /* call 0x451408 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->esi + 0x2u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 2], 0 */
L_0044e37b:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_0044e389; /* jmp 0x44e389 */
L_0044e37f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e389; /* je 0x44e389 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
L_0044e389:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->esi = (uint32_t)((uint32_t)0xffu); /* mov esi, 0xff */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    if (c->zf) goto L_0044e401; /* je 0x44e401 */
L_0044e39c:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x47c7e1u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x47c7e1], 4 */
    if (c->zf) goto L_0044e3ad; /* je 0x44e3ad */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_0044e3c7; /* jmp 0x44e3c7 */
L_0044e3ad:;
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x2fu); /* cmp cl, 0x2f */
    if (c->zf) goto L_0044e3c1; /* je 0x44e3c1 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x5cu); /* cmp cl, 0x5c */
    if (c->zf) goto L_0044e3c1; /* je 0x44e3c1 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x2eu); /* cmp cl, 0x2e */
    if (!c->zf) goto L_0044e3c7; /* jne 0x44e3c7 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    goto L_0044e3c7; /* jmp 0x44e3c7 */
L_0044e3c1:;
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0xc], ecx */
L_0044e3c7:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_0044e39c; /* jne 0x44e39c */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044e401; /* je 0x44e401 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x10], 0 */
    if (c->zf) goto L_0044e3fc; /* je 0x44e3fc */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ebx)); /* sub edi, ebx */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if (c->cf) goto L_0044e3e5; /* jb 0x44e3e5 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
L_0044e3e5:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x0044e3efu); f_00451408(c); /* call 0x451408 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->edi + c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [edi + eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
L_0044e3fc:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    goto L_0044e40b; /* jmp 0x44e40b */
L_0044e401:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0044e40b; /* je 0x44e40b */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ecx], 0 */
L_0044e40b:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044e45e; /* je 0x44e45e */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->cf) goto L_0044e45e; /* jb 0x44e45e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_0044e43b; /* je 0x44e43b */
    c->edi = (uint32_t)(sub32(c, c->edi, c->ebx)); /* sub edi, ebx */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if (c->cf) goto L_0044e424; /* jb 0x44e424 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
L_0044e424:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    PUSH32(c, 0x0044e42eu); f_00451408(c); /* call 0x451408 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->edi + c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [edi + eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
L_0044e43b:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edi, dword ptr [ebp + 0x18] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044e486; /* je 0x44e486 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu)))); /* sub eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_0044e44b; /* jae 0x44e44b */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_0044e44b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044e455u); f_00451408(c); /* call 0x451408 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->esi + c->edi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + edi], 0 */
    goto L_0044e486; /* jmp 0x44e486 */
L_0044e45e:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044e47c; /* je 0x44e47c */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_0044e46d; /* jae 0x44e46d */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_0044e46d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044e475u); f_00451408(c); /* call 0x451408 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->esi + c->edi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + edi], 0 */
L_0044e47c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e486; /* je 0x44e486 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
L_0044e486:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e48b(CPU *c) { /* FUN_0044e48b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_0044e490:;
    (void)sub32(c, R32((uint32_t)(0x46cf18u)), (uint32_t)0x1u); /* cmp dword ptr [0x46cf18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0044e4a8; /* jle 0x44e4a8 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044e4a4u); f_00451523(c); /* call 0x451523 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044e4b7; /* jmp 0x44e4b7 */
L_0044e4a8:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov ecx, dword ptr [0x46cd0c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_0044e4b7:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e4be; /* je 0x44e4be */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_0044e490; /* jmp 0x44e490 */
L_0044e4be:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044e4c8u); f_0044dd70(c); /* call 0x44dd70 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044e4d0u); f_00451492(c); /* call 0x451492 */
    FPUSH(c, RF64((uint32_t)(c->eax + 0x10u))); /* fld qword ptr [eax + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0044e4d8(CPU *c) { /* FUN_0044e4d8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
L_0044e4e0:;
    (void)sub32(c, R32((uint32_t)(0x46cf18u)), (uint32_t)0x1u); /* cmp dword ptr [0x46cf18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0044e4f8; /* jle 0x44e4f8 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044e4f4u); f_00451523(c); /* call 0x451523 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044e507; /* jmp 0x44e507 */
L_0044e4f8:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov ecx, dword ptr [0x46cd0c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_0044e507:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e50e; /* je 0x44e50e */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_0044e4e0; /* jmp 0x44e4e0 */
L_0044e50e:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->esi, (uint32_t)0x2du); /* cmp esi, 0x2d */
    c->ebp = (uint32_t)(c->esi); /* mov ebp, esi */
    if (c->zf) goto L_0044e51e; /* je 0x44e51e */
    (void)sub32(c, c->esi, (uint32_t)0x2bu); /* cmp esi, 0x2b */
    if (!c->zf) goto L_0044e522; /* jne 0x44e522 */
L_0044e51e:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_0044e522:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_0044e524:;
    (void)sub32(c, R32((uint32_t)(0x46cf18u)), (uint32_t)0x1u); /* cmp dword ptr [0x46cf18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0044e539; /* jle 0x44e539 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044e535u); f_00451523(c); /* call 0x451523 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044e544; /* jmp 0x44e544 */
L_0044e539:;
    c->eax = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov eax, dword ptr [0x46cd0c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_0044e544:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e555; /* je 0x44e555 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->eax * 2 + 0xffffffd0u)); /* lea ebx, [esi + eax*2 - 0x30] */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_0044e524; /* jmp 0x44e524 */
L_0044e555:;
    (void)sub32(c, c->ebp, (uint32_t)0x2du); /* cmp ebp, 0x2d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (!c->zf) goto L_0044e55e; /* jne 0x44e55e */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_0044e55e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_0044e563(CPU *c) { /* FUN_0044e563 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0044e56cu); f_0044e4d8(c); /* call 0x44e4d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044e56e(CPU *c) { /* PTR_0044e56e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edi, dword ptr [esp + 0x18] */
L_0044e577:;
    (void)sub32(c, R32((uint32_t)(0x46cf18u)), (uint32_t)0x1u); /* cmp dword ptr [0x46cf18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0044e58f; /* jle 0x44e58f */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044e58bu); f_00451523(c); /* call 0x451523 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044e59e; /* jmp 0x44e59e */
L_0044e58f:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov ecx, dword ptr [0x46cd0c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_0044e59e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e5a5; /* je 0x44e5a5 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_0044e577; /* jmp 0x44e577 */
L_0044e5a5:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->esi, (uint32_t)0x2du); /* cmp esi, 0x2d */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    if (c->zf) goto L_0044e5b7; /* je 0x44e5b7 */
    (void)sub32(c, c->esi, (uint32_t)0x2bu); /* cmp esi, 0x2b */
    if (!c->zf) goto L_0044e5bb; /* jne 0x44e5bb */
L_0044e5b7:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_0044e5bb:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_0044e5bf:;
    (void)sub32(c, R32((uint32_t)(0x46cf18u)), (uint32_t)0x1u); /* cmp dword ptr [0x46cf18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0044e5d4; /* jle 0x44e5d4 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044e5d0u); f_00451523(c); /* call 0x451523 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044e5df; /* jmp 0x44e5df */
L_0044e5d4:;
    c->eax = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov eax, dword ptr [0x46cd0c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_0044e5df:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e60c; /* je 0x44e60c */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffd0u)); /* lea eax, [esi - 0x30] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x24], esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    PUSH32(c, 0x0044e5fau); f_004515a0(c); /* call 0x4515a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->esi = (uint32_t)(adc32(c, c->esi, c->edx)); /* adc esi, edx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ebp = (uint32_t)(c->esi); /* mov ebp, esi */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_0044e5bf; /* jmp 0x44e5bf */
L_0044e60c:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0x10u)), (uint32_t)0x2du); /* cmp dword ptr [esp + 0x10], 0x2d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (!c->zf) goto L_0044e620; /* jne 0x44e620 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(c->ebp); /* mov edx, ebp */
    c->edx = (uint32_t)(adc32(c, c->edx, (uint32_t)0x0u)); /* adc edx, 0 */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    goto L_0044e622; /* jmp 0x44e622 */
L_0044e620:;
    c->edx = (uint32_t)(c->ebp); /* mov edx, ebp */
L_0044e622:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044e628(CPU *c) { /* FUN_0044e628 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x0044e62du); f_0044e640(c); /* call 0x44e640 */
    PUSH32(c, 0x0044e632u); f_00451624(c); /* call 0x451624 */
    W32((uint32_t)(0x47c33cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c33c], eax */
    PUSH32(c, 0x0044e63cu); f_004515d4(c); /* call 0x4515d4 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_0044e63f(CPU *c) { /* PTR_0044e63f */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_0044e640(CPU *c) { /* FUN_0044e640 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x451a12u); /* mov eax, 0x451a12 */
    W32((uint32_t)(0x46cf34u), (uint32_t)((uint32_t)0x4516a7u)); /* mov dword ptr [0x46cf34], 0x4516a7 */
    W32((uint32_t)(0x46cf30u), (uint32_t)(c->eax)); /* mov dword ptr [0x46cf30], eax */
    W32((uint32_t)(0x46cf38u), (uint32_t)((uint32_t)0x45170du)); /* mov dword ptr [0x46cf38], 0x45170d */
    W32((uint32_t)(0x46cf3cu), (uint32_t)((uint32_t)0x45164du)); /* mov dword ptr [0x46cf3c], 0x45164d */
    W32((uint32_t)(0x46cf40u), (uint32_t)((uint32_t)0x4516f5u)); /* mov dword ptr [0x46cf40], 0x4516f5 */
    W32((uint32_t)(0x46cf44u), (uint32_t)(c->eax)); /* mov dword ptr [0x46cf44], eax */
    c->esp += 4; return; /* ret  */
}

void f_0044e678(CPU *c) { /* PTR_0044e678 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c338u))); /* mov eax, dword ptr [0x47c338] */
    W32((uint32_t)(0x47c338u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c338], ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044e688(CPU *c) { /* FUN_0044e688 */
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
    PUSH32(c, 0x0044e6b6u); f_0045080e(c); /* call 0x45080e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_0044e6c8; /* js 0x44e6c8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_0044e6d5; /* jmp 0x44e6d5 */
L_0044e6c8:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x0044e6d3u); f_004506f9(c); /* call 0x4506f9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0044e6d5:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e6e0(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0044e763; /* je 0x44e763 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_0044e704; /* jne 0x44e704 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_0044e771; /* jne 0x44e771 */
    goto L_0044e725; /* jmp 0x44e725 */
L_0044e704:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0044e732; /* je 0x44e732 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0044e73a; /* je 0x44e73a */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_0044e704; /* jne 0x44e704 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_0044e771; /* jne 0x44e771 */
L_0044e720:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_0044e732; /* je 0x44e732 */
L_0044e725:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0044e75e; /* je 0x44e75e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_0044e725; /* jne 0x44e725 */
L_0044e732:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0044e73a:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_0044e754; /* je 0x44e754 */
L_0044e742:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0044e7d6; /* je 0x44e7d6 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_0044e742; /* jne 0x44e742 */
L_0044e754:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_0044e7c7; /* jne 0x44e7c7 */
L_0044e75b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_0044e75e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_0044e75b; /* jne 0x44e75b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044e763:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0044e769:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0044e720; /* je 0x44e720 */
L_0044e771:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_0044e769; /* je 0x44e769 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0044e7bb; /* je 0x44e7bb */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_0044e7b1; /* je 0x44e7b1 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_0044e7a7; /* je 0x44e7a7 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_0044e769; /* jne 0x44e769 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_0044e7bf; /* jmp 0x44e7bf */
L_0044e7a7:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_0044e7bf; /* jmp 0x44e7bf */
L_0044e7b1:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_0044e7bf; /* jmp 0x44e7bf */
L_0044e7bb:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_0044e7bf:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0044e7d1; /* je 0x44e7d1 */
L_0044e7c7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0044e7c9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0044e7c9; /* jne 0x44e7c9 */
L_0044e7d1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_0044e75b; /* jne 0x44e75b */
L_0044e7d6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_0044e7de(CPU *c) { /* FUN_0044e7de */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x47c6b8u)); PUSH32(c, v_); } /* push dword ptr [0x47c6b8] */
    PUSH32(c, 0x0044e7eau); f_00451ba8(c); /* call 0x451ba8 */
    c->edx = (uint32_t)(R32((uint32_t)(0x47c6b8u))); /* mov edx, dword ptr [0x47c6b8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c6b4u))); /* mov ecx, dword ptr [0x47c6b4] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->cf) goto L_0044e83d; /* jae 0x44e83d */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0044e809u); f_00451ba8(c); /* call 0x451ba8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x47c6b8u)); PUSH32(c, v_); } /* push dword ptr [0x47c6b8] */
    PUSH32(c, 0x0044e818u); f_0044f6e8(c); /* call 0x44f6e8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0044e820; /* jne 0x44e820 */
    c->esp += 4; return; /* ret  */
L_0044e820:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c6b4u))); /* mov ecx, dword ptr [0x47c6b4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x47c6b8u)))); /* sub ecx, dword ptr [0x47c6b8] */
    W32((uint32_t)(0x47c6b8u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6b8], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x47c6b4u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c6b4], ecx */
L_0044e83d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x47c6b4u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x47c6b4], 4 */
    c->esp += 4; return; /* ret  */
}

void f_0044e84b(CPU *c) { /* FUN_0044e84b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0044e854u); f_0044e7de(c); /* call 0x44e7de */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_0044e85d(CPU *c) { /* PTR_0044e85d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x0044e867u); f_0044f636(c); /* call 0x44f636 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c6b8u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6b8], eax */
    if (!c->zf) goto L_0044e87e; /* jne 0x44e87e */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x0044e878u); f_0044fa7e(c); /* call 0x44fa7e */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6b8u))); /* mov eax, dword ptr [0x47c6b8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0044e87e:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6b8u))); /* mov eax, dword ptr [0x47c6b8] */
    W32((uint32_t)(0x47c6b4u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6b4], eax */
    c->esp += 4; return; /* ret  */
}

void f_0044e88c(CPU *c) { /* __ftol */
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

void f_0044e8c0(CPU *c) { /* _memcmp */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e90c; /* je 0x44e90c */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->edi))); /* or edx, edi */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    if (c->zf) goto L_0044e90d; /* je 0x44e90d */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u)); /* test eax, 1 */
    if (c->zf) goto L_0044e8ed; /* je 0x44e8ed */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->ecx), R8((uint32_t)(c->edi))); /* cmp cl, byte ptr [edi] */
    if (!c->zf) goto L_0044e93a; /* jne 0x44e93a */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0044e90a; /* je 0x44e90a */
L_0044e8ed:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov dl, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (!c->zf) goto L_0044e93a; /* jne 0x44e93a */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov cl, byte ptr [esi + 1] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0x1u))); /* mov dl, byte ptr [edi + 1] */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (!c->zf) goto L_0044e93a; /* jne 0x44e93a */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x2u)); /* add edi, 2 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2u)); /* sub eax, 2 */
    if (!c->zf) goto L_0044e8ed; /* jne 0x44e8ed */
L_0044e90a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044e90c:;
    c->esp += 4; return; /* ret  */
L_0044e90d:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_0044e942; /* je 0x44e942 */
    while (c->ecx) { (void)sub32(c, R32(c->esi), R32(c->edi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; if (!c->zf) break; } /* repe cmpsd dword ptr [esi], dword ptr es:[edi] */
    if (c->zf) goto L_0044e942; /* je 0x44e942 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov ecx, dword ptr [esi - 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0xfffffffcu))); /* mov edx, dword ptr [edi - 4] */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (!c->zf) goto L_0044e935; /* jne 0x44e935 */
    (void)sub8(c, ((uint8_t)(c->ecx >> 8)), ((uint8_t)(c->edx >> 8))); /* cmp ch, dh */
    if (!c->zf) goto L_0044e935; /* jne 0x44e935 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 16)); /* shr ecx, 0x10 */
    c->edx = (uint32_t)(shr32(c, c->edx, 16)); /* shr edx, 0x10 */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (!c->zf) goto L_0044e935; /* jne 0x44e935 */
    (void)sub8(c, ((uint8_t)(c->ecx >> 8)), ((uint8_t)(c->edx >> 8))); /* cmp ch, dh */
L_0044e935:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
L_0044e93a:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0044e942:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044e90a; /* je 0x44e90a */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    (void)sub8(c, ((uint8_t)c->edx), ((uint8_t)c->ecx)); /* cmp dl, cl */
    if (!c->zf) goto L_0044e935; /* jne 0x44e935 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0044e969; /* je 0x44e969 */
    (void)sub8(c, ((uint8_t)(c->edx >> 8)), ((uint8_t)(c->ecx >> 8))); /* cmp dh, ch */
    if (!c->zf) goto L_0044e935; /* jne 0x44e935 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0044e969; /* je 0x44e969 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xff0000u))); /* and ecx, 0xff0000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u))); /* and edx, 0xff0000 */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    if (!c->zf) goto L_0044e935; /* jne 0x44e935 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_0044e969:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0044e96c(CPU *c) { /* PTR_0044e96c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x0044e973u); f_0044fa7e(c); /* call 0x44fa7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044e975(CPU *c) { /* __copysign */
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

void f_0044e996(CPU *c) { /* FUN_0044e996 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)~c->eax); /* not eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ R32((uint32_t)(c->ebp + 0xcu))))); /* xor ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7fffffffu))); /* and ecx, 0x7fffffff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->eax))); /* xor ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044e9bb(CPU *c) { /* PTR_0044e9bb */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->esp + 0x8u))); /* fld qword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044e9cdu); f_00451c09(c); /* call 0x451c09 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_0044e9d1(CPU *c) { /* FUN_0044e9d1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xffffu); /* mov esi, 0xffff */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x133fu; PUSH32(c, v_); } /* push 0x133f */
    PUSH32(c, 0x0044e9e7u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044ea58; /* jne 0x44ea58 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044ea05u); f_00451e7c(c); /* call 0x451e7c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_0044ea3b; /* jle 0x44ea3b */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if ((c->zf || c->sf != c->of)) goto L_0044ea2d; /* jle 0x44ea2d */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0044ea3b; /* jne 0x44ea3b */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x25u; PUSH32(c, v_); } /* push 0x25 */
    PUSH32(c, 0x0044ea25u); f_00451f97(c); /* call 0x451f97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_0044eab4; /* jmp 0x44eab4 */
L_0044ea2d:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044ea34u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044eab4; /* jmp 0x44eab4 */
L_0044ea3b:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x45bc48u))); /* fadd qword ptr [0x45bc48] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x25u; PUSH32(c, v_); } /* push 0x25 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_0044ea7d; /* jmp 0x44ea7d */
L_0044ea58:;
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_0044ea87; /* jne 0x44ea87 */
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(0) = -ST(0); /* fchs  */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x25u; PUSH32(c, v_); } /* push 0x25 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
L_0044ea7d:;
    PUSH32(c, 0x0044ea82u); f_00452049(c); /* call 0x452049 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    goto L_0044eab4; /* jmp 0x44eab4 */
L_0044ea87:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044ea98u); f_00451ed6(c); /* call 0x451ed6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0xcu))); /* fild dword ptr [ebp + 0xc] */
    WF64((uint32_t)(c->ebp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 8] */
    PUSH32(c, 0x0044eaaeu); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_0044eab4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044eab8(CPU *c) { /* FUN_0044eab8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xffffu); /* mov esi, 0xffff */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x133fu; PUSH32(c, v_); } /* push 0x133f */
    PUSH32(c, 0x0044ead1u); f_0045276d(c); /* call 0x45276d */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov edi, dword ptr [ebp + 0xe] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->ecx = (uint32_t)((uint32_t)0x7ff0u); /* mov ecx, 0x7ff0 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->ecx)))); /* and ax, cx */
    (void)sub16(c, ((uint16_t)c->eax), ((uint16_t)c->ecx)); /* cmp ax, cx */
    if (c->zf) goto L_0044eaf6; /* je 0x44eaf6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x16u))); /* mov eax, dword ptr [ebp + 0x16] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->ecx)))); /* and ax, cx */
    (void)sub16(c, ((uint16_t)c->eax), ((uint16_t)c->ecx)); /* cmp ax, cx */
    if (!c->zf) goto L_0044eb63; /* jne 0x44eb63 */
L_0044eaf6:;
    c->eax = (uint32_t)((uint32_t)0x7ff8u); /* mov eax, 0x7ff8 */
    c->ebx = (uint32_t)((uint32_t)0x7ffffu); /* mov ebx, 0x7ffff */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->eax))); /* and edi, eax */
    (void)sub16(c, ((uint16_t)c->edi), ((uint16_t)c->ecx)); /* cmp di, cx */
    if (!c->zf) goto L_0044eb10; /* jne 0x44eb10 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & c->ebx)); /* test dword ptr [ebp + 0xc], ebx */
    if (!c->zf) goto L_0044eb25; /* jne 0x44eb25 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_0044eb25; /* jne 0x44eb25 */
L_0044eb10:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x16u))); /* mov esi, dword ptr [ebp + 0x16] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & c->eax))); /* and esi, eax */
    (void)sub16(c, ((uint16_t)c->esi), ((uint16_t)c->ecx)); /* cmp si, cx */
    if (!c->zf) goto L_0044eb4c; /* jne 0x44eb4c */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0x14u)) & c->ebx)); /* test dword ptr [ebp + 0x14], ebx */
    if (!c->zf) goto L_0044eb25; /* jne 0x44eb25 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x10], 0 */
    if (c->zf) goto L_0044eb4c; /* je 0x44eb4c */
L_0044eb25:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->ebp + 0x10u))); /* fadd qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x26u; PUSH32(c, v_); } /* push 0x26 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_0044ed11; /* jmp 0x44ed11 */
L_0044eb4c:;
    (void)sub16(c, ((uint16_t)c->edi), ((uint16_t)c->eax)); /* cmp di, ax */
    if (c->zf) goto L_0044ed2b; /* je 0x44ed2b */
    (void)sub16(c, ((uint16_t)c->esi), ((uint16_t)c->eax)); /* cmp si, ax */
    if (c->zf) goto L_0044ed2b; /* je 0x44ed2b */
    c->esi = (uint32_t)((uint32_t)0xffffu); /* mov esi, 0xffff */
L_0044eb63:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_0044eb81; /* jne 0x44eb81 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x0044eb77u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044ed48; /* jmp 0x44ed48 */
L_0044eb81:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_0044ebae; /* jne 0x44ebae */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_0044eba7; /* jbe 0x44eba7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x18], 0 */
    goto L_0044ebae; /* jmp 0x44ebae */
L_0044eba7:;
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)((uint32_t)0x80000000u)); /* mov dword ptr [ebp - 0x18], 0x80000000 */
L_0044ebae:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_0044ebc7; /* jbe 0x44ebc7 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_0044ebe0; /* jb 0x44ebe0 */
L_0044ebc7:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_0044ebf3; /* jae 0x44ebf3 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_0044ebf3; /* jbe 0x44ebf3 */
L_0044ebe0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea edi, [edx - 1] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x1c], edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    if (!c->zf) goto L_0044ec3e; /* jne 0x44ec3e */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_0044ec36; /* jmp 0x44ec36 */
L_0044ebf3:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_0044ec0c; /* jbe 0x44ec0c */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_0044ec25; /* ja 0x44ec25 */
L_0044ec0c:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_0044ec3b; /* jae 0x44ec3b */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_0044ec3b; /* jae 0x44ec3b */
L_0044ec25:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->edx + 0x1u)); /* lea edi, [edx + 1] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x1c], edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    if (!c->zf) goto L_0044ec3e; /* jne 0x44ec3e */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_0044ec36:;
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    goto L_0044ec3e; /* jmp 0x44ec3e */
L_0044ec3b:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
L_0044ec3e:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffeau)) & ((uint16_t)c->ecx))); /* test word ptr [ebp - 0x16], cx */
    if (!c->zf) goto L_0044eca5; /* jne 0x44eca5 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp - 0x18], 0xfffff */
    if (!c->zf) goto L_0044ec51; /* jne 0x44ec51 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044eca5; /* je 0x44eca5 */
L_0044ec51:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe4u))); /* fld qword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044ec62u); f_00451ed6(c); /* call 0x451ed6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x600u)); /* add eax, 0x600 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044ec7eu); f_00451def(c); /* call 0x451def */
    WF64((uint32_t)(c->ebp + 0xffffffe4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x1c] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe4u))); /* fld qword ptr [ebp - 0x1c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x26u; PUSH32(c, v_); } /* push 0x26 */
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    goto L_0044ed11; /* jmp 0x44ed11 */
L_0044eca5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), (uint32_t)0x7ff00000u); /* cmp dword ptr [ebp - 0x18], 0x7ff00000 */
    if (!c->zf) goto L_0044ecb2; /* jne 0x44ecb2 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044ecbf; /* je 0x44ecbf */
L_0044ecb2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), (uint32_t)0xfff00000u); /* cmp dword ptr [ebp - 0x18], 0xfff00000 */
    if (!c->zf) goto L_0044ed1b; /* jne 0x44ed1b */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_0044ed1b; /* jne 0x44ed1b */
L_0044ecbf:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe4u))); /* fld qword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044ecd0u); f_00451ed6(c); /* call 0x451ed6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffa00u)); /* add eax, 0xfffffa00 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044ececu); f_00451def(c); /* call 0x451def */
    WF64((uint32_t)(c->ebp + 0xffffffe4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x1c] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe4u))); /* fld qword ptr [ebp - 0x1c] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x26u; PUSH32(c, v_); } /* push 0x26 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
L_0044ed11:;
    PUSH32(c, 0x0044ed16u); f_004520e1(c); /* call 0x4520e1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    goto L_0044ed48; /* jmp 0x44ed48 */
L_0044ed1b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x0044ed24u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe4u))); /* fld qword ptr [ebp - 0x1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044ed48; /* jmp 0x44ed48 */
L_0044ed2b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x26u; PUSH32(c, v_); } /* push 0x26 */
    PUSH32(c, 0x0044ed45u); f_00451fea(c); /* call 0x451fea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0044ed48:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044ed4d(CPU *c) { /* PTR_0044ed4d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xau))); /* mov eax, dword ptr [esp + 0xa] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne cl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044ed61(CPU *c) { /* FUN_0044ed61 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xau))); /* mov eax, dword ptr [esp + 0xa] */
    c->ecx = (uint32_t)((uint32_t)0x7ff8u); /* mov ecx, 0x7ff8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (!c->zf) goto L_0044ed83; /* jne 0x44ed83 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esp + 0x8u)) & (uint32_t)0x7ffffu)); /* test dword ptr [esp + 8], 0x7ffff */
    if (!c->zf) goto L_0044ed88; /* jne 0x44ed88 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 4], 0 */
    if (!c->zf) goto L_0044ed88; /* jne 0x44ed88 */
L_0044ed83:;
    (void)sub16(c, ((uint16_t)c->eax), ((uint16_t)c->ecx)); /* cmp ax, cx */
    if (!c->zf) goto L_0044ed8c; /* jne 0x44ed8c */
L_0044ed88:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_0044ed8c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_0044ed8f(CPU *c) { /* FUN_0044ed8f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->ecx = (uint32_t)((uint32_t)0x7ff0u); /* mov ecx, 0x7ff0 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->ecx)); /* cmp dx, cx */
    if (!c->zf) goto L_0044edcf; /* jne 0x44edcf */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044edb0u); f_00451e7c(c); /* call 0x451e7c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0044edc8; /* je 0x44edc8 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0044edc4; /* je 0x44edc4 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0044edc0; /* je 0x44edc0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_0044edbd:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_0044edc0:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_0044edbd; /* jmp 0x44edbd */
L_0044edc4:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    goto L_0044edbd; /* jmp 0x44edbd */
L_0044edc8:;
    c->eax = (uint32_t)((uint32_t)0x200u); /* mov eax, 0x200 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_0044edcf:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (!c->zf) goto L_0044edf9; /* jne 0x44edf9 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp + 0xc], 0xfffff */
    if (!c->zf) goto L_0044edea; /* jne 0x44edea */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_0044edf9; /* je 0x44edf9 */
L_0044edea:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x90u))); /* and al, 0x90 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x80u)); /* add eax, 0x80 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_0044edf9:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    if (!c->zf) goto L_0044ee14; /* jne 0x44ee14 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xe0u))); /* and al, 0xe0 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x40u)); /* add eax, 0x40 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_0044ee14:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u))); /* and al, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x100u)); /* add eax, 0x100 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0044ee21(CPU *c) { /* FUN_0044ee21 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xffffu); /* mov esi, 0xffff */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x46c900u)); PUSH32(c, v_); } /* push dword ptr [0x46c900] */
    PUSH32(c, 0x0044ee39u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    if (!c->zf) goto L_0044eea7; /* jne 0x44eea7 */
    PUSH32(c, 0x0044ee57u); f_00451e7c(c); /* call 0x451e7c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_0044ee8a; /* jle 0x44ee8a */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if ((c->zf || c->sf != c->of)) goto L_0044ee7c; /* jle 0x44ee7c */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0044ee8a; /* jne 0x44ee8a */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0044ee77u); f_00451f97(c); /* call 0x451f97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_0044eeec; /* jmp 0x44eeec */
L_0044ee7c:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044ee83u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044eeec; /* jmp 0x44eeec */
L_0044ee8a:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x45bc48u))); /* fadd qword ptr [0x45bc48] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_0044eee4; /* jmp 0x44eee4 */
L_0044eea7:;
    PUSH32(c, 0x0044eeacu); f_004527e6(c); /* call 0x4527e6 */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_0044eeca; /* jne 0x44eeca */
L_0044eebc:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044eec3u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044eeec; /* jmp 0x44eeec */
L_0044eeca:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x20u)); /* test bl, 0x20 */
    if (!c->zf) goto L_0044eebc; /* jne 0x44eebc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
L_0044eee4:;
    PUSH32(c, 0x0044eee9u); f_00452049(c); /* call 0x452049 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
L_0044eeec:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044eef0(CPU *c) { /* FUN_0044eef0 */
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
    PUSH32(c, 0x0044ef1du); f_0045080e(c); /* call 0x45080e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_0044ef2f; /* js 0x44ef2f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_0044ef3c; /* jmp 0x44ef3c */
L_0044ef2f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x0044ef3au); f_004506f9(c); /* call 0x4506f9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0044ef3c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044ef50(CPU *c) { /* PTR_0044ef50 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)0x46d060u); /* mov edx, 0x46d060 */
    { f_00452924(c); return; } /* jmp 0x452924 */
}

void f_0044ef70(CPU *c) { /* FUN_0044ef70 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x0044ef7bu); f_00452d58(c); /* call 0x452d58 */
    PUSH32(c, 0x0044ef80u); f_0044ef8d(c); /* call 0x44ef8d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0044ef84(CPU *c) { /* FUN_0044ef84 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    PUSH32(c, 0x0044ef8du); f_00452d15(c); /* call 0x452d15 */
    { f_0044ef8d(c); return; }
}

void f_0044ef8d(CPU *c) { /* FUN_0044ef8d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_0044efca; /* je 0x44efca */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044efa2; /* je 0x44efa2 */
    c->fpu_cw = R16((uint32_t)(0x45be88u)); fpu_sync_rounding(c); /* fldcw word ptr [0x45be88] */
L_0044efa2:;
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = atan2(ST(1), ST(0)); FPOP(c); /* fpatan  */
L_0044efa6:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0xfu); /* mov edx, 0xf */
    c->ecx = (uint32_t)((uint32_t)(0x46c910u)); /* lea ecx, [0x46c910] */
    { f_00452d7b(c); return; } /* jmp 0x452d7b */
L_0044efc3:;
    PUSH32(c, 0x0044efc8u); f_00452cfc(c); /* call 0x452cfc */
    goto L_0044eff0; /* jmp 0x44eff0 */
L_0044efca:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044efc3; /* jne 0x44efc3 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044efc3; /* jne 0x44efc3 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0bau))); /* fld xword ptr [0x46d0ba] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000000u)); /* test eax, 0x80000000 */
    if (c->zf) goto L_0044efa6; /* je 0x44efa6 */
    ST(0) = -ST(0); /* fchs  */
    goto L_0044efa6; /* jmp 0x44efa6 */
L_0044eff0:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0xfu); /* mov edx, 0xf */
    c->ecx = (uint32_t)((uint32_t)(0x46c910u)); /* lea ecx, [0x46c910] */
    PUSH32(c, 0x0044f00du); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f010(CPU *c) { /* PTR_0044f010 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x0044f01bu); f_00452d58(c); /* call 0x452d58 */
    PUSH32(c, 0x0044f020u); f_0044f02d(c); /* call 0x44f02d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0044f024(CPU *c) { /* FUN_0044f024 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    PUSH32(c, 0x0044f02du); f_00452d15(c); /* call 0x452d15 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_0044f088; /* je 0x44f088 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044f042; /* je 0x44f042 */
    c->fpu_cw = R16((uint32_t)(0x45be88u)); fpu_sync_rounding(c); /* fldcw word ptr [0x45be88] */
L_0044f042:;
    { double v_ = ST(0); if (fabs(v_) >= 9223372036854775808.0) c->fpu_sw |= 0x0400; else { c->fpu_sw &= ~0x0400; ST(0) = tan(v_); FPUSH(c, 1.0); } } /* fptan  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f069; /* jp 0x44f069 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_0044f04c:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x20u); /* mov edx, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(0x46c920u)); /* lea ecx, [0x46c920] */
    { f_00452d7b(c); return; } /* jmp 0x452d7b */
L_0044f069:;
    FPUSH(c, RF80((uint32_t)(0x45be8au))); /* fld xword ptr [0x45be8a] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_0044f071:;
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f071; /* jp 0x44f071 */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); if (fabs(v_) >= 9223372036854775808.0) c->fpu_sw |= 0x0400; else { c->fpu_sw &= ~0x0400; ST(0) = tan(v_); FPUSH(c, 1.0); } } /* fptan  */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    goto L_0044f04c; /* jmp 0x44f04c */
L_0044f081:;
    PUSH32(c, 0x0044f086u); f_00452cfc(c); /* call 0x452cfc */
    goto L_0044f0a3; /* jmp 0x44f0a3 */
L_0044f088:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044f081; /* jne 0x44f081 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044f081; /* jne 0x44f081 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0044f0a3:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x20u); /* mov edx, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(0x46c920u)); /* lea ecx, [0x46c920] */
    PUSH32(c, 0x0044f0c0u); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f02d(CPU *c) { /* PTR_0044f02d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_0044f088; /* je 0x44f088 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044f042; /* je 0x44f042 */
    c->fpu_cw = R16((uint32_t)(0x45be88u)); fpu_sync_rounding(c); /* fldcw word ptr [0x45be88] */
L_0044f042:;
    { double v_ = ST(0); if (fabs(v_) >= 9223372036854775808.0) c->fpu_sw |= 0x0400; else { c->fpu_sw &= ~0x0400; ST(0) = tan(v_); FPUSH(c, 1.0); } } /* fptan  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f069; /* jp 0x44f069 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_0044f04c:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x20u); /* mov edx, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(0x46c920u)); /* lea ecx, [0x46c920] */
    { f_00452d7b(c); return; } /* jmp 0x452d7b */
L_0044f069:;
    FPUSH(c, RF80((uint32_t)(0x45be8au))); /* fld xword ptr [0x45be8a] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_0044f071:;
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f071; /* jp 0x44f071 */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); if (fabs(v_) >= 9223372036854775808.0) c->fpu_sw |= 0x0400; else { c->fpu_sw &= ~0x0400; ST(0) = tan(v_); FPUSH(c, 1.0); } } /* fptan  */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    goto L_0044f04c; /* jmp 0x44f04c */
L_0044f081:;
    PUSH32(c, 0x0044f086u); f_00452cfc(c); /* call 0x452cfc */
    goto L_0044f0a3; /* jmp 0x44f0a3 */
L_0044f088:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044f081; /* jne 0x44f081 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044f081; /* jne 0x44f081 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0044f0a3:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x20u); /* mov edx, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(0x46c920u)); /* lea ecx, [0x46c920] */
    PUSH32(c, 0x0044f0c0u); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f0d0(CPU *c) { /* FUN_0044f0d0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x0044f0dbu); f_00452d58(c); /* call 0x452d58 */
    PUSH32(c, 0x0044f0e0u); f_0044f0ed(c); /* call 0x44f0ed */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0044f0e4(CPU *c) { /* FUN_0044f0e4 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    PUSH32(c, 0x0044f0edu); f_00452d15(c); /* call 0x452d15 */
    { f_0044f0ed(c); return; }
}

void f_0044f0ed(CPU *c) { /* FUN_0044f0ed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_0044f144; /* je 0x44f144 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044f102; /* je 0x44f102 */
    c->fpu_cw = R16((uint32_t)(0x45be88u)); fpu_sync_rounding(c); /* fldcw word ptr [0x45be88] */
L_0044f102:;
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f127; /* jp 0x44f127 */
L_0044f10a:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x12u); /* mov edx, 0x12 */
    c->ecx = (uint32_t)((uint32_t)(0x46c930u)); /* lea ecx, [0x46c930] */
    { f_00452d7b(c); return; } /* jmp 0x452d7b */
L_0044f127:;
    FPUSH(c, RF80((uint32_t)(0x45be8au))); /* fld xword ptr [0x45be8a] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_0044f12f:;
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f12f; /* jp 0x44f12f */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    goto L_0044f10a; /* jmp 0x44f10a */
L_0044f13d:;
    PUSH32(c, 0x0044f142u); f_00452cfc(c); /* call 0x452cfc */
    goto L_0044f15f; /* jmp 0x44f15f */
L_0044f144:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044f13d; /* jne 0x44f13d */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044f13d; /* jne 0x44f13d */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0044f15f:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x12u); /* mov edx, 0x12 */
    c->ecx = (uint32_t)((uint32_t)(0x46c930u)); /* lea ecx, [0x46c930] */
    PUSH32(c, 0x0044f17cu); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f180(CPU *c) { /* FUN_0044f180 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x0044f18bu); f_00452d58(c); /* call 0x452d58 */
    PUSH32(c, 0x0044f190u); f_0044f19d(c); /* call 0x44f19d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0044f194(CPU *c) { /* FUN_0044f194 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    PUSH32(c, 0x0044f19du); f_00452d15(c); /* call 0x452d15 */
    { f_0044f19d(c); return; }
}

void f_0044f19d(CPU *c) { /* FUN_0044f19d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_0044f1f4; /* je 0x44f1f4 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044f1b2; /* je 0x44f1b2 */
    c->fpu_cw = R16((uint32_t)(0x45be88u)); fpu_sync_rounding(c); /* fldcw word ptr [0x45be88] */
L_0044f1b2:;
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f1d7; /* jp 0x44f1d7 */
L_0044f1ba:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x1eu); /* mov edx, 0x1e */
    c->ecx = (uint32_t)((uint32_t)(0x46c940u)); /* lea ecx, [0x46c940] */
    { f_00452d7b(c); return; } /* jmp 0x452d7b */
L_0044f1d7:;
    FPUSH(c, RF80((uint32_t)(0x45be8au))); /* fld xword ptr [0x45be8a] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_0044f1df:;
    ST(0) = remainder(ST(0), ST(1)); c->fpu_sw &= ~0x0400; /* fprem1  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (PF(c)) goto L_0044f1df; /* jp 0x44f1df */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    goto L_0044f1ba; /* jmp 0x44f1ba */
L_0044f1ed:;
    PUSH32(c, 0x0044f1f2u); f_00452cfc(c); /* call 0x452cfc */
    goto L_0044f20f; /* jmp 0x44f20f */
L_0044f1f4:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044f1ed; /* jne 0x44f1ed */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044f1ed; /* jne 0x44f1ed */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0044f20f:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x1eu); /* mov edx, 0x1e */
    c->ecx = (uint32_t)((uint32_t)(0x46c940u)); /* lea ecx, [0x46c940] */
    PUSH32(c, 0x0044f22cu); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f230(CPU *c) { /* FUN_0044f230 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x0044f23bu); f_00452d58(c); /* call 0x452d58 */
    PUSH32(c, 0x0044f240u); f_0044f24d(c); /* call 0x44f24d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_0044f244(CPU *c) { /* FUN_0044f244 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x4u)); /* lea edx, [esp + 4] */
    PUSH32(c, 0x0044f24du); f_00452d15(c); /* call 0x452d15 */
    { f_0044f24d(c); return; }
}

void f_0044f24d(CPU *c) { /* FUN_0044f24d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    if (c->zf) goto L_0044f2a9; /* je 0x44f2a9 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044f265; /* je 0x44f265 */
    PUSH32(c, 0x0044f265u); f_00452ce5(c); /* call 0x452ce5 */
L_0044f265:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000000u)); /* test eax, 0x80000000 */
    if (!c->zf) goto L_0044f28b; /* jne 0x44f28b */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
L_0044f26e:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) goto L_00452d6e; /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x5u); /* mov edx, 5 */
    c->ecx = (uint32_t)((uint32_t)(0x46c950u)); /* lea ecx, [0x46c950] */
    { f_00452d7b(c); return; } /* jmp 0x452d7b */
L_0044f28b:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (!c->zf) goto L_0044f2be; /* jne 0x44f2be */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044f2be; /* jne 0x44f2be */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044f2be; /* jne 0x44f2be */
    goto L_0044f26e; /* jmp 0x44f26e */
L_0044f2a2:;
    PUSH32(c, 0x0044f2a7u); f_00452cfc(c); /* call 0x452cfc */
    goto L_0044f2cb; /* jmp 0x44f2cb */
L_0044f2a9:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_0044f2a2; /* jne 0x44f2a2 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_0044f2a2; /* jne 0x44f2a2 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000000u))); /* and eax, 0x80000000 */
    if (c->zf) goto L_0044f26e; /* je 0x44f26e */
L_0044f2be:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0044f2cb:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) goto L_00452d6e; /* jne 0x452d6e */
    c->edx = (uint32_t)((uint32_t)0x5u); /* mov edx, 5 */
    c->ecx = (uint32_t)((uint32_t)(0x46c950u)); /* lea ecx, [0x46c950] */
    PUSH32(c, 0x0044f2e8u); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452d6e:;
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_00452d79; /* je 0x452d79 */
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00452d79:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f2ea(CPU *c) { /* FUN_0044f2ea */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xffffu); /* mov esi, 0xffff */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x133fu; PUSH32(c, v_); } /* push 0x133f */
    PUSH32(c, 0x0044f301u); f_0045276d(c); /* call 0x45276d */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f37e; /* jne 0x44f37e */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0044f31fu); f_00451e7c(c); /* call 0x451e7c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0044f370; /* je 0x44f370 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_0044f360; /* je 0x44f360 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_0044f34f; /* je 0x44f34f */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x45bc48u))); /* fadd qword ptr [0x45bc48] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x0044f34au); f_00452049(c); /* call 0x452049 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    goto L_0044f39b; /* jmp 0x44f39b */
L_0044f34f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    PUSH32(c, 0x0044f35bu); f_00451f97(c); /* call 0x451f97 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_0044f39b; /* jmp 0x44f39b */
L_0044f360:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f367u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    ST(0) = -ST(0); /* fchs  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044f39b; /* jmp 0x44f39b */
L_0044f370:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f377u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044f39b; /* jmp 0x44f39b */
L_0044f37e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffffffu))); /* and eax, 0x7fffffff */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    PUSH32(c, 0x0044f396u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0044f39b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044f39f(CPU *c) { /* PTR_0044f39f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_0044f3a9; /* jge 0x44f3a9 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_0044f3a9:;
    c->esp += 4; return; /* ret  */
}

void f_0044f3b0(CPU *c) { /* FUN_0044f3b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); /* fst qword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    PUSH32(c, 0x0044f3c5u); f_0044f3d2(c); /* call 0x44f3d2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_0044f3c9(CPU *c) { /* PTR_0044f3c9 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edx, [esp + 0xc] */
    PUSH32(c, 0x0044f3d2u); f_00452d15(c); /* call 0x452d15 */
    { f_0044f3d2(c); return; }
}

void f_0044f3d2(CPU *c) { /* FUN_0044f3d2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_0044f3e6; /* je 0x44f3e6 */
    PUSH32(c, 0x0044f3e6u); f_00452ce5(c); /* call 0x452ce5 */
L_0044f3e6:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7ff00000u))); /* and ecx, 0x7ff00000 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    (void)sub32(c, c->ecx, (uint32_t)0x7ff00000u); /* cmp ecx, 0x7ff00000 */
    if (c->zf) goto L_0044f499; /* je 0x44f499 */
    PUSH32(c, 0x0044f401u); f_00452d15(c); /* call 0x452d15 */
    if (c->zf) goto L_0044f495; /* je 0x44f495 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_0044f508; /* je 0x44f508 */
L_0044f412:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov cl, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x80u))); /* and cl, 0x80 */
    if (!c->zf) goto L_0044f580; /* jne 0x44f580 */
L_0044f41f:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    PUSH32(c, 0x0044f426u); f_00452cd0(c); /* call 0x452cd0 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x1u); /* cmp cl, 1 */
    if (!c->zf) goto L_0044f42d; /* jne 0x44f42d */
    ST(0) = -ST(0); /* fchs  */
L_0044f42d:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->ecx = (uint32_t)((uint32_t)(0x46c968u)); /* lea ecx, [0x46c968] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    { f_00452db9(c); return; } /* jmp 0x452db9 */
L_0044f44a:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->ecx = (uint32_t)((uint32_t)(0x46c968u)); /* lea ecx, [0x46c968] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    PUSH32(c, 0x0044f467u); f_00452e60(c); /* call 0x452e60 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_0044f469:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    PUSH32(c, 0x0044f472u); f_00452d15(c); /* call 0x452d15 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x16u)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0x16], 8 */
    if (!c->zf) goto L_0044f47c; /* jne 0x44f47c */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_0044f4af; /* jmp 0x44f4af */
L_0044f47c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f485:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0xeu)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0xe], 8 */
    if (!c->zf) goto L_0044f47c; /* jne 0x44f47c */
L_0044f48c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f495:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    goto L_0044f4af; /* jmp 0x44f4af */
L_0044f499:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_0044f469; /* jne 0x44f469 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    PUSH32(c, 0x0044f4afu); f_00452d15(c); /* call 0x452d15 */
L_0044f4af:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffu))); /* and edx, 0xfffff */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (!c->zf) goto L_0044f4cd; /* jne 0x44f4cd */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | R32((uint32_t)(c->esp + 0x8u))))); /* or edx, dword ptr [esp + 8] */
    if (!c->zf) goto L_0044f485; /* jne 0x44f485 */
L_0044f4cd:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0044f48c; /* jne 0x44f48c */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x74u)); /* sub esp, 0x74 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    ; /* wait  */
    guest_trap(c, 0x0044f4e2u, "unsupported: fnsave dword ptr [ecx + 8]"); /* fnsave dword ptr [ecx + 8] */
    PUSH32(c, 0x0044f4eau); f_004530c7(c); /* call 0x4530c7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    guest_trap(c, 0x0044f4eeu, "unsupported: frstor dword ptr [ecx + 8]"); /* frstor dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00452d6e(c); return; } /* je 0x452d6e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f508:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_0044f412; /* jne 0x44f412 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_0044f565; /* je 0x44f565 */
    PUSH32(c, 0x0044f52du); f_0044f5a5(c); /* call 0x44f5a5 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esp + 0xfu))) << 8); /* mov ch, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(shr8(c, ((uint8_t)(c->ecx >> 8)), 7)) << 8); /* shr ch, 7 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esp + 0x17u)) & (uint32_t)0x80u)); /* test dword ptr [esp + 0x17], 0x80 */
    if (c->zf) goto L_0044f554; /* je 0x44f554 */
    FPUSH(c, RF80((uint32_t)(0x46d0e0u))); /* fld xword ptr [0x46d0e0] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) goto L_0044f54a; /* je 0x44f54a */
    ST(0) = -ST(0); /* fchs  */
L_0044f54a:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f554:;
    FPUSH(c, 0.0); /* fldz  */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) { f_00452d6e(c); return; } /* je 0x452d6e */
    ST(0) = -ST(0); /* fchs  */
    { f_00452d6e(c); return; } /* jmp 0x452d6e */
L_0044f565:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_0044f579; /* jne 0x44f579 */
    FPUSH(c, 1.0); /* fld1  */
    { f_00452d6e(c); return; } /* jmp 0x452d6e */
L_0044f579:;
    FPUSH(c, 0.0); /* fldz  */
    { f_00452d6e(c); return; } /* jmp 0x452d6e */
L_0044f580:;
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    PUSH32(c, 0x0044f587u); f_0044f5a5(c); /* call 0x44f5a5 */
    ST(0) = -ST(0); /* fchs  */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0044f41f; /* jne 0x44f41f */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0044f44a; /* jmp 0x44f44a */
}

void f_0044f401(CPU *c) { /* PTR_0044f401 */
    PREEMPT_POLL(c);
    if (c->zf) goto L_0044f495; /* je 0x44f495 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_0044f508; /* je 0x44f508 */
L_0044f412:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov cl, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x80u))); /* and cl, 0x80 */
    if (!c->zf) goto L_0044f580; /* jne 0x44f580 */
L_0044f41f:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    PUSH32(c, 0x0044f426u); f_00452cd0(c); /* call 0x452cd0 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x1u); /* cmp cl, 1 */
    if (!c->zf) goto L_0044f42d; /* jne 0x44f42d */
    ST(0) = -ST(0); /* fchs  */
L_0044f42d:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->ecx = (uint32_t)((uint32_t)(0x46c968u)); /* lea ecx, [0x46c968] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    { f_00452db9(c); return; } /* jmp 0x452db9 */
L_0044f44a:;
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->ecx = (uint32_t)((uint32_t)(0x46c968u)); /* lea ecx, [0x46c968] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    PUSH32(c, 0x0044f467u); f_00452e60(c); /* call 0x452e60 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_0044f47c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f485:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0xeu)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0xe], 8 */
    if (!c->zf) goto L_0044f47c; /* jne 0x44f47c */
L_0044f48c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f495:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    goto L_0044f4af; /* jmp 0x44f4af */
L_0044f4af:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffu))); /* and edx, 0xfffff */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (!c->zf) goto L_0044f4cd; /* jne 0x44f4cd */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | R32((uint32_t)(c->esp + 0x8u))))); /* or edx, dword ptr [esp + 8] */
    if (!c->zf) goto L_0044f485; /* jne 0x44f485 */
L_0044f4cd:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0044f48c; /* jne 0x44f48c */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x74u)); /* sub esp, 0x74 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    ; /* wait  */
    guest_trap(c, 0x0044f4e2u, "unsupported: fnsave dword ptr [ecx + 8]"); /* fnsave dword ptr [ecx + 8] */
    PUSH32(c, 0x0044f4eau); f_004530c7(c); /* call 0x4530c7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    guest_trap(c, 0x0044f4eeu, "unsupported: frstor dword ptr [ecx + 8]"); /* frstor dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00452d6e(c); return; } /* je 0x452d6e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f508:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_0044f412; /* jne 0x44f412 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_0044f565; /* je 0x44f565 */
    PUSH32(c, 0x0044f52du); f_0044f5a5(c); /* call 0x44f5a5 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esp + 0xfu))) << 8); /* mov ch, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(shr8(c, ((uint8_t)(c->ecx >> 8)), 7)) << 8); /* shr ch, 7 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esp + 0x17u)) & (uint32_t)0x80u)); /* test dword ptr [esp + 0x17], 0x80 */
    if (c->zf) goto L_0044f554; /* je 0x44f554 */
    FPUSH(c, RF80((uint32_t)(0x46d0e0u))); /* fld xword ptr [0x46d0e0] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) goto L_0044f54a; /* je 0x44f54a */
    ST(0) = -ST(0); /* fchs  */
L_0044f54a:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_0044f44a; /* jmp 0x44f44a */
L_0044f554:;
    FPUSH(c, 0.0); /* fldz  */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) { f_00452d6e(c); return; } /* je 0x452d6e */
    ST(0) = -ST(0); /* fchs  */
    { f_00452d6e(c); return; } /* jmp 0x452d6e */
L_0044f565:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_0044f579; /* jne 0x44f579 */
    FPUSH(c, 1.0); /* fld1  */
    { f_00452d6e(c); return; } /* jmp 0x452d6e */
L_0044f579:;
    FPUSH(c, 0.0); /* fldz  */
    { f_00452d6e(c); return; } /* jmp 0x452d6e */
L_0044f580:;
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    PUSH32(c, 0x0044f587u); f_0044f5a5(c); /* call 0x44f5a5 */
    ST(0) = -ST(0); /* fchs  */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_0044f41f; /* jne 0x44f41f */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0044f44a; /* jmp 0x44f44a */
}

void f_0044f44a(CPU *c) { /* PTR_0044f44a */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) { f_00452d6e(c); return; } /* jne 0x452d6e */
    c->ecx = (uint32_t)((uint32_t)(0x46c968u)); /* lea ecx, [0x46c968] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    PUSH32(c, 0x0044f467u); f_00452e60(c); /* call 0x452e60 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_0044f472(CPU *c) { /* PTR_0044f472 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x16u)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0x16], 8 */
    if (!c->zf) goto L_0044f47c; /* jne 0x44f47c */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_0044f4af; /* jmp 0x44f4af */
L_0044f47c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
L_0044f485:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0xeu)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0xe], 8 */
    if (!c->zf) goto L_0044f47c; /* jne 0x44f47c */
L_0044f48c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
L_0044f4af:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffu))); /* and edx, 0xfffff */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (!c->zf) goto L_0044f4cd; /* jne 0x44f4cd */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | R32((uint32_t)(c->esp + 0x8u))))); /* or edx, dword ptr [esp + 8] */
    if (!c->zf) goto L_0044f485; /* jne 0x44f485 */
L_0044f4cd:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0044f48c; /* jne 0x44f48c */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x74u)); /* sub esp, 0x74 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    ; /* wait  */
    guest_trap(c, 0x0044f4e2u, "unsupported: fnsave dword ptr [ecx + 8]"); /* fnsave dword ptr [ecx + 8] */
    PUSH32(c, 0x0044f4eau); f_004530c7(c); /* call 0x4530c7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    guest_trap(c, 0x0044f4eeu, "unsupported: frstor dword ptr [ecx + 8]"); /* frstor dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00452d6e(c); return; } /* je 0x452d6e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
}

void f_0044f47c(CPU *c) { /* PTR_0044f47c */
    PREEMPT_POLL(c);
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
}

void f_0044f485(CPU *c) { /* PTR_0044f485 */
    PREEMPT_POLL(c);
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0xeu)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0xe], 8 */
    if (!c->zf) { f_0044f47c(c); return; } /* jne 0x44f47c */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
}

void f_0044f48c(CPU *c) { /* PTR_0044f48c */
    PREEMPT_POLL(c);
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
}

void f_0044f4af(CPU *c) { /* PTR_0044f4af */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffu))); /* and edx, 0xfffff */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (!c->zf) goto L_0044f4cd; /* jne 0x44f4cd */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | R32((uint32_t)(c->esp + 0x8u))))); /* or edx, dword ptr [esp + 8] */
    if (!c->zf) { f_0044f485(c); return; } /* jne 0x44f485 */
L_0044f4cd:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) { f_0044f48c(c); return; } /* jne 0x44f48c */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x74u)); /* sub esp, 0x74 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    ; /* wait  */
    guest_trap(c, 0x0044f4e2u, "unsupported: fnsave dword ptr [ecx + 8]"); /* fnsave dword ptr [ecx + 8] */
    PUSH32(c, 0x0044f4eau); f_004530c7(c); /* call 0x4530c7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    guest_trap(c, 0x0044f4eeu, "unsupported: frstor dword ptr [ecx + 8]"); /* frstor dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00452d6e(c); return; } /* je 0x452d6e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { f_0044f44a(c); return; } /* jmp 0x44f44a */
}

void f_0044f5a5(CPU *c) { /* PTR_0044f5a5 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov cl, 0 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_0044f5ca; /* jne 0x44f5ca */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x46c960u))); /* fmul qword ptr [0x46c960] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_0044f5c9; /* jne 0x44f5c9 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
L_0044f5c9:;
    c->esp += 4; return; /* ret  */
L_0044f5ca:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_0044f5cd(CPU *c) { /* FUN_0044f5cd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0044f633; /* je 0x44f633 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6a8u))); /* mov eax, dword ptr [0x47c6a8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0044f5f9; /* jne 0x44f5f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f5e9u); f_004535f0(c); /* call 0x4535f0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if (c->zf) goto L_0044f625; /* je 0x44f625 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044f5f5u); f_0045361b(c); /* call 0x45361b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044f633; /* jmp 0x44f633 */
L_0044f5f9:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_0044f624; /* jne 0x44f624 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f60cu); f_0045476d(c); /* call 0x45476d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044f624; /* je 0x44f624 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x0044f61fu); f_004547c4(c); /* call 0x4547c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_0044f633; /* jmp 0x44f633 */
L_0044f624:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_0044f625:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b138u)); PUSH32(c, 0x0044f633u); call_indirect(c, t_); } /* call dword ptr [0x45b138] */
L_0044f633:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044f636(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x47c3f0u)); PUSH32(c, v_); } /* push dword ptr [0x47c3f0] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x0044f645u); f_0044f648(c); /* call 0x44f648 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044f648(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_0044f671; /* ja 0x44f671 */
L_0044f64f:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0044f658u); f_0044f674(c); /* call 0x44f674 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f673; /* jne 0x44f673 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_0044f673; /* je 0x44f673 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0044f66cu); f_00454d52(c); /* call 0x454d52 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f64f; /* jne 0x44f64f */
L_0044f671:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0044f673:;
    c->esp += 4; return; /* ret  */
}

void f_0044f674(CPU *c) { /* FUN_0044f674 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6a8u))); /* mov eax, dword ptr [0x47c6a8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0044f698; /* jne 0x44f698 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x47c6a0u))); /* cmp esi, dword ptr [0x47c6a0] */
    if ((!c->cf && !c->zf)) goto L_0044f6ca; /* ja 0x44f6ca */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f691u); f_00453944(c); /* call 0x453944 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0044f6ca; /* je 0x44f6ca */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_0044f698:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_0044f6ca; /* jne 0x44f6ca */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044f6ad; /* je 0x44f6ad */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0044f6b0; /* jmp 0x44f6b0 */
L_0044f6ad:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044f6b0:;
    (void)sub32(c, c->esi, R32((uint32_t)(0x46f16cu))); /* cmp esi, dword ptr [0x46f16c] */
    if ((!c->cf && !c->zf)) goto L_0044f6d7; /* ja 0x44f6d7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044f6c3u); f_00454809(c); /* call 0x454809 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f6e6; /* jne 0x44f6e6 */
    goto L_0044f6d7; /* jmp 0x44f6d7 */
L_0044f6ca:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0044f6d1; /* jne 0x44f6d1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044f6d1:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
L_0044f6d7:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b134u)); PUSH32(c, 0x0044f6e6u); call_indirect(c, t_); } /* call dword ptr [0x45b134] */
L_0044f6e6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0044f6e8(CPU *c) { /* FUN_0044f6e8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_0044f703; /* jne 0x44f703 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0044f6fdu); f_0044f636(c); /* call 0x44f636 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044f983; /* jmp 0x44f983 */
L_0044f703:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0044f718; /* jne 0x44f718 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0044f712u); f_0044f5cd(c); /* call 0x44f5cd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0044f981; /* jmp 0x44f981 */
L_0044f718:;
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6a8u))); /* mov eax, dword ptr [0x47c6a8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0044f828; /* jne 0x44f828 */
L_0044f726:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0044f804; /* ja 0x44f804 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0044f739u); f_004535f0(c); /* call 0x4535f0 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_0044f7df; /* je 0x44f7df */
    (void)sub32(c, c->esi, R32((uint32_t)(0x47c6a0u))); /* cmp esi, dword ptr [0x47c6a0] */
    if ((!c->cf && !c->zf)) goto L_0044f798; /* ja 0x44f798 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044f757u); f_00453df9(c); /* call 0x453df9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0044f794; /* jne 0x44f794 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f764u); f_00453944(c); /* call 0x453944 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044f798; /* je 0x44f798 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_0044f778; /* jb 0x44f778 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_0044f778:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f780u); f_0044df80(c); /* call 0x44df80 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044f786u); f_004535f0(c); /* call 0x4535f0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044f791u); f_0045361b(c); /* call 0x45361b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0044f794:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_0044f7db; /* jne 0x44f7db */
L_0044f798:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0044f79f; /* jne 0x44f79f */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044f79f:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b134u)); PUSH32(c, 0x0044f7b4u); call_indirect(c, t_); } /* call dword ptr [0x45b134] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044f7db; /* je 0x44f7db */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_0044f7c7; /* jb 0x44f7c7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_0044f7c7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f7cfu); f_0044df80(c); /* call 0x44df80 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0044f7d8u); f_0045361b(c); /* call 0x45361b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_0044f7db:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (!c->zf) goto L_0044f800; /* jne 0x44f800 */
L_0044f7df:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0044f7e6; /* jne 0x44f7e6 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044f7e6:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b130u)); PUSH32(c, 0x0044f7feu); call_indirect(c, t_); } /* call dword ptr [0x45b130] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_0044f800:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_0044f821; /* jne 0x44f821 */
L_0044f804:;
    (void)sub32(c, R32((uint32_t)(0x47c3f0u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c3f0], 0 */
    if (c->zf) goto L_0044f821; /* je 0x44f821 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f813u); f_00454d52(c); /* call 0x454d52 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f726; /* jne 0x44f726 */
    goto L_0044f981; /* jmp 0x44f981 */
L_0044f821:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    goto L_0044f983; /* jmp 0x44f983 */
L_0044f828:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_0044f943; /* jne 0x44f943 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0044f845; /* ja 0x44f845 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->cf || c->zf)) goto L_0044f842; /* jbe 0x44f842 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_0044f845; /* jmp 0x44f845 */
L_0044f842:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044f845:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0044f925; /* ja 0x44f925 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xcu)); /* lea eax, [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0044f860u); f_0045476d(c); /* call 0x45476d */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_0044f909; /* je 0x44f909 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x46f16cu))); /* cmp esi, dword ptr [0x46f16c] */
    if (!c->cf) goto L_0044f8cd; /* jae 0x44f8cd */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, 4)); /* shr edi, 4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x0044f887u); f_00454b35(c); /* call 0x454b35 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044f893; /* je 0x44f893 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    goto L_0044f8c5; /* jmp 0x44f8c5 */
L_0044f893:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f899u); f_00454809(c); /* call 0x454809 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044f8cd; /* je 0x44f8cd */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebx))); /* movzx eax, byte ptr [ebx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_0044f8ac; /* jb 0x44f8ac */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_0044f8ac:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f8b6u); f_0044df80(c); /* call 0x44df80 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x0044f8c2u); f_004547c4(c); /* call 0x4547c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0044f8c5:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_0044f821; /* jne 0x44f821 */
L_0044f8cd:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b134u)); PUSH32(c, 0x0044f8dcu); call_indirect(c, t_); } /* call dword ptr [0x45b134] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_0044f925; /* je 0x44f925 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebx))); /* movzx eax, byte ptr [ebx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_0044f8ee; /* jb 0x44f8ee */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_0044f8ee:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044f8f8u); f_0044df80(c); /* call 0x44df80 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x0044f904u); f_004547c4(c); /* call 0x4547c4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_0044f91d; /* jmp 0x44f91d */
L_0044f909:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b130u)); PUSH32(c, 0x0044f91bu); call_indirect(c, t_); } /* call dword ptr [0x45b130] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_0044f91d:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_0044f821; /* jne 0x44f821 */
L_0044f925:;
    (void)sub32(c, R32((uint32_t)(0x47c3f0u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c3f0], 0 */
    if (c->zf) goto L_0044f821; /* je 0x44f821 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f938u); f_00454d52(c); /* call 0x454d52 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f845; /* jne 0x44f845 */
    goto L_0044f981; /* jmp 0x44f981 */
L_0044f943:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_0044f96d; /* ja 0x44f96d */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_0044f951; /* jne 0x44f951 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_0044f951:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b130u)); PUSH32(c, 0x0044f969u); call_indirect(c, t_); } /* call dword ptr [0x45b130] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0044f983; /* jne 0x44f983 */
L_0044f96d:;
    (void)sub32(c, R32((uint32_t)(0x47c3f0u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c3f0], 0 */
    if (c->zf) goto L_0044f983; /* je 0x44f983 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f97cu); f_00454d52(c); /* call 0x454d52 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044f943; /* jne 0x44f943 */
L_0044f981:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0044f983:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044f988(CPU *c) { /* entry */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bc50u; PUSH32(c, v_); } /* push 0x45bc50 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x58u)); /* sub esp, 0x58 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    { uint32_t t_ = R32((uint32_t)(0x45b120u)); PUSH32(c, 0x0044f9b4u); call_indirect(c, t_); } /* call dword ptr [0x45b120] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(((uint8_t)(c->eax >> 8))); /* mov dl, ah */
    W32((uint32_t)(0x47c3a8u), (uint32_t)(c->edx)); /* mov dword ptr [0x47c3a8], edx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffu))); /* and ecx, 0xff */
    W32((uint32_t)(0x47c3a4u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c3a4], ecx */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 8)); /* shl ecx, 8 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    W32((uint32_t)(0x47c3a0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c3a0], ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    W32((uint32_t)(0x47c39cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c39c], eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044f9e7u); f_004533d1(c); /* call 0x4533d1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0044f9f4; /* jne 0x44f9f4 */
    { uint32_t v_ = 0x1cu; PUSH32(c, v_); } /* push 0x1c */
    PUSH32(c, 0x0044f9f3u); f_0044faa3(c); /* call 0x44faa3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0044f9f4:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    PUSH32(c, 0x0044f9fcu); f_00455381(c); /* call 0x455381 */
    { uint32_t t_ = R32((uint32_t)(0x45b124u)); PUSH32(c, 0x0044fa02u); call_indirect(c, t_); } /* call dword ptr [0x45b124] */
    W32((uint32_t)(0x47d904u), (uint32_t)(c->eax)); /* mov dword ptr [0x47d904], eax */
    PUSH32(c, 0x0044fa0cu); f_0045524f(c); /* call 0x45524f */
    W32((uint32_t)(0x47c340u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c340], eax */
    PUSH32(c, 0x0044fa16u); f_00455002(c); /* call 0x455002 */
    PUSH32(c, 0x0044fa1bu); f_00454f49(c); /* call 0x454f49 */
    PUSH32(c, 0x0044fa20u); f_00451a88(c); /* call 0x451a88 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x30], esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b128u)); PUSH32(c, 0x0044fa2du); call_indirect(c, t_); } /* call dword ptr [0x45b128] */
    PUSH32(c, 0x0044fa32u); f_00454ef1(c); /* call 0x454ef1 */
    W32((uint32_t)(c->ebp + 0xffffff9cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x64], eax */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffd0u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x30], 1 */
    if (c->zf) goto L_0044fa41; /* je 0x44fa41 */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xffffffd4u))); /* movzx eax, word ptr [ebp - 0x2c] */
    goto L_0044fa44; /* jmp 0x44fa44 */
L_0044fa41:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_0044fa44:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffff9cu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x64] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x45b12cu)); PUSH32(c, 0x0044fa50u); call_indirect(c, t_); } /* call dword ptr [0x45b12c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044fa56u); f_0043a972(c); /* call 0x43a972 */
    W32((uint32_t)(c->ebp + 0xffffffa0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x60], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044fa5fu); f_00451ab5(c); /* call 0x451ab5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->ebp + 0xffffff98u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x68], ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0044fa70u); f_00454d6d(c); /* call 0x454d6d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044fa5f(CPU *c) { /* PTR_0044fa5f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->ebp + 0xffffff98u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x68], ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0044fa70u); f_00454d6d(c); /* call 0x454d6d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044fa73(CPU *c) { /* PTR_0044fa73 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffff98u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x68] */
    PUSH32(c, 0x0044fa7eu); f_00451ac6(c); /* call 0x451ac6 */
    { f_0044fa7e(c); return; }
}

void f_0044fa7e(CPU *c) { /* FUN_0044fa7e */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x47c348u)), (uint32_t)0x1u); /* cmp dword ptr [0x47c348], 1 */
    if (!c->zf) goto L_0044fa8c; /* jne 0x44fa8c */
    PUSH32(c, 0x0044fa8cu); f_00455630(c); /* call 0x455630 */
L_0044fa8c:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0044fa95u); f_00455669(c); /* call 0x455669 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x46c96cu)); PUSH32(c, 0x0044faa0u); call_indirect(c, t_); } /* call dword ptr [0x46c96c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044faa0(CPU *c) { /* PTR_0044faa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044faa3(CPU *c) { /* FUN_0044faa3 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x47c348u)), (uint32_t)0x1u); /* cmp dword ptr [0x47c348], 1 */
    if (!c->zf) goto L_0044fab1; /* jne 0x44fab1 */
    PUSH32(c, 0x0044fab1u); f_00455630(c); /* call 0x455630 */
L_0044fab1:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x0044fabau); f_00455669(c); /* call 0x455669 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x45b15cu)); PUSH32(c, 0x0044fac6u); call_indirect(c, t_); } /* call dword ptr [0x45b15c] */
    c->esp += 4; return; /* ret  */
}

void f_0044fac6(CPU *c) { /* PTR_0044fac6 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_0044fac7(CPU *c) { /* FUN_0044fac7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_0044fadd; /* je 0x44fadd */
    PUSH32(c, 0x0044faddu); f_00450382(c); /* call 0x450382 */
L_0044fadd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_0044fb05; /* je 0x44fb05 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_0044fb5b; /* je 0x44fb5b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_0044fb5b; /* jne 0x44fb5b */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0044fb00u); f_0044fe0e(c); /* call 0x44fe0e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_0044fb5b; /* jmp 0x44fb5b */
L_0044fb05:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_0044fb5b; /* je 0x44fb5b */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_0044fb3f; /* jne 0x44fb3f */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_0044fb3f; /* jbe 0x44fb3f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0044fb3f; /* je 0x44fb3f */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x0044fb3au); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_0044fb5e; /* jmp 0x44fb5e */
L_0044fb3f:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044fb58u); f_0044fb62(c); /* call 0x44fb62 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_0044fb5b:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_0044fb5e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0044fb62(CPU *c) { /* FUN_0044fb62 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_0044fb82; /* jl 0x44fb82 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_0044fb87; /* jl 0x44fb87 */
L_0044fb82:;
    PUSH32(c, 0x0044fb87u); f_00450382(c); /* call 0x450382 */
L_0044fb87:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_0044fcde; /* jne 0x44fcde */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_0044fbfb; /* jne 0x44fbfb */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_0044fbfb; /* jne 0x44fbfb */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_0044fbfb; /* jne 0x44fbfb */
    c->esi = (uint32_t)(R32((uint32_t)(0x47c34cu))); /* mov esi, dword ptr [0x47c34c] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0044fcd9; /* je 0x44fcd9 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c350u))); /* mov eax, dword ptr [0x47c350] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x0044fbd2u); f_004557ed(c); /* call 0x4557ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044fbdd; /* jne 0x44fbdd */
    PUSH32(c, 0x0044fbddu); f_00450382(c); /* call 0x450382 */
L_0044fbdd:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_0044fcde; /* jne 0x44fcde */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_0044fbfb; /* jne 0x44fbfb */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_0044fbfb; /* jne 0x44fbfb */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_0044fbfb; /* jne 0x44fbfb */
    PUSH32(c, 0x0044fbfbu); f_00450382(c); /* call 0x450382 */
L_0044fbfb:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_0044fcde; /* jne 0x44fcde */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_0044fcde; /* jne 0x44fcde */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_0044fcde; /* jne 0x44fcde */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x0044fc2du); f_0044daad(c); /* call 0x44daad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_0044fc32:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_0044fcc9; /* jae 0x44fcc9 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_0044fcbe; /* jg 0x44fcbe */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_0044fcbe; /* jg 0x44fcbe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_0044fcbb; /* jle 0x44fcbb */
L_0044fc57:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_0044fc88; /* jle 0x44fc88 */
L_0044fc69:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0044fc76u); f_0044fdb1(c); /* call 0x44fdb1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0044fc97; /* jne 0x44fc97 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_0044fc69; /* jg 0x44fc69 */
L_0044fc88:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0044fc57; /* jg 0x44fc57 */
    goto L_0044fcbb; /* jmp 0x44fcbb */
L_0044fc97:;
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
    PUSH32(c, 0x0044fcb8u); f_0044fec2(c); /* call 0x44fec2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_0044fcbb:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_0044fcbe:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_0044fc32; /* jmp 0x44fc32 */
L_0044fcc9:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_0044fcd9; /* je 0x44fcd9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044fcd7u); f_00450237(c); /* call 0x450237 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0044fcd9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0044fcde:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_0044fd04; /* jne 0x44fd04 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044fcffu); f_0044fd09(c); /* call 0x44fd09 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_0044fcd9; /* jmp 0x44fcd9 */
L_0044fd04:;
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_0044fd09(CPU *c) { /* FUN_0044fd09 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x47c354u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c354], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_0044fd3a; /* je 0x44fd3a */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0044fd33u); f_0044d984(c); /* call 0x44d984 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0044fdad; /* jne 0x44fdad */
L_0044fd3a:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x0044fd51u); f_0044daad(c); /* call 0x44daad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_0044fd56:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_0044fdad; /* jae 0x44fdad */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_0044fda5; /* jl 0x44fda5 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_0044fda5; /* jg 0x44fda5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0044fd7f; /* je 0x44fd7f */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_0044fda5; /* jne 0x44fda5 */
L_0044fd7f:;
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
    PUSH32(c, 0x0044fda2u); f_0044fec2(c); /* call 0x44fec2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_0044fda5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_0044fd56; /* jmp 0x44fd56 */
L_0044fdad:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044fdb1(CPU *c) { /* FUN_0044fdb1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044fe08; /* je 0x44fe08 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_0044fe08; /* je 0x44fe08 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_0044fde2; /* je 0x44fde2 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0044fddcu); f_0044e2c0(c); /* call 0x44e2c0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0044fe04; /* jne 0x44fe04 */
L_0044fde2:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_0044fdec; /* je 0x44fdec */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_0044fe04; /* je 0x44fe04 */
L_0044fdec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_0044fdfb; /* je 0x44fdfb */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_0044fe04; /* je 0x44fe04 */
L_0044fdfb:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_0044fe08; /* je 0x44fe08 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_0044fe08; /* jne 0x44fe08 */
L_0044fe04:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0044fe0b; /* jmp 0x44fe0b */
L_0044fe08:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_0044fe0b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_0044fe0e(CPU *c) { /* FUN_0044fe0e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bc60u; PUSH32(c, v_); } /* push 0x45bc60 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
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
L_0044fe40:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_0044fe9a; /* je 0x44fe9a */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_0044fe4f; /* jle 0x44fe4f */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_0044fe54; /* jl 0x44fe54 */
L_0044fe4f:;
    PUSH32(c, 0x0044fe54u); f_00450382(c); /* call 0x450382 */
L_0044fe54:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044fe6f; /* je 0x44fe6f */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044fe6fu); f_004502d0(c); /* call 0x4502d0 */
L_0044fe6f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_0044fe8f; /* jmp 0x44fe8f */
L_0044fe8f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_0044fe40; /* jmp 0x44fe40 */
L_0044fe9a:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044fe40(CPU *c) { /* PTR_0044fe40 */
    PREEMPT_POLL(c);
L_0044fe40:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_0044fe9a; /* je 0x44fe9a */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_0044fe4f; /* jle 0x44fe4f */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_0044fe54; /* jl 0x44fe54 */
L_0044fe4f:;
    PUSH32(c, 0x0044fe54u); f_00450382(c); /* call 0x450382 */
L_0044fe54:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044fe6f; /* je 0x44fe6f */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044fe6fu); f_004502d0(c); /* call 0x4502d0 */
L_0044fe6f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_0044fe8f; /* jmp 0x44fe8f */
L_0044fe8f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_0044fe40; /* jmp 0x44fe40 */
L_0044fe9a:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044fe75(CPU *c) { /* PTR_0044fe75 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x0044fe7du); f_0044feac(c); /* call 0x44feac */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044fe7f(CPU *c) { /* PTR_0044fe7f */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_0044fe40(c); return; } /* jmp 0x44fe40 */
}

void f_0044feac(CPU *c) { /* PTR_0044feac */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_0044febd; /* je 0x44febd */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_0044febd:;
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_0044fec2(CPU *c) { /* FUN_0044fec2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_0044fee4; /* je 0x44fee4 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0044fee1u); f_00450073(c); /* call 0x450073 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_0044fee4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_0044fef0; /* jne 0x44fef0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_0044fef3; /* jmp 0x44fef3 */
L_0044fef0:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_0044fef3:;
    PUSH32(c, 0x0044fef8u); f_0044d86c(c); /* call 0x44d86c */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0044ff09u); f_0044fe0e(c); /* call 0x44fe0e */
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
    PUSH32(c, 0x0044ff2au); f_0044ff3d(c); /* call 0x44ff3d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0044ff38; /* je 0x44ff38 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044ff38u); f_0044d823(c); /* call 0x44d823 */
L_0044ff38:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0044ff3d(CPU *c) { /* FUN_0044ff3d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bc70u; PUSH32(c, v_); } /* push 0x45bc70 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
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
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c34cu))); /* mov ecx, dword ptr [0x47c34c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x1c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c350u))); /* mov ecx, dword ptr [0x47c350] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(0x47c34cu), (uint32_t)(c->edi)); /* mov dword ptr [0x47c34c], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(0x47c350u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c350], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0044ffb5u); f_0044d90b(c); /* call 0x44d90b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0044ffc7u); f_00450003(c); /* call 0x450003 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044ffca(CPU *c) { /* PTR_0044ffca */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0044ffd9(CPU *c) { /* PTR_0044ffd9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x0044ffe1u); f_00450049(c); /* call 0x450049 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_0044ffe3(CPU *c) { /* PTR_0044ffe3 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0044fff5u); f_0044db6a(c); /* call 0x44db6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_0044ffca(c); return; } /* jmp 0x44ffca */
}

void f_0044fffb(CPU *c) { /* PTR_0044fffb */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00450003(c); return; }
}

void f_00450003(CPU *c) { /* FUN_00450003 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(0x47c34cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c34c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    W32((uint32_t)(0x47c350u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c350], eax */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00450048; /* jne 0x450048 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00450048; /* jne 0x450048 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00450048; /* jne 0x450048 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ebx); /* cmp dword ptr [ebp - 0x24], ebx */
    if (!c->zf) goto L_00450048; /* jne 0x450048 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), c->ebx); /* cmp dword ptr [ebp - 0x2c], ebx */
    if (c->zf) goto L_00450048; /* je 0x450048 */
    PUSH32(c, 0x0045003fu); f_0044dbd2(c); /* call 0x44dbd2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00450046u); f_00450237(c); /* call 0x450237 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00450048:;
    c->esp += 4; return; /* ret  */
}

void f_00450049(CPU *c) { /* PTR_00450049 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00450070; /* jne 0x450070 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00450070; /* jne 0x450070 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00450070; /* jne 0x450070 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00450070; /* jne 0x450070 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00450070:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00450073(CPU *c) { /* FUN_00450073 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bc88u; PUSH32(c, v_); } /* push 0x45bc88 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
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
    if (c->zf) goto L_0045021c; /* je 0x45021c */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_0045021c; /* je 0x45021c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0045021c; /* je 0x45021c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00450110; /* je 0x450110 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x004500d9u); f_004557ed(c); /* call 0x4557ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004500ebu); f_00455809(c); /* call 0x455809 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_00450101:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450107u); f_0045029e(c); /* call 0x45029e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00450218; /* jmp 0x450218 */
L_00450110:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_0045016a; /* je 0x45016a */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00450125u); f_004557ed(c); /* call 0x4557ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00450137u); f_00455809(c); /* call 0x455809 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0045014du); f_00455840(c); /* call 0x455840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00450218; /* jne 0x450218 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450218; /* je 0x450218 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00450101; /* jmp 0x450101 */
L_0045016a:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_004501b2; /* jne 0x4501b2 */
    PUSH32(c, 0x0045017du); f_004557ed(c); /* call 0x4557ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0045018fu); f_00455809(c); /* call 0x455809 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x004501a4u); f_0045029e(c); /* call 0x45029e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004501adu); f_00455840(c); /* call 0x455840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00450218; /* jmp 0x450218 */
L_004501b2:;
    PUSH32(c, 0x004501b7u); f_004557ed(c); /* call 0x4557ed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004501c5u); f_00455809(c); /* call 0x455809 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x004501d3u); f_00455825(c); /* call 0x455825 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450213; /* je 0x450213 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_004501f9; /* je 0x4501f9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x004501ebu); f_0045029e(c); /* call 0x45029e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004501f7u); f_0044d865(c); /* call 0x44d865 */
    goto L_00450218; /* jmp 0x450218 */
L_004501f9:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00450205u); f_0045029e(c); /* call 0x45029e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00450211u); f_0044d85e(c); /* call 0x44d85e */
    goto L_00450218; /* jmp 0x450218 */
L_00450213:;
    PUSH32(c, 0x00450218u); f_00450382(c); /* call 0x450382 */
L_00450218:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_0045021c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045022b(CPU *c) { /* PTR_0045022b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0045022f(CPU *c) { /* PTR_0045022f */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_00450237(CPU *c) { /* FUN_00450237 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bc98u; PUSH32(c, v_); } /* push 0x45bc98 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
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
    if (c->zf) goto L_0045027e; /* je 0x45027e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0045027e; /* je 0x45027e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x0045027au); f_0044d857(c); /* call 0x44d857 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_0045027e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045028d(CPU *c) { /* PTR_0045028d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_00450296(CPU *c) { /* PTR_00450296 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_0045029e(CPU *c) { /* FUN_0045029e */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_004502bf; /* jl 0x4502bf */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_004502bf:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_004502d0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x004502f3u); f_0044dbf5(c); /* call 0x44dbf5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x004502f7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_0045030f; /* jne 0x45030f */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_0045030f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00450315u); f_0044dbf5(c); /* call 0x44dbf5 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_0045031c(CPU *c) { /* FUN_0045031c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bca8u; PUSH32(c, v_); } /* push 0x45bca8 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x47c358u))); /* mov eax, dword ptr [0x47c358] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450364; /* je 0x450364 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00450357u); call_indirect(c, t_); } /* call eax */
    goto L_00450360; /* jmp 0x450360 */
L_00450360:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00450364:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0045036du); f_0045036d(c); /* call 0x45036d */
    { f_00455b75(c); return; } /* jmp 0x455b75 */
}

void f_00450359(CPU *c) { /* PTR_00450359 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0045035d(CPU *c) { /* PTR_0045035d */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x0045036du); f_0045036d(c); /* call 0x45036d */
    { f_00455b75(c); return; } /* jmp 0x455b75 */
}

void f_0045036d(CPU *c) { /* PTR_0045036d */
    PREEMPT_POLL(c);
    { f_00455b75(c); return; } /* jmp 0x455b75 */
}

void f_00450372(CPU *c) { /* PTR_00450372 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x46c980u))); /* mov eax, dword ptr [0x46c980] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0045037d; /* je 0x45037d */
    { uint32_t t_ = c->eax; PUSH32(c, 0x0045037du); call_indirect(c, t_); } /* call eax */
L_0045037d:;
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_00450382(CPU *c) { /* FUN_00450382 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x45bcc0u; PUSH32(c, v_); } /* push 0x45bcc0 */
    { uint32_t v_ = 0x455558u; PUSH32(c, v_); } /* push 0x455558 */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x46c984u))); /* mov eax, dword ptr [0x46c984] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004503ca; /* je 0x4503ca */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x004503bdu); call_indirect(c, t_); } /* call eax */
    goto L_004503c6; /* jmp 0x4503c6 */
L_004503c6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_004503ca:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x004503d3u); f_004503d3(c); /* call 0x4503d3 */
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_004503bf(CPU *c) { /* PTR_004503bf */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_004503c3(CPU *c) { /* PTR_004503c3 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x004503d3u); f_004503d3(c); /* call 0x4503d3 */
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_004503d3(CPU *c) { /* PTR_004503d3 */
    PREEMPT_POLL(c);
    { f_0045031c(c); return; } /* jmp 0x45031c */
}

void f_004503d8(CPU *c) { /* FUN_004503d8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_004503fb; /* jne 0x4503fb */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_004503fb; /* jne 0x4503fb */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_004503fb; /* jne 0x4503fb */
    { f_0045031c(c); return; } /* jmp 0x45031c */
L_004503fb:;
    c->eax = (uint32_t)(R32((uint32_t)(0x47c35cu))); /* mov eax, dword ptr [0x47c35c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450418; /* je 0x450418 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045040au); f_00455825(c); /* call 0x455825 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00450418; /* je 0x450418 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x47c35cu)); PUSH32(c, 0x00450416u); call_indirect(c, t_); } /* call dword ptr [0x47c35c] */
    goto L_0045041a; /* jmp 0x45041a */
L_00450418:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0045041a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_0045041e(CPU *c) { /* PTR_0045041e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x4503d8u; PUSH32(c, v_); } /* push 0x4503d8 */
    { uint32_t t_ = R32((uint32_t)(0x45b11cu)); PUSH32(c, 0x00450429u); call_indirect(c, t_); } /* call dword ptr [0x45b11c] */
    W32((uint32_t)(0x47c35cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c35c], eax */
    c->esp += 4; return; /* ret  */
}

void f_0045042f(CPU *c) { /* PTR_0045042f */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x47c35cu)); PUSH32(c, v_); } /* push dword ptr [0x47c35c] */
    { uint32_t t_ = R32((uint32_t)(0x45b11cu)); PUSH32(c, 0x0045043bu); call_indirect(c, t_); } /* call dword ptr [0x45b11c] */
    c->esp += 4; return; /* ret  */
}

void f_0045043c(CPU *c) { /* FUN_0045043c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x47c680u))); /* cmp eax, dword ptr [0x47c680] */
    if (!c->cf) goto L_00450485; /* jae 0x450485 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1fu))); /* and edx, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x47c580u))); /* mov ecx, dword ptr [ecx*4 + 0x47c580] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->edx * 8 + 0x4u)) & (uint8_t)0x1u)); /* test byte ptr [ecx + edx*8 + 4], 1 */
    if (c->zf) goto L_00450485; /* je 0x450485 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450466u); f_00455d12(c); /* call 0x455d12 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b18cu)); PUSH32(c, 0x0045046eu); call_indirect(c, t_); } /* call dword ptr [0x45b18c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0045047a; /* jne 0x45047a */
    { uint32_t t_ = R32((uint32_t)(0x45b118u)); PUSH32(c, 0x00450478u); call_indirect(c, t_); } /* call dword ptr [0x45b118] */
    goto L_0045047c; /* jmp 0x45047c */
L_0045047a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0045047c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00450492; /* je 0x450492 */
    W32((uint32_t)(0x47c394u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c394], eax */
L_00450485:;
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [0x47c390], 9 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_00450492:;
    c->esp += 4; return; /* ret  */
}

void f_00450493(CPU *c) { /* FUN_00450493 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x414u)); /* sub esp, 0x414 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x47c680u))); /* cmp ecx, dword ptr [0x47c680] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->cf) goto L_00450627; /* jae 0x450627 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x1fu))); /* and esi, 0x1f */
    c->ebx = (uint32_t)((uint32_t)(c->eax * 4 + 0x47c580u)); /* lea ebx, [eax*4 + 0x47c580] */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u))); /* mov al, byte ptr [eax + esi + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00450627; /* je 0x450627 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edi); /* cmp dword ptr [ebp + 0x10], edi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x10], edi */
    if (!c->zf) goto L_004504e4; /* jne 0x4504e4 */
L_004504dd:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0045063b; /* jmp 0x45063b */
L_004504e4:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x20u)); /* test al, 0x20 */
    if (c->zf) goto L_004504f4; /* je 0x4504f4 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x004504f1u); f_00455e53(c); /* call 0x455e53 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_004504f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x80u)); /* test byte ptr [eax + 4], 0x80 */
    if (c->zf) goto L_004505c3; /* je 0x4505c3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edi); /* cmp dword ptr [ebp + 0x10], edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
    if ((c->cf || c->zf)) goto L_004505fb; /* jbe 0x4505fb */
L_00450514:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffbecu)); /* lea eax, [ebp - 0x414] */
L_0045051a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_0045054e; /* jae 0x45054e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov cl, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xau); /* cmp cl, 0xa */
    if (!c->zf) goto L_00450539; /* jne 0x450539 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0xdu)); /* mov byte ptr [eax], 0xd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00450539:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffbecu)); /* lea edx, [ebp - 0x414] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if ((c->sf != c->of)) goto L_0045051a; /* jl 0x45051a */
L_0045054e:;
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
    { uint32_t t_ = R32((uint32_t)(0x45b150u)); PUSH32(c, 0x00450571u); call_indirect(c, t_); } /* call dword ptr [0x45b150] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004505b8; /* je 0x4505b8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp - 8], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->sf != c->of)) goto L_0045058a; /* jl 0x45058a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu)))); /* sub eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if (c->cf) goto L_00450514; /* jb 0x450514 */
L_0045058a:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_0045058c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00450622; /* jne 0x450622 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (c->zf) goto L_004505fb; /* je 0x4505fb */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->eax); /* cmp dword ptr [ebp + 8], eax */
    if (!c->zf) goto L_004505f0; /* jne 0x4505f0 */
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [0x47c390], 9 */
    W32((uint32_t)(0x47c394u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c394], eax */
    goto L_00450638; /* jmp 0x450638 */
L_004505b8:;
    { uint32_t t_ = R32((uint32_t)(0x45b118u)); PUSH32(c, 0x004505beu); call_indirect(c, t_); } /* call dword ptr [0x45b118] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    goto L_0045058a; /* jmp 0x45058a */
L_004505c3:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea ecx, [ebp - 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(0x45b150u)); PUSH32(c, 0x004505d6u); call_indirect(c, t_); } /* call dword ptr [0x45b150] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004505e5; /* je 0x4505e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_0045058c; /* jmp 0x45058c */
L_004505e5:;
    { uint32_t t_ = R32((uint32_t)(0x45b118u)); PUSH32(c, 0x004505ebu); call_indirect(c, t_); } /* call dword ptr [0x45b118] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    goto L_0045058c; /* jmp 0x45058c */
L_004505f0:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x004505f8u); f_00455dec(c); /* call 0x455dec */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00450638; /* jmp 0x450638 */
L_004505fb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + c->esi + 0x4u)) & (uint8_t)0x40u)); /* test byte ptr [eax + esi + 4], 0x40 */
    if (c->zf) goto L_00450610; /* je 0x450610 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x1au); /* cmp byte ptr [eax], 0x1a */
    if (c->zf) goto L_004504dd; /* je 0x4504dd */
L_00450610:;
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x1cu)); /* mov dword ptr [0x47c390], 0x1c */
    W32((uint32_t)(0x47c394u), (uint32_t)(c->edi)); /* mov dword ptr [0x47c394], edi */
    goto L_00450638; /* jmp 0x450638 */
L_00450622:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub eax, dword ptr [ebp - 0x10] */
    goto L_0045063b; /* jmp 0x45063b */
L_00450627:;
    { uint32_t a_ = (uint32_t)(0x47c394u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x47c394], 0 */
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [0x47c390], 9 */
L_00450638:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_0045063b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00450640(CPU *c) { /* PTR_00450640 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47d900u))); /* mov eax, dword ptr [0x47d900] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_00450654; /* jne 0x450654 */
    c->eax = (uint32_t)((uint32_t)0x200u); /* mov eax, 0x200 */
    goto L_0045065a; /* jmp 0x45065a */
L_00450654:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf == c->of)) goto L_0045065f; /* jge 0x45065f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_0045065a:;
    W32((uint32_t)(0x47d900u), (uint32_t)(c->eax)); /* mov dword ptr [0x47d900], eax */
L_0045065f:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450667u); f_00455eed(c); /* call 0x455eed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c8e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c8e8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00450693; /* jne 0x450693 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(0x47d900u), (uint32_t)(c->esi)); /* mov dword ptr [0x47d900], esi */
    PUSH32(c, 0x00450680u); f_00455eed(c); /* call 0x455eed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c8e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c8e8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00450693; /* jne 0x450693 */
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    PUSH32(c, 0x00450692u); f_0044fa7e(c); /* call 0x44fa7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00450693:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x46c988u); /* mov eax, 0x46c988 */
L_0045069a:;
    c->edx = (uint32_t)(R32((uint32_t)(0x47c8e8u))); /* mov edx, dword ptr [0x47c8e8] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x46cc08u); /* cmp eax, 0x46cc08 */
    if ((c->sf != c->of)) goto L_0045069a; /* jl 0x45069a */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (uint32_t)((uint32_t)0x46c998u); /* mov ecx, 0x46c998 */
L_004506b7:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esi = (uint32_t)(c->edx); /* mov esi, edx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x1fu))); /* and esi, 0x1f */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x47c580u))); /* mov eax, dword ptr [eax*4 + 0x47c580] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov eax, dword ptr [eax + esi*8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_004506d4; /* je 0x4506d4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004506d7; /* jne 0x4506d7 */
L_004506d4:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ecx], 0xffffffff */
L_004506d7:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x20u)); /* add ecx, 0x20 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->ecx, (uint32_t)0x46c9f8u); /* cmp ecx, 0x46c9f8 */
    if ((c->sf != c->of)) goto L_004506b7; /* jl 0x4506b7 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_004506e5(CPU *c) { /* PTR_004506e5 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x004506eau); f_0044deb6(c); /* call 0x44deb6 */
    (void)sub8(c, R8((uint32_t)(0x47c3d0u)), (uint8_t)0x0u); /* cmp byte ptr [0x47c3d0], 0 */
    if (c->zf) goto L_004506f8; /* je 0x4506f8 */
    { f_00455f9e(c); return; } /* jmp 0x455f9e */
L_004506f8:;
    c->esp += 4; return; /* ret  */
}

void f_004506f9(CPU *c) { /* FUN_004506f9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ebx, dword ptr [esi + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x82u)); /* test al, 0x82 */
    if (c->zf) goto L_00450802; /* je 0x450802 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x40u)); /* test al, 0x40 */
    if (!c->zf) goto L_00450802; /* jne 0x450802 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00450731; /* je 0x450731 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00450802; /* je 0x450802 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfeu))); /* and al, 0xfe */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_00450731:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xefu))); /* and al, 0xef */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x10cu)); /* test ax, 0x10c */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_0045076b; /* jne 0x45076b */
    (void)sub32(c, c->esi, (uint32_t)0x46c9a8u); /* cmp esi, 0x46c9a8 */
    if (c->zf) goto L_00450759; /* je 0x450759 */
    (void)sub32(c, c->esi, (uint32_t)0x46c9c8u); /* cmp esi, 0x46c9c8 */
    if (!c->zf) goto L_00450764; /* jne 0x450764 */
L_00450759:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0045075fu); f_0045603a(c); /* call 0x45603a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0045076b; /* jne 0x45076b */
L_00450764:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0045076au); f_00455ff6(c); /* call 0x455ff6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0045076b:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->esi + 0xcu)) & (uint16_t)0x108u)); /* test word ptr [esi + 0xc], 0x108 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_004507d8; /* je 0x4507d8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    if ((c->zf || c->sf != c->of)) goto L_0045079b; /* jle 0x45079b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00450793u); f_00450493(c); /* call 0x450493 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    goto L_004507ce; /* jmp 0x4507ce */
L_0045079b:;
    (void)sub32(c, c->ebx, (uint32_t)0xffffffffu); /* cmp ebx, -1 */
    if (c->zf) goto L_004507b6; /* je 0x4507b6 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x47c580u))); /* mov eax, dword ptr [eax*4 + 0x47c580] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 8)); /* lea eax, [eax + ecx*8] */
    goto L_004507bb; /* jmp 0x4507bb */
L_004507b6:;
    c->eax = (uint32_t)((uint32_t)0x46f1f8u); /* mov eax, 0x46f1f8 */
L_004507bb:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x20u)); /* test byte ptr [eax + 4], 0x20 */
    if (c->zf) goto L_004507ce; /* je 0x4507ce */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x004507cbu); f_00455e53(c); /* call 0x455e53 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_004507ce:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    goto L_004507ec; /* jmp 0x4507ec */
L_004507d8:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x004507e6u); f_00450493(c); /* call 0x450493 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_004507ec:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edi); /* cmp dword ptr [ebp + 0xc], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_004507f8; /* je 0x4507f8 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    goto L_00450807; /* jmp 0x450807 */
L_004507f8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    goto L_0045080a; /* jmp 0x45080a */
L_00450802:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_00450807:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_0045080a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0045080e(CPU *c) { /* FUN_0045080e */
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
    if (c->zf) goto L_00450f27; /* je 0x450f27 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_00450842; /* jmp 0x450842 */
L_0045083a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov esi, dword ptr [ebp - 0x30] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00450842:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->edx); /* cmp dword ptr [ebp - 0x14], edx */
    if ((c->sf != c->of)) goto L_00450f27; /* jl 0x450f27 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x20u); /* cmp bl, 0x20 */
    if ((c->sf != c->of)) goto L_00450863; /* jl 0x450863 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x78u); /* cmp bl, 0x78 */
    if ((!c->zf && c->sf == c->of)) goto L_00450863; /* jg 0x450863 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x45bcb8u))); /* mov al, byte ptr [eax + 0x45bcb8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    goto L_00450865; /* jmp 0x450865 */
L_00450863:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00450865:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + c->eax * 8 + 0x45bcd8u))); /* movsx eax, byte ptr [esi + eax*8 + 0x45bcd8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    if ((!c->cf && !c->zf)) goto L_00450f16; /* ja 0x450f16 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x450f2fu)); switch (t_) { case 0x00450883u: goto L_00450883; case 0x0045089eu: goto L_0045089e; case 0x004508eau: goto L_004508ea; case 0x00450921u: goto L_00450921; case 0x00450929u: goto L_00450929; case 0x0045095eu: goto L_0045095e; case 0x004509adu: goto L_004509ad; case 0x004509f1u: goto L_004509f1; default: jump_indirect(c, t_, 0x0045087cu); return; } } /* jmp dword ptr [eax*4 + 0x450f2f] */
L_00450883:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_00450f16; /* jmp 0x450f16 */
L_0045089e:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    if (c->zf) goto L_004508e1; /* je 0x4508e1 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_004508d8; /* je 0x4508d8 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x8u)); /* sub eax, 8 */
    if (c->zf) goto L_004508cf; /* je 0x4508cf */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_004508c6; /* je 0x4508c6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00450f16; /* jne 0x450f16 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp - 4], 8 */
    goto L_00450f16; /* jmp 0x450f16 */
L_004508c6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    goto L_00450f16; /* jmp 0x450f16 */
L_004508cf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp - 4], 1 */
    goto L_00450f16; /* jmp 0x450f16 */
L_004508d8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 4], 0x80 */
    goto L_00450f16; /* jmp 0x450f16 */
L_004508e1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp - 4], 2 */
    goto L_00450f16; /* jmp 0x450f16 */
L_004508ea:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_00450912; /* jne 0x450912 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004508f8u); f_00450fed(c); /* call 0x450fed */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    if ((c->sf == c->of)) goto L_00450f16; /* jge 0x450f16 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_0045090a:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    goto L_00450f16; /* jmp 0x450f16 */
L_00450912:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    goto L_0045090a; /* jmp 0x45090a */
L_00450921:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    goto L_00450f16; /* jmp 0x450f16 */
L_00450929:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_0045094c; /* jne 0x45094c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450937u); f_00450fed(c); /* call 0x450fed */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf == c->of)) goto L_00450f16; /* jge 0x450f16 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    goto L_00450f16; /* jmp 0x450f16 */
L_0045094c:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4)); /* lea eax, [ecx + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    goto L_00450f16; /* jmp 0x450f16 */
L_0045095e:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x49u); /* cmp bl, 0x49 */
    if (c->zf) goto L_00450991; /* je 0x450991 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x68u); /* cmp bl, 0x68 */
    if (c->zf) goto L_00450988; /* je 0x450988 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x6cu); /* cmp bl, 0x6c */
    if (c->zf) goto L_0045097f; /* je 0x45097f */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x77u); /* cmp bl, 0x77 */
    if (!c->zf) goto L_00450f16; /* jne 0x450f16 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
    goto L_00450f16; /* jmp 0x450f16 */
L_0045097f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ebp - 4], 0x10 */
    goto L_00450f16; /* jmp 0x450f16 */
L_00450988:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [ebp - 4], 0x20 */
    goto L_00450f16; /* jmp 0x450f16 */
L_00450991:;
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x36u); /* cmp byte ptr [edi], 0x36 */
    if (!c->zf) goto L_004509aa; /* jne 0x4509aa */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x1u)), (uint8_t)0x34u); /* cmp byte ptr [edi + 1], 0x34 */
    if (!c->zf) goto L_004509aa; /* jne 0x4509aa */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 3], 0x80 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    goto L_00450f16; /* jmp 0x450f16 */
L_004509aa:;
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x30], edx */
L_004509ad:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov ecx, dword ptr [0x46cd0c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [ecx + eax*2 + 1], 0x80 */
    if (c->zf) goto L_004509d9; /* je 0x4509d9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004509d0u); f_00450f4f(c); /* call 0x450f4f */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_004509d9:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004509e9u); f_00450f4f(c); /* call 0x450f4f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00450f16; /* jmp 0x450f16 */
L_004509f1:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    (void)sub32(c, c->eax, (uint32_t)0x67u); /* cmp eax, 0x67 */
    if ((!c->zf && c->sf == c->of)) goto L_00450c19; /* jg 0x450c19 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    if ((c->sf == c->of)) goto L_00450a9c; /* jge 0x450a9c */
    (void)sub32(c, c->eax, (uint32_t)0x58u); /* cmp eax, 0x58 */
    if ((!c->zf && c->sf == c->of)) goto L_00450afa; /* jg 0x450afa */
    if (c->zf) goto L_00450c8d; /* je 0x450c8d */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x43u)); /* sub eax, 0x43 */
    if (c->zf) goto L_00450abd; /* je 0x450abd */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00450a92; /* je 0x450a92 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00450a92; /* je 0x450a92 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xcu)); /* sub eax, 0xc */
    if (!c->zf) goto L_00450e18; /* jne 0x450e18 */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_00450a3b; /* jne 0x450a3b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_00450a3b:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov esi, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00450a48; /* jne 0x450a48 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
L_00450a48:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450a51u); f_00450fed(c); /* call 0x450fed */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if (c->zf) goto L_00450c61; /* je 0x450c61 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00450a70; /* jne 0x450a70 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cc0cu))); /* mov ecx, dword ptr [0x46cc0c] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00450a70:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_00450a79:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00450c58; /* je 0x450c58 */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x0u); /* cmp word ptr [eax], 0 */
    if (c->zf) goto L_00450c58; /* je 0x450c58 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00450a79; /* jmp 0x450a79 */
L_00450a92:;
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x20u)); /* add bl, 0x20 */
L_00450a9c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea edi, [ebp - 0x248] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    if ((c->sf == c->of)) goto L_00450b80; /* jge 0x450b80 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6u)); /* mov dword ptr [ebp - 0x10], 6 */
    goto L_00450b8e; /* jmp 0x450b8e */
L_00450abd:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_00450ac9; /* jne 0x450ac9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_00450ac9:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00450b10; /* je 0x450b10 */
    PUSH32(c, 0x00450adau); f_0045100a(c); /* call 0x45100a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450ae7u); f_00456060(c); /* call 0x456060 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_00450b23; /* jge 0x450b23 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_00450b23; /* jmp 0x450b23 */
L_00450afa:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5au)); /* sub eax, 0x5a */
    if (c->zf) goto L_00450b31; /* je 0x450b31 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    if (c->zf) goto L_00450ac9; /* je 0x450ac9 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00450cf3; /* je 0x450cf3 */
    goto L_00450e18; /* jmp 0x450e18 */
L_00450b10:;
    PUSH32(c, 0x00450b15u); f_00450fed(c); /* call 0x450fed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebp + 0xfffffdb8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x248], al */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0xc], 1 */
L_00450b23:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_00450e18; /* jmp 0x450e18 */
L_00450b31:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450b3au); f_00450fed(c); /* call 0x450fed */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00450b72; /* je 0x450b72 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00450b72; /* je 0x450b72 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x8u)); /* test byte ptr [ebp - 3], 8 */
    if (c->zf) goto L_00450b63; /* je 0x450b63 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    goto L_00450e18; /* jmp 0x450e18 */
L_00450b63:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    goto L_00450e15; /* jmp 0x450e15 */
L_00450b72:;
    c->eax = (uint32_t)(R32((uint32_t)(0x46cc08u))); /* mov eax, dword ptr [0x46cc08] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    goto L_00450c0e; /* jmp 0x450c0e */
L_00450b80:;
    if (!c->zf) goto L_00450b8e; /* jne 0x450b8e */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_00450b8e; /* jne 0x450b8e */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
L_00450b8e:;
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
    { uint32_t t_ = R32((uint32_t)(0x46cf30u)); PUSH32(c, 0x00450bbeu); call_indirect(c, t_); } /* call dword ptr [0x46cf30] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80u))); /* and esi, 0x80 */
    if (c->zf) goto L_00450be0; /* je 0x450be0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (!c->zf) goto L_00450be0; /* jne 0x450be0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x46cf3cu)); PUSH32(c, 0x00450bdfu); call_indirect(c, t_); } /* call dword ptr [0x46cf3c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00450be0:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_00450bf7; /* jne 0x450bf7 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00450bf7; /* jne 0x450bf7 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x46cf34u)); PUSH32(c, 0x00450bf6u); call_indirect(c, t_); } /* call dword ptr [0x46cf34] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00450bf7:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffdb8u)), (uint8_t)0x2du); /* cmp byte ptr [ebp - 0x248], 0x2d */
    if (!c->zf) goto L_00450c0d; /* jne 0x450c0d */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb9u)); /* lea edi, [ebp - 0x247] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
L_00450c0d:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00450c0e:;
    PUSH32(c, 0x00450c13u); f_0044dd70(c); /* call 0x44dd70 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00450e15; /* jmp 0x450e15 */
L_00450c19:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x69u)); /* sub eax, 0x69 */
    if (c->zf) goto L_00450cf3; /* je 0x450cf3 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5u)); /* sub eax, 5 */
    if (c->zf) goto L_00450cc9; /* je 0x450cc9 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00450cb6; /* je 0x450cb6 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00450c86; /* je 0x450c86 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00450a3b; /* je 0x450a3b */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00450cf7; /* je 0x450cf7 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00450e18; /* jne 0x450e18 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x27u)); /* mov dword ptr [ebp - 0x2c], 0x27 */
    goto L_00450c94; /* jmp 0x450c94 */
L_00450c58:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 1)); /* sar eax, 1 */
    goto L_00450e15; /* jmp 0x450e15 */
L_00450c61:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00450c6e; /* jne 0x450c6e */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cc08u))); /* mov ecx, dword ptr [0x46cc08] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00450c6e:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_00450c70:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00450c7f; /* je 0x450c7f */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00450c7f; /* je 0x450c7f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00450c70; /* jmp 0x450c70 */
L_00450c7f:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00450e15; /* jmp 0x450e15 */
L_00450c86:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x10], 8 */
L_00450c8d:;
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x7u)); /* mov dword ptr [ebp - 0x2c], 7 */
L_00450c94:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ebp - 0xc], 0x10 */
    if (c->zf) goto L_00450cfe; /* je 0x450cfe */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffd4u))); /* mov al, byte ptr [ebp - 0x2c] */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebp - 0x16], 0x30 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x51u)); /* add al, 0x51 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x1c], 2 */
    W8((uint32_t)(c->ebp + 0xffffffebu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x15], al */
    goto L_00450cfe; /* jmp 0x450cfe */
L_00450cb6:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0xc], 8 */
    if (c->zf) goto L_00450cfe; /* je 0x450cfe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 3], 2 */
    goto L_00450cfe; /* jmp 0x450cfe */
L_00450cc9:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450cd2u); f_00450fed(c); /* call 0x450fed */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00450ce2; /* je 0x450ce2 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffecu))); /* mov cx, word ptr [ebp - 0x14] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
    goto L_00450ce7; /* jmp 0x450ce7 */
L_00450ce2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00450ce7:;
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_00450f16; /* jmp 0x450f16 */
L_00450cf3:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
L_00450cf7:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp - 0xc], 0xa */
L_00450cfe:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (c->zf) goto L_00450d10; /* je 0x450d10 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450d0du); f_00450ffa(c); /* call 0x450ffa */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00450d51; /* jmp 0x450d51 */
L_00450d10:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    if (c->zf) goto L_00450d37; /* je 0x450d37 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00450d2c; /* je 0x450d2c */
    PUSH32(c, 0x00450d25u); f_00450fed(c); /* call 0x450fed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx eax, ax */
L_00450d29:;
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    goto L_00450d51; /* jmp 0x450d51 */
L_00450d2c:;
    PUSH32(c, 0x00450d31u); f_00450fed(c); /* call 0x450fed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)((uint16_t)c->eax)); /* movzx eax, ax */
    goto L_00450d29; /* jmp 0x450d29 */
L_00450d37:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_00450d49; /* je 0x450d49 */
    PUSH32(c, 0x00450d46u); f_00450fed(c); /* call 0x450fed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00450d29; /* jmp 0x450d29 */
L_00450d49:;
    PUSH32(c, 0x00450d4eu); f_00450fed(c); /* call 0x450fed */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00450d51:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    if (c->zf) goto L_00450d72; /* je 0x450d72 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_00450d72; /* jg 0x450d72 */
    if ((c->sf != c->of)) goto L_00450d61; /* jl 0x450d61 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->cf) goto L_00450d72; /* jae 0x450d72 */
L_00450d61:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(adc32(c, c->edx, (uint32_t)0x0u)); /* adc edx, 0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    goto L_00450d76; /* jmp 0x450d76 */
L_00450d72:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
L_00450d76:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (!c->zf) goto L_00450d7f; /* jne 0x450d7f */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x0u))); /* and edi, 0 */
L_00450d7f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if ((c->sf == c->of)) goto L_00450d8e; /* jge 0x450d8e */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
    goto L_00450d92; /* jmp 0x450d92 */
L_00450d8e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [ebp - 4], 0xfffffff7 */
L_00450d92:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (!c->zf) goto L_00450d9c; /* jne 0x450d9c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
L_00450d9c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00450da2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00450db2; /* jg 0x450db2 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (c->zf) goto L_00450ded; /* je 0x450ded */
L_00450db2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x3c], edx */
    PUSH32(c, 0x00450dc5u); f_00456140(c); /* call 0x456140 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x30u)); /* add ebx, 0x30 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00450dd7u); f_004560d0(c); /* call 0x4560d0 */
    (void)sub32(c, c->ebx, (uint32_t)0x39u); /* cmp ebx, 0x39 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    if ((c->zf || c->sf != c->of)) goto L_00450de3; /* jle 0x450de3 */
    c->ebx = (uint32_t)(add32(c, c->ebx, R32((uint32_t)(c->ebp + 0xffffffd4u)))); /* add ebx, dword ptr [ebp - 0x2c] */
L_00450de3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00450da2; /* jmp 0x450da2 */
L_00450ded:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x2u)); /* test byte ptr [ebp - 3], 2 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if (c->zf) goto L_00450e18; /* je 0x450e18 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x30u); /* cmp byte ptr [ecx], 0x30 */
    if (!c->zf) goto L_00450e0b; /* jne 0x450e0b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00450e18; /* jne 0x450e18 */
L_00450e0b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00450e15:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00450e18:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00450f16; /* jne 0x450f16 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x40u)); /* test bl, 0x40 */
    if (c->zf) goto L_00450e50; /* je 0x450e50 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x1u)); /* test bh, 1 */
    if (c->zf) goto L_00450e35; /* je 0x450e35 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp - 0x16], 0x2d */
    goto L_00450e49; /* jmp 0x450e49 */
L_00450e35:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00450e40; /* je 0x450e40 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2bu)); /* mov byte ptr [ebp - 0x16], 0x2b */
    goto L_00450e49; /* jmp 0x450e49 */
L_00450e40:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00450e50; /* je 0x450e50 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x16], 0x20 */
L_00450e49:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
L_00450e50:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffe4u)))); /* sub esi, dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* sub esi, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0xcu)); /* test bl, 0xc */
    if (!c->zf) goto L_00450e70; /* jne 0x450e70 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00450e6du); f_00450f84(c); /* call 0x450f84 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00450e70:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffeau)); /* lea eax, [ebp - 0x16] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450e83u); f_00450fb5(c); /* call 0x450fb5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00450ea2; /* je 0x450ea2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (!c->zf) goto L_00450ea2; /* jne 0x450ea2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    PUSH32(c, 0x00450e9fu); f_00450f84(c); /* call 0x450f84 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00450ea2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (c->zf) goto L_00450ee9; /* je 0x450ee9 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00450ee9; /* jle 0x450ee9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
L_00450eb7:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    PUSH32(c, 0x00450ec6u); f_00456060(c); /* call 0x456060 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_00450efe; /* jle 0x450efe */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea ecx, [ebp - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450eddu); f_00450fb5(c); /* call 0x450fb5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00450eb7; /* jne 0x450eb7 */
    goto L_00450efe; /* jmp 0x450efe */
L_00450ee9:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x00450efbu); f_00450fb5(c); /* call 0x450fb5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00450efe:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x4u)); /* test byte ptr [ebp - 4], 4 */
    if (c->zf) goto L_00450f16; /* je 0x450f16 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00450f13u); f_00450f84(c); /* call 0x450f84 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00450f16:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) goto L_0045083a; /* jne 0x45083a */
L_00450f27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00450883(CPU *c) { /* PTR_00450883 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_00450f16; /* jmp 0x450f16 */
L_00450f16:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) { jump_indirect(c, 0x0045083au, 0x00450f21u); return; } /* jne 0x45083a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00450f4f(CPU *c) { /* PTR_00450f4f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 4] */
    if (c->sf) goto L_00450f68; /* js 0x450f68 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov al, byte ptr [ebp + 8] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    goto L_00450f73; /* jmp 0x450f73 */
L_00450f68:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00450f71u); f_004506f9(c); /* call 0x4506f9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00450f73:;
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_00450f80; /* jne 0x450f80 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00450f80:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00450f84(CPU *c) { /* PTR_00450f84 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00450fb2; /* jle 0x450fb2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_00450f95:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    PUSH32(c, 0x00450fa3u); f_00450f4f(c); /* call 0x450f4f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi], -1 */
    if (c->zf) goto L_00450fb2; /* je 0x450fb2 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00450f95; /* jg 0x450f95 */
L_00450fb2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00450fb5(CPU *c) { /* PTR_00450fb5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00450fe9; /* jle 0x450fe9 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_00450fcb:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00450fdau); f_00450f4f(c); /* call 0x450f4f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi], -1 */
    if (c->zf) goto L_00450fe9; /* je 0x450fe9 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00450fcb; /* jg 0x450fcb */
L_00450fe9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00450fed(CPU *c) { /* PTR_00450fed */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov eax, dword ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_00450ffa(CPU *c) { /* PTR_00450ffa */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8u))); } /* add dword ptr [eax], 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffff8u))); /* mov eax, dword ptr [ecx - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov edx, dword ptr [ecx - 4] */
    c->esp += 4; return; /* ret  */
}

void f_0045100a(CPU *c) { /* PTR_0045100a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + 0xfffffffcu))); /* mov ax, word ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_00451018(CPU *c) { /* FUN_00451018 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00451029u); f_004511b1(c); /* call 0x4511b1 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, R32((uint32_t)(0x47c6bcu))); /* cmp esi, dword ptr [0x47c6bc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    if (c->zf) goto L_004511a5; /* je 0x4511a5 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_0045119b; /* je 0x45119b */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0x46cc18u); /* mov eax, 0x46cc18 */
L_0045104c:;
    (void)sub32(c, R32((uint32_t)(c->eax)), c->esi); /* cmp dword ptr [eax], esi */
    if (c->zf) goto L_004510c2; /* je 0x4510c2 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x30u)); /* add eax, 0x30 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0x46cd08u); /* cmp eax, 0x46cd08 */
    if ((c->sf != c->of)) goto L_0045104c; /* jl 0x45104c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x45b114u)); PUSH32(c, 0x00451066u); call_indirect(c, t_); } /* call dword ptr [0x45b114] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00451193; /* jne 0x451193 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)((uint32_t)0x47c7e0u); /* mov edi, 0x47c7e0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), (uint32_t)0x1u); /* cmp dword ptr [ebp - 0x18], 1 */
    W32((uint32_t)(0x47c6bcu), (uint32_t)(c->esi)); /* mov dword ptr [0x47c6bc], esi */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    W32((uint32_t)(0x47c8e4u), (uint32_t)(c->ebx)); /* mov dword ptr [0x47c8e4], ebx */
    if ((c->cf || c->zf)) goto L_00451181; /* jbe 0x451181 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffeeu)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x12], 0 */
    if (c->zf) goto L_00451157; /* je 0x451157 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffefu)); /* lea ecx, [ebp - 0x11] */
L_0045109f:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00451157; /* je 0x451157 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + 0xffffffffu))); /* movzx eax, byte ptr [ecx - 1] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
L_004510b0:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((!c->cf && !c->zf)) goto L_0045114b; /* ja 0x45114b */
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x4u)))); } /* or byte ptr [eax + 0x47c7e1], 4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_004510b0; /* jmp 0x4510b0 */
L_004510c2:;
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)((uint32_t)0x47c7e0u); /* mov edi, 0x47c7e0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea esi, [edx + edx*2] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x46cc28u)); /* lea ebx, [esi + 0x46cc28] */
L_004510de:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if (c->zf) goto L_00451111; /* je 0x451111 */
L_004510e5:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00451111; /* je 0x451111 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx eax, byte ptr [ecx] */
    c->edi = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edi, dl */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((!c->cf && !c->zf)) goto L_0045110a; /* ja 0x45110a */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x46cc10u))); /* mov dl, byte ptr [edx + 0x46cc10] */
L_004510ff:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->edx))))); } /* or byte ptr [eax + 0x47c7e1], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_004510ff; /* jbe 0x4510ff */
L_0045110a:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (!c->zf) goto L_004510e5; /* jne 0x4510e5 */
L_00451111:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x4u); /* cmp dword ptr [ebp - 4], 4 */
    if (c->cf) goto L_004510de; /* jb 0x4510de */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0x47c6ccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c6cc], 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x47c6bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6bc], eax */
    PUSH32(c, 0x00451135u); f_004511fb(c); /* call 0x4511fb */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x46cc1cu)); /* lea esi, [esi + 0x46cc1c] */
    c->edi = (uint32_t)((uint32_t)0x47c6c0u); /* mov edi, 0x47c6c0 */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c8e4u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c8e4], eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_004511a0; /* jmp 0x4511a0 */
L_0045114b:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0xffffffffu)), (uint8_t)0x0u); /* cmp byte ptr [ecx - 1], 0 */
    if (!c->zf) goto L_0045109f; /* jne 0x45109f */
L_00451157:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_0045115a:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [eax + 0x47c7e1], 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xffu); /* cmp eax, 0xff */
    if (c->cf) goto L_0045115a; /* jb 0x45115a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0045116fu); f_004511fb(c); /* call 0x4511fb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c8e4u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c8e4], eax */
    W32((uint32_t)(0x47c6ccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c6cc], 1 */
    goto L_00451187; /* jmp 0x451187 */
L_00451181:;
    W32((uint32_t)(0x47c6ccu), (uint32_t)(c->ebx)); /* mov dword ptr [0x47c6cc], ebx */
L_00451187:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x47c6c0u); /* mov edi, 0x47c6c0 */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    goto L_004511a0; /* jmp 0x4511a0 */
L_00451193:;
    (void)sub32(c, R32((uint32_t)(0x47c364u)), c->ebx); /* cmp dword ptr [0x47c364], ebx */
    if (c->zf) goto L_004511a9; /* je 0x4511a9 */
L_0045119b:;
    PUSH32(c, 0x004511a0u); f_0045122e(c); /* call 0x45122e */
L_004511a0:;
    PUSH32(c, 0x004511a5u); f_00451257(c); /* call 0x451257 */
L_004511a5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_004511ac; /* jmp 0x4511ac */
L_004511a9:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_004511ac:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004511b1(CPU *c) { /* FUN_004511b1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0x47c364u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x47c364], 0 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (!c->zf) goto L_004511d1; /* jne 0x4511d1 */
    W32((uint32_t)(0x47c364u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c364], 1 */
    { uint32_t t_ = R32((uint32_t)(0x45b10cu)); switch (t_) {  default: jump_indirect(c, t_, 0x004511cbu); return; } } /* jmp dword ptr [0x45b10c] */
L_004511d1:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_004511e6; /* jne 0x4511e6 */
    W32((uint32_t)(0x47c364u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c364], 1 */
    { uint32_t t_ = R32((uint32_t)(0x45b110u)); switch (t_) {  default: jump_indirect(c, t_, 0x004511e0u); return; } } /* jmp dword ptr [0x45b110] */
L_004511e6:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if (!c->zf) goto L_004511fa; /* jne 0x4511fa */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c520u))); /* mov eax, dword ptr [0x47c520] */
    W32((uint32_t)(0x47c364u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c364], 1 */
L_004511fa:;
    c->esp += 4; return; /* ret  */
}

void f_004511fb(CPU *c) { /* FUN_004511fb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3a4u)); /* sub eax, 0x3a4 */
    if (c->zf) goto L_00451228; /* je 0x451228 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00451222; /* je 0x451222 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xdu)); /* sub eax, 0xd */
    if (c->zf) goto L_0045121c; /* je 0x45121c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00451216; /* je 0x451216 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00451216:;
    c->eax = (uint32_t)((uint32_t)0x404u); /* mov eax, 0x404 */
    c->esp += 4; return; /* ret  */
L_0045121c:;
    c->eax = (uint32_t)((uint32_t)0x412u); /* mov eax, 0x412 */
    c->esp += 4; return; /* ret  */
L_00451222:;
    c->eax = (uint32_t)((uint32_t)0x804u); /* mov eax, 0x804 */
    c->esp += 4; return; /* ret  */
L_00451228:;
    c->eax = (uint32_t)((uint32_t)0x411u); /* mov eax, 0x411 */
    c->esp += 4; return; /* ret  */
}

void f_0045122e(CPU *c) { /* FUN_0045122e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x47c7e0u); /* mov edi, 0x47c7e0 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0x47c6c0u); /* mov edi, 0x47c6c0 */
    W32((uint32_t)(0x47c6bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6bc], eax */
    W32((uint32_t)(0x47c6ccu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6cc], eax */
    W32((uint32_t)(0x47c8e4u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c8e4], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00451257(CPU *c) { /* FUN_00451257 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x514u)); /* sub esp, 0x514 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x47c6bcu)); PUSH32(c, v_); } /* push dword ptr [0x47c6bc] */
    { uint32_t t_ = R32((uint32_t)(0x45b114u)); PUSH32(c, 0x00451271u); call_indirect(c, t_); } /* call dword ptr [0x45b114] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00451390; /* jne 0x451390 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00451281:;
    W8((uint32_t)(c->ebp + c->eax + 0xfffffeecu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + eax - 0x114], al */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00451281; /* jb 0x451281 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff2u))); /* mov al, byte ptr [ebp - 0xe] */
    W8((uint32_t)(c->ebp + 0xfffffeecu), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x114], 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_004512d2; /* je 0x4512d2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff3u)); /* lea edx, [ebp - 0xd] */
L_004512a0:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((!c->cf && !c->zf)) goto L_004512c7; /* ja 0x4512c7 */
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
L_004512c7:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffffu))); /* mov al, byte ptr [edx - 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_004512a0; /* jne 0x4512a0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_004512d2:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea eax, [ebp - 0x514] */
    { uint32_t v_ = R32((uint32_t)(0x47c8e4u)); PUSH32(c, v_); } /* push dword ptr [0x47c8e4] */
    { uint32_t v_ = R32((uint32_t)(0x47c6bcu)); PUSH32(c, v_); } /* push dword ptr [0x47c6bc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x004512f6u); f_00456404(c); /* call 0x456404 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdecu)); /* lea eax, [ebp - 0x214] */
    { uint32_t v_ = R32((uint32_t)(0x47c6bcu)); PUSH32(c, v_); } /* push dword ptr [0x47c6bc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x47c8e4u)); PUSH32(c, v_); } /* push dword ptr [0x47c8e4] */
    PUSH32(c, 0x0045131au); f_004561b5(c); /* call 0x4561b5 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffcecu)); /* lea eax, [ebp - 0x314] */
    { uint32_t v_ = R32((uint32_t)(0x47c6bcu)); PUSH32(c, v_); } /* push dword ptr [0x47c6bc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0x47c8e4u)); PUSH32(c, v_); } /* push dword ptr [0x47c8e4] */
    PUSH32(c, 0x00451342u); f_004561b5(c); /* call 0x4561b5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea ecx, [ebp - 0x514] */
L_0045134d:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx))); /* mov dx, word ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    if (c->zf) goto L_0045136b; /* je 0x45136b */
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x47c7e1], 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffdecu))); /* mov dl, byte ptr [ebp + eax - 0x214] */
L_00451363:;
    W8((uint32_t)(c->eax + 0x47c6e0u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x47c6e0], dl */
    goto L_00451387; /* jmp 0x451387 */
L_0045136b:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x2u)); /* test dl, 2 */
    if (c->zf) goto L_00451380; /* je 0x451380 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x47c7e1], 0x20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffcecu))); /* mov dl, byte ptr [ebp + eax - 0x314] */
    goto L_00451363; /* jmp 0x451363 */
L_00451380:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c6e0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x47c6e0], 0 */
L_00451387:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_0045134d; /* jb 0x45134d */
    goto L_004513d9; /* jmp 0x4513d9 */
L_00451390:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00451397:;
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if (c->cf) goto L_004513b5; /* jb 0x4513b5 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->cf && !c->zf)) goto L_004513b5; /* ja 0x4513b5 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x47c7e1], 0x10 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_004513ad:;
    W8((uint32_t)(c->eax + 0x47c6e0u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x47c6e0], cl */
    goto L_004513d4; /* jmp 0x4513d4 */
L_004513b5:;
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if (c->cf) goto L_004513cd; /* jb 0x4513cd */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->cf && !c->zf)) goto L_004513cd; /* ja 0x4513cd */
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c7e1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x47c7e1], 0x20 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    goto L_004513ad; /* jmp 0x4513ad */
L_004513cd:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x47c6e0u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x47c6e0], 0 */
L_004513d4:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00451397; /* jb 0x451397 */
L_004513d9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004513dc(CPU *c) { /* PTR_004513dc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6ccu))); /* mov eax, dword ptr [0x47c6cc] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x47c6bcu))))); /* and eax, dword ptr [0x47c6bc] */
    c->esp += 4; return; /* ret  */
}

void f_004513ec(CPU *c) { /* FUN_004513ec */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x47c6b0u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c6b0], 0 */
    if (!c->zf) goto L_00451407; /* jne 0x451407 */
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    PUSH32(c, 0x004513fcu); f_00451018(c); /* call 0x451018 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c6b0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c6b0], 1 */
L_00451407:;
    c->esp += 4; return; /* ret  */
}

void f_00451408(CPU *c) { /* FUN_00451408 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(0x47c6ccu)), (uint32_t)0x0u); /* cmp dword ptr [0x47c6cc], 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
    if (!c->zf) goto L_0045142c; /* jne 0x45142c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00451427u); f_0044e6e0(c); /* call 0x44e6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_0045148f; /* jmp 0x45148f */
L_0045142c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00451471; /* je 0x451471 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
L_00451437:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx esi, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + 0x47c7e1u)) & (uint8_t)0x4u)); /* test byte ptr [esi + 0x47c7e1], 4 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    if (c->zf) goto L_0045145b; /* je 0x45145b */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00451467; /* je 0x451467 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0045146d; /* je 0x45146d */
    goto L_00451461; /* jmp 0x451461 */
L_0045145b:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00451471; /* je 0x451471 */
L_00451461:;
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_00451437; /* jne 0x451437 */
    goto L_00451471; /* jmp 0x451471 */
L_00451467:;
    { uint32_t a_ = (uint32_t)(c->edi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [edi - 1], 0 */
    goto L_00451471; /* jmp 0x451471 */
L_0045146d:;
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [edi - 2], 0 */
L_00451471:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_0045148c; /* je 0x45148c */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0x1u)); /* lea ecx, [edx + 1] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    while (c->ecx) { W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); c->ecx--; } /* rep stosb byte ptr es:[edi], al */
L_0045148c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
L_0045148f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00451492(CPU *c) { /* FUN_00451492 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004514b3u); f_004569e1(c); /* call 0x4569e1 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_004514ca; /* je 0x4514ca */
    c->edi = (uint32_t)((uint32_t)0x200u); /* mov edi, 0x200 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    goto L_004514f8; /* jmp 0x4514f8 */
L_004514ca:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004514d7u); f_004568b3(c); /* call 0x4568b3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_004514e3; /* jne 0x4514e3 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_004514e8; /* jne 0x4514e8 */
L_004514e3:;
    c->edi = (uint32_t)((uint32_t)0x80u); /* mov edi, 0x80 */
L_004514e8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_004514f2; /* jne 0x4514f2 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_004514f8; /* jne 0x4514f8 */
L_004514f2:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0x100u))); /* or edi, 0x100 */
L_004514f8:;
    c->eax = (uint32_t)(R32((uint32_t)(0x46cd08u))); /* mov eax, dword ptr [0x46cd08] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u)))); /* sub eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd08u))); /* mov ecx, dword ptr [0x46cd08] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x46cd08u))); /* mov eax, dword ptr [0x46cd08] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    WF64((uint32_t)(c->eax + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [eax + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(0x46cd08u))); /* mov eax, dword ptr [0x46cd08] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00451523(CPU *c) { /* FUN_00451523 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_00451541; /* ja 0x451541 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov ecx, dword ptr [0x46cd0c] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_00451593; /* jmp 0x451593 */
L_00451541:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov esi, dword ptr [0x46cd0c] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00451566; /* je 0x451566 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_0045156f; /* jmp 0x45156f */
L_00451566:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_0045156f:;
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
    PUSH32(c, 0x00451586u); f_00456404(c); /* call 0x456404 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0045158f; /* jne 0x45158f */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0045158f:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_00451593:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004515a0(CPU *c) { /* PTR_004515a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_004515b9; /* jne 0x4515b9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_004515b9:;
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

void f_004515d4(CPU *c) { /* FUN_004515d4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x004515e3u); f_00456f4a(c); /* call 0x456f4a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_004515e6(CPU *c) { /* FUN_004515e6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x45bd58u))); /* fld qword ptr [0x45bd58] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x45bd50u))); /* fld qword ptr [0x45bd50] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc48u))); FPOP(c); /* fcomp qword ptr [0x45bc48] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00451620; /* jbe 0x451620 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00451620:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00451624(CPU *c) { /* FUN_00451624 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x45bd7cu; PUSH32(c, v_); } /* push 0x45bd7c */
    { uint32_t t_ = R32((uint32_t)(0x45b12cu)); PUSH32(c, 0x0045162fu); call_indirect(c, t_); } /* call dword ptr [0x45b12c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451648; /* je 0x451648 */
    { uint32_t v_ = 0x45bd60u; PUSH32(c, v_); } /* push 0x45bd60 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b144u)); PUSH32(c, 0x0045163fu); call_indirect(c, t_); } /* call dword ptr [0x45b144] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451648; /* je 0x451648 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00451647u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00451648:;
    { f_004515e6(c); return; } /* jmp 0x4515e6 */
}

void f_0045164d(CPU *c) { /* FUN_0045164d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045165bu); f_004570e2(c); /* call 0x4570e2 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0045168d; /* je 0x45168d */
L_00451661:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x46cf18u)), (uint32_t)0x1u); /* cmp dword ptr [0x46cf18], 1 */
    if ((c->zf || c->sf != c->of)) goto L_0045167a; /* jle 0x45167a */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00451676u); f_00451523(c); /* call 0x451523 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00451689; /* jmp 0x451689 */
L_0045167a:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46cd0cu))); /* mov ecx, dword ptr [0x46cd0c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00451689:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00451661; /* jne 0x451661 */
L_0045168d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x46cf1cu))); /* mov cl, byte ptr [0x46cf1c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00451698:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00451698; /* jne 0x451698 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_004516a7(CPU *c) { /* PTR_004516a7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x46cf1cu))); /* mov dl, byte ptr [0x46cf1c] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_004516c3; /* je 0x4516c3 */
L_004516b7:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_004516c3; /* je 0x4516c3 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_004516b7; /* jne 0x4516b7 */
L_004516c3:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_004516f4; /* je 0x4516f4 */
L_004516ca:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_004516dd; /* je 0x4516dd */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_004516dd; /* je 0x4516dd */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_004516dd; /* je 0x4516dd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_004516ca; /* jmp 0x4516ca */
L_004516dd:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_004516df:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_004516df; /* je 0x4516df */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_004516ea; /* jne 0x4516ea */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_004516ea:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_004516ea; /* jne 0x4516ea */
L_004516f4:;
    c->esp += 4; return; /* ret  */
}

void f_004516f5(CPU *c) { /* PTR_004516f5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_0045170a; /* jb 0x45170a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_0045170a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_0045170d(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00451736; /* je 0x451736 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00451724u); f_00456959(c); /* call 0x456959 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00451736:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045173fu); f_004569b4(c); /* call 0x4569b4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045174b(CPU *c) { /* FUN_0045174b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub8(c, R8((uint32_t)(0x47c384u)), (uint8_t)0x0u); /* cmp byte ptr [0x47c384], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    if (c->zf) goto L_00451780; /* je 0x451780 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c380u))); /* mov eax, dword ptr [0x47c380] */
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
    PUSH32(c, 0x0045177cu); f_00451a63(c); /* call 0x451a63 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_004517b8; /* jmp 0x4517b8 */
L_00451780:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0045178fu); f_00457224(c); /* call 0x457224 */
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
    PUSH32(c, 0x004517b5u); f_004571ad(c); /* call 0x4571ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_004517b8:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_004517c4; /* jne 0x4517c4 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [eax], 0x2d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_004517c4:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_004517dc; /* jle 0x4517dc */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edi, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x46cf1cu))); /* mov cl, byte ptr [0x46cf1c] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_004517dc:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    { uint32_t v_ = 0x45bd88u; PUSH32(c, v_); } /* push 0x45bd88 */
    (void)sub8(c, R8((uint32_t)(0x47c384u)), ((uint8_t)c->ecx)); /* cmp byte ptr [0x47c384], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x004517f6u); f_0044dc50(c); /* call 0x44dc50 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00451803; /* je 0x451803 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00451803:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00451848; /* je 0x451848 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00451817; /* jns 0x451817 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00451817:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_0045182e; /* jl 0x45182e */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00451823u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0045182au, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_0045182e:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00451845; /* jl 0x451845 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0045183au, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00451841u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00451845:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00451848:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0045184f(CPU *c) { /* FUN_0045184f */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(0x47c384u)), (uint8_t)0x0u); /* cmp byte ptr [0x47c384], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebp, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_0045188a; /* je 0x45188a */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c388u))); /* mov eax, dword ptr [0x47c388] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov ebx, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(0x47c380u))); /* mov esi, dword ptr [0x47c380] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_004518ba; /* jne 0x4518ba */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebp)); /* add ecx, ebp */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
    goto L_004518ba; /* jmp 0x4518ba */
L_0045188a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0045189au); f_00457224(c); /* call 0x457224 */
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
    PUSH32(c, 0x004518b7u); f_004571ad(c); /* call 0x4571ad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_004518ba:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebp); /* mov edi, ebp */
    if (!c->zf) goto L_004518c8; /* jne 0x4518c8 */
    W8((uint32_t)(c->ebp), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x1u)); /* lea edi, [ebp + 1] */
L_004518c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_004518df; /* jg 0x4518df */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004518d7u); f_00451a63(c); /* call 0x451a63 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_004518e1; /* jmp 0x4518e1 */
L_004518df:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_004518e1:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00451926; /* jle 0x451926 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004518edu); f_00451a63(c); /* call 0x451a63 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x46cf1cu))); /* mov al, byte ptr [0x46cf1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00451926; /* jge 0x451926 */
    (void)sub8(c, R8((uint32_t)(0x47c384u)), (uint8_t)0x0u); /* cmp byte ptr [0x47c384], 0 */
    if (c->zf) goto L_0045190b; /* je 0x45190b */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00451911; /* jmp 0x451911 */
L_0045190b:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->sf != c->of)) goto L_00451913; /* jl 0x451913 */
L_00451911:;
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_00451913:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0045191au); f_00451a63(c); /* call 0x451a63 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00451923u); f_0044d730(c); /* call 0x44d730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00451926:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_0045192d(CPU *c) { /* FUN_0045192d */
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
    PUSH32(c, 0x00451942u); f_00457224(c); /* call 0x457224 */
    W32((uint32_t)(0x47c380u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c380], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(0x47c388u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c388], ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x2du); /* cmp dword ptr [eax], 0x2d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00451969u); f_004571ad(c); /* call 0x4571ad */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c380u))); /* mov eax, dword ptr [0x47c380] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, R32((uint32_t)(0x47c388u)), c->ecx); /* cmp dword ptr [0x47c388], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    W8((uint32_t)(0x47c38cu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [0x47c38c], cl */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    W32((uint32_t)(0x47c388u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c388], eax */
    if ((c->sf != c->of)) goto L_004519b3; /* jl 0x4519b3 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_004519b3; /* jge 0x4519b3 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_004519a4; /* je 0x4519a4 */
L_0045199a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_0045199a; /* jne 0x45199a */
    { uint32_t a_ = (uint32_t)(c->esi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [esi - 2], al */
L_004519a4:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004519aeu); f_004519ef(c); /* call 0x4519ef */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_004519c3; /* jmp 0x4519c3 */
L_004519b3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004519c0u); f_004519c8(c); /* call 0x4519c8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_004519c3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_004519c8(CPU *c) { /* FUN_004519c8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    W8((uint32_t)(0x47c384u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [0x47c384], 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x004519e4u); f_0045174b(c); /* call 0x45174b */
    { uint32_t a_ = (uint32_t)(0x47c384u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [0x47c384], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_004519ef(CPU *c) { /* FUN_004519ef */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    W8((uint32_t)(0x47c384u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [0x47c384], 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00451a07u); f_0045184f(c); /* call 0x45184f */
    { uint32_t a_ = (uint32_t)(0x47c384u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [0x47c384], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00451a12(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00451a4d; /* je 0x451a4d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00451a4d; /* je 0x451a4d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00451a3a; /* jne 0x451a3a */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00451a35u); f_0045184f(c); /* call 0x45184f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00451a3a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00451a4bu); f_0045192d(c); /* call 0x45192d */
    goto L_00451a5e; /* jmp 0x451a5e */
L_00451a4d:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00451a5eu); f_0045174b(c); /* call 0x45174b */
L_00451a5e:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00451a63(CPU *c) { /* FUN_00451a63 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00451a86; /* je 0x451a86 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00451a77u); f_0044dd70(c); /* call 0x44dd70 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00451a82u); f_00455840(c); /* call 0x455840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00451a86:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00451a88(CPU *c) { /* FUN_00451a88 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x46c8e8u))); /* mov eax, dword ptr [0x46c8e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451a93; /* je 0x451a93 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00451a93u); call_indirect(c, t_); } /* call eax */
L_00451a93:;
    { uint32_t v_ = 0x45f040u; PUSH32(c, v_); } /* push 0x45f040 */
    { uint32_t v_ = 0x45f02cu; PUSH32(c, v_); } /* push 0x45f02c */
    PUSH32(c, 0x00451aa2u); f_00451b8e(c); /* call 0x451b8e */
    { uint32_t v_ = 0x45f028u; PUSH32(c, v_); } /* push 0x45f028 */
    { uint32_t v_ = 0x45f000u; PUSH32(c, v_); } /* push 0x45f000 */
    PUSH32(c, 0x00451ab1u); f_00451b8e(c); /* call 0x451b8e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00451ab5(CPU *c) { /* FUN_00451ab5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00451ac2u); f_00451af5(c); /* call 0x451af5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00451ac6(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00451ad3u); f_00451af5(c); /* call 0x451af5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00451ad7(CPU *c) { /* PTR_00451ad7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00451ae2u); f_00451af5(c); /* call 0x451af5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00451af5(CPU *c) { /* FUN_00451af5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x47c3d8u)), c->edi); /* cmp dword ptr [0x47c3d8], edi */
    if (!c->zf) goto L_00451b12; /* jne 0x451b12 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x45b104u)); PUSH32(c, 0x00451b0bu); call_indirect(c, t_); } /* call dword ptr [0x45b104] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b108u)); PUSH32(c, 0x00451b12u); call_indirect(c, t_); } /* call dword ptr [0x45b108] */
L_00451b12:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x47c3d4u), (uint32_t)(c->edi)); /* mov dword ptr [0x47c3d4], edi */
    W8((uint32_t)(0x47c3d0u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x47c3d0], bl */
    if (!c->zf) goto L_00451b66; /* jne 0x451b66 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6b8u))); /* mov eax, dword ptr [0x47c6b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451b55; /* je 0x451b55 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c6b4u))); /* mov ecx, dword ptr [0x47c6b4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00451b54; /* jb 0x451b54 */
L_00451b41:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451b49; /* je 0x451b49 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00451b49u); call_indirect(c, t_); } /* call eax */
L_00451b49:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x47c6b8u))); /* cmp esi, dword ptr [0x47c6b8] */
    if (!c->cf) goto L_00451b41; /* jae 0x451b41 */
L_00451b54:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00451b55:;
    { uint32_t v_ = 0x45f04cu; PUSH32(c, v_); } /* push 0x45f04c */
    { uint32_t v_ = 0x45f044u; PUSH32(c, v_); } /* push 0x45f044 */
    PUSH32(c, 0x00451b64u); f_00451b8e(c); /* call 0x451b8e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00451b66:;
    { uint32_t v_ = 0x45f058u; PUSH32(c, v_); } /* push 0x45f058 */
    { uint32_t v_ = 0x45f050u; PUSH32(c, v_); } /* push 0x45f050 */
    PUSH32(c, 0x00451b75u); f_00451b8e(c); /* call 0x451b8e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (!c->zf) goto L_00451b8c; /* jne 0x451b8c */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x47c3d8u), (uint32_t)(c->edi)); /* mov dword ptr [0x47c3d8], edi */
    { uint32_t t_ = R32((uint32_t)(0x45b15cu)); PUSH32(c, 0x00451b8cu); call_indirect(c, t_); } /* call dword ptr [0x45b15c] */
L_00451b8c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00451b8e(CPU *c) { /* FUN_00451b8e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00451b93:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00451ba6; /* jae 0x451ba6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451ba1; /* je 0x451ba1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00451ba1u); call_indirect(c, t_); } /* call eax */
L_00451ba1:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00451b93; /* jmp 0x451b93 */
L_00451ba6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00451ba8(CPU *c) { /* FUN_00451ba8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6a8u))); /* mov eax, dword ptr [0x47c6a8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00451bd1; /* jne 0x451bd1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00451bc1u); f_004535f0(c); /* call 0x4535f0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00451bce; /* je 0x451bce */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    goto L_00451c06; /* jmp 0x451c06 */
L_00451bce:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00451bf8; /* jmp 0x451bf8 */
L_00451bd1:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00451bf5; /* jne 0x451bf5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00451be6u); f_0045476d(c); /* call 0x45476d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00451bf5; /* je 0x451bf5 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx eax, byte ptr [eax] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    goto L_00451c06; /* jmp 0x451c06 */
L_00451bf5:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
L_00451bf8:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b100u)); PUSH32(c, 0x00451c06u); call_indirect(c, t_); } /* call dword ptr [0x45b100] */
L_00451c06:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00451c09(CPU *c) { /* FUN_00451c09 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xffffu); /* mov esi, 0xffff */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x133fu; PUSH32(c, v_); } /* push 0x133f */
    PUSH32(c, 0x00451c21u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00451ca3; /* jne 0x451ca3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451c3fu); f_00451e7c(c); /* call 0x451e7c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_00451c75; /* jle 0x451c75 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if ((c->zf || c->sf != c->of)) goto L_00451cae; /* jle 0x451cae */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00451c75; /* jne 0x451c75 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0x10u))); /* fild dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00451c6du); f_00451fea(c); /* call 0x451fea */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00451deb; /* jmp 0x451deb */
L_00451c75:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x45bc48u))); /* fadd qword ptr [0x45bc48] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0x10u))); /* fild dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_00451dc3; /* jmp 0x451dc3 */
L_00451ca3:;
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00451cbf; /* jne 0x451cbf */
L_00451cae:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00451cb5u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00451deb; /* jmp 0x451deb */
L_00451cbf:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451cd0u); f_00451ed6(c); /* call 0x451ed6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if ((c->sf == c->of)) goto L_00451ce1; /* jge 0x451ce1 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_00451ce1:;
    (void)sub32(c, c->ecx, (uint32_t)0x7fffffffu); /* cmp ecx, 0x7fffffff */
    if ((!c->zf && c->sf == c->of)) goto L_00451cee; /* jg 0x451cee */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_00451cee:;
    (void)sub32(c, c->eax, (uint32_t)0xa00u); /* cmp eax, 0xa00 */
    if ((c->zf || c->sf != c->of)) goto L_00451d32; /* jle 0x451d32 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451d0eu); f_0044e975(c); /* call 0x44e975 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0x10u))); /* fild dword ptr [ebp + 0x10] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
L_00451d1c:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    goto L_00451dc3; /* jmp 0x451dc3 */
L_00451d32:;
    (void)sub32(c, c->eax, (uint32_t)0x400u); /* cmp eax, 0x400 */
    if ((c->zf || c->sf != c->of)) goto L_00451d66; /* jle 0x451d66 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffa00u)); /* add eax, 0xfffffa00 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451d4cu); f_00451def(c); /* call 0x451def */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0x10u))); /* fild dword ptr [ebp + 0x10] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00451d1c; /* jmp 0x451d1c */
L_00451d66:;
    (void)sub32(c, c->eax, (uint32_t)0xfffff603u); /* cmp eax, 0xfffff603 */
    if ((c->sf == c->of)) goto L_00451d80; /* jge 0x451d80 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, 0.0); /* fldz  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0x10u))); /* fild dword ptr [ebp + 0x10] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00451db2; /* jmp 0x451db2 */
L_00451d80:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffc03u); /* cmp eax, 0xfffffc03 */
    if ((c->sf == c->of)) goto L_00451dcd; /* jge 0x451dcd */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x600u)); /* add eax, 0x600 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451d9au); f_00451def(c); /* call 0x451def */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ebp + 0x10u))); /* fild dword ptr [ebp + 0x10] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
L_00451db2:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
L_00451dc3:;
    PUSH32(c, 0x00451dc8u); f_004520e1(c); /* call 0x4520e1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    goto L_00451deb; /* jmp 0x451deb */
L_00451dcd:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451ddbu); f_00451def(c); /* call 0x451def */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00451de5u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00451deb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00451def(CPU *c) { /* FUN_00451def */
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

void f_00451e18(CPU *c) { /* PTR_00451e18 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xau))); /* mov eax, dword ptr [esp + 0xa] */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ffu))); /* and ax, 0x7ff */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3feu)); /* sub eax, 0x3fe */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx eax, ax */
    c->esp += 4; return; /* ret  */
}

void f_00451e58(CPU *c) { /* FUN_00451e58 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov ecx, dword ptr [ebp + 0xe] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ecx) & (uint16_t)0x800fu))); /* and cx, 0x800f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
    W16((uint32_t)(c->ebp + 0xfffffffeu), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 2], ax */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00451e7c(CPU *c) { /* FUN_00451e7c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x7ff00000u); /* cmp dword ptr [ebp + 0xc], 0x7ff00000 */
    if (!c->zf) goto L_00451e93; /* jne 0x451e93 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_00451ea5; /* jne 0x451ea5 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_00451ecf; /* jmp 0x451ecf */
L_00451e93:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0xfff00000u); /* cmp dword ptr [ebp + 0xc], 0xfff00000 */
    if (!c->zf) goto L_00451ea5; /* jne 0x451ea5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_00451ea5; /* jne 0x451ea5 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00451ecf; /* jmp 0x451ecf */
L_00451ea5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov ecx, dword ptr [ebp + 0xe] */
    c->eax = (uint32_t)((uint32_t)0x7ff8u); /* mov eax, 0x7ff8 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->eax))); /* and ecx, eax */
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_00451eb8; /* jne 0x451eb8 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00451ecf; /* jmp 0x451ecf */
L_00451eb8:;
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7ff0u); /* cmp cx, 0x7ff0 */
    if (!c->zf) goto L_00451ed2; /* jne 0x451ed2 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0x7ffffu)); /* test dword ptr [ebp + 0xc], 0x7ffff */
    if (!c->zf) goto L_00451ecd; /* jne 0x451ecd */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (c->zf) goto L_00451ed2; /* je 0x451ed2 */
L_00451ecd:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
L_00451ecf:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00451ed2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00451ed6(CPU *c) { /* FUN_00451ed6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00451ef6; /* jne 0x451ef6 */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    goto L_00451f8c; /* jmp 0x451f8c */
L_00451ef6:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xeu)) & (uint16_t)0x7ff0u)); /* test word ptr [ebp + 0xe], 0x7ff0 */
    if (!c->zf) goto L_00451f65; /* jne 0x451f65 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp + 0xc], 0xfffff */
    if (!c->zf) goto L_00451f0e; /* jne 0x451f0e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->ecx); /* cmp dword ptr [ebp + 8], ecx */
    if (c->zf) goto L_00451f65; /* je 0x451f65 */
L_00451f0e:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->esi = (uint32_t)((uint32_t)0xfffffc03u); /* mov esi, 0xfffffc03 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00451f26; /* jae 0x451f26 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00451f28; /* jmp 0x451f28 */
L_00451f26:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00451f28:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xeu)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0xe], 0x10 */
    if (!c->zf) goto L_00451f41; /* jne 0x451f41 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp + 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xbu)) & (uint8_t)0x80u)); /* test byte ptr [ebp + 0xb], 0x80 */
    if (c->zf) goto L_00451f3b; /* je 0x451f3b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp + 0xc], 1 */
L_00451f3b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp + 8], 1 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    goto L_00451f28; /* jmp 0x451f28 */
L_00451f41:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xeu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0xffefu)))); } /* and word ptr [ebp + 0xe], 0xffef */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00451f4f; /* je 0x451f4f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp + 0xf], 0x80 */
L_00451f4f:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451f5du); f_00451def(c); /* call 0x451def */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00451f8c; /* jmp 0x451f8c */
L_00451f65:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00451f73u); f_00451def(c); /* call 0x451def */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ffu))); /* and ax, 0x7ff */
    c->esi = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx esi, ax */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3feu)); /* sub esi, 0x3fe */
L_00451f8c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00451f97(CPU *c) { /* FUN_00451f97 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(0x46f430u)), (uint32_t)0x0u); /* cmp dword ptr [0x46f430], 0 */
    if (!c->zf) goto L_00451fcc; /* jne 0x451fcc */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xcu))); /* fld qword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, 0.0); /* fldz  */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xcu))); /* fld qword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00451fc7u); f_00452650(c); /* call 0x452650 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00451fcc:;
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x21u)); /* mov dword ptr [0x47c390], 0x21 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    PUSH32(c, 0x00451fe3u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xcu))); /* fld qword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00451fea(CPU *c) { /* FUN_00451fea */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xcu))); /* fld qword ptr [ebp + 0xc] */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(c->ebp + 0x14u))); /* fadd qword ptr [ebp + 0x14] */
    (void)sub32(c, R32((uint32_t)(0x46f430u)), (uint32_t)0x0u); /* cmp dword ptr [0x46f430], 0 */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    if (!c->zf) goto L_0045202b; /* jne 0x45202b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x14u))); /* fld qword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xcu))); /* fld qword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00452026u); f_00452650(c); /* call 0x452650 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0045202b:;
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x21u)); /* mov dword ptr [0x47c390], 0x21 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    PUSH32(c, 0x00452042u); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452049(CPU *c) { /* FUN_00452049 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x58u)); /* sub esp, 0x58 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x18u)); /* lea eax, [ebp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0045205eu); f_00452439(c); /* call 0x452439 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00452087; /* jne 0x452087 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x18u)); /* lea eax, [ebp + 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [ebp - 0x20], 0xfffffffe */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x20u)); /* lea eax, [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa8u)); /* lea eax, [ebp - 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00452084u); f_00452186(c); /* call 0x452186 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00452087:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x0045208fu); f_00452723(c); /* call 0x452723 */
    (void)sub32(c, R32((uint32_t)(0x46f430u)), (uint32_t)0x0u); /* cmp dword ptr [0x46f430], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_004520c5; /* jne 0x4520c5 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004520c5; /* je 0x4520c5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x18u))); /* fld qword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, 0.0); /* fldz  */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004520c0u); f_00452650(c); /* call 0x452650 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004520c5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004520cbu); f_004526d8(c); /* call 0x4526d8 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0xffffu)); /* mov dword ptr [esp], 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    PUSH32(c, 0x004520dau); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x18u))); /* fld qword ptr [ebp + 0x18] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004520e1(CPU *c) { /* FUN_004520e1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x58u)); /* sub esp, 0x58 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x28u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x28] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x20u)); /* lea eax, [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x004520f6u); f_00452439(c); /* call 0x452439 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0045212b; /* jne 0x45212b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xe3u))); /* and al, 0xe3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3u))); /* or al, 3 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x20u)); /* lea eax, [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x28u)); /* lea eax, [ebp + 0x28] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x18u))); /* fld qword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    WF64((uint32_t)(c->ebp + 0xffffffd0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa8u)); /* lea eax, [ebp - 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00452128u); f_00452186(c); /* call 0x452186 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_0045212b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00452133u); f_00452723(c); /* call 0x452723 */
    (void)sub32(c, R32((uint32_t)(0x46f430u)), (uint32_t)0x0u); /* cmp dword ptr [0x46f430], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_0045216a; /* jne 0x45216a */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0045216a; /* je 0x45216a */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x28u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x28] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x20u))); /* fld qword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x18u))); /* fld qword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00452165u); f_00452650(c); /* call 0x452650 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0045216a:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00452170u); f_004526d8(c); /* call 0x4526d8 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0xffffu)); /* mov dword ptr [esp], 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x28u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x28] */
    PUSH32(c, 0x0045217fu); f_0045276d(c); /* call 0x45276d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x20u))); /* fld qword ptr [ebp + 0x20] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452186(CPU *c) { /* FUN_00452186 */
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
    if (c->zf) goto L_004521b8; /* je 0x4521b8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008fu)); /* mov dword ptr [ebp + 0x10], 0xc000008f */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 4], ebx */
L_004521b8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_004521cb; /* je 0x4521cb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000093u)); /* mov dword ptr [ebp + 0x10], 0xc0000093 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [eax + 4], 2 */
L_004521cb:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ecx))); /* test bl, cl */
    if (c->zf) goto L_004521dd; /* je 0x4521dd */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000091u)); /* mov dword ptr [ebp + 0x10], 0xc0000091 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [eax + 4], 4 */
L_004521dd:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_004521f0; /* je 0x4521f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008eu)); /* mov dword ptr [ebp + 0x10], 0xc000008e */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [eax + 4], 8 */
L_004521f0:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00452203; /* je 0x452203 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000090u)); /* mov dword ptr [ebp + 0x10], 0xc0000090 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [eax + 4], 0x10 */
L_00452203:;
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
    PUSH32(c, 0x00452281u); f_00452750(c); /* call 0x452750 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_0045228c; /* je 0x45228c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ecx + 0xc], 0x10 */
L_0045228c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00452297; /* je 0x452297 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ecx + 0xc], 8 */
L_00452297:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_004522a2; /* je 0x4522a2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ecx + 0xc], 4 */
L_004522a2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_004522ac; /* je 0x4522ac */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 0xc], edi */
L_004522ac:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x20u)); /* test al, 0x20 */
    if (c->zf) goto L_004522b6; /* je 0x4522b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 0xc], ebx */
L_004522b6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0xc00u); /* mov ecx, 0xc00 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_004522f5; /* je 0x4522f5 */
    (void)sub32(c, c->eax, (uint32_t)0x400u); /* cmp eax, 0x400 */
    if (c->zf) goto L_004522e7; /* je 0x4522e7 */
    (void)sub32(c, c->eax, (uint32_t)0x800u); /* cmp eax, 0x800 */
    if (c->zf) goto L_004522db; /* je 0x4522db */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_004522fb; /* jne 0x4522fb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x3u)))); } /* or dword ptr [eax], 3 */
    goto L_004522fb; /* jmp 0x4522fb */
L_004522db:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffeu))); /* and ecx, 0xfffffffe */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    goto L_004522f1; /* jmp 0x4522f1 */
L_004522e7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffdu))); /* and ecx, 0xfffffffd */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
L_004522f1:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    goto L_004522fb; /* jmp 0x4522fb */
L_004522f5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffcu)))); } /* and dword ptr [eax], 0xfffffffc */
L_004522fb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0x300u); /* mov ecx, 0x300 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00452326; /* je 0x452326 */
    (void)sub32(c, c->eax, (uint32_t)0x200u); /* cmp eax, 0x200 */
    if (c->zf) goto L_00452319; /* je 0x452319 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00452333; /* jne 0x452333 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffe3u)))); } /* and dword ptr [eax], 0xffffffe3 */
    goto L_00452333; /* jmp 0x452333 */
L_00452319:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe7u))); /* and ecx, 0xffffffe7 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x4u))); /* or ecx, 4 */
    goto L_00452331; /* jmp 0x452331 */
L_00452326:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffebu))); /* and ecx, 0xffffffeb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x8u))); /* or ecx, 8 */
L_00452331:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00452333:;
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
    PUSH32(c, 0x00452391u); f_0045275e(c); /* call 0x45275e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0x45b13cu)); PUSH32(c, 0x004523a1u); call_indirect(c, t_); } /* call dword ptr [0x45b13c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [eax + 8], 0x10 */
    if (c->zf) goto L_004523ad; /* je 0x4523ad */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [esi], 0xfffffffe */
L_004523ad:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x8u)); /* test byte ptr [eax + 8], 8 */
    if (c->zf) goto L_004523b6; /* je 0x4523b6 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffbu)))); } /* and dword ptr [esi], 0xfffffffb */
L_004523b6:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x4u)); /* test byte ptr [eax + 8], 4 */
    if (c->zf) goto L_004523bf; /* je 0x4523bf */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [esi], 0xfffffff7 */
L_004523bf:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x2u)); /* test byte ptr [eax + 8], 2 */
    if (c->zf) goto L_004523c8; /* je 0x4523c8 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffefu)))); } /* and dword ptr [esi], 0xffffffef */
L_004523c8:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & ((uint8_t)c->ebx))); /* test byte ptr [eax + 8], bl */
    if (c->zf) goto L_004523d0; /* je 0x4523d0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffdfu)))); } /* and dword ptr [esi], 0xffffffdf */
L_004523d0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)0xfffff3ffu); /* mov edx, 0xfffff3ff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00452404; /* je 0x452404 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_004523f8; /* je 0x4523f8 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_004523ee; /* je 0x4523ee */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00452406; /* jne 0x452406 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xcu)))); } /* or byte ptr [esi + 1], 0xc */
    goto L_00452406; /* jmp 0x452406 */
L_004523ee:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xfbu))) << 8); /* and ch, 0xfb */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x8u))) << 8); /* or ch, 8 */
    goto L_00452400; /* jmp 0x452400 */
L_004523f8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xf7u))) << 8); /* and ch, 0xf7 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x4u))) << 8); /* or ch, 4 */
L_00452400:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    goto L_00452406; /* jmp 0x452406 */
L_00452404:;
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
L_00452406:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7u))); /* and ecx, 7 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00452426; /* je 0x452426 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_0045241d; /* je 0x45241d */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0045242f; /* jne 0x45242f */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
    goto L_0045242f; /* jmp 0x45242f */
L_0045241d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x2u))) << 8); /* or ch, 2 */
    goto L_0045242d; /* jmp 0x45242d */
L_00452426:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x3u))) << 8); /* or ch, 3 */
L_0045242d:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_0045242f:;
    FPUSH(c, RF64((uint32_t)(c->eax + 0x40u))); /* fld qword ptr [eax + 0x40] */
    WF64((uint32_t)(c->edi), ST(0)); FPOP(c); /* fstp qword ptr [edi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00452439(CPU *c) { /* FUN_00452439 */
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
    if (c->zf) goto L_00452464; /* je 0x452464 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp + 0x10], bl */
    if (c->zf) goto L_00452464; /* je 0x452464 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0045245bu); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffff7u))); /* and edi, 0xfffffff7 */
    goto L_0045262e; /* jmp 0x45262e */
L_00452464:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_0045247e; /* je 0x45247e */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0x10], 4 */
    if (c->zf) goto L_0045247e; /* je 0x45247e */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x00452475u); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffbu))); /* and edi, 0xfffffffb */
    goto L_0045262e; /* jmp 0x45262e */
L_0045247e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00452558; /* je 0x452558 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x8u)); /* test byte ptr [ebp + 0x10], 8 */
    if (c->zf) goto L_00452558; /* je 0x452558 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00452497u); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)0xc00u); /* mov eax, 0xc00 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->eax))); /* and ecx, eax */
    if (c->zf) goto L_00452530; /* je 0x452530 */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if (c->zf) goto L_00452508; /* je 0x452508 */
    (void)sub32(c, c->ecx, (uint32_t)0x800u); /* cmp ecx, 0x800 */
    if (c->zf) goto L_004524e0; /* je 0x4524e0 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->zf) goto L_00452550; /* jne 0x452550 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    FPUSH(c, RF64((uint32_t)(0x46cf58u))); /* fld qword ptr [0x46cf58] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_004524d8; /* ja 0x4524d8 */
    ST(0) = -ST(0); /* fchs  */
L_004524d8:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_0045254e; /* jmp 0x45254e */
L_004524e0:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_004524f8; /* jbe 0x4524f8 */
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    goto L_00452500; /* jmp 0x452500 */
L_004524f8:;
    FPUSH(c, RF64((uint32_t)(0x46cf58u))); /* fld qword ptr [0x46cf58] */
    ST(0) = -ST(0); /* fchs  */
L_00452500:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_0045254e; /* jmp 0x45254e */
L_00452508:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00452520; /* jbe 0x452520 */
    FPUSH(c, RF64((uint32_t)(0x46cf58u))); /* fld qword ptr [0x46cf58] */
    goto L_00452528; /* jmp 0x452528 */
L_00452520:;
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    ST(0) = -ST(0); /* fchs  */
L_00452528:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_0045254e; /* jmp 0x45254e */
L_00452530:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00452548; /* ja 0x452548 */
    ST(0) = -ST(0); /* fchs  */
L_00452548:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
L_0045254e:;
    WF64((uint32_t)(c->ecx), ST(0)); FPOP(c); /* fstp qword ptr [ecx] */
L_00452550:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffeu))); /* and edi, 0xfffffffe */
    goto L_0045262e; /* jmp 0x45262e */
L_00452558:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_0045262e; /* je 0x45262e */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0x10], 0x10 */
    if (c->zf) goto L_0045262e; /* je 0x45262e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00452573; /* je 0x452573 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00452573:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_0045261c; /* je 0x45261c */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0045259eu); f_00451ed6(c); /* call 0x451ed6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfffffa00u)); /* lea ecx, [eax - 0x600] */
    (void)sub32(c, c->ecx, (uint32_t)0xfffffbceu); /* cmp ecx, 0xfffffbce */
    if ((c->sf == c->of)) goto L_004525be; /* jge 0x4525be */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    goto L_00452612; /* jmp 0x452612 */
L_004525be:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_004525d0; /* jae 0x4525d0 */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_004525d2; /* jmp 0x4525d2 */
L_004525d0:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_004525d2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffau))); /* mov al, byte ptr [ebp - 6] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
    W16((uint32_t)(c->ebp + 0xfffffffau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 6], ax */
    c->eax = (uint32_t)((uint32_t)0xfffffc03u); /* mov eax, 0xfffffc03 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00452606; /* jge 0x452606 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
L_004525e9:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 0xc], bl */
    if (c->zf) goto L_004525f4; /* je 0x4525f4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_004525f4; /* jne 0x4525f4 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_004525f4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff8u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 8], bl */
    if (c->zf) goto L_00452600; /* je 0x452600 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
L_00452600:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 8], 1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_004525e9; /* jne 0x4525e9 */
L_00452606:;
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00452612; /* je 0x452612 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    ST(0) = -ST(0); /* fchs  */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
L_00452612:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_0045261e; /* jmp 0x45261e */
L_0045261c:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_0045261e:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_0045262b; /* je 0x45262b */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x0045262au); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0045262b:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffdu))); /* and edi, 0xfffffffd */
L_0045262e:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 8], 0x10 */
    if (c->zf) goto L_00452645; /* je 0x452645 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x20u)); /* test byte ptr [ebp + 0x10], 0x20 */
    if (c->zf) goto L_00452645; /* je 0x452645 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00452641u); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffffffefu))); /* and edi, 0xffffffef */
L_00452645:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004525e9(CPU *c) { /* PTR_004525e9 */
    PREEMPT_POLL(c);
L_004525e9:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 0xc], bl */
    if (c->zf) goto L_004525f4; /* je 0x4525f4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_004525f4; /* jne 0x4525f4 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_004525f4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff8u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 8], bl */
    if (c->zf) goto L_00452600; /* je 0x452600 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
L_00452600:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 8], 1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_004525e9; /* jne 0x4525e9 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00452612; /* je 0x452612 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    ST(0) = -ST(0); /* fchs  */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
L_00452612:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_0045261e; /* jmp 0x45261e */
L_0045261e:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_0045262b; /* je 0x45262b */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x0045262au); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0045262b:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffdu))); /* and edi, 0xfffffffd */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 8], 0x10 */
    if (c->zf) goto L_00452645; /* je 0x452645 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x20u)); /* test byte ptr [ebp + 0x10], 0x20 */
    if (c->zf) goto L_00452645; /* je 0x452645 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00452641u); f_00452790(c); /* call 0x452790 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffffffefu))); /* and edi, 0xffffffef */
L_00452645:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452650(CPU *c) { /* FUN_00452650 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x0045265eu); f_004526fe(c); /* call 0x4526fe */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    if (c->zf) goto L_004526bb; /* je 0x4526bb */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x28u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x28] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov eax, dword ptr [ebp + 0x24] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    PUSH32(c, 0x0045269eu); f_0045276d(c); /* call 0x45276d */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004526a7u); f_00457347(c); /* call 0x457347 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004526b5; /* jne 0x4526b5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x004526b4u); f_004526d8(c); /* call 0x4526d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_004526b5:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004526bb:;
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x28u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x28] */
    PUSH32(c, 0x004526c8u); f_0045276d(c); /* call 0x45276d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x004526d0u); f_004526d8(c); /* call 0x4526d8 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x20u))); /* fld qword ptr [ebp + 0x20] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004526d8(CPU *c) { /* FUN_004526d8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_004526f3; /* je 0x4526f3 */
    if ((c->zf || c->sf != c->of)) goto L_004526fd; /* jle 0x4526fd */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->zf && c->sf == c->of)) goto L_004526fd; /* jg 0x4526fd */
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [0x47c390], 0x22 */
    c->esp += 4; return; /* ret  */
L_004526f3:;
    W32((uint32_t)(0x47c390u), (uint32_t)((uint32_t)0x21u)); /* mov dword ptr [0x47c390], 0x21 */
L_004526fd:;
    c->esp += 4; return; /* ret  */
}

void f_004526fe(CPU *c) { /* FUN_004526fe */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x46cf70u); /* mov eax, 0x46cf70 */
L_00452705:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x4u))); /* cmp edx, dword ptr [esp + 4] */
    if (c->zf) goto L_0045271b; /* je 0x45271b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0x46d048u); /* cmp eax, 0x46d048 */
    if ((c->sf != c->of)) goto L_00452705; /* jl 0x452705 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_0045271b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 8 + 0x46cf74u))); /* mov eax, dword ptr [ecx*8 + 0x46cf74] */
    c->esp += 4; return; /* ret  */
}

void f_00452723(CPU *c) { /* FUN_00452723 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x20u)); /* test al, 0x20 */
    if (c->zf) goto L_0045272f; /* je 0x45272f */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00452745; /* jmp 0x452745 */
L_0045272f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_00452737; /* je 0x452737 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_00452745; /* jmp 0x452745 */
L_00452737:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_0045273f; /* je 0x45273f */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00452745; /* jmp 0x452745 */
L_0045273f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00452747; /* je 0x452747 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
L_00452745:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00452747:;
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00452750(CPU *c) { /* FUN_00452750 */
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

void f_0045275e(CPU *c) { /* FUN_0045275e */
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

void f_0045276d(CPU *c) { /* FUN_0045276d */
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

void f_00452790(CPU *c) { /* FUN_00452790 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    if (c->zf) goto L_004527a7; /* je 0x4527a7 */
    FPUSH(c, RF80((uint32_t)(0x46d048u))); /* fld xword ptr [0x46d048] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 8] */
    ; /* wait  */
L_004527a7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_004527bc; /* je 0x4527bc */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    FPUSH(c, RF80((uint32_t)(0x46d048u))); /* fld xword ptr [0x46d048] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
L_004527bc:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x10u)); /* test cl, 0x10 */
    if (c->zf) goto L_004527cb; /* je 0x4527cb */
    FPUSH(c, RF80((uint32_t)(0x46d054u))); /* fld xword ptr [0x46d054] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_004527cb:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_004527d9; /* je 0x4527d9 */
    FPUSH(c, 0.0); /* fldz  */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ; /* wait  */
L_004527d9:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x20u)); /* test cl, 0x20 */
    if (c->zf) goto L_004527e4; /* je 0x4527e4 */
    FPUSH(c, M_PI); /* fldpi  */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_004527e4:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004527e6(CPU *c) { /* __frnd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452800(CPU *c) { /* PTR_00452800 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00452805u); f_0045283c(c); /* call 0x45283c */
    { uint8_t t0_ = ((uint8_t)c->ecx), t1_ = ((uint8_t)(c->ecx >> 8)); c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(t1_); c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(t0_) << 8); } /* xchg cl, ch */
    goto L_0045282b; /* jmp 0x45282b */
L_0045282b:;
    ST(1) = atan2(ST(1), ST(0)); FPOP(c); /* fpatan  */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    if (c->zf) goto L_00452835; /* je 0x452835 */
    FPUSH(c, M_PI); /* fldpi  */
    ST(1) = FPRES(c, ST(0) - ST(1)); FPOP(c); /* fsubrp st(1) */
L_00452835:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_0045283b; /* je 0x45283b */
    ST(0) = -ST(0); /* fchs  */
L_0045283b:;
    c->esp += 4; return; /* ret  */
}

void f_0045281c(CPU *c) { /* PTR_0045281c */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0xfeu)); /* mov byte ptr [ebp - 0x90], 0xfe */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fabs(ST(0)); /* fabs  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = atan2(ST(1), ST(0)); FPOP(c); /* fpatan  */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    if (c->zf) goto L_00452835; /* je 0x452835 */
    FPUSH(c, M_PI); /* fldpi  */
    ST(1) = FPRES(c, ST(0) - ST(1)); FPOP(c); /* fsubrp st(1) */
L_00452835:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_0045283b; /* je 0x45283b */
    ST(0) = -ST(0); /* fchs  */
L_0045283b:;
    c->esp += 4; return; /* ret  */
}

void f_0045283c(CPU *c) { /* PTR_0045283c */
    PREEMPT_POLL(c);
    ST(0) = fabs(ST(0)); /* fabs  */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(0) - ST(1)); FPOP(c); /* fsubrp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (!c->zf) goto L_00452866; /* jne 0x452866 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, 0)) << 8); /* xor ch, ch */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    c->esp += 4; return; /* ret  */
L_00452866:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { f_00452ca6(c); return; } /* jmp 0x452ca6 */
}

void f_0045286c(CPU *c) { /* FUN_0045286c */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0bau))); /* fld xword ptr [0x46d0ba] */
    c->esp += 4; return; /* ret  */
}

void f_00452875(CPU *c) { /* PTR_00452875 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    if (c->zf) goto L_00452886; /* je 0x452886 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, M_PI); /* fldpi  */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00452885; /* je 0x452885 */
    ST(0) = -ST(0); /* fchs  */
L_00452885:;
    c->esp += 4; return; /* ret  */
L_00452886:;
    { f_00452c06(c); return; } /* jmp 0x452c06 */
}

void f_00452892(CPU *c) { /* PTR_00452892 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)(c->ecx >> 8))); /* mov cl, ch */
    goto L_00452898; /* jmp 0x452898 */
L_00452898:;
    PUSH32(c, 0x0045289du); f_0045286c(c); /* call 0x45286c */
    { f_00452cc3(c); return; } /* jmp 0x452cc3 */
}

void f_004528b0(CPU *c) { /* __cintrindisp2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd60u)); /* add esp, 0xfffffd60 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    ; /* wait  */
    (void)sub32(c, R32((uint32_t)(0x46f430u)), (uint32_t)0x0u); /* cmp dword ptr [0x46f430], 0 */
    if (c->zf) goto L_004528df; /* je 0x4528df */
L_004528cb:;
    PUSH32(c, 0x004528d0u); f_00452b67(c); /* call 0x452b67 */
    W8((uint32_t)(0x47c3e8u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [0x47c3e8], 1 */
    PUSH32(c, 0x004528dcu); f_00452965(c); /* call 0x452965 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004528df:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->ebp + 0xffffff7au), ST(0)); /* fst qword ptr [ebp - 0x86] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->ebp + 0xffffff82u), ST(0)); /* fst qword ptr [ebp - 0x7e] */
    goto L_004528cb; /* jmp 0x4528cb */
}

void f_004528ee(CPU *c) { /* __cintrindisp1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd60u)); /* add esp, 0xfffffd60 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    (void)sub32(c, R32((uint32_t)(0x46f430u)), (uint32_t)0x0u); /* cmp dword ptr [0x46f430], 0 */
    if (c->zf) goto L_0045291c; /* je 0x45291c */
L_00452908:;
    PUSH32(c, 0x0045290du); f_00452b00(c); /* call 0x452b00 */
    W8((uint32_t)(0x47c3e8u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [0x47c3e8], 1 */
    PUSH32(c, 0x00452919u); f_00452965(c); /* call 0x452965 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0045291c:;
    WF64((uint32_t)(c->ebp + 0xffffff7au), ST(0)); /* fst qword ptr [ebp - 0x86] */
    goto L_00452908; /* jmp 0x452908 */
}

void f_00452924(CPU *c) { /* __ctrandisp2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd60u)); /* add esp, 0xfffffd60 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00452939u); f_00452ac1(c); /* call 0x452ac1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00452947u); f_00452ac1(c); /* call 0x452ac1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    PUSH32(c, 0x00452956u); f_00452b67(c); /* call 0x452b67 */
    PUSH32(c, 0x0045295bu); f_0045295e(c); /* call 0x45295e */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045295e(CPU *c) { /* FUN_0045295e */
    PREEMPT_POLL(c);
    W8((uint32_t)(0x47c3e8u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [0x47c3e8], 0 */
    { f_00452965(c); return; }
}

void f_00452965(CPU *c) { /* FUN_00452965 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x47c338u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c338], 0 */
    if (!c->zf) goto L_004529ba; /* jne 0x4529ba */
    WF64((uint32_t)(0x47c3e0u), ST(0)); /* fst qword ptr [0x47c3e0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff70u))); /* mov al, byte ptr [ebp - 0x90] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00452998; /* je 0x452998 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0xffu); /* cmp al, 0xff */
    if (c->zf) goto L_004529c2; /* je 0x4529c2 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0xfeu); /* cmp al, 0xfe */
    if (c->zf) goto L_004529c2; /* je 0x4529c2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_004529ba; /* je 0x4529ba */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x8e], eax */
    goto L_00452a33; /* jmp 0x452a33 */
L_00452998:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov ax, word ptr [ebp - 0xa4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_004529ba; /* jne 0x4529ba */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_004529ba; /* je 0x4529ba */
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x8e], 8 */
    goto L_00452a33; /* jmp 0x452a33 */
L_004529ba:;
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5cu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa4] */
    ; /* wait  */
    c->esp += 4; return; /* ret  */
L_004529c2:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x47c3e6u))); /* mov ax, word ptr [0x47c3e6] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) | ((uint16_t)c->eax)))); /* or ax, ax */
    if (c->zf) goto L_004529d9; /* je 0x4529d9 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (c->zf) goto L_00452a07; /* je 0x452a07 */
    goto L_00452998; /* jmp 0x452998 */
L_004529d9:;
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x8e], 4 */
    FPUSH(c, RF64((uint32_t)(0x45be68u))); /* fld qword ptr [0x45be68] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x45be58u))); FPOP(c); /* fcomp qword ptr [0x45be58] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00452a33; /* jae 0x452a33 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x45be78u))); /* fmul qword ptr [0x45be78] */
    goto L_00452a33; /* jmp 0x452a33 */
L_00452a07:;
    W32((uint32_t)(c->ebp + 0xffffff72u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebp - 0x8e], 3 */
    FPUSH(c, RF64((uint32_t)(0x45be60u))); /* fld qword ptr [0x45be60] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x45be50u))); FPOP(c); /* fcomp qword ptr [0x45be50] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00452a33; /* jbe 0x452a33 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x45be70u))); /* fmul qword ptr [0x45be70] */
L_00452a33:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff6cu))); /* mov ebx, dword ptr [ebp - 0x94] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    W32((uint32_t)(c->ebp + 0xffffff76u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x8a], ebx */
    (void)sub8(c, R8((uint32_t)(0x47c3e8u)), (uint8_t)0x0u); /* cmp byte ptr [0x47c3e8], 0 */
    if (!c->zf) goto L_00452a65; /* jne 0x452a65 */
    c->df = 0; /* cld  */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea esi, [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffff7au)); /* lea edi, [ebp - 0x86] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    (void)sub8(c, R8((uint32_t)(c->ebx + 0xcu)), (uint8_t)0x1u); /* cmp byte ptr [ebx + 0xc], 1 */
    if (c->zf) goto L_00452a65; /* je 0x452a65 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea esi, [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffff82u)); /* lea edi, [ebp - 0x7e] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
L_00452a65:;
    WF64((uint32_t)(c->ebp + 0xffffff8au), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x76] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff72u)); /* lea eax, [ebp - 0x8e] */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0xffffff5cu)); /* lea ebx, [ebp - 0xa4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffff6cu))); /* mov ebx, dword ptr [ebp - 0x94] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx + 0xeu))); /* mov al, byte ptr [ebx + 0xe] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00452a88u); f_0045734a(c); /* call 0x45734a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffff8au))); /* fld qword ptr [ebp - 0x76] */
    goto L_004529ba; /* jmp 0x4529ba */
}

void f_00452a95(CPU *c) { /* __ctrandisp1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffd60u)); /* add esp, 0xfffffd60 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00452aaau); f_00452ac1(c); /* call 0x452ac1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff5cu), c->fpu_cw); /* fnstcw word ptr [ebp - 0xa4] */
    PUSH32(c, 0x00452ab9u); f_00452b00(c); /* call 0x452b00 */
    PUSH32(c, 0x00452abeu); f_0045295e(c); /* call 0x45295e */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452ac1(CPU *c) { /* __fload */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xfffffff4u)); /* add esp, -0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xeu))); /* mov ax, word ptr [ebp + 0xe] */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(((uint16_t)c->eax)); /* mov bx, ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    if (!c->zf) goto L_00452af7; /* jne 0x452af7 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ebx) | (uint16_t)0x7fffu))); /* or bx, 0x7fff */
    W16((uint32_t)(c->ebp + 0xfffffffeu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 2], bx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(({ unsigned n_ = 11 & 31; uint32_t r_ = n_ ? ((c->eax << n_) | (c->ebx >> (32 - n_))) : c->eax; if (n_) { c->cf = (c->eax >> (32 - n_)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })); /* shld eax, ebx, 0xb */
    W32((uint32_t)(c->ebp + 0xfffffffau), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 6], eax */
    W32((uint32_t)(c->ebp + 0xfffffff6u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xa], ebx */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xfffffff6u))); /* fld xword ptr [ebp - 0xa] */
    goto L_00452afa; /* jmp 0x452afa */
L_00452af7:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
L_00452afa:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452b00(CPU *c) { /* __trandisp1 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00452b17; /* jne 0x452b17 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00452b1b; /* jmp 0x452b1b */
L_00452b17:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00452b1b:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0x46d0cdu); /* mov ebx, 0x46d0cd */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00452b65u); return; } } /* jmp dword ptr [ebx] */
}

void f_00452b67(CPU *c) { /* __trandisp2 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00452b7e; /* jne 0x452b7e */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00452b82; /* jmp 0x452b82 */
L_00452b7e:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00452b82:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0x46d0cdu); /* mov ebx, 0x46d0cd */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00452bf1u); return; } } /* jmp dword ptr [ebx] */
}

void f_00452bf8(CPU *c) { /* FUN_00452bf8 */
    PREEMPT_POLL(c);
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00452bfa(CPU *c) { /* PTR_00452bfa */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00452bfd(CPU *c) { /* PTR_00452bfd */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00452c02u); f_00452cb9(c); /* call 0x452cb9 */
    { f_00452bfa(c); return; } /* jmp 0x452bfa */
}

void f_00452c06(CPU *c) { /* FUN_00452c06 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 0.0); /* fldz  */
    c->esp += 4; return; /* ret  */
}

void f_00452c0b(CPU *c) { /* PTR_00452c0b */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 1.0); /* fld1  */
    c->esp += 4; return; /* ret  */
}

void f_00452c0d(CPU *c) { /* PTR_00452c0d */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 1.0); /* fld1  */
    c->esp += 4; return; /* ret  */
}

void f_00452c12(CPU *c) { /* PTR_00452c12 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00452c2f; /* je 0x452c2f */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    c->esp += 4; return; /* ret  */
L_00452c2f:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x46d0c4u))); /* fadd qword ptr [0x46d0c4] */
    c->esp += 4; return; /* ret  */
}

void f_00452c3d(CPU *c) { /* PTR_00452c3d */
    PREEMPT_POLL(c);
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00452c5d; /* je 0x452c5d */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00452c64; /* jmp 0x452c64 */
L_00452c5d:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00452c64:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00452c3f(CPU *c) { /* PTR_00452c3f */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00452c5d; /* je 0x452c5d */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00452c64; /* jmp 0x452c64 */
L_00452c5d:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00452c64:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00452c67(CPU *c) { /* PTR_00452c67 */
    PREEMPT_POLL(c);
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00452c9c; /* je 0x452c9c */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF80((uint32_t)(c->ebp + 0xffffff62u), ST(0)); FPOP(c); /* fstp xword ptr [ebp - 0x9e] */
    FPUSH(c, RF80((uint32_t)(c->ebp + 0xffffff62u))); /* fld xword ptr [ebp - 0x9e] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff69u)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 0x97], 0x40 */
    if (c->zf) goto L_00452c9c; /* je 0x452c9c */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x7u)); /* mov byte ptr [ebp - 0x90], 7 */
    goto L_00452ca3; /* jmp 0x452ca3 */
L_00452c9c:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00452ca3:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->esp += 4; return; /* ret  */
}

void f_00452ca6(CPU *c) { /* PTR_00452ca6 */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0b0u))); /* fld xword ptr [0x46d0b0] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffff70u)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x90], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00452cc0; /* jg 0x452cc0 */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00452cc0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00452cb9(CPU *c) { /* PTR_00452cb9 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00452cc3(CPU *c) { /* FUN_00452cc3 */
    PREEMPT_POLL(c);
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    if (c->zf) goto L_00452cc9; /* je 0x452cc9 */
    ST(0) = -ST(0); /* fchs  */
L_00452cc9:;
    c->esp += 4; return; /* ret  */
}

void f_00452cd0(CPU *c) { /* PTR_00452cd0 */
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

void f_00452ce5(CPU *c) { /* FUN_00452ce5 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x300u))); /* and edx, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x7fu))); /* or edx, 0x7f */
    W16((uint32_t)(c->esp + 0x6u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esp + 6], dx */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x6u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 6] */
    c->esp += 4; return; /* ret  */
}

void f_00452cfc(CPU *c) { /* FUN_00452cfc */
    PREEMPT_POLL(c);
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000u)); /* test eax, 0x80000 */
    if (c->zf) goto L_00452d09; /* je 0x452d09 */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    c->esp += 4; return; /* ret  */
L_00452d09:;
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x45be80u))); /* fadd qword ptr [0x45be80] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00452d15(CPU *c) { /* __fload_withFB */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00452d27; /* je 0x452d27 */
    FPUSH(c, RF64((uint32_t)(c->edx))); /* fld qword ptr [edx] */
    c->esp += 4; return; /* ret  */
L_00452d27:;
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

void f_00452d58(CPU *c) { /* FUN_00452d58 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00452d69; /* je 0x452d69 */
    c->esp += 4; return; /* ret  */
L_00452d69:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00452d6e(CPU *c) { /* PTR_00452d6e */
    PREEMPT_POLL(c);
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_00452d79; /* je 0x452d79 */
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00452d79:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00452d79(CPU *c) { /* PTR_00452d79 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00452d7b(CPU *c) { /* __math_exit */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_00452da3; /* je 0x452da3 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00452da0; /* je 0x452da0 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00452da0; /* je 0x452da0 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
    PUSH32(c, 0x00452d9eu); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452da0:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00452da3:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00452da5(CPU *c) { /* PTR_00452da5 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    goto L_00452dcd; /* jmp 0x452dcd */
L_00452dcd:;
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00452e33; /* je 0x452e33 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_00452e08; /* je 0x452e08 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_00452e05; /* jne 0x452e05 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00452e05; /* je 0x452e05 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
L_00452df2:;
    (void)sub32(c, c->edx, (uint32_t)0x1du); /* cmp edx, 0x1d */
    if (c->zf) goto L_00452dfe; /* je 0x452dfe */
    PUSH32(c, 0x00452dfcu); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452dfe:;
    PUSH32(c, 0x00452e03u); f_00452e60(c); /* call 0x452e60 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452e05:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00452e08:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452e33:;
    FPUSH(c, RF64((uint32_t)(0x45bea4u))); /* fld qword ptr [0x45bea4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x45be94u))); FPOP(c); /* fcomp qword ptr [0x45be94] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    if ((c->cf || c->zf)) goto L_00452df2; /* jbe 0x452df2 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x45beb4u))); /* fmul qword ptr [0x45beb4] */
    goto L_00452df2; /* jmp 0x452df2 */
}

void f_00452db9(CPU *c) { /* PTR_00452db9 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    if (c->zf) goto L_00452e0a; /* je 0x452e0a */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00452e33; /* je 0x452e33 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_00452e08; /* je 0x452e08 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_00452e05; /* jne 0x452e05 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00452e05; /* je 0x452e05 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
L_00452df2:;
    (void)sub32(c, c->edx, (uint32_t)0x1du); /* cmp edx, 0x1d */
    if (c->zf) goto L_00452dfe; /* je 0x452dfe */
    PUSH32(c, 0x00452dfcu); f_00452e77(c); /* call 0x452e77 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452dfe:;
    PUSH32(c, 0x00452e03u); f_00452e60(c); /* call 0x452e60 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452e05:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00452e08:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00452e0a:;
    FPUSH(c, RF64((uint32_t)(0x45beacu))); /* fld qword ptr [0x45beac] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x45be9cu))); FPOP(c); /* fcomp qword ptr [0x45be9c] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x4u); /* mov eax, 4 */
    if (!c->cf) goto L_00452df2; /* jae 0x452df2 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x45bebcu))); /* fmul qword ptr [0x45bebc] */
    goto L_00452df2; /* jmp 0x452df2 */
L_00452e33:;
    FPUSH(c, RF64((uint32_t)(0x45bea4u))); /* fld qword ptr [0x45bea4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0x45be94u))); FPOP(c); /* fcomp qword ptr [0x45be94] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    if ((c->cf || c->zf)) goto L_00452df2; /* jbe 0x452df2 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x45beb4u))); /* fmul qword ptr [0x45beb4] */
    goto L_00452df2; /* jmp 0x452df2 */
}

void f_00452e60(CPU *c) { /* FUN_00452e60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe0u)); /* add esp, -0x20 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    { f_00452e80(c); return; } /* jmp 0x452e80 */
}

void f_00452e77(CPU *c) { /* __startOneArgErrorHandling */
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
    PUSH32(c, 0x00452ea0u); f_0045734a(c); /* call 0x45734a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_00452eb1; /* je 0x452eb1 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_00452eb1:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452e80(CPU *c) { /* PTR_00452e80 */
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
    PUSH32(c, 0x00452ea0u); f_0045734a(c); /* call 0x45734a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_00452eb1; /* je 0x452eb1 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_00452eb1:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00452ec0(CPU *c) { /* PTR_00452ec0 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0xfeu)); /* mov byte ptr [ebp - 0x90], 0xfe */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (!c->zf) goto L_00452f16; /* jne 0x452f16 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_00452ecd:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    goto L_00452ede; /* jmp 0x452ede */
L_00452ede:;
    PUSH32(c, 0x00452ee3u); f_0045301e(c); /* call 0x45301e */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (c->zf) goto L_00452f04; /* je 0x452f04 */
    FPUSH(c, 1.0); /* fld1  */
    (void)sub32(c, R32((uint32_t)(0x47c33cu)), (uint32_t)0x1u); /* cmp dword ptr [0x47c33c], 1 */
    if (c->zf) goto L_00452eff; /* je 0x452eff */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    goto L_00452f04; /* jmp 0x452f04 */
L_00452eff:;
    PUSH32(c, 0x00452f04u); f_00457c11(c); /* call 0x457c11 */
L_00452f04:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x40u)); /* test dl, 0x40 */
    if (!c->zf) goto L_00452f0b; /* jne 0x452f0b */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
L_00452f0b:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00452f11; /* je 0x452f11 */
    ST(0) = -ST(0); /* fchs  */
L_00452f11:;
    { f_00452bf8(c); return; } /* jmp 0x452bf8 */
L_00452f16:;
    PUSH32(c, 0x00452f1bu); f_00453061(c); /* call 0x453061 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00452f33; /* je 0x452f33 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, 0)) << 8); /* xor ch, ch */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00452f28; /* je 0x452f28 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)~((uint8_t)(c->ecx >> 8))) << 8); /* not ch */
L_00452f28:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fabs(ST(0)); /* fabs  */
    goto L_00452ecd; /* jmp 0x452ecd */
L_00452f33:;
    { f_00452ca6(c); return; } /* jmp 0x452ca6 */
}

void f_00452ed1(CPU *c) { /* PTR_00452ed1 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0xfeu)); /* mov byte ptr [ebp - 0x90], 0xfe */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, 0)) << 8); /* xor ch, ch */
    FPUSH(c, M_LOG2E); /* fldl2e  */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    PUSH32(c, 0x00452ee3u); f_0045301e(c); /* call 0x45301e */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (c->zf) goto L_00452f04; /* je 0x452f04 */
    FPUSH(c, 1.0); /* fld1  */
    (void)sub32(c, R32((uint32_t)(0x47c33cu)), (uint32_t)0x1u); /* cmp dword ptr [0x47c33c], 1 */
    if (c->zf) goto L_00452eff; /* je 0x452eff */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    goto L_00452f04; /* jmp 0x452f04 */
L_00452eff:;
    PUSH32(c, 0x00452f04u); f_00457c11(c); /* call 0x457c11 */
L_00452f04:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x40u)); /* test dl, 0x40 */
    if (!c->zf) goto L_00452f0b; /* jne 0x452f0b */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
L_00452f0b:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00452f11; /* je 0x452f11 */
    ST(0) = -ST(0); /* fchs  */
L_00452f11:;
    { f_00452bf8(c); return; } /* jmp 0x452bf8 */
}

void f_00452fc4(CPU *c) { /* PTR_00452fc4 */
    PREEMPT_POLL(c);
    { f_00452c06(c); return; } /* jmp 0x452c06 */
}

void f_00452fd0(CPU *c) { /* PTR_00452fd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (!c->zf) goto L_00452ff3; /* jne 0x452ff3 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0e0u))); /* fld xword ptr [0x46d0e0] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00452ff2; /* je 0x452ff2 */
    ST(0) = -ST(0); /* fchs  */
L_00452ff2:;
    c->esp += 4; return; /* ret  */
L_00452ff3:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [ebp - 0x90], 4 */
    { f_00452c06(c); return; } /* jmp 0x452c06 */
}

void f_00452ff2(CPU *c) { /* PTR_00452ff2 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00452ff3(CPU *c) { /* PTR_00452ff3 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [ebp - 0x90], 4 */
    { f_00452c06(c); return; } /* jmp 0x452c06 */
}

void f_00452fff(CPU *c) { /* PTR_00452fff */
    PREEMPT_POLL(c);
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0e0u))); /* fld xword ptr [0x46d0e0] */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [ebp - 0x90], 3 */
    c->esp += 4; return; /* ret  */
}

void f_00453011(CPU *c) { /* PTR_00453011 */
    PREEMPT_POLL(c);
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    if (!c->zf) { f_00452fc4(c); return; } /* jne 0x452fc4 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0e0u))); /* fld xword ptr [0x46d0e0] */
    c->esp += 4; return; /* ret  */
}

void f_0045301e(CPU *c) { /* FUN_0045301e */
    PREEMPT_POLL(c);
    goto L_0045301e;
L_00452fd0:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (!c->zf) goto L_00452ff3; /* jne 0x452ff3 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x46d0e0u))); /* fld xword ptr [0x46d0e0] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00452ff2; /* je 0x452ff2 */
    ST(0) = -ST(0); /* fchs  */
L_00452ff2:;
    c->esp += 4; return; /* ret  */
L_00452ff3:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [ebp - 0x90], 4 */
    { f_00452c06(c); return; } /* jmp 0x452c06 */
L_0045301e:;
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, RF80((uint32_t)(0x46d0feu))); /* fld xword ptr [0x46d0fe] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x41u)); /* test byte ptr [ebp - 0x9f], 0x41 */
    if (!c->zf) goto L_00452fd0; /* jne 0x452fd0 */
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

void f_00453061(CPU *c) { /* PTR_00453061 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00453087; /* jne 0x453087 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x46d112u))); /* fmul qword ptr [0x46d112] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_0045308e; /* je 0x45308e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00453086:;
    c->esp += 4; return; /* ret  */
L_00453087:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00453086; /* jmp 0x453086 */
L_0045308e:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_00453086; /* jmp 0x453086 */
}

void f_004530c7(CPU *c) { /* FUN_004530c7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_004530e4; /* jae 0x4530e4 */
    ST(0) = -ST(0); /* fchs  */
L_004530e4:;
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)((uint32_t)0x7ff00000u); /* mov eax, 0x7ff00000 */
    c->ecx = (uint32_t)((uint32_t)0xfff00000u); /* mov ecx, 0xfff00000 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->eax); /* cmp dword ptr [ebp + 0x14], eax */
    if (!c->zf) goto L_0045312a; /* jne 0x45312a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edx); /* cmp dword ptr [ebp + 0x10], edx */
    if (!c->zf) goto L_00453152; /* jne 0x453152 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc48u))); FPOP(c); /* fcomp qword ptr [0x45bc48] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_0045316e; /* ja 0x45316e */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc48u))); FPOP(c); /* fcomp qword ptr [0x45bc48] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00453184; /* jb 0x453184 */
L_00453117:;
    FPUSH(c, RF64((uint32_t)(0x46cf50u))); /* fld qword ptr [0x46cf50] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_004531f2; /* jmp 0x4531f2 */
L_0045312a:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->ecx); /* cmp dword ptr [ebp + 0x14], ecx */
    if (!c->zf) goto L_00453152; /* jne 0x453152 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edx); /* cmp dword ptr [ebp + 0x10], edx */
    if (!c->zf) goto L_00453152; /* jne 0x453152 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc48u))); FPOP(c); /* fcomp qword ptr [0x45bc48] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00453184; /* ja 0x453184 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc48u))); FPOP(c); /* fcomp qword ptr [0x45bc48] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00453117; /* jae 0x453117 */
    goto L_0045316e; /* jmp 0x45316e */
L_00453152:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->eax); /* cmp dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00453188; /* jne 0x453188 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_004531f2; /* jne 0x4531f2 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00453176; /* jbe 0x453176 */
L_0045316e:;
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    goto L_004531ed; /* jmp 0x4531ed */
L_00453176:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_004531eb; /* jae 0x4531eb */
L_00453184:;
    FPUSH(c, 0.0); /* fldz  */
    goto L_004531ed; /* jmp 0x4531ed */
L_00453188:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_004531f2; /* jne 0x4531f2 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_004531f2; /* jne 0x4531f2 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0045319fu); f_004531f7(c); /* call 0x4531f7 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_004531c6; /* jbe 0x4531c6 */
    FPUSH(c, RF64((uint32_t)(0x46cf48u))); /* fld qword ptr [0x46cf48] */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (!c->zf) goto L_004531be; /* jne 0x4531be */
    ST(0) = -ST(0); /* fchs  */
L_004531be:;
    WF64((uint32_t)(c->ebp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    goto L_004531ed; /* jmp 0x4531ed */
L_004531c6:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0x45bc40u))); FPOP(c); /* fcomp qword ptr [0x45bc40] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_004531eb; /* jae 0x4531eb */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (!c->zf) goto L_004531e1; /* jne 0x4531e1 */
    FPUSH(c, RF64((uint32_t)(0x46cf68u))); /* fld qword ptr [0x46cf68] */
    goto L_004531e3; /* jmp 0x4531e3 */
L_004531e1:;
    FPUSH(c, 0.0); /* fldz  */
L_004531e3:;
    WF64((uint32_t)(c->ebp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    goto L_004531ed; /* jmp 0x4531ed */
L_004531eb:;
    FPUSH(c, 1.0); /* fld1  */
L_004531ed:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
L_004531f2:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004531f7(CPU *c) { /* FUN_004531f7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00453209u); f_0044ed8f(c); /* call 0x44ed8f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x90u)); /* test al, 0x90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00453258; /* jne 0x453258 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x0045321cu); f_004527e6(c); /* call 0x4527e6 */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00453258; /* jne 0x453258 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(0x45bec8u)))); /* fdiv qword ptr [0x45bec8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->ebp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00453245u); f_004527e6(c); /* call 0x4527e6 */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00453253; /* jne 0x453253 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00453255; /* jmp 0x453255 */
L_00453253:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00453255:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00453258:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045325c(CPU *c) { /* FUN_0045325c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0x45b12cu)); PUSH32(c, 0x0045326cu); call_indirect(c, t_); } /* call dword ptr [0x45b12c] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_00453287; /* jne 0x453287 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00453287; /* je 0x453287 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_00453287:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00453289(CPU *c) { /* FUN_00453289 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x00453296u); f_0044ddf0(c); /* call 0x44ddf0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0x45b0f4u)); PUSH32(c, 0x004532aeu); call_indirect(c, t_); } /* call dword ptr [0x45b0f4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004532cc; /* je 0x4532cc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_004532cc; /* jne 0x4532cc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_004532cc; /* jb 0x4532cc */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004533ce; /* jmp 0x4533ce */
L_004532cc:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x45bee8u; PUSH32(c, v_); } /* push 0x45bee8 */
    { uint32_t t_ = R32((uint32_t)(0x45b0f8u)); PUSH32(c, 0x004532e3u); call_indirect(c, t_); } /* call dword ptr [0x45b0f8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004533bb; /* je 0x4533bb */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_0045330e; /* je 0x45330e */
L_004532fb:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00453309; /* jl 0x453309 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00453309; /* jg 0x453309 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00453309:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_004532fb; /* jne 0x4532fb */
L_0045330e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x45bed0u; PUSH32(c, v_); } /* push 0x45bed0 */
    PUSH32(c, 0x00453321u); f_00458540(c); /* call 0x458540 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00453330; /* jne 0x453330 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00453379; /* jmp 0x453379 */
L_00453330:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x45b0fcu)); PUSH32(c, 0x00453343u); call_indirect(c, t_); } /* call dword ptr [0x45b0fc] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00453364; /* je 0x453364 */
L_00453351:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_0045335f; /* jl 0x45335f */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_0045335f; /* jg 0x45335f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_0045335f:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00453351; /* jne 0x453351 */
L_00453364:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00453377u); f_004584c0(c); /* call 0x4584c0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00453379:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_004533bb; /* je 0x4533bb */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00453385u); f_00458400(c); /* call 0x458400 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_004533bb; /* je 0x4533bb */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_004533a0; /* je 0x4533a0 */
L_00453392:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_0045339b; /* jne 0x45339b */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_0045339c; /* jmp 0x45339c */
L_0045339b:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_0045339c:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00453392; /* jne 0x453392 */
L_004533a0:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004533a9u); f_004581ab(c); /* call 0x4581ab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_004533ce; /* je 0x4533ce */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_004533ce; /* je 0x4533ce */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_004533ce; /* je 0x4533ce */
L_004533bb:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004533c4u); f_0045325c(c); /* call 0x45325c */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_004533ce:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004533d1(CPU *c) { /* FUN_004533d1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b0ecu)); PUSH32(c, 0x004533e8u); call_indirect(c, t_); } /* call dword ptr [0x45b0ec] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x47c6a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6a4], eax */
    if (c->zf) goto L_00453427; /* je 0x453427 */
    PUSH32(c, 0x004533f6u); f_00453289(c); /* call 0x453289 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0x47c6a8u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6a8], eax */
    if (!c->zf) goto L_0045340d; /* jne 0x45340d */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x0045340au); f_004535a8(c); /* call 0x4535a8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00453417; /* jmp 0x453417 */
L_0045340d:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_0045342a; /* jne 0x45342a */
    PUSH32(c, 0x00453417u); f_00454511(c); /* call 0x454511 */
L_00453417:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0045342a; /* jne 0x45342a */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b0f0u)); PUSH32(c, 0x00453427u); call_indirect(c, t_); } /* call dword ptr [0x45b0f0] */
L_00453427:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_0045342a:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_0045342e(CPU *c) { /* PTR_0045342e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6a8u))); /* mov eax, dword ptr [0x47c6a8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_004534a0; /* jne 0x4534a0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x47c698u)), c->ebx); /* cmp dword ptr [0x47c698], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x45b138u))); /* mov ebp, dword ptr [0x45b138] */
    if ((c->zf || c->sf != c->of)) goto L_0045348c; /* jle 0x45348c */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov eax, dword ptr [0x47c69c] */
    c->edi = (uint32_t)(R32((uint32_t)(0x45b0e8u))); /* mov edi, dword ptr [0x45b0e8] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_0045345a:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00453468u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00453473u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00453480u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x47c698u))); /* cmp ebx, dword ptr [0x47c698] */
    if ((c->sf != c->of)) goto L_0045345a; /* jl 0x45345a */
L_0045348c:;
    { uint32_t v_ = R32((uint32_t)(0x47c69cu)); PUSH32(c, v_); } /* push dword ptr [0x47c69c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x0045349cu); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_004534c7; /* jmp 0x4534c7 */
L_004534a0:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_004534c7; /* jne 0x4534c7 */
    c->edi = (uint32_t)((uint32_t)0x46d148u); /* mov edi, 0x46d148 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_004534ac:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004534c1; /* je 0x4534c1 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b0e8u)); PUSH32(c, 0x004534c1u); call_indirect(c, t_); } /* call dword ptr [0x45b0e8] */
L_004534c1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_004534ac; /* jne 0x4534ac */
L_004534c7:;
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b0f0u)); PUSH32(c, 0x004534d3u); call_indirect(c, t_); } /* call dword ptr [0x45b0f0] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_004534f5(CPU *c) { /* FUN_004534f5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c6a8u))); /* mov eax, dword ptr [0x47c6a8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_0045351b; /* jne 0x45351b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x3f8u); /* cmp eax, 0x3f8 */
    if ((!c->cf && !c->zf)) goto L_004535a3; /* ja 0x4535a3 */
    W32((uint32_t)(0x47c6a0u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c6a0], eax */
    goto L_0045359e; /* jmp 0x45359e */
L_0045351b:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00453536; /* jne 0x453536 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    (void)sub32(c, c->eax, (uint32_t)0x780u); /* cmp eax, 0x780 */
    if ((!c->cf && !c->zf)) goto L_004535a3; /* ja 0x4535a3 */
    W32((uint32_t)(0x46f16cu), (uint32_t)(c->eax)); /* mov dword ptr [0x46f16c], eax */
    goto L_0045359e; /* jmp 0x45359e */
L_00453536:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_004535a3; /* jne 0x4535a3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->cf || c->zf)) goto L_004535a3; /* jbe 0x4535a3 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045354bu); f_0045325c(c); /* call 0x45325c */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x8u)), (uint8_t)0x6u); /* cmp byte ptr [ebp + 8], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->cf) goto L_00453577; /* jb 0x453577 */
    (void)sub32(c, c->esi, (uint32_t)0x3f8u); /* cmp esi, 0x3f8 */
    if ((!c->cf && !c->zf)) goto L_004535a3; /* ja 0x4535a3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00453560u); f_004535a8(c); /* call 0x4535a8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_004535a3; /* je 0x4535a3 */
    W32((uint32_t)(0x47c6a0u), (uint32_t)(c->esi)); /* mov dword ptr [0x47c6a0], esi */
    W32((uint32_t)(0x47c6a8u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [0x47c6a8], 3 */
    goto L_0045359e; /* jmp 0x45359e */
L_00453577:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    (void)sub32(c, c->esi, (uint32_t)0x780u); /* cmp esi, 0x780 */
    if ((!c->cf && !c->zf)) goto L_004535a3; /* ja 0x4535a3 */
    PUSH32(c, 0x0045358au); f_00454511(c); /* call 0x454511 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004535a3; /* je 0x4535a3 */
    W32((uint32_t)(0x46f16cu), (uint32_t)(c->esi)); /* mov dword ptr [0x46f16c], esi */
    W32((uint32_t)(0x47c6a8u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x47c6a8], 2 */
L_0045359e:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004535a5; /* jmp 0x4535a5 */
L_004535a3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_004535a5:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_004535a8(CPU *c) { /* FUN_004535a8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x140u; PUSH32(c, v_); } /* push 0x140 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b134u)); PUSH32(c, 0x004535bbu); call_indirect(c, t_); } /* call dword ptr [0x45b134] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x47c69cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c69c], eax */
    if (!c->zf) goto L_004535c5; /* jne 0x4535c5 */
    c->esp += 4; return; /* ret  */
L_004535c5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0x47c694u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x47c694], 0 */
    { uint32_t a_ = (uint32_t)(0x47c698u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x47c698], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x47c68cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c68c], eax */
    W32((uint32_t)(0x47c6a0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c6a0], ecx */
    W32((uint32_t)(0x47c684u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [0x47c684], 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_004535f0(CPU *c) { /* FUN_004535f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov eax, dword ptr [0x47c69c] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
L_00453600:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00453618; /* jae 0x453618 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->eax + 0xcu)))); /* sub edx, dword ptr [eax + 0xc] */
    (void)sub32(c, c->edx, (uint32_t)0x100000u); /* cmp edx, 0x100000 */
    if (c->cf) goto L_0045361a; /* jb 0x45361a */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x14u)); /* add eax, 0x14 */
    goto L_00453600; /* jmp 0x453600 */
L_00453618:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0045361a:;
    c->esp += 4; return; /* ret  */
}

void f_0045361b(CPU *c) { /* FUN_0045361b */
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
    if (!c->zf) goto L_0045393f; /* jne 0x45393f */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi))); /* mov edx, dword ptr [ecx + esi] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea ebx, [ecx + esi] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov edx, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0xc], ebx */
    if (!c->zf) goto L_004536f1; /* jne 0x4536f1 */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_0045367f; /* jbe 0x45367f */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_0045367f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx + 0x8u))); /* cmp ecx, dword ptr [ebx + 8] */
    if (!c->zf) goto L_004536d3; /* jne 0x4536d3 */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    if (!c->cf) goto L_004536aa; /* jae 0x4536aa */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_004536cb; /* jne 0x4536cb */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_004536cb; /* jmp 0x4536cb */
L_004536aa:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_004536cb; /* jne 0x4536cb */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_004536cb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    goto L_004536d6; /* jmp 0x4536d6 */
L_004536d3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
L_004536d6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edx, dword ptr [ebx + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebx, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* add ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
L_004536f1:;
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_004536ff; /* jbe 0x4536ff */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_004536ff:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x1u))); /* and ebx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xc], ebx */
    if (!c->zf) goto L_004537a2; /* jne 0x4537a2 */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(sar32(c, c->ebx, 4)); /* sar ebx, 4 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->cf || c->zf)) goto L_00453724; /* jbe 0x453724 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_00453724:;
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if ((c->cf || c->zf)) goto L_00453736; /* jbe 0x453736 */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
L_00453736:;
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_0045379d; /* je 0x45379d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ecx + 0x8u))); /* cmp esi, dword ptr [ecx + 8] */
    if (!c->zf) goto L_00453785; /* jne 0x453785 */
    (void)sub32(c, c->ebx, (uint32_t)0x20u); /* cmp ebx, 0x20 */
    if (!c->cf) goto L_00453766; /* jae 0x453766 */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0x44], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00453785; /* jne 0x453785 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx], esi */
    goto L_00453785; /* jmp 0x453785 */
L_00453766:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0xffffffe0u)); /* lea ecx, [ebx - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0xc4], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00453785; /* jne 0x453785 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx + 4], esi */
L_00453785:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
L_0045379d:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    goto L_004537a5; /* jmp 0x4537a5 */
L_004537a2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_004537a5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_004537b3; /* jne 0x4537b3 */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00453834; /* je 0x453834 */
L_004537b3:;
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
    if (!c->zf) goto L_00453834; /* jne 0x453834 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + c->eax + 0x4u))); /* mov cl, byte ptr [edx + eax + 4] */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edx + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax + 4], cl */
    if (!c->cf) goto L_0045380b; /* jae 0x45380b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_004537fa; /* jne 0x4537fa */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_004537fa:;
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0x44u)); /* lea eax, [eax + edi*4 + 0x44] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax], ebx */
    goto L_00453834; /* jmp 0x453834 */
L_0045380b:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00453821; /* jne 0x453821 */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00453821:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0xc4u)); /* lea eax, [eax + edi*4 + 0xc4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00453834:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->eax + c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax] */
    if (!c->zf) goto L_0045393f; /* jne 0x45393f */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00453931; /* je 0x453931 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c688u))); /* mov ecx, dword ptr [0x47c688] */
    c->esi = (uint32_t)(R32((uint32_t)(0x45b0e8u))); /* mov esi, dword ptr [0x45b0e8] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 15)); /* shl ecx, 0xf */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->eax + 0xcu)))); /* add ecx, dword ptr [eax + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x8000u); /* mov ebx, 0x8000 */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00453875u); call_indirect(c, t_); } /* call esi */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c688u))); /* mov ecx, dword ptr [0x47c688] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c688u))); /* mov ecx, dword ptr [0x47c688] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + ecx*4 + 0xc4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x43u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [eax + 0x43] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x43u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 0x43], 0 */
    if (!c->zf) goto L_004538c2; /* jne 0x4538c2 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [eax + 4], 0xfffffffe */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
L_004538c2:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + 8], -1 */
    if (!c->zf) goto L_00453931; /* jne 0x453931 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x004538d0u); call_indirect(c, t_); } /* call esi */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b138u)); PUSH32(c, 0x004538e6u); call_indirect(c, t_); } /* call dword ptr [0x45b138] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
    c->edx = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov edx, dword ptr [0x47c69c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffffecu)); /* lea ecx, [ecx + edx - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x14u)); /* lea ecx, [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045390fu); f_00455840(c); /* call 0x455840 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(0x47c698u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x47c698] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x47c694u))); /* cmp eax, dword ptr [0x47c694] */
    if ((c->cf || c->zf)) goto L_00453927; /* jbe 0x453927 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x14u))); } /* sub dword ptr [ebp + 8], 0x14 */
L_00453927:;
    c->eax = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov eax, dword ptr [0x47c69c] */
    W32((uint32_t)(0x47c68cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c68c], eax */
L_00453931:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0x47c688u), (uint32_t)(c->edi)); /* mov dword ptr [0x47c688], edi */
    W32((uint32_t)(0x47c694u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c694], eax */
L_0045393f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00453944(CPU *c) { /* FUN_00453944 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
    c->edx = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov edx, dword ptr [0x47c69c] */
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
    if ((c->sf == c->of)) goto L_00453984; /* jge 0x453984 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    goto L_00453994; /* jmp 0x453994 */
L_00453984:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00453994:;
    c->eax = (uint32_t)(R32((uint32_t)(0x47c68cu))); /* mov eax, dword ptr [0x47c68c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_004539bb; /* jae 0x4539bb */
L_004539a2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_004539bb; /* jne 0x4539bb */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->cf) goto L_004539a2; /* jb 0x4539a2 */
L_004539bb:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00453a39; /* jne 0x453a39 */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_004539c2:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_004539de; /* jae 0x4539de */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_004539dc; /* jne 0x4539dc */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_004539c2; /* jmp 0x4539c2 */
L_004539dc:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_004539de:;
    if (!c->zf) goto L_00453a39; /* jne 0x453a39 */
L_004539e0:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->cf) goto L_004539f6; /* jae 0x4539f6 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_004539f3; /* jne 0x4539f3 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    goto L_004539e0; /* jmp 0x4539e0 */
L_004539f3:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
L_004539f6:;
    if (!c->zf) goto L_00453a1e; /* jne 0x453a1e */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_004539fa:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00453a0e; /* jae 0x453a0e */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00453a0c; /* jne 0x453a0c */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_004539fa; /* jmp 0x4539fa */
L_00453a0c:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00453a0e:;
    if (!c->zf) goto L_00453a1e; /* jne 0x453a1e */
    PUSH32(c, 0x00453a15u); f_00453c4d(c); /* call 0x453c4d */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->zf) goto L_00453a32; /* je 0x453a32 */
L_00453a1e:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00453a24u); f_00453cfe(c); /* call 0x453cfe */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00453a39; /* jne 0x453a39 */
L_00453a32:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00453c48; /* jmp 0x453c48 */
L_00453a39:;
    W32((uint32_t)(0x47c68cu), (uint32_t)(c->ebx)); /* mov dword ptr [0x47c68c], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    if (c->zf) goto L_00453a60; /* je 0x453a60 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov edi, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00453a97; /* jne 0x453a97 */
L_00453a60:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xc4u))); /* mov edx, dword ptr [eax + 0xc4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov esi, dword ptr [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & R32((uint32_t)(c->ebp + 0xfffffff4u))))); /* and esi, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x44u)); /* lea ecx, [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->esi))); /* or edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    if (!c->zf) goto L_00453a94; /* jne 0x453a94 */
L_00453a7d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edx, dword ptr [ecx + 0x84] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & R32((uint32_t)(c->ecx))))); /* and edi, dword ptr [ecx] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->edi))); /* or edx, edi */
    if (c->zf) goto L_00453a7d; /* je 0x453a7d */
L_00453a94:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
L_00453a97:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov ecx, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->esi))); /* and ecx, esi */
    if (!c->zf) goto L_00453ac0; /* jne 0x453ac0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00453ac0:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf != c->of)) goto L_00453ac9; /* jl 0x453ac9 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00453ac0; /* jmp 0x453ac0 */
L_00453ac9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [ecx + edi*8 + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_00453ae6; /* jle 0x453ae6 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00453ae6:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00453bfb; /* je 0x453bfb */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x8u))); /* cmp ecx, dword ptr [edx + 8] */
    if (!c->zf) goto L_00453b57; /* jne 0x453b57 */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if ((c->sf == c->of)) goto L_00453b26; /* jge 0x453b26 */
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
    if (!c->zf) goto L_00453b54; /* jne 0x453b54 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx], ecx */
    goto L_00453b57; /* jmp 0x453b57 */
L_00453b26:;
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
    if (!c->zf) goto L_00453b54; /* jne 0x453b54 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx + 4], ecx */
    goto L_00453b57; /* jmp 0x453b57 */
L_00453b54:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00453b57:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ecx, dword ptr [edx + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    if (c->zf) goto L_00453c07; /* je 0x453c07 */
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
    if (!c->zf) goto L_00453bf8; /* jne 0x453bf8 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xbu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xb], cl */
    if ((c->sf == c->of)) goto L_00453bc9; /* jge 0x453bc9 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00453bb7; /* jne 0x453bb7 */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx], edi */
L_00453bb7:;
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + ecx*4 + 0x44], edi */
    goto L_00453bf8; /* jmp 0x453bf8 */
L_00453bc9:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00453be2; /* jne 0x453be2 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx + 4], edi */
L_00453be2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx * 4 + 0xc4u)); /* lea edi, [eax + ecx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->esi)))); } /* or dword ptr [edi], esi */
L_00453bf8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00453bfb:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00453c0a; /* je 0x453c0a */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->ecx + c->edx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + edx - 4], ecx */
    goto L_00453c0a; /* jmp 0x453c0a */
L_00453c07:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00453c0a:;
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
    if (!c->zf) goto L_00453c40; /* jne 0x453c40 */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x47c694u))); /* cmp ebx, dword ptr [0x47c694] */
    if (!c->zf) goto L_00453c40; /* jne 0x453c40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x47c688u))); /* cmp ecx, dword ptr [0x47c688] */
    if (!c->zf) goto L_00453c40; /* jne 0x453c40 */
    { uint32_t a_ = (uint32_t)(0x47c694u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x47c694], 0 */
L_00453c40:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea eax, [edx + 4] */
L_00453c48:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00453c4d(CPU *c) { /* FUN_00453c4d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c684u))); /* mov ecx, dword ptr [0x47c684] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00453c90; /* jne 0x453c90 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4 + 0x50u)); /* lea eax, [ecx + ecx*4 + 0x50] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x47c69cu)); PUSH32(c, v_); } /* push dword ptr [0x47c69c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b130u)); PUSH32(c, 0x00453c7bu); call_indirect(c, t_); } /* call dword ptr [0x45b130] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00453ce0; /* je 0x453ce0 */
    { uint32_t a_ = (uint32_t)(0x47c684u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [0x47c684], 0x10 */
    W32((uint32_t)(0x47c69cu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c69c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
L_00453c90:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov ecx, dword ptr [0x47c69c] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    { uint32_t t_ = R32((uint32_t)(0x45b134u)); PUSH32(c, 0x00453cafu); call_indirect(c, t_); } /* call dword ptr [0x45b134] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    if (c->zf) goto L_00453ce0; /* je 0x453ce0 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x45b1b0u)); PUSH32(c, 0x00453cc9u); call_indirect(c, t_); } /* call dword ptr [0x45b1b0] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_00453ce4; /* jne 0x453ce4 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b138u)); PUSH32(c, 0x00453ce0u); call_indirect(c, t_); } /* call dword ptr [0x45b138] */
L_00453ce0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00453cfb; /* jmp 0x453cfb */
L_00453ce4:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 8], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t a_ = (uint32_t)(0x47c698u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x47c698] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00453cfb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00453cfe(CPU *c) { /* FUN_00453cfe */
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
L_00453d10:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00453d19; /* jl 0x453d19 */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00453d10; /* jmp 0x453d10 */
L_00453d19:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x204u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x204 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi + 0x144u)); /* lea eax, [eax + esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00453d2e:;
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 8], eax */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 4], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00453d2e; /* jne 0x453d2e */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edi = (uint32_t)(shl32(c, c->edi, 15)); /* shl edi, 0xf */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ecx + 0xcu)))); /* add edi, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x45b1b0u)); PUSH32(c, 0x00453d55u); call_indirect(c, t_); } /* call dword ptr [0x45b1b0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00453d61; /* jne 0x453d61 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00453df4; /* jmp 0x453df4 */
L_00453d61:;
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x7000u)); /* lea edx, [edi + 0x7000] */
    (void)sub32(c, c->edi, c->edx); /* cmp edi, edx */
    if ((!c->cf && !c->zf)) goto L_00453da7; /* ja 0x453da7 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea eax, [edi + 0x10] */
L_00453d6e:;
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
    if ((c->cf || c->zf)) goto L_00453d6e; /* jbe 0x453d6e */
L_00453da7:;
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
    if (!c->zf) goto L_00453de4; /* jne 0x453de4 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + 4], edi */
L_00453de4:;
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00453df4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00453df9(CPU *c) { /* FUN_00453df9 */
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
    if ((c->zf || c->sf != c->of)) goto L_00453fa7; /* jle 0x453fa7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00453fa0; /* jne 0x453fa0 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ecx)); /* add ebx, ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_00453fa0; /* jg 0x453fa0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if ((c->cf || c->zf)) goto L_00453e70; /* jbe 0x453e70 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00453e70:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ebx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00453ec0; /* jne 0x453ec0 */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if (!c->cf) goto L_00453e9c; /* jae 0x453e9c */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00453ec0; /* jne 0x453ec0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00453ec0; /* jmp 0x453ec0 */
L_00453e9c:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00453ec0; /* jne 0x453ec0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00453ec0:;
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
    if ((c->zf || c->sf != c->of)) goto L_00453f8e; /* jle 0x453f8e */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(sar32(c, c->edi, 4)); /* sar edi, 4 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea ecx, [ecx + esi - 4] */
    (void)sub32(c, c->edi, (uint32_t)0x3fu); /* cmp edi, 0x3f */
    if ((c->cf || c->zf)) goto L_00453efa; /* jbe 0x453efa */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00453efa:;
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
    if (!c->zf) goto L_00453f7c; /* jne 0x453f7c */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + c->eax + 0x4u))); /* mov cl, byte ptr [edi + eax + 4] */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    W8((uint32_t)(c->ebp + 0x13u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0x13], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edi + eax + 4], cl */
    if (!c->cf) goto L_00453f53; /* jae 0x453f53 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00453f46; /* jne 0x453f46 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00453f46:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    goto L_00453f78; /* jmp 0x453f78 */
L_00453f53:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00453f69; /* jne 0x453f69 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00453f69:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00453f78:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00453f7c:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->esi + 0xfffffffcu)); /* lea eax, [edx + esi - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->ecx + c->eax + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + eax - 4], ecx */
    goto L_00453f91; /* jmp 0x453f91 */
L_00453f8e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
L_00453f91:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    W32((uint32_t)(c->edx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edx - 4], eax */
    W32((uint32_t)(c->edx + c->esi + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + esi - 8], eax */
    goto L_004540e7; /* jmp 0x4540e7 */
L_00453fa0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_004540ea; /* jmp 0x4540ea */
L_00453fa7:;
    if ((c->sf == c->of)) goto L_004540e7; /* jge 0x4540e7 */
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
    if ((c->cf || c->zf)) goto L_00453fd2; /* jbe 0x453fd2 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00453fd2:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 4], 1 */
    if (!c->zf) goto L_00454061; /* jne 0x454061 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00453feb; /* jbe 0x453feb */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00453feb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ecx, dword ptr [edi + 8] */
    if (!c->zf) goto L_0045403a; /* jne 0x45403a */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    if (!c->cf) goto L_00454016; /* jae 0x454016 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea esi, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esi] */
    if (!c->zf) goto L_00454037; /* jne 0x454037 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00454037; /* jmp 0x454037 */
L_00454016:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea ecx, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00454037; /* jne 0x454037 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00454037:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
L_0045403a:;
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
    if ((c->cf || c->zf)) goto L_00454061; /* jbe 0x454061 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00454061:;
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
    if (!c->zf) goto L_004540de; /* jne 0x4540de */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->cf) goto L_004540b5; /* jae 0x4540b5 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_004540a8; /* jne 0x4540a8 */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx], edi */
L_004540a8:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    goto L_004540da; /* jmp 0x4540da */
L_004540b5:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_004540cb; /* jne 0x4540cb */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 4], edi */
L_004540cb:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_004540da:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_004540de:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(c->eax + c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + ebx - 4], eax */
L_004540e7:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_004540ea:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004540ef(CPU *c) { /* PTR_004540ef */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004541bf; /* je 0x4541bf */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c688u))); /* mov ecx, dword ptr [0x47c688] */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 15)); /* shl ecx, 0xf */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->eax + 0xcu)))); /* add ecx, dword ptr [eax + 0xc] */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x45b0e8u)); PUSH32(c, 0x00454119u); call_indirect(c, t_); } /* call dword ptr [0x45b0e8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c688u))); /* mov ecx, dword ptr [0x47c688] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c688u))); /* mov ecx, dword ptr [0x47c688] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + ecx*4 + 0xc4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x43u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [eax + 0x43] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x43u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 0x43], 0 */
    if (!c->zf) goto L_00454166; /* jne 0x454166 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [eax + 4], 0xfffffffe */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
L_00454166:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + 8], -1 */
    if (!c->zf) goto L_004541b8; /* jne 0x4541b8 */
    (void)sub32(c, R32((uint32_t)(0x47c698u)), (uint32_t)0x1u); /* cmp dword ptr [0x47c698], 1 */
    if ((c->zf || c->sf != c->of)) goto L_004541b8; /* jle 0x4541b8 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b138u)); PUSH32(c, 0x00454186u); call_indirect(c, t_); } /* call dword ptr [0x45b138] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
    c->edx = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov edx, dword ptr [0x47c69c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c694u))); /* mov eax, dword ptr [0x47c694] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffffecu)); /* lea ecx, [ecx + edx - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x14u)); /* lea ecx, [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004541afu); f_00455840(c); /* call 0x455840 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(0x47c698u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x47c698] */
L_004541b8:;
    { uint32_t a_ = (uint32_t)(0x47c694u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x47c694], 0 */
L_004541bf:;
    c->esp += 4; return; /* ret  */
}

void f_004541c0(CPU *c) { /* FUN_004541c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x13cu)); /* sub esp, 0x13c */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c698u))); /* mov eax, dword ptr [0x47c698] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x47c69cu)); PUSH32(c, v_); } /* push dword ptr [0x47c69c] */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x004541e4u); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004541f0; /* je 0x4541f0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_004544ad; /* jmp 0x4544ad */
L_004541f0:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x47c69cu))); /* mov ebx, dword ptr [0x47c69c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0x47c698u)), c->edi); /* cmp dword ptr [0x47c698], edi */
    W32((uint32_t)(c->ebp + 0xffffffc8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x38], ebx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x20], edi */
    if ((c->zf || c->sf != c->of)) goto L_004544ab; /* jle 0x4544ab */
    goto L_0045420e; /* jmp 0x45420e */
L_0045420c:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_0045420e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov esi, dword ptr [ebx + 0x10] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x0045421du); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004544b2; /* jne 0x4544b2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x2c], edi */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x144u)); /* lea eax, [esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xc4u)); /* add esi, 0xc4 */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x18], edi */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x3c], esi */
    goto L_00454250; /* jmp 0x454250 */
L_0045424e:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00454250:;
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x1c], edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->eax); /* cmp dword ptr [ebp - 0x14], eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea edi, [ebp - 0x13c] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    if ((c->sf != c->of)) goto L_00454449; /* jl 0x454449 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x0045427du); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004544b6; /* jne 0x4544b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0xffcu)); /* lea edx, [eax + 0xffc] */
L_00454290:;
    (void)sub32(c, R32((uint32_t)(c->edx + 0xfffff00cu)), (uint32_t)0xffffffffu); /* cmp dword ptr [edx - 0xff4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0xfffff010u)); /* lea esi, [edx - 0xff0] */
    if (!c->zf) goto L_004544c6; /* jne 0x4544c6 */
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0xffffffffu); /* cmp dword ptr [edx], -1 */
    if (!c->zf) goto L_004544c6; /* jne 0x4544c6 */
L_004542ac:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    if (c->zf) goto L_004542c7; /* je 0x4542c7 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if ((!c->zf && c->sf == c->of)) goto L_004544ba; /* jg 0x4544ba */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    goto L_004542e3; /* jmp 0x4542e3 */
L_004542c7:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, (uint32_t)0x3fu); /* cmp eax, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_004542d5; /* jle 0x4542d5 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_004542d5:;
    { uint32_t a_ = (uint32_t)(c->ebp + c->eax * 4 + 0xfffffec4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + eax*4 - 0x13c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->eax * 4 + 0xfffffec4u)); /* lea eax, [ebp + eax*4 - 0x13c] */
L_004542e3:;
    (void)sub32(c, c->ecx, (uint32_t)0x10u); /* cmp ecx, 0x10 */
    if ((c->sf != c->of)) goto L_004544c2; /* jl 0x4544c2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0xfu)); /* test cl, 0xf */
    if (!c->zf) goto L_004544c2; /* jne 0x4544c2 */
    (void)sub32(c, c->ecx, (uint32_t)0xff0u); /* cmp ecx, 0xff0 */
    if ((!c->zf && c->sf == c->of)) goto L_004544c2; /* jg 0x4544c2 */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->esi + 0xfffffffcu)), c->edi); /* cmp dword ptr [ecx + esi - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea eax, [ecx + esi] */
    if (!c->zf) goto L_004544be; /* jne 0x4544be */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_004542ac; /* jb 0x4542ac */
    if (!c->zf) goto L_004544be; /* jne 0x4544be */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1000u)); /* add edx, 0x1000 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x8u); /* cmp ebx, 8 */
    if ((c->sf != c->of)) goto L_00454290; /* jl 0x454290 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_004544ca; /* jne 0x4544ca */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea eax, [ebp - 0x13c] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00454345:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x10], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea edi, [esi + 8] */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    if (c->zf) goto L_00454411; /* je 0x454411 */
L_0045435c:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx))); /* cmp ecx, dword ptr [ebx] */
    if (c->zf) goto L_004543e4; /* je 0x4543e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_004544da; /* jb 0x4544da */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8000u)); /* add ecx, 0x8000 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_004544da; /* jae 0x4544da */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ecx) & (uint16_t)0xf000u))); /* and cx, 0xf000 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xff0u)); /* lea edx, [ecx + 0xff0] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004544ce; /* je 0x4544ce */
L_00454397:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_004543a6; /* je 0x4543a6 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0xfffffffeu))); /* and ebx, 0xfffffffe */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00454397; /* jne 0x454397 */
L_004543a6:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004544ce; /* je 0x4544ce */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_004543bc; /* jle 0x4543bc */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_004543bc:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp ecx, dword ptr [ebp - 8] */
    if (!c->zf) goto L_004544d2; /* jne 0x4544d2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov ecx, dword ptr [ebp - 0x34] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), c->ecx); /* cmp dword ptr [eax + 8], ecx */
    if (!c->zf) goto L_004544d6; /* jne 0x4544d6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0045435c; /* jne 0x45435c */
L_004543e4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (c->zf) goto L_00454411; /* je 0x454411 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if ((c->sf == c->of)) goto L_00454401; /* jge 0x454401 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x2c], eax */
    goto L_00454411; /* jmp 0x454411 */
L_00454401:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x18], eax */
L_00454411:;
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    if (!c->zf) goto L_004544e2; /* jne 0x4544e2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx))); /* cmp eax, dword ptr [ecx] */
    if (!c->zf) goto L_004544e2; /* jne 0x4544e2 */
    (void)sub32(c, R32((uint32_t)(c->edi)), c->edx); /* cmp dword ptr [edi], edx */
    if (!c->zf) goto L_004544de; /* jne 0x4544de */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x40u); /* cmp dword ptr [ebp - 8], 0x40 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    if ((c->sf != c->of)) goto L_00454345; /* jl 0x454345 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc4u))); /* mov esi, dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc8u))); /* mov ebx, dword ptr [ebp - 0x38] */
L_00454449:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi + 0xffffff80u))); /* cmp eax, dword ptr [esi - 0x80] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi))); /* cmp eax, dword ptr [esi] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8000u))); } /* add dword ptr [ebp - 0xc], 0x8000 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x204u))); } /* add dword ptr [ebp - 0x28], 0x204 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp - 0x14], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x30] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x20u); /* cmp dword ptr [ebp - 0x30], 0x20 */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x3c], esi */
    if ((c->sf != c->of)) goto L_0045424e; /* jl 0x45424e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx))); /* cmp eax, dword ptr [ebx] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx + 0x4u))); /* cmp eax, dword ptr [ebx + 4] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffc8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x38], ebx */
    (void)sub32(c, c->eax, R32((uint32_t)(0x47c698u))); /* cmp eax, dword ptr [0x47c698] */
    if ((c->sf != c->of)) goto L_0045420c; /* jl 0x45420c */
L_004544ab:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_004544ad:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004544b2:;
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544b6:;
    { uint32_t v_ = 0xfffffffcu; PUSH32(c, v_); } /* push -4 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ba:;
    { uint32_t v_ = 0xfffffffau; PUSH32(c, v_); } /* push -6 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544be:;
    { uint32_t v_ = 0xfffffff8u; PUSH32(c, v_); } /* push -8 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544c2:;
    { uint32_t v_ = 0xfffffff9u; PUSH32(c, v_); } /* push -7 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544c6:;
    { uint32_t v_ = 0xfffffffbu; PUSH32(c, v_); } /* push -5 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ca:;
    { uint32_t v_ = 0xfffffff7u; PUSH32(c, v_); } /* push -9 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ce:;
    { uint32_t v_ = 0xfffffff5u; PUSH32(c, v_); } /* push -0xb */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544d2:;
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544d6:;
    { uint32_t v_ = 0xfffffff3u; PUSH32(c, v_); } /* push -0xd */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544da:;
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544de:;
    { uint32_t v_ = 0xfffffff1u; PUSH32(c, v_); } /* push -0xf */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544e2:;
    { uint32_t v_ = 0xfffffff2u; PUSH32(c, v_); } /* push -0xe */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544e6:;
    { uint32_t v_ = 0xfffffff0u; PUSH32(c, v_); } /* push -0x10 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ea:;
    { uint32_t v_ = 0xffffffefu; PUSH32(c, v_); } /* push -0x11 */
L_004544ec:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004544ad; /* jmp 0x4544ad */
}

void f_0045420c(CPU *c) { /* PTR_0045420c */
    PREEMPT_POLL(c);
L_0045420c:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov esi, dword ptr [ebx + 0x10] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x0045421du); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004544b2; /* jne 0x4544b2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x2c], edi */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x144u)); /* lea eax, [esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov eax, dword ptr [ebx + 8] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xc4u)); /* add esi, 0xc4 */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x18], edi */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x3c], esi */
    goto L_00454250; /* jmp 0x454250 */
L_0045424e:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00454250:;
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x1c], edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->eax); /* cmp dword ptr [ebp - 0x14], eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea edi, [ebp - 0x13c] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    if ((c->sf != c->of)) goto L_00454449; /* jl 0x454449 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x0045427du); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004544b6; /* jne 0x4544b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0xffcu)); /* lea edx, [eax + 0xffc] */
L_00454290:;
    (void)sub32(c, R32((uint32_t)(c->edx + 0xfffff00cu)), (uint32_t)0xffffffffu); /* cmp dword ptr [edx - 0xff4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0xfffff010u)); /* lea esi, [edx - 0xff0] */
    if (!c->zf) goto L_004544c6; /* jne 0x4544c6 */
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0xffffffffu); /* cmp dword ptr [edx], -1 */
    if (!c->zf) goto L_004544c6; /* jne 0x4544c6 */
L_004542ac:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    if (c->zf) goto L_004542c7; /* je 0x4542c7 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if ((!c->zf && c->sf == c->of)) goto L_004544ba; /* jg 0x4544ba */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    goto L_004542e3; /* jmp 0x4542e3 */
L_004542c7:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, (uint32_t)0x3fu); /* cmp eax, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_004542d5; /* jle 0x4542d5 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_004542d5:;
    { uint32_t a_ = (uint32_t)(c->ebp + c->eax * 4 + 0xfffffec4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + eax*4 - 0x13c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->eax * 4 + 0xfffffec4u)); /* lea eax, [ebp + eax*4 - 0x13c] */
L_004542e3:;
    (void)sub32(c, c->ecx, (uint32_t)0x10u); /* cmp ecx, 0x10 */
    if ((c->sf != c->of)) goto L_004544c2; /* jl 0x4544c2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0xfu)); /* test cl, 0xf */
    if (!c->zf) goto L_004544c2; /* jne 0x4544c2 */
    (void)sub32(c, c->ecx, (uint32_t)0xff0u); /* cmp ecx, 0xff0 */
    if ((!c->zf && c->sf == c->of)) goto L_004544c2; /* jg 0x4544c2 */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->esi + 0xfffffffcu)), c->edi); /* cmp dword ptr [ecx + esi - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea eax, [ecx + esi] */
    if (!c->zf) goto L_004544be; /* jne 0x4544be */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_004542ac; /* jb 0x4542ac */
    if (!c->zf) goto L_004544be; /* jne 0x4544be */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1000u)); /* add edx, 0x1000 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x8u); /* cmp ebx, 8 */
    if ((c->sf != c->of)) goto L_00454290; /* jl 0x454290 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_004544ca; /* jne 0x4544ca */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea eax, [ebp - 0x13c] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00454345:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x10], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea edi, [esi + 8] */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    if (c->zf) goto L_00454411; /* je 0x454411 */
L_0045435c:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx))); /* cmp ecx, dword ptr [ebx] */
    if (c->zf) goto L_004543e4; /* je 0x4543e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_004544da; /* jb 0x4544da */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8000u)); /* add ecx, 0x8000 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_004544da; /* jae 0x4544da */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ecx) & (uint16_t)0xf000u))); /* and cx, 0xf000 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xff0u)); /* lea edx, [ecx + 0xff0] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004544ce; /* je 0x4544ce */
L_00454397:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_004543a6; /* je 0x4543a6 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0xfffffffeu))); /* and ebx, 0xfffffffe */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00454397; /* jne 0x454397 */
L_004543a6:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004544ce; /* je 0x4544ce */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_004543bc; /* jle 0x4543bc */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_004543bc:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp ecx, dword ptr [ebp - 8] */
    if (!c->zf) goto L_004544d2; /* jne 0x4544d2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov ecx, dword ptr [ebp - 0x34] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), c->ecx); /* cmp dword ptr [eax + 8], ecx */
    if (!c->zf) goto L_004544d6; /* jne 0x4544d6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0045435c; /* jne 0x45435c */
L_004543e4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (c->zf) goto L_00454411; /* je 0x454411 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if ((c->sf == c->of)) goto L_00454401; /* jge 0x454401 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x2c], eax */
    goto L_00454411; /* jmp 0x454411 */
L_00454401:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x18], eax */
L_00454411:;
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    if (!c->zf) goto L_004544e2; /* jne 0x4544e2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx))); /* cmp eax, dword ptr [ecx] */
    if (!c->zf) goto L_004544e2; /* jne 0x4544e2 */
    (void)sub32(c, R32((uint32_t)(c->edi)), c->edx); /* cmp dword ptr [edi], edx */
    if (!c->zf) goto L_004544de; /* jne 0x4544de */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x40u); /* cmp dword ptr [ebp - 8], 0x40 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    if ((c->sf != c->of)) goto L_00454345; /* jl 0x454345 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc4u))); /* mov esi, dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc8u))); /* mov ebx, dword ptr [ebp - 0x38] */
L_00454449:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi + 0xffffff80u))); /* cmp eax, dword ptr [esi - 0x80] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi))); /* cmp eax, dword ptr [esi] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8000u))); } /* add dword ptr [ebp - 0xc], 0x8000 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x204u))); } /* add dword ptr [ebp - 0x28], 0x204 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp - 0x14], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x30] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x20u); /* cmp dword ptr [ebp - 0x30], 0x20 */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x3c], esi */
    if ((c->sf != c->of)) goto L_0045424e; /* jl 0x45424e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx))); /* cmp eax, dword ptr [ebx] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx + 0x4u))); /* cmp eax, dword ptr [ebx + 4] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffc8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x38], ebx */
    (void)sub32(c, c->eax, R32((uint32_t)(0x47c698u))); /* cmp eax, dword ptr [0x47c698] */
    if ((c->sf != c->of)) goto L_0045420c; /* jl 0x45420c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_004544ad:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004544b2:;
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544b6:;
    { uint32_t v_ = 0xfffffffcu; PUSH32(c, v_); } /* push -4 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ba:;
    { uint32_t v_ = 0xfffffffau; PUSH32(c, v_); } /* push -6 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544be:;
    { uint32_t v_ = 0xfffffff8u; PUSH32(c, v_); } /* push -8 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544c2:;
    { uint32_t v_ = 0xfffffff9u; PUSH32(c, v_); } /* push -7 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544c6:;
    { uint32_t v_ = 0xfffffffbu; PUSH32(c, v_); } /* push -5 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ca:;
    { uint32_t v_ = 0xfffffff7u; PUSH32(c, v_); } /* push -9 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ce:;
    { uint32_t v_ = 0xfffffff5u; PUSH32(c, v_); } /* push -0xb */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544d2:;
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544d6:;
    { uint32_t v_ = 0xfffffff3u; PUSH32(c, v_); } /* push -0xd */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544da:;
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544de:;
    { uint32_t v_ = 0xfffffff1u; PUSH32(c, v_); } /* push -0xf */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544e2:;
    { uint32_t v_ = 0xfffffff2u; PUSH32(c, v_); } /* push -0xe */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544e6:;
    { uint32_t v_ = 0xfffffff0u; PUSH32(c, v_); } /* push -0x10 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ea:;
    { uint32_t v_ = 0xffffffefu; PUSH32(c, v_); } /* push -0x11 */
L_004544ec:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004544ad; /* jmp 0x4544ad */
}

void f_0045424e(CPU *c) { /* PTR_0045424e */
    PREEMPT_POLL(c);
L_0045424e:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x1c], edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->eax); /* cmp dword ptr [ebp - 0x14], eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea edi, [ebp - 0x13c] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    if ((c->sf != c->of)) goto L_00454449; /* jl 0x454449 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x0045427du); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004544b6; /* jne 0x4544b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0xffcu)); /* lea edx, [eax + 0xffc] */
L_00454290:;
    (void)sub32(c, R32((uint32_t)(c->edx + 0xfffff00cu)), (uint32_t)0xffffffffu); /* cmp dword ptr [edx - 0xff4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->edx + 0xfffff010u)); /* lea esi, [edx - 0xff0] */
    if (!c->zf) goto L_004544c6; /* jne 0x4544c6 */
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0xffffffffu); /* cmp dword ptr [edx], -1 */
    if (!c->zf) goto L_004544c6; /* jne 0x4544c6 */
L_004542ac:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    if (c->zf) goto L_004542c7; /* je 0x4542c7 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if ((!c->zf && c->sf == c->of)) goto L_004544ba; /* jg 0x4544ba */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    goto L_004542e3; /* jmp 0x4542e3 */
L_004542c7:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->eax, (uint32_t)0x3fu); /* cmp eax, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_004542d5; /* jle 0x4542d5 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_004542d5:;
    { uint32_t a_ = (uint32_t)(c->ebp + c->eax * 4 + 0xfffffec4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + eax*4 - 0x13c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + c->eax * 4 + 0xfffffec4u)); /* lea eax, [ebp + eax*4 - 0x13c] */
L_004542e3:;
    (void)sub32(c, c->ecx, (uint32_t)0x10u); /* cmp ecx, 0x10 */
    if ((c->sf != c->of)) goto L_004544c2; /* jl 0x4544c2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0xfu)); /* test cl, 0xf */
    if (!c->zf) goto L_004544c2; /* jne 0x4544c2 */
    (void)sub32(c, c->ecx, (uint32_t)0xff0u); /* cmp ecx, 0xff0 */
    if ((!c->zf && c->sf == c->of)) goto L_004544c2; /* jg 0x4544c2 */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->esi + 0xfffffffcu)), c->edi); /* cmp dword ptr [ecx + esi - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea eax, [ecx + esi] */
    if (!c->zf) goto L_004544be; /* jne 0x4544be */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_004542ac; /* jb 0x4542ac */
    if (!c->zf) goto L_004544be; /* jne 0x4544be */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1000u)); /* add edx, 0x1000 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x8u); /* cmp ebx, 8 */
    if ((c->sf != c->of)) goto L_00454290; /* jl 0x454290 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_004544ca; /* jne 0x4544ca */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffec4u)); /* lea eax, [ebp - 0x13c] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00454345:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x10], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea edi, [esi + 8] */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    if (c->zf) goto L_00454411; /* je 0x454411 */
L_0045435c:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx))); /* cmp ecx, dword ptr [ebx] */
    if (c->zf) goto L_004543e4; /* je 0x4543e4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_004544da; /* jb 0x4544da */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8000u)); /* add ecx, 0x8000 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_004544da; /* jae 0x4544da */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->ecx) & (uint16_t)0xf000u))); /* and cx, 0xf000 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xcu)); /* add ecx, 0xc */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xff0u)); /* lea edx, [ecx + 0xff0] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004544ce; /* je 0x4544ce */
L_00454397:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_004543a6; /* je 0x4543a6 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0xfffffffeu))); /* and ebx, 0xfffffffe */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00454397; /* jne 0x454397 */
L_004543a6:;
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004544ce; /* je 0x4544ce */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_004543bc; /* jle 0x4543bc */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_004543bc:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp ecx, dword ptr [ebp - 8] */
    if (!c->zf) goto L_004544d2; /* jne 0x4544d2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov ecx, dword ptr [ebp - 0x34] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), c->ecx); /* cmp dword ptr [eax + 8], ecx */
    if (!c->zf) goto L_004544d6; /* jne 0x4544d6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0045435c; /* jne 0x45435c */
L_004543e4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (c->zf) goto L_00454411; /* je 0x454411 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if ((c->sf == c->of)) goto L_00454401; /* jge 0x454401 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x2c], eax */
    goto L_00454411; /* jmp 0x454411 */
L_00454401:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [ebp - 0x18], eax */
L_00454411:;
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    if (!c->zf) goto L_004544e2; /* jne 0x4544e2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx))); /* cmp eax, dword ptr [ecx] */
    if (!c->zf) goto L_004544e2; /* jne 0x4544e2 */
    (void)sub32(c, R32((uint32_t)(c->edi)), c->edx); /* cmp dword ptr [edi], edx */
    if (!c->zf) goto L_004544de; /* jne 0x4544de */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x40u); /* cmp dword ptr [ebp - 8], 0x40 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    if ((c->sf != c->of)) goto L_00454345; /* jl 0x454345 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc4u))); /* mov esi, dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc8u))); /* mov ebx, dword ptr [ebp - 0x38] */
L_00454449:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi + 0xffffff80u))); /* cmp eax, dword ptr [esi - 0x80] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi))); /* cmp eax, dword ptr [esi] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8000u))); } /* add dword ptr [ebp - 0xc], 0x8000 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x204u))); } /* add dword ptr [ebp - 0x28], 0x204 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp - 0x14], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x30] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x20u); /* cmp dword ptr [ebp - 0x30], 0x20 */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x3c], esi */
    if ((c->sf != c->of)) goto L_0045424e; /* jl 0x45424e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx))); /* cmp eax, dword ptr [ebx] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx + 0x4u))); /* cmp eax, dword ptr [ebx + 4] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffc8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x38], ebx */
    (void)sub32(c, c->eax, R32((uint32_t)(0x47c698u))); /* cmp eax, dword ptr [0x47c698] */
    if ((c->sf != c->of)) { f_0045420c(c); return; } /* jl 0x45420c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_004544ad:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004544b6:;
    { uint32_t v_ = 0xfffffffcu; PUSH32(c, v_); } /* push -4 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ba:;
    { uint32_t v_ = 0xfffffffau; PUSH32(c, v_); } /* push -6 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544be:;
    { uint32_t v_ = 0xfffffff8u; PUSH32(c, v_); } /* push -8 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544c2:;
    { uint32_t v_ = 0xfffffff9u; PUSH32(c, v_); } /* push -7 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544c6:;
    { uint32_t v_ = 0xfffffffbu; PUSH32(c, v_); } /* push -5 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ca:;
    { uint32_t v_ = 0xfffffff7u; PUSH32(c, v_); } /* push -9 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ce:;
    { uint32_t v_ = 0xfffffff5u; PUSH32(c, v_); } /* push -0xb */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544d2:;
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544d6:;
    { uint32_t v_ = 0xfffffff3u; PUSH32(c, v_); } /* push -0xd */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544da:;
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544de:;
    { uint32_t v_ = 0xfffffff1u; PUSH32(c, v_); } /* push -0xf */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544e2:;
    { uint32_t v_ = 0xfffffff2u; PUSH32(c, v_); } /* push -0xe */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544e6:;
    { uint32_t v_ = 0xfffffff0u; PUSH32(c, v_); } /* push -0x10 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ea:;
    { uint32_t v_ = 0xffffffefu; PUSH32(c, v_); } /* push -0x11 */
L_004544ec:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004544ad; /* jmp 0x4544ad */
}

void f_0045444f(CPU *c) { /* PTR_0045444f */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esi))); /* cmp eax, dword ptr [esi] */
    if (!c->zf) goto L_004544e6; /* jne 0x4544e6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8000u))); } /* add dword ptr [ebp - 0xc], 0x8000 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x204u))); } /* add dword ptr [ebp - 0x28], 0x204 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp - 0x14], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x30] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x20u); /* cmp dword ptr [ebp - 0x30], 0x20 */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x3c], esi */
    if ((c->sf != c->of)) { f_0045424e(c); return; } /* jl 0x45424e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx))); /* cmp eax, dword ptr [ebx] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebx + 0x4u))); /* cmp eax, dword ptr [ebx + 4] */
    if (!c->zf) goto L_004544ea; /* jne 0x4544ea */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffc8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x38], ebx */
    (void)sub32(c, c->eax, R32((uint32_t)(0x47c698u))); /* cmp eax, dword ptr [0x47c698] */
    if ((c->sf != c->of)) { f_0045420c(c); return; } /* jl 0x45420c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_004544ad:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004544e6:;
    { uint32_t v_ = 0xfffffff0u; PUSH32(c, v_); } /* push -0x10 */
    goto L_004544ec; /* jmp 0x4544ec */
L_004544ea:;
    { uint32_t v_ = 0xffffffefu; PUSH32(c, v_); } /* push -0x11 */
L_004544ec:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004544ad; /* jmp 0x4544ad */
}

void f_004544ef(CPU *c) { /* PTR_004544ef */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x46f16cu))); /* mov eax, dword ptr [0x46f16c] */
    c->esp += 4; return; /* ret  */
}

void f_00454511(CPU *c) { /* FUN_00454511 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x46d158u)), (uint32_t)0xffffffffu); /* cmp dword ptr [0x46d158], -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00454525; /* jne 0x454525 */
    c->esi = (uint32_t)((uint32_t)0x46d148u); /* mov esi, 0x46d148 */
    goto L_00454542; /* jmp 0x454542 */
L_00454525:;
    { uint32_t v_ = 0x2020u; PUSH32(c, v_); } /* push 0x2020 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b134u)); PUSH32(c, 0x00454538u); call_indirect(c, t_); } /* call dword ptr [0x45b134] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_0045464e; /* je 0x45464e */
L_00454542:;
    c->ebp = (uint32_t)(R32((uint32_t)(0x45b1b0u))); /* mov ebp, dword ptr [0x45b1b0] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x400000u; PUSH32(c, v_); } /* push 0x400000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00454558u); call_indirect(c, t_); } /* call ebp */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00454637; /* je 0x454637 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->ebx = (uint32_t)((uint32_t)0x10000u); /* mov ebx, 0x10000 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00454572u); call_indirect(c, t_); } /* call ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00454629; /* je 0x454629 */
    c->eax = (uint32_t)((uint32_t)0x46d148u); /* mov eax, 0x46d148 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->zf) goto L_004545a1; /* jne 0x4545a1 */
    (void)sub32(c, R32((uint32_t)(0x46d148u)), (uint32_t)0x0u); /* cmp dword ptr [0x46d148], 0 */
    if (!c->zf) goto L_00454591; /* jne 0x454591 */
    W32((uint32_t)(0x46d148u), (uint32_t)(c->eax)); /* mov dword ptr [0x46d148], eax */
L_00454591:;
    (void)sub32(c, R32((uint32_t)(0x46d14cu)), (uint32_t)0x0u); /* cmp dword ptr [0x46d14c], 0 */
    if (!c->zf) goto L_004545b6; /* jne 0x4545b6 */
    W32((uint32_t)(0x46d14cu), (uint32_t)(c->eax)); /* mov dword ptr [0x46d14c], eax */
    goto L_004545b6; /* jmp 0x4545b6 */
L_004545a1:;
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x46d14cu))); /* mov eax, dword ptr [0x46d14c] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(0x46d14cu), (uint32_t)(c->esi)); /* mov dword ptr [0x46d14c], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_004545b6:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x400000u)); /* lea eax, [edi + 0x400000] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x98u)); /* lea ecx, [esi + 0x98] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea eax, [esi + 0x18] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)((uint32_t)0xf1u); /* mov ecx, 0xf1 */
L_004545d8:;
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
    if ((c->sf != c->of)) goto L_004545d8; /* jl 0x4545d8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x004545feu); f_0044d730(c); /* call 0x44d730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00454601:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00454625; /* jae 0x454625 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xf8u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xffu)))); } /* or byte ptr [edi + 0xf8], 0xff */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf0u)); /* mov dword ptr [edi + 4], 0xf0 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x1000u)); /* add edi, 0x1000 */
    goto L_00454601; /* jmp 0x454601 */
L_00454625:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00454650; /* jmp 0x454650 */
L_00454629:;
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x45b0e8u)); PUSH32(c, 0x00454637u); call_indirect(c, t_); } /* call dword ptr [0x45b0e8] */
L_00454637:;
    (void)sub32(c, c->esi, (uint32_t)0x46d148u); /* cmp esi, 0x46d148 */
    if (c->zf) goto L_0045464e; /* je 0x45464e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b138u)); PUSH32(c, 0x0045464eu); call_indirect(c, t_); } /* call dword ptr [0x45b138] */
L_0045464e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00454650:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00454655(CPU *c) { /* FUN_00454655 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0x45b0e8u)); PUSH32(c, 0x0045466au); call_indirect(c, t_); } /* call dword ptr [0x45b0e8] */
    (void)sub32(c, R32((uint32_t)(0x46f168u)), c->esi); /* cmp dword ptr [0x46f168], esi */
    if (!c->zf) goto L_0045467a; /* jne 0x45467a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(0x46f168u), (uint32_t)(c->eax)); /* mov dword ptr [0x46f168], eax */
L_0045467a:;
    (void)sub32(c, c->esi, (uint32_t)0x46d148u); /* cmp esi, 0x46d148 */
    if (c->zf) goto L_004546a2; /* je 0x4546a2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    { uint32_t v_ = R32((uint32_t)(0x47c6a4u)); PUSH32(c, v_); } /* push dword ptr [0x47c6a4] */
    { uint32_t t_ = R32((uint32_t)(0x45b138u)); PUSH32(c, 0x004546a0u); call_indirect(c, t_); } /* call dword ptr [0x45b138] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_004546a2:;
    { uint32_t a_ = (uint32_t)(0x46d158u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x46d158], 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_004546ab(CPU *c) { /* FUN_004546ab */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x46d14cu))); /* mov esi, dword ptr [0x46d14c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_004546b8:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi + 0x10], -1 */
    if (c->zf) goto L_00454756; /* je 0x454756 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2010u)); /* lea edi, [esi + 0x2010] */
    c->ebx = (uint32_t)((uint32_t)0x3ff000u); /* mov ebx, 0x3ff000 */
L_004546d1:;
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xf0u); /* cmp dword ptr [edi], 0xf0 */
    if (!c->zf) goto L_00454712; /* jne 0x454712 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->esi + 0x10u)))); /* add eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b0e8u)); PUSH32(c, 0x004546efu); call_indirect(c, t_); } /* call dword ptr [0x45b0e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00454712; /* je 0x454712 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(0x47c3ecu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x47c3ec] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00454707; /* je 0x454707 */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_0045470a; /* jbe 0x45470a */
L_00454707:;
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
L_0045470a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (c->zf) goto L_0045471f; /* je 0x45471f */
L_00454712:;
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x1000u)); /* sub ebx, 0x1000 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x8u)); /* sub edi, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_004546d1; /* jge 0x4546d1 */
L_0045471f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    if (c->zf) goto L_00454756; /* je 0x454756 */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x18u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + 0x18], -1 */
    if (!c->zf) goto L_00454756; /* jne 0x454756 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea eax, [ecx + 0x20] */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00454736:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00454747; /* jne 0x454747 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if ((c->sf != c->of)) goto L_00454736; /* jl 0x454736 */
L_00454747:;
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (!c->zf) goto L_00454756; /* jne 0x454756 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00454755u); f_00454655(c); /* call 0x454655 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00454756:;
    (void)sub32(c, c->esi, R32((uint32_t)(0x46d14cu))); /* cmp esi, dword ptr [0x46d14c] */
    if (c->zf) goto L_00454768; /* je 0x454768 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_004546b8; /* jg 0x4546b8 */
L_00454768:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045476d(CPU *c) { /* FUN_0045476d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0x46d148u); /* mov edx, 0x46d148 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
L_00454779:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x10u))); /* cmp eax, dword ptr [ecx + 0x10] */
    if ((c->cf || c->zf)) goto L_00454783; /* jbe 0x454783 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x14u))); /* cmp eax, dword ptr [ecx + 0x14] */
    if (c->cf) goto L_0045478b; /* jb 0x45478b */
L_00454783:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_004547c0; /* je 0x4547c0 */
    goto L_00454779; /* jmp 0x454779 */
L_0045478b:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu)); /* test al, 0xf */
    if (!c->zf) goto L_004547c0; /* jne 0x4547c0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)((uint32_t)0x100u); /* mov edx, 0x100 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffu))); /* and esi, 0xfff */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_004547c0; /* jb 0x4547c0 */
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
L_004547c0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_004547c4(CPU *c) { /* FUN_004547c4 */
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
    if (!c->zf) goto L_00454808; /* jne 0x454808 */
    { uint32_t a_ = (uint32_t)(0x47c3ecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x47c3ec] */
    (void)sub32(c, R32((uint32_t)(0x47c3ecu)), (uint32_t)0x20u); /* cmp dword ptr [0x47c3ec], 0x20 */
    if (!c->zf) goto L_00454808; /* jne 0x454808 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00454807u); f_004546ab(c); /* call 0x4546ab */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00454808:;
    c->esp += 4; return; /* ret  */
}

void f_00454809(CPU *c) { /* FUN_00454809 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x46f168u))); /* mov esi, dword ptr [0x46f168] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00454817:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (c->zf) goto L_004548c2; /* je 0x4548c2 */
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
    if (!c->cf) goto L_0045487c; /* jae 0x45487c */
L_00454842:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00454865; /* jl 0x454865 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00454865; /* jbe 0x454865 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00454858u); f_00454a11(c); /* call 0x454a11 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004548d4; /* jne 0x4548d4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00454865:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2018u)); /* lea ecx, [esi + 0x2018] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (c->cf) goto L_00454842; /* jb 0x454842 */
    goto L_0045487f; /* jmp 0x45487f */
L_0045487c:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_0045487f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    if (!c->cf) goto L_004548c5; /* jae 0x4548c5 */
L_00454892:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf != c->of)) goto L_004548b1; /* jl 0x4548b1 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_004548b1; /* jbe 0x4548b1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x004548a7u); f_00454a11(c); /* call 0x454a11 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004548d4; /* jne 0x4548d4 */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_004548b1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x1000u))); } /* add dword ptr [ebp - 4], 0x1000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp edi, dword ptr [ebp - 8] */
    if (c->cf) goto L_00454892; /* jb 0x454892 */
    goto L_004548c5; /* jmp 0x4548c5 */
L_004548c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_004548c5:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x46f168u))); /* cmp esi, dword ptr [0x46f168] */
    if (c->zf) goto L_004548e4; /* je 0x4548e4 */
    goto L_00454817; /* jmp 0x454817 */
L_004548d4:;
    W32((uint32_t)(0x46f168u), (uint32_t)(c->esi)); /* mov dword ptr [0x46f168], esi */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(sub32(c, R32(a_), c->ebx))); } /* sub dword ptr [edi], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    goto L_00454a0c; /* jmp 0x454a0c */
L_004548e4:;
    c->eax = (uint32_t)((uint32_t)0x46d148u); /* mov eax, 0x46d148 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_004548eb:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi + 0x10], -1 */
    if (c->zf) goto L_004548f7; /* je 0x4548f7 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [edi + 0xc], 0 */
    if (!c->zf) goto L_00454903; /* jne 0x454903 */
L_004548f7:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->zf) goto L_004549d8; /* je 0x4549d8 */
    goto L_004548eb; /* jmp 0x4548eb */
L_00454903:;
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
    if (!c->zf) goto L_00454932; /* jne 0x454932 */
L_00454921:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x10u); /* cmp dword ptr [ebp - 4], 0x10 */
    if ((c->sf == c->of)) goto L_00454932; /* jge 0x454932 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (c->zf) goto L_00454921; /* je 0x454921 */
L_00454932:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(shl32(c, c->eax, 12)); /* shl eax, 0xc */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t t_ = R32((uint32_t)(0x45b1b0u)); PUSH32(c, 0x0045494au); call_indirect(c, t_); } /* call dword ptr [0x45b1b0] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00454a0a; /* jne 0x454a0a */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0045495du); f_0044d730(c); /* call 0x44d730 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00454999; /* jle 0x454999 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
L_0045496f:;
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
    if (!c->zf) goto L_0045496f; /* jne 0x45496f */
L_00454999:;
    W32((uint32_t)(0x46f168u), (uint32_t)(c->edi)); /* mov dword ptr [0x46f168], edi */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2018u)); /* lea eax, [edi + 0x2018] */
L_004549a5:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->cf) goto L_004549b5; /* jae 0x4549b5 */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx], -1 */
    if (c->zf) goto L_004549b3; /* je 0x4549b3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    goto L_004549a5; /* jmp 0x4549a5 */
L_004549b3:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
L_004549b5:;
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
    goto L_00454a0c; /* jmp 0x454a0c */
L_004549d8:;
    PUSH32(c, 0x004549ddu); f_00454511(c); /* call 0x454511 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00454a0a; /* je 0x454a0a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    W8((uint32_t)(c->ecx + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx + 8], bl */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ebx + 0x8u)); /* lea edx, [ecx + ebx + 8] */
    W32((uint32_t)(0x46f168u), (uint32_t)(c->eax)); /* mov dword ptr [0x46f168], eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)((uint32_t)0xf0u); /* mov edx, 0xf0 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx edx, bl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x18u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [eax + 0x18], edx */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x100u)); /* lea eax, [ecx + 0x100] */
    goto L_00454a0c; /* jmp 0x454a0c */
L_00454a0a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00454a0c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00454a11(CPU *c) { /* FUN_00454a11 */
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
    if (c->cf) goto L_00454a56; /* jb 0x454a56 */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->cf) goto L_00454a45; /* jae 0x454a45 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [ecx], edx */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [ecx + 4], edx */
    goto L_00454a4e; /* jmp 0x454a4e */
L_00454a45:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00454a4e:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    goto L_00454b24; /* jmp 0x454b24 */
L_00454a56:;
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_00454a5f; /* je 0x454a5f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00454a5f:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->cf) goto L_00454aa9; /* jae 0x454aa9 */
L_00454a66:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (!c->zf) goto L_00454a9c; /* jne 0x454a9c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ebx, [eax + 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00454a72:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00454a7b; /* jne 0x454a7b */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00454a72; /* jmp 0x454a72 */
L_00454a7b:;
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (!c->cf) goto L_00454acd; /* jae 0x454acd */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp eax, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00454a89; /* jne 0x454a89 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00454a95; /* jmp 0x454a95 */
L_00454a89:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 0xc], esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00454b2e; /* jb 0x454b2e */
L_00454a95:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00454aa1; /* jmp 0x454aa1 */
L_00454a9c:;
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
L_00454aa1:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x8u))); /* cmp esi, dword ptr [ebp + 8] */
    if (c->cf) goto L_00454a66; /* jb 0x454a66 */
L_00454aa9:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
L_00454aac:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->cf) goto L_00454b2e; /* jae 0x454b2e */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea eax, [esi + edx] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u))); /* cmp eax, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00454b2e; /* jae 0x454b2e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00454afe; /* jne 0x454afe */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ebx, [esi + 1] */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00454ac4:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00454aee; /* jne 0x454aee */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00454ac4; /* jmp 0x454ac4 */
L_00454acd:;
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea ebx, [eax + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00454ade; /* jae 0x454ade */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00454ae7; /* jmp 0x454ae7 */
L_00454ade:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00454ae7:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    goto L_00454b24; /* jmp 0x454b24 */
L_00454aee:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->cf) goto L_00454b05; /* jae 0x454b05 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [ebp + 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00454b2e; /* jb 0x454b2e */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    goto L_00454aac; /* jmp 0x454aac */
L_00454afe:;
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    goto L_00454aac; /* jmp 0x454aac */
L_00454b05:;
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea ebx, [esi + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00454b16; /* jae 0x454b16 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    goto L_00454b1f; /* jmp 0x454b1f */
L_00454b16:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00454b1f:;
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
L_00454b24:;
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0xfu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0xf */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00454b30; /* jmp 0x454b30 */
L_00454b2e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00454b30:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00454b35(CPU *c) { /* FUN_00454b35 */
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
    if ((c->cf || c->zf)) goto L_00454b6f; /* jbe 0x454b6f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [edi + 4], 0xf1 */
    goto L_00454bcf; /* jmp 0x454bcf */
L_00454b6f:;
    if (!c->cf) goto L_00454bd6; /* jae 0x454bd6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->eax)); /* lea esi, [edx + eax] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00454bd6; /* jb 0x454bd6 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea eax, [ecx + edx] */
L_00454b84:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00454b92; /* jae 0x454b92 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00454b90; /* jne 0x454b90 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00454b84; /* jmp 0x454b84 */
L_00454b90:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
L_00454b92:;
    if (!c->zf) goto L_00454bd6; /* jne 0x454bd6 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x14u))); /* mov al, byte ptr [ebp + 0x14] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if ((!c->cf && !c->zf)) goto L_00454bca; /* ja 0x454bca */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00454bca; /* jbe 0x454bca */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00454bc1; /* jae 0x454bc1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebx), (uint32_t)(c->esi)); /* mov dword ptr [ebx], esi */
    (void)sub8(c, R8((uint32_t)(c->esi)), ((uint8_t)c->eax)); /* cmp byte ptr [esi], al */
    if (!c->zf) goto L_00454bbc; /* jne 0x454bbc */
L_00454bb5:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->esi + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [esi + eax], 0 */
    if (c->zf) goto L_00454bb5; /* je 0x454bb5 */
L_00454bbc:;
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    goto L_00454bca; /* jmp 0x454bca */
L_00454bc1:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea eax, [ebx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00454bca:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x14u)))); /* sub ecx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
L_00454bcf:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
L_00454bd6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00454bde(CPU *c) { /* FUN_00454bde */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((uint32_t)0x46d148u); /* mov edx, 0x46d148 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
L_00454bf3:;
    (void)sub32(c, R32((uint32_t)(0x46f168u)), c->edx); /* cmp dword ptr [0x46f168], edx */
    if (!c->zf) goto L_00454bfe; /* jne 0x454bfe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
L_00454bfe:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov ecx, dword ptr [edx + 0x10] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00454cf6; /* je 0x454cf6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x18], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x18u)); /* lea eax, [edx + 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea edi, [ebx + 8] */
L_00454c1d:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00454c39; /* jne 0x454c39 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_00454c31; /* jne 0x454c31 */
    (void)sub32(c, R32((uint32_t)(c->edx + 0xcu)), c->eax); /* cmp dword ptr [edx + 0xc], eax */
    if (!c->zf) goto L_00454d08; /* jne 0x454d08 */
L_00454c31:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    goto L_00454cd7; /* jmp 0x454cd7 */
L_00454c39:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov esi, dword ptr [ebx] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xf0u)); /* lea ecx, [edi + 0xf0] */
    (void)sub32(c, c->esi, c->ecx); /* cmp esi, ecx */
    if (!c->cf) goto L_00454d0d; /* jae 0x454d0d */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0xffu); /* cmp byte ptr [ecx], 0xff */
    if (!c->zf) goto L_00454d12; /* jne 0x454d12 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebp - 8], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebp - 0x10], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebp - 4], ecx */
L_00454c5d:;
    c->esi = (uint32_t)((uint32_t)(c->edi + c->ecx)); /* lea esi, [edi + ecx] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebx))); /* cmp esi, dword ptr [ebx] */
    if (!c->zf) goto L_00454c6a; /* jne 0x454c6a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
L_00454c6a:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (!c->zf) goto L_00454c78; /* jne 0x454c78 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_00454cc2; /* jmp 0x454cc2 */
L_00454c78:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax + 0x4u))); /* cmp edx, dword ptr [eax + 4] */
    if ((c->sf == c->of)) goto L_00454d16; /* jge 0x454d16 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x1u); /* cmp dword ptr [ebp - 8], 1 */
    if (!c->zf) goto L_00454c9f; /* jne 0x454c9f */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xfffffffcu))); /* cmp eax, dword ptr [edi - 4] */
    if ((c->sf != c->of)) goto L_00454d1a; /* jl 0x454d1a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 8], 2 */
L_00454c9f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0x1u)); /* lea edx, [ecx + 1] */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->esi))); /* movzx esi, byte ptr [esi] */
L_00454ca9:;
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if ((c->sf == c->of)) goto L_00454cbd; /* jge 0x454cbd */
    (void)sub8(c, R8((uint32_t)(c->edi + c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edi + edx], 0 */
    if (!c->zf) goto L_00454d1e; /* jne 0x454d1e */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + c->ebx + 0x8u))); /* movzx esi, byte ptr [ecx + ebx + 8] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    goto L_00454ca9; /* jmp 0x454ca9 */
L_00454cbd:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov edx, dword ptr [ebp - 0x20] */
L_00454cc2:;
    (void)sub32(c, c->ecx, (uint32_t)0xf0u); /* cmp ecx, 0xf0 */
    if ((c->sf != c->of)) goto L_00454c5d; /* jl 0x454c5d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax))); /* cmp ecx, dword ptr [eax] */
    if (!c->zf) goto L_00454d22; /* jne 0x454d22 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if (c->zf) goto L_00454d26; /* je 0x454d26 */
L_00454cd7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x18] */
    c->ecx = (uint32_t)((uint32_t)0x1000u); /* mov ecx, 0x1000 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ecx)); /* add ebx, ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->ecx)); /* add edi, ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), (uint32_t)0x400u); /* cmp dword ptr [ebp - 0x18], 0x400 */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    if ((c->sf != c->of)) goto L_00454c1d; /* jl 0x454c1d */
L_00454cf6:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov edx, dword ptr [edx] */
    (void)sub32(c, c->edx, (uint32_t)0x46d148u); /* cmp edx, 0x46d148 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    if (c->zf) goto L_00454d2a; /* je 0x454d2a */
    goto L_00454bf3; /* jmp 0x454bf3 */
L_00454d08:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00454d37; /* jmp 0x454d37 */
L_00454d0d:;
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
L_00454d0f:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00454d37; /* jmp 0x454d37 */
L_00454d12:;
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    goto L_00454d0f; /* jmp 0x454d0f */
L_00454d16:;
    { uint32_t v_ = 0xfffffffcu; PUSH32(c, v_); } /* push -4 */
    goto L_00454d0f; /* jmp 0x454d0f */
L_00454d1a:;
    { uint32_t v_ = 0xfffffffbu; PUSH32(c, v_); } /* push -5 */
    goto L_00454d0f; /* jmp 0x454d0f */
L_00454d1e:;
    { uint32_t v_ = 0xfffffffau; PUSH32(c, v_); } /* push -6 */
    goto L_00454d0f; /* jmp 0x454d0f */
L_00454d22:;
    { uint32_t v_ = 0xfffffff9u; PUSH32(c, v_); } /* push -7 */
    goto L_00454d0f; /* jmp 0x454d0f */
L_00454d26:;
    { uint32_t v_ = 0xfffffff8u; PUSH32(c, v_); } /* push -8 */
    goto L_00454d0f; /* jmp 0x454d0f */
L_00454d2a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x9u))); /* and eax, 9 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff7u)); /* add eax, -9 */
L_00454d37:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00454d3c(CPU *c) { /* PTR_00454d3c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c3f4u))); /* mov eax, dword ptr [0x47c3f4] */
    W32((uint32_t)(0x47c3f4u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c3f4], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00454d41(CPU *c) { /* PTR_00454d41 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00454d41u, "hlt"); /* hlt  */
}

void f_00454d52(CPU *c) { /* FUN_00454d52 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c3f4u))); /* mov eax, dword ptr [0x47c3f4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00454d6a; /* je 0x454d6a */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00454d61u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00454d6a; /* je 0x454d6a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00454d6a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00454d6d(CPU *c) { /* FUN_00454d6d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00454d79u); f_00454eae(c); /* call 0x454eae */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00454ea2; /* je 0x454ea2 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00454ea2; /* je 0x454ea2 */
    (void)sub32(c, c->ebx, (uint32_t)0x5u); /* cmp ebx, 5 */
    if (!c->zf) goto L_00454d9e; /* jne 0x454d9e */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00454eab; /* jmp 0x454eab */
L_00454d9e:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (c->zf) goto L_00454e9d; /* je 0x454e9d */
    c->ecx = (uint32_t)(R32((uint32_t)(0x47c3f8u))); /* mov ecx, dword ptr [0x47c3f8] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(0x47c3f8u), (uint32_t)(c->ecx)); /* mov dword ptr [0x47c3f8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (!c->zf) goto L_00454e8d; /* jne 0x454e8d */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46f1e8u))); /* mov ecx, dword ptr [0x46f1e8] */
    c->edx = (uint32_t)(R32((uint32_t)(0x46f1ecu))); /* mov edx, dword ptr [0x46f1ec] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf == c->of)) goto L_00454ded; /* jge 0x454ded */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea esi, [ecx + ecx*2] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi * 4 + 0x46f178u)); /* lea esi, [esi*4 + 0x46f178] */
L_00454de4:;
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xcu)); /* add esi, 0xc */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00454de4; /* jne 0x454de4 */
L_00454ded:;
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->esi = (uint32_t)(R32((uint32_t)(0x46f1f4u))); /* mov esi, dword ptr [0x46f1f4] */
    (void)sub32(c, c->eax, (uint32_t)0xc000008eu); /* cmp eax, 0xc000008e */
    if (!c->zf) goto L_00454e08; /* jne 0x454e08 */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x83u)); /* mov dword ptr [0x46f1f4], 0x83 */
    goto L_00454e78; /* jmp 0x454e78 */
L_00454e08:;
    (void)sub32(c, c->eax, (uint32_t)0xc0000090u); /* cmp eax, 0xc0000090 */
    if (!c->zf) goto L_00454e1b; /* jne 0x454e1b */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x81u)); /* mov dword ptr [0x46f1f4], 0x81 */
    goto L_00454e78; /* jmp 0x454e78 */
L_00454e1b:;
    (void)sub32(c, c->eax, (uint32_t)0xc0000091u); /* cmp eax, 0xc0000091 */
    if (!c->zf) goto L_00454e2e; /* jne 0x454e2e */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x84u)); /* mov dword ptr [0x46f1f4], 0x84 */
    goto L_00454e78; /* jmp 0x454e78 */
L_00454e2e:;
    (void)sub32(c, c->eax, (uint32_t)0xc0000093u); /* cmp eax, 0xc0000093 */
    if (!c->zf) goto L_00454e41; /* jne 0x454e41 */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x85u)); /* mov dword ptr [0x46f1f4], 0x85 */
    goto L_00454e78; /* jmp 0x454e78 */
L_00454e41:;
    (void)sub32(c, c->eax, (uint32_t)0xc000008du); /* cmp eax, 0xc000008d */
    if (!c->zf) goto L_00454e54; /* jne 0x454e54 */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x82u)); /* mov dword ptr [0x46f1f4], 0x82 */
    goto L_00454e78; /* jmp 0x454e78 */
L_00454e54:;
    (void)sub32(c, c->eax, (uint32_t)0xc000008fu); /* cmp eax, 0xc000008f */
    if (!c->zf) goto L_00454e67; /* jne 0x454e67 */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x86u)); /* mov dword ptr [0x46f1f4], 0x86 */
    goto L_00454e78; /* jmp 0x454e78 */
L_00454e67:;
    (void)sub32(c, c->eax, (uint32_t)0xc0000092u); /* cmp eax, 0xc0000092 */
    if (!c->zf) goto L_00454e78; /* jne 0x454e78 */
    W32((uint32_t)(0x46f1f4u), (uint32_t)((uint32_t)0x8au)); /* mov dword ptr [0x46f1f4], 0x8a */
L_00454e78:;
    { uint32_t v_ = R32((uint32_t)(0x46f1f4u)); PUSH32(c, v_); } /* push dword ptr [0x46f1f4] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00454e82u); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x46f1f4u), (uint32_t)(c->esi)); /* mov dword ptr [0x46f1f4], esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    goto L_00454e95; /* jmp 0x454e95 */
L_00454e8d:;
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00454e94u); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00454e95:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0x47c3f8u), (uint32_t)(c->eax)); /* mov dword ptr [0x47c3f8], eax */
L_00454e9d:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00454eab; /* jmp 0x454eab */
L_00454ea2:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x45b1bcu)); PUSH32(c, 0x00454eabu); call_indirect(c, t_); } /* call dword ptr [0x45b1bc] */
L_00454eab:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00454eae(CPU *c) { /* FUN_00454eae */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x46f1f0u))); /* mov ecx, dword ptr [0x46f1f0] */
    (void)sub32(c, R32((uint32_t)(0x46f170u)), c->edx); /* cmp dword ptr [0x46f170], edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)0x46f170u); /* mov eax, 0x46f170 */
    if (c->zf) goto L_00454edb; /* je 0x454edb */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea esi, [ecx + ecx*2] */
    c->esi = (uint32_t)((uint32_t)(c->esi * 4 + 0x46f170u)); /* lea esi, [esi*4 + 0x46f170] */
L_00454ed0:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00454edb; /* jae 0x454edb */
    (void)sub32(c, R32((uint32_t)(c->eax)), c->edx); /* cmp dword ptr [eax], edx */
    if (!c->zf) goto L_00454ed0; /* jne 0x454ed0 */
L_00454edb:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx * 4 + 0x46f170u)); /* lea ecx, [ecx*4 + 0x46f170] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00454eee; /* jae 0x454eee */
    (void)sub32(c, R32((uint32_t)(c->eax)), c->edx); /* cmp dword ptr [eax], edx */
    if (c->zf) goto L_00454ef0; /* je 0x454ef0 */
L_00454eee:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00454ef0:;
    c->esp += 4; return; /* ret  */
}

void f_00454ef1(CPU *c) { /* FUN_00454ef1 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x47c6b0u)), (uint32_t)0x0u); /* cmp dword ptr [0x47c6b0], 0 */
    if (!c->zf) goto L_00454eff; /* jne 0x454eff */
    PUSH32(c, 0x00454effu); f_004513ec(c); /* call 0x4513ec */
L_00454eff:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x47d904u))); /* mov esi, dword ptr [0x47d904] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (!c->zf) goto L_00454f31; /* jne 0x454f31 */
L_00454f0c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x22u); /* cmp al, 0x22 */
    if (c->zf) goto L_00454f29; /* je 0x454f29 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00454f29; /* je 0x454f29 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00454f21u); f_0045860c(c); /* call 0x45860c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00454f0c; /* je 0x454f0c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00454f0c; /* jmp 0x454f0c */
L_00454f29:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x22u); /* cmp byte ptr [esi], 0x22 */
    if (!c->zf) goto L_00454f3b; /* jne 0x454f3b */
L_00454f2e:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00454f3b; /* jmp 0x454f3b */
L_00454f31:;
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u); /* cmp al, 0x20 */
    if ((c->cf || c->zf)) goto L_00454f3b; /* jbe 0x454f3b */
L_00454f35:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x20u); /* cmp byte ptr [esi], 0x20 */
    if ((!c->cf && !c->zf)) goto L_00454f35; /* ja 0x454f35 */
L_00454f3b:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00454f45; /* je 0x454f45 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u); /* cmp al, 0x20 */
    if ((c->cf || c->zf)) goto L_00454f2e; /* jbe 0x454f2e */
L_00454f45:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00454f49(CPU *c) { /* FUN_00454f49 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x47c6b0u)), c->ebx); /* cmp dword ptr [0x47c6b0], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00454f5b; /* jne 0x454f5b */
    PUSH32(c, 0x00454f5bu); f_004513ec(c); /* call 0x4513ec */
L_00454f5b:;
    c->esi = (uint32_t)(R32((uint32_t)(0x47c340u))); /* mov esi, dword ptr [0x47c340] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00454f63:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00454f7b; /* je 0x454f7b */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00454f6e; /* je 0x454f6e */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00454f6e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00454f74u); f_0044dd70(c); /* call 0x44dd70 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_00454f63; /* jmp 0x454f63 */
L_00454f7b:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00454f88u); f_0044f636(c); /* call 0x44f636 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0x47c3b8u), (uint32_t)(c->esi)); /* mov dword ptr [0x47c3b8], esi */
    if (!c->zf) goto L_00454f9d; /* jne 0x454f9d */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00454f9cu); f_0044fa7e(c); /* call 0x44fa7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00454f9d:;
    c->edi = (uint32_t)(R32((uint32_t)(0x47c340u))); /* mov edi, dword ptr [0x47c340] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_00454fe0; /* je 0x454fe0 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_00454fa8:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00454faeu); f_0044dd70(c); /* call 0x44dd70 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_00454fd9; /* je 0x454fd9 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00454fbdu); f_0044f636(c); /* call 0x44f636 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_00454fcc; /* jne 0x454fcc */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00454fcbu); f_0044fa7e(c); /* call 0x44fa7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00454fcc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00454fd4u); f_0044dc50(c); /* call 0x44dc50 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00454fd9:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_00454fa8; /* jne 0x454fa8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00454fe0:;
    { uint32_t v_ = R32((uint32_t)(0x47c340u)); PUSH32(c, v_); } /* push dword ptr [0x47c340] */
    PUSH32(c, 0x00454febu); f_0044f5cd(c); /* call 0x44f5cd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x47c340u), (uint32_t)(c->ebx)); /* mov dword ptr [0x47c340], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x47c6acu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c6ac], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00455002(CPU *c) { /* FUN_00455002 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x47c6b0u)), c->ebx); /* cmp dword ptr [0x47c6b0], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00455019; /* jne 0x455019 */
    PUSH32(c, 0x00455019u); f_004513ec(c); /* call 0x4513ec */
L_00455019:;
    c->esi = (uint32_t)((uint32_t)0x47c3fcu); /* mov esi, 0x47c3fc */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x45b0fcu)); PUSH32(c, 0x0045502bu); call_indirect(c, t_); } /* call dword ptr [0x45b0fc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x47d904u))); /* mov eax, dword ptr [0x47d904] */
    W32((uint32_t)(0x47c3c8u), (uint32_t)(c->esi)); /* mov dword ptr [0x47c3c8], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_0045503e; /* je 0x45503e */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_0045503e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x0045504eu); f_0045509b(c); /* call 0x45509b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045505du); f_0044f636(c); /* call 0x44f636 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_0045506e; /* jne 0x45506e */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x0045506du); f_0044fa7e(c); /* call 0x44fa7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_0045506e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00455084u); f_0045509b(c); /* call 0x45509b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0x47c3b0u), (uint32_t)(c->esi)); /* mov dword ptr [0x47c3b0], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x47c3acu), (uint32_t)(c->eax)); /* mov dword ptr [0x47c3ac], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0045509b(CPU *c) { /* FUN_0045509b */
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
    if (c->zf) goto L_004550c5; /* je 0x4550c5 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_004550c5:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_0045510e; /* jne 0x45510e */
L_004550ca:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_004550fc; /* je 0x4550fc */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_004550fc; /* je 0x4550fc */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x47c7e1u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x47c7e1], 4 */
    if (c->zf) goto L_004550ef; /* je 0x4550ef */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_004550ef; /* je 0x4550ef */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_004550ef:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_004550ca; /* je 0x4550ca */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_004550ca; /* jmp 0x4550ca */
L_004550fc:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00455106; /* je 0x455106 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00455106:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00455151; /* jne 0x455151 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00455151; /* jmp 0x455151 */
L_0045510e:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00455119; /* je 0x455119 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00455119:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x47c7e1u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x47c7e1], 4 */
    if (c->zf) goto L_00455134; /* je 0x455134 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00455133; /* je 0x455133 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00455133:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00455134:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00455142; /* je 0x455142 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00455146; /* je 0x455146 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_0045510e; /* jne 0x45510e */
L_00455142:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00455149; /* jne 0x455149 */
L_00455146:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00455151; /* jmp 0x455151 */
L_00455149:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00455151; /* je 0x455151 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_00455151:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00455155:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_0045523e; /* je 0x45523e */
L_0045515e:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_0045516a; /* je 0x45516a */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_0045516d; /* jne 0x45516d */
L_0045516a:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_0045515e; /* jmp 0x45515e */
L_0045516d:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_0045523e; /* je 0x45523e */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00455182; /* je 0x455182 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00455182:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_00455187:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00455190:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_00455199; /* jne 0x455199 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00455190; /* jmp 0x455190 */
L_00455199:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_004551ca; /* jne 0x4551ca */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_004551c8; /* jne 0x4551c8 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_004551b7; /* je 0x4551b7 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_004551b7; /* jne 0x4551b7 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_004551ba; /* jmp 0x4551ba */
L_004551b7:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_004551ba:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_004551c8:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_004551ca:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_004551df; /* je 0x4551df */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_004551d2:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_004551da; /* je 0x4551da */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_004551da:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_004551d2; /* jne 0x4551d2 */
L_004551df:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0045522f; /* je 0x45522f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_004551f5; /* jne 0x4551f5 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_0045522f; /* je 0x45522f */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_0045522f; /* je 0x45522f */
L_004551f5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00455229; /* je 0x455229 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00455218; /* je 0x455218 */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x47c7e1u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x47c7e1], 4 */
    if (c->zf) goto L_00455211; /* je 0x455211 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00455211:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00455227; /* jmp 0x455227 */
L_00455218:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x47c7e1u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x47c7e1], 4 */
    if (c->zf) goto L_00455227; /* je 0x455227 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00455227:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00455229:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00455187; /* jmp 0x455187 */
L_0045522f:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00455237; /* je 0x455237 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00455237:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00455155; /* jmp 0x455155 */
L_0045523e:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00455245; /* je 0x455245 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00455245:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0045524f(CPU *c) { /* FUN_0045524f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c500u))); /* mov eax, dword ptr [0x47c500] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x45b0c8u))); /* mov ebp, dword ptr [0x45b0c8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_0045529d; /* jne 0x45529d */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x0045526cu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_0045527e; /* je 0x45527e */
    W32((uint32_t)(0x47c500u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x47c500], 1 */
    goto L_004552a6; /* jmp 0x4552a6 */
L_0045527e:;
    { uint32_t t_ = R32((uint32_t)(0x45b0ccu)); PUSH32(c, 0x00455284u); call_indirect(c, t_); } /* call dword ptr [0x45b0cc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00455378; /* je 0x455378 */
    W32((uint32_t)(0x47c500u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x47c500], 2 */
    goto L_0045532c; /* jmp 0x45532c */
L_0045529d:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00455327; /* jne 0x455327 */
L_004552a6:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_004552b6; /* jne 0x4552b6 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x004552acu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00455378; /* je 0x455378 */
L_004552b6:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_004552cb; /* je 0x4552cb */
L_004552bd:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_004552bd; /* jne 0x4552bd */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_004552bd; /* jne 0x4552bd */
L_004552cb:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0x45b0d0u))); /* mov edi, dword ptr [0x45b0d0] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x004552e4u); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_0045531c; /* je 0x45531c */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x004552f0u); f_0044f636(c); /* call 0x44f636 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_0045531c; /* je 0x45531c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00455306u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00455318; /* jne 0x455318 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00455313u); f_0044f5cd(c); /* call 0x44f5cd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00455318:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_0045531c:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x45b0d4u)); PUSH32(c, 0x00455323u); call_indirect(c, t_); } /* call dword ptr [0x45b0d4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_0045537a; /* jmp 0x45537a */
L_00455327:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00455378; /* jne 0x455378 */
L_0045532c:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_0045533c; /* jne 0x45533c */
    { uint32_t t_ = R32((uint32_t)(0x45b0ccu)); PUSH32(c, 0x00455336u); call_indirect(c, t_); } /* call dword ptr [0x45b0cc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00455378; /* je 0x455378 */
L_0045533c:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_0045534c; /* je 0x45534c */
L_00455342:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00455342; /* jne 0x455342 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00455342; /* jne 0x455342 */
L_0045534c:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00455357u); f_0044f636(c); /* call 0x44f636 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00455362; /* jne 0x455362 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_0045536d; /* jmp 0x45536d */
L_00455362:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x0045536au); f_0044df80(c); /* call 0x44df80 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_0045536d:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x45b0d8u)); PUSH32(c, 0x00455374u); call_indirect(c, t_); } /* call dword ptr [0x45b0d8] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_0045537a; /* jmp 0x45537a */
L_00455378:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0045537a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00455381(CPU *c) { /* FUN_00455381 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x44u)); /* sub esp, 0x44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    PUSH32(c, 0x00455392u); f_0044f636(c); /* call 0x44f636 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_004553a1; /* jne 0x4553a1 */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x004553a0u); f_0044fa7e(c); /* call 0x44fa7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_004553a1:;
    W32((uint32_t)(0x47c580u), (uint32_t)(c->esi)); /* mov dword ptr [0x47c580], esi */
    W32((uint32_t)(0x47c680u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x47c680], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x100u)); /* lea eax, [esi + 0x100] */
L_004553b7:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_004553d5; /* jae 0x4553d5 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c580u))); /* mov eax, dword ptr [0x47c580] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x100u)); /* add eax, 0x100 */
    goto L_004553b7; /* jmp 0x4553b7 */
L_004553d5:;
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b128u)); PUSH32(c, 0x004553e0u); call_indirect(c, t_); } /* call dword ptr [0x45b128] */
    (void)sub16(c, R16((uint32_t)(c->esp + 0x42u)), (uint16_t)0x0u); /* cmp word ptr [esp + 0x42], 0 */
    if (c->zf) goto L_004554b1; /* je 0x4554b1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov eax, dword ptr [esp + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004554b1; /* je 0x4554b1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    c->ebp = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebp, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->ebp)); /* lea ebx, [esi + ebp] */
    if ((c->sf != c->of)) goto L_0045540b; /* jl 0x45540b */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_0045540b:;
    (void)sub32(c, R32((uint32_t)(0x47c680u)), c->esi); /* cmp dword ptr [0x47c680], esi */
    if ((c->sf == c->of)) goto L_00455465; /* jge 0x455465 */
    c->edi = (uint32_t)((uint32_t)0x47c584u); /* mov edi, 0x47c584 */
L_00455418:;
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    PUSH32(c, 0x00455422u); f_0044f636(c); /* call 0x44f636 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_0045545f; /* je 0x45545f */
    { uint32_t a_ = (uint32_t)(0x47c680u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x47c680], 0x20 */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x100u)); /* lea ecx, [eax + 0x100] */
L_00455436:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00455452; /* jae 0x455452 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x100u)); /* add ecx, 0x100 */
    goto L_00455436; /* jmp 0x455436 */
L_00455452:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(0x47c680u)), c->esi); /* cmp dword ptr [0x47c680], esi */
    if ((c->sf != c->of)) goto L_00455418; /* jl 0x455418 */
    goto L_00455465; /* jmp 0x455465 */
L_0045545f:;
    c->esi = (uint32_t)(R32((uint32_t)(0x47c680u))); /* mov esi, dword ptr [0x47c680] */
L_00455465:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_004554b1; /* jle 0x4554b1 */
L_0045546b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_004554a8; /* je 0x4554a8 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp))); /* mov cl, byte ptr [ebp] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    if (c->zf) goto L_004554a8; /* je 0x4554a8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (!c->zf) goto L_0045548a; /* jne 0x45548a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b0bcu)); PUSH32(c, 0x00455486u); call_indirect(c, t_); } /* call dword ptr [0x45b0bc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004554a8; /* je 0x4554a8 */
L_0045548a:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x47c580u))); /* mov eax, dword ptr [eax*4 + 0x47c580] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 8)); /* lea eax, [eax + ecx*8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ecx, dword ptr [ebx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp))); /* mov cl, byte ptr [ebp] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_004554a8:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x4u)); /* add ebx, 4 */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if ((c->sf != c->of)) goto L_0045546b; /* jl 0x45546b */
L_004554b1:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_004554b3:;
    c->eax = (uint32_t)(R32((uint32_t)(0x47c580u))); /* mov eax, dword ptr [0x47c580] */
    (void)sub32(c, R32((uint32_t)(c->eax + c->ebx * 8)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + ebx*8], -1 */
    c->esi = (uint32_t)((uint32_t)(c->eax + c->ebx * 8)); /* lea esi, [eax + ebx*8] */
    if (!c->zf) goto L_0045550e; /* jne 0x45550e */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_004554ce; /* jne 0x4554ce */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_004554d8; /* jmp 0x4554d8 */
L_004554ce:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_004554d8:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b0c0u)); PUSH32(c, 0x004554dfu); call_indirect(c, t_); } /* call dword ptr [0x45b0c0] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_004554fd; /* je 0x4554fd */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x45b0bcu)); PUSH32(c, 0x004554edu); call_indirect(c, t_); } /* call dword ptr [0x45b0bc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_004554fd; /* je 0x4554fd */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00455503; /* jne 0x455503 */
L_004554fd:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_00455512; /* jmp 0x455512 */
L_00455503:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00455512; /* jne 0x455512 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_00455512; /* jmp 0x455512 */
L_0045550e:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_00455512:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_004554b3; /* jl 0x4554b3 */
    { uint32_t v_ = R32((uint32_t)(0x47c680u)); PUSH32(c, v_); } /* push dword ptr [0x47c680] */
    { uint32_t t_ = R32((uint32_t)(0x45b0c4u)); PUSH32(c, 0x00455524u); call_indirect(c, t_); } /* call dword ptr [0x45b0c4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x44u)); /* add esp, 0x44 */
    c->esp += 4; return; /* ret  */
}

void f_0045552c(CPU *c) { /* PTR_0045552c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x47c580u); /* mov esi, 0x47c580 */
L_00455532:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00455542; /* je 0x455542 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045553eu); f_0044f5cd(c); /* call 0x44f5cd */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00455542:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x47c680u); /* cmp esi, 0x47c680 */
    if ((c->sf != c->of)) goto L_00455532; /* jl 0x455532 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00455550(CPU *c) { /* PTR_00455550 */
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
    if (!c->zf) goto L_004555f8; /* jne 0x4555f8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_0045558b:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_004555f1; /* je 0x4555f1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_004555df; /* je 0x4555df */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x004555a3u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_004555df; /* je 0x4555df */
    if (c->sf) goto L_004555ea; /* js 0x4555ea */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x004555b7u); f_0044db28(c); /* call 0x44db28 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x004555c4u); f_0044db6a(c); /* call 0x44db6a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x004555d5u); f_0044dbfe(c); /* call 0x44dbfe */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x004555dfu); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_004555df:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_0045558b; /* jmp 0x45558b */
L_004555ea:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_0045560d; /* jmp 0x45560d */
L_004555f1:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0045560d; /* jmp 0x45560d */
L_004555f8:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00455604u); f_0044db6a(c); /* call 0x44db6a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_0045560d:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00455615(CPU *c) { /* FUN_00455615 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00455629u); f_0044db6a(c); /* call 0x44db6a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00455630(CPU *c) { /* FUN_00455630 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x47c348u))); /* mov eax, dword ptr [0x47c348] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00455647; /* je 0x455647 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00455668; /* jne 0x455668 */
    (void)sub32(c, R32((uint32_t)(0x46c970u)), (uint32_t)0x1u); /* cmp dword ptr [0x46c970], 1 */
    if (!c->zf) goto L_00455668; /* jne 0x455668 */
L_00455647:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00455651u); f_00455669(c); /* call 0x455669 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c504u))); /* mov eax, dword ptr [0x47c504] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0045565d; /* je 0x45565d */
    { uint32_t t_ = c->eax; PUSH32(c, 0x0045565du); call_indirect(c, t_); } /* call eax */
L_0045565d:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00455667u); f_00455669(c); /* call 0x455669 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00455668:;
    c->esp += 4; return; /* ret  */
}

void f_00455669(CPU *c) { /* FUN_00455669 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x46f200u); /* mov eax, 0x46f200 */
L_0045567c:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_0045568b; /* je 0x45568b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0x46f290u); /* cmp eax, 0x46f290 */
    if ((c->sf != c->of)) goto L_0045567c; /* jl 0x45567c */
L_0045568b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0x46f200u))); /* cmp edx, dword ptr [esi + 0x46f200] */
    if (!c->zf) goto L_004557b9; /* jne 0x4557b9 */
    c->eax = (uint32_t)(R32((uint32_t)(0x47c348u))); /* mov eax, dword ptr [0x47c348] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00455793; /* je 0x455793 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004556bc; /* jne 0x4556bc */
    (void)sub32(c, R32((uint32_t)(0x46c970u)), (uint32_t)0x1u); /* cmp dword ptr [0x46c970], 1 */
    if (c->zf) goto L_00455793; /* je 0x455793 */
L_004556bc:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_004557b9; /* je 0x4557b9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x45b0fcu)); PUSH32(c, 0x004556dcu); call_indirect(c, t_); } /* call dword ptr [0x45b0fc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_004556f3; /* jne 0x4556f3 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x45c1d8u; PUSH32(c, v_); } /* push 0x45c1d8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x004556f1u); f_0044dc50(c); /* call 0x44dc50 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_004556f3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00455706u); f_0044dd70(c); /* call 0x44dd70 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00455736; /* jbe 0x455736 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00455719u); f_0044dd70(c); /* call 0x44dd70 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0x45c1d4u; PUSH32(c, v_); } /* push 0x45c1d4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00455733u); f_0044e6e0(c); /* call 0x44e6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00455736:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x45c1b8u; PUSH32(c, v_); } /* push 0x45c1b8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00455747u); f_0044dc50(c); /* call 0x44dc50 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00455754u); f_0044dc60(c); /* call 0x44dc60 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x45c1b4u; PUSH32(c, v_); } /* push 0x45c1b4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00455765u); f_0044dc60(c); /* call 0x44dc60 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x46f204u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x46f204] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00455777u); f_0044dc60(c); /* call 0x44dc60 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x45c18cu; PUSH32(c, v_); } /* push 0x45c18c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0045578du); f_00458686(c); /* call 0x458686 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_004557b9; /* jmp 0x4557b9 */
L_00455793:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x46f204u)); /* lea esi, [esi + 0x46f204] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x004557a6u); f_0044dd70(c); /* call 0x44dd70 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x45b0c0u)); PUSH32(c, 0x004557b2u); call_indirect(c, t_); } /* call dword ptr [0x45b0c0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x45b150u)); PUSH32(c, 0x004557b9u); call_indirect(c, t_); } /* call dword ptr [0x45b150] */
L_004557b9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_004557bc(CPU *c) { /* PTR_004557bc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0x46f200u); /* mov eax, 0x46f200 */
L_004557c7:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax))); /* cmp ecx, dword ptr [eax] */
    if (c->zf) goto L_004557d6; /* je 0x4557d6 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0x46f290u); /* cmp eax, 0x46f290 */
    if ((c->sf != c->of)) goto L_004557c7; /* jl 0x4557c7 */
L_004557d6:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->eax = (uint32_t)(shl32(c, c->eax, 3)); /* shl eax, 3 */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x46f200u))); /* cmp ecx, dword ptr [eax + 0x46f200] */
    if (!c->zf) goto L_004557ea; /* jne 0x4557ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x46f204u))); /* mov eax, dword ptr [eax + 0x46f204] */
    c->esp += 4; return; /* ret  */
L_004557ea:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_004557ed(CPU *c) { /* FUN_004557ed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x45b0b8u)); PUSH32(c, 0x004557ffu); call_indirect(c, t_); } /* call dword ptr [0x45b0b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00455805; /* je 0x455805 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00455805:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00455809(CPU *c) { /* FUN_00455809 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x45b0e0u)); PUSH32(c, 0x0045581bu); call_indirect(c, t_); } /* call dword ptr [0x45b0e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00455821; /* je 0x455821 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00455821:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00455825(CPU *c) { /* FUN_00455825 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x45b0b4u)); PUSH32(c, 0x00455833u); call_indirect(c, t_); } /* call dword ptr [0x45b0b4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00455839; /* je 0x455839 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00455839:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00455840(CPU *c) { /* FUN_00455840 */
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
    if ((c->cf || c->zf)) goto L_00455860; /* jbe 0x455860 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_004559d8; /* jb 0x4559d8 */
L_00455860:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_0045587c; /* jne 0x45587c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_0045589c; /* jb 0x45589c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x455988u)); switch (t_) { case 0x00455998u: goto L_00455998; case 0x004559a0u: goto L_004559a0; case 0x004559acu: goto L_004559ac; case 0x004559c0u: goto L_004559c0; default: jump_indirect(c, t_, 0x00455875u); return; } } /* jmp dword ptr [edx*4 + 0x455988] */
L_0045587c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00455894; /* jb 0x455894 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x4558a0u)); switch (t_) {  default: jump_indirect(c, t_, 0x0045588du); return; } } /* jmp dword ptr [eax*4 + 0x4558a0] */
L_00455894:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x455998u)); switch (t_) {  default: jump_indirect(c, t_, 0x00455894u); return; } } /* jmp dword ptr [ecx*4 + 0x455998] */
L_0045589c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x45591cu)); switch (t_) { case 0x0045593cu: goto L_0045593c; case 0x00455944u: goto L_00455944; case 0x0045594cu: goto L_0045594c; case 0x00455954u: goto L_00455954; case 0x0045595cu: goto L_0045595c; case 0x00455964u: goto L_00455964; case 0x0045596cu: goto L_0045596c; case 0x0045597fu: goto L_0045597f; default: jump_indirect(c, t_, 0x0045589cu); return; } } /* jmp dword ptr [ecx*4 + 0x45591c] */
L_0045593c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00455944:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_0045594c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00455954:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_0045595c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00455964:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_0045596c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_0045597f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x455988u)); switch (t_) { case 0x00455998u: goto L_00455998; case 0x004559a0u: goto L_004559a0; case 0x004559acu: goto L_004559ac; case 0x004559c0u: goto L_004559c0; default: jump_indirect(c, t_, 0x0045597fu); return; } } /* jmp dword ptr [edx*4 + 0x455988] */
L_00455998:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004559a0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004559ac:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_004559c0:;
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
L_004559d8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00455a0c; /* jne 0x455a0c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00455a00; /* jb 0x455a00 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x455b20u)); switch (t_) { case 0x00455b30u: goto L_00455b30; case 0x00455b38u: goto L_00455b38; case 0x00455b48u: goto L_00455b48; case 0x00455b5cu: goto L_00455b5c; default: jump_indirect(c, t_, 0x004559f7u); return; } } /* jmp dword ptr [edx*4 + 0x455b20] */
L_00455a00:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x455ad0u)); switch (t_) { case 0x00455b17u: goto L_00455b17; default: jump_indirect(c, t_, 0x00455a02u); return; } } /* jmp dword ptr [ecx*4 + 0x455ad0] */
L_00455a0c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00455a24; /* jb 0x455a24 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x455a28u)); switch (t_) {  default: jump_indirect(c, t_, 0x00455a1du); return; } } /* jmp dword ptr [eax*4 + 0x455a28] */
L_00455a24:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x455b20u)); switch (t_) { case 0x00455b30u: goto L_00455b30; case 0x00455b38u: goto L_00455b38; case 0x00455b48u: goto L_00455b48; case 0x00455b5cu: goto L_00455b5c; default: jump_indirect(c, t_, 0x00455a24u); return; } } /* jmp dword ptr [ecx*4 + 0x455b20] */
L_00455b17:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x455b20u)); switch (t_) { case 0x00455b30u: goto L_00455b30; case 0x00455b38u: goto L_00455b38; case 0x00455b48u: goto L_00455b48; case 0x00455b5cu: goto L_00455b5c; default: jump_indirect(c, t_, 0x00455b17u); return; } } /* jmp dword ptr [edx*4 + 0x455b20] */
L_00455b30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00455b38:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00455b48:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00455b5c:;
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
