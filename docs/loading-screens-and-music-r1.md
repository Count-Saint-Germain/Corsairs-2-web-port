> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

# R1: protecting music `.ogg` files in preflight and `Textures/Loading/Russian` loading screens

Date: 2026-11-12. Status: **code and data analysis complete; no live run** (the task prohibited launching the browser and game;
ephemeral headless Chromium was used only for a synthetic OPFS preflight module test). Game data, `historical diagnostic materials (removed)`,
`engine.dll`/`data1.dat`, user saves and OPFS were not modified. Renderer and `host/*.c` were not touched. Follow-up to D2
(`docs/sound-duplicates-d2.md` §7.3, §9) and E0 (`docs/language-audit-e0.md`, “Loading screens” row).

## 1. Verdicts

| Question | Verdict | Evidence level |
|---|---|---|
| Can a missing music `.ogg` crash the port? | **Yes** | observed for `Coridor.ogg` (`historical diagnostic materials (removed)`); the other files follow the same code path (disassembler), but were not observed separately |
| Which music files are actually requested? | 24 of 37 (list in §2.2) | scripts `PROGRAM/sound.c`, `mainmenu.c`, `AIShip.c` + `music_alias.ini`; 8 files belong to aliases not referenced by scripts, 5 are not mentioned anywhere |
| Is music requested that is absent from the data? | **No**: all 32 alias names and `music\Coridor.ogg` exist on disk (case differs: `Main_Theme`/`Sea_battle01` versus `Main_theme`/`Sea_Battle01` — guest lookup is case-insensitive) | filesystem comparison; test `настоящая игра: KNOWN_MUSIC_PATHS == …` (“real game: KNOWN_MUSIC_PATHS == …”) |
| Are location loading screens not found by the engine? | **Confirmed by code and data**: 121 of 131 names requested by executable scripts exist **only** in `Loading/Russian/`; neither engine nor host substitutes `Russian` | `DX8RENDER` disassembly, strings in all images, scripts; **not visually verified** |
| What does the player see instead? | **Unknown**: code produces “Can't load texture”, a failure without exception, and an untextured rectangle (host empty slot = white texture); `historical log (removed)` mentions a “white loading screen” on an F4 transition, without establishing its cause | inference from code, no live test |
| File-set solution | Implemented: `files.relocate_if_absent` rule (§3.5), 128 files (67.1 MB, ≈29.8 MB gzip) published as `Loading/<name>` without a second copy | tests in §5 |

## 2. Music

### 2.1 Why a crash rather than silence

- Music is the only `.ogg` consumer: `SetMusic()` and `PlayStereoOGG()` in `PROGRAM/sound.c` set type `SOUND_MP3_STEREO`; other sounds use
  the PCM path and silently do not play when a file is missing (D2 §3.2).
- On failed Ogg open, `SoundService.dll` throws a C++ exception (`%s: Can't open file`, `Can't recognize OGG file`); SEH is not
  dispatched in the port, so the exception is fatal (`historical diagnostic materials (removed)`). **Observed** on startup without the `music` directory: “exception attempting to read
  `RESOURCE/Sounds/music/Coridor.ogg`”; after restoration from `setup-1.bin`, opening `Coridor.ogg` and creating a buffer were confirmed
  (`historical diagnostic materials (removed)`).
- The other files use the same code (`MP3StereoSound` → `AMP3Coded.cpp`; `FUN_10005210` has one `type-1` branch for all). An alias name is selected
  **randomly from all listed** (`f_009946b0`: weighted selection by probability sum), so a missing file from any alias crashes with some
  probability rather than deterministically.
- Caveat: in the Windows original, some C++ exceptions may have been caught by an in-game `catch` (`FUN_10005210` has an EH frame); in the port
  `catch` does not execute, so the port crashes where the original might have survived. For protection, this is irrelevant: the file must not be missing.

### 2.2 What is requested (scripts and aliases)

| Source | Names |
|---|---|
| Hard-coded: `INTERFACE/mainmenu.c:63` | `SetMusic("music\Coridor.ogg")` (main menu) |
| `sound.c` via `SetMusicAlarm`/`SetMusic` (locations and sea) | aliases `music_gorod`, `music_jungle`, `music_coridor`, `music_church`, `music_gubernator`, `music_shop`, `music_tavern`, `music_storm`, `music_spokplavanie`, `music_map`, `music_bitva`, `music_sea_battle` |
| `SEA_AI/AIShip.c:821,1276,1280` via `PlayStereoOGG` | `music_ship_dead`, `music_ship_victory`, `music_End_storm` |

Files for these aliases (**24**, 33.9 MB of 49.1 MB): `Bitva1, Bitva2, Cave_or_Dungeon_Walking, Church_Theme, Coridor, End_storm, Enplavanie, Gorod-1,
Governors_Theme, Gubernator, Jungle, Jungle_Shore_Exploration, Sailing01, Sea_Battle01–03, Ship_dead, Ship_victory01, Ship_victory03, Sobor,
Spokplavanie, Storm, Taverna, Town_Exploration02`.

The remainder (13 files): aliases `music_main_theme`, `music_final_theme`, `music_shipyard`, `music_enplavanie`, `music_abordage`, `music_victory`, `music_death` are
not called from `PROGRAM` or from strings in the 46 images (`Main_theme`, `March`, `Abordage`, `Board_&_Capture`, `Paluba`, `Sailing02`, `Death`, `Victori`);
`Gorod-2`, `Rolik`, `Spokplavaniye`, `YoHo_instrumental`, `YoHo_With_Vocals` are not mentioned anywhere.

Non-file pitfalls (not caught by preflight, not observed with the data):

- `SetMusic("music_abordaz")` in `SetSchemeForAbordage()` (`sound.c:235`): no such alias exists (typo). Disassembly shows an unknown name without `\` used as path
  `resource\sounds\music_abordaz`, likely causing the same exception, **but** the function is never called (dead code; searched `PROGRAM` and all images).
- `loc.music = "enplav.ogg"` and `Locations[n].music = "town.mp3"` (`locations_init.c:25`, `FalaiseDeFleur.c`): no image reads the `music` attribute
  (no `music` string in `Location.dll`); `SoundService` receives music only through `SetMusic`.
- `SetMusic(oldMusicName)` with empty `oldMusicName` (`Sound_OnAlarm`, `Sound_OnSeaAlarm`) — empty name; in practice `musicName` matches and the
  `name == musicName` branch returns earlier. Not tested live.

### 2.3 Changes

`korsary2-next/recomp/web/missing-resource-preflight.mjs`:

- `KNOWN_MUSIC_PATHS` — 24 files from §2.2 using their on-disk names. Added to “fatal” with `why: 'crash-music'` alongside `blade1/blade6`:
  absence, unreadability or a directory in place → `RES_MISSING`/`RES_UNREADABLE`/`RES_NOT_FILE` refusal (as for `blade1`) **also in `presence-only` mode** (without manifest,
  folder install) — the list is static. Refusal text: «Без этого музыкального файла игра аварийно завершается при открытии музыки (проверено для
  Coridor.ogg, остальные открываются тем же кодом)» (“Without this music file the game crashes when opening music; confirmed for Coridor.ogg, the others use the same code”).
- `CHECK_RULES` rule `{prefix: resource/sounds/music/, suffix: .ogg, label: 'music'}`: the other 13 files (and any other music) produce only a warning
  (when using a manifest). Music size is compared with the manifest, but **content is not read** (`sizeOnly`): otherwise ≈34 MB is read/hashed
  on every launch; with the real manifest, the plan grew from 116 to 153 files, while the same 114 files / 5.2 MB are hashed in ≈30–230 ms.
- Truncated/empty file: `RES_SIZE_MISMATCH` warning (a crash from an existing damaged Ogg has not been proven); same-size replacement is not caught
  (README caveat).
- `presence-only` without a manifest remains functional: `ENGINE.exe`, `required`, `blade1/blade6` and music are checked for presence; nothing else is planned.

Updated: `tests/test_missing_resource_preflight.mjs` (21 groups, +3), `historical diagnostic materials (removed)`,
`historical diagnostic materials (removed)` (“protected / unprotected” table).

### 2.4 Why not `files.required` in `port.json`

A `required` check during folder selection would reject a music-less install earlier, but `required` is shared across the port, changes `port-config.js` and
`verify_dist`, and duplicating the list of 24 files there is inconvenient. Preflight runs before runtime startup without side effects. If early folder-import refusal is needed,
add `RESOURCE/Sounds/MUSIC/Coridor.ogg` to `files.required` (D2 §7.3 recommendation) — not done.

### 2.5 Hazard caught by a separate test

`exclude_if_sibling` (D2) drops `.ogg` if a `.wav` is adjacent. `MUSIC` has no neighboring `.wav`, but adding one would remove music from the manifest and crash the
port. The test `настоящая игра: …` (“real game: …”) uses the real `gamefiles.game_files()` and requires all 37 `MUSIC` files and all 24 `KNOWN_MUSIC_PATHS` in the published set.

## 3. Loading screens

### 3.1 (a) What scripts and engine request

- The `fader` (`Location.dll`, `Fader.cpp`) receives an image via `FADER_PICTURE` with a script string: `loading\sea.tga` (`reload.c:194`, `sea.c:281,394`,
  `AISea.c:72`), `Locations[i].image` (`reload.c:202`; 143 `.image` assignments in `PROGRAM/Locations/**`, all literals of form `loading\X.tga`), `loading\load_rus.tga`/`new_game_rus.tga`
  (`seadogs.c:360-362, 597-599`, `LanguageGetLanguage()=="English"` selects the English pair; `language.ini` `defaultLanguage=russian`), `loading\save_game|lost_controller|low_storage|start_loading|options.tga`
  (`INTERFACE/interface.c:1056-1076`), `Loading\initialization.tga.tx` (`locations.c:38`, `SetReloadProgressBackImage`), `Loading\progress.tga` (string in `DX8RENDER.dll`).
  There are no dynamic names `"loading\" + …`.
- Total `loading\…` literals: 133 unique names. Two (`InkasHram.tga`, `my_image`) occur only in `PROGRAM/Locations/location_init.txt`, which is never loaded.
- INI: `RESOURCE/INI/*loading*` and interface INIs contain no `loading\` references.

### 3.2 (b) Where they are stored

| Category | Names | Examples |
|---|---|---|
| At the top level (`Loading/*.tga.tx`) | 10 | `initialization, load, load_rus, lost_controller, low_storage, new_game, new_game_rus, options, save_game, start_loading` + `progress` from DLL |
| **Only in `Loading/Russian/`** | **121** | `Sea`, `Boarding`, `Deck_01–03`, `Cabin`, `Tavern_01–03`, `Store_02–04`, `Shipyard_01–03`, `House_03–08`, `Fort_01–03`, `FF_*`, `Oxbay_*`, `Isla_Muelle_*`, `Khael_Roa_*`, `Conceicao_*`, … |
| Nowhere | 0 (2 only in dead `location_init.txt`) | `InkasHram`, `my_image` |

`Russian/` contains 137 files (≈69 MB), 9 share a name with top-level files (`Bgd`, `New_Game`, `Options`, `Save_Game`, `initialization`, `load`, `lost_controller`,
`low_storage`, `start_loading`); of these `initialization`, `low_storage`, `save_game`, `lost_controller` are byte-identical, while `Bgd`, `load`, `new_game`, `options`, `start_loading`
differ (top-level ones are English, checked for `start_loading`, `options`, `load`; “Russian” ones have Russian text: «Подождите, идет загрузка…» (“Please wait, loading…”)). `Textures/WorldMap/reload/Russian/` (4 files: `Battle`, `sea`, `Storm`, `Twister`)
~~**is not requested by anything**~~ — **W1 correction (2026-11-12): it is requested.** This search covered only `loading\…` literals and image strings; `PROGRAM/WorldMap/worldmap_reload.c` (included from `worldmap.c`) in `wdmReloadToSea()` sends
`FADER_PICTURE` with `WorldMap\reload\sea.tga` (`Battle`/`Storm`/`Twister` as appropriate) — the same `resource\textures\<name>.tx` rendering path as `loading\…`. Therefore a second `relocate_if_absent` rule (§4.1) was added; see `docs/english-layer-assets.md` §3.3.

File format: `.tga.tx`, 512×512, `D3DFMT_R5G6B5`, 24-byte header + 512 KB data; a sample was visually checked (script wrote to `scratchpad`; nothing was
written to the project): Russian location screens are full illustrations captioned «Таверна» (“Tavern”), «Море» (“Sea”), «Абордаж» (“Boarding”) and «Подождите, идет загрузка…» (“Please wait, loading…”).

### 3.3 (c) What happens if a file is missing

- `DX8RENDER` (`FUN_100036b0` = `f_006936b0`): the path is built using `resource\textures\%s.tx` (string `0x10033f68`) from the texture name **literally**; opened using the engine
  file service (`GENERIC_READ`, `OPEN_EXISTING`); on `-1` — trace `Can't load texture %s` (string `0x10033f50`), release slot, return failure. No exception.
- There is no language substitution anywhere: `Russian`/`\rus\` does not appear in any of the 46 images and `ENGINE.exe` (ASCII), or in `host/*.c`, `runtime`, `web/*` (except video bridge `videos/Russian/Invasion.mp4`
  and comments). `Fader` does not alter the path (`Fader.cpp` strings: only `tips\tips_%.4u.tga`).
- In the host a missing texture produces an empty slot, and `render_wgpu.c` substitutes `g_white` (without a pixel shader). Thus an untextured rectangle replaces the image — probably
  white or the vertex color; **the exact appearance is not established**.
- Repository logs: all saved `CreateFileA(resource\textures\LOADING\…)` traces (71+48+13+10 lines) cover only `PROGRESS`, `START_LOADING`, `NEW_GAME_RUS`, `LOAD_RUS`,
  i.e. menu → new game/load; no traces of location or sea transitions. `game/system.log` and `compile.log` (2026-11-05, 15 and 17 lines) are from an early run and do not concern textures.

### 3.4 (d) Previous evidence

- `historical diagnostic materials (removed)` (conventions table, “Loading screens” row) claims “the engine adds the language directory itself; 137 images exist only in `Loading/Russian/` on disk” —
  **without evidence, and code disproves it** (§3.3). Only file existence was checked, not opening.
- `docs/asset-plan.md:61`: “leave as-is in the port … nothing needs copying” is incorrect for `Textures/Loading` (`restore_russian_voice.mjs` was created for `VOICE`).
- `historical log (removed)`: “a white loading screen appeared” on F4 transition (cause not investigated; `RaiseException` also present). `historical diagnostic materials (removed)` and `docs/tutorial-check.md`
  do not describe the loading screen appearance: Oxbay → map → Douwesen → port transitions were confirmed logically, but images were not captured. User visual approval concerned the game overall;
  “approved appearance of location loading screens” is not recorded in the documents.

### 3.5 (e) How the original handled this

`sound_video_on.bat` (2003-11-09, in game root) and `sound_video_on.txt` («Перенос звуков, заставок, шрифтов и тп» (“Relocating sounds, splash screens, fonts, etc.”)) copy `VOICE\RUSSIAN\*` → `VOICE\`, `Textures\Loading\Russian\*` → `Textures\Loading\`,
`Textures\WorldMap\reload\Russian\*` → `Textures\WorldMap\reload\`, `VIDEOS\Russian\*` → `VIDEOS\` — specifically **copy over existing files** (Russian files replace same-named top-level files). `what_change.txt` («рус-анг версия» (“Russian-English version”),
July–August 2003) and `history.txt` do not mention this; **whether the installer ran `.bat`** (Inno Setup 5.3.10, `setup.exe`) was not checked (the packed script was not unpacked). In this distribution the `.bat`
was not run: top-level `Loading` has 17 files, and root `VOICE` was filled manually by a port script.

## 4. Solution: `files.relocate_if_absent`

### 4.1 Rule

`port.json`:

```json
"relocate_if_absent": [
  { "from": "RESOURCE/Textures/Loading/Russian", "to": "RESOURCE/Textures/Loading" }
]
```

A file **directly inside** `from` is published under `to` with the same name (and no longer under `from`) if `to` has no file or directory of the same name, case-insensitively. Left in place: files with occupied
names (9 files: the top-level file wins — **English `start_loading`/`options`/`load`/`new_game`/`Bgd` remain as the player saw them**, rather than being replaced with Russian as `.bat` would do), nested directories,
and the second of two files differing only by case. This is a move, not a copy: bytes are unchanged, no second set is downloaded or stored. Idempotent. Nothing is discarded or overwritten.
~~`WorldMap/reload/Russian` is unaffected (never requested).~~ W1 correction: a **second rule** was added for it (`RESOURCE/Textures/WorldMap/reload/Russian` → `RESOURCE/Textures/WorldMap/reload`, 4 files). Validator rejects `from == to`, `to` inside `from`, chains and unsafe paths.

Result on real data: 9824 files (same set as after D2), `Loading/` has 145 files (17 + 128 relocated, 67 111 936 B); 9 same-named files remain in `Loading/Russian/`.
**All 131 names requested by executable scripts are present in `Loading/`** (test checks real `PROGRAM`). D1 transfer size: 128 files 67.1 MB → ≈29.8 MB gzip (44%); relocation does not increase size.

### 4.2 Implementation (one solution, four places)

| Place | Change |
|---|---|
| `korsary2-next/port.json` | rule; `recomp/web/port-config.js` regenerated according to `tools/configure.mjs` logic (the tool itself was not run: it writes to `host/`); `configuration consistency tests` enforces byte equality |
| `recomp/web/gamefiles.py` | `parse_relocate_rules`, `relocations()` (pure function), third pass in `game_files()` after `exclude_if_sibling`; through `game_files`, the rule reaches `make_dist.py` (copies from original location under published name, `.gz` under published name), `serve.py` (`files`: published name → source; old `Russian/…` path returns 404), and manifest |
| `recomp/web/save-protection.mjs` + `port.js` (`importFromPicker`) | `relocateIfAbsent` — same decision for browser folder import (`dest` changes, bytes unchanged); the table is run through real Python |
| `recomp/tests/verify_dist.py` | manifest and `game/` must not contain `Loading/Russian/<name>` without a same-named file in `Loading/`; `--source-game` finds relocated file in old directory; defaults apply if `port.json` is unreadable or lacks the key |

`make_dist.py`, `serve.py` and `port.js` `wanted()` did not need changes: files are published using the “published path → source” mapping already in `game_files()`;
`wanted()` filters by original paths and is unaffected by the rule.

### 4.3 Compatibility

- **D1 (compression)**: `enc`/`csize` refer to the published path; `size`/`sha256` refer to decompressed content; `version` is independent of transfer method. Tests: `test_make_dist` (both `--compress`/`--no-compress`
  modes give the same `version`, `<published name>.gz` decompresses to original bytes, ordinary and compressed copies do not coexist), `test_compression_dist` (serve `--compress` under published name).
- **Players with installed games**: manifest version changes → normal resync; 128 new paths are downloaded (≈30 MB gzip, ≈67 MB decompressed); old `Loading/Russian/*` remain in OPFS as “extra”
  (resync deletes nothing, `docs/hosting.md` item 5): **+≈67 MB OPFS** for existing installations, 0 for new ones. `SAVE`, `SAVE_META`, `SAVE_TX`, `options` unaffected (`test_resync_preservation` §9).
- **Preflight**: it does not check loading screens (absence = untextured rectangle, not a crash).
- **Folder selection**: Russian screens reach `Textures/Loading/` from another game folder too; `required` unchanged.

## 5. Tests

All run from `korsary2-next/recomp` (Python with `-I`) and pass:

| Test | Result |
|---|---|
| Node: `test_missing_resource_preflight` | PASS, 21 groups (was 18; +music ×2, +comparison with aliases and real-game scripts; real dist: 153 files, 114 hashed) |
| Node: `test_resync_preservation` | PASS (+§9 Loading/Russian relocation on update) |
| Node: `test_game_transfer`, `test_storage_estimate`, `test_options_sync`, `test_plan_file_update`, `test_save_update_lock`, `test_sibling_duplicates` | PASS |
| Node: `test_relocate_if_absent` (new) | PASS: table, Python parity, idempotence and ordering, `port-config.js == port.json`, “page keeps more”, SAVE/options, real game folder (154 → 154 paths, 145 at top level, all requested names found) |
| Python: `test_make_dist` | OK, 28 tests (+3 relocation and rule validation, +1 on real game folder) |
| Python: `test_serve_path_safety` | OK, 9 (+1) |
| Python: `test_verify_dist` | OK, 24 (+3) |
| Python: `test_compression_dist` | OK, 20 (+1) |
| Python: `test_video_serve`, `test_upload` | OK (14 and 8) |
| Python: `test_dist_http_smoke` | OK, 1 skipped “no packed entries in this dist” (also in baseline before changes) |
| Additional: `verify_dist.py --selftest`, `historical diagnostic materials (removed)` (ephemeral Chromium, synthetic OPFS), `test-preflight.mjs`, `test_game_transfer_browser.mjs` | PASS |

**Mutation testing** (edit file, run targeted test, restore and verify file): preflight — 7 mutants killed (no `KNOWN_MUSIC` in fatal; `Coridor` omitted from list;
music warn-only; music size not checked; no `music` rule; music hash calculated; `presence-only` skips music); relocation — 8 mutants killed (no third pass; overwrite existing file;
both case variants moved; same in JS; `port.js` does not call `relocateIfAbsent`; `verify_dist` omits check; `--source-game` omits old directory; outdated `port-config.js`).

## 6. Risks and caveats

1. **Visual result not verified.** “Screens are not found” follows from code; their appearance before and after the change requires live testing (§7).
2. **Approved appearance changes where it was “empty”**: 121 screens show Russian illustrations instead of an untextured rectangle. Files players saw before (`start_loading`, `options`, `load*`, `new_game*`, `progress`) do not change.
   If Russian `start_loading`/`options` are desired as with `.bat`, that is a separate decision (replace top-level files with Russian; deliberately not done here).
3. **+≈67 MB OPFS for existing installs** (old `Russian/*` remain), +≈30 MB download; new installs do not grow. A new dist was not built (disk): `historical diagnostic materials (removed)` (154 `Loading*` entries, no relocated paths or compression)
   would be **rejected** by the new `verify_dist` rule — it must be rebuilt (R5), also due to D2 rules.
4. **Music list is static**: if scripts/aliases change, update `KNOWN_MUSIC_PATHS`; the real-game test fails on mismatch. Uncalled music aliases (8 files) only receive warnings.
5. **Random-choice music crash**: a missing file in a multi-name alias would not necessarily crash immediately; preflight blocks startup beforehand, so a player with an incomplete install cannot start (message asks for reinstall; no automatic recovery).
6. **Documents containing incorrect claims** (`historical diagnostic materials (removed)` §conventions, `docs/asset-plan.md:61`, `docs/language-audit-e0.md` — “`LanguageGetLanguage()` is never called” is wrong: called in `seadogs.c:359, 596`) were not changed.
7. **Not checked**: whether the installer runs `sound_video_on.bat`; `fader` behavior without a texture in all branches; effect of `texture_degradation`/texture cache on relocated files.
8. **Deliberately not done**: ~~`WorldMap/reload/Russian` (never requested)~~ (done in W1, see §3.2), `VIDEOS/Russian` (video via HTTP, separate `videos/Russian/Invasion.mp4` path), `restore_russian_voice.mjs`-like `VOICE/RUSSIAN` relocation (already done by script, D2 §2).

## 7. Live check (for another agent)

Run with `PORT_LOG=1` from a new dist. From the repository root, the local development server is `node korsary2-next/recomp/web/serve.mjs --game korsary2-next/game`; its manifest publishes the relocated paths.

1. New game → cabin → Oxbay pier → any building (tavern/shop/shipyard) → town → port → sea → landing → boarding (if available). For each transition:
   `grep -i 'CreateFileA(resource.textures.loading' log` — expected `… -> …/Loading/<Name>.tga.tx … = ok`; **any `LOADING\<name>` line with an error** rejects the verdict (name from §3.2 not found).
2. `grep -i "Can't load texture" log`/system log — expected empty for `LOADING\…` names.
3. Visually: on transition to tavern — «Таверна» (“Tavern”) image with «Подождите, идет загрузка…» (“Please wait, loading…”) (previously empty/white/black frame); on sea transition — «Море» (“Sea”). Compare with pre-fix `?log` screenshot (old dist).
4. Menu → «Новая игра» (“New game”) and «Загрузить» (“Load”): still `NEW_GAME_RUS`/`LOAD_RUS` from `Loading/` (unchanged); first screen (`START_LOADING`) remains English.
5. Music: menu (`Coridor.ogg`), port/town/tavern/church/jungle/dungeon/sea/storm/combat — log `CreateFileA(resource.sounds.music…)` and `SETTING MUSIC: …`;
   no `MUSIC\*.ogg` open errors. Deleting/renaming any of the 24 OPFS files before startup should refuse with «Игра не запущена: … RES_MISSING» (“Game not started: … RES_MISSING”) before runtime startup.
6. Previously installed game: after page update ≈128 files downloaded, `SAVE`, `options` and slots remain; OPFS retains `Loading/Russian/` (extra).

## 8. For project documents (paragraphs)

- **ROADMAP / BUGFIX_PLAN (R1):** music `.ogg` (24 files requested by scripts) is now protected by preflight like `blade1/blade6`: missing → `RES_MISSING` refusal before launch (observed for `Coridor.ogg`, others use same code path);
  other 13 — warning; size checked, content not. Engine does not find location loading screens (121 names from `Loading/Russian/`; no language substitution, confirmed by `DX8RENDER` code); `files.relocate_if_absent` publishes
  128 files as `Textures/Loading/<name>` without a second copy; not visually checked, live verification required (§7).
- **PORTING_LOG:** R1 — code/data analysis; two tests of new rule and music list checked against the real game; no live run.
- **asset-plan.md / historical diagnostic materials (removed):** correct “the engine adds the language directory itself” and “nothing needs copying” claims for `Textures/Loading/Russian`.
