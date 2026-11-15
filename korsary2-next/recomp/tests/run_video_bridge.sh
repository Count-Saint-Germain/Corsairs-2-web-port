#!/bin/sh
# Видеомост (host/video.c): poll/done, точка открытия CAviPlayer, ожидание страницы — native без emcc;
# test_video_vm_layout.c исполняет РЕАЛЬНЫЕ переведённые функции (вырезаны из out_all/*.c в extracted.inc).
# Сборка под node проверяет только компиляцию (экспортов там нет по замыслу).
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/video-bridge.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "${1:-native}" in
native) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUT="$T/test";;
native-nodehook) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined -DPORT_NODE_BUILD'; OUT="$T/test";;   # хук вырезан, как в Node-сборке
node) SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -DPORT_NODE_BUILD'; OUT="$T/test.js";;
*) echo 'usage: run_video_bridge.sh [native|native-nodehook|node]' >&2; exit 2;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -I"$P/recomp/runtime" "$D/test_video_bridge.c" -pthread -o "$OUT"
case "${1:-native}" in node) node "$OUT";; *) "$OUT";; esac
# Реальный диспетчер call_indirect: хук активен в браузерной сборке и вырезан под PORT_NODE_BUILD.
DISP="$T/dispatch"; case "${1:-native}" in node) DISP="$T/dispatch.js";; esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w -std=gnu11 $FLAGS -I"$P/recomp/runtime" "$D/test_video_dispatch.c" "$P/recomp/runtime/runtime.c" -pthread -lm -o "$DISP"
case "${1:-native}" in node) node "$DISP";; *) "$DISP";; esac
# Раскладка/путь на переведённом коде: функции вырезаются из out_all дословно (границы: строка 'void f_X(CPU *c)' ... '^}').
extract() { awk -v f="$2" '$0 ~ "^void " f "\\(CPU \\*c\\)" {on=1} on {print} on && /^}/ {exit}' "$P/recomp/out_all/$1"; }
{ extract recomp_004.c f_004473cf; extract MODULES_XINTERFACE_004.c f_00ae7700; extract MODULES_XINTERFACE_004.c f_00ae77d0
  extract MODULES_XINTERFACE_000.c f_00ab1578; } > "$T/extracted.inc"
[ "$(grep -c '^void f_' "$T/extracted.inc")" = 4 ] || { echo 'extract failed: out_all changed?' >&2; exit 1; }
LAY="$T/layout"; case "${1:-native}" in node) LAY="$T/layout.js";; esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w -std=gnu11 $FLAGS -I"$T" -I"$P/recomp/runtime" "$D/test_video_vm_layout.c" "$P/recomp/runtime/runtime.c" -pthread -lm -o "$LAY"
case "${1:-native}" in node) node "$LAY";; *) "$LAY";; esac
