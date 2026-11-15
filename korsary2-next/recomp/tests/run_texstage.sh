#!/bin/sh
# Texture stages 2-3 (audit W6): the recorder's stage-state packing gate/normalization and the
# fixed-function multi-stage blend formula (old 2-stage == new 4-stage equivalence, the shipped
# maineffects/artifact stage-2 cases, SELECTARG1/alpha ops, disable termination). The test includes
# the recorder source itself.
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/texstage.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
cd "$P"
case "${1:-native}" in
native)
  case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip ;; *) GC=-Wl,--gc-sections ;; esac
  clang -std=gnu11 -Wall -Wextra -Werror -fsanitize=address,undefined \
    -ffunction-sections -fdata-sections "$GC" -Irecomp/host -Irecomp/runtime \
    recomp/tests/test_texstage.c -lm -o "$T/test"
  "$T/test" ;;
*) echo 'usage: run_texstage.sh [native]' >&2; exit 2;;
esac
