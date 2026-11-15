#!/bin/sh
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/cube-d3d.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
clang -std=gnu11 -w -fsanitize=address,undefined -ffunction-sections -fdata-sections "$GC" \
 -I"$P/recomp/host" -I"$P/recomp/runtime" "$P/recomp/tests/test_cube_d3d_coherence.c" -lm -o "$T/test"
"$T/test"
