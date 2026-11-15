/* Recorder command test: six independent RGB565 faces/mips, ordering and RT ids. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int reject_realloc;
static void *checked_realloc(void *p,size_t n) { return reject_realloc ? NULL : realloc(p,n); }
#define PORT_CMD_REALLOC checked_realloc
#include "../host/render_rec.c"

uint8_t *g_mem;
uint8_t g_palettes[1024][1024];
int g_gpu_bc;
int g_log;
uint32_t heap_try_alloc(uint32_t n,int zero) { (void)n; (void)zero; return 0; }
double host_seconds(void) { return 0; }
uint32_t format_bpp(uint32_t fmt) { return fmt==FMT_R5G6B5?16:fmt==FMT_DXT1?4:32; }
int format_is_dxt(uint32_t fmt) { return fmt==FMT_DXT1 || fmt==FMT_DXT2 || fmt==FMT_DXT3 || fmt==FMT_DXT4 || fmt==FMT_DXT5; }
static CmdUploadTex *last;
static size_t last_size;
static CmdCopyCubeRT last_copy;
static int uploads, copies, regions, destroy_commands, fail_after_regions;
static uint64_t region_bytes;
static uint32_t next_y[14];
void gpu_exec(const CmdHdr *h) {
    if (h->type==CMD_UPLOAD_TEX) { free(last); last=malloc(h->size); assert(last); memcpy(last,h,h->size); last_size=h->size; uploads++; }
    else if (h->type==CMD_UPLOAD_TEX_REGION) {
        const CmdUploadTexRegion *r=(const CmdUploadTexRegion *)h;
        assert(h->size<=TEX_STRIPE_BYTES+sizeof *r+7);
        assert(r->face==0 && r->level<14 && r->y==next_y[r->level]);
        assert(r->rows && r->y+r->rows<=r->tex.h_[r->level]);
        const uint8_t *p=(const uint8_t *)(r+1);
        assert(p[0]==0 && p[1]==0 && p[2]==0 && p[3]==255);
        assert(p[(size_t)r->tex.w[r->level]*r->rows*4-1]==255);
        next_y[r->level]+=r->rows;
        region_bytes+=(uint64_t)r->tex.w[r->level]*r->rows*4;
        regions++;
        if (fail_after_regions && regions==fail_after_regions) { reject_realloc=1; g_cb_cap=0; }
    }
    else if (h->type==CMD_DESTROY_TEX) destroy_commands++;
    else if (h->type==CMD_COPY_CUBE_RT) { assert(h->size>=sizeof last_copy); memcpy(&last_copy,h,sizeof last_copy); copies++; }
}
static Surface surfaces[6][3];
void *com_data(uint32_t handle) {
    if (handle<1 || handle>18) return NULL;
    return &surfaces[(handle-1)/3][(handle-1)%3];
}
int main(void) {
    g_mem=calloc(1,65536); assert(g_mem);
    Device d={0}; Texture t={0};
    t.type=RT_CUBETEXTURE; t.width=t.height=4; t.format=FMT_R5G6B5; t.faces=6; t.levels=3; t.gpu_id=42; t.sent_version=0xffffffffu;
    uint32_t addr=0x100;
    for (unsigned l=0;l<3;l++) { t.lw[l]=t.lh[l]=4u>>l; t.pitch[l]=t.lw[l]*2+2; t.size[l]=t.pitch[l]*t.lh[l]; }
    for (unsigned f=0;f<6;f++) for (unsigned l=0;l<3;l++) {
        t.mem[f][l]=addr; addr+=t.size[l]+8;
        uint16_t p=(uint16_t)(((f+1)<<11)|((l+1)<<5)|f);
        for(unsigned y=0;y<t.lh[l];y++) for(unsigned x=0;x<t.lw[l];x++) memcpy(g_mem+t.mem[f][l]+y*t.pitch[l]+x*2,&p,2);
    }
    assert(sync_texture(&d,&t)); assert(uploads==1 && last->id==42 && last->faces==6 && last->levels==3 && last->fmt==TEXFMT_RGBA8);
    const uint8_t *px=(const uint8_t *)(last+1);
    for(unsigned f=0;f<6;f++) for(unsigned l=0;l<3;l++) {
        uint8_t expected[4]={(uint8_t)((f+1)*255/31),(uint8_t)((l+1)*255/63),(uint8_t)(f*255/31),255};
        for(unsigned i=0;i<t.lw[l]*t.lh[l];i++,px+=4) assert(!memcmp(px,expected,4));
    }
    assert((size_t)(px-(uint8_t *)last)<=last_size);
    assert(sync_texture(&d,&t) && uploads==1);
    t.version++; assert(sync_texture(&d,&t) && uploads==2);
    t.usage=1; t.version++; assert(sync_texture(&d,&t) && last->fmt==TEXFMT_SURF_RGBA8 && uploads==3);
    for(unsigned f=0;f<6;f++) for(unsigned l=0;l<3;l++) { surfaces[f][l].is_rt=1; surfaces[f][l].gpu_id=100+f*3+l; t.rt_surface_ids[f][l]=100+f*3+l; }
    sync_cube_render_targets(&t); assert(copies==1 && last_copy.id==42 && last_copy.levels==3);
    for(unsigned f=0;f<6;f++) for(unsigned l=0;l<3;l++) assert(last_copy.surface[f][l]==100+f*3+l);
    int old=uploads; t.version++; t.mem[5][2]=0; assert(!sync_texture(&d,&t) && uploads==old);
    t.mem[5][2]=addr; t.levels=15; assert(!sync_texture(&d,&t) && uploads==old);
    t.levels=1; t.faces=1; assert(!sync_texture(&d,&t) && uploads==old);
    Texture flat={0}; flat.type=RT_TEXTURE; flat.width=flat.height=4; flat.faces=1; flat.levels=1;
    flat.format=FMT_R5G6B5; flat.gpu_id=43; flat.sent_version=0xffffffffu;
    flat.lw[0]=flat.lh[0]=4; flat.pitch[0]=t.pitch[0]; flat.mem[0][0]=t.mem[0][0];
    assert(sync_texture(&d,&flat) && last->id==43 && last->faces==1 && last->fmt==TEXFMT_RGBA8);
    Texture blocks={0}; blocks.type=RT_CUBETEXTURE; blocks.width=blocks.height=4; blocks.faces=6; blocks.levels=1;
    blocks.format=FMT_DXT1; blocks.gpu_id=44; blocks.sent_version=0xffffffffu;
    blocks.lw[0]=blocks.lh[0]=4; blocks.pitch[0]=8; g_gpu_bc=1;
    for(unsigned f=0;f<6;f++) { blocks.mem[f][0]=0x800+f*16; memset(g_mem+blocks.mem[f][0],f+1,8); }
    assert(sync_texture(&d,&blocks) && last->id==44 && last->faces==6 && last->fmt==TEXFMT_BC1);
    px=(const uint8_t *)(last+1);
    for(unsigned f=0;f<6;f++) for(unsigned i=0;i<8;i++) assert(*px++==f+1);
    free(g_mem); g_mem=calloc(1,140u<<20); assert(g_mem);
    for (unsigned pass=0;pass<2;pass++) {
        Texture big={0}; big.type=RT_TEXTURE; big.faces=1; big.width=big.height=pass?8192:4096;
        big.levels=pass?1:13; big.format=FMT_R5G6B5; big.gpu_id=50+pass; big.sent_version=0xffffffffu;
        uint32_t offset=4096; uint64_t expected=0;
        for (unsigned l=0;l<big.levels;l++) {
            big.lw[l]=big.lh[l]=big.width>>l; if (!big.lw[l]) big.lw[l]=big.lh[l]=1;
            big.pitch[l]=big.lw[l]*2; big.mem[0][l]=offset; offset+=big.pitch[l]*big.lh[l];
            expected+=(uint64_t)big.lw[l]*big.lh[l]*4;
        }
        assert(offset<(140u<<20)); regions=0; region_bytes=0; memset(next_y,0,sizeof next_y);
        assert(sync_texture(&d,&big) && big.sent_version==big.version);
        assert(regions>1 && region_bytes==expected);
        for (unsigned l=0;l<big.levels;l++) assert(next_y[l]==big.lh[l]);
        free(g_cb); g_cb=NULL; g_cb_len=g_cb_cap=0;
        big.version++; reject_realloc=1;
        assert(!sync_texture(&d,&big) && big.sent_version!=big.version);
        reject_realloc=0;
        if (!pass) {
            /* A first upload can fail after two GPU commands; destruction must
               still be sent although this version was never fully uploaded. */
            Texture partial=big; partial.sent_version=0xffffffffu;
            regions=0; memset(next_y,0,sizeof next_y); fail_after_regions=2;
            assert(!sync_texture(&d,&partial) && regions==2 && partial.sent_version==0xffffffffu);
            fail_after_regions=0; reject_realloc=0;
            int old_destroy=destroy_commands; rec_destroy_texture_impl(&partial);
            assert(destroy_commands==old_destroy+1);
        }
    }
    free(g_cb); g_cb=NULL; g_cb_len=g_cb_cap=0; reject_realloc=1;
    Surface rt={.is_rt=1,.mem=0x100,.width=1,.height=1,.pitch=4};
    assert(!rec_readback_impl(&d,&rt)); reject_realloc=0;
    free(last); free(g_mem); free(g_cb); puts("cube recorder face/mip packing, versions, RT ids, BC and rejection PASS");
}
