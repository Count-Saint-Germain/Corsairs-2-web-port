/* ps.1.1 translator check: the sea reflection shaders (handles 0x1000b / 0x1000d, GF3Shaders.sha)
   must translate instead of being rejected on texm3x3vspec (op 77). The token streams below are
   the assembler output of the two shaders, hand-encoded from their asm (version, tex t0,
   texm3x3pad t1,t0_bx2, texm3x3pad t2,t0_bx2, texm3x3vspec t3,t0_bx2, then r0 = t3 [* v0] [+ v1]). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char *ps_to_wgsl(const uint32_t *code, uint32_t n, char *why, size_t why_n);

#define OP(o, len) ((len) << 16 | (o))
#define DEST(reg, mask) ((mask) << 16 | (reg))                       /* r#/t# dest, no sat/shift */
#define SRC(type, num, mod) ((type) << 28 | (mod) << 24 | 0xE4u << 16 | (num))
#define SRCW(type, num, mod, swz) ((type) << 28 | (mod) << 24 | (swz) << 16 | (num))

static const uint32_t reflect[] = {
    0xFFFF0101u,
    OP(66, 2), DEST(3 << 28 | 0, 0xF),                                    /* tex t0 */
    OP(73, 3), DEST(3 << 28 | 1, 0xF), SRC(3, 0, 4),                      /* texm3x3pad t1, t0_bx2 */
    OP(73, 3), DEST(3 << 28 | 2, 0xF), SRC(3, 0, 4),                      /* texm3x3pad t2, t0_bx2 */
    OP(77, 3), DEST(3 << 28 | 3, 0xF), SRC(3, 0, 4),                      /* texm3x3vspec t3, t0_bx2 */
    OP(1, 3), DEST(0, 0xF), SRC(3, 3, 0),                                 /* mov r0, t3 */
    OP(5, 4), DEST(0, 0xF), SRC(0, 0, 0), SRC(1, 0, 0),                   /* mul r0, r0, v0 */
    OP(2, 4), DEST(0, 0x7), SRC(0, 0, 0), SRC(1, 1, 0),                   /* add r0.rgb, r0, v1 */
    0x0000FFFFu,
};
static const uint32_t reflect_sunroad[] = {
    0xFFFF0101u,
    OP(66, 2), DEST(3 << 28 | 0, 0xF),                                    /* tex t0 */
    OP(73, 3), DEST(3 << 28 | 1, 0xF), SRC(3, 0, 4),                      /* texm3x3pad t1, t0_bx2 */
    OP(73, 3), DEST(3 << 28 | 2, 0xF), SRC(3, 0, 4),                      /* texm3x3pad t2, t0_bx2 */
    OP(77, 3), DEST(3 << 28 | 3, 0xF), SRC(3, 0, 4),                      /* texm3x3vspec t3, t0_bx2 */
    OP(1, 3), DEST(0, 0xF), SRC(3, 3, 0),                                 /* mov r0, t3 */
    OP(5, 4), DEST(0, 0x7), SRC(0, 0, 0), SRCW(1, 1, 0, 0xFF),            /* mul r0.rgb, r0, v1.a */
    0x0000FFFFu,
};

static int run(const char *name, const uint32_t *code, uint32_t n, const char *const *needles) {
    char why[96] = "";
    char *fs = ps_to_wgsl(code, n, why, sizeof why);
    int ok = fs != NULL;
    printf("== %s: %s (%s)\n", name, ok ? "translated" : "REJECTED", ok ? "ok" : why);
    if (!ok) return 0;
    puts(fs);
    for (int i = 0; needles[i]; i++)
        if (!strstr(fs, needles[i])) { printf("FAIL: missing %s\n", needles[i]); ok = 0; }
    free(fs);
    return ok;
}

int main(void) {
    static const char *const need_reflect[] = {
        "vec3<f32>(pad0, pad1", "i.tc1.w, i.tc2.w, i.tc3.w", "2.0 * dot(x", "smoothstep",
        "t3 = vec4<f32>(x", "textureSample(cube3, smp3, x", "u.flags.w == 2u", "textureSample(tex0, smp0, i.tc0.xy)", "let o = saturate(r0)", NULL,
    };
    static const char *const need_sunroad[] = {
        "vec3<f32>(pad0, pad1", "t3 = vec4<f32>(x", "v1).wwww", NULL,
    };
    int ok = run("SeaPS_GF3Reflect", reflect, sizeof reflect / 4, need_reflect) &&
             run("SeaPS_GF3ReflectSunRoad", reflect_sunroad, sizeof reflect_sunroad / 4, need_sunroad);

    /* a shader that must still be rejected: texdepth (op 78) */
    static const uint32_t texdepth[] = { 0xFFFF0101u, OP(78, 2), DEST(3 << 28 | 3, 0xF), SRC(3, 0, 4), 0x0000FFFFu };
    char why[96] = "";
    if (ps_to_wgsl(texdepth, sizeof texdepth / 4, why, sizeof why)) { printf("FAIL: texdepth translated\n"); ok = 0; }
    else printf("== texdepth rejected (%s)\n", why);
    printf(ok ? "PASS\n" : "FAIL\n");
    return !ok;
}
