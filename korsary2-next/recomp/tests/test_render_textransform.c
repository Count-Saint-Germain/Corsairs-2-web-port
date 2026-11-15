#include "../host/render_textransform.h"
#include <assert.h>
#include <math.h>

static int near(float a, float b) { return fabsf(a-b)<0.00001f; }
int main(void) {
    const float matrix[16]={2,3,0,0, 4,5,0,0, 6,7,1,0, 8,9,0,1};
    float uv[4]={.25f,.5f,0,1};
    d3d8_textransform_count2(uv,matrix,0);
    assert(near(uv[0],.25f) && near(uv[1],.5f));
    d3d8_textransform_count2(uv,matrix,0x102); /* projected mode is untouched */
    assert(near(uv[0],.25f) && near(uv[1],.5f));
    d3d8_textransform_count2(uv,matrix,2);
    assert(near(uv[0],8.5f) && near(uv[1],10.25f));
    assert(near(uv[2],0) && near(uv[3],1));
    return 0;
}
