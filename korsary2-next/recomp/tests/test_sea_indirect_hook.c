#define _POSIX_C_SOURCE 200809L
/* Integration test uses the actual indirect dispatcher and user's sea.dll.
   No game-derived bytes are included in this test or published. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../runtime/sea_hook.h"

static int calls, dynamic_calls, imported, bad_esp, bad_esi, bad_caps;
static uint32_t dynamic_target;
int dyncode_contains(uint32_t target) { return target==dynamic_target && target!=0; }
void interp_call(CPU *c, uint32_t target) {
    assert(target==dynamic_target); dynamic_calls++;
    uint32_t dst=R32(c->esp+4); W32(dst+204,0xffff0101u); c->esp+=8;
}
static void caps_service(CPU *c) {
    calls++;
    uint32_t dst=R32(c->esp+4);
    W32(dst+204,bad_caps ? 0xffff0104u : 0xffff0101u);
    c->eax=0; c->esp+=bad_esp ? 4 : 8;
    if (bad_esi) c->esi^=1;
}
static void import_service(CPU *c) {
    assert(g_import_target>=IMPORT_BASE); imported++; c->esp+=4;
}
static CPU setup(uint32_t object, uint32_t target, uint32_t ret) {
    CPU c; memset(&c,0,sizeof c);
    c.esp=0x10000; c.esi=object; c.ecx=0x30000; c.edx=0x40000;
    W32(c.esp,ret); W32(c.esp+4,object+0x6c);
    W32(object+0x190,c.ecx); W32(c.ecx,c.edx); W32(c.edx+0x148,target);
    W32(object+0x138,0xabcdef01); W32(0x50000+204,0xffff0101);
    return c;
}
int main(int argc,char **argv) {
    assert(argc==2 || (argc==3 && !strcmp(argv[2],"--trace")));
    /* Node's process environment is not automatically the Emscripten libc
       environment; configure the guest environment explicitly. */
    if (argc==3) assert(!setenv("PORT_TRACE_CALL","501000",1));
    else assert(!unsetenv("PORT_TRACE_CALL"));
    g_mem=calloc(1,0xd00000); assert(g_mem);
    LoadedImage image;
    assert(!load_image(argv[1],SEA_KNOWN_BASE,&image));
    module_set_name(image.image_base,"MODULES/sea.dll");
    assert(sea_text_fingerprint()==SEA_TEXT_FNV);
    const uint32_t obj=0x20000, target=0x501000;
    register_function(target,caps_service);

    unsetenv("PORT_SEA_FALLBACK");
    CPU c=setup(obj,target,SEA_CAPS_RETURN); call_indirect(&c,target);
    assert(R32(obj+0x138)==0xffff0101 && c.esp==0x10008 && calls==1);
    setenv("PORT_SEA_FALLBACK","1",1);
    c=setup(obj,target,SEA_CAPS_RETURN); call_indirect(&c,target);
    assert(R32(obj+0x138)==0 && R32(0x50000+204)==0xffff0101 && calls==2);

    /* Other call sites and target clients retain advertised caps. */
    c=setup(obj,target,0x00c04000); call_indirect(&c,target);
    assert(R32(obj+0x138)==0xffff0101 && R32(0x50000+204)==0xffff0101);
    c=setup(obj,target,SEA_CAPS_RETURN+0x10000); call_indirect(&c,target);
    assert(R32(obj+0x138)==0xffff0101); /* same low 16 bits, different caller */
    c=setup(obj,target,SEA_CAPS_RETURN); W32(c.edx+0x148,target+4);
    call_indirect(&c,target); assert(R32(obj+0x138)==0xffff0101);
    module_set_name(image.image_base,"MODULES/other.dll");
    c=setup(obj,target,SEA_CAPS_RETURN); call_indirect(&c,target);
    assert(R32(obj+0x138)==0xffff0101);
    module_set_name(image.image_base,"MODULES/sea.dll");
    c=setup(obj,target,SEA_CAPS_RETURN); W32(c.esp+4,obj+0x70);
    call_indirect(&c,target); assert(R32(obj+0x138)==0xabcdef01);
    c=setup(obj,target,SEA_CAPS_RETURN); W32(obj+0x190,0x31000);
    call_indirect(&c,target); assert(R32(obj+0x138)==0xffff0101);
    c=setup(obj,target,SEA_CAPS_RETURN); W8(SEA_KNOWN_BASE+SEA_TEXT_RVA,R8(SEA_KNOWN_BASE+SEA_TEXT_RVA)^1);
    call_indirect(&c,target); assert(R32(obj+0x138)==0xffff0101);
    W8(SEA_KNOWN_BASE+SEA_TEXT_RVA,R8(SEA_KNOWN_BASE+SEA_TEXT_RVA)^1);
    c=setup(obj,target,SEA_CAPS_RETURN); bad_esi=1; call_indirect(&c,target); bad_esi=0;
    assert(R32(obj+0x138)==0xffff0101);
    c=setup(obj,target,SEA_CAPS_RETURN); bad_esp=1; call_indirect(&c,target); bad_esp=0;
    assert(R32(obj+0x138)==0xffff0101);
    c=setup(obj,target,SEA_CAPS_RETURN); bad_caps=1; call_indirect(&c,target); bad_caps=0;
    assert(R32(obj+0x138)==0xffff0104);

    /* Existing direct dispatch, tail jump, dynamic code and import bookkeeping. */
    c=setup(obj,target,0x00400100); jump_indirect(&c,target,0x400090);
    assert(c.esp==0x10008 && R32(obj+0x138)==0xffff0101);
    dynamic_target=0x502000; c=setup(obj,dynamic_target,0x00400100);
    call_indirect(&c,dynamic_target); assert(dynamic_calls==1 && c.esp==0x10008);
    c=setup(obj,dynamic_target,SEA_CAPS_RETURN); call_indirect(&c,dynamic_target);
    assert(dynamic_calls==2 && c.esp==0x10008 && R32(obj+0x138)==0);
    uint32_t import=add_dynamic_import("TEST.DLL!CAPS",import_service);
    c=setup(obj,import,0x00400100); call_indirect(&c,import);
    assert(imported==1 && c.esp==0x10004 && g_import_target==import);
    puts("sea indirect hook: guards, caps isolation and indirect paths OK");
    free(g_mem);
    return 0;
}
