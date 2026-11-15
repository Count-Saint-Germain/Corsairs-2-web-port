> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

> **Status as of 2026-11-12:** the size tables (739 `.ogg`), the ≈ 1160 MB estimate, and the controls table (F3, Space to fire) are outdated: `Sounds` contains 970 `.wav` + 776 `.ogg`, the manifest contains 9824 files / 2351 MB, gzip-6 ≈ 1223 MB, and firing uses the left mouse button. See `historical log (removed)`, §3.6.

> **Correction 2026-11-12:** “nothing needs copying” (line ~61) is incorrect for `Textures/Loading/Russian`: the engine does not substitute the language directory (`docs/loading-screens-and-music-r1.md`). A `files.relocate_if_absent` rule was added.

> **Outdated (2026-11-12):** §2.2 assumes “only two videos are launched”. Reverse engineering identified 12 names and the video bridge was retargeted — see `historical diagnostic materials (removed)` and the top of `historical log (removed)`.

# Asset plan — Corsairs 2 / Pirates of the Caribbean (Storm engine) → WASM

Date: 2026-11-04. Source: `game/` (Repack 1C, v1.03). All figures are actual measurements.
Related documents: `docs/bringup-notes.md` (§3 — DirectShow→DDraw AVI in XINTERFACE.dll), `../PORT_SPECIFICATION.md`.

## 1. Asset inventory

### 1.1 Top-level sizes (du -sk)

| Directory | Size | Files | Notes |
|---|---|---|---|
| RESOURCE/Textures | 1 060 MB | ~1 780 | `.tx` = proprietary container with DXTn inside (see 1.3) |
| RESOURCE/MODELS | 912 MB | ~5 400 | `.gm` (geometry) + `.col` (collision) |
| RESOURCE/VIDEOS | 119 MB | 12 | all `.wmv` (ASF/WMV2/WMAv2), 640×384 |
| RESOURCE/animation | 108 MB | 291 | `.an` (data) + `.ani` (text index) |
| RESOURCE/Sounds | 16 MB | 745 | 739 `.ogg` (Vorbis), 1 `dsstdfx.bin` |
| RESOURCE/foam | 6.4 MB | 70 | `.ini` + `.zap` (foam at the waterline) |
| RESOURCE/INI | 0.8 MB | 105 | ini + text (CP1251) |
| RESOURCE/QUESTSTEXT | 0.1 MB | 1 | quests_texts.txt |
| PROGRAM | 7.6 MB | ~470 | Storm scripts (CP1251/ASCII C-like language) |
| MODULES | 5.3 MB | 45 DLL | all export `DMAInterface` |
| SAVE | 0 | 0 | empty directory; the engine writes saves here |
| **Total game/** | **2 294.7 MB** | | including ~61 MB of StarForce/repack junk in the root |

RESOURCE = 2 221 MB (du). The complete include set (PROGRAM+MODULES+RESOURCE+SAVE+engine.ini+options), by sum of file bytes = **2 319 680 617 B = 2 212.2 MB**.

### 1.2 Largest subdirectories/files

- `MODELS/Locations/*` dominate: `Town_Greenford/Exit/grexit.gm` 12.5 MB, `Jungle_1/jungle01.gm` 11.6 MB, towns 8–12 MB each (Conceicao, Douwesen, Redmond, FalaiseDeFleur…).
- `Textures/lighting/{day,evening,mn,storm}/...` — the same location texture ×4 lighting variants, multiplying storage.
- `Textures/*.tx` — 1 707 files, 956 MB total; `island_isla` and loading screens are 2–8 MB each.
- `animation/*.an` — 143 files, 107 MB (character skeletal animations).
- Largest individual files: 3 videos (28.7 / 24.7 / 21.7 MB) and 5 `.gm` (9–12 MB).

### 1.3 Format breakdown (extension, count, size, magic)

| Ext. | Count | Size | Format (magic) |
|---|---|---|---|
| `.tx` | 1 707 | 956 MB | proprietary Storm container: 16-byte header (version, width, height, mips) + fourcc `DXT1/DXT3/DXT5` + DDS-like DXTn data without a DDS header. The DX8RENDER host shim must already decode DXTn for WebGPU |
| `.gm` | 2 053 | 591 MB | proprietary binary: ASCII version `"50.1\0"` + binary blocks (vertices/locators) |
| `.col` | 3 387 | 130 MB | binary collision models |
| `.wmv` | 12 | 119 MB | ASF container, **WMV2 (WMV8)** video, **WMAv2 (WMA8)** audio, 640×384 — see §2 |
| `.an` | 143 | 107 MB | binary animations |
| `.ptc` | 136 | 39 MB | ASCII magic `PTC    1.01` + binary data (particles) |
| `.ogg` | 739 | 14 MB | standard Ogg Vorbis (played natively by the browser) |
| `.grs` | 64 | 15 MB | magic `Grs1.00` (grass) |
| `.zap` | 36 | 7 MB | binary, structured like a `.tx` header (compressed foam texture) |
| `.ini` | 105 | 0.5 MB | CP1251 text |
| `.ani` | 148 | 0.5 MB | text: `animation = …` (index to `.an`) |
| `.qch` | 7 | 9.5 MB | binary (quest effects?) |
| `.tga` | 10 | 0.4 MB | raw TGA |
| `.txt`/`.atg`/`.lng` | 40 | ~0.2 MB | CP1251 text |
| `.sfk` | 5 | ~0 | **Sound Forge junk (peak files) — exclude** |
| `.xbx` | 2 | ~0 | `XPR0` — Xbox port artifacts (options.xbx etc.) — can be excluded |
| `.old`, `.bin` | 2 | ~0 | dialog.old (junk), dsstdfx.bin (needed for DirectSound effects) |

Text is **CP1251** (QUESTSTEXT/quests_texts.txt: `d1ee…` = «Сооб…» (the start of a Russian word); `options`, PROGRAM/*.c, RESOURCE/INI/TEXTS/*). Port: convert to UTF-8 during packaging or decode in the host (guest file reads use the `CreateFileA/ReadFile` shim; supplying UTF-8 and patching `CharToOem` paths may be simpler… see WORK ITEM).

`sound_video_on.bat` shows that the 1C repack stores Russian content in `*/Russian/` subfolders (VOICE/RUSSIAN, Textures/Loading/Russian, Textures/WorldMap/reload/Russian, VIDEOS/Russian), which the batch file copies over the main files. Leave as-is in the port (Russian is already the `language.ini` default); nothing needs copying.

### 1.4 What can be excluded entirely

- game/ root: `engine.dll` (StarForce, 3.9 MB), `data1.dat` (StarForce, 6.5 MB), `decode.exe`, `depack.exe`, `7z.dll`, `setup-1.bin` (49 MB — repack installer), `Config.exe`, `Soft/` (0.3 MB) — ~61 MB total. Confirmed in bringup-notes §2/§5: there are no references to them.
- `RESOURCE/**/*.sfk` (5 files, 0 MB) — audio editor junk.
- 10 of 12 `.wmv` files **are not referenced** by scripts, INIs, or ENGINE.exe/XINTERFACE.dll strings (checked with `strings`): leftover cutscenes. Keep them — after conversion they total only 39 MB and load on demand.
- For savings (Phase 4, cautiously): the ×4 lighting textures duplicate locations — potentially −30% Textures; `.sfk` and Xbox `*.xbx`.

## 2. Web video pipeline

### 2.1 Conversion results (completed)

Script: `web-port/scripts/convert_videos.sh` (idempotent: skips an MP4 newer than its source; recursive under VIDEOS/). Output: `web-port/videos-web/`. All 12 files: ASF/WMV2+WMAv2 → **H.264 (libx264 CRF23 preset medium, yuv420p) + AAC 96k, `+faststart`**, retaining 640×384 resolution. Native FFmpeg decoders decoded the codecs without failures. All 12 videos **have an audio track** (WMAv2); none are silent.

| Source | MB | → MP4 | MB | Duration, s |
|---|---|---|---|---|
| Artefact.wmv | 3.5 | Artefact.mp4 | 1.7 | 12.0 |
| BlackPearl.wmv | 3.9 | BlackPearl.mp4 | 1.2 | 14.3 |
| Blaze_land_dead.wmv | 3.2 | Blaze_land_dead.mp4 | 1.4 | 12.6 |
| Blaze_mutiny_dead.wmv | 3.1 | Blaze_mutiny_dead.mp4 | 0.5 | 12.0 |
| Ending.wmv | 21.7 | Ending.mp4 | 6.5 | 75.0 |
| Idol.wmv | 3.3 | Idol.mp4 | 1.1 | 10.9 |
| Russian/Invasion.wmv | 24.7 | Russian/Invasion.mp4 | 8.7 | 83.2 |
| Skeleton_on_beach.wmv | 3.2 | Skeleton_on_beach.mp4 | 1.3 | 12.6 |
| Storm.wmv | 3.9 | Storm.mp4 | 1.8 | 14.0 |
| Temple.wmv | 16.2 | Temple.mp4 | 5.5 | 56.1 |
| Trailer.wmv | 28.7 | Trailer.mp4 | 8.5 | 96.2 |
| Undersea.wmv | 3.2 | Undersea.mp4 | 0.8 | 12.0 |
| **Total** | **118.7** | | **39.0** | −67% |

Names are 1:1 (including the `Russian/` subfolder): `<name>.wmv` → `<name>.mp4`.

### 2.2 What actually launches them (observed)

- Scripts launch only 2: `StartPostVideo("credits",1)` (mainmenu.c:223 — `credits.wmv` is **absent** on disk; the engine must handle this correctly) and `StartPostVideo("trailer",1)` (mainmenu.c:275 — the menu attract mode; `Trailer.wmv` exists; Windows searches case-insensitively).
- The other 10 are not referenced anywhere (DLL/EXE/INI/script strings are clear). Cutscenes (Ending, Temple, Idol…) are probably cut content.
- XINTERFACE.dll strings: `CAviPlayer, iVideo, midVideo, videoTexture, videoName, videoFile, videoToBack, VIDEORECTANGLE, resource\videos`.

### 2.3 Integration design (for the bring-up agent; no code)

Guest AVI/DirectShow path in XINTERFACE.dll: DirectShow `AMMultiMediaStream` → `DirectDrawMediaStream` → `DirectDrawCreate`/surface → upload to the D3D texture `videoTexture`, with the interface drawn on top. Proposal:

- **Host AVI/DirectShow stub** (shim layer, `ole32`+`ddraw` level): all `IAMMultiMediaStream`/`IDirectDraw*` methods return `S_OK`/empty surfaces. On “opening” `resource\videos\<name>.wmv`, the host in the **web build** publishes `play_video { name }` (1:1 converted filename: `Russian/Invasion` → `videos-web/Russian/Invasion.mp4`); guest texture rendering then uses the last decoded frame each frame: natively, copy the frame into the texture (real decoding is possible); on the web, draw `<video>` into a WebGL texture through `texSubImage2D(videoEl)` or composite over the canvas (simpler: a `<video>` layer under the WebGL canvas with a transparent interface background, as the `videoToBack` flag implies).
- **`EVENT_END_VIDEO`**: the host sends the guest event when `<video>` receives `ended` (or after a timeout if the file is missing — see `credits`).
- **Open failures**: if `videos-web/<name>.mp4` is absent (as with `credits`), the stub returns success, immediately emits `EVENT_END_VIDEO`, and logs a warning. The game must not hang on the attract screen.
- **Bring-up hook**: find the XINTERFACE.dll function owning the strings `Video Error!!! Can't create interface AMMultiMediaStream` and `resource\videos` (`CAviPlayer::Open/Play` pseudocode); intercept `CoCreateInstance(CLSID_AMMultiMediaStream)` and `DirectDrawCreate` in the stub — WORK ITEM No. 1 for the bring-up agent. The native stub can silently skip video or decode WMV with the ffmpeg library; “skip silently + immediate end event” is sufficient for now.
- Note: `<video>` requires an HTTP(S) source or blob; in the OPFS model the file is copied from OPFS to a blob URL on first request.

## 3. Packaging proposal (port.json — NOT applied; proposal only)

```jsonc
"files": {
  "include": [
    "PROGRAM",      // engine scripts (seadogs.c and everything else)
    "MODULES",      // all 45 DLLs MUST be files: the engine scans the directory with FindFirstFileA("*.dll")
    "RESOURCE",     // INI, MODELS, Textures, Sounds, VIDEOS, animation, foam, QUESTSTEXT
    "SAVE",         // empty, but the engine writes saves here — the directory must exist
    "engine.ini",
    "options"
  ],
  "required": [
    "engine.ini",
    "options",
    "PROGRAM/seadogs.c",
    "PROGRAM/CONTROLS/controls.c",
    "PROGRAM/CONTROLS/init_pc.c",
    "MODULES/XINTERFACE.dll",
    "MODULES/DX8RENDER.dll",
    "MODULES/SOUND.dll",
    "MODULES/PCS_CONTROLS.dll",
    "RESOURCE/INI/TEXTS/language.ini"
  ]
  // exclude — the entire root except the items listed above: engine.dll, data1.dat (StarForce),
  // decode/depack/Config.exe, 7z.dll, setup-1.bin, Soft/, sound_video_on.*
}
```

Browser build payload estimate:

- Raw include set: **2 212.2 MB** (2 319 680 617 B).
- gzip -9 (measured on content): tar stream with a shared dictionary = **1 173 729 254 B = 1 119.4 MB**; per-file (realistic for OPFS/HTTP storage) = **1 175 913 734 B = 1 121.4 MB**. Total **~50.7% of raw** (−47%).
- Note: DXTn data in `.tx` and binary `.gm`/`.col` compress moderately (already quantized); text (PROGRAM/INI/QUESTSTEXT) and `.an` compress well. Brotli would save another ~5–10%; QOI/KTX2 texture transcoding is Phase 4.
- Video is counted separately: +39.0 MB MP4 (outside the include set; served by the page on demand).
- Audio: 14.3 MB OGG Vorbis — played as-is by the browser (DirectSound → WebAudio shim).

## 4. Controls

Source of truth: `PROGRAM/CONTROLS/init_pc.c` (defaults) + `options` (effective bindings, applied over defaults by the engine). Mouse: VK_LBUTTON=left, VK_RBUTTON=right, VK_MBUTTON=middle. Keyboard codes are VK_*.

Effective defaults (from `options`):

| Mode | Action | Key |
|---|---|---|
| Land (PrimaryLand) | Look/turn camera | mouse |
| | Walk forward | **left mouse** |
| | Backward | **right mouse** |
| | (old init_pc.c default: middle mouse backward) | |
| | Run | Shift |
| | Action/activate | left mouse/Space |
| | Change camera (ChrCamCameraSwitch) | Tab |
| | Combat mode | E |
| | Activate combat interface | Enter |
| | Fast command (BIFastCommand) | Space |
| Sea, third person (Sailing3Pers) | Camera forward/back | left / right mouse |
| | Turn left/right | A / D |
| | Raise/lower sails | W / S |
| | Fire | left mouse (in options; Space in init_pc.c) |
| | Change camera | Tab |
| | Minimap +/− | E / F |
| | Combat interface | Enter, arrows, Esc |
| | Change ammunition | 1/2/3/4 (cannonballs/grapeshot/chain shot/bombs) |
| Sea, first person (Sailing1Pers) | Camera forward/back | right / middle mouse |
| | Telescope | Ctrl (press/release) |
| | Fire/turn/sails | as in third person |
| Combat (FightModeControls) | Attack | left mouse |
| | Block | Ctrl |
| | Lunge (recoil) | Z |
| | Fire pistol | Q |
| | Toggle combat mode | E |
| | Run | Shift |
| | Forward/back | right / middle mouse |
| World map (WorldMapControls) | Move/turn | left/right mouse, A/D, W/S |
| | Skip encounter | B |
| | Cancel/exit | Space, Tab |
| Interface/dialogs | Main menu | F1 (double Esc) |
| | Game interface | F2 |
| | Fast command | F3 |
| | Debug (boal) | F11 / F12 |
| | Potion | C |
| | Time acceleration | R (+/− numeric keys faster/slower) |
| | Dialog: action/scroll | Space, ↑/↓, PgUp/PgDn, Esc |
| | Menu: navigation | Enter, Backspace, Esc, arrows |

Remapping groups (in game, through options UI): `Sailing1Pers, Sailing3Pers, PrimaryLand, FightModeControls`.

Proposed port.json (originally Russian, one line):

```jsonc
"controls": "Mouse: left/right — move/camera; A/D — turn, W/S — sails, Space/left — fire and action, E/F — minimap, Tab — camera, Shift — run, E — combat, Ctrl — block/telescope, Q — pistol, Z — lunge, 1-4 — ammunition, Enter/Esc/F1/F2/F3 — interface, R — time, B — skip encounter on the map"
```

## 5. Download planning figures (summary)

| Component | Raw | Compressed (gzip -9, measured) |
|---|---|---|
| Include set (PROGRAM+MODULES+RESOURCE+SAVE+ini+options) | 2 212.2 MB | **1 119.4 MB** (tar stream) / **1 121.4 MB** (per file) |
| Video (MP4, already H.264, separate) | 39.0 MB | ~39 MB (recompression is pointless) |
| **Total browser payload** | **2 251 MB** | **~1 160 MB** |
| Excluded (StarForce/repack) | ~61 MB | — |

WORK ITEMs for the bring-up agent:
1. Find `CAviPlayer::Open/Play` in XINTERFACE.dll (strings `Video Error!!!…`, `resource\videos`) — the video stub point (§2.3).
2. Encoding: decide where to convert CP1251→UTF-8 (packaging vs ReadFile/TextOut shim); `language.ini` selects `russian`.
3. `credits.wmv` is absent — verify that the attract menu does not hang (the stub must immediately send EVENT_END_VIDEO).
