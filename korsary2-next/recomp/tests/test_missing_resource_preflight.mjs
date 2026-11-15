// Тесты web/missing-resource-preflight.mjs (Ф3.1). Только Node, fixtures во временных
// каталогах; игровые данные не изменяются (опциональный блок читает сборку и копирует
// небольшой поднабор файлов во временный каталог).
//   node korsary2-next/recomp/tests/test_missing_resource_preflight.mjs
import assert from 'node:assert/strict';
import { createHash, webcrypto } from 'node:crypto';
import { execFileSync } from 'node:child_process';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { gunzipSync, brotliDecompressSync } from 'node:zlib';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { gameFiles, manifestFor } from '../web/gamefiles.mjs';
// PREFLIGHT_MODULE: путь к мутированной копии модуля (mutate_missing_resource_preflight.mjs); по умолчанию — боевой модуль
const modUrl = process.env.PREFLIGHT_MODULE ? pathToFileURL(path.resolve(process.env.PREFLIGHT_MODULE)).href : new URL('../web/missing-resource-preflight.mjs', import.meta.url).href;
const {
  preflightOverlay, checkOverlayBeforeRun, describeOverlayReport, languageIniProblem, LANGUAGE_INI_PATH, OVERLAY_BLOCKING,
  preflightResources, checkResourcesBeforeRun, describeReport, manifestVersionDigest,
  KNOWN_CRASH_PATHS, KNOWN_MUSIC_PATHS, KNOWN_ITEM_MODELS, KNOWN_AMMO_MODELS, KNOWN_STARTUP_MODELS, KNOWN_GM_PATHS, GM_MAGIC, GM_HEADER_BYTES,
  CHECK_RULES, LIMITS, CODES,
} = await import(modUrl);

if (!globalThis.crypto) globalThis.crypto = webcrypto;
const here = path.dirname(fileURLToPath(import.meta.url));
const webDir = path.resolve(here, '../web');
const sha = (b) => createHash('sha256').update(b).digest('hex');
const BLADE1 = KNOWN_CRASH_PATHS[0], BLADE6 = KNOWN_CRASH_PATHS[1];
const CORIDOR = 'RESOURCE/Sounds/MUSIC/Coridor.ogg';
// музыка, на которую скрипты не ссылаются: только предупреждение (Abordage — алиас music_abordage без вызова, Rolik — без ссылок)
const MUSIC_WARN = ['RESOURCE/Sounds/MUSIC/Abordage.ogg', 'RESOURCE/Sounds/MUSIC/Rolik.ogg'];
// модели каталога Items, на которые таблица предметов не ссылается (только предупреждение) и прочие модели (только наличие по списку каталога)
const GM_WARN = ['RESOURCE/MODELS/Items/elixir.gm', 'RESOURCE/MODELS/Items/adrenaline.gm'];
const MODEL_ANY = ['RESOURCE/MODELS/Characters/extra1.gm', 'RESOURCE/MODELS/Locations/Town/town1.gm'];
const ITEM_OTHER = KNOWN_ITEM_MODELS.find((p) => !KNOWN_CRASH_PATHS.includes(p)), AMMO_ONE = KNOWN_AMMO_MODELS[0], STARTUP_ONE = KNOWN_STARTUP_MODELS[0];
const scratchBase = process.env.PREFLIGHT_TEST_TMP || os.tmpdir();
const created = [];
const mkTmp = (label) => { const d = fs.mkdtempSync(path.join(scratchBase, `preflight-${label}-`)); created.push(d); return d; };

// ---- File System Access API поверх реального каталога. Любая попытка записи -> провал теста.
const writeLog = [];
const readLog = { files: new Set(), lists: 0, sliceBytes: 0 };
const nfe = (m) => Object.assign(new Error(m), { name: 'NotFoundError' });
function mapErr(e) {
  if (e?.name && e.name.endsWith('Error') && !e.code) return e;
  const name = e.code === 'ENOENT' || e.code === 'ENOTDIR' ? 'NotFoundError' : e.code === 'EACCES' || e.code === 'EPERM' ? 'NotAllowedError'
    : e.code === 'EISDIR' ? 'TypeMismatchError' : 'NotReadableError';
  return Object.assign(new Error(e.message), { name });
}
class FsFile {
  constructor(p) { this.p = p; this.kind = 'file'; this.name = path.basename(p); }
  async getFile() {
    let st; try { st = fs.statSync(this.p); } catch (e) { throw mapErr(e); }
    if (st.isDirectory()) throw Object.assign(new Error('dir'), { name: 'TypeMismatchError' });
    readLog.files.add(this.p);
    const p = this.p;
    return { size: st.size,
      slice(a, b) { return { async arrayBuffer() {   // только чтение диапазона; число прочитанных байт учитывается
        try { const fd = fs.openSync(p, 'r'); const buf = Buffer.alloc(Math.max(0, Math.min(b, st.size) - a)); fs.readSync(fd, buf, 0, buf.length, a); fs.closeSync(fd);
          readLog.sliceBytes += buf.length; return buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.length); } catch (e) { throw mapErr(e); } } }; },
      async arrayBuffer() {
        try { const b = fs.readFileSync(p); return b.buffer.slice(b.byteOffset, b.byteOffset + b.length); } catch (e) { throw mapErr(e); }
      } };
  }
  async createWritable() { writeLog.push(['createWritable', this.p]); throw new Error('WRITE'); }
}
class FsDir {
  constructor(p) { this.p = p; this.kind = 'directory'; this.name = path.basename(p); }
  async *entries() {
    readLog.lists++;
    let names; try { names = fs.readdirSync(this.p); } catch (e) { throw mapErr(e); }
    for (const n of names) {
      const full = path.join(this.p, n);
      let isDir = false; try { isDir = fs.statSync(full).isDirectory(); } catch { /* dangling symlink: a file that cannot be opened */ }
      yield [n, isDir ? new FsDir(full) : new FsFile(full)];
    }
  }
  async getDirectoryHandle(n, o) {
    if (o?.create) { writeLog.push(['getDirectoryHandle', n, o]); throw new Error('WRITE'); }
    const full = path.join(this.p, n);
    try { if (!fs.statSync(full).isDirectory()) throw Object.assign(new Error('x'), { name: 'TypeMismatchError' }); } catch (e) { throw mapErr(e); }
    return new FsDir(full);
  }
  async getFileHandle(n, o) {
    if (o?.create) { writeLog.push(['getFileHandle', n, o]); throw new Error('WRITE'); }
    const full = path.join(this.p, n);
    try { if (fs.statSync(full).isDirectory()) throw Object.assign(new Error('x'), { name: 'TypeMismatchError' }); } catch (e) { throw mapErr(e); }
    return new FsFile(full);
  }
  async removeEntry(...a) { writeLog.push(['removeEntry', ...a]); throw new Error('WRITE'); }
}
const open = (root) => () => Promise.resolve(new FsDir(root));

// ---- синтетическая установка
const REQUIRED = ['engine.ini', 'options', 'PROGRAM/seadogs.c', 'MODULES/GEOMETRY.dll'];
// .gm: заголовок GEOMETRY.dll (первые 4 байта "50.1", файл не короче 72 байт); прочие файлы: произвольное содержимое
const withHeader = (rel, tail = '') => Buffer.from(GM_MAGIC + `:synthetic:${rel}:` + 'x'.repeat(GM_HEADER_BYTES + rel.length) + tail);
function content(rel) { return rel.toLowerCase().endsWith('.gm') ? withHeader(rel) : Buffer.from(`synthetic:${rel}:` + 'x'.repeat(40 + rel.length)); }
function fixtureFiles() {
  const list = ['ENGINE.exe', ...REQUIRED, BLADE1, BLADE6, ...KNOWN_GM_PATHS, ...GM_WARN, ...MODEL_ANY,
    'RESOURCE/Textures/Items/Blade6.tga.tx', 'RESOURCE/Textures/Items/blade2.tga.tx', 'RESOURCE/Sounds/x.wav',
    ...KNOWN_MUSIC_PATHS, ...MUSIC_WARN];
  return [...new Set(list)];
}
function buildInstall(root, files = fixtureFiles()) {
  for (const rel of files) {
    const full = path.join(root, ...rel.split('/'));
    fs.mkdirSync(path.dirname(full), { recursive: true });
    fs.writeFileSync(full, content(rel));
  }
  return files;
}
async function manifestOf(files, mutate) {
  const entries = files.map((p) => ({ path: p, size: content(p).length, sha256: sha(content(p)) }))
    .sort((a, b) => (a.path < b.path ? -1 : a.path > b.path ? 1 : 0));
  const m = { version: await manifestVersionDigest(entries), files: entries };
  return mutate ? mutate(m) : m;
}
async function fresh(label) {
  const root = mkTmp(label);
  const files = buildInstall(root);
  const manifest = await manifestOf(files);
  const run = (extra = {}) => preflightResources({ openGameDir: open(root), manifest, installedVersion: manifest.version,
    exe: 'ENGINE.exe', required: REQUIRED, ...extra });
  return { root, files, manifest, run, file: (rel) => path.join(root, ...rel.split('/')) };
}
const findingFor = (r, rel) => r.findings.find((f) => f.path === rel);
const codes = (r) => r.findings.map((f) => f.code);
function snapshotTree(root) {
  const out = [];
  const walk = (d) => { for (const n of fs.readdirSync(d).sort()) {
    const full = path.join(d, n); const st = fs.lstatSync(full);
    if (st.isDirectory()) { out.push(['d', path.relative(root, full), st.mode, st.mtimeMs]); walk(full); }
    else out.push(['f', path.relative(root, full), st.size, st.mtimeMs, st.mode, st.isSymbolicLink() ? fs.readlinkSync(full) : sha(fs.readFileSync(full))]);
  } };
  walk(root); return JSON.stringify(out);
}

let passed = 0;
const test = async (name, fn) => {
  const before = writeLog.length;
  try { await fn(); } catch (e) { console.error(`FAIL: ${name}`); throw e; }
  assert.equal(writeLog.length, before, `${name}: preflight tried to write: ${JSON.stringify(writeLog.slice(before))}`);
  passed++; console.log(`ok - ${name}`);
};

try {
  await test('ресурсы на месте и совпадают с манифестом', async () => {
    const t = await fresh('ok');
    const r = await t.run();
    assert.equal(r.status, 'ok'); assert.equal(r.mode, 'verified'); assert.equal(r.trust.level, 'verified');
    assert.equal(r.counts.fatal, 0); assert.equal(r.counts.warn, 0);
    // fatal: ENGINE.exe, 4 required (options -> check class), все .gm из KNOWN_GM_PATHS (в т.ч. blade1/blade6) + 24 музыкальных;
    // check: Items без ссылок из таблицы предметов, текстуры Items, прочая музыка; model: остальные модели (только наличие)
    assert.deepEqual(r.items.filter((i) => i.cls === 'fatal').map((i) => i.path).sort(),
      ['ENGINE.exe', 'MODULES/GEOMETRY.dll', 'PROGRAM/seadogs.c', 'engine.ini', ...KNOWN_GM_PATHS, ...KNOWN_MUSIC_PATHS].sort());
    assert.deepEqual(r.items.filter((i) => i.why === 'music').map((i) => i.path).sort(), [...MUSIC_WARN].sort());
    assert.deepEqual(r.items.filter((i) => i.why === 'item-model').map((i) => i.path).sort(), [...GM_WARN].sort());
    assert.deepEqual(r.items.filter((i) => i.why === 'model').map((i) => i.path).sort(), [...MODEL_ANY].sort());
    assert.ok(r.items.filter((i) => i.why === 'model').every((i) => i.verified === 'presence'), 'прочие модели: только наличие');
    assert.ok(r.items.filter((i) => i.cls === 'fatal' && /\.gm$/.test(i.path)).every((i) => i.verified === 'hash'), 'fatal .gm: заголовок и хеш сверены');
    assert.ok(r.items.some((i) => i.path === 'RESOURCE/Textures/Items/Blade6.tga.tx' && i.verified === 'hash'));
    assert.ok(!r.items.some((i) => /Sounds\/x\.wav/.test(i.path)), 'прочие ресурсы не читаются');
    const d = describeReport(r); assert.equal(d.block, false); assert.equal(d.level, 'ok'); assert.equal(d.message, '');
  });

  await test('отсутствует blade1 / blade6 / ENGINE.exe: отказ с кодом и русским текстом', async () => {
    for (const rel of [BLADE1, BLADE6, 'ENGINE.exe', 'MODULES/GEOMETRY.dll']) {
      const t = await fresh('missing');
      fs.rmSync(t.file(rel));
      const r = await t.run();
      assert.equal(r.status, 'blocked', rel);
      assert.equal(findingFor(r, rel).code, CODES.RES_MISSING);
      assert.equal(findingFor(r, rel).severity, 'fatal');
      const d = describeReport(r);
      assert.equal(d.block, true); assert.equal(d.code, 'RES_MISSING');
      assert.match(d.message, /Игра не запущена/); assert.match(d.message, new RegExp(rel.replace(/[.\\]/g, '\\$&')));
      assert.match(d.message, /RES_MISSING/); assert.match(d.message, /Сохранения и настройки не затронуты/);
      if (rel === BLADE1) assert.match(d.message, /аварийно завершается/);
    }
  });

  await test('каталог Items целиком или каталог игры отсутствует', async () => {
    const t = await fresh('nodir');
    fs.rmSync(t.file('RESOURCE/MODELS/Items'), { recursive: true });
    const r = await t.run();
    assert.equal(r.status, 'blocked'); assert.equal(r.counts.fatal, KNOWN_ITEM_MODELS.length);   // все модели предметов из таблицы
    assert.ok(r.findings.filter((f) => f.severity === 'fatal').every((f) => f.code === 'RES_MISSING' && /\/Items\//.test(f.path)));
    const t2 = await fresh('nogame');
    const r2 = await t2.run({ openGameDir: async () => { throw nfe('no game dir'); } });
    assert.equal(r2.status, 'blocked'); assert.ok(r2.findings.filter((f) => f.severity === 'fatal').every((f) => f.code === 'RES_MISSING'));
  });

  await test('музыка: отсутствие любого запрашиваемого .ogg — отказ RES_MISSING (как blade1/blade6)', async () => {
    assert.equal(KNOWN_MUSIC_PATHS.length, 24);
    assert.ok(KNOWN_MUSIC_PATHS.includes(CORIDOR));
    assert.equal(new Set(KNOWN_MUSIC_PATHS.map((p) => p.toLowerCase())).size, KNOWN_MUSIC_PATHS.length, 'без дубликатов');
    for (const rel of KNOWN_MUSIC_PATHS) {
      const t = await fresh('music-missing');
      fs.rmSync(t.file(rel));
      const r = await t.run();
      assert.equal(r.status, 'blocked', rel);
      assert.equal(findingFor(r, rel).code, CODES.RES_MISSING, rel);
      assert.equal(findingFor(r, rel).severity, 'fatal', rel);
      assert.equal(findingFor(r, rel).why, 'crash-music', rel);
      const d = describeReport(r);
      assert.equal(d.block, true); assert.equal(d.code, 'RES_MISSING');
      assert.match(d.message, /Игра не запущена/); assert.match(d.message, /RES_MISSING/); assert.match(d.message, /музыкального файла/);
      assert.match(d.message, /Сохранения и настройки не затронуты/);
    }
    // весь каталог MUSIC отсутствует (чистая раздача репака: музыка лежит только в setup-1.bin): один отказ, 24 файла в деталях
    const t = await fresh('music-nodir');
    fs.rmSync(t.file('RESOURCE/Sounds/MUSIC'), { recursive: true });
    const r = await t.run();
    assert.equal(r.status, 'blocked'); assert.equal(r.counts.fatal, KNOWN_MUSIC_PATHS.length);
    assert.equal(describeReport(r).details.length, KNOWN_MUSIC_PATHS.length);
    // без манифеста (presence-only, установка из папки): наличие всё равно проверяется
    const t2 = await fresh('music-presence');
    fs.rmSync(t2.file(CORIDOR));
    const rp = await t2.run({ manifest: null, installedVersion: 'local' });
    assert.equal(rp.mode, 'presence-only'); assert.equal(rp.status, 'blocked');
    assert.equal(findingFor(rp, CORIDOR).code, 'RES_MISSING');
    fs.writeFileSync(t2.file(CORIDOR), content(CORIDOR));
    assert.equal((await t2.run({ manifest: null, installedVersion: 'local' })).status, 'ok');
    // манифест не знает файла и на диске его нет: отказ, inManifest=false; манифест без музыки, а на диске есть — ok
    const t3 = await fresh('music-nomanifest-entry');
    const m = await manifestOf(t3.files.filter((p) => p !== CORIDOR));
    fs.rmSync(t3.file(CORIDOR));
    let rr = await t3.run({ manifest: m, installedVersion: m.version });
    assert.equal(rr.status, 'blocked'); assert.equal(findingFor(rr, CORIDOR).inManifest, false);
    fs.writeFileSync(t3.file(CORIDOR), content(CORIDOR));
    rr = await t3.run({ manifest: m, installedVersion: m.version });
    assert.equal(rr.status, 'ok'); assert.equal(rr.items.find((i) => i.path === CORIDOR).verified, 'presence');
  });

  await test('музыка: обрезка/пустой файл — предупреждение RES_SIZE_MISMATCH по размеру манифеста; содержимое не читается', async () => {
    for (const rel of [CORIDOR, 'RESOURCE/Sounds/MUSIC/Storm.ogg', MUSIC_WARN[0]]) {
      for (const size of [10, 0]) {
        const t = await fresh('music-trunc');
        fs.truncateSync(t.file(rel), size);
        const r = await t.run();
        assert.equal(r.status, 'warn', `${rel} -> ${size}`);
        const f = findingFor(r, rel);
        assert.equal(f.code, 'RES_SIZE_MISMATCH'); assert.equal(f.severity, 'warn');
        assert.equal(f.actualSize, size); assert.equal(f.expectedSize, content(rel).length);
        assert.equal(r.counts.fatal, 0);
        assert.equal(describeReport(r).block, false);
      }
    }
    // отсутствие музыки без ссылок из скриптов (алиас без вызова, неупомянутый файл): предупреждение, запуск не блокируется
    for (const rel of MUSIC_WARN) {
      const t = await fresh('music-warn-missing');
      fs.rmSync(t.file(rel));
      const r = await t.run();
      assert.equal(r.status, 'warn', rel); assert.equal(findingFor(r, rel).code, 'RES_MISSING'); assert.equal(findingFor(r, rel).severity, 'warn');
      assert.equal(describeReport(r).block, false);
    }
    // здоровая установка: музыка проверена по размеру, хеши не считаются (десятки МБ на запуск)
    const t = await fresh('music-size-only');
    const r = await t.run();
    assert.equal(r.status, 'ok');
    const musicItems = r.items.filter((i) => /^RESOURCE\/Sounds\/MUSIC\//.test(i.path));
    assert.equal(musicItems.length, KNOWN_MUSIC_PATHS.length + MUSIC_WARN.length);
    assert.ok(musicItems.every((i) => i.verified === 'size'), 'музыка: verified=size');
    assert.equal(r.counts.hashedFiles, r.items.filter((i) => i.verified === 'hash').length);
    assert.ok(!r.items.some((i) => /MUSIC/.test(i.path) && i.verified === 'hash'));
    // тот же размер, другое содержимое музыки не определяется (оговорка README), но предупреждения о размере нет
    fs.writeFileSync(t.file(CORIDOR), Buffer.alloc(content(CORIDOR).length, 0x41));
    assert.equal((await t.run()).status, 'ok');
    assert.ok(CHECK_RULES.some((c) => c.label === 'music' && c.sizeOnly === true));
  });

  await test('отсутствие нефатальной модели и текстуры: только предупреждение', async () => {
    const t = await fresh('warnmissing');
    fs.rmSync(t.file(GM_WARN[0]));
    fs.rmSync(t.file('RESOURCE/Textures/Items/Blade6.tga.tx'));
    fs.rmSync(t.file('options'));
    fs.rmSync(t.file(MODEL_ANY[0]));
    const r = await t.run();
    assert.equal(r.status, 'warn');
    assert.deepEqual(r.findings.filter((f) => f.severity === 'fatal'), []);
    assert.equal(r.findings.filter((f) => f.code === 'RES_MISSING').length, 4);
    assert.equal(findingFor(r, MODEL_ANY[0]).why, 'model'); assert.equal(findingFor(r, GM_WARN[0]).why, 'item-model');
    const d = describeReport(r);
    assert.equal(d.block, false); assert.equal(d.level, 'warn'); assert.match(d.message, /RES_MISSING/);
  });

  await test('обрезанный файл с неповреждённым заголовком: предупреждение RES_SIZE_MISMATCH, запуск не блокируется', async () => {
    const t = await fresh('trunc');
    fs.truncateSync(t.file(BLADE1), GM_HEADER_BYTES);                 // заголовок цел (по опыту G01-G03 такие файлы игра переживает)
    fs.truncateSync(t.file(GM_WARN[1]), 0);                           // не в таблице предметов: пустой файл только предупреждение
    const r = await t.run();
    assert.equal(r.status, 'warn');
    const f = findingFor(r, BLADE1);
    assert.equal(f.code, 'RES_SIZE_MISMATCH'); assert.equal(f.severity, 'warn');
    assert.equal(f.actualSize, GM_HEADER_BYTES); assert.equal(f.expectedSize, content(BLADE1).length);
    assert.equal(findingFor(r, GM_WARN[1]).actualSize, 0);
    assert.equal(findingFor(r, GM_WARN[1]).severity, 'warn');
  });

  await test('подменённый файл того же размера: RES_HASH_MISMATCH', async () => {
    const t = await fresh('swap');
    const orig = content(BLADE6); fs.writeFileSync(t.file(BLADE6), Buffer.concat([orig.subarray(0, GM_HEADER_BYTES), Buffer.alloc(orig.length - GM_HEADER_BYTES, 0x41)]));
    const r = await t.run();
    assert.equal(r.status, 'warn'); assert.equal(findingFor(r, BLADE6).code, 'RES_HASH_MISMATCH');
    assert.equal(r.counts.fatal, 0);
  });

  await test('манифест: структура, согласованность, версия, записи', async () => {
    const t = await fresh('manifest');
    // нет манифеста (офлайн / установка из папки): только наличие, без предупреждений
    let r = await t.run({ manifest: null, installedVersion: 'local' });
    assert.equal(r.status, 'ok'); assert.equal(r.mode, 'presence-only'); assert.equal(r.trust.level, 'absent');
    assert.deepEqual(r.items.map((i) => i.path).sort(), ['ENGINE.exe', 'MODULES/GEOMETRY.dll', 'PROGRAM/seadogs.c', 'engine.ini', 'options', ...KNOWN_GM_PATHS, ...KNOWN_MUSIC_PATHS].sort());
    assert.ok(r.items.every((i) => i.verified === 'presence'));
    fs.rmSync(t.file(BLADE1));
    r = await t.run({ manifest: null }); assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE1).code, 'RES_MISSING');
    // испорченные структуры
    for (const bad of [42, 'x', {}, { version: '', files: [] }, { version: 'v', files: 'no' }, { files: [] }]) {
      const rr = await t.run({ manifest: bad });
      assert.equal(rr.mode, 'presence-only'); assert.ok(codes(rr).includes('PF_MANIFEST_INVALID'), JSON.stringify(bad));
      assert.equal(rr.status, 'blocked');   // blade1 всё ещё удалён
    }
    const t2 = await fresh('manifest2');
    // отредактированная запись при старой version -> несогласованный манифест не используется
    const forged = JSON.parse(JSON.stringify(t2.manifest));
    forged.files.find((e) => e.path === BLADE6).sha256 = '0'.repeat(64);
    let rr = await t2.run({ manifest: forged });
    assert.equal(rr.mode, 'presence-only'); assert.equal(rr.trust.level, 'inconsistent'); assert.ok(codes(rr).includes('PF_MANIFEST_INCONSISTENT'));
    assert.equal(rr.status, 'warn');   // хеши не сверялись, обнаружения подмены нет — честно указано режимом
    // версия установки не равна манифесту
    rr = await t2.run({ installedVersion: 'oldversion123' });
    assert.equal(rr.mode, 'presence-only'); assert.equal(rr.trust.level, 'stale'); assert.ok(codes(rr).includes('PF_VERSION_MISMATCH'));
    rr = await t2.run({ installedVersion: null }); assert.equal(rr.trust.level, 'stale');
    // записи без sha256 / с неверным sha256: сверяется только размер
    const m3 = await manifestOf(t2.files, (m) => { m.files.forEach((e) => { if (e.path === BLADE6) delete e.sha256; }); return m; });
    rr = await t2.run({ manifest: m3 });
    assert.equal(rr.trust.level, 'unverified');   // не у всех записей есть хеш
    assert.equal(rr.items.find((i) => i.path === BLADE6).verified, 'size');
    // blade1 есть на диске, но нет в манифесте: наличие проверяется, ошибки нет; нет ни там ни там -> отказ
    const m4 = await manifestOf(t2.files.filter((p) => p !== BLADE1));
    rr = await t2.run({ manifest: m4, installedVersion: m4.version });
    assert.equal(rr.status, 'ok'); assert.equal(rr.items.find((i) => i.path === BLADE1).verified, 'presence');
    fs.rmSync(t2.file(BLADE1));
    rr = await t2.run({ manifest: m4, installedVersion: m4.version });
    assert.equal(rr.status, 'blocked'); assert.equal(findingFor(rr, BLADE1).inManifest, false);
    // небезопасные пути и неверные записи не попадают в проверку
    const m5 = await manifestOf(t2.files);
    m5.files.push({ path: 'RESOURCE/MODELS/Items/../../../etc/passwd', size: 1, sha256: '0'.repeat(64) }, null, { path: 5 });
    rr = await t2.run({ manifest: m5, installedVersion: m5.version });
    assert.ok(!rr.items.some((i) => i.path.includes('..')));
    assert.ok(codes(rr).includes('PF_MANIFEST_ENTRY_INVALID'));
    // дубликат пути без учёта регистра: запись неоднозначна, не используется
    const m6 = await manifestOf(t2.files);
    m6.files.push({ ...m6.files.find((e) => e.path === GM_WARN[0]), path: GM_WARN[0].toUpperCase() });
    rr = await t2.run({ manifest: m6, installedVersion: m6.version });
    assert.ok(codes(rr).includes('PF_MANIFEST_AMBIGUOUS') || codes(rr).includes('PF_MANIFEST_INCONSISTENT'));
  });

  await test('совместимость с реальным генератором манифеста gamefiles.manifest_for', async () => {
    const t = await fresh('pygen');
    const files = new Map();
    function visit(dir) { for (const entry of fs.readdirSync(dir, { withFileTypes: true })) { const full = path.join(dir, entry.name); if (entry.isDirectory()) visit(full); else files.set(path.relative(t.root, full).split(path.sep).join('/'), full); } }
    visit(t.root);
    const manifest = manifestFor(files);
    const r = await t.run({ manifest, installedVersion: manifest.version });
    assert.equal(r.trust.level, 'verified'); assert.equal(r.status, 'ok'); assert.equal(r.mode, 'verified');
  });

  await test('регистр имён и alias (память, как OPFS: регистр различается)', async () => {
    // Файловая система macOS не различает регистр, поэтому здесь дерево в памяти.
    class MemDir {
      constructor() { this.kind = 'directory'; this.kids = new Map(); }
      async *entries() { for (const [n, h] of this.kids) yield [n, h]; }
      async getDirectoryHandle(n, o) { assert.ok(!o?.create); const h = this.kids.get(n); if (!h) throw nfe(n); if (h.kind !== 'directory') throw Object.assign(new Error(n), { name: 'TypeMismatchError' }); return h; }
      async getFileHandle(n, o) { assert.ok(!o?.create); const h = this.kids.get(n); if (!h) throw nfe(n); if (h.kind !== 'file') throw Object.assign(new Error(n), { name: 'TypeMismatchError' }); return h; }
    }
    const memFile = (b) => ({ kind: 'file', async getFile() { return { size: b.length, slice: (x, y) => ({ arrayBuffer: async () => { const c = b.subarray(x, y); return c.buffer.slice(c.byteOffset, c.byteOffset + c.length); } }), arrayBuffer: async () => b.buffer.slice(b.byteOffset, b.byteOffset + b.length) }; } });
    const build = (spell) => {   // spell: rel -> фактический путь с другим регистром
      const root = new MemDir();
      for (const rel of fixtureFiles()) {
        const parts = (spell[rel] ?? rel).split('/'); let d = root;
        for (const p of parts.slice(0, -1)) { if (!d.kids.has(p)) d.kids.set(p, new MemDir()); d = d.kids.get(p); }
        d.kids.set(parts.at(-1), memFile(content(rel)));
      }
      return root;
    };
    const files = fixtureFiles(); const manifest = await manifestOf(files);
    const run = (root) => preflightResources({ openGameDir: async () => root, manifest, installedVersion: manifest.version, exe: 'ENGINE.exe', required: REQUIRED });
    // единственный вариант другого регистра (и в каталогах): игра найдёт его (core.c find_ci) — ok
    let root = build({ [BLADE1]: 'RESOURCE/MODELS/Items/BLADE1.GM', [BLADE6]: 'RESOURCE/MODELS/Items/Blade6.GM', 'ENGINE.exe': 'engine.EXE',
      // музыка: в алиасах Sea_battle01/Main_Theme, на диске Sea_Battle01/Main_theme; игра находит файл без учёта регистра
      'RESOURCE/Sounds/MUSIC/Sea_Battle01.ogg': 'RESOURCE/Sounds/MUSIC/SEA_BATTLE01.OGG' });
    let r = await run(root);
    assert.equal(r.status, 'ok', JSON.stringify(r.findings));
    assert.equal(r.items.find((i) => i.why === 'crash-music' && /sea_battle01/i.test(i.path)).verified, 'size');
    assert.equal(r.items.find((i) => i.path === BLADE1).verified, 'hash', 'хеш сверён для файла под другим регистром');
    // всё дерево в нижнем регистре: каждое имя имеет единственный вариант
    root = new MemDir(); { const low = {}; for (const f of files) low[f] = f.toLowerCase(); root = build(low); }
    r = await run(root); assert.equal(r.status, 'ok', JSON.stringify(r.findings));
    // точный каталог есть, но файл лежит в каталоге другого регистра: игра могла выбрать любой -> предупреждение
    root = build({ [BLADE1]: 'resource/MODELS/Items/blade1.gm' });
    r = await run(root); assert.equal(r.status, 'warn'); assert.equal(r.items.find((i) => i.path === BLADE1).result, 'ambiguous');
    // два варианта имени, точное совпадает: игра может выбрать любой -> предупреждение, не блокировка
    root = build({}); root.kids.get('RESOURCE').kids.get('MODELS').kids.get('Items').kids.set('BLADE6.GM', memFile(withHeader('other')));
    r = await run(root);
    assert.equal(r.status, 'warn'); assert.equal(findingFor(r, BLADE6).code, 'RES_AMBIGUOUS_CASE'); assert.equal(r.counts.fatal, 0);
    // точного имени нет, два чужих регистра -> неоднозначно (предупреждение)
    root = build({ [BLADE6]: 'RESOURCE/MODELS/Items/Blade6.gm' }); root.kids.get('RESOURCE').kids.get('MODELS').kids.get('Items').kids.set('BLADE6.GM', memFile(withHeader('o2')));
    r = await run(root);
    assert.equal(r.items.find((i) => i.path === BLADE6).result, 'ambiguous'); assert.equal(r.counts.fatal, 0); assert.equal(r.status, 'warn');
    // лишний каталог другого регистра рядом с точным: предупреждение, блокировки нет
    root = build({}); root.kids.get('RESOURCE').kids.set('models', new MemDir());
    r = await run(root); assert.equal(r.status, 'warn'); assert.equal(r.counts.fatal, 0);
    assert.ok(r.findings.every((f) => f.code === 'RES_AMBIGUOUS_CASE'));
    // каталог другого типа на месте файла / файл на месте каталога
    const t3 = await fresh('case3');
    fs.rmSync(t3.file(BLADE1)); fs.mkdirSync(t3.file(BLADE1));
    r = await t3.run();
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE1).code, 'RES_NOT_FILE');
    root = build({}); root.kids.get('RESOURCE').kids.get('MODELS').kids.set('Items', memFile(Buffer.from('f')));
    r = await run(root); assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE1).code, 'RES_NOT_FILE');
  });

  await test('симлинки', async () => {
    const t = await fresh('symlink');
    const outside = mkTmp('symlink-target');
    // симлинк на файл с верным содержимым -> ок (как и для игры, open следует ссылке)
    fs.writeFileSync(path.join(outside, 'b1'), content(BLADE1));
    fs.rmSync(t.file(BLADE1)); fs.symlinkSync(path.join(outside, 'b1'), t.file(BLADE1));
    let r = await t.run(); assert.equal(r.status, 'ok');
    // симлинк на файл с неверным содержимым -> предупреждение о хеше
    fs.writeFileSync(path.join(outside, 'b1'), Buffer.concat([content(BLADE1).subarray(0, GM_HEADER_BYTES), Buffer.alloc(content(BLADE1).length - GM_HEADER_BYTES, 1)]));
    r = await t.run(); assert.equal(findingFor(r, BLADE1).code, 'RES_HASH_MISMATCH');
    // висячий симлинк -> файл не открыть, отказ
    fs.rmSync(path.join(outside, 'b1'));
    r = await t.run(); assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE1).code, 'RES_MISSING');
    // симлинк на каталог Items
    const t2 = await fresh('symlink-dir');
    const real = path.join(outside, 'Items'); fs.renameSync(t2.file('RESOURCE/MODELS/Items'), real);
    fs.symlinkSync(real, t2.file('RESOURCE/MODELS/Items'));
    r = await t2.run(); assert.equal(r.status, 'ok');
    // цикл симлинков не вешает проверку
    const t3 = await fresh('symlink-loop');
    fs.rmSync(t3.file(BLADE6)); fs.symlinkSync(t3.file(BLADE6), t3.file(BLADE6));
    r = await t3.run(); assert.equal(r.status, 'blocked');
  });

  await test('нет прав чтения', async () => {
    if (process.getuid?.() === 0) { console.log('  (пропущено: запуск от root)'); return; }
    const t = await fresh('perm');
    fs.chmodSync(t.file(BLADE1), 0o000);
    try {
      try { fs.readFileSync(t.file(BLADE1)); console.log('  (пропущено: chmod 000 не ограничивает чтение)'); return; } catch { /* ожидаемо */ }
      const r = await t.run();
      assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE1).code, 'RES_UNREADABLE'); assert.equal(findingFor(r, BLADE1).detail, 'NotAllowedError');
      // нефатальный файл без прав -> предупреждение
      fs.chmodSync(t.file(BLADE1), 0o644);
      fs.chmodSync(t.file(GM_WARN[0]), 0o000);
      const r2 = await t.run();
      assert.equal(r2.status, 'warn'); assert.equal(findingFor(r2, GM_WARN[0]).code, 'RES_UNREADABLE');
      // каталог без прав на перечисление
      fs.chmodSync(t.file(GM_WARN[0]), 0o644);
      fs.chmodSync(t.file('RESOURCE/MODELS/Items'), 0o000);
      const r3 = await t.run();
      assert.equal(r3.status, 'blocked'); assert.ok(r3.findings.some((f) => f.severity === 'fatal' && f.code === 'RES_UNREADABLE'));
    } finally {
      fs.chmodSync(t.file('RESOURCE/MODELS/Items'), 0o755); fs.chmodSync(t.file(BLADE1), 0o644);
      fs.chmodSync(t.file(GM_WARN[0]), 0o644);
    }
  });

  await test('ошибка чтения содержимого и изменение файла во время проверки', async () => {
    const t = await fresh('io');
    const rootHandle = new FsDir(t.root);
    // arrayBuffer бросает NotReadableError
    const wrap = (h) => Object.assign(Object.create(Object.getPrototypeOf(h)), h, {
      async getFile() { const f = await h.getFile(); return { size: f.size, arrayBuffer: async () => { throw Object.assign(new Error('io'), { name: 'NotReadableError' }); } }; } });
    const root2 = { async *entries() { for await (const [n, h] of rootHandle.entries()) yield [n, n === 'ENGINE.exe' ? wrap(h) : h]; },
      getDirectoryHandle: (...a) => rootHandle.getDirectoryHandle(...a), getFileHandle: (...a) => rootHandle.getFileHandle(...a) };
    let r = await t.run({ openGameDir: async () => root2 });
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, 'ENGINE.exe').code, 'RES_UNREADABLE');
    // arrayBuffer возвращает другое число байт, чем size -> RES_CHANGED (предупреждение)
    const wrap2 = (h) => Object.assign(Object.create(Object.getPrototypeOf(h)), h, {
      async getFile() { const f = await h.getFile(); return { size: f.size, arrayBuffer: async () => new ArrayBuffer(f.size + 1) }; } });
    const root3 = { async *entries() { for await (const [n, h] of rootHandle.entries()) yield [n, n === 'ENGINE.exe' ? wrap2(h) : h]; },
      getDirectoryHandle: (...a) => rootHandle.getDirectoryHandle(...a), getFileHandle: (...a) => rootHandle.getFileHandle(...a) };
    r = await t.run({ openGameDir: async () => root3 });
    assert.equal(r.status, 'warn'); assert.equal(findingFor(r, 'ENGINE.exe').code, 'RES_CHANGED');
    // хостовый WebCrypto недоступен -> только размеры и предупреждение PF_NO_HASH
    r = await t.run({ sha256: async () => { throw new Error('no crypto'); } });
    assert.ok(codes(r).includes('PF_NO_HASH')); assert.equal(r.counts.hashedFiles, 0);
  });

  await test('корень без entries() (минимальный FileSystemDirectoryHandle): точные имена', async () => {
    const t = await fresh('noentries');
    const h = new FsDir(t.root);
    const minimal = (d) => ({ getDirectoryHandle: async (n, o) => minimal(await d.getDirectoryHandle(n, o)), getFileHandle: (n, o) => d.getFileHandle(n, o) });
    let r = await t.run({ openGameDir: async () => minimal(h) });
    assert.equal(r.status, 'ok');
    fs.rmSync(t.file(BLADE6));
    r = await t.run({ openGameDir: async () => minimal(h) });
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE6).code, 'RES_MISSING');
  });

  await test('большой манифест: читаются только защищаемые файлы, пределы соблюдены', async () => {
    const t = await fresh('big');
    const m = JSON.parse(JSON.stringify(t.manifest));
    for (let i = 0; i < 60000; i++) m.files.push({ path: `RESOURCE/Locations/L${i % 977}/f${i}.bin`, size: 100 + i, sha256: sha(`n${i}`) });
    m.version = await manifestVersionDigest(m.files);
    readLog.files.clear(); const lists0 = readLog.lists;
    const t0 = Date.now();
    const r = await t.run({ manifest: m, installedVersion: m.version });
    const ms = Date.now() - t0;
    assert.equal(r.status, 'ok'); assert.equal(r.trust.level, 'verified');
    assert.ok(ms < 15000, `слишком долго: ${ms} мс`);
    assert.equal(readLog.files.size, r.items.filter((i) => i.why !== 'model').length, 'прочитаны только запланированные файлы (прочие модели: только список каталога)');
    assert.ok(MODEL_ANY.every((p) => !readLog.files.has(t.file(p))), 'прочие модели не открываются (getFile не вызывается)');
    assert.ok(readLog.lists - lists0 < 30, 'каталоги перечисляются один раз за вызов');
    // слишком много проверяемых файлов (Items-записей): предел, fatal-класс всё равно проверен первым
    const m2 = JSON.parse(JSON.stringify(t.manifest));
    for (let i = 0; i < LIMITS.maxProtected + 300; i++) m2.files.push({ path: `RESOURCE/MODELS/Items/gen${i}.gm`, size: 5, sha256: sha(`g${i}`) });
    m2.version = await manifestVersionDigest(m2.files);
    fs.rmSync(t.file(BLADE1));
    const r2 = await t.run({ manifest: m2, installedVersion: m2.version });
    assert.equal(r2.status, 'blocked'); assert.equal(findingFor(r2, BLADE1).code, 'RES_MISSING');
    assert.equal(r2.items.length, LIMITS.maxProtected);
    assert.ok(codes(r2).includes('PF_LIMITS'));
    assert.ok(r2.findings.length <= LIMITS.maxWarnFindings + 10, 'число предупреждений ограничено');
    assert.ok(r2.warningsDropped > 0 && r2.counts.warn > LIMITS.maxWarnFindings, 'счётчик warn остаётся точным');
    // манифест с записями выше предела разбора
    assert.ok(LIMITS.maxManifestFiles >= 100000);
  });

  await test('повторные вызовы дают тот же результат и не хранят состояние', async () => {
    const t = await fresh('repeat');
    const strip = (r) => ({ ...r, stats: undefined });
    const a = strip(await t.run()), b = strip(await t.run());
    assert.deepEqual(a, b);
    fs.rmSync(t.file(BLADE1));
    const c = await t.run(); assert.equal(c.status, 'blocked');
    fs.writeFileSync(t.file(BLADE1), content(BLADE1));
    const d = strip(await t.run()); assert.deepEqual(d, a);
    const results = await Promise.all([t.run(), t.run(), t.run()]);
    assert.ok(results.every((r) => r.status === 'ok'));
    const dsc = describeReport(a); assert.deepEqual(dsc, describeReport(b));
  });

  await test('отсутствие данных не вызывает записи: дерево каталога не меняется', async () => {
    const t = await fresh('nowrite');
    fs.rmSync(t.file(BLADE1)); fs.truncateSync(t.file(BLADE6), 3); fs.rmSync(t.file('RESOURCE/Textures/Items/blade2.gm'), { force: true });
    fs.writeFileSync(t.file('options'), 'user-modified'); // изменяемый файл
    fs.mkdirSync(t.file('SAVE/slot1'), { recursive: true }); fs.writeFileSync(t.file('SAVE/slot1/data'), 'player');
    fs.mkdirSync(t.file('SAVE_META'), { recursive: true }); fs.writeFileSync(t.file('SAVE_META/m'), 'meta');
    fs.writeFileSync(t.file('installed.json'), '{"version":"x"}');
    const before = snapshotTree(t.root);
    for (let i = 0; i < 3; i++) { const r = await t.run(); assert.equal(r.status, 'blocked'); }
    assert.equal(snapshotTree(t.root), before);
    assert.equal(writeLog.length, 0);
    assert.ok(!readLog.files.has(t.file('SAVE/slot1/data')) && !readLog.files.has(t.file('SAVE_META/m')), 'SAVE не читается');
    // изменяемый options: только наличие
    const r = await t.run(); assert.equal(r.items.find((i) => i.path === 'options').verified, 'presence');
  });

  await test('checkResourcesBeforeRun: собственный сбой не блокирует запуск; аргументы', async () => {
    const t = await fresh('entry');
    const badManifest = { get version() { throw new Error('boom'); }, files: [] };
    const v = await checkResourcesBeforeRun({ openGameDir: open(t.root), manifest: badManifest, installedVersion: 'x' });
    assert.equal(v.block, false); assert.equal(v.level, 'error'); assert.equal(v.code, 'PF_INTERNAL'); assert.equal(v.report.status, 'error');
    const v2 = await checkResourcesBeforeRun({});
    assert.equal(v2.block, false); assert.equal(v2.code, 'PF_INTERNAL');
    // openGameDir бросает не NotFound -> нечитаемо, отказ
    const v3 = await checkResourcesBeforeRun({ openGameDir: async () => { throw Object.assign(new Error('q'), { name: 'SecurityError' }); } });
    assert.equal(v3.block, true); assert.equal(v3.code, 'RES_UNREADABLE');
    const ok = await checkResourcesBeforeRun({ openGameDir: open(t.root), manifest: t.manifest, installedVersion: t.manifest.version, required: REQUIRED });
    assert.equal(ok.block, false); assert.equal(ok.level, 'ok'); assert.equal(ok.report.status, 'ok');
  });

  // ---- .gm: GEOMETRY.dll бросает исключение при любом неудавшемся открытии .gm и при неверном заголовке (PORT_SPECIFICATION.md)
  await test('списки .gm: без дубликатов, непересекающиеся, пути под RESOURCE/MODELS, заголовок 50.1 / 72 байта', () => {
    assert.equal(GM_MAGIC, '50.1'); assert.equal(GM_HEADER_BYTES, 72);
    assert.equal(KNOWN_ITEM_MODELS.length, 45); assert.equal(KNOWN_AMMO_MODELS.length, 29); assert.equal(KNOWN_STARTUP_MODELS.length, 17);
    assert.equal(KNOWN_GM_PATHS.length, 45 + 29 + 17);
    const low = KNOWN_GM_PATHS.map((p) => p.toLowerCase());
    assert.equal(new Set(low).size, low.length, 'пересечений и дубликатов нет (Items/blade1 и Ammo/blade1 — разные файлы)');
    assert.ok(KNOWN_GM_PATHS.every((p) => /^RESOURCE\/MODELS\/.+\.gm$/.test(p) && !p.includes('..')));
    assert.ok(KNOWN_CRASH_PATHS.every((p) => KNOWN_ITEM_MODELS.includes(p)), 'blade1/blade6 входят в модели предметов');
    assert.ok(Object.isFrozen(KNOWN_GM_PATHS) && Object.isFrozen(KNOWN_ITEM_MODELS) && Object.isFrozen(KNOWN_AMMO_MODELS) && Object.isFrozen(KNOWN_STARTUP_MODELS));
    assert.ok(CHECK_RULES.some((c) => c.label === 'model' && c.listOnly === true && c.prefix === 'resource/models/'));
    assert.ok(CHECK_RULES.findIndex((c) => c.label === 'item-model') < CHECK_RULES.findIndex((c) => c.label === 'model'), 'Items сверяются раньше общего правила моделей');
  });

  await test('каждая модель из KNOWN_GM_PATHS: отсутствие = отказ RES_MISSING (с манифестом и без него); модели вне списков — предупреждение', async () => {
    for (const rel of KNOWN_GM_PATHS) {
      const t = await fresh('gm-missing');
      fs.rmSync(t.file(rel));
      for (const extra of [{}, { manifest: null, installedVersion: 'local' }]) {
        const r = await t.run(extra);
        assert.equal(r.status, 'blocked', `${rel} ${JSON.stringify(extra)}`);
        const f = findingFor(r, rel);
        assert.equal(f.code, CODES.RES_MISSING, rel); assert.equal(f.severity, 'fatal', rel);
        assert.equal(f.why, KNOWN_CRASH_PATHS.includes(rel) ? 'crash-known' : 'crash-gm', rel);
        const d = describeReport(r);
        assert.equal(d.block, true); assert.equal(d.code, 'RES_MISSING'); assert.match(d.message, /аварийно завершается/); assert.match(d.message, /Игра не запущена/);
      }
    }
    // отсутствует целый каталог Ammo / Islands: все его записи — отказ, один код
    for (const dir of ['RESOURCE/MODELS/Ammo', 'RESOURCE/MODELS/Islands', 'RESOURCE/MODELS/Heads']) {
      const t = await fresh('gm-dir');
      fs.rmSync(t.file(dir), { recursive: true });
      const r = await t.run();
      assert.equal(r.status, 'blocked', dir);
      assert.ok(r.counts.fatal >= 1 && r.findings.filter((f) => f.severity === 'fatal').every((f) => f.code === 'RES_MISSING' && f.path.startsWith(dir + '/')), dir);
    }
    // каталог на месте файла
    const t = await fresh('gm-notfile'); fs.rmSync(t.file(AMMO_ONE)); fs.mkdirSync(t.file(AMMO_ONE));
    const rn = await t.run(); assert.equal(findingFor(rn, AMMO_ONE).code, 'RES_NOT_FILE'); assert.equal(rn.status, 'blocked');
  });

  await test('модели вне списков (Items без ссылок, прочие .gm): отсутствие — только предупреждение; наличие проверяется без чтения', async () => {
    for (const [rel, why] of [[GM_WARN[0], 'item-model'], [GM_WARN[1], 'item-model'], [MODEL_ANY[0], 'model'], [MODEL_ANY[1], 'model']]) {
      const t = await fresh('gm-warn');
      fs.rmSync(t.file(rel));
      const r = await t.run();
      assert.equal(r.status, 'warn', rel); assert.equal(r.counts.fatal, 0);
      const f = findingFor(r, rel); assert.equal(f.code, 'RES_MISSING'); assert.equal(f.severity, 'warn'); assert.equal(f.why, why);
      assert.equal(describeReport(r).block, false);
      // без манифеста список прочих моделей неизвестен: ничего не проверяется
      const rp = await t.run({ manifest: null, installedVersion: 'local' });
      assert.equal(rp.status, 'ok', rel);
    }
    // прочая модель с пустым/мусорным содержимым не читается: предупреждения нет (оговорка README)
    const t = await fresh('gm-any-garbage');
    fs.writeFileSync(t.file(MODEL_ANY[0]), 'garbage');
    readLog.files.clear();
    const r = await t.run();
    assert.equal(r.status, 'ok'); assert.ok(!readLog.files.has(t.file(MODEL_ANY[0])));
    // Items без ссылок: сверяется размер/хеш (предупреждение), заголовок не проверяется
    fs.writeFileSync(t.file(GM_WARN[0]), 'garbage'); fs.writeFileSync(t.file(GM_WARN[1]), withHeader(GM_WARN[1]));
    const r2 = await t.run();
    assert.equal(r2.status, 'warn'); assert.equal(r2.counts.fatal, 0); assert.ok(findingFor(r2, GM_WARN[0]).code === 'RES_SIZE_MISMATCH');
    assert.equal(r2.items.find((i) => i.path === GM_WARN[1]).verified, 'hash');
  });

  await test('заголовок .gm: пустой, короче 72 байт, не "50.1" — отказ RES_BAD_HEADER (с манифестом и без него)', async () => {
    const full = (rel) => content(rel);
    const bad = {
      'пустой файл': () => Buffer.alloc(0),
      'короче заголовка (71 байт, версия верная)': (rel) => full(rel).subarray(0, GM_HEADER_BYTES - 1),
      'только версия': () => Buffer.from(GM_MAGIC),
      'версия 20.1 (sky.gm)': (rel) => Buffer.concat([Buffer.from('20.1'), full(rel).subarray(4)]),
      'версия 50.2': (rel) => Buffer.concat([Buffer.from('50.2'), full(rel).subarray(4)]),
      'версия 05.1 (перестановка)': (rel) => Buffer.concat([Buffer.from('05.1'), full(rel).subarray(4)]),
      'нули': (rel) => Buffer.alloc(full(rel).length),
      'текст': (rel) => Buffer.alloc(full(rel).length, 0x41),
      'регистр/пробел: " 50."': (rel) => Buffer.concat([Buffer.from(' 50.'), full(rel).subarray(4)]),
    };
    for (const rel of [BLADE1, ITEM_OTHER, AMMO_ONE, STARTUP_ONE, KNOWN_STARTUP_MODELS.at(-1)]) {
      for (const [name, make] of Object.entries(bad)) {
        const t = await fresh('gm-header');
        fs.writeFileSync(t.file(rel), make(rel));
        for (const extra of [{}, { manifest: null, installedVersion: 'local' }]) {
          const r = await t.run(extra);
          assert.equal(r.status, 'blocked', `${rel}: ${name} ${JSON.stringify(extra)}`);
          const f = findingFor(r, rel);
          assert.equal(f.code, CODES.RES_BAD_HEADER, `${rel}: ${name}`); assert.equal(f.severity, 'fatal');
          const d = describeReport(r); assert.equal(d.block, true); assert.equal(d.code, 'RES_BAD_HEADER'); assert.match(d.message, /RES_BAD_HEADER/);
          assert.match(d.message, /Игра не запущена/); assert.match(d.message, /Сохранения и настройки не затронуты/);
        }
      }
    }
    // исправный заголовок, но другой размер/содержимое — только предупреждение (опыты G01-G03: игра переживает обрезку после заголовка)
    for (const rel of [BLADE1, AMMO_ONE, STARTUP_ONE]) {
      const t = await fresh('gm-header-ok');
      fs.truncateSync(t.file(rel), GM_HEADER_BYTES);
      let r = await t.run(); assert.equal(r.status, 'warn', rel); assert.equal(findingFor(r, rel).code, 'RES_SIZE_MISMATCH'); assert.equal(r.counts.fatal, 0);
      fs.writeFileSync(t.file(rel), withHeader(rel, 'tail'));
      r = await t.run(); assert.equal(r.status, 'warn'); assert.equal(findingFor(r, rel).code, 'RES_SIZE_MISMATCH');
      r = await t.run({ manifest: null, installedVersion: 'local' }); assert.equal(r.status, 'ok', 'без манифеста размер не сверяется');
    }
    // читаются только 4 байта заголовка: в presence-only файл целиком не читается
    const t = await fresh('gm-header-bytes');
    readLog.sliceBytes = 0;
    const rp = await t.run({ manifest: null, installedVersion: 'local' });
    assert.equal(rp.status, 'ok');
    assert.equal(readLog.sliceBytes, 4 * KNOWN_GM_PATHS.length, 'по 4 байта на модель');
    assert.equal(rp.counts.hashedBytes, 0);
    // граничный размер ровно 72: заголовок принят
    fs.writeFileSync(t.file(BLADE1), Buffer.concat([Buffer.from(GM_MAGIC), Buffer.alloc(GM_HEADER_BYTES - 4)]));
    assert.equal((await t.run({ manifest: null, installedVersion: 'local' })).status, 'ok');
    fs.writeFileSync(t.file(BLADE1), Buffer.concat([Buffer.from(GM_MAGIC), Buffer.alloc(GM_HEADER_BYTES - 5)]));
    assert.equal((await t.run({ manifest: null, installedVersion: 'local' })).status, 'blocked');
  });

  await test('заголовок .gm: сбой чтения заголовка — нечитаемо (отказ); file.slice недоступен — проверка заголовка пропускается', async () => {
    const t = await fresh('gm-slice');
    const rootHandle = new FsDir(t.root);
    const wrapFile = (h, mk) => Object.assign(Object.create(Object.getPrototypeOf(h)), h, { async getFile() { const f = await h.getFile(); return mk(f); } });
    const rootWith = (name, mk) => {
      const walk = (dir, prefix) => ({
        async *entries() { for await (const [n, h] of dir.entries()) { const rel = prefix ? `${prefix}/${n}` : n;
          yield [n, h.kind === 'directory' ? walk(h, rel) : (rel === name ? wrapFile(h, mk) : h)]; } },
        kind: 'directory',
        getDirectoryHandle: async (n, o) => walk(await dir.getDirectoryHandle(n, o), prefix ? `${prefix}/${n}` : n),
        getFileHandle: async (n, o) => { const h = await dir.getFileHandle(n, o); const rel = prefix ? `${prefix}/${n}` : n; return rel === name ? wrapFile(h, mk) : h; },
      });
      return walk(rootHandle, '');
    };
    // slice().arrayBuffer() бросает NotReadableError
    let r = await t.run({ openGameDir: async () => rootWith(BLADE1, (f) => ({ ...f, slice: () => ({ arrayBuffer: async () => { throw Object.assign(new Error('io'), { name: 'NotReadableError' }); } }) })) });
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, BLADE1).code, 'RES_UNREADABLE'); assert.equal(findingFor(r, BLADE1).detail, 'NotReadableError');
    // нет slice (нестандартный File): проверка заголовка не выполняется, остальное работает (хеш сверяется)
    r = await t.run({ openGameDir: async () => rootWith(BLADE1, (f) => ({ size: f.size, arrayBuffer: f.arrayBuffer })) });
    assert.equal(r.status, 'ok'); assert.equal(r.items.find((i) => i.path === BLADE1).verified, 'hash');
    // нет slice и мусорное содержимое: ловится хешем (предупреждение), блокировки нет — честная оговорка
    fs.writeFileSync(t.file(BLADE1), Buffer.alloc(content(BLADE1).length, 0x41));
    r = await t.run({ openGameDir: async () => rootWith(BLADE1, (f) => ({ size: f.size, arrayBuffer: f.arrayBuffer })) });
    assert.equal(r.status, 'warn'); assert.equal(findingFor(r, BLADE1).code, 'RES_HASH_MISMATCH');
  });

  await test('данные: известные ресурсы и, при наличии raw-game, сверка скриптов и моделей', async () => {
    if (process.env.PREFLIGHT_FAST) { console.log('- PREFLIGHT_FAST: сверка с настоящей игрой пропущена'); return; }
    const gameDirLocal = path.resolve(here, '../../game');
    const dataFile = path.resolve(here, '../../tools/resource-audit/known-mines.json');
    const auditPy = path.resolve(here, '../../tools/resource-audit/audit_refs.mjs');
    assert.ok(fs.existsSync(dataFile), `не найден обязательный файл ${dataFile}`);
    const data = JSON.parse(fs.readFileSync(dataFile, 'utf8'));
    assert.equal(data.schema, 1);
    assert.equal(data.gm.magic, GM_MAGIC); assert.equal(data.gm.header_bytes, GM_HEADER_BYTES);
    assert.deepEqual(data.gm.items, [...KNOWN_ITEM_MODELS], 'JSON.items != KNOWN_ITEM_MODELS');
    assert.deepEqual(data.gm.ammo, [...KNOWN_AMMO_MODELS], 'JSON.ammo != KNOWN_AMMO_MODELS');
    assert.deepEqual([...data.gm.startup].sort(), [...KNOWN_STARTUP_MODELS].sort(), 'JSON.startup != KNOWN_STARTUP_MODELS');
    // известные ссылки: нет невыясненных; каждая запись имеет класс достижимости и примечание
    assert.ok(data.known_missing_refs.every((m) => m.reach !== 'unclassified' && m.note && m.expected && m.kind));
    // h_offic_hol закрыт данными (korsary2-next/tools/apply_content_fixes.mjs): голова добавлена, ссылка больше не пропавшая
    assert.ok(!data.known_missing_refs.some((m) => /h_offic_hol\.gm$/i.test(m.expected)), 'h_offic_hol: закрыт apply_content_fixes.mjs, не должен быть пропавшей ссылкой');
    // В чистом checkout уже есть PROGRAM и один INI в RESOURCE. Ни ENGINE.exe, ни моделей
    // там нет; при любом признаке восстановления проверяем дерево и сообщаем о повреждениях.
    if (!fs.existsSync(path.join(gameDirLocal, 'ENGINE.exe')) &&
        !fs.existsSync(path.join(gameDirLocal, 'RESOURCE/MODELS'))) {
      console.log('- raw-game: RESOURCE не восстановлен; сверка с исходными ресурсами пропущена');
      return;
    }
    assert.ok(fs.existsSync(path.join(gameDirLocal, 'RESOURCE/MODELS/Heads/h_Offic_hol.gm')), 'h_Offic_hol.gm должен существовать (node korsary2-next/tools/apply_content_fixes.mjs)');
    if (!fs.existsSync(path.join(gameDirLocal, 'PROGRAM/Items')) && !fs.existsSync(path.join(gameDirLocal, 'PROGRAM/ITEMS'))) { console.log('- каталог игры не найден: сверка со скриптом пропущена'); return; }
    // статический скрипт (быстрый режим, без чтения .gm): те же списки и те же пропавшие ссылки (кроме текстур)
    const outFile = path.join(mkTmp('audit'), 'audit.json');
    execFileSync(process.execPath, [auditPy, '--game', gameDirLocal, '--no-textures', '--out', outFile], { encoding: 'utf8', maxBuffer: 64 << 20 });
    const out = JSON.parse(fs.readFileSync(outFile, 'utf8'));
    assert.deepEqual(out.lists.items, [...KNOWN_ITEM_MODELS], 'audit_refs.mjs: список предметов != KNOWN_ITEM_MODELS (изменились скрипты или файлы игры)');
    assert.deepEqual(out.lists.ammo, [...KNOWN_AMMO_MODELS], 'audit_refs.mjs: список Ammo != KNOWN_AMMO_MODELS');
    const key = (m) => `${m.kind}|${m.expected}|${m.reach}`;
    assert.deepEqual(out.missing.map(key).sort(), data.known_missing_refs.filter((m) => m.kind !== 'texture').map(key).sort(),
      'пропавшие ссылки скрипта != known-mines.json (перегенерируйте: audit_refs.mjs --emit-data)');
    // файлы настоящей игры: все модели списков опубликованы, существуют и начинаются с "50.1"
    const published = new Set(gameFiles(gameDirLocal).keys());
    for (const p of KNOWN_GM_PATHS) {
      assert.ok(published.has(p), `${p}: нет в публикуемом наборе (регистр имени как на диске)`);
      const fd = fs.openSync(path.join(gameDirLocal, ...p.split('/')), 'r'); const b = Buffer.alloc(4); fs.readSync(fd, b, 0, 4, 0); fs.closeSync(fd);
      assert.equal(b.toString('latin1'), GM_MAGIC, `${p}: заголовок не 50.1`);
      assert.ok(fs.statSync(path.join(gameDirLocal, ...p.split('/'))).size >= GM_HEADER_BYTES, p);
    }
  });

  // ---- опционально: реальный манифест и реальные файлы dist (только чтение; поднабор копируется во временный каталог)
  const distRoot = process.env.K2_DISTRIBUTION_ROOT ? path.resolve(process.env.K2_DISTRIBUTION_ROOT) : path.resolve(here, '../../../distribution');
  const dist = path.join(distRoot, 'game');
  // Распакованная установка и пакетированная сборка устроены по-разному. В последней
  // проверяем наличие всех ключевых файлов и подлинность выборки внутри пакетов.
  if (!process.env.PREFLIGHT_FAST && fs.existsSync(path.join(dist, 'manifest.json'))) {
    await test('сборка: ключевые ресурсы в манифесте, выборка распаковывается и совпадает с SHA-256', async () => {
      const manifest = JSON.parse(fs.readFileSync(path.join(dist, 'manifest.json'), 'utf8'));
      const entries = new Map(manifest.files.map((e) => [e.path.toLowerCase(), e]));
      for (const p of [...KNOWN_GM_PATHS, ...KNOWN_MUSIC_PATHS])
        assert.ok(entries.has(p.toLowerCase()), `${p}: нет в манифесте сборки`);
      for (const p of [BLADE1, BLADE6]) {
        const e = entries.get(p.toLowerCase());
        let bytes;
        if (e.pack !== undefined) {
          const pack = manifest.packs[e.pack];
          assert.ok(pack && e.offset + e.csize <= pack.size, `${p}: неверный диапазон пакета`);
          const fd = fs.openSync(path.join(dist, pack.path), 'r');
          try { bytes = Buffer.alloc(e.csize); assert.equal(fs.readSync(fd, bytes, 0, e.csize, e.offset), e.csize); }
          finally { fs.closeSync(fd); }
        } else {
          bytes = fs.readFileSync(path.join(dist, e.path + (e.enc === 'gzip' ? '.gz' : e.enc === 'br' ? '.br' : '')));
        }
        if (e.enc === 'gzip') bytes = gunzipSync(bytes);
        else if (e.enc === 'br') bytes = brotliDecompressSync(bytes);
        else assert.ok(!e.enc, `${p}: неизвестное сжатие ${e.enc}`);
        assert.equal(bytes.length, e.size, p);
        assert.equal(sha(bytes), e.sha256, p);
        assert.equal(bytes.subarray(0, 4).toString('latin1'), GM_MAGIC, p);
      }
    });
  }
  if (!process.env.PREFLIGHT_FAST && fs.existsSync(path.join(dist, 'manifest.json')) && fs.existsSync(path.join(dist, 'RESOURCE/MODELS/Items'))) {
    await test('реальный dist: манифест согласован, Items/ENGINE совпадают; удаление blade1 в КОПИИ даёт отказ', async () => {
      const manifest = JSON.parse(fs.readFileSync(path.join(dist, 'manifest.json'), 'utf8'));
      const required = JSON.parse(fs.readFileSync(path.resolve(here, '../../port.json'), 'utf8')).files.required;
      const r = await preflightResources({ openGameDir: open(dist), manifest, installedVersion: manifest.version, exe: 'ENGINE.exe', required });
      assert.equal(r.trust.level, 'verified');
      assert.ok(r.counts.planned >= 100, `planned=${r.counts.planned}`);
      assert.equal(r.status, 'ok', JSON.stringify(r.findings.slice(0, 5)));
      assert.ok(r.items.find((i) => i.path === BLADE1).verified === 'hash');
      assert.ok(KNOWN_MUSIC_PATHS.every((p) => r.items.some((i) => i.path.toLowerCase() === p.toLowerCase() && i.cls === 'fatal' && i.verified === 'size')),
        'вся запрашиваемая музыка настоящего dist на месте, размер совпадает с манифестом');
      // копия поднабора: Items-модели/текстуры + обязательные файлы (несколько МБ)
      const copy = mkTmp('realcopy');
      for (const i of r.items) {
        const dst = path.join(copy, ...i.path.split('/')); fs.mkdirSync(path.dirname(dst), { recursive: true });
        if (i.verified === 'size') { const fd = fs.openSync(dst, 'w'); fs.ftruncateSync(fd, i.actualSize); fs.closeSync(fd); }   // музыка: нужен только размер
        else if (i.why === 'model') fs.closeSync(fs.openSync(dst, 'w'));   // прочие модели (705 МБ): проверяется только наличие в списке каталога
        else fs.copyFileSync(path.join(dist, ...i.path.split('/')), dst);
      }
      const run = () => preflightResources({ openGameDir: open(copy), manifest, installedVersion: manifest.version, exe: 'ENGINE.exe', required });
      assert.equal((await run()).status, 'ok');
      fs.rmSync(path.join(copy, ...BLADE1.split('/')));
      const blocked = await run();
      assert.equal(blocked.status, 'blocked'); assert.equal(describeReport(blocked).code, 'RES_MISSING');
      fs.writeFileSync(path.join(copy, ...BLADE1.split('/')), '');   // не важно: ниже проверяется музыка отдельно
      fs.copyFileSync(path.join(dist, ...BLADE1.split('/')), path.join(copy, ...BLADE1.split('/')));
      const mus = r.items.find((i) => i.path.toLowerCase() === CORIDOR.toLowerCase()).path;
      fs.rmSync(path.join(copy, ...mus.split('/')));
      const noMusic = await run();
      assert.equal(noMusic.status, 'blocked'); assert.equal(findingFor(noMusic, mus).code, 'RES_MISSING'); assert.equal(findingFor(noMusic, mus).why, 'crash-music');
      // оригинал dist не изменялся: blade1 на месте
      assert.ok(fs.existsSync(path.join(dist, ...BLADE1.split('/'))));
      console.log(`  реальный dist: запланировано ${r.counts.planned}, хешировано ${r.counts.hashedFiles} файлов / ${r.counts.hashedBytes} байт за ${r.stats.elapsedMs} мс`);
    });
  } else console.log('- распакованная установка в сборке отсутствует: проверка физического дерева пропущена');

  // ---- опционально: список музыки сверяется с настоящими скриптами/алиасами игры (только чтение имён и текстов)
  const gameDir = path.resolve(here, '../../game');
  const aliasIni = path.join(gameDir, 'RESOURCE/INI/ALIASES/music_alias.ini');
  if (!process.env.PREFLIGHT_FAST && fs.existsSync(aliasIni) && fs.existsSync(path.join(gameDir, 'PROGRAM/sound.c'))) {
    await test('настоящая игра: KNOWN_MUSIC_PATHS == музыка, достижимая из скриптов; всё есть в наборе файлов dist', async () => {
      const read = (rel) => fs.readFileSync(path.join(gameDir, rel), 'latin1');
      // алиасы: [имя] + строки name = MUSIC\file.ogg (music_alias.ini и дубль music_bitva в sound_alias.ini)
      const aliases = new Map();
      for (const rel of ['RESOURCE/INI/ALIASES/music_alias.ini', 'RESOURCE/INI/ALIASES/sound_alias.ini']) {
        let cur = null;
        for (const line of read(rel).split(/\r?\n/)) {
          const h = /^\s*\[([^\]]+)\]/.exec(line);
          if (h) { cur = h[1].toLowerCase(); continue; }
          const n = /^\s*name\s*=\s*MUSIC\\([^,\r\n]+\.ogg)\s*$/i.exec(line);
          if (n && cur) { if (!aliases.has(cur)) aliases.set(cur, new Set()); aliases.get(cur).add(n[1].toLowerCase()); }
        }
      }
      // имена, которые скрипты передают SetMusic/SetMusicAlarm/PlayStereoOGG; плюс жёсткий путь из главного меню
      const used = new Set();
      const walk = (d) => { for (const e of fs.readdirSync(d, { withFileTypes: true })) {
        const full = path.join(d, e.name);
        if (e.isDirectory()) walk(full);
        else if (/\.(c|h)$/i.test(e.name)) {
          const text = fs.readFileSync(full, 'latin1');
          for (const m of text.matchAll(/(?:SetMusic|SetMusicAlarm|PlayStereoOGG)\(\s*"([^"]+)"/g)) used.add(m[1].toLowerCase());
        } } };
      walk(path.join(gameDir, 'PROGRAM'));
      const reachable = new Set();
      for (const name of used) {
        if (aliases.has(name)) for (const f of aliases.get(name)) reachable.add(f);
        else if (/^music\\.+\.ogg$/.test(name)) reachable.add(name.slice('music\\'.length));
        else if (name.startsWith('music_')) continue;   // опечатка music_abordaz в мёртвой SetSchemeForAbordage (нигде не вызывается)
      }
      const listed = new Set(KNOWN_MUSIC_PATHS.map((p) => p.split('/').pop().toLowerCase()));
      assert.deepEqual([...reachable].sort(), [...listed].sort(), 'список KNOWN_MUSIC_PATHS расходится с алиасами/скриптами игры');
      // все есть на диске (без учёта регистра) и входят в публикуемый набор (файлы без .wav-пары не исключаются правилом exclude_if_sibling)
      const published = [...gameFiles(gameDir).keys()].filter(p => p.toLowerCase().startsWith('resource/sounds/music/')).map(p => p.toLowerCase());
      for (const p of KNOWN_MUSIC_PATHS) assert.ok(published.includes(p.toLowerCase()), `${p} не публикуется`);
      assert.equal(published.length, 37, 'в публикуемом наборе все 37 музыкальных файлов');
    });
  } else console.log('- каталог игры не найден: сверка музыки с алиасами пропущена');

  // ================================================================ английский слой (E5): preflightOverlay / checkOverlayBeforeRun
  const LISTS = JSON.parse(fs.readFileSync(path.join(webDir, 'overlay-required.json'), 'utf8'));
  const OV_LANG_EN = Buffer.from('; ini file for language information\r\n[COMMON]\r\ndefaultLanguage\t= English\r\n;defaultLanguage\t= russian\r\n\r\n[LANGUAGE]\r\nEnglish\t\t= common.ini\r\n');
  const OV_LANG_RU = Buffer.from('; ini\r\n[COMMON]\r\n;defaultLanguage\t= English\r\ndefaultLanguage\t= russian\r\n[LANGUAGE]\r\nEnglish\t\t= common.ini\r\n');
  const ovContent = (rel) => (rel === LANGUAGE_INI_PATH ? OV_LANG_EN : Buffer.from(`overlay:${rel}:` + 'y'.repeat(30 + rel.length)));
  async function freshOverlay(label, { recommended = LISTS.recommended, baseFiles = LISTS.base_recommended } = {}) {
    const root = mkTmp(label + '-en'), baseRoot = mkTmp(label + '-base');
    const files = [...LISTS.required, ...recommended, 'PROGRAM/DIALOGS/extra_dialog.h'];
    for (const rel of files) { const full = path.join(root, ...rel.split('/')); fs.mkdirSync(path.dirname(full), { recursive: true }); fs.writeFileSync(full, ovContent(rel)); }
    for (const rel of baseFiles) { const full = path.join(baseRoot, ...rel.split('/')); fs.mkdirSync(path.dirname(full), { recursive: true }); fs.writeFileSync(full, `base:${rel}`); }
    const entries = files.map((p) => ({ path: p, size: ovContent(p).length, sha256: sha(ovContent(p)) })).sort((a, b) => (a.path < b.path ? -1 : 1));
    const version = await manifestVersionDigest(entries);
    const run = (extra = {}) => preflightOverlay({ openOverlayDir: open(root), openGameDir: open(baseRoot), files: entries, version, installedVersion: version,
      required: LISTS.required, recommended: LISTS.recommended, baseRecommended: LISTS.base_recommended, ...extra });
    return { root, baseRoot, files, entries, version, run, file: (rel) => path.join(root, ...rel.split('/')), baseFile: (rel) => path.join(baseRoot, ...rel.split('/')) };
  }

  await test('E5: слой на месте и совпадает с манифестом слоя: ok, всё сверено по SHA-256', async () => {
    const t = await freshOverlay('ov-ok');
    const r = await t.run();
    assert.equal(r.status, 'ok', JSON.stringify(r.findings)); assert.equal(r.kind, 'overlay'); assert.equal(r.mode, 'verified'); assert.equal(r.trust.level, 'verified');
    assert.equal(r.counts.fatal, 0); assert.equal(r.counts.warn, 0);
    const need = LISTS.required.length + LISTS.recommended.length + LISTS.base_recommended.length;
    assert.equal(r.counts.planned, need); assert.equal(r.counts.ok, need);
    assert.deepEqual(r.items.filter((i) => i.cls === 'fatal').map((i) => i.path).sort(), [...LISTS.required].sort());
    assert.ok(r.items.filter((i) => i.where === 'overlay').every((i) => i.verified === 'hash'), 'файлы слоя сверены по SHA-256');
    assert.ok(r.items.filter((i) => i.where === 'base').every((i) => i.verified === 'presence'), 'файлы базы: только наличие');
    const d = describeOverlayReport(r); assert.equal(d.block, false); assert.equal(d.level, 'ok'); assert.equal(d.message, '');
    const v = await checkOverlayBeforeRun({ openOverlayDir: open(t.root), openGameDir: open(t.baseRoot), files: t.entries, version: t.version, installedVersion: t.version,
      required: LISTS.required, recommended: LISTS.recommended, baseRecommended: LISTS.base_recommended });
    assert.equal(v.block, false); assert.equal(v.report.status, 'ok');
  });

  await test('E5: нет language.ini слоя — отказ (игра осталась бы русской), русский текст и код', async () => {
    const t = await freshOverlay('ov-nolang');
    fs.rmSync(t.file(LANGUAGE_INI_PATH));
    const r = await t.run();
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, LANGUAGE_INI_PATH).code, CODES.RES_MISSING); assert.equal(findingFor(r, LANGUAGE_INI_PATH).severity, 'fatal');
    const d = describeOverlayReport(r);
    assert.equal(d.block, true); assert.equal(d.code, 'RES_MISSING');
    assert.match(d.message, /Английский слой не прошёл проверку/); assert.match(d.message, /Английский режим не запущен/); assert.match(d.message, /Вернуться к русскому/);
    assert.match(d.message, /русская установка и сохранения не затронуты/);
  });

  await test('E5: language.ini слоя не даёт English — отказ с RES_BAD_CONTENT (в т. ч. при верных размере манифеста и SHA-файла)', async () => {
    const t = await freshOverlay('ov-ru');
    fs.writeFileSync(t.file(LANGUAGE_INI_PATH), OV_LANG_RU);
    // манифест слоя, «собранный» вместе с таким файлом: размер и SHA совпадают — содержимое всё равно не годится
    const entries = t.entries.map((e) => (e.path === LANGUAGE_INI_PATH ? { ...e, size: OV_LANG_RU.length, sha256: sha(OV_LANG_RU) } : e));
    const r = await t.run({ files: entries, version: await manifestVersionDigest(entries), installedVersion: await manifestVersionDigest(entries) });
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, LANGUAGE_INI_PATH).code, CODES.RES_BAD_CONTENT);
    const d = describeOverlayReport(r); assert.equal(d.block, true); assert.match(d.message, /осталась бы русской/); assert.match(d.message, /RES_BAD_CONTENT/);
    // без манифеста (presence-only) содержимое проверяется так же
    const r2 = await t.run({ files: null, version: null });
    assert.equal(r2.mode, 'presence-only'); assert.equal(r2.status, 'blocked'); assert.equal(findingFor(r2, LANGUAGE_INI_PATH).code, CODES.RES_BAD_CONTENT);
  });

  await test('E5: languageIniProblem: таблица (активная строка, комментарии, регистр, пробелы, дубли)', async () => {
    const ok = (s) => assert.equal(languageIniProblem(Buffer.from(s, 'latin1')), null, s);
    const bad = (s, re) => assert.match(languageIniProblem(Buffer.from(s, 'latin1')) ?? 'null', re, s);
    ok('[COMMON]\r\ndefaultLanguage\t= English\r\n'); ok('defaultLanguage=English'); ok('  defaultLanguage =  english  \n'); ok('defaultLanguage = ENGLISH ; comment');
    ok(OV_LANG_EN.toString('latin1'));
    bad('', /нет активной строки/); bad(';defaultLanguage = English\r\n', /нет активной строки/); bad('[COMMON]\r\ndefaultLanguage = russian\r\n', /русской/);
    bad(OV_LANG_RU.toString('latin1'), /русской/); bad('defaultLanguage = English\r\ndefaultLanguage = russian\r\n', /противоречат/);
    ok('defaultLanguage = English\r\ndefaultLanguage = english\r\n');   // повтор той же строки не вредит
    bad('defaultLanguage =\r\n', /пусто/); bad('defaultLanguage = Englishh\r\n', /Englishh/); bad('xdefaultLanguage = English\r\n', /нет активной/);
    assert.ok(LANGUAGE_INI_PATH === 'RESOURCE/INI/TEXTS/language.ini');
  });

  await test('E5: language.ini слоя необычного размера (> 64 КБ) не читается целиком и не годится', async () => {
    const t = await freshOverlay('ov-big');
    const big = Buffer.concat([OV_LANG_EN, Buffer.from(';' + 'x'.repeat(70 * 1024) + '\r\n')]);
    fs.writeFileSync(t.file(LANGUAGE_INI_PATH), big);
    const r = await t.run({ files: null, version: null });
    assert.equal(r.status, 'blocked'); assert.equal(findingFor(r, LANGUAGE_INI_PATH).code, CODES.RES_BAD_CONTENT);
  });

  await test('E5: любой обязательный файл слоя: нет / размер / SHA / каталог вместо файла — отказ; в манифесте нет — отказ по диску', async () => {
    for (const rel of LISTS.required) {
      let t = await freshOverlay('ov-req');
      fs.rmSync(t.file(rel));
      let r = await t.run();
      assert.equal(r.status, 'blocked', rel); assert.equal(findingFor(r, rel).code, CODES.RES_MISSING, rel); assert.equal(findingFor(r, rel).severity, 'fatal');
      t = await freshOverlay('ov-req-size');
      if (rel !== LANGUAGE_INI_PATH) {
        fs.appendFileSync(t.file(rel), 'x');
        r = await t.run();
        assert.equal(r.status, 'blocked', rel); assert.equal(findingFor(r, rel).code, CODES.RES_SIZE_MISMATCH, rel);
        t = await freshOverlay('ov-req-hash');
        const b = fs.readFileSync(t.file(rel)); b[b.length - 1] ^= 1; fs.writeFileSync(t.file(rel), b);
        r = await t.run();
        assert.equal(r.status, 'blocked', rel); assert.equal(findingFor(r, rel).code, CODES.RES_HASH_MISMATCH, rel);
      }
      t = await freshOverlay('ov-req-dir');
      fs.rmSync(t.file(rel)); fs.mkdirSync(t.file(rel));
      r = await t.run();
      assert.equal(r.status, 'blocked', rel); assert.equal(findingFor(r, rel).code, CODES.RES_NOT_FILE, rel);
    }
    assert.ok(['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed', 'content'].every((x) => OVERLAY_BLOCKING.has(x)) && !OVERLAY_BLOCKING.has('ambiguous'));
  });

  await test('E5: каталога слоя нет — отказ; слой есть, а базы нет — только предупреждения', async () => {
    const t = await freshOverlay('ov-nodir');
    const r = await t.run({ openOverlayDir: async () => { throw nfe('no overlay dir'); } });
    assert.equal(r.status, 'blocked'); assert.ok(r.findings.filter((f) => f.severity === 'fatal').every((f) => f.code === 'RES_MISSING'));
    assert.equal(r.counts.fatal, LISTS.required.length);
    const r2 = await t.run({ openGameDir: async () => { throw nfe('no base'); } });
    assert.equal(r2.status, 'warn'); assert.equal(r2.counts.fatal, 0); assert.equal(describeOverlayReport(r2).block, false);
    const r3 = await t.run({ openGameDir: null });   // базы нет вовсе: её файлы не проверяются
    assert.equal(r3.status, 'ok'); assert.equal(r3.counts.planned, LISTS.required.length + LISTS.recommended.length);
  });

  await test('E5: рекомендуемые файлы слоя и нужные английскому файлы базы — только предупреждения, запуск не блокируется', async () => {
    for (const rel of LISTS.recommended) {
      const t = await freshOverlay('ov-rec');
      fs.rmSync(t.file(rel));
      const r = await t.run();
      assert.equal(r.status, 'warn', rel); assert.equal(r.counts.fatal, 0); assert.equal(findingFor(r, rel).severity, 'warn'); assert.equal(findingFor(r, rel).code, CODES.RES_MISSING);
      const d = describeOverlayReport(r); assert.equal(d.block, false); assert.equal(d.level, 'warn'); assert.match(d.message, /Игра будет запущена/);
    }
    for (const rel of LISTS.base_recommended) {
      const t = await freshOverlay('ov-base');
      fs.rmSync(t.baseFile(rel));
      const r = await t.run();
      assert.equal(r.status, 'warn', rel); assert.equal(findingFor(r, rel).severity, 'warn'); assert.equal(findingFor(r, rel).where, 'base');
    }
    // порча (SHA) рекомендуемого файла слоя — предупреждение; размер без манифеста не сверяется
    const t = await freshOverlay('ov-rec-hash');
    const rel = LISTS.recommended[0]; const b = fs.readFileSync(t.file(rel)); b[0] ^= 1; fs.writeFileSync(t.file(rel), b);
    const r = await t.run(); assert.equal(r.status, 'warn'); assert.equal(findingFor(r, rel).code, CODES.RES_HASH_MISMATCH);
  });

  await test('E5: версия слоя на диске не равна версии списка / списка нет — режим presence-only (хеши не сверяются), обязательные файлы проверяются', async () => {
    const t = await freshOverlay('ov-ver');
    const stale = await t.run({ installedVersion: 'ffffffffffff' });
    assert.equal(stale.mode, 'presence-only'); assert.ok(codes(stale).includes(CODES.PF_VERSION_MISMATCH)); assert.equal(stale.counts.fatal, 0);
    fs.appendFileSync(t.file(LISTS.required[1]), 'x');   // другой размер, но манифеста нет: файл есть — не отказ
    assert.equal((await t.run({ installedVersion: 'ffffffffffff' })).counts.fatal, 0);
    fs.rmSync(t.file(LISTS.required[1]));
    assert.equal((await t.run({ installedVersion: 'ffffffffffff' })).status, 'blocked');
    const none = await t.run({ files: null, version: null });
    assert.equal(none.mode, 'presence-only'); assert.equal(none.trust.level, 'absent');
    // несогласованный список (правка записи при старой версии) не используется для размеров и хешей
    const t2 = await freshOverlay('ov-incons');
    const entries = t2.entries.map((e, i) => (i === 0 ? { ...e, sha256: '0'.repeat(64) } : e));
    const r = await t2.run({ files: entries });
    assert.equal(r.trust.level, 'inconsistent'); assert.equal(r.mode, 'presence-only'); assert.equal(r.counts.fatal, 0);
  });

  await test('E5: собственный сбой проверки не блокирует запуск; без openOverlayDir — тоже; русский режим этих функций не вызывает', async () => {
    const v = await checkOverlayBeforeRun({});
    assert.equal(v.block, false); assert.equal(v.level, 'error'); assert.equal(v.code, CODES.PF_INTERNAL); assert.match(v.log[0], /PF_INTERNAL/);
    const t = await freshOverlay('ov-crash');
    const v2 = await checkOverlayBeforeRun({ openOverlayDir: () => { throw new TypeError('boom'); }, files: t.entries, version: t.version, installedVersion: t.version, required: LISTS.required });
    assert.equal(v2.block, true, 'ошибка открытия корня слоя — это «слоя нет», не сбой проверки');   // NotFound-эквивалент: обязательные файлы не найдены
    const v3 = await checkOverlayBeforeRun({ openOverlayDir: open(t.root), sha256: async () => { throw new Error('no crypto'); }, files: t.entries, version: t.version,
      installedVersion: t.version, required: LISTS.required, recommended: LISTS.recommended });
    assert.equal(v3.block, false); assert.ok(codes(v3.report).includes(CODES.PF_NO_HASH));
    await assert.rejects(() => preflightOverlay({}), TypeError);
    // базовая проверка не меняется: тот же ввод, что в первом тесте файла, даёт тот же результат
    const base = await fresh('ov-base-unchanged'); const br = await base.run();
    assert.equal(br.status, 'ok'); assert.equal(br.kind, undefined); assert.equal(describeReport(br).block, false);
  });

  await test('E5: проверка только читает: ни одной записи, слой и база побайтно те же (в т. ч. при отказе)', async () => {
    const t = await freshOverlay('ov-ro');
    fs.writeFileSync(t.file(LANGUAGE_INI_PATH), OV_LANG_RU);   // отказ тоже ничего не пишет
    fs.rmSync(t.file(LISTS.recommended[0]));
    const before = snapshotTree(t.root) + snapshotTree(t.baseRoot);
    const r = await t.run();
    assert.equal(r.status, 'blocked');
    assert.equal(writeLog.length, 0);
    assert.equal(snapshotTree(t.root) + snapshotTree(t.baseRoot), before);
  });

  await test('E5: порт читает списки из overlay-required.json и подключает проверку только в английском режиме, после базовой', async () => {
    const portJs = fs.readFileSync(path.join(webDir, 'port.js'), 'utf8');
    assert.match(portJs, /if \(english && !\(await overlayResourceGate\(\)\)\) return;/);
    assert.ok(portJs.indexOf('if (!(await resourceGate())) return;') < portJs.indexOf('if (english && !(await overlayResourceGate())) return;'));
    assert.match(portJs, /required: O\.OVERLAY_REQUIRED, recommended: O\.OVERLAY_RECOMMENDED, baseRecommended: O\.OVERLAY_BASE_RECOMMENDED/);
    assert.equal(portJs.split('await overlayResourceGate()').length - 1, 1, 'вызывается ровно из run(), и только в английском режиме');
  });
} finally {
  for (const d of created.reverse()) {
    try { for (const p of fs.readdirSync(d)) { /* restore perms best-effort */ } } catch { /* ignore */ }
    fs.rmSync(d, { recursive: true, force: true });
  }
}
console.log(`missing-resource-preflight (page module): ${passed} test groups PASS`);
