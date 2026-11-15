/* Язык игры и английский оверлей (E1, docs/overlay-e1.md, формат слоя — docs/english-layer.md раздел 1).

   Что здесь: (1) выбор языка (?lang=ru|en > localStorage `korsary2.lang` > русский), (2) СТРОГИЙ валидатор манифеста оверлея
   `game-en/manifest.json` (отказ ДО первой записи), (3) установка оверлея под тем же страничным SAVE-замком, что и базовая установка,
   (4) быстрая проверка полноты установленного оверлея перед запуском, (5) путь оверлея для хоста (PORT_OVERLAY).
   Оверлей — второй каталог OPFS рядом с базовым (`korsary2-game-en`), только файлы PROGRAM/ и RESOURCE/, у него свой манифест и своя
   метка установки `installed-en.json`. Базовая (русская) установка, её манифест, метка и SAVE этим модулем не затрагиваются.

   Нет браузерных зависимостей: хранилище, замки и сеть передаются параметрами (тот же код проверяется в Node и в настоящем Chromium). */
import { validateManifestFiles } from './save-protection.mjs';
import { validateManifestPacks } from './game-transfer.mjs';
import { LANG_SUFFIX, isLangRecord, key as nameKey, withSaveLock } from './save-export.mjs';
// Списки файлов слоя живут в ОДНОМ месте (overlay-required.json, E5): его же читают gamefiles.py и verify_dist.py, make_dist кладёт его в dist.
// Если файла нет/он не разбирается, модуль не загружается, а страница тогда не предлагает English (русский не страдает).
import REQUIRED_LISTS from './overlay-required.json' with { type: 'json' };

export const LANG_KEY = 'korsary2.lang';
export const LANGS = Object.freeze(['ru', 'en']);
/** Каталог OPFS оверлея = каталог базовой установки + суффикс; метка установки — свой файл в этом каталоге. */
export const OVERLAY_DIR_SUFFIX = '-en';
export const OVERLAY_MARKER = 'installed-en.json';
/** Где хост (main.c: wasmfs_create_directory("/opfs", ...)) видит корень OPFS. */
export const OPFS_MOUNT = '/opfs';
/** Файлы слоя из overlay-required.json: `required` — без любого из них английский режим не запускается (контракт E2, docs/english-layer.md 1.8);
 *  `recommended` — файлы слоя, отсутствие которых только предупреждение (озвучка, экраны, остальные тексты); `base_recommended` — файлы БАЗЫ,
 *  без которых английский режим даст смесь языков (проверка перед запуском, предупреждение). */
function listOf(data, key, { optional = false } = {}) {
  const v = data?.[key];
  if (v === undefined && optional) return Object.freeze([]);
  if (!Array.isArray(v) || (key === 'required' && !v.length) || v.some((p) => typeof p !== 'string' || overlayPathProblemEarly(p)))
    throw new Error(`overlay-required.json: поле ${key} не список допустимых путей`);
  if (new Set(v.map((p) => p.toLowerCase())).size !== v.length) throw new Error(`overlay-required.json: поле ${key} повторяет путь`);
  return Object.freeze([...v]);
}
// простая проверка пути до определения overlayPathProblem (ниже): без `.`/`..`, не пустой, без обратной косой, в PROGRAM/ или RESOURCE/
const overlayPathProblemEarly = (p) => !p || p.startsWith('/') || p.includes('\\') || p.split('/').some((x) => !x || x === '.' || x === '..') ||
  !/^(PROGRAM|RESOURCE)\/./.test(p);
if (REQUIRED_LISTS?.format !== 1) throw new Error('overlay-required.json: неизвестный формат');
export const OVERLAY_REQUIRED = listOf(REQUIRED_LISTS, 'required');
export const OVERLAY_RECOMMENDED = listOf(REQUIRED_LISTS, 'recommended', { optional: true });
export const OVERLAY_BASE_RECOMMENDED = listOf(REQUIRED_LISTS, 'base_recommended', { optional: true });
export const OVERLAY_LIMITS = Object.freeze({ maxFiles: 20000, maxTotalBytes: 4 * 1024 ** 3, maxPathBytes: 240, maxDepth: 20 });

const fail = (message) => { throw new OverlayError(message); };
export class OverlayError extends Error {
  constructor(message) { super(message); this.name = 'OverlayError'; }
}

/* ------------------------------------------------------------------ выбор языка */

export function normalizeLang(v) {
  const s = String(v ?? '').trim().toLowerCase();
  return s === 'ru' || s === 'en' ? s : null;
}

/** Язык страницы: адрес (?lang=ru|en) важнее запомненного, запомненное (localStorage[LANG_KEY]) важнее умолчания (русский).
 *  Незнакомое значение в адресе игнорируется (urlInvalid), недоступное/сломанное хранилище — тоже (storageError): русский по умолчанию. */
export function chooseLang({ search = '', storage = null } = {}) {
  let raw = null;
  try { raw = new URLSearchParams(search).get('lang'); } catch { /* неразборчивый адрес: как будто параметра нет */ }
  const fromUrl = normalizeLang(raw);
  const out = { lang: 'ru', source: 'default', stored: null, urlInvalid: raw !== null && raw !== '' && !fromUrl, storageError: null };
  try { out.stored = storage ? normalizeLang(storage.getItem(LANG_KEY)) : null; }
  catch (e) { out.storageError = String(e?.message || e); }
  if (fromUrl) { out.lang = fromUrl; out.source = 'url'; }
  else if (out.stored) { out.lang = out.stored; out.source = 'storage'; }
  return out;
}

/** Запоминает выбор игрока. false — хранилище недоступно (приватное окно, запрет): выбор живёт только до перезагрузки. */
export function rememberLang(storage, lang) {
  if (!normalizeLang(lang)) return false;
  try { storage.setItem(LANG_KEY, lang); return true; } catch { return false; }
}

export const overlayDirName = (baseDirName) => `${baseDirName}${OVERLAY_DIR_SUFFIX}`;
export const overlayHostPath = (baseDirName) => `${OPFS_MOUNT}/${overlayDirName(baseDirName)}`;

/* ------------------------------------------------------------------ язык слотов сохранений (E5) */

/** Метки языка слотов: хост пишет SAVE_META/<слот>.lang (ровно «en» или «ru») для слота, созданного в английском режиме. Слоты общие для обоих
 *  языков, но имена персонажей и строки внутри слота остаются на языке создания. Только чтение: ничего не создаётся и не пишется.
 *  Возвращает { slots: [имена файлов SAVE], labels: Map(ключ имени -> 'en'|'ru') }; нет каталога — пусто; нечитаемая или недопустимая метка — слот
 *  просто не помечен. */
export async function readSlotLanguages(gameRoot) {
  const out = { slots: [], labels: new Map() };
  if (!gameRoot?.getDirectoryHandle) return out;
  try {
    const save = await gameRoot.getDirectoryHandle('SAVE', { create: false });
    for await (const [name, handle] of save.entries()) if (handle.kind === 'file') out.slots.push(name);
  } catch { return out; }
  let meta;
  try { meta = await gameRoot.getDirectoryHandle('SAVE_META', { create: false }); } catch { return out; }
  try {
    for await (const [name, handle] of meta.entries()) {
      if (handle.kind !== 'file' || !name.endsWith(LANG_SUFFIX) || name.length === LANG_SUFFIX.length) continue;
      try {
        const file = await handle.getFile();
        if (file.size !== 2) continue;
        const bytes = new Uint8Array(await file.arrayBuffer());
        if (isLangRecord(bytes)) out.labels.set(nameKey(name.slice(0, -LANG_SUFFIX.length)), String.fromCharCode(bytes[0], bytes[1]));
      } catch { /* нечитаемая метка = нет метки */ }
    }
  } catch { /* каталог не перечислился: слоты остаются непомеченными */ }
  return out;
}

/** Что сказать игроку о языках слотов при выбранном языке `lang` ('ru' | 'en'). Не блокирует ничего: только текст. Слот без метки — «не помечен»
 *  (его язык неизвестен; в том числе текущий русский режим не ставит метку), а не «русский». */
export function summarizeSlotLanguages({ slots = [], labels = new Map() } = {}, lang = 'ru') {
  const want = lang === 'en' ? 'en' : 'ru';
  const s = { lang: want, total: slots.length, same: 0, other: 0, unmarked: 0, message: null };
  for (const name of slots) {
    const l = labels.get(nameKey(name));
    if (!l) s.unmarked++; else if (l === want) s.same++; else s.other++;
  }
  const parts = [];
  if (s.other && want === 'en') parts.push(`${s.other} of ${s.total} saves were created in another language; character names may appear in that language. Saves are shared between both languages and can be loaded; names retain the language used when the game was created.`);
  if (s.other && want !== 'en') parts.push(`Часть сохранений (${s.other} из ${s.total}) создана в другом языке; имена персонажей в них могут отображаться на другом языке. ` +
    'Сохранения общие для обоих языков: их можно загружать, имена внутри слота остаются такими, какими были при создании игры.');
  // Непомеченными могут быть как старые слоты, так и новые слоты русского режима.
  if (want === 'en' && s.unmarked) parts.push(`${s.unmarked} of ${s.total} saves have no language label. If created in Russian, their character names may remain Russian.`);
  if (parts.length) s.message = parts.join(' ');
  return s;
}

/* ------------------------------------------------------------------ строгий валидатор оверлея */

const FORBIDDEN_TOP = new Map([
  ['save', 'сохранения игрока'], ['save_meta', 'записи времени сохранений'], ['save_tx', 'журнал сохранений'],
  ['options', 'настройки игрока'], ['engine.ini', 'настройки движка'], ['engine.exe', 'исполняемый файл'], ['modules', 'модули игры'],
]);
const DEVICE_NAME = /^(con|prn|aux|nul|com[1-9]|lpt[1-9])(\..*)?$/i;
const JUNK_NAME = /^(thumbs\.db|desktop\.ini)$/i;
const BAD_CHARS = /[\x00-\x1f\x7f\\:*?"<>|]/u;
const HEX64 = /^[0-9a-f]{64}$/i;

/** Причина отказа для пути записи оверлея или null. Строже базового: только PROGRAM/ и RESOURCE/ (точное написание), всё остальное отказ,
 *  а не молчаливый пропуск. */
export function overlayPathProblem(path) {
  if (typeof path !== 'string' || !path) return 'путь не строка';
  if (new TextEncoder().encode(path).length > OVERLAY_LIMITS.maxPathBytes) return 'путь длиннее допустимого';
  if (path.startsWith('/')) return 'абсолютный путь';
  if (BAD_CHARS.test(path)) return 'в пути обратная косая черта, двоеточие, спецсимвол или управляющий символ';
  const parts = path.split('/');
  if (parts.some((p) => !p)) return 'пустой компонент пути';
  if (parts.some((p) => p === '.')) return 'компонент «.» в пути';
  if (parts.some((p) => p === '..')) return 'компонент «..» в пути (выход из корня оверлея)';
  if (parts.length > OVERLAY_LIMITS.maxDepth) return 'слишком глубокий путь';
  const top = parts[0].toLowerCase();
  if (FORBIDDEN_TOP.has(top)) return `${FORBIDDEN_TOP.get(top)} (${parts[0]}) в оверлей не входят`;
  if (parts[0] !== 'PROGRAM' && parts[0] !== 'RESOURCE')
    return top === 'program' || top === 'resource' ? 'верхний каталог должен называться PROGRAM или RESOURCE (регистр важен)'
      : 'путь вне PROGRAM/ и RESOURCE/';
  if (parts.length < 2) return 'файл должен лежать внутри PROGRAM/ или RESOURCE/';
  for (const p of parts) {
    if (p.startsWith('.')) return `скрытое имя «${p}»`;
    if (/[. ]$/.test(p)) return `имя «${p}» оканчивается точкой или пробелом`;
    if (DEVICE_NAME.test(p)) return `зарезервированное имя «${p}»`;
    if (JUNK_NAME.test(p)) return `служебное имя «${p}»`;
  }
  return null;
}

/** Проверка манифеста оверлея ДО любой записи. Бросает OverlayError с понятным текстом. Возвращает {files, packs, version, overlay, totalBytes}.
 *  opts: required (список обязательных файлов, по умолчанию OVERLAY_REQUIRED), baseManifest (манифест базовой установки: сверка
 *  overlay.base, «собран на другой русской раздаче»). Неизвестные ключи верхнего уровня игнорируются (формат расширяемый). */
export function validateOverlayManifest(manifest, { required = OVERLAY_REQUIRED, baseManifest = null } = {}) {
  if (!manifest || typeof manifest !== 'object' || Array.isArray(manifest)) fail('Манифест английского слоя повреждён (не объект); английский режим не запущен.');
  if (typeof manifest.version !== 'string' || !manifest.version) fail('В манифесте английского слоя нет версии.');
  if (!Array.isArray(manifest.files) || !manifest.files.length) fail('В манифесте английского слоя нет файлов.');
  if (manifest.files.length > OVERLAY_LIMITS.maxFiles) fail('В манифесте английского слоя слишком много файлов.');
  const seen = new Map(), dirs = new Set();
  let total = 0;
  for (const f of manifest.files) {
    if (!f || typeof f !== 'object' || Array.isArray(f)) fail('Запись манифеста английского слоя не объект.');
    const why = overlayPathProblem(f.path);
    if (why) fail(`Английский слой: «${String(f.path).slice(0, 120)}»: ${why}; установка отменена, ничего не записано.`);
    if (!Number.isSafeInteger(f.size) || f.size < 0) fail(`Английский слой: ${f.path}: некорректный размер; установка отменена.`);
    if (typeof f.sha256 !== 'string' || !HEX64.test(f.sha256)) fail(`Английский слой: ${f.path}: в манифесте нет SHA-256 (64 hex); установка отменена.`);
    const low = f.path.toLowerCase();
    if (seen.has(low)) fail(seen.get(low) === f.path ? `Английский слой: путь ${f.path} повторяется.` : `Английский слой: пути ${seen.get(low)} и ${f.path} различаются только регистром.`);
    seen.set(low, f.path);
    const parts = low.split('/');
    for (let i = 1; i < parts.length; i++) dirs.add(parts.slice(0, i).join('/'));
    total += f.size;
  }
  for (const low of seen.keys()) if (dirs.has(low)) fail(`Английский слой: ${seen.get(low)} одновременно файл и каталог.`);
  if (total > OVERLAY_LIMITS.maxTotalBytes) fail('Английский слой больше допустимого размера.');
  const files = validateManifestFiles(manifest.files);   // кодирования, csize, pack/offset: те же правила, что у базовой установки
  if (files.length !== manifest.files.length) fail('Английский слой: запись манифеста отброшена как данные игрока; установка отменена.');
  validateManifestPacks(files, manifest.packs);
  let overlay = null;
  if (manifest.overlay !== undefined) {
    const o = manifest.overlay;
    if (!o || typeof o !== 'object' || Array.isArray(o)) fail('Блок overlay манифеста английского слоя повреждён.');
    if (o.format !== 1) fail(`Формат английского слоя ${String(o.format)} не поддерживается этой страницей; обновите страницу игры.`);
    if (o.language !== undefined && typeof o.language !== 'string') fail('Блок overlay: язык не строка.');
    const base = o.base ?? {};
    if (typeof base !== 'object' || Array.isArray(base)) fail('Блок overlay: base не объект.');
    for (const [p, sha] of Object.entries(base)) {
      if (overlayPathProblem(p)) fail(`Блок overlay: недопустимый путь в base: ${p.slice(0, 120)}.`);
      if (typeof sha !== 'string' || !HEX64.test(sha)) fail(`Блок overlay: base[${p}] не SHA-256.`);
      if (!seen.has(p.toLowerCase())) fail(`Блок overlay: base[${p}] не файл оверлея.`);
    }
    if (baseManifest && Array.isArray(baseManifest.files) && Object.keys(base).length) {
      const have = new Map(baseManifest.files.map((e) => [String(e?.path).toLowerCase(), e]));
      for (const [p, sha] of Object.entries(base)) {
        const e = have.get(p.toLowerCase());
        if (!e || String(e.sha256 || '').toLowerCase() !== sha.toLowerCase())
          fail(`Английский слой собран на другой версии русской раздачи (${p} отличается); обновите английский слой или вернитесь к русскому языку.`);
      }
    }
    overlay = o;
  }
  const have = new Set(seen.keys());
  for (const r of required) if (!have.has(r.toLowerCase())) fail(`В английском слое нет обязательного файла ${r}; английский режим не запущен.`);
  return { files, packs: manifest.packs ?? null, version: manifest.version, overlay, totalBytes: total };
}

/* ------------------------------------------------------------------ установка под SAVE-замком */

/** Метка установленного оверлея: {version, at, ...} или null. Читается через `readMarker` (страница): ошибка чтения — исключение. */
const markerCurrent = (marker, version) => !!marker && marker.version === version;

/** Установка/обновление оверлея под тем же страничным замком, что и базовая (withSaveLock над КОРНЕМ БАЗЫ: `${rootName}:save-backup`;
 *  работающая игра держит его всю жизнь страницы, save-owner.mjs — тогда установка отказывает, а не гоняется с игрой). Порядок:
 *  метка без замка (если версия текущая, замок не нужен и не берётся), затем замок, метка ещё раз, `sync()`. Архив SAVE при этом НЕ
 *  делается: оверлей не касается SAVE. Возвращает {skipped:'current'} или {installed:true}. */
export async function installOverlayUnderSaveLock({ locks, rootName, version, readMarker, sync }) {
  if (typeof version !== 'string' || !version || typeof readMarker !== 'function' || typeof sync !== 'function' || typeof rootName !== 'string' || !rootName)
    fail('Некорректные параметры установки английского слоя.');
  if (markerCurrent(await readMarker(), version)) return { skipped: 'current' };
  return withSaveLock(locks, rootName, async () => {
    if (markerCurrent(await readMarker(), version)) return { skipped: 'current' };
    await sync();
    return { installed: true };
  });
}

/** Быстрая проверка полноты (без хэшей): каждый файл манифеста есть и имеет свой размер. Метка «завершено» этого не доказывает
 *  (хранилище могли почистить), а дешёвая проверка размеров ловит неполный слой до запуска. existingSize(dir, path) -> размер или -1. */
export async function verifyOverlayFiles({ dir, files, existingSize, concurrency = 8 }) {
  const missing = [], wrongSize = [];
  let next = 0;
  const lane = async () => {
    for (;;) {
      const i = next++;
      if (i >= files.length) return;
      const f = files[i], got = await existingSize(dir, f.path);
      if (got < 0) missing.push(f.path); else if (got !== f.size) wrongSize.push(f.path);
    }
  };
  await Promise.all(Array.from({ length: Math.max(1, Math.min(concurrency, files.length || 1)) }, lane));
  return { ok: !missing.length && !wrongSize.length, missing: missing.sort(), wrongSize: wrongSize.sort(), checked: files.length };
}

/** Текст отказа запуска английского режима по результату verifyOverlayFiles (с предложением вернуться к русскому). */
export function incompleteOverlayMessage(v) {
  const bad = [...v.missing, ...v.wrongSize];
  return `Английский слой неполон или повреждён (проблемных файлов: ${bad.length}, например ${bad.slice(0, 2).join(', ')}). Английский режим не запущен, ` +
    'русская установка не затронута. Вернитесь к русскому языку или переустановите английский слой.';
}
