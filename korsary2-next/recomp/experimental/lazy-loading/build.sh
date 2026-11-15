#!/bin/sh
# Build an isolated EXPERIMENTAL wasm from a compatible, already built tree.
# This does not change build_web/ or distribution/. The output directory must
# not exist, to avoid overwriting any previously built assets or user data.
set -eu
if [ "$#" -ne 1 ]; then echo "Usage: sh $0 NEW_OUTPUT_DIRECTORY" >&2; exit 2; fi
mkdir "$1" || { echo 'Output directory must be new and its parent must exist.' >&2; exit 1; }
OUT=$(CDPATH= cd -- "$1" && pwd)
RECOMP=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
SDK=${K2_EMSDK:-"$RECOMP/../third_party/emsdk"}
[ -f "$SDK/.emscripten" ] && [ -x "$SDK/upstream/emscripten/emcc" ] || { echo 'Prepared Emscripten SDK is missing.' >&2; exit 1; }
[ -f "$RECOMP/build_web/runtime.o" ] && [ -f "$RECOMP/build_web/interp.o" ] && [ -d "$RECOMP/build_web/obj" ] || {
  echo 'Build the normal WebAssembly port first; its compatible objects are required.' >&2; exit 1;
}
export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$RECOMP/web_toolchain/cache" EM_PORTS="$RECOMP/web_toolchain/ports" EM_FROZEN_CACHE=1
export PYTHONDONTWRITEBYTECODE=1
export PATH="$SDK/upstream/emscripten:$SDK/upstream/bin:$PATH"
cd "$RECOMP"
mkdir "$OUT/host"
for source in host/*.c; do
  case "$(basename "$source")" in window.c|watch.c) continue ;; esac
  emcc -O1 -pthread -frounding-math -w -DPORT_LAZY_EXPERIMENT --use-port=emdawnwebgpu -Iruntime -Ihost \
    -c "$source" -o "$OUT/host/$(basename "${source%.c}").o"
done
emcc -O1 -pthread -frounding-math -w -DPORT_LAZY_EXPERIMENT -Iruntime -Ihost \
  -c experimental/lazy-loading/lazy_bridge.c -o "$OUT/lazy_bridge.o"
emcc -pthread -O1 --profiling-funcs -o "$OUT/game.js" build_web/runtime.o build_web/interp.o \
  "$OUT/lazy_bridge.o" "$OUT"/host/*.o build_web/obj/*.o \
  --use-port=emdawnwebgpu -sWASMFS -sPROXY_TO_PTHREAD -sPTHREAD_POOL_SIZE=16 -sALLOW_MEMORY_GROWTH \
  -sINITIAL_MEMORY=33554432 -sMAXIMUM_MEMORY=4GB -sSTACK_SIZE=8MB -sDEFAULT_PTHREAD_STACK_SIZE=32MB -sENVIRONMENT=web,worker \
  -sMODULARIZE -sEXPORT_NAME=createPort '-sEXPORTED_FUNCTIONS=["_main","_malloc","_free"]' \
  -sEXPORTED_RUNTIME_METHODS=ENV,wasmMemory -sEXIT_RUNTIME=0
perl -0pi -e 's/\(growMemViews\(\), HEAPU32\), \(\(dynamicOffsetsPtr\) >>> 2\), dynamicOffsetCount\)/(growMemViews(), HEAPU32.slice(dynamicOffsetsPtr >>> 2, (dynamicOffsetsPtr >>> 2) + dynamicOffsetCount)))/g' "$OUT/game.js"
grep -q 'HEAPU32.slice(dynamicOffsetsPtr' "$OUT/game.js" || { echo 'WebGPU dynamic offsets patch did not apply.' >&2; exit 1; }
echo "Experimental build: $OUT"
