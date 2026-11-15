#!/bin/sh
# Fog (audit W5): D3D8 fog formulas/state mapping, specular-alpha transport, oFog capture and the
# fog injection into real pshader.c WGSL output. Sources are included by the test itself.
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/fog.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
cd "$P"
case "${1:-native}" in
native)
  case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip ;; *) GC=-Wl,--gc-sections ;; esac
  clang -std=gnu11 -Wall -Wextra -Werror -fsanitize=address,undefined \
    -ffunction-sections -fdata-sections "$GC" -Irecomp/host -Irecomp/runtime \
    recomp/tests/test_fog.c -lm -o "$T/test"
  "$T/test" ;;
wasm)
  export EM_CONFIG="$PWD/third_party/emsdk/.emscripten"
  export EM_CACHE="$PWD/recomp/web_toolchain/cache" EM_PORTS="$PWD/recomp/web_toolchain/ports"
  export TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  ./third_party/emsdk/upstream/emscripten/emcc -std=gnu11 -O1 -ffunction-sections -fdata-sections \
    -Wl,--gc-sections -sENVIRONMENT=node -Irecomp/host -Irecomp/runtime \
    recomp/tests/test_fog.c -lm -o "$T/test.js"
  node "$T/test.js" ;;
*) echo 'usage: run_fog.sh [native|wasm]' >&2; exit 2;;
esac
