// N11: валидатор манифеста (web/save-protection.mjs validateManifestFiles) обязан требовать у КАЖДОЙ записи игрового файла
// `size` (целое >= 0) и `sha256` (64 hex) и отказывать ДО любой записи на диск. Исключение по коду: пути SAVE/SAVE_META/SAVE_TX
// (данные игрока; selectGameAssets отбрасывает их до проверки, они не качаются и не сверяются).
// Манифесты настоящего генератора (gamefiles.manifest_for) и текущей сборки обязаны проходить.
//   node korsary2-next/recomp/tests/test_manifest_strict_sha256.mjs
// Мутационная проверка самого теста: mutate_manifest_strict_sha256.mjs (подставляет изменённую копию модуля через SAVE_PROTECTION_DIR).
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { manifestFor } from '../web/gamefiles.mjs';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const webDir = path.resolve(here, '../web');
const modDir = process.env.SAVE_PROTECTION_DIR ? path.resolve(process.env.SAVE_PROTECTION_DIR) : webDir;
const M = await import(pathToFileURL(path.join(modDir, 'save-protection.mjs')).href);
const { validateManifestFiles, syncManifestFiles, checkStorageForSync } = M;

let groups = 0;
const ok = (name) => { groups++; console.log(`ok - ${name}`); };
const sha = (d) => createHash('sha256').update(d).digest('hex');
const S1 = sha('x');
const noShaRe = () => /нет SHA-256/;
const good = (p, size = 1) => ({ path: p, size, sha256: S1 });

/* ------------------------------------------------------------ 1. запись без sha256 / с неверным sha256 */
{
  const noSha = /нет SHA-256/;
  // сама запись «как есть», какой её делает старый манифест без хешей
  assert.throws(() => validateManifestFiles([{ path: 'engine.ini', size: 1 }]), noSha);
  assert.throws(() => validateManifestFiles([{ path: 'RESOURCE/a/b.tx', size: 0 }]), /RESOURCE\/a\/b\.tx: в манифесте нет SHA-256/, 'сообщение называет файл');
  const bad = {
    'пустая строка': '', 'короче на 1': 'a'.repeat(63), 'длиннее на 1': 'a'.repeat(65), 'не hex (g)': 'g'.repeat(64),
    'пробел в конце': 'a'.repeat(63) + ' ', 'с префиксом sha256:': 'sha256:' + S1, 'число': 12345, 'null': null,
    'объект': {}, 'массив': [S1], 'true': true, 'Buffer': Buffer.from(S1),
  };
  for (const [what, v] of Object.entries(bad))
    assert.throws(() => validateManifestFiles([{ path: 'a.bin', size: 1, sha256: v }]), noSha, `sha256 = ${what}`);
  // регистр hex не важен (и верхний, и нижний допустимы)
  assert.equal(validateManifestFiles([{ path: 'a.bin', size: 1, sha256: S1.toUpperCase() }]).length, 1);
  assert.equal(validateManifestFiles([{ path: 'a.bin', size: 1, sha256: S1 }]).length, 1);
  ok('запись без sha256 или с коротким/длинным/не-hex/нестроковым sha256 отвергается; верхний регистр допустим');
}

/* ------------------------------------------------------------ 2. size обязателен */
{
  for (const [what, v] of Object.entries({ 'нет': undefined, 'отрицательный': -1, 'дробный': 1.5, 'строка': '5', 'NaN': NaN, 'Infinity': Infinity, 'null': null, '2^53': 2 ** 53 })) {
    const e = { path: 'a.bin', sha256: S1 }; if (v !== undefined) e.size = v;
    assert.throws(() => validateManifestFiles([e]), /Некорректный размер игрового файла \(a\.bin\)/, `size: ${what}`);
  }
  assert.equal(validateManifestFiles([good('empty.bin', 0)]).length, 1, 'size 0 допустим');
  ok('запись без size / с некорректным size отвергается (с именем файла в сообщении)');
}

/* ------------------------------------------------------------ 3. options, сжатые и пакетные записи */
{
  assert.throws(() => validateManifestFiles([{ path: 'options', size: 10 }]), /настроек/, 'options без SHA');
  assert.throws(() => validateManifestFiles([{ path: 'options', size: 10, sha256: 'z'.repeat(64) }]), /настроек/);
  assert.equal(validateManifestFiles([good('options', 10)]).length, 1);
  // сжатая запись без SHA
  assert.throws(() => validateManifestFiles([{ path: 'a.tx', size: 9, enc: 'gzip', csize: 5 }]), noShaRe());
  assert.throws(() => validateManifestFiles([{ path: 'a.tx', size: 9, enc: 'br', csize: 5 }]), noShaRe());
  // пакетная запись (в т.ч. «как есть», без enc) без SHA
  assert.throws(() => validateManifestFiles([{ path: 'a.tx', size: 9, enc: 'gzip', csize: 5, pack: 0, offset: 0 }]), noShaRe());
  assert.throws(() => validateManifestFiles([{ path: 'a.ogg', size: 9, csize: 9, pack: 1, offset: 4 }]), noShaRe());
  assert.throws(() => validateManifestFiles([{ path: 'a.ogg', size: 9, csize: 9, pack: 1, offset: 4, sha256: 'abc' }]), noShaRe());
  // и с SHA проходят
  assert.equal(validateManifestFiles([{ ...good('a.tx', 9), enc: 'gzip', csize: 5 }, { ...good('b.tx', 9), enc: 'br', csize: 5, pack: 0, offset: 0 },
    { ...good('c.ogg', 9), csize: 9, pack: 1, offset: 4 }]).length, 3);
  ok('options без SHA, сжатая и пакетная записи без SHA отвергаются; с SHA проходят');
}

/* ------------------------------------------------------------ 4. смешанные манифесты и SAVE */
{
  const many = Array.from({ length: 1000 }, (_, i) => good(`RESOURCE/f${i}.bin`, i));
  assert.equal(validateManifestFiles(many).length, 1000);
  // одна плохая запись в начале, середине, конце портит весь манифест
  for (const at of [0, 500, 999]) {
    const m = many.map((e, i) => (i === at ? { path: e.path, size: e.size } : e));
    assert.throws(() => validateManifestFiles(m), new RegExp(`RESOURCE/f${at}\\.bin: в манифесте нет SHA-256`), `плохая запись #${at}`);
  }
  // несколько плохих: названа первая, видно число остальных
  const two = [good('a'), { path: 'b', size: 1 }, { path: 'c', size: 1, sha256: 'x' }, { path: 'd', size: 1 }];
  assert.throws(() => validateManifestFiles(two), /b: в манифесте нет SHA-256 \(64 hex\) \(и ещё у 2 файлов\)/);
  // смешанный: сжатые + «как есть» с SHA + options
  const mixed = [{ ...good('a.tx', 9), enc: 'gzip', csize: 5 }, good('c.ogg', 9), good('options', 12), { ...good('d.wav', 9), enc: 'identity' }];
  assert.equal(validateManifestFiles(mixed).length, 4);
  assert.throws(() => validateManifestFiles([...mixed, { path: 'e.bin', size: 1 }]), /e\.bin: в манифесте нет SHA-256/);
  // SAVE*, SAVE_META, SAVE_TX — данные игрока: не файлы игры, игнорируются без SHA и не возвращаются
  const withSave = [good('ENGINE.exe', 5), { path: 'SAVE/slot1/x', size: 3 }, { path: 'save_meta/a', size: 1 }, { path: 'SAVE_TX/j', size: 1 }, { path: 'Save', size: 1 }];
  const out = validateManifestFiles(withSave);
  assert.deepEqual(out.map((f) => f.path), ['ENGINE.exe'], 'записи данных игрока отброшены, остальное цело');
  // путь, похожий на SAVE, но не он: игровой файл, SHA обязателен
  assert.throws(() => validateManifestFiles([{ path: 'SAVEGAME/x', size: 1 }]), /нет SHA-256/);
  assert.throws(() => validateManifestFiles([{ path: 'RESOURCE/SAVE/x', size: 1 }]), /нет SHA-256/);
  // не-массив, мусорные пути и записи: прежние отказы целы
  assert.throws(() => validateManifestFiles(null), /Некорректный список/);
  assert.throws(() => validateManifestFiles([null]), /Некорректный путь/);
  assert.throws(() => validateManifestFiles([{ size: 1, sha256: S1 }]), /Некорректный путь/);
  ok('смешанные манифесты: одна плохая запись (начало/середина/конец) отвергает все; SAVE* исключены; похожие на SAVE — нет');
}

/* ------------------------------------------------------------ 5. отказ ДО записи: syncManifestFiles и checkStorageForSync */
{
  class Dir {
    constructor() { this.files = new Map(); this.writes = 0; }
    async getDirectoryHandle() { this.writes++; throw new Error('не должно вызываться'); }
  }
  const run = async (files, install = {}, hadMarker = false) => {
    const dir = new Dir();
    for (const [k, v] of Object.entries(install)) dir.files.set(k, v);
    const log = { download: 0, options: 0, marker: 0, show: 0 };
    const rec = { dir, log };
    rec.promise = syncManifestFiles({
      dir, files, hadMarker, version: 'v',
      existingSize: async (d, p) => (d.files.has(p) ? d.files.get(p).length : -1),
      downloadFile: async () => { log.download++; }, downloadOptionsFile: async () => { log.options++; },
      writeMarker: async () => { log.marker++; }, show: () => { log.show++; }, sleep: async () => {},
    });
    return rec;
  };
  // 5a. плохая запись в конце: ни одной загрузки, метки нет, каталог не тронут
  const files = [good('a.bin', 3), good('b.bin', 3), { path: 'c.bin', size: 3 }];
  const r = await run(files);
  await assert.rejects(r.promise, /c\.bin: в манифесте нет SHA-256/);
  assert.deepEqual(r.log, { download: 0, options: 0, marker: 0, show: 0 }, 'до отказа ничего не скачано и не записано');
  assert.equal(r.dir.writes, 0);
  // 5b. старая дыра: файл без SHA уже стоит с тем же размером — раньше считался целым без проверки, теперь отказ
  const r2 = await run([{ path: 'a.bin', size: 3 }], { 'a.bin': 'abc' }, true);
  await assert.rejects(r2.promise, /a\.bin: в манифесте нет SHA-256/);
  assert.equal(r2.log.marker, 0);
  // 5c. оценка места тот же манифест отвергает так же (а не оценивает молча)
  await assert.rejects(checkStorageForSync({ dir: null, files, hadMarker: false, existingSize: async () => -1, estimate: async () => ({ quota: 1e12, usage: 0 }) }), /нет SHA-256/);
  // 5d. верхний регистр hex в манифесте: установленный файл сверяется без учёта регистра (не качается заново),
  //     а файл того же размера с другим содержимым перекачивается
  const mem = (data) => ({ files: new Map(Object.entries(data)),
    async getDirectoryHandle() { throw Object.assign(new Error('nf'), { name: 'NotFoundError' }); },
    async getFileHandle(n) { if (!this.files.has(n)) throw Object.assign(new Error('nf'), { name: 'NotFoundError' });
      const d = this.files.get(n); return { kind: 'file', async getFile() { return new Blob([d]); } }; } });
  const syncMem = async (dir, files) => {
    const log = { download: [], marker: 0 };
    await syncManifestFiles({ dir, files, hadMarker: true, version: 'v',
      existingSize: async (d, p) => (d.files.has(p) ? Buffer.byteLength(d.files.get(p)) : -1),
      downloadFile: async (d, p, size, from, onBytes) => { log.download.push(p); d.files.set(p, 'x'.repeat(size)); onBytes(size); },
      downloadOptionsFile: async () => {}, writeMarker: async () => { log.marker++; }, show: () => {}, sleep: async () => {} });
    return log;
  };
  const upper = { path: 'a.bin', size: 5, sha256: sha('hello').toUpperCase() };
  const l1 = await syncMem(mem({ 'a.bin': 'hello' }), [upper]);
  assert.deepEqual(l1, { download: [], marker: 1 }, 'совпавший файл при верхнем регистре hex не перекачивается');
  const l2 = await syncMem(mem({ 'a.bin': 'HELLO' }), [upper]);
  assert.deepEqual(l2.download, ['a.bin'], 'тот же размер, другое содержимое: перекачка');
  ok('отказ до записи: ни загрузок, ни метки, ни каталогов; файл без SHA с совпавшим размером больше не «верен»; оценка места отвергает так же; hex в верхнем регистре сверяется без учёта регистра');
}

/* ------------------------------------------------------------ 6. настоящий генератор gamefiles.manifest_for */
{
  const tmp = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-manifest-strict-'));
  try {
    const files = new Map();
    for (const [name, data] of [['ENGINE.exe','MZ'.repeat(40)],['options','[opt]\n'.repeat(3)],['RESOURCE/INI/a.ini','k=v\r\n'.repeat(2000)],['RESOURCE/Sounds/a.ogg',Buffer.alloc(5000,23)],['RESOURCE/empty.bin',''],['RESOURCE/Textures/b.tga.tx','T'.repeat(70000)],['RESOURCE/c.gm','50.1'+'G'.repeat(900)]]) { const p=path.join(tmp,name);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,data);files.set(name,p); }
    const out = {plain:manifestFor(files),gz:manifestFor(files,{'RESOURCE/INI/a.ini':{enc:'gzip',csize:40},'RESOURCE/Textures/b.tga.tx':{enc:'gzip'}}),br:manifestFor(files,{'RESOURCE/INI/a.ini':{enc:'br',csize:40}}),packed:manifestFor(files,{'RESOURCE/INI/a.ini':{pack:0,offset:0,csize:40,enc:'gzip'},'RESOURCE/Sounds/a.ogg':{pack:0,offset:40,csize:5000}},[{path:'_k2pack/0000-x.pack',size:2000,files:2}])};
    for (const [kind, manifest] of Object.entries(out)) {
      assert.equal(manifest.files.length, 7, kind);
      assert.ok(manifest.files.every((e) => /^[0-9a-f]{64}$/.test(e.sha256) && Number.isSafeInteger(e.size)), `${kind}: генератор пишет sha256 и size у всех записей`);
      assert.equal(validateManifestFiles(manifest.files).length, 7, `${kind}: настоящий манифест проходит строгий валидатор`);
      // каждая запись по очереди теряет sha256 (и, отдельно, получает укороченный): манифест отвергается
      manifest.files.forEach((e, i) => {
        const cut = manifest.files.map((x, j) => (j === i ? (({ sha256, ...rest }) => rest)(x) : x));
        assert.throws(() => validateManifestFiles(cut), /нет SHA-256|настроек/, `${kind}: без sha256 у ${e.path}`);
        const short = manifest.files.map((x, j) => (j === i ? { ...x, sha256: x.sha256.slice(1) } : x));
        assert.throws(() => validateManifestFiles(short), /нет SHA-256|настроек/, `${kind}: укороченный sha256 у ${e.path}`);
      });
    }
  } finally { fs.rmSync(tmp, { recursive: true, force: true }); }
  ok('gamefiles.manifest_for (обычный, gzip, br, пакеты): проходит; потеря/укорочение sha256 у любой записи отвергается');
}

/* ------------------------------------------------------------ 7. текущая сборка (только чтение) */
{
  const dist = process.env.K2_DISTRIBUTION_ROOT ? path.resolve(process.env.K2_DISTRIBUTION_ROOT) : path.resolve(here, '../../../distribution');
  const p = path.join(dist, 'game/manifest.json');
  if (!fs.existsSync(p)) console.log(`skip - ${p} не найден`);
  else {
    const m = JSON.parse(fs.readFileSync(p, 'utf8'));
    const files = validateManifestFiles(m.files);
    assert.ok(files.length > 1000 && files.every((e) => /^[0-9a-f]{64}$/.test(e.sha256)));
    ok(`манифест сборки (${files.length} записей, SHA у всех): проходит`);
  }
}

console.log(`manifest-strict-sha256: ${groups} групп проверок PASS`);
