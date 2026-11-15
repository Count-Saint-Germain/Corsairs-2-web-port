/* Exercise the actual executor's RT-cube copy command with a recording WebGPU shim. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#define __EMSCRIPTEN__ 1
#include "../host/render_wgpu.c"
uint8_t *g_mem;
static int event, ends, releases, copies, begins, writes;
static unsigned expected_layer, expected_mip, expected_y, expected_rows;
static uint8_t mapped_bytes[256]; static int unmaps;
const void *wgpuBufferGetConstMappedRange(WGPUBuffer b,size_t off,size_t size) { assert(b && !off && size<=sizeof mapped_bytes); return mapped_bytes; }
void wgpuBufferUnmap(WGPUBuffer b) { assert(b); unmaps++; }
void wgpuBufferDestroy(WGPUBuffer b) { assert(b); }
void wgpuBufferRelease(WGPUBuffer b) { assert(b); }
static unsigned layers[12], mips[12], widths[12];
void wgpuQueueWriteTexture(WGPUQueue q,const WGPUTexelCopyTextureInfo *dst,const void *data,size_t n,
                           const WGPUTexelCopyBufferLayout *layout,const WGPUExtent3D *extent) {
    (void)q; assert(dst->texture && dst->origin.z==expected_layer && dst->mipLevel==expected_mip);
    assert(dst->origin.y==expected_y && extent->height==expected_rows && extent->depthOrArrayLayers==1);
    assert(layout->bytesPerRow==extent->width*4 && n==(size_t)extent->width*extent->height*4);
    const uint8_t *p=data; assert(p[0]==32 && p[1]==64 && p[2]==128 && p[3]==255); writes++;
}
void wgpuRenderPassEncoderEnd(WGPURenderPassEncoder p) { assert(p && event==0); event=1; ends++; }
void wgpuRenderPassEncoderRelease(WGPURenderPassEncoder p) { assert(p && event==1); event=2; releases++; }
WGPUCommandEncoder wgpuDeviceCreateCommandEncoder(WGPUDevice d,const WGPUCommandEncoderDescriptor *desc) {
    (void)d; (void)desc; assert(event==2 || event==0); return (WGPUCommandEncoder)(uintptr_t)0x10;
}
void wgpuCommandEncoderCopyTextureToTexture(WGPUCommandEncoder e,const WGPUTexelCopyTextureInfo *from,
                                             const WGPUTexelCopyTextureInfo *to,const WGPUExtent3D *size) {
    assert(e && from->texture && to->texture==(WGPUTexture)(uintptr_t)0x20 && event>=2);
    event=3; assert(copies<12); layers[copies]=to->origin.z; mips[copies]=to->mipLevel; widths[copies]=size->width; copies++;
}
WGPURenderPassEncoder wgpuCommandEncoderBeginRenderPass(WGPUCommandEncoder e,const WGPURenderPassDescriptor *desc) {
    assert(e && event==3 && desc->colorAttachmentCount==1);
    assert(desc->colorAttachments[0].view==(WGPUTextureView)(uintptr_t)0x40);
    event=4; begins++; return (WGPURenderPassEncoder)(uintptr_t)0x50;
}
int main(void) {
    GTex cube={0}; cube.tex=(WGPUTexture)(uintptr_t)0x20; cube.faces=6; cube.fmt=TEXFMT_SURF_RGBA8; cube.w=cube.h=8; cube.levels=2;
    GSurf a={0}, b={0}, bad={0}; a.tex=(WGPUTexture)(uintptr_t)0x21; a.w=a.h=8;
    b.tex=(WGPUTexture)(uintptr_t)0x22; b.w=b.h=4; bad.tex=(WGPUTexture)(uintptr_t)0x23; bad.w=7; bad.h=8;
    obj_put(1,&cube); obj_put(2,&a); obj_put(3,&b); obj_put(4,&bad);
    CmdCopyCubeRT cmd={0}; cmd.id=1; cmd.levels=2; cmd.surface[0][0]=2; cmd.surface[1][1]=3; cmd.surface[2][0]=4;
    g_pass=(WGPURenderPassEncoder)(uintptr_t)0x30; g_enc=(WGPUCommandEncoder)(uintptr_t)0x10;
    g_tgt_color=(WGPUTextureView)(uintptr_t)0x40; g_tgt_depth=(WGPUTextureView)(uintptr_t)0x41;
    exec_copy_cube_rt(&cmd);
    assert(ends==1 && releases==1 && copies==2 && !g_pass);
    assert(layers[0]==0 && mips[0]==0 && widths[0]==8 && layers[1]==1 && mips[1]==1 && widths[1]==4);
    begin_pass(0,0,1,0); assert(begins==1 && g_pass && g_tgt_color==(WGPUTextureView)(uintptr_t)0x40);
    cube.fmt=TEXFMT_RGBA8; int old=event; exec_copy_cube_rt(&cmd); assert(event==old && copies==2);
    /* Exercise actual executor readback for both channel layouts and sRGB. */
    g_mem=calloc(1,4096); assert(g_mem);
    CmdReadback read={0}; read.w=read.h_=1; read.pitch=4; read.guest_mem=0x100; read.fmt=FMT_A8R8G8B8;
    const uint8_t rgba[4]={128,64,32,123}, expected[4]={32,64,128,123}; uint8_t raw[4];
    WGPUTextureFormat formats[4]={WGPUTextureFormat_RGBA8Unorm,WGPUTextureFormat_BGRA8Unorm,
        WGPUTextureFormat_RGBA8UnormSrgb,WGPUTextureFormat_BGRA8UnormSrgb};
    for (int i=0;i<4;i++) {
        g_surf_fmt=formats[i]; surface_from_rgba(rgba,raw,surface_bgra(),surface_srgb());
        store_pixels(&read,raw,1,1,4);
        for (int k=0;k<4;k++) assert(abs((int)g_mem[0x100+k]-expected[k])<=(i>=2 && k<3 ? 1 : 0));
        read.fmt=FMT_R5G6B5; read.pitch=2; store_pixels(&read,raw,1,1,4);
        assert(g_mem[0x100]==0x04 && g_mem[0x101]==0x82); /* 0x8204: R16 G16 B4 */
        read.fmt=FMT_A8R8G8B8; read.pitch=4;
    }
    /* Async map failure is reported and must not mark a dirty RT current. */
    volatile int done=0; g_rb_cmd=read; g_rb_cmd.id=2; g_rb_cmd.done_ptr=(uint64_t)(uintptr_t)&done;
    g_rb_buf=(WGPUBuffer)(uintptr_t)0x99; g_rb_stride=4; g_rb_gw=g_rb_gh=1; g_rb_pending=1; a.gpu_dirty=1;
    on_rb_mapped((WGPUMapAsyncStatus)999,(WGPUStringView){0},NULL,NULL);
    assert(done==-1 && a.gpu_dirty==1 && !g_rb_pending && unmaps==0);
    done=0; g_rb_pending=1; mapped_bytes[0]=32; mapped_bytes[1]=64; mapped_bytes[2]=128; mapped_bytes[3]=255;
    g_surf_fmt=WGPUTextureFormat_BGRA8Unorm;
    on_rb_mapped(WGPUMapAsyncStatus_Success,(WGPUStringView){0},NULL,NULL);
    assert(done==1 && a.gpu_dirty==0 && !g_rb_pending && unmaps==1);
    /* Actual row writer preserves origin/face/mip and converts BGRA in place. */
    CmdUploadTex upload={0}; upload.id=1; upload.faces=6; upload.levels=2; upload.fmt=TEXFMT_SURF_RGBA8;
    upload.w[0]=upload.h_[0]=8; upload.w[1]=upload.h_[1]=4; assert(valid_tex_command(&upload));
    upload.w[1]=3; assert(!valid_tex_command(&upload)); upload.w[1]=4;
    g_surf_fmt=WGPUTextureFormat_BGRA8Unorm;
    uint8_t pixels[4*2*4]; for (unsigned i=0;i<sizeof pixels;i+=4) {
        pixels[i]=128; pixels[i+1]=64; pixels[i+2]=32; pixels[i+3]=255;
    }
    expected_layer=5; expected_mip=1; expected_y=2; expected_rows=2;
    write_texture_rows(&cube,&upload,5,1,2,2,pixels); assert(writes==1);
    free(g_mem);
    puts("cube RT executor: end pass, layer/mip copies, invalid surface, reopen and 4 readback formats PASS");
}
