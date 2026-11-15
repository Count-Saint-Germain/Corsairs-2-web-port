/* D1b: brotli как кодирование передачи — web/brotli-decoder.mjs (WebAssembly-сборка официального декодера Google brotli
   1.2.1, web/vendor/brotli/k2br.wasm) и его подключение в web/game-transfer.mjs (`enc: "br"`).
   Без сети и без браузера: настоящий WebAssembly/TransformStream/Response из Node, хранилище с семантикой OPFS и «сервер»
   из tests/pack_fixture.mjs. Эталон для сравнения — родной brotli Node (zlib): декодер должен давать те же байты.

   Доказывается: round-trip при любой нарезке чанков, качествах и окнах; усечённый, повреждённый поток и лишние байты
   после конца; «бомба» (выход больше size записи) обрывается ДО лишних байт; окно больше 4 МиБ отвергается; WebAssembly
   сверяется с SHA-256, зашитым в модуль; память декодера не растёт от числа потоков (в том числе оборванных); ленивая
   загрузка и отказ ДО записи; одиночные файлы и записи пакетов (gzip, br и «как есть» вперемешку), восстановление по Range.
     node tests/test_brotli_transfer.mjs */
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import fs from 'node:fs';
import { brotliCompressSync, brotliDecompressSync, constants as Z, gzipSync } from 'node:zlib';
import * as T from '../web/game-transfer.mjs';
import { BrotliDecodeError, K2BR_WASM_PATH, K2BR_WASM_SHA256, brotliWindowBits, loadBrotliDecoder } from '../web/brotli-decoder.mjs';
import { syncManifestFiles, validateManifestFiles } from '../web/save-protection.mjs';
import { Dir, buildGame, existingSize, fileHandle, noise, pseudo, read, removeFile, server, sha, wire } from './pack_fixture.mjs';

let n = 0;
const ok = (name) => { n++; console.log('ok - ' + name); };
const wasmBytes = fs.readFileSync(new URL(K2BR_WASM_PATH, new URL('../web/brotli-decoder.mjs', import.meta.url)));
const br = (data, q = 9, w = 22) => brotliCompressSync(data, { params: { [Z.BROTLI_PARAM_QUALITY]: q, [Z.BROTLI_PARAM_LGWIN]: w, [Z.BROTLI_PARAM_SIZE_HINT]: data.length } });
const same = (a, b) => a.length === b.length && Buffer.compare(Buffer.from(a), Buffer.from(b)) === 0;
const structured = (len, seed) => { const o = new Uint8Array(len), h = len >> 1; o.set(pseudo(h, seed)); o.set(noise(len - h, seed), h); return o; };
const text = (len) => { const w = ['alpha', 'beta', 'gamma', 'delta', 'ship', 'cannon', 'sail', 'rope', '\n']; let s = '', i = 0; while (s.length < len) s += w[(i * 7 + (i >> 3)) % w.length] + ' ', i++; return new TextEncoder().encode(s.slice(0, len)); };

const dec = await loadBrotliDecoder();

/** Пропускает `comp` через поток декодера кусками chunkSize (или функцией); возвращает {out, chunks, error}. */
async function run(comp, { chunk = 65536, opts = {}, d = dec } = {}) {
  const ts = d.createStream(opts), w = ts.writable.getWriter(), r = ts.readable.getReader();
  const parts = []; let readErr = null;
  const pump = (async () => { try { for (;;) { const { done, value } = await r.read(); if (done) break; parts.push(value); } } catch (e) { readErr = e; } })();
  let err = null;
  try {
    let i = 0, k = 0;
    while (i < comp.length) { const c = typeof chunk === 'function' ? chunk(k++) : chunk; await w.write(comp.subarray(i, i + c)); i += c; }
    await w.close();
  } catch (e) { err = e; }
  await pump;
  err = err || readErr;
  const out = Buffer.concat(parts);
  return { out, chunks: parts.length, error: err };
}

/* 1. сам файл декодера: SHA-256, нет импортов, экспорты; подмена не запускается */
{
  assert.equal(createHash('sha256').update(wasmBytes).digest('hex'), K2BR_WASM_SHA256, 'зашитый SHA-256 = SHA-256 файла k2br.wasm');
  const m = new WebAssembly.Module(wasmBytes);
  assert.deepEqual(WebAssembly.Module.imports(m), [], 'у декодера нет импортов: ни сети, ни eval, ни JS-функций');
  const names = WebAssembly.Module.exports(m).map((e) => e.name).sort();
  assert.deepEqual(names, ['k2br_avail_in', 'k2br_close', 'k2br_error', 'k2br_feed', 'k2br_heap_used', 'k2br_in_ptr', 'k2br_open',
    'k2br_out_ptr', 'k2br_produced', 'k2br_run', 'k2br_version', 'memory']);
  assert.equal(dec.version, 0x1002001, 'brotli 1.2.1');
  await assert.rejects(loadBrotliDecoder({ loadWasm: async () => wasmBytes.map((b, i) => (i === 100 ? b ^ 1 : b)) }), /SHA-256/);
  await assert.rejects(loadBrotliDecoder({ expectedSha256: '0'.repeat(64) }), /SHA-256/);
  await assert.rejects(loadBrotliDecoder({ loadWasm: async () => { throw new Error('HTTP 404'); } }), /404/);
  const saved = globalThis.WebAssembly; globalThis.WebAssembly = undefined;
  try { await assert.rejects(loadBrotliDecoder(), /WebAssembly/); } finally { globalThis.WebAssembly = saved; }
  ok('декодер: SHA-256 файла совпадает с зашитым, нет импортов, подмена/отсутствие WebAssembly/сбой загрузки отвергаются');
}

/* 2. окно из первого байта: сверка с настоящим кодировщиком */
{
  for (const w of [10, 12, 16, 17, 18, 20, 22, 23, 24]) {
    const first = br(structured(200_000, w), 5, w)[0];
    assert.equal(brotliWindowBits(first), w, `окно ${w}`);
  }
  assert.equal(brotliWindowBits(0x00), 16);
  assert.equal(brotliWindowBits(0x11), 0, 'расширение «большое окно» не поддержано: 0');
  ok('brotliWindowBits читает окно из первого байта потока (10..24) так же, как кодировщик его пишет');
}

/* 3. round-trip: данные x качества x окна x нарезка */
{
  const samples = { one: new Uint8Array([42]), text1k: text(1000), text200k: text(200_000), structured: structured(1_500_000, 3),
    noise: noise(300_000, 4), zeros: new Uint8Array(5_000_000), dup: Uint8Array.from({ length: 400_000 }, (_, i) => (i * 31) & 0xff) };
  let cases = 0;
  for (const [name, data] of Object.entries(samples)) {
    for (const [q, w] of [[0, 16], [1, 18], [5, 22], [9, 22], [11, 22], [9, 20]]) {
      if (q === 11 && data.length > 1_000_000) continue;       // q11 медленный: крупное только на q9
      const c = br(data, q, w);
      for (const chunk of [1, 3, 1000, 65536, 1 << 20, (k) => 1 + ((k * 7919) % 5000)]) {
        if (chunk === 1 && c.length > 3000) continue;
        const r = await run(c, { chunk });
        assert.equal(r.error, null, `${name} q${q} w${w}: ${r.error}`);
        assert.ok(same(r.out, data), `${name} q${q} w${w} chunk=${typeof chunk}`);
        cases++;
      }
    }
  }
  const c = br(samples.structured, 9, 22);
  assert.ok(same(brotliDecompressSync(c), (await run(c)).out), 'совпадает с родным декодером Node');
  ok(`round-trip: ${cases} сочетаний (данные x качество x окно x нарезка чанков, до 1 байта) равны исходным и родному декодеру Node`);
}

/* 4. большой файл с несколькими метаблоками: память ограничена, вывод порциями */
{
  const big = structured(13_000_000, 9);
  const c = br(big, 9, 22);
  const before = dec.memory.buffer.byteLength;
  const r = await run(c, { opts: { maxOutput: big.length } });
  assert.equal(r.error, null);
  assert.ok(same(r.out, big));
  assert.ok(r.chunks >= big.length / (256 * 1024) / 2, `вывод порциями (${r.chunks} кусков)`);
  assert.ok(dec.memory.buffer.byteLength - before < 24 * 1048576, `рост памяти ${(dec.memory.buffer.byteLength - before) / 1048576} МиБ`);
  ok(`13 МБ (${r.chunks} кусков вывода): верно, память wasm ${(dec.memory.buffer.byteLength / 1048576).toFixed(1)} МиБ`);
}

/* 5. усечённый и повреждённый поток, лишние байты */
{
  const data = structured(120_000, 5), c = br(data, 9, 22);
  let badTrunc = 0;
  for (let cut = 0; cut < c.length; cut += Math.max(1, Math.floor(c.length / 60))) {
    const r = await run(c.subarray(0, cut), { opts: { maxOutput: data.length } });
    assert.ok(r.error instanceof BrotliDecodeError || r.error, `усечение до ${cut} принято`);
    if (!r.error) badTrunc++;
  }
  assert.equal(badTrunc, 0);
  assert.ok((await run(c.subarray(0, c.length - 1))).error, 'без последнего байта — ошибка');
  assert.match(String((await run(c.subarray(0, c.length - 1))).error.message), /оборван|испорчен/);
  let silent = 0, errors = 0;
  for (let i = 0; i < 80; i++) {
    const bad = Buffer.from(c); bad[(i * 2654435761) % bad.length] ^= 1 << (i % 8);
    const r = await run(bad, { opts: { maxOutput: data.length } });
    if (r.error) { errors++; assert.ok(r.error instanceof BrotliDecodeError, String(r.error)); } else if (same(r.out, data)) silent++;
  }
  assert.equal(silent, 0, 'повреждение, которое осталось незамеченным и дало те же байты, невозможно для изменённого бита');
  assert.ok(errors >= 1);
  for (const tail of [[0], [0, 0, 0, 0], Array.from({ length: 300 }, (_, i) => i)]) {
    const t = Buffer.concat([c, Buffer.from(tail)]);
    assert.match(String((await run(t, { chunk: 1 << 20 })).error?.message), /лишние байты/, 'хвост в том же чанке');
    assert.match(String((await run(t, { chunk: c.length })).error?.message), /лишние байты/, 'хвост отдельным чанком');
    assert.match(String((await run(t, { chunk: 1000 })).error?.message), /лишние байты/, 'хвост при мелких чанках');
  }
  assert.ok((await run(new Uint8Array(0))).error, 'пустой вход — не поток brotli');
  assert.ok((await run(Buffer.from('not brotli at all, just text'))).error);
  ok(`усечение (60 точек) отвергается; из 80 испорченных битов ${errors} поймал сам декодер, остальные дают другие байты (их ловит SHA-256); лишние байты после конца отвергаются`);
}

/* 6. «бомба»: вывод больше size обрывается ДО лишних байт */
{
  const bomb = br(new Uint8Array(256 * 1024 * 1024), 5, 22);
  assert.ok(bomb.length < 1000, `256 МиБ нулей сжаты в ${bomb.length} байт`);
  const t0 = performance.now();
  const r = await run(bomb, { opts: { maxOutput: 1 << 20 } });
  assert.match(String(r.error?.message), /длиннее ожидаемого/);
  assert.ok(r.out.length <= 1 << 20, `потребителю отдано ${r.out.length} байт при пределе 1 МиБ`);
  assert.ok(performance.now() - t0 < 2000, 'остановка быстрая');
  // предел ровно по размеру: принимается; на байт меньше — отказ
  const exact = br(structured(50_000, 2), 9, 22), want = 50_000;
  assert.equal((await run(exact, { opts: { maxOutput: want } })).error, null);
  assert.match(String((await run(exact, { opts: { maxOutput: want - 1 } })).error?.message), /длиннее ожидаемого/);
  ok('бомба 256 МиБ -> отказ при пределе 1 МиБ без передачи лишнего; предел точный по байту');
}

/* 7. окно больше разрешённого отвергается ДО распаковки */
{
  const data = structured(5_000_000, 6);
  for (const w of [23, 24]) {
    const c = br(data, 5, w);
    assert.equal(brotliWindowBits(c[0]), w);
    const r = await run(c);
    assert.match(String(r.error?.message), /окно/);
    assert.equal(r.out.length, 0, 'ни одного байта вывода');
  }
  const c22 = br(data, 5, 22);
  assert.equal((await run(c22)).error, null);
  const r24 = await run(br(data, 5, 24), { opts: { maxWindowBits: 24 } });      // явное разрешение (не по умолчанию)
  assert.equal(r24.error, null); assert.ok(same(r24.out, data));
  ok('окно 23/24 бит отвергается (предел по умолчанию 22 = 4 МиБ), 22 принимается, предел настраивается явно');
}

/* 8. память: потоки, ошибки и отмены не копят кучу; параллельные потоки не мешают друг другу */
{
  const data = structured(300_000, 8), c = br(data, 5, 22);
  const cycle = async () => {
    assert.ok(same((await run(c)).out, data));
    assert.ok((await run(c.subarray(0, c.length >> 1))).error);                   // усечённый
    const ts = dec.createStream({ maxOutput: data.length }), w = ts.writable.getWriter(), r = ts.readable.getReader();
    const wp = w.write(c.subarray(0, 4000)).catch(() => {});                     // отмена посреди потока
    await r.read().catch(() => {}); await r.cancel().catch(() => {}); await wp;
    const bomb = await run(br(new Uint8Array(40_000_000), 1, 22), { opts: { maxOutput: 5000 } });
    assert.ok(bomb.error);
  };
  for (let i = 0; i < 5; i++) await cycle();
  const heap0 = dec.heapUsed(), mem0 = dec.memory.buffer.byteLength;
  for (let i = 0; i < 60; i++) await cycle();
  assert.equal(dec.heapUsed(), heap0, 'число занятых блоков кучи не растёт от повторов (всё освобождается)');
  assert.equal(dec.memory.buffer.byteLength, mem0, 'память wasm не растёт');
  // шесть потоков одновременно, чанки перемежаются
  const sets = [0, 1, 2, 3, 4, 5].map((i) => structured(400_000 + i * 50_000, 20 + i));
  const results = await Promise.all(sets.map((d, i) => run(br(d, 9, 22), { chunk: 900 + i * 111 })));
  results.forEach((r, i) => { assert.equal(r.error, null); assert.ok(same(r.out, sets[i]), `поток ${i}`); });
  assert.ok(dec.memory.buffer.byteLength < 64 * 1048576, `память wasm после 6 параллельных потоков: ${(dec.memory.buffer.byteLength / 1048576).toFixed(1)} МиБ`);
  ok(`65 повторов (успех, усечение, отмена, бомба): куча стабильна (${(dec.heapUsed() / 1024).toFixed(0)} КиБ); 6 параллельных потоков верны`);
}

/* ---- интеграция с game-transfer.mjs ---- */
const mk = (path, data, enc = 'br', extra = {}) => {
  const rec = enc === 'br' ? br(data, 9, 22) : gzipSync(data, { level: 6 });
  return { entry: { path, size: data.length, sha256: sha(data), enc, csize: rec.length, ...extra }, rec };
};
async function one({ entry, rec, fetchImpl, dir = new Dir(), decoders }) {
  return T.downloadPackedFile({ entry, url: 'http://t/game/' + T.remotePath(entry), fetchImpl: fetchImpl || server({ [T.remotePath(entry)]: rec }), decoders,
    openWritable: async () => (await fileHandle(dir, entry.path, true)).createWritable(), discard: () => removeFile(dir, entry.path) });
}

/* 9. ленивая загрузка, отказ до записи, имя объекта */
{
  const f = (enc) => ({ path: 'a', size: 5, sha256: '0'.repeat(64), enc });
  assert.equal(T.remotePath({ path: 'RESOURCE/x.gm', enc: 'br' }), 'RESOURCE/x.gm.br');
  assert.equal(T.transferSize({ path: 'a', size: 100, enc: 'br', csize: 40 }), 40);
  assert.equal(T.entryEncoding({ path: 'a', enc: 'br' }), 'br');
  assert.throws(() => T.entryEncoding({ path: 'a', enc: 'zstd' }), /неподдерживаемое/);
  let loads = 0;
  const spy = async () => { loads++; return dec; };
  const target = { brotli: null };
  await T.prepareDecoders([{ path: 'a', size: 1 }, f('gzip'), f(null), f('identity')], { loadBrotli: spy, decoders: target });
  assert.equal(loads, 0, 'манифест без br ничего не загружает');
  assert.equal(target.brotli, null);
  await T.prepareDecoders([f('gzip'), f('br'), f('br')], { loadBrotli: spy, decoders: target });
  await T.prepareDecoders([f('br')], { loadBrotli: spy, decoders: target });
  assert.equal(loads, 1, 'декодер грузится один раз');
  await assert.rejects(T.prepareDecoders([f('br')], { loadBrotli: async () => { throw new Error('HTTP 404 k2br.wasm'); }, decoders: { brotli: null } }),
    /декодер brotli.*404/);
  await assert.rejects(T.prepareDecoders([f('br')], { loadBrotli: async () => { throw new Error('SHA-256 не совпадает'); }, decoders: { brotli: null } }), /SHA-256/);
  assert.deepEqual(T.unsupportedEncodings([f('br')]), []);
  const saved = globalThis.WebAssembly; globalThis.WebAssembly = undefined;
  try { assert.deepEqual(T.unsupportedEncodings([f('br'), f('gzip')]), ['br']); } finally { globalThis.WebAssembly = saved; }
  // распаковщик не подготовлен: отказ ДО любой записи
  const data = structured(20_000, 1), { entry, rec } = mk('t/a.gm', data);
  const dir = new Dir();
  await assert.rejects(one({ entry, rec, dir, decoders: { brotli: null } }), /не загружен/);
  assert.equal(dir.stats.writes + dir.stats.commits, 0);
  ok('ленивая загрузка (один раз, и только если есть br), отказ при сбое загрузки и без WebAssembly, незнакомое enc, .br-имя');
}

/* 10. одиночный файл br: успех и все отказы; файл не остаётся */
{
  await T.prepareDecoders([{ path: 'x', size: 1, enc: 'br' }]);          // настоящая загрузка файла .wasm
  const data = structured(900_000, 12), { entry, rec } = mk('t/big.gm', data);
  const dir = new Dir(); let progress = 0;
  await T.downloadPackedFile({ entry, url: 'http://t/game/t/big.gm.br', fetchImpl: server({ 't/big.gm.br': rec }, { chunk: 777 }),
    onBytes: (k) => { progress += k; }, openWritable: async () => (await fileHandle(dir, entry.path, true)).createWritable(), discard: () => removeFile(dir, entry.path) });
  assert.ok(same(await read(dir, 't/big.gm'), data));
  assert.equal(progress, data.length, 'прогресс в распакованных байтах');
  assert.ok(dir.stats.writes > 3, 'пишется чанками, не целиком');

  const cases = [
    ['неверный SHA', { ...entry, sha256: sha(new Uint8Array(1)) }, rec, /SHA-256/],
    ['size больше', { ...entry, size: entry.size + 1, sha256: entry.sha256 }, rec, /после распаковки/],
    ['size меньше (бомба в записи)', { ...entry, size: 1000 }, rec, /длиннее/],
    ['csize меньше', { ...entry, csize: rec.length - 1 }, rec, /длиннее манифеста/],
    ['csize больше', { ...entry, csize: rec.length + 1 }, rec, /короче манифеста/],
    ['усечённый', entry, rec.subarray(0, rec.length - 5), /оборван|короче/],
    ['испорченный', entry, Buffer.concat([rec.subarray(0, 100), Buffer.from([rec[100] ^ 0x55]), rec.subarray(101)]), /./],
    ['лишний хвост', { ...entry, csize: undefined }, Buffer.concat([rec, Buffer.from([1, 2, 3])]), /лишние байты/],
    ['gzip вместо brotli', entry, gzipSync(data), /./],
  ];
  for (const [name, e, body, re] of cases) {
    const d = new Dir();
    await assert.rejects(one({ entry: e, rec: body, dir: d }), re, name);
    assert.equal(await read(d, 't/big.gm'), null, `${name}: файл не остался`);
    assert.equal(d.stats.commits, 0, `${name}: close не вызывался`);
  }
  // хост добавил Content-Encoding к .br: fetch уже распаковал, дальше работают проверки размера и SHA
  const d2 = new Dir();
  await one({ entry, fetchImpl: server({ 't/big.gm.br': data }, { headers: { 'Content-Encoding': 'br' } }), dir: d2 });
  assert.ok(same(await read(d2, 't/big.gm'), data));
  const d3 = new Dir();
  await assert.rejects(one({ entry, fetchImpl: server({ 't/big.gm.br': structured(900_000, 13) }, { headers: { 'Content-Encoding': 'br' } }), dir: d3 }), /SHA-256/);
  // бомба 256 МиБ нулей в записи на 10 КБ: отказ, в хранилище не больше пары чанков
  const small = structured(10_000, 3), bombEntry = { path: 't/bomb.gm', size: small.length, sha256: sha(small), enc: 'br' };
  const d4 = new Dir();
  await assert.rejects(one({ entry: bombEntry, rec: br(new Uint8Array(256 * 1024 * 1024), 5, 22), dir: d4 }), /длиннее/);
  assert.equal(await read(d4, 't/bomb.gm'), null);
  assert.equal(d4.stats.commits, 0);
  assert.ok(d4.stats.writes <= 2, `в хранилище записано ${d4.stats.writes} кусков до отказа`);
  ok('файл br: round-trip по чанкам и 9 видов порчи/несоответствия отвергаются без остатка; Content-Encoding хоста; бомба в записи');
}

/* 11. пакеты: записи gzip, br и «как есть» вперемешку; установка через настоящий syncManifestFiles; Range-восстановление */
{
  const files = {};
  for (let i = 0; i < 50; i++) files[`RESOURCE/Models/loc${i % 4}/m${String(i).padStart(3, '0')}.gm`] = structured(1500 + 97 * i, 30 + i);
  for (let i = 0; i < 12; i++) files[`RESOURCE/Textures/t${i}.tx`] = text(2500 + 313 * i);
  files['RESOURCE/Sounds/n.wav'] = noise(8000, 3);
  files['PROGRAM/s.c'] = new TextEncoder().encode('// tiny\n'.repeat(20));
  files['RESOURCE/Textures/big.tx'] = new Uint8Array(Buffer.concat(Array(5).fill(noise(40_000, 5))));   // период 40 КБ > окна gzip (32 КБ): br ≪ gzip
  files['options'] = new TextEncoder().encode('options-bytes'.repeat(20));
  const game = buildGame(files, { packSize: 16_000, maxFile: 12_000, br: true });
  const encs = new Map(); for (const e of game.manifest.files) encs.set(e.enc || 'raw', (encs.get(e.enc || 'raw') || 0) + 1);
  assert.ok(encs.get('br') > 5 && encs.get('gzip') > 0 && encs.get('raw') > 0, `смесь кодирований: ${[...encs]}`);
  assert.ok(game.manifest.files.some((e) => e.pack !== undefined && e.enc === 'br'), 'br-записи внутри пакетов');
  assert.ok(game.manifest.files.some((e) => e.pack === undefined && e.enc === 'br'), 'и отдельные .br-объекты');
  validateManifestFiles(game.manifest.files);
  T.validateManifestPacks(game.manifest.files, game.manifest.packs);

  async function install({ manifest = game.manifest, objects = game.objects, dir = new Dir(), hadMarker = false, serverOpts = {}, concurrency = 4 } = {}) {
    const fi = server(objects, { chunk: 700, ...serverOpts });
    const w = wire(T, { dir, fetchImpl: fi });
    let error = null;
    try {
      await T.prepareDecoders(manifest.files);
      await syncManifestFiles({ dir, files: manifest.files, hadMarker, version: manifest.version, existingSize, downloadFile: w.downloadFile,
        downloadPackRun: w.downloadPackRun, packs: manifest.packs, concurrency,
        downloadOptionsFile: async (d, entry, onBytes) => { const b = new Uint8Array(await (await fi('http://t/game/options', {})).arrayBuffer()); const fh = await fileHandle(d, 'options', true); const wr = await fh.createWritable(); await wr.write(b); await wr.close(); onBytes(b.length); },
        writeMarker: async () => {}, show: () => {}, sleep: async () => {} });
    } catch (e) { error = e; }
    return { error, dir, fi };
  }
  const check = async (dir, g = game) => { for (const e of g.manifest.files) { const got = await read(dir, e.path); assert.ok(got, e.path); assert.equal(sha(got), e.sha256, e.path); assert.equal(got.length, e.size); } };

  const r1 = await install();
  assert.equal(r1.error, null, String(r1.error));
  await check(r1.dir);
  assert.ok(r1.fi.state.maxInflight <= 4);
  const br0 = [...encs].find(([k]) => k === 'br')[1];

  // удалить несколько файлов из середины пакетов и докачать: запросы идут по Range, принимаются и br-записи
  const lost = game.manifest.files.filter((e) => e.pack !== undefined && e.enc === 'br').slice(2, 6).map((e) => e.path);
  for (const p of lost) await removeFile(r1.dir, p);
  const r2 = await install({ dir: r1.dir, hadMarker: true });
  assert.equal(r2.error, null, String(r2.error));
  await check(r2.dir);
  assert.ok(r2.fi.log.some((l) => l.range), 'докачка по Range');
  assert.ok(r2.fi.log.length < game.manifest.packs.length + 4, `запросов ${r2.fi.log.length}`);

  // порча br-записи внутри пакета: отказ, испорченного файла нет, принятые ДО неё целы
  const victim = game.manifest.files.filter((e) => e.pack !== undefined && e.enc === 'br')[3];
  const packName = game.manifest.packs[victim.pack].path;
  const bad = Buffer.from(game.objects[packName]);
  bad[victim.offset + (victim.csize >> 1)] ^= 0xFF;
  const r3 = await install({ objects: { ...game.objects, [packName]: bad }, concurrency: 1 });
  assert.ok(r3.error, 'порча записи пакета обнаружена');
  assert.equal(await read(r3.dir, victim.path), null, 'испорченный файл не остался');
  // усечённый пакет
  const r4 = await install({ objects: { ...game.objects, [packName]: game.objects[packName].subarray(0, victim.offset + 10) }, concurrency: 1 });
  assert.ok(r4.error);
  assert.equal(await read(r4.dir, victim.path), null);
  // манифест лжёт про size записи br (меньше): бомба-предел сработал
  const lying = { ...game.manifest, files: game.manifest.files.map((e) => (e.path === victim.path ? { ...e, size: 10 } : e)) };
  const r5 = await install({ manifest: lying, concurrency: 1 });
  assert.ok(r5.error); assert.equal(await read(r5.dir, victim.path), null);
  ok(`пакеты: gzip/br/raw вперемешку (${[...encs].map(([k, v]) => k + ' ' + v).join(', ')}), установка, Range-докачка (${r2.fi.log.length} запросов), порча/усечение/ложный size отвергнуты`);
}

console.log(`brotli-transfer: ${n} групп проверок PASS`);
