#!/bin/sh
# Synthetic WasmFS + OPFS test, with its own browser context and temporary server.
# Requires the prepared local Emscripten cache and Playwright described in the build docs.
set -eu
HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
RECOMP=$(dirname "$HERE")
SDK=${K2_EMSDK:-"$RECOMP/../third_party/emsdk"}
TMP=$(mktemp -d "${TMPDIR:-/tmp}/k2-lazy-browser.XXXXXXXX")
trap 'rm -rf "$TMP"' EXIT HUP INT TERM
export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$RECOMP/web_toolchain/cache" EM_FROZEN_CACHE=1
export PYTHONDONTWRITEBYTECODE=1
"$SDK/upstream/emscripten/emcc" "$RECOMP/experimental/lazy-loading/browser_probe.c" \
  "$RECOMP/experimental/lazy-loading/lazy_bridge.c" -I"$RECOMP/experimental/lazy-loading" \
  -pthread -sWASMFS=1 -sPROXY_TO_PTHREAD=1 -sPTHREAD_POOL_SIZE=4 -sEXIT_RUNTIME=0 -sALLOW_BLOCKING_ON_MAIN_THREAD=0 \
  -sENVIRONMENT=web,worker '-sEXPORTED_FUNCTIONS=["_main","_malloc","_free"]' \
  '-sEXPORTED_RUNTIME_METHODS=["wasmMemory"]' '-sDEFAULT_LIBRARY_FUNCS_TO_INCLUDE=["$stringToUTF8OnStack"]' \
  -o "$TMP/probe.js"
node "$HERE/test_lazy_bridge_browser.mjs" "$TMP"
