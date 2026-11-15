#!/bin/bash
# Собирает k2br.wasm из vendor/brotli (официальный декодер brotli 1.2.1 + k2br.c) БЕЗ emcc: clang и wasm-ld из emsdk
# репозитория, sysroot — только за заголовками (libc не линкуется). Пути с пробелами допустимы.
#   bash web/vendor/brotli/build.sh [OUT.wasm]     # по умолчанию web/vendor/brotli/k2br.wasm и k2br.wasm.sha256
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../../../.." && pwd)          # korsary2-next
SDK="$P/third_party/emsdk/upstream"
SYSROOT="$SDK/emscripten/cache/sysroot"
OUT=${1:-$D/k2br.wasm}
T=$(mktemp -d "${TMPDIR:-/tmp}/k2br.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
CFLAGS=(-O2 -ffreestanding -fno-builtin-memcpy -fno-builtin-memmove -fno-builtin-memset -fno-builtin-memcmp
  --target=wasm32 -mbulk-memory -mno-simd128 -DNDEBUG -DBROTLI_STATIC_INIT=0 -w
  -I"$D/c/include" -isystem "$SYSROOT/include" -isystem "$SYSROOT/include/compat")
OBJS=()
for f in c/dec/bit_reader c/dec/decode c/dec/huffman c/dec/prefix c/dec/state c/dec/static_init \
         c/common/constants c/common/context c/common/dictionary c/common/platform c/common/shared_dictionary c/common/transform k2br; do
  "$SDK/bin/clang" "${CFLAGS[@]}" -c "$D/$f.c" -o "$T/$(basename "$f").o"
  OBJS+=("$T/$(basename "$f").o")
done
"$SDK/bin/wasm-ld" --no-entry --gc-sections --strip-all -z stack-size=262144 --initial-memory=1048576 --max-memory=134217728 \
  --export=k2br_open --export=k2br_close --export=k2br_in_ptr --export=k2br_out_ptr --export=k2br_feed --export=k2br_run \
  --export=k2br_produced --export=k2br_avail_in --export=k2br_error --export=k2br_heap_used --export=k2br_version \
  "${OBJS[@]}" -o "$T/raw.wasm"
"$SDK/bin/wasm-opt" -O3 --enable-bulk-memory --enable-sign-ext --enable-mutable-globals --strip-debug --strip-producers "$T/raw.wasm" -o "$OUT"
( cd "$(dirname "$OUT")" && shasum -a 256 "$(basename "$OUT")" | cut -d' ' -f1 > "$(basename "$OUT").sha256" )
ls -l "$OUT"; cat "$OUT.sha256"
