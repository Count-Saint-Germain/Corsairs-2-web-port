> Historical technical document: intermediate diagnostic runs have been removed. Their snapshots and example commands are unavailable; the current instructions are in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md).

# B3: reproducible preparation of game data (`tools/prepare_game.mjs`)

The Node.js implementation is covered by `node --test korsary2-next/recomp/tests/test_prepare_game_node.mjs` and `test_prepare_game_core.mjs`. The Node.js patch generator is covered by `node --test korsary2-next/recomp/tests/test_make_content_patch.mjs`.


Date: 12.11.2026. This closes gap `N1` in the historical log (removed), section 5: the working copy `korsary2-work/game`
differed from the repack, but only some changes were encoded. The working copy can now be reproduced from the clean repack and
verified by inventory and SHA-256.

**Verdict: reproducible.** `prepare_game.mjs --repack <repack>/game --out <new-directory>` produces a directory that differs from
`korsary2-work/game` only in system-created files (see §4). Verified with `diff -rq` and the built-in baseline comparison (including
`--deep`), in two independent runs on 12.11.2026.

Work files (all new; no files in another person's area were changed):

* `korsary2-next/tools/prepare_game.mjs` — preparation script;
* `korsary2-next/tools/make_content_patch.mjs` — maintainer tool that generates patches and the baseline;
* `korsary2-next/content-patches/` — 11 patches, `expected-manifest.json`, `README.md`, `.gitattributes`;
* `korsary2-next/recomp/tests/test_prepare_game_node.mjs` and `test_prepare_game_core.mjs` — regression tests against a synthetic mini-repack;
* this report.

## 1. Source and method for each change

Source data: `diff -rq` between the repack and `korsary2-work/game` (12.11.2026), plus Git history, logs, and documents.

| Difference | Details | How obtained (source) | How reproduced now |
|---|---|---|---|
| `PROGRAM/**` (10 files) and `boal_map.ini` | character model fixes, tutorial prompts, encounter-dialog focus, aref rebinding, F2 chain analysis (traces + deferred-launch fence fix) | Git: `4fb6c5f`, `d95efa3`, `2f00c2b`, `f41895f`, `d8c093c`, `96e3ab1`, `9208026`, `dda40ec`, `f5fd9dd`; SHA-256 of patches 09 and 10 matches the pins from historical diagnostic materials (removed) | `content-patches/*.patch` (step 2), see `content-patches/README.md` |
| `Items/*.gm` (21) and `Textures/Items/*` (26) | byte-for-byte copies from `Ammo` (SHA-256 checked against `MODELS/Ammo` and `Textures/Ammo`) | historical log (removed), 8.11.2026: “system item audit” (`18c341c`; earlier `6d2a4a2` for `blade6`). No script existed | step 3: all files in `Ammo` missing from `Items` (case-insensitively), without overwriting; only `Blade6.tga.tx` changes case |
| 970 `.wav` | decoded copies of 739 `.ogg`: Russian voice 231 -> two folders (`VOICE/RUSSIAN` and `VOICE`) = 462, 508 effects next to `.ogg` | `scripts/restore_russian_voice.mjs` (in `web-port/scripts`; no scripts in `korsary2-next/tools` or `~/ports/korsary2`); historical log (removed), “Achieved” item 3; `docs/sound-duplicates-d2.md` §2 (created 5.11.2026) | step 4: same pipeline, but without temporary files (see §3) |
| `Sounds/MUSIC` (37 `.ogg`, 46.8 MB) | original music missing from the repack | extracted from `game/setup-1.bin`: **7z, Copy method**, 37 files, 49 083 812 bytes (historical log and diagnostic materials removed; `docs/sound-duplicates-d2.md` §2). No script existed | step 5: `7zz x`/`7z x`, or `--music-from DIR` |
| `Heads/h_Offic_hol.gm` | copy of `h_Offic_eng.gm` (Douwesen coast guard) | `tools/apply_content_fixes.mjs` (`1ce5ff3`) | step 6: called unchanged |
| no `engine.dll`, `data1.dat` | StarForce protection was not copied to the working copy | historical logs (removed), `docs/bringup-notes.md` | step 1: neither copied nor read |

`setup-1.bin` inside `game/` (49 MB) is the same archive; `file` identifies it as “7-zip archive data, version 0.3”. Installed
`7zz` (7-Zip 26.05) and `7z` (p7zip 17.05) read it without problems. `innoextract` is not needed (it is not Inno Setup; the Inno
installer is a separate `setup.exe` beside the repack and was not touched).

## 2. How the script works

```
node tools/prepare_game.mjs --repack "<repack>/game" --out <NEW-directory> [--skip-wav] [--music-from DIR] [--deep]
node tools/prepare_game.mjs --repack "<repack>/game" --out <directory> --check     # verification only, writes nothing
```

Steps: 0 preflight checks; 1 APFS clone (`cp -c -R -p`, otherwise a filesystem copy) of the top-level repack entries without `engine.dll`/`data1.dat`;
2 patches; 3 Items; 4 `.wav`; 5 `MUSIC`; 6 `apply_content_fixes`; 7 verification. Return codes: 0 — ready and verification passed,
1 — error or refusal, 3 — build exists but verification failed.

Guarantees (all covered by tests):

* `--repack` is not written to: read-only, temporary files are created in `--out`. A test compares the repack tree (sizes, SHA-256, mtime) before and after a successful and a failed run. Protected test files have `000` permissions: any attempt to read their contents would fail.
* `--out` must be a new or empty directory. A nonempty directory is refused without `--force`. `--force` does not delete or overwrite anything; it only fills in missing files (for repeat runs). The script refuses if `--out` equals or is inside the repack or inside `korsary2-work/game`.
* Free space is checked before writing: an estimate (clone: about +209 MB; regular copy: about 2.5 GB) and available space are printed, with a 256 MB margin.
* New files are created through a temporary file and `os.link` (no overwriting). Existing contents are not replaced. Patches replace a file with a new inode (when cloned, the original repack is unaffected).
* Each step is idempotent: a repeat run with `--force` changes nothing (the test compares mtime).
* A patch is applied strictly: the before SHA-256 must match and the after SHA-256 must also match after application. Otherwise the script refuses, leaves the file untouched, and performs no further steps.
* `SAVE/` and `options` in `--out` are simply copied from the repack. The script does not know the path to player data and does not write to `korsary2-work/game`.

### Verification (step 7)

The baseline `content-patches/expected-manifest.json` stores differences from the repack, not the full inventory: 11 changed files (before/after SHA-256), 1056
added files (970 `.wav`, 37 `.ogg`, 21 `.gm`, 26 textures, head `h_Offic_hol.gm` and its `.ani` — since 12.11.2026, N6) with sizes and SHA-256, counts (9541 repack files, 2 protected, 10 595 expected), and
a fingerprint of the repack inventory (SHA-256 of the “path + size” list). The check verifies that the path set (repack minus protected files plus additions) exactly matches `--out`
(case-sensitive), the sizes of all files, SHA-256 of added and changed files, and consistency of patches with the baseline. `--deep` additionally hashes
unchanged files and compares them to the repack. Only `.DS_Store` is ignored; `system.log`, `compile.log`, and everything under `SAVE/` are allowed as extras with a warning.

## 3. `.wav`: determinism

The pipeline matches `scripts/restore_russian_voice.mjs`: `ffprobe` (source sample rate and channels) -> `ffmpeg -c:a pcm_s16le -f s16le`
-> Node.js writes a classic 44-byte header (the game WAV reader expects `fmt` at 0x0c, `data` at 0x24, without an ffmpeg LIST chunk).
The difference is that data passes through memory rather than a temporary file and conversion uses 8 threads (writing in sorted order).

**Byte-for-byte reproduction confirmed:** all 970 `.wav` files from the historical preparation run matched the working copy by SHA-256 (ffmpeg 9.0.2, Apple clang, arm64). The Node.js implementation has additionally passed deep verification of the real repack and working copy and full synthetic preparation tests.
Entire files were compared, not just PCM. A synthetic test also compares PCM after byte 44 with direct ffmpeg decoding. **Limitation:** byte-for-byte identity
is not guaranteed with another ffmpeg version or Vorbis decoder (fractional rounding). The ffmpeg version is recorded in the baseline (`tooling.ffmpeg_version_line`);
the script warns before building if it differs, and a `.wav` SHA-256 mismatch will appear as a verification difference (code 3). The data remains a valid decode
of the same `.ogg`; the maintainer decides whether to accept a new baseline or install the same ffmpeg version. Without ffmpeg, `--skip-wav` creates a copy
without sound effects or voice. **The game will be silent**, and the script prints this warning.

Permissions of created `.wav` files: `0600` in the working copy, `0644` in this output. This does not affect the inventory or SHA-256.

## 4. Reproduction check (12.11.2026)

Environment: macOS, APFS, about 17 GB free before and after, `ffmpeg 9.0.2`, `7zz 26.05`.

```
node tools/prepare_game.mjs --repack "<repack>/game" --out <scratchpad>/prepared2 --deep   # verify the prepared copy
diff -rq <scratchpad>/prepared2 korsary2-next/../korsary2-work/game
```

Complete `diff -rq` output:

```
Files prepared2/.DS_Store and korsary2-work/game/.DS_Store differ
Files prepared2/RESOURCE/.DS_Store and …/RESOURCE/.DS_Store differ
Files prepared2/RESOURCE/MODELS/.DS_Store and …/RESOURCE/MODELS/.DS_Store differ
Files prepared2/RESOURCE/MODELS/Locations/.DS_Store and …/Locations/.DS_Store differ
Only in korsary2-work/game: compile.log
Only in korsary2-work/game: system.log
```

Explanation: `.DS_Store` is Finder metadata (different in the repack and working copy, does not affect the game, excluded from verification); the game
writes `compile.log` and `system.log` on launch (5.11.2026). There were no `Only in prepared` files; the contents of the other 10 594 files matched
(after adding `h_Offic_hol.ani` — 10 595, rechecked on 12.11.2026). `SAVE/` and `options` matched (the working copy had not been changed by a player).
The same copy is checked by `prepare_game.mjs --check --out korsary2-work/game` (read-only): verification passed, with warnings only about `system.log` and
`compile.log`. The working copy, repack, and `SAVE/` were not changed during the work (the repack contained no `.wav`, `.prepare*`, or files newer than the start of the work). The check directory
was removed.

A repeat run to the same directory (`--force`, `--music-from` pointing to existing `MUSIC`) created nothing and passed verification.

## 5. Tests

`node --test korsary2-next/recomp/tests/test_prepare_game_node.mjs korsary2-next/recomp/tests/test_prepare_game_core.mjs korsary2-next/recomp/tests/test_make_content_patch.mjs` covers preparation, patch primitives and generation. The predecessor Python implementation passed **29 tests** before the Node migration. Synthetic mini-repack: fake protected files with `000` permissions, CRLF and
CP1251 files, `Ammo`/`Items`, voice and effects `.ogg` (ffmpeg, vorbis, stereo), `setup-1.bin` archive (7z). The test manually builds the synthetic baseline “working copy”; patches
and baseline are generated by `make_content_patch.mjs`, so both generator and applier are tested. Coverage: full byte-for-byte reproduction; idempotence (mtime); two independent identical runs;
canonical WAV header and PCM; `--skip-wav`; `--no-clone`; refusal for nonempty `--out`/file/inside repack/inside working copy; empty existing `--out` allowed; repack
is not written (success and failure); protected files not read; insufficient space; `--dry-run`; patch SHA-256 mismatch (file untouched, further steps stopped); hunk and CRLF precision;
CP1251 and CRLF->LF; no escape from `--out`; `install_new` does not overwrite; only missing Items, `Blade6`; existing `Items`/`.wav` are not overwritten and verification detects this;
`--music-from`: foreign hash, missing, extra file, flat directory; 7z archive extraction with temporary directory cleanup; `--check` (missing, extra, allowed extra, no writes); `--deep`; baseline counts.
Mutation checking: removing the patch SHA-256 check, `--out` protection, and protected-file exclusion killed each mutant; replacing `os.link` with `os.replace`
was not killed (existence is checked before every write; `os.link` protects against races), so a direct `install_new` test was added.

## 6. Gaps and limitations

1. **ffmpeg is required for sound.** Byte-for-byte `.wav` equality was confirmed only for ffmpeg 9.0.2 (§3). Without ffmpeg, `--skip-wav` is available (the game is silent).
2. **`MUSIC` requires `7zz`/`7z`** (or `--music-from DIR`). The script has no built-in 7z extractor; the Copy-method archive is simple, but the header is compressed with LZMA, and a parser was not written for a single set. The input directory is checked for the exact names and SHA-256 of all 37 files; extra `.ogg` files cause refusal.
3. **The baseline is tied to one repack.** A mismatched repack inventory fingerprint gives a warning; patch SHA-256 (different file) or inventory verification causes a hard refusal.
4. **Line endings in patches 01–03 (CRLF -> LF)** were a side effect of commit `4fb6c5f`, reproduced as-is (details in `content-patches/README.md`). Proposal: separately restore CRLF (updating patches and the baseline).
5. **`SELECT_TRACE` traces (patches 07, 08)** remain in the working copy because they are present there. Removing them is a separate decision.
6. Patch 04 contains about 2.7 KB of original Hatcher dialogue text (removed lines). For repository publication it should be replaced with metadata.
7. The baseline must be regenerated after any further data changes (instructions in `content-patches/README.md`). Otherwise `--check` will report a difference: this is intentional.
8. The script does not create or update the directory from which the browser plays (`web/gamefiles.py`, `make_dist`): that belongs to D1b. `--out` is a normal `game` directory; the symlink
   `korsary2-next/game -> ../korsary2-work/game` and the `dist` build remain unchanged.
9. Only files with uniform line endings are supported (all CRLF or all LF); the generator rejects mixed endings. This is sufficient for the current 11 files.

## 7. What to check live

* On another machine (different ffmpeg version), run `prepare_game.mjs` and check that `.wav` verification passes. If not, decide whether to update the baseline or pin the version.
* Prepare a copy in a new directory and, without touching the working copy, run the normal port path on it (`play.sh`/manual dist verification): confirm that the game starts from the reproduced copy
  as from `korsary2-work/game` (SHA-256 is theoretically identical, but “plays the same” requires a live check).
* Check the removed historical diagnostic checks on the reproduced copy if the scripts accept a path to it (SHA-256 matches their pins, but the scripts were not run on the copy).
* Decide what to do with CRLF in `Characters/init` and `SELECT_TRACE` (items 4 and 5 of §6).
* Remove patch 04 when publishing the repository (item 6).
