#!/bin/sh
# E1: мутации страничной части (web/overlay.mjs, web/port.js). Копия web/ и нужных тестов собирается во временный корень, одна замена за раз,
# затем запускаются тесты: страничная логика (Node) и сценарии настоящего port.js в Chromium; каждая мутация ОБЯЗАНА уронить хотя бы один.
#   mutate_overlay_page.sh
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)            # korsary2-next
W=$(CDPATH= cd -- "$P/.." && pwd)               # web-port
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/overlay-page-mut.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
caught=0; missed=0
# mutate NAME FILE 'OLD' 'NEW' 'node|browser' [ONLY scenarios]
mutate() {
  name=$1; file=$2; old=$3; new=$4; kind=$5; only=${6:-}
  if [ -n "${MUTATION_KIND:-}" ] && [ "$kind" != "$MUTATION_KIND" ]; then return; fi
  rm -rf "$T/m"; mkdir -p "$T/m/korsary2-next/recomp"
  cp -R "$P/recomp/web" "$T/m/korsary2-next/recomp/web"
  mkdir -p "$T/m/korsary2-next/recomp/tests"
  for f in test_overlay_page.mjs test_overlay_browser.mjs overlay_fixture.mjs; do cp "$D/$f" "$T/m/korsary2-next/recomp/tests/"; done
  cp "$D"/verify_dist*.mjs "$T/m/korsary2-next/recomp/tests/"
  cp "$P/port.json" "$T/m/korsary2-next/port.json"
  ln -s "$W/third_party" "$T/m/third_party"
  OLD=$old NEW=$new FILE="$T/m/korsary2-next/recomp/web/$file" node -e '
    const fs = require("node:fs");
    const { FILE, OLD, NEW } = process.env;
    const source = fs.readFileSync(FILE, "utf8"), count = source.split(OLD).length - 1;
    if (count !== 1) throw new Error(`mutation anchor found ${count} times: ${OLD.slice(0, 60)}`);
    fs.writeFileSync(FILE, source.replace(OLD, () => NEW));
  '
  cd "$T/m/korsary2-next/recomp/tests"
  if [ "$kind" = node ]; then
    if node test_overlay_page.mjs > "$T/out" 2>&1; then echo "MISSED  $name"; missed=$((missed + 1)); else echo "caught  $name  ($(grep -m1 -E 'AssertionError|Error' "$T/out" | cut -c1-150))"; caught=$((caught + 1)); fi
  else
    if OVERLAY_ONLY=$only node test_overlay_browser.mjs > "$T/out" 2>&1; then echo "MISSED  $name"; missed=$((missed + 1)); else echo "caught  $name  ($(grep -m1 -E 'AssertionError|Error' "$T/out" | cut -c1-150))"; caught=$((caught + 1)); fi
  fi
  cd "$D"
}
# --- страничная логика
mutate stricter-paths-off overlay.mjs "if (FORBIDDEN_TOP.has(top))" "if (false)" node
mutate sha-not-required overlay.mjs "if (typeof f.sha256 !== 'string' || !HEX64.test(f.sha256)) fail(" "if (false) fail(" node
mutate install-without-lock overlay.mjs "return withSaveLock(locks, rootName, async () => {" "return (async (fn) => fn())(async () => {" node
mutate url-weaker-than-storage overlay.mjs "if (fromUrl) { out.lang = fromUrl; out.source = 'url'; }
  else if (out.stored)" "if (!out.stored && fromUrl) { out.lang = fromUrl; out.source = 'url'; }
  else if (out.stored)" node
mutate base-compat-skipped overlay.mjs "if (baseManifest && Array.isArray(baseManifest.files) && Object.keys(base).length) {" "if (false) {" node
mutate required-skipped overlay.mjs "for (const r of required) if (!have.has(r.toLowerCase()))" "for (const r of []) if (!have.has(r.toLowerCase()))" node
mutate case-dups-allowed overlay.mjs "if (seen.has(low)) fail(" "if (false) fail(" node
# --- страница в Chromium
mutate overlay-env-always port.js "if (english) m.ENV.PORT_OVERLAY = langState.hostPath;" "m.ENV.PORT_OVERLAY = langState.hostPath;" browser A
mutate overlay-marker-is-base-marker port.js "const OVERLAY_MARKER = 'installed-en.json';" "const OVERLAY_MARKER = 'installed.json';" browser B
mutate raw-sha-not-checked port.js "if (ctx?.verifySha && entry?.sha256) {" "if (false) {" browser E
mutate play-not-blocked port.js "const blocked = en && langState.overlay !== 'ready';" "const blocked = false;" browser D
mutate overlay-in-base-dir port.js "const OVERLAY_DIR = OPFS_DIR + '-en';" "const OVERLAY_DIR = OPFS_DIR;" browser B
mutate overlay-quota-skipped port.js "if (space.status === 'insufficient') throw new Error(space.message);" "if (false) throw new Error(space.message);" browser F
echo "page mutations: $caught caught, $missed missed"
[ "$missed" -eq 0 ]
