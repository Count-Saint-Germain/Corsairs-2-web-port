#!/bin/sh
# Runs the differential tester in N parallel shards and merges the results.
# Usage: recomp/tests/run_difftest.sh [N] [extra difftest.mjs args...]
set -eu
P=$(cd "$(dirname "$0")/../.." && pwd)
EXE=$(node "$P/tools/configure.mjs" --print-exe)
N=${1:-8}
if [ "$#" -gt 0 ]; then shift; fi
case "$N" in *[!0-9]*|'') echo "Invalid shard count: $N" >&2; exit 2;; esac
[ "$N" -gt 0 ] || { echo "Shard count must be positive" >&2; exit 2; }
OUT=${DIFFTEST_OUT:-"$P/recomp/tests/results"}
mkdir -p "$OUT"
rm -f "$OUT"/shard_*.json "$OUT"/shard_*.log
pids=""
for k in $(seq 0 $((N - 1))); do
  node "$P/recomp/tests/difftest.mjs" "$P/game/$EXE" "$P/recomp/data/functions.json" \
    "$P/recomp/build/libportrecomp.dylib" --shard "$k/$N" --report "$OUT/shard_$k.json" "$@" > "$OUT/shard_$k.log" 2>&1 &
  pids="$pids $!"
done
failed=0
for pid in $pids; do wait "$pid" || failed=1; done
[ "$failed" -eq 0 ] || { echo "A differential test shard failed; check $OUT/shard_*.log" >&2; exit 1; }
node "$P/recomp/tests/difftest_reports.mjs" merge "$OUT" "$N"
