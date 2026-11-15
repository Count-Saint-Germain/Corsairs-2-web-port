/* Rendering is split in two (see render_rec.c and render_wgpu.c):
 *   recorder  - runs on the game thread; does all CPU work (primitive expansion, vertex shaders,
 *               texture conversion, uniforms) and emits self-contained commands;
 *   executor  - owns every WebGPU object and executes the commands.
 * Natively each command is executed right away. In the browser, WebGPU must live on the page's
 * thread (which returns to its event loop), so commands are queued per frame and replayed there.
 * Commands never point at game objects: textures and surfaces are referred to by numeric ids. */
#ifndef PORT_RENDER_CMD_H
#define PORT_RENDER_CMD_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct { float x, y, z, w; uint32_t diffuse, specular; float tc[4][4]; } CVert;  /* 88 bytes */

typedef struct {
    float mvp[16];
    float vp[4];
    uint32_t flags[4];
    uint32_t st0[4], st0b[4], st1[4], st1b[4];
    /* audit W6: texture stages 2-3, same layout as st0/st0b (colorop, colorarg1, colorarg2, alphaop /
     * alphaarg1, alphaarg2, texcoord index, colorarg0 | alphaarg0 << 8). Packed by the recorder only
     * when stage 2 runs a real color op (> D3DTOP_DISABLE); otherwise left zeroed, which the WGSL
     * stage-2/3 gates treat as the documented D3D8 default (D3DTOP_DISABLE for stages 1+). */
    uint32_t st2[4], st2b[4], st3[4], st3b[4];
    float tfactor[4];
    float misc[4];
    float mat_diffuse[4];
    float ambient[4];
    float psc[8][4];
    float bem[4][4];
    float bel[4][4];
    float fog[4];   /* audit W5: xyz = fog color (0..1), w = fog enabled (0/1); mixed at the end of both fs */
} Uniforms;   /* 560 bytes; every member is 16-byte aligned (WGSL uniform layout), USTRIDE must stay >= this */
_Static_assert(sizeof(Uniforms) % 16 == 0, "Uniforms feeds a WGSL uniform buffer (16-byte multiples)");

typedef struct PKey { uint32_t blend, src, dst, op, zen, zwrite, zfunc, cull, cmask, topo, ps, zbias; } PKey;

enum { CMD_TARGET = 1, CMD_CLEAR, CMD_DRAW, CMD_UPLOAD_TEX, CMD_DESTROY_TEX, CMD_UPLOAD_SURF, CMD_DESTROY_SURF,
       CMD_READBACK, CMD_PRESENT, CMD_COPY_CUBE_RT, CMD_UPLOAD_TEX_REGION };

typedef struct { uint32_t type, size; } CmdHdr;   /* size includes the header; 8-byte aligned */

/* Render target for the following clears/draws. color_id 0 = the back buffer. depth_id 0 = the
   device's own depth buffer (back buffer) or a scratch one (render targets). */
typedef struct { CmdHdr h; uint32_t color_id, color_w, color_h, depth_id, depth_w, depth_h, lw, lh; } CmdTarget;

typedef struct { CmdHdr h; uint32_t flags, color, stencil; float z; } CmdClear;

/* texture slot kinds */
enum { TS_NONE = 0, TS_TEX, TS_RTSURF, TS_CUBE };

typedef struct {
    CmdHdr h;
    PKey key;
    float vp[4];              /* Direct3D viewport (target logical pixels) */
    float minz, maxz;
    uint32_t full_viewport;   /* clear quads: ignore vp, cover the whole target */
    uint32_t slot_kind[4], slot_id[4], samp_key[4];
    uint32_t pixel_shader;    /* empty slots read black (pixel shaders) or white (fixed function) */
    int32_t capture_index;    /* debugging: save the back buffer after this draw (native only); -1 none */
    Uniforms u;
    uint32_t nverts;
    /* CVert verts[nverts] follow */
} CmdDraw;

/* Payload is face-major, mip-minor: each RGBA8 level has w*h*4 bytes.
   BC formats contain the stored blocks instead when the GPU samples BC. */
enum { TEXFMT_RGBA8 = 0, TEXFMT_BC1, TEXFMT_BC2, TEXFMT_BC3, TEXFMT_SURF_RGBA8 };
typedef struct { CmdHdr h; uint32_t id, levels, faces, fmt, w[14], h_[14]; } CmdUploadTex;
/* One bounded face/mip stripe for large resources. y/rows are logical pixels;
   BC payloads use complete block rows (including rounded-up final dimensions). */
typedef struct { CmdUploadTex tex; uint32_t face, level, y, rows; } CmdUploadTexRegion;
/* Render-target cube: copy existing face/mip GSurf resources into its array layers.
   Zero ids denote an uncreated surface. Commands contain no guest pointers. */
typedef struct { CmdHdr h; uint32_t id, levels, surface[6][14]; } CmdCopyCubeRT;
extern int g_gpu_bc;   /* the device can sample BC1-3 (set before the game draws) */
typedef struct { CmdHdr h; uint32_t id; } CmdDestroy;
/* level data follows: RGBA8 rows, or BC blocks (rows of (w+3)/4 blocks) */
typedef struct { CmdHdr h; uint32_t id, w, h_; } CmdUploadSurf;

/* Copies a render target (id 0: back buffer, scaled to w x h) into guest memory in format `fmt`,
   then sets *done (a host address) to 1. */
typedef struct { CmdHdr h; uint32_t id, w, h_, fmt, pitch, guest_mem; uint64_t done_ptr; } CmdReadback;

typedef struct { CmdHdr h; uint32_t frame, screenshot; } CmdPresent;

/* executor entry points */
void gpu_exec(const CmdHdr *c);              /* native: run one command now */
int gpu_init_native(void);                   /* native: create device, surface and pipelines */

/* ------------------------------------------------------------------ fog (audit W5)
 * D3D8 fog on the port: the recorder computes the per-vertex blend factor f (1 = no fog, 0 = full
 * fog) on the CPU and packs it into the alpha byte of CVert.specular - the exact place D3D itself
 * keeps it ("The system stores the fog factor in the alpha component of the specular color", MSDN
 * "Fog Formulas"). The uniform fog color is mixed at the end of both fragment paths; D3D blends RGB
 * only, the pixel alpha is untouched. Uniforms.fog.w gates the mix so draws without fog keep their
 * original specular alpha. Per-vertex lighting (audit W2, implemented in render_rec.c) computes the
 * specular RGB into CVert.specular and keeps the alpha byte (bits 24-31) reserved for the fog
 * factor, which the draw loop applies after lighting. */

/* ps.1.x shaders are translated by the frozen pshader.c, which ends every fragment entry point with
   this exact tail; the executor appends the fog mix just before it, so the generator stays untouched. */
#define RENDER_PS_FOG_TAIL "  let o = saturate(r0);\n"
#define RENDER_PS_FOG_LINE \
    "  if (u.fog.w > 0.0) { r0 = vec4<f32>(mix(u.fog.xyz, r0.rgb, clamp(i.specular.a, 0.0, 1.0)), r0.a); }\n"

/* Inserts RENDER_PS_FOG_LINE before the last fragment-tail occurrence in a pshader.c WGSL string
   (frees the string, returns a fresh one). Returns the input unchanged when the tail is not found
   (fail-safe: that shader simply renders without fog instead of breaking). */
static inline char *ps_inject_fog(char *fs) {
    const size_t tail_n = sizeof(RENDER_PS_FOG_TAIL) - 1, line_n = sizeof(RENDER_PS_FOG_LINE) - 1;
    const char *last = NULL;
    for (const char *p = fs; (p = strstr(p, RENDER_PS_FOG_TAIL)) != NULL; p += tail_n) last = p;
    if (!last) return fs;
    size_t head = (size_t)(last - fs), rest = strlen(last);
    char *out = malloc(head + line_n + rest + 1);
    if (!out) return fs;
    memcpy(out, fs, head);
    memcpy(out + head, RENDER_PS_FOG_LINE, line_n);
    memcpy(out + head + line_n, last, rest + 1);
    free(fs);
    return out;
}

#endif
