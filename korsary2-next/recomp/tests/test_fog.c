/* Fog (audit W5): synthetic checks of the recorder's CPU fog pipeline.
 *
 * Covers the D3D8 fog formulas (linear/exp/exp2, state indices, depth rules), the specular-alpha
 * transport of the blend factor, the oFog capture in the vertex-shader interpreter, and the fog
 * injection into real pshader.c WGSL output. CPU-side only: no GPU, no browser.
 * Run: sh recomp/tests/run_fog.sh   (native ASan/UBSan; "wasm" runs under Node). */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../host/render_rec.c"   /* fog helpers, Uniforms, CVert */
#include "../host/vshader.c"      /* vs_run / vs_writes_ofog */
#include "../host/pshader.c"      /* ps_to_wgsl: real generated WGSL for the injection test */

static int near_f(float a, float b) { return fabsf(a - b) < 1e-4f; }

static void test_uniform_layout(void) {
    /* WGSL uniform buffer: every member must sit on a 16-byte boundary and fit the USTRIDE stride
       (render_wgpu.c; 768 since audit W6 added stages 2-3 - dynamic uniform offsets are 256-aligned) */
    assert(sizeof(Uniforms) % 16 == 0);
    assert(sizeof(Uniforms) <= 768);
    assert(offsetof(Uniforms, fog) % 16 == 0);
    assert(offsetof(Uniforms, fog) + 16 == sizeof(Uniforms));
}

static void test_linear(void) {
    /* start=100, end=1000: 1.0 at start (no fog), 0.5 midway, 0.0 at end (full fog) */
    assert(near_f(fog_factor(FOG_LINEAR, 100.f, 100.f, 1000.f, 0.f), 1.f));
    assert(near_f(fog_factor(FOG_LINEAR, 0.f, 100.f, 1000.f, 0.f), 1.f));      /* before start: clamped to 1 */
    assert(near_f(fog_factor(FOG_LINEAR, 550.f, 100.f, 1000.f, 0.f), 0.5f));
    assert(fog_factor(FOG_LINEAR, 1000.f, 100.f, 1000.f, 0.f) == 0.f);
    assert(near_f(fog_factor(FOG_LINEAR, 2000.f, 100.f, 1000.f, 0.f), 0.f));   /* beyond end: clamped to 0 */
    assert(near_f(fog_factor(FOG_LINEAR, 550.f, 1000.f, 100.f, 0.f), 0.5f));   /* reversed start/end still blends */
    /* degenerate range (end <= start): no fog before end, full fog at/after it */
    assert(fog_factor(FOG_LINEAR, 5.f, 10.f, 10.f, 0.f) == 1.f);
    assert(fog_factor(FOG_LINEAR, 15.f, 10.f, 10.f, 0.f) == 0.f);
    /* negative depth (behind the eye) clamps to d=0: no fog */
    assert(near_f(fog_factor(FOG_LINEAR, -50.f, 100.f, 1000.f, 0.f), 1.f));
}

static void test_exponential(void) {
    assert(fog_factor(FOG_EXP, 0.f, 0.f, 0.f, 0.001f) == 1.f);                          /* density*d=0 */
    assert(near_f(fog_factor(FOG_EXP, 1000.f, 0.f, 0.f, 0.001f), expf(-1.f)));          /* 1/e ~ 0.3679 */
    assert(near_f(fog_factor(FOG_EXP, 3000.f, 0.f, 0.f, 0.001f), expf(-3.f)));
    assert(fog_factor(FOG_EXP, 5000.f, 0.f, 0.f, 0.f) == 1.f);                          /* density 0 = no fog */
    assert(near_f(fog_factor(FOG_EXP2, 1000.f, 0.f, 0.f, 0.001f), expf(-1.f)));         /* (d*density)^2 = 1 */
    assert(near_f(fog_factor(FOG_EXP2, 2000.f, 0.f, 0.f, 0.001f), expf(-4.f)));         /* (2)^2 = 4 */
    assert(fog_factor(FOG_EXP2, 1000.f, 0.f, 0.f, 0.f) == 1.f);
    assert(fog_factor(FOG_NONE, 10000.f, 0.f, 0.f, 1.f) == 1.f);                        /* NONE: always no fog */
    assert(fog_factor(99u, 10000.f, 0.f, 0.f, 1.f) == 1.f);                             /* unknown mode: no fog */
    /* garbage (negative/NaN) density must not fog anything */
    float nan = NAN;
    assert(fog_factor(FOG_EXP, 100.f, 0.f, 0.f, -0.5f) == 1.f);
    assert(fog_factor(FOG_EXP2, 100.f, 0.f, 0.f, nan) == 1.f);
}

static void test_draw_fog_mode(void) {
    DevState st;
    memset(&st, 0, sizeof st);
    st.rs[RS_FOGVERTEXMODE] = FOG_LINEAR;
    assert(draw_fog_mode(&st) == FOG_NONE);                        /* FOGENABLE off wins */
    st.rs[RS_FOGENABLE] = 1;
    assert(draw_fog_mode(&st) == FOG_LINEAR);                      /* vertex mode when no table mode */
    st.rs[RS_FOGTABLEMODE] = FOG_EXP;
    assert(draw_fog_mode(&st) == FOG_EXP);                         /* table mode takes precedence */
    st.rs[RS_FOGTABLEMODE] = FOG_LINEAR;
    assert(draw_fog_mode(&st) == FOG_LINEAR);
    st.rs[RS_FOGVERTEXMODE] = FOG_NONE;
    st.rs[RS_FOGTABLEMODE] = FOG_NONE;
    assert(draw_fog_mode(&st) == FOG_NONE);                        /* both NONE: no fog even when enabled */
}

static void test_state_float(void) {
    DevState st;
    memset(&st, 0, sizeof st);
    float v = 123.5f;
    memcpy(&st.rs[RS_FOGSTART], &v, 4);
    assert(fog_state_float(&st, RS_FOGSTART) == 123.5f);           /* FOGSTART is float bits in a DWORD */
}

static void test_depth(void) {
    /* view = translate by (0, 0, -10): camera at origin looking down -z... a D3D view matrix moves
       the world by (0,0,-10), so a vertex at z=5 sits at depth |5-10| = 5 */
    float wv[16] = { 1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, -10.f, 1 };
    assert(near_f(fog_depth(wv, 0.f, 0.f, 5.f, 0), 5.f));          /* |camera-space z| (non-range) */
    assert(near_f(fog_depth(wv, 0.f, 0.f, 15.f, 0), 5.f));         /* abs() behind the eye too */
    assert(near_f(fog_depth(wv, 3.f, 4.f, 10.f, 1), 5.f));         /* RANGEFOG: full eye distance (3-4-5) */
    assert(near_f(fog_depth(wv, 3.f, 4.f, 10.f, 0), 0.f));         /* non-range: |z| only */
}

static void test_specular_transport(void) {
    assert(fog_alpha_byte(0.f) == 0u);                             /* full fog */
    assert(fog_alpha_byte(1.f) == 0xFF000000u);                    /* no fog */
    assert(fog_alpha_byte(0.5f) == 128u << 24);                    /* 0.5*255+0.5 rounds to 128 */
    assert(fog_alpha_byte(2.f) == 0xFF000000u);                    /* clamped */
    assert(fog_alpha_byte(-1.f) == 0u);
    float nan = NAN;
    assert(fog_alpha_byte(nan) == 0u);                             /* NaN: clamped, never garbage */
    /* the draw loop keeps the specular RGB bits and only replaces alpha */
    CVert v;
    memset(&v, 0, sizeof v);
    v.specular = 0x00102030u;
    float f = fog_factor(FOG_LINEAR, 550.f, 100.f, 1000.f, 0.f);
    v.specular = (v.specular & 0x00FFFFFFu) | fog_alpha_byte(f);
    assert((v.specular & 0x00FFFFFFu) == 0x00102030u);
    assert((v.specular >> 24) == 128u);
}

static void test_uniform_fog_fill(void) {
    /* replicates the recorder's uniform fill for fog color 0x00FF8040 (alpha byte ignored) */
    float fog[4] = { 0, 0, 0, 0 };
    unpack_color(0x00FF8040u, fog);
    fog[3] = 1.f;
    assert(near_f(fog[0], 1.f) && near_f(fog[1], 128.f / 255.f) && near_f(fog[2], 64.f / 255.f));
    assert(fog[3] == 1.f);
}

/* ------------------------------------------------------------------ vertex shader oFog */

static void test_vs_ofog(void) {
    /* vs.1.1: def c9, 0.25 ... mov oFog.x, c9.x  (dest: RASTOUT #1, mask x) */
    static const uint32_t code[] = {
        0xFFFE0101u,                                                        /* vs.1.1 */
        81u, 2u << 28 | 9u, 0x3E800000u, 0, 0, 0,                           /* def c9, 0.25, 0, 0, 0 */
        1u, 4u << 28 | 1u << 16 | 1u, 2u << 28 | 0xE4u << 16 | 9u,          /* mov oFog.x, c9.x */
        0x0000FFFFu,
    };
    static const uint32_t decl[] = { 0xFFFFFFFFu };
    float ident[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    VsStreams streams;
    memset(&streams, 0, sizeof streams);
    streams.ff_mvp = ident;

    Shader sh = { 0 };
    sh.decl = (uint32_t *)decl;
    sh.decl_len = 1;
    sh.code = (uint32_t *)code;
    sh.code_len = sizeof code / sizeof *code;
    assert(vs_writes_ofog(&sh) == 1);

    float consts[96][4];
    memset(consts, 0, sizeof consts);
    consts[9][0] = 0.25f;
    VsOut out;
    vs_run(&sh, (const float (*)[4])consts, &streams, 0, &out);
    assert(out.fog[0] == 0.25f);   /* the recorder would pack 0.25*255+0.5 = 64 into specular alpha */
    assert(out.fog[1] == 0.f && out.fog[2] == 0.f && out.fog[3] == 0.f);

    /* the same shader without the oFog write: vs_writes_ofog = 0, oFog defaults to 1 (no fog) */
    static const uint32_t code_nofog[] = {
        0xFFFE0101u, 1u, 0u << 28 | 0xFu << 16 | 0u, 2u << 28 | 0xE4u << 16 | 0u, 0x0000FFFFu,  /* mov r0, c0 */
    };
    Shader sh2 = { 0 };
    sh2.decl = (uint32_t *)decl;
    sh2.decl_len = 1;
    sh2.code = (uint32_t *)code_nofog;
    sh2.code_len = sizeof code_nofog / sizeof *code_nofog;
    assert(vs_writes_ofog(&sh2) == 0);
    vs_run(&sh2, (const float (*)[4])consts, &streams, 0, &out);
    assert(out.fog[0] == 1.f);

    /* declaration-only (fixed-function emulation) shader: no oFog ever */
    Shader sh3 = { 0 };
    sh3.decl = (uint32_t *)decl;
    sh3.decl_len = 1;
    assert(vs_writes_ofog(&sh3) == 0);
    vs_run(&sh3, (const float (*)[4])consts, &streams, 0, &out);
    assert(out.fog[0] == 1.f);
}

/* ------------------------------------------------------------------ pshader.c injection */

#define OP(o, len) ((len) << 16 | (o))
#define DEST(reg, mask) ((mask) << 16 | (reg))                       /* r#/t# dest, no sat/shift */
#define SRC(type, num, mod) ((type) << 28 | (mod) << 24 | 0xE4u << 16 | (num))

/* hand-encoded GF3 sea reflection pixel shader (same tokens as test_pshader_sea.c) */
static const uint32_t sea_ps[] = {
    0xFFFF0101u,
    OP(66, 2), DEST(3 << 28 | 0, 0xF),                                    /* tex t0 */
    OP(73, 3), DEST(3 << 28 | 1, 0xF), SRC(3, 0, 4),                      /* texm3x3pad t1, t0_bx2 */
    OP(73, 3), DEST(3 << 28 | 2, 0xF), SRC(3, 0, 4),                      /* texm3x3pad t2, t0_bx2 */
    OP(77, 3), DEST(3 << 28 | 3, 0xF), SRC(3, 0, 4),                      /* texm3x3vspec t3, t0_bx2 */
    OP(1, 3), DEST(0, 0xF), SRC(3, 3, 0),                                 /* mov r0, t3 */
    0x0000FFFFu,
};

static int count_occurrences(const char *hay, const char *needle) {
    int n = 0;
    for (const char *p = hay; (p = strstr(p, needle)) != NULL; p += 1) n++;
    return n;
}

static void test_ps_inject_fog(void) {
    char why[96] = "";
    char *fs = ps_to_wgsl(sea_ps, sizeof sea_ps / sizeof *sea_ps, why, sizeof why);
    assert(fs && !why[0]);
    /* the frozen generator's fragment tail the injector keys on appears exactly once */
    assert(count_occurrences(fs, RENDER_PS_FOG_TAIL) == 1);
    char *fogged = ps_inject_fog(fs);
    assert(fogged != fs);
    assert(count_occurrences(fogged, RENDER_PS_FOG_LINE) == 1);
    assert(count_occurrences(fogged, RENDER_PS_FOG_TAIL) == 1);
    assert(count_occurrences(fogged, "@fragment fn fs") == 1);
    /* fog line sits before the alpha-test tail and reads the specular-alpha factor */
    const char *line = strstr(fogged, RENDER_PS_FOG_LINE);
    const char *tail = strstr(fogged, RENDER_PS_FOG_TAIL);
    assert(line < tail);
    assert(strstr(fogged, "i.specular.a") && strstr(fogged, "u.fog.w"));
    free(fogged);

    /* a fragment source without the generator tail is returned unchanged (fail-safe) */
    char plain[] = "@fragment fn fs(i: VO) -> @location(0) vec4<f32> { return i.diffuse; }\n";
    char *same = ps_inject_fog(plain);
    assert(same == plain && !strstr(same, RENDER_PS_FOG_LINE));
}

int main(void) {
    test_uniform_layout();
    test_linear();
    test_exponential();
    test_draw_fog_mode();
    test_state_float();
    test_depth();
    test_specular_transport();
    test_uniform_fog_fill();
    test_vs_ofog();
    test_ps_inject_fog();
    puts("fog: formulas, states, specular-alpha transport, oFog capture and ps injection passed");
    return 0;
}
