/* Actual COM registry: host retain/release, nested destruction and singleton. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/d3d8.h"
#include "../host/com.c"
uint8_t *g_mem;
__thread uint32_t g_import_target;
static uint32_t next_mem=0x1000; static int frees, destroys;
uint32_t heap_alloc(uint32_t n,int zero) { (void)zero; assert(next_mem+n<0xf000); uint32_t p=next_mem; next_mem+=n+16; return p; }
void heap_free(uint32_t p) { assert(p); frees++; }
uint32_t add_dynamic_import(const char *name,GuestFn fn) { static uint32_t slot; (void)name; assert(fn); return IMPORT_BASE+16*slot++; }
void guest_trap(CPU *c,uint32_t addr,const char *why) { (void)c;(void)addr;(void)why; abort(); }
typedef struct { uint32_t parent; } Data;
static void destroy(void *v) { Data *d=v; destroys++; uint32_t parent=d->parent; free(d); if(parent) com_release_handle(parent); }
static const ComMethod methods[]={{"Release",0,NULL}};
int main(void) {
    g_mem=calloc(1,0x10000); assert(g_mem);
    ComInterface iface={"test",methods,1,0,destroy};
    Data *pd=calloc(1,sizeof *pd), *cd=calloc(1,sizeof *cd); assert(pd&&cd);
    uint32_t parent=com_new(&iface,RT_TEXTURE,pd); cd->parent=parent;
    assert(com_retain_handle(parent)==2);
    uint32_t child=com_new(&iface,RT_SURFACE,cd);
    assert(com_release_handle(parent)==1 && com_get(parent));
    assert(com_release_handle(child)==0 && !com_get(child) && !com_get(parent));
    assert(destroys==2 && frees==2 && !com_release_handle(child));
    ComInterface singleton={"single",methods,1,0,NULL};
    uint32_t single=com_new(&singleton,RT_DEVICE,NULL); assert(com_release_handle(single)==0 && com_get(single));
    assert(com_retain_handle(single)==1);
    CPU c={0}; c.esp=0x200; W32(0x204,single); com_Release(&c);
    assert(c.eax==0 && c.esp==0x208 && com_get(single));
    free(g_mem); puts("COM ownership: retained parent, nested destruction, singleton and guest Release PASS");
}
