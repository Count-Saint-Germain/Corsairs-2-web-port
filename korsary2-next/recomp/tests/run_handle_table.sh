#!/bin/sh
# Таблица дескрипторов core.c под несколькими потоками (PORT_SPECIFICATION.md): настоящие core.c и
# kernel32.c, синтетические временные папки; игра не запускается.
#   run_handle_table.sh [native|tsan|stress|wasm|node|before BASE_DIR|before-tails BASE_DIR|mutate|bench]     (по умолчанию: native)
#   native  clang ASan/UBSan; режимы unset, 0, empty (permissive) и 1 (strict)
#   tsan    clang ThreadSanitizer; permissive и strict
#   stress  16 потоков x 100000 операций сырой таблицы и guest-уровня под ASan, затем 16 x 20000 под TSan
#   wasm    emcc WasmFS (память /tmp, не браузерный OPFS) под Node; нужен замок emcc
#   node    emcc NODERAWFS под Node; нужен замок emcc
#   before  тот же тест под TSan против СТАРОЙ копии recomp/host (BASE_DIR/host): ОЖИДАЕТСЯ провал (гонка)
#   before-tails BASE_DIR  части F (ожидание при закрытии), G (таблица потоков), H (fd маппинга) против копии host ДО правок
#           хвостов (раздел «Закрытые хвосты»): ОЖИДАЕТСЯ провал каждой; S под TSan показывает гонку, I (контракт снимка) проходит
#   mutate  снятие замка / атомарности в каждой точке таблицы должно ловиться тестом (tests/mutate_handle_table.sh)
#   bench   [BASE_DIR] микробенчмарк накладных расходов на операцию с handle (tests/bench_handle_table.c), native -O2; с BASE_DIR сравнение со старой копией
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/handle-table.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
MODE=${1:-native}
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
CC=${CC:-clang}
SRC="$D/test_handle_table.c"
HOST="$P/recomp/host"
build() {   # build OUT FLAGS HOSTDIR
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w $2 -ffunction-sections -fdata-sections -I"$3" -I"$P/recomp/runtime" "$SRC" "$GC" -pthread -o "$1"
}
case "$MODE" in
native)
  build "$T/t" '-fsanitize=address,undefined' "$HOST"
  for m in unset 0 empty 1; do "$T/t" "$T" "$m"; done;;
tsan)
  build "$T/t" '-fsanitize=thread' "$HOST"
  for m in unset 1; do "$T/t" "$T" "$m"; done;;
stress)
  build "$T/a" '-fsanitize=address,undefined' "$HOST"
  build "$T/t" '-fsanitize=thread' "$HOST"
  for m in unset 1; do HT_THREADS=16 HT_ITERS=100000 HT_RAW_ITERS=100000 "$T/a" "$T" "$m"; done
  for m in unset 1; do HT_THREADS=16 HT_ITERS=20000 HT_RAW_ITERS=100000 "$T/t" "$T" "$m"; done;;
before)
  BASE=${2:?usage: run_handle_table.sh before BASE_DIR}
  [ -f "$BASE/host/core.c" ] || { echo "no $BASE/host/core.c" >&2; exit 2; }
  mkdir -p "$T/basetree/tests"
  ln -s "$BASE/host" "$T/basetree/host"
  cp "$SRC" "$T/basetree/tests/"
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w -DHT_OLD_TREE -fsanitize=thread -ffunction-sections -fdata-sections -I"$BASE/host" -I"$P/recomp/runtime" "$T/basetree/tests/test_handle_table.c" "$GC" -pthread -o "$T/before"
  rc=0
  for m in unset 1; do
    HT_ONLY=none HT_THREADS=4 HT_ITERS=2000 "$T/before" "$T" "$m" > "$T/before.$m.txt" 2>&1 || rc=1   # parts A-E only: the wait/thread/mapping parts have their own before-tails
    n=$(grep -c 'WARNING: ThreadSanitizer' "$T/before.$m.txt" || true)
    echo "old tree, mode $m: $n ThreadSanitizer warnings"
    grep '^SUMMARY' "$T/before.$m.txt" | sort | uniq -c | sort -rn | head -12
    [ "$n" -gt 0 ] || { echo "the old tree did not show the race (the test no longer reproduces it)" >&2; exit 1; }
  done
  [ -z "${BEFORE_KEEP:-}" ] || cp "$T/before.unset.txt" "$T/before.1.txt" "$BEFORE_KEEP"/
  echo "old tree reproduces the race: PASS"
  exit 0;;
before-tails)
  BASE=${2:?usage: run_handle_table.sh before-tails BASE_DIR}
  [ -f "$BASE/host/core.c" ] || { echo "no $BASE/host/core.c" >&2; exit 2; }
  mkdir -p "$T/basetree/tests" "$T/sc"
  ln -s "$BASE/host" "$T/basetree/host"
  cp "$SRC" "$T/basetree/tests/"
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w -DHT_OLD_TREE -fsanitize=address,undefined -ffunction-sections -fdata-sections -I"$BASE/host" -I"$P/recomp/runtime" "$T/basetree/tests/test_handle_table.c" "$GC" -pthread -o "$T/old_asan"
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w -DHT_OLD_TREE -fsanitize=thread -ffunction-sections -fdata-sections -I"$BASE/host" -I"$P/recomp/runtime" "$T/basetree/tests/test_handle_table.c" "$GC" -pthread -o "$T/old_tsan"
  bad=0
  for part in F G H; do
    if HT_ONLY=$part HT_THREADS=2 HT_ITERS=300 "$T/old_asan" "$T/sc" unset > "$T/old.$part.txt" 2>&1; then echo "old tree, part $part: passes (the test does not reproduce the defect)"; bad=1
    else echo "old tree, part $part: FAILS as expected: $(grep -m1 -E '^FAIL|ERROR' "$T/old.$part.txt" | sed 's#.*/tests/##' | cut -c1-110)"; fi
  done
  HT_ONLY=S HT_THREADS=2 HT_ITERS=1500 "$T/old_tsan" "$T/sc" unset > "$T/old.S.txt" 2>&1 || true
  n=$(grep -c 'WARNING: ThreadSanitizer' "$T/old.S.txt" || true)
  echo "old tree, part S under TSan: $n warnings"; grep '^SUMMARY' "$T/old.S.txt" | sort | uniq -c | head -5
  [ "$n" -gt 0 ] || { echo "the old tree did not show the wait/slot race under TSan" >&2; bad=1; }
  if HT_ONLY=I HT_THREADS=2 HT_ITERS=300 "$T/old_asan" "$T/sc" unset > "$T/old.I.txt" 2>&1; then echo "old tree, part I (snapshot contract): passes, behaviour unchanged"
  else echo "old tree, part I FAILS: the snapshot contract differs between the trees" >&2; bad=1; fi
  [ "$bad" -eq 0 ] && echo "old tree shows the tails (F, G, H, S) and the same snapshot contract (I): PASS"
  exit "$bad";;
mutate) rc=0; sh "$D/mutate_handle_table.sh" > "$T/mut.txt" 2>&1 || rc=$?; grep -v "Abort trap" "$T/mut.txt"; exit "$rc";;
bench)
  # bench [BASE_DIR]: the new host, and the old copy for comparison when BASE_DIR is given
  "$CC" -O2 -g -w -DNDEBUG -ffunction-sections -fdata-sections -I"$HOST" -I"$P/recomp/runtime" "$D/bench_handle_table.c" "$GC" -pthread -o "$T/bench_new"
  if [ -n "${2:-}" ]; then
    mkdir -p "$T/basetree/tests"; ln -s "$2/host" "$T/basetree/host"; cp "$D/bench_handle_table.c" "$T/basetree/tests/"
    "$CC" -O2 -g -w -DNDEBUG -ffunction-sections -fdata-sections -I"$2/host" -I"$P/recomp/runtime" "$T/basetree/tests/bench_handle_table.c" "$GC" -pthread -o "$T/bench_old"
    echo "=== old tree (BASE_DIR/host)"; "$T/bench_old" "$T"
  fi
  echo "=== current tree (recomp/host)"; "$T/bench_new" "$T"
  exit 0;;
wasm|node)
  SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; OUT="$T/test.js"; GC=-Wl,--gc-sections
  # main runs in a worker so that pthread_cond_wait/join do not block Node's event loop; the pool covers every test thread
  FLAGS='-pthread -sPROXY_TO_PTHREAD=1 -sPTHREAD_POOL_SIZE=24 -sEXIT_RUNTIME=1 -sENVIRONMENT=node -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB'
  if [ "$MODE" = wasm ]; then FLAGS="$FLAGS -sWASMFS=1"; SCRATCH=/tmp; else FLAGS="$FLAGS -DPORT_NODE_BUILD -sNODERAWFS=1"; SCRATCH="$T"; fi
  # shellcheck disable=SC2086
  "$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$HOST" -I"$P/recomp/runtime" "$SRC" "$GC" -pthread -o "$OUT"
  # the environment does not reach the wasm module reliably (WasmFS): threads and iterations go in as arguments
  for m in unset 1; do node "$OUT" "$SCRATCH" "$m" 8 1500; done;;
*) echo 'usage: run_handle_table.sh [native|tsan|stress|wasm|node|before BASE_DIR|before-tails BASE_DIR|mutate|bench [BASE_DIR]]' >&2; exit 2;;
esac
