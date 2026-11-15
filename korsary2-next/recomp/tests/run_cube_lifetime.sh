#!/bin/sh
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/cube-lifetime.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
clang -std=gnu11 -w -fsanitize=address,undefined -ffunction-sections -fdata-sections "$GC" \
 -I"$P/recomp/host" -I"$P/recomp/runtime" "$P/recomp/tests/test_cube_lifetime.c" -lm -o "$T/test"
"$T/test"
clang -std=gnu11 -w -DUSE_REAL_COM -fsanitize=address,undefined -ffunction-sections -fdata-sections "$GC" \
 -I"$P/recomp/host" -I"$P/recomp/runtime" "$P/recomp/tests/test_cube_lifetime.c" -lm -pthread -o "$T/test-real"
"$T/test-real"
