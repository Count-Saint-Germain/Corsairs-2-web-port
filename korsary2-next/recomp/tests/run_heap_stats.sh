#!/bin/sh
# Native ASan/UBSan: диагностический проход по куче гостя (-DPORT_HEAP_STATS) и, для контроля,
# что штатный test_guest_heap.c без флага по-прежнему проходит (в обычной сборке кода счётчика нет).
set -eu
P=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
T=$(mktemp -d "${TMPDIR:-/tmp}/heap-stats.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
for t in test_heap_stats test_guest_heap; do
  clang -std=gnu11 -w -O1 -fsanitize=address,undefined -ffunction-sections -fdata-sections "$GC" \
    -I"$P/recomp/host" -I"$P/recomp/runtime" "$P/recomp/tests/$t.c" -pthread -o "$T/$t"
  "$T/$t"
done
# флаг выключен: символов диагностики нет
clang -std=gnu11 -w -O1 -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" \
  -c "$P/recomp/host/core.c" -o "$T/core_off.o"
if nm "$T/core_off.o" | grep -q guest_heap_walk_stats; then echo "FAIL: диагностика попала в обычную сборку" >&2; exit 1; fi
echo "heap stats: флаг выключен — символов нет"
