/* E1: язык игры и английский оверлей в НАСТОЯЩЕМ port.js и настоящем OPFS эфемерного headless Chromium (bundled Playwright, чистый контекст на сценарий,
   свободный порт loopback, всё гасится). Игра НЕ запускается: build/game.js — заглушка теста, которая записывает env, заданное страницей
   (PORT_OVERLAY, arguments) и останавливается; проверка ресурсов (missing-resource-preflight.mjs) подменена заглушкой теста (это не предмет проверки);
   остальные модули страницы настоящие. Данные синтетические (tests/overlay_fixture.mjs, настоящий make_dist), данных игры и профиля пользователя нет.

   Сценарии: A русский по умолчанию — game-en/ не качается (один HEAD), каталога оверлея нет, env без PORT_OVERLAY; B ?lang=en на чистом профиле — установка
   базы и оверлея, байты в OPFS = манифесту (SHA-256 WebCrypto, независимо от кода страницы), своя метка installed-en.json, PORT_OVERLAY=/opfs/korsary2-game-en
   и arguments=/opfs/korsary2-game в env игры, база не изменилась ни на байт; C переключатель на странице: установка по нажатию English, localStorage, смена
   Русский<->English без перекачки, следующий запуск берёт запомненное, пояснение «применяется при запуске»; D обрыв установки оверлея -> безопасный отказ,
   возврат к русскому, продолжение без перекачки готового; E порча объекта оверлея (файл и запись пакета) -> отказ, файла нет, метки нет; F квота:
   отказ ДО записи; G запрещённые пути/нет SHA в манифесте оверлея -> отказ до первой записи; H dist без game-en/ — English отключён, ?lang=en = русский;
   I SAVE и база не тронуты, экспорт сохранений не включает оверлей; J игра держит SAVE-замок в другой вкладке -> установка оверлея отказывает, не гоняется;
   K обновление оверлея (новая версия): докачиваются только изменённые файлы; L оверлей собран на другой русской раздаче -> английский запрещён;
   M неполный слой при установленной метке (OPFS почищен) -> починка при старте, а если нельзя — отказ запуска.
     node tests/test_overlay_browser.mjs                      (OVERLAY_VERBOSE=1 — подробный лог страницы)  */
import assert from 'node:assert/strict';
import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { buildFixture } from './overlay_fixture.mjs';
import { readFileSync, mkdtempSync, rmSync, statSync, existsSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { fileURLToPath } from 'node:url';
import { resolve, dirname, join, extname } from 'node:path';
import { createHash } from 'node:crypto';

const here = dirname(fileURLToPath(import.meta.url));
const root = resolve(here, '../../..');
const playwrightDir = resolve(root, 'third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH = resolve(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');
const VERBOSE = !!process.env.OVERLAY_VERBOSE;

const tmp = mkdtempSync(join(tmpdir(), 'k2-overlay-browser-'));
process.on('exit', () => rmSync(tmp, { recursive: true, force: true }));
const fx = await buildFixture(join(tmp, 'fx'), { big: true });
const fxOld = await buildFixture(join(tmp, 'fx-nooverlay'), { big: true, overlay: false });
const dist = fx.dist;
const ovManifest = () => JSON.parse(readFileSync(join(dist, 'game-en/manifest.json'), 'utf8'));
const gameManifest = () => JSON.parse(readFileSync(join(dist, 'game/manifest.json'), 'utf8'));
console.log(`фикстура: игра ${gameManifest().files.length} файлов, оверлей ${ovManifest().files.length} файлов, пакетов ${ovManifest().packs?.length}`);

/* ---- сервер: статика dist + журнал запросов + управляемые сбои */
const MIME = { '.html': 'text/html', '.js': 'text/javascript', '.mjs': 'text/javascript', '.json': 'application/json', '.wasm': 'application/wasm' };
const ISOLATION = { 'Cross-Origin-Opener-Policy': 'same-origin', 'Cross-Origin-Embedder-Policy': 'require-corp', 'Cross-Origin-Resource-Policy': 'same-origin', 'Cache-Control': 'no-store' };
const FAKE_GAME_JS = `/* stands in for the build: its glue names the host's overlay export */ var _port_overlay_state = 0;\nwindow.createPort = async (opts) => { window.__port = { arguments: opts.arguments };
  const m = { ENV: {} }; for (const f of opts.preRun) f(m); window.__port.env = { ...m.ENV };
  throw new Error('synthetic runtime stop (test stand: the game is not started)'); };\n`;
const OLD_GAME_JS = FAKE_GAME_JS.replace('_port_overlay_state', '_port_something_else');   // a build made before E1
const PREFLIGHT_STUB = 'export async function checkResourcesBeforeRun() { return { block: false, report: { stub: true }, log: [] }; }\n' +
  'export async function checkOverlayBeforeRun() { return { block: false, report: { stub: true }, log: [] }; }\n';
// сценарий Q: база по-прежнему подменена (в синтетической игре нет blade1.gm и музыки), а проверка английского слоя — НАСТОЯЩАЯ из dist
const PREFLIGHT_REAL_OVERLAY = "import * as real from './missing-resource-preflight.real.mjs';\n" +
  'export async function checkResourcesBeforeRun() { return { block: false, report: { stub: true }, log: [] }; }\n' +
  'export const checkOverlayBeforeRun = real.checkOverlayBeforeRun;\n';
const state = { realOverlayPreflight: false, oldBuild: false, overrides: null, log: [], noOverlay: false, failOverlayAfter: Infinity, overlayObjects: 0, corrupt: null, ovManifest: null, gameManifest: null, delay: 0, distDir: dist };
const reset = (s = {}) => Object.assign(state, { realOverlayPreflight: false, oldBuild: false, overrides: null, log: [], noOverlay: false, failOverlayAfter: Infinity, overlayObjects: 0, corrupt: null, ovManifest: null, gameManifest: null, delay: 0, distDir: dist }, s);
const sleep = (ms) => new Promise((r) => setTimeout(r, ms));
const srv = createServer(async (req, res) => {
  const url = new URL(req.url, 'http://x');
  const p = decodeURIComponent(url.pathname);
  const send = (code, body, type = 'application/octet-stream', extra = {}) => {
    res.writeHead(code, { 'Content-Type': type, 'Content-Length': Buffer.byteLength(body), ...ISOLATION, ...extra });
    res.end(req.method === 'HEAD' ? undefined : body);
  };
  state.log.push(`${req.method} ${p}${req.headers.range ? ' ' + req.headers.range : ''}`);
  if (p === '/build/game.js') return send(200, state.oldBuild ? OLD_GAME_JS : FAKE_GAME_JS, 'text/javascript');
  if (p === '/missing-resource-preflight.mjs') return send(200, state.realOverlayPreflight ? PREFLIGHT_REAL_OVERLAY : PREFLIGHT_STUB, 'text/javascript');
  if (p === '/missing-resource-preflight.real.mjs') return send(200, readFileSync(join(dist, 'missing-resource-preflight.mjs')), 'text/javascript');
  const isOv = p.startsWith('/game-en/');
  if (isOv && state.noOverlay) return send(404, 'nope', 'text/plain');
  if (p === '/game-en/manifest.json' && state.ovManifest) return send(200, JSON.stringify(state.ovManifest), 'application/json');
  if (p === '/game/manifest.json' && state.gameManifest) return send(200, JSON.stringify(state.gameManifest), 'application/json');
  if (state.overrides?.has(p)) { state.overlayObjects++; return send(200, state.overrides.get(p), 'application/octet-stream', { 'Accept-Ranges': 'bytes' }); }
  const file = join(state.distDir, p === '/' ? 'index.html' : p.slice(1));
  if (p.includes('..') || !existsSync(file) || !statSync(file).isFile()) return send(404, 'nope', 'text/plain');
  if (isOv && p !== '/game-en/manifest.json') {
    state.overlayObjects++;
    if (state.overlayObjects > state.failOverlayAfter) return send(500, 'injected failure', 'text/plain');
  }
  if (state.delay && isOv) await sleep(state.delay);
  let body = readFileSync(file), status = 200;
  const headers = { ...ISOLATION, 'Accept-Ranges': 'bytes' };
  const m = /^bytes=(\d+)-(\d*)$/.exec(req.headers.range || '');
  let start = 0;
  if (m) { start = +m[1]; const end = m[2] === '' ? body.length - 1 : Math.min(+m[2], body.length - 1); headers['Content-Range'] = `bytes ${start}-${end}/${body.length}`; body = body.subarray(start, end + 1); status = 206; }
  if (state.corrupt && p === state.corrupt.path) { body = Buffer.from(body); const at = state.corrupt.at - start; if (at >= 0 && at < body.length) body[at] ^= 0xFF; }
  send(status, body, MIME[extname(file)] || 'application/octet-stream', headers);
});
await new Promise((ok, fail) => { srv.once('error', fail); srv.listen(0, '127.0.0.1', ok); });
const origin = `http://127.0.0.1:${srv.address().port}`;
const browser = await chromium.launch({ headless: true });
console.log('Chromium', browser.version());
process.on('exit', () => { try { srv.close(); } catch { /* gone */ } });

const overlayRequests = () => state.log.filter((l) => l.includes(' /game-en/') && !l.includes('manifest.json'));
const overlayManifestRequests = () => state.log.filter((l) => l.includes(' /game-en/manifest.json'));
const gameRequests = () => state.log.filter((l) => l.includes(' /game/') && !l.includes('manifest.json'));

async function openPage(ctx, query = '', init = null) {
  const page = await ctx.newPage();
  const errors = [], logs = [];
  page.on('pageerror', (e) => errors.push(e.message));
  page.on('console', (m) => { logs.push(m.text()); if (VERBOSE) console.log('   [page]', m.text()); });
  await page.addInitScript(() => {   // WebGPU не нужен: игра не запускается
    Object.defineProperty(navigator, 'gpu', { value: { requestAdapter: async () => ({ info: {}, isFallbackAdapter: false }) }, configurable: true });
  });
  if (init) await page.addInitScript(init);
  await page.goto(`${origin}/${query ? query + '&lazy=0' : '?lazy=0'}`);
  page.errors = errors; page.logs = logs;
  return page;
}
const settle = (page, timeout = 120_000) => page.waitForFunction(() =>
  !document.getElementById('view-home').classList.contains('hidden') && window.langInfo && !['unknown', 'installing'].includes(window.langInfo.overlay),
  null, { timeout });
const info = (page) => page.evaluate(() => JSON.parse(JSON.stringify(window.langInfo)));
const ui = (page) => page.evaluate(() => ({
  ruPressed: document.getElementById('lang-ru').getAttribute('aria-pressed'), enPressed: document.getElementById('lang-en').getAttribute('aria-pressed'),
  enDisabled: document.getElementById('lang-en').disabled, ruDisabled: document.getElementById('lang-ru').disabled, enTitle: document.getElementById('lang-en').title,
  status: document.getElementById('lang-status').textContent, note: document.getElementById('lang-note').textContent,
  backHidden: document.getElementById('lang-back-ru').classList.contains('hidden'), playDisabled: document.getElementById('play').disabled,
  stored: (() => { try { return localStorage.getItem('korsary2.lang'); } catch { return 'ERR'; } })() }));

/* независимый слепок OPFS: путь -> {size, sha256} (WebCrypto) для каталога верхнего уровня */
async function opfsTree(page, dirName) {
  return page.evaluate(async (name) => {
    const hex = async (b) => [...new Uint8Array(await crypto.subtle.digest('SHA-256', b))].map((x) => x.toString(16).padStart(2, '0')).join('');
    let dir;
    try { dir = await (await navigator.storage.getDirectory()).getDirectoryHandle(name); } catch (e) { return null; }
    const out = {};
    const walk = async (d, prefix) => {
      for await (const [n, h] of d.entries()) {
        if (h.kind === 'directory') await walk(h, prefix + n + '/');
        else { const f = await h.getFile(); out[prefix + n] = { size: f.size, sha256: await hex(await f.arrayBuffer()) }; }
      }
    };
    await walk(dir, '');
    return out;
  }, dirName);
}
const expectInstalled = (tree, manifest, markerName, label) => {
  assert.ok(tree, `${label}: каталога нет`);
  for (const f of manifest.files) {
    const got = tree[f.path];
    assert.ok(got, `${label}: нет файла ${f.path}`);
    assert.deepEqual([got.size, got.sha256], [f.size, f.sha256], `${label}: ${f.path} не совпадает с манифестом`);
  }
  assert.ok(tree[markerName], `${label}: нет метки ${markerName}`);
};
const stripMarkers = (t) => Object.fromEntries(Object.entries(t || {}).filter(([k]) => !/^installed(-en)?\.json$/.test(k)));
const markerOf = async (page, dirName, name) => page.evaluate(async ([d, n]) => {
  try { return JSON.parse(await (await (await (await navigator.storage.getDirectory()).getDirectoryHandle(d)).getFileHandle(n)).getFile().then((f) => f.text())); } catch { return null; }
}, [dirName, name]);

let passed = 0;
const done = (msg) => { passed++; console.log('ok -', msg); };
const ONLY = process.env.OVERLAY_ONLY ? process.env.OVERLAY_ONLY.split(',') : null;   // e.g. OVERLAY_ONLY=A,B,D,E (mutation runs)
async function scenario(name, fn) {
  if (ONLY && !ONLY.includes(name.split('-')[0])) return false;
  const ctx = await browser.newContext();
  try { await fn(ctx); } finally { await ctx.close(); }
  return true;
}

try {
  /* A. русский по умолчанию */
  await scenario('A', async (ctx) => {
    reset();
    const page = await openPage(ctx);
    await settle(page);
    const li = await info(page);
    assert.deepEqual([li.lang, li.source, li.overlay], ['ru', 'default', 'absent']);
    assert.deepEqual(overlayRequests(), [], 'русский режим не качает ни одного объекта game-en/');
    assert.deepEqual(overlayManifestRequests(), ['HEAD /game-en/manifest.json'], 'ровно один HEAD манифеста: есть ли слой');
    assert.equal(await opfsTree(page, 'korsary2-game-en'), null, 'каталога оверлея нет');
    const u = await ui(page);
    assert.deepEqual([u.ruPressed, u.enPressed, u.enDisabled, u.playDisabled, u.stored], ['true', 'false', false, false, null]);
    assert.ok(/применяется при запуске/.test(u.note), 'пояснение про следующий запуск');
    // запуск русского: env как раньше, PORT_OVERLAY нет
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    const port = await page.evaluate(() => window.__port);
    assert.deepEqual(port.arguments, ['/opfs/korsary2-game']);
    assert.equal('PORT_OVERLAY' in port.env, false, 'в русском режиме PORT_OVERLAY не задаётся (код оверлея в хосте не выполняется)');
    assert.deepEqual(page.errors.filter((e) => !/synthetic runtime stop/.test(e)), []);
    done('A русский по умолчанию: один HEAD game-en/manifest.json, объектов оверлея 0, каталога оверлея нет, env без PORT_OVERLAY');
  });

  /* B. ?lang=en на чистом профиле */
  let baseSnapshot;
  await scenario('B', async (ctx) => {
    reset();
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    const li = await info(page);
    assert.deepEqual([li.lang, li.source, li.overlay, li.installed], ['en', 'url', 'ready', 'installed']);
    assert.equal(li.hostPath, '/opfs/korsary2-game-en');
    assert.equal(li.dir, 'korsary2-game-en');
    const base = await opfsTree(page, 'korsary2-game');
    expectInstalled(base, gameManifest(), 'installed.json', 'база');
    const ov = await opfsTree(page, 'korsary2-game-en');
    expectInstalled(ov, ovManifest(), 'installed-en.json', 'оверлей');
    assert.equal(Object.keys(stripMarkers(ov)).length, ovManifest().files.length, 'в оверлее ровно файлы манифеста');
    assert.deepEqual(Object.keys(ov).filter((k) => /^(SAVE|options|engine\.ini)/i.test(k)), [], 'в оверлее нет SAVE/options/engine.ini');
    assert.equal((await markerOf(page, 'korsary2-game-en', 'installed-en.json')).version, ovManifest().version);
    assert.equal((await markerOf(page, 'korsary2-game', 'installed.json')).version, gameManifest().version, 'метка базы — её версия, не оверлея');
    assert.equal(await page.evaluate(() => { try { return localStorage.getItem('korsary2.lang'); } catch { return 'ERR'; } }), null, '?lang= не записывается сам (только выбор игрока)');
    const stats = await page.evaluate(() => window.overlayInstallStats);
    assert.equal(stats.files, ovManifest().files.length);
    assert.ok(ovManifest().packs.length >= 1 && stats.packs === ovManifest().packs.length);
    baseSnapshot = stripMarkers(base);
    // запуск английского: env для хоста
    const u = await ui(page);
    assert.deepEqual([u.enPressed, u.playDisabled], ['true', false]);
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    const port = await page.evaluate(() => window.__port);
    assert.deepEqual(port.arguments, ['/opfs/korsary2-game'], 'аргумент игры — база, как раньше');
    assert.equal(port.env.PORT_OVERLAY, '/opfs/korsary2-game-en', 'оверлей — второй каталог OPFS, как его видит хост');
    assert.equal((await info(page)).launched.hostPath, '/opfs/korsary2-game-en');
    assert.deepEqual(page.errors.filter((e) => !/synthetic runtime stop/.test(e)), []);
    done(`B ?lang=en: база и оверлей установлены (${ovManifest().files.length} файлов оверлея, SHA-256 верны), метки раздельны, env PORT_OVERLAY=/opfs/korsary2-game-en`);
  });

  /* C. переключатель на странице, запоминание, смена без перекачки */
  await scenario('C', async (ctx) => {
    reset();
    let page = await openPage(ctx);
    await settle(page);
    const before = gameRequests().length;
    await page.click('#lang-en');
    await page.waitForFunction(() => window.langInfo.overlay === 'ready', null, { timeout: 120_000 });
    let u = await ui(page);
    assert.deepEqual([u.enPressed, u.ruPressed, u.stored, u.playDisabled], ['true', 'false', 'en', false]);
    assert.equal(gameRequests().length, before, 'русская установка не перекачивалась');
    assert.ok(overlayRequests().length >= 1);
    assert.match(u.note, /applied when the game starts.*does not change.*another tab/s);
    // назад на русский: запомнено, перекачки нет
    const ovReq = overlayRequests().length;
    await page.click('#lang-ru');
    await page.waitForFunction(() => window.langInfo.lang === 'ru');
    u = await ui(page);
    assert.deepEqual([u.ruPressed, u.stored], ['true', 'ru']);
    assert.equal(overlayRequests().length, ovReq);
    // снова English: оверлей уже установлен, ничего не качается
    await page.click('#lang-en');
    await page.waitForFunction(() => window.langInfo.lang === 'en' && window.langInfo.overlay === 'ready');
    assert.equal(overlayRequests().length, ovReq, 'повторный выбор English: объектов не качается');
    await page.close();
    // новая страница без ?lang: берёт запомненное, оверлей текущий -> ни одного объекта
    state.log = [];
    page = await openPage(ctx);
    await settle(page);
    const li = await info(page);
    assert.deepEqual([li.lang, li.source, li.overlay, li.installed], ['en', 'storage', 'ready', 'current']);
    assert.deepEqual([overlayRequests().length, gameRequests().length], [0, 0], 'следующий запуск: ничего не качается');
    assert.equal(overlayManifestRequests().length, 1, 'манифест слоя запрошен GET один раз (HEAD при английском не нужен)');
    // ?lang=ru перекрывает запомненное, не меняя его
    const p2 = await openPage(ctx, '?lang=ru');
    await settle(p2);
    assert.deepEqual([(await info(p2)).lang, (await info(p2)).source, (await ui(p2)).stored], ['ru', 'url', 'en']);
    done('C переключатель: English ставит слой по нажатию, localStorage, смена языка без перекачки, следующий запуск из localStorage, ?lang перекрывает');
  });

  /* D. обрыв установки оверлея -> безопасный отказ, возврат к русскому, продолжение */
  await scenario('D', async (ctx) => {
    reset({ failOverlayAfter: 0 });   // база ставится (game/), любой объект оверлея -> 500
    let page = await openPage(ctx, '?lang=en');
    await settle(page);
    let li = await info(page);
    assert.deepEqual([li.lang, li.overlay], ['en', 'error']);
    let u = await ui(page);
    assert.equal(u.playDisabled, true, 'при неготовом слое Play заблокирован');
    assert.equal(u.backHidden, false, 'предложено вернуться к русскому');
    assert.match(u.status, /Could not install or verify.*Return to Russian/i);
    assert.match(page.logs.join('\n'), /HTTP 500|500/);
    // запуск не стартует (кнопка заблокирована; прямой вызов — тоже отказ)
    await page.evaluate(() => { document.getElementById('play').disabled = false; document.getElementById('play').click(); });
    await sleep(500);
    assert.equal(await page.evaluate(() => !!window.__port), false, 'английский не запускается без слоя');
    assert.equal(await markerOf(page, 'korsary2-game-en', 'installed-en.json'), null, 'метки слоя нет');
    const baseTree = await opfsTree(page, 'korsary2-game');
    expectInstalled(baseTree, gameManifest(), 'installed.json', 'база после сбоя оверлея');
    // вернуться к русскому: Play работает, env без оверлея
    await page.click('#lang-back-ru');
    await page.waitForFunction(() => window.langInfo.lang === 'ru');
    u = await ui(page);
    assert.deepEqual([u.ruPressed, u.playDisabled, u.backHidden, u.stored], ['true', false, true, 'ru']);
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    assert.equal('PORT_OVERLAY' in (await page.evaluate(() => window.__port.env)), false);
    await page.close();
    // сервер здоров: продолжение
    reset({});
    page = await openPage(ctx, '?lang=en');
    await settle(page);
    li = await info(page);
    assert.deepEqual([li.lang, li.overlay], ['en', 'ready']);
    expectInstalled(await opfsTree(page, 'korsary2-game-en'), ovManifest(), 'installed-en.json', 'оверлей после повтора');
    assert.deepEqual(gameRequests(), [], 'русская база не перекачивалась');
    done('D обрыв оверлея: Play заблокирован, метки нет, «Вернуться к русскому» работает и запускает русский, повтор ставит слой, база не перекачивается');
  });

  /* E. порча объектов оверлея */
  for (const kind of ['loose', 'pack']) await scenario('E-' + kind, async (ctx) => {
    const m = ovManifest();
    const victim = kind === 'loose' ? m.files.find((e) => e.pack === undefined && e.path.endsWith('Eng_long.wav'))
      : m.files.find((e) => e.pack !== undefined && e.enc === 'gzip' && e.csize > 400);
    const path = kind === 'loose' ? '/game-en/' + victim.path + (victim.enc ? '.gz' : '') : '/game-en/' + m.packs[victim.pack].path;
    reset({ corrupt: { path, at: kind === 'loose' ? 1000 : victim.offset + 40 } });
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    const li = await info(page);
    assert.equal(li.overlay, 'error', kind);
    assert.match((await ui(page)).status, /Could not install or verify.*Return to Russian/i, kind);
    assert.match(page.logs.join('\n'), /SHA-256|не совпадает|повреждён|распаков|gzip|данные|not valid/i, kind);
    const tree = await opfsTree(page, 'korsary2-game-en');
    assert.equal(tree?.['installed-en.json'], undefined, 'метки нет');
    assert.equal(tree?.[victim.path], undefined, 'испорченный файл не остался в OPFS');
    for (const [p, v] of Object.entries(stripMarkers(tree))) {   // всё, что успело установиться, целое
      const f = m.files.find((e) => e.path === p);
      assert.deepEqual([v.size, v.sha256], [f.size, f.sha256], p);
    }
    expectInstalled(await opfsTree(page, 'korsary2-game'), gameManifest(), 'installed.json', 'база');
    assert.equal((await ui(page)).playDisabled, true);
    done(`E порча (${kind}): английский отклонён, файла в OPFS нет, метки нет, установленное целое, база цела`);
  });

  /* F. квота */
  await scenario('F', async (ctx) => {
    reset();
    let page = await openPage(ctx);   // русская установка (оценка квоты нормальная)
    await settle(page);
    await page.close();
    state.log = [];
    page = await openPage(ctx, '?lang=en', () => {
      const real = navigator.storage.estimate.bind(navigator.storage);
      navigator.storage.estimate = async () => ({ ...(await real()), quota: 50_000, usage: 0 });   // 50 КБ на всё
    });
    await settle(page);
    const li = await info(page);
    assert.equal(li.overlay, 'error');
    assert.match((await ui(page)).status, /Could not install or verify.*Return to Russian/i);
    assert.match(page.logs.join('\n'), /Недостаточно места/);
    assert.deepEqual(overlayRequests(), [], 'до первой записи: ни одного объекта оверлея не запрошено');
    assert.equal(await opfsTree(page, 'korsary2-game-en'), null, 'каталог оверлея даже не создан');
    assert.equal((await page.evaluate(() => window.overlayStoragePreflight)).status, 'insufficient');
    done('F квота: отказ ДО записи (объектов 0, каталога нет), сообщение о месте');
  });

  /* G. запрещённые пути и нет SHA в манифесте оверлея */
  for (const [label, mutate, re] of [
    ['SAVE в манифесте', (m) => { m.files.push({ path: 'SAVE/slot1', size: 1, sha256: '0'.repeat(64) }); }, /сохранения игрока/],
    ['options в манифесте', (m) => { m.files.push({ path: 'options', size: 1, sha256: '0'.repeat(64) }); }, /настройки игрока/],
    ['engine.ini в манифесте', (m) => { m.files.push({ path: 'engine.ini', size: 1, sha256: '0'.repeat(64) }); }, /настройки движка/],
    ['.. в пути', (m) => { m.files.push({ path: 'RESOURCE/../SAVE/x', size: 1, sha256: '0'.repeat(64) }); }, /\.\./],
    ['нет SHA-256', (m) => { delete m.files.find((f) => f.path === 'RESOURCE/INI/fonts.ini').sha256; }, /нет SHA-256/],
    ['нет обязательного файла', (m) => { m.files = m.files.filter((f) => f.path !== 'RESOURCE/INI/TEXTS/language.ini'); delete m.overlay.base['RESOURCE/INI/TEXTS/language.ini']; }, /обязательного файла/],
  ]) await scenario('G-' + label, async (ctx) => {
    const m = ovManifest(); mutate(m);
    reset({ ovManifest: m });
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'error', label);
    assert.match((await ui(page)).status, /Could not install or verify.*Return to Russian/i, label);
    assert.match(page.logs.join('\n'), re, label);
    assert.deepEqual(overlayRequests(), [], `${label}: отказ до первой загрузки`);
    assert.equal(await opfsTree(page, 'korsary2-game-en'), null, `${label}: до первой записи`);
    assert.equal((await ui(page)).playDisabled, true);
  }).then((ran) => { if (ran) done(`G ${label}: отказ до первой записи (объектов 0, каталога нет)`); });

  /* H. dist без game-en/ */
  await scenario('H', async (ctx) => {
    reset({ distDir: fxOld.dist });
    let page = await openPage(ctx);
    await settle(page);
    let u = await ui(page);
    assert.equal((await info(page)).overlay, 'unavailable');
    assert.deepEqual([u.enDisabled, u.playDisabled], [true, false]);
    assert.match(u.enTitle, /нет game-en/);
    assert.match(u.status, /не опубликован/);
    await page.close();
    page = await openPage(ctx, '?lang=en');
    await settle(page);
    const li = await info(page);
    assert.deepEqual([li.lang, li.overlay], ['ru', 'unavailable'], '?lang=en без слоя на сервере: идёт русский');
    u = await ui(page);
    assert.deepEqual([u.ruPressed, u.playDisabled], ['true', false]);
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    assert.equal('PORT_OVERLAY' in (await page.evaluate(() => window.__port.env)), false);
    // запомненный English из dist, где слой был, на dist без слоя: тоже русский, выбор в хранилище сохраняется
    await page.evaluate(() => localStorage.setItem('korsary2.lang', 'en'));
    await page.reload();
    await settle(page);
    assert.deepEqual([(await info(page)).lang, (await ui(page)).stored], ['ru', 'en']);
    done('H старый dist без game-en/: English отключён с пояснением, ?lang=en и запомненный English дают русский');
  });

  /* I. SAVE и база не тронуты; экспорт сохранений без оверлея */
  await scenario('I', async (ctx) => {
    reset();
    let page = await openPage(ctx);
    await settle(page);
    await page.evaluate(async () => {   // «сохранение игрока» в SAVE базы (как пишет игра)
      const game = await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game');
      const save = await game.getDirectoryHandle('SAVE', { create: true });
      const w = await (await save.getFileHandle('slot1', { create: true })).createWritable();
      await w.write(new TextEncoder().encode('PLAYER SAVE SLOT 1')); await w.close();
    });
    const before = await opfsTree(page, 'korsary2-game');
    const markerBefore = await markerOf(page, 'korsary2-game', 'installed.json');
    await page.click('#lang-en');
    await page.waitForFunction(() => window.langInfo.overlay === 'ready', null, { timeout: 120_000 });
    const after = await opfsTree(page, 'korsary2-game');
    assert.deepEqual(after, before, 'база (включая SAVE и метку) не изменилась ни на байт');
    assert.deepEqual(await markerOf(page, 'korsary2-game', 'installed.json'), markerBefore, 'метка базы та же, вместе с отметкой времени');
    const exported = await page.evaluate(async () => {
      const { openSaveDirectory, readSaveDirectory, encodeBackup } = await import('./save-export.mjs');
      const root = await navigator.storage.getDirectory();
      const gameDir = async (create) => root.getDirectoryHandle('korsary2-game', { create });
      const dir = await openSaveDirectory(gameDir);
      const entries = await readSaveDirectory(dir, await gameDir(false));
      const zip = encodeBackup(entries);
      return { names: entries.map((e) => e.name), zipText: new TextDecoder('latin1').decode(zip) };
    });
    assert.ok(exported.names.length >= 1 && exported.names.every((n) => /^SAVE\//i.test(n) || /^SAVE_META\//i.test(n) || !n.includes('/')), `экспорт: ${exported.names}`);
    assert.ok(!exported.zipText.includes('language.ini') && !exported.zipText.includes('PROGRAM/'), 'в архив сохранений оверлей не попадает');
    // резервной копии SAVE перед установкой оверлея нет (оверлей SAVE не трогает): каталога backups нет
    assert.equal(await page.evaluate(async () => { try { await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game-backups'); return true; } catch { return false; } }), false);
    done('I SAVE/база не тронуты установкой оверлея, метка базы та же; экспорт сохранений не включает оверлей; архив SAVE не делался');
  });

  /* J. игра держит SAVE-замок в другой вкладке */
  await scenario('J', async (ctx) => {
    reset();
    const first = await openPage(ctx);   // русская установка
    await settle(first);
    // «работающая игра»: эта вкладка держит замок базы всю жизнь страницы
    await first.evaluate(() => { navigator.locks.request('korsary2-game:save-backup', { mode: 'exclusive' }, () => new Promise(() => {})); });
    await sleep(200);
    state.log = [];
    const second = await openPage(ctx, '?lang=en');
    // база текущая: старт страницы не берёт замок (метка совпала раньше замка в этом коде? нет — база берёт замок и отказывает); проверяем итог
    await sleep(1500);
    const status = await second.evaluate(() => document.getElementById('status').textContent);
    if (/Update failed/.test(status)) {
      assert.match(status, /заняты|Update failed/);   // базовое поведение: вторая вкладка при запущенной игре не стартует (как и до E1)
      assert.deepEqual(overlayRequests(), []);
      done('J вторая вкладка при работающей игре: страница отказывает как и раньше, объектов оверлея не запрошено, ничего не записано');
    } else {
      await settle(second);
      assert.equal((await info(second)).overlay, 'error');
      assert.match((await ui(second)).status, /another game tab.*save lock/i);
      assert.deepEqual(overlayRequests(), []);
      assert.equal(await opfsTree(second, 'korsary2-game-en'), null);
      done('J игра держит замок: установка оверлея отказывает (занято), объектов 0, каталога нет');
    }
  });

  /* K. обновление оверлея: докачиваются только изменённые файлы */
  await scenario('K', async (ctx) => {
    reset();
    let page = await openPage(ctx, '?lang=en');
    await settle(page);
    const first = ovManifest();
    await page.close();
    // новая версия слоя на сервере: один изменённый файл (отдаётся как есть, без пакета и без enc)
    const m2 = JSON.parse(JSON.stringify(first));
    const changed = m2.files.find((f) => f.path === 'PROGRAM/DIALOGS/q001_dialog.h');
    const data = Buffer.from('CHANGED DIALOG TEXT '.repeat(30));
    changed.size = data.length; changed.sha256 = createHash('sha256').update(data).digest('hex');
    delete changed.enc; delete changed.csize; delete changed.pack; delete changed.offset;
    m2.version = 'f'.repeat(12);
    reset({ ovManifest: m2, overrides: new Map([['/game-en/PROGRAM/DIALOGS/q001_dialog.h', data]]) });
    page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'ready');
    expectInstalled(await opfsTree(page, 'korsary2-game-en'), m2, 'installed-en.json', 'оверлей v2');
    assert.equal((await markerOf(page, 'korsary2-game-en', 'installed-en.json')).version, m2.version);
    const reqs = overlayRequests();
    assert.ok(reqs.some((l) => l.includes('q001_dialog.h')), 'изменённый файл докачан');
    assert.ok(!reqs.some((l) => l.includes('_k2pack')), `пакеты не качались заново: ${reqs}`);
    assert.deepEqual(gameRequests(), [], 'база не перекачивалась');
    done('K обновление слоя: докачан только изменённый файл (пакеты и база не перекачивались), метка новой версии');
  });

  /* L. оверлей собран на другой русской раздаче */
  await scenario('L', async (ctx) => {
    const m = ovManifest();
    const victim = Object.keys(m.overlay.base)[0];
    m.overlay.base[victim] = 'a'.repeat(64);
    reset({ ovManifest: m });
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'error');
    assert.match((await ui(page)).status, /Could not install or verify.*Return to Russian/i);
    assert.match(page.logs.join('\n'), /другой версии русской раздачи/);
    assert.deepEqual(overlayRequests(), []);
    assert.equal((await ui(page)).playDisabled, true);
    done('L оверлей собран на другой русской раздаче: английский запрещён до загрузки, русский работает');
  });

  /* M. метка есть, файлов нет: починка при старте; при невозможности — отказ */
  await scenario('M', async (ctx) => {
    reset();
    let page = await openPage(ctx, '?lang=en');
    await settle(page);
    await page.evaluate(async () => {   // «браузер почистил часть хранилища»: файл исчез, метка осталась
      const d = await (await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game-en')).getDirectoryHandle('PROGRAM');
      const dl = await d.getDirectoryHandle('DIALOGS');
      await dl.removeEntry('q003_dialog.h');
    });
    await page.close();
    state.log = [];
    page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'ready', 'неполный слой починен при старте');
    expectInstalled(await opfsTree(page, 'korsary2-game-en'), ovManifest(), 'installed-en.json', 'после починки');
    assert.ok(overlayRequests().length >= 1 && overlayRequests().length < ovManifest().files.length, 'докачано только недостающее');
    await page.close();
    // и при недоступном сервере починить нельзя: безопасный отказ
    const p2 = await openPage(ctx, '');
    await settle(p2);
    await p2.evaluate(async () => {
      const d = await (await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game-en')).getDirectoryHandle('PROGRAM');
      await (await d.getDirectoryHandle('DIALOGS')).removeEntry('q004_dialog.h');
    });
    await p2.close();
    reset({ failOverlayAfter: 0 });
    const p3 = await openPage(ctx, '?lang=en');
    await settle(p3);
    const li = await info(p3);
    assert.equal(li.overlay, 'error');
    assert.match((await ui(p3)).status, /Return to Russian/i);
    assert.equal((await ui(p3)).playDisabled, true);
    await p3.evaluate(() => { document.getElementById('play').disabled = false; document.getElementById('play').click(); });
    await sleep(400);
    assert.equal(await p3.evaluate(() => !!window.__port), false, 'неполный слой: английский не стартует');
    done('M слой неполон при установленной метке: починка при старте (докачано недостающее); невозможно починить — безопасный отказ');
  });

  /* N. сервер манифеста недоступен (нет сети): установленный слой проверяется по метке и работает; не установленный — отказ */
  await scenario('N', async (ctx) => {
    reset();
    let page = await openPage(ctx, '?lang=en');
    await settle(page);
    const marker = await markerOf(page, 'korsary2-game-en', 'installed-en.json');
    assert.ok(Array.isArray(marker.files) && marker.files.length === ovManifest().files.length, 'метка хранит список файлов слоя');
    await page.close();
    state.log = [];
    page = await ctx.newPage();
    await page.addInitScript(() => { Object.defineProperty(navigator, 'gpu', { value: { requestAdapter: async () => ({ info: {}, isFallbackAdapter: false }) }, configurable: true }); });
    await page.route('**/game-en/manifest.json', (route) => route.abort());
    await page.goto(`${origin}/?lang=en&lazy=0`);
    page.on('console', (m) => { if (VERBOSE) console.log('   [page2]', m.text()); });
    await settle(page);
    const li = await info(page);
    assert.deepEqual([li.overlay, li.installed, li.version, li.error], ['ready', 'offline', ovManifest().version, null]);
    assert.deepEqual(overlayRequests(), []);
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    assert.equal((await page.evaluate(() => window.__port.env)).PORT_OVERLAY, '/opfs/korsary2-game-en');
    await page.close();
    // слоя нет в OPFS и манифест недоступен: безопасный отказ
    const ctx2 = await browser.newContext();
    try {
      const p2 = await ctx2.newPage();
      await p2.addInitScript(() => { Object.defineProperty(navigator, 'gpu', { value: { requestAdapter: async () => ({ info: {}, isFallbackAdapter: false }) }, configurable: true }); });
      await p2.route('**/game-en/manifest.json', (route) => route.abort());
      await p2.goto(`${origin}/?lang=en&lazy=0`);
      await settle(p2);
      assert.equal((await info(p2)).overlay, 'error');
      assert.equal((await ui(p2)).playDisabled, true);
    } finally { await ctx2.close(); }
    done('N манифест слоя недоступен: установленный слой проверен по метке и запущен (PORT_OVERLAY задан); неустановленный — безопасный отказ');
  });

  /* O. сборка игры старше E1 (её glue не экспортирует port_overlay_state): английский не стартует, русский работает */
  await scenario('O', async (ctx) => {
    reset({ oldBuild: true });
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'ready');
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => /English language files are incomplete or changed/.test(document.getElementById('lang-status').textContent), null, { timeout: 30_000 });
    assert.equal(await page.evaluate(() => !!window.__port), false, 'игра не запущена');
    if (VERBOSE) console.log(JSON.stringify(await ui(page)), await page.evaluate(() => JSON.stringify({ lang: window.langInfo.lang, ov: window.langInfo.overlay, view: [...document.querySelectorAll('#panel .view')].map((v) => v.id + ':' + v.classList.contains('hidden')), panel: document.getElementById('panel').className })));
    assert.equal((await ui(page)).backHidden, false, 'предложено вернуться к русскому');
    await page.click('#lang-back-ru');
    await page.waitForFunction(() => window.langInfo.lang === 'ru');
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    assert.equal('PORT_OVERLAY' in (await page.evaluate(() => window.__port.env)), false);
    done('O старая сборка игры без поддержки оверлея: английский не стартует (понятный отказ + возврат), русский запускается');
  });

  /* P. слой стал неполным уже после готовности (файл исчез до нажатия Play): запуск перепроверяет под замком и отказывает */
  await scenario('P', async (ctx) => {
    reset();
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'ready');
    await page.evaluate(async () => {
      const d = await (await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game-en')).getDirectoryHandle('PROGRAM');
      await (await d.getDirectoryHandle('DIALOGS')).removeEntry('q010_dialog.h');
    });
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => /English language files are incomplete or changed/.test(document.getElementById('lang-status').textContent), null, { timeout: 30_000 });
    assert.equal(await page.evaluate(() => !!window.__port), false, 'игра не запущена');
    const u = await ui(page);
    assert.deepEqual([u.backHidden, u.playDisabled], [false, true]);
    // замок игры отпущен (ничего не стартовало): повторная установка слоя возможна, русский тоже
    await page.click('#lang-back-ru');
    await page.waitForFunction(() => window.langInfo.lang === 'ru');
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    done('P слой стал неполным после готовности: запуск английского перепроверяется под замком и отказывает, замок не остаётся занятым, русский запускается');
  });

  /* Q. E5: настоящая проверка английского слоя перед запуском (missing-resource-preflight.mjs из dist): чистый слой запускается, слой с language.ini,
        который оставил бы игру русской (размер как у английского: Russian/English — по 7 букв), отказывает ДО замков, с возвратом к русскому */
  await scenario('Q', async (ctx) => {
    reset({ realOverlayPreflight: true });
    const page = await openPage(ctx, '?lang=en');
    await settle(page);
    assert.equal((await info(page)).overlay, 'ready');
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    const pf = await page.evaluate(() => window.overlayPreflight);
    // у синтетического слоя нет озвучки/экранов/части текстов: это предупреждения (RES_MISSING), не отказ; обязательные файлы на месте
    assert.deepEqual([pf.kind, pf.status, pf.mode, pf.counts.fatal], ['overlay', 'warn', 'verified', 0], JSON.stringify(pf.findings));
    assert.ok(pf.findings.every((f) => f.severity === 'warn' && f.code === 'RES_MISSING'), JSON.stringify(pf.findings));
    assert.ok(pf.items.some((i) => i.path === 'RESOURCE/INI/TEXTS/language.ini' && i.verified === 'hash'));
    assert.equal((await page.evaluate(() => window.__port.env.PORT_OVERLAY)), '/opfs/korsary2-game-en');
    // новая вкладка того же профиля нельзя (игра держит замок): отдельный чистый контекст, слой портится после установки
    const ctx2 = await browser.newContext();
    try {
      reset({ realOverlayPreflight: true });
      const p2 = await openPage(ctx2, '?lang=en');
      await settle(p2);
      assert.equal((await info(p2)).overlay, 'ready');
      await p2.evaluate(async () => {   // тот же размер, другой язык: проверка полноты по размерам этого не видит
        const d = await (await (await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game-en')).getDirectoryHandle('RESOURCE')).getDirectoryHandle('INI');
        const f = await (await d.getDirectoryHandle('TEXTS')).getFileHandle('language.ini');
        const text = await (await f.getFile()).text();
        const w = await f.createWritable(); await w.write(text.replaceAll('English', 'russian')); await w.close();
      });
      await p2.evaluate(() => document.getElementById('play').click());
      await p2.waitForFunction(() => window.overlayPreflight?.status === 'blocked', null, { timeout: 30_000 });
      assert.equal(await p2.evaluate(() => !!window.__port), false, 'игра не запущена');
      const u = await ui(p2);
      assert.match(u.status, /Required English language files are missing or unreadable.*return to Russian/i);
      assert.deepEqual([u.backHidden, u.playDisabled], [false, true]);
      assert.equal((await info(p2)).overlay, 'error');
      assert.equal(await p2.evaluate(() => window.overlayPreflight.status), 'blocked');
      assert.ok(p2.logs.some((l) => /\[preflight-en\] fatal RES_BAD_CONTENT/.test(l)), 'причина в консоли');
      // замок игры не взят: возврат к русскому и запуск русского
      const preLines = p2.logs.filter((l) => /\[preflight-en\]/.test(l)).length;
      await p2.click('#lang-back-ru');
      await p2.waitForFunction(() => window.langInfo.lang === 'ru');
      await p2.evaluate(() => document.getElementById('play').click());
      await p2.waitForFunction(() => window.__port, null, { timeout: 30_000 });
      assert.equal('PORT_OVERLAY' in (await p2.evaluate(() => window.__port.env)), false);
      assert.equal(p2.logs.filter((l) => /\[preflight-en\]/.test(l)).length, preLines, 'русский режим проверку слоя не вызывает');
    } finally { await ctx2.close(); }
    done('Q проверка английского слоя перед запуском: слой без рекомендуемых файлов — предупреждения, запуск (SHA сверены), language.ini с русским языком — отказ до замков с причиной и возвратом к русскому');
  });

  /* R. E5: язык слотов — неблокирующее уведомление при старте и при смене языка; ничего не пишется (SAVE и SAVE_META побайтно те же) */
  await scenario('R', async (ctx) => {
    reset();
    const page = await openPage(ctx);
    await settle(page);
    const note = (p) => p.evaluate(() => ({ hidden: document.getElementById('slot-lang-note').classList.contains('hidden'), text: document.getElementById('slot-lang-note').textContent,
      play: document.getElementById('play').disabled, info: window.slotLanguages ? { ...window.slotLanguages } : null }));
    assert.equal((await note(page)).hidden, true, 'нет слотов — нет уведомления');
    await page.evaluate(async () => {   // три слота: один создан в английском режиме (метка en), два без метки
      const game = await (await navigator.storage.getDirectory()).getDirectoryHandle('korsary2-game');
      const save = await game.getDirectoryHandle('SAVE', { create: true }), meta = await game.getDirectoryHandle('SAVE_META', { create: true });
      const put = async (d, n, b) => { const w = await (await d.getFileHandle(n, { create: true })).createWritable(); await w.write(b); await w.close(); };
      const enc = new TextEncoder();
      for (const n of ['Oxbay', 'Douwesen', 'Isla']) await put(save, n, enc.encode('slot ' + n));
      await put(meta, 'Douwesen.lang', enc.encode('en')); await put(meta, 'Oxbay.time', new Uint8Array(8));
    });
    const treeBefore = JSON.stringify(Object.entries(await opfsTree(page, 'korsary2-game')).filter(([k]) => /^SAVE/.test(k)));
    await page.reload();
    await settle(page);
    let n = await note(page);
    assert.equal(n.hidden, false); assert.match(n.text, /Часть сохранений \(1 из 3\) создана в другом языке; имена персонажей в них могут отображаться на другом языке/);
    assert.ok(!/не помечены/.test(n.text)); assert.equal(n.play, false, 'уведомление не блокирует запуск');
    assert.deepEqual([n.info.lang, n.info.total, n.info.other, n.info.unmarked], ['ru', 3, 1, 2]);
    // выбор English: другой язык теперь «другой» для меток ru, а непомеченные названы осторожно
    await page.click('#lang-en');
    await page.waitForFunction(() => window.langInfo.overlay === 'ready', null, { timeout: 120_000 });
    await page.waitForFunction(() => window.slotLanguages?.lang === 'en', null, { timeout: 30_000 });
    n = await note(page);
    assert.equal(n.hidden, false); assert.match(n.text, /2 of 3 saves have no language label/); assert.doesNotMatch(n.text, /predate this feature/); assert.ok(!/создана в другом языке/.test(n.text));
    assert.equal(n.play, false);
    assert.equal(JSON.stringify(Object.entries(await opfsTree(page, 'korsary2-game')).filter(([k]) => /^SAVE/.test(k))), treeBefore, 'SAVE и SAVE_META не изменились');
    // запуск игры по-прежнему возможен: уведомление ничего не держит
    await page.evaluate(() => document.getElementById('play').click());
    await page.waitForFunction(() => window.__port, null, { timeout: 30_000 });
    done('R язык слотов: уведомление о слотах другого языка / непомеченных, не блокирует запуск, ничего не пишет');
  });

  console.log(`overlay browser (настоящий port.js + Chromium + OPFS): PASS (${passed} сценариев)`);
} finally {
  await browser.close();
  srv.close();
  writeFileSync(join(tmp, 'done'), 'x');
}
