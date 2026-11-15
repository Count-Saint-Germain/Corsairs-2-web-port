#!/bin/sh
# Ghidra pass over one guest module DLL (same passes as analyze.sh, own project so it can run while
# the executable's analysis is still open):
#   re/analyze_module.sh MODULES/DX8RENDER.dll
# writes recomp/data/functions.<tag>.json — the name the translator's images.json manifest expects
# (tag from: node tools/configure.mjs --tag-for MODULES/DX8RENDER.dll). A module with no
# functions file is still translated from its exports and a code scan, so this is optional per module.
# Everything it writes is derived from the game: keep it out of anything you share.
set -e
P=$(cd "$(dirname "$0")/.." && pwd)
export JAVA_HOME="$P/third_party/jdk/Contents/Home"
[ $# -eq 1 ] || { echo "usage: re/analyze_module.sh MODULES/<Name>.dll   (path relative to game/)"; exit 1; }
MOD=$1
[ -f "$P/game/$MOD" ] || { echo "no such game/$MOD"; exit 1; }
TAG=$(node "$P/tools/configure.mjs" --tag-for "$MOD")
GHIDRA=$(ls -d "$P"/third_party/ghidra_*_PUBLIC 2>/dev/null | tail -1)
[ -n "$GHIDRA" ] || { echo "Ghidra is not in third_party/: run the skill's setup script first"; exit 1; }
mkdir -p "$P/re/ghidra_modules/$TAG" "$P/recomp/data"
"$GHIDRA/support/analyzeHeadless" "$P/re/ghidra_modules/$TAG" Port -import "$P/game/$MOD" -overwrite \
  -scriptPath "$P/re/scripts" \
  -postScript NameFromAsserts.java "$P/re/${TAG}_assert_names.csv" \
  -postScript RecoverRttiClasses.java "$P/re/${TAG}_rtti_classes.csv" \
  -postScript ExportFunctions.java "$P/recomp/data/functions.$TAG.json" > "$P/re/${TAG}_analysis.log" 2>&1 \
  || { tail -30 "$P/re/${TAG}_analysis.log"; exit 1; }
node -e 'const f=JSON.parse(require("node:fs").readFileSync(process.argv[1],"utf8")); console.log(`exported ${(Array.isArray(f)?f:f.functions).length} functions`);' "$P/recomp/data/functions.$TAG.json"
