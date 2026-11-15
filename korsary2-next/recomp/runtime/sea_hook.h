#ifndef PORT_SEA_HOOK_H
#define PORT_SEA_HOOK_H
/* Opt-in fallback for this exact translated sea.dll. This is a version
   fingerprint and accidental-mismatch guard, not cryptographic authentication. */
#include "runtime.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { SEA_KNOWN_BASE=0x00c00000u, SEA_CAPS_RETURN=0x00c03ed6u,
       SEA_TEXT_RVA=0x1000u, SEA_TEXT_SIZE=0x22733u };
#define SEA_TEXT_FNV UINT64_C(0x796fad582ab24ba9)
typedef struct { uint32_t object, esp; int active; } SeaCapsProbe;

static inline uint64_t sea_text_fingerprint(void) {
    uint64_t h=UINT64_C(14695981039346656037);
    const uint8_t *p=HP(SEA_KNOWN_BASE + SEA_TEXT_RVA);
    for (size_t i=0;i<SEA_TEXT_SIZE;i++) { h ^= p[i]; h *= UINT64_C(1099511628211); }
    return h;
}

static inline SeaCapsProbe sea_caps_probe_before(CPU *c, uint32_t target) {
    SeaCapsProbe probe={0};
    /* ESI points at the sea object and its +0x6c caps is the sole argument. */
    const char *option=getenv("PORT_SEA_FALLBACK");
    if (!option || strcmp(option,"1")) return probe;
    if ((uint64_t)c->esp+4u>GUEST_SPACE || R32(c->esp)!=SEA_CAPS_RETURN) return probe;
    if (guest_module_base("MODULES/sea.dll") != SEA_KNOWN_BASE) {
        fprintf(stderr,"[sea-hook] skip: module/base mismatch\n"); return probe;
    }
    uint64_t hash=sea_text_fingerprint();
    if (hash!=SEA_TEXT_FNV) {
        fprintf(stderr,"[sea-hook] skip: relocated text fingerprint %016" PRIx64 " expected %016" PRIx64 "\n",hash,SEA_TEXT_FNV);
        return probe;
    }
    uint32_t obj=c->esi;
    if (!obj || (uint64_t)obj+0x194u>GUEST_SPACE ||
        (uint64_t)c->esp+8u>GUEST_SPACE || R32(c->esp+4)!=obj+0x6cu ||
        !c->ecx || (uint64_t)c->ecx+4u>GUEST_SPACE ||
        c->ecx!=R32(obj+0x190u) || !c->edx ||
        (uint64_t)c->edx+0x14cu>GUEST_SPACE || c->edx!=R32(c->ecx) ||
        target!=R32(c->edx+0x148u)) {
        fprintf(stderr,"[sea-hook] skip: pre-call object/argument/vtable mismatch\n"); return probe;
    }
    probe.object=obj; probe.esp=c->esp; probe.active=1;
    return probe;
}

static inline void sea_caps_probe_after(CPU *c, const SeaCapsProbe *probe) {
    if (!probe->active) return;
    if (c->esi!=probe->object || (uint64_t)probe->esp+8u>GUEST_SPACE ||
        c->esp!=probe->esp+8u) {
        fprintf(stderr,"[sea-hook] skip: post-call ESI/ESP mismatch\n"); return;
    }
    uint32_t version=R32(probe->object+0x138u);
    if (version!=0xffff0101u) {
        fprintf(stderr,"[sea-hook] skip: unexpected pixel caps %08" PRIx32 "\n",version); return;
    }
    W32(probe->object+0x138u,0);
    fprintf(stderr,"[sea-hook] enabled: sea-only pixel caps %08" PRIx32 " -> 00000000, fingerprint %016" PRIx64 "\n",version,SEA_TEXT_FNV);
}
#endif
