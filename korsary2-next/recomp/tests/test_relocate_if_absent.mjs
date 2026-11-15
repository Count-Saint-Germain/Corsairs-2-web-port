/* port.json files.relocate_if_absent в странице (выбор папки): save-protection.mjs relocateIfAbsent.
 * Решение должно совпадать с gamefiles.relocations, используемым сборщиком и сервером. Русские экраны загрузки Textures/Loading/Russian публикуются
 * как Textures/Loading/<имя>, где их и открывает движок (docs/loading-screens-and-music-r1.md); экраны перехода по карте
 * мира Textures/WorldMap/reload/Russian (sea, Battle, Storm, Twister) — как Textures/WorldMap/reload/<имя>
 * (PROGRAM/WorldMap/worldmap_reload.c открывает WorldMap\reload\<имя>.tga; W1).
 * Ничего не пишет и не читает игровые данные (опциональный блок читает только имена настоящей папки);
 * SAVE/SAVE_META/SAVE_TX и options эта функция не трогает. */
import assert from 'node:assert/strict';
import { relocations } from '../web/gamefiles.mjs';
import { existsSync, readFileSync, readdirSync, statSync } from 'node:fs';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';
import { relocateIfAbsent, selectGameAssets } from '../web/save-protection.mjs';

const here = dirname(fileURLToPath(import.meta.url));
const RULE = { from: 'RESOURCE/Textures/Loading/Russian', to: 'RESOURCE/Textures/Loading' };
const RULE_WM = { from: 'RESOURCE/Textures/WorldMap/reload/Russian', to: 'RESOURCE/Textures/WorldMap/reload' };
const RULES = [RULE, RULE_WM];
const L = 'RESOURCE/Textures/Loading', R = 'RESOURCE/Textures/Loading/Russian';
const WL = 'RESOURCE/Textures/WorldMap/reload', WR = 'RESOURCE/Textures/WorldMap/reload/Russian';

// путь -> путь после правила (тот же объект и в Node-тесте test_make_dist_coverage.mjs)
const TABLE = {
  'ENGINE.exe': 'ENGINE.exe',
  [`${L}/start_loading.tga.tx`]: `${L}/start_loading.tga.tx`,              // файл верхнего уровня остаётся
  [`${R}/start_loading.tga.tx`]: `${R}/start_loading.tga.tx`,              // его русская версия остаётся в подпапке (верхний побеждает)
  [`${R}/Start_Loading.TGA.TX`]: `${R}/Start_Loading.TGA.TX`,              // то же имя другого регистра: верхний файл есть
  [`${R}/Tavern_01.tga.tx`]: `${L}/Tavern_01.tga.tx`,                      // единственная копия: публикуется наверху
  [`${R}/Dungeon 01.tga.tx`]: `${L}/Dungeon 01.tga.tx`,                    // имя с пробелом
  [`${R}/Sea.tga.tx`]: `${L}/Sea.tga.tx`,                                  // loading\sea.tga: нужен при каждом выходе в море
  [`${R}/DUP.tga.tx`]: `${L}/DUP.tga.tx`,                                  // два имени, различающихся регистром: первое в порядке сортировки
  [`${R}/dup.tga.tx`]: `${R}/dup.tga.tx`,
  [`${R}/deeper/x.tga.tx`]: `${R}/deeper/x.tga.tx`,                        // вложенная папка не затрагивается
  [`${R}/folder.tga.tx`]: `${R}/folder.tga.tx`,                            // на месте цели лежит папка
  [`${L}/folder.tga.tx/inner`]: `${L}/folder.tga.tx/inner`,
  [`${WR}/sea.tga.tx`]: `${WL}/sea.tga.tx`,                               // W1: worldmap_reload.c открывает WorldMap\\reload\\sea.tga
  [`${WR}/Battle.tga.tx`]: `${WL}/Battle.tga.tx`,
  [`${WR}/Storm.tga.tx`]: `${WR}/Storm.tga.tx`,                            // имя занято наверху -> остаётся в подпапке
  [`${WL}/storm.tga.tx`]: `${WL}/storm.tga.tx`,
  [`${WR}/deeper/x.tga.tx`]: `${WR}/deeper/x.tga.tx`,                      // вложенная папка не затрагивается
  'RESOURCE/Textures/WorldMap/Sea/sea.tga.tx': 'RESOURCE/Textures/WorldMap/Sea/sea.tga.tx',                        // другие папки не затронуты
  'RESOURCE/Sounds/VOICE/RUSSIAN/Cole_Brock.wav': 'RESOURCE/Sounds/VOICE/RUSSIAN/Cole_Brock.wav',
  'RESOURCE/Textures/Loading/RussianX/a.tga.tx': 'RESOURCE/Textures/Loading/RussianX/a.tga.tx',                    // только полные имена каталогов
  'resource/textures/loading/russian/lower.tga.tx': 'resource/textures/loading/lower.tga.tx',                        // регистр каталогов: цель берёт написание из списка
};
const items = Object.keys(TABLE).map((dest) => ({ dest, size: 5 }));
const pathOf = (e) => e.dest;
const withPath = (e, dest) => ({ ...e, dest });
const reloc = (list = items, rules = RULES) => relocateIfAbsent(list, pathOf, withPath, rules);
const paths = (list) => list.map(pathOf).sort();

/* ---------- 1. таблица ---------- */
{
  const out = reloc();
  assert.deepEqual(paths(out), Object.values(TABLE).sort());
  assert.deepEqual(items.map(pathOf), Object.keys(TABLE), 'входной список не изменён');
  assert.equal(out.length, items.length, 'ничего не отбрасывается и не добавляется');
  assert.equal(out.filter((e, i) => e.dest !== items[i].dest).length, 7, 'переносятся ровно семь файлов таблицы (5 экранов загрузки + 2 экрана карты)');
  // остальные поля элемента сохраняются (File при импорте папки)
  assert.ok(out.every((e) => e.size === 5));
}

/* ---------- 2. то же решение, что у сборщика ---------- */
{
  const builderMoves = Object.fromEntries(relocations(Object.keys(TABLE), RULES));
  const js = Object.fromEntries(items.map((e, i) => [e.dest, reloc()[i].dest]).filter(([a, b]) => a !== b));
  assert.deepEqual(js, builderMoves, 'страница и gamefiles.mjs должны переносить одни и те же файлы');
  assert.equal(Object.keys(builderMoves).length, 7);
}

/* ---------- 3. идемпотентность и порядок ---------- */
{
  const once = reloc();
  assert.deepEqual(paths(reloc(once)), paths(once), 'повторное применение ничего не меняет');
  const shuffled = [...items].reverse();
  assert.deepEqual(paths(reloc(shuffled)), paths(once), 'порядок списка не влияет');
}

/* ---------- 4. настоящие правила: port.json == port-config.js ---------- */
{
  const portJson = JSON.parse(readFileSync(join(here, '..', '..', 'port.json'), 'utf8'));
  const text = readFileSync(join(here, '..', 'web', 'port-config.js'), 'utf8');
  const PORT = JSON.parse(text.slice(text.indexOf('{', text.indexOf('window.PORT =')), text.lastIndexOf('}') + 1));
  assert.deepEqual(PORT.files.relocate_if_absent, portJson.files.relocate_if_absent, 'port-config.js устарел: запустите tools/configure.mjs');
  assert.deepEqual(PORT.files.relocate_if_absent, RULES);
  assert.equal(paths(reloc(items, PORT.files.relocate_if_absent)).join('|'), Object.values(TABLE).sort().join('|'));
  // порт читает правило именно из PORT.files.relocate_if_absent
  const portJs = readFileSync(join(here, '..', 'web', 'port.js'), 'utf8');
  assert.match(portJs, /relocateIfAbsent\(kept, e => e\.dest, \(e, dest\) => \(\{ \.\.\.e, dest \}\), PORT\.files\.relocate_if_absent\)/);
}

/* ---------- 5. страница оставляет больше, а не меньше ---------- */
{
  const same = (rules) => relocateIfAbsent(items, pathOf, withPath, rules) === items;
  assert.ok(same(undefined) && same(null) && same([]) && same('x'), 'нет правил — ничего не переносится');
  for (const bad of [
    { ...RULE, extra: 1 }, { from: RULE.from }, { ...RULE, to: RULE.from }, { ...RULE, to: `${RULE.from}/sub` },
    { ...RULE, to: 'RESOURCE/../x' }, { ...RULE, from: 'a\\b' }, { ...RULE, to: '' }, { ...RULE, from: 5 }, null, 'S',
  ]) assert.ok(same([bad]), `некорректное правило игнорируется целиком: ${JSON.stringify(bad)}`);
  // цепочка: to одного правила — from другого -> весь набор игнорируется
  assert.ok(same([RULE, { from: L, to: 'RESOURCE/Textures' }]));
  assert.ok(same([{ from: 'A/B', to: 'A' }, { from: 'A', to: 'A/B' }]));
  // слэши по краям допустимы
  assert.equal(paths(reloc(items, [{ from: `/${R}/`, to: `/${L}/` }, { from: `/${WR}/`, to: `/${WL}/` }])).join('|'), Object.values(TABLE).sort().join('|'));
  // каждое правило действует само по себе (второе без первого не трогает экраны загрузки)
  const onlyWm = relocateIfAbsent(items, pathOf, withPath, [RULE_WM]).filter((e, i) => e.dest !== items[i].dest).map(pathOf).sort();
  assert.deepEqual(onlyWm, [`${WL}/Battle.tga.tx`, `${WL}/sea.tga.tx`]);
}

/* ---------- 6. данные игрока не затронуты: функция работает поверх уже отобранного ---------- */
{
  const withSaves = [...items, { dest: 'SAVE/slot1', size: 10 }, { dest: 'SAVE_META/slot1.time', size: 8 },
    { dest: 'SAVE_TX/journal.log', size: 5 }, { dest: 'options', size: 100 }];
  const selected = selectGameAssets(withSaves, pathOf);
  assert.deepEqual(paths(selected).filter((p) => /^save/i.test(p)), [], 'SAVE* не попадают в список');
  const out = reloc(selected);
  assert.ok(out.some((e) => e.dest === 'options'), 'options остаётся как был');
  // даже если бы такой путь дошёл сюда, правило касается только папки from
  const odd = [{ dest: 'SAVE/a', size: 1 }, { dest: 'options', size: 5 }];
  assert.deepEqual(paths(reloc(odd)), ['SAVE/a', 'options']);
  assert.equal(reloc(odd), odd, 'без совпадений возвращается тот же список');
}

/* ---------- 7. настоящая папка игры (только имена и размеры): все запрошенные скриптами экраны находятся ---------- */
{
  const gameLoading = join(here, '..', '..', 'game', 'RESOURCE', 'Textures', 'Loading');
  if (existsSync(join(gameLoading, 'Russian'))) {
    const real = [...readdirSync(gameLoading).filter((n) => statSync(join(gameLoading, n)).isFile()).map((n) => `${L}/${n}`),
      ...readdirSync(join(gameLoading, 'Russian')).map((n) => `${R}/${n}`)].map((dest) => ({ dest, size: 1 }));
    const out = paths(reloc(real));
    const top = out.filter((p) => p.startsWith(`${L}/`) && !p.slice(L.length + 1).includes('/')).map((p) => p.slice(L.length + 1).toLowerCase());
    assert.equal(real.length, 154); assert.equal(out.length, 154);
    assert.equal(top.length, 145, '17 прежних + 128 перенесённых');
    // имена, которые скрипты передают рендеру: loading\X.tga -> X.tga.tx (без .tx, если имя уже оканчивается на .tx)
    const names = new Set();
    const walk = (d) => { for (const e of readdirSync(d, { withFileTypes: true })) {
      const full = join(d, e.name);
      if (e.isDirectory()) walk(full);
      else if (/\.(c|h)$/i.test(e.name)) for (const m of readFileSync(full, 'latin1').matchAll(/"loading[\\/]([^"]+)"/gi)) names.add(m[1].toLowerCase());
    } };
    walk(join(here, '..', '..', 'game', 'PROGRAM'));
    const missing = [...names].filter((n) => !top.includes(n.endsWith('.tx') ? n : `${n}.tx`));
    assert.deepEqual(missing, [], 'экраны загрузки, которые не находятся в Textures/Loading после переноса');
    assert.ok(top.includes('sea.tga.tx') && top.includes('tavern_01.tga.tx') && top.includes('boarding.tga.tx'));
    // и до переноса большинство из них находилось только в Russian/
    const before = real.map(pathOf).filter((p) => p.startsWith(`${L}/`) && !p.slice(L.length + 1).includes('/')).map((p) => p.slice(L.length + 1).toLowerCase());
    const before_missing = [...names].filter((n) => !before.includes(n.endsWith('.tx') ? n : `${n}.tx`));
    assert.ok(before_missing.length >= 100, `до переноса не находились ${before_missing.length} имён`);
  } else console.log('- папка игры не найдена: сверка со скриптами пропущена');
}

/* ---------- 8. настоящая папка игры: экраны перехода по карте мира (W1) ---------- */
{
  const gameWm = join(here, '..', '..', 'game', 'RESOURCE', 'Textures', 'WorldMap', 'reload');
  const script = join(here, '..', '..', 'game', 'PROGRAM', 'WorldMap', 'worldmap_reload.c');
  if (existsSync(join(gameWm, 'Russian')) && existsSync(script)) {
    const real = [...readdirSync(gameWm).filter((n) => statSync(join(gameWm, n)).isFile()).map((n) => `${WL}/${n}`),
      ...readdirSync(join(gameWm, 'Russian')).map((n) => `${WR}/${n}`)].map((dest) => ({ dest, size: 1 }));
    const top = paths(reloc(real)).filter((p) => p.startsWith(`${WL}/`) && !p.slice(WL.length + 1).includes('/')).map((p) => p.slice(WL.length + 1).toLowerCase());
    // имена, которые запрашивает скрипт перехода: "WorldMap\reload\<имя>.tga"
    const asked = [...readFileSync(script, 'latin1').matchAll(/"WorldMap[\\/]reload[\\/]([^"]+)"/gi)].map((m) => m[1].toLowerCase());
    assert.deepEqual([...new Set(asked)].sort(), ['battle.tga', 'sea.tga', 'storm.tga', 'twister.tga']);
    assert.deepEqual(asked.filter((n) => !top.includes(`${n}.tx`)), [], 'экраны перехода по карте находятся в WorldMap/reload после переноса');
    assert.ok(!paths(reloc(real)).some((p) => p.startsWith(`${WR}/`)), 'ничего не остаётся в reload/Russian');
    assert.ok(reloc(real, [RULE]).every((e, i) => e.dest === real[i].dest) && !reloc(real, [RULE]).some((e) => e.dest.startsWith(`${WL}/`) && !e.dest.includes('/Russian/')),
      'без второго правила (прежний port.json) экраны карты недоступны');
  } else console.log('- папка игры не найдена: сверка экранов карты мира пропущена');
}

console.log('OK: test_relocate_if_absent');
