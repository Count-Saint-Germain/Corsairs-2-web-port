#include "recomp.h"

void f_006767a0(CPU *c) { /* _strstr */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_0067681a; /* je 0x67681a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00676807; /* je 0x676807 */
L_006767b8:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_006767da; /* je 0x6767da */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006767d4; /* je 0x6767d4 */
L_006767c9:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006767cc:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_006767da; /* je 0x6767da */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_006767c9; /* jne 0x6767c9 */
L_006767d4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006767da:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_006767cc; /* jne 0x6767cc */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_006767e4:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00676813; /* je 0x676813 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_006767b8; /* jne 0x6767b8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00676813; /* je 0x676813 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_006767e4; /* je 0x6767e4 */
    goto L_006767b8; /* jmp 0x6767b8 */
L_00676807:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_006766e6(c); return; } /* jmp 0x6766e6 */
L_00676813:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0067681a:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_0067680c(CPU *c) { /* PTR_0067680c */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_006766e6(c); return; } /* jmp 0x6766e6 */
}

void f_00676820(CPU *c) { /* _strncmp */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    if (c->ecx == 0) goto L_00676851; /* jecxz 0x676851 */
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
    if ((!c->cf && !c->zf)) goto L_0067684f; /* ja 0x67684f */
    if (c->zf) goto L_00676851; /* je 0x676851 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
L_0067684f:;
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
L_00676851:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00676860(CPU *c) { /* FUN_10006860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_00676880; /* jb 0x676880 */
L_0067686c:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_0067686c; /* jae 0x67686c */
L_00676880:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_0067688f(CPU *c) { /* FUN_1000688f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x67c1e8u)), c->ebx); /* cmp dword ptr [0x1000c1e8], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006768de; /* jne 0x6768de */
    { uint32_t v_ = 0x6785a8u; PUSH32(c, v_); } /* push 0x100085a8 */
    { uint32_t t_ = R32((uint32_t)(0x6780bcu)); PUSH32(c, 0x006768a7u); call_indirect(c, t_); } /* call dword ptr [0x100080bc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00676914; /* je 0x676914 */
    c->esi = (uint32_t)(R32((uint32_t)(0x6780b8u))); /* mov esi, dword ptr [0x100080b8] */
    { uint32_t v_ = 0x67859cu; PUSH32(c, v_); } /* push 0x1000859c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006768bbu); call_indirect(c, t_); } /* call esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x67c1e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c1e8], eax */
    if (c->zf) goto L_00676914; /* je 0x676914 */
    { uint32_t v_ = 0x67858cu; PUSH32(c, v_); } /* push 0x1000858c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006768ccu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = 0x678578u; PUSH32(c, v_); } /* push 0x10008578 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(0x67c1ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c1ec], eax */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006768d9u); call_indirect(c, t_); } /* call esi */
    W32((uint32_t)(0x67c1f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c1f0], eax */
L_006768de:;
    c->eax = (uint32_t)(R32((uint32_t)(0x67c1ecu))); /* mov eax, dword ptr [0x1000c1ec] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006768fd; /* je 0x6768fd */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006768e9u); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_006768fd; /* je 0x6768fd */
    c->eax = (uint32_t)(R32((uint32_t)(0x67c1f0u))); /* mov eax, dword ptr [0x1000c1f0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006768fd; /* je 0x6768fd */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006768fbu); call_indirect(c, t_); } /* call eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_006768fd:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x67c1e8u)); PUSH32(c, 0x00676910u); call_indirect(c, t_); } /* call dword ptr [0x1000c1e8] */
L_00676910:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00676914:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00676910; /* jmp 0x676910 */
}

void f_00676920(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006769a3; /* je 0x6769a3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00676944; /* jne 0x676944 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_006769b1; /* jne 0x6769b1 */
    goto L_00676965; /* jmp 0x676965 */
L_00676944:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00676972; /* je 0x676972 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0067697a; /* je 0x67697a */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_00676944; /* jne 0x676944 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_006769b1; /* jne 0x6769b1 */
L_00676960:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_00676972; /* je 0x676972 */
L_00676965:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_0067699e; /* je 0x67699e */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00676965; /* jne 0x676965 */
L_00676972:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_0067697a:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_00676994; /* je 0x676994 */
L_00676982:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00676a16; /* je 0x676a16 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00676982; /* jne 0x676982 */
L_00676994:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_00676a07; /* jne 0x676a07 */
L_0067699b:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_0067699e:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_0067699b; /* jne 0x67699b */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006769a3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006769a9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00676960; /* je 0x676960 */
L_006769b1:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_006769a9; /* je 0x6769a9 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006769fb; /* je 0x6769fb */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_006769f1; /* je 0x6769f1 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_006769e7; /* je 0x6769e7 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_006769a9; /* jne 0x6769a9 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_006769ff; /* jmp 0x6769ff */
L_006769e7:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_006769ff; /* jmp 0x6769ff */
L_006769f1:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_006769ff; /* jmp 0x6769ff */
L_006769fb:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_006769ff:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00676a11; /* je 0x676a11 */
L_00676a07:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676a09:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00676a09; /* jne 0x676a09 */
L_00676a11:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_0067699b; /* jne 0x67699b */
L_00676a16:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00676a20(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00676a73; /* je 0x676a73 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_00676a67; /* jb 0x676a67 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_00676a49; /* je 0x676a49 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_00676a43:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00676a43; /* jne 0x676a43 */
L_00676a49:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_00676a67; /* je 0x676a67 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00676a6d; /* je 0x676a6d */
L_00676a67:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00676a67; /* jne 0x676a67 */
L_00676a6d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00676a73:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00676a78(CPU *c) { /* FUN_10006a78 */
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
    if (c->zf) goto L_00676af3; /* je 0x676af3 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00676ad6; /* je 0x676ad6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00676ad6; /* je 0x676ad6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00676ad6; /* je 0x676ad6 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00676ac9; /* je 0x676ac9 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_00676abc; /* je 0x676abc */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00676aaf; /* je 0x676aaf */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00676bf5; /* jmp 0x676bf5 */
L_00676aaf:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x67c1fcu))); /* mov ebx, dword ptr [0x1000c1fc] */
    c->edi = (uint32_t)((uint32_t)0x67c1fcu); /* mov edi, 0x1000c1fc */
    goto L_00676afe; /* jmp 0x676afe */
L_00676abc:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x67c1f8u))); /* mov ebx, dword ptr [0x1000c1f8] */
    c->edi = (uint32_t)((uint32_t)0x67c1f8u); /* mov edi, 0x1000c1f8 */
    goto L_00676afe; /* jmp 0x676afe */
L_00676ac9:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x67c200u))); /* mov ebx, dword ptr [0x1000c200] */
    c->edi = (uint32_t)((uint32_t)0x67c200u); /* mov edi, 0x1000c200 */
    goto L_00676afe; /* jmp 0x676afe */
L_00676ad6:;
    PUSH32(c, 0x00676adbu); f_00672eb1(c); /* call 0x672eb1 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x50u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x50] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00676ae8u); f_00676bfa(c); /* call 0x676bfa */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x8u)); /* add edi, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ebx, dword ptr [edi] */
    goto L_00676b10; /* jmp 0x676b10 */
L_00676af3:;
    c->ebx = (uint32_t)(R32((uint32_t)(0x67c1f4u))); /* mov ebx, dword ptr [0x1000c1f4] */
    c->edi = (uint32_t)((uint32_t)0x67c1f4u); /* mov edi, 0x1000c1f4 */
L_00676afe:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00676b0cu); f_00674867(c); /* call 0x674867 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00676b10:;
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    if (!c->zf) goto L_00676b2b; /* jne 0x676b2b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00676bf3; /* je 0x676bf3 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00676b25u); f_006748c8(c); /* call 0x6748c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00676bf3; /* jmp 0x676bf3 */
L_00676b2b:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if (!c->zf) goto L_00676b45; /* jne 0x676b45 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ecx); /* cmp dword ptr [ebp - 4], ecx */
    if (c->zf) goto L_00676b3e; /* je 0x676b3e */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00676b3du); f_006748c8(c); /* call 0x6748c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00676b3e:;
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00676b45u); f_0067309c(c); /* call 0x67309c */
L_00676b45:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (c->zf) goto L_00676b57; /* je 0x676b57 */
    (void)sub32(c, c->eax, (uint32_t)0xbu); /* cmp eax, 0xb */
    if (c->zf) goto L_00676b57; /* je 0x676b57 */
    (void)sub32(c, c->eax, (uint32_t)0x4u); /* cmp eax, 4 */
    if (!c->zf) goto L_00676b72; /* jne 0x676b72 */
L_00676b57:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x54u))); /* mov edx, dword ptr [esi + 0x54] */
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0x54], ecx */
    if (!c->zf) goto L_00676bae; /* jne 0x676bae */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x58u))); /* mov edx, dword ptr [esi + 0x58] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [esi + 0x58], 0x8c */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_00676b72:;
    (void)sub32(c, c->eax, (uint32_t)0x8u); /* cmp eax, 8 */
    if (!c->zf) goto L_00676bae; /* jne 0x676bae */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6797f8u))); /* mov ecx, dword ptr [0x100097f8] */
    c->eax = (uint32_t)(R32((uint32_t)(0x6797fcu))); /* mov eax, dword ptr [0x100097fc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00676bb0; /* jge 0x676bb0 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
L_00676b8e:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov edx, dword ptr [esi + 0x50] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx + eax - 4], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(0x6797f8u))); /* mov edx, dword ptr [0x100097f8] */
    c->edi = (uint32_t)(R32((uint32_t)(0x6797fcu))); /* mov edi, dword ptr [0x100097fc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, c->edx)); /* add edi, edx */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if ((c->sf != c->of)) goto L_00676b8e; /* jl 0x676b8e */
    goto L_00676bb0; /* jmp 0x676bb0 */
L_00676bae:;
    W32((uint32_t)(c->edi), (uint32_t)(c->ecx)); /* mov dword ptr [edi], ecx */
L_00676bb0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00676bbe; /* je 0x676bbe */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00676bbdu); f_006748c8(c); /* call 0x6748c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00676bbe:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    if (!c->zf) goto L_00676bcf; /* jne 0x676bcf */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x58u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x58] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00676bcbu); call_indirect(c, t_); } /* call ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00676be1; /* jmp 0x676be1 */
L_00676bcf:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = c->ebx; PUSH32(c, 0x00676bd4u); call_indirect(c, t_); } /* call ebx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0xbu); /* cmp dword ptr [ebp + 8], 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00676be1; /* je 0x676be1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x4u); /* cmp dword ptr [ebp + 8], 4 */
    if (!c->zf) goto L_00676bf3; /* jne 0x676bf3 */
L_00676be1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x8u); /* cmp dword ptr [ebp + 8], 8 */
    W32((uint32_t)(c->esi + 0x54u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x54], eax */
    if (!c->zf) goto L_00676bf3; /* jne 0x676bf3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->esi + 0x58u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x58], eax */
L_00676bf3:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676bf5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00676bfa(CPU *c) { /* FUN_10006bfa */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x679804u))); /* mov ecx, dword ptr [0x10009804] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x4u)), c->esi); /* cmp dword ptr [edx + 4], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    if (c->zf) goto L_00676c23; /* je 0x676c23 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edi, [ecx + ecx*2] */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->edi * 4)); /* lea edi, [edx + edi*4] */
L_00676c17:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->cf) goto L_00676c23; /* jae 0x676c23 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (!c->zf) goto L_00676c17; /* jne 0x676c17 */
L_00676c23:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    c->ecx = (uint32_t)((uint32_t)(c->edx + c->ecx * 4)); /* lea ecx, [edx + ecx*4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00676c32; /* jae 0x676c32 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->esi); /* cmp dword ptr [eax + 4], esi */
    if (c->zf) goto L_00676c34; /* je 0x676c34 */
L_00676c32:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676c34:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00676c37(CPU *c) { /* FUN_10006c37 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6785c0u; PUSH32(c, v_); } /* push 0x100085c0 */
    { uint32_t v_ = 0x67427cu; PUSH32(c, v_); } /* push 0x1000427c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(0x67c228u)), c->edi); /* cmp dword ptr [0x1000c228], edi */
    if (!c->zf) goto L_00676cad; /* jne 0x676cad */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x6785b8u; PUSH32(c, v_); } /* push 0x100085b8 */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676c7fu); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676c8b; /* je 0x676c8b */
    W32((uint32_t)(0x67c228u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000c228], ebx */
    goto L_00676cad; /* jmp 0x676cad */
L_00676c8b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x6785b4u; PUSH32(c, v_); } /* push 0x100085b4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6780c4u)); PUSH32(c, 0x00676c9bu); call_indirect(c, t_); } /* call dword ptr [0x100080c4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    W32((uint32_t)(0x67c228u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x1000c228], 2 */
L_00676cad:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->edi); /* cmp dword ptr [ebp + 0x14], edi */
    if ((c->zf || c->sf != c->of)) goto L_00676cc2; /* jle 0x676cc2 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x00676cbdu); f_00676e5b(c); /* call 0x676e5b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_00676cc2:;
    c->eax = (uint32_t)(R32((uint32_t)(0x67c228u))); /* mov eax, dword ptr [0x1000c228] */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00676ce9; /* jne 0x676ce9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c4u)); PUSH32(c, 0x00676ce4u); call_indirect(c, t_); } /* call dword ptr [0x100080c4] */
    goto L_00676dc7; /* jmp 0x676dc7 */
L_00676ce9:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00676dc5; /* jne 0x676dc5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), c->edi); /* cmp dword ptr [ebp + 0x20], edi */
    if (!c->zf) goto L_00676cff; /* jne 0x676cff */
    c->eax = (uint32_t)(R32((uint32_t)(0x67c220u))); /* mov eax, dword ptr [0x1000c220] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
L_00676cff:;
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
    { uint32_t t_ = R32((uint32_t)(0x6780c0u)); PUSH32(c, 0x00676d1cu); call_indirect(c, t_); } /* call dword ptr [0x100080c0] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x1c], ebx */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea eax, [ebx + ebx] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00676d39u); f_00676860(c); /* call 0x676860 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00676d5a; /* jmp 0x676d5a */
L_00676d5a:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x6780c0u)); PUSH32(c, 0x00676d74u); call_indirect(c, t_); } /* call dword ptr [0x100080c0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676d8au); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00676dd9; /* je 0x676dd9 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00676e54; /* je 0x676e54 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00676dc5; /* jg 0x676dc5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676dbdu); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00676e54; /* jne 0x676e54 */
L_00676dc5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676dc7:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00676dd9:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00676dedu); f_00676860(c); /* call 0x676860 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00676e0d; /* jmp 0x676e0d */
L_00676e0d:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676e25u); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00676e34; /* jne 0x676e34 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00676e3a; /* jmp 0x676e3a */
L_00676e34:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00676e3a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x678060u)); PUSH32(c, 0x00676e4au); call_indirect(c, t_); } /* call dword ptr [0x10008060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
L_00676e54:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00676dc7; /* jmp 0x676dc7 */
}

void f_00676d47(CPU *c) { /* PTR_00676d47 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00676d4b(CPU *c) { /* PTR_00676d4b */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ebx, dword ptr [ebp - 0x1c] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x6780c0u)); PUSH32(c, 0x00676d74u); call_indirect(c, t_); } /* call dword ptr [0x100080c0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676d8au); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xdu)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0xd], 4 */
    if (c->zf) goto L_00676dd9; /* je 0x676dd9 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    if (c->zf) goto L_00676e54; /* je 0x676e54 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp esi, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_00676dc5; /* jg 0x676dc5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676dbdu); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00676e54; /* jne 0x676e54 */
L_00676dc5:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676dc7:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea esp, [ebp - 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00676dd9:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi)); /* lea eax, [esi + esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00676dedu); f_00676860(c); /* call 0x676860 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(c->esp); /* mov ebx, esp */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00676e0d; /* jmp 0x676e0d */
L_00676e0d:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676e25u); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00676e34; /* jne 0x676e34 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00676e3a; /* jmp 0x676e3a */
L_00676e34:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00676e3a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x678060u)); PUSH32(c, 0x00676e4au); call_indirect(c, t_); } /* call dword ptr [0x10008060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) goto L_00676dc5; /* je 0x676dc5 */
L_00676e54:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00676dc7; /* jmp 0x676dc7 */
}

void f_00676dc5(CPU *c) { /* PTR_00676dc5 */
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

void f_00676dfb(CPU *c) { /* PTR_00676dfb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00676dff(CPU *c) { /* PTR_00676dff */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov esi, dword ptr [ebp - 0x28] */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) { f_00676dc5(c); return; } /* je 0x676dc5 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780c8u)); PUSH32(c, 0x00676e25u); call_indirect(c, t_); } /* call dword ptr [0x100080c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00676dc5(c); return; } /* je 0x676dc5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), c->edi); /* cmp dword ptr [ebp + 0x1c], edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00676e34; /* jne 0x676e34 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00676e3a; /* jmp 0x676e3a */
L_00676e34:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
L_00676e3a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t t_ = R32((uint32_t)(0x678060u)); PUSH32(c, 0x00676e4au); call_indirect(c, t_); } /* call dword ptr [0x10008060] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (c->zf) { f_00676dc5(c); return; } /* je 0x676dc5 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { jump_indirect(c, 0x00676dc7u, 0x00676e56u); return; } /* jmp 0x676dc7 */
}

void f_00676e5b(CPU *c) { /* FUN_10006e5b */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea ecx, [edx - 1] */
    if (c->zf) goto L_00676e78; /* je 0x676e78 */
L_00676e6b:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00676e78; /* je 0x676e78 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00676e6b; /* jne 0x676e6b */
L_00676e78:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_00676e83; /* jne 0x676e83 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x4u)))); /* sub eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
L_00676e83:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->esp += 4; return; /* ret  */
}

void f_00676e86(CPU *c) { /* FUN_10006e86 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6785d8u; PUSH32(c, v_); } /* push 0x100085d8 */
    { uint32_t v_ = 0x67427cu; PUSH32(c, v_); } /* push 0x1000427c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->eax = (uint32_t)(R32((uint32_t)(0x67c22cu))); /* mov eax, dword ptr [0x1000c22c] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00676ef5; /* jne 0x676ef5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x6785b8u; PUSH32(c, v_); } /* push 0x100085b8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x6780d0u)); PUSH32(c, 0x00676ecbu); call_indirect(c, t_); } /* call dword ptr [0x100080d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676ed3; /* je 0x676ed3 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00676ef0; /* jmp 0x676ef0 */
L_00676ed3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x6785b4u; PUSH32(c, v_); } /* push 0x100085b4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x6780ccu)); PUSH32(c, 0x00676ee5u); call_indirect(c, t_); } /* call dword ptr [0x100080cc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00676fbb; /* je 0x676fbb */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00676ef0:;
    W32((uint32_t)(0x67c22cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000c22c], eax */
L_00676ef5:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00676f1e; /* jne 0x676f1e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00676f06; /* jne 0x676f06 */
    c->eax = (uint32_t)(R32((uint32_t)(0x67c210u))); /* mov eax, dword ptr [0x1000c210] */
L_00676f06:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6780ccu)); PUSH32(c, 0x00676f19u); call_indirect(c, t_); } /* call dword ptr [0x100080cc] */
    goto L_00676fbd; /* jmp 0x676fbd */
L_00676f1e:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00676fbb; /* jne 0x676fbb */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->ebx); /* cmp dword ptr [ebp + 0x18], ebx */
    if (!c->zf) goto L_00676f34; /* jne 0x676f34 */
    c->eax = (uint32_t)(R32((uint32_t)(0x67c220u))); /* mov eax, dword ptr [0x1000c220] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x18], eax */
L_00676f34:;
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
    { uint32_t t_ = R32((uint32_t)(0x6780c0u)); PUSH32(c, 0x00676f51u); call_indirect(c, t_); } /* call dword ptr [0x100080c0] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00676fbb; /* je 0x676fbb */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->eax)); /* lea edi, [eax + eax] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00676f6au); f_00676860(c); /* call 0x676860 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(c->esp); /* mov esi, esp */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00676f7au); f_00676a20(c); /* call 0x676a20 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00676f8a; /* jmp 0x676f8a */
L_00676f8a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00676fbb; /* je 0x676fbb */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0x6780c0u)); PUSH32(c, 0x00676fa7u); call_indirect(c, t_); } /* call dword ptr [0x100080c0] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00676fbb; /* je 0x676fbb */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780d0u)); PUSH32(c, 0x00676fb9u); call_indirect(c, t_); } /* call dword ptr [0x100080d0] */
    goto L_00676fbd; /* jmp 0x676fbd */
L_00676fbb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676fbd:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00676f7f(CPU *c) { /* PTR_00676f7f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00676f83(CPU *c) { /* PTR_00676f83 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00676fbb; /* je 0x676fbb */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t t_ = R32((uint32_t)(0x6780c0u)); PUSH32(c, 0x00676fa7u); call_indirect(c, t_); } /* call dword ptr [0x100080c0] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00676fbb; /* je 0x676fbb */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6780d0u)); PUSH32(c, 0x00676fb9u); call_indirect(c, t_); } /* call dword ptr [0x100080d0] */
    goto L_00676fbd; /* jmp 0x676fbd */
L_00676fbb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00676fbd:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00676fcf(CPU *c) { /* FUN_10006fcf */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00676fd4u); f_00672eb1(c); /* call 0x672eb1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00676fd8(CPU *c) { /* FUN_10006fd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x67c210u)), c->ebx); /* cmp dword ptr [0x1000c210], ebx */
    if (!c->zf) goto L_00676ff6; /* jne 0x676ff6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00677045; /* jl 0x677045 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00677045; /* jg 0x677045 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00676ff6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0x67c37cu); /* mov esi, 0x1000c37c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x6780d8u)); PUSH32(c, 0x00677004u); call_indirect(c, t_); } /* call dword ptr [0x100080d8] */
    (void)sub32(c, R32((uint32_t)(0x67c378u)), c->ebx); /* cmp dword ptr [0x1000c378], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0x6780d4u))); /* mov edi, dword ptr [0x100080d4] */
    if (c->zf) goto L_00677020; /* je 0x677020 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00677015u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0067701cu); f_00674867(c); /* call 0x674867 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00677020:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00677029u); f_00677047(c); /* call 0x677047 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_0067703c; /* je 0x67703c */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00677039u); f_006748c8(c); /* call 0x6748c8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0067703f; /* jmp 0x67703f */
L_0067703c:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x0067703fu); call_indirect(c, t_); } /* call edi */
L_0067703f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00677045:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00677047(CPU *c) { /* FUN_10007047 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x67c210u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000c210], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_00677072; /* jne 0x677072 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00677110; /* jl 0x677110 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00677110; /* jg 0x677110 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_00677110; /* jmp 0x677110 */
L_00677072:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_006770a5; /* jge 0x6770a5 */
    (void)sub32(c, R32((uint32_t)(0x67bca4u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000bca4], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00677092; /* jle 0x677092 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0067708eu); f_00677113(c); /* call 0x677113 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0067709d; /* jmp 0x67709d */
L_00677092:;
    c->eax = (uint32_t)(R32((uint32_t)(0x67ba98u))); /* mov eax, dword ptr [0x1000ba98] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_0067709d:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006770a5; /* jne 0x6770a5 */
L_006770a1:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00677110; /* jmp 0x677110 */
L_006770a5:;
    c->edx = (uint32_t)(R32((uint32_t)(0x67ba98u))); /* mov edx, dword ptr [0x1000ba98] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_006770c8; /* je 0x6770c8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_006770d1; /* jmp 0x6770d1 */
L_006770c8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_006770d1:;
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
    { uint32_t v_ = R32((uint32_t)(0x67c210u)); PUSH32(c, v_); } /* push dword ptr [0x1000c210] */
    PUSH32(c, 0x006770f1u); f_00676c37(c); /* call 0x676c37 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006770a1; /* je 0x6770a1 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00677103; /* jne 0x677103 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00677110; /* jmp 0x677110 */
L_00677103:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00677110:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00677113(CPU *c) { /* FUN_10007113 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_00677131; /* ja 0x677131 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x67ba98u))); /* mov ecx, dword ptr [0x1000ba98] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_00677183; /* jmp 0x677183 */
L_00677131:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x67ba98u))); /* mov esi, dword ptr [0x1000ba98] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00677156; /* je 0x677156 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_0067715f; /* jmp 0x67715f */
L_00677156:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_0067715f:;
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
    PUSH32(c, 0x00677176u); f_00676e86(c); /* call 0x676e86 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0067717f; /* jne 0x67717f */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_0067717f:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_00677183:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00677190(CPU *c) { /* FUN_10007190 */
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
L_006771a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006771b1; /* je 0x6771b1 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_006771a4; /* jmp 0x6771a4 */
L_006771b1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    ; /* nop  */
L_006771b8:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006771c6; /* je 0x6771c6 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_006771b8; /* jae 0x6771b8 */
L_006771c6:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006771d0(CPU *c) { /* FUN_100071d0 */
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
L_006771e4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006771f1; /* je 0x6771f1 */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; W32(a_, v_ | (1u << k_)); } /* bts dword ptr [esp], eax */
    goto L_006771e4; /* jmp 0x6771e4 */
L_006771f1:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
L_006771f4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00677204; /* je 0x677204 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { int32_t b_ = (int32_t)(c->eax); uint32_t a_ = (uint32_t)(c->esp) + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1; } /* bt dword ptr [esp], eax */
    if (!c->cf) goto L_006771f4; /* jae 0x6771f4 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea eax, [esi - 1] */
L_00677204:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00677210(CPU *c) { /* FUN_10007210 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0x67c208u)); /* lea eax, [0x1000c208] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00677263; /* jne 0x677263 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_0067722c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0067725e; /* je 0x67725e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_0067722c; /* je 0x67722c */
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
    if (c->zf) goto L_0067722c; /* je 0x67722c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_0067725e:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_006772db; /* jmp 0x6772db */
L_00677263:;
    { guest_lock(); guest_trap(c, 0x00677263u, "unsupported: lock inc dword ptr [0x1000c37c]"); guest_unlock(); } /* lock inc dword ptr [0x1000c37c] */
    (void)sub32(c, R32((uint32_t)(0x67c378u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000c378], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00677277; /* jg 0x677277 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_0067728c; /* jmp 0x67728c */
L_00677277:;
    { guest_lock(); guest_trap(c, 0x00677277u, "unsupported: lock dec dword ptr [0x1000c37c]"); guest_unlock(); } /* lock dec dword ptr [0x1000c37c] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00677285u); f_00674867(c); /* call 0x674867 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_0067728c:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_00677294:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006772bf; /* je 0x6772bf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00677294; /* je 0x677294 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006772a9u); f_006774d5(c); /* call 0x6774d5 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x006772b3u); f_006774d5(c); /* call 0x6774d5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_00677294; /* je 0x677294 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_006772bf:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_006772cf; /* jne 0x6772cf */
    { guest_lock(); guest_trap(c, 0x006772c6u, "unsupported: lock dec dword ptr [0x1000c37c]"); guest_unlock(); } /* lock dec dword ptr [0x1000c37c] */
    goto L_006772d9; /* jmp 0x6772d9 */
L_006772cf:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006772d6u); f_006748c8(c); /* call 0x6748c8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_006772d9:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_006772db:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006772e0(CPU *c) { /* FUN_100072e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_006773da; /* je 0x6773da */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0x67c208u)); /* lea eax, [0x1000c208] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_00677351; /* jne 0x677351 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_0067730c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_00677335; /* je 0x677335 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00677335; /* je 0x677335 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_00677324; /* jb 0x677324 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_00677324; /* ja 0x677324 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_00677324:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_0067732e; /* jb 0x67732e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_0067732e; /* ja 0x67732e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_0067732e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_0067733f; /* jne 0x67733f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0067730c; /* jne 0x67730c */
L_00677335:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_006773da; /* je 0x6773da */
L_0067733f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_006773da; /* jb 0x6773da */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_006773da; /* jmp 0x6773da */
L_00677351:;
    { guest_lock(); guest_trap(c, 0x00677351u, "unsupported: lock inc dword ptr [0x1000c37c]"); guest_unlock(); } /* lock inc dword ptr [0x1000c37c] */
    (void)sub32(c, R32((uint32_t)(0x67c378u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000c378], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00677365; /* jg 0x677365 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_0067737e; /* jmp 0x67737e */
L_00677365:;
    { guest_lock(); guest_trap(c, 0x00677365u, "unsupported: lock dec dword ptr [0x1000c37c]"); guest_unlock(); } /* lock dec dword ptr [0x1000c37c] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00677375u); f_00674867(c); /* call 0x674867 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_0067737e:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00677384:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_006773af; /* je 0x6773af */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_006773af; /* je 0x6773af */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0067739au); f_006774d5(c); /* call 0x6774d5 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x006773a4u); f_006774d5(c); /* call 0x6774d5 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_006773b5; /* jne 0x6773b5 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00677384; /* jne 0x677384 */
L_006773af:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_006773be; /* je 0x6773be */
L_006773b5:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_006773be; /* jb 0x6773be */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_006773be:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_006773cc; /* jne 0x6773cc */
    { guest_lock(); guest_trap(c, 0x006773c3u, "unsupported: lock dec dword ptr [0x1000c37c]"); guest_unlock(); } /* lock dec dword ptr [0x1000c37c] */
    goto L_006773da; /* jmp 0x6773da */
L_006773cc:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006773d5u); f_006748c8(c); /* call 0x6748c8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_006773da:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006773f0(CPU *c) { /* PTR_006773f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00677412; /* jne 0x677412 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00677404u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0067740cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00677453; /* jmp 0x677453 */
L_00677412:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
L_00677420:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_00677420; /* jne 0x677420 */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0067742cu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x18u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    { uint64_t r_ = (uint64_t)c->eax * c->esi; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul esi */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_0067744e; /* jb 0x67744e */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0x10u))); /* cmp edx, dword ptr [esp + 0x10] */
    if ((!c->cf && !c->zf)) goto L_0067744e; /* ja 0x67744e */
    if (c->cf) goto L_0067744f; /* jb 0x67744f */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0xcu))); /* cmp eax, dword ptr [esp + 0xc] */
    if ((c->cf || c->zf)) goto L_0067744f; /* jbe 0x67744f */
L_0067744e:;
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
L_0067744f:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00677453:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_00677460(CPU *c) { /* PTR_00677460 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_00677481; /* jne 0x677481 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00677473u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t d_ = c->ecx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x00677479u, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ecx */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_006774d1; /* jmp 0x6774d1 */
L_00677481:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
L_0067748f:;
    c->ecx = (uint32_t)(shr32(c, c->ecx, 1)); /* shr ecx, 1 */
    c->ebx = (uint32_t)(rcr32(c, c->ebx, 1)); /* rcr ebx, 1 */
    c->edx = (uint32_t)(shr32(c, c->edx, 1)); /* shr edx, 1 */
    c->eax = (uint32_t)(rcr32(c, c->eax, 1)); /* rcr eax, 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (!c->zf) goto L_0067748f; /* jne 0x67748f */
    { uint32_t d_ = c->ebx; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; if (!d_) guest_trap(c, 0x0067749bu, "divide by zero"); c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); } /* div ebx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x14u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x14] */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint64_t r_ = (uint64_t)c->eax * R32((uint32_t)(c->esp + 0x10u)); c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    if (c->cf) goto L_006774ba; /* jb 0x6774ba */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esp + 0xcu))); /* cmp edx, dword ptr [esp + 0xc] */
    if ((!c->cf && !c->zf)) goto L_006774ba; /* ja 0x6774ba */
    if (c->cf) goto L_006774c2; /* jb 0x6774c2 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u))); /* cmp eax, dword ptr [esp + 8] */
    if ((c->cf || c->zf)) goto L_006774c2; /* jbe 0x6774c2 */
L_006774ba:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x10u)))); /* sub eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0x14u)))); /* sbb edx, dword ptr [esp + 0x14] */
L_006774c2:;
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->esp + 0x8u)))); /* sub eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(sbb32(c, c->edx, R32((uint32_t)(c->esp + 0xcu)))); /* sbb edx, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(sbb32(c, c->edx, (uint32_t)0x0u)); /* sbb edx, 0 */
L_006774d1:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006774d5(CPU *c) { /* FUN_100074d5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x67c210u)), (uint32_t)0x0u); /* cmp dword ptr [0x1000c210], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00677502; /* jne 0x677502 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_0067759b; /* jl 0x67759b */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_0067759b; /* jg 0x67759b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_0067759b; /* jmp 0x67759b */
L_00677502:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_00677536; /* jge 0x677536 */
    (void)sub32(c, R32((uint32_t)(0x67bca4u)), c->esi); /* cmp dword ptr [0x1000bca4], esi */
    if ((c->zf || c->sf != c->of)) goto L_00677524; /* jle 0x677524 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00677520u); f_00677113(c); /* call 0x677113 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_0067752e; /* jmp 0x67752e */
L_00677524:;
    c->eax = (uint32_t)(R32((uint32_t)(0x67ba98u))); /* mov eax, dword ptr [0x1000ba98] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_0067752e:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00677536; /* jne 0x677536 */
L_00677532:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_0067759b; /* jmp 0x67759b */
L_00677536:;
    c->edx = (uint32_t)(R32((uint32_t)(0x67ba98u))); /* mov edx, dword ptr [0x1000ba98] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_0067755a; /* je 0x67755a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00677563; /* jmp 0x677563 */
L_0067755a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00677563:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x67c210u)); PUSH32(c, v_); } /* push dword ptr [0x1000c210] */
    PUSH32(c, 0x0067757du); f_00676c37(c); /* call 0x676c37 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00677532; /* je 0x677532 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0067758e; /* jne 0x67758e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_0067759b; /* jmp 0x67759b */
L_0067758e:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_0067759b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00677541(CPU *c) { /* PTR_00677541 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_0067755a; /* je 0x67755a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00677563; /* jmp 0x677563 */
L_0067755a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00677563:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x67c210u)); PUSH32(c, v_); } /* push dword ptr [0x1000c210] */
    PUSH32(c, 0x0067757du); f_00676c37(c); /* call 0x676c37 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { jump_indirect(c, 0x00677532u, 0x00677582u); return; } /* je 0x677532 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_0067758e; /* jne 0x67758e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_0067759b; /* jmp 0x67759b */
L_0067758e:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_0067759b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006775a0(CPU *c) { /* PTR_006775a0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_006775b9; /* jne 0x6775b9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_006775b9:;
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

void f_006775d4(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x678000u)); switch (t_) {  default: jump_indirect(c, t_, 0x006775d4u); return; } } /* jmp dword ptr [0x10008000] */
}

void f_006775e0(CPU *c) { /* Unwind@100075e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = 0x679048u; PUSH32(c, v_); } /* push 0x10009048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006775f0u); f_00671030(c); /* call 0x671030 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006775f4(CPU *c) { /* PTR_006775f4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x678750u); /* mov eax, 0x10008750 */
    { f_00672011(c); return; } /* jmp 0x672011 */
}
