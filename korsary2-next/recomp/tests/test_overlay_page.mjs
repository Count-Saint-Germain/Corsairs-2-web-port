/* E1: страничная часть оверлея языка (web/overlay.mjs) без браузера: выбор языка (адрес / localStorage / умолчание), СТРОГИЙ валидатор манифеста
   оверлея (отказ ДО записи), согласованность правил с packager-ом (gamefiles.overlay_path_problem, тот же список путей), установка под тем же
   страничным SAVE-замком, что и базовая (имя замка, порядок, занято = отказ, «текущая метка» не берёт замок), быстрая проверка полноты,
   квота оверлея отдельно (planStorageNeed). Манифесты берутся из настоящего make_dist на синтетической фикстуре (tests/overlay_fixture.mjs).
     node tests/test_overlay_page.mjs */
import assert from 'node:assert/strict';
import { buildFixture } from './overlay_fixture.mjs';
import { overlayPathProblem as builderPathProblem } from '../web/gamefiles.mjs';
import { overlayPathProblem as verifierPathProblem } from './verify_dist_overlay.mjs';
import { mkdtempSync, readFileSync, rmSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join, dirname, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { LANG_KEY, OVERLAY_REQUIRED, OVERLAY_RECOMMENDED, OVERLAY_BASE_RECOMMENDED, chooseLang, rememberLang, normalizeLang, overlayDirName, overlayHostPath, overlayPathProblem, validateOverlayManifest,
  installOverlayUnderSaveLock, verifyOverlayFiles, incompleteOverlayMessage, OverlayError } from '../web/overlay.mjs';
import { saveLockName } from '../web/save-export.mjs';
import { planStorageNeed, assessStorage, checkStorageForSync } from '../web/save-protection.mjs';

const here = dirname(fileURLToPath(import.meta.url));
const tmp = mkdtempSync(join(tmpdir(), 'k2-overlay-page-'));
process.on('exit', () => rmSync(tmp, { recursive: true, force: true }));
await buildFixture(tmp);
const ovManifest = JSON.parse(readFileSync(join(tmp, 'dist/game-en/manifest.json'), 'utf8'));
const baseManifest = JSON.parse(readFileSync(join(tmp, 'dist/game/manifest.json'), 'utf8'));
const clone = (x) => JSON.parse(JSON.stringify(x));
let n = 0;
const ok = (msg) => { n++; console.log('ok -', msg); };
const refuses = (m, re, opts) => assert.throws(() => validateOverlayManifest(m, opts), (e) => e instanceof OverlayError && re.test(e.message), `ожидался отказ ${re}`);

/* ---- выбор языка */
{
  const store = (v) => ({ getItem: (k) => { assert.equal(k, LANG_KEY); return v; } });
  assert.equal(LANG_KEY, 'korsary2.lang');
  const d = chooseLang({ search: '', storage: store(null) });
  assert.deepEqual([d.lang, d.source], ['ru', 'default'], 'по умолчанию русский');
  assert.deepEqual([chooseLang({ search: '?lang=en', storage: store(null) }).lang, chooseLang({ search: '?lang=en', storage: store(null) }).source], ['en', 'url']);
  assert.equal(chooseLang({ search: '', storage: store('en') }).lang, 'en');
  assert.equal(chooseLang({ search: '', storage: store('en') }).source, 'storage');
  assert.equal(chooseLang({ search: '?lang=ru', storage: store('en') }).lang, 'ru', 'адрес важнее запомненного');
  assert.equal(chooseLang({ search: '?lang=en', storage: store('ru') }).lang, 'en');
  assert.equal(chooseLang({ search: '?lang=EN', storage: store(null) }).lang, 'en', 'регистр значения не важен');
  for (const bad of ['?lang=fr', '?lang=', '?lang=english', '?lang=ru,en', '?x=1', '?lang=%00']) {
    const r = chooseLang({ search: bad, storage: store(null) });
    assert.equal(r.lang, 'ru', bad);
  }
  assert.equal(chooseLang({ search: '?lang=fr', storage: store(null) }).urlInvalid, true);
  assert.equal(chooseLang({ search: '?lang=fr', storage: store('en') }).lang, 'en', 'незнакомое значение в адресе не мешает запомненному');
  assert.equal(chooseLang({ search: '', storage: store('de') }).lang, 'ru', 'мусор в хранилище игнорируется');
  // хранилище недоступно: русский, ошибка отражена
  const boom = { getItem() { throw new Error('SecurityError'); } };
  const r = chooseLang({ search: '', storage: boom });
  assert.deepEqual([r.lang, r.source], ['ru', 'default']);
  assert.match(r.storageError, /SecurityError/);
  assert.equal(chooseLang({ search: '?lang=en', storage: boom }).lang, 'en', 'адрес работает и без хранилища');
  assert.equal(chooseLang({ search: '', storage: null }).lang, 'ru');
  assert.equal(chooseLang().lang, 'ru');
  assert.equal(chooseLang({ search: '?%', storage: store(null) }).lang, 'ru', 'нечитаемый адрес');
  // запись
  const saved = {};
  assert.equal(rememberLang({ setItem: (k, v) => { saved[k] = v; } }, 'en'), true);
  assert.deepEqual(saved, { 'korsary2.lang': 'en' });
  assert.equal(rememberLang({ setItem() { throw new Error('QuotaExceeded'); } }, 'en'), false, 'запись в try/catch');
  assert.equal(rememberLang({ setItem() { throw new Error('x'); } }, 'xx'), false);
  assert.equal(rememberLang(null, 'ru'), false);
  assert.equal(normalizeLang(' RU '), 'ru');
  assert.equal(overlayDirName('korsary2-game'), 'korsary2-game-en');
  assert.equal(overlayHostPath('korsary2-game'), '/opfs/korsary2-game-en');
  ok('выбор языка: адрес > localStorage > русский; сбои хранилища и мусор безопасны; хост-путь /opfs/korsary2-game-en');
}

/* ---- валидатор: настоящий манифест оверлея принимается */
{
  const v = validateOverlayManifest(clone(ovManifest), { baseManifest });
  assert.equal(v.version, ovManifest.version);
  assert.equal(v.files.length, ovManifest.files.length);
  assert.ok(v.overlay && v.overlay.format === 1);
  assert.ok(v.totalBytes > 0);
  // неизвестные ключи верхнего уровня игнорируются; тот же манифест без блока overlay тоже годится
  const m = clone(ovManifest); m.futureKey = { x: 1 };
  assert.equal(validateOverlayManifest(m, { baseManifest }).files.length, v.files.length);
  const noBlock = clone(ovManifest); delete noBlock.overlay;
  assert.equal(validateOverlayManifest(noBlock).overlay, null);
  ok('настоящий манифест game-en принимается; неизвестные ключи верхнего уровня игнорируются');
}

/* ---- валидатор: отказы (всё ДО записи — функция ничего не пишет) */
{
  const add = (e) => { const m = clone(ovManifest); m.files.push({ size: 1, sha256: '0'.repeat(64), ...e }); return m; };
  const sha = (path) => ovManifest.files.find((f) => f.path === path).sha256;
  for (const [path, re] of [
    ['SAVE/slot1', /сохранения игрока/], ['save/slot1', /сохранения игрока/], ['SAVE_META/x', /записи времени/], ['SAVE_TX/x', /журнал/],
    ['options', /настройки игрока/], ['engine.ini', /настройки движка/], ['ENGINE.exe', /исполняемый/], ['MODULES/m.dll', /модули/],
    ['README', /вне PROGRAM/], ['Other/x', /вне PROGRAM/], ['program/x.c', /регистр/], ['PROGRAM', /внутри/],
    ['RESOURCE/../x', /\.\./], ['RESOURCE/./x', /«\.»/], ['/RESOURCE/x', /абсолютный/], ['RESOURCE\\x', /обратная/], ['RESOURCE/a:b', /двоеточие|спецсимвол/],
    ['RESOURCE/.hidden', /скрытое/], ['RESOURCE/.git/config', /скрытое/], ['RESOURCE/CON', /зарезервированное/], ['RESOURCE/nul.txt', /зарезервированное/],
    ['RESOURCE/LPT1', /зарезервированное/], ['RESOURCE/Thumbs.db', /служебное/], ['RESOURCE/x.', /точкой/], ['RESOURCE/x ', /точкой или пробелом/],
    ['RESOURCE//x', /пустой/], ['RESOURCE/x\u0000', /управляющий/], ['RESOURCE/' + 'd/'.repeat(25) + 'x', /глубокий/], ['RESOURCE/' + 'n'.repeat(250), /длиннее/],
  ]) refuses(add({ path }), re, {});
  ok('запрещённые пути (SAVE*, options, engine.ini, .., абсолютные, ".", скрытые, зарезервированные, не-PROGRAM/RESOURCE) отвергаются понятным текстом');

  const noSha = clone(ovManifest); delete noSha.files[0].sha256;
  refuses(noSha, /нет SHA-256/);
  const badSha = clone(ovManifest); badSha.files[0].sha256 = 'g'.repeat(64);
  refuses(badSha, /нет SHA-256/);
  const noSize = clone(ovManifest); noSize.files[0].size = -1;
  refuses(noSize, /размер/);
  const frac = clone(ovManifest); frac.files[0].size = 1.5;
  refuses(frac, /размер/);
  const dup = clone(ovManifest); dup.files.push({ ...dup.files[0] });
  refuses(dup, /повторяется/);
  const caseDup = clone(ovManifest); caseDup.files.push({ ...caseDup.files.find((f) => f.path === 'RESOURCE/INI/fonts.ini'), path: 'RESOURCE/ini/FONTS.INI' });
  refuses(caseDup, /только регистром/);
  const clash = clone(ovManifest); clash.files.push({ path: 'RESOURCE/INI', size: 1, sha256: '1'.repeat(64) });
  refuses(clash, /одновременно файл и каталог/);
  refuses({ version: 'x', files: [] }, /нет файлов/);
  refuses({ files: ovManifest.files }, /нет версии/);
  refuses(clone(ovManifest.files), /не объект/);                         // старый формат манифеста-массива
  refuses(null, /не объект/);
  refuses({ ...clone(ovManifest), files: 'x' }, /нет файлов/);
  refuses(clone({ ...ovManifest, files: [null] }), /не объект/);
  const badEnc = clone(ovManifest); badEnc.files.find((f) => f.enc).enc = 'zstd';
  assert.throws(() => validateOverlayManifest(badEnc), /неподдерживаемое кодирование/);
  const packless = clone(ovManifest); delete packless.packs;
  assert.throws(() => validateOverlayManifest(packless), /пакет/i);
  const f2 = clone(ovManifest); f2.overlay.format = 2;
  refuses(f2, /не поддерживается/);
  const baseArr = clone(ovManifest); baseArr.overlay.base = [];
  refuses(baseArr, /base не объект/);
  const baseForeign = clone(ovManifest); baseForeign.overlay.base['RESOURCE/not/there.x'] = '1'.repeat(64);
  refuses(baseForeign, /не файл оверлея/);
  const baseBadPath = clone(ovManifest); baseBadPath.overlay.base['SAVE/x'] = '1'.repeat(64);
  refuses(baseBadPath, /недопустимый путь/);
  const baseBadSha = clone(ovManifest); baseBadSha.overlay.base['RESOURCE/INI/fonts.ini'] = 'nothex';
  refuses(baseBadSha, /не SHA-256/);
  ok('отказы: нет/неверный SHA-256 и размер, дубли и регистровые дубли, файл=каталог, старый формат, неизвестное кодирование, пакеты, блок overlay');

  // обязательные файлы слоя
  for (const r of OVERLAY_REQUIRED) {
    const m = clone(ovManifest); m.files = m.files.filter((f) => f.path !== r); delete m.overlay.base[r];
    refuses(m, /нет обязательного файла/, {});
  }
  const minimal = clone(ovManifest); minimal.files = minimal.files.filter((f) => f.path !== OVERLAY_REQUIRED[1]); delete minimal.overlay.base[OVERLAY_REQUIRED[1]];
  assert.equal(validateOverlayManifest(minimal, { required: [OVERLAY_REQUIRED[0]] }).files.length, minimal.files.length, 'список обязательных настраивается');
  ok('обязательные файлы слоя (6 по контракту E2): отсутствие любого — отказ');

  // E5: список живёт в одном файле (overlay-required.json): страница импортирует именно его
  const listFile = JSON.parse(readFileSync(join(here, '../web/overlay-required.json'), 'utf8'));
  assert.deepEqual([...OVERLAY_REQUIRED], listFile.required);
  assert.deepEqual([...OVERLAY_RECOMMENDED], listFile.recommended);
  assert.deepEqual([...OVERLAY_BASE_RECOMMENDED], listFile.base_recommended);
  assert.ok(Object.isFrozen(OVERLAY_REQUIRED) && OVERLAY_REQUIRED.length === 6);
  const overlaySource = readFileSync(join(here, '../web/overlay.mjs'), 'utf8');
  assert.match(overlaySource, /from '\.\/overlay-required\.json' with \{ type: 'json' \}/);
  assert.ok(!overlaySource.includes('ItemsDescribe'), 'пути обязательных файлов в overlay.mjs не повторяются');
  ok('список обязательных файлов: один файл overlay-required.json (страница, упаковщик и verify_dist читают его же)');

  // собран на другой русской раздаче: overlay.base против манифеста базы
  const otherBase = clone(baseManifest);
  const victim = Object.keys(ovManifest.overlay.base)[0];
  otherBase.files.find((f) => f.path === victim).sha256 = '3'.repeat(64);
  refuses(clone(ovManifest), /другой версии русской раздачи/, { baseManifest: otherBase });
  const missingBase = clone(baseManifest); missingBase.files = missingBase.files.filter((f) => f.path !== victim);
  refuses(clone(ovManifest), /другой версии русской раздачи/, { baseManifest: missingBase });
  assert.ok(validateOverlayManifest(clone(ovManifest), { baseManifest: null }), 'без манифеста базы (установка из папки) сверка пропускается');
  ok('overlay.base сверяется с манифестом базы: оверлей на другой русской раздаче отвергается');
}

/* ---- согласованность правил путей с упаковщиком и verify_dist (один список путей, три реализации) */
{
  const samples = ['PROGRAM/a.c', 'RESOURCE/x/y.z', 'program/a.c', 'SAVE/x', 'options', 'engine.ini', 'RESOURCE/../x', 'RESOURCE/./x', '/RESOURCE/x', 'RESOURCE\\x',
    'RESOURCE/a:b', 'RESOURCE/.h', 'RESOURCE/CON', 'RESOURCE/con.txt', 'RESOURCE/Lpt1.x', 'RESOURCE/a ', 'RESOURCE/a.', 'PROGRAM', 'MODULES/x.dll', 'RESOURCE//x',
    'RESOURCE/Thumbs.db', 'RESOURCE/ёж.txt', 'RESOURCE/x\u0001', 'RESOURCE/' + 'a/'.repeat(30) + 'b', 'RESOURCE/COM1', 'RESOURCE/com10', 'RESOURCE/PRN.x.y', 'RESOURCE/ok name.txt',
    'RESOURCE/' + 'z'.repeat(240), 'RESOURCE/' + 'ё'.repeat(120), 'RESOURCE/a*b', 'RESOURCE/a?b', 'RESOURCE/a"b', 'RESOURCE/a|b', 'RESOURCE/a<b', 'RESOURCE/a>b', 'RESOURCE/\u007f'];
  const got = samples.map(s => [!!builderPathProblem(s), !!verifierPathProblem(s)]);
  samples.forEach((s, i) => {
    const js = !!overlayPathProblem(s);
    assert.equal(got[i][0], js, `упаковщик и страница расходятся для ${JSON.stringify(s)}`);
    assert.equal(got[i][1], js, `verify_dist и страница расходятся для ${JSON.stringify(s)}`);
  });
  ok(`правила путей оверлея: страница, упаковщик и verify_dist согласны на ${samples.length} путях`);
}

/* ---- установка под страничным SAVE-замком */
{
  class Locks {
    held = new Set(); log = [];
    async request(name, options, fn) {
      assert.deepEqual(options, { mode: 'exclusive', ifAvailable: true });
      this.log.push(name);
      if (this.held.has(name)) return fn(null);
      this.held.add(name);
      try { return await fn({ name }); } finally { this.held.delete(name); }
    }
  }
  const rootName = 'korsary2-game';
  // 1. текущая метка: замок НЕ берётся, sync не вызывается (работающая игра в другой вкладке не мешает)
  {
    const locks = new Locks(); locks.held.add(saveLockName(rootName));   // игра держит замок
    let syncs = 0;
    const r = await installOverlayUnderSaveLock({ locks, rootName, version: 'v1', readMarker: async () => ({ version: 'v1' }), sync: async () => { syncs++; } });
    assert.deepEqual(r, { skipped: 'current' });
    assert.equal(syncs, 0);
    assert.deepEqual(locks.log, [], 'замок не запрашивался');
  }
  // 2. устарело + замок занят: отказ, sync не вызван, ничего не записано
  {
    const locks = new Locks(); locks.held.add(saveLockName(rootName));
    let syncs = 0;
    await assert.rejects(installOverlayUnderSaveLock({ locks, rootName, version: 'v2', readMarker: async () => ({ version: 'v1' }), sync: async () => { syncs++; } }), /заняты/);
    assert.equal(syncs, 0);
    assert.deepEqual(locks.log, [saveLockName(rootName)], 'тот же замок, что у базовой установки и игры (`<корень базы>:save-backup`)');
  }
  // 3. установка: sync один раз, под замком; метка читается снова под замком; замок отпущен после
  {
    const locks = new Locks();
    let marker = null, syncs = 0, heldDuring = null;
    const r = await installOverlayUnderSaveLock({ locks, rootName, version: 'v3', readMarker: async () => marker,
      sync: async () => { syncs++; heldDuring = locks.held.has(saveLockName(rootName)); marker = { version: 'v3' }; } });
    assert.deepEqual(r, { installed: true });
    assert.equal(syncs, 1);
    assert.equal(heldDuring, true);
    assert.equal(locks.held.size, 0);
    // повторный вызов: метка текущая, замок не нужен
    assert.deepEqual(await installOverlayUnderSaveLock({ locks, rootName, version: 'v3', readMarker: async () => marker, sync: async () => { throw new Error('не должен вызываться'); } }), { skipped: 'current' });
  }
  // 4. гонка двух вкладок: пока одна ставит, вторая получает отказ «занято», а не вторую запись
  {
    const locks = new Locks();
    let release, started;
    const gate = new Promise((r) => { release = r; }), go = new Promise((r) => { started = r; });
    let marker = null, syncs = 0;
    const first = installOverlayUnderSaveLock({ locks, rootName, version: 'v4', readMarker: async () => marker,
      sync: async () => { syncs++; started(); await gate; marker = { version: 'v4' }; } });
    await go;
    await assert.rejects(installOverlayUnderSaveLock({ locks, rootName, version: 'v4', readMarker: async () => marker, sync: async () => { syncs++; } }), /заняты/);
    release();
    assert.deepEqual(await first, { installed: true });
    assert.equal(syncs, 1);
  }
  // 5. ошибка sync: метка не пишется (её пишет syncManifestFiles после успеха), замок отпущен, ошибка наружу
  {
    const locks = new Locks();
    await assert.rejects(installOverlayUnderSaveLock({ locks, rootName, version: 'v5', readMarker: async () => null, sync: async () => { throw new Error('HTTP 500'); } }), /HTTP 500/);
    assert.equal(locks.held.size, 0);
  }
  await assert.rejects(installOverlayUnderSaveLock({ locks: new Locks(), rootName: '', version: 'v', readMarker: async () => null, sync: async () => {} }), /параметры/);
  await assert.rejects(installOverlayUnderSaveLock({ locks: new Locks(), rootName, version: 'v', readMarker: null, sync: async () => {} }), /параметры/);
  ok('установка под SAVE-замком: текущая метка без замка; занято = отказ без записи; один sync; гонка вкладок; ошибка отпускает замок');
}

/* ---- проверка полноты, сообщение отказа */
{
  const sizes = new Map(ovManifest.files.map((f) => [f.path, f.size]));
  const existingSize = async (_dir, path) => (sizes.has(path) ? sizes.get(path) : -1);
  const files = ovManifest.files;
  assert.deepEqual(await verifyOverlayFiles({ dir: {}, files, existingSize }), { ok: true, missing: [], wrongSize: [], checked: files.length });
  sizes.delete(files[3].path); sizes.set(files[5].path, files[5].size + 1);
  const bad = await verifyOverlayFiles({ dir: {}, files, existingSize });
  assert.equal(bad.ok, false);
  assert.deepEqual(bad.missing, [files[3].path]);
  assert.deepEqual(bad.wrongSize, [files[5].path]);
  assert.match(incompleteOverlayMessage(bad), /неполон или повреждён.*Английский режим не запущен.*русская установка не затронута.*Вернитесь к русскому/s);
  assert.equal((await verifyOverlayFiles({ dir: {}, files: [], existingSize })).ok, true);
  ok('быстрая проверка полноты: отсутствующие и файлы другого размера найдены, сообщение предлагает русский');
}

/* ---- квота оверлея считается отдельно от базовой */
{
  const files = ovManifest.files.map((f) => ({ path: f.path, size: f.size, ...(f.enc ? { enc: f.enc, csize: f.csize } : {}), ...(f.pack !== undefined ? { pack: f.pack, offset: f.offset, csize: f.csize } : {}), sha256: f.sha256 }));
  const total = files.reduce((s, f) => s + f.size, 0);
  const plan = planStorageNeed({ files, haveSizes: new Map(), hadMarker: false, saveBytes: 0 });
  assert.equal(plan.writeBytes, total, 'пишется весь оверлей и ТОЛЬКО он');
  assert.equal(plan.fresh, true);
  const gamePlan = planStorageNeed({ files: baseManifest.files, haveSizes: new Map(), hadMarker: false, saveBytes: 0 });
  assert.notEqual(plan.writeBytes, gamePlan.writeBytes);
  const missing = () => Object.assign(new Error('x'), { name: 'NotFoundError' });
  const noDir = { dir: null, files, hadMarker: false, existingSize: async () => -1, concurrency: 1 };
  const tiny = await checkStorageForSync({ ...noDir, estimate: async () => ({ quota: 1000, usage: 0 }) });
  assert.equal(tiny.status, 'insufficient', 'квота 1 КБ: оверлей не поместится — отказ до записи');
  assert.match(tiny.message, /Недостаточно места/);
  const roomy = await checkStorageForSync({ ...noDir, estimate: async () => ({ quota: 5e9, usage: 1e9 }) });
  assert.equal(roomy.status, 'ok');
  const unknown = await checkStorageForSync({ ...noDir, estimate: async () => undefined });
  assert.equal(unknown.status, 'unknown');
  // уже установлен: ничего писать не нужно
  const sizes = new Map(files.map((f) => [f.path, f.size]));
  const done = await checkStorageForSync({ dir: {}, files, hadMarker: true, existingSize: async (_d, p) => sizes.get(p) ?? -1, concurrency: 1,
    estimate: async () => ({ quota: 1000, usage: 999 }) });
  assert.equal(done.plan.writeBytes, 0);
  assert.equal(done.status, 'ok');
  void missing; void assessStorage;
  ok('квота: план оверлея (writeBytes = размер слоя), отказ до записи при нехватке, уже установленный слой места не просит');
}

/* ---- E5: язык слотов сохранений (readSlotLanguages / summarizeSlotLanguages): только текст, ничего не блокирует и не пишет */
{
  const { readSlotLanguages, summarizeSlotLanguages } = await import('../web/overlay.mjs');
  const te = new TextEncoder();
  const file = (b) => ({ kind: 'file', async getFile() { return { size: b.length, async arrayBuffer() { return b.slice().buffer; } }; } });
  const dirOf = (entries) => ({ kind: 'directory', async *entries() { yield* entries; } });
  const root = (save, meta, log = []) => ({ async getDirectoryHandle(name, o) {
    log.push([name, o?.create]);
    if (name === 'SAVE' && save) return dirOf(save);
    if (name === 'SAVE_META' && meta) return dirOf(meta);
    const e = new Error('nf'); e.name = 'NotFoundError'; throw e; } });
  const L = (s) => file(te.encode(s));
  const save = [['Oxbay', L('x')], ['Тест.sav', L('y')], ['old1', L('z')], ['old2', L('z')], ['sub', { kind: 'directory' }]];
  const meta = [['Oxbay.lang', L('en')], ['тест.sav.lang', L('en')], ['old1.time', L('12345678')], ['ghost.lang', L('en')], ['bad.lang', L('xx')], ['.lang', L('en')], ['old2.lang', L('eng')]];
  const log = [];
  const info = await readSlotLanguages(root(save, meta, log));
  assert.deepEqual(info.slots.sort(), ['Oxbay', 'old1', 'old2', 'Тест.sav'].sort());
  assert.deepEqual([...info.labels.entries()].sort(), [['ghost', 'en'], ['oxbay', 'en'], ['тест.sav', 'en']].sort());   // ключ — имя без учёта регистра; недопустимые метки не берутся
  assert.ok(log.every(([, create]) => create === false), 'только чтение: ни одного create');
  // русский: слоты, помеченные «en», — другой язык; непомеченные про русский режим молчат
  let s = summarizeSlotLanguages(info, 'ru');
  assert.deepEqual([s.total, s.same, s.other, s.unmarked], [4, 0, 2, 2]);
  assert.match(s.message, /Часть сохранений \(2 из 4\) создана в другом языке; имена персонажей в них могут отображаться на другом языке/);
  assert.ok(!/не помечены/.test(s.message));
  // английский: метки «en» — свои; непомеченные названы «не помеченными», а не «русскими»
  s = summarizeSlotLanguages(info, 'en');
  assert.deepEqual([s.total, s.same, s.other, s.unmarked], [4, 2, 0, 2]);
  assert.match(s.message, /2 of 4 saves have no language label/); assert.ok(!/создана в другом языке/.test(s.message)); assert.ok(!/русск[а-я]+ слот/i.test(s.message));
  assert.doesNotMatch(s.message, /predate this feature/, 'unmarked Russian saves may be newly created');
  // метка «ru» (если появится) в английском режиме — другой язык
  s = summarizeSlotLanguages({ slots: ['a', 'b'], labels: new Map([['a', 'ru'], ['b', 'en']]) }, 'en');
  assert.deepEqual([s.same, s.other, s.unmarked], [1, 1, 0]); assert.match(s.message, /1 of 2 saves were created in another language/);
  // нет слотов, нет каталога, нет меток: сообщения нет и ничего не падает
  assert.equal(summarizeSlotLanguages({ slots: [], labels: new Map() }, 'en').message, null);
  assert.equal(summarizeSlotLanguages(await readSlotLanguages(root(null, null)), 'en').message, null);
  assert.equal(summarizeSlotLanguages(await readSlotLanguages(root(save, null)), 'ru').message, null, 'без SAVE_META русский режим молчит');
  assert.deepEqual(summarizeSlotLanguages(), { lang: 'ru', total: 0, same: 0, other: 0, unmarked: 0, message: null }, 'без аргументов');
  assert.deepEqual((await readSlotLanguages(null)).slots, []);
  const broken = { async getDirectoryHandle(name) { if (name === 'SAVE') return { async *entries() { throw new Error('io'); } }; throw new Error('io'); } };
  assert.deepEqual((await readSlotLanguages(broken)).labels.size, 0);
  assert.equal(summarizeSlotLanguages(info, 'xx').lang, 'ru', 'незнакомый язык — русский');
  ok('язык слотов: метки читаются только на чтение, «другой язык» и «не помечены» говорятся осторожно, нет слотов/каталога/меток — тишина');
}

console.log(`overlay page logic: PASS (${n} groups)`);
