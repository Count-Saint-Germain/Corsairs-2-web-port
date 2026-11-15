/* CPU copies to/from WGPU render surfaces. D3D8 values are treated as the
 * shader's numeric channel values; an sRGB attachment encodes on write and
 * decodes on sampling, so raw CPU copies must perform those conversions too.
 * This does not make sRGB attachment blending identical to D3D8 gamma-space
 * blending: prefer a non-sRGB surface and warn when none is available. */
#ifndef PORT_RENDER_SURFACE_COLOR_H
#define PORT_RENDER_SURFACE_COLOR_H
#include <math.h>
#include <stddef.h>
#include <stdint.h>

static inline uint8_t surface_byte(float x) {
    if (x<=0.f) return 0;
    if (x>=1.f) return 255;
    return (uint8_t)(x*255.f+0.5f);
}
static inline uint8_t surface_srgb_encode(uint8_t linear) {
    float x=(float)linear/255.f;
    return surface_byte(x<=0.0031308f ? x*12.92f : 1.055f*powf(x,1.f/2.4f)-0.055f);
}
static inline uint8_t surface_srgb_decode(uint8_t encoded) {
    float x=(float)encoded/255.f;
    return surface_byte(x<=0.04045f ? x/12.92f : powf((x+0.055f)/1.055f,2.4f));
}
/* RGBA8 numeric values -> raw 4-byte texture storage; in-place is allowed. */
static inline void surface_from_rgba(const uint8_t *rgba,uint8_t *out,int bgra,int srgb) {
    uint8_t r=rgba[0],g=rgba[1],b=rgba[2],a=rgba[3];
    if (srgb) { r=surface_srgb_encode(r); g=surface_srgb_encode(g); b=surface_srgb_encode(b); }
    out[0]=bgra?b:r; out[1]=g; out[2]=bgra?r:b; out[3]=a;
}
/* Raw texture storage -> numeric values in BGRA order for pack_pixel(). */
static inline void surface_to_bgra(const uint8_t *raw,uint8_t *out,int bgra,int srgb) {
    uint8_t r=raw[bgra?2:0],g=raw[1],b=raw[bgra?0:2],a=raw[3];
    if (srgb) { r=surface_srgb_decode(r); g=surface_srgb_decode(g); b=surface_srgb_decode(b); }
    out[0]=b; out[1]=g; out[2]=r; out[3]=a;
}
#endif
