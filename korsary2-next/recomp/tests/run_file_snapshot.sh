#!/bin/sh
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/file-snapshot.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "${1:-native}" in
native) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUT="$T/test";
  case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac;;
wasm) SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -sWASMFS=1'; GC=-Wl,--gc-sections; OUT="$T/test.js";;
node) SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -DPORT_NODE_BUILD -sNODERAWFS=1'; GC=-Wl,--gc-sections; OUT="$T/test.js";;
*) echo 'usage: run_file_snapshot.sh [native|wasm|node]' >&2; exit 2;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_file_snapshot.c" "$GC" -pthread -o "$OUT"
# The snapshot default and the PORT_FILE_SNAPSHOT=0 off switch are both part of the contract.
case "${1:-native}" in
wasm|node)
  node "$OUT"
  PORT_FILE_SNAPSHOT_OFF=1 node "$OUT";;
*)
  "$OUT"
  PORT_FILE_SNAPSHOT_OFF=1 "$OUT";;
esac
