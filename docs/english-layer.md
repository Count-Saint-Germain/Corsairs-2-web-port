> Historical technical document: intermediate diagnostic runs have been removed. Their snapshots and example commands are unavailable; current instructions are in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md).

# English text layer (E2): overlay contract and reproducible build

Date: 12.11.2026. Author: E2 agent. Status: **ready** (build, baseline, tests); not checked live (rendering, layout, `STRSERVICE`).
Section 1 (“Overlay format”) is the specification for E1 (host + page), E3/E4 (resources, voice), and E5 (preflight, verify_dist, slot marker).
**As of 12.11.2026 (after W1 and E5):** layer — 762 files + `OVERLAY.json` (E2 text + E3/E4 resources, `docs/english-layer-assets.md`); world map `WorldMap/reload/*` now **overlays** base files (W1, section 11.1);
E5 implemented (section 11: one required-file list, preflight, `verify_dist --overlay`, slot language marker); live acceptance — section 12.
Original decisions: `docs/english-sources-audit.md`, section 10 (implement English throughout, E1–E5; one distribution with optional English layer;
shared save slots with language marker; US name lists in English mode; Russian mode remains byte-for-byte unchanged by default;
Bethesda/Disney/Akella logos and Credits video are not shown in English mode).

**Overview.** `tools/prepare_english.mjs` builds an overlay directory from a Russian working copy and US images: **242 files + `OVERLAY.json`, 1.64 MB (0.43 MB gzip)**,
built in ≈ 6 s, deterministically (two runs from different images yield identical SHA-256). 11 111 script literals, 670 names, 401 quest entries, and 662 interface text values
are taken automatically from US version 1.0; **143 strings translated manually** (`english-layer/manual-strings.json`);
**187 strings remain Russian** (also Russian in the US version, §6).

## 1. Overlay format (contract for E1/E3/E4/E5)

### 1.1. What an overlay is

The English-layer overlay is a **directory mirroring the game tree**, containing only files that in English mode **differ from
base (Russian) files**. Paths match the game: `PROGRAM/**`, `RESOURCE/INI/**`, `RESOURCE/QUESTSTEXT/**`, later (E3/E4) `RESOURCE/Textures/Loading/**`,
`RESOURCE/Sounds/VOICE/**`. Built by `tools/prepare_english.mjs` (E2, text); E3/E4 add files to the same directory. Base Russian
distribution, its `manifest.json`, `version` and SHA-256 **do not change by a byte**.

```
server:   game/            (Russian distribution, as now)    game-en/   (English layer: files + manifest.json)
OPFS:     korsary2-game/                                      korsary2-game-en/   (installed only when English is selected)
launch:   PORT_OVERLAY unset  -> previous path, no overlay;  PORT_OVERLAY=/opfs/korsary2-game-en -> overlay enabled
```

### 1.2. Path resolution rules (host, `map_path` and everything opening a file by name)

1. **Scope:** only paths under `PROGRAM/` and `RESOURCE/` (first component after game root, case-insensitive). Everything else —
   `SAVE/`, `SAVE_META/`, `SAVE_TX/`, `options`, `engine.ini`, `ENGINE.exe`, `MODULES/**`, any paths outside game root — **always base**.
   An overlay manifest with an entry outside `PROGRAM/`/`RESOURCE/` is invalid (`make_dist --overlay-dir` and verify_dist refuse).
2. **Read** (`CreateFile` without write access with `OPEN_EXISTING`, `GetFileAttributes(Ex)`, `GetFileSize`, `FindFirstFile`, `LoadLibrary`, etc.):
   first search overlay, then base installation. An overlay file completely replaces the base file (no content merging).
3. **Write/create/delete/rename/change attributes** (any write access, `CREATE_*`, `TRUNCATE_EXISTING`, `DeleteFile`, `MoveFile`,
   `CreateDirectory`, `RemoveDirectory`, `SetFileAttributes`): **overlay is read-only**, operation goes to base installation and does not see overlay.
   Engine writes nothing under `PROGRAM/`/`RESOURCE/`; if such an attempt reaches a path present in overlay, **refusal with
   `ERROR_ACCESS_DENIED` and `PORT_LOG` entry is recommended** (otherwise the file would exist in two versions: decision for E1, but silent base writes are not allowed).
4. **Name normalisation:** case-insensitive matching of each component, as now (`find_ci`/`find_ci_fold` with `PORT_NAME_CP1251`).
   `\` and `/` separators are equivalent, `.` and `..` resolved before overlay lookup (escape above overlay root impossible). Overlay manifest paths
   use **the same spelling as base** (`prepare_english.mjs` takes spelling from base file); two overlay paths differing only by case are forbidden.
5. **Directories** (`FindFirstFile`/`FindNextFile`, directory `GetFileAttributes`, `SetCurrentDirectory`): a directory exists if present in base **or**
   overlay. Listing is **union of names** (case-insensitive): base entries first in base order, then overlay-only names
   (in overlay order); on a matching name, use overlay entry (size, time, attributes from overlay). `.` and `..` once. Nested directories
   are recursively merged by the same rules. Needed for directories to which overlay **adds** files (E4: `RESOURCE/Sounds/VOICE`, E3: `Textures/Loading`).
   If an overlay name is a file and base name a directory (or vice versa), overlay wins; this does not occur in data, and E1 can test it.
6. **Base-only file:** visible as usual (overlay does not “hide” the rest of installation). **Overlay-only file:** visible (new files, e.g. English
   voice). The format cannot **hide a base file** in English mode (no “tombstones”); if needed, overlay supplies a replacement file
   (E3/E4 decide through data).
7. **File identity** (K2 strict mode, handles): determined by final host path. Overlay and base paths for one logical file are different host paths;
   while the file is open, the second path for the same logical name must not be reopened differently (achieved by deterministic rule 2: logical name always
   resolves to the same host path while overlay is enabled and unchanged).

### 1.3. Overlay manifest `game-en/manifest.json`

Same format as `game/manifest.json` (`web/gamefiles.py`, D1/D1b/D3), built by `make_dist.py --overlay-dir <overlay directory>` (implemented by E1):

```
{ "version": "<12 hex: digest path:size:sha256, like base>",
  "files": [ {"path": "PROGRAM/DIALOGS/blaze_dialog.h", "size": N, "sha256": "…",
              "enc": "gzip"|"br" (optional), "csize": N, "pack": i, "offset": N}, … ],
  "packs": [ … ],                       // as in D3 when packing is enabled
  "overlay": { "format": 1, "language": "English", "base": { "<path>": "<base file sha256>", … } } }
```

* `size`/`sha256` describe **unpacked** contents; `version` is independent of delivery method (as for base).
* `make_dist --overlay-dir` takes the `overlay` block from `OVERLAY.json` at overlay directory root (written by `prepare_english.mjs`: `{"format": 1, "language": "English",
  "generator": "prepare_english.py/1", "base": {path: base file sha256}}`, keys sorted); `OVERLAY.json` itself is **not included** in `files` or copied into OPFS.
  Page must ignore unknown top-level keys (E1 checks this in a test). E3/E4 put their files in the same directory and add `base` entries for files they replace
  (files absent from base have no `base` entry).
* `overlay.base[path]` — SHA-256 of the **base file on which the replacing overlay file was built** (English-layer scripts are Russian files with
  substituted literals). verify_dist (E5) compares these with base manifest `size/sha256`: mismatch means overlay built against another Russian distribution and
  English launch is forbidden (code skeleton may have diverged). Overlay-only files (absent from base) are absent from `base`.
* Paths only under `PROGRAM/` and `RESOURCE/`, no `..`, no case collisions; each file occurs in `files` exactly once; sizes/hashes checked as for base.
* `port.json` rules (`exclude_*`, `relocate_if_absent`) do not apply to overlay: it contains exactly what is needed.

### 1.4. Installation and launch (page, E1)

Installed only when English is selected, into a separate OPFS directory with its own marker/`version`; English launch is blocked until complete
layer synchronisation (partial layer does not start; Russian works independently). Wasm starts with `PORT_OVERLAY=<layer path>`; in Russian mode
variable is unset and overlay branch in host does not run. Language selection is on page (`?lang=en`, `localStorage korsary2.lang`); in game language is set by
layer file `RESOURCE/INI/TEXTS/language.ini`.

### 1.5. Language file and fonts

* **`RESOURCE/INI/TEXTS/language.ini`** in overlay: active line `defaultLanguage\t= English` (base has `russian`); rest of file unchanged. This is the only
  `STRSERVICE` language switch; base file and manifest unchanged.
* **`RESOURCE/INI/fonts.ini`** in overlay is **not the whole US file** (a correction to `docs/english-sources-audit.md`, §2/§3.3, which says “совпадает с нашим `fonts_eng.ini`” (matches our `fonts_eng.ini`):
  true, but `fonts_eng.ini` predates 1.03), but the 1.03 base with one line replaced in `[INTERFACE_TITLE]`: `Texture = fonts\menu font.tga` (Latin title
  font instead of `menu font rus.tga`; file size −4 bytes). US/`fonts_eng.ini` lacks `[DIALOG21]` (required by `INI/dialog.ini` 1.03: `mainfont = DIALOG21`) and `[INTERFACE_SMALL]`
  sections and `pcscale` parameters; replacing the whole file would break dialogue fonts. Other English-mode sections are the same (`* rus.tga`, contain Latin). The build compares
  each US-file section to ours (only `pcscale` and comments may differ).

### 1.6. Encoding and characters

Overlay files use the bytes/encoding of base files: CRLF, no BOM; replacement literal text is **ASCII** (Latin, digits, punctuation, `\n` sequences); Russian CP1251 bytes
remain only in literals that are also Russian in the US version (list §6). Game fonts (`fonts.ini`) contain ASCII glyphs (without `~`) and bytes `0xA8`, `0xB8`, `0xC0..0xFF` as **Russian**
letters: any byte `0x80..0xFF` in English text (typographic quotes, dashes, `é`, `ç`…) would render as Cyrillic or disappear, so such characters are replaced with ASCII (§4).

### 1.7. Save-slot language marker (E5)

`SAVE/` slots are shared. NPC names and headings assigned when a game is created remain in the creation language. **Implemented in E5 (section 11.5), differently from the E2 sketch:** marker is not a field inside the record, but a separate sidecar
`SAVE_META/<slot>.lang` (exactly 2 bytes `en`; `ru` allowed), written by **host** when a slot is created in English mode (overlay enabled). Russian mode writes nothing new; **no marker = “unmarked”**
(old slots created before marker, and everything created in Russian mode: one cannot assert such a slot is Russian). At launch the page gives a nonblocking notice about slots of another language.

### 1.8. Preflight and verify_dist (E5)

* `verify_dist --overlay game-en`: same code checks `game-en/manifest.json` (structure, `size`/`sha256`, `version`, allowed paths, no `SAVE*`/`options`/`engine.ini`), `overlay.base` against base manifest,
  layer inventory against `english-layer/expected-overlay.json`.
* English-mode page preflight: mandatory layer files — `RESOURCE/INI/TEXTS/language.ini`, `RESOURCE/INI/fonts.ini`, `RESOURCE/QUESTSTEXT/quests_texts.txt`,
  `RESOURCE/INI/TEXTS/ENGLISH/common.ini`, `…/ItemsDescribe.txt`, `PROGRAM/Characters/Characters_names.c` (all in E2 layer); absence of any refuses English launch;
  other files give warnings. Russian mode uses unchanged code. **Implemented in E5 (sections 11.2–11.3); the list now lives in one place — `recomp/web/overlay-required.json`.**
* E2 layer inventory is checked by `prepare_english.mjs --check --out <layer directory>` (§2): file set, sizes, SHA-256 against `english-layer/expected-overlay.json`; with `--base`, also
  code skeleton of each file against base. E3/E4 extend the baseline with their files (or maintain their own).

## 2. Build procedure

Inputs: prepared **Russian** working copy (`--base`, `korsary2-next/game` = `prepare_game.mjs` result; read-only; `PROGRAM` scripts already contain port fixes, `content-patches/`
patches are not rebuilt) and US source — **images** (`--us-iso`: single disc or Disc 1 + Disc 2) or extracted tree (`--us-game`). Images read only `rb`, nothing mounted or
run; required files (`PROGRAM/**`, `RESOURCE/INI/TEXTS/**`, `INI/fonts.ini`, `QUESTSTEXT`; ≈ 800 files, 8.4 MB) read **into memory**, nothing extracted to disk.

```
node korsary2-next/tools/prepare_english.mjs --base korsary2-next/game \
    --us-iso "…/Pirates of the Caribbean (Disc 1 & 2)/… (Disc 1).iso" "…/… (Disc 2).iso" --out <NEW directory>        # ≈ 6 s
node korsary2-next/tools/prepare_english.mjs --check --out <directory> --base korsary2-next/game                   # baseline + skeleton verification
node korsary2-next/tools/prepare_english.mjs --check --base korsary2-next/game --us-iso … …                      # in-memory rebuild and verification (no writes)
```

Options: `--out` must be new/empty (otherwise refusal; `--force` deletes nothing, leaves equal files, replaces others); refusal if `--out` equals or is nested in `--base`/source (or vice versa);
`--dry-run` — calculate/check everything, write nothing; `--manual`/`--expected` — manual layer and baseline paths (default `english-layer/`); `--write-expected FILE` — for maintainers (regenerate baseline
after any translation or base change); `--skip-image-hash`/`--ignore-pins` — development only. Return codes like `prepare_game.mjs`: 0 ready and verified, 1 error/refusal, 3 built but verification failed.

**Source pins** (mismatch causes refusal): SHA-256 of `data1.hdr`, `data1.cab`, `data2.cab`, `data3.cab` volumes from images (`english-audit/results/iso-sha256.txt`; identical for Disc 1/Disc 2 and single-disc image —
verified: builds from both are byte-identical) and fingerprint of used US files (`us_files_digest`: 800 files, path + size + SHA-256). For Russian base
baseline stores input-file fingerprint (`base_inputs_digest`, mismatch warning), exact binding via `OVERLAY.json: base` (base-file SHA-256 for each overlay replacement).

**Algorithm by class** (`tools/english_text.mjs` library, `tools/prepare_english.mjs` build, CLI and checks):

| Class | What | How |
|---|---|---|
| `align` (231 files) | `PROGRAM/**` with US counterpart | `"…"` literals containing Cyrillic in Russian file replaced by US. `DIALOGS/*.h` (`DLG_TEXT[]`): by index if counts equal; otherwise align paired `*_dialog.c` by skeleton (`DLG_TEXT[#]`), Russian “extra” lines remain for manual layer. Other files: align lines by code skeleton (`difflib`), take pair if literal counts in line match. Pair not taken if US literal is Russian (run ≥ 2 Cyrillic bytes) — Russian 1.03 remains — if format specifiers (`%s`, `%d`, `{…}`, `#…#`) differ, or character has no safe ASCII replacement |
| `manual` (2) | `PROGRAM/**` without US counterpart | `INTERFACE/boal_map.c`, `Eng_Bertillon's Guard_dialog.h` — manual layer only |
| `names` (1) | `Characters/Characters_names.c` | entire US file (670 literals instead of 45), characters normalised; structure checked against Russian (same operator set, extra `Trace` allowed) |
| `texts` (7) | `TEXTS/language.ini`, `INI/fonts.ini`, `TEXTS/ENGLISH/{common.ini, ItemsDescribe.txt, AbilityDescribe.txt, HelpSectionTitles.txt, HELPSECTIONS/Dialog_window.txt}` | `language.ini` — base with `defaultLanguage` switched (checked byte-identical to US); `fonts.ini` — §1.5; `common.ini`, `ItemsDescribe.txt`, `AbilityDescribe.txt`, `HelpSectionTitles.txt` — **structure, order and keys of Russian 1.03 file**, values US (by key; 5 1.01+ renames via `TEXT_KEY_RENAMES`) or manual; `Dialog_window.txt` — US with `à` replaced by `a`. Other 12 base `TEXTS/ENGLISH` files already complete (keys/order as Russian) and not duplicated |
| `quests` (1) | `QUESTSTEXT/quests_texts.txt` | Russian headings/order/CRLF, entry bodies `(quest, #TEXT n)` US (401) or manual (23); empty US body not used |

**Safety checks on every build** (violation refuses instead of silent corruption): (1) **code skeleton**: after replacement all bytes outside string literals byte-identical to Russian file, same literal count
(per-file check, then again `verify_payload` on finished set and at `--check`); (2) replacement literals ASCII only; (3) format specifiers equal Russian original (`\n` in automatic pairs
may differ — US text is freer, 90 cases, informational); (4) **alignment anchors**: among pairs “Russian literal without Cyrillic ↔ US literal without Cyrillic” (identifiers, models), ≥ 99% must match
(real data: 4 files differ in 1–2 pairs — 1.01+/port changes `corsair2`/`Animists2`/`1500`; `Characters/init/*.c` block alignment confirmed); (5) manual layer: SHA-256 of Russian original (base drift refuses),
index/key exists, overriding automatic pair only with `"override": true`, specifiers (including `\n`) as original, ASCII, no unescaped quotes; unused entry refuses; (6) CRLF as base, no BOM.

## 3. Layer contents

Files: **242 + `OVERLAY.json`**; 1 643 619 B (1.57 MiB), gzip-9 — 431 395 B (0.41 MiB; `OVERLAY.json` 27 KB, 12.5 KB gzip, included). Directories: `PROGRAM/DIALOGS` 214 files (`.h` and several `.c`), `PROGRAM/Characters` 16 (including `init/*.c`, `Characters_names.c`), `PROGRAM` 3 (`Dialog_func.c`, `seadogs.c`, …), `PROGRAM/INTERFACE` 1 (`boal_map.c`),
`RESOURCE/INI` 1 (`fonts.ini`), `RESOURCE/INI/TEXTS` 1 (`language.ini`) + `ENGLISH` 4 + `ENGLISH/HELPSECTIONS` 1, `RESOURCE/QUESTSTEXT` 1. All replace existing base files; no overlay-only files in E2.

| Class | Files | Bytes | gzip-9 | Automatic | Manual | Remain Russian in layer files |
|---|---:|---:|---:|---:|---:|---:|
| `align` | 231 | 1 375 029 | 343 397 | 11 111 literals | 66 | 7 |
| `manual` | 2 | 5 420 | 1 923 | — | 20 | 0 |
| `names` | 1 | 94 992 | 32 617 | 670 literals | — | 0 |
| `quests` | 1 | 73 810 | 24 050 | 401 entries | 23 | 0 |
| `texts` | 7 | 67 043 | 16 881 | 662 values | 34 | 0 |
| total | 242 | 1 616 294 | 418 868 | 12 844 | **143** | 7 |

Additionally 180 literals remain Russian in files not included in layer (US literals there are Russian too, §6). Literal matching: 11 384 Russian literals with Cyrillic in `PROGRAM` (excluding `Characters_names.c`, taken whole) → 11 111 replaced
automatically, 86 manually, 187 remain Russian (168 equal US, 19 also Russian but different in US).

## 4. Encoding, fonts, characters

* All layer files use CRLF like base, no BOM; replacement literals ASCII. Russian CP1251 remains only in literals not replaced by layer.
* **What `fonts.ini` fonts draw** (all sections analysed): text fonts (`NORMAL`, `DIALOG2`, `DIALOG21`, `DIALOG3`, `INTERFACE_NORMAL`, `INTERFACE_SMALL`) contain printable ASCII (except `~`; `=` via `char_equ`)
  and bytes `0xA8`, `0xB8`, `0xC0..0xFF` — **Russian letters Ё, ё, А–я**; bytes `0x80..0xA7`, `0xA9..0xB7`, `0xB9..0xBF` absent from tables (character disappears). Heading font (`INTERFACE_TITLE`, `menu font.tga`) — uppercase
  `A–Z` and period only; no digits or lowercase (hence headings in `common.ini` are uppercase, as is our `titleBoal_map`). **Consequence:** any accented Latin character (`é` = `0xE9` — “й”!) or typographic character in English
  would render Cyrillic or disappear. Such bytes occur in US data (14 literals and one help file total); original US game would render them equally incorrectly; layer replaces:
  `0x85 …`→`...`, `0x91/0x92`→`'`, `0x93/0x94`→`\"` in literals (`'` in texts), `0x96/0x97`→`-`, `0xA0`→space, `ç é ô ó ñ à â`→`c e o o n a a` (NFKD without diacritics; ligatures `ß æ œ`→`ss ae oe`); character without safe
  replacement refuses build. Found in data: `Ran\xE7on`, `Saint-Ch\xE9ron`, `Trich\xE2tel`, `M\xF3nica`, `Ver\xF3nica`, `Pe\xF1alver` (names), `\x92` (5 lines), `\x91…'` (2), `\x85` (1), `\x96` (2), `à` in help (1).
* Manual layer ASCII only (loader check). Layer contains no `~` (font lacks it).
* String length: 8 US interface labels are 1.6+ times longer than Russian with length > 30 characters (audit). Six replaced by manual layer for other reasons or shortened (`perkIronWill`, `perkStormProfessional`, `perkTrustworthy` — semantic drift; `Wait for save` — Xbox console text; `You give item`, `land_commands` — shortened, §5); `AbilityDescribe.perkAdvancedCommerce` (multiline description field) and `interface_strings.save game limit` (message window with wrapping) remain — baseline `len_ratio_hi` field. Layout checked in live acceptance.

## 5. Translation (manual layer)

File `korsary2-next/english-layer/manual-strings.json` (in Git): **145 entries** = 143 translated strings + 2 alignment corrections (`kind: pairs`, contain no text). Entry: file, kind (`literal`: literal ordinal in file,
for `DIALOGS/*.h` = `DLG_TEXT` index; `quest`: `quest#number`, 0 = heading; `text_key`: TEXTS-file key), **SHA-256 of Russian original** (base-drift protection), English text, `override` (deliberate override of
automatic pair), `note`. File and baseline contain no US text (checked by marker-word test); translation is agent's original work, `note` has no references to US text.

| What | Strings | Note |
|---|---:|---|
| 1.01–1.03 dialogues: 4 governors × 9 “sink the pirate” lines (Christofor Manuel De Alencar, Jacinto Arcibaldo Barreto, Joseph Claude Le Moigne, Reynard Grueneveldt), `Douwesen Citizen` 3, `Simon Hanpool` 4, `Quest_ANIMISTS` 3, `Enc_Raiders` 4, `Eng_Bertillon's Guard` 2, Douwesen/Isla Muelle soldiers 1 each | 54 | new NPC lines from patches; governor lines concatenated by code (ship name, colony, sum) — neutral formal tone |
| Loanshark (`Usurer_dialog.h`) | 4 | US pair contains `%%`, Russian code prints number without percent (`percent` added to translation) |
| **Malcolm Hatcher tutorial** (port patch 04: “assigned command” instead of F3/Ctrl/…) | 8 | not 7 as in audit: eight changed strings (indices 8, 34, 36, 48, 50, 54, 157, 235). Prompts refer to assigned commands and control settings, not hardcoded keys; “usually Space” follows Russian port text; US text outdated and overridden (`override`) |
| `INTERFACE/boal_map.c` (world-map encounter labels) | 18 | assembled by code from pieces; “Captain, there's a battle ahead. It looks like [merchants], under [English colors] vs. …” |
| `StoryCharacters.c` (“Пират” → `Pirate`), `seadogs.c` (“Все ок!” → `All OK!`) | 2 | |
| Quest entries | 23 | 6 “sink the pirate” quests × 3 (18), `Story_1stTaskReceived#14`, `Blaze_in_prison#7`, `animists#38`, `convoy_por#1`, and **`resque_researcher#0`** (US file has empty quest heading) |
| TEXTS keys: 12 (`common.ini`) + 2 (`itmname/itmdescr_artefact`) — from audit | 14 | `Video Settings`, `Brightness`, `Contrast`, `Gamma Correction`, `Invert Vertical Mouse Axis`, `Vertical/Horizontal Mouse Sensitivity`, `Restore Defaults`, `Save Settings`, `Raise Flag`, `Sell All`, `SAILS ON THE HORIZON`, `Artifact` |
| **Additionally found by E2 audit:** descriptions where US describes 1.0 mechanics but Russian 1.03 has changed | 15 | 6 abilities (`AbilityDescribe`: `perkSwordplayProfessional` 25%/40%, `perkImmediateReload`, `perkLightRepair`, `perkStormProfessional` 20%, `perkIronWill` — “mutiny does not start”, `perkTrustworthy`) and 9 items (`ItemsDescribe`: “+1 Leadership/Luck/Commerce/Melee Combat”, “−1 Luck/Leadership” bonuses absent from US descriptions) |
| Xbox console strings in US `common.ini` (`Wait for save` “do not turn off your Xbox”, `Memory card` “Memory Unit”, `Change key` “Controller Configuration”) | 3 | replaced by PC translation of Russian |
| Shortened (US text 1.6+ times longer) | 2 | `You give item` → `You gave away an item`, `land_commands` → `Party status and commands for actions on land.` |
| **Total translated by agent** | **143** | 86 script literals + 23 quest entries + 34 TEXTS keys |

**Principles.** Translate Russian 1.03 text (not US: it is not in Git), by meaning and in tone of neighbouring US lines of same NPC/quest (dry formal governor tone, “sir/captain”, moderate “pirate” speech, drunken
soldier's stutter retained); 17th century (`warden`, `commandant`, `colors`, `corsairs`); proper names as in US version (`Falaise de Fleur`, `Isla Muelle`, `Douwesen`, `Conceicao`, `Redmond`, `Oxbay`,
`Governor Silehard`, `Greenford`); skill names as in English interface (`Leadership`, `Melee Combat`, `Commerce`, `Luck`). Format specifiers and `\n` retained (loader checks); length close to original.
One shared line for four governors of different nations is deliberate simplification.

**Places needing human proofreading** (marked `REVIEW` in `manual-strings.json`, 17 entries): 12 governor “sink the pirate” lines (code concatenation: `…sink the ship '` + name + `', believed to be in the waters of the colony of ` + colony + `\nIf you complete this task, I will pay you the sum of ` + sum + `.`);
translation of `начальник` (chief) as `warden` for Simon Hanpool while journal uses `commandant`; 4 `boal_map.c` fragments (concatenation “Captain, … It looks like ” + group + `, under ` + flag + `vs. `). Less certain: `corsairs` for “корсары”,
“pirate colors”, jokingly stuttered drunken-soldier lines whose Russian originals are careless even in Russian version (“Пошлика со мной”, “мятежнику” (a malformed “come with me”, “to the mutineer”)); `Pirate` as murderer's name; `Restore Defaults`/`Change Current Settings` (button labels, usage not checked).

**US-data defects found and worked around** (would be visible to player): (1) **line shift** in `Douwesen Soldier_Dialog.h` and `isla muelle soldier_dialog.h`: US file one line shorter, `.c` alignment would shift 23–27 —
fixed with `pairs` correction; (2) alignment of all `COUNT_NE` files checked manually, others correct; for equal-length files independent alignment by length/punctuation matched index alignment everywhere; (3) `fonts.ini` (§1.5);
(4) semantic TEXTS drift (15, above); (5) console strings; (6) accented bytes; (7) `%%` at loanshark; (8) empty quest heading; (9) US title font contains uppercase only.

## 6. What remains Russian

187 `PROGRAM` literals with Cyrillic remain Russian (also Russian in US version: 168 byte-identical, 19 differ but US is Russian too; old US 1.0 Russian was not substituted for our 1.03).
List with index and original SHA-256 — `expected-overlay.json: left_russian` (no text). Classification:

| Group | Literals | Visible to player? |
|---|---:|---|
| `Enc_RapersGirl_dialog.h` 53, `Enc_Rapers_dialog.h` 14 — random “bandits and girl” encounter | 67 | **yes** (Russian text in English mode) |
| `quest_sailor_tmp.h` 15, `quest_sapper.h` 12 (“tmp” quests, probably unused) | 27 | probably not |
| `Rumour_Data.h` 7 + `Rumour_Data.c` 8 (rumours: Russian parody portion), `arnaud matton_dialog.h` 1 | 16 | yes (rumours) |
| `Valentin Massoni_dialog.c` — voice identifiers `voice\VIМА\VIМА0NN` with Cyrillic `М`,`А` | 23 | no (file keys), must not translate |
| Debugging: `Dialog_func.c` 6, `LEnc_login.c` 9, `quests_scenes.c` 4, `both_reaction.c` 2, `Docker Generated_dialog.c` 2, `Ralph Damerell_dialog.c` 2 | 25 | no (`Trace`) |
| `Locations/location_init.txt` 13 (field descriptions), `Locations/init/{Redmond,Oxbay,IslaMuelle,QuebradasCostillas}.c` 16 (“Порт.”, “Джунгли.” (Port, Jungle) …) | 29 | probably not (utility labels) |

Approximately 110 player-visible Russian strings total (first two visible groups + rumours). Translation optional (user decision: “≈ 90 Russian in US version too”); add to `manual-strings.json` without code changes:
for each string — `kind: literal`, file, index, `ru_sha256`, `en`.

## 7. Checks and tests

Current Node tests: `node --test korsary2-next/recomp/tests/test_prepare_english_*.mjs korsary2-next/recomp/tests/test_english_text.mjs`. **Historical Python run: 43 tests OK (≈ 0.5 s)**, on synthetic mini-base (CP1251, CRLF) and mini “US” game (CP1252): alignment (by index, `.c`, lines), substitution,
byte-identical code skeleton (including rejection of changed code/literal count/non-ASCII), file classes, `OVERLAY.json`, manual strings (SHA drift, override without `override`, specifiers, non-ASCII, unused entries, `pairs`), anchors,
refusal on nonempty `--out`/`--out` inside base or source, **no writes to `--base` and source** (trees before/after including failure; protected file with `000` permissions not read), images opened only `rb`, `--dry-run`, determinism
(two runs and mtime), CRLF/BOM/ASCII, character normalisation, specifiers, baseline without game text, `--check` (tampered byte, extra/missing file, changed code with “adjusted” baseline), source fingerprint.
**Mutations** (protection disabled -> scenario fails, mutant killed): skeleton, SHA drift, specifiers (manual and automatic), anchors, `--out` nonempty, `--out` inside base, `Characters_names.c` structure.
Optional: `K2_ENGLISH_OVERLAY=<directory> node korsary2-next/tools/prepare_english.mjs --check --out "$K2_ENGLISH_OVERLAY" --base korsary2-next/game` — real layer payload against `korsary2-next/game` (skeleton of each file, Cyrillic ≡ baseline) — passed 12.11.2026.

**Run on real data (12.11.2026):** `prepare_english.mjs --base korsary2-next/game --us-iso Disc1 Disc2 --out <scratchpad>/overlay-en` — rc 0, ≈ 6 s, ≥ 15 GB free not required (2 MB layer, images read without extraction); second run from single-disc image to another directory —
empty `diff -r`; `--check --out` (with `--base`, with `--us-game`) — “СВЕРКА ПРОЙДЕНА” (verification passed), 243 files. Images, `korsary2-work/game` working copy and `SAVE/` unchanged (checked by mtime, `hdiutil info` contains no images).

## 8. Limitations and risks

* **Not checked live:** Latin rendering with `rus` fonts in dialogue/journal/interfaces, wrapping and overflow, `STRSERVICE` behaviour with English `language.ini` (`WARNING: language ini files has different size`, `Language … not exist` in `system.log`),
  phrase concatenation from fragments (governors, `boal_map.c`), loading a slot after language change.
* Alignment is heuristic (`difflib` by skeleton, `DLG_TEXT` indices); confirmed: code skeleton, identifier anchors (≥ 99%), examination of all 10 divergent dialogues; **semantic match of 11 111 automatic pairs sampled** (length ratio, punctuation), not by a person.
  Russian 1.01–1.03 lines that replaced US meaning at same indices (e.g. `Malcolm Hatcher_dialog.h[10]`) read as US in English mode — layer's purpose.
* Layer bound to Russian base: `OVERLAY.json: base` (SHA-256 of overlaid files). Any new `PROGRAM` script change (new port patch) requires rebuilding layer and baseline; build refuses manual-string drift.
* NPC names and headings in game-creation language remain in slot (§1.7); `Characters_names.c` names are US lists (Russian lists in Russian mode).
* Legal status (R6) unchanged: layer built from user's images, no US text in repository (`expected-overlay.json`, `manual-strings.json`, `english-audit/results/` — only hashes, numbers, names and our translation),
  but **resulting overlay directory contains US text** and is not committed to Git; layer publication is user's decision.

## 9. What remains

**(Outdated: E1–E5 done; current list — section 11.7. Original E2 plan below.)**

* **E1** — host (`PORT_OVERLAY`, §1.2: another agent working on it), page (language choice, second OPFS directory, launch blocked until complete sync), `make_dist --overlay-dir <directory>` (manifest §1.3 + `overlay` block from `OVERLAY.json`).
* **E3** — loading screens (127 + 4), `Invasion` video; **E4** — voice (860 files, Russian `Greetings_alias.ini`). Both place files in same overlay directory and extend baseline.
* **E5** — preflight (§1.8), `verify_dist --overlay`, slot language marker (§1.7), `PORT_OVERLAY` + English `language.ini` integration tests in Node build.
* **Live acceptance** (another agent, separate origin and test slots): Latin in dialogue/interfaces/journal; key NPCs (Blaze, Malcolm, Danielle, merchants, governors); tutorial (control hints); world map (encounter phrases);
  quest journal (`kill_*`); ability and item descriptions; Russian remnants (§6, especially `Enc_Rapers`); `system.log`; Russian-mode regression.

## 10. Host and page (E1)

Author: E1 agent, 12.11.2026. Full description, design, tests, measurements and live check — `docs/overlay-e1.md`; here how the layer **is used** (file contract §1, source of truth for file inventory this document).

* **Host** (`host/core.c`, `kernel32.c`): `PORT_OVERLAY=<absolute host path>` (unset/empty/`0` — disabled, overlay code does not run). §1.2 rules implemented as follows: scope only `PROGRAM/`, `RESOURCE/` (index contains nothing else, even if directory contains
  `SAVE`, `options`, `engine.ini`); reads layer first, then base; enumeration union (base first in its own order/spelling but with layer data, then layer-only names); layer **read-only** — write/`CREATE_ALWAYS`/`TRUNCATE`/delete/
  move at layer path gives `ERROR_ACCESS_DENIED` (creating layer directory — `ERROR_ALREADY_EXISTS`, move to layer name — `ERROR_ALREADY_EXISTS`); new names created in base; `map_path` returns only base paths (identity §1.2.7 respected: one logical file — one host path);
  `..` does not leave layer root (layer path built from index, not guest text), symlinks inside layer not indexed; layer root inside game folder, containing it, or not a directory prevents host launch.
  **Layer requirements:** regular files and directories (no symlinks), only `PROGRAM/`+`RESOURCE/` (+`OVERLAY.json`, itself excluded from layer), no layer changes while game runs.
* **Page** (`web/overlay.mjs`, `port.js`): `?lang=ru|en` > `localStorage korsary2.lang` > Russian; for English `game-en/manifest.json` strictly checked before writing (paths §1.3, `size`+`sha256` per entry, 6 required files §1.8, `overlay.format` = 1, `overlay.base` checked against `game/manifest.json`),
  installed to second OPFS directory `korsary2-game-en` (`installed-en.json` marker, does not touch `installed.json` or SAVE) under base page SAVE lock; launch `PORT_OVERLAY=/opfs/korsary2-game-en`. Incomplete/corrupt/foreign-base layer or no space — English does not start, Russian offered.
* **Build:** `make_dist.py --overlay-dir <directory> [--overlay-name en]` → `game-en/` + manifest `overlay` block from `OVERLAY.json`; `verify_dist.py` — `overlay` block. E2 layer (242 files) accepted by packer and page validator.

## 11. E5: world map, unified file list, layer preflight, dist verification, slot language marker

Author: E5/W1 agent, 12.11.2026. Status: **implemented and checked synthetically and on real data without launching the game**; live (game, rendering, audio) **not checked** — section 12.

### 11.1. W1: world-map transition screen `WorldMap/reload/*` (Russian mode)

E3 found, R1 §3.2 was wrong: `PROGRAM/WorldMap/worldmap.c` includes `worldmap_reload.c`, `wdmReloadToSea()` sends `FADER_PICTURE` with `WorldMap\reload\sea.tga` (`Battle`, `Storm`, `Twister`), renderer opens `resource\textures\<name>.tx`
literally. Russian distribution files existed only in `RESOURCE/Textures/WorldMap/reload/Russian/`, `relocate_if_absent` covered only `Loading/Russian`. **Confirmed from code and data; fixed:** second rule in `korsary2-next/port.json`
(`reload/Russian` → `reload`), `recomp/web/port-config.js` recreated by `tools/configure.mjs` logic (without running it; `configuration consistency tests` keeps equality), `gamefiles.game_files`: 9826 files (same as before rule), 4 files
published as `WorldMap/reload/<name>.tga.tx`, no name collisions. `make_dist`, `serve.py`, page (`relocateIfAbsent` on folder import) and `verify_dist` obtain rules from `port.json`/`PORT` — no code change needed (`verify_dist.DEFAULT_RELOCATE_RULES`
and `english_assets.DEFAULT_RELOCATE` fallbacks extended with second rule). Existing players retain old `reload/Russian/*` as extras (≈ 2 MB), new files downloaded (`test_resync_preservation.mjs` §9b), SAVE/SAVE_META/options untouched.
English layer rebuilt: four world-map screens became base-file **overrides** (`OVERLAY.json: base` 566 → 570 entries, `resources.worldmap.new_only` 4 → 0; baseline has `kind: replace`, `base_sha256`; `OVERLAY.json` +481 B). Real-data build
(both sources: Disc 1 + Disc 2 and single-disc image) — `--check` “СВЕРКА ПРОЙДЕНА” (verification passed), two runs produce byte-identical directory (empty `diff -r`) and one video. Tests: `test_relocate_if_absent.mjs` (table of two rules, real folder: names requested by script found after relocation),
`test_make_dist_coverage.mjs` (real inventory), `test_verify_dist.py`, `test_resync_preservation.mjs`, `test_prepare_english_*.mjs` (historically 77 Python tests; world-map overlay, old `port.json` with one rule gives “overlay only”, defaults equal real `port.json`).

### 11.2. Unified required-file list

Previously `OVERLAY_REQUIRED` was copied into `web/overlay.mjs`, `web/gamefiles.py`, `tests/verify_dist.py`. Now it is written **once — `recomp/web/overlay-required.json`** (`format: 1`, `required` fields — 6 contract files §1.8, `recommended` — layer files whose absence only warns
(`Greetings_alias.ini`, three `TEXTS/ENGLISH` files, `Loading/Sea` and `WorldMap/reload/sea` screens), `base_recommended` — BASE files needed by English (other `TEXTS/ENGLISH/*`, Latin title font `Menu font.tga.tx`)). Readers:
page — `import … from './overlay-required.json' with { type: 'json' }` (if file missing or invalid, `overlay.mjs` does not load, page does not offer English, Russian unaffected; `make_dist` finds import and includes file in dist, `serve.py`/worker use `application/json`);
`gamefiles.load_overlay_required` (build refuses any file defect); `verify_dist.read_overlay_required` (also checks **dist copy** requires at least the list). “Page does not launch incomplete layer” protection is not weakened (`validateOverlayManifest` still refuses before writing).
`RequiredListSingleSourceTest` (`test_overlay_dist.py`): all readers see one file, paths (except `language.ini`, needing separate preflight content check) are not duplicated in source, defective lists rejected, dist contains file, layer baseline contains each listed path; `test_overlay_page.mjs` — page sees same list.

### 11.3. English-layer preflight

`web/missing-resource-preflight.mjs`: `preflightOverlay` / `describeOverlayReport` / `checkOverlayBeforeRun` (report shape like base check, `kind: 'overlay'`; **read-only**: no `create`/writes, layer and base snapshots equal before/after). `port.js` calls `overlayResourceGate()` in `run()` **only when `english`**, after base
`resourceGate()` and **before** locks and runtime; Russian mode does not execute this code (no `[preflight-en]` in log). Input: layer root `korsary2-game-en`, base root (for its files), layer list (validated manifest or installation marker) and version; mode `verified` (sizes and SHA-256 from list, as base check; list compared to `version`)
or `presence-only` (no list/version mismatch).

| What | Class | Result on problem |
|---|---|---|
| required layer files (`required`): missing / unreadable / directory instead of file / size / SHA-256 | fatal | **English mode refused**: `RES_MISSING`, `RES_UNREADABLE`, `RES_NOT_FILE`, `RES_SIZE_MISMATCH`, `RES_HASH_MISMATCH`, `RES_CHANGED` |
| layer `language.ini`: no active `defaultLanguage = English` line (all active lines must say English; comments excluded; value case-insensitive; > 64 KB not read) — game would remain Russian under English label | fatal | refusal, `RES_BAD_CONTENT` (checked independently of manifest, including `presence-only`) |
| layer `recommended`, base `base_recommended` files | warn | launch proceeds, warning in console and `window.overlayPreflight`: some text/voice may remain Russian |
| layer list inconsistent with `version` / disk version different / no list | warn (info) | `presence-only`: hashes not checked, mandatory files and language checked |
| check itself fails (exception, no WebCrypto) | nonblocking | `PF_INTERNAL` / `PF_NO_HASH` warning; `checkOverlayBeforeRun` does not throw |

Refusal: `langState.overlay = 'error'`, text “Английский слой не прошёл проверку: <файл> — <причина> (код …). … Английский режим не запущен; русская установка и сохранения не затронуты… Нажмите «Вернуться к русскому»” (English layer failed validation; English mode not started; Russian installation and saves unaffected; return to Russian), button `#lang-back-ru`
visible, Play blocked; no locks acquired, nothing started (after return to Russian, game starts). Log: `[preflight-en] fatal|warn <code> <path> — <details>` (console), `[lang] overlay preflight refused <code>`. Decisions: strictly refuse only where game would definitely receive a mixture/crash
(required layer files; their size/SHA mismatch also refuses, since `verifyOverlayFiles` already refuses size on launch, and a corrupted script would not compile); warn for everything else.
Tests: `test_missing_resource_preflight.mjs` (37 groups, including 11 new: clean layer, no `language.ini`, Russian `language.ini` with correct manifest size and SHA, `languageIniProblem` table, each of 6 required files × (missing/size/SHA/directory), no layer/base directory,
recommended → warning, `presence-only`/inconsistent list, check failure nonblocking, read-only, integration in `port.js`), `mutate_missing_resource_preflight.mjs` (**39 mutants, all caught**: 18 new), historical diagnostic materials (removed) (real OPFS in ephemeral Chromium),
`test_overlay_browser.mjs` scenario **Q** (real `port.js` and module in Chromium: layer without recommended files launches with warnings; Russian `language.ini` of same size refuses before locks, return to Russian, Russian launch). Real layer (762 files) check gives `ok`, 19 files, 11 ms.

### 11.4. `verify_dist --overlay` and English-mode video

`node recomp/tests/verify_dist.mjs --dist DIST --overlay [english-layer/expected-overlay.json] [--full-hash]` (implies `--require-overlay`) adds **`overlay-layer`** block: exactly the baseline set of 762 paths, size and SHA-256 of every file, classes by path (`loading`, `worldmap`, `voice`, `aliases`, `text`)
with `totals` counts and bytes, `resources` field (`loading`/`worldmap`: files, bytes, without base file; `voice`: selected, bytes, replaced/added), `OVERLAY.json` (manifest `overlay` block written as file matches baseline size and SHA-256) and `overlay.base` equals baseline `base_sha256`,
**independence from base** (layer file in `game/manifest.json` must have `base` entry; `base` names only base file; `game/` without layer contents — previous `overlay` block), and `videos/English/Invasion.mp4` in dist (different size/SHA — “different ffmpeg version” warning, absent — refusal). Missing/unreadable baseline refuses.
`overlay` block now also requires **dist copy of `overlay-required.json`** to exist and require at least mandatory list, and every `VIDEO_FILES_EN` video from `video-player.mjs` to be in `videos/` (if `videos/` entirely absent, warning as for Russian). `make_dist.py` with built layer warns about
`videos/English/Invasion.mp4` absent from package (`--videos`), as for `VIDEO_FILES`. **Real data** (real working copy, real layer, video, `make_dist` → 9826 + 762 files, 1223 MB + 75 MB network) `verify_dist --overlay --full-hash --source-game` — PASS all blocks; without video both blocks fail.
Tests: `test_overlay_dist.py` (`OverlayLayerCheckTest`: 8 tests, all mismatch types; `make_dist` warning).

### 11.5. Slot language marker

**Format.** `SAVE_META/<slot>.lang`, exactly 2 bytes `en` (`ru` allowed, host does not write it). Beside `SAVE_META/<slot>.time`; **outside `SAVE/`**, so `FindFirstFileA("SAVE\\*")` does not see marker and `find_next` neither reads nor touches it. Slot without marker = “unmarked”
(old slots and everything created in Russian mode — language unknown, not “Russian”).

**Host** (`host/kernel32.c`, only builds with `SAVE_META_ON`, i.e. browser): (1) **genuine slot creation** (`CREATE_NEW`, `CREATE_ALWAYS`/`OPEN_ALWAYS` on missing name: engine overwrites slot by deleting old and creating anew) with overlay enabled (`overlay_active()`) writes `en` marker with `fsync`;
write failure does not break file operation (partial marker removed). (2) **Russian mode writes nothing new**; only “new” action is `stat` probe of exact marker name on genuine creation: stale marker for missing slot removed to avoid marking new slot. (3) In-place overwrite of existing slot
(`CREATE_ALWAYS`/`TRUNCATE_EXISTING` without deletion) **does not change marker** (like creation time); unmarked slot does not acquire one. (4) `DeleteFileA` (including strict-mode “delete on last close”) deletes marker with slot **in any mode** (slots shared: English-session marker must not outlive slot during Russian session);
marker name sought case-sensitively, like `.time`. (5) `MoveFileA` (native/Node only; browser build rejects moves) moves marker to new name. (6) **SAVE_TX** (opt-in): `arm` line gets optional `lang=<4 hex>` (`656e`/`7275`) **only if slot has valid marker** — Russian-mode journal byte-identical;
invalid marker (not 2 bytes, not `en`/`ru`) = “no marker”. Page (`save-tx.mjs`): strict field parsing (`656e`|`7275`, otherwise journal line corrupt), rollback restores marker with slot and time; missing field = no marker existed, and marker left by failed attempt goes to quarantine `…<tx>.lang/`; orphan after “explicit deletion” cleaned likewise.
**Marker meaning:** language of host session in which slot was created (not language of game originally started): slot loaded from another language and saved again gets current marker (engine always deletes and recreates). Names inside slot remain as at game start — marker only warns.

**ZIP export/import/backups** (`save-export.mjs`, `save-import.mjs`, `save-protection.mjs`): `SAVE_META/<name>.lang` entry per slot; encoding accepts `lang` exactly 2 bytes `en`/`ru`, decoding rejects archive with other size/value, incorrect name (same naming rules as slots and `.time`), duplicate, compression, CRC;
ZIP entry limit raised 1024 → 1536 (512 slots × slot+time+marker); marker for slot absent from archive ignored (in `ignored`); import follows same marker decisions as time (`planLangRestore`): written slot receives archive marker, **replaced slot without archive marker loses old one** (stale marker must not assign a language to new bytes), matching and skipped slots retain theirs;
recovery point before replacement now saves **marker and time** of replaced slots (previously bytes only); import result `langWritten`. Export and backups read marker themselves (`readSaveDirectory(dir, gameRoot)`). Without marker archive is **byte-for-byte unchanged**. `SAVE_META` remains entirely outside dist/serve/manifest/page assets (`selectGameAssets`, `PLAYER_DIRS`; `make_dist`, `serve`, `dist_http_smoke`, `save-tx` tests).

**Startup notice** (`overlay.mjs`: `readSlotLanguages`, `summarizeSlotLanguages`; `port.js`: `updateSlotLanguageNote()`, element `#slot-lang-note`, log `[lang] slots of another language or without a mark {…}`, `window.slotLanguages`): nonblocking text below language switch; reads `SAVE` and `SAVE_META` read-only, never blocks launch or throws.
Russian mode: if slots marked `en` exist — “Часть сохранений (N из M) создана в другом языке; имена персонажей в них могут отображаться на другом языке…” (some saves were created in another language; character names may appear in another language). English mode: same for `ru` markers (host does not write them), **and** “N из M сохранений не помечены языком (созданы до появления метки): если они из русской игры, имена персонажей в них могут оставаться русскими” (N of M saves lack a language marker; if from a Russian game, names may remain Russian) — cautious, no assertion that they are Russian.
Updated on language change. Tests: host — `test_save_meta_time.c` (`run_save_meta_time.sh native wasm node`), `test_save_tx.c` (`run_save_tx.sh all wasm node`), host mutations `node recomp/tests/mutate_save_lang.mjs` (9 `kernel32.c` mutants, all killed); page — `test_save_tx.mjs`, `test_save_export.mjs`, `test_save_import.mjs`, `test_save_backup.mjs`, `test_overlay_page.mjs`, `test_overlay_browser.mjs` (scenario **R**: real `port.js` in Chromium, slots and markers in OPFS, notice does not block Play, SAVE/SAVE_META unchanged).

**Russian mode unchanged** (evidence): `run_file_share_semantics.sh diff` — 313-line trace identical to old `host/` (pre-change copy) with all `PORT_OVERLAY` variants; mutating syscall counts and final SAVE/SAVE_META files for SAVE_TX `same/rename/fresh/trunc/delete/legacy` scenarios in browser configuration
**match** old tree (OPS 61/61/51/55/10/60), no `.lang` created; journal without `lang=` field; ZIP without marker byte-identical; page in Russian mode does not call layer check.

### 11.6. E5 tests in one list

Host: `run_save_meta_time.sh native|wasm|node`, `run_save_tx.sh all|wasm|node`, `run_overlay.sh native|tsan|diff|wasm|node`, `run_file_share_semantics.sh native|tsan|savetx|diff|wasm|node`. Node: `test_overlay_page`, `test_overlay_browser` (A–R), `test_missing_resource_preflight`, `mutate_missing_resource_preflight`, `test_save_*`,
`test_relocate_if_absent`, `test_resync_preservation`. Python `-I`: `test_overlay_dist` (34), `test_make_dist`, `test_verify_dist`, `test_serve_path_safety`, `test_dist_http_smoke`, `test_prepare_english` (77).

### 11.7. What remains

* **Live acceptance** (section 12) — only part not checked: game, Latin rendering, audio, video, real OPFS host (layer directory listing), phrase concatenations, layout.
* **Rebuild `game.wasm`** (coordinator): without `port_overlay_state` export page refuses English launch; `.lang` marker and `.lang` move on `MoveFileA` appear in browser build only with new `kernel32.c`.
* Marker reflects host-session language when saving, not language of originally started game (11.5); “loaded Russian slot and saved in English” cannot be distinguished without parsing slot format.
* Russian remnants (§6: `Enc_Rapers*`, rumours), `manual-strings.json` `REVIEW` proofreading, US voice volume (−5.6 dB), normalisation (E4c) — user decisions after live acceptance.
* Layer publication (US content, R6) — user decision; layer directory and `videos/English/Invasion.mp4` not committed to Git.

## 12. Live English-mode acceptance (for another agent)

Conditions: **separate origin and browser profile**, test slots, do not use user saves. First build `game.wasm` with E1+E5 host (`grep _port_overlay_state build/game.js`), then dist:
`node recomp/web/make_dist.mjs --game korsary2-next/game --out dist-test --overlay-dir <layer directory> --videos <videos-web with English/Invasion.mp4>` and `node recomp/tests/verify_dist.mjs --dist dist-test --overlay --full-hash` (PASS expected, no video warnings). Open `?lang=en&log` (host and page console logs). Each item states expectation; record deviations with exact log line.

1. **Clean English installation.** Empty profile → `?lang=en&log`: install base then layer (“Английский слой: X / Y МБ”, English layer: X / Y MB); `window.langInfo.overlay === 'ready'`; console `[lang] overlay ready {"files":762,…}`, `[install-en] …`; two OPFS directories `korsary2-game`, `korsary2-game-en` with `installed-en.json`; layer ≈ 119 MiB.
   Press Play: `[overlay] on: /opfs/korsary2-game-en (read-only…)`, `window.langInfo.launched.hostState === 1`, `window.overlayPreflight.status` — `ok` (or `warn` without `fatal`), **no** `[preflight-en] fatal`. In game `system.log`: English `language.ini`, no `Language English not exist`, no `Can't load texture`.
2. **Startup speed** (overlay directory listing in OPFS): time from Play to main menu in English versus Russian (first opening of `Textures/Loading` (122 files), `Sounds/VOICE` (393+231), `PROGRAM/DIALOGS` (214); on second launch); measure and record numbers; record noticeable delay on first entry to a location.
3. **Main menu and logos.** Bethesda/Disney/Akella logos and Credits video not shown; “Credits” button has no effect; English game logo (`potc_logo`); menu headings Latin (uppercase `menu font`), no Russian text or garbled characters.
4. **New game, dialogues, journal, interfaces.** Latin everywhere: Blaze/Malcolm/Danielle/merchant/governor dialogues, quest journal (`kill_*`), ability (`AbilityDescribe`) and item (`ItemsDescribe`) descriptions, help, settings (`Video Settings`, `Brightness`…, `Restore Defaults`), save window (`save game limit`), ship/town names. No “й/ё/ж” instead of `é/ç/ô` (layer replaces characters with ASCII), no missing characters or overflow
   (especially `perkAdvancedCommerce` and `interface_strings.save game limit` — `len_ratio_hi`).
5. **Russian remnants.** Random “bandits and girl” encounter (`Enc_Rapers`, `Enc_RapersGirl`: 67 Russian literals), rumours (`Rumour_Data`, 16 Russian literals) — expected Russian; record other Russian text encountered (outside §6 list).
6. **Malcolm tutorial.** Hints refer to the “assigned command” and control settings (not fixed F3/Ctrl… keys): 8 rewritten lines (indices 8, 34, 36, 48, 50, 54, 157, 235) read sensibly, “usually Space” as in Russian port text.
7. **Phrase concatenations from `manual-strings.json` `REVIEW` list** (17 entries): 12 governor “sink the pirate” lines (take quest from four nations' governors: `…sink the ship '<name>', believed to be in the waters of the colony of <colony>. If you complete this task, I will pay you the sum of <amount>.`), Simon Hanpool's `warden` versus journal `commandant`,
   4 `boal_map.c` fragments (world-map encounters: “Captain, there's a battle ahead. It looks like <group>, under <flag> vs. …”); drunken soldier (stutter), murderer's `Pirate`, `Restore Defaults`/`Change Current Settings` labels. For each, check full phrase readability, no doubled spaces/quotes/missing words.
8. **Loading screens.** English labels (“Tavern / Loading…” etc.) on entry to **tavern** (`Tavern_01`), **house**, **fort**, **landing** (jungle/shore), **sea** (`Sea`), relocated names (`Loading/Russian` → `Loading`). No white/empty screens, no `Can't load texture` in log. **World-map transition** (W1): `Sea`, `Battle` (encounter), `Storm`, `Twister` — picture exists
   (English in English mode, **Russian in Russian mode** — check both: previously screen could be empty).
9. **Voice.** Greetings from NPCs of different nations (English, Dutch, French, Spanish, Portuguese; US `Greetings_alias.ini`): correct NPC/nation's voice, no Russian voices, “silent” lines (192 new files) audible; compare volume of US voices and common effects (US median −5.6 dB) — loud enough, normalisation needed (E4c). `Sound` from `sound_alias.ini` without `.wav` open errors in log.
10. **Invasion video** leaving Oxbay: `videos/English/Invasion.mp4`, English audio, keyboard skip; Russian mode — `videos/Russian/Invasion.mp4` as before (network shows requested file: `videos/English/Invasion.mp4` or `videos/Russian/Invasion.mp4`). Other videos (Trailer, Artefact, …) identical in both modes.
11. **Language change and slots.** Create slot in English mode → OPFS has `SAVE_META/<slot>.time` and `SAVE_META/<slot>.lang` (2 bytes `en`). Overwrite same slot (engine deletes and recreates): marker remains `en`, time new. Delete slot: `.time` and `.lang` disappear. Switch to Russian (`#lang-ru`) and reload: **notice** “Часть сохранений (N из M) создана в другом языке; имена персонажей…” (some saves created in another language; character names…),
   Play not blocked, slot loads (names inside English). Create Russian-mode slot: no `.lang`. English mode on profile with old slots: “N из M сохранений не помечены языком…” (N of M saves have no language marker). Load other-language slot and save: marker matches current mode (11.5). Export saves to ZIP → archive contains `SAVE_META/<slot>.lang`; import into clean profile restores markers.
   Start with `?saveTx=1` in English mode: interruption (close tab) during save → next startup rollback restores slot, time and marker.
12. **Refusal on damaged layer.** Stop game, in DevTools → OPFS replace layer `RESOURCE/INI/TEXTS/language.ini` with Russian (`defaultLanguage = russian`, same size) → `?lang=en`: “Английский слой не прошёл проверку: … RES_BAD_CONTENT … осталась бы русской” (English layer failed validation; game would remain Russian), Play blocked, “Вернуться к русскому” (Return to Russian) works and starts Russian game; delete any required layer file — startup repair or refusal (E1); reinstalling layer restores mode.
13. **Russian-mode regression.** Without `?lang` and with empty `localStorage`: one `HEAD game-en/manifest.json` on network, no requests to `game-en/` objects, no `[overlay]` log, `PORT_OVERLAY` unset, no `[preflight-en]`; loading screens (including world map), voices, videos, save/load, backups as before E1. Compare `korsary2-game/installed.json` and files before/after layer installation (unchanged).
14. **Two tabs.** Game running in first tab (holds `korsary2-game:save-backup` lock); second uses `?lang=en` and switch: layer installation refuses (“заняты другой операцией”, busy with another operation), Russian installation and slot unaffected; changing language in running game does not change language (applies next launch).
15. **Disk and quota.** Layer ≈ 119 MiB raw (≈ 71 MiB network): insufficient quota refuses BEFORE writing (layer directory not created), space message; `navigator.storage.estimate()` before and after installation.
16. **Logs.** Collect `system.log`, page console (`[lang]`, `[install-en]`, `[overlay]`, `[preflight-en]`, `[file]`): no `[overlay] … refused` (overlay write refusal) during normal game; no `SAVE_META(…): lang … failed`; no `Can't load texture`, `Language … not exist`, `language ini files has different size`.
