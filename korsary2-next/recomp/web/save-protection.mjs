/* Experimental launcher guard. Does not provide locking against old launchers. */
import { encodeBackup, readSaveDirectory, withSaveLock } from './save-export.mjs';

const fail=(message)=>{ throw new Error(message); };

export function selectGameAssets(items, pathOf) {
  if (!Array.isArray(items) || typeof pathOf !== 'function') throw new Error('Некорректный список игровых файлов.');
  return items.filter(item=>{
    const path=pathOf(item);
    if(typeof path!=='string' || !path || path.includes('\\') || /[\x00-\x1f\x7f]/u.test(path) ||
       path.split('/').some(p=>!p || p==='.' || p==='..'))
      throw new Error('Некорректный путь игрового файла; копирование отменено.');
    const parts = path.split('/');
    if (parts[0].toLowerCase() === 'options' && parts.length > 1)
      throw new Error('Вложенные пути внутри файла настроек запрещены.');
    // SAVE (slots), SAVE_META (their creation-time records and language labels) and SAVE_TX (the
    // opt-in save transaction journal, prior copies and quarantine) are player
    // data beside the game files, never downloadable game assets.
    const top = parts[0].toLowerCase();
    return top!=='save' && top!=='save_meta' && top!=='save_tx';
  });
}

/** port.json files.exclude_if_sibling in the page (the same decision as gamefiles.redundant_siblings, which
 *  the packager and serve.py use): a file under `path` ending in `extension` is dropped only while the same
 *  folder also holds a file of the same stem with `sibling_extension` of at least `min_sibling_bytes`.
 *  Names compare case-insensitively. The page keeps more rather than less: a malformed or chained rule
 *  set is ignored as a whole, and a missing/short sibling keeps the file. */
export function dropSiblingDuplicates(items, pathOf, sizeOf, rawRules) {
  const rules = [];
  for (const r of Array.isArray(rawRules) ? rawRules : []) {
    const ext = String(r?.extension ?? '').toLowerCase(), sib = String(r?.sibling_extension ?? '').toLowerCase();
    const floor = r?.min_sibling_bytes === undefined ? 1 : r.min_sibling_bytes;
    if (!(ext.length > 1 && sib.length > 1 && ext[0] === '.' && sib[0] === '.' && ext !== sib && !(ext + sib).includes('/') &&
          Number.isSafeInteger(floor) && floor >= 1)) return items;
    rules.push({ path: String(r.path ?? '').toLowerCase().replace(/^\/+|\/+$/g, ''), ext, sib, floor });
  }
  if (!rules.length) return items;
  if (rules.some((r) => rules.some((o) => o.ext === r.sib))) return items;
  const sizes = new Map();
  for (const item of items) sizes.set(pathOf(item).toLowerCase(), sizeOf(item));
  return items.filter((item) => {
    const low = pathOf(item).toLowerCase();
    return !rules.some((r) => (!r.path || low.startsWith(r.path + '/')) && low.endsWith(r.ext) &&
      (sizes.get(low.slice(0, -r.ext.length) + r.sib) ?? 0) >= r.floor);
  });
}

/** port.json files.relocate_if_absent в странице (то же решение, что gamefiles.relocations, которое применяют
 *  make_dist.py и serve.py, и tests/verify_dist.py): файл прямо внутри папки `from` публикуется в папке `to` под тем же
 *  именем (и больше не под `from`), если в `to` нет файла (или папки) с таким именем без учёта регистра. Так русские экраны
 *  загрузки из Textures/Loading/Russian оказываются там, где их открывает движок (Textures/Loading/<имя>.tga.tx).
 *  `withPath(item, path)` возвращает копию элемента с новым путём; исходный список не меняется. Страница оставляет всё как есть,
 *  если набор правил некорректен или цепочечный; повторное применение ничего не меняет. */
export function relocateIfAbsent(items, pathOf, withPath, rawRules) {
  const rules = [];
  for (const r of Array.isArray(rawRules) ? rawRules : []) {
    if (!r || typeof r !== 'object' || typeof r.from !== 'string' || typeof r.to !== 'string' ||
        Object.keys(r).length !== 2) return items;
    const from = r.from.replace(/^\/+|\/+$/g, ''), to = r.to.replace(/^\/+|\/+$/g, '');
    if (`${from}/${to}`.split('/').some((p) => p === '' || p === '.' || p === '..' || p.includes('\\')) ||
        from.toLowerCase() === to.toLowerCase() || to.toLowerCase().startsWith(from.toLowerCase() + '/')) return items;
    rules.push({ from, to });
  }
  if (!rules.length) return items;
  if (rules.some((a) => rules.some((b) => a.to.toLowerCase() === b.from.toLowerCase()))) return items;
  const paths = items.map(pathOf).sort();
  const taken = new Set(paths.map((p) => p.toLowerCase()));
  const dirs = new Set();
  for (const low of taken) { const parts = low.split('/'); for (let i = 1; i < parts.length; i++) dirs.add(parts.slice(0, i).join('/')); }
  const moves = new Map();
  for (const r of rules) {
    const src = r.from.toLowerCase(), dst = r.to.toLowerCase();
    for (const p of paths) {
      if (!p.toLowerCase().startsWith(src + '/') || p.slice(src.length + 1).includes('/')) continue;
      const name = p.slice(src.length + 1);
      const target = `${src.startsWith(dst + '/') ? p.slice(0, dst.length) : r.to}/${name}`;
      if (taken.has(target.toLowerCase()) || dirs.has(target.toLowerCase())) continue;
      taken.add(target.toLowerCase());
      moves.set(p, target);
    }
  }
  if (!moves.size) return items;
  return items.map((item) => (moves.has(pathOf(item)) ? withPath(item, moves.get(pathOf(item))) : item));
}

/** Кодирования записей манифеста (D1, game-transfer.mjs ENCODINGS): отсутствует/identity = файл как есть. */
const KNOWN_ENCODINGS = ['gzip', 'br'];
const hasEnc = (f) => !!f && f.enc !== undefined && f.enc !== null && f.enc !== '' && f.enc !== 'identity';
/** Запись в пакете передачи (D3, game-transfer.mjs): место записи — pack/offset/csize. */
const inPackEntry = (f) => !!f && f.pack !== undefined && f.pack !== null;
/** Файл приходит не «как есть» по своему имени: сжатым (`enc`) и/или записью пакета. С середины такой файл
 *  не докачать (сжатый поток не продолжить, запись пакета качается целиком). */
const isPacked = (f) => hasEnc(f) || inPackEntry(f);
/** Сколько байт пойдёт по сети за файл (csize, если он известен и файл не «как есть»; иначе size). */
const wireBytes = (f) => isPacked(f) && Number.isSafeInteger(f.csize) && f.csize >= 0 ? f.csize : f.size;

/** SHA-256 записи манифеста: ровно 64 шестнадцатеричных символа (регистр не важен; сравнения идут по toLowerCase). */
const HEX64 = /^[0-9a-f]{64}$/i;
const hasSha256 = (f) => typeof f?.sha256 === 'string' && HEX64.test(f.sha256);

/** Проверка списка файлов манифеста ДО любой записи на диск. Каждая запись игрового файла (всё, кроме SAVE,
 *  SAVE_META и SAVE_TX: их selectGameAssets отбрасывает, они данные игрока и не качаются) обязана иметь
 *  `size` (целое >= 0) и `sha256` (64 hex): по ним принимается скачанный сжатый файл и сверяется уже
 *  установленный (syncManifestFiles), и без SHA файл того же размера считался бы целым без проверки (N11).
 *  Манифесты, которые пишут make_dist.py и serve.py (gamefiles.manifest_for), SHA имеют у всех записей. */
export function validateManifestFiles(items) {
  const files = selectGameAssets(items, f => f?.path);
  for (const f of files)
    if (!f || typeof f !== 'object' || !Number.isSafeInteger(f.size) || f.size < 0)
      throw new Error(`Некорректный размер игрового файла (${f?.path}): нужно целое число байт >= 0; копирование отменено.`);
  // Запись со сжатием: распакованные size/sha256 обязательны (по ним принимается файл), csize — число.
  for (const f of files.filter(isPacked)) {
    if (hasEnc(f) && (typeof f.enc !== 'string' || !KNOWN_ENCODINGS.includes(f.enc)))
      throw new Error(`${f.path}: неподдерживаемое кодирование «${String(f.enc)}»; обновите страницу игры.`);
    if (!/^[0-9a-f]{64}$/i.test(f.sha256 || ''))
      throw new Error(`${f.path}: для сжатого файла в манифесте нет SHA-256; копирование отменено.`);
    if (f.csize !== undefined && (!Number.isSafeInteger(f.csize) || f.csize < 0))
      throw new Error(`${f.path}: некорректный размер сжатого файла; копирование отменено.`);
    if (f.path.toLowerCase() === 'options')
      throw new Error('Файл настроек нельзя передавать сжатым.');
  }
  // Запись пакета: pack/offset/csize вместе, целые неотрицательные; запись без кодирования равна размеру файла.
  // Принадлежность пакету и границы проверяет validateManifestPacks (game-transfer.mjs) по верхнему списку packs.
  for (const f of files.filter(inPackEntry)) {
    if (!Number.isSafeInteger(f.pack) || f.pack < 0 || !Number.isSafeInteger(f.offset) || f.offset < 0 ||
        !Number.isSafeInteger(f.csize) || f.csize < 0)
      throw new Error(`${f.path}: некорректное место записи в пакете; копирование отменено.`);
    if (!hasEnc(f) && f.csize !== f.size)
      throw new Error(`${f.path}: запись пакета без кодирования должна быть равна размеру файла; копирование отменено.`);
  }
  const options = files.filter(f => f.path.toLowerCase() === 'options');
  if (options.length > 1 || (options.length && (options[0].path !== 'options' ||
      !/^[0-9a-f]{64}$/i.test(options[0].sha256 || '') || options[0].size > 1024 * 1024)))
    throw new Error('Некорректные данные файла настроек в манифесте.');
  // Все остальные записи (несжатые, «как есть»): SHA-256 обязателен так же, как у options и сжатых.
  const noSha = files.filter(f => !hasSha256(f));
  if (noSha.length)
    throw new Error(`${noSha[0].path}: в манифесте нет SHA-256 (64 hex)` +
      (noSha.length > 1 ? ` (и ещё у ${noSha.length - 1} файлов)` : '') + '; копирование отменено.');
  return files;
}

/** Download and verify settings before the caller opens the destination file. */
export async function fetchVerifiedOptions(url, entry, fetchImpl) {
  const res = await fetchImpl(url, {cache:'no-store'});
  if (!res.ok) throw new Error(`options: HTTP ${res.status}`);
  if (!res.body) throw new Error('options: ответ без тела');
  const reader = res.body.getReader(), chunks = [], st = sha256Init();
  let size = 0;
  try {
    for (;;) {
      const {done, value} = await reader.read();
      if (done) break;
      size += value.length;
      if (size > entry.size) throw new Error('options: ответ длиннее манифеста');
      chunks.push(value); sha256Update(st, value);
    }
  } catch (err) {
    try { await reader.cancel(); } catch { /* original error wins */ }
    throw err;
  }
  if (size !== entry.size || sha256Hex(st) !== entry.sha256.toLowerCase())
    throw new Error('options: размер или SHA-256 не совпадает с манифестом');
  const bytes = new Uint8Array(size);
  let offset = 0;
  for (const chunk of chunks) { bytes.set(chunk, offset); offset += chunk.length; }
  return bytes;
}

/** Called only after picker validation. Never remove or reuse an existing root.
 * A Web Lock coordinates cooperating copies only; OPFS has no atomic
 * create-if-absent, and older pages do not take this lock. */
export async function withFreshGameDirectory(root, locks, name, callback) {
  if(!locks?.request) throw new Error('Браузер не поддерживает защитную блокировку.');
  return withSaveLock(locks, name, () => locks.request(`${name}:game-folder-import`,{mode:'exclusive',ifAvailable:true},async lock=>{
    if(!lock) throw new Error('Другая вкладка уже копирует игру.');
    try {
      await root.getDirectoryHandle(name,{create:false});
      throw new Error('Игровой каталог уже существует. Копирование отменено, чтобы сохранить данные.');
    } catch(e) { if(e.name!=='NotFoundError') throw e; }
    return callback(await root.getDirectoryHandle(name,{create:true}));
  }));
}

/** What to do when the installed copy of one manifest file does not match the
 * server: resume an interrupted download of the current file only when the
 * installation was never complete (no marker); an existing complete install
 * whose file size changed means the server content changed, and appending to
 * the old bytes would corrupt the file, so rewrite it from scratch. A size
 * match alone does not prove the content matches the server — 'verify' tells the
 * caller to compare SHA-256 (every manifest entry has one, validateManifestFiles). */
export function planFileUpdate(have, size, hadMarker, packed = false) {
  if (!Number.isSafeInteger(have) || have < 0 || !Number.isSafeInteger(size) || size < 0)
    return 'rewrite';
  if (have === size) return 'verify';
  // сжатый поток с середины не продолжить (состояние распаковщика не хранится): только с нуля
  if (have > 0 && have < size && !hadMarker && !packed) return 'resume';
  return 'rewrite';
}

/** The root options file is mutable user data, not an updateable game asset.
 * Do not infer ownership from a missing marker: it may have been lost after a
 * completed install. Enumerate case variants because OPFS is case-sensitive
 * while the guest resolves game paths case-insensitively. */
export async function planOptionsUpdate(dir, files, hadMarker) {
  if (typeof hadMarker !== 'boolean' || !Array.isArray(files))
    throw new Error('Некорректные параметры настроек игры.');
  const entries = files.filter(f => typeof f?.path === 'string' && f.path.toLowerCase() === 'options');
  if (entries.length > 1 || (entries.length === 1 && entries[0].path !== 'options'))
    throw new Error('Неоднозначное имя файла настроек в манифесте.');
  if (!entries.length) return 'not-listed';
  let found;
  for await (const [name, handle] of dir.entries()) {
    if (name.toLowerCase() !== 'options') continue;
    if (found || handle.kind !== 'file')
      throw new Error('Неоднозначный файл настроек игры.');
    found = handle;
  }
  if (!found) {
    // A completed install that lost its settings is ambiguous. Refuse rather
    // than create a file that a crash could leave empty under the old marker.
    if (hadMarker)
      throw new Error('В завершённой установке отсутствует файл настроек. Обновление остановлено; восстановите настройки вручную.');
    return 'install';
  }
  // A read error must not look like an absent file. Do not touch its bytes.
  const file = await found.getFile();
  if (!hadMarker) {
    // An interrupted first install can leave the complete original options
    // before its marker is written. Reuse it only with exact verified bytes;
    // a partial file or user modification is ambiguous and must not be lost.
    const expected = entries[0];
    if (!/^[0-9a-f]{64}$/i.test(expected.sha256 || '') || file.size !== expected.size ||
        await sha256File(file) !== expected.sha256.toLowerCase())
      throw new Error('Найдены существующие настройки без подтверждения установки. Обновление остановлено, чтобы сохранить настройки.');
  }
  return 'preserve';
}

/** Сколько файлов/пакетов качается одновременно по умолчанию, предел и повторы (D3). Браузер на HTTP/1.1 всё равно
 *  держит не больше 6 соединений на хост; на HTTP/2 запросы идут по одному соединению, и дальше нескольких
 *  десятков выигрыша нет, зато растут память и нагрузка на процессор (SHA-256 на главном потоке). */
export const INSTALL_CONCURRENCY = Object.freeze({ default: 6, max: 16 });
const MAX_ATTEMPTS = 4;

export function installConcurrency(value, fallback = INSTALL_CONCURRENCY.default) {
  const n = Number(value);
  if (!Number.isInteger(n) || n < 1) return fallback;
  return Math.min(n, INSTALL_CONCURRENCY.max);
}

const abortError = (signal) => signal?.reason instanceof Error ? signal.reason
  : Object.assign(new Error('Установка отменена.'), { name: 'AbortError' });

/** Прогресс установки: готовые (проверенные) байты + байты задач, идущих сейчас. Повтор задачи откатывает её
 *  счётчик, но то, что видит `show`, не уменьшается (наибольшее значение): полоса на экране не пятится. */
class InstallProgress {
  constructor(show) { this.show = show; this.base = 0; this.live = 0; this.high = 0; }
  task() { return { cur: 0 }; }
  verified(n) { this.base += n; this.emit(); }
  add(task, n, name) { task.cur += n; this.live += n; this.emit(name); }
  reset(task) { this.live -= task.cur; task.cur = 0; }
  emit(name) {
    this.high = Math.max(this.high, this.base + this.live);
    if (name === undefined) this.show(this.high); else this.show(this.high, name);
  }
}

/** Выполняет `worker(item, index)` для items не более чем в `limit` потоков, беря элементы по порядку. Первая
 *  неудача останавливает выдачу новых элементов и отменяет `signal`, переданный воркерам; пул дожидается
 *  завершения всех запущенных и бросает первую ошибку. Отмена снаружи (`outer`) действует так же. */
async function runPool(items, limit, worker, outer) {
  const inner = new AbortController();
  const onOuter = () => inner.abort(outer.reason);
  if (outer?.aborted) throw abortError(outer);
  outer?.addEventListener?.('abort', onOuter, { once: true });
  let next = 0, failure = null;
  const lane = async () => {
    while (!failure && !inner.signal.aborted) {
      const i = next++;
      if (i >= items.length) return;
      try { await worker(items[i], i, inner.signal); }
      catch (err) { if (!failure) { failure = err; inner.abort(err); } }
    }
  };
  try { await Promise.all(Array.from({ length: Math.min(limit, items.length) }, lane)); }
  finally { outer?.removeEventListener?.('abort', onOuter); }
  if (failure) throw failure;
  if (outer?.aborted) throw abortError(outer);
}

/** Execute the same manifest update loop used by the launcher. Dependencies
 * are injected so the real control flow can be tested without a browser.
 *
 * Установка идёт в два шага. 1) Осмотр: каждый файл манифеста сверяется с тем, что уже лежит в хранилище (размер,
 * затем SHA-256 совпавших по размеру); готовые файлы больше не трогаются. 2) Загрузка недостающего не более чем
 * в `concurrency` потоков: отдельные файлы — через `downloadFile`, записи пакетов — через `downloadPackRun`, по
 * одному запросу на диапазон пакета (записи одного пакета, которые нужны, объединяются в диапазоны). Каждая задача
 * повторяется до 4 раз (для пакета «раз» — подряд без единого нового принятого файла: принятые записи остаются,
 * повтор пересчитывает недостающие). Файл принимается атомарно: при неудаче или отмене он не остаётся
 * принятым, остальные задачи этим не портятся. Метка установки пишется только после успеха ВСЕХ задач.
 *
 * `concurrency` 1 (по умолчанию) — файлы по очереди, как всегда. `packs` — верхний список manifest.packs.
 * `signal` — AbortSignal: отмена останавливает выдачу новых задач и обрывает идущие запросы, метка не пишется. */
export async function syncManifestFiles({dir, files, hadMarker, version, existingSize,
  downloadFile, downloadOptionsFile, writeMarker, show, sleep,
  packs = null, downloadPackRun = null, concurrency = 1, signal = null}) {
  files = validateManifestFiles(files);
  if (files.some(inPackEntry)) {
    if (typeof downloadPackRun !== 'function')
      throw new Error('Манифест содержит пакеты, а загрузчик их не умеет; обновите страницу игры.');
    (await import('./game-transfer.mjs')).validateManifestPacks(files, packs);   // до первой записи
  }
  const limit = installConcurrency(concurrency, 1);
  const optionsPlan = await planOptionsUpdate(dir, files, hadMarker);
  const progress = new InstallProgress(show);

  // 1. осмотр: что из манифеста уже установлено верно
  const todo = new Array(files.length).fill(null);
  await runPool(files, limit, async (f, i, sig) => {
    if (sig.aborted) throw abortError(sig);
    if (f.path === 'options' && optionsPlan === 'preserve') { progress.verified(f.size); return; }
    const have = await existingSize(dir, f.path);
    const plan = planFileUpdate(have, f.size, hadMarker, isPacked(f));
    if (plan === 'verify') {
      const ok = (await sha256GameFile(dir, f.path)) === f.sha256.toLowerCase();   // SHA есть у каждой записи (validateManifestFiles)
      if (ok) { progress.verified(f.size); return; }
    }
    todo[i] = { f, have, from: plan === 'resume' ? have : 0 };
  }, signal);

  // 2. задачи: отдельные файлы и диапазоны пакетов, в порядке первого файла в манифесте
  const tasks = [];
  const runs = new Map();
  const missing = [];
  todo.forEach((t, i) => {
    if (!t) return;
    if (inPackEntry(t.f)) missing.push({ entry: t.f, i });
    else tasks.push({ i, kind: 'file', ...t });
  });
  if (missing.length) {
    const { planPackRuns } = await import('./game-transfer.mjs');
    const order = new Map(missing.map((m) => [m.entry, m.i]));
    for (const run of planPackRuns(missing.map((m) => m.entry)))
      tasks.push({ i: Math.min(...run.entries.map((e) => order.get(e))), kind: 'pack', run });
  }
  tasks.sort((a, b) => a.i - b.i);

  const attemptsFile = async (t, sig) => {
    const { f, from } = t;
    const state = progress.task();
    for (let attempt = 1; ; attempt++) {
      progress.add(state, from);
      try {
        const onBytes = (n) => progress.add(state, n, f.path);
        if (f.path === 'options') await downloadOptionsFile(dir, f, onBytes);
        else await downloadFile(dir, f.path, f.size, from, onBytes, f, { signal: sig });
        return;
      } catch (err) {
        progress.reset(state);
        if (sig.aborted || err?.name === 'QuotaExceededError' || attempt >= MAX_ATTEMPTS) throw err;
        await sleep(1500 * attempt, f.path, err, sig);
        if (sig.aborted) throw abortError(sig);
      }
    }
  };
  const attemptsPack = async (t, sig) => {
    const pack = packs[t.run.pack];
    let left = t.run.entries;
    let futile = 0;
    for (;;) {
      const before = left.length;
      const state = progress.task();
      const accepted = new Set();
      try {
        await downloadPackRun(dir, pack, left, (n) => progress.add(state, n, pack.path),
          (entry) => { accepted.add(entry); progress.reset(state); progress.base += entry.size; progress.emit(pack.path); },
          { signal: sig });
        return;
      } catch (err) {
        progress.reset(state);
        if (sig.aborted || err?.name === 'QuotaExceededError') throw err;
        left = left.filter((e) => !accepted.has(e));
        futile = left.length < before ? 0 : futile + 1;
        if (futile >= MAX_ATTEMPTS) throw err;
        await sleep(1500 * Math.max(1, futile), pack.path, err, sig);
        if (sig.aborted) throw abortError(sig);
      }
    }
  };
  await runPool(tasks, limit, (t, _i, sig) => t.kind === 'pack' ? attemptsPack(t, sig) : attemptsFile(t, sig), signal);
  await writeMarker(version);
}

/* ------------------------------------------------------ оценка нужного места (квота) */

/* Оценка делается ДО загрузки по реальному объёму того, что придётся записать, а не по размеру
 * всего манифеста: при обновлении `usage` браузера уже включает установленные файлы.
 *
 * Что считается для каждого файла манифеста (те же правила, что у planFileUpdate/syncManifestFiles):
 *   verify  — размер совпал: файл считается совпавшим и места не просит (его SHA-256 проверит
 *             синхронизация позже; несовпавший по содержимому файл будет перезаписан целиком, на
 *             этот случай оставлен запас — самый большой такой файл, но не больше maxVerifyReserveBytes);
 *   resume  — частичный файл незавершённой установки: докачивается только хвост;
 *   rewrite — новый файл или файл другого размера: пишется целиком; старая копия освобождается
 *             только после закрытия записи, поэтому на время записи нужно место и под временную
 *             копию (OPFS пишет в swap-файл рядом) — это `tempBytes` (наибольший заменяемый файл).
 * Верхняя граница пикового прироста: сумма приростов + tempBytes. К ней добавляются запас под
 * следующий архив SAVE (restore point; сам архив этого обновления к моменту проверки уже записан и
 * учтён в usage) и небольшой запас на метаданные и неточность оценки браузера.
 * Файл `options` — данные игрока (<= 1 МиБ): при наличии он не перезаписывается и места не считает.
 * При параллельной загрузке (`concurrency`, D3) временные копии бывают сразу у нескольких файлов: tempBytes — сумма самых
 * больших из них (не больше `concurrency`), при одном потоке — наибольшая, как раньше. */
export const STORAGE_LIMITS = Object.freeze({
  minSlackBytes: 16 * 1024 * 1024,        // минимум запаса на неточность/метаданные
  slackRatio: 0.02,                       // или 2% от прироста, что больше
  minBackupReserveBytes: 8 * 1024 * 1024, // минимум под следующий архив SAVE
  maxVerifyReserveBytes: 64 * 1024 * 1024, // потолок запаса на файл, совпавший по размеру, но не по содержимому
});

const finiteNonNegative = (n) => typeof n === 'number' && Number.isFinite(n) && n >= 0;

// Brave deliberately reports a fixed 2 GiB StorageEstimate for privacy, even
// when the actual quota is larger or smaller. Treat it as unknown, not as a
// hard limit; actual OPFS write failures still stop the operation safely.
export async function isPrivacyCappedQuota(estimate, nav = globalThis.navigator) {
  if (estimate?.quota !== 2 ** 31) return false;
  try { return typeof nav?.brave?.isBrave === 'function' && await nav.brave.isBrave() === true; }
  catch { return false; }
}

/** Чистый расчёт. files: [{path, size}]; haveSizes: Map путь -> размер установленного файла
 * (-1/нет записи = файла нет; нечисловое значение считается «файла нет»); hadMarker: есть метка
 * завершённой установки; saveBytes: суммарный размер SAVE (неизвестный/некорректный = 0). Записи
 * с некорректным размером не учитываются и считаются в `invalid` (validateManifestFiles отвергает
 * такой манифест раньше). */
export function planStorageNeed({ files, haveSizes, hadMarker = false, saveBytes = 0, concurrency = 1 } = {}) {
  if (!Array.isArray(files)) throw new Error('Некорректный список файлов для оценки места.');
  const have = (path) => {
    const v = haveSizes instanceof Map ? haveSizes.get(path) : undefined;
    return Number.isSafeInteger(v) && v >= 0 ? v : -1;
  };
  const replaced = [];
  const r = { writeBytes: 0, growthBytes: 0, tempBytes: 0, verifyBytes: 0, largestVerifyBytes: 0,
    toDownload: 0, toResume: 0, unchanged: 0, invalid: 0, fresh: true, transferBytes: 0 };
  for (const f of files) {
    if (!f || typeof f.path !== 'string' || !Number.isSafeInteger(f.size) || f.size < 0) { r.invalid++; continue; }
    const h = have(f.path);
    if (h >= 0) r.fresh = false;
    if (f.path === 'options' && h >= 0) { r.unchanged++; continue; }   // данные игрока, не перезаписываются
    const plan = planFileUpdate(h, f.size, !!hadMarker, isPacked(f));
    // Квота считается по РАСПАКОВАННОМУ размеру (f.size): OPFS хранит распакованные файлы; csize — только
    // объём трафика (transferBytes), на место он не влияет.
    const wire = wireBytes(f);
    if (plan === 'verify') {
      r.unchanged++; r.verifyBytes += f.size;
      r.largestVerifyBytes = Math.max(r.largestVerifyBytes, f.size);
    } else if (plan === 'resume') {
      r.toResume++; r.writeBytes += f.size - h; r.growthBytes += f.size - h;
      r.transferBytes += f.size - h;
    } else {
      r.toDownload++; r.writeBytes += f.size; r.transferBytes += wire;
      if (h < 0) r.growthBytes += f.size;
      else {
        r.growthBytes += Math.max(0, f.size - h);
        replaced.push(Math.min(f.size, h));
      }
    }
  }
  // Заменяемые файлы пишутся через временную копию; одновременно идёт до `concurrency` записей, так что
  // в худшем случае занято место под самые большие из них разом (при одном потоке — под один, как раньше).
  const slots = Math.max(1, Math.min(Number.isInteger(concurrency) ? concurrency : 1, INSTALL_CONCURRENCY.max));
  r.tempBytes = replaced.sort((x, y) => y - x).slice(0, slots).reduce((x, y) => x + y, 0);
  if (hadMarker) r.fresh = false;
  const save = finiteNonNegative(saveBytes) ? saveBytes : 0;
  r.backupReserveBytes = Math.max(STORAGE_LIMITS.minBackupReserveBytes, Math.ceil(save));
  r.slackBytes = Math.max(STORAGE_LIMITS.minSlackBytes, Math.ceil(r.growthBytes * STORAGE_LIMITS.slackRatio),
    Math.min(r.largestVerifyBytes, STORAGE_LIMITS.maxVerifyReserveBytes));
  r.minBytes = r.growthBytes + r.tempBytes;   // меньше этого записать обновление точно не удастся
  r.totalBytes = r.minBytes + r.backupReserveBytes + r.slackBytes;
  return r;
}

const mbUp = (n) => Math.ceil(n / 1e6);
const mbDown = (n) => Math.floor(n / 1e6);

/** Решение по оценке браузера `estimate` ({quota, usage}; undefined/некорректное = неизвестно).
 * status: 'ok' (места хватает или писать нечего), 'tight' (хватает на минимум, но не на запас:
 * загрузка начинается, предупреждение), 'insufficient' (не хватает даже минимума: остановка до
 * записи чего-либо), 'unknown' (оценки нет или она бессмысленна: НЕ блокируем, ошибку записи
 * обработает сама загрузка). Оценка квоты у браузеров приблизительная, поэтому блокирует только
 * нехватка минимума. */
export function assessStorage(plan, estimate, { privacyCapped = false } = {}) {
  const base = { plan, free: null };
  if (!plan || !finiteNonNegative(plan.minBytes) || !finiteNonNegative(plan.totalBytes))
    return { ...base, status: 'unknown', message: 'Не удалось оценить нужное место; загрузка начнётся без предварительной проверки.' };
  if (plan.writeBytes === 0) return { ...base, status: 'ok', message: '' };
  if (privacyCapped) return { ...base, status: 'unknown',
    message: 'Браузер скрывает фактическую квоту хранилища. Загрузка начнётся, но может остановиться, если место действительно закончится.' };
  const quota = estimate?.quota, usage = estimate?.usage;
  if (!finiteNonNegative(quota) || quota === 0)
    return { ...base, status: 'unknown',
      message: 'Браузер не сообщил объём доступного хранилища; загрузка начнётся без предварительной проверки места.' };
  const usageKnown = finiteNonNegative(usage);
  const free = Math.max(0, quota - (usageKnown ? usage : 0));
  const what = plan.fresh ? 'установки' : 'обновления';
  if (free < plan.minBytes && (usageKnown || quota < plan.minBytes))
    return { ...base, free, status: 'insufficient',
      message: `Недостаточно места в хранилище браузера: свободно около ${mbDown(free)} МБ, для ${what} нужно не меньше ` +
        `${mbUp(plan.minBytes)} МБ (записать ${mbUp(plan.writeBytes)} МБ${plan.transferBytes < plan.writeBytes ? `, по сети около ${mbUp(plan.transferBytes)} МБ` : ''}). Освободите место или закройте другие вкладки с игрой ` +
        `и перезагрузите страницу. Сохранения не затронуты.` };
  if (!usageKnown)
    return { ...base, free, status: 'unknown',
      message: 'Браузер не сообщил занятый объём хранилища; загрузка начнётся без предварительной проверки места.' };
  if (free < plan.totalBytes)
    return { ...base, free, status: 'tight',
      message: `Свободного места мало (около ${mbDown(free)} МБ при рекомендуемых ${mbUp(plan.totalBytes)} МБ для ${what}): ` +
        `загрузка начнётся, но может прерваться из-за нехватки места.` };
  return { ...base, free, status: 'ok', message: '' };
}

/** Суммарный размер файлов каталога (рекурсивно, с пределом глубины); любая ошибка чтения даёт 0 —
 * это лишь размер запаса под архив, а не условие безопасности. */
export async function measureDirBytes(dir, depth = 4) {
  if (!dir?.entries || depth < 0) return 0;
  let total = 0;
  try {
    for await (const [, h] of dir.entries()) {
      if (h.kind === 'file') total += (await h.getFile()).size;
      else if (h.kind === 'directory') total += await measureDirBytes(h, depth - 1);
    }
  } catch { return 0; }
  return total;
}

/** Всё вместе для страницы: размеры установленных файлов (existingSize — та же функция, что у
 * syncManifestFiles; dir может быть null, если игровой каталог ещё не создан), размер SAVE,
 * оценка браузера. Ничего не пишет и не создаёт; сбой самой оценки не блокирует загрузку. */
export async function checkStorageForSync({ dir, files, hadMarker, existingSize, estimate, concurrency = 1, nav = globalThis.navigator }) {
  files = validateManifestFiles(files);
  const haveSizes = new Map();
  let saveBytes = 0;
  try {
    if (dir) {
      for (const f of files) haveSizes.set(f.path, await existingSize(dir, f.path));
      try { saveBytes = await measureDirBytes(await dir.getDirectoryHandle('SAVE', { create: false })); }
      catch { saveBytes = 0; }
    }
    const plan = planStorageNeed({ files, haveSizes, hadMarker, saveBytes, concurrency });
    let est;
    try { est = await estimate?.(); } catch { est = undefined; }
    return assessStorage(plan, est, { privacyCapped: await isPrivacyCappedQuota(est, nav) });
  } catch (e) {
    return { status: 'unknown', free: null, plan: null,
      message: `Не удалось оценить нужное место (${e?.message || e}); загрузка начнётся без предварительной проверки.` };
  }
}

/** Incremental SHA-256 (WebCrypto cannot digest a stream). First call with no
 * state, then feed returned {h} back in. */
export function sha256Init() {
  const h = new Uint32Array([0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                             0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19]);
  return { h, len: 0, buf: new Uint8Array(0) };
}
const K = new Uint32Array([
  0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
  0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
  0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
  0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
  0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
  0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
  0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
  0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2]);

const W = new Int32Array(64);

/* `blocks` 64-byte blocks of `data` starting at `o`, into the state words `h` (locals instead of an
   array destructuring per block: about 3x faster, which matters when a whole install is hashed). */
function sha256Blocks(h, data, o, blocks) {
  let h0 = h[0], h1 = h[1], h2 = h[2], h3 = h[3], h4 = h[4], h5 = h[5], h6 = h[6], h7 = h[7];
  for (let b = 0; b < blocks; b++, o += 64) {
    for (let i = 0; i < 16; i++, o += 4)
      W[i] = (data[o] << 24) | (data[o + 1] << 16) | (data[o + 2] << 8) | data[o + 3];
    o -= 64;
    for (let i = 16; i < 64; i++) {
      const x = W[i - 15], y = W[i - 2];
      const s0 = ((x >>> 7) | (x << 25)) ^ ((x >>> 18) | (x << 14)) ^ (x >>> 3);
      const s1 = ((y >>> 17) | (y << 15)) ^ ((y >>> 19) | (y << 13)) ^ (y >>> 10);
      W[i] = (W[i - 16] + s0 + W[i - 7] + s1) | 0;
    }
    let a = h0, b2 = h1, c = h2, d = h3, e = h4, f = h5, g = h6, hh = h7;
    for (let i = 0; i < 64; i++) {
      const S1 = ((e >>> 6) | (e << 26)) ^ ((e >>> 11) | (e << 21)) ^ ((e >>> 25) | (e << 7));
      const t1 = (hh + S1 + ((e & f) ^ (~e & g)) + K[i] + W[i]) | 0;
      const S0 = ((a >>> 2) | (a << 30)) ^ ((a >>> 13) | (a << 19)) ^ ((a >>> 22) | (a << 10));
      const t2 = (S0 + ((a & b2) ^ (a & c) ^ (b2 & c))) | 0;
      hh = g; g = f; f = e; e = (d + t1) | 0; d = c; c = b2; b2 = a; a = (t1 + t2) | 0;
    }
    h0 = (h0 + a) | 0; h1 = (h1 + b2) | 0; h2 = (h2 + c) | 0; h3 = (h3 + d) | 0;
    h4 = (h4 + e) | 0; h5 = (h5 + f) | 0; h6 = (h6 + g) | 0; h7 = (h7 + hh) | 0;
  }
  h[0] = h0; h[1] = h1; h[2] = h2; h[3] = h3; h[4] = h4; h[5] = h5; h[6] = h6; h[7] = h7;
}

export function sha256Update(st, bytes) {
  st.len += bytes.length;
  let pos = 0;
  if (st.buf.length) {                       // finish the pending partial block first
    const need = 64 - st.buf.length;
    if (bytes.length < need) {
      const nb = new Uint8Array(st.buf.length + bytes.length);
      nb.set(st.buf); nb.set(bytes, st.buf.length);
      st.buf = nb;
      return st;
    }
    const block = new Uint8Array(64);
    block.set(st.buf); block.set(bytes.subarray(0, need), st.buf.length);
    sha256Blocks(st.h, block, 0, 1);
    st.buf = new Uint8Array(0);
    pos = need;
  }
  const full = (bytes.length - pos) >> 6;
  sha256Blocks(st.h, bytes, pos, full);
  st.buf = bytes.slice(pos + full * 64);     // a copy: the caller may reuse its buffer
  return st;
}

export function sha256Hex(st) {
  const bits = st.len * 8;
  const pad = new Uint8Array((((55 - st.buf.length) % 64) + 64) % 64 + 1 + 8);
  pad[0] = 0x80;
  new DataView(pad.buffer).setUint32(pad.length - 4, bits >>> 0);
  new DataView(pad.buffer).setUint32(pad.length - 8, Math.floor(bits / 0x100000000));
  sha256Update(st, pad);
  st.buf = new Uint8Array(0);
  return [...st.h].map(x => (x >>> 0).toString(16).padStart(8, '0')).join('');
}

/** SHA-256 of an OPFS file, chunk by chunk (works on the main thread). */
async function sha256File(file) {
  const st = sha256Init();
  for (let off = 0; off < file.size; off += 1 << 20)
    sha256Update(st, new Uint8Array(await file.slice(off, off + (1 << 20)).arrayBuffer()));
  return sha256Hex(st);
}

export async function sha256GameFile(dir, relPath) {
  return sha256File(await (await fileHandleOf(dir, relPath)).getFile());
}

async function fileHandleOf(dir, relPath) {
  const parts = relPath.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create: false });
  return dir.getFileHandle(parts[parts.length - 1], { create: false });
}

/* ------------------------------------------------------ SAVE restore points (Ф4.2) */

/* Local restore points for the SAVE folder, written as ZIP32 archives (via
 * encodeBackup, so the same name/size limits as export apply) into a dedicated
 * OPFS folder that is a SIBLING of the game root (`<rootName>-backups`, e.g.
 * "korsary2-game-backups"): game installs and updates only ever touch the game
 * root, so these archives cannot be removed or overwritten by game-file
 * operations. Every write takes the same `${rootName}:save-backup` exclusive
 * Web Lock as export/import — it coordinates cooperating pages, and a running
 * game holds it for its whole page lifetime (save-owner.mjs), which is what
 * makes other tabs' backup/import/export refuse fast. */

export const BACKUP_KEEP = 10;   // newest archives kept, older ones pruned

/** "pre-update-2026-11-09T19-45-12-456Z.zip": the ISO stamp (with ':' replaced,
 * it is legal in OPFS but awkward in listings) sorts chronologically as a plain
 * string, which planRetention relies on. */
export function backupFileName(label, d = new Date()) {
  if (typeof label !== 'string' || !label || label.length > 40 || /[/\\:*?"<>|\x00-\x1f]/u.test(label))
    fail('Некорректная метка архива сохранений.');
  return `${label}-${d.toISOString().replace(/:/g, '-')}.zip`;
}

/** Pure retention plan: keep the newest `keep` names (ISO stamps sort as
 * strings), return the rest for best-effort removal. */
export function planRetention(names, keep = BACKUP_KEEP) {
  if (!Number.isSafeInteger(keep) || keep < 1) fail('Некорректный предел хранения архивов сохранений.');
  const sorted = [...names].sort();
  return { keep: sorted.slice(-keep), remove: sorted.slice(0, -keep) };
}

const storageEstimate = () =>
  typeof navigator !== 'undefined' ? navigator.storage?.estimate?.() : undefined;

/** Write `entries` (SAVE files, {name, bytes}) as one archive into the sibling
 * backups folder and prune old archives beyond BACKUP_KEEP. The caller must
 * already hold the `${rootName}:save-backup` lock (backupSavesBeforeUpdate does,
 * and importBackupZip holds it for its whole run) — requesting it again here
 * would refuse to a cooperating caller that is allowed to proceed. Fails closed:
 * a backup that cannot be written raises and nothing else has changed. */
export async function writeSaveBackupLocked(root, rootName, entries, label) {
  if (!root?.getDirectoryHandle) fail('Браузер не поддерживает каталоги OPFS.');
  const archive = encodeBackup(entries);   // validates names and enforces LIMITS
  const est = await storageEstimate();
  if (est && est.quota != null && !(await isPrivacyCappedQuota(est)) && est.quota - (est.usage || 0) < archive.length + 1024)
    fail('В хранилище браузера недостаточно места для резервной копии сохранений.');
  const dir = await root.getDirectoryHandle(`${rootName}-backups`, { create: true });
  let name = backupFileName(label);
  for (let n = 1; ; n++) {   // same-millisecond collision: nudge the stamp later,
    try { await dir.getFileHandle(name, { create: false }); }   // keeping names sorted chronologically
    catch (e) { if (e.name === 'NotFoundError') break; throw e; }
    name = backupFileName(label, new Date(Date.now() + n));
  }
  const fh = await dir.getFileHandle(name, { create: true });
  let w;
  try {
    w = await fh.createWritable();
    await w.write(archive);
    await w.close();
  } catch (e) {
    try { await w?.abort?.(); } catch { /* keep original failure */ }
    try { await dir.removeEntry(name); } catch { /* keep original failure */ }
    throw e;
  }
  const warnings = [];
  try {
    const names = [];
    for await (const [n, h] of dir.entries()) if (h.kind === 'file' && n.endsWith('.zip')) names.push(n);
    for (const n of planRetention(names).remove)
      try { await dir.removeEntry(n); }
      catch (e) { warnings.push(`Не удалось удалить старый архив ${n}: ${e.message}.`); }
  } catch (e) { warnings.push(`Не удалось пересмотреть старые архивы сохранений: ${e.message}.`); }
  return { name, bytes: archive.length, entries: entries.length, warnings };
}

/** Restore point before a risky operation (a game update from the server, a
 * mass replace in the importer). Takes the same exclusive save lock as
 * export/import, so it never races a backup/restore on another tab. A missing
 * game folder or SAVE, or an empty SAVE, is not an error — there is simply
 * nothing to protect. Throws (and the caller should abort the risky operation)
 * when a non-empty SAVE exists but cannot be backed up. */
// The caller owns the SAVE lock for this root. Do not acquire it recursively.
export async function backupSavesBeforeUpdateLocked(root, rootName, label = 'pre-update') {
  let game, dir;
  try { game=await root.getDirectoryHandle(rootName, { create: false }); }
  catch (e) { if (e.name === 'NotFoundError') return { skipped: 'no-saves' }; throw e; }
  try { dir = await game.getDirectoryHandle('SAVE', { create: false }); }
  catch (e) { if (e.name === 'NotFoundError') return { skipped: 'no-saves' }; throw e; }
  let count = 0;
  for await (const [, h] of dir.entries()) if (h.kind === 'file') count++;
  if (!count) return { skipped: 'empty' };
  // the game root lets the archive include each slot's SAVE_META time record and (E5) language label
  const saved = await writeSaveBackupLocked(root, rootName, await readSaveDirectory(dir, game), label);
  return { backup: saved.name, bytes: saved.bytes, entries: saved.entries, warnings: saved.warnings };
}

export async function backupSavesBeforeUpdate(root, locks, rootName, label = 'pre-update') {
  return withSaveLock(locks, rootName, () => backupSavesBeforeUpdateLocked(root, rootName, label));
}

/** Serialize a manifest update and its restore point with save import/export
 * and fresh picker installs. A missing marker does not imply missing SAVE.
 * This is not an atomic transaction; a running game holds the same lock for
 * its whole page lifetime (save-owner.mjs), so an update can only start in a
 * tab that has not started the game yet. */
export async function updateUnderSaveLock({ root, locks, rootName, version, readMarker, sync, onBackup = () => {} }) {
  if (typeof version !== 'string' || !version || typeof readMarker !== 'function' ||
      typeof sync !== 'function' || typeof onBackup !== 'function')
    throw new Error('Некорректные параметры обновления.');
  return withSaveLock(locks, rootName, async () => {
    const marker = await readMarker();
    if (marker?.version === version) return { skipped: 'current' };
    const backup = await backupSavesBeforeUpdateLocked(root, rootName);
    onBackup(backup);
    await sync();
    return { backup };
  });
}
