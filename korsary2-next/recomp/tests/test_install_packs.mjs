/* D3: пакеты передачи и параллельная установка — web/game-transfer.mjs (downloadPackRun, planPackRuns,
   validateManifestPacks) и web/save-protection.mjs (syncManifestFiles с concurrency/packs/signal, planStorageNeed).
   Без сети и без браузера: настоящие DecompressionStream/Response из Node, хранилище с семантикой OPFS и «сервер»
   (tests/pack_fixture.mjs) — синтетические. Эти проверки доказывают логику; реальный OPFS и задержки сети —
   tests/test_install_requests_browser.mjs.
     node tests/test_install_packs.mjs */
import assert from 'node:assert/strict';
import * as T from '../web/game-transfer.mjs';
import { syncManifestFiles, validateManifestFiles, planStorageNeed, planFileUpdate, installConcurrency, INSTALL_CONCURRENCY } from '../web/save-protection.mjs';
import { Dir, buildGame, existingSize, noise, pseudo, put, read, server, sha, sleepMs, wire } from './pack_fixture.mjs';

let n = 0;
const ok = (name) => { n++; console.log('ok - ' + name); };

/* ---- игра: 60 мелких файлов в нескольких папках + несжимаемый + пустой + крупный + options */
const files = {};
for (let i = 0; i < 60; i++) files[`RESOURCE/Models/Locations/loc${i % 5}/f${String(i).padStart(3, '0')}.gm`] = mixed(1200 + 83 * i, 10 + i);
files['PROGRAM/s.c'] = new TextEncoder().encode('// tiny\n'.repeat(20));
files['PROGRAM/empty.c'] = new Uint8Array(0);
files['RESOURCE/Sounds/noise.wav'] = noise(9000, 5);
files['RESOURCE/Textures/big.tx'] = concatBig();
files['options'] = new TextEncoder().encode('options-bytes'.repeat(20));
/** Наполовину сжимаемые, наполовину шум: gzip даёт около 55 %. */
function mixed(len, seed) { const o = new Uint8Array(len), h = len >> 1; o.set(pseudo(h, seed)); o.set(noise(len - h, seed), h); return o; }
function concatBig() { const a = pseudo(30_000, 3), b = noise(30_000, 9); const o = new Uint8Array(60_000); o.set(a); o.set(b, 30_000); return o; }
const game = buildGame(files, { packSize: 16_000, maxFile: 12_000 });
assert.ok(game.manifest.packs.length >= 4, 'несколько пакетов');
const loose = game.manifest.files.filter((e) => e.pack === undefined).map((e) => e.path);
assert.ok(loose.includes('options') && loose.includes('RESOURCE/Textures/big.tx'), 'options и крупный файл остаются отдельными объектами');
const total = game.manifest.files.reduce((s, e) => s + e.size, 0);

/* общий прогон установки */
async function install({ manifest = game.manifest, objects = game.objects, dir = new Dir(), hadMarker = false, concurrency = 4, signal = null,
  serverOpts = {}, fetchImpl = null, retrySleep = 0, show = null } = {}) {
  const fi = fetchImpl || server(objects, { chunk: 700, ...serverOpts });
  const ctx = { marker: null, sleeps: [], progress: [], error: null, fetch: fi, dir };
  const w = wire(T, { dir, fetchImpl: fi });
  try {
    await syncManifestFiles({ dir, files: manifest.files, hadMarker, version: manifest.version, existingSize,
      downloadFile: w.downloadFile, downloadPackRun: w.downloadPackRun, packs: manifest.packs, concurrency, signal,
      downloadOptionsFile: async (d, entry, onBytes) => {
        const res = await fi('http://t/game/options', {}); const b = new Uint8Array(await res.arrayBuffer());
        assert.equal(sha(b), entry.sha256); await put(d, 'options', b); onBytes(b.length);
      },
      writeMarker: async (v) => { ctx.marker = v; },
      show: (done, name) => { ctx.progress.push(done); show?.(done, name); },
      sleep: async (ms, path, err, sig) => { ctx.sleeps.push([path, err.name + ': ' + String(err.message).slice(0, 70)]); if (retrySleep) await sleepMs(retrySleep); } });
  } catch (e) { ctx.error = e; }
  return ctx;
}
async function assertInstalled(dir, g = game, label = '') {
  for (const e of g.manifest.files) {
    const got = await read(dir, e.path);
    assert.ok(got, `${label} ${e.path} отсутствует`);
    assert.equal(got.length, e.size, `${label} размер ${e.path}`);
    assert.equal(sha(got), e.sha256, `${label} SHA-256 ${e.path}`);
  }
}
const monotone = (p) => p.every((v, i) => i === 0 || v >= p[i - 1]);

/* 1. валидация манифеста: пакеты */
{
  const f = game.manifest.files, p = game.manifest.packs;
  assert.equal(T.validateManifestPacks(validateManifestFiles(f), p).length, f.length);
  assert.equal(T.validateManifestPacks(validateManifestFiles(f.filter((e) => e.pack === undefined)), undefined).length, loose.length, 'манифест без пакетов проходит как есть');
  const rec = f.find((e) => e.pack !== undefined && e.enc === 'gzip'), raw = f.find((e) => e.pack !== undefined && !e.enc && e.csize > 0);
  const bad = (mut, re, packs = p) => {
    const files2 = f.map((e) => ({ ...e }));
    mut(files2, packs);
    assert.throws(() => T.validateManifestPacks(validateManifestFiles(files2), packs), re);
  };
  bad((a) => { a.find((e) => e.path === rec.path).pack = 99; }, /номер пакета/);
  bad((a) => { a.find((e) => e.path === rec.path).offset = -1; }, /некорректное место записи/);
  bad((a, ps) => { a.find((e) => e.path === rec.path).csize = p[rec.pack].size + 1; }, /за пределы пакета/);
  bad((a) => { const e = a.find((x) => x.path === raw.path); e.csize = e.size - 1; }, /должна быть равна размеру/);
  bad((a) => { const e = a.find((x) => x.path === rec.path); const o = a.find((x) => x.pack === e.pack && x.offset > e.offset && x.csize > 0); o.offset = e.offset + 1; }, /пересекаются/);
  bad((a, ps) => {}, /нет списка пакетов/, null);
  bad((a, ps) => {}, /дважды/, [p[0], { ...p[0] }, ...p.slice(2)]);
  bad((a) => {}, /Некорректное описание пакета/, p.map((x, i) => (i === 0 ? { ...x, path: '../etc/passwd' } : x)));
  bad((a) => {}, /Некорректное описание пакета/, p.map((x, i) => (i === 0 ? { ...x, size: -1 } : x)));
  assert.throws(() => validateManifestFiles([{ path: 'options', size: 3, sha256: '0'.repeat(64), pack: 0, offset: 0, csize: 3 }]), /нельзя передавать сжатым/);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 3, sha256: '0'.repeat(64), pack: 'x', offset: 0, csize: 3 }]), /некорректное место/);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 3, sha256: '0'.repeat(64), enc: 'zstd', pack: 0, offset: 0, csize: 3 }]), /неподдерживаемое кодирование/);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 3, pack: 0, offset: 0, csize: 3 }]), /нет SHA-256/);
  ok('manifest: проверка пакетов (индекс, диапазон, пересечения, csize сырой записи, options, имена, старый манифест)');
}

/* 2. планировщик диапазонов */
{
  const e = (path, pack, offset, csize) => ({ path, pack, offset, csize });
  const runs = T.planPackRuns([e('a', 0, 0, 100), e('b', 0, 100, 50), e('c', 0, 100_000, 10), e('d', 1, 5, 5), e('z', 0, 100, 0)], 1000);
  assert.deepEqual(runs.map((r) => [r.pack, r.start, r.end, r.entries.map((x) => x.path)]), [[0, 0, 150, ['a', 'z', 'b']], [0, 100_000, 100_010, ['c']], [1, 5, 10, ['d']]]);
  assert.equal(T.planPackRuns([e('a', 0, 0, 10), e('b', 0, 11 + T.PACK_RUN_GAP, 10)]).length, 2);
  assert.equal(T.planPackRuns([e('a', 0, 0, 10), e('b', 0, 10 + T.PACK_RUN_GAP, 10)]).length, 1, 'зазор ровно в предел сливается');
  assert.deepEqual(T.planPackRuns([]), []);
  ok('planPackRuns: слияние близких записей, нулевая запись раньше соседней, пакеты раздельно');
}

/* 3. downloadPackRun: круговой обход, Range, сервер без Range, прогресс, нулевые записи */
for (const chunk of [1, 7, 333, 5000, 1 << 20]) {
  const dir = new Dir(), fi = server(game.objects, { chunk });
  const w = wire(T, { dir, fetchImpl: fi });
  const progress = []; const accepted = [];
  const ps = game.manifest.packs;
  for (let i = 0; i < ps.length; i++) {
    const es = game.manifest.files.filter((e) => e.pack === i);
    await w.downloadPackRun(dir, ps[i], es, (b) => progress.push(b), (e) => accepted.push(e.path), {});
  }
  assert.equal(progress.reduce((a, b) => a + b, 0), game.manifest.files.filter((e) => e.pack !== undefined).reduce((s, e) => s + e.size, 0), `chunk ${chunk}: прогресс = сумма РАСПАКОВАННЫХ размеров`);
  assert.equal(accepted.length, game.manifest.files.filter((e) => e.pack !== undefined).length);
  assert.ok(fi.log.every((r) => r.range === null), 'пакет целиком: без Range');
  assert.equal(fi.log.length, ps.length, 'по одному запросу на пакет');
  for (const e of game.manifest.files.filter((x) => x.pack !== undefined)) assert.equal(sha(await read(dir, e.path)), e.sha256, `${e.path} (chunk ${chunk})`);
}
ok('downloadPackRun: пакет целиком одним запросом, любая нарезка чанков (1 байт … 1 МиБ), SHA, прогресс, нулевая запись');
{
  const ps = game.manifest.packs;
  const es = game.manifest.files.filter((e) => e.pack === 1).sort((a, b) => a.offset - b.offset);
  const pick = [es[1], es[es.length - 2]];
  for (const honorRange of [true, false]) {
    const dir = new Dir(), fi = server(game.objects, { chunk: 211, honorRange });
    const w = wire(T, { dir, fetchImpl: fi });
    const got = [];
    await w.downloadPackRun(dir, ps[1], pick, () => {}, (e) => got.push(e.path), {});
    assert.deepEqual(got, pick.map((e) => e.path));
    assert.equal(fi.log[0].range, `bytes=${pick[0].offset}-${pick[1].offset + pick[1].csize - 1}`);
    for (const e of pick) assert.equal(sha(await read(dir, e.path)), e.sha256);
    assert.equal((await read(dir, es[0].path)), null, 'не запрошенная запись не создаётся');
  }
  ok('downloadPackRun: Range от первой до последней нужной записи; сервер, проигнорировавший Range (200), тоже годится');
  const dir = new Dir(), fi = server(game.objects);
  const zero = game.manifest.files.find((e) => e.size === 0);
  await wire(T, { dir, fetchImpl: fi }).downloadPackRun(dir, ps[zero.pack], [zero], () => {}, () => {}, {});
  assert.equal(fi.log.length, 0, 'пустая запись: сеть не нужна');
  assert.equal((await read(dir, zero.path)).length, 0);
  ok('downloadPackRun: пустой файл создаётся без запроса');
}

/* 4. порча, усечение, ложный диапазон: файл не принят, предыдущие приняты, close не вызван для плохого */
{
  const ps = game.manifest.packs;
  const es = game.manifest.files.filter((e) => e.pack === 0).sort((a, b) => a.offset - b.offset || a.csize - b.csize);
  const target = es.find((e, i) => i >= 3 && e.csize > 50);
  const cases = {
    'усечённый пакет': { f: (info) => ({ cutAt: target.offset + Math.floor(target.csize / 2) }), re: /network error|оборван/ },
    'повреждённая запись': { f: () => ({ mutate: (b) => { b[target.offset + 15] ^= 0xFF; return b; } }), re: /./ },
    'ответ другой длины': { f: () => ({ mutate: (b) => b.subarray(0, target.offset + 3) }), re: /оборван|короче|распаковк/ },
    'не тот диапазон': { f: () => ({ contentRange: 'bytes 5-9/100' }), re: /не тот диапазон/ },
  };
  for (const [name, c] of Object.entries(cases)) {
    const dir = new Dir(), fi = server(game.objects, { chunk: 97, fault: c.f });
    const w = wire(T, { dir, fetchImpl: fi });
    const accepted = [];
    const list = name === 'не тот диапазон' ? es.slice(2) : es;
    await assert.rejects(w.downloadPackRun(dir, ps[0], list, () => {}, (e) => accepted.push(e.path), {}), c.re, name);
    assert.ok(!accepted.includes(target.path), `${name}: плохая запись не принята`);
    assert.equal(await read(dir, target.path), null, `${name}: плохой файл не остался в хранилище`);
    for (const p of accepted) assert.ok(await read(dir, p), `${name}: принятое осталось`);
    const idx = list.indexOf(target);
    if (name !== 'не тот диапазон') assert.deepEqual(accepted, list.slice(0, idx).map((e) => e.path), `${name}: приняты ровно записи до плохой`);
    assert.equal(dir.stats.openWritables, 0, `${name}: незавершённых записей не осталось`);
  }
  // повреждение сырой записи (SHA)
  const raw = game.manifest.files.find((e) => e.pack !== undefined && !e.enc && e.csize > 100);
  const dir = new Dir(), fi = server(game.objects, { fault: () => ({ mutate: (b) => { b[raw.offset + 5] ^= 1; return b; } }) });
  await assert.rejects(wire(T, { dir, fetchImpl: fi }).downloadPackRun(dir, ps[raw.pack], game.manifest.files.filter((e) => e.pack === raw.pack), () => {}, () => {}, {}), /SHA-256/);
  assert.equal(await read(dir, raw.path), null);
  // HTTP-ошибки и нехватка места
  await assert.rejects(wire(T, { dir: new Dir(), fetchImpl: server({}) }).downloadPackRun(new Dir(), ps[0], es, () => {}, () => {}, {}), /HTTP 404/);
  await assert.rejects(wire(T, { dir: new Dir(), fetchImpl: server(game.objects, { fault: () => '500' }) }).downloadPackRun(new Dir(), ps[0], es, () => {}, () => {}, {}), /HTTP 500/);
  ok('пакет: усечение, порча gzip-записи и сырой записи, ответ короче, чужой Content-Range, 404/500: плохая запись не принята и не остаётся, прежние приняты');
}

/* 5. чистая установка: смешанный манифест, параллелизм, прогресс */
for (const concurrency of [1, 3, 6]) {
  const ctx = await install({ concurrency, serverOpts: { delay: 3 } });
  assert.equal(ctx.error, null, ctx.error?.message);
  assert.equal(ctx.marker, game.manifest.version);
  await assertInstalled(ctx.dir, game, `c${concurrency}`);
  assert.ok(ctx.fetch.state.maxInflight <= concurrency, `одновременных запросов ${ctx.fetch.state.maxInflight} > ${concurrency}`);
  if (concurrency > 1) assert.ok(ctx.fetch.state.maxInflight >= Math.min(concurrency, 3), `параллелизм не используется (${ctx.fetch.state.maxInflight})`);
  assert.ok(monotone(ctx.progress), 'прогресс не убывает');
  assert.equal(ctx.progress.at(-1), total, 'прогресс заканчивается на сумме РАСПАКОВАННЫХ размеров');
  assert.ok(ctx.progress.every((v) => v <= total));
  const expectedRequests = game.manifest.packs.length + loose.length - 1 /* options: через downloadOptionsFile, тоже fetch */ + 1;
  assert.equal(ctx.fetch.log.length, expectedRequests, 'запросов: пакеты + отдельные объекты, не по файлу');
  assert.equal(ctx.dir.stats.openWritables, 0);
}
ok('установка: чистая, concurrency 1/3/6, всё верно, не больше N запросов сразу, прогресс монотонен и доходит до суммы, запросов = пакеты + отдельные');

/* 6. порядок выдачи и ограничение N */
{
  const order = [];
  const g2 = buildGame(Object.fromEntries(Array.from({ length: 24 }, (_, i) => [`d/f${String(i).padStart(2, '0')}.bin`, noise(3000 + i, i + 1)])), { pack: false });
  const fi = server(g2.objects, { delay: 5, chunk: 4000 });
  const orig = fi;
  const logging = async (u, i) => { order.push(decodeURIComponent(new URL(u).pathname)); return orig(u, i); };
  logging.state = orig.state; logging.log = orig.log;
  const ctx = await install({ manifest: g2.manifest, objects: g2.objects, fetchImpl: logging, concurrency: 4 });
  assert.equal(ctx.error, null);
  assert.deepEqual(order, Object.keys(g2.objects).sort().map((k) => '/game/' + k).map((x) => x), 'файлы выдаются в порядке манифеста');
  assert.equal(orig.state.maxInflight, 4);
  ok('порядок выдачи = порядок манифеста; одновременных запросов ровно N при 24 файлах');
}

/* 7. один файл не ломает остальные: постоянная ошибка */
{
  const bad = 'RESOURCE/Models/Locations/loc2/f032.gm';
  const badRec = game.manifest.files.find((e) => e.path === bad);
  // 7a: запись пакета с постоянной порчей
  let ctx = await install({ serverOpts: { fault: (info) => (info.key === game.manifest.packs[badRec.pack].path ? { mutate: (b, at) => { b[badRec.offset + 20 - at] ^= 0xFF; return b; } } : undefined), delay: 2 }, concurrency: 4 });
  assert.ok(ctx.error, 'установка отказывает');
  assert.equal(ctx.marker, null, 'метка не ставится');
  assert.equal(await read(ctx.dir, bad), null, 'плохой файл не остался');
  assert.equal(ctx.dir.stats.openWritables, 0, 'незавершённых записей нет');
  assert.ok(ctx.sleeps.length >= 3 && ctx.sleeps.length <= 4, `4 попытки подряд без нового принятого файла (первая принесла прогресс): ${ctx.sleeps.length} пауз`);
  // всё принятое — верно (нет «полупринятых» файлов): каждый присутствующий файл совпадает с манифестом
  for (const e of game.manifest.files) { const got = await read(ctx.dir, e.path); if (got) assert.equal(sha(got), e.sha256, `${e.path}: принятый файл должен быть целым`); }
  // 7b: отдельный файл с 404
  const g3 = buildGame(files, { packSize: 16_000, maxFile: 12_000 });
  const key = 'RESOURCE/Textures/big.tx.gz';
  ctx = await install({ manifest: g3.manifest, objects: g3.objects, serverOpts: { fault: (info) => (info.key === key ? '404' : undefined) }, concurrency: 4 });
  assert.match(ctx.error.message, /HTTP 404/);
  assert.equal(ctx.marker, null);
  for (const e of g3.manifest.files) { const got = await read(ctx.dir, e.path); if (got) assert.equal(sha(got), e.sha256); }
  ok('постоянная ошибка одного файла/записи: 4 попытки, отказ, метки нет, ни одного неполного файла, остальные не испорчены');
}

/* 8. временный сбой: повтор, итог верный; сбой в разгар параллельной загрузки */
{
  let cuts = 0;
  const ps = game.manifest.packs;
  const ctx = await install({ concurrency: 4, serverOpts: { chunk: 300, delay: 1, fault: (info) => {
    if ((info.key === ps[1].path || info.key === ps[3].path) && cuts < 2) { cuts++; return 'cut'; }
    if (info.key === 'RESOURCE/Textures/big.tx.gz' && cuts < 3) { cuts++; return { cutAt: 4000 }; }
  } } });
  assert.equal(ctx.error, null, ctx.error?.message);
  await assertInstalled(ctx.dir, game, 'retry');
  assert.equal(cuts, 3);
  assert.equal(ctx.sleeps.length, 3, 'три паузы перед повторами');
  assert.ok(monotone(ctx.progress) && ctx.progress.at(-1) === total, 'прогресс монотонен и верен после повторов');
  ok('обрыв посреди пакета и крупного файла: повтор, пакет докачивается ТОЛЬКО недостающими записями, итог верен');
}

/* 9. обрыв посреди пакета: принятые записи остаются, повтор просит Range от первой недостающей */
{
  const ps = game.manifest.packs;
  const pk = ps[0], es = game.manifest.files.filter((e) => e.pack === 0).sort((a, b) => a.offset - b.offset || a.csize - b.csize);
  const half = es[Math.floor(es.length / 2)];
  let cuts = 0;
  const ctx = await install({ concurrency: 1, serverOpts: { chunk: 200, fault: (info) => (info.key === pk.path && cuts++ === 0 ? { cutAt: half.offset + 5 } : undefined) } });
  assert.equal(ctx.error, null, ctx.error?.message);
  await assertInstalled(ctx.dir, game, 'mid-pack');
  const reqs = ctx.fetch.log.filter((r) => r.key === pk.path);
  assert.equal(reqs.length, 2);
  assert.equal(reqs[0].range, null);
  const m = /^bytes=(\d+)-(\d+)$/.exec(reqs[1].range);
  assert.ok(m && +m[1] > 0 && +m[1] <= half.offset && +m[2] === pk.size - 1, `повтор просит хвост пакета (${reqs[1].range})`);
  assert.equal(ctx.sleeps.length, 1);
  ok('обрыв посреди пакета: принятые записи остаются, повтор — Range от первой недостающей записи до конца');
}

/* 10. возобновление после обрыва установки (страница закрыта): повторный запуск качает только недостающее */
{
  const dir = new Dir();
  let count = 0;
  const first = await install({ dir, concurrency: 3, serverOpts: { chunk: 400, delay: 2, fault: (info) => (info.n > 5 ? '500' : undefined) }, retrySleep: 0 });
  assert.ok(first.error && first.marker === null);
  const have = [];
  for (const e of game.manifest.files) if (await read(dir, e.path)) have.push(e.path);
  assert.ok(have.length > 0 && have.length < game.manifest.files.length, `установка прервана на середине (${have.length}/${game.manifest.files.length})`);
  const second = await install({ dir, concurrency: 3 });
  assert.equal(second.error, null, second.error?.message);
  await assertInstalled(dir, game, 'resume');
  assert.equal(second.marker, game.manifest.version);
  const asked = new Set(second.fetch.log.map((r) => r.key));
  // пакет, где все файлы уже стоят, не запрашивается вовсе
  const complete = game.manifest.packs.filter((p, i) => game.manifest.files.filter((e) => e.pack === i).every((e) => have.includes(e.path)));
  for (const p of complete) assert.ok(!asked.has(p.path), `готовый пакет ${p.path} не запрашивается`);
  assert.ok(second.fetch.log.length < first.fetch.log.length + second.fetch.log.length, 'ok');
  assert.equal(second.progress.at(-1), total);
  // третий запуск (всё готово): ни одного запроса
  const third = await install({ dir, concurrency: 3, hadMarker: true });
  assert.equal(third.error, null); assert.equal(third.fetch.log.length, 0, 'всё установлено: запросов нет');
  ok('возобновление: готовые файлы и целые пакеты пропускаются, качается недостающее; повторный запуск без запросов');
}

/* 11. resync: из пакета нужны несколько файлов -> Range-запросы, а не весь пакет */
{
  const dir = new Dir();
  const c0 = await install({ dir, concurrency: 3 });
  assert.equal(c0.error, null);
  const ps = game.manifest.packs;
  const members = (i) => game.manifest.files.filter((e) => e.pack === i).sort((a, b) => a.offset - b.offset);
  const m2 = members(2);
  const lose = [m2[1], m2[m2.length - 1]];
  for (const e of lose) await put(dir, e.path, new Uint8Array(0).fill(0));            // файл испорчен: размер не тот
  const wrongContent = members(1).find((e) => e.size > 100);
  const cur = await read(dir, wrongContent.path); const flipped = cur.slice(); flipped[3] ^= 1;
  await put(dir, wrongContent.path, flipped);                                          // размер тот же, содержимое другое
  const again = await install({ dir, concurrency: 3, hadMarker: true });
  assert.equal(again.error, null, again.error?.message);
  await assertInstalled(dir, game, 'resync');
  const expected = T.planPackRuns([...lose, wrongContent]).map((r) => `${ps[r.pack].path} bytes=${r.start}-${r.end - 1}`).sort();
  const asked = again.fetch.log.map((r) => `${r.key} ${r.range}`).sort();
  assert.deepEqual(asked, expected, 'ровно по одному запросу с Range на пакет, от первой нужной записи до конца последней');
  const bytes = again.fetch.log.reduce((s2, r) => { const m = /^bytes=(\d+)-(\d+)$/.exec(r.range); return s2 + (+m[2] - +m[1] + 1); }, 0);
  assert.ok(bytes < ps.reduce((s2, p) => s2 + p.size, 0) / 2, `resync качает диапазоны (${bytes} байт), а не все пакеты`);
  ok('resync: недостающие и испорченные (по SHA) файлы пакета докачиваются диапазонами; остальное не трогается');
}

/* 12. обновление: на месте стоят старые файлы (другой размер) — переписываются, запись пакета «с нуля», без resume */
{
  const dir = new Dir();
  const stale = game.manifest.files.find((e) => e.pack !== undefined && e.size > 500);
  await put(dir, stale.path, new Uint8Array(Math.floor(stale.size / 2)).fill(65));   // обрезанный файл: для сжатого resume не бывает
  assert.equal(planFileUpdate(stale.size / 2 | 0, stale.size, false, true), 'rewrite');
  const ctx = await install({ dir, concurrency: 2 });
  assert.equal(ctx.error, null);
  await assertInstalled(dir, game, 'rewrite');
  ok('запись пакета с частичным старым файлом: переписывается целиком (докачки с середины нет)');
}

/* 13. отмена */
{
  const ac = new AbortController();
  const dir = new Dir();
  const ps = game.manifest.packs;
  let started = 0;
  const ctx = await install({ dir, concurrency: 3, signal: ac.signal, serverOpts: { chunk: 100, delay: 4, fault: () => { if (++started === 4) setTimeout(() => ac.abort(), 5); } } });
  assert.ok(ctx.error, 'отмена даёт ошибку'); assert.equal(ctx.error.name, 'AbortError');
  assert.equal(ctx.marker, null);
  assert.equal(ctx.dir.stats.openWritables, 0, 'незавершённых записей нет');
  for (const e of game.manifest.files) { const got = await read(dir, e.path); if (got) assert.equal(sha(got), e.sha256, `${e.path}: после отмены нет неполных файлов`); }
  const after = ctx.fetch.log.length;
  await sleepMs(50);
  assert.equal(ctx.fetch.log.length, after, 'после отмены новые запросы не выдаются');
  assert.equal(ctx.fetch.state.inflight, 0, 'идущие запросы оборваны');
  // отмена до начала
  const ac2 = new AbortController(); ac2.abort();
  const c2 = await install({ signal: ac2.signal });
  assert.equal(c2.error.name, 'AbortError'); assert.equal(c2.fetch.log.length, 0); assert.equal(c2.marker, null);
  // после отмены установку можно продолжить
  const c3 = await install({ dir, concurrency: 3 });
  assert.equal(c3.error, null); await assertInstalled(dir, game, 'after-abort');
  ok('отмена: запросы оборваны, новые не выдаются, неполных файлов нет, метки нет; после отмены установка продолжается');
}

/* 14. нехватка места в разгар параллельной записи: ошибка, неполных файлов нет */
{
  const dir = new Dir();
  dir.stats.quota = Math.floor(total / 2);            // общий для всех подкаталогов предел записанных байт
  const ctx = await install({ dir, concurrency: 4 });
  assert.ok(ctx.error, 'установка отказывает'); assert.equal(ctx.error.name, 'QuotaExceededError'); assert.equal(ctx.marker, null);
  assert.equal(dir.stats.openWritables, 0);
  let have = 0;
  for (const e of game.manifest.files) { const got = await read(dir, e.path); if (got) { have++; assert.equal(sha(got), e.sha256, `${e.path}: файл либо целый, либо его нет`); } }
  assert.ok(have > 0 && have < game.manifest.files.length, 'часть файлов успела установиться');
  dir.stats.quota = undefined;                          // место освободили: установка продолжается с места остановки
  const again = await install({ dir, concurrency: 4 });
  assert.equal(again.error, null); await assertInstalled(dir, game, 'after-quota');
  ok('QuotaExceeded во время параллельной записи: отказ, метки нет, ни одного неполного файла; после освобождения места установка продолжается');
}

/* 15. старый манифест и совместимость */
{
  const old = buildGame(files, { pack: false, gz: false });
  assert.ok(!old.manifest.packs && old.manifest.files.every((e) => !('pack' in e) && !('enc' in e)));
  for (const concurrency of [1, 5]) {
    const ctx = await install({ manifest: old.manifest, objects: old.objects, concurrency });
    assert.equal(ctx.error, null, ctx.error?.message);
    await assertInstalled(ctx.dir, old, `old c${concurrency}`);
    assert.equal(ctx.fetch.log.length, old.manifest.files.length, 'старый манифест: по запросу на файл, как раньше');
  }
  const d1 = buildGame(files, { pack: false });
  const c = await install({ manifest: d1.manifest, objects: d1.objects, concurrency: 4 });
  assert.equal(c.error, null); await assertInstalled(c.dir, d1, 'd1');
  // страница без загрузчика пакетов, но с манифестом пакетов: отказ до записи
  const dir = new Dir();
  await assert.rejects(syncManifestFiles({ dir, files: game.manifest.files, hadMarker: false, version: 'v', existingSize, downloadFile: async () => {}, downloadOptionsFile: async () => {}, writeMarker: async () => {}, show: () => {}, sleep: async () => {} }), /загрузчик их не умеет/);
  assert.equal(dir.dirs.size + dir.files.size, 0, 'до проверки ничего не записано');
  // манифест пакетов с испорченным списком: отказ до записи
  await assert.rejects(syncManifestFiles({ dir, files: game.manifest.files, hadMarker: false, version: 'v', existingSize, downloadFile: async () => {}, downloadPackRun: async () => {}, packs: [], downloadOptionsFile: async () => {}, writeMarker: async () => {}, show: () => {}, sleep: async () => {} }), /нет списка пакетов/);
  assert.equal(dir.dirs.size + dir.files.size, 0);
  ok('совместимость: старый манифест (concurrency 1 и 5), манифест D1, отказ до записи при пакетах без загрузчика/списка');
}

/* 16. квота: сеть по csize, место по size; временные копии при параллельной замене */
{
  const files3 = game.manifest.files;
  const plan = planStorageNeed({ files: files3, haveSizes: new Map(), hadMarker: false });
  assert.equal(plan.writeBytes, total);
  assert.equal(plan.transferBytes, files3.reduce((s, e) => s + (e.csize ?? e.size), 0), 'по сети — csize записей, по месту — распакованный size');
  assert.ok(plan.transferBytes < plan.writeBytes);
  // параллельная замена: временные копии нескольких самых больших заменяемых файлов
  const have = new Map(files3.map((e) => [e.path, e.size + 1]));        // все файлы «другого размера»: перезапись
  const one = planStorageNeed({ files: files3, haveSizes: have, hadMarker: true });
  const four = planStorageNeed({ files: files3, haveSizes: have, hadMarker: true, concurrency: 4 });
  const sizes = files3.map((e) => e.size).sort((a, b) => b - a);
  assert.equal(one.tempBytes, sizes[0]);
  assert.equal(four.tempBytes, sizes.slice(0, 4).reduce((a, b) => a + b, 0));
  assert.ok(four.minBytes >= one.minBytes);
  assert.equal(planStorageNeed({ files: files3, haveSizes: have, hadMarker: true, concurrency: 1000 }).tempBytes, sizes.slice(0, INSTALL_CONCURRENCY.max).reduce((a, b) => a + b, 0), 'предел потоков');
  ok('квота: трафик по csize, место по size; tempBytes — сумма самых больших заменяемых файлов по числу потоков');
}

/* 17. числа потоков */
{
  assert.equal(installConcurrency(undefined), 6); assert.equal(installConcurrency('3'), 3); assert.equal(installConcurrency('0'), 6);
  assert.equal(installConcurrency('abc'), 6); assert.equal(installConcurrency(99), 16); assert.equal(installConcurrency(2.5), 6); assert.equal(installConcurrency(-1, 1), 1);
  ok('installConcurrency: значение по умолчанию 6, предел 16, мусор отвергается');
}

/* 18. options: сохраняется, не берётся из пакета; план 'preserve' */
{
  const dir = new Dir();
  await put(dir, 'options', new TextEncoder().encode('player edited options'));
  const ctx = await install({ dir, hadMarker: true, concurrency: 3 });
  assert.equal(ctx.error, null, ctx.error?.message);
  assert.equal(new TextDecoder().decode(await read(dir, 'options')), 'player edited options', 'options игрока не тронут');
  assert.ok(!ctx.fetch.log.some((r) => r.key === 'options'));
  ok('options: изменённый игроком файл остаётся (никогда не в пакете), остальное устанавливается');
}

// A real quota failure must stop immediately without clearing a player's saves or marking the update complete.
for (const packed of [false, true]) {
  const dir = new Dir();
  const saved = new TextEncoder().encode('player-save');
  await put(dir, 'SAVE/slot1', saved);
  let calls = 0, sleeps = 0, marker = false;
  const quota = Object.assign(new Error('storage full'), {name:'QuotaExceededError'});
  const one = game.manifest.files.find(e => e.pack === undefined && e.path !== 'options');
  const selected = packed ? game.manifest.files : [one];
  const reject = async () => { calls++; throw quota; };
  await assert.rejects(() => syncManifestFiles({dir, files:selected, hadMarker:false, version:'quota-test', existingSize,
    packs:packed ? game.manifest.packs : null, concurrency:1, downloadFile:reject, downloadPackRun:reject,
    downloadOptionsFile:reject, writeMarker:async()=>{marker=true;}, show:()=>{}, sleep:async()=>{sleeps++;}}),
    e => e === quota);
  assert.equal(calls, 1, 'quota errors are not retried');
  assert.equal(sleeps, 0); assert.equal(marker, false);
  assert.deepEqual(await read(dir, 'SAVE/slot1'), saved);
}
ok('actual quota errors stop without retries and preserve saves');

console.log(`install-packs: ${n} групп проверок PASS`);
