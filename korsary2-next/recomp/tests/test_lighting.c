/* Lighting (audit W2): synthetic checks of the recorder's CPU per-vertex D3D8 lighting.
 *
 * Covers the state indices, the D3DLIGHT8/D3DMATERIAL8 layout, directional/point/spot math
 * (attenuation, cone halving, falloff), COLORVERTEX + material-source selection, NORMALIZENORMALS,
 * LOCALVIEWER specular, the lighting/fog transport split (diffuse RGB + unlit alpha, specular RGB +
 * fog alpha), LIGHTING=0 passthrough and the eight-light array. CPU-side only: no GPU, no browser.
 * Run: sh recomp/tests/run_lighting.sh   (native ASan/UBSan).
 * D3DCOLOR note: 0xAARRGGBB - unpack_color reads r from bits 16-23, g from 8-15, b from 0-7. */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../host/render_rec.c"

static int near_f(float a, float b) { return fabsf(a - b) < 1e-4f; }
/* D3DCOLOR channels are quantized to 8 bits: 0.7071 packs to 180/255 = 0.7059 */
static int near_c(uint32_t got, float r, float g, float b) {
    return fabsf(((got >> 16) & 255) / 255.f - r) < 2 / 255.f &&
           fabsf(((got >> 8) & 255) / 255.f - g) < 2 / 255.f &&
           fabsf((got & 255) / 255.f - b) < 2 / 255.f;
}
static int near_a(uint32_t got, float a) { return fabsf((got >> 24) / 255.f - a) < 2 / 255.f; }

/* raw D3DLIGHT8 (104 bytes) as SetLight delivers it */
typedef struct {
    uint32_t type;
    float diff[4], spec[4], amb[4];
    float pos[3], dir[3];
    float range, falloff, att0, att1, att2, theta, phi;
} TestLight;
_Static_assert(sizeof(TestLight) == 104, "raw D3DLIGHT8 layout");

static TestLight light(uint32_t type, float dr, float dg, float db, float ar, float ag, float ab) {
    TestLight l;
    memset(&l, 0, sizeof l);
    l.type = type;
    l.diff[0] = dr; l.diff[1] = dg; l.diff[2] = db; l.diff[3] = 1.f;
    l.amb[0] = ar; l.amb[1] = ag; l.amb[2] = ab; l.amb[3] = 1.f;
    l.range = 0.f; l.falloff = 1.f; l.att0 = 1.f;
    return l;
}

/* documented D3D8 defaults (the same ones d3d8.c CreateDevice installs) */
static void base_state(DevState *st) {
    memset(st, 0, sizeof *st);
    for (int i = 0; i < MAX_TS; i++)
        st->transform[i][0] = st->transform[i][5] = st->transform[i][10] = st->transform[i][15] = 1.f;
    st->rs[RS_LIGHTING] = 1;
    st->rs[RS_COLORVERTEX] = 1;
    st->rs[RS_LOCALVIEWER] = 1;
    st->rs[RS_DIFFUSEMS] = MCS_COLOR1;
    st->rs[RS_SPECULARMS] = MCS_COLOR2;
    st->rs[RS_AMBIENTMS] = MCS_MATERIAL;
    st->rs[RS_EMISSIVEMS] = MCS_MATERIAL;
}

static void enable_light(DevState *st, uint32_t i, const TestLight *l) {
    memcpy(st->light[i], l, sizeof *l);
    st->light_enabled[i] = 1;
}

/* raw FVF vertex: XYZ, NORMAL, DIFFUSE, SPECULAR (stride 32) */
static const uint32_t FVF_NCD = 0x2u | 0x10u | 0x40u | 0x80u;
typedef struct { float pos[3], n[3]; uint32_t diff, spec; } RawVtx;

static void lit_check(DevState *st, const RawVtx *in, RawVtx *out) {
    FvfLayout L;
    fvf_layout(FVF_NCD, &L);
    float wv[16];
    memcpy(wv, st->transform[256], sizeof wv);   /* identity view: WORLD*VIEW = WORLD */
    LightEnv e;
    assert(light_setup(st, &L, wv, &e) == 1);
    CVert v;
    memset(&v, 0, sizeof v);
    v.x = in->pos[0]; v.y = in->pos[1]; v.z = in->pos[2]; v.w = 1.f;
    v.diffuse = in->diff; v.specular = in->spec;
    light_vertex(&e, wv, (const uint8_t *)in, &L, &v);
    out->diff = v.diffuse;
    out->spec = v.specular;
}

static void mat_set(DevState *st, float dr, float dg, float db, float ar, float ag, float ab, float sr, float sg,
                    float sb, float er, float eg, float eb, float power) {
    float m[17] = { dr, dg, db, 1, ar, ag, ab, 1, sr, sg, sb, 1, er, eg, eb, 1, power };
    memcpy(st->material, m, sizeof m);
}

static void w32v(uint8_t *p, uint32_t v) { memcpy(p, &v, 4); }

/* ------------------------------------------------------------------ states and layout */

static void test_state_indices(void) {
    /* d3d8types.h numbering */
    assert(RS_LIGHTING == 137 && RS_AMBIENT == 139 && RS_COLORVERTEX == 141 && RS_LOCALVIEWER == 142 &&
           RS_NORMALIZENORMALS == 143 && RS_DIFFUSEMS == 145 && RS_SPECULARMS == 146 &&
           RS_AMBIENTMS == 147 && RS_EMISSIVEMS == 148);
    assert(MCS_MATERIAL == 0 && MCS_COLOR1 == 1 && MCS_COLOR2 == 2);
    assert(LIGHT_POINT == 1 && LIGHT_SPOT == 2 && LIGHT_DIRECTIONAL == 3);
    /* DevState.material: Diffuse, Ambient, Specular, Emissive, Power (D3DMATERIAL8) */
    DevState st;
    base_state(&st);
    mat_set(&st, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.f, 0.f, 0.f, 2.f);
    assert(near_f(st.material[16], 2.f) && near_f(st.material[3], 1.f) && near_f(st.material[7], 1.f));
    FvfLayout L;
    fvf_layout(FVF_NCD, &L);
    float wv[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    LightEnv e;
    light_setup(&st, &L, wv, &e);
    assert(near_f(e.power, 2.f));   /* Power is float 16 of D3DMATERIAL8 */
}

/* ------------------------------------------------------------------ directional */

static void test_directional(void) {
    /* sun straight up: Direction (0,-1,0) -> Ldir = (0,1,0); white light, no ambient/specular */
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_DIRECTIONAL, 1, 1, 1, 0, 0, 0);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st, 0, &l);

    RawVtx in = { { 0, 0, 0 }, { 0, 1, 0 }, 0x40FFFFFFu, 0x40000000u };
    RawVtx out;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1, 1, 1));          /* NdL = 1: full white (diffuse source = COLOR1) */
    assert(near_a(out.diff, 0x40 / 255.f));     /* vertex alpha passes unlit */
    assert(out.spec == in.spec);                /* SPECULARENABLE off: specular untouched */

    memcpy(in.n, (float[]){ 0, -1, 0 }, 12);    /* facing away */
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0, 0, 0));          /* ambient only (zero here), never the raw color */

    memcpy(in.n, (float[]){ 1 / sqrtf(2.f), 1 / sqrtf(2.f), 0 }, 12);   /* 45 degrees: NdL = 1/sqrt(2) */
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1 / sqrtf(2.f), 1 / sqrtf(2.f), 1 / sqrtf(2.f)));

    /* DIFFUSEMATERIALSOURCE = material */
    st.rs[RS_DIFFUSEMS] = MCS_MATERIAL;
    mat_set(&st, 0.5f, 0.25f, 0.f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    memcpy(in.n, (float[]){ 0, 1, 0 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.5f, 0.25f, 0.f));   /* Cd * Ld * 1 */

    /* COLORVERTEX=0 ignores the source states: material wins despite DIFFUSEMS=COLOR1 */
    st.rs[RS_DIFFUSEMS] = MCS_COLOR1;
    st.rs[RS_COLORVERTEX] = 0;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.5f, 0.25f, 0.f));
}

/* ------------------------------------------------------------------ point attenuation */

static void test_point(void) {
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_POINT, 1, 1, 1, 0, 0, 0);
    memcpy(l.pos, (float[]){ 0, 0, 10 }, 12);
    l.att0 = 0; l.att1 = 1; l.att2 = 0;
    l.range = 100;
    enable_light(&st, 0, &l);

    RawVtx in = { { 0, 0, 0 }, { 0, 0, 1 }, 0xFFFFFFFFu, 0 };
    RawVtx out;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.1f, 0.1f, 0.1f));   /* d=10: 1/(1*d) = 0.1, NdL = 1 */

    memcpy(in.pos, (float[]){ 0, 0, -10 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.05f, 0.05f, 0.05f));   /* d=20 */

    memcpy(in.pos, (float[]){ 0, 0, -95 }, 12);      /* d=105 > Range */
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0, 0, 0));               /* beyond Range: no contribution at all */

    /* quadratic attenuation: 1/(att2*d^2) = 1/(0.25*100) = 0.04 */
    l.att1 = 0; l.att2 = 0.25f;
    enable_light(&st, 0, &l);
    memcpy(in.pos, (float[]){ 0, 0, 0 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.04f, 0.04f, 0.04f));

    /* Range = 0: no distance limit */
    l.range = 0;
    l.att1 = 1; l.att2 = 0;
    enable_light(&st, 0, &l);
    memcpy(in.pos, (float[]){ 0, 0, -10000 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1 / 10010.f, 1 / 10010.f, 1 / 10010.f));

    /* all attenuation factors zero: denominator 0 -> treated as no attenuation */
    l.att1 = 0;
    enable_light(&st, 0, &l);
    memcpy(in.pos, (float[]){ 0, 0, 0 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1, 1, 1));
}

/* ------------------------------------------------------------------ spot cone */

static void test_spot(void) {
    const float PI = 3.14159265f;
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_SPOT, 1, 1, 1, 0, 0, 0);
    memcpy(l.pos, (float[]){ 0, 0, 10 }, 12);
    memcpy(l.dir, (float[]){ 0, 0, -1 }, 12);   /* shining toward -z */
    l.theta = PI / 4;                            /* inner cone: half angle 22.5 deg */
    l.phi = PI / 2;                              /* outer cone: half angle 45 deg */
    l.falloff = 1;
    l.att0 = 1; l.att1 = 0; l.att2 = 0;
    enable_light(&st, 0, &l);

    /* vertices on a 10-unit arc around the axis; normals face the light exactly (NdL = 1), so the
       diffuse output is the spotlight factor itself */
    float a10 = 10 * PI / 180, a35 = 35 * PI / 180, a60 = 60 * PI / 180;
    float p10[3] = { 10 * sinf(a10), 0, 10 - 10 * cosf(a10) };
    float p35[3] = { 10 * sinf(a35), 0, 10 - 10 * cosf(a35) };
    float p60[3] = { 10 * sinf(a60), 0, 10 - 10 * cosf(a60) };
    float n10[3] = { -sinf(a10), 0, cosf(a10) }, n35[3] = { -sinf(a35), 0, cosf(a35) },
          n60[3] = { -sinf(a60), 0, cosf(a60) };
    RawVtx in, out;
    memset(&in, 0, sizeof in);
    in.diff = 0xFFFFFFFFu;

    memcpy(in.pos, p10, 12); memcpy(in.n, n10, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1, 1, 1));   /* inside Theta: Spot = 1 */

    memcpy(in.pos, p35, 12); memcpy(in.n, n35, 12);
    lit_check(&st, &in, &out);
    float rho35 = cosf(a35), t35 = (cosf(l.phi / 2) - rho35) / (cosf(l.phi / 2) - cosf(l.theta / 2));
    assert(t35 > 0 && t35 < 1);
    /* between the cones: ((cosPhi - cosRho)/(cosPhi - cosTheta))^falloff */
    assert(near_c(out.diff, t35, t35, t35));

    memcpy(in.pos, p60, 12); memcpy(in.n, n60, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0, 0, 0));   /* outside Phi: nothing, ambient included */

    /* falloff 0: constant between the cones */
    l.falloff = 0;
    enable_light(&st, 0, &l);
    memcpy(in.pos, p35, 12); memcpy(in.n, n35, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1, 1, 1));

    /* per-light ambient is spotlighted too: inside the cone it survives, outside it dies */
    memcpy(l.amb, (float[]){ 0.2f, 0.2f, 0.2f }, 12);
    enable_light(&st, 0, &l);
    mat_set(&st, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0);
    st.rs[RS_DIFFUSEMS] = MCS_MATERIAL;
    st.rs[RS_AMBIENTMS] = MCS_MATERIAL;
    memcpy(in.pos, (float[]){ 0, 0, 0 }, 12);
    memcpy(in.n, (float[]){ 0, 0, 1 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.2f, 0.2f, 0.2f));   /* on the axis: Ca*La, diffuse material black */
    memcpy(in.pos, p60, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0, 0, 0));
}

/* ------------------------------------------------------------------ COLORVERTEX sources */

static void test_color_sources(void) {
    DevState st;
    base_state(&st);
    st.rs[RS_AMBIENT] = 0xFFC08040u;   /* global ambient Ga = (0.75, 0.5, 0.25) */
    mat_set(&st, 0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, 0.3f, 0.3f, 0.3f, 0.4f, 0.4f, 0.4f, 0);

    RawVtx in = { { 0, 0, 0 }, { 0, 1, 0 }, 0xC0FF0000u, 0x80201008u };
    RawVtx out;
    /* no lights: emissive + ambient-only output; AMBIENTMATERIALSOURCE default = material */
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.4f + 0.75f * 0.2f, 0.4f + 0.5f * 0.2f, 0.4f + 0.25f * 0.2f));   /* Ce + Ga*Ca */
    assert(near_a(out.diff, 0xC0 / 255.f));   /* unlit alpha of the diffuse source (COLOR1 here) */

    /* AMBIENTMATERIALSOURCE = COLOR1: Ga * vertex diffuse rgb (r clamps at 1: 0.4 + 0.75) */
    st.rs[RS_AMBIENTMS] = MCS_COLOR1;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1.f, 0.4f, 0.4f));   /* Ce + Ga*(1,0,0), clamped */

    /* EMISSIVEMATERIALSOURCE = COLOR2: emissive from the vertex specular rgb */
    st.rs[RS_AMBIENTMS] = MCS_MATERIAL;
    st.rs[RS_EMISSIVEMS] = MCS_COLOR2;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.125f + 0.15f, 0.0625f + 0.1f, 8 / 255.f + 0.05f));

    /* DIFFUSEMATERIALSOURCE = COLOR2: the diffuse term (and output alpha) read the vertex specular */
    DevState st2;
    base_state(&st2);
    TestLight l = light(LIGHT_DIRECTIONAL, 1, 1, 1, 0, 0, 0);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st2, 0, &l);
    st2.rs[RS_DIFFUSEMS] = MCS_COLOR2;
    mat_set(&st2, 0.9f, 0.9f, 0.9f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    RawVtx in2 = { { 0, 0, 0 }, { 0, 1, 0 }, 0xFF101010u, 0x30FF8000u };
    RawVtx out2;
    lit_check(&st2, &in2, &out2);
    assert(near_c(out2.diff, 1, 128 / 255.f, 0));   /* Cd rgb from COLOR2 */
    assert(near_a(out2.diff, 0x30 / 255.f));        /* alpha from COLOR2 alpha */

    /* a vertex color the FVF lacks falls back to the material (MSDN "Per-Vertex Color State") */
    FvfLayout L;
    fvf_layout(0x12u /* XYZ|NORMAL */, &L);
    float wv[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    LightEnv e;
    assert(light_setup(&st2, &L, wv, &e) == 1);
    uint8_t raw[24];
    memset(raw, 0, sizeof raw);
    memcpy(raw, (float[]){ 0, 0, 0 }, 12);
    memcpy(raw + 12, (float[]){ 0, 1, 0 }, 12);
    CVert v;
    memset(&v, 0, sizeof v);
    v.w = 1.f;
    light_vertex(&e, wv, raw, &L, &v);
    assert(near_c(v.diffuse, 0.9f, 0.9f, 0.9f));   /* material diffuse: COLOR1 unavailable */
    assert(near_a(v.diffuse, 1.f));                /* material diffuse alpha (mat_set writes 1) */
}

/* ------------------------------------------------------------------ NORMALIZENORMALS */

static void test_normalize_normals(void) {
    const float PI = 3.14159265f;
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_DIRECTIONAL, 0.4f, 0.4f, 0.4f, 0, 0, 0);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st, 0, &l);
    /* WORLD scales by 2: the inverse-transpose shrinks transformed normals to half length */
    st.transform[256][0] = st.transform[256][5] = st.transform[256][10] = 2.f;

    RawVtx in = { { 1, 1, 0 }, { 1, 1, 0 }, 0xFFFFFFFFu, 0 };
    RawVtx out;
    float a45 = cosf(PI / 4);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.2f, 0.2f, 0.2f));   /* unnormalized: N=(0.5,0.5,0), NdL = 0.5 */

    st.rs[RS_NORMALIZENORMALS] = 1;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.4f * a45, 0.4f * a45, 0.4f * a45));   /* normalized after transform */
}

/* ------------------------------------------------------------------ specular */

static void test_specular(void) {
    const float PI = 3.14159265f;
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_DIRECTIONAL, 0, 0, 0, 0, 0, 0);
    memcpy(l.spec, (float[]){ 1, 1, 1, 1 }, 16);
    memcpy(l.dir, (float[]){ 0, 0, -1 }, 12);   /* Ldir = (0,0,1): toward the camera */
    enable_light(&st, 0, &l);
    st.rs[29] = 1;   /* SPECULARENABLE */
    st.rs[RS_SPECULARMS] = MCS_MATERIAL;
    mat_set(&st, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2.f);   /* white specular, Power 2 */

    /* on the half-vector: ndh = 1 -> 1^2 */
    RawVtx in = { { 0, 0, -5 }, { 0, 0, 1 }, 0xFF101010u, 0xC0000000u };
    RawVtx out;
    lit_check(&st, &in, &out);
    assert(near_c(out.spec, 1, 1, 1));           /* Cs * Ls * (N.H)^2 * 1 */
    assert(near_a(out.spec, 0xC0 / 255.f));      /* specular alpha untouched by lighting (fog owns it) */
    assert(near_c(out.diff, 0, 0, 0));           /* the light has no diffuse/ambient color */

    /* 60 degrees off the half-vector: ndh = 0.5, ^2 = 0.25 */
    memcpy(in.n, (float[]){ sinf(PI / 3), 0, cosf(PI / 3) }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.spec, 0.25f, 0.25f, 0.25f));

    /* LOCALVIEWER=FALSE: the view vector is pinned to (0,0,1) regardless of the vertex position */
    memcpy(in.n, (float[]){ 0, 0, 1 }, 12);
    memcpy(in.pos, (float[]){ 5, 0, -5 }, 12);
    st.rs[RS_LOCALVIEWER] = 0;
    lit_check(&st, &in, &out);
    assert(near_c(out.spec, 1, 1, 1));           /* H = norm((0,0,1)+Ldir) = (0,0,1) */

    /* LOCALVIEWER=TRUE: view = norm(-V) = (-0.7071, 0, 0.7071), H follows it */
    st.rs[RS_LOCALVIEWER] = 1;
    lit_check(&st, &in, &out);
    float hx = -5 / sqrtf(50.f), hz = 5 / sqrtf(50.f) + 1;
    float ndh = hz / sqrtf(hx * hx + hz * hz);
    assert(near_c(out.spec, ndh * ndh, ndh * ndh, ndh * ndh));

    /* SPECULARENABLE=0: no specular computed, raw FVF specular kept */
    st.rs[29] = 0;
    lit_check(&st, &in, &out);
    assert(out.spec == in.spec);
}

/* ------------------------------------------------------------------ transport, gates, limits */

static void test_fog_transport(void) {
    /* the draw loop order: lighting writes specular RGB, fog then owns the alpha byte */
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_DIRECTIONAL, 1, 1, 1, 0, 0, 0);
    memcpy(l.spec, (float[]){ 1, 1, 1, 1 }, 16);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st, 0, &l);
    st.rs[29] = 1;
    st.rs[RS_SPECULARMS] = MCS_MATERIAL;
    mat_set(&st, 0, 0, 0, 0, 0, 0, 0.5f, 0.25f, 0.f, 0, 0, 0, 0);

    RawVtx in = { { 0, 0, 0 }, { 0, 1, 0 }, 0xFFFFFFFFu, 0x00102030u };
    RawVtx out;
    lit_check(&st, &in, &out);
    /* simulate the fog write that follows lighting in the loop */
    uint32_t fogged = (out.spec & 0x00FFFFFFu) | fog_alpha_byte(0.5f);
    assert(near_c(fogged, 0.5f, 0.25f, 0.f));   /* lit specular RGB survives */
    assert((fogged >> 24) == 128u);             /* the fog factor replaced the alpha byte */
}

static void test_lighting_off(void) {
    DevState st;
    base_state(&st);
    st.rs[RS_LIGHTING] = 0;
    st.rs[RS_AMBIENT] = 0xFF804020u;
    mat_set(&st, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0);
    TestLight l = light(LIGHT_DIRECTIONAL, 1, 1, 1, 0, 0, 0);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st, 0, &l);
    FvfLayout L;
    fvf_layout(FVF_NCD, &L);
    float wv[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    LightEnv e;
    assert(light_setup(&st, &L, wv, &e) == 0);   /* LIGHTING=0: the draw loop skips lighting */
}

static void test_light_sum_and_clamp(void) {
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_DIRECTIONAL, 0.6f, 0.6f, 0.6f, 0, 0, 0);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st, 0, &l);
    enable_light(&st, 7, &l);   /* two of the eight slots */
    RawVtx in = { { 0, 0, 0 }, { 0, 1, 0 }, 0xFFFFFFFFu, 0 };
    RawVtx out;
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1.f, 1.f, 1.f));   /* Cd=COLOR1 white: 0.6 + 0.6 clamps at 1 */
    /* all eight slots at once */
    base_state(&st);
    for (int i = 0; i < 8; i++) enable_light(&st, (uint32_t)i, &l);
    memcpy(in.n, (float[]){ 0, 0.5f, 0 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 1.f, 1.f, 1.f));   /* 8 * 0.6 * 0.5 clamps at 1 */
    /* light bytes in a disabled slot contribute nothing */
    base_state(&st);
    enable_light(&st, 0, &l);
    memcpy(st.light[7], &l, sizeof l);
    st.light_enabled[7] = 0;
    memcpy(in.n, (float[]){ 0, 1, 0 }, 12);
    lit_check(&st, &in, &out);
    assert(near_c(out.diff, 0.6f, 0.6f, 0.6f));
}

static void test_ambient_only_no_normals(void) {
    /* FVF without normals: no diffuse/specular term, emissive + global/per-light ambient only */
    DevState st;
    base_state(&st);
    TestLight l = light(LIGHT_DIRECTIONAL, 1, 1, 1, 0.3f, 0.3f, 0.3f);
    memcpy(l.dir, (float[]){ 0, -1, 0 }, 12);
    enable_light(&st, 0, &l);
    st.rs[RS_AMBIENT] = 0xFF102040u;   /* Ga = (16/255, 32/255, 64/255) */
    mat_set(&st, 0.9f, 0.9f, 0.9f, 0.5f, 0.5f, 0.5f, 0.9f, 0.9f, 0.9f, 0.1f, 0.1f, 0.1f, 0);

    FvfLayout L;
    fvf_layout(0x42u /* XYZ|DIFFUSE */, &L);
    float wv[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    LightEnv e;
    assert(light_setup(&st, &L, wv, &e) == 1);
    uint8_t raw[16];
    memset(raw, 0, sizeof raw);
    memcpy(raw, (float[]){ 0, 0, 0 }, 12);
    w32v(raw + 12, 0x80FF8000u);   /* vertex diffuse, no specular in the FVF */
    CVert v;
    memset(&v, 0, sizeof v);
    v.w = 1.f;
    v.diffuse = 0x80FF8000u;   /* what convert_vertex would have loaded from the FVF */
    light_vertex(&e, wv, raw, &L, &v);
    /* emissive(0.1) + Ga*Ca + La*Ca per channel; the sun's diffuse term never applies without a normal */
    assert(near_c(v.diffuse, 0.1f + (16 / 255.f + 0.3f) * 0.5f, 0.1f + (32 / 255.f + 0.3f) * 0.5f,
                  0.1f + (64 / 255.f + 0.3f) * 0.5f));
    assert(near_a(v.diffuse, 128 / 255.f));   /* unlit vertex alpha */
}

int main(void) {
    test_state_indices();
    test_directional();
    test_point();
    test_spot();
    test_color_sources();
    test_normalize_normals();
    test_specular();
    test_fog_transport();
    test_lighting_off();
    test_light_sum_and_clamp();
    test_ambient_only_no_normals();
    puts("lighting: states, directional/point/spot math, color sources, normalize, specular, "
         "fog-alpha transport and light limits passed");
    return 0;
}
