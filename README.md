# Corsairs 2 in the browser

English | [Русский](README.ru.md) | [Українська](README.uk.md)

A browser port of Corsairs 2 (Sea Dogs 2 / Pirates of the Caribbean 1.03, the 1C release). The game's x86 executables are statically translated into C and compiled to WebAssembly. The port's compatibility layer implements the required Windows, Direct3D 8, audio, and input interfaces; the browser renders graphics using WebGPU.

The repository contains a ready-to-run build with game data, the port's source code and tools, and generated C code for rebuilding it. The original game engine source code is not included. Game data and the English language layer can be restored from the distribution for further development without a separate copy of the original repack.

A full initial clone transfers approximately 1.15 GiB of Git data and requires additional disk space for the checkout. Actual transfer size can vary. No Git LFS setup is required.

## Quick start

1. Download or clone the complete repository and change to its root directory. The `distribution/` directory occupies about 1.3 GiB.
2. Start the local server; Node.js 18.20.8 or later is required:

   ```sh
   ./play
   ```

   To configure the server directly, you can also use:

   ```sh
   node scripts/serve_distribution.mjs --port 8007
   ```

3. Open `http://localhost:8007/`, choose a language, and start a solo game. Keep the server running while the game is open; press `Ctrl+C` in the terminal to stop it.

On first launch, game data is downloaded to browser storage and unpacked: the Russian version needs about 2.4 GB plus additional free space, and the English layer is installed separately. Later launches use the installed copy. Player saves are not included in the repository.

By default, the server is accessible only on this machine and serves files with the required headers, MIME types, and Range support. Opening `distribution/index.html` directly via `file://` is not suitable for running the game.

## Distribution contents

`distribution/` contains 457 files totalling **1,397,667,448 bytes (1.30 GiB)**:

| Contents | Size |
|---|---:|
| Packed Russian game data, including the manifest | 1,168.47 MiB |
| English language layer | 71.54 MiB |
| Game WebAssembly module | 44.46 MiB |
| 13 MP4 videos | 47.75 MiB |
| Page, JavaScript, and supporting files | approximately 0.70 MiB |

The game packages contain 9,826 files, occupying approximately 2.19 GiB when unpacked. Most of this is textures, models, audio, and animation. The English layer contains another 771 files and expands to approximately 119 MiB. Local diagnostics and user saves are not included in the distribution.

Brave can report a privacy-limited storage estimate even when more space is available. The installer treats that particular estimate as unknown; an actual storage limit can still stop the download.

## Requirements and controls

You need a current browser with working WebGPU, hardware acceleration enabled, WebAssembly threads, browser file storage (OPFS), and Web Locks. Threads require an isolated page (`crossOriginIsolated`); WebGPU and storage require a secure context, either HTTPS or `http://localhost`. The browser must also allow enough disk space. A Chromium environment was tested on desktop; behavior in a particular browser depends on the device and driver. In a private Vivaldi window, installation failed because the browser storage quota was insufficient.

Examples of bindings in the supplied profile:

| Action | Control |
|---|---|
| Move forward / action | Right / left mouse button |
| Run, combat, block | Shift, E, Ctrl |
| Pistol, dodge | Q, Z |
| Ship: steering and sails | A/D, W/S |
| Quick command, camera, time | Space, Tab, R |
| Skip encounter, menus | B, Enter / Esc / F1 / F2 |

You can view and change bindings in the game's settings. In solo play on a touch device, a panel appears with Land, Sea and map, Menu, and More tabs; its trackpad controls the camera and cursor. Use `?touch=1` to force the panel on for testing or `?touch=0` to turn it off. See [touch controls](docs/touch-controls.md).

By default the game fills the browser viewport by stretching the original 4:3 image horizontally. Move the mouse to reveal the **4:3** button in the bottom-right corner to restore undistorted proportions (with side bars on a wide screen); use the same button to fill the viewport again. The choice is saved in the browser. The touch layout keeps its 4:3 game area.

Use **Alt+Enter** (Option+Enter on a Mac) or the corner button for native fullscreen. In browsers that support Keyboard Lock and grant its permission, a single Esc reaches the game; press Esc twice quickly, hold Esc, or use Alt+Enter to leave fullscreen. If Keyboard Lock is unavailable or denied, the browser controls Esc and may leave fullscreen on the first press. In windowed mode the game still fills the viewport; the browser may consume the first Esc to release the captured mouse. The game draws its own cursor and captures the mouse on a click.

If the browser reserves Esc in fullscreen or while the mouse is captured, use **F10** for the game's Esc action; on Macs with media keys, use **Fn+F10**. An **Esc** button also appears near the bottom-right corner when this fallback is active. This does not change your browser's privacy settings. F10 retains its normal game binding when the fallback is inactive.

## Saves

Saves are kept in browser storage and are tied to the exact site address, including the port. Before changing the address or browser, or clearing site data, make a backup: choose **Download saves** on the start screen and **Restore saves** to transfer them. Close other tabs running the game before exporting or restoring. If names conflict, the page will ask how to proceed. Clearing site data deletes local saves.

In the game, saving and loading are available from the game menu; F1 opens the menu in the supplied profile. Keep the backup ZIP outside the browser.

## Development from a clone

For detailed steps, dependencies, and build examples, see [build from a clone](docs/BUILD_FROM_CLONE.md). Run the commands below from the repository root.

Restore the game data and English layer for development:

```sh
node korsary2-next/tools/restore_dist.mjs \
  --dist distribution --game-out korsary2-work/game \
  --overlay-out korsary2-work/english-overlay
```

The tool checks hashes, keeps existing matching files, and refuses to overwrite files that differ. If you have your own changes, you can specify new output directories and transfer those changes separately. `korsary2-next/game` is a symlink to `korsary2-work/game`.

Rebuilding WebAssembly requires Emscripten 6.0.13 and the pinned Dawn `emdawnwebgpu` package; the guide explains how to set up the SDK and additional dependencies. After installing the tools and restoring the data:

```sh
sh korsary2-next/recomp/build_web_local.sh
```

The script builds browser and Node versions from the included generated C code. To create a new standalone distribution from a modified project, use `make_dist.mjs` as shown in the guide. Building requires several additional gigabytes of free space and may take a long time.

## Tests

A full distribution check reads all game files and verifies their SHA-256 hashes:

```sh
node korsary2-next/recomp/tests/verify_dist.mjs --dist distribution \
  --full-hash --require-overlay --no-freshness --no-videos-web
```

Examples of quick regression checks for data restoration and touch input:

```sh
node --test korsary2-next/recomp/tests/test_restore_dist.mjs
node --test tests/test_git_game_bytes.mjs
node korsary2-next/recomp/tests/test_touch_controls.mjs
node korsary2-next/recomp/tests/test_missing_resource_preflight.mjs
```

Node.js must be installed for the Node tests. Build and gameplay tests do not replace running the game in a browser after making changes.

## Structure

| Path | Contents |
|---|---|
| `distribution/` | Ready-to-run build, packed game data, English layer, and videos |
| `scripts/serve_distribution.mjs` | Local server for the finished build |
| `korsary2-next/recomp/translator/` | x86 machine-code-to-C translator |
| `korsary2-next/recomp/runtime/`, `host/` | Runtime and implementations of system and graphics interfaces |
| `korsary2-next/recomp/out_all/` | Generated C code for building |
| `korsary2-next/recomp/web/` | Page, data loading, saves, local server, and packager |
| `korsary2-next/recomp/tests/` | Port component and distribution tests |
| `korsary2-next/tools/` | Data restoration and preparation, configuration, and build tools |
| `korsary2-next/content-patches/`, `english-layer/` | Game fixes and English layer preparation data |
| `docs/` | Instructions and reports |

The `korsary2-work/game/` working copy, local SDK, build caches, browser profiles, and saves are created separately. Do not add user saves or local profiles to the repository.

## Hosting and verification status

To publish, host the contents of `distribution/` on a static HTTPS host with correct MIME types, Range support, and COOP/COEP/CORP headers. The `_headers` file contains rules for compatible platforms; other hosts require separate configuration. Before opening the site to users, check actual HTTP responses, `crossOriginIsolated`, installation, and saving/loading. See the [hosting guide](docs/hosting.md).

The finished build has been checked for game-data integrity, clean installation, starting a game, saving, and loading; the touch panel was tested using phone emulation in a browser. A real iPhone and Safari have not yet been tested. Long playthroughs and listening to audio were not performed. A hosting provider still needs to be selected and verified before publication. The scope of the checks is described in the [readiness report](docs/PUBLICATION_READINESS_2026-11-15_RELEASE.md).
