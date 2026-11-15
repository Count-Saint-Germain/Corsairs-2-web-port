#!/bin/sh
# Ф4.2 SAVE_TX: host half (native, ASan/UBSan, real kernel32.c handlers + syscall shim) and,
# with "matrix", the kill-point matrix recovered by the page code (Node). Synthetic temp dirs only.
#   run_save_tx.sh [unit|strict|matrix|all|wasm|node]     (default: all; wasm/node = unit assertions under emcc)
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/save-tx.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "${1:-all}" in
wasm|node)   # unit assertions only, in WasmFS / NODERAWFS (needs the machine-wide emcc lock; see the report)
  SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  if [ "$1" = wasm ]; then FLAGS='-pthread -sWASMFS=1 -DPORT_SAVE_TX=1 -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB -sPTHREAD_POOL_SIZE=4'; else FLAGS='-pthread -DPORT_NODE_BUILD -sNODERAWFS=1 -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1 -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB -sPTHREAD_POOL_SIZE=4'; fi
  # shellcheck disable=SC2086
  "$SDK/upstream/emscripten/emcc" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_save_tx.c" -Wl,--gc-sections -pthread -o "$T/test_save_tx.js"
  # NODERAWFS: the pthread stress part hangs on the Node event loop (pool workers never start while the main thread blocks); WasmFS runs it
  if [ "$1" = node ]; then SAVE_TX_NO_THREADS=1 node "$T/test_save_tx.js"; else node "$T/test_save_tx.js"; fi; exit $?;;
esac
CC=${CC:-clang}
FLAGS='-fsanitize=address,undefined -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1'
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_save_tx.c" "$GC" -pthread -o "$T/test_save_tx"
envcheck() {   # the runtime switch alone (no -DPORT_SAVE_TX): unset, "0" and "" are OFF, anything else ON
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w -fsanitize=address,undefined -DPORT_SAVE_META=1 -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_save_tx.c" "$GC" -pthread -o "$T/test_save_tx_env"
  env -u PORT_SAVE_TX "$T/test_save_tx_env" --envcheck 0
  PORT_SAVE_TX=0 "$T/test_save_tx_env" --envcheck 0
  PORT_SAVE_TX= "$T/test_save_tx_env" --envcheck 0
  PORT_SAVE_TX=1 "$T/test_save_tx_env" --envcheck 1
}
case "${1:-all}" in
unit) "$T/test_save_tx"; envcheck;;
strict) PORT_STRICT_FILE_SHARE=1 "$T/test_save_tx";;
matrix) SAVE_TX_BIN="$T/test_save_tx" node "$D/test_save_tx_matrix.mjs";;
all) "$T/test_save_tx"; envcheck; PORT_STRICT_FILE_SHARE=1 "$T/test_save_tx"; SAVE_TX_BIN="$T/test_save_tx" node "$D/test_save_tx_matrix.mjs";;
*) echo 'usage: run_save_tx.sh [unit|strict|matrix|all|wasm|node]' >&2; exit 2;;
esac
