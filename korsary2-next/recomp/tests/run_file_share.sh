#!/bin/sh
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/file-share.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
MODE=${1:-native}
case "$MODE" in
native) CC=${CC:-clang}; FLAGS='-fsanitize=address,undefined'; OUT="$T/test";
  case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac;;
wasm) SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -sWASMFS=1'; GC=-Wl,--gc-sections; OUT="$T/test.js";;
node) SDK="$P/third_party/emsdk"; export EM_CONFIG="$SDK/.emscripten" EM_CACHE="$P/recomp/web_toolchain/cache" EM_PORTS="$P/recomp/web_toolchain/ports" TMPDIR="$T" XDG_CACHE_HOME="$T/xdg" PYTHONDONTWRITEBYTECODE=1
  CC="$SDK/upstream/emscripten/emcc"; FLAGS='-pthread -DPORT_NODE_BUILD -sNODERAWFS=1'; GC=-Wl,--gc-sections; OUT="$T/test.js";;
*) echo 'usage: run_file_share.sh [native|wasm|node]' >&2; exit 2;;
esac
# The WasmFS build does not automatically inherit Node's environment. Copy
# the selected mode into Emscripten ENV before main, otherwise the purported
# strict run silently exercises the permissive branch a second time.
if [ "$MODE" = wasm ]; then
  cat > "$T/env.js" <<'EOF'
Module.preRun = Module.preRun || [];
Module.preRun.push(() => {
  if (process.env.PORT_STRICT_FILE_SHARE !== undefined)
    ENV.PORT_STRICT_FILE_SHARE = process.env.PORT_STRICT_FILE_SHARE;
});
EOF
  set -- --pre-js "$T/env.js"
else
  set --
fi
# shellcheck disable=SC2086
"$CC" -O1 -g -w $FLAGS -ffunction-sections -fdata-sections -I"$P/recomp/host" -I"$P/recomp/runtime" "$D/test_file_share.c" "$GC" -pthread "$@" -o "$OUT"
# The default permissive policy and the opt-in strict policy are both part of the contract.
case "$MODE" in
wasm|node)
  node "$OUT"
  PORT_STRICT_FILE_SHARE=1 node "$OUT";;
*)
  "$OUT"
  PORT_STRICT_FILE_SHARE=1 "$OUT";;
esac
