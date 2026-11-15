#include "recomp.h"

void f_00a01000(CPU *c) { /* FUN_10001000 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { uint32_t v_ = 0xa10040u; PUSH32(c, v_); } /* push 0x10010040 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xa0e0f0u)); /* mov dword ptr [esi], 0x1000e0f0 */
    W32((uint32_t)(c->esi + 0xd4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xd4], edi */
    W32((uint32_t)(c->esi + 0xbd8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xbd8], edi */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x40u)); PUSH32(c, 0x00a0102fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x40] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    W32((uint32_t)(c->esi + 0xbdcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xbdc], eax */
    PUSH32(c, 0x00a01041u); f_00a01c50(c); /* call 0xa01c50 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 4], edi */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 8], edi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01050(CPU *c) { /* FUN_10001050 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a01058u); f_00a01070(c); /* call 0xa01070 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a01068; /* je 0xa01068 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a01065u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a01068:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01070(CPU *c) { /* FUN_10001070 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xd4u))); /* mov eax, dword ptr [ecx + 0xd4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xa0e0f0u)); /* mov dword ptr [ecx], 0x1000e0f0 */
    if ((c->zf || c->sf != c->of)) goto L_00a010bc; /* jle 0xa010bc */
    c->ebp = (uint32_t)((uint32_t)(c->ecx + 0x14u)); /* lea ebp, [ecx + 0x14] */
L_00a0108e:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov esi, dword ptr [ebp] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00a010acu); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0xcu)); /* add ebp, 0xc */
    (void)sub32(c, c->ebx, R32((uint32_t)(c->eax + 0xd4u))); /* cmp ebx, dword ptr [eax + 0xd4] */
    if ((c->sf != c->of)) goto L_00a0108e; /* jl 0xa0108e */
L_00a010bc:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a010d0(CPU *c) { /* FUN_100010d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x3fc00000u; PUSH32(c, v_); } /* push 0x3fc00000 */
    { uint32_t v_ = 0x43fa0000u; PUSH32(c, v_); } /* push 0x43fa0000 */
    { uint32_t v_ = 0xa10124u; PUSH32(c, v_); } /* push 0x10010124 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a010e7u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3fd9999au; PUSH32(c, v_); } /* push 0x3fd9999a */
    { uint32_t v_ = 0x43c80000u; PUSH32(c, v_); } /* push 0x43c80000 */
    { uint32_t v_ = 0xa10114u; PUSH32(c, v_); } /* push 0x10010114 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a010fdu); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    { uint32_t v_ = 0x42c80000u; PUSH32(c, v_); } /* push 0x42c80000 */
    { uint32_t v_ = 0xa10104u; PUSH32(c, v_); } /* push 0x10010104 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a01113u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f8ccccdu; PUSH32(c, v_); } /* push 0x3f8ccccd */
    { uint32_t v_ = 0x43fa0000u; PUSH32(c, v_); } /* push 0x43fa0000 */
    { uint32_t v_ = 0xa100f4u; PUSH32(c, v_); } /* push 0x100100f4 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a01129u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f666666u; PUSH32(c, v_); } /* push 0x3f666666 */
    { uint32_t v_ = 0x41c80000u; PUSH32(c, v_); } /* push 0x41c80000 */
    { uint32_t v_ = 0xa100e4u; PUSH32(c, v_); } /* push 0x100100e4 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a0113fu); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f19999au; PUSH32(c, v_); } /* push 0x3f19999a */
    { uint32_t v_ = 0x40a00000u; PUSH32(c, v_); } /* push 0x40a00000 */
    { uint32_t v_ = 0xa100d0u; PUSH32(c, v_); } /* push 0x100100d0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a01155u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3ecccccdu; PUSH32(c, v_); } /* push 0x3ecccccd */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    { uint32_t v_ = 0xa100bcu; PUSH32(c, v_); } /* push 0x100100bc */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a0116bu); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f4ccccdu; PUSH32(c, v_); } /* push 0x3f4ccccd */
    { uint32_t v_ = 0x41a00000u; PUSH32(c, v_); } /* push 0x41a00000 */
    { uint32_t v_ = 0xa100a8u; PUSH32(c, v_); } /* push 0x100100a8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a01181u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f000000u; PUSH32(c, v_); } /* push 0x3f000000 */
    { uint32_t v_ = 0x41700000u; PUSH32(c, v_); } /* push 0x41700000 */
    { uint32_t v_ = 0xa10094u; PUSH32(c, v_); } /* push 0x10010094 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a01197u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f59999au; PUSH32(c, v_); } /* push 0x3f59999a */
    { uint32_t v_ = 0x41200000u; PUSH32(c, v_); } /* push 0x41200000 */
    { uint32_t v_ = 0xa10080u; PUSH32(c, v_); } /* push 0x10010080 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a011adu); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f8ccccdu; PUSH32(c, v_); } /* push 0x3f8ccccd */
    { uint32_t v_ = 0x40a00000u; PUSH32(c, v_); } /* push 0x40a00000 */
    { uint32_t v_ = 0xa1006cu; PUSH32(c, v_); } /* push 0x1001006c */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a011c3u); f_00a01860(c); /* call 0xa01860 */
    { uint32_t v_ = 0x3f99999au; PUSH32(c, v_); } /* push 0x3f99999a */
    { uint32_t v_ = 0x40a00000u; PUSH32(c, v_); } /* push 0x40a00000 */
    { uint32_t v_ = 0xa10058u; PUSH32(c, v_); } /* push 0x10010058 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a011d9u); f_00a01860(c); /* call 0xa01860 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a011e0u); f_00a019e0(c); /* call 0xa019e0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13400u))); /* mov ecx, dword ptr [0x10013400] */
    { uint32_t v_ = 0xa10048u; PUSH32(c, v_); } /* push 0x10010048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00a011f0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a01200(CPU *c) { /* FUN_10001200 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xd4u))); /* mov eax, dword ptr [ebx + 0xd4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a01690; /* je 0xa01690 */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x8u))); /* fld dword ptr [ebx + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01230; /* jne 0xa01230 */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x8u))); /* fld dword ptr [ebx + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x28u))); /* fsub dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->ebx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 8] */
L_00a01230:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xbd8u)), (uint32_t)0x40u); /* cmp dword ptr [ebx + 0xbd8], 0x40 */
    if (!c->cf) goto L_00a0142b; /* jae 0xa0142b */
    PUSH32(c, 0x00a01242u); f_00a0454d(c); /* call 0xa0454d */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1u))); /* and eax, 1 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x1u); /* cmp al, 1 */
    if (!c->zf) goto L_00a0142b; /* jne 0xa0142b */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    PUSH32(c, 0x00a01254u); f_00a01ad0(c); /* call 0xa01ad0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a0142b; /* je 0xa0142b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ecx * 2)); /* lea edx, [eax + ecx*2] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edx * 4 + 0xf0u)); /* lea eax, [ebx + edx*4 + 0xf0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a01277u); f_00a01a30(c); /* call 0xa01a30 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov ecx, dword ptr [ebx + 0xbd8] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4)); /* lea edx, [ecx + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(c->ecx + c->edx * 2)); /* lea ecx, [ecx + edx*2] */
    W32((uint32_t)(c->ebx + c->ecx * 4 + 0x100u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + ecx*4 + 0x100], eax */
    PUSH32(c, 0x00a0128fu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x5u)); /* add eax, 5 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e138u))); /* fmul dword ptr [0x1000e138] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 2)); /* lea eax, [eax + edx*2] */
    WF32((uint32_t)(c->ebx + c->eax * 4), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + eax*4] */
    PUSH32(c, 0x00a012b4u); f_00a0454d(c); /* call 0xa0454d */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7u))); /* and eax, 7 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ecx * 2)); /* lea edx, [eax + ecx*2] */
    WF32((uint32_t)(c->ebx + c->edx * 4 + 0xe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + edx*4 + 0xe0] */
    PUSH32(c, 0x00a012d7u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ecx * 2)); /* lea edx, [eax + ecx*2] */
    WF32((uint32_t)(c->ebx + c->edx * 4 + 0xd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + edx*4 + 0xd8] */
    PUSH32(c, 0x00a012fdu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x1c], 0 */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x20], 0 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e130u))); /* fmul dword ptr [0x1000e130] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ecx * 2)); /* lea edx, [eax + ecx*2] */
    WF32((uint32_t)(c->ebx + c->edx * 4 + 0xe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + edx*4 + 0xe4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea ecx, [eax + eax*4] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ecx * 2)); /* lea edx, [eax + ecx*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edx * 4 + 0xf4u)); /* lea eax, [ebx + edx*4 + 0xf4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    PUSH32(c, 0x00a01362u); f_00a0454d(c); /* call 0xa0454d */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e12cu))); /* fmul dword ptr [0x1000e12c] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 2)); /* lea eax, [eax + edx*2] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e128u))); /* fadd dword ptr [0x1000e128] */
    WF32((uint32_t)(c->ebx + c->eax * 4 + 0xecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + eax*4 + 0xec] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov ecx, dword ptr [ebx + 0xbd8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebx + 0xbd8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 0xbd8], ecx */
    if (c->zf) goto L_00a0142b; /* je 0xa0142b */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x8u))); /* fld dword ptr [ebx + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00a0142b; /* jp 0xa0142b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00a013beu); f_00a029c0(c); /* call 0xa029c0 */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00a013ccu); f_00a02a20(c); /* call 0xa02a20 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x24u)); /* lea eax, [esp + 0x24] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x30], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov ecx, dword ptr [ebx + 4] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x40], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0xa10134u; PUSH32(c, v_); } /* push 0x10010134 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00a0140fu); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    PUSH32(c, 0x00a01414u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e124u))); /* fmul dword ptr [0x1000e124] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e120u))); /* fadd dword ptr [0x1000e120] */
    WF32((uint32_t)(c->ebx + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 8] */
L_00a0142b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    PUSH32(c, 0x00a01433u); f_00a02940(c); /* call 0xa02940 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_00a01690; /* jle 0xa01690 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e11cu))); /* fmul dword ptr [0x1000e11c] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0xe4u)); /* lea ebp, [ebx + 0xe4] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
L_00a01464:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp + 0xcu))); /* fmul dword ptr [ebp + 0xc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp))); /* fadd dword ptr [ebp] */
    WF32((uint32_t)(c->ebp), (float)ST(0)); /* fst dword ptr [ebp] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xcu))); /* fld dword ptr [ebp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e118u))); /* fmul dword ptr [0x1000e118] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x10u))); FPOP(c); /* fcomp dword ptr [esp + 0x10] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01492; /* jne 0xa01492 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ebp), (uint32_t)(c->ecx)); /* mov dword ptr [ebp], ecx */
L_00a01492:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp))); /* fmul dword ptr [ebp] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0xfffffffcu))); /* fadd dword ptr [ebp - 4] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF32((uint32_t)(c->ebp + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x1cu))); FPOP(c); /* fcomp dword ptr [esp + 0x1c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a014dd; /* jne 0xa014dd */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea edi, [ebp - 0xc] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->ecx = (uint32_t)((uint32_t)0xbu); /* mov ecx, 0xb */
    W32((uint32_t)(c->ebx + 0xbd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0xbd8], eax */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea edx, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->edx * 2)); /* lea eax, [eax + edx*2] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + c->eax * 4 + 0xd8u)); /* lea esi, [ebx + eax*4 + 0xd8] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    goto L_00a01673; /* jmp 0xa01673 */
L_00a014dd:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x14], ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01500; /* jne 0xa01500 */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0x14], 0x3f800000 */
L_00a01500:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a0150du); f_00a02960(c); /* call 0xa02960 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ebp + 0xfffffff8u))); /* fsub dword ptr [ebp - 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0xfffffff8u))); /* fadd dword ptr [ebp - 8] */
    WF32((uint32_t)(c->ebp + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    PUSH32(c, 0x00a01526u); f_00a02950(c); /* call 0xa02950 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e114u))); /* fsub dword ptr [0x1000e114] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e110u))); /* fmul dword ptr [0x1000e110] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e10cu))); /* fmul dword ptr [0x1000e10c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e108u))); /* fadd dword ptr [0x1000e108] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x34u))); /* fmul dword ptr [esp + 0x34] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0xfffffff4u))); /* fadd dword ptr [ebp - 0xc] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->ebp + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01578; /* jne 0xa01578 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->ebp + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0xc] */
L_00a01578:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e100u))); /* fmul dword ptr [0x1000e100] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0x14u))); /* fadd dword ptr [ebp + 0x14] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->ebp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a015a8; /* jne 0xa015a8 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->ebp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x14] */
L_00a015a8:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e0fcu))); /* fmul dword ptr [0x1000e0fc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0x10u))); /* fadd dword ptr [ebp + 0x10] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->ebp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a015dc; /* jne 0xa015dc */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->ebp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x10] */
L_00a015dc:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x34u))); /* fld dword ptr [esp + 0x34] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e0f8u))); /* fmul dword ptr [0x1000e0f8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebp + 0x18u))); /* fadd dword ptr [ebp + 0x18] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->ebp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01610; /* jne 0xa01610 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->ebp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 0x18] */
L_00a01610:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xfffffffcu))); /* fld dword ptr [ebp - 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e108u))); FPOP(c); /* fcomp dword ptr [0x1000e108] */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ebp + 4], 0x3f800000 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01633; /* jp 0xa01633 */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xfffffffcu))); /* fld dword ptr [ebp - 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e0f4u))); /* fmul dword ptr [0x1000e0f4] */
    WF32((uint32_t)(c->ebp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 4] */
L_00a01633:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e114u))); /* fmul dword ptr [0x1000e114] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->ebp + 0xfffffffcu))); /* fcom dword ptr [ebp - 4] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a0165a; /* jp 0xa0165a */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xfffffffcu))); /* fld dword ptr [ebp - 4] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    ST(1) = FPRES(c, FDIV(c, ST(1), ST(0))); FPOP(c); /* fdivp st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp + 0x4u))); /* fmul dword ptr [ebp + 4] */
    WF32((uint32_t)(c->ebp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp + 4] */
L_00a0165a:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x4u))); /* fld dword ptr [ebp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01673; /* jp 0xa01673 */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp + 4], 0 */
L_00a01673:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov ecx, dword ptr [ebx + 0xbd8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0x2cu)); /* add ebp, 0x2c */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    if ((c->sf != c->of)) goto L_00a01464; /* jl 0xa01464 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00a01690:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a016a0(CPU *c) { /* FUN_100016a0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x28u)); /* sub esp, 0x28 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov eax, dword ptr [ebx + 0xbd8] */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x20], edi */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if ((c->zf || c->sf != c->of)) goto L_00a01858; /* jle 0xa01858 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ebp, dword ptr [esp + 0x38] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0xd8u)); /* lea esi, [ebx + 0xd8] */
    goto L_00a016cb; /* jmp 0xa016cb */
L_00a016c9:;
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00a016cb:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    PUSH32(c, 0x00a016dfu); f_00a029c0(c); /* call 0xa029c0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x30], ecx */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov ecx, dword ptr [ebx + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    PUSH32(c, 0x00a01706u); f_00a02a20(c); /* call 0xa02a20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x4u))); /* fmul dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x24u))); /* fld dword ptr [esi + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x20u))); /* fld dword ptr [esi + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fmul dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x20u))); /* fadd dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { double v_ = ST(2); FPUSH(c, v_); } /* fld st(2) */
    ST(0) = FPRES(c, ST(0) * ST(2)); /* fmul st(2) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fmul dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x18u))); /* fsub dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->eax + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->eax + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->eax + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x30] */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0xc], edi */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x1c], edi */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x2c], edi */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [eax + 0x3c], 0x3f800000 */
    c->edi = (uint32_t)((uint32_t)0x20u); /* mov edi, 0x20 */
    WF32((uint32_t)(c->eax + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fld dword ptr [esp + 0x3c] */
    ST(0) = -ST(0); /* fchs  */
    WF32((uint32_t)(c->eax + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    WF32((uint32_t)(c->eax + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fmul dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fsub dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x3cu))); /* fmul dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x24u))); /* fadd dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->eax + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    WF32((uint32_t)(c->eax + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x28] */
    WF32((uint32_t)(c->eax + 0x38u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 0x38] */
L_00a017f0:;
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
L_00a017f7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    if (!c->zf) goto L_00a017f7; /* jne 0xa017f7 */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x10u)); /* add edi, 0x10 */
    (void)sub32(c, c->edi, (uint32_t)0x50u); /* cmp edi, 0x50 */
    if ((c->sf != c->of)) goto L_00a017f0; /* jl 0xa017f0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x10u))); /* fld dword ptr [esi + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0x10u))); /* fmul dword ptr [ebx + 0x10] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov edi, dword ptr [ebp] */
    PUSH32(c, 0x00a0181fu); f_00a04570(c); /* call 0xa04570 */
    c->eax = (uint32_t)(shl32(c, c->eax, 24)); /* shl eax, 0x18 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffu))); /* or eax, 0xffffff */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x3cu; PUSH32(c, v_); } /* push 0x3c */
    { uint32_t t_ = R32((uint32_t)(c->edi + 0x12cu)); PUSH32(c, 0x00a01832u); call_indirect(c, t_); } /* call dword ptr [edi + 0x12c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov ecx, dword ptr [esi + 0x28] */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00a0183cu); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov eax, dword ptr [esp + 0x28] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0xbd8u))); /* mov ecx, dword ptr [ebx + 0xbd8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2cu)); /* add esi, 0x2c */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x28], eax */
    if ((c->sf != c->of)) goto L_00a016c9; /* jl 0xa016c9 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00a01858:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01860(CPU *c) { /* FUN_10001860 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0d390u; PUSH32(c, v_); } /* push 0x1000d390 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x24u)); /* sub esp, 0x24 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xd4u))); /* mov eax, dword ptr [ebx + 0xd4] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->esp)); /* mov dword ptr [ebp - 0x10], esp */
    (void)sub32(c, c->eax, (uint32_t)0x30u); /* cmp eax, 0x30 */
    if (!c->cf) goto L_00a0199b; /* jae 0xa0199b */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x28], esi */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x24], esi */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd0u)); /* lea eax, [ebp - 0x30] */
    { uint32_t v_ = 0xa10174u; PUSH32(c, v_); } /* push 0x10010174 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x5cu)); PUSH32(c, 0x00a018bcu); call_indirect(c, t_); } /* call dword ptr [edx + 0x5c] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a0199b; /* je 0xa0199b */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd0u)); /* lea eax, [ebp - 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00a018d3u); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    if (c->zf) goto L_00a0199b; /* je 0xa0199b */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = 0xa10168u; PUSH32(c, v_); } /* push 0x10010168 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x4cu)); PUSH32(c, 0x00a018eeu); call_indirect(c, t_); } /* call dword ptr [edx + 0x4c] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    if (c->zf) goto L_00a0199b; /* je 0xa0199b */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0xa1015cu; PUSH32(c, v_); } /* push 0x1001015c */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00a01905u); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x5014u; PUSH32(c, v_); } /* push 0x5014 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0xa10158u; PUSH32(c, v_); } /* push 0x10010158 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xffffffd0u)); /* lea esi, [ebp - 0x30] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x98u)); PUSH32(c, 0x00a01933u); call_indirect(c, t_); } /* call dword ptr [edx + 0x98] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp - 4], 0xffffffff */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0xa133f8u; PUSH32(c, v_); } /* push 0x100133f8 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x38u)); PUSH32(c, 0x00a0194au); call_indirect(c, t_); } /* call dword ptr [edx + 0x38] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esi, dword ptr [ebp - 0x18] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x34u)); PUSH32(c, 0x00a01956u); call_indirect(c, t_); } /* call dword ptr [eax + 0x34] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a01966; /* je 0xa01966 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0xa10148u; PUSH32(c, v_); } /* push 0x10010148 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00a01966u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
L_00a01966:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xd4u))); /* mov eax, dword ptr [ebx + 0xd4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0xcu))); /* fld dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    W32((uint32_t)(c->ebx + c->eax * 4 + 0x14u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + eax*4 + 0x14], esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xd4u))); /* mov eax, dword ptr [ebx + 0xd4] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x2u)); /* add eax, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea ecx, [eax + eax*2] */
    WF32((uint32_t)(c->ebx + c->ecx * 4), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + ecx*4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xd4u))); /* mov eax, dword ptr [ebx + 0xd4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebp + 0x10u))); /* fld dword ptr [ebp + 0x10] */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea edx, [eax + eax*2] */
    WF32((uint32_t)(c->ebx + c->edx * 4 + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + edx*4 + 0x1c] */
    { uint32_t a_ = (uint32_t)(c->ebx + 0xd4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebx + 0xd4] */
L_00a0199b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00a0199b(CPU *c) { /* PTR_00a0199b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov ecx, dword ptr [ebp - 0xc] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00a019ae(CPU *c) { /* Catch@100019ae */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    { uint32_t v_ = 0xa133f8u; PUSH32(c, v_); } /* push 0x100133f8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x38u)); PUSH32(c, 0x00a019bbu); call_indirect(c, t_); } /* call dword ptr [eax + 0x38] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xffffffd0u)); /* lea esi, [ebp - 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00a019d6u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    c->eax = (uint32_t)((uint32_t)0xa0199bu); /* mov eax, 0x1000199b */
    c->esp += 4; return; /* ret  */
}

void f_00a019e0(CPU *c) { /* FUN_100019e0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(0xa0e13cu))); /* fld dword ptr [0x1000e13c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx + 0xd4u))); /* mov esi, dword ptr [ecx + 0xd4] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_00a019fe; /* jle 0xa019fe */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x18u)); /* lea eax, [ecx + 0x18] */
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
L_00a019f6:;
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->eax))); /* fadd dword ptr [eax] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00a019f6; /* jne 0xa019f6 */
L_00a019fe:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->zf || c->sf != c->of)) goto L_00a01a20; /* jle 0xa01a20 */
    ST(0) = FPRES(c, FDIV(c, (double)RF32((uint32_t)(0xa0e128u)), ST(0))); /* fdivr dword ptr [0x1000e128] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + 0x18u)); /* lea eax, [ecx + 0x18] */
L_00a01a0d:;
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    WF32((uint32_t)(c->eax + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 0xc] */
    (void)sub32(c, c->edx, R32((uint32_t)(c->ecx + 0xd4u))); /* cmp edx, dword ptr [ecx + 0xd4] */
    if ((c->sf != c->of)) goto L_00a01a0d; /* jl 0xa01a0d */
L_00a01a20:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a01a30(CPU *c) { /* FUN_10001a30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a01a3au); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xd4u))); /* mov eax, dword ptr [esi + 0xd4] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edx, [eax - 1] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e144u))); /* fmul dword ptr [0x1000e144] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e13cu))); /* fld dword ptr [0x1000e13c] */
    if ((c->zf || c->sf != c->of)) goto L_00a01a7b; /* jle 0xa01a7b */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x18u)); /* lea edi, [esi + 0x18] */
L_00a01a64:;
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->edi))); /* fadd dword ptr [edi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_00a01a96; /* jnp 0xa01a96 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xcu)); /* add edi, 0xc */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if ((c->sf != c->of)) goto L_00a01a64; /* jl 0xa01a64 */
L_00a01a7b:;
    c->edx = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea edx, [ecx + ecx*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->edx * 4 + 0x1cu))); /* mov ecx, dword ptr [esi + edx*4 + 0x1c] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->edx * 4)); /* lea eax, [esi + edx*4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
L_00a01a96:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 2)); /* lea eax, [ecx + ecx*2] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea esi, [esi + eax*4] */
    PUSH32(c, 0x00a01aa3u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x8u))); /* fild dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e140u))); /* fmul dword ptr [0x1000e140] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e114u))); /* fadd dword ptr [0x1000e114] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fmul dword ptr [esi + 0x1c] */
    WF32((uint32_t)(c->ecx), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov eax, dword ptr [esi + 0x14] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01ad0(CPU *c) { /* FUN_10001ad0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x40u)); /* sub esp, 0x40 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x30], eax */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x34], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xbdcu))); /* mov eax, dword ptr [esi + 0xbdc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x3c], ebx */
    W32((uint32_t)(c->esp + 0x40u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x40], ebx */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x44], ebx */
    W32((uint32_t)(c->esp + 0x48u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x48], ebx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea eax, [esp + 0x34] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x44u)); PUSH32(c, 0x00a01b0bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x44] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a01c3a; /* je 0xa01c3a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a01b1cu); f_00a02a20(c); /* call 0xa02a20 */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov ecx, dword ptr [esi + 0xc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a01b29u); f_00a029c0(c); /* call 0xa029c0 */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
L_00a01b2d:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x64u)); PUSH32(c, 0x00a01b3du); call_indirect(c, t_); } /* call dword ptr [edx + 0x64] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00a01c3a; /* je 0xa01c3a */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x50u)); PUSH32(c, 0x00a01b4eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x50] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a01b75; /* jne 0xa01b75 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov eax, dword ptr [0x100133fc] */
    { uint32_t v_ = 0xa101d8u; PUSH32(c, v_); } /* push 0x100101d8 */
    { uint32_t v_ = 0xd2u; PUSH32(c, v_); } /* push 0xd2 */
    { uint32_t v_ = 0xa101b0u; PUSH32(c, v_); } /* push 0x100101b0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0xa1017cu; PUSH32(c, v_); } /* push 0x1001017c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00a01b71u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00a01b74u, "int3"); /* int3  */
L_00a01b75:;
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x50u)); PUSH32(c, 0x00a01b7cu); call_indirect(c, t_); } /* call dword ptr [edx + 0x50] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x38u))); /* fsub dword ptr [eax + 0x38] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x34u))); /* fld dword ptr [eax + 0x34] */
    ST(0) = -ST(0); /* fchs  */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->eax + 0x30u))); /* fsub dword ptr [eax + 0x30] */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    { double v_ = ST(3); FPUSH(c, v_); } /* fld st(3) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ecx, [esp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x24u))); /* fmul dword ptr [eax + 0x24] */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x28u))); /* fmul dword ptr [eax + 0x28] */
    ST(2) = FPRES(c, ST(2) + ST(0)); FPOP(c); /* faddp st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x20u))); /* fmul dword ptr [eax + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x54u)); PUSH32(c, 0x00a01bc6u); call_indirect(c, t_); } /* call dword ptr [eax + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e148u))); /* fsub dword ptr [0x1000e148] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x18u))); FPOP(c); /* fcomp dword ptr [esp + 0x18] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_00a01c22; /* je 0xa01c22 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e148u))); /* fadd dword ptr [0x1000e148] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x18u))); FPOP(c); /* fcomp dword ptr [esp + 0x18] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (!PF(c)) goto L_00a01c22; /* jnp 0xa01c22 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e148u))); /* fsub dword ptr [0x1000e148] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x20u))); FPOP(c); /* fcomp dword ptr [esp + 0x20] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (c->zf) goto L_00a01c22; /* je 0xa01c22 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e148u))); /* fadd dword ptr [0x1000e148] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esp + 0x20u))); FPOP(c); /* fcomp dword ptr [esp + 0x20] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01c42; /* jp 0xa01c42 */
L_00a01c22:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x30u)); /* lea eax, [esp + 0x30] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x48u)); PUSH32(c, 0x00a01c32u); call_indirect(c, t_); } /* call dword ptr [edx + 0x48] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00a01b2d; /* jne 0xa01b2d */
L_00a01c3a:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x40u)); /* add esp, 0x40 */
    c->esp += 4; return; /* ret  */
L_00a01c42:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x40u)); /* add esp, 0x40 */
    c->esp += 4; return; /* ret  */
}

void f_00a01c50(CPU *c) { /* FUN_10001c50 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); /* fcom dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01c75; /* jp 0xa01c75 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e13cu))); /* fld dword ptr [0x1000e13c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e14cu))); /* fmul dword ptr [0x1000e14c] */
    WF32((uint32_t)(c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x10] */
    c->esp += 8; return; /* ret 4 */
L_00a01c75:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); /* fcom dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01c8c; /* jne 0xa01c8c */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e128u))); /* fld dword ptr [0x1000e128] */
L_00a01c8c:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e14cu))); /* fmul dword ptr [0x1000e14c] */
    WF32((uint32_t)(c->ecx + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x10] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01ca0(CPU *c) { /* FUN_10001ca0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->ebx = (uint32_t)((uint32_t)0x3f000000u); /* mov ebx, 0x3f000000 */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    W32((uint32_t)(c->ebp), (uint32_t)((uint32_t)0xa0e154u)); /* mov dword ptr [ebp], 0x1000e154 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x14u)); /* lea esi, [ebp + 0x14] */
L_00a01cc3:;
    PUSH32(c, 0x00a01cc8u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 8], 0 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0x44480000u)); /* mov dword ptr [esi + 0xc], 0x44480000 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esi + 0x18], 0xbf800000 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x18u))); /* fild dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e150u))); /* fmul dword ptr [0x1000e150] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    PUSH32(c, 0x00a01d05u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x18u))); /* fild dword ptr [esp + 0x18] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x20u)); /* add esi, 0x20 */
    (void)sub32(c, c->edi, (uint32_t)0x40u); /* cmp edi, 0x40 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x18], edi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e138u))); /* fmul dword ptr [0x1000e138] */
    WF32((uint32_t)(c->esi + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 4] */
    if (c->cf) goto L_00a01cc3; /* jb 0xa01cc3 */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    W32((uint32_t)(c->ebp + 0x4u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [ebp + 4], 0xffffffff */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ebp + 0x10], 0 */
    PUSH32(c, 0x00a01d3du); f_00a02270(c); /* call 0xa02270 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebp); /* mov eax, ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01d50(CPU *c) { /* FUN_10001d50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a01d58u); f_00a01d70(c); /* call 0xa01d70 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a01d68; /* je 0xa01d68 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a01d65u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a01d68:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01d70(CPU *c) { /* FUN_10001d70 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xa0e154u)); /* mov dword ptr [ecx], 0x1000e154 */
    c->esp += 4; return; /* ret  */
}

void f_00a01d80(CPU *c) { /* FUN_10001d80 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e190u))); /* fmul dword ptr [0x1000e190] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x40u)); /* mov dword ptr [esp + 0x10], 0x40 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x1cu)); /* lea esi, [edi + 0x1c] */
L_00a01da3:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fld dword ptr [esi - 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e18cu))); FPOP(c); /* fcomp dword ptr [0x1000e18c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x100u))); /* and eax, 0x100 */
    if (!c->zf) goto L_00a01db8; /* jne 0xa01db8 */
    W32((uint32_t)(c->esi + 0xfffffff8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi - 8], ebx */
L_00a01db8:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fld dword ptr [esi - 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e188u))); /* fmul dword ptr [0x1000e188] */
    FPUSH(c, RF64((uint32_t)(0xa0e180u))); /* fld qword ptr [0x1000e180] */
    PUSH32(c, 0x00a01dccu); f_00a04970(c); /* call 0xa04970 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e178u))); /* fmul dword ptr [0x1000e178] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e174u)) - ST(0)); /* fsubr dword ptr [0x1000e174] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); /* fcom dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01df1; /* jp 0xa01df1 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e13cu))); /* fld dword ptr [0x1000e13c] */
L_00a01df1:;
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffffcu))); /* fadd dword ptr [esi - 4] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esi + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01e1d; /* jne 0xa01e1d */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 4] */
L_00a01e1d:;
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi))); /* fadd dword ptr [esi] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01e44; /* jne 0xa01e44 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
L_00a01e44:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fadd dword ptr [esi - 8] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esi + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e170u))); FPOP(c); /* fcomp dword ptr [0x1000e170] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01e70; /* jp 0xa01e70 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e16cu))); /* fmul dword ptr [0x1000e16c] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
L_00a01e70:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e168u))); FPOP(c); /* fcomp dword ptr [0x1000e168] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01e9c; /* jne 0xa01e9c */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e168u))); /* fsub dword ptr [0x1000e168] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e164u))); /* fmul dword ptr [0x1000e164] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
L_00a01e9c:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01eaf; /* jp 0xa01eaf */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 8], ebx */
L_00a01eaf:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01ec8; /* jne 0xa01ec8 */
    W32((uint32_t)(c->esi + 0x8u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 8], 0x3f800000 */
L_00a01ec8:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x10u))); /* fld dword ptr [esi + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01f30; /* jp 0xa01f30 */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x14u))); /* fadd dword ptr [esi + 0x14] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esi + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x14] */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if ((c->sf == c->of)) goto L_00a01f96; /* jge 0xa01f96 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e160u))); FPOP(c); /* fcomp dword ptr [0x1000e160] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01f96; /* jp 0xa01f96 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e10cu))); FPOP(c); /* fcomp dword ptr [0x1000e10c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a01f96; /* jne 0xa01f96 */
    PUSH32(c, 0x00a01f1du); f_00a0454d(c); /* call 0xa0454d */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fu))); /* and eax, 0x7f */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7u); /* cmp al, 7 */
    if (!c->zf) goto L_00a01f96; /* jne 0xa01f96 */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x10], ebx */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a01f93; /* jmp 0xa01f93 */
L_00a01f30:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e15cu))); /* fmul dword ptr [0x1000e15c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x10u))); /* fadd dword ptr [esi + 0x10] */
    WF32((uint32_t)(c->esp + 0xcu), (float)ST(0)); /* fst dword ptr [esp + 0xc] */
    WF32((uint32_t)(c->esi + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a01f7e; /* jp 0xa01f7e */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e114u))); /* fsub dword ptr [0x1000e114] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e110u))); /* fmul dword ptr [0x1000e110] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e158u))); /* fmul dword ptr [0x1000e158] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e120u))); /* fadd dword ptr [0x1000e120] */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    goto L_00a01f96; /* jmp 0xa01f96 */
L_00a01f7e:;
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esi + 0x14], ebx */
    W32((uint32_t)(c->esi + 0x10u), (uint32_t)((uint32_t)0xbf800000u)); /* mov dword ptr [esi + 0x10], 0xbf800000 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)((uint32_t)0x3f000000u)); /* mov dword ptr [esi + 0xc], 0x3f000000 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x10u))); /* mov eax, dword ptr [edi + 0x10] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00a01f93:;
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0x10], eax */
L_00a01f96:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x20u)); /* add esi, 0x20 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (!c->zf) goto L_00a01da3; /* jne 0xa01da3 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a01fc0(CPU *c) { /* FUN_10001fc0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x6cu)); /* sub esp, 0x6c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov ecx, dword ptr [esp + 0x80] */
    W32((uint32_t)(c->esp + 0x28u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x28], edi */
    c->edx = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov edx, dword ptr [edi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x00a01fdfu); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x824u)); /* lea esi, [edi + 0x824] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x1cu)); /* lea ebx, [edi + 0x1c] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)((uint32_t)0x40u)); /* mov dword ptr [esp + 0x24], 0x40 */
    c->ebp = (uint32_t)((uint32_t)0x3f800000u); /* mov ebp, 0x3f800000 */
    goto L_00a01ffb; /* jmp 0xa01ffb */
L_00a01ff7:;
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
L_00a01ffb:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x4u))); /* mov eax, dword ptr [ebx + 4] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x264u))); /* mov edx, dword ptr [ecx + 0x264] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx))); /* fld dword ptr [ebx] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xfffffffcu))); /* fld dword ptr [ebx - 4] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xfffffffcu))); /* fld dword ptr [ebx - 4] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0xfffffff8u))); /* fmul dword ptr [ebx - 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x268u))); /* fadd dword ptr [ecx + 0x268] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    PUSH32(c, 0x00a0203fu); f_00a02940(c); /* call 0xa02940 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx + 0xfffffff8u))); /* fmul dword ptr [ebx - 8] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xfffffff0u)); /* lea eax, [esi - 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fadd dword ptr [esp + 0x2c] */
    WF32((uint32_t)(c->esp + 0x64u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x64] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x14u))); /* fsub dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x10u))); /* fadd dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); /* fst dword ptr [esp + 0x30] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); /* fst dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esp + 0x50u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x50] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fadd dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ecx, dword ptr [esp + 0x4c] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov edx, dword ptr [esp + 0x50] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x54] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x54u))); /* mov ecx, dword ptr [esp + 0x54] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->esp + 0x44u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x44], edx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 4], eax */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea ecx, [esi + 8] */
    WF32((uint32_t)(c->esp + 0x70u), (float)ST(0)); /* fst dword ptr [esp + 0x70] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov edx, dword ptr [esp + 0x40] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fadd dword ptr [esp + 0x1c] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov edx, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x18], eax */
    W32((uint32_t)(c->esi + 0x34u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x34], eax */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov edx, dword ptr [esp + 0x48] */
    W32((uint32_t)(c->esi + 0x4cu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x4c], eax */
    W32((uint32_t)(c->esi + 0x60u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x60], eax */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x38], ecx */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x20u)); /* lea edx, [esi + 0x20] */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x68u)); /* lea eax, [esi + 0x68] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fadd dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esi + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x1c], ebp */
    W32((uint32_t)(c->esi + 0x30u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x30], ebp */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x14u))); /* fsub dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ecx, dword ptr [esp + 0x34] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x38u)); /* lea edx, [esi + 0x38] */
    W32((uint32_t)(c->esi + 0x48u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x48], ebp */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x64u))); /* fadd dword ptr [esp + 0x64] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ecx, dword ptr [esp + 0x38] */
    W32((uint32_t)(c->esi + 0x64u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x64], ebp */
    W32((uint32_t)(c->esi + 0x78u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x78], ebp */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ecx, dword ptr [esp + 0x3c] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ecx, dword ptr [esp + 0x40] */
    WF32((uint32_t)(c->esp + 0x58u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x58] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0x50u)); /* lea edx, [esi + 0x50] */
    W32((uint32_t)(c->esi + 0x7cu), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 0x7c], ebp */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fadd dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ecx, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ecx, dword ptr [esp + 0x48] */
    WF32((uint32_t)(c->esp + 0x60u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x60] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x58u))); /* mov ecx, dword ptr [esp + 0x58] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x60u))); /* mov ecx, dword ptr [esp + 0x60] */
    W32((uint32_t)(c->esp + 0x5cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x5c], edx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xcu))); /* fld dword ptr [ebx + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e190u))); /* fmul dword ptr [0x1000e190] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x8u))); /* fld dword ptr [ebx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->edi + 0xcu))); /* fmul dword ptr [edi + 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e198u))); /* fmul dword ptr [0x1000e198] */
    PUSH32(c, 0x00a021cfu); f_00a04570(c); /* call 0xa04570 */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e194u))); /* fld dword ptr [0x1000e194] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->edi = (uint32_t)(shl32(c, c->edi, 8)); /* shl edi, 8 */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    PUSH32(c, 0x00a021e1u); f_00a04570(c); /* call 0xa04570 */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e158u))); /* fld dword ptr [0x1000e158] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->eax))); /* or edi, eax */
    c->edi = (uint32_t)(shl32(c, c->edi, 8)); /* shl edi, 8 */
    PUSH32(c, 0x00a021f3u); f_00a04570(c); /* call 0xa04570 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->eax))); /* or edi, eax */
    c->edi = (uint32_t)(shl32(c, c->edi, 8)); /* shl edi, 8 */
    PUSH32(c, 0x00a021fdu); f_00a04570(c); /* call 0xa04570 */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | c->eax))); /* or edi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [esi - 4], edi */
    W32((uint32_t)(c->esi + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x14], edi */
    W32((uint32_t)(c->esi + 0x2cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x2c], edi */
    W32((uint32_t)(c->esi + 0x44u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x44], edi */
    W32((uint32_t)(c->esi + 0x5cu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x5c], edi */
    W32((uint32_t)(c->esi + 0x74u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0x74], edi */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x20u)); /* add ebx, 0x20 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x90u)); /* add esi, 0x90 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    if (!c->zf) goto L_00a01ff7; /* jne 0xa01ff7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x80u))); /* mov eax, dword ptr [esp + 0x80] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xa101ecu; PUSH32(c, v_); } /* push 0x100101ec */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x814u)); /* add ecx, 0x814 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xe8u)); PUSH32(c, 0x00a02259u); call_indirect(c, t_); } /* call dword ptr [edx + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x6cu)); /* add esp, 0x6c */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02270(CPU *c) { /* FUN_10002270 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); /* fcom dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a02295; /* jp 0xa02295 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e13cu))); /* fld dword ptr [0x1000e13c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e14cu))); /* fmul dword ptr [0x1000e14c] */
    WF32((uint32_t)(c->ecx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0xc] */
    c->esp += 8; return; /* ret 4 */
L_00a02295:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); /* fcom dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a022ac; /* jne 0xa022ac */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e128u))); /* fld dword ptr [0x1000e128] */
L_00a022ac:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e14cu))); /* fmul dword ptr [0x1000e14c] */
    WF32((uint32_t)(c->ecx + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0xc] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a022c0(CPU *c) { /* FUN_100022c0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0xa0e1bcu)); /* mov dword ptr [edi], 0x1000e1bc */
    { uint32_t t_ = R32((uint32_t)(0xa0e000u)); PUSH32(c, 0x00a022d5u); call_indirect(c, t_); } /* call dword ptr [0x1000e000] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a022dbu); f_00a04540(c); /* call 0xa04540 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea esi, [edi + 0xc] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00a022e9:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1b8u))); /* fmul dword ptr [0x1000e1b8] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); /* fst dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1b4u))); /* fmul dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00a0230cu); f_00a02960(c); /* call 0xa02960 */
    WF32((uint32_t)(c->esi + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1b0u))); /* fmul dword ptr [0x1000e1b0] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebp)); /* mov dword ptr [esi], ebp */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [esi + 4], ebp */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FPUSH(c, RF64((uint32_t)(0xa0e1a8u))); /* fld qword ptr [0x1000e1a8] */
    PUSH32(c, 0x00a02330u); f_00a04970(c); /* call 0xa04970 */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    (void)sub32(c, c->ebx, (uint32_t)0x18u); /* cmp ebx, 0x18 */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e114u))); /* fsub dword ptr [0x1000e114] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e110u))); /* fmul dword ptr [0x1000e110] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fmul dword ptr [esi - 0x18] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (c->cf) goto L_00a022e9; /* jb 0xa022e9 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1e8u)); /* lea eax, [edi + 0x1e8] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
L_00a0237c:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    (void)sub32(c, c->ecx, (uint32_t)0x10u); /* cmp ecx, 0x10 */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1a0u))); /* fmul dword ptr [0x1000e1a0] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->eax + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->eax + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax - 8] */
    if (c->cf) goto L_00a0237c; /* jb 0xa0237c */
    W32((uint32_t)(c->edi + 0x268u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x268], ebp */
    W32((uint32_t)(c->edi + 0x264u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x264], ebp */
    PUSH32(c, 0x00a023b0u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    PUSH32(c, 0x00a023c7u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x10u))); /* fild dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e19cu))); /* fmul dword ptr [0x1000e19c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e108u))); /* fadd dword ptr [0x1000e108] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->edi + 0x26cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x26c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    WF32((uint32_t)(c->edi + 0x270u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x270] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    PUSH32(c, 0x00a023feu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x274u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x274] */
    PUSH32(c, 0x00a02417u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x278u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x278] */
    PUSH32(c, 0x00a02430u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x27cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x27c] */
    PUSH32(c, 0x00a02449u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x280u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x280] */
    PUSH32(c, 0x00a02462u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x284u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x284] */
    PUSH32(c, 0x00a0247bu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x288u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x288] */
    PUSH32(c, 0x00a02494u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x28cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x28c] */
    PUSH32(c, 0x00a024adu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x18u))); /* fild dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->edi + 0x290u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 0x290] */
    PUSH32(c, 0x00a024cdu); f_00a02b20(c); /* call 0xa02b20 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_00a024e0(CPU *c) { /* FUN_100024e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a024e8u); f_00a02500(c); /* call 0xa02500 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a024f8; /* je 0xa024f8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a024f5u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a024f8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02500(CPU *c) { /* FUN_10002500 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xa0e1bcu)); /* mov dword ptr [ecx], 0x1000e1bc */
    c->esp += 4; return; /* ret  */
}

void f_00a02510(CPU *c) { /* FUN_10002510 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x8u))); /* fld dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x26cu))); /* fmul dword ptr [esi + 0x26c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x264u))); /* fadd dword ptr [esi + 0x264] */
    WF32((uint32_t)(c->esi + 0x264u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x264] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x270u))); /* fmul dword ptr [esi + 0x270] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x268u))); /* fadd dword ptr [esi + 0x268] */
    WF32((uint32_t)(c->esi + 0x268u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x268] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1dcu))); /* fmul dword ptr [0x1000e1dc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x274u))); /* fadd dword ptr [esi + 0x274] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x274u), (float)ST(0)); /* fst dword ptr [esi + 0x274] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a02576; /* jne 0xa02576 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x274u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x274] */
    goto L_00a02578; /* jmp 0xa02578 */
L_00a02576:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a02578:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1d8u))); /* fmul dword ptr [0x1000e1d8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x278u))); /* fadd dword ptr [esi + 0x278] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x278u), (float)ST(0)); /* fst dword ptr [esi + 0x278] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a025ab; /* jne 0xa025ab */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x278u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x278] */
    goto L_00a025ad; /* jmp 0xa025ad */
L_00a025ab:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a025ad:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1d4u))); /* fmul dword ptr [0x1000e1d4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x27cu))); /* fadd dword ptr [esi + 0x27c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x27cu), (float)ST(0)); /* fst dword ptr [esi + 0x27c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a025e0; /* jne 0xa025e0 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x27cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x27c] */
    goto L_00a025e2; /* jmp 0xa025e2 */
L_00a025e0:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a025e2:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1d0u))); /* fmul dword ptr [0x1000e1d0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x280u))); /* fadd dword ptr [esi + 0x280] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x280u), (float)ST(0)); /* fst dword ptr [esi + 0x280] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a02615; /* jne 0xa02615 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x280u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x280] */
    goto L_00a02617; /* jmp 0xa02617 */
L_00a02615:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a02617:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x27cu))); /* fld dword ptr [esi + 0x27c] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1ccu))); /* fadd dword ptr [0x1000e1cc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x284u))); /* fadd dword ptr [esi + 0x284] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x284u), (float)ST(0)); /* fst dword ptr [esi + 0x284] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a02658; /* jne 0xa02658 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x284u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x284] */
    goto L_00a0265a; /* jmp 0xa0265a */
L_00a02658:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a0265a:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x280u))); /* fld dword ptr [esi + 0x280] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e108u))); /* fld dword ptr [0x1000e108] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1c8u))); /* fadd dword ptr [0x1000e1c8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x288u))); /* fadd dword ptr [esi + 0x288] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x288u), (float)ST(0)); /* fst dword ptr [esi + 0x288] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a0269d; /* jne 0xa0269d */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x288u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x288] */
    goto L_00a0269f; /* jmp 0xa0269f */
L_00a0269d:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a0269f:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e128u))); /* fadd dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1c4u))); /* fmul dword ptr [0x1000e1c4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x28cu))); /* fadd dword ptr [esi + 0x28c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x28cu), (float)ST(0)); /* fst dword ptr [esi + 0x28c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a026dc; /* jne 0xa026dc */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x28cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x28c] */
    goto L_00a026de; /* jmp 0xa026de */
L_00a026dc:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a026de:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e120u))); /* fmul dword ptr [0x1000e120] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1c0u))); /* fadd dword ptr [0x1000e1c0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x290u))); /* fadd dword ptr [esi + 0x290] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); /* fcom dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x290u), (float)ST(0)); /* fst dword ptr [esi + 0x290] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a02717; /* jne 0xa02717 */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0x290u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x290] */
    goto L_00a02719; /* jmp 0xa02719 */
L_00a02717:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
L_00a02719:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x10u)); /* lea edi, [esi + 0x10] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
L_00a02722:;
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x18u))); /* fild dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1b8u))); /* fmul dword ptr [0x1000e1b8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1b4u))); /* fmul dword ptr [0x1000e1b4] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebp, dword ptr [esp + 0x18] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00a02742u); f_00a029c0(c); /* call 0xa029c0 */
    WF32((uint32_t)(c->edi + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi - 4] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a0274du); f_00a02a20(c); /* call 0xa02a20 */
    WF32((uint32_t)(c->edi), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x14u)); /* add edi, 0x14 */
    (void)sub32(c, c->ebx, (uint32_t)0x18u); /* cmp ebx, 0x18 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x18], ebx */
    if (c->cf) goto L_00a02722; /* jb 0xa02722 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02770(CPU *c) { /* FUN_10002770 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0x14u)); /* lea esi, [ecx + 0x14] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x18u)); /* mov dword ptr [esp + 0x14], 0x18 */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + 0x1e8u)); /* lea ebx, [ecx + 0x1e8] */
    c->ebp = (uint32_t)((uint32_t)0x10u); /* mov ebp, 0x10 */
    goto L_00a027ac; /* jmp 0xa027ac */
L_00a02797:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ebp = (uint32_t)((uint32_t)0x10u); /* mov ebp, 0x10 */
    c->ebx = (uint32_t)((uint32_t)(c->ecx + 0x1e8u)); /* lea ebx, [ecx + 0x1e8] */
    goto L_00a027ac; /* jmp 0xa027ac */
L_00a027a8:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
L_00a027ac:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0xfffffffcu))); /* fld dword ptr [ebx - 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xfffffff0u))); /* fmul dword ptr [esi - 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fadd dword ptr [esi - 8] */
    WF32((uint32_t)(c->edi), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 4], eax */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff0u))); /* fld dword ptr [esi - 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebx))); /* fmul dword ptr [ebx] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffffcu))); /* fadd dword ptr [esi - 4] */
    WF32((uint32_t)(c->edi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [edi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx + 0x294u))); /* fmul dword ptr [ecx + 0x294] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e120u))); /* fmul dword ptr [0x1000e120] */
    PUSH32(c, 0x00a027dbu); f_00a04570(c); /* call 0xa04570 */
    c->eax = (uint32_t)(shl32(c, c->eax, 24)); /* shl eax, 0x18 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x32323fu))); /* or eax, 0x32323f */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x8u)); /* add ebx, 8 */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0xc], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x10u)); /* add edi, 0x10 */
    c->ebp = (uint32_t)(dec32(c, c->ebp)); /* dec ebp */
    if (!c->zf) goto L_00a027a8; /* jne 0xa027a8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    if (!c->zf) goto L_00a02797; /* jne 0xa02797 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02810(CPU *c) { /* FUN_10002810 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
L_00a02823:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ebx, dword ptr [esp + 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ecx, dword ptr [esp + 0x28] */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 4)); /* shl ebx, 4 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebp = (uint32_t)((uint32_t)0xfff0u); /* mov ebp, 0xfff0 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffffu))); /* and eax, 0xffff */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x10u)); /* lea edi, [ebx + 0x10] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [esp + 0x14], 1 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    c->ebp = (uint32_t)(sub32(c, c->ebp, c->ebx)); /* sub ebp, ebx */
L_00a02850:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(((uint16_t)c->ebp)); /* mov dx, bp */
    c->edx = (c->edx & 0xffff0000u) | (uint16_t)(add16(c, ((uint16_t)c->edx), ((uint16_t)c->edi))); /* add dx, di */
    W16((uint32_t)(c->esi), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [esi], di */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0xfu); /* cmp dx, 0xf */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0xfffffff0u)); /* lea edx, [edi - 0x10] */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    W16((uint32_t)(c->esi + 0xfffffffcu), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esi - 4], dx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->ecx))); /* and eax, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xfffffffcu)); /* lea ecx, [esi - 4] */
    W16((uint32_t)(c->esi + 0x6u), (uint16_t)(((uint16_t)c->edi))); /* mov word ptr [esi + 6], di */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->edx = (uint32_t)((uint32_t)(c->eax + c->ebx)); /* lea edx, [eax + ebx] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax + 0x10u)); /* lea eax, [ebx + eax + 0x10] */
    W16((uint32_t)(c->esi + 0xfffffffeu), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esi - 2], dx */
    W16((uint32_t)(c->esi + 0x2u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esi + 2], dx */
    W16((uint32_t)(c->esi + 0x4u), (uint16_t)(((uint16_t)c->eax))); /* mov word ptr [esi + 4], ax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)((uint32_t)0x6u)); /* mov dword ptr [esp + 0x1c], 6 */
L_00a02892:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov ecx, dword ptr [esp + 0x20] */
    PUSH32(c, 0x00a0289bu); f_00a02920(c); /* call 0xa02920 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov cx, word ptr [edx] */
    (void)sub32(c, c->ecx, c->eax); /* cmp ecx, eax */
    if ((c->sf != c->of)) goto L_00a028cb; /* jl 0xa028cb */
    c->eax = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov eax, dword ptr [0x100133fc] */
    { uint32_t v_ = 0xa10224u; PUSH32(c, v_); } /* push 0x10010224 */
    { uint32_t v_ = 0x86u; PUSH32(c, v_); } /* push 0x86 */
    { uint32_t v_ = 0xa101fcu; PUSH32(c, v_); } /* push 0x100101fc */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = 0xa1017cu; PUSH32(c, v_); } /* push 0x1001017c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00a028c7u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    guest_trap(c, 0x00a028cau, "int3"); /* int3  */
L_00a028cb:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    if (!c->zf) goto L_00a02892; /* jne 0xa02892 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xcu)); /* add esi, 0xc */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    c->edx = (uint32_t)((uint32_t)(c->edi + c->ebp)); /* lea edx, [edi + ebp] */
    (void)sub16(c, ((uint16_t)c->edx), (uint16_t)0x10u); /* cmp dx, 0x10 */
    if (c->cf) goto L_00a02850; /* jb 0xa02850 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, (uint32_t)0x17u); /* cmp eax, 0x17 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    if (c->cf) goto L_00a02823; /* jb 0xa02823 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02920(CPU *c) { /* FUN_10002920 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x180u); /* mov eax, 0x180 */
    c->esp += 4; return; /* ret  */
}

void f_00a02930(CPU *c) { /* FUN_10002930 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x2e0u); /* mov eax, 0x2e0 */
    c->esp += 4; return; /* ret  */
}

void f_00a02940(CPU *c) { /* FUN_10002940 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(0xa0e1b4u))); /* fld dword ptr [0x1000e1b4] */
    c->esp += 4; return; /* ret  */
}

void f_00a02950(CPU *c) { /* FUN_10002950 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1e0u))); /* fmul dword ptr [0x1000e1e0] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02960(CPU *c) { /* FUN_10002960 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1e0u))); /* fmul dword ptr [0x1000e1e0] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); /* fst dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a02985; /* jp 0xa02985 */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 4], 0 */
    goto L_00a029a0; /* jmp 0xa029a0 */
L_00a02985:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a029a0; /* jne 0xa029a0 */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 4], 0x3f800000 */
L_00a029a0:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(0xa0e1e8u))); /* fld qword ptr [0x1000e1e8] */
    PUSH32(c, 0x00a029afu); f_00a04970(c); /* call 0xa04970 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1e4u))); /* fmul dword ptr [0x1000e1e4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e148u))); /* fadd dword ptr [0x1000e148] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a029c0(CPU *c) { /* FUN_100029c0 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1e0u))); /* fmul dword ptr [0x1000e1e0] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x28cu))); /* fld dword ptr [ecx + 0x28c] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1fcu))); /* fmul dword ptr [0x1000e1fc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e174u))); /* fadd dword ptr [0x1000e174] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x274u))); /* fadd dword ptr [ecx + 0x274] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e128u))); /* fld dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1f8u))); /* fmul dword ptr [0x1000e1f8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1f4u))); /* fadd dword ptr [0x1000e1f4] */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1f0u))); /* fmul dword ptr [0x1000e1f0] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x284u))); /* fsub dword ptr [ecx + 0x284] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x264u))); /* fadd dword ptr [ecx + 0x264] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02a20(CPU *c) { /* FUN_10002a20 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1e0u))); /* fmul dword ptr [0x1000e1e0] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x290u))); /* fld dword ptr [ecx + 0x290] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1fcu))); /* fmul dword ptr [0x1000e1fc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e174u))); /* fadd dword ptr [0x1000e174] */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x278u))); /* fadd dword ptr [ecx + 0x278] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e128u))); /* fld dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1f8u))); /* fmul dword ptr [0x1000e1f8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1f4u))); /* fadd dword ptr [0x1000e1f4] */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e118u))); /* fmul dword ptr [0x1000e118] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->ecx + 0x288u))); /* fsub dword ptr [ecx + 0x288] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e200u))); /* fmul dword ptr [0x1000e200] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x268u))); /* fadd dword ptr [ecx + 0x268] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02a90(CPU *c) { /* FUN_10002a90 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    PUSH32(c, 0x00a02aa0u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e208u))); /* fmul dword ptr [0x1000e208] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    PUSH32(c, 0x00a02ab6u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x14u))); /* fild dword ptr [esp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e204u))); /* fmul dword ptr [0x1000e204] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    PUSH32(c, 0x00a02ad3u); f_00a02960(c); /* call 0xa02960 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00a02ae2u); f_00a029c0(c); /* call 0xa029c0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov edx, dword ptr [esi + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); /* fst dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0xcu))); /* fmul dword ptr [esp + 0xc] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    PUSH32(c, 0x00a02afdu); f_00a02a20(c); /* call 0xa02a20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); /* fst dword ptr [esp + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x4u))); /* fmul dword ptr [esp + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02b20(CPU *c) { /* FUN_10002b20 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); /* fcom dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a02b48; /* jp 0xa02b48 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e13cu))); /* fld dword ptr [0x1000e13c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e14cu))); /* fmul dword ptr [0x1000e14c] */
    WF32((uint32_t)(c->ecx + 0x294u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x294] */
    c->esp += 8; return; /* ret 4 */
L_00a02b48:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); /* fcom dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a02b5f; /* jne 0xa02b5f */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e128u))); /* fld dword ptr [0x1000e128] */
L_00a02b5f:;
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e14cu))); /* fmul dword ptr [0x1000e14c] */
    WF32((uint32_t)(c->ecx + 0x294u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ecx + 0x294] */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02b70(CPU *c) { /* DMAInterface */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    W32((uint32_t)(0xa13418u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013418], eax */
    W32((uint32_t)(0xa13400u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013400], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    W32((uint32_t)(0xa133fcu), (uint32_t)(c->ecx)); /* mov dword ptr [0x100133fc], ecx */
    W32((uint32_t)(0xa13404u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013404], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0xa1341cu))); /* mov eax, dword ptr [0x1001341c] */
    c->esp += 4; return; /* ret  */
}

void f_00a02ba0(CPU *c) { /* FUN_10002ba0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00a02bb0u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00a02bc0(CPU *c) { /* FUN_10002bc0 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00a02bdau); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00a02be0(CPU *c) { /* PTR_00a02be0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00a02be5u); f_00a02bf0(c); /* call 0xa02bf0 */
    { f_00a02cd0(c); return; } /* jmp 0xa02cd0 */
}

void f_00a02bf0(CPU *c) { /* PTR_00a02bf0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa1341cu; PUSH32(c, v_); } /* push 0x1001341c */
    c->ecx = (uint32_t)((uint32_t)0xa13408u); /* mov ecx, 0x10013408 */
    PUSH32(c, 0x00a02bffu); f_00a02c00(c); /* call 0xa02c00 */
    c->esp += 4; return; /* ret  */
}

void f_00a02c00(CPU *c) { /* PTR_00a02c00 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xa0e20cu)); /* mov dword ptr [eax], 0x1000e20c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02c20(CPU *c) { /* PTR_00a02c20 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa10244u); /* mov eax, 0x10010244 */
    c->esp += 4; return; /* ret  */
}

void f_00a02c30(CPU *c) { /* FUN_10002c30 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0d3b4u; PUSH32(c, v_); } /* push 0x1000d3b4 */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = 0xa1024cu; PUSH32(c, v_); } /* push 0x1001024c */
    { uint32_t v_ = 0x1bb20u; PUSH32(c, v_); } /* push 0x1bb20 */
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xc], eax */
    PUSH32(c, 0x00a02c5eu); f_00a02bc0(c); /* call 0xa02bc0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->esp), (uint32_t)(c->eax)); /* mov dword ptr [esp], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    if (c->zf) goto L_00a02c87; /* je 0xa02c87 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    PUSH32(c, 0x00a02c78u); f_00a02cf0(c); /* call 0xa02cf0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
L_00a02c87:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00a02ca0(CPU *c) { /* FUN_10002ca0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a02ca8u); f_00a02cc0(c); /* call 0xa02cc0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a02cb8; /* je 0xa02cb8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a02cb5u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a02cb8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02cc0(CPU *c) { /* FUN_10002cc0 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xa0e22cu)); /* mov dword ptr [ecx], 0x1000e22c */
    c->esp += 4; return; /* ret  */
}

void f_00a02cd0(CPU *c) { /* PTR_00a02cd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa02ce0u; PUSH32(c, v_); } /* push 0x10002ce0 */
    PUSH32(c, 0x00a02cdau); f_00a04c0b(c); /* call 0xa04c0b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a02ce0(CPU *c) { /* PTR_00a02ce0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)((uint32_t)0xa13408u); /* mov ecx, 0x10013408 */
    { f_00a02cc0(c); return; } /* jmp 0xa02cc0 */
}

void f_00a02cf0(CPU *c) { /* FUN_10002cf0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0d3efu; PUSH32(c, v_); } /* push 0x1000d3ef */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea edi, [ebx + 4] */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x14], ebx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 4], eax */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 8], ebp */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0xc], ebp */
    W32((uint32_t)(c->edi + 0x10u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x10], ebp */
    W32((uint32_t)(c->edi + 0x14u), (uint32_t)(c->ebp)); /* mov dword ptr [edi + 0x14], ebp */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xa0e270u)); /* mov dword ptr [ebx], 0x1000e270 */
    W32((uint32_t)(c->ebx + 0x1cu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x1c], ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xcu)); PUSH32(c, 0x00a02d41u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x14u)); /* lea edx, [esp + 0x14] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x10u)); PUSH32(c, 0x00a02d51u); call_indirect(c, t_); } /* call dword ptr [eax + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov edx, dword ptr [ebx + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov edx, dword ptr [ebx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4u)); PUSH32(c, 0x00a02d6du); call_indirect(c, t_); } /* call dword ptr [eax + 4] */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x2cu)); /* lea esi, [ebx + 0x2c] */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x34], ebp */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a02d7bu); f_00a022c0(c); /* call 0xa022c0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x2c4u)); /* lea ecx, [ebx + 0x2c4] */
    W8((uint32_t)(c->esp + 0x38u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x38], 1 */
    PUSH32(c, 0x00a02d8cu); f_00a036d0(c); /* call 0xa036d0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x18318u)); /* lea ecx, [ebx + 0x18318] */
    W8((uint32_t)(c->esp + 0x38u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x38], 2 */
    PUSH32(c, 0x00a02d9du); f_00a01ca0(c); /* call 0xa01ca0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x1af2cu)); /* lea ecx, [ebx + 0x1af2c] */
    W8((uint32_t)(c->esp + 0x38u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x38], 3 */
    PUSH32(c, 0x00a02daeu); f_00a01000(c); /* call 0xa01000 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    W32((uint32_t)(c->ebx + 0x1bb18u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x1bb18], eax */
    W32((uint32_t)(c->ebx + 0x1bb1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 0x1bb1c], eax */
    W32((uint32_t)(c->ebx + 0x20u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x20], ebp */
    W32((uint32_t)(c->ebx + 0x1bb0cu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x1bb0c], ebp */
    W32((uint32_t)(c->ebx + 0x24u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x24], ebp */
    W32((uint32_t)(c->ebx + 0x28u), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0x28], ebp */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebx), (uint32_t)((uint32_t)0xa0e24cu)); /* mov dword ptr [ebx], 0x1000e24c */
    W32((uint32_t)(c->ebx + 0x1bb10u), (uint32_t)((uint32_t)0x42700000u)); /* mov dword ptr [ebx + 0x1bb10], 0x42700000 */
    W32((uint32_t)(c->ebx + 0x1bb14u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ebx + 0x1bb14], 0x3f800000 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x28u)); /* add esp, 0x28 */
    c->esp += 4; return; /* ret  */
}

void f_00a02e00(CPU *c) { /* FUN_10002e00 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a02e08u); f_00a02e20(c); /* call 0xa02e20 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a02e18; /* je 0xa02e18 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a02e15u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a02e18:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a02e20(CPU *c) { /* FUN_10002e20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0d43du; PUSH32(c, v_); } /* push 0x1000d43d */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    W32((uint32_t)(c->esp + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [esp + 4], esi */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xa0e24cu)); /* mov dword ptr [esi], 0x1000e24c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x4u)); /* mov dword ptr [esp + 0x10], 4 */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a02ebd; /* je 0xa02ebd */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1bb18u))); /* mov eax, dword ptr [esi + 0x1bb18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a02e65; /* jl 0xa02e65 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x128u)); PUSH32(c, 0x00a02e65u); call_indirect(c, t_); } /* call dword ptr [edx + 0x128] */
L_00a02e65:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1bb1cu))); /* mov eax, dword ptr [esi + 0x1bb1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a02e7b; /* jl 0xa02e7b */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x124u)); PUSH32(c, 0x00a02e7bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x124] */
L_00a02e7b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1831cu))); /* mov eax, dword ptr [esi + 0x1831c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a02e91; /* jl 0xa02e91 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x80u)); PUSH32(c, 0x00a02e91u); call_indirect(c, t_); } /* call dword ptr [edx + 0x80] */
L_00a02e91:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2c8u))); /* mov eax, dword ptr [esi + 0x2c8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a02ea7; /* jl 0xa02ea7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x80u)); PUSH32(c, 0x00a02ea7u); call_indirect(c, t_); } /* call dword ptr [edx + 0x80] */
L_00a02ea7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x2ccu))); /* mov eax, dword ptr [esi + 0x2cc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf != c->of)) goto L_00a02ebd; /* jl 0xa02ebd */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x80u)); PUSH32(c, 0x00a02ebdu); call_indirect(c, t_); } /* call dword ptr [edx + 0x80] */
L_00a02ebd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov ecx, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a02ed1; /* je 0xa02ed1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a02ed1; /* je 0xa02ed1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x2cu)); PUSH32(c, 0x00a02ed1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x2c] */
L_00a02ed1:;
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1af2cu)); /* lea ecx, [esi + 0x1af2c] */
    W8((uint32_t)(c->esp + 0x10u), (uint8_t)((uint8_t)0x3u)); /* mov byte ptr [esp + 0x10], 3 */
    PUSH32(c, 0x00a02ee1u); f_00a01070(c); /* call 0xa01070 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x18318u)); /* lea ecx, [esi + 0x18318] */
    W8((uint32_t)(c->esp + 0x10u), (uint8_t)((uint8_t)0x2u)); /* mov byte ptr [esp + 0x10], 2 */
    PUSH32(c, 0x00a02ef1u); f_00a01d70(c); /* call 0xa01d70 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2c4u)); /* lea ecx, [esi + 0x2c4] */
    W8((uint32_t)(c->esp + 0x10u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [esp + 0x10], 1 */
    PUSH32(c, 0x00a02f01u); f_00a03900(c); /* call 0xa03900 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2cu)); /* lea ecx, [esi + 0x2c] */
    W8((uint32_t)(c->esp + 0x10u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [esp + 0x10], 0 */
    PUSH32(c, 0x00a02f0eu); f_00a02500(c); /* call 0xa02500 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xa0e270u)); /* mov dword ptr [esi], 0x1000e270 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0xffffffffu)); /* mov dword ptr [esp + 0x14], 0xffffffff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00a02f2bu); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00a02f40(CPU *c) { /* PTR_00a02f40 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0d45bu; PUSH32(c, v_); } /* push 0x1000d45b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x260u)); /* sub esp, 0x260 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0xa1032cu; PUSH32(c, v_); } /* push 0x1001032c */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x9cu)); PUSH32(c, 0x00a02f78u); call_indirect(c, t_); } /* call dword ptr [eax + 0x9c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0xa1032cu; PUSH32(c, v_); } /* push 0x1001032c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xc0u)); PUSH32(c, 0x00a02f8du); call_indirect(c, t_); } /* call dword ptr [edx + 0xc0] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0xa10324u; PUSH32(c, v_); } /* push 0x10010324 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x9cu)); PUSH32(c, 0x00a02fa4u); call_indirect(c, t_); } /* call dword ptr [eax + 0x9c] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0xa10324u; PUSH32(c, v_); } /* push 0x10010324 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xc4u)); PUSH32(c, 0x00a02fb9u); call_indirect(c, t_); } /* call dword ptr [edx + 0xc4] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    { uint32_t v_ = 0x11170u; PUSH32(c, v_); } /* push 0x11170 */
    c->ebx = (uint32_t)((uint32_t)(c->ebp + 0x4u)); /* lea ebx, [ebp + 4] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = 0xa1032cu; PUSH32(c, v_); } /* push 0x1001032c */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00a02fe3u); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    { uint32_t v_ = 0x11170u; PUSH32(c, v_); } /* push 0x11170 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    { uint32_t v_ = 0xa10324u; PUSH32(c, v_); } /* push 0x10010324 */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xb0u)); PUSH32(c, 0x00a0300au); call_indirect(c, t_); } /* call dword ptr [edx + 0xb0] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = 0xa10318u; PUSH32(c, v_); } /* push 0x10010318 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00a0301au); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->ebp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x20], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a030af; /* jne 0xa030af */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x18u)); PUSH32(c, 0x00a03032u); call_indirect(c, t_); } /* call dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov eax, dword ptr [0x100133fc] */
    { uint32_t v_ = 0xa10300u; PUSH32(c, v_); } /* push 0x10010300 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00a03042u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov eax, dword ptr [0x100133fc] */
    { uint32_t v_ = 0x3eu; PUSH32(c, v_); } /* push 0x3e */
    { uint32_t v_ = 0xa1024cu; PUSH32(c, v_); } /* push 0x1001024c */
    { uint32_t v_ = 0xa102f4u; PUSH32(c, v_); } /* push 0x100102f4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); PUSH32(c, 0x00a03059u); call_indirect(c, t_); } /* call dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov eax, dword ptr [0x100133fc] */
    { uint32_t v_ = 0xa102dcu; PUSH32(c, v_); } /* push 0x100102dc */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0x14u)); PUSH32(c, 0x00a03069u); call_indirect(c, t_); } /* call dword ptr [ecx + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esp + 0x144u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x144], edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a03075:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0xa102dcu))); /* mov cl, byte ptr [eax + 0x100102dc] */
    W8((uint32_t)(c->esp + c->eax + 0x20u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esp + eax + 0x20], cl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00a03075; /* jne 0xa03075 */
    W32((uint32_t)(c->esp + 0x278u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x278], edi */
    c->ecx = (uint32_t)((uint32_t)0x4au); /* mov ecx, 0x4a */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea esi, [esp + 0x20] */
    c->edi = (uint32_t)((uint32_t)(c->esp + 0x148u)); /* lea edi, [esp + 0x148] */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x148u)); /* lea edx, [esp + 0x148] */
    { uint32_t v_ = 0xa0ebacu; PUSH32(c, v_); } /* push 0x1000ebac */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a030afu); f_00a04c91(c); /* call 0xa04c91 */
L_00a030af:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ebx, dword ptr [eax] */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0x2cu)); /* lea esi, [ebp + 0x2c] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a030bdu); f_00a02930(c); /* call 0xa02930 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 2)); /* lea eax, [eax + eax*2] */
    c->eax = (uint32_t)(add32(c, c->eax, c->eax)); /* add eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x104u)); PUSH32(c, 0x00a030ccu); call_indirect(c, t_); } /* call dword ptr [ebx + 0x104] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->ebp + 0x1bb18u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1bb18], eax */
    if ((c->sf == c->of)) goto L_00a030dd; /* jge 0xa030dd */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    goto L_00a031f6; /* jmp 0xa031f6 */
L_00a030dd:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a030ebu); f_00a02920(c); /* call 0xa02920 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x42u; PUSH32(c, v_); } /* push 0x42 */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x100u)); PUSH32(c, 0x00a030fau); call_indirect(c, t_); } /* call dword ptr [ebx + 0x100] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->ebp + 0x1bb1cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1bb1c], eax */
    if ((c->sf == c->of)) goto L_00a0310b; /* jge 0xa0310b */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    goto L_00a031f6; /* jmp 0xa031f6 */
L_00a0310b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1bb18u))); /* mov eax, dword ptr [ebp + 0x1bb18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x11cu)); PUSH32(c, 0x00a0311eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x11c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a03129; /* jne 0xa03129 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    goto L_00a031f6; /* jmp 0xa031f6 */
L_00a03129:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a03131u); f_00a02810(c); /* call 0xa02810 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1bb18u))); /* mov eax, dword ptr [ebp + 0x1bb18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x120u)); PUSH32(c, 0x00a03143u); call_indirect(c, t_); } /* call dword ptr [edx + 0x120] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    { uint32_t v_ = 0xa102c4u; PUSH32(c, v_); } /* push 0x100102c4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x78u)); PUSH32(c, 0x00a03150u); call_indirect(c, t_); } /* call dword ptr [edx + 0x78] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0x1831cu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x1831c], eax */
    { uint32_t v_ = 0xa102acu; PUSH32(c, v_); } /* push 0x100102ac */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x78u)); PUSH32(c, 0x00a03163u); call_indirect(c, t_); } /* call dword ptr [eax + 0x78] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x20u))); /* mov ecx, dword ptr [ebp + 0x20] */
    W32((uint32_t)(c->ebp + 0x2c8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x2c8], eax */
    { uint32_t v_ = 0xa10294u; PUSH32(c, v_); } /* push 0x10010294 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x78u)); PUSH32(c, 0x00a03176u); call_indirect(c, t_); } /* call dword ptr [edx + 0x78] */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0x1af2cu)); /* lea ecx, [ebp + 0x1af2c] */
    W32((uint32_t)(c->ebp + 0x2ccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x2cc], eax */
    PUSH32(c, 0x00a03187u); f_00a010d0(c); /* call 0xa010d0 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13400u))); /* mov ecx, dword ptr [0x10013400] */
    { uint32_t v_ = 0xa10048u; PUSH32(c, v_); } /* push 0x10010048 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x4cu)); PUSH32(c, 0x00a03197u); call_indirect(c, t_); } /* call dword ptr [eax + 0x4c] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    W32((uint32_t)(c->ebp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x24], eax */
    if (c->zf) goto L_00a031f4; /* je 0xa031f4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a031a6u); f_00a029c0(c); /* call 0xa029c0 */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    PUSH32(c, 0x00a031b2u); f_00a02a20(c); /* call 0xa02a20 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x20u)); /* lea eax, [esp + 0x20] */
    { uint32_t v_ = 0xbf800000u; PUSH32(c, v_); } /* push 0xbf800000 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x2c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov ecx, dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->esp + 0x3cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x3c], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0xa1028cu; PUSH32(c, v_); } /* push 0x1001028c */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x1cu)); PUSH32(c, 0x00a031f1u); call_indirect(c, t_); } /* call dword ptr [edx + 0x1c] */
    W32((uint32_t)(c->ebp + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x28], eax */
L_00a031f4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
L_00a031f6:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x270u))); /* mov ecx, dword ptr [esp + 0x270] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x26cu)); /* add esp, 0x26c */
    c->esp += 4; return; /* ret  */
}

void f_00a03210(CPU *c) { /* PTR_00a03210 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x14], edi */
    FPUSH(c, (double)(int64_t)R64((uint32_t)(c->esp + 0x10u))); /* fild qword ptr [esp + 0x10] */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e294u))); /* fmul dword ptr [0x1000e294] */
    c->ebp = (uint32_t)((uint32_t)(c->ebx + 0x2cu)); /* lea ebp, [ebx + 0x2c] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov esi, dword ptr [esp + 0x20] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a03244u); f_00a02510(c); /* call 0xa02510 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x2c4u)); /* lea ecx, [ebx + 0x2c4] */
    PUSH32(c, 0x00a03250u); f_00a03910(c); /* call 0xa03910 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x18318u)); /* lea ecx, [ebx + 0x18318] */
    PUSH32(c, 0x00a0325cu); f_00a01d80(c); /* call 0xa01d80 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + 0x1af2cu)); /* lea ecx, [ebx + 0x1af2c] */
    PUSH32(c, 0x00a03268u); f_00a01200(c); /* call 0xa01200 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ebx + 0x1bb0cu))); /* fadd dword ptr [ebx + 0x1bb0c] */
    WF32((uint32_t)(c->ebx + 0x1bb0cu), (float)ST(0)); /* fst dword ptr [ebx + 0x1bb0c] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a032cf; /* jne 0xa032cf */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov ecx, dword ptr [0x10013418] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov esi, dword ptr [ecx] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00a03297u); f_00a02a20(c); /* call 0xa02a20 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a032a5u); f_00a029c0(c); /* call 0xa029c0 */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    c->edx = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov edx, dword ptr [0x10013418] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x1bb0cu))); /* fld dword ptr [ebx + 0x1bb0c] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    { uint32_t v_ = 0xa10354u; PUSH32(c, v_); } /* push 0x10010354 */
    { uint32_t v_ = 0xa10344u; PUSH32(c, v_); } /* push 0x10010344 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t t_ = R32((uint32_t)(c->esi + 0xecu)); PUSH32(c, 0x00a032ccu); call_indirect(c, t_); } /* call dword ptr [esi + 0xec] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
L_00a032cf:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x1bb10u))); /* fld dword ptr [ebx + 0x1bb10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a0334a; /* jp 0xa0334a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x1bb14u))); /* mov eax, dword ptr [ebx + 0x1bb14] */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a032f0u); f_00a03530(c); /* call 0xa03530 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e120u))); /* fmul dword ptr [0x1000e120] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(c->ebx + 0x1bb14u)) - ST(0)); /* fsubr dword ptr [ebx + 0x1bb14] */
    WF32((uint32_t)(c->ebx + 0x1bb14u), (float)ST(0)); /* fst dword ptr [ebx + 0x1bb14] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a0335a; /* jp 0xa0335a */
    W32((uint32_t)(c->ebx + 0x1bb14u), (uint32_t)(c->edi)); /* mov dword ptr [ebx + 0x1bb14], edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0xa10334u; PUSH32(c, v_); } /* push 0x10010334 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xecu)); PUSH32(c, 0x00a0332du); call_indirect(c, t_); } /* call dword ptr [ecx + 0xec] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13418u))); /* mov eax, dword ptr [0x10013418] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->esi = (uint32_t)((uint32_t)(c->ebx + 0x4u)); /* lea esi, [ebx + 4] */
    c->ecx = (uint32_t)((uint32_t)0x6u); /* mov ecx, 6 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->edi = (uint32_t)(c->esp); /* mov edi, esp */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x60u)); PUSH32(c, 0x00a03348u); call_indirect(c, t_); } /* call dword ptr [edx + 0x60] */
    goto L_00a0335a; /* jmp 0xa0335a */
L_00a0334a:;
    FPUSH(c, (double)RF32((uint32_t)(c->ebx + 0x1bb10u))); /* fld dword ptr [ebx + 0x1bb10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x20u))); /* fsub dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->ebx + 0x1bb10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebx + 0x1bb10] */
L_00a0335a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov eax, dword ptr [ebx + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a033a5; /* je 0xa033a5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x28u))); /* mov eax, dword ptr [ebx + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a033a5; /* je 0xa033a5 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00a03371u); f_00a02a20(c); /* call 0xa02a20 */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    PUSH32(c, 0x00a0337eu); f_00a029c0(c); /* call 0xa029c0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov ecx, dword ptr [ebx + 0x24] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x18], eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea eax, [esp + 0x10] */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x28u))); /* mov eax, dword ptr [ebx + 0x28] */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x24u)); PUSH32(c, 0x00a033a5u); call_indirect(c, t_); } /* call dword ptr [edx + 0x24] */
L_00a033a5:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
}

void f_00a033b0(CPU *c) { /* PTR_00a033b0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x44u)); /* sub esp, 0x44 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov eax, dword ptr [esi + 0x20] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1af2cu)); /* lea ecx, [esi + 0x1af2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->esi + 0x1bb10u), (uint32_t)((uint32_t)0x447a0000u)); /* mov dword ptr [esi + 0x1bb10], 0x447a0000 */
    PUSH32(c, 0x00a033d0u); f_00a016a0(c); /* call 0xa016a0 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ecx, [esp + 0xc] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)((uint32_t)0x3f800000u); /* mov ecx, 0x3f800000 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x18], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x20], ebx */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x24], ebx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x28], ecx */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x2c], ebx */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x30], ebx */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x34], ebx */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x38], ebx */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x3c], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea eax, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00a03424u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x18318u)); /* lea ecx, [esi + 0x18318] */
    PUSH32(c, 0x00a03433u); f_00a01fc0(c); /* call 0xa01fc0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1bb1cu))); /* mov eax, dword ptr [esi + 0x1bb1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x110u)); PUSH32(c, 0x00a03447u); call_indirect(c, t_); } /* call dword ptr [edx + 0x110] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_00a034d7; /* je 0xa034d7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00a0345eu); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0x2cu)); /* lea edi, [esi + 0x2c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00a03469u); f_00a02770(c); /* call 0xa02770 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1bb1cu))); /* mov edx, dword ptr [esi + 0x1bb1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x114u)); PUSH32(c, 0x00a0347bu); call_indirect(c, t_); } /* call dword ptr [eax + 0x114] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = 0x42u; PUSH32(c, v_); } /* push 0x42 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x1b8u)); PUSH32(c, 0x00a03488u); call_indirect(c, t_); } /* call dword ptr [eax + 0x1b8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xa10358u; PUSH32(c, v_); } /* push 0x10010358 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ebx, dword ptr [ecx] */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00a0349bu); f_00a02930(c); /* call 0xa02930 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00a034a5u); f_00a02920(c); /* call 0xa02920 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x1bb18u))); /* mov edx, dword ptr [esi + 0x1bb18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov ecx, dword ptr [esi + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1bb1cu))); /* mov eax, dword ptr [esi + 0x1bb1c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0xdcu)); PUSH32(c, 0x00a034c4u); call_indirect(c, t_); } /* call dword ptr [ebx + 0xdc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x20u))); /* mov edx, dword ptr [esi + 0x20] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2c4u)); /* lea ecx, [esi + 0x2c4] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a034d6u); f_00a03cc0(c); /* call 0xa03cc0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a034d7:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x44u)); /* add esp, 0x44 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a034e0(CPU *c) { /* PTR_00a034e0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x14u)); PUSH32(c, 0x00a034e9u); call_indirect(c, t_); } /* call dword ptr [eax + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    WF32((uint32_t)(c->ecx + 0x1bb10u), (float)ST(0)); /* fst dword ptr [ecx + 0x1bb10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e10cu))); FPOP(c); /* fcomp dword ptr [0x1000e10c] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a0350a; /* jp 0xa0350a */
    W32((uint32_t)(c->ecx + 0x1bb10u), (uint32_t)((uint32_t)0x40a00000u)); /* mov dword ptr [ecx + 0x1bb10], 0x40a00000 */
L_00a0350a:;
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x1bb10u))); /* fld dword ptr [ecx + 0x1bb10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e298u))); FPOP(c); /* fcomp dword ptr [0x1000e298] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03529; /* jne 0xa03529 */
    W32((uint32_t)(c->ecx + 0x1bb10u), (uint32_t)((uint32_t)0x45610000u)); /* mov dword ptr [ecx + 0x1bb10], 0x45610000 */
L_00a03529:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00a03530(CPU *c) { /* FUN_10003530 */
    PREEMPT_POLL(c);
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x4u))); /* fld dword ptr [esp + 4] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e13cu))); FPOP(c); /* fcomp dword ptr [0x1000e13c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a0354f; /* jp 0xa0354f */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0xc], 0 */
    goto L_00a0356a; /* jmp 0xa0356a */
L_00a0354f:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0xcu))); /* fld dword ptr [esp + 0xc] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a0356a; /* jne 0xa0356a */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esp + 0xc], 0x3f800000 */
L_00a0356a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2cu)); /* lea ecx, [esi + 0x2c] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->esi + 0x1bb14u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1bb14], eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a0357fu); f_00a02b20(c); /* call 0xa02b20 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x2c4u)); /* lea ecx, [esi + 0x2c4] */
    PUSH32(c, 0x00a0358bu); f_00a01c50(c); /* call 0xa01c50 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x18318u)); /* lea ecx, [esi + 0x18318] */
    PUSH32(c, 0x00a03597u); f_00a02270(c); /* call 0xa02270 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0x1af2cu)); /* lea ecx, [esi + 0x1af2c] */
    PUSH32(c, 0x00a035a3u); f_00a01c50(c); /* call 0xa01c50 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a035b0(CPU *c) { /* FUN_100035b0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xa0e270u)); /* mov dword ptr [eax], 0x1000e270 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov eax, dword ptr [eax + 0x14] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x8u)); PUSH32(c, 0x00a035c7u); call_indirect(c, t_); } /* call dword ptr [edx + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00a035d0(CPU *c) { /* PTR_00a035d0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00a035e0(CPU *c) { /* PTR_00a035e0 */
    PREEMPT_POLL(c);
    c->esp += 8; return; /* ret 4 */
}

void f_00a035f0(CPU *c) { /* PTR_00a035f0 */
    PREEMPT_POLL(c);
    c->esp += 16; return; /* ret 0xc */
}

void f_00a03600(CPU *c) { /* PTR_00a03600 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((uint8_t)0x1u); /* mov al, 1 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a03610(CPU *c) { /* PTR_00a03610 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 8; return; /* ret 4 */
}

void f_00a03620(CPU *c) { /* FUN_10003620 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0x14u))); /* mov edx, dword ptr [esi + 0x14] */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xa0e270u)); /* mov dword ptr [esi], 0x1000e270 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa133fcu))); /* mov ecx, dword ptr [0x100133fc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x8u)); PUSH32(c, 0x00a03638u); call_indirect(c, t_); } /* call dword ptr [eax + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a03648; /* je 0xa03648 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a03645u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a03648:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a03650(CPU *c) { /* PTR_00a03650 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00a03660(CPU *c) { /* PTR_00a03660 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00a03670(CPU *c) { /* PTR_00a03670 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ecx + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00a03680(CPU *c) { /* PTR_00a03680 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov eax, dword ptr [ecx + 0xc] */
    c->esp += 4; return; /* ret  */
}

void f_00a03690(CPU *c) { /* PTR_00a03690 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx + 0xcu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [ecx + 0xc], 0 */
    c->esp += 4; return; /* ret  */
}

void f_00a036a0(CPU *c) { /* PTR_00a036a0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, 0)); /* xor al, al */
    c->esp += 4; return; /* ret  */
}

void f_00a036b0(CPU *c) { /* PTR_00a036b0 */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x4u))); /* mov al, byte ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xa0e22cu)); /* mov dword ptr [esi], 0x1000e22c */
    if (c->zf) goto L_00a036ca; /* je 0xa036ca */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a036c7u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a036ca:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a036d0(CPU *c) { /* FUN_100036d0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0x14u)); /* lea ecx, [edi + 0x14] */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + 0xc], eax */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x20], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)0x3f800000u); /* mov ecx, 0x3f800000 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x18], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x20], ebx */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x24], ebx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x28], ecx */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x2c], ebx */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x30], ebx */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x34], ebx */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x38], ebx */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x3c], ecx */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x14], 0 */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebp, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edi), (uint32_t)((uint32_t)0xa0e2acu)); /* mov dword ptr [edi], 0x1000e2ac */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x10], 0 */
    W32((uint32_t)(c->esp + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esp + 0x18], 0 */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x64u)); /* lea esi, [edi + 0x64] */
    c->ebx = (uint32_t)((uint32_t)0x200u); /* mov ebx, 0x200 */
L_00a0374b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xfffffff0u)); /* lea edx, [esi - 0x10] */
    W32((uint32_t)(c->esi + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [esi - 0x10], eax */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    PUSH32(c, 0x00a03764u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x3f333333u)); /* mov dword ptr [esi + 4], 0x3f333333 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2a8u))); /* fmul dword ptr [0x1000e2a8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e194u))); /* fadd dword ptr [0x1000e194] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2a4u))); /* fmul dword ptr [0x1000e2a4] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    PUSH32(c, 0x00a0378cu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->esi + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 4] */
    PUSH32(c, 0x00a037a2u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2a0u))); /* fmul dword ptr [0x1000e2a0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e158u))); /* fadd dword ptr [0x1000e158] */
    WF32((uint32_t)(c->esi + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 8] */
    PUSH32(c, 0x00a037beu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->esi + 0xcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0xc] */
    PUSH32(c, 0x00a037d4u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e29cu))); /* fmul dword ptr [0x1000e29c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e118u))); /* fadd dword ptr [0x1000e118] */
    WF32((uint32_t)(c->esi + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x10] */
    PUSH32(c, 0x00a037f0u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    W32((uint32_t)(c->esi + 0x18u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0x18], 0 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e144u))); /* fmul dword ptr [0x1000e144] */
    WF32((uint32_t)(c->esi + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 0x14] */
    PUSH32(c, 0x00a0380du); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x30u)); /* add esi, 0x30 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e138u))); /* fmul dword ptr [0x1000e138] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e174u))); /* fadd dword ptr [0x1000e174] */
    WF32((uint32_t)(c->esi + 0xffffffecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x14] */
    if (!c->zf) goto L_00a0374b; /* jne 0xa0374b */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x6070u)); /* lea esi, [edi + 0x6070] */
    c->ebx = (uint32_t)((uint32_t)0x400u); /* mov ebx, 0x400 */
L_00a03839:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xffffffe4u)); /* lea edx, [esi - 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a03845u); f_00a02a90(c); /* call 0xa02a90 */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    PUSH32(c, 0x00a0384cu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    W32((uint32_t)(c->esi + 0xfffffff8u), (uint32_t)((uint32_t)0x3f333333u)); /* mov dword ptr [esi - 8], 0x3f333333 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2a8u))); /* fmul dword ptr [0x1000e2a8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e194u))); /* fadd dword ptr [0x1000e194] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1f4u))); /* fmul dword ptr [0x1000e1f4] */
    WF32((uint32_t)(c->esi + 0xfffffff4u), (float)ST(0)); /* fst dword ptr [esi - 0xc] */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi + 4] */
    PUSH32(c, 0x00a03878u); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e134u))); /* fmul dword ptr [0x1000e134] */
    WF32((uint32_t)(c->esi + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x10] */
    PUSH32(c, 0x00a0388eu); f_00a0454d(c); /* call 0xa0454d */
    W32((uint32_t)(c->esp + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x20], eax */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    FPUSH(c, (double)(int32_t)R32((uint32_t)(c->esp + 0x20u))); /* fild dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2a0u))); /* fmul dword ptr [0x1000e2a0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e158u))); /* fadd dword ptr [0x1000e158] */
    WF32((uint32_t)(c->esi + 0xffffffd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x28] */
    if (!c->zf) goto L_00a03839; /* jne 0xa03839 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00a038b4u); f_00a03910(c); /* call 0xa03910 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    { uint32_t v_ = 0x3f800000u; PUSH32(c, v_); } /* push 0x3f800000 */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 8], eax */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + 4], eax */
    PUSH32(c, 0x00a038c9u); f_00a01c50(c); /* call 0xa01c50 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 8; return; /* ret 4 */
}

void f_00a038e0(CPU *c) { /* FUN_100038e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a038e8u); f_00a03900(c); /* call 0xa03900 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a038f8; /* je 0xa038f8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a038f5u); f_00a02ba0(c); /* call 0xa02ba0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_00a038f8:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a03900(CPU *c) { /* FUN_10003900 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ecx), (uint32_t)((uint32_t)0xa0e2acu)); /* mov dword ptr [ecx], 0x1000e2ac */
    c->esp += 4; return; /* ret  */
}

void f_00a03910(CPU *c) { /* FUN_10003910 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1c4u))); /* fmul dword ptr [0x1000e1c4] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    c->ebp = (uint32_t)((uint32_t)0x200u); /* mov ebp, 0x200 */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x78u)); /* lea esi, [edi + 0x78] */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0x606cu)); /* lea ebx, [edi + 0x606c] */
L_00a03935:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4u))); /* fadd dword ptr [esi + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x14], eax */
    WF32((uint32_t)(c->esi + 0x4u), (float)ST(0)); /* fst dword ptr [esi + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi))); /* fadd dword ptr [esi] */
    WF32((uint32_t)(c->esi), (float)ST(0)); /* fst dword ptr [esi] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e128u))); FPOP(c); /* fcomp dword ptr [0x1000e128] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a0396d; /* jne 0xa0396d */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi], 0 */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 4], 0 */
L_00a0396d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1f4u))); /* fmul dword ptr [0x1000e1f4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1d0u))); /* fadd dword ptr [0x1000e1d0] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fadd dword ptr [esi - 8] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esi + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a039b5; /* jne 0xa039b5 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 8] */
L_00a039b5:;
    FPUSH(c, (double)RF32((uint32_t)(0xa0e128u))); /* fld dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xfffffffcu))); /* fmul dword ptr [esi - 4] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x8u))); /* fld dword ptr [esi + 8] */
    PUSH32(c, 0x00a039d2u); f_00a04970(c); /* call 0xa04970 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2c8u))); /* fmul dword ptr [0x1000e2c8] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); /* fst dword ptr [esp + 0x20] */
    WF32((uint32_t)(c->esi + 0xffffffe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fld dword ptr [esi - 8] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov edx, dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    PUSH32(c, 0x00a039f5u); f_00a029c0(c); /* call 0xa029c0 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe0u))); /* mov eax, dword ptr [esi - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esi + 0xffffffdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff8u))); /* fld dword ptr [esi - 8] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    PUSH32(c, 0x00a03a17u); f_00a02a20(c); /* call 0xa02a20 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x24u))); /* fld dword ptr [esp + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x18u))); /* fmul dword ptr [esp + 0x18] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    WF32((uint32_t)(c->esi + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x10u))); /* fmul dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e10cu))); /* fmul dword ptr [0x1000e10c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e1dcu))); /* fadd dword ptr [0x1000e1dc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fadd dword ptr [esi - 0x18] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03a6a; /* jne 0xa03a6a */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
L_00a03a6a:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e198u))); FPOP(c); /* fcomp dword ptr [0x1000e198] */
    W32((uint32_t)(c->esi + 0xfffffff0u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi - 0x10], 0x3f800000 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a03a8f; /* jp 0xa03a8f */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2c4u))); /* fmul dword ptr [0x1000e2c4] */
    WF32((uint32_t)(c->esi + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x10] */
L_00a03a8f:;
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e114u))); FPOP(c); /* fcomp dword ptr [0x1000e114] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03abe; /* jne 0xa03abe */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e158u))); /* fsub dword ptr [0x1000e158] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e10cu))); /* fmul dword ptr [0x1000e10c] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xfffffff0u))); /* fmul dword ptr [esi - 0x10] */
    WF32((uint32_t)(c->esi + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x10] */
L_00a03abe:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe0u))); /* fld dword ptr [esi - 0x20] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e108u))); FPOP(c); /* fcomp dword ptr [0x1000e108] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03aeb; /* jne 0xa03aeb */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xffffffe0u))); /* fld dword ptr [esi - 0x20] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e108u))); /* fsub dword ptr [0x1000e108] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2c0u))); /* fmul dword ptr [0x1000e2c0] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0xfffffff0u))); /* fmul dword ptr [esi - 0x10] */
    WF32((uint32_t)(c->esi + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x10] */
L_00a03aeb:;
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x30u)); /* add esi, 0x30 */
    c->ebp = (uint32_t)(dec32(c, c->ebp)); /* dec ebp */
    if (!c->zf) goto L_00a03935; /* jne 0xa03935 */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x6070u)); /* lea esi, [edi + 0x6070] */
    c->ebx = (uint32_t)((uint32_t)0x400u); /* mov ebx, 0x400 */
L_00a03b03:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe8u))); /* mov ecx, dword ptr [esi - 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    PUSH32(c, 0x00a03b0fu); f_00a02950(c); /* call 0xa02950 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * ST(1)); /* fmul st(1) */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov edx, dword ptr [esi - 4] */
    W32((uint32_t)(c->esp + 0x14u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x14], edx */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fld dword ptr [esp + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2bcu))); /* fmul dword ptr [0x1000e2bc] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(0xa0e118u))); /* fadd dword ptr [0x1000e118] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); /* fadd dword ptr [esi - 0x18] */
    WF32((uint32_t)(c->esi + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    PUSH32(c, 0x00a03b46u); f_00a02940(c); /* call 0xa02940 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(c->esi + 0xffffffe8u))); FPOP(c); /* fcomp dword ptr [esi - 0x18] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x41u)); /* test ah, 0x41 */
    if (PF(c)) goto L_00a03b57; /* jp 0xa03b57 */
    W32((uint32_t)(c->esi + 0xffffffe8u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi - 0x18], 0 */
L_00a03b57:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe8u))); /* mov eax, dword ptr [esi - 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a03b63u); f_00a029c0(c); /* call 0xa029c0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe8u))); /* mov ecx, dword ptr [esi - 0x18] */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    PUSH32(c, 0x00a03b73u); f_00a02a20(c); /* call 0xa02a20 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe8u))); /* mov edx, dword ptr [esi - 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a03b83u); f_00a02960(c); /* call 0xa02960 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xfffffff4u))); /* fld dword ptr [esi - 0xc] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e12cu))); /* fmul dword ptr [0x1000e12c] */
    ST(1) = FPRES(c, ST(1) - ST(0)); FPOP(c); /* fsubp st(1) */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x14u))); /* fld dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2b8u))); /* fmul dword ptr [0x1000e2b8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0xfffffff0u))); /* fadd dword ptr [esi - 0x10] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esi + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03bca; /* jne 0xa03bca */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x10] */
L_00a03bca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe8u))); /* mov eax, dword ptr [esi - 0x18] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a03bd6u); f_00a02950(c); /* call 0xa02950 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e1f4u))); /* fmul dword ptr [0x1000e1f4] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e2b4u)) - ST(0)); /* fsubr dword ptr [0x1000e2b4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fmul dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi))); /* fadd dword ptr [esi] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e104u))); FPOP(c); /* fcomp dword ptr [0x1000e104] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03c11; /* jne 0xa03c11 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x18u))); /* fld dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(0xa0e104u))); /* fsub dword ptr [0x1000e104] */
    WF32((uint32_t)(c->esi), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi] */
L_00a03c11:;
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0xffffffe8u))); /* mov ecx, dword ptr [esi - 0x18] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x28u))); /* fadd dword ptr [esp + 0x28] */
    WF32((uint32_t)(c->esi + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi))); /* fld dword ptr [esi] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x24u))); /* fadd dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->esi + 0xffffffecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e2b0u))); /* fmul dword ptr [0x1000e2b0] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4u))); /* fadd dword ptr [esi + 4] */
    WF32((uint32_t)(c->esi + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov ecx, dword ptr [edi + 0xc] */
    PUSH32(c, 0x00a03c4bu); f_00a02950(c); /* call 0xa02950 */
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e114u))); /* fcom dword ptr [0x1000e114] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4100u))); /* and eax, 0x4100 */
    if (!c->zf) goto L_00a03c73; /* jne 0xa03c73 */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e114u))); /* fld dword ptr [0x1000e114] */
    ST(0) = FPRES(c, ST(1) - ST(0)); /* fsubr st(1) */
    ST(0) = FPRES(c, ST(0) + ST(0)); /* fadd st(0), st(0) */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e194u))); /* fmul dword ptr [0x1000e194] */
    WF32((uint32_t)(c->esi + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 8] */
L_00a03c73:;
    FCOM(c, ST(0), (double)RF32((uint32_t)(0xa0e120u))); /* fcom dword ptr [0x1000e120] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & (uint8_t)0x5u)); /* test ah, 5 */
    if (PF(c)) goto L_00a03c9d; /* jp 0xa03c9d */
    FPUSH(c, (double)RF32((uint32_t)(0xa0e120u))); /* fld dword ptr [0x1000e120] */
    ST(0) = FPRES(c, ST(0) - ST(1)); /* fsub st(1) */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e10cu))); /* fmul dword ptr [0x1000e10c] */
    ST(0) = FPRES(c, (double)RF32((uint32_t)(0xa0e128u)) - ST(0)); /* fsubr dword ptr [0x1000e128] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e194u))); /* fmul dword ptr [0x1000e194] */
    WF32((uint32_t)(c->esi + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esi - 8] */
L_00a03c9d:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (!c->zf) goto L_00a03b03; /* jne 0xa03b03 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a03cc0(CPU *c) { /* FUN_10003cc0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xd0u)); /* sub esp, 0xd0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ecx); /* mov ebp, ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xe0u))); /* mov esi, dword ptr [esp + 0xe0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0x14u)); /* lea edi, [ebp + 0x14] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W32((uint32_t)(c->esp + 0x30u), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0x30], ebp */
    W32((uint32_t)(c->esp + 0x34u), (uint32_t)(c->edi)); /* mov dword ptr [esp + 0x34], edi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x5cu)); PUSH32(c, 0x00a03ce8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x5c] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea ecx, [esp + 0x40] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x3f800000u); /* mov ecx, 0x3f800000 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x18], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x20], ebx */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x24], ebx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x28], ecx */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x2c], ebx */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x30], ebx */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x34], ebx */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x38], ebx */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x3c], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea eax, [esp + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00a03d38u); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea ecx, [esp + 0x40] */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x10], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)0x3f800000u); /* mov ecx, 0x3f800000 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0xc], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x10], ebx */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    W32((uint32_t)(c->eax + 0x18u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x18], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x20u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x20], ebx */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x24], ebx */
    W32((uint32_t)(c->eax + 0x28u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x28], ecx */
    W32((uint32_t)(c->eax + 0x2cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x2c], ebx */
    W32((uint32_t)(c->eax + 0x30u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x30], ebx */
    W32((uint32_t)(c->eax + 0x34u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x34], ebx */
    W32((uint32_t)(c->eax + 0x38u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x38], ebx */
    W32((uint32_t)(c->eax + 0x3cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x3c], ecx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x40u)); /* lea eax, [esp + 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x58u)); PUSH32(c, 0x00a03d8bu); call_indirect(c, t_); } /* call dword ptr [edx + 0x58] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov eax, dword ptr [ebp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x7cu)); PUSH32(c, 0x00a03d98u); call_indirect(c, t_); } /* call dword ptr [edx + 0x7c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x6054u)); /* lea eax, [ebp + 0x6054] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)((uint32_t)0x400u)); /* mov dword ptr [esp + 0x10], 0x400 */
    goto L_00a03db6; /* jmp 0xa03db6 */
L_00a03daa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov eax, dword ptr [esp + 0x30] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebp, dword ptr [esp + 0x28] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov edi, dword ptr [esp + 0x2c] */
L_00a03db6:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x38], eax */
    PUSH32(c, 0x00a03dccu); f_00a04470(c); /* call 0xa04470 */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x10u))); /* fld dword ptr [esi + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e114u))); /* fmul dword ptr [0x1000e114] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xcu))); /* fld dword ptr [esi + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0xcu))); /* fld dword ptr [esi + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x14u))); /* fld dword ptr [esi + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ebp + 0x10u))); /* fmul dword ptr [ebp + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e198u))); /* fmul dword ptr [0x1000e198] */
    PUSH32(c, 0x00a03dfcu); f_00a04570(c); /* call 0xa04570 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x24u))); /* fadd dword ptr [esp + 0x24] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->edi = (uint32_t)(shl32(c, c->edi, 24)); /* shl edi, 0x18 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb4u)); /* lea ecx, [esp + 0xb4] */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi | (uint32_t)0xafcfffu))); /* or edi, 0xafcfff */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x28u))); /* fld dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x24u))); /* fsub dword ptr [esp + 0x24] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x24u))); /* fmul dword ptr [esp + 0x24] */
    WF32((uint32_t)(c->esp + 0x1cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a03e3fu); f_00a04420(c); /* call 0xa04420 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xd8u)); /* lea edx, [esp + 0xd8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a03e52u); f_00a04440(c); /* call 0xa04440 */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea ecx, [ebx + ebx*8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 4)); /* shl ecx, 4 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->ebp)); /* lea esi, [ecx + ebp] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x24u))); /* fsub dword ptr [esp + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xf054u)); /* lea edx, [esi + 0xf054] */
    W32((uint32_t)(c->esi + 0xf054u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 0xf054], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    W32((uint32_t)(c->esi + 0xf060u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xf060], edi */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xa4u)); /* lea ecx, [esp + 0xa4] */
    W32((uint32_t)(c->esi + 0xf064u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xf064], eax */
    W32((uint32_t)(c->esi + 0xf068u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xf068], eax */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    PUSH32(c, 0x00a03eb0u); f_00a04420(c); /* call 0xa04420 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea edx, [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0xd0u)); /* lea eax, [esp + 0xd0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a03ec3u); f_00a04440(c); /* call 0xa04440 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x2cu))); /* fld dword ptr [esp + 0x2c] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x30u))); /* fsub dword ptr [esp + 0x30] */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ebp = (uint32_t)((uint32_t)(c->esi + 0xf06cu)); /* lea ebp, [esi + 0xf06c] */
    c->ecx = (uint32_t)(c->ebp); /* mov ecx, ebp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x1cu))); /* fmul dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edx, dword ptr [esp + 0x1c] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov ecx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esi + 0xf078u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xf078], edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8cu)); /* lea ecx, [esp + 0x8c] */
    W32((uint32_t)(c->esi + 0xf07cu), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xf07c], 0 */
    W32((uint32_t)(c->esi + 0xf080u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0xf080], 0x3f800000 */
    PUSH32(c, 0x00a03f20u); f_00a04420(c); /* call 0xa04420 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->esp + 0x38u)); /* lea eax, [esp + 0x38] */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x90u)); /* lea ecx, [esp + 0x90] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00a03f33u); f_00a04440(c); /* call 0xa04440 */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xf084u)); /* lea ecx, [esi + 0xf084] */
    W32((uint32_t)(c->esp + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x30u))); /* fld dword ptr [esp + 0x30] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov eax, dword ptr [esp + 0x24] */
    ST(0) = -ST(0); /* fchs  */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x20u))); /* fsub dword ptr [esp + 0x20] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xf09cu)); /* lea edx, [esi + 0xf09c] */
    W32((uint32_t)(c->esi + 0xf090u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xf090], edi */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov eax, dword ptr [ecx + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    W32((uint32_t)(c->esi + 0xf094u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [esi + 0xf094], 0x3f800000 */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    c->eax = (uint32_t)((uint32_t)0x3f800000u); /* mov eax, 0x3f800000 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x20u))); /* fmul dword ptr [esp + 0x20] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    c->edx = (uint32_t)((uint32_t)(c->esi + 0xf0b4u)); /* lea edx, [esi + 0xf0b4] */
    W32((uint32_t)(c->esi + 0xf0acu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xf0ac], eax */
    W32((uint32_t)(c->esi + 0xf0c8u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xf0c8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov eax, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ecx)); /* mov dword ptr [edx], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x4u))); /* mov ecx, dword ptr [ebp + 4] */
    W32((uint32_t)(c->esi + 0xf098u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xf098], 0 */
    W32((uint32_t)(c->esi + 0xf0a8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xf0a8], edi */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 4], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ebp, dword ptr [esp + 0x2c] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [edx + 8], ecx */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8 + 0xf0cu)); /* lea edx, [ebx + ebx*8 + 0xf0c] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    W32((uint32_t)(c->esi + 0xf0b0u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xf0b0], 0 */
    W32((uint32_t)(c->esi + 0xf0c4u), (uint32_t)((uint32_t)0x0u)); /* mov dword ptr [esi + 0xf0c4], 0 */
    W32((uint32_t)(c->edx + c->ebp), (uint32_t)(c->edi)); /* mov dword ptr [edx + ebp], edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0xb0u)); /* lea ecx, [esp + 0xb0] */
    PUSH32(c, 0x00a04002u); f_00a04420(c); /* call 0xa04420 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x34u)); /* lea ecx, [esp + 0x34] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0xc0u)); /* lea edx, [esp + 0xc0] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a04015u); f_00a04440(c); /* call 0xa04440 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    c->ecx = (uint32_t)((uint32_t)(c->esi + 0xf0ccu)); /* lea ecx, [esi + 0xf0cc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov edx, dword ptr [eax + 4] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    W32((uint32_t)(c->esi + 0xf0d8u), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xf0d8], edi */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 8], eax */
    c->ecx = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea ecx, [ebx + ebx] */
    c->eax = (uint32_t)((uint32_t)0x3f800000u); /* mov eax, 0x3f800000 */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    W32((uint32_t)(c->esi + 0xf0dcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xf0dc], eax */
    W32((uint32_t)(c->esi + 0xf0e0u), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xf0e0], eax */
    if (!c->zf) goto L_00a0407e; /* jne 0xa0407e */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xe4u))); /* mov eax, dword ptr [esp + 0xe4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xa10380u; PUSH32(c, v_); } /* push 0x10010380 */
    c->ebp = (uint32_t)(add32(c, c->ebp, (uint32_t)0xf054u)); /* add ebp, 0xf054 */
    c->edx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edx, dword ptr [eax] */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0xe8u)); PUSH32(c, 0x00a04079u); call_indirect(c, t_); } /* call dword ptr [edx + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00a0407e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (!c->zf) goto L_00a03daa; /* jne 0xa03daa */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov edi, dword ptr [esp + 0x28] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xe4u))); /* mov esi, dword ptr [esp + 0xe4] */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00a040c3; /* jle 0xa040c3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xa10380u; PUSH32(c, v_); } /* push 0x10010380 */
    c->ecx = (uint32_t)((uint32_t)(c->edi + 0xf054u)); /* lea ecx, [edi + 0xf054] */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    c->edx = (uint32_t)((uint32_t)(c->ebx + c->ebx)); /* lea edx, [ebx + ebx] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0xe8u)); PUSH32(c, 0x00a040c0u); call_indirect(c, t_); } /* call dword ptr [eax + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00a040c3:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov ecx, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x7cu)); PUSH32(c, 0x00a040d0u); call_indirect(c, t_); } /* call dword ptr [eax + 0x7c] */
    { uint32_t v_ = 0xa10368u; PUSH32(c, v_); } /* push 0x10010368 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    c->edx = (uint32_t)((uint32_t)(c->edi + 0x54u)); /* lea edx, [edi + 0x54] */
    { uint32_t v_ = 0x200u; PUSH32(c, v_); } /* push 0x200 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ecx = (uint32_t)(c->edi); /* mov ecx, edi */
    PUSH32(c, 0x00a040eau); f_00a04110(c); /* call 0xa04110 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ecx, dword ptr [esp + 0x2c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x58u)); PUSH32(c, 0x00a040f8u); call_indirect(c, t_); } /* call dword ptr [eax + 0x58] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xd0u)); /* add esp, 0xd0 */
    c->esp += 8; return; /* ret 4 */
}

void f_00a04110(CPU *c) { /* FUN_10004110 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x5cu)); /* sub esp, 0x5c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    if ((c->zf || c->sf != c->of)) goto L_00a04416; /* jle 0xa04416 */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
L_00a0412d:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x74u))); /* mov ecx, dword ptr [esp + 0x74] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x7cu))); /* mov edx, dword ptr [esp + 0x7c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x34u))); /* fld dword ptr [esi + 0x34] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    W32((uint32_t)(c->esp + 0x74u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 0x74], ecx */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x24u))); /* fmul dword ptr [esi + 0x24] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x14u))); /* fmul dword ptr [esi + 0x14] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x44u))); /* fadd dword ptr [esi + 0x44] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x28u))); /* fmul dword ptr [esi + 0x28] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x18u))); /* fld dword ptr [esi + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x38u))); /* fld dword ptr [esi + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x48u))); /* fadd dword ptr [esi + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x2cu))); /* fmul dword ptr [esi + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x3cu))); /* fld dword ptr [esi + 0x3c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->esi + 0x1cu))); /* fld dword ptr [esi + 0x1c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esi + 0x4cu))); /* fadd dword ptr [esi + 0x4c] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x10u))); /* fld dword ptr [eax + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e114u))); /* fmul dword ptr [0x1000e114] */
    WF32((uint32_t)(c->esp + 0x14u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0xcu))); /* fld dword ptr [eax + 0xc] */
    ST(0) = FTRIG(c, ST(0), sin); /* fsin  */
    WF32((uint32_t)(c->esp + 0x78u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x78] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0xcu))); /* fld dword ptr [eax + 0xc] */
    ST(0) = FTRIG(c, ST(0), cos); /* fcos  */
    WF32((uint32_t)(c->esp + 0x10u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x10] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x14u))); /* fld dword ptr [eax + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esi + 0x10u))); /* fmul dword ptr [esi + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(0xa0e198u))); /* fmul dword ptr [0x1000e198] */
    PUSH32(c, 0x00a041b5u); f_00a04570(c); /* call 0xa04570 */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x78u))); /* fld dword ptr [esp + 0x78] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)((uint32_t)(c->edi + c->edi * 8)); /* lea ecx, [edi + edi*8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 24)); /* shl eax, 0x18 */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(shl32(c, c->ecx, 4)); /* shl ecx, 4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xafcfffu))); /* or eax, 0xafcfff */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->esi)); /* add ecx, esi */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->esp + 0x78u))); /* fadd dword ptr [esp + 0x78] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xf054u)); /* lea edx, [ecx + 0xf054] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    WF32((uint32_t)(c->esp + 0x20u), (float)ST(0)); /* fst dword ptr [esp + 0x20] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + ST(5)); /* fadd st(5) */
    WF32((uint32_t)(c->esp + 0x3cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x3c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x3cu))); /* mov ebp, dword ptr [esp + 0x3c] */
    ST(0) = FPRES(c, ST(0) + ST(3)); /* fadd st(3) */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebp)); /* mov dword ptr [edx], ebp */
    WF32((uint32_t)(c->esp + 0x40u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x40] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x40u))); /* mov ebp, dword ptr [esp + 0x40] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF32((uint32_t)(c->esp + 0x18u), (float)ST(0)); /* fst dword ptr [esp + 0x18] */
    WF32((uint32_t)(c->esp + 0x44u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x44] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x44u))); /* mov ebp, dword ptr [esp + 0x44] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 8], ebp */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = -ST(0); /* fchs  */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x78u))); /* fsub dword ptr [esp + 0x78] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx + 0xf060u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf060], eax */
    W32((uint32_t)(c->esp + 0x38u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x38], edx */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xf06cu)); /* lea edx, [ecx + 0xf06c] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    W32((uint32_t)(c->ecx + 0xf064u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 0xf064], ebx */
    W32((uint32_t)(c->ecx + 0xf068u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 0xf068], ebx */
    W32((uint32_t)(c->ecx + 0xf078u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf078], eax */
    W32((uint32_t)(c->ecx + 0xf07cu), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 0xf07c], ebx */
    W32((uint32_t)(c->ecx + 0xf080u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + 0xf080], 0x3f800000 */
    W32((uint32_t)(c->ecx + 0xf090u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf090], eax */
    WF32((uint32_t)(c->esp + 0x54u), (float)ST(0)); /* fst dword ptr [esp + 0x54] */
    ST(0) = FPRES(c, ST(0) + ST(3)); /* fadd st(3) */
    W32((uint32_t)(c->ecx + 0xf094u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + 0xf094], 0x3f800000 */
    W32((uint32_t)(c->ecx + 0xf098u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 0xf098], ebx */
    W32((uint32_t)(c->ecx + 0xf0a8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf0a8], eax */
    W32((uint32_t)(c->ecx + 0xf0acu), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + 0xf0ac], 0x3f800000 */
    WF32((uint32_t)(c->esp + 0x30u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x30] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebp, dword ptr [esp + 0x30] */
    W32((uint32_t)(c->ecx + 0xf0b0u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 0xf0b0], ebx */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebp)); /* mov dword ptr [edx], ebp */
    W32((uint32_t)(c->ecx + 0xf0c4u), (uint32_t)(c->ebx)); /* mov dword ptr [ecx + 0xf0c4], ebx */
    W32((uint32_t)(c->ecx + 0xf0c8u), (uint32_t)((uint32_t)0x3f800000u)); /* mov dword ptr [ecx + 0xf0c8], 0x3f800000 */
    WF32((uint32_t)(c->esp + 0x34u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x34] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x20u))); /* fld dword ptr [esp + 0x20] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x10u))); /* fld dword ptr [esp + 0x10] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x78u))); /* fsub dword ptr [esp + 0x78] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebp, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ebp, dword ptr [esp + 0x38] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 8], ebp */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->esp + 0x2cu), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x2c], edx */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xf084u)); /* lea edx, [ecx + 0xf084] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    { double t_ = ST(0); ST(0) = ST(2); ST(2) = t_; } /* fxch st(2) */
    ST(0) = FPRES(c, ST(0) + ST(4)); /* fadd st(4) */
    WF32((uint32_t)(c->esp + 0x24u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x24] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = FPRES(c, ST(0) + ST(2)); /* fadd st(2) */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebp)); /* mov dword ptr [edx], ebp */
    WF32((uint32_t)(c->esp + 0x28u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x28] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebp, dword ptr [esp + 0x28] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ebp, dword ptr [esp + 0x2c] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x78u))); /* fld dword ptr [esp + 0x78] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 8], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x24u))); /* mov ebp, dword ptr [esp + 0x24] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xf09cu)); /* lea edx, [ecx + 0xf09c] */
    ST(0) = -ST(0); /* fchs  */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebp)); /* mov dword ptr [edx], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x28u))); /* mov ebp, dword ptr [esp + 0x28] */
    ST(0) = FPRES(c, ST(0) - (double)RF32((uint32_t)(c->esp + 0x10u))); /* fsub dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x2cu))); /* mov ebp, dword ptr [esp + 0x2c] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 8], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x30u))); /* mov ebp, dword ptr [esp + 0x30] */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xf0b4u)); /* lea edx, [ecx + 0xf0b4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->esp + 0x14u))); /* fmul dword ptr [esp + 0x14] */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebp)); /* mov dword ptr [edx], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x34u))); /* mov ebp, dword ptr [esp + 0x34] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x38u))); /* mov ebp, dword ptr [esp + 0x38] */
    WF32((uint32_t)(c->esp + 0x64u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x64] */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 8], ebp */
    c->edx = (uint32_t)((uint32_t)(c->edi + c->edi * 8 + 0xf0cu)); /* lea edx, [edi + edi*8 + 0xf0c] */
    c->edx = (uint32_t)(shl32(c, c->edx, 4)); /* shl edx, 4 */
    W32((uint32_t)(c->edx + c->esi), (uint32_t)(c->eax)); /* mov dword ptr [edx + esi], eax */
    ST(0) = FPRES(c, ST(0) + ST(2)); /* fadd st(2) */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov edx, dword ptr [esp + 0x18] */
    W32((uint32_t)(c->ecx + 0xf0d8u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf0d8], eax */
    W32((uint32_t)(c->esp + 0x50u), (uint32_t)(c->edx)); /* mov dword ptr [esp + 0x50], edx */
    c->edx = (uint32_t)((uint32_t)(c->ecx + 0xf0ccu)); /* lea edx, [ecx + 0xf0cc] */
    WF32((uint32_t)(c->esp + 0x48u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x48] */
    FPUSH(c, (double)RF32((uint32_t)(c->esp + 0x64u))); /* fld dword ptr [esp + 0x64] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x48u))); /* mov ebp, dword ptr [esp + 0x48] */
    c->eax = (uint32_t)((uint32_t)0x3f800000u); /* mov eax, 0x3f800000 */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    W32((uint32_t)(c->edx), (uint32_t)(c->ebp)); /* mov dword ptr [edx], ebp */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ecx + 0xf0dcu), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf0dc], eax */
    W32((uint32_t)(c->ecx + 0xf0e0u), (uint32_t)(c->eax)); /* mov dword ptr [ecx + 0xf0e0], eax */
    WF32((uint32_t)(c->esp + 0x4cu), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 0x4c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x4cu))); /* mov ebp, dword ptr [esp + 0x4c] */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi)); /* lea eax, [edi + edi] */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 4], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x50u))); /* mov ebp, dword ptr [esp + 0x50] */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->ebp)); /* mov dword ptr [edx + 8], ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(c->esp + 0x70u))); /* mov ebp, dword ptr [esp + 0x70] */
    (void)sub32(c, c->eax, (uint32_t)0x100u); /* cmp eax, 0x100 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (!c->zf) goto L_00a043d9; /* jne 0xa043d9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x84u))); /* mov edx, dword ptr [esp + 0x84] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0xf054u)); /* lea eax, [esi + 0xf054] */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x100u; PUSH32(c, v_); } /* push 0x100 */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xe8u)); PUSH32(c, 0x00a043d4u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00a043d9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov eax, dword ptr [esp + 0x1c] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->esp + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x1c], eax */
    if (!c->zf) goto L_00a0412d; /* jne 0xa0412d */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if ((c->zf || c->sf != c->of)) goto L_00a04416; /* jle 0xa04416 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x84u))); /* mov edx, dword ptr [esp + 0x84] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp))); /* mov ecx, dword ptr [ebp] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xf054u)); /* add esi, 0xf054 */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi)); /* lea eax, [edi + edi] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x142u; PUSH32(c, v_); } /* push 0x142 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t t_ = R32((uint32_t)(c->ecx + 0xe8u)); PUSH32(c, 0x00a04413u); call_indirect(c, t_); } /* call dword ptr [ecx + 0xe8] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00a04416:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x5cu)); /* add esp, 0x5c */
    c->esp += 28; return; /* ret 0x18 */
}

void f_00a04420(CPU *c) { /* FUN_10004420 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [eax + 4], edx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 8], ecx */
    c->esp += 16; return; /* ret 0xc */
}

void f_00a04440(CPU *c) { /* FUN_10004440 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x8u))); /* fld dword ptr [eax + 8] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fadd dword ptr [ecx + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax + 0x4u))); /* fld dword ptr [eax + 4] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fadd dword ptr [ecx + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx))); /* fadd dword ptr [ecx] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    WF32((uint32_t)(c->eax), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax] */
    WF32((uint32_t)(c->eax + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 4] */
    WF32((uint32_t)(c->eax + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [eax + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00a04470(CPU *c) { /* FUN_10004470 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x20u))); /* fld dword ptr [ecx + 0x20] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x10u))); /* fld dword ptr [ecx + 0x10] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->eax))); /* fld dword ptr [eax] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->ecx))); /* fmul dword ptr [ecx] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x30u))); /* fadd dword ptr [ecx + 0x30] */
    WF32((uint32_t)(c->esp), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x24u))); /* fld dword ptr [ecx + 0x24] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x14u))); /* fld dword ptr [ecx + 0x14] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp))); /* mov edx, dword ptr [esp] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x4u))); /* fld dword ptr [ecx + 4] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x34u))); /* fadd dword ptr [ecx + 0x34] */
    WF32((uint32_t)(c->esp + 0x4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 4] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x28u))); /* fld dword ptr [ecx + 0x28] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x8u))); /* fmul dword ptr [eax + 8] */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x18u))); /* fld dword ptr [ecx + 0x18] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax + 0x4u))); /* fmul dword ptr [eax + 4] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    FPUSH(c, (double)RF32((uint32_t)(c->ecx + 0x8u))); /* fld dword ptr [ecx + 8] */
    ST(0) = FPRES(c, ST(0) * (double)RF32((uint32_t)(c->eax))); /* fmul dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    ST(0) = FPRES(c, ST(0) + (double)RF32((uint32_t)(c->ecx + 0x38u))); /* fadd dword ptr [ecx + 0x38] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    WF32((uint32_t)(c->esp + 0x8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 4], edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(c->edx)); /* mov dword ptr [ecx + 8], edx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 12; return; /* ret 8 */
}

void f_00a044f0(CPU *c) { /* FUN_100044f0 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00a044f5u); f_00a04508(c); /* call 0xa04508 */
    PUSH32(c, 0x00a044fau); f_00a04ec4(c); /* call 0xa04ec4 */
    W32((uint32_t)(0xa13424u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013424], eax */
    PUSH32(c, 0x00a04504u); f_00a04e74(c); /* call 0xa04e74 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_00a04507(CPU *c) { /* PTR_00a04507 */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_00a04508(CPU *c) { /* FUN_10004508 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0xa0529du); /* mov eax, 0x1000529d */
    W32((uint32_t)(0xa103f4u), (uint32_t)((uint32_t)0xa04f47u)); /* mov dword ptr [0x100103f4], 0x10004f47 */
    W32((uint32_t)(0xa103f0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100103f0], eax */
    W32((uint32_t)(0xa103f8u), (uint32_t)((uint32_t)0xa04fadu)); /* mov dword ptr [0x100103f8], 0x10004fad */
    W32((uint32_t)(0xa103fcu), (uint32_t)((uint32_t)0xa04eedu)); /* mov dword ptr [0x100103fc], 0x10004eed */
    W32((uint32_t)(0xa10400u), (uint32_t)((uint32_t)0xa04f95u)); /* mov dword ptr [0x10010400], 0x10004f95 */
    W32((uint32_t)(0xa10404u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010404], eax */
    c->esp += 4; return; /* ret  */
}

void f_00a04540(CPU *c) { /* FUN_10004540 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00a04545u); f_00a05398(c); /* call 0xa05398 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a0454d(CPU *c) { /* _rand */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00a04552u); f_00a05398(c); /* call 0xa05398 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x14u))); /* mov ecx, dword ptr [eax + 0x14] */
    { int64_t r_ = (int64_t)(int32_t)c->ecx * (int32_t)(uint32_t)0x343fdu; c->ecx = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul ecx, ecx, 0x343fd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x269ec3u)); /* add ecx, 0x269ec3 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x14], ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7fffu))); /* and eax, 0x7fff */
    c->esp += 4; return; /* ret  */
}

void f_00a04570(CPU *c) { /* __ftol */
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

void f_00a04597(CPU *c) { /* FUN_10004597 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00a045c2u); return; } } /* jmp eax */
}

void f_00a045c4(CPU *c) { /* PTR_00a045c4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00a045cb(CPU *c) { /* FUN_100045cb */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00a045d0u); return; } } /* jmp eax */
}

void f_00a045d2(CPU *c) { /* FUN_100045d2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x00a045d7u); return; } } /* jmp eax */
}

void f_00a045d9(CPU *c) { /* FUN_100045d9 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0xa04601u)); /* mov dword ptr [ebp - 4], 0x10004601 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a04601u); f_00a0d384(c); /* call 0xa0d384 */
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

void f_00a04601(CPU *c) { /* PTR_00a04601 */
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

void f_00a04628(CPU *c) { /* FUN_10004628 */
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
    PUSH32(c, 0x00a0464eu); f_00a0549f(c); /* call 0xa0549f */
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

void f_00a0465e(CPU *c) { /* FUN_1000465e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xa046b2u)); /* mov dword ptr [ebp - 0x10], 0x100046b2 */
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
    PUSH32(c, 0x00a046a3u); f_00a05cc0(c); /* call 0xa05cc0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a046b2(CPU *c) { /* FUN_100046b2 */
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
    PUSH32(c, 0x00a046d2u); f_00a0549f(c); /* call 0xa0549f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a046d7(CPU *c) { /* FUN_100046d7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0xa0478du)); /* mov dword ptr [ebp - 0x24], 0x1000478d */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0xa0475fu)); /* mov dword ptr [ebp - 0x10], 0x1000475f */
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
    PUSH32(c, 0x00a04756u); f_00a05398(c); /* call 0xa05398 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x00a04759u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00a0477c; /* je 0xa0477c */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00a04785; /* jmp 0xa04785 */
L_00a0477c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00a04785:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0475f(CPU *c) { /* PTR_00a0475f */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_00a0477c; /* je 0xa0477c */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_00a04785; /* jmp 0xa04785 */
L_00a0477c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_00a04785:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0478d(CPU *c) { /* FUN_1000478d */
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
    if (c->zf) goto L_00a047b0; /* je 0xa047b0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a047fd; /* jmp 0xa047fd */
L_00a047b0:;
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
    PUSH32(c, 0x00a047d7u); f_00a0549f(c); /* call 0xa0549f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_00a047ee; /* jne 0xa047ee */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a047eeu); f_00a045d9(c); /* call 0xa045d9 */
L_00a047ee:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a047f7u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_00a047fd:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a04802(CPU *c) { /* FUN_10004802 */
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
    if ((c->sf != c->of)) goto L_00a04859; /* jl 0xa04859 */
L_00a04820:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00a0482a; /* jne 0xa0482a */
    PUSH32(c, 0x00a0482au); f_00a05d6d(c); /* call 0xa05d6d */
L_00a0482a:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_00a0483f; /* jge 0xa0483f */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_00a04844; /* jle 0xa04844 */
L_00a0483f:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_00a04850; /* jne 0xa04850 */
L_00a04844:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_00a04850:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_00a04820; /* jge 0xa04820 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_00a04859:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_00a0486d; /* ja 0xa0486d */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_00a04872; /* jbe 0xa04872 */
L_00a0486d:;
    PUSH32(c, 0x00a04872u); f_00a05d6d(c); /* call 0xa05d6d */
L_00a04872:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a04880(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0xa04898u; PUSH32(c, v_); } /* push 0x10004898 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a04898u); f_00a0d384(c); /* call 0xa0d384 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a04898(CPU *c) { /* PTR_00a04898 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a048a0(CPU *c) { /* PTR_00a048a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_00a048c1; /* je 0xa048c1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_00a048c1:;
    c->esp += 4; return; /* ret  */
}

void f_00a048c2(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0xa048a0u; PUSH32(c, v_); } /* push 0x100048a0 */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_00a048df:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_00a0491c; /* je 0xa0491c */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_00a0491c; /* je 0xa0491c */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_00a0491a; /* jne 0xa0491a */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x00a04916u); f_00a04956(c); /* call 0xa04956 */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x00a0491au); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_00a0491a:;
    goto L_00a048df; /* jmp 0xa048df */
L_00a0491c:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a0492a(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0xa048a0u); /* cmp dword ptr [ecx + 4], 0x100048a0 */
    if (!c->zf) goto L_00a0494c; /* jne 0xa0494c */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_00a0494c; /* jne 0xa0494c */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00a0494c:;
    c->esp += 4; return; /* ret  */
}

void f_00a0494d(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xa103acu); /* mov ebx, 0x100103ac */
    { f_00a04960(c); return; } /* jmp 0xa04960 */
}

void f_00a04956(CPU *c) { /* FUN_10004956 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0xa103acu); /* mov ebx, 0x100103ac */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00a04960(CPU *c) { /* PTR_00a04960 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_00a04970(CPU *c) { /* FUN_10004970 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); /* fst qword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    PUSH32(c, 0x00a04985u); f_00a04992(c); /* call 0xa04992 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00a04992(CPU *c) { /* FUN_10004992 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_00a049a6; /* je 0xa049a6 */
    PUSH32(c, 0x00a049a6u); f_00a06225(c); /* call 0xa06225 */
L_00a049a6:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7ff00000u))); /* and ecx, 0x7ff00000 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    (void)sub32(c, c->ecx, (uint32_t)0x7ff00000u); /* cmp ecx, 0x7ff00000 */
    if (c->zf) goto L_00a04a59; /* je 0xa04a59 */
    PUSH32(c, 0x00a049c1u); f_00a06255(c); /* call 0xa06255 */
    if (c->zf) goto L_00a04a55; /* je 0xa04a55 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_00a04ac8; /* je 0xa04ac8 */
L_00a049d2:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov cl, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x80u))); /* and cl, 0x80 */
    if (!c->zf) goto L_00a04b40; /* jne 0xa04b40 */
L_00a049df:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    PUSH32(c, 0x00a049e6u); f_00a06210(c); /* call 0xa06210 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x1u); /* cmp cl, 1 */
    if (!c->zf) goto L_00a049ed; /* jne 0xa049ed */
    ST(0) = -ST(0); /* fchs  */
L_00a049ed:;
    (void)sub32(c, R32((uint32_t)(0xa13420u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013420], 0 */
    if (!c->zf) { f_00a062ae(c); return; } /* jne 0xa062ae */
    c->ecx = (uint32_t)((uint32_t)(0xa103c8u)); /* lea ecx, [0x100103c8] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    { f_00a062f9(c); return; } /* jmp 0xa062f9 */
L_00a04a0a:;
    (void)sub32(c, R32((uint32_t)(0xa13420u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013420], 0 */
    if (!c->zf) { f_00a062ae(c); return; } /* jne 0xa062ae */
    c->ecx = (uint32_t)((uint32_t)(0xa103c8u)); /* lea ecx, [0x100103c8] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    PUSH32(c, 0x00a04a27u); f_00a061b0(c); /* call 0xa061b0 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00a04a29:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    PUSH32(c, 0x00a04a32u); f_00a06255(c); /* call 0xa06255 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x16u)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0x16], 8 */
    if (!c->zf) goto L_00a04a3c; /* jne 0xa04a3c */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_00a04a6f; /* jmp 0xa04a6f */
L_00a04a3c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00a04a0a; /* jmp 0xa04a0a */
L_00a04a45:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0xeu)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0xe], 8 */
    if (!c->zf) goto L_00a04a3c; /* jne 0xa04a3c */
L_00a04a4c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    goto L_00a04a0a; /* jmp 0xa04a0a */
L_00a04a55:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    goto L_00a04a6f; /* jmp 0xa04a6f */
L_00a04a59:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00a04a29; /* jne 0xa04a29 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    PUSH32(c, 0x00a04a6fu); f_00a06255(c); /* call 0xa06255 */
L_00a04a6f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffu))); /* and edx, 0xfffff */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (!c->zf) goto L_00a04a8d; /* jne 0xa04a8d */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | R32((uint32_t)(c->esp + 0x8u))))); /* or edx, dword ptr [esp + 8] */
    if (!c->zf) goto L_00a04a45; /* jne 0xa04a45 */
L_00a04a8d:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_00a04a4c; /* jne 0xa04a4c */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x74u)); /* sub esp, 0x74 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    ; /* wait  */
    guest_trap(c, 0x00a04aa2u, "unsupported: fnsave dword ptr [ecx + 8]"); /* fnsave dword ptr [ecx + 8] */
    PUSH32(c, 0x00a04aaau); f_00a0639c(c); /* call 0xa0639c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    guest_trap(c, 0x00a04aaeu, "unsupported: frstor dword ptr [ecx + 8]"); /* frstor dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_00a062ae(c); return; } /* je 0xa062ae */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00a04a0a; /* jmp 0xa04a0a */
L_00a04ac8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_00a049d2; /* jne 0xa049d2 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_00a04b25; /* je 0xa04b25 */
    PUSH32(c, 0x00a04aedu); f_00a04b65(c); /* call 0xa04b65 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esp + 0xfu))) << 8); /* mov ch, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(shr8(c, ((uint8_t)(c->ecx >> 8)), 7)) << 8); /* shr ch, 7 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esp + 0x17u)) & (uint32_t)0x80u)); /* test dword ptr [esp + 0x17], 0x80 */
    if (c->zf) goto L_00a04b14; /* je 0xa04b14 */
    FPUSH(c, RF80((uint32_t)(0xa10420u))); /* fld xword ptr [0x10010420] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) goto L_00a04b0a; /* je 0xa04b0a */
    ST(0) = -ST(0); /* fchs  */
L_00a04b0a:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_00a04a0a; /* jmp 0xa04a0a */
L_00a04b14:;
    FPUSH(c, 0.0); /* fldz  */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) { f_00a062ae(c); return; } /* je 0xa062ae */
    ST(0) = -ST(0); /* fchs  */
    { f_00a062ae(c); return; } /* jmp 0xa062ae */
L_00a04b25:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_00a04b39; /* jne 0xa04b39 */
    FPUSH(c, 1.0); /* fld1  */
    { f_00a062ae(c); return; } /* jmp 0xa062ae */
L_00a04b39:;
    FPUSH(c, 0.0); /* fldz  */
    { f_00a062ae(c); return; } /* jmp 0xa062ae */
L_00a04b40:;
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    PUSH32(c, 0x00a04b47u); f_00a04b65(c); /* call 0xa04b65 */
    ST(0) = -ST(0); /* fchs  */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00a049df; /* jne 0xa049df */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0xa10480u))); /* fld xword ptr [0x10010480] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_00a04a0a; /* jmp 0xa04a0a */
}

void f_00a04b65(CPU *c) { /* FUN_10004b65 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov cl, 0 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00a04b8a; /* jne 0xa04b8a */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xa103c0u))); /* fmul qword ptr [0x100103c0] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00a04b89; /* jne 0xa04b89 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
L_00a04b89:;
    c->esp += 4; return; /* ret  */
L_00a04b8a:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_00a04b8d(CPU *c) { /* PTR_00a04b8d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a04b93u); f_00a06623(c); /* call 0xa06623 */
    { uint32_t v_ = R32((uint32_t)(0xa13b10u)); PUSH32(c, v_); } /* push dword ptr [0x10013b10] */
    PUSH32(c, 0x00a04b9eu); f_00a0697e(c); /* call 0xa0697e */
    c->edx = (uint32_t)(R32((uint32_t)(0xa13b10u))); /* mov edx, dword ptr [0x10013b10] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13b0cu))); /* mov ecx, dword ptr [0x10013b0c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_00a04bf3; /* jae 0xa04bf3 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a04bbcu); f_00a0697e(c); /* call 0xa0697e */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0xa13b10u)); PUSH32(c, v_); } /* push dword ptr [0x10013b10] */
    PUSH32(c, 0x00a04bcbu); f_00a0664f(c); /* call 0xa0664f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a04bd6; /* jne 0xa04bd6 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00a04c02; /* jmp 0xa04c02 */
L_00a04bd6:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13b0cu))); /* mov ecx, dword ptr [0x10013b0c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0xa13b10u)))); /* sub ecx, dword ptr [0x10013b10] */
    W32((uint32_t)(0xa13b10u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b10], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0xa13b0cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x10013b0c], ecx */
L_00a04bf3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0xa13b0cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x10013b0c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a04c02:;
    PUSH32(c, 0x00a04c07u); f_00a0662c(c); /* call 0xa0662c */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a04c0b(CPU *c) { /* PTR_00a04c0b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00a04c14u); f_00a04b8d(c); /* call 0xa04b8d */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_00a04c1d(CPU *c) { /* PTR_00a04c1d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x00a04c27u); f_00a06a6c(c); /* call 0xa06a6c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xa13b10u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b10], eax */
    if (!c->zf) goto L_00a04c3e; /* jne 0xa04c3e */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00a04c38u); f_00a04e41(c); /* call 0xa04e41 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13b10u))); /* mov eax, dword ptr [0x10013b10] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a04c3e:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13b10u))); /* mov eax, dword ptr [0x10013b10] */
    W32((uint32_t)(0xa13b0cu), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b0c], eax */
    c->esp += 4; return; /* ret  */
}

void f_00a04c4c(CPU *c) { /* FUN_10004c4c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0xa0e2d0u)); /* mov dword ptr [esi], 0x1000e2d0 */
    PUSH32(c, 0x00a04c5cu); f_00a06c3b(c); /* call 0xa06c3b */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a04c6b; /* je 0xa04c6b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a04c6au); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a04c6b:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00a04c72u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a04c75(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x00a04c7du); f_00a04c4c(c); /* call 0xa04c4c */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_00a04c8b; /* je 0xa04c8b */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a04c8au); f_00a02ba0(c); /* call 0xa02ba0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a04c8b:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a04c91(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0xa0e2d8u); /* mov esi, 0x1000e2d8 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea edi, [ebp - 0x20] */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t t_ = R32((uint32_t)(0xa0e008u)); PUSH32(c, 0x00a04cc5u); call_indirect(c, t_); } /* call dword ptr [0x1000e008] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_00a04ccb(CPU *c) { /* FUN_10004ccb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00a04d60; /* jne 0xa04d60 */
    { uint32_t t_ = R32((uint32_t)(0xa0e010u)); PUSH32(c, 0x00a04cdeu); call_indirect(c, t_); } /* call dword ptr [0x1000e010] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0xa13440u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013440], eax */
    PUSH32(c, 0x00a04ceau); f_00a07645(c); /* call 0xa07645 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a04d2b; /* je 0xa04d2b */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13440u))); /* mov eax, dword ptr [0x10013440] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xa13441u))); /* mov cl, byte ptr [0x10013441] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0xa13440u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x10013440], 0x10 */
    W32((uint32_t)(0xa13448u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013448], eax */
    W32((uint32_t)(0xa1344cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1001344c], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0xa13444u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013444], eax */
    PUSH32(c, 0x00a04d22u); f_00a05313(c); /* call 0xa05313 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a04d2f; /* jne 0xa04d2f */
    PUSH32(c, 0x00a04d2bu); f_00a076a2(c); /* call 0xa076a2 */
L_00a04d2b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a04da1; /* jmp 0xa04da1 */
L_00a04d2f:;
    { uint32_t t_ = R32((uint32_t)(0xa0e00cu)); PUSH32(c, 0x00a04d35u); call_indirect(c, t_); } /* call dword ptr [0x1000e00c] */
    W32((uint32_t)(0xa13b14u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013b14], eax */
    PUSH32(c, 0x00a04d3fu); f_00a0739e(c); /* call 0xa0739e */
    W32((uint32_t)(0xa1342cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1001342c], eax */
    PUSH32(c, 0x00a04d49u); f_00a06e88(c); /* call 0xa06e88 */
    PUSH32(c, 0x00a04d4eu); f_00a07151(c); /* call 0xa07151 */
    PUSH32(c, 0x00a04d53u); f_00a07098(c); /* call 0xa07098 */
    PUSH32(c, 0x00a04d58u); f_00a06531(c); /* call 0xa06531 */
    { uint32_t a_ = (uint32_t)(0xa13428u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10013428] */
    goto L_00a04d9e; /* jmp 0xa04d9e */
L_00a04d60:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_00a04d92; /* jne 0xa04d92 */
    (void)sub32(c, R32((uint32_t)(0xa13428u)), c->ecx); /* cmp dword ptr [0x10013428], ecx */
    if ((c->zf || c->sf != c->of)) goto L_00a04d2b; /* jle 0xa04d2b */
    { uint32_t a_ = (uint32_t)(0xa13428u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10013428] */
    (void)sub32(c, R32((uint32_t)(0xa13478u)), c->ecx); /* cmp dword ptr [0x10013478], ecx */
    if (!c->zf) goto L_00a04d81; /* jne 0xa04d81 */
    PUSH32(c, 0x00a04d81u); f_00a0656f(c); /* call 0xa0656f */
L_00a04d81:;
    PUSH32(c, 0x00a04d86u); f_00a07044(c); /* call 0xa07044 */
    PUSH32(c, 0x00a04d8bu); f_00a05367(c); /* call 0xa05367 */
    PUSH32(c, 0x00a04d90u); f_00a076a2(c); /* call 0xa076a2 */
    goto L_00a04d9e; /* jmp 0xa04d9e */
L_00a04d92:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00a04d9e; /* jne 0xa04d9e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00a04d9du); f_00a053ff(c); /* call 0xa053ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a04d9e:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a04da1:;
    c->esp += 16; return; /* ret 0xc */
}

void f_00a04da4(CPU *c) { /* entry */
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
    if (!c->zf) goto L_00a04dc0; /* jne 0xa04dc0 */
    (void)sub32(c, R32((uint32_t)(0xa13428u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013428], 0 */
    goto L_00a04de6; /* jmp 0xa04de6 */
L_00a04dc0:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_00a04dca; /* je 0xa04dca */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_00a04dec; /* jne 0xa04dec */
L_00a04dca:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa13b18u))); /* mov eax, dword ptr [0x10013b18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a04ddc; /* je 0xa04ddc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a04dd8u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a04de8; /* je 0xa04de8 */
L_00a04ddc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a04de4u); f_00a04ccb(c); /* call 0xa04ccb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_00a04de6:;
    if (!c->zf) goto L_00a04dec; /* jne 0xa04dec */
L_00a04de8:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a04e3a; /* jmp 0xa04e3a */
L_00a04dec:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a04df4u); f_00a0774a(c); /* call 0xa0774a */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00a04e08; /* jne 0xa04e08 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a04e37; /* jne 0xa04e37 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a04e08u); f_00a04ccb(c); /* call 0xa04ccb */
L_00a04e08:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a04e11; /* je 0xa04e11 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_00a04e37; /* jne 0xa04e37 */
L_00a04e11:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a04e19u); f_00a04ccb(c); /* call 0xa04ccb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a04e20; /* jne 0xa04e20 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_00a04e20:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_00a04e37; /* je 0xa04e37 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13b18u))); /* mov eax, dword ptr [0x10013b18] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a04e37; /* je 0xa04e37 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a04e34u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_00a04e37:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00a04e3a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_00a04e41(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa13434u))); /* mov eax, dword ptr [0x10013434] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00a04e58; /* je 0xa04e58 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a04e5d; /* jne 0xa04e5d */
    (void)sub32(c, R32((uint32_t)(0xa13438u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013438], 1 */
    if (!c->zf) goto L_00a04e5d; /* jne 0xa04e5d */
L_00a04e58:;
    PUSH32(c, 0x00a04e5du); f_00a07750(c); /* call 0xa07750 */
L_00a04e5d:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00a04e66u); f_00a07789(c); /* call 0xa07789 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0xa103ecu)); PUSH32(c, 0x00a04e71u); call_indirect(c, t_); } /* call dword ptr [0x100103ec] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a04e71(CPU *c) { /* PTR_00a04e71 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a04e74(CPU *c) { /* FUN_10004e74 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x00a04e83u); f_00a07911(c); /* call 0xa07911 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a04e86(CPU *c) { /* FUN_10004e86 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0xa0e308u))); /* fld qword ptr [0x1000e308] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0xa0e300u))); /* fld qword ptr [0x1000e300] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e2f8u))); FPOP(c); /* fcomp qword ptr [0x1000e2f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00a04ec0; /* jbe 0xa04ec0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a04ec0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a04ec4(CPU *c) { /* FUN_10004ec4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa0e32cu; PUSH32(c, v_); } /* push 0x1000e32c */
    { uint32_t t_ = R32((uint32_t)(0xa0e018u)); PUSH32(c, 0x00a04ecfu); call_indirect(c, t_); } /* call dword ptr [0x1000e018] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a04ee8; /* je 0xa04ee8 */
    { uint32_t v_ = 0xa0e310u; PUSH32(c, v_); } /* push 0x1000e310 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e014u)); PUSH32(c, 0x00a04edfu); call_indirect(c, t_); } /* call dword ptr [0x1000e014] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a04ee8; /* je 0xa04ee8 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a04ee7u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_00a04ee8:;
    { f_00a04e86(c); return; } /* jmp 0xa04e86 */
}

void f_00a04eed(CPU *c) { /* FUN_10004eed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a04efbu); f_00a07ab7(c); /* call 0xa07ab7 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a04f2d; /* je 0xa04f2d */
L_00a04f01:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0xa10628u)), (uint32_t)0x1u); /* cmp dword ptr [0x10010628], 1 */
    if ((c->zf || c->sf != c->of)) goto L_00a04f1a; /* jle 0xa04f1a */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a04f16u); f_00a07a42(c); /* call 0xa07a42 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a04f29; /* jmp 0xa04f29 */
L_00a04f1a:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa10634u))); /* mov ecx, dword ptr [0x10010634] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_00a04f29:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a04f01; /* jne 0xa04f01 */
L_00a04f2d:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xa1062cu))); /* mov cl, byte ptr [0x1001062c] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a04f38:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00a04f38; /* jne 0xa04f38 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a04f47(CPU *c) { /* PTR_00a04f47 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xa1062cu))); /* mov dl, byte ptr [0x1001062c] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00a04f63; /* je 0xa04f63 */
L_00a04f57:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_00a04f63; /* je 0xa04f63 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_00a04f57; /* jne 0xa04f57 */
L_00a04f63:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00a04f94; /* je 0xa04f94 */
L_00a04f6a:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00a04f7d; /* je 0xa04f7d */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_00a04f7d; /* je 0xa04f7d */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_00a04f7d; /* je 0xa04f7d */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a04f6a; /* jmp 0xa04f6a */
L_00a04f7d:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_00a04f7f:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00a04f7f; /* je 0xa04f7f */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_00a04f8a; /* jne 0xa04f8a */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_00a04f8a:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_00a04f8a; /* jne 0xa04f8a */
L_00a04f94:;
    c->esp += 4; return; /* ret  */
}

void f_00a04f95(CPU *c) { /* PTR_00a04f95 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e338u))); FPOP(c); /* fcomp qword ptr [0x1000e338] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00a04faa; /* jb 0xa04faa */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00a04faa:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00a04fad(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_00a04fd6; /* je 0xa04fd6 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a04fc4u); f_00a07f83(c); /* call 0xa07f83 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a04fd6:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a04fdfu); f_00a07fb0(c); /* call 0xa07fb0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a04feb(CPU *c) { /* FUN_10004feb */
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
    PUSH32(c, 0x00a05009u); f_00a08054(c); /* call 0xa08054 */
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
    PUSH32(c, 0x00a05031u); f_00a07fdd(c); /* call 0xa07fdd */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a05043u); f_00a0504c(c); /* call 0xa0504c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0504c(CPU *c) { /* FUN_1000504c */
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
    if (c->zf) goto L_00a0507a; /* je 0xa0507a */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05078u); f_00a052ee(c); /* call 0xa052ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a0507a:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_00a05087; /* jne 0xa05087 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_00a05087:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_00a0509e; /* jle 0xa0509e */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xa1062cu))); /* mov cl, byte ptr [0x1001062c] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_00a0509e:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0xa0e340u; PUSH32(c, v_); } /* push 0x1000e340 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00a050b6u); f_00a08170(c); /* call 0xa08170 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_00a050c2; /* je 0xa050c2 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_00a050c2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_00a05107; /* je 0xa05107 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_00a050d6; /* jns 0xa050d6 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_00a050d6:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_00a050ed; /* jl 0xa050ed */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a050e2u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a050e9u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00a050ed:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_00a05104; /* jl 0xa05104 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a050f9u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a05100u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_00a05104:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_00a05107:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a0510e(CPU *c) { /* FUN_1000510e */
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
    PUSH32(c, 0x00a0512cu); f_00a08054(c); /* call 0xa08054 */
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
    PUSH32(c, 0x00a0514bu); f_00a07fdd(c); /* call 0xa07fdd */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a0515au); f_00a05163(c); /* call 0xa05163 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a05163(CPU *c) { /* FUN_10005163 */
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
    if (c->zf) goto L_00a05193; /* je 0xa05193 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_00a05193; /* jne 0xa05193 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_00a05193:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_00a051a0; /* jne 0xa051a0 */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_00a051a0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00a051b7; /* jg 0xa051b7 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a051afu); f_00a052ee(c); /* call 0xa052ee */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_00a051b9; /* jmp 0xa051b9 */
L_00a051b7:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00a051b9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_00a05203; /* jle 0xa05203 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a051c7u); f_00a052ee(c); /* call 0xa052ee */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0xa1062cu))); /* mov al, byte ptr [0x1001062c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00a05203; /* jge 0xa05203 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_00a051e2; /* je 0xa051e2 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_00a051e9; /* jmp 0xa051e9 */
L_00a051e2:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_00a051ec; /* jl 0xa051ec */
L_00a051e9:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00a051ec:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a051f5u); f_00a052ee(c); /* call 0xa052ee */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05200u); f_00a08260(c); /* call 0xa08260 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00a05203:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a0520a(CPU *c) { /* FUN_1000520a */
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
    PUSH32(c, 0x00a0522au); f_00a08054(c); /* call 0xa08054 */
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
    PUSH32(c, 0x00a0524cu); f_00a07fdd(c); /* call 0xa07fdd */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_00a05283; /* jl 0xa05283 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_00a05283; /* jge 0xa05283 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_00a0526f; /* je 0xa0526f */
L_00a05265:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_00a05265; /* jne 0xa05265 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_00a0526f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a0527eu); f_00a05163(c); /* call 0xa05163 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00a05298; /* jmp 0xa05298 */
L_00a05283:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a05295u); f_00a0504c(c); /* call 0xa0504c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00a05298:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0529d(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_00a052d8; /* je 0xa052d8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_00a052d8; /* je 0xa052d8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_00a052c5; /* jne 0xa052c5 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a052c0u); f_00a0510e(c); /* call 0xa0510e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_00a052c5:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a052d6u); f_00a0520a(c); /* call 0xa0520a */
    goto L_00a052e9; /* jmp 0xa052e9 */
L_00a052d8:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a052e9u); f_00a04feb(c); /* call 0xa04feb */
L_00a052e9:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a052ee(CPU *c) { /* FUN_100052ee */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a05311; /* je 0xa05311 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a05302u); f_00a08600(c); /* call 0xa08600 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a0530du); f_00a082c0(c); /* call 0xa082c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a05311:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a05313(CPU *c) { /* FUN_10005313 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a05319u); f_00a06ba6(c); /* call 0xa06ba6 */
    { uint32_t t_ = R32((uint32_t)(0xa0e024u)); PUSH32(c, 0x00a0531fu); call_indirect(c, t_); } /* call dword ptr [0x1000e024] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0xa10408u), (uint32_t)(c->eax)); /* mov dword ptr [0x10010408], eax */
    if (c->zf) goto L_00a05363; /* je 0xa05363 */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00a05332u); f_00a08684(c); /* call 0xa08684 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a05363; /* je 0xa05363 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xa10408u)); PUSH32(c, v_); } /* push dword ptr [0x10010408] */
    { uint32_t t_ = R32((uint32_t)(0xa0e020u)); PUSH32(c, 0x00a05347u); call_indirect(c, t_); } /* call dword ptr [0x1000e020] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05363; /* je 0xa05363 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a05351u); f_00a05385(c); /* call 0xa05385 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xa0e01cu)); PUSH32(c, 0x00a05358u); call_indirect(c, t_); } /* call dword ptr [0x1000e01c] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00a05363:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a05367(CPU *c) { /* FUN_10005367 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x00a0536cu); f_00a06bcf(c); /* call 0xa06bcf */
    c->eax = (uint32_t)(R32((uint32_t)(0xa10408u))); /* mov eax, dword ptr [0x10010408] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00a05384; /* je 0xa05384 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e028u)); PUSH32(c, 0x00a0537du); call_indirect(c, t_); } /* call dword ptr [0x1000e028] */
    { uint32_t a_ = (uint32_t)(0xa10408u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x10010408], 0xffffffff */
L_00a05384:;
    c->esp += 4; return; /* ret  */
}

void f_00a05385(CPU *c) { /* FUN_10005385 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0xa10870u)); /* mov dword ptr [eax + 0x50], 0x10010870 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_00a05398(CPU *c) { /* FUN_10005398 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa0e034u)); PUSH32(c, 0x00a053a0u); call_indirect(c, t_); } /* call dword ptr [0x1000e034] */
    { uint32_t v_ = R32((uint32_t)(0xa10408u)); PUSH32(c, v_); } /* push dword ptr [0x10010408] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e030u)); PUSH32(c, 0x00a053aeu); call_indirect(c, t_); } /* call dword ptr [0x1000e030] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00a053f3; /* jne 0xa053f3 */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x00a053bdu); f_00a08684(c); /* call 0xa08684 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a053eb; /* je 0xa053eb */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0xa10408u)); PUSH32(c, v_); } /* push dword ptr [0x10010408] */
    { uint32_t t_ = R32((uint32_t)(0xa0e020u)); PUSH32(c, 0x00a053d2u); call_indirect(c, t_); } /* call dword ptr [0x1000e020] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a053eb; /* je 0xa053eb */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a053dcu); f_00a05385(c); /* call 0xa05385 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0xa0e01cu)); PUSH32(c, 0x00a053e3u); call_indirect(c, t_); } /* call dword ptr [0x1000e01c] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_00a053f3; /* jmp 0xa053f3 */
L_00a053eb:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x00a053f2u); f_00a04e41(c); /* call 0xa04e41 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a053f3:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa0e02cu)); PUSH32(c, 0x00a053fau); call_indirect(c, t_); } /* call dword ptr [0x1000e02c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a053ff(CPU *c) { /* FUN_100053ff */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa10408u))); /* mov eax, dword ptr [0x10010408] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_00a0549e; /* je 0xa0549e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00a05423; /* jne 0xa05423 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e030u)); PUSH32(c, 0x00a0541du); call_indirect(c, t_); } /* call dword ptr [0x1000e030] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a0548f; /* je 0xa0548f */
L_00a05423:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05431; /* je 0xa05431 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05430u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a05431:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0543f; /* je 0xa0543f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a0543eu); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a0543f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0544d; /* je 0xa0544d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a0544cu); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a0544d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0545b; /* je 0xa0545b */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a0545au); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a0545b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05469; /* je 0xa05469 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05468u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a05469:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05477; /* je 0xa05477 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05476u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a05477:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0xa10870u); /* cmp eax, 0x10010870 */
    if (c->zf) goto L_00a05488; /* je 0xa05488 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05487u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a05488:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a0548eu); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a0548f:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa10408u)); PUSH32(c, v_); } /* push dword ptr [0x10010408] */
    { uint32_t t_ = R32((uint32_t)(0xa0e020u)); PUSH32(c, 0x00a0549du); call_indirect(c, t_); } /* call dword ptr [0x1000e020] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a0549e:;
    c->esp += 4; return; /* ret  */
}

void f_00a0549f(CPU *c) { /* FUN_1000549f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_00a054b5; /* je 0xa054b5 */
    PUSH32(c, 0x00a054b5u); f_00a05d6d(c); /* call 0xa05d6d */
L_00a054b5:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_00a054dd; /* je 0xa054dd */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_00a05533; /* je 0xa05533 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00a05533; /* jne 0xa05533 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a054d8u); f_00a057f4(c); /* call 0xa057f4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_00a05533; /* jmp 0xa05533 */
L_00a054dd:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_00a05533; /* je 0xa05533 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00a05517; /* jne 0xa05517 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_00a05517; /* jbe 0xa05517 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a05517; /* je 0xa05517 */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x00a05512u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00a05536; /* jmp 0xa05536 */
L_00a05517:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05530u); f_00a0553a(c); /* call 0xa0553a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00a05533:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a05536:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a0553a(CPU *c) { /* FUN_1000553a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_00a0555a; /* jl 0xa0555a */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_00a0555f; /* jl 0xa0555f */
L_00a0555a:;
    PUSH32(c, 0x00a0555fu); f_00a05d6d(c); /* call 0xa05d6d */
L_00a0555f:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00a056c2; /* jne 0xa056c2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00a055df; /* jne 0xa055df */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00a055df; /* jne 0xa055df */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00a055df; /* jne 0xa055df */
    PUSH32(c, 0x00a0558du); f_00a05398(c); /* call 0xa05398 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_00a056bd; /* je 0xa056bd */
    PUSH32(c, 0x00a0559cu); f_00a05398(c); /* call 0xa05398 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x00a055a4u); f_00a05398(c); /* call 0xa05398 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x00a055b6u); f_00a087c1(c); /* call 0xa087c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a055c1; /* jne 0xa055c1 */
    PUSH32(c, 0x00a055c1u); f_00a05d6d(c); /* call 0xa05d6d */
L_00a055c1:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00a056c2; /* jne 0xa056c2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00a055df; /* jne 0xa055df */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00a055df; /* jne 0xa055df */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_00a055df; /* jne 0xa055df */
    PUSH32(c, 0x00a055dfu); f_00a05d6d(c); /* call 0xa05d6d */
L_00a055df:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_00a056c2; /* jne 0xa056c2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_00a056c2; /* jne 0xa056c2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_00a056c2; /* jne 0xa056c2 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00a05611u); f_00a04802(c); /* call 0xa04802 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_00a05616:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_00a056ad; /* jae 0xa056ad */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_00a056a2; /* jg 0xa056a2 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00a056a2; /* jg 0xa056a2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_00a0569f; /* jle 0xa0569f */
L_00a0563b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_00a0566c; /* jle 0xa0566c */
L_00a0564d:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a0565au); f_00a05797(c); /* call 0xa05797 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a0567b; /* jne 0xa0567b */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_00a0564d; /* jg 0xa0564d */
L_00a0566c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a0563b; /* jg 0xa0563b */
    goto L_00a0569f; /* jmp 0xa0569f */
L_00a0567b:;
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
    PUSH32(c, 0x00a0569cu); f_00a058a8(c); /* call 0xa058a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00a0569f:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_00a056a2:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_00a05616; /* jmp 0xa05616 */
L_00a056ad:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_00a056bd; /* je 0xa056bd */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a056bbu); f_00a05c2c(c); /* call 0xa05c2c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a056bd:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a056c2:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_00a056e8; /* jne 0xa056e8 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a056e3u); f_00a056ed(c); /* call 0xa056ed */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_00a056bd; /* jmp 0xa056bd */
L_00a056e8:;
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a056ed(CPU *c) { /* FUN_100056ed */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a056f9u); f_00a05398(c); /* call 0xa05398 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_00a05720; /* je 0xa05720 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a05719u); f_00a046d7(c); /* call 0xa046d7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a05793; /* jne 0xa05793 */
L_00a05720:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x00a05737u); f_00a04802(c); /* call 0xa04802 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a0573c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_00a05793; /* jae 0xa05793 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_00a0578b; /* jl 0xa0578b */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_00a0578b; /* jg 0xa0578b */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a05765; /* je 0xa05765 */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_00a0578b; /* jne 0xa0578b */
L_00a05765:;
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
    PUSH32(c, 0x00a05788u); f_00a058a8(c); /* call 0xa058a8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_00a0578b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_00a0573c; /* jmp 0xa0573c */
L_00a05793:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a05797(CPU *c) { /* FUN_10005797 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a057ee; /* je 0xa057ee */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_00a057ee; /* je 0xa057ee */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_00a057c8; /* je 0xa057c8 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x00a057c2u); f_00a06da0(c); /* call 0xa06da0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a057ea; /* jne 0xa057ea */
L_00a057c8:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_00a057d2; /* je 0xa057d2 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_00a057ea; /* je 0xa057ea */
L_00a057d2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00a057e1; /* je 0xa057e1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_00a057ea; /* je 0xa057ea */
L_00a057e1:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_00a057ee; /* je 0xa057ee */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_00a057ee; /* jne 0xa057ee */
L_00a057ea:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_00a057f1; /* jmp 0xa057f1 */
L_00a057ee:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a057f1:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a057f4(CPU *c) { /* FUN_100057f4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e348u; PUSH32(c, v_); } /* push 0x1000e348 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
L_00a05826:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00a05880; /* je 0xa05880 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00a05835; /* jle 0xa05835 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00a0583a; /* jl 0xa0583a */
L_00a05835:;
    PUSH32(c, 0x00a0583au); f_00a05d6d(c); /* call 0xa05d6d */
L_00a0583a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05855; /* je 0xa05855 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05855u); f_00a05cc0(c); /* call 0xa05cc0 */
L_00a05855:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00a05875; /* jmp 0xa05875 */
L_00a05875:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00a05826; /* jmp 0xa05826 */
L_00a05880:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a05826(CPU *c) { /* PTR_00a05826 */
    PREEMPT_POLL(c);
L_00a05826:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_00a05880; /* je 0xa05880 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_00a05835; /* jle 0xa05835 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_00a0583a; /* jl 0xa0583a */
L_00a05835:;
    PUSH32(c, 0x00a0583au); f_00a05d6d(c); /* call 0xa05d6d */
L_00a0583a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05855; /* je 0xa05855 */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05855u); f_00a05cc0(c); /* call 0xa05cc0 */
L_00a05855:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_00a05875; /* jmp 0xa05875 */
L_00a05875:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_00a05826; /* jmp 0xa05826 */
L_00a05880:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0585b(CPU *c) { /* PTR_00a0585b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00a05863u); f_00a05892(c); /* call 0xa05892 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a05865(CPU *c) { /* PTR_00a05865 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_00a05826(c); return; } /* jmp 0xa05826 */
}

void f_00a05892(CPU *c) { /* FUN_10005892 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_00a058a3; /* je 0xa058a3 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a058a3:;
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a058a8(CPU *c) { /* FUN_100058a8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_00a058ca; /* je 0xa058ca */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a058c7u); f_00a05a68(c); /* call 0xa05a68 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00a058ca:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_00a058d6; /* jne 0xa058d6 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_00a058d9; /* jmp 0xa058d9 */
L_00a058d6:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_00a058d9:;
    PUSH32(c, 0x00a058deu); f_00a045d9(c); /* call 0xa045d9 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a058efu); f_00a057f4(c); /* call 0xa057f4 */
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
    PUSH32(c, 0x00a05910u); f_00a05923(c); /* call 0xa05923 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0591e; /* je 0xa0591e */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a0591eu); f_00a04597(c); /* call 0xa04597 */
L_00a0591e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a05923(CPU *c) { /* FUN_10005923 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e358u; PUSH32(c, v_); } /* push 0x1000e358 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
    PUSH32(c, 0x00a05961u); f_00a05398(c); /* call 0xa05398 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x00a0596cu); f_00a05398(c); /* call 0xa05398 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x00a05977u); f_00a05398(c); /* call 0xa05398 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x00a05982u); f_00a05398(c); /* call 0xa05398 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a059a3u); f_00a0465e(c); /* call 0xa0465e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a059b6u); f_00a059f0(c); /* call 0xa059f0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a059b9(CPU *c) { /* PTR_00a059b9 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a059c8(CPU *c) { /* PTR_00a059c8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x00a059d0u); f_00a05a3e(c); /* call 0xa05a3e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a059d2(CPU *c) { /* PTR_00a059d2 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a059e4u); f_00a048c2(c); /* call 0xa048c2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_00a059b9(c); return; } /* jmp 0xa059b9 */
}

void f_00a059ea(CPU *c) { /* PTR_00a059ea */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_00a059f0(c); return; }
}

void f_00a059f0(CPU *c) { /* FUN_100059f0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x00a059fbu); f_00a05398(c); /* call 0xa05398 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x00a05a06u); f_00a05398(c); /* call 0xa05398 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_00a05a3d; /* jne 0xa05a3d */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_00a05a3d; /* jne 0xa05a3d */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_00a05a3d; /* jne 0xa05a3d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a05a3d; /* jne 0xa05a3d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_00a05a3d; /* je 0xa05a3d */
    PUSH32(c, 0x00a05a34u); f_00a0492a(c); /* call 0xa0492a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05a3bu); f_00a05c2c(c); /* call 0xa05c2c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a05a3d:;
    c->esp += 4; return; /* ret  */
}

void f_00a05a3e(CPU *c) { /* FUN_10005a3e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00a05a65; /* jne 0xa05a65 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00a05a65; /* jne 0xa05a65 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00a05a65; /* jne 0xa05a65 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_00a05a65; /* jne 0xa05a65 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00a05a65:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00a05a68(CPU *c) { /* FUN_10005a68 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e370u; PUSH32(c, v_); } /* push 0x1000e370 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
    if (c->zf) goto L_00a05c11; /* je 0xa05c11 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_00a05c11; /* je 0xa05c11 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c11; /* je 0xa05c11 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_00a05b05; /* je 0xa05b05 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00a05aceu); f_00a087c1(c); /* call 0xa087c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05ae0u); f_00a087dd(c); /* call 0xa087dd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_00a05af6:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a05afcu); f_00a05c93(c); /* call 0xa05c93 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_00a05c0d; /* jmp 0xa05c0d */
L_00a05b05:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_00a05b5f; /* je 0xa05b5f */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00a05b1au); f_00a087c1(c); /* call 0xa087c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05b2cu); f_00a087dd(c); /* call 0xa087dd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05b42u); f_00a082c0(c); /* call 0xa082c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_00a05c0d; /* jne 0xa05c0d */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c0d; /* je 0xa05c0d */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00a05af6; /* jmp 0xa05af6 */
L_00a05b5f:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_00a05ba7; /* jne 0xa05ba7 */
    PUSH32(c, 0x00a05b72u); f_00a087c1(c); /* call 0xa087c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05b84u); f_00a087dd(c); /* call 0xa087dd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00a05b99u); f_00a05c93(c); /* call 0xa05c93 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05ba2u); f_00a082c0(c); /* call 0xa082c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_00a05c0d; /* jmp 0xa05c0d */
L_00a05ba7:;
    PUSH32(c, 0x00a05bacu); f_00a087c1(c); /* call 0xa087c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05bbau); f_00a087dd(c); /* call 0xa087dd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x00a05bc8u); f_00a087f9(c); /* call 0xa087f9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05c08; /* je 0xa05c08 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_00a05bee; /* je 0xa05bee */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00a05be0u); f_00a05c93(c); /* call 0xa05c93 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05becu); f_00a045d2(c); /* call 0xa045d2 */
    goto L_00a05c0d; /* jmp 0xa05c0d */
L_00a05bee:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x00a05bfau); f_00a05c93(c); /* call 0xa05c93 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a05c06u); f_00a045cb(c); /* call 0xa045cb */
    goto L_00a05c0d; /* jmp 0xa05c0d */
L_00a05c08:;
    PUSH32(c, 0x00a05c0du); f_00a05d6d(c); /* call 0xa05d6d */
L_00a05c0d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00a05c11:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a05c20(CPU *c) { /* PTR_00a05c20 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a05c24(CPU *c) { /* PTR_00a05c24 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a05c2c(CPU *c) { /* FUN_10005c2c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e380u; PUSH32(c, v_); } /* push 0x1000e380 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
    if (c->zf) goto L_00a05c73; /* je 0xa05c73 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a05c73; /* je 0xa05c73 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x00a05c6fu); f_00a045cb(c); /* call 0xa045cb */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_00a05c73:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a05c82(CPU *c) { /* PTR_00a05c82 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_00a05c8b(CPU *c) { /* PTR_00a05c8b */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a05c93(CPU *c) { /* FUN_10005c93 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_00a05cb4; /* jl 0xa05cb4 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_00a05cb4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a05cc0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x00a05ce3u); f_00a0494d(c); /* call 0xa0494d */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a05ce7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_00a05cff; /* jne 0xa05cff */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_00a05cff:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x00a05d05u); f_00a0494d(c); /* call 0xa0494d */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_00a05d0c(CPU *c) { /* FUN_10005d0c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e390u; PUSH32(c, v_); } /* push 0x1000e390 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
    PUSH32(c, 0x00a05d3bu); f_00a05398(c); /* call 0xa05398 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_00a05d5f; /* je 0xa05d5f */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x00a05d4cu); f_00a05398(c); /* call 0xa05398 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x00a05d4fu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_00a05d5f; /* jmp 0xa05d5f */
L_00a05d5f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a05d68u); f_00a05d68(c); /* call 0xa05d68 */
    { f_00a088f4(c); return; } /* jmp 0xa088f4 */
}

void f_00a05d54(CPU *c) { /* PTR_00a05d54 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a05d58(CPU *c) { /* PTR_00a05d58 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a05d68u); f_00a05d68(c); /* call 0xa05d68 */
    { f_00a088f4(c); return; } /* jmp 0xa088f4 */
}

void f_00a05d68(CPU *c) { /* PTR_00a05d68 */
    PREEMPT_POLL(c);
    { f_00a088f4(c); return; } /* jmp 0xa088f4 */
}

void f_00a05d6d(CPU *c) { /* FUN_10005d6d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e3a8u; PUSH32(c, v_); } /* push 0x1000e3a8 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
    c->eax = (uint32_t)(R32((uint32_t)(0xa10410u))); /* mov eax, dword ptr [0x10010410] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a05db5; /* je 0xa05db5 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a05da8u); call_indirect(c, t_); } /* call eax */
    goto L_00a05db1; /* jmp 0xa05db1 */
L_00a05db1:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_00a05db5:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a05dbeu); f_00a05dbe(c); /* call 0xa05dbe */
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a05daa(CPU *c) { /* PTR_00a05daa */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a05dae(CPU *c) { /* PTR_00a05dae */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a05dbeu); f_00a05dbe(c); /* call 0xa05dbe */
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a05dbe(CPU *c) { /* PTR_00a05dbe */
    PREEMPT_POLL(c);
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
}

void f_00a05dd0(CPU *c) { /* PTR_00a05dd0 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0xfeu)); /* mov byte ptr [ebp - 0x90], 0xfe */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (!c->zf) goto L_00a05e26; /* jne 0xa05e26 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_00a05ddd:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    goto L_00a05dee; /* jmp 0xa05dee */
L_00a05dee:;
    PUSH32(c, 0x00a05df3u); f_00a05f2e(c); /* call 0xa05f2e */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (c->zf) goto L_00a05e14; /* je 0xa05e14 */
    FPUSH(c, 1.0); /* fld1  */
    (void)sub32(c, R32((uint32_t)(0xa13424u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013424], 1 */
    if (c->zf) goto L_00a05e0f; /* je 0xa05e0f */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    goto L_00a05e14; /* jmp 0xa05e14 */
L_00a05e0f:;
    PUSH32(c, 0x00a05e14u); f_00a09101(c); /* call 0xa09101 */
L_00a05e14:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x40u)); /* test dl, 0x40 */
    if (!c->zf) goto L_00a05e1b; /* jne 0xa05e1b */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
L_00a05e1b:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00a05e21; /* je 0xa05e21 */
    ST(0) = -ST(0); /* fchs  */
L_00a05e21:;
    goto L_00a060d8; /* jmp 0xa060d8 */
L_00a05e26:;
    PUSH32(c, 0x00a05e2bu); f_00a05f71(c); /* call 0xa05f71 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_00a05e43; /* je 0xa05e43 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, 0)) << 8); /* xor ch, ch */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00a05e38; /* je 0xa05e38 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)~((uint8_t)(c->ecx >> 8))) << 8); /* not ch */
L_00a05e38:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fabs(ST(0)); /* fabs  */
    goto L_00a05ddd; /* jmp 0xa05ddd */
L_00a05e43:;
    goto L_00a06186; /* jmp 0xa06186 */
L_00a060d8:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
L_00a06186:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0xa10480u))); /* fld xword ptr [0x10010480] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffff70u)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x90], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_00a061a0; /* jg 0xa061a0 */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_00a061a0:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_00a05ee0(CPU *c) { /* PTR_00a05ee0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (!c->zf) goto L_00a05f03; /* jne 0xa05f03 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0xa10420u))); /* fld xword ptr [0x10010420] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_00a05f02; /* je 0xa05f02 */
    ST(0) = -ST(0); /* fchs  */
L_00a05f02:;
    c->esp += 4; return; /* ret  */
L_00a05f03:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [ebp - 0x90], 4 */
    goto L_00a060e6; /* jmp 0xa060e6 */
L_00a060e6:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 0.0); /* fldz  */
    c->esp += 4; return; /* ret  */
}

void f_00a05f2e(CPU *c) { /* PTR_00a05f2e */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, RF80((uint32_t)(0xa1043eu))); /* fld xword ptr [0x1001043e] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x41u)); /* test byte ptr [ebp - 0x9f], 0x41 */
    if (!c->zf) { f_00a05ee0(c); return; } /* jne 0xa05ee0 */
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

void f_00a05f71(CPU *c) { /* PTR_00a05f71 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00a05f97; /* jne 0xa05f97 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xa10452u))); /* fmul qword ptr [0x10010452] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_00a05f9e; /* je 0xa05f9e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_00a05f96:;
    c->esp += 4; return; /* ret  */
L_00a05f97:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_00a05f96; /* jmp 0xa05f96 */
L_00a05f9e:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_00a05f96; /* jmp 0xa05f96 */
}

void f_00a05fe0(CPU *c) { /* PTR_00a05fe0 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_00a05ff7; /* jne 0xa05ff7 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_00a05ffb; /* jmp 0xa05ffb */
L_00a05ff7:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_00a05ffb:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0xa1049cu); /* mov ebx, 0x1001049c */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x00a06045u); return; } } /* jmp dword ptr [ebx] */
}

void f_00a061b0(CPU *c) { /* FUN_100061b0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe0u)); /* add esp, -0x20 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    { f_00a061d0(c); return; } /* jmp 0xa061d0 */
}

void f_00a061c7(CPU *c) { /* __startOneArgErrorHandling */
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
    PUSH32(c, 0x00a061f0u); f_00a0969b(c); /* call 0xa0969b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_00a06201; /* je 0xa06201 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_00a06201:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a061d0(CPU *c) { /* PTR_00a061d0 */
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
    PUSH32(c, 0x00a061f0u); f_00a0969b(c); /* call 0xa0969b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_00a06201; /* je 0xa06201 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_00a06201:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06210(CPU *c) { /* FUN_10006210 */
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

void f_00a06225(CPU *c) { /* FUN_10006225 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x300u))); /* and edx, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x7fu))); /* or edx, 0x7f */
    W16((uint32_t)(c->esp + 0x6u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esp + 6], dx */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x6u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 6] */
    c->esp += 4; return; /* ret  */
}

void f_00a0623c(CPU *c) { /* PTR_00a0623c */
    PREEMPT_POLL(c);
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000u)); /* test eax, 0x80000 */
    if (c->zf) goto L_00a06249; /* je 0xa06249 */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    c->esp += 4; return; /* ret  */
L_00a06249:;
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0xa0e3c0u))); /* fadd qword ptr [0x1000e3c0] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}

void f_00a06255(CPU *c) { /* __fload_withFB */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00a06267; /* je 0xa06267 */
    FPUSH(c, RF64((uint32_t)(c->edx))); /* fld qword ptr [edx] */
    c->esp += 4; return; /* ret  */
L_00a06267:;
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

void f_00a06298(CPU *c) { /* PTR_00a06298 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00a062a9; /* je 0xa062a9 */
    c->esp += 4; return; /* ret  */
L_00a062a9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->esp += 4; return; /* ret  */
}

void f_00a062ae(CPU *c) { /* FUN_100062ae */
    PREEMPT_POLL(c);
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_00a062b9; /* je 0xa062b9 */
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00a062b9:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00a062bb(CPU *c) { /* PTR_00a062bb */
    PREEMPT_POLL(c);
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_00a062e3; /* je 0xa062e3 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00a062e0; /* je 0xa062e0 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00a062e0; /* je 0xa062e0 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
    PUSH32(c, 0x00a062deu); f_00a061c7(c); /* call 0xa061c7 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00a062e0:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00a062e3:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_00a062f9(CPU *c) { /* FUN_100062f9 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    if (c->zf) goto L_00a0634a; /* je 0xa0634a */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (c->zf) goto L_00a06373; /* je 0xa06373 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->esp))); /* mov ax, word ptr [esp] */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x27fu); /* cmp ax, 0x27f */
    if (c->zf) goto L_00a06348; /* je 0xa06348 */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (!c->zf) goto L_00a06345; /* jne 0xa06345 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x20u))); /* and ax, 0x20 */
    if (c->zf) goto L_00a06345; /* je 0xa06345 */
    c->eax = (uint32_t)((uint32_t)0x8u); /* mov eax, 8 */
L_00a06332:;
    (void)sub32(c, c->edx, (uint32_t)0x1du); /* cmp edx, 0x1d */
    if (c->zf) goto L_00a0633e; /* je 0xa0633e */
    PUSH32(c, 0x00a0633cu); f_00a061c7(c); /* call 0xa061c7 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00a0633e:;
    PUSH32(c, 0x00a06343u); f_00a061b0(c); /* call 0xa061b0 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00a06345:;
    c->fpu_cw = R16((uint32_t)(c->esp)); fpu_sync_rounding(c); /* fldcw word ptr [esp] */
L_00a06348:;
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_00a0634a:;
    FPUSH(c, RF64((uint32_t)(0xa0e3ecu))); /* fld qword ptr [0x1000e3ec] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e3dcu))); FPOP(c); /* fcomp qword ptr [0x1000e3dc] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x4u); /* mov eax, 4 */
    if (!c->cf) goto L_00a06332; /* jae 0xa06332 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xa0e3fcu))); /* fmul qword ptr [0x1000e3fc] */
    goto L_00a06332; /* jmp 0xa06332 */
L_00a06373:;
    FPUSH(c, RF64((uint32_t)(0xa0e3e4u))); /* fld qword ptr [0x1000e3e4] */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
    ST(1) = ST(0); FPOP(c); /* fstp st(1) */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e3d4u))); FPOP(c); /* fcomp qword ptr [0x1000e3d4] */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
    if ((c->cf || c->zf)) goto L_00a06332; /* jbe 0xa06332 */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0xa0e3f4u))); /* fmul qword ptr [0x1000e3f4] */
    goto L_00a06332; /* jmp 0xa06332 */
}

void f_00a0639c(CPU *c) { /* FUN_1000639c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e338u))); FPOP(c); /* fcomp qword ptr [0x1000e338] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00a063b9; /* jae 0xa063b9 */
    ST(0) = -ST(0); /* fchs  */
L_00a063b9:;
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    c->eax = (uint32_t)((uint32_t)0x7ff00000u); /* mov eax, 0x7ff00000 */
    c->ecx = (uint32_t)((uint32_t)0xfff00000u); /* mov ecx, 0xfff00000 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->eax); /* cmp dword ptr [ebp + 0x14], eax */
    if (!c->zf) goto L_00a063ff; /* jne 0xa063ff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edx); /* cmp dword ptr [ebp + 0x10], edx */
    if (!c->zf) goto L_00a06427; /* jne 0xa06427 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e2f8u))); FPOP(c); /* fcomp qword ptr [0x1000e2f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00a06443; /* ja 0xa06443 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e2f8u))); FPOP(c); /* fcomp qword ptr [0x1000e2f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_00a06459; /* jb 0xa06459 */
L_00a063ec:;
    FPUSH(c, RF64((uint32_t)(0xa10a68u))); /* fld qword ptr [0x10010a68] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
    goto L_00a064c7; /* jmp 0xa064c7 */
L_00a063ff:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), c->ecx); /* cmp dword ptr [ebp + 0x14], ecx */
    if (!c->zf) goto L_00a06427; /* jne 0xa06427 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->edx); /* cmp dword ptr [ebp + 0x10], edx */
    if (!c->zf) goto L_00a06427; /* jne 0xa06427 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e2f8u))); FPOP(c); /* fcomp qword ptr [0x1000e2f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((!c->cf && !c->zf)) goto L_00a06459; /* ja 0xa06459 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e2f8u))); FPOP(c); /* fcomp qword ptr [0x1000e2f8] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00a063ec; /* jae 0xa063ec */
    goto L_00a06443; /* jmp 0xa06443 */
L_00a06427:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->eax); /* cmp dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_00a0645d; /* jne 0xa0645d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_00a064c7; /* jne 0xa064c7 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e338u))); FPOP(c); /* fcomp qword ptr [0x1000e338] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00a0644b; /* jbe 0xa0644b */
L_00a06443:;
    FPUSH(c, RF64((uint32_t)(0xa10a60u))); /* fld qword ptr [0x10010a60] */
    goto L_00a064c2; /* jmp 0xa064c2 */
L_00a0644b:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e338u))); FPOP(c); /* fcomp qword ptr [0x1000e338] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00a064c0; /* jae 0xa064c0 */
L_00a06459:;
    FPUSH(c, 0.0); /* fldz  */
    goto L_00a064c2; /* jmp 0xa064c2 */
L_00a0645d:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ecx); /* cmp dword ptr [ebp + 0xc], ecx */
    if (!c->zf) goto L_00a064c7; /* jne 0xa064c7 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edx); /* cmp dword ptr [ebp + 8], edx */
    if (!c->zf) goto L_00a064c7; /* jne 0xa064c7 */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00a06474u); f_00a064cc(c); /* call 0xa064cc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e338u))); FPOP(c); /* fcomp qword ptr [0x1000e338] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_00a0649b; /* jbe 0xa0649b */
    FPUSH(c, RF64((uint32_t)(0xa10a60u))); /* fld qword ptr [0x10010a60] */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (!c->zf) goto L_00a06493; /* jne 0xa06493 */
    ST(0) = -ST(0); /* fchs  */
L_00a06493:;
    WF64((uint32_t)(c->ebp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    goto L_00a064c2; /* jmp 0xa064c2 */
L_00a0649b:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    FCOM(c, ST(0), RF64((uint32_t)(0xa0e338u))); FPOP(c); /* fcomp qword ptr [0x1000e338] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->cf) goto L_00a064c0; /* jae 0xa064c0 */
    (void)sub32(c, c->ecx, (uint32_t)0x1u); /* cmp ecx, 1 */
    if (!c->zf) goto L_00a064b6; /* jne 0xa064b6 */
    FPUSH(c, RF64((uint32_t)(0xa10a80u))); /* fld qword ptr [0x10010a80] */
    goto L_00a064b8; /* jmp 0xa064b8 */
L_00a064b6:;
    FPUSH(c, 0.0); /* fldz  */
L_00a064b8:;
    WF64((uint32_t)(c->ebp + 0x10u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x10u))); /* fld qword ptr [ebp + 0x10] */
    goto L_00a064c2; /* jmp 0xa064c2 */
L_00a064c0:;
    FPUSH(c, 1.0); /* fld1  */
L_00a064c2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    WF64((uint32_t)(c->eax), ST(0)); FPOP(c); /* fstp qword ptr [eax] */
L_00a064c7:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a064cc(CPU *c) { /* FUN_100064cc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00a064deu); f_00a098c1(c); /* call 0xa098c1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x90u)); /* test al, 0x90 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a0652d; /* jne 0xa0652d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00a064f1u); f_00a098af(c); /* call 0xa098af */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00a0652d; /* jne 0xa0652d */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(0xa0e408u)))); /* fdiv qword ptr [0x1000e408] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->ebp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp + 8] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x00a0651au); f_00a098af(c); /* call 0xa098af */
    FCOM(c, ST(0), RF64((uint32_t)(c->ebp + 0x8u))); FPOP(c); /* fcomp qword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_00a06528; /* jne 0xa06528 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00a0652a; /* jmp 0xa0652a */
L_00a06528:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00a0652a:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a0652d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06531(CPU *c) { /* FUN_10006531 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa103a0u))); /* mov eax, dword ptr [0x100103a0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0653c; /* je 0xa0653c */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a0653cu); call_indirect(c, t_); } /* call eax */
L_00a0653c:;
    { uint32_t v_ = 0xa1001cu; PUSH32(c, v_); } /* push 0x1001001c */
    { uint32_t v_ = 0xa1000cu; PUSH32(c, v_); } /* push 0x1001000c */
    PUSH32(c, 0x00a0654bu); f_00a06635(c); /* call 0xa06635 */
    { uint32_t v_ = 0xa10008u; PUSH32(c, v_); } /* push 0x10010008 */
    { uint32_t v_ = 0xa10000u; PUSH32(c, v_); } /* push 0x10010000 */
    PUSH32(c, 0x00a0655au); f_00a06635(c); /* call 0xa06635 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_00a0655e(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00a0656bu); f_00a0657e(c); /* call 0xa0657e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00a0656f(CPU *c) { /* FUN_1000656f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x00a0657au); f_00a0657e(c); /* call 0xa0657e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00a0657e(CPU *c) { /* FUN_1000657e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a06584u); f_00a06623(c); /* call 0xa06623 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0xa1347cu)), c->edi); /* cmp dword ptr [0x1001347c], edi */
    if (!c->zf) goto L_00a065a0; /* jne 0xa065a0 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0xa0e040u)); PUSH32(c, 0x00a06599u); call_indirect(c, t_); } /* call dword ptr [0x1000e040] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e03cu)); PUSH32(c, 0x00a065a0u); call_indirect(c, t_); } /* call dword ptr [0x1000e03c] */
L_00a065a0:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0xa13478u), (uint32_t)(c->edi)); /* mov dword ptr [0x10013478], edi */
    W8((uint32_t)(0xa13474u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x10013474], bl */
    if (!c->zf) goto L_00a065f4; /* jne 0xa065f4 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13b10u))); /* mov eax, dword ptr [0x10013b10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a065e3; /* je 0xa065e3 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13b0cu))); /* mov ecx, dword ptr [0x10013b0c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_00a065e2; /* jb 0xa065e2 */
L_00a065cf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a065d7; /* je 0xa065d7 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a065d7u); call_indirect(c, t_); } /* call eax */
L_00a065d7:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa13b10u))); /* cmp esi, dword ptr [0x10013b10] */
    if (!c->cf) goto L_00a065cf; /* jae 0xa065cf */
L_00a065e2:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a065e3:;
    { uint32_t v_ = 0xa10024u; PUSH32(c, v_); } /* push 0x10010024 */
    { uint32_t v_ = 0xa10020u; PUSH32(c, v_); } /* push 0x10010020 */
    PUSH32(c, 0x00a065f2u); f_00a06635(c); /* call 0xa06635 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a065f4:;
    { uint32_t v_ = 0xa10030u; PUSH32(c, v_); } /* push 0x10010030 */
    { uint32_t v_ = 0xa10028u; PUSH32(c, v_); } /* push 0x10010028 */
    PUSH32(c, 0x00a06603u); f_00a06635(c); /* call 0xa06635 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00a06611; /* je 0xa06611 */
    PUSH32(c, 0x00a0660fu); f_00a0662c(c); /* call 0xa0662c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a06611:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0xa1347cu), (uint32_t)(c->edi)); /* mov dword ptr [0x1001347c], edi */
    { uint32_t t_ = R32((uint32_t)(0xa0e038u)); PUSH32(c, 0x00a06621u); call_indirect(c, t_); } /* call dword ptr [0x1000e038] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a06621(CPU *c) { /* PTR_00a06621 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a06623(CPU *c) { /* FUN_10006623 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00a0662au); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a0662c(CPU *c) { /* FUN_1000662c */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x00a06633u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06635(CPU *c) { /* FUN_10006635 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_00a0663a:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_00a0664d; /* jae 0xa0664d */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06648; /* je 0xa06648 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a06648u); call_indirect(c, t_); } /* call eax */
L_00a06648:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_00a0663a; /* jmp 0xa0663a */
L_00a0664d:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a0664f(CPU *c) { /* FUN_1000664f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e410u; PUSH32(c, v_); } /* push 0x1000e410 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
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
    if (!c->zf) goto L_00a06689; /* jne 0xa06689 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x00a06683u); f_00a06a6c(c); /* call 0xa06a6c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a0696f; /* jmp 0xa0696f */
L_00a06689:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00a0669c; /* jne 0xa0669c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a06696u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a0696d; /* jmp 0xa0696d */
L_00a0669c:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa139e8u))); /* mov eax, dword ptr [0x100139e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00a067e3; /* jne 0xa067e3 */
L_00a066aa:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a067a7; /* ja 0xa067a7 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a066bdu); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a066c7u); f_00a0999b(c); /* call 0xa0999b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00a06777; /* je 0xa06777 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa139e0u))); /* cmp esi, dword ptr [0x100139e0] */
    if ((!c->cf && !c->zf)) goto L_00a06727; /* ja 0xa06727 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a066e3u); f_00a0a1a4(c); /* call 0xa0a1a4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a066ef; /* je 0xa066ef */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_00a06727; /* jmp 0xa06727 */
L_00a066ef:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a066f5u); f_00a09cef(c); /* call 0xa09cef */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00a06727; /* je 0xa06727 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a0670a; /* jb 0xa0670a */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a0670a:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a06714u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0671au); f_00a0999b(c); /* call 0xa0999b */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06724u); f_00a099c6(c); /* call 0xa099c6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a06727:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_00a06777; /* jne 0xa06777 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00a06736; /* jne 0xa06736 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00a06736:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a0674du); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_00a06777; /* je 0xa06777 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06761; /* jb 0xa06761 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06761:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0676bu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00a06774u); f_00a099c6(c); /* call 0xa099c6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_00a06777:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06780u); f_00a067da(c); /* call 0xa067da */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_00a067a7; /* jne 0xa067a7 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00a0678c; /* jne 0xa0678c */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a0678c:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a067a4u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00a067a7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a0696f; /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) goto L_00a0696f; /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a067c4u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a066aa; /* jne 0xa066aa */
    goto L_00a0696d; /* jmp 0xa0696d */
L_00a067e3:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a06933; /* jne 0xa06933 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06803; /* ja 0xa06803 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00a067fd; /* jbe 0xa067fd */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00a06800; /* jmp 0xa06800 */
L_00a067fd:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a06800:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00a06803:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06902; /* ja 0xa06902 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06816u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0682cu); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a068e6; /* je 0xa068e6 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if (!c->cf) goto L_00a068a0; /* jae 0xa068a0 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a06856u); f_00a0aabe(c); /* call 0xa0aabe */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06865; /* je 0xa06865 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00a0689d; /* jmp 0xa0689d */
L_00a06865:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0686bu); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0689d; /* je 0xa0689d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06882; /* jb 0xa06882 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06882:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a0689d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a068a0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068e6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a068f6u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
L_00a06902:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a0696f; /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) goto L_00a0696f; /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06803; /* jne 0xa06803 */
    goto L_00a0696d; /* jmp 0xa0696d */
L_00a06933:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06956; /* ja 0xa06956 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00a06941; /* jne 0xa06941 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a06941:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a06956u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
L_00a06956:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a0696f; /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) goto L_00a0696f; /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06968u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06933; /* jne 0xa06933 */
L_00a0696d:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a0696f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a067d2(CPU *c) { /* PTR_00a067d2 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_00a067da(c); return; }
}

void f_00a067da(CPU *c) { /* FUN_100067da */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a067e1u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a067e3(CPU *c) { /* PTR_00a067e3 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00a06933(c); return; } /* jne 0xa06933 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06803; /* ja 0xa06803 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_00a067fd; /* jbe 0xa067fd */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00a06800; /* jmp 0xa06800 */
L_00a067fd:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a06800:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00a06803:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06902; /* ja 0xa06902 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06816u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0682cu); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a068e6; /* je 0xa068e6 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if (!c->cf) goto L_00a068a0; /* jae 0xa068a0 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a06856u); f_00a0aabe(c); /* call 0xa0aabe */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06865; /* je 0xa06865 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00a0689d; /* jmp 0xa0689d */
L_00a06865:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0686bu); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0689d; /* je 0xa0689d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06882; /* jb 0xa06882 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06882:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a0689d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a068a0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068e6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a068f6u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
L_00a06902:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06803; /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a067fd(CPU *c) { /* PTR_00a067fd */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00a06803:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06902; /* ja 0xa06902 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06816u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0682cu); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a068e6; /* je 0xa068e6 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if (!c->cf) goto L_00a068a0; /* jae 0xa068a0 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a06856u); f_00a0aabe(c); /* call 0xa0aabe */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06865; /* je 0xa06865 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00a0689d; /* jmp 0xa0689d */
L_00a06865:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0686bu); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0689d; /* je 0xa0689d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06882; /* jb 0xa06882 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06882:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a0689d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a068a0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068e6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a068f6u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
L_00a06902:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06803; /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a06800(CPU *c) { /* PTR_00a06800 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_00a06803:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06902; /* ja 0xa06902 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06816u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0682cu); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a068e6; /* je 0xa068e6 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if (!c->cf) goto L_00a068a0; /* jae 0xa068a0 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a06856u); f_00a0aabe(c); /* call 0xa0aabe */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06865; /* je 0xa06865 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00a0689d; /* jmp 0xa0689d */
L_00a06865:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0686bu); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0689d; /* je 0xa0689d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06882; /* jb 0xa06882 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06882:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a0689d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a068a0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068e6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a068f6u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
L_00a06902:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06803; /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a06803(CPU *c) { /* PTR_00a06803 */
    PREEMPT_POLL(c);
L_00a06803:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06902; /* ja 0xa06902 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06816u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0682cu); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a068e6; /* je 0xa068e6 */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if (!c->cf) goto L_00a068a0; /* jae 0xa068a0 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a06856u); f_00a0aabe(c); /* call 0xa0aabe */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06865; /* je 0xa06865 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_00a0689d; /* jmp 0xa0689d */
L_00a06865:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0686bu); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0689d; /* je 0xa0689d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06882; /* jb 0xa06882 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06882:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a0689d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_00a068a0:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068e6:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a068f6u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
L_00a06902:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06803; /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a06865(CPU *c) { /* PTR_00a06865 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a0686bu); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0689d; /* je 0xa0689d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a06882; /* jb 0xa06882 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a06882:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_00a0689d:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a06882(CPU *c) { /* PTR_00a06882 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a0688eu); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a0689au); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a0689d(CPU *c) { /* PTR_00a0689d */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a068a0(CPU *c) { /* PTR_00a068a0 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_00a068f9; /* jne 0xa068f9 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a068b5u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a068f9; /* je 0xa068f9 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_00a068cb; /* jb 0xa068cb */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a068cb:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a068cb(CPU *c) { /* PTR_00a068cb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x00a068d5u); f_00a0ab90(c); /* call 0xa0ab90 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x00a068e1u); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_00a068f9; /* jmp 0xa068f9 */
L_00a068f9:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a068e6(CPU *c) { /* PTR_00a068e6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a068f6u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a068f9(CPU *c) { /* PTR_00a068f9 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06902u); f_00a06928(c); /* call 0xa06928 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a06902(CPU *c) { /* PTR_00a06902 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_00a0696f(c); return; } /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) { f_00a0696f(c); return; } /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06917u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06803(c); return; } /* jne 0xa06803 */
    { f_00a0696d(c); return; } /* jmp 0xa0696d */
}

void f_00a06922(CPU *c) { /* PTR_00a06922 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_00a06928(c); return; }
}

void f_00a06928(CPU *c) { /* FUN_10006928 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a0692fu); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_00a06933(CPU *c) { /* PTR_00a06933 */
    PREEMPT_POLL(c);
L_00a06933:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06956; /* ja 0xa06956 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00a06941; /* jne 0xa06941 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a06941:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a06956u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
L_00a06956:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a0696f; /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) goto L_00a0696f; /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06968u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06933; /* jne 0xa06933 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a0696f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06941(CPU *c) { /* PTR_00a06941 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e044u)); PUSH32(c, 0x00a06956u); call_indirect(c, t_); } /* call dword ptr [0x1000e044] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a0696f; /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) goto L_00a0696f; /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06968u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06933(c); return; } /* jne 0xa06933 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a0696f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06956(CPU *c) { /* PTR_00a06956 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_00a0696f; /* jne 0xa0696f */
    (void)sub32(c, R32((uint32_t)(0xa135f8u)), c->edi); /* cmp dword ptr [0x100135f8], edi */
    if (c->zf) goto L_00a0696f; /* je 0xa0696f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06968u); f_00a0ab67(c); /* call 0xa0ab67 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06933(c); return; } /* jne 0xa06933 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a0696f:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0696d(CPU *c) { /* PTR_00a0696d */
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

void f_00a0696f(CPU *c) { /* PTR_00a0696f */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a0697e(CPU *c) { /* FUN_1000697e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e428u; PUSH32(c, v_); } /* push 0x1000e428 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xa139e8u))); /* mov eax, dword ptr [0x100139e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00a069f1; /* jne 0xa069f1 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a069b2u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a069c0u); f_00a0999b(c); /* call 0xa0999b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a069d3; /* je 0xa069d3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00a069d6; /* jmp 0xa069d6 */
L_00a069d3:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00a069d6:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a069dfu); f_00a069e8(c); /* call 0xa069e8 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00a06a3a; /* jmp 0xa06a3a */
L_00a069f1:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a06a3c; /* jne 0xa06a3c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a069fdu); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a06a15u); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06a2a; /* je 0xa06a2a */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00a06a2d; /* jmp 0xa06a2d */
L_00a06a2a:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00a06a2d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06a36u); f_00a06a63(c); /* call 0xa06a63 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_00a06a3a:;
    if (!c->zf) goto L_00a06a4f; /* jne 0xa06a4f */
L_00a06a3c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e04cu)); PUSH32(c, 0x00a06a4du); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a06a4f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a069e5(CPU *c) { /* PTR_00a069e5 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00a069e8(c); return; }
}

void f_00a069e8(CPU *c) { /* FUN_100069e8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a069efu); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a069f1(CPU *c) { /* PTR_00a069f1 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a06a3c; /* jne 0xa06a3c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a069fdu); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a06a15u); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06a2a; /* je 0xa06a2a */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_00a06a2d; /* jmp 0xa06a2d */
L_00a06a2a:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_00a06a2d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06a36u); f_00a06a63(c); /* call 0xa06a63 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00a06a4f; /* jne 0xa06a4f */
L_00a06a3c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e04cu)); PUSH32(c, 0x00a06a4du); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a06a4f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06a2a(CPU *c) { /* PTR_00a06a2a */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06a36u); f_00a06a63(c); /* call 0xa06a63 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00a06a4f; /* jne 0xa06a4f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e04cu)); PUSH32(c, 0x00a06a4du); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a06a4f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06a2d(CPU *c) { /* PTR_00a06a2d */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06a36u); f_00a06a63(c); /* call 0xa06a63 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_00a06a4f; /* jne 0xa06a4f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e04cu)); PUSH32(c, 0x00a06a4du); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a06a4f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06a3a(CPU *c) { /* PTR_00a06a3a */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_00a06a4f; /* jne 0xa06a4f */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e04cu)); PUSH32(c, 0x00a06a4du); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_00a06a4f:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06a3c(CPU *c) { /* PTR_00a06a3c */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e04cu)); PUSH32(c, 0x00a06a4du); call_indirect(c, t_); } /* call dword ptr [0x1000e04c] */
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

void f_00a06a4f(CPU *c) { /* PTR_00a06a4f */
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

void f_00a06a60(CPU *c) { /* PTR_00a06a60 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_00a06a63(c); return; }
}

void f_00a06a63(CPU *c) { /* FUN_10006a63 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06a6au); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06a6c(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xa135f8u)); PUSH32(c, v_); } /* push dword ptr [0x100135f8] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00a06a7bu); f_00a06a7e(c); /* call 0xa06a7e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06a7e(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_00a06aa7; /* ja 0xa06aa7 */
L_00a06a85:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00a06a8eu); f_00a06aaa(c); /* call 0xa06aaa */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a06aa9; /* jne 0xa06aa9 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_00a06aa9; /* je 0xa06aa9 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x00a06aa2u); f_00a0ab67(c); /* call 0xa0ab67 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a06a85; /* jne 0xa06a85 */
L_00a06aa7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a06aa9:;
    c->esp += 4; return; /* ret  */
}

void f_00a06aaa(CPU *c) { /* FUN_10006aaa */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e440u; PUSH32(c, v_); } /* push 0x1000e440 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0xa139e8u))); /* mov eax, dword ptr [0x100139e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00a06b1a; /* jne 0xa06b1a */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa139e0u))); /* cmp esi, dword ptr [0x100139e0] */
    if ((!c->cf && !c->zf)) goto L_00a06b79; /* ja 0xa06b79 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06aedu); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06af8u); f_00a09cef(c); /* call 0xa09cef */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06b05u); f_00a06b11(c); /* call 0xa06b11 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06b79; /* je 0xa06b79 */
    goto L_00a06b97; /* jmp 0xa06b97 */
L_00a06b1a:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a06b79; /* jne 0xa06b79 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06b2e; /* je 0xa06b2e */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00a06b31; /* jmp 0xa06b31 */
L_00a06b2e:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a06b31:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if ((!c->cf && !c->zf)) goto L_00a06b6a; /* ja 0xa06b6a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06b43u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06b56u); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06b63u); f_00a06b70(c); /* call 0xa06b70 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06b97; /* jne 0xa06b97 */
L_00a06b6a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_00a06b89; /* jmp 0xa06b89 */
L_00a06b79:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06b83; /* jne 0xa06b83 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a06b83:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_00a06b89:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a06b97u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
L_00a06b97:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06b11(CPU *c) { /* FUN_10006b11 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06b18u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06b1a(CPU *c) { /* PTR_00a06b1a */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00a06b79(c); return; } /* jne 0xa06b79 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06b2e; /* je 0xa06b2e */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_00a06b31; /* jmp 0xa06b31 */
L_00a06b2e:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a06b31:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if ((!c->cf && !c->zf)) goto L_00a06b6a; /* ja 0xa06b6a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06b43u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06b56u); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06b63u); f_00a06b70(c); /* call 0xa06b70 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06b97(c); return; } /* jne 0xa06b97 */
L_00a06b6a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00a06b89(c); return; } /* jmp 0xa06b89 */
}

void f_00a06b2e(CPU *c) { /* PTR_00a06b2e */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if ((!c->cf && !c->zf)) goto L_00a06b6a; /* ja 0xa06b6a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06b43u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06b56u); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06b63u); f_00a06b70(c); /* call 0xa06b70 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06b97(c); return; } /* jne 0xa06b97 */
L_00a06b6a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00a06b89(c); return; } /* jmp 0xa06b89 */
}

void f_00a06b31(CPU *c) { /* PTR_00a06b31 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0xa12aacu))); /* cmp esi, dword ptr [0x10012aac] */
    if ((!c->cf && !c->zf)) goto L_00a06b6a; /* ja 0xa06b6a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06b43u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06b56u); f_00a0a792(c); /* call 0xa0a792 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06b63u); f_00a06b70(c); /* call 0xa06b70 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_00a06b97(c); return; } /* jne 0xa06b97 */
L_00a06b6a:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00a06b89(c); return; } /* jmp 0xa06b89 */
}

void f_00a06b6a(CPU *c) { /* PTR_00a06b6a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_00a06b89(c); return; } /* jmp 0xa06b89 */
}

void f_00a06b6d(CPU *c) { /* PTR_00a06b6d */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_00a06b70(c); return; }
}

void f_00a06b70(CPU *c) { /* FUN_10006b70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06b77u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06b79(CPU *c) { /* PTR_00a06b79 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a06b83; /* jne 0xa06b83 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a06b83:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a06b97u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06b83(CPU *c) { /* PTR_00a06b83 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a06b97u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06b89(CPU *c) { /* PTR_00a06b89 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e048u)); PUSH32(c, 0x00a06b97u); call_indirect(c, t_); } /* call dword ptr [0x1000e048] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06b97(CPU *c) { /* PTR_00a06b97 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06ba6(CPU *c) { /* FUN_10006ba6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xa0e050u))); /* mov esi, dword ptr [0x1000e050] */
    { uint32_t v_ = R32((uint32_t)(0xa104f4u)); PUSH32(c, v_); } /* push dword ptr [0x100104f4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a06bb5u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xa104e4u)); PUSH32(c, v_); } /* push dword ptr [0x100104e4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a06bbdu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xa104d4u)); PUSH32(c, v_); } /* push dword ptr [0x100104d4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a06bc5u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0xa104b4u)); PUSH32(c, v_); } /* push dword ptr [0x100104b4] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x00a06bcdu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a06bcf(CPU *c) { /* FUN_10006bcf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0xa0e054u))); /* mov edi, dword ptr [0x1000e054] */
    c->esi = (uint32_t)((uint32_t)0xa104b0u); /* mov esi, 0x100104b0 */
L_00a06bdc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06c0d; /* je 0xa06c0d */
    (void)sub32(c, c->esi, (uint32_t)0xa104f4u); /* cmp esi, 0x100104f4 */
    if (c->zf) goto L_00a06c0d; /* je 0xa06c0d */
    (void)sub32(c, c->esi, (uint32_t)0xa104e4u); /* cmp esi, 0x100104e4 */
    if (c->zf) goto L_00a06c0d; /* je 0xa06c0d */
    (void)sub32(c, c->esi, (uint32_t)0xa104d4u); /* cmp esi, 0x100104d4 */
    if (c->zf) goto L_00a06c0d; /* je 0xa06c0d */
    (void)sub32(c, c->esi, (uint32_t)0xa104b4u); /* cmp esi, 0x100104b4 */
    if (c->zf) goto L_00a06c0d; /* je 0xa06c0d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a06c05u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00a06c0cu); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a06c0d:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xa10570u); /* cmp esi, 0x10010570 */
    if ((c->sf != c->of)) goto L_00a06bdc; /* jl 0xa06bdc */
    { uint32_t v_ = R32((uint32_t)(0xa104d4u)); PUSH32(c, v_); } /* push dword ptr [0x100104d4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a06c20u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xa104e4u)); PUSH32(c, v_); } /* push dword ptr [0x100104e4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a06c28u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xa104f4u)); PUSH32(c, v_); } /* push dword ptr [0x100104f4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a06c30u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0xa104b4u)); PUSH32(c, v_); } /* push dword ptr [0x100104b4] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a06c38u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a06c3b(CPU *c) { /* FUN_10006c3b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0xa104b0u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x100104b0], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0xa104b0u)); /* lea esi, [eax*4 + 0x100104b0] */
    if (!c->zf) goto L_00a06c91; /* jne 0xa06c91 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x00a06c5bu); f_00a06a6c(c); /* call 0xa06a6c */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_00a06c6a; /* jne 0xa06c6a */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00a06c69u); f_00a04e41(c); /* call 0xa04e41 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a06c6a:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00a06c71u); f_00a06c3b(c); /* call 0xa06c3b */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a06c82; /* jne 0xa06c82 */
    { uint32_t t_ = R32((uint32_t)(0xa0e050u)); PUSH32(c, 0x00a06c7eu); call_indirect(c, t_); } /* call dword ptr [0x1000e050] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_00a06c88; /* jmp 0xa06c88 */
L_00a06c82:;
    PUSH32(c, 0x00a06c87u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a06c88:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x00a06c8fu); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_00a06c91:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0xa0e058u)); PUSH32(c, 0x00a06c99u); call_indirect(c, t_); } /* call dword ptr [0x1000e058] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a06c9c(CPU *c) { /* FUN_10006c9c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0xa104b0u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x100104b0] */
    { uint32_t t_ = R32((uint32_t)(0xa0e05cu)); PUSH32(c, 0x00a06cafu); call_indirect(c, t_); } /* call dword ptr [0x1000e05c] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a06cb1(CPU *c) { /* FUN_10006cb1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0xa0e458u; PUSH32(c, v_); } /* push 0x1000e458 */
    { uint32_t v_ = 0xa0881cu; PUSH32(c, v_); } /* push 0x1000881c */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a06d8b; /* je 0xa06d8b */
    c->eax = (uint32_t)(R32((uint32_t)(0xa139e8u))); /* mov eax, dword ptr [0x100139e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00a06d24; /* jne 0xa06d24 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06cf0u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06cfbu); f_00a0999b(c); /* call 0xa0999b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06d0c; /* je 0xa06d0c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06d0au); f_00a099c6(c); /* call 0xa099c6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a06d0c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06d15u); f_00a06d1b(c); /* call 0xa06d1b */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_00a06d6c; /* jmp 0xa06d6c */
L_00a06d24:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a06d7c; /* jne 0xa06d7c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06d30u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06d46u); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06d5f; /* je 0xa06d5f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00a06d5cu); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00a06d5f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06d68u); f_00a06d73(c); /* call 0xa06d73 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_00a06d6c:;
    if (!c->zf) goto L_00a06d8b; /* jne 0xa06d8b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_00a06d7d; /* jmp 0xa06d7d */
L_00a06d7c:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_00a06d7d:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e060u)); PUSH32(c, 0x00a06d8bu); call_indirect(c, t_); } /* call dword ptr [0x1000e060] */
L_00a06d8b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06d1b(CPU *c) { /* FUN_10006d1b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06d22u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06d24(CPU *c) { /* PTR_00a06d24 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_00a06d7c(c); return; } /* jne 0xa06d7c */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06d30u); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a06d46u); f_00a0a6f6(c); /* call 0xa0a6f6 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06d5f; /* je 0xa06d5f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x00a06d5cu); f_00a0a74d(c); /* call 0xa0a74d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00a06d5f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06d68u); f_00a06d73(c); /* call 0xa06d73 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00a06d8b(c); return; } /* jne 0xa06d8b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00a06d7d(c); return; } /* jmp 0xa06d7d */
}

void f_00a06d5f(CPU *c) { /* PTR_00a06d5f */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x00a06d68u); f_00a06d73(c); /* call 0xa06d73 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_00a06d8b(c); return; } /* jne 0xa06d8b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00a06d7d(c); return; } /* jmp 0xa06d7d */
}

void f_00a06d6c(CPU *c) { /* PTR_00a06d6c */
    PREEMPT_POLL(c);
    if (!c->zf) { f_00a06d8b(c); return; } /* jne 0xa06d8b */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_00a06d7d(c); return; } /* jmp 0xa06d7d */
}

void f_00a06d73(CPU *c) { /* FUN_10006d73 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a06d7au); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a06d7c(CPU *c) { /* PTR_00a06d7c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e060u)); PUSH32(c, 0x00a06d8bu); call_indirect(c, t_); } /* call dword ptr [0x1000e060] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06d7d(CPU *c) { /* PTR_00a06d7d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e060u)); PUSH32(c, 0x00a06d8bu); call_indirect(c, t_); } /* call dword ptr [0x1000e060] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06d8b(CPU *c) { /* PTR_00a06d8b */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a06da0(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_00a06dec; /* jne 0xa06dec */
L_00a06db0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a06de0; /* je 0xa06de0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00a06de0; /* je 0xa06de0 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a06de0; /* je 0xa06de0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_00a06db0; /* jne 0xa06db0 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_00a06de0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a06de4:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_00a06dec:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_00a06e08; /* je 0xa06e08 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a06de0; /* je 0xa06de0 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_00a06db0; /* je 0xa06db0 */
L_00a06e08:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_00a06de0; /* je 0xa06de0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_00a06de4; /* jne 0xa06de4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_00a06de0; /* je 0xa06de0 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_00a06db0; /* jmp 0xa06db0 */
}

void f_00a06e24(CPU *c) { /* FUN_10006e24 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_00a06e47; /* jne 0xa06e47 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_00a06e47; /* jne 0xa06e47 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_00a06e47; /* jne 0xa06e47 */
    { f_00a05d0c(c); return; } /* jmp 0xa05d0c */
L_00a06e47:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa134e0u))); /* mov eax, dword ptr [0x100134e0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06e64; /* je 0xa06e64 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a06e56u); f_00a087f9(c); /* call 0xa087f9 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a06e64; /* je 0xa06e64 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xa134e0u)); PUSH32(c, 0x00a06e62u); call_indirect(c, t_); } /* call dword ptr [0x100134e0] */
    goto L_00a06e66; /* jmp 0xa06e66 */
L_00a06e64:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a06e66:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_00a06e6a(CPU *c) { /* PTR_00a06e6a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa06e24u; PUSH32(c, v_); } /* push 0x10006e24 */
    { uint32_t t_ = R32((uint32_t)(0xa0e064u)); PUSH32(c, 0x00a06e75u); call_indirect(c, t_); } /* call dword ptr [0x1000e064] */
    W32((uint32_t)(0xa134e0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100134e0], eax */
    c->esp += 4; return; /* ret  */
}

void f_00a06e7b(CPU *c) { /* PTR_00a06e7b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0xa134e0u)); PUSH32(c, v_); } /* push dword ptr [0x100134e0] */
    { uint32_t t_ = R32((uint32_t)(0xa0e064u)); PUSH32(c, 0x00a06e87u); call_indirect(c, t_); } /* call dword ptr [0x1000e064] */
    c->esp += 4; return; /* ret  */
}

void f_00a06e88(CPU *c) { /* FUN_10006e88 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x48u)); /* sub esp, 0x48 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00a06e9bu); f_00a06a6c(c); /* call 0xa06a6c */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_00a06eaa; /* jne 0xa06eaa */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x00a06ea9u); f_00a04e41(c); /* call 0xa04e41 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a06eaa:;
    W32((uint32_t)(0xa13a00u), (uint32_t)(c->esi)); /* mov dword ptr [0x10013a00], esi */
    W32((uint32_t)(0xa13b00u), (uint32_t)((uint32_t)0x20u)); /* mov dword ptr [0x10013b00], 0x20 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x480u)); /* lea eax, [esi + 0x480] */
L_00a06ec0:;
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (!c->cf) goto L_00a06ee2; /* jae 0xa06ee2 */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->esi + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 8], 0 */
    W8((uint32_t)(c->esi + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [esi + 5], 0xa */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13a00u))); /* mov eax, dword ptr [0x10013a00] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x24u)); /* add esi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    goto L_00a06ec0; /* jmp 0xa06ec0 */
L_00a06ee2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb8u)); /* lea eax, [ebp - 0x48] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e074u)); PUSH32(c, 0x00a06eecu); call_indirect(c, t_); } /* call dword ptr [0x1000e074] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0xffffffeau)), (uint16_t)0x0u); /* cmp word ptr [ebp - 0x16], 0 */
    if (c->zf) goto L_00a06fc8; /* je 0xa06fc8 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06fc8; /* je 0xa06fc8 */
    c->edi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov edi, dword ptr [eax] */
    c->ebx = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea ebx, [eax + 4] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->edi)); /* lea eax, [ebx + edi] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)0x800u); /* mov eax, 0x800 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if ((c->sf != c->of)) goto L_00a06f18; /* jl 0xa06f18 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00a06f18:;
    (void)sub32(c, R32((uint32_t)(0xa13b00u)), c->edi); /* cmp dword ptr [0x10013b00], edi */
    if ((c->sf == c->of)) goto L_00a06f76; /* jge 0xa06f76 */
    c->esi = (uint32_t)((uint32_t)0xa13a04u); /* mov esi, 0x10013a04 */
L_00a06f25:;
    { uint32_t v_ = 0x480u; PUSH32(c, v_); } /* push 0x480 */
    PUSH32(c, 0x00a06f2fu); f_00a06a6c(c); /* call 0xa06a6c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a06f70; /* je 0xa06f70 */
    { uint32_t a_ = (uint32_t)(0xa13b00u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x20u))); } /* add dword ptr [0x10013b00], 0x20 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x480u)); /* lea ecx, [eax + 0x480] */
L_00a06f43:;
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->cf) goto L_00a06f63; /* jae 0xa06f63 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t a_ = (uint32_t)(c->eax + 0x8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax + 8], 0 */
    W8((uint32_t)(c->eax + 0x5u), (uint8_t)((uint8_t)0xau)); /* mov byte ptr [eax + 5], 0xa */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov ecx, dword ptr [esi] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x24u)); /* add eax, 0x24 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x480u)); /* add ecx, 0x480 */
    goto L_00a06f43; /* jmp 0xa06f43 */
L_00a06f63:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, R32((uint32_t)(0xa13b00u)), c->edi); /* cmp dword ptr [0x10013b00], edi */
    if ((c->sf != c->of)) goto L_00a06f25; /* jl 0xa06f25 */
    goto L_00a06f76; /* jmp 0xa06f76 */
L_00a06f70:;
    c->edi = (uint32_t)(R32((uint32_t)(0xa13b00u))); /* mov edi, dword ptr [0x10013b00] */
L_00a06f76:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_00a06fc8; /* jle 0xa06fc8 */
L_00a06f7c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    (void)sub32(c, c->ecx, (uint32_t)0xffffffffu); /* cmp ecx, -1 */
    if (c->zf) goto L_00a06fbe; /* je 0xa06fbe */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov al, byte ptr [ebx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_00a06fbe; /* je 0xa06fbe */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u)); /* test al, 8 */
    if (!c->zf) goto L_00a06f9b; /* jne 0xa06f9b */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t t_ = R32((uint32_t)(0xa0e070u)); PUSH32(c, 0x00a06f97u); call_indirect(c, t_); } /* call dword ptr [0x1000e070] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a06fbe; /* je 0xa06fbe */
L_00a06f9b:;
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0xa13a00u))); /* mov ecx, dword ptr [ecx*4 + 0x10013a00] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov ecx, dword ptr [ecx] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebx))); /* mov cl, byte ptr [ebx] */
    W8((uint32_t)(c->eax + 0x4u), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax + 4], cl */
L_00a06fbe:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [ebp - 4], 4 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->sf != c->of)) goto L_00a06f7c; /* jl 0xa06f7c */
L_00a06fc8:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00a06fca:;
    c->ecx = (uint32_t)(R32((uint32_t)(0xa13a00u))); /* mov ecx, dword ptr [0x10013a00] */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 8)); /* lea eax, [ebx + ebx*8] */
    (void)sub32(c, R32((uint32_t)(c->ecx + c->eax * 4)), (uint32_t)0xffffffffu); /* cmp dword ptr [ecx + eax*4], -1 */
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea esi, [ecx + eax*4] */
    if (!c->zf) goto L_00a07029; /* jne 0xa07029 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    W8((uint32_t)(c->esi + 0x4u), (uint8_t)((uint8_t)0x81u)); /* mov byte ptr [esi + 4], 0x81 */
    if (!c->zf) goto L_00a06fe9; /* jne 0xa06fe9 */
    { uint32_t v_ = 0xfffffff6u; PUSH32(c, v_); } /* push -0xa */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a06ff3; /* jmp 0xa06ff3 */
L_00a06fe9:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfffffff5u)); /* add eax, -0xb */
L_00a06ff3:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e06cu)); PUSH32(c, 0x00a06ffau); call_indirect(c, t_); } /* call dword ptr [0x1000e06c] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, (uint32_t)0xffffffffu); /* cmp edi, -1 */
    if (c->zf) goto L_00a07018; /* je 0xa07018 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa0e070u)); PUSH32(c, 0x00a07008u); call_indirect(c, t_); } /* call dword ptr [0x1000e070] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07018; /* je 0xa07018 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a0701e; /* jne 0xa0701e */
L_00a07018:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x40u)))); } /* or byte ptr [esi + 4], 0x40 */
    goto L_00a0702d; /* jmp 0xa0702d */
L_00a0701e:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_00a0702d; /* jne 0xa0702d */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [esi + 4], 8 */
    goto L_00a0702d; /* jmp 0xa0702d */
L_00a07029:;
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [esi + 4], 0x80 */
L_00a0702d:;
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, (uint32_t)0x3u); /* cmp ebx, 3 */
    if ((c->sf != c->of)) goto L_00a06fca; /* jl 0xa06fca */
    { uint32_t v_ = R32((uint32_t)(0xa13b00u)); PUSH32(c, v_); } /* push dword ptr [0x10013b00] */
    { uint32_t t_ = R32((uint32_t)(0xa0e068u)); PUSH32(c, 0x00a0703fu); call_indirect(c, t_); } /* call dword ptr [0x1000e068] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07044(CPU *c) { /* FUN_10007044 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)((uint32_t)0xa13a00u); /* mov esi, 0x10013a00 */
L_00a0704c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07089; /* je 0xa07089 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (!c->cf) goto L_00a0707e; /* jae 0xa0707e */
    c->ebx = (uint32_t)((uint32_t)(c->edi + 0xcu)); /* lea ebx, [edi + 0xc] */
L_00a07060:;
    (void)sub32(c, R32((uint32_t)(c->ebx + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebx - 4], 0 */
    if (c->zf) goto L_00a0706d; /* je 0xa0706d */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xa0e054u)); PUSH32(c, 0x00a0706du); call_indirect(c, t_); } /* call dword ptr [0x1000e054] */
L_00a0706d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x24u)); /* add edi, 0x24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x480u)); /* add eax, 0x480 */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x24u)); /* add ebx, 0x24 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00a07060; /* jb 0xa07060 */
L_00a0707e:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00a07085u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07089:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0xa13b00u); /* cmp esi, 0x10013b00 */
    if ((c->sf != c->of)) goto L_00a0704c; /* jl 0xa0704c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a07098(CPU *c) { /* FUN_10007098 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xa13b08u)), c->ebx); /* cmp dword ptr [0x10013b08], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a070aa; /* jne 0xa070aa */
    PUSH32(c, 0x00a070aau); f_00a0b29d(c); /* call 0xa0b29d */
L_00a070aa:;
    c->esi = (uint32_t)(R32((uint32_t)(0xa1342cu))); /* mov esi, dword ptr [0x1001342c] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
L_00a070b2:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_00a070ca; /* je 0xa070ca */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x3du); /* cmp al, 0x3d */
    if (c->zf) goto L_00a070bd; /* je 0xa070bd */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_00a070bd:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a070c3u); f_00a08600(c); /* call 0xa08600 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->eax + 0x1u)); /* lea esi, [esi + eax + 1] */
    goto L_00a070b2; /* jmp 0xa070b2 */
L_00a070ca:;
    c->eax = (uint32_t)((uint32_t)(c->edi * 4 + 0x4u)); /* lea eax, [edi*4 + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a070d7u); f_00a06a6c(c); /* call 0xa06a6c */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    W32((uint32_t)(0xa1345cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1001345c], esi */
    if (!c->zf) goto L_00a070ec; /* jne 0xa070ec */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a070ebu); f_00a04e41(c); /* call 0xa04e41 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a070ec:;
    c->edi = (uint32_t)(R32((uint32_t)(0xa1342cu))); /* mov edi, dword ptr [0x1001342c] */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (c->zf) goto L_00a0712f; /* je 0xa0712f */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
L_00a070f7:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a070fdu); f_00a08600(c); /* call 0xa08600 */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ebp = (uint32_t)(inc32(c, c->ebp)); /* inc ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x3du); /* cmp byte ptr [edi], 0x3d */
    if (c->zf) goto L_00a07128; /* je 0xa07128 */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00a0710cu); f_00a06a6c(c); /* call 0xa06a6c */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    if (!c->zf) goto L_00a0711b; /* jne 0xa0711b */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x00a0711au); f_00a04e41(c); /* call 0xa04e41 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a0711b:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00a07123u); f_00a08170(c); /* call 0xa08170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07128:;
    c->edi = (uint32_t)(add32(c, c->edi, c->ebp)); /* add edi, ebp */
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    if (!c->zf) goto L_00a070f7; /* jne 0xa070f7 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
L_00a0712f:;
    { uint32_t v_ = R32((uint32_t)(0xa1342cu)); PUSH32(c, v_); } /* push dword ptr [0x1001342c] */
    PUSH32(c, 0x00a0713au); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0xa1342cu), (uint32_t)(c->ebx)); /* mov dword ptr [0x1001342c], ebx */
    W32((uint32_t)(c->esi), (uint32_t)(c->ebx)); /* mov dword ptr [esi], ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xa13b04u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x10013b04], 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a07151(CPU *c) { /* FUN_10007151 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xa13b08u)), c->ebx); /* cmp dword ptr [0x10013b08], ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a07168; /* jne 0xa07168 */
    PUSH32(c, 0x00a07168u); f_00a0b29d(c); /* call 0xa0b29d */
L_00a07168:;
    c->esi = (uint32_t)((uint32_t)0xa134e4u); /* mov esi, 0x100134e4 */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xa0e078u)); PUSH32(c, 0x00a0717au); call_indirect(c, t_); } /* call dword ptr [0x1000e078] */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13b14u))); /* mov eax, dword ptr [0x10013b14] */
    W32((uint32_t)(0xa1346cu), (uint32_t)(c->esi)); /* mov dword ptr [0x1001346c], esi */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00a0718d; /* je 0xa0718d */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
L_00a0718d:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a0719du); f_00a071ea(c); /* call 0xa071ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea eax, [eax + ecx*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a071acu); f_00a06a6c(c); /* call 0xa06a6c */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00a071bd; /* jne 0xa071bd */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    PUSH32(c, 0x00a071bcu); f_00a04e41(c); /* call 0xa04e41 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a071bd:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->eax * 4)); /* lea eax, [esi + eax*4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a071d3u); f_00a071ea(c); /* call 0xa071ea */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(0xa13454u), (uint32_t)(c->esi)); /* mov dword ptr [0x10013454], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(0xa13450u), (uint32_t)(c->eax)); /* mov dword ptr [0x10013450], eax */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a071ea(CPU *c) { /* FUN_100071ea */
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
    if (c->zf) goto L_00a07214; /* je 0xa07214 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00a07214:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00a0725d; /* jne 0xa0725d */
L_00a07219:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x22u); /* cmp dl, 0x22 */
    if (c->zf) goto L_00a0724b; /* je 0xa0724b */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a0724b; /* je 0xa0724b */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xa138c1u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x100138c1], 4 */
    if (c->zf) goto L_00a0723e; /* je 0xa0723e */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a0723e; /* je 0xa0723e */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00a0723e:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07219; /* je 0xa07219 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00a07219; /* jmp 0xa07219 */
L_00a0724b:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07255; /* je 0xa07255 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a07255:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00a072a0; /* jne 0xa072a0 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a072a0; /* jmp 0xa072a0 */
L_00a0725d:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07268; /* je 0xa07268 */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a07268:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xa138c1u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x100138c1], 4 */
    if (c->zf) goto L_00a07283; /* je 0xa07283 */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07282; /* je 0xa07282 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov bl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [esi], bl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a07282:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
L_00a07283:;
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00a07291; /* je 0xa07291 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a07295; /* je 0xa07295 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00a0725d; /* jne 0xa0725d */
L_00a07291:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (!c->zf) goto L_00a07298; /* jne 0xa07298 */
L_00a07295:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    goto L_00a072a0; /* jmp 0xa072a0 */
L_00a07298:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a072a0; /* je 0xa072a0 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xffffffffu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi - 1], 0 */
L_00a072a0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x18u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0x18], 0 */
L_00a072a4:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00a0738d; /* je 0xa0738d */
L_00a072ad:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00a072b9; /* je 0xa072b9 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (!c->zf) goto L_00a072bc; /* jne 0xa072bc */
L_00a072b9:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a072ad; /* jmp 0xa072ad */
L_00a072bc:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_00a0738d; /* je 0xa0738d */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a072d1; /* je 0xa072d1 */
    W32((uint32_t)(c->edi), (uint32_t)(c->esi)); /* mov dword ptr [edi], esi */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_00a072d1:;
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov edx, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx] */
L_00a072d6:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 8], 1 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00a072df:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x5cu); /* cmp byte ptr [eax], 0x5c */
    if (!c->zf) goto L_00a072e8; /* jne 0xa072e8 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    goto L_00a072df; /* jmp 0xa072df */
L_00a072e8:;
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x22u); /* cmp byte ptr [eax], 0x22 */
    if (!c->zf) goto L_00a07319; /* jne 0xa07319 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (!c->zf) goto L_00a07317; /* jne 0xa07317 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edi); /* cmp dword ptr [ebp + 0x18], edi */
    if (c->zf) goto L_00a07306; /* je 0xa07306 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x1u)), (uint8_t)0x22u); /* cmp byte ptr [eax + 1], 0x22 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea edx, [eax + 1] */
    if (!c->zf) goto L_00a07306; /* jne 0xa07306 */
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    goto L_00a07309; /* jmp 0xa07309 */
L_00a07306:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 8], edi */
L_00a07309:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), c->edx); /* cmp dword ptr [ebp + 0x18], edx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete dl */
    W32((uint32_t)(c->ebp + 0x18u), (uint32_t)(c->edx)); /* mov dword ptr [ebp + 0x18], edx */
L_00a07317:;
    c->ebx = (uint32_t)(shr32(c, c->ebx, 1)); /* shr ebx, 1 */
L_00a07319:;
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00a0732e; /* je 0xa0732e */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00a07321:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07329; /* je 0xa07329 */
    W8((uint32_t)(c->esi), (uint8_t)((uint8_t)0x5cu)); /* mov byte ptr [esi], 0x5c */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a07329:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_00a07321; /* jne 0xa07321 */
L_00a0732e:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a0737e; /* je 0xa0737e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x18], 0 */
    if (!c->zf) goto L_00a07344; /* jne 0xa07344 */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x20u); /* cmp dl, 0x20 */
    if (c->zf) goto L_00a0737e; /* je 0xa0737e */
    (void)sub8(c, ((uint8_t)c->edx), (uint8_t)0x9u); /* cmp dl, 9 */
    if (c->zf) goto L_00a0737e; /* je 0xa0737e */
L_00a07344:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_00a07378; /* je 0xa07378 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07367; /* je 0xa07367 */
    c->ebx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx ebx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebx + 0xa138c1u)) & (uint8_t)0x4u)); /* test byte ptr [ebx + 0x100138c1], 4 */
    if (c->zf) goto L_00a07360; /* je 0xa07360 */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00a07360:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov dl, byte ptr [eax] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [esi], dl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    goto L_00a07376; /* jmp 0xa07376 */
L_00a07367:;
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->edx)); /* movzx edx, dl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + 0xa138c1u)) & (uint8_t)0x4u)); /* test byte ptr [edx + 0x100138c1], 4 */
    if (c->zf) goto L_00a07376; /* je 0xa07376 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00a07376:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
L_00a07378:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_00a072d6; /* jmp 0xa072d6 */
L_00a0737e:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_00a07386; /* je 0xa07386 */
    { uint32_t a_ = (uint32_t)(c->esi); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [esi], 0 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_00a07386:;
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    goto L_00a072a4; /* jmp 0xa072a4 */
L_00a0738d:;
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_00a07394; /* je 0xa07394 */
    { uint32_t a_ = (uint32_t)(c->edi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [edi], 0 */
L_00a07394:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a0739e(CPU *c) { /* FUN_1000739e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(0xa135e8u))); /* mov eax, dword ptr [0x100135e8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xa0e08cu))); /* mov ebp, dword ptr [0x1000e08c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00a073ec; /* jne 0xa073ec */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00a073bbu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00a073cd; /* je 0xa073cd */
    W32((uint32_t)(0xa135e8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [0x100135e8], 1 */
    goto L_00a073f5; /* jmp 0xa073f5 */
L_00a073cd:;
    { uint32_t t_ = R32((uint32_t)(0xa0e088u)); PUSH32(c, 0x00a073d3u); call_indirect(c, t_); } /* call dword ptr [0x1000e088] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00a074c7; /* je 0xa074c7 */
    W32((uint32_t)(0xa135e8u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [0x100135e8], 2 */
    goto L_00a0747b; /* jmp 0xa0747b */
L_00a073ec:;
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_00a07476; /* jne 0xa07476 */
L_00a073f5:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00a07405; /* jne 0xa07405 */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00a073fbu); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_00a074c7; /* je 0xa074c7 */
L_00a07405:;
    (void)sub16(c, R16((uint32_t)(c->esi)), ((uint16_t)c->ebx)); /* cmp word ptr [esi], bx */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    if (c->zf) goto L_00a0741a; /* je 0xa0741a */
L_00a0740c:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00a0740c; /* jne 0xa0740c */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub16(c, R16((uint32_t)(c->eax)), ((uint16_t)c->ebx)); /* cmp word ptr [eax], bx */
    if (!c->zf) goto L_00a0740c; /* jne 0xa0740c */
L_00a0741a:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->edi = (uint32_t)(R32((uint32_t)(0xa0e084u))); /* mov edi, dword ptr [0x1000e084] */
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
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a07433u); call_indirect(c, t_); } /* call edi */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    (void)sub32(c, c->ebp, c->ebx); /* cmp ebp, ebx */
    if (c->zf) goto L_00a0746b; /* je 0xa0746b */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00a0743fu); f_00a06a6c(c); /* call 0xa06a6c */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00a0746b; /* je 0xa0746b */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a07455u); call_indirect(c, t_); } /* call edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a07467; /* jne 0xa07467 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00a07462u); f_00a06cb1(c); /* call 0xa06cb1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->ebx)); /* mov dword ptr [esp + 0x10], ebx */
L_00a07467:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ebx, dword ptr [esp + 0x10] */
L_00a0746b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xa0e080u)); PUSH32(c, 0x00a07472u); call_indirect(c, t_); } /* call dword ptr [0x1000e080] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00a074c9; /* jmp 0xa074c9 */
L_00a07476:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a074c7; /* jne 0xa074c7 */
L_00a0747b:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (!c->zf) goto L_00a0748b; /* jne 0xa0748b */
    { uint32_t t_ = R32((uint32_t)(0xa0e088u)); PUSH32(c, 0x00a07485u); call_indirect(c, t_); } /* call dword ptr [0x1000e088] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_00a074c7; /* je 0xa074c7 */
L_00a0748b:;
    (void)sub8(c, R8((uint32_t)(c->edi)), ((uint8_t)c->ebx)); /* cmp byte ptr [edi], bl */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (c->zf) goto L_00a0749b; /* je 0xa0749b */
L_00a07491:;
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00a07491; /* jne 0xa07491 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (!c->zf) goto L_00a07491; /* jne 0xa07491 */
L_00a0749b:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ebp = (uint32_t)(c->eax); /* mov ebp, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    PUSH32(c, 0x00a074a6u); f_00a06a6c(c); /* call 0xa06a6c */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_00a074b1; /* jne 0xa074b1 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00a074bc; /* jmp 0xa074bc */
L_00a074b1:;
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a074b9u); f_00a0ab90(c); /* call 0xa0ab90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_00a074bc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0xa0e07cu)); PUSH32(c, 0x00a074c3u); call_indirect(c, t_); } /* call dword ptr [0x1000e07c] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    goto L_00a074c9; /* jmp 0xa074c9 */
L_00a074c7:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a074c9:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a074d0(CPU *c) { /* FUN_100074d0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t a_ = (uint32_t)(c->esi); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi], 0 */
    { uint32_t t_ = R32((uint32_t)(0xa0e018u)); PUSH32(c, 0x00a074e0u); call_indirect(c, t_); } /* call dword ptr [0x1000e018] */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x5a4du); /* cmp word ptr [eax], 0x5a4d */
    if (!c->zf) goto L_00a074fb; /* jne 0xa074fb */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x3cu))); /* mov ecx, dword ptr [eax + 0x3c] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_00a074fb; /* je 0xa074fb */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1au))); /* mov cl, byte ptr [eax + 0x1a] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1bu))); /* mov al, byte ptr [eax + 0x1b] */
    W8((uint32_t)(c->esi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi + 1], al */
L_00a074fb:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a074fd(CPU *c) { /* FUN_100074fd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)((uint32_t)0x122cu); /* mov eax, 0x122c */
    PUSH32(c, 0x00a0750au); f_00a0b670(c); /* call 0xa0b670 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff68u)); /* lea eax, [ebp - 0x98] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffff68u), (uint32_t)((uint32_t)0x94u)); /* mov dword ptr [ebp - 0x98], 0x94 */
    { uint32_t t_ = R32((uint32_t)(0xa0e094u)); PUSH32(c, 0x00a07522u); call_indirect(c, t_); } /* call dword ptr [0x1000e094] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07540; /* je 0xa07540 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff78u)), (uint32_t)0x2u); /* cmp dword ptr [ebp - 0x88], 2 */
    if (!c->zf) goto L_00a07540; /* jne 0xa07540 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffff6cu)), (uint32_t)0x5u); /* cmp dword ptr [ebp - 0x94], 5 */
    if (c->cf) goto L_00a07540; /* jb 0xa07540 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a07642; /* jmp 0xa07642 */
L_00a07540:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x1090u; PUSH32(c, v_); } /* push 0x1090 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xa0e488u; PUSH32(c, v_); } /* push 0x1000e488 */
    { uint32_t t_ = R32((uint32_t)(0xa0e090u)); PUSH32(c, 0x00a07557u); call_indirect(c, t_); } /* call dword ptr [0x1000e090] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0762f; /* je 0xa0762f */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea ecx, [ebp - 0x122c] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffedd4u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x122c], bl */
    if (c->zf) goto L_00a07582; /* je 0xa07582 */
L_00a0756f:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00a0757d; /* jl 0xa0757d */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00a0757d; /* jg 0xa0757d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00a0757d:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00a0756f; /* jne 0xa0756f */
L_00a07582:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = 0x16u; PUSH32(c, v_); } /* push 0x16 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xa0e470u; PUSH32(c, v_); } /* push 0x1000e470 */
    PUSH32(c, 0x00a07595u); f_00a0b630(c); /* call 0xa0b630 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a075a4; /* jne 0xa075a4 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    goto L_00a075ed; /* jmp 0xa075ed */
L_00a075a4:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = R32((uint32_t)(0xa0e078u)); PUSH32(c, 0x00a075b7u); call_indirect(c, t_); } /* call dword ptr [0x1000e078] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffe64u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp - 0x19c], bl */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea ecx, [ebp - 0x19c] */
    if (c->zf) goto L_00a075d8; /* je 0xa075d8 */
L_00a075c5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if ((c->sf != c->of)) goto L_00a075d3; /* jl 0xa075d3 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x7au); /* cmp al, 0x7a */
    if ((!c->zf && c->sf == c->of)) goto L_00a075d3; /* jg 0xa075d3 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(sub8(c, ((uint8_t)c->eax), (uint8_t)0x20u)); /* sub al, 0x20 */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ecx], al */
L_00a075d3:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00a075c5; /* jne 0xa075c5 */
L_00a075d8:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe64u)); /* lea eax, [ebp - 0x19c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffedd4u)); /* lea eax, [ebp - 0x122c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a075ebu); f_00a0b5b0(c); /* call 0xa0b5b0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a075ed:;
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_00a0762f; /* je 0xa0762f */
    { uint32_t v_ = 0x2cu; PUSH32(c, v_); } /* push 0x2c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a075f9u); f_00a0b4f0(c); /* call 0xa0b4f0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_00a0762f; /* je 0xa0762f */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->ebx)); /* cmp byte ptr [eax], bl */
    if (c->zf) goto L_00a07614; /* je 0xa07614 */
L_00a07606:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x3bu); /* cmp byte ptr [ecx], 0x3b */
    if (!c->zf) goto L_00a0760f; /* jne 0xa0760f */
    W8((uint32_t)(c->ecx), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ecx], bl */
    goto L_00a07610; /* jmp 0xa07610 */
L_00a0760f:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
L_00a07610:;
    (void)sub8(c, R8((uint32_t)(c->ecx)), ((uint8_t)c->ebx)); /* cmp byte ptr [ecx], bl */
    if (!c->zf) goto L_00a07606; /* jne 0xa07606 */
L_00a07614:;
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a0761du); f_00a0b2b9(c); /* call 0xa0b2b9 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_00a07642; /* je 0xa07642 */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (c->zf) goto L_00a07642; /* je 0xa07642 */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00a07642; /* je 0xa07642 */
L_00a0762f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07638u); f_00a074d0(c); /* call 0xa074d0 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffffcu)), (uint8_t)0x6u); /* cmp byte ptr [ebp - 4], 6 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x3u)); /* add eax, 3 */
L_00a07642:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07645(CPU *c) { /* FUN_10007645 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    { uint32_t v_ = 0x1000u; PUSH32(c, v_); } /* push 0x1000 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e09cu)); PUSH32(c, 0x00a0765cu); call_indirect(c, t_); } /* call dword ptr [0x1000e09c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(0xa139e4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100139e4], eax */
    if (c->zf) goto L_00a0769b; /* je 0xa0769b */
    PUSH32(c, 0x00a0766au); f_00a074fd(c); /* call 0xa074fd */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    W32((uint32_t)(0xa139e8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100139e8], eax */
    if (!c->zf) goto L_00a07681; /* jne 0xa07681 */
    { uint32_t v_ = 0x3f8u; PUSH32(c, v_); } /* push 0x3f8 */
    PUSH32(c, 0x00a0767eu); f_00a09953(c); /* call 0xa09953 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a0768b; /* jmp 0xa0768b */
L_00a07681:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a0769e; /* jne 0xa0769e */
    PUSH32(c, 0x00a0768bu); f_00a0a49a(c); /* call 0xa0a49a */
L_00a0768b:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a0769e; /* jne 0xa0769e */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e098u)); PUSH32(c, 0x00a0769bu); call_indirect(c, t_); } /* call dword ptr [0x1000e098] */
L_00a0769b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_00a0769e:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_00a076a2(CPU *c) { /* FUN_100076a2 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa139e8u))); /* mov eax, dword ptr [0x100139e8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a07714; /* jne 0xa07714 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xa139d8u)), c->ebx); /* cmp dword ptr [0x100139d8], ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(R32((uint32_t)(0xa0e060u))); /* mov ebp, dword ptr [0x1000e060] */
    if ((c->zf || c->sf != c->of)) goto L_00a07700; /* jle 0xa07700 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa139dcu))); /* mov eax, dword ptr [0x100139dc] */
    c->edi = (uint32_t)(R32((uint32_t)(0xa0e0a0u))); /* mov edi, dword ptr [0x1000e0a0] */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xcu)); /* lea esi, [eax + 0xc] */
L_00a076ce:;
    { uint32_t v_ = 0x4000u; PUSH32(c, v_); } /* push 0x4000 */
    { uint32_t v_ = 0x100000u; PUSH32(c, v_); } /* push 0x100000 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a076dcu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a076e7u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00a076f4u); call_indirect(c, t_); } /* call ebp */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->ebx, R32((uint32_t)(0xa139d8u))); /* cmp ebx, dword ptr [0x100139d8] */
    if ((c->sf != c->of)) goto L_00a076ce; /* jl 0xa076ce */
L_00a07700:;
    { uint32_t v_ = R32((uint32_t)(0xa139dcu)); PUSH32(c, v_); } /* push dword ptr [0x100139dc] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = c->ebp; PUSH32(c, 0x00a07710u); call_indirect(c, t_); } /* call ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    goto L_00a0773b; /* jmp 0xa0773b */
L_00a07714:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_00a0773b; /* jne 0xa0773b */
    c->edi = (uint32_t)((uint32_t)0xa10a88u); /* mov edi, 0x10010a88 */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
L_00a07720:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov eax, dword ptr [esi + 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07735; /* je 0xa07735 */
    { uint32_t v_ = 0x8000u; PUSH32(c, v_); } /* push 0x8000 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e0a0u)); PUSH32(c, 0x00a07735u); call_indirect(c, t_); } /* call dword ptr [0x1000e0a0] */
L_00a07735:;
    c->esi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov esi, dword ptr [esi] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_00a07720; /* jne 0xa07720 */
L_00a0773b:;
    { uint32_t v_ = R32((uint32_t)(0xa139e4u)); PUSH32(c, v_); } /* push dword ptr [0x100139e4] */
    { uint32_t t_ = R32((uint32_t)(0xa0e098u)); PUSH32(c, 0x00a07747u); call_indirect(c, t_); } /* call dword ptr [0x1000e098] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a0774a(CPU *c) { /* FUN_1000774a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 16; return; /* ret 0xc */
}

void f_00a07750(CPU *c) { /* FUN_10007750 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0xa13434u))); /* mov eax, dword ptr [0x10013434] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00a07767; /* je 0xa07767 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a07788; /* jne 0xa07788 */
    (void)sub32(c, R32((uint32_t)(0xa13438u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013438], 1 */
    if (!c->zf) goto L_00a07788; /* jne 0xa07788 */
L_00a07767:;
    { uint32_t v_ = 0xfcu; PUSH32(c, v_); } /* push 0xfc */
    PUSH32(c, 0x00a07771u); f_00a07789(c); /* call 0xa07789 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa135ecu))); /* mov eax, dword ptr [0x100135ec] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a0777d; /* je 0xa0777d */
    { uint32_t t_ = c->eax; PUSH32(c, 0x00a0777du); call_indirect(c, t_); } /* call eax */
L_00a0777d:;
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    PUSH32(c, 0x00a07787u); f_00a07789(c); /* call 0xa07789 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07788:;
    c->esp += 4; return; /* ret  */
}

void f_00a07789(CPU *c) { /* FUN_10007789 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1a4u)); /* sub esp, 0x1a4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0xa10598u); /* mov eax, 0x10010598 */
L_00a0779c:;
    (void)sub32(c, c->edx, R32((uint32_t)(c->eax))); /* cmp edx, dword ptr [eax] */
    if (c->zf) goto L_00a077ab; /* je 0xa077ab */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->eax, (uint32_t)0xa10628u); /* cmp eax, 0x10010628 */
    if ((c->sf != c->of)) goto L_00a0779c; /* jl 0xa0779c */
L_00a077ab:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 3)); /* shl esi, 3 */
    (void)sub32(c, c->edx, R32((uint32_t)(c->esi + 0xa10598u))); /* cmp edx, dword ptr [esi + 0x10010598] */
    if (!c->zf) goto L_00a078d9; /* jne 0xa078d9 */
    c->eax = (uint32_t)(R32((uint32_t)(0xa13434u))); /* mov eax, dword ptr [0x10013434] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_00a078b3; /* je 0xa078b3 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a077dc; /* jne 0xa077dc */
    (void)sub32(c, R32((uint32_t)(0xa13438u)), (uint32_t)0x1u); /* cmp dword ptr [0x10013438], 1 */
    if (c->zf) goto L_00a078b3; /* je 0xa078b3 */
L_00a077dc:;
    (void)sub32(c, c->edx, (uint32_t)0xfcu); /* cmp edx, 0xfc */
    if (c->zf) goto L_00a078d9; /* je 0xa078d9 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0x104u; PUSH32(c, v_); } /* push 0x104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = R32((uint32_t)(0xa0e078u)); PUSH32(c, 0x00a077fcu); call_indirect(c, t_); } /* call dword ptr [0x1000e078] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a07813; /* jne 0xa07813 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = 0xa0e778u; PUSH32(c, v_); } /* push 0x1000e778 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07811u); f_00a08170(c); /* call 0xa08170 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07813:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea edi, [ebp - 0x1a4] */
    PUSH32(c, 0x00a07826u); f_00a08600(c); /* call 0xa08600 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->eax, (uint32_t)0x3cu); /* cmp eax, 0x3c */
    if ((c->cf || c->zf)) goto L_00a07856; /* jbe 0xa07856 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07839u); f_00a08600(c); /* call 0xa08600 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffe5cu)); /* lea eax, [ebp - 0x1a4] */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3bu)); /* sub eax, 0x3b */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
    { uint32_t v_ = 0xa0e774u; PUSH32(c, v_); } /* push 0x1000e774 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a07853u); f_00a0b730(c); /* call 0xa0b730 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00a07856:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xa0e758u; PUSH32(c, v_); } /* push 0x1000e758 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07867u); f_00a08170(c); /* call 0xa08170 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07874u); f_00a08180(c); /* call 0xa08180 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xa0e754u; PUSH32(c, v_); } /* push 0x1000e754 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07885u); f_00a08180(c); /* call 0xa08180 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0xa1059cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1001059c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07897u); f_00a08180(c); /* call 0xa08180 */
    { uint32_t v_ = 0x12010u; PUSH32(c, v_); } /* push 0x12010 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff60u)); /* lea eax, [ebp - 0xa0] */
    { uint32_t v_ = 0xa0e72cu; PUSH32(c, v_); } /* push 0x1000e72c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a078adu); f_00a0b69f(c); /* call 0xa0b69f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_00a078d9; /* jmp 0xa078d9 */
L_00a078b3:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)(c->esi + 0xa1059cu)); /* lea esi, [esi + 0x1001059c] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x00a078c6u); f_00a08600(c); /* call 0xa08600 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = 0xfffffff4u; PUSH32(c, v_); } /* push -0xc */
    { uint32_t t_ = R32((uint32_t)(0xa0e06cu)); PUSH32(c, 0x00a078d2u); call_indirect(c, t_); } /* call dword ptr [0x1000e06c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0xa0e0a4u)); PUSH32(c, 0x00a078d9u); call_indirect(c, t_); } /* call dword ptr [0x1000e0a4] */
L_00a078d9:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a078dc(CPU *c) { /* FUN_100078dc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xfffffffcu), c->fpu_cw); /* fnstcw word ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    PUSH32(c, 0x00a078edu); f_00a07927(c); /* call 0xa07927 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)((uint32_t)~c->eax); /* not eax */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & c->eax))); /* and esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | c->eax))); /* or esi, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a07904u); f_00a079b9(c); /* call 0xa079b9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xcu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07911(CPU *c) { /* FUN_10007911 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfff7ffffu))); /* and eax, 0xfff7ffff */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x00a07924u); f_00a078dc(c); /* call 0xa078dc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_00a07927(CPU *c) { /* FUN_10007927 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_00a07938; /* je 0xa07938 */
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a07938:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00a0793f; /* je 0xa0793f */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00a0793f:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00a07946; /* je 0xa07946 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00a07946:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00a0794d; /* je 0xa0794d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00a0794d:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x20u)); /* test bl, 0x20 */
    if (c->zf) goto L_00a07954; /* je 0xa07954 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x1u))); /* or al, 1 */
L_00a07954:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00a0795e; /* je 0xa0795e */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x80000u))); /* or eax, 0x80000 */
L_00a0795e:;
    c->ecx = (uint32_t)((uint32_t)((uint16_t)c->ebx)); /* movzx ecx, bx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (uint32_t)(c->ecx); /* mov edx, ecx */
    c->esi = (uint32_t)((uint32_t)0xc00u); /* mov esi, 0xc00 */
    c->edi = (uint32_t)((uint32_t)0x300u); /* mov edi, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->esi))); /* and edx, esi */
    c->ebp = (uint32_t)((uint32_t)0x200u); /* mov ebp, 0x200 */
    if (c->zf) goto L_00a07996; /* je 0xa07996 */
    (void)sub32(c, c->edx, (uint32_t)0x400u); /* cmp edx, 0x400 */
    if (c->zf) goto L_00a07993; /* je 0xa07993 */
    (void)sub32(c, c->edx, (uint32_t)0x800u); /* cmp edx, 0x800 */
    if (c->zf) goto L_00a0798f; /* je 0xa0798f */
    (void)sub32(c, c->edx, c->esi); /* cmp edx, esi */
    if (!c->zf) goto L_00a07996; /* jne 0xa07996 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    goto L_00a07996; /* jmp 0xa07996 */
L_00a0798f:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ebp))); /* or eax, ebp */
    goto L_00a07996; /* jmp 0xa07996 */
L_00a07993:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x1u))) << 8); /* or ah, 1 */
L_00a07996:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edi))); /* and ecx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00a079a6; /* je 0xa079a6 */
    (void)sub32(c, c->ecx, c->ebp); /* cmp ecx, ebp */
    if (!c->zf) goto L_00a079ab; /* jne 0xa079ab */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x10000u))); /* or eax, 0x10000 */
    goto L_00a079ab; /* jmp 0xa079ab */
L_00a079a6:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x20000u))); /* or eax, 0x20000 */
L_00a079ab:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x10u)); /* test bh, 0x10 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00a079b8; /* je 0xa079b8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0x40000u))); /* or eax, 0x40000 */
L_00a079b8:;
    c->esp += 4; return; /* ret  */
}

void f_00a079b9(CPU *c) { /* FUN_100079b9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ebx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x10u)); /* test bl, 0x10 */
    if (c->zf) goto L_00a079c9; /* je 0xa079c9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_00a079c9:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_00a079d0; /* je 0xa079d0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x4u))); /* or al, 4 */
L_00a079d0:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (c->zf) goto L_00a079d7; /* je 0xa079d7 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x8u))); /* or al, 8 */
L_00a079d7:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_00a079de; /* je 0xa079de */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x10u))); /* or al, 0x10 */
L_00a079de:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_00a079e5; /* je 0xa079e5 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
L_00a079e5:;
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000u)); /* test ebx, 0x80000 */
    if (c->zf) goto L_00a079ef; /* je 0xa079ef */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
L_00a079ef:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->edx = (uint32_t)((uint32_t)0x300u); /* mov edx, 0x300 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & c->edx))); /* and ecx, edx */
    c->esi = (uint32_t)((uint32_t)0x200u); /* mov esi, 0x200 */
    if (c->zf) goto L_00a07a1c; /* je 0xa07a1c */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (c->zf) goto L_00a07a19; /* je 0xa07a19 */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    if (c->zf) goto L_00a07a14; /* je 0xa07a14 */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (!c->zf) goto L_00a07a1c; /* jne 0xa07a1c */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0xcu))) << 8); /* or ah, 0xc */
    goto L_00a07a1c; /* jmp 0xa07a1c */
L_00a07a14:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x8u))) << 8); /* or ah, 8 */
    goto L_00a07a1c; /* jmp 0xa07a1c */
L_00a07a19:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x4u))) << 8); /* or ah, 4 */
L_00a07a1c:;
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x30000u))); /* and ecx, 0x30000 */
    if (c->zf) goto L_00a07a32; /* je 0xa07a32 */
    (void)sub32(c, c->ecx, (uint32_t)0x10000u); /* cmp ecx, 0x10000 */
    if (!c->zf) goto L_00a07a34; /* jne 0xa07a34 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->esi))); /* or eax, esi */
    goto L_00a07a34; /* jmp 0xa07a34 */
L_00a07a32:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
L_00a07a34:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->ebx & (uint32_t)0x40000u)); /* test ebx, 0x40000 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_00a07a41; /* je 0xa07a41 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | (uint8_t)0x10u))) << 8); /* or ah, 0x10 */
L_00a07a41:;
    c->esp += 4; return; /* ret  */
}

void f_00a07a42(CPU *c) { /* FUN_10007a42 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_00a07a60; /* ja 0xa07a60 */
    c->ecx = (uint32_t)(R32((uint32_t)(0xa10634u))); /* mov ecx, dword ptr [0x10010634] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_00a07ab2; /* jmp 0xa07ab2 */
L_00a07a60:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0xa10634u))); /* mov esi, dword ptr [0x10010634] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_00a07a85; /* je 0xa07a85 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_00a07a8e; /* jmp 0xa07a8e */
L_00a07a85:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_00a07a8e:;
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
    PUSH32(c, 0x00a07aa5u); f_00a0b9ed(c); /* call 0xa0b9ed */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a07aae; /* jne 0xa07aae */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a07aae:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_00a07ab2:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07ab7(CPU *c) { /* FUN_10007ab7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, R32((uint32_t)(0xa13638u)), c->ebx); /* cmp dword ptr [0x10013638], ebx */
    if (!c->zf) goto L_00a07ad5; /* jne 0xa07ad5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_00a07b24; /* jl 0xa07b24 */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_00a07b24; /* jg 0xa07b24 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_00a07ad5:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)0xa13794u); /* mov esi, 0x10013794 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0xa0e0acu)); PUSH32(c, 0x00a07ae3u); call_indirect(c, t_); } /* call dword ptr [0x1000e0ac] */
    (void)sub32(c, R32((uint32_t)(0xa13790u)), c->ebx); /* cmp dword ptr [0x10013790], ebx */
    c->edi = (uint32_t)(R32((uint32_t)(0xa0e0a8u))); /* mov edi, dword ptr [0x1000e0a8] */
    if (c->zf) goto L_00a07aff; /* je 0xa07aff */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a07af4u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a07afbu); f_00a06c3b(c); /* call 0xa06c3b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
L_00a07aff:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x00a07b08u); f_00a07b26(c); /* call 0xa07b26 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->esp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [esp + 0x10], eax */
    if (c->zf) goto L_00a07b1b; /* je 0xa07b1b */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x00a07b18u); f_00a06c9c(c); /* call 0xa06c9c */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a07b1e; /* jmp 0xa07b1e */
L_00a07b1b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = c->edi; PUSH32(c, 0x00a07b1eu); call_indirect(c, t_); } /* call edi */
L_00a07b1e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_00a07b24:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a07b26(CPU *c) { /* FUN_10007b26 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(0xa13638u)), (uint32_t)0x0u); /* cmp dword ptr [0x10013638], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_00a07b53; /* jne 0xa07b53 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x41u); /* cmp eax, 0x41 */
    if ((c->sf != c->of)) goto L_00a07bec; /* jl 0xa07bec */
    (void)sub32(c, c->eax, (uint32_t)0x5au); /* cmp eax, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_00a07bec; /* jg 0xa07bec */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    goto L_00a07bec; /* jmp 0xa07bec */
L_00a07b53:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)((uint32_t)0x100u); /* mov edi, 0x100 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if ((c->sf == c->of)) goto L_00a07b87; /* jge 0xa07b87 */
    (void)sub32(c, R32((uint32_t)(0xa10628u)), c->esi); /* cmp dword ptr [0x10010628], esi */
    if ((c->zf || c->sf != c->of)) goto L_00a07b75; /* jle 0xa07b75 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x00a07b71u); f_00a07a42(c); /* call 0xa07a42 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a07b7f; /* jmp 0xa07b7f */
L_00a07b75:;
    c->eax = (uint32_t)(R32((uint32_t)(0xa10634u))); /* mov eax, dword ptr [0x10010634] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->ebx * 2))); /* mov al, byte ptr [eax + ebx*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & c->esi))); /* and eax, esi */
L_00a07b7f:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_00a07b87; /* jne 0xa07b87 */
L_00a07b83:;
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    goto L_00a07bec; /* jmp 0xa07bec */
L_00a07b87:;
    c->edx = (uint32_t)(R32((uint32_t)(0xa10634u))); /* mov edx, dword ptr [0x10010634] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->eax = (uint32_t)(sar32(c, c->eax, 8)); /* sar eax, 8 */
    c->ecx = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx ecx, al */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edx + c->ecx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [edx + ecx*2 + 1], 0x80 */
    if (c->zf) goto L_00a07bab; /* je 0xa07bab */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xau); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 0xa], 0 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp + 8], al */
    W8((uint32_t)(c->ebp + 0x9u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 9], bl */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a07bb4; /* jmp 0xa07bb4 */
L_00a07bab:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x9u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + 9], 0 */
    W8((uint32_t)(c->ebp + 0x8u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [ebp + 8], bl */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_00a07bb4:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea ecx, [ebp - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0xa13638u)); PUSH32(c, v_); } /* push dword ptr [0x10013638] */
    PUSH32(c, 0x00a07bceu); f_00a0bb36(c); /* call 0xa0bb36 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07b83; /* je 0xa07b83 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_00a07bdf; /* jne 0xa07bdf */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx eax, byte ptr [ebp - 4] */
    goto L_00a07bec; /* jmp 0xa07bec */
L_00a07bdf:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffdu))); /* movzx eax, byte ptr [ebp - 3] */
    c->ecx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0xfffffffcu))); /* movzx ecx, byte ptr [ebp - 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->ecx))); /* or eax, ecx */
L_00a07bec:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07bf1(CPU *c) { /* FUN_10007bf1 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07bfau, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07c05u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->edx)); /* sub ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    c->edx = (uint32_t)((uint32_t)~c->edx); /* not edx */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4)) & c->edx)); /* test dword ptr [eax + esi*4], edx */
    if (!c->zf) goto L_00a07c36; /* jne 0xa07c36 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf == c->of)) goto L_00a07c31; /* jge 0xa07c31 */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->esi * 4)); /* lea eax, [eax + esi*4] */
L_00a07c23:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00a07c36; /* jne 0xa07c36 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if ((c->sf != c->of)) goto L_00a07c23; /* jl 0xa07c23 */
L_00a07c31:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_00a07c36:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a07c3a(CPU *c) { /* FUN_10007c3a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07c49u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07c52u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
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
    PUSH32(c, 0x00a07c6au); f_00a0bd85(c); /* call 0xa0bd85 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    if (c->sf) goto L_00a07c8c; /* js 0xa07c8c */
    c->edi = (uint32_t)((uint32_t)(c->ebx + c->esi * 4)); /* lea edi, [ebx + esi*4] */
L_00a07c73:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07c8c; /* je 0xa07c8c */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    PUSH32(c, 0x00a07c81u); f_00a0bd85(c); /* call 0xa0bd85 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->edi = (uint32_t)(sub32(c, c->edi, (uint32_t)0x4u)); /* sub edi, 4 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_00a07c73; /* jge 0xa07c73 */
L_00a07c8c:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_00a07c90(CPU *c) { /* FUN_10007c90 */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07caeu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t v_ = 0x1fu; PUSH32(c, v_); } /* push 0x1f */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07cb7u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
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
    if (c->zf) goto L_00a07cf4; /* je 0xa07cf4 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a07cddu); f_00a07bf1(c); /* call 0xa07bf1 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a07cf1; /* jne 0xa07cf1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x00a07cecu); f_00a07c3a(c); /* call 0xa07c3a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07cf1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_00a07cf4:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0xffffffffu))); /* or edx, 0xffffffff */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    c->edx = (uint32_t)(shl32(c, c->edx, (c->ecx & 0xff))); /* shl edx, cl */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->edx)))); } /* and dword ptr [eax], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if ((c->sf == c->of)) goto L_00a07d14; /* jge 0xa07d14 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->edi = (uint32_t)((uint32_t)(c->edx + c->eax * 4)); /* lea edi, [edx + eax*4] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
L_00a07d14:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07d1c(CPU *c) { /* FUN_10007d1c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00a07d2a:;
    c->esi = (uint32_t)(R32((uint32_t)(c->eax))); /* mov esi, dword ptr [eax] */
    W32((uint32_t)(c->ecx + c->eax), (uint32_t)(c->esi)); /* mov dword ptr [ecx + eax], esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00a07d2a; /* jne 0xa07d2a */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_00a07d37(CPU *c) { /* FUN_10007d37 */
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

void f_00a07d43(CPU *c) { /* FUN_10007d43 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
L_00a07d49:;
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0x0u); /* cmp dword ptr [eax], 0 */
    if (!c->zf) goto L_00a07d5b; /* jne 0xa07d5b */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x4u)); /* add eax, 4 */
    (void)sub32(c, c->ecx, (uint32_t)0x3u); /* cmp ecx, 3 */
    if ((c->sf != c->of)) goto L_00a07d49; /* jl 0xa07d49 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_00a07d5b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_00a07d5e(CPU *c) { /* FUN_10007d5e */
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
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07d7du, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->ecx; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x00a07d86u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->esi = (uint32_t)(shl32(c, c->esi, (c->ecx & 0xff))); /* shl esi, cl */
    c->ebx = (uint32_t)(sub32(c, c->ebx, c->edx)); /* sub ebx, edx */
    c->esi = (uint32_t)((uint32_t)~c->esi); /* not esi */
L_00a07d94:;
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
    if (!c->zf) goto L_00a07d94; /* jne 0xa07d94 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov edi, dword ptr [ebp - 0xc] */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
L_00a07dc6:;
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if ((c->sf != c->of)) goto L_00a07dd9; /* jl 0xa07dd9 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(sub32(c, c->eax, c->esi)); /* sub eax, esi */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->edx))); /* mov eax, dword ptr [eax + edx] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    goto L_00a07de0; /* jmp 0xa07de0 */
L_00a07dd9:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ecx + c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ecx + eax], 0 */
L_00a07de0:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (!c->sf) goto L_00a07dc6; /* jns 0xa07dc6 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07deb(CPU *c) { /* FUN_10007deb */
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
    if (!c->zf) goto L_00a07e58; /* jne 0xa07e58 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07e3du); f_00a07d43(c); /* call 0xa07d43 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_00a07f17; /* jne 0xa07f17 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07e4fu); f_00a07d37(c); /* call 0xa07d37 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07e50:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
L_00a07e52:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_00a07f19; /* jmp 0xa07f19 */
L_00a07e58:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07e65u); f_00a07d1c(c); /* call 0xa07d1c */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07e71u); f_00a07c90(c); /* call 0xa07c90 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_00a07e79; /* je 0xa07e79 */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
L_00a07e79:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->edi + 0x8u)))); /* sub ecx, dword ptr [edi + 8] */
    (void)sub32(c, c->ebx, c->ecx); /* cmp ebx, ecx */
    if ((c->sf == c->of)) goto L_00a07e91; /* jge 0xa07e91 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07e8eu); f_00a07d37(c); /* call 0xa07d37 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_00a07ecd; /* jmp 0xa07ecd */
L_00a07e91:;
    (void)sub32(c, c->ebx, c->eax); /* cmp ebx, eax */
    if ((!c->zf && c->sf == c->of)) goto L_00a07ed4; /* jg 0xa07ed4 */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ebx)); /* sub eax, ebx */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07ea6u); f_00a07d1c(c); /* call 0xa07d1c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07eb0u); f_00a07d5e(c); /* call 0xa07d5e */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0x8u)); PUSH32(c, v_); } /* push dword ptr [edi + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07ebcu); f_00a07c90(c); /* call 0xa07c90 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0xcu))); /* mov eax, dword ptr [edi + 0xc] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07ecau); f_00a07d5e(c); /* call 0xa07d5e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_00a07ecd:;
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_00a07e50; /* jmp 0xa07e50 */
L_00a07ed4:;
    (void)sub32(c, c->ebx, R32((uint32_t)(c->edi))); /* cmp ebx, dword ptr [edi] */
    if ((c->sf != c->of)) goto L_00a07f00; /* jl 0xa07f00 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07ee1u); f_00a07d37(c); /* call 0xa07d37 */
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 9], 0x80 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07ef1u); f_00a07d5e(c); /* call 0xa07d5e */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->edi)))); /* add esi, dword ptr [edi] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    goto L_00a07e52; /* jmp 0xa07e52 */
L_00a07f00:;
    { uint32_t v_ = R32((uint32_t)(c->edi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [edi + 0xc] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edi + 0x14u))); /* mov esi, dword ptr [edi + 0x14] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff7u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x7fu)))); } /* and byte ptr [ebp - 9], 0x7f */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esi = (uint32_t)(add32(c, c->esi, c->ebx)); /* add esi, ebx */
    PUSH32(c, 0x00a07f15u); f_00a07d5e(c); /* call 0xa07d5e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_00a07f17:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_00a07f19:;
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
    if (!c->zf) goto L_00a07f48; /* jne 0xa07f48 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov edx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->ecx + 0x4u), (uint32_t)(c->esi)); /* mov dword ptr [ecx + 4], esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    goto L_00a07f52; /* jmp 0xa07f52 */
L_00a07f48:;
    (void)sub32(c, c->edi, (uint32_t)0x20u); /* cmp edi, 0x20 */
    if (!c->zf) goto L_00a07f52; /* jne 0xa07f52 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
L_00a07f52:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07f57(CPU *c) { /* FUN_10007f57 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa10840u; PUSH32(c, v_); } /* push 0x10010840 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00a07f69u); f_00a07deb(c); /* call 0xa07deb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00a07f6d(CPU *c) { /* FUN_10007f6d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xa10858u; PUSH32(c, v_); } /* push 0x10010858 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x00a07f7fu); f_00a07deb(c); /* call 0xa07deb */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_00a07f83(CPU *c) { /* FUN_10007f83 */
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
    PUSH32(c, 0x00a07f9fu); f_00a0bf26(c); /* call 0xa0bf26 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07fabu); f_00a07f57(c); /* call 0xa07f57 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07fb0(CPU *c) { /* FUN_10007fb0 */
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
    PUSH32(c, 0x00a07fccu); f_00a0bf26(c); /* call 0xa0bf26 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff4u)); /* lea eax, [ebp - 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x00a07fd8u); f_00a07f6d(c); /* call 0xa07f6d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x24u)); /* add esp, 0x24 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a07fdd(CPU *c) { /* FUN_10007fdd */
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
    if ((c->zf || c->sf != c->of)) goto L_00a0801a; /* jle 0xa0801a */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_00a08000:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a0800c; /* je 0xa0800c */
    c->edx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->edx)); /* movsx edx, dl */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_00a0800f; /* jmp 0xa0800f */
L_00a0800c:;
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_00a0800f:;
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 8] */
    if (!c->zf) goto L_00a08000; /* jne 0xa08000 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
L_00a0801a:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if ((c->sf != c->of)) goto L_00a08033; /* jl 0xa08033 */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x35u); /* cmp byte ptr [ecx], 0x35 */
    if ((c->sf != c->of)) goto L_00a08033; /* jl 0xa08033 */
L_00a08026:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x39u); /* cmp byte ptr [eax], 0x39 */
    if (!c->zf) goto L_00a08031; /* jne 0xa08031 */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    goto L_00a08026; /* jmp 0xa08026 */
L_00a08031:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(inc8(c, R8(a_)))); } /* inc byte ptr [eax] */
L_00a08033:;
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x31u); /* cmp byte ptr [esi], 0x31 */
    if (!c->zf) goto L_00a0803d; /* jne 0xa0803d */
    { uint32_t a_ = (uint32_t)(c->edx + 0x4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [edx + 4] */
    goto L_00a0804f; /* jmp 0xa0804f */
L_00a0803d:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x00a08043u); f_00a08600(c); /* call 0xa08600 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x00a0804cu); f_00a082c0(c); /* call 0xa082c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_00a0804f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_00a08054(CPU *c) { /* FUN_10008054 */
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
    PUSH32(c, 0x00a08069u); f_00a080b0(c); /* call 0xa080b0 */
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
    PUSH32(c, 0x00a08084u); f_00a0c3f7(c); /* call 0xa0c3f7 */
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
    PUSH32(c, 0x00a080a4u); f_00a08170(c); /* call 0xa08170 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [esi + 0xc], edi */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a080b0(CPU *c) { /* FUN_100080b0 */
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
    if (c->zf) goto L_00a080fe; /* je 0xa080fe */
    (void)sub32(c, c->ebx, c->edi); /* cmp ebx, edi */
    if (c->zf) goto L_00a080f7; /* je 0xa080f7 */
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c00u)); /* lea edi, [ecx + 0x3c00] */
    goto L_00a0811f; /* jmp 0xa0811f */
L_00a080f7:;
    c->edi = (uint32_t)((uint32_t)0x7fffu); /* mov edi, 0x7fff */
    goto L_00a0811f; /* jmp 0xa0811f */
L_00a080fe:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (!c->zf) goto L_00a08116; /* jne 0xa08116 */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (!c->zf) goto L_00a08116; /* jne 0xa08116 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [eax + 8], bx */
    goto L_00a08161; /* jmp 0xa08161 */
L_00a08116:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0x3c01u)); /* lea edi, [ecx + 0x3c01] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
L_00a0811f:;
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 21)); /* shr ecx, 0x15 */
    c->eax = (uint32_t)(shl32(c, c->eax, 11)); /* shl eax, 0xb */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | R32((uint32_t)(c->ebp + 0xfffffffcu))))); /* or ecx, dword ptr [ebp - 4] */
    c->edx = (uint32_t)(shl32(c, c->edx, 11)); /* shl edx, 0xb */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    W32((uint32_t)(c->eax), (uint32_t)(c->edx)); /* mov dword ptr [eax], edx */
L_00a08137:;
    (void)logic32(c, (uint32_t)(c->esi & c->ecx)); /* test esi, ecx */
    if (!c->zf) goto L_00a08158; /* jne 0xa08158 */
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
    goto L_00a08137; /* jmp 0xa08137 */
L_00a08158:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->edi))); /* or ecx, edi */
    W16((uint32_t)(c->eax + 0x8u), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax + 8], cx */
L_00a08161:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_00a08170(CPU *c) { /* FUN_10008170 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edi, dword ptr [esp + 8] */
    { f_00a081e1(c); return; } /* jmp 0xa081e1 */
}

void f_00a08180(CPU *c) { /* FUN_10008180 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00a0819c; /* je 0xa0819c */
L_00a0818d:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov al, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a081cf; /* je 0xa081cf */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00a0818d; /* jne 0xa0818d */
L_00a0819c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00a0819c; /* je 0xa0819c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov eax, dword ptr [ecx - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_00a081de; /* je 0xa081de */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_00a081d9; /* je 0xa081d9 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff0000u)); /* test eax, 0xff0000 */
    if (c->zf) goto L_00a081d4; /* je 0xa081d4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xff000000u)); /* test eax, 0xff000000 */
    if (c->zf) goto L_00a081cf; /* je 0xa081cf */
    goto L_00a0819c; /* jmp 0xa0819c */
L_00a081cf:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xffffffffu)); /* lea edi, [ecx - 1] */
    goto L_00a081e1; /* jmp 0xa081e1 */
L_00a081d4:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffeu)); /* lea edi, [ecx - 2] */
    goto L_00a081e1; /* jmp 0xa081e1 */
L_00a081d9:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffdu)); /* lea edi, [ecx - 3] */
    goto L_00a081e1; /* jmp 0xa081e1 */
L_00a081de:;
    c->edi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea edi, [ecx - 4] */
L_00a081e1:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00a08206; /* je 0xa08206 */
L_00a081ed:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a08258; /* je 0xa08258 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00a081ed; /* jne 0xa081ed */
    goto L_00a08206; /* jmp 0xa08206 */
L_00a08201:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_00a08206:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00a08201; /* je 0xa08201 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a08258; /* je 0xa08258 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00a0824f; /* je 0xa0824f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00a08242; /* je 0xa08242 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_00a0823a; /* je 0xa0823a */
    goto L_00a08201; /* jmp 0xa08201 */
L_00a0823a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a08242:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a0824f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a08258:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a081e1(CPU *c) { /* PTR_00a081e1 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (c->zf) goto L_00a08206; /* je 0xa08206 */
L_00a081ed:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a08258; /* je 0xa08258 */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u)); /* test ecx, 3 */
    if (!c->zf) goto L_00a081ed; /* jne 0xa081ed */
    goto L_00a08206; /* jmp 0xa08206 */
L_00a08201:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
L_00a08206:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_00a08201; /* je 0xa08201 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_00a08258; /* je 0xa08258 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_00a0824f; /* je 0xa0824f */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_00a08242; /* je 0xa08242 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (c->zf) goto L_00a0823a; /* je 0xa0823a */
    goto L_00a08201; /* jmp 0xa08201 */
L_00a0823a:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a08242:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)((uint8_t)0x0u)); /* mov byte ptr [edi + 2], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a0824f:;
    W16((uint32_t)(c->edi), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [edi], dx */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a08258:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [edi], dl */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_00a08260(CPU *c) { /* _memset */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00a082b3; /* je 0xa082b3 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(c->ecx); /* mov edi, ecx */
    (void)sub32(c, c->edx, (uint32_t)0x4u); /* cmp edx, 4 */
    if (c->cf) goto L_00a082a7; /* jb 0xa082a7 */
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x3u))); /* and ecx, 3 */
    if (c->zf) goto L_00a08289; /* je 0xa08289 */
    c->edx = (uint32_t)(sub32(c, c->edx, c->ecx)); /* sub edx, ecx */
L_00a08283:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_00a08283; /* jne 0xa08283 */
L_00a08289:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 16)); /* shl eax, 0x10 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(c->edx); /* mov ecx, edx */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (c->zf) goto L_00a082a7; /* je 0xa082a7 */
    while (c->ecx) { W32(c->edi, (uint32_t)c->eax); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep stosd dword ptr es:[edi], eax */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_00a082ad; /* je 0xa082ad */
L_00a082a7:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edx = (uint32_t)(dec32(c, c->edx)); /* dec edx */
    if (!c->zf) goto L_00a082a7; /* jne 0xa082a7 */
L_00a082ad:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_00a082b3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 4; return; /* ret  */
}

void f_00a082c0(CPU *c) { /* FUN_100082c0 */
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
    if ((c->cf || c->zf)) goto L_00a082e0; /* jbe 0xa082e0 */
    (void)sub32(c, c->edi, c->eax); /* cmp edi, eax */
    if (c->cf) goto L_00a08458; /* jb 0xa08458 */
L_00a082e0:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00a082fc; /* jne 0xa082fc */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00a0831c; /* jb 0xa0831c */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa08408u)); switch (t_) { case 0x00a08418u: goto L_00a08418; case 0x00a08420u: goto L_00a08420; case 0x00a0842cu: goto L_00a0842c; case 0x00a08440u: goto L_00a08440; default: jump_indirect(c, t_, 0x00a082f5u); return; } } /* jmp dword ptr [edx*4 + 0x10008408] */
L_00a082fc:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x4u)); /* sub ecx, 4 */
    if (c->cf) goto L_00a08314; /* jb 0xa08314 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xa08320u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a0830du); return; } } /* jmp dword ptr [eax*4 + 0x10008320] */
L_00a08314:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa08418u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a08314u); return; } } /* jmp dword ptr [ecx*4 + 0x10008418] */
L_00a0831c:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa0839cu)); switch (t_) { case 0x00a083bcu: goto L_00a083bc; case 0x00a083c4u: goto L_00a083c4; case 0x00a083ccu: goto L_00a083cc; case 0x00a083d4u: goto L_00a083d4; case 0x00a083dcu: goto L_00a083dc; case 0x00a083e4u: goto L_00a083e4; case 0x00a083ecu: goto L_00a083ec; case 0x00a083ffu: goto L_00a083ff; default: jump_indirect(c, t_, 0x00a0831cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000839c] */
L_00a083bc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00a083c4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00a083cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00a083d4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00a083dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00a083e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00a083ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00a083ff:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa08408u)); switch (t_) { case 0x00a08418u: goto L_00a08418; case 0x00a08420u: goto L_00a08420; case 0x00a0842cu: goto L_00a0842c; case 0x00a08440u: goto L_00a08440; default: jump_indirect(c, t_, 0x00a083ffu); return; } } /* jmp dword ptr [edx*4 + 0x10008408] */
L_00a08418:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a08420:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a0842c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a08440:;
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
L_00a08458:;
    c->esi = (uint32_t)((uint32_t)(c->ecx + c->esi + 0xfffffffcu)); /* lea esi, [ecx + esi - 4] */
    c->edi = (uint32_t)((uint32_t)(c->ecx + c->edi + 0xfffffffcu)); /* lea edi, [ecx + edi - 4] */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_00a0848c; /* jne 0xa0848c */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u))); /* and edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x8u); /* cmp ecx, 8 */
    if (c->cf) goto L_00a08480; /* jb 0xa08480 */
    c->df = 1; /* std  */
    if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } else while (c->ecx) { W32(c->edi, R32(c->esi)); c->esi += (c->df ? -4 : 4); c->edi += (c->df ? -4 : 4); c->ecx--; } /* rep movsd dword ptr es:[edi], dword ptr [esi] */
    c->df = 0; /* cld  */
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa085a0u)); switch (t_) { case 0x00a085b0u: goto L_00a085b0; case 0x00a085b8u: goto L_00a085b8; case 0x00a085c8u: goto L_00a085c8; case 0x00a085dcu: goto L_00a085dc; default: jump_indirect(c, t_, 0x00a08477u); return; } } /* jmp dword ptr [edx*4 + 0x100085a0] */
L_00a08480:;
    c->ecx = (uint32_t)(neg32(c, c->ecx)); /* neg ecx */
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa08550u)); switch (t_) { case 0x00a08597u: goto L_00a08597; default: jump_indirect(c, t_, 0x00a08482u); return; } } /* jmp dword ptr [ecx*4 + 0x10008550] */
L_00a0848c:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edx = (uint32_t)((uint32_t)0x3u); /* mov edx, 3 */
    (void)sub32(c, c->ecx, (uint32_t)0x4u); /* cmp ecx, 4 */
    if (c->cf) goto L_00a084a4; /* jb 0xa084a4 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x3u))); /* and eax, 3 */
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0xa084a8u)); switch (t_) {  default: jump_indirect(c, t_, 0x00a0849du); return; } } /* jmp dword ptr [eax*4 + 0x100084a8] */
L_00a084a4:;
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa085a0u)); switch (t_) { case 0x00a085b0u: goto L_00a085b0; case 0x00a085b8u: goto L_00a085b8; case 0x00a085c8u: goto L_00a085c8; case 0x00a085dcu: goto L_00a085dc; default: jump_indirect(c, t_, 0x00a084a4u); return; } } /* jmp dword ptr [ecx*4 + 0x100085a0] */
L_00a08597:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa085a0u)); switch (t_) { case 0x00a085b0u: goto L_00a085b0; case 0x00a085b8u: goto L_00a085b8; case 0x00a085c8u: goto L_00a085c8; case 0x00a085dcu: goto L_00a085dc; default: jump_indirect(c, t_, 0x00a08597u); return; } } /* jmp dword ptr [edx*4 + 0x100085a0] */
L_00a085b0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a085b8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a085c8:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x3u))); /* mov al, byte ptr [esi + 3] */
    W8((uint32_t)(c->edi + 0x3u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 3], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x2u))); /* mov al, byte ptr [esi + 2] */
    W8((uint32_t)(c->edi + 0x2u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 2], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a085dc:;
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

void f_00a0831c(CPU *c) { /* PTR_00a0831c */
    PREEMPT_POLL(c);
    { uint32_t t_ = R32((uint32_t)(c->ecx * 4 + 0xa0839cu)); switch (t_) { case 0x00a083bcu: goto L_00a083bc; case 0x00a083c4u: goto L_00a083c4; case 0x00a083ccu: goto L_00a083cc; case 0x00a083d4u: goto L_00a083d4; case 0x00a083dcu: goto L_00a083dc; case 0x00a083e4u: goto L_00a083e4; case 0x00a083ecu: goto L_00a083ec; case 0x00a083ffu: goto L_00a083ff; default: jump_indirect(c, t_, 0x00a0831cu); return; } } /* jmp dword ptr [ecx*4 + 0x1000839c] */
L_00a083bc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe4u))); /* mov eax, dword ptr [esi + ecx*4 - 0x1c] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x1c], eax */
L_00a083c4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffe8u))); /* mov eax, dword ptr [esi + ecx*4 - 0x18] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x18], eax */
L_00a083cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xffffffecu))); /* mov eax, dword ptr [esi + ecx*4 - 0x14] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x14], eax */
L_00a083d4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff0u))); /* mov eax, dword ptr [esi + ecx*4 - 0x10] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0x10], eax */
L_00a083dc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff4u))); /* mov eax, dword ptr [esi + ecx*4 - 0xc] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 0xc], eax */
L_00a083e4:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffff8u))); /* mov eax, dword ptr [esi + ecx*4 - 8] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 8], eax */
L_00a083ec:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->ecx * 4 + 0xfffffffcu))); /* mov eax, dword ptr [esi + ecx*4 - 4] */
    W32((uint32_t)(c->edi + c->ecx * 4 + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [edi + ecx*4 - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ecx * 4)); /* lea eax, [ecx*4] */
    c->esi = (uint32_t)(add32(c, c->esi, c->eax)); /* add esi, eax */
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_00a083ff:;
    { uint32_t t_ = R32((uint32_t)(c->edx * 4 + 0xa08408u)); switch (t_) { case 0x00a08418u: goto L_00a08418; case 0x00a08420u: goto L_00a08420; case 0x00a0842cu: goto L_00a0842c; case 0x00a08440u: goto L_00a08440; default: jump_indirect(c, t_, 0x00a083ffu); return; } } /* jmp dword ptr [edx*4 + 0x10008408] */
L_00a08418:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a08420:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a0842c:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi + 0x1u))); /* mov al, byte ptr [esi + 1] */
    W8((uint32_t)(c->edi + 0x1u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi + 1], al */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_00a08440:;
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
