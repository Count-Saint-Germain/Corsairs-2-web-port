> Historical technical document: intermediate diagnostic runs were deleted. Their screenshots and example commands are unavailable; current instructions are in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md).

# D2: Which `.wav` / `.ogg` duplicate does the game read?

Date: 2026-11-12. Status: **code analysis completed; no live run was performed** (the task prohibited browser and gameplay runs).
Method: inspect scripts, INI files and aliases, `SoundService.dll` strings and disassembly (headless Ghidra, instruction listing only: the native decompiler was unavailable on this machine, so conclusions below are from disassembly, not decompilation); search all 46 images for byte strings; read the port's host code and documentation. Nothing was run and neither game data nor OPFS was modified.

## 1. Verdict: option (a)

For each of the 739 sounds present in both formats, the game reads **only `.wav`**. None of the 739 duplicate `.ogg` files is opened; `.ogg` is read only for music (`RESOURCE/Sounds/MUSIC/*.ogg`, 37 files without `.wav` siblings). Music must not be excluded and is unaffected by the rule.

The exclusion is **conditional**: an `.ogg` under `RESOURCE/Sounds` is omitted from the manifest, distribution and folder selection **only when a supplied `.wav` in the same folder is at least 45 bytes** (44-byte header plus at least one data byte). If the `.wav` is missing, empty or truncated to its header, the `.ogg` remains, so the rule does not discard that sound.

Savings on the actual game (names and sizes read from `game/`, without hashes): **739 files, 15,191,918 bytes ≈ 15.2 MB** (manifest 10,563 → 9,824 files; 2,366,232,575 → 2,351,040,657 bytes, −0.64%). This is small: most duplicate data is in `.wav` files (see §7); the duplicate `.ogg` files are the smaller copies.

## 2. Inventory (rechecked, including subdirectories with spaces)

| Item | Files | Size |
|---|---:|---:|
| All `.wav` | 970 | 119.36 MB |
| All `.ogg` | 776 | 64.28 MB |
| Base names with both formats | **739** | wav 89.04 MB + ogg 15.19 MB |
| `.wav` only | 231 | 30.32 MB (all `VOICE/*.wav`, copies of `VOICE/RUSSIAN`) |
| `.ogg` only | 37 | 49.08 MB (all `MUSIC`) |
| Other | 1 `dsstdfx.bin`, 5 `.sfk` | already excluded by extension |

The 739 pairs by directory: `VOICE/RUSSIAN` 231 (ogg 5.23 MB), `trep` 164 (3.42), `OBJECTS` 133 (2.19), `AMBIENT` 103 (1.97), `NATURE` 48 (1.81), `PEOPLE` 40 (0.32), `INTERFACE` 20 (0.25).

**Origin (important for the verdict):** the `.wav` files **do not come from the repack**. The unpacked repack (`<root>/game/RESOURCE/Sounds`) contains only 739 `.ogg` files (mtime 2011-01-16) and zero `.wav` files. It has no `MUSIC` directory: 37 music `.ogg` files are in `game/setup-1.bin` (7z, Copy method, 37 files, 49,083,812 bytes, exactly the “ogg only” total). All 970 `.wav` files in the working copy were created on 2026-11-05 from 21:17–21:21 with mode `0600` by `web-port/scripts/restore_russian_voice.mjs` (`ffmpeg` → canonical 44-byte PCM header; documented in the historical logs, since deleted). In all 739 pairs, `.wav` and `.ogg` have equal sample rates and channel counts and matching durations (median difference ≈ 3·10⁻⁷ s, maximum 0.031 s due to decoder padding). The `.wav` is a decoded copy of the `.ogg`, which is the original repack source (the 2011 repack compressed sound to ogg; the 2003 disc contained the `.wav` files referenced by scripts).

How much of this is done by the Windows repack installer (`decode.exe`, `depack.exe`, `7z.dll` are in the game root; `setup.exe` is Inno Setup 5.3.10) was **not checked**: the installer was neither run nor unpacked.

## 3. Code evidence

### 3.1 Names requested by the game (scripts, INI files and DLLs)

- The sound system receives an **alias** (`PlayStereoSound("rain")`, `Play3DSound("ball2bort", …)`, `SetMusic("music_gorod")`) or a **path containing `\`**. Aliases are defined in `RESOURCE/INI/ALIASES/*.ini` as `name = <path with extension>`.
- Of all **1,612** `name =` values in `ALIASES`, **1,573 end in `.wav`, 39 in `.ogg`, and none lack an extension**. All 39 `.ogg` values are `MUSIC\…` and none has a `.wav` sibling (checked against the filesystem). No literal `.ogg` refers to non-music files: `.ogg` appears in `PROGRAM` only in `SetMusic("music\Coridor.ogg")` (`mainmenu.c`), `loc.music = "enplav.ogg"` (`locations_init.c`, no file exists at that path, producing silence, outside this question), and `PlayStereoOGG("music_ship_dead" | "music_ship_victory" | "music_End_storm")`; all three aliases point into `MUSIC\`.
- In `sound_scheme.ini`, `ch =` / `ch_loop =` entries are alias keys or `….wav` paths.
- `.wav` in `PROGRAM`: only `PlaySound("interface\knock.wav")` three times. In the images: one literal `.wav` each in `animals.dll` (`chaika.wav`), `DIALOG.dll` (`interface\ok.wav`) and `Location.dll` (`OBJECTS\sgboom.wav`). A byte search for `.wav`/`.ogg`/`wav\0`/`ogg\0` and UTF-16 in all 45 `MODULES/*.dll` files and `ENGINE.exe` found **only those three `.wav` literals and no `.ogg`**.
- Of the 739 pairs, 492 have direct `….wav` references in INI/scripts. The other 247 (mostly `trep/*`, some `VOICE`, `OBJECTS`, `AMBIENT`, `interface`) have no literal `.wav` or `.ogg` reference and are not read, unless their names are constructed at runtime; no such construction was found in `PROGRAM` or DLL strings.

### 3.2 `SoundService.dll` behaviour (disassembly, addresses at preferred base `0x10000000`; port image at `0x00990000`)

- **Extensions are never supplied or replaced.** No `.wav`/`.ogg` string constants occur in the image; other strings include only `OggS`/`vorbis` (statically linked Vorbis decoder) and `Can`t recognize OGG file`. `FUN_10005210` (SoundPlay) takes a name; if it contains no `\` (`strchr(name,'\\')`), it looks up an alias in a 500-slot hash table and takes the alias name. It copies the sound path (`engine.ini [sound] sound path = resource\sounds\`, read at `0x10004cf4`…`0x10004d13`) and appends the name unchanged. No further name modification occurs.
- **The decoder is selected by the script's sound type, not the extension:** jump table `0x1000568c` by `type-1` (SOUND.H): 1 `SOUND_WAV_3D` → constructor `PCM3DSound` (`0x10002e40`), 2 `SOUND_MP3_STEREO` → `MP3StereoSound` (`0x10002a20`), 3 `SOUND_MP3_3D` → `MP33DSound` (`0x100025c0`), 4 `SOUND_WAV_STEREO` → `PCMStereoSound` (`0x10003580`). “MP3” is a legacy class name; the implementation uses Ogg Vorbis (`AMP3Coded.cpp`, `0x100013e0`). Only `SetMusic()` and `PlayStereoOGG()` (`sound.c`) set `SOUND_MP3_*`, so this is music only.
- **The PCM path reads a fixed-layout RIFF/WAVE:** `FUN_10001d40`/`FUN_10001db0` use `SetFilePointer` at `0x14` (18 format bytes) and `0x28` (data size), the classic 44-byte header, then read all data. An Ogg file named `.wav` will not work.
- **There is no fallback.** On open failure the PCM loader (`FUN_10002010`) returns false (`XOR AL,AL`) without searching for another file; `SoundPlay` returns 0. Missing `.wav` means silence, with no exception. **Opening Ogg music on failure throws a C++ exception** (`%s: Can`t open file` / `Can`t recognize OGG file`, `0x10001484`, `0x10001500`); SEH is not dispatched by the port, so the exception stops the process. This was observed for `RESOURCE/Sounds/music/Coridor.ogg` (historical diagnostic materials deleted). **Music `.ogg` files are therefore required and unaffected by the rule.**

### 3.3 Port host and recompiled translation

- `recomp/host/*.c`, `recomp/web/*.js|.mjs` and `recomp/runtime` contain no `.ogg`, `.wav`, `vorbis` or `stb_vorbis` references: **there is no Ogg decoder on the port host** and no mode to enable one. The recompiled guest `SoundService.dll` decodes music itself (`out_all/MODULES_SoundService_00*.c`; `f_00995210` = `FUN_10005210`, `_002.c` refers to `OggS` at `0x009bab7c`). The host (`dsound.c`) receives decoded PCM in DirectSound secondary buffers.
- Neither `host/kernel32.c` (file layer) nor `host/misc.c`/`core.c` rewrites sound filenames (searches for `ogg`/`wav` were empty; `kernel32.c` does not mention these extensions).

### 3.4 Logs

- Early `game/system.log` / `compile.log` (2026-11-05) contained `SETTING MUSIC: music\Coridor.ogg`, `PauseAllSounds`/`ResetSoundScheme`, but no `.wav` opens or `.ogg`/`.wav` open errors. Historical logs and diagnostics, since deleted, confirmed the `Coridor.ogg` open and sound-buffer creation. No sound-file-open trace (`[file] CreateFileA(...)`) exists in the saved logs: **the repository contains no direct run proving that `.wav` is read**. The verdict follows from code (§3.1–3.3), not logs.

## 4. Unproven points and limits

1. No live trace was recorded (forbidden by the task). “The game reads `.wav`” is inferred from code; §8 lists log lines that would confirm it.
2. For 247 pairs without literal references, “not read” follows from absent references in `PROGRAM`, INI and strings from 46 images. Runtime-generated names are theoretically possible, although none was found in `PROGRAM` or DLLs. This does not change the verdict: if such a file is read, it is read as `.wav` (§3.2: the extension comes from the alias/name without substitution; `.ogg` needs an `MP3` type scripts assign only to music).
3. This is disassembly, not decompilation. Because decompilation alone was not considered proof, conclusions were cross-checked against byte-string searches, INI files and filesystem data.
4. The DLLs contain three hard-coded `.wav` literals (`chaika.wav`, `ok.wav`, `sgboom.wav`); see §7.6.

## 5. Changes

| File | Change |
|---|---|
| `korsary2-next/port.json` | `files.exclude_if_sibling`: `{path: RESOURCE/Sounds, extension: .ogg, sibling_extension: .wav, min_sibling_bytes: 45}` |
| `korsary2-next/recomp/web/port-config.js` | Generated as by `tools/configure.mjs`: byte-identical to `configure.load()` output plus the same three lines (checked; it also matched before the change). `configure.mjs` was not run because it writes to `host/`; `configuration consistency tests` enforces equality. |
| `korsary2-next/recomp/web/gamefiles.py` | `parse_sibling_rules` validates rules and rejects chains/cycles so both copies cannot be removed; `redundant_siblings` returns a pure list of `(path, size)`; `game_files()` applies it in a second pass over accepted files. `make_dist.py` and `serve.py` use it without modifications. |
| `korsary2-next/recomp/web/save-protection.mjs` | New `dropSiblingDuplicates` export, implementing the same page rule; invalid or chained rules discard nothing. |
| `korsary2-next/recomp/web/port.js` | Only `importFromPicker`: calls `dropSiblingDuplicates` after `selectGameAssets`; `wanted()` was unchanged because a single path cannot reveal siblings. |
| `korsary2-next/recomp/tests/verify_dist.py` | Checks that `game/` and its manifest contain no `.ogg` with a supplied `.wav` sibling, independently of the packager; `sibling_rules_from_port_json` has a safe default. |
| Tests | `test_make_dist_coverage.mjs` (+4), `test_serve_path_safety.py` (+1), `test_verify_dist.py` (+2), `test_resync_preservation.mjs` (block 8), new `tests/test_sibling_duplicates.mjs`. |
| `docs/hosting.md` | Package composition section on `.ogg` beside `.wav`. |

Unaffected: `SAVE`/`SAVE_META`/`SAVE_TX`/`options` (the rule is limited to `RESOURCE/Sounds`; `selectGameAssets` and synchronization are unchanged), `missing-resource-preflight.mjs` (it checks only manifest files: excluded `.ogg` files are not required or marked missing; `required` contains neither `.wav` nor `.ogg`), `host/*.c`, `engine.dll`, `data1.dat` and historical diagnostic materials (deleted).

## 6. Tests

Historical results below were run from `korsary2-next/recomp` on 2026-11-12. The migrated Node packager suite command is run from the repository root:

- `node tests/test_resync_preservation.mjs` — PASS (block 8: manifest without `.ogg`; old `.ogg` files remain in OPFS, `.wav` and music remain, SAVE/SAVE_META/options untouched, sounds not re-downloaded).
- `node tests/test_missing_resource_preflight.mjs` — PASS (18 groups); `test_options_sync.mjs`, `test_plan_file_update.mjs`, `test_save_update_lock.mjs`, `test_storage_estimate.mjs` — PASS.
- `node tests/test_sibling_duplicates.mjs` — PASS (20 paths covering case, spaces in folder names, music without `.wav`, `.wav` in another folder, `.wav` shorter than a header, `Sounds2` and unrelated folders; the same table is run through Node `gamefiles.redundantSiblings` and compared; `port-config.js` == `port.json`; invalid rules retain everything).
- `node --test korsary2-next/recomp/tests/test_make_dist_coverage.mjs` — 16 Node tests (covering the historical 24 tests, including a full `buildDistribution()` run on a synthetic game, leaving the source byte-identical; the real `game/` test reads only names and sizes).
- `test_serve_path_safety.py` — 8 OK (`.ogg` → 404 for GET/HEAD/Range, `.wav` 200, manifest without `.ogg`); `test_verify_dist.py` — 21 OK; `test_video_serve.py` — 8 OK; `test_upload.py` — 14 OK; `verify_dist.py --selftest` — PASS; `test_dist_http_smoke.mjs` — OK.

No new distribution was built (disk constraints). The old diagnostic distribution (deleted; 10,575 files, 776 `.ogg` + 970 `.wav`, WMV included) would be **rejected** by the new `verify_dist.py` rule because it has 739 `.ogg` files beside `.wav`, as well as by the WMV rule; it would require rebuilding (R5).

## 7. Risks and caveats

1. **Small saving (15 MB).** Most redundancy is in `.wav`: 89.04 MB of `.wav` in 739 pairs was decoded from 15.19 MB of `.ogg` (≈ six times smaller), plus 291 groups of byte-identical `.wav` (≈ 39.3 MB extra: 231 copies from `VOICE/RUSSIAN` to `VOICE`, ≈ 30.3 MB; the game reads both paths, `VOICE\x.wav` from `sound_alias.ini` and `VOICE\Russian\x.wav` from `*.lng`/scripts; the rest is in `trep/*`). Alternatives include transfer compression (D1), content-addressed storage or generating `.wav` from `.ogg` on the client (−74 MB; requires a deterministic browser decoder, canonical 44-byte headers, time to process 970 files, and confirmation that audio matches). **Not implemented**; assess separately (D1/D2b).
2. **A fresh “clean” repack import is silent.** The actual repack contains no `.wav` (§2). Selecting an unchanged installation creates a manifest with only `.ogg`; the rule keeps them (no `.wav` sibling), but the game does not read them, so effects and voice are silent without a crash (§3.2). Reliable bring-your-own-files installation needs `.wav` restoration (currently the manual `restore_russian_voice.mjs` step). This defect predated D2 and was neither caused nor fixed by it.
3. **Music** (`MUSIC/*.ogg`): a missing file crashes the port (Ogg open exception, SEH not dispatched), unlike missing `.wav` (silence). The rule leaves music intact, but **preflight does not protect it** (`KNOWN_CRASH_PATHS` contains only `blade1/blade6`). Recommendation, not implemented because it was out of scope and changes `required`/preflight: add `RESOURCE/Sounds/MUSIC/Coridor.ogg` (hard-coded `SetMusic("music\Coridor.ogg")` in the main menu) to `files.required`/`KNOWN_CRASH_PATHS`.
4. **The `.wav` size condition** (≥ 45 bytes) protects against an empty or truncated header, not a corrupted larger file; manifest SHA and preflight verify/warn about `.wav` integrity.
5. **Existing installations:** duplicate `.ogg` files remain in OPFS (≈15 MB); nothing is removed (synchronization does not delete files outside the manifest; `docs/hosting.md` §5). A new manifest `version` causes normal revalidation; unchanged `.wav` files are not re-downloaded.
6. **Hard-coded `.wav` literals in DLLs:** `chaika.wav` (`animals.dll`; absent from `Sounds` and elsewhere, producing silence), `OBJECTS\sgboom.wav` and `interface\ok.wav` (`Location.dll`, `DIALOG.dll`; both have `.wav`+`.ogg` pairs and the `.wav` is read). A missing name is silent, not a crash, and unrelated to the rule.
7. **Missing references:** 493 `name =` values (383 unique) point to files absent on disk: the Russian voice set contains 231 lines while `VOICE\Eng_*/Dut_*/Fre_*` aliases expect more; there are original typos (`NATURE\foutain.wav`, `NATURE\widmill.wav`, `music_abordaz`). For PCM this means silence, as before the rule.

## 8. Measurements for a live agent (not performed)

Run with `PORT_LOG=1` (the host writes `[file] CreateFileA(<guest name> -> <host path>, disp N) = ok | <error>`, `kernel32.c:2343`), proceed through menu → new game → cabin → pier → town → sea combat, then:

1. `grep -i 'CreateFileA(resource.sounds' log | grep -i '\.ogg'` — expect **only** `MUSIC\…ogg` (especially `Coridor.ogg` in the menu). Any `.ogg` in `AMBIENT|OBJECTS|NATURE|PEOPLE|INTERFACE|trep|VOICE` disproves the verdict.
2. `grep -i 'CreateFileA(resource.sounds' log | grep -i '\.wav' | grep -v '= ok'` — lists missing `.wav` files (expect Russian lines `VOICE\Eng_*|Dut_*|Fre_*` and typos from §7.7; **none** of the 739 paired names should appear).
3. After installing the new distribution without duplicate `.ogg` files, listen for menu music, pier footsteps/waves/seagulls and combat cannon sounds; the number of opened `.wav` files should match before and after.
4. `?log` `[dsstats]`/mixer buffer counts should be unchanged from a full installation.

Rollback criterion: if sound disappears when duplicate `.ogg` files are absent, remove the rule from `port.json` (`exclude_if_sibling: []`) and regenerate `port-config.js` (`tools/configure.mjs`).

## 9. Findings outside D2

- `RESOURCE/Textures/Loading` contains 18 files; 137 Russian loading screens (≈ 71.8 MB) are in `Loading/Russian/` and **not copied up** (`sound_video_on.bat` copies them). Scripts request `loading\Tavern_01.tga` etc.; `DX8RENDER`/`ENGINE` contain no `Russian` substitution (string search), suggesting a cause of black loading screens. The same applies to `Textures/WorldMap/reload/Russian` (four files). `docs/asset-plan.md` (“nothing needs copying”) does not account for this. Check for failed `CreateFileA(resource.textures.loading…)` in the log. See `docs/language-audit-e0.md`.
