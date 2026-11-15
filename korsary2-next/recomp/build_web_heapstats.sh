#!/bin/sh
# K3: диагностическая сборка с -DPORT_HEAP_STATS в ОТДЕЛЬНЫЙ каталог (штатный build_web/ не затрагивается).
#   recomp/build_web_heapstats.sh <OUT_DIR> [node|www|all]     (по умолчанию node)
# Результат: <OUT_DIR>/node/game.js (headless, Node) и/или <OUT_DIR>/www/game.js (браузер).
# Флаг влияет только на host/core.c, dsound.c, d3d8.c, com.c, поэтому сгенерированные объекты (out_all/*.c) не
# перекомпилируются: берутся из build_web/obj (клон APFS), если их хэш (как в build_web.sh) совпадает, иначе
# собираются в <OUT_DIR>/obj. Конфигурация (host/port_config.h) не обновляется — перед сборкой при необходимости
# выполните `node tools/configure.mjs`. emcc запускать только под глобальным локом сборок.
set -eu
R=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(dirname "$R")
[ $# -ge 1 ] || { echo "usage: $0 <OUT_DIR> [node|www|all]" >&2; exit 2; }
mkdir -p "$1"
B=$(CDPATH= cd -- "$1" && pwd)
what=${2:-node}
[ "$B" != "$R/build_web" ] || { echo "OUT_DIR must not be the regular build_web" >&2; exit 2; }
case "$B" in "$R/build_web"/*) echo "OUT_DIR must not be inside the regular build_web" >&2; exit 2 ;; esac

# Тот же набор переменных, что и build_web_local.sh (SDK только для чтения, кэш и порты рядом).
SDK="$P/third_party/emsdk"
export EM_CONFIG="$SDK/.emscripten"
export EM_CACHE="$R/web_toolchain/cache"
export EM_PORTS="$R/web_toolchain/ports"
export TMPDIR="$R/web_toolchain/tmp"
export XDG_CACHE_HOME="$R/web_toolchain/xdg-cache"
export PYTHONDONTWRITEBYTECODE=1
export PATH="$SDK/upstream/emscripten:$SDK/upstream/bin:$PATH"
unset EMCC_LOCAL_PORTS EM_COMPILER_WRAPPER
mkdir -p "$TMPDIR" "$XDG_CACHE_HOME"
[ -f "$EM_PORTS/emdawnwebgpu/emdawnwebgpu_pkg/emdawnwebgpu.port.py" ] || { echo "missing emdawnwebgpu port (tools/stage_emdawn.mjs)" >&2; exit 1; }
emcc --version >/dev/null

OPT=${OPT:--O1}
BASE="$OPT -pthread -frounding-math -w "        # ровно как CFLAGS в build_web.sh без EXTRA_CFLAGS (для хэшей объектов)
CFLAGS="$OPT -pthread -frounding-math -w -DPORT_HEAP_STATS ${EXTRA_CFLAGS:-}"
OUT=out_all
cd "$R"
[ -d "$OUT" ] || { echo "run build.sh first (it generates $OUT/)"; exit 1; }
node "$R/translator/fix_root_aref.mjs" --manifest "$R/data/images.json" --out "$R/$OUT"
mkdir -p "$B/obj" "$B/host" "$B/node" "$B/www"

# сгенерированные объекты: клон штатного, если актуален; иначе сборка без флага диагностики
for f in $OUT/*.c; do
    b=$(basename "$f" .c)
    h=$( (cat "$f"; echo "$BASE") | shasum | cut -c1-40)
    if [ -f "$B/obj/$b.o" ] && [ "$(cat "$B/obj/$b.hash" 2>/dev/null)" = "$h" ]; then continue; fi
    if [ -f "build_web/obj/$b.o" ] && [ "$(cat "build_web/obj/$b.hash" 2>/dev/null)" = "$h" ]; then
        cp -c "build_web/obj/$b.o" "$B/obj/$b.o" 2>/dev/null || cp "build_web/obj/$b.o" "$B/obj/$b.o"
        echo "$h" > "$B/obj/$b.hash"; continue
    fi
    echo "$f $b $h"
done | xargs -P 10 -L 1 sh -c 'emcc '"$BASE"' -Iruntime -I'"$OUT"' "$0" -c -o "'"$B"'/obj/$1.o" && echo "$2" > "'"$B"'/obj/$1.hash" && echo "  compiled $1"'
for o in "$B"/obj/*.o; do [ -f "$OUT/$(basename "$o" .o).c" ] || rm -f "$o" "${o%.o}.hash"; done

# runtime и слой Windows — всегда заново, с флагом (host-объекты зависят от PORT_HEAP_STATS)
rm -f "$B/.fail"
cc() { emcc "$@" || touch "$B/.fail"; }
cc $CFLAGS -Iruntime -c runtime/runtime.c -o "$B/runtime.o" &
cc $CFLAGS -Iruntime -c runtime/interp.c -o "$B/interp.o" &
for f in host/*.c; do
    case "$(basename "$f")" in window.c|watch.c) continue ;; esac
    cc $CFLAGS --use-port=emdawnwebgpu -Iruntime -Ihost -c "$f" -o "$B/host/$(basename "$f" .c).o" &
    while [ "$(jobs -r | wc -l)" -ge 8 ]; do sleep 0.2; done
done
cc $CFLAGS -DPORT_NODE_BUILD -Iruntime -Ihost -c host/main.c -o "$B/main_node.o" &
cc $CFLAGS -DPORT_NODE_BUILD -Iruntime -Ihost -c host/kernel32.c -o "$B/kernel32_node.o" &
cc $CFLAGS -DPORT_NODE_BUILD -Iruntime -c runtime/runtime.c -o "$B/runtime_node.o" &
cc $CFLAGS -c web/node_stubs.c -o "$B/node_stubs.o" &
wait
[ ! -e "$B/.fail" ] || { echo "compilation failed (see messages above)" >&2; rm -f "$B/.fail"; exit 1; }
echo "objects done"

if [ "$what" = node ] || [ "$what" = all ]; then
    set --
    for o in "$B"/host/*.o; do
        case "$(basename "$o")" in main.o|render_wgpu.o|kernel32.o|video.o) continue ;; esac
        set -- "$@" "$o"
    done
    emcc -pthread ${LINKOPT:-$OPT} --profiling-funcs -o "$B/node/game.js" "$B"/runtime_node.o "$B"/interp.o "$B"/main_node.o "$B/kernel32_node.o" "$@" "$B/node_stubs.o" "$B"/obj/*.o \
        -sPROXY_TO_PTHREAD -sPTHREAD_POOL_SIZE=12 -sALLOW_MEMORY_GROWTH -sINITIAL_MEMORY=33554432 -sMAXIMUM_MEMORY=4GB \
        -sSTACK_SIZE=8MB -sDEFAULT_PTHREAD_STACK_SIZE=32MB -sENVIRONMENT=node -sNODERAWFS=1 -sEXIT_RUNTIME=1 \
        --pre-js web/node_env.js ${EXTRA_LINK:-}
    perl -0pi -e 's/("?name"?:\s*"em-pthread")/$1, resourceLimits: { stackSizeMb: 256 }/' "$B/node/game.js"
    echo "built $B/node/game.js"
fi
if [ "$what" = www ] || [ "$what" = all ]; then
    emcc -pthread ${LINKOPT:-$OPT} --profiling-funcs -o "$B/www/game.js" "$B"/runtime.o "$B"/interp.o "$B"/host/*.o "$B"/obj/*.o \
        --use-port=emdawnwebgpu -sWASMFS -sPROXY_TO_PTHREAD -sPTHREAD_POOL_SIZE=16 -sALLOW_MEMORY_GROWTH \
        -sINITIAL_MEMORY=33554432 -sMAXIMUM_MEMORY=4GB -sSTACK_SIZE=8MB -sDEFAULT_PTHREAD_STACK_SIZE=32MB -sENVIRONMENT=web,worker \
        -sMODULARIZE -sEXPORT_NAME=createPort -sEXPORTED_RUNTIME_METHODS=ENV,wasmMemory -sEXIT_RUNTIME=0 ${EXTRA_LINK:-}
    # та же правка setBindGroup для Firefox, что и в build_web.sh
    perl -0pi -e 's/\(growMemViews\(\), HEAPU32\), \(\(dynamicOffsetsPtr\) >>> 2\), dynamicOffsetCount\)/(growMemViews(), HEAPU32.slice(dynamicOffsetsPtr >>> 2, (dynamicOffsetsPtr >>> 2) + dynamicOffsetCount)))/g' "$B/www/game.js"
    grep -q 'HEAPU32.slice(dynamicOffsetsPtr' "$B/www/game.js" || echo "warning: setBindGroup offsets patch did not apply" >&2
    echo "built $B/www/game.js (serve with: node recomp/web/serve.mjs ... ; страница берёт www из build_web — см. docs/heap-measurement-k3.md)"
fi
