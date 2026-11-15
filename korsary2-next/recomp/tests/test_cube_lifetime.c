/* Real D3D resource/target/state-block paths with a deterministic mock COM registry. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/d3d8.c"
#ifdef USE_REAL_COM
#include "../host/com.c"
#endif
uint8_t *g_mem;
#ifndef USE_REAL_COM
int g_log_d3d;
#endif
double host_seconds(void) { return 0; }
#ifdef USE_REAL_COM
__thread uint32_t g_import_target;
uint32_t add_dynamic_import(const char *name,GuestFn fn) { static uint32_t slot; (void)name;(void)fn; return IMPORT_BASE+16*slot++; }
void guest_trap(CPU *c,uint32_t addr,const char *why) { (void)c;(void)addr;(void)why; abort(); }
#else
static ComObj objects[256]; static unsigned next_handle=1;
uint32_t com_new(ComInterface *iface,int type,void *data) {
    assert(next_handle<256); unsigned h=next_handle++;
    objects[h]=(ComObj){.iface=iface,.refs=1,.type=type,.data=data,.guest=h}; return h;
}
ComObj *com_get(uint32_t h) { return h && h<256 && objects[h].guest ? &objects[h] : NULL; }
void *com_data(uint32_t h) { ComObj *o=com_get(h); return o?o->data:NULL; }
uint32_t com_retain_handle(uint32_t h) { ComObj *o=com_get(h); return o?(uint32_t)++o->refs:0; }
uint32_t com_release_handle(uint32_t h) {
    ComObj *o=com_get(h); if(!o) return 0; int n=--o->refs;
    if(n<=0 && o->iface->destroy) { o->refs=0; o->iface->destroy(o->data); o->data=NULL; o->guest=0; }
    return n>0?(uint32_t)n:0;
}
void com_QueryInterface(CPU *c) { (void)c; } void com_AddRef(CPU *c) { (void)c; } void com_Release(CPU *c) { (void)c; }
#endif
static uint32_t next_mem=0x10000; static int allocations, freed_mem, fail_after=-1;
uint32_t heap_alloc(uint32_t n,int zero) { (void)zero; assert(n<0x10000 && next_mem+n<0xf0000); uint32_t r=next_mem; next_mem+=n+8; return r; }
uint32_t heap_try_alloc(uint32_t n,int zero) {
    if (fail_after>=0 && allocations++>=fail_after) return 0;
    return heap_alloc(n,zero);
}
void heap_free(uint32_t p) { if(p) freed_mem++; }
static int tex_destroys,surf_destroys,initial_uploads;
static int fail_upload;
static uint32_t initial_id; static uint8_t initial_pixel;
static int init_surface(Device *d, Surface *s) {
    assert(d==g_device && s->is_rt && s->mem);
    initial_uploads++; initial_id=s->gpu_id; initial_pixel=g_mem[s->mem]; return !fail_upload;
}
static void destroy_tex(Texture *t) { assert(t); tex_destroys++; }
static void destroy_surf(Surface *s) { assert(s); surf_destroys++; }
static void args(CPU *c,uint32_t a,uint32_t b,uint32_t d,uint32_t e,uint32_t f,uint32_t g,uint32_t h,uint32_t i) {
    memset(c,0,sizeof *c); c->esp=0x100; W32(0x104,a); W32(0x108,b); W32(0x10c,d); W32(0x110,e);
    W32(0x114,f); W32(0x118,g); W32(0x11c,h); W32(0x120,i);
}
int main(void) {
    g_mem=calloc(1,0x100000); assert(g_mem);
    RenderBackend backend={0}; backend.destroy_texture=destroy_tex; backend.destroy_surface=destroy_surf;
    backend.upload_surface=init_surface; g_render=&backend;
    Device device={0}; g_device=&device;
    assert(!create_texture(0,4,1,0,FMT_R5G6B5,0,0));
    assert(!create_texture(16384,16384,0,0,FMT_R5G6B5,0,1));
    CPU c; args(&c,0,16384,0,0,FMT_R5G6B5,0,0x600,0); dev_CreateCubeTexture(&c);
    assert(c.eax==D3DERR_INVALIDCALL && R32(0x600)==0);
    args(&c,0,16384,1,1,0,FMT_R5G6B5,0,0x604); dev_CreateTexture(&c);
    assert(c.eax==D3DERR_INVALIDCALL && R32(0x604)==0);
    fail_after=3; allocations=0;
    args(&c,0,4,1,0,FMT_R5G6B5,0,0x600,0); dev_CreateCubeTexture(&c);
    assert(c.eax==0x8007000Eu && R32(0x600)==0 && freed_mem==3);
    fail_after=-1;
    uint32_t tex=create_texture(4,4,0,1,FMT_R5G6B5,0,1); assert(tex);
    Texture *t=com_data(tex); assert(t->levels==3 && com_get(tex)->refs==1);
    uint32_t surf=texture_surface(tex,t,2,0); assert(surf && com_get(surf)->refs==1 && com_get(tex)->refs==2);
    assert(texture_surface(tex,t,2,0)==surf && com_get(surf)->refs==2 && com_get(tex)->refs==2);
    assert(com_release_handle(tex)==1 && com_data(tex)==t);
    assert(com_release_handle(surf)==1 && com_data(tex)==t);
    assert(com_release_handle(surf)==0 && !com_get(surf) && !com_get(tex) && tex_destroys==1 && surf_destroys==1);

    /* A transient surface must not destroy parent-owned GPU face storage. */
    tex=create_texture(4,4,1,1,FMT_R5G6B5,0,1); t=com_data(tex);
    /* A failed initial upload cannot expose a zeroed render target; retry works. */
    fail_upload=1; assert(!texture_surface(tex,t,1,0));
    assert(!t->surfaces[1][0] && !t->rt_surface_ids[1][0]);
    fail_upload=0;
    /* CPU write precedes first GetSurface; untouched target pixels must retain it. */
    g_mem[t->mem[2][0]]=0x7b; int before_upload=initial_uploads;
    surf=texture_surface(tex,t,2,0); uint32_t gpu_id=((Surface *)com_data(surf))->gpu_id;
    assert(t->rt_surface_ids[2][0]==gpu_id && initial_uploads==before_upload+1 && initial_id==gpu_id && initial_pixel==0x7b);
    int before_surf=surf_destroys;
    com_release_handle(surf); assert(!com_get(surf) && t->surfaces[2][0]==0 && t->rt_surface_ids[2][0]==gpu_id && surf_destroys==before_surf);
    surf=texture_surface(tex,t,2,0); assert(((Surface *)com_data(surf))->gpu_id==gpu_id);
    assert(initial_uploads==before_upload+1); /* recreation must not overwrite later GPU drawing */
    com_release_handle(surf); assert(surf_destroys==before_surf);
    com_release_handle(tex); assert(surf_destroys==before_surf+1 && !com_get(tex));
    /* The same ownership applies to ordinary 2D render-target textures. */
    tex=create_texture(4,4,1,1,FMT_R5G6B5,0,0); t=com_data(tex);
    surf=texture_surface(tex,t,0,0); gpu_id=((Surface *)com_data(surf))->gpu_id;
    before_surf=surf_destroys; com_release_handle(surf);
    assert(t->rt_surface_ids[0][0]==gpu_id && !t->surfaces[0][0] && surf_destroys==before_surf);
    surf=texture_surface(tex,t,0,0); assert(((Surface *)com_data(surf))->gpu_id==gpu_id);
    com_release_handle(surf); com_release_handle(tex); assert(surf_destroys==before_surf+1);
    tex_destroys=1; surf_destroys=1; /* reset counters for the scenarios below */

    ComInterface device_iface={0}; uint32_t devh=com_new(&device_iface,RT_DEVICE,&device);
    uint32_t t1=create_texture(4,4,1,0,FMT_R5G6B5,0,1); assert(t1);
    args(&c,devh,3,t1,0,0,0,0,0); dev_SetTexture(&c); assert(c.eax==S_OK && com_get(t1)->refs==2);
    args(&c,devh,3,t1,0,0,0,0,0); dev_SetTexture(&c); assert(com_get(t1)->refs==2);
    com_release_handle(t1); assert(com_get(t1)->refs==1);
    uint32_t block=new_block(&device); assert(block && com_get(t1)->refs==2);
    args(&c,devh,3,0,0,0,0,0,0); dev_SetTexture(&c); assert(com_get(t1)->refs==1);
    args(&c,devh,block,0,0,0,0,0,0); dev_ApplyStateBlock(&c); assert(com_get(t1)->refs==2 && device.st.texture[3]==t1);
    args(&c,devh,block,0,0,0,0,0,0); dev_CaptureStateBlock(&c); assert(com_get(t1)->refs==2);
    args(&c,devh,block,0,0,0,0,0,0); dev_DeleteStateBlock(&c); assert(com_get(t1)->refs==1);
    args(&c,devh,0x800,0,0,0,0,0,0); dev_Reset(&c); assert(com_get(t1)->refs==1);
    args(&c,devh,3,0,0,0,0,0,0); dev_SetTexture(&c); assert(!com_get(t1) && tex_destroys==2);
    args(&c,devh,3,surf,0,0,0,0,0); dev_SetTexture(&c); assert(c.eax==D3DERR_INVALIDCALL);

    tex=create_texture(4,4,1,1,FMT_R5G6B5,0,1); t=com_data(tex);
    surf=texture_surface(tex,t,0,0);
    args(&c,devh,surf,0,0,0,0,0,0); dev_SetRenderTarget(&c); assert(com_get(surf)->refs==2);
    com_release_handle(surf); com_release_handle(tex); assert(com_get(surf) && com_get(tex));
    uint32_t alternate=new_surface(FMT_R5G6B5,4,4,1,0,0);
    args(&c,devh,alternate,0,0,0,0,0,0); dev_SetRenderTarget(&c);
    assert(!com_get(surf) && !com_get(tex) && tex_destroys==3 && surf_destroys==2);
    com_release_handle(alternate); args(&c,devh,0,0,0,0,0,0,0); dev_SetRenderTarget(&c);
    assert(device.st.render_target==alternate && com_get(alternate)); /* NULL leaves colour unchanged */

    /* One texture bound on multiple stages survives state-block capture/apply. */
    uint32_t shared=create_texture(4,4,1,0,FMT_R5G6B5,0,1);
    args(&c,devh,0,shared,0,0,0,0,0); dev_SetTexture(&c);
    args(&c,devh,5,shared,0,0,0,0,0); dev_SetTexture(&c);
    assert(com_get(shared)->refs==3); com_release_handle(shared); assert(com_get(shared)->refs==2);
    block=new_block(&device); assert(com_get(shared)->refs==4);
    args(&c,devh,0,0,0,0,0,0,0); dev_SetTexture(&c);
    args(&c,devh,5,0,0,0,0,0,0); dev_SetTexture(&c); assert(com_get(shared)->refs==2);
    args(&c,devh,block,0,0,0,0,0,0); dev_ApplyStateBlock(&c); assert(com_get(shared)->refs==4);
    args(&c,devh,block,0,0,0,0,0,0); dev_CaptureStateBlock(&c); assert(com_get(shared)->refs==4);
    args(&c,devh,block,0,0,0,0,0,0); dev_DeleteStateBlock(&c); assert(com_get(shared)->refs==2);
    args(&c,devh,0,0,0,0,0,0,0); dev_SetTexture(&c);
    args(&c,devh,5,0,0,0,0,0,0); dev_SetTexture(&c); assert(!com_get(shared));
    free(g_mem); puts("cube lifetime: mip guard, parent/surface, device, state blocks and reset PASS");
}
