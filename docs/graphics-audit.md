> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

> **Status as of 2026-11-12:** the 2026-11-06 header is outdated: W2, W3 (cube sampling, op 77), W5 and W6 are implemented and accepted; TCI camera-space, COUNT2 and zbias remain unimplemented (low priority); W1 (vtable) was a false alarm. See `historical log (removed)`, §3.3.

> **Update 2026-11-06:** the early sections below preserve the history and describe the state at the time of the experiments. Server 8011 has stopped; the culling and FVF reading fixes have already been integrated into the main build, as has the opt-in sea-only fallback. See the later sections and `historical log (removed)` for details. Full cube textures and shader op 77 are still unimplemented.

> **CORRECTION (2026-11-05):** the claim in this report about “swapping IDirect3D8 vtable slots 5/6/7” is INCORRECT. The official d3d8.h (dxsdk) confirms that the template uses the canonical order; no change is needed. The other findings (sea shaders texm3x3vspec/ps.1.4, missing fixed-function lighting) remain valid.

> **Browser check, 2026-11-05:** the game reached the dialog in the tutorial cabin; purple areas were visible on the floor and beyond the door. The console reported `[wgpu] pixel shader 1000b not translated: texture op 77 (cube maps)` and a similar error for `1000d`. A fixed-function shader is used when translation fails; the cause of the purple floor was not independently established. The current code creates `RT_CUBETEXTURE` objects, but the recorder passes only `RT_TEXTURE` for sampling and WGSL samplers are declared as `texture_2d`: full cube sampling is not yet available. The purple areas have not been proven to result from any one error.

> **Isolated GF2MX experiment:** a separate copy of the port was created in `historical diagnostic materials (removed)`. Only in that copy, `fill_caps()` reports `PixelShaderVersion=0`; the declared vertex shader version was unchanged. The web build succeeded (`historical diagnostic materials (removed)`), and a local comparison server listens on `http://localhost:8011/`. In the embedded browser, the same cabin showed gray water beyond the door and a dark blue surface at the bottom instead of bright purple sea; messages about unsupported texture op 77 disappeared. A repeated run of the tracing build confirmed `[gf2mx-probe] selected=0 pixel=0.0`; index 0 corresponds to `Geforce2MXSea` in the sea.dll table. Some floor/geometry still appears missing; water quality is limited, and the cause of the geometry defect has not been independently established. This is a global caps change in the copy, not a verified fix. The main build was unchanged. The historical Python run reported one passing 2D test and two expected failures: the recorder then lost the third and fourth FVF coordinate components. The current equivalent is `node --test web-port/tests/test_fvf_texcoords.mjs`.

> **Experiment limitations:** `fill_caps` serves both `IDirect3D8::GetDeviceCaps` and `IDirect3DDevice8::GetDeviceCaps`, so the zero pixel-shader cap is visible to all consumers, not just the sea. The supplied technique files also explicitly assign a pixel shader in `SeaFoam.sha`, whose ps.1.1 was previously reported as supported; the effect of changing caps on foam requires separate testing. The tracing build was recorded in `historical diagnostic materials (removed)`.

# Graphics-Layer Audit — Sea Dogs II / Pirates of the Caribbean (Storm engine) → WebGPU port

Read-only static audit. Evidence: PE imports/disassembly of `game/MODULES/DX8RENDER.dll` (capstone/pefile),
61 `game/MODULES/Techniques/**/*.sha` files, and template host source
(`~/Tools/retro-port/plugins/retro-port/skills/port-pc-game-to-browser/template/recomp/host/`).
The live port copy `~/ports/korsary2/recomp/host/` was spot-checked and matches the template
(d3d8.c method tables identical, including the flagged IDirect3D8 ordering).

---

## 1. DX8RENDER.dll vs template D3D8 coverage

**Imports:** DX8RENDER.dll imports exactly ONE function from d3d8.dll: `Direct3DCreate8` (IAT 0x1002E164,
jump-thunk 0x1000D720, one call site 0x10002AA5). Everything else is COM vtable calls, so coverage must be
judged on vtable slots. No d3dx8 import — DX8RENDER embeds its own assembler ("D3DX8 Shader Assembler
Version 0.91" string, `Technique.cpp`).

**Vtable-call scan** (all indirect `call [reg+disp]` in .text): heavily polluted by Storm service interfaces
(this-in-ECX convention, e.g. the logging service at `[0x1003E348]`). Genuine D3D calls were pinned by
argument-content anchors, e.g.:

| site | disp/idx | args observed | canonical method |
|---|---|---|---|
| 0x1000209E | 0xC8 / 50 | (this, 19, 5), (this, 20, 6) | `SetRenderState(D3DRS_SRCBLEND, SRCALPHA)` etc. |
| 0x100020C2 | 0x118 / 70 | (this, 4, 0, 2*n) | `DrawPrimitive(TRIANGLELIST, 0, n)` |
| 0x10003BB8 | 0x1C / 7 | (this, &caps) | `GetDeviceCaps` (device) |
| 0x10002B2F | 0x20 / 8 | (this=IDirect3D8, 0, &mode) | `GetAdapterDisplayMode` |
| 0x10002C4E/C6A | 0x3C / 15 | CreateDevice/Present (both idx 15) | confirmed by template note "creates one, releases it, creates another" |

Observed device-method usage (disp → count) mapped through the canonical IDirect3DDevice8 vtable:
TCL 21, GetAvailableTextureMem 4, GetDeviceCaps 4, GetDisplayMode 20, ShowCursor ~229 (mostly service noise),
Reset 3, Present ~8, SetRenderTarget 7, BeginScene 2, EndScene 2, Clear 3, SetTransform 5, MultiplyTransform,
SetViewport, SetMaterial 1, SetLight 2, LightEnable 2, SetRenderState 39, GetRenderState 1, GetTexture 6,
SetTexture 3, GetTextureStageState 1, SetTextureStageState 26, SetCurrentTexturePalette, DrawPrimitive 1,
DrawPrimitiveUP 2, DrawIndexedPrimitive 5, DrawIndexedPrimitiveUP 1, ProcessVertices 5, CreateVertexShader 3,
SetVertexShader 2, DeleteVertexShader 1, SetVertexShaderConstant 3, GetVertexShaderConstant 8,
SetStreamSource 6, SetIndices 5, CreatePixelShader 3, SetPixelShader 1, SetPixelShaderConstant 6,
GetPixelShaderFunction 5, plus CreateTexture/CreateVertexBuffer/CreateIndexBuffer/CreateCubeTexture/
GetCubeMapSurface/CopyRects (strings `d3d8->CreateCubeTexture`, `tex->GetCubeMapSurface`, cube-mip error text
confirm runtime use). **State-block methods (idx 52-57) are never called. Patches (94-96) never called.**

**Coverage verdict vs template `d3d8.c`:**

| Group | Template status |
|---|---|
| IDirect3DDevice8 (97 slots) | **All slots present**, real impls for every method the game calls; only DrawRectPatch/DrawTriPatch/DeletePatch are NULL stubs (warn + S_OK) — never called by this game. Coverage ≈ **96/96 used slots (100%)**. |
| IDirect3D8 (16 slots) | 13/16 correctly placed; **slots 5/6/7 are permuted** vs canonical d3d8.h — see risk W1. |
| Resource interfaces (texture/cube/surface/vb/ib/swapchain) | Implemented incl. GetCubeMapSurface, LockRect, dirty-upload. |

**Slot-order defect (highest-confidence correctness bug):** template `d3d_methods[]` order is
`[5]=GetAdapterIdentifier, [6]=GetAdapterModeCount, [7]=EnumAdapterModes`; canonical d3d8.h is
`[5]=GetAdapterModeCount, [6]=EnumAdapterModes, [7]=GetAdapterIdentifier`. If the game calls canonical
slot 5 (`GetAdapterModeCount(Adapter)` — 1 stack arg), the template runs `GetAdapterIdentifier` which
`memset(HP(p), 0, 1068)` writes **1068 bytes into the game's 12-byte D3DDISPLAYMODE buffer** and pops 16
bytes where the game pushed 8 → guest stack/memory corruption at init. Slot 6 (`EnumAdapterModes`) would
dispatch `GetAdapterModeCount` (returns count in EAX as if HRESULT; 8-byte pop vs 16 pushed). The device
vtable is correct at every verified anchor; only the state-block cluster (53-57) is permuted (Begin/
**End,Apply,Capture,Delete,Create** vs canonical Begin/**Create,End,Delete,Apply,Capture**) — unused by
DX8RENDER.dll, so harmless here but worth fixing while touching the file. Fix both tables by hand to the
canonical order and confirm via `PORT_LOG_D3D=2` (`[com] IDirect3D8::…` lines around init).

---

## 2. Shader audit (.sha files)

The 61 `.sha` files are Storm technique scripts (`block/technique/pass` with render-state assignments).
Raw D3DX8 assembly lives in `VertexShader Name { decl{…} asm{ … } }` / `PixelShader Name { asm{ … } }`
blocks inside 8 of them (7 with version directives found by text scan; every asm block carries its own
version line):

**Inventory: 9 shader programs (3 vertex + 6 pixel), all for the sea.**

| version | count | shaders (file) | opcodes used |
|---|---|---|---|
| vs.1.0 | 3 | SeaVS_ATIReflect (Weather/Shaders/ATIShaders.sha), SeaVS_GF3Reflect (GF3Shaders.sha), SeaVS_Foam (SeaFoam.sha) | dp3×36, mul×24, mov×22, dp4×14, rsq×9, add×8, mad, sub×3, max×2, expp×2, rcp×2, def, decl |
| ps.1.1 | 5 | SeaPS_GF3Reflect, SeaPS_GF3ReflectSunRoad (GF3Shaders.sha); SeaPS_XBoxReflect, SeaPS_XBoxReflectSunRoad (XBoxShaders.sha); SeaPS_Foam (SeaFoam.sha) | tex, **texm3x3pad×8, texm3x3vspec×4**, mov, mul, add, lrp |
| ps.1.4 | 1 | SeaPS_ATIReflect (ATIShaders.sha) | texcrd×4, texld×3, dp3×3, mul×2, add×2, mad, **phase**, def |

Technique selection: `sea.dll` references blocks `Geforce2MXSea`, `Geforce3Sea`, `Geforce3SeaSunRoad`,
`Radeon8500Sea` plus attribute `gf2mx` (Weather/Sea/{G2MXSea,G3Sea,XBoxSea,RadeonSea}.sha). GF3/XBox blocks
bind `SeaVS_GF3Reflect` + the ps.1.1 `texm3x3vspec` shaders; Radeon block binds the vs.1.0/ps.1.4 pair.

**Template comparison:**

- `vshader.c` (CPU vs.1.1 interpreter): implements opcodes 1-24 (mov/add/sub/mad/mul/rcp/rsq/dp3/dp4/min/
  max/slt/sge/exp/log/lit/dst/lrp/frc/m4x4/m4x3/m3x4/m3x3/m3x2), expp(78), logp(79), def(81), a0 relative
  addressing, D3DVSD declaration parsing (STREAM/REG/SKIP/CONST/EXT), 12 temps, 96 constants.
  **Every opcode in the 3 vertex shaders is supported.** vs.1.0 is a subset of vs.1.1. No vertex-side gap.
- `pshader.c` (ps.1.x → WGSL): accepts **only ps.1.0/ps.1.1 version tokens** (0xFFFF0100/0xFFFF0101);
  arithmetic mov/add/sub/mad/mul/dp3/dp4/lrp/cnd/cmp; texture ops texcoord, texkill, tex, texbem, texbeml,
  texreg2ar, texreg2gb, texm3x2pad, texm3x2tex, texm3x3pad. **texm3x3tex/texm3x3spec/texm3x3vspec hit the
  `default:` branch → shader rejected → fixed-function fallback.** ps.1.2/1.3/1.4 → rejected at the version
  check. Co-issued rgb/alpha pairs and destination shifts (×1..×8, _x2/_bx2, saturate) are handled.

**(a)/(b) Concrete risk list — .sha vs template:**

| # | Construct | Files | Template |
|---|---|---|---|
| S1 | ps.1.1 `texm3x3pad`+`texm3x3vspec` (cube-map env reflection) | GF3Shaders.sha, XBoxShaders.sha (SeaPS_*Reflect, SeaPS_*ReflectSunRoad) | **REJECTED** (default case "texture op … cube maps") → sea reflections fall back to fixed function → wrong water. Needs cube-map sampling in render_wgpu.c + m3x3 emission in pshader.c. |
| S2 | ps.1.4 (texcrd/texld/phase) | ATIShaders.sha (SeaPS_ATIReflect) | **REJECTED** (version token). Avoid: never let the game pick Radeon8500Sea (report caps/vendor accordingly). |
| S3 | vs.1.0 / ps.1.1 foam path (tex,tex,lrp,mul,mov) | SeaFoam.sha (SeaVS_Foam/SeaPS_Foam) | Fully supported. |

**(c) Runtime technique**: with template caps (VertexShaderVersion=vs_1_1, PixelShaderVersion=ps_1_1,
vendor NVIDIA GeForce 6800 GT / 0x10DE:0x0045), sea.dll will most plausibly select the Geforce3/XBox
ps.1.1 path → hits S1. The engine can select the Geforce2MXSea technique based on shader capability: that block
is pure fixed function (ColorOp[0]=modulate2x, ColorOp[1]=modulatealpha_addcolor, ColorOp[2]=disable) —
**but** it uses `TexCoordIndex[1] = cameraspacereflectionvector` (see W4), which the template also doesn't
implement. `Sea.GF2MX` script attributes hold weather parameters; they do not select the technique.
Changing globally advertised shader caps may affect other materials; use only in an isolated experiment.

---

## 3. Runtime flags, formats, render states

**Texture formats.** DX8RENDER.dll strings name: `D3DFMT_A1R5G5B5, D3DFMT_A4R4G4B4, D3DFMT_A8R8G8B8,
D3DFMT_DXT1, D3DFMT_DXT3, D3DFMT_DXT5, D3DFMT_R5G6B5, D3DFMT_X8R8G8B8`. Ground truth from the 1768
pre-converted `RESOURCE/**/*.tx` cache files (header at +16): DXT1 1015, DXT5 77, DXT3 49, and numeric
codes 21=A8R8G8B8 (34), 22=X8R8G8B8 (13), 23=R5G6B5 (487), 25=A1R5G5B5 (35), 26=A4R4G4B4 (58); sizes up to
2048×2048, 1-10 levels. `texconv.c` decodes **all of these** (DXT1-5 incl. alpha, P8 with palette, L8, A8,
A8L8, A1R5G5B5, A4R4G4B4, R5G6B5, X1R5G5B5, R8G8B8, A8R8G8B8, X8R8G8B8) → **no format gap**. Palettized
textures exist at runtime (TGA loads; DLL carries the shared-palette error text;
SetPaletteEntries/SetCurrentTexturePalette implemented in template). sea.dll bump maps: `SeaBump%04d.tga`
(+ .tx). Uncompressed bump/normal formats (V8U8 etc.) are NOT seen in shipped data and are NOT in texconv —
add only if a TGA path turns out to request them.

**CreateDevice/swapchain flags.** Behavior flags are read but not branched on by the template (always
CPU vertex processing + CPU shaders, which is the right model — logs `behavior %x`). Caps advertise
DYNAMICTEXTURES/CANRENDERWINDOWED/FULLSCREENGAMMA, PresentationIntervals IMMEDIATE|ONE, 8 blend stages,
4 simultaneous textures, 8 texcoord sets, vs_1_1 + 96 constants, ps_1_1, non-POW2 textures. These caps
drive sea.dll technique choice (see S1/S2). Multisample: CheckDeviceMultiSampleType accepts only 0/1.

**Render/state surface actually set by the shipped techniques** (state-name census over all 61 .sha):
ColorOp/AlphaOp/ColorArg1-2/AlphaArg0/AlphaArg1-2 (630+ sets), AlphaTestEnable/AlphaRef, AlphaBlendEnable,
SrcBlend/DestBlend, CullMode, Lighting, FogEnable/FogVertexMode/FogTableMode, ZEnable/ZWriteEnable,
ColorVertex, SpecularEnable, TextureFactor, TexCoordIndex (incl. `cameraspacereflectionvector`,
`CameraSpaceNormal`), TextureTransformFlags, AddressU/V, LocalViewer, NormalizeNormals, zbias (depth bias,
mdebug/shark/Effects). Known state names also in DX8RENDER.dll: PointSpriteEnable, StencilPass, mipmaplodbias,
pixelshader/vertexshader(+constant), texture_degradation. Template `SetRenderState`/`SetTextureStageState`
store the full RS (200+) / TSS (32×8) arrays, and the WGSL fixed-function `top()` implements every
D3DTOP used: selectarg1/2, modulate, modulate2x, modulate4x, add, addsigned(2x), subtract, addsmooth,
blenddiffuse/texture/factor/current-alpha, blendtexturealpham, modulatealpha_addcolor, modulatecolor_addalpha,
modulateinvalpha_addcolor, modulateinvcolor_addalpha, dotproduct3, multiplyadd, lerp (arg0 complement +
alpha-replicate handled). **All ops present** — but see stage/feature gaps below.

---

## 4. Module probes (feature usage)

Every gameplay module imports nothing from d3d8/d3dx8; all carry the string `"No service: dx8render"`
— **DX8RENDER.dll is the only direct D3D8 consumer.** Per module:

- **sea.dll** (ocean): `BumpMap.cpp`, `CubeMap.cpp`, `ShipTrail.cpp`; technique blocks Geforce2MXSea /
  Geforce3Sea / Geforce3SeaSunRoad / Radeon8500Sea; attributes WaterReflection, sea_reflection, cubemap,
  bump; textures `SeaBump%04d.tga(.tx)`, `pena.tga`. → needs: render targets (reflection), cube-map
  sampling, ps.1.1 texm3x3vspec (or gf2mx fallback + TCI fix).
- **PARTICLES.dll / seafoam.dll**: technique-driven sprite quads (`key_alpha`, "no technique for particle
  system") — fixed-function alpha-blend tris; no shader strings. Should be fine.
- **Lighter.dll**: lightmap baking ("Smooth shadows"/"Trace shadows", `_shadow`); goes through dx8render
  (likely CopyRects/SetRenderTarget + locked surfaces — template implements both).
- **WEATHER.dll**: sky (`sky_side.tga`, `sky_up.tga`), SunGlow, WaterFlare, Lightning, rain, fog color
  (WhrCalcFogColor), TimeBlend/MaxBlend techniques. Heavy FogEnable user — see F3.
- **rigging.dll**: sail/flag textures, `alpha_rand` — plain blended geometry.
- **shadow.dll / ISLAND.dll / ship.dll**: technique blocks shadow_draw/shadow_smooth/shadow_model;
  multi-stage blends (shadow.sha sets ColorOp[2], disabled in most blocks).
- **DX8RENDER.dll** itself: cube maps (load + GetCubeMapSurface), palettized textures, point sprites
  (PointSpriteEnable known but unused by shipped techniques), texture_degradation, ValidateVertex/PixelShader.

**Template render-target path**: `render_cmd.h` supports it end-to-end — `CmdTarget` (color+depth ids),
TS_RTSURF texture slots (RT sampled as texture), `CMD_UPLOAD_SURF`/`CMD_READBACK`, CopyRects, upload_surface
hook; wgpu side creates offscreen textures and render passes. **Cube maps are NOT sampled anywhere in
render_wgpu.c** (d3d8.c creates RT_CUBETEXTURE objects, but there is no cube view/sampler in WGSL and
pshader refuses cube-map-dependent ops).

---

## 5. Work items for the bring-up agent (risk-ranked)

**W1 — Fix IDirect3D8 vtable slot order (blocker for init).**
What: template+port `d3d8.c` `d3d_methods[]` slots 5/6/7 are `[GetAdapterIdentifier, GetAdapterModeCount,
EnumAdapterModes]`; canonical is `[GetAdapterModeCount, EnumAdapterModes, GetAdapterIdentifier]`.
Where: `recomp/host/d3d8.c` (both copies; com.c dispatches by slot index).
Why: canonical slot 5 (`GetAdapterModeCount`) would memset 1068 bytes over the game's 12-byte struct and
corrupt the guest stack; slot 6 breaks resolution enumeration. One wrong call at boot = crash/corrupt mode
list. Fix in 1 minute; verify with `PORT_LOG_D3D=2` and confirm `IDirect3D8::GetAdapterModeCount` /
`EnumAdapterModes` land correctly during startup. Optionally also fix the unused 53-57 state-block cluster
order to canonical.

**W2 — Per-vertex fixed-function lighting with normals.**
What: D3D fixed-function lighting (D3DLIGHT8: directional sun/moon + point lights, material diffuse/
ambient/specular, NormalizeNormals) is not computed anywhere. WGSL only multiplies ambient when the FVF has
NO normals (`render_rec.c:446`). POTC ships ships/crew/islands with normals and 120+ technique passes set
`Lighting = true`; WEATHER.dll feeds sun/moon lights.
Where: `render_rec.c` (CPU lighting — best: it already walks every vertex and has FVF normals, lights and
material in `Device.st`), or WGSL.
Why: every outdoor scene renders fullbright/flat — the most visible global artifact after basic bring-up.
Suggested: CPU per-vertex loop over enabled lights (few lights in practice), fold into `CVert.diffuse`
before upload; also implement specular (rs 29) into `CVert.specular`.

> **Implemented, 2026-11-09 (code + synthetic tests only; browser verification deferred):** the recorder
> computes the D3D8 fixed-function lighting per vertex in `recomp/host/render_rec.c` (lighting helpers +
> the fixed-function draw loop) for every non-pre-transformed draw when LIGHTING=1 — including FVF draws
> without normals, which now get the documented ambient-only result (emissive + global/per-light
> ambient) instead of the old GPU ambient hack (`Uniforms.flags[3]` is retired; the WGSL branch in
> render_wgpu.c remains but is never enabled, so that file is untouched). Lighting runs in camera space
> per MSDN "Camera Space Transformations": V through WORLD·VIEW, normals through its inverse transpose
> (NORMALIZENORMALS normalizes afterwards), light positions through VIEW, directional light directions
> as −norm(Direction·VIEW). Per light: Atten = 1/(att0+att1·d+att2·d²) with Range culling and the
> spotlight cone (Theta/Phi are total angles, halved before the cosines, Falloff exponent; outside Phi
> the light adds nothing, ambient included). Vertex RGB = emissive + Ca·(D3DRS_AMBIENT + Σ
> Atten·Spot·La) + Σ Cd·Ld·max(N·Ldir,0)·Atten·Spot; specular RGB = Σ Cs·Ls·(N·H)^Power·Atten·Spot with
> the LOCALVIEWER half-vector (norm(−V)+Ldir local, (0,0,1)+Ldir remote), packed into CVert.specular
> RGB — the fixed-function WGSL already adds it after texturing on SPECULARENABLE, and ps.1.x WGSL
> reads v1 = specular itself. COLORVERTEX=0 forces the material; the four MATERIALSOURCE states select
> material/COLOR1/COLOR2 with the MSDN fallback to the material when the FVF lacks the color. Vertex
> alpha is never lit: the output alpha is the unlit alpha of the diffuse color source (default COLOR1
> → vertex alpha), and CVert.specular alpha stays reserved for the fog factor (W5), applied after
> lighting exactly like the D3D pipeline. `d3d8.c` gained the documented LOCALVIEWER=TRUE default.
> Fixed en route: the old no-normals ambient path multiplied the global ambient by the material
> **specular** (wrong D3DMATERIAL8 offset, 8 instead of 4). Limits: per-vertex Gouraud approximates
> per-pixel specular/spot falloff; a zero attenuation denominator and Range≤0 are treated as no
> attenuation/no range limit; behavior without lights follows D3D (lit draws with a zero material go
> black instead of fullbright). Native test: `recomp/tests/test_lighting.c` / `run_lighting.sh native`
> (ASan/UBSan); fog/pshader/FVF/cull regressions green; browser verification recipe in
> `historical diagnostic materials (removed)`.

**W3 — Sea rendering path (cube-map reflection).**
What: (a) add cube-map sampling to render_wgpu.c (WGPUTextureViewDimension_Cube + sampler); (b) implement
texm3x3pad/texm3x3vspec (and texm3x3tex/spec) in `pshader.c` WGSL emission (3×dot rows + reflected
eye-vector cube fetch); (c) keep ps.1.4 rejected and steer the game away from Radeon8500Sea (caps/vendor
already do this — NVIDIA + ps_1_1 caps select the GF3/XBox path).
Where: `recomp/host/render_wgpu.c`, `pshader.c`, `d3d8.c` (surface-of-cube identity).
Why: the ocean is the game's centerpiece; today every sea-reflection pixel shader is rejected → wrong water.
Possible diagnostic comparison: select the Geforce2MXSea capability path in an isolated build. This path
still needs W4, and cube-texture use must be verified. `Sea.GF2MX` weather attributes do not select it.

**Scoped fallback diagnostic (implementation unverified):** the 2003 sea.dll initialization calls the renderer
for caps and returns at RVA `0x3ed6` (current rebased address `0x00c03ed6`), storing the returned caps in its own
object at `this+0x6c`; the pixel-shader version is at object offset `0x138`. An opt-in, version-checked
port hook immediately after that call could set only this sea object's reported version to zero before
the original technique-selection logic runs, leaving shared device caps and other modules unchanged.
Use module identity plus guest RVA and verify the instruction signature; fail closed on unknown versions.
This remains a visual fallback, not a correct cube-map implementation. Test that disabled mode changes
nothing, enabled mode selects index 0, normal caps are unchanged for other clients, and sea foam and
unsupported shader handling continue to work. Verify visual results independently in the browser.


**Stopped diagnostic implementation, 2026-11-05:** in `historical diagnostic materials (removed)` the global
`PixelShaderVersion` was restored to `0xffff0101`; a new `host/sea_fallback.c` checks an opt-in
`PORT_SEA_FALLBACK=1`, the module identity, return RVA `0x3ed6`, object bounds, and a 42-byte
instruction signature before clearing only the sea object's version field. The browser option is
`?sea_fallback=1`. A hook was inserted into the diagnostic generated `MODULES_sea_000.c` after the
caps call. This generated-file edit would be lost on retranslating; it is not a production integration.
These changes were stopped before tests, rebuild or browser validation; the served WASM is the previous
global-caps experiment, not this new code. Other-version handling and any actual visual effect remain
unverified. The unchanged main port has not received this fallback.

**W4 — TexCoordIndex camera-space generation and full tc-index range.**
What: WGSL picks only `tc0`/`tc1` by `st*b.z==1` and never computes `TCI_CAMERASPACENORMAL` (1),
`TCI_CAMERASPACEPOSITION` (2) or `TCI_CAMERASPACEREFLECTIONVECTOR` (3). These are the high-word values:
the DirectX 8 SDK defines them as `0x00010000`, `0x00020000`, and `0x00030000`, respectively
([Microsoft D3D8 header](https://github.com/apitrace/dxsdk/blob/master/Include/d3d8types.h)). Used by G2MXSea.sha (the fixed-function sea!), Ship/ship_reflect.sha
(CameraSpaceNormal), location/maineffects.sha (reflection vector).
Where: `render_rec.c` vertex loop (has view matrix + normals) → emit generated coords into the CVert tc
slots; extend `render_rec.c:451` packing so any index 0-7 maps to the right tc set, not just 0/1.
Why: without it, sea/ship reflection passes sample garbage; even the W3 fallback needs this.

**Verification plan (before enabling by default):**
- Test stage-specific TEXCOORDINDEX, including two stages selecting different FVF sets and indices 0–7.
  Preserve all 1–4 input components; `web-port/tests/test_fvf_texcoords.mjs` exposes current 3D/4D loss.
- Test identity and non-identity texture matrices with `D3DTTFF_DISABLE` and `COUNT2/COUNT3`: Microsoft's
  [2D translation example](https://learn.microsoft.com/en-us/windows/win32/direct3d9/special-effects)
  places offsets in `_31/_32`, so input-coordinate dimensionality matters.
- For generated coordinates test position, normal, and both `LOCALVIEWER` modes. Non-uniform world/view
  scale must use the inverse-transpose normal matrix; compare normalization off and on against the
  [camera-space rules](https://learn.microsoft.com/en-us/windows/win32/direct3d9/camera-space-transformations).
- Confirm texture stages are independent, `XYZRHW` and programmable vertex-shader output keep their
  established paths, and projected coordinates are compared against an actual D3D8 reference before
  declaring that mode correct.
- Capture comparable frames with the same camera, weather, stage states, textures and selected technique
  in browser; log `RT_CUBETEXTURE` binds separately. A correct TCI calculation alone does not implement
  the missing cube sampler or prove that the cabin floor defect is repaired.

**W5 — Fog.**
What: no fog implementation in render_rec.c/render_wgpu.c, but 90+ techniques set FogEnable/FogVertexMode/
FogTableMode and WEATHER.dll drives fog color/density (EWhr_GetFogDensity exported for other modules).
Where: easiest correct model is per-vertex exponential/table fog computed in render_rec.c into an
interpolant (add a float to CVert or fold into specular.alpha) then mixed at the end of both WGSL `fs`
entry points.
Why: everything beyond a short draw distance loses depth cueing; sea/island horizons look wrong.

> **Implemented, 2026-11-09 (code + synthetic tests only; browser verification deferred):** the recorder
> computes the D3D8 fog blend factor per vertex (`recomp/host/render_rec.c` fog helpers and the draw
> loop) — linear FOGSTART/FOGEND, exp/exp2 FOGDENSITY, depth = |camera z| or eye distance when
> RANGEFOGENABLE — and packs it into the alpha byte of `CVert.specular`, the same place D3D keeps it
> (MSDN "Fog Formulas"; formulas checked against learn.microsoft.com). FOGTABLEMODE takes precedence
> over FOGVERTEXMODE; table (pixel) fog is approximated per-vertex and interpolated, not per-pixel.
> The fog color rides in the new `Uniforms.fog` (`render_cmd.h`, 496-byte struct, USTRIDE 512 unchanged)
> and both fragment paths mix it by the specular-alpha factor: the fixed-function `fs` in
> `render_wgpu.c` and, via the `ps_inject_fog` tail injection (`render_cmd.h`, applied in
> `render_wgpu.c:ps_program`), the frozen pshader.c WGSL without touching the generator. Vertex-shader
> draws use the shader's own oFog.x (`vshader.c` RASTOUT #1 capture, `vs_writes_ofog`); the GF3/XBox sea
> shaders compute `rcp oFog.x` there, so their fog works too. XYZRHW draws are never fogged; FOGENABLE=0
> or mode NONE leaves every draw untouched. All seven fog render states already reach the recorder
> through `d3d8.c dev_SetRenderState`. Native test: `recomp/tests/test_fog.c` /
> `recomp/tests/run_fog.sh native` (ASan/UBSan). Limits: per-pixel table fog curve is not reproduced;
> when a vertex shader never writes oFog, its draws get no fog (hardware default oFog is unspecified);
> stages reading D3DTA_SPECULAR alpha see the fog factor; browser mixing, WGSL compile on Dawn and real
> technique behavior are unverified — see `historical diagnostic materials (removed)` for the browser recipe.

**W6 — Texture stages 2-3 in the fixed-function fragment path.**
What: `Uniforms` carries only st0/st1 and the WGSL evaluates exactly 2 stages; caps advertise 8 blend
stages / 4 simultaneous textures. Shipped techniques with an ENABLED stage 2: `location/maineffects.sha`
(ColorOp[2]=modulate2x), `artifact.sha` (ColorOp[2]=modulate); every other [2] occurrence is `disable`.
Where: `render_rec.c` (pack st2/st3), `render_cmd.h` (Uniforms), `render_wgpu.c` (WGSL stage loop —
tex2/tex3 bind groups already exist as slot_kind/slot_id).
Why: two location-effect and artifact passes render one blend short (wrong colors, not missing geometry).

> **Implemented, 2026-11-09 (code + synthetic tests only; browser verification deferred):** the
> recorder packs the blend state of stages 2-3 into the new `Uniforms.st2/st2b/st3/st3b`
> (`render_rec.c` `pack_stages`, extracted from the old stages-0/1 loop, which packs stages 0-1
> unchanged) — but only when stage 2 runs a real color op (`tss[2][1] > D3DTOP_DISABLE`): the raw
> unset value 0 has no D3DTOP meaning and the documented D3D8 default for stages 1+ is
> D3DTOP_DISABLE, which the zeroed uniforms express through the WGSL gates, so two-stage draws keep
> the previous path unchanged. When stage 2 is packed, a zeroed stage-3 colorop is normalized to
> DISABLE. The fixed-function `fs` in `render_wgpu.c` now evaluates up to four stages with the same
> nested-disable rule (a D3DTOP_DISABLE stage ends the rest of the pipeline, so each stage gates the
> next one): stages 0-1 keep their packing and gates untouched, stage 2/3 gates read 0 like DISABLE,
> and tex2/tex3 sample FVF sets 2/3 (the D3D8 default TEXCOORDINDEX = stage number). `Uniforms`
> grew 496 → 560 bytes and USTRIDE 512 → 768 (dynamic uniform offsets must be 256-aligned; nothing
> else hardcodes the size, `minBindingSize`/`be.size` already use `sizeof(Uniforms)`). D3D8 facts
> honored: no shipped technique enables stage 3; an alpha op alone cannot enable a stage whose color
> op is disabled; all shipped stage-2 alpha ops are disable, so alpha passes through. Limits: stages
> 4-7 are not implemented (none is enabled by any shipped technique despite the 8-stage caps), the
> per-stage TEXCOORDINDEX selection of audit W4 still does not cover stages 2-3, and artifact.sha
> leaves ColorArg2[2] unset, which the port's raw-tss policy packs as D3DTA_DIFFUSE where a fresh
> D3D8 device default would be D3DTA_CURRENT (location/maineffects sets both stage-2 args
> explicitly and is exact). Native test: `recomp/tests/test_texstage.c` / `run_texstage.sh native`
> (ASan/UBSan): layout/packing gate, 300-draw bit-exact equivalence of the old 2-stage vs the new
> 4-stage chains, hand-computed maineffects (modulate2x, saturating overshoot) and artifact cases,
> SELECTARG1/alpha-op on stage 2 and disable termination. Fog, lighting, pshader, cull and FVF
> regressions green; WGSL compile on Dawn and in-game behavior are unverified — see
> `historical diagnostic materials (removed)` for the browser recipe.

**W7 — Depth bias ("zbias") and point sprites (polish).**
What: no SLOPESCALEDEPTHBIAS/DEPTHBIAS handling in the recorder/wgpu depth state; TOPO_POINTS draws
single-vertex points with no point-size/point-sprite expansion. zbias is used by shark.sha, Effects/
maineffects.sha, mdebug; PointSpriteEnable is recognized by DX8RENDER but unused by shipped techniques.
Why: minor z-fighting on decals; particles currently never use points — verify PARTICLES.dll draw type at
runtime before spending time here.

**W8 — Idempotent checks (no code change expected).**
Formats: complete (see §3). Textures ≥2048², non-POW2, DXT mip chains: supported. Lighter lightmaps:
CopyRects + SetRenderTarget + lock/unlock all implemented — verify at runtime. `MaxPrimitiveCount=0xFFFFF`
in caps is fine for POTC. Storm's `.tx` container is parsed by DX8RENDER.dll itself (guest code), so no
host work needed beyond D3DFMT mapping. If any module requests P8 while a shader is bound, the shared-
palette restriction is not enforced (D3D would fail) — acceptable to ignore.

No fundamental blocker found: the template's architecture (CPU vertex pipeline, recorded commands, WGSL
pixel path) covers this game's needs; the gaps are correctness of specific features, all with clear
implementation sites.

## Scoped sea fallback: isolated A/B, 2026-11-06

The previously unfinished experiment in `historical diagnostic materials (removed)` was built
with `sh recomp/build_web_local.sh`; both browser and Node/WASM targets linked
successfully (`build-scoped-fallback.log`). The generated C hook is still an
experimental manual edit and will disappear if `out_all` is regenerated.
It has not been transferred to `korsary2-next`.

- `recomp/tests/test_sea_fallback.c`, run natively with ASan/UBSan, checks the
  unset/disabled flag, wrong return address, zero/out-of-range object, altered
  byte signature, unknown module and preservation of adjacent object words.
  The enabled, matching case changed only the inspected pixel-version word.
- Two Node/WASM headless runs used the same binary, separate `PORT_USERDATA`,
  `PORT_INPUT=300:key=1c`, and were stopped after 45 seconds each. Disabled:
  `[gf2mx-probe] selected=1 pixel=1.1`. Enabled: `[sea-fallback] sea-only pixel
  caps ffff0101 -> 00000000`, then `[gf2mx-probe] selected=0 pixel=0.0`.
  These logs prove selection for this initialization path, not rendering.
- In the Codex in-app browser, the same build and initial cabin camera were
  compared with and without `?sea_fallback=1`. Disabled showed bright purple
  water through the door and under the character, selected index 1, and logged
  unsupported pixel shader op 77 for 1000b and 1000d. Enabled showed gray-blue
  water through the door and a dark blue area under the character; its console
  confirmed the hook and index 0, with no shader-translation errors observed
  in that run. This reproduces the improvement without globally lowering caps.
  The ceiling/floor geometry still appears incomplete in both views. No proof
  of correct reflections, geometry, foam, other scenes or long-run stability.
- `fill_caps` remains statically set to `0xffff0101`; the hook changes the
  sea object's copied field, and its log confirms the copy initially contained
  that value. A separate runtime audit of other caps clients and sea foam is
  still needed. This is a narrow workaround, not cube sampling or a full fix.

Reproduce guard test from the diagnostic directory:

```sh
clang -std=c11 -Wall -Wextra -Werror -fsanitize=address,undefined \
  -Irecomp/runtime recomp/tests/test_sea_fallback.c \
  -o /tmp/korsary-sea-fallback-test && /tmp/korsary-sea-fallback-test
sh recomp/build_web_local.sh
node recomp/web/serve.mjs --port 8011 --game game
```

Open only the local server in the Codex built-in browser; add
`?sea_fallback=1` to enable. Its diagnostic `game` link targets
`historical diagnostic materials (removed)`; that copy may receive runtime logs. For automation,
use a separate userdata directory per process. The prior diagnostic web build
has been replaced by the scoped-hook build.

## Cull winding correction, 2026-11-06

A separate three-way browser experiment held the sea fallback on and compared
identical initial cabin views. The prior recorder reversed `D3DCULL_CW` and
`D3DCULL_CCW`; that view lacked the cabin floor, carpet, ceiling and parts of
furniture and showed water/sky through them. Passing the cull value directly
restored the floor, carpet, ceiling, bed and doorway; disabling culling also
restored them in that view. A fourth launch with direct mapping and the sea
fallback **off** restored the same cabin surfaces, showing this geometry result
is independent of the sea workaround. This does not establish correctness of
other locations, all materials, or transparent/double-sided effects.

The old reversal contradicts the configured pipeline: `frontFace=CW`,
`D3DCULL_CW` must reject clockwise faces and therefore maps to WebGPU `Front`;
`D3DCULL_CCW` maps to `Back`. See [Microsoft's D3DCULL values and meaning](https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dcull)
(the D3D9 enum is used here as supporting API documentation) and the [WebGPU
front-face and cull-mode definitions](https://www.w3.org/TR/webgpu/). WebGPU
specifies winding in framebuffer coordinates and notes matching DirectX pipeline
coordinate systems. If future code flips clip-space Y, reverses emitted vertex
order, or changes the pipeline front face, this mapping must be re-evaluated.
Pre-transformed XYZRHW continues to disable culling as before, separately from
this correction.

Only the winding correction was transferred to the main host: `render_rec.c`
passes the original cull state through and `render_wgpu.c` uses
`render_cull.h`. The opt-in sea hook and diagnostic flags were **not** moved.
A native table test passed (`recomp/tests/test_render_cull.c`): with CW front,
NONE rejects neither orientation, CW rejects clockwise only and CCW rejects
counterclockwise only. This unit test verifies the state mapping; it does not
render triangles or cover transformed vertex paths. The browser comparison above
was performed in the isolated diagnostic build. The main browser and Node/WASM
build subsequently completed through `build_web_local.sh`. In the Codex in-app
browser the rebuilt main version reached the menu and the initial cabin, where
the floor, carpet, ceiling, bed and doorway were visible. Other main-build
locations and material regressions remain to be checked.

Diagnostic flags in `historical diagnostic materials (removed)` are `?cull_diagnostic=direct` and
`?cull_diagnostic=none`; default retains the old reversed mapping for comparison.
The diagnostic web/Node build was refreshed using `build_web_local.sh` and the
build log is `build-cull-diagnostic.log`. These flags are not product features.

The isolated direct-cull build was also taken through Malcolm's opening dialog
and the transition into Oxbay port, with sea fallback **off**. The pier,
barrels, nearby walls and player were visible in that second location; the sea
was still bright purple. This confirms that the winding correction does not fix
the unsupported sea shader and is not a complete graphics audit. No A/B of
port geometry against the old winding was performed in this pass.

## FVF texture-coordinate dimensions: isolated fix, 2026-11-06

`historical diagnostic materials (removed)` now records the per-set FVF
dimension and copies exactly 1–4 floats into each of the existing four
`CVert` coordinate slots. The pre-existing slot defaults `(0, 0, 0, 1)` are
preserved for missing components; for a 1D coordinate the previous code
incorrectly overwrote `.y` by reading four bytes beyond that coordinate.
The FVF bit encodings (`1→3`, `2→0`, `3→1`, `4→2`) agree with Microsoft's
[format definitions](https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dfvf-texcoordsizen).
The existing padding convention has not been independently verified against a
D3D8 reference for every dimension.

Before the change, the new test `recomp/tests/test_fvf_dimensions.c` with an
exact-sized single-1D source triggered an ASan heap-buffer-overflow reading
8 bytes at `convert_vertex` (`historical diagnostic materials (removed)`). Afterward the
same test passed with ASan/UBSan and in Node/WASM. Cases cover individual
1D/2D/3D/4D sets, mixed dimensions and offsets, eight input sets, no texture
sets, and a layout with normal/diffuse/specular fields. The test verifies the
first four output sets and checks the layout's full stride; it does not claim
rendering support for input sets 4–7. Both browser and Node builds completed
via `build_web_local.sh` (`build-fvf-diagnostic.log`). In the Codex in-app
browser this build was opened, a new game started, and the initial cabin and
dialogue inspected: floor, carpet, ceiling, bed and characters were
visible, with no obvious regression versus the main build in that view. This
is a limited visual check, not an isolated visual test of 3D/4D coordinate
sampling. No other browser was used. The fix and test were then transferred to
the main port. Main native ASan/UBSan, Node/WASM and Python 3D/4D checks
passed; browser and Node builds completed via `build_web_local.sh`.
The latest rebuilt main browser version was also opened in the Codex in-app
browser and reached the initial cabin; the floor, carpet, ceiling, furniture
and characters remained visible. This is not a sampling-conformance test.

`CVert`, WebGPU vertex attributes and the vertex-stage varyings already carry
four components for four sets, and some translated ps.1.1 operations read
`.xyz`. In contrast, the fixed-function fragment shader currently selects
only `.xy` from tc0/tc1; camera-space generation, texture transforms, projected
sampling, selection of all 0–7 sets and cube texture sampling remain missing.
Thus successful FVF copying is not proof of correct sea rendering, projected
coordinates, or complete D3D8 texture handling. Actual GPU behavior of the
extra components has not been independently tested against D3D8.

Run the native test from `historical diagnostic materials (removed)`:

```sh
clang -std=gnu11 -Wall -Wextra -Werror -fsanitize=address,undefined \
  -ffunction-sections -fdata-sections -Wl,-dead_strip \
  -Irecomp/host -Irecomp/runtime recomp/tests/test_fvf_dimensions.c -lm \
  -o /tmp/korsary-fvf-diagnostic-test && /tmp/korsary-fvf-diagnostic-test
```

## Regeneration-stable opt-in sea fallback — isolated experiment, 2026-11-06

After the separate FVF routing native Metal GPU A/B described below, the narrow
stage 0/1 FVF routing patch was transferred to the main renderer. The main
native ASan/UBSan and Node/WASM unit tests passed, as did the browser/Node
rebuild. This does not establish GPU behavior in a browser or actual game
usage of FVF sets 2–7.

A subsequent run of the separate FVF-routing diagnostic also reached a sea
scene near the island: ship, sails, shore and dark water were visible. This is
another regression observation, not proof that the changed 2–7 routing was
used by the scene. A press of Space did not visibly establish cannon fire.

Correction to the earlier test description: the old Node runner exported
`PORT_TRACE_CALL` only to Node, not to Emscripten's libc environment, so that
run did not establish execution of the trace branch. The main-port test now
sets the mode through argv and `setenv`, verifies both trace log points and
checks that the plain run does not trace. Both native ASan/UBSan and Node/WASM
passed again. This changes the test, not the graphics runtime.

In a later short run of the main build with the fallback enabled, the in-app
browser transitioned from the Oxbay pier to the world map and then a sea
encounter. The player's ship and sails, a dark sea, sky and HUD were visible;
steering changed the ship's appearance and readings. No opponent, gunfire or
hits were visually established. This additional scene is not a fidelity or
long-duration comparison and does not establish that other weather works.

The earlier generated-C sea hook was removed by a full retranslation of all 46
images into **`historical diagnostic materials (removed)`**; no generated sea source is
patched. The new diagnostic-only implementation is in `runtime/sea_hook.h`
and the `runtime.c` indirect-call dispatcher. The legacy
`host/sea_fallback.c` is retained unused for its earlier test. Following the
isolated checks below, the guarded post-call hook and its tests were copied
to the main runtime as an opt-in; the diagnostic-only probes were not copied.
Main native ASan/UBSan and Node/WASM tests passed, and the main browser and
Node builds completed via `build_web_local.sh`. The rebuilt main port with
`?sea_fallback=1` reached Oxbay in the Codex in-app browser and showed gray-blue
water; its log confirmed the expected hook fingerprint. This one view does not
establish reflection fidelity, foam correctness or stability. A subsequent
separate run of the same main build without the option reached the same pier
and showed purple water and the two unsupported op-77 shader messages, with no
sea-hook messages. The main-build on/off comparison therefore covers this view,
not other scenes or weather conditions.

The hook is disabled unless `PORT_SEA_FALLBACK=1` / `?sea_fallback=1` is set.
The dispatcher first range-checks guest ESP and checks the **full** return PC
`0x00c03ed6` before any fallback logging or version check; unrelated indirect
calls, including ones with the same low 16 bits, are not candidates. It then
requires the `sea.dll` module at the known rebased base, and the FNV-1a-64
fingerprint `796fad582ab24ba9` of its entire relocated `.text` range. This
fingerprint is a version-mismatch guard, **not cryptographic authentication**;
an unknown version/rebase is skipped with a diagnostic, not adapted by guess.
The hook further checks the captured sea object's caps destination and renderer
vtable/target before dispatch. After the original call has returned it requires
the expected guest ESP advance, preserved ESI and `ffff0101` in the copied
pixel-cap field before changing that field to zero. A non-returning call has
no post-call effect. The global device caps remain `ffff0101`; this is still a
visual fallback rather than cube sampling, and may differ from a real GF2MX.

The actual dispatcher is exercised by `recomp/tests/test_sea_indirect_hook.c`
with the user's own locally loaded/rebased `sea.dll`. Native ASan/UBSan and
Node/WASM pthread suites pass both with and without `PORT_TRACE_CALL`. Cases
include disabled mode, other clients/call sites, same-low16 foreign PC, module
and fingerprint mismatches, object/argument/vtable mismatches, changed ESP/ESI,
unexpected caps, and normal indirect, tail-jump, dynamic-code and import
bookkeeping paths. The synthetic dynamic/import targets are test doubles; this
is not a full audit of all possible indirect calls. To reproduce from the
isolated diagnostic directory (local game assets stay private):

```sh
recomp/tests/run_sea_indirect_hook.sh native
recomp/tests/run_sea_indirect_hook.sh wasm
sh recomp/build_web_local.sh
```

Actual headless Node/WASM A/B on the regenerated port reached sea initialization:
off logged `[sea-probe] selected=1 pixel=1.1`; on logged the matching hook
fingerprint and `[sea-probe] selected=0 pixel=0.0`. The read-only sea-selection
probe checks the same code fingerprint, is enabled independently by
`PORT_SEA_DIAG=1` / `?sea_diag=1` and survives retranslation. In each run two
observed real `fill_caps` calls reported `ffff0101`, including a later distinct
client after sea selection (`runtime-stable-hook/off.log`, `on.log`); this is not
an exhaustive audit of every consumer or of foam. The browser build also passed.
In the Codex in-app browser the enabled hook reached Oxbay: the pier, shore and
character were visible and the water was gray-blue; the console reported the
hook enabled and `selected=0`. The disabled run reached the initial cabin with
`selected=1`, but its transition to port hit the known random `.PAD`
RaiseException before an Oxbay frame. An earlier run of the latest main build
without this fallback showed purple water on the same pier; consequently this
is a cross-run comparison, not a successful same-build visual A/B of that port
frame. It does not verify foam, reflection fidelity or long-term behavior. Use
`?cull_diagnostic=direct&sea_diag=1` in the isolated copy, adding
`&sea_fallback=1` for the enabled case. The diagnostic copy's old default cull
mapping is deliberate for prior comparisons; the main port already uses the
corrected mapping.

## Isolated fixed-function FVF coordinate routing, 2026-11-06

`historical diagnostic materials (removed)` routes each of the first two
fixed-function texture stages to its selected FVF coordinate set 0–7 when
both stage indices are plain values 0–7 and neither a programmable vertex nor
pixel shader is active. Previously the fixed fragment shader selected only
input set 1 or fell back to set 0, even though FVF layout already described
all eight sets. The recorder now copies the selected 1–4 components from the
original vertex into stage slots 0 and 1 before interpolation, preserving the
existing `(0,0,0,1)` fill for missing components, and records corresponding
slot indices. The two stages can select the same or different sets. All other
paths—including camera-space TCI, invalid/high-word indices, programmable
shaders, and texture transforms—retain their previous behavior; no claim of
correctness is made for them. The implementation is diagnostic-only.

`recomp/tests/run_fvf_routing.sh native` passed with ASan/UBSan, and the
`wasm` mode passed under Node. The existing FVF dimensions test also passed
again under native ASan/UBSan. The test invokes the recorder's real FVF layout,
conversion and routing helpers on exactly sized inputs; all 64 pairs of stage
indices are checked for 0–8 input sets, mixed 1–4 component dimensions,
XYZ and XYZRHW, same/different sets, defaults and preservation of other
vertex fields. It tests routing eligibility for both shader paths and generated
or out-of-range indices. This is CPU-side testing, not a GPU sampling test or
a full draw-state integration test. `sh recomp/build_web_local.sh` completed
both browser and Node builds (`historical diagnostic materials (removed)`).

The checked technique text explicitly selects pass-through indices 0 or 1;
no scene using indices 2–7 was established. Thus no visible improvement in the
game is asserted. In particular, this does not implement camera-space
coordinates, texture matrices, cube sampling, or fix the purple sea. Browser GPU sampling of non-default indices and a controlled in-game visual A/B remain
open before considering transfer to the main port. See the native offscreen A/B below. The agent's own attempt to
open the Codex IAB returned `Browser is not available: iab`; no alternative
browser was used. A separate agent with access to Codex IAB then opened the
diagnostic build with `?cull_diagnostic=direct&sea_fallback=1`: the menu,
cabin, and Oxbay appeared, with characters, cabin floor, carpet and furniture,
pier and gray-blue water visible. No obvious regression was noticed versus
previous views. This was not a controlled A/B and does not establish use of
TEXCOORDINDEX 2–7 or an improvement in the game. The temporary server was
stopped afterwards.


## Offscreen GPU A/B for FVF routing, 2026-11-06

A separate synthetic test now runs both recorders through the actual native
`render_rec` and `render_wgpu` drawing and readback path. The test creates a
64×64 offscreen target and a four-texel RGBA texture; it uses no game assets.
Its runner extracts the real `SetTextureStageState` handler and `dev` helper
from `d3d8.c` into a temporary file, supplies a synthetic guest call frame and
COM object lookup, and changes `TEXCOORDINDEX` between draws on the same
`Device`, with the same uploaded texture. The full COM dispatch path is not
part of this test. The executor is copied into a temporary file with only the
surface initialization changed to an offscreen target; the real shader,
texture binding, draw and readback logic are used. The baseline recorder is
the same diagnostic code with the new routing switch forced off, matching the
previous coordinate-selection branch, rather than a historical binary.

With the local Metal backend (reported Apple M4), GPU readback at the triangle
center produced the following ARGB values for **each** of stages 0 and 1:

| FVF set | Routing off | Routing on |
| --- | --- | --- |
| 0 | `ffff0000` | `ffff0000` |
| 2 | `ffff0000` | `ff00ff00` |
| 7 | `ffff0000` | `ff0000ff` |

With both stages enabled, stage 0 selecting 2 and stage 1 selecting 7, and
`COLOROP=ADD` on stage 1, readback changed from `ffff0000` to `ff00ffff`.
The native sandbox initially reported no Metal adapter; the local test passed
when run with GPU access. It does not exercise browser Dawn/WebGPU, an actual
Windows D3D8 reference, perspective interpolation, texture transformations,
generated camera coordinates, programmable shaders, or real game content.
The test is not an in-game visual A/B and does not establish that these
coordinate sets are used in a game scene. No browser was opened for this test.

The isolated diagnostic copy and its GPU runner have been removed, so this
specific Metal experiment cannot be reproduced from the current repository.
The current FVF coordinate checks can be run from the repository root with
`node --test tests/test_fvf_texcoords.mjs`; these do not reproduce the GPU A/B.
The isolated patch against the
current main recorder is `recomp/tests/fvf-routing-main.patch`: it excludes
the diagnostic cull-mode code and passed `patch --dry-run` against the main
copy. The patch has not been applied there.

## Narrow fixed-function COUNT2 texture transform, 2026-11-06

`game/MODULES/Techniques/worldmap.sha` declares `TextureTransformFlags[0] =
count2` in `WdmSeaDraw1/2` and `count2` for both stages in `WdmSeaDraw3`.
Those declarations establish requested technique states, not the actual FVF,
matrices, or whether those passes were used in a particular game session.
The diagnostic recorder previously ignored texture matrices.

An isolated change in `historical diagnostic materials (removed)` handles only
untransformed `XYZ`, a present 2D FVF texture-coordinate set, pass-through
indices 0–7, no programmable VS/PS, and exactly `D3DTTFF_COUNT2` on the
individual stage. It uses the relevant `D3DTS_TEXTURE0/1` matrix on `(u,v,1)`
before interpolation. The other dimension/flag cases, generated coordinates,
programmable shaders and XYZRHW retain their prior behavior. Microsoft's
[Direct3D 8 header](https://raw.githubusercontent.com/apitrace/dxsdk/master/Include/d3d8types.h)
confirms the state and transform indices; its [Direct3D 9 2D example](https://learn.microsoft.com/en-us/windows/win32/direct3d9/special-effects)
shows 2D translation in `_31/_32`, while [D3D9 texture transforms](https://learn.microsoft.com/en-us/windows/win32/direct3d9/texture-coordinate-transformations)
exclude already transformed and lit vertices. These D3D9 documents support the
bounded interpretation but are not an independent D3D8 hardware reference.

`recomp/tests/run_texture_transform2.sh native` passed under ASan/UBSan and
`wasm` passed under Node. It covers separate stage matrices, scale/shear and
translation, disabled/projected flags, omitted or non-2D sets, unsupported
indices and XYZRHW. Existing FVF routing tests passed both modes again.
`recomp/tests/run_texture_transform2_webgpu.py` passed its synthetic offscreen
GPU A/B under Metal on Apple M4: the actual extracted `SetTransform` and
`SetTextureStageState` handlers receive test guest frames and test COM lookup;
the real recorder/executor draws and reads back a four-color texture. For
both stages, identity read `ffff0000`; translations `_31=0.25/0.5` read
`ff00ff00/ff0000ff` with the fix and `ffff0000` without it; disabling the flag
returned red. Two simultaneous stage matrices and ADD produced `ff00ffff`
with the fix versus red without it. The XYZRHW control remained red. The
baseline is the same recorder with this new helper call disabled; initialization
is test-only offscreen, not the browser surface. CPU shader/device/COM services
are test substitutes, and neither this Metal run nor the CPU tests prove
browser Dawn behavior or correctness on D3D8 hardware.

Both browser and Node builds completed via `sh recomp/build_web_local.sh`
(`historical diagnostic materials (removed)`). Optional diagnostic query
`?texture_xform_diag=1` logs the first 32 structurally distinct COUNT2 draw
states, including FVF/PS, indices, texture dimensions and the first observed
matrices; matrices may change later without another log. The option is off by
default, and no conclusions about worldmap are made until a relevant draw is
observed. The isolated fix has not been transferred to the main port and does
not implement cube sampling, `texm3x3vspec`, camera-space generation, projected
texture coordinates, or transforms for other FVF dimensions.

A separate `historical diagnostic materials (removed)` APFS copy has its own `game` and
userdata, and a test-only headless draw callback logs the same bounded COUNT2
state summary without using a GPU. A 45-second Node run with Enter at frame 300
and Space at frames 700, 850, 1000 and 1150 logged entry into a new game and
the enabled sea hook, but no `[texture-xform-headless]` line. No rendered
image is produced and the log does not establish that the world map was
reached, so this is not evidence that the technique is unused. The browser
server and its game files were not used by that run.

After adding the optional trace, the offscreen Metal COUNT2 A/B and the earlier
FVF routing GPU A/B both passed again. `recomp/tests/texture-transform2.patch`
contains only the COUNT2 change against a recorder that already has the FVF
routing experiment; it excludes the trace and has not been applied to main.
A second isolated headless run stopped after 55 seconds and logged scripted
input through frame 1300; it likewise produced no COUNT2-state trace. The same
limitations on determining location from these headless logs apply.
The requested world-map browser trace was not performed in this session; the
local server on port 8011 was stopped. No new browser visual result is claimed.
