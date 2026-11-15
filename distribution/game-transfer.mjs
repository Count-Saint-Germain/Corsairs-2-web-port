/* Загрузка игровых файлов, которые лежат на сервере сжатыми (D1, docs/compression-d1.md).

   Манифест: запись файла может иметь `enc: "gzip"` (и необязательный `csize` — длину сжатого потока).
   Тогда файл опубликован как `<path>.gz` — обычный gzip-поток, который страница распаковывает на лету
   через DecompressionStream и пишет в хранилище (OPFS хранит РАСПАКОВАННЫЕ данные). `size` и `sha256`
   записи всегда относятся к распакованному содержимому: по ним проверяются установленные файлы, ими
   считается квота, из них складывается `version` манифеста. Запись без `enc` — файл как есть (все старые
   манифесты и несжимаемые типы).

   Пакеты передачи (D3, docs/install-requests-d3.md): мелкие файлы лежат на сервере не по одному, а в пакетах
   `game/_k2pack/<NNNN>-<digest>.pack` — это просто склейка записей файлов (запись = сам файл или его gzip-поток).
   Запись манифеста тогда содержит `pack` (индекс в верхнем списке `packs`: {path, size, files}), `offset` и
   `csize` — диапазон байт записи в пакете; `size`/`sha256`, как всегда, относятся к РАСПАКОВАННОМУ файлу. Страница
   качает пакет (или нужный ему диапазон) ОДНИМ запросом, режет поток на записи по манифесту, распаковывает каждую
   отдельным потоком и принимает файл только после проверки размера и SHA-256 распакованных байт.

   Кодирования (D1b, docs/compression-d1b.md): `gzip` распаковывает сам браузер (DecompressionStream); `br` (brotli,
   `game/<path>.br`) — WebAssembly-декодер web/brotli-decoder.mjs, который подгружается ЛЕНИВО (prepareDecoders) и только
   если в манифесте есть запись `enc: "br"`. Для br действует то же правило: размер и SHA-256 проверяются ПОСЛЕ
   распаковки, а сам декодер не даёт вывести больше `size` байт записи (защита от «бомбы»).

   Здесь нет браузерных зависимостей: хранилище, сеть и распаковщик передаются параметрами, поэтому тот же
   код проверяется и в Node (test_game_transfer.mjs), и в настоящем Chromium с OPFS. */
import { sha256Init, sha256Update, sha256Hex } from './save-protection.mjs';

/** Известные кодирования. `format` — имя для DecompressionStream; `decoder` — имя WebAssembly-декодера из `decoders`. */
export const ENCODINGS = Object.freeze({
  gzip: { suffix: '.gz', format: 'gzip' },
  br: { suffix: '.br', decoder: 'brotli' },
});

/** Загруженные WebAssembly-декодеры страницы (prepareDecoders). Тесты подставляют свои через параметр `decoders`. */
const pageDecoders = { brotli: null };

/** Подготовка декодеров ДО загрузки: если среди записей есть `br`, подгружает WebAssembly-декодер brotli (один раз).
 *  Ошибка (нет WebAssembly, файл декодера недоступен или не совпал по SHA-256) — исключение: страница отказывает до
 *  первой записи, как при любом неподдерживаемом кодировании. Манифест без `br` ничего не загружает. */
export async function prepareDecoders(files, { loadBrotli = defaultLoadBrotli, decoders = pageDecoders } = {}) {
  let need = false;
  for (const f of files) { const enc = entryEncoding(f); if (enc && ENCODINGS[enc].decoder === 'brotli') { need = true; break; } }
  if (!need || decoders.brotli) return;
  try { decoders.brotli = await loadBrotli(); }
  catch (err) { throw new Error(`не удалось подготовить декодер brotli (${err?.message || err}); обновите страницу игры или браузер.`); }
}
const defaultLoadBrotli = async () => (await import('./brotli-decoder.mjs')).loadBrotliDecoder();

/** Поток распаковки записи: DecompressionStream для gzip или поток WebAssembly-декодера (brotli) с пределом вывода
 *  `entry.size`. Нужный декодер должен быть уже загружен (prepareDecoders). */
function decompressor(enc, entry, DecompressionStreamImpl, decoders) {
  const spec = ENCODINGS[enc];
  if (spec.decoder) {
    const d = decoders?.[spec.decoder];
    if (!d) throw new Error(`${entry.path}: декодер ${spec.decoder} не загружен (prepareDecoders)`);
    return d.createStream({ maxOutput: entry.size });
  }
  return new DecompressionStreamImpl(spec.format);
}

/** Кодирование записи манифеста: null (файл как есть) или 'gzip'. Незнакомое значение — ошибка: такой
 *  манифест написан новее этой страницы, и молча скачать «как есть» значило бы испортить файл. */
export function entryEncoding(entry) {
  const enc = entry?.enc;
  if (enc === undefined || enc === null || enc === '' || enc === 'identity') return null;
  if (typeof enc !== 'string' || !Object.hasOwn(ENCODINGS, enc))
    throw new Error(`${entry?.path}: неподдерживаемое кодирование «${String(enc)}»; обновите страницу игры.`);
  return enc;
}

/** Путь файла относительно game/ на сервере: сжатый файл лежит под именем с суффиксом. */
export function remotePath(entry) {
  const enc = entryEncoding(entry);
  return enc ? entry.path + ENCODINGS[enc].suffix : entry.path;
}

/** Сколько байт пойдёт по сети для записи (csize, если известен; иначе размер файла). */
export function transferSize(entry) {
  return entryEncoding(entry) && Number.isSafeInteger(entry.csize) && entry.csize >= 0 ? entry.csize : entry.size;
}

/** Есть ли в манифесте сжатые файлы, которые этот браузер не сможет распаковать (проверка ДО загрузки): gzip —
 *  если нет DecompressionStream('gzip'), brotli — если нет WebAssembly (сам декодер грузит prepareDecoders). */
export function unsupportedEncodings(files, DecompressionStreamImpl = globalThis.DecompressionStream) {
  const need = new Set();
  for (const f of files) { const enc = entryEncoding(f); if (enc) need.add(enc); }
  return [...need].filter((enc) => {
    if (ENCODINGS[enc].decoder) return typeof WebAssembly !== 'object' || typeof WebAssembly.instantiate !== 'function';
    if (typeof DecompressionStreamImpl !== 'function') return true;
    try { new DecompressionStreamImpl(ENCODINGS[enc].format); return false; } catch { return true; }
  });
}

/** Ошибка, после которой ЭТА запись не принята: данные не совпали с манифестом. */
export class TransferIntegrityError extends Error {
  constructor(message) { super(message); this.name = 'TransferIntegrityError'; }
}

/** One OPFS write attempt. Never remove an existing file on abort or failure:
 * createWritable() uses a temporary swap and commits only on close. A newly
 * created empty placeholder, however, must be removed if that attempt fails.
 * getFile(create) must use create:false first and reject on errors other than
 * NotFoundError; removeFile() removes only the path of this attempt. */
export function createSafeWriteTarget({getFile, removeFile}) {
  if (typeof getFile !== 'function' || typeof removeFile !== 'function')
    throw new TypeError('getFile and removeFile are required');
  let created = false;
  return {
    async openWritable(options) {
      let file;
      try { file = await getFile(false); }
      catch (e) {
        if (e?.name !== 'NotFoundError') throw e;
        file = await getFile(true);
        created = true;
      }
      return options === undefined ? file.createWritable() : file.createWritable(options);
    },
    async discard() {
      if (created) { await removeFile(); created = false; }
    },
  };
}

/** Общий конец загрузки файла: читает распакованные байты через `read()` (Uint8Array или null в конце), считает
 *  SHA-256, пишет в `openWritable()`, фиксирует (close) ТОЛЬКО после проверки размера и SHA-256. Любая неудача:
 *  `cancel(err)`, abort записи, очистка нового пустого файла, исключение. `finalCheck()` вызывается после последнего чанка. */
async function writeVerified({ entry, read, cancel, openWritable, discard, onBytes, finalCheck }) {
  let writer = null;
  const st = sha256Init();
  let size = 0;
  try {
    writer = await openWritable();
    for (;;) {
      const value = await read();
      if (value === null) break;
      if (!value.length) continue;
      size += value.length;
      if (size > entry.size) throw new TransferIntegrityError(`${entry.path}: распакованные данные длиннее манифеста (${entry.size} байт)`);
      sha256Update(st, value);
      await writer.write(value);
      onBytes(value.length);
    }
    finalCheck?.();
    if (size !== entry.size)
      throw new TransferIntegrityError(`${entry.path}: после распаковки ${size} из ${entry.size} байт`);
    if (sha256Hex(st) !== entry.sha256.toLowerCase())
      throw new TransferIntegrityError(`${entry.path}: SHA-256 после распаковки не совпадает с манифестом`);
    await writer.close();
    writer = null;
  } catch (err) {
    try { await cancel(err); } catch { /* the original error wins */ }
    if (writer) { try { await writer.abort?.(); } catch { /* ignore */ } }
    try { await discard(); } catch { /* ignore */ }
    throw err;
  }
}

/** Скачивает один файл, распаковывает его потоком и записывает распакованные байты.
 *
 *  entry          запись манифеста ({path, size, sha256, enc, csize?})
 *  url            полный адрес сжатого (или обычного) объекта
 *  fetchImpl      fetch
 *  openWritable   () => Promise<{write(chunk), close(), abort?()}>  (FileSystemWritableFileStream);
 *                 вызывается только после того, как сервер ответил успешно
 *  discard        () => Promise<void>  убрать только созданный этим запросом файл (после abort)
 *  onBytes(n)     прогресс в РАСПАКОВАННЫХ байтах
 *  signal         AbortSignal: отмена обрывает запрос; прежняя версия файла остаётся
 *
 *  Файл целиком в памяти не держится: чанк -> SHA-256 -> запись. Запись фиксируется (close) только после
 *  того, как поток дочитан без ошибки, длина равна size, а SHA-256 равен sha256; иначе abort + discard,
 *  новый файл не остаётся «принятым», а прежняя версия сохраняется до успешной записи.
 *  Сжатый файл докачать с середины нельзя (состояние распаковщика не сохраняется): повтор — с нуля. */
export async function downloadPackedFile({ entry, url, fetchImpl, openWritable, discard, onBytes = () => {}, signal,
  DecompressionStreamImpl = globalThis.DecompressionStream, decoders = pageDecoders }) {
  const enc = entryEncoding(entry);
  if (!enc) throw new Error(`${entry?.path}: запись без кодирования; downloadPackedFile не для неё`);
  if (!/^[0-9a-f]{64}$/i.test(entry.sha256 || '')) throw new TransferIntegrityError(`${entry.path}: в манифесте нет SHA-256`);
  if (unsupportedEncodings([entry], DecompressionStreamImpl).length)
    throw new Error(`${entry.path}: браузер не умеет распаковывать ${enc} (${ENCODINGS[enc].decoder ? 'WebAssembly' : 'DecompressionStream'}); обновите браузер.`);
  const hasCsize = Number.isSafeInteger(entry.csize) && entry.csize >= 0;
  const res = await fetchImpl(url, signal ? { cache: 'no-store', signal } : { cache: 'no-store' });
  if (!res.ok) throw new Error(`${entry.path}: HTTP ${res.status}`);
  if (!res.body) throw new Error(`${entry.path}: ответ без тела`);
  // A host or proxy that adds Content-Encoding to the .gz object has already been undone by fetch():
  // the bytes that arrive are then the plain file, which the size and SHA-256 checks below still decide.
  const hostDecoded = !!(res.headers?.get?.('content-encoding') || '').trim() &&
    (res.headers.get('content-encoding').trim().toLowerCase() !== 'identity');
  let received = 0;
  const counter = new TransformStream({
    transform(chunk, controller) {
      received += chunk.length;
      if (!hostDecoded && hasCsize && received > entry.csize)
        throw new TransferIntegrityError(`${entry.path}: сжатый поток длиннее манифеста (${entry.csize} байт)`);
      controller.enqueue(chunk);
    },
  });
  const source = res.body.pipeThrough(counter);
  const body = hostDecoded ? source : source.pipeThrough(decompressor(enc, entry, DecompressionStreamImpl, decoders));
  const reader = body.getReader();
  return writeVerified({
    entry, openWritable, discard, onBytes,
    read: async () => { const { done, value } = await reader.read(); return done ? null : value; },
    cancel: (err) => reader.cancel(err),
    finalCheck: () => {
      if (!hostDecoded && hasCsize && received !== entry.csize)
        throw new TransferIntegrityError(`${entry.path}: сжатый поток короче манифеста (${received} из ${entry.csize} байт)`);
    },
  });
}

/* ------------------------------------------------------------------ пакеты передачи (D3) */

/** Порядок записей пакета: по смещению, пустая запись раньше той, что начинается там же. */
const byOffset = (a, b) => a.offset - b.offset || a.csize - b.csize;

/** Запись манифеста лежит в пакете? */
export const inPack = (entry) => entry?.pack !== undefined && entry?.pack !== null;

/** Сколько соседних (по байтам) записей одного пакета можно захватить одним запросом, даже если часть из них
 *  уже установлена: байты между недостающими записями не больше этого предела дешевле нового запроса. */
export const PACK_RUN_GAP = 256 * 1024;

/** Проверка пакетной части манифеста ДО любой записи: `packs` — верхний список [{path, size, files?}], записи
 *  с `pack` ссылаются на него по индексу; диапазон записи лежит внутри пакета, записи одного пакета не
 *  пересекаются, у записи есть csize, у записи без `enc` csize равен size. Возвращает files без изменений.
 *  Манифест без пакетов (старый) проходит как есть. */
export function validateManifestPacks(files, packs) {
  const packed = files.filter(inPack);
  if (packs !== undefined && packs !== null && !Array.isArray(packs)) throw new Error('Некорректный список пакетов в манифесте.');
  if (!packed.length) return files;
  if (!packs?.length) throw new Error('В манифесте есть файлы в пакетах, но нет списка пакетов; обновите страницу игры.');
  const names = new Set();
  for (const [i, p] of packs.entries()) {
    if (typeof p?.path !== 'string' || !/^[A-Za-z0-9_][A-Za-z0-9_.\-]*(\/[A-Za-z0-9_][A-Za-z0-9_.\-]*)*$/.test(p.path) ||
        !Number.isSafeInteger(p.size) || p.size < 0)
      throw new Error(`Некорректное описание пакета ${i} в манифесте.`);
    if (names.has(p.path)) throw new Error(`Пакет ${p.path} указан в манифесте дважды.`);
    names.add(p.path);
  }
  const spans = new Map();
  for (const f of packed) {
    if (!Number.isSafeInteger(f.pack) || f.pack < 0 || f.pack >= packs.length)
      throw new Error(`${f.path}: некорректный номер пакета.`);
    if (!Number.isSafeInteger(f.offset) || f.offset < 0 || !Number.isSafeInteger(f.csize) || f.csize < 0)
      throw new Error(`${f.path}: некорректное место записи в пакете.`);
    if (f.offset + f.csize > packs[f.pack].size)
      throw new Error(`${f.path}: запись выходит за пределы пакета ${packs[f.pack].path}.`);
    if (!entryEncoding(f) && f.csize !== f.size)
      throw new Error(`${f.path}: запись без кодирования должна быть равна размеру файла.`);
    if (!spans.has(f.pack)) spans.set(f.pack, []);
    spans.get(f.pack).push(f);
  }
  for (const [index, list] of spans) {
    list.sort(byOffset);
    for (let i = 1; i < list.length; i++)
      if (list[i].offset < list[i - 1].offset + list[i - 1].csize)
        throw new Error(`${list[i].path}: записи пакета ${packs[index].path} пересекаются.`);
  }
  return files;
}

/** Группирует недостающие записи (в порядке манифеста) в запросы: {pack, entries, start, end} — один диапазон
 *  байт одного пакета. Соседние записи сливаются, если между ними не больше `gap` байт (их тоже придётся
 *  прочитать, но это дешевле нового запроса). */
export function planPackRuns(entries, gap = PACK_RUN_GAP) {
  const byPack = new Map();
  for (const e of entries) {
    if (!byPack.has(e.pack)) byPack.set(e.pack, []);
    byPack.get(e.pack).push(e);
  }
  const runs = [];
  for (const [pack, list] of byPack) {
    list.sort(byOffset);
    let run = null;
    for (const e of list) {
      if (run && e.offset - run.end <= gap) { run.entries.push(e); run.end = e.offset + e.csize; }
      else { run = { pack, entries: [e], start: e.offset, end: e.offset + e.csize }; runs.push(run); }
    }
  }
  return runs;
}

/** Читает поток по частям: read(max) отдаёт не больше max байт из текущего чанка, skip(n) пропускает n байт.
 *  Конец потока раньше времени — TransferIntegrityError (пакет усечён). */
class ByteCursor {
  constructor(reader, name) { this.reader = reader; this.name = name; this.chunk = null; this.at = 0; }
  async read(max) {
    while (!this.chunk || this.at >= this.chunk.length) {
      const { done, value } = await this.reader.read();
      if (done) return null;
      this.chunk = value; this.at = 0;
    }
    const n = Math.min(max, this.chunk.length - this.at);
    const out = this.chunk.subarray(this.at, this.at + n);
    this.at += n;
    return out;
  }
  async skip(n) {
    while (n > 0) {
      const c = await this.read(n);
      if (!c) throw new TransferIntegrityError(`${this.name}: пакет оборван раньше конца записи`);
      n -= c.length;
    }
  }
}

/** Скачивает диапазон пакета одним запросом и принимает записи этого диапазона по одной.
 *
 *  pack           {path, size}  запись из manifest.packs
 *  entries        записи манифеста этого пакета (pack/offset/csize/enc), которые нужно принять; в любом порядке
 *  url            полный адрес пакета
 *  openWritable   (entry) => Promise<{write, close, abort?}>       discard (entry) => Promise<void>
 *  onBytes(n)     прогресс в РАСПАКОВАННЫХ байтах (как у downloadPackedFile)
 *  onFile(entry)  запись принята (файл зафиксирован); вызывается сразу, не в конце пакета
 *  signal         AbortSignal
 *
 *  Запрос: весь пакет (без Range), если нужны записи от 0 до конца, иначе `Range: bytes=a-b` от начала первой до
 *  конца последней записи (между ними недостающие записи могут перемежаться готовыми: их байты читаются и
 *  отбрасываются). Сервер, не знающий Range и ответивший 200 с начала пакета, тоже годится: начало пропускается.
 *  Каждая запись режется по манифесту ровно на csize байт, распаковывается своим потоком (gzip) и принимается
 *  только после проверки размера и SHA-256 распакованных байт; при первой же неудаче (сеть, порча, усечение)
 *  выполнение останавливается исключением: принятые ДО неё записи остаются, повтор пересчитывает недостающие. */
export async function downloadPackRun({ pack, entries, url, fetchImpl, openWritable, discard, onBytes = () => {},
  onFile = () => {}, signal, DecompressionStreamImpl = globalThis.DecompressionStream, decoders = pageDecoders }) {
  const list = [...entries].sort(byOffset);
  if (!list.length) return;
  if (unsupportedEncodings(list, DecompressionStreamImpl).length)
    throw new Error(`${pack.path}: браузер не умеет распаковывать записи пакета (DecompressionStream или WebAssembly); обновите браузер.`);
  for (const e of list) {
    if (!/^[0-9a-f]{64}$/i.test(e.sha256 || '')) throw new TransferIntegrityError(`${e.path}: в манифесте нет SHA-256`);
    if (e.offset + e.csize > pack.size) throw new TransferIntegrityError(`${e.path}: запись за пределами пакета`);
  }
  for (let i = 1; i < list.length; i++)
    if (list[i].offset < list[i - 1].offset + list[i - 1].csize) throw new TransferIntegrityError(`${list[i].path}: записи пакета пересекаются`);
  const start = list[0].offset;
  const end = list[list.length - 1].offset + list[list.length - 1].csize;
  const wholePack = start === 0 && end === pack.size;
  let reader = null;
  let cursor;
  let streamPos = 0;                       // смещение в пакете следующего байта, который отдаст cursor
  if (end === start) {                     // только пустые записи: сеть не нужна
    cursor = new ByteCursor({ read: async () => ({ done: true }) }, pack.path);
    streamPos = start;
  } else {
    const init = signal ? { cache: 'no-store', signal } : { cache: 'no-store' };
    if (!wholePack) init.headers = { Range: `bytes=${start}-${end - 1}` };
    const res = await fetchImpl(url, init);
    if (!res.ok) throw new Error(`${pack.path}: HTTP ${res.status}`);
    if (!res.body) throw new Error(`${pack.path}: ответ без тела`);
    if (!wholePack && res.status === 206) {
      const m = /^bytes (\d+)-(\d+)\/(\d+|\*)$/.exec(res.headers?.get?.('content-range') || '');
      if (!m || Number(m[1]) !== start || Number(m[2]) < end - 1 || (m[3] !== '*' && Number(m[3]) !== pack.size))
        throw new TransferIntegrityError(`${pack.path}: сервер вернул не тот диапазон (${res.headers?.get?.('content-range') || 'без Content-Range'}) или другой пакет`);
      streamPos = start;
    } else if (res.status !== 200 && res.status !== 206) {
      throw new Error(`${pack.path}: HTTP ${res.status}`);
    }
    reader = res.body.getReader();
    cursor = new ByteCursor(reader, pack.path);
  }
  try {
    for (const e of list) {
      if (streamPos > e.offset) throw new TransferIntegrityError(`${e.path}: запись пакета уже прочитана`);
      await cursor.skip(e.offset - streamPos);
      streamPos = e.offset;
      let left = e.csize;
      const enc = entryEncoding(e);
      if (enc) {
        // источник сжатых байт ровно этой записи; конец записи = конец потока для распаковщика
        const source = new ReadableStream({
          async pull(ctl) {
            if (left === 0) { ctl.close(); return; }
            const c = await cursor.read(left);
            if (!c) { ctl.error(new TransferIntegrityError(`${e.path}: пакет оборван раньше конца записи`)); return; }
            left -= c.length; streamPos += c.length;
            ctl.enqueue(c);
          },
        });
        const unpacked = source.pipeThrough(decompressor(enc, e, DecompressionStreamImpl, decoders)).getReader();
        await writeVerified({
          entry: e, openWritable: () => openWritable(e), discard: () => discard(e), onBytes,
          read: async () => { const { done, value } = await unpacked.read(); return done ? null : value; },
          cancel: (err) => unpacked.cancel(err),
        });
      } else {
        await writeVerified({
          entry: e, openWritable: () => openWritable(e), discard: () => discard(e), onBytes,
          read: async () => {
            if (left === 0) return null;
            const c = await cursor.read(left);
            if (!c) throw new TransferIntegrityError(`${e.path}: пакет оборван раньше конца записи`);
            left -= c.length; streamPos += c.length;
            return c;
          },
          cancel: () => {},
        });
      }
      if (left !== 0) throw new TransferIntegrityError(`${e.path}: запись прочитана не до конца`);
      onFile(e);
    }
  } catch (err) {
    if (reader) { try { await reader.cancel(err); } catch { /* ignore */ } }
    throw err;
  }
  if (reader) { try { await reader.cancel(); } catch { /* the rest of the range is not needed */ } }
}
