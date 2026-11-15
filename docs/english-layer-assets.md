# English resource layer (E3 + E4): loading screens, world map, voice, video

> Historical report: recorded tool names and commands describe the versions used for the original investigation. For the current Node.js development workflow, see [Development after cloning](BUILD_FROM_CLONE.md).

Date: 12.11.2026. Author: E3/E4 agent. Status: **ready** (build, baseline, tests, format verification); **not checked live** (screen display, sound, video, layout).
Continuation of `docs/english-layer.md` (E2, overlay contract §1) and `docs/english-sources-audit.md` (§4, §6 E3/E4). User decisions: implement all English at once; one distribution with
an optional English layer; Bethesda/Disney/Akella logos and Credits video are not shown in English mode; voice “as is” (E4b — `.ogg`→`.wav` transcoding at installation — was not implemented, §5.7);
Russian mode unchanged byte for byte.

## 0. Overview

`tools/prepare_english.mjs` now builds, in **the same overlay directory**, in addition to text (242 files), **resources: 122 loading screens, 4 world-map screens, 393 lines, 1 alias file**, and
separately (outside the overlay) the video `English/Invasion.mp4`. Total **762 files + `OVERLAY.json`, 118.9 MiB raw (124.7 MB), ≈ 71 MiB over the network (gzip-6) / 69.5 MiB (brotli-9)**, video 8.75 MiB over HTTP.
Build ≈ 10 s, deterministic (two runs from different images — empty `diff -r`, video byte-identical), all pins and hashes in `english-layer/expected-overlay.json` (no US content there).
Russian files, their manifest and SHA-256 are unchanged; Russian mode is unaffected byte for byte.

Main findings (details in sections):

1. **Voice: of 860 US `.wav` files, the game will ever request only 393** (the remaining 467 — 65.6 MB — are referenced by no alias/script in either Russian or US version). By default the layer includes
   393 (54.3 MiB instead of 116.9 MiB); `--voice-scope all` includes all 860. The game **never reads** `Sounds/VOICE/RUSSIAN` (§5.3), so it need not be overlaid (flag exists, off by default).
2. **Russian greeting aliases are renumbered** for Russian recordings (37 of 191 `Greetings_alias.ini` sections point to different files than US). The layer includes the **US `Greetings_alias.ini`**
   (sections and all parameters except `name` equal Russian — verified), so in English mode **no requested line remains Russian** (with the Russian alias, 2 remained) (§5.4).
3. **World-map `WorldMap/reload/*` is requested by a script** (`PROGRAM/WorldMap/worldmap_reload.c`: `sea`, `Battle`, `Storm`, `Twister`), contrary to `docs/loading-screens-and-music-r1.md` §3.2 (“not requested by anything”);
   in the Russian distribution they exist only under `reload/Russian/` and **were not published** (`relocate_if_absent` covered only `Loading/Russian`) — a RUSSIAN-mode defect (§3.3). **Fixed in W1 (12.11.2026): second rule in `port.json`**
   (`reload/Russian` → `reload`); Russian world-map screens are now published where the game opens them, and the English layer overlays them (`base` entry, not “overlay-only file”); figures below account for this.
4. **Loading screens:** English covers 125 of 132 requested names; the remaining 7 are English/utility base files at the top level (nothing Russian remains) (§3.2).
5. **Other language-related resources** (interface INI, `items1`/`icons`/`BuySellFlags`…, font and logo textures): **not included in the layer** — differences between 1.0 and 1.03 (mechanics, layout), while the engine itself selects
   language-dependent logos/fonts (§4).
6. **Videos:** only `Invasion` differs in English (other 11 are byte-identical); Credits and three logos are excluded. The bridge needs the language: **`port.js` patch** `english-layer/PAGE_PATCH_video-lang.patch`,
   `video-player.mjs` ready (§6).

## 1. Layer contents

Baseline: `english-layer/expected-overlay.json` (source pins, sizes, SHA-256 of each file, counters, E2 “remaining Russian” list). Calculated from real images and real working copy `korsary2-next/game`.

| Class | What | Files | Bytes | MiB | gzip-6 | brotli-9 |
|---|---|---:|---:|---:|---:|---:|
| `loading` | `RESOURCE/Textures/Loading/<name>.tga.tx` (R5G6B5 512×512, 1 mip) | 122 | 63 966 064 | 61.00 | 26.86 | 26.06 |
| `worldmap` | `RESOURCE/Textures/WorldMap/reload/{Battle,sea,Storm,Twister}.tga.tx` | 4 | 2 097 248 | 2.00 | 0.93 | 0.90 |
| `voice` | `RESOURCE/Sounds/VOICE/*.wav` (PCM 22050/16/mono) | 393 | 56 948 080 | 54.31 | 43.10 | 42.13 |
| `aliases` | `RESOURCE/INI/ALIASES/Greetings_alias.ini` | 1 | 27 936 | 0.03 | ≈ 0.01 | ≈ 0.01 |
| text (E2) | `PROGRAM/**`, `RESOURCE/INI/**`, `QUESTSTEXT` | 242 | 1 616 294 | 1.54 | 0.43 | 0.40 |
| **overlay total** | | **762** | **124 655 622** (+ `OVERLAY.json` 64 451) | **118.9** | **71.3** | **69.5** |
| video (outside overlay) | `videos/English/Invasion.mp4` | 1 | 9 172 106 | 8.75 | — (mp4) | — |

(gzip — zlib level 6 per file + 18 B header, like port `PACK_LEVEL`; brotli — CLI `-q 9`, port's `-q 11` saves a few more percent; voice compresses little, 16-bit textures by half.)
All 570 files overlaying the base have an `OVERLAY.json: base` entry (SHA-256 of the **published** base file: for files relocated from `Loading/Russian` — SHA of Russian file under `Loading/<name>`); verified against
`recomp/web/gamefiles.game_files(korsary2-next/game)`: 570 `base` entries (242 text + 122 + 4 world map (W1) + 201 + 1), 0 missing, 0 incorrect SHA, all path spellings match base. **192 overlay-only files** (192 voice lines)
have no `base` entries (before W1: 196, including 4 more world-map screens). All paths are under `RESOURCE/` or `PROGRAM/`, no case duplicates, longest path 62 characters (`RESOURCE/Textures/Loading/Quebradas Costillas_Town_Exit.tga.tx`).

Change from E0 audit (194 MB raw / 130 MB gzip for entire layer): **−39% raw and −45% network**, because dead voice lines are not installed (§5.2).

## 2. Reproduction

```
node korsary2-next/tools/prepare_english.mjs --base korsary2-next/game \
    --us-iso "…/Pirates of the Caribbean (Disc 1 & 2)/… (Disc 1).iso" "…/… (Disc 2).iso" \
    --out <NEW directory> --video-out web-port/videos-web                        # ≈ 10 s; --video-out = page video directory
node korsary2-next/tools/prepare_english.mjs --check --out <directory> --base korsary2-next/game --video-out web-port/videos-web    # verify against baseline
node korsary2-next/tools/prepare_english.mjs --check --base korsary2-next/game --us-iso … --video-out …                          # in-memory rebuild
```

New options (E2 behaviour without them unchanged: resource classes enabled only if present in the US source; `--text-only` = old behaviour):

| Option | Meaning |
|---|---|
| `--skip-loading` | omit `Textures/Loading` and `WorldMap/reload` |
| `--skip-voice` | omit voice and `Greetings_alias.ini` (for a user without space; US voice needs no `ffmpeg` — files already PCM `.wav`) |
| `--skip-video` / `--video-out DIR` | video built only with `--video-out` (needs `ffmpeg`, `ffprobe`; `--ffmpeg/--ffprobe` specify paths); without ffmpeg, warning with ready command, not an error |
| `--text-only` | text layer E2 only (same as all three `--skip-*`) |
| `--voice-scope referenced\|all` | default `referenced` (393 lines); `all` — all 860 (116.85 MiB) |
| `--keep-ru-greetings` | Russian `Greetings_alias.ini` instead of US (2 greetings remain Russian) |
| `--voice-russian-dir` | additionally `VOICE/RUSSIAN/<name>.wav` (+201 files, +25.9 MB; game does not read this path) |
| `--port-json` | `port.json` with `relocate_if_absent` (default `korsary2-next/port.json`) |

Sources are read-only: text into memory, resources **on demand** from the image (InstallShield, nothing extracted to disk; ≈ 300 MB in memory at once). Refusal on nonempty `--out`/`--video-out`
(a video with different contents is not overwritten without `--force`), `--out`/`--video-out` inside base/source/each other. Pins: `us_files_digest` (E2) + per-class `us_digest` (path, size, SHA-256 of all US class files,
including those not taken into the layer) and `base_digest` (path and size of base files); video has WMV SHA-256 and ffmpeg version. `--check` with `--skip-*` does not require skipped classes (and does not compare `OVERLAY.json`, whose `base` binding depends
on the class set; binding is checked by `verify_payload` against the base).

## 3. E3-a: loading screens and world map

### 3.1 Name matching and format

* US `Textures/Loading/*`: **129** files (one directory, 128 × R5G6B5 512×512 + `progress` DXT5 512×512), all `.tga.tx`, no case duplicates. Russian distribution: 17 files at top level + 137 in `Loading/Russian/`.
* **Names match without adjustments:** 127 US names exist in `Russian/` (case rarely differs — path and spelling taken from base file), 2 (`load_game`, `progress`) only at top level; `Russian/` has 10 files without US counterparts
  (`Bgd`, `House_01`, `Loading`, `Loading_Game`, `Save_Game`, `Storm`, `Twister`, `initialization`, `lost_controller`, `low_storage`).
* **`.tx` headers are structurally identical** (24 bytes `<6I`: flags 0, 512, 512, 1 mip, `D3DFMT_R5G6B5`=23, size 524 288; then 524 288 data bytes = 524 312 B; `progress` — DXT5, 262 168 B). For each file the build requires
  **the same format, dimensions and mip-level count as the base file of the same name** (for new files, `reload/Russian/<name>`), and refuses a mismatch (“loader would not accept it”), incorrect file size according to header, or unknown format. The
  `tx` check (`english_assets.parse_tx`, mirrors `english-audit/tx2png.mjs` parsing): all 126 layer files passed — 122 `R5G6B5 512x512 mips=1`, 4 world-map files as well. `host/texconv.c` converts R5G6B5 for loading, the same format as Russian.
* Byte-identical to the base and therefore **not included**: `load`, `load_game`, `new_game`, `options`, `start_loading`, `progress` (base top level — already English screens, also seen by player in Russian mode) and `Falaise_de_Fleur_Townhall`
  (Russian file byte-identical to US). Total: 129 US = **122 in layer + 7 equal to base**.
* Overlay path is the **published base path** (`Loading/<name>`, `relocate_if_absent` rule from `port.json` repeated in `english_assets.relocations`, 0 differences from `gamefiles.game_files`). The overlay
  covers both top-level files and relocated Russian `Russian/*`.
* What visual PNG inspection showed (`english-audit/tx2png.mjs`): `Tavern_01` — “Tavern / Loading…” versus “Таверна / Подождите, идет загрузка…” (Tavern / Please wait, loading…) on the same picture; `Sea`, `Fort_02`, `Jungle`, `Townhall`, `Maze`, `Animist`s Lair`, `Isla Muelle`…
  (sample of 20 layer files) — English area label and “Loading…”, no Russian text.

### 3.2 Coverage of requested names

Scripts request 132 names `loading\<name>.tga` (R1 counted 131 + utility; here all `PROGRAM` literals). **125 are covered in English.** 7 remain from base, all without Russian labels:

| Name | Base source | Appearance |
|---|---|---|
| `initialization`, `lost_controller`, `low_storage`, `save_game` | top `Loading/` | English/neutral screens (“Initialization. Please, wait.”, “Please reconnect the controller…”, “Low storage…”, “Saving Game”) — English on PNG, as the player sees them |
| `load_rus`, `new_game_rus` | top `Loading/` | Russian “Корсары II” (Sea Dogs II) screens with “LOADING GAME”; **used only when `LanguageGetLanguage()=="Russian"`** (`seadogs.c:359-362, 596-599`), English mode uses `load`/`new_game` (English, equal to US) |
| `InkasHram` | nowhere | dead reference in `location_init.txt` (nobody loads the file) |

Russian “Russian/Bgd”, “House_01”, “Loading”, “Loading_Game”, “Storm”, “Twister” **are not requested by scripts** (no `loading\…` literals); `Storm`/`Twister` in `Textures/Loading` are not the world-map files (§3.3).

### 3.3 World map `WorldMap/reload` and Russian-mode defect

`PROGRAM/WorldMap/worldmap_reload.c` constructs `WorldMap\reload\sea.tga` (`Battle`, `Storm`, `Twister` depending on situation). In the Russian distribution files exist only in `reload/Russian/` (4 × 524 312 B, Russian labels “Море/Сражение/Шторм/Смерч” (Sea/Battle/Storm/Twister)), absent in `reload/`
and `relocate_if_absent` did not relocate them: **the Russian-mode world-map transition screen was probably empty** (same mechanism as `Loading/Russian` before R1).
**W1 (rechecked from code and data, not reports):** `worldmap.c` includes `worldmap_reload.c`; `wdmReloadToSea()` sends `FADER_PICTURE` with `WorldMap\reload\sea.tga|Battle.tga|Storm.tga|Twister.tga`; renderer opens
`resource\textures\<name>.tx` literally (R1 §3.3, no language substitution); working-copy `reload/` contains only `Russian/` (4 files). Thus R1 §3.2's “not requested by anything” was wrong (R1 searched only `loading\…` literals and image strings).
A second rule `{"from": "RESOURCE/Textures/WorldMap/reload/Russian", "to": "RESOURCE/Textures/WorldMap/reload"}` was added to `port.json` (and `web/port-config.js`, same text `tools/configure.mjs` would write); same bytes published under `WorldMap/reload/<name>.tga.tx`
(9826 files as before, no name collisions, 4 files relocated); Russian manifest changed, installed players retain old `reload/Russian/*` as extras (≈ 2 MB), as in R1. US `reload/*` (“Sea/Battle/Storm/Twister” + “Loading…”) are now **overlaid**
under these names by the English layer (`base` entry = SHA of Russian file); format still checked against base file. Baseline `english-layer/expected-overlay.json` rebuilt (changed: `OVERLAY.json` +481 B, `resources.worldmap.new_only` 4 → 0, 4 files `kind: replace` and `base_sha256`).

## 4. E3-b: other resources outside PROGRAM/TEXTS — verdicts

Method: full byte comparison of all common-name `RESOURCE/**` files (except models, `lighting`, animations — no language there) between US image and Russian copy (`english-audit/compare_resources.mjs` →
`english-audit/results/inventory/resource_diff.tsv`, names and sizes only); for each differing non-sound file, PNG inspection (`english-audit/tx2png.mjs <file.tx> <output.png>`, scratchpad only; one file,
`City_Radmond.tga.tx`, is split across InstallShield volumes and cannot be read by the reader — unrelated to language). **Of 2 234 common-name files, 796 differ: 705 sounds (derived from `.ogg` and voice — E4), 50 textures (40 `WEATHER` — different resolution, 10 others — table below), 33 interface INIs and 8 INI/text files (`dialog.ini`, `fonts.ini`, `Greetings_alias.ini`, `language.ini`, `TEXTS`, quests — E2/E4).**

| Resource | Difference | Observation | Verdict |
|---|---|---|---|
| `Textures/Loading/*` (129) | label language | English versus Russian labels | **include** (§3) |
| `Textures/WorldMap/reload/*` (4) | label language | “Sea/Battle/Storm/Twister/Loading…” versus Russian | **include** (§3.3) |
| `INI/INTERFACES/*.ini` (33 size_diff) | **not language**: `EXIT_BTN` added (19+ files: exit button 613,6,635,28), `SELLEVERYTHING_BUTTON` in `store.ini` (“Sell all”), `pictures.ini` (`exit button`, relocated `ship max hp icon`), `perks.ini`/`defaultnode.ini` | differences 1.01–1.03; interface texts are `TEXTS` keys | **exclude**: US 1.0 layout would break 1.03 (missing exit button, icons) |
| `INI/dialog.ini` | `mainfont = DIALOG21` (1.03) versus `DIALOG2` | — | exclude (E2 already considered: font sections) |
| `INI/fonts.ini` | E2 (§1.5): 1.03 base + Latin header | — | done in E2 |
| `INI/mainmenu.ini` | **equal** in both; logo selected by `item = 400,LANG,<language>,PICTURE,…` according to `defaultLanguage` | `potc_logo` (EN) and `potc_logo_rus` (“Пираты Карибского Моря” (Pirates of the Caribbean), 131 096 B) already in base; `potc_logo` byte-identical to US | nothing needed (engine selects English logo itself) |
| `Textures/FONTS/Menu font.tga.tx` | differs at same size: US = A–Z + Cyrillic (like `Menu font rus`), Russian = A–Z + Latin with diacritics | first 26 glyphs A–Z (all `[INTERFACE_TITLE]` uses) identical; E2 changes font to `menu font.tga` | exclude: base supports A–Z, Cyrillic not needed in English mode |
| `Textures/FONTS/* rus` | equal to US (contain Latin) | — | nothing needed |
| `Textures/INTERFACES/items1.tga.tx` | US: cells “Rome”, “Infravision”, “Holy Light” with labels; Russian 1.03 replaced three cells with new item icons (ear, anchor, shotgun) and retained other labels **in English** | 12 labels “Invisibility/Intuition/No Ammo/Lost Memory/…” are English in both | **exclude**: US would lose 1.03 item icons (mechanics, not language) |
| `Textures/INTERFACES/BuySellFlags.tga.tx` | US: flags with `buy`/`sell` text; Russian 1.03: textless arrows (different layout, 65 560 versus 32 792 B) | Russian version has no language | exclude (1.03 layout, language unnecessary) |
| `INTERFACES/ship-1`, `UpDownScrollBtn`, `icons` (region 320…504×192…254), `BATTLE_INTERFACE/MessageIcons` (“1 UP” versus “+1”), `Ships/parus_pirate`, `Characters/Danielle`, `WEATHER/*` (40) | different graphics/resolution 1.0→1.03 | language-neutral icons and sprites | exclude |
| `Textures/INTERFACES/potc_logo_rus`, `Loading/load_rus`, `new_game_rus`, `FONTS/* rus`, `LandCommands2`, `depp`, `PERKS/*`, `Items/*` (RU-only) | only in Russian | Russian logo/screens/icons 1.01+ | remain in base (game does not select them in English mode) |
| `INI/ALIASES/Greetings_alias.ini` | voice-line renumbering (37 of 191 sections) | — | **include US** (§5.4) |
| `INI/ALIASES/sound_alias.ini`, `music_alias.ini`, `max.ini` | equal | — | — |
| `INI/ALIASES/*.lng` (RU-only) | Russian aliases `[Russian Gr_…]` | **not loaded** (§5.3) | — |
| `Textures/tips` (78 US-only, 40.9 MB) | `numoftips = 0`, no references | — | not needed |
| `Textures/FONTS` US-only (6, unused), `TextureSequence/old` | obsolete | — | not needed |

Thus only content displaying Russian text in Russian mode and English in US mode, compatible in format, was added to the layer: loading, world map, greetings/voice.

## 5. E4: voice audio

### 5.1 What the files are

US `RESOURCE/Sounds/VOICE/*.wav`: **860 files, 122 528 830 B (116.9 MiB)**, flat directory, names `Eng_/Dut_/Fre_/Spa_/Por_/Ita_<sex>_<type>_<number>.wav` (268/81/241/137/128/5). **All classic PCM:
RIFF/WAVE, 44-byte header, 16-bit, 22 050 Hz, mono**, length in header = file length (`parse_wav` check, matching `SoundService`: fmt at 0x0c, data at 0x24, size at 0x28). These are `.wav`, not `.ogg`: copied
**byte for byte** (no ffmpeg or conversion; comparison with `restore_russian_voice.mjs` unnecessary — no US `.ogg`). Russian counterparts: 231 `.wav` in root `VOICE` (byte-identical to `VOICE/RUSSIAN/*.wav`),
also PCM 22 050/16/mono. **Frequency/channel mismatches among 201 replaced pairs: 0.**

### 5.2 How the game finds voice

* Greeting lines (`ch.greeting = "Gr_<name>"` → `DialogPlayGreeting`) and “talk” sounds come **only from aliases**: `SoundService.dll` reads `resource\ini\aliases\*.ini` (`*.ini`, `resource\ini\aliases\` in DLL strings),
  `[Gr_…] name = VOICE\<file>.wav`. `Greetings_alias.ini`: 191 sections (395 references to 262 distinct files), `sound_alias.ini`: 253 references to 197 files. The path **does not** contain a language and **is not** rewritten.
* `Dialog.snd = "voice\PADO\PADO043"` (1C dialogue lines) **is never played**: no `snd` attribute in strings of any DLL or `ENGINE.exe`, no `voice\PADO\…`/`VIMA\…` files in either distribution.
* `.lng` (`Greetings_russian.lng`, `talk_russian.lng`: `[Russian Gr_…] name = VOICE\Russian\…`) **are not loaded**: no `.lng` references in `MODULES/*.dll`, `ENGINE.exe`, `PROGRAM`.
* **Conclusion:** game requests 392 distinct names (400 including US alias variants); of 860 US files **393 can play**, the remaining 467 (65.6 MB) are needed by nobody — absent from all aliases (Russian and US) and `PROGRAM` literals.
  Therefore **393 files are included by default** (`--voice-scope referenced`: names from all base and US `ALIASES/*.ini`, and `voice\…wav` literals); `--voice-scope all` — all 860 (116.85 MiB, +467 dead).

Name matching (filenames in Russian distribution match US — Russian recordings are named `Eng_m_a_001`, etc.):

| Class | Names | What happens in English mode |
|---|---:|---|
| Russian and US file both exist | 201 in layer (204 common names total) | US overlays Russian file in root `VOICE` (`replace`, `base` entry); contents differ in all 204 |
| US only (“silent” in Russian mode) | **192** (145 from `sound_alias.ini` + 55 from Russian `Greetings_alias.ini` + 7 from US, with overlaps) | **new files** (`add`): voiced in English mode; not added in Russian mode (Russian base unchanged) |
| Russian file only | 27 (`Cole_Brock`, `Enc_Officer`, `Tavern_Fightman`, `Smuglers_Citizen1–4`, `Rel_m_b_001–3`, `Por_m_a_0180/0190`…) | remain in base; **none requested** by English-mode aliases (2 — `Por_m_a_0180/0190` — were requested by Russian `Greetings_alias.ini`) |
| neither | 5 (`Dut_m_b_032–036`) | silent, as in original |

### 5.3 `VOICE/RUSSIAN` is not overlaid

`D2` stated that game reads `VOICE\x.wav` and `VOICE\Russian\x.wav` pairs; in fact the latter is only from unloaded `.lng` files (above). Therefore “Russian voice under an English name in `VOICE/RUSSIAN/…`”
**does not play and need not be overlaid** in English mode. `--voice-russian-dir` still overlays `VOICE/RUSSIAN/<name>.wav` (+201 files, +25.9 MB) in case live verification disproves this finding.
The game does not read Russian base `.ogg` files at all (D2).

### 5.4 Greetings: US `Greetings_alias.ini`

The Russian distribution renumbered greeting names to match Russian recordings: `name` differs in 37 of 191 sections (`gr_counterspy` → `Dut_m_a_037` versus `Eng_m_a_001`, variant lists for `Gr_Douwesen citizen`/`Gr_Isla Muelle citizen` shorter, name removed for
`Gr_Pepin Bertillon`, `Gr_Caminero`). With the Russian alias, English lines would sound “from the wrong NPC” and 2 greetings would remain Russian. US file: same 191 sections, **all parameters except `name` match**
(`english_assets.alias_compat` refuses any difference), and it references US names throughout (393 of 398). Decision: **include US file** (`aliases`, 27 936 B, `base` = SHA of Russian). Revert with `--keep-ru-greetings`
(or remove file from layer). Other alias files (`sound_alias.ini`, `music_alias.ini`, `max.ini`) are equal in both versions.

### 5.5 Text/voice mismatch

* Only **greetings** (a short line when conversation starts) and “talk” sounds are voiced; **there is no line-by-line dialogue voice** in either version (§5.2). Thus Russian text of branches added in 1.01–1.03 (≈ 62 lines, E2) has no
  voice in either mode: “Russian voice under English text” cannot happen. The only source of mismatch is greeting renumbering (§5.4), addressed by US alias.
* **Russian voice remnants in English mode: 0 requested** (with `--keep-ru-greetings` — 2: `Por_m_a_0180/0190`). “Remove Russian voice (silence)” is unnecessary: nothing to replace.
* 145 “silent” lines in Russian mode are **not added** to Russian mode; they exist in the layer as new `VOICE/<name>.wav` files and are audible only in English mode.

### 5.6 Volume and risk

US lines have lower RMS level than Russian: among 201 replaced pairs, median **−5.6 dB** (mean −5.1; range −18.8 to +6.8), peak −2.5 dB; mean across all US −19.4 dBFS (Russian −14.9). EN/RU duration: median ×1.10
(0.20…4.68: different lines under one name). “As is” — volume was not equalised (possible E4c: normalisation at layer stage; user decides after live verification).

### 5.7 E4b (not implemented, description only)

Audit option: transfer US voice as `.ogg` and decode to `.wav` during installation (as in `restore_russian_voice.mjs`: `ffprobe` + `ffmpeg -c:a pcm_s16le` + canonical 44-byte header). Images contain
ready PCM, so the layer would have to **encode to ogg** (estimate from Russian: `.ogg` ≈ 17% of `.wav` → ≈ 10 MB instead of 43 MiB gzip) and add page decoding (`decodeAudioData`) — more expensive and risky; not needed now.

## 6. E3-c: videos

* **Comparison:** of 16 US `RESOURCE/VIDEOS/*.wmv`, 11 (`Artefact`, `BlackPearl`, `Blaze_land_dead`, `Blaze_mutiny_dead`, `Ending`, `Idol`, `Skeleton_on_beach`, `Storm`, `Temple`, `Trailer`, `Undersea`) are **byte-identical** to Russian
  (SHA-256) — no English versions and none needed. Differ: `Invasion` (Russian voice 25.9 MB in `Russian/` versus English 26.1 MB), `Credits` (62.5 MB), `AkellaLogo`, `BethesdaLogo`, `WaltDisneyLogo` — only in US.
* **Only `Invasion` is enabled in English mode:** `English/Invasion.mp4` (WMV2/WMA2 → H.264 High 640×384 25 fps + AAC 44.1 kHz stereo, **9 172 106 B, 83.08 s**; Russian `videos-web/Russian/Invasion.mp4` — 9 171 737 B, 83.08 s).
  Recipe `scripts/convert_videos.sh` (libx264 CRF 23 preset medium yuv420p, AAC 96k, `+faststart`) plus reproducibility options: `-threads 1`, `-fflags +bitexact`, `-flags:v/a +bitexact`, `-map_metadata -1`, no chapters. **ffmpeg 9.0.2:**
  two runs and a build from another image give one SHA-256 (`de57a2f6…9329`). Byte equality guaranteed only with same ffmpeg version; with another version `--check` verifies WMV-source SHA-256 and parameters (codecs, frame size, duration ±0.5 s).
* **Path convention:** `videos/English/Invasion.mp4` beside `videos/Russian/Invasion.mp4`, one nesting level (`make_dist`/`verify_dist` permit it). Build: `--video-out web-port/videos-web` (places `English/Invasion.mp4`, leaves rest untouched); `make_dist`/`serve.py`
  publish `videos-web/**/*.mp4` as before. **Not in overlay or OPFS.** Without ffmpeg: `--skip-video` (or no `--video-out`) and command from warning; video is not built and bridge skips `Invasion` in English mode (fail-open).
* **`Credits`, `WaltDisneyLogo`, `BethesdaLogo`, `AkellaLogo` are not shown in English mode** (user decision). These names are already absent from `VIDEO_FILES` (bridge replied “skip”), but now explicitly enforced (`EN_SKIP`): even if a file later
  appears in `VIDEO_FILES`, English mode will not show it, Russian unchanged. Menu “Credits” button has no effect in English mode (as currently in Russian).
* **Bridge (`web/video-player.mjs`, my file):** `createVideoPlayer({ lang })` — value or function (`'ru'` default; `'en'`/`'EN'`/`'en-US'`/`'English'` — English; any other value or function failure — Russian), read for each request;
  `resolveRequest(name, lang='ru')`, `videoFile(name, lang)`, `normalizeLang`, `VIDEO_FILES_EN = {invasion: 'videos/English/Invasion.mp4'}`, `EN_SKIP`. One-argument calls and `VIDEO_FILES` (parsed by `make_dist.player_video_targets` and
  `verify_dist` using regex `VIDEO_FILES\s*=\s*\{…\}`) unchanged. Tests: `recomp/tests/test_video_player.mjs`, 27 (was 23): language, `EN_SKIP` overrides map, dynamic language, language-function failure.
* **`port.js` patch (E1/E5 apply; I did not change the file):** `korsary2-next/english-layer/PAGE_PATCH_video-lang.patch` — one line in `createVideoPlayer({…})` inside `run()`: `lang: english ? 'en' : 'ru'` (`english` variable already there; `patch --dry-run -p1` on current `port.js` passes).
  Without patch bridge stays Russian (behaviour unchanged). **E5:** add `VIDEO_FILES_EN` to `verify_dist`/`make_dist` checks (they only check `VIDEO_FILES`: without this missing `English/Invasion.mp4` in dist would go unnoticed).

## 7. Checks and tests

Current Node tests: `node --test korsary2-next/recomp/tests/test_prepare_english_*.mjs korsary2-next/recomp/tests/test_english_text.mjs`. **Historical Python run: 75 tests OK** (≈ 3 s; was 43, previous unchanged; 1 skip — optional `RealOverlay`); with `K2_ENGLISH_OVERLAY=<real layer directory>` additionally passes: code skeleton of each file,
`.tx`/`.wav` formats, path spelling and `OVERLAY.json: base` against real `korsary2-next/game`. New tests (synthetic mini “US” game with `.wav`, `.tx`, aliases, WMV; fake `ffmpeg`/`ffprobe`): paths/spelling/`base` binding (including relocated), files equal to base excluded,
**refusal on different format/size/mip/truncated `.tx`** (including world map), `.wav` validity (non-PCM, 8-bit, no `data`, length, `OggS` named `.wav`), `.ogg` in US voice — refusal with `--skip-voice` hint, `referenced`/`all` scopes, replacements/new,
`--keep-ru-greetings`, `--voice-russian-dir`, incompatible alias file, frequency mismatch (counted, not refused), `--skip-*`/`--text-only` keep text layer byte-identical, missing source resources — warning, **baseline without US content**,
`--check` (tampered voice byte, missing/extra screen, “adjusted” baseline with tampered `.tx` caught by payload check against base), `--check` with `--skip-*`, `base` binding, paths outside `PROGRAM/RESOURCE`, video (fake ffmpeg: determinism, “unchanged”, foreign file not overwritten without `--force`,
no video without `--video-out`/with `--skip-video`/without ffmpeg, `--video-out` inside `--out`/base/source — refusal, ffmpeg failure — error, video pin and comparison), determinism across two runs and mtime, `--base` and source unwritten (tree before/after), failure does not create `--out`.
**Mutations — 8 new mutants killed** (scenario passes on real code and fails without protection): format/size/mip checking, `.tx` header parsing, `.wav` validation, `relocate_if_absent` rule, alias compatibility, “what is referenced” filter, `base` binding in `verify_resources`, `--video-out` guard
(plus 7 earlier E2 mutants). `recomp/tests/test_make_dist_coverage.mjs` (28) and `test_verify_dist.py` (24) — OK (checked after `video-player.mjs` change).

**Real data (12.11.2026):** `prepare_english.mjs --base korsary2-next/game --us-iso Disc1 Disc2 --out <scratchpad> --video-out <scratchpad>` — rc 0, ≈ 10 s, 763 files (762 + `OVERLAY.json`), `--check --out … --base …` and `--check` (in-memory rebuild) from single-disc image — “СВЕРКА ПРОЙДЕНА” (verification passed);
**second independent run from single-disc image to another directory: empty `diff -r` of directories, videos byte-identical**; `--text-only` gives same 243 files as E2, `--check --text-only` passes. Baseline text portion unchanged: all 242 text entries matched prior `expected-overlay.json`,
only `OVERLAY.json` entry differs (`base` expanded). Images, `korsary2-next/game`, `SAVE/` unchanged; scratchpad layer directory deleted after check (disk: ≈ 16 GB free before and after).
Format validation: 126 layer `.tx` headers match base (format, dimensions, mip: 0 mismatches), 393 `.wav` valid RIFF/PCM 16-bit; **frequency/channels match Russian counterparts: 0 mismatches of 201 pairs**.

## 8. Limitations and risks

* **Not checked live:** displaying English screens (including relocated names and `WorldMap/reload`), absence of “white” screens (R1 conclusion from code only), greeting and “silent” voice playback, volume (§5.6), Invasion video (codec, audio, skip), world-map transition.
* **Texture format:** structurally checked (`.tx` header), not loaded by engine. All 126 are 1 mip R5G6B5 512×512, like Russian (same “Loading” loader). Low risk.
* **Volume** of US voice is ≈ 5 dB below Russian (§5.6); greetings are short.
* **Layer tied to Russian base** by `OVERLAY.json: base` (SHA-256 of published files) and `port.json` (`relocate_if_absent`): any change to relocation rules (both `Loading/Russian` and `WorldMap/reload/Russian` already considered, W1) or these directories' contents requires rebuilding layer and baseline (build sees base files
  and switches to “replacement”). Rules read from `port.json`; for nonstandard `port.json` specify `--port-json`; without `port.json` same two rules used (`english_assets.DEFAULT_RELOCATE`).
* **Alias file** is US (§5.4): if Russian `Greetings_alias.ini` is updated (new sections), build refuses (`alias_compat`) instead of silently substituting.
* **Size:** +71.3 MiB network (gzip-6) for English install; without space — `--skip-voice` (−43.1 MiB, no voice added, Russian remains for Russian NPCs) or `--voice-scope referenced` (default).
* **US content** does not enter Git; overlay directory and `videos-web/English/Invasion.mp4` contain US data and are not committed (publication is user decision, R6). Paths up to 62 characters are within normal limits.
* **mp4:** byte equality only with same ffmpeg version (9.0.2); with a different version parameters are checked.

## 9. What remains

* **E1/E5:** apply `PAGE_PATCH_video-lang.patch`; `make_dist --overlay-dir <layer directory>` (layer manifest: 762 files, `overlay.base` — 570 entries; `.wav`/`.tx` packed gzip without `.ogg` rule), `videos-web/English/Invasion.mp4` — in `videos/`; `verify_dist --overlay`:
  compare against `english-layer/expected-overlay.json` (classes `loading`, `worldmap`, `voice`, `aliases` and `resources` field), `VIDEO_FILES_EN`; English preflight — same required layer files as E2 (resources are warnings, not refusal: missing screen/line does not crash game).
* **Done (W1):** `relocate_if_absent` rule for `WorldMap/reload/Russian` (§3.3) — Russian-mode defect, independent of English; E5 (`docs/english-layer.md`, section 11) closed `verify_dist --overlay`, `VIDEO_FILES_EN`, preflight; `PAGE_PATCH_video-lang.patch` applied (`lang: english ? 'en' : 'ru'` in `port.js`).
* **Live acceptance** (another agent, separate origin and test slots): English mode — loading screens for tavern/house/fort/landing/sea (`Sea`) and world-map transitions (`Battle/Storm/Twister`); greetings from different nations
  in dialogue (volume, “silent” lines, no Russian voices); Invasion video leaving Oxbay (English audio, keyboard skip); no Bethesda/Disney/Akella logos at startup; “Credits” button (no effect); `system.log` without `Can't load texture`;
  Russian-mode regression (screens, voices, `Russian/Invasion.mp4` — as before).
