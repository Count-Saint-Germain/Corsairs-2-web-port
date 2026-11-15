/* Direct3D 8: IDirect3D8, IDirect3DDevice8 and resources, with complete state tracking.
 * Drawing goes to g_render (headless by default). */
#include "d3d8.h"
#include "render.h"

#include <math.h>
#include <pthread.h>
#include <unistd.h>

#define W(name) static void name(CPU *c)
#define D3DERR_NOTAVAILABLE 0x8876086Au
#define D3DERR_INVALIDCALL 0x8876086Cu

RenderBackend *g_render = &g_render_headless;
uint8_t g_palettes[1024][1024];   /* PALETTEENTRY r, g, b, flags (alpha) x 256 per palette */

/* ------------------------------------------------------------------ formats */

int format_is_dxt(uint32_t f) { return f >= FMT_DXT1 && f <= FMT_DXT5; }

uint32_t format_bpp(uint32_t f) {
    switch (f) {
    case FMT_A8R8G8B8: case FMT_X8R8G8B8: case FMT_D32: case FMT_D24S8: case FMT_D24X8: case FMT_INDEX32: return 32;
    case FMT_R8G8B8: return 24;
    case FMT_R5G6B5: case FMT_X1R5G5B5: case FMT_A1R5G5B5: case FMT_A4R4G4B4: case FMT_A8L8: case FMT_V8U8:
    case FMT_D16: case FMT_INDEX16: return 16;
    case FMT_A8: case FMT_P8: case FMT_L8: return 8;
    case FMT_DXT1: return 4;
    case FMT_DXT2: case FMT_DXT3: case FMT_DXT4: case FMT_DXT5: return 8;
    default: return 32;
    }
}

static uint32_t level_pitch(uint32_t f, uint32_t w) {
    if (format_is_dxt(f)) return ((w + 3) / 4) * (f == FMT_DXT1 ? 8 : 16);
    return (w * format_bpp(f) / 8 + 3) & ~3u;
}

static uint32_t level_rows(uint32_t f, uint32_t h) { return format_is_dxt(f) ? (h + 3) / 4 : h; }

static int supported_format(uint32_t f) {
    switch (f) {
    case FMT_A8R8G8B8: case FMT_X8R8G8B8: case FMT_R5G6B5: case FMT_X1R5G5B5: case FMT_A1R5G5B5:
    case FMT_A4R4G4B4: case FMT_A8: case FMT_L8: case FMT_A8L8: case FMT_P8:
    case FMT_DXT1: case FMT_DXT2: case FMT_DXT3: case FMT_DXT4: case FMT_DXT5:
    case FMT_D16: case FMT_D24S8: case FMT_D24X8: case FMT_D32: return 1;
    default: return 0;
    }
}

/* ------------------------------------------------------------------ interfaces (defined below) */

static ComInterface IDirect3D8_i, IDirect3DDevice8_i, IDirect3DTexture8_i, IDirect3DCubeTexture8_i,
    IDirect3DSurface8_i, IDirect3DVertexBuffer8_i, IDirect3DIndexBuffer8_i, IDirect3DSwapChain8_i,
    IDirect3DVolumeTexture8_i;

static uint32_t g_d3d_object;
static uint32_t g_device_object;  /* the most recently created device: what resources report as their device */
Device *g_device;                 /* ...and its state */

/* ------------------------------------------------------------------ IDirect3D8 */

static const struct { uint32_t w, h; } g_modes[] = {
    { 640, 480 }, { 800, 600 }, { 1024, 768 }, { 1152, 864 }, { 1280, 720 }, { 1280, 960 }, { 1280, 1024 },
    { 1600, 1200 },
};
#define NMODES (sizeof g_modes / sizeof g_modes[0])

W(d3d_GetAdapterCount) { RET(1, 1); }
W(d3d_RegisterSoftwareDevice) { RET(2, E_FAIL); }

W(d3d_GetAdapterIdentifier) {
    uint32_t p = ARG(3);
    memset(HP(p), 0, 1068);
    strcpy((char *)HP(p), "nv4_disp.dll");
    strcpy((char *)HP(p + 512), "NVIDIA GeForce 6800 GT");
    W64(p + 1024, 0x0006000E000A1700ull);  /* driver version 6.14.10.5888 */
    W32(p + 1032, 0x10DE);                 /* vendor: NVIDIA */
    W32(p + 1036, 0x0045);                 /* GeForce 6800 GT, listed in videocards.xml */
    W32(p + 1040, 0);
    W32(p + 1044, 0xA2);
    W32(p + 1064, 1);                      /* WHQL */
    RET(4, S_OK);
}

static int mode_format_ok(uint32_t f) { return f == FMT_X8R8G8B8 || f == FMT_R5G6B5 || f == 0; }
W(d3d_GetAdapterModeCount) { RET(2, NMODES * 2); }
W(d3d_EnumAdapterModes) {
    uint32_t i = ARG(2), p = ARG(3);
    if (i >= NMODES * 2) RET(4, D3DERR_INVALIDCALL);
    W32(p, g_modes[i % NMODES].w); W32(p + 4, g_modes[i % NMODES].h); W32(p + 8, 60);
    W32(p + 12, i < NMODES ? FMT_X8R8G8B8 : FMT_R5G6B5);
    RET(4, S_OK);
}
W(d3d_GetAdapterDisplayMode) {
    uint32_t p = ARG(2);
    W32(p, (uint32_t)g_screen_w); W32(p + 4, (uint32_t)g_screen_h); W32(p + 8, 60); W32(p + 12, FMT_X8R8G8B8);
    RET(3, S_OK);
}
W(d3d_CheckDeviceType) { RET(6, mode_format_ok(ARG(3)) ? S_OK : D3DERR_NOTAVAILABLE); }
W(d3d_CheckDeviceFormat) {
    uint32_t r = supported_format(ARG(6)) ? S_OK : D3DERR_NOTAVAILABLE;
    if (g_log_d3d) fprintf(stderr, "[d3d] CheckDeviceFormat(usage %x, rtype %u, fmt %u) = %s\n", ARG(4), ARG(5),
                           ARG(6), r ? "no" : "ok");
    RET(7, r);
}
W(d3d_CheckDeviceMultiSampleType) { RET(6, ARG(5) <= 1 ? S_OK : D3DERR_NOTAVAILABLE); }
W(d3d_CheckDepthStencilMatch) { RET(6, S_OK); }

static void fill_caps(uint32_t p) {
    memset(HP(p), 0, 212);
    W32(p + 0, 1);                         /* D3DDEVTYPE_HAL */
    W32(p + 8, 0x00020000);                /* Caps: READ_SCANLINE */
    W32(p + 12, 0x20000000 | 0x00080000 | 0x00020000);  /* DYNAMICTEXTURES | CANRENDERWINDOWED | FULLSCREENGAMMA */
    W32(p + 16, 0x20);                     /* Caps3 */
    W32(p + 20, 0x80000001u);              /* presentation intervals: IMMEDIATE | ONE */
    W32(p + 24, 1);                        /* CursorCaps */
    W32(p + 28, 0x001BBEF0);               /* DevCaps: HW T&L, HW raster, pure device, ... */
    W32(p + 32, 0x0000FFF2);               /* PrimitiveMiscCaps */
    W32(p + 36, 0x00732191);               /* RasterCaps: dither, ztest, fog, mip LOD bias, aniso, w/z fog */
    W32(p + 40, 0xFF); W32(p + 44, 0x1FFF); W32(p + 48, 0x1FFF); W32(p + 52, 0xFF);
    W32(p + 56, 0x00084208);               /* ShadeCaps */
    W32(p + 60, 0x0001EC45);               /* TextureCaps (no POW2/SQUAREONLY restrictions) */
    W32(p + 64, 0x07030700); W32(p + 68, 0x07030700); W32(p + 72, 0x07030700);
    W32(p + 76, 0x3F); W32(p + 80, 0x3F); W32(p + 84, 0x1F);
    W32(p + 88, 4096); W32(p + 92, 4096); W32(p + 96, 256); W32(p + 100, 8192); W32(p + 104, 4096);
    W32(p + 108, 16);
    WF32(p + 112, 1e10f);
    WF32(p + 116, -8192.f); WF32(p + 120, -8192.f); WF32(p + 124, 8192.f); WF32(p + 128, 8192.f);
    W32(p + 136, 0xFF);                    /* StencilCaps */
    W32(p + 140, 8 | 0x00100000);          /* FVFCaps: 8 texcoord sets, PSIZE */
    W32(p + 144, 0x03FFFFFF);              /* TextureOpCaps */
    W32(p + 148, 8); W32(p + 152, 4);      /* blend stages, simultaneous textures */
    W32(p + 156, 0x7B);                    /* VertexProcessingCaps */
    W32(p + 160, 8); W32(p + 164, 6); W32(p + 168, 4); W32(p + 172, 0);
    WF32(p + 176, 64.f);
    W32(p + 180, 0xFFFFF); W32(p + 184, 0xFFFFF); W32(p + 188, 16); W32(p + 192, 255);
    W32(p + 196, 0xFFFE0101);              /* vs_1_1 */
    W32(p + 200, 96);
    W32(p + 204, 0xFFFF0101);              /* ps_1_1 */
    WF32(p + 208, 1.f);
}
W(d3d_GetDeviceCaps) { fill_caps(ARG(3)); RET(4, S_OK); }
W(d3d_GetAdapterMonitor) { RET(2, 0x00070001u); }

static uint32_t new_surface(uint32_t fmt, uint32_t w, uint32_t h, int rt, int depth, int with_mem);
W(d3d_CreateDevice) {
    uint32_t pp = ARG(5), out = ARG(6);
    Device *d = calloc(1, sizeof *d);
    d->width = R32(pp) ? R32(pp) : (uint32_t)g_screen_w;
    d->height = R32(pp + 4) ? R32(pp + 4) : (uint32_t)g_screen_h;
    d->backbuffer_format = R32(pp + 8) ? R32(pp + 8) : FMT_X8R8G8B8;
    d->windowed = R32(pp + 28);
    d->depth_format = R32(pp + 32) ? R32(pp + 36) : 0;
    d->hwnd = R32(pp + 24) ? R32(pp + 24) : ARG(3);
    d->d3d = THIS;
    fprintf(stderr, "[d3d] CreateDevice: %ux%u fmt %u, %s, backbuffers %u, multisample %u, swap %u, depth %u, "
            "behavior %x, flags %x\n", d->width, d->height, d->backbuffer_format, d->windowed ? "windowed" : "fullscreen",
            R32(pp + 12), R32(pp + 16), R32(pp + 20), d->depth_format, ARG(4), R32(pp + 40));
    if (R32(pp) == 0) { W32(pp, d->width); W32(pp + 4, d->height); }
    d->backbuffer = new_surface(d->backbuffer_format, d->width, d->height, 1, 0, 0);
    if (d->depth_format) d->depth = new_surface(d->depth_format, d->width, d->height, 0, 1, 0);
    d->st.render_target = d->backbuffer;
    d->st.depth_stencil = d->depth;
    com_retain_handle(d->st.render_target); com_retain_handle(d->st.depth_stencil);
    /* Direct3D 8's documented default states (D3DRENDERSTATETYPE / D3DTEXTURESTAGESTATETYPE numbering) */
    uint32_t *rs = d->st.rs;
    rs[7] = d->depth ? 1 : 0;            /* ZENABLE */
    rs[8] = 3;                           /* FILLMODE: solid */
    rs[9] = 2;                           /* SHADEMODE: gouraud */
    rs[14] = 1;                          /* ZWRITEENABLE */
    rs[19] = 2; rs[20] = 1;              /* SRCBLEND one, DESTBLEND zero */
    rs[22] = 3;                          /* CULLMODE: ccw */
    rs[23] = 4;                          /* ZFUNC: lessequal */
    rs[25] = 8;                          /* ALPHAFUNC: always */
    rs[53] = rs[54] = rs[55] = 1;        /* STENCILFAIL / ZFAIL / PASS: keep */
    rs[56] = 8;                          /* STENCILFUNC: always */
    rs[58] = rs[59] = 0xFFFFFFFFu;       /* STENCILMASK / STENCILWRITEMASK */
    rs[60] = 0xFFFFFFFFu;                /* TEXTUREFACTOR */
    rs[136] = 1;                         /* CLIPPING */
    rs[137] = 1;                         /* LIGHTING */
    rs[141] = 1;                         /* COLORVERTEX */
    rs[142] = 1;                         /* LOCALVIEWER (documented Direct3D 8 default: TRUE) */
    rs[145] = 1; rs[146] = 2;            /* DIFFUSE/SPECULARMATERIALSOURCE: color1 / color2 */
    rs[154] = 0x3F800000;                /* POINTSIZE 1.0 */
    rs[155] = 0x3F800000;                /* POINTSIZE_MIN 1.0 */
    rs[161] = 1;                         /* MULTISAMPLEANTIALIAS */
    rs[162] = 0xFFFFFFFFu;               /* MULTISAMPLEMASK */
    rs[168] = 0xF;                       /* COLORWRITEENABLE */
    rs[171] = 1;                         /* BLENDOP: add */
    for (int s = 0; s < 8; s++) {
        uint32_t *t = d->st.tss[s];
        t[1] = s == 0 ? 4 : 1;           /* COLOROP: modulate / disable */
        t[2] = 2; t[3] = 1;              /* COLORARG1 texture, COLORARG2 current */
        t[4] = s == 0 ? 2 : 1;           /* ALPHAOP: selectarg1 / disable */
        t[5] = 2; t[6] = 1;              /* ALPHAARG1 texture, ALPHAARG2 current */
        t[11] = (uint32_t)s;             /* TEXCOORDINDEX */
        t[13] = t[14] = t[25] = 1;       /* ADDRESSU/V/W: wrap */
        t[16] = t[17] = 1; t[18] = 0;    /* MAG/MINFILTER point, MIPFILTER none */
        t[26] = 1;                       /* COLORARG0 current */
    }
    for (int i = 0; i < MAX_TS; i++)
        for (int k = 0; k < 4; k++) d->st.transform[i][k * 5] = 1.f;
    d->st.viewport.w = d->width; d->st.viewport.h = d->height; d->st.viewport.maxz = 1.f;
    if (g_render->init) g_render->init(d);
    g_device_object = com_new(&IDirect3DDevice8_i, RT_DEVICE, d);
    g_device = d;
    W32(out, g_device_object);
    RET(7, S_OK);
}

static const ComMethod d3d_methods[] = {
    { "QueryInterface", 2, com_QueryInterface }, { "AddRef", 0, com_AddRef }, { "Release", 0, com_Release },
    { "RegisterSoftwareDevice", 1, d3d_RegisterSoftwareDevice }, { "GetAdapterCount", 0, d3d_GetAdapterCount },
    { "GetAdapterIdentifier", 3, d3d_GetAdapterIdentifier }, { "GetAdapterModeCount", 1, d3d_GetAdapterModeCount },
    { "EnumAdapterModes", 3, d3d_EnumAdapterModes }, { "GetAdapterDisplayMode", 2, d3d_GetAdapterDisplayMode },
    { "CheckDeviceType", 5, d3d_CheckDeviceType }, { "CheckDeviceFormat", 6, d3d_CheckDeviceFormat },
    { "CheckDeviceMultiSampleType", 5, d3d_CheckDeviceMultiSampleType },
    { "CheckDepthStencilMatch", 5, d3d_CheckDepthStencilMatch }, { "GetDeviceCaps", 3, d3d_GetDeviceCaps },
    { "GetAdapterMonitor", 1, d3d_GetAdapterMonitor }, { "CreateDevice", 6, d3d_CreateDevice },
};
static ComInterface IDirect3D8_i = { "IDirect3D8", d3d_methods, 16, 0 };

void w_Direct3DCreate8(CPU *c) {
    fprintf(stderr, "[d3d] Direct3DCreate8(%u) -> headless Direct3D 8 (%s backend)\n", ARG(0), g_render->name);
    g_d3d_object = com_new(&IDirect3D8_i, RT_D3D, NULL);  /* the game creates one, releases it, creates another */
    RET(1, g_d3d_object);
}

/* ------------------------------------------------------------------ resources */

static Device *dev(CPU *c) { return com_data(THIS); }

uint32_t gpu_new_id(void) {
    static uint32_t next = 1;
    return __atomic_fetch_add(&next, 1, __ATOMIC_SEQ_CST);
}

static uint32_t new_surface(uint32_t fmt, uint32_t w, uint32_t h, int rt, int depth, int with_mem) {
    Surface *s = calloc(1, sizeof *s);
    s->gpu_id = gpu_new_id();
    s->format = fmt; s->width = w; s->height = h;
    s->pitch = level_pitch(fmt, w);
    s->is_rt = rt; s->is_depth = depth;
    if (with_mem || rt || depth) s->mem = heap_alloc(s->pitch * level_rows(fmt, h) + 16, 1);
    return com_new(&IDirect3DSurface8_i, RT_SURFACE, s);
}

/* Texture arrays have 14 mip entries. This check precedes all allocations and
   indexing, including levels=0 (full chain). */
static int texture_levels(uint32_t w,uint32_t h,uint32_t levels,uint32_t *actual) {
    if (!w || !h || w>8192 || h>8192) return 0;
    uint32_t maxlev=1;
    for (uint32_t x=w>h?w:h; x>1; x>>=1) maxlev++;
    uint32_t n=(!levels || levels>maxlev) ? maxlev : levels;
    if (!n || n>14) return 0;
    *actual=n; return 1;
}
static uint32_t create_texture(uint32_t w, uint32_t h, uint32_t levels, uint32_t usage, uint32_t fmt,
                               uint32_t pool, int cube) {
    uint32_t actual_levels;
    if (!texture_levels(w,h,levels,&actual_levels)) return 0;
    Texture *t = calloc(1, sizeof *t);
    if (!t) return 0;
    t->gpu_id = gpu_new_id();
    t->sent_version = 0xFFFFFFFFu;
    t->type = cube ? RT_CUBETEXTURE : RT_TEXTURE;
    t->format = fmt; t->usage = usage; t->pool = pool; t->width = w; t->height = h;
    t->faces = cube ? 6 : 1;
    t->levels = actual_levels;
    for (uint32_t l = 0; l < t->levels; l++) {
        uint32_t lw = w >> l ? w >> l : 1, lh = h >> l ? h >> l : 1;
        t->lw[l] = lw; t->lh[l] = lh;
        t->pitch[l] = level_pitch(fmt, lw);
        t->size[l] = t->pitch[l] * level_rows(fmt, lh);
        for (uint32_t f=0;f<t->faces;f++) {
            t->mem[f][l]=heap_try_alloc(t->size[l]+16,1);
            if (!t->mem[f][l]) {
                for (uint32_t a=0;a<t->faces;a++) for (uint32_t b=0;b<t->levels;b++)
                    if (t->mem[a][b]) heap_free(t->mem[a][b]);
                free(t); return 0;
            }
        }
    }
    uint32_t g = com_new(cube ? &IDirect3DCubeTexture8_i : &IDirect3DTexture8_i, t->type, t);
    if (g_log_d3d) fprintf(stderr, "[d3d] Create%sTexture %ux%u levels %u fmt %x usage %x pool %u -> %08x\n",
                           cube ? "Cube" : "", w, h, t->levels, fmt, usage, pool, g);
    return g;
}

/* ------------------------------------------------------------------ IDirect3DDevice8 */

W(dev_TestCooperativeLevel) { RET(1, S_OK); }
W(dev_GetAvailableTextureMem) { RET(1, 256u << 20); }
W(dev_ResourceManagerDiscardBytes) { RET(2, S_OK); }
W(dev_GetDirect3D) { W32(ARG(1), dev(c)->d3d); RET(2, S_OK); }
W(dev_GetDeviceCaps) { fill_caps(ARG(1)); RET(2, S_OK); }
W(dev_GetDisplayMode) {
    Device *d = dev(c);
    uint32_t p = ARG(1);
    W32(p, d->width); W32(p + 4, d->height); W32(p + 8, 60); W32(p + 12, d->backbuffer_format);
    RET(2, S_OK);
}
W(dev_GetCreationParameters) {
    uint32_t p = ARG(1);
    W32(p, 0); W32(p + 4, 1); W32(p + 8, dev(c)->hwnd); W32(p + 12, 0x40);
    RET(2, S_OK);
}
W(dev_Reset) {
    Device *d = dev(c);
    uint32_t pp = ARG(1);
    fprintf(stderr, "[d3d] Reset to %ux%u\n", R32(pp), R32(pp + 4));
    if (R32(pp)) { d->width = R32(pp); d->height = R32(pp + 4); }
    RET(2, S_OK);
}
/* Determinism checks: PORT_HASH_LOG=<file> writes a hash of the game's global data (.data + .data1,
   g_data_lo-g_data_hi, from the image's writable sections) every frame; PORT_SNAPSHOT=<frame>,... writes that memory raw to
   <PORT_SNAPSHOT_DIR or /tmp>/port_state_<frame>.bin, to diff two runs at their first differing frame. */
#define STATE_LO g_data_lo
#define STATE_HI g_data_hi
static uint64_t state_hash_globals(void) {
    uint64_t h = 1469598103934665603ull;   /* FNV-1a over 8-byte words */
    for (uint32_t a = STATE_LO; a < STATE_HI; a += 8) { h ^= R64(a); h *= 1099511628211ull; }
    return h;
}
static void state_hash_tick(uint32_t frame) {
    static FILE *log = (FILE *)1;
    static const char *snap = (const char *)1;
    if (log == (FILE *)1) { const char *p = getenv("PORT_HASH_LOG"); log = p ? fopen(p, "w") : NULL; }
    if (snap == (const char *)1) snap = getenv("PORT_SNAPSHOT");
    if (log) {
        uint64_t h = state_hash_globals();
        extern uint32_t g_det_sleeps, g_det_waits, g_det_reads;
        fprintf(log, "%u %016llx sleeps=%u waits=%u reads=%u t=%.6f\n", frame, (unsigned long long)h, g_det_sleeps,
                g_det_waits, g_det_reads, guest_peek_seconds());
        /* PORT_HASH_ALL=N: every N frames also the heap and VirtualAlloc'd memory (thread stacks, game pools) */
        static int every = -1;
        if (every < 0) every = getenv("PORT_HASH_ALL") ? atoi(getenv("PORT_HASH_ALL")) : 0;
        if (every > 0 && frame % (uint32_t)every == 0) {
            extern void guest_mem_ranges(uint32_t r[4]);
            uint32_t r[4];
            guest_mem_ranges(r);
            uint64_t hh = 1469598103934665603ull, hv = hh;
            for (uint32_t a = r[0]; a + 8 <= r[1]; a += 8) { hh ^= R64(a); hh *= 1099511628211ull; }
            for (uint32_t a = r[2]; a + 8 <= r[3]; a += 8) { hv ^= R64(a); hv *= 1099511628211ull; }
            fprintf(log, "%u heap %016llx %u MB valloc %016llx %u MB\n", frame, (unsigned long long)hh, (r[1] - r[0]) >> 20,
                    (unsigned long long)hv, (r[3] - r[2]) >> 20);
        }
        fflush(log);
    }
    if (snap) {
        char tmp[16];
        snprintf(tmp, sizeof tmp, "%u", frame);
        for (const char *p = strstr(snap, tmp); p; p = strstr(p + 1, tmp)) {
            size_t n = strlen(tmp);
            if ((p != snap && p[-1] != ',') || (p[n] && p[n] != ',')) continue;
            char path[512];
            snprintf(path, sizeof path, "%s/port_state_%u.bin", getenv("PORT_SNAPSHOT_DIR") ? getenv("PORT_SNAPSHOT_DIR") : "/tmp", frame);
            FILE *f = fopen(path, "wb");
            if (f) { fwrite(HP(STATE_LO), 1, STATE_HI - STATE_LO, f); fclose(f); }
            if (getenv("PORT_SNAPSHOT_HEAP")) {   /* also the heap, as port_heap_<frame>.bin */
                extern void guest_mem_ranges(uint32_t r[4]);
                uint32_t r[4];
                guest_mem_ranges(r);
                snprintf(path, sizeof path, "%s/port_heap_%u.bin", getenv("PORT_SNAPSHOT_DIR") ? getenv("PORT_SNAPSHOT_DIR") : "/tmp", frame);
                if ((f = fopen(path, "wb"))) { fwrite(HP(r[0]), 1, r[1] - r[0], f); fclose(f); }
            }
            break;
        }
    }
}

#ifdef PORT_HEAP_STATS
/* Диагностика (только с -DPORT_HEAP_STATS): сколько живых ресурсов d3d8 держит память кучи гостя.
   Вызывается из Present на потоке игры; объекты d3d8 создаются и уничтожаются на нём же. */
typedef struct { unsigned surf, surf_mem, tex, buf; unsigned long long surf_b, tex_b, buf_b; } D3dStats;
static void d3d_stats_cb(const ComObj *o, void *ctx) {
    D3dStats *st = ctx;
    if (!o->data) return;
    if (o->type == RT_SURFACE) {
        Surface *s = o->data;
        st->surf++;
        if (!s->container && s->mem) { st->surf_mem++; st->surf_b += heap_size(s->mem); }
    } else if (o->type == RT_TEXTURE || o->type == RT_CUBETEXTURE) {
        Texture *t = o->data;
        st->tex++;
        for (uint32_t f = 0; f < t->faces && f < 6; f++)
            for (uint32_t l = 0; l < t->levels && l < 14; l++)
                if (t->mem[f][l]) st->tex_b += heap_size(t->mem[f][l]);
    } else if (o->type == RT_VERTEXBUFFER || o->type == RT_INDEXBUFFER) {
        Buffer *b = o->data;
        st->buf++;
        if (b->mem) st->buf_b += heap_size(b->mem);
    }
}
void d3d_stats_log(void) {
    extern void com_foreach_live(void (*)(const ComObj *, void *), void *), com_stats_log(void);
    D3dStats st = {0};
    com_foreach_live(d3d_stats_cb, &st);
    fprintf(stderr, "[d3dstats] surfaces=%u (own memory %u, %llu KB) textures=%u (%llu KB) vertex/index buffers=%u (%llu KB)\n",
            st.surf, st.surf_mem, st.surf_b >> 10, st.tex, st.tex_b >> 10, st.buf, st.buf_b >> 10);
    com_stats_log();
}
#endif

W(dev_Present) {
    Device *d = dev(c);
    d->frame++;
    extern void input_script_tick(uint32_t frame);
    extern void dump_tick(uint32_t frame);
    input_script_tick(d->frame);
    dump_tick(d->frame);
    extern void netplay_frame(uint32_t frame, uint64_t (*state_hash)(void));
    netplay_frame(d->frame, state_hash_globals);   /* lockstep: exchange and apply pad inputs */
    vclock_frame();
    state_hash_tick(d->frame);
    static double last_t;
    static uint32_t last_f;
    static int fps_log = -1;
    if (fps_log < 0) fps_log = getenv("PORT_LOG_FPS") != NULL;
    double now = host_seconds();
    if (fps_log && now - last_t >= 2.0) {
        if (last_t) fprintf(stderr, "[fps] %.1f  (frame %u, %u draws in the last frame)\n",
                            (d->frame - last_f) / (now - last_t), d->frame, d->draws_this_frame);
        extern void guest_mem_stats(uint32_t *, uint32_t *);
        uint32_t hu, vu;
        guest_mem_stats(&hu, &vu);
        extern size_t g_gpu_tex_bytes;
        extern uint32_t g_gpu_bind_groups_made;
        fprintf(stderr, "[mem] guest heap %u MB, virtual allocations %u MB, GPU textures %zu MB, bind groups made %u\n",
                hu >> 20, vu >> 20, g_gpu_tex_bytes >> 20, g_gpu_bind_groups_made);
#ifdef PORT_HEAP_STATS   /* диагностика: живые блоки кучи и PCM-буферы DirectSound (core.c, dsound.c) */
        { extern void guest_heap_stats_log(void), dsound_stats_log(void); guest_heap_stats_log(); dsound_stats_log(); d3d_stats_log(); }
#endif
        last_t = now; last_f = d->frame;
    }
    if (g_render->present) g_render->present(d);
    if (g_log_d3d && (d->frame <= 3 || d->frame % 300 == 0))
        fprintf(stderr, "[d3d] Present: frame %u, %u draws\n", d->frame, d->draws_this_frame);
    d->draws_this_frame = 0;
    RET(5, S_OK);
}
W(dev_GetBackBuffer) {
    Device *d = dev(c);
    ComObj *o = com_get(d->backbuffer);
    if (o) o->refs++;
    W32(ARG(3), d->backbuffer);
    RET(4, S_OK);
}
W(dev_GetRasterStatus) { W32(ARG(1), 1); W32(ARG(1) + 4, 0); RET(2, S_OK); }
W(dev_SetGammaRamp) { RET(3, S_OK); }
W(dev_GetGammaRamp) {
    for (int i = 0; i < 256; i++) for (int k = 0; k < 3; k++) W16(ARG(1) + 512u * k + 2u * i, (uint16_t)(i * 257));
    RET(2, S_OK);
}
W(dev_CreateTexture) {
    uint32_t t=create_texture(ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6), 0);
    uint32_t actual; int valid=texture_levels(ARG(1),ARG(2),ARG(3),&actual);
    W32(ARG(7),t); RET(8, t ? S_OK : valid ? 0x8007000Eu /* E_OUTOFMEMORY */ : D3DERR_INVALIDCALL);
}
W(dev_CreateCubeTexture) {
    uint32_t t=create_texture(ARG(1), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), 1);
    uint32_t actual; int valid=texture_levels(ARG(1),ARG(1),ARG(2),&actual);
    W32(ARG(6),t); RET(7, t ? S_OK : valid ? 0x8007000Eu /* E_OUTOFMEMORY */ : D3DERR_INVALIDCALL);
}
W(dev_CreateVolumeTexture) {
    fprintf(stderr, "[d3d] CreateVolumeTexture is not supported\n");
    RET(9, D3DERR_NOTAVAILABLE);
}
static uint32_t create_buffer(int index, uint32_t len, uint32_t usage, uint32_t fvf_fmt, uint32_t pool) {
    Buffer *b = calloc(1, sizeof *b);
    b->index = index; b->size = len; b->usage = usage; b->fvf_or_format = fvf_fmt; b->pool = pool;
    b->mem = heap_alloc(len + 16, 1);
    return com_new(index ? &IDirect3DIndexBuffer8_i : &IDirect3DVertexBuffer8_i,
                   index ? RT_INDEXBUFFER : RT_VERTEXBUFFER, b);
}
W(dev_CreateVertexBuffer) { W32(ARG(5), create_buffer(0, ARG(1), ARG(2), ARG(3), ARG(4))); RET(6, S_OK); }
W(dev_CreateIndexBuffer) { W32(ARG(5), create_buffer(1, ARG(1), ARG(2), ARG(3), ARG(4))); RET(6, S_OK); }
W(dev_CreateRenderTarget) { W32(ARG(6), new_surface(ARG(3), ARG(1), ARG(2), 1, 0, 1)); RET(7, S_OK); }
W(dev_CreateDepthStencilSurface) { W32(ARG(5), new_surface(ARG(3), ARG(1), ARG(2), 0, 1, 0)); RET(6, S_OK); }
W(dev_CreateImageSurface) { W32(ARG(4), new_surface(ARG(3), ARG(1), ARG(2), 0, 0, 1)); RET(5, S_OK); }
W(dev_CreateAdditionalSwapChain) { RET(3, D3DERR_NOTAVAILABLE); }

/* A texture owns the GPU storage of an RT face even when its last temporary
   COM surface view was released. Reconstruct only the host-side descriptor;
   all queued rendering commands still carry self-contained ids and bytes. */
static int texture_rt_surface(Texture *t,uint32_t f,uint32_t l,Surface *out) {
    if (!t || !(t->usage & 1) || f>=t->faces || f>=6 || l>=t->levels || l>=14 || !t->rt_surface_ids[f][l])
        return 0;
    memset(out,0,sizeof *out);
    out->gpu_id=t->rt_surface_ids[f][l]; out->format=t->format;
    out->width=t->lw[l]; out->height=t->lh[l]; out->pitch=t->pitch[l]; out->mem=t->mem[f][l];
    out->face=(int)f; out->level=(int)l; out->is_rt=1;
    return 1;
}

/* CPU changes remain authoritative until their RT upload is queued. */
static uint8_t *surface_dirty(Surface *s) {
    Texture *t=s->container ? com_data(s->container) : NULL;
    if (t && s->face>=0 && s->face<6 && s->level>=0 && s->level<14)
        return &t->rt_cpu_dirty[s->face][s->level];
    return NULL;
}
static int surface_needs_upload(Surface *s) {
    uint8_t *dirty=surface_dirty(s); return dirty ? *dirty : s->cpu_dirty;
}
static void surface_set_dirty(Surface *s,int value) {
    uint8_t *dirty=surface_dirty(s); if (dirty) *dirty=(uint8_t)value; else s->cpu_dirty=value;
}
int d3d_sync_surface(Device *d, Surface *s) {
    if (!s || !s->is_rt || !surface_needs_upload(s)) return 1;
    if (g_render->upload_surface && (!d || !g_render->upload_surface(d,s))) return 0;
    surface_set_dirty(s,0); return 1;
}
static int surface_changed(Device *d,Surface *s) {
    if (!s || !s->is_rt) return 1;
    surface_set_dirty(s,1); return d3d_sync_surface(d,s);
}
int d3d_sync_texture_rt(Device *d, Texture *t) {
    if (!t || !(t->usage&1)) return 1;
    for (uint32_t f=0;f<t->faces && f<6;f++) for (uint32_t l=0;l<t->levels && l<14;l++) {
        if (!t->rt_cpu_dirty[f][l]) continue;
        Surface surface;
        if (!texture_rt_surface(t,f,l,&surface)) { t->rt_cpu_dirty[f][l]=0; continue; }
        if (g_render->upload_surface && (!d || !g_render->upload_surface(d,&surface))) return 0;
        t->rt_cpu_dirty[f][l]=0;
    }
    return 1;
}

static void touch_container(Surface *s) {
    Texture *t = s->container ? com_data(s->container) : NULL;
    if (t) t->version++;
}
static int is_gpu_surface(Device *d, Surface *s) { return s && (s->is_rt || com_data(d->backbuffer) == s); }

/* Reject same-surface overlap before any readback or writes. Work in BC block
   coordinates to match the actual copy; no temporary allocation is needed. */
typedef struct CopyArea { uint32_t x,y,w,h,dx,dy; } CopyArea;
static int copy_area(Surface *s,Surface *dst,uint32_t rects,uint32_t points,uint32_t i,CopyArea *a) {
    uint32_t x0=0,y0=0,x1=s->width,y1=s->height;
    if (rects) { uint32_t r=rects+16*i; x0=R32(r); y0=R32(r+4); x1=R32(r+8); y1=R32(r+12); }
    uint32_t dx=points?R32(points+8*i):x0, dy=points?R32(points+8*i+4):y0;
    if (x0>x1 || y0>y1 || x1>s->width || y1>s->height ||
        dx>dst->width || dy>dst->height || x1-x0>dst->width-dx || y1-y0>dst->height-dy) return 0;
    if (format_is_dxt(s->format)) {
        x0/=4; y0/=4; x1=(x1+3)/4; y1=(y1+3)/4; dx/=4; dy/=4;
        uint32_t dw=(dst->width+3)/4, dh=(dst->height+3)/4;
        if (dx>dw || dy>dh || x1-x0>dw-dx || y1-y0>dh-dy) return 0;
    }
    *a=(CopyArea){x0,y0,x1-x0,y1-y0,dx,dy}; return 1;
}
static int same_surface_copy_valid(Surface *s,uint32_t n,uint32_t rects,uint32_t points) {
    for (uint32_t i=0;i<n;i++) {
        CopyArea a; if (!copy_area(s,s,rects,points,i,&a)) return 0;
        for (uint32_t j=0;j<n;j++) {
            CopyArea b; if (!copy_area(s,s,rects,points,j,&b)) return 0;
            if (i==j && a.x==a.dx && a.y==a.dy) continue; /* exact no-op */
            if (a.w && a.h && b.w && b.h && a.x<b.dx+b.w && b.dx<a.x+a.w &&
                a.y<b.dy+b.h && b.dy<a.y+a.h) return 0;
        }
    }
    return 1;
}

static int copy_arrays_valid(uint32_t n,uint32_t rects,uint32_t points) {
    uint64_t count=n?n:1;
    return (!rects || (uint64_t)rects+16u*count<=GUEST_SPACE) &&
           (!points || (uint64_t)points+8u*count<=GUEST_SPACE);
}

W(dev_CopyRects) {
    Device *dv = dev(c);
    Surface *src = com_data(ARG(1)), *dst = com_data(ARG(4));
    uint32_t n = ARG(3);
    if (src && dst && src->format!=dst->format) RET(6,D3DERR_INVALIDCALL);
    if (!copy_arrays_valid(n,ARG(2),ARG(5))) RET(6,D3DERR_INVALIDCALL);
    if (src && dst) {
        for (uint32_t i=0;i<(n?n:1);i++) {
            CopyArea area; if (!copy_area(src,dst,ARG(2),ARG(5),i,&area)) RET(6,D3DERR_INVALIDCALL);
        }
        if (src==dst && !same_surface_copy_valid(src,n?n:1,ARG(2),ARG(5))) RET(6,D3DERR_INVALIDCALL);
    }
    if (!d3d_sync_surface(dv,src) || !d3d_sync_surface(dv,dst)) RET(6,0x8007000Eu);
    if (is_gpu_surface(dv,src) && g_render->readback && !g_render->readback(dv,src)) RET(6,0x8007000Eu);
    if (dst!=src && is_gpu_surface(dv,dst) && g_render->readback && !g_render->readback(dv,dst)) RET(6,0x8007000Eu);
    if (dst && !dst->mem) dst->mem = heap_alloc(dst->pitch * level_rows(dst->format, dst->height) + 16, 1);
    if (!src || !dst || !src->mem || !dst->mem)
        RET(6, S_OK);
    uint32_t unit_bytes=format_is_dxt(src->format) ? (src->format==FMT_DXT1 ? 8 : 16) : format_bpp(src->format)/8;
    for (uint32_t i=0;i<(n?n:1);i++) {
        CopyArea a; if (!copy_area(src,dst,ARG(2),ARG(5),i,&a)) RET(6,D3DERR_INVALIDCALL);
        size_t row=(size_t)a.w*unit_bytes;
        for (uint32_t y=0;y<a.h;y++)
            memmove(HP(dst->mem+(a.dy+y)*dst->pitch+a.dx*unit_bytes),
                    HP(src->mem+(a.y+y)*src->pitch+a.x*unit_bytes),row);
    }
    touch_container(dst);
    RET(6,surface_changed(dv,dst) ? S_OK : 0x8007000Eu);
}
W(dev_UpdateTexture) {
    Texture *s = com_data(ARG(1)), *d = com_data(ARG(2));
    if (s && d && s->format == d->format && s->faces == d->faces) {
        if (!d3d_sync_texture_rt(g_device,s)) RET(3,0x8007000Eu);
        for (uint32_t f=0;f<d->faces && f<6;f++) for (uint32_t l=0;l<d->levels && l<s->levels && l<14;l++) {
            memcpy(HP(d->mem[f][l]),HP(s->mem[f][l]),d->size[l]<s->size[l]?d->size[l]:s->size[l]);
            if (d->rt_surface_ids[f][l]) d->rt_cpu_dirty[f][l]=1;
        }
        d->version++;
        if (!d3d_sync_texture_rt(g_device,d)) RET(3,0x8007000Eu);
    }
    RET(3,S_OK);
}
W(dev_GetFrontBuffer) { RET(2, S_OK); }
W(dev_SetRenderTarget) {
    Device *d = dev(c);
    uint32_t color=ARG(1), depth=ARG(2);
    ComObj *co=color ? com_get(color) : NULL, *ds=depth ? com_get(depth) : NULL;
    if ((color && (!co || co->type!=RT_SURFACE)) || (depth && (!ds || ds->type!=RT_SURFACE)))
        RET(3,D3DERR_INVALIDCALL);
    /* Acquire both new references before dropping either old one. */
    if (color) com_retain_handle(color);
    if (depth) com_retain_handle(depth);
    uint32_t old_color=d->st.render_target, old_depth=d->st.depth_stencil;
    if (color) {
        d->st.render_target=color;
        Surface *rt=co->data;
        if (rt) { d->st.viewport.x=0; d->st.viewport.y=0; d->st.viewport.w=rt->width; d->st.viewport.h=rt->height;
                  d->st.viewport.minz=0.f; d->st.viewport.maxz=1.f; }
        com_release_handle(old_color);
    }
    d->st.depth_stencil=depth;
    com_release_handle(old_depth);
    RET(3,S_OK);
}
static void out_addref(uint32_t out, uint32_t obj) {
    ComObj *o = com_get(obj);
    if (o) o->refs++;
    W32(out, obj);
}
W(dev_GetRenderTarget) { out_addref(ARG(1), dev(c)->st.render_target); RET(2, S_OK); }
W(dev_GetDepthStencilSurface) {
    uint32_t ds = dev(c)->st.depth_stencil;
    out_addref(ARG(1), ds);
    RET(2, ds ? S_OK : 0x8876086Au);
}
W(dev_BeginScene) { RET(1, S_OK); }
W(dev_EndScene) { RET(1, S_OK); }
W(dev_Clear) {
    if (g_render->clear) {
        float z;
        uint32_t zbits = ARG(5);
        memcpy(&z, &zbits, 4);
        g_render->clear(dev(c), ARG(1), ARG(2), ARG(3), ARG(4), z, ARG(6));
    }
    RET(7, S_OK);
}
static uint32_t ts_index(uint32_t t) { return t < MAX_TS ? t : MAX_TS - 1; }
W(dev_SetTransform) { memcpy(dev(c)->st.transform[ts_index(ARG(1))], HP(ARG(2)), 64); RET(3, S_OK); }
W(dev_GetTransform) { memcpy(HP(ARG(2)), dev(c)->st.transform[ts_index(ARG(1))], 64); RET(3, S_OK); }
W(dev_MultiplyTransform) {
    float *m = dev(c)->st.transform[ts_index(ARG(1))], r[16], b[16];
    memcpy(b, HP(ARG(2)), 64);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        float s = 0; for (int k = 0; k < 4; k++) s += m[i * 4 + k] * b[k * 4 + j]; r[i * 4 + j] = s;
    }
    memcpy(m, r, 64);
    RET(3, S_OK);
}
W(dev_SetViewport) { memcpy(&dev(c)->st.viewport, HP(ARG(1)), 24); RET(2, S_OK); }
W(dev_GetViewport) { memcpy(HP(ARG(1)), &dev(c)->st.viewport, 24); RET(2, S_OK); }
W(dev_SetMaterial) { memcpy(dev(c)->st.material, HP(ARG(1)), 68); RET(2, S_OK); }
W(dev_GetMaterial) { memcpy(HP(ARG(1)), dev(c)->st.material, 68); RET(2, S_OK); }
W(dev_SetLight) { if (ARG(1) < 8) memcpy(dev(c)->st.light[ARG(1)], HP(ARG(2)), 104); RET(3, S_OK); }
W(dev_GetLight) { if (ARG(1) < 8) memcpy(HP(ARG(2)), dev(c)->st.light[ARG(1)], 104); RET(3, S_OK); }
W(dev_LightEnable) { if (ARG(1) < 8) dev(c)->st.light_enabled[ARG(1)] = ARG(2); RET(3, S_OK); }
W(dev_GetLightEnable) { W32(ARG(2), ARG(1) < 8 ? dev(c)->st.light_enabled[ARG(1)] : 0); RET(3, S_OK); }
W(dev_SetClipPlane) { if (ARG(1) < 6) memcpy(dev(c)->st.clip_plane[ARG(1)], HP(ARG(2)), 16); RET(3, S_OK); }
W(dev_GetClipPlane) { if (ARG(1) < 6) memcpy(HP(ARG(2)), dev(c)->st.clip_plane[ARG(1)], 16); RET(3, S_OK); }
W(dev_SetRenderState) { if (ARG(1) < 256) dev(c)->st.rs[ARG(1)] = ARG(2); RET(3, S_OK); }
W(dev_GetRenderState) { W32(ARG(2), ARG(1) < 256 ? dev(c)->st.rs[ARG(1)] : 0); RET(3, S_OK); }

/* State blocks: recorded blocks capture a full snapshot; good enough until a game relies on partial blocks. */
#define MAX_BLOCKS 1024
static DevState *g_blocks[MAX_BLOCKS];
static void retain_block_textures(const DevState *st) {
    for (int i=0;i<8;i++) com_retain_handle(st->texture[i]);
}
static void release_block_textures(const DevState *st) {
    for (int i=0;i<8;i++) com_release_handle(st->texture[i]);
}
static uint32_t new_block(Device *d) {
    for (uint32_t i=1;i<MAX_BLOCKS;i++) if (!g_blocks[i]) {
        DevState *block=malloc(sizeof *block);
        if (!block) return 0;
        *block=d->st; retain_block_textures(block); g_blocks[i]=block;
        return i;
    }
    return 0;
}
W(dev_BeginStateBlock) { dev(c)->recording_block = 1; RET(1, S_OK); }
W(dev_EndStateBlock) { Device *d = dev(c); d->recording_block = 0; W32(ARG(1), new_block(d)); RET(2, S_OK); }
W(dev_ApplyStateBlock) {
    Device *d=dev(c); uint32_t i=ARG(1);
    if (i<MAX_BLOCKS && g_blocks[i]) {
        uint32_t rt=d->st.render_target, ds=d->st.depth_stencil;
        uint32_t old[8]; memcpy(old,d->st.texture,sizeof old);
        retain_block_textures(g_blocks[i]);
        d->st=*g_blocks[i]; d->st.render_target=rt; d->st.depth_stencil=ds;
        for (int j=0;j<8;j++) com_release_handle(old[j]);
    }
    RET(2,S_OK);
}
W(dev_CaptureStateBlock) {
    uint32_t i=ARG(1); Device *d=dev(c);
    if (i<MAX_BLOCKS && g_blocks[i]) {
        retain_block_textures(&d->st); release_block_textures(g_blocks[i]); *g_blocks[i]=d->st;
    }
    RET(2,S_OK);
}
W(dev_DeleteStateBlock) {
    uint32_t i=ARG(1);
    if (i<MAX_BLOCKS && g_blocks[i]) { release_block_textures(g_blocks[i]); free(g_blocks[i]); g_blocks[i]=NULL; }
    RET(2,S_OK);
}
W(dev_CreateStateBlock) { W32(ARG(2), new_block(dev(c))); RET(3, S_OK); }
W(dev_SetClipStatus) { RET(2, S_OK); }
W(dev_GetClipStatus) { memset(HP(ARG(1)), 0, 8); RET(2, S_OK); }
W(dev_GetTexture) { out_addref(ARG(2), ARG(1) < 8 ? dev(c)->st.texture[ARG(1)] : 0); RET(3, S_OK); }
W(dev_SetTexture) {
    uint32_t stage=ARG(1), next=ARG(2); Device *d=dev(c);
    if (stage>=8) RET(3,D3DERR_INVALIDCALL);
    ComObj *o=next ? com_get(next) : NULL;
    if (next && (!o || (o->type!=RT_TEXTURE && o->type!=RT_CUBETEXTURE))) RET(3,D3DERR_INVALIDCALL);
    if (next) com_retain_handle(next);
    uint32_t old=d->st.texture[stage]; d->st.texture[stage]=next;
    com_release_handle(old);
    RET(3,S_OK);
}
W(dev_GetTextureStageState) { W32(ARG(3), ARG(1) < 8 && ARG(2) < 32 ? dev(c)->st.tss[ARG(1)][ARG(2)] : 0); RET(4, S_OK); }
W(dev_SetTextureStageState) { if (ARG(1) < 8 && ARG(2) < 32) dev(c)->st.tss[ARG(1)][ARG(2)] = ARG(3); RET(4, S_OK); }
W(dev_ValidateDevice) { if (ARG(1)) W32(ARG(1), 1); RET(2, S_OK); }
W(dev_GetInfo) { RET(4, 1 /* S_FALSE */); }
W(dev_SetPaletteEntries) { if (ARG(1) < 1024) memcpy(g_palettes[ARG(1)], HP(ARG(2)), 1024); RET(3, S_OK); }
W(dev_GetPaletteEntries) { if (ARG(1) < 1024) memcpy(HP(ARG(2)), g_palettes[ARG(1)], 1024); RET(3, S_OK); }
W(dev_SetCurrentTexturePalette) { dev(c)->st.palette_current = ARG(1); RET(2, S_OK); }
W(dev_GetCurrentTexturePalette) { W32(ARG(1), dev(c)->st.palette_current); RET(2, S_OK); }

/* primitive count -> vertex count */
static uint32_t prim_vertices(uint32_t prim, uint32_t n) {
    switch (prim) {
    case 1: return n;          /* point list */
    case 2: return n * 2;      /* line list */
    case 3: return n + 1;      /* line strip */
    case 4: return n * 3;      /* triangle list */
    case 5: case 6: return n + 2;  /* strip / fan */
    default: return 0;
    }
}

W(dev_DrawPrimitive) {
    Device *d = dev(c);
    d->draws_this_frame++;
    if (g_render->draw) g_render->draw(d, ARG(1), ARG(3), ARG(2), prim_vertices(ARG(1), ARG(3)), NULL, 0, NULL, 0, 0);
    RET(4, S_OK);
}
W(dev_DrawIndexedPrimitive) {
    Device *d = dev(c);
    d->draws_this_frame++;
    Buffer *ib = com_data(d->st.ib);
    if (g_render->draw && ib) {
        int i32 = ib->fvf_or_format == FMT_INDEX32;
        g_render->draw(d, ARG(1), ARG(5), ARG(2), ARG(3), NULL, 0, HP(ib->mem), i32, ARG(4));
    }
    RET(6, S_OK);
}
W(dev_DrawPrimitiveUP) {
    Device *d = dev(c);
    d->draws_this_frame++;
    if (g_render->draw)
        g_render->draw(d, ARG(1), ARG(2), 0, prim_vertices(ARG(1), ARG(2)), HP(ARG(3)), ARG(4), NULL, 0, 0);
    RET(5, S_OK);
}
W(dev_DrawIndexedPrimitiveUP) {
    Device *d = dev(c);
    d->draws_this_frame++;
    if (g_render->draw)
        g_render->draw(d, ARG(1), ARG(4), ARG(2), ARG(3), HP(ARG(7)), ARG(8), HP(ARG(5)), ARG(6) == FMT_INDEX32, 0);
    RET(9, S_OK);
}
W(dev_ProcessVertices) { RET(6, S_OK); }

/* Shaders */
#define MAX_SHADERS 4096
static Shader *g_shaders[MAX_SHADERS];
Shader *shader_get(uint32_t h) {
    uint32_t i = (h - 0x10001u) / 2;
    return (h & 1) && h >= 0x10001u && i < MAX_SHADERS ? g_shaders[i] : NULL;
}
static uint32_t copy_tokens(uint32_t p, uint32_t end_token, uint32_t **out) {
    if (!p) { *out = NULL; return 0; }
    uint32_t n = 0;
    while (R32(p + 4 * n) != end_token && n < 65536) n++;
    n++;
    *out = malloc(4 * n);
    memcpy(*out, HP(p), 4 * n);
    return n;
}
static uint32_t new_shader(Shader *s) {
    for (uint32_t i = 0; i < MAX_SHADERS; i++) if (!g_shaders[i]) { g_shaders[i] = s; return 0x10001u + 2 * i; }
    return 0;
}
W(dev_CreateVertexShader) {
    Shader *s = calloc(1, sizeof *s);
    s->decl_len = copy_tokens(ARG(1), 0xFFFFFFFFu, &s->decl);
    s->code_len = copy_tokens(ARG(2), 0x0000FFFFu, &s->code);
    uint32_t h = new_shader(s);
    if (g_log_d3d) fprintf(stderr, "[d3d] CreateVertexShader: %u decl tokens, %u code tokens (version %08x) -> %x\n",
                           s->decl_len, s->code_len, s->code ? s->code[0] : 0, h);
    W32(ARG(3), h);
    RET(5, S_OK);
}
W(dev_SetVertexShader) { dev(c)->st.vs = ARG(1); RET(2, S_OK); }
W(dev_GetVertexShader) { W32(ARG(1), dev(c)->st.vs); RET(2, S_OK); }
W(dev_DeleteVertexShader) { RET(2, S_OK); }
W(dev_SetVertexShaderConstant) {
    uint32_t r = ARG(1), n = ARG(3);
    static int watch = -2;
    if (watch == -2) watch = getenv("PORT_WATCH_VSC") ? atoi(getenv("PORT_WATCH_VSC")) : -1;
    if (watch >= 0 && (uint32_t)watch >= r && (uint32_t)watch < r + n) {
        const float *f = (const float *)HP(ARG(2) + 16 * ((uint32_t)watch - r));
        fprintf(stderr, "[vsc] frame %u: c%d = %g %g %g %g (data %08x, call c%u x%u from %08x; stack", dev(c)->frame, watch, f[0], f[1],
                f[2], f[3], ARG(2) + 16 * ((uint32_t)watch - r), r, n, R32(c->esp));
        for (int k = 1; k < 24; k++) { uint32_t v = R32(c->esp + 4 * k); if (looks_like_code(v)) fprintf(stderr, " %08x", v); }
        fprintf(stderr, ")\n");
        extern void watch_arm(uint32_t addr);
        if (getenv("PORT_WATCH_ARM") && f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0)
            watch_arm(ARG(2) + 16 * ((uint32_t)watch - r));
    }
    if (r < 96) memcpy(dev(c)->st.vs_const[r], HP(ARG(2)), 16 * (r + n > 96 ? 96 - r : n));
    RET(4, S_OK);
}
W(dev_GetVertexShaderConstant) {
    uint32_t r = ARG(1), n = ARG(3);
    if (r < 96) memcpy(HP(ARG(2)), dev(c)->st.vs_const[r], 16 * (r + n > 96 ? 96 - r : n));
    RET(4, S_OK);
}
W(dev_GetVertexShaderDeclaration) { RET(4, D3DERR_INVALIDCALL); }
W(dev_GetVertexShaderFunction) { RET(4, D3DERR_INVALIDCALL); }
W(dev_SetStreamSource) {
    if (ARG(1) < 16) { dev(c)->st.stream_vb[ARG(1)] = ARG(2); dev(c)->st.stream_stride[ARG(1)] = ARG(3); }
    RET(4, S_OK);
}
W(dev_GetStreamSource) {
    if (ARG(1) < 16) { out_addref(ARG(2), dev(c)->st.stream_vb[ARG(1)]); W32(ARG(3), dev(c)->st.stream_stride[ARG(1)]); }
    RET(4, S_OK);
}
W(dev_SetIndices) { dev(c)->st.ib = ARG(1); dev(c)->st.base_vertex = ARG(2); RET(3, S_OK); }
W(dev_GetIndices) { out_addref(ARG(1), dev(c)->st.ib); W32(ARG(2), dev(c)->st.base_vertex); RET(3, S_OK); }
W(dev_CreatePixelShader) {
    Shader *s = calloc(1, sizeof *s);
    s->pixel = 1;
    s->code_len = copy_tokens(ARG(1), 0x0000FFFFu, &s->code);
    uint32_t h = new_shader(s);
    if (g_log_d3d) fprintf(stderr, "[d3d] CreatePixelShader: %u tokens (version %08x) -> %x\n", s->code_len,
                           s->code ? s->code[0] : 0, h);
    W32(ARG(2), h);
    RET(3, S_OK);
}
W(dev_SetPixelShader) { dev(c)->st.ps = ARG(1); RET(2, S_OK); }
W(dev_GetPixelShader) { W32(ARG(1), dev(c)->st.ps); RET(2, S_OK); }
W(dev_DeletePixelShader) { RET(2, S_OK); }
W(dev_SetPixelShaderConstant) {
    uint32_t r = ARG(1), n = ARG(3);
    if (r < 8) memcpy(dev(c)->st.ps_const[r], HP(ARG(2)), 16 * (r + n > 8 ? 8 - r : n));
    RET(4, S_OK);
}
W(dev_GetPixelShaderConstant) {
    uint32_t r = ARG(1), n = ARG(3);
    if (r < 8) memcpy(HP(ARG(2)), dev(c)->st.ps_const[r], 16 * (r + n > 8 ? 8 - r : n));
    RET(4, S_OK);
}
W(dev_GetPixelShaderFunction) { RET(4, D3DERR_INVALIDCALL); }
W(dev_SetCursorProperties) { RET(4, S_OK); }
W(dev_SetCursorPosition) { RET(4, S_OK); }
W(dev_ShowCursor) { RET(2, 0); }

static const ComMethod dev_methods[] = {
    { "QueryInterface", 2, com_QueryInterface }, { "AddRef", 0, com_AddRef }, { "Release", 0, com_Release },
    { "TestCooperativeLevel", 0, dev_TestCooperativeLevel }, { "GetAvailableTextureMem", 0, dev_GetAvailableTextureMem },
    { "ResourceManagerDiscardBytes", 1, dev_ResourceManagerDiscardBytes }, { "GetDirect3D", 1, dev_GetDirect3D },
    { "GetDeviceCaps", 1, dev_GetDeviceCaps }, { "GetDisplayMode", 1, dev_GetDisplayMode },
    { "GetCreationParameters", 1, dev_GetCreationParameters }, { "SetCursorProperties", 3, dev_SetCursorProperties },
    { "SetCursorPosition", 3, dev_SetCursorPosition }, { "ShowCursor", 1, dev_ShowCursor },
    { "CreateAdditionalSwapChain", 2, dev_CreateAdditionalSwapChain }, { "Reset", 1, dev_Reset },
    { "Present", 4, dev_Present }, { "GetBackBuffer", 3, dev_GetBackBuffer },
    { "GetRasterStatus", 1, dev_GetRasterStatus }, { "SetGammaRamp", 2, dev_SetGammaRamp },
    { "GetGammaRamp", 1, dev_GetGammaRamp }, { "CreateTexture", 7, dev_CreateTexture },
    { "CreateVolumeTexture", 8, dev_CreateVolumeTexture }, { "CreateCubeTexture", 6, dev_CreateCubeTexture },
    { "CreateVertexBuffer", 5, dev_CreateVertexBuffer }, { "CreateIndexBuffer", 5, dev_CreateIndexBuffer },
    { "CreateRenderTarget", 6, dev_CreateRenderTarget }, { "CreateDepthStencilSurface", 5, dev_CreateDepthStencilSurface },
    { "CreateImageSurface", 4, dev_CreateImageSurface }, { "CopyRects", 5, dev_CopyRects },
    { "UpdateTexture", 2, dev_UpdateTexture }, { "GetFrontBuffer", 1, dev_GetFrontBuffer },
    { "SetRenderTarget", 2, dev_SetRenderTarget }, { "GetRenderTarget", 1, dev_GetRenderTarget },
    { "GetDepthStencilSurface", 1, dev_GetDepthStencilSurface }, { "BeginScene", 0, dev_BeginScene },
    { "EndScene", 0, dev_EndScene }, { "Clear", 6, dev_Clear }, { "SetTransform", 2, dev_SetTransform },
    { "GetTransform", 2, dev_GetTransform }, { "MultiplyTransform", 2, dev_MultiplyTransform },
    { "SetViewport", 1, dev_SetViewport }, { "GetViewport", 1, dev_GetViewport },
    { "SetMaterial", 1, dev_SetMaterial }, { "GetMaterial", 1, dev_GetMaterial }, { "SetLight", 2, dev_SetLight },
    { "GetLight", 2, dev_GetLight }, { "LightEnable", 2, dev_LightEnable }, { "GetLightEnable", 2, dev_GetLightEnable },
    { "SetClipPlane", 2, dev_SetClipPlane }, { "GetClipPlane", 2, dev_GetClipPlane },
    { "SetRenderState", 2, dev_SetRenderState }, { "GetRenderState", 2, dev_GetRenderState },
    { "BeginStateBlock", 0, dev_BeginStateBlock }, { "EndStateBlock", 1, dev_EndStateBlock },
    { "ApplyStateBlock", 1, dev_ApplyStateBlock }, { "CaptureStateBlock", 1, dev_CaptureStateBlock },
    { "DeleteStateBlock", 1, dev_DeleteStateBlock }, { "CreateStateBlock", 2, dev_CreateStateBlock },
    { "SetClipStatus", 1, dev_SetClipStatus }, { "GetClipStatus", 1, dev_GetClipStatus },
    { "GetTexture", 2, dev_GetTexture }, { "SetTexture", 2, dev_SetTexture },
    { "GetTextureStageState", 3, dev_GetTextureStageState }, { "SetTextureStageState", 3, dev_SetTextureStageState },
    { "ValidateDevice", 1, dev_ValidateDevice }, { "GetInfo", 3, dev_GetInfo },
    { "SetPaletteEntries", 2, dev_SetPaletteEntries }, { "GetPaletteEntries", 2, dev_GetPaletteEntries },
    { "SetCurrentTexturePalette", 1, dev_SetCurrentTexturePalette },
    { "GetCurrentTexturePalette", 1, dev_GetCurrentTexturePalette }, { "DrawPrimitive", 3, dev_DrawPrimitive },
    { "DrawIndexedPrimitive", 5, dev_DrawIndexedPrimitive }, { "DrawPrimitiveUP", 4, dev_DrawPrimitiveUP },
    { "DrawIndexedPrimitiveUP", 8, dev_DrawIndexedPrimitiveUP }, { "ProcessVertices", 5, dev_ProcessVertices },
    { "CreateVertexShader", 4, dev_CreateVertexShader }, { "SetVertexShader", 1, dev_SetVertexShader },
    { "GetVertexShader", 1, dev_GetVertexShader }, { "DeleteVertexShader", 1, dev_DeleteVertexShader },
    { "SetVertexShaderConstant", 3, dev_SetVertexShaderConstant },
    { "GetVertexShaderConstant", 3, dev_GetVertexShaderConstant },
    { "GetVertexShaderDeclaration", 3, dev_GetVertexShaderDeclaration },
    { "GetVertexShaderFunction", 3, dev_GetVertexShaderFunction }, { "SetStreamSource", 3, dev_SetStreamSource },
    { "GetStreamSource", 3, dev_GetStreamSource }, { "SetIndices", 2, dev_SetIndices },
    { "GetIndices", 2, dev_GetIndices }, { "CreatePixelShader", 2, dev_CreatePixelShader },
    { "SetPixelShader", 1, dev_SetPixelShader }, { "GetPixelShader", 1, dev_GetPixelShader },
    { "DeletePixelShader", 1, dev_DeletePixelShader }, { "SetPixelShaderConstant", 3, dev_SetPixelShaderConstant },
    { "GetPixelShaderConstant", 3, dev_GetPixelShaderConstant },
    { "GetPixelShaderFunction", 3, dev_GetPixelShaderFunction }, { "DrawRectPatch", 3, NULL },
    { "DrawTriPatch", 3, NULL }, { "DeletePatch", 1, NULL },
};
static ComInterface IDirect3DDevice8_i = { "IDirect3DDevice8", dev_methods, 97, 0 };

/* ------------------------------------------------------------------ common resource methods */

static void out_addref(uint32_t out, uint32_t obj);
W(res_GetDevice) { out_addref(ARG(1), g_device_object); RET(2, g_device_object ? S_OK : D3DERR_INVALIDCALL); }
W(res_SetPrivateData) { RET(5, S_OK); }
W(res_GetPrivateData) { RET(4, 0x88760866u /* D3DERR_NOTFOUND */); }
W(res_FreePrivateData) { RET(2, S_OK); }
W(res_SetPriority) { RET(2, 0); }
W(res_GetPriority) { RET(1, 0); }
W(res_PreLoad) { RET(1, 0); }
W(res_GetType) { ComObj *o = com_get(THIS); RET(1, o ? (uint32_t)o->type : 0); }
W(tex_SetLOD) { RET(2, 0); }
W(tex_GetLOD) { RET(1, 0); }
W(tex_GetLevelCount) { Texture *t = com_data(THIS); RET(1, t ? t->levels : 1); }

#define RESOURCE_METHODS \
    { "QueryInterface", 2, com_QueryInterface }, { "AddRef", 0, com_AddRef }, { "Release", 0, com_Release }, \
    { "GetDevice", 1, res_GetDevice }, { "SetPrivateData", 4, res_SetPrivateData }, \
    { "GetPrivateData", 3, res_GetPrivateData }, { "FreePrivateData", 1, res_FreePrivateData }, \
    { "SetPriority", 1, res_SetPriority }, { "GetPriority", 0, res_GetPriority }, { "PreLoad", 0, res_PreLoad }, \
    { "GetType", 0, res_GetType }
#define BASETEXTURE_METHODS RESOURCE_METHODS, { "SetLOD", 1, tex_SetLOD }, { "GetLOD", 0, tex_GetLOD }, \
    { "GetLevelCount", 0, tex_GetLevelCount }

static void write_desc(uint32_t p, uint32_t fmt, uint32_t type, uint32_t usage, uint32_t pool, uint32_t size,
                       uint32_t w, uint32_t h) {
    W32(p, fmt); W32(p + 4, type); W32(p + 8, usage); W32(p + 12, pool); W32(p + 16, size); W32(p + 20, 0);
    W32(p + 24, w); W32(p + 28, h);
}

static uint32_t texture_surface(uint32_t tex_obj, Texture *t, uint32_t face, uint32_t level) {
    if (!t->surfaces[face][level]) {
        if (!com_get(tex_obj)) return 0;
        Surface *s=calloc(1,sizeof *s);
        if (!s) return 0;
        int first_rt_surface=0;
        if (t->usage & 1) {
            if (!t->rt_surface_ids[face][level]) { t->rt_surface_ids[face][level]=gpu_new_id(); first_rt_surface=1; }
            s->gpu_id=t->rt_surface_ids[face][level];
        } else s->gpu_id=gpu_new_id();
        s->format=t->format; s->width=t->lw[level]; s->height=t->lh[level]; s->pitch=t->pitch[level];
        s->mem=t->mem[face][level]; s->container=tex_obj; s->face=(int)face; s->level=(int)level;
        s->is_rt=(t->usage & 1)!=0; s->is_depth=(t->usage & 2)!=0;
        /* Parent is retained by the surface, while this table is a weak cache. */
        com_retain_handle(tex_obj);
        t->surfaces[face][level]=com_new(&IDirect3DSurface8_i,RT_SURFACE,s);
        /* A first RT view must preserve CPU data written before GetSurface:
           a depth-only clear or partially covering draw must not replace the
           untouched pixels with WebGPU's zero-initialized texture. Do not
           reupload when this COM view is later recreated: GPU may be newer. */
        if (first_rt_surface && g_device && g_render->upload_surface &&
            !g_render->upload_surface(g_device,s)) {
            /* No initial GPU data exists: discard the view and allow retry. */
            t->rt_surface_ids[face][level]=0;
            com_release_handle(t->surfaces[face][level]);
            return 0;
        }
        return t->surfaces[face][level]; /* com_new supplied the caller's reference */
    }
    com_retain_handle(t->surfaces[face][level]);
    return t->surfaces[face][level];
}
static void destroy_texture(void *p) {
    Texture *t = p;
    /* Rendered face storage belongs to the parent, not a transient COM view. */
    if (g_render->destroy_surface) for (uint32_t f=0;f<t->faces;f++) for (uint32_t l=0;l<t->levels;l++) {
        if (t->rt_surface_ids[f][l]) {
            Surface temporary={0}; temporary.gpu_id=t->rt_surface_ids[f][l];
            g_render->destroy_surface(&temporary);
        }
    }
    if (g_render->destroy_texture) g_render->destroy_texture(t);
    for (uint32_t f = 0; f < t->faces; f++)
        for (uint32_t l = 0; l < t->levels; l++) {
            heap_free(t->mem[f][l]);
            /* level surfaces handed out earlier point into this memory: detach them */
            Surface *s = t->surfaces[f][l] ? com_data(t->surfaces[f][l]) : NULL;
            if (s) { s->mem = 0; s->container = 0; }
        }
    free(t);
}
static void destroy_surface(void *p) {
    Surface *s=p; uint32_t parent=s->container;
    /* Parent-owned RT storage survives destruction/recreation of its COM view. */
    if ((!parent || !s->is_rt) && g_render->destroy_surface) g_render->destroy_surface(s);
    if (!parent && s->mem) heap_free(s->mem);
    if (parent) {
        Texture *t=com_data(parent);
        if (t && s->face>=0 && s->face<6 && s->level>=0 && s->level<14)
            t->surfaces[s->face][s->level]=0;
    }
    free(s);
    if (parent) com_release_handle(parent);
}
static void destroy_buffer(void *p) { Buffer *b = p; heap_free(b->mem); free(b); }

/* IDirect3DTexture8 */
W(tx_GetLevelDesc) {
    Texture *t = com_data(THIS);
    uint32_t l = ARG(1);
    if (!t || l >= t->levels) RET(3, D3DERR_INVALIDCALL);
    write_desc(ARG(2), t->format, RT_SURFACE, t->usage, t->pool, t->size[l], t->lw[l], t->lh[l]);
    RET(3, S_OK);
}
W(tx_GetSurfaceLevel) {
    Texture *t = com_data(THIS);
    if (!t || ARG(1) >= t->levels) RET(3, D3DERR_INVALIDCALL);
    uint32_t surface=texture_surface(THIS, t, 0, ARG(1));
    W32(ARG(2),surface); RET(3,surface ? S_OK : 0x8007000Eu);
}
static void lock_rect(uint32_t out, uint32_t mem, uint32_t pitch, uint32_t fmt, uint32_t rect) {
    uint32_t off = 0;
    if (rect) {
        uint32_t x = R32(rect), y = R32(rect + 4);
        if (format_is_dxt(fmt)) off = (y / 4) * pitch + (x / 4) * (fmt == FMT_DXT1 ? 8 : 16);
        else off = y * pitch + x * format_bpp(fmt) / 8;
    }
    W32(out, pitch);
    W32(out + 4, mem + off);
}
W(tx_LockRect) {
    Texture *t = com_data(THIS);
    uint32_t l = ARG(1);
    if (!t || l >= t->levels) RET(5, D3DERR_INVALIDCALL);
    if (!d3d_sync_texture_rt(g_device,t)) RET(5,0x8007000Eu);
    Surface surface;
    if (texture_rt_surface(t,0,l,&surface) && g_device && g_render->readback && !g_render->readback(g_device,&surface)) RET(5,0x8007000Eu);
    lock_rect(ARG(2), t->mem[0][l], t->pitch[l], t->format, ARG(3));
    RET(5, S_OK);
}
W(tx_UnlockRect) {
    Texture *t=com_data(THIS); uint32_t l=ARG(1);
    if (!t || l>=t->levels || l>=14) RET(2,D3DERR_INVALIDCALL);
    t->version++; if (t->rt_surface_ids[0][l]) t->rt_cpu_dirty[0][l]=1;
    RET(2,d3d_sync_texture_rt(g_device,t) ? S_OK : 0x8007000Eu);
}
W(tx_AddDirtyRect) { RET(2, S_OK); }

static const ComMethod tex_methods[] = {
    BASETEXTURE_METHODS, { "GetLevelDesc", 2, tx_GetLevelDesc }, { "GetSurfaceLevel", 2, tx_GetSurfaceLevel },
    { "LockRect", 4, tx_LockRect }, { "UnlockRect", 1, tx_UnlockRect }, { "AddDirtyRect", 1, tx_AddDirtyRect },
};
static ComInterface IDirect3DTexture8_i = { "IDirect3DTexture8", tex_methods, 19, 0, destroy_texture };

/* IDirect3DCubeTexture8 */
W(cube_GetCubeMapSurface) {
    Texture *t = com_data(THIS);
    if (!t || ARG(1) > 5 || ARG(2) >= t->levels) RET(4, D3DERR_INVALIDCALL);
    uint32_t surface=texture_surface(THIS, t, ARG(1), ARG(2));
    W32(ARG(3),surface); RET(4,surface ? S_OK : 0x8007000Eu);
}
W(cube_LockRect) {
    Texture *t = com_data(THIS);
    uint32_t f = ARG(1), l = ARG(2);
    if (!t || f > 5 || l >= t->levels) RET(6, D3DERR_INVALIDCALL);
    Surface surface;
    if (!d3d_sync_texture_rt(g_device,t)) RET(6,0x8007000Eu);
    if (texture_rt_surface(t,f,l,&surface) && g_device && g_render->readback && !g_render->readback(g_device,&surface)) RET(6,0x8007000Eu);
    lock_rect(ARG(3), t->mem[f][l], t->pitch[l], t->format, ARG(4));
    RET(6, S_OK);
}
W(cube_UnlockRect) {
    Texture *t=com_data(THIS); uint32_t f=ARG(1),l=ARG(2);
    if (!t || f>=t->faces || l>=t->levels || l>=14) RET(3,D3DERR_INVALIDCALL);
    t->version++;
    Surface surface;
    if (texture_rt_surface(t,f,l,&surface)) t->rt_cpu_dirty[f][l]=1;
    RET(3,d3d_sync_texture_rt(g_device,t) ? S_OK : 0x8007000Eu);
}
W(cube_AddDirtyRect) { RET(3, S_OK); }
static const ComMethod cube_methods[] = {
    BASETEXTURE_METHODS, { "GetLevelDesc", 2, tx_GetLevelDesc }, { "GetCubeMapSurface", 3, cube_GetCubeMapSurface },
    { "LockRect", 5, cube_LockRect }, { "UnlockRect", 2, cube_UnlockRect }, { "AddDirtyRect", 2, cube_AddDirtyRect },
};
static ComInterface IDirect3DCubeTexture8_i = { "IDirect3DCubeTexture8", cube_methods, 19, 0, destroy_texture };

static const ComMethod vol_methods[] = {
    BASETEXTURE_METHODS, { "GetLevelDesc", 2, NULL }, { "GetVolumeLevel", 2, NULL }, { "LockBox", 4, NULL },
    { "UnlockBox", 1, NULL }, { "AddDirtyBox", 1, NULL },
};
static ComInterface IDirect3DVolumeTexture8_i __attribute__((unused)) = { "IDirect3DVolumeTexture8", vol_methods, 19, 0 };

/* IDirect3DSurface8 */
W(surf_GetDevice) { out_addref(ARG(1), g_device_object); RET(2, g_device_object ? S_OK : D3DERR_INVALIDCALL); }
W(surf_GetContainer) {
    Surface *s = com_data(THIS);
    if (!s || !s->container) RET(3, D3DERR_INVALIDCALL);
    out_addref(ARG(2), s->container);
    RET(3, S_OK);
}
W(surf_GetDesc) {
    Surface *s = com_data(THIS);
    if (!s) RET(2, D3DERR_INVALIDCALL);
    write_desc(ARG(1), s->format, RT_SURFACE, s->is_rt ? 1 : s->is_depth ? 2 : 0, 0,
               s->pitch * level_rows(s->format, s->height), s->width, s->height);
    RET(2, S_OK);
}
W(surf_LockRect) {
    Surface *s = com_data(THIS);
    if (!s) RET(4, D3DERR_INVALIDCALL);
    if (!d3d_sync_surface(g_device,s)) RET(4,0x8007000Eu);
    if (g_device && is_gpu_surface(g_device,s) && g_render->readback && !g_render->readback(g_device,s)) RET(4,0x8007000Eu);
    if (!s->mem) s->mem = heap_alloc(s->pitch * level_rows(s->format, s->height) + 16, 1);
    lock_rect(ARG(1), s->mem, s->pitch, s->format, ARG(2));
    RET(4, S_OK);
}
W(surf_UnlockRect) {
    Surface *s = com_data(THIS);
    if (s) touch_container(s);
    RET(1,surface_changed(g_device,s) ? S_OK : 0x8007000Eu);
}
static const ComMethod surf_methods[] = {
    { "QueryInterface", 2, com_QueryInterface }, { "AddRef", 0, com_AddRef }, { "Release", 0, com_Release },
    { "GetDevice", 1, surf_GetDevice }, { "SetPrivateData", 4, res_SetPrivateData },
    { "GetPrivateData", 3, res_GetPrivateData }, { "FreePrivateData", 1, res_FreePrivateData },
    { "GetContainer", 2, surf_GetContainer }, { "GetDesc", 1, surf_GetDesc }, { "LockRect", 3, surf_LockRect },
    { "UnlockRect", 0, surf_UnlockRect },
};
static ComInterface IDirect3DSurface8_i = { "IDirect3DSurface8", surf_methods, 11, 0, destroy_surface };

/* Vertex / index buffers */
W(buf_Lock) {
    Buffer *b = com_data(THIS);
    if (!b) RET(5, D3DERR_INVALIDCALL);
    W32(ARG(3), b->mem + ARG(1));
    RET(5, S_OK);
}
W(buf_Unlock) { Buffer *b = com_data(THIS); if (b) b->version++; RET(1, S_OK); }
W(buf_GetDesc) {
    Buffer *b = com_data(THIS);
    uint32_t p = ARG(1);
    if (!b) RET(2, D3DERR_INVALIDCALL);
    W32(p, b->index ? b->fvf_or_format : 100 /* D3DFMT_VERTEXDATA */);
    W32(p + 4, b->index ? RT_INDEXBUFFER : RT_VERTEXBUFFER);
    W32(p + 8, b->usage); W32(p + 12, b->pool); W32(p + 16, b->size);
    if (!b->index) W32(p + 20, b->fvf_or_format);
    RET(2, S_OK);
}
static const ComMethod vb_methods[] = {
    RESOURCE_METHODS, { "Lock", 4, buf_Lock }, { "Unlock", 0, buf_Unlock }, { "GetDesc", 1, buf_GetDesc },
};
static ComInterface IDirect3DVertexBuffer8_i = { "IDirect3DVertexBuffer8", vb_methods, 14, 0, destroy_buffer };
static ComInterface IDirect3DIndexBuffer8_i = { "IDirect3DIndexBuffer8", vb_methods, 14, 0, destroy_buffer };

static const ComMethod sc_methods[] = {
    { "QueryInterface", 2, com_QueryInterface }, { "AddRef", 0, com_AddRef }, { "Release", 0, com_Release },
    { "Present", 4, NULL }, { "GetBackBuffer", 3, NULL },
};
static ComInterface IDirect3DSwapChain8_i __attribute__((unused)) = { "IDirect3DSwapChain8", sc_methods, 5, 0 };

/* ------------------------------------------------------------------ headless backend */

/* Headless "vsync": pace Present to 60 Hz like a real display would. */
static void hl_present(Device *d) {
    (void)d;
#ifdef PORT_HEAP_STATS   /* диагностика (K3): PORT_HL_NOPACE=<кадр> снимает 60-Гц паузу начиная с этого кадра (1 — с начала),
                            чтобы прогнать много кадров быстрее реального времени; без переменной поведение прежнее */
    static long nopace_from = -2;
    if (nopace_from == -2) { const char *e = getenv("PORT_HL_NOPACE"); nopace_from = e ? atol(e) : -1; }
    if (nopace_from >= 0 && (long)d->frame >= nopace_from) return;
#endif
    static double next;
    double now = host_seconds();
    if (next == 0 || now - next > 0.1) next = now;
    next += 1.0 / 60.0;
    if (next > now) usleep((useconds_t)((next - now) * 1e6));
}
RenderBackend g_render_headless = { "headless", NULL, NULL, NULL, hl_present, NULL };
