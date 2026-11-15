/* Render recorder: the game-thread half of the renderer (see render_cmd.h).
 *
 * Implements the Direct3D backend interface by doing all CPU work here - expanding primitives to
 * lists, running vertex shaders, converting changed textures to RGBA, building uniforms and pipeline
 * keys - and emitting self-contained commands for the executor (render_wgpu.c). Natively every
 * command runs immediately; in the browser commands are queued per frame for the page's thread. */
#include "render.h"
#include "render_cmd.h"
#include "vshader.h"

#include <math.h>
#include <sys/stat.h>
#include <unistd.h>

int texture_to_rgba8(uint32_t fmt, const uint8_t *src, uint32_t pitch, uint32_t w, uint32_t h, uint8_t *dst,
                     const uint8_t *palette);
extern uint8_t g_palettes[][1024];

/* WGPUPrimitiveTopology values (kept numeric so this file doesn't need webgpu.h) */
enum { TOPO_POINTS = 1, TOPO_LINES = 2, TOPO_TRIANGLES = 4 };

/* ------------------------------------------------------------------ command buffer
 * One recorder for the whole process: Direct3D calls come from the game thread, but objects can be
 * released from others, so every entry point holds g_rec_lock (recursive). */

#include <pthread.h>
static pthread_mutex_t g_rec_lock;
static pthread_once_t g_rec_once = PTHREAD_ONCE_INIT;
static void rec_lock_init(void) {
    pthread_mutexattr_t a;
    pthread_mutexattr_init(&a);
    pthread_mutexattr_settype(&a, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&g_rec_lock, &a);
}
static void rec_enter(void) { pthread_once(&g_rec_once, rec_lock_init); pthread_mutex_lock(&g_rec_lock); }
static void rec_leave(void) { pthread_mutex_unlock(&g_rec_lock); }

static uint8_t *g_cb;
static size_t g_cb_len, g_cb_cap;

#ifndef PORT_CMD_REALLOC
#define PORT_CMD_REALLOC realloc
#endif
static void *cmd_alloc(uint32_t type, size_t size) {
    if (size > UINT32_MAX-7u || size > SIZE_MAX-7u) return NULL;
    size = (size+7u) & ~(size_t)7;
    if (g_cb_len > SIZE_MAX-size) return NULL;
    size_t needed=g_cb_len+size;
    if (needed>g_cb_cap) {
        size_t cap=needed;
        if (needed <= (SIZE_MAX-(1u<<20))/2u) cap=needed*2u+(1u<<20);
        void *p=PORT_CMD_REALLOC(g_cb,cap);
        if (!p && cap!=needed) { cap=needed; p=PORT_CMD_REALLOC(g_cb,cap); }
        if (!p) { static int warned; if (!warned++) fprintf(stderr,"[render] command allocation failed\n"); return NULL; }
        g_cb=p; g_cb_cap=cap;
    }
    CmdHdr *h=(CmdHdr *)(g_cb+g_cb_len);
    memset(h,0,size); h->type=type; h->size=(uint32_t)size; g_cb_len=needed; return h;
}

#ifdef __EMSCRIPTEN__
/* browser: completed command chunks go to the page's thread (web_gpu.c) */
void web_queue_chunk(uint8_t *buf, size_t len, int ends_frame);
int web_queued_frames(void);
int web_queued_chunks(void);
int web_gpu_ready(void);

static void cmd_end(void) {}

static void cmd_flush(int ends_frame) {
    if (!g_cb_len && !ends_frame) return;
    web_queue_chunk(g_cb, g_cb_len, ends_frame);   /* takes ownership */
    g_cb = NULL; g_cb_len = g_cb_cap = 0;
}
#else
/* native: run each command as soon as it is recorded */
static void cmd_end(void) {
    size_t off = 0;
    while (off < g_cb_len) {
        const CmdHdr *h = (const CmdHdr *)(g_cb + off);
        gpu_exec(h);
        off += h->size;
    }
    g_cb_len = 0;
}
static void cmd_flush(int ends_frame) { (void)ends_frame; }
#endif

/* ------------------------------------------------------------------ debugging aids
 * PORT_SCREENSHOTS="120,600" saves /tmp/port_frame_N.png; `touch /tmp/port_snap` or PORT_CAPTURE=N logs
 * every draw of a frame and saves the back buffer after each one (native only). */

static int g_snap_detail;
static uint32_t g_f_drawn;
static uint32_t g_trace_vs;

static int want_screenshot(uint32_t frame) {
    static uint32_t last_check;
    static int cap_frame = -1;
    if (cap_frame < 0) {
        cap_frame = getenv("PORT_CAPTURE") ? atoi(getenv("PORT_CAPTURE")) : 0;
        g_trace_vs = getenv("PORT_TRACE_VS") ? (uint32_t)strtoul(getenv("PORT_TRACE_VS"), NULL, 16) : 0;
    }
    if (cap_frame && frame + 1 == (uint32_t)cap_frame) { g_snap_detail = 1; return 0; }
    if (frame - last_check >= 15) {
        last_check = frame;
        if (!access("/tmp/port_snap", F_OK)) {
            unlink("/tmp/port_snap");
            g_snap_detail = 1;
            return 0;
        }
    }
    if (g_snap_detail) {
        g_snap_detail = 0;
        fprintf(stderr, "[snap] frame %u: %u draws\n", frame, g_f_drawn);
        return 1;
    }
    static const char *list = (const char *)1;
    if (list == (const char *)1) list = getenv("PORT_SCREENSHOTS");
    if (!list) return 0;
    char tmp[64];
    snprintf(tmp, sizeof tmp, "%u", frame);
    for (const char *p = list; *p;) {
        size_t n = strcspn(p, ",");
        if (n == strlen(tmp) && !strncmp(p, tmp, n)) return 1;
        p += n + (p[n] == ',');
    }
    return 0;
}

/* ------------------------------------------------------------------ render target tracking */

static CmdTarget g_last_target;   /* zero: back buffer, not yet sent */
static int g_target_sent;
static uint32_t g_tgt_lw, g_tgt_lh;

static int select_target(Device *d) {
    const DevState *st = &d->st;
    Surface *rt = st->render_target && st->render_target != d->backbuffer ? com_data(st->render_target) : NULL;
    Surface *ds = st->depth_stencil && st->depth_stencil != d->depth ? com_data(st->depth_stencil) : NULL;
    if (rt && !d3d_sync_surface(d,rt)) return 0;
    CmdTarget t;
    memset(&t, 0, sizeof t);
    if (rt) { t.color_id = rt->gpu_id; t.color_w = rt->width; t.color_h = rt->height; t.lw = rt->width; t.lh = rt->height; }
    else { t.lw = d->width; t.lh = d->height; }
    if (ds) { t.depth_id = ds->gpu_id; t.depth_w = ds->width; t.depth_h = ds->height; }
    g_tgt_lw = t.lw; g_tgt_lh = t.lh;
    if (g_target_sent && !memcmp(&t.color_id, &g_last_target.color_id, sizeof t - sizeof t.h)) return 1;
    if (g_snap_detail)
        fprintf(stderr, "[target] color %u (%ux%u, logical %ux%u) depth %u\n", t.color_id, t.color_w, t.color_h, t.lw, t.lh,
                t.depth_id);
    CmdTarget *c = cmd_alloc(CMD_TARGET, sizeof *c);
    if (!c) return 0;
    memcpy(&c->color_id, &t.color_id, sizeof t - sizeof t.h);
    cmd_end();
    g_last_target = t;
    g_target_sent = 1;
    return 1;
}

/* ------------------------------------------------------------------ vertices */

typedef struct { uint32_t stride, pos_type, has_normal, has_psize, has_diffuse, has_specular, ntex,
                 off_normal, off_diffuse, off_specular, off_tex[8], tex_dim[8]; } FvfLayout;

static void fvf_layout(uint32_t fvf, FvfLayout *L) {
    memset(L, 0, sizeof *L);
    uint32_t off = 0;
    L->pos_type = fvf & 0xE;
    switch (L->pos_type) {
    case 0x2: off = 12; break;              /* XYZ */
    case 0x4: off = 16; break;              /* XYZRHW */
    case 0x6: off = 16; break; case 0x8: off = 20; break; case 0xA: off = 24; break;   /* XYZB1-3 */
    case 0xC: off = 28; break; case 0xE: off = 32; break;
    }
    if (fvf & 0x10) { L->has_normal = 1; L->off_normal = off; off += 12; }
    if (fvf & 0x20) { L->has_psize = 1; off += 4; }
    if (fvf & 0x40) { L->has_diffuse = 1; L->off_diffuse = off; off += 4; }
    if (fvf & 0x80) { L->has_specular = 1; L->off_specular = off; off += 4; }
    L->ntex = (fvf >> 8) & 0xF;
    for (uint32_t i = 0; i < L->ntex && i < 8; i++) {
        L->off_tex[i] = off;
        uint32_t f = (fvf >> (16 + 2 * i)) & 3;
        L->tex_dim[i] = f == 0 ? 2 : f == 1 ? 3 : f == 2 ? 4 : 1;
        off += 4 * L->tex_dim[i];
    }
    L->stride = off;
}

static void convert_vertex(const uint8_t *v, const FvfLayout *L, CVert *o) {
    float f[4] = { 0, 0, 0, 1 };
    memcpy(f, v, L->pos_type == 0x4 ? 16 : 12);
    o->x = f[0]; o->y = f[1]; o->z = f[2]; o->w = L->pos_type == 0x4 ? f[3] : 1.f;
    o->diffuse = 0xFFFFFFFFu; o->specular = 0;
    if (L->has_diffuse) memcpy(&o->diffuse, v + L->off_diffuse, 4);
    if (L->has_specular) memcpy(&o->specular, v + L->off_specular, 4);
    memset(o->tc, 0, sizeof o->tc);
    for (uint32_t t = 0; t < 4; t++) {
        o->tc[t][3] = 1.f;
        if (t < L->ntex) memcpy(o->tc[t], v + L->off_tex[t], 4 * L->tex_dim[t]);
    }
}

/* Route FVF pass-through coordinates to fixed-function stages before interpolation.
   Only the ordinary 0..7 case is supported here: generated coordinates and
   programmable shaders retain their existing paths. */
static int route_fvf_texcoords_enabled(int has_vs, uint32_t ps, uint32_t tc0, uint32_t tc1) {
    return !has_vs && !ps && tc0 < 8 && tc1 < 8;
}

static void route_fvf_texcoords(const uint8_t *src, const FvfLayout *L, CVert *out,
                                uint32_t stage0, uint32_t stage1) {
    uint32_t index[2] = {stage0, stage1};
    for (unsigned s = 0; s < 2; ++s) {
        float *dst = out->tc[s];
        dst[0] = dst[1] = dst[2] = 0.f; dst[3] = 1.f;
        if (index[s] < L->ntex && index[s] < 8)
            memcpy(dst, src + L->off_tex[index[s]], 4 * L->tex_dim[index[s]]);
    }
}

static void mat_mul(const float *a, const float *b, float *r) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            float s = 0;
            for (int k = 0; k < 4; k++) s += a[i * 4 + k] * b[k * 4 + j];
            r[i * 4 + j] = s;
        }
}

static uint32_t pack_color(const float *f) {   /* RGBA floats -> D3DCOLOR (ARGB) */
    uint32_t b[4];
    for (int i = 0; i < 4; i++) { float v = f[i] < 0 ? 0 : f[i] > 1 ? 1 : f[i]; b[i] = (uint32_t)(v * 255.f + 0.5f); }
    return b[2] | b[1] << 8 | b[0] << 16 | b[3] << 24;
}

static void unpack_color(uint32_t c, float *o) {
    o[0] = ((c >> 16) & 255) / 255.f; o[1] = ((c >> 8) & 255) / 255.f; o[2] = (c & 255) / 255.f; o[3] = (c >> 24) / 255.f;
}

/* ------------------------------------------------------------------ fog (audit W5)
 * D3D8 fog states (d3d8types.h): FOGENABLE=28, FOGCOLOR=34, FOGTABLEMODE=35, FOGSTART=36,
 * FOGEND=37, FOGDENSITY=38, RANGEFOGENABLE=48, FOGVERTEXMODE=140; D3DFOG_NONE/EXP/EXP2/LINEAR
 * = 0/1/2/3. FOGSTART/FOGEND/FOGDENSITY arrive as float bits in the DWORD state.
 * Formulas (MSDN "Fog Formulas"; f is the visibility factor, 1 = no fog):
 *   linear: f = (end - d) / (end - start)      exp: f = 1/e^(d*density)      exp2: f = 1/e^((d*density)^2)
 *   final color = f * source + (1 - f) * fogcolor (RGB only; pixel alpha is not fogged).
 * Depth: non-range fog uses |camera-space z|, RANGEFOGENABLE uses the eye distance (same doc);
 * pixel/table fog is approximated with the same view-space depth - with a compliant projection its
 * hardware depth is the eye-relative w, which matches -z of a rigid view transform (MSDN "Pixel
 * Fog"). Table fog is therefore computed per vertex and interpolated, not per pixel. */

enum { RS_FOGENABLE = 28, RS_FOGCOLOR = 34, RS_FOGTABLEMODE = 35, RS_FOGSTART = 36, RS_FOGEND = 37,
       RS_FOGDENSITY = 38, RS_RANGEFOGENABLE = 48, RS_FOGVERTEXMODE = 140 };
enum { FOG_NONE = 0, FOG_EXP = 1, FOG_EXP2 = 2, FOG_LINEAR = 3 };

static float fog_state_float(const DevState *st, uint32_t rs) {
    float f;
    memcpy(&f, &st->rs[rs], 4);
    return f;
}

/* the mode fog is computed with for a draw: FOGTABLEMODE wins over FOGVERTEXMODE (MSDN "Pixel Fog");
   0 (D3DFOG_NONE) = fog disabled for this draw even when FOGENABLE is set */
static uint32_t draw_fog_mode(const DevState *st) {
    if (!st->rs[RS_FOGENABLE]) return FOG_NONE;
    if (st->rs[RS_FOGTABLEMODE]) return st->rs[RS_FOGTABLEMODE];
    return st->rs[RS_FOGVERTEXMODE];
}

static float clamp01(float v) {
    if (!(v >= 0)) return 0;   /* also maps NaN to 0 */
    return v > 1 ? 1 : v;
}

static float fog_factor(uint32_t mode, float d, float start, float end, float density) {
    if (d < 0) d = 0;
    switch (mode) {
    case FOG_LINEAR: {
        float denom = end - start;
        if (fabsf(denom) < 1e-6f) return end >= d ? 1.f : 0.f;   /* zero-width ramp */
        return clamp01((end - d) / denom);   /* end < start keeps the raw inverted-ramp formula */
    }
    case FOG_EXP:
        if (!(density >= 0)) return 1.f;   /* negative or NaN density: no fog */
        return clamp01(expf(-d * density));
    case FOG_EXP2: {
        if (!(density >= 0)) return 1.f;
        float x = d * density;
        return clamp01(expf(-x * x));
    }
    default: return 1.f;   /* D3DFOG_NONE and unknown modes: no fog */
    }
}

/* view-space fog depth for a model-space vertex through the WORLD*VIEW matrix (row-major, D3D layout) */
static float fog_depth(const float *wv, float x, float y, float z, int range) {
    float vx = x * wv[0] + y * wv[4] + z * wv[8] + wv[12];
    float vy = x * wv[1] + y * wv[5] + z * wv[9] + wv[13];
    float vz = x * wv[2] + y * wv[6] + z * wv[10] + wv[14];
    if (range) return sqrtf(vx * vx + vy * vy + vz * vz);
    return fabsf(vz);
}

/* visibility factor -> the alpha byte of the D3DCOLOR specular (where D3D keeps the fog factor) */
static uint32_t fog_alpha_byte(float f) {
    return (uint32_t)(clamp01(f) * 255.f + 0.5f) << 24;
}

/* ------------------------------------------------------------------ texture-stage uniforms (audit W6)
 * TSS indices (d3d8types.h): COLOROP=1, COLORARG1=2, COLORARG2=3, ALPHAOP=4, ALPHAARG1=5,
 * ALPHAARG2=6, TEXCOORDINDEX=11, COLORARG0=26, ALPHAARG0=27. D3DTOP_DISABLE=1. */

/* texture-stage blend state -> uniforms. Stages 0-1 are packed for every draw exactly as before.
 * Stages 2-3 are packed only when stage 2 runs a real color op (> D3DTOP_DISABLE = 1): the unset
 * raw value 0 has no D3DTOP meaning, and the documented D3D8 default for stages 1+ is
 * D3DTOP_DISABLE, which the zeroed uniforms express through the WGSL gates. This keeps every
 * two-stage draw on the previous path unchanged. Stage 3 is packed with stage 2 (per the D3D
 * disable rule an enabled stage behind a disabled one is inert, so the stage-2 gate is complete; a
 * zeroed stage-3 colorop is normalized to DISABLE). AlphaOp[2]/[3] values 0 and 1 both read as
 * disabled in the WGSL (alpha preserved), matching the same default. */
static void pack_stages(Uniforms *u, const DevState *st, int sh, int route_fvf) {
    for (int s = 0; s < 2; s++) {
        const uint32_t *t = st->tss[s];
        uint32_t *a = s ? u->st1 : u->st0, *b = s ? u->st1b : u->st0b;
        a[0] = t[1]; a[1] = t[2]; a[2] = t[3]; a[3] = t[4];
        b[0] = t[5]; b[1] = t[6]; b[2] = sh || route_fvf ? (uint32_t)s : t[11] & 7; b[3] = (t[26] & 255) | (t[27] & 255) << 8;
    }
    if (st->tss[2][1] <= 1) return;   /* unset (0) or D3DTOP_DISABLE: stage 2+ stays off */
    for (int s = 2; s < 4; s++) {
        const uint32_t *t = st->tss[s];
        uint32_t *a = s == 2 ? u->st2 : u->st3, *b = s == 2 ? u->st2b : u->st3b;
        a[0] = t[1] ? t[1] : 1u;   /* unset colorop (0) -> D3DTOP_DISABLE (the D3D8 default, stages 1+) */
        a[1] = t[2]; a[2] = t[3]; a[3] = t[4];
        b[0] = t[5]; b[1] = t[6]; b[2] = t[11] & 7; b[3] = (t[26] & 255) | (t[27] & 255) << 8;
    }
}

/* ------------------------------------------------------------------ lighting (audit W2)
 * Render states (d3d8types.h numbering): LIGHTING=137, AMBIENT=139, COLORVERTEX=141,
 * LOCALVIEWER=142, NORMALIZENORMALS=143, DIFFUSE/SPECULAR/AMBIENT/EMISSIVEMATERIALSOURCE =
 * 145/146/147/148 with D3DMCS MATERIAL/COLOR1/COLOR2 = 0/1/2. DevState.material is a raw
 * D3DMATERIAL8 (Diffuse, Ambient, Specular, Emissive, Power = floats 0..16); DevState.light[i] is
 * a raw 104-byte D3DLIGHT8 (Type, Diffuse[4], Specular[4], Ambient[4], Position[3], Direction[3],
 * Range, Falloff, Attenuation0..2, Theta, Phi); D3DLIGHT_POINT/SPOT/DIRECTIONAL = 1/2/3.
 * Model (MSDN "Mathematics of Lighting", "Camera Space Transformations"): lighting runs in camera
 * space - V = WORLD*VIEW*v, N = N*((WORLD*VIEW)^-1)^T (normalized afterwards when
 * NORMALIZENORMALS), the light position is transformed by VIEW, and the direction to the light is
 * -norm(Direction*VIEW) for directional lights, norm(Lp - V) for point/spot ones;
 *   vertex RGB   = emissive + Ca*(global ambient + sum(Atten*Spot*La)) + sum(Cd*Ld*max(N.Ldir,0)*Atten*Spot)
 *   specular RGB = sum(Cs*Ls*(N.H)^Power*Atten*Spot) over SPECULARENABLE, with the halfway vector
 *                  H = norm(norm(-V) + Ldir) under LOCALVIEWER and norm((0,0,1) + Ldir) without.
 * The diffuse sum stays in CVert.diffuse (the texture stages read it); the specular sum goes into
 * CVert.specular.rgb and the fixed-function fragment stage adds it after texturing. Vertex alpha is
 * never lit: the output alpha is the unlit alpha of the diffuse color source. Ca/Cd/Cs/Ce come from
 * the material or per-vertex colors per the material-source states (COLORVERTEX=0 forces the
 * material; a vertex color the FVF lacks falls back to the material, per MSDN).
 * Atten = 1/(att0 + att1*d + att2*d^2) for point/spot lights (directional: 1), and a light makes no
 * contribution beyond its Range (Range <= 0 is treated as no limit; zero denominator = no
 * attenuation). The spotlight factor is 1 inside the Theta cone, 0 outside Phi, and
 * ((cosPhi - cos rho)/(cosPhi - cosTheta))^Falloff between; Theta/Phi are total cone angles, the
 * runtime halves them before the cosines (MSDN "Light Types"); rho = cos of the angle between the
 * light axis and the light-to-vertex vector, both in camera space. Lighting is a per-vertex
 * approximation of the rasterizer's Gouraud shading, so per-pixel specular highlights are not
 * reproduced; pre-transformed (XYZRHW) and programmable vertex-shader draws are never lit, like
 * the D3D pipeline. */

enum { RS_LIGHTING = 137, RS_AMBIENT = 139, RS_COLORVERTEX = 141, RS_LOCALVIEWER = 142,
       RS_NORMALIZENORMALS = 143, RS_DIFFUSEMS = 145, RS_SPECULARMS = 146, RS_AMBIENTMS = 147,
       RS_EMISSIVEMS = 148 };
enum { MCS_MATERIAL = 0, MCS_COLOR1 = 1, MCS_COLOR2 = 2 };
enum { LIGHT_POINT = 1, LIGHT_SPOT = 2, LIGHT_DIRECTIONAL = 3 };

typedef struct {
    int type;
    float diff[4], spec[4], amb[4];
    float pos[3];      /* point/spot: light position in camera space */
    float axis[3];     /* normalized light axis in camera space: -norm(Direction * VIEW) */
    float range, falloff, att0, att1, att2, cos_theta, cos_phi;
} LitLight;

typedef struct {
    int has_normal, spec, normalize, local_viewer, nlights;
    int src_diffuse, src_ambient, src_specular, src_emissive;
    float power, amb_global[3];
    float vnm[9];                      /* normal -> camera space: inverse transpose of WORLD*VIEW */
    const float *material;             /* DevState.material (raw D3DMATERIAL8) */
    LitLight l[8];
} LightEnv;

static float lit_dot3(const float *a, const float *b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

static void lit_norm3(float *v) {
    float l = sqrtf(lit_dot3(v, v));
    if (l > 1e-9f) { v[0] /= l; v[1] /= l; v[2] /= l; }
    else { v[0] = v[1] = v[2] = 0.f; }
}

/* upper-left 3x3 of a row-major D3D 4x4 -> its inverse transpose (normals want (M^-1)^T per MSDN
   "Camera Space Transformations"); singular matrices fall back to identity */
static void lit_normal_matrix(const float *m, float *r) {
    float a = m[0], b = m[1], c = m[2], d = m[4], e = m[5], f = m[6], g = m[8], h = m[9], i = m[10];
    float cof[9] = { e * i - f * h, f * g - d * i, d * h - e * g,
                     c * h - b * i, a * i - c * g, b * g - a * h,
                     b * f - c * e, c * d - a * f, a * e - b * d };
    float det = a * cof[0] + b * cof[1] + c * cof[2];
    if (fabsf(det) < 1e-20f) {
        memset(r, 0, 9 * sizeof *r); r[0] = r[4] = r[8] = 1.f;
        return;
    }
    float s = 1.f / det;
    for (int k = 0; k < 9; k++) r[k] = cof[k] * s;
}

/* parse one raw D3DLIGHT8 and move it into camera space */
static void light_setup_one(const DevState *st, uint32_t i, LitLight *o) {
    const uint8_t *raw = st->light[i];
    const float PI = 3.14159265f;
    memcpy(&o->type, raw, 4);
    memcpy(o->diff, raw + 4, 16);
    memcpy(o->spec, raw + 20, 16);
    memcpy(o->amb, raw + 36, 16);
    memcpy(o->pos, raw + 52, 12);
    memcpy(&o->range, raw + 76, 4);
    memcpy(&o->falloff, raw + 80, 4);
    memcpy(&o->att0, raw + 84, 4);
    memcpy(&o->att1, raw + 88, 4);
    memcpy(&o->att2, raw + 92, 4);
    float theta, phi;
    memcpy(&theta, raw + 96, 4);
    memcpy(&phi, raw + 100, 4);
    const float *view = st->transform[2];
    float pos[3] = { o->pos[0] * view[0] + o->pos[1] * view[4] + o->pos[2] * view[8] + view[12],
                     o->pos[0] * view[1] + o->pos[1] * view[5] + o->pos[2] * view[9] + view[13],
                     o->pos[0] * view[2] + o->pos[1] * view[6] + o->pos[2] * view[10] + view[14] };
    memcpy(o->pos, pos, sizeof pos);
    float dir[3];
    memcpy(dir, raw + 64, 12);
    float axis[3] = { dir[0] * view[0] + dir[1] * view[4] + dir[2] * view[8],
                      dir[0] * view[1] + dir[1] * view[5] + dir[2] * view[9],
                      dir[0] * view[2] + dir[1] * view[6] + dir[2] * view[10] };
    lit_norm3(axis);
    o->axis[0] = -axis[0]; o->axis[1] = -axis[1]; o->axis[2] = -axis[2];
    /* Theta in [0, Phi], Phi in [0, pi] (MSDN); the total cone angles are halved before the cosines */
    if (!(theta >= 0)) theta = 0;
    if (!(phi >= theta)) phi = theta;
    if (phi > PI) phi = PI;
    o->cos_theta = cosf(theta * 0.5f);
    o->cos_phi = cosf(phi * 0.5f);
    if (!(o->range >= 0)) o->range = 0;              /* NaN/negative: no range limit */
    if (!(o->falloff == o->falloff)) o->falloff = 1.f;   /* NaN falloff: even falloff */
}

/* returns 1 when the draw must be lit (LIGHTING=1, fixed function, not pre-transformed) */
static int light_setup(const DevState *st, const FvfLayout *L, const float *wv, LightEnv *e) {
    memset(e, 0, sizeof *e);
    if (!st->rs[RS_LIGHTING]) return 0;   /* unlit draws keep their raw FVF colors */
    e->has_normal = L->has_normal;
    e->spec = st->rs[29] != 0;            /* SPECULARENABLE */
    e->normalize = st->rs[RS_NORMALIZENORMALS] != 0;
    e->local_viewer = st->rs[RS_LOCALVIEWER] != 0;
    e->power = st->material[16];
    if (!(e->power >= 0)) e->power = 0;   /* negative/NaN Power: flat specular */
    float ga[4];
    unpack_color(st->rs[RS_AMBIENT], ga);
    e->amb_global[0] = ga[0]; e->amb_global[1] = ga[1]; e->amb_global[2] = ga[2];
    lit_normal_matrix(wv, e->vnm);
    e->material = st->material;
    if (st->rs[RS_COLORVERTEX]) {         /* COLORVERTEX=0: every term comes from the material */
        e->src_diffuse = st->rs[RS_DIFFUSEMS] & 3;
        e->src_ambient = st->rs[RS_AMBIENTMS] & 3;
        e->src_specular = st->rs[RS_SPECULARMS] & 3;
        e->src_emissive = st->rs[RS_EMISSIVEMS] & 3;
    }
    for (uint32_t i = 0; i < 8; i++) {
        if (!st->light_enabled[i]) continue;
        int type;
        memcpy(&type, st->light[i], 4);
        if (type < LIGHT_POINT || type > LIGHT_DIRECTIONAL) continue;   /* unknown types are skipped */
        light_setup_one(st, i, &e->l[e->nlights++]);
    }
    return 1;
}

/* the color a lighting term uses: the material-source choice, falling back to the material when
   the FVF does not carry the requested vertex color (MSDN "Per-Vertex Color State") */
static const float *light_source(int src, const float *material, const float *c1, const float *c2,
                                 int has_c1, int has_c2) {
    if (src == MCS_COLOR1 && has_c1) return c1;
    if (src == MCS_COLOR2 && has_c2) return c2;
    return material;
}

/* Lights one fixed-function vertex in place (model-space position in CVert, normal read from the
   raw FVF). Diffuse RGB becomes emissive + ambient + diffuse; its alpha is the unlit alpha of the
   diffuse color source (lighting changes RGB only). Specular RGB becomes the specular sum when
   SPECULARENABLE; its alpha byte is never touched here - it carries the fog factor (audit W5),
   applied after lighting exactly like the D3D pipeline does. */
static void light_vertex(const LightEnv *e, const float *wv, const uint8_t *src, const FvfLayout *L, CVert *v) {
    float c1[4], c2[4];
    unpack_color(v->diffuse, c1);
    unpack_color(v->specular, c2);
    const float *cd = light_source(e->src_diffuse, e->material + 0, c1, c2, L->has_diffuse, L->has_specular);
    const float *ca = light_source(e->src_ambient, e->material + 4, c1, c2, L->has_diffuse, L->has_specular);
    const float *cs = light_source(e->src_specular, e->material + 8, c1, c2, L->has_diffuse, L->has_specular);
    const float *ce = light_source(e->src_emissive, e->material + 12, c1, c2, L->has_diffuse, L->has_specular);
    float out[4] = { ce[0], ce[1], ce[2], cd[3] };
    out[0] += e->amb_global[0] * ca[0];
    out[1] += e->amb_global[1] * ca[1];
    out[2] += e->amb_global[2] * ca[2];
    float nc[3] = { 0, 0, 0 };
    if (e->has_normal) {
        float n[3];
        memcpy(n, src + L->off_normal, 12);
        nc[0] = n[0] * e->vnm[0] + n[1] * e->vnm[3] + n[2] * e->vnm[6];
        nc[1] = n[0] * e->vnm[1] + n[1] * e->vnm[4] + n[2] * e->vnm[7];
        nc[2] = n[0] * e->vnm[2] + n[1] * e->vnm[5] + n[2] * e->vnm[8];
        if (e->normalize) lit_norm3(nc);
    }
    float vcam[3] = { v->x * wv[0] + v->y * wv[4] + v->z * wv[8] + wv[12],
                      v->x * wv[1] + v->y * wv[5] + v->z * wv[9] + wv[13],
                      v->x * wv[2] + v->y * wv[6] + v->z * wv[10] + wv[14] };
    float spec[3] = { 0, 0, 0 };
    for (int i = 0; i < e->nlights; i++) {
        const LitLight *l = &e->l[i];
        float atten = 1.f, spot = 1.f;
        float ldir[3];
        if (l->type == LIGHT_DIRECTIONAL) {
            ldir[0] = l->axis[0]; ldir[1] = l->axis[1]; ldir[2] = l->axis[2];
        } else {
            float ld[3] = { l->pos[0] - vcam[0], l->pos[1] - vcam[1], l->pos[2] - vcam[2] };
            float d = sqrtf(lit_dot3(ld, ld));
            if (d < 1e-9f) d = 1e-9f;   /* the light-vertex distance is positive by definition */
            if (l->range > 0 && d > l->range) continue;   /* beyond Range: no effect at all */
            ldir[0] = ld[0] / d; ldir[1] = ld[1] / d; ldir[2] = ld[2] / d;
            float denom = l->att0 + l->att1 * d + l->att2 * d * d;
            atten = denom > 1e-9f ? 1.f / denom : 1.f;   /* zero denominator: no attenuation */
            if (l->type == LIGHT_SPOT) {
                float rho = lit_dot3(l->axis, ldir);
                if (rho <= l->cos_phi) continue;   /* outside the outer cone: the light adds nothing */
                if (rho < l->cos_theta) {
                    float t = (l->cos_phi - rho) / (l->cos_phi - l->cos_theta);
                    spot = powf(t, l->falloff);
                }
            }
        }
        float w = atten * spot;
        out[0] += ca[0] * l->amb[0] * w;
        out[1] += ca[1] * l->amb[1] * w;
        out[2] += ca[2] * l->amb[2] * w;
        if (!e->has_normal) continue;
        float ndl = lit_dot3(nc, ldir);
        if (ndl > 0.f) {
            float dw = ndl * w;
            out[0] += cd[0] * l->diff[0] * dw;
            out[1] += cd[1] * l->diff[1] * dw;
            out[2] += cd[2] * l->diff[2] * dw;
        }
        if (e->spec) {
            float view[3];
            if (e->local_viewer) {
                view[0] = -vcam[0]; view[1] = -vcam[1]; view[2] = -vcam[2];
                lit_norm3(view);
            } else {
                view[0] = 0.f; view[1] = 0.f; view[2] = 1.f;   /* viewpoint at infinity on the z axis */
            }
            float h[3] = { view[0] + ldir[0], view[1] + ldir[1], view[2] + ldir[2] };
            lit_norm3(h);
            float ndh = lit_dot3(nc, h);
            if (ndh > 0.f) {
                float sw = powf(ndh, e->power) * w;
                spec[0] += cs[0] * l->spec[0] * sw;
                spec[1] += cs[1] * l->spec[1] * sw;
                spec[2] += cs[2] * l->spec[2] * sw;
            }
        }
    }
    v->diffuse = pack_color(out);
    if (e->spec) {
        float spc[4] = { spec[0], spec[1], spec[2], (float)(v->specular >> 24) / 255.f };
        v->specular = (v->specular & 0xFF000000u) | (pack_color(spc) & 0x00FFFFFFu);
    }
}

/* ------------------------------------------------------------------ textures */

static uint32_t sampler_key(const uint32_t *tss) {
    uint32_t mag = tss[16] >= 2, min = tss[17] >= 2, mip = tss[18];
    uint32_t au = tss[13] & 7, av = tss[14] & 7;
    return mag | min << 1 | (mip & 3) << 2 | au << 4 | av << 7;   /* < 1024 */
}

/* send a texture's contents if they changed since the last upload */
/* DXT textures go to the GPU as BC blocks when it can sample them: 4-8x less GPU memory than RGBA8 (a match
   needs hundreds of MB uncompressed, more than some GPUs/browsers give a page). WebGPU wants whole blocks,
   so the base level must be a multiple of 4; other textures are converted. */
static uint32_t bc_format(const Texture *t) {
    if (!g_gpu_bc || !format_is_dxt(t->format) || t->lw[0] % 4 || t->lh[0] % 4) return TEXFMT_RGBA8;
    return t->format == FMT_DXT1 ? TEXFMT_BC1 : t->format <= FMT_DXT3 ? TEXFMT_BC2 : TEXFMT_BC3;
}

/* The browser opts in by default; native and Node callers may set PORT_CUBE_RENDER=1. */
static int cube_render_enabled(void) {
    static int cached = -1;
    if (cached < 0) { const char *p = getenv("PORT_CUBE_RENDER"); cached = p && !strcmp(p, "1"); }
    return cached;
}

/* Commands own their bytes. Large images are sent as bounded face/mip row
   stripes; the browser drains queued chunks during the upload to bound RAM. */
#define TEX_STRIPE_BYTES (4u<<20)
static void texture_header(CmdUploadTex *c,const Texture *t,uint32_t faces,uint32_t fmt) {
    c->id=t->gpu_id; c->levels=t->levels; c->faces=faces; c->fmt=fmt;
    for (uint32_t l=0;l<t->levels;l++) { c->w[l]=t->lw[l]; c->h_[l]=t->lh[l]; }
}
static void texture_rows(Device *d,const Texture *t,uint32_t f,uint32_t l,uint32_t y,uint32_t rows,
                         uint32_t fmt,uint8_t *out) {
    uint32_t w=t->lw[l], bc=fmt>=TEXFMT_BC1 && fmt<=TEXFMT_BC3;
    uint32_t src_bc=format_is_dxt(t->format), src_y=src_bc ? y/4 : y;
    const uint8_t *src=HP(t->mem[f][l]+src_y*t->pitch[l]);
    if (bc) {
        uint32_t bs=fmt==TEXFMT_BC1?8:16, bw=(w+3)/4, bh=(rows+3)/4;
        for (uint32_t i=0;i<bh;i++) memcpy(out+(size_t)i*bw*bs,src+(size_t)i*t->pitch[l],(size_t)bw*bs);
    } else {
        const uint8_t *pal=d->st.palette_current<1024 ? g_palettes[d->st.palette_current] : NULL;
        if (!texture_to_rgba8(t->format,src,t->pitch[l],w,rows,out,pal)) {
            static int warned;
            if (!warned++) fprintf(stderr,"[render] unsupported texture format %x\n",t->format);
            memset(out,255,(size_t)w*rows*4);
        }
    }
}
static int sync_texture(Device *d, Texture *t) {
    uint32_t faces=t->type==RT_CUBETEXTURE?6:1;
    if (!t->levels || t->levels>14 || t->faces!=faces || !t->width || !t->height ||
        (faces==6 && t->width!=t->height)) return 0;
    if (t->sent_version==t->version) return 1;
    uint32_t fmt=(faces==6 && (t->usage&1))?TEXFMT_SURF_RGBA8:bc_format(t);
    uint32_t bc=fmt>=TEXFMT_BC1 && fmt<=TEXFMT_BC3, bs=fmt==TEXFMT_BC1?8:16;
    uint64_t per_face=0;
    for (uint32_t l=0;l<t->levels;l++) {
        uint32_t w=t->lw[l],h=t->lh[l];
        uint32_t ew=t->width>>l?t->width>>l:1, eh=t->height>>l?t->height>>l:1;
        if (!w || !h || w>8192 || h>8192 || w!=ew || h!=eh) return 0;
        uint32_t src_bc=format_is_dxt(t->format), src_rows=src_bc?(h+3)/4:h;
        uint64_t minrow=src_bc?(uint64_t)((w+3)/4)*(t->format==FMT_DXT1?8:16):
            ((uint64_t)w*format_bpp(t->format)+7)/8;
        if (t->pitch[l]<minrow) return 0;
        per_face+=bc?(uint64_t)((w+3)/4)*((h+3)/4)*bs:(uint64_t)w*h*4;
        for (uint32_t f=0;f<faces;f++) {
            uint64_t span=(uint64_t)t->pitch[l]*src_rows;
            if (!t->mem[f][l] || (uint64_t)t->mem[f][l]+span>GUEST_SPACE) return 0;
        }
    }
    uint64_t total=per_face*faces;
    if (total<=TEX_STRIPE_BYTES) {
        CmdUploadTex *c=cmd_alloc(CMD_UPLOAD_TEX,sizeof *c+(size_t)total);
        if (!c) return 0;
        texture_header(c,t,faces,fmt);
        uint8_t *out=(uint8_t *)(c+1);
        for (uint32_t f=0;f<faces;f++) for (uint32_t l=0;l<t->levels;l++) {
            uint32_t w=t->lw[l],h=t->lh[l];
            texture_rows(d,t,f,l,0,h,fmt,out);
            out+=bc?(size_t)((w+3)/4)*((h+3)/4)*bs:(size_t)w*h*4;
        }
        cmd_end();
    } else {
#ifdef __EMSCRIPTEN__
        /* Keep existing commands ordered before the first region. */
        cmd_flush(0);
#endif
        for (uint32_t f=0;f<faces;f++) for (uint32_t l=0;l<t->levels;l++) {
            uint32_t w=t->lw[l],h=t->lh[l],src_bc=format_is_dxt(t->format);
            uint32_t rowbytes=bc?((w+3)/4)*bs:w*4;
            uint32_t block_rows=TEX_STRIPE_BYTES/rowbytes;
            if (!block_rows) return 0;
            uint32_t rows_per=bc?block_rows*4:block_rows;
            if (src_bc && !bc && rows_per>=4) rows_per=(rows_per/4)*4;
            if (src_bc && !bc && rows_per<4 && h>rows_per) return 0;
            for (uint32_t y=0;y<h;) {
                uint32_t rows=h-y<rows_per?h-y:rows_per;
                size_t n=bc?(size_t)rowbytes*((rows+3)/4):(size_t)rowbytes*rows;
                CmdUploadTexRegion *c=cmd_alloc(CMD_UPLOAD_TEX_REGION,sizeof *c+n);
                if (!c) return 0; /* already-issued regions never bind while version is unsent */
                texture_header(&c->tex,t,faces,fmt);
                c->face=f; c->level=l; c->y=y; c->rows=rows;
                texture_rows(d,t,f,l,y,rows,fmt,(uint8_t *)(c+1));
                cmd_end();
#ifdef __EMSCRIPTEN__
                cmd_flush(0);
                while (web_queued_chunks()>=8) usleep(1000);
#endif
                y+=rows;
            }
        }
    }
    t->sent_version=t->version; return 1;
}

/* Before sampling a render-target cube, assemble the current GPU surfaces. */
static int sync_cube_render_targets(Texture *t) {
    CmdCopyCubeRT *c=cmd_alloc(CMD_COPY_CUBE_RT,sizeof *c);
    if (!c) return 0;
    c->id=t->gpu_id; c->levels=t->levels;
    for (uint32_t f=0;f<6;f++) for (uint32_t l=0;l<t->levels;l++) {
        c->surface[f][l]=t->rt_surface_ids[f][l];
    }
    cmd_end();
    return 1;
}

/* ------------------------------------------------------------------ clears */

static void clear_quad(Device *d, float x1, float y1, float x2, float y2, uint32_t flags, uint32_t color, float z) {
    if (x2 <= x1 || y2 <= y1 || !(flags & 3)) return;
    CmdDraw *c = cmd_alloc(CMD_DRAW, sizeof *c + 6 * sizeof(CVert));
    if (!c) return;
    c->key = (PKey){ 0, 2, 1, 1, 1, (flags & 2) ? 1u : 0u, 8, 1, (flags & 1) ? 0xFu : 0u, TOPO_TRIANGLES, 0 };
    c->full_viewport = 1;
    c->minz = 0.f; c->maxz = 1.f;
    c->capture_index = -1;
    for (int i = 0; i < 4; i++) c->samp_key[i] = sampler_key(d->st.tss[i]);
    c->u.vp[2] = (float)g_tgt_lw; c->u.vp[3] = (float)g_tgt_lh;
    c->u.flags[0] = 1;   /* pre-transformed */
    c->u.st0[0] = 1;     /* stage disabled: output = diffuse */
    c->nverts = 6;
    CVert *v = (CVert *)(c + 1);
    const float px[6] = { x1, x2, x1, x1, x2, x2 }, py[6] = { y1, y1, y2, y2, y1, y2 };
    for (int i = 0; i < 6; i++) { v[i].x = px[i] - 0.5f; v[i].y = py[i] - 0.5f; v[i].z = z; v[i].w = 1.f; v[i].diffuse = color; }
    cmd_end();
}

static void rec_clear_impl(Device *d, uint32_t count, uint32_t rects, uint32_t flags, uint32_t color, float z,
                      uint32_t stencil) {
    if (!select_target(d)) return;
    const DevState *st = &d->st;
    float vx1 = (float)st->viewport.x, vy1 = (float)st->viewport.y;
    float vx2 = vx1 + (float)(st->viewport.w ? st->viewport.w : g_tgt_lw);
    float vy2 = vy1 + (float)(st->viewport.h ? st->viewport.h : g_tgt_lh);
    int full = !count && vx1 <= 0 && vy1 <= 0 && vx2 >= (float)g_tgt_lw && vy2 >= (float)g_tgt_lh;
    if (full) {
        CmdClear *c = cmd_alloc(CMD_CLEAR, sizeof *c);
        if (!c) return;
        c->flags = flags & 7; c->color = color; c->z = z; c->stencil = stencil;
        cmd_end();
        return;
    }
    /* Direct3D clears only the viewport (or the given rects): draw quads instead of a pass clear */
    for (uint32_t i = 0; i < (count ? count : 1); i++) {
        float x1 = vx1, y1 = vy1, x2 = vx2, y2 = vy2;
        if (count && rects) {
            int32_t r[4];
            memcpy(r, HP(rects + 16 * i), 16);
            if (r[0] > x1) x1 = (float)r[0];
            if (r[1] > y1) y1 = (float)r[1];
            if (r[2] < x2) x2 = (float)r[2];
            if (r[3] < y2) y2 = (float)r[3];
        }
        clear_quad(d, x1, y1, x2, y2, flags, color, z);
    }
}

/* ------------------------------------------------------------------ draw */

static void rec_draw_impl(Device *d, uint32_t prim, uint32_t prim_count, uint32_t start_vertex, uint32_t num_vertices,
                     const uint8_t *vertices_up, uint32_t up_stride, const void *indices, int index32,
                     uint32_t start_index) {
    DevState *st = &d->st;
    (void)num_vertices;
    if (!prim_count) return;
    Shader *sh = (st->vs & 1) ? shader_get(st->vs) : NULL;   /* vertex shader handle (FVFs have bit 0 clear) */
    if ((st->vs & 1) && !sh) return;
    g_f_drawn++;
    if (!select_target(d)) return;
    if (g_snap_detail) {
        Texture *t0 = com_data(st->texture[0]), *t1 = com_data(st->texture[1]);
        fprintf(stderr, "[draw] #%04u vs %x ps %x prim %u n %u | tex0 %s fmt %x tex1 %s fmt %x | tss0 op %u a %u,%u aop %u | "
                "tss1 op %u | blend %u %u/%u atest %u\n", g_f_drawn - 1, st->vs, st->ps, prim, prim_count,
                t0 ? (t0->type == RT_TEXTURE ? "2d" : "cube") : "-", t0 ? t0->format : 0,
                t1 ? (t1->type == RT_TEXTURE ? "2d" : "cube") : "-", t1 ? t1->format : 0,
                st->tss[0][1], st->tss[0][2], st->tss[0][3], st->tss[0][4], st->tss[1][1], st->rs[27], st->rs[19],
                st->rs[20], st->rs[15]);
    }

    FvfLayout L;
    fvf_layout(sh ? 0x2 /* XYZ: transformed by the shader */ : st->vs, &L);
    const uint8_t *vb = NULL;
    uint32_t stride;
    if (vertices_up) { vb = vertices_up; stride = up_stride; }
    else {
        Buffer *b = com_data(st->stream_vb[0]);
        if (!b && !sh) return;
        if (b) vb = HP(b->mem);
        stride = st->stream_stride[0];
    }
    if (!stride && !sh) stride = L.stride;
    uint32_t base = indices && !vertices_up ? st->base_vertex : 0;

    /* expand to a list topology */
    uint32_t topo, n = 0;
    uint32_t cap = prim_count * 3 + 4;
    uint32_t *idx = malloc(4 * cap);
#define IDX(i) (indices ? (index32 ? ((const uint32_t *)indices)[start_index + (i)] : ((const uint16_t *)indices)[start_index + (i)]) + base : start_vertex + (i))
    switch (prim) {
    case 1: topo = TOPO_POINTS; for (uint32_t i = 0; i < prim_count; i++) idx[n++] = IDX(i); break;
    case 2: topo = TOPO_LINES; for (uint32_t i = 0; i < 2 * prim_count; i++) idx[n++] = IDX(i); break;
    case 3: topo = TOPO_LINES;
        for (uint32_t i = 0; i < prim_count; i++) { idx[n++] = IDX(i); idx[n++] = IDX(i + 1); } break;
    case 4: topo = TOPO_TRIANGLES; for (uint32_t i = 0; i < 3 * prim_count; i++) idx[n++] = IDX(i); break;
    case 5: topo = TOPO_TRIANGLES;
        for (uint32_t i = 0; i < prim_count; i++) {
            if (i & 1) { idx[n++] = IDX(i + 1); idx[n++] = IDX(i); idx[n++] = IDX(i + 2); }
            else { idx[n++] = IDX(i); idx[n++] = IDX(i + 1); idx[n++] = IDX(i + 2); }
        }
        break;
    case 6: topo = TOPO_TRIANGLES;
        for (uint32_t i = 0; i < prim_count; i++) { idx[n++] = IDX(0); idx[n++] = IDX(i + 1); idx[n++] = IDX(i + 2); }
        break;
    default: free(idx); return;
    }
#undef IDX

    /* textures first: an upload is its own command and must precede the draw */
    uint32_t failed_texture_mask=0;
    for (int s=0;s<4;s++) {
        Texture *t=com_data(st->texture[s]);
        if (t && t->type==RT_TEXTURE && (t->usage&1) && !d3d_sync_texture_rt(d,t)) {
            failed_texture_mask|=1u<<s;
        } else if (t && t->type==RT_TEXTURE && !(t->usage&1)) {
            if (!sync_texture(d,t)) failed_texture_mask|=1u<<s;
        } else if (t && t->type==RT_CUBETEXTURE && cube_render_enabled()) {
            if (!d3d_sync_texture_rt(d,t) || !sync_texture(d,t) || ((t->usage&1) && !sync_cube_render_targets(t))) failed_texture_mask|=1u<<s;
        }
    }

    CmdDraw *c = cmd_alloc(CMD_DRAW, sizeof *c + (size_t)n * sizeof(CVert));
    if (!c) { free(idx); return; }
    CVert *cv = (CVert *)(c + 1);
    c->nverts = n;
    c->capture_index = g_snap_detail ? (int32_t)(g_f_drawn - 1) : -1;
    int route_fvf = route_fvf_texcoords_enabled(sh != NULL, st->ps, st->tss[0][11], st->tss[1][11]);

    /* fog setup (audit W5): fixed-function draws compute the factor from the render states; vertex
       shader draws use the shader's own oFog output (the sea shaders compute exp fog there).
       Pre-transformed (XYZRHW) draws are never fogged, like the D3D vertex pipeline that cannot fog
       already-screen-space vertices; draws without fog keep their original specular alpha. */
    uint32_t fog_mode = 0;
    int fog_vs = 0, fog_range = 0;
    float fog_wv[16], fog_start = 0, fog_end = 0, fog_density = 0;
    /* per-vertex fixed-function lighting (audit W2): LIGHTING=1 replaces the vertex colors of every
       non-pre-transformed draw (normals add the diffuse/specular terms; without them it is
       ambient-only). Pre-transformed (XYZRHW) and vertex-shader draws are never lit, like the D3D
       pipeline; fog and lighting share the WORLD*VIEW matrix. */
    LightEnv lit;
    int lit_on = 0;
    if (!sh) {
        fog_mode = L.pos_type == 0x4 ? FOG_NONE : draw_fog_mode(st);
        if (fog_mode) {
            fog_start = fog_state_float(st, RS_FOGSTART);
            fog_end = fog_state_float(st, RS_FOGEND);
            fog_density = fog_state_float(st, RS_FOGDENSITY);
            fog_range = st->rs[RS_RANGEFOGENABLE] != 0;
        }
        if (fog_mode || L.pos_type != 0x4) mat_mul(st->transform[256], st->transform[2], fog_wv);
        if (L.pos_type != 0x4) lit_on = light_setup(st, &L, fog_wv, &lit);
    } else if (st->rs[RS_FOGENABLE]) {
        fog_vs = vs_writes_ofog(sh);
    }

    if (sh) {
        VsStreams vss;
        memset(&vss, 0, sizeof vss);
        if (vertices_up) { vss.data[0] = vertices_up; vss.stride[0] = up_stride; }
        else
            for (int s = 0; s < 16; s++) {
                Buffer *sb = com_data(st->stream_vb[s]);
                if (sb) { vss.data[s] = HP(sb->mem); vss.stride[s] = st->stream_stride[s]; }
            }
        float wv[16], ff_mvp[16];
        mat_mul(st->transform[256], st->transform[2], wv);
        mat_mul(wv, st->transform[3], ff_mvp);
        vss.ff_mvp = ff_mvp;
        /* run the shader once per distinct vertex: over the referenced range when it is compact */
        uint32_t lo = 0xFFFFFFFFu, hi = 0;
        for (uint32_t i = 0; i < n; i++) { if (idx[i] < lo) lo = idx[i]; if (idx[i] > hi) hi = idx[i]; }
        uint32_t range = n ? hi - lo + 1 : 0;
        int use_range = range <= 2 * n + 64;
        CVert *tmp = use_range ? malloc(sizeof(CVert) * (range ? range : 1)) : NULL;
        for (uint32_t i = 0; i < (use_range ? range : n); i++) {
            VsOut o;
            extern int vs_trace;
            vs_trace = g_snap_detail && i == 0 && st->vs == g_trace_vs;
            vs_run(sh, (const float (*)[4])st->vs_const, &vss, use_range ? lo + i : idx[i], &o);
            vs_trace = 0;
            CVert *v = use_range ? &tmp[i] : &cv[i];
            v->x = o.pos[0]; v->y = o.pos[1]; v->z = o.pos[2]; v->w = o.pos[3];
            v->diffuse = pack_color(o.d0); v->specular = pack_color(o.d1);
            if (fog_vs) v->specular = (v->specular & 0x00FFFFFFu) | fog_alpha_byte(o.fog[0]);
            memcpy(v->tc, o.tex, sizeof v->tc);
        }
        if (use_range) { for (uint32_t i = 0; i < n; i++) cv[i] = tmp[idx[i] - lo]; free(tmp); }
    } else {
        for (uint32_t i = 0; i < n; i++) {
            const uint8_t *src = vb + (size_t)idx[i] * stride;
            convert_vertex(src, &L, &cv[i]);
            if (route_fvf) route_fvf_texcoords(src, &L, &cv[i], st->tss[0][11], st->tss[1][11]);
            if (lit_on) light_vertex(&lit, fog_wv, src, &L, &cv[i]);   /* audit W2: lighting first */
            if (fog_mode) {   /* audit W5: the factor lands in the specular alpha after lighting */
                float f = fog_factor(fog_mode, fog_depth(fog_wv, cv[i].x, cv[i].y, cv[i].z, fog_range),
                                     fog_start, fog_end, fog_density);
                cv[i].specular = (cv[i].specular & 0x00FFFFFFu) | fog_alpha_byte(f);
            }
        }
    }
    free(idx);

    for (int s = 0; s < 4; s++) {
        Texture *t = com_data(st->texture[s]);
        c->samp_key[s] = sampler_key(st->tss[s]);
        if (failed_texture_mask & (1u<<s)) continue;
        if (t && t->type == RT_TEXTURE && (t->usage & 1)) {
            if (t->rt_surface_ids[0][0]) { c->slot_kind[s] = TS_RTSURF; c->slot_id[s] = t->rt_surface_ids[0][0]; }
        } else if (t && t->type == RT_TEXTURE && t->sent_version == t->version) {
            c->slot_kind[s] = TS_TEX; c->slot_id[s] = t->gpu_id;
        } else if (t && t->type == RT_CUBETEXTURE && cube_render_enabled() && t->sent_version == t->version) {
            c->slot_kind[s] = TS_CUBE; c->slot_id[s] = t->gpu_id;
        }
    }
    c->pixel_shader = st->ps;

    Uniforms *u = &c->u;
    if (!sh && L.pos_type != 0x4) {
        float wv[16];
        mat_mul(st->transform[256], st->transform[2], wv);    /* WORLD * VIEW */
        mat_mul(wv, st->transform[3], u->mvp);                /* * PROJECTION */
    }
    u->vp[0] = (float)st->viewport.x; u->vp[1] = (float)st->viewport.y;
    u->vp[2] = (float)(st->viewport.w ? st->viewport.w : g_tgt_lw);
    u->vp[3] = (float)(st->viewport.h ? st->viewport.h : g_tgt_lh);
    u->flags[0] = sh ? 2 : L.pos_type == 0x4;
    u->flags[1] = st->rs[15] ? st->rs[25] : 0;                 /* ALPHATESTENABLE ? ALPHAFUNC */
    u->flags[2] = st->rs[29] != 0;                  /* SPECULARENABLE: fs adds specular.rgb */
    u->flags[3] = cube_render_enabled() ? 2u : 0u; /* real cubemap; otherwise legacy gradient */
    /* The old flags[3] no-normals ambient hack is retired: audit W2 lights no-normal draws on
       the CPU as well (emissive + global/per-light ambient with a zero normal). */
    pack_stages(u, st, sh ? 1 : 0, route_fvf);
    unpack_color(st->rs[60], u->tfactor);
    u->misc[0] = (st->rs[24] & 255) / 255.f;
    if (fog_mode || fog_vs) {   /* the fragment stages mix u.fog.rgb by the specular-alpha factor */
        unpack_color(st->rs[RS_FOGCOLOR], u->fog);
        u->fog[3] = 1.f;
    }
    for (int i = 0; i < 4; i++) u->mat_diffuse[i] = 1.f;
    memcpy(u->psc, st->ps_const, sizeof u->psc);
    for (int s = 0; s < 4; s++) {
        memcpy(u->bem[s], &st->tss[s][7], 16);        /* BUMPENVMAT00, 01, 10, 11 (float bits) */
        memcpy(&u->bel[s][0], &st->tss[s][22], 4);    /* BUMPENVLSCALE */
        memcpy(&u->bel[s][1], &st->tss[s][23], 4);    /* BUMPENVLOFFSET */
    }

    PKey k = { st->rs[27] != 0, st->rs[19], st->rs[20], st->rs[171] ? st->rs[171] : 1, st->rs[7] != 0 && st->depth_stencil,
               st->rs[14], st->rs[23], st->rs[22], st->rs[168] & 0xF, topo, st->ps };
    if (L.pos_type == 0x4) k.cull = 1;  /* keep 2D simple: no culling for pre-transformed vertices */
    /* Pass D3DCULL through: the WebGPU pipeline uses CW front and maps CW to front culling. */
    c->key = k;
    c->vp[0] = (float)st->viewport.x; c->vp[1] = (float)st->viewport.y;
    c->vp[2] = (float)(st->viewport.w ? st->viewport.w : g_tgt_lw);
    c->vp[3] = (float)(st->viewport.h ? st->viewport.h : g_tgt_lh);
    c->minz = st->viewport.minz;
    c->maxz = st->viewport.maxz > st->viewport.minz ? st->viewport.maxz : 1.f;
    cmd_end();
}

/* ------------------------------------------------------------------ frames, readback, resources */

static int rec_init(Device *d) {
    (void)d;
#ifdef __EMSCRIPTEN__
    while (!web_gpu_ready()) usleep(1000);   /* the page creates the WebGPU device before starting the game */
    return 1;
#else
    return gpu_init_native();
#endif
}

static void rec_present_impl(Device *d) {
    CmdPresent *c = cmd_alloc(CMD_PRESENT, sizeof *c);
    if (!c) return;
    c->frame = d->frame;
    c->screenshot = (uint32_t)want_screenshot(d->frame);
    cmd_end();
#ifdef __EMSCRIPTEN__
    /* During a save-load episode the frames must not race the display: a load is ~1300 ordinary
       frames, and waiting for requestAnimationFrame in each would stretch it to 60 fps of wall
       time. Ship load frames without the frame-end marker - the page's 1 ms pump runs them (the
       loading screen still reaches the canvas at whatever rate it composites) - and skip the
       frame-depth wait. The episode frames still need loose backpressure: the pump executes a
       few hundred frames per second, and a free-running game thread queues whole frames faster
       than that - the unbounded queue aborted on memory growth ~1 s into the first browser test. */
    int unpaced = port_load_pacing_active();
    cmd_flush(!unpaced);
#else
    cmd_flush(1);
#endif
    g_target_sent = 0;   /* the executor ends every frame on the back buffer */
    g_f_drawn = 0;
#ifdef __EMSCRIPTEN__
    if (unpaced) {
        while (web_queued_chunks() >= 64) usleep(1000);   /* cap the in-flight load frames */
        return;
    }
    double t0 = host_seconds();
    while (web_queued_frames() >= 2) usleep(1000);   /* don't run ahead of the display */
    double dt = host_seconds() - t0;
    static uint32_t pn;
    static double ptotal;
    pn++; ptotal += dt;
    if (g_log && (dt > 0.05 || pn % 600 == 0))
        LOG("[present-wait] #%u waited %.3f s (total %.2f s over %u)\n", pn, dt, ptotal, pn);
#endif
}

static int rec_readback_impl(Device *d, Surface *s) {
    int is_bb = com_data(d->backbuffer) == s;
    if (!is_bb && !s->is_rt) return 1;
    uint64_t bytes=(uint64_t)s->pitch*s->height+16;
    if (bytes>UINT32_MAX) return 0;
    if (!s->mem) s->mem=heap_try_alloc((uint32_t)bytes,1);
    if (!s->mem) return 0;
    volatile int done = 0;
    CmdReadback *c = cmd_alloc(CMD_READBACK, sizeof *c);
    if (!c) { fprintf(stderr,"[render] readback skipped: no command memory\n"); return 0; }
    c->id = is_bb ? 0 : s->gpu_id;
    c->w = s->width; c->h_ = s->height; c->fmt = s->format; c->pitch = s->pitch; c->guest_mem = s->mem;
    c->done_ptr = (uint64_t)(uintptr_t)&done;
    cmd_end();
    cmd_flush(0);
    double t0 = host_seconds();
    while (!__atomic_load_n(&done, __ATOMIC_ACQUIRE)) usleep(200);   /* natively it already ran */
    double dt = host_seconds() - t0;
    static uint32_t n;
    static double total;
    n++; total += dt;
    if (g_log && (dt > 0.05 || n % 100 == 0))
        LOG("[readback] #%u waited %.3f s (total %.2f s over %u), %ux%u fmt %x %s\n",
            n, dt, total, n, s->width, s->height, s->format, is_bb ? "backbuffer" : "rt");
    return __atomic_load_n(&done,__ATOMIC_ACQUIRE)>0;
}

static int rec_upload_surface_impl(Device *d, Surface *s) {
    if (!s->mem || s->is_depth || com_data(d->backbuffer) == s) return 1;
    CmdUploadSurf *c = cmd_alloc(CMD_UPLOAD_SURF, sizeof *c + (size_t)s->width * s->height * 4);
    if (!c) { fprintf(stderr,"[render] surface upload skipped: no command memory\n"); return 0; }
    c->id = s->gpu_id; c->w = s->width; c->h_ = s->height;
    if (!texture_to_rgba8(s->format, HP(s->mem), s->pitch, s->width, s->height, (uint8_t *)(c + 1), NULL))
        memset(c + 1, 0, (size_t)s->width * s->height * 4);
    cmd_end();
    return 1;
}

static void rec_destroy_texture_impl(Texture *t) {
    CmdDestroy *c = cmd_alloc(CMD_DESTROY_TEX, sizeof *c);
    if (!c) return; /* leak GPU resource rather than dereference a null command */
    c->id = t->gpu_id;
    cmd_end();
}

static void rec_destroy_surface_impl(Surface *s) {
    CmdDestroy *c = cmd_alloc(CMD_DESTROY_SURF, sizeof *c);
    if (!c) return;
    c->id = s->gpu_id;
    cmd_end();
}

/* ------------------------------------------------------------------ locked entry points */

static void rec_clear(Device *d, uint32_t count, uint32_t rects, uint32_t flags, uint32_t color, float z, uint32_t stencil) {
    rec_enter(); rec_clear_impl(d, count, rects, flags, color, z, stencil); rec_leave();
}
static void rec_draw(Device *d, uint32_t prim, uint32_t prim_count, uint32_t start_vertex, uint32_t num_vertices,
                     const uint8_t *vertices_up, uint32_t up_stride, const void *indices, int index32, uint32_t start_index) {
    rec_enter();
    rec_draw_impl(d, prim, prim_count, start_vertex, num_vertices, vertices_up, up_stride, indices, index32, start_index);
    rec_leave();
}
static void rec_present(Device *d) { rec_enter(); rec_present_impl(d); rec_leave(); }
static int rec_readback(Device *d, Surface *s) { rec_enter(); int ok=rec_readback_impl(d, s); rec_leave(); return ok; }
static int rec_upload_surface(Device *d, Surface *s) { rec_enter(); int ok=rec_upload_surface_impl(d, s); rec_leave(); return ok; }
static void rec_destroy_texture(Texture *t) { rec_enter(); rec_destroy_texture_impl(t); rec_leave(); }
static void rec_destroy_surface(Surface *s) { rec_enter(); rec_destroy_surface_impl(s); rec_leave(); }

RenderBackend g_render_gpu = { "webgpu", rec_init, rec_clear, rec_draw, rec_present, rec_destroy_texture,
                               rec_readback, rec_upload_surface, rec_destroy_surface };
