/* port.json files.exclude_if_sibling в странице (выбор папки): save-protection.mjs dropSiblingDuplicates.
 * Решение должно совпадать с gamefiles.redundantSiblings, используемым сборщиком и сервером.
 * Ничего не пишет и не читает игровые данные; SAVE/SAVE_META/SAVE_TX и options эта функция не трогает. */
import assert from 'node:assert/strict';
import { redundantSiblings } from '../web/gamefiles.mjs';
import { readFileSync } from 'node:fs';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';
import { dropSiblingDuplicates, selectGameAssets } from '../web/save-protection.mjs';

const here = dirname(fileURLToPath(import.meta.url));
const RULE = { path: 'RESOURCE/Sounds', extension: '.ogg', sibling_extension: '.wav', min_sibling_bytes: 45 };

// путь -> [размер, должен ли попасть в установку]; та же таблица, что SOUND_FIXTURE в test_make_dist_coverage.mjs
const TABLE = {
  'ENGINE.exe': [3, true],
  'RESOURCE/Sounds/PEOPLE/step_sand.wav': [100, true],
  'RESOURCE/Sounds/PEOPLE/step_sand.ogg': [10, false],
  'RESOURCE/Sounds/INTERFACE/_Abandon0.WAV': [100, true],
  'RESOURCE/Sounds/INTERFACE/_abandon0.ogg': [10, false],
  'RESOURCE/Sounds/AMBIENT/INCA TEMPLE/hiss.wav': [100, true],
  'RESOURCE/Sounds/AMBIENT/INCA TEMPLE/hiss.OGG': [10, false],
  'RESOURCE/Sounds/MUSIC/Coridor.ogg': [10, true],
  'RESOURCE/Sounds/VOICE/RUSSIAN/Cole_Brock.ogg': [10, true],
  'RESOURCE/Sounds/VOICE/Cole_Brock.wav': [100, true],
  'RESOURCE/Sounds/trep/short.ogg': [10, true],
  'RESOURCE/Sounds/trep/short.wav': [44, true],
  'RESOURCE/Sounds/trep/empty.ogg': [10, true],
  'RESOURCE/Sounds/trep/empty.wav': [0, true],
  'RESOURCE/Sounds/trep/only.wav': [100, true],
  'RESOURCE/Sounds2/x.ogg': [10, true],
  'RESOURCE/Sounds2/x.wav': [100, true],
  'RESOURCE/Textures/x.ogg': [10, true],
  'RESOURCE/Textures/x.wav': [100, true],
  'RESOURCE/Sounds/notes.ogg.txt': [5, true],
};
const items = Object.entries(TABLE).map(([dest, [size]]) => ({ dest, size }));
const pathOf = (e) => e.dest, sizeOf = (e) => e.size;
const shipped = (list) => list.map(pathOf).sort();

/* ---------- 1. таблица ---------- */
{
  const kept = dropSiblingDuplicates(items, pathOf, sizeOf, [RULE]);
  assert.deepEqual(shipped(kept), Object.entries(TABLE).filter(([, [, ships]]) => ships).map(([p]) => p).sort());
  assert.equal(items.length - kept.length, 3, 'ровно три пары из таблицы');
  assert.deepEqual(items.map(pathOf), Object.keys(TABLE), 'входной список не изменён');
}

/* ---------- 2. то же решение, что у сборщика ---------- */
{
  const builderDrop = [...redundantSiblings(items.map((e) => [e.dest, e.size]))].sort();
  const jsDrop = items.map(pathOf).filter((p) => !shipped(dropSiblingDuplicates(items, pathOf, sizeOf, [RULE])).includes(p)).sort();
  assert.deepEqual(jsDrop, builderDrop, 'страница и gamefiles.mjs должны отбрасывать одни и те же файлы');
  assert.equal(builderDrop.length, 3);
}

/* ---------- 3. настоящие правила: port.json == port-config.js, и они дают то же ---------- */
{
  const portJson = JSON.parse(readFileSync(join(here, '..', '..', 'port.json'), 'utf8'));
  const text = readFileSync(join(here, '..', 'web', 'port-config.js'), 'utf8');
  const PORT = JSON.parse(text.slice(text.indexOf('{', text.indexOf('window.PORT =')), text.lastIndexOf('}') + 1));
  assert.deepEqual(PORT.files.exclude_if_sibling, portJson.files.exclude_if_sibling, 'port-config.js устарел: запустите tools/configure.mjs');
  assert.deepEqual(PORT.files.exclude_if_sibling, [RULE]);
  assert.equal(dropSiblingDuplicates(items, pathOf, sizeOf, PORT.files.exclude_if_sibling).length, items.length - 3);
}

/* ---------- 4. страница оставляет больше, а не меньше ---------- */
{
  const all = (rules) => dropSiblingDuplicates(items, pathOf, sizeOf, rules).length === items.length;
  assert.ok(all(undefined) && all(null) && all([]) && all('x'), 'нет правил — ничего не отбрасывается');
  for (const bad of [
    { ...RULE, extension: 'ogg' }, { ...RULE, sibling_extension: '.ogg' }, { ...RULE, min_sibling_bytes: 0 },
    { ...RULE, min_sibling_bytes: '45' }, { ...RULE, extension: '.a/b' }, null, 'S',
  ]) assert.ok(all([bad]), `некорректное правило игнорируется целиком: ${JSON.stringify(bad)}`);
  // цепочка/цикл могли бы убрать обе копии пары: весь набор правил игнорируется
  assert.ok(all([RULE, { path: 'RESOURCE/Sounds', extension: '.wav', sibling_extension: '.ogg' }]));
  assert.ok(all([RULE, { path: 'RESOURCE/Sounds', extension: '.mp3', sibling_extension: '.ogg' }]));
  // значение по умолчанию min_sibling_bytes = 1: непустой .wav достаточен, пустой — нет
  const dflt = { path: 'RESOURCE/Sounds', extension: '.ogg', sibling_extension: '.wav' };
  const kept = shipped(dropSiblingDuplicates(items, pathOf, sizeOf, [dflt]));
  assert.ok(kept.includes('RESOURCE/Sounds/trep/empty.ogg') && !kept.includes('RESOURCE/Sounds/trep/short.ogg'));
  // правило без path действует везде
  const anywhere = shipped(dropSiblingDuplicates(items, pathOf, sizeOf, [{ ...RULE, path: '' }]));
  assert.ok(!anywhere.includes('RESOURCE/Textures/x.ogg') && !anywhere.includes('RESOURCE/Sounds2/x.ogg'));
}

/* ---------- 5. данные игрока не затронуты: функция работает после selectGameAssets, поверх уже отобранного ---------- */
{
  const withSaves = [...items, { dest: 'SAVE/slot1', size: 10 }, { dest: 'SAVE_META/slot1.time', size: 8 },
    { dest: 'SAVE_TX/journal.log', size: 5 }, { dest: 'options', size: 100 }];
  const selected = selectGameAssets(withSaves, pathOf);
  assert.deepEqual(shipped(selected).filter((p) => /^save/i.test(p)), [], 'SAVE* не попадают в список');
  const kept = dropSiblingDuplicates(selected, pathOf, sizeOf, [RULE]);
  assert.ok(kept.some((e) => e.dest === 'options'), 'options остаётся как был');
  // даже если бы такой файл дошёл сюда, он не пара .ogg/.wav и не отбрасывается
  const odd = [{ dest: 'SAVE/a.wav', size: 100 }, { dest: 'SAVE/a.ogg', size: 10 }, { dest: 'options', size: 5 }];
  assert.deepEqual(shipped(dropSiblingDuplicates(odd, pathOf, sizeOf, [RULE])), ['SAVE/a.ogg', 'SAVE/a.wav', 'options']);
}

console.log('OK: test_sibling_duplicates');
