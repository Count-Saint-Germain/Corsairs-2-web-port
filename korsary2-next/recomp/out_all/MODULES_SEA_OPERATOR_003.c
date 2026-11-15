#include "recomp.h"

void f_0092e396(CPU *c) { /* PTR_0092e396 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_0092e39c(CPU *c) { /* PTR_0092e39c */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_0092e3ba; /* jne 0x92e3ba */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092e449; /* jmp 0x92e449 */
L_0092e3ba:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_0092e3c9; /* jne 0x92e3c9 */
    c->edx = (uint32_t)(R32((uint32_t)(0x952cdcu))); /* mov edx, dword ptr [0x10042cdc] */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x1c], edx */
L_0092e3c9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    W16((uint32_t)(c->ecx + c->eax * 2), (uint16_t)((uint16_t)0xffffu)); /* mov word ptr [ecx + eax*2], 0xffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    W16((uint32_t)(c->eax + c->edx * 2 + 0xfffffffeu), (uint16_t)((uint16_t)0xffffu)); /* mov word ptr [eax + edx*2 - 2], 0xffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov edx, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552a4u)); PUSH32(c, 0x0092e3fcu); call_indirect(c, t_); } /* call dword ptr [0x100452a4] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx + c->eax * 2 + 0xfffffffeu))); /* mov dx, word ptr [ecx + eax*2 - 2] */
    (void)sub32(c, c->edx, (uint32_t)0xffffu); /* cmp edx, 0xffff */
    if (c->zf) goto L_0092e428; /* je 0x92e428 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx + c->eax * 2))); /* mov dx, word ptr [ecx + eax*2] */
    (void)sub32(c, c->edx, (uint32_t)0xffffu); /* cmp edx, 0xffff */
    if (c->zf) goto L_0092e42c; /* je 0x92e42c */
L_0092e428:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092e449; /* jmp 0x92e449 */
L_0092e42c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092e43fu); f_00915bb0(c); /* call 0x915bb0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    goto L_0092e449; /* jmp 0x92e449 */
L_0092e449:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea esp, [ebp - 0x40] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092e460(CPU *c) { /* FUN_1001e460 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(0x952cd4u)); /* lea eax, [0x10042cd4] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_0092e4b3; /* jne 0x92e4b3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0xffu); /* mov al, 0xff */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_0092e47c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0092e4ae; /* je 0x92e4ae */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->edi))) << 8); /* mov ah, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_0092e47c; /* je 0x92e47c */
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
    if (c->zf) goto L_0092e47c; /* je 0x92e47c */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), ((uint8_t)c->eax))); /* sbb al, al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0xffu)); /* sbb al, 0xff */
L_0092e4ae:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    goto L_0092e52b; /* jmp 0x92e52b */
L_0092e4b3:;
    { guest_lock(); guest_trap(c, 0x0092e4b3u, "unsupported: lock inc dword ptr [0x100441b4]"); guest_unlock(); } /* lock inc dword ptr [0x100441b4] */
    (void)sub32(c, R32((uint32_t)(0x9541a4u)), (uint32_t)0x0u); /* cmp dword ptr [0x100441a4], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0092e4c7; /* jg 0x92e4c7 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_0092e4dc; /* jmp 0x92e4dc */
L_0092e4c7:;
    { guest_lock(); guest_trap(c, 0x0092e4c7u, "unsupported: lock dec dword ptr [0x100441b4]"); guest_unlock(); } /* lock dec dword ptr [0x100441b4] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0092e4d5u); f_0091cbf0(c); /* call 0x91cbf0 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
L_0092e4dc:;
    c->eax = (uint32_t)((uint32_t)0xffu); /* mov eax, 0xff */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    ; /* nop  */
L_0092e4e4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0092e50f; /* je 0x92e50f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_0092e4e4; /* je 0x92e4e4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0092e4f9u); f_0091d440(c); /* call 0x91d440 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x0092e503u); f_0091d440(c); /* call 0x91d440 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub8(c, ((uint8_t)c->ebx), ((uint8_t)c->eax)); /* cmp bl, al */
    if (c->zf) goto L_0092e4e4; /* je 0x92e4e4 */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xffffffffu)); /* sbb eax, -1 */
L_0092e50f:;
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_0092e51f; /* jne 0x92e51f */
    { guest_lock(); guest_trap(c, 0x0092e516u, "unsupported: lock dec dword ptr [0x100441b4]"); guest_unlock(); } /* lock dec dword ptr [0x100441b4] */
    goto L_0092e529; /* jmp 0x92e529 */
L_0092e51f:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0092e526u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0092e529:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
L_0092e52b:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0092e530(CPU *c) { /* FUN_1001e530 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->ecx))); /* or ecx, ecx */
    if (c->zf) goto L_0092e62a; /* je 0x92e62a */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(0x952cd4u)); /* lea eax, [0x10042cd4] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_0092e5a1; /* jne 0x92e5a1 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x41u) << 8); /* mov bh, 0x41 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x5au); /* mov bl, 0x5a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x20u) << 8); /* mov dh, 0x20 */
    c->ecx = (uint32_t)((uint32_t)(c->ecx)); /* lea ecx, [ecx] */
L_0092e55c:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi))) << 8); /* mov ah, byte ptr [esi] */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    if (c->zf) goto L_0092e585; /* je 0x92e585 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_0092e585; /* je 0x92e585 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8))); /* cmp ah, bh */
    if (c->cf) goto L_0092e574; /* jb 0x92e574 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if ((!c->cf && !c->zf)) goto L_0092e574; /* ja 0x92e574 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(add8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->edx >> 8)))) << 8); /* add ah, dh */
L_0092e574:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->ebx >> 8))); /* cmp al, bh */
    if (c->cf) goto L_0092e57e; /* jb 0x92e57e */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if ((!c->cf && !c->zf)) goto L_0092e57e; /* ja 0x92e57e */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8)))); /* add al, dh */
L_0092e57e:;
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (!c->zf) goto L_0092e58f; /* jne 0x92e58f */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0092e55c; /* jne 0x92e55c */
L_0092e585:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->eax)); /* cmp ah, al */
    if (c->zf) goto L_0092e62a; /* je 0x92e62a */
L_0092e58f:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_0092e62a; /* jb 0x92e62a */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    goto L_0092e62a; /* jmp 0x92e62a */
L_0092e5a1:;
    { guest_lock(); guest_trap(c, 0x0092e5a1u, "unsupported: lock inc dword ptr [0x100441b4]"); guest_unlock(); } /* lock inc dword ptr [0x100441b4] */
    (void)sub32(c, R32((uint32_t)(0x9541a4u)), (uint32_t)0x0u); /* cmp dword ptr [0x100441a4], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_0092e5b5; /* jg 0x92e5b5 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    goto L_0092e5ce; /* jmp 0x92e5ce */
L_0092e5b5:;
    { guest_lock(); guest_trap(c, 0x0092e5b5u, "unsupported: lock dec dword ptr [0x100441b4]"); guest_unlock(); } /* lock dec dword ptr [0x100441b4] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0092e5c5u); f_0091cbf0(c); /* call 0x91cbf0 */
    W32((uint32_t)(c->esp), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp], 1 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_0092e5ce:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_0092e5d4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    if (c->zf) goto L_0092e5ff; /* je 0x92e5ff */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->ebx))); /* or ebx, ebx */
    if (c->zf) goto L_0092e5ff; /* je 0x92e5ff */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x0092e5eau); f_0091d440(c); /* call 0x91d440 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x0092e5f4u); f_0091d440(c); /* call 0x91d440 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_0092e605; /* jne 0x92e605 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_0092e5d4; /* jne 0x92e5d4 */
L_0092e5ff:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_0092e60e; /* je 0x92e60e */
L_0092e605:;
    c->ecx = (uint32_t)((uint32_t)0xffffffffu); /* mov ecx, 0xffffffff */
    if (c->cf) goto L_0092e60e; /* jb 0x92e60e */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
L_0092e60e:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (!c->zf) goto L_0092e61c; /* jne 0x92e61c */
    { guest_lock(); guest_trap(c, 0x0092e613u, "unsupported: lock dec dword ptr [0x100441b4]"); guest_unlock(); } /* lock dec dword ptr [0x100441b4] */
    goto L_0092e62a; /* jmp 0x92e62a */
L_0092e61c:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x0092e625u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
L_0092e62a:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_0092e640(CPU *c) { /* FUN_1001e640 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 8], 0xffffffff */
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    PUSH32(c, 0x0092e655u); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0xc], 0 */
    goto L_0092e66a; /* jmp 0x92e66a */
L_0092e661:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_0092e66a:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x40u); /* cmp dword ptr [ebp - 0xc], 0x40 */
    if ((c->sf == c->of)) goto L_0092e810; /* jge 0x92e810 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx * 4 + 0x9544a0u)), (uint32_t)0x0u); /* cmp dword ptr [ecx*4 + 0x100444a0], 0 */
    if (c->zf) goto L_0092e776; /* je 0x92e776 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x9544a0u))); /* mov eax, dword ptr [edx*4 + 0x100444a0] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    goto L_0092e69d; /* jmp 0x92e69d */
L_0092e694:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x24u)); /* add ecx, 0x24 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
L_0092e69d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x9544a0u))); /* mov eax, dword ptr [edx*4 + 0x100444a0] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    if (!c->cf) goto L_0092e766; /* jae 0x92e766 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx + 0x4u))); /* movsx edx, byte ptr [ecx + 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u))); /* and edx, 1 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_0092e761; /* jne 0x92e761 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_0092e709; /* jne 0x92e709 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x0092e6d7u); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ecx + 8], 0 */
    if (!c->zf) goto L_0092e6ff; /* jne 0x92e6ff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x955274u)); PUSH32(c, 0x0092e6f0u); call_indirect(c, t_); } /* call dword ptr [0x10045274] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
L_0092e6ff:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x0092e706u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0092e709:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x955278u)); PUSH32(c, 0x0092e716u); call_indirect(c, t_); } /* call dword ptr [0x10045278] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx + 0x4u))); /* movsx edx, byte ptr [ecx + 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u))); /* and edx, 1 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092e736; /* je 0x92e736 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x95527cu)); PUSH32(c, 0x0092e731u); call_indirect(c, t_); } /* call dword ptr [0x1004527c] */
    goto L_0092e694; /* jmp 0x92e694 */
L_0092e736:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ecx], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->edx * 4 + 0x9544a0u)))); /* sub eax, dword ptr [edx*4 + 0x100444a0] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->esi = (uint32_t)((uint32_t)0x24u); /* mov esi, 0x24 */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0092e758u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    goto L_0092e766; /* jmp 0x92e766 */
L_0092e761:;
    goto L_0092e694; /* jmp 0x92e694 */
L_0092e766:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 8], -1 */
    if (c->zf) goto L_0092e771; /* je 0x92e771 */
    goto L_0092e810; /* jmp 0x92e810 */
L_0092e771:;
    goto L_0092e80b; /* jmp 0x92e80b */
L_0092e776:;
    { uint32_t v_ = 0x79u; PUSH32(c, v_); } /* push 0x79 */
    { uint32_t v_ = 0x94bd20u; PUSH32(c, v_); } /* push 0x1003bd20 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x0092e789u); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_0092e809; /* je 0x92e809 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax * 4 + 0x9544a0u), (uint32_t)(c->ecx)); /* mov dword ptr [eax*4 + 0x100444a0], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(0x9545dcu))); /* mov edx, dword ptr [0x100445dc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x20u)); /* add edx, 0x20 */
    W32((uint32_t)(0x9545dcu), (uint32_t)(c->edx)); /* mov dword ptr [0x100445dc], edx */
    goto L_0092e7bc; /* jmp 0x92e7bc */
L_0092e7b3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_0092e7bc:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9544a0u))); /* mov edx, dword ptr [ecx*4 + 0x100444a0] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x480u)); /* add edx, 0x480 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->edx); /* cmp dword ptr [ebp - 4], edx */
    if (!c->cf) goto L_0092e7f4; /* jae 0x92e7f4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + 4], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ecx], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    W8((uint32_t)(c->edx + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [edx + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 8], 0 */
    goto L_0092e7b3; /* jmp 0x92e7b3 */
L_0092e7f4:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 5)); /* shl ecx, 5 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092e806u); f_0092eb50(c); /* call 0x92eb50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0092e809:;
    goto L_0092e810; /* jmp 0x92e810 */
L_0092e80b:;
    goto L_0092e661; /* jmp 0x92e661 */
L_0092e810:;
    { uint32_t v_ = 0x12u; PUSH32(c, v_); } /* push 0x12 */
    PUSH32(c, 0x0092e817u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092e830(CPU *c) { /* __set_osfhnd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9545dcu))); /* cmp eax, dword ptr [0x100445dc] */
    if (!c->cf) goto L_0092e8ca; /* jae 0x92e8ca */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1fu))); /* and edx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x24u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x24 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9544a0u))); /* mov eax, dword ptr [ecx*4 + 0x100444a0] */
    (void)sub32(c, R32((uint32_t)(c->eax + c->edx)), (uint32_t)0xffffffffu); /* cmp dword ptr [eax + edx], -1 */
    if (!c->zf) goto L_0092e8ca; /* jne 0x92e8ca */
    (void)sub32(c, R32((uint32_t)(0x952ac0u)), (uint32_t)0x1u); /* cmp dword ptr [0x10042ac0], 1 */
    if (!c->zf) goto L_0092e8aa; /* jne 0x92e8aa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_0092e882; /* je 0x92e882 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x1u); /* cmp dword ptr [ebp - 4], 1 */
    if (c->zf) goto L_0092e890; /* je 0x92e890 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 4], 2 */
    if (c->zf) goto L_0092e89e; /* je 0x92e89e */
    goto L_0092e8aa; /* jmp 0x92e8aa */
L_0092e882:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t t_ = R32((uint32_t)(0x9552e0u)); PUSH32(c, 0x0092e88eu); call_indirect(c, t_); } /* call dword ptr [0x100452e0] */
    goto L_0092e8aa; /* jmp 0x92e8aa */
L_0092e890:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffff5u; PUSH32(c, v_); } /* push -0xb */
    { uint32_t t_ = R32((uint32_t)(0x9552e0u)); PUSH32(c, 0x0092e89cu); call_indirect(c, t_); } /* call dword ptr [0x100452e0] */
    goto L_0092e8aa; /* jmp 0x92e8aa */
L_0092e89e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x9552e0u)); PUSH32(c, 0x0092e8aau); call_indirect(c, t_); } /* call dword ptr [0x100452e0] */
L_0092e8aa:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(sar32(c, c->edx, 5)); /* sar edx, 5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x24u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x24 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x9544a0u))); /* mov ecx, dword ptr [edx*4 + 0x100444a0] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax], edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092e8e3; /* jmp 0x92e8e3 */
L_0092e8ca:;
    PUSH32(c, 0x0092e8cfu); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x0092e8dau); f_00928820(c); /* call 0x928820 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_0092e8e3:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092e8f0(CPU *c) { /* FUN_1001e8f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9545dcu))); /* cmp eax, dword ptr [0x100445dc] */
    if (!c->cf) goto L_0092e9ab; /* jae 0x92e9ab */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1fu))); /* and edx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x24u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x24 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9544a0u))); /* mov eax, dword ptr [ecx*4 + 0x100444a0] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax + c->edx + 0x4u))); /* movsx ecx, byte ptr [eax + edx + 4] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u))); /* and ecx, 1 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0092e9ab; /* je 0x92e9ab */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(sar32(c, c->edx, 5)); /* sar edx, 5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x24u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x24 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x9544a0u))); /* mov ecx, dword ptr [edx*4 + 0x100444a0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax], -1 */
    if (c->zf) goto L_0092e9ab; /* je 0x92e9ab */
    (void)sub32(c, R32((uint32_t)(0x952ac0u)), (uint32_t)0x1u); /* cmp dword ptr [0x10042ac0], 1 */
    if (!c->zf) goto L_0092e98a; /* jne 0x92e98a */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_0092e968; /* je 0x92e968 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x1u); /* cmp dword ptr [ebp - 4], 1 */
    if (c->zf) goto L_0092e974; /* je 0x92e974 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 4], 2 */
    if (c->zf) goto L_0092e980; /* je 0x92e980 */
    goto L_0092e98a; /* jmp 0x92e98a */
L_0092e968:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t t_ = R32((uint32_t)(0x9552e0u)); PUSH32(c, 0x0092e972u); call_indirect(c, t_); } /* call dword ptr [0x100452e0] */
    goto L_0092e98a; /* jmp 0x92e98a */
L_0092e974:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xfffffff5u; PUSH32(c, v_); } /* push -0xb */
    { uint32_t t_ = R32((uint32_t)(0x9552e0u)); PUSH32(c, 0x0092e97eu); call_indirect(c, t_); } /* call dword ptr [0x100452e0] */
    goto L_0092e98a; /* jmp 0x92e98a */
L_0092e980:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x9552e0u)); PUSH32(c, 0x0092e98au); call_indirect(c, t_); } /* call dword ptr [0x100452e0] */
L_0092e98a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    W32((uint32_t)(c->edx + c->ecx), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [edx + ecx], 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092e9c4; /* jmp 0x92e9c4 */
L_0092e9ab:;
    PUSH32(c, 0x0092e9b0u); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x0092e9bbu); f_00928820(c); /* call 0x928820 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_0092e9c4:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092e9d0(CPU *c) { /* FUN_1001e9d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9545dcu))); /* cmp eax, dword ptr [0x100445dc] */
    if (!c->cf) goto L_0092ea1b; /* jae 0x92ea1b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1fu))); /* and edx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x24u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x24 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9544a0u))); /* mov eax, dword ptr [ecx*4 + 0x100444a0] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax + c->edx + 0x4u))); /* movsx ecx, byte ptr [eax + edx + 4] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u))); /* and ecx, 1 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0092ea1b; /* je 0x92ea1b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(sar32(c, c->edx, 5)); /* sar edx, 5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x24u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x24 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x9544a0u))); /* mov ecx, dword ptr [edx*4 + 0x100444a0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax))); /* mov eax, dword ptr [ecx + eax] */
    goto L_0092ea34; /* jmp 0x92ea34 */
L_0092ea1b:;
    PUSH32(c, 0x0092ea20u); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x0092ea2bu); f_00928820(c); /* call 0x928820 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_0092ea34:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ea40(CPU *c) { /* FUN_1001ea40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebp - 0xc], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092ea5d; /* je 0x92ea5d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov cl, byte ptr [ebp - 0xc] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | (uint8_t)0x20u))); /* or cl, 0x20 */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 0xc], cl */
L_0092ea5d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x4000u))); /* and edx, 0x4000 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092ea72; /* je 0x92ea72 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov al, byte ptr [ebp - 0xc] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x80u))); /* or al, 0x80 */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0xc], al */
L_0092ea72:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x80u))); /* and ecx, 0x80 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0092ea88; /* je 0x92ea88 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov dl, byte ptr [ebp - 0xc] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | (uint8_t)0x10u))); /* or dl, 0x10 */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ebp - 0xc], dl */
L_0092ea88:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x95523cu)); PUSH32(c, 0x0092ea92u); call_indirect(c, t_); } /* call dword ptr [0x1004523c] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (!c->zf) goto L_0092eab2; /* jne 0x92eab2 */
    { uint32_t t_ = R32((uint32_t)(0x9551f0u)); PUSH32(c, 0x0092eaa1u); call_indirect(c, t_); } /* call dword ptr [0x100451f0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092eaa7u); f_00928770(c); /* call 0x928770 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0092eb40; /* jmp 0x92eb40 */
L_0092eab2:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 4], 2 */
    if (!c->zf) goto L_0092eac3; /* jne 0x92eac3 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov cl, byte ptr [ebp - 0xc] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | (uint8_t)0x40u))); /* or cl, 0x40 */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 0xc], cl */
    goto L_0092ead2; /* jmp 0x92ead2 */
L_0092eac3:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x3u); /* cmp dword ptr [ebp - 4], 3 */
    if (!c->zf) goto L_0092ead2; /* jne 0x92ead2 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov dl, byte ptr [ebp - 0xc] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | (uint8_t)0x8u))); /* or dl, 8 */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ebp - 0xc], dl */
L_0092ead2:;
    PUSH32(c, 0x0092ead7u); f_0092e640(c); /* call 0x92e640 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0xffffffffu); /* cmp dword ptr [ebp - 8], -1 */
    if (!c->zf) goto L_0092eafb; /* jne 0x92eafb */
    PUSH32(c, 0x0092eae5u); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x18u)); /* mov dword ptr [eax], 0x18 */
    PUSH32(c, 0x0092eaf0u); f_00928820(c); /* call 0x928820 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0092eb40; /* jmp 0x92eb40 */
L_0092eafb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092eb08u); f_0092e830(c); /* call 0x92e830 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov dl, byte ptr [ebp - 0xc] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->edx) | (uint8_t)0x1u))); /* or dl, 1 */
    W8((uint32_t)(c->ebp + 0xfffffff4u), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [ebp - 0xc], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffff4u))); /* mov al, byte ptr [ebp - 0xc] */
    W8((uint32_t)(c->edx + c->ecx + 0x4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx + ecx + 4], al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092eb3au); f_0092ebe0(c); /* call 0x92ebe0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
L_0092eb40:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092eb50(CPU *c) { /* FUN_1001eb50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 8], 0 */
    if (!c->zf) goto L_0092ebb1; /* jne 0x92ebb1 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x0092eb7fu); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ecx + 8], 0 */
    if (!c->zf) goto L_0092eba7; /* jne 0x92eba7 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xcu)); /* add edx, 0xc */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x955274u)); PUSH32(c, 0x0092eb98u); call_indirect(c, t_); } /* call dword ptr [0x10045274] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
L_0092eba7:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x0092ebaeu); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0092ebb1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->ecx + 0xcu)); /* lea eax, [edx + ecx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x955278u)); PUSH32(c, 0x0092ebd2u); call_indirect(c, t_); } /* call dword ptr [0x10045278] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ebe0(CPU *c) { /* __unlock_fhandle */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    c->eax = (uint32_t)((uint32_t)(c->edx + c->ecx + 0xcu)); /* lea eax, [edx + ecx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x95527cu)); PUSH32(c, 0x0092ec04u); call_indirect(c, t_); } /* call dword ptr [0x1004527c] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ec10(CPU *c) { /* FUN_1001ec10 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x0092ec24u); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [ebp - 8], 3 */
    goto L_0092ec39; /* jmp 0x92ec39 */
L_0092ec30:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_0092ec39:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x9541a0u))); /* cmp ecx, dword ptr [0x100441a0] */
    if ((c->sf == c->of)) goto L_0092ecd9; /* jge 0x92ecd9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov eax, dword ptr [0x10042e4c] */
    (void)sub32(c, R32((uint32_t)(c->eax + c->edx * 4)), (uint32_t)0x0u); /* cmp dword ptr [eax + edx*4], 0 */
    if (c->zf) goto L_0092ecd4; /* je 0x92ecd4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov edx, dword ptr [0x10042e4c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 4))); /* mov eax, dword ptr [edx + ecx*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x83u))); /* and ecx, 0x83 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0092ec91; /* je 0x92ec91 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov eax, dword ptr [0x10042e4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4))); /* mov ecx, dword ptr [eax + edx*4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092ec80u); f_0092fc30(c); /* call 0x92fc30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_0092ec91; /* je 0x92ec91 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1u)); /* add edx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
L_0092ec91:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x14u); /* cmp dword ptr [ebp - 8], 0x14 */
    if ((c->sf != c->of)) goto L_0092ecd4; /* jl 0x92ecd4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov ecx, dword ptr [0x10042e4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x20u)); /* add edx, 0x20 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x955244u)); PUSH32(c, 0x0092ecadu); call_indirect(c, t_); } /* call dword ptr [0x10045244] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov ecx, dword ptr [0x10042e4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092ecc1u); f_009193f0(c); /* call 0x9193f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov ecx, dword ptr [0x10042e4c] */
    W32((uint32_t)(c->ecx + c->eax * 4), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + eax*4], 0 */
L_0092ecd4:;
    goto L_0092ec30; /* jmp 0x92ec30 */
L_0092ecd9:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x0092ece0u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ecf0(CPU *c) { /* FUN_1001ecf0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_0092ed06; /* jne 0x92ed06 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x0092ed01u); f_0092ee60(c); /* call 0x92ee60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    goto L_0092ed30; /* jmp 0x92ed30 */
L_0092ed06:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092ed0fu); f_0092c8e0(c); /* call 0x92c8e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092ed1bu); f_0092ed40(c); /* call 0x92ed40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092ed2au); f_0092c950(c); /* call 0x92c950 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_0092ed30:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ed40(CPU *c) { /* FUN_1001ed40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092ed4cu); f_0092ed90(c); /* call 0x92ed90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092ed58; /* je 0x92ed58 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0092ed7f; /* jmp 0x92ed7f */
L_0092ed58:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x4000u))); /* and edx, 0x4000 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092ed7d; /* je 0x92ed7d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092ed74u); f_0092fd80(c); /* call 0x92fd80 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    goto L_0092ed7f; /* jmp 0x92ed7f */
L_0092ed7d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0092ed7f:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ed90(CPU *c) { /* FUN_1001ed90 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->edx, (uint32_t)0x2u); /* cmp edx, 2 */
    if (!c->zf) goto L_0092ee2b; /* jne 0x92ee2b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x108u))); /* and ecx, 0x108 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0092ee2b; /* je 0x92ee2b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx))); /* mov ecx, dword ptr [edx] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u)))); /* sub ecx, dword ptr [eax + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_0092ee2b; /* jle 0x92ee2b */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ecx, dword ptr [eax + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov eax, dword ptr [edx + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092edecu); f_0092c370(c); /* call 0x92c370 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff4u))); /* cmp eax, dword ptr [ebp - 0xc] */
    if (!c->zf) goto L_0092ee15; /* jne 0x92ee15 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x80u))); /* and edx, 0x80 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092ee13; /* je 0x92ee13 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffdu))); /* and ecx, 0xfffffffd */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0xc], ecx */
L_0092ee13:;
    goto L_0092ee2b; /* jmp 0x92ee2b */
L_0092ee15:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x20u))); /* or ecx, 0x20 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 0xc], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
L_0092ee2b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov edx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ee50(CPU *c) { /* FUN_1001ee50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0092ee5au); f_0092ee60(c); /* call 0x92ee60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ee60(CPU *c) { /* FUN_1001ee60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 8], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x0092ee7bu); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0xc], 0 */
    goto L_0092ee90; /* jmp 0x92ee90 */
L_0092ee87:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_0092ee90:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x9541a0u))); /* cmp ecx, dword ptr [0x100441a0] */
    if ((c->sf == c->of)) goto L_0092ef83; /* jge 0x92ef83 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov eax, dword ptr [0x10042e4c] */
    (void)sub32(c, R32((uint32_t)(c->eax + c->edx * 4)), (uint32_t)0x0u); /* cmp dword ptr [eax + edx*4], 0 */
    if (c->zf) goto L_0092ef7e; /* je 0x92ef7e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov edx, dword ptr [0x10042e4c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 4))); /* mov eax, dword ptr [edx + ecx*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x83u))); /* and ecx, 0x83 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0092ef7e; /* je 0x92ef7e */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov eax, dword ptr [0x10042e4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4))); /* mov ecx, dword ptr [eax + edx*4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092eee3u); f_0092c920(c); /* call 0x92c920 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov ecx, dword ptr [0x10042e4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x83u))); /* and eax, 0x83 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092ef65; /* je 0x92ef65 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 8], 1 */
    if (!c->zf) goto L_0092ef29; /* jne 0x92ef29 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov edx, dword ptr [0x10042e4c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 4))); /* mov eax, dword ptr [edx + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092ef16u); f_0092ed40(c); /* call 0x92ed40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_0092ef27; /* je 0x92ef27 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
L_0092ef27:;
    goto L_0092ef65; /* jmp 0x92ef65 */
L_0092ef29:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_0092ef65; /* jne 0x92ef65 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov eax, dword ptr [0x10042e4c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edx * 4))); /* mov ecx, dword ptr [eax + edx*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u))); /* and edx, 2 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092ef65; /* je 0x92ef65 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov ecx, dword ptr [0x10042e4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092ef56u); f_0092ed40(c); /* call 0x92ed40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (!c->zf) goto L_0092ef65; /* jne 0x92ef65 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 8], 0xffffffff */
L_0092ef65:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e4cu))); /* mov ecx, dword ptr [0x10042e4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092ef7bu); f_0092c990(c); /* call 0x92c990 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_0092ef7e:;
    goto L_0092ee87; /* jmp 0x92ee87 */
L_0092ef83:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x0092ef8au); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 8], 1 */
    if (!c->zf) goto L_0092ef98; /* jne 0x92ef98 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    goto L_0092ef9b; /* jmp 0x92ef9b */
L_0092ef98:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
L_0092ef9b:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092efa0(CPU *c) { /* FUN_1001efa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(0x952e28u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e28], 0 */
    if (!c->zf) goto L_0092efdb; /* jne 0x92efdb */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0092efb3u); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, R32((uint32_t)(0x952e28u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e28], 0 */
    if (!c->zf) goto L_0092efd1; /* jne 0x92efd1 */
    PUSH32(c, 0x0092efc4u); f_0092f000(c); /* call 0x92f000 */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e28u))); /* mov eax, dword ptr [0x10042e28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(0x952e28u), (uint32_t)(c->eax)); /* mov dword ptr [0x10042e28], eax */
L_0092efd1:;
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0092efd8u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0092efdb:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092efe0(CPU *c) { /* FUN_1001efe0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0092efeau); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    PUSH32(c, 0x0092eff2u); f_0092f000(c); /* call 0x92f000 */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0092eff9u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092f000(CPU *c) { /* FUN_1001f000 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092f014u); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(0x952d70u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10042d70], 0 */
    W32((uint32_t)(0x951830u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [0x10041830], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(0x951830u))); /* mov eax, dword ptr [0x10041830] */
    W32((uint32_t)(0x951820u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041820], eax */
    { uint32_t v_ = 0x94bd74u; PUSH32(c, v_); } /* push 0x1003bd74 */
    PUSH32(c, 0x0092f03fu); f_0092fe90(c); /* call 0x92fe90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_0092f183; /* jne 0x92f183 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092f056u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = 0x952d78u; PUSH32(c, v_); } /* push 0x10042d78 */
    { uint32_t t_ = R32((uint32_t)(0x9552e4u)); PUSH32(c, 0x0092f064u); call_indirect(c, t_); } /* call dword ptr [0x100452e4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_0092f17e; /* je 0x92f17e */
    W32((uint32_t)(0x952d70u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10042d70], 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952d78u))); /* mov ecx, dword ptr [0x10042d78] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x3cu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x3c */
    W32((uint32_t)(0x95178cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1004178c], ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dbeu))); /* mov dx, word ptr [0x10042dbe] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092f0a9; /* je 0x92f0a9 */
    c->eax = (uint32_t)(R32((uint32_t)(0x952dccu))); /* mov eax, dword ptr [0x10042dcc] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x3cu; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x3c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x95178cu))); /* mov ecx, dword ptr [0x1004178c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(0x95178cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1004178c], ecx */
L_0092f0a9:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e12u))); /* mov dx, word ptr [0x10042e12] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092f0de; /* je 0x92f0de */
    (void)sub32(c, R32((uint32_t)(0x952e20u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e20], 0 */
    if (c->zf) goto L_0092f0de; /* je 0x92f0de */
    W32((uint32_t)(0x951790u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10041790], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e20u))); /* mov eax, dword ptr [0x10042e20] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(0x952dccu)))); /* sub eax, dword ptr [0x10042dcc] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x3cu; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x3c */
    W32((uint32_t)(0x951794u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041794], eax */
    goto L_0092f0f2; /* jmp 0x92f0f2 */
L_0092f0de:;
    W32((uint32_t)(0x951790u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10041790], 0 */
    W32((uint32_t)(0x951794u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [0x10041794], 0 */
L_0092f0f2:;
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea ecx, [ebp - 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    c->edx = (uint32_t)(R32((uint32_t)(0x951818u))); /* mov edx, dword ptr [0x10041818] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x952d7cu; PUSH32(c, v_); } /* push 0x10042d7c */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    c->eax = (uint32_t)(R32((uint32_t)(0x952cecu))); /* mov eax, dword ptr [0x10042cec] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x0092f119u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092f12f; /* je 0x92f12f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if (!c->zf) goto L_0092f12f; /* jne 0x92f12f */
    c->ecx = (uint32_t)(R32((uint32_t)(0x951818u))); /* mov ecx, dword ptr [0x10041818] */
    W8((uint32_t)(c->ecx + 0x3fu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx + 0x3f], 0 */
    goto L_0092f138; /* jmp 0x92f138 */
L_0092f12f:;
    c->edx = (uint32_t)(R32((uint32_t)(0x951818u))); /* mov edx, dword ptr [0x10041818] */
    W8((uint32_t)(c->edx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edx], 0 */
L_0092f138:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x3fu; PUSH32(c, v_); } /* push 0x3f */
    c->ecx = (uint32_t)(R32((uint32_t)(0x95181cu))); /* mov ecx, dword ptr [0x1004181c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x952dd0u; PUSH32(c, v_); } /* push 0x10042dd0 */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    c->edx = (uint32_t)(R32((uint32_t)(0x952cecu))); /* mov edx, dword ptr [0x10042cec] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x0092f160u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092f175; /* je 0x92f175 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if (!c->zf) goto L_0092f175; /* jne 0x92f175 */
    c->eax = (uint32_t)(R32((uint32_t)(0x95181cu))); /* mov eax, dword ptr [0x1004181c] */
    W8((uint32_t)(c->eax + 0x3fu), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + 0x3f], 0 */
    goto L_0092f17e; /* jmp 0x92f17e */
L_0092f175:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x95181cu))); /* mov ecx, dword ptr [0x1004181c] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx], 0 */
L_0092f17e:;
    goto L_0092f3a7; /* jmp 0x92f3a7 */
L_0092f183:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx eax, byte ptr [edx] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092f1ad; /* je 0x92f1ad */
    (void)sub32(c, R32((uint32_t)(0x952e24u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e24], 0 */
    if (c->zf) goto L_0092f1bc; /* je 0x92f1bc */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952e24u))); /* mov ecx, dword ptr [0x10042e24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092f1a6u); f_009158d0(c); /* call 0x9158d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092f1bc; /* jne 0x92f1bc */
L_0092f1ad:;
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092f1b4u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    goto L_0092f3a7; /* jmp 0x92f3a7 */
L_0092f1bc:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e24u))); /* mov eax, dword ptr [0x10042e24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092f1c9u); f_009193f0(c); /* call 0x9193f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = 0x10cu; PUSH32(c, v_); } /* push 0x10c */
    { uint32_t v_ = 0x94bd6cu; PUSH32(c, v_); } /* push 0x1003bd6c */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092f1e1u); f_0091e130(c); /* call 0x91e130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092f1edu); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(0x952e24u), (uint32_t)(c->eax)); /* mov dword ptr [0x10042e24], eax */
    (void)sub32(c, R32((uint32_t)(0x952e24u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e24], 0 */
    if (!c->zf) goto L_0092f20d; /* jne 0x92f20d */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092f205u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    goto L_0092f3a7; /* jmp 0x92f3a7 */
L_0092f20d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x952e24u))); /* mov eax, dword ptr [0x10042e24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092f21cu); f_0091e040(c); /* call 0x91e040 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092f226u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(0x951818u))); /* mov edx, dword ptr [0x10041818] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092f23bu); f_0091ed30(c); /* call 0x91ed30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(0x951818u))); /* mov eax, dword ptr [0x10041818] */
    W8((uint32_t)(c->eax + 0x3u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax + 3], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x3u)); /* add ecx, 3 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx eax, byte ptr [edx] */
    (void)sub32(c, c->eax, (uint32_t)0x2du); /* cmp eax, 0x2d */
    if (!c->zf) goto L_0092f26d; /* jne 0x92f26d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1u)); /* add edx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_0092f26d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092f276u); f_00915960(c); /* call 0x915960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0xe10u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0xe10 */
    W32((uint32_t)(0x95178cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1004178c], eax */
L_0092f284:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx))); /* movsx edx, byte ptr [ecx] */
    (void)sub32(c, c->edx, (uint32_t)0x2bu); /* cmp edx, 0x2b */
    if (c->zf) goto L_0092f2a5; /* je 0x92f2a5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx ecx, byte ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0x30u); /* cmp ecx, 0x30 */
    if ((c->sf != c->of)) goto L_0092f2b0; /* jl 0x92f2b0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx eax, byte ptr [edx] */
    (void)sub32(c, c->eax, (uint32_t)0x39u); /* cmp eax, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_0092f2b0; /* jg 0x92f2b0 */
L_0092f2a5:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    goto L_0092f284; /* jmp 0x92f284 */
L_0092f2b0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx eax, byte ptr [edx] */
    (void)sub32(c, c->eax, (uint32_t)0x3au); /* cmp eax, 0x3a */
    if (!c->zf) goto L_0092f355; /* jne 0x92f355 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092f2d1u); f_00915960(c); /* call 0x915960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x3cu; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x3c */
    c->ecx = (uint32_t)(R32((uint32_t)(0x95178cu))); /* mov ecx, dword ptr [0x1004178c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(0x95178cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1004178c], ecx */
L_0092f2e5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx eax, byte ptr [edx] */
    (void)sub32(c, c->eax, (uint32_t)0x30u); /* cmp eax, 0x30 */
    if ((c->sf != c->of)) goto L_0092f306; /* jl 0x92f306 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx))); /* movsx edx, byte ptr [ecx] */
    (void)sub32(c, c->edx, (uint32_t)0x39u); /* cmp edx, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_0092f306; /* jg 0x92f306 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    goto L_0092f2e5; /* jmp 0x92f2e5 */
L_0092f306:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx))); /* movsx edx, byte ptr [ecx] */
    (void)sub32(c, c->edx, (uint32_t)0x3au); /* cmp edx, 0x3a */
    if (!c->zf) goto L_0092f355; /* jne 0x92f355 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092f323u); f_00915960(c); /* call 0x915960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(0x95178cu))); /* mov edx, dword ptr [0x1004178c] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    W32((uint32_t)(0x95178cu), (uint32_t)(c->edx)); /* mov dword ptr [0x1004178c], edx */
L_0092f334:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx ecx, byte ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0x30u); /* cmp ecx, 0x30 */
    if ((c->sf != c->of)) goto L_0092f355; /* jl 0x92f355 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx))); /* movsx eax, byte ptr [edx] */
    (void)sub32(c, c->eax, (uint32_t)0x39u); /* cmp eax, 0x39 */
    if ((!c->zf && c->sf == c->of)) goto L_0092f355; /* jg 0x92f355 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    goto L_0092f334; /* jmp 0x92f334 */
L_0092f355:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_0092f369; /* je 0x92f369 */
    c->edx = (uint32_t)(R32((uint32_t)(0x95178cu))); /* mov edx, dword ptr [0x1004178c] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    W32((uint32_t)(0x95178cu), (uint32_t)(c->edx)); /* mov dword ptr [0x1004178c], edx */
L_0092f369:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax))); /* movsx ecx, byte ptr [eax] */
    W32((uint32_t)(0x951790u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10041790], ecx */
    (void)sub32(c, R32((uint32_t)(0x951790u)), (uint32_t)0x0u); /* cmp dword ptr [0x10041790], 0 */
    if (c->zf) goto L_0092f39e; /* je 0x92f39e */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(0x95181cu))); /* mov eax, dword ptr [0x1004181c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092f38fu); f_0091ed30(c); /* call 0x91ed30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(R32((uint32_t)(0x95181cu))); /* mov ecx, dword ptr [0x1004181c] */
    W8((uint32_t)(c->ecx + 0x3u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ecx + 3], 0 */
    goto L_0092f3a7; /* jmp 0x92f3a7 */
L_0092f39e:;
    c->edx = (uint32_t)(R32((uint32_t)(0x95181cu))); /* mov edx, dword ptr [0x1004181c] */
    W8((uint32_t)(c->edx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edx], 0 */
L_0092f3a7:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092f3b0(CPU *c) { /* FUN_1001f3b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0092f3bbu); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092f3c7u); f_0092f3e0(c); /* call 0x92f3e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = 0xbu; PUSH32(c, v_); } /* push 0xb */
    PUSH32(c, 0x0092f3d4u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092f3e0(CPU *c) { /* FUN_1001f3e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x951790u)), (uint32_t)0x0u); /* cmp dword ptr [0x10041790], 0 */
    if (!c->zf) goto L_0092f3f4; /* jne 0x92f3f4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f3f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x951820u))); /* cmp ecx, dword ptr [0x10041820] */
    if (!c->zf) goto L_0092f414; /* jne 0x92f414 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x14u))); /* mov eax, dword ptr [edx + 0x14] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x951830u))); /* cmp eax, dword ptr [0x10041830] */
    if (c->zf) goto L_0092f5db; /* je 0x92f5db */
L_0092f414:;
    (void)sub32(c, R32((uint32_t)(0x952d70u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042d70], 0 */
    if (c->zf) goto L_0092f595; /* je 0x92f595 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e10u))); /* mov cx, word ptr [0x10042e10] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0092f489; /* jne 0x92f489 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e1eu))); /* mov dx, word ptr [0x10042e1e] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e1cu))); /* mov ax, word ptr [0x10042e1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e1au))); /* mov cx, word ptr [0x10042e1a] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e18u))); /* mov dx, word ptr [0x10042e18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e14u))); /* mov ax, word ptr [0x10042e14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e16u))); /* mov cx, word ptr [0x10042e16] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e12u))); /* mov dx, word ptr [0x10042e12] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0092f484u); f_0092f6e0(c); /* call 0x92f6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    goto L_0092f4da; /* jmp 0x92f4da */
L_0092f489:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e1eu))); /* mov dx, word ptr [0x10042e1e] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e1cu))); /* mov ax, word ptr [0x10042e1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e1au))); /* mov cx, word ptr [0x10042e1a] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e18u))); /* mov dx, word ptr [0x10042e18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e16u))); /* mov ax, word ptr [0x10042e16] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952e12u))); /* mov cx, word ptr [0x10042e12] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x14u))); /* mov eax, dword ptr [edx + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0092f4d7u); f_0092f6e0(c); /* call 0x92f6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_0092f4da:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dbcu))); /* mov cx, word ptr [0x10042dbc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0092f542; /* jne 0x92f542 */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dcau))); /* mov dx, word ptr [0x10042dca] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc8u))); /* mov ax, word ptr [0x10042dc8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc6u))); /* mov cx, word ptr [0x10042dc6] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc4u))); /* mov dx, word ptr [0x10042dc4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc0u))); /* mov ax, word ptr [0x10042dc0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc2u))); /* mov cx, word ptr [0x10042dc2] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dbeu))); /* mov dx, word ptr [0x10042dbe] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x0092f53du); f_0092f6e0(c); /* call 0x92f6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    goto L_0092f593; /* jmp 0x92f593 */
L_0092f542:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dcau))); /* mov dx, word ptr [0x10042dca] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc8u))); /* mov ax, word ptr [0x10042dc8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc6u))); /* mov cx, word ptr [0x10042dc6] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc4u))); /* mov dx, word ptr [0x10042dc4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dc2u))); /* mov ax, word ptr [0x10042dc2] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(0x952dbeu))); /* mov cx, word ptr [0x10042dbe] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x14u))); /* mov eax, dword ptr [edx + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x0092f590u); f_0092f6e0(c); /* call 0x92f6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_0092f593:;
    goto L_0092f5db; /* jmp 0x92f5db */
L_0092f595:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov edx, dword ptr [ecx + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x0092f5b5u); f_0092f6e0(c); /* call 0x92f6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x0092f5d8u); f_0092f6e0(c); /* call 0x92f6e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_0092f5db:;
    c->edx = (uint32_t)(R32((uint32_t)(0x951824u))); /* mov edx, dword ptr [0x10041824] */
    (void)sub32(c, c->edx, R32((uint32_t)(0x951834u))); /* cmp edx, dword ptr [0x10041834] */
    if ((c->sf == c->of)) goto L_0092f634; /* jge 0x92f634 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x951824u))); /* cmp ecx, dword ptr [0x10041824] */
    if ((c->sf != c->of)) goto L_0092f605; /* jl 0x92f605 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x1cu))); /* mov eax, dword ptr [edx + 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x951834u))); /* cmp eax, dword ptr [0x10041834] */
    if ((c->zf || c->sf != c->of)) goto L_0092f60c; /* jle 0x92f60c */
L_0092f605:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f60c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov edx, dword ptr [ecx + 0x1c] */
    (void)sub32(c, c->edx, R32((uint32_t)(0x951824u))); /* cmp edx, dword ptr [0x10041824] */
    if ((c->zf || c->sf != c->of)) goto L_0092f632; /* jle 0x92f632 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x951834u))); /* cmp ecx, dword ptr [0x10041834] */
    if ((c->sf == c->of)) goto L_0092f632; /* jge 0x92f632 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f632:;
    goto L_0092f677; /* jmp 0x92f677 */
L_0092f634:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x1cu))); /* mov eax, dword ptr [edx + 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x951834u))); /* cmp eax, dword ptr [0x10041834] */
    if ((c->sf != c->of)) goto L_0092f650; /* jl 0x92f650 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov edx, dword ptr [ecx + 0x1c] */
    (void)sub32(c, c->edx, R32((uint32_t)(0x951824u))); /* cmp edx, dword ptr [0x10041824] */
    if ((c->zf || c->sf != c->of)) goto L_0092f657; /* jle 0x92f657 */
L_0092f650:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f657:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x951834u))); /* cmp ecx, dword ptr [0x10041834] */
    if ((c->zf || c->sf != c->of)) goto L_0092f677; /* jle 0x92f677 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x1cu))); /* mov eax, dword ptr [edx + 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x951824u))); /* cmp eax, dword ptr [0x10041824] */
    if ((c->sf == c->of)) goto L_0092f677; /* jge 0x92f677 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f677:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x3cu; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x3c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0xe10u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0xe10 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x3e8u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x3e8 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov edx, dword ptr [ecx + 0x1c] */
    (void)sub32(c, c->edx, R32((uint32_t)(0x951824u))); /* cmp edx, dword ptr [0x10041824] */
    if (!c->zf) goto L_0092f6c2; /* jne 0x92f6c2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x951828u))); /* cmp eax, dword ptr [0x10041828] */
    if ((c->sf != c->of)) goto L_0092f6be; /* jl 0x92f6be */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f6be:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f6c2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x951838u))); /* cmp ecx, dword ptr [0x10041838] */
    if ((c->sf == c->of)) goto L_0092f6d4; /* jge 0x92f6d4 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_0092f6d6; /* jmp 0x92f6d6 */
L_0092f6d4:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0092f6d6:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092f6e0(CPU *c) { /* FUN_1001f6e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 0xc], 1 */
    if (!c->zf) goto L_0092f7bc; /* jne 0x92f7bc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092f709; /* jne 0x92f709 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x951838u))); /* mov edx, dword ptr [ecx*4 + 0x10041838] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    goto L_0092f716; /* jmp 0x92f716 */
L_0092f709:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x95186cu))); /* mov ecx, dword ptr [eax*4 + 0x1004186c] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
L_0092f716:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1u)); /* add edx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x46u)); /* sub eax, 0x46 */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x16du; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x16d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(sub32(c, c->edx, (uint32_t)0x1u)); /* sub edx, 1 */
    c->edx = (uint32_t)(sar32(c, c->edx, 2)); /* sar edx, 2 */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->edx + 0xfffffff3u)); /* lea eax, [ecx + edx - 0xd] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    c->ecx = (uint32_t)((uint32_t)0x7u); /* mov ecx, 7 */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x0092f743u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp edx, dword ptr [ebp + 0x1c] */
    if ((!c->zf && c->sf == c->of)) goto L_0092f769; /* jg 0x92f769 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu)))); /* sub eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1u)); /* sub ecx, 1 */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x7u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 7 */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    goto L_0092f77d; /* jmp 0x92f77d */
L_0092f769:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edx, dword ptr [ebp + 0x1c] */
    c->edx = (uint32_t)(sub32(c, c->edx, R32((uint32_t)(c->ebp + 0xfffffffcu)))); /* sub edx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x7u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 7 */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* add eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_0092f77d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x5u); /* cmp dword ptr [ebp + 0x18], 5 */
    if (!c->zf) goto L_0092f7ba; /* jne 0x92f7ba */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0092f79c; /* jne 0x92f79c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x95183cu))); /* mov eax, dword ptr [edx*4 + 0x1004183c] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    goto L_0092f7a9; /* jmp 0x92f7a9 */
L_0092f79c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x951870u))); /* mov edx, dword ptr [ecx*4 + 0x10041870] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
L_0092f7a9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff0u))); /* cmp eax, dword ptr [ebp - 0x10] */
    if ((c->zf || c->sf != c->of)) goto L_0092f7ba; /* jle 0x92f7ba */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x7u)); /* sub ecx, 7 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_0092f7ba:;
    goto L_0092f7f1; /* jmp 0x92f7f1 */
L_0092f7bc:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_0092f7d5; /* jne 0x92f7d5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x951838u))); /* mov ecx, dword ptr [eax*4 + 0x10041838] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x14], ecx */
    goto L_0092f7e2; /* jmp 0x92f7e2 */
L_0092f7d5:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx * 4 + 0x95186cu))); /* mov eax, dword ptr [edx*4 + 0x1004186c] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
L_0092f7e2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(add32(c, c->edx, R32((uint32_t)(c->ebp + 0x20u)))); /* add edx, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
L_0092f7f1:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 8], 1 */
    if (!c->zf) goto L_0092f831; /* jne 0x92f831 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    W32((uint32_t)(0x951824u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041824], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov ecx, dword ptr [ebp + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x3cu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x3c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x28u))); /* mov edx, dword ptr [ebp + 0x28] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x3cu; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x3c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x2cu))); /* mov eax, dword ptr [ebp + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x3e8u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x3e8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x30u))); /* mov ecx, dword ptr [ebp + 0x30] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(0x951828u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10041828], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(0x951820u), (uint32_t)(c->edx)); /* mov dword ptr [0x10041820], edx */
    goto L_0092f8d4; /* jmp 0x92f8d4 */
L_0092f831:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    W32((uint32_t)(0x951834u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041834], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov ecx, dword ptr [ebp + 0x24] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x3cu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x3c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x28u))); /* mov edx, dword ptr [ebp + 0x28] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x3cu; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x3c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x2cu))); /* mov eax, dword ptr [ebp + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)(uint32_t)0x3e8u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, eax, 0x3e8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x30u))); /* mov ecx, dword ptr [ebp + 0x30] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    W32((uint32_t)(0x951838u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10041838], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(0x951794u))); /* mov edx, dword ptr [0x10041794] */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x3e8u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x3e8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x951838u))); /* mov eax, dword ptr [0x10041838] */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    W32((uint32_t)(0x951838u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041838], eax */
    (void)sub32(c, R32((uint32_t)(0x951838u)), (uint32_t)0x0u); /* cmp dword ptr [0x10041838], 0 */
    if ((c->sf == c->of)) goto L_0092f8a1; /* jge 0x92f8a1 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x951838u))); /* mov ecx, dword ptr [0x10041838] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x5265c00u)); /* add ecx, 0x5265c00 */
    W32((uint32_t)(0x951838u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10041838], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(0x951834u))); /* mov edx, dword ptr [0x10041834] */
    c->edx = (uint32_t)(sub32(c, c->edx, (uint32_t)0x1u)); /* sub edx, 1 */
    W32((uint32_t)(0x951834u), (uint32_t)(c->edx)); /* mov dword ptr [0x10041834], edx */
    goto L_0092f8cb; /* jmp 0x92f8cb */
L_0092f8a1:;
    (void)sub32(c, R32((uint32_t)(0x951838u)), (uint32_t)0x5265c00u); /* cmp dword ptr [0x10041838], 0x5265c00 */
    if ((c->sf != c->of)) goto L_0092f8cb; /* jl 0x92f8cb */
    c->eax = (uint32_t)(R32((uint32_t)(0x951838u))); /* mov eax, dword ptr [0x10041838] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5265c00u)); /* sub eax, 0x5265c00 */
    W32((uint32_t)(0x951838u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041838], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x951834u))); /* mov ecx, dword ptr [0x10041834] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(0x951834u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10041834], ecx */
L_0092f8cb:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(0x951830u), (uint32_t)(c->edx)); /* mov dword ptr [0x10041830], edx */
L_0092f8d4:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092f8e0(CPU *c) { /* FUN_1001f8e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x94bd78u; PUSH32(c, v_); } /* push 0x1003bd78 */
    { uint32_t v_ = 0x91ef60u; PUSH32(c, v_); } /* push 0x1000ef60 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe8u)); /* add esp, -0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    (void)sub32(c, R32((uint32_t)(0x952e2cu)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e2c], 0 */
    if (!c->zf) goto L_0092f952; /* jne 0x92f952 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x9552e8u)); PUSH32(c, 0x0092f91du); call_indirect(c, t_); } /* call dword ptr [0x100452e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092f92d; /* je 0x92f92d */
    W32((uint32_t)(0x952e2cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10042e2c], 1 */
    goto L_0092f952; /* jmp 0x92f952 */
L_0092f92d:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x9552d0u)); PUSH32(c, 0x0092f93bu); call_indirect(c, t_); } /* call dword ptr [0x100452d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092f94b; /* je 0x92f94b */
    W32((uint32_t)(0x952e2cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x10042e2c], 2 */
    goto L_0092f952; /* jmp 0x92f952 */
L_0092f94b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092f952:;
    (void)sub32(c, R32((uint32_t)(0x952e2cu)), (uint32_t)0x1u); /* cmp dword ptr [0x10042e2c], 1 */
    if (!c->zf) goto L_0092f976; /* jne 0x92f976 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552e8u)); PUSH32(c, 0x0092f971u); call_indirect(c, t_); } /* call dword ptr [0x100452e8] */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092f976:;
    (void)sub32(c, R32((uint32_t)(0x952e2cu)), (uint32_t)0x2u); /* cmp dword ptr [0x10042e2c], 2 */
    if (!c->zf) goto L_0092fa5f; /* jne 0x92fa5f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_0092f992; /* jne 0x92f992 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952cecu))); /* mov ecx, dword ptr [0x10042cec] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x18], ecx */
L_0092f992:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552d0u)); PUSH32(c, 0x0092f9a4u); call_indirect(c, t_); } /* call dword ptr [0x100452d0] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_0092f9b4; /* jne 0x92f9b4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092f9b4:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x0092f9c8u); f_0091e6b0(c); /* call 0x91e6b0 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x28], esp */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    goto L_0092f9f4; /* jmp 0x92f9f4 */
L_0092f9f4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_0092f9fe; /* jne 0x92f9fe */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092f9fe:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552d0u)); PUSH32(c, 0x0092fa14u); call_indirect(c, t_); } /* call dword ptr [0x100452d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092fa1c; /* jne 0x92fa1c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092fa1c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (!c->zf) goto L_0092fa3d; /* jne 0x92fa3d */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x0092fa38u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0092fa5a; /* jmp 0x92fa5a */
L_0092fa3d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x0092fa57u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_0092fa5a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092fa5f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0092fa61:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092f9dd(CPU *c) { /* PTR_0092f9dd */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_0092f9e3(CPU *c) { /* PTR_0092f9e3 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0x20], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_0092f9fe; /* jne 0x92f9fe */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092f9fe:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552d0u)); PUSH32(c, 0x0092fa14u); call_indirect(c, t_); } /* call dword ptr [0x100452d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092fa1c; /* jne 0x92fa1c */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092fa1c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (!c->zf) goto L_0092fa3d; /* jne 0x92fa3d */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x0092fa38u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0092fa5a; /* jmp 0x92fa5a */
L_0092fa3d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x0092fa57u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_0092fa5a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    goto L_0092fa61; /* jmp 0x92fa61 */
L_0092fa61:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fa80(CPU *c) { /* FUN_1001fa80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x94bd88u; PUSH32(c, v_); } /* push 0x1003bd88 */
    { uint32_t v_ = 0x91ef60u; PUSH32(c, v_); } /* push 0x1000ef60 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe8u)); /* add esp, -0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    (void)sub32(c, R32((uint32_t)(0x952e30u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e30], 0 */
    if (!c->zf) goto L_0092faf2; /* jne 0x92faf2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x9552e8u)); PUSH32(c, 0x0092fabdu); call_indirect(c, t_); } /* call dword ptr [0x100452e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092facd; /* je 0x92facd */
    W32((uint32_t)(0x952e30u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10042e30], 1 */
    goto L_0092faf2; /* jmp 0x92faf2 */
L_0092facd:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x9552d0u)); PUSH32(c, 0x0092fadbu); call_indirect(c, t_); } /* call dword ptr [0x100452d0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092faeb; /* je 0x92faeb */
    W32((uint32_t)(0x952e30u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x10042e30], 2 */
    goto L_0092faf2; /* jmp 0x92faf2 */
L_0092faeb:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092faf2:;
    (void)sub32(c, R32((uint32_t)(0x952e30u)), (uint32_t)0x2u); /* cmp dword ptr [0x10042e30], 2 */
    if (!c->zf) goto L_0092fb16; /* jne 0x92fb16 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552d0u)); PUSH32(c, 0x0092fb11u); call_indirect(c, t_); } /* call dword ptr [0x100452d0] */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fb16:;
    (void)sub32(c, R32((uint32_t)(0x952e30u)), (uint32_t)0x1u); /* cmp dword ptr [0x10042e30], 1 */
    if (!c->zf) goto L_0092fc0f; /* jne 0x92fc0f */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_0092fb32; /* jne 0x92fb32 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952cecu))); /* mov ecx, dword ptr [0x10042cec] */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x18], ecx */
L_0092fb32:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552e8u)); PUSH32(c, 0x0092fb44u); call_indirect(c, t_); } /* call dword ptr [0x100452e8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_0092fb54; /* jne 0x92fb54 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fb54:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x0092fb6au); f_0091e6b0(c); /* call 0x91e6b0 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x28], esp */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ecx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x20], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    goto L_0092fb96; /* jmp 0x92fb96 */
L_0092fb96:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_0092fba0; /* jne 0x92fba0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fba0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552e8u)); PUSH32(c, 0x0092fbb6u); call_indirect(c, t_); } /* call dword ptr [0x100452e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092fbbe; /* jne 0x92fbbe */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fbbe:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (!c->zf) goto L_0092fbe6; /* jne 0x92fbe6 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x0092fbe1u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0092fc0a; /* jmp 0x92fc0a */
L_0092fbe6:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x0092fc07u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_0092fc0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fc0f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0092fc11:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fb7f(CPU *c) { /* PTR_0092fb7f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_0092fb85(CPU *c) { /* PTR_0092fb85 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0x20], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_0092fba0; /* jne 0x92fba0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fba0:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x9552e8u)); PUSH32(c, 0x0092fbb6u); call_indirect(c, t_); } /* call dword ptr [0x100452e8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092fbbe; /* jne 0x92fbbe */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fbbe:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (!c->zf) goto L_0092fbe6; /* jne 0x92fbe6 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x0092fbe1u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_0092fc0a; /* jmp 0x92fc0a */
L_0092fbe6:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x220u; PUSH32(c, v_); } /* push 0x220 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x0092fc07u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_0092fc0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    goto L_0092fc11; /* jmp 0x92fc11 */
L_0092fc11:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffccu)); /* lea esp, [ebp - 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fc30(CPU *c) { /* FUN_1001fc30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
L_0092fc3e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_0092fc62; /* jne 0x92fc62 */
    { uint32_t v_ = 0x94bda0u; PUSH32(c, v_); } /* push 0x1003bda0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x3au; PUSH32(c, v_); } /* push 0x3a */
    { uint32_t v_ = 0x94bd94u; PUSH32(c, v_); } /* push 0x1003bd94 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x0092fc59u); f_00917190(c); /* call 0x917190 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_0092fc62; /* jne 0x92fc62 */
    guest_trap(c, 0x0092fc61u, "int3"); /* int3  */
L_0092fc62:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092fc3e; /* jne 0x92fc3e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x40u))); /* and edx, 0x40 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0092fc81; /* je 0x92fc81 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0xc], 0 */
    goto L_0092fca8; /* jmp 0x92fca8 */
L_0092fc81:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092fc8au); f_0092c8e0(c); /* call 0x92c8e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092fc96u); f_0092fcc0(c); /* call 0x92fcc0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092fca5u); f_0092c950(c); /* call 0x92c950 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_0092fca8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fcc0(CPU *c) { /* FUN_1001fcc0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_0092fcd6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_0092fcfa; /* jne 0x92fcfa */
    { uint32_t v_ = 0x94b3acu; PUSH32(c, v_); } /* push 0x1003b3ac */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x77u; PUSH32(c, v_); } /* push 0x77 */
    { uint32_t v_ = 0x94bd94u; PUSH32(c, v_); } /* push 0x1003bd94 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x0092fcf1u); f_00917190(c); /* call 0x917190 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_0092fcfa; /* jne 0x92fcfa */
    guest_trap(c, 0x0092fcf9u, "int3"); /* int3  */
L_0092fcfa:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0092fcd6; /* jne 0x92fcd6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x83u))); /* and eax, 0x83 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092fd6a; /* je 0x92fd6a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092fd18u); f_0092ed90(c); /* call 0x92ed90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092fd27u); f_00930090(c); /* call 0x930090 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x10u))); /* mov ecx, dword ptr [eax + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092fd36u); f_0092ff60(c); /* call 0x92ff60 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_0092fd46; /* jge 0x92fd46 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    goto L_0092fd6a; /* jmp 0x92fd6a */
L_0092fd46:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->edx + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [edx + 0x1c], 0 */
    if (c->zf) goto L_0092fd6a; /* je 0x92fd6a */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092fd5du); f_009193f0(c); /* call 0x9193f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->edx + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx + 0x1c], 0 */
L_0092fd6a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 0xc], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fd80(CPU *c) { /* FUN_1001fd80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9545dcu))); /* cmp eax, dword ptr [0x100445dc] */
    if (!c->cf) goto L_0092fdb1; /* jae 0x92fdb1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1fu))); /* and edx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x24u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x24 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9544a0u))); /* mov eax, dword ptr [ecx*4 + 0x100444a0] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax + c->edx + 0x4u))); /* movsx ecx, byte ptr [eax + edx + 4] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u))); /* and ecx, 1 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0092fdc4; /* jne 0x92fdc4 */
L_0092fdb1:;
    PUSH32(c, 0x0092fdb6u); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0092fe4e; /* jmp 0x92fe4e */
L_0092fdc4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092fdcdu); f_0092eb50(c); /* call 0x92eb50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx + c->ecx + 0x4u))); /* movsx eax, byte ptr [edx + ecx + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092fe2d; /* je 0x92fe2d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092fdfbu); f_0092e9d0(c); /* call 0x92e9d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552ecu)); PUSH32(c, 0x0092fe05u); call_indirect(c, t_); } /* call dword ptr [0x100452ec] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092fe14; /* jne 0x92fe14 */
    { uint32_t t_ = R32((uint32_t)(0x9551f0u)); PUSH32(c, 0x0092fe0fu); call_indirect(c, t_); } /* call dword ptr [0x100451f0] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    goto L_0092fe1b; /* jmp 0x92fe1b */
L_0092fe14:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
L_0092fe1b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (!c->zf) goto L_0092fe23; /* jne 0x92fe23 */
    goto L_0092fe3f; /* jmp 0x92fe3f */
L_0092fe23:;
    PUSH32(c, 0x0092fe28u); f_00928820(c); /* call 0x928820 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_0092fe2d:;
    PUSH32(c, 0x0092fe32u); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
L_0092fe3f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092fe48u); f_0092ebe0(c); /* call 0x92ebe0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_0092fe4e:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fe60(CPU *c) { /* FUN_1001fe60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092fe6bu); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092fe77u); f_0092fe90(c); /* call 0x92fe90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    PUSH32(c, 0x0092fe84u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092fe90(CPU *c) { /* FID_conflict:__getenv_lk */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov eax, dword ptr [0x10042ae8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, R32((uint32_t)(0x9545ecu)), (uint32_t)0x0u); /* cmp dword ptr [0x100445ec], 0 */
    if (!c->zf) goto L_0092feae; /* jne 0x92feae */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092ff52; /* jmp 0x92ff52 */
L_0092feae:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if (!c->zf) goto L_0092fed6; /* jne 0x92fed6 */
    (void)sub32(c, R32((uint32_t)(0x952af0u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042af0], 0 */
    if (c->zf) goto L_0092fed6; /* je 0x92fed6 */
    PUSH32(c, 0x0092fec2u); f_00930180(c); /* call 0x930180 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0092fecd; /* je 0x92fecd */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0092ff52; /* jmp 0x92ff52 */
L_0092fecd:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov ecx, dword ptr [0x10042ae8] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_0092fed6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if (c->zf) goto L_0092ff50; /* je 0x92ff50 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_0092ff50; /* je 0x92ff50 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092feebu); f_0091e130(c); /* call 0x91e130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_0092fef1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_0092ff50; /* je 0x92ff50 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092ff04u); f_0091e130(c); /* call 0x91e130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffffcu))); /* cmp eax, dword ptr [ebp - 4] */
    if ((c->cf || c->zf)) goto L_0092ff45; /* jbe 0x92ff45 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx + c->edx))); /* movsx eax, byte ptr [ecx + edx] */
    (void)sub32(c, c->eax, (uint32_t)0x3du); /* cmp eax, 0x3d */
    if (!c->zf) goto L_0092ff45; /* jne 0x92ff45 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092ff30u); f_00930130(c); /* call 0x930130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0092ff45; /* jne 0x92ff45 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx + 0x1u)); /* lea eax, [eax + ecx + 1] */
    goto L_0092ff52; /* jmp 0x92ff52 */
L_0092ff45:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    goto L_0092fef1; /* jmp 0x92fef1 */
L_0092ff50:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0092ff52:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ff60(CPU *c) { /* FUN_1001ff60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, R32((uint32_t)(0x9545dcu))); /* cmp eax, dword ptr [0x100445dc] */
    if (!c->cf) goto L_0092ff91; /* jae 0x92ff91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x1fu))); /* and edx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->edx * (int32_t)(uint32_t)0x24u; c->edx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul edx, edx, 0x24 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x9544a0u))); /* mov eax, dword ptr [ecx*4 + 0x100444a0] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax + c->edx + 0x4u))); /* movsx ecx, byte ptr [eax + edx + 4] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u))); /* and ecx, 1 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_0092ffac; /* jne 0x92ffac */
L_0092ff91:;
    PUSH32(c, 0x0092ff96u); f_00928810(c); /* call 0x928810 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x9u)); /* mov dword ptr [eax], 9 */
    PUSH32(c, 0x0092ffa1u); f_00928820(c); /* call 0x928820 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0092ffd6; /* jmp 0x92ffd6 */
L_0092ffac:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0092ffb5u); f_0092eb50(c); /* call 0x92eb50 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092ffc1u); f_0092ffe0(c); /* call 0x92ffe0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0092ffd0u); f_0092ebe0(c); /* call 0x92ebe0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_0092ffd6:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0092ffe0(CPU *c) { /* __close_lk */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0092ffeeu); f_0092e9d0(c); /* call 0x92e9d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00930033; /* je 0x930033 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 8], 1 */
    if (c->zf) goto L_00930002; /* je 0x930002 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x2u); /* cmp dword ptr [ebp + 8], 2 */
    if (!c->zf) goto L_0093001c; /* jne 0x93001c */
L_00930002:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00930009u); f_0092e9d0(c); /* call 0x92e9d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x00930015u); f_0092e9d0(c); /* call 0x92e9d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->zf) goto L_00930033; /* je 0x930033 */
L_0093001c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00930025u); f_0092e9d0(c); /* call 0x92e9d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552f0u)); PUSH32(c, 0x0093002fu); call_indirect(c, t_); } /* call dword ptr [0x100452f0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_0093003c; /* je 0x93003c */
L_00930033:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    goto L_00930045; /* jmp 0x930045 */
L_0093003c:;
    { uint32_t t_ = R32((uint32_t)(0x9551f0u)); PUSH32(c, 0x00930042u); call_indirect(c, t_); } /* call dword ptr [0x100451f0] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_00930045:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x0093004eu); f_0092e8f0(c); /* call 0x92e8f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1fu))); /* and ecx, 0x1f */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x24u; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x24 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x9544a0u))); /* mov edx, dword ptr [eax*4 + 0x100444a0] */
    W8((uint32_t)(c->edx + c->ecx + 0x4u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edx + ecx + 4], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00930083; /* je 0x930083 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x0093007bu); f_00928770(c); /* call 0x928770 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_00930085; /* jmp 0x930085 */
L_00930083:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00930085:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930090(CPU *c) { /* FUN_10020090 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_00930096:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_009300ba; /* jne 0x9300ba */
    { uint32_t v_ = 0x94bda0u; PUSH32(c, v_); } /* push 0x1003bda0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = 0x94bdb0u; PUSH32(c, v_); } /* push 0x1003bdb0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x009300b1u); f_00917190(c); /* call 0x917190 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009300ba; /* jne 0x9300ba */
    guest_trap(c, 0x009300b9u, "int3"); /* int3  */
L_009300ba:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00930096; /* jne 0x930096 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x83u))); /* and edx, 0x83 */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_0093011d; /* je 0x93011d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ecx, dword ptr [eax + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x8u))); /* and ecx, 8 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_0093011d; /* je 0x93011d */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009300ebu); f_009193f0(c); /* call 0x9193f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffbf7u))); /* and edx, 0xfffffbf7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx + 8], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax + 4], 0 */
L_0093011d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930130(CPU *c) { /* __mbsnbicoll */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x10], 0 */
    if (!c->zf) goto L_0093013e; /* jne 0x93013e */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0093017b; /* jmp 0x93017b */
L_0093013e:;
    c->eax = (uint32_t)(R32((uint32_t)(0x9541b8u))); /* mov eax, dword ptr [0x100441b8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->edx = (uint32_t)(R32((uint32_t)(0x954444u))); /* mov edx, dword ptr [0x10044444] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00930162u); f_00930230(c); /* call 0x930230 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (!c->zf) goto L_00930175; /* jne 0x930175 */
    c->eax = (uint32_t)((uint32_t)0x7fffffffu); /* mov eax, 0x7fffffff */
    goto L_0093017b; /* jmp 0x93017b */
L_00930175:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2u)); /* sub eax, 2 */
L_0093017b:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930180(CPU *c) { /* FUN_10020180 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(0x952af0u))); /* mov eax, dword ptr [0x10042af0] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
L_0093018e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->ecx)), (uint32_t)0x0u); /* cmp dword ptr [ecx], 0 */
    if (c->zf) goto L_00930228; /* je 0x930228 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x009301b4u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_009301c2; /* jne 0x9301c2 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093022a; /* jmp 0x93022a */
L_009301c2:;
    { uint32_t v_ = 0x3du; PUSH32(c, v_); } /* push 0x3d */
    { uint32_t v_ = 0x94bdbcu; PUSH32(c, v_); } /* push 0x1003bdbc */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009301d4u); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if (!c->zf) goto L_009301e5; /* jne 0x9301e5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093022a; /* jmp 0x93022a */
L_009301e5:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(0x955250u)); PUSH32(c, 0x00930203u); call_indirect(c, t_); } /* call dword ptr [0x10045250] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0093020c; /* jne 0x93020c */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093022a; /* jmp 0x93022a */
L_0093020c:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930217u); f_00930680(c); /* call 0x930680 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    goto L_0093018e; /* jmp 0x93018e */
L_00930228:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0093022a:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930230(CPU *c) { /* FUN_10020230 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x94be10u; PUSH32(c, v_); } /* push 0x1003be10 */
    { uint32_t v_ = 0x91ef60u; PUSH32(c, v_); } /* push 0x1000ef60 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffc8u)); /* add esp, -0x38 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    (void)sub32(c, R32((uint32_t)(0x952e34u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042e34], 0 */
    if (!c->zf) goto L_009302b6; /* jne 0x9302b6 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x94b2b4u; PUSH32(c, v_); } /* push 0x1003b2b4 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x94b2b4u; PUSH32(c, v_); } /* push 0x1003b2b4 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x9552f8u)); PUSH32(c, 0x00930277u); call_indirect(c, t_); } /* call dword ptr [0x100452f8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00930287; /* je 0x930287 */
    W32((uint32_t)(0x952e34u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10042e34], 1 */
    goto L_009302b6; /* jmp 0x9302b6 */
L_00930287:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x94b2b0u; PUSH32(c, v_); } /* push 0x1003b2b0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x94b2b0u; PUSH32(c, v_); } /* push 0x1003b2b0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x9552f4u)); PUSH32(c, 0x0093029fu); call_indirect(c, t_); } /* call dword ptr [0x100452f4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_009302af; /* je 0x9302af */
    W32((uint32_t)(0x952e34u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x10042e34], 2 */
    goto L_009302b6; /* jmp 0x9302b6 */
L_009302af:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009302b6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if ((c->zf || c->sf != c->of)) goto L_009302cf; /* jle 0x9302cf */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009302c9u); f_00930630(c); /* call 0x930630 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
L_009302cf:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if ((c->zf || c->sf != c->of)) goto L_009302e8; /* jle 0x9302e8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009302e2u); f_00930630(c); /* call 0x930630 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1c], eax */
L_009302e8:;
    (void)sub32(c, R32((uint32_t)(0x952e34u)), (uint32_t)0x2u); /* cmp dword ptr [0x10042e34], 2 */
    if (!c->zf) goto L_00930314; /* jne 0x930314 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552f4u)); PUSH32(c, 0x0093030fu); call_indirect(c, t_); } /* call dword ptr [0x100452f4] */
    goto L_00930614; /* jmp 0x930614 */
L_00930314:;
    (void)sub32(c, R32((uint32_t)(0x952e34u)), (uint32_t)0x1u); /* cmp dword ptr [0x10042e34], 1 */
    if (!c->zf) goto L_00930612; /* jne 0x930612 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    if (!c->zf) goto L_00930330; /* jne 0x930330 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952cecu))); /* mov ecx, dword ptr [0x10042cec] */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 0x20], ecx */
L_00930330:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00930340; /* je 0x930340 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_009304bc; /* jne 0x9304bc */
L_00930340:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ebp + 0x1cu))); /* cmp edx, dword ptr [ebp + 0x1c] */
    if (!c->zf) goto L_00930352; /* jne 0x930352 */
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_00930614; /* jmp 0x930614 */
L_00930352:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 0x1c], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00930362; /* jle 0x930362 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00930614; /* jmp 0x930614 */
L_00930362:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 0x14], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00930372; /* jle 0x930372 */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    goto L_00930614; /* jmp 0x930614 */
L_00930372:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc4u)); /* lea eax, [ebp - 0x3c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x9552acu)); PUSH32(c, 0x00930380u); call_indirect(c, t_); } /* call dword ptr [0x100452ac] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0093038b; /* jne 0x93038b */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_0093038b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (!c->zf) goto L_00930397; /* jne 0x930397 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 0x1c], 1 */
    if (c->zf) goto L_009303c4; /* je 0x9303c4 */
L_00930397:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 0x14], 1 */
    if (!c->zf) goto L_009303a3; /* jne 0x9303a3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_009303c4; /* je 0x9303c4 */
L_009303a3:;
    { uint32_t v_ = 0x94bdd0u; PUSH32(c, v_); } /* push 0x1003bdd0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xb6u; PUSH32(c, v_); } /* push 0xb6 */
    { uint32_t v_ = 0x94bdc8u; PUSH32(c, v_); } /* push 0x1003bdc8 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x009303bbu); f_00917190(c); /* call 0x917190 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_009303c4; /* jne 0x9303c4 */
    guest_trap(c, 0x009303c3u, "int3"); /* int3  */
L_009303c4:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_0093038b; /* jne 0x93038b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00930443; /* jle 0x930443 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffc4u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x3c], 2 */
    if (!c->cf) goto L_009303e0; /* jae 0x9303e0 */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    goto L_00930614; /* jmp 0x930614 */
L_009303e0:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffcau)); /* lea eax, [ebp - 0x36] */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
    goto L_009303f1; /* jmp 0x9303f1 */
L_009303e8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov ecx, dword ptr [ebp - 0x40] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x40], ecx */
L_009303f1:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00930439; /* je 0x930439 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov ecx, dword ptr [ebp - 0x40] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x1u))); /* mov dl, byte ptr [ecx + 1] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00930439; /* je 0x930439 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf != c->of)) goto L_00930437; /* jl 0x930437 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov eax, dword ptr [ebp - 0x40] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    (void)sub32(c, c->edx, c->ecx); /* cmp edx, ecx */
    if ((!c->zf && c->sf == c->of)) goto L_00930437; /* jg 0x930437 */
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_00930614; /* jmp 0x930614 */
L_00930437:;
    goto L_009303e8; /* jmp 0x9303e8 */
L_00930439:;
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    goto L_00930614; /* jmp 0x930614 */
L_00930443:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if ((c->zf || c->sf != c->of)) goto L_009304bc; /* jle 0x9304bc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffc4u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x3c], 2 */
    if (!c->cf) goto L_00930459; /* jae 0x930459 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00930614; /* jmp 0x930614 */
L_00930459:;
    c->edx = (uint32_t)((uint32_t)(c->ebp + 0xffffffcau)); /* lea edx, [ebp - 0x36] */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x40], edx */
    goto L_0093046a; /* jmp 0x93046a */
L_00930461:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov eax, dword ptr [ebp - 0x40] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
L_0093046a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov ecx, dword ptr [ebp - 0x40] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_009304b2; /* je 0x9304b2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov eax, dword ptr [ebp - 0x40] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_009304b2; /* je 0x9304b2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov ecx, dword ptr [ebp - 0x40] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_009304b0; /* jl 0x9304b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffc0u))); /* mov edx, dword ptr [ebp - 0x40] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx + 0x1u))); /* mov al, byte ptr [edx + 1] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_009304b0; /* jg 0x9304b0 */
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_00930614; /* jmp 0x930614 */
L_009304b0:;
    goto L_00930461; /* jmp 0x930461 */
L_009304b2:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00930614; /* jmp 0x930614 */
L_009304bc:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x009304d4u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_009304e4; /* jne 0x9304e4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009304e4:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x009304fau); f_0091e6b0(c); /* call 0x91e6b0 */
    W32((uint32_t)(c->ebp + 0xffffffbcu), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x44], esp */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffbcu))); /* mov ecx, dword ptr [ebp - 0x44] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x24], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    goto L_00930526; /* jmp 0x930526 */
L_00930526:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00930533; /* jne 0x930533 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_00930533:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x0093054fu); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0093055a; /* jne 0x93055a */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_0093055a:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x00930572u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_00930582; /* jne 0x930582 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_00930582:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00930598u); f_0091e6b0(c); /* call 0x91e6b0 */
    W32((uint32_t)(c->ebp + 0xffffffb8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x48], esp */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffb8u))); /* mov ecx, dword ptr [ebp - 0x48] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x28], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    goto L_009305c4; /* jmp 0x9305c4 */
L_009305c4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_009305ce; /* jne 0x9305ce */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009305ce:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov edx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x009305eau); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009305f2; /* jne 0x9305f2 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009305f2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov edx, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552f8u)); PUSH32(c, 0x00930610u); call_indirect(c, t_); } /* call dword ptr [0x100452f8] */
    goto L_00930614; /* jmp 0x930614 */
L_00930612:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00930614:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffacu)); /* lea esp, [ebp - 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_0093050f(CPU *c) { /* PTR_0093050f */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00930515(CPU *c) { /* PTR_00930515 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00930533; /* jne 0x930533 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_00930533:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edx, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x0093054fu); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_0093055a; /* jne 0x93055a */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_0093055a:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x00930572u); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_00930582; /* jne 0x930582 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_00930582:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfcu))); /* and al, 0xfc */
    PUSH32(c, 0x00930598u); f_0091e6b0(c); /* call 0x91e6b0 */
    W32((uint32_t)(c->ebp + 0xffffffb8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x48], esp */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffb8u))); /* mov ecx, dword ptr [ebp - 0x48] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x28], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    goto L_009305c4; /* jmp 0x9305c4 */
L_009305c4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_009305ce; /* jne 0x9305ce */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009305ce:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov edx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x009305eau); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009305f2; /* jne 0x9305f2 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009305f2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov edx, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552f8u)); PUSH32(c, 0x00930610u); call_indirect(c, t_); } /* call dword ptr [0x100452f8] */
    goto L_00930614; /* jmp 0x930614 */
L_00930614:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffacu)); /* lea esp, [ebp - 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009305ad(CPU *c) { /* PTR_009305ad */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_009305b3(CPU *c) { /* PTR_009305b3 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_009305ce; /* jne 0x9305ce */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009305ce:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov edx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edx, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552a0u)); PUSH32(c, 0x009305eau); call_indirect(c, t_); } /* call dword ptr [0x100452a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009305f2; /* jne 0x9305f2 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930614; /* jmp 0x930614 */
L_009305f2:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov edx, dword ptr [ebp - 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov ecx, dword ptr [ebp - 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552f8u)); PUSH32(c, 0x00930610u); call_indirect(c, t_); } /* call dword ptr [0x100452f8] */
    goto L_00930614; /* jmp 0x930614 */
L_00930614:;
    c->esp = (uint32_t)((uint32_t)(c->ebp + 0xffffffacu)); /* lea esp, [ebp - 0x54] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930630(CPU *c) { /* FUN_10020630 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
L_00930642:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1u)); /* sub eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00930667; /* je 0x930667 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx))); /* movsx edx, byte ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00930667; /* je 0x930667 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    goto L_00930642; /* jmp 0x930642 */
L_00930667:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->ecx))); /* movsx edx, byte ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_00930679; /* jne 0x930679 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u)))); /* sub eax, dword ptr [ebp + 8] */
    goto L_0093067c; /* jmp 0x93067c */
L_00930679:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_0093067c:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930680(CPU *c) { /* FUN_10020680 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_009306ac; /* je 0x9306ac */
    { uint32_t v_ = 0x3du; PUSH32(c, v_); } /* push 0x3d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930698u); f_00930ad0(c); /* call 0x930ad0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x18], 0 */
    if (c->zf) goto L_009306ac; /* je 0x9306ac */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp ecx, dword ptr [ebp - 0x18] */
    if (!c->zf) goto L_009306b4; /* jne 0x9306b4 */
L_009306ac:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093095b; /* jmp 0x93095b */
L_009306b4:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov edx, dword ptr [ebp - 0x18] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx + 0x1u))); /* movsx eax, byte ptr [edx + 1] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov ecx, dword ptr [0x10042ae8] */
    (void)sub32(c, c->ecx, R32((uint32_t)(0x952aecu))); /* cmp ecx, dword ptr [0x10042aec] */
    if (!c->zf) goto L_009306e5; /* jne 0x9306e5 */
    c->edx = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov edx, dword ptr [0x10042ae8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009306ddu); f_009309e0(c); /* call 0x9309e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    W32((uint32_t)(0x952ae8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10042ae8], eax */
L_009306e5:;
    (void)sub32(c, R32((uint32_t)(0x952ae8u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042ae8], 0 */
    if (!c->zf) goto L_009307a5; /* jne 0x9307a5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00930717; /* je 0x930717 */
    (void)sub32(c, R32((uint32_t)(0x952af0u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042af0], 0 */
    if (c->zf) goto L_00930717; /* je 0x930717 */
    PUSH32(c, 0x00930706u); f_00930180(c); /* call 0x930180 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00930712; /* je 0x930712 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093095b; /* jmp 0x93095b */
L_00930712:;
    goto L_009307a5; /* jmp 0x9307a5 */
L_00930717:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_00930724; /* je 0x930724 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0093095b; /* jmp 0x93095b */
L_00930724:;
    (void)sub32(c, R32((uint32_t)(0x952ae8u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042ae8], 0 */
    if (!c->zf) goto L_00930764; /* jne 0x930764 */
    { uint32_t v_ = 0x87u; PUSH32(c, v_); } /* push 0x87 */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x00930740u); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(0x952ae8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10042ae8], eax */
    (void)sub32(c, R32((uint32_t)(0x952ae8u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042ae8], 0 */
    if (!c->zf) goto L_00930759; /* jne 0x930759 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093095b; /* jmp 0x93095b */
L_00930759:;
    c->eax = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov eax, dword ptr [0x10042ae8] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
L_00930764:;
    (void)sub32(c, R32((uint32_t)(0x952af0u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042af0], 0 */
    if (!c->zf) goto L_009307a5; /* jne 0x9307a5 */
    { uint32_t v_ = 0x8eu; PUSH32(c, v_); } /* push 0x8e */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    PUSH32(c, 0x00930780u); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(0x952af0u), (uint32_t)(c->eax)); /* mov dword ptr [0x10042af0], eax */
    (void)sub32(c, R32((uint32_t)(0x952af0u)), (uint32_t)0x0u); /* cmp dword ptr [0x10042af0], 0 */
    if (!c->zf) goto L_00930799; /* jne 0x930799 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093095b; /* jmp 0x93095b */
L_00930799:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x952af0u))); /* mov ecx, dword ptr [0x10042af0] */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx], 0 */
L_009307a5:;
    c->edx = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov edx, dword ptr [0x10042ae8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x8u)))); /* sub eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009307beu); f_00930960(c); /* call 0x930960 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if ((c->sf != c->of)) goto L_00930861; /* jl 0x930861 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0x0u); /* cmp dword ptr [edx], 0 */
    if (c->zf) goto L_00930861; /* je 0x930861 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (c->zf) goto L_00930853; /* je 0x930853 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov edx, dword ptr [ecx + eax*4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x009307f1u); f_009193f0(c); /* call 0x9193f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_009307ff; /* jmp 0x9307ff */
L_009307f6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_009307ff:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    (void)sub32(c, R32((uint32_t)(c->edx + c->ecx * 4)), (uint32_t)0x0u); /* cmp dword ptr [edx + ecx*4], 0 */
    if (c->zf) goto L_00930820; /* je 0x930820 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov esi, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + c->edx * 4 + 0x4u))); /* mov edx, dword ptr [esi + edx*4 + 4] */
    W32((uint32_t)(c->ecx + c->eax * 4), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4], edx */
    goto L_009307f6; /* jmp 0x9307f6 */
L_00930820:;
    { uint32_t v_ = 0xb9u; PUSH32(c, v_); } /* push 0xb9 */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x0093083cu); f_00918d40(c); /* call 0x918d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (c->zf) goto L_00930851; /* je 0x930851 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x952ae8u), (uint32_t)(c->edx)); /* mov dword ptr [0x10042ae8], edx */
L_00930851:;
    goto L_0093085f; /* jmp 0x93085f */
L_00930853:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ecx + c->eax * 4), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*4], edx */
L_0093085f:;
    goto L_009308d4; /* jmp 0x9308d4 */
L_00930861:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x14], 0 */
    if (!c->zf) goto L_009308cd; /* jne 0x9308cd */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 8], 0 */
    if ((c->sf == c->of)) goto L_00930875; /* jge 0x930875 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_00930875:;
    { uint32_t v_ = 0xceu; PUSH32(c, v_); } /* push 0xce */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)((uint32_t)(c->ecx * 4 + 0x8u)); /* lea edx, [ecx*4 + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930895u); f_00918d40(c); /* call 0x918d40 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if (!c->zf) goto L_009308a9; /* jne 0x9308a9 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    goto L_0093095b; /* jmp 0x93095b */
L_009308a9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->edx + c->ecx * 4), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx*4], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edx, dword ptr [ebp - 0xc] */
    W32((uint32_t)(c->edx + c->ecx * 4 + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edx + ecx*4 + 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    W32((uint32_t)(0x952ae8u), (uint32_t)(c->eax)); /* mov dword ptr [0x10042ae8], eax */
    goto L_009308d4; /* jmp 0x9308d4 */
L_009308cd:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_0093095b; /* jmp 0x93095b */
L_009308d4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00930959; /* je 0x930959 */
    { uint32_t v_ = 0xe5u; PUSH32(c, v_); } /* push 0xe5 */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x009308efu); f_0091e130(c); /* call 0x91e130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x009308fbu); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (c->zf) goto L_00930959; /* je 0x930959 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930914u); f_0091e040(c); /* call 0x91e040 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov ecx, dword ptr [ebp - 0x18] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0x8u)))); /* sub ecx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edx, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(add32(c, c->edx, c->ecx)); /* add edx, ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [eax], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov edx, dword ptr [ebp - 0x14] */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    c->edx = (uint32_t)(sbb32(c, c->edx, c->edx)); /* sbb edx, edx */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* and edx, dword ptr [ebp - 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x9552fcu)); PUSH32(c, 0x0093094bu); call_indirect(c, t_); } /* call dword ptr [0x100452fc] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00930956u); f_009193f0(c); /* call 0x9193f0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00930959:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_0093095b:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930960(CPU *c) { /* findenv */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x952ae8u))); /* mov eax, dword ptr [0x10042ae8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    goto L_00930977; /* jmp 0x930977 */
L_0093096e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
L_00930977:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0x0u); /* cmp dword ptr [edx], 0 */
    if (c->zf) goto L_009309ca; /* je 0x9309ca */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930992u); f_00930130(c); /* call 0x930130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_009309c8; /* jne 0x9309c8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->edx + c->eax))); /* movsx ecx, byte ptr [edx + eax] */
    (void)sub32(c, c->ecx, (uint32_t)0x3du); /* cmp ecx, 0x3d */
    if (c->zf) goto L_009309ba; /* je 0x9309ba */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->eax + c->ecx))); /* movsx edx, byte ptr [eax + ecx] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (!c->zf) goto L_009309c8; /* jne 0x9309c8 */
L_009309ba:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(0x952ae8u)))); /* sub eax, dword ptr [0x10042ae8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 2)); /* sar eax, 2 */
    goto L_009309d8; /* jmp 0x9309d8 */
L_009309c8:;
    goto L_0093096e; /* jmp 0x93096e */
L_009309ca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(0x952ae8u)))); /* sub eax, dword ptr [0x10042ae8] */
    c->eax = (uint32_t)(sar32(c, c->eax, 2)); /* sar eax, 2 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_009309d8:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_009309e0(CPU *c) { /* copy_environ */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp - 0x10], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (!c->zf) goto L_00930a00; /* jne 0x930a00 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930aca; /* jmp 0x930aca */
L_00930a00:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00930a1d; /* je 0x930a1d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x1u)); /* add ecx, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0x10], ecx */
    goto L_00930a00; /* jmp 0x930a00 */
L_00930a1d:;
    { uint32_t v_ = 0x146u; PUSH32(c, v_); } /* push 0x146 */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edx, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->edx * 4 + 0x4u)); /* lea eax, [edx*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930a39u); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 4], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (!c->zf) goto L_00930a55; /* jne 0x930a55 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00930a52u); f_00916590(c); /* call 0x916590 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00930a55:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0xc], edx */
L_00930a5b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (c->zf) goto L_00930abe; /* je 0x930abe */
    { uint32_t v_ = 0x14fu; PUSH32(c, v_); } /* push 0x14f */
    { uint32_t v_ = 0x94be28u; PUSH32(c, v_); } /* push 0x1003be28 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00930a7au); f_0091e130(c); /* call 0x91e130 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1u)); /* add eax, 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930a86u); f_00918850(c); /* call 0x918850 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    (void)sub32(c, R32((uint32_t)(c->edx)), (uint32_t)0x0u); /* cmp dword ptr [edx], 0 */
    if (c->zf) goto L_00930aaa; /* je 0x930aaa */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00930aa7u); f_0091e040(c); /* call 0x91e040 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_00930aaa:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 0xc], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 8], edx */
    goto L_00930a5b; /* jmp 0x930a5b */
L_00930abe:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00930aca:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930ad0(CPU *c) { /* FUN_10020ad0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0x95423cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1004423c], 0 */
    if (!c->zf) goto L_00930af2; /* jne 0x930af2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00930aeau); f_00925290(c); /* call 0x925290 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    goto L_00930bb9; /* jmp 0x930bb9 */
L_00930af2:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00930af9u); f_0091cbf0(c); /* call 0x91cbf0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    goto L_00930b07; /* jmp 0x930b07 */
L_00930afe:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1u)); /* add edx, 1 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 8], edx */
L_00930b07:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx cx, byte ptr [eax] */
    W16((uint32_t)(c->ebp + 0xfffffffcu), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [ebp - 4], cx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00930b9b; /* je 0x930b9b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x954341u))); /* mov cl, byte ptr [eax + 0x10044341] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x4u))); /* and ecx, 4 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00930b86; /* je 0x930b86 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x1u)); /* add edx, 1 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 8], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00930b58; /* jne 0x930b58 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00930b51u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00930bb9; /* jmp 0x930bb9 */
L_00930b58:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    c->edx = (uint32_t)(shl32(c, c->edx, 8)); /* shl edx, 8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | c->ecx))); /* or edx, ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (!c->zf) goto L_00930b84; /* jne 0x930b84 */
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00930b79u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1u)); /* sub eax, 1 */
    goto L_00930bb9; /* jmp 0x930bb9 */
L_00930b84:;
    goto L_00930b96; /* jmp 0x930b96 */
L_00930b86:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov edx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edx); /* cmp dword ptr [ebp + 0xc], edx */
    if (!c->zf) goto L_00930b96; /* jne 0x930b96 */
    goto L_00930b9b; /* jmp 0x930b9b */
L_00930b96:;
    goto L_00930afe; /* jmp 0x930afe */
L_00930b9b:;
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x00930ba2u); f_0091cc90(c); /* call 0x91cc90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->eax); /* cmp dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00930bb7; /* jne 0x930bb7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    goto L_00930bb9; /* jmp 0x930bb9 */
L_00930bb7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00930bb9:;
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00930bc0(CPU *c) { /* KERNEL32.DLL::RtlUnwind */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x9551ccu)); switch (t_) {  default: jump_indirect(c, t_, 0x00930bc0u); return; } } /* jmp dword ptr [0x100451cc] */
}

void f_00930bc6(CPU *c) { /* PTR_00930bc6 */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x9551d0u)); switch (t_) {  default: jump_indirect(c, t_, 0x00930bc6u); return; } } /* jmp dword ptr [0x100451d0] */
}

void f_00938c0f(CPU *c) { /* PTR_00938c0f */
    PREEMPT_POLL(c);
    guest_trap(c, 0x00938c0fu, "int3"); /* int3  */
}

void f_00938c40(CPU *c) { /* Unwind@10028c40 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    { uint32_t v_ = 0x94a060u; PUSH32(c, v_); } /* push 0x1003a060 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00938c50u); f_009110e1(c); /* call 0x9110e1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00938c54(CPU *c) { /* PTR_00938c54 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x94c4f4u); /* mov eax, 0x1003c4f4 */
    { f_00915340(c); return; } /* jmp 0x915340 */
}

void f_00938c70(CPU *c) { /* Unwind@10028c70 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x00938c78u); f_009110b9(c); /* call 0x9110b9 */
    c->esp += 4; return; /* ret  */
}

void f_00938c79(CPU *c) { /* Unwind@10028c79 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x68u)); /* add ecx, 0x68 */
    PUSH32(c, 0x00938c84u); f_009110f0(c); /* call 0x9110f0 */
    c->esp += 4; return; /* ret  */
}

void f_00938c85(CPU *c) { /* PTR_00938c85 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x94c524u); /* mov eax, 0x1003c524 */
    { f_00915340(c); return; } /* jmp 0x915340 */
}

void f_00938ca0(CPU *c) { /* Unwind@10028ca0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    PUSH32(c, 0x00938ca8u); f_009110b9(c); /* call 0x9110b9 */
    c->esp += 4; return; /* ret  */
}

void f_00938ca9(CPU *c) { /* PTR_00938ca9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x94c54cu); /* mov eax, 0x1003c54c */
    { f_00915340(c); return; } /* jmp 0x915340 */
}
