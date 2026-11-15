#!/bin/sh
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/move-safe.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "${1:-native}" in
native) CC=${CC:-clang};FLAGS='-fsanitize=address,undefined';OUT="$T/test";
  case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac;;
wasm) SDK="$P/third_party/emsdk";export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc";FLAGS='-pthread -sWASMFS=1';GC=-Wl,--gc-sections;OUT="$T/test.js";;
node) SDK="$P/third_party/emsdk";export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc";FLAGS='-pthread -DPORT_NODE_BUILD -sNODERAWFS=1';GC=-Wl,--gc-sections;OUT="$T/test.js";;
*) echo 'usage: run_move_file_fail_closed.sh [native|wasm|node]' >&2;exit 2;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_move_file_fail_closed.c" "$GC" -pthread -o "$OUT"
if [ "${1:-native}" = native ];then "$OUT";else node "$OUT";fi
