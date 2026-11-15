/* Обновление (resync) установленной игры при новой версии манифеста — сохранность данных игрока
   на синтетической OPFS-фикстуре (в памяти; настоящий OPFS, браузерная квота и сеть здесь НЕ
   участвуют). Используются настоящие updateUnderSaveLock / syncManifestFiles /
   backupSavesBeforeUpdateLocked; подменены только хранилище, загрузка и оценка квоты.

   Что доказано: слоты SAVE, SAVE_META и изменённый игроком options не меняются при обновлении,
   а файлы манифеста про SAVE игнорируются; перед обновлением создаётся резервная копия; при
   нехватке места (квота) во время загрузки или записи резервной копии сохранения остаются
   нетронутыми, метка установки не продвигается, а повторный запуск после освобождения места
   достраивает установку; «лишние» файлы вне манифеста (в т.ч. исходные RESOURCE/VIDEOS/*.wmv)
   не удаляются. Оценка места проверяется на тех же фикстурах через checkStorageForSync (сама
   проверка вызывается из port.js syncFromServer; сама страница и настоящая квота браузера здесь НЕ
   участвуют, см. docs/hosting.md и test_storage_estimate.mjs). */
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { decodeBackup } from '../web/save-export.mjs';
import { checkStorageForSync, syncManifestFiles, updateUnderSaveLock } from '../web/save-protection.mjs';

const missing = () => Object.assign(new Error('missing'), { name: 'NotFoundError' });
const quotaError = () => Object.assign(new Error('The quota has been exceeded.'), { name: 'QuotaExceededError' });
const bytes = (s) => new TextEncoder().encode(s);
const text = (b) => new TextDecoder().decode(b);
const sha = (b) => createHash('sha256').update(b).digest('hex');
const entry = (path, data) => ({ path, size: data.length, sha256: sha(data) });

class Dir {
  dirs = new Map(); files = new Map();
  async getDirectoryHandle(name, { create } = {}) {
    if (!this.dirs.has(name)) { if (!create) throw missing(); this.dirs.set(name, new Dir()); }
    return this.dirs.get(name);
  }
  async getFileHandle(name, { create } = {}) {
    if (!this.files.has(name)) { if (!create) throw missing(); this.files.set(name, { data: new Uint8Array() }); }
    const record = this.files.get(name);
    return { kind: 'file', async getFile() { return new Blob([record.data.slice()]); },
      async createWritable() { let data; return { async write(v) { data = v.slice(); }, async close() { record.data = data; } }; } };
  }
  async *entries() {
    for (const n of this.files.keys()) yield [n, await this.getFileHandle(n)];
    for (const [n, d] of this.dirs) yield [n, Object.assign(d, { kind: 'directory' })];
  }
  async removeEntry(n) { if (!this.files.delete(n)) throw missing(); }
}

async function resolve(dir, rel, create) {
  const parts = rel.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create });
  return [dir, parts.at(-1)];
}

/* Хранилище с ограниченным местом: put пишет не больше свободного, затем бросает QuotaExceededError
   (как запись в OPFS: часть данных уже на диске). */
function storage(free) {
  const s = { free, used: 0 };
  s.put = async (dir, rel, data) => {
    const [d, name] = await resolve(dir, rel, true);
    const fh = await d.getFileHandle(name, { create: true });
    const room = Math.max(0, s.free);
    const take = Math.min(room, data.length);
    s.free -= take;
    const w = await fh.createWritable();
    await w.write(data.slice(0, take)); await w.close();
    if (take < data.length) throw quotaError();
  };
  return s;
}

function harness({ free = Infinity, version }) {
  const root = new Dir();
  const st = storage(free);
  const locks = { async request(_n, _o, fn) { return fn({ name: 'lock' }); } };
  const ctx = { root, locks, st, marker: null, downloads: [], sleeps: [], progress: [], rootName: 'test-game' };
  ctx.game = null;
  ctx.update = async (manifest, payloads, extra = {}) => updateUnderSaveLock({
    root, locks, rootName: ctx.rootName, version: manifest.version, readMarker: async () => ctx.marker,
    sync: () => syncManifestFiles({
      dir: ctx.game, files: manifest.files, hadMarker: !!ctx.marker?.version, version: manifest.version,
      existingSize: async (dir, path) => {
        try { const [d, n] = await resolve(dir, path, false); return (await (await d.getFileHandle(n)).getFile()).size; }
        catch { return -1; }
      },
      async downloadFile(dir, path, size, from, onBytes) {
        ctx.downloads.push(path);
        const data = payloads[path];
        assert.ok(data, `нет полезной нагрузки для ${path}`);
        assert.equal(data.length, size);
        await st.put(dir, path, data);
        onBytes(size);
      },
      async downloadOptionsFile(dir, e, onBytes) {
        ctx.downloads.push('options');
        await st.put(dir, 'options', payloads.options); onBytes(e.size);
      },
      async writeMarker(v) { ctx.marker = { version: v }; },
      show(done) { ctx.progress.push(done); },
      async sleep(ms, path, err) { ctx.sleeps.push([ms, path, err.name]); },
    }),
    ...extra,
  });
  return ctx;
}

async function installedGame(h, files) {
  h.game = await h.root.getDirectoryHandle(h.rootName, { create: true });
  for (const [rel, data] of Object.entries(files)) await storage(Infinity).put(h.game, rel, data);
  const save = await h.game.getDirectoryHandle('SAVE', { create: true });
  save.files.set('slot1', { data: bytes('slot one progress') });
  save.files.set('slot2', { data: bytes('slot two progress') });
  const meta = await h.game.getDirectoryHandle('SAVE_META', { create: true });
  meta.files.set('slot1.time', { data: new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]) });
  return { save, meta };
}

const snapshot = (dir) => JSON.stringify([...dir.files].map(([n, r]) => [n, [...r.data]]));

const v1src = { 'ENGINE.exe': bytes('engine v1'), 'PROGRAM/a.c': bytes('script one'), options: bytes('default options') };
const v2src = { 'ENGINE.exe': bytes('engine v2 is longer'), 'PROGRAM/a.c': bytes('script one'), 'PROGRAM/new.c': bytes('brand new script'),
  options: bytes('default options') };
const manifestOf = (version, src, extra = []) => ({ version, files: [...Object.entries(src).map(([p, d]) => entry(p, d)), ...extra] });

/* ---------- 1. обычное обновление ---------- */
{
  const h = harness({});
  const { save, meta } = await installedGame(h, v1src);
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });          // игрок менял настройки
  await storage(Infinity).put(h.game, 'PROGRAM/stale-from-v0.c', bytes('left over'));   // файл, которого нет в новом манифесте
  h.marker = { version: 'v1' };
  const saveBefore = snapshot(save), metaBefore = snapshot(meta);
  // сервер (по ошибке или злонамеренно) перечисляет и слот сохранения, и SAVE_META: их страница не принимает
  const hostile = [entry('SAVE/slot1', bytes('OVERWRITE')), entry('save_meta/slot1.time', bytes('x')), entry('sAvE/slot3', bytes('y'))];
  const result = await h.update(manifestOf('v2', v2src, hostile), { ...v2src, 'SAVE/slot1': bytes('OVERWRITE'), 'save_meta/slot1.time': bytes('x'), 'sAvE/slot3': bytes('y') });
  assert.ok(result.backup?.backup, 'резервная копия перед обновлением создана');
  assert.equal(snapshot(save), saveBefore, 'слоты SAVE не тронуты');
  assert.equal(snapshot(meta), metaBefore, 'SAVE_META не тронут');
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS', 'options игрока сохранён');
  assert.equal(text(h.game.files.get('ENGINE.exe').data), 'engine v2 is longer', 'изменённый файл заменён целиком');
  assert.equal(text((await resolve(h.game, 'PROGRAM/new.c'))[0].files.get('new.c').data), 'brand new script');
  assert.ok(!h.downloads.includes('options'), 'options не скачивался повторно');
  assert.ok(!h.downloads.some((p) => /^save/i.test(p)), 'файлы SAVE/SAVE_META манифеста не скачивались');
  assert.equal(h.game.dirs.get('PROGRAM').files.has('stale-from-v0.c'), true, 'лишние старые файлы не удаляются (оговорка в docs/hosting.md)');
  assert.deepEqual(h.marker, { version: 'v2' });
  const backups = await h.root.getDirectoryHandle('test-game-backups');
  const archive = decodeBackup(backups.files.get(result.backup.backup).data);
  assert.deepEqual(archive.entries.map((e) => e.name).sort().filter((n) => !/\.time$/i.test(n)), ['slot1', 'slot2']);
  // повторный запуск той же версии — ничего не делает
  assert.deepEqual(await h.update(manifestOf('v2', v2src), v2src), { skipped: 'current' });
}

/* ---------- 2. нехватка места во время загрузки ---------- */
{
  const h = harness({ free: 10 });                      // новому ENGINE.exe нужно 19 байт
  const { save, meta } = await installedGame(h, v1src);
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });
  h.marker = { version: 'v1' };
  h.st.free = 10;
  const saveBefore = snapshot(save), metaBefore = snapshot(meta);
  await assert.rejects(() => h.update(manifestOf('v2', v2src), v2src), /quota/i);
  assert.equal(h.sleeps.length, 3, 'четыре попытки с паузами, затем ошибка');
  assert.ok(h.sleeps.every(([, path, name]) => path === 'ENGINE.exe' && name === 'QuotaExceededError'));
  assert.deepEqual(h.marker, { version: 'v1' }, 'метка установки не продвинута при неполном обновлении');
  assert.equal(snapshot(save), saveBefore, 'сохранения целы после сбоя по квоте');
  assert.equal(snapshot(meta), metaBefore);
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS');
  // место появилось: повторный запуск достраивает установку (метка v1 -> целиком заново для изменённого файла)
  h.st.free = Infinity; h.downloads.length = 0; h.sleeps.length = 0;
  await h.update(manifestOf('v2', v2src), v2src);
  assert.deepEqual(h.marker, { version: 'v2' });
  assert.equal(text(h.game.files.get('ENGINE.exe').data), 'engine v2 is longer');
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS');
  assert.equal(snapshot(save), saveBefore);
}

/* ---------- 3. нет места даже для резервной копии: обновление не начинается ---------- */
{
  const h = harness({});
  const { save } = await installedGame(h, v1src);
  h.marker = { version: 'v1' };
  const gameBefore = JSON.stringify([...h.game.files].map(([n, r]) => [n, [...r.data]]));
  const realNavigator = Object.getOwnPropertyDescriptor(globalThis, 'navigator');
  Object.defineProperty(globalThis, 'navigator', { configurable: true, value: { storage: { estimate: async () => ({ quota: 1000, usage: 990 }) } } });
  try {
    await assert.rejects(() => h.update(manifestOf('v2', v2src), v2src), /недостаточно места для резервной копии/);
  } finally {
    if (realNavigator) Object.defineProperty(globalThis, 'navigator', realNavigator); else delete globalThis.navigator;
  }
  assert.deepEqual(h.downloads, [], 'при невозможной резервной копии ничего не скачивалось');
  assert.deepEqual(h.marker, { version: 'v1' });
  assert.equal(JSON.stringify([...h.game.files].map(([n, r]) => [n, [...r.data]])), gameBefore, 'файлы игры не менялись');
  assert.equal(text(save.files.get('slot1').data), 'slot one progress');
}

/* ---------- 4. первая установка при нехватке места: частичные файлы, затем достройка с возобновлением ---------- */
{
  const h = harness({ free: 12 });
  h.game = await h.root.getDirectoryHandle(h.rootName, { create: true });
  const save = await h.game.getDirectoryHandle('SAVE', { create: true });
  save.files.set('slot1', { data: bytes('from an older browser profile') });
  const before = snapshot(save);
  await assert.rejects(() => h.update(manifestOf('v1', v1src), v1src), /quota/i);
  assert.equal(h.marker, null, 'недоустановленная игра не получает метку');
  assert.equal(snapshot(save), before);
  h.st.free = Infinity; h.downloads.length = 0;
  await h.update(manifestOf('v1', v1src), v1src);
  assert.deepEqual(h.marker, { version: 'v1' });
  assert.equal(text(h.game.files.get('ENGINE.exe').data), 'engine v1');
  assert.equal(snapshot(save), before);
}

/* ---------- 5. тот же размер, другое содержимое: хэш замечает подмену ---------- */
{
  const h = harness({});
  await installedGame(h, { 'ENGINE.exe': bytes('AAAA'), options: bytes('o') });
  h.marker = { version: 'v1' };
  const next = { 'ENGINE.exe': bytes('BBBB'), options: bytes('o') };
  await h.update(manifestOf('v2', next), next);
  assert.equal(text(h.game.files.get('ENGINE.exe').data), 'BBBB');
  assert.deepEqual(h.downloads, ['ENGINE.exe']);
}

/* ---------- 6. исходные WMV исключены из манифеста: уже установленные у игрока остаются ---------- */
{
  // Манифест нового dist больше не перечисляет RESOURCE/VIDEOS (port.json files.exclude_paths). Для уже
  // установленной игры эти файлы — «лишние»: resync не удаляет ничего, чего нет в манифесте (см. 5 в
  // docs/hosting.md), поэтому ~119 МБ остаются в OPFS игрока, но не мешают и не перекачиваются.
  const h = harness({});
  const { save, meta } = await installedGame(h, v1src);
  await storage(Infinity).put(h.game, 'RESOURCE/VIDEOS/Trailer.wmv', bytes('W'.repeat(64)));
  await storage(Infinity).put(h.game, 'RESOURCE/VIDEOS/Russian/Invasion.wmv', bytes('I'.repeat(32)));
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });
  h.marker = { version: 'v1' };
  const saveBefore = snapshot(save), metaBefore = snapshot(meta);
  const result = await h.update(manifestOf('v2', v2src), v2src);
  assert.ok(result.backup?.backup);
  assert.equal(text(h.game.dirs.get('RESOURCE').dirs.get('VIDEOS').files.get('Trailer.wmv').data), 'W'.repeat(64));
  assert.equal(text(h.game.dirs.get('RESOURCE').dirs.get('VIDEOS').dirs.get('Russian').files.get('Invasion.wmv').data), 'I'.repeat(32));
  assert.ok(!h.downloads.some((p) => /videos/i.test(p)), 'WMV не скачивались');
  assert.equal(snapshot(save), saveBefore, 'SAVE не тронут');
  assert.equal(snapshot(meta), metaBefore, 'SAVE_META не тронут');
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS');
  assert.deepEqual(h.marker, { version: 'v2' });
}

/* ---------- 7. оценка места в порядке port.js: мелкое обновление при почти полной квоте проходит ---------- */
{
  const h = harness({});
  await installedGame(h, v1src);
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });
  h.marker = { version: 'v1' };
  const existingSize = async (dir, path) => {
    try { const [d, n] = await resolve(dir, path, false); return (await (await d.getFileHandle(n)).getFile()).size; }
    catch { return -1; }
  };
  const manifest = manifestOf('v2', v2src);   // ENGINE.exe 9 -> 19 байт, один новый файл; всё прочее совпало
  const total = manifest.files.reduce((s, f) => s + f.size, 0);
  const MiB = 1024 * 1024;
  // квота занята почти полностью (usage включает установленную игру): свободно 20 МиБ
  const nearlyFull = { quota: 5000 * MiB, usage: 4980 * MiB };
  const r = await checkStorageForSync({ dir: h.game, files: manifest.files, hadMarker: true, existingSize,
    estimate: async () => nearlyFull });
  assert.notEqual(r.status, 'insufficient');
  assert.equal(r.plan.toDownload, 2);
  assert.ok(r.plan.writeBytes < total);
  await h.update(manifest, v2src);
  assert.deepEqual(h.marker, { version: 'v2' });
  // то же обновление, но свободно меньше самого прироста (меньше килобайта): отказ ДО записи
  const h2 = harness({});
  await installedGame(h2, v1src);
  h2.marker = { version: 'v1' };
  const full = await checkStorageForSync({ dir: h2.game, files: manifest.files, hadMarker: true, existingSize,
    estimate: async () => ({ quota: 1000, usage: 995 }) });
  assert.equal(full.status, 'insufficient');
  assert.deepEqual(h2.downloads, []);
  assert.deepEqual(h2.marker, { version: 'v1' });
}

/* ---------- 8. .ogg рядом с .wav исключены из манифеста (files.exclude_if_sibling): у игрока остаются, звук цел ---------- */
{
  // Новый манифест не перечисляет RESOURCE/Sounds/**/*.ogg, у которых есть .wav (движок открывает именно .wav,
  // PORT_SPECIFICATION.md). Для установленной игры эти .ogg — «лишние»: не удаляются (~15 МБ остаются в
  // OPFS), не перекачиваются; .wav на месте и не перекачиваются; музыка (.ogg без .wav) остаётся в манифесте.
  const wav = bytes('RIFF'.padEnd(100, 'w')), dup = bytes('OggS-duplicate'), music = bytes('OggS-music');
  const v1sounds = { ...v1src, 'RESOURCE/Sounds/PEOPLE/step.wav': wav, 'RESOURCE/Sounds/PEOPLE/step.ogg': dup,
    'RESOURCE/Sounds/MUSIC/theme.ogg': music };
  const { 'RESOURCE/Sounds/PEOPLE/step.ogg': _dropped, ...v2sounds } = { ...v1sounds, ...v2src };
  const h = harness({});
  const { save, meta } = await installedGame(h, v1sounds);
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });
  h.marker = { version: 'v1' };
  const saveBefore = snapshot(save), metaBefore = snapshot(meta);
  const result = await h.update(manifestOf('v2', v2sounds), v2sounds);
  assert.ok(result.backup?.backup);
  const people = h.game.dirs.get('RESOURCE').dirs.get('Sounds').dirs.get('PEOPLE');
  assert.equal(text(people.files.get('step.ogg').data), 'OggS-duplicate', 'исключённый дубль не удалён');
  assert.equal(text(people.files.get('step.wav').data), text(wav), '.wav не тронут');
  assert.equal(text(h.game.dirs.get('RESOURCE').dirs.get('Sounds').dirs.get('MUSIC').files.get('theme.ogg').data), 'OggS-music');
  assert.ok(!h.downloads.some((p) => /sounds/i.test(p)), 'звуки не перекачивались');
  assert.equal(snapshot(save), saveBefore, 'SAVE не тронут');
  assert.equal(snapshot(meta), metaBefore, 'SAVE_META не тронут');
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS');
  assert.deepEqual(h.marker, { version: 'v2' });
}

/* ---------- 9. экраны загрузки из Loading/Russian публикуются как Loading/<имя> (files.relocate_if_absent) ---------- */
{
  // Старый манифест перечислял Loading/Russian/*; новый — те же байты под Loading/<имя> (кроме имён, уже занятых наверху).
  // У установленной игры старые копии в Russian/ — «лишние»: не удаляются (+~64 МБ остаются в OPFS), новые файлы докачиваются,
  // слоты SAVE, SAVE_META, options и файлы вне манифеста не затрагиваются.
  const en = bytes('EN start'), ru = bytes('RU start'), tavern = bytes('RU tavern'), sea = bytes('RU sea');
  const v1loading = { ...v1src, 'RESOURCE/Textures/Loading/start_loading.tga.tx': en, 'RESOURCE/Textures/Loading/Russian/start_loading.tga.tx': ru,
    'RESOURCE/Textures/Loading/Russian/Tavern_01.tga.tx': tavern, 'RESOURCE/Textures/Loading/Russian/Sea.tga.tx': sea };
  const v2loading = { ...v1src, 'RESOURCE/Textures/Loading/start_loading.tga.tx': en, 'RESOURCE/Textures/Loading/Russian/start_loading.tga.tx': ru,
    'RESOURCE/Textures/Loading/Tavern_01.tga.tx': tavern, 'RESOURCE/Textures/Loading/Sea.tga.tx': sea };
  const h = harness({});
  const { save, meta } = await installedGame(h, v1loading);
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });
  await storage(Infinity).put(h.game, 'RESOURCE/Textures/Loading/Russian/not-in-manifest.tga.tx', bytes('left over'));
  h.marker = { version: 'v1' };
  const saveBefore = snapshot(save), metaBefore = snapshot(meta);
  const result = await h.update(manifestOf('v2', v2loading), v2loading);
  assert.ok(result.backup?.backup);
  assert.deepEqual(h.downloads.sort(), ['RESOURCE/Textures/Loading/Sea.tga.tx', 'RESOURCE/Textures/Loading/Tavern_01.tga.tx'],
    'докачаны только перенесённые файлы; start_loading и всё прочее не перекачивались');
  const loading = h.game.dirs.get('RESOURCE').dirs.get('Textures').dirs.get('Loading');
  assert.equal(text(loading.files.get('Tavern_01.tga.tx').data), 'RU tavern');
  assert.equal(text(loading.files.get('Sea.tga.tx').data), 'RU sea');
  assert.equal(text(loading.files.get('start_loading.tga.tx').data), 'EN start', 'файл верхнего уровня не заменён');
  const russian = loading.dirs.get('Russian');
  assert.equal(text(russian.files.get('Tavern_01.tga.tx').data), 'RU tavern', 'старая копия в Russian/ не удалена');
  assert.equal(text(russian.files.get('not-in-manifest.tga.tx').data), 'left over', 'лишний файл не удалён');
  assert.equal(snapshot(save), saveBefore, 'SAVE не тронут');
  assert.equal(snapshot(meta), metaBefore, 'SAVE_META не тронут');
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS');
  assert.deepEqual(h.marker, { version: 'v2' });
  // свежая установка: ни одного файла в Loading/Russian/ кроме занятого наверху имени
  const fresh = harness({});
  fresh.game = await fresh.root.getDirectoryHandle(fresh.rootName, { create: true });
  await fresh.update(manifestOf('v2', v2loading), v2loading);
  const rl = fresh.game.dirs.get('RESOURCE').dirs.get('Textures').dirs.get('Loading');
  assert.deepEqual([...rl.dirs.get('Russian').files.keys()], ['start_loading.tga.tx']);
  assert.deepEqual([...rl.files.keys()].sort(), ['Sea.tga.tx', 'Tavern_01.tga.tx', 'start_loading.tga.tx']);
}

/* ---------- 9b. W1: экраны перехода по карте мира WorldMap/reload/Russian публикуются как WorldMap/reload/<имя> ---------- */
{
  // То же, что §9, для второго правила relocate_if_absent: у установленного игрока старые reload/Russian/* остаются как лишние
  // (+2 МБ), новые reload/<имя> докачиваются; SAVE, SAVE_META, options не затронуты.
  const sea = bytes('RU map sea'), battle = bytes('RU map battle');
  const v1wm = { ...v1src, 'RESOURCE/Textures/WorldMap/reload/Russian/sea.tga.tx': sea, 'RESOURCE/Textures/WorldMap/reload/Russian/Battle.tga.tx': battle };
  const v2wm = { ...v1src, 'RESOURCE/Textures/WorldMap/reload/sea.tga.tx': sea, 'RESOURCE/Textures/WorldMap/reload/Battle.tga.tx': battle };
  const h = harness({});
  const { save, meta } = await installedGame(h, v1wm);
  h.game.files.set('options', { data: bytes('USER CHANGED OPTIONS') });
  h.marker = { version: 'v1' };
  const saveBefore = snapshot(save), metaBefore = snapshot(meta);
  const result = await h.update(manifestOf('v2', v2wm), v2wm);
  assert.ok(result.backup?.backup);
  assert.deepEqual(h.downloads.sort(), ['RESOURCE/Textures/WorldMap/reload/Battle.tga.tx', 'RESOURCE/Textures/WorldMap/reload/sea.tga.tx']);
  const reload = h.game.dirs.get('RESOURCE').dirs.get('Textures').dirs.get('WorldMap').dirs.get('reload');
  assert.equal(text(reload.files.get('sea.tga.tx').data), 'RU map sea');
  assert.equal(text(reload.dirs.get('Russian').files.get('sea.tga.tx').data), 'RU map sea', 'старая копия в Russian/ не удалена');
  assert.equal(snapshot(save), saveBefore, 'SAVE не тронут');
  assert.equal(snapshot(meta), metaBefore, 'SAVE_META не тронут');
  assert.equal(text(h.game.files.get('options').data), 'USER CHANGED OPTIONS');
  assert.deepEqual(h.marker, { version: 'v2' });
}

console.log('resync preservation: all checks passed');
