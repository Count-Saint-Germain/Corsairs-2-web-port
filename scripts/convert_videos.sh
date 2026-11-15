#!/usr/bin/env bash
# convert_videos.sh — transcode game/RESOURCE/VIDEOS/*.wmv -> web-port/videos-web/*.mp4
# H.264 + AAC, keep 640x384 resolution, CRF 23, preset medium.
# Idempotent: skips a video if the MP4 exists and is newer than the source.
# Requires ffmpeg, ffprobe and Node.js.
#
# The default game directory is next to web-port; paths can be overridden with
# --source-dir and --output-dir. No personal or machine-specific paths are used.
set -uo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)" || exit 1
PORT_ROOT="$(cd -- "$SCRIPT_DIR/.." && pwd -P)" || exit 1
SRC_DIR="$PORT_ROOT/../game/RESOURCE/VIDEOS"
OUT_DIR="$PORT_ROOT/videos-web"

usage() {
  printf 'Usage: %s [--source-dir DIR] [--output-dir DIR]\n' "${0##*/}"
  printf 'Defaults: ../game/RESOURCE/VIDEOS and ./videos-web relative to the web-port root.\n'
  printf 'Do not modify output directories concurrently while conversion is running.\n'
}

while (($#)); do
  case "$1" in
    --source-dir|--output-dir)
      if (($# < 2)) || [[ -z "$2" ]]; then
        printf 'ERROR: %s requires a directory\n' "$1" >&2; exit 2
      fi
      if [[ "$1" == --source-dir ]]; then SRC_DIR="$2"; else OUT_DIR="$2"; fi
      shift 2 ;;
    -h|--help) usage; exit 0 ;;
    *) printf 'ERROR: unknown argument: %s\n' "$1" >&2; usage >&2; exit 2 ;;
  esac
done

if [[ ! -d "$SRC_DIR" || ! -r "$SRC_DIR" || ! -x "$SRC_DIR" ]]; then
  printf 'ERROR: source video directory is missing or unreadable: %s\n' "$SRC_DIR" >&2
  exit 1
fi
SRC_DIR="$(cd -- "$SRC_DIR" && pwd -P)" || exit 1

command -v ffmpeg >/dev/null 2>&1 || { echo "ERROR: ffmpeg not found (brew install ffmpeg)" >&2; exit 1; }
command -v ffprobe >/dev/null 2>&1 || { echo 'ERROR: ffprobe not found' >&2; exit 1; }
command -v node >/dev/null 2>&1 || { echo 'ERROR: Node.js is required to check output name collisions' >&2; exit 1; }

# wc and awk avoid the incompatible BSD/GNU stat flags and a dependency on bc.
file_bytes() { wc -c < "$1" | tr -d '[:space:]'; }
megabytes() { awk -v n="$1" 'BEGIN { printf "%.1f", n / 1048576 }'; }

source_list="$(mktemp "${TMPDIR:-/tmp}/k2-videos.XXXXXXXX")" || exit 1
temp_dir=''
cleanup() {
  if [[ -n "$temp_dir" ]]; then
    rm -f -- "$temp_dir/output.mp4"
    rmdir -- "$temp_dir" 2>/dev/null || true
  fi
  rm -f -- "$source_list"
}
trap cleanup EXIT

# Enumerate and validate the entire input before touching the output directory.
# Process substitution would hide a failing find and could convert a partial set.
if ! find "$SRC_DIR" -type f \( -iname '*.wmv' -o -iname '*.avi' -o -iname '*.mpg' \) -print0 > "$source_list"; then
  echo 'ERROR: could not enumerate the complete source video directory' >&2
  exit 1
fi

# Two sources must never silently overwrite the same MP4. Conservatively fold
# Unicode and normalize names for case-insensitive/normalizing filesystems too.
sources=(); relatives=(); bases=(); keys=(); source_count=0
while IFS= read -r -d '' src; do
  if [[ "$src" != "$SRC_DIR/"* ]]; then echo 'ERROR: unexpected source path' >&2; exit 1; fi
  rel="${src:${#SRC_DIR}+1}"
  base="${rel%.*}"
  key="$(node "$SCRIPT_DIR/unicode_casefold.mjs" "$base.mp4")" || {
    echo 'ERROR: could not normalize output name' >&2; exit 1
  }
  i=0
  while ((i < source_count)); do
    if [[ "${keys[$i]}" == "$key" ]]; then
      printf 'ERROR: multiple videos map to the same output: %s and %s\n' "${relatives[$i]}" "$rel" >&2
      exit 1
    fi
    i=$((i + 1))
  done
  sources[$source_count]="$src"; relatives[$source_count]="$rel"
  bases[$source_count]="$base"; keys[$source_count]="$key"
  source_count=$((source_count + 1))
done < "$source_list"

mkdir -p -- "$OUT_DIR" || exit 1
OUT_DIR="$(cd -- "$OUT_DIR" && pwd -P)" || exit 1

# Refuse symlinks or non-directories at every nested parent component. Check
# physical paths remain under the explicitly chosen output root. These checks
# do not provide race-free protection against concurrent directory replacement;
# the output tree must not be modified by another process during conversion.
ensure_output_parent() {
  local output_base="$1" remaining component current resolved
  if [[ "$output_base" != */* ]]; then return 0; fi
  remaining="${output_base%/*}"
  current="$OUT_DIR"
  while [[ -n "$remaining" ]]; do
    if [[ "$remaining" == */* ]]; then
      component="${remaining%%/*}"; remaining="${remaining#*/}"
    else
      component="$remaining"; remaining=''
    fi
    if [[ -z "$component" || "$component" == '.' || "$component" == '..' ]]; then return 1; fi
    current="${current%/}/$component"
    if [[ -L "$current" ]]; then return 1; fi
    if [[ ! -e "$current" ]]; then mkdir -- "$current" || return 1; fi
    if [[ -L "$current" || ! -d "$current" ]]; then return 1; fi
    resolved="$(cd -- "$current" && pwd -P)" || return 1
    if [[ "$OUT_DIR" != / && "$resolved" != "$OUT_DIR/"* ]]; then return 1; fi
  done
}

total_src=0
total_out=0
count=0
failed=0
noaudio=""

i=0
while ((i < source_count)); do
  src="${sources[$i]}"; rel="${relatives[$i]}"; base="${bases[$i]}"
  i=$((i + 1))
  out="$OUT_DIR/${base}.mp4"
  if ! ensure_output_parent "$base"; then
    echo "FAIL  $rel (output parent is unsafe or cannot be created)" >&2
    failed=$((failed + 1)); continue
  fi

  if [[ -L "$out" || ( -e "$out" && ! -f "$out" ) ]]; then
    echo "FAIL  $rel (output is not a regular file)" >&2
    failed=$((failed + 1)); continue
  fi

  if [[ -f "$out" && "$out" -nt "$src" ]]; then
    sz_src=$(file_bytes "$src"); sz_out=$(file_bytes "$out")
    printf 'SKIP  %-28s (%.1f MB -> %.1f MB, up to date)\n' "$rel" \
      "$(megabytes "${sz_src:-0}")" "$(megabytes "${sz_out:-0}")"
    total_src=$((total_src + ${sz_src:-0})); total_out=$((total_out + ${sz_out:-0})); count=$((count + 1))
    continue
  fi

  echo "CONV  $rel -> $out"
  temp_dir="$(mktemp -d "$(dirname "$out")/.k2-video.XXXXXXXX")" || {
    echo "FAIL  $rel (cannot create temporary output)" >&2
    failed=$((failed + 1)); continue
  }
  temp_output="$temp_dir/output.mp4"
  # The temporary output is on the same filesystem: only a complete, nonempty
  # conversion is renamed into place. A failed conversion preserves an old MP4.
  if ffmpeg -nostdin -hide_banner -loglevel error -y \
       -i "$src" \
       -map 0:v:0 -map 0:a:0? \
       -c:v libx264 -crf 23 -preset medium -pix_fmt yuv420p \
       -c:a aac -b:a 96k \
       -movflags +faststart \
       "$temp_output" < /dev/null && [[ -f "$temp_output" && ! -L "$temp_output" && -s "$temp_output" ]] && ensure_output_parent "$base" && [[ ! -L "$out" && ( ! -e "$out" || -f "$out" ) ]] && mv -f -- "$temp_output" "$out"; then
    rmdir -- "$temp_dir" 2>/dev/null || true
    temp_dir=''
    sz_src=$(file_bytes "$src"); sz_out=$(file_bytes "$out")
    printf 'OK    %-28s (%.1f MB -> %.1f MB)\n' "$rel" \
      "$(megabytes "${sz_src:-0}")" "$(megabytes "${sz_out:-0}")"
    total_src=$((total_src + ${sz_src:-0})); total_out=$((total_out + ${sz_out:-0})); count=$((count + 1))
    # note streams without audio
    ffprobe -v error -select_streams a -show_entries stream=index -of csv=p=0 "$src" 2>/dev/null | grep -q . || noaudio="$noaudio $rel"
  else
    echo "FAIL  $rel (conversion or atomic replacement failed; existing output preserved)" >&2
    rm -f -- "$temp_output"
    rmdir -- "$temp_dir" 2>/dev/null || true
    temp_dir=''
    failed=$((failed + 1))
  fi
done

echo
echo "Converted/present: $count  failed: $failed"
printf 'Total source: %.1f MB   total output: %.1f MB\n' \
  "$(megabytes "$total_src")" "$(megabytes "$total_out")"
[[ -n "$noaudio" ]] && { echo "Videos without audio track:$noaudio"; } || true
if ((failed > 0)); then exit 1; fi
exit 0
