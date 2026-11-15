/* Texture stages 2-3 (audit W6): synthetic checks of the recorder's stage-state packing and the
 * fixed-function multi-stage blend formula.
 *
 * The WGSL formula (render_wgpu.c WGSL_FF: arg/top/stage plus the fs stage chain) is mirrored in C
 * below - d3d_arg/d3d_top/d3d_stage/ff_chain_new cite the WGSL line each statement implements, and
 * ff_chain_old reproduces the pre-W6 two-stage fs. The tests prove that the generalized four-stage
 * chain returns the identical result whenever stages 2-3 are disabled (shipped two-stage passes),
 * and evaluate the real shipped stage-2 cases (location/maineffects.sha modulate2x, artifact.sha
 * modulate) against hand-computed values, plus SELECTARG1/alpha-op/disable-termination on stage 2
 * and the pack_stages gate. CPU-side only: no GPU, no browser; the WGSL text itself compiles in the
 * next full build. The specular/fog tails of the fixed-function fs are unchanged by W6 and are
 * covered by test_fog/test_lighting.
 * Run: sh recomp/tests/run_texstage.sh   (native ASan/UBSan).
 * D3DCOLOR note: 0xAARRGGBB - d3dcolor reads r from bits 16-23, g from 8-15, b from 0-7. */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../host/render_rec.c"   /* Uniforms, pack_stages, DevState */

/* d3d8types.h values */
enum { D3DTOP_DISABLE = 1, D3DTOP_SELECTARG1 = 2, D3DTOP_SELECTARG2 = 3, D3DTOP_MODULATE = 4,
       D3DTOP_MODULATE2X = 5, D3DTOP_ADD = 7, D3DTOP_ADDSIGNED = 8, D3DTOP_ADDSIGNED2X = 9,
       D3DTOP_BLENDDIFFUSEALPHA = 12, D3DTOP_BLENDFACTORALPHA = 14, D3DTOP_LERP = 26 };
enum { D3DTA_DIFFUSE = 0, D3DTA_CURRENT = 1, D3DTA_TEXTURE = 2, D3DTA_TFACTOR = 3, D3DTA_SPECULAR = 4 };

static float sat1(float v) { return v < 0 ? 0 : v > 1 ? 1 : v; }
static int near_v(const float *a, const float *b) {
    for (int i = 0; i < 4; i++) if (fabsf(a[i] - b[i]) >= 1e-6f) return 0;
    return 1;
}
static void print_v(const char *tag, const float *v) {
    printf("  %s = (%.4f, %.4f, %.4f, %.4f)\n", tag, v[0], v[1], v[2], v[3]);
}

/* WGSL: fn d3dcolor(c: u32) -> vec4<f32> { return unpack4x8unorm(c).zyxw; } (ARGB byte order) */
static void d3dcolor(uint32_t c, float *v) {
    v[0] = ((c >> 16) & 255) / 255.f; v[1] = ((c >> 8) & 255) / 255.f;
    v[2] = (c & 255) / 255.f; v[3] = (c >> 24) / 255.f;
}

/* WGSL: fn arg(a: u32, cur, tex, dif, spc) -> vec4<f32> {
 *   var v = cur;
 *   switch (a & 7u) { case 0u: { v = dif; } case 2u: { v = tex; } case 3u: { v = u.tfactor; }
 *                     case 4u: { v = spc; } default: {} }
 *   if ((a & 0x10u) != 0u) { v = vec4<f32>(1.0) - v; }
 *   if ((a & 0x20u) != 0u) { v = vec4<f32>(v.a); }
 *   return v; } */
static void d3d_arg(uint32_t a, const float *cur, const float *tex, const float *dif, const float *spc,
                    const float *tf, float *v) {
    memcpy(v, cur, 4 * sizeof(float));
    switch (a & 7u) {
    case 0: memcpy(v, dif, 16); break;    /* D3DTA_DIFFUSE */
    case 2: memcpy(v, tex, 16); break;    /* D3DTA_TEXTURE */
    case 3: memcpy(v, tf, 16); break;     /* D3DTA_TFACTOR */
    case 4: memcpy(v, spc, 16); break;    /* D3DTA_SPECULAR */
    default: break;                       /* 1 = D3DTA_CURRENT */
    }
    if (a & 0x10u) for (int i = 0; i < 4; i++) v[i] = 1.f - v[i];                 /* COMPLEMENT */
    if (a & 0x20u) { float al = v[3]; for (int i = 0; i < 4; i++) v[i] = al; }    /* ALPHAREPLICATE */
}

/* WGSL: fn top(o: u32, a0, a1, a2, cur, tex, dif) -> vec4<f32> { switch (o) { ... } } */
static void d3d_top(uint32_t o, const float *a0, const float *a1, const float *a2,
                    const float *cur, const float *tex, const float *dif, const float *tf, float *out) {
    switch (o) {
    case 2: memcpy(out, a1, 16); break;                          /* SELECTARG1 */
    case 3: memcpy(out, a2, 16); break;                          /* SELECTARG2 */
    case 4: for (int i = 0; i < 4; i++) out[i] = a1[i] * a2[i]; break;
    case 5: for (int i = 0; i < 4; i++) out[i] = a1[i] * a2[i] * 2.f; break;
    case 6: for (int i = 0; i < 4; i++) out[i] = a1[i] * a2[i] * 4.f; break;
    case 7: for (int i = 0; i < 4; i++) out[i] = a1[i] + a2[i]; break;
    case 8: for (int i = 0; i < 4; i++) out[i] = a1[i] + a2[i] - 0.5f; break;
    case 9: for (int i = 0; i < 4; i++) out[i] = (a1[i] + a2[i] - 0.5f) * 2.f; break;
    case 10: for (int i = 0; i < 4; i++) out[i] = a1[i] - a2[i]; break;
    case 11: for (int i = 0; i < 4; i++) out[i] = a1[i] + a2[i] - a1[i] * a2[i]; break;
    case 12: for (int i = 0; i < 4; i++) out[i] = a2[i] + (a1[i] - a2[i]) * dif[3]; break;
    case 13: for (int i = 0; i < 4; i++) out[i] = a2[i] + (a1[i] - a2[i]) * tex[3]; break;
    case 14: for (int i = 0; i < 4; i++) out[i] = a2[i] + (a1[i] - a2[i]) * tf[3]; break;
    case 15: for (int i = 0; i < 4; i++) out[i] = a1[i] + a2[i] * (1.f - tex[3]); break;
    case 16: for (int i = 0; i < 4; i++) out[i] = a2[i] + (a1[i] - a2[i]) * cur[3]; break;
    case 18: for (int i = 0; i < 3; i++) out[i] = a1[i] + a1[3] * a2[i]; out[3] = a1[3]; break;
    case 19: for (int i = 0; i < 3; i++) out[i] = a1[i] * a2[i] + a1[3]; out[3] = a1[3]; break;
    case 20: for (int i = 0; i < 3; i++) out[i] = (1.f - a1[3]) * a2[i] + a1[i]; out[3] = a1[3]; break;
    case 21: for (int i = 0; i < 3; i++) out[i] = (1.f - a1[i]) * a2[i] + a1[3]; out[3] = a1[3]; break;
    case 24: {
        float d = (a1[0] - .5f) * (a2[0] - .5f) + (a1[1] - .5f) * (a2[1] - .5f) + (a1[2] - .5f) * (a2[2] - .5f);
        d = sat1(d * 4.f);
        for (int i = 0; i < 4; i++) out[i] = d;
        break;
    }
    case 25: for (int i = 0; i < 4; i++) out[i] = a0[i] + a1[i] * a2[i]; break;
    case 26: for (int i = 0; i < 4; i++) out[i] = a0[i] * a1[i] + (1.f - a0[i]) * a2[i]; break;
    default: memcpy(out, a1, 16); break;
    }
}

/* WGSL: fn stage(s: vec4<u32>, sb: vec4<u32>, cur, tex, dif, spc) -> vec4<f32> {
 *   let c0 = arg(sb.w & 255u, ...); let c = top(s.x, c0, arg(s.y), arg(s.z), cur, tex, dif);
 *   var a = cur.a; if (s.w > 1u) { a = top(s.w, arg(sb.w >> 8u), arg(sb.x), arg(sb.y), ...).a; }
 *   return saturate(vec4<f32>(c.rgb, a)); } */
static void d3d_stage(const uint32_t *s, const uint32_t *sb, const float *cur, const float *tex,
                      const float *dif, const float *spc, const float *tf, float *out) {
    float c0[4], a1[4], a2[4], a0[4], c[4], ta[4];
    d3d_arg(sb[3] & 255u, cur, tex, dif, spc, tf, c0);
    d3d_arg(s[1], cur, tex, dif, spc, tf, a1);
    d3d_arg(s[2], cur, tex, dif, spc, tf, a2);
    d3d_top(s[0], c0, a1, a2, cur, tex, dif, tf, c);
    float a = cur[3];
    if (s[3] > 1u) {
        d3d_arg(sb[3] >> 8u, cur, tex, dif, spc, tf, a0);
        d3d_arg(sb[0], cur, tex, dif, spc, tf, a1);
        d3d_arg(sb[1], cur, tex, dif, spc, tf, a2);
        d3d_top(s[3], a0, a1, a2, cur, tex, dif, tf, ta);
        a = ta[3];
    }
    out[0] = sat1(c[0]); out[1] = sat1(c[1]); out[2] = sat1(c[2]); out[3] = sat1(a);
}

/* the fixed-function fs stage chain of render_wgpu.c: the pre-W6 two-stage evaluation and the
 * generalized 0-3 one. Stages 2-3 sample tex2/tex3 (i.tc2/i.tc3), the D3D8 default per-stage
 * texcoord index; a DISABLE (or unpacked zero) stage ends the rest of the pipeline, so each stage
 * gates the next one - exactly like the nested ifs in the WGSL. The specular/fog tails after the
 * chain are byte-identical in the old and new WGSL and are not part of this comparison. */
static void ff_chain_old(const Uniforms *u, const float *dif, const float *spc, const float *tf,
                         const float tex[4][4], float *out) {
    float cur[4], tmp[4];
    memcpy(cur, dif, 16);
    if (u->st0[0] != 1u) {
        d3d_stage(u->st0, u->st0b, cur, tex[0], dif, spc, tf, tmp);
        memcpy(cur, tmp, 16);
        if (u->st1[0] != 1u) {
            d3d_stage(u->st1, u->st1b, cur, tex[1], dif, spc, tf, tmp);
            memcpy(cur, tmp, 16);
        }
    }
    memcpy(out, cur, 16);
}
static void ff_chain_new(const Uniforms *u, const float *dif, const float *spc, const float *tf,
                         const float tex[4][4], float *out) {
    float cur[4], tmp[4];
    memcpy(cur, dif, 16);
    if (u->st0[0] != 1u) {
        d3d_stage(u->st0, u->st0b, cur, tex[0], dif, spc, tf, tmp);
        memcpy(cur, tmp, 16);
        if (u->st1[0] != 1u) {
            d3d_stage(u->st1, u->st1b, cur, tex[1], dif, spc, tf, tmp);
            memcpy(cur, tmp, 16);
            if (u->st2[0] > 1u) {
                d3d_stage(u->st2, u->st2b, cur, tex[2], dif, spc, tf, tmp);
                memcpy(cur, tmp, 16);
                if (u->st3[0] > 1u) {
                    d3d_stage(u->st3, u->st3b, cur, tex[3], dif, spc, tf, tmp);
                    memcpy(cur, tmp, 16);
                }
            }
        }
    }
    memcpy(out, cur, 16);
}

static void set_stage(uint32_t *s, uint32_t *b, uint32_t cop, uint32_t c1, uint32_t c2, uint32_t aop,
                      uint32_t aa1, uint32_t aa2, uint32_t c0, uint32_t aa0, uint32_t tcidx) {
    s[0] = cop; s[1] = c1; s[2] = c2; s[3] = aop;
    b[0] = aa1; b[1] = aa2; b[2] = tcidx; b[3] = (c0 & 255) | (aa0 & 255) << 8;
}

static void test_uniform_layout(void) {
    /* WGSL uniform buffer: every member must sit on a 16-byte boundary and fit the USTRIDE stride
       (render_wgpu.c, 768 since W6 - dynamic uniform offsets are 256-aligned) */
    assert(sizeof(Uniforms) % 16 == 0);
    assert(sizeof(Uniforms) == 560);
    assert(sizeof(Uniforms) <= 768);
    assert(offsetof(Uniforms, st2) % 16 == 0);
    assert(offsetof(Uniforms, st2b) == offsetof(Uniforms, st2) + 16);
    assert(offsetof(Uniforms, st3) == offsetof(Uniforms, st2b) + 16);
    assert(offsetof(Uniforms, st3b) == offsetof(Uniforms, st3) + 16);
    assert(offsetof(Uniforms, fog) % 16 == 0);
    assert(offsetof(Uniforms, fog) + 16 == sizeof(Uniforms));
}

/* pack_stages gate and normalization */
static void test_pack_gate(void) {
    DevState st;
    memset(&st, 0, sizeof st);
    Uniforms u;

    /* stage-2 colorop unset (0) or explicit DISABLE (1): stage 2/3 uniforms stay zeroed */
    for (int cop = 0; cop <= 1; cop++) {
        memset(&st, 0, sizeof st);
        memset(&u, 0, sizeof u);
        st.tss[2][1] = (uint32_t)cop;
        st.tss[2][4] = D3DTOP_MODULATE;          /* an alpha op alone cannot enable the stage */
        st.tss[3][1] = D3DTOP_MODULATE;
        pack_stages(&u, &st, 0, 0);
        assert(u.st2[0] == 0 && u.st2[1] == 0 && u.st2[2] == 0 && u.st2[3] == 0);
        assert(u.st3[0] == 0 && u.st3[1] == 0 && u.st3[2] == 0 && u.st3[3] == 0);
    }

    /* maineffects-style stage 2 (modulate2x over diffuse/current), stage 3 unset: packed, with the
       zeroed stage-3 colorop normalized to D3DTOP_DISABLE and the unset alphaop left 0 (the WGSL
       alpha gate reads 0/1 as disabled either way) */
    memset(&st, 0, sizeof st);
    memset(&u, 0, sizeof u);
    st.tss[2][1] = D3DTOP_MODULATE2X;
    st.tss[2][2] = D3DTA_DIFFUSE;
    st.tss[2][3] = D3DTA_CURRENT;
    st.tss[2][11] = 5;                            /* TEXCOORDINDEX (packed informationally) */
    st.tss[2][26] = D3DTA_SPECULAR; st.tss[2][27] = D3DTA_TFACTOR;
    pack_stages(&u, &st, 0, 0);
    assert(u.st2[0] == D3DTOP_MODULATE2X && u.st2[1] == D3DTA_DIFFUSE && u.st2[2] == D3DTA_CURRENT);
    assert(u.st2[3] == 0);
    assert(u.st2b[2] == 5);
    assert(u.st2b[3] == ((D3DTA_SPECULAR & 255) | ((D3DTA_TFACTOR & 255) << 8)));
    assert(u.st3[0] == D3DTOP_DISABLE);           /* unset (0) -> DISABLE */
    assert(u.st3[1] == 0 && u.st3[2] == 0 && u.st3[3] == 0);

    /* an unset colorop (0) is normalized, an explicit one passes through */
    st.tss[3][1] = D3DTOP_LERP;
    pack_stages(&u, &st, 0, 0);
    assert(u.st3[0] == D3DTOP_LERP);

    /* stages 0/1 pack raw exactly as before, and the tc-index field follows the FVF routing rule */
    memset(&st, 0, sizeof st);
    memset(&u, 0, sizeof u);
    st.tss[0][1] = D3DTOP_MODULATE; st.tss[0][2] = D3DTA_TEXTURE; st.tss[0][3] = D3DTA_CURRENT;
    st.tss[0][4] = D3DTOP_SELECTARG1; st.tss[0][5] = D3DTA_TEXTURE; st.tss[0][6] = D3DTA_TFACTOR;
    st.tss[0][11] = 3;                            /* TEXCOORDINDEX when not routed */
    st.tss[1][1] = D3DTOP_DISABLE; st.tss[1][2] = D3DTA_CURRENT; st.tss[1][3] = D3DTA_TFACTOR;
    pack_stages(&u, &st, 0, 0);
    assert(u.st0[0] == D3DTOP_MODULATE && u.st0[1] == D3DTA_TEXTURE && u.st0[2] == D3DTA_CURRENT);
    assert(u.st0[3] == D3DTOP_SELECTARG1 && u.st0b[0] == D3DTA_TEXTURE && u.st0b[1] == D3DTA_TFACTOR);
    assert(u.st0b[2] == 3);                       /* raw TEXCOORDINDEX of stage 0 */
    assert(u.st1[0] == D3DTOP_DISABLE && u.st1[2] == D3DTA_TFACTOR);
    assert(u.st1b[2] == 0);                       /* stage 1 TEXCOORDINDEX unset (0) */
    pack_stages(&u, &st, 1, 0);                   /* vertex shader: slots carry the stage number */
    assert(u.st0b[2] == 0 && u.st1b[2] == 1);
    pack_stages(&u, &st, 0, 1);                   /* FVF routing: same */
    assert(u.st0b[2] == 0 && u.st1b[2] == 1);
}

/* the generalized chain must return the pre-W6 result whenever stages 2-3 are off */
static uint32_t rnd(uint32_t *s) { *s = *s * 1664525u + 1013904223u; return *s >> 8; }
static void test_equivalence(void) {
    static const uint32_t ops[] = { D3DTOP_DISABLE, D3DTOP_SELECTARG1, D3DTOP_SELECTARG2, D3DTOP_MODULATE,
        D3DTOP_MODULATE2X, D3DTOP_ADD, D3DTOP_ADDSIGNED, D3DTOP_ADDSIGNED2X, D3DTOP_BLENDDIFFUSEALPHA,
        D3DTOP_BLENDFACTORALPHA, D3DTOP_LERP };
    uint32_t seed = 0xC0FFEE42;
    for (int iter = 0; iter < 300; iter++) {
        Uniforms u;
        memset(&u, 0, sizeof u);
        /* random two-stage state (op 0 is impossible through D3D, so start the draws at op index 0 =
           DISABLE .. LERP); random args incl. the complement/alpha-replicate flags */
        uint32_t args[6];
        for (int k = 0; k < 6; k++) args[k] = rnd(&seed) % 5 | (rnd(&seed) & 0x30);
        set_stage(u.st0, u.st0b, ops[rnd(&seed) % 11], args[0], args[1], 1 + rnd(&seed) % 11, args[2],
                  args[3], rnd(&seed) % 5, rnd(&seed) % 5, rnd(&seed) & 7);
        set_stage(u.st1, u.st1b, ops[rnd(&seed) % 11], args[4], args[5], 1 + rnd(&seed) % 11, rnd(&seed) % 5,
                  rnd(&seed) % 5, rnd(&seed) % 5, rnd(&seed) % 5, rnd(&seed) & 7);
        float dif[4], spc[4], tf[4], tex[4][4];
        for (int k = 0; k < 4; k++) { dif[k] = (rnd(&seed) & 255) / 255.f; spc[k] = (rnd(&seed) & 255) / 255.f;
                                      tf[k] = (rnd(&seed) & 255) / 255.f; }
        for (int t = 0; t < 4; t++) for (int k = 0; k < 4; k++) tex[t][k] = (rnd(&seed) & 255) / 255.f;

        float old4[4], new4[4];
        /* zeroed stage 2/3 uniforms: the unpacked-draw layout */
        ff_chain_old(&u, dif, spc, tf, tex, old4);
        ff_chain_new(&u, dif, spc, tf, tex, new4);
        assert(memcmp(old4, new4, 16) == 0);

        /* a packed-but-disabled stage 2 and garbage stage-2b/3b: the gate must still stop it */
        u.st2[0] = D3DTOP_DISABLE; u.st2[3] = D3DTOP_MODULATE;
        memset(u.st2b, 0x55, sizeof u.st2b); memset(u.st3, 0x77, sizeof u.st3); memset(u.st3b, 0x99, sizeof u.st3b);
        ff_chain_new(&u, dif, spc, tf, tex, new4);
        assert(memcmp(old4, new4, 16) == 0);
    }
    printf("equivalence: 300 randomized two-stage draws, old chain == new chain (bit-exact)\n");
}

/* location/maineffects.sha LocationRiver/LocationFontain/... (rain and fountain effects):
 *   stage0: ColorOp=SelectArg2, ColorArg1=texture, ColorArg2 unset (raw 0 = D3DTA_DIFFUSE; the D3D8
 *           default would be D3DTA_CURRENT, identical at stage 0 where current == diffuse);
 *           AlphaOp=SelectArg2, AlphaArg2=tfactor
 *   stage1: ColorOp=addsigned (texture, current), AlphaOp=disable
 *   stage2: ColorOp=modulate2x (ColorArg1=diffuse, ColorArg2=current), AlphaOp unset
 *   stage3: unset */
static void test_maineffects(void) {
    DevState st;
    memset(&st, 0, sizeof st);
    st.tss[0][1] = D3DTOP_SELECTARG2; st.tss[0][2] = D3DTA_TEXTURE; st.tss[0][3] = D3DTA_DIFFUSE;
    st.tss[0][4] = D3DTOP_SELECTARG2; st.tss[0][6] = D3DTA_TFACTOR;
    st.tss[1][1] = D3DTOP_ADDSIGNED; st.tss[1][2] = D3DTA_TEXTURE; st.tss[1][3] = D3DTA_CURRENT;
    st.tss[1][4] = D3DTOP_DISABLE;
    st.tss[2][1] = D3DTOP_MODULATE2X; st.tss[2][2] = D3DTA_DIFFUSE; st.tss[2][3] = D3DTA_CURRENT;

    Uniforms u;
    memset(&u, 0, sizeof u);
    pack_stages(&u, &st, 0, 0);
    assert(u.st2[0] == D3DTOP_MODULATE2X && u.st2[1] == D3DTA_DIFFUSE && u.st2[2] == D3DTA_CURRENT);
    assert(u.st3[0] == D3DTOP_DISABLE);

    float dif[4], spc[4] = { 0, 0, 0, 1 }, tf[4], tex[4][4];
    d3dcolor(0xFF336699, dif);      /* r .2 g .4 b .6 a 1.0 */
    d3dcolor(0xFF4D80CC, tex[0]);   /* r .302 g .502 b .8 a 1.0 */
    d3dcolor(0xFFFFFFFF, tf);       /* the technique's TextureFactor 0x90ffffff-style alpha */
    memcpy(tex[1], tex[0], 16); memcpy(tex[2], tex[0], 16); memcpy(tex[3], tex[0], 16);

    float got[4];
    ff_chain_new(&u, dif, spc, tf, tex, got);
    /* stage0 = dif; stage1 = tex + dif - .5 (addsigned); stage2 = dif.rgb * prev.rgb * 2 (modulate2x,
       alpha preserved: alphaop[0] selected tfactor.a and stages 1-2 keep it) */
    float want[4] = { sat1(2.f * dif[0] * (dif[0] + tex[0][0] - .5f)),
                      sat1(2.f * dif[1] * (dif[1] + tex[0][1] - .5f)),
                      sat1(2.f * dif[2] * (dif[2] + tex[0][2] - .5f)), tf[3] };
    assert(near_v(got, want));
    print_v("maineffects rgb", got);
    /* the modulate2x overshoot saturates the blue channel: 2 * .6 * .9 = 1.08 -> 1.0 */
    assert(got[2] == 1.f);
}

/* artifact.sha block Artifact:
 *   stage0: ColorOp=selectarg1(texture), AlphaOp=selectarg1(texture)
 *   stage1: ColorOp=blenddiffusealpha (texture, current); AlphaOp=lerp(diffuse, texture, current)
 *   stage2: ColorOp=modulate (ColorArg1=current, ColorArg2 unset -> packed raw 0 = D3DTA_DIFFUSE;
 *           the D3D8 device default would be D3DTA_CURRENT - the port's raw-tss policy, unchanged
 *           from stages 0/1, is kept here and noted in the audit doc), AlphaOp=disable
 *   stage3: ColorOp=disable */
static void test_artifact(void) {
    DevState st;
    memset(&st, 0, sizeof st);
    st.tss[0][1] = D3DTOP_SELECTARG1; st.tss[0][2] = D3DTA_TEXTURE; st.tss[0][3] = D3DTA_DIFFUSE;
    st.tss[0][4] = D3DTOP_SELECTARG1; st.tss[0][5] = D3DTA_TEXTURE;
    st.tss[1][1] = D3DTOP_BLENDDIFFUSEALPHA; st.tss[1][2] = D3DTA_TEXTURE; st.tss[1][3] = D3DTA_CURRENT;
    st.tss[1][4] = D3DTOP_LERP; st.tss[1][5] = D3DTA_TEXTURE; st.tss[1][6] = D3DTA_CURRENT;
    st.tss[1][27] = D3DTA_DIFFUSE;                  /* AlphaArg0[1] = diffuse */
    st.tss[2][1] = D3DTOP_MODULATE; st.tss[2][2] = D3DTA_CURRENT; st.tss[2][4] = D3DTOP_DISABLE;
    st.tss[3][1] = D3DTOP_DISABLE;                  /* ColorOp[3] = disable (explicit) */

    Uniforms u;
    memset(&u, 0, sizeof u);
    pack_stages(&u, &st, 0, 0);
    assert(u.st2[0] == D3DTOP_MODULATE && u.st2[1] == D3DTA_CURRENT && u.st2[2] == D3DTA_DIFFUSE);
    assert(u.st2[3] == D3DTOP_DISABLE);
    assert(u.st3[0] == D3DTOP_DISABLE);
    assert((u.st1b[3] >> 8) == D3DTA_DIFFUSE);      /* lerp's alphaarg0 */

    float dif[4], spc[4] = { 0, 0, 0, 1 }, tf[4] = { .1f, .2f, .3f, .4f }, tex[4][4];
    d3dcolor(0x99407FFF, dif);      /* r .251 g .498 b 1.0 a .6 */
    d3dcolor(0xCC80FF00, tex[0]);   /* r .502 g 1.0 b 0.0 a .8 */
    memcpy(tex[1], tex[0], 16); memcpy(tex[2], tex[0], 16); memcpy(tex[3], tex[0], 16);

    float got[4];
    ff_chain_new(&u, dif, spc, tf, tex, got);
    /* stage0 = tex; stage1 rgb = mix(current, texture, dif.a) = tex (current == texture after
       stage 0), alpha = lerp(dif, tex, current) = dif.a*tex.a + (1-dif.a)*tex.a = tex.a;
       stage2 rgb = current * diffuse (modulate), alpha kept */
    float want[4] = { sat1(tex[0][0] * dif[0]), sat1(tex[0][1] * dif[1]), sat1(tex[0][2] * dif[2]), tex[0][3] };
    assert(near_v(got, want));
    print_v("artifact rgb", got);
}

/* stage 2 SELECTARG1 passes arg1 through; an alpha op on stage 2 updates alpha while the color pipe
 * result is kept */
static void test_stage2_selectarg_and_alpha(void) {
    Uniforms u;
    memset(&u, 0, sizeof u);
    set_stage(u.st0, u.st0b, D3DTOP_SELECTARG1, D3DTA_TEXTURE, D3DTA_DIFFUSE, D3DTOP_DISABLE, 0, 0, 0, 0, 0);
    set_stage(u.st2, u.st2b, D3DTOP_SELECTARG1, D3DTA_TEXTURE, D3DTA_CURRENT, D3DTOP_DISABLE, 0, 0, 0, 0, 0);
    float dif[4] = { .2f, .3f, .4f, .5f }, spc[4] = { 0, 0, 0, 1 }, tf[4] = { 1, 1, 1, 1 }, tex[4][4];
    d3dcolor(0xFF112233, tex[0]); memcpy(tex[1], tex[0], 16); memcpy(tex[2], tex[0], 16); memcpy(tex[3], tex[0], 16);
    float got[4];
    ff_chain_new(&u, dif, spc, tf, tex, got);
    float want[4] = { tex[0][0], tex[0][1], tex[0][2], dif[3] };   /* color from stage 2, alpha stage 0 */
    assert(near_v(got, want));

    /* alpha op on stage 2: ColorOp=SELECTARG1 (rgb passthrough), AlphaOp=modulate(tex, tfactor) */
    memset(&u, 0, sizeof u);
    set_stage(u.st0, u.st0b, D3DTOP_SELECTARG1, D3DTA_TEXTURE, D3DTA_DIFFUSE, D3DTOP_SELECTARG1,
              D3DTA_TEXTURE, 0, 0, 0, 0);
    set_stage(u.st2, u.st2b, D3DTOP_SELECTARG1, D3DTA_TEXTURE, D3DTA_CURRENT, D3DTOP_MODULATE,
              D3DTA_TEXTURE, D3DTA_TFACTOR, 0, 0, 0);
    ff_chain_new(&u, dif, spc, tf, tex, got);
    want[0] = tex[0][0]; want[1] = tex[0][1]; want[2] = tex[0][2];
    want[3] = sat1(tex[0][3] * tf[3]);
    assert(near_v(got, want));
    print_v("stage2 alpha", got);
}

/* a D3DTOP_DISABLE stage ends the rest of the pipeline: stage 2 must stay inert behind it */
static void test_disable_termination(void) {
    Uniforms u;
    memset(&u, 0, sizeof u);
    set_stage(u.st0, u.st0b, D3DTOP_SELECTARG1, D3DTA_TEXTURE, D3DTA_DIFFUSE, D3DTOP_DISABLE, 0, 0, 0, 0, 0);
    set_stage(u.st1, u.st1b, D3DTOP_DISABLE, D3DTA_TEXTURE, D3DTA_CURRENT, D3DTOP_DISABLE, 0, 0, 0, 0, 0);
    set_stage(u.st2, u.st2b, D3DTOP_MODULATE2X, D3DTA_DIFFUSE, D3DTA_CURRENT, D3DTOP_DISABLE, 0, 0, 0, 0, 0);
    float dif[4] = { .2f, .3f, .4f, .5f }, spc[4] = { 0, 0, 0, 1 }, tf[4] = { 1, 1, 1, 1 }, tex[4][4];
    d3dcolor(0xFF112233, tex[0]); memcpy(tex[1], tex[0], 16); memcpy(tex[2], tex[0], 16); memcpy(tex[3], tex[0], 16);
    float old4[4], new4[4];
    ff_chain_old(&u, dif, spc, tf, tex, old4);
    ff_chain_new(&u, dif, spc, tf, tex, new4);
    assert(memcmp(old4, new4, 16) == 0);
    float want[4] = { tex[0][0], tex[0][1], tex[0][2], dif[3] };   /* stage 0 only */
    assert(near_v(new4, want));
}

int main(void) {
    test_uniform_layout();
    printf("layout: Uniforms 560 bytes, st2/st2b/st3/st3b 16-aligned, fog last\n");
    test_pack_gate();
    printf("packing: stage-2 gate, DISABLE normalization, stages 0/1 and tc-index invariants\n");
    test_equivalence();
    test_maineffects();
    test_artifact();
    test_stage2_selectarg_and_alpha();
    test_disable_termination();
    printf("texstage: all tests passed\n");
    return 0;
}
