#include <assert.h>
#include <stdio.h>
#include "render_cull.h"

/* With frontFace=CW, front culling discards CW and back culling discards CCW. */
static int discarded(WGPUCullMode mode, int clockwise) {
    return (mode == WGPUCullMode_Front && clockwise) ||
           (mode == WGPUCullMode_Back && !clockwise);
}

int main(void) {
    WGPUCullMode none = d3d8_cull_to_wgpu(1);
    WGPUCullMode cw = d3d8_cull_to_wgpu(2);
    WGPUCullMode ccw = d3d8_cull_to_wgpu(3);
    assert(!discarded(none, 0) && !discarded(none, 1));
    assert(discarded(cw, 1) && !discarded(cw, 0));
    assert(discarded(ccw, 0) && !discarded(ccw, 1));
    assert(d3d8_cull_to_wgpu(0) == WGPUCullMode_None);
    puts("D3D8/WebGPU cull modes OK (frontFace=CW)");
}
