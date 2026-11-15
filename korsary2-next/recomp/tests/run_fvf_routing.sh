#!/bin/sh
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/fvf-routing.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
cd "$P"
case "${1:-native}" in
native)
  case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip ;; *) GC=-Wl,--gc-sections ;; esac
  clang -std=gnu11 -Wall -Wextra -Werror -fsanitize=address,undefined \
    -ffunction-sections -fdata-sections "$GC" -Irecomp/host -Irecomp/runtime \
    recomp/tests/test_fvf_routing.c -lm -o "$T/test"
  "$T/test" ;;
wasm)
  export EM_CONFIG="$PWD/third_party/emsdk/.emscripten"
  export EM_CACHE="$PWD/recomp/web_toolchain/cache" EM_PORTS="$PWD/recomp/web_toolchain/ports"
  export TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  ./third_party/emsdk/upstream/emscripten/emcc -std=gnu11 -O1 -ffunction-sections -fdata-sections \
    -Wl,--gc-sections -sENVIRONMENT=node -Irecomp/host -Irecomp/runtime \
    recomp/tests/test_fvf_routing.c -lm -o "$T/test.js"
  node "$T/test.js" ;;
*) echo 'usage: run_fvf_routing.sh [native|wasm]' >&2; exit 2;;
esac
