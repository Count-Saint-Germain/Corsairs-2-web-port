#!/bin/sh
# K3: нагрузочный тест кучи гостя + DirectSound (реальные core.c/com.c/dsound.c, -DPORT_HEAP_STATS) под ASan/UBSan.
set -eu
HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
T=$(mktemp -d "${TMPDIR:-/tmp}/heap-churn.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in
  Darwin) LINK_FLAGS='-Wl,-dead_strip -framework AudioToolbox' ;;
  *) LINK_FLAGS='-Wl,--gc-sections' ;;
esac
# shellcheck disable=SC2086
"${CC:-clang}" -std=gnu11 -w -O1 -g -fsanitize=address,undefined -ffunction-sections -fdata-sections \
  -I"$HERE/../host" -I"$HERE/../runtime" "$HERE/test_heap_churn.c" $LINK_FLAGS -pthread -lm -o "$T/test"
"$T/test"
