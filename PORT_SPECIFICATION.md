# Browser port architecture

The port runs Corsairs 2 (Sea Dogs 2 / Pirates of the Caribbean 1.03) executable files
statically translated from x86 to C and compiled to WebAssembly. The original
engine source code is not included. Game scripts and resources are supplied in
the ready-to-run distribution.

Components:

- `distribution/` — the ready-to-run static build and data installed by the browser.
- `korsary2-next/recomp/translator/` — the x86-to-C translator.
- `korsary2-next/recomp/out_all/` — generated C code used by normal rebuilds.
- `korsary2-next/recomp/host/` and `runtime/` — the Windows and game API compatibility layer, including graphics and input.
- `korsary2-next/recomp/web/` — the page, resource downloads and packaging, saves and video.
- `korsary2-next/tools/`, `content-patches/`, `english-layer/` — game-data and localization preparation.
- `korsary2-next/recomp/tests/` — regression tests for the engine, browser modules and distribution.

## Runtime and rendering

The translated executables run in a WebAssembly guest. The host implements the
Windows interfaces and Direct3D 8 operations used by the game; the browser
renderer submits graphics through WebGPU. The guest uses WebAssembly threads,
so the page must be cross-origin isolated. The original engine source is not
present: the generated C and its analysis inputs are needed for a rebuild.

## Progressive loading and distribution

Solo play starts with a small set of files and fetches other immutable game
resources on demand. The browser stores verified resources in OPFS for reuse.
The game needs the server when it requests an uncached resource; a partially
cached installation is not necessarily playable offline. `?lazy=0` selects a
full installation and is required for multiplayer. The previous build remains
on `classic-full-install`.

The game and English overlay have separate manifests. File `size` and `sha256`
describe the unpacked bytes. Some objects are standalone; others are records
in `_k2pack/` files, selected by the manifest's `pack`, `offset`, and `csize`.
Records can be raw, gzip, or Brotli. The installer validates manifest paths,
pack ranges, sizes and hashes before accepting data. The Brotli decoder's
source and license are documented in `korsary2-next/recomp/web/vendor/brotli/`.

Updates and game launches coordinate through Web Locks; installed immutable
files are verified and repaired when possible. Retries are bounded and a
failed, cancelled or expired request may require reloading the page, losing
unsaved progress. The server must support single HTTP range requests and the
headers described in the hosting guide.

## Language and player data

The optional English overlay is a separate, read-only tree limited to
`PROGRAM/` and `RESOURCE/`. A matching overlay file takes precedence over
the base file on reads; directory listings combine both trees. Files outside
those trees, including settings and saves, remain in the base installation.
The overlay manifest records hashes of the base files it replaces; packaging
and verification reject a mismatch. Required overlay files are listed in
`korsary2-next/recomp/web/overlay-required.json`. The English text layer uses
the game's existing encoding and fonts; see the preparation tools before
introducing characters outside their supported repertoire.

Player saves are stored locally by origin. Streaming and full-install modes
use separate stores; the launcher provides export, import and an explicit
classic-to-streaming copy. The game page holds a save lock while running.
Updates preserve saves and mutable configuration. `SAVE_META` language markers
are sidecar files: an unmarked older slot does not identify its language.
See the root README for backup instructions and `save-*.mjs` for the protocols.

## Concurrency and tests

The host handle table's publication and lock-order invariants are documented
beside its implementation in `korsary2-next/recomp/host/core.c` and
`win32.h`; changes to file handles, waits or save transactions must preserve
those invariants. Regression tests in `recomp/tests/` cover the host, resource
transfers, input, storage and distribution. The optional real-game recovery
test requires an isolated prepared site; its setup is in the build guide.

For development and game-data restoration, see
[BUILD_FROM_CLONE.md](docs/BUILD_FROM_CLONE.md). Server configuration is covered
in [hosting.md](docs/hosting.md), and validation results and limitations in
the [readiness report](docs/PUBLICATION_READINESS_2026-11-15_RELEASE.md).
