#!/bin/sh
# Isolated diagnostic test. Requires the user's local sea.dll; do not publish it.
set -eu
R=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
P=$(dirname "$R")
T=$(mktemp -d "$R/web_toolchain/tmp/sea-indirect-test.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "${1:-native}" in
native)
    CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUTPUT="$T/test"
    case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip ;; *) GC=-Wl,--gc-sections ;; esac
    ;;
wasm)
    SDK="$P/third_party/emsdk"
    export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$R/web_toolchain/cache" EM_PORTS="$R/web_toolchain/ports"
    export TMPDIR="$R/web_toolchain/tmp" XDG_CACHE_HOME="$R/web_toolchain/xdg-cache" PYTHONDONTWRITEBYTECODE=1
    export PATH="$SDK/upstream/emscripten:$SDK/upstream/bin:$PATH"
    CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -sNODERAWFS=1 -sENVIRONMENT=node'; GC=-Wl,--gc-sections; OUTPUT="$T/test.js"
    ;;
*) echo "Usage: $0 [native|wasm]" >&2; exit 2 ;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -std=gnu11 -w $FLAGS -ffunction-sections -fdata-sections -I"$R/runtime" -c "$R/runtime/runtime.c" -o "$T/runtime.o"
# shellcheck disable=SC2086
"$CC" -O1 -std=gnu11 $FLAGS -ffunction-sections -fdata-sections -I"$R/runtime" "$R/tests/test_sea_indirect_hook.c" "$T/runtime.o" "$GC" -lm -o "$OUTPUT"
if [ "${1:-native}" = wasm ]; then
    node "$OUTPUT" "$P/game/MODULES/sea.dll" >"$T/plain.log" 2>&1
    node "$OUTPUT" "$P/game/MODULES/sea.dll" --trace >"$T/trace.log" 2>&1
else
    "$OUTPUT" "$P/game/MODULES/sea.dll" >"$T/plain.log" 2>&1
    "$OUTPUT" "$P/game/MODULES/sea.dll" --trace >"$T/trace.log" 2>&1
fi
if grep -Fq '[call] 00501000' "$T/plain.log"; then
    cat "$T/plain.log"; echo 'unexpected trace in plain mode' >&2; exit 1
fi
if ! grep -Fq '[call] 00501000' "$T/trace.log" || ! grep -Fq '[call]   -> mult' "$T/trace.log"; then
    cat "$T/trace.log"; echo 'trace branch was not exercised' >&2; exit 1
fi
echo "sea indirect hook: plain and trace paths passed (${1:-native})"
