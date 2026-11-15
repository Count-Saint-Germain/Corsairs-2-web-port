# English layer: remaining Russian text (187 literals) — classification and translation of visible strings

> Historical report: recorded tool names and commands describe the versions used for the original investigation. For the current Node.js development workflow, see [Development after cloning](BUILD_FROM_CLONE.md).

Date: 13.11.2026. User decisions: the English layer is accepted as-is, 17 `REVIEW` strings remain, **the agent translates remaining visible Russian strings**, and voice audio is left unchanged.
Context: `docs/english-layer.md` (§1 contract, §6 “what remains Russian”, §11), `docs/english-headless-e6.md`. Code: `korsary2-next/tools/prepare_english.mjs`, `english_text.mjs`;
data: `korsary2-next/english-layer/{manual-strings.json, leftover-classes.json, expected-overlay.json}`; tests: `korsary2-next/recomp/tests/test_prepare_english_core.mjs` and `korsary2-next/recomp/tests/test_prepare_english_text.mjs`.
Nothing was checked live (browser rendering): that is the live-acceptance agent's work (§6 below).

## 1. Outcome

Each of the 187 `left_russian` literals was checked against the code: how the string is used (dialogue/label, key/path, comparison, debugging), and whether the file is included in the game (`#include` / `Dialog.Filename`).

| Class | Literals | Action |
|---|---:|---|
| `visible` | **110** | **translated** (manual layer `manual-strings.json`, 110 new entries); 83 are reachable in the game, 27 are in `quest_sailor_tmp`/`quest_sapper` dialogues that scripts never call (translated as a precaution, no risk) |
| `identifier` | 23 | **left unchanged**: voice paths `Dialog.snd = "voice\VIМА\VIМАnnn"` (Cyrillic `М`, `А` in the resource name) |
| `debug` | 38 | **left unchanged**: `Trace`/`trace` (`system.log` only) 25 + reference template `Locations/location_init.txt` (not compiled) 13 |
| `ambiguous` | 16 | **left unchanged**: dead `DIALOGS/Rumour_Data.c`/`.h` (15) and `locations[n].label` in `Oxbay.c` (1) |
| total | 187 | **77** remain Russian (all `identifier`/`debug`/`ambiguous`; `same_in_us` 73, `us_russian` 4) |

There is no `visible` class in `leftover-classes.json`: translated literals are already in `manual-strings.json`. The `leftover-classes.json` list contains exactly the remaining 77 and **protects** them (§4).

## 2. Classification (by file; one-line rationale)

| File | Ordinals | Lit. | Class | Rationale |
|---|---|---:|---|---|
| `DIALOGS/arnaud matton_dialog.h` | 138 | 1 | visible | Arnaud's line: `DLG_TEXT[138] + name + [141]` (concatenation), displayed |
| `DIALOGS/Enc_RapersGirl_dialog.h` | 0–52 | 53 | visible | random encounter “bandits and girl” (`ENC_RAPERS`, templates `enc6/enc2` in `LandEnc_init.c`), lines via `RandPhrase`/`Link` |
| `DIALOGS/Enc_Rapers_dialog.h` | 0–13 | 14 | visible | same, bandits' lines and player's replies |
| `DIALOGS/quest_sailor_tmp.h` | 0–4, 6, 7, 9–16 | 15 | visible | sailor dialogue; `MissingBoatswain`/`ApplinDying` branches are never enabled (`quest_sailor_tmp` character is not placed) |
| `DIALOGS/quest_sapper.h` | 0–11 | 12 | visible | sapper dialogue (`bomb_laying_go`), not called by scripts; normal `DLG_TEXT` |
| `Locations/init/Redmond.c` | 29, 34, 39, 44, 49, 69, 74 | 7 | visible | `Locations[n].reload.lN.label` — transition locator label displayed by the engine; other labels in the file are already English |
| `Locations/init/Oxbay.c` | 453, 458, 463, 627, 632, 637 | 6 | visible | same (`Джунгли.`, `Море.` — Jungle, Sea) |
| `Locations/init/IslaMuelle.c`, `QuebradasCostillas.c` | 110; 166 | 2 | visible | same (`Магазин.`, `Кебрадас Костиллас.` — Store, Quebradas Costillas) |
| `DIALOGS/Valentin Massoni_dialog.c` | 18, 21, 32, 36, 39, 42, 45, 57, 60, 63, 66, 69, 72, 76, 81, 92, 105, 108, 111, 114, 117, 120, 126 | 23 | identifier | `Dialog.snd = "voice\VIМА\VIМАnnn"`: sound-resource key with Cyrillic; translating breaks voice audio |
| `Dialog_func.c` | 177, 211, 260–263 | 6 | debug | `Trace`: character movement, smugglers, island, nation |
| `LandEncounters/LEnc_login.c` | 0, 1, 2, 4, 7, 9, 11, 19, 20 | 9 | debug | `trace` from land-encounter generator |
| `QUESTS/quests_scenes.c` | 105, 109, 129, 142 | 4 | debug | `trace("WARNING … не реализована")` (not implemented) |
| `QUESTS/both_reaction.c` | 0, 902 | 2 | debug | `trace` for quest / coast guard checks |
| `DIALOGS/Docker Generated_dialog.c`, `Ralph Damerell_dialog.c` | 47, 51; 70, 74 | 4 | debug | `trace("Айдишник персонажа - " …)` (character ID) |
| `Locations/location_init.txt` | 1, 25, 29, 31, 33, 35, 37, 38, 49, 55, 80–82 | 13 | debug | reference template for location fields in `.txt`: no `#include`, not read by scripts |
| `DIALOGS/Rumour_Data.c`, `Rumour_Data.h` | 10–17; 0–6 | 15 | ambiguous | dead files: `Dialog_func.c` includes `PROGRAM/Rumour_Data.c` (translated through its US counterpart), while nobody includes `DIALOGS/Rumour_Data.*`; `NPC_information[]` is never read |
| `Locations/init/Oxbay.c` | 1183 | 1 | ambiguous | `locations[n].label` (not `id.label`): scripts do not read or compare the attribute; whether the engine displays it is unknown, so it is not translated |

Code checks: `label` is never compared (`==`); voice paths and character `id`s referenced by dialogue (`DLG_TEXT[8] = "Ralph Fawn"`, `DLG_TEXT[139]/[140]` — `"Sylvie Bondies"`) are Latin and not part of the translation.
For `ambiguous`, translation would be harmless (no script reads these strings), but the user's decision was not to translate disputed cases; if needed, add a `manual-strings.json` entry and remove the line from `leftover-classes.json`.

## 3. What was translated (110 strings)

* **Random encounter “Bandits and girl”: 67 strings** (`Enc_RapersGirl_dialog.h` 53, `Enc_Rapers_dialog.h` 14). Tone follows the neighbouring `Enc_Raiders` encounter in the English layer (bandit threats, “sir/lad/friend”, moderate pirate speech, “Lord”, “maker”); `RandPhrase` strings are independent variants. `Enc_RapersGirl[28]` (“Никуда я пойду” — a typo in the original) was translated by meaning as “I'm not going anywhere…” (`REVIEW`).
* **Arnaud Matton (daughter → Isla Muelle): 1 string.** Concatenation: `"As I said, you must take my daughter to the island of Isla Muelle, to her godmother. Her name is "` + `Sylvie Bondies` + `". \nShe's French, but…"` (the godmother's name comes from the US pair, as in the layer). `REVIEW`: read the entire concatenation.
* **`quest_sailor_tmp.h` 15 + `quest_sapper.h` 12** (unreachable dialogues). In `quest_sailor_tmp[0]` the code concatenates the player's name and this fragment without a separator; the English fragment starts with `", are you back already? …"` (comma added; the Russian lacks it). Concatenations `[4]`+form of address+`[5]`, `[7]`+name+`[9]` are `REVIEW`.
* **Location labels: 15 strings** — wording follows nearby English labels in the same files: `Jungle.`, `Sea.`, `Store.`, `Port.`, `Shipyard.`, `Redmond.`, `Loanshark's Office.`, `Quebradas Costillas.` (island spelling follows `ISLANDS/Islands_init.c`).
* All strings: ASCII, no `\n`/`%` specifiers (checked by the loader), no smart quotes; translated from Russian 1.03, with no US text in `manual-strings.json` or the baseline (marker-word check in the test).
* New `REVIEW` entries: 5 (**22** total = previous 17 + `arnaud matton[138]`, `Enc_RapersGirl[28]`, `quest_sailor_tmp[0]`, `[4]`, `[7]`).

## 4. Tool changes

Existing logic already permits a manual entry for a literal **without a US counterpart** (`manual` class, `Only_ru.c`) and a literal that is **Russian in the US version too** (`same_in_us`/`us_russian`: no `override` needed, the file is built from the Russian base with substitution, `align` class with `manual>0`). This was verified on real data (8 new layer files) and by new tests; **no changes to `english_text.mjs` were needed**. Added to `prepare_english.mjs`:

* `english-layer/leftover-classes.json` (format: `file`, `index`|`key`, `ru_sha256`, `class` ∈ `identifier|debug|ambiguous`, `why`) and `Leftovers` loader; the file is loaded automatically when beside the manual layer (or via `--leftovers`; an explicitly specified missing file causes refusal).
* Identifier protection (`check_protected`): a manual entry (including with `override`) for a listed literal causes **refusal**; literal SHA must match (base drift causes refusal); a protected literal replaced by automatic pairing causes refusal.
* Completeness (`classify_left`): a leftover **without an entry** causes refusal (“translate or classify”); an entry without a leftover (literal translated or file changed) causes refusal. The class is recorded in baseline `left_russian` (`class`), `totals.left_by_class`, `sources.leftover_classes_sha256/leftover_entries`.
* `expected_from(..., leftovers=None)`, `build_overlay(..., leftovers=None)` — old calls work; without a classification file, behaviour is unchanged (synthetic tests do not change).

## 5. Layer figures and checks

| | Before (12.11) | After |
|---|---:|---:|
| Layer files (including `OVERLAY.json`) | 763 | **771** (+8: `Enc_RapersGirl_dialog.h`, `Enc_Rapers_dialog.h`, `quest_sailor_tmp.h`, `quest_sapper.h`, `Locations/init/{Redmond,Oxbay,IslaMuelle,QuebradasCostillas}.c`; `arnaud matton_dialog.h` and `OVERLAY.json` changed) |
| Layer size | 124 720 554 B (118.9 MiB) | **124 942 404 B (119.15 MiB)**, gzip-9 per file 74 627 686 B (71.2 MiB) |
| Text portion (excluding Textures/Sounds/ALIASES) | 243 files, 1 643 619 B, gzip 431 395 B | **251 files, 1 903 076 B (1.81 MiB), gzip 465 969 B (0.44 MiB)** |
| Manual entries | 145 | **255** (110 new literals) |
| `align`: manual / remain Russian | 66 / 7 | **176** / 7 |
| Remain Russian (`left_russian`) | 187 (`same_in_us` 168, `us_russian` 19) | **77** (`same_in_us` 73, `us_russian` 4): `identifier` 23, `debug` 38, `ambiguous` 16 |

(New `Locations/init/*.c` files enter the layer in full: the layer overlays a file, rather than patching it; +≈ 0.2 MB.)

* **Build on real data:** `prepare_english.mjs --base korsary2-next/game --us-iso Disc1 Disc2 --out <directory> --video-out <directory>` — rc 0, ≈ 10 s, “СВЕРКА ПРОЙДЕНА” (verification passed); a second run from a single-disc image to another directory — **`diff -r` empty** (layer and `Invasion.mp4` byte-identical); `--check --out <layer> --base …` — 771 files, “СВЕРКА ПРОЙДЕНА” (verification passed); `--check --base … --us-iso …` (in-memory rebuild) — “СВЕРКА ПРОЙДЕНА” (verification passed). The skeleton of every `PROGRAM` file equals the Russian one (`verify_payload`: bytes outside literals, literal count, ASCII in replacements, specifiers).
* **Cyrillic:** none in replaced literals (ASCII checked during substitution); 7 Cyrillic literals remain in layer files (`Dialog_func.c` 6 — `Trace`, `Locations/init/Oxbay.c` 1 — `ambiguous`), all in `leftover-classes.json`; another 70 are in files not present in the layer (Russian in the base too).
* **Tests:** Current Node tests: `node --test korsary2-next/recomp/tests/test_prepare_english_*.mjs korsary2-next/recomp/tests/test_english_text.mjs`. **Historical Python run: 96 tests OK** (was 77; +19: 13 in `LeftoverTests`, 3 protection mutants in `LeftoverMutationTests`, 3 in `RealLayerFiles`); with `K2_ENGLISH_OVERLAY=<layer>` — `RealOverlay` OK (including “every Russian literal in the layer is classified”). Related: `test_overlay_dist.py` (34 OK), `test_verify_dist.py` (25 OK).
  New coverage: manual translation of `same_in_us`/`us_russian`/unpaired literals, refusal on `identifier`/`debug` (including with `override`), refusal on automatic replacement of a protected literal, unclassified leftover, entry without a leftover, SHA drift in list, corrupt list files, CLI pickup of adjacent file, `--check` detects class change; mutants disabling `check_protected`, `classify_left`, and auto-pair protection were killed.
* **Historical Python smoke (`english_smoke.py --overlay <layer> --game-clone <new-directory> --keep-logs <directory> --cross --remove-clone`, 5 min 14 s, on the 771-file layer): `Вердикт автоматических критериев: PASS` (automated criteria verdict: PASS), original game unchanged (fingerprint before/after), clones removed.**
  Crashes 0 (RU and EN), `[overlay] on` 1, `refused` 0, no language/texture/patch/cannot-open/script-error classes (normal `VK_B`: 1 each in RU and EN), same 4 failed opens. 29 files opened from overlay (was 25; 4 `Locations/init/*.c` added): modified scripts compile and load. EN heap: Malcolm 154/154, names 400/400, 827 of 828 strings from opened layer files, Russian strings 0 of 208 (as before).
  Limits as in `docs/english-headless-e6.md` §6: the scenario does not open encounters, `Enc_Rapers*`, or location maps.

## 6. Proofreading points (`REVIEW`, 22 entries) and what remains for live acceptance

**Proofreading (human):** previous 17 (`docs/english-layer.md` §5/§12 item 7) + 5 new: `arnaud matton_dialog.h[138]` (concatenation with name and `[141]`), `Enc_RapersGirl_dialog.h[28]`, `quest_sailor_tmp.h[0]`, `[4]`, `[7]` (concatenations; unreachable dialogue). The other new translations need ordinary tone proofreading.

**Live acceptance (another agent, `docs/english-layer.md` §12 — add):**
1. **Random encounter “Bandits and girl”** in English mode (jungle/shore, template `enc6`): the girl and bandits speak English; branches: help → thanks (money at reputation ≥ 80), bandits leave (Fencing ≥ 5 and ≥ rank), robbery (`CheckMoney`), repeat approach, “GetTheHellOut”; no Russian remnants, no dialogue-window overflow for long lines (`[35]`, `[31]`, `[8]`).
2. **Arnaud Matton** — “daughter” branch (`daughter_9`): concatenation reads as one sentence, no double spaces or missing words.
3. **Location labels** `Redmond.`/`Port.`/`Shipyard.`/`Loanshark's Office.`/`Jungle.`/`Sea.`/`Store.`/`Quebradas Costillas.`: displayed near a door/exit without overlapping neighbours.
4. **Rumours (`Rumour_Data`)**: in English mode sourced from `PROGRAM/Rumour_Data.c` (English, US counterpart; **random rumours 2–6 are the same text about the governor of Redmond**, as in the US version). No Russian rumours in game: `DIALOGS/Rumour_Data.*` are dead files. Verify a rumour actually appears in English.
5. Ensure nothing from `identifier`/`debug`/`ambiguous` appears as Russian text (especially the `Mines_commander_house` label; Valentin Massoni's lines have English text and their `Dialog.snd` values were unchanged).

## 7. Risks

* `quest_sailor_tmp`/`quest_sapper` dialogues are unreachable in scripts; if called dynamically somewhere (not found in port code), the `quest_sailor_tmp` concatenations are the only `REVIEW` points.
* `ambiguous` (16) intentionally remain Russian; if live testing shows Russian text from `Oxbay.c: label`, translation is one manual entry.
* The layer grows by 0.2 MB because of whole `Locations/init/*.c` files; network size (gzip) is ≈ 35 KB.
* Layer/base binding (`OVERLAY.json: base`, SHA-256) has not changed in principle; a new port patch to `PROGRAM/**` requires rebuilding the layer and baseline, and if a new Russian literal appears without a translation/class the build now **refuses** (deliberately).
