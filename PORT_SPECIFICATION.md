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

Graphics use WebGPU; the game build requires an isolated browser context for
WebAssembly threads. On first installation, the page downloads and unpacks
the data into local browser storage. Saves remain on the player's device; they
are not included in `distribution/`.

For development and game-data restoration, see
[BUILD_FROM_CLONE.md](docs/BUILD_FROM_CLONE.md). Server configuration is covered
in [hosting.md](docs/hosting.md), and validation results and limitations in
the [readiness report](docs/PUBLICATION_READINESS_2026-11-15_RELEASE.md).
