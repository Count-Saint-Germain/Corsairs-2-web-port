#!/bin/sh
# Builds if needed and starts a local server; open its URL in Codex's built-in browser.
#   ./play.sh            (Ctrl-C to stop)
# The server only listens on this computer and does not open a browser itself.
set -e
P=$(cd "$(dirname "$0")" && pwd)
cd "$P"
if [ ! -f recomp/build_web/www/game.wasm ]; then
  [ -d recomp/out_all ] || sh recomp/build.sh
  sh recomp/build_web_local.sh
fi
node tools/configure.mjs
PORT=${PORT:-8007}
printf 'Open in the Codex built-in browser: http://localhost:%s/\n' "$PORT"
printf 'Optional simplified sea: http://localhost:%s/?sea_fallback=1\n' "$PORT"
exec node recomp/web/serve.mjs --port "$PORT" --game game
