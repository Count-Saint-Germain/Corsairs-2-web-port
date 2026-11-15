#include "recomp.h"

void f_00c99f0c(CPU *c) { /* PTR_00c99f0c */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if (!c->zf) goto L_00c99f25; /* jne 0xc99f25 */
L_00c99f18:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00c99f25; /* jne 0xc99f25 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00c99f18; /* jmp 0xc99f18 */
L_00c99f25:;
    (void)sub32(c, R32((uint32_t)(0xc9f330u)), c->edx); /* cmp dword ptr [0x1000f330], edx */
    if ((c->zf || c->sf != c->of)) goto L_00c99f3e; /* jle 0xc99f3e */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c99f37u); f_00c9723b(c); /* call 0xc9723b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00c99f4c; /* jmp 0xc99f4c */
L_00c99f3e:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xc9f33cu))); /* mov ecx, dword ptr [0x1000f33c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00c99f4c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00c99f6c; /* je 0xc99f6c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x19u); /* cmp dword ptr [ebp - 4], 0x19 */
    if (!c->cf) goto L_00c99f67; /* jae 0xc99f67 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u)); /* sub bl, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
L_00c99f67:;
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00c99f25; /* jmp 0xc99f25 */
L_00c99f6c:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2bu); /* cmp bl, 0x2b */
    if (c->zf) { jump_indirect(c, 0x00c99e7fu, 0x00c99f6fu); return; } /* je 0xc99e7f */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2du); /* cmp bl, 0x2d */
    if (c->zf) { jump_indirect(c, 0x00c99e7fu, 0x00c99f78u); return; } /* je 0xc99e7f */
    { jump_indirect(c, 0x00c99e58u, 0x00c99f7eu); return; } /* jmp 0xc99e58 */
}

void f_00c99f83(CPU *c) { /* PTR_00c99f83 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0xc9f330u)), c->edx); /* cmp dword ptr [0x1000f330], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    if ((c->zf || c->sf != c->of)) goto L_00c99f9f; /* jle 0xc99f9f */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c99f98u); f_00c9723b(c); /* call 0xc9723b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    goto L_00c99fad; /* jmp 0xc99fad */
L_00c99f9f:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xc9f33cu))); /* mov ecx, dword ptr [0x1000f33c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00c99fad:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00c9a05f; /* je 0xc9a05f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00c9a010; /* jmp 0xc9a010 */
L_00c9a010:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a05f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00c9a0ef; /* jmp 0xc9a0ef */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c99fb9(CPU *c) { /* PTR_00c99fb9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xfffffffeu)); /* lea ecx, [edi - 2] */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if ((c->sf != c->of)) goto L_00c99fc9; /* jl 0xc99fc9 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a00d; /* jle 0xc9a00d */
L_00c99fc9:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_00c9a045; /* je 0xc9a045 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00c9a039; /* je 0xc9a039 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_00c9a0ed; /* jne 0xc9a0ed */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    goto L_00c9a047; /* jmp 0xc9a047 */
L_00c9a00d:;
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a039:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x18], 0xffffffff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a045:;
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
L_00c9a047:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a0ed:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c99fe2(CPU *c) { /* PTR_00c99fe2 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
L_00c99fe5:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00c99fef; /* jne 0xc99fef */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00c99fe5; /* jmp 0xc99fe5 */
L_00c99fef:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00c9a0ea; /* jl 0xc9a0ea */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9a0ea; /* jg 0xc9a0ea */
    goto L_00c9a00d; /* jmp 0xc9a00d */
L_00c9a00d:;
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a0ea:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00c9a0ef; /* jmp 0xc9a0ef */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c9a003(CPU *c) { /* PTR_00c9a003 */
    PREEMPT_POLL(c);
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x31u); /* cmp bl, 0x31 */
    if ((c->sf != c->of)) goto L_00c9a016; /* jl 0xc9a016 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x39u); /* cmp bl, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9a016; /* jg 0xc9a016 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a016:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x30u); /* cmp bl, 0x30 */
    if (!c->zf) goto L_00c9a05f; /* jne 0xc9a05f */
    { jump_indirect(c, 0x00c99fdeu, 0x00c9a01bu); return; } /* jmp 0xc99fde */
L_00c9a05f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00c9a0ef; /* jmp 0xc9a0ef */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c9a01d(CPU *c) { /* PTR_00c9a01d */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    if (c->zf) goto L_00c9a04d; /* je 0xc9a04d */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea ecx, [edi - 1] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x10], ecx */
    if (c->zf) goto L_00c9a045; /* je 0xc9a045 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00c9a0ed; /* jne 0xc9a0ed */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x18], 0xffffffff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a045:;
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a04d:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if (c->zf) goto L_00c9a0ef; /* je 0xc9a0ef */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a0ed:;
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c9a051(CPU *c) { /* PTR_00c9a051 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0xau); /* cmp eax, 0xa */
    if (c->zf) goto L_00c9a0ef; /* je 0xc9a0ef */
    { f_00c99dce(c); return; } /* jmp 0xc99dce */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c9a05f(CPU *c) { /* PTR_00c9a05f */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    goto L_00c9a0ef; /* jmp 0xc9a0ef */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c9a067(CPU *c) { /* PTR_00c9a067 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_00c9a070:;
    (void)sub32(c, R32((uint32_t)(0xc9f330u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000f330], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a088; /* jle 0xc9a088 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a084u); f_00c9723b(c); /* call 0xc9723b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00c9a097; /* jmp 0xc9a097 */
L_00c9a088:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xc9f33cu))); /* mov ecx, dword ptr [0x1000f33c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00c9a097:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00c9a0b7; /* je 0xc9a0b7 */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea esi, [ecx + eax*2 - 0x30] */
    (void)sub32(c, c->esi, (uint32_t)0x1450u); /* cmp esi, 0x1450 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9a0b2; /* jg 0xc9a0b2 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00c9a070; /* jmp 0xc9a070 */
L_00c9a0b2:;
    c->esi = (uint32_t)((uint32_t)0x1451u); /* mov esi, 0x1451 */
L_00c9a0b7:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
L_00c9a0ba:;
    (void)sub32(c, R32((uint32_t)(0xc9f330u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000f330], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a0d2; /* jle 0xc9a0d2 */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a0ceu); f_00c9723b(c); /* call 0xc9723b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00c9a0e1; /* jmp 0xc9a0e1 */
L_00c9a0d2:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xc9f33cu))); /* mov ecx, dword ptr [0x1000f33c] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00c9a0e1:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00c9a0ea; /* je 0xc9a0ea */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00c9a0ba; /* jmp 0xc9a0ba */
L_00c9a0ea:;
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    goto L_00c9a0ef; /* jmp 0xc9a0ef */
L_00c9a0ef:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    W32((uint32_t)(c->eax), (uint32_t)(c->edi)); /* mov dword ptr [eax], edi */
    if (c->zf) goto L_00c9a1d7; /* je 0xc9a1d7 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if ((c->cf || c->zf)) goto L_00c9a11b; /* jbe 0xc9a11b */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffffbbu)), (uint8_t)0x5u); /* cmp byte ptr [ebp - 0x45], 5 */
    if ((c->sf != c->of)) goto L_00c9a10f; /* jl 0xc9a10f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffbbu); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [ebp - 0x45] */
L_00c9a10f:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a11e; /* jmp 0xc9a11e */
L_00c9a11b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
L_00c9a11e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if ((c->cf || c->zf)) goto L_00c9a1cd; /* jbe 0xc9a1cd */
L_00c9a128:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (!c->zf) goto L_00c9a136; /* jne 0xc9a136 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    goto L_00c9a128; /* jmp 0xc9a128 */
L_00c9a136:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffa4u)); /* lea eax, [ebp - 0x5c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a146u); f_00c99cb0(c); /* call 0xc99cb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), c->ecx); /* cmp dword ptr [ebp - 0x18], ecx */
    if ((c->sf == c->of)) goto L_00c9a155; /* jge 0xc9a155 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_00c9a155:;
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ecx); /* cmp dword ptr [ebp - 0x20], ecx */
    if (!c->zf) goto L_00c9a160; /* jne 0xc9a160 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0x18u)))); /* add eax, dword ptr [ebp + 0x18] */
L_00c9a160:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->ecx); /* cmp dword ptr [ebp - 0x24], ecx */
    if (!c->zf) goto L_00c9a168; /* jne 0xc9a168 */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x1cu)))); /* sub eax, dword ptr [ebp + 0x1c] */
L_00c9a168:;
    (void)sub32(c, c->eax, (uint32_t)0x1450u); /* cmp eax, 0x1450 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a19f; /* jle 0xc9a19f */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x2c], 1 */
L_00c9a176:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00c9a182:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00c9a1e8; /* je 0xc9a1e8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->eax = (uint32_t)((uint32_t)0x7fffu); /* mov eax, 0x7fff */
    c->esi = (uint32_t)((uint32_t)0x80000000u); /* mov esi, 0x80000000 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x14], 2 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a19f:;
    (void)sub32(c, c->eax, (uint32_t)0xffffebb0u); /* cmp eax, 0xffffebb0 */
    if ((c->sf == c->of)) goto L_00c9a1af; /* jge 0xc9a1af */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x30], 1 */
    goto L_00c9a176; /* jmp 0xc9a176 */
L_00c9a1af:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a1bcu); f_00c9af39(c); /* call 0xc9af39 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc2u))); /* mov ebx, dword ptr [ebp - 0x3e] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc6u))); /* mov esi, dword ptr [ebp - 0x3a] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffcau))); /* mov eax, dword ptr [ebp - 0x36] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1cd:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    goto L_00c9a182; /* jmp 0xc9a182 */
L_00c9a1d7:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [ebp - 0x14], 4 */
    goto L_00c9a1fd; /* jmp 0xc9a1fd */
L_00c9a1e8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x30], 0 */
    if (c->zf) goto L_00c9a1fd; /* je 0xc9a1fd */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x14], 1 */
L_00c9a1fd:;
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

void f_00c9a248(CPU *c) { /* FUN_1000a248 */
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
    if (c->zf) goto L_00c9a2aa; /* je 0xc9a2aa */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx + 2], 0x2d */
    goto L_00c9a2ae; /* jmp 0xc9a2ae */
L_00c9a2aa:;
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
L_00c9a2ae:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    if (!c->zf) goto L_00c9a2d4; /* jne 0xc9a2d4 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00c9a2d4; /* jne 0xc9a2d4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    if (!c->zf) goto L_00c9a2d4; /* jne 0xc9a2d4 */
L_00c9a2bf:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ebx + 0x4u), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebx + 4], 0x30 */
    goto L_00c9a4d2; /* jmp 0xc9a4d2 */
L_00c9a2d4:;
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->esi)); /* cmp dx, si */
    if (!c->zf) goto L_00c9a353; /* jne 0xc9a353 */
    c->eax = (uint32_t)((uint32_t)0x80000000u); /* mov eax, 0x80000000 */
    W16((uint32_t)(c->ebx), (uint16_t)((uint16_t)0x1u)); /* mov word ptr [ebx], 1 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00c9a2ed; /* jne 0xc9a2ed */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00c9a2fc; /* je 0xc9a2fc */
L_00c9a2ed:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x40000000u)); /* test edi, 0x40000000 */
    if (!c->zf) goto L_00c9a2fc; /* jne 0xc9a2fc */
    { uint32_t v_ = 0xc9c640u; PUSH32(c, v_); } /* push 0x1000c640 */
    goto L_00c9a342; /* jmp 0xc9a342 */
L_00c9a2fc:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->ecx) & ((uint16_t)c->ecx))); /* test cx, cx */
    if (c->zf) goto L_00c9a316; /* je 0xc9a316 */
    (void)sub32(c, c->edi, (uint32_t)0xc0000000u); /* cmp edi, 0xc0000000 */
    if (!c->zf) goto L_00c9a316; /* jne 0xc9a316 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00c9a33d; /* jne 0xc9a33d */
    { uint32_t v_ = 0xc9c638u; PUSH32(c, v_); } /* push 0x1000c638 */
    goto L_00c9a325; /* jmp 0xc9a325 */
L_00c9a316:;
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->zf) goto L_00c9a33d; /* jne 0xc9a33d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00c9a33d; /* jne 0xc9a33d */
    { uint32_t v_ = 0xc9c630u; PUSH32(c, v_); } /* push 0x1000c630 */
L_00c9a325:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a32eu); f_00c97770(c); /* call 0xc97770 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x5u)); /* mov byte ptr [ebx + 3], 5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00c9a334:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    goto L_00c9a4ab; /* jmp 0xc9a4ab */
L_00c9a33d:;
    { uint32_t v_ = 0xc9c628u; PUSH32(c, v_); } /* push 0x1000c628 */
L_00c9a342:;
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a34bu); f_00c97770(c); /* call 0xc97770 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x6u)); /* mov byte ptr [ebx + 3], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00c9a334; /* jmp 0xc9a334 */
L_00c9a353:;
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
    PUSH32(c, 0x00c9a399u); f_00c9af39(c); /* call 0xc9af39 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xfffffffau)), (uint16_t)0x3fffu); /* cmp word ptr [ebp - 6], 0x3fff */
    if (c->cf) goto L_00c9a3b4; /* jb 0xc9a3b4 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe4u)); /* lea eax, [ebp - 0x1c] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a3b2u); f_00c9ad19(c); /* call 0xc9ad19 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00c9a3b4:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x18u)) & (uint8_t)0x1u)); /* test byte ptr [ebp + 0x18], 1 */
    W16((uint32_t)(c->ebx), (uint16_t)(((uint16_t)c->esi))); /* mov word ptr [ebx], si */
    if (c->zf) goto L_00c9a3ce; /* je 0xc9a3ce */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->esi)); /* movsx eax, si */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((!c->zf && c->sf == c->of)) goto L_00c9a3d1; /* jg 0xc9a3d1 */
    goto L_00c9a2bf; /* jmp 0xc9a2bf */
L_00c9a3ce:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edi, dword ptr [ebp + 0x14] */
L_00c9a3d1:;
    (void)sub32(c, c->edi, (uint32_t)0x15u); /* cmp edi, 0x15 */
    if ((c->zf || c->sf != c->of)) goto L_00c9a3d9; /* jle 0xc9a3d9 */
    { uint32_t v_ = 0x15u; PUSH32(c, v_); } /* push 0x15 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00c9a3d9:;
    c->esi = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xfffffffau))); /* movzx esi, word ptr [ebp - 6] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x3ffeu)); /* sub esi, 0x3ffe */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffau); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebp - 6], 0 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp + 0x1c], 8 */
L_00c9a3ef:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a3f8u); f_00c99c55(c); /* call 0xc99c55 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x1c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00c9a3ef; /* jne 0xc9a3ef */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00c9a419; /* jge 0xc9a419 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffu))); /* and esi, 0xff */
    if ((c->zf || c->sf != c->of)) goto L_00c9a419; /* jle 0xc9a419 */
L_00c9a40c:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a415u); f_00c99c83(c); /* call 0xc99c83 */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00c9a40c; /* jne 0xc9a40c */
L_00c9a419:;
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea ecx, [edi + 1] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea eax, [ebx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
    if ((c->zf || c->sf != c->of)) goto L_00c9a476; /* jle 0xc9a476 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x14], ecx */
L_00c9a429:;
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea esi, [ebp - 0x10] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea edi, [ebp + 8] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    PUSH32(c, 0x00c9a43bu); f_00c99c55(c); /* call 0xc99c55 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a444u); f_00c99c55(c); /* call 0xc99c55 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a451u); f_00c99bf7(c); /* call 0xc99bf7 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a45au); f_00c99c55(c); /* call 0xc99c55 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffbu))); /* mov al, byte ptr [ebp - 5] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffbu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 5], 0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x30u)); /* add al, 0x30 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x1cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x14u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x14] */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
    if (!c->zf) goto L_00c9a429; /* jne 0xc9a429 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
L_00c9a476:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xffffffffu))); /* mov cl, byte ptr [eax - 1] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x35u); /* cmp cl, 0x35 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea ecx, [ebx + 4] */
    if ((c->sf != c->of)) goto L_00c9a4b3; /* jl 0xc9a4b3 */
L_00c9a483:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00c9a496; /* jb 0xc9a496 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00c9a492; /* jne 0xc9a492 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00c9a483; /* jmp 0xc9a483 */
L_00c9a492:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00c9a49a; /* jae 0xc9a49a */
L_00c9a496:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebx] */
L_00c9a49a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00c9a49c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx))); /* sub al, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x3u)); /* sub al, 3 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebx + 3], al */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + ebx + 4], 0 */
L_00c9a4ab:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00c9a4ae:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00c9a4b3:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_00c9a4c3; /* jb 0xc9a4c3 */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (!c->zf) goto L_00c9a4bf; /* jne 0xc9a4bf */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00c9a4b3; /* jmp 0xc9a4b3 */
L_00c9a4bf:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00c9a49c; /* jae 0xc9a49c */
L_00c9a4c3:;
    { uint32_t a_ = (uint32_t)(c->ebx); W16(a_, (uint16_t)(logic16(c, (uint16_t)(R16(a_) & (uint16_t)0x0u)))); } /* and word ptr [ebx], 0 */
    W8((uint32_t)(c->ebx + 0x2u), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebx + 2], 0x20 */
    W8((uint32_t)(c->ebx + 0x3u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx + 3], 1 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_00c9a4d2:;
    { uint32_t a_ = (uint32_t)(c->ebx + 0x5u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebx + 5], 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00c9a4ae; /* jmp 0xc9a4ae */
}

void f_00c9a4db(CPU *c) { /* FUN_1000a4db */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    PUSH32(c, 0x00c9a4e2u); f_00c95a1a(c); /* call 0xc95a1a */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    PUSH32(c, 0x00c9a4e9u); f_00c9afb5(c); /* call 0xc9afb5 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00c9a4f2u); f_00c941e2(c); /* call 0xc941e2 */
    guest_trap(c, 0x00c9a4f2u, "int3"); /* int3  */
}

void f_00c9a4f4(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xc9a50cu; PUSH32(c, v_); } /* push 0x1000a50c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00c9a50cu); f_00c9b128(c); /* call 0xc9b128 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00c9a50c(CPU *c) { /* PTR_00c9a50c */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00c9a514(CPU *c) { /* PTR_00c9a514 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00c9a535; /* je 0xc9a535 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00c9a535:;
    c->esp += 4; return; /* ret  */
}

void f_00c9a536(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0xc9a514u; PUSH32(c, v_); } /* push 0x1000a514 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00c9a553:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00c9a590; /* je 0xc9a590 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_00c9a590; /* je 0xc9a590 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_00c9a58e; /* jne 0xc9a58e */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x00c9a58au); f_00c9a5ca(c); /* call 0xc9a5ca */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x00c9a58eu); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_00c9a58e:;
    goto L_00c9a553; /* jmp 0xc9a553 */
L_00c9a590:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00c9a59e(CPU *c) { /* PTR_00c9a59e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0xc9a514u); /* cmp dword ptr [ecx + 4], 0x1000a514 */
    if (!c->zf) goto L_00c9a5c0; /* jne 0xc9a5c0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00c9a5c0; /* jne 0xc9a5c0 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00c9a5c0:;
    c->esp += 4; return; /* ret  */
}

void f_00c9a5ca(CPU *c) { /* FUN_1000a5ca */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xc9f8a8u); /* mov ebx, 0x1000f8a8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00c9a5e4(CPU *c) { /* PTR_00c9a5e4 */
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
    if (!c->zf) goto L_00c9a68c; /* jne 0xc9a68c */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_00c9a61f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00c9a685; /* je 0xc9a685 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_00c9a673; /* je 0xc9a673 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x00c9a637u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00c9a673; /* je 0xc9a673 */
    if (c->sf) goto L_00c9a67e; /* js 0xc9a67e */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00c9a64bu); f_00c9a4f4(c); /* call 0xc9a4f4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00c9a658u); f_00c9a536(c); /* call 0xc9a536 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x00c9a669u); f_00c9a5ca(c); /* call 0xc9a5ca */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x00c9a673u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_00c9a673:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_00c9a61f; /* jmp 0xc9a61f */
L_00c9a67e:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00c9a6a1; /* jmp 0xc9a6a1 */
L_00c9a685:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00c9a6a1; /* jmp 0xc9a6a1 */
L_00c9a68c:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00c9a698u); f_00c9a536(c); /* call 0xc9a536 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00c9a6a1:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00c9a6a9(CPU *c) { /* FUN_1000a6a9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9a6bdu); f_00c9a536(c); /* call 0xc9a536 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_00c9a6c4(CPU *c) { /* FUN_1000a6c4 */
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
    if (c->zf) goto L_00c9a6f6; /* je 0xc9a6f6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008fu)); /* mov dword ptr [ebp + 0x10], 0xc000008f */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 4], ebx */
L_00c9a6f6:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (c->zf) goto L_00c9a709; /* je 0xc9a709 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000093u)); /* mov dword ptr [ebp + 0x10], 0xc0000093 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [eax + 4], 2 */
L_00c9a709:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ecx))); /* test bl, cl */
    if (c->zf) goto L_00c9a71b; /* je 0xc9a71b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000091u)); /* mov dword ptr [ebp + 0x10], 0xc0000091 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [eax + 4], 4 */
L_00c9a71b:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_00c9a72e; /* je 0xc9a72e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc000008eu)); /* mov dword ptr [ebp + 0x10], 0xc000008e */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [eax + 4], 8 */
L_00c9a72e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00c9a741; /* je 0xc9a741 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0xc0000090u)); /* mov dword ptr [ebp + 0x10], 0xc0000090 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [eax + 4], 0x10 */
L_00c9a741:;
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
    PUSH32(c, 0x00c9a7bfu); f_00c9abb7(c); /* call 0xc9abb7 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00c9a7ca; /* je 0xc9a7ca */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ecx + 0xc], 0x10 */
L_00c9a7ca:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00c9a7d5; /* je 0xc9a7d5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ecx + 0xc], 8 */
L_00c9a7d5:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (c->zf) goto L_00c9a7e0; /* je 0xc9a7e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ecx + 0xc], 4 */
L_00c9a7e0:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00c9a7ea; /* je 0xc9a7ea */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->edi)))); } /* or dword ptr [ecx + 0xc], edi */
L_00c9a7ea:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x20u)); /* test al, 0x20 */
    if (c->zf) goto L_00c9a7f4; /* je 0xc9a7f4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->ebx)))); } /* or dword ptr [eax + 0xc], ebx */
L_00c9a7f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0xc00u); /* mov ecx, 0xc00 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00c9a833; /* je 0xc9a833 */
    (void)sub32(c, c->eax, (uint32_t)0x400u); /* cmp eax, 0x400 */
    if (c->zf) goto L_00c9a825; /* je 0xc9a825 */
    (void)sub32(c, c->eax, (uint32_t)0x800u); /* cmp eax, 0x800 */
    if (c->zf) goto L_00c9a819; /* je 0xc9a819 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00c9a839; /* jne 0xc9a839 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x3u)))); } /* or dword ptr [eax], 3 */
    goto L_00c9a839; /* jmp 0xc9a839 */
L_00c9a819:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffeu))); /* and ecx, 0xfffffffe */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    goto L_00c9a82f; /* jmp 0xc9a82f */
L_00c9a825:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffdu))); /* and ecx, 0xfffffffd */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ebx))); /* or ecx, ebx */
L_00c9a82f:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    goto L_00c9a839; /* jmp 0xc9a839 */
L_00c9a833:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffcu)))); } /* and dword ptr [eax], 0xfffffffc */
L_00c9a839:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->ecx = (uint32_t)((uint32_t)0x300u); /* mov ecx, 0x300 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    if (c->zf) goto L_00c9a864; /* je 0xc9a864 */
    (void)sub32(c, c->eax, (uint32_t)0x200u); /* cmp eax, 0x200 */
    if (c->zf) goto L_00c9a857; /* je 0xc9a857 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00c9a871; /* jne 0xc9a871 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffe3u)))); } /* and dword ptr [eax], 0xffffffe3 */
    goto L_00c9a871; /* jmp 0xc9a871 */
L_00c9a857:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffe7u))); /* and ecx, 0xffffffe7 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x4u))); /* or ecx, 4 */
    goto L_00c9a86f; /* jmp 0xc9a86f */
L_00c9a864:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xffffffebu))); /* and ecx, 0xffffffeb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x8u))); /* or ecx, 8 */
L_00c9a86f:;
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_00c9a871:;
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
    PUSH32(c, 0x00c9a8cfu); f_00c9abc5(c); /* call 0xc9abc5 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t t_ = R32((uint32_t)(0xc9c000u)); PUSH32(c, 0x00c9a8dfu); call_indirect(c, t_); } /* call dword ptr [0x1000c000] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [eax + 8], 0x10 */
    if (c->zf) goto L_00c9a8eb; /* je 0xc9a8eb */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffeu)))); } /* and dword ptr [esi], 0xfffffffe */
L_00c9a8eb:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x8u)); /* test byte ptr [eax + 8], 8 */
    if (c->zf) goto L_00c9a8f4; /* je 0xc9a8f4 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffffbu)))); } /* and dword ptr [esi], 0xfffffffb */
L_00c9a8f4:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x4u)); /* test byte ptr [eax + 8], 4 */
    if (c->zf) goto L_00c9a8fd; /* je 0xc9a8fd */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [esi], 0xfffffff7 */
L_00c9a8fd:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & (uint8_t)0x2u)); /* test byte ptr [eax + 8], 2 */
    if (c->zf) goto L_00c9a906; /* je 0xc9a906 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffefu)))); } /* and dword ptr [esi], 0xffffffef */
L_00c9a906:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x8u)) & ((uint8_t)c->ebx))); /* test byte ptr [eax + 8], bl */
    if (c->zf) goto L_00c9a90e; /* je 0xc9a90e */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xffffffdfu)))); } /* and dword ptr [esi], 0xffffffdf */
L_00c9a90e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)0xfffff3ffu); /* mov edx, 0xfffff3ff */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00c9a942; /* je 0xc9a942 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00c9a936; /* je 0xc9a936 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00c9a92c; /* je 0xc9a92c */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00c9a944; /* jne 0xc9a944 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0xcu)))); } /* or byte ptr [esi + 1], 0xc */
    goto L_00c9a944; /* jmp 0xc9a944 */
L_00c9a92c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xfbu))) << 8); /* and ch, 0xfb */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x8u))) << 8); /* or ch, 8 */
    goto L_00c9a93e; /* jmp 0xc9a93e */
L_00c9a936:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xf7u))) << 8); /* and ch, 0xf7 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x4u))) << 8); /* or ch, 4 */
L_00c9a93e:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    goto L_00c9a944; /* jmp 0xc9a944 */
L_00c9a942:;
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
L_00c9a944:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7u))); /* and ecx, 7 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x0u)); /* sub ecx, 0 */
    if (c->zf) goto L_00c9a964; /* je 0xc9a964 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_00c9a95b; /* je 0xc9a95b */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00c9a96d; /* jne 0xc9a96d */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [esi], edx */
    goto L_00c9a96d; /* jmp 0xc9a96d */
L_00c9a95b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x2u))) << 8); /* or ch, 2 */
    goto L_00c9a96b; /* jmp 0xc9a96b */
L_00c9a964:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x3u))) << 8); /* or ch, 3 */
L_00c9a96b:;
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_00c9a96d:;
    FPUSH(c, RF64((uint32_t)(c->eax + 0x40u))); /* fld qword ptr [eax + 0x40] */
    WF64((uint32_t)(c->edi), ST(0)); FPOP(c); /* fstp qword ptr [edi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00c9a977(CPU *c) { /* FUN_1000a977 */
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
    if (c->zf) goto L_00c9a9a2; /* je 0xc9a9a2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp + 0x10], bl */
    if (c->zf) goto L_00c9a9a2; /* je 0xc9a9a2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00c9a999u); f_00c9abf7(c); /* call 0xc9abf7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffff7u))); /* and edi, 0xfffffff7 */
    goto L_00c9ab6c; /* jmp 0xc9ab6c */
L_00c9a9a2:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x4u)); /* test al, 4 */
    if (c->zf) goto L_00c9a9bc; /* je 0xc9a9bc */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x4u)); /* test byte ptr [ebp + 0x10], 4 */
    if (c->zf) goto L_00c9a9bc; /* je 0xc9a9bc */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x00c9a9b3u); f_00c9abf7(c); /* call 0xc9abf7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffbu))); /* and edi, 0xfffffffb */
    goto L_00c9ab6c; /* jmp 0xc9ab6c */
L_00c9a9bc:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->eax))); /* test bl, al */
    if (c->zf) goto L_00c9aa96; /* je 0xc9aa96 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x8u)); /* test byte ptr [ebp + 0x10], 8 */
    if (c->zf) goto L_00c9aa96; /* je 0xc9aa96 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00c9a9d5u); f_00c9abf7(c); /* call 0xc9abf7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)0xc00u); /* mov eax, 0xc00 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->eax))); /* and ecx, eax */
    if (c->zf) goto L_00c9aa6e; /* je 0xc9aa6e */
    (void)sub32(c, c->ecx, (uint32_t)0x400u); /* cmp ecx, 0x400 */
    if (c->zf) goto L_00c9aa46; /* je 0xc9aa46 */
    (void)sub32(c, c->ecx, (uint32_t)0x800u); /* cmp ecx, 0x800 */
    if (c->zf) goto L_00c9aa1e; /* je 0xc9aa1e */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (!c->zf) goto L_00c9aa8e; /* jne 0xc9aa8e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xc9c218u))); FPOP(c); /* fcomp qword ptr [0x1000c218] */
    FPUSH(c, RF64((uint32_t)(0xc9f700u))); /* fld qword ptr [0x1000f700] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00c9aa16; /* ja 0xc9aa16 */
    ST(0) = -ST(0); /* fchs  */
L_00c9aa16:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00c9aa8c; /* jmp 0xc9aa8c */
L_00c9aa1e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xc9c218u))); FPOP(c); /* fcomp qword ptr [0x1000c218] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00c9aa36; /* jbe 0xc9aa36 */
    FPUSH(c, RF64((uint32_t)(0xc9f6f0u))); /* fld qword ptr [0x1000f6f0] */
    goto L_00c9aa3e; /* jmp 0xc9aa3e */
L_00c9aa36:;
    FPUSH(c, RF64((uint32_t)(0xc9f700u))); /* fld qword ptr [0x1000f700] */
    ST(0) = -ST(0); /* fchs  */
L_00c9aa3e:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00c9aa8c; /* jmp 0xc9aa8c */
L_00c9aa46:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xc9c218u))); FPOP(c); /* fcomp qword ptr [0x1000c218] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00c9aa5e; /* jbe 0xc9aa5e */
    FPUSH(c, RF64((uint32_t)(0xc9f700u))); /* fld qword ptr [0x1000f700] */
    goto L_00c9aa66; /* jmp 0xc9aa66 */
L_00c9aa5e:;
    FPUSH(c, RF64((uint32_t)(0xc9f6f0u))); /* fld qword ptr [0x1000f6f0] */
    ST(0) = -ST(0); /* fchs  */
L_00c9aa66:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    goto L_00c9aa8c; /* jmp 0xc9aa8c */
L_00c9aa6e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    FCOM(c, ST(0), RF64((uint32_t)(0xc9c218u))); FPOP(c); /* fcomp qword ptr [0x1000c218] */
    FPUSH(c, RF64((uint32_t)(0xc9f6f0u))); /* fld qword ptr [0x1000f6f0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00c9aa86; /* ja 0xc9aa86 */
    ST(0) = -ST(0); /* fchs  */
L_00c9aa86:;
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
L_00c9aa8c:;
    WF64((uint32_t)(c->ecx), ST(0)); FPOP(c); /* fstp qword ptr [ecx] */
L_00c9aa8e:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffeu))); /* and edi, 0xfffffffe */
    goto L_00c9ab6c; /* jmp 0xc9ab6c */
L_00c9aa96:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00c9ab6c; /* je 0xc9ab6c */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 0x10], 0x10 */
    if (c->zf) goto L_00c9ab6c; /* je 0xc9ab6c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_00c9aab1; /* je 0xc9aab1 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00c9aab1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0xc9c218u))); FPOP(c); /* fcomp qword ptr [0x1000c218] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_00c9ab5a; /* je 0xc9ab5a */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00c9aadcu); f_00c98d7e(c); /* call 0xc98d7e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0xfffffa00u)); /* lea ecx, [eax - 0x600] */
    (void)sub32(c, c->ecx, (uint32_t)0xfffffbceu); /* cmp ecx, 0xfffffbce */
    if ((c->sf == c->of)) goto L_00c9aafc; /* jge 0xc9aafc */
    FPUSH(c, 0.0); /* fldz  */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
    goto L_00c9ab50; /* jmp 0xc9ab50 */
L_00c9aafc:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    FCOM(c, ST(0), RF64((uint32_t)(0xc9c218u))); FPOP(c); /* fcomp qword ptr [0x1000c218] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00c9ab0e; /* jae 0xc9ab0e */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    goto L_00c9ab10; /* jmp 0xc9ab10 */
L_00c9ab0e:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_00c9ab10:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffau))); /* mov al, byte ptr [ebp - 6] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
    W16((uint32_t)(c->ebp + 0xfffffffau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [ebp - 6], ax */
    c->eax = (uint32_t)((uint32_t)0xfffffc03u); /* mov eax, 0xfffffc03 */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf == c->of)) goto L_00c9ab44; /* jge 0xc9ab44 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
L_00c9ab27:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 0xc], bl */
    if (c->zf) goto L_00c9ab32; /* je 0xc9ab32 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00c9ab32; /* jne 0xc9ab32 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00c9ab32:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 0xc], 1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff8u)) & ((uint8_t)c->ebx))); /* test byte ptr [ebp - 8], bl */
    if (c->zf) goto L_00c9ab3e; /* je 0xc9ab3e */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
L_00c9ab3e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(shr32(c, R32(a_), 1))); } /* shr dword ptr [ebp - 8], 1 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_00c9ab27; /* jne 0xc9ab27 */
L_00c9ab44:;
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00c9ab50; /* je 0xc9ab50 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    ST(0) = -ST(0); /* fchs  */
    WF64((uint32_t)(c->ebp + 0xfffffff4u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0xc] */
L_00c9ab50:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff4u))); /* fld qword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_00c9ab5c; /* jmp 0xc9ab5c */
L_00c9ab5a:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
L_00c9ab5c:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00c9ab69; /* je 0xc9ab69 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00c9ab68u); f_00c9abf7(c); /* call 0xc9abf7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00c9ab69:;
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xfffffffdu))); /* and edi, 0xfffffffd */
L_00c9ab6c:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [ebp + 8], 0x10 */
    if (c->zf) goto L_00c9ab83; /* je 0xc9ab83 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0x10u)) & (uint8_t)0x20u)); /* test byte ptr [ebp + 0x10], 0x20 */
    if (c->zf) goto L_00c9ab83; /* je 0xc9ab83 */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x00c9ab7fu); f_00c9abf7(c); /* call 0xc9abf7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0xffffffefu))); /* and edi, 0xffffffef */
L_00c9ab83:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00c9ab8e(CPU *c) { /* FUN_1000ab8e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00c9aba9; /* je 0xc9aba9 */
    if ((c->zf || c->sf != c->of)) goto L_00c9abb3; /* jle 0xc9abb3 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9abb3; /* jg 0xc9abb3 */
    W32((uint32_t)(0xc9fd48u), (uint32_t)((uint32_t)0x22u)); /* mov dword ptr [0x1000fd48], 0x22 */
    c->esp += 4; return; /* ret  */
L_00c9aba9:;
    W32((uint32_t)(0xc9fd48u), (uint32_t)((uint32_t)0x21u)); /* mov dword ptr [0x1000fd48], 0x21 */
L_00c9abb3:;
    c->esp += 4; return; /* ret  */
}

void f_00c9abb4(CPU *c) { /* FUN_1000abb4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00c9abb7(CPU *c) { /* FUN_1000abb7 */
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

void f_00c9abc5(CPU *c) { /* FUN_1000abc5 */
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

void f_00c9abd4(CPU *c) { /* FUN_1000abd4 */
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

void f_00c9abf7(CPU *c) { /* FUN_1000abf7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1u)); /* test cl, 1 */
    if (c->zf) goto L_00c9ac0e; /* je 0xc9ac0e */
    FPUSH(c, RF80((uint32_t)(0xc9f994u))); /* fld xword ptr [0x1000f994] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)fpu_to_int32(c, ST(0))); FPOP(c); /* fistp dword ptr [ebp + 8] */
    ; /* wait  */
L_00c9ac0e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x8u)); /* test cl, 8 */
    if (c->zf) goto L_00c9ac23; /* je 0xc9ac23 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    FPUSH(c, RF80((uint32_t)(0xc9f994u))); /* fld xword ptr [0x1000f994] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
L_00c9ac23:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x10u)); /* test cl, 0x10 */
    if (c->zf) goto L_00c9ac32; /* je 0xc9ac32 */
    FPUSH(c, RF80((uint32_t)(0xc9f9a0u))); /* fld xword ptr [0x1000f9a0] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_00c9ac32:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x4u)); /* test cl, 4 */
    if (c->zf) goto L_00c9ac40; /* je 0xc9ac40 */
    FPUSH(c, 0.0); /* fldz  */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ; /* wait  */
L_00c9ac40:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x20u)); /* test cl, 0x20 */
    if (c->zf) goto L_00c9ac4b; /* je 0xc9ac4b */
    FPUSH(c, M_PI); /* fldpi  */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    ; /* wait  */
L_00c9ac4b:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00c9ac4d(CPU *c) { /* FUN_1000ac4d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xc9ff1cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1000ff1c], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    if (!c->zf) goto L_00c9ac78; /* jne 0xc9ac78 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x61u); /* cmp eax, 0x61 */
    if ((c->sf != c->of)) goto L_00c9ad16; /* jl 0xc9ad16 */
    (void)sub32(c, c->eax, (uint32_t)0x7au); /* cmp eax, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00c9ad16; /* jg 0xc9ad16 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    goto L_00c9ad16; /* jmp 0xc9ad16 */
L_00c9ac78:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ebx, (uint32_t)0x100u); /* cmp ebx, 0x100 */
    if ((c->sf == c->of)) goto L_00c9acab; /* jge 0xc9acab */
    (void)sub32(c, R32((uint32_t)(0xc9f330u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000f330], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00c9ac98; /* jle 0xc9ac98 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00c9ac94u); f_00c9723b(c); /* call 0xc9723b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00c9aca3; /* jmp 0xc9aca3 */
L_00c9ac98:;
    c->eax = (uint32_t)(R32((uint32_t)(0xc9f33cu))); /* mov eax, dword ptr [0x1000f33c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x2u))); /* and eax, 2 */
L_00c9aca3:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00c9acab; /* jne 0xc9acab */
L_00c9aca7:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00c9ad16; /* jmp 0xc9ad16 */
L_00c9acab:;
    c->edx = (uint32_t)(R32((uint32_t)(0xc9f33cu))); /* mov edx, dword ptr [0x1000f33c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00c9acce; /* je 0xc9acce */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00c9acd7; /* jmp 0xc9acd7 */
L_00c9acce:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00c9acd7:;
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
    { uint32_t v_ = R32((uint32_t)(0xc9ff1cu)); PUSH32(c, v_); } /* push dword ptr [0x1000ff1c] */
    PUSH32(c, 0x00c9acf7u); f_00c99987(c); /* call 0xc99987 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00c9aca7; /* je 0xc9aca7 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00c9ad09; /* jne 0xc9ad09 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00c9ad16; /* jmp 0xc9ad16 */
L_00c9ad09:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00c9ad16:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00c9ad19(CPU *c) { /* FUN_1000ad19 */
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
    if (!c->cf) goto L_00c9af19; /* jae 0xc9af19 */
    (void)sub16(c, ((uint16_t)c->ecx), (uint16_t)0x7fffu); /* cmp cx, 0x7fff */
    if (!c->cf) goto L_00c9af19; /* jae 0xc9af19 */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xbffdu); /* cmp dx, 0xbffd */
    if ((!c->cf && !c->zf)) goto L_00c9af19; /* ja 0xc9af19 */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x3fbfu); /* cmp dx, 0x3fbf */
    if ((!c->cf && !c->zf)) goto L_00c9ad82; /* ja 0xc9ad82 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00c9adbc; /* jmp 0xc9adbc */
L_00c9ad82:;
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & ((uint16_t)c->eax))); /* test ax, ax */
    c->edx = (uint32_t)((uint32_t)0x7fffffffu); /* mov edx, 0x7fffffff */
    if (!c->zf) goto L_00c9ada4; /* jne 0xc9ada4 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esi + 0x8u)) & c->edx)); /* test dword ptr [esi + 8], edx */
    if (!c->zf) goto L_00c9ada4; /* jne 0xc9ada4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), c->eax); /* cmp dword ptr [esi + 4], eax */
    if (!c->zf) goto L_00c9ada6; /* jne 0xc9ada6 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->eax); /* cmp dword ptr [esi], eax */
    if (!c->zf) goto L_00c9ada6; /* jne 0xc9ada6 */
    goto L_00c9af13; /* jmp 0xc9af13 */
L_00c9ada4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00c9ada6:;
    (void)sub16(c, ((uint16_t)c->ecx), ((uint16_t)c->eax)); /* cmp cx, ax */
    if (!c->zf) goto L_00c9adc9; /* jne 0xc9adc9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebx + 0x8u)) & c->edx)); /* test dword ptr [ebx + 8], edx */
    if (!c->zf) goto L_00c9adc9; /* jne 0xc9adc9 */
    (void)sub32(c, R32((uint32_t)(c->ebx + 0x4u)), c->eax); /* cmp dword ptr [ebx + 4], eax */
    if (!c->zf) goto L_00c9adc9; /* jne 0xc9adc9 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->eax); /* cmp dword ptr [ebx], eax */
    if (!c->zf) goto L_00c9adc9; /* jne 0xc9adc9 */
L_00c9adbc:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00c9af34; /* jmp 0xc9af34 */
L_00c9adc9:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [ebp + 0xc], 5 */
L_00c9add9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00c9ae2d; /* jle 0xc9ae2d */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x8u)); /* lea ecx, [ebx + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
L_00c9adf5:;
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
    PUSH32(c, 0x00c9ae13u); f_00c99bd6(c); /* call 0xc99bd6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00c9ae20; /* je 0xc9ae20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [eax] */
L_00c9ae20:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 8], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(sub32(c, R32(a_), (uint32_t)0x2u))); } /* sub dword ptr [ebp - 0xc], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_00c9adf5; /* jne 0xc9adf5 */
L_00c9ae2d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x2u))); } /* add dword ptr [ebp - 4], 2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9add9; /* jg 0xc9add9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xc002u))); } /* add dword ptr [ebp + 8], 0xc002 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00c9ae70; /* jle 0xc9ae70 */
L_00c9ae4b:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffe7u)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 0x19], 0x80 */
    if (!c->zf) goto L_00c9ae69; /* jne 0xc9ae69 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9ae5au); f_00c99c55(c); /* call 0xc99c55 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9ae4b; /* jg 0xc9ae4b */
L_00c9ae69:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00c9aea9; /* jg 0xc9aea9 */
L_00c9ae70:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0xffffu))); } /* add dword ptr [ebp + 8], 0xffff */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x0u); /* cmp word ptr [ebp + 8], 0 */
    if ((c->sf == c->of)) goto L_00c9aea9; /* jge 0xc9aea9 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->ebp + 0x8u))); /* movsx eax, word ptr [ebp + 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00c9ae89:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffdcu)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x24], 1 */
    if (c->zf) goto L_00c9ae92; /* je 0xc9ae92 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x14] */
L_00c9ae92:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00c9ae9bu); f_00c99c83(c); /* call 0xc99c83 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00c9ae89; /* jne 0xc9ae89 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_00c9aea9; /* je 0xc9aea9 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 0x24], 1 */
L_00c9aea9:;
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffdcu)), (uint16_t)0x8000u); /* cmp word ptr [ebp - 0x24], 0x8000 */
    if ((!c->cf && !c->zf)) goto L_00c9aec0; /* ja 0xc9aec0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1ffffu))); /* and eax, 0x1ffff */
    (void)sub32(c, c->eax, (uint32_t)0x18000u); /* cmp eax, 0x18000 */
    if (!c->zf) goto L_00c9aef5; /* jne 0xc9aef5 */
L_00c9aec0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdeu)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x22], -1 */
    if (!c->zf) goto L_00c9aef2; /* jne 0xc9aef2 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x22], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe2u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 0x1e], -1 */
    if (!c->zf) goto L_00c9aeed; /* jne 0xc9aeed */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1e], 0 */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffe6u)), (uint16_t)0xffffu); /* cmp word ptr [ebp - 0x1a], 0xffff */
    if (!c->zf) goto L_00c9aee7; /* jne 0xc9aee7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
    W16((uint32_t)(c->ebp + 0xffffffe6u), (uint16_t)((uint16_t)0x8000u)); /* mov word ptr [ebp - 0x1a], 0x8000 */
    goto L_00c9aef5; /* jmp 0xc9aef5 */
L_00c9aee7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe6u); W16(a_, (uint16_t)(inc16(c, R16(a_)))); } /* inc word ptr [ebp - 0x1a] */
    goto L_00c9aef5; /* jmp 0xc9aef5 */
L_00c9aeed:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe2u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1e] */
    goto L_00c9aef5; /* jmp 0xc9aef5 */
L_00c9aef2:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdeu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x22] */
L_00c9aef5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7fffu); /* cmp ax, 0x7fff */
    if (!c->cf) goto L_00c9af19; /* jae 0xc9af19 */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffdeu))); /* mov cx, word ptr [ebp - 0x22] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [esi], cx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->esi + 0x2u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 2], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->esi + 0x6u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 6], ecx */
L_00c9af13:;
    W16((uint32_t)(c->esi + 0xau), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 0xa], ax */
    goto L_00c9af34; /* jmp 0xc9af34 */
L_00c9af19:;
    c->edi = (c->edi & 0xffff0000u) | (uint16_t)(neg16(c, ((uint16_t)c->edi))); /* neg di */
    c->edi = (uint32_t)(sbb32(c, c->edi, c->edi)); /* sbb edi, edi */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x80000000u))); /* and edi, 0x80000000 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x7fff8000u)); /* add edi, 0x7fff8000 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
L_00c9af34:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00c9af39(CPU *c) { /* FUN_1000af39 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)((uint32_t)0xc9f9b0u); /* mov ebx, 0x1000f9b0 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00c9afb2; /* je 0xc9afb2 */
    if ((c->sf == c->of)) goto L_00c9af61; /* jge 0xc9af61 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)((uint32_t)0xc9fb10u); /* mov ebx, 0x1000fb10 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    c->ebx = (uint32_t)(sub32(c, c->ebx, (uint32_t)0x60u)); /* sub ebx, 0x60 */
L_00c9af61:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ecx); /* cmp dword ptr [ebp + 0x10], ecx */
    if (!c->zf) goto L_00c9af6c; /* jne 0xc9af6c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
L_00c9af6c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (c->zf) goto L_00c9afb2; /* je 0xc9afb2 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00c9af73:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x54u)); /* add ebx, 0x54 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(sar32(c, R32(a_), 3))); } /* sar dword ptr [ebp + 0xc], 3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00c9afab; /* je 0xc9afab */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    (void)sub16(c, R16((uint32_t)(c->ebx + c->eax * 4)), (uint16_t)0x8000u); /* cmp word ptr [ebx + eax*4], 0x8000 */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea esi, [ebx + eax*4] */
    if (c->cf) goto L_00c9af9e; /* jb 0xc9af9e */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff6u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xa] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea esi, [ebp - 0xc] */
L_00c9af9e:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00c9afa7u); f_00c9ad19(c); /* call 0xc9ad19 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00c9afab:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_00c9af73; /* jne 0xc9af73 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00c9afb2:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00c9afb5(CPU *c) { /* FUN_1000afb5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00c9b01c; /* je 0xc9b01c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00c9b00d; /* je 0xc9b00d */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00c9b00d; /* je 0xc9b00d */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_00c9b00d; /* je 0xc9b00d */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x4u)); /* sub eax, 4 */
    if (c->zf) goto L_00c9b000; /* je 0xc9b000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (c->zf) goto L_00c9aff3; /* je 0xc9aff3 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_00c9afe6; /* je 0xc9afe6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00c9b0de; /* jmp 0xc9b0de */
L_00c9afe6:;
    c->esi = (uint32_t)(R32((uint32_t)(0xc9ff3cu))); /* mov esi, dword ptr [0x1000ff3c] */
    c->eax = (uint32_t)((uint32_t)0xc9ff3cu); /* mov eax, 0x1000ff3c */
    goto L_00c9b027; /* jmp 0xc9b027 */
L_00c9aff3:;
    c->esi = (uint32_t)(R32((uint32_t)(0xc9ff38u))); /* mov esi, dword ptr [0x1000ff38] */
    c->eax = (uint32_t)((uint32_t)0xc9ff38u); /* mov eax, 0x1000ff38 */
    goto L_00c9b027; /* jmp 0xc9b027 */
L_00c9b000:;
    c->esi = (uint32_t)(R32((uint32_t)(0xc9ff40u))); /* mov esi, dword ptr [0x1000ff40] */
    c->eax = (uint32_t)((uint32_t)0xc9ff40u); /* mov eax, 0x1000ff40 */
    goto L_00c9b027; /* jmp 0xc9b027 */
L_00c9b00d:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00c9b013u); f_00c9b0e2(c); /* call 0xc9b0e2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov esi, dword ptr [eax + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00c9b027; /* jmp 0xc9b027 */
L_00c9b01c:;
    c->esi = (uint32_t)(R32((uint32_t)(0xc9ff34u))); /* mov esi, dword ptr [0x1000ff34] */
    c->eax = (uint32_t)((uint32_t)0xc9ff34u); /* mov eax, 0x1000ff34 */
L_00c9b027:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (!c->zf) goto L_00c9b033; /* jne 0xc9b033 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00c9b0de; /* jmp 0xc9b0de */
L_00c9b033:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00c9b03e; /* jne 0xc9b03e */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    PUSH32(c, 0x00c9b03eu); f_00c941e2(c); /* call 0xc941e2 */
L_00c9b03e:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if (c->zf) goto L_00c9b050; /* je 0xc9b050 */
    (void)sub32(c, c->edi, (uint32_t)0xbu); /* cmp edi, 0xb */
    if (c->zf) goto L_00c9b050; /* je 0xc9b050 */
    (void)sub32(c, c->edi, (uint32_t)0x4u); /* cmp edi, 4 */
    if (!c->zf) goto L_00c9b076; /* jne 0xc9b076 */
L_00c9b050:;
    c->ebx = (uint32_t)(R32((uint32_t)(0xc9ff08u))); /* mov ebx, dword ptr [0x1000ff08] */
    { uint32_t a_ = (uint32_t)(0xc9ff08u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1000ff08], 0 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if (!c->zf) goto L_00c9b0a5; /* jne 0xc9b0a5 */
    c->edx = (uint32_t)(R32((uint32_t)(0xc9f8a4u))); /* mov edx, dword ptr [0x1000f8a4] */
    W32((uint32_t)(0xc9f8a4u), (uint32_t)((uint32_t)0x8cu)); /* mov dword ptr [0x1000f8a4], 0x8c */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 8], edx */
    goto L_00c9b079; /* jmp 0xc9b079 */
L_00c9b076:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00c9b079:;
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if (!c->zf) goto L_00c9b0a5; /* jne 0xc9b0a5 */
    c->eax = (uint32_t)(R32((uint32_t)(0xc9f898u))); /* mov eax, dword ptr [0x1000f898] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xc9f89cu))); /* mov ecx, dword ptr [0x1000f89c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_00c9b0ac; /* jge 0xc9b0ac */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edx = (uint32_t)((uint32_t)(c->edx * 4 + 0xc9f828u)); /* lea edx, [edx*4 + 0x1000f828] */
L_00c9b09a:;
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edx], 0 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00c9b09a; /* jne 0xc9b09a */
    goto L_00c9b0ac; /* jmp 0xc9b0ac */
L_00c9b0a5:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    (void)sub32(c, c->edi, c->ecx); /* cmp edi, ecx */
    if (!c->zf) goto L_00c9b0ba; /* jne 0xc9b0ba */
L_00c9b0ac:;
    { uint32_t v_ = R32((uint32_t)(0xc9f8a4u)); PUSH32(c, v_); } /* push dword ptr [0x1000f8a4] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00c9b0b6u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00c9b0c8; /* jmp 0xc9b0c8 */
L_00c9b0ba:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00c9b0bdu); call_indirect(c, t_); } /* call esi */
    (void)sub32(c, c->edi, (uint32_t)0xbu); /* cmp edi, 0xb */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00c9b0c8; /* je 0xc9b0c8 */
    (void)sub32(c, c->edi, (uint32_t)0x4u); /* cmp edi, 4 */
    if (!c->zf) goto L_00c9b0db; /* jne 0xc9b0db */
L_00c9b0c8:;
    (void)sub32(c, c->edi, (uint32_t)0x8u); /* cmp edi, 8 */
    W32((uint32_t)(0xc9ff08u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000ff08], ebx */
    if (!c->zf) goto L_00c9b0db; /* jne 0xc9b0db */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(0xc9f8a4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000f8a4], eax */
L_00c9b0db:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00c9b0de:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00c9b0e2(CPU *c) { /* FUN_1000b0e2 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xc9f8a0u))); /* mov ecx, dword ptr [0x1000f8a0] */
    (void)sub32(c, R32((uint32_t)(0xc9f824u)), c->edx); /* cmp dword ptr [0x1000f824], edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)0xc9f820u); /* mov eax, 0x1000f820 */
    if (c->zf) goto L_00c9b110; /* je 0xc9b110 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea esi, [ecx + ecx*2] */
    c->esi = (uint32_t)((uint32_t)(c->esi * 4 + 0xc9f820u)); /* lea esi, [esi*4 + 0x1000f820] */
L_00c9b104:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00c9b110; /* jae 0xc9b110 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->edx); /* cmp dword ptr [eax + 4], edx */
    if (!c->zf) goto L_00c9b104; /* jne 0xc9b104 */
L_00c9b110:;
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea ecx, [ecx + ecx*2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ecx = (uint32_t)((uint32_t)(c->ecx * 4 + 0xc9f820u)); /* lea ecx, [ecx*4 + 0x1000f820] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00c9b124; /* jae 0xc9b124 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x4u)), c->edx); /* cmp dword ptr [eax + 4], edx */
    if (c->zf) goto L_00c9b126; /* je 0xc9b126 */
L_00c9b124:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00c9b126:;
    c->esp += 4; return; /* ret  */
}

void f_00c9b128(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0xc9c0a4u)); switch (t_) {  default: jump_indirect(c, t_, 0x00c9b128u); return; } } /* jmp dword ptr [0x1000c0a4] */
}
