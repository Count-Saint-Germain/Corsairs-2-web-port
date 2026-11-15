#!/bin/sh
# E1: хост-оверлей (PORT_OVERLAY, host/core.c + kernel32.c): настоящие обработчики на синтетических временных деревьях
# (базовая установка, оверлей, «секрет» снаружи). Игра не запускается. docs/overlay-e1.md.
#   run_overlay.sh [native|tsan|savetx|wasm|node|all|diff BASE_DIR|bench BASE_DIR|mutate]     (по умолчанию: native)
#   native  clang ASan/UBSan: permissive и strict, снимки выключены и включены
#   tsan    clang ThreadSanitizer: permissive и strict (8 потоков строят индекс лениво и читают оверлей/базу)
#   savetx  ASan/UBSan с -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1 (оверлей рядом с SAVE_META/SAVE_TX)
#   wasm    emcc WasmFS (память /tmp, НЕ браузерный OPFS) под Node; нужен замок emcc
#   node    emcc NODERAWFS под Node; нужен замок emcc
#   all     native tsan savetx (без emcc)
#   diff    map_path на 100 000 путей (случайные и граничные) при выключенном оверлее (unset, "0", пусто, оверлей, в котором лежит
#           только то, что он не смотрит) против СТАРОЙ копии recomp/host (BASE_DIR/host): результаты байт-в-байт равны
#   bench   стоимость map_path: старая копия, оверлей выключен, оверлей включён (BASE_DIR/host как в diff)
#   mutate  мутации host/*.c (минимум 8): после каждой тесты обязаны упасть
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/overlay.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
MODE=${1:-native}
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
SRC="$D/test_overlay.c"
build() {   # build FLAGS OUT [HOSTDIR]
  # shellcheck disable=SC2086
  clang -O1 -g -w $1 -ffunction-sections -fdata-sections -I"${3:-$P/recomp/host}" -I"$P/recomp/runtime" "$SRC" "$GC" -pthread -o "$2"
}
# quiet CMD...: runs CMD, prints its output without the host's [overlay] log lines, and keeps CMD's exit status (a pipe into grep would hide a failure)
quiet() {
  "$@" > "$T/quiet.out" 2>&1 && rc=0 || rc=$?
  grep -v '^\[overlay\]' "$T/quiet.out" || true
  return $rc
}
runall() {   # runall BIN: permissive/strict x snapshots off/on
  for m in permissive strict; do for s in nosnap snap; do quiet "$1" "$T" "$m" "$s"; done; done
}
case "$MODE" in
native) build '-fsanitize=address,undefined' "$T/t"; runall "$T/t";;
tsan) build '-fsanitize=thread' "$T/t"; for m in permissive strict; do quiet "$T/t" "$T" "$m" snap; done;;
savetx) build '-fsanitize=address,undefined -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1' "$T/t"; for m in permissive strict; do quiet "$T/t" "$T" "$m" nosnap; done;;
all) sh "$0" native; sh "$0" tsan; sh "$0" savetx;;
wasm|node)
  SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  # main runs in a worker so that pthread_cond_wait/join do not block Node's event loop
  FLAGS='-pthread -sPROXY_TO_PTHREAD=1 -sPTHREAD_POOL_SIZE=14 -sEXIT_RUNTIME=1 -sENVIRONMENT=node -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB'
  if [ "$MODE" = wasm ]; then FLAGS="$FLAGS -sWASMFS=1"; WSC=/tmp; else FLAGS="$FLAGS -DPORT_NODE_BUILD -sNODERAWFS=1"; WSC="$T"; fi
  # shellcheck disable=SC2086
  "$SDK/upstream/emscripten/emcc" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$SRC" -Wl,--gc-sections -pthread -o "$T/t.js"
  for m in permissive strict; do for s in nosnap snap; do quiet node "$T/t.js" "$WSC" "$m" "$s"; done; done;;
diff|bench)
  BASE=${2:?usage: run_overlay.sh $MODE BASE_DIR}
  [ -f "$BASE/host/core.c" ] || { echo "no $BASE/host/core.c" >&2; exit 2; }
  mkdir -p "$T/basetree/tests"
  ln -s "$BASE/host" "$T/basetree/host"
  cp "$D/test_map_path_100k.c" "$T/basetree/tests/"
  clang -O1 -g -w -ffunction-sections -fdata-sections -I"$P/recomp/runtime" -fsanitize=address,undefined -I"$BASE/host" "$T/basetree/tests/test_map_path_100k.c" "$GC" -pthread -o "$T/mp_old"
  clang -O1 -g -w -ffunction-sections -fdata-sections -I"$P/recomp/runtime" -fsanitize=address,undefined -DOVERLAY_API -I"$P/recomp/host" "$D/test_map_path_100k.c" "$GC" -pthread -o "$T/mp_new"
  if [ "$MODE" = bench ]; then
    cp "$D/bench_map_path.c" "$T/basetree/tests/"
    clang -O2 -g -w -ffunction-sections -fdata-sections -I"$P/recomp/runtime" -I"$BASE/host" "$T/basetree/tests/bench_map_path.c" "$GC" -pthread -o "$T/bench_old"
    clang -O2 -g -w -DOVERLAY_API -ffunction-sections -fdata-sections -I"$P/recomp/runtime" -I"$P/recomp/host" "$D/bench_map_path.c" "$GC" -pthread -o "$T/bench_new"
    echo "-- old tree"; "$T/bench_old" "$T" off
    echo "-- new tree, overlay off"; "$T/bench_new" "$T" off
    echo "-- new tree, overlay on (empty folder)"; "$T/bench_new" "$T" empty
    echo "-- new tree, overlay on (1000 files in the hot directory)"; "$T/bench_new" "$T" full
    exit 0
  fi
  N=${OVERLAY_PATHS:-100000}
  for cp in plain cp1251; do
    a=; [ "$cp" = cp1251 ] && a=cp1251
    "$T/mp_old" "$T" "$N" unset $a > "$T/old.$cp.txt" 2> "$T/old.err"
    for v in unset 0 empty decoys; do
      "$T/mp_new" "$T" "$N" "$v" $a ov > "$T/new.$cp.$v.txt" 2> "$T/new.err" || { cat "$T/new.err"; echo "map_path_ov disagrees with map_path ($cp, overlay $v)" >&2; exit 1; }
      if cmp -s "$T/old.$cp.txt" "$T/new.$cp.$v.txt"; then echo "map_path, $N paths, name layer $cp, PORT_OVERLAY $v: identical to the old tree ($(grep -c ' 1 ' "$T/old.$cp.txt") of them exist): PASS"
      else diff "$T/old.$cp.txt" "$T/new.$cp.$v.txt" | head; echo "map_path differs from the old tree ($cp, overlay $v)" >&2; exit 1; fi
    done
  done;;
mutate) exec sh "$D/mutate_overlay.sh";;
*) echo 'usage: run_overlay.sh [native|tsan|savetx|wasm|node|all|diff BASE_DIR|bench BASE_DIR|mutate]' >&2; exit 2;;
esac
