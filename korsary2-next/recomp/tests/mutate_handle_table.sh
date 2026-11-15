#!/bin/sh
# Мутационная проверка таблицы дескрипторов: каждая мутация (tests/mutate_handle_table.mjs) снимает одну защиту в
# копии recomp/host; test_handle_table.c под TSan (permissive и strict) и ASan должен её поймать (код выхода != 0
# или отчёт санитайзера). Немутированная копия обязана пройти. Синтетические данные во временной папке.
set -u
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/handle-mut.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
CC=${CC:-clang}
SRC="$D/test_handle_table.c"
# one-shot run of the test against HOSTDIR: tsan/asan, mode; prints nothing, returns 0 when the test is clean
caught=0; total=0; failed=0
run_one() {   # run_one HOSTDIR SAN
  mkdir -p "$T/tree/tests"; rm -f "$T/tree/host"; ln -s "$1" "$T/tree/host"; cp "$SRC" "$T/tree/tests/"
  case "$2" in tsan) F=-fsanitize=thread;; asan) F=-fsanitize=address,undefined;; esac
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w $F -ffunction-sections -fdata-sections -I"$1" -I"$P/recomp/runtime" "$T/tree/tests/test_handle_table.c" "$GC" -pthread -o "$T/bin" 2> "$T/cc.txt" || { cat "$T/cc.txt" >&2; return 99; }
  rc=0
  for m in unset 1; do
    ( HT_THREADS=4 HT_ITERS=1500 HT_RAW_ITERS=8000 "$T/bin" "$T" "$m" > "$T/out.$m.txt" 2>&1 ) 2>/dev/null || rc=1
    grep -q 'Sanitizer' "$T/out.$m.txt" && rc=1
    [ "$rc" -eq 0 ] || { grep -m1 -E 'FAIL|SUMMARY|ERROR: AddressSanitizer' "$T/out.$m.txt" | cut -c1-150 > "$T/why.txt"; return 1; }
  done
  : > "$T/why.txt"
  return 0
}
echo "control (unmutated host):"
for san in tsan asan; do
  run_one "$P/recomp/host" $san || { echo "  $san: FAIL (the clean tree does not pass)"; cat "$T/why.txt"; exit 1; }
  echo "  $san: clean: PASS"
done
for name in $(node "$D/mutate_handle_table.mjs" list); do
  total=$((total+1))
  rm -rf "$T/mh"
  node "$D/mutate_handle_table.mjs" "$name" "$P/recomp/host" "$T/mh" || { echo "$name: cannot apply the mutation" >&2; exit 2; }
  tw=""; aw=""
  run_one "$T/mh" tsan; r=$?; [ $r -eq 99 ] && { echo "$name: the mutant does not compile" >&2; exit 2; }
  [ $r -ne 0 ] && tw=$(cat "$T/why.txt")
  run_one "$T/mh" asan; r=$?; [ $r -eq 99 ] && { echo "$name: the mutant does not compile" >&2; exit 2; }
  [ $r -ne 0 ] && aw=$(cat "$T/why.txt")
  if [ -n "$tw$aw" ]; then
    caught=$((caught+1))
    echo "  caught  $name"
    echo "          TSan: ${tw:-missed}"
    echo "          ASan/UBSan + the test's own checks: ${aw:-missed}"
  else failed=$((failed+1)); echo "  MISSED  $name"; fi
done
echo "mutations caught: $caught of $total"
[ "$failed" -eq 0 ]
