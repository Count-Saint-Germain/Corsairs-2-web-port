#!/bin/sh
# Re-runs the functions that failed in the merged report.
set -eu
P=$(cd "$(dirname "$0")/../.." && pwd)
EXE=$(node "$P/tools/configure.mjs" --print-exe)
OUT=${DIFFTEST_OUT:-"$P/recomp/tests/results"}
TEMP=$(mktemp -d "${TMPDIR:-/tmp}/k2-retest.XXXXXXXX")
trap 'rm -rf "$TEMP"' EXIT HUP INT TERM
node "$P/recomp/tests/difftest_reports.mjs" failures "$OUT/merged.json" > "$TEMP/addresses"
while IFS= read -r e; do
  node "$P/recomp/tests/difftest.mjs" "$P/game/$EXE" "$P/recomp/data/functions.json" \
    "$P/recomp/build/libportrecomp.dylib" --only "$e" --trials 3 --allow-calls --report "$TEMP/report.json" > /dev/null
  node "$P/recomp/tests/difftest_reports.mjs" print "$TEMP/report.json"
done < "$TEMP/addresses"
