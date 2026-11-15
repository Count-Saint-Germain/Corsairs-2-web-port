#!/bin/sh
# Isolated native bridge test; output goes to a disposable temporary directory.
set -eu
HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
RECOMP=$(dirname "$HERE")
TMP=$(mktemp -d "${TMPDIR:-/tmp}/k2-lazy-bridge.XXXXXXXX")
trap 'rm -rf "$TMP"' EXIT HUP INT TERM
${CC:-cc} -std=c11 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -Werror -pthread \
  -I"$RECOMP/experimental/lazy-loading" "$RECOMP/experimental/lazy-loading/lazy_bridge.c" \
  "$HERE/test_lazy_bridge.c" -o "$TMP/test"
"$TMP/test"
