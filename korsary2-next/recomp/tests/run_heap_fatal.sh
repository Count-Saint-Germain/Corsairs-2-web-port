#!/bin/sh
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "${TMPDIR:-/tmp}/heap-fatal.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
clang -std=gnu11 -w -O1 -fsanitize=address,undefined -ffunction-sections -fdata-sections "$GC" \
  -I"$P/recomp/host" -I"$P/recomp/runtime" "$P/recomp/tests/test_heap_fatal.c" -pthread -o "$T/test_heap_fatal"
"$T/test_heap_fatal"
