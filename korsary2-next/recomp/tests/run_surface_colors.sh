#!/bin/sh
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/surface-colors.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
clang -std=c11 -Wall -Wextra -Werror -fsanitize=address,undefined \
 -I"$P/recomp/host" "$P/recomp/tests/test_surface_colors.c" -lm -o "$T/test"
"$T/test"
