# content-patches: game-data changes in the working copy

This directory is used by `tools/prepare_game.mjs`. It describes how
`korsary2-work/game` differs from the original repack and makes it possible to
recreate the working copy from a clean repack. For the detailed report,
verification method and limitations, see `docs/prepare-game-b3.md`.

## Contents

| File | Purpose |
|---|---|
| `01…11-*.patch` | Eleven patches: ten `PROGRAM/**` scripts and `RESOURCE/INI/INTERFACES/boal_map.ini` (see table below) |
| `expected-manifest.json` | Reference differences from the repack: 11 changed files with before/after SHA-256, 1,056 added files with size and SHA-256, counters, a repack-content fingerprint, and the ffmpeg version. It does not list all 10,000 files. |
| `.gitattributes` | `*.patch -text`: patches preserve original CP1251 bytes and must not be re-encoded or normalized. |

Game resources (`.wav`, `.ogg`, `.gm`, textures) are not stored in this directory:
`expected-manifest.json` records their names, sizes and SHA-256 hashes. The ready
resources are in `distribution/` and can be restored for development as described
in `docs/BUILD_FROM_CLONE.md`.

## Patch format

A `.patch` file is a unified diff with zero lines of context and a comment header:

```
# path: PROGRAM/Dialog_func.c
# sha256-before: …      <- repack file; application fails if SHA-256 differs
# sha256-after: …       <- result; verified after application
# eol-before: crlf      <- line endings before/after (crlf|lf); diff lines are LOGICAL lines without CR/LF
# eol-after: crlf
# final-newline: yes
```

Application is exact, with no fuzz or offsets: every `-` line must match or the
operation fails without changing the file. CP1251 bytes are not re-encoded. If
the file already has `sha256-after`, the patch is considered applied
(idempotence). Generate and check with `tools/make_content_patch.mjs patches|manifest`.
Each generated patch is immediately applied to the before version and compared
with the after version.

## Changes and rationale

All patches are text diffs of scripts and INI files.

| Patch | File | Change |
|---|---|---|
| 01 | `PROGRAM/Characters/init/IslaMuelle.c` | `ch.model = "corsair2_1"` -> `"corsair2"` (Pepillo Lazaro: the `corsair2_1` model is missing on disk) |
| 02 | `PROGRAM/Characters/init/StoryCharacters.c` | `"ANIMISTSt2"` -> `"Animists2"` (ANIMISTS_04) |
| 03 | `PROGRAM/Characters/init/TempQuestCharacters.c` | `"corsar2"` -> `"corsair2"` (two occurrences: Ethilrede Claar and Giraldo Figuiera) |
| 04 | `PROGRAM/DIALOGS/Malcolm Hatcher_dialog.h` | Tutorial hints replace F3, У, Й, Я, Ctrl, Enter and Space with the assigned command because the port uses a different layout. |
| 05 | `PROGRAM/Dialog_func.c` | `TimeGreeting()`: use “Good day” only if `LanguageGetLanguage()=="English"`; otherwise use the Russian greeting. |
| 06 | `PROGRAM/INTERFACE/boal_map.c` | In the encounter dialogue, `downstep` moves focus to No only when it is available. |
| 07 | `PROGRAM/INTERFACE/interface.c` | `SELECT_TRACE` traces for F2 investigation and the **actual fix**: `DeleteAttribute(&InterfaceStates,"LaunchAfterFrame")` clears the deferred-launch guard. |
| 08 | `PROGRAM/INTERFACE/select_menu.c` | Only `SELECT_TRACE` traces (`Trace(...)`); no change to game behaviour. |
| 09 | `PROGRAM/SEA_AI/AIBalls.c` | Rebind four global projectile arefs to `NullCharacter` after deleting `AIBalls` to avoid dangling references during save serialization. |
| 10 | `PROGRAM/reload.c` | Rebind `reload_locator_ref` to `reload_xaddress` in two places. |
| 11 | `RESOURCE/INI/INTERFACES/boal_map.ini` | `command = downstep,select:B_CANCEL` -> `command = downstep` (the script selects focus; patch 06). |

### Notes

* **Patches 01–03 change CRLF line endings to LF.** The files were rewritten in
  full (diffs of 3,868, 6,076 and 7,230 lines for one or two changed lines).
  The other eight files retain CRLF. The working copy contains these exact
  bytes, so the patches reproduce them (`eol-before: crlf`, `eol-after: lf`).
  The effect of LF on the engine's script parser was not tested separately:
  the game launched after November 9 (sessions on November 11), and the logs
  contained no parse errors for these files. Do not treat the line-ending
  change as intentional. If reverting it, update the patches and reference
  manifest together (`tools/make_content_patch.mjs`).
* **The `SELECT_TRACE` traces in patches 07 and 08 are debugging traces.** They
  write to `system.log` and were used only to investigate F2. They may be removed
  separately, but doing so changes the reference manifest. Patch 07 also contains
  the actual deferred-launch guard fix.
* Patches apply only to repack files with the exact known SHA-256. A different
  edition causes an error rather than a silent corruption.

## Non-text data changes outside patches

These changes are made by `tools/prepare_game.mjs`, not by patches:

* `RESOURCE/MODELS/Items`, `RESOURCE/Textures/Items`: every file in `…/Ammo` absent
  from `Items` (21 `.gm` files and 26 textures; one name changes case from
  `blade6.tga.tx` to `Blade6.tga.tx`, matching the working copy).
* 970 `.wav` files converted from `.ogg` (`scripts/restore_russian_voice.mjs`, ffmpeg).
* `RESOURCE/Sounds/MUSIC`: 37 `.ogg` files from `setup-1.bin`.
* `RESOURCE/MODELS/Heads/h_Offic_hol.gm` and
  `RESOURCE/animation/Heads/h_Offic_hol.ani` (a byte-for-byte copy of
  `h_Offic_eng.ani`, referring to the existing `h_Offic_eng.an`; N6), via
  `tools/apply_content_fixes.mjs`.
* `engine.dll` and `data1.dat` (StarForce protection) are not copied or read;
  they are also absent from the working copy.

## Updating

After any new change to `PROGRAM/**` or game data in the working copy
(`korsary2-work/game`), regenerate the reference manifest and patches;
otherwise `prepare_game.mjs --check` reports a mismatch:

```
node tools/make_content_patch.mjs patches  --repack <repack>/game --work korsary2-work/game --out content-patches <paths relative to game/>
node tools/make_content_patch.mjs manifest --repack <repack>/game --work korsary2-work/game --out content-patches/expected-manifest.json --patches-dir content-patches
node tools/prepare_game.mjs --repack <repack>/game --out korsary2-work/game --check
```

The `patches` command renumbers patches from `01`; the path list must include all
changed files.
