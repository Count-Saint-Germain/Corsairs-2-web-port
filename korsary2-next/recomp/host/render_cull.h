#ifndef PORT_RENDER_CULL_H
#define PORT_RENDER_CULL_H

#include <stdint.h>
#include <webgpu/webgpu.h>

/* Requires a pipeline with frontFace=CW in framebuffer coordinates. */
static inline WGPUCullMode d3d8_cull_to_wgpu(uint32_t mode) {
    switch (mode) {
    case 2: return WGPUCullMode_Front; /* D3DCULL_CW */
    case 3: return WGPUCullMode_Back;  /* D3DCULL_CCW */
    default: return WGPUCullMode_None; /* D3DCULL_NONE or unknown */
    }
}
#endif
