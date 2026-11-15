/* D1b: установка с brotli (`enc: "br"`) в настоящем OPFS эфемерного headless Chromium: WebAssembly-декодер
   (web/brotli-decoder.mjs + vendor/brotli/k2br.wasm) грузится страницей лениво, поток brotli, сделанный настоящим
   make_dist.write_game (кодировщик brotli, окно 4 МиБ), распаковывается в браузере и пишется в OPFS.
   Данные синтетические; чистый контекст, свободный порт loopback, сервер гасится; не профиль пользователя, не игра.

   Доказывается в настоящем браузере: чистая установка из манифеста с br/gzip/«как есть» (отдельные объекты и записи
   пакетов), байты в OPFS равны исходным (SHA-256 считает WebCrypto, независимо от кода страницы); декодер НЕ
   запрашивается, если в манифесте нет br, и запрашивается ровно один раз, если есть; подменённый .wasm отвергается
   ДО первой записи; порча/усечение/мусор/«бомба» в br-объекте и в записи пакета: отказ, файла в OPFS нет, метки нет;
   скорость распаковки (br wasm / gzip DecompressionStream / JS SHA-256) в Chromium; память wasm при 6 потоках.
     node tests/test_brotli_browser.mjs */
import assert from 'node:assert/strict';
import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { transferFixture } from './transfer_fixture.mjs';
import { brotliCompressSync, constants as Z, gzipSync } from 'node:zlib';
import { readFileSync, readdirSync, mkdtempSync, rmSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { fileURLToPath } from 'node:url';
import { resolve, dirname, join } from 'node:path';

const here = dirname(fileURLToPath(import.meta.url));
const webDir = resolve(here, '../web');
const root = resolve(here, '../../..');           // web-port
const playwrightDir = resolve(root, 'third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH = resolve(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');

/* ---- фикстуры через настоящий make_dist.write_game: плоская (br + gzip + raw), с пакетами, только gzip */
const tmp = mkdtempSync(join(tmpdir(), 'k2-d1b-browser-'));
process.once('exit', () => rmSync(tmp, { recursive: true, force: true }));
const layout = await transferFixture(tmp, {brotli: true});
assert.ok(layout.flat[0] >= 8 && layout.flat[1] >= 1, `flat: br и gzip вперемешку ${layout.flat}`);
assert.ok(layout.packs[0] >= 4 && layout.packs[2] >= 2, `packs: ${layout.packs}`);
assert.deepEqual(layout.gz[0], 0);
assert.equal(new Set(layout.versions).size, 1, 'version не зависит от кодека');
assert.ok(layout.wire[0] < layout.wire[2] * 0.9, `br передаёт меньше gzip: ${layout.wire}`);

/* ---- сервер: /m/<file> — модули страницы, /m/vendor/brotli/k2br.wasm, /<dist>/game/<ключ> */
const state = { dist: 'flat', mode: 'normal', key: '', at: null, wasm: 'good', requests: [], sent: 0 };
const wasmGood = readFileSync(join(webDir, 'vendor/brotli/k2br.wasm'));
const wasmBad = Buffer.from(wasmGood); wasmBad[wasmBad.length >> 1] ^= 1;
function walk(dir, base = '') {
  const out = [];
  for (const e of readdirSync(dir, { withFileTypes: true })) { const p = join(dir, e.name); if (e.isDirectory()) out.push(...walk(p, base + e.name + '/')); else out.push(base + e.name); }
  return out;
}
const served = {}; for (const d of ['flat', 'packs', 'gz']) served[d] = new Set(walk(join(tmp, d, 'game')));
const bombStream = brotliCompressSync(Buffer.alloc(200 << 20), {params: {[Z.BROTLI_PARAM_QUALITY]: 5, [Z.BROTLI_PARAM_LGWIN]: 22}});
assert.ok(bombStream.length > 20 && bombStream.length < 2000, `бомба: ${bombStream.length} байт`);

/* страница-помощник: тот же порядок, что port.js (prepareDecoders до записи, потом syncManifestFiles); модуль грузится в каждом
   новом документе заново, поэтому «декодер загружен лениво и один раз» проверяется честно по запросам к .wasm */
const HELPER = `
import * as T from '/m/game-transfer.mjs';
import * as S from '/m/save-protection.mjs';
export { T, S };
export const hex = async (buf) => [...new Uint8Array(await crypto.subtle.digest('SHA-256', buf))].map((b) => b.toString(16).padStart(2, '0')).join('');
const fh = async (dir, rel, create) => { const parts = rel.split('/'); for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create }); return dir.getFileHandle(parts.at(-1), { create }); };
const rm = async (d, rel) => { const parts = rel.split('/'); let x = d; for (const p of parts.slice(0, -1)) x = await x.getDirectoryHandle(p); await x.removeEntry(parts.at(-1)); };
const existingSize = async (dir, rel) => { try { return (await (await fh(dir, rel, false)).getFile()).size; } catch { return -1; } };
export const wipe = async (name) => { const root = await navigator.storage.getDirectory(); await root.removeEntry(name, { recursive: true }).catch(() => {}); };
export async function install(name, { concurrency = 6 } = {}) {
  const root = await navigator.storage.getDirectory();
  const dir = await root.getDirectoryHandle(name, { create: true });
  const manifest = await (await fetch('/game/manifest.json')).json();
  const files = S.validateManifestFiles(manifest.files);
  const events = { sleeps: [], marker: null, progress: 0, wrote: 0 };
  try {
    T.validateManifestPacks(files, manifest.packs);
    await T.prepareDecoders(files);
    await S.syncManifestFiles({ dir, files, hadMarker: false, version: manifest.version, existingSize, concurrency, packs: manifest.packs,
      async downloadFile(d, rel, size, from, onBytes, entry, ctx) {
        if (entry?.enc) {
          return T.downloadPackedFile({ entry, url: '/game/' + T.remotePath(entry).split('/').map(encodeURIComponent).join('/'), fetchImpl: fetch, onBytes, signal: ctx?.signal,
            openWritable: async () => { events.wrote++; return (await fh(d, rel, true)).createWritable(); }, discard: () => rm(d, rel) });
        }
        const res = await fetch('/game/' + rel.split('/').map(encodeURIComponent).join('/'), { signal: ctx?.signal });
        if (!res.ok) throw new Error(rel + ': HTTP ' + res.status);
        const w = await (await fh(d, rel, true)).createWritable(); events.wrote++;
        const reader = res.body.getReader();
        for (;;) { const { done, value } = await reader.read(); if (done) break; await w.write(value); onBytes(value.length); }
        await w.close();
      },
      async downloadPackRun(d, pack, entries, onBytes, onFile, ctx) {
        return T.downloadPackRun({ pack, entries, url: '/game/' + pack.path, fetchImpl: fetch, onBytes, onFile, signal: ctx?.signal,
          openWritable: async (e) => { events.wrote++; return (await fh(d, e.path, true)).createWritable(); }, discard: (e) => rm(d, e.path) });
      },
      async downloadOptionsFile(d, entry, onBytes) {
        const bytes = await S.fetchVerifiedOptions('/game/options', entry, fetch);
        const w = await (await fh(d, 'options', true)).createWritable(); await w.write(bytes); await w.close(); onBytes(bytes.length);
      },
      async writeMarker(v) { events.marker = v; },
      show(done) { events.progress = done; },
      async sleep(ms, path, err) { events.sleeps.push([path, err.name + ': ' + err.message.slice(0, 80)]); },
    });
  } catch (e) { events.error = e.name + ': ' + e.message; }
  events.state = {};
  for (const f of files) {
    try { const file = await (await fh(dir, f.path, false)).getFile(); events.state[f.path] = { size: file.size, sha: await hex(await file.arrayBuffer()) }; }
    catch { events.state[f.path] = null; }
  }
  events.manifest = manifest;
  return events;
}
export async function perf() {
  await T.prepareDecoders([{ path: 'x', size: 1, enc: 'br' }]);
  const get = async (n) => new Uint8Array(await (await fetch('/perf/' + n)).arrayBuffer());
  const raw = await get('raw'), gz = await get('gz'), b9 = await get('br9'), b11 = await get('br11');
  const dec = (await import('/m/brotli-decoder.mjs'));
  const d = await dec.loadBrotliDecoder({ loadWasm: () => dec.defaultLoadWasm() });
  const drain = async (ts, comp) => {
    const w = ts.writable.getWriter(), r = ts.readable.getReader(); let n = 0;
    const pump = (async () => { for (;;) { const { done, value } = await r.read(); if (done) break; n += value.length; } })();
    for (let i = 0; i < comp.length; i += 65536) await w.write(comp.subarray(i, i + 65536));
    await w.close(); await pump; return n;
  };
  const best = async (fn) => { let m = Infinity; for (let i = 0; i < 3; i++) { const t0 = performance.now(); await fn(); m = Math.min(m, performance.now() - t0); } return m; };
  const mbps = (ms) => raw.length / 1048576 / (ms / 1000);
  const out = { mb: raw.length / 1048576, ratio: { gz: gz.length / raw.length, br9: b9.length / raw.length, br11: b11.length / raw.length } };
  out.gzDS = mbps(await best(async () => { if (await drain(new DecompressionStream('gzip'), gz) !== raw.length) throw new Error('gz len'); }));
  out.br9 = mbps(await best(async () => { if (await drain(d.createStream({ maxOutput: raw.length }), b9) !== raw.length) throw new Error('br9 len'); }));
  out.br11 = mbps(await best(async () => { if (await drain(d.createStream({ maxOutput: raw.length }), b11) !== raw.length) throw new Error('br11 len'); }));
  out.shaJs = mbps(await best(async () => { const st = S.sha256Init(); for (let i = 0; i < raw.length; i += 65536) S.sha256Update(st, raw.subarray(i, i + 65536)); S.sha256Hex(st); }));
  out.shaSubtle = mbps(await best(async () => { await crypto.subtle.digest('SHA-256', raw); }));
  // дольше всего блокирует главный поток один вызов декодера: берём длину самого долгого шага (вызов transform на чанк 64 КиБ)
  let longest = 0;
  { const ts = d.createStream({ maxOutput: raw.length }), w = ts.writable.getWriter(), r = ts.readable.getReader();
    const pump = (async () => { for (;;) { const { done } = await r.read(); if (done) break; } })();
    for (let i = 0; i < b11.length; i += 65536) { const t0 = performance.now(); await w.write(b11.subarray(i, i + 65536)); longest = Math.max(longest, performance.now() - t0); }
    await w.close(); await pump; }
  out.longestWriteMs = longest;
  out.wasmMiB = d.memory.buffer.byteLength / 1048576;
  // весь конвейер: fetch + распаковка + JS SHA-256 + запись в OPFS (как при установке), gzip и br
  const root = await navigator.storage.getDirectory(); const dir = await root.getDirectoryHandle('d1b-perf', { create: true });
  const sha = await hex(raw);
  for (const [enc, name] of [['gzip', 'gz'], ['br', 'br11']]) {
    out['pipe_' + enc] = mbps(await best(async () => {
      await T.downloadPackedFile({ entry: { path: 'big.bin', size: raw.length, sha256: sha, enc, csize: (name === 'gz' ? gz : b11).length }, url: '/perf/' + name, fetchImpl: fetch,
        openWritable: async () => (await dir.getFileHandle('big.bin', { create: true })).createWritable(), discard: async () => {} });
    }));
  }
  await root.removeEntry('d1b-perf', { recursive: true });
  return out;
}
`;
const perfRaw = (() => { const o = new Uint8Array(24 * 1048576); let x = 1;   // ~четверть случайных байт среди повторяющегося рисунка: gzip около 50 %
  for (let i = 0; i < o.length; i++) { x = (Math.imul(x, 1103515245) + 12345) >>> 0; o[i] = (x >>> 16) % 4 === 0 ? x >>> 24 : 48 + ((i * 7 + (i >> 9)) % 40); }
  return o; })();
const perf = { raw: Buffer.from(perfRaw), gz: gzipSync(perfRaw, { level: 6 }),
  br9: brotliCompressSync(perfRaw, { params: { [Z.BROTLI_PARAM_QUALITY]: 9, [Z.BROTLI_PARAM_LGWIN]: 22 } }),
  br11: brotliCompressSync(perfRaw, { params: { [Z.BROTLI_PARAM_QUALITY]: 11, [Z.BROTLI_PARAM_LGWIN]: 22 } }) };
const server = createServer((req, res) => {
  const url = new URL(req.url, 'http://x'); const p = decodeURIComponent(url.pathname);
  const send = (code, body, type = 'application/octet-stream', extra = {}) => { res.writeHead(code, { 'Content-Type': type, 'Content-Length': body.length, ...extra }); res.end(body); };
  if (p === '/') return send(200, '<!doctype html><title>d1b</title>', 'text/html');
  if (p === '/m/vendor/brotli/k2br.wasm') { state.requests.push('WASM'); return send(200, state.wasm === 'bad' ? wasmBad : wasmGood, 'application/wasm'); }
  if (p.startsWith('/m/')) { const f = p.slice(3); if (!/^[\w-]+\.mjs$/.test(f)) return send(404, ''); return send(200, readFileSync(join(webDir, f)), 'text/javascript'); }
  if (p === '/h.mjs') return send(200, Buffer.from(HELPER), 'text/javascript');
  if (p.startsWith('/perf/')) return send(200, perf[p.slice(6)] || Buffer.alloc(0));
  if (p === '/__state') { Object.assign(state, JSON.parse(url.searchParams.get('s'))); state.requests = []; state.sent = 0; return send(200, 'ok', 'text/plain'); }
  if (p === '/__requests') return send(200, JSON.stringify({ requests: state.requests, sent: state.sent }), 'application/json');
  if (!p.startsWith('/game/')) return send(404, '');
  const key = p.slice(6);
  if (!served[state.dist].has(key)) return send(404, 'nope', 'text/plain');
  if (key !== 'manifest.json') state.requests.push(key + (req.headers.range ? ' [range]' : ''));
  let body = readFileSync(join(tmp, state.dist, 'game', key));
  const hit = state.key === key && state.mode !== 'normal';
  // порча постоянная: применяется к объекту целиком, и Range-повтор получает те же испорченные байты
  // `at`: смещение в объекте, куда попадает порча (запись пакета); без него — середина/конец/весь объект
  if (hit && state.mode === 'corrupt') { body = Buffer.from(body); body[state.at ?? body.length >> 1] ^= 0xff; }
  if (hit && state.mode === 'truncate') body = body.subarray(0, state.at ?? body.length - 30);
  if (hit && state.mode === 'junk') body = Buffer.concat([body, Buffer.from('JUNK')]);
  if (hit && state.mode === 'bomb') { if (state.at === null) body = bombStream; else { body = Buffer.from(body); bombStream.copy(body, state.at); } }
  if (req.headers.range && key !== 'manifest.json') {
    const m = /^bytes=(\d+)-(\d*)$/.exec(req.headers.range); const a = +m[1], b = m[2] === '' ? body.length - 1 : Math.min(+m[2], body.length - 1);
    if (a >= body.length) return send(416, '');
    const whole = body.length; body = body.subarray(a, b + 1);
    state.sent += body.length;
    res.writeHead(206, { 'Content-Type': 'application/octet-stream', 'Content-Length': body.length, 'Content-Range': `bytes ${a}-${b}/${whole}` });
    return res.end(body);
  }
  if (key !== 'manifest.json') state.sent += body.length;
  send(200, body);
});
await new Promise((ok, fail) => { server.once('error', fail); server.listen(0, '127.0.0.1', ok); })
  .catch((error) => { rmSync(tmp, {recursive:true, force:true}); throw error; });
const origin = `http://127.0.0.1:${server.address().port}`;
const set = (s) => fetch(`${origin}/__state?s=${encodeURIComponent(JSON.stringify(s))}`).then((r) => r.text());
const seen = () => fetch(`${origin}/__requests`).then((r) => r.json());

let browser;
try {
  browser = await chromium.launch({ headless: true });
  const context = await browser.newContext();        // эфемерный контекст
  const page = await context.newPage();
  page.on('pageerror', (e) => console.log('pageerror:', e.message));
  if (process.env.D1B_DEBUG) page.on('response', (r) => console.log('  ', r.status(), r.url().replace(origin, ''), r.headers()['content-length']));
  console.log('Chromium', browser.version());
  // каждый сценарий — в новом документе: модули и загруженный декодер начинаются с нуля
  const boot = async (s) => { await set(s); await page.goto(origin + '/'); await page.evaluate(async () => { window.H = await import('/h.mjs'); }); };
  const run = (name, opts) => page.evaluate(([n, o]) => window.H.install(n, o), [name, opts || {}]);
  const wipe = (name) => page.evaluate((n) => window.H.wipe(n), name);

  const check = (ev, label) => {
    for (const f of ev.manifest.files) {
      assert.ok(ev.state[f.path], `${label}: ${f.path} отсутствует в OPFS`);
      assert.equal(ev.state[f.path].size, f.size, `${label}: размер ${f.path}`);
      assert.equal(ev.state[f.path].sha, f.sha256, `${label}: SHA-256 ${f.path}`);
    }
  };
  const total = (ev) => ev.manifest.files.reduce((s, f) => s + f.size, 0);

  /* A. плоская раскладка: br + gzip + raw отдельными объектами, декодер запрошен один раз */
  await boot({ dist: 'flat', mode: 'normal', key: '', wasm: 'good' });
  let ev = await run('d1b-a');
  assert.equal(ev.error, undefined, ev.error); check(ev, 'A');
  assert.equal(ev.marker, ev.manifest.version);
  assert.equal(ev.progress, total(ev), 'A: прогресс = сумма распакованных размеров');
  let s = await seen();
  assert.equal(s.requests.filter((r) => r === 'WASM').length, 1, 'A: декодер brotli запрошен ровно один раз');
  for (const f of ev.manifest.files) assert.ok(s.requests.includes(f.enc === 'br' ? f.path + '.br' : f.enc ? f.path + '.gz' : f.path), `A: запрошен ${f.path}`);
  assert.equal(s.sent, ev.manifest.files.reduce((a, f) => a + (f.csize ?? f.size), 0), 'A: по сети ровно сумма csize/size');
  console.log(`ok - A плоская: ${ev.manifest.files.length} файлов (${ev.manifest.files.filter((f) => f.enc === 'br').length} br, ${ev.manifest.files.filter((f) => f.enc === 'gzip').length} gzip), ${(total(ev) / 1e6).toFixed(2)} МБ в OPFS, по сети ${(s.sent / 1e6).toFixed(2)} МБ (gzip-раскладка: ${(layout.wire[2] / 1e6).toFixed(2)} МБ)`);
  await wipe('d1b-a');

  /* B. с пакетами: br/gzip/raw внутри пакетов, 6 потоков */
  await boot({ dist: 'packs', mode: 'normal', key: '' });
  ev = await run('d1b-b');
  assert.equal(ev.error, undefined, ev.error); check(ev, 'B');
  s = await seen();
  assert.ok(ev.manifest.files.some((f) => f.pack !== undefined && f.enc === 'br'), 'B: br-записи внутри пакетов');
  assert.equal(s.requests.filter((r) => r === 'WASM').length, 1, 'B: декодер загружен один раз и на отдельные файлы, и на пакеты');
  console.log(`ok - B пакеты (${ev.manifest.packs.length} пакетов, ${s.requests.length - 1} запросов, 6 потоков): установка верна, по сети ${(s.sent / 1e6).toFixed(2)} МБ`);
  await wipe('d1b-b');

  /* C. gzip-only манифест: декодер brotli НЕ запрашивается (лениво) */
  await boot({ dist: 'gz', mode: 'normal', key: '' });
  ev = await run('d1b-c');
  assert.equal(ev.error, undefined, ev.error); check(ev, 'C');
  s = await seen();
  assert.ok(!s.requests.includes('WASM'), 'C: без br в манифесте декодер не запрашивается');
  console.log('ok - C манифест без br: k2br.wasm не запрашивался (лениво), установка верна');
  await wipe('d1b-c');

  /* D. подменённый .wasm: отказ ДО первой записи (ни одного файла, метки нет) */
  await boot({ dist: 'flat', mode: 'normal', key: '', wasm: 'bad' });
  ev = await run('d1b-d');
  assert.ok(ev.error && /SHA-256|декодер brotli/.test(ev.error), ev.error);
  assert.equal(ev.wrote, 0, 'D: ничего не записано');
  assert.equal(ev.marker, null);
  assert.ok(Object.values(ev.state).every((v) => v === null), 'D: в OPFS нет ни одного файла');
  s = await seen();
  assert.ok(s.requests.every((r) => r === 'WASM'), `D: после отказа игровые файлы не запрашивались (${s.requests})`);
  console.log(`ok - D подменённый .wasm отвергнут до записи (${ev.error.slice(0, 90)})`);
  await wipe('d1b-d');

  /* E. порча/усечение/мусор/бомба в br: отдельный объект и запись пакета */
  const packsManifest = JSON.parse(readFileSync(join(tmp, 'packs', 'game', 'manifest.json'), 'utf8'));
  const brPacked = packsManifest.files.find((f) => f.pack !== undefined && f.enc === 'br');
  const mid = brPacked.offset + (brPacked.csize >> 1);
  const targets = [['flat', 'RESOURCE/Models/Locations/a.gm.br', 'RESOURCE/Models/Locations/a.gm', null, ['corrupt', 'truncate', 'junk', 'bomb']],
    ['packs', packsManifest.packs[brPacked.pack].path, brPacked.path, { corrupt: mid, truncate: mid, bomb: brPacked.offset }, ['corrupt', 'truncate', 'bomb']]];
  for (const [dist, key, logical, ats, modes] of targets) {
    for (const mode of modes) {
      await boot({ dist, mode, key, at: ats ? ats[mode] : null, wasm: 'good' });
      ev = await run('d1b-bad', { concurrency: 1 });
      assert.ok(ev.error, `${dist}/${mode}: установка должна завершиться отказом`);
      assert.equal(ev.marker, null, `${dist}/${mode}: метка не ставится`);
      assert.equal(ev.state[logical], null, `${dist}/${mode}: ${logical} не остаётся в OPFS`);
      console.log(`ok - E ${dist} ${mode}: отказ (${ev.error.slice(0, 80)}), файла нет, метки нет`);
      await wipe('d1b-bad');
    }
  }

  /* F. скорость и блокировка главного потока в Chromium */
  await boot({ dist: 'flat', mode: 'normal', key: '', wasm: 'good' });
  const p = await page.evaluate(() => window.H.perf());
  const f1 = (x) => x.toFixed(0);
  console.log(`info - F Chromium, ${p.mb.toFixed(0)} МБ синтетики, МБ/с распакованных: gzip DecompressionStream ${f1(p.gzDS)} | brotli wasm q9 ${f1(p.br9)}, q11 ${f1(p.br11)} | SHA-256 JS страницы ${f1(p.shaJs)}, WebCrypto ${f1(p.shaSubtle)}`);
  console.log(`info - F конвейер fetch+распаковка+SHA+OPFS: gzip ${f1(p.pipe_gzip)} МБ/с, br ${f1(p.pipe_br)} МБ/с; сжатие gzip ${(100 * p.ratio.gz).toFixed(0)} %, br9 ${(100 * p.ratio.br9).toFixed(0)} %, br11 ${(100 * p.ratio.br11).toFixed(0)} %; самая долгая запись чанка 64 КиБ в декодер: ${p.longestWriteMs.toFixed(1)} мс; память wasm ${p.wasmMiB.toFixed(1)} МиБ`);
  assert.ok(p.br11 > 20 && p.pipe_br > 20, 'декодер brotli не должен быть заметно медленнее 20 МБ/с');
  assert.ok(p.longestWriteMs < 250, `один чанк блокирует главный поток ${p.longestWriteMs} мс`);
  console.log('game-transfer br (настоящий Chromium + OPFS): PASS');
} finally {
  if (browser) await browser.close();
  server.close();
  rmSync(tmp, { recursive: true, force: true });
}
