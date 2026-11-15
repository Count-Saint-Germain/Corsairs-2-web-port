#!/bin/sh
# Native ASan/UBSan: граничные случаи только-чтения seh_diag_* (host/seh_diagnostic.h).
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "${TMPDIR:-/tmp}/seh-diagnostic.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
clang -std=gnu11 -Wall -Wextra -fsanitize=address,undefined -fno-sanitize-recover=undefined \
 -I"$P/recomp/host" "$P/recomp/tests/test_seh_diagnostic.c" -o "$T/test"
"$T/test"
