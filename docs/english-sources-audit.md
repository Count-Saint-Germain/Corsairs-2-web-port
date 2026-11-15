> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

# English sources: audit of US images and English localization plan for the port (E1–E5)

Date: 12 November 2026. Status: **analysis and plan; nothing has been added to the port.** The user's images were read-only (using a custom reader; `hdiutil attach` was not used and `hdiutil info` did not list these images at the end); nothing from the images was executed. The `WIN FIX` archive was only listed (`unzip -l/-v`), not extracted. Only scripts `PROGRAM/**`, `RESOURCE/INI/**`, `QUESTSTEXT`, `engine.ini`, `options`, `Readme.txt`, `ENGINE.exe`, `MODULES/*.dll` (≈14 MB), and a few small files for format checks were extracted, all into a temporary directory that was **deleted**. All figures below are reproducible using `english-audit/` scripts (section 11); only name/size/count tables (`english-audit/results/`, 284 KB), not game text, entered the repository.

## 0. Summary

1. **English localization exists and is complete.** The images are the US Bethesda edition “Pirates of the Caribbean”, **Retail Release 1.0** (`Readme.txt`; `ENGINE.exe` built 19 June 2003, versus 29 July 2003 in our Russian version; `FileVersion` is 1.0.0.1 for both, and the US edition has no 1.01–1.03 patch numbers). English content includes the interface (`TEXTS/ENGLISH`), 11,465 dialogue lines, 409 quest texts, items/help, voices (860 lines, 122.5 MB), 129 loading screens with English captions, and videos (Credits, Invasion, three logos).
2. **The three images contain the same data set.** `Disc 1` + `Disc 2` contain the same `data1.hdr`, `data1.cab`, `data2.cab`, `data3.cab` (identical byte-for-byte SHA-256; table: `english-audit/results/iso-sha256.txt`) as the 1.36 GB single-disc ISO; the single-disc ISO combines the two discs (`DirectX9/` and `MPSetup*.exe` are on Disc 2 and in the single-disc image). The two-disc images are “raw” 2352-byte Mode 1; `7zz`/`hdiutil` cannot open them, so a reader was written (section 1).
3. **An English text overlay on Russian 1.03 can be almost entirely automated.** The Russian release is US 1.0 with translation and patches: **219 of 231 dialogue files have identical structure** (same line count, code skeleton, and `DLG_TEXT` indexes); 10 differ (Russian adds 60 lines), and two have no pair. **11,421 of 11,483 Russian dialogue lines (99.5%) receive an English match automatically**; across all `PROGRAM/**` scripts, 98.7% of Russian string literals (11,129 of 11,272) are replaced with English while checking that code remains unchanged. Approximately 125 lines require manual work (section 3.6); another ≈90 lines are Russian even in the US edition.
4. **Assets:** the English layer is ≈**194 MB raw / ≈130 MB transferred (gzip)** for installation in OPFS (98.6 MB gz for voice, 29.6 MB gz for loading screens), plus ≈33 MB of videos (estimate, served over HTTP, not in OPFS): +8% on 2.37 GB and +11% on 1.19 GB network traffic (D1).
5. **Non-language benefits:** of 192 known “references without files,” the US edition contains **only 145 sounds** (greeting voices `VOICE\Eng_*/Dut_*/Fre_*/…`); models `none`/`capitan`/`h_*`, eight animations, 16 textures, and 10 portraits are also absent there. `Credits`, `WaltDisneyLogo`, `BethesdaLogo`, `AkellaLogo` videos exist; `sunrise` does not. The “WIN FIX” ZIP contains one file, `MODULES/sea.dll` (CRC-32 `d6a3c788`, 2012), with **different content** from `sea.dll` in both game versions (`66236c2b`); compare it with the water artifact (section 5).
6. **Recommendation:** use an **overlay layer** (second OPFS directory + second manifest + path substitution in `map_path`) rather than a second full installation or editing manifest files. Default Russian mode remains byte-for-byte unchanged. E1–E5 plan: **≈16 agent-days** plus live acceptance (section 6).

## 1. Image inventory

| Image | Size | Format | Contents |
|---|---:|---|---|
| `Pirates of the Caribbean (Disc 1 & 2)/… (Disc 1).iso` | 783 985 104 | **raw CD Mode 1, 2352 bytes/sector** (333 327 sectors, ISO9660 + Joliet, label `PIRATES`) | `Setup.exe` (56 KB), `Setup.ini`, `setup.inx` (145 KB, InstallShield script), `ikernel.ex_`, `layout.bin`, `setup.bmp`, `piratesreadme.txt`, `data1.hdr` (1.08 MB), `data1.cab` (11.2 MB), `data2.cab` (668 MB) |
| `… (Disc 2).iso` | 774 929 904 | same (329 477 sectors) | `data3.cab` (614 MB), `DirectX9/` (6 archives + `dxsetup.exe`), `MPSetup.exe`, `MPSetupXP.exe` |
| `Pirates of the Caribbean/… (USA).iso` | 1 356 122 112 | regular ISO9660, 2048 bytes (+Joliet), mounts with `hdiutil` | combination of both discs |
| `WIN FIX INSIDE, PLACE IN GAME FOLDER.zip` (in both folders, byte-identical, SHA-256 `b02d8420…ffeea67`) | 74 378 | zip (LZMA) | `MODULES/sea.dll` 196 608 bytes, dated 24 August 2012. **Not extracted or run** |

* **Installer format: InstallShield 6** (`ISc(`, version `0x0100600c`), volumes `data1.cab`…`data3.cab` + header `data1.hdr`; 10 211 files in 701 directories (volume 1: 37 auxiliary, 15.9 MB; volume 2: 8 398, 1.356 GB; volume 3: 1 776, 1.281 GB; game ≈2.63 GB uncompressed, including 199 MB WMV videos). No encryption (`u16` chunks + raw-deflate). **Tool:** `unshield` is absent from the system; `7zz`/`cabextract`/`innoextract` cannot read the format (`7zz` only sees the nested Microsoft CAB in `DirectX9/`). Nothing was installed from the network: two readers were written and later ported to Node.js, `english-audit/isoread.mjs` (ISO9660/Joliet, 2048 and 2352) and `english-audit/ishield.mjs` (`LIST`, `EXTRACT <regex>`; verified: all extracted sizes matched the table, no errors).
* Protection: `ENGINE.exe` has no third-party sections (`.text/.rdata/.data/.rsrc`); `StarForce`/`SafeDisc` were not detected; `engine.dll`/`data1.dat` are absent from the US edition. The Russian release's `XINTERFACE.dll` differs from the US one by five bytes (`call` replaced with `mov al,1; nop`): this removes disc binding, not language.
* The installer has no Russian language selection: `Setup.ini` has the sole language `0x0009`. The game installs into `Bethesda Softworks\Pirates of the Caribbean`.

Inventory comparison (`compare_inventory.mjs`; names case-insensitive): 10 207 US files, 10 601 Russian; 9 294 common by name (sizes equal for 8 365, different for 929); **913 US-only, 1 307 RU-only**. Group summary: `english-audit/results/inventory/groups.tsv`.

| Group | US only (files / MB) | RU only | Different size |
|---|---|---|---|
| `Textures/Loading` | 123 / 64.5 | 148 / 77.6 (in `Loading/Russian/`) | — |
| `Sounds/VOICE` | 656 / 95.0 | 489 / 39.2 | 204 / 27.6 (RU) |
| `VIDEOS` | 5 / 99.9 | `Russian/Invasion.wmv` 25.9 MB | — (11 of 16 identical) |
| `Textures/tips` | 78 / 40.9 | — | — |
| `Textures/FONTS` | 6 / 1.9 (unused) | 1 | — |
| `Textures/WorldMap/reload` | 4 / 2.1 | 4 / 2.1 (in `reload/Russian/`) | — |
| `PROGRAM` | 1 | 3 | 273 |
| Sound effects (`AMBIENT`, `NATURE`, `OBJECTS`, `trep`…) | — | orphaned `.ogg`, transcoding (D2) | sizes differ because of `.wav` generated from `.ogg` (not language) |

Models, item textures, animations, islands, and locations are either identical byte-for-byte/by size or only present in Russian (`Items`, `Ships`, 1.03). The US edition contains no models absent from Russian.

## 2. Version and scope of English localization

| Area | US 1.0 | Note |
|---|---|---|
| Interface, items, help | `TEXTS/ENGLISH` (19 files, 58 KB) | **Byte-identical to `TEXTS/ENGLISH` in our Russian release** (all 19 files): this is the “remnant of the English edition” from E0 |
| Dialogue | 231 `DIALOGS/*.h` files, **11 465 lines**, English; several (`Enc_Rapers*`, `quest_sailor_tmp`, `quest_sapper`…) still contain a Russian portion (≈90 literals) | Our Russian version has 11 483 lines |
| Quests | `quests_texts.txt`: 53 quests, 409 entries (title + `#TEXT n`) | Russian has 58 quests, 424 entries |
| Other scripts | NPC names, rumors, items: English literals in `Characters/init/*.c`, `Rumour_Data.c` | ≈1 260 Russian literals in Russian version |
| Fonts | Same bitmap textures `fonts\… rus.tga` as the Russian release (14 textures matched by size); US `fonts.ini` == our `fonts_eng.ini` byte-for-byte | Latin characters are rendered with the same `rus` textures (as in the US edition); only `Menu font.tga` differs (exists in both) |
| Loading screens | `Textures/Loading/*.tga.tx` (129 files, 67.4 MB), with English captions (visually checked: “Bedroom / Loading…” versus “Спальня / Подождите, идет загрузка…”) | Russian version uses `Loading/Russian/` |
| Voices | `Sounds/VOICE/*.wav`: **860 greeting lines** (Eng/Dut/Fre/Spa/Por/Ita; PCM 22 050 Hz, 16-bit, mono), 122.5 MB | Russian has 231 lines; 74 of 395 active `Greetings_alias.ini` references are dead |
| Videos | `VIDEOS/*.wmv`, 16 (199 MB): 11 shared + `Credits` (194 s), `Invasion` (83 s), `AkellaLogo`, `BethesdaLogo`, `WaltDisneyLogo` | `Invasion` has separate Russian voice in `Russian/` |
| Version | `Readme.txt`: “PC Version Retail Release 1.0” (also includes `piratesreadme.txt`); `ENGINE.exe` 19 June 2003; no `history.txt`/`what_change.txt` | Ours: `history.txt` 1.03, `ENGINE.exe` 29 July 2003 |

Version conclusion: US is an **early build (before patches 1.01–1.03)**; Russian 1.03 is its descendant: same files and names, translated texts, and ≈56 changed scripts (section 3.2).

## 3. Compatibility of Russian 1.03 and US 1.0

Method (`compare_dialogs.mjs`, `compare_scripts.mjs`, `compare_texts.mjs`): match file names case-insensitively; a script “skeleton” is code with comments removed and every string literal replaced with `""`. Equal skeletons mean only text differs. For dialogue, the paired `*_dialog.c` skeleton (branches, `DLG_TEXT[n]` indexes) is also compared.

### 3.1 Dialogue `PROGRAM/DIALOGS/*.h`

| Class | Files | RU lines | US lines | Meaning |
|---|---:|---:|---:|---|
| `IDENT` (line count and `.c` skeleton match) | 209 | 10 710 | 10 710 | index-based transfer is safe |
| `H_ONLY_EQ` (no paired `.c`, equal line count) | 9 | 84 | 84 | transfer by index |
| `COUNT_EQ` (equal line count, different `.c` literals: `Jaoquin de masse`) | 1 | 18 | 18 | `DLG_TEXT[0..17]` reference sequence in `.c` is identical: transfer by index |
| `COUNT_NE` (different line count) | 10 | 669 | 609 | align by `.c` skeleton: 609 lines paired, **60 Russian-only lines** |
| `RU_ONLY` (`Eng_Bertillon's Guard_dialog.h`, 2 lines; US `.c` includes nonexistent `.h`) | 1 | 2 | — | translate manually (2 lines) |
| `US_ONLY` (`Greenford Commander1_dialog.h`, 44 lines, no references in either version) | 1 | — | 44 | not needed |
| **Total** | **231** | **11 483** | **11 465** | |

**Divergent files (10), RU / US line counts and reason:** all are in `*_dialog.h` and paired `.c`; these are patch 1.01–1.03 changes (dialogues and quests absent in 1.0):

| File | RU | US | Extra in RU | Details (by `.c`) |
|---|---:|---:|---:|---|
| `Christofor Manuel De Alencar` | 27 | 16 | 11 | new branches (quest 1.01+), `.c` 49 versus 33 literals |
| `Jacinto Arcibaldo Barreto` | 40 | 29 | 11 | same |
| `Joseph Claude Le Moigne` | 95 | 84 | 11 | same |
| `Reynard Grueneveldt` | 60 | 49 | 11 | same |
| `Quest_ANIMISTS` | 53 | 50 | 3 | animator quest edits |
| `Simon Hanpool` | 125 | 121 | 4 | edits |
| `Douwesen Citizen` | 165 | 162 | 3 | Russian added lines at the end (`.c` indexes 162–164 are out of bounds in US) |
| `Douwesen Soldier` | 28 | 27 | 1 | same |
| `Isla Muelle Soldier` | 28 | 27 | 1 | same |
| `Enc_Raiders` | 48 | 44 | 4 | same |

The complete “file → RU/US lines → class” table for all 231 files is `english-audit/results/dialogs/dialogs.tsv` (with declared `N`, reference counts, and `.c` ASCII literals).

### 3.2 Other `PROGRAM/**` scripts (762 files)

`compare_scripts.mjs`: 482 are byte-identical, **220 differ only in text** (204 dialogues and 16 `Characters/init/*.c`, `Rumour_Data.c`, `LandInterface.c`), **56 have code changes** (21 in `DIALOGS`, 35 others), three exist only in Russian (`boal_map.c`, `character_boal.c`, `Eng_Bertillon's…h`), and one only in US. Code changes (1.01–1.03 and port): `seadogs.c` (142 skeleton lines), `quests_reaction.c` (205), `StoryCharacters.c` (37), `reload_tables.c`, `store.c`, `initItems.c`, `QuestBook.c`, `interface.c`, `AICannon.c`, `AIShip.c`, `init_pc.c` (new keys), and 25 more files. These are not an obstacle: **the English layer does not replace entire files; it replaces only literals**, retaining Russian 1.03 code. Exception: `Characters/Characters_names.c` (Russian shortened name lists to 45 literals; US has 670; arrays `sEnManNames[2]` and `AddStr2Array` match) is taken entirely from US. Code language depends on `LanguageGetLanguage()` in **three** places (`seadogs.c` `load`/`new_game` screens, `Dialog_func.c` `TimeGreeting()`): `defaultLanguage = English` enables them; everything else uses `STRSERVICE`.

### 3.3 Transfer prototype (`align_overlay.mjs`, `verify_overlay.mjs`)

Replaces Russian 1.03 literals with US literals (`.h` by index; other files by aligned skeleton lines, `difflib`). Results for all 237 differing files (`results/align`, `results/verify`):

| Metric | Value |
|---|---:|
| Russian literals containing Cyrillic | 11 272 |
| Replaced with US text | **11 129 (98.7%)** |
| Unmatched (only in Russian 1.03) | 54 (0.5%) |
| Russian in US too (same Russian text) | 89 (0.8%) |
| Files changed | 236 |
| After replacement: **code changed** | **0 files** (skeletons match) |
| After replacement: literal count changed | 0 files |
| Suspicious pairs (EN/RU length ratio outside 0.35…3.0 when RU length >25) | 83 of 8 104 (1%); sampled pairs are free translations (“How inspiring.” instead of a long phrase), not alignment failures |

### 3.4 String files `TEXTS/*` and `QUESTSTEXT`

| Set | Files | Common keys | RU only | US only | Conclusion |
|---|---:|---:|---:|---:|---|
| `RU/RUSSIAN` ~ `US/ENGLISH` | 19 | 929 | 19 | 5 | 17 files match in key order; `common.ini` and `ItemsDescribe.txt` differ |
| `RU/ENGLISH` ~ `US/ENGLISH` | 19 | 934 | 0 | 0 | match, including byte-for-byte |
| `RU/RUSSIAN` ~ `US/RUSSIAN` | 19 | 921 | 27 | 1 | US also contains outdated Russian |

* **14 keys lack English:** `common.ini` has 12 (`Brightness`, `Contrast`, `Gamma Correction`, `Horizontal/Vertical Mouse Sensitivity`, `Invert Vertical Mouse Control`, `Restore Default`, `Save Settings`, `Set Flag`, `Video Settings`, `SELLALL`, `titleBoal_map`), `ItemsDescribe.txt` has two (`itmname_artefact`, `itmdescr_artefact`). Another five are **renames** (`itmdescr_animists_amulet` → `itmdescr_satanist_amulet`, `itmnameblade22` → `itmname_blade22`, `itmdescr_blade2` → `itmdescr_blade2r`, `you've_got` → `youve_got`): transfer by mapping table.
* Placeholders `%s/%d/#…#/{…}`: zero mismatches. Eight lines (interface labels) have English at least 1.6× longer than Russian and over 30 characters: check layout live.
* `QUESTSTEXT`: key (quest, `#TEXT n`): 402 common out of 424 Russian entries; **22 Russian-only** (six governor-“sinking” quests `kill_con/dou/fal/mue/ox/red`, added as «не мое» in a fan Russian build); US has one extra quest (`Thomas_O'Reily_contraband`). Prototype `overlay_quests.mjs` replaced 402 entries with zero format-specifier mismatches.

### 3.5 Encodings, characters, length

* All text files use **CP1251 / the ASCII subset of CP1252**, without UTF-8 BOM; 791 of 799 US files use CRLF (790 of 801 Russian); the game reads bytes as-is.
* Bytes ≥0x80 outside Russian insertions are almost absent from US texts: `0x85` (…), `0x91/0x92/0x96` (quotes/dash, a handful of lines); CP1251 gives the same characters `…`, `‘’`, `–`, so these are safe. There are no accented Latin letters (CP1252 `é`).
* Russian bytes remain in 89 lines in the US layer (`Enc_RapersGirl`, `Enc_Rapers`, `quest_sailor_tmp`, `quest_sapper`, part of `Rumour_Data`, etc.); these are Russian in the US game too.

### 3.6 Manual work required (≈125 lines): user decision on translation method

| Item | Lines | Source |
|---|---:|---|
| Dialogue absent in 1.0: 60 lines in 10 files (four files with 11 each, `Quest_ANIMISTS` 3, `Simon Hanpool` 4, `Douwesen Citizen` 3, `Douwesen/Isla Muelle Soldier` 1 each, `Enc_Raiders` 4) and `Eng_Bertillon's Guard` 2 | 62 | Russian 1.03 |
| NPC name in `StoryCharacters.c`, «Все ок!» in `seadogs.c` | 2 | Russian 1.03 |
| `INTERFACE/boal_map.c` (world-map encounter captions such as «Капитан, кто-то плывет…», 19 concatenated phrases), `Напасть?` | 19 | Russian 1.03 |
| Malcolm Hatcher tutorial hints replaced by the port (patch 04: «назначенная команда» instead of F3/Ctrl/…): seven lines, **US text is outdated for the port's bindings** | 7 | port |
| `kill_*` quests | 22 entries | Russian 1.03 |
| `TEXTS/ENGLISH` keys: 12 + 2 new | 14 | Russian 1.01+ |
| Where US version is also Russian (optional) | ≈90 | 1.0 |
| **Mandatory total** | **≈126** (including 22 quest entries and 14 `TEXTS` keys; excluding optional) | |

Automation estimate: **≈99.5% of dialogue lines, 98.7% of other literals, 94.8% of quest entries, and 98% of TEXTS keys (929 of 948) transfer without human work.** The remainder is small: ≈126 lines (about 1% of Russian literals).

## 4. Voices and language-dependent assets

| Russian asset | Size | US equivalent | Compatibility | Installation contribution (raw / gzip) |
|---|---:|---|---|---|
| `Sounds/VOICE` (231 Russian lines; `.wav` in root, `.ogg`+`.wav` in `RUSSIAN/`) | 65 MB | `Sounds/VOICE/*.wav`: 860 lines | same names `Eng_m_a_001…`; PCM 22 050/16/mono (like our `.wav`); `Greetings_alias.ini` references 388 of 395 names | **122.5 / 98.6 MB** (gzip -6; br -q9: 96.3; speech PCM barely compresses) |
| `Textures/Loading/Russian` (137 files) | 71.8 MB | `Textures/Loading` (129 files) | same `.tx` format (R5G6B5, 512², 524 312 bytes); 127 matching names; 10 Russian files have no English pair (common utility screens: `bgd`, `initialization`, `loading`, `save_game`, `storm`, `twister`…): retain Russian for these | **67.4 / 29.6 MB** (br 28.7) |
| `Textures/WorldMap/reload/Russian` (4) | 2.1 MB | `WorldMap/reload` (4) | same | 2.1 / ≈1 MB |
| `VIDEOS/Russian/Invasion.wmv` → `videos/Russian/Invasion.mp4` 9.2 MB | 25.9 MB | `VIDEOS/Invasion.wmv` 26.1 MB | WMV2/WMA2 640×384, like others; converted by same ffmpeg (h264 ≈0.9 Mbit/s + aac, estimate **≈9 MB**) | not OPFS (HTTP stream) |
| `*rus*.tga.tx` fonts | — | **same files** | English uses `rus` textures (verified via `fonts_eng.ini`); no new bitmap needed | 0 |
| `potc_logo_rus`, `load_rus`, `new_game_rus` | — | `potc_logo`, `load`, `new_game` **already exist** in our release | chosen via `LanguageGetLanguage()`/`LANG` | 0 |
| `TEXTS/RUSSIAN`, `fonts.ini` | — | `TEXTS/ENGLISH`, `fonts_eng.ini` **already exist** | only `language.ini`/`fonts.ini` substitution required | ≈20 KB |

English layer total: **≈194 MB raw in OPFS, ≈130 MB transferred (gzip)**, plus ≈33 MB of videos (Credits ≈20, Invasion ≈9, three logos ≈4; estimate based on 0.32 mp4/wmv ratio in already converted videos). Texts: PROGRAM overlay 236 files, 1.36 MB raw / 0.35 MB gzip. In English mode Russian resources (`Loading/Russian` 72 MB, Russian voice 65 MB) remain installed until layers are separated (≈100 MB gzip saving for an English-only user is a possible E6; it changes the Russian manifest, so it is outside E1–E5).

`Textures/tips` (78 textures, 40.9 MB): `engine.ini numoftips = 0` in both versions, no references; not needed.

## 5. Non-language benefits

* **Missing references** (`audit_refs.mjs`: 192 missing: 148 sounds, 16 textures, 10 models, 10 portraits, eight animations; `known-mines.json` also has 192): the US edition **contains 145 of 148 sound aliases** (all `VOICE\{Dut,Eng,Fre,Ita,Por,Spa}_*.wav`, 23.2 MB; `foutain.wav`, `widmill.wav`, `hit_toground.wav` absent). **Also absent:** `Characters/none.gm`, `Heads/capitan.gm`, `h_monkey/h_mummy/h_none/h_skel1–4.gm` and their animations, `Ships/Fort/Fort.gm`, 16 cosmetic textures, portraits 47–51. Thus the US edition resolves “40 references/192 missing” only for voices, not models (these were dead in the original too). `h_Offic_hol` is also absent there (`eng/fra/por/spa` exist). These 145 voices are English too: **they cannot be enabled in Russian mode without the user's decision** (Russian voice has 231; other lines are intentionally silent).
* **Videos** (absent from the Russian release, video bridge operates fail-open): `Credits` (the menu “Credits” button currently has no effect), `WaltDisneyLogo`/`BethesdaLogo`/`AkellaLogo` (game startup, `seadogs.c:226–242`). Bethesda/Disney logos are inappropriate for the Russian 1C version; their use in English mode is a user decision. `sunrise`/`intro` are also absent from US.
* **`WIN FIX`: `MODULES/sea.dll`** (196 608 bytes, 24 August 2012, CRC-32 `d6a3c788`). Both games' `sea.dll` is `66236c2b` (byte-identical). This is the water module (`sea.dll`) and contains an **unknown substantive fix**, so comparing it to `historical diagnostic materials (removed)` / `historical diagnostic materials (removed)` is reasonable. **Not extracted** (task restriction: listing only); comparison only requires extraction into scratchpad and a static binary diff without execution: **user permission required**.
* `MODULES`: US `DIALOG.dll` and `DX8RENDER.dll` differ from Russian (≈49 KB and ≈203 KB of bytes at equal sizes: different builds); the other 101 `.dll` files match. The port was recompiled from Russian; US modules are unnecessary.
* US 1.0 scripts contain no fixes absent from Russian (Russian is newer for all 36 changed files).

## 6. E1–E5 plan (overlay layer)

### Chosen architecture

```
OPFS:  korsary2-game/      (as now; Russian release, manifest unchanged)
       korsary2-game-en/   (NEW directory: English-layer files only, its own manifest.json)
Page:  language choice -> sync base directory (as now) [+ sync English layer] -> start wasm with ENV PORT_OVERLAY=/opfs/korsary2-game-en
Host:  map_path(): for paths under the game root, first look for a file in the overlay directory, otherwise in the base
Language: RESOURCE/INI/TEXTS/language.ini IS IN THE OVERLAY (defaultLanguage = English); base manifest and its SHA are untouched
```

Rejected: (a) a second **full** installation (+2.4 GB); (b) “materialization” (copy English files over base in OPFS and retain backups), which breaks `resync`/SHA/`version` and is unsafe on interruption; (c) editing `language.ini` in place, which is in `files.required` and the manifest with SHA; (d) rewriting the manifest on the fly, which confuses preflight/dist; (e) rebuilding wasm for English.

Russian mode: `PORT_OVERLAY` unset → `map_path` follows previous code (overlay branch skipped); the page does not request `game-en/…`; `manifest.json`, `version`, and Russian release hashes remain byte-for-byte unchanged. The English layer is served by the same packer (D1/D1b/D3: `gzip`/`br`, `_k2pack` packs), built as a **separate manifest** `game-en/manifest.json` from the overlay directory.

### E1 — framework: host overlay, second directory, switch (≈4 days + 1 day coordination)

Scope:
1. **Host** (`host/core.c`, `main.c`; files owned by another agent: request via handles/K1b): `PORT_OVERLAY` (modeled on `PORT_USERDATA`, `main.c:111`) → `g_overlay_root`; in `map_path`, before `base = g_game_root`, try `g_overlay_root/<rest>` with the same `find_ci`/CP1251 logic; applies **only to reads** under `PROGRAM/` and `RESOURCE/` (`SAVE/`, `options`, `engine.ini` always use base). Directories: merged base/overlay listing (`FindFirstFile`) where overlay adds files (`VOICE`); synthetic-tree tests modeled on `test_file_share*.c`.
2. **Page** (`web/index.html`, `port.js`): “Русский / English” selection (default Russian), `?lang=en`, persisted in `localStorage` (`korsary2.lang`; read/write in try/catch); for English a second `syncFromServer` into `korsary2-game-en` with its own installation marker/version; block launch until fully synchronized (partial layer cannot launch); display size (“+≈130 MB”), estimate quota (existing `storage-estimate`), and block switching during play and with two tabs (shared lock exists).
3. `make_dist.py`/`serve.py`: layer option (`--overlay-dir`, output to `game-en/`), same manifest schema (`enc`, `pack`, `version`).
4. Layer stub for tests: one `language.ini` with `English` + `STRSERVICE` check in Node build.

Dependencies: none (parallel with E2). Risk: medium (`map_path` is common to all files; K2 strict-mode file identity uses host path, which differs for the overlay; merged-listing errors). Completion criteria: (1) Node tests: without `PORT_OVERLAY`, `map_path` result for 100 000 random paths is byte-identical to previous behavior; (2) with overlay: priority, case, CP1251, `..`, missing file → base; (3) Russian `verify_dist` unchanged; (4) Node tests of language selection and unchanged Russian manifest; (5) interrupted layer download → English launch forbidden, Russian works.

### E2 — English text layer: `tools/prepare_english.mjs` (≈4 days)

Scope (following `prepare_game.mjs`: source read-only, new `--out` directory, SHA pin, idempotence, `expected-manifest-en.json` reference):
1. Input: **US image(s)** (`--us-iso`, single or Disc 1+2) + working Russian copy (`--ru-game`). Embed InstallShield reader (`isoread/ishield`) without external dependencies; extract only `PROGRAM`, `RESOURCE/INI`, `QUESTSTEXT`.
2. Literal alignment (`align_overlay.mjs` → module): `DIALOGS/*.h` by indexes/`.c` skeleton, other scripts by lines; **safety checks**: code skeleton after replacement equals Russian, literal counts match, format specifiers match; reject violations.
3. `Characters_names.c` entirely from US; `language.ini` (`English`), `fonts.ini` ← copy of base `fonts_eng.ini` (check: SHA equals US `fonts.ini`); `TEXTS/ENGLISH/*` from US + new keys.
4. **Manual layer** (≈125 lines, section 3.6): separate project data `english-layer/manual-strings.json` (agent/user writes English text; it **contains no** copy of US text); substitute by (file, index/key), protect patch 04 (port) lines from automatic transfer.
5. Quests: `overlay_quests.mjs` → module; 22 `kill_*` from the manual layer.
6. Reference: output file list, sizes, SHA-256; check on every run; tests on a synthetic mini-image (synthetic `ISc(` volume with several files).

Dependencies: only reader needed (ready). Risk: medium: alignment of 10 `COUNT_NE` files was checked statically, **not visually** (line length and wrapping within the dialogue frame). Completion criteria: `prepare_english.mjs --check` passes on my run; 236 `PROGRAM` files + `QUESTSTEXT` + `TEXTS` match the reference; zero Russian literals outside the “remains Russian” list (≈90 lines pinned in the reference); Russian release unchanged (`--ru-game` read-only). Live agent checks Latin in dialogues/interface using Russian `rus` fonts, dialogue frames and quest journal, and `WARNING: language ini files has different size` in `system.log`.

### E3 — graphics and videos (≈3 days)

1. Loading screens: 127 English `Loading/*.tga.tx` + 4 `WorldMap/reload/*.tga.tx` (same names in overlay; 10 unpaired Russian screens remain from base); screens with `load.tga` already branch to English on `LanguageGetLanguage()=="English"` in `seadogs.c`.
2. Videos: `Invasion` (English voice) → `videos-web/en/Invasion.mp4`; `Credits` → `videos-web/Credits.mp4` for English; logos **subject to user decision**. Video bridge looks for `resource\videos\<name>.wmv` (`RE_VERDICT.md`); overlay needs a language prefix in `video-player.mjs` (`videos/<lang>/<name>.mp4` → `videos/<name>.mp4`), with no changes in Russian mode.
3. Convert using the same ffmpeg recipe as the existing 11 videos (640×384, h264 ~0.9 Mbit/s, aac).

Dependencies: E1 (overlay). Risk: low; videos are outside OPFS. Criteria: layer SHA-256 in reference; `prepare_english.mjs` writes both sets; Node video-bridge test selects path by language. Live agent checks loading screens, “Credits,” and English `Invasion`.

### E4 — voices (≈2 days)

1. Put 860 US `.wav` files in overlay `RESOURCE/Sounds/VOICE/`; the 231 Russian files in root `VOICE` are overridden by same-name US files in English mode. Use the **Russian** `Greetings_alias.ini` (contains all 1.03 sections; 388 of 395 references resolve). `.wav` files are original PCM; **no conversion from `.ogg` is required** (D2: Russian `.wav` files are derivatives; US `.wav` files are originals). Check size ≥45 bytes (`min_sibling_bytes`) and RIFF header.
2. At 98.6 MB gzip, this is the heaviest part. Option E4b (+2 days): transfer `.ogg` (≈12 MB) and decode via `WebAudio decodeAudioData` → PCM `.wav` in OPFS during installation (more code and risk; user decision).
3. Tests: all active `name=` aliases in `Greetings_alias.ini` resolve against overlay + base (reference list: 388 of 395, seven known missing).

Dependencies: E1. Risk: medium: English voices do not accompany Russian subtitles (English mode uses English text), but seven missing references stay silent as in the US original. Criteria: layer reference, alias-resolution test, and no `SoundService` exceptions on new paths (live).

### E5 — acceptance, preflight, saves, documentation (≈3 days + live acceptance)

1. **Preflight** (`web/missing-resource-preflight.mjs`): language-independent `fatal` list and `KNOWN_*` unchanged (models/music are neutral); leave `MUTABLE_PATHS` alone; add layer mode to verify required overlay files (`language.ini`, `fonts.ini`, `quests_texts.txt`) against `game-en` manifest and warn, not refuse, for the rest. Russian code runs as before.
2. **`prepare_game.mjs`**: unchanged (Russian release). New `prepare_english.mjs` is separate; common parts (image reader, SHA pin) go into a common module **without changing `prepare_game.mjs`** until its owner (N6/N11) releases the file.
3. **`verify_dist`**: validate second manifest with same code (`--overlay game-en`), check layer `version`/SHA and no overlap with `SAVE/`, `options`, `engine.ini`.
4. **Saves**: slots are shared (`SAVE/`). Dialogue/quest/item keys are language-neutral (quest journal stores `idText`, fetching text from `QUESTSTEXT` on display), but **NPC names and titles set when starting a game (`Characters/init`) are saved in the slot in the creation language**. Switching is allowed, but old slot names remain Russian: show slot language in list (`SAVE_META`: `lang` field, written by page/host; format extension subject to `save-protection.mjs` owner's approval), warn when loading a slot in another language. Recommendation: choose language before “New game”; **do not create separate language slot sets in E1–E5** (they change `SAVE/` structure).
5. Automated tests without live game: E1–E4 + dry integration (Node build with `PORT_OVERLAY`, Russian and English `language.ini`, read `common.ini`/`quests_texts.txt`/dialogue, stub `LanguageGetLanguage`); Russian regression: SHA of all Russian manifests unchanged, `diff -rq` of the `prepare_game.mjs` tree empty.
6. Documentation: `docs/english-layer.md` (reproduction, layer format, limitations).

Live acceptance (another agent, separate origin and test slots, no user saves): English interface/items/help; key NPC dialogues (Blaze, Malcolm, Danielle, merchants): no Russian lines outside the “remains Russian” list; quest journal; loading screens; greeting voices; videos; RU→EN→RU switch without leftovers; two slots in different languages; `system.log` without `Language … not exist` / `different size`; Russian regression (loading screens, voices, Invasion video).

### Summary table

| Stage | Scope | Days | Depends on | Risk |
|---|---|---:|---|---|
| E1 | host overlay, second OPFS directory, switch, `make_dist --overlay-dir` | 4 (+1 coordination) | — (host owner) | medium |
| E2 | `prepare_english.mjs`, texts, manual layer | 4 | reader (available) | medium |
| E3 | loading screens, map, videos | 3 | E1 | low |
| E4 | voices | 2 (+2 ogg→wav option) | E1 | medium |
| E5 | preflight, verify_dist, saves, tests, documentation | 3 | E1–E4 | medium |
| **Total** | | **16** (+2) | | |
| Live acceptance | another agent | 1–2 sessions | E5 | — |

Order: E1 ‖ E2 → E3 ‖ E4 → E5 → live acceptance.

## 7. Tests without a live game and work for the live agent

Automated: (1) `map_path` without/with overlay (native C); (2) page: language selection, `localStorage`, unchanged manifest (Node); (3) `prepare_english.mjs` on a synthetic mini-image; (4) layer reference (SHA-256, sizes); (5) resolution of all voice aliases; (6) code skeleton after replacement; (7) `verify_dist --overlay`; (8) Russian regression. Live agent: everything requiring rendering (Latin in `rus` fonts, dialogue/journal/interface layout, wrapping), audio, videos, loading screens, `STRSERVICE` with missing key, inter-tab behavior.

## 8. Impact on preflight, `prepare_game.mjs`, `verify_dist`

* `missing-resource-preflight.mjs`: Russian mode unchanged (`test_missing_resource_preflight.mjs` tests unchanged). English adds only overlay-file presence checks (nonfatal except `language.ini`).
* `prepare_game.mjs`: unchanged; `prepare_english.mjs` is a new tool with the same contract (read-only source, new directory, `--check`, pins).
* `verify_dist`: adds `game-en/manifest.json` validation; Russian validation remains the same. `expected-manifest-en.json` is a separate reference; Russian reference unchanged.
* `port.json`: `files.include` unchanged; English layer needs its own `port.json` equivalent (`port-en.json`?) only for packer `exclude_*` rules (overlay → include everything).

## 9. Risks

| # | Risk | Mitigation |
|---|---|---|
| 1 | US 1.0 predates 1.03: some code/lines differ | Replace only literals with skeleton checks; remaining ≈125 lines manually; do not take code from US |
| 2 | Unmatched lines | Reference list; Russian remains pending a decision; `known_untranslated` in `manual-strings.json` |
| 3 | Saves between languages | NPC names remain in creation language; slot-language label; recommend choosing before “New game” |
| 4 | Russian-mode regression | Overlay off by default, `map_path` branch not executed; manifest SHA and 100 000-path test |
| 5 | Mixed state (English text + Russian voices/loading screens with incomplete layer) | Start English only with fully synchronized layer; atomic marker |
| 6 | Line length/layout (eight captions 1.6× longer, dialogue wrapping) | Live acceptance; same font in US, where it worked |
| 7 | Legal aspect | Overlay built from user images; nothing from them in Git; publication deferred by user (R6) |
| 8 | `FindFirstFile` union and strict-mode file identity | E1 tests; host owner coordinates (`host/*.c` is not ours) |
| 9 | English layer size (+130 MB) and OPFS quota | Second directory downloaded only when English selected; quota export and “tight/insufficient” text already exist |
| 10 | PCM voices do not compress well | E4b: ogg + decode at installation (optional) |
| 11 | `STRSERVICE` behavior with missing key (not tested) | 14 missing keys covered by manual layer; live `system.log` check |
| 12 | Base `TEXTS/ENGLISH` (identical to US) may change in a future Russian update | Overlay stores its own copies of mutable files (`common.ini`, `ItemsDescribe.txt`) |

## 10. Decisions needed from the user

1. **Start E1–E5?** If so, full scope (text + voices + loading screens + videos) or text first (E1+E2: ≈8 days, ≈0.4 MB layer)?
2. **Source of translation for ≈125 lines** (section 3.6): agent writes (machine/own translation) with user proofreading, or leave Russian (mixed mode)?
3. **Bethesda/Disney/Akella logos** and Credits video: show in English mode? Not in Russian by default.
4. **Voices in Russian mode:** fill 145 silent lines with English voices (mixed language), or leave silent?
5. **Delivery:** one distribution with both languages and optional layer (recommended), or two separate variants; **publish the English layer?** (legal question R6 remains deferred).
6. **Saves:** shared slots + language label (recommended), or separate slot sets by language.
7. **Voices:** 98.6 MB gz as-is, or E4b (ogg ≈12 MB + decode at install).
8. **`WIN FIX` `sea.dll`:** allow extraction into scratchpad and static comparison with ordinary `sea.dll` (water)?
9. Is including US `Characters_names.c` acceptable (English name lists: Russian has 45, US 670 literals)?

## 11. Reproduction and limitations

Scripts (`english-audit/`, Node.js; images read-only):

| File | Purpose |
|---|---|
| `isoread.mjs` | ISO9660/Joliet reader, 2048- and 2352-byte sectors (`ls`, `tree`, `cat`, `extract`) |
| `ishield.mjs` | InstallShield 6: `LIST`, `EXTRACT <regex>` directly from image |
| `compare_inventory.mjs` | compare RU/US file inventories → `results/inventory` |
| `compare_dialogs.mjs` | dialogues, classes `IDENT/COUNT_NE/…` → `results/dialogs` |
| `compare_scripts.mjs` | all scripts: `BYTES_EQ/TEXT_ONLY/CODE_DIFF` → `results/scripts` |
| `compare_texts.mjs` | `TEXTS`, `QUESTSTEXT` by key → `results/texts` |
| `align_overlay.mjs`, `verify_overlay.mjs`, `overlay_quests.mjs` | transfer prototype and verification (`--emit` writes game text: only outside repository) |
| `scan_encoding.mjs` | byte counters ≥0x80 |
| `run_all.sh` | full run: `sh english-audit/run_all.sh <ru-game> <us-iso> <workdir-outside-repo>` |

`run_all.sh` takes ≈1 minute, writing only names/counts to `english-audit/results/`; extracted data (≈14 MB) is deleted.

Not tested: `STRSERVICE` behavior on a missing key; Latin rendering with `rus` fonts and layout (only static: `fonts.ini` and textures match US); `WIN FIX` `sea.dll` contents (CRC only); substantive US `ENGINE.exe`/`MODULES/*.dll` analysis (only version, date, equality/difference); mp4 sizes are estimated from existing ratios. Images were not mounted; `hdiutil info` contains none of the user's images.

## 12. Audit corrections following E2–E5 and W1 (12 November 2026)

The audit (E0) was an estimate before building. What the build and real-data tests changed; **the information here and in `docs/english-layer.md`, `docs/english-layer-assets.md` is authoritative** (sections 0–11 above are retained as they were).

| Audit location | Before | After (source) |
|---|---|---|
| §0.4, §2, §4 (total): layer size | ≈194 MB raw / ≈130 MB network | **762 files, 118.9 MiB raw (124.7 MB), ≈71 MiB gzip-6 / 69.5 MiB brotli-9**, 8.75 MiB video over HTTP; −39% / −45% because dead lines are not installed (E3/E4 §1) |
| §3.4, §4, E4: “860 voice lines placed in layer” | all 860 | Game requests only **393** (467 lines, 65.6 MB, are not referenced by any alias/script in either Russian or US); `--voice-scope all` includes all 860 (E4 §5.2) |
| §3.6/§4 (D2): “game reads pairs `VOICE\x.wav` and `VOICE\Russian\x.wav`” | override `VOICE/RUSSIAN` | `.lng` with `VOICE\Russian\…` paths are **not loaded** by anything; `VOICE/RUSSIAN` is not read and need not be overridden (E4 §5.3) |
| E4.1: “`Greetings_alias.ini` comes from Russian” | Russian | **US**: the Russian release renumbered line names for its recordings in 37 of 191 sections; with Russian aliases two greetings would remain Russian; all parameters except `name` match (`alias_compat` check) (E4 §5.4) |
| §2/§3.3/E2.3: `fonts.ini` “== our `fonts_eng.ini`, replace entirely” | US file | `fonts_eng.ini` **predates 1.03**: missing `[DIALOG21]` (required by `INI/dialog.ini`), `[INTERFACE_SMALL]`, `pcscale`. Layer: **base 1.03 with one replacement**, `Texture = fonts\menu font.tga` in `[INTERFACE_TITLE]`; US title font contains only uppercase `A–Z` (E2 §1.5, §4) |
| §3.6: Malcolm tutorial, seven lines | 7 | **8** (indexes 8, 34, 36, 48, 50, 54, 157, 235) (E2 §5) |
| §3.6, §0.3: ≈125 manual lines | ≈125 | **143 translated** (+15 lines of 1.0→1.03 semantic drift in `AbilityDescribe`/`ItemsDescribe`, three Xbox console lines, two shortenings) + two alignment corrections; automatically 11 111 literals, 670 names, 401 quest entries, 662 interface values; **187 literals remained Russian** (≈110 visible to players; `Enc_Rapers*` is a random encounter) (E2 §3, §5, §6) |
| E2: “alignment by index” | everywhere | US files `Douwesen Soldier_Dialog.h` and `isla muelle soldier_dialog.h` are one line shorter: shift 23–27 corrected by `pairs`; empty quest title `resque_researcher#0` in US file; `%%` at moneylender (E2 §5) |
| E3: “127 English `Loading/*` + 4 `WorldMap/reload/*`, 10 unmatched Russian remain” | 127 + 4 | US `Loading/*`: **129** (128 × R5G6B5 + `progress` DXT5); 122 in layer, seven equal to base (upper English screens, `Falaise_de_Fleur_Townhall`); of 132 script-requested names, 125 covered in English; remaining seven are English/utility (E3 §3.1–3.2) |
| §4, R1 §3.2: `WorldMap/reload/Russian` “never requested” | not requested | **Requested** by `worldmap_reload.c` (`WorldMap\reload\sea|Battle|Storm|Twister.tga`); Russian release had files only under `reload/Russian/` and they were not published (Russian-mode defect). **W1:** second `relocate_if_absent` rule in `port.json`; English layer overrides these names (E3 §3.3, `docs/english-layer-assets.md`) |
| §4, E3: videos | Credits, Invasion, three logos | 11 of 16 US videos are byte-identical to Russian; `Invasion` differs → `videos/English/Invasion.mp4` (WMV2/WMA2 → H.264/AAC 640×384, 8.75 MiB, reproducible with ffmpeg 9.0.2); `Credits` and three logos are not shown in English mode (user decision; `EN_SKIP`) (E3 §6) |
| §4: `INI/INTERFACES`, `items1`, `BuySellFlags`, `potc_logo` | “check” | **Not taken**: 1.0→1.03 differences (exit button, icons, layout), not language; engine itself chooses logo and `* rus` fonts via `defaultLanguage` (E3 §4) |
| E5 “live acceptance = everything else” | plan | **Done in E5** (`docs/english-layer.md`, section 11): unified required-file list, layer preflight, `verify_dist --overlay`, `VIDEO_FILES_EN`, slot-language label (sidecar `.lang`), nonblocking notification for slots in another language; live acceptance remains (section 12 of same document) |
