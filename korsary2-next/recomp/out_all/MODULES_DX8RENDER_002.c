#include "recomp.h"

void f_006ac94b(CPU *c) { /* PTR_006ac94b */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [eax + 8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    guest_trap(c, 0x006ac96fu, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    guest_trap(c, 0x006ac976u, "unsupported: pfmul mm1, qword ptr [edx + 0x10]"); /* pfmul mm1, qword ptr [edx + 0x10] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm2 */
    guest_trap(c, 0x006ac97eu, "unsupported: pfmul mm2, qword ptr [edx + 0x20]"); /* pfmul mm2, qword ptr [edx + 0x20] */
    guest_trap(c, 0x006ac983u, "unsupported: pfmul mm3, qword ptr [edx + 8]"); /* pfmul mm3, qword ptr [edx + 8] */
    guest_trap(c, 0x006ac988u, "unsupported: pfadd mm1, mm2"); /* pfadd mm1, mm2 */
    guest_trap(c, 0x006ac98cu, "unsupported: pfmul mm4, qword ptr [edx + 0x18]"); /* pfmul mm4, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006ac991u, "unsupported: pfmul mm5, qword ptr [edx + 0x28]"); /* pfmul mm5, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006ac996u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006ac99au, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006ac99eu, "unsupported: pfadd mm3, mm4"); /* pfadd mm3, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->ecx), v_); } /* movq qword ptr [ecx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [ecx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006ac9b2(CPU *c) { /* FUN_1001c9b2 */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [ecx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    guest_trap(c, 0x006ac9c5u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    guest_trap(c, 0x006ac9c9u, "unsupported: pfmul mm2, mm2"); /* pfmul mm2, mm2 */
    guest_trap(c, 0x006ac9cdu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006ac9d1u, "unsupported: pfacc mm0, mm0"); /* pfacc mm0, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006ac9d8u, "unsupported: pfrsqrt mm4, mm0"); /* pfrsqrt mm4, mm0 */
    guest_trap(c, 0x006ac9dcu, "unsupported: pfcmpgt mm5, qword ptr [0x1002f1d0]"); /* pfcmpgt mm5, qword ptr [0x1002f1d0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm4 */
    guest_trap(c, 0x006ac9e7u, "unsupported: pfmul mm2, mm4"); /* pfmul mm2, mm4 */
    guest_trap(c, 0x006ac9ebu, "unsupported: pfrsqit1 mm0, mm2"); /* pfrsqit1 mm0, mm2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[3], a_, 8); } /* pand mm3, mm5 */
    guest_trap(c, 0x006ac9f9u, "unsupported: pfrcpit2 mm0, mm4"); /* pfrcpit2 mm0, mm4 */
    guest_trap(c, 0x006ac9fdu, "unsupported: pfmul mm1, mm0"); /* pfmul mm1, mm0 */
    guest_trap(c, 0x006aca01u, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm1 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm3 */
    ; /* femms  */
    c->esp += 12; return; /* ret 8 */
}

void f_006aca11(CPU *c) { /* PTR_006aca11 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [esp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, dword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx] */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [eax + 8] */
    guest_trap(c, 0x006aca37u, "unsupported: pfsub mm0, mm4"); /* pfsub mm0, mm4 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [esp + 0x18] */
    guest_trap(c, 0x006aca40u, "unsupported: pfsub mm1, mm5"); /* pfsub mm1, mm5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006aca48u, "unsupported: pfsub mm2, mm4"); /* pfsub mm2, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    guest_trap(c, 0x006aca4fu, "unsupported: pfsub mm3, mm5"); /* pfsub mm3, mm5 */
    guest_trap(c, 0x006aca53u, "unsupported: pfmul mm0, mm6"); /* pfmul mm0, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    guest_trap(c, 0x006aca5au, "unsupported: pfmul mm1, mm6"); /* pfmul mm1, mm6 */
    guest_trap(c, 0x006aca5eu, "unsupported: pfadd mm0, mm4"); /* pfadd mm0, mm4 */
    guest_trap(c, 0x006aca62u, "unsupported: pfmul mm2, mm7"); /* pfmul mm2, mm7 */
    guest_trap(c, 0x006aca66u, "unsupported: pfadd mm1, mm5"); /* pfadd mm1, mm5 */
    guest_trap(c, 0x006aca6au, "unsupported: pfmul mm3, mm7"); /* pfmul mm3, mm7 */
    guest_trap(c, 0x006aca6eu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006aca72u, "unsupported: pfadd mm1, mm3"); /* pfadd mm1, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[1], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm1 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006aca82(CPU *c) { /* PTR_006aca82 */
    PREEMPT_POLL(c);
    ; /* femms  */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [esp + 0x18] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006aca8cu, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    guest_trap(c, 0x006aca93u, "unsupported: pfmul mm2, mm0"); /* pfmul mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1f8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm2 */
    guest_trap(c, 0x006acaa4u, "unsupported: pfsub mm7, mm1"); /* pfsub mm7, mm1 */
    guest_trap(c, 0x006acaa8u, "unsupported: pfmul mm4, mm3"); /* pfmul mm4, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006acaafu, "unsupported: pfmul mm1, qword ptr [0x1002f200]"); /* pfmul mm1, qword ptr [0x1002f200] */
    guest_trap(c, 0x006acab7u, "unsupported: pfmul mm2, mm3"); /* pfmul mm2, mm3 */
    guest_trap(c, 0x006acabbu, "unsupported: pfsub mm6, mm4"); /* pfsub mm6, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006acac2u, "unsupported: pfsub mm1, mm2"); /* pfsub mm1, mm2 */
    guest_trap(c, 0x006acac6u, "unsupported: pfadd mm6, mm0"); /* pfadd mm6, mm0 */
    guest_trap(c, 0x006acacau, "unsupported: pfsub mm2, mm5"); /* pfsub mm2, mm5 */
    guest_trap(c, 0x006acaceu, "unsupported: pfadd mm2, qword ptr [0x1002f1e8]"); /* pfadd mm2, qword ptr [0x1002f1e8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm7 */
    guest_trap(c, 0x006acaf1u, "unsupported: pfmul mm7, qword ptr [eax]"); /* pfmul mm7, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, mm1 */
    guest_trap(c, 0x006acaf8u, "unsupported: pfmul mm1, qword ptr [ecx]"); /* pfmul mm1, qword ptr [ecx] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [eax + 8] */
    guest_trap(c, 0x006acb00u, "unsupported: pfmul mm5, mm4"); /* pfmul mm5, mm4 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006acb08u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; memcpy(&v_, &c->mm[6], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm6 */
    guest_trap(c, 0x006acb17u, "unsupported: pfmul mm6, qword ptr [edx]"); /* pfmul mm6, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    guest_trap(c, 0x006acb1eu, "unsupported: pfadd mm1, mm7"); /* pfadd mm1, mm7 */
    guest_trap(c, 0x006acb22u, "unsupported: pfadd mm0, mm5"); /* pfadd mm0, mm5 */
    guest_trap(c, 0x006acb26u, "unsupported: pfmul mm2, qword ptr [ecx]"); /* pfmul mm2, qword ptr [ecx] */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [edx + 8] */
    guest_trap(c, 0x006acb2eu, "unsupported: pfmul mm4, mm7"); /* pfmul mm4, mm7 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [ecx + 8] */
    guest_trap(c, 0x006acb36u, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    guest_trap(c, 0x006acb3au, "unsupported: pfadd mm2, mm6"); /* pfadd mm2, mm6 */
    guest_trap(c, 0x006acb3eu, "unsupported: pfadd mm3, mm4"); /* pfadd mm3, mm4 */
    guest_trap(c, 0x006acb42u, "unsupported: pfadd mm1, mm2"); /* pfadd mm1, mm2 */
    guest_trap(c, 0x006acb46u, "unsupported: pfadd mm0, mm3"); /* pfadd mm0, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm1 */
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm0 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006acb56(CPU *c) { /* PTR_006acb56 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    guest_trap(c, 0x006acb65u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, HP((uint32_t)(0x6bf160u)), 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, dword ptr [0x1002f160] */
    guest_trap(c, 0x006acb70u, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm1 */
    guest_trap(c, 0x006acb77u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm7 */
    guest_trap(c, 0x006acb7eu, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm3 */
    guest_trap(c, 0x006acb8bu, "unsupported: pfmul mm0, qword ptr [0x1002f170]"); /* pfmul mm0, qword ptr [0x1002f170] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, HP((uint32_t)(0x6bf180u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[3], a_, 8); } /* pxor mm3, qword ptr [0x1002f180] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm7 */
    guest_trap(c, 0x006acba3u, "unsupported: pfadd mm1, mm3"); /* pfadd mm1, mm3 */
    guest_trap(c, 0x006acba7u, "unsupported: pfsub mm1, mm0"); /* pfsub mm1, mm0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    guest_trap(c, 0x006acbafu, "unsupported: pfsub mm0, mm5"); /* pfsub mm0, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [edx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    guest_trap(c, 0x006acbcdu, "unsupported: pfmul mm1, qword ptr [edx]"); /* pfmul mm1, qword ptr [edx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006acbd7u, "unsupported: pfmul mm0, qword ptr [ecx]"); /* pfmul mm0, qword ptr [ecx] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006acbdeu, "unsupported: pfmul mm2, qword ptr [eax]"); /* pfmul mm2, qword ptr [eax] */
    guest_trap(c, 0x006acbe2u, "unsupported: pfmul mm4, mm7"); /* pfmul mm4, mm7 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [ecx + 8] */
    guest_trap(c, 0x006acbeeu, "unsupported: pfmul mm5, mm7"); /* pfmul mm5, mm7 */
    guest_trap(c, 0x006acbf2u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [eax + 8] */
    guest_trap(c, 0x006acbfau, "unsupported: pfmul mm6, mm7"); /* pfmul mm6, mm7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006acc02u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm3 */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [edx + 8] */
    guest_trap(c, 0x006acc0du, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006acc11u, "unsupported: pfmul mm3, qword ptr [edx]"); /* pfmul mm3, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1c8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [0x1002f1c8] */
    guest_trap(c, 0x006acc1cu, "unsupported: pfadd mm0, mm3"); /* pfadd mm0, mm3 */
    guest_trap(c, 0x006acc20u, "unsupported: pfmul mm7, mm5"); /* pfmul mm7, mm5 */
    guest_trap(c, 0x006acc24u, "unsupported: pfadd mm4, mm6"); /* pfadd mm4, mm6 */
    guest_trap(c, 0x006acc28u, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    guest_trap(c, 0x006acc2cu, "unsupported: pfadd mm4, mm7"); /* pfadd mm4, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    guest_trap(c, 0x006acc33u, "unsupported: pfmul mm4, mm1"); /* pfmul mm4, mm1 */
    { uint32_t v_; memcpy(&v_, &c->mm[4], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm4 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006acc40(CPU *c) { /* FUN_1001cc40 */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [eax + 8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    guest_trap(c, 0x006acc64u, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    guest_trap(c, 0x006acc6bu, "unsupported: pfmul mm1, qword ptr [edx + 0x10]"); /* pfmul mm1, qword ptr [edx + 0x10] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm2 */
    guest_trap(c, 0x006acc73u, "unsupported: pfmul mm2, qword ptr [edx + 0x20]"); /* pfmul mm2, qword ptr [edx + 0x20] */
    guest_trap(c, 0x006acc78u, "unsupported: pfadd mm0, qword ptr [edx + 0x30]"); /* pfadd mm0, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006acc7du, "unsupported: pfmul mm3, qword ptr [edx + 8]"); /* pfmul mm3, qword ptr [edx + 8] */
    guest_trap(c, 0x006acc82u, "unsupported: pfadd mm1, mm2"); /* pfadd mm1, mm2 */
    guest_trap(c, 0x006acc86u, "unsupported: pfmul mm4, qword ptr [edx + 0x18]"); /* pfmul mm4, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006acc8bu, "unsupported: pfmul mm5, qword ptr [edx + 0x28]"); /* pfmul mm5, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006acc90u, "unsupported: pfadd mm3, qword ptr [edx + 0x38]"); /* pfadd mm3, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006acc95u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006acc99u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006acc9du, "unsupported: pfadd mm3, mm4"); /* pfadd mm3, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006acca7u, "unsupported: pfrcp mm4, mm5"); /* pfrcp mm4, mm5 */
    guest_trap(c, 0x006accabu, "unsupported: pfrcpit1 mm5, mm4"); /* pfrcpit1 mm5, mm4 */
    guest_trap(c, 0x006accafu, "unsupported: pfrcpit2 mm5, mm4"); /* pfrcpit2 mm5, mm4 */
    guest_trap(c, 0x006accb3u, "unsupported: pfmul mm0, mm5"); /* pfmul mm0, mm5 */
    guest_trap(c, 0x006accb7u, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->ecx), v_); } /* movq qword ptr [ecx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->ecx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [ecx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006acccb(CPU *c) { /* FUN_1001cccb */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [ecx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [edx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x10u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [edx + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x20u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [edx + 0x20] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    guest_trap(c, 0x006accf5u, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm2 */
    guest_trap(c, 0x006accfcu, "unsupported: pfmul mm0, qword ptr [edx + 8]"); /* pfmul mm0, qword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x30u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006acd05u, "unsupported: pfmul mm5, mm2"); /* pfmul mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006acd0cu, "unsupported: pfmul mm2, qword ptr [edx + 0x18]"); /* pfmul mm2, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006acd11u, "unsupported: pfadd mm5, mm4"); /* pfadd mm5, mm4 */
    guest_trap(c, 0x006acd15u, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006acd19u, "unsupported: pfadd mm2, mm0"); /* pfadd mm2, mm0 */
    guest_trap(c, 0x006acd1du, "unsupported: pfmul mm1, qword ptr [edx + 0x28]"); /* pfmul mm1, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006acd22u, "unsupported: pfadd mm6, mm5"); /* pfadd mm6, mm5 */
    guest_trap(c, 0x006acd26u, "unsupported: pfmul mm7, mm3"); /* pfmul mm7, mm3 */
    guest_trap(c, 0x006acd2au, "unsupported: pfadd mm2, mm1"); /* pfadd mm2, mm1 */
    guest_trap(c, 0x006acd2eu, "unsupported: pfmul mm3, qword ptr [edx + 0x38]"); /* pfmul mm3, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006acd33u, "unsupported: pfadd mm7, mm6"); /* pfadd mm7, mm6 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x10u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx + 0x10] */
    guest_trap(c, 0x006acd3bu, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x18u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [ecx + 0x18] */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm7 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x10u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [edx + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x20u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [edx + 0x20] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    guest_trap(c, 0x006acd61u, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm2 */
    guest_trap(c, 0x006acd68u, "unsupported: pfmul mm0, qword ptr [edx + 8]"); /* pfmul mm0, qword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x30u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006acd71u, "unsupported: pfmul mm5, mm2"); /* pfmul mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006acd78u, "unsupported: pfmul mm2, qword ptr [edx + 0x18]"); /* pfmul mm2, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006acd7du, "unsupported: pfadd mm5, mm4"); /* pfadd mm5, mm4 */
    guest_trap(c, 0x006acd81u, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006acd85u, "unsupported: pfadd mm2, mm0"); /* pfadd mm2, mm0 */
    guest_trap(c, 0x006acd89u, "unsupported: pfmul mm1, qword ptr [edx + 0x28]"); /* pfmul mm1, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006acd8eu, "unsupported: pfadd mm6, mm5"); /* pfadd mm6, mm5 */
    guest_trap(c, 0x006acd92u, "unsupported: pfmul mm7, mm3"); /* pfmul mm7, mm3 */
    guest_trap(c, 0x006acd96u, "unsupported: pfadd mm2, mm1"); /* pfadd mm2, mm1 */
    guest_trap(c, 0x006acd9au, "unsupported: pfmul mm3, qword ptr [edx + 0x38]"); /* pfmul mm3, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006acd9fu, "unsupported: pfadd mm7, mm6"); /* pfadd mm7, mm6 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x20u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx + 0x20] */
    guest_trap(c, 0x006acda7u, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x28u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [ecx + 0x28] */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); W64((uint32_t)(c->eax + 0x10u), v_); } /* movq qword ptr [eax + 0x10], mm7 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax + 0x18u), v_); } /* movq qword ptr [eax + 0x18], mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x10u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [edx + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x20u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [edx + 0x20] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    guest_trap(c, 0x006acdceu, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm2 */
    guest_trap(c, 0x006acdd5u, "unsupported: pfmul mm0, qword ptr [edx + 8]"); /* pfmul mm0, qword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x30u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006acddeu, "unsupported: pfmul mm5, mm2"); /* pfmul mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006acde5u, "unsupported: pfmul mm2, qword ptr [edx + 0x18]"); /* pfmul mm2, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006acdeau, "unsupported: pfadd mm5, mm4"); /* pfadd mm5, mm4 */
    guest_trap(c, 0x006acdeeu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006acdf2u, "unsupported: pfadd mm2, mm0"); /* pfadd mm2, mm0 */
    guest_trap(c, 0x006acdf6u, "unsupported: pfmul mm1, qword ptr [edx + 0x28]"); /* pfmul mm1, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006acdfbu, "unsupported: pfadd mm6, mm5"); /* pfadd mm6, mm5 */
    guest_trap(c, 0x006acdffu, "unsupported: pfmul mm7, mm3"); /* pfmul mm7, mm3 */
    guest_trap(c, 0x006ace03u, "unsupported: pfadd mm2, mm1"); /* pfadd mm2, mm1 */
    guest_trap(c, 0x006ace07u, "unsupported: pfmul mm3, qword ptr [edx + 0x38]"); /* pfmul mm3, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006ace0cu, "unsupported: pfadd mm7, mm6"); /* pfadd mm7, mm6 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x30u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx + 0x30] */
    guest_trap(c, 0x006ace14u, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x38u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [ecx + 0x38] */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); W64((uint32_t)(c->eax + 0x20u), v_); } /* movq qword ptr [eax + 0x20], mm7 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax + 0x28u), v_); } /* movq qword ptr [eax + 0x28], mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x10u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [edx + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x20u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [edx + 0x20] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    guest_trap(c, 0x006ace3bu, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm2 */
    guest_trap(c, 0x006ace42u, "unsupported: pfmul mm0, qword ptr [edx + 8]"); /* pfmul mm0, qword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x30u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006ace4bu, "unsupported: pfmul mm5, mm2"); /* pfmul mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ace52u, "unsupported: pfmul mm2, qword ptr [edx + 0x18]"); /* pfmul mm2, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006ace57u, "unsupported: pfadd mm5, mm4"); /* pfadd mm5, mm4 */
    guest_trap(c, 0x006ace5bu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006ace5fu, "unsupported: pfadd mm2, mm0"); /* pfadd mm2, mm0 */
    guest_trap(c, 0x006ace63u, "unsupported: pfmul mm1, qword ptr [edx + 0x28]"); /* pfmul mm1, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006ace68u, "unsupported: pfadd mm6, mm5"); /* pfadd mm6, mm5 */
    guest_trap(c, 0x006ace6cu, "unsupported: pfmul mm7, mm3"); /* pfmul mm7, mm3 */
    guest_trap(c, 0x006ace70u, "unsupported: pfadd mm2, mm1"); /* pfadd mm2, mm1 */
    guest_trap(c, 0x006ace74u, "unsupported: pfmul mm3, qword ptr [edx + 0x38]"); /* pfmul mm3, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006ace79u, "unsupported: pfadd mm7, mm6"); /* pfadd mm7, mm6 */
    guest_trap(c, 0x006ace7du, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); W64((uint32_t)(c->eax + 0x30u), v_); } /* movq qword ptr [eax + 0x30], mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax + 0x38u), v_); } /* movq qword ptr [eax + 0x38], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006ace92(CPU *c) { /* PTR_006ace92 */
    PREEMPT_POLL(c);
    { f_006acc40(c); return; } /* jmp 0x6acc40 */
}

void f_006ace97(CPU *c) { /* FUN_1001ce97 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x40u)); /* sub esp, 0x40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ebx, dword ptr [ebp + 0x14] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edi, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    c->esi = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea esi, [ebp - 0x40] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    if ((!c->cf && !c->zf)) goto L_006acf87; /* ja 0x6acf87 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6acfffu)); switch (t_) { case 0x006aced9u: goto L_006aced9; case 0x006acf2bu: goto L_006acf2b; case 0x006acf2fu: goto L_006acf2f; case 0x006acf33u: goto L_006acf33; case 0x006acf44u: goto L_006acf44; case 0x006acf48u: goto L_006acf48; case 0x006acf59u: goto L_006acf59; case 0x006acf6au: goto L_006acf6a; default: jump_indirect(c, t_, 0x006aced2u); return; } } /* jmp dword ptr [eax*4 + 0x1001cfff] */
L_006aced9:;
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 8] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0xc] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x10] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x14] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x1c] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x20] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x24] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x28] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x30] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x34] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffc8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x38] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffc4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x3c] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 4] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x18] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x2c] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffc0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x40] */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf2b:;
    c->esi = (uint32_t)(c->ebx); /* mov esi, ebx */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf2f:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf33:;
    ; /* femms  */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006acf40u); f_006acccb(c); /* call 0x6acccb */
    ; /* femms  */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf44:;
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf48:;
    ; /* femms  */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006acf55u); f_006acccb(c); /* call 0x6acccb */
    ; /* femms  */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf59:;
    ; /* femms  */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006acf66u); f_006acccb(c); /* call 0x6acccb */
    ; /* femms  */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf6a:;
    ; /* femms  */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006acf77u); f_006acccb(c); /* call 0x6acccb */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006acf85u); f_006acccb(c); /* call 0x6acccb */
    ; /* femms  */
L_006acf87:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006acf93u); f_006acc40(c); /* call 0x6acc40 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x10], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006acff8; /* je 0x6acff8 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, dword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [ecx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [ecx + 0x10] */
    guest_trap(c, 0x006acfbdu, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    guest_trap(c, 0x006acfc1u, "unsupported: pi2fd mm3, mm3"); /* pi2fd mm3, mm3 */
    guest_trap(c, 0x006acfc5u, "unsupported: pfadd mm0, qword ptr [0x1002f1e8]"); /* pfadd mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006acfcdu, "unsupported: pfmul mm3, qword ptr [0x1002f1f0]"); /* pfmul mm3, qword ptr [0x1002f1f0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006acfdbu, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006acfdfu, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    guest_trap(c, 0x006acfe3u, "unsupported: pfmul mm1, mm5"); /* pfmul mm1, mm5 */
    guest_trap(c, 0x006acfe7u, "unsupported: pfadd mm1, mm4"); /* pfadd mm1, mm4 */
    guest_trap(c, 0x006acfebu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[1], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm1 */
    ; /* femms  */
L_006acff8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006aced9(CPU *c) { /* PTR_006aced9 */
    PREEMPT_POLL(c);
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 8] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0xc] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x10] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x14] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x1c] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x20] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x24] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x28] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x30] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x34] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffc8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x38] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffc4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x3c] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 4] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x18] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x2c] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffc0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x40] */
    goto L_006acf87; /* jmp 0x6acf87 */
L_006acf87:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006acf93u); f_006acc40(c); /* call 0x6acc40 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x10], 0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006acff8; /* je 0x6acff8 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, dword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [ecx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [ecx + 0x10] */
    guest_trap(c, 0x006acfbdu, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    guest_trap(c, 0x006acfc1u, "unsupported: pi2fd mm3, mm3"); /* pi2fd mm3, mm3 */
    guest_trap(c, 0x006acfc5u, "unsupported: pfadd mm0, qword ptr [0x1002f1e8]"); /* pfadd mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006acfcdu, "unsupported: pfmul mm3, qword ptr [0x1002f1f0]"); /* pfmul mm3, qword ptr [0x1002f1f0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006acfdbu, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006acfdfu, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    guest_trap(c, 0x006acfe3u, "unsupported: pfmul mm1, mm5"); /* pfmul mm1, mm5 */
    guest_trap(c, 0x006acfe7u, "unsupported: pfadd mm1, mm4"); /* pfadd mm1, mm4 */
    guest_trap(c, 0x006acfebu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[1], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm1 */
    ; /* femms  */
L_006acff8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad01f(CPU *c) { /* PTR_006ad01f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x40u)); /* sub esp, 0x40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ebx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edi, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    if ((!c->cf && !c->zf)) goto L_006ad176; /* ja 0x6ad176 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6ad225u)); switch (t_) { case 0x006ad060u: goto L_006ad060; case 0x006ad0b5u: goto L_006ad0b5; case 0x006ad0c9u: goto L_006ad0c9; case 0x006ad0ddu: goto L_006ad0dd; case 0x006ad0fcu: goto L_006ad0fc; case 0x006ad10du: goto L_006ad10d; case 0x006ad12cu: goto L_006ad12c; case 0x006ad14bu: goto L_006ad14b; default: jump_indirect(c, t_, 0x006ad059u); return; } } /* jmp dword ptr [eax*4 + 0x1001d225] */
L_006ad060:;
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 8] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0xc] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xfffffff0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x10] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffecu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x14] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffe4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x1c] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffe0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x20] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffdcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x24] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffd8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x28] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffd0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x30] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffccu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x34] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffc8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x38] */
    FPUSH(c, 0.0); /* fldz  */
    WF32((uint32_t)(c->ebp + 0xffffffc4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x3c] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xfffffffcu), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 4] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffe8u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x18] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffd4u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x2c] */
    FPUSH(c, 1.0); /* fld1  */
    WF32((uint32_t)(c->ebp + 0xffffffc0u), (float)ST(0)); FPOP(c); /* fstp dword ptr [ebp - 0x40] */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad0b5:;
    ; /* femms  */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad0c2u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad0c9:;
    ; /* femms  */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad0d6u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad0dd:;
    ; /* femms  */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad0eau); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad0f8u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad0fc:;
    ; /* femms  */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad109u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad10d:;
    ; /* femms  */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad11au); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad128u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad12c:;
    ; /* femms  */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad139u); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad147u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
    goto L_006ad176; /* jmp 0x6ad176 */
L_006ad14b:;
    ; /* femms  */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad158u); f_006acccb(c); /* call 0x6acccb */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad166u); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad174u); f_006ac58a(c); /* call 0x6ac58a */
    ; /* femms  */
L_006ad176:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad20f; /* je 0x6ad20f */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad197u, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad19fu, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad1a9u, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad1adu, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad1b1u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad1b8u, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad1c0u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad1c4u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad1cfu, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad1d6u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad1deu, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad1e2u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad1edu, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad1f1u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad1f5u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad1f9u, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad216; /* jmp 0x6ad216 */
L_006ad20f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad216:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad21eu); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad225(CPU *c) { /* PTR_006ad225 */
    PREEMPT_POLL(c);
    { uint32_t s_ = c->esp; PUSH32(c, c->eax); PUSH32(c, c->ecx); PUSH32(c, c->edx); PUSH32(c, c->ebx); PUSH32(c, s_); PUSH32(c, c->ebp); PUSH32(c, c->esi); PUSH32(c, c->edi); } /* pushal  */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(rol8(c, R8(a_), 1))); } /* rol byte ptr [ecx], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xc91001d0u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)(c->edx >> 8))))); } /* adc byte ptr [ebp - 0x36effe30], dh */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(rol8(c, R8(a_), 1))); } /* rol byte ptr [ecx], 1 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(adc8(c, ((uint8_t)(c->ecx >> 8)), ((uint8_t)c->ebx))) << 8); /* adc ch, bl */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(rol8(c, R8(a_), 1))); } /* rol byte ptr [ecx], 1 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(adc8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)(c->ebx >> 8)))) << 8); /* adc ah, bh */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(rol8(c, R8(a_), 1))); } /* rol byte ptr [ecx], 1 */
    { uint32_t a_ = (uint32_t)(0x2c1001d1u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ecx)))); } /* adc byte ptr [0x2c1001d1], cl */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(rol32(c, R32(a_), 1))); } /* rol dword ptr [ecx], 1 */
    { uint32_t a_ = (uint32_t)(c->ebx + 0xffffffd1u); W8(a_, (uint8_t)(adc8(c, R8(a_), ((uint8_t)c->ecx)))); } /* adc byte ptr [ebx - 0x2f], cl */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), c->edx))); } /* add dword ptr [eax], edx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x40u)); /* sub esp, 0x40 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ecx, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ebx, dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, c->ecx, c->esi); /* cmp ecx, esi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov edi, dword ptr [ebp + 0x18] */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    (void)sub32(c, c->ebx, c->esi); /* cmp ebx, esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne dl */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edx))); /* or eax, edx */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    if ((!c->cf && !c->zf)) goto L_006ad2c9; /* ja 0x6ad2c9 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6ad378u)); switch (t_) { case 0x006ad282u: goto L_006ad282; case 0x006ad28eu: goto L_006ad28e; case 0x006ad291u: goto L_006ad291; case 0x006ad294u: goto L_006ad294; case 0x006ad298u: goto L_006ad298; case 0x006ad29bu: goto L_006ad29b; case 0x006ad29eu: goto L_006ad29e; case 0x006ad2a2u: goto L_006ad2a2; default: jump_indirect(c, t_, 0x006ad27bu); return; } } /* jmp dword ptr [eax*4 + 0x1001d378] */
L_006ad282:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad28bu); f_006a9212(c); /* call 0x6a9212 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006ad2c9; /* jmp 0x6ad2c9 */
L_006ad28e:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    goto L_006ad2bf; /* jmp 0x6ad2bf */
L_006ad291:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_006ad2bf; /* jmp 0x6ad2bf */
L_006ad294:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_006ad2b2; /* jmp 0x6ad2b2 */
L_006ad298:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    goto L_006ad2bf; /* jmp 0x6ad2bf */
L_006ad29b:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    goto L_006ad29f; /* jmp 0x6ad29f */
L_006ad29e:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_006ad29f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    goto L_006ad2b2; /* jmp 0x6ad2b2 */
L_006ad2a2:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2adu); f_006acccb(c); /* call 0x6acccb */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_006ad2b2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2bbu); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_006ad2bf:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
L_006ad2c9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad282(CPU *c) { /* PTR_006ad282 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad28bu); f_006a9212(c); /* call 0x6a9212 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006ad2c9; /* jmp 0x6ad2c9 */
L_006ad2c9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad28e(CPU *c) { /* PTR_006ad28e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    goto L_006ad2bf; /* jmp 0x6ad2bf */
L_006ad2bf:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad291(CPU *c) { /* PTR_006ad291 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_006ad2bf; /* jmp 0x6ad2bf */
L_006ad2bf:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad294(CPU *c) { /* PTR_006ad294 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_006ad2b2; /* jmp 0x6ad2b2 */
L_006ad2b2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2bbu); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad298(CPU *c) { /* PTR_006ad298 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    goto L_006ad2bf; /* jmp 0x6ad2bf */
L_006ad2bf:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad29b(CPU *c) { /* PTR_006ad29b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    goto L_006ad29f; /* jmp 0x6ad29f */
L_006ad29f:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    goto L_006ad2b2; /* jmp 0x6ad2b2 */
L_006ad2b2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2bbu); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad29e(CPU *c) { /* PTR_006ad29e */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    goto L_006ad2b2; /* jmp 0x6ad2b2 */
L_006ad2b2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2bbu); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad2a2(CPU *c) { /* PTR_006ad2a2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2adu); f_006acccb(c); /* call 0x6acccb */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2bbu); f_006acccb(c); /* call 0x6acccb */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006ad2c9u); f_006abeb0(c); /* call 0x6abeb0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->esi); /* cmp dword ptr [ebp + 0x10], esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006ad362; /* je 0x6ad362 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edx, dword ptr [ebp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [eax + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad2eau, "unsupported: pi2fd mm1, mm1"); /* pi2fd mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x10u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax + 0x10] */
    guest_trap(c, 0x006ad2f2u, "unsupported: pi2fd mm2, mm2"); /* pi2fd mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad2fcu, "unsupported: pfrcp mm5, mm2"); /* pfrcp mm5, mm2 */
    guest_trap(c, 0x006ad300u, "unsupported: pfrcp mm3, mm3"); /* pfrcp mm3, mm3 */
    guest_trap(c, 0x006ad304u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm3 */
    guest_trap(c, 0x006ad30bu, "unsupported: pfrcpit1 mm2, mm5"); /* pfrcpit1 mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ad313u, "unsupported: pfrcpit2 mm2, mm5"); /* pfrcpit2 mm2, mm5 */
    guest_trap(c, 0x006ad317u, "unsupported: pfmul mm2, qword ptr [0x1002f1f8]"); /* pfmul mm2, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad322u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm5 */
    guest_trap(c, 0x006ad329u, "unsupported: pfsub mm0, qword ptr [0x1002f1e8]"); /* pfsub mm0, qword ptr [0x1002f1e8] */
    guest_trap(c, 0x006ad331u, "unsupported: pfsub mm5, mm4"); /* pfsub mm5, mm4 */
    guest_trap(c, 0x006ad335u, "unsupported: pfrcp mm6, mm5"); /* pfrcp mm6, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, HP((uint32_t)(0x6bf1e0u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, qword ptr [0x1002f1e0] */
    guest_trap(c, 0x006ad340u, "unsupported: pfrcpit1 mm5, mm6"); /* pfrcpit1 mm5, mm6 */
    guest_trap(c, 0x006ad344u, "unsupported: pfrcpit2 mm5, mm6"); /* pfrcpit2 mm5, mm6 */
    guest_trap(c, 0x006ad348u, "unsupported: pfsub mm3, mm4"); /* pfsub mm3, mm4 */
    guest_trap(c, 0x006ad34cu, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->edx), v_); } /* movq qword ptr [edx], mm0 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); W32((uint32_t)(c->edx + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [edx + 8], mm3 */
    ; /* femms  */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006ad369; /* jmp 0x6ad369 */
L_006ad362:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc0u)); /* lea eax, [ebp - 0x40] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
L_006ad369:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006ad371u); f_006acc40(c); /* call 0x6acc40 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad3ed(CPU *c) { /* PTR_006ad3ed */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    guest_trap(c, 0x006ad40au, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    guest_trap(c, 0x006ad411u, "unsupported: pfmul mm1, qword ptr [edx + 0x10]"); /* pfmul mm1, qword ptr [edx + 0x10] */
    guest_trap(c, 0x006ad416u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->ecx), v_); } /* movq qword ptr [ecx], mm0 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006ad426(CPU *c) { /* PTR_006ad426 */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    guest_trap(c, 0x006ad443u, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    guest_trap(c, 0x006ad44au, "unsupported: pfmul mm1, qword ptr [edx + 0x10]"); /* pfmul mm1, qword ptr [edx + 0x10] */
    guest_trap(c, 0x006ad44fu, "unsupported: pfadd mm0, qword ptr [edx + 0x30]"); /* pfadd mm0, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006ad454u, "unsupported: pfmul mm3, qword ptr [edx + 8]"); /* pfmul mm3, qword ptr [edx + 8] */
    guest_trap(c, 0x006ad459u, "unsupported: pfmul mm4, qword ptr [edx + 0x18]"); /* pfmul mm4, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006ad45eu, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006ad462u, "unsupported: pfadd mm3, qword ptr [edx + 0x38]"); /* pfadd mm3, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006ad467u, "unsupported: pfadd mm3, mm4"); /* pfadd mm3, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad46eu, "unsupported: pfrcp mm4, mm3"); /* pfrcp mm4, mm3 */
    guest_trap(c, 0x006ad472u, "unsupported: pfrcpit1 mm3, mm4"); /* pfrcpit1 mm3, mm4 */
    guest_trap(c, 0x006ad476u, "unsupported: pfrcpit2 mm3, mm4"); /* pfrcpit2 mm3, mm4 */
    guest_trap(c, 0x006ad47au, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->ecx), v_); } /* movq qword ptr [ecx], mm0 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006ad48a(CPU *c) { /* PTR_006ad48a */
    PREEMPT_POLL(c);
    ; /* femms  */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [esp + 0x18] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ad494u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    guest_trap(c, 0x006ad49bu, "unsupported: pfmul mm2, mm0"); /* pfmul mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1f8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm2 */
    guest_trap(c, 0x006ad4acu, "unsupported: pfsub mm7, mm1"); /* pfsub mm7, mm1 */
    guest_trap(c, 0x006ad4b0u, "unsupported: pfmul mm4, mm3"); /* pfmul mm4, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006ad4b7u, "unsupported: pfmul mm1, qword ptr [0x1002f200]"); /* pfmul mm1, qword ptr [0x1002f200] */
    guest_trap(c, 0x006ad4bfu, "unsupported: pfmul mm2, mm3"); /* pfmul mm2, mm3 */
    guest_trap(c, 0x006ad4c3u, "unsupported: pfsub mm6, mm4"); /* pfsub mm6, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006ad4cau, "unsupported: pfsub mm1, mm2"); /* pfsub mm1, mm2 */
    guest_trap(c, 0x006ad4ceu, "unsupported: pfadd mm6, mm0"); /* pfadd mm6, mm0 */
    guest_trap(c, 0x006ad4d2u, "unsupported: pfsub mm2, mm5"); /* pfsub mm2, mm5 */
    guest_trap(c, 0x006ad4d6u, "unsupported: pfadd mm2, qword ptr [0x1002f1e8]"); /* pfadd mm2, qword ptr [0x1002f1e8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    guest_trap(c, 0x006ad4f6u, "unsupported: pfmul mm2, qword ptr [ecx]"); /* pfmul mm2, qword ptr [ecx] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    guest_trap(c, 0x006ad4feu, "unsupported: pfmul mm6, qword ptr [edx]"); /* pfmul mm6, qword ptr [edx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    guest_trap(c, 0x006ad506u, "unsupported: pfadd mm2, mm6"); /* pfadd mm2, mm6 */
    guest_trap(c, 0x006ad50au, "unsupported: pfmul mm1, qword ptr [ecx]"); /* pfmul mm1, qword ptr [ecx] */
    guest_trap(c, 0x006ad50eu, "unsupported: pfmul mm7, qword ptr [edx]"); /* pfmul mm7, qword ptr [edx] */
    guest_trap(c, 0x006ad512u, "unsupported: pfadd mm1, mm7"); /* pfadd mm1, mm7 */
    guest_trap(c, 0x006ad516u, "unsupported: pfadd mm2, mm1"); /* pfadd mm2, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm2 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad522(CPU *c) { /* PTR_006ad522 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [esp + 0x14] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [esp + 0x18] */
    guest_trap(c, 0x006ad544u, "unsupported: pfsub mm0, mm4"); /* pfsub mm0, mm4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    guest_trap(c, 0x006ad54fu, "unsupported: pfmul mm0, mm6"); /* pfmul mm0, mm6 */
    guest_trap(c, 0x006ad553u, "unsupported: pfsub mm2, mm4"); /* pfsub mm2, mm4 */
    guest_trap(c, 0x006ad557u, "unsupported: pfadd mm4, mm0"); /* pfadd mm4, mm0 */
    guest_trap(c, 0x006ad55bu, "unsupported: pfmul mm2, mm7"); /* pfmul mm2, mm7 */
    guest_trap(c, 0x006ad55fu, "unsupported: pfadd mm4, mm2"); /* pfadd mm4, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm4 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad56b(CPU *c) { /* PTR_006ad56b */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ad575u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006ad57du, "unsupported: pfacc mm0, mm0"); /* pfacc mm0, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm0 */
    guest_trap(c, 0x006ad584u, "unsupported: pfrsqrt mm4, mm0"); /* pfrsqrt mm4, mm0 */
    guest_trap(c, 0x006ad588u, "unsupported: pfcmpgt mm2, qword ptr [0x1002f1d0]"); /* pfcmpgt mm2, qword ptr [0x1002f1d0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm4 */
    guest_trap(c, 0x006ad593u, "unsupported: pfmul mm4, mm4"); /* pfmul mm4, mm4 */
    guest_trap(c, 0x006ad597u, "unsupported: pfrsqit1 mm4, mm0"); /* pfrsqit1 mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[2], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm2 */
    guest_trap(c, 0x006ad59eu, "unsupported: pfrcpit2 mm4, mm5"); /* pfrcpit2 mm4, mm5 */
    guest_trap(c, 0x006ad5a2u, "unsupported: pfmul mm1, mm4"); /* pfmul mm1, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm1 */
    ; /* femms  */
    c->esp += 12; return; /* ret 8 */
}

void f_006ad5ae(CPU *c) { /* PTR_006ad5ae */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [esp + 0x18] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    guest_trap(c, 0x006ad5b9u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, HP((uint32_t)(0x6bf160u)), 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, dword ptr [0x1002f160] */
    guest_trap(c, 0x006ad5c4u, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm1 */
    guest_trap(c, 0x006ad5cbu, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm7 */
    guest_trap(c, 0x006ad5d6u, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm3 */
    guest_trap(c, 0x006ad5e3u, "unsupported: pfmul mm0, qword ptr [0x1002f170]"); /* pfmul mm0, qword ptr [0x1002f170] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, HP((uint32_t)(0x6bf180u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[3], a_, 8); } /* pxor mm3, qword ptr [0x1002f180] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm7 */
    guest_trap(c, 0x006ad5fbu, "unsupported: pfadd mm1, mm3"); /* pfadd mm1, mm3 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    guest_trap(c, 0x006ad603u, "unsupported: pfsub mm1, mm0"); /* pfsub mm1, mm0 */
    guest_trap(c, 0x006ad607u, "unsupported: pfsub mm0, mm5"); /* pfsub mm0, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    guest_trap(c, 0x006ad61eu, "unsupported: pfmul mm1, qword ptr [edx]"); /* pfmul mm1, qword ptr [edx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    guest_trap(c, 0x006ad625u, "unsupported: pfmul mm0, qword ptr [ecx]"); /* pfmul mm0, qword ptr [ecx] */
    guest_trap(c, 0x006ad629u, "unsupported: pfmul mm2, qword ptr [eax]"); /* pfmul mm2, qword ptr [eax] */
    guest_trap(c, 0x006ad62du, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    guest_trap(c, 0x006ad635u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006ad63du, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006ad641u, "unsupported: pfmul mm3, qword ptr [edx]"); /* pfmul mm3, qword ptr [edx] */
    guest_trap(c, 0x006ad645u, "unsupported: pfadd mm0, mm3"); /* pfadd mm0, mm3 */
    guest_trap(c, 0x006ad649u, "unsupported: pfmul mm0, qword ptr [0x1002f1c8]"); /* pfmul mm0, qword ptr [0x1002f1c8] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad659(CPU *c) { /* PTR_006ad659 */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    guest_trap(c, 0x006ad683u, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006ad68au, "unsupported: pfmul mm1, qword ptr [edx + 0x10]"); /* pfmul mm1, qword ptr [edx + 0x10] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006ad692u, "unsupported: pfmul mm2, qword ptr [edx + 0x20]"); /* pfmul mm2, qword ptr [edx + 0x20] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm3 */
    guest_trap(c, 0x006ad69au, "unsupported: pfmul mm3, qword ptr [edx + 0x30]"); /* pfmul mm3, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006ad69fu, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006ad6a3u, "unsupported: pfmul mm4, qword ptr [edx + 8]"); /* pfmul mm4, qword ptr [edx + 8] */
    guest_trap(c, 0x006ad6a8u, "unsupported: pfadd mm2, mm3"); /* pfadd mm2, mm3 */
    guest_trap(c, 0x006ad6acu, "unsupported: pfmul mm5, qword ptr [edx + 0x18]"); /* pfmul mm5, qword ptr [edx + 0x18] */
    guest_trap(c, 0x006ad6b1u, "unsupported: pfmul mm6, qword ptr [edx + 0x28]"); /* pfmul mm6, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006ad6b6u, "unsupported: pfmul mm7, qword ptr [edx + 0x38]"); /* pfmul mm7, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006ad6bbu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006ad6bfu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006ad6c3u, "unsupported: pfadd mm6, mm7"); /* pfadd mm6, mm7 */
    guest_trap(c, 0x006ad6c7u, "unsupported: pfadd mm4, mm6"); /* pfadd mm4, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm4 */
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->esp += 16; return; /* ret 0xc */
}

void f_006ad6db(CPU *c) { /* PTR_006ad6db */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    guest_trap(c, 0x006ad6eeu, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    guest_trap(c, 0x006ad6f2u, "unsupported: pfmul mm2, mm2"); /* pfmul mm2, mm2 */
    guest_trap(c, 0x006ad6f6u, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006ad6fau, "unsupported: pfacc mm0, mm0"); /* pfacc mm0, mm0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006ad705u, "unsupported: pfrsqrt mm4, mm0"); /* pfrsqrt mm4, mm0 */
    guest_trap(c, 0x006ad709u, "unsupported: pfcmpgt mm5, qword ptr [0x1002f1d0]"); /* pfcmpgt mm5, qword ptr [0x1002f1d0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm4 */
    guest_trap(c, 0x006ad714u, "unsupported: pfmul mm2, mm4"); /* pfmul mm2, mm4 */
    guest_trap(c, 0x006ad718u, "unsupported: pfrsqit1 mm0, mm2"); /* pfrsqit1 mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[3], a_, 8); } /* pand mm3, mm5 */
    guest_trap(c, 0x006ad722u, "unsupported: pfrcpit2 mm0, mm4"); /* pfrcpit2 mm0, mm4 */
    guest_trap(c, 0x006ad726u, "unsupported: pfmul mm1, mm0"); /* pfmul mm1, mm0 */
    guest_trap(c, 0x006ad72au, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm3 */
    ; /* femms  */
    c->esp += 12; return; /* ret 8 */
}

void f_006ad73a(CPU *c) { /* PTR_006ad73a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    ; /* femms  */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [edx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[4], a_, 8); } /* punpckhdq mm4, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[6], a_, 8); } /* punpckhdq mm6, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[7], a_, 8); } /* punpckhdq mm7, mm1 */
    guest_trap(c, 0x006ad779u, "unsupported: pfmul mm4, mm5"); /* pfmul mm4, mm5 */
    guest_trap(c, 0x006ad77du, "unsupported: pfmul mm6, mm7"); /* pfmul mm6, mm7 */
    guest_trap(c, 0x006ad781u, "unsupported: pfsub mm4, mm6"); /* pfsub mm4, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm1 */
    guest_trap(c, 0x006ad791u, "unsupported: pfmul mm5, mm6"); /* pfmul mm5, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[6], a_, 8); } /* punpckhdq mm6, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm0 */
    guest_trap(c, 0x006ad7a1u, "unsupported: pfmul mm6, mm7"); /* pfmul mm6, mm7 */
    guest_trap(c, 0x006ad7a5u, "unsupported: pfsub mm5, mm6"); /* pfsub mm5, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* punpckhdq mm2, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    guest_trap(c, 0x006ad7bbu, "unsupported: pfmul mm6, mm2"); /* pfmul mm6, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm1 */
    guest_trap(c, 0x006ad7c2u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    guest_trap(c, 0x006ad7c6u, "unsupported: pfsub mm6, mm0"); /* pfsub mm6, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ebx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ebx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ebx + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [ebx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1e0u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [0x1002f1e0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[2], a_, 8); } /* pxor mm2, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[0], a_, 8); } /* punpckhdq mm0, mm3 */
    guest_trap(c, 0x006ad7eau, "unsupported: pfmul mm2, mm0"); /* pfmul mm2, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[7], a_, 8); } /* punpckhdq mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm6 */
    guest_trap(c, 0x006ad803u, "unsupported: pfmul mm3, mm1"); /* pfmul mm3, mm1 */
    guest_trap(c, 0x006ad807u, "unsupported: pfmul mm7, mm1"); /* pfmul mm7, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[0], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[3], a_, 8); } /* pxor mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[0], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm0 */
    guest_trap(c, 0x006ad811u, "unsupported: pfacc mm3, mm7"); /* pfacc mm3, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ebx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ebx] */
    guest_trap(c, 0x006ad81bu, "unsupported: pfsub mm2, mm3"); /* pfsub mm2, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[4], a_, 8); } /* punpckhdq mm4, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[4], a_, 8); } /* pxor mm4, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm5 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 32u, 8, 8, 1); memcpy(&c->mm[7], a_, 8); } /* psrlq mm7, 0x20 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[2], a_, 8); } /* pxor mm2, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[6], a_, 8); } /* punpckhdq mm6, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[6], a_, 8); } /* pxor mm6, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm3 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 32u, 8, 8, 0); memcpy(&c->mm[7], a_, 8); } /* psllq mm7, 0x20 */
    guest_trap(c, 0x006ad848u, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    guest_trap(c, 0x006ad84cu, "unsupported: pfmul mm2, mm0"); /* pfmul mm2, mm0 */
    guest_trap(c, 0x006ad850u, "unsupported: pfmul mm1, mm6"); /* pfmul mm1, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[4], a_, 8); } /* pxor mm4, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[2], a_, 8); } /* pxor mm2, mm7 */
    guest_trap(c, 0x006ad85au, "unsupported: pfacc mm4, mm2"); /* pfacc mm4, mm2 */
    guest_trap(c, 0x006ad85eu, "unsupported: pfadd mm1, mm4"); /* pfadd mm1, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm1 */
    ; /* femms  */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006ad86c(CPU *c) { /* PTR_006ad86c */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [ecx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [eax + 8] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [esp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [esp + 0x18] */
    guest_trap(c, 0x006ad897u, "unsupported: pfsub mm0, mm4"); /* pfsub mm0, mm4 */
    guest_trap(c, 0x006ad89bu, "unsupported: pfsub mm1, mm5"); /* pfsub mm1, mm5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006ad8a3u, "unsupported: pfsub mm2, mm4"); /* pfsub mm2, mm4 */
    guest_trap(c, 0x006ad8a7u, "unsupported: pfsub mm3, mm5"); /* pfsub mm3, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    guest_trap(c, 0x006ad8b1u, "unsupported: pfmul mm0, mm6"); /* pfmul mm0, mm6 */
    guest_trap(c, 0x006ad8b5u, "unsupported: pfmul mm1, mm6"); /* pfmul mm1, mm6 */
    guest_trap(c, 0x006ad8b9u, "unsupported: pfmul mm2, mm7"); /* pfmul mm2, mm7 */
    guest_trap(c, 0x006ad8bdu, "unsupported: pfadd mm0, mm4"); /* pfadd mm0, mm4 */
    guest_trap(c, 0x006ad8c1u, "unsupported: pfmul mm3, mm7"); /* pfmul mm3, mm7 */
    guest_trap(c, 0x006ad8c5u, "unsupported: pfadd mm1, mm5"); /* pfadd mm1, mm5 */
    guest_trap(c, 0x006ad8c9u, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006ad8cdu, "unsupported: pfadd mm1, mm3"); /* pfadd mm1, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm1 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad8dd(CPU *c) { /* PTR_006ad8dd */
    PREEMPT_POLL(c);
    ; /* femms  */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [esp + 0x18] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ad8e7u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    guest_trap(c, 0x006ad8eeu, "unsupported: pfmul mm2, mm0"); /* pfmul mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1f8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x1002f1f8] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm2 */
    guest_trap(c, 0x006ad8ffu, "unsupported: pfsub mm7, mm1"); /* pfsub mm7, mm1 */
    guest_trap(c, 0x006ad903u, "unsupported: pfmul mm4, mm3"); /* pfmul mm4, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006ad90au, "unsupported: pfmul mm1, qword ptr [0x1002f200]"); /* pfmul mm1, qword ptr [0x1002f200] */
    guest_trap(c, 0x006ad912u, "unsupported: pfmul mm2, mm3"); /* pfmul mm2, mm3 */
    guest_trap(c, 0x006ad916u, "unsupported: pfsub mm6, mm4"); /* pfsub mm6, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006ad91du, "unsupported: pfsub mm1, mm2"); /* pfsub mm1, mm2 */
    guest_trap(c, 0x006ad921u, "unsupported: pfadd mm6, mm0"); /* pfadd mm6, mm0 */
    guest_trap(c, 0x006ad925u, "unsupported: pfsub mm2, mm5"); /* pfsub mm2, mm5 */
    guest_trap(c, 0x006ad929u, "unsupported: pfadd mm2, qword ptr [0x1002f1e8]"); /* pfadd mm2, qword ptr [0x1002f1e8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[6], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm7 */
    guest_trap(c, 0x006ad94cu, "unsupported: pfmul mm7, qword ptr [eax]"); /* pfmul mm7, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, mm1 */
    guest_trap(c, 0x006ad953u, "unsupported: pfmul mm1, qword ptr [ecx]"); /* pfmul mm1, qword ptr [ecx] */
    guest_trap(c, 0x006ad957u, "unsupported: pfmul mm5, qword ptr [eax + 8]"); /* pfmul mm5, qword ptr [eax + 8] */
    guest_trap(c, 0x006ad95cu, "unsupported: pfmul mm0, qword ptr [ecx + 8]"); /* pfmul mm0, qword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; memcpy(&v_, &c->mm[6], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm6 */
    guest_trap(c, 0x006ad96cu, "unsupported: pfmul mm6, qword ptr [edx]"); /* pfmul mm6, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    guest_trap(c, 0x006ad973u, "unsupported: pfmul mm2, qword ptr [ecx]"); /* pfmul mm2, qword ptr [ecx] */
    guest_trap(c, 0x006ad977u, "unsupported: pfmul mm4, qword ptr [edx + 8]"); /* pfmul mm4, qword ptr [edx + 8] */
    guest_trap(c, 0x006ad97cu, "unsupported: pfmul mm3, qword ptr [ecx + 8]"); /* pfmul mm3, qword ptr [ecx + 8] */
    guest_trap(c, 0x006ad981u, "unsupported: pfadd mm1, mm7"); /* pfadd mm1, mm7 */
    guest_trap(c, 0x006ad985u, "unsupported: pfadd mm0, mm5"); /* pfadd mm0, mm5 */
    guest_trap(c, 0x006ad989u, "unsupported: pfadd mm2, mm6"); /* pfadd mm2, mm6 */
    guest_trap(c, 0x006ad98du, "unsupported: pfadd mm3, mm4"); /* pfadd mm3, mm4 */
    guest_trap(c, 0x006ad991u, "unsupported: pfadd mm1, mm2"); /* pfadd mm1, mm2 */
    guest_trap(c, 0x006ad995u, "unsupported: pfadd mm0, mm3"); /* pfadd mm0, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm0 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ad9a5(CPU *c) { /* PTR_006ad9a5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [esp + 0x18] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    guest_trap(c, 0x006ad9b4u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, HP((uint32_t)(0x6bf160u)), 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, dword ptr [0x1002f160] */
    guest_trap(c, 0x006ad9bfu, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm1 */
    guest_trap(c, 0x006ad9c6u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm7 */
    guest_trap(c, 0x006ad9cdu, "unsupported: pfsub mm0, mm1"); /* pfsub mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[3], a_, 8); } /* punpckldq mm3, mm3 */
    guest_trap(c, 0x006ad9dau, "unsupported: pfmul mm0, qword ptr [0x1002f170]"); /* pfmul mm0, qword ptr [0x1002f170] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, HP((uint32_t)(0x6bf180u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[3], a_, 8); } /* pxor mm3, qword ptr [0x1002f180] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[5], a_, 8); } /* punpckhdq mm5, mm7 */
    guest_trap(c, 0x006ad9f2u, "unsupported: pfadd mm1, mm3"); /* pfadd mm1, mm3 */
    guest_trap(c, 0x006ad9f6u, "unsupported: pfsub mm1, mm0"); /* pfsub mm1, mm0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    guest_trap(c, 0x006ad9feu, "unsupported: pfsub mm0, mm5"); /* pfsub mm0, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm1 */
    guest_trap(c, 0x006ada18u, "unsupported: pfmul mm1, qword ptr [edx]"); /* pfmul mm1, qword ptr [edx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006ada22u, "unsupported: pfmul mm0, qword ptr [ecx]"); /* pfmul mm0, qword ptr [ecx] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006ada29u, "unsupported: pfmul mm2, qword ptr [eax]"); /* pfmul mm2, qword ptr [eax] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm3 */
    guest_trap(c, 0x006ada30u, "unsupported: pfmul mm4, qword ptr [edx + 8]"); /* pfmul mm4, qword ptr [edx + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edx, dword ptr [esp + 0x14] */
    guest_trap(c, 0x006ada39u, "unsupported: pfmul mm5, qword ptr [ecx + 8]"); /* pfmul mm5, qword ptr [ecx + 8] */
    guest_trap(c, 0x006ada3eu, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006ada42u, "unsupported: pfmul mm6, qword ptr [eax + 8]"); /* pfmul mm6, qword ptr [eax + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006ada4bu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006ada4fu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006ada53u, "unsupported: pfmul mm3, qword ptr [edx]"); /* pfmul mm3, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1c8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [0x1002f1c8] */
    guest_trap(c, 0x006ada5eu, "unsupported: pfadd mm0, mm3"); /* pfadd mm0, mm3 */
    guest_trap(c, 0x006ada62u, "unsupported: pfmul mm7, qword ptr [edx + 8]"); /* pfmul mm7, qword ptr [edx + 8] */
    guest_trap(c, 0x006ada67u, "unsupported: pfadd mm4, mm6"); /* pfadd mm4, mm6 */
    guest_trap(c, 0x006ada6bu, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    guest_trap(c, 0x006ada6fu, "unsupported: pfadd mm4, mm7"); /* pfadd mm4, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    guest_trap(c, 0x006ada76u, "unsupported: pfmul mm4, mm1"); /* pfmul mm4, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm4 */
    ; /* femms  */
    c->esp += 28; return; /* ret 0x18 */
}

void f_006ada83(CPU *c) { /* PTR_006ada83 */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, dword ptr [edx + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx] */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [ecx + 8] */
    guest_trap(c, 0x006ada9fu, "unsupported: pfmul mm2, mm0"); /* pfmul mm2, mm0 */
    guest_trap(c, 0x006adaa3u, "unsupported: pfmul mm3, mm1"); /* pfmul mm3, mm1 */
    guest_trap(c, 0x006adaa7u, "unsupported: pfacc mm2, mm2"); /* pfacc mm2, mm2 */
    guest_trap(c, 0x006adaabu, "unsupported: pfadd mm2, mm3"); /* pfadd mm2, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, HP((uint32_t)(0x6bf1d8u)), 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[2], a_, 8); } /* pxor mm2, qword ptr [0x1002f1d8] */
    { uint32_t v_; memcpy(&v_, &c->mm[1], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm1 */
    { uint32_t v_; memcpy(&v_, &c->mm[2], 4); W32((uint32_t)(c->eax + 0xcu), (uint32_t)(v_)); } /* movd dword ptr [eax + 0xc], mm2 */
    ; /* femms  */
    c->esp += 16; return; /* ret 0xc */
}

void f_006adac6(CPU *c) { /* PTR_006adac6 */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(0x6bf1e0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x1002f1e0] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, dword ptr [edx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [ecx + 8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, HP((uint32_t)(c->eax + 0x8u)), 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, dword ptr [eax + 8] */
    guest_trap(c, 0x006adaf3u, "unsupported: pfsub mm0, qword ptr [eax]"); /* pfsub mm0, qword ptr [eax] */
    guest_trap(c, 0x006adaf7u, "unsupported: pfsub mm1, mm6"); /* pfsub mm1, mm6 */
    guest_trap(c, 0x006adafbu, "unsupported: pfsub mm4, qword ptr [ecx]"); /* pfsub mm4, qword ptr [ecx] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm7 */
    guest_trap(c, 0x006adb02u, "unsupported: pfsub mm7, mm4"); /* pfsub mm7, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[0], a_, 8); } /* punpckhdq mm0, mm7 */
    guest_trap(c, 0x006adb0cu, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm5 */
    guest_trap(c, 0x006adb1cu, "unsupported: pfmul mm1, mm6"); /* pfmul mm1, mm6 */
    guest_trap(c, 0x006adb20u, "unsupported: pfacc mm0, mm1"); /* pfacc mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[7], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[4], a_, 8); } /* punpckldq mm4, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm4 */
    guest_trap(c, 0x006adb30u, "unsupported: pfmul mm1, mm5"); /* pfmul mm1, mm5 */
    guest_trap(c, 0x006adb34u, "unsupported: pfacc mm1, mm1"); /* pfacc mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm1 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 32u, 8, 8, 0); memcpy(&c->mm[7], a_, 8); } /* psllq mm7, 0x20 */
    guest_trap(c, 0x006adb42u, "unsupported: pfmul mm6, mm6"); /* pfmul mm6, mm6 */
    guest_trap(c, 0x006adb46u, "unsupported: pfmul mm7, mm7"); /* pfmul mm7, mm7 */
    guest_trap(c, 0x006adb4au, "unsupported: pfadd mm6, mm7"); /* pfadd mm6, mm7 */
    guest_trap(c, 0x006adb4eu, "unsupported: pfacc mm6, mm6"); /* pfacc mm6, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[6], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm6 */
    guest_trap(c, 0x006adb55u, "unsupported: pfrsqrt mm4, mm6"); /* pfrsqrt mm4, mm6 */
    guest_trap(c, 0x006adb59u, "unsupported: pfcmpgt mm5, qword ptr [0x1002f1d0]"); /* pfcmpgt mm5, qword ptr [0x1002f1d0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm4 */
    guest_trap(c, 0x006adb64u, "unsupported: pfmul mm7, mm4"); /* pfmul mm7, mm4 */
    guest_trap(c, 0x006adb68u, "unsupported: pfrsqit1 mm6, mm7"); /* pfrsqit1 mm6, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm5 */
    guest_trap(c, 0x006adb72u, "unsupported: pfrcpit2 mm6, mm4"); /* pfrcpit2 mm6, mm4 */
    guest_trap(c, 0x006adb76u, "unsupported: pfmul mm0, mm6"); /* pfmul mm0, mm6 */
    guest_trap(c, 0x006adb7au, "unsupported: pfmul mm1, mm6"); /* pfmul mm1, mm6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006adb88u, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    guest_trap(c, 0x006adb8cu, "unsupported: pfmul mm1, mm2"); /* pfmul mm1, mm2 */
    guest_trap(c, 0x006adb90u, "unsupported: pfacc mm0, mm0"); /* pfacc mm0, mm0 */
    guest_trap(c, 0x006adb94u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[5], a_, 8); } /* pxor mm5, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm5 */
    ; /* femms  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006adb30(CPU *c) { /* PTR_006adb30 */
    PREEMPT_POLL(c);
    guest_trap(c, 0x006adb30u, "unsupported: pfmul mm1, mm5"); /* pfmul mm1, mm5 */
    guest_trap(c, 0x006adb34u, "unsupported: pfacc mm1, mm1"); /* pfacc mm1, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm1 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 32u, 8, 8, 0); memcpy(&c->mm[7], a_, 8); } /* psllq mm7, 0x20 */
    guest_trap(c, 0x006adb42u, "unsupported: pfmul mm6, mm6"); /* pfmul mm6, mm6 */
    guest_trap(c, 0x006adb46u, "unsupported: pfmul mm7, mm7"); /* pfmul mm7, mm7 */
    guest_trap(c, 0x006adb4au, "unsupported: pfadd mm6, mm7"); /* pfadd mm6, mm7 */
    guest_trap(c, 0x006adb4eu, "unsupported: pfacc mm6, mm6"); /* pfacc mm6, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[6], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm6 */
    guest_trap(c, 0x006adb55u, "unsupported: pfrsqrt mm4, mm6"); /* pfrsqrt mm4, mm6 */
    guest_trap(c, 0x006adb59u, "unsupported: pfcmpgt mm5, qword ptr [0x1002f1d0]"); /* pfcmpgt mm5, qword ptr [0x1002f1d0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm4 */
    guest_trap(c, 0x006adb64u, "unsupported: pfmul mm7, mm4"); /* pfmul mm7, mm4 */
    guest_trap(c, 0x006adb68u, "unsupported: pfrsqit1 mm6, mm7"); /* pfrsqit1 mm6, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm5 */
    guest_trap(c, 0x006adb72u, "unsupported: pfrcpit2 mm6, mm4"); /* pfrcpit2 mm6, mm4 */
    guest_trap(c, 0x006adb76u, "unsupported: pfmul mm0, mm6"); /* pfmul mm0, mm6 */
    guest_trap(c, 0x006adb7au, "unsupported: pfmul mm1, mm6"); /* pfmul mm1, mm6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006adb88u, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    guest_trap(c, 0x006adb8cu, "unsupported: pfmul mm1, mm2"); /* pfmul mm1, mm2 */
    guest_trap(c, 0x006adb90u, "unsupported: pfacc mm0, mm0"); /* pfacc mm0, mm0 */
    guest_trap(c, 0x006adb94u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[5], a_, 8); } /* pxor mm5, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm5 */
    ; /* femms  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006adbaa(CPU *c) { /* PTR_006adbaa */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [eax] */
    { uint64_t v_; v_ = R64((uint32_t)(c->eax + 0x8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, qword ptr [eax + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [edx] */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [edx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [ecx] */
    guest_trap(c, 0x006adbcdu, "unsupported: pfmul mm2, mm4"); /* pfmul mm2, mm4 */
    guest_trap(c, 0x006adbd1u, "unsupported: pfmul mm3, mm5"); /* pfmul mm3, mm5 */
    { uint32_t v_ = R32((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [ecx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    guest_trap(c, 0x006adbdcu, "unsupported: pfadd mm2, mm3"); /* pfadd mm2, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006adbe3u, "unsupported: pfmul mm4, mm6"); /* pfmul mm4, mm6 */
    guest_trap(c, 0x006adbe7u, "unsupported: pfmul mm5, mm7"); /* pfmul mm5, mm7 */
    guest_trap(c, 0x006adbebu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[3], a_, 8); } /* pxor mm3, mm3 */
    guest_trap(c, 0x006adbf2u, "unsupported: pfsub mm4, mm2"); /* pfsub mm4, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, HP((uint32_t)(0x6bf150u)), 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* punpckldq mm7, dword ptr [0x1002f150] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm0 */
    guest_trap(c, 0x006adc00u, "unsupported: pfacc mm4, mm4"); /* pfacc mm4, mm4 */
    guest_trap(c, 0x006adc04u, "unsupported: pfcmpeq mm3, mm4"); /* pfcmpeq mm3, mm4 */
    { uint32_t v_; memcpy(&v_, &c->mm[3], 4); c->eax = (uint32_t)(v_); } /* movd eax, mm3 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    guest_trap(c, 0x006adc0du, "unsupported: pfrcp mm5, mm4"); /* pfrcp mm5, mm4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm1 */
    guest_trap(c, 0x006adc18u, "unsupported: pfmul mm2, mm6"); /* pfmul mm2, mm6 */
    if (c->zf) goto L_006adc25; /* je 0x6adc25 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    ; /* femms  */
    c->esp += 20; return; /* ret 0x10 */
L_006adc25:;
    guest_trap(c, 0x006adc25u, "unsupported: pfmul mm3, mm7"); /* pfmul mm3, mm7 */
    guest_trap(c, 0x006adc29u, "unsupported: pfrcpit1 mm4, mm5"); /* pfrcpit1 mm4, mm5 */
    guest_trap(c, 0x006adc2du, "unsupported: pfadd mm2, mm3"); /* pfadd mm2, mm3 */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [edx] */
    guest_trap(c, 0x006adc34u, "unsupported: pfrcpit2 mm4, mm5"); /* pfrcpit2 mm4, mm5 */
    guest_trap(c, 0x006adc38u, "unsupported: pfacc mm2, mm2"); /* pfacc mm2, mm2 */
    { uint32_t v_ = R32((uint32_t)(c->edx + 0x8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [edx + 8] */
    guest_trap(c, 0x006adc40u, "unsupported: pfsub mm3, mm6"); /* pfsub mm3, mm6 */
    guest_trap(c, 0x006adc44u, "unsupported: pfmul mm2, mm4"); /* pfmul mm2, mm4 */
    guest_trap(c, 0x006adc48u, "unsupported: pfsub mm5, mm7"); /* pfsub mm5, mm7 */
    guest_trap(c, 0x006adc4cu, "unsupported: pfmul mm3, mm2"); /* pfmul mm3, mm2 */
    guest_trap(c, 0x006adc50u, "unsupported: pfmul mm5, mm2"); /* pfmul mm5, mm2 */
    guest_trap(c, 0x006adc54u, "unsupported: pfadd mm3, mm6"); /* pfadd mm3, mm6 */
    guest_trap(c, 0x006adc58u, "unsupported: pfadd mm5, mm7"); /* pfadd mm5, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm3 */
    { uint32_t v_; memcpy(&v_, &c->mm[5], 4); W32((uint32_t)(c->eax + 0x8u), (uint32_t)(v_)); } /* movd dword ptr [eax + 8], mm5 */
    ; /* femms  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006adc68(CPU *c) { /* FUN_1001dc68 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [edx] */
    { uint64_t v_; v_ = R64((uint32_t)(c->edx + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [edx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, HP((uint32_t)(0x6bf1b0u)), 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[2], a_, 8); } /* pand mm2, qword ptr [0x1002f1b0] */
    guest_trap(c, 0x006adc80u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    guest_trap(c, 0x006adc84u, "unsupported: pfmul mm2, mm2"); /* pfmul mm2, mm2 */
    guest_trap(c, 0x006adc88u, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006adc8cu, "unsupported: pfacc mm0, mm0"); /* pfacc mm0, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006adc93u, "unsupported: pfrsqrt mm4, mm0"); /* pfrsqrt mm4, mm0 */
    guest_trap(c, 0x006adc97u, "unsupported: pfcmpgt mm5, qword ptr [0x1002f1d0]"); /* pfcmpgt mm5, qword ptr [0x1002f1d0] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm4 */
    guest_trap(c, 0x006adca2u, "unsupported: pfmul mm2, mm4"); /* pfmul mm2, mm4 */
    guest_trap(c, 0x006adca6u, "unsupported: pfrsqit1 mm0, mm2"); /* pfrsqit1 mm0, mm2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[3], a_, 8); } /* pand mm3, mm5 */
    guest_trap(c, 0x006adcb4u, "unsupported: pfrcpit2 mm0, mm4"); /* pfrcpit2 mm0, mm4 */
    guest_trap(c, 0x006adcb8u, "unsupported: pfmul mm1, mm0"); /* pfmul mm1, mm0 */
    guest_trap(c, 0x006adcbcu, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm3 */
    ; /* femms  */
    c->esp += 12; return; /* ret 8 */
}

void f_006adccc(CPU *c) { /* PTR_006adccc */
    PREEMPT_POLL(c);
    ; /* femms  */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edx, dword ptr [esp + 0xc] */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, qword ptr [ecx] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    { uint64_t v_; v_ = R64((uint32_t)(c->ecx + 0x8u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, qword ptr [ecx + 8] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[2], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[3], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* punpckhdq mm3, mm3 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm0 */
    guest_trap(c, 0x006adcf2u, "unsupported: pfmul mm0, qword ptr [edx]"); /* pfmul mm0, qword ptr [edx] */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006adcf9u, "unsupported: pfmul mm1, qword ptr [edx + 0x10]"); /* pfmul mm1, qword ptr [edx + 0x10] */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm2 */
    guest_trap(c, 0x006add01u, "unsupported: pfmul mm2, qword ptr [edx + 0x20]"); /* pfmul mm2, qword ptr [edx + 0x20] */
    { uint64_t v_; memcpy(&v_, &c->mm[3], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm3 */
    guest_trap(c, 0x006add09u, "unsupported: pfmul mm3, qword ptr [edx + 0x30]"); /* pfmul mm3, qword ptr [edx + 0x30] */
    guest_trap(c, 0x006add0eu, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006add12u, "unsupported: pfmul mm4, qword ptr [edx + 8]"); /* pfmul mm4, qword ptr [edx + 8] */
    guest_trap(c, 0x006add17u, "unsupported: pfadd mm2, mm3"); /* pfadd mm2, mm3 */
    guest_trap(c, 0x006add1bu, "unsupported: pfmul mm5, qword ptr [edx + 0x18]"); /* pfmul mm5, qword ptr [edx + 0x18] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    guest_trap(c, 0x006add24u, "unsupported: pfmul mm6, qword ptr [edx + 0x28]"); /* pfmul mm6, qword ptr [edx + 0x28] */
    guest_trap(c, 0x006add29u, "unsupported: pfmul mm7, qword ptr [edx + 0x38]"); /* pfmul mm7, qword ptr [edx + 0x38] */
    guest_trap(c, 0x006add2eu, "unsupported: pfadd mm0, mm2"); /* pfadd mm0, mm2 */
    guest_trap(c, 0x006add32u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006add36u, "unsupported: pfadd mm6, mm7"); /* pfadd mm6, mm7 */
    guest_trap(c, 0x006add3au, "unsupported: pfadd mm4, mm6"); /* pfadd mm4, mm6 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); W64((uint32_t)(c->eax), v_); } /* movq qword ptr [eax], mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); W64((uint32_t)(c->eax + 0x8u), v_); } /* movq qword ptr [eax + 8], mm4 */
    ; /* femms  */
    c->esp += 16; return; /* ret 0xc */
}

void f_006add50(CPU *c) { /* FUN_1001dd50 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    memcpy(c->xmm[0].b, HP((uint32_t)(c->eax)), 16); /* movaps xmm0, xmmword ptr [eax] */
    c->esi = (uint32_t)((uint32_t)(c->esi)); /* lea esi, [esi] */
    c->xmm[1] = c->xmm[0]; /* movaps xmm1, xmm0 */
    c->xmm[6] = c->xmm[0]; /* movaps xmm6, xmm0 */
    { uint32_t s0_ = R32((uint32_t)(0x6c8ee0u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c8ee0u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c8ee0u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c8ee0u) + 12); c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmmword ptr [0x10038ee0] */
    { uint32_t s0_ = R32((uint32_t)(0x6c8ed0u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c8ed0u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c8ed0u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c8ed0u) + 12); c->xmm[1].u[0] = c->xmm[1].u[0] & s0_; c->xmm[1].u[1] = c->xmm[1].u[1] & s1_; c->xmm[1].u[2] = c->xmm[1].u[2] & s2_; c->xmm[1].u[3] = c->xmm[1].u[3] & s3_; } /* andps xmm1, xmmword ptr [0x10038ed0] */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    c->xmm[7] = c->xmm[0]; /* movaps xmm7, xmm0 */
    { float s0_ = RF32((uint32_t)(0x6c8ec0u) + 0); float s1_ = RF32((uint32_t)(0x6c8ec0u) + 4); float s2_ = RF32((uint32_t)(0x6c8ec0u) + 8); float s3_ = RF32((uint32_t)(0x6c8ec0u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] * s0_; c->xmm[0].f[1] = c->xmm[0].f[1] * s1_; c->xmm[0].f[2] = c->xmm[0].f[2] * s2_; c->xmm[0].f[3] = c->xmm[0].f[3] * s3_; } /* mulps xmm0, xmmword ptr [0x10038ec0] */
    memcpy(c->xmm[4].b, HP((uint32_t)(0x6c8eb0u)), 16); /* movaps xmm4, xmmword ptr [0x10038eb0] */
    memcpy(c->xmm[5].b, HP((uint32_t)(0x6c8ea0u)), 16); /* movaps xmm5, xmmword ptr [0x10038ea0] */
    c->edx = (uint32_t)(c->esp); /* mov edx, esp */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0xffffffc0u)); /* add edx, -0x40 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffff0u))); /* and edx, 0xfffffff0 */
    memcpy(c->xmm[6].b, HP((uint32_t)(0x6c8e90u)), 16); /* movaps xmm6, xmmword ptr [0x10038e90] */
    memcpy(c->xmm[7].b, HP((uint32_t)(0x6c8e80u)), 16); /* movaps xmm7, xmmword ptr [0x10038e80] */
    { float s0_ = RF32((uint32_t)(0x6c8e70u) + 0); float s1_ = RF32((uint32_t)(0x6c8e70u) + 4); float s2_ = RF32((uint32_t)(0x6c8e70u) + 8); float s3_ = RF32((uint32_t)(0x6c8e70u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] + s0_; c->xmm[0].f[1] = c->xmm[0].f[1] + s1_; c->xmm[0].f[2] = c->xmm[0].f[2] + s2_; c->xmm[0].f[3] = c->xmm[0].f[3] + s3_; } /* addps xmm0, xmmword ptr [0x10038e70] */
    c->xmm[3] = c->xmm[0]; /* movaps xmm3, xmm0 */
    { float s0_ = RF32((uint32_t)(0x6c8e70u) + 0); float s1_ = RF32((uint32_t)(0x6c8e70u) + 4); float s2_ = RF32((uint32_t)(0x6c8e70u) + 8); float s3_ = RF32((uint32_t)(0x6c8e70u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] - s0_; c->xmm[0].f[1] = c->xmm[0].f[1] - s1_; c->xmm[0].f[2] = c->xmm[0].f[2] - s2_; c->xmm[0].f[3] = c->xmm[0].f[3] - s3_; } /* subps xmm0, xmmword ptr [0x10038e70] */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[4].f[0] = c->xmm[4].f[0] * s0_; c->xmm[4].f[1] = c->xmm[4].f[1] * s1_; c->xmm[4].f[2] = c->xmm[4].f[2] * s2_; c->xmm[4].f[3] = c->xmm[4].f[3] * s3_; } /* mulps xmm4, xmm0 */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm0 */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm0 */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[7].f[0] = c->xmm[7].f[0] * s0_; c->xmm[7].f[1] = c->xmm[7].f[1] * s1_; c->xmm[7].f[2] = c->xmm[7].f[2] * s2_; c->xmm[7].f[3] = c->xmm[7].f[3] * s3_; } /* mulps xmm7, xmm0 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm4 */
    { float s0_ = c->xmm[5].f[0]; float s1_ = c->xmm[5].f[1]; float s2_ = c->xmm[5].f[2]; float s3_ = c->xmm[5].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm5 */
    memcpy(c->xmm[5].b, HP((uint32_t)(0x6c8e60u)), 16); /* movaps xmm5, xmmword ptr [0x10038e60] */
    { float s0_ = c->xmm[6].f[0]; float s1_ = c->xmm[6].f[1]; float s2_ = c->xmm[6].f[2]; float s3_ = c->xmm[6].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm6 */
    memcpy(c->xmm[6].b, HP((uint32_t)(0x6c8e50u)), 16); /* movaps xmm6, xmmword ptr [0x10038e50] */
    { float s0_ = c->xmm[7].f[0]; float s1_ = c->xmm[7].f[1]; float s2_ = c->xmm[7].f[2]; float s3_ = c->xmm[7].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm7 */
    c->xmm[4] = c->xmm[2]; /* movaps xmm4, xmm2 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[4].f[0] = c->xmm[4].f[0] * s0_; c->xmm[4].f[1] = c->xmm[4].f[1] * s1_; c->xmm[4].f[2] = c->xmm[4].f[2] * s2_; c->xmm[4].f[3] = c->xmm[4].f[3] * s3_; } /* mulps xmm4, xmm4 */
    { uint32_t s0_ = R32((uint32_t)(0x6c8e40u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c8e40u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c8e40u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c8e40u) + 12); c->xmm[3].u[0] = c->xmm[3].u[0] & s0_; c->xmm[3].u[1] = c->xmm[3].u[1] & s1_; c->xmm[3].u[2] = c->xmm[3].u[2] & s2_; c->xmm[3].u[3] = c->xmm[3].u[3] & s3_; } /* andps xmm3, xmmword ptr [0x10038e40] */
    c->xmm[0] = c->xmm[3]; /* movaps xmm0, xmm3 */
    c->xmm[7] = c->xmm[3]; /* movaps xmm7, xmm3 */
    { uint32_t s0_ = R32((uint32_t)(0x6c8e30u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c8e30u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c8e30u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c8e30u) + 12); c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmmword ptr [0x10038e30] */
    memcpy(HP((uint32_t)(c->edx)), c->xmm[0].b, 16); /* movaps xmmword ptr [edx], xmm0 */
    memcpy(HP((uint32_t)(c->edx + 0x10u)), c->xmm[3].b, 16); /* movaps xmmword ptr [edx + 0x10], xmm3 */
    memcpy(HP((uint32_t)(c->edx + 0x20u)), c->xmm[7].b, 16); /* movaps xmmword ptr [edx + 0x20], xmm7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov eax, dword ptr [edx + 0x10] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->edx)))); /* sub eax, dword ptr [edx] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x14u))); /* mov eax, dword ptr [edx + 0x14] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->edx + 0x4u)))); /* sub eax, dword ptr [edx + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x14u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x14], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x18u))); /* mov eax, dword ptr [edx + 0x18] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->edx + 0x8u)))); /* sub eax, dword ptr [edx + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x18u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x18], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x1cu))); /* mov eax, dword ptr [edx + 0x1c] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->edx + 0xcu)))); /* sub eax, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x1cu), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x1c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x20u))); /* mov eax, dword ptr [edx + 0x20] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->edx)))); /* add eax, dword ptr [edx] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x20u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x24u))); /* mov eax, dword ptr [edx + 0x24] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->edx + 0x4u)))); /* add eax, dword ptr [edx + 4] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x24u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x24], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x28u))); /* mov eax, dword ptr [edx + 0x28] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->edx + 0x8u)))); /* add eax, dword ptr [edx + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x28u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x28], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x2cu))); /* mov eax, dword ptr [edx + 0x2c] */
    c->eax = (uint32_t)(add32(c, c->eax, R32((uint32_t)(c->edx + 0xcu)))); /* add eax, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(0x6c8e20u))))); /* and eax, dword ptr [0x10038e20] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x2cu), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0x2c], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov eax, dword ptr [edx + 4] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 4], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov eax, dword ptr [edx + 8] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [edx + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov eax, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(shl32(c, c->eax, 30)); /* shl eax, 0x1e */
    W32((uint32_t)(c->edx + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [edx + 0xc], eax */
    memcpy(c->xmm[3].b, HP((uint32_t)(c->edx + 0x10u)), 16); /* movaps xmm3, xmmword ptr [edx + 0x10] */
    memcpy(c->xmm[7].b, HP((uint32_t)(c->edx + 0x20u)), 16); /* movaps xmm7, xmmword ptr [edx + 0x20] */
    memcpy(c->xmm[0].b, HP((uint32_t)(c->edx)), 16); /* movaps xmm0, xmmword ptr [edx] */
    { uint32_t s0_ = c->xmm[1].u[0]; uint32_t s1_ = c->xmm[1].u[1]; uint32_t s2_ = c->xmm[1].u[2]; uint32_t s3_ = c->xmm[1].u[3]; c->xmm[3].u[0] = c->xmm[3].u[0] ^ s0_; c->xmm[3].u[1] = c->xmm[3].u[1] ^ s1_; c->xmm[3].u[2] = c->xmm[3].u[2] ^ s2_; c->xmm[3].u[3] = c->xmm[3].u[3] ^ s3_; } /* xorps xmm3, xmm1 */
    { uint32_t s0_ = c->xmm[1].u[0]; uint32_t s1_ = c->xmm[1].u[1]; uint32_t s2_ = c->xmm[1].u[2]; uint32_t s3_ = c->xmm[1].u[3]; c->xmm[1].u[0] = c->xmm[1].u[0] ^ s0_; c->xmm[1].u[1] = c->xmm[1].u[1] ^ s1_; c->xmm[1].u[2] = c->xmm[1].u[2] ^ s2_; c->xmm[1].u[3] = c->xmm[1].u[3] ^ s3_; } /* xorps xmm1, xmm1 */
    { { float a_ = c->xmm[0].f[0], b_ = c->xmm[1].f[0]; c->xmm[0].u[0] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[1], b_ = c->xmm[1].f[1]; c->xmm[0].u[1] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[2], b_ = c->xmm[1].f[2]; c->xmm[0].u[2] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[3], b_ = c->xmm[1].f[3]; c->xmm[0].u[3] = (!(a_ == b_)) ? 0xffffffffu : 0; } } /* cmpneqps xmm0, xmm1 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8e10u) + 0); float s1_ = RF32((uint32_t)(0x6c8e10u) + 4); float s2_ = RF32((uint32_t)(0x6c8e10u) + 8); float s3_ = RF32((uint32_t)(0x6c8e10u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038e10] */
    { float s0_ = RF32((uint32_t)(0x6c8e00u) + 0); float s1_ = RF32((uint32_t)(0x6c8e00u) + 4); float s2_ = RF32((uint32_t)(0x6c8e00u) + 8); float s3_ = RF32((uint32_t)(0x6c8e00u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10038e00] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8df0u) + 0); float s1_ = RF32((uint32_t)(0x6c8df0u) + 4); float s2_ = RF32((uint32_t)(0x6c8df0u) + 8); float s3_ = RF32((uint32_t)(0x6c8df0u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038df0] */
    { float s0_ = RF32((uint32_t)(0x6c8de0u) + 0); float s1_ = RF32((uint32_t)(0x6c8de0u) + 4); float s2_ = RF32((uint32_t)(0x6c8de0u) + 8); float s3_ = RF32((uint32_t)(0x6c8de0u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10038de0] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8dd0u) + 0); float s1_ = RF32((uint32_t)(0x6c8dd0u) + 4); float s2_ = RF32((uint32_t)(0x6c8dd0u) + 8); float s3_ = RF32((uint32_t)(0x6c8dd0u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038dd0] */
    { float s0_ = RF32((uint32_t)(0x6c8dc0u) + 0); float s1_ = RF32((uint32_t)(0x6c8dc0u) + 4); float s2_ = RF32((uint32_t)(0x6c8dc0u) + 8); float s3_ = RF32((uint32_t)(0x6c8dc0u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10038dc0] */
    { float s0_ = c->xmm[2].f[0]; float s1_ = c->xmm[2].f[1]; float s2_ = c->xmm[2].f[2]; float s3_ = c->xmm[2].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm2 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8db0u) + 0); float s1_ = RF32((uint32_t)(0x6c8db0u) + 4); float s2_ = RF32((uint32_t)(0x6c8db0u) + 8); float s3_ = RF32((uint32_t)(0x6c8db0u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10038db0] */
    c->xmm[1] = c->xmm[0]; /* movaps xmm1, xmm0 */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    { uint32_t s0_ = c->xmm[5].u[0]; uint32_t s1_ = c->xmm[5].u[1]; uint32_t s2_ = c->xmm[5].u[2]; uint32_t s3_ = c->xmm[5].u[3]; c->xmm[1].u[0] = ~c->xmm[1].u[0] & s0_; c->xmm[1].u[1] = ~c->xmm[1].u[1] & s1_; c->xmm[1].u[2] = ~c->xmm[1].u[2] & s2_; c->xmm[1].u[3] = ~c->xmm[1].u[3] & s3_; } /* andnps xmm1, xmm5 */
    { uint32_t s0_ = c->xmm[6].u[0]; uint32_t s1_ = c->xmm[6].u[1]; uint32_t s2_ = c->xmm[6].u[2]; uint32_t s3_ = c->xmm[6].u[3]; c->xmm[2].u[0] = c->xmm[2].u[0] & s0_; c->xmm[2].u[1] = c->xmm[2].u[1] & s1_; c->xmm[2].u[2] = c->xmm[2].u[2] & s2_; c->xmm[2].u[3] = c->xmm[2].u[3] & s3_; } /* andps xmm2, xmm6 */
    { uint32_t s0_ = c->xmm[2].u[0]; uint32_t s1_ = c->xmm[2].u[1]; uint32_t s2_ = c->xmm[2].u[2]; uint32_t s3_ = c->xmm[2].u[3]; c->xmm[1].u[0] = c->xmm[1].u[0] | s0_; c->xmm[1].u[1] = c->xmm[1].u[1] | s1_; c->xmm[1].u[2] = c->xmm[1].u[2] | s2_; c->xmm[1].u[3] = c->xmm[1].u[3] | s3_; } /* orps xmm1, xmm2 */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    { uint32_t s0_ = c->xmm[5].u[0]; uint32_t s1_ = c->xmm[5].u[1]; uint32_t s2_ = c->xmm[5].u[2]; uint32_t s3_ = c->xmm[5].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmm5 */
    { uint32_t s0_ = c->xmm[6].u[0]; uint32_t s1_ = c->xmm[6].u[1]; uint32_t s2_ = c->xmm[6].u[2]; uint32_t s3_ = c->xmm[6].u[3]; c->xmm[2].u[0] = ~c->xmm[2].u[0] & s0_; c->xmm[2].u[1] = ~c->xmm[2].u[1] & s1_; c->xmm[2].u[2] = ~c->xmm[2].u[2] & s2_; c->xmm[2].u[3] = ~c->xmm[2].u[3] & s3_; } /* andnps xmm2, xmm6 */
    { uint32_t s0_ = c->xmm[2].u[0]; uint32_t s1_ = c->xmm[2].u[1]; uint32_t s2_ = c->xmm[2].u[2]; uint32_t s3_ = c->xmm[2].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] | s0_; c->xmm[0].u[1] = c->xmm[0].u[1] | s1_; c->xmm[0].u[2] = c->xmm[0].u[2] | s2_; c->xmm[0].u[3] = c->xmm[0].u[3] | s3_; } /* orps xmm0, xmm2 */
    { uint32_t s0_ = c->xmm[7].u[0]; uint32_t s1_ = c->xmm[7].u[1]; uint32_t s2_ = c->xmm[7].u[2]; uint32_t s3_ = c->xmm[7].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] ^ s0_; c->xmm[0].u[1] = c->xmm[0].u[1] ^ s1_; c->xmm[0].u[2] = c->xmm[0].u[2] ^ s2_; c->xmm[0].u[3] = c->xmm[0].u[3] ^ s3_; } /* xorps xmm0, xmm7 */
    { uint32_t s0_ = c->xmm[3].u[0]; uint32_t s1_ = c->xmm[3].u[1]; uint32_t s2_ = c->xmm[3].u[2]; uint32_t s3_ = c->xmm[3].u[3]; c->xmm[1].u[0] = c->xmm[1].u[0] ^ s0_; c->xmm[1].u[1] = c->xmm[1].u[1] ^ s1_; c->xmm[1].u[2] = c->xmm[1].u[2] ^ s2_; c->xmm[1].u[3] = c->xmm[1].u[3] ^ s3_; } /* xorps xmm1, xmm3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    memcpy(HP((uint32_t)(c->eax)), c->xmm[1].b, 16); /* movaps xmmword ptr [eax], xmm1 */
    memcpy(HP((uint32_t)(c->edx)), c->xmm[0].b, 16); /* movaps xmmword ptr [edx], xmm0 */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006adf40(CPU *c) { /* FUN_1001df40 */
    PREEMPT_POLL(c);
    c->xmm[1] = c->xmm[0]; /* movaps xmm1, xmm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[0].b, 16); memcpy(b_, HP((uint32_t)(0x6c8fc0u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[0].b, a_, 16); } /* pand xmm0, xmmword ptr [0x10038fc0] */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[1].b, 16); memcpy(b_, HP((uint32_t)(0x6c8fb0u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[1].b, a_, 16); } /* pand xmm1, xmmword ptr [0x10038fb0] */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    { float s0_ = RF32((uint32_t)(0x6c8fa0u) + 0); float s1_ = RF32((uint32_t)(0x6c8fa0u) + 4); float s2_ = RF32((uint32_t)(0x6c8fa0u) + 8); float s3_ = RF32((uint32_t)(0x6c8fa0u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] * s0_; c->xmm[0].f[1] = c->xmm[0].f[1] * s1_; c->xmm[0].f[2] = c->xmm[0].f[2] * s2_; c->xmm[0].f[3] = c->xmm[0].f[3] * s3_; } /* mulps xmm0, xmmword ptr [0x10038fa0] */
    memcpy(c->xmm[4].b, HP((uint32_t)(0x6c8f90u)), 16); /* movaps xmm4, xmmword ptr [0x10038f90] */
    { float s0_ = RF32((uint32_t)(0x6c8f80u) + 0); float s1_ = RF32((uint32_t)(0x6c8f80u) + 4); float s2_ = RF32((uint32_t)(0x6c8f80u) + 8); float s3_ = RF32((uint32_t)(0x6c8f80u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] + s0_; c->xmm[0].f[1] = c->xmm[0].f[1] + s1_; c->xmm[0].f[2] = c->xmm[0].f[2] + s2_; c->xmm[0].f[3] = c->xmm[0].f[3] + s3_; } /* addps xmm0, xmmword ptr [0x10038f80] */
    c->xmm[3] = c->xmm[0]; /* movaps xmm3, xmm0 */
    { float s0_ = RF32((uint32_t)(0x6c8f80u) + 0); float s1_ = RF32((uint32_t)(0x6c8f80u) + 4); float s2_ = RF32((uint32_t)(0x6c8f80u) + 8); float s3_ = RF32((uint32_t)(0x6c8f80u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] - s0_; c->xmm[0].f[1] = c->xmm[0].f[1] - s1_; c->xmm[0].f[2] = c->xmm[0].f[2] - s2_; c->xmm[0].f[3] = c->xmm[0].f[3] - s3_; } /* subps xmm0, xmmword ptr [0x10038f80] */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[4].f[0] = c->xmm[4].f[0] * s0_; c->xmm[4].f[1] = c->xmm[4].f[1] * s1_; c->xmm[4].f[2] = c->xmm[4].f[2] * s2_; c->xmm[4].f[3] = c->xmm[4].f[3] * s3_; } /* mulps xmm4, xmm0 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm4 */
    { XMM t_ = c->xmm[4]; c->xmm[4].f[0] = t_.f[1]; c->xmm[4].f[1] = t_.f[2]; c->xmm[4].f[2] = c->xmm[4].f[3]; c->xmm[4].f[3] = c->xmm[4].f[0]; } /* shufps xmm4, xmm4, 0x39 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm4 */
    { XMM t_ = c->xmm[4]; c->xmm[4].f[0] = t_.f[1]; c->xmm[4].f[1] = t_.f[2]; c->xmm[4].f[2] = c->xmm[4].f[3]; c->xmm[4].f[3] = c->xmm[4].f[0]; } /* shufps xmm4, xmm4, 0x39 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm4 */
    { XMM t_ = c->xmm[4]; c->xmm[4].f[0] = t_.f[1]; c->xmm[4].f[1] = t_.f[2]; c->xmm[4].f[2] = c->xmm[4].f[3]; c->xmm[4].f[3] = c->xmm[4].f[0]; } /* shufps xmm4, xmm4, 0x39 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm4 */
    c->xmm[4] = c->xmm[2]; /* movaps xmm4, xmm2 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[4].f[0] = c->xmm[4].f[0] * s0_; c->xmm[4].f[1] = c->xmm[4].f[1] * s1_; c->xmm[4].f[2] = c->xmm[4].f[2] * s2_; c->xmm[4].f[3] = c->xmm[4].f[3] * s3_; } /* mulps xmm4, xmm4 */
    { uint32_t s0_ = R32((uint32_t)(0x6c8f70u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c8f70u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c8f70u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c8f70u) + 12); c->xmm[3].u[0] = c->xmm[3].u[0] & s0_; c->xmm[3].u[1] = c->xmm[3].u[1] & s1_; c->xmm[3].u[2] = c->xmm[3].u[2] & s2_; c->xmm[3].u[3] = c->xmm[3].u[3] & s3_; } /* andps xmm3, xmmword ptr [0x10038f70] */
    c->xmm[0] = c->xmm[3]; /* movaps xmm0, xmm3 */
    c->xmm[7] = c->xmm[3]; /* movaps xmm7, xmm3 */
    { uint32_t s0_ = R32((uint32_t)(0x6c8f60u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c8f60u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c8f60u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c8f60u) + 12); c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmmword ptr [0x10038f60] */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[3].b, 16); memcpy(b_, c->xmm[0].b, 16); v_sub(a_, b_, 16, 4, 0); memcpy(c->xmm[3].b, a_, 16); } /* psubd xmm3, xmm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[7].b, 16); memcpy(b_, c->xmm[0].b, 16); v_add(a_, b_, 16, 4, 0); memcpy(c->xmm[7].b, a_, 16); } /* paddd xmm7, xmm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[3].b, 16); memcpy(b_, HP((uint32_t)(0x6c8f50u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[3].b, a_, 16); } /* pand xmm3, xmmword ptr [0x10038f50] */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[7].b, 16); memcpy(b_, HP((uint32_t)(0x6c8f50u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[7].b, a_, 16); } /* pand xmm7, xmmword ptr [0x10038f50] */
    { uint8_t a_[16]; memcpy(a_, c->xmm[3].b, 16); v_shift(a_, 30u, 16, 4, 0); memcpy(c->xmm[3].b, a_, 16); } /* pslld xmm3, 0x1e */
    { uint8_t a_[16]; memcpy(a_, c->xmm[7].b, 16); v_shift(a_, 30u, 16, 4, 0); memcpy(c->xmm[7].b, a_, 16); } /* pslld xmm7, 0x1e */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[3].b, 16); memcpy(b_, c->xmm[1].b, 16); v_logic(a_, b_, 16, 3); memcpy(c->xmm[3].b, a_, 16); } /* pxor xmm3, xmm1 */
    { uint8_t a_[16]; memcpy(a_, c->xmm[0].b, 16); v_shift(a_, 30u, 16, 4, 0); memcpy(c->xmm[0].b, a_, 16); } /* pslld xmm0, 0x1e */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[1].b, 16); memcpy(b_, c->xmm[1].b, 16); v_logic(a_, b_, 16, 3); memcpy(c->xmm[1].b, a_, 16); } /* pxor xmm1, xmm1 */
    { { float a_ = c->xmm[0].f[0], b_ = c->xmm[1].f[0]; c->xmm[0].u[0] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[1], b_ = c->xmm[1].f[1]; c->xmm[0].u[1] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[2], b_ = c->xmm[1].f[2]; c->xmm[0].u[2] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[3], b_ = c->xmm[1].f[3]; c->xmm[0].u[3] = (!(a_ == b_)) ? 0xffffffffu : 0; } } /* cmpneqps xmm0, xmm1 */
    memcpy(c->xmm[5].b, HP((uint32_t)(0x6c8f40u)), 16); /* movaps xmm5, xmmword ptr [0x10038f40] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8f30u) + 0); float s1_ = RF32((uint32_t)(0x6c8f30u) + 4); float s2_ = RF32((uint32_t)(0x6c8f30u) + 8); float s3_ = RF32((uint32_t)(0x6c8f30u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038f30] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8f20u) + 0); float s1_ = RF32((uint32_t)(0x6c8f20u) + 4); float s2_ = RF32((uint32_t)(0x6c8f20u) + 8); float s3_ = RF32((uint32_t)(0x6c8f20u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038f20] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8f10u) + 0); float s1_ = RF32((uint32_t)(0x6c8f10u) + 4); float s2_ = RF32((uint32_t)(0x6c8f10u) + 8); float s3_ = RF32((uint32_t)(0x6c8f10u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038f10] */
    { XMM a_ = c->xmm[2], b_ = c->xmm[4]; c->xmm[2].f[0] = a_.f[0]; c->xmm[2].f[1] = b_.f[0]; c->xmm[2].f[2] = a_.f[1]; c->xmm[2].f[3] = b_.f[1]; } /* unpcklps xmm2, xmm4 */
    { float s0_ = c->xmm[2].f[0]; float s1_ = c->xmm[2].f[1]; float s2_ = c->xmm[2].f[2]; float s3_ = c->xmm[2].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm2 */
    { float s0_ = RF32((uint32_t)(0x6c8f00u) + 0); float s1_ = RF32((uint32_t)(0x6c8f00u) + 4); float s2_ = RF32((uint32_t)(0x6c8f00u) + 8); float s3_ = RF32((uint32_t)(0x6c8f00u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038f00] */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    { uint32_t s0_ = c->xmm[5].u[0]; uint32_t s1_ = c->xmm[5].u[1]; uint32_t s2_ = c->xmm[5].u[2]; uint32_t s3_ = c->xmm[5].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmm5 */
    { uint32_t s0_ = c->xmm[5].u[0]; uint32_t s1_ = c->xmm[5].u[1]; uint32_t s2_ = c->xmm[5].u[2]; uint32_t s3_ = c->xmm[5].u[3]; c->xmm[2].u[0] = ~c->xmm[2].u[0] & s0_; c->xmm[2].u[1] = ~c->xmm[2].u[1] & s1_; c->xmm[2].u[2] = ~c->xmm[2].u[2] & s2_; c->xmm[2].u[3] = ~c->xmm[2].u[3] & s3_; } /* andnps xmm2, xmm5 */
    { XMM t_ = c->xmm[2]; c->xmm[2].f[0] = t_.f[1]; c->xmm[2].f[1] = t_.f[0]; c->xmm[2].f[2] = c->xmm[2].f[3]; c->xmm[2].f[3] = c->xmm[2].f[2]; } /* shufps xmm2, xmm2, 0xb1 */
    { uint32_t s0_ = c->xmm[2].u[0]; uint32_t s1_ = c->xmm[2].u[1]; uint32_t s2_ = c->xmm[2].u[2]; uint32_t s3_ = c->xmm[2].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] | s0_; c->xmm[0].u[1] = c->xmm[0].u[1] | s1_; c->xmm[0].u[2] = c->xmm[0].u[2] | s2_; c->xmm[0].u[3] = c->xmm[0].u[3] | s3_; } /* orps xmm0, xmm2 */
    { XMM a_ = c->xmm[7], b_ = c->xmm[3]; c->xmm[7].f[0] = a_.f[0]; c->xmm[7].f[1] = b_.f[0]; c->xmm[7].f[2] = a_.f[1]; c->xmm[7].f[3] = b_.f[1]; } /* unpcklps xmm7, xmm3 */
    { uint32_t s0_ = c->xmm[7].u[0]; uint32_t s1_ = c->xmm[7].u[1]; uint32_t s2_ = c->xmm[7].u[2]; uint32_t s3_ = c->xmm[7].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] ^ s0_; c->xmm[0].u[1] = c->xmm[0].u[1] ^ s1_; c->xmm[0].u[2] = c->xmm[0].u[2] ^ s2_; c->xmm[0].u[3] = c->xmm[0].u[3] ^ s3_; } /* xorps xmm0, xmm7 */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006ae030(CPU *c) { /* FUN_1001e030 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    memcpy(c->xmm[0].b, HP((uint32_t)(c->eax)), 16); /* movaps xmm0, xmmword ptr [eax] */
    c->esi = (uint32_t)((uint32_t)(c->esi)); /* lea esi, [esi] */
    c->xmm[1] = c->xmm[0]; /* movaps xmm1, xmm0 */
    c->xmm[6] = c->xmm[0]; /* movaps xmm6, xmm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[0].b, 16); memcpy(b_, HP((uint32_t)(0x6c9100u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[0].b, a_, 16); } /* pand xmm0, xmmword ptr [0x10039100] */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[1].b, 16); memcpy(b_, HP((uint32_t)(0x6c90f0u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[1].b, a_, 16); } /* pand xmm1, xmmword ptr [0x100390f0] */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    c->xmm[7] = c->xmm[0]; /* movaps xmm7, xmm0 */
    { float s0_ = RF32((uint32_t)(0x6c90e0u) + 0); float s1_ = RF32((uint32_t)(0x6c90e0u) + 4); float s2_ = RF32((uint32_t)(0x6c90e0u) + 8); float s3_ = RF32((uint32_t)(0x6c90e0u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] * s0_; c->xmm[0].f[1] = c->xmm[0].f[1] * s1_; c->xmm[0].f[2] = c->xmm[0].f[2] * s2_; c->xmm[0].f[3] = c->xmm[0].f[3] * s3_; } /* mulps xmm0, xmmword ptr [0x100390e0] */
    memcpy(c->xmm[4].b, HP((uint32_t)(0x6c90d0u)), 16); /* movaps xmm4, xmmword ptr [0x100390d0] */
    memcpy(c->xmm[5].b, HP((uint32_t)(0x6c90c0u)), 16); /* movaps xmm5, xmmword ptr [0x100390c0] */
    memcpy(c->xmm[6].b, HP((uint32_t)(0x6c90b0u)), 16); /* movaps xmm6, xmmword ptr [0x100390b0] */
    memcpy(c->xmm[7].b, HP((uint32_t)(0x6c90a0u)), 16); /* movaps xmm7, xmmword ptr [0x100390a0] */
    { float s0_ = RF32((uint32_t)(0x6c9090u) + 0); float s1_ = RF32((uint32_t)(0x6c9090u) + 4); float s2_ = RF32((uint32_t)(0x6c9090u) + 8); float s3_ = RF32((uint32_t)(0x6c9090u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] + s0_; c->xmm[0].f[1] = c->xmm[0].f[1] + s1_; c->xmm[0].f[2] = c->xmm[0].f[2] + s2_; c->xmm[0].f[3] = c->xmm[0].f[3] + s3_; } /* addps xmm0, xmmword ptr [0x10039090] */
    c->xmm[3] = c->xmm[0]; /* movaps xmm3, xmm0 */
    { float s0_ = RF32((uint32_t)(0x6c9090u) + 0); float s1_ = RF32((uint32_t)(0x6c9090u) + 4); float s2_ = RF32((uint32_t)(0x6c9090u) + 8); float s3_ = RF32((uint32_t)(0x6c9090u) + 12); c->xmm[0].f[0] = c->xmm[0].f[0] - s0_; c->xmm[0].f[1] = c->xmm[0].f[1] - s1_; c->xmm[0].f[2] = c->xmm[0].f[2] - s2_; c->xmm[0].f[3] = c->xmm[0].f[3] - s3_; } /* subps xmm0, xmmword ptr [0x10039090] */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[4].f[0] = c->xmm[4].f[0] * s0_; c->xmm[4].f[1] = c->xmm[4].f[1] * s1_; c->xmm[4].f[2] = c->xmm[4].f[2] * s2_; c->xmm[4].f[3] = c->xmm[4].f[3] * s3_; } /* mulps xmm4, xmm0 */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm0 */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm0 */
    { float s0_ = c->xmm[0].f[0]; float s1_ = c->xmm[0].f[1]; float s2_ = c->xmm[0].f[2]; float s3_ = c->xmm[0].f[3]; c->xmm[7].f[0] = c->xmm[7].f[0] * s0_; c->xmm[7].f[1] = c->xmm[7].f[1] * s1_; c->xmm[7].f[2] = c->xmm[7].f[2] * s2_; c->xmm[7].f[3] = c->xmm[7].f[3] * s3_; } /* mulps xmm7, xmm0 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm4 */
    { float s0_ = c->xmm[5].f[0]; float s1_ = c->xmm[5].f[1]; float s2_ = c->xmm[5].f[2]; float s3_ = c->xmm[5].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm5 */
    memcpy(c->xmm[5].b, HP((uint32_t)(0x6c9080u)), 16); /* movaps xmm5, xmmword ptr [0x10039080] */
    { float s0_ = c->xmm[6].f[0]; float s1_ = c->xmm[6].f[1]; float s2_ = c->xmm[6].f[2]; float s3_ = c->xmm[6].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm6 */
    memcpy(c->xmm[6].b, HP((uint32_t)(0x6c9070u)), 16); /* movaps xmm6, xmmword ptr [0x10039070] */
    { float s0_ = c->xmm[7].f[0]; float s1_ = c->xmm[7].f[1]; float s2_ = c->xmm[7].f[2]; float s3_ = c->xmm[7].f[3]; c->xmm[2].f[0] = c->xmm[2].f[0] - s0_; c->xmm[2].f[1] = c->xmm[2].f[1] - s1_; c->xmm[2].f[2] = c->xmm[2].f[2] - s2_; c->xmm[2].f[3] = c->xmm[2].f[3] - s3_; } /* subps xmm2, xmm7 */
    c->xmm[4] = c->xmm[2]; /* movaps xmm4, xmm2 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[4].f[0] = c->xmm[4].f[0] * s0_; c->xmm[4].f[1] = c->xmm[4].f[1] * s1_; c->xmm[4].f[2] = c->xmm[4].f[2] * s2_; c->xmm[4].f[3] = c->xmm[4].f[3] * s3_; } /* mulps xmm4, xmm4 */
    { uint32_t s0_ = R32((uint32_t)(0x6c9060u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c9060u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c9060u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c9060u) + 12); c->xmm[3].u[0] = c->xmm[3].u[0] & s0_; c->xmm[3].u[1] = c->xmm[3].u[1] & s1_; c->xmm[3].u[2] = c->xmm[3].u[2] & s2_; c->xmm[3].u[3] = c->xmm[3].u[3] & s3_; } /* andps xmm3, xmmword ptr [0x10039060] */
    c->xmm[0] = c->xmm[3]; /* movaps xmm0, xmm3 */
    c->xmm[7] = c->xmm[3]; /* movaps xmm7, xmm3 */
    { uint32_t s0_ = R32((uint32_t)(0x6c9050u) + 0); uint32_t s1_ = R32((uint32_t)(0x6c9050u) + 4); uint32_t s2_ = R32((uint32_t)(0x6c9050u) + 8); uint32_t s3_ = R32((uint32_t)(0x6c9050u) + 12); c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmmword ptr [0x10039050] */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[3].b, 16); memcpy(b_, c->xmm[0].b, 16); v_sub(a_, b_, 16, 4, 0); memcpy(c->xmm[3].b, a_, 16); } /* psubd xmm3, xmm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[7].b, 16); memcpy(b_, c->xmm[0].b, 16); v_add(a_, b_, 16, 4, 0); memcpy(c->xmm[7].b, a_, 16); } /* paddd xmm7, xmm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[3].b, 16); memcpy(b_, HP((uint32_t)(0x6c9040u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[3].b, a_, 16); } /* pand xmm3, xmmword ptr [0x10039040] */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[7].b, 16); memcpy(b_, HP((uint32_t)(0x6c9040u)), 16); v_logic(a_, b_, 16, 0); memcpy(c->xmm[7].b, a_, 16); } /* pand xmm7, xmmword ptr [0x10039040] */
    { uint8_t a_[16]; memcpy(a_, c->xmm[3].b, 16); v_shift(a_, 30u, 16, 4, 0); memcpy(c->xmm[3].b, a_, 16); } /* pslld xmm3, 0x1e */
    { uint8_t a_[16]; memcpy(a_, c->xmm[7].b, 16); v_shift(a_, 30u, 16, 4, 0); memcpy(c->xmm[7].b, a_, 16); } /* pslld xmm7, 0x1e */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[3].b, 16); memcpy(b_, c->xmm[1].b, 16); v_logic(a_, b_, 16, 3); memcpy(c->xmm[3].b, a_, 16); } /* pxor xmm3, xmm1 */
    { uint8_t a_[16]; memcpy(a_, c->xmm[0].b, 16); v_shift(a_, 30u, 16, 4, 0); memcpy(c->xmm[0].b, a_, 16); } /* pslld xmm0, 0x1e */
    { uint8_t a_[16], b_[16]; memcpy(a_, c->xmm[1].b, 16); memcpy(b_, c->xmm[1].b, 16); v_logic(a_, b_, 16, 3); memcpy(c->xmm[1].b, a_, 16); } /* pxor xmm1, xmm1 */
    { { float a_ = c->xmm[0].f[0], b_ = c->xmm[1].f[0]; c->xmm[0].u[0] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[1], b_ = c->xmm[1].f[1]; c->xmm[0].u[1] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[2], b_ = c->xmm[1].f[2]; c->xmm[0].u[2] = (!(a_ == b_)) ? 0xffffffffu : 0; } { float a_ = c->xmm[0].f[3], b_ = c->xmm[1].f[3]; c->xmm[0].u[3] = (!(a_ == b_)) ? 0xffffffffu : 0; } } /* cmpneqps xmm0, xmm1 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c9030u) + 0); float s1_ = RF32((uint32_t)(0x6c9030u) + 4); float s2_ = RF32((uint32_t)(0x6c9030u) + 8); float s3_ = RF32((uint32_t)(0x6c9030u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10039030] */
    { float s0_ = RF32((uint32_t)(0x6c9020u) + 0); float s1_ = RF32((uint32_t)(0x6c9020u) + 4); float s2_ = RF32((uint32_t)(0x6c9020u) + 8); float s3_ = RF32((uint32_t)(0x6c9020u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10039020] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c9010u) + 0); float s1_ = RF32((uint32_t)(0x6c9010u) + 4); float s2_ = RF32((uint32_t)(0x6c9010u) + 8); float s3_ = RF32((uint32_t)(0x6c9010u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10039010] */
    { float s0_ = RF32((uint32_t)(0x6c9000u) + 0); float s1_ = RF32((uint32_t)(0x6c9000u) + 4); float s2_ = RF32((uint32_t)(0x6c9000u) + 8); float s3_ = RF32((uint32_t)(0x6c9000u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10039000] */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm4 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8ff0u) + 0); float s1_ = RF32((uint32_t)(0x6c8ff0u) + 4); float s2_ = RF32((uint32_t)(0x6c8ff0u) + 8); float s3_ = RF32((uint32_t)(0x6c8ff0u) + 12); c->xmm[5].f[0] = c->xmm[5].f[0] + s0_; c->xmm[5].f[1] = c->xmm[5].f[1] + s1_; c->xmm[5].f[2] = c->xmm[5].f[2] + s2_; c->xmm[5].f[3] = c->xmm[5].f[3] + s3_; } /* addps xmm5, xmmword ptr [0x10038ff0] */
    { float s0_ = RF32((uint32_t)(0x6c8fe0u) + 0); float s1_ = RF32((uint32_t)(0x6c8fe0u) + 4); float s2_ = RF32((uint32_t)(0x6c8fe0u) + 8); float s3_ = RF32((uint32_t)(0x6c8fe0u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10038fe0] */
    { float s0_ = c->xmm[2].f[0]; float s1_ = c->xmm[2].f[1]; float s2_ = c->xmm[2].f[2]; float s3_ = c->xmm[2].f[3]; c->xmm[5].f[0] = c->xmm[5].f[0] * s0_; c->xmm[5].f[1] = c->xmm[5].f[1] * s1_; c->xmm[5].f[2] = c->xmm[5].f[2] * s2_; c->xmm[5].f[3] = c->xmm[5].f[3] * s3_; } /* mulps xmm5, xmm2 */
    { float s0_ = c->xmm[4].f[0]; float s1_ = c->xmm[4].f[1]; float s2_ = c->xmm[4].f[2]; float s3_ = c->xmm[4].f[3]; c->xmm[6].f[0] = c->xmm[6].f[0] * s0_; c->xmm[6].f[1] = c->xmm[6].f[1] * s1_; c->xmm[6].f[2] = c->xmm[6].f[2] * s2_; c->xmm[6].f[3] = c->xmm[6].f[3] * s3_; } /* mulps xmm6, xmm4 */
    { float s0_ = RF32((uint32_t)(0x6c8fd0u) + 0); float s1_ = RF32((uint32_t)(0x6c8fd0u) + 4); float s2_ = RF32((uint32_t)(0x6c8fd0u) + 8); float s3_ = RF32((uint32_t)(0x6c8fd0u) + 12); c->xmm[6].f[0] = c->xmm[6].f[0] + s0_; c->xmm[6].f[1] = c->xmm[6].f[1] + s1_; c->xmm[6].f[2] = c->xmm[6].f[2] + s2_; c->xmm[6].f[3] = c->xmm[6].f[3] + s3_; } /* addps xmm6, xmmword ptr [0x10038fd0] */
    c->xmm[1] = c->xmm[0]; /* movaps xmm1, xmm0 */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    { uint32_t s0_ = c->xmm[5].u[0]; uint32_t s1_ = c->xmm[5].u[1]; uint32_t s2_ = c->xmm[5].u[2]; uint32_t s3_ = c->xmm[5].u[3]; c->xmm[1].u[0] = ~c->xmm[1].u[0] & s0_; c->xmm[1].u[1] = ~c->xmm[1].u[1] & s1_; c->xmm[1].u[2] = ~c->xmm[1].u[2] & s2_; c->xmm[1].u[3] = ~c->xmm[1].u[3] & s3_; } /* andnps xmm1, xmm5 */
    { uint32_t s0_ = c->xmm[6].u[0]; uint32_t s1_ = c->xmm[6].u[1]; uint32_t s2_ = c->xmm[6].u[2]; uint32_t s3_ = c->xmm[6].u[3]; c->xmm[2].u[0] = c->xmm[2].u[0] & s0_; c->xmm[2].u[1] = c->xmm[2].u[1] & s1_; c->xmm[2].u[2] = c->xmm[2].u[2] & s2_; c->xmm[2].u[3] = c->xmm[2].u[3] & s3_; } /* andps xmm2, xmm6 */
    { uint32_t s0_ = c->xmm[2].u[0]; uint32_t s1_ = c->xmm[2].u[1]; uint32_t s2_ = c->xmm[2].u[2]; uint32_t s3_ = c->xmm[2].u[3]; c->xmm[1].u[0] = c->xmm[1].u[0] | s0_; c->xmm[1].u[1] = c->xmm[1].u[1] | s1_; c->xmm[1].u[2] = c->xmm[1].u[2] | s2_; c->xmm[1].u[3] = c->xmm[1].u[3] | s3_; } /* orps xmm1, xmm2 */
    c->xmm[2] = c->xmm[0]; /* movaps xmm2, xmm0 */
    { uint32_t s0_ = c->xmm[5].u[0]; uint32_t s1_ = c->xmm[5].u[1]; uint32_t s2_ = c->xmm[5].u[2]; uint32_t s3_ = c->xmm[5].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] & s0_; c->xmm[0].u[1] = c->xmm[0].u[1] & s1_; c->xmm[0].u[2] = c->xmm[0].u[2] & s2_; c->xmm[0].u[3] = c->xmm[0].u[3] & s3_; } /* andps xmm0, xmm5 */
    { uint32_t s0_ = c->xmm[6].u[0]; uint32_t s1_ = c->xmm[6].u[1]; uint32_t s2_ = c->xmm[6].u[2]; uint32_t s3_ = c->xmm[6].u[3]; c->xmm[2].u[0] = ~c->xmm[2].u[0] & s0_; c->xmm[2].u[1] = ~c->xmm[2].u[1] & s1_; c->xmm[2].u[2] = ~c->xmm[2].u[2] & s2_; c->xmm[2].u[3] = ~c->xmm[2].u[3] & s3_; } /* andnps xmm2, xmm6 */
    { uint32_t s0_ = c->xmm[2].u[0]; uint32_t s1_ = c->xmm[2].u[1]; uint32_t s2_ = c->xmm[2].u[2]; uint32_t s3_ = c->xmm[2].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] | s0_; c->xmm[0].u[1] = c->xmm[0].u[1] | s1_; c->xmm[0].u[2] = c->xmm[0].u[2] | s2_; c->xmm[0].u[3] = c->xmm[0].u[3] | s3_; } /* orps xmm0, xmm2 */
    { uint32_t s0_ = c->xmm[7].u[0]; uint32_t s1_ = c->xmm[7].u[1]; uint32_t s2_ = c->xmm[7].u[2]; uint32_t s3_ = c->xmm[7].u[3]; c->xmm[0].u[0] = c->xmm[0].u[0] ^ s0_; c->xmm[0].u[1] = c->xmm[0].u[1] ^ s1_; c->xmm[0].u[2] = c->xmm[0].u[2] ^ s2_; c->xmm[0].u[3] = c->xmm[0].u[3] ^ s3_; } /* xorps xmm0, xmm7 */
    { uint32_t s0_ = c->xmm[3].u[0]; uint32_t s1_ = c->xmm[3].u[1]; uint32_t s2_ = c->xmm[3].u[2]; uint32_t s3_ = c->xmm[3].u[3]; c->xmm[1].u[0] = c->xmm[1].u[0] ^ s0_; c->xmm[1].u[1] = c->xmm[1].u[1] ^ s1_; c->xmm[1].u[2] = c->xmm[1].u[2] ^ s2_; c->xmm[1].u[3] = c->xmm[1].u[3] ^ s3_; } /* xorps xmm1, xmm3 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edx, dword ptr [ebp + 0x10] */
    memcpy(HP((uint32_t)(c->eax)), c->xmm[1].b, 16); /* movaps xmmword ptr [eax], xmm1 */
    memcpy(HP((uint32_t)(c->edx)), c->xmm[0].b, 16); /* movaps xmmword ptr [edx], xmm0 */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006ae179(CPU *c) { /* PTR_006ae179 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)((uint32_t)(c->esi)); /* lea esi, [esi] */
    { uint32_t v_ = R32((uint32_t)(0x6c91d8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [0x100391d8] */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x100391dc] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[0], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[7], a_, 8); } /* pand mm7, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91e8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [0x100391e8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[0], 8); v_cmp(a_, b_, 8, 4, 1); memcpy(&c->mm[6], a_, 8); } /* pcmpgtd mm6, mm0 */
    guest_trap(c, 0x006ae19eu, "unsupported: pfrcp mm2, mm0"); /* pfrcp mm2, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ae1a5u, "unsupported: pfrcpit1 mm0, mm2"); /* pfrcpit1 mm0, mm2 */
    { uint32_t v_ = R32((uint32_t)(0x6c9210u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [0x10039210] */
    guest_trap(c, 0x006ae1b0u, "unsupported: pfrcpit2 mm0, mm2"); /* pfrcpit2 mm0, mm2 */
    { uint32_t v_ = R32((uint32_t)(0x6c921cu)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x1003921c] */
    guest_trap(c, 0x006ae1bbu, "unsupported: pfmin mm0, mm1"); /* pfmin mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ae1c2u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9218u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039218] */
    guest_trap(c, 0x006ae1cdu, "unsupported: pfadd mm3, mm0"); /* pfadd mm3, mm0 */
    guest_trap(c, 0x006ae1d1u, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c920cu)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x1003920c] */
    guest_trap(c, 0x006ae1dcu, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    guest_trap(c, 0x006ae1e0u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint32_t v_ = R32((uint32_t)(0x6c9214u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039214] */
    guest_trap(c, 0x006ae1ebu, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    guest_trap(c, 0x006ae1efu, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9208u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039208] */
    guest_trap(c, 0x006ae1fau, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    guest_trap(c, 0x006ae1feu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006ae202u, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    guest_trap(c, 0x006ae206u, "unsupported: pfmul mm0, mm4"); /* pfmul mm0, mm4 */
    guest_trap(c, 0x006ae20au, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    guest_trap(c, 0x006ae20eu, "unsupported: pfrcp mm5, mm3"); /* pfrcp mm5, mm3 */
    { uint32_t v_ = R32((uint32_t)(0x6c9234u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x10039234] */
    guest_trap(c, 0x006ae219u, "unsupported: pfrcpit1 mm3, mm5"); /* pfrcpit1 mm3, mm5 */
    guest_trap(c, 0x006ae21du, "unsupported: pfrcpit2 mm3, mm5"); /* pfrcpit2 mm3, mm5 */
    guest_trap(c, 0x006ae221u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    guest_trap(c, 0x006ae225u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    guest_trap(c, 0x006ae229u, "unsupported: pfsub mm4, mm0"); /* pfsub mm4, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[4], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[6], a_, 8); } /* pandn mm6, mm4 */
    guest_trap(c, 0x006ae230u, "unsupported: pfmax mm0, mm6"); /* pfmax mm0, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm7 */
    c->esp += 4; return; /* ret  */
}

void f_006ae240(CPU *c) { /* FUN_1001e240 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x6c91d8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [0x100391d8] */
    { uint32_t v_ = R32((uint32_t)(0x6c91d8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [0x100391d8] */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x100391dc] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[0], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[7], a_, 8); } /* pand mm7, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[6], a_, 8); } /* pand mm6, mm1 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 1u, 8, 4, 1); memcpy(&c->mm[7], a_, 8); } /* psrld mm7, 1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[6], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[7], a_, 8); } /* por mm7, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[0], 8); v_cmp(a_, b_, 8, 4, 1); memcpy(&c->mm[6], a_, 8); } /* pcmpgtd mm6, mm0 */
    guest_trap(c, 0x006ae271u, "unsupported: pfmax mm0, mm1"); /* pfmax mm0, mm1 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[6], 8); v_shift(a_, 31u, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* pslld mm6, 0x1f */
    guest_trap(c, 0x006ae279u, "unsupported: pfmin mm1, mm2"); /* pfmin mm1, mm2 */
    guest_trap(c, 0x006ae27du, "unsupported: pfrcp mm2, mm0"); /* pfrcp mm2, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9218u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039218] */
    guest_trap(c, 0x006ae288u, "unsupported: pfrcpit1 mm0, mm2"); /* pfrcpit1 mm0, mm2 */
    { uint32_t v_ = R32((uint32_t)(0x6c921cu)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x1003921c] */
    guest_trap(c, 0x006ae293u, "unsupported: pfrcpit2 mm0, mm2"); /* pfrcpit2 mm0, mm2 */
    { uint32_t v_ = R32((uint32_t)(0x6c9210u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [0x10039210] */
    guest_trap(c, 0x006ae29eu, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ae2a5u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    guest_trap(c, 0x006ae2a9u, "unsupported: pfadd mm3, mm0"); /* pfadd mm3, mm0 */
    guest_trap(c, 0x006ae2adu, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c920cu)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x1003920c] */
    guest_trap(c, 0x006ae2b8u, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    guest_trap(c, 0x006ae2bcu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint32_t v_ = R32((uint32_t)(0x6c9214u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039214] */
    guest_trap(c, 0x006ae2c7u, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    guest_trap(c, 0x006ae2cbu, "unsupported: pfmul mm4, mm0"); /* pfmul mm4, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9208u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039208] */
    guest_trap(c, 0x006ae2d6u, "unsupported: pfmul mm3, mm0"); /* pfmul mm3, mm0 */
    guest_trap(c, 0x006ae2dau, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    guest_trap(c, 0x006ae2deu, "unsupported: pfadd mm3, mm2"); /* pfadd mm3, mm2 */
    guest_trap(c, 0x006ae2e2u, "unsupported: pfmul mm0, mm4"); /* pfmul mm0, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm7 */
    guest_trap(c, 0x006ae2e9u, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    guest_trap(c, 0x006ae2edu, "unsupported: pfrcp mm5, mm3"); /* pfrcp mm5, mm3 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 1u, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* pslld mm7, 1 */
    guest_trap(c, 0x006ae2f5u, "unsupported: pfrcpit1 mm3, mm5"); /* pfrcpit1 mm3, mm5 */
    guest_trap(c, 0x006ae2f9u, "unsupported: pfrcpit2 mm3, mm5"); /* pfrcpit2 mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[6], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm6 */
    guest_trap(c, 0x006ae303u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    { uint32_t v_ = R32((uint32_t)(0x6c9238u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [0x10039238] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[5], a_, 8); } /* pxor mm5, mm3 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[6], 8); v_shift(a_, 31u, 8, 4, 2); memcpy(&c->mm[6], a_, 8); } /* psrad mm6, 0x1f */
    guest_trap(c, 0x006ae315u, "unsupported: pfadd mm0, mm1"); /* pfadd mm0, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[6], a_, 8); } /* pandn mm6, mm5 */
    { uint32_t v_ = R32((uint32_t)(0x6c91d8u)); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, dword ptr [0x100391d8] */
    guest_trap(c, 0x006ae323u, "unsupported: pfsub mm6, mm3"); /* pfsub mm6, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[4], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[1], a_, 8); } /* pand mm1, mm4 */
    guest_trap(c, 0x006ae32du, "unsupported: pfadd mm0, mm6"); /* pfadd mm0, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm1 */
    c->esp += 4; return; /* ret  */
}

void f_006ae340(CPU *c) { /* FUN_1001e340 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x6c91d8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [0x100391d8] */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [0x100391dc] */
    { uint32_t v_ = R32((uint32_t)(0x6c91ecu)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x100391ec] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[0], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[6], a_, 8); } /* pand mm6, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91e8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x100391e8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[5], 8); v_cmp(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* pcmpgtd mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006ae36bu, "unsupported: pfmul mm0, mm4"); /* pfmul mm0, mm4 */
    { uint32_t v_ = R32((uint32_t)(0x6c9220u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039220] */
    guest_trap(c, 0x006ae376u, "unsupported: pfsubr mm0, mm4"); /* pfsubr mm0, mm4 */
    guest_trap(c, 0x006ae37au, "unsupported: pfrsqrt mm7, mm0"); /* pfrsqrt mm7, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm7 */
    guest_trap(c, 0x006ae381u, "unsupported: pfmul mm7, mm7"); /* pfmul mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[5], 8); v_cmp(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* pcmpgtd mm2, mm5 */
    guest_trap(c, 0x006ae388u, "unsupported: pfrsqit1 mm7, mm0"); /* pfrsqit1 mm7, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9230u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x10039230] */
    guest_trap(c, 0x006ae393u, "unsupported: pfrcpit2 mm7, mm1"); /* pfrcpit2 mm7, mm1 */
    guest_trap(c, 0x006ae397u, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[2], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[5], a_, 8); } /* pand mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[0], a_, 8); } /* pandn mm0, mm7 */
    { uint32_t v_ = R32((uint32_t)(0x6c9228u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [0x10039228] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ae3b1u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9224u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039224] */
    guest_trap(c, 0x006ae3bcu, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    guest_trap(c, 0x006ae3c0u, "unsupported: pfadd mm4, mm0"); /* pfadd mm4, mm0 */
    guest_trap(c, 0x006ae3c4u, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    { uint32_t v_ = R32((uint32_t)(0x6c922cu)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x1003922c] */
    guest_trap(c, 0x006ae3cfu, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    guest_trap(c, 0x006ae3d3u, "unsupported: pfmul mm0, mm4"); /* pfmul mm0, mm4 */
    guest_trap(c, 0x006ae3d7u, "unsupported: pfadd mm0, mm5"); /* pfadd mm0, mm5 */
    guest_trap(c, 0x006ae3dbu, "unsupported: pfmul mm7, mm1"); /* pfmul mm7, mm1 */
    guest_trap(c, 0x006ae3dfu, "unsupported: pfrcp mm4, mm0"); /* pfrcp mm4, mm0 */
    guest_trap(c, 0x006ae3e3u, "unsupported: pfrcpit1 mm0, mm4"); /* pfrcpit1 mm0, mm4 */
    { uint32_t v_ = R32((uint32_t)(0x6c9238u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039238] */
    guest_trap(c, 0x006ae3eeu, "unsupported: pfrcpit2 mm0, mm4"); /* pfrcpit2 mm0, mm4 */
    guest_trap(c, 0x006ae3f2u, "unsupported: pfmul mm0, mm7"); /* pfmul mm0, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[2], a_, 8); } /* pandn mm2, mm5 */
    { uint32_t v_ = R32((uint32_t)(0x6c9234u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039234] */
    { uint64_t v_; memcpy(&v_, &c->mm[4], 8); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[6], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[2], a_, 8); } /* pxor mm2, mm6 */
    guest_trap(c, 0x006ae409u, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91f4u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [0x100391f4] */
    guest_trap(c, 0x006ae414u, "unsupported: pfadd mm2, mm5"); /* pfadd mm2, mm5 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[7], 8); v_shift(a_, 31u, 8, 4, 0); memcpy(&c->mm[7], a_, 8); } /* pslld mm7, 0x1f */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[4], a_, 8); } /* pandn mm4, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[7], 8); memcpy(b_, &c->mm[6], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[7], a_, 8); } /* pxor mm7, mm6 */
    guest_trap(c, 0x006ae422u, "unsupported: pfadd mm1, mm4"); /* pfadd mm1, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[1], a_, 8); } /* por mm1, mm7 */
    guest_trap(c, 0x006ae42cu, "unsupported: pfadd mm2, mm1"); /* pfadd mm2, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[2], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[3], a_, 8); } /* pandn mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm3 */
    c->esp += 4; return; /* ret  */
}

void f_006ae437(CPU *c) { /* PTR_006ae437 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)((uint32_t)(c->esp)); /* lea esp, [esp] */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
    { uint32_t v_ = R32((uint32_t)(0x6c91d8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 4); } /* movd mm6, dword ptr [0x100391d8] */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [0x100391dc] */
    { uint32_t v_ = R32((uint32_t)(0x6c91ecu)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x100391ec] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[0], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[6], a_, 8); } /* pand mm6, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91e8u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x100391e8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[5], 8); v_cmp(a_, b_, 8, 4, 1); memcpy(&c->mm[3], a_, 8); } /* pcmpgtd mm3, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm0 */
    guest_trap(c, 0x006ae46bu, "unsupported: pfmul mm0, mm4"); /* pfmul mm0, mm4 */
    { uint32_t v_ = R32((uint32_t)(0x6c9220u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039220] */
    guest_trap(c, 0x006ae476u, "unsupported: pfsubr mm0, mm4"); /* pfsubr mm0, mm4 */
    guest_trap(c, 0x006ae47au, "unsupported: pfrsqrt mm7, mm0"); /* pfrsqrt mm7, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[7], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm7 */
    guest_trap(c, 0x006ae481u, "unsupported: pfmul mm7, mm7"); /* pfmul mm7, mm7 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[5], 8); v_cmp(a_, b_, 8, 4, 1); memcpy(&c->mm[2], a_, 8); } /* pcmpgtd mm2, mm5 */
    guest_trap(c, 0x006ae488u, "unsupported: pfrsqit1 mm7, mm0"); /* pfrsqit1 mm7, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9230u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x10039230] */
    guest_trap(c, 0x006ae493u, "unsupported: pfrcpit2 mm7, mm1"); /* pfrcpit2 mm7, mm1 */
    guest_trap(c, 0x006ae497u, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    { uint64_t v_; memcpy(&v_, &c->mm[2], 8); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 8); } /* movq mm0, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[2], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[5], a_, 8); } /* pand mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[7], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[0], a_, 8); } /* pandn mm0, mm7 */
    { uint32_t v_ = R32((uint32_t)(0x6c9228u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 4); } /* movd mm7, dword ptr [0x10039228] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm5 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ae4b1u, "unsupported: pfmul mm0, mm0"); /* pfmul mm0, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c9224u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x10039224] */
    guest_trap(c, 0x006ae4bcu, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    guest_trap(c, 0x006ae4c0u, "unsupported: pfadd mm4, mm0"); /* pfadd mm4, mm0 */
    guest_trap(c, 0x006ae4c4u, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    { uint32_t v_ = R32((uint32_t)(0x6c922cu)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 4); } /* movd mm5, dword ptr [0x1003922c] */
    guest_trap(c, 0x006ae4cfu, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    guest_trap(c, 0x006ae4d3u, "unsupported: pfmul mm0, mm4"); /* pfmul mm0, mm4 */
    guest_trap(c, 0x006ae4d7u, "unsupported: pfadd mm0, mm5"); /* pfadd mm0, mm5 */
    guest_trap(c, 0x006ae4dbu, "unsupported: pfmul mm7, mm1"); /* pfmul mm7, mm1 */
    guest_trap(c, 0x006ae4dfu, "unsupported: pfrcp mm4, mm0"); /* pfrcp mm4, mm0 */
    guest_trap(c, 0x006ae4e3u, "unsupported: pfrcpit1 mm0, mm4"); /* pfrcpit1 mm0, mm4 */
    guest_trap(c, 0x006ae4e7u, "unsupported: pfrcpit2 mm0, mm4"); /* pfrcpit2 mm0, mm4 */
    { uint32_t v_ = R32((uint32_t)(0x6c9234u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 4); } /* movd mm4, dword ptr [0x10039234] */
    guest_trap(c, 0x006ae4f2u, "unsupported: pfmul mm7, mm0"); /* pfmul mm7, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91f4u)); memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, dword ptr [0x100391f4] */
    guest_trap(c, 0x006ae4fdu, "unsupported: pfadd mm1, mm7"); /* pfadd mm1, mm7 */
    { uint64_t v_; memcpy(&v_, &c->mm[1], 8); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, mm1 */
    guest_trap(c, 0x006ae504u, "unsupported: pfadd mm1, mm1"); /* pfadd mm1, mm1 */
    guest_trap(c, 0x006ae508u, "unsupported: pfsubr mm1, mm4"); /* pfsubr mm1, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[2], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[5], a_, 8); } /* pand mm5, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[2], a_, 8); } /* pandn mm2, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm3 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[5], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[2], a_, 8); } /* por mm2, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[6], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[2], a_, 8); } /* por mm2, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[3], 8); memcpy(b_, &c->mm[2], 8); v_logic(a_, b_, 8, 1); memcpy(&c->mm[3], a_, 8); } /* pandn mm3, mm2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 2); memcpy(&c->mm[0], a_, 8); } /* por mm0, mm3 */
    c->esp += 4; return; /* ret  */
}

void f_006ae920(CPU *c) { /* FUN_1001e920 */
    PREEMPT_POLL(c);
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); c->eax = (uint32_t)(v_); } /* movd eax, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [0x100391dc] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm3 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000000u))); /* and ebx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, 31)); /* shr edx, 0x1f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->ebx))); /* xor eax, ebx */
    { uint32_t v_ = R32((uint32_t)(0x6c9290u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039290] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006ae946u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91a0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x100391a0] */
    guest_trap(c, 0x006ae951u, "unsupported: pf2id mm0, mm0"); /* pf2id mm0, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91a8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [0x100391a8] */
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); c->ecx = (uint32_t)(v_); } /* movd ecx, mm0 */
    guest_trap(c, 0x006ae95fu, "unsupported: pi2fd mm0, mm0"); /* pi2fd mm0, mm0 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91b8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [0x100391b8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c9158u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [0x10039158] */
    guest_trap(c, 0x006ae976u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91b0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x100391b0] */
    guest_trap(c, 0x006ae981u, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    c->esi = (uint32_t)(shr32(c, c->esi, 2)); /* shr esi, 2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[0], a_, 8); } /* punpckhdq mm0, mm0 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx ^ c->esi))); /* xor edx, esi */
    guest_trap(c, 0x006ae98du, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u)); /* test ecx, 1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    if (c->zf) goto L_006ae9a0; /* je 0x6ae9a0 */
    guest_trap(c, 0x006ae99cu, "unsupported: pfsubr mm1, mm3"); /* pfsubr mm1, mm3 */
L_006ae9a0:;
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm5 */
    c->edx = (uint32_t)(shl32(c, c->edx, 31)); /* shl edx, 0x1f */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm1 */
    guest_trap(c, 0x006ae9a9u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91c0u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [0x100391c0] */
    c->esi = (uint32_t)(shr32(c, c->esi, 1)); /* shr esi, 1 */
    guest_trap(c, 0x006ae9b8u, "unsupported: pfmul mm7, mm1"); /* pfmul mm7, mm1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->esi))); /* xor ecx, esi */
    guest_trap(c, 0x006ae9beu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    c->esi = (uint32_t)(shl32(c, c->esi, 31)); /* shl esi, 0x1f */
    guest_trap(c, 0x006ae9c5u, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx ^ c->esi))); /* xor ebx, esi */
    guest_trap(c, 0x006ae9cbu, "unsupported: pfmul mm4, mm1"); /* pfmul mm4, mm1 */
    guest_trap(c, 0x006ae9cfu, "unsupported: pfmul mm7, mm6"); /* pfmul mm7, mm6 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91c8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [0x100391c8] */
    guest_trap(c, 0x006ae9dau, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    guest_trap(c, 0x006ae9deu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006ae9e2u, "unsupported: pfmul mm4, mm7"); /* pfmul mm4, mm7 */
    { uint32_t v_ = c->edx; memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, edx */
    guest_trap(c, 0x006ae9e9u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm5 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[5], 8); v_shift(a_, 32u, 8, 8, 1); memcpy(&c->mm[5], a_, 8); } /* psrlq mm5, 0x20 */
    guest_trap(c, 0x006ae9f4u, "unsupported: pfmul mm4, mm6"); /* pfmul mm4, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint32_t v_ = c->ebx; memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, ebx */
    guest_trap(c, 0x006ae9feu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u)); /* test ecx, 1 */
    guest_trap(c, 0x006aea08u, "unsupported: pfmul mm4, mm2"); /* pfmul mm4, mm2 */
    if (c->zf) goto L_006aea14; /* je 0x6aea14 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[4], a_, 8); } /* punpckhdq mm4, mm5 */
L_006aea14:;
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[4], a_, 8); } /* pxor mm4, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[4], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, mm4 */
    ; /* nop  */
    c->esp += 4; return; /* ret  */
}

void f_006aea20(CPU *c) { /* FUN_1001ea20 */
    PREEMPT_POLL(c);
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); c->eax = (uint32_t)(v_); } /* movd eax, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [0x100391dc] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm3 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000000u))); /* and ebx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, 31)); /* shr edx, 0x1f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->ebx))); /* xor eax, ebx */
    { uint32_t v_ = R32((uint32_t)(0x6c9290u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039290] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006aea46u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91a0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x100391a0] */
    guest_trap(c, 0x006aea51u, "unsupported: pf2id mm0, mm0"); /* pf2id mm0, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91a8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [0x100391a8] */
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); c->ecx = (uint32_t)(v_); } /* movd ecx, mm0 */
    guest_trap(c, 0x006aea5fu, "unsupported: pi2fd mm0, mm0"); /* pi2fd mm0, mm0 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91b8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [0x100391b8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c9158u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [0x10039158] */
    guest_trap(c, 0x006aea76u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91b0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x100391b0] */
    guest_trap(c, 0x006aea81u, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    c->esi = (uint32_t)(shr32(c, c->esi, 2)); /* shr esi, 2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[0], a_, 8); } /* punpckhdq mm0, mm0 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx ^ c->esi))); /* xor edx, esi */
    guest_trap(c, 0x006aea8du, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u)); /* test ecx, 1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    if (c->zf) goto L_006aeaa0; /* je 0x6aeaa0 */
    guest_trap(c, 0x006aea9cu, "unsupported: pfsubr mm1, mm3"); /* pfsubr mm1, mm3 */
L_006aeaa0:;
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm5 */
    c->edx = (uint32_t)(shl32(c, c->edx, 31)); /* shl edx, 0x1f */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm1 */
    guest_trap(c, 0x006aeaa9u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91c0u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [0x100391c0] */
    c->esi = (uint32_t)(shr32(c, c->esi, 1)); /* shr esi, 1 */
    guest_trap(c, 0x006aeab8u, "unsupported: pfmul mm7, mm1"); /* pfmul mm7, mm1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->esi))); /* xor ecx, esi */
    guest_trap(c, 0x006aeabeu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    c->esi = (uint32_t)(shl32(c, c->esi, 31)); /* shl esi, 0x1f */
    guest_trap(c, 0x006aeac5u, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx ^ c->esi))); /* xor ebx, esi */
    guest_trap(c, 0x006aeacbu, "unsupported: pfmul mm4, mm1"); /* pfmul mm4, mm1 */
    guest_trap(c, 0x006aeacfu, "unsupported: pfmul mm7, mm6"); /* pfmul mm7, mm6 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91c8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [0x100391c8] */
    guest_trap(c, 0x006aeadau, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    guest_trap(c, 0x006aeadeu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006aeae2u, "unsupported: pfmul mm4, mm7"); /* pfmul mm4, mm7 */
    { uint32_t v_ = c->edx; memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, edx */
    guest_trap(c, 0x006aeae9u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm5 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[5], 8); v_shift(a_, 32u, 8, 8, 1); memcpy(&c->mm[5], a_, 8); } /* psrlq mm5, 0x20 */
    guest_trap(c, 0x006aeaf4u, "unsupported: pfmul mm4, mm6"); /* pfmul mm4, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint32_t v_ = c->ebx; memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, ebx */
    guest_trap(c, 0x006aeafeu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u)); /* test ecx, 1 */
    guest_trap(c, 0x006aeb08u, "unsupported: pfmul mm4, mm2"); /* pfmul mm4, mm2 */
    if (c->zf) goto L_006aeb14; /* je 0x6aeb14 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[4], a_, 8); } /* punpckhdq mm4, mm5 */
L_006aeb14:;
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[4], a_, 8); } /* pxor mm4, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[4], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[0], a_, 8); } /* punpckhdq mm0, mm0 */
    c->esp += 4; return; /* ret  */
}

void f_006aeb1e(CPU *c) { /* PTR_006aeb1e */
    PREEMPT_POLL(c);
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); c->eax = (uint32_t)(v_); } /* movd eax, mm0 */
    { uint32_t v_ = R32((uint32_t)(0x6c91dcu)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 4); } /* movd mm3, dword ptr [0x100391dc] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[3], 8); v_logic(a_, b_, 8, 0); memcpy(&c->mm[0], a_, 8); } /* pand mm0, mm3 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x80000000u))); /* and ebx, 0x80000000 */
    c->edx = (uint32_t)(shr32(c, c->edx, 31)); /* shr edx, 0x1f */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->ebx))); /* xor eax, ebx */
    { uint32_t v_ = R32((uint32_t)(0x6c9290u)); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 4); } /* movd mm2, dword ptr [0x10039290] */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006aeb46u, "unsupported: pfmul mm0, mm2"); /* pfmul mm0, mm2 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91a0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x100391a0] */
    guest_trap(c, 0x006aeb51u, "unsupported: pf2id mm0, mm0"); /* pf2id mm0, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91a8u)); memset(&c->mm[7], 0, 8); memcpy(&c->mm[7], &v_, 8); } /* movq mm7, qword ptr [0x100391a8] */
    { uint32_t v_; memcpy(&v_, &c->mm[0], 4); c->ecx = (uint32_t)(v_); } /* movd ecx, mm0 */
    guest_trap(c, 0x006aeb5fu, "unsupported: pi2fd mm0, mm0"); /* pi2fd mm0, mm0 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91b8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [0x100391b8] */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c9158u)); memset(&c->mm[5], 0, 8); memcpy(&c->mm[5], &v_, 8); } /* movq mm5, qword ptr [0x10039158] */
    guest_trap(c, 0x006aeb76u, "unsupported: pfmul mm0, mm3"); /* pfmul mm0, mm3 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91b0u)); memset(&c->mm[3], 0, 8); memcpy(&c->mm[3], &v_, 8); } /* movq mm3, qword ptr [0x100391b0] */
    guest_trap(c, 0x006aeb81u, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    c->esi = (uint32_t)(shr32(c, c->esi, 2)); /* shr esi, 2 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[0], a_, 8); } /* punpckhdq mm0, mm0 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx ^ c->esi))); /* xor edx, esi */
    guest_trap(c, 0x006aeb8du, "unsupported: pfadd mm1, mm0"); /* pfadd mm1, mm0 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u)); /* test ecx, 1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[1], a_, 8); } /* punpckldq mm1, mm1 */
    if (c->zf) goto L_006aeba0; /* je 0x6aeba0 */
    guest_trap(c, 0x006aeb9cu, "unsupported: pfsubr mm1, mm3"); /* pfsubr mm1, mm3 */
L_006aeba0:;
    { uint64_t v_; memcpy(&v_, &c->mm[5], 8); memset(&c->mm[2], 0, 8); memcpy(&c->mm[2], &v_, 8); } /* movq mm2, mm5 */
    c->edx = (uint32_t)(shl32(c, c->edx, 31)); /* shl edx, 0x1f */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[2], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[2], a_, 8); } /* punpckldq mm2, mm1 */
    guest_trap(c, 0x006aeba9u, "unsupported: pfmul mm1, mm1"); /* pfmul mm1, mm1 */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91c0u)); memset(&c->mm[4], 0, 8); memcpy(&c->mm[4], &v_, 8); } /* movq mm4, qword ptr [0x100391c0] */
    c->esi = (uint32_t)(shr32(c, c->esi, 1)); /* shr esi, 1 */
    guest_trap(c, 0x006aebb8u, "unsupported: pfmul mm7, mm1"); /* pfmul mm7, mm1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx ^ c->esi))); /* xor ecx, esi */
    guest_trap(c, 0x006aebbeu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    c->esi = (uint32_t)(shl32(c, c->esi, 31)); /* shl esi, 0x1f */
    guest_trap(c, 0x006aebc5u, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx ^ c->esi))); /* xor ebx, esi */
    guest_trap(c, 0x006aebcbu, "unsupported: pfmul mm4, mm1"); /* pfmul mm4, mm1 */
    guest_trap(c, 0x006aebcfu, "unsupported: pfmul mm7, mm6"); /* pfmul mm7, mm6 */
    { uint64_t v_; v_ = R64((uint32_t)(0x6c91c8u)); memset(&c->mm[6], 0, 8); memcpy(&c->mm[6], &v_, 8); } /* movq mm6, qword ptr [0x100391c8] */
    guest_trap(c, 0x006aebdau, "unsupported: pfadd mm7, mm5"); /* pfadd mm7, mm5 */
    guest_trap(c, 0x006aebdeu, "unsupported: pfmul mm6, mm1"); /* pfmul mm6, mm1 */
    guest_trap(c, 0x006aebe2u, "unsupported: pfmul mm4, mm7"); /* pfmul mm4, mm7 */
    { uint32_t v_ = c->edx; memset(&c->mm[0], 0, 8); memcpy(&c->mm[0], &v_, 4); } /* movd mm0, edx */
    guest_trap(c, 0x006aebe9u, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[6], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[6], a_, 8); } /* punpckldq mm6, mm5 */
    { uint8_t a_[16]; memcpy(a_, &c->mm[5], 8); v_shift(a_, 32u, 8, 8, 1); memcpy(&c->mm[5], a_, 8); } /* psrlq mm5, 0x20 */
    guest_trap(c, 0x006aebf4u, "unsupported: pfmul mm4, mm6"); /* pfmul mm4, mm6 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[0], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[0], a_, 8); } /* punpckldq mm0, mm0 */
    { uint32_t v_ = c->ebx; memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 4); } /* movd mm1, ebx */
    guest_trap(c, 0x006aebfeu, "unsupported: pfadd mm4, mm5"); /* pfadd mm4, mm5 */
    (void)logic32(c, (uint32_t)(c->ecx & (uint32_t)0x1u)); /* test ecx, 1 */
    guest_trap(c, 0x006aec08u, "unsupported: pfmul mm4, mm2"); /* pfmul mm4, mm2 */
    if (c->zf) goto L_006aec14; /* je 0x6aec14 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[5], 8); memcpy(b_, &c->mm[4], 8); v_unpack(a_, b_, 8, 4, 0); memcpy(&c->mm[5], a_, 8); } /* punpckldq mm5, mm4 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[5], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[4], a_, 8); } /* punpckhdq mm4, mm5 */
L_006aec14:;
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[4], 8); memcpy(b_, &c->mm[1], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[4], a_, 8); } /* pxor mm4, mm1 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[0], 8); memcpy(b_, &c->mm[4], 8); v_logic(a_, b_, 8, 3); memcpy(&c->mm[0], a_, 8); } /* pxor mm0, mm4 */
    { uint64_t v_; memcpy(&v_, &c->mm[0], 8); memset(&c->mm[1], 0, 8); memcpy(&c->mm[1], &v_, 8); } /* movq mm1, mm0 */
    guest_trap(c, 0x006aec1du, "unsupported: pfrcp mm2, mm0"); /* pfrcp mm2, mm0 */
    { uint8_t a_[16], b_[16]; memcpy(a_, &c->mm[1], 8); memcpy(b_, &c->mm[1], 8); v_unpack(a_, b_, 8, 4, 1); memcpy(&c->mm[1], a_, 8); } /* punpckhdq mm1, mm1 */
    guest_trap(c, 0x006aec24u, "unsupported: pfrcpit1 mm0, mm2"); /* pfrcpit1 mm0, mm2 */
    guest_trap(c, 0x006aec28u, "unsupported: pfrcpit2 mm0, mm2"); /* pfrcpit2 mm0, mm2 */
    guest_trap(c, 0x006aec2cu, "unsupported: pfmul mm0, mm1"); /* pfmul mm0, mm1 */
    c->esp += 4; return; /* ret  */
}

void f_006aedd8(CPU *c) { /* FUN_1001edd8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    W32((uint32_t)(c->esi), (uint32_t)((uint32_t)0x6c13d4u)); /* mov dword ptr [esi], 0x100313d4 */
    PUSH32(c, 0x006aede8u); f_006b0d09(c); /* call 0x6b0d09 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006aedf7; /* je 0x6aedf7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006aedf6u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006aedf7:;
    { uint32_t v_ = 0x1bu; PUSH32(c, v_); } /* push 0x1b */
    PUSH32(c, 0x006aedfeu); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006aee01(CPU *c) { /* type_info::vfunc_0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    PUSH32(c, 0x006aee09u); f_006aedd8(c); /* call 0x6aedd8 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x1u)); /* test byte ptr [esp + 8], 1 */
    if (c->zf) goto L_006aee17; /* je 0x6aee17 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006aee16u); f_00692260(c); /* call 0x692260 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006aee17:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006aee1d(CPU *c) { /* FUN_1001ee1d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov edi, dword ptr [esp + 0x14] */
L_006aee25:;
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006aee3d; /* jle 0x6aee3d */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006aee39u); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006aee4c; /* jmp 0x6aee4c */
L_006aee3d:;
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
L_006aee4c:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006aee53; /* je 0x6aee53 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_006aee25; /* jmp 0x6aee25 */
L_006aee53:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub32(c, c->esi, (uint32_t)0x2du); /* cmp esi, 0x2d */
    c->ebp = (uint32_t)(c->esi); /* mov ebp, esi */
    if (c->zf) goto L_006aee63; /* je 0x6aee63 */
    (void)sub32(c, c->esi, (uint32_t)0x2bu); /* cmp esi, 0x2b */
    if (!c->zf) goto L_006aee67; /* jne 0x6aee67 */
L_006aee63:;
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_006aee67:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006aee69:;
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006aee7e; /* jle 0x6aee7e */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006aee7au); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006aee89; /* jmp 0x6aee89 */
L_006aee7e:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov eax, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi * 2))); /* mov al, byte ptr [eax + esi*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_006aee89:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006aee9a; /* je 0x6aee9a */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->ebx * 4)); /* lea eax, [ebx + ebx*4] */
    c->ebx = (uint32_t)((uint32_t)(c->esi + c->eax * 2 + 0xffffffd0u)); /* lea ebx, [esi + eax*2 - 0x30] */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx esi, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_006aee69; /* jmp 0x6aee69 */
L_006aee9a:;
    (void)sub32(c, c->ebp, (uint32_t)0x2du); /* cmp ebp, 0x2d */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    if (!c->zf) goto L_006aeea3; /* jne 0x6aeea3 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_006aeea3:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006aeea8(CPU *c) { /* FUN_1001eea8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006aeeb1u); f_006aee1d(c); /* call 0x6aee1d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006aeeb3(CPU *c) { /* FUN_1001eeb3 */
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
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x006aeedeu); return; } } /* jmp eax */
}

void f_006aeee0(CPU *c) { /* PTR_006aeee0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_006aeee7(CPU *c) { /* FUN_1001eee7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x006aeeecu); return; } } /* jmp eax */
}

void f_006aeeee(CPU *c) { /* FUN_1001eeee */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { guest_lock(); { uint32_t t0_ = R32((uint32_t)(c->esp)), t1_ = c->eax; W32((uint32_t)(c->esp), (uint32_t)(t1_)); c->eax = (uint32_t)(t0_); } guest_unlock(); } /* xchg dword ptr [esp], eax */
    { uint32_t t_ = c->eax; switch (t_) {  default: jump_indirect(c, t_, 0x006aeef3u); return; } } /* jmp eax */
}

void f_006aeef5(CPU *c) { /* FUN_1001eef5 */
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
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x6aef1du)); /* mov dword ptr [ebp - 4], 0x1001ef1d */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 4] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006aef1du); f_006bd120(c); /* call 0x6bd120 */
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

void f_006aef1d(CPU *c) { /* PTR_006aef1d */
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

void f_006aef44(CPU *c) { /* FUN_1001ef44 */
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
    PUSH32(c, 0x006aef6au); f_006b0eb4(c); /* call 0x6b0eb4 */
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

void f_006aef7a(CPU *c) { /* FUN_1001ef7a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x14u)); /* sub esp, 0x14 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x14], 0 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6aefceu)); /* mov dword ptr [ebp - 0x10], 0x1001efce */
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
    PUSH32(c, 0x006aefbfu); f_006b16c0(c); /* call 0x6b16c0 */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006aefce(CPU *c) { /* FUN_1001efce */
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
    PUSH32(c, 0x006aefeeu); f_006b0eb4(c); /* call 0x6b0eb4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006aeff3(CPU *c) { /* FUN_1001eff3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x34u)); /* sub esp, 0x34 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd8u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x28], 0 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x6af0a9u)); /* mov dword ptr [ebp - 0x24], 0x1001f0a9 */
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
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6af07bu)); /* mov dword ptr [ebp - 0x10], 0x1001f07b */
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
    PUSH32(c, 0x006af072u); f_006b1791(c); /* call 0x6b1791 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x68u)); PUSH32(c, 0x006af075u); call_indirect(c, t_); } /* call dword ptr [eax + 0x68] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffccu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x34], 0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_006af098; /* je 0x6af098 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_006af0a1; /* jmp 0x6af0a1 */
L_006af098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_006af0a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006af07b(CPU *c) { /* PTR_006af07b */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    if (c->zf) goto L_006af098; /* je 0x6af098 */
    c->ebx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ebx, dword ptr fs:[0] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov ebx, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ebx)); /* mov dword ptr fs:[0], ebx */
    goto L_006af0a1; /* jmp 0x6af0a1 */
L_006af098:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->eax)); /* mov dword ptr fs:[0], eax */
L_006af0a1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffccu))); /* mov eax, dword ptr [ebp - 0x34] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006af0a9(CPU *c) { /* FUN_1001f0a9 */
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
    if (c->zf) goto L_006af0cc; /* je 0x6af0cc */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->eax + 0x24u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x24], 1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    goto L_006af119; /* jmp 0x6af119 */
L_006af0cc:;
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
    PUSH32(c, 0x006af0f3u); f_006b0eb4(c); /* call 0x6b0eb4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x24u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x24], 0 */
    if (!c->zf) goto L_006af10a; /* jne 0x6af10a */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006af10au); f_006aeef5(c); /* call 0x6aeef5 */
L_006af10a:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ebx, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov esp, dword ptr [ebx + 0x1c] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov ebp, dword ptr [ebx + 0x20] */
    { uint32_t t_ = R32((uint32_t)(c->ebx + 0x18u)); switch (t_) {  default: jump_indirect(c, t_, 0x006af113u); return; } } /* jmp dword ptr [ebx + 0x18] */
L_006af119:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006af11e(CPU *c) { /* FUN_1001f11e */
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
    if ((c->sf != c->of)) goto L_006af175; /* jl 0x6af175 */
L_006af13c:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_006af146; /* jne 0x6af146 */
    PUSH32(c, 0x006af146u); f_006b18f9(c); /* call 0x6b18f9 */
L_006af146:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->eax * 4 + 0x4u)), c->ecx); /* cmp dword ptr [ebx + eax*4 + 4], ecx */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    if ((c->sf == c->of)) goto L_006af15b; /* jge 0x6af15b */
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax + 0x8u))); /* cmp ecx, dword ptr [eax + 8] */
    if ((c->zf || c->sf != c->of)) goto L_006af160; /* jle 0x6af160 */
L_006af15b:;
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_006af16c; /* jne 0x6af16c */
L_006af160:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
L_006af16c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->sf == c->of)) goto L_006af13c; /* jge 0x6af13c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_006af175:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W32((uint32_t)(c->ecx), (uint32_t)(c->esi)); /* mov dword ptr [ecx], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    (void)sub32(c, c->eax, R32((uint32_t)(c->edi + 0xcu))); /* cmp eax, dword ptr [edi + 0xc] */
    if ((!c->cf && !c->zf)) goto L_006af189; /* ja 0x6af189 */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if ((c->cf || c->zf)) goto L_006af18e; /* jbe 0x6af18e */
L_006af189:;
    PUSH32(c, 0x006af18eu); f_006b18f9(c); /* call 0x6b18f9 */
L_006af18e:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 4)); /* lea eax, [esi + esi*4] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->eax = (uint32_t)((uint32_t)(c->ebx + c->eax * 4)); /* lea eax, [ebx + eax*4] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006af19c(CPU *c) { /* __global_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x6af1b4u; PUSH32(c, v_); } /* push 0x1001f1b4 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006af1b4u); f_006bd120(c); /* call 0x6bd120 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006af1b4(CPU *c) { /* PTR_006af1b4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = (uint32_t)(c->ebp); /* mov esp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006af1bc(CPU *c) { /* PTR_006af1bc */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ecx, dword ptr [esp + 4] */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx + 0x4u)) & (uint32_t)0x6u)); /* test dword ptr [ecx + 4], 6 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    if (c->zf) goto L_006af1dd; /* je 0x6af1dd */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edx, dword ptr [esp + 0x10] */
    W32((uint32_t)(c->edx), (uint32_t)(c->eax)); /* mov dword ptr [edx], eax */
    c->eax = (uint32_t)((uint32_t)0x3u); /* mov eax, 3 */
L_006af1dd:;
    c->esp += 4; return; /* ret  */
}

void f_006af1de(CPU *c) { /* __local_unwind2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xfffffffeu; PUSH32(c, v_); } /* push -2 */
    { uint32_t v_ = 0x6af1bcu; PUSH32(c, v_); } /* push 0x1001f1bc */
    { uint32_t v_ = R32((uint32_t)(0x0u + c->fs_base)); PUSH32(c, v_); } /* push dword ptr fs:[0] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
L_006af1fb:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x20u))); /* mov eax, dword ptr [esp + 0x20] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov ebx, dword ptr [eax + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov esi, dword ptr [eax + 0xc] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (c->zf) goto L_006af238; /* je 0x6af238 */
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0x24u))); /* cmp esi, dword ptr [esp + 0x24] */
    if (c->zf) goto L_006af238; /* je 0x6af238 */
    c->esi = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea esi, [esi + esi*2] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4))); /* mov ecx, dword ptr [ebx + esi*4] */
    W32((uint32_t)(c->esp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [esp + 8], ecx */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0xc], ecx */
    (void)sub32(c, R32((uint32_t)(c->ebx + c->esi * 4 + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [ebx + esi*4 + 4], 0 */
    if (!c->zf) goto L_006af236; /* jne 0x6af236 */
    { uint32_t v_ = 0x101u; PUSH32(c, v_); } /* push 0x101 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u))); /* mov eax, dword ptr [ebx + esi*4 + 8] */
    PUSH32(c, 0x006af232u); f_006af272(c); /* call 0x6af272 */
    { uint32_t t_ = R32((uint32_t)(c->ebx + c->esi * 4 + 0x8u)); PUSH32(c, 0x006af236u); call_indirect(c, t_); } /* call dword ptr [ebx + esi*4 + 8] */
L_006af236:;
    goto L_006af1fb; /* jmp 0x6af1fb */
L_006af238:;
    { uint32_t v_ = R32(c->esp); c->esp += 4; W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(v_)); } /* pop dword ptr fs:[0] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006af246(CPU *c) { /* __abnormal_termination */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov ecx, dword ptr fs:[0] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x4u)), (uint32_t)0x6af1bcu); /* cmp dword ptr [ecx + 4], 0x1001f1bc */
    if (!c->zf) goto L_006af268; /* jne 0x6af268 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xcu))); /* mov edx, dword ptr [ecx + 0xc] */
    c->edx = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov edx, dword ptr [edx + 0xc] */
    (void)sub32(c, R32((uint32_t)(c->ecx + 0x8u)), c->edx); /* cmp dword ptr [ecx + 8], edx */
    if (!c->zf) goto L_006af268; /* jne 0x6af268 */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_006af268:;
    c->esp += 4; return; /* ret  */
}

void f_006af269(CPU *c) { /* __NLG_Notify1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x6ca460u); /* mov ebx, 0x1003a460 */
    { f_006af27c(c); return; } /* jmp 0x6af27c */
}

void f_006af272(CPU *c) { /* FUN_1001f272 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->ebx = (uint32_t)((uint32_t)0x6ca460u); /* mov ebx, 0x1003a460 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_006af27c(CPU *c) { /* PTR_006af27c */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebx + 8], ecx */
    W32((uint32_t)(c->ebx + 0x4u), (uint32_t)(c->eax)); /* mov dword ptr [ebx + 4], eax */
    W32((uint32_t)(c->ebx + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [ebx + 0xc], ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 8; return; /* ret 4 */
}

void f_006af28a(CPU *c) { /* __CxxThrowException@8 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)((uint32_t)0x6c13d8u); /* mov esi, 0x100313d8 */
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
    { uint32_t t_ = R32((uint32_t)(0x6be048u)); PUSH32(c, 0x006af2beu); call_indirect(c, t_); } /* call dword ptr [0x1002e048] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 12; return; /* ret 8 */
}

void f_006af2c4(CPU *c) { /* FUN_1001f2c4 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006af2c9u); f_006af2dc(c); /* call 0x6af2dc */
    PUSH32(c, 0x006af2ceu); f_006b1a03(c); /* call 0x6b1a03 */
    W32((uint32_t)(0x6d00ecu), (uint32_t)(c->eax)); /* mov dword ptr [0x100400ec], eax */
    PUSH32(c, 0x006af2d8u); f_006b19b3(c); /* call 0x6b19b3 */
    c->fpu_sw &= 0x7f00; /* fnclex  */
    c->esp += 4; return; /* ret  */
}

void f_006af2db(CPU *c) { /* PTR_006af2db */
    PREEMPT_POLL(c);
    c->esp += 4; return; /* ret  */
}

void f_006af2dc(CPU *c) { /* FUN_1001f2dc */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)0x6b1ddcu); /* mov eax, 0x10021ddc */
    W32((uint32_t)(0x6ca90cu), (uint32_t)((uint32_t)0x6b1a86u)); /* mov dword ptr [0x1003a90c], 0x10021a86 */
    W32((uint32_t)(0x6ca908u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003a908], eax */
    W32((uint32_t)(0x6ca910u), (uint32_t)((uint32_t)0x6b1aecu)); /* mov dword ptr [0x1003a910], 0x10021aec */
    W32((uint32_t)(0x6ca914u), (uint32_t)((uint32_t)0x6b1a2cu)); /* mov dword ptr [0x1003a914], 0x10021a2c */
    W32((uint32_t)(0x6ca918u), (uint32_t)((uint32_t)0x6b1ad4u)); /* mov dword ptr [0x1003a918], 0x10021ad4 */
    W32((uint32_t)(0x6ca91cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1003a91c], eax */
    c->esp += 4; return; /* ret  */
}

void f_006af314(CPU *c) { /* __ftol */
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

void f_006af33b(CPU *c) { /* FUN_1001f33b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x42u)); /* mov dword ptr [ebp - 0x14], 0x42 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006af367u); f_006b1f6a(c); /* call 0x6b1f6a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_006af379; /* js 0x6af379 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_006af386; /* jmp 0x6af386 */
L_006af379:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x006af384u); f_006b1e52(c); /* call 0x6b1e52 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006af386:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006af38b(CPU *c) { /* PTR_006af38b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006af391u); f_006b09d1(c); /* call 0x6b09d1 */
    { uint32_t v_ = R32((uint32_t)(0x6d1830u)); PUSH32(c, v_); } /* push dword ptr [0x10041830] */
    PUSH32(c, 0x006af39cu); f_006b2aa3(c); /* call 0x6b2aa3 */
    c->edx = (uint32_t)(R32((uint32_t)(0x6d1830u))); /* mov edx, dword ptr [0x10041830] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6d182cu))); /* mov ecx, dword ptr [0x1004182c] */
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->esi = (uint32_t)(sub32(c, c->esi, c->edx)); /* sub esi, edx */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->cf) goto L_006af3f1; /* jae 0x6af3f1 */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x006af3bau); f_006b2aa3(c); /* call 0x6b2aa3 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x10u)); /* add eax, 0x10 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(0x6d1830u)); PUSH32(c, v_); } /* push dword ptr [0x10041830] */
    PUSH32(c, 0x006af3c9u); f_006b2774(c); /* call 0x6b2774 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006af3d4; /* jne 0x6af3d4 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_006af400; /* jmp 0x6af400 */
L_006af3d4:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x6d182cu))); /* mov ecx, dword ptr [0x1004182c] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(0x6d1830u)))); /* sub ecx, dword ptr [0x10041830] */
    W32((uint32_t)(0x6d1830u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041830], eax */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 2)); /* sar ecx, 2 */
    c->ecx = (uint32_t)((uint32_t)(c->eax + c->ecx * 4)); /* lea ecx, [eax + ecx*4] */
    W32((uint32_t)(0x6d182cu), (uint32_t)(c->ecx)); /* mov dword ptr [0x1004182c], ecx */
L_006af3f1:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    W32((uint32_t)(c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [ecx], eax */
    { uint32_t a_ = (uint32_t)(0x6d182cu); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [0x1004182c], 4 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006af400:;
    PUSH32(c, 0x006af405u); f_006b09da(c); /* call 0x6b09da */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006af409(CPU *c) { /* PTR_006af409 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006af412u); f_006af38b(c); /* call 0x6af38b */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->esp += 4; return; /* ret  */
}

void f_006af41b(CPU *c) { /* PTR_006af41b */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x80u; PUSH32(c, v_); } /* push 0x80 */
    PUSH32(c, 0x006af425u); f_006b09fd(c); /* call 0x6b09fd */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x6d1830u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041830], eax */
    if (!c->zf) goto L_006af43c; /* jne 0x6af43c */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x006af436u); f_006afd31(c); /* call 0x6afd31 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d1830u))); /* mov eax, dword ptr [0x10041830] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006af43c:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [eax], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d1830u))); /* mov eax, dword ptr [0x10041830] */
    W32((uint32_t)(0x6d182cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1004182c], eax */
    c->esp += 4; return; /* ret  */
}

void f_006af44a(CPU *c) { /* FUN_1001f44a */
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
    PUSH32(c, 0x006af478u); f_006b1f6a(c); /* call 0x6b1f6a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_006af48a; /* js 0x6af48a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_006af497; /* jmp 0x6af497 */
L_006af48a:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x006af495u); f_006b1e52(c); /* call 0x6b1e52 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006af497:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006af4a0(CPU *c) { /* FUN_1001f4a0 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006af51a; /* je 0x6af51a */
    c->edx = (c->edx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x1u))) << 8); /* mov dh, byte ptr [ecx + 1] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_006af507; /* je 0x6af507 */
L_006af4b8:;
    c->esi = (uint32_t)(c->edi); /* mov esi, edi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ecx, dword ptr [esp + 0x14] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_006af4da; /* je 0x6af4da */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006af4d4; /* je 0x6af4d4 */
L_006af4c9:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006af4cc:;
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->edx)); /* cmp al, dl */
    if (c->zf) goto L_006af4da; /* je 0x6af4da */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_006af4c9; /* jne 0x6af4c9 */
L_006af4d4:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006af4da:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->edx >> 8))); /* cmp al, dh */
    if (!c->zf) goto L_006af4cc; /* jne 0x6af4cc */
    c->edi = (uint32_t)((uint32_t)(c->esi + 0xffffffffu)); /* lea edi, [esi - 1] */
L_006af4e4:;
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->ecx + 0x2u))) << 8); /* mov ah, byte ptr [ecx + 2] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006af513; /* je 0x6af513 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x2u)); /* add esi, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (!c->zf) goto L_006af4b8; /* jne 0x6af4b8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + 0x3u))); /* mov al, byte ptr [ecx + 3] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006af513; /* je 0x6af513 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esi + 0xffffffffu))) << 8); /* mov ah, byte ptr [esi - 1] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)(c->eax >> 8))); /* cmp al, ah */
    if (c->zf) goto L_006af4e4; /* je 0x6af4e4 */
    goto L_006af4b8; /* jmp 0x6af4b8 */
L_006af507:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->edx)); /* mov al, dl */
    { f_006b2bb6(c); return; } /* jmp 0x6b2bb6 */
L_006af513:;
    c->eax = (uint32_t)((uint32_t)(c->edi + 0xffffffffu)); /* lea eax, [edi - 1] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006af51a:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006af520(CPU *c) { /* FUN_1001f520 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006af526u); f_006b2f3c(c); /* call 0x6b2f3c */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006af52e; /* jne 0x6af52e */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006af52e:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    PUSH32(c, 0x006af541u); f_006b2dcc(c); /* call 0x6b2dcc */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    PUSH32(c, 0x006af549u); f_006b2d7a(c); /* call 0x6b2d7a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006af551(CPU *c) { /* FUN_1001f551 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x40u; PUSH32(c, v_); } /* push 0x40 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006af560u); f_006af520(c); /* call 0x6af520 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006af570(CPU *c) { /* _strncpy */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006af5f3; /* je 0x6af5f3 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov esi, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_006af594; /* jne 0x6af594 */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_006af601; /* jne 0x6af601 */
    goto L_006af5b5; /* jmp 0x6af5b5 */
L_006af594:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_006af5c2; /* je 0x6af5c2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006af5ca; /* je 0x6af5ca */
    (void)logic32(c, (uint32_t)(c->esi & (uint32_t)0x3u)); /* test esi, 3 */
    if (!c->zf) goto L_006af594; /* jne 0x6af594 */
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_006af601; /* jne 0x6af601 */
L_006af5b0:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (c->zf) goto L_006af5c2; /* je 0x6af5c2 */
L_006af5b5:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006af5ee; /* je 0x6af5ee */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_006af5b5; /* jne 0x6af5b5 */
L_006af5c2:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006af5ca:;
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (c->zf) goto L_006af5e4; /* je 0x6af5e4 */
L_006af5d2:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_006af666; /* je 0x6af666 */
    (void)logic32(c, (uint32_t)(c->edi & (uint32_t)0x3u)); /* test edi, 3 */
    if (!c->zf) goto L_006af5d2; /* jne 0x6af5d2 */
L_006af5e4:;
    c->ebx = (uint32_t)(c->ecx); /* mov ebx, ecx */
    c->ecx = (uint32_t)(shr32(c, c->ecx, 2)); /* shr ecx, 2 */
    if (!c->zf) goto L_006af657; /* jne 0x6af657 */
L_006af5eb:;
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
L_006af5ee:;
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->zf) goto L_006af5eb; /* jne 0x6af5eb */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006af5f3:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006af5f9:;
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_006af5b0; /* je 0x6af5b0 */
L_006af601:;
    c->edx = (uint32_t)((uint32_t)0x7efefeffu); /* mov edx, 0x7efefeff */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    c->edx = (uint32_t)(add32(c, c->edx, c->eax)); /* add edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ (uint32_t)0xffffffffu))); /* xor eax, 0xffffffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax ^ c->edx))); /* xor eax, edx */
    c->edx = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edx, dword ptr [esi] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u)); /* test eax, 0x81010100 */
    if (c->zf) goto L_006af5f9; /* je 0x6af5f9 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    if (c->zf) goto L_006af64b; /* je 0x6af64b */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->edx >> 8)) & ((uint8_t)(c->edx >> 8)))); /* test dh, dh */
    if (c->zf) goto L_006af641; /* je 0x6af641 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff0000u)); /* test edx, 0xff0000 */
    if (c->zf) goto L_006af637; /* je 0x6af637 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0xff000000u)); /* test edx, 0xff000000 */
    if (!c->zf) goto L_006af5f9; /* jne 0x6af5f9 */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_006af64f; /* jmp 0x6af64f */
L_006af637:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffffu))); /* and edx, 0xffff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_006af64f; /* jmp 0x6af64f */
L_006af641:;
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xffu))); /* and edx, 0xff */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
    goto L_006af64f; /* jmp 0x6af64f */
L_006af64b:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    W32((uint32_t)(c->edi), (uint32_t)(c->edx)); /* mov dword ptr [edi], edx */
L_006af64f:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (c->zf) goto L_006af661; /* je 0x6af661 */
L_006af657:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006af659:;
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    if (!c->zf) goto L_006af659; /* jne 0x6af659 */
L_006af661:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx & (uint32_t)0x3u))); /* and ebx, 3 */
    if (!c->zf) goto L_006af5eb; /* jne 0x6af5eb */
L_006af666:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov eax, dword ptr [esp + 0x10] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006af66e(CPU *c) { /* FUN_1001f66e */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    { uint32_t t_ = R32((uint32_t)(0x6be04cu)); PUSH32(c, 0x006af678u); call_indirect(c, t_); } /* call dword ptr [0x1002e04c] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (!c->zf) goto L_006af68e; /* jne 0x6af68e */
    { uint32_t t_ = R32((uint32_t)(0x6be018u)); PUSH32(c, 0x006af683u); call_indirect(c, t_); } /* call dword ptr [0x1002e018] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006af689u); f_006b3004(c); /* call 0x6b3004 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006af68a:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
    c->esp += 4; return; /* ret  */
L_006af68e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_006af6b1; /* je 0x6af6b1 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x8u)) & (uint8_t)0x2u)); /* test byte ptr [esp + 8], 2 */
    if (c->zf) goto L_006af6b1; /* je 0x6af6b1 */
    PUSH32(c, 0x006af69eu); f_006b3077(c); /* call 0x6b3077 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xdu)); /* mov dword ptr [eax], 0xd */
    PUSH32(c, 0x006af6a9u); f_006b3080(c); /* call 0x6b3080 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x5u)); /* mov dword ptr [eax], 5 */
    goto L_006af68a; /* jmp 0x6af68a */
L_006af6b1:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006af6c0(CPU *c) { /* FUN_1001f6c0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); /* fst qword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    PUSH32(c, 0x006af6d5u); f_006af6e2(c); /* call 0x6af6e2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006af6e2(CPU *c) { /* FUN_1001f6e2 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_006af6f6; /* je 0x6af6f6 */
    PUSH32(c, 0x006af6f6u); f_006b34e5(c); /* call 0x6b34e5 */
L_006af6f6:;
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x7ff00000u))); /* and ecx, 0x7ff00000 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    (void)sub32(c, c->ecx, (uint32_t)0x7ff00000u); /* cmp ecx, 0x7ff00000 */
    if (c->zf) goto L_006af7a9; /* je 0x6af7a9 */
    PUSH32(c, 0x006af711u); f_006b3515(c); /* call 0x6b3515 */
    if (c->zf) goto L_006af7a5; /* je 0x6af7a5 */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_006af818; /* je 0x6af818 */
L_006af722:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0xfu))); /* mov cl, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x80u))); /* and cl, 0x80 */
    if (!c->zf) goto L_006af890; /* jne 0x6af890 */
L_006af72f:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    PUSH32(c, 0x006af736u); f_006b34d0(c); /* call 0x6b34d0 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x1u); /* cmp cl, 1 */
    if (!c->zf) goto L_006af73d; /* jne 0x6af73d */
    ST(0) = -ST(0); /* fchs  */
L_006af73d:;
    (void)sub32(c, R32((uint32_t)(0x6d00e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100400e8], 0 */
    if (!c->zf) { f_006b356e(c); return; } /* jne 0x6b356e */
    c->ecx = (uint32_t)((uint32_t)(0x6ca498u)); /* lea ecx, [0x1003a498] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    { f_006b35b9(c); return; } /* jmp 0x6b35b9 */
L_006af75a:;
    (void)sub32(c, R32((uint32_t)(0x6d00e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100400e8], 0 */
    if (!c->zf) { f_006b356e(c); return; } /* jne 0x6b356e */
    c->ecx = (uint32_t)((uint32_t)(0x6ca498u)); /* lea ecx, [0x1003a498] */
    c->edx = (uint32_t)((uint32_t)0x1du); /* mov edx, 0x1d */
    PUSH32(c, 0x006af777u); f_006b3470(c); /* call 0x6b3470 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
L_006af779:;
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    PUSH32(c, 0x006af782u); f_006b3515(c); /* call 0x6b3515 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0x16u)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0x16], 8 */
    if (!c->zf) goto L_006af78c; /* jne 0x6af78c */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    goto L_006af7bf; /* jmp 0x6af7bf */
L_006af78c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_006af75a; /* jmp 0x6af75a */
L_006af795:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esp + 0xeu)) & (uint8_t)0x8u)); /* test byte ptr [esp + 0xe], 8 */
    if (!c->zf) goto L_006af78c; /* jne 0x6af78c */
L_006af79c:;
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    goto L_006af75a; /* jmp 0x6af75a */
L_006af7a5:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    goto L_006af7bf; /* jmp 0x6af7bf */
L_006af7a9:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_006af779; /* jne 0x6af779 */
    c->edx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea edx, [esp + 8] */
    PUSH32(c, 0x006af7bfu); f_006b3515(c); /* call 0x6b3515 */
L_006af7bf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u))); /* and eax, 0x7ff00000 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0xfffffu))); /* and edx, 0xfffff */
    (void)sub32(c, c->eax, (uint32_t)0x7ff00000u); /* cmp eax, 0x7ff00000 */
    if (!c->zf) goto L_006af7dd; /* jne 0x6af7dd */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | R32((uint32_t)(c->esp + 0x8u))))); /* or edx, dword ptr [esp + 8] */
    if (!c->zf) goto L_006af795; /* jne 0x6af795 */
L_006af7dd:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_006af79c; /* jne 0x6af79c */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x74u)); /* sub esp, 0x74 */
    c->ecx = (uint32_t)(c->esp); /* mov ecx, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    WF64((uint32_t)(c->esp + 0x8u), ST(0)); FPOP(c); /* fstp qword ptr [esp + 8] */
    ; /* wait  */
    guest_trap(c, 0x006af7f2u, "unsupported: fnsave dword ptr [ecx + 8]"); /* fnsave dword ptr [ecx + 8] */
    PUSH32(c, 0x006af7fau); f_006b365c(c); /* call 0x6b365c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    guest_trap(c, 0x006af7feu, "unsupported: frstor dword ptr [ecx + 8]"); /* frstor dword ptr [ecx + 8] */
    FPUSH(c, RF64((uint32_t)(c->ecx))); /* fld qword ptr [ecx] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x74u)); /* add esp, 0x74 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) { f_006b356e(c); return; } /* je 0x6b356e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_006af75a; /* jmp 0x6af75a */
L_006af818:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_006af722; /* jne 0x6af722 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x7ff00000u)); /* test eax, 0x7ff00000 */
    if (c->zf) goto L_006af875; /* je 0x6af875 */
    PUSH32(c, 0x006af83du); f_006af8b5(c); /* call 0x6af8b5 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(R8((uint32_t)(c->esp + 0xfu))) << 8); /* mov ch, byte ptr [esp + 0xf] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(shr8(c, ((uint8_t)(c->ecx >> 8)), 7)) << 8); /* shr ch, 7 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->esp + 0x17u)) & (uint32_t)0x80u)); /* test dword ptr [esp + 0x17], 0x80 */
    if (c->zf) goto L_006af864; /* je 0x6af864 */
    FPUSH(c, RF80((uint32_t)(0x6cad20u))); /* fld xword ptr [0x1003ad20] */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) goto L_006af85a; /* je 0x6af85a */
    ST(0) = -ST(0); /* fchs  */
L_006af85a:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_006af75a; /* jmp 0x6af75a */
L_006af864:;
    FPUSH(c, 0.0); /* fldz  */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & ((uint8_t)c->ecx))); /* test ch, cl */
    if (c->zf) { f_006b356e(c); return; } /* je 0x6b356e */
    ST(0) = -ST(0); /* fchs  */
    { f_006b356e(c); return; } /* jmp 0x6b356e */
L_006af875:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x10u))))); /* or eax, dword ptr [esp + 0x10] */
    if (!c->zf) goto L_006af889; /* jne 0x6af889 */
    FPUSH(c, 1.0); /* fld1  */
    { f_006b356e(c); return; } /* jmp 0x6b356e */
L_006af889:;
    FPUSH(c, 0.0); /* fldz  */
    { f_006b356e(c); return; } /* jmp 0x6b356e */
L_006af890:;
    { double v_ = ST(1); FPUSH(c, v_); } /* fld st(1) */
    PUSH32(c, 0x006af897u); f_006af8b5(c); /* call 0x6af8b5 */
    ST(0) = -ST(0); /* fchs  */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006af72f; /* jne 0x6af72f */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x6cad80u))); /* fld xword ptr [0x1003ad80] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    goto L_006af75a; /* jmp 0x6af75a */
}

void f_006af88b(CPU *c) { /* PTR_006af88b */
    PREEMPT_POLL(c);
    { f_006b356e(c); return; } /* jmp 0x6b356e */
}

void f_006af8b5(CPU *c) { /* FUN_1001f8b5 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((uint8_t)0x0u); /* mov cl, 0 */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_006af8da; /* jne 0x6af8da */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x6ca490u))); /* fmul qword ptr [0x1003a490] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_006af8d9; /* jne 0x6af8d9 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(inc8(c, ((uint8_t)c->ecx))); /* inc cl */
L_006af8d9:;
    c->esp += 4; return; /* ret  */
L_006af8da:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
}

void f_006af8dd(CPU *c) { /* FUN_1001f8dd */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c13f8u; PUSH32(c, v_); } /* push 0x100313f8 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x10u)); /* sub esp, 0x10 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
L_006af90b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0x10u))); /* cmp eax, dword ptr [ebp + 0x10] */
    if ((c->sf == c->of)) goto L_006af926; /* jge 0x6af926 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(c->esi); /* mov ecx, esi */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x006af91bu); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, R32((uint32_t)(c->ebp + 0xcu)))); /* add esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 0x1c] */
    goto L_006af90b; /* jmp 0x6af90b */
L_006af926:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x20], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006af936u); f_006af947(c); /* call 0x6af947 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 24; return; /* ret 0x14 */
}

void f_006af947(CPU *c) { /* FUN_1001f947 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x20], 0 */
    if (!c->zf) goto L_006af95e; /* jne 0x6af95e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006af95eu); f_006af9df(c); /* call 0x6af9df */
L_006af95e:;
    c->esp += 4; return; /* ret  */
}

void f_006af95f(CPU *c) { /* FUN_1001f95f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1408u; PUSH32(c, v_); } /* push 0x10031408 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)R32((uint32_t)(c->ebp + 0x10u)); c->eax = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul eax, dword ptr [ebp + 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), c->eax))); } /* add dword ptr [ebp + 8], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_006af996:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_006af9a6; /* js 0x6af9a6 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(sub32(c, R32(a_), c->esi))); } /* sub dword ptr [ebp + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x006af9a4u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_006af996; /* jmp 0x6af996 */
L_006af9a6:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006af9b6u); f_006af9c7(c); /* call 0x6af9c7 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006af9c7(CPU *c) { /* FUN_1001f9c7 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    if (!c->zf) goto L_006af9de; /* jne 0x6af9de */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006af9deu); f_006af9df(c); /* call 0x6af9df */
L_006af9de:;
    c->esp += 4; return; /* ret  */
}

void f_006af9df(CPU *c) { /* FUN_1001f9df */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1418u; PUSH32(c, v_); } /* push 0x10031418 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
L_006afa08:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x10u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp + 0x10] */
    if (c->sf) goto L_006afa28; /* js 0x6afa28 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ecx, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)(sub32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* sub ecx, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp + 8], ecx */
    { uint32_t t_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, 0x006afa19u); call_indirect(c, t_); } /* call dword ptr [ebp + 0x14] */
    goto L_006afa08; /* jmp 0x6afa08 */
L_006afa28:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006afa1b(CPU *c) { /* PTR_006afa1b */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x006afa23u); f_006afa3d(c); /* call 0x6afa3d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006afa25(CPU *c) { /* PTR_006afa25 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 20; return; /* ret 0x10 */
}

void f_006afa3d(CPU *c) { /* PTR_006afa3d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (c->zf) goto L_006afa4e; /* je 0x6afa4e */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006afa4e:;
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006afa53(CPU *c) { /* FUN_1001fa53 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x49u)); /* mov dword ptr [ebp - 0x14], 0x49 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x006afa6fu); f_006b4390(c); /* call 0x6b4390 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006afa82u); f_006b38d4(c); /* call 0x6b38d4 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006afa87(CPU *c) { /* FUN_1001fa87 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, R32((uint32_t)(0x6d01ccu)), c->esi); /* cmp dword ptr [0x100401cc], esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 8], esi */
    if (!c->zf) goto L_006afac5; /* jne 0x6afac5 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_006afbb7; /* je 0x6afbb7 */
L_006afaa9:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x41u); /* cmp cl, 0x41 */
    if ((c->sf != c->of)) goto L_006afaba; /* jl 0x6afaba */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x5au); /* cmp cl, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_006afaba; /* jg 0x6afaba */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx], cl */
L_006afaba:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_006afaa9; /* jne 0x6afaa9 */
    goto L_006afbb7; /* jmp 0x6afbb7 */
L_006afac5:;
    c->edi = (uint32_t)((uint32_t)0x6d1838u); /* mov edi, 0x10041838 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6be054u)); PUSH32(c, 0x006afad1u); call_indirect(c, t_); } /* call dword ptr [0x1002e054] */
    (void)sub32(c, R32((uint32_t)(0x6d1834u)), c->esi); /* cmp dword ptr [0x10041834], esi */
    if (c->zf) goto L_006afaf1; /* je 0x6afaf1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6be050u)); PUSH32(c, 0x006afae0u); call_indirect(c, t_); } /* call dword ptr [0x1002e050] */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006afae7u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    goto L_006afaf4; /* jmp 0x6afaf4 */
L_006afaf1:;
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
L_006afaf4:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6d01ccu))); /* mov eax, dword ptr [0x100401cc] */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (!c->zf) goto L_006afb3a; /* jne 0x6afb3a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->esi); /* cmp dword ptr [ebp - 4], esi */
    if (c->zf) goto L_006afb0c; /* je 0x6afb0c */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006afb09u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006afb13; /* jmp 0x6afb13 */
L_006afb0c:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6be050u)); PUSH32(c, 0x006afb13u); call_indirect(c, t_); } /* call dword ptr [0x1002e050] */
L_006afb13:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_006afbb7; /* je 0x6afbb7 */
L_006afb21:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x41u); /* cmp cl, 0x41 */
    if ((c->sf != c->of)) goto L_006afb32; /* jl 0x6afb32 */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x5au); /* cmp cl, 0x5a */
    if ((!c->zf && c->sf == c->of)) goto L_006afb32; /* jg 0x6afb32 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ecx), (uint8_t)0x20u)); /* add cl, 0x20 */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [edx], cl */
L_006afb32:;
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, R8((uint32_t)(c->edx)), (uint8_t)0x0u); /* cmp byte ptr [edx], 0 */
    if (!c->zf) goto L_006afb21; /* jne 0x6afb21 */
    goto L_006afbb7; /* jmp 0x6afbb7 */
L_006afb3a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->esi = (uint32_t)((uint32_t)0x100u); /* mov esi, 0x100 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006afb51u); f_006b4500(c); /* call 0x6b4500 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    if (c->zf) goto L_006afb93; /* je 0x6afb93 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006afb60u); f_006b09fd(c); /* call 0x6b09fd */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if (c->zf) goto L_006afb93; /* je 0x6afb93 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x6d01ccu)); PUSH32(c, v_); } /* push dword ptr [0x100401cc] */
    PUSH32(c, 0x006afb7fu); f_006b4500(c); /* call 0x6b4500 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006afb93; /* je 0x6afb93 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006afb91u); f_006b4410(c); /* call 0x6b4410 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006afb93:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 4], 0 */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006afba4; /* je 0x6afba4 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006afba1u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006afbab; /* jmp 0x6afbab */
L_006afba4:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6be050u)); PUSH32(c, 0x006afbabu); call_indirect(c, t_); } /* call dword ptr [0x1002e050] */
L_006afbab:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x006afbb3u); f_006b002f(c); /* call 0x6b002f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006afbb7:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006afbbb(CPU *c) { /* FUN_1001fbbb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (!c->zf) goto L_006afc50; /* jne 0x6afc50 */
    { uint32_t t_ = R32((uint32_t)(0x6be05cu)); PUSH32(c, 0x006afbceu); call_indirect(c, t_); } /* call dword ptr [0x1002e05c] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(0x6d0114u), (uint32_t)(c->eax)); /* mov dword ptr [0x10040114], eax */
    PUSH32(c, 0x006afbdau); f_006b4f0c(c); /* call 0x6b4f0c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006afc1b; /* je 0x6afc1b */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d0114u))); /* mov eax, dword ptr [0x10040114] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6d0115u))); /* mov cl, byte ptr [0x10040115] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    { uint32_t a_ = (uint32_t)(0x6d0114u); W32(a_, (uint32_t)(shr32(c, R32(a_), 16))); } /* shr dword ptr [0x10040114], 0x10 */
    W32((uint32_t)(0x6d011cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1004011c], eax */
    W32((uint32_t)(0x6d0120u), (uint32_t)(c->ecx)); /* mov dword ptr [0x10040120], ecx */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    W32((uint32_t)(0x6d0118u), (uint32_t)(c->eax)); /* mov dword ptr [0x10040118], eax */
    PUSH32(c, 0x006afc12u); f_006b170c(c); /* call 0x6b170c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006afc1f; /* jne 0x6afc1f */
    PUSH32(c, 0x006afc1bu); f_006b4f69(c); /* call 0x6b4f69 */
L_006afc1b:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006afc91; /* jmp 0x6afc91 */
L_006afc1f:;
    { uint32_t t_ = R32((uint32_t)(0x6be058u)); PUSH32(c, 0x006afc25u); call_indirect(c, t_); } /* call dword ptr [0x1002e058] */
    W32((uint32_t)(0x6d183cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1004183c], eax */
    PUSH32(c, 0x006afc2fu); f_006b4c65(c); /* call 0x6b4c65 */
    W32((uint32_t)(0x6d00f4u), (uint32_t)(c->eax)); /* mov dword ptr [0x100400f4], eax */
    PUSH32(c, 0x006afc39u); f_006b474f(c); /* call 0x6b474f */
    PUSH32(c, 0x006afc3eu); f_006b4a18(c); /* call 0x6b4a18 */
    PUSH32(c, 0x006afc43u); f_006b495f(c); /* call 0x6b495f */
    PUSH32(c, 0x006afc48u); f_006b08df(c); /* call 0x6b08df */
    { uint32_t a_ = (uint32_t)(0x6d00f0u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x100400f0] */
    goto L_006afc8e; /* jmp 0x6afc8e */
L_006afc50:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (!c->zf) goto L_006afc82; /* jne 0x6afc82 */
    (void)sub32(c, R32((uint32_t)(0x6d00f0u)), c->ecx); /* cmp dword ptr [0x100400f0], ecx */
    if ((c->zf || c->sf != c->of)) goto L_006afc1b; /* jle 0x6afc1b */
    { uint32_t a_ = (uint32_t)(0x6d00f0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x100400f0] */
    (void)sub32(c, R32((uint32_t)(0x6d014cu)), c->ecx); /* cmp dword ptr [0x1004014c], ecx */
    if (!c->zf) goto L_006afc71; /* jne 0x6afc71 */
    PUSH32(c, 0x006afc71u); f_006b091d(c); /* call 0x6b091d */
L_006afc71:;
    PUSH32(c, 0x006afc76u); f_006b490b(c); /* call 0x6b490b */
    PUSH32(c, 0x006afc7bu); f_006b1760(c); /* call 0x6b1760 */
    PUSH32(c, 0x006afc80u); f_006b4f69(c); /* call 0x6b4f69 */
    goto L_006afc8e; /* jmp 0x6afc8e */
L_006afc82:;
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006afc8e; /* jne 0x6afc8e */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006afc8du); f_006b17f8(c); /* call 0x6b17f8 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006afc8e:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006afc91:;
    c->esp += 16; return; /* ret 0xc */
}

void f_006afc94(CPU *c) { /* entry */
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
    if (!c->zf) goto L_006afcb0; /* jne 0x6afcb0 */
    (void)sub32(c, R32((uint32_t)(0x6d00f0u)), (uint32_t)0x0u); /* cmp dword ptr [0x100400f0], 0 */
    goto L_006afcd6; /* jmp 0x6afcd6 */
L_006afcb0:;
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    if (c->zf) goto L_006afcba; /* je 0x6afcba */
    (void)sub32(c, c->esi, (uint32_t)0x2u); /* cmp esi, 2 */
    if (!c->zf) goto L_006afcdc; /* jne 0x6afcdc */
L_006afcba:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6d1840u))); /* mov eax, dword ptr [0x10041840] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006afccc; /* je 0x6afccc */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006afcc8u); call_indirect(c, t_); } /* call eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006afcd8; /* je 0x6afcd8 */
L_006afccc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006afcd4u); f_006afbbb(c); /* call 0x6afbbb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
L_006afcd6:;
    if (!c->zf) goto L_006afcdc; /* jne 0x6afcdc */
L_006afcd8:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006afd2a; /* jmp 0x6afd2a */
L_006afcdc:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006afce4u); f_006b5011(c); /* call 0x6b5011 */
    (void)sub32(c, c->esi, (uint32_t)0x1u); /* cmp esi, 1 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    if (!c->zf) goto L_006afcf8; /* jne 0x6afcf8 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006afd27; /* jne 0x6afd27 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006afcf8u); f_006afbbb(c); /* call 0x6afbbb */
L_006afcf8:;
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006afd01; /* je 0x6afd01 */
    (void)sub32(c, c->esi, (uint32_t)0x3u); /* cmp esi, 3 */
    if (!c->zf) goto L_006afd27; /* jne 0x6afd27 */
L_006afd01:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006afd09u); f_006afbbb(c); /* call 0x6afbbb */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006afd10; /* jne 0x6afd10 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp + 0xc], eax */
L_006afd10:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if (c->zf) goto L_006afd27; /* je 0x6afd27 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d1840u))); /* mov eax, dword ptr [0x10041840] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006afd27; /* je 0x6afd27 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006afd24u); call_indirect(c, t_); } /* call eax */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_006afd27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
L_006afd2a:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 16; return; /* ret 0xc */
}

void f_006afd31(CPU *c) { /* __amsg_exit */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6d00fcu))); /* mov eax, dword ptr [0x100400fc] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    if (c->zf) goto L_006afd48; /* je 0x6afd48 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006afd4d; /* jne 0x6afd4d */
    (void)sub32(c, R32((uint32_t)(0x6d0100u)), (uint32_t)0x1u); /* cmp dword ptr [0x10040100], 1 */
    if (!c->zf) goto L_006afd4d; /* jne 0x6afd4d */
L_006afd48:;
    PUSH32(c, 0x006afd4du); f_006b5017(c); /* call 0x6b5017 */
L_006afd4d:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006afd56u); f_006b5050(c); /* call 0x6b5050 */
    { uint32_t v_ = 0xffu; PUSH32(c, v_); } /* push 0xff */
    { uint32_t t_ = R32((uint32_t)(0x6ca49cu)); PUSH32(c, 0x006afd61u); call_indirect(c, t_); } /* call dword ptr [0x1003a49c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006afd61(CPU *c) { /* PTR_006afd61 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006afd70(CPU *c) { /* FUN_1001fd70 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    c->ecx = (uint32_t)((uint32_t)(c->esp + 0x8u)); /* lea ecx, [esp + 8] */
    if (c->cf) goto L_006afd90; /* jb 0x6afd90 */
L_006afd7c:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, (uint32_t)0x1000u)); /* sub ecx, 0x1000 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x1000u)); /* sub eax, 0x1000 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    (void)sub32(c, c->eax, (uint32_t)0x1000u); /* cmp eax, 0x1000 */
    if (!c->cf) goto L_006afd7c; /* jae 0x6afd7c */
L_006afd90:;
    c->ecx = (uint32_t)(sub32(c, c->ecx, c->eax)); /* sub ecx, eax */
    c->eax = (uint32_t)(c->esp); /* mov eax, esp */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ecx)) & c->eax)); /* test dword ptr [ecx], eax */
    c->esp = (uint32_t)(c->ecx); /* mov esp, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov eax, dword ptr [eax + 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_006afd9f(CPU *c) { /* FUN_1001fd9f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x20u)); /* sub esp, 0x20 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffe8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x18], eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)((uint32_t)0x42u)); /* mov dword ptr [ebp - 0x14], 0x42 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x14u)); /* lea eax, [ebp + 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006afdccu); f_006b1f6a(c); /* call 0x6b1f6a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    if (c->sf) goto L_006afdde; /* js 0x6afdde */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    goto L_006afdeb; /* jmp 0x6afdeb */
L_006afdde:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x006afde9u); f_006b1e52(c); /* call 0x6b1e52 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006afdeb:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006afdf0(CPU *c) { /* FUN_1001fdf0 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x8u)); /* sub esp, 8 */
    WF64((uint32_t)(c->esp), ST(0)); /* fst qword ptr [esp] */
    PUSH32(c, 0x006afdfbu); f_006b3558(c); /* call 0x6b3558 */
    PUSH32(c, 0x006afe00u); f_006afe0d(c); /* call 0x6afe0d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
    c->esp += 4; return; /* ret  */
}

void f_006afe0d(CPU *c) { /* FUN_1001fe0d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    ; /* wait  */
    W16((uint32_t)(c->esp), c->fpu_cw); /* fnstcw word ptr [esp] */
    if (c->zf) goto L_006afe81; /* je 0x6afe81 */
    (void)sub16(c, R16((uint32_t)(c->esp)), (uint16_t)0x27fu); /* cmp word ptr [esp], 0x27f */
    if (c->zf) goto L_006afe21; /* je 0x6afe21 */
    PUSH32(c, 0x006afe21u); f_006b34e5(c); /* call 0x6b34e5 */
L_006afe21:;
    (void)sub32(c, c->eax, (uint32_t)0x3ff00000u); /* cmp eax, 0x3ff00000 */
    if (!c->cf) goto L_006afe55; /* jae 0x6afe55 */
    FPUSH(c, 1.0); /* fld1  */
    ST(0) = FPRES(c, ST(0) + ST(1)); /* fadd st(1) */
    FPUSH(c, 1.0); /* fld1  */
    ST(0) = FPRES(c, ST(0) - ST(2)); /* fsub st(2) */
    ST(1) = FPRES(c, ST(1) * ST(0)); FPOP(c); /* fmulp st(1) */
    ST(0) = FPRES(c, sqrt(ST(0))); /* fsqrt  */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(1) = atan2(ST(1), ST(0)); FPOP(c); /* fpatan  */
L_006afe38:;
    (void)sub32(c, R32((uint32_t)(0x6d00e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100400e8], 0 */
    if (!c->zf) { f_006b356e(c); return; } /* jne 0x6b356e */
    c->edx = (uint32_t)((uint32_t)0xdu); /* mov edx, 0xd */
    c->ecx = (uint32_t)((uint32_t)(0x6ca4a0u)); /* lea ecx, [0x1003a4a0] */
    { f_006b357b(c); return; } /* jmp 0x6b357b */
L_006afe55:;
    if ((!c->cf && !c->zf)) goto L_006afe8f; /* ja 0x6afe8f */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu))); /* and eax, 0xfffff */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | R32((uint32_t)(c->esp + 0x8u))))); /* or eax, dword ptr [esp + 8] */
    if (!c->zf) goto L_006afe8f; /* jne 0x6afe8f */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0x80000000u))); /* and ecx, 0x80000000 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    if (c->zf) goto L_006afe76; /* je 0x6afe76 */
    FPUSH(c, M_PI); /* fldpi  */
    goto L_006afe38; /* jmp 0x6afe38 */
L_006afe76:;
    FPUSH(c, 0.0); /* fldz  */
    goto L_006afe38; /* jmp 0x6afe38 */
L_006afe7a:;
    PUSH32(c, 0x006afe7fu); f_006b34fc(c); /* call 0x6b34fc */
    goto L_006afe9c; /* jmp 0x6afe9c */
L_006afe81:;
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0xfffffu)); /* test eax, 0xfffff */
    if (!c->zf) goto L_006afe7a; /* jne 0x6afe7a */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [esp + 8], 0 */
    if (!c->zf) goto L_006afe7a; /* jne 0x6afe7a */
L_006afe8f:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x6cad80u))); /* fld xword ptr [0x1003ad80] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_006afe9c:;
    (void)sub32(c, R32((uint32_t)(0x6d00e8u)), (uint32_t)0x0u); /* cmp dword ptr [0x100400e8], 0 */
    if (!c->zf) { f_006b356e(c); return; } /* jne 0x6b356e */
    c->edx = (uint32_t)((uint32_t)0xdu); /* mov edx, 0xd */
    c->ecx = (uint32_t)((uint32_t)(0x6ca4a0u)); /* lea ecx, [0x1003a4a0] */
    PUSH32(c, 0x006afeb9u); f_006b3487(c); /* call 0x6b3487 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
    c->esp += 4; return; /* ret  */
}

void f_006afebb(CPU *c) { /* FUN_1001febb */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xau))); /* mov eax, dword ptr [esp + 0xa] */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x7ff0u))); /* and ax, 0x7ff0 */
    (void)sub16(c, ((uint16_t)c->eax), (uint16_t)0x7ff0u); /* cmp ax, 0x7ff0 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne cl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esp += 4; return; /* ret  */
}

void f_006afecf(CPU *c) { /* FUN_1001fecf */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xeu))); /* mov eax, dword ptr [ebp + 0xe] */
    c->ecx = (uint32_t)((uint32_t)0x7ff0u); /* mov ecx, 0x7ff0 */
    c->edx = (uint32_t)(c->eax); /* mov edx, eax */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & c->ecx))); /* and edx, ecx */
    (void)sub16(c, ((uint16_t)c->edx), ((uint16_t)c->ecx)); /* cmp dx, cx */
    if (!c->zf) goto L_006aff0f; /* jne 0x6aff0f */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    WF64((uint32_t)(c->esp), ST(0)); FPOP(c); /* fstp qword ptr [esp] */
    PUSH32(c, 0x006afef0u); f_006b51cc(c); /* call 0x6b51cc */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006aff08; /* je 0x6aff08 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006aff04; /* je 0x6aff04 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006aff00; /* je 0x6aff00 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_006afefd:;
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006aff00:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_006afefd; /* jmp 0x6afefd */
L_006aff04:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    goto L_006afefd; /* jmp 0x6afefd */
L_006aff08:;
    c->eax = (uint32_t)((uint32_t)0x200u); /* mov eax, 0x200 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006aff0f:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8000u))); /* and eax, 0x8000 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->edx) & ((uint16_t)c->edx))); /* test dx, dx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (!c->zf) goto L_006aff39; /* jne 0x6aff39 */
    (void)logic32(c, (uint32_t)(R32((uint32_t)(c->ebp + 0xcu)) & (uint32_t)0xfffffu)); /* test dword ptr [ebp + 0xc], 0xfffff */
    if (!c->zf) goto L_006aff2a; /* jne 0x6aff2a */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    if (c->zf) goto L_006aff39; /* je 0x6aff39 */
L_006aff2a:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x90u))); /* and al, 0x90 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x80u)); /* add eax, 0x80 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006aff39:;
    FPUSH(c, RF64((uint32_t)(c->ebp + 0x8u))); /* fld qword ptr [ebp + 8] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6c1428u))); FPOP(c); /* fcomp qword ptr [0x10031428] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    if (!c->zf) goto L_006aff54; /* jne 0x6aff54 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xe0u))); /* and al, 0xe0 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x40u)); /* add eax, 0x40 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006aff54:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x8u))); /* and al, 8 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x100u)); /* add eax, 0x100 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006aff64(CPU *c) { /* FUN_1001ff64 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov eax, dword ptr [esp + 0xc] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    W32((uint32_t)(c->esp + 0xcu), (uint32_t)(c->ebp)); /* mov dword ptr [esp + 0xc], ebp */
    c->ebp = (uint32_t)((uint32_t)(c->esp + 0xcu)); /* lea ebp, [esp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->esp += 4; return; /* ret  */
}

void f_006aff83(CPU *c) { /* FUN_1001ff83 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006aff9d; /* jle 0x6aff9d */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006aff9au); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006aff9d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx + c->eax * 2))); /* mov ax, word ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x103u))); /* and eax, 0x103 */
    c->esp += 4; return; /* ret  */
}

void f_006affb1(CPU *c) { /* FUN_1001ffb1 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006affc8; /* jle 0x6affc8 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006affc5u); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006affc8:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
    c->esp += 4; return; /* ret  */
}

void f_006affd9(CPU *c) { /* FUN_1001ffd9 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006afff0; /* jle 0x6afff0 */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006affedu); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006afff0:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x8u))); /* and eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_006b0001(CPU *c) { /* FUN_10020001 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006b001b; /* jle 0x6b001b */
    { uint32_t v_ = 0x107u; PUSH32(c, v_); } /* push 0x107 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006b0018u); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006b001b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ecx + c->eax * 2))); /* mov ax, word ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x107u))); /* and eax, 0x107 */
    c->esp += 4; return; /* ret  */
}

void f_006b002f(CPU *c) { /* FUN_1002002f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1438u; PUSH32(c, v_); } /* push 0x10031438 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006b0109; /* je 0x6b0109 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d06e8u))); /* mov eax, dword ptr [0x100406e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006b00a2; /* jne 0x6b00a2 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b006eu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0079u); f_006b58b7(c); /* call 0x6b58b7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b008a; /* je 0x6b008a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0088u); f_006b58e2(c); /* call 0x6b58e2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b008a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0093u); f_006b0099(c); /* call 0x6b0099 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_006b00ea; /* jmp 0x6b00ea */
L_006b00a2:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b00fa; /* jne 0x6b00fa */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b00aeu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b00c4u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b00dd; /* je 0x6b00dd */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x006b00dau); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b00dd:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b00e6u); f_006b00f1(c); /* call 0x6b00f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
L_006b00ea:;
    if (!c->zf) goto L_006b0109; /* jne 0x6b0109 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006b00fb; /* jmp 0x6b00fb */
L_006b00fa:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_006b00fb:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be028u)); PUSH32(c, 0x006b0109u); call_indirect(c, t_); } /* call dword ptr [0x1002e028] */
L_006b0109:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0099(CPU *c) { /* FUN_10020099 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b00a0u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b00a2(CPU *c) { /* PTR_006b00a2 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_006b00fa(c); return; } /* jne 0x6b00fa */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b00aeu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd8u)); /* lea eax, [ebp - 0x28] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b00c4u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b00dd; /* je 0x6b00dd */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x006b00dau); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b00dd:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b00e6u); f_006b00f1(c); /* call 0x6b00f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_006b0109(c); return; } /* jne 0x6b0109 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_006b00fb(c); return; } /* jmp 0x6b00fb */
}

void f_006b00dd(CPU *c) { /* PTR_006b00dd */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b00e6u); f_006b00f1(c); /* call 0x6b00f1 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) { f_006b0109(c); return; } /* jne 0x6b0109 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_006b00fb(c); return; } /* jmp 0x6b00fb */
}

void f_006b00ea(CPU *c) { /* PTR_006b00ea */
    PREEMPT_POLL(c);
    if (!c->zf) { f_006b0109(c); return; } /* jne 0x6b0109 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { f_006b00fb(c); return; } /* jmp 0x6b00fb */
}

void f_006b00f1(CPU *c) { /* FUN_100200f1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b00f8u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b00fa(CPU *c) { /* PTR_006b00fa */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be028u)); PUSH32(c, 0x006b0109u); call_indirect(c, t_); } /* call dword ptr [0x1002e028] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b00fb(CPU *c) { /* PTR_006b00fb */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be028u)); PUSH32(c, 0x006b0109u); call_indirect(c, t_); } /* call dword ptr [0x1002e028] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0109(CPU *c) { /* PTR_006b0109 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0118(CPU *c) { /* FUN_10020118 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006b013f; /* je 0x6b013f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0127u); f_006b4390(c); /* call 0x6b4390 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b012eu); f_006b09fd(c); /* call 0x6b09fd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b013f; /* je 0x6b013f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b013bu); f_006b4410(c); /* call 0x6b4410 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006b013f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b0143(CPU *c) { /* FUN_10020143 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x88u)); /* sub esp, 0x88 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if ((c->sf != c->of)) goto L_006b0383; /* jl 0x6b0383 */
    (void)sub32(c, c->esi, (uint32_t)0x5u); /* cmp esi, 5 */
    if ((!c->zf && c->sf == c->of)) goto L_006b0383; /* jg 0x6b0383 */
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006b016bu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t a_ = (uint32_t)(0x6d1834u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x10041834] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0172:;
    (void)sub32(c, R32((uint32_t)(0x6d1838u)), c->ebx); /* cmp dword ptr [0x10041838], ebx */
    if (c->zf) goto L_006b0184; /* je 0x6b0184 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t t_ = R32((uint32_t)(0x6be060u)); PUSH32(c, 0x006b0182u); call_indirect(c, t_); } /* call dword ptr [0x1002e060] */
    goto L_006b0172; /* jmp 0x6b0172 */
L_006b0184:;
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006b01ad; /* je 0x6b01ad */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if (c->zf) goto L_006b019e; /* je 0x6b019e */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0197u); f_006b0389(c); /* call 0x6b0389 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b036e; /* jmp 0x6b036e */
L_006b019e:;
    c->eax = (uint32_t)((uint32_t)(c->esi + c->esi * 2)); /* lea eax, [esi + esi*2] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax * 4 + 0x6ca5bcu))); /* mov esi, dword ptr [eax*4 + 0x1003a5bc] */
    goto L_006b0370; /* jmp 0x6b0370 */
L_006b01ad:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp + 8], ebx */
    if (c->zf) goto L_006b0369; /* je 0x6b0369 */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x4cu); /* cmp byte ptr [edi], 0x4c */
    if (!c->zf) goto L_006b02e0; /* jne 0x6b02e0 */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x1u)), (uint8_t)0x43u); /* cmp byte ptr [edi + 1], 0x43 */
    if (!c->zf) goto L_006b02e0; /* jne 0x6b02e0 */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x2u)), (uint8_t)0x5fu); /* cmp byte ptr [edi + 2], 0x5f */
    if (!c->zf) goto L_006b02e0; /* jne 0x6b02e0 */
    { uint32_t v_ = 0x6c1490u; PUSH32(c, v_); } /* push 0x10031490 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b01eau); f_006b7710(c); /* call 0x6b7710 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b02c0; /* je 0x6b02c0 */
    goto L_006b01fa; /* jmp 0x6b01fa */
L_006b01f8:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006b01fa:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(sub32(c, c->eax, c->edi)); /* sub eax, edi */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    if (c->zf) goto L_006b02c0; /* je 0x6b02c0 */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x3bu); /* cmp byte ptr [esi], 0x3b */
    if (c->zf) goto L_006b02c0; /* je 0x6b02c0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp + 0xc], 1 */
    c->ebx = (uint32_t)((uint32_t)0x6ca5c4u); /* mov ebx, 0x1003a5c4 */
    goto L_006b0221; /* jmp 0x6b0221 */
L_006b021e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
L_006b0221:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebx)); PUSH32(c, v_); } /* push dword ptr [ebx] */
    PUSH32(c, 0x006b022au); f_006b76d0(c); /* call 0x6b76d0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b023e; /* jne 0x6b023e */
    { uint32_t v_ = R32((uint32_t)(c->ebx)); PUSH32(c, v_); } /* push dword ptr [ebx] */
    PUSH32(c, 0x006b0238u); f_006b4390(c); /* call 0x6b4390 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->eax); /* cmp dword ptr [ebp - 4], eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b024c; /* je 0x6b024c */
L_006b023e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0xcu)); /* add ebx, 0xc */
    (void)sub32(c, c->ebx, (uint32_t)0x6ca5f4u); /* cmp ebx, 0x1003a5f4 */
    if ((c->zf || c->sf != c->of)) goto L_006b021e; /* jle 0x6b021e */
L_006b024c:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = 0x6c638cu; PUSH32(c, v_); } /* push 0x1003638c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0258u); f_006b7690(c); /* call 0x6b7690 */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0265; /* jne 0x6b0265 */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x3bu); /* cmp byte ptr [esi], 0x3b */
    if (!c->zf) goto L_006b02c0; /* jne 0x6b02c0 */
L_006b0265:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x5u); /* cmp dword ptr [ebp + 0xc], 5 */
    if ((!c->zf && c->sf == c->of)) goto L_006b029a; /* jg 0x6b029a */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0279u); f_006af570(c); /* call 0x6af570 */
    { uint32_t a_ = (uint32_t)(c->ebp + c->edi + 0xffffff78u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp + edi - 0x88], 0 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b0290u); f_006b0389(c); /* call 0x6b0389 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b029a; /* je 0x6b029a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
L_006b029a:;
    c->edi = (uint32_t)(add32(c, c->edi, c->esi)); /* add edi, esi */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x0u); /* cmp byte ptr [edi], 0 */
    if (c->zf) goto L_006b02cf; /* je 0x6b02cf */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x0u); /* cmp byte ptr [edi], 0 */
    if (c->zf) goto L_006b02cf; /* je 0x6b02cf */
    { uint32_t v_ = 0x6c1490u; PUSH32(c, v_); } /* push 0x10031490 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b02b2u); f_006b7710(c); /* call 0x6b7710 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b01f8; /* jne 0x6b01f8 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006b02c0:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006b02c7u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_006b0378; /* jmp 0x6b0378 */
L_006b02cf:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
L_006b02d3:;
    if (!c->zf) goto L_006b0369; /* jne 0x6b0369 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    goto L_006b0370; /* jmp 0x6b0370 */
L_006b02e0:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b02f0u); f_006b055d(c); /* call 0x6b055d */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (c->zf) goto L_006b0370; /* je 0x6b0370 */
    c->esi = (uint32_t)((uint32_t)0x6ca5bcu); /* mov esi, 0x1003a5bc */
    c->edi = (uint32_t)(c->esi); /* mov edi, esi */
L_006b0300:;
    (void)sub32(c, c->edi, c->esi); /* cmp edi, esi */
    if (c->zf) goto L_006b0333; /* je 0x6b0333 */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0312u); f_006b0d80(c); /* call 0x6b0d80 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b0330; /* je 0x6b0330 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b0325u); f_006b0389(c); /* call 0x6b0389 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0330; /* jne 0x6b0330 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & c->eax)))); } /* and dword ptr [ebp - 4], eax */
    goto L_006b0333; /* jmp 0x6b0333 */
L_006b0330:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 8] */
L_006b0333:;
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0xcu)); /* add edi, 0xc */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    (void)sub32(c, c->edi, (uint32_t)0x6ca5f8u); /* cmp edi, 0x1003a5f8 */
    if ((c->zf || c->sf != c->of)) goto L_006b0300; /* jle 0x6b0300 */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->edi); /* cmp dword ptr [ebp - 4], edi */
    if (c->zf) goto L_006b0361; /* je 0x6b0361 */
    PUSH32(c, 0x006b034bu); f_006b04a4(c); /* call 0x6b04a4 */
    { uint32_t v_ = R32((uint32_t)(0x6ca5bcu)); PUSH32(c, v_); } /* push dword ptr [0x1003a5bc] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    PUSH32(c, 0x006b0358u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x6ca5bcu), (uint32_t)(c->edi)); /* mov dword ptr [0x1003a5bc], edi */
    goto L_006b0370; /* jmp 0x6b0370 */
L_006b0361:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), c->edi); /* cmp dword ptr [ebp + 8], edi */
    goto L_006b02d3; /* jmp 0x6b02d3 */
L_006b0369:;
    PUSH32(c, 0x006b036eu); f_006b04a4(c); /* call 0x6b04a4 */
L_006b036e:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b0370:;
    { uint32_t v_ = 0x13u; PUSH32(c, v_); } /* push 0x13 */
    PUSH32(c, 0x006b0377u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0378:;
    { uint32_t a_ = (uint32_t)(0x6d1834u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [0x10041834] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    goto L_006b0385; /* jmp 0x6b0385 */
L_006b0383:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b0385:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0389(CPU *c) { /* FUN_10020389 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xa4u)); /* sub esp, 0xa4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff5cu)); /* lea eax, [ebp - 0xa4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b03b0u); f_006b055d(c); /* call 0x6b055d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0483; /* je 0x6b0483 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff5cu)); /* lea eax, [ebp - 0xa4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b03c7u); f_006b4390(c); /* call 0x6b4390 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b03ceu); f_006b09fd(c); /* call 0x6b09fd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b0483; /* je 0x6b0483 */
    c->esi = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea esi, [edi + edi*2] */
    c->ebx = (uint32_t)((uint32_t)(c->edi * 4 + 0x6d01c4u)); /* lea ebx, [edi*4 + 0x100401c4] */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x6ca5bcu))); /* mov eax, dword ptr [esi + 0x1003a5bc] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov eax, dword ptr [ebx] */
    W32((uint32_t)(c->ebp + 0xffffffecu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x14], eax */
    c->eax = (uint32_t)((uint32_t)(c->edi + c->edi * 2)); /* lea eax, [edi + edi*2] */
    c->eax = (uint32_t)((uint32_t)(c->eax * 2 + 0x6d0310u)); /* lea eax, [eax*2 + 0x10040310] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe0u)); /* lea eax, [ebp - 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b040fu); f_006b7750(c); /* call 0x6b7750 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d01dcu))); /* mov eax, dword ptr [0x100401dc] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 4], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff5cu)); /* lea eax, [ebp - 0xa4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b0426u); f_006b4410(c); /* call 0x6b4410 */
    W32((uint32_t)(c->esi + 0x6ca5bcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1003a5bc], eax */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xfffffff0u))); /* movzx eax, word ptr [ebp - 0x10] */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x006b0440u); f_006b7750(c); /* call 0x6b7750 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov eax, dword ptr [ebp - 0x18] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    (void)sub32(c, c->edi, (uint32_t)0x2u); /* cmp edi, 2 */
    if (!c->zf) goto L_006b0450; /* jne 0x6b0450 */
    W32((uint32_t)(0x6d01dcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100401dc], eax */
L_006b0450:;
    (void)sub32(c, c->edi, (uint32_t)0x1u); /* cmp edi, 1 */
    if (!c->zf) goto L_006b045a; /* jne 0x6b045a */
    W32((uint32_t)(0x6d01e0u), (uint32_t)(c->eax)); /* mov dword ptr [0x100401e0], eax */
L_006b045a:;
    { uint32_t t_ = R32((uint32_t)(c->esi + 0x6ca5c0u)); PUSH32(c, 0x006b0460u); call_indirect(c, t_); } /* call dword ptr [esi + 0x1003a5c0] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0487; /* je 0x6b0487 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->esi + 0x6ca5bcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0x1003a5bc], eax */
    PUSH32(c, 0x006b0475u); f_006b002f(c); /* call 0x6b002f */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebx), (uint32_t)(c->eax)); /* mov dword ptr [ebx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    W32((uint32_t)(0x6d01dcu), (uint32_t)(c->eax)); /* mov dword ptr [0x100401dc], eax */
L_006b0483:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006b049f; /* jmp 0x6b049f */
L_006b0487:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x6ca4a8u); /* cmp dword ptr [ebp + 8], 0x1003a4a8 */
    if (c->zf) goto L_006b0499; /* je 0x6b0499 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b0498u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0499:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x6ca5bcu))); /* mov eax, dword ptr [esi + 0x1003a5bc] */
L_006b049f:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b04a4(CPU *c) { /* FUN_100204a4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca5bcu))); /* mov eax, dword ptr [0x1003a5bc] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    if (!c->zf) goto L_006b04c4; /* jne 0x6b04c4 */
    { uint32_t v_ = 0x351u; PUSH32(c, v_); } /* push 0x351 */
    PUSH32(c, 0x006b04beu); f_006b09fd(c); /* call 0x6b09fd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x6ca5bcu), (uint32_t)(c->eax)); /* mov dword ptr [0x1003a5bc], eax */
L_006b04c4:;
    { uint32_t a_ = (uint32_t)(c->eax); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax], 0 */
    { uint32_t v_ = R32((uint32_t)(0x6ca5c8u)); PUSH32(c, v_); } /* push dword ptr [0x1003a5c8] */
    c->edi = (uint32_t)((uint32_t)0x6c66c0u); /* mov edi, 0x100366c0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x6ca5c4u)); PUSH32(c, v_); } /* push dword ptr [0x1003a5c4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = R32((uint32_t)(0x6ca5bcu)); PUSH32(c, v_); } /* push dword ptr [0x1003a5bc] */
    PUSH32(c, 0x006b04e6u); f_006b0675(c); /* call 0x6b0675 */
    c->esi = (uint32_t)((uint32_t)0x6ca5c8u); /* mov esi, 0x1003a5c8 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
L_006b04f0:;
    { uint32_t v_ = 0x6c638cu; PUSH32(c, v_); } /* push 0x1003638c */
    { uint32_t v_ = R32((uint32_t)(0x6ca5bcu)); PUSH32(c, v_); } /* push dword ptr [0x1003a5bc] */
    PUSH32(c, 0x006b0500u); f_006b4420(c); /* call 0x6b4420 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esi + 0xc] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xcu)); /* add esi, 0xc */
    { uint32_t v_ = R32((uint32_t)(c->ebx)); PUSH32(c, v_); } /* push dword ptr [ebx] */
    PUSH32(c, 0x006b050du); f_006b0d80(c); /* call 0x6b0d80 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0516; /* je 0x6b0516 */
    c->ebp = (uint32_t)(logic32(c, 0)); /* xor ebp, ebp */
L_006b0516:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0xfffffffcu)); PUSH32(c, v_); } /* push dword ptr [esi - 4] */
    { uint32_t v_ = 0x3u; PUSH32(c, v_); } /* push 3 */
    { uint32_t v_ = R32((uint32_t)(0x6ca5bcu)); PUSH32(c, v_); } /* push dword ptr [0x1003a5bc] */
    PUSH32(c, 0x006b052bu); f_006b0675(c); /* call 0x6b0675 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    (void)sub32(c, c->esi, (uint32_t)0x6ca5f8u); /* cmp esi, 0x1003a5f8 */
    if ((c->sf != c->of)) goto L_006b04f0; /* jl 0x6b04f0 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    (void)logic32(c, (uint32_t)(c->ebp & c->ebp)); /* test ebp, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (!c->zf) goto L_006b0544; /* jne 0x6b0544 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca5bcu))); /* mov eax, dword ptr [0x1003a5bc] */
    c->esp += 4; return; /* ret  */
L_006b0544:;
    { uint32_t v_ = R32((uint32_t)(0x6ca5bcu)); PUSH32(c, v_); } /* push dword ptr [0x1003a5bc] */
    PUSH32(c, 0x006b054fu); f_006b002f(c); /* call 0x6b002f */
    { uint32_t a_ = (uint32_t)(0x6ca5bcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [0x1003a5bc], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca5d4u))); /* mov eax, dword ptr [0x1003a5d4] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b055d(CPU *c) { /* FUN_1002055d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x88u)); /* sub esp, 0x88 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    (void)sub32(c, c->esi, c->edx); /* cmp esi, edx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006b0603; /* je 0x6b0603 */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x43u); /* cmp byte ptr [esi], 0x43 */
    if (!c->zf) goto L_006b05ad; /* jne 0x6b05ad */
    (void)sub8(c, R8((uint32_t)(c->esi + 0x1u)), ((uint8_t)c->edx)); /* cmp byte ptr [esi + 1], dl */
    if (!c->zf) goto L_006b05ad; /* jne 0x6b05ad */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->edx))))); } /* and byte ptr [eax + 1], dl */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x43u)); /* mov byte ptr [eax], 0x43 */
    if (c->zf) goto L_006b059b; /* je 0x6b059b */
    W16((uint32_t)(c->ecx), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx], dx */
    W16((uint32_t)(c->ecx + 0x2u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx + 2], dx */
    W16((uint32_t)(c->ecx + 0x4u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [ecx + 4], dx */
L_006b059b:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    if (c->zf) goto L_006b0670; /* je 0x6b0670 */
    W32((uint32_t)(c->ecx), (uint32_t)(c->edx)); /* mov dword ptr [ecx], edx */
    goto L_006b0670; /* jmp 0x6b0670 */
L_006b05ad:;
    c->edi = (uint32_t)((uint32_t)0x6ca530u); /* mov edi, 0x1003a530 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b05b9u); f_006b0d80(c); /* call 0x6b0d80 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b0633; /* je 0x6b0633 */
    c->ebx = (uint32_t)((uint32_t)0x6ca4acu); /* mov ebx, 0x1003a4ac */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b05cbu); f_006b0d80(c); /* call 0x6b0d80 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b0633; /* je 0x6b0633 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b05deu); f_006b069a(c); /* call 0x6b069a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0603; /* jne 0x6b0603 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = 0x6d0104u; PUSH32(c, v_); } /* push 0x10040104 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b05fcu); f_006b7a85(c); /* call 0x6b7a85 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b0607; /* jne 0x6b0607 */
L_006b0603:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006b0670; /* jmp 0x6b0670 */
L_006b0607:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(0x6d0108u))); /* movzx eax, word ptr [0x10040108] */
    W32((uint32_t)(0x6d010cu), (uint32_t)(c->eax)); /* mov dword ptr [0x1004010c], eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffff78u)); /* lea eax, [ebp - 0x88] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b0620u); f_006b0766(c); /* call 0x6b0766 */
    (void)sub8(c, R8((uint32_t)(c->esi)), (uint8_t)0x0u); /* cmp byte ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b062a; /* je 0x6b062a */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_006b062b; /* jmp 0x6b062b */
L_006b062a:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_006b062b:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b0631u); f_006b4410(c); /* call 0x6b4410 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0633:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x10], 0 */
    if (c->zf) goto L_006b064b; /* je 0x6b064b */
    { uint32_t v_ = 0x6u; PUSH32(c, v_); } /* push 6 */
    { uint32_t v_ = 0x6d0104u; PUSH32(c, v_); } /* push 0x10040104 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    PUSH32(c, 0x006b0648u); f_006b7750(c); /* call 0x6b7750 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b064b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x14u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_006b0663; /* je 0x6b0663 */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = 0x6d010cu; PUSH32(c, v_); } /* push 0x1004010c */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    PUSH32(c, 0x006b0660u); f_006b7750(c); /* call 0x6b7750 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b0663:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b066cu); f_006b4410(c); /* call 0x6b4410 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0670:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0675(CPU *c) { /* FUN_10020675 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if ((c->zf || c->sf != c->of)) goto L_006b0698; /* jle 0x6b0698 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->esp + 0x10u)); /* lea esi, [esp + 0x10] */
L_006b0683:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esi + 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x006b0692u); f_006b4420(c); /* call 0x6b4420 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0683; /* jne 0x6b0683 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b0698:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006b069a(CPU *c) { /* FUN_1002069a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x88u; PUSH32(c, v_); } /* push 0x88 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b06b0u); f_006b8330(c); /* call 0x6b8330 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006b06d8; /* je 0x6b06d8 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x2eu); /* cmp al, 0x2e */
    if (!c->zf) goto L_006b06df; /* jne 0x6b06df */
    (void)sub8(c, R8((uint32_t)(c->esi + 0x1u)), (uint8_t)0x0u); /* cmp byte ptr [esi + 1], 0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x1u)); /* lea eax, [esi + 1] */
    if (c->zf) goto L_006b06df; /* je 0x6b06df */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x80u)); /* add edi, 0x80 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b06d6u); f_006b4410(c); /* call 0x6b4410 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b06d8:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006b0761; /* jmp 0x6b0761 */
L_006b06df:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
L_006b06e3:;
    { uint32_t v_ = 0x6c1494u; PUSH32(c, v_); } /* push 0x10031494 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b06eeu); f_006b7690(c); /* call 0x6b7690 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b075e; /* je 0x6b075e */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + c->esi))); /* mov bl, byte ptr [eax + esi] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->esi)); /* lea edi, [eax + esi] */
    if (!c->zf) goto L_006b0711; /* jne 0x6b0711 */
    (void)sub32(c, c->eax, (uint32_t)0x40u); /* cmp eax, 0x40 */
    if ((c->sf == c->of)) goto L_006b075e; /* jge 0x6b075e */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2eu); /* cmp bl, 0x2e */
    if (c->zf) goto L_006b075e; /* je 0x6b075e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    goto L_006b0745; /* jmp 0x6b0745 */
L_006b0711:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x1u); /* cmp dword ptr [ebp + 0xc], 1 */
    if (!c->zf) goto L_006b072b; /* jne 0x6b072b */
    (void)sub32(c, c->eax, (uint32_t)0x40u); /* cmp eax, 0x40 */
    if ((c->sf == c->of)) goto L_006b075e; /* jge 0x6b075e */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x5fu); /* cmp bl, 0x5f */
    if (c->zf) goto L_006b075e; /* je 0x6b075e */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x40u)); /* add eax, 0x40 */
    goto L_006b0744; /* jmp 0x6b0744 */
L_006b072b:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x2u); /* cmp dword ptr [ebp + 0xc], 2 */
    if (!c->zf) goto L_006b075e; /* jne 0x6b075e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (c->zf) goto L_006b073a; /* je 0x6b073a */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2cu); /* cmp bl, 0x2c */
    if (!c->zf) goto L_006b075e; /* jne 0x6b075e */
L_006b073a:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x80u)); /* add eax, 0x80 */
L_006b0744:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_006b0745:;
    PUSH32(c, 0x006b074au); f_006af570(c); /* call 0x6af570 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2cu); /* cmp bl, 0x2c */
    if (c->zf) goto L_006b06d8; /* je 0x6b06d8 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    if (c->zf) goto L_006b06d8; /* je 0x6b06d8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp + 0xc] */
    c->esi = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea esi, [edi + 1] */
    goto L_006b06e3; /* jmp 0x6b06e3 */
L_006b075e:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006b0761:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b0766(CPU *c) { /* FUN_10020766 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006b0775u); f_006b4410(c); /* call 0x6b4410 */
    (void)sub8(c, R8((uint32_t)(c->esi + 0x40u)), (uint8_t)0x0u); /* cmp byte ptr [esi + 0x40], 0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x40u)); /* lea eax, [esi + 0x40] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b0794; /* je 0x6b0794 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6c1498u; PUSH32(c, v_); } /* push 0x10031498 */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    PUSH32(c, 0x006b0791u); f_006b0675(c); /* call 0x6b0675 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b0794:;
    (void)sub8(c, R8((uint32_t)(c->esi + 0x80u)), (uint8_t)0x0u); /* cmp byte ptr [esi + 0x80], 0 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x80u)); /* lea eax, [esi + 0x80] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_006b07b8; /* je 0x6b07b8 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x6c662cu; PUSH32(c, v_); } /* push 0x1003662c */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x10] */
    PUSH32(c, 0x006b07b5u); f_006b0675(c); /* call 0x6b0675 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b07b8:;
    c->esp += 4; return; /* ret  */
}

void f_006b07bc(CPU *c) { /* PTR_006b07bc */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov ebx, dword ptr [esp + 4] */
    c->ebp = (uint32_t)(R32((uint32_t)(c->ebx))); /* mov ebp, dword ptr [ebx] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebx + 0x18u))); /* mov esi, dword ptr [ebx + 0x18] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x0u + c->fs_base))); /* cmp esi, dword ptr fs:[0] */
    if (c->zf) goto L_006b07d7; /* je 0x6b07d7 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b07d4u); f_006af19c(c); /* call 0x6af19c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
L_006b07d7:;
    (void)sub32(c, c->esi, (uint32_t)0x0u); /* cmp esi, 0 */
    if (c->zf) goto L_006b080c; /* je 0x6b080c */
    c->eax = (uint32_t)((uint32_t)(c->ebx + 0x20u)); /* lea eax, [ebx + 0x20] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b07e5u); f_006b8388(c); /* call 0x6b8388 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_006b07ff; /* je 0x6b07ff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x20u))); /* mov eax, dword ptr [ebx + 0x20] */
    (void)sub32(c, c->eax, (uint32_t)0x56433230u); /* cmp eax, 0x56433230 */
    if (!c->zf) goto L_006b07ff; /* jne 0x6b07ff */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x24u))); /* mov eax, dword ptr [ebx + 0x24] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_006b080c; /* je 0x6b080c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b07fdu); call_indirect(c, t_); } /* call eax */
    goto L_006b080c; /* jmp 0x6b080c */
L_006b07ff:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x1cu))); /* mov eax, dword ptr [ebx + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0809u); f_006af1de(c); /* call 0x6af1de */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x8u)); /* add esp, 8 */
L_006b080c:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x14u))); /* mov eax, dword ptr [ebx + 0x14] */
    PUSH32(c, 0x006b0816u); f_006af272(c); /* call 0x6af272 */
    c->edx = (uint32_t)(c->ebx); /* mov edx, ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->edx + 0x4u))); /* mov ebx, dword ptr [edx + 4] */
    c->edi = (uint32_t)(R32((uint32_t)(c->edx + 0x8u))); /* mov edi, dword ptr [edx + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + 0xcu))); /* mov esi, dword ptr [edx + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    (void)sub32(c, c->eax, (uint32_t)0x1u); /* cmp eax, 1 */
    c->eax = (uint32_t)(adc32(c, c->eax, (uint32_t)0x0u)); /* adc eax, 0 */
    c->esp = (uint32_t)(R32((uint32_t)(c->edx + 0x10u))); /* mov esp, dword ptr [edx + 0x10] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x4u)); /* add esp, 4 */
    { uint32_t t_ = R32((uint32_t)(c->edx + 0x14u)); switch (t_) {  default: jump_indirect(c, t_, 0x006b0831u); return; } } /* jmp dword ptr [edx + 0x14] */
}

void f_006b08c0(CPU *c) { /* PTR_006b08c0 */
    PREEMPT_POLL(c);
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x40u); /* cmp cl, 0x40 */
    if (!c->cf) goto L_006b08da; /* jae 0x6b08da */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x20u); /* cmp cl, 0x20 */
    if (!c->cf) goto L_006b08d0; /* jae 0x6b08d0 */
    c->eax = (uint32_t)(({ unsigned n_ = (c->ecx & 0xff) & 31; uint32_t r_ = n_ ? ((c->eax >> n_) | (c->edx << (32 - n_))) : c->eax; if (n_) { c->cf = (c->eax >> (n_ - 1)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })); /* shrd eax, edx, cl */
    c->edx = (uint32_t)(shr32(c, c->edx, (c->ecx & 0xff))); /* shr edx, cl */
    c->esp += 4; return; /* ret  */
L_006b08d0:;
    c->eax = (uint32_t)(c->edx); /* mov eax, edx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x1fu))); /* and cl, 0x1f */
    c->eax = (uint32_t)(shr32(c, c->eax, (c->ecx & 0xff))); /* shr eax, cl */
    c->esp += 4; return; /* ret  */
L_006b08da:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    c->esp += 4; return; /* ret  */
}

void f_006b08df(CPU *c) { /* FUN_100208df */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca47cu))); /* mov eax, dword ptr [0x1003a47c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b08ea; /* je 0x6b08ea */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b08eau); call_indirect(c, t_); } /* call eax */
L_006b08ea:;
    { uint32_t v_ = 0x6c3020u; PUSH32(c, v_); } /* push 0x10033020 */
    { uint32_t v_ = 0x6c300cu; PUSH32(c, v_); } /* push 0x1003300c */
    PUSH32(c, 0x006b08f9u); f_006b09e3(c); /* call 0x6b09e3 */
    { uint32_t v_ = 0x6c3008u; PUSH32(c, v_); } /* push 0x10033008 */
    { uint32_t v_ = 0x6c3000u; PUSH32(c, v_); } /* push 0x10033000 */
    PUSH32(c, 0x006b0908u); f_006b09e3(c); /* call 0x6b09e3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->esp += 4; return; /* ret  */
}

void f_006b090c(CPU *c) { /* __exit */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [esp + 0xc] */
    PUSH32(c, 0x006b0919u); f_006b092c(c); /* call 0x6b092c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006b091d(CPU *c) { /* FUN_1002091d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    PUSH32(c, 0x006b0928u); f_006b092c(c); /* call 0x6b092c */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006b092c(CPU *c) { /* FUN_1002092c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b0932u); f_006b09d1(c); /* call 0x6b09d1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    (void)sub32(c, R32((uint32_t)(0x6d0150u)), c->edi); /* cmp dword ptr [0x10040150], edi */
    if (!c->zf) goto L_006b094e; /* jne 0x6b094e */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    { uint32_t t_ = R32((uint32_t)(0x6be06cu)); PUSH32(c, 0x006b0947u); call_indirect(c, t_); } /* call dword ptr [0x1002e06c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be068u)); PUSH32(c, 0x006b094eu); call_indirect(c, t_); } /* call dword ptr [0x1002e068] */
L_006b094e:;
    (void)sub32(c, R32((uint32_t)(c->esp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esp + 0xc], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov ebx, dword ptr [esp + 0x14] */
    W32((uint32_t)(0x6d014cu), (uint32_t)(c->edi)); /* mov dword ptr [0x1004014c], edi */
    W8((uint32_t)(0x6d0148u), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [0x10040148], bl */
    if (!c->zf) goto L_006b09a2; /* jne 0x6b09a2 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d1830u))); /* mov eax, dword ptr [0x10041830] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0991; /* je 0x6b0991 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6d182cu))); /* mov ecx, dword ptr [0x1004182c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)((uint32_t)(c->ecx + 0xfffffffcu)); /* lea esi, [ecx - 4] */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    if (c->cf) goto L_006b0990; /* jb 0x6b0990 */
L_006b097d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0985; /* je 0x6b0985 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b0985u); call_indirect(c, t_); } /* call eax */
L_006b0985:;
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x4u)); /* sub esi, 4 */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6d1830u))); /* cmp esi, dword ptr [0x10041830] */
    if (!c->cf) goto L_006b097d; /* jae 0x6b097d */
L_006b0990:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b0991:;
    { uint32_t v_ = 0x6c302cu; PUSH32(c, v_); } /* push 0x1003302c */
    { uint32_t v_ = 0x6c3024u; PUSH32(c, v_); } /* push 0x10033024 */
    PUSH32(c, 0x006b09a0u); f_006b09e3(c); /* call 0x6b09e3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b09a2:;
    { uint32_t v_ = 0x6c3038u; PUSH32(c, v_); } /* push 0x10033038 */
    { uint32_t v_ = 0x6c3030u; PUSH32(c, v_); } /* push 0x10033030 */
    PUSH32(c, 0x006b09b1u); f_006b09e3(c); /* call 0x6b09e3 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->ebx & c->ebx)); /* test ebx, ebx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    if (c->zf) goto L_006b09bf; /* je 0x6b09bf */
    PUSH32(c, 0x006b09bdu); f_006b09da(c); /* call 0x6b09da */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
L_006b09bf:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    W32((uint32_t)(0x6d0150u), (uint32_t)(c->edi)); /* mov dword ptr [0x10040150], edi */
    { uint32_t t_ = R32((uint32_t)(0x6be064u)); PUSH32(c, 0x006b09cfu); call_indirect(c, t_); } /* call dword ptr [0x1002e064] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006b09cf(CPU *c) { /* PTR_006b09cf */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006b09d1(CPU *c) { /* FUN_100209d1 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x006b09d8u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b09da(CPU *c) { /* FUN_100209da */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0xdu; PUSH32(c, v_); } /* push 0xd */
    PUSH32(c, 0x006b09e1u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b09e3(CPU *c) { /* FUN_100209e3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
L_006b09e8:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->esp + 0xcu))); /* cmp esi, dword ptr [esp + 0xc] */
    if (!c->cf) goto L_006b09fb; /* jae 0x6b09fb */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b09f6; /* je 0x6b09f6 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b09f6u); call_indirect(c, t_); } /* call eax */
L_006b09f6:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    goto L_006b09e8; /* jmp 0x6b09e8 */
L_006b09fb:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b09fd(CPU *c) { /* _malloc */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x6d0358u)); PUSH32(c, v_); } /* push dword ptr [0x10040358] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [esp + 8] */
    PUSH32(c, 0x006b0a0cu); f_006b0a0f(c); /* call 0x6b0a0f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b0a0f(CPU *c) { /* __nh_malloc */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->esp + 0x4u)), (uint32_t)0xffffffe0u); /* cmp dword ptr [esp + 4], -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b0a38; /* ja 0x6b0a38 */
L_006b0a16:;
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006b0a1fu); f_006b0a3b(c); /* call 0x6b0a3b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0a3a; /* jne 0x6b0a3a */
    (void)sub32(c, R32((uint32_t)(c->esp + 0x8u)), c->eax); /* cmp dword ptr [esp + 8], eax */
    if (c->zf) goto L_006b0a3a; /* je 0x6b0a3a */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x4u)); PUSH32(c, v_); } /* push dword ptr [esp + 4] */
    PUSH32(c, 0x006b0a33u); f_006b83ff(c); /* call 0x6b83ff */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0a16; /* jne 0x6b0a16 */
L_006b0a38:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b0a3a:;
    c->esp += 4; return; /* ret  */
}

void f_006b0a3b(CPU *c) { /* FUN_10020a3b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c14a0u; PUSH32(c, v_); } /* push 0x100314a0 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0xcu)); /* sub esp, 0xc */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d06e8u))); /* mov eax, dword ptr [0x100406e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006b0aab; /* jne 0x6b0aab */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6d06e0u))); /* cmp esi, dword ptr [0x100406e0] */
    if ((!c->cf && !c->zf)) goto L_006b0b0a; /* ja 0x6b0b0a */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0a7eu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0a89u); f_006b5c0b(c); /* call 0x6b5c0b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0a96u); f_006b0aa2(c); /* call 0x6b0aa2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0b0a; /* je 0x6b0b0a */
    goto L_006b0b28; /* jmp 0x6b0b28 */
L_006b0aab:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b0b0a; /* jne 0x6b0b0a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0abf; /* je 0x6b0abf */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_006b0ac2; /* jmp 0x6b0ac2 */
L_006b0abf:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b0ac2:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if ((!c->cf && !c->zf)) goto L_006b0afb; /* ja 0x6b0afb */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0ad4u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0ae7u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0af4u); f_006b0b01(c); /* call 0x6b0b01 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b0b28; /* jne 0x6b0b28 */
L_006b0afb:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_006b0b1a; /* jmp 0x6b0b1a */
L_006b0b0a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b0b14; /* jne 0x6b0b14 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006b0b14:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
L_006b0b1a:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0b28u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
L_006b0b28:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0aa2(CPU *c) { /* FUN_10020aa2 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0aa9u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b0aab(CPU *c) { /* PTR_006b0aab */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_006b0b0a(c); return; } /* jne 0x6b0b0a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0abf; /* je 0x6b0abf */
    c->esi = (uint32_t)((uint32_t)(c->eax + 0xfu)); /* lea esi, [eax + 0xf] */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_006b0ac2; /* jmp 0x6b0ac2 */
L_006b0abf:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b0ac2:;
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if ((!c->cf && !c->zf)) goto L_006b0afb; /* ja 0x6b0afb */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0ad4u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0ae7u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0af4u); f_006b0b01(c); /* call 0x6b0b01 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b28(c); return; } /* jne 0x6b0b28 */
L_006b0afb:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_006b0b1a(c); return; } /* jmp 0x6b0b1a */
}

void f_006b0abf(CPU *c) { /* PTR_006b0abf */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if ((!c->cf && !c->zf)) goto L_006b0afb; /* ja 0x6b0afb */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0ad4u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0ae7u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0af4u); f_006b0b01(c); /* call 0x6b0b01 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b28(c); return; } /* jne 0x6b0b28 */
L_006b0afb:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_006b0b1a(c); return; } /* jmp 0x6b0b1a */
}

void f_006b0ac2(CPU *c) { /* PTR_006b0ac2 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 8], esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if ((!c->cf && !c->zf)) goto L_006b0afb; /* ja 0x6b0afb */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0ad4u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0ae7u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0af4u); f_006b0b01(c); /* call 0x6b0b01 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov eax, dword ptr [ebp - 0x1c] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b28(c); return; } /* jne 0x6b0b28 */
L_006b0afb:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_006b0b1a(c); return; } /* jmp 0x6b0b1a */
}

void f_006b0afb(CPU *c) { /* PTR_006b0afb */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { f_006b0b1a(c); return; } /* jmp 0x6b0b1a */
}

void f_006b0afe(CPU *c) { /* PTR_006b0afe */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { f_006b0b01(c); return; }
}

void f_006b0b01(CPU *c) { /* FUN_10020b01 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0b08u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b0b0a(CPU *c) { /* PTR_006b0b0a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b0b14; /* jne 0x6b0b14 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006b0b14:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0b28u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0b14(CPU *c) { /* PTR_006b0b14 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xfu)); /* add eax, 0xf */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xf0u))); /* and al, 0xf0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0b28u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0b1a(CPU *c) { /* PTR_006b0b1a */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0b28u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0b28(CPU *c) { /* PTR_006b0b28 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0b37(CPU *c) { /* FUN_10020b37 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c14b8u; PUSH32(c, v_); } /* push 0x100314b8 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { int64_t r_ = (int64_t)(int32_t)c->esi * (int32_t)R32((uint32_t)(c->ebp + 0xcu)); c->esi = (uint32_t)(r_); c->cf = c->of = r_ != (int32_t)r_; } /* imul esi, dword ptr [ebp + 0xc] */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b0b80; /* ja 0x6b0b80 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    (void)sub32(c, c->esi, c->ebx); /* cmp esi, ebx */
    if (!c->zf) goto L_006b0b75; /* jne 0x6b0b75 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b0b75:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    goto L_006b0b82; /* jmp 0x6b0b82 */
L_006b0b80:;
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
L_006b0b82:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b0c36; /* ja 0x6b0c36 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d06e8u))); /* mov eax, dword ptr [0x100406e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006b0bd9; /* jne 0x6b0bd9 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0x6d06e0u))); /* cmp edi, dword ptr [0x100406e0] */
    if ((!c->cf && !c->zf)) goto L_006b0c1f; /* ja 0x6b0c1f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0baau); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b0bb4u); f_006b5c0b(c); /* call 0x6b5c0b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0bc1u); f_006b0bd0(c); /* call 0x6b0bd0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_006b0c24; /* je 0x6b0c24 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    goto L_006b0c13; /* jmp 0x6b0c13 */
L_006b0bd9:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b0c1f; /* jne 0x6b0c1f */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if ((!c->cf && !c->zf)) goto L_006b0c1f; /* ja 0x6b0c1f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0bedu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0c00u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0c0du); f_006b0c59(c); /* call 0x6b0c59 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_006b0c24; /* je 0x6b0c24 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
L_006b0c13:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x006b0c1cu); f_006b8330(c); /* call 0x6b8330 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b0c1f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_006b0c62; /* jne 0x6b0c62 */
L_006b0c24:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0c33u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
L_006b0c36:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) goto L_006b0c62; /* jne 0x6b0c62 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->ebx); /* cmp dword ptr [0x10040358], ebx */
    if (c->zf) goto L_006b0c62; /* je 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0c49u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b0b82; /* jne 0x6b0b82 */
    goto L_006b0c65; /* jmp 0x6b0c65 */
L_006b0c62:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
L_006b0c65:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0b82(CPU *c) { /* PTR_006b0b82 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x20], ebx */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) { f_006b0c36(c); return; } /* ja 0x6b0c36 */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d06e8u))); /* mov eax, dword ptr [0x100406e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) { f_006b0bd9(c); return; } /* jne 0x6b0bd9 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov edi, dword ptr [ebp - 0x1c] */
    (void)sub32(c, c->edi, R32((uint32_t)(0x6d06e0u))); /* cmp edi, dword ptr [0x100406e0] */
    if ((!c->cf && !c->zf)) { f_006b0c1f(c); return; } /* ja 0x6b0c1f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0baau); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b0bb4u); f_006b5c0b(c); /* call 0x6b5c0b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0bc1u); f_006b0bd0(c); /* call 0x6b0bd0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) { f_006b0c24(c); return; } /* je 0x6b0c24 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { f_006b0c13(c); return; } /* jmp 0x6b0c13 */
}

void f_006b0bcb(CPU *c) { /* PTR_006b0bcb */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_006b0bd0(c); return; }
}

void f_006b0bd0(CPU *c) { /* FUN_10020bd0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0bd7u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b0bd9(CPU *c) { /* PTR_006b0bd9 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b0c1f; /* jne 0x6b0c1f */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if ((!c->cf && !c->zf)) goto L_006b0c1f; /* ja 0x6b0c1f */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0bedu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(shr32(c, c->eax, 4)); /* shr eax, 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0c00u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b0c0du); f_006b0c59(c); /* call 0x6b0c59 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (c->zf) goto L_006b0c24; /* je 0x6b0c24 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x006b0c1cu); f_006b8330(c); /* call 0x6b8330 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b0c1f:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
L_006b0c24:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0c33u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->ebx); /* cmp dword ptr [0x10040358], ebx */
    if (c->zf) { f_006b0c62(c); return; } /* je 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0c49u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b82(c); return; } /* jne 0x6b0b82 */
    { f_006b0c65(c); return; } /* jmp 0x6b0c65 */
}

void f_006b0c13(CPU *c) { /* PTR_006b0c13 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x20] */
    PUSH32(c, 0x006b0c1cu); f_006b8330(c); /* call 0x6b8330 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0c33u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->ebx); /* cmp dword ptr [0x10040358], ebx */
    if (c->zf) { f_006b0c62(c); return; } /* je 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0c49u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b82(c); return; } /* jne 0x6b0b82 */
    { f_006b0c65(c); return; } /* jmp 0x6b0c65 */
}

void f_006b0c1f(CPU *c) { /* PTR_006b0c1f */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0c33u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->ebx); /* cmp dword ptr [0x10040358], ebx */
    if (c->zf) { f_006b0c62(c); return; } /* je 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0c49u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b82(c); return; } /* jne 0x6b0b82 */
    { f_006b0c65(c); return; } /* jmp 0x6b0c65 */
}

void f_006b0c24(CPU *c) { /* PTR_006b0c24 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x8u; PUSH32(c, v_); } /* push 8 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b0c33u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->ebx); /* cmp dword ptr [0x10040358], ebx */
    if (c->zf) { f_006b0c62(c); return; } /* je 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0c49u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b82(c); return; } /* jne 0x6b0b82 */
    { f_006b0c65(c); return; } /* jmp 0x6b0c65 */
}

void f_006b0c36(CPU *c) { /* PTR_006b0c36 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe0u)), c->ebx); /* cmp dword ptr [ebp - 0x20], ebx */
    if (!c->zf) { f_006b0c62(c); return; } /* jne 0x6b0c62 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->ebx); /* cmp dword ptr [0x10040358], ebx */
    if (c->zf) { f_006b0c62(c); return; } /* je 0x6b0c62 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b0c49u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b0b82(c); return; } /* jne 0x6b0b82 */
    { f_006b0c65(c); return; } /* jmp 0x6b0c65 */
}

void f_006b0c54(CPU *c) { /* PTR_006b0c54 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    { f_006b0c59(c); return; }
}

void f_006b0c59(CPU *c) { /* FUN_10020c59 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b0c60u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b0c62(CPU *c) { /* PTR_006b0c62 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0c65(CPU *c) { /* PTR_006b0c65 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0c74(CPU *c) { /* FUN_10020c74 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x6be074u))); /* mov esi, dword ptr [0x1002e074] */
    { uint32_t v_ = R32((uint32_t)(0x6ca654u)); PUSH32(c, v_); } /* push dword ptr [0x1003a654] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006b0c83u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x6ca644u)); PUSH32(c, v_); } /* push dword ptr [0x1003a644] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006b0c8bu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x6ca634u)); PUSH32(c, v_); } /* push dword ptr [0x1003a634] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006b0c93u); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = R32((uint32_t)(0x6ca614u)); PUSH32(c, v_); } /* push dword ptr [0x1003a614] */
    { uint32_t t_ = c->esi; PUSH32(c, 0x006b0c9bu); call_indirect(c, t_); } /* call esi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b0c9d(CPU *c) { /* FUN_10020c9d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(0x6be078u))); /* mov edi, dword ptr [0x1002e078] */
    c->esi = (uint32_t)((uint32_t)0x6ca610u); /* mov esi, 0x1003a610 */
L_006b0caa:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b0cdb; /* je 0x6b0cdb */
    (void)sub32(c, c->esi, (uint32_t)0x6ca654u); /* cmp esi, 0x1003a654 */
    if (c->zf) goto L_006b0cdb; /* je 0x6b0cdb */
    (void)sub32(c, c->esi, (uint32_t)0x6ca644u); /* cmp esi, 0x1003a644 */
    if (c->zf) goto L_006b0cdb; /* je 0x6b0cdb */
    (void)sub32(c, c->esi, (uint32_t)0x6ca634u); /* cmp esi, 0x1003a634 */
    if (c->zf) goto L_006b0cdb; /* je 0x6b0cdb */
    (void)sub32(c, c->esi, (uint32_t)0x6ca614u); /* cmp esi, 0x1003a614 */
    if (c->zf) goto L_006b0cdb; /* je 0x6b0cdb */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006b0cd3u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    PUSH32(c, 0x006b0cdau); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0cdb:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x4u)); /* add esi, 4 */
    (void)sub32(c, c->esi, (uint32_t)0x6ca6d0u); /* cmp esi, 0x1003a6d0 */
    if ((c->sf != c->of)) goto L_006b0caa; /* jl 0x6b0caa */
    { uint32_t v_ = R32((uint32_t)(0x6ca634u)); PUSH32(c, v_); } /* push dword ptr [0x1003a634] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006b0ceeu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x6ca644u)); PUSH32(c, v_); } /* push dword ptr [0x1003a644] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006b0cf6u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x6ca654u)); PUSH32(c, v_); } /* push dword ptr [0x1003a654] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006b0cfeu); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = R32((uint32_t)(0x6ca614u)); PUSH32(c, v_); } /* push dword ptr [0x1003a614] */
    { uint32_t t_ = c->edi; PUSH32(c, 0x006b0d06u); call_indirect(c, t_); } /* call edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b0d09(CPU *c) { /* FUN_10020d09 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    (void)sub32(c, R32((uint32_t)(c->eax * 4 + 0x6ca610u)), (uint32_t)0x0u); /* cmp dword ptr [eax*4 + 0x1003a610], 0 */
    c->esi = (uint32_t)((uint32_t)(c->eax * 4 + 0x6ca610u)); /* lea esi, [eax*4 + 0x1003a610] */
    if (!c->zf) goto L_006b0d5f; /* jne 0x6b0d5f */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x18u; PUSH32(c, v_); } /* push 0x18 */
    PUSH32(c, 0x006b0d29u); f_006b09fd(c); /* call 0x6b09fd */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (!c->zf) goto L_006b0d38; /* jne 0x6b0d38 */
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x006b0d37u); f_006afd31(c); /* call 0x6afd31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0d38:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x006b0d3fu); f_006b0d09(c); /* call 0x6b0d09 */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x0u); /* cmp dword ptr [esi], 0 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (!c->zf) goto L_006b0d50; /* jne 0x6b0d50 */
    { uint32_t t_ = R32((uint32_t)(0x6be074u)); PUSH32(c, 0x006b0d4cu); call_indirect(c, t_); } /* call dword ptr [0x1002e074] */
    W32((uint32_t)(c->esi), (uint32_t)(c->edi)); /* mov dword ptr [esi], edi */
    goto L_006b0d56; /* jmp 0x6b0d56 */
L_006b0d50:;
    PUSH32(c, 0x006b0d55u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b0d56:;
    { uint32_t v_ = 0x11u; PUSH32(c, v_); } /* push 0x11 */
    PUSH32(c, 0x006b0d5du); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_006b0d5f:;
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t t_ = R32((uint32_t)(0x6be07cu)); PUSH32(c, 0x006b0d67u); call_indirect(c, t_); } /* call dword ptr [0x1002e07c] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b0d6a(CPU *c) { /* FUN_10020d6a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->eax * 4 + 0x6ca610u)); PUSH32(c, v_); } /* push dword ptr [eax*4 + 0x1003a610] */
    { uint32_t t_ = R32((uint32_t)(0x6be080u)); PUSH32(c, 0x006b0d7du); call_indirect(c, t_); } /* call dword ptr [0x1002e080] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b0d80(CPU *c) { /* _strcmp */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_006b0dcc; /* jne 0x6b0dcc */
L_006b0d90:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx))); /* mov eax, dword ptr [edx] */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006b0dc0; /* je 0x6b0dc0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_006b0dc0; /* je 0x6b0dc0 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx + 0x2u))); /* cmp al, byte ptr [ecx + 2] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006b0dc0; /* je 0x6b0dc0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x3u))); /* cmp ah, byte ptr [ecx + 3] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x4u)); /* add edx, 4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (!c->zf) goto L_006b0d90; /* jne 0x6b0d90 */
    c->edi = (uint32_t)(c->edi); /* mov edi, edi */
L_006b0dc0:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006b0dc4:;
    c->eax = (uint32_t)(sbb32(c, c->eax, c->eax)); /* sbb eax, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 1)); /* shl eax, 1 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->esp += 4; return; /* ret  */
L_006b0dcc:;
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x1u)); /* test edx, 1 */
    if (c->zf) goto L_006b0de8; /* je 0x6b0de8 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov al, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006b0dc0; /* je 0x6b0dc0 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x2u)); /* test edx, 2 */
    if (c->zf) goto L_006b0d90; /* je 0x6b0d90 */
L_006b0de8:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->edx))); /* mov ax, word ptr [edx] */
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x2u)); /* add edx, 2 */
    (void)sub8(c, ((uint8_t)c->eax), R8((uint32_t)(c->ecx))); /* cmp al, byte ptr [ecx] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | ((uint8_t)c->eax)))); /* or al, al */
    if (c->zf) goto L_006b0dc0; /* je 0x6b0dc0 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), R8((uint32_t)(c->ecx + 0x1u))); /* cmp ah, byte ptr [ecx + 1] */
    if (!c->zf) goto L_006b0dc4; /* jne 0x6b0dc4 */
    c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) | ((uint8_t)(c->eax >> 8))))) << 8); /* or ah, ah */
    if (c->zf) goto L_006b0dc0; /* je 0x6b0dc0 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x2u)); /* add ecx, 2 */
    goto L_006b0d90; /* jmp 0x6b0d90 */
}

void f_006b0e04(CPU *c) { /* FUN_10020e04 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if ((!c->cf && !c->zf)) goto L_006b0e22; /* ja 0x6b0e22 */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ecx + c->eax * 2))); /* movzx eax, word ptr [ecx + eax*2] */
    goto L_006b0e74; /* jmp 0x6b0e74 */
L_006b0e22:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov esi, dword ptr [0x1003a6d0] */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 8)); /* sar ecx, 8 */
    c->edx = (uint32_t)((uint32_t)((uint8_t)c->ecx)); /* movzx edx, cl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi + c->edx * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [esi + edx*2 + 1], 0x80 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (c->zf) goto L_006b0e47; /* je 0x6b0e47 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 2], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [ebp - 4], cl */
    W8((uint32_t)(c->ebp + 0xfffffffdu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 3], al */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    goto L_006b0e50; /* jmp 0x6b0e50 */
L_006b0e47:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 3], 0 */
    W8((uint32_t)(c->ebp + 0xfffffffcu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 4], al */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
L_006b0e50:;
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
    PUSH32(c, 0x006b0e67u); f_006b841a(c); /* call 0x6b841a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b0e70; /* jne 0x6b0e70 */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006b0e70:;
    c->eax = (uint32_t)((uint32_t)R16((uint32_t)(c->ebp + 0xau))); /* movzx eax, word ptr [ebp + 0xa] */
L_006b0e74:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & R32((uint32_t)(c->ebp + 0xcu))))); /* and eax, dword ptr [ebp + 0xc] */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b0e80(CPU *c) { /* __allmul */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov ecx, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ecx, dword ptr [esp + 0xc] */
    if (!c->zf) goto L_006b0e99; /* jne 0x6b0e99 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint64_t r_ = (uint64_t)c->eax * c->ecx; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; } /* mul ecx */
    c->esp += 20; return; /* ret 0x10 */
L_006b0e99:;
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

void f_006b0eb4(CPU *c) { /* FUN_10020eb4 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov esi, dword ptr [ebp + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->edi); /* cmp dword ptr [esi], edi */
    if (c->zf) goto L_006b0eca; /* je 0x6b0eca */
    PUSH32(c, 0x006b0ecau); f_006b18f9(c); /* call 0x6b18f9 */
L_006b0eca:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x66u)); /* test byte ptr [eax + 4], 0x66 */
    if (c->zf) goto L_006b0ef2; /* je 0x6b0ef2 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x4u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 4], 0 */
    if (c->zf) goto L_006b0f48; /* je 0x6b0f48 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_006b0f48; /* jne 0x6b0f48 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b0eedu); f_006b1209(c); /* call 0x6b1209 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_006b0f48; /* jmp 0x6b0f48 */
L_006b0ef2:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0xc], 0 */
    if (c->zf) goto L_006b0f48; /* je 0x6b0f48 */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_006b0f2c; /* jne 0x6b0f2c */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), c->edi); /* cmp dword ptr [eax + 0x14], edi */
    if ((c->cf || c->zf)) goto L_006b0f2c; /* jbe 0x6b0f2c */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006b0f2c; /* je 0x6b0f2c */
    c->edx = (uint32_t)((uint32_t)R8((uint32_t)(c->ebp + 0x24u))); /* movzx edx, byte ptr [ebp + 0x24] */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = c->ecx; PUSH32(c, 0x006b0f27u); call_indirect(c, t_); } /* call ecx */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_006b0f4b; /* jmp 0x6b0f4b */
L_006b0f2c:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b0f45u); f_006b0f4f(c); /* call 0x6b0f4f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
L_006b0f48:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006b0f4b:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b0f4f(CPU *c) { /* FUN_10020f4f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffecu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [ebp - 0x14], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x8u))); /* mov eax, dword ptr [eax + 8] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf != c->of)) goto L_006b0f6f; /* jl 0x6b0f6f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov ecx, dword ptr [ebp + 0x18] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ecx + 0x4u))); /* cmp eax, dword ptr [ecx + 4] */
    if ((c->sf != c->of)) goto L_006b0f74; /* jl 0x6b0f74 */
L_006b0f6f:;
    PUSH32(c, 0x006b0f74u); f_006b18f9(c); /* call 0x6b18f9 */
L_006b0f74:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    c->ebx = (uint32_t)((uint32_t)0xe06d7363u); /* mov ebx, 0xe06d7363 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)((uint32_t)0x19930520u); /* mov edi, 0x19930520 */
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_006b10d7; /* jne 0x6b10d7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_006b0ff4; /* jne 0x6b0ff4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_006b0ff4; /* jne 0x6b0ff4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_006b0ff4; /* jne 0x6b0ff4 */
    PUSH32(c, 0x006b0fa2u); f_006b1791(c); /* call 0x6b1791 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x6cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x6c], 0 */
    if (c->zf) goto L_006b10d2; /* je 0x6b10d2 */
    PUSH32(c, 0x006b0fb1u); f_006b1791(c); /* call 0x6b1791 */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov esi, dword ptr [eax + 0x6c] */
    PUSH32(c, 0x006b0fb9u); f_006b1791(c); /* call 0x6b1791 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0x10u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0x10], eax */
    W8((uint32_t)(c->ebp + 0xffffffecu), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x14], 1 */
    PUSH32(c, 0x006b0fcbu); f_006b8563(c); /* call 0x6b8563 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b0fd6; /* jne 0x6b0fd6 */
    PUSH32(c, 0x006b0fd6u); f_006b18f9(c); /* call 0x6b18f9 */
L_006b0fd6:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_006b10d7; /* jne 0x6b10d7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_006b0ff4; /* jne 0x6b0ff4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_006b0ff4; /* jne 0x6b0ff4 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x1c], 0 */
    if (!c->zf) goto L_006b0ff4; /* jne 0x6b0ff4 */
    PUSH32(c, 0x006b0ff4u); f_006b18f9(c); /* call 0x6b18f9 */
L_006b0ff4:;
    (void)sub32(c, R32((uint32_t)(c->esi)), c->ebx); /* cmp dword ptr [esi], ebx */
    if (!c->zf) goto L_006b10d7; /* jne 0x6b10d7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [esi + 0x10], 3 */
    if (!c->zf) goto L_006b10d7; /* jne 0x6b10d7 */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), c->edi); /* cmp dword ptr [esi + 0x14], edi */
    if (!c->zf) goto L_006b10d7; /* jne 0x6b10d7 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffe8u)); /* lea eax, [ebp - 0x18] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x006b1026u); f_006af11e(c); /* call 0x6af11e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
L_006b102b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xffffffe8u))); /* cmp eax, dword ptr [ebp - 0x18] */
    if (!c->cf) goto L_006b10c2; /* jae 0x6b10c2 */
    (void)sub32(c, R32((uint32_t)(c->ebx)), c->edi); /* cmp dword ptr [ebx], edi */
    if ((!c->zf && c->sf == c->of)) goto L_006b10b7; /* jg 0x6b10b7 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->ebx + 0x4u))); /* cmp edi, dword ptr [ebx + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_006b10b7; /* jg 0x6b10b7 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0x10u))); /* mov eax, dword ptr [ebx + 0x10] */
    W32((uint32_t)(c->ebp + 0x8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 8], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xcu))); /* mov eax, dword ptr [ebx + 0xc] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if ((c->zf || c->sf != c->of)) goto L_006b10b4; /* jle 0x6b10b4 */
L_006b1050:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x1cu))); /* mov eax, dword ptr [esi + 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xcu))); /* mov eax, dword ptr [eax + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0x4u)); /* lea edi, [eax + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    if ((c->zf || c->sf != c->of)) goto L_006b1081; /* jle 0x6b1081 */
L_006b1062:;
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esi + 0x1c] */
    { uint32_t v_ = R32((uint32_t)(c->edi)); PUSH32(c, v_); } /* push dword ptr [edi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b106fu); f_006b11ac(c); /* call 0x6b11ac */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b1090; /* jne 0x6b1090 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->edi = (uint32_t)(add32(c, c->edi, (uint32_t)0x4u)); /* add edi, 4 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->eax); /* cmp dword ptr [ebp - 8], eax */
    if ((!c->zf && c->sf == c->of)) goto L_006b1062; /* jg 0x6b1062 */
L_006b1081:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0x8u); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x10u))); } /* add dword ptr [ebp + 8], 0x10 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_006b1050; /* jg 0x6b1050 */
    goto L_006b10b4; /* jmp 0x6b10b4 */
L_006b1090:;
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
    PUSH32(c, 0x006b10b1u); f_006b12a7(c); /* call 0x6b12a7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_006b10b4:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov edi, dword ptr [ebp - 0x10] */
L_006b10b7:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x14u)); /* add ebx, 0x14 */
    goto L_006b102b; /* jmp 0x6b102b */
L_006b10c2:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (c->zf) goto L_006b10d2; /* je 0x6b10d2 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b10d0u); f_006b162b(c); /* call 0x6b162b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b10d2:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006b10d7:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x1cu)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x1c], 0 */
    if (!c->zf) goto L_006b10fd; /* jne 0x6b10fd */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b10f8u); f_006b1102(c); /* call 0x6b1102 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x20u)); /* add esp, 0x20 */
    goto L_006b10d2; /* jmp 0x6b10d2 */
L_006b10fd:;
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006b1102(CPU *c) { /* FUN_10021102 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b110eu); f_006b1791(c); /* call 0x6b1791 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x68u)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x68], 0 */
    if (c->zf) goto L_006b1135; /* je 0x6b1135 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x24u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b112eu); f_006aeff3(c); /* call 0x6aeff3 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b11a8; /* jne 0x6b11a8 */
L_006b1135:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov edi, dword ptr [ebp + 0x1c] */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffffcu)); /* lea eax, [ebp - 4] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    PUSH32(c, 0x006b114cu); f_006af11e(c); /* call 0x6af11e */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b1151:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov eax, dword ptr [ebp - 4] */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u))); /* cmp eax, dword ptr [ebp - 8] */
    if (!c->cf) goto L_006b11a8; /* jae 0x6b11a8 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi))); /* cmp edi, dword ptr [esi] */
    if ((c->sf != c->of)) goto L_006b11a0; /* jl 0x6b11a0 */
    (void)sub32(c, c->edi, R32((uint32_t)(c->esi + 0x4u))); /* cmp edi, dword ptr [esi + 4] */
    if ((!c->zf && c->sf == c->of)) goto L_006b11a0; /* jg 0x6b11a0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ecx, dword ptr [esi + 0x10] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffff4u))); /* mov ecx, dword ptr [eax - 0xc] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006b117a; /* je 0x6b117a */
    (void)sub8(c, R8((uint32_t)(c->ecx + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [ecx + 8], 0 */
    if (!c->zf) goto L_006b11a0; /* jne 0x6b11a0 */
L_006b117a:;
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
    PUSH32(c, 0x006b119du); f_006b12a7(c); /* call 0x6b12a7 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
L_006b11a0:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 4] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x14u)); /* add esi, 0x14 */
    goto L_006b1151; /* jmp 0x6b1151 */
L_006b11a8:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b11ac(CPU *c) { /* FUN_100211ac */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x4u))); /* mov eax, dword ptr [edi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1203; /* je 0x6b1203 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    c->edx = (uint32_t)((uint32_t)(c->eax + 0x8u)); /* lea edx, [eax + 8] */
    if (c->zf) goto L_006b1203; /* je 0x6b1203 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ecx, dword ptr [esi + 4] */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->zf) goto L_006b11dd; /* je 0x6b11dd */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    PUSH32(c, 0x006b11d7u); f_006b0d80(c); /* call 0x6b0d80 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b11ff; /* jne 0x6b11ff */
L_006b11dd:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x2u)); /* test byte ptr [esi], 2 */
    if (c->zf) goto L_006b11e7; /* je 0x6b11e7 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x8u)); /* test byte ptr [edi], 8 */
    if (c->zf) goto L_006b11ff; /* je 0x6b11ff */
L_006b11e7:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x14u))); /* mov eax, dword ptr [esp + 0x14] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_006b11f6; /* je 0x6b11f6 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x1u)); /* test byte ptr [edi], 1 */
    if (c->zf) goto L_006b11ff; /* je 0x6b11ff */
L_006b11f6:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x2u)); /* test al, 2 */
    if (c->zf) goto L_006b1203; /* je 0x6b1203 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->edi)) & (uint8_t)0x2u)); /* test byte ptr [edi], 2 */
    if (!c->zf) goto L_006b1203; /* jne 0x6b1203 */
L_006b11ff:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006b1206; /* jmp 0x6b1206 */
L_006b1203:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
L_006b1206:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b1209(CPU *c) { /* FUN_10021209 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c14d0u; PUSH32(c, v_); } /* push 0x100314d0 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
L_006b123b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_006b1295; /* je 0x6b1295 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_006b124a; /* jle 0x6b124a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_006b124f; /* jl 0x6b124f */
L_006b124a:;
    PUSH32(c, 0x006b124fu); f_006b18f9(c); /* call 0x6b18f9 */
L_006b124f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b126a; /* je 0x6b126a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b126au); f_006b16c0(c); /* call 0x6b16c0 */
L_006b126a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_006b128a; /* jmp 0x6b128a */
L_006b128a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_006b123b; /* jmp 0x6b123b */
L_006b1295:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b123b(CPU *c) { /* PTR_006b123b */
    PREEMPT_POLL(c);
L_006b123b:;
    (void)sub32(c, c->esi, R32((uint32_t)(c->ebp + 0x14u))); /* cmp esi, dword ptr [ebp + 0x14] */
    if (c->zf) goto L_006b1295; /* je 0x6b1295 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if ((c->zf || c->sf != c->of)) goto L_006b124a; /* jle 0x6b124a */
    (void)sub32(c, c->esi, R32((uint32_t)(c->edi + 0x4u))); /* cmp esi, dword ptr [edi + 4] */
    if ((c->sf != c->of)) goto L_006b124f; /* jl 0x6b124f */
L_006b124a:;
    PUSH32(c, 0x006b124fu); f_006b18f9(c); /* call 0x6b18f9 */
L_006b124f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8 + 0x4u))); /* mov eax, dword ptr [eax + esi*8 + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b126a; /* je 0x6b126a */
    { uint32_t v_ = 0x103u; PUSH32(c, v_); } /* push 0x103 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b126au); f_006b16c0(c); /* call 0x6b16c0 */
L_006b126a:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    goto L_006b128a; /* jmp 0x6b128a */
L_006b128a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    goto L_006b123b; /* jmp 0x6b123b */
L_006b1295:;
    W32((uint32_t)(c->ebx + 0x8u), (uint32_t)(c->esi)); /* mov dword ptr [ebx + 8], esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1270(CPU *c) { /* PTR_006b1270 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x006b1278u); f_006afa3d(c); /* call 0x6afa3d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b127a(CPU *c) { /* PTR_006b127a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov edi, dword ptr [ebp + 0x10] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov esi, dword ptr [ebp - 0x1c] */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi + 0x8u))); /* mov eax, dword ptr [edi + 8] */
    c->esi = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 8))); /* mov esi, dword ptr [eax + esi*8] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x1c], esi */
    { f_006b123b(c); return; } /* jmp 0x6b123b */
}

void f_006b12a7(CPU *c) { /* FUN_100212a7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x20u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x20], 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov ebx, dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    if (c->zf) goto L_006b12c9; /* je 0x6b12c9 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b12c6u); f_006b1467(c); /* call 0x6b1467 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b12c9:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x2cu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0x2c], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    if (!c->zf) goto L_006b12d5; /* jne 0x6b12d5 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    goto L_006b12d8; /* jmp 0x6b12d8 */
L_006b12d5:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x2cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x2c] */
L_006b12d8:;
    PUSH32(c, 0x006b12ddu); f_006aeef5(c); /* call 0x6aeef5 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x24u))); /* mov esi, dword ptr [ebp + 0x24] */
    { uint32_t v_ = R32((uint32_t)(c->esi)); PUSH32(c, v_); } /* push dword ptr [esi] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b12eeu); f_006b1209(c); /* call 0x6b1209 */
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
    PUSH32(c, 0x006b130fu); f_006b1322(c); /* call 0x6b1322 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b131d; /* je 0x6b131d */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b131du); f_006aeeb3(c); /* call 0x6aeeb3 */
L_006b131d:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b1322(CPU *c) { /* FUN_10021322 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c14e0u; PUSH32(c, v_); } /* push 0x100314e0 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
    PUSH32(c, 0x006b1360u); f_006b1791(c); /* call 0x6b1791 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x6cu))); /* mov eax, dword ptr [eax + 0x6c] */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    PUSH32(c, 0x006b136bu); f_006b1791(c); /* call 0x6b1791 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0x70u))); /* mov eax, dword ptr [eax + 0x70] */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    PUSH32(c, 0x006b1376u); f_006b1791(c); /* call 0x6b1791 */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->edi)); /* mov dword ptr [eax + 0x6c], edi */
    PUSH32(c, 0x006b1381u); f_006b1791(c); /* call 0x6b1791 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x20u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x20] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x1c] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b13a2u); f_006aef7a(c); /* call 0x6aef7a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x2c], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b13b5u); f_006b13ef(c); /* call 0x6b13ef */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd4u))); /* mov eax, dword ptr [ebp - 0x2c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b13b8(CPU *c) { /* PTR_006b13b8 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b13c7(CPU *c) { /* PTR_006b13c7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffecu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x14] */
    PUSH32(c, 0x006b13cfu); f_006b143d(c); /* call 0x6b143d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b13d1(CPU *c) { /* PTR_006b13d1 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffd4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x2c], 0 */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b13e3u); f_006af1de(c); /* call 0x6af1de */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { f_006b13b8(c); return; } /* jmp 0x6b13b8 */
}

void f_006b13e9(CPU *c) { /* PTR_006b13e9 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov edi, dword ptr [ebp + 8] */
    { f_006b13ef(c); return; }
}

void f_006b13ef(CPU *c) { /* FUN_100213ef */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd8u))); /* mov eax, dword ptr [ebp - 0x28] */
    W32((uint32_t)(c->esi + 0xfffffffcu), (uint32_t)(c->eax)); /* mov dword ptr [esi - 4], eax */
    PUSH32(c, 0x006b13fau); f_006b1791(c); /* call 0x6b1791 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe4u))); /* mov ecx, dword ptr [ebp - 0x1c] */
    W32((uint32_t)(c->eax + 0x6cu), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x6c], ecx */
    PUSH32(c, 0x006b1405u); f_006b1791(c); /* call 0x6b1791 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov ecx, dword ptr [ebp - 0x20] */
    W32((uint32_t)(c->eax + 0x70u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x70], ecx */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xe06d7363u); /* cmp dword ptr [edi], 0xe06d7363 */
    if (!c->zf) goto L_006b143c; /* jne 0x6b143c */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [edi + 0x10], 3 */
    if (!c->zf) goto L_006b143c; /* jne 0x6b143c */
    (void)sub32(c, R32((uint32_t)(c->edi + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [edi + 0x14], 0x19930520 */
    if (!c->zf) goto L_006b143c; /* jne 0x6b143c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b143c; /* jne 0x6b143c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x2c], 0 */
    if (c->zf) goto L_006b143c; /* je 0x6b143c */
    PUSH32(c, 0x006b1433u); f_006af246(c); /* call 0x6af246 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b143au); f_006b162b(c); /* call 0x6b162b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b143c:;
    c->esp += 4; return; /* ret  */
}

void f_006b143d(CPU *c) { /* PTR_006b143d */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_006b1464; /* jne 0x6b1464 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_006b1464; /* jne 0x6b1464 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_006b1464; /* jne 0x6b1464 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x1cu)), (uint32_t)0x0u); /* cmp dword ptr [eax + 0x1c], 0 */
    if (!c->zf) goto L_006b1464; /* jne 0x6b1464 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_006b1464:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006b1467(CPU *c) { /* FUN_10021467 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c14f8u; PUSH32(c, v_); } /* push 0x100314f8 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
    if (c->zf) goto L_006b1610; /* je 0x6b1610 */
    (void)sub8(c, R8((uint32_t)(c->eax + 0x8u)), (uint8_t)0x0u); /* cmp byte ptr [eax + 8], 0 */
    if (c->zf) goto L_006b1610; /* je 0x6b1610 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov eax, dword ptr [ecx + 8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1610; /* je 0x6b1610 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edx, dword ptr [ebp + 0xc] */
    c->edi = (uint32_t)((uint32_t)(c->eax + c->edx + 0xcu)); /* lea edi, [eax + edx + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx)) & (uint8_t)0x8u)); /* test byte ptr [ecx], 8 */
    if (c->zf) goto L_006b1504; /* je 0x6b1504 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x006b14cdu); f_006b8563(c); /* call 0x6b8563 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b14dfu); f_006b857f(c); /* call 0x6b857f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov eax, dword ptr [esi + 0x18] */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov ecx, dword ptr [ebp + 0x14] */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x8u)); /* add ecx, 8 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
L_006b14f5:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b14fbu); f_006b1692(c); /* call 0x6b1692 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->edi), (uint32_t)(c->eax)); /* mov dword ptr [edi], eax */
    goto L_006b160c; /* jmp 0x6b160c */
L_006b1504:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov esi, dword ptr [ebp + 0x14] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x1u)); /* test byte ptr [esi], 1 */
    if (c->zf) goto L_006b155e; /* je 0x6b155e */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006b1519u); f_006b8563(c); /* call 0x6b8563 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b152bu); f_006b857f(c); /* call 0x6b857f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1541u); f_006b85c0(c); /* call 0x6b85c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi + 0x14u)), (uint32_t)0x4u); /* cmp dword ptr [esi + 0x14], 4 */
    if (!c->zf) goto L_006b160c; /* jne 0x6b160c */
    c->eax = (uint32_t)(R32((uint32_t)(c->edi))); /* mov eax, dword ptr [edi] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b160c; /* je 0x6b160c */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    goto L_006b14f5; /* jmp 0x6b14f5 */
L_006b155e:;
    (void)sub32(c, R32((uint32_t)(c->esi + 0x18u)), (uint32_t)0x0u); /* cmp dword ptr [esi + 0x18], 0 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    if (!c->zf) goto L_006b15a6; /* jne 0x6b15a6 */
    PUSH32(c, 0x006b1571u); f_006b8563(c); /* call 0x6b8563 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1583u); f_006b857f(c); /* call 0x6b857f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x14] */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0x8u)); /* add esi, 8 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006b1598u); f_006b1692(c); /* call 0x6b1692 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b15a1u); f_006b85c0(c); /* call 0x6b85c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_006b160c; /* jmp 0x6b160c */
L_006b15a6:;
    PUSH32(c, 0x006b15abu); f_006b8563(c); /* call 0x6b8563 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b15b9u); f_006b857f(c); /* call 0x6b857f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    PUSH32(c, 0x006b15c7u); f_006b859b(c); /* call 0x6b859b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1607; /* je 0x6b1607 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->esi)) & (uint8_t)0x4u)); /* test byte ptr [esi], 4 */
    if (c->zf) goto L_006b15ed; /* je 0x6b15ed */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006b15dfu); f_006b1692(c); /* call 0x6b1692 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b15ebu); f_006aeeee(c); /* call 0x6aeeee */
    goto L_006b160c; /* jmp 0x6b160c */
L_006b15ed:;
    c->eax = (uint32_t)((uint32_t)(c->esi + 0x8u)); /* lea eax, [esi + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebx + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebx + 0x18] */
    PUSH32(c, 0x006b15f9u); f_006b1692(c); /* call 0x6b1692 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->esi + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esi + 0x18] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1605u); f_006aeee7(c); /* call 0x6aeee7 */
    goto L_006b160c; /* jmp 0x6b160c */
L_006b1607:;
    PUSH32(c, 0x006b160cu); f_006b18f9(c); /* call 0x6b18f9 */
L_006b160c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_006b1610:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b161f(CPU *c) { /* PTR_006b161f */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006b1623(CPU *c) { /* PTR_006b1623 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006b162b(CPU *c) { /* FUN_1002162b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1508u; PUSH32(c, v_); } /* push 0x10031508 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
    if (c->zf) goto L_006b1672; /* je 0x6b1672 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x1cu))); /* mov ecx, dword ptr [eax + 0x1c] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov ecx, dword ptr [ecx + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006b1672; /* je 0x6b1672 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->eax + 0x18u)); PUSH32(c, v_); } /* push dword ptr [eax + 0x18] */
    PUSH32(c, 0x006b166eu); f_006aeee7(c); /* call 0x6aeee7 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
L_006b1672:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1681(CPU *c) { /* PTR_006b1681 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xcu)), ((uint8_t)c->eax)); /* cmp byte ptr [ebp + 0xc], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(!c->zf ? 1 : 0); /* setne al */
    c->esp += 4; return; /* ret  */
}

void f_006b168a(CPU *c) { /* PTR_006b168a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006b1692(CPU *c) { /* FUN_10021692 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov eax, dword ptr [ecx] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0x4u))); /* mov edx, dword ptr [ecx + 4] */
    c->eax = (uint32_t)(add32(c, c->eax, c->esi)); /* add eax, esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((c->sf != c->of)) goto L_006b16b3; /* jl 0x6b16b3 */
    c->esi = (uint32_t)(R32((uint32_t)(c->edx + c->esi))); /* mov esi, dword ptr [edx + esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx + 0x8u))); /* mov ecx, dword ptr [ecx + 8] */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + c->ecx))); /* mov ecx, dword ptr [esi + ecx] */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->edx)); /* add ecx, edx */
    c->eax = (uint32_t)(add32(c, c->eax, c->ecx)); /* add eax, ecx */
L_006b16b3:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b16c0(CPU *c) { /* __CallSettingFrame@12 */
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
    PUSH32(c, 0x006b16e3u); f_006af269(c); /* call 0x6af269 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b16e7u); call_indirect(c, t_); } /* call eax */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->ebx = (uint32_t)(c->ebp); /* mov ebx, ebp */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->ebx); /* mov ebp, ebx */
    (void)sub32(c, c->ecx, (uint32_t)0x100u); /* cmp ecx, 0x100 */
    if (!c->zf) goto L_006b16ff; /* jne 0x6b16ff */
    c->ecx = (uint32_t)((uint32_t)0x2u); /* mov ecx, 2 */
L_006b16ff:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006b1705u); f_006af269(c); /* call 0x6af269 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 16; return; /* ret 0xc */
}

void f_006b170c(CPU *c) { /* FUN_1002170c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b1712u); f_006b0c74(c); /* call 0x6b0c74 */
    { uint32_t t_ = R32((uint32_t)(0x6be08cu)); PUSH32(c, 0x006b1718u); call_indirect(c, t_); } /* call dword ptr [0x1002e08c] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    W32((uint32_t)(0x6ca900u), (uint32_t)(c->eax)); /* mov dword ptr [0x1003a900], eax */
    if (c->zf) goto L_006b175c; /* je 0x6b175c */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x006b172bu); f_006b0b37(c); /* call 0x6b0b37 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b175c; /* je 0x6b175c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x6ca900u)); PUSH32(c, v_); } /* push dword ptr [0x1003a900] */
    { uint32_t t_ = R32((uint32_t)(0x6be088u)); PUSH32(c, 0x006b1740u); call_indirect(c, t_); } /* call dword ptr [0x1002e088] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b175c; /* je 0x6b175c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b174au); f_006b177e(c); /* call 0x6b177e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x6be13cu)); PUSH32(c, 0x006b1751u); call_indirect(c, t_); } /* call dword ptr [0x1002e13c] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006b175c:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b1760(CPU *c) { /* FUN_10021760 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006b1765u); f_006b0c9d(c); /* call 0x6b0c9d */
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca900u))); /* mov eax, dword ptr [0x1003a900] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006b177d; /* je 0x6b177d */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be090u)); PUSH32(c, 0x006b1776u); call_indirect(c, t_); } /* call dword ptr [0x1002e090] */
    { uint32_t a_ = (uint32_t)(0x6ca900u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [0x1003a900], 0xffffffff */
L_006b177d:;
    c->esp += 4; return; /* ret  */
}

void f_006b177e(CPU *c) { /* FUN_1002177e */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    W32((uint32_t)(c->eax + 0x50u), (uint32_t)((uint32_t)0x6cd740u)); /* mov dword ptr [eax + 0x50], 0x1003d740 */
    W32((uint32_t)(c->eax + 0x14u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [eax + 0x14], 1 */
    c->esp += 4; return; /* ret  */
}

void f_006b1791(CPU *c) { /* FUN_10021791 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6be018u)); PUSH32(c, 0x006b1799u); call_indirect(c, t_); } /* call dword ptr [0x1002e018] */
    { uint32_t v_ = R32((uint32_t)(0x6ca900u)); PUSH32(c, v_); } /* push dword ptr [0x1003a900] */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    { uint32_t t_ = R32((uint32_t)(0x6be098u)); PUSH32(c, 0x006b17a7u); call_indirect(c, t_); } /* call dword ptr [0x1002e098] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006b17ec; /* jne 0x6b17ec */
    { uint32_t v_ = 0x74u; PUSH32(c, v_); } /* push 0x74 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    PUSH32(c, 0x006b17b6u); f_006b0b37(c); /* call 0x6b0b37 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b17e4; /* je 0x6b17e4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(0x6ca900u)); PUSH32(c, v_); } /* push dword ptr [0x1003a900] */
    { uint32_t t_ = R32((uint32_t)(0x6be088u)); PUSH32(c, 0x006b17cbu); call_indirect(c, t_); } /* call dword ptr [0x1002e088] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b17e4; /* je 0x6b17e4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b17d5u); f_006b177e(c); /* call 0x6b177e */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t t_ = R32((uint32_t)(0x6be13cu)); PUSH32(c, 0x006b17dcu); call_indirect(c, t_); } /* call dword ptr [0x1002e13c] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [esi + 4], 0xffffffff */
    W32((uint32_t)(c->esi), (uint32_t)(c->eax)); /* mov dword ptr [esi], eax */
    goto L_006b17ec; /* jmp 0x6b17ec */
L_006b17e4:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    PUSH32(c, 0x006b17ebu); f_006afd31(c); /* call 0x6afd31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b17ec:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t t_ = R32((uint32_t)(0x6be094u)); PUSH32(c, 0x006b17f3u); call_indirect(c, t_); } /* call dword ptr [0x1002e094] */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b17f8(CPU *c) { /* FUN_100217f8 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca900u))); /* mov eax, dword ptr [0x1003a900] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006b1897; /* je 0x6b1897 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006b181c; /* jne 0x6b181c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be098u)); PUSH32(c, 0x006b1816u); call_indirect(c, t_); } /* call dword ptr [0x1002e098] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (c->zf) goto L_006b1888; /* je 0x6b1888 */
L_006b181c:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x24u))); /* mov eax, dword ptr [esi + 0x24] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b182a; /* je 0x6b182a */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1829u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b182a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x28u))); /* mov eax, dword ptr [esi + 0x28] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1838; /* je 0x6b1838 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1837u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1838:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x30u))); /* mov eax, dword ptr [esi + 0x30] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1846; /* je 0x6b1846 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1845u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1846:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x38u))); /* mov eax, dword ptr [esi + 0x38] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1854; /* je 0x6b1854 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1853u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1854:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x40u))); /* mov eax, dword ptr [esi + 0x40] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1862; /* je 0x6b1862 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1861u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1862:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x44u))); /* mov eax, dword ptr [esi + 0x44] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1870; /* je 0x6b1870 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b186fu); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1870:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x50u))); /* mov eax, dword ptr [esi + 0x50] */
    (void)sub32(c, c->eax, (uint32_t)0x6cd740u); /* cmp eax, 0x1003d740 */
    if (c->zf) goto L_006b1881; /* je 0x6b1881 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1880u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1881:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b1887u); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1888:;
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6ca900u)); PUSH32(c, v_); } /* push dword ptr [0x1003a900] */
    { uint32_t t_ = R32((uint32_t)(0x6be088u)); PUSH32(c, 0x006b1896u); call_indirect(c, t_); } /* call dword ptr [0x1002e088] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b1897:;
    c->esp += 4; return; /* ret  */
}

void f_006b1898(CPU *c) { /* FUN_10021898 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1518u; PUSH32(c, v_); } /* push 0x10031518 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
    PUSH32(c, 0x006b18c7u); f_006b1791(c); /* call 0x6b1791 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x60u)), c->esi); /* cmp dword ptr [eax + 0x60], esi */
    if (c->zf) goto L_006b18eb; /* je 0x6b18eb */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    PUSH32(c, 0x006b18d8u); f_006b1791(c); /* call 0x6b1791 */
    { uint32_t t_ = R32((uint32_t)(c->eax + 0x60u)); PUSH32(c, 0x006b18dbu); call_indirect(c, t_); } /* call dword ptr [eax + 0x60] */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 4], esi */
    goto L_006b18eb; /* jmp 0x6b18eb */
L_006b18eb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b18f4u); f_006b18f4(c); /* call 0x6b18f4 */
    { f_006b88f5(c); return; } /* jmp 0x6b88f5 */
}

void f_006b18e0(CPU *c) { /* PTR_006b18e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006b18e4(CPU *c) { /* PTR_006b18e4 */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b18f4u); f_006b18f4(c); /* call 0x6b18f4 */
    { f_006b88f5(c); return; } /* jmp 0x6b88f5 */
}

void f_006b18f4(CPU *c) { /* PTR_006b18f4 */
    PREEMPT_POLL(c);
    { f_006b88f5(c); return; } /* jmp 0x6b88f5 */
}

void f_006b18f9(CPU *c) { /* FUN_100218f9 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1530u; PUSH32(c, v_); } /* push 0x10031530 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca904u))); /* mov eax, dword ptr [0x1003a904] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1941; /* je 0x6b1941 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b1934u); call_indirect(c, t_); } /* call eax */
    goto L_006b193d; /* jmp 0x6b193d */
L_006b193d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
L_006b1941:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b194au); f_006b194a(c); /* call 0x6b194a */
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006b1936(CPU *c) { /* PTR_006b1936 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
}

void f_006b193a(CPU *c) { /* PTR_006b193a */
    PREEMPT_POLL(c);
    c->esp = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe8u))); /* mov esp, dword ptr [ebp - 0x18] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b194au); f_006b194a(c); /* call 0x6b194a */
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006b194a(CPU *c) { /* PTR_006b194a */
    PREEMPT_POLL(c);
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
}

void f_006b194f(CPU *c) { /* FUN_1002194f */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi))); /* mov eax, dword ptr [esi] */
    (void)sub32(c, R32((uint32_t)(c->eax)), (uint32_t)0xe06d7363u); /* cmp dword ptr [eax], 0xe06d7363 */
    if (!c->zf) goto L_006b1972; /* jne 0x6b1972 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x10u)), (uint32_t)0x3u); /* cmp dword ptr [eax + 0x10], 3 */
    if (!c->zf) goto L_006b1972; /* jne 0x6b1972 */
    (void)sub32(c, R32((uint32_t)(c->eax + 0x14u)), (uint32_t)0x19930520u); /* cmp dword ptr [eax + 0x14], 0x19930520 */
    if (!c->zf) goto L_006b1972; /* jne 0x6b1972 */
    { f_006b1898(c); return; } /* jmp 0x6b1898 */
L_006b1972:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6d01b8u))); /* mov eax, dword ptr [0x100401b8] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b198f; /* je 0x6b198f */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1981u); f_006b859b(c); /* call 0x6b859b */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b198f; /* je 0x6b198f */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t t_ = R32((uint32_t)(0x6d01b8u)); PUSH32(c, 0x006b198du); call_indirect(c, t_); } /* call dword ptr [0x100401b8] */
    goto L_006b1991; /* jmp 0x6b1991 */
L_006b198f:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b1991:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 8; return; /* ret 4 */
}

void f_006b1995(CPU *c) { /* PTR_006b1995 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6b194fu; PUSH32(c, v_); } /* push 0x1002194f */
    { uint32_t t_ = R32((uint32_t)(0x6be09cu)); PUSH32(c, 0x006b19a0u); call_indirect(c, t_); } /* call dword ptr [0x1002e09c] */
    W32((uint32_t)(0x6d01b8u), (uint32_t)(c->eax)); /* mov dword ptr [0x100401b8], eax */
    c->esp += 4; return; /* ret  */
}

void f_006b19a6(CPU *c) { /* PTR_006b19a6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(0x6d01b8u)); PUSH32(c, v_); } /* push dword ptr [0x100401b8] */
    { uint32_t t_ = R32((uint32_t)(0x6be09cu)); PUSH32(c, 0x006b19b2u); call_indirect(c, t_); } /* call dword ptr [0x1002e09c] */
    c->esp += 4; return; /* ret  */
}

void f_006b19b3(CPU *c) { /* FUN_100219b3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x30000u; PUSH32(c, v_); } /* push 0x30000 */
    { uint32_t v_ = 0x10000u; PUSH32(c, v_); } /* push 0x10000 */
    PUSH32(c, 0x006b19c2u); f_006b8941(c); /* call 0x6b8941 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b19c5(CPU *c) { /* FUN_100219c5 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x18u)); /* sub esp, 0x18 */
    FPUSH(c, RF64((uint32_t)(0x6c1550u))); /* fld qword ptr [0x10031550] */
    WF64((uint32_t)(c->ebp + 0xfffffff8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 8] */
    FPUSH(c, RF64((uint32_t)(0x6c1548u))); /* fld qword ptr [0x10031548] */
    WF64((uint32_t)(c->ebp + 0xfffffff0u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x10] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff0u))); /* fld qword ptr [ebp - 0x10] */
    ST(0) = FPRES(c, FDIV(c, ST(0), RF64((uint32_t)(c->ebp + 0xfffffff8u)))); /* fdiv qword ptr [ebp - 8] */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fmul qword ptr [ebp - 8] */
    ST(0) = FPRES(c, RF64((uint32_t)(c->ebp + 0xfffffff0u)) - ST(0)); /* fsubr qword ptr [ebp - 0x10] */
    WF64((uint32_t)(c->ebp + 0xffffffe8u), ST(0)); FPOP(c); /* fstp qword ptr [ebp - 0x18] */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xffffffe8u))); /* fld qword ptr [ebp - 0x18] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6c1430u))); FPOP(c); /* fcomp qword ptr [0x10031430] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if ((c->cf || c->zf)) goto L_006b19ff; /* jbe 0x6b19ff */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006b19ff:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1a03(CPU *c) { /* FUN_10021a03 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x6c1574u; PUSH32(c, v_); } /* push 0x10031574 */
    { uint32_t t_ = R32((uint32_t)(0x6be038u)); PUSH32(c, 0x006b1a0eu); call_indirect(c, t_); } /* call dword ptr [0x1002e038] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1a27; /* je 0x6b1a27 */
    { uint32_t v_ = 0x6c1558u; PUSH32(c, v_); } /* push 0x10031558 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be030u)); PUSH32(c, 0x006b1a1eu); call_indirect(c, t_); } /* call dword ptr [0x1002e030] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b1a27; /* je 0x6b1a27 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t t_ = c->eax; PUSH32(c, 0x006b1a26u); call_indirect(c, t_); } /* call eax */
    c->esp += 4; return; /* ret  */
L_006b1a27:;
    { f_006b19c5(c); return; } /* jmp 0x6b19c5 */
}

void f_006b1a2c(CPU *c) { /* FUN_10021a2c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov esi, dword ptr [esp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1a3au); f_006b8a72(c); /* call 0x6b8a72 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b1a6c; /* je 0x6b1a6c */
L_006b1a40:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, R32((uint32_t)(0x6ca8dcu)), (uint32_t)0x1u); /* cmp dword ptr [0x1003a8dc], 1 */
    if ((c->zf || c->sf != c->of)) goto L_006b1a59; /* jle 0x6b1a59 */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1a55u); f_006b0e04(c); /* call 0x6b0e04 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b1a68; /* jmp 0x6b1a68 */
L_006b1a59:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2))); /* mov al, byte ptr [ecx + eax*2] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x4u))); /* and eax, 4 */
L_006b1a68:;
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b1a40; /* jne 0x6b1a40 */
L_006b1a6c:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ca8e0u))); /* mov cl, byte ptr [0x1003a8e0] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov al, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [esi], cl */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
L_006b1a77:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    W8((uint32_t)(c->esi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [esi], al */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(((uint8_t)c->ecx)); /* mov al, cl */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esi))); /* mov cl, byte ptr [esi] */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006b1a77; /* jne 0x6b1a77 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b1a86(CPU *c) { /* PTR_006b1a86 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ca8e0u))); /* mov dl, byte ptr [0x1003a8e0] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006b1aa2; /* je 0x6b1aa2 */
L_006b1a96:;
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->edx)); /* cmp cl, dl */
    if (c->zf) goto L_006b1aa2; /* je 0x6b1aa2 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov cl, byte ptr [eax + 1] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (!c->zf) goto L_006b1a96; /* jne 0x6b1a96 */
L_006b1aa2:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006b1ad3; /* je 0x6b1ad3 */
L_006b1aa9:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax))); /* mov cl, byte ptr [eax] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006b1abc; /* je 0x6b1abc */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x65u); /* cmp cl, 0x65 */
    if (c->zf) goto L_006b1abc; /* je 0x6b1abc */
    (void)sub8(c, ((uint8_t)c->ecx), (uint8_t)0x45u); /* cmp cl, 0x45 */
    if (c->zf) goto L_006b1abc; /* je 0x6b1abc */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006b1aa9; /* jmp 0x6b1aa9 */
L_006b1abc:;
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
L_006b1abe:;
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_006b1abe; /* je 0x6b1abe */
    (void)sub8(c, R8((uint32_t)(c->eax)), ((uint8_t)c->edx)); /* cmp byte ptr [eax], dl */
    if (!c->zf) goto L_006b1ac9; /* jne 0x6b1ac9 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
L_006b1ac9:;
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ecx))); /* mov dl, byte ptr [ecx] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & ((uint8_t)c->edx))); /* test dl, dl */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    if (!c->zf) goto L_006b1ac9; /* jne 0x6b1ac9 */
L_006b1ad3:;
    c->esp += 4; return; /* ret  */
}

void f_006b1ad4(CPU *c) { /* PTR_006b1ad4 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    FPUSH(c, RF64((uint32_t)(c->eax))); /* fld qword ptr [eax] */
    FCOM(c, ST(0), RF64((uint32_t)(0x6c1428u))); FPOP(c); /* fcomp qword ptr [0x10031428] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->cf) goto L_006b1ae9; /* jb 0x6b1ae9 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    c->esp += 4; return; /* ret  */
L_006b1ae9:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
}

void f_006b1aec(CPU *c) { /* __fassign */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 8], 0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    if (c->zf) goto L_006b1b15; /* je 0x6b1b15 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff8u)); /* lea eax, [ebp - 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1b03u); f_006b8f3e(c); /* call 0x6b8f3e */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ecx, dword ptr [ebp - 4] */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 4], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
L_006b1b15:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1b1eu); f_006b8f6b(c); /* call 0x6b8f6b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov ecx, dword ptr [ebp + 0x10] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1b2a(CPU *c) { /* FUN_10021b2a */
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
    PUSH32(c, 0x006b1b48u); f_006b900f(c); /* call 0x6b900f */
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
    PUSH32(c, 0x006b1b70u); f_006b8f98(c); /* call 0x6b8f98 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b1b82u); f_006b1b8b(c); /* call 0x6b1b8b */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x30u)); /* add esp, 0x30 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1b8b(CPU *c) { /* FUN_10021b8b */
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
    if (c->zf) goto L_006b1bb9; /* je 0x6b1bb9 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)((!c->zf && c->sf == c->of) ? 1 : 0); /* setg al */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete al */
    c->eax = (uint32_t)(add32(c, c->eax, c->edi)); /* add eax, edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b1bb7u); f_006b1e2d(c); /* call 0x6b1e2d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1bb9:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    if (!c->zf) goto L_006b1bc6; /* jne 0x6b1bc6 */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [edi], 0x2d */
    c->eax = (uint32_t)((uint32_t)(c->edi + 0x1u)); /* lea eax, [edi + 1] */
L_006b1bc6:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->ebx); /* cmp dword ptr [ebp + 0xc], ebx */
    if ((c->zf || c->sf != c->of)) goto L_006b1bdd; /* jle 0x6b1bdd */
    c->edx = (c->edx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x1u))); /* mov dl, byte ptr [eax + 1] */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->edx))); /* mov byte ptr [eax], dl */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ca8e0u))); /* mov cl, byte ptr [0x1003a8e0] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
L_006b1bdd:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x18u)), ((uint8_t)c->ebx)); /* cmp byte ptr [ebp + 0x18], bl */
    { uint32_t v_ = 0x6c1580u; PUSH32(c, v_); } /* push 0x10031580 */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, R32((uint32_t)(c->ebp + 0xcu)))); /* add ecx, dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    PUSH32(c, 0x006b1bf5u); f_006b4410(c); /* call 0x6b4410 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), c->ebx); /* cmp dword ptr [ebp + 0x10], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    if (c->zf) goto L_006b1c01; /* je 0x6b1c01 */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x45u)); /* mov byte ptr [ecx], 0x45 */
L_006b1c01:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x30u); /* cmp byte ptr [eax], 0x30 */
    if (c->zf) goto L_006b1c46; /* je 0x6b1c46 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov ebx, dword ptr [esi + 4] */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    if (!c->sf) goto L_006b1c15; /* jns 0x6b1c15 */
    c->ebx = (uint32_t)(neg32(c, c->ebx)); /* neg ebx */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ecx], 0x2d */
L_006b1c15:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0x64u); /* cmp ebx, 0x64 */
    if ((c->sf != c->of)) goto L_006b1c2c; /* jl 0x6b1c2c */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0x64u; PUSH32(c, v_); } /* push 0x64 */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006b1c21u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006b1c28u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_006b1c2c:;
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->ebx, (uint32_t)0xau); /* cmp ebx, 0xa */
    if ((c->sf != c->of)) goto L_006b1c43; /* jl 0x6b1c43 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = 0xau; PUSH32(c, v_); } /* push 0xa */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006b1c38u, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    { uint32_t a_ = (uint32_t)(c->ecx); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->eax)))); } /* add byte ptr [ecx], al */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { int32_t d_ = (int32_t)c->esi; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); if (!d_) guest_trap(c, 0x006b1c3fu, "divide by zero"); c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); } /* idiv esi */
    c->ebx = (uint32_t)(c->edx); /* mov ebx, edx */
L_006b1c43:;
    { uint32_t a_ = (uint32_t)(c->ecx + 0x1u); W8(a_, (uint8_t)(add8(c, R8(a_), ((uint8_t)c->ebx)))); } /* add byte ptr [ecx + 1], bl */
L_006b1c46:;
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b1c4d(CPU *c) { /* FUN_10021c4d */
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
    PUSH32(c, 0x006b1c6bu); f_006b900f(c); /* call 0x6b900f */
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
    PUSH32(c, 0x006b1c8au); f_006b8f98(c); /* call 0x6b8f98 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b1c99u); f_006b1ca2(c); /* call 0x6b1ca2 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov eax, dword ptr [ebp + 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x2cu)); /* add esp, 0x2c */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1ca2(CPU *c) { /* FUN_10021ca2 */
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
    if (c->zf) goto L_006b1cd2; /* je 0x6b1cd2 */
    (void)sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xcu))); /* cmp eax, dword ptr [ebp + 0xc] */
    if (!c->zf) goto L_006b1cd2; /* jne 0x6b1cd2 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(c->zf ? 1 : 0); /* sete cl */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->eax)); /* add ecx, eax */
    c->ecx = (uint32_t)(add32(c, c->ecx, c->ebx)); /* add ecx, ebx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    W8((uint32_t)(c->eax), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [eax], 0x30 */
    { uint32_t a_ = (uint32_t)(c->eax + 0x1u); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & (uint8_t)0x0u)))); } /* and byte ptr [eax + 1], 0 */
L_006b1cd2:;
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0x2du); /* cmp dword ptr [esi], 0x2d */
    c->edi = (uint32_t)(c->ebx); /* mov edi, ebx */
    if (!c->zf) goto L_006b1cdf; /* jne 0x6b1cdf */
    W8((uint32_t)(c->ebx), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebx], 0x2d */
    c->edi = (uint32_t)((uint32_t)(c->ebx + 0x1u)); /* lea edi, [ebx + 1] */
L_006b1cdf:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov eax, dword ptr [esi + 4] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006b1cf6; /* jg 0x6b1cf6 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1ceeu); f_006b1e2d(c); /* call 0x6b1e2d */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [edi], 0x30 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    goto L_006b1cf8; /* jmp 0x6b1cf8 */
L_006b1cf6:;
    c->edi = (uint32_t)(add32(c, c->edi, c->eax)); /* add edi, eax */
L_006b1cf8:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp + 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_006b1d42; /* jle 0x6b1d42 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1d06u); f_006b1e2d(c); /* call 0x6b1e2d */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(0x6ca8e0u))); /* mov al, byte ptr [0x1003a8e0] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->edi), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edi], al */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0x4u))); /* mov esi, dword ptr [esi + 4] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if ((c->sf == c->of)) goto L_006b1d42; /* jge 0x6b1d42 */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0x14u)), (uint8_t)0x0u); /* cmp byte ptr [ebp + 0x14], 0 */
    if (c->zf) goto L_006b1d21; /* je 0x6b1d21 */
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    goto L_006b1d28; /* jmp 0x6b1d28 */
L_006b1d21:;
    c->esi = (uint32_t)(neg32(c, c->esi)); /* neg esi */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->esi); /* cmp dword ptr [ebp + 0xc], esi */
    if ((c->sf != c->of)) goto L_006b1d2b; /* jl 0x6b1d2b */
L_006b1d28:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_006b1d2b:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1d34u); f_006b1e2d(c); /* call 0x6b1e2d */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b1d3fu); f_006b8330(c); /* call 0x6b8330 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006b1d42:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b1d49(CPU *c) { /* FUN_10021d49 */
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
    PUSH32(c, 0x006b1d69u); f_006b900f(c); /* call 0x6b900f */
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
    PUSH32(c, 0x006b1d8bu); f_006b8f98(c); /* call 0x6b8f98 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x1cu)); /* add esp, 0x1c */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    (void)sub32(c, c->esi, c->eax); /* cmp esi, eax */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)((c->sf != c->of) ? 1 : 0); /* setl cl */
    (void)sub32(c, c->eax, (uint32_t)0xfffffffcu); /* cmp eax, -4 */
    if ((c->sf != c->of)) goto L_006b1dc2; /* jl 0x6b1dc2 */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if ((c->sf == c->of)) goto L_006b1dc2; /* jge 0x6b1dc2 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006b1dae; /* je 0x6b1dae */
L_006b1da4:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (!c->zf) goto L_006b1da4; /* jne 0x6b1da4 */
    { uint32_t a_ = (uint32_t)(c->edi + 0xfffffffeu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) & ((uint8_t)c->eax))))); } /* and byte ptr [edi - 2], al */
L_006b1dae:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b1dbdu); f_006b1ca2(c); /* call 0x6b1ca2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    goto L_006b1dd7; /* jmp 0x6b1dd7 */
L_006b1dc2:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffff0u)); /* lea eax, [ebp - 0x10] */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b1dd4u); f_006b1b8b(c); /* call 0x6b1b8b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006b1dd7:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1ddc(CPU *c) { /* __cfltcvt */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x65u); /* cmp dword ptr [ebp + 0x10], 0x65 */
    if (c->zf) goto L_006b1e17; /* je 0x6b1e17 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x45u); /* cmp dword ptr [ebp + 0x10], 0x45 */
    if (c->zf) goto L_006b1e17; /* je 0x6b1e17 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0x10u)), (uint32_t)0x66u); /* cmp dword ptr [ebp + 0x10], 0x66 */
    if (!c->zf) goto L_006b1e04; /* jne 0x6b1e04 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b1dffu); f_006b1c4d(c); /* call 0x6b1c4d */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006b1e04:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b1e15u); f_006b1d49(c); /* call 0x6b1d49 */
    goto L_006b1e28; /* jmp 0x6b1e28 */
L_006b1e17:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x14] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b1e28u); f_006b1b2a(c); /* call 0x6b1b2a */
L_006b1e28:;
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b1e2d(CPU *c) { /* FUN_10021e2d */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov edi, dword ptr [esp + 0xc] */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006b1e50; /* je 0x6b1e50 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov esi, dword ptr [esp + 0xc] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b1e41u); f_006b4390(c); /* call 0x6b4390 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(add32(c, c->esi, c->edi)); /* add esi, edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b1e4cu); f_006b85c0(c); /* call 0x6b85c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b1e50:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->esp += 4; return; /* ret  */
}

void f_006b1e52(CPU *c) { /* FUN_10021e52 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esi + 0x10u))); /* mov ebx, dword ptr [esi + 0x10] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x82u)); /* test al, 0x82 */
    if (c->zf) goto L_006b1f5e; /* je 0x6b1f5e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x40u)); /* test al, 0x40 */
    if (!c->zf) goto L_006b1f5e; /* jne 0x6b1f5e */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x1u)); /* test al, 1 */
    if (c->zf) goto L_006b1e8a; /* je 0x6b1e8a */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0x10u)); /* test al, 0x10 */
    if (c->zf) goto L_006b1f5e; /* je 0x6b1f5e */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov ecx, dword ptr [esi + 8] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xfeu))); /* and al, 0xfe */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_006b1e8a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0xcu))); /* mov eax, dword ptr [esi + 0xc] */
    { uint32_t a_ = (uint32_t)(c->esi + 0x4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [esi + 4], 0 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp + 0xc], 0 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) & (uint8_t)0xefu))); /* and al, 0xef */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x2u))); /* or al, 2 */
    (void)logic16(c, (uint16_t)(((uint16_t)c->eax) & (uint16_t)0x10cu)); /* test ax, 0x10c */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
    if (!c->zf) goto L_006b1ec4; /* jne 0x6b1ec4 */
    (void)sub32(c, c->esi, (uint32_t)0x6ca950u); /* cmp esi, 0x1003a950 */
    if (c->zf) goto L_006b1eb2; /* je 0x6b1eb2 */
    (void)sub32(c, c->esi, (uint32_t)0x6ca970u); /* cmp esi, 0x1003a970 */
    if (!c->zf) goto L_006b1ebd; /* jne 0x6b1ebd */
L_006b1eb2:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b1eb8u); f_006b9436(c); /* call 0x6b9436 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b1ec4; /* jne 0x6b1ec4 */
L_006b1ebd:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b1ec3u); f_006b93f2(c); /* call 0x6b93f2 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b1ec4:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->esi + 0xcu)) & (uint16_t)0x108u)); /* test word ptr [esi + 0xc], 0x108 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    if (c->zf) goto L_006b1f34; /* je 0x6b1f34 */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi))); /* mov edi, dword ptr [esi] */
    c->edi = (uint32_t)(sub32(c, c->edi, c->eax)); /* sub edi, eax */
    c->ecx = (uint32_t)((uint32_t)(c->eax + 0x1u)); /* lea ecx, [eax + 1] */
    W32((uint32_t)(c->esi), (uint32_t)(c->ecx)); /* mov dword ptr [esi], ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi + 0x18u))); /* mov ecx, dword ptr [esi + 0x18] */
    c->ecx = (uint32_t)(dec32(c, c->ecx)); /* dec ecx */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    W32((uint32_t)(c->esi + 0x4u), (uint32_t)(c->ecx)); /* mov dword ptr [esi + 4], ecx */
    if ((c->zf || c->sf != c->of)) goto L_006b1ef4; /* jle 0x6b1ef4 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b1eecu); f_006b9202(c); /* call 0x6b9202 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
    goto L_006b1f2a; /* jmp 0x6b1f2a */
L_006b1ef4:;
    (void)sub32(c, c->ebx, (uint32_t)0xffffffffu); /* cmp ebx, -1 */
    if (c->zf) goto L_006b1f12; /* je 0x6b1f12 */
    c->ecx = (uint32_t)(c->ebx); /* mov ecx, ebx */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ecx = (uint32_t)(sar32(c, c->ecx, 5)); /* sar ecx, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ecx * 4 + 0x6d0700u))); /* mov ecx, dword ptr [ecx*4 + 0x10040700] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 4)); /* lea eax, [ecx + eax*4] */
    goto L_006b1f17; /* jmp 0x6b1f17 */
L_006b1f12:;
    c->eax = (uint32_t)((uint32_t)0x6cadc0u); /* mov eax, 0x1003adc0 */
L_006b1f17:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0x4u)) & (uint8_t)0x20u)); /* test byte ptr [eax + 4], 0x20 */
    if (c->zf) goto L_006b1f2a; /* je 0x6b1f2a */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b1f27u); f_006b912a(c); /* call 0x6b912a */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
L_006b1f2a:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + 0x8u))); /* mov eax, dword ptr [esi + 8] */
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov cl, byte ptr [ebp + 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ecx))); /* mov byte ptr [eax], cl */
    goto L_006b1f48; /* jmp 0x6b1f48 */
L_006b1f34:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x8u)); /* lea eax, [ebp + 8] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b1f42u); f_006b9202(c); /* call 0x6b9202 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp + 0xc], eax */
L_006b1f48:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xcu)), c->edi); /* cmp dword ptr [ebp + 0xc], edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    if (c->zf) goto L_006b1f54; /* je 0x6b1f54 */
    { uint32_t a_ = (uint32_t)(c->esi + 0xcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [esi + 0xc], 0x20 */
    goto L_006b1f63; /* jmp 0x6b1f63 */
L_006b1f54:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xffu))); /* and eax, 0xff */
    goto L_006b1f66; /* jmp 0x6b1f66 */
L_006b1f5e:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->eax) | (uint8_t)0x20u))); /* or al, 0x20 */
    W32((uint32_t)(c->esi + 0xcu), (uint32_t)(c->eax)); /* mov dword ptr [esi + 0xc], eax */
L_006b1f63:;
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | (uint32_t)0xffffffffu))); /* or eax, 0xffffffff */
L_006b1f66:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b1f6a(CPU *c) { /* FUN_10021f6a */
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
    if (c->zf) goto L_006b2683; /* je 0x6b2683 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_006b1f9e; /* jmp 0x6b1f9e */
L_006b1f96:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffd0u))); /* mov esi, dword ptr [ebp - 0x30] */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_006b1f9e:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffecu)), c->edx); /* cmp dword ptr [ebp - 0x14], edx */
    if ((c->sf != c->of)) goto L_006b2683; /* jl 0x6b2683 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x20u); /* cmp bl, 0x20 */
    if ((c->sf != c->of)) goto L_006b1fbf; /* jl 0x6b1fbf */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x78u); /* cmp bl, 0x78 */
    if ((!c->zf && c->sf == c->of)) goto L_006b1fbf; /* jg 0x6b1fbf */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->eax + 0x6c1568u))); /* mov al, byte ptr [eax + 0x10031568] */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0xfu))); /* and eax, 0xf */
    goto L_006b1fc1; /* jmp 0x6b1fc1 */
L_006b1fbf:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b1fc1:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi + c->eax * 8 + 0x6c1588u))); /* movsx eax, byte ptr [esi + eax*8 + 0x10031588] */
    c->eax = (uint32_t)(sar32(c, c->eax, 4)); /* sar eax, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x7u); /* cmp eax, 7 */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x30], eax */
    if ((!c->cf && !c->zf)) goto L_006b2672; /* ja 0x6b2672 */
    { uint32_t t_ = R32((uint32_t)(c->eax * 4 + 0x6b268bu)); switch (t_) { case 0x006b1fdfu: goto L_006b1fdf; case 0x006b1ffau: goto L_006b1ffa; case 0x006b2046u: goto L_006b2046; case 0x006b207du: goto L_006b207d; case 0x006b2085u: goto L_006b2085; case 0x006b20bau: goto L_006b20ba; case 0x006b2109u: goto L_006b2109; case 0x006b214du: goto L_006b214d; default: jump_indirect(c, t_, 0x006b1fd8u); return; } } /* jmp dword ptr [eax*4 + 0x1002268b] */
L_006b1fdf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b1ffa:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x20u)); /* sub eax, 0x20 */
    if (c->zf) goto L_006b203d; /* je 0x6b203d */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_006b2034; /* je 0x6b2034 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x8u)); /* sub eax, 8 */
    if (c->zf) goto L_006b202b; /* je 0x6b202b */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b2022; /* je 0x6b2022 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_006b2672; /* jne 0x6b2672 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x8u)))); } /* or dword ptr [ebp - 4], 8 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b2022:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b202b:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x1u)))); } /* or dword ptr [ebp - 4], 1 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b2034:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 4], 0x80 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b203d:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x2u)))); } /* or dword ptr [ebp - 4], 2 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b2046:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_006b206e; /* jne 0x6b206e */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2054u); f_006b2749(c); /* call 0x6b2749 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    if ((c->sf == c->of)) goto L_006b2672; /* jge 0x6b2672 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x4u)))); } /* or dword ptr [ebp - 4], 4 */
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
L_006b2066:;
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b206e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov eax, dword ptr [ebp - 0x20] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 4)); /* lea eax, [eax + eax*4] */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    goto L_006b2066; /* jmp 0x6b2066 */
L_006b207d:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x10], edx */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b2085:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x2au); /* cmp bl, 0x2a */
    if (!c->zf) goto L_006b20a8; /* jne 0x6b20a8 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2093u); f_006b2749(c); /* call 0x6b2749 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    if ((c->sf == c->of)) goto L_006b2672; /* jge 0x6b2672 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b20a8:;
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->ecx * 4)); /* lea eax, [ecx + ecx*4] */
    c->ecx = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx ecx, bl */
    c->eax = (uint32_t)((uint32_t)(c->ecx + c->eax * 2 + 0xffffffd0u)); /* lea eax, [ecx + eax*2 - 0x30] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b20ba:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x49u); /* cmp bl, 0x49 */
    if (c->zf) goto L_006b20ed; /* je 0x6b20ed */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x68u); /* cmp bl, 0x68 */
    if (c->zf) goto L_006b20e4; /* je 0x6b20e4 */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x6cu); /* cmp bl, 0x6c */
    if (c->zf) goto L_006b20db; /* je 0x6b20db */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x77u); /* cmp bl, 0x77 */
    if (!c->zf) goto L_006b2672; /* jne 0x6b2672 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b20db:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x10u)))); } /* or dword ptr [ebp - 4], 0x10 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b20e4:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x20u)))); } /* or dword ptr [ebp - 4], 0x20 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b20ed:;
    (void)sub8(c, R8((uint32_t)(c->edi)), (uint8_t)0x36u); /* cmp byte ptr [edi], 0x36 */
    if (!c->zf) goto L_006b2106; /* jne 0x6b2106 */
    (void)sub8(c, R8((uint32_t)(c->edi + 0x1u)), (uint8_t)0x34u); /* cmp byte ptr [edi + 1], 0x34 */
    if (!c->zf) goto L_006b2106; /* jne 0x6b2106 */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x80u)))); } /* or byte ptr [ebp - 3], 0x80 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b2106:;
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x30], edx */
L_006b2109:;
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca6d0u))); /* mov ecx, dword ptr [0x1003a6d0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->ebx)); /* movzx eax, bl */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ecx + c->eax * 2 + 0x1u)) & (uint8_t)0x80u)); /* test byte ptr [ecx + eax*2 + 1], 0x80 */
    if (c->zf) goto L_006b2135; /* je 0x6b2135 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b212cu); f_006b26ab(c); /* call 0x6b26ab */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
L_006b2135:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2145u); f_006b26ab(c); /* call 0x6b26ab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b214d:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->ebx)); /* movsx eax, bl */
    (void)sub32(c, c->eax, (uint32_t)0x67u); /* cmp eax, 0x67 */
    if ((!c->zf && c->sf == c->of)) goto L_006b2375; /* jg 0x6b2375 */
    (void)sub32(c, c->eax, (uint32_t)0x65u); /* cmp eax, 0x65 */
    if ((c->sf == c->of)) goto L_006b21f8; /* jge 0x6b21f8 */
    (void)sub32(c, c->eax, (uint32_t)0x58u); /* cmp eax, 0x58 */
    if ((!c->zf && c->sf == c->of)) goto L_006b2256; /* jg 0x6b2256 */
    if (c->zf) goto L_006b23e9; /* je 0x6b23e9 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x43u)); /* sub eax, 0x43 */
    if (c->zf) goto L_006b2219; /* je 0x6b2219 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b21ee; /* je 0x6b21ee */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b21ee; /* je 0x6b21ee */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xcu)); /* sub eax, 0xc */
    if (!c->zf) goto L_006b2574; /* jne 0x6b2574 */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_006b2197; /* jne 0x6b2197 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_006b2197:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov esi, dword ptr [ebp - 0x10] */
    (void)sub32(c, c->esi, (uint32_t)0xffffffffu); /* cmp esi, -1 */
    if (!c->zf) goto L_006b21a4; /* jne 0x6b21a4 */
    c->esi = (uint32_t)((uint32_t)0x7fffffffu); /* mov esi, 0x7fffffff */
L_006b21a4:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b21adu); f_006b2749(c); /* call 0x6b2749 */
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    if (c->zf) goto L_006b23bd; /* je 0x6b23bd */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_006b21cc; /* jne 0x6b21cc */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca924u))); /* mov ecx, dword ptr [0x1003a924] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_006b21cc:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_006b21d5:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006b23b4; /* je 0x6b23b4 */
    (void)sub16(c, R16((uint32_t)(c->eax)), (uint16_t)0x0u); /* cmp word ptr [eax], 0 */
    if (c->zf) goto L_006b23b4; /* je 0x6b23b4 */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006b21d5; /* jmp 0x6b21d5 */
L_006b21ee:;
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x34], 1 */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->ebx), (uint8_t)0x20u)); /* add bl, 0x20 */
L_006b21f8:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea edi, [ebp - 0x248] */
    (void)sub32(c, c->ecx, c->edx); /* cmp ecx, edx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
    if ((c->sf == c->of)) goto L_006b22dc; /* jge 0x6b22dc */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x6u)); /* mov dword ptr [ebp - 0x10], 6 */
    goto L_006b22ea; /* jmp 0x6b22ea */
L_006b2219:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x830u)); /* test word ptr [ebp - 4], 0x830 */
    if (!c->zf) goto L_006b2225; /* jne 0x6b2225 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x8u)))); } /* or byte ptr [ebp - 3], 8 */
L_006b2225:;
    (void)logic16(c, (uint16_t)(R16((uint32_t)(c->ebp + 0xfffffffcu)) & (uint16_t)0x810u)); /* test word ptr [ebp - 4], 0x810 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_006b226c; /* je 0x6b226c */
    PUSH32(c, 0x006b2236u); f_006b2766(c); /* call 0x6b2766 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2243u); f_006b945f(c); /* call 0x6b945f */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->sf == c->of)) goto L_006b227f; /* jge 0x6b227f */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_006b227f; /* jmp 0x6b227f */
L_006b2256:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5au)); /* sub eax, 0x5a */
    if (c->zf) goto L_006b228d; /* je 0x6b228d */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x9u)); /* sub eax, 9 */
    if (c->zf) goto L_006b2225; /* je 0x6b2225 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b244f; /* je 0x6b244f */
    goto L_006b2574; /* jmp 0x6b2574 */
L_006b226c:;
    PUSH32(c, 0x006b2271u); f_006b2749(c); /* call 0x6b2749 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W8((uint32_t)(c->ebp + 0xfffffdb8u), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x248], al */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0xc], 1 */
L_006b227f:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    goto L_006b2574; /* jmp 0x6b2574 */
L_006b228d:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2296u); f_006b2749(c); /* call 0x6b2749 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b22ce; /* je 0x6b22ce */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax + 0x4u))); /* mov ecx, dword ptr [eax + 4] */
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (c->zf) goto L_006b22ce; /* je 0x6b22ce */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x8u)); /* test byte ptr [ebp - 3], 8 */
    if (c->zf) goto L_006b22bf; /* je 0x6b22bf */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    c->eax = (uint32_t)(shr32(c, c->eax, 1)); /* shr eax, 1 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x24], 1 */
    goto L_006b2574; /* jmp 0x6b2574 */
L_006b22bf:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffdcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x24], 0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)R16((uint32_t)(c->eax))); /* movsx eax, word ptr [eax] */
    goto L_006b2571; /* jmp 0x6b2571 */
L_006b22ce:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6ca920u))); /* mov eax, dword ptr [0x1003a920] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    goto L_006b236a; /* jmp 0x6b236a */
L_006b22dc:;
    if (!c->zf) goto L_006b22ea; /* jne 0x6b22ea */
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_006b22ea; /* jne 0x6b22ea */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
L_006b22ea:;
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
    { uint32_t t_ = R32((uint32_t)(0x6ca908u)); PUSH32(c, 0x006b231au); call_indirect(c, t_); } /* call dword ptr [0x1003a908] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80u))); /* and esi, 0x80 */
    if (c->zf) goto L_006b233c; /* je 0x6b233c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (!c->zf) goto L_006b233c; /* jne 0x6b233c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ca914u)); PUSH32(c, 0x006b233bu); call_indirect(c, t_); } /* call dword ptr [0x1003a914] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b233c:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_006b2353; /* jne 0x6b2353 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006b2353; /* jne 0x6b2353 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ca90cu)); PUSH32(c, 0x006b2352u); call_indirect(c, t_); } /* call dword ptr [0x1003a90c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b2353:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffdb8u)), (uint8_t)0x2du); /* cmp byte ptr [ebp - 0x248], 0x2d */
    if (!c->zf) goto L_006b2369; /* jne 0x6b2369 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb9u)); /* lea edi, [ebp - 0x247] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
L_006b2369:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
L_006b236a:;
    PUSH32(c, 0x006b236fu); f_006b4390(c); /* call 0x6b4390 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b2571; /* jmp 0x6b2571 */
L_006b2375:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x69u)); /* sub eax, 0x69 */
    if (c->zf) goto L_006b244f; /* je 0x6b244f */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x5u)); /* sub eax, 5 */
    if (c->zf) goto L_006b2425; /* je 0x6b2425 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b2412; /* je 0x6b2412 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b23e2; /* je 0x6b23e2 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (c->zf) goto L_006b2197; /* je 0x6b2197 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b2453; /* je 0x6b2453 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x3u)); /* sub eax, 3 */
    if (!c->zf) goto L_006b2574; /* jne 0x6b2574 */
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x27u)); /* mov dword ptr [ebp - 0x2c], 0x27 */
    goto L_006b23f0; /* jmp 0x6b23f0 */
L_006b23b4:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 1)); /* sar eax, 1 */
    goto L_006b2571; /* jmp 0x6b2571 */
L_006b23bd:;
    (void)logic32(c, (uint32_t)(c->ecx & c->ecx)); /* test ecx, ecx */
    if (!c->zf) goto L_006b23ca; /* jne 0x6b23ca */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6ca920u))); /* mov ecx, dword ptr [0x1003a920] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ecx)); /* mov dword ptr [ebp - 8], ecx */
L_006b23ca:;
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
L_006b23cc:;
    c->edx = (uint32_t)(c->esi); /* mov edx, esi */
    c->esi = (uint32_t)(dec32(c, c->esi)); /* dec esi */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if (c->zf) goto L_006b23db; /* je 0x6b23db */
    (void)sub8(c, R8((uint32_t)(c->eax)), (uint8_t)0x0u); /* cmp byte ptr [eax], 0 */
    if (c->zf) goto L_006b23db; /* je 0x6b23db */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    goto L_006b23cc; /* jmp 0x6b23cc */
L_006b23db:;
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    goto L_006b2571; /* jmp 0x6b2571 */
L_006b23e2:;
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0x10], 8 */
L_006b23e9:;
    W32((uint32_t)(c->ebp + 0xffffffd4u), (uint32_t)((uint32_t)0x7u)); /* mov dword ptr [ebp - 0x2c], 7 */
L_006b23f0:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x10u)); /* mov dword ptr [ebp - 0xc], 0x10 */
    if (c->zf) goto L_006b245a; /* je 0x6b245a */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0xffffffd4u))); /* mov al, byte ptr [ebp - 0x2c] */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ebp - 0x16], 0x30 */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(add8(c, ((uint8_t)c->eax), (uint8_t)0x51u)); /* add al, 0x51 */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x2u)); /* mov dword ptr [ebp - 0x1c], 2 */
    W8((uint32_t)(c->ebp + 0xffffffebu), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [ebp - 0x15], al */
    goto L_006b245a; /* jmp 0x6b245a */
L_006b2412:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 4], 0x80 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [ebp - 0xc], 8 */
    if (c->zf) goto L_006b245a; /* je 0x6b245a */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x2u)))); } /* or byte ptr [ebp - 3], 2 */
    goto L_006b245a; /* jmp 0x6b245a */
L_006b2425:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b242eu); f_006b2749(c); /* call 0x6b2749 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (c->zf) goto L_006b243e; /* je 0x6b243e */
    c->ecx = (c->ecx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffffecu))); /* mov cx, word ptr [ebp - 0x14] */
    W16((uint32_t)(c->eax), (uint16_t)(((uint16_t)c->ecx))); /* mov word ptr [eax], cx */
    goto L_006b2443; /* jmp 0x6b2443 */
L_006b243e:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov ecx, dword ptr [ebp - 0x14] */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
L_006b2443:;
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x28], 1 */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b244f:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0x40u)))); } /* or dword ptr [ebp - 4], 0x40 */
L_006b2453:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)((uint32_t)0xau)); /* mov dword ptr [ebp - 0xc], 0xa */
L_006b245a:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (c->zf) goto L_006b246c; /* je 0x6b246c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2469u); f_006b2756(c); /* call 0x6b2756 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b24ad; /* jmp 0x6b24ad */
L_006b246c:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x20u)); /* test byte ptr [ebp - 4], 0x20 */
    if (c->zf) goto L_006b2493; /* je 0x6b2493 */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_006b2488; /* je 0x6b2488 */
    PUSH32(c, 0x006b2481u); f_006b2749(c); /* call 0x6b2749 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int16_t)((uint16_t)c->eax)); /* movsx eax, ax */
L_006b2485:;
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    goto L_006b24ad; /* jmp 0x6b24ad */
L_006b2488:;
    PUSH32(c, 0x006b248du); f_006b2749(c); /* call 0x6b2749 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)((uint32_t)((uint16_t)c->eax)); /* movzx eax, ax */
    goto L_006b2485; /* jmp 0x6b2485 */
L_006b2493:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0x10u)); /* lea eax, [ebp + 0x10] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    if (c->zf) goto L_006b24a5; /* je 0x6b24a5 */
    PUSH32(c, 0x006b24a2u); f_006b2749(c); /* call 0x6b2749 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b2485; /* jmp 0x6b2485 */
L_006b24a5:;
    PUSH32(c, 0x006b24aau); f_006b2749(c); /* call 0x6b2749 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
L_006b24ad:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x40u)); /* test byte ptr [ebp - 4], 0x40 */
    if (c->zf) goto L_006b24ce; /* je 0x6b24ce */
    (void)logic32(c, (uint32_t)(c->edx & c->edx)); /* test edx, edx */
    if ((!c->zf && c->sf == c->of)) goto L_006b24ce; /* jg 0x6b24ce */
    if ((c->sf != c->of)) goto L_006b24bd; /* jl 0x6b24bd */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->cf) goto L_006b24ce; /* jae 0x6b24ce */
L_006b24bd:;
    c->eax = (uint32_t)(neg32(c, c->eax)); /* neg eax */
    c->edx = (uint32_t)(adc32(c, c->edx, (uint32_t)0x0u)); /* adc edx, 0 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edx = (uint32_t)(neg32(c, c->edx)); /* neg edx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    goto L_006b24d2; /* jmp 0x6b24d2 */
L_006b24ce:;
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
L_006b24d2:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x80u)); /* test byte ptr [ebp - 3], 0x80 */
    if (!c->zf) goto L_006b24db; /* jne 0x6b24db */
    c->edi = (uint32_t)(logic32(c, (uint32_t)(c->edi & (uint32_t)0x0u))); /* and edi, 0 */
L_006b24db:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if ((c->sf == c->of)) goto L_006b24ea; /* jge 0x6b24ea */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x10], 1 */
    goto L_006b24ee; /* jmp 0x6b24ee */
L_006b24ea:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0xfffffff7u)))); } /* and dword ptr [ebp - 4], 0xfffffff7 */
L_006b24ee:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (!c->zf) goto L_006b24f8; /* jne 0x6b24f8 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xffffffe4u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 0x1c], 0 */
L_006b24f8:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 8], eax */
L_006b24fe:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov eax, dword ptr [ebp - 0x10] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 0x10] */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006b250e; /* jg 0x6b250e */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->edi))); /* or eax, edi */
    if (c->zf) goto L_006b2549; /* je 0x6b2549 */
L_006b250e:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->edx = (uint32_t)((int32_t)c->eax >> 31); /* cdq  */
    { uint32_t v_ = c->edx; PUSH32(c, v_); } /* push edx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(c->ebp + 0xffffffc0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x40], eax */
    W32((uint32_t)(c->ebp + 0xffffffc4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x3c], edx */
    PUSH32(c, 0x006b2521u); f_006b95a0(c); /* call 0x6b95a0 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x3c] */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->ebx = (uint32_t)(add32(c, c->ebx, (uint32_t)0x30u)); /* add ebx, 0x30 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc0u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x40] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2533u); f_006b9530(c); /* call 0x6b9530 */
    (void)sub32(c, c->ebx, (uint32_t)0x39u); /* cmp ebx, 0x39 */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
    c->edi = (uint32_t)(c->edx); /* mov edi, edx */
    if ((c->zf || c->sf != c->of)) goto L_006b253f; /* jle 0x6b253f */
    c->ebx = (uint32_t)(add32(c, c->ebx, R32((uint32_t)(c->ebp + 0xffffffd4u)))); /* add ebx, dword ptr [ebp - 0x2c] */
L_006b253f:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    W8((uint32_t)(c->eax), (uint8_t)(((uint8_t)c->ebx))); /* mov byte ptr [eax], bl */
    goto L_006b24fe; /* jmp 0x6b24fe */
L_006b2549:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffb7u)); /* lea eax, [ebp - 0x49] */
    c->eax = (uint32_t)(sub32(c, c->eax, R32((uint32_t)(c->ebp + 0xfffffff8u)))); /* sub eax, dword ptr [ebp - 8] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ebp - 8] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffdu)) & (uint8_t)0x2u)); /* test byte ptr [ebp - 3], 2 */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    if (c->zf) goto L_006b2574; /* je 0x6b2574 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    (void)sub8(c, R8((uint32_t)(c->ecx)), (uint8_t)0x30u); /* cmp byte ptr [ecx], 0x30 */
    if (!c->zf) goto L_006b2567; /* jne 0x6b2567 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2574; /* jne 0x6b2574 */
L_006b2567:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff8u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ebp - 8] */
    c->eax = (uint32_t)(inc32(c, c->eax)); /* inc eax */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ecx, dword ptr [ebp - 8] */
    W8((uint32_t)(c->ecx), (uint8_t)((uint8_t)0x30u)); /* mov byte ptr [ecx], 0x30 */
L_006b2571:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
L_006b2574:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_006b2672; /* jne 0x6b2672 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x40u)); /* test bl, 0x40 */
    if (c->zf) goto L_006b25ac; /* je 0x6b25ac */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x1u)); /* test bh, 1 */
    if (c->zf) goto L_006b2591; /* je 0x6b2591 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp - 0x16], 0x2d */
    goto L_006b25a5; /* jmp 0x6b25a5 */
L_006b2591:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_006b259c; /* je 0x6b259c */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2bu)); /* mov byte ptr [ebp - 0x16], 0x2b */
    goto L_006b25a5; /* jmp 0x6b25a5 */
L_006b259c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_006b25ac; /* je 0x6b25ac */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x16], 0x20 */
L_006b25a5:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
L_006b25ac:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffe4u)))); /* sub esi, dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* sub esi, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0xcu)); /* test bl, 0xc */
    if (!c->zf) goto L_006b25cc; /* jne 0x6b25cc */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x006b25c9u); f_006b26e0(c); /* call 0x6b26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b25cc:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffeau)); /* lea eax, [ebp - 0x16] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b25dfu); f_006b2711(c); /* call 0x6b2711 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_006b25fe; /* je 0x6b25fe */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (!c->zf) goto L_006b25fe; /* jne 0x6b25fe */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    PUSH32(c, 0x006b25fbu); f_006b26e0(c); /* call 0x6b26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b25fe:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (c->zf) goto L_006b2645; /* je 0x6b2645 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_006b2645; /* jle 0x6b2645 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
L_006b2613:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    PUSH32(c, 0x006b2622u); f_006b945f(c); /* call 0x6b945f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_006b265a; /* jle 0x6b265a */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea ecx, [ebp - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2639u); f_006b2711(c); /* call 0x6b2711 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2613; /* jne 0x6b2613 */
    goto L_006b265a; /* jmp 0x6b265a */
L_006b2645:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x006b2657u); f_006b2711(c); /* call 0x6b2711 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b265a:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x4u)); /* test byte ptr [ebp - 4], 4 */
    if (c->zf) goto L_006b2672; /* je 0x6b2672 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x006b266fu); f_006b26e0(c); /* call 0x6b26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b2672:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) goto L_006b1f96; /* jne 0x6b1f96 */
L_006b2683:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b1fdf(CPU *c) { /* PTR_006b1fdf */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffff0u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 0x10], 0xffffffff */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x34], edx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x28], edx */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x20], edx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x1c], edx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 4], edx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edx)); /* mov dword ptr [ebp - 0x24], edx */
    goto L_006b2672; /* jmp 0x6b2672 */
L_006b2672:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) { jump_indirect(c, 0x006b1f96u, 0x006b267du); return; } /* jne 0x6b1f96 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b22f0(CPU *c) { /* PTR_006b22f0 */
    PREEMPT_POLL(c);
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
    { uint32_t t_ = R32((uint32_t)(0x6ca908u)); PUSH32(c, 0x006b231au); call_indirect(c, t_); } /* call dword ptr [0x1003a908] */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov esi, dword ptr [ebp - 4] */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80u))); /* and esi, 0x80 */
    if (c->zf) goto L_006b233c; /* je 0x6b233c */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff0u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x10], 0 */
    if (!c->zf) goto L_006b233c; /* jne 0x6b233c */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ca914u)); PUSH32(c, 0x006b233bu); call_indirect(c, t_); } /* call dword ptr [0x1003a914] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b233c:;
    (void)sub8(c, ((uint8_t)c->ebx), (uint8_t)0x67u); /* cmp bl, 0x67 */
    if (!c->zf) goto L_006b2353; /* jne 0x6b2353 */
    (void)logic32(c, (uint32_t)(c->esi & c->esi)); /* test esi, esi */
    if (!c->zf) goto L_006b2353; /* jne 0x6b2353 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb8u)); /* lea eax, [ebp - 0x248] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6ca90cu)); PUSH32(c, 0x006b2352u); call_indirect(c, t_); } /* call dword ptr [0x1003a90c] */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b2353:;
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xfffffdb8u)), (uint8_t)0x2du); /* cmp byte ptr [ebp - 0x248], 0x2d */
    if (!c->zf) goto L_006b2369; /* jne 0x6b2369 */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffdu); W8(a_, (uint8_t)(logic8(c, (uint8_t)(R8(a_) | (uint8_t)0x1u)))); } /* or byte ptr [ebp - 3], 1 */
    c->edi = (uint32_t)((uint32_t)(c->ebp + 0xfffffdb9u)); /* lea edi, [ebp - 0x247] */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 8], edi */
L_006b2369:;
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    PUSH32(c, 0x006b236fu); f_006b4390(c); /* call 0x6b4390 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b2571; /* jmp 0x6b2571 */
L_006b2571:;
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_006b2672; /* jne 0x6b2672 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffffcu))); /* mov ebx, dword ptr [ebp - 4] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x40u)); /* test bl, 0x40 */
    if (c->zf) goto L_006b25ac; /* je 0x6b25ac */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0x1u)); /* test bh, 1 */
    if (c->zf) goto L_006b2591; /* je 0x6b2591 */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2du)); /* mov byte ptr [ebp - 0x16], 0x2d */
    goto L_006b25a5; /* jmp 0x6b25a5 */
L_006b2591:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x1u)); /* test bl, 1 */
    if (c->zf) goto L_006b259c; /* je 0x6b259c */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x2bu)); /* mov byte ptr [ebp - 0x16], 0x2b */
    goto L_006b25a5; /* jmp 0x6b25a5 */
L_006b259c:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x2u)); /* test bl, 2 */
    if (c->zf) goto L_006b25ac; /* je 0x6b25ac */
    W8((uint32_t)(c->ebp + 0xffffffeau), (uint8_t)((uint8_t)0x20u)); /* mov byte ptr [ebp - 0x16], 0x20 */
L_006b25a5:;
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 0x1c], 1 */
L_006b25ac:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xffffffe4u)))); /* sub esi, dword ptr [ebp - 0x1c] */
    c->esi = (uint32_t)(sub32(c, c->esi, R32((uint32_t)(c->ebp + 0xfffffff4u)))); /* sub esi, dword ptr [ebp - 0xc] */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0xcu)); /* test bl, 0xc */
    if (!c->zf) goto L_006b25cc; /* jne 0x6b25cc */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x006b25c9u); f_006b26e0(c); /* call 0x6b26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b25cc:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffeau)); /* lea eax, [ebp - 0x16] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffe4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b25dfu); f_006b2711(c); /* call 0x6b2711 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x8u)); /* test bl, 8 */
    if (c->zf) goto L_006b25fe; /* je 0x6b25fe */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & (uint8_t)0x4u)); /* test bl, 4 */
    if (!c->zf) goto L_006b25fe; /* jne 0x6b25fe */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x30u; PUSH32(c, v_); } /* push 0x30 */
    PUSH32(c, 0x006b25fbu); f_006b26e0(c); /* call 0x6b26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b25fe:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (c->zf) goto L_006b2645; /* je 0x6b2645 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0xc], 0 */
    if ((c->zf || c->sf != c->of)) goto L_006b2645; /* jle 0x6b2645 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff4u))); /* mov eax, dword ptr [ebp - 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff8u))); /* mov ebx, dword ptr [ebp - 8] */
    c->edi = (uint32_t)((uint32_t)(c->eax + 0xffffffffu)); /* lea edi, [eax - 1] */
L_006b2613:;
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebx))); /* mov ax, word ptr [ebx] */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->ebx = (uint32_t)(inc32(c, c->ebx)); /* inc ebx */
    PUSH32(c, 0x006b2622u); f_006b945f(c); /* call 0x6b945f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_006b265a; /* jle 0x6b265a */
    c->ecx = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea ecx, [ebp - 0x14] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2639u); f_006b2711(c); /* call 0x6b2711 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2613; /* jne 0x6b2613 */
    goto L_006b265a; /* jmp 0x6b265a */
L_006b2645:;
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0xc] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xfffffff8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 8] */
    PUSH32(c, 0x006b2657u); f_006b2711(c); /* call 0x6b2711 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b265a:;
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xfffffffcu)) & (uint8_t)0x4u)); /* test byte ptr [ebp - 4], 4 */
    if (c->zf) goto L_006b2672; /* je 0x6b2672 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffecu)); /* lea eax, [ebp - 0x14] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x20u; PUSH32(c, v_); } /* push 0x20 */
    PUSH32(c, 0x006b266fu); f_006b26e0(c); /* call 0x6b26e0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
L_006b2672:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov bl, byte ptr [edi] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ebx) & ((uint8_t)c->ebx))); /* test bl, bl */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp + 0xc], edi */
    if (!c->zf) { jump_indirect(c, 0x006b1f96u, 0x006b267du); return; } /* jne 0x6b1f96 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffecu))); /* mov eax, dword ptr [ebp - 0x14] */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b26ab(CPU *c) { /* PTR_006b26ab */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov ecx, dword ptr [ebp + 0xc] */
    { uint32_t a_ = (uint32_t)(c->ecx + 0x4u); W32(a_, (uint32_t)(dec32(c, R32(a_)))); } /* dec dword ptr [ecx + 4] */
    if (c->sf) goto L_006b26c4; /* js 0x6b26c4 */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx))); /* mov edx, dword ptr [ecx] */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->ebp + 0x8u))); /* mov al, byte ptr [ebp + 8] */
    W8((uint32_t)(c->edx), (uint8_t)(((uint8_t)c->eax))); /* mov byte ptr [edx], al */
    { uint32_t a_ = (uint32_t)(c->ecx); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [ecx] */
    c->eax = (uint32_t)((uint32_t)((uint8_t)c->eax)); /* movzx eax, al */
    goto L_006b26cf; /* jmp 0x6b26cf */
L_006b26c4:;
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b26cdu); f_006b1e52(c); /* call 0x6b1e52 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b26cf:;
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x10u))); /* mov eax, dword ptr [ebp + 0x10] */
    if (!c->zf) goto L_006b26dc; /* jne 0x6b26dc */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [eax], 0xffffffff */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
L_006b26dc:;
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [eax] */
    { uint32_t v_ = POP32(c); c->ebp = (uint32_t)(v_); } /* pop ebp */
    c->esp += 4; return; /* ret  */
}

void f_006b26e0(CPU *c) { /* PTR_006b26e0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov edi, dword ptr [esp + 0x10] */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006b270e; /* jle 0x6b270e */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x18u))); /* mov esi, dword ptr [esp + 0x18] */
L_006b26f1:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x18u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x18] */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x14u)); PUSH32(c, v_); } /* push dword ptr [esp + 0x14] */
    PUSH32(c, 0x006b26ffu); f_006b26ab(c); /* call 0x6b26ab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->esi)), (uint32_t)0xffffffffu); /* cmp dword ptr [esi], -1 */
    if (c->zf) goto L_006b270e; /* je 0x6b270e */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    c->edi = (uint32_t)(dec32(c, c->edi)); /* dec edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006b26f1; /* jg 0x6b26f1 */
L_006b270e:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b2711(CPU *c) { /* PTR_006b2711 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(R32((uint32_t)(c->esp + 0xcu))); /* mov ebx, dword ptr [esp + 0xc] */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((c->zf || c->sf != c->of)) goto L_006b2745; /* jle 0x6b2745 */
    c->edi = (uint32_t)(R32((uint32_t)(c->esp + 0x1cu))); /* mov edi, dword ptr [esp + 0x1c] */
    c->esi = (uint32_t)(R32((uint32_t)(c->esp + 0x10u))); /* mov esi, dword ptr [esp + 0x10] */
L_006b2727:;
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)R8((uint32_t)(c->esi))); /* movsx eax, byte ptr [esi] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    { uint32_t v_ = R32((uint32_t)(c->esp + 0x1cu)); PUSH32(c, v_); } /* push dword ptr [esp + 0x1c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2736u); f_006b26ab(c); /* call 0x6b26ab */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)sub32(c, R32((uint32_t)(c->edi)), (uint32_t)0xffffffffu); /* cmp dword ptr [edi], -1 */
    if (c->zf) goto L_006b2745; /* je 0x6b2745 */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(dec32(c, c->ebx)); /* dec ebx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if ((!c->zf && c->sf == c->of)) goto L_006b2727; /* jg 0x6b2727 */
L_006b2745:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006b2749(CPU *c) { /* PTR_006b2749 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + 0xfffffffcu))); /* mov eax, dword ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_006b2756(CPU *c) { /* PTR_006b2756 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x8u))); } /* add dword ptr [eax], 8 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->eax))); /* mov ecx, dword ptr [eax] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffff8u))); /* mov eax, dword ptr [ecx - 8] */
    c->edx = (uint32_t)(R32((uint32_t)(c->ecx + 0xfffffffcu))); /* mov edx, dword ptr [ecx - 4] */
    c->esp += 4; return; /* ret  */
}

void f_006b2766(CPU *c) { /* PTR_006b2766 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    { uint32_t a_ = (uint32_t)(c->eax); W32(a_, (uint32_t)(add32(c, R32(a_), (uint32_t)0x4u))); } /* add dword ptr [eax], 4 */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax))); /* mov eax, dword ptr [eax] */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->eax + 0xfffffffcu))); /* mov ax, word ptr [eax - 4] */
    c->esp += 4; return; /* ret  */
}

void f_006b2774(CPU *c) { /* FUN_10022774 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1600u; PUSH32(c, v_); } /* push 0x10031600 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
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
    if (!c->zf) goto L_006b27ae; /* jne 0x6b27ae */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xcu)); PUSH32(c, v_); } /* push dword ptr [ebp + 0xc] */
    PUSH32(c, 0x006b27a8u); f_006b09fd(c); /* call 0x6b09fd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b2a94; /* jmp 0x6b2a94 */
L_006b27ae:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_006b27c1; /* jne 0x6b27c1 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b27bbu); f_006b002f(c); /* call 0x6b002f */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    goto L_006b2a92; /* jmp 0x6b2a92 */
L_006b27c1:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6d06e8u))); /* mov eax, dword ptr [0x100406e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006b2908; /* jne 0x6b2908 */
L_006b27cf:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b28cc; /* ja 0x6b28cc */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b27e2u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 4], edi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b27ecu); f_006b58b7(c); /* call 0x6b58b7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_006b289c; /* je 0x6b289c */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6d06e0u))); /* cmp esi, dword ptr [0x100406e0] */
    if ((!c->cf && !c->zf)) goto L_006b284c; /* ja 0x6b284c */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2808u); f_006b60c0(c); /* call 0x6b60c0 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2814; /* je 0x6b2814 */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 0x24], ebx */
    goto L_006b284c; /* jmp 0x6b284c */
L_006b2814:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b281au); f_006b5c0b(c); /* call 0x6b5c0b */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_006b284c; /* je 0x6b284c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b282f; /* jb 0x6b282f */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b282f:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b2839u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b283fu); f_006b58b7(c); /* call 0x6b58b7 */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2849u); f_006b58e2(c); /* call 0x6b58e2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b284c:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), c->edi); /* cmp dword ptr [ebp - 0x24], edi */
    if (!c->zf) goto L_006b289c; /* jne 0x6b289c */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_006b285b; /* jne 0x6b285b */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_006b285b:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b2872u); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (c->zf) goto L_006b289c; /* je 0x6b289c */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebx + 0xfffffffcu))); /* mov eax, dword ptr [ebx - 4] */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b2886; /* jb 0x6b2886 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b2886:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b2890u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x28] */
    PUSH32(c, 0x006b2899u); f_006b58e2(c); /* call 0x6b58e2 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x14u)); /* add esp, 0x14 */
L_006b289c:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b28a5u); f_006b28ff(c); /* call 0x6b28ff */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), c->edi); /* cmp dword ptr [ebp - 0x28], edi */
    if (!c->zf) goto L_006b28cc; /* jne 0x6b28cc */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_006b28b1; /* jne 0x6b28b1 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b28b1:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b28c9u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_006b28cc:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006b2a94; /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) goto L_006b2a94; /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b28e9u); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b27cf; /* jne 0x6b27cf */
    goto L_006b2a92; /* jmp 0x6b2a92 */
L_006b2908:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b2a58; /* jne 0x6b2a58 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2928; /* ja 0x6b2928 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_006b2922; /* jbe 0x6b2922 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_006b2925; /* jmp 0x6b2925 */
L_006b2922:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b2925:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_006b2928:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a27; /* ja 0x6b2a27 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b293bu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2951u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006b2a0b; /* je 0x6b2a0b */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if (!c->cf) goto L_006b29c5; /* jae 0x6b29c5 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b297bu); f_006b69da(c); /* call 0x6b69da */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b298a; /* je 0x6b298a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_006b29c2; /* jmp 0x6b29c2 */
L_006b298a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2990u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b29c2; /* je 0x6b29c2 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29a7; /* jb 0x6b29a7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29a7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b29c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_006b29c5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a0b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a1bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
L_006b2a27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006b2a94; /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) goto L_006b2a94; /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2928; /* jne 0x6b2928 */
    goto L_006b2a92; /* jmp 0x6b2a92 */
L_006b2a58:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a7b; /* ja 0x6b2a7b */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_006b2a66; /* jne 0x6b2a66 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b2a66:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a7bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
L_006b2a7b:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006b2a94; /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) goto L_006b2a94; /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a8du); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2a58; /* jne 0x6b2a58 */
L_006b2a92:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b2a94:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b28f7(CPU *c) { /* PTR_006b28f7 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    { f_006b28ff(c); return; }
}

void f_006b28ff(CPU *c) { /* FUN_100228ff */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2906u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b2908(CPU *c) { /* PTR_006b2908 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) { f_006b2a58(c); return; } /* jne 0x6b2a58 */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2928; /* ja 0x6b2928 */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if ((c->cf || c->zf)) goto L_006b2922; /* jbe 0x6b2922 */
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    goto L_006b2925; /* jmp 0x6b2925 */
L_006b2922:;
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b2925:;
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_006b2928:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a27; /* ja 0x6b2a27 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b293bu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2951u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006b2a0b; /* je 0x6b2a0b */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if (!c->cf) goto L_006b29c5; /* jae 0x6b29c5 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b297bu); f_006b69da(c); /* call 0x6b69da */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b298a; /* je 0x6b298a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_006b29c2; /* jmp 0x6b29c2 */
L_006b298a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2990u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b29c2; /* je 0x6b29c2 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29a7; /* jb 0x6b29a7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29a7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b29c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_006b29c5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a0b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a1bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
L_006b2a27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2928; /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2922(CPU *c) { /* PTR_006b2922 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x10u; PUSH32(c, v_); } /* push 0x10 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_006b2928:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a27; /* ja 0x6b2a27 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b293bu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2951u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006b2a0b; /* je 0x6b2a0b */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if (!c->cf) goto L_006b29c5; /* jae 0x6b29c5 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b297bu); f_006b69da(c); /* call 0x6b69da */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b298a; /* je 0x6b298a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_006b29c2; /* jmp 0x6b29c2 */
L_006b298a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2990u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b29c2; /* je 0x6b29c2 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29a7; /* jb 0x6b29a7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29a7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b29c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_006b29c5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a0b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a1bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
L_006b2a27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2928; /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2925(CPU *c) { /* PTR_006b2925 */
    PREEMPT_POLL(c);
    W32((uint32_t)(c->ebp + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [ebp + 0xc], esi */
L_006b2928:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a27; /* ja 0x6b2a27 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b293bu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2951u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006b2a0b; /* je 0x6b2a0b */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if (!c->cf) goto L_006b29c5; /* jae 0x6b29c5 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b297bu); f_006b69da(c); /* call 0x6b69da */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b298a; /* je 0x6b298a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_006b29c2; /* jmp 0x6b29c2 */
L_006b298a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2990u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b29c2; /* je 0x6b29c2 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29a7; /* jb 0x6b29a7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29a7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b29c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_006b29c5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a0b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a1bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
L_006b2a27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2928; /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2928(CPU *c) { /* PTR_006b2928 */
    PREEMPT_POLL(c);
L_006b2928:;
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x24], edi */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a27; /* ja 0x6b2a27 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b293bu); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffc8u)); /* lea eax, [ebp - 0x38] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2951u); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    c->edi = (uint32_t)(c->eax); /* mov edi, eax */
    W32((uint32_t)(c->ebp + 0xffffffd0u), (uint32_t)(c->edi)); /* mov dword ptr [ebp - 0x30], edi */
    (void)logic32(c, (uint32_t)(c->edi & c->edi)); /* test edi, edi */
    if (c->zf) goto L_006b2a0b; /* je 0x6b2a0b */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6ccfb4u))); /* cmp esi, dword ptr [0x1003cfb4] */
    if (!c->cf) goto L_006b29c5; /* jae 0x6b29c5 */
    c->ebx = (uint32_t)(c->esi); /* mov ebx, esi */
    c->ebx = (uint32_t)(shr32(c, c->ebx, 4)); /* shr ebx, 4 */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b297bu); f_006b69da(c); /* call 0x6b69da */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b298a; /* je 0x6b298a */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov eax, dword ptr [ebp + 8] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    goto L_006b29c2; /* jmp 0x6b29c2 */
L_006b298a:;
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2990u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b29c2; /* je 0x6b29c2 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29a7; /* jb 0x6b29a7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29a7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b29c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
L_006b29c5:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a0b:;
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a1bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
L_006b2a27:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2928; /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b298a(CPU *c) { /* PTR_006b298a */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    PUSH32(c, 0x006b2990u); f_006b66ae(c); /* call 0x6b66ae */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b29c2; /* je 0x6b29c2 */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29a7; /* jb 0x6b29a7 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29a7:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
L_006b29c2:;
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b29a7(CPU *c) { /* PTR_006b29a7 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29b3u); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b29bfu); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b29c2(CPU *c) { /* PTR_006b29c2 */
    PREEMPT_POLL(c);
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b29c5(CPU *c) { /* PTR_006b29c5 */
    PREEMPT_POLL(c);
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffdcu)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x24], 0 */
    if (!c->zf) goto L_006b2a1e; /* jne 0x6b2a1e */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be070u)); PUSH32(c, 0x006b29dau); call_indirect(c, t_); } /* call dword ptr [0x1002e070] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2a1e; /* je 0x6b2a1e */
    c->eax = (uint32_t)((uint32_t)R8((uint32_t)(c->edi))); /* movzx eax, byte ptr [edi] */
    c->eax = (uint32_t)(shl32(c, c->eax, 4)); /* shl eax, 4 */
    W32((uint32_t)(c->ebp + 0xffffffccu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x34], eax */
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if (c->cf) goto L_006b29f0; /* jb 0x6b29f0 */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b29f0:;
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b29f0(CPU *c) { /* PTR_006b29f0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffdcu)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x24] */
    PUSH32(c, 0x006b29fau); f_006b7750(c); /* call 0x6b7750 */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffd4u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x2c] */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0xffffffc8u)); PUSH32(c, v_); } /* push dword ptr [ebp - 0x38] */
    PUSH32(c, 0x006b2a06u); f_006b6669(c); /* call 0x6b6669 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x18u)); /* add esp, 0x18 */
    goto L_006b2a1e; /* jmp 0x6b2a1e */
L_006b2a1e:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2a0b(CPU *c) { /* PTR_006b2a0b */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a1bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    W32((uint32_t)(c->ebp + 0xffffffdcu), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x24], eax */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2a1e(CPU *c) { /* PTR_006b2a1e */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2a27u); f_006b2a4d(c); /* call 0x6b2a4d */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2a27(CPU *c) { /* PTR_006b2a27 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffdcu))); /* mov eax, dword ptr [ebp - 0x24] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) { f_006b2a94(c); return; } /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) { f_006b2a94(c); return; } /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a3cu); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2928(c); return; } /* jne 0x6b2928 */
    { f_006b2a92(c); return; } /* jmp 0x6b2a92 */
}

void f_006b2a47(CPU *c) { /* PTR_006b2a47 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov esi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov ebx, dword ptr [ebp + 8] */
    { f_006b2a4d(c); return; }
}

void f_006b2a4d(CPU *c) { /* FUN_10022a4d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2a54u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    c->esp += 4; return; /* ret  */
}

void f_006b2a58(CPU *c) { /* PTR_006b2a58 */
    PREEMPT_POLL(c);
L_006b2a58:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    (void)sub32(c, c->esi, (uint32_t)0xffffffe0u); /* cmp esi, -0x20 */
    if ((!c->cf && !c->zf)) goto L_006b2a7b; /* ja 0x6b2a7b */
    (void)sub32(c, c->esi, c->edi); /* cmp esi, edi */
    if (!c->zf) goto L_006b2a66; /* jne 0x6b2a66 */
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
L_006b2a66:;
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a7bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
L_006b2a7b:;
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006b2a94; /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) goto L_006b2a94; /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a8du); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2a58; /* jne 0x6b2a58 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b2a94:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2a66(CPU *c) { /* PTR_006b2a66 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(add32(c, c->esi, (uint32_t)0xfu)); /* add esi, 0xf */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffff0u))); /* and esi, 0xfffffff0 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a0u)); PUSH32(c, 0x006b2a7bu); call_indirect(c, t_); } /* call dword ptr [0x1002e0a0] */
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006b2a94; /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) goto L_006b2a94; /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a8du); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2a58(c); return; } /* jne 0x6b2a58 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b2a94:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2a7b(CPU *c) { /* PTR_006b2a7b */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, c->edi); /* cmp eax, edi */
    if (!c->zf) goto L_006b2a94; /* jne 0x6b2a94 */
    (void)sub32(c, R32((uint32_t)(0x6d0358u)), c->edi); /* cmp dword ptr [0x10040358], edi */
    if (c->zf) goto L_006b2a94; /* je 0x6b2a94 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2a8du); f_006b83ff(c); /* call 0x6b83ff */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) { f_006b2a58(c); return; } /* jne 0x6b2a58 */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
L_006b2a94:;
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2a92(CPU *c) { /* PTR_006b2a92 */
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

void f_006b2a94(CPU *c) { /* PTR_006b2a94 */
    PREEMPT_POLL(c);
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2aa3(CPU *c) { /* FUN_10022aa3 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = 0xffffffffu; PUSH32(c, v_); } /* push -1 */
    { uint32_t v_ = 0x6c1618u; PUSH32(c, v_); } /* push 0x10031618 */
    { uint32_t v_ = 0x6b37fcu; PUSH32(c, v_); } /* push 0x100237fc */
    c->eax = (uint32_t)(R32((uint32_t)(0x0u + c->fs_base))); /* mov eax, dword ptr fs:[0] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->esp)); /* mov dword ptr fs:[0], esp */
    c->esp = (uint32_t)(sub32(c, c->esp, (uint32_t)0x1cu)); /* sub esp, 0x1c */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d06e8u))); /* mov eax, dword ptr [0x100406e8] */
    (void)sub32(c, c->eax, (uint32_t)0x3u); /* cmp eax, 3 */
    if (!c->zf) goto L_006b2b16; /* jne 0x6b2b16 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2ad7u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) & (uint32_t)0x0u)))); } /* and dword ptr [ebp - 4], 0 */
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0x8u))); /* mov esi, dword ptr [ebp + 8] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2ae5u); f_006b58b7(c); /* call 0x6b58b7 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xffffffe4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x1c], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2af8; /* je 0x6b2af8 */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi + 0xfffffffcu))); /* mov esi, dword ptr [esi - 4] */
    c->esi = (uint32_t)(sub32(c, c->esi, (uint32_t)0x9u)); /* sub esi, 9 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_006b2afb; /* jmp 0x6b2afb */
L_006b2af8:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_006b2afb:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2b04u); f_006b2b0d(c); /* call 0x6b2b0d */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffe4u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x1c], 0 */
    goto L_006b2b5f; /* jmp 0x6b2b5f */
L_006b2b16:;
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b2b61; /* jne 0x6b2b61 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2b22u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b2b3au); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2b4f; /* je 0x6b2b4f */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_006b2b52; /* jmp 0x6b2b52 */
L_006b2b4f:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_006b2b52:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2b5bu); f_006b2b88(c); /* call 0x6b2b88 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
L_006b2b5f:;
    if (!c->zf) goto L_006b2b74; /* jne 0x6b2b74 */
L_006b2b61:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a4u)); PUSH32(c, 0x006b2b72u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b2b74:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2b0a(CPU *c) { /* PTR_006b2b0a */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_006b2b0d(c); return; }
}

void f_006b2b0d(CPU *c) { /* FUN_10022b0d */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2b14u); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b2b16(CPU *c) { /* PTR_006b2b16 */
    PREEMPT_POLL(c);
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (!c->zf) goto L_006b2b61; /* jne 0x6b2b61 */
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2b22u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffdcu)); /* lea eax, [ebp - 0x24] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    c->eax = (uint32_t)((uint32_t)(c->ebp + 0xffffffd4u)); /* lea eax, [ebp - 0x2c] */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b2b3au); f_006b6612(c); /* call 0x6b6612 */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    W32((uint32_t)(c->ebp + 0xffffffd8u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x28], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (c->zf) goto L_006b2b4f; /* je 0x6b2b4f */
    c->esi = (uint32_t)((uint32_t)R8((uint32_t)(c->eax))); /* movzx esi, byte ptr [eax] */
    c->esi = (uint32_t)(shl32(c, c->esi, 4)); /* shl esi, 4 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->esi)); /* mov dword ptr [ebp - 0x20], esi */
    goto L_006b2b52; /* jmp 0x6b2b52 */
L_006b2b4f:;
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
L_006b2b52:;
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2b5bu); f_006b2b88(c); /* call 0x6b2b88 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_006b2b74; /* jne 0x6b2b74 */
L_006b2b61:;
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a4u)); PUSH32(c, 0x006b2b72u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b2b74:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2b4f(CPU *c) { /* PTR_006b2b4f */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2b5bu); f_006b2b88(c); /* call 0x6b2b88 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_006b2b74; /* jne 0x6b2b74 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a4u)); PUSH32(c, 0x006b2b72u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b2b74:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2b52(CPU *c) { /* PTR_006b2b52 */
    PREEMPT_POLL(c);
    { uint32_t a_ = (uint32_t)(c->ebp + 0xfffffffcu); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [ebp - 4], 0xffffffff */
    PUSH32(c, 0x006b2b5bu); f_006b2b88(c); /* call 0x6b2b88 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xffffffd8u)), (uint32_t)0x0u); /* cmp dword ptr [ebp - 0x28], 0 */
    if (!c->zf) goto L_006b2b74; /* jne 0x6b2b74 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a4u)); PUSH32(c, 0x006b2b72u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b2b74:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2b5f(CPU *c) { /* PTR_006b2b5f */
    PREEMPT_POLL(c);
    if (!c->zf) goto L_006b2b74; /* jne 0x6b2b74 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a4u)); PUSH32(c, 0x006b2b72u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a4] */
    c->esi = (uint32_t)(c->eax); /* mov esi, eax */
L_006b2b74:;
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
    c->ecx = (uint32_t)(R32((uint32_t)(c->ebp + 0xfffffff0u))); /* mov ecx, dword ptr [ebp - 0x10] */
    W32((uint32_t)(0x0u + c->fs_base), (uint32_t)(c->ecx)); /* mov dword ptr fs:[0], ecx */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2b61(CPU *c) { /* PTR_006b2b61 */
    PREEMPT_POLL(c);
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    { uint32_t v_ = 0x0u; PUSH32(c, v_); } /* push 0 */
    { uint32_t v_ = R32((uint32_t)(0x6d06e4u)); PUSH32(c, v_); } /* push dword ptr [0x100406e4] */
    { uint32_t t_ = R32((uint32_t)(0x6be0a4u)); PUSH32(c, 0x006b2b72u); call_indirect(c, t_); } /* call dword ptr [0x1002e0a4] */
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

void f_006b2b74(CPU *c) { /* PTR_006b2b74 */
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

void f_006b2b85(CPU *c) { /* PTR_006b2b85 */
    PREEMPT_POLL(c);
    c->esi = (uint32_t)(R32((uint32_t)(c->ebp + 0xffffffe0u))); /* mov esi, dword ptr [ebp - 0x20] */
    { f_006b2b88(c); return; }
}

void f_006b2b88(CPU *c) { /* FUN_10022b88 */
    PREEMPT_POLL(c);
    { uint32_t v_ = 0x9u; PUSH32(c, v_); } /* push 9 */
    PUSH32(c, 0x006b2b8fu); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
}

void f_006b2ba0(CPU *c) { /* PTR_006b2ba0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006b2bb0(CPU *c) { /* FUN_10022bb0 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->esp + 0x8u))); /* mov al, byte ptr [esp + 8] */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_006b2bdb; /* je 0x6b2bdb */
L_006b2bc8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_006b2ba0(c); return; } /* je 0x6b2ba0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006b2c24; /* je 0x6b2c24 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_006b2bc8; /* jne 0x6b2bc8 */
L_006b2bdb:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_006b2be6:;
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
    if (!c->zf) goto L_006b2c28; /* jne 0x6b2c28 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_006b2be6; /* je 0x6b2be6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_006b2c22; /* jne 0x6b2c22 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_006b2be6; /* jne 0x6b2be6 */
L_006b2c22:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_006b2c24:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006b2c28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006b2c65; /* je 0x6b2c65 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_006b2c5e; /* je 0x6b2c5e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006b2c57; /* je 0x6b2c57 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_006b2c50; /* je 0x6b2c50 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    goto L_006b2be6; /* jmp 0x6b2be6 */
L_006b2c50:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_006b2c57:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_006b2c5e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_006b2c65:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006b2bb6(CPU *c) { /* PTR_006b2bb6 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    c->ebx = (uint32_t)(c->eax); /* mov ebx, eax */
    c->eax = (uint32_t)(shl32(c, c->eax, 8)); /* shl eax, 8 */
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov edx, dword ptr [esp + 8] */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (c->zf) goto L_006b2bdb; /* je 0x6b2bdb */
L_006b2bc8:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edx))); /* mov cl, byte ptr [edx] */
    c->edx = (uint32_t)(inc32(c, c->edx)); /* inc edx */
    (void)sub8(c, ((uint8_t)c->ecx), ((uint8_t)c->ebx)); /* cmp cl, bl */
    if (c->zf) { f_006b2ba0(c); return; } /* je 0x6b2ba0 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & ((uint8_t)c->ecx))); /* test cl, cl */
    if (c->zf) goto L_006b2c24; /* je 0x6b2c24 */
    (void)logic32(c, (uint32_t)(c->edx & (uint32_t)0x3u)); /* test edx, 3 */
    if (!c->zf) goto L_006b2bc8; /* jne 0x6b2bc8 */
L_006b2bdb:;
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->eax = (uint32_t)(c->ebx); /* mov eax, ebx */
    c->ebx = (uint32_t)(shl32(c, c->ebx, 16)); /* shl ebx, 0x10 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->ebx = (uint32_t)(logic32(c, (uint32_t)(c->ebx | c->eax))); /* or ebx, eax */
L_006b2be6:;
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
    if (!c->zf) goto L_006b2c28; /* jne 0x6b2c28 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x81010100u))); /* and eax, 0x81010100 */
    if (c->zf) goto L_006b2be6; /* je 0x6b2be6 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1010100u))); /* and eax, 0x1010100 */
    if (!c->zf) goto L_006b2c22; /* jne 0x6b2c22 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0x80000000u))); /* and esi, 0x80000000 */
    if (!c->zf) goto L_006b2be6; /* jne 0x6b2be6 */
L_006b2c22:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
L_006b2c24:;
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    c->esp += 4; return; /* ret  */
L_006b2c28:;
    c->eax = (uint32_t)(R32((uint32_t)(c->edx + 0xfffffffcu))); /* mov eax, dword ptr [edx - 4] */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006b2c65; /* je 0x6b2c65 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_006b2c5e; /* je 0x6b2c5e */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    c->eax = (uint32_t)(shr32(c, c->eax, 16)); /* shr eax, 0x10 */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006b2c57; /* je 0x6b2c57 */
    (void)logic8(c, (uint8_t)(((uint8_t)c->eax) & ((uint8_t)c->eax))); /* test al, al */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    (void)sub8(c, ((uint8_t)(c->eax >> 8)), ((uint8_t)c->ebx)); /* cmp ah, bl */
    if (c->zf) goto L_006b2c50; /* je 0x6b2c50 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->eax >> 8)) & ((uint8_t)(c->eax >> 8)))); /* test ah, ah */
    if (c->zf) goto L_006b2c22; /* je 0x6b2c22 */
    goto L_006b2be6; /* jmp 0x6b2be6 */
L_006b2c50:;
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xffffffffu)); /* lea eax, [edx - 1] */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_006b2c57:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffeu)); /* lea eax, [edx - 2] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_006b2c5e:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffdu)); /* lea eax, [edx - 3] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
L_006b2c65:;
    c->eax = (uint32_t)((uint32_t)(c->edx + 0xfffffffcu)); /* lea eax, [edx - 4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006b2c6c(CPU *c) { /* PTR_006b2c6c */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(0x6d1820u))); /* mov eax, dword ptr [0x10041820] */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = 0x14u; PUSH32(c, v_); } /* push 0x14 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    if (!c->zf) goto L_006b2c80; /* jne 0x6b2c80 */
    c->eax = (uint32_t)((uint32_t)0x200u); /* mov eax, 0x200 */
    goto L_006b2c86; /* jmp 0x6b2c86 */
L_006b2c80:;
    (void)sub32(c, c->eax, c->esi); /* cmp eax, esi */
    if ((c->sf == c->of)) goto L_006b2c8b; /* jge 0x6b2c8b */
    c->eax = (uint32_t)(c->esi); /* mov eax, esi */
L_006b2c86:;
    W32((uint32_t)(0x6d1820u), (uint32_t)(c->eax)); /* mov dword ptr [0x10041820], eax */
L_006b2c8b:;
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2c93u); f_006b0b37(c); /* call 0x6b0b37 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x6d0804u), (uint32_t)(c->eax)); /* mov dword ptr [0x10040804], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b2cbf; /* jne 0x6b2cbf */
    { uint32_t v_ = 0x4u; PUSH32(c, v_); } /* push 4 */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    W32((uint32_t)(0x6d1820u), (uint32_t)(c->esi)); /* mov dword ptr [0x10041820], esi */
    PUSH32(c, 0x006b2cacu); f_006b0b37(c); /* call 0x6b0b37 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    W32((uint32_t)(0x6d0804u), (uint32_t)(c->eax)); /* mov dword ptr [0x10040804], eax */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if (!c->zf) goto L_006b2cbf; /* jne 0x6b2cbf */
    { uint32_t v_ = 0x1au; PUSH32(c, v_); } /* push 0x1a */
    PUSH32(c, 0x006b2cbeu); f_006afd31(c); /* call 0x6afd31 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b2cbf:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->eax = (uint32_t)((uint32_t)0x6ca930u); /* mov eax, 0x1003a930 */
L_006b2cc6:;
    c->edx = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov edx, dword ptr [0x10040804] */
    W32((uint32_t)(c->ecx + c->edx), (uint32_t)(c->eax)); /* mov dword ptr [ecx + edx], eax */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    c->ecx = (uint32_t)(add32(c, c->ecx, (uint32_t)0x4u)); /* add ecx, 4 */
    (void)sub32(c, c->eax, (uint32_t)0x6cabb0u); /* cmp eax, 0x1003abb0 */
    if ((c->sf != c->of)) goto L_006b2cc6; /* jl 0x6b2cc6 */
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->edx = (uint32_t)((uint32_t)0x6ca940u); /* mov edx, 0x1003a940 */
L_006b2ce3:;
    c->esi = (uint32_t)(c->ecx); /* mov esi, ecx */
    c->eax = (uint32_t)(c->ecx); /* mov eax, ecx */
    c->esi = (uint32_t)(sar32(c, c->esi, 5)); /* sar esi, 5 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax & (uint32_t)0x1fu))); /* and eax, 0x1f */
    c->esi = (uint32_t)(R32((uint32_t)(c->esi * 4 + 0x6d0700u))); /* mov esi, dword ptr [esi*4 + 0x10040700] */
    c->eax = (uint32_t)((uint32_t)(c->eax + c->eax * 8)); /* lea eax, [eax + eax*8] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax * 4))); /* mov eax, dword ptr [esi + eax*4] */
    (void)sub32(c, c->eax, (uint32_t)0xffffffffu); /* cmp eax, -1 */
    if (c->zf) goto L_006b2d03; /* je 0x6b2d03 */
    (void)logic32(c, (uint32_t)(c->eax & c->eax)); /* test eax, eax */
    if (!c->zf) goto L_006b2d06; /* jne 0x6b2d06 */
L_006b2d03:;
    { uint32_t a_ = (uint32_t)(c->edx); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edx], 0xffffffff */
L_006b2d06:;
    c->edx = (uint32_t)(add32(c, c->edx, (uint32_t)0x20u)); /* add edx, 0x20 */
    c->ecx = (uint32_t)(inc32(c, c->ecx)); /* inc ecx */
    (void)sub32(c, c->edx, (uint32_t)0x6ca9a0u); /* cmp edx, 0x1003a9a0 */
    if ((c->sf != c->of)) goto L_006b2ce3; /* jl 0x6b2ce3 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b2d14(CPU *c) { /* PTR_006b2d14 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006b2d19u); f_006b9720(c); /* call 0x6b9720 */
    (void)sub8(c, R8((uint32_t)(0x6d0148u)), (uint8_t)0x0u); /* cmp byte ptr [0x10040148], 0 */
    if (c->zf) goto L_006b2d27; /* je 0x6b2d27 */
    { f_006b9615(c); return; } /* jmp 0x6b9615 */
L_006b2d27:;
    c->esp += 4; return; /* ret  */
}

void f_006b2d28(CPU *c) { /* FUN_10022d28 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)((uint32_t)0x6ca930u); /* mov ecx, 0x1003a930 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_006b2d4c; /* jb 0x6b2d4c */
    (void)sub32(c, c->eax, (uint32_t)0x6cab90u); /* cmp eax, 0x1003ab90 */
    if ((!c->cf && !c->zf)) goto L_006b2d4c; /* ja 0x6b2d4c */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2d4au); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006b2d4c:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be07cu)); PUSH32(c, 0x006b2d56u); call_indirect(c, t_); } /* call dword ptr [0x1002e07c] */
    c->esp += 4; return; /* ret  */
}

void f_006b2d57(CPU *c) { /* FUN_10022d57 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x14u); /* cmp eax, 0x14 */
    if ((c->sf == c->of)) goto L_006b2d6b; /* jge 0x6b2d6b */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2d69u); f_006b0d09(c); /* call 0x6b0d09 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006b2d6b:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be07cu)); PUSH32(c, 0x006b2d79u); call_indirect(c, t_); } /* call dword ptr [0x1002e07c] */
    c->esp += 4; return; /* ret  */
}

void f_006b2d7a(CPU *c) { /* FUN_10022d7a */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    c->ecx = (uint32_t)((uint32_t)0x6ca930u); /* mov ecx, 0x1003a930 */
    (void)sub32(c, c->eax, c->ecx); /* cmp eax, ecx */
    if (c->cf) goto L_006b2d9e; /* jb 0x6b2d9e */
    (void)sub32(c, c->eax, (uint32_t)0x6cab90u); /* cmp eax, 0x1003ab90 */
    if ((!c->cf && !c->zf)) goto L_006b2d9e; /* ja 0x6b2d9e */
    c->eax = (uint32_t)(sub32(c, c->eax, c->ecx)); /* sub eax, ecx */
    c->eax = (uint32_t)(sar32(c, c->eax, 5)); /* sar eax, 5 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2d9cu); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006b2d9e:;
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be080u)); PUSH32(c, 0x006b2da8u); call_indirect(c, t_); } /* call dword ptr [0x1002e080] */
    c->esp += 4; return; /* ret  */
}

void f_006b2da9(CPU *c) { /* FUN_10022da9 */
    PREEMPT_POLL(c);
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov eax, dword ptr [esp + 4] */
    (void)sub32(c, c->eax, (uint32_t)0x14u); /* cmp eax, 0x14 */
    if ((c->sf == c->of)) goto L_006b2dbd; /* jge 0x6b2dbd */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x1cu)); /* add eax, 0x1c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    PUSH32(c, 0x006b2dbbu); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->esp += 4; return; /* ret  */
L_006b2dbd:;
    c->eax = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov eax, dword ptr [esp + 8] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be080u)); PUSH32(c, 0x006b2dcbu); call_indirect(c, t_); } /* call dword ptr [0x1002e080] */
    c->esp += 4; return; /* ret  */
}

void f_006b2dcc(CPU *c) { /* FUN_10022dcc */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    c->esi = (uint32_t)(R32((uint32_t)(0x6d0364u))); /* mov esi, dword ptr [0x10040364] */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    c->edi = (uint32_t)(R32((uint32_t)(c->ebp + 0xcu))); /* mov edi, dword ptr [ebp + 0xc] */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 8], ebx */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)(c->ebx)); /* mov dword ptr [ebp - 4], ebx */
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi))); /* mov al, byte ptr [edi] */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x61u); /* cmp al, 0x61 */
    if (c->zf) goto L_006b2e05; /* je 0x6b2e05 */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x72u); /* cmp al, 0x72 */
    if (c->zf) goto L_006b2dfe; /* je 0x6b2dfe */
    (void)sub8(c, ((uint8_t)c->eax), (uint8_t)0x77u); /* cmp al, 0x77 */
    if (!c->zf) goto L_006b2f19; /* jne 0x6b2f19 */
    c->ecx = (uint32_t)((uint32_t)0x301u); /* mov ecx, 0x301 */
    goto L_006b2e0a; /* jmp 0x6b2e0a */
L_006b2dfe:;
    c->ecx = (uint32_t)(logic32(c, 0)); /* xor ecx, ecx */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x1u))); /* or esi, 1 */
    goto L_006b2e0d; /* jmp 0x6b2e0d */
L_006b2e05:;
    c->ecx = (uint32_t)((uint32_t)0x109u); /* mov ecx, 0x109 */
L_006b2e0a:;
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x2u))); /* or esi, 2 */
L_006b2e0d:;
    { uint32_t v_ = 0x1u; PUSH32(c, v_); } /* push 1 */
    { uint32_t v_ = POP32(c); c->edx = (uint32_t)(v_); } /* pop edx */
L_006b2e10:;
    c->eax = (c->eax & 0xffffff00u) | (uint8_t)(R8((uint32_t)(c->edi + 0x1u))); /* mov al, byte ptr [edi + 1] */
    c->edi = (uint32_t)(inc32(c, c->edi)); /* inc edi */
    (void)sub8(c, ((uint8_t)c->eax), ((uint8_t)c->ebx)); /* cmp al, bl */
    if (c->zf) goto L_006b2eff; /* je 0x6b2eff */
    (void)sub32(c, c->edx, c->ebx); /* cmp edx, ebx */
    if (c->zf) goto L_006b2eff; /* je 0x6b2eff */
    c->eax = (uint32_t)((uint32_t)(int32_t)(int8_t)((uint8_t)c->eax)); /* movsx eax, al */
    (void)sub32(c, c->eax, (uint32_t)0x54u); /* cmp eax, 0x54 */
    if ((!c->zf && c->sf == c->of)) goto L_006b2e9e; /* jg 0x6b2e9e */
    if (c->zf) goto L_006b2e8e; /* je 0x6b2e8e */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x2bu)); /* sub eax, 0x2b */
    if (c->zf) goto L_006b2e78; /* je 0x6b2e78 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x19u)); /* sub eax, 0x19 */
    if (c->zf) goto L_006b2e6e; /* je 0x6b2e6e */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xeu)); /* sub eax, 0xe */
    if (c->zf) goto L_006b2e59; /* je 0x6b2e59 */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ebx); /* cmp dword ptr [ebp - 4], ebx */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x20u))); /* or ecx, 0x20 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2e59:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffffcu)), c->ebx); /* cmp dword ptr [ebp - 4], ebx */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    W32((uint32_t)(c->ebp + 0xfffffffcu), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 4], 1 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x10u))); /* or ecx, 0x10 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2e6e:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x40u)); /* test cl, 0x40 */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x40u))); /* or ecx, 0x40 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2e78:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->ecx) & (uint8_t)0x2u)); /* test cl, 2 */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx & (uint32_t)0xfffffffeu))); /* and ecx, 0xfffffffe */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xfffffffcu))); /* and esi, 0xfffffffc */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | (uint32_t)0x2u))); /* or ecx, 2 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x80u))); /* or esi, 0x80 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2e8e:;
    c->eax = (uint32_t)((uint32_t)0x1000u); /* mov eax, 0x1000 */
    (void)logic32(c, (uint32_t)(c->eax & c->ecx)); /* test eax, ecx */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    c->ecx = (uint32_t)(logic32(c, (uint32_t)(c->ecx | c->eax))); /* or ecx, eax */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2e9e:;
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x62u)); /* sub eax, 0x62 */
    if (c->zf) goto L_006b2eeb; /* je 0x6b2eeb */
    c->eax = (uint32_t)(dec32(c, c->eax)); /* dec eax */
    if (c->zf) goto L_006b2ed4; /* je 0x6b2ed4 */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0xbu)); /* sub eax, 0xb */
    if (c->zf) goto L_006b2ebd; /* je 0x6b2ebd */
    c->eax = (uint32_t)(sub32(c, c->eax, (uint32_t)0x6u)); /* sub eax, 6 */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xc0u)); /* test ch, 0xc0 */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x40u))) << 8); /* or ch, 0x40 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2ebd:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->ebx); /* cmp dword ptr [ebp - 8], ebx */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 8], 1 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi & (uint32_t)0xffffbfffu))); /* and esi, 0xffffbfff */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2ed4:;
    (void)sub32(c, R32((uint32_t)(c->ebp + 0xfffffff8u)), c->ebx); /* cmp dword ptr [ebp - 8], ebx */
    if (!c->zf) goto L_006b2ef0; /* jne 0x6b2ef0 */
    W32((uint32_t)(c->ebp + 0xfffffff8u), (uint32_t)((uint32_t)0x1u)); /* mov dword ptr [ebp - 8], 1 */
    c->esi = (uint32_t)(logic32(c, (uint32_t)(c->esi | (uint32_t)0x4000u))); /* or esi, 0x4000 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2eeb:;
    (void)logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) & (uint8_t)0xc0u)); /* test ch, 0xc0 */
    if (c->zf) goto L_006b2ef7; /* je 0x6b2ef7 */
L_006b2ef0:;
    c->edx = (uint32_t)(logic32(c, 0)); /* xor edx, edx */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2ef7:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | (uint8_t)0x80u))) << 8); /* or ch, 0x80 */
    goto L_006b2e10; /* jmp 0x6b2e10 */
L_006b2eff:;
    { uint32_t v_ = 0x1a4u; PUSH32(c, v_); } /* push 0x1a4 */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x10u)); PUSH32(c, v_); } /* push dword ptr [ebp + 0x10] */
    { uint32_t v_ = c->ecx; PUSH32(c, v_); } /* push ecx */
    { uint32_t v_ = R32((uint32_t)(c->ebp + 0x8u)); PUSH32(c, v_); } /* push dword ptr [ebp + 8] */
    PUSH32(c, 0x006b2f10u); f_006b97cd(c); /* call 0x6b97cd */
    c->ecx = (uint32_t)(c->eax); /* mov ecx, eax */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0x10u)); /* add esp, 0x10 */
    (void)sub32(c, c->ecx, c->ebx); /* cmp ecx, ebx */
    if ((c->sf == c->of)) goto L_006b2f1d; /* jge 0x6b2f1d */
L_006b2f19:;
    c->eax = (uint32_t)(logic32(c, 0)); /* xor eax, eax */
    goto L_006b2f37; /* jmp 0x6b2f37 */
L_006b2f1d:;
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x14u))); /* mov eax, dword ptr [ebp + 0x14] */
    { uint32_t a_ = (uint32_t)(0x6d01bcu); W32(a_, (uint32_t)(inc32(c, R32(a_)))); } /* inc dword ptr [0x100401bc] */
    W32((uint32_t)(c->eax + 0xcu), (uint32_t)(c->esi)); /* mov dword ptr [eax + 0xc], esi */
    W32((uint32_t)(c->eax + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 4], ebx */
    W32((uint32_t)(c->eax), (uint32_t)(c->ebx)); /* mov dword ptr [eax], ebx */
    W32((uint32_t)(c->eax + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 8], ebx */
    W32((uint32_t)(c->eax + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [eax + 0x1c], ebx */
    W32((uint32_t)(c->eax + 0x10u), (uint32_t)(c->ecx)); /* mov dword ptr [eax + 0x10], ecx */
L_006b2f37:;
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b2f3c(CPU *c) { /* FUN_10022f3c */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebx; PUSH32(c, v_); } /* push ebx */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    { uint32_t v_ = c->edi; PUSH32(c, v_); } /* push edi */
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    c->ebx = (uint32_t)(logic32(c, 0)); /* xor ebx, ebx */
    c->edi = (uint32_t)(logic32(c, 0)); /* xor edi, edi */
    PUSH32(c, 0x006b2f4au); f_006b0d09(c); /* call 0x6b0d09 */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    (void)sub32(c, R32((uint32_t)(0x6d1820u)), c->ebx); /* cmp dword ptr [0x10041820], ebx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    if ((c->zf || c->sf != c->of)) goto L_006b2ff6; /* jle 0x6b2ff6 */
L_006b2f59:;
    c->eax = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov eax, dword ptr [0x10040804] */
    c->eax = (uint32_t)(R32((uint32_t)(c->eax + c->esi * 4))); /* mov eax, dword ptr [eax + esi*4] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_006b2f9c; /* je 0x6b2f9c */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [eax + 0xc], 0x83 */
    if (!c->zf) goto L_006b2f8c; /* jne 0x6b2f8c */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2f72u); f_006b2d57(c); /* call 0x6b2d57 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov ecx, dword ptr [0x10040804] */
    c->eax = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov eax, dword ptr [ecx + esi*4] */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->eax + 0xcu)) & (uint8_t)0x83u)); /* test byte ptr [eax + 0xc], 0x83 */
    if (c->zf) goto L_006b2f97; /* je 0x6b2f97 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b2f8au); f_006b2da9(c); /* call 0x6b2da9 */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
L_006b2f8c:;
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->esi, R32((uint32_t)(0x6d1820u))); /* cmp esi, dword ptr [0x10041820] */
    if ((c->sf != c->of)) goto L_006b2f59; /* jl 0x6b2f59 */
    goto L_006b2ff6; /* jmp 0x6b2ff6 */
L_006b2f97:;
    c->edi = (uint32_t)(R32((uint32_t)(c->ecx + c->esi * 4))); /* mov edi, dword ptr [ecx + esi*4] */
    goto L_006b2fe0; /* jmp 0x6b2fe0 */
L_006b2f9c:;
    { uint32_t v_ = 0x38u; PUSH32(c, v_); } /* push 0x38 */
    c->esi = (uint32_t)(shl32(c, c->esi, 2)); /* shl esi, 2 */
    PUSH32(c, 0x006b2fa6u); f_006b09fd(c); /* call 0x6b09fd */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->ecx = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov ecx, dword ptr [0x10040804] */
    W32((uint32_t)(c->esi + c->ecx), (uint32_t)(c->eax)); /* mov dword ptr [esi + ecx], eax */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov eax, dword ptr [0x10040804] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov eax, dword ptr [esi + eax] */
    (void)sub32(c, c->eax, c->ebx); /* cmp eax, ebx */
    if (c->zf) goto L_006b2ff6; /* je 0x6b2ff6 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be074u)); PUSH32(c, 0x006b2fc6u); call_indirect(c, t_); } /* call dword ptr [0x1002e074] */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov eax, dword ptr [0x10040804] */
    c->eax = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov eax, dword ptr [esi + eax] */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x20u)); /* add eax, 0x20 */
    { uint32_t v_ = c->eax; PUSH32(c, v_); } /* push eax */
    { uint32_t t_ = R32((uint32_t)(0x6be07cu)); PUSH32(c, 0x006b2fd8u); call_indirect(c, t_); } /* call dword ptr [0x1002e07c] */
    c->eax = (uint32_t)(R32((uint32_t)(0x6d0804u))); /* mov eax, dword ptr [0x10040804] */
    c->edi = (uint32_t)(R32((uint32_t)(c->esi + c->eax))); /* mov edi, dword ptr [esi + eax] */
L_006b2fe0:;
    (void)sub32(c, c->edi, c->ebx); /* cmp edi, ebx */
    if (c->zf) goto L_006b2ff6; /* je 0x6b2ff6 */
    { uint32_t a_ = (uint32_t)(c->edi + 0x10u); W32(a_, (uint32_t)(logic32(c, (uint32_t)(R32(a_) | (uint32_t)0xffffffffu)))); } /* or dword ptr [edi + 0x10], 0xffffffff */
    W32((uint32_t)(c->edi + 0x4u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 4], ebx */
    W32((uint32_t)(c->edi + 0xcu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0xc], ebx */
    W32((uint32_t)(c->edi + 0x8u), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 8], ebx */
    W32((uint32_t)(c->edi), (uint32_t)(c->ebx)); /* mov dword ptr [edi], ebx */
    W32((uint32_t)(c->edi + 0x1cu), (uint32_t)(c->ebx)); /* mov dword ptr [edi + 0x1c], ebx */
L_006b2ff6:;
    { uint32_t v_ = 0x2u; PUSH32(c, v_); } /* push 2 */
    PUSH32(c, 0x006b2ffdu); f_006b0d6a(c); /* call 0x6b0d6a */
    { uint32_t v_ = POP32(c); c->ecx = (uint32_t)(v_); } /* pop ecx */
    c->eax = (uint32_t)(c->edi); /* mov eax, edi */
    { uint32_t v_ = POP32(c); c->edi = (uint32_t)(v_); } /* pop edi */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    { uint32_t v_ = POP32(c); c->ebx = (uint32_t)(v_); } /* pop ebx */
    c->esp += 4; return; /* ret  */
}

void f_006b3004(CPU *c) { /* FUN_10023004 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->esi; PUSH32(c, v_); } /* push esi */
    PUSH32(c, 0x006b300au); f_006b3080(c); /* call 0x6b3080 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esp + 0x8u))); /* mov ecx, dword ptr [esp + 8] */
    c->esi = (uint32_t)(logic32(c, 0)); /* xor esi, esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->eax = (uint32_t)((uint32_t)0x6cabb0u); /* mov eax, 0x1003abb0 */
L_006b3017:;
    (void)sub32(c, c->ecx, R32((uint32_t)(c->eax))); /* cmp ecx, dword ptr [eax] */
    if (c->zf) goto L_006b303d; /* je 0x6b303d */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esi = (uint32_t)(inc32(c, c->esi)); /* inc esi */
    (void)sub32(c, c->eax, (uint32_t)0x6cad18u); /* cmp eax, 0x1003ad18 */
    if ((c->sf != c->of)) goto L_006b3017; /* jl 0x6b3017 */
    (void)sub32(c, c->ecx, (uint32_t)0x13u); /* cmp ecx, 0x13 */
    if (c->cf) goto L_006b304d; /* jb 0x6b304d */
    (void)sub32(c, c->ecx, (uint32_t)0x24u); /* cmp ecx, 0x24 */
    if ((!c->cf && !c->zf)) goto L_006b304d; /* ja 0x6b304d */
    PUSH32(c, 0x006b3035u); f_006b3077(c); /* call 0x6b3077 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0xdu)); /* mov dword ptr [eax], 0xd */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006b303d:;
    PUSH32(c, 0x006b3042u); f_006b3077(c); /* call 0x6b3077 */
    c->ecx = (uint32_t)(R32((uint32_t)(c->esi * 8 + 0x6cabb4u))); /* mov ecx, dword ptr [esi*8 + 0x1003abb4] */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    W32((uint32_t)(c->eax), (uint32_t)(c->ecx)); /* mov dword ptr [eax], ecx */
    c->esp += 4; return; /* ret  */
L_006b304d:;
    (void)sub32(c, c->ecx, (uint32_t)0xbcu); /* cmp ecx, 0xbc */
    if (c->cf) goto L_006b306a; /* jb 0x6b306a */
    (void)sub32(c, c->ecx, (uint32_t)0xcau); /* cmp ecx, 0xca */
    if ((!c->cf && !c->zf)) goto L_006b306a; /* ja 0x6b306a */
    PUSH32(c, 0x006b3062u); f_006b3077(c); /* call 0x6b3077 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x8u)); /* mov dword ptr [eax], 8 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
L_006b306a:;
    PUSH32(c, 0x006b306fu); f_006b3077(c); /* call 0x6b3077 */
    W32((uint32_t)(c->eax), (uint32_t)((uint32_t)0x16u)); /* mov dword ptr [eax], 0x16 */
    { uint32_t v_ = POP32(c); c->esi = (uint32_t)(v_); } /* pop esi */
    c->esp += 4; return; /* ret  */
}

void f_006b3077(CPU *c) { /* FUN_10023077 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006b307cu); f_006b1791(c); /* call 0x6b1791 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0x8u)); /* add eax, 8 */
    c->esp += 4; return; /* ret  */
}

void f_006b3080(CPU *c) { /* FUN_10023080 */
    PREEMPT_POLL(c);
    PUSH32(c, 0x006b3085u); f_006b1791(c); /* call 0x6b1791 */
    c->eax = (uint32_t)(add32(c, c->eax, (uint32_t)0xcu)); /* add eax, 0xc */
    c->esp += 4; return; /* ret  */
}

void f_006b3090(CPU *c) { /* PTR_006b3090 */
    PREEMPT_POLL(c);
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0xfeu)); /* mov byte ptr [ebp - 0x90], 0xfe */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (!c->zf) goto L_006b30e6; /* jne 0x6b30e6 */
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
L_006b309d:;
    ST(1) = ST(1) * log2(ST(0)); FPOP(c); /* fyl2x  */
    goto L_006b30ae; /* jmp 0x6b30ae */
L_006b30ae:;
    PUSH32(c, 0x006b30b3u); f_006b31ee(c); /* call 0x6b31ee */
    FPUSH(c, 1.0); /* fld1  */
    ST(1) = FPRES(c, ST(1) + ST(0)); FPOP(c); /* faddp st(1) */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (c->zf) goto L_006b30d4; /* je 0x6b30d4 */
    FPUSH(c, 1.0); /* fld1  */
    (void)sub32(c, R32((uint32_t)(0x6d00ecu)), (uint32_t)0x1u); /* cmp dword ptr [0x100400ec], 1 */
    if (c->zf) goto L_006b30cf; /* je 0x6b30cf */
    ST(1) = FPRES(c, FDIV(c, ST(0), ST(1))); FPOP(c); /* fdivrp st(1) */
    goto L_006b30d4; /* jmp 0x6b30d4 */
L_006b30cf:;
    PUSH32(c, 0x006b30d4u); f_006ba291(c); /* call 0x6ba291 */
L_006b30d4:;
    (void)logic8(c, (uint8_t)(((uint8_t)c->edx) & (uint8_t)0x40u)); /* test dl, 0x40 */
    if (!c->zf) goto L_006b30db; /* jne 0x6b30db */
    ST(0) = ldexp(ST(0), (int)trunc(ST(1))); /* fscale  */
L_006b30db:;
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_006b30e1; /* je 0x6b30e1 */
    ST(0) = -ST(0); /* fchs  */
L_006b30e1:;
    goto L_006b3398; /* jmp 0x6b3398 */
L_006b30e6:;
    PUSH32(c, 0x006b30ebu); f_006b3231(c); /* call 0x6b3231 */
    c->eax = (uint32_t)(logic32(c, (uint32_t)(c->eax | c->eax))); /* or eax, eax */
    if (c->zf) goto L_006b3103; /* je 0x6b3103 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, 0)) << 8); /* xor ch, ch */
    (void)sub32(c, c->eax, (uint32_t)0x2u); /* cmp eax, 2 */
    if (c->zf) goto L_006b30f8; /* je 0x6b30f8 */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)((uint8_t)~((uint8_t)(c->ecx >> 8))) << 8); /* not ch */
L_006b30f8:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = fabs(ST(0)); /* fabs  */
    goto L_006b309d; /* jmp 0x6b309d */
L_006b3103:;
    goto L_006b3446; /* jmp 0x6b3446 */
L_006b3398:;
    { double t_ = ST(0); ST(0) = ST(1); ST(1) = t_; } /* fxch st(1) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    c->esp += 4; return; /* ret  */
L_006b3446:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x6cad80u))); /* fld xword ptr [0x1003ad80] */
    (void)sub8(c, R8((uint32_t)(c->ebp + 0xffffff70u)), (uint8_t)0x0u); /* cmp byte ptr [ebp - 0x90], 0 */
    if ((!c->zf && c->sf == c->of)) goto L_006b3460; /* jg 0x6b3460 */
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x1u)); /* mov byte ptr [ebp - 0x90], 1 */
L_006b3460:;
    c->ecx = (c->ecx & 0xffffff00u) | (uint8_t)(logic8(c, (uint8_t)(((uint8_t)c->ecx) | ((uint8_t)c->ecx)))); /* or cl, cl */
    c->esp += 4; return; /* ret  */
}

void f_006b31a0(CPU *c) { /* PTR_006b31a0 */
    PREEMPT_POLL(c);
    { uint32_t v_ = POP32(c); c->eax = (uint32_t)(v_); } /* pop eax */
    FCOM(c, ST(0), 0.0); /* ftst  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x1u)); /* test byte ptr [ebp - 0x9f], 1 */
    if (!c->zf) goto L_006b31c3; /* jne 0x6b31c3 */
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, RF80((uint32_t)(0x6cad20u))); /* fld xword ptr [0x1003ad20] */
    c->ecx = (c->ecx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ecx >> 8)) | ((uint8_t)(c->ecx >> 8))))) << 8); /* or ch, ch */
    if (c->zf) goto L_006b31c2; /* je 0x6b31c2 */
    ST(0) = -ST(0); /* fchs  */
L_006b31c2:;
    c->esp += 4; return; /* ret  */
L_006b31c3:;
    W8((uint32_t)(c->ebp + 0xffffff70u), (uint8_t)((uint8_t)0x4u)); /* mov byte ptr [ebp - 0x90], 4 */
    goto L_006b33a6; /* jmp 0x6b33a6 */
L_006b33a6:;
    ST(0) = ST(0); FPOP(c); /* fstp st(0) */
    FPUSH(c, 0.0); /* fldz  */
    c->esp += 4; return; /* ret  */
}

void f_006b31ee(CPU *c) { /* PTR_006b31ee */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fabs(ST(0)); /* fabs  */
    FPUSH(c, RF80((uint32_t)(0x6cad3eu))); /* fld xword ptr [0x1003ad3e] */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    W16((uint32_t)(c->ebp + 0xffffff60u), FNSTSW(c)); /* fnstsw word ptr [ebp - 0xa0] */
    ; /* wait  */
    (void)logic8(c, (uint8_t)(R8((uint32_t)(c->ebp + 0xffffff61u)) & (uint8_t)0x41u)); /* test byte ptr [ebp - 0x9f], 0x41 */
    if (!c->zf) { f_006b31a0(c); return; } /* jne 0x6b31a0 */
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

void f_006b3231(CPU *c) { /* PTR_006b3231 */
    PREEMPT_POLL(c);
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); /* fcomp st(1) */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (!c->zf) goto L_006b3257; /* jne 0x6b3257 */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = FPRES(c, ST(0) * RF64((uint32_t)(0x6cad52u))); /* fmul qword ptr [0x1003ad52] */
    { double v_ = ST(0); FPUSH(c, v_); } /* fld st(0) */
    ST(0) = fpu_round(c, ST(0)); /* frndint  */
    FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c); /* fcompp  */
    ; /* wait  */
    c->eax = (c->eax & 0xffff0000u) | (uint16_t)(FNSTSW(c)); /* fnstsw ax */
    { uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; } /* sahf  */
    if (c->zf) goto L_006b325e; /* je 0x6b325e */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
L_006b3256:;
    c->esp += 4; return; /* ret  */
L_006b3257:;
    c->eax = (uint32_t)((uint32_t)0x0u); /* mov eax, 0 */
    goto L_006b3256; /* jmp 0x6b3256 */
L_006b325e:;
    c->eax = (uint32_t)((uint32_t)0x2u); /* mov eax, 2 */
    goto L_006b3256; /* jmp 0x6b3256 */
}

void f_006b32a0(CPU *c) { /* PTR_006b32a0 */
    PREEMPT_POLL(c);
    (void)sub8(c, R8((uint32_t)(c->edx + 0xeu)), (uint8_t)0x5u); /* cmp byte ptr [edx + 0xe], 5 */
    if (!c->zf) goto L_006b32b7; /* jne 0x6b32b7 */
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)(R16((uint32_t)(c->ebp + 0xffffff5cu))); /* mov bx, word ptr [ebp - 0xa4] */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) | (uint8_t)0x2u))) << 8); /* or bh, 2 */
    c->ebx = (c->ebx & 0xffff00ffu) | ((uint32_t)(uint8_t)(logic8(c, (uint8_t)(((uint8_t)(c->ebx >> 8)) & (uint8_t)0xfeu))) << 8); /* and bh, 0xfe */
    c->ebx = (c->ebx & 0xffffff00u) | (uint8_t)((uint8_t)0x3fu); /* mov bl, 0x3f */
    goto L_006b32bb; /* jmp 0x6b32bb */
L_006b32b7:;
    c->ebx = (c->ebx & 0xffff0000u) | (uint16_t)((uint16_t)0x133fu); /* mov bx, 0x133f */
L_006b32bb:;
    W16((uint32_t)(c->ebp + 0xffffff5eu), (uint16_t)(((uint16_t)c->ebx))); /* mov word ptr [ebp - 0xa2], bx */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0xffffff5eu)); fpu_sync_rounding(c); /* fldcw word ptr [ebp - 0xa2] */
    c->ebx = (uint32_t)((uint32_t)0x6cad9cu); /* mov ebx, 0x1003ad9c */
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
    { uint32_t t_ = R32((uint32_t)(c->ebx)); switch (t_) {  default: jump_indirect(c, t_, 0x006b3305u); return; } } /* jmp dword ptr [ebx] */
}

void f_006b3470(CPU *c) { /* FUN_10023470 */
    PREEMPT_POLL(c);
    { uint32_t v_ = c->ebp; PUSH32(c, v_); } /* push ebp */
    c->ebp = (uint32_t)(c->esp); /* mov ebp, esp */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xffffffe0u)); /* add esp, -0x20 */
    W32((uint32_t)(c->ebp + 0xffffffe0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x20], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x18u))); /* mov eax, dword ptr [ebp + 0x18] */
    W32((uint32_t)(c->ebp + 0xfffffff0u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0x10], eax */
    c->eax = (uint32_t)(R32((uint32_t)(c->ebp + 0x1cu))); /* mov eax, dword ptr [ebp + 0x1c] */
    W32((uint32_t)(c->ebp + 0xfffffff4u), (uint32_t)(c->eax)); /* mov dword ptr [ebp - 0xc], eax */
    { f_006b3490(c); return; } /* jmp 0x6b3490 */
}

void f_006b3487(CPU *c) { /* __startOneArgErrorHandling */
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
    PUSH32(c, 0x006b34b0u); f_006ba82b(c); /* call 0x6ba82b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_006b34c1; /* je 0x6b34c1 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_006b34c1:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b3490(CPU *c) { /* PTR_006b3490 */
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
    PUSH32(c, 0x006b34b0u); f_006ba82b(c); /* call 0x6ba82b */
    c->esp = (uint32_t)(add32(c, c->esp, (uint32_t)0xcu)); /* add esp, 0xc */
    FPUSH(c, RF64((uint32_t)(c->ebp + 0xfffffff8u))); /* fld qword ptr [ebp - 8] */
    (void)sub16(c, R16((uint32_t)(c->ebp + 0x8u)), (uint16_t)0x27fu); /* cmp word ptr [ebp + 8], 0x27f */
    if (c->zf) goto L_006b34c1; /* je 0x6b34c1 */
    c->fpu_cw = R16((uint32_t)(c->ebp + 0x8u)); fpu_sync_rounding(c); /* fldcw word ptr [ebp + 8] */
L_006b34c1:;
    c->esp = c->ebp; c->ebp = POP32(c); /* leave  */
    c->esp += 4; return; /* ret  */
}

void f_006b34d0(CPU *c) { /* FUN_100234d0 */
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

void f_006b34e5(CPU *c) { /* FUN_100234e5 */
    PREEMPT_POLL(c);
    c->edx = (uint32_t)(R32((uint32_t)(c->esp + 0x4u))); /* mov edx, dword ptr [esp + 4] */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx & (uint32_t)0x300u))); /* and edx, 0x300 */
    c->edx = (uint32_t)(logic32(c, (uint32_t)(c->edx | (uint32_t)0x7fu))); /* or edx, 0x7f */
    W16((uint32_t)(c->esp + 0x6u), (uint16_t)(((uint16_t)c->edx))); /* mov word ptr [esp + 6], dx */
    c->fpu_cw = R16((uint32_t)(c->esp + 0x6u)); fpu_sync_rounding(c); /* fldcw word ptr [esp + 6] */
    c->esp += 4; return; /* ret  */
}

void f_006b34fc(CPU *c) { /* FUN_100234fc */
    PREEMPT_POLL(c);
    (void)logic32(c, (uint32_t)(c->eax & (uint32_t)0x80000u)); /* test eax, 0x80000 */
    if (c->zf) goto L_006b3509; /* je 0x6b3509 */
    c->eax = (uint32_t)((uint32_t)0x7u); /* mov eax, 7 */
    c->esp += 4; return; /* ret  */
L_006b3509:;
    ST(0) = FPRES(c, ST(0) + RF64((uint32_t)(0x6c1630u))); /* fadd qword ptr [0x10031630] */
    c->eax = (uint32_t)((uint32_t)0x1u); /* mov eax, 1 */
    c->esp += 4; return; /* ret  */
}
