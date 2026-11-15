#!/bin/sh
# Use the existing SDK read-only; keep generated files, ports, caches and temp files here.
set -eu
R=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(dirname "$R")
SDK=${K2_EMSDK:-"$P/third_party/emsdk"}
if [ ! -f "$SDK/.emscripten" ] || [ ! -x "$SDK/upstream/emscripten/emcc" ]; then
    echo "Emscripten SDK not found or not activated at $SDK; see docs/BUILD_FROM_CLONE.md." >&2
    exit 1
fi
SDK=$(CDPATH= cd -- "$SDK" && pwd)
export EM_CONFIG="$SDK/.emscripten"
export EM_CACHE="$R/web_toolchain/cache"
export EM_PORTS="$R/web_toolchain/ports"
export TMPDIR="$R/web_toolchain/tmp"
export XDG_CACHE_HOME="$R/web_toolchain/xdg-cache"
export PYTHONDONTWRITEBYTECODE=1
export PATH="$SDK/upstream/emscripten:$SDK/upstream/bin:$PATH"
unset EMCC_LOCAL_PORTS EM_COMPILER_WRAPPER
mkdir -p "$EM_CACHE" "$EM_PORTS" "$TMPDIR" "$XDG_CACHE_HOME"

PORT="$EM_PORTS/emdawnwebgpu/emdawnwebgpu_pkg/emdawnwebgpu.port.py"
URL='https://github.com/google/dawn/releases/download/v20260423.175430/emdawnwebgpu_pkg-v20260423.175430.zip'
if [ ! -f "$PORT" ] || ! grep -Fqx "$URL" "$EM_PORTS/emdawnwebgpu/.emscripten_url" 2>/dev/null; then
    echo "Missing verified emdawnwebgpu package; run tools/stage_emdawn.mjs with the pinned archive." >&2
    exit 1
fi

# Run sanity before restoring sysroot: Emscripten clears its cache when the SDK
# path changes, even when a copied cache contains otherwise valid libraries.
emcc --version >/dev/null
if [ ! -d "$EM_CACHE/sysroot" ]; then
    SDK_CACHE="$SDK/upstream/emscripten/cache"
    if [ -d "$SDK_CACHE/sysroot" ] && [ -f "$SDK_CACHE/sysroot_install.stamp" ]; then
        # A failed or interrupted copy must not look like a complete sysroot.
        COPY_DIR="$EM_CACHE/.sysroot-copy-$$"
        trap 'rm -rf "$COPY_DIR"' EXIT HUP INT TERM
        if [ "$(uname -s)" = Darwin ] && cp -cR "$SDK_CACHE/sysroot" "$COPY_DIR"; then
            : # APFS clone avoids copying hundreds of MB when available.
        else
            rm -rf "$COPY_DIR"
            cp -R "$SDK_CACHE/sysroot" "$COPY_DIR"
        fi
        cp "$SDK_CACHE/sysroot_install.stamp" "$EM_CACHE/sysroot_install.stamp"
        mv "$COPY_DIR" "$EM_CACHE/sysroot"
        trap - EXIT HUP INT TERM
    fi
fi
exec sh "$R/build_web.sh"
