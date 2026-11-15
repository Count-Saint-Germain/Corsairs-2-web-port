#ifndef PORT_RENDER_TEXTRANSFORM_H
#define PORT_RENDER_TEXTRANSFORM_H

#include <stdint.h>

/* D3DTTFF_COUNT2: row-vector texture matrix, for ordinary FVF coordinates.
   Other modes (including projected coordinates) need their own implementation. */
static inline void d3d8_textransform_count2(float uv[4], const float matrix[16], uint32_t flags) {
    if (flags != 2) return;
    /* D3D expands two-dimensional fixed-function input to (u,v,1,0). */
    const float x=uv[0], y=uv[1];
    uv[0]=x*matrix[0]+y*matrix[4]+matrix[8];
    uv[1]=x*matrix[1]+y*matrix[5]+matrix[9];
}
#endif
