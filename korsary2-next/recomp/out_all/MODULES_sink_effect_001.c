#include "recomp.h"

void f_00cd6bfc(CPU *c) { /* FUN_10006bfc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffcu), c->fpu_cw); /* fnstcw word ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00cd6c0du); f_00cd6c47(c); /* call 0xcd6c47 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)~c->eax); /* not eax */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & c->eax))); /* and esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->eax))); /* or esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd6c24u); f_00cd6cd9(c); /* call 0xcd6cd9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6c31(CPU *c) { /* FUN_10006c31 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfff7ffffu))); /* and eax, 0xfff7ffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00cd6c44u); f_00cd6bfc(c); /* call 0xcd6bfc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd6c47(CPU *c) { /* FUN_10006c47 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00cd6c58; /* je 0xcd6c58 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd6c58:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00cd6c5f; /* je 0xcd6c5f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00cd6c5f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00cd6c66; /* je 0xcd6c66 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00cd6c66:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00cd6c6d; /* je 0xcd6c6d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00cd6c6d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x20u)); /* test bl, 0x20 */
    if (c->zf) goto L_00cd6c74; /* je 0xcd6c74 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1u))); /* or al, 1 */
L_00cd6c74:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00cd6c7e; /* je 0xcd6c7e */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x80000u))); /* or eax, 0x80000 */
L_00cd6c7e:;
    c->ecx = (uint32_t)((uint32_t)((uint16_t)c->ebx)); /* movzx ecx, bx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)((uint32_t)0xc00u); /* mov esi, 0xc00 */
    c->edi = (uint32_t)((uint32_t)0x300u); /* mov edi, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->esi))); /* and edx, esi */
    c->ebp = (uint32_t)((uint32_t)0x200u); /* mov ebp, 0x200 */
    if (c->zf) goto L_00cd6cb6; /* je 0xcd6cb6 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (c->zf) goto L_00cd6cb3; /* je 0xcd6cb3 */
    (void)sub32(c, c->edx, (uint32_t)0x800u); /* cmp edx, 0x800 */
    if (c->zf) goto L_00cd6caf; /* je 0xcd6caf */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if (!c->zf) goto L_00cd6cb6; /* jne 0xcd6cb6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    goto L_00cd6cb6; /* jmp 0xcd6cb6 */
L_00cd6caf:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ebp))); /* or eax, ebp */
    goto L_00cd6cb6; /* jmp 0xcd6cb6 */
L_00cd6cb3:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x1u))) << 8); /* or ah, 1 */
L_00cd6cb6:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00cd6cc6; /* je 0xcd6cc6 */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (!c->zf) goto L_00cd6ccb; /* jne 0xcd6ccb */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x10000u))); /* or eax, 0x10000 */
    goto L_00cd6ccb; /* jmp 0xcd6ccb */
L_00cd6cc6:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x20000u))); /* or eax, 0x20000 */
L_00cd6ccb:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x10u)); /* test bh, 0x10 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00cd6cd8; /* je 0xcd6cd8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x40000u))); /* or eax, 0x40000 */
L_00cd6cd8:;
    c->esp += 4; return; /* ret  */
}

void f_00cd6cd9(CPU *c) { /* FUN_10006cd9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00cd6ce9; /* je 0xcd6ce9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd6ce9:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00cd6cf0; /* je 0xcd6cf0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00cd6cf0:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00cd6cf7; /* je 0xcd6cf7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00cd6cf7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00cd6cfe; /* je 0xcd6cfe */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
L_00cd6cfe:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00cd6d05; /* je 0xcd6d05 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
L_00cd6d05:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000u)); /* test ebx, 0x80000 */
    if (c->zf) goto L_00cd6d0f; /* je 0xcd6d0f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00cd6d0f:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)((uint32_t)0x300u); /* mov edx, 0x300 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->esi = (uint32_t)((uint32_t)0x200u); /* mov esi, 0x200 */
    if (c->zf) goto L_00cd6d3c; /* je 0xcd6d3c */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (c->zf) goto L_00cd6d39; /* je 0xcd6d39 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (c->zf) goto L_00cd6d34; /* je 0xcd6d34 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00cd6d3c; /* jne 0xcd6d3c */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0xcu))) << 8); /* or ah, 0xc */
    goto L_00cd6d3c; /* jmp 0xcd6d3c */
L_00cd6d34:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x8u))) << 8); /* or ah, 8 */
    goto L_00cd6d3c; /* jmp 0xcd6d3c */
L_00cd6d39:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x4u))) << 8); /* or ah, 4 */
L_00cd6d3c:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x30000u))); /* and ecx, 0x30000 */
    if (c->zf) goto L_00cd6d52; /* je 0xcd6d52 */
    (void)sub32(c, c->ecx, (uint32_t)0x10000u); /* cmp ecx, 0x10000 */
    if (!c->zf) goto L_00cd6d54; /* jne 0xcd6d54 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    goto L_00cd6d54; /* jmp 0xcd6d54 */
L_00cd6d52:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
L_00cd6d54:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x40000u)); /* test ebx, 0x40000 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00cd6d61; /* je 0xcd6d61 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x10u))) << 8); /* or ah, 0x10 */
L_00cd6d61:;
    c->esp += 4; return; /* ret  */
}

void f_00cd6d62(CPU *c) { /* FUN_10006d62 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xce068cu)), c->ebx); /* cmp dword ptr [0x1001068c], ebx */
    if (!c->zf) goto L_00cd6d80; /* jne 0xcd6d80 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_00cd6dcf; /* jl 0xcd6dcf */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_00cd6dcf; /* jg 0xcd6dcf */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd6d80:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xce07ecu); /* mov esi, 0x100107ec */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0a8u)); PUSH32(c, 0x00cd6d8eu); call_indirect(c, t_); } /* call dword ptr [0x1000c0a8] */
    (void)sub32(c, R32((uint32_t)(0xce07e8u)), c->ebx); /* cmp dword ptr [0x100107e8], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0xcdc0a4u))); /* mov edi, dword ptr [0x1000c0a4] */
    if (c->zf) goto L_00cd6daa; /* je 0xcd6daa */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd6d9fu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cd6da6u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00cd6daa:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00cd6db3u); f_00cd6dd1(c); /* call 0xcd6dd1 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00cd6dc6; /* je 0xcd6dc6 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cd6dc3u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd6dc9; /* jmp 0xcd6dc9 */
L_00cd6dc6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cd6dc9u); call_indirect(c, t_); } /* call edi */
L_00cd6dc9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd6dcf:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd6dd1(CPU *c) { /* FUN_10006dd1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xce068cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1001068c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd6dfe; /* jne 0xcd6dfe */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_00cd6e97; /* jl 0xcd6e97 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_00cd6e97; /* jg 0xcd6e97 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_00cd6e97; /* jmp 0xcd6e97 */
L_00cd6dfe:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_00cd6e32; /* jge 0xcd6e32 */
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), c->esi); /* cmp dword ptr [0x1000d500], esi */
    if ((c->zf || c->sf != c->of)) goto L_00cd6e20; /* jle 0xcd6e20 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd6e1cu); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd6e2a; /* jmp 0xcd6e2a */
L_00cd6e20:;
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov eax, dword ptr [0x1000d2f4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00cd6e2a:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd6e32; /* jne 0xcd6e32 */
L_00cd6e2e:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00cd6e97; /* jmp 0xcd6e97 */
L_00cd6e32:;
    c->edx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov edx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00cd6e56; /* je 0xcd6e56 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd6e5f; /* jmp 0xcd6e5f */
L_00cd6e56:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd6e5f:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce068cu)); PUSH32(c, v_); } /* push dword ptr [0x1001068c] */
    PUSH32(c, 0x00cd6e79u); f_00cda08d(c); /* call 0xcda08d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd6e2e; /* je 0xcd6e2e */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00cd6e8a; /* jne 0xcd6e8a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00cd6e97; /* jmp 0xcd6e97 */
L_00cd6e8a:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00cd6e97:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6e9c(CPU *c) { /* FUN_10006e9c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd6ea5u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd6eb0u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4)) & c->edx)); /* test dword ptr [eax + esi*4], edx */
    if (!c->zf) goto L_00cd6ee1; /* jne 0xcd6ee1 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf == c->of)) goto L_00cd6edc; /* jge 0xcd6edc */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi * 4)); /* lea eax, [eax + esi*4] */
L_00cd6ece:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00cd6ee1; /* jne 0xcd6ee1 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf != c->of)) goto L_00cd6ece; /* jl 0xcd6ece */
L_00cd6edc:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00cd6ee1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd6ee5(CPU *c) { /* FUN_10006ee5 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd6ef4u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd6efdu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
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
    PUSH32(c, 0x00cd6f15u); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00cd6f37; /* js 0xcd6f37 */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->esi * 4)); /* lea edi, [ebx + esi*4] */
L_00cd6f1e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd6f37; /* je 0xcd6f37 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    PUSH32(c, 0x00cd6f2cu); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x4u)); /* sub edi, 4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00cd6f1e; /* jge 0xcd6f1e */
L_00cd6f37:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd6f3b(CPU *c) { /* FUN_10006f3b */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd6f59u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd6f62u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
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
    if (c->zf) goto L_00cd6f9f; /* je 0xcd6f9f */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd6f88u); f_00cd6e9c(c); /* call 0xcd6e9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd6f9c; /* jne 0xcd6f9c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd6f97u); f_00cd6ee5(c); /* call 0xcd6ee5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd6f9c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00cd6f9f:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_00cd6fbf; /* jge 0xcd6fbf */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 4)); /* lea edi, [edx + eax*4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_00cd6fbf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd6fc7(CPU *c) { /* FUN_10006fc7 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00cd6fd5:;
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)(c->esi)); /* mov dword ptr [ecx + eax], esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00cd6fd5; /* jne 0xcd6fd5 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd6fe2(CPU *c) { /* FUN_10006fe2 */
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

void f_00cd6fee(CPU *c) { /* FUN_10006fee */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00cd6ff4:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00cd7006; /* jne 0xcd7006 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    if ((c->sf != c->of)) goto L_00cd6ff4; /* jl 0xcd6ff4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00cd7006:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd7009(CPU *c) { /* FUN_10007009 */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd7028u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00cd7031u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, (c->ecx & 0xff))); /* shl esi, cl */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edx)); /* sub ebx, edx */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
L_00cd703f:;
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
    if (!c->zf) goto L_00cd703f; /* jne 0xcd703f */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edi, dword ptr [ebp - 0xc] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
L_00cd7071:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->sf != c->of)) goto L_00cd7084; /* jl 0xcd7084 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov eax, dword ptr [eax + edx] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    goto L_00cd708b; /* jmp 0xcd708b */
L_00cd7084:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + eax], 0 */
L_00cd708b:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (!c->sf) goto L_00cd7071; /* jns 0xcd7071 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7096(CPU *c) { /* FUN_10007096 */
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
    if (!c->zf) goto L_00cd7103; /* jne 0xcd7103 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd70e8u); f_00cd6fee(c); /* call 0xcd6fee */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd71c2; /* jne 0xcd71c2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd70fau); f_00cd6fe2(c); /* call 0xcd6fe2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd70fb:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
L_00cd70fd:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd71c4; /* jmp 0xcd71c4 */
L_00cd7103:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7110u); f_00cd6fc7(c); /* call 0xcd6fc7 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd711cu); f_00cd6f3b(c); /* call 0xcd6f3b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd7124; /* je 0xcd7124 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00cd7124:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u)))); /* sub ecx, dword ptr [edi + 8] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf == c->of)) goto L_00cd713c; /* jge 0xcd713c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7139u); f_00cd6fe2(c); /* call 0xcd6fe2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd7178; /* jmp 0xcd7178 */
L_00cd713c:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00cd717f; /* jg 0xcd717f */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7151u); f_00cd6fc7(c); /* call 0xcd6fc7 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd715bu); f_00cd7009(c); /* call 0xcd7009 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7167u); f_00cd6f3b(c); /* call 0xcd6f3b */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7175u); f_00cd7009(c); /* call 0xcd7009 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00cd7178:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00cd70fb; /* jmp 0xcd70fb */
L_00cd717f:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi))); /* cmp ebx, dword ptr [edi] */
    if ((c->sf != c->of)) goto L_00cd71ab; /* jl 0xcd71ab */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd718cu); f_00cd6fe2(c); /* call 0xcd6fe2 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd719cu); f_00cd7009(c); /* call 0xcd7009 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->edi)))); /* add esi, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_00cd70fd; /* jmp 0xcd70fd */
L_00cd71ab:;
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x7fu)))); } /* and byte ptr [ebp - 9], 0x7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebx)); /* add esi, ebx */
    PUSH32(c, 0x00cd71c0u); f_00cd7009(c); /* call 0xcd7009 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd71c2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd71c4:;
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
    if (!c->zf) goto L_00cd71f3; /* jne 0xcd71f3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    goto L_00cd71fd; /* jmp 0xcd71fd */
L_00cd71f3:;
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if (!c->zf) goto L_00cd71fd; /* jne 0xcd71fd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00cd71fd:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7202(CPU *c) { /* FUN_10007202 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcdd7e0u; PUSH32(c, v_); } /* push 0x1000d7e0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00cd7214u); f_00cd7096(c); /* call 0xcd7096 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00cd7218(CPU *c) { /* FUN_10007218 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcdd7f8u; PUSH32(c, v_); } /* push 0x1000d7f8 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00cd722au); f_00cd7096(c); /* call 0xcd7096 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00cd722e(CPU *c) { /* FUN_1000722e */
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
    PUSH32(c, 0x00cd724au); f_00cd8c72(c); /* call 0xcd8c72 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7256u); f_00cd7202(c); /* call 0xcd7202 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd725b(CPU *c) { /* FUN_1000725b */
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
    PUSH32(c, 0x00cd7277u); f_00cd8c72(c); /* call 0xcd8c72 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7283u); f_00cd7218(c); /* call 0xcd7218 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7288(CPU *c) { /* FUN_10007288 */
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
    if ((c->zf || c->sf != c->of)) goto L_00cd72c5; /* jle 0xcd72c5 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00cd72ab:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd72b7; /* je 0xcd72b7 */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->edx)); /* movsx edx, dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_00cd72ba; /* jmp 0xcd72ba */
L_00cd72b7:;
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00cd72ba:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (!c->zf) goto L_00cd72ab; /* jne 0xcd72ab */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00cd72c5:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_00cd72de; /* jl 0xcd72de */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x35u); /* cmp byte ptr [ecx], 0x35 */
    if ((c->sf != c->of)) goto L_00cd72de; /* jl 0xcd72de */
L_00cd72d1:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00cd72dc; /* jne 0xcd72dc */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    goto L_00cd72d1; /* jmp 0xcd72d1 */
L_00cd72dc:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00cd72de:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x31u); /* cmp byte ptr [esi], 0x31 */
    if (!c->zf) goto L_00cd72e8; /* jne 0xcd72e8 */
    { uint32_t a_ = (uint32_t)(c->edx + 0x4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx + 4] */
    goto L_00cd72fa; /* jmp 0xcd72fa */
L_00cd72e8:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd72eeu); f_00cd46d0(c); /* call 0xcd46d0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd72f7u); f_00cd7570(c); /* call 0xcd7570 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00cd72fa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cd72ff(CPU *c) { /* FUN_100072ff */
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
    PUSH32(c, 0x00cd7314u); f_00cd735b(c); /* call 0xcd735b */
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
    PUSH32(c, 0x00cd732fu); f_00cda47d(c); /* call 0xcda47d */
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
    PUSH32(c, 0x00cd734fu); f_00cd7420(c); /* call 0xcd7420 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd735b(CPU *c) { /* FUN_1000735b */
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
    if (c->zf) goto L_00cd73a9; /* je 0xcd73a9 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00cd73a2; /* je 0xcd73a2 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c00u)); /* lea edi, [ecx + 0x3c00] */
    goto L_00cd73ca; /* jmp 0xcd73ca */
L_00cd73a2:;
    c->edi = (uint32_t)((uint32_t)0x7fffu); /* mov edi, 0x7fff */
    goto L_00cd73ca; /* jmp 0xcd73ca */
L_00cd73a9:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00cd73c1; /* jne 0xcd73c1 */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (!c->zf) goto L_00cd73c1; /* jne 0xcd73c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [eax + 8], bx */
    goto L_00cd740c; /* jmp 0xcd740c */
L_00cd73c1:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c01u)); /* lea edi, [ecx + 0x3c01] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
L_00cd73ca:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 21)); /* shr ecx, 0x15 */
    c->eax = (uint32_t)(shl32(c, c->eax, 11)); /* shl eax, 0xb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* or ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(shl32(c, c->edx, 11)); /* shl edx, 0xb */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_00cd73e2:;
    (void)logic32(c, (uint32_t)(c->esi & c->ecx)); /* test esi, ecx */
    if (!c->zf) goto L_00cd7403; /* jne 0xcd7403 */
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
    goto L_00cd73e2; /* jmp 0xcd73e2 */
L_00cd7403:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax + 8], cx */
L_00cd740c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7420(CPU *c) { /* FUN_10007420 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    { f_00cd7491(c); return; } /* jmp 0xcd7491 */
}

void f_00cd7430(CPU *c) { /* FUN_10007430 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00cd744c; /* je 0xcd744c */
L_00cd743d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd747f; /* je 0xcd747f */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00cd743d; /* jne 0xcd743d */
L_00cd744c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00cd744c; /* je 0xcd744c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd748e; /* je 0xcd748e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd7489; /* je 0xcd7489 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_00cd7484; /* je 0xcd7484 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00cd747f; /* je 0xcd747f */
    goto L_00cd744c; /* jmp 0xcd744c */
L_00cd747f:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea edi, [ecx - 1] */
    goto L_00cd7491; /* jmp 0xcd7491 */
L_00cd7484:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea edi, [ecx - 2] */
    goto L_00cd7491; /* jmp 0xcd7491 */
L_00cd7489:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea edi, [ecx - 3] */
    goto L_00cd7491; /* jmp 0xcd7491 */
L_00cd748e:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea edi, [ecx - 4] */
L_00cd7491:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00cd74b6; /* je 0xcd74b6 */
L_00cd749d:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd7508; /* je 0xcd7508 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00cd749d; /* jne 0xcd749d */
    goto L_00cd74b6; /* jmp 0xcd74b6 */
L_00cd74b1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_00cd74b6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00cd74b1; /* je 0xcd74b1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd7508; /* je 0xcd7508 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00cd74ff; /* je 0xcd74ff */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00cd74f2; /* je 0xcd74f2 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_00cd74ea; /* je 0xcd74ea */
    goto L_00cd74b1; /* jmp 0xcd74b1 */
L_00cd74ea:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd74f2:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd74ff:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd7508:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd7491(CPU *c) { /* PTR_00cd7491 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00cd74b6; /* je 0xcd74b6 */
L_00cd749d:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd7508; /* je 0xcd7508 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00cd749d; /* jne 0xcd749d */
    goto L_00cd74b6; /* jmp 0xcd74b6 */
L_00cd74b1:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_00cd74b6:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00cd74b1; /* je 0xcd74b1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd7508; /* je 0xcd7508 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00cd74ff; /* je 0xcd74ff */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00cd74f2; /* je 0xcd74f2 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_00cd74ea; /* je 0xcd74ea */
    goto L_00cd74b1; /* jmp 0xcd74b1 */
L_00cd74ea:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd74f2:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd74ff:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd7508:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd7510(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00cd7563; /* je 0xcd7563 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_00cd7557; /* jb 0xcd7557 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_00cd7539; /* je 0xcd7539 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_00cd7533:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00cd7533; /* jne 0xcd7533 */
L_00cd7539:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_00cd7557; /* je 0xcd7557 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00cd755d; /* je 0xcd755d */
L_00cd7557:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00cd7557; /* jne 0xcd7557 */
L_00cd755d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd7563:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00cd7570(CPU *c) { /* FUN_10007570 */
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
    if ((c->cf || c->zf)) goto L_00cd7590; /* jbe 0xcd7590 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00cd7708; /* jb 0xcd7708 */
L_00cd7590:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00cd75ac; /* jne 0xcd75ac */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00cd75cc; /* jb 0xcd75cc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd75a5u); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd75ac:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00cd75c4; /* jb 0xcd75c4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xcd75d0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd75bdu); return; } } /* jmp dword ptr [eax*4 + 0x100075d0] */
L_00cd75c4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd76c8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd75c4u); return; } } /* jmp dword ptr [ecx*4 + 0x100076c8] */
L_00cd75cc:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd764cu)); switch (t_) { case 0x00cd766cu: goto L_00cd766c; case 0x00cd7674u: goto L_00cd7674; case 0x00cd767cu: goto L_00cd767c; case 0x00cd7684u: goto L_00cd7684; case 0x00cd768cu: goto L_00cd768c; case 0x00cd7694u: goto L_00cd7694; case 0x00cd769cu: goto L_00cd769c; case 0x00cd76afu: goto L_00cd76af; default: jump_indirect(c, t_, 0x00cd75ccu); return; } } /* jmp dword ptr [ecx*4 + 0x1000764c] */
L_00cd766c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00cd7674:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00cd767c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00cd7684:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00cd768c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00cd7694:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00cd769c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00cd76af:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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
L_00cd7708:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00cd773c; /* jne 0xcd773c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00cd7730; /* jb 0xcd7730 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7727u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7730:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd7800u)); switch (t_) { case 0x00cd7847u: goto L_00cd7847; default: jump_indirect(c, t_, 0x00cd7732u); return; } } /* jmp dword ptr [ecx*4 + 0x10007800] */
L_00cd773c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00cd7754; /* jb 0xcd7754 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xcd7758u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd774du); return; } } /* jmp dword ptr [eax*4 + 0x10007758] */
L_00cd7754:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7754u); return; } } /* jmp dword ptr [ecx*4 + 0x10007850] */
L_00cd7847:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd75cc(CPU *c) { /* PTR_00cd75cc */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd764cu)); switch (t_) { case 0x00cd766cu: goto L_00cd766c; case 0x00cd7674u: goto L_00cd7674; case 0x00cd767cu: goto L_00cd767c; case 0x00cd7684u: goto L_00cd7684; case 0x00cd768cu: goto L_00cd768c; case 0x00cd7694u: goto L_00cd7694; case 0x00cd769cu: goto L_00cd769c; case 0x00cd76afu: goto L_00cd76af; default: jump_indirect(c, t_, 0x00cd75ccu); return; } } /* jmp dword ptr [ecx*4 + 0x1000764c] */
L_00cd766c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00cd7674:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00cd767c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00cd7684:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00cd768c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00cd7694:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00cd769c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00cd76af:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd75e0(CPU *c) { /* PTR_00cd75e0 */
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
    if (c->cf) { f_00cd75cc(c); return; } /* jb 0xcd75cc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd7602u); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd7600(CPU *c) { /* PTR_00cd7600 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd7602u); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd760c(CPU *c) { /* PTR_00cd760c */
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
    if (c->cf) { f_00cd75cc(c); return; } /* jb 0xcd75cc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd7628u); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd7630(CPU *c) { /* PTR_00cd7630 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00cd75cc(c); return; } /* jb 0xcd75cc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd7642u); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd766c(CPU *c) { /* PTR_00cd766c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd7674(CPU *c) { /* PTR_00cd7674 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd767c(CPU *c) { /* PTR_00cd767c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd7684(CPU *c) { /* PTR_00cd7684 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd768c(CPU *c) { /* PTR_00cd768c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd7694(CPU *c) { /* PTR_00cd7694 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd769c(CPU *c) { /* PTR_00cd769c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd76af(CPU *c) { /* PTR_00cd76af */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd76b8u)); switch (t_) { case 0x00cd76c8u: goto L_00cd76c8; case 0x00cd76d0u: goto L_00cd76d0; case 0x00cd76dcu: goto L_00cd76dc; case 0x00cd76f0u: goto L_00cd76f0; default: jump_indirect(c, t_, 0x00cd76afu); return; } } /* jmp dword ptr [edx*4 + 0x100076b8] */
L_00cd76c8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76d0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76dc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd76f0:;
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

void f_00cd76c8(CPU *c) { /* PTR_00cd76c8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd76d0(CPU *c) { /* PTR_00cd76d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd76dc(CPU *c) { /* PTR_00cd76dc */
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

void f_00cd76f0(CPU *c) { /* PTR_00cd76f0 */
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

void f_00cd7730(CPU *c) { /* PTR_00cd7730 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd7800u)); switch (t_) { case 0x00cd7847u: goto L_00cd7847; default: jump_indirect(c, t_, 0x00cd7732u); return; } } /* jmp dword ptr [ecx*4 + 0x10007800] */
L_00cd7847:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7768(CPU *c) { /* PTR_00cd7768 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00cd7730(c); return; } /* jb 0xcd7730 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd777eu); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7788(CPU *c) { /* PTR_00cd7788 */
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
    if (c->cf) { f_00cd7730(c); return; } /* jb 0xcd7730 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd77a8u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd77b0(CPU *c) { /* PTR_00cd77b0 */
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
    if (c->cf) { f_00cd7730(c); return; } /* jb 0xcd7730 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd77dau); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7804(CPU *c) { /* PTR_00cd7804 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd780c(CPU *c) { /* PTR_00cd780c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7814(CPU *c) { /* PTR_00cd7814 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd781c(CPU *c) { /* PTR_00cd781c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7824(CPU *c) { /* PTR_00cd7824 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd782c(CPU *c) { /* PTR_00cd782c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7834(CPU *c) { /* PTR_00cd7834 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7847(CPU *c) { /* PTR_00cd7847 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd7850u)); switch (t_) { case 0x00cd7860u: goto L_00cd7860; case 0x00cd7868u: goto L_00cd7868; case 0x00cd7878u: goto L_00cd7878; case 0x00cd788cu: goto L_00cd788c; default: jump_indirect(c, t_, 0x00cd7847u); return; } } /* jmp dword ptr [edx*4 + 0x10007850] */
L_00cd7860:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7868:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd7878:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd788c:;
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

void f_00cd7860(CPU *c) { /* PTR_00cd7860 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7868(CPU *c) { /* PTR_00cd7868 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7878(CPU *c) { /* PTR_00cd7878 */
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

void f_00cd788c(CPU *c) { /* PTR_00cd788c */
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

void f_00cd78a5(CPU *c) { /* PTR_00cd78a5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x00cd78acu); f_00cd33c8(c); /* call 0xcd33c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cd78ae(CPU *c) { /* FUN_100078ae */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x140u; PUSH32(c, v_); } /* push 0x140 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd78c1u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xce0a3cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a3c], eax */
    if (!c->zf) goto L_00cd78cb; /* jne 0xcd78cb */
    c->esp += 4; return; /* ret  */
L_00cd78cb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xce0a34u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10010a34], 0 */
    { uint32_t a_ = (uint32_t)(0xce0a38u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10010a38], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xce0a30u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a30], eax */
    W32((uint32_t)(0xce0a40u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10010a40], ecx */
    W32((uint32_t)(0xce0a28u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [0x10010a28], 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd78f6(CPU *c) { /* FUN_100078f6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a38u))); /* mov eax, dword ptr [0x10010a38] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a3cu))); /* mov eax, dword ptr [0x10010a3c] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
L_00cd7906:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00cd791e; /* jae 0xcd791e */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->eax + 0xcu)))); /* sub edx, dword ptr [eax + 0xc] */
    (void)sub32(c, c->edx, (uint32_t)0x100000u); /* cmp edx, 0x100000 */
    if (c->cf) goto L_00cd7920; /* jb 0xcd7920 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x14u)); /* add eax, 0x14 */
    goto L_00cd7906; /* jmp 0xcd7906 */
L_00cd791e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd7920:;
    c->esp += 4; return; /* ret  */
}

void f_00cd7921(CPU *c) { /* FUN_10007921 */
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
    if (!c->zf) goto L_00cd7c45; /* jne 0xcd7c45 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->esi))); /* mov edx, dword ptr [ecx + esi] */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + c->esi)); /* lea ebx, [ecx + esi] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov edx, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 0xc], ebx */
    if (!c->zf) goto L_00cd79f7; /* jne 0xcd79f7 */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00cd7985; /* jbe 0xcd7985 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00cd7985:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebx + 0x8u))); /* cmp ecx, dword ptr [ebx + 8] */
    if (!c->zf) goto L_00cd79d9; /* jne 0xcd79d9 */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    if (!c->cf) goto L_00cd79b0; /* jae 0xcd79b0 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00cd79d1; /* jne 0xcd79d1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00cd79d1; /* jmp 0xcd79d1 */
L_00cd79b0:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->eax + 0x4u)); /* lea ecx, [edx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edi*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00cd79d1; /* jne 0xcd79d1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00cd79d1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    goto L_00cd79dc; /* jmp 0xcd79dc */
L_00cd79d9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
L_00cd79dc:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edx, dword ptr [ebx + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ebx, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* add ecx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edx, dword ptr [edx + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebx + 8], edx */
L_00cd79f7:;
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, (uint32_t)0x3fu); /* cmp edx, 0x3f */
    if ((c->cf || c->zf)) goto L_00cd7a05; /* jbe 0xcd7a05 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00cd7a05:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x1u))); /* and ebx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0xc], ebx */
    if (!c->zf) goto L_00cd7aa8; /* jne 0xcd7aa8 */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub esi, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->ebx = (uint32_t)(sar32(c, c->ebx, 4)); /* sar ebx, 4 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    if ((c->cf || c->zf)) goto L_00cd7a2a; /* jbe 0xcd7a2a */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_00cd7a2a:;
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(sar32(c, c->edx, 4)); /* sar edx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if ((c->cf || c->zf)) goto L_00cd7a3c; /* jbe 0xcd7a3c */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
L_00cd7a3c:;
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00cd7aa3; /* je 0xcd7aa3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ecx + 0x8u))); /* cmp esi, dword ptr [ecx + 8] */
    if (!c->zf) goto L_00cd7a8b; /* jne 0xcd7a8b */
    (void)sub32(c, c->ebx, (uint32_t)0x20u); /* cmp ebx, 0x20 */
    if (!c->cf) goto L_00cd7a6c; /* jae 0xcd7a6c */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0x44], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00cd7a8b; /* jne 0xcd7a8b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx], esi */
    goto L_00cd7a8b; /* jmp 0xcd7a8b */
L_00cd7a6c:;
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0xffffffe0u)); /* lea ecx, [ebx - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
    { uint32_t a_ = (uint32_t)(c->eax + c->edi * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [eax + edi*4 + 0xc4], esi */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax + 0x4u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ebx + eax + 4] */
    if (!c->zf) goto L_00cd7a8b; /* jne 0xcd7a8b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->esi)))); } /* and dword ptr [ecx + 4], esi */
L_00cd7a8b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov esi, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov esi, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
L_00cd7aa3:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    goto L_00cd7aab; /* jmp 0xcd7aab */
L_00cd7aa8:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd7aab:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_00cd7ab9; /* jne 0xcd7ab9 */
    (void)sub32(c, c->ebx, c->edx); /* cmp ebx, edx */
    if (c->zf) goto L_00cd7b3a; /* je 0xcd7b3a */
L_00cd7ab9:;
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
    if (!c->zf) goto L_00cd7b3a; /* jne 0xcd7b3a */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + c->eax + 0x4u))); /* mov cl, byte ptr [edx + eax + 4] */
    (void)sub32(c, c->edx, (uint32_t)0x20u); /* cmp edx, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edx + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx + eax + 4], cl */
    if (!c->cf) goto L_00cd7b11; /* jae 0xcd7b11 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00cd7b00; /* jne 0xcd7b00 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00cd7b00:;
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0x44u)); /* lea eax, [eax + edi*4 + 0x44] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax], ebx */
    goto L_00cd7b3a; /* jmp 0xcd7b3a */
L_00cd7b11:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00cd7b27; /* jne 0xcd7b27 */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00cd7b27:;
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffe0u)); /* lea ecx, [edx - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edi * 4 + 0xc4u)); /* lea eax, [eax + edi*4 + 0xc4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00cd7b3a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->eax + c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + esi - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [eax] */
    if (!c->zf) goto L_00cd7c45; /* jne 0xcd7c45 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd7c37; /* je 0xcd7c37 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0a2cu))); /* mov ecx, dword ptr [0x10010a2c] */
    c->esi = (uint32_t)(R32((uint32_t)(0xcdc09cu))); /* mov esi, dword ptr [0x1000c09c] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 15)); /* shl ecx, 0xf */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->eax + 0xcu)))); /* add ecx, dword ptr [eax + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0x8000u); /* mov ebx, 0x8000 */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd7b7bu); call_indirect(c, t_); } /* call esi */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0a2cu))); /* mov ecx, dword ptr [0x10010a2c] */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0a2cu))); /* mov ecx, dword ptr [0x10010a2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + ecx*4 + 0xc4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov eax, dword ptr [eax + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x43u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [eax + 0x43] */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x43u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 0x43], 0 */
    if (!c->zf) goto L_00cd7bc8; /* jne 0xcd7bc8 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [eax + 4], 0xfffffffe */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
L_00cd7bc8:;
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + 8], -1 */
    if (!c->zf) goto L_00cd7c37; /* jne 0xcd7c37 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd7bd6u); call_indirect(c, t_); } /* call esi */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd7becu); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a38u))); /* mov eax, dword ptr [0x10010a38] */
    c->edx = (uint32_t)(R32((uint32_t)(0xce0a3cu))); /* mov edx, dword ptr [0x10010a3c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a34u))); /* mov eax, dword ptr [0x10010a34] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xffffffecu)); /* lea ecx, [ecx + edx - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x14u)); /* lea ecx, [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd7c15u); f_00cd7570(c); /* call 0xcd7570 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(0xce0a38u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10010a38] */
    (void)sub32(c, c->eax, R32((uint32_t)(0xce0a34u))); /* cmp eax, dword ptr [0x10010a34] */
    if ((c->cf || c->zf)) goto L_00cd7c2d; /* jbe 0xcd7c2d */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x14u))); } /* sub dword ptr [ebp + 8], 0x14 */
L_00cd7c2d:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a3cu))); /* mov eax, dword ptr [0x10010a3c] */
    W32((uint32_t)(0xce0a30u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a30], eax */
L_00cd7c37:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xce0a2cu), (uint32_t)(c->edi)); /* mov dword ptr [0x10010a2c], edi */
    W32((uint32_t)(0xce0a34u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a34], eax */
L_00cd7c45:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7c4a(CPU *c) { /* FUN_10007c4a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a38u))); /* mov eax, dword ptr [0x10010a38] */
    c->edx = (uint32_t)(R32((uint32_t)(0xce0a3cu))); /* mov edx, dword ptr [0x10010a3c] */
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
    if ((c->sf == c->of)) goto L_00cd7c8a; /* jge 0xcd7c8a */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    goto L_00cd7c9a; /* jmp 0xcd7c9a */
L_00cd7c8a:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0xc], esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00cd7c9a:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a30u))); /* mov eax, dword ptr [0x10010a30] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00cd7cc1; /* jae 0xcd7cc1 */
L_00cd7ca8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00cd7cc1; /* jne 0xcd7cc1 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->cf) goto L_00cd7ca8; /* jb 0xcd7ca8 */
L_00cd7cc1:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00cd7d3f; /* jne 0xcd7d3f */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00cd7cc8:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00cd7ce4; /* jae 0xcd7ce4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov edi, dword ptr [ebx] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00cd7ce2; /* jne 0xcd7ce2 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00cd7cc8; /* jmp 0xcd7cc8 */
L_00cd7ce2:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00cd7ce4:;
    if (!c->zf) goto L_00cd7d3f; /* jne 0xcd7d3f */
L_00cd7ce6:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
    if (!c->cf) goto L_00cd7cfc; /* jae 0xcd7cfc */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00cd7cf9; /* jne 0xcd7cf9 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    goto L_00cd7ce6; /* jmp 0xcd7ce6 */
L_00cd7cf9:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp ebx, dword ptr [ebp - 4] */
L_00cd7cfc:;
    if (!c->zf) goto L_00cd7d24; /* jne 0xcd7d24 */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00cd7d00:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->cf) goto L_00cd7d14; /* jae 0xcd7d14 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + 8], 0 */
    if (!c->zf) goto L_00cd7d12; /* jne 0xcd7d12 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00cd7d00; /* jmp 0xcd7d00 */
L_00cd7d12:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
L_00cd7d14:;
    if (!c->zf) goto L_00cd7d24; /* jne 0xcd7d24 */
    PUSH32(c, 0x00cd7d1bu); f_00cd7f53(c); /* call 0xcd7f53 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->zf) goto L_00cd7d38; /* je 0xcd7d38 */
L_00cd7d24:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd7d2au); f_00cd8004(c); /* call 0xcd8004 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov ecx, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00cd7d3f; /* jne 0xcd7d3f */
L_00cd7d38:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd7f4e; /* jmp 0xcd7f4e */
L_00cd7d3f:;
    W32((uint32_t)(0xce0a30u), (uint32_t)(c->ebx)); /* mov dword ptr [0x10010a30], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    if (c->zf) goto L_00cd7d66; /* je 0xcd7d66 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov edi, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & c->esi))); /* and edi, esi */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    if (!c->zf) goto L_00cd7d9d; /* jne 0xcd7d9d */
L_00cd7d66:;
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0xc4u))); /* mov edx, dword ptr [eax + 0xc4] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x44u))); /* mov esi, dword ptr [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & R32((uint32_t)(c->ebp + 0xfffffff4u))))); /* and esi, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x44u)); /* lea ecx, [eax + 0x44] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->esi))); /* or edx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    if (!c->zf) goto L_00cd7d9a; /* jne 0xcd7d9a */
L_00cd7d83:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x84u))); /* mov edx, dword ptr [ecx + 0x84] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and edx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & R32((uint32_t)(c->ecx))))); /* and edi, dword ptr [ecx] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->edi))); /* or edx, edi */
    if (c->zf) goto L_00cd7d83; /* je 0xcd7d83 */
L_00cd7d9a:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
L_00cd7d9d:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x204u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x204 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x144u)); /* lea ecx, [ecx + eax + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0x44u))); /* mov ecx, dword ptr [eax + edx*4 + 0x44] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->esi))); /* and ecx, esi */
    if (!c->zf) goto L_00cd7dc6; /* jne 0xcd7dc6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4 + 0xc4u))); /* mov ecx, dword ptr [eax + edx*4 + 0xc4] */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & R32((uint32_t)(c->ebp + 0xfffffff8u))))); /* and ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cd7dc6:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if ((c->sf != c->of)) goto L_00cd7dcf; /* jl 0xcd7dcf */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 1)); /* shl ecx, 1 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd7dc6; /* jmp 0xcd7dc6 */
L_00cd7dcf:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 8 + 0x4u))); /* mov edx, dword ptr [ecx + edi*8 + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff0u)))); /* sub ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->zf || c->sf != c->of)) goto L_00cd7dec; /* jle 0xcd7dec */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd7dec:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00cd7f01; /* je 0xcd7f01 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edx + 0x8u))); /* cmp ecx, dword ptr [edx + 8] */
    if (!c->zf) goto L_00cd7e5d; /* jne 0xcd7e5d */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if ((c->sf == c->of)) goto L_00cd7e2c; /* jge 0xcd7e2c */
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
    if (!c->zf) goto L_00cd7e5a; /* jne 0xcd7e5a */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx], ecx */
    goto L_00cd7e5d; /* jmp 0xcd7e5d */
L_00cd7e2c:;
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
    if (!c->zf) goto L_00cd7e5a; /* jne 0xcd7e5a */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ecx)))); } /* and dword ptr [ebx + 4], ecx */
    goto L_00cd7e5d; /* jmp 0xcd7e5d */
L_00cd7e5a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd7e5d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov ecx, dword ptr [edx + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edi, dword ptr [edx + 4] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 4], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ecx + 8], edi */
    if (c->zf) goto L_00cd7f0d; /* je 0xcd7f0d */
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
    if (!c->zf) goto L_00cd7efe; /* jne 0xcd7efe */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xbu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xb], cl */
    if ((c->sf == c->of)) goto L_00cd7ecf; /* jge 0xcd7ecf */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00cd7ebd; /* jne 0xcd7ebd */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx], edi */
L_00cd7ebd:;
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + ecx*4 + 0x44], edi */
    goto L_00cd7efe; /* jmp 0xcd7efe */
L_00cd7ecf:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xbu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xb], 0 */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->zf) goto L_00cd7ee8; /* jne 0xcd7ee8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ebx + 4], edi */
L_00cd7ee8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->ecx * 4 + 0xc4u)); /* lea edi, [eax + ecx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->esi = (uint32_t)(shr32(c, c->esi, (c->ecx & 0xff))); /* shr esi, cl */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->esi)))); } /* or dword ptr [edi], esi */
L_00cd7efe:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00cd7f01:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd7f10; /* je 0xcd7f10 */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    W32((uint32_t)(c->ecx + c->edx + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + edx - 4], ecx */
    goto L_00cd7f10; /* jmp 0xcd7f10 */
L_00cd7f0d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
L_00cd7f10:;
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
    if (!c->zf) goto L_00cd7f46; /* jne 0xcd7f46 */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xce0a34u))); /* cmp ebx, dword ptr [0x10010a34] */
    if (!c->zf) goto L_00cd7f46; /* jne 0xcd7f46 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0xce0a2cu))); /* cmp ecx, dword ptr [0x10010a2c] */
    if (!c->zf) goto L_00cd7f46; /* jne 0xcd7f46 */
    { uint32_t a_ = (uint32_t)(0xce0a34u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10010a34], 0 */
L_00cd7f46:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0x4u)); /* lea eax, [edx + 4] */
L_00cd7f4e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd7f53(CPU *c) { /* FUN_10007f53 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a38u))); /* mov eax, dword ptr [0x10010a38] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0a28u))); /* mov ecx, dword ptr [0x10010a28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00cd7f96; /* jne 0xcd7f96 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4 + 0x50u)); /* lea eax, [ecx + ecx*4 + 0x50] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xce0a3cu)); PUSH32(c, v_); } /* push dword ptr [0x10010a3c] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc058u)); PUSH32(c, 0x00cd7f81u); call_indirect(c, t_); } /* call dword ptr [0x1000c058] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00cd7fe6; /* je 0xcd7fe6 */
    { uint32_t a_ = (uint32_t)(0xce0a28u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [0x10010a28], 0x10 */
    W32((uint32_t)(0xce0a3cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a3c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0a38u))); /* mov eax, dword ptr [0x10010a38] */
L_00cd7f96:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xce0a3cu))); /* mov ecx, dword ptr [0x10010a3c] */
    { uint32_t v_ = 0x41c4u; PUSH32(c, v_); } /* push 0x41c4 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd7fb5u); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    if (c->zf) goto L_00cd7fe6; /* je 0xcd7fe6 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0acu)); PUSH32(c, 0x00cd7fcfu); call_indirect(c, t_); } /* call dword ptr [0x1000c0ac] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_00cd7fea; /* jne 0xcd7fea */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd7fe6u); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
L_00cd7fe6:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd8001; /* jmp 0xcd8001 */
L_00cd7fea:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 8], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    { uint32_t a_ = (uint32_t)(0xce0a38u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10010a38] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd8001:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd8004(CPU *c) { /* FUN_10008004 */
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
L_00cd8016:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00cd801f; /* jl 0xcd801f */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00cd8016; /* jmp 0xcd8016 */
L_00cd801f:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x204u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x204 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi + 0x144u)); /* lea eax, [eax + esi + 0x144] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00cd8034:;
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 8], eax */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [eax + 4], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00cd8034; /* jne 0xcd8034 */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->edi = (uint32_t)(shl32(c, c->edi, 15)); /* shl edi, 0xf */
    c->edi = (uint32_t)(add32(c, c->edi, R32((uint32_t)(c->ecx + 0xcu)))); /* add edi, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0acu)); PUSH32(c, 0x00cd805bu); call_indirect(c, t_); } /* call dword ptr [0x1000c0ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd8067; /* jne 0xcd8067 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00cd80fa; /* jmp 0xcd80fa */
L_00cd8067:;
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x7000u)); /* lea edx, [edi + 0x7000] */
    (void)sub32(c, c->edi, c->edx); /* cmp edi, edx */
    if ((!c->cf && !c->zf)) goto L_00cd80ad; /* ja 0xcd80ad */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x10u)); /* lea eax, [edi + 0x10] */
L_00cd8074:;
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
    if ((c->cf || c->zf)) goto L_00cd8074; /* jbe 0xcd8074 */
L_00cd80ad:;
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
    if (!c->zf) goto L_00cd80ea; /* jne 0xcd80ea */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [eax + 4], edi */
L_00cd80ea:;
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax + 8], edx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00cd80fa:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd80ff(CPU *c) { /* FUN_100080ff */
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
    if ((c->zf || c->sf != c->of)) goto L_00cd82ad; /* jle 0xcd82ad */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00cd82a6; /* jne 0xcd82a6 */
    c->ebx = (uint32_t)(add32(c, c->ebx, c->ecx)); /* add ebx, ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((!c->zf && c->sf == c->of)) goto L_00cd82a6; /* jg 0xcd82a6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 4)); /* sar ecx, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)sub32(c, c->ecx, (uint32_t)0x3fu); /* cmp ecx, 0x3f */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if ((c->cf || c->zf)) goto L_00cd8176; /* jbe 0xcd8176 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_00cd8176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ebx, dword ptr [edi + 4] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ebx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00cd81c6; /* jne 0xcd81c6 */
    (void)sub32(c, c->ecx, (uint32_t)0x20u); /* cmp ecx, 0x20 */
    if (!c->cf) goto L_00cd81a2; /* jae 0xcd81a2 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00cd81c6; /* jne 0xcd81c6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00cd81c6; /* jmp 0xcd81c6 */
L_00cd81a2:;
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0xffffffe0u)); /* add ecx, -0x20 */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->eax + 0x4u)); /* lea ecx, [ecx + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00cd81c6; /* jne 0xcd81c6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00cd81c6:;
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
    if ((c->zf || c->sf != c->of)) goto L_00cd8294; /* jle 0xcd8294 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(sar32(c, c->edi, 4)); /* sar edi, 4 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea ecx, [ecx + esi - 4] */
    (void)sub32(c, c->edi, (uint32_t)0x3fu); /* cmp edi, 0x3f */
    if ((c->cf || c->zf)) goto L_00cd8200; /* jbe 0xcd8200 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cd8200:;
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
    if (!c->zf) goto L_00cd8282; /* jne 0xcd8282 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + c->eax + 0x4u))); /* mov cl, byte ptr [edi + eax + 4] */
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    W8((uint32_t)(c->ebp + 0x13u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0x13], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->edi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edi + eax + 4], cl */
    if (!c->cf) goto L_00cd8259; /* jae 0xcd8259 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00cd824c; /* jne 0xcd824c */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx], ebx */
L_00cd824c:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    goto L_00cd827e; /* jmp 0xcd827e */
L_00cd8259:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x13u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x13], 0 */
    if (!c->zf) goto L_00cd826f; /* jne 0xcd826f */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [ecx + 4], ebx */
L_00cd826f:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffe0u)); /* lea ecx, [edi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00cd827e:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00cd8282:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->esi + 0xfffffffcu)); /* lea eax, [edx + esi - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->ecx + c->eax + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ecx + eax - 4], ecx */
    goto L_00cd8297; /* jmp 0xcd8297 */
L_00cd8294:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
L_00cd8297:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    W32((uint32_t)(c->edx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edx - 4], eax */
    W32((uint32_t)(c->edx + c->esi + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + esi - 8], eax */
    goto L_00cd83ed; /* jmp 0xcd83ed */
L_00cd82a6:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd83f0; /* jmp 0xcd83f0 */
L_00cd82ad:;
    if ((c->sf == c->of)) goto L_00cd83ed; /* jge 0xcd83ed */
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
    if ((c->cf || c->zf)) goto L_00cd82d8; /* jbe 0xcd82d8 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd82d8:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 4], 1 */
    if (!c->zf) goto L_00cd8367; /* jne 0xcd8367 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esi = (uint32_t)(sar32(c, c->esi, 4)); /* sar esi, 4 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)sub32(c, c->esi, (uint32_t)0x3fu); /* cmp esi, 0x3f */
    if ((c->cf || c->zf)) goto L_00cd82f1; /* jbe 0xcd82f1 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd82f1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov ecx, dword ptr [edi + 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u))); /* cmp ecx, dword ptr [edi + 8] */
    if (!c->zf) goto L_00cd8340; /* jne 0xcd8340 */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    if (!c->cf) goto L_00cd831c; /* jae 0xcd831c */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea esi, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0x44u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0x44], ebx */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esi] */
    if (!c->zf) goto L_00cd833d; /* jne 0xcd833d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx], ebx */
    goto L_00cd833d; /* jmp 0xcd833d */
L_00cd831c:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->ebx = (uint32_t)((uint32_t)0x80000000u); /* mov ebx, 0x80000000 */
    c->ebx = (uint32_t)(shr32(c, c->ebx, (c->ecx & 0xff))); /* shr ebx, cl */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->eax + 0x4u)); /* lea ecx, [esi + eax + 4] */
    c->ebx = (uint32_t)((uint32_t)~c->ebx); /* not ebx */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4 + 0xc4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [eax + edx*4 + 0xc4], ebx */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [ecx] */
    if (!c->zf) goto L_00cd833d; /* jne 0xcd833d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->ebx)))); } /* and dword ptr [ecx + 4], ebx */
L_00cd833d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
L_00cd8340:;
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
    if ((c->cf || c->zf)) goto L_00cd8367; /* jbe 0xcd8367 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd8367:;
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
    if (!c->zf) goto L_00cd83e4; /* jne 0xcd83e4 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + c->eax + 0x4u))); /* mov cl, byte ptr [esi + eax + 4] */
    (void)sub32(c, c->esi, (uint32_t)0x20u); /* cmp esi, 0x20 */
    W8((uint32_t)(c->ebp + 0xfu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp + 0xf], cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    W8((uint32_t)(c->esi + c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi + eax + 4], cl */
    if (!c->cf) goto L_00cd83bb; /* jae 0xcd83bb */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00cd83ae; /* jne 0xcd83ae */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx], edi */
L_00cd83ae:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0x44u)); /* lea eax, [eax + edx*4 + 0x44] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    goto L_00cd83e0; /* jmp 0xcd83e0 */
L_00cd83bb:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0xf], 0 */
    if (!c->zf) goto L_00cd83d1; /* jne 0xcd83d1 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edi = (uint32_t)((uint32_t)0x80000000u); /* mov edi, 0x80000000 */
    c->edi = (uint32_t)(shr32(c, c->edi, (c->ecx & 0xff))); /* shr edi, cl */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 4], edi */
L_00cd83d1:;
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 4 + 0xc4u)); /* lea eax, [eax + edx*4 + 0xc4] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xffffffe0u)); /* lea ecx, [esi - 0x20] */
    c->edx = (uint32_t)((uint32_t)0x80000000u); /* mov edx, 0x80000000 */
L_00cd83e0:;
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edx)))); } /* or dword ptr [eax], edx */
L_00cd83e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(c->eax + c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [eax + ebx - 4], eax */
L_00cd83ed:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd83f0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd83f5(CPU *c) { /* FUN_100083f5 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xcdd820u)), (uint32_t)0xffffffffu); /* cmp dword ptr [0x1000d820], -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd8409; /* jne 0xcd8409 */
    c->esi = (uint32_t)((uint32_t)0xcdd810u); /* mov esi, 0x1000d810 */
    goto L_00cd8426; /* jmp 0xcd8426 */
L_00cd8409:;
    { uint32_t v_ = 0x2020u; PUSH32(c, v_); } /* push 0x2020 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc05cu)); PUSH32(c, 0x00cd841cu); call_indirect(c, t_); } /* call dword ptr [0x1000c05c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00cd8532; /* je 0xcd8532 */
L_00cd8426:;
    c->ebp = (uint32_t)(R32((uint32_t)(0xcdc0acu))); /* mov ebp, dword ptr [0x1000c0ac] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x2000u; PUSH32(c, v_); } /* push 0x2000 */
    { uint32_t v_ = 0x400000u; PUSH32(c, v_); } /* push 0x400000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00cd843cu); call_indirect(c, t_); } /* call ebp */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00cd851b; /* je 0xcd851b */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->ebx = (uint32_t)((uint32_t)0x10000u); /* mov ebx, 0x10000 */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00cd8456u); call_indirect(c, t_); } /* call ebp */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd850d; /* je 0xcd850d */
    c->eax = (uint32_t)((uint32_t)0xcdd810u); /* mov eax, 0x1000d810 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->zf) goto L_00cd8485; /* jne 0xcd8485 */
    (void)sub32(c, R32((uint32_t)(0xcdd810u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d810], 0 */
    if (!c->zf) goto L_00cd8475; /* jne 0xcd8475 */
    W32((uint32_t)(0xcdd810u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d810], eax */
L_00cd8475:;
    (void)sub32(c, R32((uint32_t)(0xcdd814u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000d814], 0 */
    if (!c->zf) goto L_00cd849a; /* jne 0xcd849a */
    W32((uint32_t)(0xcdd814u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d814], eax */
    goto L_00cd849a; /* jmp 0xcd849a */
L_00cd8485:;
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd814u))); /* mov eax, dword ptr [0x1000d814] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(0xcdd814u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000d814], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
L_00cd849a:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x400000u)); /* lea eax, [edi + 0x400000] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x98u)); /* lea ecx, [esi + 0x98] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea eax, [esi + 0x18] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xc], ecx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)((uint32_t)0xf1u); /* mov ecx, 0xf1 */
L_00cd84bc:;
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
    if ((c->sf != c->of)) goto L_00cd84bc; /* jl 0xcd84bc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00cd84e2u); f_00cd7510(c); /* call 0xcd7510 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00cd84e5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00cd8509; /* jae 0xcd8509 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xf8u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xffu)))); } /* or byte ptr [edi + 0xf8], 0xff */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf0u)); /* mov dword ptr [edi + 4], 0xf0 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x1000u)); /* add edi, 0x1000 */
    goto L_00cd84e5; /* jmp 0xcd84e5 */
L_00cd8509:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cd8534; /* jmp 0xcd8534 */
L_00cd850d:;
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc09cu)); PUSH32(c, 0x00cd851bu); call_indirect(c, t_); } /* call dword ptr [0x1000c09c] */
L_00cd851b:;
    (void)sub32(c, c->esi, (uint32_t)0xcdd810u); /* cmp esi, 0x1000d810 */
    if (c->zf) goto L_00cd8532; /* je 0xcd8532 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd8532u); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
L_00cd8532:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd8534:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd8539(CPU *c) { /* FUN_10008539 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xcdc09cu)); PUSH32(c, 0x00cd854eu); call_indirect(c, t_); } /* call dword ptr [0x1000c09c] */
    (void)sub32(c, R32((uint32_t)(0xcdf830u)), c->esi); /* cmp dword ptr [0x1000f830], esi */
    if (!c->zf) goto L_00cd855e; /* jne 0xcd855e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(0xcdf830u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f830], eax */
L_00cd855e:;
    (void)sub32(c, c->esi, (uint32_t)0xcdd810u); /* cmp esi, 0x1000d810 */
    if (c->zf) goto L_00cd8586; /* je 0xcd8586 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    { uint32_t v_ = R32((uint32_t)(0xce0a44u)); PUSH32(c, v_); } /* push dword ptr [0x10010a44] */
    { uint32_t t_ = R32((uint32_t)(0xcdc048u)); PUSH32(c, 0x00cd8584u); call_indirect(c, t_); } /* call dword ptr [0x1000c048] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00cd8586:;
    { uint32_t a_ = (uint32_t)(0xcdd820u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000d820], 0xffffffff */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd858f(CPU *c) { /* FUN_1000858f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xcdd814u))); /* mov esi, dword ptr [0x1000d814] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00cd859c:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi + 0x10], -1 */
    if (c->zf) goto L_00cd863a; /* je 0xcd863a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2010u)); /* lea edi, [esi + 0x2010] */
    c->ebx = (uint32_t)((uint32_t)0x3ff000u); /* mov ebx, 0x3ff000 */
L_00cd85b5:;
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xf0u); /* cmp dword ptr [edi], 0xf0 */
    if (!c->zf) goto L_00cd85f6; /* jne 0xcd85f6 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->esi + 0x10u)))); /* add eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc09cu)); PUSH32(c, 0x00cd85d3u); call_indirect(c, t_); } /* call dword ptr [0x1000c09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd85f6; /* je 0xcd85f6 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(0xce0644u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10010644] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd85eb; /* je 0xcd85eb */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00cd85ee; /* jbe 0xcd85ee */
L_00cd85eb:;
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
L_00cd85ee:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (c->zf) goto L_00cd8603; /* je 0xcd8603 */
L_00cd85f6:;
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x1000u)); /* sub ebx, 0x1000 */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x8u)); /* sub edi, 8 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf == c->of)) goto L_00cd85b5; /* jge 0xcd85b5 */
L_00cd8603:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    if (c->zf) goto L_00cd863a; /* je 0xcd863a */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x18u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + 0x18], -1 */
    if (!c->zf) goto L_00cd863a; /* jne 0xcd863a */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x20u)); /* lea eax, [ecx + 0x20] */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00cd861a:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (!c->zf) goto L_00cd862b; /* jne 0xcd862b */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if ((c->sf != c->of)) goto L_00cd861a; /* jl 0xcd861a */
L_00cd862b:;
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (!c->zf) goto L_00cd863a; /* jne 0xcd863a */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00cd8639u); f_00cd8539(c); /* call 0xcd8539 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd863a:;
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdd814u))); /* cmp esi, dword ptr [0x1000d814] */
    if (c->zf) goto L_00cd864c; /* je 0xcd864c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd859c; /* jg 0xcd859c */
L_00cd864c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd8651(CPU *c) { /* FUN_10008651 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)((uint32_t)0xcdd810u); /* mov edx, 0x1000d810 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
L_00cd865d:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x10u))); /* cmp eax, dword ptr [ecx + 0x10] */
    if ((c->cf || c->zf)) goto L_00cd8667; /* jbe 0xcd8667 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x14u))); /* cmp eax, dword ptr [ecx + 0x14] */
    if (c->cf) goto L_00cd866f; /* jb 0xcd866f */
L_00cd8667:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_00cd86a4; /* je 0xcd86a4 */
    goto L_00cd865d; /* jmp 0xcd865d */
L_00cd866f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfu)); /* test al, 0xf */
    if (!c->zf) goto L_00cd86a4; /* jne 0xcd86a4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)((uint32_t)0x100u); /* mov edx, 0x100 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffu))); /* and esi, 0xfff */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (c->cf) goto L_00cd86a4; /* jb 0xcd86a4 */
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
L_00cd86a4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd86a8(CPU *c) { /* FUN_100086a8 */
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
    if (!c->zf) goto L_00cd86ec; /* jne 0xcd86ec */
    { uint32_t a_ = (uint32_t)(0xce0644u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10010644] */
    (void)sub32(c, R32((uint32_t)(0xce0644u)), (uint32_t)0x20u); /* cmp dword ptr [0x10010644], 0x20 */
    if (!c->zf) goto L_00cd86ec; /* jne 0xcd86ec */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00cd86ebu); f_00cd858f(c); /* call 0xcd858f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd86ec:;
    c->esp += 4; return; /* ret  */
}

void f_00cd86ed(CPU *c) { /* FUN_100086ed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xcdf830u))); /* mov esi, dword ptr [0x1000f830] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00cd86fb:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (c->zf) goto L_00cd87a6; /* je 0xcd87a6 */
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
    if (!c->cf) goto L_00cd8760; /* jae 0xcd8760 */
L_00cd8726:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf != c->of)) goto L_00cd8749; /* jl 0xcd8749 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00cd8749; /* jbe 0xcd8749 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd873cu); f_00cd88f5(c); /* call 0xcd88f5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd87b8; /* jne 0xcd87b8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00cd8749:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2018u)); /* lea ecx, [esi + 0x2018] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1000u)); /* add eax, 0x1000 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (c->cf) goto L_00cd8726; /* jb 0xcd8726 */
    goto L_00cd8763; /* jmp 0xcd8763 */
L_00cd8760:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd8763:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    if (!c->cf) goto L_00cd87a9; /* jae 0xcd87a9 */
L_00cd8776:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf != c->of)) goto L_00cd8795; /* jl 0xcd8795 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x4u)), c->ebx); /* cmp dword ptr [edi + 4], ebx */
    if ((c->cf || c->zf)) goto L_00cd8795; /* jbe 0xcd8795 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00cd878bu); f_00cd88f5(c); /* call 0xcd88f5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd87b8; /* jne 0xcd87b8 */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
L_00cd8795:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x1000u))); } /* add dword ptr [ebp - 4], 0x1000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp edi, dword ptr [ebp - 8] */
    if (c->cf) goto L_00cd8776; /* jb 0xcd8776 */
    goto L_00cd87a9; /* jmp 0xcd87a9 */
L_00cd87a6:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00cd87a9:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xcdf830u))); /* cmp esi, dword ptr [0x1000f830] */
    if (c->zf) goto L_00cd87c8; /* je 0xcd87c8 */
    goto L_00cd86fb; /* jmp 0xcd86fb */
L_00cd87b8:;
    W32((uint32_t)(0xcdf830u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000f830], esi */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(sub32(c, R32(a_), c->ebx))); } /* sub dword ptr [edi], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    goto L_00cd88f0; /* jmp 0xcd88f0 */
L_00cd87c8:;
    c->eax = (uint32_t)((uint32_t)0xcdd810u); /* mov eax, 0x1000d810 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00cd87cf:;
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi + 0x10], -1 */
    if (c->zf) goto L_00cd87db; /* je 0xcd87db */
    (void)sub32(c, R32((uint32_t)(c->edi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [edi + 0xc], 0 */
    if (!c->zf) goto L_00cd87e7; /* jne 0xcd87e7 */
L_00cd87db:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->zf) goto L_00cd88bc; /* je 0xcd88bc */
    goto L_00cd87cf; /* jmp 0xcd87cf */
L_00cd87e7:;
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
    if (!c->zf) goto L_00cd8816; /* jne 0xcd8816 */
L_00cd8805:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x10u); /* cmp dword ptr [ebp - 4], 0x10 */
    if ((c->sf == c->of)) goto L_00cd8816; /* jge 0xcd8816 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax], -1 */
    if (c->zf) goto L_00cd8805; /* je 0xcd8805 */
L_00cd8816:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->eax = (uint32_t)(shl32(c, c->eax, 12)); /* shl eax, 0xc */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc0acu)); PUSH32(c, 0x00cd882eu); call_indirect(c, t_); } /* call dword ptr [0x1000c0ac] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00cd88ee; /* jne 0xcd88ee */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd8841u); f_00cd7510(c); /* call 0xcd7510 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00cd887d; /* jle 0xcd887d */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
L_00cd8853:;
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
    if (!c->zf) goto L_00cd8853; /* jne 0xcd8853 */
L_00cd887d:;
    W32((uint32_t)(0xcdf830u), (uint32_t)(c->edi)); /* mov dword ptr [0x1000f830], edi */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x2018u)); /* lea eax, [edi + 0x2018] */
L_00cd8889:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->cf) goto L_00cd8899; /* jae 0xcd8899 */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx], -1 */
    if (c->zf) goto L_00cd8897; /* je 0xcd8897 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    goto L_00cd8889; /* jmp 0xcd8889 */
L_00cd8897:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
L_00cd8899:;
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
    goto L_00cd88f0; /* jmp 0xcd88f0 */
L_00cd88bc:;
    PUSH32(c, 0x00cd88c1u); f_00cd83f5(c); /* call 0xcd83f5 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd88ee; /* je 0xcd88ee */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    W8((uint32_t)(c->ecx + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx + 8], bl */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ebx + 0x8u)); /* lea edx, [ecx + ebx + 8] */
    W32((uint32_t)(0xcdf830u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f830], eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)((uint32_t)0xf0u); /* mov edx, 0xf0 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ebx)); /* sub edx, ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx edx, bl */
    { uint32_t a_ = (uint32_t)(c->eax + 0x18u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [eax + 0x18], edx */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x100u)); /* lea eax, [ecx + 0x100] */
    goto L_00cd88f0; /* jmp 0xcd88f0 */
L_00cd88ee:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd88f0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd88f5(CPU *c) { /* FUN_100088f5 */
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
    if (c->cf) goto L_00cd893a; /* jb 0xcd893a */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edx)); /* lea eax, [edi + edx] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->cf) goto L_00cd8929; /* jae 0xcd8929 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [ecx], edx */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->edx))); } /* sub dword ptr [ecx + 4], edx */
    goto L_00cd8932; /* jmp 0xcd8932 */
L_00cd8929:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00cd8932:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x8u)); /* lea eax, [edi + 8] */
    goto L_00cd8a08; /* jmp 0xcd8a08 */
L_00cd893a:;
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    if (c->zf) goto L_00cd8943; /* je 0xcd8943 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd8943:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->cf) goto L_00cd898d; /* jae 0xcd898d */
L_00cd894a:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (!c->zf) goto L_00cd8980; /* jne 0xcd8980 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ebx, [eax + 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd8956:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00cd895f; /* jne 0xcd895f */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00cd8956; /* jmp 0xcd8956 */
L_00cd895f:;
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    if (!c->cf) goto L_00cd89b1; /* jae 0xcd89b1 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp eax, dword ptr [ebp - 4] */
    if (!c->zf) goto L_00cd896d; /* jne 0xcd896d */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00cd8979; /* jmp 0xcd8979 */
L_00cd896d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 0xc], esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00cd8a12; /* jb 0xcd8a12 */
L_00cd8979:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edi, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00cd8985; /* jmp 0xcd8985 */
L_00cd8980:;
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
L_00cd8985:;
    c->esi = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea esi, [eax + edx] */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x8u))); /* cmp esi, dword ptr [ebp + 8] */
    if (c->cf) goto L_00cd894a; /* jb 0xcd894a */
L_00cd898d:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
L_00cd8990:;
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->cf) goto L_00cd8a12; /* jae 0xcd8a12 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea eax, [esi + edx] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u))); /* cmp eax, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00cd8a12; /* jae 0xcd8a12 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd89e2; /* jne 0xcd89e2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea ebx, [esi + 1] */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd89a8:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    if (!c->zf) goto L_00cd89d2; /* jne 0xcd89d2 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd89a8; /* jmp 0xcd89a8 */
L_00cd89b1:;
    c->ebx = (uint32_t)((uint32_t)(c->eax + c->edx)); /* lea ebx, [eax + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00cd89c2; /* jae 0xcd89c2 */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    goto L_00cd89cb; /* jmp 0xcd89cb */
L_00cd89c2:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea esi, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00cd89cb:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    goto L_00cd8a08; /* jmp 0xcd8a08 */
L_00cd89d2:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if (!c->cf) goto L_00cd89e9; /* jae 0xcd89e9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [ebp + 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (c->cf) goto L_00cd8a12; /* jb 0xcd8a12 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    goto L_00cd8990; /* jmp 0xcd8990 */
L_00cd89e2:;
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    goto L_00cd8990; /* jmp 0xcd8990 */
L_00cd89e9:;
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->edx)); /* lea ebx, [esi + edx] */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->ebp + 0x8u))); /* cmp ebx, dword ptr [ebp + 8] */
    if (!c->cf) goto L_00cd89fa; /* jae 0xcd89fa */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->ebx)); /* mov dword ptr [ecx], ebx */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    goto L_00cd8a03; /* jmp 0xcd8a03 */
L_00cd89fa:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x8u)); /* lea eax, [ecx + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
L_00cd8a03:;
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
L_00cd8a08:;
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0xfu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0xf */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_00cd8a14; /* jmp 0xcd8a14 */
L_00cd8a12:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd8a14:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd8a19(CPU *c) { /* FUN_10008a19 */
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
    if ((c->cf || c->zf)) goto L_00cd8a53; /* jbe 0xcd8a53 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)((uint32_t)0xf1u)); /* mov dword ptr [edi + 4], 0xf1 */
    goto L_00cd8ab3; /* jmp 0xcd8ab3 */
L_00cd8a53:;
    if (!c->cf) goto L_00cd8aba; /* jae 0xcd8aba */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->eax)); /* lea esi, [edx + eax] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd8aba; /* jb 0xcd8aba */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx)); /* lea eax, [ecx + edx] */
L_00cd8a68:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00cd8a76; /* jae 0xcd8a76 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00cd8a74; /* jne 0xcd8a74 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd8a68; /* jmp 0xcd8a68 */
L_00cd8a74:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
L_00cd8a76:;
    if (!c->zf) goto L_00cd8aba; /* jne 0xcd8aba */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x14u))); /* mov al, byte ptr [ebp + 0x14] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    (void)sub32(c, c->edx, c->eax); /* cmp edx, eax */
    if ((!c->cf && !c->zf)) goto L_00cd8aae; /* ja 0xcd8aae */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00cd8aae; /* jbe 0xcd8aae */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0xf8u)); /* lea eax, [ebx + 0xf8] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00cd8aa5; /* jae 0xcd8aa5 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebx), (uint32_t)(c->esi)); /* mov dword ptr [ebx], esi */
    (void)sub8(c, R8((uint32_t)(c->esi)), ((uint8_t)c->eax)); /* cmp byte ptr [esi], al */
    if (!c->zf) goto L_00cd8aa0; /* jne 0xcd8aa0 */
L_00cd8a99:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->esi + c->eax)), (uint8_t)0x0u); /* cmp byte ptr [esi + eax], 0 */
    if (c->zf) goto L_00cd8a99; /* je 0xcd8a99 */
L_00cd8aa0:;
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    goto L_00cd8aae; /* jmp 0xcd8aae */
L_00cd8aa5:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebx + 4], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea eax, [ebx + 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00cd8aae:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x14u)))); /* sub ecx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(add32(c, R32(a_), c->ecx))); } /* add dword ptr [edi], ecx */
L_00cd8ab3:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
L_00cd8aba:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd8ac2(CPU *c) { /* FUN_10008ac2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0b4u)); PUSH32(c, 0x00cd8ad4u); call_indirect(c, t_); } /* call dword ptr [0x1000c0b4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8ada; /* je 0xcd8ada */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00cd8ada:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd8ade(CPU *c) { /* FUN_10008ade */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0b0u)); PUSH32(c, 0x00cd8af0u); call_indirect(c, t_); } /* call dword ptr [0x1000c0b0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8af6; /* je 0xcd8af6 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00cd8af6:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd8afa(CPU *c) { /* FUN_10008afa */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0b8u)); PUSH32(c, 0x00cd8b08u); call_indirect(c, t_); } /* call dword ptr [0x1000c0b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8b0e; /* je 0xcd8b0e */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00cd8b0e:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cd8b12(CPU *c) { /* FUN_10008b12 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    PUSH32(c, 0x00cd8b19u); f_00cd696c(c); /* call 0xcd696c */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    PUSH32(c, 0x00cd8b20u); f_00cd9ece(c); /* call 0xcd9ece */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00cd8b29u); f_00cd4778(c); /* call 0xcd4778 */
    { f_00cd8b29(c); return; }
}

void f_00cd8b29(CPU *c) { /* FUN_10008b29 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc6e0u; PUSH32(c, v_); } /* push 0x1000c6e0 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0648u))); /* mov eax, dword ptr [0x10010648] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00cd8b98; /* jne 0xcd8b98 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xcdc6dcu; PUSH32(c, v_); } /* push 0x1000c6dc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c4u)); PUSH32(c, 0x00cd8b6eu); call_indirect(c, t_); } /* call dword ptr [0x1000c0c4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8b76; /* je 0xcd8b76 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cd8b93; /* jmp 0xcd8b93 */
L_00cd8b76:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xcdc6d8u; PUSH32(c, v_); } /* push 0x1000c6d8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c0u)); PUSH32(c, 0x00cd8b88u); call_indirect(c, t_); } /* call dword ptr [0x1000c0c0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8c5e; /* je 0xcd8c5e */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd8b93:;
    W32((uint32_t)(0xce0648u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010648], eax */
L_00cd8b98:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cd8bc1; /* jne 0xcd8bc1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00cd8ba9; /* jne 0xcd8ba9 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce068cu))); /* mov eax, dword ptr [0x1001068c] */
L_00cd8ba9:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c0u)); PUSH32(c, 0x00cd8bbcu); call_indirect(c, t_); } /* call dword ptr [0x1000c0c0] */
    goto L_00cd8c60; /* jmp 0xcd8c60 */
L_00cd8bc1:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cd8c5e; /* jne 0xcd8c5e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->ebx); /* cmp dword ptr [ebp + 0x18], ebx */
    if (!c->zf) goto L_00cd8bd7; /* jne 0xcd8bd7 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce069cu))); /* mov eax, dword ptr [0x1001069c] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
L_00cd8bd7:;
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
    { uint32_t t_ = R32((uint32_t)(0xcdc0bcu)); PUSH32(c, 0x00cd8bf4u); call_indirect(c, t_); } /* call dword ptr [0x1000c0bc] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00cd8c5e; /* je 0xcd8c5e */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax)); /* lea edi, [eax + eax] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00cd8c0du); f_00cd9d10(c); /* call 0xcd9d10 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(c->esp); /* mov esi, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd8c1du); f_00cd7510(c); /* call 0xcd7510 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00cd8c2d; /* jmp 0xcd8c2d */
L_00cd8c2d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00cd8c5e; /* je 0xcd8c5e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0bcu)); PUSH32(c, 0x00cd8c4au); call_indirect(c, t_); } /* call dword ptr [0x1000c0bc] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00cd8c5e; /* je 0xcd8c5e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c4u)); PUSH32(c, 0x00cd8c5cu); call_indirect(c, t_); } /* call dword ptr [0x1000c0c4] */
    goto L_00cd8c60; /* jmp 0xcd8c60 */
L_00cd8c5e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd8c60:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd8c22(CPU *c) { /* PTR_00cd8c22 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd8c26(CPU *c) { /* PTR_00cd8c26 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00cd8c5e; /* je 0xcd8c5e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0bcu)); PUSH32(c, 0x00cd8c4au); call_indirect(c, t_); } /* call dword ptr [0x1000c0bc] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00cd8c5e; /* je 0xcd8c5e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c4u)); PUSH32(c, 0x00cd8c5cu); call_indirect(c, t_); } /* call dword ptr [0x1000c0c4] */
    goto L_00cd8c60; /* jmp 0xcd8c60 */
L_00cd8c5e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd8c60:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd8c72(CPU *c) { /* FUN_10008c72 */
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
L_00cd8cad:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov cl, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u); /* cmp cl, 0x20 */
    if (c->zf) goto L_00cd8cc3; /* je 0xcd8cc3 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x9u); /* cmp cl, 9 */
    if (c->zf) goto L_00cd8cc3; /* je 0xcd8cc3 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xau); /* cmp cl, 0xa */
    if (c->zf) goto L_00cd8cc3; /* je 0xcd8cc3 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0xdu); /* cmp cl, 0xd */
    if (!c->zf) goto L_00cd8cc6; /* jne 0xcd8cc6 */
L_00cd8cc3:;
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8cad; /* jmp 0xcd8cad */
L_00cd8cc6:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd8cc9:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if ((!c->cf && !c->zf)) goto L_00cd8f4c; /* ja 0xcd8f4c */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xcd9113u)); switch (t_) { case 0x00cd8cdcu: goto L_00cd8cdc; case 0x00cd8d2bu: goto L_00cd8d2b; case 0x00cd8d82u: goto L_00cd8d82; case 0x00cd8dacu: goto L_00cd8dac; case 0x00cd8e07u: goto L_00cd8e07; case 0x00cd8e7eu: goto L_00cd8e7e; case 0x00cd8eb4u: goto L_00cd8eb4; case 0x00cd8eddu: goto L_00cd8edd; case 0x00cd8efeu: goto L_00cd8efe; case 0x00cd8f18u: goto L_00cd8f18; case 0x00cd8f4cu: goto L_00cd8f4c; case 0x00cd8f62u: goto L_00cd8f62; default: jump_indirect(c, t_, 0x00cd8cd5u); return; } } /* jmp dword ptr [eax*4 + 0x10009113] */
L_00cd8cdc:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00cd8ced; /* jl 0xcd8ced */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd8ced; /* jg 0xcd8ced */
L_00cd8ce6:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00cd8f0a; /* jmp 0xcd8f0a */
L_00cd8ced:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xcdd504u))); /* cmp bl, byte ptr [0x1000d504] */
    if (!c->zf) goto L_00cd8cfc; /* jne 0xcd8cfc */
L_00cd8cf5:;
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00cd8f42; /* jmp 0xcd8f42 */
L_00cd8cfc:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00cd8d22; /* je 0xcd8d22 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd8d16; /* je 0xcd8d16 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00cd8fe5; /* jne 0xcd8fe5 */
    goto L_00cd8da5; /* jmp 0xcd8da5 */
L_00cd8d16:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8d22:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8d2b:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    if ((c->sf != c->of)) goto L_00cd8d38; /* jl 0xcd8d38 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8ce6; /* jle 0xcd8ce6 */
L_00cd8d38:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xcdd504u))); /* cmp bl, byte ptr [0x1000d504] */
    if (c->zf) goto L_00cd8e00; /* je 0xcd8e00 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00cd8d7a; /* je 0xcd8d7a */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00cd8d7a; /* je 0xcd8d7a */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00cd8da5; /* je 0xcd8da5 */
L_00cd8d53:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x43u); /* cmp bl, 0x43 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8fe5; /* jle 0xcd8fe5 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x45u); /* cmp bl, 0x45 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8d73; /* jle 0xcd8d73 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x63u); /* cmp bl, 0x63 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8fe5; /* jle 0xcd8fe5 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x65u); /* cmp bl, 0x65 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd8fe5; /* jg 0xcd8fe5 */
L_00cd8d73:;
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    goto L_00cd8f42; /* jmp 0xcd8f42 */
L_00cd8d7a:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    goto L_00cd8f42; /* jmp 0xcd8f42 */
L_00cd8d82:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00cd8d90; /* jl 0xcd8d90 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8ce6; /* jle 0xcd8ce6 */
L_00cd8d90:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xcdd504u))); /* cmp bl, byte ptr [0x1000d504] */
    if (c->zf) goto L_00cd8cf5; /* je 0xcd8cf5 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00cd8f5a; /* jne 0xcd8f5a */
L_00cd8da5:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8dac:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
L_00cd8daf:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), c->edx); /* cmp dword ptr [0x1000d500], edx */
    if ((c->zf || c->sf != c->of)) goto L_00cd8dc8; /* jle 0xcd8dc8 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd8dc1u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00cd8dd6; /* jmp 0xcd8dd6 */
L_00cd8dc8:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00cd8dd6:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8df8; /* je 0xcd8df8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00cd8df0; /* jae 0xcd8df0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_00cd8df3; /* jmp 0xcd8df3 */
L_00cd8df0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
L_00cd8df3:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8daf; /* jmp 0xcd8daf */
L_00cd8df8:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xcdd504u))); /* cmp bl, byte ptr [0x1000d504] */
    if (!c->zf) goto L_00cd8e67; /* jne 0xcd8e67 */
L_00cd8e00:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8e07:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if (!c->zf) goto L_00cd8e20; /* jne 0xcd8e20 */
L_00cd8e13:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00cd8e20; /* jne 0xcd8e20 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8e13; /* jmp 0xcd8e13 */
L_00cd8e20:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), c->edx); /* cmp dword ptr [0x1000d500], edx */
    if ((c->zf || c->sf != c->of)) goto L_00cd8e39; /* jle 0xcd8e39 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd8e32u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00cd8e47; /* jmp 0xcd8e47 */
L_00cd8e39:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00cd8e47:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8e67; /* je 0xcd8e67 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00cd8e62; /* jae 0xcd8e62 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
L_00cd8e62:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8e20; /* jmp 0xcd8e20 */
L_00cd8e67:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) goto L_00cd8d7a; /* je 0xcd8d7a */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) goto L_00cd8d7a; /* je 0xcd8d7a */
    goto L_00cd8d53; /* jmp 0xcd8d53 */
L_00cd8e7e:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), c->edx); /* cmp dword ptr [0x1000d500], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if ((c->zf || c->sf != c->of)) goto L_00cd8e9a; /* jle 0xcd8e9a */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd8e93u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00cd8ea8; /* jmp 0xcd8ea8 */
L_00cd8e9a:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00cd8ea8:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8f5a; /* je 0xcd8f5a */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cd8f0b; /* jmp 0xcd8f0b */
L_00cd8eb4:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xfffffffeu)); /* lea ecx, [edi - 2] */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if ((c->sf != c->of)) goto L_00cd8ec4; /* jl 0xcd8ec4 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8f08; /* jle 0xcd8f08 */
L_00cd8ec4:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00cd8f40; /* je 0xcd8f40 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd8f34; /* je 0xcd8f34 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00cd8fe8; /* jne 0xcd8fe8 */
L_00cd8ed9:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_00cd8f42; /* jmp 0xcd8f42 */
L_00cd8edd:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
L_00cd8ee0:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00cd8eea; /* jne 0xcd8eea */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8ee0; /* jmp 0xcd8ee0 */
L_00cd8eea:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00cd8fe5; /* jl 0xcd8fe5 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd8fe5; /* jg 0xcd8fe5 */
    goto L_00cd8f08; /* jmp 0xcd8f08 */
L_00cd8efe:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00cd8f11; /* jl 0xcd8f11 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd8f11; /* jg 0xcd8f11 */
L_00cd8f08:;
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
L_00cd8f0a:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd8f0b:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8f11:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00cd8f5a; /* jne 0xcd8f5a */
    goto L_00cd8ed9; /* jmp 0xcd8ed9 */
L_00cd8f18:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    if (c->zf) goto L_00cd8f48; /* je 0xcd8f48 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if (c->zf) goto L_00cd8f40; /* je 0xcd8f40 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00cd8fe8; /* jne 0xcd8fe8 */
L_00cd8f34:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x18], 0xffffffff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8f40:;
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
L_00cd8f42:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8f48:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cd8f4c:;
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if (c->zf) goto L_00cd8fea; /* je 0xcd8fea */
    goto L_00cd8cc9; /* jmp 0xcd8cc9 */
L_00cd8f5a:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00cd8fea; /* jmp 0xcd8fea */
L_00cd8f62:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00cd8f6b:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8f83; /* jle 0xcd8f83 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd8f7fu); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd8f92; /* jmp 0xcd8f92 */
L_00cd8f83:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00cd8f92:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8fb2; /* je 0xcd8fb2 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea esi, [ecx + eax*2 - 0x30] */
    (void)sub32(c, c->esi, (uint32_t)0x1450u); /* cmp esi, 0x1450 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd8fad; /* jg 0xcd8fad */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8f6b; /* jmp 0xcd8f6b */
L_00cd8fad:;
    c->esi = (uint32_t)((uint32_t)0x1451u); /* mov esi, 0x1451 */
L_00cd8fb2:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
L_00cd8fb5:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd8fcd; /* jle 0xcd8fcd */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd8fc9u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd8fdc; /* jmp 0xcd8fdc */
L_00cd8fcd:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00cd8fdc:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd8fe5; /* je 0xcd8fe5 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00cd8fb5; /* jmp 0xcd8fb5 */
L_00cd8fe5:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00cd8fea; /* jmp 0xcd8fea */
L_00cd8fe8:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00cd8fea:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00cd90d2; /* je 0xcd90d2 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00cd9016; /* jbe 0xcd9016 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00cd900a; /* jl 0xcd900a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00cd900a:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00cd9019; /* jmp 0xcd9019 */
L_00cd9016:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00cd9019:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00cd90c8; /* jbe 0xcd90c8 */
L_00cd9023:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00cd9031; /* jne 0xcd9031 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00cd9023; /* jmp 0xcd9023 */
L_00cd9031:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd9041u); f_00cda3b6(c); /* call 0xcda3b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00cd9050; /* jge 0xcd9050 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00cd9050:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00cd905b; /* jne 0xcd905b */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00cd905b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00cd9063; /* jne 0xcd9063 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00cd9063:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00cd909a; /* jle 0xcd909a */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00cd9071:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00cd907d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00cd90e3; /* je 0xcd90e3 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00cd90f8; /* jmp 0xcd90f8 */
L_00cd909a:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00cd90aa; /* jge 0xcd90aa */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00cd9071; /* jmp 0xcd9071 */
L_00cd90aa:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd90b7u); f_00cda930(c); /* call 0xcda930 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00cd907d; /* jmp 0xcd907d */
L_00cd90c8:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00cd907d; /* jmp 0xcd907d */
L_00cd90d2:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00cd90f8; /* jmp 0xcd90f8 */
L_00cd90e3:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00cd90f8; /* je 0xcd90f8 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00cd90f8:;
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

void f_00cd8cdc(CPU *c) { /* PTR_00cd8cdc */
    PREEMPT_POLL(c);
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00cd8ced; /* jl 0xcd8ced */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd8ced; /* jg 0xcd8ced */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    goto L_00cd8f0a; /* jmp 0xcd8f0a */
L_00cd8ced:;
    (void)sub8(c, ((uint8_t)c->ebx), R8((uint32_t)(0xcdd504u))); /* cmp bl, byte ptr [0x1000d504] */
    if (!c->zf) goto L_00cd8cfc; /* jne 0xcd8cfc */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    goto L_00cd8f42; /* jmp 0xcd8f42 */
L_00cd8cfc:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00cd8d22; /* je 0xcd8d22 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd8d16; /* je 0xcd8d16 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00cd8fe5; /* jne 0xcd8fe5 */
    goto L_00cd8da5; /* jmp 0xcd8da5 */
L_00cd8d16:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x8000u)); /* mov dword ptr [ebp - 0x28], 0x8000 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00cd8cc9u, 0x00cd8d20u); return; } /* jmp 0xcd8cc9 */
L_00cd8d22:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00cd8cc9u, 0x00cd8d29u); return; } /* jmp 0xcd8cc9 */
L_00cd8da5:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    { jump_indirect(c, 0x00cd8cc9u, 0x00cd8da7u); return; } /* jmp 0xcd8cc9 */
L_00cd8f0a:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { jump_indirect(c, 0x00cd8cc9u, 0x00cd8f0cu); return; } /* jmp 0xcd8cc9 */
L_00cd8f42:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { jump_indirect(c, 0x00cd8cc9u, 0x00cd8f43u); return; } /* jmp 0xcd8cc9 */
L_00cd8fe5:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00cd8fea; /* jmp 0xcd8fea */
L_00cd8fea:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00cd90d2; /* je 0xcd90d2 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00cd9016; /* jbe 0xcd9016 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00cd900a; /* jl 0xcd900a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00cd900a:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00cd9019; /* jmp 0xcd9019 */
L_00cd9016:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00cd9019:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00cd90c8; /* jbe 0xcd90c8 */
L_00cd9023:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00cd9031; /* jne 0xcd9031 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00cd9023; /* jmp 0xcd9023 */
L_00cd9031:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd9041u); f_00cda3b6(c); /* call 0xcda3b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00cd9050; /* jge 0xcd9050 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00cd9050:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00cd905b; /* jne 0xcd905b */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00cd905b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00cd9063; /* jne 0xcd9063 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00cd9063:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00cd909a; /* jle 0xcd909a */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00cd9071:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00cd907d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00cd90e3; /* je 0xcd90e3 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00cd90f8; /* jmp 0xcd90f8 */
L_00cd909a:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00cd90aa; /* jge 0xcd90aa */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00cd9071; /* jmp 0xcd9071 */
L_00cd90aa:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd90b7u); f_00cda930(c); /* call 0xcda930 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00cd907d; /* jmp 0xcd907d */
L_00cd90c8:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00cd907d; /* jmp 0xcd907d */
L_00cd90d2:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00cd90f8; /* jmp 0xcd90f8 */
L_00cd90e3:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00cd90f8; /* je 0xcd90f8 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00cd90f8:;
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

void f_00cd8f5a(CPU *c) { /* PTR_00cd8f5a */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00cd8fea; /* jmp 0xcd8fea */
L_00cd8fea:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00cd90d2; /* je 0xcd90d2 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00cd9016; /* jbe 0xcd9016 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00cd900a; /* jl 0xcd900a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00cd900a:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00cd9019; /* jmp 0xcd9019 */
L_00cd9016:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00cd9019:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00cd90c8; /* jbe 0xcd90c8 */
L_00cd9023:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00cd9031; /* jne 0xcd9031 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00cd9023; /* jmp 0xcd9023 */
L_00cd9031:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd9041u); f_00cda3b6(c); /* call 0xcda3b6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00cd9050; /* jge 0xcd9050 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00cd9050:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00cd905b; /* jne 0xcd905b */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00cd905b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00cd9063; /* jne 0xcd9063 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00cd9063:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00cd909a; /* jle 0xcd909a */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00cd9071:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00cd907d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00cd90e3; /* je 0xcd90e3 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00cd90f8; /* jmp 0xcd90f8 */
L_00cd909a:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00cd90aa; /* jge 0xcd90aa */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00cd9071; /* jmp 0xcd9071 */
L_00cd90aa:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd90b7u); f_00cda930(c); /* call 0xcda930 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00cd907d; /* jmp 0xcd907d */
L_00cd90c8:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00cd907d; /* jmp 0xcd907d */
L_00cd90d2:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00cd90f8; /* jmp 0xcd90f8 */
L_00cd90e3:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00cd90f8; /* je 0xcd90f8 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00cd90f8:;
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

void f_00cd9113(CPU *c) { /* PTR_00cd9113 */
    PREEMPT_POLL(c);
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->eax + c->eax + 0x8d2b10u))); /* fmul qword ptr [eax + eax + 0x8d2b10] */
    { uint32_t a_ = (uint32_t)(c->edx + 0xac10008du); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->eax)))); } /* adc byte ptr [edx - 0x53efff73], al */
    c->eax = (uint32_t)((uint32_t)(c->eax)); /* lea eax, [eax] */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->eax)))); } /* adc byte ptr [edi], al */
    guest_trap(c, 0x00cd9124u, "unsupported: mov es, word ptr [eax]"); /* mov es, word ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffff8eu); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ebx >> 8))))); } /* adc byte ptr [esi - 0x72], bh */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x8eu) << 8); /* mov ah, 0x8e */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8edd1000u); W8(a_, (uint8_t)(dec8(c, R8(a_)))); } /* dec byte ptr [esi - 0x7122f000] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x00cd9137u, "unsupported: bound ecx, qword ptr [edi - 0x70b3f000]"); /* bound ecx, qword ptr [edi - 0x70b3f000] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->edi + 0x4ca11000u); W8(a_, (uint8_t)(sbb8(c, R8(a_), ((uint8_t)c->ecx)))); } /* sbb byte ptr [edi + 0x4ca11000], cl */
    { jump_indirect(c, 0x00cd9145u, 0x00cd913fu); return; }
}

void f_00cd9143(CPU *c) { /* FUN_10009143 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xce064cu))); /* mov eax, dword ptr [0x1001064c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd915b; /* je 0xcd915b */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd9152u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd915b; /* je 0xcd915b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00cd915b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd9160(CPU *c) { /* FUN_10009160 */
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
    if ((c->cf || c->zf)) goto L_00cd9180; /* jbe 0xcd9180 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00cd92f8; /* jb 0xcd92f8 */
L_00cd9180:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00cd919c; /* jne 0xcd919c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00cd91bc; /* jb 0xcd91bc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd9195u); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd919c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00cd91b4; /* jb 0xcd91b4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xcd91c0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd91adu); return; } } /* jmp dword ptr [eax*4 + 0x100091c0] */
L_00cd91b4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd92b8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd91b4u); return; } } /* jmp dword ptr [ecx*4 + 0x100092b8] */
L_00cd91bc:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd923cu)); switch (t_) { case 0x00cd925cu: goto L_00cd925c; case 0x00cd9264u: goto L_00cd9264; case 0x00cd926cu: goto L_00cd926c; case 0x00cd9274u: goto L_00cd9274; case 0x00cd927cu: goto L_00cd927c; case 0x00cd9284u: goto L_00cd9284; case 0x00cd928cu: goto L_00cd928c; case 0x00cd929fu: goto L_00cd929f; default: jump_indirect(c, t_, 0x00cd91bcu); return; } } /* jmp dword ptr [ecx*4 + 0x1000923c] */
L_00cd925c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00cd9264:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00cd926c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00cd9274:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00cd927c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00cd9284:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00cd928c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00cd929f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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
L_00cd92f8:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00cd932c; /* jne 0xcd932c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00cd9320; /* jb 0xcd9320 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9317u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9320:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd93f0u)); switch (t_) { case 0x00cd9437u: goto L_00cd9437; default: jump_indirect(c, t_, 0x00cd9322u); return; } } /* jmp dword ptr [ecx*4 + 0x100093f0] */
L_00cd932c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00cd9344; /* jb 0xcd9344 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xcd9348u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd933du); return; } } /* jmp dword ptr [eax*4 + 0x10009348] */
L_00cd9344:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9344u); return; } } /* jmp dword ptr [ecx*4 + 0x10009440] */
L_00cd9437:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd91bc(CPU *c) { /* PTR_00cd91bc */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd923cu)); switch (t_) { case 0x00cd925cu: goto L_00cd925c; case 0x00cd9264u: goto L_00cd9264; case 0x00cd926cu: goto L_00cd926c; case 0x00cd9274u: goto L_00cd9274; case 0x00cd927cu: goto L_00cd927c; case 0x00cd9284u: goto L_00cd9284; case 0x00cd928cu: goto L_00cd928c; case 0x00cd929fu: goto L_00cd929f; default: jump_indirect(c, t_, 0x00cd91bcu); return; } } /* jmp dword ptr [ecx*4 + 0x1000923c] */
L_00cd925c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00cd9264:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00cd926c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00cd9274:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00cd927c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00cd9284:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00cd928c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00cd929f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd91d0(CPU *c) { /* PTR_00cd91d0 */
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
    if (c->cf) { f_00cd91bc(c); return; } /* jb 0xcd91bc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd91f2u); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd91f0(CPU *c) { /* PTR_00cd91f0 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd91f2u); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd91fc(CPU *c) { /* PTR_00cd91fc */
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
    if (c->cf) { f_00cd91bc(c); return; } /* jb 0xcd91bc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd9218u); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd9220(CPU *c) { /* PTR_00cd9220 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00cd91bc(c); return; } /* jb 0xcd91bc */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd9232u); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd925c(CPU *c) { /* PTR_00cd925c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd9264(CPU *c) { /* PTR_00cd9264 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd926c(CPU *c) { /* PTR_00cd926c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd9274(CPU *c) { /* PTR_00cd9274 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd927c(CPU *c) { /* PTR_00cd927c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd9284(CPU *c) { /* PTR_00cd9284 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd928c(CPU *c) { /* PTR_00cd928c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd929f(CPU *c) { /* PTR_00cd929f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd92a8u)); switch (t_) { case 0x00cd92b8u: goto L_00cd92b8; case 0x00cd92c0u: goto L_00cd92c0; case 0x00cd92ccu: goto L_00cd92cc; case 0x00cd92e0u: goto L_00cd92e0; default: jump_indirect(c, t_, 0x00cd929fu); return; } } /* jmp dword ptr [edx*4 + 0x100092a8] */
L_00cd92b8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92c0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92cc:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd92e0:;
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

void f_00cd92b8(CPU *c) { /* PTR_00cd92b8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd92c0(CPU *c) { /* PTR_00cd92c0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd92cc(CPU *c) { /* PTR_00cd92cc */
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

void f_00cd92e0(CPU *c) { /* PTR_00cd92e0 */
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

void f_00cd9320(CPU *c) { /* PTR_00cd9320 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xcd93f0u)); switch (t_) { case 0x00cd9437u: goto L_00cd9437; default: jump_indirect(c, t_, 0x00cd9322u); return; } } /* jmp dword ptr [ecx*4 + 0x100093f0] */
L_00cd9437:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9358(CPU *c) { /* PTR_00cd9358 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_00cd9320(c); return; } /* jb 0xcd9320 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd936eu); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9378(CPU *c) { /* PTR_00cd9378 */
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
    if (c->cf) { f_00cd9320(c); return; } /* jb 0xcd9320 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9398u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd93a0(CPU *c) { /* PTR_00cd93a0 */
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
    if (c->cf) { f_00cd9320(c); return; } /* jb 0xcd9320 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd93cau); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd93f4(CPU *c) { /* PTR_00cd93f4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd93fc(CPU *c) { /* PTR_00cd93fc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9404(CPU *c) { /* PTR_00cd9404 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd940c(CPU *c) { /* PTR_00cd940c */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9414(CPU *c) { /* PTR_00cd9414 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd941c(CPU *c) { /* PTR_00cd941c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [esi + ecx*4 + 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9424(CPU *c) { /* PTR_00cd9424 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0x4u))); /* mov eax, dword ptr [esi + ecx*4 + 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 + 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9437(CPU *c) { /* PTR_00cd9437 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xcd9440u)); switch (t_) { case 0x00cd9450u: goto L_00cd9450; case 0x00cd9458u: goto L_00cd9458; case 0x00cd9468u: goto L_00cd9468; case 0x00cd947cu: goto L_00cd947c; default: jump_indirect(c, t_, 0x00cd9437u); return; } } /* jmp dword ptr [edx*4 + 0x10009440] */
L_00cd9450:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd9468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cd947c:;
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

void f_00cd9450(CPU *c) { /* PTR_00cd9450 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd9458(CPU *c) { /* PTR_00cd9458 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd9468(CPU *c) { /* PTR_00cd9468 */
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

void f_00cd947c(CPU *c) { /* PTR_00cd947c */
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

void f_00cd9495(CPU *c) { /* FUN_10009495 */
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
    if (c->zf) goto L_00cd94da; /* je 0xcd94da */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd94d6; /* je 0xcd94d6 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd94d2; /* je 0xcd94d2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd94ce; /* je 0xcd94ce */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd94da; /* je 0xcd94da */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd94c6; /* je 0xcd94c6 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00cd9530; /* jne 0xcd9530 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    goto L_00cd94dc; /* jmp 0xcd94dc */
L_00cd94c6:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    goto L_00cd9530; /* jmp 0xcd9530 */
L_00cd94ce:;
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    goto L_00cd94dc; /* jmp 0xcd94dc */
L_00cd94d2:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    goto L_00cd94dc; /* jmp 0xcd94dc */
L_00cd94d6:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    goto L_00cd94dc; /* jmp 0xcd94dc */
L_00cd94da:;
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
L_00cd94dc:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd94e8u); f_00cdac5f(c); /* call 0xcdac5f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd9530; /* jne 0xcd9530 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x10u); /* cmp eax, 0x10 */
    if (c->zf) goto L_00cd9507; /* je 0xcd9507 */
    (void)sub32(c, c->eax, (uint32_t)0x16u); /* cmp eax, 0x16 */
    if (c->zf) goto L_00cd9507; /* je 0xcd9507 */
    (void)sub32(c, c->eax, (uint32_t)0x1du); /* cmp eax, 0x1d */
    if (c->zf) goto L_00cd9507; /* je 0xcd9507 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [ebp - 0x20], 0xfffffffe */
    goto L_00cd9519; /* jmp 0xcd9519 */
L_00cd9507:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    FPUSH(c, RF64((uint32_t)(c->esi + 0x10u))); /* fld qword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe3u))); /* and ecx, 0xffffffe3 */
    WF64((uint32_t)(c->ebp + 0xffffffd0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x30] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x3u))); /* or ecx, 3 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
L_00cd9519:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea ecx, [esi + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa8u)); /* lea eax, [ebp - 0x58] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd952du); f_00cda9ac(c); /* call 0xcda9ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00cd9530:;
    { uint32_t v_ = 0xffffu; PUSH32(c, v_); } /* push 0xffff */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00cd953du); f_00cdaebe(c); /* call 0xcdaebe */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x8u); /* cmp dword ptr [esi], 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cd9558; /* je 0xcd9558 */
    (void)sub32(c, R32((uint32_t)(0xcdfb28u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000fb28], 0 */
    if (!c->zf) goto L_00cd9558; /* jne 0xcd9558 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd9553u); f_00cdae9e(c); /* call 0xcdae9e */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd9560; /* jne 0xcd9560 */
L_00cd9558:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00cd955fu); f_00cdae76(c); /* call 0xcdae76 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd9560:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd9565(CPU *c) { /* FUN_10009565 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00cd9575u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd957du); f_00cd9712(c); /* call 0xcd9712 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xce07f0u))); /* cmp ebx, dword ptr [0x100107f0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (!c->zf) goto L_00cd9593; /* jne 0xcd9593 */
L_00cd958c:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00cd9703; /* jmp 0xcd9703 */
L_00cd9593:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00cd96f1; /* je 0xcd96f1 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)((uint32_t)0xcdf848u); /* mov eax, 0x1000f848 */
L_00cd95a2:;
    (void)sub32(c, R32((uint32_t)(c->eax)), c->ebx); /* cmp dword ptr [eax], ebx */
    if (c->zf) goto L_00cd961a; /* je 0xcd961a */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x30u)); /* add eax, 0x30 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub32(c, c->eax, (uint32_t)0xcdf938u); /* cmp eax, 0x1000f938 */
    if ((c->sf != c->of)) goto L_00cd95a2; /* jl 0xcd95a2 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c8u)); PUSH32(c, 0x00cd95bcu); call_indirect(c, t_); } /* call dword ptr [0x1000c0c8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00cd96e8; /* jne 0xcd96e8 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t a_ = (uint32_t)(0xce0a24u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10010a24], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xce0920u); /* mov edi, 0x10010920 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->esi); /* cmp dword ptr [ebp - 0x18], esi */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    W32((uint32_t)(0xce07f0u), (uint32_t)(c->ebx)); /* mov dword ptr [0x100107f0], ebx */
    if ((c->cf || c->zf)) goto L_00cd96d5; /* jbe 0xcd96d5 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffeeu)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x12], 0 */
    if (c->zf) goto L_00cd96b0; /* je 0xcd96b0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffefu)); /* lea ecx, [ebp - 0x11] */
L_00cd95f7:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd96b0; /* je 0xcd96b0 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx + 0xffffffffu))); /* movzx eax, byte ptr [ecx - 1] */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
L_00cd9608:;
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((!c->cf && !c->zf)) goto L_00cd96a4; /* ja 0xcd96a4 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x4u)))); } /* or byte ptr [eax + 0x10010921], 4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00cd9608; /* jmp 0xcd9608 */
L_00cd961a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xce0920u); /* mov edi, 0x10010920 */
    c->esi = (uint32_t)((uint32_t)(c->edx + c->edx * 2)); /* lea esi, [edx + edx*2] */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0xcdf858u)); /* lea ebx, [esi + 0x1000f858] */
L_00cd9637:;
    (void)sub8(c, R8((uint32_t)(c->ebx)), (uint8_t)0x0u); /* cmp byte ptr [ebx], 0 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    if (c->zf) goto L_00cd966a; /* je 0xcd966a */
L_00cd963e:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd966a; /* je 0xcd966a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ecx))); /* movzx eax, byte ptr [ecx] */
    c->edi = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edi, dl */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((!c->cf && !c->zf)) goto L_00cd9663; /* ja 0xcd9663 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xcdf840u))); /* mov dl, byte ptr [edx + 0x1000f840] */
L_00cd9658:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->edx))))); } /* or byte ptr [eax + 0x10010921], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->cf || c->zf)) goto L_00cd9658; /* jbe 0xcd9658 */
L_00cd9663:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x0u); /* cmp byte ptr [ecx], 0 */
    if (!c->zf) goto L_00cd963e; /* jne 0xcd963e */
L_00cd966a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x4u); /* cmp dword ptr [ebp - 4], 4 */
    if (c->cf) goto L_00cd9637; /* jb 0xcd9637 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xce080cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x1001080c], 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0xce07f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100107f0], eax */
    PUSH32(c, 0x00cd968eu); f_00cd975c(c); /* call 0xcd975c */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xcdf84cu)); /* lea esi, [esi + 0x1000f84c] */
    c->edi = (uint32_t)((uint32_t)0xce0800u); /* mov edi, 0x10010800 */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xce0a24u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a24], eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_00cd96f6; /* jmp 0xcd96f6 */
L_00cd96a4:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0xffffffffu)), (uint8_t)0x0u); /* cmp byte ptr [ecx - 1], 0 */
    if (!c->zf) goto L_00cd95f7; /* jne 0xcd95f7 */
L_00cd96b0:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cd96b2:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [eax + 0x10010921], 8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0xffu); /* cmp eax, 0xff */
    if (c->cf) goto L_00cd96b2; /* jb 0xcd96b2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd96c7u); f_00cd975c(c); /* call 0xcd975c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xce0a24u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a24], eax */
    W32((uint32_t)(0xce080cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1001080c], esi */
    goto L_00cd96dc; /* jmp 0xcd96dc */
L_00cd96d5:;
    { uint32_t a_ = (uint32_t)(0xce080cu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1001080c], 0 */
L_00cd96dc:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xce0800u); /* mov edi, 0x10010800 */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    goto L_00cd96f6; /* jmp 0xcd96f6 */
L_00cd96e8:;
    (void)sub32(c, R32((uint32_t)(0xce0654u)), (uint32_t)0x0u); /* cmp dword ptr [0x10010654], 0 */
    if (c->zf) goto L_00cd9700; /* je 0xcd9700 */
L_00cd96f1:;
    PUSH32(c, 0x00cd96f6u); f_00cd978f(c); /* call 0xcd978f */
L_00cd96f6:;
    PUSH32(c, 0x00cd96fbu); f_00cd97b8(c); /* call 0xcd97b8 */
    goto L_00cd958c; /* jmp 0xcd958c */
L_00cd9700:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0xffffffffu))); /* or esi, 0xffffffff */
L_00cd9703:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00cd970au); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd9712(CPU *c) { /* FUN_10009712 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(0xce0654u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x10010654], 0 */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffeu); /* cmp eax, -2 */
    if (!c->zf) goto L_00cd9732; /* jne 0xcd9732 */
    W32((uint32_t)(0xce0654u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10010654], 1 */
    { uint32_t t_ = R32((uint32_t)(0xcdc0d0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd972cu); return; } } /* jmp dword ptr [0x1000c0d0] */
L_00cd9732:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffdu); /* cmp eax, -3 */
    if (!c->zf) goto L_00cd9747; /* jne 0xcd9747 */
    W32((uint32_t)(0xce0654u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10010654], 1 */
    { uint32_t t_ = R32((uint32_t)(0xcdc0ccu)); switch (t_) {  default: jump_indirect(c, t_, 0x00cd9741u); return; } } /* jmp dword ptr [0x1000c0cc] */
L_00cd9747:;
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if (!c->zf) goto L_00cd975b; /* jne 0xcd975b */
    c->eax = (uint32_t)(R32((uint32_t)(0xce069cu))); /* mov eax, dword ptr [0x1001069c] */
    W32((uint32_t)(0xce0654u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10010654], 1 */
L_00cd975b:;
    c->esp += 4; return; /* ret  */
}

void f_00cd975c(CPU *c) { /* FUN_1000975c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3a4u)); /* sub eax, 0x3a4 */
    if (c->zf) goto L_00cd9789; /* je 0xcd9789 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00cd9783; /* je 0xcd9783 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xdu)); /* sub eax, 0xd */
    if (c->zf) goto L_00cd977d; /* je 0xcd977d */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd9777; /* je 0xcd9777 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd9777:;
    c->eax = (uint32_t)((uint32_t)0x404u); /* mov eax, 0x404 */
    c->esp += 4; return; /* ret  */
L_00cd977d:;
    c->eax = (uint32_t)((uint32_t)0x412u); /* mov eax, 0x412 */
    c->esp += 4; return; /* ret  */
L_00cd9783:;
    c->eax = (uint32_t)((uint32_t)0x804u); /* mov eax, 0x804 */
    c->esp += 4; return; /* ret  */
L_00cd9789:;
    c->eax = (uint32_t)((uint32_t)0x411u); /* mov eax, 0x411 */
    c->esp += 4; return; /* ret  */
}

void f_00cd978f(CPU *c) { /* FUN_1000978f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xce0920u); /* mov edi, 0x10010920 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)0xce0800u); /* mov edi, 0x10010800 */
    W32((uint32_t)(0xce07f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100107f0], eax */
    W32((uint32_t)(0xce080cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001080c], eax */
    W32((uint32_t)(0xce0a24u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010a24], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd97b8(CPU *c) { /* FUN_100097b8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x514u)); /* sub esp, 0x514 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xce07f0u)); PUSH32(c, v_); } /* push dword ptr [0x100107f0] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0c8u)); PUSH32(c, 0x00cd97d2u); call_indirect(c, t_); } /* call dword ptr [0x1000c0c8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cd98f1; /* jne 0xcd98f1 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00cd97e2:;
    W8((uint32_t)(c->ebp + c->eax + 0xfffffeecu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + eax - 0x114], al */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd97e2; /* jb 0xcd97e2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff2u))); /* mov al, byte ptr [ebp - 0xe] */
    W8((uint32_t)(c->ebp + 0xfffffeecu), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x114], 0x20 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9833; /* je 0xcd9833 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff3u)); /* lea edx, [ebp - 0xd] */
L_00cd9801:;
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->edx))); /* movzx ecx, byte ptr [edx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((!c->cf && !c->zf)) goto L_00cd9828; /* ja 0xcd9828 */
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
L_00cd9828:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0xffffffffu))); /* mov al, byte ptr [edx - 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd9801; /* jne 0xcd9801 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00cd9833:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea eax, [ebp - 0x514] */
    { uint32_t v_ = R32((uint32_t)(0xce0a24u)); PUSH32(c, v_); } /* push dword ptr [0x10010a24] */
    { uint32_t v_ = R32((uint32_t)(0xce07f0u)); PUSH32(c, v_); } /* push dword ptr [0x100107f0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00cd9857u); f_00cd8b29(c); /* call 0xcd8b29 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdecu)); /* lea eax, [ebp - 0x214] */
    { uint32_t v_ = R32((uint32_t)(0xce07f0u)); PUSH32(c, v_); } /* push dword ptr [0x100107f0] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xce0a24u)); PUSH32(c, v_); } /* push dword ptr [0x10010a24] */
    PUSH32(c, 0x00cd987bu); f_00cda08d(c); /* call 0xcda08d */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffcecu)); /* lea eax, [ebp - 0x314] */
    { uint32_t v_ = R32((uint32_t)(0xce07f0u)); PUSH32(c, v_); } /* push dword ptr [0x100107f0] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffeecu)); /* lea eax, [ebp - 0x114] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = R32((uint32_t)(0xce0a24u)); PUSH32(c, v_); } /* push dword ptr [0x10010a24] */
    PUSH32(c, 0x00cd98a3u); f_00cda08d(c); /* call 0xcda08d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffaecu)); /* lea ecx, [ebp - 0x514] */
L_00cd98ae:;
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx))); /* mov dx, word ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x1u)); /* test dl, 1 */
    if (c->zf) goto L_00cd98cc; /* je 0xcd98cc */
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x10010921], 0x10 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffdecu))); /* mov dl, byte ptr [ebp + eax - 0x214] */
L_00cd98c4:;
    W8((uint32_t)(c->eax + 0xce0820u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax + 0x10010820], dl */
    goto L_00cd98e8; /* jmp 0xcd98e8 */
L_00cd98cc:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x2u)); /* test dl, 2 */
    if (c->zf) goto L_00cd98e1; /* je 0xcd98e1 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x10010921], 0x20 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + c->eax + 0xfffffcecu))); /* mov dl, byte ptr [ebp + eax - 0x314] */
    goto L_00cd98c4; /* jmp 0xcd98c4 */
L_00cd98e1:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0820u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x10010820], 0 */
L_00cd98e8:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd98ae; /* jb 0xcd98ae */
    goto L_00cd993a; /* jmp 0xcd993a */
L_00cd98f1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
L_00cd98f8:;
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if (c->cf) goto L_00cd9916; /* jb 0xcd9916 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->cf && !c->zf)) goto L_00cd9916; /* ja 0xcd9916 */
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x10u)))); } /* or byte ptr [eax + 0x10010921], 0x10 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
L_00cd990e:;
    W8((uint32_t)(c->eax + 0xce0820u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 0x10010820], cl */
    goto L_00cd9935; /* jmp 0xcd9935 */
L_00cd9916:;
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if (c->cf) goto L_00cd992e; /* jb 0xcd992e */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->cf && !c->zf)) goto L_00cd992e; /* ja 0xcd992e */
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0921u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x20u)))); } /* or byte ptr [eax + 0x10010921], 0x20 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(((uint8_t)c->eax)); /* mov cl, al */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* sub cl, 0x20 */
    goto L_00cd990e; /* jmp 0xcd990e */
L_00cd992e:;
    { uint32_t a_ = (uint32_t)(c->eax + 0xce0820u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 0x10010820], 0 */
L_00cd9935:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00cd98f8; /* jb 0xcd98f8 */
L_00cd993a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd993d(CPU *c) { /* FUN_1000993d */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xce0b68u)), (uint32_t)0x0u); /* cmp dword ptr [0x10010b68], 0 */
    if (!c->zf) goto L_00cd9958; /* jne 0xcd9958 */
    { uint32_t v_ = 0xfffffffdu; PUSH32(c, v_); } /* push -3 */
    PUSH32(c, 0x00cd994du); f_00cd9565(c); /* call 0xcd9565 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xce0b68u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10010b68], 1 */
L_00cd9958:;
    c->esp += 4; return; /* ret  */
}

void f_00cd9959(CPU *c) { /* FUN_10009959 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00cd996cu); f_00cd9970(c); /* call 0xcd9970 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00cd9970(CPU *c) { /* FUN_10009970 */
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
L_00cd9988:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd99a0; /* jle 0xcd99a0 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd999cu); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd99af; /* jmp 0xcd99af */
L_00cd99a0:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov ecx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_00cd99af:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd99b8; /* je 0xcd99b8 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00cd9988; /* jmp 0xcd9988 */
L_00cd99b8:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    if (!c->zf) goto L_00cd99c6; /* jne 0xcd99c6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp + 0x14], 2 */
    goto L_00cd99cb; /* jmp 0xcd99cb */
L_00cd99c6:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (!c->zf) goto L_00cd99d1; /* jne 0xcd99d1 */
L_00cd99cb:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov bl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00cd99d1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00cd9b65; /* jl 0xcd9b65 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cd9b65; /* je 0xcd9b65 */
    (void)sub32(c, c->eax, (uint32_t)0x24u); /* cmp eax, 0x24 */
    if ((!c->zf && c->sf == c->of)) goto L_00cd9b65; /* jg 0xcd9b65 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cd9a19; /* jne 0xcd9a19 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (c->zf) goto L_00cd9a03; /* je 0xcd9a03 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp + 0x10], 0xa */
    goto L_00cd9a35; /* jmp 0xcd9a35 */
L_00cd9a03:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00cd9a16; /* je 0xcd9a16 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (c->zf) goto L_00cd9a16; /* je 0xcd9a16 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x10], 8 */
    goto L_00cd9a35; /* jmp 0xcd9a35 */
L_00cd9a16:;
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
L_00cd9a19:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00cd9a35; /* jne 0xcd9a35 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00cd9a35; /* jne 0xcd9a35 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x78u); /* cmp al, 0x78 */
    if (c->zf) goto L_00cd9a2d; /* je 0xcd9a2d */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x58u); /* cmp al, 0x58 */
    if (!c->zf) goto L_00cd9a35; /* jne 0xcd9a35 */
L_00cd9a2d:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov bl, byte ptr [esi + 1] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_00cd9a35:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cd9a3au, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    c->edi = (uint32_t)((uint32_t)0x103u); /* mov edi, 0x103 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_00cd9a45:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    c->esi = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx esi, bl */
    if ((c->zf || c->sf != c->of)) goto L_00cd9a5d; /* jle 0xcd9a5d */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd9a59u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd9a68; /* jmp 0xcd9a68 */
L_00cd9a5d:;
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov eax, dword ptr [0x1000d2f4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00cd9a68:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd9a74; /* je 0xcd9a74 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x30u)); /* sub ecx, 0x30 */
    goto L_00cd9aa6; /* jmp 0xcd9aa6 */
L_00cd9a74:;
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00cd9a88; /* jle 0xcd9a88 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00cd9a84u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cd9a93; /* jmp 0xcd9a93 */
L_00cd9a88:;
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov eax, dword ptr [0x1000d2f4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + c->esi * 2))); /* mov ax, word ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->edi))); /* and eax, edi */
L_00cd9a93:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd9ae1; /* je 0xcd9ae1 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cd9aa0u); f_00cdaf40(c); /* call 0xcdaf40 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x37u)); /* sub ecx, 0x37 */
L_00cd9aa6:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x10u))); /* cmp ecx, dword ptr [ebp + 0x10] */
    if (!c->cf) goto L_00cd9ae1; /* jae 0xcd9ae1 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov esi, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp + 0x14], 8 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u))); /* cmp esi, dword ptr [ebp - 0xc] */
    if (c->cf) goto L_00cd9acb; /* jb 0xcd9acb */
    if (!c->zf) goto L_00cd9ac5; /* jne 0xcd9ac5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = R32((uint32_t)(c->ebp + 0x10u)); uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cd9abeu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div dword ptr [ebp + 0x10] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->cf || c->zf)) goto L_00cd9acb; /* jbe 0xcd9acb */
L_00cd9ac5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp + 0x14], 4 */
    goto L_00cd9ad4; /* jmp 0xcd9ad4 */
L_00cd9acb:;
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, c->ecx)); /* add esi, ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
L_00cd9ad4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    goto L_00cd9a45; /* jmp 0xcd9a45 */
L_00cd9ae1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00cd9afe; /* jne 0xcd9afe */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00cd9af8; /* je 0xcd9af8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00cd9af8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    goto L_00cd9b49; /* jmp 0xcd9b49 */
L_00cd9afe:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
    if (!c->zf) goto L_00cd9b22; /* jne 0xcd9b22 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (!c->zf) goto L_00cd9b49; /* jne 0xcd9b49 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
    if (c->zf) goto L_00cd9b19; /* je 0xcd9b19 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x80000000u); /* cmp dword ptr [ebp - 8], 0x80000000 */
    if ((!c->cf && !c->zf)) goto L_00cd9b22; /* ja 0xcd9b22 */
L_00cd9b19:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cd9b49; /* jne 0xcd9b49 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->esi); /* cmp dword ptr [ebp - 8], esi */
    if ((c->cf || c->zf)) goto L_00cd9b49; /* jbe 0xcd9b49 */
L_00cd9b22:;
    PUSH32(c, 0x00cd9b27u); f_00cdaf37(c); /* call 0xcdaf37 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x14], 1 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    if (c->zf) goto L_00cd9b39; /* je 0xcd9b39 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 8], 0xffffffff */
    goto L_00cd9b49; /* jmp 0xcd9b49 */
L_00cd9b39:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u))); /* and al, 2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(neg8(c, ((uint8_t)c->eax))); /* neg al */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00cd9b49:;
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00cd9b52; /* je 0xcd9b52 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
L_00cd9b52:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x14u)) & (uint8_t)0x2u)); /* test byte ptr [ebp + 0x14], 2 */
    if (c->zf) goto L_00cd9b60; /* je 0xcd9b60 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00cd9b60:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    goto L_00cd9b70; /* jmp 0xcd9b70 */
L_00cd9b65:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd9b6e; /* je 0xcd9b6e */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
L_00cd9b6e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd9b70:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd9b80(CPU *c) { /* PTR_00cd9b80 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd9b90(CPU *c) { /* _strchr */
    PREEMPT_POLL(c);
    goto L_00cd9b90;
L_00cd9b80:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9b90:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00cd9bbb; /* je 0xcd9bbb */
L_00cd9ba8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) goto L_00cd9b80; /* je 0xcd9b80 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00cd9c04; /* je 0xcd9c04 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00cd9ba8; /* jne 0xcd9ba8 */
L_00cd9bbb:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00cd9bc6:;
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
    if (!c->zf) goto L_00cd9c08; /* jne 0xcd9c08 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00cd9bc6; /* je 0xcd9bc6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00cd9c02; /* jne 0xcd9c02 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00cd9bc6; /* jne 0xcd9bc6 */
L_00cd9c02:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cd9c04:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd9c08:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00cd9c45; /* je 0xcd9c45 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00cd9c3e; /* je 0xcd9c3e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00cd9c37; /* je 0xcd9c37 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00cd9c30; /* je 0xcd9c30 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    goto L_00cd9bc6; /* jmp 0xcd9bc6 */
L_00cd9c30:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9c37:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9c3e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9c45:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd9b96(CPU *c) { /* PTR_00cd9b96 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_00cd9bbb; /* je 0xcd9bbb */
L_00cd9ba8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_00cd9b80(c); return; } /* je 0xcd9b80 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00cd9c04; /* je 0xcd9c04 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00cd9ba8; /* jne 0xcd9ba8 */
L_00cd9bbb:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_00cd9bc6:;
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
    if (!c->zf) goto L_00cd9c08; /* jne 0xcd9c08 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_00cd9bc6; /* je 0xcd9bc6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_00cd9c02; /* jne 0xcd9c02 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_00cd9bc6; /* jne 0xcd9bc6 */
L_00cd9c02:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cd9c04:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd9c08:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00cd9c45; /* je 0xcd9c45 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00cd9c3e; /* je 0xcd9c3e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00cd9c37; /* je 0xcd9c37 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_00cd9c30; /* je 0xcd9c30 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd9c02; /* je 0xcd9c02 */
    goto L_00cd9bc6; /* jmp 0xcd9bc6 */
L_00cd9c30:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9c37:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9c3e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9c45:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cd9c50(CPU *c) { /* _strstr */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd9cca; /* je 0xcd9cca */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00cd9cb7; /* je 0xcd9cb7 */
L_00cd9c68:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_00cd9c8a; /* je 0xcd9c8a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9c84; /* je 0xcd9c84 */
L_00cd9c79:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00cd9c7c:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_00cd9c8a; /* je 0xcd9c8a */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00cd9c79; /* jne 0xcd9c79 */
L_00cd9c84:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00cd9c8a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_00cd9c7c; /* jne 0xcd9c7c */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_00cd9c94:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00cd9cc3; /* je 0xcd9cc3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_00cd9c68; /* jne 0xcd9c68 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9cc3; /* je 0xcd9cc3 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_00cd9c94; /* je 0xcd9c94 */
    goto L_00cd9c68; /* jmp 0xcd9c68 */
L_00cd9cb7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_00cd9b96(c); return; } /* jmp 0xcd9b96 */
L_00cd9cc3:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd9cca:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd9cd0(CPU *c) { /* _strncmp */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    if (c->ecx == 0) goto L_00cd9d01; /* jecxz 0xcd9d01 */
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
    if ((!c->cf && !c->zf)) goto L_00cd9cff; /* ja 0xcd9cff */
    if (c->zf) goto L_00cd9d01; /* je 0xcd9d01 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_00cd9cff:;
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
L_00cd9d01:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cd9d10(CPU *c) { /* FUN_10009d10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_00cd9d30; /* jb 0xcd9d30 */
L_00cd9d1c:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_00cd9d1c; /* jae 0xcd9d1c */
L_00cd9d30:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_00cd9d3f(CPU *c) { /* FUN_10009d3f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xce0658u)), c->ebx); /* cmp dword ptr [0x10010658], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cd9d8e; /* jne 0xcd9d8e */
    { uint32_t v_ = 0xcdc71cu; PUSH32(c, v_); } /* push 0x1000c71c */
    { uint32_t t_ = R32((uint32_t)(0xcdc0d4u)); PUSH32(c, 0x00cd9d57u); call_indirect(c, t_); } /* call dword ptr [0x1000c0d4] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00cd9dc4; /* je 0xcd9dc4 */
    c->esi = (uint32_t)(R32((uint32_t)(0xcdc02cu))); /* mov esi, dword ptr [0x1000c02c] */
    { uint32_t v_ = 0xcdc710u; PUSH32(c, v_); } /* push 0x1000c710 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd9d6bu); call_indirect(c, t_); } /* call esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xce0658u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010658], eax */
    if (c->zf) goto L_00cd9dc4; /* je 0xcd9dc4 */
    { uint32_t v_ = 0xcdc700u; PUSH32(c, v_); } /* push 0x1000c700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd9d7cu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = 0xcdc6ecu; PUSH32(c, v_); } /* push 0x1000c6ec */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0xce065cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001065c], eax */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00cd9d89u); call_indirect(c, t_); } /* call esi */
    W32((uint32_t)(0xce0660u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010660], eax */
L_00cd9d8e:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce065cu))); /* mov eax, dword ptr [0x1001065c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd9dad; /* je 0xcd9dad */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd9d99u); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00cd9dad; /* je 0xcd9dad */
    c->eax = (uint32_t)(R32((uint32_t)(0xce0660u))); /* mov eax, dword ptr [0x10010660] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cd9dad; /* je 0xcd9dad */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00cd9dabu); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00cd9dad:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xce0658u)); PUSH32(c, 0x00cd9dc0u); call_indirect(c, t_); } /* call dword ptr [0x10010658] */
L_00cd9dc0:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cd9dc4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cd9dc0; /* jmp 0xcd9dc0 */
}

void f_00cd9dd0(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00cd9e53; /* je 0xcd9e53 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00cd9df4; /* jne 0xcd9df4 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00cd9e61; /* jne 0xcd9e61 */
    goto L_00cd9e15; /* jmp 0xcd9e15 */
L_00cd9df4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cd9e22; /* je 0xcd9e22 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9e2a; /* je 0xcd9e2a */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00cd9df4; /* jne 0xcd9df4 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00cd9e61; /* jne 0xcd9e61 */
L_00cd9e10:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_00cd9e22; /* je 0xcd9e22 */
L_00cd9e15:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00cd9e4e; /* je 0xcd9e4e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00cd9e15; /* jne 0xcd9e15 */
L_00cd9e22:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd9e2a:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_00cd9e44; /* je 0xcd9e44 */
L_00cd9e32:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cd9ec6; /* je 0xcd9ec6 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00cd9e32; /* jne 0xcd9e32 */
L_00cd9e44:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00cd9eb7; /* jne 0xcd9eb7 */
L_00cd9e4b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00cd9e4e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00cd9e4b; /* jne 0xcd9e4b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cd9e53:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00cd9e59:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cd9e10; /* je 0xcd9e10 */
L_00cd9e61:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00cd9e59; /* je 0xcd9e59 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00cd9eab; /* je 0xcd9eab */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00cd9ea1; /* je 0xcd9ea1 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00cd9e97; /* je 0xcd9e97 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_00cd9e59; /* jne 0xcd9e59 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00cd9eaf; /* jmp 0xcd9eaf */
L_00cd9e97:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00cd9eaf; /* jmp 0xcd9eaf */
L_00cd9ea1:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_00cd9eaf; /* jmp 0xcd9eaf */
L_00cd9eab:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_00cd9eaf:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cd9ec1; /* je 0xcd9ec1 */
L_00cd9eb7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cd9eb9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00cd9eb9; /* jne 0xcd9eb9 */
L_00cd9ec1:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_00cd9e4b; /* jne 0xcd9e4b */
L_00cd9ec6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00cd9ece(CPU *c) { /* FUN_10009ece */
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
    if (c->zf) goto L_00cd9f49; /* je 0xcd9f49 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd9f2c; /* je 0xcd9f2c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00cd9f2c; /* je 0xcd9f2c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00cd9f2c; /* je 0xcd9f2c */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00cd9f1f; /* je 0xcd9f1f */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_00cd9f12; /* je 0xcd9f12 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00cd9f05; /* je 0xcd9f05 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00cda04b; /* jmp 0xcda04b */
L_00cd9f05:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xce066cu))); /* mov ebx, dword ptr [0x1001066c] */
    c->edi = (uint32_t)((uint32_t)0xce066cu); /* mov edi, 0x1001066c */
    goto L_00cd9f54; /* jmp 0xcd9f54 */
L_00cd9f12:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xce0668u))); /* mov ebx, dword ptr [0x10010668] */
    c->edi = (uint32_t)((uint32_t)0xce0668u); /* mov edi, 0x10010668 */
    goto L_00cd9f54; /* jmp 0xcd9f54 */
L_00cd9f1f:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xce0670u))); /* mov ebx, dword ptr [0x10010670] */
    c->edi = (uint32_t)((uint32_t)0xce0670u); /* mov edi, 0x10010670 */
    goto L_00cd9f54; /* jmp 0xcd9f54 */
L_00cd9f2c:;
    PUSH32(c, 0x00cd9f31u); f_00cd3480(c); /* call 0xcd3480 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x50u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x50] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cd9f3eu); f_00cda050(c); /* call 0xcda050 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    goto L_00cd9f66; /* jmp 0xcd9f66 */
L_00cd9f49:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xce0664u))); /* mov ebx, dword ptr [0x10010664] */
    c->edi = (uint32_t)((uint32_t)0xce0664u); /* mov edi, 0x10010664 */
L_00cd9f54:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00cd9f62u); f_00cd3abb(c); /* call 0xcd3abb */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd9f66:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (!c->zf) goto L_00cd9f81; /* jne 0xcd9f81 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00cda049; /* je 0xcda049 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cd9f7bu); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cda049; /* jmp 0xcda049 */
L_00cd9f81:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (!c->zf) goto L_00cd9f9b; /* jne 0xcd9f9b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ecx); /* cmp dword ptr [ebp - 4], ecx */
    if (c->zf) goto L_00cd9f94; /* je 0xcd9f94 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00cd9f93u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cd9f94:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00cd9f9bu); f_00cd4778(c); /* call 0xcd4778 */
L_00cd9f9b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (c->zf) goto L_00cd9fad; /* je 0xcd9fad */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if (c->zf) goto L_00cd9fad; /* je 0xcd9fad */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_00cd9fc8; /* jne 0xcd9fc8 */
L_00cd9fad:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if (!c->zf) goto L_00cda004; /* jne 0xcda004 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [esi + 0x58], 0x8c */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_00cd9fc8:;
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (!c->zf) goto L_00cda004; /* jne 0xcda004 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd7d0u))); /* mov ecx, dword ptr [0x1000d7d0] */
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd7d4u))); /* mov eax, dword ptr [0x1000d7d4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00cda006; /* jge 0xcda006 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
L_00cd9fe4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx + eax - 4], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0xcdd7d0u))); /* mov edx, dword ptr [0x1000d7d0] */
    c->edi = (uint32_t)(R32((uint32_t)(0xcdd7d4u))); /* mov edi, dword ptr [0x1000d7d4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if ((c->sf != c->of)) goto L_00cd9fe4; /* jl 0xcd9fe4 */
    goto L_00cda006; /* jmp 0xcda006 */
L_00cda004:;
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
L_00cda006:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00cda014; /* je 0xcda014 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00cda013u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cda014:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    if (!c->zf) goto L_00cda025; /* jne 0xcda025 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x58] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00cda021u); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cda037; /* jmp 0xcda037 */
L_00cda025:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00cda02au); call_indirect(c, t_); } /* call ebx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0xbu); /* cmp dword ptr [ebp + 8], 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00cda037; /* je 0xcda037 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x4u); /* cmp dword ptr [ebp + 8], 4 */
    if (!c->zf) goto L_00cda049; /* jne 0xcda049 */
L_00cda037:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if (!c->zf) goto L_00cda049; /* jne 0xcda049 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_00cda049:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cda04b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cda050(CPU *c) { /* FUN_1000a050 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xcdd7dcu))); /* mov ecx, dword ptr [0x1000d7dc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    if (c->zf) goto L_00cda079; /* je 0xcda079 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edi, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->edi * 4)); /* lea edi, [edx + edi*4] */
L_00cda06d:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_00cda079; /* jae 0xcda079 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (!c->zf) goto L_00cda06d; /* jne 0xcda06d */
L_00cda079:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea ecx, [edx + ecx*4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00cda088; /* jae 0xcda088 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (c->zf) goto L_00cda08a; /* je 0xcda08a */
L_00cda088:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cda08a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cda08d(CPU *c) { /* FUN_1000a08d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xcdc728u; PUSH32(c, v_); } /* push 0x1000c728 */
    { uint32_t v_ = 0xcd4dc8u; PUSH32(c, v_); } /* push 0x10004dc8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0xce06a4u)), c->edi); /* cmp dword ptr [0x100106a4], edi */
    if (!c->zf) goto L_00cda103; /* jne 0xcda103 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xcdc6dcu; PUSH32(c, v_); } /* push 0x1000c6dc */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda0d5u); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda0e1; /* je 0xcda0e1 */
    W32((uint32_t)(0xce06a4u), (uint32_t)(c->ebx)); /* mov dword ptr [0x100106a4], ebx */
    goto L_00cda103; /* jmp 0xcda103 */
L_00cda0e1:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0xcdc6d8u; PUSH32(c, v_); } /* push 0x1000c6d8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0d8u)); PUSH32(c, 0x00cda0f1u); call_indirect(c, t_); } /* call dword ptr [0x1000c0d8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    W32((uint32_t)(0xce06a4u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x100106a4], 2 */
L_00cda103:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->edi); /* cmp dword ptr [ebp + 0x14], edi */
    if ((c->zf || c->sf != c->of)) goto L_00cda118; /* jle 0xcda118 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00cda113u); f_00cda2b1(c); /* call 0xcda2b1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_00cda118:;
    c->eax = (uint32_t)(R32((uint32_t)(0xce06a4u))); /* mov eax, dword ptr [0x100106a4] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00cda13f; /* jne 0xcda13f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0d8u)); PUSH32(c, 0x00cda13au); call_indirect(c, t_); } /* call dword ptr [0x1000c0d8] */
    goto L_00cda21d; /* jmp 0xcda21d */
L_00cda13f:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cda21b; /* jne 0xcda21b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), c->edi); /* cmp dword ptr [ebp + 0x20], edi */
    if (!c->zf) goto L_00cda155; /* jne 0xcda155 */
    c->eax = (uint32_t)(R32((uint32_t)(0xce069cu))); /* mov eax, dword ptr [0x1001069c] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
L_00cda155:;
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
    { uint32_t t_ = R32((uint32_t)(0xcdc0bcu)); PUSH32(c, 0x00cda172u); call_indirect(c, t_); } /* call dword ptr [0x1000c0bc] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x1c], ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea eax, [ebx + ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00cda18fu); f_00cd9d10(c); /* call 0xcd9d10 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00cda1b0; /* jmp 0xcda1b0 */
L_00cda1b0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0bcu)); PUSH32(c, 0x00cda1cau); call_indirect(c, t_); } /* call dword ptr [0x1000c0bc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda1e0u); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00cda22f; /* je 0xcda22f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00cda2aa; /* je 0xcda2aa */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00cda21b; /* jg 0xcda21b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda213u); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cda2aa; /* jne 0xcda2aa */
L_00cda21b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cda21d:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cda22f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00cda243u); f_00cd9d10(c); /* call 0xcd9d10 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00cda263; /* jmp 0xcda263 */
L_00cda263:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda27bu); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cda28a; /* jne 0xcda28a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00cda290; /* jmp 0xcda290 */
L_00cda28a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00cda290:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xcdc080u)); PUSH32(c, 0x00cda2a0u); call_indirect(c, t_); } /* call dword ptr [0x1000c080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
L_00cda2aa:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cda21d; /* jmp 0xcda21d */
}

void f_00cda19d(CPU *c) { /* PTR_00cda19d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cda1a1(CPU *c) { /* PTR_00cda1a1 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ebx, dword ptr [ebp - 0x1c] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0bcu)); PUSH32(c, 0x00cda1cau); call_indirect(c, t_); } /* call dword ptr [0x1000c0bc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda1e0u); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00cda22f; /* je 0xcda22f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00cda2aa; /* je 0xcda2aa */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00cda21b; /* jg 0xcda21b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda213u); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cda2aa; /* jne 0xcda2aa */
L_00cda21b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cda21d:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cda22f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00cda243u); f_00cd9d10(c); /* call 0xcd9d10 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00cda263; /* jmp 0xcda263 */
L_00cda263:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda27bu); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cda28a; /* jne 0xcda28a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00cda290; /* jmp 0xcda290 */
L_00cda28a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00cda290:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xcdc080u)); PUSH32(c, 0x00cda2a0u); call_indirect(c, t_); } /* call dword ptr [0x1000c080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00cda21b; /* je 0xcda21b */
L_00cda2aa:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00cda21d; /* jmp 0xcda21d */
}

void f_00cda21b(CPU *c) { /* PTR_00cda21b */
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

void f_00cda251(CPU *c) { /* PTR_00cda251 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00cda255(CPU *c) { /* PTR_00cda255 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) { f_00cda21b(c); return; } /* je 0xcda21b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xcdc0dcu)); PUSH32(c, 0x00cda27bu); call_indirect(c, t_); } /* call dword ptr [0x1000c0dc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00cda21b(c); return; } /* je 0xcda21b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00cda28a; /* jne 0xcda28a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00cda290; /* jmp 0xcda290 */
L_00cda28a:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00cda290:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xcdc080u)); PUSH32(c, 0x00cda2a0u); call_indirect(c, t_); } /* call dword ptr [0x1000c080] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) { f_00cda21b(c); return; } /* je 0xcda21b */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { jump_indirect(c, 0x00cda21du, 0x00cda2acu); return; } /* jmp 0xcda21d */
}

void f_00cda2b1(CPU *c) { /* FUN_1000a2b1 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea ecx, [edx - 1] */
    if (c->zf) goto L_00cda2ce; /* je 0xcda2ce */
L_00cda2c1:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00cda2ce; /* je 0xcda2ce */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00cda2c1; /* jne 0xcda2c1 */
L_00cda2ce:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_00cda2d9; /* jne 0xcda2d9 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
L_00cda2d9:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esp += 4; return; /* ret  */
}

void f_00cda2dc(CPU *c) { /* FUN_1000a2dc */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->esi)); /* lea ecx, [edx + esi] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->cf) goto L_00cda2f2; /* jb 0xcda2f2 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (!c->cf) goto L_00cda2f5; /* jae 0xcda2f5 */
L_00cda2f2:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00cda2f5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00cda2fd(CPU *c) { /* ___add_12 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00cda311u); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda32f; /* je 0xcda32f */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00cda325u); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda32f; /* je 0xcda32f */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00cda32f:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea eax, [esi + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [edi + 4] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00cda33du); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda347; /* je 0xcda347 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [esi + 8] */
L_00cda347:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x00cda355u); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00cda35b(CPU *c) { /* FUN_1000a35b */
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

void f_00cda389(CPU *c) { /* FUN_1000a389 */
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

void f_00cda3b6(CPU *c) { /* FUN_1000a3b6 */
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
    if ((c->cf || c->zf)) goto L_00cda42a; /* jbe 0xcda42a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
L_00cda3dd:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea edi, [ebp - 0x10] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00cda3ebu); f_00cda35b(c); /* call 0xcda35b */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cda3f1u); f_00cda35b(c); /* call 0xcda35b */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cda3fbu); f_00cda2fd(c); /* call 0xcda2fd */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cda401u); f_00cda35b(c); /* call 0xcda35b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx eax, byte ptr [eax] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cda41cu); f_00cda2fd(c); /* call 0xcda2fd */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_00cda3dd; /* jne 0xcda3dd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cda42a:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x8u)), c->edx); /* cmp dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00cda457; /* jne 0xcda457 */
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
    goto L_00cda42a; /* jmp 0xcda42a */
L_00cda457:;
    c->esi = (uint32_t)((uint32_t)0x8000u); /* mov esi, 0x8000 */
L_00cda45c:;
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->esi)); /* test dword ptr [ebx + 8], esi */
    if (!c->zf) goto L_00cda471; /* jne 0xcda471 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cda467u); f_00cda35b(c); /* call 0xcda35b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp - 4], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cda45c; /* jmp 0xcda45c */
L_00cda471:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ax, word ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W16((uint32_t)(c->ebx + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebx + 0xa], ax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cda47d(CPU *c) { /* FUN_1000a47d */
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
    if (c->zf) goto L_00cda4df; /* je 0xcda4df */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx + 2], 0x2d */
    goto L_00cda4e3; /* jmp 0xcda4e3 */
L_00cda4df:;
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
L_00cda4e3:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    if (!c->zf) goto L_00cda509; /* jne 0xcda509 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00cda509; /* jne 0xcda509 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (!c->zf) goto L_00cda509; /* jne 0xcda509 */
L_00cda4f4:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ebx + 0x4u), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebx + 4], 0x30 */
    goto L_00cda707; /* jmp 0xcda707 */
L_00cda509:;
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->esi)); /* cmp dx, si */
    if (!c->zf) goto L_00cda588; /* jne 0xcda588 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    W16((uint32_t)(c->ebx), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [ebx], 1 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00cda522; /* jne 0xcda522 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00cda531; /* je 0xcda531 */
L_00cda522:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x40000000u)); /* test edi, 0x40000000 */
    if (!c->zf) goto L_00cda531; /* jne 0xcda531 */
    { uint32_t v_ = 0xcdc758u; PUSH32(c, v_); } /* push 0x1000c758 */
    goto L_00cda577; /* jmp 0xcda577 */
L_00cda531:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->ecx) & ((uint16_t)c->ecx))); /* test cx, cx */
    if (c->zf) goto L_00cda54b; /* je 0xcda54b */
    (void)sub32(c, c->edi, (uint32_t)0xc0000000u); /* cmp edi, 0xc0000000 */
    if (!c->zf) goto L_00cda54b; /* jne 0xcda54b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00cda572; /* jne 0xcda572 */
    { uint32_t v_ = 0xcdc750u; PUSH32(c, v_); } /* push 0x1000c750 */
    goto L_00cda55a; /* jmp 0xcda55a */
L_00cda54b:;
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00cda572; /* jne 0xcda572 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00cda572; /* jne 0xcda572 */
    { uint32_t v_ = 0xcdc748u; PUSH32(c, v_); } /* push 0x1000c748 */
L_00cda55a:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda563u); f_00cd7420(c); /* call 0xcd7420 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [ebx + 3], 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cda569:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    goto L_00cda6e0; /* jmp 0xcda6e0 */
L_00cda572:;
    { uint32_t v_ = 0xcdc740u; PUSH32(c, v_); } /* push 0x1000c740 */
L_00cda577:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda580u); f_00cd7420(c); /* call 0xcd7420 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [ebx + 3], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cda569; /* jmp 0xcda569 */
L_00cda588:;
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
    PUSH32(c, 0x00cda5ceu); f_00cda930(c); /* call 0xcda930 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xfffffffau)), (uint16_t)0x3fffu); /* cmp word ptr [ebp - 6], 0x3fff */
    if (c->cf) goto L_00cda5e9; /* jb 0xcda5e9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda5e7u); f_00cda710(c); /* call 0xcda710 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cda5e9:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x18u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x18], 1 */
    W16((uint32_t)(c->ebx), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [ebx], si */
    if (c->zf) goto L_00cda603; /* je 0xcda603 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->esi)); /* movsx eax, si */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((!c->zf && c->sf == c->of)) goto L_00cda606; /* jg 0xcda606 */
    goto L_00cda4f4; /* jmp 0xcda4f4 */
L_00cda603:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
L_00cda606:;
    (void)sub32(c, c->edi, (uint32_t)0x15u); /* cmp edi, 0x15 */
    if ((c->zf || c->sf != c->of)) goto L_00cda60e; /* jle 0xcda60e */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00cda60e:;
    c->esi = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xfffffffau))); /* movzx esi, word ptr [ebp - 6] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3ffeu)); /* sub esi, 0x3ffe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffau); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebp - 6], 0 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x1c], 8 */
L_00cda624:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda62du); f_00cda35b(c); /* call 0xcda35b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cda624; /* jne 0xcda624 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00cda64e; /* jge 0xcda64e */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffu))); /* and esi, 0xff */
    if ((c->zf || c->sf != c->of)) goto L_00cda64e; /* jle 0xcda64e */
L_00cda641:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda64au); f_00cda389(c); /* call 0xcda389 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cda641; /* jne 0xcda641 */
L_00cda64e:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea ecx, [edi + 1] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
    if ((c->zf || c->sf != c->of)) goto L_00cda6ab; /* jle 0xcda6ab */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x14], ecx */
L_00cda65e:;
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea esi, [ebp - 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea edi, [ebp + 8] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00cda670u); f_00cda35b(c); /* call 0xcda35b */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda679u); f_00cda35b(c); /* call 0xcda35b */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda686u); f_00cda2fd(c); /* call 0xcda2fd */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda68fu); f_00cda35b(c); /* call 0xcda35b */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffbu))); /* mov al, byte ptr [ebp - 5] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffbu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 5], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x30u)); /* add al, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x14] */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    if (!c->zf) goto L_00cda65e; /* jne 0xcda65e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
L_00cda6ab:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xffffffffu))); /* mov cl, byte ptr [eax - 1] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x35u); /* cmp cl, 0x35 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ecx, [ebx + 4] */
    if ((c->sf != c->of)) goto L_00cda6e8; /* jl 0xcda6e8 */
L_00cda6b8:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00cda6cb; /* jb 0xcda6cb */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00cda6c7; /* jne 0xcda6c7 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00cda6b8; /* jmp 0xcda6b8 */
L_00cda6c7:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00cda6cf; /* jae 0xcda6cf */
L_00cda6cb:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebx] */
L_00cda6cf:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00cda6d1:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx))); /* sub al, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x3u)); /* sub al, 3 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebx + 3], al */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ebx + 4], 0 */
L_00cda6e0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00cda6e3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00cda6e8:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00cda6f8; /* jb 0xcda6f8 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (!c->zf) goto L_00cda6f4; /* jne 0xcda6f4 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00cda6e8; /* jmp 0xcda6e8 */
L_00cda6f4:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00cda6d1; /* jae 0xcda6d1 */
L_00cda6f8:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00cda707:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x5u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebx + 5], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cda6e3; /* jmp 0xcda6e3 */
}

void f_00cda710(CPU *c) { /* FUN_1000a710 */
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
    if (!c->cf) goto L_00cda910; /* jae 0xcda910 */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7fffu); /* cmp cx, 0x7fff */
    if (!c->cf) goto L_00cda910; /* jae 0xcda910 */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xbffdu); /* cmp dx, 0xbffd */
    if ((!c->cf && !c->zf)) goto L_00cda910; /* ja 0xcda910 */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x3fbfu); /* cmp dx, 0x3fbf */
    if ((!c->cf && !c->zf)) goto L_00cda779; /* ja 0xcda779 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00cda7b3; /* jmp 0xcda7b3 */
L_00cda779:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    c->edx = (uint32_t)((uint32_t)0x7fffffffu); /* mov edx, 0x7fffffff */
    if (!c->zf) goto L_00cda79b; /* jne 0xcda79b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + 0x8u)) & c->edx)); /* test dword ptr [esi + 8], edx */
    if (!c->zf) goto L_00cda79b; /* jne 0xcda79b */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), c->eax); /* cmp dword ptr [esi + 4], eax */
    if (!c->zf) goto L_00cda79d; /* jne 0xcda79d */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_00cda79d; /* jne 0xcda79d */
    goto L_00cda90a; /* jmp 0xcda90a */
L_00cda79b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cda79d:;
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_00cda7c0; /* jne 0xcda7c0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->edx)); /* test dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00cda7c0; /* jne 0xcda7c0 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x4u)), c->eax); /* cmp dword ptr [ebx + 4], eax */
    if (!c->zf) goto L_00cda7c0; /* jne 0xcda7c0 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (!c->zf) goto L_00cda7c0; /* jne 0xcda7c0 */
L_00cda7b3:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00cda92b; /* jmp 0xcda92b */
L_00cda7c0:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [ebp + 0xc], 5 */
L_00cda7d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00cda824; /* jle 0xcda824 */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea ecx, [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
L_00cda7ec:;
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
    PUSH32(c, 0x00cda80au); f_00cda2dc(c); /* call 0xcda2dc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cda817; /* je 0xcda817 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [eax] */
L_00cda817:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 8], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x2u))); } /* sub dword ptr [ebp - 0xc], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_00cda7ec; /* jne 0xcda7ec */
L_00cda824:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 4], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cda7d0; /* jg 0xcda7d0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xc002u))); } /* add dword ptr [ebp + 8], 0xc002 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00cda867; /* jle 0xcda867 */
L_00cda842:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffe7u)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 0x19], 0x80 */
    if (!c->zf) goto L_00cda860; /* jne 0xcda860 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda851u); f_00cda35b(c); /* call 0xcda35b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cda842; /* jg 0xcda842 */
L_00cda860:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cda8a0; /* jg 0xcda8a0 */
L_00cda867:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->sf == c->of)) goto L_00cda8a0; /* jge 0xcda8a0 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0x8u))); /* movsx eax, word ptr [ebp + 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00cda880:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffdcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x24], 1 */
    if (c->zf) goto L_00cda889; /* je 0xcda889 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x14] */
L_00cda889:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cda892u); f_00cda389(c); /* call 0xcda389 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00cda880; /* jne 0xcda880 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_00cda8a0; /* je 0xcda8a0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x24], 1 */
L_00cda8a0:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffdcu)), (uint16_t)0x8000u); /* cmp word ptr [ebp - 0x24], 0x8000 */
    if ((!c->cf && !c->zf)) goto L_00cda8b7; /* ja 0xcda8b7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1ffffu))); /* and eax, 0x1ffff */
    (void)sub32(c, c->eax, (uint32_t)0x18000u); /* cmp eax, 0x18000 */
    if (!c->zf) goto L_00cda8ec; /* jne 0xcda8ec */
L_00cda8b7:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdeu)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x22], -1 */
    if (!c->zf) goto L_00cda8e9; /* jne 0xcda8e9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x22], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe2u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x1e], -1 */
    if (!c->zf) goto L_00cda8e4; /* jne 0xcda8e4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1e], 0 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffe6u)), (uint16_t)0xffffu); /* cmp word ptr [ebp - 0x1a], 0xffff */
    if (!c->zf) goto L_00cda8de; /* jne 0xcda8de */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    W16((uint32_t)(c->ebp + 0xffffffe6u), (uint16_t)((uint16_t)0x8000u)); /* mov word ptr [ebp - 0x1a], 0x8000 */
    goto L_00cda8ec; /* jmp 0xcda8ec */
L_00cda8de:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe6u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebp - 0x1a] */
    goto L_00cda8ec; /* jmp 0xcda8ec */
L_00cda8e4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1e] */
    goto L_00cda8ec; /* jmp 0xcda8ec */
L_00cda8e9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x22] */
L_00cda8ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    if (!c->cf) goto L_00cda910; /* jae 0xcda910 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffdeu))); /* mov cx, word ptr [ebp - 0x22] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [esi], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->esi + 0x2u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 2], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->esi + 0x6u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 6], ecx */
L_00cda90a:;
    W16((uint32_t)(c->esi + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xa], ax */
    goto L_00cda92b; /* jmp 0xcda92b */
L_00cda910:;
    c->edi = (c->edi & 0xffff0000u) | (uint16_t)(neg16(c, ((uint16_t)c->edi))); /* neg di */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edi)); /* sbb edi, edi */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x80000000u))); /* and edi, 0x80000000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7fff8000u)); /* add edi, 0x7fff8000 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
L_00cda92b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cda930(CPU *c) { /* FUN_1000a930 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)0xcdfcb0u); /* mov ebx, 0x1000fcb0 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00cda9a9; /* je 0xcda9a9 */
    if ((c->sf == c->of)) goto L_00cda958; /* jge 0xcda958 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0xcdfe10u); /* mov ebx, 0x1000fe10 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
L_00cda958:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00cda963; /* jne 0xcda963 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
L_00cda963:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00cda9a9; /* je 0xcda9a9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00cda96a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x54u)); /* add ebx, 0x54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sar32(c, R32(a_), 3))); } /* sar dword ptr [ebp + 0xc], 3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00cda9a2; /* je 0xcda9a2 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)sub16(c, R16((uint32_t)(c->ebx + c->eax * 4)), (uint16_t)0x8000u); /* cmp word ptr [ebx + eax*4], 0x8000 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea esi, [ebx + eax*4] */
    if (c->cf) goto L_00cda995; /* jb 0xcda995 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff6u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xa] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
L_00cda995:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00cda99eu); f_00cda710(c); /* call 0xcda710 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00cda9a2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_00cda96a; /* jne 0xcda96a */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cda9a9:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cda9ac(CPU *c) { /* FUN_1000a9ac */
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
    if (c->zf) goto L_00cda9de; /* je 0xcda9de */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008fu)); /* mov dword ptr [ebp + 0x10], 0xc000008f */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 4], ebx */
L_00cda9de:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_00cda9f1; /* je 0xcda9f1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000093u)); /* mov dword ptr [ebp + 0x10], 0xc0000093 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [eax + 4], 2 */
L_00cda9f1:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ecx))); /* test bl, cl */
    if (c->zf) goto L_00cdaa03; /* je 0xcdaa03 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000091u)); /* mov dword ptr [ebp + 0x10], 0xc0000091 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [eax + 4], 4 */
L_00cdaa03:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_00cdaa16; /* je 0xcdaa16 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008eu)); /* mov dword ptr [ebp + 0x10], 0xc000008e */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [eax + 4], 8 */
L_00cdaa16:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00cdaa29; /* je 0xcdaa29 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000090u)); /* mov dword ptr [ebp + 0x10], 0xc0000090 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [eax + 4], 0x10 */
L_00cdaa29:;
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
    PUSH32(c, 0x00cdaaa7u); f_00cdaea1(c); /* call 0xcdaea1 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00cdaab2; /* je 0xcdaab2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ecx + 0xc], 0x10 */
L_00cdaab2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00cdaabd; /* je 0xcdaabd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ecx + 0xc], 8 */
L_00cdaabd:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_00cdaac8; /* je 0xcdaac8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ecx + 0xc], 4 */
L_00cdaac8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00cdaad2; /* je 0xcdaad2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 0xc], edi */
L_00cdaad2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x20u)); /* test al, 0x20 */
    if (c->zf) goto L_00cdaadc; /* je 0xcdaadc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 0xc], ebx */
L_00cdaadc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0xc00u); /* mov ecx, 0xc00 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00cdab1b; /* je 0xcdab1b */
    (void)sub32(c, c->eax, (uint32_t)0x400u); /* cmp eax, 0x400 */
    if (c->zf) goto L_00cdab0d; /* je 0xcdab0d */
    (void)sub32(c, c->eax, (uint32_t)0x800u); /* cmp eax, 0x800 */
    if (c->zf) goto L_00cdab01; /* je 0xcdab01 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00cdab21; /* jne 0xcdab21 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x3u)))); } /* or dword ptr [eax], 3 */
    goto L_00cdab21; /* jmp 0xcdab21 */
L_00cdab01:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffeu))); /* and ecx, 0xfffffffe */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    goto L_00cdab17; /* jmp 0xcdab17 */
L_00cdab0d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffdu))); /* and ecx, 0xfffffffd */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
L_00cdab17:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    goto L_00cdab21; /* jmp 0xcdab21 */
L_00cdab1b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffcu)))); } /* and dword ptr [eax], 0xfffffffc */
L_00cdab21:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0x300u); /* mov ecx, 0x300 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00cdab4c; /* je 0xcdab4c */
    (void)sub32(c, c->eax, (uint32_t)0x200u); /* cmp eax, 0x200 */
    if (c->zf) goto L_00cdab3f; /* je 0xcdab3f */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00cdab59; /* jne 0xcdab59 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffe3u)))); } /* and dword ptr [eax], 0xffffffe3 */
    goto L_00cdab59; /* jmp 0xcdab59 */
L_00cdab3f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe7u))); /* and ecx, 0xffffffe7 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x4u))); /* or ecx, 4 */
    goto L_00cdab57; /* jmp 0xcdab57 */
L_00cdab4c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffebu))); /* and ecx, 0xffffffeb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x8u))); /* or ecx, 8 */
L_00cdab57:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00cdab59:;
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
    PUSH32(c, 0x00cdabb7u); f_00cdaeaf(c); /* call 0xcdaeaf */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xcdc004u)); PUSH32(c, 0x00cdabc7u); call_indirect(c, t_); } /* call dword ptr [0x1000c004] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [eax + 8], 0x10 */
    if (c->zf) goto L_00cdabd3; /* je 0xcdabd3 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [esi], 0xfffffffe */
L_00cdabd3:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x8u)); /* test byte ptr [eax + 8], 8 */
    if (c->zf) goto L_00cdabdc; /* je 0xcdabdc */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffbu)))); } /* and dword ptr [esi], 0xfffffffb */
L_00cdabdc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x4u)); /* test byte ptr [eax + 8], 4 */
    if (c->zf) goto L_00cdabe5; /* je 0xcdabe5 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [esi], 0xfffffff7 */
L_00cdabe5:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x2u)); /* test byte ptr [eax + 8], 2 */
    if (c->zf) goto L_00cdabee; /* je 0xcdabee */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffefu)))); } /* and dword ptr [esi], 0xffffffef */
L_00cdabee:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & ((uint8_t)c->ebx))); /* test byte ptr [eax + 8], bl */
    if (c->zf) goto L_00cdabf6; /* je 0xcdabf6 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffdfu)))); } /* and dword ptr [esi], 0xffffffdf */
L_00cdabf6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)0xfffff3ffu); /* mov edx, 0xfffff3ff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00cdac2a; /* je 0xcdac2a */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cdac1e; /* je 0xcdac1e */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cdac14; /* je 0xcdac14 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00cdac2c; /* jne 0xcdac2c */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xcu)))); } /* or byte ptr [esi + 1], 0xc */
    goto L_00cdac2c; /* jmp 0xcdac2c */
L_00cdac14:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xfbu))) << 8); /* and ch, 0xfb */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x8u))) << 8); /* or ch, 8 */
    goto L_00cdac26; /* jmp 0xcdac26 */
L_00cdac1e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xf7u))) << 8); /* and ch, 0xf7 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x4u))) << 8); /* or ch, 4 */
L_00cdac26:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    goto L_00cdac2c; /* jmp 0xcdac2c */
L_00cdac2a:;
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
L_00cdac2c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7u))); /* and ecx, 7 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00cdac4c; /* je 0xcdac4c */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00cdac43; /* je 0xcdac43 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00cdac55; /* jne 0xcdac55 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
    goto L_00cdac55; /* jmp 0xcdac55 */
L_00cdac43:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x2u))) << 8); /* or ch, 2 */
    goto L_00cdac53; /* jmp 0xcdac53 */
L_00cdac4c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x3u))) << 8); /* or ch, 3 */
L_00cdac53:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_00cdac55:;
    FPUSH(c, RF64((uint32_t)(c->eax + 0x40u))); /* fld qword ptr [eax + 0x40] */
    WF64((uint32_t)(c->edi), ST(0)); FPOP(c); /* fstp qword ptr [edi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00cdac5f(CPU *c) { /* FUN_1000ac5f */
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
    if (c->zf) goto L_00cdac8a; /* je 0xcdac8a */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp + 0x10], bl */
    if (c->zf) goto L_00cdac8a; /* je 0xcdac8a */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cdac81u); f_00cdaee1(c); /* call 0xcdaee1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffff7u))); /* and edi, 0xfffffff7 */
    goto L_00cdae54; /* jmp 0xcdae54 */
L_00cdac8a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00cdaca4; /* je 0xcdaca4 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0x10], 4 */
    if (c->zf) goto L_00cdaca4; /* je 0xcdaca4 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x00cdac9bu); f_00cdaee1(c); /* call 0xcdaee1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffbu))); /* and edi, 0xfffffffb */
    goto L_00cdae54; /* jmp 0xcdae54 */
L_00cdaca4:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00cdad7e; /* je 0xcdad7e */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x8u)); /* test byte ptr [ebp + 0x10], 8 */
    if (c->zf) goto L_00cdad7e; /* je 0xcdad7e */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00cdacbdu); f_00cdaee1(c); /* call 0xcdaee1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)0xc00u); /* mov eax, 0xc00 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->eax))); /* and ecx, eax */
    if (c->zf) goto L_00cdad56; /* je 0xcdad56 */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if (c->zf) goto L_00cdad2e; /* je 0xcdad2e */
    (void)sub32(c, c->ecx, (uint32_t)0x800u); /* cmp ecx, 0x800 */
    if (c->zf) goto L_00cdad06; /* je 0xcdad06 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->zf) goto L_00cdad76; /* jne 0xcdad76 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    FPUSH(c, RF64((uint32_t)(0xcdff80u))); /* fld qword ptr [0x1000ff80] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00cdacfe; /* ja 0xcdacfe */
    ST(0) = -ST(0); /* fchs  */
L_00cdacfe:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00cdad74; /* jmp 0xcdad74 */
L_00cdad06:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00cdad1e; /* jbe 0xcdad1e */
    FPUSH(c, RF64((uint32_t)(0xcdff70u))); /* fld qword ptr [0x1000ff70] */
    goto L_00cdad26; /* jmp 0xcdad26 */
L_00cdad1e:;
    FPUSH(c, RF64((uint32_t)(0xcdff80u))); /* fld qword ptr [0x1000ff80] */
    ST(0) = -ST(0); /* fchs  */
L_00cdad26:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00cdad74; /* jmp 0xcdad74 */
L_00cdad2e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00cdad46; /* jbe 0xcdad46 */
    FPUSH(c, RF64((uint32_t)(0xcdff80u))); /* fld qword ptr [0x1000ff80] */
    goto L_00cdad4e; /* jmp 0xcdad4e */
L_00cdad46:;
    FPUSH(c, RF64((uint32_t)(0xcdff70u))); /* fld qword ptr [0x1000ff70] */
    ST(0) = -ST(0); /* fchs  */
L_00cdad4e:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00cdad74; /* jmp 0xcdad74 */
L_00cdad56:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    FPUSH(c, RF64((uint32_t)(0xcdff70u))); /* fld qword ptr [0x1000ff70] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00cdad6e; /* ja 0xcdad6e */
    ST(0) = -ST(0); /* fchs  */
L_00cdad6e:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
L_00cdad74:;
    WF64((uint32_t)(c->ecx), ST(0)); FPOP(c); /* fstp qword ptr [ecx] */
L_00cdad76:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffeu))); /* and edi, 0xfffffffe */
    goto L_00cdae54; /* jmp 0xcdae54 */
L_00cdad7e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00cdae54; /* je 0xcdae54 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0x10], 0x10 */
    if (c->zf) goto L_00cdae54; /* je 0xcdae54 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00cdad99; /* je 0xcdad99 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00cdad99:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_00cdae42; /* je 0xcdae42 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00cdadc4u); f_00cdb123(c); /* call 0xcdb123 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfffffa00u)); /* lea ecx, [eax - 0x600] */
    (void)sub32(c, c->ecx, (uint32_t)0xfffffbceu); /* cmp ecx, 0xfffffbce */
    if ((c->sf == c->of)) goto L_00cdade4; /* jge 0xcdade4 */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    goto L_00cdae38; /* jmp 0xcdae38 */
L_00cdade4:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00cdadf6; /* jae 0xcdadf6 */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00cdadf8; /* jmp 0xcdadf8 */
L_00cdadf6:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00cdadf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffau))); /* mov al, byte ptr [ebp - 6] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
    W16((uint32_t)(c->ebp + 0xfffffffau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 6], ax */
    c->eax = (uint32_t)((uint32_t)0xfffffc03u); /* mov eax, 0xfffffc03 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00cdae2c; /* jge 0xcdae2c */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
L_00cdae0f:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 0xc], bl */
    if (c->zf) goto L_00cdae1a; /* je 0xcdae1a */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00cdae1a; /* jne 0xcdae1a */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00cdae1a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff8u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 8], bl */
    if (c->zf) goto L_00cdae26; /* je 0xcdae26 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
L_00cdae26:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 8], 1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00cdae0f; /* jne 0xcdae0f */
L_00cdae2c:;
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00cdae38; /* je 0xcdae38 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    ST(0) = -ST(0); /* fchs  */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
L_00cdae38:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_00cdae44; /* jmp 0xcdae44 */
L_00cdae42:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00cdae44:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00cdae51; /* je 0xcdae51 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00cdae50u); f_00cdaee1(c); /* call 0xcdaee1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00cdae51:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffdu))); /* and edi, 0xfffffffd */
L_00cdae54:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 8], 0x10 */
    if (c->zf) goto L_00cdae6b; /* je 0xcdae6b */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x20u)); /* test byte ptr [ebp + 0x10], 0x20 */
    if (c->zf) goto L_00cdae6b; /* je 0xcdae6b */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00cdae67u); f_00cdaee1(c); /* call 0xcdaee1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffffffefu))); /* and edi, 0xffffffef */
L_00cdae6b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdae76(CPU *c) { /* FUN_1000ae76 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00cdae92; /* je 0xcdae92 */
    if ((c->zf || c->sf != c->of)) goto L_00cdae9d; /* jle 0xcdae9d */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->zf && c->sf == c->of)) goto L_00cdae9d; /* jg 0xcdae9d */
    PUSH32(c, 0x00cdae8bu); f_00cdaf37(c); /* call 0xcdaf37 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [eax], 0x22 */
    c->esp += 4; return; /* ret  */
L_00cdae92:;
    PUSH32(c, 0x00cdae97u); f_00cdaf37(c); /* call 0xcdaf37 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x21u)); /* mov dword ptr [eax], 0x21 */
L_00cdae9d:;
    c->esp += 4; return; /* ret  */
}

void f_00cdae9e(CPU *c) { /* FUN_1000ae9e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00cdaea1(CPU *c) { /* FUN_1000aea1 */
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

void f_00cdaeaf(CPU *c) { /* FUN_1000aeaf */
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

void f_00cdaebe(CPU *c) { /* FUN_1000aebe */
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

void f_00cdaee1(CPU *c) { /* FUN_1000aee1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    if (c->zf) goto L_00cdaef8; /* je 0xcdaef8 */
    FPUSH(c, RF80((uint32_t)(0xcdfb2cu))); /* fld xword ptr [0x1000fb2c] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 8] */
    ; /* wait  */
L_00cdaef8:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00cdaf0d; /* je 0xcdaf0d */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    FPUSH(c, RF80((uint32_t)(0xcdfb2cu))); /* fld xword ptr [0x1000fb2c] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
L_00cdaf0d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x10u)); /* test cl, 0x10 */
    if (c->zf) goto L_00cdaf1c; /* je 0xcdaf1c */
    FPUSH(c, RF80((uint32_t)(0xcdfb38u))); /* fld xword ptr [0x1000fb38] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_00cdaf1c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_00cdaf2a; /* je 0xcdaf2a */
    FPUSH(c, 0.0); /* fldz  */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ; /* wait  */
L_00cdaf2a:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x20u)); /* test cl, 0x20 */
    if (c->zf) goto L_00cdaf35; /* je 0xcdaf35 */
    FPUSH(c, M_PI); /* fldpi  */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_00cdaf35:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdaf37(CPU *c) { /* FUN_1000af37 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00cdaf3cu); f_00cd3480(c); /* call 0xcd3480 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00cdaf40(CPU *c) { /* FUN_1000af40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xce068cu)), c->ebx); /* cmp dword ptr [0x1001068c], ebx */
    if (!c->zf) goto L_00cdaf5e; /* jne 0xcdaf5e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00cdafad; /* jl 0xcdafad */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00cdafad; /* jg 0xcdafad */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00cdaf5e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xce07ecu); /* mov esi, 0x100107ec */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xcdc0a8u)); PUSH32(c, 0x00cdaf6cu); call_indirect(c, t_); } /* call dword ptr [0x1000c0a8] */
    (void)sub32(c, R32((uint32_t)(0xce07e8u)), c->ebx); /* cmp dword ptr [0x100107e8], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0xcdc0a4u))); /* mov edi, dword ptr [0x1000c0a4] */
    if (c->zf) goto L_00cdaf88; /* je 0xcdaf88 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cdaf7du); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cdaf84u); f_00cd3abb(c); /* call 0xcd3abb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00cdaf88:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00cdaf91u); f_00cdafaf(c); /* call 0xcdafaf */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00cdafa4; /* je 0xcdafa4 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cdafa1u); f_00cd3b1c(c); /* call 0xcd3b1c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cdafa7; /* jmp 0xcdafa7 */
L_00cdafa4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00cdafa7u); call_indirect(c, t_); } /* call edi */
L_00cdafa7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00cdafad:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00cdafaf(CPU *c) { /* FUN_1000afaf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xce068cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1001068c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_00cdafda; /* jne 0xcdafda */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00cdb078; /* jl 0xcdb078 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00cdb078; /* jg 0xcdb078 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_00cdb078; /* jmp 0xcdb078 */
L_00cdafda:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_00cdb00d; /* jge 0xcdb00d */
    (void)sub32(c, R32((uint32_t)(0xcdd500u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d500], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00cdaffa; /* jle 0xcdaffa */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cdaff6u); f_00cd4617(c); /* call 0xcd4617 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00cdb005; /* jmp 0xcdb005 */
L_00cdaffa:;
    c->eax = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov eax, dword ptr [0x1000d2f4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_00cdb005:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00cdb00d; /* jne 0xcdb00d */
L_00cdb009:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00cdb078; /* jmp 0xcdb078 */
L_00cdb00d:;
    c->edx = (uint32_t)(R32((uint32_t)(0xcdd2f4u))); /* mov edx, dword ptr [0x1000d2f4] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00cdb030; /* je 0xcdb030 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00cdb039; /* jmp 0xcdb039 */
L_00cdb030:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00cdb039:;
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
    { uint32_t v_ = R32((uint32_t)(0xce068cu)); PUSH32(c, v_); } /* push dword ptr [0x1001068c] */
    PUSH32(c, 0x00cdb059u); f_00cda08d(c); /* call 0xcda08d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00cdb009; /* je 0xcdb009 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00cdb06b; /* jne 0xcdb06b */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00cdb078; /* jmp 0xcdb078 */
L_00cdb06b:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00cdb078:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdb080(CPU *c) { /* FUN_1000b080 */
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
L_00cdb094:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb0a1; /* je 0xcdb0a1 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00cdb094; /* jmp 0xcdb094 */
L_00cdb0a1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_00cdb0a8:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb0b6; /* je 0xcdb0b6 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00cdb0a8; /* jae 0xcdb0a8 */
L_00cdb0b6:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdb0c0(CPU *c) { /* FUN_1000b0c0 */
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
L_00cdb0d4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb0e1; /* je 0xcdb0e1 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_00cdb0d4; /* jmp 0xcdb0d4 */
L_00cdb0e1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_00cdb0e4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb0f4; /* je 0xcdb0f4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_00cdb0e4; /* jae 0xcdb0e4 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00cdb0f4:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdb0fa(CPU *c) { /* FUN_1000b0fa */
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

void f_00cdb123(CPU *c) { /* FUN_1000b123 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00cdb143; /* jne 0xcdb143 */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    goto L_00cdb1d9; /* jmp 0xcdb1d9 */
L_00cdb143:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xeu)) & (uint16_t)0x7ff0u)); /* test word ptr [ebp + 0xe], 0x7ff0 */
    if (!c->zf) goto L_00cdb1b2; /* jne 0xcdb1b2 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp + 0xc], 0xfffff */
    if (!c->zf) goto L_00cdb15b; /* jne 0xcdb15b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->ecx); /* cmp dword ptr [ebp + 8], ecx */
    if (c->zf) goto L_00cdb1b2; /* je 0xcdb1b2 */
L_00cdb15b:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xcdc288u))); FPOP(c); /* fcomp qword ptr [0x1000c288] */
    c->esi = (uint32_t)((uint32_t)0xfffffc03u); /* mov esi, 0xfffffc03 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00cdb173; /* jae 0xcdb173 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00cdb175; /* jmp 0xcdb175 */
L_00cdb173:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00cdb175:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xeu)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0xe], 0x10 */
    if (!c->zf) goto L_00cdb18e; /* jne 0xcdb18e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp + 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xbu)) & (uint8_t)0x80u)); /* test byte ptr [ebp + 0xb], 0x80 */
    if (c->zf) goto L_00cdb188; /* je 0xcdb188 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp + 0xc], 1 */
L_00cdb188:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(shl32(c, R32(a_), 1))); } /* shl dword ptr [ebp + 8], 1 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    goto L_00cdb175; /* jmp 0xcdb175 */
L_00cdb18e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xeu); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0xffefu)))); } /* and word ptr [ebp + 0xe], 0xffef */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00cdb19c; /* je 0xcdb19c */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp + 0xf], 0x80 */
L_00cdb19c:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00cdb1aau); f_00cdb0fa(c); /* call 0xcdb0fa */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00cdb1d9; /* jmp 0xcdb1d9 */
L_00cdb1b2:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00cdb1c0u); f_00cdb0fa(c); /* call 0xcdb0fa */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ffu))); /* and ax, 0x7ff */
    c->esi = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx esi, ax */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3feu)); /* sub esi, 0x3fe */
L_00cdb1d9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->esi)); /* mov dword ptr [eax], esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdb1f0(CPU *c) { /* FUN_1000b1f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0xce0684u)); /* lea eax, [0x10010684] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00cdb243; /* jne 0xcdb243 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00cdb20c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb23e; /* je 0xcdb23e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00cdb20c; /* je 0xcdb20c */
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
    if (c->zf) goto L_00cdb20c; /* je 0xcdb20c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_00cdb23e:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_00cdb2bb; /* jmp 0xcdb2bb */
L_00cdb243:;
    { guest_lock(); guest_trap(c, 0x00cdb243u, "unsupported: lock inc dword ptr [0x100107ec]"); guest_unlock(); } /* lock inc dword ptr [0x100107ec] */
    (void)sub32(c, R32((uint32_t)(0xce07e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100107e8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cdb257; /* jg 0xcdb257 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00cdb26c; /* jmp 0xcdb26c */
L_00cdb257:;
    { guest_lock(); guest_trap(c, 0x00cdb257u, "unsupported: lock dec dword ptr [0x100107ec]"); guest_unlock(); } /* lock dec dword ptr [0x100107ec] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cdb265u); f_00cd3abb(c); /* call 0xcd3abb */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_00cdb26c:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_00cdb274:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb29f; /* je 0xcdb29f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00cdb274; /* je 0xcdb274 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cdb289u); f_00cd6dd1(c); /* call 0xcd6dd1 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00cdb293u); f_00cd6dd1(c); /* call 0xcd6dd1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_00cdb274; /* je 0xcdb274 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_00cdb29f:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00cdb2af; /* jne 0xcdb2af */
    { guest_lock(); guest_trap(c, 0x00cdb2a6u, "unsupported: lock dec dword ptr [0x100107ec]"); guest_unlock(); } /* lock dec dword ptr [0x100107ec] */
    goto L_00cdb2b9; /* jmp 0xcdb2b9 */
L_00cdb2af:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cdb2b6u); f_00cd3b1c(c); /* call 0xcd3b1c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00cdb2b9:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_00cdb2bb:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdb2c0(CPU *c) { /* FUN_1000b2c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_00cdb3ba; /* je 0xcdb3ba */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0xce0684u)); /* lea eax, [0x10010684] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00cdb331; /* jne 0xcdb331 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_00cdb2ec:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_00cdb315; /* je 0xcdb315 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00cdb315; /* je 0xcdb315 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_00cdb304; /* jb 0xcdb304 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_00cdb304; /* ja 0xcdb304 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_00cdb304:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_00cdb30e; /* jb 0xcdb30e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_00cdb30e; /* ja 0xcdb30e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_00cdb30e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_00cdb31f; /* jne 0xcdb31f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00cdb2ec; /* jne 0xcdb2ec */
L_00cdb315:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_00cdb3ba; /* je 0xcdb3ba */
L_00cdb31f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00cdb3ba; /* jb 0xcdb3ba */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_00cdb3ba; /* jmp 0xcdb3ba */
L_00cdb331:;
    { guest_lock(); guest_trap(c, 0x00cdb331u, "unsupported: lock inc dword ptr [0x100107ec]"); guest_unlock(); } /* lock inc dword ptr [0x100107ec] */
    (void)sub32(c, R32((uint32_t)(0xce07e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100107e8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00cdb345; /* jg 0xcdb345 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_00cdb35e; /* jmp 0xcdb35e */
L_00cdb345:;
    { guest_lock(); guest_trap(c, 0x00cdb345u, "unsupported: lock dec dword ptr [0x100107ec]"); guest_unlock(); } /* lock dec dword ptr [0x100107ec] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cdb355u); f_00cd3abb(c); /* call 0xcd3abb */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00cdb35e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00cdb364:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_00cdb38f; /* je 0xcdb38f */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_00cdb38f; /* je 0xcdb38f */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00cdb37au); f_00cd6dd1(c); /* call 0xcd6dd1 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x00cdb384u); f_00cd6dd1(c); /* call 0xcd6dd1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00cdb395; /* jne 0xcdb395 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00cdb364; /* jne 0xcdb364 */
L_00cdb38f:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00cdb39e; /* je 0xcdb39e */
L_00cdb395:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_00cdb39e; /* jb 0xcdb39e */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_00cdb39e:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00cdb3ac; /* jne 0xcdb3ac */
    { guest_lock(); guest_trap(c, 0x00cdb3a3u, "unsupported: lock dec dword ptr [0x100107ec]"); guest_unlock(); } /* lock dec dword ptr [0x100107ec] */
    goto L_00cdb3ba; /* jmp 0xcdb3ba */
L_00cdb3ac:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00cdb3b5u); f_00cd3b1c(c); /* call 0xcd3b1c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_00cdb3ba:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00cdb3d0(CPU *c) { /* PTR_00cdb3d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00cdb3f2; /* jne 0xcdb3f2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cdb3e4u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cdb3ecu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00cdb433; /* jmp 0xcdb433 */
L_00cdb3f2:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_00cdb400:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00cdb400; /* jne 0xcdb400 */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cdb40cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x18u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint64_t r_ = (uint64_t)c->eax * c->esi; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul esi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_00cdb42e; /* jb 0xcdb42e */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x10u))); /* cmp edx, dword ptr [esp + 0x10] */
    if ((!c->cf && !c->zf)) goto L_00cdb42e; /* ja 0xcdb42e */
    if (c->cf) goto L_00cdb42f; /* jb 0xcdb42f */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0xcu))); /* cmp eax, dword ptr [esp + 0xc] */
    if ((c->cf || c->zf)) goto L_00cdb42f; /* jbe 0xcdb42f */
L_00cdb42e:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
L_00cdb42f:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00cdb433:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cdb440(CPU *c) { /* PTR_00cdb440 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00cdb461; /* jne 0xcdb461 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cdb453u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cdb459u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_00cdb4b1; /* jmp 0xcdb4b1 */
L_00cdb461:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
L_00cdb46f:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00cdb46f; /* jne 0xcdb46f */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00cdb47bu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_00cdb49a; /* jb 0xcdb49a */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0xcu))); /* cmp edx, dword ptr [esp + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00cdb49a; /* ja 0xcdb49a */
    if (c->cf) goto L_00cdb4a2; /* jb 0xcdb4a2 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u))); /* cmp eax, dword ptr [esp + 8] */
    if ((c->cf || c->zf)) goto L_00cdb4a2; /* jbe 0xcdb4a2 */
L_00cdb49a:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x10u)))); /* sub eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0x14u)))); /* sbb edx, dword ptr [esp + 0x14] */
L_00cdb4a2:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0xcu)))); /* sbb edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(sbb32(c, c->edx, (uint32_t)0x0u)); /* sbb edx, 0 */
L_00cdb4b1:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00cdb4b6(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xcdc000u)); switch (t_) {  default: jump_indirect(c, t_, 0x00cdb4b6u); return; } } /* jmp dword ptr [0x1000c000] */
}

void f_00cdb4c0(CPU *c) { /* Unwind@1000b4c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = 0xcdd058u; PUSH32(c, v_); } /* push 0x1000d058 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cdb4d0u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00cdb4d4(CPU *c) { /* PTR_00cdb4d4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdc980u); /* mov eax, 0x1000c980 */
    { f_00cd2c73(c); return; } /* jmp 0xcd2c73 */
}

void f_00cdb4e0(CPU *c) { /* Unwind@1000b4e0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    { f_00cd15b0(c); return; } /* jmp 0xcd15b0 */
}

void f_00cdb4e8(CPU *c) { /* PTR_00cdb4e8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdc9a4u); /* mov eax, 0x1000c9a4 */
    { f_00cd2c73(c); return; } /* jmp 0xcd2c73 */
}

void f_00cdb500(CPU *c) { /* Unwind@1000b500 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { f_00cd15b0(c); return; } /* jmp 0xcd15b0 */
}

void f_00cdb508(CPU *c) { /* PTR_00cdb508 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdc9c8u); /* mov eax, 0x1000c9c8 */
    { f_00cd2c73(c); return; } /* jmp 0xcd2c73 */
}

void f_00cdb520(CPU *c) { /* Unwind@1000b520 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcd2620u; PUSH32(c, v_); } /* push 0x10002620 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x34u; PUSH32(c, v_); } /* push 0x34 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cdb535u); f_00cd3120(c); /* call 0xcd3120 */
    c->esp += 4; return; /* ret  */
}

void f_00cdb536(CPU *c) { /* PTR_00cdb536 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdc9ecu); /* mov eax, 0x1000c9ec */
    { f_00cd2c73(c); return; } /* jmp 0xcd2c73 */
}

void f_00cdb540(CPU *c) { /* Unwind@1000b540 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcd2620u; PUSH32(c, v_); } /* push 0x10002620 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x34u; PUSH32(c, v_); } /* push 0x34 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cdb555u); f_00cd3120(c); /* call 0xcd3120 */
    c->esp += 4; return; /* ret  */
}

void f_00cdb556(CPU *c) { /* Unwind@1000b556 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xcd1750u; PUSH32(c, v_); } /* push 0x10001750 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    { uint32_t v_ = 0x50u; PUSH32(c, v_); } /* push 0x50 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x65cu)); /* add eax, 0x65c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cdb56du); f_00cd3120(c); /* call 0xcd3120 */
    c->esp += 4; return; /* ret  */
}

void f_00cdb56e(CPU *c) { /* PTR_00cdb56e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdca18u); /* mov eax, 0x1000ca18 */
    { f_00cd2c73(c); return; } /* jmp 0xcd2c73 */
}

void f_00cdb580(CPU *c) { /* Unwind@1000b580 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    { uint32_t v_ = 0xcdd150u; PUSH32(c, v_); } /* push 0x1000d150 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00cdb590u); f_00cd10b0(c); /* call 0xcd10b0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00cdb594(CPU *c) { /* PTR_00cdb594 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xcdca3cu); /* mov eax, 0x1000ca3c */
    { f_00cd2c73(c); return; } /* jmp 0xcd2c73 */
}
