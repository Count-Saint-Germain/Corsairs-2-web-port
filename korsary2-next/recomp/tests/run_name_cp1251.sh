#!/bin/sh
# Слой имён CP1251 <-> UTF-8 (PORT_NAME_CP1251): обработчики kernel32.c над синтетическими временными каталогами.
# Это не проверка запущенной игры.
#   run_name_cp1251.sh [native|tsan|savetx|wasm|node|all]  [SCRATCH_DIR]            (default: native)
#   native  clang ASan/UBSan, режимы share: permissive и strict
#   tsan    clang ThreadSanitizer: потоки (8 x 40 кругов) в strict и в permissive (таблица дескрипторов защищена, docs/handle-table-race.md)
#   savetx  ASan/UBSan с -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1: sidecar SAVE_META, журнал SAVE_TX, страничный
#           save-tx.mjs восстанавливает слот с кириллическим именем (test_name_cp1251_savetx.mjs)
#   wasm    emcc WasmFS (память, регистрозависимо, принимает не-UTF-8 имена), под Node; нужен lock emcc
#   node    emcc NODERAWFS под Node; нужен lock emcc
#   all     native tsan savetx (без emcc)
# SCRATCH_DIR (native/tsan/savetx): где создавать временные каталоги; чтобы пройти регистрозависимую ветку на macOS,
# укажите каталог тома «Case-sensitive APFS» (hdiutil create -size 40m -fs "Case-sensitive APFS" ...).
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/name-cp1251.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
MODE=${1:-native}
SC=${2:-$T}
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
SRC="$D/test_name_cp1251.c"
build() {   # build FLAGS OUT
  # shellcheck disable=SC2086
  clang -O1 -g -w $1 -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$SRC" "$GC" -pthread -o "$2"
}
case "$MODE" in
native) build '-fsanitize=address,undefined' "$T/t"; for m in permissive strict; do "$T/t" "$SC" "$m"; done;;
tsan) build '-fsanitize=thread' "$T/t"
  # permissive: its handle table had unlocked accesses until docs/handle-table-race.md (TSan reported them as soon as two guest
  # threads opened and closed files, so the threads part used to run in strict only); both modes run the threads part now
  for m in strict permissive; do "$T/t" "$SC" "$m"; done;;
savetx)
  build '-fsanitize=address,undefined -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1' "$T/t"
  for m in permissive strict; do "$T/t" "$SC" "$m"; done
  NAME_TX_BIN="$T/t" NAME_TX_TMP="$T/tx" node "$D/test_name_cp1251_savetx.mjs";;
all) sh "$0" native "$SC"; sh "$0" tsan "$SC"; sh "$0" savetx "$SC";;
wasm|node)
  SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  # main runs in a worker so that pthread_cond_wait/join do not block Node's event loop
  FLAGS='-pthread -sPROXY_TO_PTHREAD=1 -sPTHREAD_POOL_SIZE=14 -sEXIT_RUNTIME=1 -sENVIRONMENT=node -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB'
  if [ "$MODE" = wasm ]; then FLAGS="$FLAGS -sWASMFS=1"; WSC=/tmp; else FLAGS="$FLAGS -DPORT_NODE_BUILD -sNODERAWFS=1"; WSC="$T"; fi
  # shellcheck disable=SC2086
  "$SDK/upstream/emscripten/emcc" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$SRC" -Wl,--gc-sections -pthread -o "$T/t.js"
  for m in permissive strict; do node "$T/t.js" "$WSC" "$m"; done;;
*) echo 'usage: run_name_cp1251.sh [native|tsan|savetx|wasm|node|all] [SCRATCH_DIR]' >&2; exit 2;;
esac
