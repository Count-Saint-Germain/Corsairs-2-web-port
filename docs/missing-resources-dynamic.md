> Historical technical document: intermediate diagnostic runs were deleted. Their screenshots and example commands are unavailable; current instructions are in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md).

# Missing resources: static missing-reference inventory, dynamic verification and preflight expansion

Date: 2026-11-12. Task: K4 recommendation (historical diagnostic materials, deleted, section 6): keep SEH dispatch disabled and expand preflight based on dynamic tests. Neither the game nor browser was run visually; original game data, `engine.dll`/`data1.dat`, user saves and OPFS were not modified. All game runs used the standard headless Node build (`recomp/build_web/node`, **not** rebuilt) against APFS clones of the game directory (`cp -Rc`); each experiment's clone was removed afterwards. Ephemeral headless Chromium was used only for the module's synthetic OPFS test.

## 1. Findings

| Question | Finding | Evidence |
|---|---|---|
| Does any missing `.gm` crash the port? | **Yes, any** (Items, Ammo, Characters, Heads, Locations, seagull, island locators): `RaiseException e06d7363` from `0x006e4697`, terminal trap | **Dynamic**: 18 different files (13 startup files and five names absent from the original), no exceptions (section 4). |
| Does an invalid `.gm` header (empty, garbage) crash the port? | **Yes**, the same trap; a file of exactly 72 bytes without data gives a different “memory access out of bounds” trap. | **Dynamic** (M08, M09, M10, G05) and `f_006e1d70` code. |
| Does GEOMETRY's second throw site (`f_006e1d70`) check the header? | **Confirmed**: the first word of the 0x48-byte header must be `0x312e3035` (ASCII “50.1”), otherwise “invalid version”. | Generated code `out_all/MODULES_GEOMETRY_000.c`, `GEOMETRY.dll` strings (section 3), experiments M08/M10. |
| Does truncating `.gm` after the header crash the port? | **Not proven**: the game survived `blade1.gm` at 25%, 75% and 99%, and `bocman3.gm` at 50%. | Dynamic (G01–G04); accidental loader behaviour, not a guarantee. |
| Do missing textures (including portraits and loading screens), `.wav`, `.an/.ani`, `.ptc` or INI files crash the port? | **No**: a message appears in `system.log` and the game continues. | Dynamic (T01–T06, P01, S03–S05, A01–A03, H01–H03, M12, I01–I06). |
| Does missing `.ogg` music crash the port? | **Yes**, confirmed for **two** files (`Coridor.ogg`, `Gubernator.ogg`); raise site `0x0099839b` (SoundService), not GEOMETRY. | Dynamic (S01, S02). |
| References to files absent from the original installation (“40 references”) | Now **11 models** (10 dead, one conditionally reachable), 9 head animations, 10 portraits, 16 textures and 148 sounds; only a requested model crashes the port. | Static (section 2) and dynamic tests of real names (X01, X03–X06). |
| Is SEH dispatch needed? | **No** for known cases; leave disabled (section 8). | — |

## 2. Static missing-reference inventory

Tool: `korsary2-next/tools/resource-audit/audit_refs.mjs` (Node.js, read-only; run `node korsary2-next/tools/resource-audit/audit_refs.mjs --game korsary2-next/game`, ≈20 s; `--no-textures` ≈0.6 s). The file universe is **the published port set** (`web/gamefiles.game_files`: excludes `.sfk/.xbx`, `RESOURCE/VIDEOS`, `.ogg` beside `.wav`; moves `Loading/Russian` → `Loading`), not the raw directory; preflight checks this same set. Names are case-insensitive as in the guest. Textures use `X.tx` or raw `X`; `.gm` textures are searched under `Textures/<model path>/`, `Textures/<first component>/`, the root and, for locations, `Textures/lighting/{day,evening,mn,storm}/<path>/`. A head shares the body's texture (`Heads/h_bocman3.gm` → `Characters/BOCMAN3`, trace). Script comments are stripped; encoding is cp1251.

Reference sources: `PROGRAM/**` scripts (literal and computed character model families `man1–6`, `skel1–4`, `soldier_<nation>2–5`, `pirat2–5`, `offic_<nation>`, `boardingModel`; heads `h_` + model and explicit `headModel`; item `itm.model` and held weapons `Ammo/<model>`; location scene items `lab3.items.b_1.model`; ships `refShip.Name`; location parts `Locations[n].models.*` with `filespath`, `.ptc/.grs`, loading screens; islands and forts; `LowCharacters`; portraits `FaceId`; animations `model.animation` and `animation = X.an` inside `.ani`; head animations `animation/Heads/<h>.ani`), sound and music alias INIs, and `*.tga` strings inside `.gm`.

References checked: `.gm` 1,023; `.ptc` 136; `.grs` 64; `.ani` 144; `.an` 131; sound 456; music 32; portraits 106; textures 137. **194 are missing** (all classified; `unclassified` = 0):

| Class | Count | Reachability | Details |
|---|---:|---|---|
| `.gm` models | 11 | See below | `Characters/none.gm`, `Heads/capitan.gm`, `h_none.gm`, `h_Monkey.gm`, `h_mummy.gm`, `h_skel1–4.gm`, `Ships/Fort/Fort.gm`: **dead** (10); `Heads/h_offic_hol.gm`: **conditionally reachable**. |
| Head animations | 9 | Dead | `animation/Heads/` for those same absent heads. |
| Portraits | 10 | Cosmetic | `PORTRAITS/{64,256}/face_47–51.tga.tx` (FaceId of `Offic_*` models); missing texture does not crash (P01). |
| Textures inside `.gm` | 16 | Cosmetic | `yacht.tga` (Yacht1/2, no references), dead heads `OfGolland`, `Satanist1/2`, world map (`compass`, `DAY`, `Fort1`, `highlight`, `numbers`, `sails_shiplet`, `SPHETE`), `light/white`, `jungle_land_09`, `sh03_envday` (Pirate_House), `WaterBlend` (Douwesen waterfall). |
| Alias sounds | 148 | Cosmetic | 145 voice files `VOICE/*.wav` (`Dut_*`, `Eng_*`, `Fre_*`, `Ita_*`, `Por_*`) and three effects (`foutain`, `widmill`, `hit_toground`): silence (S03–S05). |

Model classification (manual code analysis; references are `PROGRAM` files):

| File | Reachability | Basis |
|---|---|---|
| `Characters/none.gm`, `Heads/h_none.gm`, `Heads/capitan.gm` | Dead defaults | `ch.model = "none"`, `ch.headModel = "capitan"` for empty `Characters[0..999]` slots (`characters_init.c:34, 55`); active NPCs overwrite the head with `"h_"+model` (`characters_init.c:297`, `LAi_utils.c:340`). Real names were tested dynamically: `none.gm` (X04) and `capitan.gm` (X05) **crash the port if requested**. |
| `Heads/h_Monkey.gm`, `h_mummy.gm` | Dead | Monsters in `LandEncounters/LEnc_monsters.c`; heads load only in dialogue (M04: `h_bocman3` at frame 660; the player head does not load); monsters have no dialogues. Requesting `h_Monkey` crashes (X06). |
| `Heads/h_skel1–4.gm` | Dead | `skel1` is the player model in the finale (`quests_reaction.c:6536`) and a monster model; the player head is not loaded in dialogue. A request crashes (X03). |
| `Ships/Fort/Fort.gm` | Dead (code; not dynamically tested) | `AIFort.c` builds forts from island models; the SHIP_FORT ship model is never created (`AIShip.c:167`, `AIFort.c:344`); the headless scenario does not reach sea. |
| **`Heads/h_offic_hol.gm`** | **Conditionally reachable (new finding)** | `SelectSoldierModelByNation(.., "Officer")` for the Dutch nation returns `offic_hol` (body `Offic_hol.gm` exists), `headModel = "h_offic_hol"` (`Dialog_func.c:661, 682, 703, 808–840`); `Douwesen` is the only island with `smuggling_nation = HOLLAND` (`Islands_init.c:376`): smuggling → coast guard (`SetCoastalGuardPursuit`, `both_reaction.c:1631`, group `Coastal_Guards`, captains `Coastal_Captain01–03`) → captain dialogue → `h_offic_hol.gm` fails to open → `.PAD`. Substituting the actual name confirmed the mechanism (X01, trap at frame 660); substituting an existing head removes the trap (X02). The previous audit missed it because `SelectSoldierModelByNation` was not analyzed. |

Changes from the deleted historical diagnostic materials (6,585 references, “40 missing”): three story-NPC model typos (`ANIMISTSt2`, `corsair2_1`, `corsar2` and their heads) were fixed on November 9 (commit `4fb6c5f`) and are no longer listed; `h_offic_hol` was added; animals, yacht and orphan heads now appear as textures inside `.gm`. The old report's “Missing” column sums to 35, not 40 (4+11+10+1+2+4+3); its “40” is inaccurate. That audit's `/tmp/content-audit/audit.py` script was lost; this inventory reconstructs its classes and is test-checked.

## 3. GEOMETRY code: two throw sites

Source: generated translation `korsary2-next/recomp/out_all/MODULES_GEOMETRY_000.c/_001.c` and `MODULES/GEOMETRY.dll` strings (file offsets = RVA). Decompilation was **not** accepted as evidence; results were checked dynamically.

| Function (VA in game image) | Behaviour | Exception |
|---|---|---|
| `f_006e3ad0` (`0x6e3ad0`) | Opens geometry: `CreateFile(name, GENERIC_READ, share 1, OPEN_EXISTING)` via service `[0x100976f4]`. | On `INVALID_HANDLE_VALUE`, if the final four name characters are **not** `.col` (`__strcmpi` with `0x1000e1d8` = “.col”), throws `char*` “can't open geometry file” (`0x1000e1bc`) at `0x6e3b39` (return `0x6e3b3e`) through `f_006e4663` = `_CxxThrowException`. |
| `f_006e1d70` (`geom_static.cpp`, static geometry constructor) | Opens `.gm`, reads its **0x48-byte header** into `this+0x28`. | `cmp dword [edi], 0x312e3035` (**“50.1”**); mismatch throws “invalid version” (`0x1000e0a4`) at `0x6e1e33` (return `0x6e1e38`), same `ThrowInfo 0x6ed8fc` (`.PAD`). |
| `f_006e3860` | Registers `try` with `catch (char*)` and `catch (...)`; both return NULL (`docs/missing-item-models.md`). | **The original does not crash**: the model is simply not created; the port does not execute the catch. |

Both throws lead to one `RaiseException` at `0x006e4697` and cannot be distinguished in the port log. The `0x006e4697 → 0x006e3b3e → 0x006e1e04` chain in `docs/missing-item-models.md` is the first site (`.gm` failed to open), called from `f_006e1d70`. Other header versions (`sky/small_sky/big_sky.gm` “20.1”, `sphere/light.gm` “10.1”) are not loaded through this path; all other 2,069 `.gm` files, including all listed models, use “50.1”. A failed “50.1” check is the only additional case reliably detected without reading the entire file.

## 4. Dynamic tests

Method (historical diagnostic materials deleted): for each experiment clone `game/` to a scratchpad with `cp -Rc game/` (at least 8 GB free was checked: 19 GB free, clone ≈0 bytes); mutate one resource (`rm`, `trunc`, `zero`, `garbage`, `edit` of a cp1251 script). `dyn_probe.py` runs the standard Node build `build_web/node/game.js` with `PORT_LOG=1 PORT_NO_AUDIO=1`, a separate empty `PORT_USERDATA`, and scripted `PORT_INPUT` (as in K3's `recomp/tests/heap_scenario.mjs`: `300:key=1c` for New Game, Space through Malcolm dialogue pages). Stop at frame/timeout/crash; inspect failed opens (`[file] CreateFileA(...) = No such file`), `RaiseException`/trap, clone `system.log`/`compile.log`; remove clone and profile. 60 runs, up to three in parallel, ≈55 s for non-crashing and 3–29 s for crashing runs. Only the clone was read; the original was unchanged (no `korsary2-work/game` file was newer than the session start).

Scenario coverage: new game → loading screen → Tutorial_Deck (≈ frame 327: location, player, Malcolm and weapon load; ≈ frame 660: dialogue and head load) → read dialogue until ≈ frame 1560, then continue to frames 2600–3000 without walking input. B00 (9,000 frames, scenario in `docs/missing-item-models.md`) **did not leave** the tutorial or reach Oxbay; all eight island locators open at frame 0 (initial `Islands_init`). **Not reached:** sea, towns, other locations, F2/trade interfaces, random items/encounters, combat, boarding and finale. Thus crash evidence covers the loader mechanism for reachable files; reachability of others is static analysis.

Results (frame = stop; `trap` = `RaiseException e06d7363 (from 006e4697)` → `guest trap` → `Aborted()`, process exited on its own):

| Test | Mutation | Result |
|---|---|---|
| M00 | Control | 2,702 frames, no crash; opened at frame 327: Items/blade1, Ammo/blade20, Characters/Blaze, bocman3, Tut_deck (four `.gm`), seagull, fish01; at frame 660: Heads/h_bocman3 (+ `animation/Heads/h_bocman3.ani`, `Heads/AN/h_bocman3.an`). |
| M01, M05 | Missing `Items/blade1.gm` / `Ammo/blade20.gm` | **trap**, frame 327. |
| M02, M03 | Missing `Characters/Blaze.gm` / `bocman3.gm` | **trap**, frame 327. |
| M04 | Missing `Heads/h_bocman3.gm` | **trap**, frame 660 (dialogue). |
| M06, M13, M14, L04 | Missing `Tut_deck/tut_deck_w.gm`, `_fd.gm`, `tut_Deck.gm`, `tut_Deck_l.gm` | **trap**, frames 322–327. |
| M07, L03 | Missing `seagull.gm` / `fish01.gm` | **trap**, frame 327. |
| L01, L02 | Missing `Islands/Oxbay/Oxbay_locators.gm` / `KhaelRoa_locators.gm` | **trap, frame 0** (before menu). |
| M15 | Missing both blade1 and h_bocman3 | Trap on the first (frame 327). |
| L05 | Missing `Items/blade6.gm` | No crash through frame 2717 (not opened in this part of the scenario). |
| M08 | `blade1.gm`: 200 garbage bytes | **trap**, frame 327 (invalid version). |
| M10 | `blade1.gm`: empty | **trap**, frame 327. |
| M09, G05 | `blade1.gm` / `h_bocman3.gm`: exactly 72 bytes | **“memory access out of bounds”** (wasm), frame 326 / 662. |
| G01, G02, G03 | `blade1.gm`: 25% / 75% / −66 bytes | No crash (frames 2716–2718). |
| G04 | `bocman3.gm`: 50% | No crash. |
| M12 | Missing `tut_Deck_p.ptc` | “Can't loaded patch data file tut_Deck_p.ptc for npc.”, no crash. |
| T01–T05 | Missing texture Characters/Blaze, Items/BLADE1, CAP_DECK (location), Characters/bocman3, BATTLE_INTERFACE/LANDCOMMANDS | “Can't load texture …”, no crash. |
| T06 | Missing `LOADING/START_LOADING.TGA.tx` | Same. |
| P01 | Missing `PORTRAITS/64/face_16.tga.tx` (player HUD portrait) | “Can't load texture …FACE_16…”, no crash (analogous to face_47–51). |
| A01, A02, A03 | Missing `animation/man.an`, `man.ani`, `woman.an` | “Cannot open file / animation file …”, no crash. |
| H01, H02, H03 | Missing `animation/Heads/h_bocman3.ani`, `Heads/AN/h_bocman3.an`, `dialog_head.ani` | “Cannot open …”, no crash. |
| S01 | Missing `Sounds/music/Coridor.ogg` | **trap, frame 17** (main menu; raise site `0x0099839b`). |
| S02 | Missing `Sounds/MUSIC/Gubernator.ogg` | **trap, frame 327**: second confirmation of R1. |
| S03, S04, S05 | Missing `ok.wav`, `step_wood.wav`, `seagull2.wav` | Silence, no crash. |
| I01–I06 | Missing `lights.ini`, `dialog.ini`, `animals.ini`, `loclighter.ini`, `PARTICLES/alcove.ini`, `ALIASES/Greetings_alias.ini` | No crash in the first 2,700 frames (effects not assessed; `language.ini` is required by `port.json`). |
| X01 | Clone script: Malcolm's head = `h_offic_hol` (real hazard) | **trap**, frame 660. |
| X02 | Same, head = `h_Offic_eng` (exists) | No crash: script mitigation removes the crash. |
| X03 | Clone script: Malcolm's model = `skel1` (`h_skel1` missing) | **trap**, frame 667 (dialogue). |
| X04 | Model = `none` (`Characters/none.gm` absent from original) | **trap**, frame 329. |
| X05, X06 | Head = `capitan` / `h_Monkey` (absent from original) | **trap**, frame 625 / 623. |
| X07, P02, P03 | Attempt to show portrait 256 through F2 | Screen did not open with `key=3c`: **not checked**. |

Dynamic conclusions: (1) GEOMETRY throws wherever a requested `.gm` cannot open or fails its version check; **one** missing file of any class suffices. (2) The crash happens when the file is **requested**, not at process start: Items/Ammo on giving/equipping an item, heads in dialogue, locations on entry. (3) `.col` exceptions are suppressed (the original lacks `tut_Deck_l_day1.col` and others), confirmed by code and their absence in the control. (4) All tested resources other than `.gm` and `.ogg` were safe.

## 5. Preflight changes (`web/missing-resource-preflight.mjs`)

Previously: refuse to start if `ENGINE.exe`, `port.json` required files, `Items/blade1.gm`, `blade6.gm` or 24 music `.ogg` files were missing; warn for other Items, textures and music.

Now (all decisions follow section 4; `presence-only` and “a preflight failure does not block launch” remain):

| Rule | Outcome | Data | Modes |
|---|---|---|---|
| Missing/unreadable/directory instead of file: **45 item models** from the item table (`KNOWN_ITEM_MODELS`), **29 held weapon models** `Ammo/*` (`KNOWN_AMMO_MODELS`), **17 startup models** (`KNOWN_STARTUP_MODELS`: Tut_deck ×4, Blaze, bocman3, h_bocman3, eight island locators, seagull, fish01) | Refuse `RES_MISSING`/`RES_UNREADABLE`/`RES_NOT_FILE`, `why: crash-gm` (`crash-known` for blade1/blade6). | Module constants = `known-mines.json`. | With or without manifest. |
| Headers of these 91 `.gm`: under 72 bytes or first four bytes ≠ “50.1” | Refuse **`RES_BAD_HEADER`** (new code). | `GM_MAGIC`, `GM_HEADER_BYTES`. | With or without manifest; four bytes read via `file.slice`; check skipped if `slice` is unavailable. |
| Size/SHA-256 of these `.gm` and five unreferenced `Items` (`adrenaline`, `door`, `elixir`, `sqitem`, `stonemap`) | Warn `RES_SIZE_MISMATCH`/`RES_HASH_MISMATCH` as before; Ammo and startup models now also get hash checks. | Manifest. | With manifest. |
| Other manifest `RESOURCE/MODELS/**.gm` (≈1,980 files) | Warn `RES_MISSING`, `why: model`; **presence from directory listing only** (`getFile` is not called). | `CHECK_RULES` (`listOnly`). | Manifest only. |

Why **not** refuse for every missing manifest `.gm`: the loader crash is proven, but blocking launch for a file never opened in a game (dead `Yacht*`, `Fort`, unused location variants) would be a false refusal. Warnings retain diagnostics in the console and `window.resourcePreflight`. Size/hash mismatches are not fatal because truncation after the header was not proven to crash (G01–G04), and a garbage/empty/short file is caught by the header independently of the manifest.

**Not done**, and why: `Ships/*`, `Locations/*`, `Characters/*` outside startup and `Heads/*` outside `h_bocman3` are not protected by fatal refusal; only the models listed in the experiments are dynamically reachable, the rest have static evidence and a `model` warning. Expanding `KNOWN_STARTUP_MODELS` needs another entry scenario (town, sea), see section 9. Preflight **cannot** fix references absent from the original because they are not in the manifest; see section 7.

Cost: for the real manifest (historical diagnostics deleted), 2,177 entries are planned (was 153), and 160 files / 8.75 MB hashed (was 114 / 5.2 MB); 81–167 ms in Node, 28 ms without directory listings. In ephemeral headless Chromium with real OPFS and 2,120 synthetic files in 216 directories (matching 2,074 `.gm` in 216 directories in the actual set): **107 ms** with manifest (median of five runs), **26 ms** in `presence-only` (118 files, four header bytes each). This exceeds the “tens of milliseconds” target because listing 216 directories costs ≈80 ms; it is negligible before a ≥20-second game load, and the separate `model` rule is easily disabled. SAVE/SAVE_META/`options` are not read; tests forbid all writes.

## 6. Protected / unprotected summary

The full table was in historical diagnostics (deleted).

| Fatal protection | Warning | Unprotected |
|---|---|---|
| `ENGINE.exe`; port `required`; 91 `.gm` (presence + “50.1” header); 24 music `.ogg` | Remaining `Items`, Items textures, other music, other manifest `.gm`, size/hash of checked files | References absent from the original (`h_offic_hol`); truncation after a `.gm` header; same-size music substitution; a file disappearing after the check; other C++ exceptions. |

## 7. References absent from the original

Preflight compares an installation with the manifest, which does not include these files. The only **reachable** one is `Heads/h_offic_hol.gm` (Dutch coast guard at Douwesen). Options (precedent: typo fixes `4fb6c5f`; the head was added using option 2, animation: see N6/N11 below):

1. Script: in `SetCoastalGuardPursuit` (`Dialog_func.c`), assign an existing head for the Dutch nation (X02: `h_Offic_eng` eliminates the crash). Minimal change but changes appearance.
2. Distribution data: add `Heads/h_offic_hol.gm` (copy of `h_Offic_eng.gm`) plus `animation/Heads/h_offic_hol.ani` and `Heads/AN/h_offic_hol.an` (copies). Requires a distribution `files` rule owned by another agent.
3. Defer: requires SEH dispatch (section 8); not recommended.

Dead references (`none`, `capitan`, `h_skel*`, `h_Monkey/mummy`, `Fort`) crash if requested (X03–X06), but code does not request them. A dummy asset could also protect them, but is not meaningful without demonstrated reachability.

## 8. SEH dispatch conclusion

K4 section 6 recommends leaving it disabled and reconsidering only if dynamic tests find a reachable **unknown** case. One reachable case was found, but it is **known and addressable with data** (`h_offic_hol`, section 7). No other reachable missing files were found among the statically inferred references; each class with a demonstrated crash is now either protected by refusal or unreachable.

Dispatch would restore original behaviour (catch at `0x006e39fa` in `f_006e3860` returns NULL, no model, game continues) for **any** missing or invalid model, including unknowns. Its cost is that K4 blockers 4–8 remain open: a bug would turn a clear refusal into corrupted state. For known cases, data/preflight is cheaper and safer. **Conclusion: keep dispatch disabled.** Reconsider if (a) a live agent finds a real `e06d7363` crash with an intact installation, or (b) an audit of later locations finds many reachable absences.

## 9. Checks for a live agent (separate origin, clean profile, no user data)

1. Control: `window.resourcePreflight.status === 'ok'`, `counts.planned ≈ 2177`, `elapsedMs` on real OPFS, cold and warm: expect ≈0.1–0.3 s; record if >0.5 s (disable `model` rule).
2. In the test origin remove one at a time `Items/blade1.gm`, `Ammo/blade20.gm`, `Islands/Oxbay/Oxbay_locators.gm`, `Heads/h_bocman3.gm`, `Sounds/MUSIC/Gubernator.ogg`: expect `RES_MISSING` before runtime launch, no trap. Replace `blade1.gm` with a 71-byte file and with different first four bytes: expect `RES_BAD_HEADER`.
3. **Expand game-entry coverage** (this session's dynamic test did not pass the tutorial): finish the tutorial, go to Oxbay/port/sea, then collect actually opened `.gm` files in the browser (`[preflight]` log/console) and add new ones to `KNOWN_STARTUP_MODELS` (`startup-gm.json` format: `[file] CreateFileA(...) = ok`).
4. Douwesen coast-guard scenario, if reachable (smuggling near the Dutch island, board the guard captain, dialogue): confirm a browser-build crash on `h_offic_hol`, then the mitigation effect.
5. Confirm portraits face_47–51 yield an empty portrait without crashing (Character screen for a Dutch officer).

## 10. Files

Changed: `korsary2-next/recomp/web/missing-resource-preflight.mjs`, `korsary2-next/recomp/tests/test_missing_resource_preflight.mjs`, historical diagnostic materials (deleted).
New: `docs/missing-resources-dynamic.md`, `korsary2-next/tools/resource-audit/audit_refs.mjs`, `korsary2-next/tools/resource-audit/known-mines.json`, historical diagnostic materials (deleted; `matrix_defs_6.json`, `startup-gm.json`), `korsary2-next/recomp/tests/mutate_missing_resource_preflight.mjs`.
Unchanged: `host/*.c`, `port.js`, `make_dist.py`, `port.json` (`files.required` unchanged: adding `.gm` to `required` is neither needed nor safe without `tools/configure.mjs`/`test_make_dist_coverage.mjs`; it is shared by the port, while preflight lists also work without it).

Reproduction command referred to deleted historical diagnostic materials; its arguments were `--game korsary2-next/game --node-js korsary2-next/recomp/build_web/node/game.js --work <scratchpad directory> --out r.json --defs <deleted diagnostic definitions> --parallel 3`. Original run logs were in the session scratchpad (`.../scratchpad/mrp/mx1…mx6`) and were not committed.

## 11. Limitations

- Node build without rendering or sound (`PORT_NO_AUDIO`): GEOMETRY/SoundService crashes reproduce, but browser behaviour (WebGPU, workers) was not checked; loader code is shared and no differences are expected.
- The scenario does not reach sea or towns; “reachable” there is inferred from code, not the run. `Ships/Fort/Fort.gm` and the coast-guard calculation were not dynamically confirmed.
- Experiments mutate **one** resource; simultaneous absences were not investigated except M15.
- The startup `.gm` list depends on one scenario (frames ≤ 9110); random items (`blade6`, etc.) were not opened and are protected through the item table rather than the trace.
- Static auditing is heuristic (script regular expressions): it misses models named differently, including names from `.ini`, and quest substitutions outside checked templates; reference counts are estimates, not proof of completeness.
- Tests against the actual game (`test_missing_resource_preflight.mjs`: list comparisons, “50.1” headers of 91 files) read `korsary2-next/game` and skip without the game directory.

## 12. N6/N11 outcome (2026-11-12)

**N6 — `h_offic_hol` head animation: resolved with data.** The engine chooses the dialogue head animation by head name: `headModel = "h_" + model` (`Dialog_func.c:662, 683, 704`, `SelectSoldierModelByNation`) → `RESOURCE/animation/Heads/<headModel>.ani` (M00 trace: `Heads/h_bocman3.gm` → `animation/Heads/h_bocman3.ani` → `Heads/AN/h_bocman3.an`). Without `.ani`, the game does not crash (H01/H02: “Cannot open …”), but the Douwesen coast-guard captain's head remains motionless during dialogue (`dialog_stay*`, `yes*`/`no*`), like a mannequin; this is cosmetic and rare.

Analogue selection: `.ani` is text with first line `animation = Heads\AN\<name>.an` plus clip descriptions. `h_Offic_eng/fra/por/spa.ani` have identical clips (3,432 bytes), while each head has its own `.an` (766,292 bytes, differing by ≈140 bytes). `h_Offic_hol.gm` is byte-identical to `h_Offic_eng.gm`, so paired `h_Offic_eng.an` fits exactly. Therefore `tools/apply_content_fixes.mjs` (`h_offic_hol_ani` fix) copies **only** `animation/Heads/h_Offic_eng.ani` → `h_Offic_hol.ani` byte for byte. The copy's first line still references existing `Heads\AN\h_Offic_eng.an`; a copy of `.an` (766 KB) is unnecessary. Original-data precedents: `h_mask_2/3/4.ani` → `h_mask.an`, `h_Will_2.ani` → `h_Will.an`, `h_storeman.ani` → `h_Storeman1.an` (multiple `.ani` files share one `.an`). The 3,432-byte file was added to `korsary2-work/game` (SHA-256 `d0bafe83…`) without overwrite; rerunning does nothing. `h_OfGolland.ani` is unsuitable because its `.an` is absent.

Related: `tools/make_content_patch.mjs` classifies `resource/animation/heads/` as `content_fix`; `content-patches/expected-manifest.json` regenerated (1,056 added, 10,595 expected, `content_fix` = 2); `prepare_game.mjs --repack … --deep` reproduced the working copy on an APFS repack clone (comparison passed, `diff -rq` differed only in `.DS_Store`, `compile.log`, `system.log`; clone deleted); `known-mines.json` regenerated (`animation/Heads/h_offic_hol.ani` removed from dead missing references, `known_missing_refs` 192, unclassified 0). Tests: `test_prepare_game.py` (29, mini-repack received `h_Offic_eng.ani`), `test_missing_resource_preflight.mjs` (27 groups), `mutate_missing_resource_preflight.mjs` (21/21). Live check not performed: Douwesen coast-guard captain dialogue (smuggling, boarding) should animate the head, without “Cannot open … h_offic_hol.ani” in the log.

**N11 — manifest validator: SHA-256 required for every entry.** Location: `web/save-protection.mjs`, `validateManifestFiles`. Previously `sha256` was required only for `options` and encoded/packed entries; a normal file entry without `sha256` passed with only `size` checked. The `syncManifestFiles` expression `const ok = !f.sha256 || …` then treated an installed same-size file as intact without checking contents; uncompressed installed files were checked only by size.

Now every entry except `SAVE`, `SAVE_META`, `SAVE_TX` (which `selectGameAssets` discards as player data) must have `size` (integer ≥0) and `sha256` (64 hex digits); otherwise it refuses before disk writes, naming the file and count of other bad entries. The `!f.sha256 ||` bypass is removed; verification of installed files ignores hex case. Compatibility: `make_dist.py`/`serve.py` manifests (`gamefiles.manifest_for`) include SHA for all entries; tested with the real generator on fixtures (normal, gzip, br, packs), on the real game (`game_files` + `manifest_for`, 9,826 entries) and on the old diagnostic distribution (deleted; 10,575 entries, all with SHA, passes).

Tests: new `test_manifest_strict_sha256.mjs` (seven groups: missing/short/long/non-hex/non-string sha256, missing/invalid size, `options` without SHA, compressed and packed entries without SHA, mixed manifests with bad entries at start/middle/end, SAVE*, refusal before writes in `syncManifestFiles` and `checkStorageForSync`, real generator with SHA missing/truncated in every entry, dist-real) and `mutate_manifest_strict_sha256.mjs` (22/22 mutations caught; mutation of the compressed-entry loop and `options` check excluded as equivalent mutants duplicated by the common check). Existing `test_game_transfer.mjs` fixtures (group 11 explicitly asserted acceptance without SHA) and `test_storage_estimate.mjs` gained SHA.
