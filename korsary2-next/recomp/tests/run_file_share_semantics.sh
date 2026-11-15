#!/bin/sh
# Ф3.2 file semantics of the opt-in strict share mode (aliases, delete-pending, exhaustion, closing,
# directories, CopyFileA, concurrency) on the real kernel32.c handlers. Synthetic temp dirs only; this
# is not a check of the running game.
#   run_file_share_semantics.sh [native|tsan|savetx|wasm|node|diff BASE_DIR]     (default: native)
#   native  clang ASan/UBSan, permissive (env unset, "0", "") and strict runs
#   tsan    clang ThreadSanitizer, strict run (the concurrency part is the target)
#   savetx  native ASan/UBSan with -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1: pending delete of a SAVE slot
#   wasm    emcc WasmFS (in-memory /tmp, NOT browser OPFS) under Node; needs the emcc lock
#   node    emcc NODERAWFS under Node; needs the emcc lock
#   diff    default-mode equivalence against an older copy of recomp/host (BASE_DIR/host): both builds run
#           the same scripted permissive scenario and the traces must be identical
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/file-share-sem.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
MODE=${1:-native}
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
SRC="$D/test_file_share_semantics.c"
case "$MODE" in
native) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUT="$T/test"; SCRATCH="$T";;
tsan) CC=${CC:-clang}; FLAGS='-fsanitize=thread'; OUT="$T/test"; SCRATCH="$T";;
savetx) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1'; OUT="$T/test"; SCRATCH="$T";;
wasm|node)
  SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; OUT="$T/test.js"; GC=-Wl,--gc-sections
  # main runs in a worker so that pthread_cond_wait/join do not block Node's event loop
  FLAGS='-pthread -sPROXY_TO_PTHREAD=1 -sPTHREAD_POOL_SIZE=14 -sEXIT_RUNTIME=1 -sENVIRONMENT=node -sSTACK_SIZE=2MB -sDEFAULT_PTHREAD_STACK_SIZE=1MB -sINITIAL_MEMORY=128MB'
  if [ "$MODE" = wasm ]; then FLAGS="$FLAGS -sWASMFS=1"; SCRATCH=/tmp; else FLAGS="$FLAGS -DPORT_NODE_BUILD -sNODERAWFS=1"; SCRATCH="$T"; fi;;
diff) BASE=${2:?usage: run_file_share_semantics.sh diff BASE_DIR}
  [ -f "$BASE/host/kernel32.c" ] || { echo "no $BASE/host/kernel32.c" >&2; exit 2; }
  CC=${CC:-clang}
  # The scenario source lives in tests/; the base build gets the same file next to the base host/ copy.
  mkdir -p "$T/basetree/tests" "$T/newtree"
  ln -s "$BASE/host" "$T/basetree/host"
  cp "$D/test_file_share_default_trace.c" "$T/basetree/tests/"
  "$CC" -O1 -g -w -fsanitize=address,undefined -ffunction-sections -fdata-sections -I"$BASE/host" -I"$P/recomp/runtime" "$T/basetree/tests/test_file_share_default_trace.c" "$GC" -pthread -o "$T/trace_base"
  "$CC" -O1 -g -w -fsanitize=address,undefined -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_file_share_default_trace.c" "$GC" -pthread -o "$T/trace_new"
  # Unset env: the new tree must reproduce the old tree byte for byte. Env "0" and "" used to switch the
  # old tree to strict mode (any set value did); they are now permissive by design, so they are compared
  # with the new unset trace instead.
  "$T/trace_base" "$T" unset > "$T/base.unset.txt"
  "$T/trace_new" "$T" unset > "$T/new.unset.txt"
  if cmp -s "$T/base.unset.txt" "$T/new.unset.txt"; then echo "default-mode trace identical to the old tree (env unset): $(wc -l < "$T/new.unset.txt") lines: PASS"
  else diff "$T/base.unset.txt" "$T/new.unset.txt" | head -20; echo "default-mode trace DIFFERS from the old tree" >&2; exit 1; fi
  for v in 0 empty; do
    "$T/trace_new" "$T" "$v" > "$T/new.$v.txt"
    if cmp -s "$T/new.unset.txt" "$T/new.$v.txt"; then echo "env $v behaves as unset (permissive): PASS"
    else diff "$T/new.unset.txt" "$T/new.$v.txt" | head; echo "env $v is not permissive" >&2; exit 1; fi
  done
  # PORT_OVERLAY (E1, language overlay): unset, "0" and "" are off, and an overlay that never applies (an empty folder; a folder
  # whose files sit only where the overlay is not looked at: top level, SAVE, options, engine.ini) changes nothing either.
  # Compared with the OLD tree's trace (the old host does not know the variable and ignores it).
  for snap in nosnap snap; do
    for v in unset 0 empty emptydir decoys; do
      "$T/trace_new" "$T" unset unset "$snap" "$v" > "$T/new.ov.$snap.$v.txt"
      "$T/trace_base" "$T" unset unset "$snap" "$v" > "$T/base.ov.$snap.$v.txt"
      if cmp -s "$T/base.ov.$snap.$v.txt" "$T/new.ov.$snap.$v.txt"; then echo "PORT_OVERLAY $v ($snap): trace identical to the old tree: $(wc -l < "$T/new.ov.$snap.$v.txt") lines: PASS"
      else diff "$T/base.ov.$snap.$v.txt" "$T/new.ov.$snap.$v.txt" | head -20; echo "PORT_OVERLAY $v ($snap) changes the trace" >&2; exit 1; fi
    done
  done
  # PORT_NAME_CP1251 (CP1251 <-> UTF-8 layer for names): unset, "0" and "" are the unchanged default
  # Snapshots on (the browser default): read-only opens take a one-shot buffer; same equivalence
  "$T/trace_base" "$T" unset unset snap > "$T/base.snap.txt"
  "$T/trace_new" "$T" unset unset snap > "$T/new.snap.txt"
  if cmp -s "$T/base.snap.txt" "$T/new.snap.txt"; then echo "default-mode trace with snapshots on identical to the old tree: $(wc -l < "$T/new.snap.txt") lines: PASS"
  else diff "$T/base.snap.txt" "$T/new.snap.txt" | head -20; echo "snapshot trace DIFFERS from the old tree" >&2; exit 1; fi
  for v in 0 empty; do
    "$T/trace_new" "$T" unset "$v" > "$T/new.name.$v.txt"
    if cmp -s "$T/new.unset.txt" "$T/new.name.$v.txt"; then echo "PORT_NAME_CP1251 $v behaves as unset: PASS"
    else diff "$T/new.unset.txt" "$T/new.name.$v.txt" | head; echo "PORT_NAME_CP1251 $v is not the default" >&2; exit 1; fi
  done
  exit 0;;
*) echo 'usage: run_file_share_semantics.sh [native|tsan|savetx|wasm|node|diff BASE_DIR]' >&2; exit 2;;
esac
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$SRC" "$GC" -pthread -o "$OUT"
run() {
  case "$MODE" in wasm|node) node "$OUT" "$SCRATCH" "$1";; *) "$OUT" "$SCRATCH" "$1";; esac
}
case "$MODE" in
tsan) run 1;;
savetx) run 1;;
*) for m in unset 0 empty 1 yes; do echo "-- PORT_STRICT_FILE_SHARE mode: $m"; run "$m"; done;;
esac
