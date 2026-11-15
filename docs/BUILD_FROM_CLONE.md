# Development after cloning

Run the commands below from the `web-port` root. Git contains the ready-to-run
`distribution/`, the port source, and generated C code used by the normal
WebAssembly rebuild. You do not need a compiler to run the ready build; this
document covers the development environment. Allow several gigabytes beyond
the clone size for the build, SDK, and unpacked game data.

The examples target macOS and Unix-like environments with a POSIX shell. The
current native build, `recomp/build.sh`, uses macOS and Homebrew; the commands
below are for the browser build and do not themselves establish support for
another operating system.

The development checkout must preserve Git symbolic links: `korsary2-next/game`
and the `third_party` links connect the working directories. On systems where
Git checks out symlinks as plain text files, these development commands will not
work until symlink support is enabled and the repository is checked out again.

The project scripts and a clean WebAssembly rebuild have been tested with Node.js
18.20.8 on macOS ARM64. The Emscripten SDK uses its own bundled Node.js for its
internal tools. Optional browser automation may need a newer Node.js: the
Playwright 1.65 installation used during verification requires Node.js 20 or later.

## Restoring game files

In the distribution, game files are stored in compressed objects and packs.
Restore the working game and English layer while verifying their hashes:

```sh
node korsary2-next/tools/restore_dist.mjs \
  --dist distribution --game-out korsary2-work/game \
  --overlay-out korsary2-work/english-overlay
```

In a clean clone, `korsary2-work/game` already contains tracked game scripts.
The tool keeps identical files and refuses to overwrite files with different
contents. If working files have already been changed, restore to new directories
and move the changes yourself; do not overwrite your work blindly.
`korsary2-next/game` is a link to `../korsary2-work/game`.
Player saves are not included in the distribution.

To verify the distribution itself, including the English layer and every file hash:

```sh
node korsary2-next/recomp/tests/verify_dist.mjs --dist distribution \
  --full-hash --require-overlay --no-freshness --no-videos-web
```

## Installing tools

You need Node.js 18.20.8 or later, Git, Python 3.11 or later (required by the external Emscripten SDK), `curl`, `sh`, standard Unix utilities
(`cp`, `xargs`, `shasum`, `perl`), and network access to download the SDK. To
check the ready build in a browser, you need a browser with WebGPU. Install
**Emscripten 6.0.13**:

```sh
mkdir -p korsary2-work/third_party
git clone https://github.com/emscripten-core/emsdk.git korsary2-work/third_party/emsdk
korsary2-work/third_party/emsdk/emsdk install 6.0.13
korsary2-work/third_party/emsdk/emsdk activate 6.0.13
```

`korsary2-next/third_party` links to `../korsary2-work/third_party`.
If the SDK is installed elsewhere, set its absolute path before building:

```sh
export K2_EMSDK=/absolute/path/to/emsdk
```

The pinned version of Dawn's `emdawnwebgpu` package is also required. The script
checks the archive's SHA-512 before extraction. This example downloads the
archive to a temporary file and then removes it:

```sh
DAWN_ZIP=$(mktemp "${TMPDIR:-/tmp}/k2-dawn.XXXXXX")
curl -fL 'https://github.com/google/dawn/releases/download/v20260423.175430/emdawnwebgpu_pkg-v20260423.175430.zip' -o "$DAWN_ZIP"
node korsary2-next/tools/stage_emdawn.mjs "$DAWN_ZIP"
rm "$DAWN_ZIP"
```

`stage_emdawn.mjs` writes the package to the local `recomp/web_toolchain/` cache.
If the download fails, do not proceed until the download and verification succeed.
To translate x86 to C again, install the pinned Node.js dependencies:

```sh
npm ci --prefix korsary2-next/recomp/translator
node korsary2-next/recomp/translator/x86toc.mjs --help
```

The normal web build uses the included `out_all/` and does not require the translator packages. Retranslation also uses the included analysis data; repeating executable
analysis in Ghidra and running natively have additional dependencies, including
Ghidra, JDK, and the macOS SDK.

## Building and running locally

```sh
sh korsary2-next/recomp/build_web_local.sh
cd korsary2-next
node recomp/web/serve.mjs --port 8007 --game game \
  --videos ../distribution/videos --overlay-dir ../korsary2-work/english-overlay
```

Open `http://localhost:8007/`. The first build compiles a large amount of C code;
generated caches and object files remain local. The server accepts connections
only from this machine. The original ready build in `distribution/` is not changed.
Stop the server with `Ctrl+C`.

To build a new standalone directory after changing code or game data, return to
the repository root and specify a **new empty** output directory:

```sh
node korsary2-next/recomp/web/make_dist.mjs \
  --game korsary2-work/game --videos distribution/videos \
  --overlay-dir korsary2-work/english-overlay --out /path/to/new-distribution
node korsary2-next/recomp/tests/verify_dist.mjs \
  --dist /path/to/new-distribution --full-hash --require-overlay \
  --no-videos-web --source-game korsary2-work/game
```

If base files used by the English layer have changed, the packager reports a
mismatch: update the layer rather than disabling the check. To verify gameplay
in the new build, also run it in a browser. The packager excludes `SAVE`,
`SAVE_META`, and `SAVE_TX` directories from the distribution.
