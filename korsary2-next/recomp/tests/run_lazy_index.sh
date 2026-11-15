#!/bin/sh
# Experimental manifest namespace, checked against real folding in host/core.c.
# The temporary test files contain paths only; no saved data or game files change.
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
R=$(CDPATH= cd -- "$D/../../.." && pwd)
T=$(mktemp -d "${TMPDIR:-/tmp}/corsairs-lazy-index.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
clang -O1 -g -w -fsanitize=address,undefined -ffunction-sections -fdata-sections \
  -I"$D/../host" -I"$D/../runtime" "$D/test_lazy_index.c" "$GC" -pthread -o "$T/test"
node -e 'const fs=require("fs"); const m=JSON.parse(fs.readFileSync(process.argv[1],"utf8"));
  if (!Array.isArray(m.files) || m.files.some(x => typeof x.path !== "string" || /[\r\n]/.test(x.path))) process.exit(1);
  fs.writeFileSync(process.argv[2], m.files.map(x => x.path+"\n").join(""));' \
  "${LAZY_INDEX_MANIFEST:-$R/distribution/game/manifest.json}" "$T/paths"
"$T/test" "$T/paths"
