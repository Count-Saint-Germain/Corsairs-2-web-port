#!/bin/sh
# E1: мутации хоста-оверлея. Для каждой мутации копия recomp/host правится ОДНОЙ заменой, test_overlay.c собирается против копии
# и ОБЯЗАН упасть (иначе тесты не ловят эту ошибку). Живое дерево не трогается.
#   mutate_overlay.sh            все мутации; код возврата 0 только если каждая поймана
set -eu
D=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
P=$(CDPATH= cd -- "$D/../.." && pwd)
mkdir -p "$P/recomp/web_toolchain/tmp"
T=$(mktemp -d "$P/recomp/web_toolchain/tmp/overlay-mut.XXXXXXXX")
trap 'rm -rf "$T"' EXIT HUP INT TERM
case "$(uname -s)" in Darwin) GC=-Wl,-dead_strip;; *) GC=-Wl,--gc-sections;; esac
caught=0; missed=0
# mutate NAME FILE 'OLD' 'NEW' [tsan]
mutate() {
  name=$1; file=$2; old=$3; new=$4; san=${5:-asan}
  rm -rf "$T/m"; mkdir -p "$T/m/tests"
  cp -R "$P/recomp/host" "$T/m/host"
  cp "$D/test_overlay.c" "$T/m/tests/"
  OLD=$old NEW=$new OLD2=${OLD2:-} NEW2=${NEW2:-} FILE="$T/m/host/$file" node <<'EOF'
const fs = require('node:fs');
const p = process.env.FILE;
let s = fs.readFileSync(p, 'utf8');
for (const [old, replacement] of [[process.env.OLD, process.env.NEW], [process.env.OLD2, process.env.NEW2]]) {
  if (!old) continue;
  const count = s.split(old).length - 1;
  if (count !== 1) throw new Error('mutation anchor found ' + count + ' times: ' + JSON.stringify(old.slice(0, 60)));
  s = s.replace(old, replacement);
}
fs.writeFileSync(p, s);
EOF
  if [ "$san" = tsan ]; then FL='-fsanitize=thread'; else FL='-fsanitize=address,undefined'; fi
  # shellcheck disable=SC2086
  if ! clang -O1 -g -w $FL -ffunction-sections -fdata-sections -I"$T/m/host" -I"$P/recomp/runtime" "$T/m/tests/test_overlay.c" "$GC" -pthread -o "$T/m/t" 2> "$T/m/build.err"; then
    echo "MUTANT DOES NOT BUILD: $name"; cat "$T/m/build.err" | head -5; missed=$((missed + 1)); return
  fi
  last=
  for m in permissive strict; do
    if ! out=$("$T/m/t" "$T/m" "$m" nosnap 2>&1); then
      last=$(printf '%s\n' "$out" | grep -E 'FAIL|Sanitizer|runtime error|Assertion' | head -1)
      [ -n "$last" ] || last=$(printf '%s\n' "$out" | grep -v '^\[overlay\]' | tail -1)
      break
    fi
  done
  if [ -n "$last" ]; then echo "caught  $name  ($m: $last)" | cut -c1-230; caught=$((caught + 1))
  else echo "MISSED  $name"; missed=$((missed + 1)); fi
}
# 1  the overlay's SAVE/options/engine.ini are visible (top-level filter of the index off)
mutate top-level-filter core.c 'if (d == g_ov_root && !ov_top_allowed(e->d_name)) { g_ov_skipped++; continue; }' '/* mutated: no filter */'
# 2  symlinks of the overlay are indexed and followed
mutate symlinks-followed core.c 'if (e->d_type != DT_UNKNOWN) return 0;' 'if (e->d_type != DT_UNKNOWN) return 1;'
# 3  a write open of an overlay path is not refused (it would write into the overlay file)
mutate write-open-allowed kernel32.c 'if (ov.kind && ((access & 0x40000000u) || disp == 2 || disp == 5)) {' 'if (0 && ov.kind && ((access & 0x40000000u) || disp == 2 || disp == 5)) {'
# 4  DeleteFileA of an overlay path is not refused
mutate delete-allowed kernel32.c 'if (ov_refuses_write(&ov, "DeleteFileA", GSTR(ARG(0)))) {' 'if (0 && ov_refuses_write(&ov, "DeleteFileA", GSTR(ARG(0)))) {'
# 5  ".." does not step back in the overlay index (the two walks drift apart)
mutate dotdot-drift core.c 'if (ocur) { if (omiss) omiss--; else if (ocur->parent) ocur = ocur->parent; }' 'if (ocur) { if (omiss) omiss--; }'
# 6  the canonical host path keeps the guest's spelling for overlay-only components (strict identity breaks on case variants)
mutate canonical-spelling core.c 'snprintf(out + L, sizeof out - L, "/%s", ochild ? ochild->name : comp);' 'snprintf(out + L, sizeof out - L, "/%s", comp);'
# 7  the union listing shows names twice
mutate union-duplicates kernel32.c 'if (find_seen_has(fs, key)) continue;' '/* mutated */'
# 8  GetFileAttributesA ignores the overlay
mutate attrs-ignore-overlay kernel32.c 'if (ov.kind) return ov.kind == 2 ? 0x10 : 0x20;   /* the overlay'"'"'s entry shadows the base'"'"'s */' '/* mutated */'
# 9  a read open takes the base path even when the overlay holds the file
mutate base-wins kernel32.c 'open_path = ov.host;' 'open_path = host;'
# 10 the overlay root may lie inside the game folder
mutate root-nesting core.c '} else if (ov_inside(real, g_game_root) || ov_inside(g_game_root, real)) {' '} else if (0) {'
# 11 a directory only in the overlay is not listed
mutate union-dir-missing kernel32.c 'if (ov.kind == 2) { fs->ovdir = ov.node;' 'if (0 && ov.kind == 2) { fs->ovdir = ov.node;'
# 12 "0" does not switch the overlay off
mutate env-zero-is-a-path core.c 'if (e && *e && strcmp(e, "0") != 0) {' 'if (e && *e) {'
# 13 paths outside the game folder are overlaid too
mutate outside-game-overlaid core.c 'base = g_user_root;  /* anything outside the game folder: profiles, temp files, ... */' 'base = g_user_root; if (ovh) ocur = g_ov_root;'
# 14 CopyFileA may write into an overlay path
mutate copy-destination-allowed kernel32.c 'if (ov_refuses_write(&odst, "CopyFileA", dst)) { set_error(ERROR_ACCESS_DENIED); RET(3, 0); }' '/* mutated */'
# 15 CreateDirectoryA/RemoveDirectoryA on overlay directories are not refused
mutate rmdir-allowed kernel32.c 'if (ov_refuses_write(&ov, "RemoveDirectoryA", GSTR(ARG(0)))) { set_error(ERROR_ACCESS_DENIED); RET(1, 0); }   /* E1 */' '/* mutated */'
# 16 the lazy index is built without its lock (only ThreadSanitizer can see it)
OLD2='    pthread_mutex_unlock(&g_ov_lock);
}
/* The child of directory d' NEW2='}
/* The child of directory d' mutate index-race core.c '    pthread_mutex_lock(&g_ov_lock);
    if (!d->loaded) {' '    if (!d->loaded) {' tsan
echo "mutations: $caught caught, $missed missed"
[ "$missed" -eq 0 ]
