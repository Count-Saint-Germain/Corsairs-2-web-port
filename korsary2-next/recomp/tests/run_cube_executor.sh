#!/bin/sh
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/cube-executor.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
printf '%s\n' '#define EMSCRIPTEN_KEEPALIVE' 'static inline double emscripten_get_now(void) { return 0; }' > "$T/emscripten.h"
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
clang -std=gnu11 -w -fsanitize=address,undefined -ffunction-sections -fdata-sections "$GC" \
 -I"$T" -I"$P/recomp/host" -I"$P/recomp/runtime" \
 -I"$P/recomp/web_toolchain/ports/emdawnwebgpu/emdawnwebgpu_pkg/webgpu/include" \
 "$P/recomp/tests/test_cube_executor.c" -lm -o "$T/test"
"$T/test"
