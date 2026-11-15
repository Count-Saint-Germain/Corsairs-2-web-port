#include "recomp.h"

void f_008a1000(CPU *c) { /* PTR_008a1000 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff38u))); /* mov ecx, dword ptr [0x1000ff38] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_008a100f; /* jne 0x8a100f */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
L_008a100f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a1019u); f_008a1030(c); /* call 0x8a1030 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a1030(CPU *c) { /* FUN_10001030 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x2cu)); /* sub esp, 0x2c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov edi, dword ptr [esp + 0x3c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov eax, dword ptr [edi + 0x18] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xcu)); /* test al, 0xc */
    if (c->zf) goto L_008a10b3; /* je 0x8a10b3 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov edx, dword ptr [edi + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x20u)); /* lea edx, [edi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x8ad0ccu; PUSH32(c, v_); } /* push 0x1000d0cc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a105fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ebx, dword ptr [esi + 0x14] */
    { uint32_t v_ = 0x1eu; PUSH32(c, v_); } /* push 0x1e */
    { uint32_t v_ = 0x8ad09cu; PUSH32(c, v_); } /* push 0x1000d09c */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea eax, [ebx + 1] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a107cu); f_008a1e30(c); /* call 0x8a1e30 */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 4)); /* shl ebx, 4 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    W32((uint32_t)(c->ebx + c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebx + eax], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->ecx + c->ebx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov ecx, dword ptr [edi + 0x18] */
    W32((uint32_t)(c->eax + c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + ebx + 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov eax, dword ptr [edi + 0x1c] */
    W32((uint32_t)(c->edx + c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + ebx + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_008a123b; /* jmp 0x8a123b */
L_008a10b3:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x3u)); /* test al, 3 */
    if (c->zf) goto L_008a11c7; /* je 0x8a11c7 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov edx, dword ptr [edi + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x20u)); /* lea edx, [edi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x8ad07cu; PUSH32(c, v_); } /* push 0x1000d07c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a10d7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ebx, dword ptr [esi + 0x14] */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = 0x8ad09cu; PUSH32(c, v_); } /* push 0x1000d09c */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea eax, [ebx + 1] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a10f4u); f_008a1e30(c); /* call 0x8a1e30 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 4)); /* shl ecx, 4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + eax], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->edx + c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx + 4], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov eax, dword ptr [edi + 0x18] */
    W32((uint32_t)(c->edx + c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx + 8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov eax, dword ptr [edi + 0x1c] */
    W32((uint32_t)(c->edx + c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx + 0xc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 0x20], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov ecx, dword ptr [edi + 0x18] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea ecx, [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x18u)); /* mov dword ptr [esp + 0x20], 0x18 */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x24], 0x10 */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x2c], 2 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x008a115cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a117d; /* jne 0x8a117d */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x8ad064u; PUSH32(c, v_); } /* push 0x1000d064 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x008a117au); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_008a117d:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov edx, dword ptr [edi + 0x18] */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x14u)); /* mov dword ptr [esp + 0xc], 0x14 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x10], 0x10 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x18], 2 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    if (c->zf) goto L_008a11ad; /* je 0x8a11ad */
    (void)sub32(c, c->ebx, (uint32_t)0x1u); /* cmp ebx, 1 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x9c4u)); /* mov dword ptr [esp + 0x1c], 0x9c4 */
    if (!c->zf) goto L_008a11b5; /* jne 0x8a11b5 */
L_008a11ad:;
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x1388u)); /* mov dword ptr [esp + 0x1c], 0x1388 */
L_008a11b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea edx, [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x18u)); PUSH32(c, 0x008a11c5u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x18] */
    goto L_008a123e; /* jmp 0x8a123e */
L_008a11c7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_008a123e; /* je 0x8a123e */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov edx, dword ptr [edi + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x20u)); /* lea edx, [edi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x8ad040u; PUSH32(c, v_); } /* push 0x1000d040 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a11e7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ebx, dword ptr [esi + 0x14] */
    { uint32_t v_ = 0x52u; PUSH32(c, v_); } /* push 0x52 */
    { uint32_t v_ = 0x8ad09cu; PUSH32(c, v_); } /* push 0x1000d09c */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x24], ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea eax, [ebx + 1] */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x14], eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a1207u); f_008a1e30(c); /* call 0x8a1e30 */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 4)); /* shl ebx, 4 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    W32((uint32_t)(c->ebx + c->eax), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebx + eax], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->ecx + c->ebx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + ebx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x18u))); /* mov ecx, dword ptr [edi + 0x18] */
    W32((uint32_t)(c->eax + c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + ebx + 8], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov eax, dword ptr [edi + 0x1c] */
    W32((uint32_t)(c->edx + c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + ebx + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
L_008a123b:;
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x20], eax */
L_008a123e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov ecx, dword ptr [esi + 0x1c] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_008a126c; /* jb 0x8a126c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    { uint32_t v_ = 0x5eu; PUSH32(c, v_); } /* push 0x5e */
    c->eax = (uint32_t)(shr32(c, c->eax, 2)); /* shr eax, 2 */
    { uint32_t v_ = 0x8ad09cu; PUSH32(c, v_); } /* push 0x1000d09c */
    c->eax = (uint32_t)((uint32_t)(c->eax * 4 + 0x4u)); /* lea eax, [eax*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1c], eax */
    PUSH32(c, 0x008a1266u); f_008a1e30(c); /* call 0x8a1e30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x18], eax */
L_008a126c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->esp += 8; return; /* ret 4 */
}

void f_008a1280(CPU *c) { /* FUN_10001280 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aa988u; PUSH32(c, v_); } /* push 0x1000a988 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 4], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov eax, dword ptr [esp + 0x3c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov ebp, dword ptr [esp + 0x50] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab0f8u)); /* mov dword ptr [esi], 0x1000b0f8 */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esi + 0x24], 0xffffffff */
    W32((uint32_t)(0x8aff38u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ff38], esi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W8((uint32_t)(c->ebp), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x44u)); /* lea edx, [esp + 0x44] */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x18], ebx */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x1c], ebx */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x20], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x44], ebx */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xcu)); PUSH32(c, 0x008a12f2u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a136d; /* jl 0x8a136d */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea edx, [esp + 0x50] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x8a1000u; PUSH32(c, v_); } /* push 0x10001000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x10u)); PUSH32(c, 0x008a1309u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a136d; /* jl 0x8a136d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x20], edx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x18u)); /* mov dword ptr [esp + 0x14], 0x18 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x28], ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x18], 0x10 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x1c], 1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x2cu)); PUSH32(c, 0x008a1347u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a136d; /* jl 0x8a136d */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x3c], edi */
    { uint32_t v_ = 0x5u; PUSH32(c, v_); } /* push 5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x008a1360u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x34u)); PUSH32(c, 0x008a1369u); call_indirect(c, t_); } /* call dword ptr [edi + 0x34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a1370; /* jge 0x8a1370 */
L_008a136d:;
    W8((uint32_t)(c->ebp), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp], bl */
L_008a1370:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 28; return; /* ret 0x18 */
}

void f_008a1390(CPU *c) { /* FUN_10001390 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x008a1398u); f_008a13b0(c); /* call 0x8a13b0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_008a13a8; /* je 0x8a13a8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a13a5u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a13a8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a13b0(CPU *c) { /* FUN_100013b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aa9a8u; PUSH32(c, v_); } /* push 0x1000a9a8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab0f8u)); /* mov dword ptr [esi], 0x1000b0f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a13f1; /* je 0x8a13f1 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x20u)); PUSH32(c, 0x008a13e8u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x008a13f1u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_008a13f1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a1401; /* je 0x8a1401 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a13feu); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a1401:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a1411; /* je 0x8a1411 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a140eu); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a1411:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab114u)); /* mov dword ptr [esi], 0x1000b114 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008a1430(CPU *c) { /* PTR_008a1430 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8ad0ecu); /* mov eax, 0x1000d0ec */
    c->esp += 4; return; /* ret  */
}

void f_008a1440(CPU *c) { /* PTR_008a1440 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov eax, dword ptr [ecx + 0x14] */
    c->esp += 4; return; /* ret  */
}

void f_008a1450(CPU *c) { /* PTR_008a1450 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    W8((uint32_t)(c->ecx + 0x4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx + 4], al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 4], ecx */
    if (c->zf) goto L_008a1467; /* je 0x8a1467 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); switch (t_) {  default: jump_indirect(c, t_, 0x008a1464u); return; } } /* jmp dword ptr [eax + 0x1c] */
L_008a1467:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a1469u); return; } } /* jmp dword ptr [edx + 0x20] */
}

void f_008a1470(CPU *c) { /* FUN_10001470 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov edx, dword ptr [esi + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x24u)); PUSH32(c, 0x008a1484u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x24] */
    (void)sub32(c, c->eax, (uint32_t)0x8007001eu); /* cmp eax, 0x8007001e */
    if (!c->zf) goto L_008a14a5; /* jne 0x8a14a5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x1cu)); PUSH32(c, 0x008a1494u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov ecx, dword ptr [esi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x008a14a5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
L_008a14a5:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a14b0(CPU *c) { /* PTR_008a14b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x4u))); /* mov al, byte ptr [ecx + 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (!c->zf) goto L_008a14ce; /* jne 0x8a14ce */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a14ce:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    (void)sub32(c, c->eax, (uint32_t)0x100u); /* cmp eax, 0x100 */
    if (c->cf) goto L_008a15d6; /* jb 0x8a15d6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x24u))); /* mov edx, dword ptr [ecx + 0x24] */
    (void)sub32(c, c->edx, (uint32_t)0xffffffffu); /* cmp edx, -1 */
    if (!c->zf) goto L_008a14f1; /* jne 0x8a14f1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a14f1:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov edi, dword ptr [ecx + 0x10] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, c->edi)); /* add edx, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x8u)) & (uint8_t)0x10u)); /* test byte ptr [edx + 8], 0x10 */
    if (c->zf) goto L_008a1669; /* je 0x8a1669 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov edx, dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov ecx, dword ptr [ecx + 0x18] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xffffff00u)); /* add eax, 0xffffff00 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx))); /* mov ecx, dword ptr [edx + ecx] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->cf && !c->zf)) goto L_008a1669; /* ja 0x8a1669 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x8a1670u)); switch (t_) { case 0x008a1523u: goto L_008a1523; case 0x008a152fu: goto L_008a152f; case 0x008a1547u: goto L_008a1547; case 0x008a155fu: goto L_008a155f; default: jump_indirect(c, t_, 0x008a151cu); return; } } /* jmp dword ptr [eax*4 + 0x10001670] */
L_008a1523:;
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x1194u); /* cmp ecx, 0x1194 */
    goto L_008a156d; /* jmp 0x8a156d */
L_008a152f:;
    (void)sub32(c, c->ecx, (uint32_t)0x1194u); /* cmp ecx, 0x1194 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x2328u); /* cmp ecx, 0x2328 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x34bcu); /* cmp ecx, 0x34bc */
    goto L_008a1575; /* jmp 0x8a1575 */
L_008a1547:;
    (void)sub32(c, c->ecx, (uint32_t)0x34bcu); /* cmp ecx, 0x34bc */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x4650u); /* cmp ecx, 0x4650 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x57e4u); /* cmp ecx, 0x57e4 */
    goto L_008a1575; /* jmp 0x8a1575 */
L_008a155f:;
    (void)sub32(c, c->ecx, (uint32_t)0x57e4u); /* cmp ecx, 0x57e4 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x6978u); /* cmp ecx, 0x6978 */
L_008a156d:;
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x7b0cu); /* cmp ecx, 0x7b0c */
L_008a1575:;
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
L_008a1589:;
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1594:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 8], 1 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 4], 0x3f800000 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
L_008a15ba:;
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15c9:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15d6:;
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x14u))); /* cmp eax, dword ptr [ecx + 0x14] */
    if (c->cf) goto L_008a15e2; /* jb 0x8a15e2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15e2:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov edx, dword ptr [ecx + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->edx)); /* add eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov edx, dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0xcu)); /* test dl, 0xc */
    if (c->zf) goto L_008a1633; /* je 0x8a1633 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov ecx, dword ptr [ecx + 0x18] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ecx))); /* mov dl, byte ptr [eax + ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    (void)sub8(c, ((uint8_t)c->edx), ((uint8_t)c->ebx)); /* cmp dl, bl */
    if (c->zf) goto L_008a161a; /* je 0x8a161a */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 8], 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 4], 0x3f800000 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    goto L_008a15ba; /* jmp 0x8a15ba */
L_008a161a:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    goto L_008a1589; /* jmp 0x8a1589 */
L_008a1633:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x3u)); /* test dl, 3 */
    if (c->zf) goto L_008a1669; /* je 0x8a1669 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->edx + c->eax))); /* fild dword ptr [edx + eax] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0x8ab134u))); /* fsub dword ptr [0x1000b134] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0x8ab130u))); /* fmul dword ptr [0x1000b130] */
    PUSH32(c, 0x008a1652u); f_008a3f14(c); /* call 0x8a3f14 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne cl */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
L_008a1669:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1523(CPU *c) { /* PTR_008a1523 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x1194u); /* cmp ecx, 0x1194 */
    goto L_008a156d; /* jmp 0x8a156d */
L_008a156d:;
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x7b0cu); /* cmp ecx, 0x7b0c */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1594:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 8], 1 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 4], 0x3f800000 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15c9:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a152f(CPU *c) { /* PTR_008a152f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->ecx, (uint32_t)0x1194u); /* cmp ecx, 0x1194 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x2328u); /* cmp ecx, 0x2328 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x34bcu); /* cmp ecx, 0x34bc */
    goto L_008a1575; /* jmp 0x8a1575 */
L_008a1575:;
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1594:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 8], 1 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 4], 0x3f800000 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15c9:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1547(CPU *c) { /* PTR_008a1547 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->ecx, (uint32_t)0x34bcu); /* cmp ecx, 0x34bc */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x4650u); /* cmp ecx, 0x4650 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x57e4u); /* cmp ecx, 0x57e4 */
    goto L_008a1575; /* jmp 0x8a1575 */
L_008a1575:;
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1594:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 8], 1 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 4], 0x3f800000 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15c9:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a155f(CPU *c) { /* PTR_008a155f */
    PREEMPT_POLL(c);
    (void)sub32(c, c->ecx, (uint32_t)0x57e4u); /* cmp ecx, 0x57e4 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x6978u); /* cmp ecx, 0x6978 */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    (void)sub32(c, c->ecx, (uint32_t)0x7b0cu); /* cmp ecx, 0x7b0c */
    if (c->zf) goto L_008a15a1; /* je 0x8a15a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 4], ebx */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_008a1594; /* je 0x8a1594 */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1594:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi + 8], 1 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 4], 0x3f800000 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_008a15c9; /* je 0x8a15c9 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esi], 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a15c9:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1680(CPU *c) { /* FUN_10001680 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x8ab114u)); /* mov dword ptr [ecx], 0x1000b114 */
    c->esp += 4; return; /* ret  */
}

void f_008a1690(CPU *c) { /* PTR_008a1690 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    W8((uint32_t)(c->ecx + 0x4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx + 4], al */
    c->esp += 8; return; /* ret 4 */
}

void f_008a16a0(CPU *c) { /* PTR_008a16a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a16b0(CPU *c) { /* PTR_008a16b0 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_008a16c0(CPU *c) { /* PTR_008a16c0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab114u)); /* mov dword ptr [esi], 0x1000b114 */
    if (c->zf) goto L_008a16da; /* je 0x8a16da */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a16d7u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a16da:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a16e0(CPU *c) { /* PTR_008a16e0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff3cu))); /* mov eax, dword ptr [0x1000ff3c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a16ee; /* jne 0x8a16ee */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
L_008a16ee:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff40u))); /* mov eax, dword ptr [0x1000ff40] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(0x8aff40u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff40], eax */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a1710(CPU *c) { /* FUN_10001710 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aa9c8u; PUSH32(c, v_); } /* push 0x1000a9c8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xc], esi */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 4], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab138u)); /* mov dword ptr [esi], 0x1000b138 */
    W32((uint32_t)(0x8aff3cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ff3c], esi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebx], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x28u)); /* lea edx, [esp + 0x28] */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [edi], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x28], 0 */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xcu)); PUSH32(c, 0x008a176fu); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a17c0; /* jl 0x8a17c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x8ab45cu; PUSH32(c, v_); } /* push 0x1000b45c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x2cu)); PUSH32(c, 0x008a1780u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a17c0; /* jl 0x8a17c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebp, dword ptr [eax] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x008a179au); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov eax, dword ptr [esp + 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x34u)); PUSH32(c, 0x008a17a3u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if ((c->sf != c->of)) goto L_008a17c0; /* jl 0x8a17c0 */
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea edx, [esp + 0x34] */
    { uint32_t v_ = 0xcu; PUSH32(c, v_); } /* push 0xc */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi))); /* mov ecx, dword ptr [edi] */
    { uint32_t v_ = 0x8a16e0u; PUSH32(c, v_); } /* push 0x100016e0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x10u)); PUSH32(c, 0x008a17bcu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a17c3; /* jge 0x8a17c3 */
L_008a17c0:;
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebx], 0 */
L_008a17c3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 28; return; /* ret 0x18 */
}

void f_008a17e0(CPU *c) { /* FUN_100017e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x008a17e8u); f_008a1800(c); /* call 0x8a1800 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_008a17f8; /* je 0x8a17f8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a17f5u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a17f8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a1800(CPU *c) { /* FUN_10001800 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aa9e8u; PUSH32(c, v_); } /* push 0x1000a9e8 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab138u)); /* mov dword ptr [esi], 0x1000b138 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a1841; /* je 0x8a1841 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x20u)); PUSH32(c, 0x008a1838u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x008a1841u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_008a1841:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab114u)); /* mov dword ptr [esi], 0x1000b114 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008a1860(CPU *c) { /* PTR_008a1860 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8ad0f8u); /* mov eax, 0x1000d0f8 */
    c->esp += 4; return; /* ret  */
}

void f_008a1870(CPU *c) { /* PTR_008a1870 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x100u); /* mov eax, 0x100 */
    c->esp += 4; return; /* ret  */
}

void f_008a1880(CPU *c) { /* PTR_008a1880 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8ad0f4u); /* mov eax, 0x1000d0f4 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a1890(CPU *c) { /* FUN_10001890 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea edi, [esi + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x24u)); PUSH32(c, 0x008a18a6u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x24] */
    (void)sub32(c, c->eax, (uint32_t)0x8007001eu); /* cmp eax, 0x8007001e */
    if (!c->zf) goto L_008a18c5; /* jne 0x8a18c5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x008a18b6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x008a18c5u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
L_008a18c5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a18d0(CPU *c) { /* PTR_008a18d0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x4u))); /* mov dl, byte ptr [ecx + 4] */
    (void)sub8(c, ((uint8_t)c->edx), ((uint8_t)c->ebx)); /* cmp dl, bl */
    if (!c->zf) goto L_008a18ec; /* jne 0x8a18ec */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a18ec:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    (void)sub32(c, c->edx, (uint32_t)0x100u); /* cmp edx, 0x100 */
    if (c->cf) goto L_008a1904; /* jb 0x8a1904 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1904:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx + 0x10u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx + 0x10], 0x80 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    if (c->zf) goto L_008a193e; /* je 0x8a193e */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 8], 1 */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 4], 0x3f800000 */
    if (c->zf) goto L_008a1932; /* je 0x8a1932 */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if (c->zf) goto L_008a1932; /* je 0x8a1932 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax], 1 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1932:;
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [eax], 3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a193e:;
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    if (c->zf) goto L_008a1958; /* je 0x8a1958 */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (c->zf) goto L_008a1958; /* je 0x8a1958 */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1958:;
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [eax], 2 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1970(CPU *c) { /* PTR_008a1970 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff44u))); /* mov ecx, dword ptr [0x1000ff44] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_008a197f; /* jne 0x8a197f */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
L_008a197f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0x20u)); /* lea esi, [eax + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a1991u); f_008a19b0(c); /* call 0x8a19b0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8ad104u; PUSH32(c, v_); } /* push 0x1000d104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a19a2u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 12; return; /* ret 8 */
}

void f_008a19b0(CPU *c) { /* FUN_100019b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x90u))); /* mov eax, dword ptr [ecx + 0x90] */
    (void)sub32(c, c->eax, (uint32_t)0x10u); /* cmp eax, 0x10 */
    if ((c->sf == c->of)) goto L_008a19de; /* jge 0x8a19de */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    W32((uint32_t)(c->ecx + c->eax * 8 + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*8 + 0x10], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x90u))); /* mov eax, dword ptr [ecx + 0x90] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + c->eax * 8 + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + eax*8 + 0x14], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x90u))); /* mov eax, dword ptr [ecx + 0x90] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ecx + 0x90u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0x90], eax */
L_008a19de:;
    c->esp += 12; return; /* ret 8 */
}

void f_008a19f0(CPU *c) { /* FUN_100019f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aaa08u; PUSH32(c, v_); } /* push 0x1000aa08 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0x10], esi */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esi + 4], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov eax, dword ptr [esp + 0x48] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x5cu))); /* mov ebp, dword ptr [esp + 0x5c] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab154u)); /* mov dword ptr [esi], 0x1000b154 */
    W32((uint32_t)(0x8aff44u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ff44], esi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W8((uint32_t)(c->ebp), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xcu)); /* lea edi, [esi + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x50u)); /* lea edx, [esp + 0x50] */
    W32((uint32_t)(c->esi + 0x90u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x90], ebx */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x50], ebx */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xcu)); PUSH32(c, 0x008a1a52u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a1a5e; /* jge 0x8a1a5e */
    W8((uint32_t)(c->ebp), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp], bl */
    goto L_008a1b17; /* jmp 0x8a1b17 */
L_008a1a5e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x8ab664u; PUSH32(c, v_); } /* push 0x1000b664 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x2cu)); PUSH32(c, 0x008a1a6bu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x2c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a1a77; /* jge 0x8a1a77 */
    W8((uint32_t)(c->ebp), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp], bl */
    goto L_008a1b17; /* jmp 0x8a1b17 */
L_008a1a77:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    W32((uint32_t)(c->esp + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x4c], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x008a1a8cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov eax, dword ptr [esp + 0x50] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x34u)); PUSH32(c, 0x008a1a95u); call_indirect(c, t_); } /* call dword ptr [ebx + 0x34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a1a9f; /* jge 0x8a1a9f */
    W8((uint32_t)(c->ebp), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [ebp], 0 */
    goto L_008a1b17; /* jmp 0x8a1b17 */
L_008a1a9f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x5cu)); /* lea edx, [esp + 0x5c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x8a1970u; PUSH32(c, v_); } /* push 0x10001970 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x10u)); PUSH32(c, 0x008a1ab4u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a1abd; /* jge 0x8a1abd */
    W8((uint32_t)(c->ebp), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp], bl */
    goto L_008a1b17; /* jmp 0x8a1b17 */
L_008a1abd:;
    c->edi = (uint32_t)(R32((uint32_t)(c->edi))); /* mov edi, dword ptr [edi] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea ecx, [esp + 0x24] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x14u)); /* mov dword ptr [esp + 0x24], 0x14 */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [esp + 0x28], 0x10 */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x30], ebx */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x2c], ebx */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x34], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x008a1aecu); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_008a1af5; /* jge 0x8a1af5 */
    W8((uint32_t)(c->ebp), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp], bl */
    goto L_008a1b17; /* jmp 0x8a1b17 */
L_008a1af5:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, 0x008a1b05u); call_indirect(c, t_); } /* call dword ptr [eax + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab0e8u)); PUSH32(c, 0x008a1b0cu); call_indirect(c, t_); } /* call dword ptr [0x1000b0e8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea ecx, [esp + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x8ab0ecu)); PUSH32(c, 0x008a1b17u); call_indirect(c, t_); } /* call dword ptr [0x1000b0ec] */
L_008a1b17:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x34u)); /* add esp, 0x34 */
    c->esp += 28; return; /* ret 0x18 */
}

void f_008a1b30(CPU *c) { /* FUN_10001b30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x008a1b38u); f_008a1b50(c); /* call 0x8a1b50 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_008a1b48; /* je 0x8a1b48 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a1b45u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a1b48:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a1b50(CPU *c) { /* FUN_10001b50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aaa28u; PUSH32(c, v_); } /* push 0x1000aa28 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab154u)); /* mov dword ptr [esi], 0x1000b154 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a1b91; /* je 0x8a1b91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x20u)); PUSH32(c, 0x008a1b88u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x008a1b91u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
L_008a1b91:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab114u)); /* mov dword ptr [esi], 0x1000b114 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008a1bb0(CPU *c) { /* PTR_008a1bb0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8ad11cu); /* mov eax, 0x1000d11c */
    c->esp += 4; return; /* ret  */
}

void f_008a1bc0(CPU *c) { /* PTR_008a1bc0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x90u))); /* mov eax, dword ptr [ecx + 0x90] */
    c->esp += 4; return; /* ret  */
}

void f_008a1bd0(CPU *c) { /* PTR_008a1bd0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    if ((c->sf != c->of)) goto L_008a1bea; /* jl 0x8a1bea */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x90u))); /* cmp eax, dword ptr [ecx + 0x90] */
    if ((c->sf == c->of)) goto L_008a1bea; /* jge 0x8a1bea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8 + 0x14u))); /* mov eax, dword ptr [ecx + eax*8 + 0x14] */
    c->esp += 12; return; /* ret 8 */
L_008a1bea:;
    c->eax = (uint32_t)((uint32_t)0x8ad124u); /* mov eax, 0x1000d124 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a1c00(CPU *c) { /* PTR_008a1c00 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    W8((uint32_t)(c->ecx + 0x4u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx + 4], al */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    if (c->zf) goto L_008a1c3f; /* je 0x8a1c3f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1cu)); PUSH32(c, 0x008a1c17u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp)); /* lea ecx, [esp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x008a1c27u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab0e8u)); PUSH32(c, 0x008a1c2eu); call_indirect(c, t_); } /* call dword ptr [0x1000b0e8] */
    c->eax = (uint32_t)((uint32_t)(c->esp)); /* lea eax, [esp] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab0ecu)); PUSH32(c, 0x008a1c39u); call_indirect(c, t_); } /* call dword ptr [0x1000b0ec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 8; return; /* ret 4 */
L_008a1c3f:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x20u)); PUSH32(c, 0x008a1c44u); call_indirect(c, t_); } /* call dword ptr [edx + 0x20] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x8ab0ecu)); PUSH32(c, 0x008a1c4cu); call_indirect(c, t_); } /* call dword ptr [0x1000b0ec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 8; return; /* ret 4 */
}

void f_008a1c60(CPU *c) { /* FUN_10001c60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x94u)); /* lea edi, [esi + 0x94] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x24u)); PUSH32(c, 0x008a1c76u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x24] */
    (void)sub32(c, c->eax, (uint32_t)0x8007001eu); /* cmp eax, 0x8007001e */
    if (!c->zf) goto L_008a1c92; /* jne 0x8a1c92 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x008a1c86u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x24u)); PUSH32(c, 0x008a1c92u); call_indirect(c, t_); } /* call dword ptr [eax + 0x24] */
L_008a1c92:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a1ca0(CPU *c) { /* PTR_008a1ca0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 8], ebx */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebx)); /* mov dword ptr [edx], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x4u))); /* mov al, byte ptr [ecx + 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a1d86; /* je 0x8a1d86 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    if ((c->sf != c->of)) goto L_008a1d86; /* jl 0x8a1d86 */
    (void)sub32(c, c->eax, (uint32_t)0x10u); /* cmp eax, 0x10 */
    if ((c->sf == c->of)) goto L_008a1d86; /* jge 0x8a1d86 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 8 + 0x10u))); /* mov esi, dword ptr [ecx + eax*8 + 0x10] */
    (void)sub32(c, c->esi, (uint32_t)0xfu); /* cmp esi, 0xf */
    if ((!c->cf && !c->zf)) goto L_008a1d7f; /* ja 0x8a1d7f */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x8a1dacu))); /* mov al, byte ptr [esi + 0x10001dac] */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x8a1d8cu)); switch (t_) { case 0x008a1cefu: goto L_008a1cef; case 0x008a1cf7u: goto L_008a1cf7; case 0x008a1cffu: goto L_008a1cff; case 0x008a1d07u: goto L_008a1d07; case 0x008a1d3bu: goto L_008a1d3b; case 0x008a1d54u: goto L_008a1d54; case 0x008a1d6du: goto L_008a1d6d; case 0x008a1d7fu: goto L_008a1d7f; default: jump_indirect(c, t_, 0x008a1ce8u); return; } } /* jmp dword ptr [eax*4 + 0x10001d8c] */
L_008a1cef:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa0u))); /* mov al, byte ptr [ecx + 0xa0] */
    goto L_008a1d0d; /* jmp 0x8a1d0d */
L_008a1cf7:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa1u))); /* mov al, byte ptr [ecx + 0xa1] */
    goto L_008a1d0d; /* jmp 0x8a1d0d */
L_008a1cff:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa2u))); /* mov al, byte ptr [ecx + 0xa2] */
    goto L_008a1d0d; /* jmp 0x8a1d0d */
L_008a1d07:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa3u))); /* mov al, byte ptr [ecx + 0xa3] */
L_008a1d0d:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a1d2c; /* je 0x8a1d2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx], 1 */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx + 8], 1 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [edx + 4], 0x3f800000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d2c:;
    W32((uint32_t)(c->edx), (uint32_t)(c->ebx)); /* mov dword ptr [edx], ebx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 8], ebx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d3b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x94u))); /* mov eax, dword ptr [ecx + 0x94] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x94u))); /* fild dword ptr [ecx + 0x94] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    c->esp += 16; return; /* ret 0xc */
L_008a1d54:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x98u))); /* mov eax, dword ptr [ecx + 0x98] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x98u))); /* fild dword ptr [ecx + 0x98] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    c->esp += 16; return; /* ret 0xc */
L_008a1d6d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x9cu))); /* mov eax, dword ptr [ecx + 0x9c] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x9cu))); /* fild dword ptr [ecx + 0x9c] */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
L_008a1d7f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d86:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1cef(CPU *c) { /* PTR_008a1cef */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa0u))); /* mov al, byte ptr [ecx + 0xa0] */
    goto L_008a1d0d; /* jmp 0x8a1d0d */
L_008a1d0d:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a1d2c; /* je 0x8a1d2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx], 1 */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx + 8], 1 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [edx + 4], 0x3f800000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d2c:;
    W32((uint32_t)(c->edx), (uint32_t)(c->ebx)); /* mov dword ptr [edx], ebx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 8], ebx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1cf7(CPU *c) { /* PTR_008a1cf7 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa1u))); /* mov al, byte ptr [ecx + 0xa1] */
    goto L_008a1d0d; /* jmp 0x8a1d0d */
L_008a1d0d:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a1d2c; /* je 0x8a1d2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx], 1 */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx + 8], 1 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [edx + 4], 0x3f800000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d2c:;
    W32((uint32_t)(c->edx), (uint32_t)(c->ebx)); /* mov dword ptr [edx], ebx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 8], ebx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1cff(CPU *c) { /* PTR_008a1cff */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa2u))); /* mov al, byte ptr [ecx + 0xa2] */
    goto L_008a1d0d; /* jmp 0x8a1d0d */
L_008a1d0d:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a1d2c; /* je 0x8a1d2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx], 1 */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx + 8], 1 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [edx + 4], 0x3f800000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d2c:;
    W32((uint32_t)(c->edx), (uint32_t)(c->ebx)); /* mov dword ptr [edx], ebx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 8], ebx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1d07(CPU *c) { /* PTR_008a1d07 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0xa3u))); /* mov al, byte ptr [ecx + 0xa3] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a1d2c; /* je 0x8a1d2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx], 1 */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [edx + 8], 1 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [edx + 4], 0x3f800000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
L_008a1d2c:;
    W32((uint32_t)(c->edx), (uint32_t)(c->ebx)); /* mov dword ptr [edx], ebx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 8], ebx */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edx + 4], ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1d3b(CPU *c) { /* PTR_008a1d3b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x94u))); /* mov eax, dword ptr [ecx + 0x94] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x94u))); /* fild dword ptr [ecx + 0x94] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1d54(CPU *c) { /* PTR_008a1d54 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x98u))); /* mov eax, dword ptr [ecx + 0x98] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x98u))); /* fild dword ptr [ecx + 0x98] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1d6d(CPU *c) { /* PTR_008a1d6d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x9cu))); /* mov eax, dword ptr [ecx + 0x9c] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->ecx + 0x9cu))); /* fild dword ptr [ecx + 0x9c] */
    WF32((uint32_t)(c->edx + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edx + 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1d7f(CPU *c) { /* PTR_008a1d7f */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a1dc0(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0x8aff68u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff68], eax */
    W32((uint32_t)(0x8aff4cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff4c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0x8aff48u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000ff48], ecx */
    W32((uint32_t)(0x8aff50u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff50], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff6cu))); /* mov eax, dword ptr [0x1000ff6c] */
    c->esp += 4; return; /* ret  */
}

void f_008a1df0(CPU *c) { /* FUN_10001df0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x008a1e00u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_008a1e10(CPU *c) { /* FUN_10001e10 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x008a1e2au); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_008a1e30(CPU *c) { /* FUN_10001e30 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov ecx, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, 0x008a1e4fu); call_indirect(c, t_); } /* call dword ptr [eax + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_008a1e50(CPU *c) { /* PTR_008a1e50 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x008a1e55u); f_008a1e60(c); /* call 0x8a1e60 */
    { f_008a1f80(c); return; } /* jmp 0x8a1f80 */
}

void f_008a1e60(CPU *c) { /* PTR_008a1e60 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x8aff6cu; PUSH32(c, v_); } /* push 0x1000ff6c */
    c->ecx = (uint32_t)((uint32_t)0x8aff54u); /* mov ecx, 0x1000ff54 */
    PUSH32(c, 0x008a1e6fu); f_008a1e70(c); /* call 0x8a1e70 */
    c->esp += 4; return; /* ret  */
}

void f_008a1e70(CPU *c) { /* PTR_008a1e70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0xc], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 8], edx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x8ab170u)); /* mov dword ptr [eax], 0x1000b170 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [eax + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 0x10], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a1ea0(CPU *c) { /* PTR_008a1ea0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8ad13cu); /* mov eax, 0x1000d13c */
    c->esp += 4; return; /* ret  */
}

void f_008a1eb0(CPU *c) { /* FUN_10001eb0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aaa54u; PUSH32(c, v_); } /* push 0x1000aa54 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a1eff; /* jne 0x8a1eff */
    { uint32_t v_ = 0x7u; PUSH32(c, v_); } /* push 7 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    PUSH32(c, 0x008a1edeu); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 4], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    if (c->zf) goto L_008a1efa; /* je 0x8a1efa */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x008a1ef8u); f_008a1fa0(c); /* call 0x8a1fa0 */
    goto L_008a1efc; /* jmp 0x8a1efc */
L_008a1efa:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a1efc:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
L_008a1eff:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008a1f20(CPU *c) { /* PTR_008a1f20 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_008a1f30(CPU *c) { /* FUN_10001f30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    (void)sub32(c, c->ecx, c->edi); /* cmp ecx, edi */
    if (c->zf) goto L_008a1f46; /* je 0x8a1f46 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->eax)); PUSH32(c, 0x008a1f46u); call_indirect(c, t_); } /* call dword ptr [eax] */
L_008a1f46:;
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a1f50(CPU *c) { /* FUN_10001f50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x008a1f58u); f_008a1f70(c); /* call 0x8a1f70 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_008a1f68; /* je 0x8a1f68 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a1f65u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a1f68:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a1f70(CPU *c) { /* FUN_10001f70 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x8ab190u)); /* mov dword ptr [ecx], 0x1000b190 */
    c->esp += 4; return; /* ret  */
}

void f_008a1f80(CPU *c) { /* PTR_008a1f80 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x8a1f90u; PUSH32(c, v_); } /* push 0x10001f90 */
    PUSH32(c, 0x008a1f8au); f_008a3fb9(c); /* call 0x8a3fb9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a1f90(CPU *c) { /* PTR_008a1f90 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0x8aff54u); /* mov ecx, 0x1000ff54 */
    { f_008a1f70(c); return; } /* jmp 0x8a1f70 */
}

void f_008a1fa0(CPU *c) { /* FUN_10001fa0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aaa68u; PUSH32(c, v_); } /* push 0x1000aa68 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [esp + 0xc], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab1b0u)); /* mov dword ptr [esi], 0x1000b1b0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov eax, dword ptr [0x1000ff70] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x1c], edi */
    if (!c->zf) goto L_008a1fdc; /* jne 0x8a1fdc */
    W32((uint32_t)(0x8aff70u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ff70], esi */
L_008a1fdc:;
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x24], edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x18], edi */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x1c], edi */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x20], edi */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x10], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0x8ad17cu; PUSH32(c, v_); } /* push 0x1000d17c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a2004u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ebx = (uint32_t)((uint32_t)(c->esi + 0x4u)); /* lea ebx, [esi + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x8ab6bcu; PUSH32(c, v_); } /* push 0x1000b6bc */
    { uint32_t v_ = 0x800u; PUSH32(c, v_); } /* push 0x800 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x008a201eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a2024u); f_008a3ae0(c); /* call 0x8a3ae0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a203d; /* jl 0x8a203d */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ebx, dword ptr [ebx] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea ecx, [esp + 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    { uint32_t v_ = 0x8a20e0u; PUSH32(c, v_); } /* push 0x100020e0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x008a203du); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
L_008a203d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 4; return; /* ret  */
}

void f_008a2060(CPU *c) { /* FUN_10002060 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x008a2068u); f_008a2080(c); /* call 0x8a2080 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_008a2078; /* je 0x8a2078 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a2075u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a2078:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2080(CPU *c) { /* FUN_10002080 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aaa88u; PUSH32(c, v_); } /* push 0x1000aa88 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab1b0u)); /* mov dword ptr [esi], 0x1000b1b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a20b8; /* je 0x8a20b8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x8u)); PUSH32(c, 0x008a20b8u); call_indirect(c, t_); } /* call dword ptr [ecx + 8] */
L_008a20b8:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x008a20bfu); f_008a2360(c); /* call 0x8a2360 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab210u)); /* mov dword ptr [esi], 0x1000b210 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008a20e0(CPU *c) { /* FUN_100020e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8aaadcu; PUSH32(c, v_); } /* push 0x1000aadc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov eax, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_008a2116; /* jne 0x8a2116 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
L_008a2116:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov esi, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x28u)); /* lea edx, [esi + 0x28] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x8ad204u; PUSH32(c, v_); } /* push 0x1000d204 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a212eu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xffffffeeu)); /* add eax, -0x12 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if ((!c->cf && !c->zf)) goto L_008a22d9; /* ja 0x8a22d9 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x8a2304u)); switch (t_) { case 0x008a214cu: goto L_008a214c; case 0x008a21bcu: goto L_008a21bc; case 0x008a21c6u: goto L_008a21c6; case 0x008a2236u: goto L_008a2236; default: jump_indirect(c, t_, 0x008a2145u); return; } } /* jmp dword ptr [eax*4 + 0x10002304] */
L_008a214c:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = 0x8ad1f8u; PUSH32(c, v_); } /* push 0x1000d1f8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a215cu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    { uint32_t v_ = 0x39u; PUSH32(c, v_); } /* push 0x39 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    PUSH32(c, 0x008a216au); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if (c->zf) goto L_008a22a2; /* je 0x8a22a2 */
    c->edx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov edx, dword ptr [0x1000ff70] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    PUSH32(c, 0x008a21b5u); f_008a1280(c); /* call 0x8a1280 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_008a22a4; /* jmp 0x8a22a4 */
L_008a21bc:;
    { uint32_t v_ = 0x8ad1ecu; PUSH32(c, v_); } /* push 0x1000d1ec */
    goto L_008a22de; /* jmp 0x8a22de */
L_008a21c6:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = 0x8ad1c8u; PUSH32(c, v_); } /* push 0x1000d1c8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x008a21d6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    { uint32_t v_ = 0x46u; PUSH32(c, v_); } /* push 0x46 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0x110u; PUSH32(c, v_); } /* push 0x110 */
    PUSH32(c, 0x008a21e7u); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x14], 1 */
    if (c->zf) goto L_008a22a2; /* je 0x8a22a2 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov ecx, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    PUSH32(c, 0x008a2232u); f_008a1710(c); /* call 0x8a1710 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_008a22a4; /* jmp 0x8a22a4 */
L_008a2236:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = 0x8ad1a8u; PUSH32(c, v_); } /* push 0x1000d1a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a2246u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    { uint32_t v_ = 0x50u; PUSH32(c, v_); } /* push 0x50 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0xa4u; PUSH32(c, v_); } /* push 0xa4 */
    PUSH32(c, 0x008a2257u); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x14], 2 */
    if (c->zf) goto L_008a22a2; /* je 0x8a22a2 */
    c->edx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov edx, dword ptr [0x1000ff70] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    PUSH32(c, 0x008a229eu); f_008a19f0(c); /* call 0x8a19f0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_008a22a4; /* jmp 0x8a22a4 */
L_008a22a2:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a22a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x1cu))); /* mov al, byte ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008a22cb; /* je 0x8a22cb */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov ecx, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a22c0u); f_008a25b0(c); /* call 0x8a25b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x008a22c9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22cb:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a22ec; /* je 0x8a22ec */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x008a22d7u); call_indirect(c, t_); } /* call dword ptr [edx] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22d9:;
    { uint32_t v_ = 0x8ad190u; PUSH32(c, v_); } /* push 0x1000d190 */
L_008a22de:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a22e9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_008a22ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a214c(CPU *c) { /* PTR_008a214c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = 0x8ad1f8u; PUSH32(c, v_); } /* push 0x1000d1f8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a215cu); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    { uint32_t v_ = 0x39u; PUSH32(c, v_); } /* push 0x39 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0x28u; PUSH32(c, v_); } /* push 0x28 */
    PUSH32(c, 0x008a216au); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    if (c->zf) goto L_008a22a2; /* je 0x8a22a2 */
    c->edx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov edx, dword ptr [0x1000ff70] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    PUSH32(c, 0x008a21b5u); f_008a1280(c); /* call 0x8a1280 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_008a22a4; /* jmp 0x8a22a4 */
L_008a22a2:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a22a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x1cu))); /* mov al, byte ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008a22cb; /* je 0x8a22cb */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov ecx, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a22c0u); f_008a25b0(c); /* call 0x8a25b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x008a22c9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22cb:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a22ec; /* je 0x8a22ec */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x008a22d7u); call_indirect(c, t_); } /* call dword ptr [edx] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a21bc(CPU *c) { /* PTR_008a21bc */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x8ad1ecu; PUSH32(c, v_); } /* push 0x1000d1ec */
    goto L_008a22de; /* jmp 0x8a22de */
L_008a22de:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a22e9u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a21c6(CPU *c) { /* PTR_008a21c6 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = 0x8ad1c8u; PUSH32(c, v_); } /* push 0x1000d1c8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x30u)); PUSH32(c, 0x008a21d6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x30] */
    { uint32_t v_ = 0x46u; PUSH32(c, v_); } /* push 0x46 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0x110u; PUSH32(c, v_); } /* push 0x110 */
    PUSH32(c, 0x008a21e7u); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x14], 1 */
    if (c->zf) goto L_008a22a2; /* je 0x8a22a2 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov ecx, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    PUSH32(c, 0x008a2232u); f_008a1710(c); /* call 0x8a1710 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_008a22a4; /* jmp 0x8a22a4 */
L_008a22a2:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a22a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x1cu))); /* mov al, byte ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008a22cb; /* je 0x8a22cb */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov ecx, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a22c0u); f_008a25b0(c); /* call 0x8a25b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x008a22c9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22cb:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a22ec; /* je 0x8a22ec */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x008a22d7u); call_indirect(c, t_); } /* call dword ptr [edx] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2236(CPU *c) { /* PTR_008a2236 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff68u))); /* mov eax, dword ptr [0x1000ff68] */
    { uint32_t v_ = 0x8ad1a8u; PUSH32(c, v_); } /* push 0x1000d1a8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x30u)); PUSH32(c, 0x008a2246u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x30] */
    { uint32_t v_ = 0x50u; PUSH32(c, v_); } /* push 0x50 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    { uint32_t v_ = 0xa4u; PUSH32(c, v_); } /* push 0xa4 */
    PUSH32(c, 0x008a2257u); f_008a1e10(c); /* call 0x8a1e10 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esp + 0x14], 2 */
    if (c->zf) goto L_008a22a2; /* je 0x8a22a2 */
    c->edx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov edx, dword ptr [0x1000ff70] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ecx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x1cu)); /* lea edx, [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->edx), (uint32_t)(c->edi)); /* mov dword ptr [edx], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edi, dword ptr [esi + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 4], edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov edi, dword ptr [esi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov esi, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [edx + 8], edi */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [edx + 0xc], esi */
    PUSH32(c, 0x008a229eu); f_008a19f0(c); /* call 0x8a19f0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    goto L_008a22a4; /* jmp 0x8a22a4 */
L_008a22a2:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a22a4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x1cu))); /* mov al, byte ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_008a22cb; /* je 0x8a22cb */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8aff70u))); /* mov ecx, dword ptr [0x1000ff70] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a22c0u); f_008a25b0(c); /* call 0x8a25b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x008a22c9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22cb:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a22ec; /* je 0x8a22ec */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x008a22d7u); call_indirect(c, t_); } /* call dword ptr [edx] */
    goto L_008a22ec; /* jmp 0x8a22ec */
L_008a22ec:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2304(CPU *c) { /* PTR_008a2304 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & R8((uint32_t)(c->eax))))); /* and al, byte ptr ss:[eax] */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(adc8(c, ((uint8_t)(c->edx >> 8)), ((uint8_t)c->eax))) << 8); /* adc dh, al */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x214c1000u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->ebx >> 8))))); } /* adc byte ptr [ecx + 0x214c1000], bh */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    { f_008a2320(c); return; }
}

void f_008a2320(CPU *c) { /* FUN_10002320 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a234e; /* je 0x8a234e */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_008a234e; /* jbe 0x8a234e */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_008a2339:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov ecx, dword ptr [eax + esi*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x10u)); PUSH32(c, 0x008a2345u); call_indirect(c, t_); } /* call dword ptr [edx + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_008a2339; /* jb 0x8a2339 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_008a234e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2360(CPU *c) { /* FUN_10002360 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->ebp); /* cmp dword ptr [esi + 0x14], ebp */
    if (c->zf) goto L_008a23a3; /* je 0x8a23a3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_008a2397; /* jle 0x8a2397 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_008a2378:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->eax + 0x4u))); /* mov eax, dword ptr [edi + eax + 4] */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_008a238c; /* je 0x8a238c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a2389u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a238c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x10u)); /* add edi, 0x10 */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_008a2378; /* jl 0x8a2378 */
L_008a2397:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov ecx, dword ptr [esi + 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a23a0u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a23a3:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), c->ebp); /* cmp dword ptr [esi + 0x1c], ebp */
    if (c->zf) goto L_008a23dd; /* je 0x8a23dd */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_008a23d1; /* jle 0x8a23d1 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_008a23b3:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->edx))); /* mov eax, dword ptr [edi + edx] */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if (c->zf) goto L_008a23c6; /* je 0x8a23c6 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a23c3u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a23c6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x1cu)); /* add edi, 0x1c */
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((c->sf != c->of)) goto L_008a23b3; /* jl 0x8a23b3 */
L_008a23d1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a23dau); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a23dd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x1c], ebp */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x20], ebp */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x14], ebp */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x18], ebp */
    if (c->zf) goto L_008a241d; /* je 0x8a241d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebp); /* cmp eax, ebp */
    if ((c->zf || c->sf != c->of)) goto L_008a2411; /* jle 0x8a2411 */
L_008a23f9:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->edi * 4))); /* mov ecx, dword ptr [ecx + edi*4] */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (c->zf) goto L_008a2409; /* je 0x8a2409 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(c->edx)); PUSH32(c, 0x008a2409u); call_indirect(c, t_); } /* call dword ptr [edx] */
L_008a2409:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_008a23f9; /* jl 0x8a23f9 */
L_008a2411:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a241au); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a241d:;
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0xc], ebp */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x10], ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_008a2430(CPU *c) { /* PTR_008a2430 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    c->esp += 4; return; /* ret  */
}

void f_008a2440(CPU *c) { /* PTR_008a2440 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov edx, dword ptr [ecx + 0x18] */
    (void)sub32(c, c->eax, c->edx); /* cmp eax, edx */
    if ((c->sf != c->of)) goto L_008a2450; /* jl 0x8a2450 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
L_008a2450:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x14u))); /* mov edx, dword ptr [ecx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov esi, dword ptr [eax + edx] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx + 0x4u))); /* mov eax, dword ptr [eax + edx + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2470(CPU *c) { /* FUN_10002470 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (!c->zf) goto L_008a2488; /* jne 0x8a2488 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_008a2488:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_008a24b6; /* jle 0x8a24b6 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_008a2493:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->ebp))); /* mov ecx, dword ptr [eax + ebp] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a24a0u); f_008aa660(c); /* call 0x8aa660 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a254f; /* je 0x8a254f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x1cu)); /* add ebp, 0x1c */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_008a2493; /* jl 0x8a2493 */
L_008a24b6:;
    c->ebp = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ebp, dword ptr [esi + 0x20] */
    { uint32_t v_ = 0xb2u; PUSH32(c, v_); } /* push 0xb2 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x1u)); /* lea eax, [ebp + 1] */
    W32((uint32_t)(c->esi + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x20], eax */
    c->edx = (uint32_t)((uint32_t)(c->eax * 8)); /* lea edx, [eax*8] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->edx = (uint32_t)(shl32(c, c->edx, 2)); /* shl edx, 2 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a24dfu); f_008a1e30(c); /* call 0x8a1e30 */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1c], eax */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0xffffffffu))); /* or ecx, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); c->ecx--; if (c->zf) break; } /* repne scasb al, byte ptr es:[edi] */
    { uint32_t v_ = 0xb3u; PUSH32(c, v_); } /* push 0xb3 */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    c->ecx = (uint32_t)((uint32_t)~c->ecx); /* not ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a24fdu); f_008a1e10(c); /* call 0x8a1e10 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp * 8)); /* lea ecx, [ebp*8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->ebp)); /* sub ecx, ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 2)); /* shl ecx, 2 */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->edx))); /* mov edi, dword ptr [ecx + edx] */
L_008a251a:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_008a251a; /* jne 0x8a251a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->eax + c->ecx + 0x4u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [eax + ecx + 4], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->edx + c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx + 8], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    W32((uint32_t)(c->edx + c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx + 0xc], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov edx, dword ptr [esi + 0x1c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->edx + c->ecx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edx + ecx + 0x10], eax */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
L_008a254f:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2560(CPU *c) { /* PTR_008a2560 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x20u))); /* mov eax, dword ptr [ecx + 0x20] */
    c->esp += 4; return; /* ret  */
}

void f_008a2570(CPU *c) { /* PTR_008a2570 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_008a25a6; /* jl 0x8a25a6 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ecx + 0x20u))); /* cmp edx, dword ptr [ecx + 0x20] */
    if ((c->sf == c->of)) goto L_008a25a6; /* jge 0x8a25a6 */
    c->eax = (uint32_t)((uint32_t)(c->edx * 8)); /* lea eax, [edx*8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edx)); /* sub eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov edx, dword ptr [ecx + 0x1c] */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov esi, dword ptr [eax + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->edx), (uint32_t)(c->esi)); /* mov dword ptr [edx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov ecx, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->eax + 0x4u))); /* mov eax, dword ptr [ecx + eax + 4] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 12; return; /* ret 8 */
L_008a25a6:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
}

void f_008a25b0(CPU *c) { /* FUN_100025b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_008a25e7; /* je 0x8a25e7 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov edi, dword ptr [esi + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = 0xd2u; PUSH32(c, v_); } /* push 0xd2 */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
    { uint32_t v_ = 0x8ad148u; PUSH32(c, v_); } /* push 0x1000d148 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x10], eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 2)); /* shl eax, 2 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a25ddu); f_008a1e30(c); /* call 0x8a1e30 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    W32((uint32_t)(c->eax + c->edi * 4), (uint32_t)(c->ebx)); /* mov dword ptr [eax + edi*4], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_008a25e7:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_008a25f0(CPU *c) { /* PTR_008a25f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x10u))); /* mov eax, dword ptr [ecx + 0x10] */
    c->esp += 4; return; /* ret  */
}

void f_008a2600(CPU *c) { /* PTR_008a2600 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a2623; /* jl 0x8a2623 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x10u))); /* cmp eax, dword ptr [ecx + 0x10] */
    if ((c->sf == c->of)) goto L_008a2623; /* jge 0x8a2623 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + c->eax * 4))); /* mov ecx, dword ptr [ecx + eax*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4u)); PUSH32(c, 0x008a2618u); call_indirect(c, t_); } /* call dword ptr [edx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 12; return; /* ret 8 */
L_008a2623:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2630(CPU *c) { /* PTR_008a2630 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a2651; /* jl 0x8a2651 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x20u))); /* cmp eax, dword ptr [ecx + 0x20] */
    if ((c->sf == c->of)) goto L_008a2651; /* jge 0x8a2651 */
    c->edx = (uint32_t)((uint32_t)(c->eax * 8)); /* lea edx, [eax*8] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->eax + c->edx * 4 + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + edx*4 + 4], ecx */
L_008a2651:;
    c->esp += 12; return; /* ret 8 */
}

void f_008a2660(CPU *c) { /* PTR_008a2660 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebp, dword ptr [esp + 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    if (c->zf) goto L_008a26a1; /* je 0x8a26a1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->zf || c->sf != c->of)) goto L_008a26a1; /* jle 0x8a26a1 */
L_008a2682:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->ebx))); /* mov ecx, dword ptr [eax + ebx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x008a268fu); f_008aa660(c); /* call 0x8aa660 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a26aa; /* je 0x8a26aa */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x1cu)); /* add ebx, 0x1c */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_008a2682; /* jl 0x8a2682 */
L_008a26a1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a26aa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x008a26b7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a26c0(CPU *c) { /* PTR_008a26c0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    if ((c->sf != c->of)) goto L_008a2841; /* jl 0x8a2841 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0x20u))); /* cmp eax, dword ptr [edi + 0x20] */
    if ((c->sf == c->of)) goto L_008a2841; /* jge 0x8a2841 */
    c->ebx = (uint32_t)((uint32_t)(c->eax * 8)); /* lea ebx, [eax*8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov edx, dword ptr [edi + 0x10] */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->eax)); /* sub ebx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov eax, dword ptr [edi + 0x1c] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 2)); /* shl ebx, 2 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ebx)); /* add eax, ebx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + 0x6u))); /* mov cx, word ptr [eax + 6] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->cf) goto L_008a2841; /* jae 0x8a2841 */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov edx, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov ebp, dword ptr [eax + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edx + c->ecx * 4))); /* mov ecx, dword ptr [edx + ecx*4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x008a2727u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->ebp = (uint32_t)((uint32_t)0x3f800000u); /* mov ebp, 0x3f800000 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0x8u)) & (uint8_t)0x2u)); /* test byte ptr [ecx + 8], 2 */
    if (c->zf) goto L_008a2787; /* je 0x8a2787 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->edx); /* cmp dword ptr [esi + 8], edx */
    if ((c->sf == c->of)) goto L_008a2767; /* jge 0x8a2767 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2759; /* je 0x8a2759 */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->zf) goto L_008a2759; /* je 0x8a2759 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2789; /* jmp 0x8a2789 */
L_008a2759:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2789; /* jmp 0x8a2789 */
L_008a2767:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_008a2779; /* je 0x8a2779 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2779; /* je 0x8a2779 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
    goto L_008a2789; /* jmp 0x8a2789 */
L_008a2779:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
    goto L_008a2789; /* jmp 0x8a2789 */
L_008a2787:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_008a2789:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + c->ecx + 0x8u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + ecx + 8], 4 */
    if (c->zf) goto L_008a27c7; /* je 0x8a27c7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x4u))); /* fld dword ptr [esi + 4] */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    if ((!c->cf && !c->zf)) goto L_008a27c7; /* ja 0x8a27c7 */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a284cu)); switch (t_) { case 0x008a27b1u: goto L_008a27b1; case 0x008a27b5u: goto L_008a27b5; case 0x008a27b9u: goto L_008a27b9; case 0x008a27c1u: goto L_008a27c1; default: jump_indirect(c, t_, 0x008a27aau); return; } } /* jmp dword ptr [ecx*4 + 0x1000284c] */
L_008a27b1:;
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a27c7; /* jmp 0x8a27c7 */
L_008a27b5:;
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_008a27c7; /* jmp 0x8a27c7 */
L_008a27b9:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    goto L_008a27c7; /* jmp 0x8a27c7 */
L_008a27c1:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
L_008a27c7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0x8u)) & ((uint8_t)c->eax))); /* test byte ptr [ecx + 8], al */
    if (c->zf) goto L_008a2812; /* je 0x8a2812 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->edx); /* cmp dword ptr [esi + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    if ((c->zf || c->sf != c->of)) goto L_008a27fa; /* jle 0x8a27fa */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27ec:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27fa:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a280c; /* jmp 0x8a280c */
L_008a2806:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
L_008a280c:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
L_008a2812:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov edx, dword ptr [edi + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + c->edx + 0x10u))); /* mov ebp, dword ptr [ebx + edx + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->edx)); /* lea ecx, [ebx + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov edx, dword ptr [edi + 0x24] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if (c->zf) goto L_008a2836; /* je 0x8a2836 */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebx + ecx + 0xc], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2836:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2841:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a27b1(CPU *c) { /* PTR_008a27b1 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a27c7; /* jmp 0x8a27c7 */
L_008a27c7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0x8u)) & ((uint8_t)c->eax))); /* test byte ptr [ecx + 8], al */
    if (c->zf) goto L_008a2812; /* je 0x8a2812 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->edx); /* cmp dword ptr [esi + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    if ((c->zf || c->sf != c->of)) goto L_008a27fa; /* jle 0x8a27fa */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27ec:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27fa:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a280c; /* jmp 0x8a280c */
L_008a2806:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
L_008a280c:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
L_008a2812:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov edx, dword ptr [edi + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + c->edx + 0x10u))); /* mov ebp, dword ptr [ebx + edx + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->edx)); /* lea ecx, [ebx + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov edx, dword ptr [edi + 0x24] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if (c->zf) goto L_008a2836; /* je 0x8a2836 */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebx + ecx + 0xc], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2836:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a27b5(CPU *c) { /* PTR_008a27b5 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_008a27c7; /* jmp 0x8a27c7 */
L_008a27c7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0x8u)) & ((uint8_t)c->eax))); /* test byte ptr [ecx + 8], al */
    if (c->zf) goto L_008a2812; /* je 0x8a2812 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->edx); /* cmp dword ptr [esi + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    if ((c->zf || c->sf != c->of)) goto L_008a27fa; /* jle 0x8a27fa */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27ec:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27fa:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a280c; /* jmp 0x8a280c */
L_008a2806:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
L_008a280c:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
L_008a2812:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov edx, dword ptr [edi + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + c->edx + 0x10u))); /* mov ebp, dword ptr [ebx + edx + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->edx)); /* lea ecx, [ebx + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov edx, dword ptr [edi + 0x24] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if (c->zf) goto L_008a2836; /* je 0x8a2836 */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebx + ecx + 0xc], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2836:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a27b9(CPU *c) { /* PTR_008a27b9 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
    goto L_008a27c7; /* jmp 0x8a27c7 */
L_008a27c7:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0x8u)) & ((uint8_t)c->eax))); /* test byte ptr [ecx + 8], al */
    if (c->zf) goto L_008a2812; /* je 0x8a2812 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->edx); /* cmp dword ptr [esi + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    if ((c->zf || c->sf != c->of)) goto L_008a27fa; /* jle 0x8a27fa */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27ec:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27fa:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a280c; /* jmp 0x8a280c */
L_008a2806:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
L_008a280c:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
L_008a2812:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov edx, dword ptr [edi + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + c->edx + 0x10u))); /* mov ebp, dword ptr [ebx + edx + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->edx)); /* lea ecx, [ebx + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov edx, dword ptr [edi + 0x24] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if (c->zf) goto L_008a2836; /* je 0x8a2836 */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebx + ecx + 0xc], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2836:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a27c1(CPU *c) { /* PTR_008a27c1 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + 0x8u)) & ((uint8_t)c->eax))); /* test byte ptr [ecx + 8], al */
    if (c->zf) goto L_008a2812; /* je 0x8a2812 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x8u)), c->edx); /* cmp dword ptr [esi + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    if ((c->zf || c->sf != c->of)) goto L_008a27fa; /* jle 0x8a27fa */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    (void)sub32(c, c->ecx, (uint32_t)0x2u); /* cmp ecx, 2 */
    if (c->zf) goto L_008a27ec; /* je 0x8a27ec */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27ec:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x3u)); /* mov dword ptr [esi], 3 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 8], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    goto L_008a2812; /* jmp 0x8a2812 */
L_008a27fa:;
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_008a2806; /* je 0x8a2806 */
    W32((uint32_t)(c->esi), (uint32_t)(c->edx)); /* mov dword ptr [esi], edx */
    goto L_008a280c; /* jmp 0x8a280c */
L_008a2806:;
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [esi], 2 */
L_008a280c:;
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 8], edx */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [esi + 4], edx */
L_008a2812:;
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov edx, dword ptr [edi + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + c->edx + 0x10u))); /* mov ebp, dword ptr [ebx + edx + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->edx)); /* lea ecx, [ebx + edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x24u))); /* mov edx, dword ptr [edi + 0x24] */
    (void)sub32(c, c->ebp, c->edx); /* cmp ebp, edx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if (c->zf) goto L_008a2836; /* je 0x8a2836 */
    W32((uint32_t)(c->ecx + 0x10u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 0x10], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x1cu))); /* mov ecx, dword ptr [edi + 0x1c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + c->ecx + 0xcu), (uint32_t)(c->edx)); /* mov dword ptr [ebx + ecx + 0xc], edx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2836:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov ecx, dword ptr [ecx + 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2860(CPU *c) { /* FUN_10002860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_008a2880; /* jbe 0x8a2880 */
L_008a286d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->edi * 4))); /* mov ecx, dword ptr [eax + edi*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x008a2878u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_008a286d; /* jb 0x8a286d */
L_008a2880:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->esi + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x24], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2890(CPU *c) { /* PTR_008a2890 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a28b6; /* jl 0x8a28b6 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x20u))); /* cmp eax, dword ptr [ecx + 0x20] */
    if ((c->sf == c->of)) goto L_008a28b6; /* jge 0x8a28b6 */
    c->edx = (uint32_t)((uint32_t)(c->eax * 8)); /* lea edx, [eax*8] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(c->eax + c->edx * 4 + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + edx*4 + 8], ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 12; return; /* ret 8 */
L_008a28b6:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
}

void f_008a28c0(CPU *c) { /* PTR_008a28c0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebp, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if (c->zf) goto L_008a28f8; /* je 0x8a28f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->cf || c->zf)) goto L_008a28f8; /* jbe 0x8a28f8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_008a28d9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + c->ebx))); /* mov ecx, dword ptr [eax + ebx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x008a28e6u); f_008aa660(c); /* call 0x8aa660 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a2901; /* je 0x8a2901 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x1cu)); /* add ebx, 0x1c */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_008a28d9; /* jb 0x8a28d9 */
L_008a28f8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
L_008a2901:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x008a290eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2920(CPU *c) { /* PTR_008a2920 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_008a2948; /* jl 0x8a2948 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x20u))); /* cmp eax, dword ptr [ecx + 0x20] */
    if ((c->sf == c->of)) goto L_008a2948; /* jge 0x8a2948 */
    c->edx = (uint32_t)((uint32_t)(c->eax * 8)); /* lea edx, [eax*8] */
    c->edx = (uint32_t)(sub32(c, c->edx, c->eax)); /* sub edx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + c->edx * 4 + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + edx*4 + 0xc], ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 12; return; /* ret 8 */
L_008a2948:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2950(CPU *c) { /* FUN_10002950 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0x8ab210u)); /* mov dword ptr [ecx], 0x1000b210 */
    c->esp += 4; return; /* ret  */
}

void f_008a2960(CPU *c) { /* PTR_008a2960 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2970(CPU *c) { /* PTR_008a2970 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 12; return; /* ret 8 */
}

void f_008a2980(CPU *c) { /* PTR_008a2980 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2990(CPU *c) { /* PTR_008a2990 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 12; return; /* ret 8 */
}

void f_008a29a0(CPU *c) { /* PTR_008a29a0 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_008a29b0(CPU *c) { /* PTR_008a29b0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 12; return; /* ret 8 */
}

void f_008a29d0(CPU *c) { /* PTR_008a29d0 */
    PREEMPT_POLL(c);
    c->esp += 12; return; /* ret 8 */
}

void f_008a29e0(CPU *c) { /* PTR_008a29e0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab210u)); /* mov dword ptr [esi], 0x1000b210 */
    if (c->zf) goto L_008a29fa; /* je 0x8a29fa */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a29f7u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a29fa:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2a00(CPU *c) { /* PTR_008a2a00 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_008a2a10(CPU *c) { /* PTR_008a2a10 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_008a2a20(CPU *c) { /* PTR_008a2a20 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_008a2a28(CPU *c) { /* PTR_008a2a28 */
    PREEMPT_POLL(c);
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_008a2a30(CPU *c) { /* PTR_008a2a30 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_008a2a38(CPU *c) { /* PTR_008a2a38 */
    PREEMPT_POLL(c);
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_008a2a40(CPU *c) { /* PTR_008a2a40 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_008a2a48(CPU *c) { /* PTR_008a2a48 */
    PREEMPT_POLL(c);
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    ; /* nop  */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab190u)); /* mov dword ptr [esi], 0x1000b190 */
    if (c->zf) goto L_008a2a6a; /* je 0x8a2a6a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a2a67u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a2a6a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2a50(CPU *c) { /* PTR_008a2a50 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x8ab190u)); /* mov dword ptr [esi], 0x1000b190 */
    if (c->zf) goto L_008a2a6a; /* je 0x8a2a6a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a2a67u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_008a2a6a:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2a58(CPU *c) { /* PTR_008a2a58 */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    guest_trap(c, 0x008a2a5au, "unsupported: push es"); /* push es */
    ; /* nop  */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov cl, 0 */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ecx + 0x56u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->edx >> 8))))); } /* adc byte ptr [ecx + ecx + 0x56], dh */
    PUSH32(c, 0x008a2a67u); f_008a1df0(c); /* call 0x8a1df0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a2a68(CPU *c) { /* PTR_008a2a68 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x008a2a68u, "unsupported: les eax, ptr [ebx + ecx*4]"); /* les eax, ptr [ebx + ecx*4] */
    { jump_indirect(c, 0x008a2a6bu, 0x008a2a68u); return; }
}

void f_008a2a70(CPU *c) { /* PTR_008a2a70 */
    PREEMPT_POLL(c);
    if ((c->sf != c->of)) { f_008a2a28(c); return; } /* jl 0x8a2a28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2a78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x0u))); /* or al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) { f_008a2a38(c); return; } /* jl 0x8a2a38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2a88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1u))); /* or al, 1 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) { f_008a2a48(c); return; } /* jl 0x8a2a48 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax)))); /* add al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2a98:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) { f_008a2a58(c); return; } /* jl 0x8a2a58 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->eax)))); /* add eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2aa8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3u))); /* or al, 3 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) { f_008a2a68(c); return; } /* jl 0x8a2a68 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x0u)); /* add al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2ab8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2a78; /* jl 0x8a2a78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xc000000u)); /* add eax, 0xc000000 */
    goto L_008a2ac9;
L_008a2ac8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5u))); /* or al, 5 */
    goto L_008a2aca;
L_008a2ac9:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8000u)); /* add eax, 0x8000 */
    goto L_008a2ace;
L_008a2aca:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2ad0;
L_008a2ace:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2ad0:;
    if ((c->sf != c->of)) goto L_008a2a88; /* jl 0x8a2a88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2ad4u, "unsupported: push es"); /* push es */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + eax], cl */
    goto L_008a2ada;
L_008a2ad8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6u))); /* or al, 6 */
L_008a2ada:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2a98; /* jl 0x8a2a98 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2ae4u, "unsupported: pop es"); /* pop es */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + eax], cl */
    goto L_008a2aea;
L_008a2ae8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7u))); /* or al, 7 */
L_008a2aea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2aa8; /* jl 0x8a2aa8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | ((uint8_t)c->eax))))); } /* or byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2af8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ab8; /* jl 0x8a2ab8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | c->eax)))); } /* or dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9u))); /* or al, 9 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ac8; /* jl 0x8a2ac8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | R8((uint32_t)(c->eax))))); /* or al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xau))); /* or al, 0xa */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ad8; /* jl 0x8a2ad8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->eax))))); /* or eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b28:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xbu))); /* or al, 0xb */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ae8; /* jl 0x8a2ae8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x0u))); /* or al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b38:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xcu))); /* or al, 0xc */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2af8; /* jl 0x8a2af8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xc000000u))); /* or eax, 0xc000000 */
    goto L_008a2b49;
L_008a2b48:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xdu))); /* or al, 0xd */
    goto L_008a2b4a;
L_008a2b49:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x8000u))); /* or eax, 0x8000 */
    goto L_008a2b4e;
L_008a2b4a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2b50;
L_008a2b4e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b50:;
    if ((c->sf != c->of)) goto L_008a2b08; /* jl 0x8a2b08 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2b54u, "unsupported: push cs"); /* push cs */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ecx], cl */
    goto L_008a2b5a;
L_008a2b58:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xeu))); /* or al, 0xe */
L_008a2b5a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b18; /* jl 0x8a2b18 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2b64u, "unsupported: sldt word ptr [eax]"); /* sldt word ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->edi + c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ecx], cl */
    goto L_008a2b6a;
L_008a2b68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xfu))); /* or al, 0xf */
L_008a2b6a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b28; /* jl 0x8a2b28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->eax)))); } /* adc byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b38; /* jl 0x8a2b38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(adc32(c, R32(a_), c->eax))); } /* adc dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x11u))); /* or al, 0x11 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b48; /* jl 0x8a2b48 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(adc8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax)))); /* adc al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2b98:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x12u))); /* or al, 0x12 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b58; /* jl 0x8a2b58 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(adc32(c, c->eax, R32((uint32_t)(c->eax)))); /* adc eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2ba8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x13u))); /* or al, 0x13 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b68; /* jl 0x8a2b68 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(adc8(c, ((uint8_t)c->eax), (uint8_t)0x0u)); /* adc al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2bb8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x14u))); /* or al, 0x14 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b78; /* jl 0x8a2b78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(adc32(c, c->eax, (uint32_t)0xc000000u)); /* adc eax, 0xc000000 */
    goto L_008a2bc9;
L_008a2bc8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x15u))); /* or al, 0x15 */
    goto L_008a2bca;
L_008a2bc9:;
    c->eax = (uint32_t)(adc32(c, c->eax, (uint32_t)0x8000u)); /* adc eax, 0x8000 */
    goto L_008a2bce;
L_008a2bca:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2bd0;
L_008a2bce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2bd0:;
    if ((c->sf != c->of)) goto L_008a2b88; /* jl 0x8a2b88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2bd4u, "unsupported: push ss"); /* push ss */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->edx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + edx], cl */
    goto L_008a2bda;
L_008a2bd8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x16u))); /* or al, 0x16 */
L_008a2bda:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2b98; /* jl 0x8a2b98 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2be4u, "unsupported: pop ss"); /* pop ss */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->edx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + edx], cl */
    goto L_008a2bea;
L_008a2be8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x17u))); /* or al, 0x17 */
L_008a2bea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ba8; /* jl 0x8a2ba8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(sbb8(c, R8(a_), ((uint8_t)c->eax)))); } /* sbb byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2bf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x18u))); /* or al, 0x18 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2bb8; /* jl 0x8a2bb8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sbb32(c, R32(a_), c->eax))); } /* sbb dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x19u))); /* or al, 0x19 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2bc8; /* jl 0x8a2bc8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax)))); /* sbb al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1au))); /* or al, 0x1a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2bd8; /* jl 0x8a2bd8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(sbb32(c, c->eax, R32((uint32_t)(c->eax)))); /* sbb eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c28:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1bu))); /* or al, 0x1b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2be8; /* jl 0x8a2be8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sbb8(c, ((uint8_t)c->eax), (uint8_t)0x0u)); /* sbb al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c38:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1cu))); /* or al, 0x1c */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2bf8; /* jl 0x8a2bf8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0xc000000u)); /* sbb eax, 0xc000000 */
    goto L_008a2c49;
L_008a2c48:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1du))); /* or al, 0x1d */
    goto L_008a2c4a;
L_008a2c49:;
    c->eax = (uint32_t)(sbb32(c, c->eax, (uint32_t)0x8000u)); /* sbb eax, 0x8000 */
    goto L_008a2c4e;
L_008a2c4a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2c50;
L_008a2c4e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c50:;
    if ((c->sf != c->of)) goto L_008a2c08; /* jl 0x8a2c08 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2c54u, "unsupported: push ds"); /* push ds */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ebx], cl */
    goto L_008a2c5a;
L_008a2c58:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1eu))); /* or al, 0x1e */
L_008a2c5a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c18; /* jl 0x8a2c18 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2c64u, "unsupported: pop ds"); /* pop ds */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ebx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ebx], cl */
    goto L_008a2c6a;
L_008a2c68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1fu))); /* or al, 0x1f */
L_008a2c6a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c28; /* jl 0x8a2c28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c38; /* jl 0x8a2c38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x21u))); /* or al, 0x21 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c48; /* jl 0x8a2c48 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & R8((uint32_t)(c->eax))))); /* and al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2c98:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x22u))); /* or al, 0x22 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c58; /* jl 0x8a2c58 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->eax))))); /* and eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2ca8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x23u))); /* or al, 0x23 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c68; /* jl 0x8a2c68 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x0u))); /* and al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2cb8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x24u))); /* or al, 0x24 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c78; /* jl 0x8a2c78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xc000000u))); /* and eax, 0xc000000 */
    goto L_008a2cc9;
L_008a2cc8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x25u))); /* or al, 0x25 */
    goto L_008a2cca;
L_008a2cc9:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    goto L_008a2cce;
L_008a2cca:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2cd0;
L_008a2cce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2cd0:;
    if ((c->sf != c->of)) goto L_008a2c88; /* jl 0x8a2c88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr es:[eax], al */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi], cl */
    goto L_008a2cda;
L_008a2cd8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x26u))); /* or al, 0x26 */
L_008a2cda:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2c98; /* jl 0x8a2c98 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2ce4u, "unsupported: daa "); /* daa  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi], cl */
    goto L_008a2cea;
L_008a2ce8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x27u))); /* or al, 0x27 */
L_008a2cea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ca8; /* jl 0x8a2ca8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(sub8(c, R8(a_), ((uint8_t)c->eax)))); } /* sub byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2cf8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x28u))); /* or al, 0x28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2cb8; /* jl 0x8a2cb8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(sub32(c, R32(a_), c->eax))); } /* sub dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x29u))); /* or al, 0x29 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2cc8; /* jl 0x8a2cc8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax)))); /* sub al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2au))); /* or al, 0x2a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2cd8; /* jl 0x8a2cd8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->eax)))); /* sub eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d28:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2bu))); /* or al, 0x2b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ce8; /* jl 0x8a2ce8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x0u)); /* sub al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d38:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2cu))); /* or al, 0x2c */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2cf8; /* jl 0x8a2cf8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xc000000u)); /* sub eax, 0xc000000 */
    goto L_008a2d49;
L_008a2d48:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2du))); /* or al, 0x2d */
    goto L_008a2d4a;
L_008a2d49:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x8000u)); /* sub eax, 0x8000 */
    goto L_008a2d4e;
L_008a2d4a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2d50;
L_008a2d4e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d50:;
    if ((c->sf != c->of)) goto L_008a2d08; /* jl 0x8a2d08 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr cs:[eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebp); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ebp], cl */
    goto L_008a2d5a;
L_008a2d58:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2eu))); /* or al, 0x2e */
L_008a2d5a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d18; /* jl 0x8a2d18 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2d64u, "unsupported: das "); /* das  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ebp); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ebp], cl */
    goto L_008a2d6a;
L_008a2d68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2fu))); /* or al, 0x2f */
L_008a2d6a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d28; /* jl 0x8a2d28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) ^ ((uint8_t)c->eax))))); } /* xor byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x30u))); /* or al, 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d38; /* jl 0x8a2d38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) ^ c->eax)))); } /* xor dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x31u))); /* or al, 0x31 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d48; /* jl 0x8a2d48 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) ^ R8((uint32_t)(c->eax))))); /* xor al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2d98:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x32u))); /* or al, 0x32 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d58; /* jl 0x8a2d58 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ R32((uint32_t)(c->eax))))); /* xor eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2da8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x33u))); /* or al, 0x33 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d68; /* jl 0x8a2d68 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) ^ (uint8_t)0x0u))); /* xor al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2db8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x34u))); /* or al, 0x34 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d78; /* jl 0x8a2d78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xc000000u))); /* xor eax, 0xc000000 */
    goto L_008a2dc9;
L_008a2dc8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x35u))); /* or al, 0x35 */
    goto L_008a2dca;
L_008a2dc9:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0x8000u))); /* xor eax, 0x8000 */
    goto L_008a2dce;
L_008a2dca:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2dd0;
L_008a2dce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2dd0:;
    if ((c->sf != c->of)) goto L_008a2d88; /* jl 0x8a2d88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr ss:[eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->esi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + esi], cl */
    goto L_008a2dda;
L_008a2dd8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x36u))); /* or al, 0x36 */
L_008a2dda:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2d98; /* jl 0x8a2d98 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2de4u, "unsupported: aaa "); /* aaa  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->esi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + esi], cl */
    goto L_008a2dea;
L_008a2de8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x37u))); /* or al, 0x37 */
L_008a2dea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2da8; /* jl 0x8a2da8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->eax)); /* cmp byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2df8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x38u))); /* or al, 0x38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2db8; /* jl 0x8a2db8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub32(c, R32((uint32_t)(c->eax)), c->eax); /* cmp dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2e08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x39u))); /* or al, 0x39 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2dc8; /* jl 0x8a2dc8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->eax))); /* cmp al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2e18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3au))); /* or al, 0x3a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2dd8; /* jl 0x8a2dd8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub32(c, c->eax, R32((uint32_t)(c->eax))); /* cmp eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2e28:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3bu))); /* or al, 0x3b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2de8; /* jl 0x8a2de8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x0u); /* cmp al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2e38:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3cu))); /* or al, 0x3c */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2df8; /* jl 0x8a2df8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub32(c, c->eax, (uint32_t)0xc000000u); /* cmp eax, 0xc000000 */
    goto L_008a2e49;
L_008a2e48:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3du))); /* or al, 0x3d */
    goto L_008a2e4a;
L_008a2e49:;
    (void)sub32(c, c->eax, (uint32_t)0x8000u); /* cmp eax, 0x8000 */
    goto L_008a2e4e;
L_008a2e4a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2e50;
L_008a2e4e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2e50:;
    if ((c->sf != c->of)) goto L_008a2e08; /* jl 0x8a2e08 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr ds:[eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->edi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + edi], cl */
    goto L_008a2e5a;
L_008a2e58:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3eu))); /* or al, 0x3e */
L_008a2e5a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e18; /* jl 0x8a2e18 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a2e64u, "unsupported: aas "); /* aas  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->edi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + edi], cl */
    goto L_008a2e6a;
L_008a2e68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x3fu))); /* or al, 0x3f */
L_008a2e6a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e28; /* jl 0x8a2e28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + eax*2], cl */
    goto L_008a2e7a;
L_008a2e78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x40u))); /* or al, 0x40 */
L_008a2e7a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e38; /* jl 0x8a2e38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + eax*2], cl */
    goto L_008a2e8a;
L_008a2e88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x41u))); /* or al, 0x41 */
L_008a2e8a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e48; /* jl 0x8a2e48 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + eax*2], cl */
    goto L_008a2e9a;
L_008a2e98:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x42u))); /* or al, 0x42 */
L_008a2e9a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e58; /* jl 0x8a2e58 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + eax*2], cl */
    goto L_008a2eaa;
L_008a2ea8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x43u))); /* or al, 0x43 */
L_008a2eaa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e68; /* jl 0x8a2e68 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esp = (uint32_t)(inc32(c, c->esp)); /* inc esp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + eax*2], cl */
    goto L_008a2eba;
L_008a2eb8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x44u))); /* or al, 0x44 */
L_008a2eba:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e78; /* jl 0x8a2e78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax * 2 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax*2 + 0x8000], cl */
    goto L_008a2ece;
L_008a2ec8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x45u))); /* or al, 0x45 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2ed0;
L_008a2ece:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2ed0:;
    if ((c->sf != c->of)) goto L_008a2e88; /* jl 0x8a2e88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + eax*2], cl */
    goto L_008a2eda;
L_008a2ed8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x46u))); /* or al, 0x46 */
L_008a2eda:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2e98; /* jl 0x8a2e98 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->eax * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + eax*2], cl */
    goto L_008a2eea;
L_008a2ee8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x47u))); /* or al, 0x47 */
L_008a2eea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ea8; /* jl 0x8a2ea8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + ecx*2], cl */
    goto L_008a2efa;
L_008a2ef8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x48u))); /* or al, 0x48 */
L_008a2efa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2eb8; /* jl 0x8a2eb8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + ecx*2], cl */
    goto L_008a2f0a;
L_008a2f08:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x49u))); /* or al, 0x49 */
L_008a2f0a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ec8; /* jl 0x8a2ec8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + ecx*2], cl */
    goto L_008a2f1a;
L_008a2f18:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4au))); /* or al, 0x4a */
L_008a2f1a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ed8; /* jl 0x8a2ed8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + ecx*2], cl */
    goto L_008a2f2a;
L_008a2f28:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4bu))); /* or al, 0x4b */
L_008a2f2a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ee8; /* jl 0x8a2ee8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esp = (uint32_t)(dec32(c, c->esp)); /* dec esp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + ecx*2], cl */
    goto L_008a2f3a;
L_008a2f38:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4cu))); /* or al, 0x4c */
L_008a2f3a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ef8; /* jl 0x8a2ef8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebp = (uint32_t)(dec32(c, c->ebp)); /* dec ebp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx * 2 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx*2 + 0x8000], cl */
    goto L_008a2f4e;
L_008a2f48:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4du))); /* or al, 0x4d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2f50;
L_008a2f4e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2f50:;
    if ((c->sf != c->of)) goto L_008a2f08; /* jl 0x8a2f08 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ecx*2], cl */
    goto L_008a2f5a;
L_008a2f58:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4eu))); /* or al, 0x4e */
L_008a2f5a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f18; /* jl 0x8a2f18 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ecx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ecx*2], cl */
    goto L_008a2f6a;
L_008a2f68:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4fu))); /* or al, 0x4f */
L_008a2f6a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f28; /* jl 0x8a2f28 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + edx*2], cl */
    goto L_008a2f7a;
L_008a2f78:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x50u))); /* or al, 0x50 */
L_008a2f7a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f38; /* jl 0x8a2f38 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + edx*2], cl */
    goto L_008a2f8a;
L_008a2f88:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x51u))); /* or al, 0x51 */
L_008a2f8a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f48; /* jl 0x8a2f48 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + edx*2], cl */
    goto L_008a2f9a;
L_008a2f98:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x52u))); /* or al, 0x52 */
L_008a2f9a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f58; /* jl 0x8a2f58 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + edx*2], cl */
    goto L_008a2faa;
L_008a2fa8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x53u))); /* or al, 0x53 */
L_008a2faa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f68; /* jl 0x8a2f68 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->esp; PUSH32(c, v_); } /* push esp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + edx*2], cl */
    goto L_008a2fba;
L_008a2fb8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x54u))); /* or al, 0x54 */
L_008a2fba:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f78; /* jl 0x8a2f78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx * 2 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx*2 + 0x8000], cl */
    goto L_008a2fce;
L_008a2fc8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x55u))); /* or al, 0x55 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a2fd0;
L_008a2fce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a2fd0:;
    if ((c->sf != c->of)) goto L_008a2f88; /* jl 0x8a2f88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + edx*2], cl */
    goto L_008a2fda;
L_008a2fd8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x56u))); /* or al, 0x56 */
L_008a2fda:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2f98; /* jl 0x8a2f98 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->edx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + edx*2], cl */
    goto L_008a2fea;
L_008a2fe8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x57u))); /* or al, 0x57 */
L_008a2fea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2fa8; /* jl 0x8a2fa8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + ebx*2], cl */
    goto L_008a2ffa;
L_008a2ff8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x58u))); /* or al, 0x58 */
L_008a2ffa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2fb8; /* jl 0x8a2fb8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + ebx*2], cl */
    goto L_008a300a;
L_008a3008:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x59u))); /* or al, 0x59 */
L_008a300a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2fc8; /* jl 0x8a2fc8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + ebx*2], cl */
    goto L_008a301a;
L_008a3018:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5au))); /* or al, 0x5a */
L_008a301a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2fd8; /* jl 0x8a2fd8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + ebx*2], cl */
    goto L_008a302a;
L_008a3028:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5bu))); /* or al, 0x5b */
L_008a302a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2fe8; /* jl 0x8a2fe8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->esp = (uint32_t)(v_); } /* pop esp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + ebx*2], cl */
    goto L_008a303a;
L_008a3038:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5cu))); /* or al, 0x5c */
L_008a303a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a2ff8; /* jl 0x8a2ff8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx * 2 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx*2 + 0x8000], cl */
    goto L_008a304e;
L_008a3048:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5du))); /* or al, 0x5d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3050;
L_008a304e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3050:;
    if ((c->sf != c->of)) goto L_008a3008; /* jl 0x8a3008 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ebx*2], cl */
    goto L_008a305a;
L_008a3058:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5eu))); /* or al, 0x5e */
L_008a305a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3018; /* jl 0x8a3018 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ebx * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ebx*2], cl */
    goto L_008a306a;
L_008a3068:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x5fu))); /* or al, 0x5f */
L_008a306a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3028; /* jl 0x8a3028 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t s_ = c->esp; PUSH32(c, c->eax); PUSH32(c, c->ecx); PUSH32(c, c->edx); PUSH32(c, c->ebx); PUSH32(c, s_); PUSH32(c, c->ebp); PUSH32(c, c->esi); PUSH32(c, c->edi); } /* pushal  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax], cl */
    goto L_008a307a;
L_008a3078:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x60u))); /* or al, 0x60 */
L_008a307a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3038; /* jl 0x8a3038 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edi = POP32(c); c->esi = POP32(c); c->ebp = POP32(c); c->esp += 4; c->ebx = POP32(c); c->edx = POP32(c); c->ecx = POP32(c); c->eax = POP32(c); /* popal  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx], cl */
    goto L_008a308a;
L_008a3088:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x61u))); /* or al, 0x61 */
L_008a308a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3048; /* jl 0x8a3048 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3094u, "unsupported: bound eax, qword ptr [eax]"); /* bound eax, qword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3098:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x62u))); /* or al, 0x62 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3058; /* jl 0x8a3058 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a30a4u, "unsupported: arpl word ptr [eax], ax"); /* arpl word ptr [eax], ax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a30a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x63u))); /* or al, 0x63 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3068; /* jl 0x8a3068 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax + c->fs_base); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr fs:[eax], al */
    { uint32_t a_ = (uint32_t)(c->esp); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp], cl */
    goto L_008a30ba;
L_008a30b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x64u))); /* or al, 0x64 */
L_008a30ba:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3078; /* jl 0x8a3078 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr gs:[eax], al */
    { uint32_t a_ = (uint32_t)(0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [0x8000], cl */
    goto L_008a30ce;
L_008a30c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x65u))); /* or al, 0x65 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a30d0;
L_008a30ce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a30d0:;
    if ((c->sf != c->of)) goto L_008a3088; /* jl 0x8a3088 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi], cl */
    goto L_008a30da;
L_008a30d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x66u))); /* or al, 0x66 */
L_008a30da:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3098; /* jl 0x8a3098 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(((uint16_t)c->ebx) + ((uint16_t)c->esi)); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [bx + si], al */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi], cl */
    goto L_008a30ea;
L_008a30e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x67u))); /* or al, 0x67 */
L_008a30ea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a30a8; /* jl 0x8a30a8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = 0xc000000u; PUSH32(c, v_); } /* push 0xc000000 */
    goto L_008a30f9;
L_008a30f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x68u))); /* or al, 0x68 */
    goto L_008a30fa;
L_008a30f9:;
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    goto L_008a30fe;
L_008a30fa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3100;
L_008a30fe:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3100:;
    if ((c->sf != c->of)) goto L_008a30b8; /* jl 0x8a30b8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { int64_t r_ = (int64_t)(int32_t)R32((uint32_t)(c->eax)) * (int32_t)(uint32_t)0x690c0000u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, dword ptr [eax], 0x690c0000 */
    goto L_008a310a;
L_008a3108:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x69u))); /* or al, 0x69 */
L_008a310a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a30c8; /* jl 0x8a30c8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3118:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6au))); /* or al, 0x6a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a30d8; /* jl 0x8a30d8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { int64_t r_ = (int64_t)(int32_t)R32((uint32_t)(c->eax)) * (int32_t)(uint32_t)0x0u; c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, dword ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->ebx + c->ebp * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + ebp*2], cl */
    goto L_008a312a;
L_008a3128:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6bu))); /* or al, 0x6b */
L_008a312a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a30e8; /* jl 0x8a30e8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3134u, "unsupported: insb byte ptr es:[edi], dx"); /* insb byte ptr es:[edi], dx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->ebp * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + ebp*2], cl */
    goto L_008a313a;
L_008a3138:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6cu))); /* or al, 0x6c */
L_008a313a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a30f8; /* jl 0x8a30f8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3144u, "unsupported: insd dword ptr es:[edi], dx"); /* insd dword ptr es:[edi], dx */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebp * 2 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebp*2 + 0x8000], cl */
    goto L_008a314e;
L_008a3148:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6du))); /* or al, 0x6d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3150;
L_008a314e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3150:;
    if ((c->sf != c->of)) goto L_008a3108; /* jl 0x8a3108 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3154u, "unsupported: outsb dx, byte ptr [esi]"); /* outsb dx, byte ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebp * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ebp*2], cl */
    goto L_008a315a;
L_008a3158:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6eu))); /* or al, 0x6e */
L_008a315a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3118; /* jl 0x8a3118 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3164u, "unsupported: outsd dx, dword ptr [esi]"); /* outsd dx, dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ebp * 2); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ebp*2], cl */
    goto L_008a316a;
L_008a3168:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x6fu))); /* or al, 0x6f */
L_008a316a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3128; /* jl 0x8a3128 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (c->of) goto L_008a3176; /* jo 0x8a3176 */
L_008a3176:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3178:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x70u))); /* or al, 0x70 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3138; /* jl 0x8a3138 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (!c->of) goto L_008a3186; /* jno 0x8a3186 */
L_008a3186:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3188:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x71u))); /* or al, 0x71 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3148; /* jl 0x8a3148 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (c->cf) goto L_008a3196; /* jb 0x8a3196 */
L_008a3196:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3198:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x72u))); /* or al, 0x72 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3158; /* jl 0x8a3158 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (!c->cf) goto L_008a31a6; /* jae 0x8a31a6 */
L_008a31a6:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a31a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x73u))); /* or al, 0x73 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3168; /* jl 0x8a3168 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (c->zf) goto L_008a31b6; /* je 0x8a31b6 */
L_008a31b6:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a31b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x74u))); /* or al, 0x74 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3178; /* jl 0x8a3178 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (!c->zf) goto L_008a31c6; /* jne 0x8a31c6 */
L_008a31c6:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a31c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x75u))); /* or al, 0x75 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3188; /* jl 0x8a3188 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if ((c->cf || c->zf)) goto L_008a31d6; /* jbe 0x8a31d6 */
L_008a31d6:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a31d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x76u))); /* or al, 0x76 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3198; /* jl 0x8a3198 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if ((!c->cf && !c->zf)) goto L_008a31e6; /* ja 0x8a31e6 */
L_008a31e6:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a31e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x77u))); /* or al, 0x77 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a31a8; /* jl 0x8a31a8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (c->sf) goto L_008a31f6; /* js 0x8a31f6 */
L_008a31f6:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a31f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x78u))); /* or al, 0x78 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a31b8; /* jl 0x8a31b8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (!c->sf) goto L_008a3206; /* jns 0x8a3206 */
L_008a3206:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3208:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x79u))); /* or al, 0x79 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a31c8; /* jl 0x8a31c8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (PF(c)) goto L_008a3216; /* jp 0x8a3216 */
L_008a3216:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3218:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7au))); /* or al, 0x7a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a31d8; /* jl 0x8a31d8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if (!PF(c)) goto L_008a3226; /* jnp 0x8a3226 */
L_008a3226:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3228:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7bu))); /* or al, 0x7b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a31e8; /* jl 0x8a31e8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if ((c->sf != c->of)) goto L_008a3236; /* jl 0x8a3236 */
L_008a3236:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3238:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7cu))); /* or al, 0x7c */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a31f8; /* jl 0x8a31f8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if ((c->sf == c->of)) goto L_008a3246; /* jge 0x8a3246 */
L_008a3246:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3248:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7du))); /* or al, 0x7d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3208; /* jl 0x8a3208 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if ((c->zf || c->sf != c->of)) goto L_008a3256; /* jle 0x8a3256 */
L_008a3256:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3258:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7eu))); /* or al, 0x7e */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3218; /* jl 0x8a3218 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    if ((!c->zf && c->sf == c->of)) goto L_008a3266; /* jg 0x8a3266 */
L_008a3266:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3268:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x7fu))); /* or al, 0x7f */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3228; /* jl 0x8a3228 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), (uint8_t)0x0u))); } /* add byte ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->eax + c->eax * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + eax*4], cl */
    goto L_008a327a;
L_008a3278:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x80u))); /* or al, 0x80 */
L_008a327a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3238; /* jl 0x8a3238 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x810c0000u))); } /* add dword ptr [eax], 0x810c0000 */
    goto L_008a328a;
L_008a3288:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x81u))); /* or al, 0x81 */
L_008a328a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3248; /* jl 0x8a3248 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), (uint8_t)0x0u))); } /* add byte ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->edx + c->eax * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + eax*4], cl */
    goto L_008a329a;
L_008a3298:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x82u))); /* or al, 0x82 */
L_008a329a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3258; /* jl 0x8a3258 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x0u))); } /* add dword ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->ebx + c->eax * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + eax*4], cl */
    goto L_008a32aa;
L_008a32a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x83u))); /* or al, 0x83 */
L_008a32aa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3268; /* jl 0x8a3268 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax)) & ((uint8_t)c->eax))); /* test byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a32b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x84u))); /* or al, 0x84 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3278; /* jl 0x8a3278 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax)) & c->eax)); /* test dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a32c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x85u))); /* or al, 0x85 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3288; /* jl 0x8a3288 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { guest_lock(); { uint8_t t0_ = R8((uint32_t)(c->eax)), t1_ = ((uint8_t)c->eax); W8((uint32_t)(c->eax), (uint8_t)(t1_)); c->eax = (c->eax & 0xffffff00u) | (uint8_t)(t0_); } guest_unlock(); } /* xchg byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a32d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x86u))); /* or al, 0x86 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3298; /* jl 0x8a3298 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->eax)), t1_ = c->eax; W32((uint32_t)(c->eax), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a32e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x87u))); /* or al, 0x87 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a32a8; /* jl 0x8a32a8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a32f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x88u))); /* or al, 0x88 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a32b8; /* jl 0x8a32b8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W32((uint32_t)(c->eax), (uint32_t)(c->eax)); /* mov dword ptr [eax], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3308:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x89u))); /* or al, 0x89 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a32c8; /* jl 0x8a32c8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov al, byte ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3318:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8au))); /* or al, 0x8a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a32d8; /* jl 0x8a32d8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3328:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8bu))); /* or al, 0x8b */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a32e8; /* jl 0x8a32e8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3334u, "unsupported: mov word ptr [eax], es"); /* mov word ptr [eax], es */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3338:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8cu))); /* or al, 0x8c */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a32f8; /* jl 0x8a32f8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)((uint32_t)(c->eax)); /* lea eax, [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3348:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8du))); /* or al, 0x8d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3308; /* jl 0x8a3308 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3354u, "unsupported: mov es, word ptr [eax]"); /* mov es, word ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3358:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8eu))); /* or al, 0x8e */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3318; /* jl 0x8a3318 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(c->eax), (uint32_t)(v_)); } /* pop dword ptr [eax] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3368:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8fu))); /* or al, 0x8f */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3328; /* jl 0x8a3328 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    ; /* nop  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + edx*4], cl */
    goto L_008a337a;
L_008a3378:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x90u))); /* or al, 0x90 */
L_008a337a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3338; /* jl 0x8a3338 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->ecx, t1_ = c->eax; c->ecx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ecx, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + edx*4], cl */
    goto L_008a338a;
L_008a3388:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x91u))); /* or al, 0x91 */
L_008a338a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3348; /* jl 0x8a3348 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->edx, t1_ = c->eax; c->edx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg edx, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + edx*4], cl */
    goto L_008a339a;
L_008a3398:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x92u))); /* or al, 0x92 */
L_008a339a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3358; /* jl 0x8a3358 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->ebx, t1_ = c->eax; c->ebx = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ebx, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + edx*4], cl */
    goto L_008a33aa;
L_008a33a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x93u))); /* or al, 0x93 */
L_008a33aa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3368; /* jl 0x8a3368 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->esp, t1_ = c->eax; c->esp = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg esp, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + edx*4], cl */
    goto L_008a33ba;
L_008a33b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x94u))); /* or al, 0x94 */
L_008a33ba:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3378; /* jl 0x8a3378 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->ebp, t1_ = c->eax; c->ebp = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg ebp, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx * 4 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx*4 + 0x8000], cl */
    goto L_008a33ce;
L_008a33c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x95u))); /* or al, 0x95 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a33d0;
L_008a33ce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a33d0:;
    if ((c->sf != c->of)) goto L_008a3388; /* jl 0x8a3388 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->esi, t1_ = c->eax; c->esi = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg esi, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + edx*4], cl */
    goto L_008a33da;
L_008a33d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x96u))); /* or al, 0x96 */
L_008a33da:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3398; /* jl 0x8a3398 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t t0_ = c->edi, t1_ = c->eax; c->edi = (uint32_t)(t1_); c->eax = (uint32_t)(t0_); } /* xchg edi, eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->edx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + edx*4], cl */
    goto L_008a33ea;
L_008a33e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x97u))); /* or al, 0x97 */
L_008a33ea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a33a8; /* jl 0x8a33a8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(int32_t)(int16_t)c->eax; /* cwde  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax + c->ebx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + ebx*4], cl */
    goto L_008a33fa;
L_008a33f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x98u))); /* or al, 0x98 */
L_008a33fa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a33b8; /* jl 0x8a33b8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ecx + c->ebx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + ebx*4], cl */
    goto L_008a340a;
L_008a3408:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x99u))); /* or al, 0x99 */
L_008a340a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a33c8; /* jl 0x8a33c8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    guest_trap(c, 0x008a3414u, "unsupported: lcall 0x9a, 0xc000000"); /* lcall 0x9a, 0xc000000 */
    goto L_008a341b;
L_008a3418:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9au))); /* or al, 0x9a */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3420;
L_008a341b:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), (uint8_t)0x0u))); } /* add byte ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3420:;
    if ((c->sf != c->of)) goto L_008a33d8; /* jl 0x8a33d8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    ; /* wait  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->ebx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + ebx*4], cl */
    goto L_008a342a;
L_008a3428:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9bu))); /* or al, 0x9b */
L_008a342a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a33e8; /* jl 0x8a33e8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    PUSH32(c, ((uint32_t)c->cf | (PF(c) << 2) | ((uint32_t)c->zf << 6) | ((uint32_t)c->sf << 7) | ((uint32_t)c->df << 10) | ((uint32_t)c->of << 11) | ((uint32_t)c->idf << 21) | 0x202u)); /* pushfd  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->ebx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + ebx*4], cl */
    goto L_008a343a;
L_008a3438:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9cu))); /* or al, 0x9c */
L_008a343a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a33f8; /* jl 0x8a33f8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t f_ = POP32(c); c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; c->df = (f_ >> 10) & 1; c->of = (f_ >> 11) & 1; c->idf = (f_ >> 21) & 1; } /* popfd  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx * 4 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx*4 + 0x8000], cl */
    goto L_008a344e;
L_008a3448:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9du))); /* or al, 0x9d */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3450;
L_008a344e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3450:;
    if ((c->sf != c->of)) goto L_008a3408; /* jl 0x8a3408 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ebx*4], cl */
    goto L_008a345a;
L_008a3458:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9eu))); /* or al, 0x9e */
L_008a345a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3418; /* jl 0x8a3418 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)((c->cf | (PF(c) << 2) | 2 | (c->zf << 6) | (c->sf << 7))) << 8); /* lahf  */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ebx * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ebx*4], cl */
    goto L_008a346a;
L_008a3468:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x9fu))); /* or al, 0x9f */
L_008a346a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3428; /* jl 0x8a3428 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xc000000u))); /* mov al, byte ptr [0xc000000] */
    goto L_008a3479;
L_008a3478:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa0u))); /* or al, 0xa0 */
    goto L_008a347a;
L_008a3479:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x8000u))); /* mov al, byte ptr [0x8000] */
    goto L_008a347e;
L_008a347a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3480;
L_008a347e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3480:;
    if ((c->sf != c->of)) goto L_008a3438; /* jl 0x8a3438 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(R32((uint32_t)(0xc000000u))); /* mov eax, dword ptr [0xc000000] */
    goto L_008a3489;
L_008a3488:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa1u))); /* or al, 0xa1 */
    goto L_008a348a;
L_008a3489:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8000u))); /* mov eax, dword ptr [0x8000] */
    goto L_008a348e;
L_008a348a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3490;
L_008a348e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3490:;
    if ((c->sf != c->of)) goto L_008a3448; /* jl 0x8a3448 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W8((uint32_t)(0xc000000u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [0xc000000], al */
    goto L_008a3499;
L_008a3498:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa2u))); /* or al, 0xa2 */
    goto L_008a349a;
L_008a3499:;
    W8((uint32_t)(0x8000u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [0x8000], al */
    goto L_008a349e;
L_008a349a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a34a0;
L_008a349e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a34a0:;
    if ((c->sf != c->of)) goto L_008a3458; /* jl 0x8a3458 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W32((uint32_t)(0xc000000u), (uint32_t)(c->eax)); /* mov dword ptr [0xc000000], eax */
    goto L_008a34a9;
L_008a34a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa3u))); /* or al, 0xa3 */
    goto L_008a34aa;
L_008a34a9:;
    W32((uint32_t)(0x8000u), (uint32_t)(c->eax)); /* mov dword ptr [0x8000], eax */
    goto L_008a34ae;
L_008a34aa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a34b0;
L_008a34ae:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a34b0:;
    if ((c->sf != c->of)) goto L_008a3468; /* jl 0x8a3468 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W8(c->edi, R8(c->esi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); /* movsb byte ptr es:[edi], byte ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp], cl */
    goto L_008a34ba;
L_008a34b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa4u))); /* or al, 0xa4 */
L_008a34ba:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3478; /* jl 0x8a3478 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [0x8000], cl */
    goto L_008a34ce;
L_008a34c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa5u))); /* or al, 0xa5 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a34d0;
L_008a34ce:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a34d0:;
    if ((c->sf != c->of)) goto L_008a3488; /* jl 0x8a3488 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub8(c, R8(c->esi), R8(c->edi)); c->esi += (c->df ? -1 : 1); c->edi += (c->df ? -1 : 1); /* cmpsb byte ptr [esi], byte ptr es:[edi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi], cl */
    goto L_008a34da;
L_008a34d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa6u))); /* or al, 0xa6 */
L_008a34da:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3498; /* jl 0x8a3498 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub32(c, R32(c->esi), R32(c->edi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); /* cmpsd dword ptr [esi], dword ptr es:[edi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi], cl */
    goto L_008a34ea;
L_008a34e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa7u))); /* or al, 0xa7 */
L_008a34ea:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a34a8; /* jl 0x8a34a8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x0u)); /* test al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a34f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa8u))); /* or al, 0xa8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a34b8; /* jl 0x8a34b8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xc000000u)); /* test eax, 0xc000000 */
    goto L_008a3509;
L_008a3508:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xa9u))); /* or al, 0xa9 */
    goto L_008a350a;
L_008a3509:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u)); /* test eax, 0x8000 */
    goto L_008a350e;
L_008a350a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3510;
L_008a350e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3510:;
    if ((c->sf != c->of)) goto L_008a34c8; /* jl 0x8a34c8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W8(c->edi, (uint8_t)((uint8_t)c->eax)); c->edi += (c->df ? -1 : 1); /* stosb byte ptr es:[edi], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edx + c->ebp * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edx + ebp*4], cl */
    goto L_008a351a;
L_008a3518:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xaau))); /* or al, 0xaa */
L_008a351a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a34d8; /* jl 0x8a34d8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); /* stosd dword ptr es:[edi], eax */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx + c->ebp * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebx + ebp*4], cl */
    goto L_008a352a;
L_008a3528:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xabu))); /* or al, 0xab */
L_008a352a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a34e8; /* jl 0x8a34e8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8(c->esi)); c->esi += (c->df ? -1 : 1); /* lodsb al, byte ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esp + c->ebp * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esp + ebp*4], cl */
    goto L_008a353a;
L_008a3538:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xacu))); /* or al, 0xac */
L_008a353a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a34f8; /* jl 0x8a34f8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)(R32(c->esi)); c->esi += (c->df ? -4 : 4); /* lodsd eax, dword ptr [esi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebp * 4 + 0x8000u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ebp*4 + 0x8000], cl */
    goto L_008a354e;
L_008a3548:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xadu))); /* or al, 0xad */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3550;
L_008a354e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3550:;
    if ((c->sf != c->of)) goto L_008a3508; /* jl 0x8a3508 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub8(c, ((uint8_t)c->eax), R8(c->edi)); c->edi += (c->df ? -1 : 1); /* scasb al, byte ptr es:[edi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->esi + c->ebp * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [esi + ebp*4], cl */
    goto L_008a355a;
L_008a3558:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xaeu))); /* or al, 0xae */
L_008a355a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3518; /* jl 0x8a3518 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    (void)sub32(c, c->eax, R32(c->edi)); c->edi += (c->df ? -4 : 4); /* scasd eax, dword ptr es:[edi] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->edi + c->ebp * 4); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [edi + ebp*4], cl */
    goto L_008a356a;
L_008a3568:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xafu))); /* or al, 0xaf */
L_008a356a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3528; /* jl 0x8a3528 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov al, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3578:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb0u))); /* or al, 0xb0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3538; /* jl 0x8a3538 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov cl, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3588:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb1u))); /* or al, 0xb1 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3548; /* jl 0x8a3548 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov dl, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3598:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb2u))); /* or al, 0xb2 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3558; /* jl 0x8a3558 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov bl, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a35a8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb3u))); /* or al, 0xb3 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3568; /* jl 0x8a3568 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x0u) << 8); /* mov ah, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a35b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb4u))); /* or al, 0xb4 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3578; /* jl 0x8a3578 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x0u) << 8); /* mov ch, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a35c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb5u))); /* or al, 0xb5 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3588; /* jl 0x8a3588 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x0u) << 8); /* mov dh, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a35d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb6u))); /* or al, 0xb6 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3598; /* jl 0x8a3598 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x0u) << 8); /* mov bh, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a35e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb7u))); /* or al, 0xb7 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a35a8; /* jl 0x8a35a8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->eax = (uint32_t)((uint32_t)0xc000000u); /* mov eax, 0xc000000 */
    goto L_008a35f9;
L_008a35f8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb8u))); /* or al, 0xb8 */
    goto L_008a35fa;
L_008a35f9:;
    c->eax = (uint32_t)((uint32_t)0x8000u); /* mov eax, 0x8000 */
    goto L_008a35fe;
L_008a35fa:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3600;
L_008a35fe:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3600:;
    if ((c->sf != c->of)) goto L_008a35b8; /* jl 0x8a35b8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ecx = (uint32_t)((uint32_t)0xc000000u); /* mov ecx, 0xc000000 */
    goto L_008a3609;
L_008a3608:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xb9u))); /* or al, 0xb9 */
    goto L_008a360a;
L_008a3609:;
    c->ecx = (uint32_t)((uint32_t)0x8000u); /* mov ecx, 0x8000 */
    goto L_008a360e;
L_008a360a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3610;
L_008a360e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3610:;
    if ((c->sf != c->of)) goto L_008a35c8; /* jl 0x8a35c8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edx = (uint32_t)((uint32_t)0xc000000u); /* mov edx, 0xc000000 */
    goto L_008a3619;
L_008a3618:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xbau))); /* or al, 0xba */
    goto L_008a361a;
L_008a3619:;
    c->edx = (uint32_t)((uint32_t)0x8000u); /* mov edx, 0x8000 */
    goto L_008a361e;
L_008a361a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3620;
L_008a361e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3620:;
    if ((c->sf != c->of)) goto L_008a35d8; /* jl 0x8a35d8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebx = (uint32_t)((uint32_t)0xc000000u); /* mov ebx, 0xc000000 */
    goto L_008a3629;
L_008a3628:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xbbu))); /* or al, 0xbb */
    goto L_008a362a;
L_008a3629:;
    c->ebx = (uint32_t)((uint32_t)0x8000u); /* mov ebx, 0x8000 */
    goto L_008a362e;
L_008a362a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3630;
L_008a362e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3630:;
    if ((c->sf != c->of)) goto L_008a35e8; /* jl 0x8a35e8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esp = (uint32_t)((uint32_t)0xc000000u); /* mov esp, 0xc000000 */
    goto L_008a3639;
L_008a3638:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xbcu))); /* or al, 0xbc */
    goto L_008a363a;
L_008a3639:;
    c->esp = (uint32_t)((uint32_t)0x8000u); /* mov esp, 0x8000 */
    goto L_008a363e;
L_008a363a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3640;
L_008a363e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3640:;
    if ((c->sf != c->of)) goto L_008a35f8; /* jl 0x8a35f8 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->ebp = (uint32_t)((uint32_t)0xc000000u); /* mov ebp, 0xc000000 */
    goto L_008a3649;
L_008a3648:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0xbdu))); /* or al, 0xbd */
    goto L_008a364a;
L_008a3649:;
    c->ebp = (uint32_t)((uint32_t)0x8000u); /* mov ebp, 0x8000 */
    goto L_008a364e;
L_008a364a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    goto L_008a3650;
L_008a364e:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
L_008a3650:;
    if ((c->sf != c->of)) goto L_008a3608; /* jl 0x8a3608 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esi = (uint32_t)((uint32_t)0xc000000u); /* mov esi, 0xc000000 */
    c->esi = (uint32_t)((uint32_t)0x8000u); /* mov esi, 0x8000 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3618; /* jl 0x8a3618 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->edi = (uint32_t)((uint32_t)0xc000000u); /* mov edi, 0xc000000 */
    c->edi = (uint32_t)((uint32_t)0x8000u); /* mov edi, 0x8000 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3628; /* jl 0x8a3628 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(rol8(c, R8(a_), 0))); } /* rol byte ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->eax + c->eax * 8); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [eax + eax*8], cl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3638; /* jl 0x8a3638 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(rol32(c, R32(a_), 0))); } /* rol dword ptr [eax], 0 */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax * 8); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ecx)))); } /* add byte ptr [ecx + eax*8], cl */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    if ((c->sf != c->of)) goto L_008a3648; /* jl 0x8a3648 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->edx)))); } /* add byte ptr [eax], dl */
    c->esp += 4; return; /* ret 0 */
}

void f_008a3a70(CPU *c) { /* PTR_008a3a70 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8(c->esi)); c->esi += (c->df ? -1 : 1); /* lodsb al, byte ptr [esi] */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)0x0u) << 8); /* mov dh, 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->eax)))); } /* adc byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [eax], al */
    { uint32_t a_ = (uint32_t)(c->ebx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ebx], al */
    { jump_indirect(c, 0x008a3a79u, 0x008a3a77u); return; }
}

void f_008a3ae0(CPU *c) { /* DINPUT8.DLL::DirectInput8Create */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(0x8ab000u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a3ae0u); return; } } /* jmp dword ptr [0x1000b000] */
}

void f_008a3ae6(CPU *c) { /* FUN_10003ae6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov esp, dword ptr [ebx - 4] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebp, dword ptr [ebp - 4] */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x008a3b11u); return; } } /* jmp eax */
}

void f_008a3b13(CPU *c) { /* PTR_008a3b13 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_008a3b1a(CPU *c) { /* FUN_10003b1a */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x008a3b1fu); return; } } /* jmp eax */
}

void f_008a3b21(CPU *c) { /* FUN_10003b21 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x008a3b26u); return; } } /* jmp eax */
}

void f_008a3b28(CPU *c) { /* FUN_10003b28 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x8a3b50u)); /* mov dword ptr [ebp - 4], 0x10003b50 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a3b50u); f_008aa970(c); /* call 0x8aa970 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_008a3b50(CPU *c) { /* PTR_008a3b50 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfdu))); /* and al, 0xfd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_008a3b77(CPU *c) { /* FUN_10003b77 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x4u)); /* sub esp, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->df = 0; /* cld  */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a3b9du); f_008a41a3(c); /* call 0x8a41a3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->ebp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x14], eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a3bad(CPU *c) { /* FUN_10003bad */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8a3c01u)); /* mov dword ptr [ebp - 0x10], 0x10003c01 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x008a3bf2u); f_008a49c0(c); /* call 0x8a49c0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a3c01(CPU *c) { /* FUN_10003c01 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->df = 0; /* cld  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, v_); } /* push dword ptr [eax + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a3c21u); f_008a41a3(c); /* call 0x8a41a3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a3c26(CPU *c) { /* FUN_10003c26 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x8a3cdcu)); /* mov dword ptr [ebp - 0x24], 0x10003cdc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov eax, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x10], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0xc], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 8], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8a3caeu)); /* mov dword ptr [ebp - 0x10], 0x10003cae */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0xc], esp */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ebp)); /* mov dword ptr [ebp - 8], ebp */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd0u)); /* lea eax, [ebp - 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax)); PUSH32(c, v_); } /* push dword ptr [eax] */
    PUSH32(c, 0x008a3ca5u); f_008a4a91(c); /* call 0x8a4a91 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x008a3ca8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_008a3ccb; /* je 0x8a3ccb */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_008a3cd4; /* jmp 0x8a3cd4 */
L_008a3ccb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_008a3cd4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a3cae(CPU *c) { /* PTR_008a3cae */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_008a3ccb; /* je 0x8a3ccb */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_008a3cd4; /* jmp 0x8a3cd4 */
L_008a3ccb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_008a3cd4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a3cdc(CPU *c) { /* FUN_10003cdc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->df = 0; /* cld  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x66u))); /* and eax, 0x66 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a3cff; /* je 0x8a3cff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_008a3d4c; /* jmp 0x8a3d4c */
L_008a3cff:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, v_); } /* push dword ptr [eax + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a3d26u); f_008a41a3(c); /* call 0x8a41a3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_008a3d3d; /* jne 0x8a3d3d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a3d3du); f_008a3b28(c); /* call 0x8a3b28 */
L_008a3d3d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a3d46u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_008a3d4c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a3d01(CPU *c) { /* PTR_008a3d01 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, v_); } /* push dword ptr [eax + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0xcu)); PUSH32(c, v_); } /* push dword ptr [eax + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a3d26u); f_008a41a3(c); /* call 0x8a41a3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_008a3d3d; /* jne 0x8a3d3d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a3d3du); f_008a3b28(c); /* call 0x8a3b28 */
L_008a3d3d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a3d46u); return; } } /* jmp dword ptr [ebx + 0x18] */
}

void f_008a3d51(CPU *c) { /* FUN_10003d51 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov esi, dword ptr [edi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov ebx, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if ((c->sf != c->of)) goto L_008a3da8; /* jl 0x8a3da8 */
L_008a3d6f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_008a3d79; /* jne 0x8a3d79 */
    PUSH32(c, 0x008a3d79u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a3d79:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_008a3d8e; /* jge 0x8a3d8e */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_008a3d93; /* jle 0x8a3d93 */
L_008a3d8e:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_008a3d9f; /* jne 0x8a3d9f */
L_008a3d93:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_008a3d9f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_008a3d6f; /* jge 0x8a3d6f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_008a3da8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_008a3dbc; /* ja 0x8a3dbc */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_008a3dc1; /* jbe 0x8a3dc1 */
L_008a3dbc:;
    PUSH32(c, 0x008a3dc1u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a3dc1:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a3dcc(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x8a3de4u; PUSH32(c, v_); } /* push 0x10003de4 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a3de4u); f_008aa970(c); /* call 0x8aa970 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a3de4(CPU *c) { /* PTR_008a3de4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a3dec(CPU *c) { /* PTR_008a3dec */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_008a3e0d; /* je 0x8a3e0d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_008a3e0d:;
    c->esp += 4; return; /* ret  */
}

void f_008a3e0e(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x8a3decu; PUSH32(c, v_); } /* push 0x10003dec */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_008a3e2b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_008a3e68; /* je 0x8a3e68 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_008a3e68; /* je 0x8a3e68 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_008a3e66; /* jne 0x8a3e66 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x008a3e62u); f_008a3ea2(c); /* call 0x8a3ea2 */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x008a3e66u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_008a3e66:;
    goto L_008a3e2b; /* jmp 0x8a3e2b */
L_008a3e68:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_008a3e76(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x8a3decu); /* cmp dword ptr [ecx + 4], 0x10003dec */
    if (!c->zf) goto L_008a3e98; /* jne 0x8a3e98 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_008a3e98; /* jne 0x8a3e98 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_008a3e98:;
    c->esp += 4; return; /* ret  */
}

void f_008a3e99(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x8ad208u); /* mov ebx, 0x1000d208 */
    { f_008a3eac(c); return; } /* jmp 0x8a3eac */
}

void f_008a3ea2(CPU *c) { /* FUN_10003ea2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x8ad208u); /* mov ebx, 0x1000d208 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_008a3eac(CPU *c) { /* PTR_008a3eac */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_008a3eba(CPU *c) { /* PTR_008a3eba */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x19u; PUSH32(c, v_); } /* push 0x19 */
    PUSH32(c, 0x008a3ec1u); f_008a4170(c); /* call 0x8a4170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a3ec3(CPU *c) { /* FUN_10003ec3 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x008a3ec8u); f_008a3edb(c); /* call 0x8a3edb */
    PUSH32(c, 0x008a3ecdu); f_008a4c9f(c); /* call 0x8a4c9f */
    W32((uint32_t)(0x8aff78u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff78], eax */
    PUSH32(c, 0x008a3ed7u); f_008a4c4f(c); /* call 0x8a4c4f */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_008a3eda(CPU *c) { /* PTR_008a3eda */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_008a3edb(CPU *c) { /* FUN_10003edb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x8a5078u); /* mov eax, 0x10005078 */
    W32((uint32_t)(0x8ad24cu), (uint32_t)((uint32_t)0x8a4d22u)); /* mov dword ptr [0x1000d24c], 0x10004d22 */
    W32((uint32_t)(0x8ad248u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d248], eax */
    W32((uint32_t)(0x8ad250u), (uint32_t)((uint32_t)0x8a4d88u)); /* mov dword ptr [0x1000d250], 0x10004d88 */
    W32((uint32_t)(0x8ad254u), (uint32_t)((uint32_t)0x8a4cc8u)); /* mov dword ptr [0x1000d254], 0x10004cc8 */
    W32((uint32_t)(0x8ad258u), (uint32_t)((uint32_t)0x8a4d70u)); /* mov dword ptr [0x1000d258], 0x10004d70 */
    W32((uint32_t)(0x8ad25cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d25c], eax */
    c->esp += 4; return; /* ret  */
}

void f_008a3f14(CPU *c) { /* __ftol */
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

void f_008a3f3b(CPU *c) { /* PTR_008a3f3b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a3f41u); f_008a51e0(c); /* call 0x8a51e0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0670u)); PUSH32(c, v_); } /* push dword ptr [0x10010670] */
    PUSH32(c, 0x008a3f4cu); f_008a553b(c); /* call 0x8a553b */
    c->edx = (uint32_t)(R32((uint32_t)(0x8b0670u))); /* mov edx, dword ptr [0x10010670] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8b066cu))); /* mov ecx, dword ptr [0x1001066c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_008a3fa1; /* jae 0x8a3fa1 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008a3f6au); f_008a553b(c); /* call 0x8a553b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x8b0670u)); PUSH32(c, v_); } /* push dword ptr [0x10010670] */
    PUSH32(c, 0x008a3f79u); f_008a520c(c); /* call 0x8a520c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a3f84; /* jne 0x8a3f84 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_008a3fb0; /* jmp 0x8a3fb0 */
L_008a3f84:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x8b066cu))); /* mov ecx, dword ptr [0x1001066c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x8b0670u)))); /* sub ecx, dword ptr [0x10010670] */
    W32((uint32_t)(0x8b0670u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010670], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x8b066cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001066c], ecx */
L_008a3fa1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x8b066cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x1001066c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a3fb0:;
    PUSH32(c, 0x008a3fb5u); f_008a51e9(c); /* call 0x8a51e9 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a3fb9(CPU *c) { /* PTR_008a3fb9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x008a3fc2u); f_008a3f3b(c); /* call 0x8a3f3b */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_008a3fcb(CPU *c) { /* PTR_008a3fcb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x008a3fd5u); f_008a5629(c); /* call 0x8a5629 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x8b0670u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010670], eax */
    if (!c->zf) goto L_008a3fec; /* jne 0x8a3fec */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x008a3fe6u); f_008a4170(c); /* call 0x8a4170 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0670u))); /* mov eax, dword ptr [0x10010670] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a3fec:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0670u))); /* mov eax, dword ptr [0x10010670] */
    W32((uint32_t)(0x8b066cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001066c], eax */
    c->esp += 4; return; /* ret  */
}

void f_008a3ffa(CPU *c) { /* FUN_10003ffa */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_008a408f; /* jne 0x8a408f */
    { uint32_t t_ = R32((uint32_t)(0x8ab014u)); PUSH32(c, 0x008a400du); call_indirect(c, t_); } /* call dword ptr [0x1000b014] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x8aff94u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff94], eax */
    PUSH32(c, 0x008a4019u); f_008a5f20(c); /* call 0x8a5f20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a405a; /* je 0x8a405a */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff94u))); /* mov eax, dword ptr [0x1000ff94] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x8aff95u))); /* mov cl, byte ptr [0x1000ff95] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x8aff94u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x1000ff94], 0x10 */
    W32((uint32_t)(0x8aff9cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff9c], eax */
    W32((uint32_t)(0x8affa0u), (uint32_t)(c->ecx)); /* mov dword ptr [0x1000ffa0], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x8aff98u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff98], eax */
    PUSH32(c, 0x008a4051u); f_008a4a0c(c); /* call 0x8a4a0c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a405e; /* jne 0x8a405e */
    PUSH32(c, 0x008a405au); f_008a5f7d(c); /* call 0x8a5f7d */
L_008a405a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_008a40d0; /* jmp 0x8a40d0 */
L_008a405e:;
    { uint32_t t_ = R32((uint32_t)(0x8ab010u)); PUSH32(c, 0x008a4064u); call_indirect(c, t_); } /* call dword ptr [0x1000b010] */
    W32((uint32_t)(0x8b0674u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010674], eax */
    PUSH32(c, 0x008a406eu); f_008a5c79(c); /* call 0x8a5c79 */
    W32((uint32_t)(0x8aff80u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ff80], eax */
    PUSH32(c, 0x008a4078u); f_008a5763(c); /* call 0x8a5763 */
    PUSH32(c, 0x008a407du); f_008a5a2c(c); /* call 0x8a5a2c */
    PUSH32(c, 0x008a4082u); f_008a5973(c); /* call 0x8a5973 */
    PUSH32(c, 0x008a4087u); f_008a50ee(c); /* call 0x8a50ee */
    { uint32_t a_ = (uint32_t)(0x8aff7cu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x1000ff7c] */
    goto L_008a40cd; /* jmp 0x8a40cd */
L_008a408f:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_008a40c1; /* jne 0x8a40c1 */
    (void)sub32(c, R32((uint32_t)(0x8aff7cu)), c->ecx); /* cmp dword ptr [0x1000ff7c], ecx */
    if ((c->zf || c->sf != c->of)) goto L_008a405a; /* jle 0x8a405a */
    { uint32_t a_ = (uint32_t)(0x8aff7cu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x1000ff7c] */
    (void)sub32(c, R32((uint32_t)(0x8affccu)), c->ecx); /* cmp dword ptr [0x1000ffcc], ecx */
    if (!c->zf) goto L_008a40b0; /* jne 0x8a40b0 */
    PUSH32(c, 0x008a40b0u); f_008a512c(c); /* call 0x8a512c */
L_008a40b0:;
    PUSH32(c, 0x008a40b5u); f_008a591f(c); /* call 0x8a591f */
    PUSH32(c, 0x008a40bau); f_008a4a60(c); /* call 0x8a4a60 */
    PUSH32(c, 0x008a40bfu); f_008a5f7d(c); /* call 0x8a5f7d */
    goto L_008a40cd; /* jmp 0x8a40cd */
L_008a40c1:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_008a40cd; /* jne 0x8a40cd */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a40ccu); f_008a4af8(c); /* call 0x8a4af8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a40cd:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_008a40d0:;
    c->esp += 16; return; /* ret 0xc */
}

void f_008a40d3(CPU *c) { /* entry */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_008a40ef; /* jne 0x8a40ef */
    (void)sub32(c, R32((uint32_t)(0x8aff7cu)), (uint32_t)0x0u); /* cmp dword ptr [0x1000ff7c], 0 */
    goto L_008a4115; /* jmp 0x8a4115 */
L_008a40ef:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_008a40f9; /* je 0x8a40f9 */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_008a411b; /* jne 0x8a411b */
L_008a40f9:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0678u))); /* mov eax, dword ptr [0x10010678] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a410b; /* je 0x8a410b */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a4107u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4117; /* je 0x8a4117 */
L_008a410b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a4113u); f_008a3ffa(c); /* call 0x8a3ffa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_008a4115:;
    if (!c->zf) goto L_008a411b; /* jne 0x8a411b */
L_008a4117:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_008a4169; /* jmp 0x8a4169 */
L_008a411b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a4123u); f_008a6025(c); /* call 0x8a6025 */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_008a4137; /* jne 0x8a4137 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a4166; /* jne 0x8a4166 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a4137u); f_008a3ffa(c); /* call 0x8a3ffa */
L_008a4137:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a4140; /* je 0x8a4140 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_008a4166; /* jne 0x8a4166 */
L_008a4140:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a4148u); f_008a3ffa(c); /* call 0x8a3ffa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a414f; /* jne 0x8a414f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_008a414f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_008a4166; /* je 0x8a4166 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0678u))); /* mov eax, dword ptr [0x10010678] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4166; /* je 0x8a4166 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a4163u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_008a4166:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_008a4169:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a4170(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff88u))); /* mov eax, dword ptr [0x1000ff88] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_008a4187; /* je 0x8a4187 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a418c; /* jne 0x8a418c */
    (void)sub32(c, R32((uint32_t)(0x8aff8cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000ff8c], 1 */
    if (!c->zf) goto L_008a418c; /* jne 0x8a418c */
L_008a4187:;
    PUSH32(c, 0x008a418cu); f_008a602b(c); /* call 0x8a602b */
L_008a418c:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x008a4195u); f_008a6064(c); /* call 0x8a6064 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x8ad22cu)); PUSH32(c, 0x008a41a0u); call_indirect(c, t_); } /* call dword ptr [0x1000d22c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a41a0(CPU *c) { /* PTR_008a41a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a41a3(CPU *c) { /* FUN_100041a3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_008a41b9; /* je 0x8a41b9 */
    PUSH32(c, 0x008a41b9u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a41b9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_008a41e1; /* je 0x8a41e1 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_008a4237; /* je 0x8a4237 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_008a4237; /* jne 0x8a4237 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a41dcu); f_008a44f8(c); /* call 0x8a44f8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_008a4237; /* jmp 0x8a4237 */
L_008a41e1:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_008a4237; /* je 0x8a4237 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_008a421b; /* jne 0x8a421b */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_008a421b; /* jbe 0x8a421b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008a421b; /* je 0x8a421b */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x008a4216u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_008a423a; /* jmp 0x8a423a */
L_008a421b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4234u); f_008a423e(c); /* call 0x8a423e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_008a4237:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_008a423a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a423e(CPU *c) { /* FUN_1000423e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_008a425e; /* jl 0x8a425e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_008a4263; /* jl 0x8a4263 */
L_008a425e:;
    PUSH32(c, 0x008a4263u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a4263:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_008a43c6; /* jne 0x8a43c6 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_008a42e3; /* jne 0x8a42e3 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_008a42e3; /* jne 0x8a42e3 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_008a42e3; /* jne 0x8a42e3 */
    PUSH32(c, 0x008a4291u); f_008a4a91(c); /* call 0x8a4a91 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_008a43c1; /* je 0x8a43c1 */
    PUSH32(c, 0x008a42a0u); f_008a4a91(c); /* call 0x8a4a91 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x008a42a8u); f_008a4a91(c); /* call 0x8a4a91 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x008a42bau); f_008a621b(c); /* call 0x8a621b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_008a42c5; /* jne 0x8a42c5 */
    PUSH32(c, 0x008a42c5u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a42c5:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_008a43c6; /* jne 0x8a43c6 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_008a42e3; /* jne 0x8a42e3 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_008a42e3; /* jne 0x8a42e3 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_008a42e3; /* jne 0x8a42e3 */
    PUSH32(c, 0x008a42e3u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a42e3:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_008a43c6; /* jne 0x8a43c6 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_008a43c6; /* jne 0x8a43c6 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_008a43c6; /* jne 0x8a43c6 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x008a4315u); f_008a3d51(c); /* call 0x8a3d51 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_008a431a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_008a43b1; /* jae 0x8a43b1 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_008a43a6; /* jg 0x8a43a6 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_008a43a6; /* jg 0x8a43a6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_008a43a3; /* jle 0x8a43a3 */
L_008a433f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_008a4370; /* jle 0x8a4370 */
L_008a4351:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a435eu); f_008a449b(c); /* call 0x8a449b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a437f; /* jne 0x8a437f */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_008a4351; /* jg 0x8a4351 */
L_008a4370:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_008a433f; /* jg 0x8a433f */
    goto L_008a43a3; /* jmp 0x8a43a3 */
L_008a437f:;
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
    PUSH32(c, 0x008a43a0u); f_008a45ac(c); /* call 0x8a45ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_008a43a3:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_008a43a6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_008a431a; /* jmp 0x8a431a */
L_008a43b1:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_008a43c1; /* je 0x8a43c1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a43bfu); f_008a4930(c); /* call 0x8a4930 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a43c1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a43c6:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_008a43ec; /* jne 0x8a43ec */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a43e7u); f_008a43f1(c); /* call 0x8a43f1 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_008a43c1; /* jmp 0x8a43c1 */
L_008a43ec:;
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a43f1(CPU *c) { /* FUN_100043f1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a43fdu); f_008a4a91(c); /* call 0x8a4a91 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_008a4424; /* je 0x8a4424 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a441du); f_008a3c26(c); /* call 0x8a3c26 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a4497; /* jne 0x8a4497 */
L_008a4424:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x008a443bu); f_008a3d51(c); /* call 0x8a3d51 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a4440:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_008a4497; /* jae 0x8a4497 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_008a448f; /* jl 0x8a448f */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_008a448f; /* jg 0x8a448f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008a4469; /* je 0x8a4469 */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_008a448f; /* jne 0x8a448f */
L_008a4469:;
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
    PUSH32(c, 0x008a448cu); f_008a45ac(c); /* call 0x8a45ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_008a448f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_008a4440; /* jmp 0x8a4440 */
L_008a4497:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a449b(CPU *c) { /* FUN_1000449b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a44f2; /* je 0x8a44f2 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_008a44f2; /* je 0x8a44f2 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_008a44cc; /* je 0x8a44cc */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x008a44c6u); f_008a6270(c); /* call 0x8a6270 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_008a44ee; /* jne 0x8a44ee */
L_008a44cc:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_008a44d6; /* je 0x8a44d6 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_008a44ee; /* je 0x8a44ee */
L_008a44d6:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_008a44e5; /* je 0x8a44e5 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_008a44ee; /* je 0x8a44ee */
L_008a44e5:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_008a44f2; /* je 0x8a44f2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_008a44f2; /* jne 0x8a44f2 */
L_008a44ee:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_008a44f5; /* jmp 0x8a44f5 */
L_008a44f2:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_008a44f5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a44f8(CPU *c) { /* FUN_100044f8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab6d0u; PUSH32(c, v_); } /* push 0x1000b6d0 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
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
L_008a452a:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_008a4584; /* je 0x8a4584 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_008a4539; /* jle 0x8a4539 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_008a453e; /* jl 0x8a453e */
L_008a4539:;
    PUSH32(c, 0x008a453eu); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a453e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4559; /* je 0x8a4559 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4559u); f_008a49c0(c); /* call 0x8a49c0 */
L_008a4559:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_008a4579; /* jmp 0x8a4579 */
L_008a4579:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_008a452a; /* jmp 0x8a452a */
L_008a4584:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a452a(CPU *c) { /* PTR_008a452a */
    PREEMPT_POLL(c);
L_008a452a:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_008a4584; /* je 0x8a4584 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_008a4539; /* jle 0x8a4539 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_008a453e; /* jl 0x8a453e */
L_008a4539:;
    PUSH32(c, 0x008a453eu); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a453e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4559; /* je 0x8a4559 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4559u); f_008a49c0(c); /* call 0x8a49c0 */
L_008a4559:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_008a4579; /* jmp 0x8a4579 */
L_008a4579:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_008a452a; /* jmp 0x8a452a */
L_008a4584:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a455f(CPU *c) { /* PTR_008a455f */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x008a4567u); f_008a4596(c); /* call 0x8a4596 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a4569(CPU *c) { /* PTR_008a4569 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_008a452a(c); return; } /* jmp 0x8a452a */
}

void f_008a4596(CPU *c) { /* FUN_10004596 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_008a45a7; /* je 0x8a45a7 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_008a45a7:;
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a45ac(CPU *c) { /* FUN_100045ac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_008a45ce; /* je 0x8a45ce */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a45cbu); f_008a476c(c); /* call 0x8a476c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_008a45ce:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_008a45da; /* jne 0x8a45da */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_008a45dd; /* jmp 0x8a45dd */
L_008a45da:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_008a45dd:;
    PUSH32(c, 0x008a45e2u); f_008a3b28(c); /* call 0x8a3b28 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a45f3u); f_008a44f8(c); /* call 0x8a44f8 */
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
    PUSH32(c, 0x008a4614u); f_008a4627(c); /* call 0x8a4627 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4622; /* je 0x8a4622 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4622u); f_008a3ae6(c); /* call 0x8a3ae6 */
L_008a4622:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a4627(CPU *c) { /* FUN_10004627 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab6e0u; PUSH32(c, v_); } /* push 0x1000b6e0 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ebx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x2c], ebx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov eax, dword ptr [esi - 4] */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    PUSH32(c, 0x008a4665u); f_008a4a91(c); /* call 0x8a4a91 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x008a4670u); f_008a4a91(c); /* call 0x8a4a91 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x008a467bu); f_008a4a91(c); /* call 0x8a4a91 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x008a4686u); f_008a4a91(c); /* call 0x8a4a91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a46a7u); f_008a3bad(c); /* call 0x8a3bad */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a46bau); f_008a46f4(c); /* call 0x8a46f4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a46bd(CPU *c) { /* PTR_008a46bd */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a46cc(CPU *c) { /* PTR_008a46cc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x008a46d4u); f_008a4742(c); /* call 0x8a4742 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a46d6(CPU *c) { /* PTR_008a46d6 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a46e8u); f_008a3e0e(c); /* call 0x8a3e0e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_008a46bd(c); return; } /* jmp 0x8a46bd */
}

void f_008a46ee(CPU *c) { /* PTR_008a46ee */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_008a46f4(c); return; }
}

void f_008a46f4(CPU *c) { /* FUN_100046f4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x008a46ffu); f_008a4a91(c); /* call 0x8a4a91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x008a470au); f_008a4a91(c); /* call 0x8a4a91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_008a4741; /* jne 0x8a4741 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_008a4741; /* jne 0x8a4741 */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_008a4741; /* jne 0x8a4741 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a4741; /* jne 0x8a4741 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_008a4741; /* je 0x8a4741 */
    PUSH32(c, 0x008a4738u); f_008a3e76(c); /* call 0x8a3e76 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a473fu); f_008a4930(c); /* call 0x8a4930 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4741:;
    c->esp += 4; return; /* ret  */
}

void f_008a4742(CPU *c) { /* FUN_10004742 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_008a4769; /* jne 0x8a4769 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_008a4769; /* jne 0x8a4769 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_008a4769; /* jne 0x8a4769 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_008a4769; /* jne 0x8a4769 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_008a4769:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_008a476c(CPU *c) { /* FUN_1000476c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab6f8u; PUSH32(c, v_); } /* push 0x1000b6f8 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
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
    if (c->zf) goto L_008a4915; /* je 0x8a4915 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_008a4915; /* je 0x8a4915 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4915; /* je 0x8a4915 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_008a4809; /* je 0x8a4809 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x008a47d2u); f_008a621b(c); /* call 0x8a621b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a47e4u); f_008a6237(c); /* call 0x8a6237 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_008a47fa:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4800u); f_008a4997(c); /* call 0x8a4997 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_008a4911; /* jmp 0x8a4911 */
L_008a4809:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_008a4863; /* je 0x8a4863 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x008a481eu); f_008a621b(c); /* call 0x8a621b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4830u); f_008a6237(c); /* call 0x8a6237 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4846u); f_008a63e0(c); /* call 0x8a63e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_008a4911; /* jne 0x8a4911 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4911; /* je 0x8a4911 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_008a47fa; /* jmp 0x8a47fa */
L_008a4863:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_008a48ab; /* jne 0x8a48ab */
    PUSH32(c, 0x008a4876u); f_008a621b(c); /* call 0x8a621b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4888u); f_008a6237(c); /* call 0x8a6237 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x008a489du); f_008a4997(c); /* call 0x8a4997 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a48a6u); f_008a63e0(c); /* call 0x8a63e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_008a4911; /* jmp 0x8a4911 */
L_008a48ab:;
    PUSH32(c, 0x008a48b0u); f_008a621b(c); /* call 0x8a621b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a48beu); f_008a6237(c); /* call 0x8a6237 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x008a48ccu); f_008a6253(c); /* call 0x8a6253 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a490c; /* je 0x8a490c */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_008a48f2; /* je 0x8a48f2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x008a48e4u); f_008a4997(c); /* call 0x8a4997 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a48f0u); f_008a3b21(c); /* call 0x8a3b21 */
    goto L_008a4911; /* jmp 0x8a4911 */
L_008a48f2:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x008a48feu); f_008a4997(c); /* call 0x8a4997 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a490au); f_008a3b1a(c); /* call 0x8a3b1a */
    goto L_008a4911; /* jmp 0x8a4911 */
L_008a490c:;
    PUSH32(c, 0x008a4911u); f_008a4bf9(c); /* call 0x8a4bf9 */
L_008a4911:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_008a4915:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a4924(CPU *c) { /* PTR_008a4924 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_008a4928(CPU *c) { /* PTR_008a4928 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a4930(CPU *c) { /* FUN_10004930 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab708u; PUSH32(c, v_); } /* push 0x1000b708 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
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
    if (c->zf) goto L_008a4977; /* je 0x8a4977 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008a4977; /* je 0x8a4977 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x008a4973u); f_008a3b1a(c); /* call 0x8a3b1a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_008a4977:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a4986(CPU *c) { /* PTR_008a4986 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_008a498f(CPU *c) { /* PTR_008a498f */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a4997(CPU *c) { /* FUN_10004997 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_008a49b8; /* jl 0x8a49b8 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_008a49b8:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a49c0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x008a49e3u); f_008a3e99(c); /* call 0x8a3e99 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a49e7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_008a49ff; /* jne 0x8a49ff */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_008a49ff:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a4a05u); f_008a3e99(c); /* call 0x8a3e99 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a4a0c(CPU *c) { /* FUN_10004a0c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a4a12u); f_008a6852(c); /* call 0x8a6852 */
    { uint32_t t_ = R32((uint32_t)(0x8ab020u)); PUSH32(c, 0x008a4a18u); call_indirect(c, t_); } /* call dword ptr [0x1000b020] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0x8ad240u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000d240], eax */
    if (c->zf) goto L_008a4a5c; /* je 0x8a4a5c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x008a4a2bu); f_008a6715(c); /* call 0x8a6715 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a4a5c; /* je 0x8a4a5c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x8ad240u)); PUSH32(c, v_); } /* push dword ptr [0x1000d240] */
    { uint32_t t_ = R32((uint32_t)(0x8ab01cu)); PUSH32(c, 0x008a4a40u); call_indirect(c, t_); } /* call dword ptr [0x1000b01c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4a5c; /* je 0x8a4a5c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a4a4au); f_008a4a7e(c); /* call 0x8a4a7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x8ab018u)); PUSH32(c, 0x008a4a51u); call_indirect(c, t_); } /* call dword ptr [0x1000b018] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_008a4a5c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a4a60(CPU *c) { /* FUN_10004a60 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x008a4a65u); f_008a687b(c); /* call 0x8a687b */
    c->eax = (uint32_t)(R32((uint32_t)(0x8ad240u))); /* mov eax, dword ptr [0x1000d240] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_008a4a7d; /* je 0x8a4a7d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab024u)); PUSH32(c, 0x008a4a76u); call_indirect(c, t_); } /* call dword ptr [0x1000b024] */
    { uint32_t a_ = (uint32_t)(0x8ad240u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1000d240], 0xffffffff */
L_008a4a7d:;
    c->esp += 4; return; /* ret  */
}

void f_008a4a7e(CPU *c) { /* FUN_10004a7e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x8ad3e0u)); /* mov dword ptr [eax + 0x50], 0x1000d3e0 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_008a4a91(CPU *c) { /* FUN_10004a91 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x8ab030u)); PUSH32(c, 0x008a4a99u); call_indirect(c, t_); } /* call dword ptr [0x1000b030] */
    { uint32_t v_ = R32((uint32_t)(0x8ad240u)); PUSH32(c, v_); } /* push dword ptr [0x1000d240] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab02cu)); PUSH32(c, 0x008a4aa7u); call_indirect(c, t_); } /* call dword ptr [0x1000b02c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_008a4aec; /* jne 0x8a4aec */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x008a4ab6u); f_008a6715(c); /* call 0x8a6715 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a4ae4; /* je 0x8a4ae4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x8ad240u)); PUSH32(c, v_); } /* push dword ptr [0x1000d240] */
    { uint32_t t_ = R32((uint32_t)(0x8ab01cu)); PUSH32(c, 0x008a4acbu); call_indirect(c, t_); } /* call dword ptr [0x1000b01c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4ae4; /* je 0x8a4ae4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a4ad5u); f_008a4a7e(c); /* call 0x8a4a7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x8ab018u)); PUSH32(c, 0x008a4adcu); call_indirect(c, t_); } /* call dword ptr [0x1000b018] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_008a4aec; /* jmp 0x8a4aec */
L_008a4ae4:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x008a4aebu); f_008a4170(c); /* call 0x8a4170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4aec:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x8ab028u)); PUSH32(c, 0x008a4af3u); call_indirect(c, t_); } /* call dword ptr [0x1000b028] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a4af8(CPU *c) { /* FUN_10004af8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8ad240u))); /* mov eax, dword ptr [0x1000d240] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_008a4b97; /* je 0x8a4b97 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_008a4b1c; /* jne 0x8a4b1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab02cu)); PUSH32(c, 0x008a4b16u); call_indirect(c, t_); } /* call dword ptr [0x1000b02c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a4b88; /* je 0x8a4b88 */
L_008a4b1c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4b2a; /* je 0x8a4b2a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b29u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b2a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4b38; /* je 0x8a4b38 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b37u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b38:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4b46; /* je 0x8a4b46 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b45u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b46:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4b54; /* je 0x8a4b54 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b53u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b54:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4b62; /* je 0x8a4b62 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b61u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b62:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4b70; /* je 0x8a4b70 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b6fu); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b70:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0x8ad3e0u); /* cmp eax, 0x1000d3e0 */
    if (c->zf) goto L_008a4b81; /* je 0x8a4b81 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4b80u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b81:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a4b87u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4b88:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8ad240u)); PUSH32(c, v_); } /* push dword ptr [0x1000d240] */
    { uint32_t t_ = R32((uint32_t)(0x8ab01cu)); PUSH32(c, 0x008a4b96u); call_indirect(c, t_); } /* call dword ptr [0x1000b01c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a4b97:;
    c->esp += 4; return; /* ret  */
}

void f_008a4b98(CPU *c) { /* FUN_10004b98 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab718u; PUSH32(c, v_); } /* push 0x1000b718 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x18], esp */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    PUSH32(c, 0x008a4bc7u); f_008a4a91(c); /* call 0x8a4a91 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_008a4beb; /* je 0x8a4beb */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x008a4bd8u); f_008a4a91(c); /* call 0x8a4a91 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x008a4bdbu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_008a4beb; /* jmp 0x8a4beb */
L_008a4beb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a4bf4u); f_008a4bf4(c); /* call 0x8a4bf4 */
    { f_008a6a46(c); return; } /* jmp 0x8a6a46 */
}

void f_008a4be0(CPU *c) { /* PTR_008a4be0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_008a4be4(CPU *c) { /* PTR_008a4be4 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a4bf4u); f_008a4bf4(c); /* call 0x8a4bf4 */
    { f_008a6a46(c); return; } /* jmp 0x8a6a46 */
}

void f_008a4bf4(CPU *c) { /* PTR_008a4bf4 */
    PREEMPT_POLL(c);
    { f_008a6a46(c); return; } /* jmp 0x8a6a46 */
}

void f_008a4bf9(CPU *c) { /* FUN_10004bf9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab730u; PUSH32(c, v_); } /* push 0x1000b730 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x8ad244u))); /* mov eax, dword ptr [0x1000d244] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4c41; /* je 0x8a4c41 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a4c34u); call_indirect(c, t_); } /* call eax */
    goto L_008a4c3d; /* jmp 0x8a4c3d */
L_008a4c3d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_008a4c41:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a4c4au); f_008a4c4a(c); /* call 0x8a4c4a */
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a4c36(CPU *c) { /* PTR_008a4c36 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_008a4c3a(CPU *c) { /* PTR_008a4c3a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a4c4au); f_008a4c4a(c); /* call 0x8a4c4a */
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a4c4a(CPU *c) { /* PTR_008a4c4a */
    PREEMPT_POLL(c);
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
}

void f_008a4c4f(CPU *c) { /* FUN_10004c4f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x008a4c5eu); f_008a6a92(c); /* call 0x8a6a92 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a4c61(CPU *c) { /* FUN_10004c61 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x8ab758u))); /* fld qword ptr [0x1000b758] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x8ab750u))); /* fld qword ptr [0x1000b750] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x8ab748u))); FPOP(c); /* fcomp qword ptr [0x1000b748] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_008a4c9b; /* jbe 0x8a4c9b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a4c9b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a4c9f(CPU *c) { /* FUN_10004c9f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x8ab77cu; PUSH32(c, v_); } /* push 0x1000b77c */
    { uint32_t t_ = R32((uint32_t)(0x8ab038u)); PUSH32(c, 0x008a4caau); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4cc3; /* je 0x8a4cc3 */
    { uint32_t v_ = 0x8ab760u; PUSH32(c, v_); } /* push 0x1000b760 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab034u)); PUSH32(c, 0x008a4cbau); call_indirect(c, t_); } /* call dword ptr [0x1000b034] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a4cc3; /* je 0x8a4cc3 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a4cc2u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_008a4cc3:;
    { f_008a4c61(c); return; } /* jmp 0x8a4c61 */
}

void f_008a4cc8(CPU *c) { /* FUN_10004cc8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4cd6u); f_008a6c38(c); /* call 0x8a6c38 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a4d08; /* je 0x8a4d08 */
L_008a4cdc:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x8ad468u)), (uint32_t)0x1u); /* cmp dword ptr [0x1000d468], 1 */
    if ((c->zf || c->sf != c->of)) goto L_008a4cf5; /* jle 0x8a4cf5 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4cf1u); f_008a6bc3(c); /* call 0x8a6bc3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_008a4d04; /* jmp 0x8a4d04 */
L_008a4cf5:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8ad474u))); /* mov ecx, dword ptr [0x1000d474] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_008a4d04:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a4cdc; /* jne 0x8a4cdc */
L_008a4d08:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x8ad46cu))); /* mov cl, byte ptr [0x1000d46c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_008a4d13:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_008a4d13; /* jne 0x8a4d13 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a4d22(CPU *c) { /* PTR_008a4d22 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x8ad46cu))); /* mov dl, byte ptr [0x1000d46c] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_008a4d3e; /* je 0x8a4d3e */
L_008a4d32:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_008a4d3e; /* je 0x8a4d3e */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_008a4d32; /* jne 0x8a4d32 */
L_008a4d3e:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_008a4d6f; /* je 0x8a4d6f */
L_008a4d45:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_008a4d58; /* je 0x8a4d58 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_008a4d58; /* je 0x8a4d58 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_008a4d58; /* je 0x8a4d58 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_008a4d45; /* jmp 0x8a4d45 */
L_008a4d58:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_008a4d5a:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_008a4d5a; /* je 0x8a4d5a */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_008a4d65; /* jne 0x8a4d65 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_008a4d65:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_008a4d65; /* jne 0x8a4d65 */
L_008a4d6f:;
    c->esp += 4; return; /* ret  */
}

void f_008a4d70(CPU *c) { /* PTR_008a4d70 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x8ab788u))); FPOP(c); /* fcomp qword ptr [0x1000b788] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_008a4d85; /* jb 0x8a4d85 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_008a4d85:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_008a4d88(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_008a4db1; /* je 0x8a4db1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4d9fu); f_008a7104(c); /* call 0x8a7104 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a4db1:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4dbau); f_008a7131(c); /* call 0x8a7131 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a4dc6(CPU *c) { /* FUN_10004dc6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x008a4de4u); f_008a71d5(c); /* call 0x8a71d5 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x2du); /* cmp dword ptr [ebp - 0x10], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg cl */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a4e0cu); f_008a715e(c); /* call 0x8a715e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a4e1eu); f_008a4e27(c); /* call 0x8a4e27 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a4e27(CPU *c) { /* FUN_10004e27 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    if (c->zf) goto L_008a4e55; /* je 0x8a4e55 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4e53u); f_008a50c9(c); /* call 0x8a50c9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a4e55:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_008a4e62; /* jne 0x8a4e62 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_008a4e62:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_008a4e79; /* jle 0x8a4e79 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x8ad46cu))); /* mov cl, byte ptr [0x1000d46c] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_008a4e79:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0x8ab790u; PUSH32(c, v_); } /* push 0x1000b790 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x008a4e91u); f_008a72f0(c); /* call 0x8a72f0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_008a4e9d; /* je 0x8a4e9d */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_008a4e9d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_008a4ee2; /* je 0x8a4ee2 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_008a4eb1; /* jns 0x8a4eb1 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_008a4eb1:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_008a4ec8; /* jl 0x8a4ec8 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x008a4ebdu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x008a4ec4u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_008a4ec8:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_008a4edf; /* jl 0x8a4edf */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x008a4ed4u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x008a4edbu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_008a4edf:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_008a4ee2:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a4ee9(CPU *c) { /* FUN_10004ee9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x008a4f07u); f_008a71d5(c); /* call 0x8a71d5 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x2du); /* cmp dword ptr [ebp - 0x10], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu)))); /* add eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a4f26u); f_008a715e(c); /* call 0x8a715e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a4f35u); f_008a4f3e(c); /* call 0x8a4f3e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a4f3e(CPU *c) { /* FUN_10004f3e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov esi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_008a4f6e; /* je 0x8a4f6e */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_008a4f6e; /* jne 0x8a4f6e */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_008a4f6e:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_008a4f7b; /* jne 0x8a4f7b */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_008a4f7b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_008a4f92; /* jg 0x8a4f92 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4f8au); f_008a50c9(c); /* call 0x8a50c9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_008a4f94; /* jmp 0x8a4f94 */
L_008a4f92:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_008a4f94:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_008a4fde; /* jle 0x8a4fde */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4fa2u); f_008a50c9(c); /* call 0x8a50c9 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x8ad46cu))); /* mov al, byte ptr [0x1000d46c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_008a4fde; /* jge 0x8a4fde */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_008a4fbd; /* je 0x8a4fbd */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_008a4fc4; /* jmp 0x8a4fc4 */
L_008a4fbd:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_008a4fc7; /* jl 0x8a4fc7 */
L_008a4fc4:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008a4fc7:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4fd0u); f_008a50c9(c); /* call 0x8a50c9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a4fdbu); f_008a73e0(c); /* call 0x8a73e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_008a4fde:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a4fe5(CPU *c) { /* FUN_10004fe5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x008a5005u); f_008a71d5(c); /* call 0x8a71d5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ebx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea esi, [eax - 1] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x2du); /* cmp dword ptr [ebp - 0x10], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu)))); /* add eax, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a5027u); f_008a715e(c); /* call 0x8a715e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_008a505e; /* jl 0x8a505e */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_008a505e; /* jge 0x8a505e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_008a504a; /* je 0x8a504a */
L_008a5040:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_008a5040; /* jne 0x8a5040 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_008a504a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a5059u); f_008a4f3e(c); /* call 0x8a4f3e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_008a5073; /* jmp 0x8a5073 */
L_008a505e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a5070u); f_008a4e27(c); /* call 0x8a4e27 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_008a5073:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5078(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_008a50b3; /* je 0x8a50b3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_008a50b3; /* je 0x8a50b3 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_008a50a0; /* jne 0x8a50a0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a509bu); f_008a4ee9(c); /* call 0x8a4ee9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_008a50a0:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a50b1u); f_008a4fe5(c); /* call 0x8a4fe5 */
    goto L_008a50c4; /* jmp 0x8a50c4 */
L_008a50b3:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a50c4u); f_008a4dc6(c); /* call 0x8a4dc6 */
L_008a50c4:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a50c9(CPU *c) { /* FUN_100050c9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a50ec; /* je 0x8a50ec */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a50ddu); f_008a7440(c); /* call 0x8a7440 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a50e8u); f_008a63e0(c); /* call 0x8a63e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a50ec:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_008a50ee(CPU *c) { /* FUN_100050ee */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8ad220u))); /* mov eax, dword ptr [0x1000d220] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a50f9; /* je 0x8a50f9 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a50f9u); call_indirect(c, t_); } /* call eax */
L_008a50f9:;
    { uint32_t v_ = 0x8ad01cu; PUSH32(c, v_); } /* push 0x1000d01c */
    { uint32_t v_ = 0x8ad00cu; PUSH32(c, v_); } /* push 0x1000d00c */
    PUSH32(c, 0x008a5108u); f_008a51f2(c); /* call 0x8a51f2 */
    { uint32_t v_ = 0x8ad008u; PUSH32(c, v_); } /* push 0x1000d008 */
    { uint32_t v_ = 0x8ad000u; PUSH32(c, v_); } /* push 0x1000d000 */
    PUSH32(c, 0x008a5117u); f_008a51f2(c); /* call 0x8a51f2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_008a511b(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x008a5128u); f_008a513b(c); /* call 0x8a513b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008a512c(CPU *c) { /* FUN_1000512c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x008a5137u); f_008a513b(c); /* call 0x8a513b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_008a513b(CPU *c) { /* FUN_1000513b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a5141u); f_008a51e0(c); /* call 0x8a51e0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x8affd0u)), c->edi); /* cmp dword ptr [0x1000ffd0], edi */
    if (!c->zf) goto L_008a515d; /* jne 0x8a515d */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x8ab044u)); PUSH32(c, 0x008a5156u); call_indirect(c, t_); } /* call dword ptr [0x1000b044] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab040u)); PUSH32(c, 0x008a515du); call_indirect(c, t_); } /* call dword ptr [0x1000b040] */
L_008a515d:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x8affccu), (uint32_t)(c->edi)); /* mov dword ptr [0x1000ffcc], edi */
    W8((uint32_t)(0x8affc8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x1000ffc8], bl */
    if (!c->zf) goto L_008a51b1; /* jne 0x8a51b1 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0670u))); /* mov eax, dword ptr [0x10010670] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a51a0; /* je 0x8a51a0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x8b066cu))); /* mov ecx, dword ptr [0x1001066c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_008a519f; /* jb 0x8a519f */
L_008a518c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5194; /* je 0x8a5194 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a5194u); call_indirect(c, t_); } /* call eax */
L_008a5194:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8b0670u))); /* cmp esi, dword ptr [0x10010670] */
    if (!c->cf) goto L_008a518c; /* jae 0x8a518c */
L_008a519f:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a51a0:;
    { uint32_t v_ = 0x8ad024u; PUSH32(c, v_); } /* push 0x1000d024 */
    { uint32_t v_ = 0x8ad020u; PUSH32(c, v_); } /* push 0x1000d020 */
    PUSH32(c, 0x008a51afu); f_008a51f2(c); /* call 0x8a51f2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a51b1:;
    { uint32_t v_ = 0x8ad030u; PUSH32(c, v_); } /* push 0x1000d030 */
    { uint32_t v_ = 0x8ad028u; PUSH32(c, v_); } /* push 0x1000d028 */
    PUSH32(c, 0x008a51c0u); f_008a51f2(c); /* call 0x8a51f2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_008a51ce; /* je 0x8a51ce */
    PUSH32(c, 0x008a51ccu); f_008a51e9(c); /* call 0x8a51e9 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_008a51ce:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x8affd0u), (uint32_t)(c->edi)); /* mov dword ptr [0x1000ffd0], edi */
    { uint32_t t_ = R32((uint32_t)(0x8ab03cu)); PUSH32(c, 0x008a51deu); call_indirect(c, t_); } /* call dword ptr [0x1000b03c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_008a51de(CPU *c) { /* PTR_008a51de */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_008a51e0(CPU *c) { /* FUN_100051e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x008a51e7u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a51e9(CPU *c) { /* FUN_100051e9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x008a51f0u); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a51f2(CPU *c) { /* FUN_100051f2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_008a51f7:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_008a520a; /* jae 0x8a520a */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5205; /* je 0x8a5205 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a5205u); call_indirect(c, t_); } /* call eax */
L_008a5205:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_008a51f7; /* jmp 0x8a51f7 */
L_008a520a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a520c(CPU *c) { /* FUN_1000520c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab798u; PUSH32(c, v_); } /* push 0x1000b798 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (!c->zf) goto L_008a5246; /* jne 0x8a5246 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x008a5240u); f_008a5629(c); /* call 0x8a5629 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_008a552c; /* jmp 0x8a552c */
L_008a5246:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008a5259; /* jne 0x8a5259 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5253u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_008a552a; /* jmp 0x8a552a */
L_008a5259:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0548u))); /* mov eax, dword ptr [0x10010548] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_008a53a0; /* jne 0x8a53a0 */
L_008a5267:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a5364; /* ja 0x8a5364 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a527au); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5284u); f_008a750c(c); /* call 0x8a750c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_008a5334; /* je 0x8a5334 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8b0540u))); /* cmp esi, dword ptr [0x10010540] */
    if ((!c->cf && !c->zf)) goto L_008a52e4; /* ja 0x8a52e4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a52a0u); f_008a7d15(c); /* call 0x8a7d15 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a52ac; /* je 0x8a52ac */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_008a52e4; /* jmp 0x8a52e4 */
L_008a52ac:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a52b2u); f_008a7860(c); /* call 0x8a7860 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_008a52e4; /* je 0x8a52e4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a52c7; /* jb 0x8a52c7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a52c7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a52d1u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a52d7u); f_008a750c(c); /* call 0x8a750c */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a52e1u); f_008a7537(c); /* call 0x8a7537 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a52e4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_008a5334; /* jne 0x8a5334 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008a52f3; /* jne 0x8a52f3 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008a52f3:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a530au); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_008a5334; /* je 0x8a5334 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a531e; /* jb 0x8a531e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a531e:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5328u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x008a5331u); f_008a7537(c); /* call 0x8a7537 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_008a5334:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a533du); f_008a5397(c); /* call 0x8a5397 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_008a5364; /* jne 0x8a5364 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008a5349; /* jne 0x8a5349 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a5349:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a5361u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_008a5364:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008a552c; /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) goto L_008a552c; /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a5381u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5267; /* jne 0x8a5267 */
    goto L_008a552a; /* jmp 0x8a552a */
L_008a53a0:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a54f0; /* jne 0x8a54f0 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a53c0; /* ja 0x8a53c0 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_008a53ba; /* jbe 0x8a53ba */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_008a53bd; /* jmp 0x8a53bd */
L_008a53ba:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a53bd:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008a53c0:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a54bf; /* ja 0x8a54bf */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a53d3u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a53e9u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a54a3; /* je 0x8a54a3 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if (!c->cf) goto L_008a545d; /* jae 0x8a545d */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5413u); f_008a862f(c); /* call 0x8a862f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5422; /* je 0x8a5422 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_008a545a; /* jmp 0x8a545a */
L_008a5422:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5428u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a545a; /* je 0x8a545a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a543f; /* jb 0x8a543f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a543f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a545a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_008a545d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54a3:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a54b3u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
L_008a54bf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008a552c; /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) goto L_008a552c; /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a53c0; /* jne 0x8a53c0 */
    goto L_008a552a; /* jmp 0x8a552a */
L_008a54f0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a5513; /* ja 0x8a5513 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008a54fe; /* jne 0x8a54fe */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a54fe:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a5513u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
L_008a5513:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008a552c; /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) goto L_008a552c; /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a5525u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a54f0; /* jne 0x8a54f0 */
L_008a552a:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a552c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a538f(CPU *c) { /* PTR_008a538f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_008a5397(c); return; }
}

void f_008a5397(CPU *c) { /* FUN_10005397 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a539eu); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a53a0(CPU *c) { /* PTR_008a53a0 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_008a54f0(c); return; } /* jne 0x8a54f0 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a53c0; /* ja 0x8a53c0 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_008a53ba; /* jbe 0x8a53ba */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_008a53bd; /* jmp 0x8a53bd */
L_008a53ba:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a53bd:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008a53c0:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a54bf; /* ja 0x8a54bf */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a53d3u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a53e9u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a54a3; /* je 0x8a54a3 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if (!c->cf) goto L_008a545d; /* jae 0x8a545d */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5413u); f_008a862f(c); /* call 0x8a862f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5422; /* je 0x8a5422 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_008a545a; /* jmp 0x8a545a */
L_008a5422:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5428u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a545a; /* je 0x8a545a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a543f; /* jb 0x8a543f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a543f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a545a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_008a545d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54a3:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a54b3u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
L_008a54bf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a53c0; /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a53ba(CPU *c) { /* PTR_008a53ba */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008a53c0:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a54bf; /* ja 0x8a54bf */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a53d3u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a53e9u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a54a3; /* je 0x8a54a3 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if (!c->cf) goto L_008a545d; /* jae 0x8a545d */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5413u); f_008a862f(c); /* call 0x8a862f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5422; /* je 0x8a5422 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_008a545a; /* jmp 0x8a545a */
L_008a5422:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5428u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a545a; /* je 0x8a545a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a543f; /* jb 0x8a543f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a543f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a545a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_008a545d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54a3:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a54b3u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
L_008a54bf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a53c0; /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a53bd(CPU *c) { /* PTR_008a53bd */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_008a53c0:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a54bf; /* ja 0x8a54bf */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a53d3u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a53e9u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a54a3; /* je 0x8a54a3 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if (!c->cf) goto L_008a545d; /* jae 0x8a545d */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5413u); f_008a862f(c); /* call 0x8a862f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5422; /* je 0x8a5422 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_008a545a; /* jmp 0x8a545a */
L_008a5422:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5428u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a545a; /* je 0x8a545a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a543f; /* jb 0x8a543f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a543f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a545a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_008a545d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54a3:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a54b3u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
L_008a54bf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a53c0; /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a53c0(CPU *c) { /* PTR_008a53c0 */
    PREEMPT_POLL(c);
L_008a53c0:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a54bf; /* ja 0x8a54bf */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a53d3u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a53e9u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a54a3; /* je 0x8a54a3 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if (!c->cf) goto L_008a545d; /* jae 0x8a545d */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5413u); f_008a862f(c); /* call 0x8a862f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5422; /* je 0x8a5422 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_008a545a; /* jmp 0x8a545a */
L_008a5422:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5428u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a545a; /* je 0x8a545a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a543f; /* jb 0x8a543f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a543f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a545a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_008a545d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54a3:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a54b3u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
L_008a54bf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a53c0; /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a5422(CPU *c) { /* PTR_008a5422 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a5428u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a545a; /* je 0x8a545a */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a543f; /* jb 0x8a543f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a543f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_008a545a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a543f(CPU *c) { /* PTR_008a543f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a544bu); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a5457u); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a545a(CPU *c) { /* PTR_008a545a */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a545d(CPU *c) { /* PTR_008a545d */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_008a54b6; /* jne 0x8a54b6 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5472u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a54b6; /* je 0x8a54b6 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_008a5488; /* jb 0x8a5488 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_008a5488:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a5488(CPU *c) { /* PTR_008a5488 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x008a5492u); f_008a8700(c); /* call 0x8a8700 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x008a549eu); f_008a82be(c); /* call 0x8a82be */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_008a54b6; /* jmp 0x8a54b6 */
L_008a54b6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a54a3(CPU *c) { /* PTR_008a54a3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a54b3u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a54b6(CPU *c) { /* PTR_008a54b6 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a54bfu); f_008a54e5(c); /* call 0x8a54e5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a54bf(CPU *c) { /* PTR_008a54bf */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_008a552c(c); return; } /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) { f_008a552c(c); return; } /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a54d4u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a53c0(c); return; } /* jne 0x8a53c0 */
    { f_008a552a(c); return; } /* jmp 0x8a552a */
}

void f_008a54df(CPU *c) { /* PTR_008a54df */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_008a54e5(c); return; }
}

void f_008a54e5(CPU *c) { /* FUN_100054e5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a54ecu); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_008a54f0(CPU *c) { /* PTR_008a54f0 */
    PREEMPT_POLL(c);
L_008a54f0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a5513; /* ja 0x8a5513 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008a54fe; /* jne 0x8a54fe */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a54fe:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a5513u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
L_008a5513:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008a552c; /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) goto L_008a552c; /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a5525u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a54f0; /* jne 0x8a54f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a552c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a54fe(CPU *c) { /* PTR_008a54fe */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab048u)); PUSH32(c, 0x008a5513u); call_indirect(c, t_); } /* call dword ptr [0x1000b048] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008a552c; /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) goto L_008a552c; /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a5525u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a54f0(c); return; } /* jne 0x8a54f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a552c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5513(CPU *c) { /* PTR_008a5513 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_008a552c; /* jne 0x8a552c */
    (void)sub32(c, R32((uint32_t)(0x8b0150u)), c->edi); /* cmp dword ptr [0x10010150], edi */
    if (c->zf) goto L_008a552c; /* je 0x8a552c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a5525u); f_008a86d8(c); /* call 0x8a86d8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a54f0(c); return; } /* jne 0x8a54f0 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a552c:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a552a(CPU *c) { /* PTR_008a552a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a552c(CPU *c) { /* PTR_008a552c */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a553b(CPU *c) { /* FUN_1000553b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab7b0u; PUSH32(c, v_); } /* push 0x1000b7b0 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0548u))); /* mov eax, dword ptr [0x10010548] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_008a55ae; /* jne 0x8a55ae */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a556fu); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a557du); f_008a750c(c); /* call 0x8a750c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5590; /* je 0x8a5590 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_008a5593; /* jmp 0x8a5593 */
L_008a5590:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_008a5593:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a559cu); f_008a55a5(c); /* call 0x8a55a5 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_008a55f7; /* jmp 0x8a55f7 */
L_008a55ae:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a55f9; /* jne 0x8a55f9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a55bau); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a55d2u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a55e7; /* je 0x8a55e7 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_008a55ea; /* jmp 0x8a55ea */
L_008a55e7:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_008a55ea:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a55f3u); f_008a5620(c); /* call 0x8a5620 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_008a55f7:;
    if (!c->zf) goto L_008a560c; /* jne 0x8a560c */
L_008a55f9:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab050u)); PUSH32(c, 0x008a560au); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a560c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a55a2(CPU *c) { /* PTR_008a55a2 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_008a55a5(c); return; }
}

void f_008a55a5(CPU *c) { /* FUN_100055a5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a55acu); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a55ae(CPU *c) { /* PTR_008a55ae */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a55f9; /* jne 0x8a55f9 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a55bau); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x008a55d2u); f_008a8267(c); /* call 0x8a8267 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a55e7; /* je 0x8a55e7 */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_008a55ea; /* jmp 0x8a55ea */
L_008a55e7:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_008a55ea:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a55f3u); f_008a5620(c); /* call 0x8a5620 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_008a560c; /* jne 0x8a560c */
L_008a55f9:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab050u)); PUSH32(c, 0x008a560au); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a560c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a55e7(CPU *c) { /* PTR_008a55e7 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a55f3u); f_008a5620(c); /* call 0x8a5620 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_008a560c; /* jne 0x8a560c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab050u)); PUSH32(c, 0x008a560au); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a560c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a55ea(CPU *c) { /* PTR_008a55ea */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a55f3u); f_008a5620(c); /* call 0x8a5620 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_008a560c; /* jne 0x8a560c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab050u)); PUSH32(c, 0x008a560au); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a560c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a55f7(CPU *c) { /* PTR_008a55f7 */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_008a560c; /* jne 0x8a560c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab050u)); PUSH32(c, 0x008a560au); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_008a560c:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a55f9(CPU *c) { /* PTR_008a55f9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab050u)); PUSH32(c, 0x008a560au); call_indirect(c, t_); } /* call dword ptr [0x1000b050] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a560c(CPU *c) { /* PTR_008a560c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a561d(CPU *c) { /* PTR_008a561d */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_008a5620(c); return; }
}

void f_008a5620(CPU *c) { /* FUN_10005620 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a5627u); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a5629(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x8b0150u)); PUSH32(c, v_); } /* push dword ptr [0x10010150] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x008a5638u); f_008a563b(c); /* call 0x8a563b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a563b(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_008a5664; /* ja 0x8a5664 */
L_008a5642:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x008a564bu); f_008a5667(c); /* call 0x8a5667 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_008a5666; /* jne 0x8a5666 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_008a5666; /* je 0x8a5666 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x008a565fu); f_008a86d8(c); /* call 0x8a86d8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_008a5642; /* jne 0x8a5642 */
L_008a5664:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a5666:;
    c->esp += 4; return; /* ret  */
}

void f_008a5667(CPU *c) { /* FUN_10005667 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x8ab7c8u; PUSH32(c, v_); } /* push 0x1000b7c8 */
    { uint32_t v_ = 0x8a62fcu; PUSH32(c, v_); } /* push 0x100062fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0548u))); /* mov eax, dword ptr [0x10010548] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_008a56d7; /* jne 0x8a56d7 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8b0540u))); /* cmp esi, dword ptr [0x10010540] */
    if ((!c->cf && !c->zf)) goto L_008a5736; /* ja 0x8a5736 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a56aau); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a56b5u); f_008a7860(c); /* call 0x8a7860 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a56c2u); f_008a56ce(c); /* call 0x8a56ce */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5736; /* je 0x8a5736 */
    goto L_008a5754; /* jmp 0x8a5754 */
L_008a56d7:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a5736; /* jne 0x8a5736 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a56eb; /* je 0x8a56eb */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_008a56ee; /* jmp 0x8a56ee */
L_008a56eb:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a56ee:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if ((!c->cf && !c->zf)) goto L_008a5727; /* ja 0x8a5727 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a5700u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5713u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a5720u); f_008a572d(c); /* call 0x8a572d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5754; /* jne 0x8a5754 */
L_008a5727:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_008a5746; /* jmp 0x8a5746 */
L_008a5736:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5740; /* jne 0x8a5740 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_008a5740:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_008a5746:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5754u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
L_008a5754:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a56ce(CPU *c) { /* FUN_100056ce */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a56d5u); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a56d7(CPU *c) { /* PTR_008a56d7 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_008a5736(c); return; } /* jne 0x8a5736 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a56eb; /* je 0x8a56eb */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_008a56ee; /* jmp 0x8a56ee */
L_008a56eb:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_008a56ee:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if ((!c->cf && !c->zf)) goto L_008a5727; /* ja 0x8a5727 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a5700u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5713u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a5720u); f_008a572d(c); /* call 0x8a572d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a5754(c); return; } /* jne 0x8a5754 */
L_008a5727:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_008a5746(c); return; } /* jmp 0x8a5746 */
}

void f_008a56eb(CPU *c) { /* PTR_008a56eb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if ((!c->cf && !c->zf)) goto L_008a5727; /* ja 0x8a5727 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a5700u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5713u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a5720u); f_008a572d(c); /* call 0x8a572d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a5754(c); return; } /* jne 0x8a5754 */
L_008a5727:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_008a5746(c); return; } /* jmp 0x8a5746 */
}

void f_008a56ee(CPU *c) { /* PTR_008a56ee */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x8af6d4u))); /* cmp esi, dword ptr [0x1000f6d4] */
    if ((!c->cf && !c->zf)) goto L_008a5727; /* ja 0x8a5727 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a5700u); f_008a68e7(c); /* call 0x8a68e7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5713u); f_008a8303(c); /* call 0x8a8303 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x008a5720u); f_008a572d(c); /* call 0x8a572d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_008a5754(c); return; } /* jne 0x8a5754 */
L_008a5727:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_008a5746(c); return; } /* jmp 0x8a5746 */
}

void f_008a5727(CPU *c) { /* PTR_008a5727 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_008a5746(c); return; } /* jmp 0x8a5746 */
}

void f_008a572a(CPU *c) { /* PTR_008a572a */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_008a572d(c); return; }
}

void f_008a572d(CPU *c) { /* FUN_1000572d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a5734u); f_008a6948(c); /* call 0x8a6948 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a5736(CPU *c) { /* PTR_008a5736 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5740; /* jne 0x8a5740 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_008a5740:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5754u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5740(CPU *c) { /* PTR_008a5740 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5754u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5746(CPU *c) { /* PTR_008a5746 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab04cu)); PUSH32(c, 0x008a5754u); call_indirect(c, t_); } /* call dword ptr [0x1000b04c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5754(CPU *c) { /* PTR_008a5754 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5763(CPU *c) { /* FUN_10005763 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x008a5776u); f_008a5629(c); /* call 0x8a5629 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_008a5785; /* jne 0x8a5785 */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x008a5784u); f_008a4170(c); /* call 0x8a4170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a5785:;
    W32((uint32_t)(0x8b0560u), (uint32_t)(c->esi)); /* mov dword ptr [0x10010560], esi */
    W32((uint32_t)(0x8b0660u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x10010660], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_008a579b:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_008a57bd; /* jae 0x8a57bd */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0560u))); /* mov eax, dword ptr [0x10010560] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_008a579b; /* jmp 0x8a579b */
L_008a57bd:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab060u)); PUSH32(c, 0x008a57c7u); call_indirect(c, t_); } /* call dword ptr [0x1000b060] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_008a58a3; /* je 0x8a58a3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a58a3; /* je 0x8a58a3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_008a57f3; /* jl 0x8a57f3 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_008a57f3:;
    (void)sub32(c, R32((uint32_t)(0x8b0660u)), c->edi); /* cmp dword ptr [0x10010660], edi */
    if ((c->sf == c->of)) goto L_008a5851; /* jge 0x8a5851 */
    c->esi = (uint32_t)((uint32_t)0x8b0564u); /* mov esi, 0x10010564 */
L_008a5800:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x008a580au); f_008a5629(c); /* call 0x8a5629 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a584b; /* je 0x8a584b */
    { uint32_t a_ = (uint32_t)(0x8b0660u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x10010660], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_008a581e:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_008a583e; /* jae 0x8a583e */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_008a581e; /* jmp 0x8a581e */
L_008a583e:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0x8b0660u)), c->edi); /* cmp dword ptr [0x10010660], edi */
    if ((c->sf != c->of)) goto L_008a5800; /* jl 0x8a5800 */
    goto L_008a5851; /* jmp 0x8a5851 */
L_008a584b:;
    c->edi = (uint32_t)(R32((uint32_t)(0x8b0660u))); /* mov edi, dword ptr [0x10010660] */
L_008a5851:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_008a58a3; /* jle 0x8a58a3 */
L_008a5857:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_008a5899; /* je 0x8a5899 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_008a5899; /* je 0x8a5899 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_008a5876; /* jne 0x8a5876 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0x8ab05cu)); PUSH32(c, 0x008a5872u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5899; /* je 0x8a5899 */
L_008a5876:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x8b0560u))); /* mov ecx, dword ptr [ecx*4 + 0x10010560] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_008a5899:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_008a5857; /* jl 0x8a5857 */
L_008a58a3:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_008a58a5:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x8b0560u))); /* mov ecx, dword ptr [0x10010560] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_008a5904; /* jne 0x8a5904 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_008a58c4; /* jne 0x8a58c4 */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_008a58ce; /* jmp 0x8a58ce */
L_008a58c4:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_008a58ce:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab058u)); PUSH32(c, 0x008a58d5u); call_indirect(c, t_); } /* call dword ptr [0x1000b058] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_008a58f3; /* je 0x8a58f3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x8ab05cu)); PUSH32(c, 0x008a58e3u); call_indirect(c, t_); } /* call dword ptr [0x1000b05c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a58f3; /* je 0x8a58f3 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a58f9; /* jne 0x8a58f9 */
L_008a58f3:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_008a5908; /* jmp 0x8a5908 */
L_008a58f9:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_008a5908; /* jne 0x8a5908 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_008a5908; /* jmp 0x8a5908 */
L_008a5904:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_008a5908:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_008a58a5; /* jl 0x8a58a5 */
    { uint32_t v_ = R32((uint32_t)(0x8b0660u)); PUSH32(c, v_); } /* push dword ptr [0x10010660] */
    { uint32_t t_ = R32((uint32_t)(0x8ab054u)); PUSH32(c, 0x008a591au); call_indirect(c, t_); } /* call dword ptr [0x1000b054] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a591f(CPU *c) { /* FUN_1000591f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0x8b0560u); /* mov esi, 0x10010560 */
L_008a5927:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5964; /* je 0x8a5964 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_008a5959; /* jae 0x8a5959 */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_008a593b:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_008a5948; /* je 0x8a5948 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x8ab064u)); PUSH32(c, 0x008a5948u); call_indirect(c, t_); } /* call dword ptr [0x1000b064] */
L_008a5948:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_008a593b; /* jb 0x8a593b */
L_008a5959:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x008a5960u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a5964:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x8b0660u); /* cmp esi, 0x10010660 */
    if ((c->sf != c->of)) goto L_008a5927; /* jl 0x8a5927 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_008a5973(CPU *c) { /* FUN_10005973 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x8b0668u)), c->ebx); /* cmp dword ptr [0x10010668], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_008a5985; /* jne 0x8a5985 */
    PUSH32(c, 0x008a5985u); f_008a8e0d(c); /* call 0x8a8e0d */
L_008a5985:;
    c->esi = (uint32_t)(R32((uint32_t)(0x8aff80u))); /* mov esi, dword ptr [0x1000ff80] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_008a598d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_008a59a5; /* je 0x8a59a5 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_008a5998; /* je 0x8a5998 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_008a5998:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a599eu); f_008a7440(c); /* call 0x8a7440 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_008a598d; /* jmp 0x8a598d */
L_008a59a5:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a59b2u); f_008a5629(c); /* call 0x8a5629 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0x8affb0u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ffb0], esi */
    if (!c->zf) goto L_008a59c7; /* jne 0x8a59c7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a59c6u); f_008a4170(c); /* call 0x8a4170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a59c7:;
    c->edi = (uint32_t)(R32((uint32_t)(0x8aff80u))); /* mov edi, dword ptr [0x1000ff80] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_008a5a0a; /* je 0x8a5a0a */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_008a59d2:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a59d8u); f_008a7440(c); /* call 0x8a7440 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_008a5a03; /* je 0x8a5a03 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x008a59e7u); f_008a5629(c); /* call 0x8a5629 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_008a59f6; /* jne 0x8a59f6 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x008a59f5u); f_008a4170(c); /* call 0x8a4170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a59f6:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x008a59feu); f_008a72f0(c); /* call 0x8a72f0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a5a03:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_008a59d2; /* jne 0x8a59d2 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_008a5a0a:;
    { uint32_t v_ = R32((uint32_t)(0x8aff80u)); PUSH32(c, v_); } /* push dword ptr [0x1000ff80] */
    PUSH32(c, 0x008a5a15u); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x8aff80u), (uint32_t)(c->ebx)); /* mov dword ptr [0x1000ff80], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x8b0664u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10010664], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_008a5a2c(CPU *c) { /* FUN_10005a2c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x8b0668u)), c->ebx); /* cmp dword ptr [0x10010668], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_008a5a43; /* jne 0x8a5a43 */
    PUSH32(c, 0x008a5a43u); f_008a8e0d(c); /* call 0x8a8e0d */
L_008a5a43:;
    c->esi = (uint32_t)((uint32_t)0x8affd4u); /* mov esi, 0x1000ffd4 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x8ab068u)); PUSH32(c, 0x008a5a55u); call_indirect(c, t_); } /* call dword ptr [0x1000b068] */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0674u))); /* mov eax, dword ptr [0x10010674] */
    W32((uint32_t)(0x8affc0u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ffc0], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_008a5a68; /* je 0x8a5a68 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_008a5a68:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a5a78u); f_008a5ac5(c); /* call 0x8a5ac5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5a87u); f_008a5629(c); /* call 0x8a5629 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_008a5a98; /* jne 0x8a5a98 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x008a5a97u); f_008a4170(c); /* call 0x8a4170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a5a98:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a5aaeu); f_008a5ac5(c); /* call 0x8a5ac5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0x8affa8u), (uint32_t)(c->esi)); /* mov dword ptr [0x1000ffa8], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x8affa4u), (uint32_t)(c->eax)); /* mov dword ptr [0x1000ffa4], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5ac5(CPU *c) { /* FUN_10005ac5 */
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
    if (c->zf) goto L_008a5aef; /* je 0x8a5aef */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_008a5aef:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_008a5b38; /* jne 0x8a5b38 */
L_008a5af4:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_008a5b26; /* je 0x8a5b26 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_008a5b26; /* je 0x8a5b26 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x8b0421u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10010421], 4 */
    if (c->zf) goto L_008a5b19; /* je 0x8a5b19 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5b19; /* je 0x8a5b19 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_008a5b19:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5af4; /* je 0x8a5af4 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_008a5af4; /* jmp 0x8a5af4 */
L_008a5b26:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5b30; /* je 0x8a5b30 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_008a5b30:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_008a5b7b; /* jne 0x8a5b7b */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_008a5b7b; /* jmp 0x8a5b7b */
L_008a5b38:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5b43; /* je 0x8a5b43 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_008a5b43:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x8b0421u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10010421], 4 */
    if (c->zf) goto L_008a5b5e; /* je 0x8a5b5e */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5b5d; /* je 0x8a5b5d */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_008a5b5d:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_008a5b5e:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_008a5b6c; /* je 0x8a5b6c */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_008a5b70; /* je 0x8a5b70 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_008a5b38; /* jne 0x8a5b38 */
L_008a5b6c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_008a5b73; /* jne 0x8a5b73 */
L_008a5b70:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_008a5b7b; /* jmp 0x8a5b7b */
L_008a5b73:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5b7b; /* je 0x8a5b7b */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_008a5b7b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_008a5b7f:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_008a5c68; /* je 0x8a5c68 */
L_008a5b88:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_008a5b94; /* je 0x8a5b94 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_008a5b97; /* jne 0x8a5b97 */
L_008a5b94:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_008a5b88; /* jmp 0x8a5b88 */
L_008a5b97:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_008a5c68; /* je 0x8a5c68 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a5bac; /* je 0x8a5bac */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_008a5bac:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_008a5bb1:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_008a5bba:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_008a5bc3; /* jne 0x8a5bc3 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_008a5bba; /* jmp 0x8a5bba */
L_008a5bc3:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_008a5bf4; /* jne 0x8a5bf4 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_008a5bf2; /* jne 0x8a5bf2 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_008a5be1; /* je 0x8a5be1 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_008a5be1; /* jne 0x8a5be1 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_008a5be4; /* jmp 0x8a5be4 */
L_008a5be1:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_008a5be4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_008a5bf2:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_008a5bf4:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_008a5c09; /* je 0x8a5c09 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_008a5bfc:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5c04; /* je 0x8a5c04 */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_008a5c04:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_008a5bfc; /* jne 0x8a5bfc */
L_008a5c09:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_008a5c59; /* je 0x8a5c59 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_008a5c1f; /* jne 0x8a5c1f */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_008a5c59; /* je 0x8a5c59 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_008a5c59; /* je 0x8a5c59 */
L_008a5c1f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_008a5c53; /* je 0x8a5c53 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5c42; /* je 0x8a5c42 */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0x8b0421u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x10010421], 4 */
    if (c->zf) goto L_008a5c3b; /* je 0x8a5c3b */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_008a5c3b:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_008a5c51; /* jmp 0x8a5c51 */
L_008a5c42:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0x8b0421u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x10010421], 4 */
    if (c->zf) goto L_008a5c51; /* je 0x8a5c51 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_008a5c51:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_008a5c53:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_008a5bb1; /* jmp 0x8a5bb1 */
L_008a5c59:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_008a5c61; /* je 0x8a5c61 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_008a5c61:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_008a5b7f; /* jmp 0x8a5b7f */
L_008a5c68:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_008a5c6f; /* je 0x8a5c6f */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_008a5c6f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a5c79(CPU *c) { /* FUN_10005c79 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b00d8u))); /* mov eax, dword ptr [0x100100d8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x8ab07cu))); /* mov ebp, dword ptr [0x1000b07c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_008a5cc7; /* jne 0x8a5cc7 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x008a5c96u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_008a5ca8; /* je 0x8a5ca8 */
    W32((uint32_t)(0x8b00d8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x100100d8], 1 */
    goto L_008a5cd0; /* jmp 0x8a5cd0 */
L_008a5ca8:;
    { uint32_t t_ = R32((uint32_t)(0x8ab078u)); PUSH32(c, 0x008a5caeu); call_indirect(c, t_); } /* call dword ptr [0x1000b078] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_008a5da2; /* je 0x8a5da2 */
    W32((uint32_t)(0x8b00d8u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x100100d8], 2 */
    goto L_008a5d56; /* jmp 0x8a5d56 */
L_008a5cc7:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_008a5d51; /* jne 0x8a5d51 */
L_008a5cd0:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_008a5ce0; /* jne 0x8a5ce0 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x008a5cd6u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_008a5da2; /* je 0x8a5da2 */
L_008a5ce0:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_008a5cf5; /* je 0x8a5cf5 */
L_008a5ce7:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_008a5ce7; /* jne 0x8a5ce7 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_008a5ce7; /* jne 0x8a5ce7 */
L_008a5cf5:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0x8ab074u))); /* mov edi, dword ptr [0x1000b074] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x008a5d0eu); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_008a5d46; /* je 0x8a5d46 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x008a5d1au); f_008a5629(c); /* call 0x8a5629 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_008a5d46; /* je 0x8a5d46 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x008a5d30u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5d42; /* jne 0x8a5d42 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x008a5d3du); f_008a695d(c); /* call 0x8a695d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_008a5d42:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_008a5d46:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x8ab070u)); PUSH32(c, 0x008a5d4du); call_indirect(c, t_); } /* call dword ptr [0x1000b070] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_008a5da4; /* jmp 0x8a5da4 */
L_008a5d51:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a5da2; /* jne 0x8a5da2 */
L_008a5d56:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_008a5d66; /* jne 0x8a5d66 */
    { uint32_t t_ = R32((uint32_t)(0x8ab078u)); PUSH32(c, 0x008a5d60u); call_indirect(c, t_); } /* call dword ptr [0x1000b078] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_008a5da2; /* je 0x8a5da2 */
L_008a5d66:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_008a5d76; /* je 0x8a5d76 */
L_008a5d6c:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_008a5d6c; /* jne 0x8a5d6c */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_008a5d6c; /* jne 0x8a5d6c */
L_008a5d76:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x008a5d81u); f_008a5629(c); /* call 0x8a5629 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_008a5d8c; /* jne 0x8a5d8c */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_008a5d97; /* jmp 0x8a5d97 */
L_008a5d8c:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x008a5d94u); f_008a8700(c); /* call 0x8a8700 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_008a5d97:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x8ab06cu)); PUSH32(c, 0x008a5d9eu); call_indirect(c, t_); } /* call dword ptr [0x1000b06c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_008a5da4; /* jmp 0x8a5da4 */
L_008a5da2:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a5da4:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_008a5dab(CPU *c) { /* FUN_10005dab */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0x8ab038u)); PUSH32(c, 0x008a5dbbu); call_indirect(c, t_); } /* call dword ptr [0x1000b038] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_008a5dd6; /* jne 0x8a5dd6 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_008a5dd6; /* je 0x8a5dd6 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_008a5dd6:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a5dd8(CPU *c) { /* FUN_10005dd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x008a5de5u); f_008a91e0(c); /* call 0x8a91e0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0x8ab084u)); PUSH32(c, 0x008a5dfdu); call_indirect(c, t_); } /* call dword ptr [0x1000b084] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5e1b; /* je 0x8a5e1b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_008a5e1b; /* jne 0x8a5e1b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_008a5e1b; /* jb 0x8a5e1b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_008a5f1d; /* jmp 0x8a5f1d */
L_008a5e1b:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x8ab7f8u; PUSH32(c, v_); } /* push 0x1000b7f8 */
    { uint32_t t_ = R32((uint32_t)(0x8ab080u)); PUSH32(c, 0x008a5e32u); call_indirect(c, t_); } /* call dword ptr [0x1000b080] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a5f0a; /* je 0x8a5f0a */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_008a5e5d; /* je 0x8a5e5d */
L_008a5e4a:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_008a5e58; /* jl 0x8a5e58 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_008a5e58; /* jg 0x8a5e58 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_008a5e58:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_008a5e4a; /* jne 0x8a5e4a */
L_008a5e5d:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x8ab7e0u; PUSH32(c, v_); } /* push 0x1000b7e0 */
    PUSH32(c, 0x008a5e70u); f_008a91a0(c); /* call 0x8a91a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5e7f; /* jne 0x8a5e7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_008a5ec8; /* jmp 0x8a5ec8 */
L_008a5e7f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0x8ab068u)); PUSH32(c, 0x008a5e92u); call_indirect(c, t_); } /* call dword ptr [0x1000b068] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_008a5eb3; /* je 0x8a5eb3 */
L_008a5ea0:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_008a5eae; /* jl 0x8a5eae */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_008a5eae; /* jg 0x8a5eae */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_008a5eae:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_008a5ea0; /* jne 0x8a5ea0 */
L_008a5eb3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5ec6u); f_008a9120(c); /* call 0x8a9120 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a5ec8:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_008a5f0a; /* je 0x8a5f0a */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5ed4u); f_008a9060(c); /* call 0x8a9060 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a5f0a; /* je 0x8a5f0a */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_008a5eef; /* je 0x8a5eef */
L_008a5ee1:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_008a5eea; /* jne 0x8a5eea */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_008a5eeb; /* jmp 0x8a5eeb */
L_008a5eea:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_008a5eeb:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_008a5ee1; /* jne 0x8a5ee1 */
L_008a5eef:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5ef8u); f_008a8e29(c); /* call 0x8a8e29 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_008a5f1d; /* je 0x8a5f1d */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_008a5f1d; /* je 0x8a5f1d */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_008a5f1d; /* je 0x8a5f1d */
L_008a5f0a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a5f13u); f_008a5dab(c); /* call 0x8a5dab */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_008a5f1d:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a5f20(CPU *c) { /* FUN_10005f20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab008u)); PUSH32(c, 0x008a5f37u); call_indirect(c, t_); } /* call dword ptr [0x1000b008] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0x8b0544u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010544], eax */
    if (c->zf) goto L_008a5f76; /* je 0x8a5f76 */
    PUSH32(c, 0x008a5f45u); f_008a5dd8(c); /* call 0x8a5dd8 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0x8b0548u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010548], eax */
    if (!c->zf) goto L_008a5f5c; /* jne 0x8a5f5c */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x008a5f59u); f_008a74c4(c); /* call 0x8a74c4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_008a5f66; /* jmp 0x8a5f66 */
L_008a5f5c:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a5f79; /* jne 0x8a5f79 */
    PUSH32(c, 0x008a5f66u); f_008a800b(c); /* call 0x8a800b */
L_008a5f66:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a5f79; /* jne 0x8a5f79 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab088u)); PUSH32(c, 0x008a5f76u); call_indirect(c, t_); } /* call dword ptr [0x1000b088] */
L_008a5f76:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_008a5f79:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_008a5f7d(CPU *c) { /* FUN_10005f7d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8b0548u))); /* mov eax, dword ptr [0x10010548] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_008a5fef; /* jne 0x8a5fef */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0x8b0538u)), c->ebx); /* cmp dword ptr [0x10010538], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0x8ab090u))); /* mov ebp, dword ptr [0x1000b090] */
    if ((c->zf || c->sf != c->of)) goto L_008a5fdb; /* jle 0x8a5fdb */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b053cu))); /* mov eax, dword ptr [0x1001053c] */
    c->edi = (uint32_t)(R32((uint32_t)(0x8ab08cu))); /* mov edi, dword ptr [0x1000b08c] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_008a5fa9:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x008a5fb7u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x008a5fc2u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x008a5fcfu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0x8b0538u))); /* cmp ebx, dword ptr [0x10010538] */
    if ((c->sf != c->of)) goto L_008a5fa9; /* jl 0x8a5fa9 */
L_008a5fdb:;
    { uint32_t v_ = R32((uint32_t)(0x8b053cu)); PUSH32(c, v_); } /* push dword ptr [0x1001053c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x008a5febu); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_008a6016; /* jmp 0x8a6016 */
L_008a5fef:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_008a6016; /* jne 0x8a6016 */
    c->edi = (uint32_t)((uint32_t)0x8ad6b0u); /* mov edi, 0x1000d6b0 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_008a5ffb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a6010; /* je 0x8a6010 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab08cu)); PUSH32(c, 0x008a6010u); call_indirect(c, t_); } /* call dword ptr [0x1000b08c] */
L_008a6010:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_008a5ffb; /* jne 0x8a5ffb */
L_008a6016:;
    { uint32_t v_ = R32((uint32_t)(0x8b0544u)); PUSH32(c, v_); } /* push dword ptr [0x10010544] */
    { uint32_t t_ = R32((uint32_t)(0x8ab088u)); PUSH32(c, 0x008a6022u); call_indirect(c, t_); } /* call dword ptr [0x1000b088] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a6025(CPU *c) { /* FUN_10006025 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_008a602b(CPU *c) { /* FUN_1000602b */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff88u))); /* mov eax, dword ptr [0x1000ff88] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_008a6042; /* je 0x8a6042 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a6063; /* jne 0x8a6063 */
    (void)sub32(c, R32((uint32_t)(0x8aff8cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000ff8c], 1 */
    if (!c->zf) goto L_008a6063; /* jne 0x8a6063 */
L_008a6042:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x008a604cu); f_008a6064(c); /* call 0x8a6064 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8b00dcu))); /* mov eax, dword ptr [0x100100dc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a6058; /* je 0x8a6058 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x008a6058u); call_indirect(c, t_); } /* call eax */
L_008a6058:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x008a6062u); f_008a6064(c); /* call 0x8a6064 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a6063:;
    c->esp += 4; return; /* ret  */
}

void f_008a6064(CPU *c) { /* FUN_10006064 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x8ad288u); /* mov eax, 0x1000d288 */
L_008a6077:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_008a6086; /* je 0x8a6086 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0x8ad318u); /* cmp eax, 0x1000d318 */
    if ((c->sf != c->of)) goto L_008a6077; /* jl 0x8a6077 */
L_008a6086:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0x8ad288u))); /* cmp edx, dword ptr [esi + 0x1000d288] */
    if (!c->zf) goto L_008a61b4; /* jne 0x8a61b4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x8aff88u))); /* mov eax, dword ptr [0x1000ff88] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_008a618e; /* je 0x8a618e */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a60b7; /* jne 0x8a60b7 */
    (void)sub32(c, R32((uint32_t)(0x8aff8cu)), (uint32_t)0x1u); /* cmp dword ptr [0x1000ff8c], 1 */
    if (c->zf) goto L_008a618e; /* je 0x8a618e */
L_008a60b7:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_008a61b4; /* je 0x8a61b4 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0x8ab068u)); PUSH32(c, 0x008a60d7u); call_indirect(c, t_); } /* call dword ptr [0x1000b068] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_008a60ee; /* jne 0x8a60ee */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x8abae8u; PUSH32(c, v_); } /* push 0x1000bae8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a60ecu); f_008a72f0(c); /* call 0x8a72f0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_008a60ee:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x008a6101u); f_008a7440(c); /* call 0x8a7440 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_008a6131; /* jbe 0x8a6131 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a6114u); f_008a7440(c); /* call 0x8a7440 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0x8abae4u; PUSH32(c, v_); } /* push 0x1000bae4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x008a612eu); f_008a92a0(c); /* call 0x8a92a0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_008a6131:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x8abac8u; PUSH32(c, v_); } /* push 0x1000bac8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a6142u); f_008a72f0(c); /* call 0x8a72f0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a614fu); f_008a7300(c); /* call 0x8a7300 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x8abac4u; PUSH32(c, v_); } /* push 0x1000bac4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a6160u); f_008a7300(c); /* call 0x8a7300 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x8ad28cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1000d28c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a6172u); f_008a7300(c); /* call 0x8a7300 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0x8aba9cu; PUSH32(c, v_); } /* push 0x1000ba9c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a6188u); f_008a920f(c); /* call 0x8a920f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_008a61b4; /* jmp 0x8a61b4 */
L_008a618e:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0x8ad28cu)); /* lea esi, [esi + 0x1000d28c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x008a61a1u); f_008a7440(c); /* call 0x8a7440 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0x8ab058u)); PUSH32(c, 0x008a61adu); call_indirect(c, t_); } /* call dword ptr [0x1000b058] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x8ab094u)); PUSH32(c, 0x008a61b4u); call_indirect(c, t_); } /* call dword ptr [0x1000b094] */
L_008a61b4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a61b7(CPU *c) { /* FUN_100061b7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_008a61da; /* jne 0x8a61da */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_008a61da; /* jne 0x8a61da */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_008a61da; /* jne 0x8a61da */
    { f_008a4b98(c); return; } /* jmp 0x8a4b98 */
L_008a61da:;
    c->eax = (uint32_t)(R32((uint32_t)(0x8b00e0u))); /* mov eax, dword ptr [0x100100e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a61f7; /* je 0x8a61f7 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a61e9u); f_008a6253(c); /* call 0x8a6253 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_008a61f7; /* je 0x8a61f7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x8b00e0u)); PUSH32(c, 0x008a61f5u); call_indirect(c, t_); } /* call dword ptr [0x100100e0] */
    goto L_008a61f9; /* jmp 0x8a61f9 */
L_008a61f7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_008a61f9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_008a61fd(CPU *c) { /* PTR_008a61fd */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x8a61b7u; PUSH32(c, v_); } /* push 0x100061b7 */
    { uint32_t t_ = R32((uint32_t)(0x8ab098u)); PUSH32(c, 0x008a6208u); call_indirect(c, t_); } /* call dword ptr [0x1000b098] */
    W32((uint32_t)(0x8b00e0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100100e0], eax */
    c->esp += 4; return; /* ret  */
}

void f_008a620e(CPU *c) { /* PTR_008a620e */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x8b00e0u)); PUSH32(c, v_); } /* push dword ptr [0x100100e0] */
    { uint32_t t_ = R32((uint32_t)(0x8ab098u)); PUSH32(c, 0x008a621au); call_indirect(c, t_); } /* call dword ptr [0x1000b098] */
    c->esp += 4; return; /* ret  */
}

void f_008a621b(CPU *c) { /* FUN_1000621b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x8ab09cu)); PUSH32(c, 0x008a622du); call_indirect(c, t_); } /* call dword ptr [0x1000b09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a6233; /* je 0x8a6233 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a6233:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a6237(CPU *c) { /* FUN_10006237 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t t_ = R32((uint32_t)(0x8ab0a0u)); PUSH32(c, 0x008a6249u); call_indirect(c, t_); } /* call dword ptr [0x1000b0a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a624f; /* je 0x8a624f */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a624f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a6253(CPU *c) { /* FUN_10006253 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x8ab0a4u)); PUSH32(c, 0x008a6261u); call_indirect(c, t_); } /* call dword ptr [0x1000b0a4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_008a6267; /* je 0x8a6267 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
L_008a6267:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_008a6270(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_008a62bc; /* jne 0x8a62bc */
L_008a6280:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_008a62b0; /* je 0x8a62b0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_008a62b0; /* je 0x8a62b0 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_008a62b0; /* je 0x8a62b0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_008a6280; /* jne 0x8a6280 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_008a62b0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_008a62b4:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_008a62bc:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_008a62d8; /* je 0x8a62d8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_008a62b0; /* je 0x8a62b0 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_008a6280; /* je 0x8a6280 */
L_008a62d8:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_008a62b0; /* je 0x8a62b0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_008a62b4; /* jne 0x8a62b4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_008a62b0; /* je 0x8a62b0 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_008a6280; /* jmp 0x8a6280 */
}

void f_008a62f4(CPU *c) { /* PTR_008a62f4 */
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
    if (!c->zf) goto L_008a639c; /* jne 0x8a639c */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    W32((uint32_t)(c->ebx + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx - 4], eax */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov esi, dword ptr [ebx + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
L_008a632f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_008a6395; /* je 0x8a6395 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    (void)sub32(c, R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [edi + ecx*4 + 4], 0 */
    if (c->zf) goto L_008a6383; /* je 0x8a6383 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x4u)); PUSH32(c, 0x008a6347u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 4] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_008a6383; /* je 0x8a6383 */
    if (c->sf) goto L_008a638e; /* js 0x8a638e */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a635bu); f_008a3dcc(c); /* call 0x8a3dcc */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a6368u); f_008a3e0e(c); /* call 0x8a3e0e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u))); /* mov eax, dword ptr [edi + ecx*4 + 8] */
    PUSH32(c, 0x008a6379u); f_008a3ea2(c); /* call 0x8a3ea2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov eax, dword ptr [edi + ecx*4] */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xc], eax */
    { uint32_t t_ = R32((uint32_t)(c->edi + c->ecx * 4 + 0x8u)); PUSH32(c, 0x008a6383u); call_indirect(c, t_); } /* call dword ptr [edi + ecx*4 + 8] */
L_008a6383:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebx + 0x8u))); /* mov edi, dword ptr [ebx + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea ecx, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + c->ecx * 4))); /* mov esi, dword ptr [edi + ecx*4] */
    goto L_008a632f; /* jmp 0x8a632f */
L_008a638e:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_008a63b1; /* jmp 0x8a63b1 */
L_008a6395:;
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_008a63b1; /* jmp 0x8a63b1 */
L_008a639c:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea ebp, [ebx + 0x10] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x008a63a8u); f_008a3e0e(c); /* call 0x8a3e0e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_008a63b1:;
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_008a63b9(CPU *c) { /* FUN_100063b9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebp, dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x1cu))); /* mov eax, dword ptr [ecx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x18u))); /* mov eax, dword ptr [ecx + 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x008a63cdu); f_008a3e0e(c); /* call 0x8a3e0e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 8; return; /* ret 4 */
}

void f_008a63e0(CPU *c) { /* FUN_100063e0 */
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
    if ((c->cf || c->zf)) goto L_008a6400; /* jbe 0x8a6400 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_008a6578; /* jb 0x8a6578 */
L_008a6400:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_008a641c; /* jne 0x8a641c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_008a643c; /* jb 0x8a643c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a6415u); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a641c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_008a6434; /* jb 0x8a6434 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x8a6440u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a642du); return; } } /* jmp dword ptr [eax*4 + 0x10006440] */
L_008a6434:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a6538u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a6434u); return; } } /* jmp dword ptr [ecx*4 + 0x10006538] */
L_008a643c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a64bcu)); switch (t_) { case 0x008a64dcu: goto L_008a64dc; case 0x008a64e4u: goto L_008a64e4; case 0x008a64ecu: goto L_008a64ec; case 0x008a64f4u: goto L_008a64f4; case 0x008a64fcu: goto L_008a64fc; case 0x008a6504u: goto L_008a6504; case 0x008a650cu: goto L_008a650c; case 0x008a651fu: goto L_008a651f; default: jump_indirect(c, t_, 0x008a643cu); return; } } /* jmp dword ptr [ecx*4 + 0x100064bc] */
L_008a64dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_008a64e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_008a64ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_008a64f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_008a64fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_008a6504:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_008a650c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_008a651f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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
L_008a6578:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_008a65ac; /* jne 0x8a65ac */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_008a65a0; /* jb 0x8a65a0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a6597u); return; } } /* jmp dword ptr [edx*4 + 0x100066c0] */
L_008a65a0:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a6670u)); switch (t_) { case 0x008a66b7u: goto L_008a66b7; default: jump_indirect(c, t_, 0x008a65a2u); return; } } /* jmp dword ptr [ecx*4 + 0x10006670] */
L_008a65ac:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_008a65c4; /* jb 0x8a65c4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x8a65c8u)); switch (t_) {  default: jump_indirect(c, t_, 0x008a65bdu); return; } } /* jmp dword ptr [eax*4 + 0x100065c8] */
L_008a65c4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a65c4u); return; } } /* jmp dword ptr [ecx*4 + 0x100066c0] */
L_008a66b7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a66b7u); return; } } /* jmp dword ptr [edx*4 + 0x100066c0] */
L_008a66d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66fc:;
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

void f_008a643c(CPU *c) { /* PTR_008a643c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a64bcu)); switch (t_) { case 0x008a64dcu: goto L_008a64dc; case 0x008a64e4u: goto L_008a64e4; case 0x008a64ecu: goto L_008a64ec; case 0x008a64f4u: goto L_008a64f4; case 0x008a64fcu: goto L_008a64fc; case 0x008a6504u: goto L_008a6504; case 0x008a650cu: goto L_008a650c; case 0x008a651fu: goto L_008a651f; default: jump_indirect(c, t_, 0x008a643cu); return; } } /* jmp dword ptr [ecx*4 + 0x100064bc] */
L_008a64dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_008a64e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_008a64ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_008a64f4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_008a64fc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_008a6504:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_008a650c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_008a651f:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a6450(CPU *c) { /* PTR_008a6450 */
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
    if (c->cf) { f_008a643c(c); return; } /* jb 0x8a643c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a6472u); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a6470(CPU *c) { /* PTR_008a6470 */
    PREEMPT_POLL(c);
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a6472u); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a647c(CPU *c) { /* PTR_008a647c */
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
    if (c->cf) { f_008a643c(c); return; } /* jb 0x8a643c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a6498u); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a64a0(CPU *c) { /* PTR_008a64a0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_008a643c(c); return; } /* jb 0x8a643c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a64b2u); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a64dc(CPU *c) { /* PTR_008a64dc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a64e4(CPU *c) { /* PTR_008a64e4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a64ec(CPU *c) { /* PTR_008a64ec */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a64f4(CPU *c) { /* PTR_008a64f4 */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a64fc(CPU *c) { /* PTR_008a64fc */
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
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a6504(CPU *c) { /* PTR_008a6504 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a650c(CPU *c) { /* PTR_008a650c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a651f(CPU *c) { /* PTR_008a651f */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a6528u)); switch (t_) { case 0x008a6538u: goto L_008a6538; case 0x008a6540u: goto L_008a6540; case 0x008a654cu: goto L_008a654c; case 0x008a6560u: goto L_008a6560; default: jump_indirect(c, t_, 0x008a651fu); return; } } /* jmp dword ptr [edx*4 + 0x10006528] */
L_008a6538:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6540:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a654c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a6560:;
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

void f_008a6538(CPU *c) { /* PTR_008a6538 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a6540(CPU *c) { /* PTR_008a6540 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_008a654c(CPU *c) { /* PTR_008a654c */
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

void f_008a6560(CPU *c) { /* PTR_008a6560 */
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

void f_008a65a0(CPU *c) { /* PTR_008a65a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0x8a6670u)); switch (t_) { case 0x008a66b7u: goto L_008a66b7; default: jump_indirect(c, t_, 0x008a65a2u); return; } } /* jmp dword ptr [ecx*4 + 0x10006670] */
L_008a66b7:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a66b7u); return; } } /* jmp dword ptr [edx*4 + 0x100066c0] */
L_008a66d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66fc:;
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

void f_008a65d8(CPU *c) { /* PTR_008a65d8 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) { f_008a65a0(c); return; } /* jb 0x8a65a0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a65eeu); return; } } /* jmp dword ptr [edx*4 + 0x100066c0] */
L_008a66d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66fc:;
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

void f_008a65f8(CPU *c) { /* PTR_008a65f8 */
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
    if (c->cf) { f_008a65a0(c); return; } /* jb 0x8a65a0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a6618u); return; } } /* jmp dword ptr [edx*4 + 0x100066c0] */
L_008a66d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66fc:;
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

void f_008a6620(CPU *c) { /* PTR_008a6620 */
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
    if (c->cf) { f_008a65a0(c); return; } /* jb 0x8a65a0 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0x8a66c0u)); switch (t_) { case 0x008a66d0u: goto L_008a66d0; case 0x008a66d8u: goto L_008a66d8; case 0x008a66e8u: goto L_008a66e8; case 0x008a66fcu: goto L_008a66fc; default: jump_indirect(c, t_, 0x008a664au); return; } } /* jmp dword ptr [edx*4 + 0x100066c0] */
L_008a66d0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66d8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66e8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_008a66fc:;
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
