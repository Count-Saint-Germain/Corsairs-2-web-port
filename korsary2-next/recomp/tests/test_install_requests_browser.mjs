/* D3: стенд замера установки тысяч файлов — НАСТОЯЩИЙ port.js (страница index.html без запуска игры) в эфемерном
   headless Chromium с настоящим OPFS против loopback-сервера с ИСКУССТВЕННОЙ задержкой на запрос (имитация RTT) и
   необязательным ограничением пропускной способности. Данные синтетические: dist строит настоящий make_dist
   (write_game): раскладка D1 (по файлу) и раскладка с пакетами; состав и размеры файлов повторяют гистограмму
   реальной игры (docs/BUILD_FROM_CLONE.md). Игра НЕ запускается: кнопку Play никто не нажимает, build/game.js не
   запрашивается; браузер — bundled Playwright Chromium, чистый контекст на каждый прогон, свободный loopback-порт,
   всё гасится в конце. Данные пользователя и настоящий OPFS не затрагиваются.

   Прогоны (один и тот же набор файлов): D1-раскладка последовательно (= схема ДО D3: один запрос и одна запись за
   раз), D1-раскладка в 6 потоков (параллелизм без пакетов), пакеты в 1 и в 6 потоков; затем HTTP/2 (https с
   самоподписанным сертификатом, ignoreHTTPSErrors): 6 и 16 потоков без пакетов, пакеты в 6 потоков; затем
   ограничение пропускной способности; затем сбои: обрыв посреди установки и продолжение, порча записи пакета.
   Проверяется: байты в OPFS равны манифесту (SHA-256 через WebCrypto, независимо от кода страницы), метка версии,
   число запросов, ограничение числа одновременных запросов, относительные времена (с запасом на шум).

     node tests/test_install_requests_browser.mjs
     D3_FILES=2000 D3_DELAY=80 D3_VERBOSE=1 node tests/test_install_requests_browser.mjs   # полный замер
   Переменные: D3_FILES (файлов, по умолчанию 500), D3_DELAY (мс на запрос, 50), D3_MAXFILE (МБ, потолок размера файла, 2),
   D3_MBIT (ограничение канала для третьей части, 100). */
import assert from 'node:assert/strict';
import http from 'node:http';
import http2 from 'node:http2';
import { createRequire } from 'node:module';
import { spawnSync } from 'node:child_process';
import { readFileSync, mkdtempSync, rmSync, mkdirSync, statSync, createReadStream, writeFileSync, existsSync, openSync, readSync, closeSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { fileURLToPath } from 'node:url';
import { resolve, dirname, join, extname } from 'node:path';
import { simulate as simulateNetwork } from '../web/install_model.mjs';
import { writeGame } from '../web/make_dist.mjs';
import { manifestFor } from '../web/gamefiles.mjs';

const here = dirname(fileURLToPath(import.meta.url));
const webDir = resolve(here, '../web');
const root = resolve(here, '../../..');           // web-port
const playwrightDir = resolve(root, 'third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH = resolve(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');

const FILES = Number(process.env.D3_FILES || 500);
const DELAY = Number(process.env.D3_DELAY || 50);
const MAXFILE = Number(process.env.D3_MAXFILE || 2) * 1e6;
const MBIT = Number(process.env.D3_MBIT || 100);
const VERBOSE = !!process.env.D3_VERBOSE;

/* ---- фикстура: игра по гистограмме реальной раскладки, два dist (D1 и пакеты) через настоящий make_dist */
const tmp = mkdtempSync(join(tmpdir(), 'k2-d3-browser-'));
let seed=20261112;
function random(){seed^=seed<<13;seed^=seed>>>17;seed^=seed<<5;return (seed>>>0)/0x100000000;}
function randomBytes(n){const out=Buffer.alloc(n);for(let i=0;i<n;i++)out[i]=Math.floor(random()*256);return out;}
const buckets=[[0,1024,17.5],[1024,4096,17],[4096,16384,14.5],[16384,65536,16.8],[65536,262144,20.3],[262144,1048576,8.8],[1048576,4194304,4.5],[4194304,16777216,0.6]];
const exts=['gm','tx','col','col','wav','an','c','ptc'],noise={gm:.45,tx:.5,col:.1,wav:.95,an:.1,c:.2,ptc:.1},block=randomBytes(4096),src=join(tmp,'src'),files=new Map();
function content(n,ratio){const out=Buffer.alloc(n);for(let i=0;i<Math.ceil(n/1024);i++){const chunk=random()<ratio?randomBytes(1024):block.subarray((i*97)%3000,(i*97)%3000+1024);chunk.copy(out,i*1024);}return out;}
function put(rel,data){const p=join(src,rel);mkdirSync(dirname(p),{recursive:true});writeFileSync(p,data);files.set(rel,p);}
for(let i=0;i<FILES;i++){let weight=random()*buckets.reduce((n,b)=>n+b[2],0),bucket=buckets.at(-1);for(const b of buckets){weight-=b[2];if(weight<0){bucket=b;break;}}const [lo,hi]=bucket,n=Math.min(Math.floor(lo+(hi-lo)*random()**2),Math.floor(MAXFILE)),ext=exts[Math.floor(random()*exts.length)],loc=Math.floor(random()*40),folder=['gm','col'].includes(ext)?'Models/Locations':ext==='tx'?'Textures':ext==='wav'?'Sounds':'Anim';put(`RESOURCE/${folder}/loc${String(loc).padStart(2,'0')}/obj${String(i).padStart(5,'0')}.${ext}`,content(n,noise[ext]));}
put('options','options '.repeat(200));put('engine.ini','[x]\n'.repeat(400));
const layouts={};for(const [name,pack,codec] of [['d1',false,'gzip'],['pack',true,'gzip'],['brpack',true,'br']]){const gameOut=join(tmp,name,'game');mkdirSync(gameOut,{recursive:true});const [packed,packs,hashes]=await writeGame(files,gameOut,{compress:true,pack,codec,quality:5});const m=manifestFor(new Map([...files].map(([rel,p])=>[rel,packed.has(rel)?p:join(gameOut,rel)])),packed,packs,hashes);writeFileSync(join(gameOut,'manifest.json'),JSON.stringify(m));layouts[name]={files:m.files.length,raw:m.files.reduce((n,e)=>n+e.size,0),wire:m.files.reduce((n,e)=>n+(e.csize??e.size),0),objects:m.files.length-m.files.filter(e=>'pack'in e).length+packs.length,packs:packs.length,version:m.version};}
assert.equal(layouts.d1.version, layouts.pack.version, 'версия манифеста не зависит от упаковки');
console.log(`фикстура: ${layouts.d1.files} файлов, ${(layouts.d1.raw / 1e6).toFixed(0)} МБ в OPFS, по сети ${(layouts.d1.wire / 1e6).toFixed(0)} МБ; ` +
  `объектов: D1 ${layouts.d1.objects}, с пакетами ${layouts.pack.objects} (пакетов ${layouts.pack.packs}); задержка ${DELAY} мс на запрос`);

/* ---- Network-only model */
function model(layout, slots, mbit) {
  const mf = JSON.parse(readFileSync(join(tmp, layout, 'game', 'manifest.json'), 'utf8'));
  const files = mf.files.map(e => e.csize ?? e.size);
  const sizes = mf.packs ? mf.packs.map(p => p.size).concat(files.filter((_, i) => !('pack' in mf.files[i]))) : files;
  return simulateNetwork(sizes, DELAY / 1000, (mbit || 1e6) * 1e6 / 8, slots);
}

/* ---- сервер (HTTP/1.1 и HTTP/2) */
const sleep = (ms) => new Promise((r) => setTimeout(r, ms));
const state = { layout: 'd1', delay: DELAY, mbit: 0, failAfter: Infinity, corrupt: null, requests: 0, inflight: 0, max: 0, bytes: 0, keys: [], wasm: 0 };
const reset = (s) => { Object.assign(state, { layout: 'd1', delay: DELAY, mbit: 0, failAfter: Infinity, corrupt: null }, s, { requests: 0, inflight: 0, max: 0, bytes: 0, keys: [], wasm: 0 }); limiter.next = 0; };
const limiter = { next: 0 };
const MIME = { '.html': 'text/html', '.js': 'text/javascript', '.mjs': 'text/javascript', '.wasm': 'application/wasm' };
const ISOLATION = { 'Cross-Origin-Opener-Policy': 'same-origin', 'Cross-Origin-Embedder-Policy': 'require-corp', 'Cross-Origin-Resource-Policy': 'same-origin', 'Cache-Control': 'no-store' };
async function handle(req, res) {
  const url = new URL(req.url, 'http://x');
  const p = decodeURIComponent(url.pathname);
  const send = (code, body, type = 'application/octet-stream') => { res.writeHead(code, { 'Content-Type': type, 'Content-Length': Buffer.byteLength(body), ...ISOLATION }); res.end(body); };
  if (p === '/__stats') return send(200, JSON.stringify({ requests: state.requests, max: state.max, bytes: state.bytes, keys: state.keys, wasm: state.wasm }), 'application/json');
  if (p === '/vendor/brotli/k2br.wasm') { state.wasm++; return send(200, readFileSync(join(webDir, 'vendor/brotli/k2br.wasm')), 'application/wasm'); }
  if (!p.startsWith('/game/')) {
    const f = p === '/' ? 'index.html' : p.slice(1);
    if (!/^[\w.-]+$/.test(f) || !existsSync(join(webDir, f))) return send(404, 'nope', 'text/plain');
    return send(200, readFileSync(join(webDir, f)), MIME[extname(f)] || 'text/plain');
  }
  const key = p.slice(6);
  const file = join(tmp, state.layout, 'game', key);
  if (key.includes('..') || !existsSync(file) || !statSync(file).isFile()) return send(404, 'nope', 'text/plain');
  const isManifest = key === 'manifest.json';
  if (!isManifest) { state.requests++; state.keys.push(key + (req.headers.range ? ' ' + req.headers.range : '')); }
  if (!isManifest && state.requests > state.failAfter) { await sleep(state.delay); return send(500, 'injected failure', 'text/plain'); }
  state.inflight++; state.max = Math.max(state.max, state.inflight);
  try {
    await sleep(state.delay);
    let body = readFileSync(file), status = 200, headers = { 'Content-Type': 'application/octet-stream', ...ISOLATION, 'Accept-Ranges': 'bytes' };
    const m = /^bytes=(\d+)-(\d*)$/.exec(req.headers.range || '');
    let start = 0;
    if (m && !isManifest) {
      start = +m[1]; const end = m[2] === '' ? body.length - 1 : Math.min(+m[2], body.length - 1);
      headers['Content-Range'] = `bytes ${start}-${end}/${body.length}`; body = body.subarray(start, end + 1); status = 206;
    }
    if (state.corrupt && key === state.corrupt.key) { body = Buffer.from(body); const at = state.corrupt.at - start; if (at >= 0 && at < body.length) body[at] ^= 0xFF; }
    headers['Content-Length'] = body.length;
    res.writeHead(status, headers);
    if (!isManifest) state.bytes += body.length;
    if (!state.mbit || isManifest) { res.end(body); return; }
    const bw = state.mbit * 1e6 / 8;                           // общий канал: очередь записей на всех соединениях
    for (let o = 0; o < body.length; o += 32768) {
      const chunk = body.subarray(o, o + 32768), now = Date.now();
      limiter.next = Math.max(limiter.next, now) + chunk.length / bw * 1000;
      const wait = limiter.next - now;
      if (wait > 1) await sleep(wait);
      if (!res.write(chunk)) await new Promise((r) => res.once('drain', r));
    }
    res.end();
  } finally { state.inflight--; }
}
const h1 = http.createServer((q, s) => { handle(q, s).catch(() => { try { s.destroy(); } catch { /* gone */ } }); });
await new Promise((ok, fail) => { h1.once('error', fail); h1.listen(0, '127.0.0.1', ok); });
const origin1 = `http://127.0.0.1:${h1.address().port}`;
let h2srv = null, origin2 = null;
{
  const key = join(tmp, 'k.pem'), crt = join(tmp, 'c.pem');
  const gen = spawnSync('openssl', ['req', '-x509', '-newkey', 'rsa:2048', '-nodes', '-keyout', key, '-out', crt, '-subj', '/CN=localhost', '-days', '1',
    '-addext', 'subjectAltName=DNS:localhost,IP:127.0.0.1'], { encoding: 'utf8' });
  if (gen.status === 0) {
    h2srv = http2.createSecureServer({ key: readFileSync(key), cert: readFileSync(crt), allowHTTP1: true, settings: { maxConcurrentStreams: 100 } },
      (q, s) => { handle(q, s).catch(() => { try { s.destroy(); } catch { /* gone */ } }); });
    await new Promise((ok, fail) => { h2srv.once('error', fail); h2srv.listen(0, '127.0.0.1', ok); });
    origin2 = `https://127.0.0.1:${h2srv.address().port}`;
  } else console.log('info - openssl недоступен: прогоны HTTP/2 пропущены');
}
const stats = async (origin, ctx) => (await ctx.request.get(origin + '/__stats', { ignoreHTTPSErrors: true })).json();

/* ---- прогон: настоящая страница, чистый контекст, установка, независимая проверка OPFS */
const browser = await chromium.launch({ headless: true, args: ['--ignore-certificate-errors'] });
console.log('Chromium', browser.version());
const rows = [];
async function run(label, { origin = origin1, layout, concurrency, delay = DELAY, mbit = 0, failAfter, corrupt, expectFail = false, context = null, keep = false } = {}) {
  reset({ layout, delay, mbit, failAfter: failAfter ?? Infinity, corrupt });
  const ctx = context || await browser.newContext({ ignoreHTTPSErrors: true });
  const page = await ctx.newPage();
  const errors = [];
  page.on('pageerror', (e) => errors.push(e.message));
  await page.addInitScript(() => {   // WebGPU не нужен: игра не запускается, страница только устанавливает файлы
    Object.defineProperty(navigator, 'gpu', { value: { requestAdapter: async () => ({ info: {}, isFallbackAdapter: false }) }, configurable: true });
  });
  const t0 = Date.now();
  await page.goto(`${origin}/?lazy=0&installConcurrency=${concurrency}`);
  await page.waitForFunction(() => window.installStats || /Update failed|Error/.test(document.getElementById('status').textContent) ||
    !document.getElementById('view-home').classList.contains('hidden'), null, { timeout: 600_000 });   // последнее: версия уже установлена, качать нечего
  const wall = (Date.now() - t0) / 1000;
  const result = await page.evaluate(async () => ({ install: window.installStats || null, status: document.getElementById('status').textContent,
    home: !document.getElementById('view-home').classList.contains('hidden'), isolated: crossOriginIsolated }));
  const st = await stats(origin, ctx);
  // независимая проверка: что лежит в OPFS (SHA-256 через WebCrypto), по манифесту сервера
  const manifest = JSON.parse(readFileSync(join(tmp, layout, 'game', 'manifest.json'), 'utf8'));
  const check = await page.evaluate(async (files) => {
    const dir = await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game');
    const hex = async (b) => [...new Uint8Array(await crypto.subtle.digest('SHA-256', b))].map((x) => x.toString(16).padStart(2, '0')).join('');
    let ok = 0, absent = 0, bad = [];
    for (const f of files) {
      try {
        let d = dir; const parts = f.path.split('/');
        for (const p of parts.slice(0, -1)) d = await d.getDirectoryHandle(p);
        const file = await (await d.getFileHandle(parts.at(-1))).getFile();
        if (file.size === f.size && await hex(await file.arrayBuffer()) === f.sha256) ok++; else bad.push(f.path);
      } catch { absent++; }
    }
    let marker = null;
    try { marker = JSON.parse(await (await (await dir.getFileHandle('installed.json')).getFile()).text()).version; } catch { /* none */ }
    return { ok, absent, bad: bad.slice(0, 5), badCount: bad.length, marker };
  }, manifest.files);
  if (!keep && !context) await ctx.close();
  assert.deepEqual(errors, [], `${label}: ошибки страницы`);
  const row = { label, layout, concurrency, delay, mbit, seconds: result.install?.seconds ?? null, wall, requests: st.requests, max: st.max, bytes: st.bytes, ...check, files: manifest.files.length,
    status: result.status, isolated: result.isolated, keys: st.keys, wasm: st.wasm };
  if (!expectFail) {
    assert.ok(result.isolated, `${label}: страница должна быть cross-origin isolated (COOP/COEP)`);
    assert.ok(result.install, `${label}: установка не завершилась: ${result.status}`);
    assert.equal(check.ok, manifest.files.length, `${label}: файлов с верными размером и SHA-256 ${check.ok} из ${manifest.files.length} (плохих ${check.badCount}: ${check.bad}, нет ${check.absent})`);
    assert.equal(check.marker, manifest.version, `${label}: метка установки`);
    assert.equal(result.install.concurrency, concurrency, `${label}: страница взяла concurrency из адреса`);
    rows.push(row);
    console.log(`${label.padEnd(34)} ${row.seconds.toFixed(1).padStart(6)} с  запросов ${String(st.requests).padStart(5)}  одновременно ${String(st.max).padStart(2)}  ` +
      `${(st.bytes / 1e6).toFixed(0)} МБ по сети, ${(check.ok)} файлов проверено`);
  }
  return { row, ctx, page };
}

try {
  /* A. HTTP/1.1, задержка на запрос, без ограничения канала */
  const a1 = (await run('A1 D1, последовательно (до D3)', { layout: 'd1', concurrency: 1 })).row;
  const a2 = (await run('A2 D1, 6 потоков', { layout: 'd1', concurrency: 6 })).row;
  const a3 = (await run('A3 пакеты, 1 поток', { layout: 'pack', concurrency: 1 })).row;
  const a4 = (await run('A4 пакеты, 6 потоков', { layout: 'pack', concurrency: 6 })).row;
  assert.equal(a1.requests, layouts.d1.objects, 'до D3: запрос на каждый файл');
  assert.equal(a1.max, 1, 'последовательная схема: один запрос за раз');
  assert.ok(a2.max <= 6 && a2.max >= 3, `6 потоков: одновременно ${a2.max}`);
  assert.equal(a4.requests, layouts.pack.objects, 'пакеты: запросов = пакеты + отдельные объекты');
  assert.ok(a4.requests * 4 < a1.requests, `запросов с пакетами (${a4.requests}) должно быть заметно меньше (${a1.requests})`);
  assert.ok(a2.seconds * 2.5 < a1.seconds, `параллелизм (${a2.seconds.toFixed(1)} с) быстрее последовательной схемы (${a1.seconds.toFixed(1)} с) более чем в 2,5 раза`);
  assert.ok(a4.seconds * 4 < a1.seconds, `пакеты в 6 потоков (${a4.seconds.toFixed(1)} с) быстрее последовательной схемы (${a1.seconds.toFixed(1)} с) более чем в 4 раза`);
  assert.ok(a4.seconds < a2.seconds * 1.15, `пакеты (${a4.seconds.toFixed(1)} с) не медленнее параллельных файлов (${a2.seconds.toFixed(1)} с)`);
  assert.ok(a3.seconds < a1.seconds / 2, `пакеты даже в один поток быстрее файлов по одному (${a3.seconds.toFixed(1)} против ${a1.seconds.toFixed(1)} с)`);

  /* модель против измерения: сеть-только оценка — нижняя граница, страница добавляет CPU (SHA-256, OPFS) */
  const modeled = { A1: model('d1', 1, 0), A2: model('d1', 6, 0), A4: model('pack', 6, 0) };
  for (const [k, row] of Object.entries({ A1: a1, A2: a2, A4: a4 }))
    assert.ok(row.seconds > modeled[k] * 0.8, `${k}: измерение ${row.seconds.toFixed(1)} с не может быть заметно меньше сетевой модели ${modeled[k].toFixed(1)} с`);
  console.log(`модель (только сеть, ${DELAY} мс на запрос, канал не ограничен): последовательно ${modeled.A1.toFixed(1)} с, D1 ×6 ${modeled.A2.toFixed(1)} с, пакеты ×6 ${modeled.A4.toFixed(1)} с; измерено ${a1.seconds.toFixed(1)} / ${a2.seconds.toFixed(1)} / ${a4.seconds.toFixed(1)} с`);

  /* B. без задержки: накладные расходы страницы (CPU, OPFS), сеть почти бесплатна */
  const b1 = (await run('B1 D1, последовательно, без задержки', { layout: 'd1', concurrency: 1, delay: 0 })).row;
  const b2 = (await run('B2 пакеты, 6 потоков, без задержки', { layout: 'pack', concurrency: 6, delay: 0 })).row;

  /* C. ограниченный канал + задержка: модель из make_dist --estimate против измерения */
  const c1 = (await run(`C1 D1, 6 потоков, ${MBIT} Мбит/с`, { layout: 'd1', concurrency: 6, mbit: MBIT })).row;
  const c2 = (await run(`C2 пакеты, 6 потоков, ${MBIT} Мбит/с`, { layout: 'pack', concurrency: 6, mbit: MBIT })).row;
  const floor = layouts.d1.wire / (MBIT * 1e6 / 8);
  assert.ok(c1.seconds > floor * 0.9 && c2.seconds > floor * 0.9, `быстрее канала не бывает (пол ${floor.toFixed(1)} с)`);
  console.log(`модель (только сеть, ${MBIT} Мбит/с + ${DELAY} мс): D1 ×6 ${model('d1', 6, MBIT).toFixed(1)} с, пакеты ×6 ${model('pack', 6, MBIT).toFixed(1)} с; измерено ${c1.seconds.toFixed(1)} / ${c2.seconds.toFixed(1)} с`);
  assert.ok(c2.seconds < c1.seconds * 1.1, `с пакетами не медленнее (${c2.seconds.toFixed(1)} против ${c1.seconds.toFixed(1)} с)`);

  /* D. HTTP/2 (мультиплексирование): сколько потоков нужно без пакетов */
  if (origin2) {
    const d1 = (await run('D1 HTTP/2, D1, 6 потоков', { origin: origin2, layout: 'd1', concurrency: 6 })).row;
    const d2 = (await run('D2 HTTP/2, D1, 16 потоков', { origin: origin2, layout: 'd1', concurrency: 16 })).row;
    const d3 = (await run('D3 HTTP/2, пакеты, 6 потоков', { origin: origin2, layout: 'pack', concurrency: 6 })).row;
    assert.ok(d2.max > 6, `HTTP/2: 16 потоков идут по одному соединению, одновременно ${d2.max} (> 6, лимита HTTP/1.1 нет)`);
    assert.ok(d2.seconds < d1.seconds, `HTTP/2: 16 потоков (${d2.seconds.toFixed(1)} с) быстрее 6 (${d1.seconds.toFixed(1)} с)`);
    assert.ok(d3.seconds < d1.seconds * 1.15, `HTTP/2: пакеты (${d3.seconds.toFixed(1)} с) не хуже 6 потоков файлов (${d1.seconds.toFixed(1)} с)`);
  }

  /* E. сбой посреди установки и продолжение: тот же контекст (OPFS сохраняется между страницами) */
  {
    const ctx = await browser.newContext({ ignoreHTTPSErrors: true });
    const cutAfter = Math.floor(layouts.pack.objects / 2);
    const first = await run('E1 пакеты, сбой сервера на середине', { layout: 'pack', concurrency: 4, failAfter: cutAfter, expectFail: true, context: ctx, keep: true, delay: 5 });
    assert.ok(!first.row.install && /Update failed|HTTP 500/.test(first.row.status), `E1: установка должна отказать: ${first.row.status}`);
    assert.equal(first.row.marker, null, 'E1: метки нет');
    assert.ok(first.row.ok > 0 && first.row.ok < first.row.files, `E1: часть файлов успела установиться (${first.row.ok}/${first.row.files})`);
    assert.equal(first.row.badCount, 0, 'E1: ни одного неполного файла: каждый присутствующий файл целый');
    await first.page.close();
    const second = await run('E2 продолжение здоровым сервером', { layout: 'pack', concurrency: 4, context: ctx, keep: true, delay: 5 });
    assert.ok(second.row.requests < layouts.pack.objects, `E2: докачка просит меньше, чем чистая установка (${second.row.requests} против ${layouts.pack.objects})`);
    const third = await run('E3 повторный запуск (всё установлено)', { layout: 'pack', concurrency: 4, context: ctx, keep: true, delay: 5, expectFail: true });
    assert.equal(third.row.requests, 0, 'E3: ничего не качается');
    assert.equal(third.row.ok, third.row.files);
    await ctx.close();
  }

  /* F. порча записи в пакете: установка отказывает, плохого файла в OPFS нет, остальное целое */
  {
    const manifest = JSON.parse(readFileSync(join(tmp, 'pack', 'game', 'manifest.json'), 'utf8'));
    const victim = manifest.files.filter((e) => e.pack !== undefined && e.enc === 'gzip' && e.csize > 400)[3];
    const corrupt = { key: manifest.packs[victim.pack].path, at: victim.offset + 40 };
    const r = await run('F порча записи в пакете', { layout: 'pack', concurrency: 4, delay: 0, corrupt, expectFail: true, keep: true });
    assert.ok(!r.row.install, 'F: установка должна отказать'); assert.equal(r.row.marker, null);
    assert.equal(r.row.badCount, 0, `F: ни одного неполного/испорченного файла (${r.row.bad})`);
    assert.ok(!r.row.bad.includes(victim.path));
    const page = r.page;
    const has = await page.evaluate(async (path) => { try { let d = await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game'); const ps = path.split('/'); for (const p of ps.slice(0, -1)) d = await d.getDirectoryHandle(p); await d.getFileHandle(ps.at(-1)); return true; } catch { return false; } }, victim.path);
    assert.equal(has, false, 'F: испорченный файл не остался в OPFS');
    console.log(`ok - F порча записи пакета: отказ («${r.row.status.slice(0, 90)}»), файла нет, остальные ${r.row.ok} целы`);
    await r.ctx.close();
  }

  /* G. D1b: тот же настоящий port.js, раскладка с br-записями в пакетах: декодер brotli грузится лениво и один раз */
  if (layouts.brpack) {
    const g = (await run('G пакеты + brotli (q5), 6 потоков', { layout: 'brpack', concurrency: 6, delay: 5 })).row;
    assert.equal(g.wasm, 1, `G: k2br.wasm запрошен ${g.wasm} раз(а), ожидался один`);
    assert.equal(a4.wasm, 0, 'A4: без br декодер не запрашивается');
    assert.ok(layouts.brpack.wire < layouts.pack.wire, `G: brotli передаёт меньше gzip (${layouts.brpack.wire} против ${layouts.pack.wire})`);
    assert.equal(layouts.brpack.version, layouts.pack.version, 'G: версия манифеста не зависит от кодека');
    console.log(`ok - G brotli в пакетах (настоящий port.js): ${g.seconds.toFixed(1)} с, по сети ${(g.bytes / 1e6).toFixed(1)} МБ (gzip-раскладка ${(layouts.pack.wire / 1e6).toFixed(1)} МБ), декодер загружен один раз`);
  } else console.log('info - G пропущен: нет кодировщика brotli');

  /* сводка и замеры накладных расходов */
  const f = (x) => x.toFixed(1);
  console.log('\nсводка (секунды установки, как её видит страница):');
  console.log(`  A  задержка ${DELAY} мс, HTTP/1.1:  последовательно ${f(a1.seconds)} | D1 ×6 ${f(a2.seconds)} | пакеты ×1 ${f(a3.seconds)} | пакеты ×6 ${f(a4.seconds)}`);
  console.log(`     ускорение к схеме до D3: ×${(a1.seconds / a2.seconds).toFixed(1)} (потоки), ×${(a1.seconds / a3.seconds).toFixed(1)} (пакеты, 1 поток), ×${(a1.seconds / a4.seconds).toFixed(1)} (пакеты + потоки)`);
  console.log(`  B  без задержки:  D1 последовательно ${f(b1.seconds)} | пакеты ×6 ${f(b2.seconds)}  (${(layouts.d1.raw / 1e6 / b2.seconds).toFixed(0)} МБ/с распакованных)`);
  console.log(`  C  ${MBIT} Мбит/с + ${DELAY} мс:  D1 ×6 ${f(c1.seconds)} | пакеты ×6 ${f(c2.seconds)} | пол по каналу ${f(layouts.d1.wire / (MBIT * 1e6 / 8))}`);
  const per = (b1.seconds / layouts.d1.files * 1000), perPk = (b2.seconds / layouts.d1.files * 1000);
  console.log(`  накладные расходы страницы на файл (без задержки): ${per.toFixed(2)} мс (D1, 1 поток), ${perPk.toFixed(2)} мс (пакеты, 6 потоков)`);
  if (VERBOSE) console.log(JSON.stringify(rows.map(({ keys, ...r }) => r), null, 1));
  writeFileSync(join(tmp, 'results.json'), JSON.stringify(rows.map(({ keys, ...r }) => r)));
  if (process.env.D3_RESULTS) writeFileSync(process.env.D3_RESULTS, JSON.stringify({ files: layouts, delay: DELAY, mbit: MBIT, rows: rows.map(({ keys, ...r }) => r) }, null, 1));
  console.log('install-requests (настоящий port.js + Chromium + OPFS): PASS');
} finally {
  await browser.close();
  h1.close(); h2srv?.close();
  rmSync(tmp, { recursive: true, force: true });
}
