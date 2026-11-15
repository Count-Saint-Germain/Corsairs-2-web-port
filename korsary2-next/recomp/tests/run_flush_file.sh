#!/bin/sh
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/flush-file.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "${1:-native}" in
native)
    CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUT="$T/test"
    case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip ;; *) GC=-Wl,--gc-sections ;; esac ;;
wasm)
    SDK="$P/third_party/emsdk"
    export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$T/cache" EM_PORTS="$T/ports"
    export TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
    CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -sWASMFS=1'; GC=-Wl,--gc-sections; OUT="$T/test.js" ;;
*) echo "Usage: $0 [native|wasm]" >&2; exit 2 ;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_flush_file.c" "$GC" -pthread -o "$OUT"
if [ "${1:-native}" = wasm ]; then node "$OUT"; else "$OUT"; fi
