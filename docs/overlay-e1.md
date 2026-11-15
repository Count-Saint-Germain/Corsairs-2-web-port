# E1: host overlay, second OPFS directory, language switch, building the overlay into dist

> Historical report: recorded tool names and commands describe the versions used for the original investigation. For the current Node.js development workflow, see [Development after cloning](BUILD_FROM_CLONE.md).

Date: 12.11.2026. Author: E1 agent. Status: **implemented and synthetically verified** (native ASan/UBSan, TSan, WasmFS, Node, real `port.js` in ephemeral Chromium with real OPFS);
**not checked live (with the real game, rendering, rebuilt `game.wasm`)** — see §9. Neither the game nor the user's browser was launched; game data and images were not read.
The layer file contract is in `docs/english-layer.md` (E2, §1); this document covers the mechanics of how the host and page use the overlay. User decisions: implement English throughout (E1–E5), one distribution with
an optional English layer, Russian mode unchanged **byte for byte** by default.

## 0. Overview

* **Host.** `PORT_OVERLAY=<absolute-host-path>` (unset / empty / `0` — disabled, in which case overlay code does not run). For guest paths under `PROGRAM/` and `RESOURCE/`, reads, attributes and enumeration
  check the overlay first, then the base; directory enumeration is a union; `SAVE*`, `options`, `engine.ini`, `ENGINE.exe`, `MODULES/**` and everything outside `PROGRAM/`/`RESOURCE/` always use the base.
  The overlay is **read-only**: any write/delete/move at a path held by the overlay is refused (`ERROR_ACCESS_DENIED`/`ERROR_ALREADY_EXISTS`); new names are created in the base.
  `map_path` still returns only **base** paths (canonical), so share/identity/SAVE_TX/SAVE_META/handles do not change.
* **Page.** The “Русский / English” (Russian / English) switch on the start screen (`?lang=ru|en` > `localStorage korsary2.lang` > Russian); English installs the overlay from `game-en/manifest.json` into the second OPFS directory
  `korsary2-game-en` (`installed-en.json` marker), using the same synchronisation mechanism under the same SAVE lock; strict overlay manifest validation (refusal before the first write); launch with `PORT_OVERLAY=/opfs/korsary2-game-en`.
  Any layer failure refuses **English** launch and offers a return to Russian; Russian is never broken.
* **Build.** `make_dist.py --overlay-dir DIR [--overlay-name en]` builds `game-en/` with a manifest, packs and codecs like `game/`; `serve.py --overlay-dir`, `worker.js`, `upload.py`, `verify_dist.py`
  understand `game-en/`. Without `--overlay-dir` the dist is unchanged byte for byte.
* **Evidence that Russian mode is unchanged:** `run_file_share_semantics.sh diff` trace (313 lines) is identical to the old tree with `PORT_OVERLAY` unset/`0`/empty/empty directory/trap directory, with and without snapshots;
  `map_path` gives byte-for-byte identical results for **100 000** random and boundary paths (4 environment-variable modes × 2 CP1251 name modes); dist without `--overlay-dir` has the same files; the page in Russian mode
  downloads no bytes from `game-en/` (one `HEAD`), does not create an overlay directory, and does not set `PORT_OVERLAY`.

## 1. Host (`host/core.c`, `host/kernel32.c`, `host/win32.h`, `host/main.c`)

### 1.1. Enabling it and design choices

| Decision | Choice | Why |
|---|---|---|
| Second WasmFS mount | **not needed** | `main.c` mounts the OPFS **root** at `/opfs`; `korsary2-game-en` is a sibling directory at the root, so `/opfs/korsary2-game-en` already exists. The page only sets `m.ENV.PORT_OVERLAY` |
| Path substitution | **overlay index + extended `map_path` walk**, not “physical path instead of canonical” | file identity (strict share, SAVE_TX, SAVE_META, handle table) is based on the host path; if `map_path` returned an overlay path, one guest file would have two host paths |
| Writing to overlay | **forbidden, error**, not “silently to base” | silent writes to the base produce two copies of a file: the overlay is read and the written data is lost |
| New files | to the base, as before | the overlay is not a place for player data; the same code as before creates parents |
| Invalid root | **host does not start** (`main` → code 3) | a half-English game is worse than refusal; the page checks the layer in advance, so this is a safeguard |
| Cache | directory index, built **lazily**, once per directory | the overlay does not change during play (the page holds the SAVE lock and does not touch the layer); OPFS listing is expensive in the browser, so lazy loading visits only needed directories |

### 1.2. Operation semantics

| Operation | Overlay enabled |
|---|---|
| `CreateFileA` without write access, `OPEN_EXISTING`/`OPEN_ALWAYS` | if file is in overlay, read it (overlay fd), otherwise base. Handle stores **canonical** (base) path; snapshot (`file_snapshot`) and load pacing (`fs_activity`) work as before |
| `CreateFileA` with `GENERIC_WRITE`, `CREATE_ALWAYS`, `TRUNCATE_EXISTING` at a path held by overlay (file or directory) | `ERROR_ACCESS_DENIED`, log entry, **before** reservation in strict registry; `CREATE_NEW` — `ERROR_FILE_EXISTS` (path exists; in browser build `CREATE_NEW` still refuses first, `ERROR_NOT_SUPPORTED`) |
| `GetFileAttributesA` | overlay takes precedence: `0x20` (file) / `0x10` (directory, including overlay-only) |
| `FindFirstFileA`/`FindNextFileA` | **union**: base entries first in base order (matching names use overlay data under base spelling), then overlay-only names (overlay order); `.`/`..` once; overlay-only directory gets synthetic `.`/`..`; wildcard and CP1251 as before |
| `DeleteFileA` / `RemoveDirectoryA` at overlay path | `ERROR_ACCESS_DENIED` |
| `MoveFileA` | overlay source — `ERROR_ACCESS_DENIED`; destination is a name held by overlay — `ERROR_ALREADY_EXISTS` |
| `CreateDirectoryA` at overlay directory | `ERROR_ALREADY_EXISTS` |
| `CopyFileA` | overlay source is read; destination at overlay path — `ERROR_ACCESS_DENIED` (strict: source reserved under canonical name) |
| `SetFileAttributesA`, `CreateFileMappingA`, `LoadLibraryA` | unchanged (first is a stub, second works with fd, third is not file-based) |
| `SAVE/`, `SAVE_META/`, `SAVE_TX/`, `options`, `engine.ini`, `ENGINE.exe`, `MODULES/`, everything outside the game folder | **always base**: overlay index contains nothing except top-level `PROGRAM` and `RESOURCE` |

### 1.3. File identity and canonical names

`map_path` returns the base host path. If a component is absent from the base but present in the overlay, **overlay spelling** is inserted into the path (otherwise two spellings of one overlay-only file
would look like a spelling conflict between two absent names to the strict registry). `share_name_for`/`share_name_make`/`share_rel_of`/SAVE_TX/SAVE_META receive that path and know nothing about the overlay.
Verified (strict): opening a file exclusively blocks opening it under different case; for an overlay-only file, two spellings both open with compatible modes, but incompatible modes produce `SHARING_VIOLATION`;
`CopyFileA` does not read an exclusively open file; a refused write reserves nothing.

### 1.4. Security

* Guest text **never** becomes an overlay host path: the path is built from index nodes' `host` names. Component traversal uses the same `..` arithmetic as the base (does not go above the game root), and follows the index
  step by step, so “`RESOURCE\..\SAVE\x`” uses the base.
* The index excludes symlinks and everything that is not a regular file/directory (`lstat`/`d_type`): an overlay symlink pointing outside is **neither indexed nor opened**; the overlay root itself may be a symlink (resolved using `realpath`).
* The overlay root is rejected if it is not a directory, is **inside** the game folder, or **contains** it.
* `escape` test: random traversal of 60 000 paths (`..`, `.`, symlink names, “secrets” beside roots): every host path is inside the game root, every overlay path is strictly inside the overlay root and not a symlink; files “outside” are not read.
* Limitation: the index is a **snapshot**. If the overlay changes during gameplay, old names are shown (opening a deleted file returns an error). The page prevents this (SAVE lock, §2.4).

### 1.5. Changes

* `core.c`: “language overlay” block (`OvNode` index, lazy directory loading under lock, hash table of children by case-insensitive name; lookup follows the same rules as `find_ci`/`find_ci_fold`, including CP1251);
  `map_path` rewritten as `map_path_walk` (when `ovh == NULL`, old code; when overlay is enabled, follows the index in parallel); `map_path_ov` (return logical existence + what the overlay holds);
  `overlay_init_from_env`, `overlay_test_reset`, `overlay_dir_entry/find`, `overlay_name_key`; diagnostic functions `port_overlay_state()` (0/1/2) and `port_overlay_hits()` (exported to browser).
* `kernel32.c`: `file_attr`, `CopyFileA` (both paths), `CreateFileA`, `DeleteFileA`, `MoveFileA`, `CreateDirectoryA`, `RemoveDirectoryA`, `FindFirstFileA`/`find_next` (union; WIN32_FIND_DATAA reading moved to `find_fill`, name matching to `find_name_ok`).
* `win32.h`: `OvHit`, prototypes. `main.c`: 4 lines — `overlay_init_from_env()` immediately after `realpath(game)`; `-1` → exit with code 3.

### 1.6. Host log lines

```
[overlay] on: /opfs/korsary2-game-en (read-only, PROGRAM/ and RESOURCE/ only)             always, once per process
[overlay] PORT_OVERLAY=<…> is not a readable directory: refused                          invalid root (host does not start)
[overlay] PORT_OVERLAY=<…> overlaps the game folder <…>: refused (the overlay must stay read-only)
[file] CreateFileA(<guest-path> -> <canonical-path>, disp 3) = ok (overlay <overlay-path>)   with ?log (PORT_LOG): read from overlay
[overlay] CreateFileA(<…>) refused: write access to a path of the read-only overlay (disp 2)
[overlay] DeleteFileA(<…>) refused: the path is served from the read-only overlay             (also MoveFileA, CopyFileA, CreateDirectoryA, RemoveDirectoryA)
```

## 2. Page (`web/overlay.mjs`, `web/port.js`, `web/index.html`)

### 2.1. Language selection

`chooseLang({search, storage})`: `?lang=ru|en` (value is case-insensitive; unknown values ignored) > `localStorage['korsary2.lang']` > Russian. `localStorage` reads and writes are in `try/catch` (private window, denial, quota:
selection lasts until reload). The URL parameter is **not stored** by itself — only a player's click is remembered. The switch is in `view-home` above the “Play Solo / Play Multiplayer” buttons:
“Русский / English” (Russian / English), status line, layer-installation progress, “Вернуться к русскому” (Return to Russian) button (visible only on layer error), and explanation: **“Язык применяется при запуске игры: в уже запущенной игре (в том числе в другой вкладке) он не меняется”** (The language applies when the game starts; it does not change in a running game, including in another tab).
Choosing a language for a running game is impossible by design: the start screen disappears on launch, and `run()` fixes the language at launch time.

### 2.2. Layer states (`window.langInfo.overlay`)

`unavailable` (server has no `game-en/`: English button disabled with explanation; `?lang=en` and remembered English yield Russian; `localStorage` selection retained) → `absent` (available, not installed) →
`installing` → `ready` | `error`. In Russian mode layer availability is one `HEAD game-en/manifest.json` (an HTML “placeholder” returned instead of the file does not count as a layer); in English, manifest `GET` happens during installation.

### 2.3. Install/update (same mechanism, parameterised by target)

`syncFromServer(manifest, target, ui)`: target is the base (default, behaviour unchanged) or overlay `{directory korsary2-game-en, marker installed-en.json, URL game-en/}`. The same `syncManifestFiles`/`game-transfer.mjs`:
`size`+`sha256`, `enc` gzip/br, `csize`, `game-en/_k2pack/*` packs (Range, ranges), `?installConcurrency=` parallelism, up to 4 retries, clean install / update (only changed files overwritten) /
resume after interruption (missing data downloaded, completed data not downloaded again).
Stricter than the base (`overlay.mjs`): `validateOverlayManifest` **before any write** — only `PROGRAM/` and `RESOURCE/` (exact spelling); forbidden `SAVE*`, `options`, `engine.ini`, `ENGINE.exe`, `MODULES`, `..`, `.`,
absolute paths and backslashes, `:*?"<>|`, control characters, hidden (`.x`) and reserved (`CON`, `NUL`, `COM1`…) names, trailing dot/space, case duplicates, file-and-directory collisions, depth ≤ 20, path ≤ 240 bytes;
`size` and `sha256` on **every** entry (including “as-is”); an “as-is” file is additionally checked against SHA-256 after download (the base has no such check — size only) and deleted on mismatch; `overlay` block (`format` 1;
`base`: paths are overlay files); required layer files (6 under E2 contract); `overlay.base` checked against `game/manifest.json`: an overlay built on another Russian distribution is rejected (“собран на другой версии русской раздачи” (built against a different Russian distribution version)).
Unknown top-level manifest keys are ignored. **Quota** (`checkStorageForSync` → `planStorageNeed`) is calculated for overlay files independently of base; insufficient space refuses **before writing**, without even creating the overlay directory.
`installed-en.json` marker is written after all tasks succeed and stores `version`, time and **file list** (path, size, SHA-256): if the manifest is unavailable (offline), the installed layer is checked against the marker and works (“offline”).

### 2.4. Locks and ordering

One lock — `korsary2-game:save-backup` (`withSaveLock` on the **base root**; overlay name has no lock). Order: base (`updateUnderSaveLock`) → release → overlay (`installOverlayUnderSaveLock`) → release; locks are never nested.
`installOverlayUnderSaveLock`: marker is read **without a lock** (current version — lock unnecessary, sync not called, a game running in another tab does not interfere), otherwise `ifAvailable` lock (busy — refusal without writes),
marker rechecked under lock, `sync()`. No SAVE archive is made before overlay installation (overlay does not touch SAVE). Game launch (`runExclusiveForPageLifetime`) holds the same lock for the page's lifetime, so installation in another tab
is refused instead of racing the game; **before English starts, already under the page lock** (`beforeStart`), the layer is rechecked (marker, presence and size of all files, game build overlay support) —
nobody can change the layer between check and start. SAVE backup/export/import operate only on `korsary2-game/SAVE*`; the overlay is excluded from archives (verified in browser).

### 2.4a. Pre-launch checks and refusals

* After installation and at every English start: fast completeness check (`verifyOverlayFiles`: every manifest file exists and has its size, without hashes). The marker is not trusted blindly: “marker exists, file missing” (storage was cleared) → repair under lock
  (download missing data); failure → refusal.
* English launch refusal (and messages): layer not installed/incomplete/corrupt, insufficient space, server unavailable, layer built on another Russian distribution, lock busy, **`game.wasm` build predates E1** (its glue lacks `port_overlay_state`:
  it would ignore `PORT_OVERLAY` and start in Russian under an English label). In all cases: “Английский режим не запущен; русская установка не затронута” (English mode was not started; the Russian installation is unaffected), Play blocked, “Вернуться к русскому” (Return to Russian) button (`#lang-back-ru`).

### 2.5. Launch and diagnostics

`startRuntime`: `arguments: ['/opfs/korsary2-game']` (unchanged), for English `m.ENV.PORT_OVERLAY = '/opfs/korsary2-game-en'` (Russian does not set the key at all). Multiplayer: English adds `:en-<layer-version>` to `buildVersion()`
(players with different layers cannot join); Russian string unchanged. `window.langInfo`: `{lang, source: url|storage|default|user[+unavailable], stored, urlInvalid, storageError, overlay, version, files, bytes, error, installed: installed|current|offline,
launched: {version, hostPath, hostState}, hostPath, dir, marker, url}`. Also `window.overlayInstallStats`, `window.overlayStoragePreflight`. Console lines:

```
[lang] language en (url)            [lang] language ru (default)         [lang] language en (storage)        [lang] language en (user)
[install-en] {"seconds":…,"concurrency":6,"files":242,"packs":1}
[lang] overlay ready {"version":"…","files":242,"how":"installed|current|offline"}
[lang] overlay error <text>        [lang] overlay unavailable on this server       [lang] start refused <text>        [lang] host overlay state 1
```

## 3. Build (`web/make_dist.py`, `gamefiles.py`, `serve.py`, `cloudflare/{worker.js,upload.py}`, `tests/verify_dist.py`)

* `make_dist.py --overlay-dir DIR [--overlay-name en] [--overlay-no-required-check] [--overlay-skip-base-check]`: input is `tools/prepare_english.mjs` directory (`PROGRAM/`, `RESOURCE/`, `OVERLAY.json`). `gamefiles.overlay_files` inventory
  **before writing**: only `PROGRAM`/`RESOURCE` and `OVERLAY.json`; `SAVE*`/`options`/`engine.ini`/`ENGINE.exe`/`MODULES` — refusal naming the path; symlinks (file, directory, top directory), hard links, non-regular files, hidden/reserved/special names,
  `..`, case duplicates, file-and-directory collisions, empty overlay, missing required files, `OVERLAY.json` not format 1 / `base` with a foreign path or non-SHA — refusal; overlay and game/output must not contain one another.
  Then same `write_game` (`--codec gzip|br`, `--no-compress`, `--no-pack`, `game-en/_k2pack/*` packs), `manifest_for` manifest + `overlay` block from `OVERLAY.json`; `version` follows the `gamefiles.py` contract (block excluded).
  SHA-256 of `overlay.base` files is checked against the source Russian game **before writing**. `--estimate` with an overlay also prints the overlay table. Global `/*` rule in `_headers` covers `/game-en/*`; no separate duplicate header is added.
* `serve.py --overlay-dir DIR [--overlay-name en]`: `/game-en/` (manifest GET **and HEAD**, files, `.gz`/`.br`, packs, Range) with the same `--compress/--codec/--pack`; overlay checked at startup as in `make_dist`; without flag `/game-en/` is 404; paths `SAVE`, `options`, `..`, `OVERLAY.json` are 404.
* `worker.js`: `game-en/` tree gets the same caching (`private, max-age=86400`, manifest `no-cache`), `no-transform`, removal of `Content-Encoding`, and Range as `game/`; “`game-entry/`” is not considered a game tree. `upload.py`: `game-en/` objects are immutable
  (skip by size and SHA-256), both manifests are sent **last**, a manifest promising a missing object refuses before upload.
* `verify_dist.py`: `overlay` block (if `game-en/` exists or `--require-overlay`): structure, strict paths (own copy of rules, compared with packer and page on 37 paths), SHA/size/`version`, packs and records, `overlay.base` against `game/manifest.json`, required files,
  nothing forbidden on disk, no symlinks/hard links, **independence**: no `overlay` block or `game-en` paths in `game/manifest.json`, no overlay content in `game/`, global `Cache-Control: no-cache` applies to `/game-en/*`.

## 4. Tests

Commands (from `korsary2-next/recomp/tests`):

| Command | What it establishes |
|---|---|
| `sh run_overlay.sh native` | ASan/UBSan, permissive and strict × snapshots off/on: resolve, forbidden, attrs, union, writes, escape (60 000 paths), symlinks, root, identity (strict), cp1251, dup, threads |
| `sh run_overlay.sh tsan` / `savetx` | TSan (8 threads lazily build the index); build with `-DPORT_SAVE_META=1 -DPORT_SAVE_TX=1` |
| `sh run_overlay.sh wasm` / `node` | same in WasmFS (memory, case-sensitive: case-duplicate test is real) and NODERAWFS, under emcc lock |
| `sh run_overlay.sh diff BASE_DIR` | `map_path` on 100 000 paths against old `host/` copy (unset/`0`/empty/“traps” × plain/CP1251 names) |
| `sh run_overlay.sh bench BASE_DIR` | `map_path` cost |
| `sh run_overlay.sh mutate` | 16 host mutations must fail |
| `sh run_file_share_semantics.sh diff BASE_DIR` | 313-line trace is identical (including with `PORT_OVERLAY` unset/`0`/empty/empty directory/“traps”) |
| `node test_overlay_page.mjs` | language selection, strict validator (≈ 60 refusals), path-rule agreement with packer and verify_dist, locked installation (current marker / busy / race / error), completeness, quota |
| `node test_overlay_browser.mjs` | real `port.js` + Chromium + OPFS: 21 scenarios A–P (§4.2) |
| `node test_worker_overlay.mjs` | `worker.js` and `game-en/` |
| `node --test test_overlay_dist_node.mjs` | overlay distribution layouts, validation and integration checks |
| `sh mutate_overlay.sh`, `sh mutate_overlay_page.sh` | host (16) and page (13) mutations |

### 4.1. Host: evidence of unchanged behaviour

* `test_file_share_default_trace.c` trace (313 lines: opens, reads/writes, duplicates, deletion, moves, directories, CopyFile, CP1251 names, handle table) is identical to the old tree with `PORT_OVERLAY` unset, `0`, empty, **empty overlay directory**
  and **“trap” directory** (files with the same names as in the scenario, at top level and in `SAVE/`, `options`, `engine.ini`), with and without snapshots: 10 comparisons plus earlier ones.
* `test_map_path_100k.c`: 100 000 paths per run (≈ 48% inside game folder, ≈ 52% profile/outside; ≈ 9.7% exist); results (existence + path) are identical to old `core.c`; plus `map_path_ov` == `map_path` when overlay holds nothing.

### 4.2. Page in real Chromium (21 scenarios)

A Russian by default; B `?lang=en` (clean install, independent SHA-256 of all files, separate markers, game env, unchanged base); C switch, remembered selection, change without re-download; D interrupted layer installation → refusal → “Вернуться к русскому” (Return to Russian) → retry;
E corruption of an “as-is” file and a pack record; F quota; G forbidden paths and missing SHA (6 variants); H dist without `game-en/`; I SAVE/base untouched, export without overlay, no SAVE archive made; J second tab while game runs; K layer update (one file downloaded);
L layer for another Russian distribution; M “marker exists, file missing” → repair / refusal; N layer manifest unavailable (offline via marker); O game build without overlay support; P layer corrupted after ready → refusal on launch.
Test stubs: `build/game.js` (records env set by page and stops; game does not launch) and `missing-resource-preflight.mjs` (resource checking is not the subject of this test); other page modules are real.

## 5. `map_path` overhead measurements

Native, `-O2`, macOS arm64, synthetic tree (1000 files each in base and overlay `VOICE`), μs per call, three consecutive runs (machine noise ±15%; first run on a busy machine):

| | `VOICE\Eng_NNNN.wav` (1000-entry directory) | `ini / SAVE / scripts` (small directories) |
|---|---:|---:|
| old tree | 292 / 202 / 209 | 50 / 40 / 43 |
| new, overlay disabled | 280 / 198 / 204 | 50 / 40 / 50 |
| new, overlay enabled, empty | 228 / 201 / 203 | 40 / 40 / 40 |
| new, overlay enabled, 1000 files in hot directory | 199 / 233 / 201 | 41 / 43 / 40 |

Conclusion: disabled overlay overhead (one `relaxed` atomic flag load) and enabled overhead (index hash lookup, no system calls after first directory listing) are **indistinguishable from noise**; base `readdir` dominates
(≈ 0.2 ms for a 1000-entry directory: O(n) per component, as before). Browser OPFS listing is significantly more expensive: the overlay index is built once per directory, lazily. Not measured: real OPFS (`readdir`/`lstat` in WasmFS OPFS backend), index construction time on the real layer.

## 6. What was checked only synthetically

Host on synthetic trees in native/WasmFS(memory)/NODERAWFS, **not** in the real browser OPFS backend of WasmFS (`d_type`/`lstat` and listing speed need live verification); page on synthetic dist with a `game.js` stub
(game not launched; `game.wasm` rebuilt with this host still needs to be built); real E2 layer (242 files) accepted by page validator and packer (format check), but installation and launch with it were not run.

## 7. Risks

1. **`game.wasm` must be rebuilt** (coordinator): without `port_overlay_state` the page refuses English launch (intentional). Russian works with any build.
2. Overlay index is a snapshot (§1.4); mutating the layer in a running browser would break listings — prevented by the page lock, but not enforced by the host.
3. Real OPFS: `lstat`/`d_type` in the WasmFS OPFS backend were not checked (code has `lstat` fallback on `DT_UNKNOWN`); OPFS has no symlinks, their protection is for native/Node.
4. An “as-is” base file is still not checked against SHA-256 after download (size only); overlay files are checked. Base was not changed in E1 (Russian behaviour unchanged).
5. Two tabs: a second tab does not start at all while a game is running (base behaviour: `updateUnderSaveLock` takes the lock before reading the marker); layer installation is also unavailable in that case — not a regression.
6. Slot `lang` marker implemented in E5 as sidecar `SAVE_META/<slot>.lang` (`docs/english-layer.md`, section 11.4). Slots are shared; NPC names retain their creation language.
7. `game-en/` size in OPFS and on the network (E3/E4: ≈ 125 MB or more): quota checked before writing; insufficient space causes refusal.
8. `HEAD game-en/manifest.json` in Russian mode is one extra request; hosts without HEAD support (405/501) → `GET`.

## 8. Requirements for E3/E4/E5

* **E3/E4:** put files in the same overlay directory (`RESOURCE/Textures/Loading/**`, `RESOURCE/Sounds/VOICE/**`) — no manifest/page/host changes needed. Overlay-only files need nothing special; for replacement, use the same spelling as the base
  (contract §1.2.4; host lookup is case-insensitive regardless). Each file must have SHA-256 (packer and page refuse otherwise). Large files may be packed with `--codec br`. Video bridge (`video-player.mjs`) is separate (HTTP, not OPFS).
* **E5 (done, `docs/english-layer.md` section 11):** required-file list is one file `web/overlay-required.json` (page imports it, `gamefiles.py` and `verify_dist.py` read it, `make_dist` places it in dist); slot language marker; English layer preflight
  (`checkOverlayBeforeRun` in `missing-resource-preflight.mjs`); `verify_dist --overlay` (`overlay-layer` block: comparison with `expected-overlay.json`), `VIDEO_FILES_EN`.

## 9. Live verification (for another agent; separate origin, test slots, no user saves)

0. Build `game.wasm` with this host (`build_web.sh` — coordinator); ensure `grep _port_overlay_state build/game.js` finds the export.
1. From `korsary2-next`, build a test dist: `node recomp/web/make_dist.mjs --game <russian-copy> --out dist-test --overlay-dir <prepared-overlay-directory> --codec br`. Alternatively use `node recomp/web/serve.mjs --game <russian-copy> --overlay-dir <prepared-overlay-directory> --pack`. Verify the dist with `node recomp/tests/verify_dist.mjs --dist dist-test --require-overlay --full-hash`.
2. **Clean install with English** in a clean browser profile: open `?lang=en&log`; expect base installation then layer (“Английский слой: X / Y МБ” (English layer: X / Y MB)), `window.langInfo.overlay === 'ready'`, console `[lang] overlay ready`, `[install-en] …`; two OPFS directories
   (`korsary2-game`, `korsary2-game-en` with `installed-en.json`). Play: host console `[overlay] on: /opfs/korsary2-game-en …`, `window.langInfo.launched.hostState === 1`; game `system.log` has English `language.ini` without `Language … not exist`.
3. **Language change:** on the start screen click “Русский” (Russian) → restart game → Russian (no `[overlay] on` in log); back to “English” → layer not downloaded again.
4. **Refusal with corrupt overlay:** stop game, in DevTools → Application → OPFS delete one file from `korsary2-game-en` (or corrupt its size), reload with `?lang=en` — layer repairs; then break server (500 for a `game-en/` object)
   and delete a file — “Английский режим не запущен…” (English mode was not started…), Play blocked, “Вернуться к русскому” (Return to Russian) works.
5. **Russian mode unchanged:** without `?lang` and with empty `localStorage` — no network requests to `game-en/` except one `HEAD manifest.json`; game runs as before; compare `korsary2-game/installed.json` and files before/after layer installation (must not change).
6. Check in a live game what cannot be checked synthetically: `RESOURCE\Sounds\VOICE\*` listings (E4), loading screens (E3), start speed (overlay directory listing in OPFS), two-tab behaviour.

## 10. Files

`host/core.c`, `host/kernel32.c`, `host/win32.h`, `host/main.c`; `web/overlay.mjs` (new), `web/port.js`, `web/index.html`, `web/make_dist.py`, `web/gamefiles.py`, `web/serve.py`, `web/cloudflare/worker.js`, `web/cloudflare/upload.py`;
tests: `tests/test_overlay.c`, `test_map_path_100k.c`, `bench_map_path.c`, `run_overlay.sh`, `mutate_overlay.sh`, `mutate_overlay_page.sh`, `test_overlay_page.mjs`, `test_overlay_browser.mjs`, `test_worker_overlay.mjs`, `test_overlay_dist.py`, `overlay_fixture.py`,
`verify_dist.py` (`overlay` block, `add_synthetic_overlay`), `test_file_share_default_trace.c` and `run_file_share_semantics.sh` (`PORT_OVERLAY` variants); `docs/overlay-e1.md`, section 10 in `docs/english-layer.md`.
