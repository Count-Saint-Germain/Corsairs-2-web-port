#!/bin/sh
# K1: default-mode CreateDirectoryA / RemoveDirectoryA / CopyFileA contract (the one live caller is
# CreateDirectoryA("SAVE") of the save list; see tools-dev/file-share-policy-diagnostic/K1_COPYFILE_AUDIT.md) on the
# real kernel32.c handlers. Synthetic temp dirs only; not a check of the running game.
#   run_k1_dir_copy.sh [native|savetx|wasm|node]     (default: native)
#   native  clang ASan/UBSan
#   savetx  native ASan/UBSan with -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1 (mkdir/copy/rmdir next to the SAVE hooks)
#   wasm    emcc WasmFS (in-memory /tmp, NOT browser OPFS) under Node; needs the emcc lock
#   node    emcc NODERAWFS under Node; needs the emcc lock
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/k1-dir-copy.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
MODE=${1:-native}
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
case "$MODE" in
native) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUT="$T/test"; SCRATCH="$T";;
savetx) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1'; OUT="$T/test"; SCRATCH="$T";;
wasm|node)
  SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; OUT="$T/test.js"; GC=-Wl,--gc-sections
  FLAGS='-pthread -sPROXY_TO_PTHREAD=1 -sPTHREAD_POOL_SIZE=14 -sEXIT_RUNTIME=1 -sENVIRONMENT=node -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB'
  if [ "$MODE" = wasm ]; then FLAGS="$FLAGS -sWASMFS=1"; SCRATCH=/tmp; else FLAGS="$FLAGS -DPORT_NODE_BUILD -sNODERAWFS=1"; SCRATCH="$T"; fi;;
*) echo 'usage: run_k1_dir_copy.sh [native|savetx|wasm|node]' >&2; exit 2;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_k1_default_dirs_copy.c" "$GC" -pthread -o "$OUT"
case "$MODE" in wasm|node) node "$OUT" "$SCRATCH";; *) "$OUT" "$SCRATCH";; esac
