/* D1: сжатая установка в настоящем OPFS и DecompressionStream эфемерного headless Chromium
   (bundled Playwright из web-port/third_party/playwright; чистый контекст, не профиль пользователя;
   сервер слушает свободный порт loopback и гасится в конце). Данные синтетические: фикстуру собирает
   настоящий Node-сборщик make_dist.writeGame (gzip) — проверяется и то, что Chromium принимает
   именно наши потоки.

   Доказывается в настоящем браузере: чистая установка из смешанного манифеста (.gz + обычные файлы) через
   настоящий syncManifestFiles, байты в OPFS равны исходным (SHA-256 считает WebCrypto, независимо от
   кода страницы), по сети идёт меньше распакованного; обрыв соединения посреди файла + повтор; повреждённый
   и усечённый поток, поток с мусором в хвосте: отказ, файл не остаётся в OPFS, метка не ставится;
   хост, добавивший Content-Encoding: gzip к .gz; пропускная способность распаковки+SHA (для оценки CPU).
     node tests/test_game_transfer_browser.mjs
   Не запускает игру и не трогает данные игры. */
import assert from 'node:assert/strict';
import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { transferFixture } from './transfer_fixture.mjs';
import { readFileSync, readdirSync, statSync, mkdtempSync, rmSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { gzipSync } from 'node:zlib';
import { fileURLToPath } from 'node:url';
import { resolve, dirname, join } from 'node:path';

const here = dirname(fileURLToPath(import.meta.url));
const webDir = resolve(here, '../web');
const root = resolve(here, '../../..');           // web-port
const playwrightDir = resolve(root, 'third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH = resolve(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');

/* ---- фикстура игры через настоящий make_dist */
const tmp = mkdtempSync(join(tmpdir(), 'k2-d1-browser-'));
process.once('exit', () => rmSync(tmp, { recursive: true, force: true }));
const fixture = join(tmp, 'fixture');
const layout = await transferFixture(tmp, {brotli: false});
assert.deepEqual(layout.packed, ['PROGRAM/big.c', 'RESOURCE/Models/Locations/b.gm', 'RESOURCE/Models/c.an', 'RESOURCE/Textures/a.tx', 'engine.ini']);
assert.deepEqual(layout.raw, ['PROGRAM/s.c', 'RESOURCE/Sounds/noise.wav', 'RESOURCE/Sounds/x.ogg', 'options']);

/* ---- сервер */
const state = { mode: 'normal', key: '', requests: [], sent: 0 };
const big = (() => { // 48 МБ сжимаемых данных для оценки скорости, в памяти
  const o = new Uint8Array(48 * 1024 * 1024); let x = 1;
  for (let i = 0; i < o.length; i++) { x = (x * 1103515245 + 12345) >>> 0; o[i] = (x >>> 16) % 5 ? 65 + (i % 13) : x >>> 24; }
  return { raw: o, gz: gzipSync(o, { level: 6 }) };
})();
function walk(dir, base = '') {
  const out = [];
  for (const e of readdirSync(dir, { withFileTypes: true })) { const p = join(dir, e.name); if (e.isDirectory()) out.push(...walk(p, base + e.name + '/')); else out.push(base + e.name); }
  return out;
}
const served = new Set(walk(join(fixture, 'game')));
const server = createServer((req, res) => {
  const url = new URL(req.url, 'http://x'); const p = decodeURIComponent(url.pathname);
  const send = (code, body, type = 'application/octet-stream', extra = {}) => { res.writeHead(code, { 'Content-Type': type, 'Content-Length': body.length, ...extra }); res.end(body); };
  if (p === '/') return send(200, '<!doctype html><title>d1</title>', 'text/html');
  if (p.startsWith('/m/')) { const f = p.slice(3); if (!/^[\w-]+\.mjs$/.test(f)) return send(404, ''); return send(200, readFileSync(join(webDir, f)), 'text/javascript'); }
  if (p === '/__state') { Object.assign(state, JSON.parse(url.searchParams.get('s'))); state.requests = []; state.sent = 0; return send(200, 'ok', 'text/plain'); }
  if (p === '/__requests') return send(200, JSON.stringify({ requests: state.requests, sent: state.sent }), 'application/json');
  if (p === '/big.gz') { state.requests.push('big.gz'); return send(200, big.gz); }
  if (!p.startsWith('/game/')) return send(404, '');
  const key = p.slice(6);
  if (!served.has(key)) return send(404, 'nope', 'text/plain');
  if (key !== 'manifest.json') state.requests.push(key + (req.headers.range ? ' [range]' : ''));
  let body = readFileSync(join(fixture, 'game', key));
  const counted = key !== 'manifest.json';
  const hit = state.key === key && key.endsWith('.gz');
  if (hit && state.mode === 'corrupt') { body = Buffer.from(body); body[body.length >> 1] ^= 0xff; }
  if (hit && state.mode === 'truncate') body = body.subarray(0, body.length - 30);
  if (hit && state.mode === 'junk') body = Buffer.concat([body, Buffer.from('JUNK')]);
  const headers = hit && state.mode === 'host-encoded' ? { 'Content-Encoding': 'gzip' } : {};
  if (state.mode === 'host-encoded' && key.endsWith('.gz')) {   // хост отдаёт .gz с Content-Encoding: gzip
    if (counted) state.sent += body.length; res.writeHead(200, { 'Content-Type': 'application/octet-stream', 'Content-Encoding': 'gzip', 'Content-Length': body.length }); return res.end(body);
  }
  if (hit && state.mode === 'cut-once') {                       // обрыв посреди ответа один раз
    state.mode = 'normal';
    res.writeHead(200, { 'Content-Type': 'application/octet-stream', 'Content-Length': body.length });
    res.write(body.subarray(0, Math.floor(body.length / 3)));
    return setTimeout(() => res.destroy(), 20);
  }
  if (counted) state.sent += body.length;
  send(200, body, 'application/octet-stream', headers);
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
  await page.goto(origin + '/');
  console.log('Chromium', browser.version());

  // общий код страницы: то же, что port.js (syncFromServer/downloadFile), но с параметрами теста
  await page.evaluate(async () => {
    const T = await import('/m/game-transfer.mjs');
    const S = await import('/m/save-protection.mjs');
    window.T = T; window.S = S;
    const hex = async (buf) => [...new Uint8Array(await crypto.subtle.digest('SHA-256', buf))].map((b) => b.toString(16).padStart(2, '0')).join('');
    window.hex = hex;
    window.fh = async (dir, rel, create) => { const parts = rel.split('/'); for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create }); return dir.getFileHandle(parts.at(-1), { create }); };
    window.existingSize = async (dir, rel) => { try { return (await (await window.fh(dir, rel, false)).getFile()).size; } catch { return -1; } };
    window.install = async (name, { retrySleep = 0 } = {}) => {
      const root = await navigator.storage.getDirectory();
      const dir = await root.getDirectoryHandle(name, { create: true });
      const manifest = await (await fetch('/game/manifest.json')).json();
      const files = S.validateManifestFiles(manifest.files);
      const events = { sleeps: [], calls: [], marker: null, progress: 0 };
      try {
        await S.syncManifestFiles({ dir, files, hadMarker: false, version: manifest.version, existingSize: window.existingSize,
          async downloadFile(d, rel, size, from, onBytes, entry) {
            events.calls.push([rel, from, !!entry?.enc]);
            if (entry?.enc) {
              return T.downloadPackedFile({ entry, url: '/game/' + T.remotePath(entry).split('/').map(encodeURIComponent).join('/'), fetchImpl: fetch, onBytes,
                openWritable: async () => (await window.fh(d, rel, true)).createWritable(),
                discard: async () => { const parts = rel.split('/'); let x = d; for (const p of parts.slice(0, -1)) x = await x.getDirectoryHandle(p); await x.removeEntry(parts.at(-1)); } });
            }
            const res = await fetch('/game/' + rel.split('/').map(encodeURIComponent).join('/'));
            if (!res.ok) throw new Error(rel + ': HTTP ' + res.status);
            const w = await (await window.fh(d, rel, true)).createWritable();
            const reader = res.body.getReader();
            for (;;) { const { done, value } = await reader.read(); if (done) break; await w.write(value); onBytes(value.length); }
            await w.close();
          },
          async downloadOptionsFile(d, entry, onBytes) {
            const bytes = await S.fetchVerifiedOptions('/game/options', entry, fetch);
            const w = await (await window.fh(d, 'options', true)).createWritable(); await w.write(bytes); await w.close(); onBytes(bytes.length);
          },
          async writeMarker(v) { events.marker = v; },
          show(done) { events.progress = done; },
          async sleep(ms, path, err) { events.sleeps.push([path, err.name + ': ' + err.message.slice(0, 80)]); if (retrySleep) await new Promise((r) => setTimeout(r, retrySleep)); },
        });
      } catch (e) { events.error = e.name + ': ' + e.message; }
      // независимая проверка содержимого OPFS: SHA-256 через WebCrypto
      events.state = {};
      for (const f of files) {
        try { const file = await (await window.fh(dir, f.path, false)).getFile(); events.state[f.path] = { size: file.size, sha: await hex(await file.arrayBuffer()) }; }
        catch { events.state[f.path] = null; }
      }
      events.manifest = manifest;
      return events;
    };
    window.wipe = async (name) => { const root = await navigator.storage.getDirectory(); await root.removeEntry(name, { recursive: true }).catch(() => {}); };
  });

  const check = (ev, label) => {
    for (const f of ev.manifest.files) {
      assert.ok(ev.state[f.path], `${label}: ${f.path} отсутствует в OPFS`);
      assert.equal(ev.state[f.path].size, f.size, `${label}: размер ${f.path}`);
      assert.equal(ev.state[f.path].sha, f.sha256, `${label}: SHA-256 ${f.path}`);
    }
  };
  const total = (ev) => ev.manifest.files.reduce((s, f) => s + f.size, 0);

  /* A. чистая установка */
  await set({ mode: 'normal', key: '' });
  let ev = await page.evaluate(() => window.install('d1-a'));
  assert.equal(ev.error, undefined, ev.error); check(ev, 'A');
  assert.equal(ev.marker, ev.manifest.version);
  assert.equal(ev.progress, total(ev), 'A: прогресс = сумма распакованных размеров');
  let s = await seen();
  for (const f of ev.manifest.files) assert.ok(s.requests.includes(f.enc ? f.path + '.gz' : f.path), `A: запрошен ${f.path}`);
  assert.ok(!s.requests.some((r) => ['RESOURCE/Textures/a.tx', 'RESOURCE/Models/c.an'].includes(r)), 'A: исходные несжатые копии сжатых файлов не запрашиваются');
  assert.ok(s.sent < total(ev) * 0.85, `A: по сети ${s.sent} байт при ${total(ev)} распакованных`);
  const csum = ev.manifest.files.reduce((a, f) => a + (f.csize ?? f.size), 0);
  assert.equal(s.sent, csum, 'A: по сети ушло ровно сумма csize/size из манифеста');
  console.log(`ok - A чистая установка: ${ev.manifest.files.length} файлов, ${(total(ev) / 1e6).toFixed(2)} МБ в OPFS, по сети ${(s.sent / 1e6).toFixed(2)} МБ`);
  await page.evaluate(() => window.wipe('d1-a'));

  /* B. обрыв посреди сжатого файла, повтор */
  await set({ mode: 'cut-once', key: 'RESOURCE/Textures/a.tx.gz' });
  ev = await page.evaluate(() => window.install('d1-b'));
  assert.equal(ev.error, undefined, ev.error); check(ev, 'B');
  assert.equal(ev.sleeps.length, 1, 'B: один повтор'); assert.equal(ev.progress, total(ev));
  assert.deepEqual(ev.calls.filter((c) => c[0] === 'RESOURCE/Textures/a.tx').map((c) => c[1]), [0, 0]);
  console.log('ok - B обрыв соединения посреди a.tx.gz: повтор с нуля, итог верный (' + ev.sleeps[0][1] + ')');
  await page.evaluate(() => window.wipe('d1-b'));

  /* C-E. порча / усечение / мусор: отказ, файла нет, метки нет */
  for (const mode of ['corrupt', 'truncate', 'junk']) {
    await set({ mode, key: 'RESOURCE/Models/Locations/b.gm.gz' });
    ev = await page.evaluate(() => window.install('d1-bad', { retrySleep: 0 }));
    assert.ok(ev.error, `${mode}: установка должна завершиться отказом`);
    assert.equal(ev.marker, null, `${mode}: метка установки не ставится`);
    assert.equal(ev.state['RESOURCE/Models/Locations/b.gm'], null, `${mode}: файл не остаётся в OPFS`);
    assert.equal(ev.sleeps.length, 3, `${mode}: 4 попытки`);
    console.log(`ok - ${mode}: отказ (${ev.error.slice(0, 70)}), файла нет, метки нет`);
    await page.evaluate(() => window.wipe('d1-bad'));
  }

  /* F. хост добавил Content-Encoding: gzip к .gz: браузер распаковал сам, проверки остаются */
  await set({ mode: 'host-encoded', key: '' });
  ev = await page.evaluate(() => window.install('d1-f'));
  assert.equal(ev.error, undefined, ev.error); check(ev, 'F');
  console.log('ok - F Content-Encoding: gzip на .gz-объектах: установка верна (fetch распаковал сам, SHA сверен)');
  await page.evaluate(() => window.wipe('d1-f'));

  /* G. пропускная способность: 48 МБ распаковка + SHA-256 + запись в OPFS в Chromium */
  await set({ mode: 'normal', key: '' });
  const perf = await page.evaluate(async () => {
    const root = await navigator.storage.getDirectory();
    const dir = await root.getDirectoryHandle('d1-perf', { create: true });
    const entry = await (async () => {
      const r = await fetch('/big.gz'); const gz = new Uint8Array(await r.arrayBuffer());
      return { gz };
    })();
    // манифестные size/sha известны серверу только через независимый подсчёт: берём их из самой распаковки
    const ds = new Response(new Blob([entry.gz]).stream().pipeThrough(new DecompressionStream('gzip')));
    const raw = new Uint8Array(await ds.arrayBuffer());
    const sha = await window.hex(raw);
    const e = { path: 'big.bin', size: raw.length, sha256: sha, enc: 'gzip', csize: entry.gz.length };
    const t0 = performance.now();
    await window.T.downloadPackedFile({ entry: e, url: '/big.gz', fetchImpl: fetch,
      openWritable: async () => (await dir.getFileHandle('big.bin', { create: true })).createWritable(), discard: async () => {} });
    const dt = performance.now() - t0;
    await root.removeEntry('d1-perf', { recursive: true });
    return { mb: raw.length / 1048576, ms: dt, ratio: entry.gz.length / raw.length };
  });
  console.log(`info - G скорость (localhost, без сетевого ограничения): ${perf.mb.toFixed(0)} МБ распакованных за ${(perf.ms / 1000).toFixed(2)} с = ${(perf.mb / (perf.ms / 1000)).toFixed(0)} МБ/с (fetch + gunzip + JS SHA-256 + OPFS), сжатие ${(perf.ratio * 100).toFixed(0)} %`);
  assert.ok(perf.mb / (perf.ms / 1000) > 20, 'конвейер не должен быть заметно медленнее 20 МБ/с');
  console.log('game-transfer (настоящий Chromium + OPFS): PASS');
} finally {
  if (browser) await browser.close();
  server.close();
  rmSync(tmp, { recursive: true, force: true });
}
