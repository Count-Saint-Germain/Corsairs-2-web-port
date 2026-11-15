/* Direct3D entry points: CPU locks and UpdateTexture synchronize existing RT faces. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/d3d8.c"
uint8_t *g_mem;
double host_seconds(void) { return 0; }
uint32_t heap_alloc(uint32_t n,int zero) { (void)n; (void)zero; abort(); }
static Texture src,dst;
static Device device;
static Surface rt, source_surface, target_surface;
void *com_data(uint32_t h) { return h==1?&src:h==2?&dst:h==3?&rt:h==4?&source_surface:h==5?&device:h==6?&target_surface:NULL; }
static int reads,writes,fail_id,fail_read,fill_read;
static unsigned seen[100];
static int readback(Device *d,Surface *s) { assert(d==g_device && s->gpu_id && s->is_rt); reads++; if (fail_read) return 0; if (fill_read) memset(g_mem+s->mem,0x55,8); return 1; }
static int upload(Device *d,Surface *s) { assert(d==g_device && s->gpu_id<100 && s->is_rt); writes++; seen[s->gpu_id]++; return s->gpu_id!=(uint32_t)fail_id; }
static void args(CPU *c,uint32_t a,uint32_t b,uint32_t d,uint32_t e,uint32_t f,uint32_t g) {
    memset(c,0,sizeof *c); c->esp=0x100; W32(0x104,a); W32(0x108,b); W32(0x10c,d); W32(0x110,e); W32(0x114,f); W32(0x118,g);
}
int main(void) {
    g_mem=calloc(1,65536); assert(g_mem);
    RenderBackend backend={0}; backend.readback=readback; backend.upload_surface=upload; g_render=&backend;
    g_device=&device;
    src.type=dst.type=RT_CUBETEXTURE; src.faces=dst.faces=6; src.levels=dst.levels=1;
    src.format=dst.format=FMT_R5G6B5; dst.pitch[0]=4; dst.mem[2][0]=0x2000;
    dst.usage=1; dst.lw[0]=dst.lh[0]=2; dst.rt_surface_ids[2][0]=77;
    rt.is_rt=1; dst.surfaces[2][0]=0; /* parent-owned GPU storage, no COM surface */
    CPU c; args(&c,2,2,0,0x500,0,0); cube_LockRect(&c);
    assert(c.eax==S_OK && reads==1 && R32(0x500)==4 && R32(0x504)==0x2000);
    args(&c,2,2,0,0,0,0); cube_UnlockRect(&c);
    assert(c.eax==S_OK && writes==1 && dst.version==1);
    args(&c,2,6,0,0,0,0); cube_UnlockRect(&c); assert(c.eax==D3DERR_INVALIDCALL && writes==1);
    for(unsigned f=0;f<6;f++) { src.mem[f][0]=0x3000+f*32; dst.mem[f][0]=0x4000+f*32; src.size[0]=dst.size[0]=8; memset(HP(src.mem[f][0]),f+1,8); }
    args(&c,0,1,2,0,0,0); dev_UpdateTexture(&c);
    assert(c.eax==S_OK && dst.version==2 && writes==2);
    for(unsigned f=0;f<6;f++) for(unsigned i=0;i<8;i++) assert(g_mem[dst.mem[f][0]+i]==f+1);
    /* A multi-face update must retain pending data for the failed face and
       every later face, even when a prior face uploaded successfully. */
    dst.rt_surface_ids[0][0]=78; dst.rt_surface_ids[4][0]=79;
    fail_id=77; args(&c,0,1,2,0,0,0); dev_UpdateTexture(&c);
    assert(c.eax==0x8007000Eu && dst.version==3);
    assert(!dst.rt_cpu_dirty[0][0] && dst.rt_cpu_dirty[2][0] && dst.rt_cpu_dirty[4][0]);
    int old_reads=reads; args(&c,2,2,0,0x500,0,0); cube_LockRect(&c);
    assert(c.eax==0x8007000Eu && reads==old_reads && dst.rt_cpu_dirty[2][0] && dst.rt_cpu_dirty[4][0]);
    fail_id=0; assert(d3d_sync_texture_rt(&device,&dst));
    assert(!dst.rt_cpu_dirty[2][0] && !dst.rt_cpu_dirty[4][0] && seen[78]==1 && seen[79]==1);
    fail_id=77; args(&c,2,2,0,0,0,0); cube_UnlockRect(&c);
    assert(c.eax==0x8007000Eu && dst.rt_cpu_dirty[2][0]);
    fail_id=0; assert(d3d_sync_texture_rt(&device,&dst) && !dst.rt_cpu_dirty[2][0]);
    /* Surface COM wrappers share dirty state with their parent, even across
       failed Unlock and CopyRects before their next GPU use. */
    rt=(Surface){.is_rt=1,.gpu_id=77,.format=FMT_R5G6B5,.width=2,.height=2,.pitch=4,
                 .mem=dst.mem[2][0],.container=2,.face=2,.level=0};
    fail_id=77; args(&c,3,0,0,0,0,0); surf_UnlockRect(&c);
    assert(c.eax==0x8007000Eu && dst.rt_cpu_dirty[2][0]);
    old_reads=reads; args(&c,3,0x500,0,0,0,0); surf_LockRect(&c);
    assert(c.eax==0x8007000Eu && reads==old_reads);
    fail_id=0; assert(d3d_sync_surface(&device,&rt) && !dst.rt_cpu_dirty[2][0]);
    source_surface=(Surface){.format=FMT_R5G6B5,.width=2,.height=2,.pitch=4,.mem=0x6000};
    memset(g_mem+0x6000,0x6a,8);
    fail_id=77; args(&c,5,4,0,0,3,0); dev_CopyRects(&c);
    assert(c.eax==0x8007000Eu && dst.rt_cpu_dirty[2][0] && g_mem[dst.mem[2][0]]==0x6a);
    fail_id=0; assert(d3d_sync_surface(&device,&rt) && !dst.rt_cpu_dirty[2][0]);
    /* Partial copy must read GPU destination before patching CPU bytes. */
    W32(0x700,0); W32(0x704,0); W32(0x708,1); W32(0x70c,1);
    fill_read=1; args(&c,5,4,0x700,1,3,0); dev_CopyRects(&c);
    assert(c.eax==S_OK && g_mem[dst.mem[2][0]]==0x6a && g_mem[dst.mem[2][0]+2]==0x55 && g_mem[dst.mem[2][0]+7]==0x55);
    int before=writes; fail_read=1; g_mem[dst.mem[2][0]]=0x42;
    args(&c,5,4,0x700,1,3,0); dev_CopyRects(&c);
    assert(c.eax==0x8007000Eu && writes==before && g_mem[dst.mem[2][0]]==0x42);
    args(&c,2,2,0,0x500,0,0); cube_LockRect(&c); assert(c.eax==0x8007000Eu);
    args(&c,2,0,0x500,0,0,0); tx_LockRect(&c); assert(c.eax==0x8007000Eu);
    args(&c,3,0x500,0,0,0,0); surf_LockRect(&c); assert(c.eax==0x8007000Eu);
    fail_read=0; fill_read=0;
    old_reads=reads; args(&c,5,3,0,0,3,0); dev_CopyRects(&c);
    assert(c.eax==S_OK && reads==old_reads+1);
    /* In-place overlapping copies fail before readback, upload or mutation;
       this policy uses no snapshot allocation and cannot fail halfway. */
    source_surface.width=source_surface.height=4; source_surface.pitch=8;
    uint8_t original[32]; for (unsigned i=0;i<32;i++) original[i]=(uint8_t)i;
    memcpy(g_mem+0x6000,original,32); old_reads=reads; before=writes;
    W32(0x700,0); W32(0x704,0); W32(0x708,3); W32(0x70c,4);
    W32(0x780,1); W32(0x784,0);
    args(&c,5,4,0x700,1,4,0x780); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6000,original,32) && reads==old_reads && writes==before);
    W32(0x708,4); W32(0x70c,3); W32(0x780,0); W32(0x784,1);
    args(&c,5,4,0x700,1,4,0x780); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6000,original,32) && reads==old_reads && writes==before);
    /* Cross-rectangle dependencies are rejected too. */
    W32(0x708,1); W32(0x70c,1); W32(0x710,2); W32(0x714,0); W32(0x718,3); W32(0x71c,1);
    W32(0x780,2); W32(0x784,0); W32(0x788,3); W32(0x78c,0);
    args(&c,5,4,0x700,2,4,0x780); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6000,original,32));
    W32(0x780,1); W32(0x784,1); args(&c,5,4,0x700,1,4,0x780); dev_CopyRects(&c);
    assert(c.eax==S_OK && g_mem[0x6000+10]==original[0] && g_mem[0x6000+11]==original[1]);
    /* Two independent DXT1 blocks must use the same eight-byte block size. */
    source_surface=(Surface){.format=FMT_DXT1,.width=8,.height=8,.pitch=16,.mem=0x6000};
    target_surface=(Surface){.format=FMT_DXT1,.width=8,.height=8,.pitch=16,.mem=0x6100};
    for (unsigned i=0;i<32;i++) g_mem[0x6000+i]=(uint8_t)(i+1);
    memset(g_mem+0x6100,0xee,48);
    W32(0x700,0); W32(0x704,0); W32(0x708,4); W32(0x70c,4);
    W32(0x710,4); W32(0x714,4); W32(0x718,8); W32(0x71c,8);
    W32(0x780,0); W32(0x784,0); W32(0x788,4); W32(0x78c,4);
    args(&c,5,4,0x700,2,6,0x780); dev_CopyRects(&c);
    assert(c.eax==S_OK && !memcmp(g_mem+0x6100,g_mem+0x6000,8));
    for (unsigned i=8;i<24;i++) assert(g_mem[0x6100+i]==0xee);
    assert(!memcmp(g_mem+0x6118,g_mem+0x6018,8));
    for (unsigned i=32;i<48;i++) assert(g_mem[0x6100+i]==0xee);
    uint8_t bc_before[32]; memcpy(bc_before,g_mem+0x6100,32);
    /* In pixels this fits, but rounding x=3..5 spans two blocks and
       destination block x=1 has only one block remaining. */
    W32(0x700,3); W32(0x704,0); W32(0x708,5); W32(0x70c,4);
    W32(0x780,4); W32(0x784,0);
    args(&c,5,4,0x700,1,6,0x780); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6100,bc_before,32));
    /* Equal bits per pixel is insufficient: BC3 blocks and A8 rows have
       different layout. Both directions fail before readback or mutation. */
    source_surface=(Surface){.format=FMT_A8,.width=8,.height=8,.pitch=8,.mem=0x6000};
    target_surface=(Surface){.format=FMT_DXT3,.width=8,.height=8,.pitch=32,.mem=0x6100};
    memset(g_mem+0x6000,0x31,80); memset(g_mem+0x6100,0x79,80);
    uint8_t a_before[80],b_before[80]; memcpy(a_before,g_mem+0x6000,80); memcpy(b_before,g_mem+0x6100,80);
    old_reads=reads; before=writes;
    args(&c,5,4,0,0,6,0); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6100,b_before,80));
    args(&c,5,6,0,0,4,0); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6000,a_before,80));
    assert(reads==old_reads && writes==before);
    /* Bounds are computed in 64-bit before indexing guest arrays. */
    assert(copy_arrays_valid(1,(uint32_t)(GUEST_SPACE-16),0));
    assert(copy_arrays_valid(1,0,(uint32_t)(GUEST_SPACE-8)));
    assert(!copy_arrays_valid(1,(uint32_t)(GUEST_SPACE-15),0));
    assert(!copy_arrays_valid(1,0,(uint32_t)(GUEST_SPACE-7)));
    assert(!copy_arrays_valid(0xffffffffu,0x700,0));
    source_surface.format=target_surface.format=FMT_A8;
    args(&c,5,4,(uint32_t)(GUEST_SPACE-8),1,6,0); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6100,b_before,80));
    args(&c,5,4,0,1,6,(uint32_t)(GUEST_SPACE-4)); dev_CopyRects(&c);
    assert(c.eax==D3DERR_INVALIDCALL && !memcmp(g_mem+0x6100,b_before,80));
    src.faces=1; int old_writes=writes; args(&c,0,1,2,0,0,0); dev_UpdateTexture(&c);
    assert(dst.version==8 && writes==old_writes);
    free(g_mem); puts("cube LockRect/UnlockRect and UpdateTexture RT coherence PASS");
}
