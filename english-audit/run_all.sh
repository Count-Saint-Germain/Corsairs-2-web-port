#!/bin/sh
# Воспроизведение аудита: sh english-audit/run_all.sh <ru-game-dir> <us-iso> <рабочий-каталог-вне-репозитория>
#   <ru-game-dir>  каталог русской игры (korsary2-next/game, только чтение)
#   <us-iso>       американский образ с InstallShield-архивами ("Pirates of the Caribbean (USA).iso" - единый диск;
#                  образы Disc 1/Disc 2 побайтно содержат те же data1.hdr/data1.cab/data2.cab/data3.cab, см. отчёт)
#   <рабочий-каталог> куда временно извлекаются US-скрипты и тексты (~14 МБ; удалить после прогона)
# Результаты (только имена, размеры, числа) пишутся в english-audit/results/.
# Ничего не запускается из образов; образы открываются только на чтение (english-audit/isoread.mjs).
set -eu
RU="$1"; ISO="$2"; WORK="$3"
HERE="$(cd "$(dirname "$0")" && pwd)"
OUT="$HERE/results"
mkdir -p "$WORK/us" "$OUT"
node "$HERE/ishield.mjs" EXTRACT "$WORK/us" '^(PROGRAM|RESOURCE\\INI|RESOURCE\\QUESTSTEXT|ENGINE\.exe|engine\.ini|options|Readme\.txt|MODULES\\[^\\]+\.dll$)' "$ISO"
node "$HERE/ishield.mjs" LIST "$ISO" | cut -f1-4 > "$WORK/us-list.tsv"
node "$HERE/compare_inventory.mjs" "$RU" "$ISO" --out "$OUT/inventory"
node "$HERE/compare_dialogs.mjs" "$RU/PROGRAM" "$WORK/us/PROGRAM" --out "$OUT/dialogs"
node "$HERE/compare_scripts.mjs" "$RU/PROGRAM" "$WORK/us/PROGRAM" --out "$OUT/scripts"
node "$HERE/compare_texts.mjs" "$RU/RESOURCE" "$WORK/us/RESOURCE" --out "$OUT/texts"
node "$HERE/align_overlay.mjs" "$RU/PROGRAM" "$WORK/us/PROGRAM" --out "$OUT/align" --emit "$WORK/emit"
node "$HERE/verify_overlay.mjs" "$RU/PROGRAM" "$WORK/us/PROGRAM" "$WORK/emit" --out "$OUT/verify"
node "$HERE/overlay_quests.mjs" "$RU/RESOURCE/QUESTSTEXT/quests_texts.txt" "$WORK/us/RESOURCE/QUESTSTEXT/quests_texts.txt" > "$OUT/quests_summary.txt"
node "$HERE/scan_encoding.mjs" "$WORK/us" > "$OUT/encoding_us.txt"
node "$HERE/scan_encoding.mjs" "$RU" > "$OUT/encoding_ru.txt"
echo "готово: $OUT (игровой текст в $WORK/us и $WORK/emit: удалить)"
