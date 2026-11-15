#!/bin/sh
# Both experimental-on and default-off Win32 paths on synthetic game trees.
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
T=$(mktemp -d "${TMPDIR:-/tmp}/corsairs-lazy-fs.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
for mode in off on; do
  flags=
  if [ "$mode" = on ]; then flags=-DPORT_LAZY_EXPERIMENT; fi
  # flags is either empty or a single compiler option.
  # shellcheck disable=SC2086
  clang -O1 -g -w -fsanitize=address,undefined -ffunction-sections -fdata-sections $flags \
    -I"$D/../host" -I"$D/../runtime" "$D/test_lazy_fs.c" "$GC" -pthread -o "$T/$mode"
  mkdir "$T/tree-$mode"
  "$T/$mode" "$T/tree-$mode"
done
