#!/bin/sh
set -eu
HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
TMPDIR_TEST=$(mktemp -d "${TMPDIR:-/tmp}/dsound-lifetime.XXXXXXXX")
trap 'rm -rf "$TMPDIR_TEST"' EXIT HUP INT TERM
case "${1:-asan}" in
  asan) SANITIZER=address,undefined ;;
  tsan) SANITIZER=thread ;;
  *) echo 'usage: run_dsound_lifetime.sh [asan|tsan]' >&2; exit 2 ;;
esac
case "$(uname -s)" in
  Darwin) LINK_FLAGS='-Wl,-dead_strip -framework AudioToolbox' ;;
  *) LINK_FLAGS='-Wl,--gc-sections' ;;
esac
# LINK_FLAGS is selected solely from the fixed alternatives above.
# shellcheck disable=SC2086
"${CC:-clang}" -std=c11 -O1 -g "-fsanitize=$SANITIZER" -ffunction-sections -fdata-sections \
  -I"$HERE/../host" -I"$HERE/../runtime" "$HERE/test_dsound_lifetime.c" \
  $LINK_FLAGS -pthread -lm -o "$TMPDIR_TEST/test"
"$TMPDIR_TEST/test"
