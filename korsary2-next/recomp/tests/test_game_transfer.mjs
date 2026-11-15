/* D1: загрузка сжатых (gzip) игровых файлов — web/game-transfer.mjs и связанные места save-protection.mjs.
   Без сети и без браузера: настоящий DecompressionStream/TransformStream/Response из Node, хранилище
   (с семантикой OPFS: запись видна только после close, abort отбрасывает её) и сервер — синтетические.

   Доказывается: round-trip с многими мелкими чанками без удержания файла целиком; проверка размера и
   SHA-256 ПОСЛЕ распаковки (несовпадение — отказ, файл не остаётся ни «принятым», ни докачиваемым);
   усечённый и повреждённый поток; неверные size/csize; обрыв сети посреди файла и повтор через настоящий
   syncManifestFiles (сжатый файл начинается с нуля, прогресс не расходится); смешанный и старый
   манифесты; незнакомое кодирование отвергается; квота считается по распакованному размеру.
     node tests/test_game_transfer.mjs */
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { gzipSync } from 'node:zlib';
import { downloadPackedFile, entryEncoding, remotePath, transferSize, unsupportedEncodings,
  TransferIntegrityError } from '../web/game-transfer.mjs';
import { checkStorageForSync, planFileUpdate, planStorageNeed, sha256Hex, sha256Init, sha256Update,
  syncManifestFiles, validateManifestFiles } from '../web/save-protection.mjs';

const sha = (b) => createHash('sha256').update(b).digest('hex');
const missing = () => Object.assign(new Error('missing'), { name: 'NotFoundError' });
const quotaError = () => Object.assign(new Error('The quota has been exceeded.'), { name: 'QuotaExceededError' });
const concat = (parts) => { const o = new Uint8Array(parts.reduce((n, p) => n + p.length, 0)); let k = 0; for (const p of parts) { o.set(p, k); k += p.length; } return o; };
const pseudo = (n, seed = 7) => { const o = new Uint8Array(n); let x = seed; for (let i = 0; i < n; i++) { x = (x * 1103515245 + 12345) >>> 0; o[i] = (x >>> 16) % 23 === 0 ? x >>> 24 : 65 + (i % 7); } return o; };

/* ---- хранилище как OPFS: createWritable пишет в «своп», close фиксирует, abort отбрасывает */
class Dir {
  dirs = new Map(); files = new Map(); stats = { writes: 0, commits: 0, aborts: 0, maxChunk: 0, removed: [] };
  async getDirectoryHandle(name, { create } = {}) {
    if (!this.dirs.has(name)) { if (!create) throw missing(); this.dirs.set(name, new Dir()); this.dirs.get(name).stats = this.stats; }
    return this.dirs.get(name);
  }
  async getFileHandle(name, { create } = {}) {
    if (!this.files.has(name)) { if (!create) throw missing(); this.files.set(name, { data: new Uint8Array() }); }
    const record = this.files.get(name), stats = this.stats;
    return { kind: 'file', async getFile() { return new Blob([record.data.slice()]); },
      async createWritable() {
        const parts = [];
        return { async write(v) { stats.writes++; stats.maxChunk = Math.max(stats.maxChunk, v.length); parts.push(v.slice()); },
          async close() { stats.commits++; record.data = concat(parts); },
          async abort() { stats.aborts++; } };
      } };
  }
  async removeEntry(n) { if (!this.files.delete(n)) throw missing(); this.stats.removed.push(n); }
}
async function put(dir, rel, data) {
  const parts = rel.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create: true });
  (await dir.getFileHandle(parts.at(-1), { create: true }));
  dir.files.get(parts.at(-1)).data = data;
}
async function read(dir, rel) {
  const parts = rel.split('/');
  try { for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p); } catch { return null; }
  return dir.files.has(parts.at(-1)) ? dir.files.get(parts.at(-1)).data : null;
}
const existingSize = async (dir, rel) => { const d = await read(dir, rel); return d ? d.length : -1; };

/* ---- «сервер»: путь -> байты; чанки заданного размера; обрыв после n байт */
function server(objects, { chunk = 1000, cutAfter = null, headers = {}, cutOnce = true } = {}) {
  const log = [];
  let cuts = 0;
  const fetchImpl = async (url, init) => {
    const key = decodeURIComponent(new URL(url).pathname.replace(/^\/game\//, ''));
    log.push({ key, range: init?.headers?.Range ?? null });
    const body = objects[key];
    if (!body) return new Response('nope', { status: 404 });
    let off = 0, sent = 0;
    const doCut = cutAfter !== null && (!cutOnce || cuts === 0);
    if (doCut) cuts++;
    const stream = new ReadableStream({
      pull(ctl) {
        if (doCut && sent >= cutAfter) { ctl.error(new TypeError('network error (cut)')); return; }
        if (off >= body.length) { ctl.close(); return; }
        const n = Math.min(chunk, body.length - off, doCut ? Math.max(1, cutAfter - sent) : Infinity);
        ctl.enqueue(body.slice(off, off + n)); off += n; sent += n;
      },
    });
    return new Response(stream, { status: 200, headers });
  };
  fetchImpl.log = log;
  return fetchImpl;
}

const packedEntry = (path, content, extra = {}) => {
  const gz = gzipSync(content, { level: 6 });
  return { entry: { path, size: content.length, sha256: sha(content), enc: 'gzip', csize: gz.length, ...extra }, gz };
};

async function fh(dir, rel) {
  const parts = rel.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create: true });
  return dir.getFileHandle(parts.at(-1), { create: true });
}
async function rm(dir, rel) {
  const parts = rel.split('/');
  try { for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p); await dir.removeEntry(parts.at(-1)); } catch { /* absent */ }
}
// the same wiring as port.js downloadFile: a fresh writable (old data stays until close), discard = removeEntry
async function one({ entry, gz, fetchImpl, dir = new Dir(), onBytes = () => {} }) {
  return downloadPackedFile({ entry, url: 'http://t/game/' + remotePath(entry), fetchImpl: fetchImpl || server({ [remotePath(entry)]: gz }), onBytes,
    openWritable: async () => (await fh(dir, entry.path)).createWritable(),
    discard: () => rm(dir, entry.path) });
}

let n = 0;
const ok = (name) => { n++; console.log('ok - ' + name); };

/* 1. helpers: encodings, remote name, transfer size, capability */
assert.equal(entryEncoding({ path: 'a' }), null);
assert.equal(entryEncoding({ path: 'a', enc: 'identity' }), null);
assert.equal(entryEncoding({ path: 'a', enc: 'gzip' }), 'gzip');
assert.equal(entryEncoding({ path: 'a', enc: 'br' }), 'br');          // D1b: brotli известен (WebAssembly-декодер)
assert.throws(() => entryEncoding({ path: 'a', enc: 'zstd' }), /неподдерживаемое кодирование/);
assert.throws(() => entryEncoding({ path: 'a', enc: 'brotli' }), /обновите страницу/);
assert.equal(remotePath({ path: 'RESOURCE/x y.tx', enc: 'gzip' }), 'RESOURCE/x y.tx.gz');
assert.equal(remotePath({ path: 'RESOURCE/x.tx' }), 'RESOURCE/x.tx');
assert.equal(transferSize({ path: 'a', size: 100, enc: 'gzip', csize: 40 }), 40);
assert.equal(transferSize({ path: 'a', size: 100, enc: 'gzip' }), 100);
assert.equal(transferSize({ path: 'a', size: 100 }), 100);
assert.deepEqual(unsupportedEncodings([{ path: 'a', size: 1 }]), []);
assert.deepEqual(unsupportedEncodings([{ path: 'a', size: 1, enc: 'gzip' }]), []);       // настоящий DecompressionStream
assert.deepEqual(unsupportedEncodings([{ path: 'a', size: 1, enc: 'gzip' }], undefined), []);
assert.deepEqual(unsupportedEncodings([{ path: 'a', size: 1, enc: 'gzip' }], null), ['gzip']);   // браузер без API
assert.deepEqual(unsupportedEncodings([{ path: 'a', size: 1, enc: 'gzip' }], class { constructor() { throw new TypeError('x'); } }), ['gzip']);
ok('кодирования, имя на сервере, размер передачи, проверка поддержки браузером');

/* 1b. SHA-256 страницы (ускоренный sha256Update) равен crypto при любой нарезке на чанки */
{
  let seed = 3; const rnd = (m) => { seed = (seed * 1103515245 + 12345) >>> 0; return (seed >>> 8) % m; };
  for (const len of [0, 1, 55, 56, 63, 64, 65, 119, 120, 127, 128, 129, 1000, 70_001]) {
    const data = pseudo(len, len + 1);
    for (const mode of ['whole', 'bytes', 'random']) {
      const st = sha256Init();
      if (mode === 'whole') sha256Update(st, data);
      else for (let off = 0; off < len;) { const k = mode === 'bytes' ? 1 : 1 + rnd(150); const piece = data.slice(off, off + k); sha256Update(st, piece); piece.fill(0xEE); off += k; }
      assert.equal(sha256Hex(st), sha(data), `len=${len} ${mode}`);
    }
  }
  ok('SHA-256 страницы совпадает с crypto для разных длин и нарезок (буфер вызывающего можно переиспользовать)');
}

/* 2. round-trip: много чанков, запись по чанкам, файл целиком не накапливается */
{
  const content = pseudo(3_000_000);
  const p = packedEntry('RESOURCE/Textures/big.tx', content);
  assert.ok(p.gz.length < content.length * 0.8, 'фикстура должна сжиматься');
  const dir = new Dir(); const progress = [];
  await one({ ...p, dir, fetchImpl: server({ [remotePath(p.entry)]: p.gz }, { chunk: 777 }), onBytes: (b) => progress.push(b) });
  const got = await read(dir, p.entry.path);
  assert.deepEqual(got, content);
  assert.equal(progress.reduce((a, b) => a + b, 0), content.length, 'прогресс в распакованных байтах');
  assert.ok(dir.stats.writes > 10, 'запись идёт чанками');
  assert.ok(dir.stats.maxChunk < content.length / 4, `чанк ${dir.stats.maxChunk} не должен быть почти всем файлом`);
  assert.equal(dir.stats.commits, 1); assert.equal(dir.stats.aborts, 0);
  ok('round-trip 3 МБ: распаковка потоком, чанки, прогресс = распакованный размер');
}

/* 3. пустой и маленький файлы */
{
  for (const content of [new Uint8Array(0), new Uint8Array([1, 2, 3])]) {
    const p = packedEntry('x/small.bin', content); const dir = new Dir();
    await one({ ...p, dir });
    assert.deepEqual(await read(dir, 'x/small.bin'), content);
  }
  ok('пустой и крошечный файлы');
}

/* 4. SHA-256 после распаковки не совпал: отказ, файл не остаётся, старый тоже убран */
{
  const content = pseudo(50_000), other = pseudo(50_000, 99);
  const p = packedEntry('RESOURCE/a.gm', content, { sha256: sha(other) });   // манифест врёт про содержимое
  const dir = new Dir(); await put(dir, 'RESOURCE/a.gm', pseudo(10, 1));       // был старый файл
  await assert.rejects(one({ ...p, dir }), (e) => e instanceof TransferIntegrityError && /SHA-256 после распаковки/.test(e.message));
  assert.equal(await read(dir, 'RESOURCE/a.gm'), null, 'файл с неверным содержимым не должен остаться');
  assert.equal(dir.stats.commits, 0, 'запись не зафиксирована'); assert.ok(dir.stats.aborts >= 1);
  ok('несовпадение SHA после распаковки: abort, файл удалён, close не вызывался');
}

/* 5. усечённый поток */
{
  const content = pseudo(200_000); const p = packedEntry('t/trunc.tx', content);
  for (const cut of [5, Math.floor(p.gz.length / 2), p.gz.length - 1, p.gz.length - 8]) {
    const dir = new Dir();
    await assert.rejects(one({ entry: p.entry, gz: p.gz.slice(0, cut), dir }), Error, `усечение на ${cut}`);
    assert.equal(await read(dir, 'x'), null);
    assert.equal(await read(dir, 't/trunc.tx'), null, 'после усечённого потока файла нет');
    assert.equal(dir.stats.commits, 0);
  }
  // csize не задан в манифесте (как у serve.py): усечение всё равно ловится распаковщиком/размером
  const noCsize = { ...p.entry }; delete noCsize.csize;
  await assert.rejects(one({ entry: noCsize, gz: p.gz.slice(0, p.gz.length - 20), dir: new Dir() }));
  ok('усечённый поток: отказ, файл не остаётся (с csize и без него)');
}

/* 6. повреждённый поток */
{
  const content = pseudo(200_000); const p = packedEntry('t/bad.tx', content);
  const bad = p.gz.slice(); bad[Math.floor(bad.length / 2)] ^= 0xff; bad[bad.length - 6] ^= 0x01;
  const dir = new Dir();
  await assert.rejects(one({ entry: p.entry, gz: bad, dir }));
  assert.equal(await read(dir, 't/bad.tx'), null); assert.equal(dir.stats.commits, 0);
  // не gzip вообще (например, страница ошибки со статусом 200)
  const dir2 = new Dir();
  await assert.rejects(one({ entry: p.entry, gz: new TextEncoder().encode('<html>login</html>'.repeat(50)), dir: dir2 }));
  assert.equal(await read(dir2, 't/bad.tx'), null);
  ok('повреждённый поток и не-gzip ответ: отказ, файл не остаётся');
}

/* 7. неверные size/csize в манифесте, мусор после потока */
{
  const content = pseudo(100_000); const p = packedEntry('t/m.tx', content);
  const cases = [
    ['size меньше фактического', { ...p.entry, size: content.length - 1 }, p.gz, /длиннее манифеста/],
    ['size больше фактического', { ...p.entry, size: content.length + 1 }, p.gz, /после распаковки/],
    ['csize меньше фактического', { ...p.entry, csize: p.gz.length - 1 }, p.gz, /сжатый поток длиннее/],
    ['csize больше фактического', { ...p.entry, csize: p.gz.length + 1 }, p.gz, /сжатый поток короче/],
    ['мусор после gzip (csize известен)', p.entry, concat([p.gz, new Uint8Array([1, 2, 3, 4])]), /длиннее манифеста|Error|error/i],
  ];
  for (const [name, entry, gz, re] of cases) {
    const dir = new Dir();
    await assert.rejects(one({ entry, gz, dir }), re, name);
    assert.equal(await read(dir, 't/m.tx'), null, name); assert.equal(dir.stats.commits, 0, name);
  }
  ok('неверные size/csize и хвост после потока: отказ без принятого файла');
}

/* 8. HTTP-ошибка, ответ без SHA в манифесте, незнакомое кодирование, хост уже распаковал */
{
  const content = pseudo(30_000); const p = packedEntry('t/h.tx', content);
  const dir = new Dir();
  await assert.rejects(one({ entry: p.entry, fetchImpl: server({}), dir }), /HTTP 404/);
  assert.equal(await read(dir, 't/h.tx'), null, 'при 404 хранилище не трогается');
  assert.equal(dir.stats.writes, 0);
  await assert.rejects(one({ entry: { ...p.entry, sha256: undefined }, gz: p.gz, dir }), /нет SHA-256/);
  await assert.rejects(one({ entry: { ...p.entry, enc: 'zstd' }, gz: p.gz, dir }), /неподдерживаемое/);
  // хост/прокси добавил Content-Encoding к .gz: fetch уже распаковал, приходят обычные байты
  const dir2 = new Dir();
  await one({ entry: p.entry, fetchImpl: server({ 't/h.tx.gz': content }, { headers: { 'Content-Encoding': 'gzip' } }), dir: dir2 });
  assert.deepEqual(await read(dir2, 't/h.tx'), content);
  // ...но если и после этого содержимое не то — отказ
  const dir3 = new Dir();
  await assert.rejects(one({ entry: p.entry, fetchImpl: server({ 't/h.tx.gz': pseudo(30_000, 5) }, { headers: { 'Content-Encoding': 'gzip' } }), dir: dir3 }), /SHA-256/);
  ok('HTTP 404, нет SHA, незнакомое кодирование, хост сам распаковал (проверка SHA остаётся)');
}

/* 9. обрыв сети посреди файла и повтор через настоящий syncManifestFiles; возобновление установки */
function syncHarness({ dir, manifest, fetchImpl, hadMarker = false, rawDownloads = [] }) {
  const ctx = { marker: null, sleeps: [], progress: [], calls: [] };
  ctx.run = () => syncManifestFiles({
    dir, files: manifest.files, hadMarker, version: manifest.version, existingSize,
    async downloadFile(d, path, size, from, onBytes, entry) {
      ctx.calls.push({ path, from, packed: !!entry?.enc });
      if (entry?.enc) {
        if (from > 0) onBytes(-from);
        return downloadPackedFile({ entry, url: 'http://t/game/' + remotePath(entry), fetchImpl, onBytes,
          openWritable: async () => (await fh(d, path)).createWritable(),
          discard: () => rm(d, path) });
      }
      // обычный файл: как port.js — Range для докачки
      const body = rawDownloads[path]; assert.ok(body, 'нет тела для ' + path);
      const prev = (await read(d, path)) || new Uint8Array();
      const w = await (await fh(d, path)).createWritable();
      await w.write(from > 0 ? concat([prev.slice(0, from), body.slice(from)]) : body); await w.close(); onBytes(size - from);
    },
    async downloadOptionsFile() { throw new Error('options не ожидается'); },
    async writeMarker(v) { ctx.marker = { version: v }; },
    show(done) { ctx.progress.push(done); },
    async sleep(ms, path, err) { ctx.sleeps.push([ms, path, err.message]); },
  });
  return ctx;
}
{
  const a = pseudo(400_000, 1), b = pseudo(300_000, 2), plain = pseudo(5_000, 3);
  const pa = packedEntry('RESOURCE/Textures/a.tx', a), pb = packedEntry('RESOURCE/Models/b.gm', b);
  const rawEntry = { path: 'engine.ini', size: plain.length, sha256: sha(plain) };       // без enc: как раньше
  const manifest = { version: 'v1', files: [pa.entry, pb.entry, rawEntry] };
  const objects = { [remotePath(pa.entry)]: pa.gz, [remotePath(pb.entry)]: pb.gz };
  // обрыв после 1/3 первого файла, один раз
  const dir = new Dir();
  const fetchImpl = server(objects, { chunk: 5000, cutAfter: Math.floor(pa.gz.length / 3) });
  const h = syncHarness({ dir, manifest, fetchImpl, rawDownloads: { 'engine.ini': plain } });
  await h.run();
  assert.deepEqual(await read(dir, pa.entry.path), a); assert.deepEqual(await read(dir, pb.entry.path), b);
  assert.deepEqual(await read(dir, 'engine.ini'), plain);
  assert.equal(h.sleeps.length, 1, 'ровно один повтор после обрыва'); assert.match(h.sleeps[0][2], /network error/);
  assert.equal(h.marker.version, 'v1');
  const total = a.length + b.length + plain.length;
  assert.equal(h.progress.at(-1), total, 'прогресс заканчивается на сумме РАСПАКОВАННЫХ размеров');
  assert.ok(h.progress.every((v) => v <= total), 'прогресс не превышает итог даже после повтора');
  assert.deepEqual(h.calls.filter((c) => c.path === pa.entry.path).map((c) => c.from), [0, 0], 'сжатый файл повторяется с нуля');
  assert.equal(dir.stats.commits, 3); assert.ok(dir.stats.aborts >= 1);
  ok('обрыв сети посреди сжатого файла: повтор с нуля, итог верный, прогресс согласован');

  // установка прервана ПОСЛЕ первого файла (процесс убит): второй запуск не качает готовый файл заново
  const dir2 = new Dir();
  await put(dir2, pa.entry.path, a);                                   // первый файл уже на месте и верен
  await put(dir2, pb.entry.path, b.slice(0, 1234));                    // второй — «частичный» (по размеру)
  const f2 = server(objects);
  const h2 = syncHarness({ dir: dir2, manifest, fetchImpl: f2, rawDownloads: { 'engine.ini': plain } });
  await h2.run();
  assert.deepEqual(h2.calls.map((c) => c.path), [pb.entry.path, 'engine.ini'], 'установленный верный файл пропущен после проверки SHA');
  assert.equal(h2.calls[0].from, 0, 'частичный СЖАТЫЙ файл начинается с нуля, а не «докачивается»');
  assert.deepEqual(f2.log.map((l) => l.range), [null], 'Range для сжатого объекта не запрашивается');
  assert.deepEqual(await read(dir2, pb.entry.path), b);
  ok('возобновление: готовый файл пропущен, частичный сжатый перекачан с нуля без Range');

  // тот же размер, другое содержимое (порча на диске): verify -> перекачка
  const dir3 = new Dir();
  const broken = a.slice(); broken[10] ^= 1;
  await put(dir3, pa.entry.path, broken);
  const h3 = syncHarness({ dir: dir3, manifest: { version: 'v1', files: [pa.entry] }, fetchImpl: server(objects) });
  await h3.run();
  assert.deepEqual(await read(dir3, pa.entry.path), a); assert.equal(h3.calls.length, 1);
  ok('файл той же длины, но с испорченным содержимым, скачивается заново');

  // повреждение на сервере: все 4 попытки неудачны, файла нет, метка установки не ставится
  const dir4 = new Dir();
  const bad = pa.gz.slice(); bad[bad.length >> 1] ^= 0xff;
  const h4 = syncHarness({ dir: dir4, manifest: { version: 'v1', files: [pa.entry] }, fetchImpl: server({ [remotePath(pa.entry)]: bad }) });
  await assert.rejects(h4.run());
  assert.equal(h4.sleeps.length, 3, '4 попытки'); assert.equal(h4.marker, null, 'метка установки не поставлена');
  assert.equal(await read(dir4, pa.entry.path), null);
  ok('постоянная порча на сервере: 4 попытки, файла нет, метка не поставлена');
}

/* 10. обычная (несжатая) докачка сохранена: частичный файл без enc — resume с Range */
{
  assert.equal(planFileUpdate(10, 100, false), 'resume');
  assert.equal(planFileUpdate(10, 100, false, false), 'resume');
  assert.equal(planFileUpdate(10, 100, false, true), 'rewrite');
  assert.equal(planFileUpdate(100, 100, false, true), 'verify');
  assert.equal(planFileUpdate(10, 100, true, false), 'rewrite');
  const plain = pseudo(5000, 3);
  const dir = new Dir(); await put(dir, 'engine.ini', plain.slice(0, 1000));
  const h = syncHarness({ dir, manifest: { version: 'v', files: [{ path: 'engine.ini', size: plain.length, sha256: sha(plain) }] }, fetchImpl: null, rawDownloads: { 'engine.ini': plain } });
  await h.run();
  assert.equal(h.calls[0].from, 1000); assert.deepEqual(await read(dir, 'engine.ini'), plain);
  ok('несжатый файл докачивается с середины, как раньше');
}

/* 11. манифест: старый (без enc), смешанный, неверные поля */
{
  const old = [{ path: 'a/b.tx', size: 3, sha256: sha(new Uint8Array(3)) }, { path: 'engine.ini', size: 1, sha256: sha(new Uint8Array(1)) }];
  assert.deepEqual(validateManifestFiles(old), old, 'старый манифест (без enc, но с SHA) проходит без изменений');
  assert.throws(() => validateManifestFiles([...old, { path: 'x.bin', size: 1 }]), /x\.bin: в манифесте нет SHA-256/, 'N11: несжатая запись без sha256 отвергается');
  const mixed = [{ path: 'a/b.tx', size: 3, sha256: sha(new Uint8Array(3)), enc: 'gzip', csize: 23 },
    { path: 'c.ogg', size: 9, sha256: sha(new Uint8Array(9)) }, { path: 'd.wav', size: 9, sha256: sha(new Uint8Array(9)), enc: 'identity' }];
  assert.equal(validateManifestFiles(mixed).length, 3);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 1, sha256: 'x'.repeat(64), enc: 'zstd' }]), /неподдерживаемое кодирование/);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 1, sha256: sha(new Uint8Array(1)), enc: 'gzip', csize: -1 }]), /размер сжатого/);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 1, sha256: sha(new Uint8Array(1)), enc: 'gzip', csize: 1.5 }]), /размер сжатого/);
  assert.throws(() => validateManifestFiles([{ path: 'a', size: 1, enc: 'gzip' }]), /нет SHA-256/);
  assert.throws(() => validateManifestFiles([{ path: 'options', size: 1, sha256: sha(new Uint8Array(1)), enc: 'gzip' }]), /настроек/);
  // сводные проверки двух мест согласованы
  for (const enc of [undefined, null, '', 'identity', 'gzip', 'br', 'zstd', 5, {}]) {
    let a = 'ok', b = 'ok';
    try { entryEncoding({ path: 'p', enc }); } catch { a = 'throw'; }
    try { validateManifestFiles([{ path: 'p', size: 1, sha256: sha(new Uint8Array(1)), enc }]); } catch { b = 'throw'; }
    assert.equal(a, b, `entryEncoding и validateManifestFiles расходятся для enc=${JSON.stringify(enc)}`);
  }
  ok('манифесты: старый, смешанный, неверные enc/csize/sha, согласованность проверок');
}

/* 12. квота: считается по распакованному размеру, трафик — по csize */
{
  const mk = (path, size, csize) => ({ path, size, sha256: sha(new Uint8Array(1)), enc: 'gzip', csize });
  const files = [mk('RESOURCE/a.tx', 600_000_000, 300_000_000), mk('RESOURCE/b.gm', 400_000_000, 140_000_000),
    { path: 'RESOURCE/c.ogg', size: 50_000_000, sha256: sha(new Uint8Array(2)) }];
  const plan = planStorageNeed({ files, haveSizes: new Map(), hadMarker: false });
  assert.equal(plan.writeBytes, 1_050_000_000, 'на диск идёт распакованный размер');
  assert.equal(plan.growthBytes, 1_050_000_000);
  assert.equal(plan.transferBytes, 300_000_000 + 140_000_000 + 50_000_000, 'по сети — csize');
  // места хватило бы на сжатый объём, но не на распакованный: отказ
  const est = { quota: 600_000_000, usage: 0 };
  const res = await checkStorageForSync({ dir: null, files, hadMarker: false, existingSize, estimate: async () => est });
  assert.equal(res.status, 'insufficient');
  assert.match(res.message, /по сети около 490 МБ/);
  const enough = await checkStorageForSync({ dir: null, files, hadMarker: false, existingSize, estimate: async () => ({ quota: 5e9, usage: 0 }) });
  assert.equal(enough.status, 'ok');
  // сжатый файл с частичной копией и без метки: resume не планируется, пишется целиком
  const part = planStorageNeed({ files: [files[0]], haveSizes: new Map([['RESOURCE/a.tx', 1000]]), hadMarker: false });
  assert.equal(part.toResume, 0); assert.equal(part.toDownload, 1); assert.equal(part.writeBytes, 600_000_000);
  // манифест без enc: поля как раньше, transferBytes = writeBytes
  const oldPlan = planStorageNeed({ files: [{ path: 'x', size: 1000, sha256: sha(new Uint8Array(1)) }], haveSizes: new Map() });
  assert.equal(oldPlan.transferBytes, 1000);
  ok('квота по распакованному размеру; сеть по csize; частичный сжатый файл не «докачивается»');
}

console.log(`game-transfer: ${n} групп проверок PASS`);
