#!/bin/sh
# Sea pixel shaders (ps.1.1 texm3x3vspec, handles 0x1000b/0x1000d) must translate to WGSL.
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/pshader-sea.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
CC=${CC:-clang}
# shellcheck disable=SC2086
"$CC" -O1 -g -w -fsanitize=address,undefined -I"$P/recomp/host" "$D/test_pshader_sea.c" "$P/recomp/host/pshader.c" -o "$T/test"
"$T/test"
