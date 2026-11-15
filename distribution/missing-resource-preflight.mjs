/* Read-only проверка игровых ресурсов перед запуском игры (Ф3.1).
 *
 * Зачем. Отсутствие файла, который игра гарантированно откроет (например
 * RESOURCE/MODELS/Items/blade1.gm), приводит к C++-исключению GEOMETRY.dll
 * "can't open geometry file" и терминальному trap RaiseException: SEH-dispatch
 * в порте не включён (seh-session-report.md). Этот модуль не чинит причину, а
 * выявляет такую установку ДО запуска игрового рантайма и даёт читаемый отказ
 * с кодом вместо аварии.
 *
 * Источник ожидаемых значений. Размеры и SHA-256 берутся только из манифеста
 * установки (game/manifest.json, тот же объект, по которому port.js выполнил
 * resync), а не из данных на диске. Доверие к манифесту равно доверию к origin,
 * который отдаёт саму страницу и game.wasm: это защита от потери, обрезки и
 * порчи локальных файлов в OPFS, а не от враждебного сервера. Согласованность
 * манифеста проверяется по контракту `version` (gamefiles.py: sha1 от
 * "path:size:sha256;" по отсортированным записям); несогласованный манифест не
 * используется для размеров и хешей. Без пригодного манифеста (офлайн, установка
 * через выбор папки, версия манифеста не равна версии установки) выполняется
 * только проверка наличия обязательных файлов.
 *
 * Что модуль НЕ делает: ничего не создаёт, не пишет и не удаляет (все
 * дескрипторы открываются только на чтение; тесты запрещают create:true и любые
 * write-методы), не трогает SAVE, SAVE_META, options и маркер установки, не
 * исполняет SEH, не исправляет файлы. Проверка точна только на момент чтения.
 *
 * Классы защиты (подробности и ограничения — missing-resource-preflight/README.md):
 *   fatal  — отсутствие/нечитаемость блокирует запуск: исполняемый файл игры,
 *            обязательные файлы port.json (кроме изменяемого `options`), модели
 *            blade1.gm/blade6.gm, для которых падение подтверждено
 *            (docs/missing-item-models.md), и музыка RESOURCE/Sounds/MUSIC/*.ogg,
 *            которую запрашивают скрипты (KNOWN_MUSIC_PATHS; docs/loading-screens-and-music-r1.md:
 *            SoundService при неудачном открытии Ogg бросает C++-исключение, а в порте оно
 *            терминально; наблюдалось для Coridor.ogg);
 *   check  — остальные модели RESOURCE/MODELS/Items/*.gm, текстуры
 *            RESOURCE/Textures/Items/* и прочие *.ogg каталога MUSIC (алиасы, на которые
 *            скрипты не ссылаются, и неупомянутые файлы): только предупреждение;
 *   несовпадение размера или SHA у любого файла — только предупреждение, так как
 *   падение игры от повреждённого, но существующего файла не доказано.
 *
 * Английский слой (E5, docs/english-layer.md, раздел «E5»). В английском режиме страница дополнительно вызывает checkOverlayBeforeRun
 * ДО замков и запуска: слой (каталог korsary2-game-en, список файлов — валидированный манифест слоя или метка установки) читается так же,
 * только на чтение. Fail-closed (отказ английского режима, русский остаётся доступным) только там, где игра гарантированно получила бы
 * смесь языков или падение: нет/нечитаем/не тот размер или SHA обязательного файла слоя (overlay-required.json: language.ini, fonts.ini,
 * тексты, Characters_names.c) и language.ini слоя, в котором активный defaultLanguage не English (игра осталась бы русской под английской
 * надписью). Предупреждение: файлы слоя «recommended» (озвучка приветствий, экраны, остальные тексты) и файлы БАЗЫ, нужные английскому
 * (TEXTS/ENGLISH/*, латинский заголовочный шрифт). Сбой самой проверки запуск не блокирует; русский режим выполняет прежний код.
 */

const HEX64 = /^[0-9a-f]{64}$/;
const HEX12 = /^[0-9a-f]{12}$/;

/** Модели, отсутствие которых воспроизведённо роняет игру (GEOMETRY.dll бросает
 * исключение при неудачном open; blade1 — стартовая каюта, blade6 — туториал и
 * случайные встречи; см. docs/missing-item-models.md, PORTING_LOG.md). */
export const KNOWN_CRASH_PATHS = Object.freeze([
  'RESOURCE/MODELS/Items/blade1.gm',
  'RESOURCE/MODELS/Items/blade6.gm',
]);

const gmPaths = (dir, names) => names.map((n) => `RESOURCE/MODELS/${dir}/${n}`);

/** Все модели предметов из таблицы PROGRAM/ITEMS/initItems.c (itm.model, folder по умолчанию items; плюс items-модели
 * локаций: Labirint_3 b1). Не вошли 5 файлов каталога без ссылок из скриптов (adrenaline, door, elixir, sqitem, stonemap):
 * для них CHECK_RULES. Имена как на диске (поиск без учёта регистра). Сверяется с missing-resource-preflight/audit_refs.mjs. */
export const KNOWN_ITEM_MODELS = Object.freeze(gmPaths('Items', [
  'Antidote.gm', 'Balsam.gm', 'Diamond.gm', 'Emerald.gm', 'PearlBig.gm', 'PearlSmall.gm', 'PotionBig.gm', 'Purse.gm',
  'PurseL.gm', 'PurseM.gm', 'Ruby.gm', 'Sapphire.gm', 'b1.gm', 'blade1.gm', 'blade10.gm', 'blade11.gm', 'blade12.gm',
  'blade13.gm', 'blade14.gm', 'blade15.gm', 'blade16.gm', 'blade17.gm', 'blade18.gm', 'blade19.gm', 'blade2.gm',
  'blade20.gm', 'blade21.gm', 'blade22.gm', 'blade23.gm', 'blade3.gm', 'blade4.gm', 'blade5.gm', 'blade6.gm',
  'blade7.gm', 'blade8.gm', 'blade9.gm', 'pistol1.gm', 'pistol2.gm', 'pistol3.gm', 'pistol4.gm', 'pistol5.gm',
  'pistol6.gm', 'potion.gm', 'spyglass4.gm', 'stat1.gm',
]));

/** Модели оружия в руке: у каждого предмета группы BLADE/GUN в таблице предметов есть одноимённая MODELS/Ammo/<model>.gm
 * (трасса: Ammo/blade20.gm открывается при старте новой игры у Малкольма). */
export const KNOWN_AMMO_MODELS = Object.freeze(gmPaths('Ammo', [
  'blade1.gm', 'blade10.gm', 'blade11.gm', 'blade12.gm', 'blade13.gm', 'blade14.gm', 'blade15.gm', 'blade16.gm',
  'blade17.gm', 'blade18.gm', 'blade19.gm', 'blade2.gm', 'blade20.gm', 'blade21.gm', 'blade22.gm', 'blade23.gm',
  'blade3.gm', 'blade4.gm', 'blade5.gm', 'blade6.gm', 'blade7.gm', 'blade8.gm', 'blade9.gm', 'pistol1.gm',
  'pistol2.gm', 'pistol3.gm', 'pistol4.gm', 'pistol5.gm', 'pistol6.gm',
]));

/** Модели (кроме Items/Ammo), которые игра открывает от запуска до диалога с Малкольмом в туториале: журнал открытий
 * Node-сборки на клоне игры (missing-resource-preflight/dynamic, опыт M00/B00: `[file] CreateFileA(...) = ok`).
 * Отсутствие любой из них в клоне давало RaiseException e06d7363 (опыты M02, M03, M04, M06, M07, M13, M14). */
export const KNOWN_STARTUP_MODELS = Object.freeze([
  'RESOURCE/MODELS/Characters/Blaze.gm', 'RESOURCE/MODELS/Characters/bocman3.gm', 'RESOURCE/MODELS/Heads/h_bocman3.gm',
  'RESOURCE/MODELS/Islands/Conceicao/Conceicao_locators.gm', 'RESOURCE/MODELS/Islands/Douwesen/Douwesen_locators.gm',
  'RESOURCE/MODELS/Islands/FalaiseDeFleur/FalaisedeFleur_locators.gm', 'RESOURCE/MODELS/Islands/IslaMuelle/IslaMuelle_locators.gm',
  'RESOURCE/MODELS/Islands/KhaelRoa/KhaelRoa_locators.gm', 'RESOURCE/MODELS/Islands/Oxbay/Oxbay_locators.gm',
  'RESOURCE/MODELS/Islands/QuebradasCostillas/QuebradasCostillas_locators.gm', 'RESOURCE/MODELS/Islands/Redmond/Redmond_locators.gm',
  'RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck.gm', 'RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck_fd.gm',
  'RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck_l.gm', 'RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck_w.gm',
  'RESOURCE/MODELS/fish01.gm', 'RESOURCE/MODELS/seagull.gm',
]);

/** Все .gm, отсутствие которых блокирует запуск (проверка наличия и заголовка). */
export const KNOWN_GM_PATHS = Object.freeze([...KNOWN_ITEM_MODELS, ...KNOWN_AMMO_MODELS, ...KNOWN_STARTUP_MODELS]);

/** Заголовок .gm, который принимает GEOMETRY.dll (f_006e1d70: первое слово заголовка из 0x48 байт == 0x312e3035, то есть
 * ASCII "50.1"); иначе исключение "invalid version". Файл короче заголовка тоже не проходит (опыты M08, M10; M09: заголовок без
 * данных даёт "memory access out of bounds"). У sky/sphere/light.gm другие версии ("20.1", "10.1") — их грузит не этот код. */
export const GM_MAGIC = '50.1';
export const GM_HEADER_BYTES = 0x48;

/** Музыка, которую игра может открыть: Coridor.ogg жёстко в mainmenu.c (`SetMusic("music\\Coridor.ogg")`), остальные —
 * все файлы алиасов `music_*` из RESOURCE/INI/ALIASES/music_alias.ini, которые вызываются из PROGRAM/sound.c
 * (SetMusicAlarm/SetMusic/PlayStereoOGG; имя из алиаса выбирается случайно из всех перечисленных). Имена — как на диске
 * (поиск без учёта регистра: в алиасах `Main_Theme`, `Sea_battle01`, на диске `Main_theme`, `Sea_Battle01`).
 * Все 24 есть в раздаче. Отсутствие любого — то же исключение при открытии Ogg, которое остановило процесс
 * для Coridor.ogg (soundservice-diagnostic/README.md): путь кода открытия у всех один (MP3StereoSound,
 * AMP3Coded.cpp), поэтому прямое наблюдение для одного файла распространено на остальные по коду. Алиасы без вызова
 * из PROGRAM (music_main_theme, music_final_theme, music_shipyard, music_enplavanie, music_abordage, music_victory,
 * music_death) и неупомянутые файлы сюда НЕ входят — для них только предупреждение (CHECK_RULES, label 'music'). */
export const KNOWN_MUSIC_PATHS = Object.freeze([
  'Bitva1', 'Bitva2', 'Cave_or_Dungeon_Walking', 'Church_Theme', 'Coridor', 'End_storm', 'Enplavanie', 'Gorod-1',
  'Governors_Theme', 'Gubernator', 'Jungle', 'Jungle_Shore_Exploration', 'Sailing01', 'Sea_Battle01', 'Sea_Battle02',
  'Sea_Battle03', 'Ship_dead', 'Ship_victory01', 'Ship_victory03', 'Sobor', 'Spokplavanie', 'Storm', 'Taverna',
  'Town_Exploration02',
].map((n) => `RESOURCE/Sounds/MUSIC/${n}.ogg`));

/** Файлы, которые игра или игрок могут менять: сверяется только наличие. */
export const MUTABLE_PATHS = Object.freeze(['options', 'engine.ini']);

/** Классы "check": префикс (нижний регистр), необязательный суффикс. */
export const CHECK_RULES = Object.freeze([
  Object.freeze({ prefix: 'resource/models/items/', suffix: '.gm', label: 'item-model' }),
  Object.freeze({ prefix: 'resource/textures/items/', suffix: '', label: 'item-texture' }),
  // музыка, на которую скрипты не ссылаются (и обрезка/подмена любой музыки): размер без хеша (десятки МБ на каждый запуск не читаются)
  Object.freeze({ prefix: 'resource/sounds/music/', suffix: '.ogg', label: 'music', sizeOnly: true }),
  // все прочие модели манифеста: только наличие по списку каталога, без getFile (в манифесте ~2000 .gm; чтение не нужно)
  Object.freeze({ prefix: 'resource/models/', suffix: '.gm', label: 'model', listOnly: true }),
]);

export const LIMITS = Object.freeze({
  maxManifestFiles: 1_000_000,   // записей манифеста, которые вообще разбираются
  maxProtected: 5000,            // файлов, которые проверяются за вызов
  maxHashFileBytes: 8 * 1024 * 1024,
  maxHashTotalBytes: 64 * 1024 * 1024,
  maxWarnFindings: 500,          // предупреждений в отчёте (счётчики точны всегда)
});

/** Коды: RES_* относятся к файлу, PF_* — к самой проверке. */
export const CODES = Object.freeze({
  RES_MISSING: 'RES_MISSING',
  RES_UNREADABLE: 'RES_UNREADABLE',
  RES_NOT_FILE: 'RES_NOT_FILE',
  RES_SIZE_MISMATCH: 'RES_SIZE_MISMATCH',
  RES_HASH_MISMATCH: 'RES_HASH_MISMATCH',
  RES_CHANGED: 'RES_CHANGED',
  RES_AMBIGUOUS_CASE: 'RES_AMBIGUOUS_CASE',
  RES_BAD_HEADER: 'RES_BAD_HEADER',
  RES_BAD_CONTENT: 'RES_BAD_CONTENT',
  PF_NO_MANIFEST: 'PF_NO_MANIFEST',
  PF_MANIFEST_INVALID: 'PF_MANIFEST_INVALID',
  PF_MANIFEST_INCONSISTENT: 'PF_MANIFEST_INCONSISTENT',
  PF_MANIFEST_UNVERIFIED: 'PF_MANIFEST_UNVERIFIED',
  PF_MANIFEST_AMBIGUOUS: 'PF_MANIFEST_AMBIGUOUS',
  PF_MANIFEST_ENTRY_INVALID: 'PF_MANIFEST_ENTRY_INVALID',
  PF_VERSION_MISMATCH: 'PF_VERSION_MISMATCH',
  PF_NO_HASH: 'PF_NO_HASH',
  PF_LIMITS: 'PF_LIMITS',
  PF_INTERNAL: 'PF_INTERNAL',
});

const asciiLower = (s) => s.replace(/[A-Z]/g, (c) => String.fromCharCode(c.charCodeAt(0) + 32));
const hex = (buf) => [...new Uint8Array(buf)].map((x) => x.toString(16).padStart(2, '0')).join('');
const errName = (e) => (e && typeof e.name === 'string' && e.name) || 'Error';

function safePath(p) {
  return typeof p === 'string' && p.length > 0 && p.length <= 1024 && !p.includes('\\') &&
    !/[\x00-\x1f\x7f]/u.test(p) && !p.startsWith('/') &&
    p.split('/').every((part) => part && part !== '.' && part !== '..');
}

async function defaultSha256(bytes) {
  const subtle = globalThis.crypto?.subtle;
  if (!subtle) throw new Error('no WebCrypto');
  return hex(await subtle.digest('SHA-256', bytes));
}
async function defaultSha1(bytes) {
  const subtle = globalThis.crypto?.subtle;
  if (!subtle) throw new Error('no WebCrypto');
  return hex(await subtle.digest('SHA-1', bytes));
}

/** Контракт `version` манифеста (gamefiles.manifest_for / verify_dist.manifest_version). */
export async function manifestVersionDigest(files, sha1 = defaultSha1) {
  const sorted = [...files].sort((a, b) => (a.path < b.path ? -1 : a.path > b.path ? 1 : 0));
  const joined = sorted.map((e) => `${e.path}:${e.size}:${e.sha256};`).join('');
  return (await sha1(new TextEncoder().encode(joined))).slice(0, 12);
}

// ---------------------------------------------------------------- manifest trust

async function assessManifest(manifest, installedVersion, add, sha1) {
  const none = (level) => ({ level, usable: false, files: [], version: null });
  if (manifest === null || manifest === undefined) {
    add('info', CODES.PF_NO_MANIFEST, null, 'манифест установки недоступен (офлайн или установка из папки)');
    return none('absent');
  }
  if (typeof manifest !== 'object' || typeof manifest.version !== 'string' || !manifest.version ||
      !Array.isArray(manifest.files)) {
    add('warn', CODES.PF_MANIFEST_INVALID, null, 'манифест имеет неверную структуру');
    return none('invalid');
  }
  const version = manifest.version;
  if (manifest.files.length > LIMITS.maxManifestFiles) {
    add('warn', CODES.PF_LIMITS, null, `в манифесте больше ${LIMITS.maxManifestFiles} записей`);
    return { ...none('invalid'), version };
  }
  const files = [];
  let badEntries = 0;
  for (const e of manifest.files) {
    if (e && typeof e === 'object' && typeof e.path === 'string' && Number.isSafeInteger(e.size) && e.size >= 0)
      files.push(e);
    else badEntries++;
  }
  if (badEntries) add('warn', CODES.PF_MANIFEST_ENTRY_INVALID, null, `записей манифеста с неверным форматом: ${badEntries}`);
  if (installedVersion !== version) {
    add('warn', CODES.PF_VERSION_MISMATCH, null,
      `версия установки (${installedVersion ?? 'нет маркера'}) не равна версии манифеста (${version}); хеши не сверяются`);
    return { level: 'stale', usable: false, files, version };
  }
  if (HEX12.test(version)) {
    let digest = null;
    try {
      // Digest only when every entry carries a hash; a legacy list without one cannot be verified.
      if (files.every((e) => typeof e.sha256 === 'string')) digest = await manifestVersionDigest(files, sha1);
    } catch { /* no WebCrypto: stays unverified below */ }
    if (digest !== null && digest !== version) {
      add('warn', CODES.PF_MANIFEST_INCONSISTENT, null,
        `version манифеста (${version}) не совпадает с вычисленным (${digest}); размеры и хеши не используются`);
      return { level: 'inconsistent', usable: false, files, version };
    }
    if (digest === version) return { level: 'verified', usable: true, files, version };
  }
  add('info', CODES.PF_MANIFEST_UNVERIFIED, null, 'версия манифеста не поддаётся проверке согласованности');
  return { level: 'unverified', usable: true, files, version };
}

// ---------------------------------------------------------------- plan

function buildPlan({ manifest, exe, required, add }) {
  const byLower = new Map();
  let rejected = 0;
  if (manifest.usable) {
    for (const e of manifest.files) {
      if (!safePath(e.path)) { rejected++; continue; }
      const k = asciiLower(e.path);
      if (!byLower.has(k)) byLower.set(k, []);
      byLower.get(k).push(e);
    }
    if (rejected) add('warn', CODES.PF_MANIFEST_ENTRY_INVALID, null, `записей манифеста с небезопасным путём пропущено: ${rejected}`);
  }
  const plan = [];
  const seen = new Set();
  const fatalSpecs = [];
  if (typeof exe === 'string' && exe) fatalSpecs.push({ path: exe, why: 'required' });
  for (const r of required || []) if (typeof r === 'string' && r) fatalSpecs.push({ path: r, why: 'required' });
  for (const p of KNOWN_CRASH_PATHS) fatalSpecs.push({ path: p, why: 'crash-known', gm: true });
  for (const p of KNOWN_GM_PATHS) fatalSpecs.push({ path: p, why: 'crash-gm', gm: true });
  for (const p of KNOWN_MUSIC_PATHS) fatalSpecs.push({ path: p, why: 'crash-music', sizeOnly: true });
  for (const spec of fatalSpecs) {
    const lower = asciiLower(spec.path);
    if (!safePath(spec.path)) continue;
    const mutable = MUTABLE_PATHS.includes(lower);
    if (seen.has(lower)) {
      // crash-known is the stronger statement for the report
      const prev = plan.find((x) => asciiLower(x.path) === lower);
      if (spec.why === 'crash-known') prev.why = 'crash-known';
      if (spec.gm) prev.gm = true;
      continue;
    }
    seen.add(lower);
    const found = byLower.get(lower) || [];
    let item;
    if (mutable) {
      // options is user data, engine.ini may be rewritten: only presence is compared.
      // The fatal class applies to engine.ini but not to options (see README).
      item = { path: found.length === 1 ? found[0].path : spec.path, cls: lower === 'options' ? 'check' : 'fatal',
        why: spec.why, expected: null, inManifest: manifest.usable ? found.length >= 1 : null, mutable: true };
    } else if (found.length === 1) {
      item = { path: found[0].path, cls: 'fatal', why: spec.why, expected: found[0], inManifest: true, mutable: false };
    } else {
      if (found.length > 1) add('warn', CODES.PF_MANIFEST_AMBIGUOUS, spec.path, 'несколько записей манифеста с этим путём без учёта регистра');
      item = { path: spec.path, cls: 'fatal', why: spec.why, expected: null,
        inManifest: manifest.usable ? false : null, mutable: false };
    }
    if (spec.sizeOnly) item.sizeOnly = true;
    if (spec.gm) item.gm = true;
    plan.push(item);
  }
  if (manifest.usable) {
    const checks = [];
    for (const [lower, list] of byLower) {
      if (seen.has(lower)) continue;
      const rule = CHECK_RULES.find((r) => lower.startsWith(r.prefix) && lower.length > r.prefix.length && lower.endsWith(r.suffix));
      if (!rule) continue;
      if (list.length !== 1) { add('warn', CODES.PF_MANIFEST_AMBIGUOUS, list[0].path, 'несколько записей манифеста с этим путём без учёта регистра'); continue; }
      checks.push({ path: list[0].path, cls: 'check', why: rule.label, expected: list[0], inManifest: true, mutable: false,
        ...(rule.sizeOnly ? { sizeOnly: true } : {}), ...(rule.listOnly ? { listOnly: true } : {}) });
    }
    checks.sort((a, b) => (a.path < b.path ? -1 : a.path > b.path ? 1 : 0));
    plan.push(...checks);
  }
  if (plan.length > LIMITS.maxProtected) {
    add('warn', CODES.PF_LIMITS, null, `проверяемых файлов ${plan.length}; проверены первые ${LIMITS.maxProtected}`);
    plan.length = LIMITS.maxProtected;
  }
  return plan;
}

// ---------------------------------------------------------------- directory access (read-only)

async function listDir(dir, key, cache) {
  if (cache.has(key)) return cache.get(key);
  let list = null;
  if (typeof dir.entries === 'function') {
    list = [];
    for await (const [name, handle] of dir.entries()) list.push([name, handle]);
  }
  cache.set(key, list);
  return list;
}

/** Resolves one path like the guest does (host/core.c map_path): exact name first,
 * otherwise a single ASCII case-insensitive match. Returns {handle} or {status}. */
async function resolvePath(root, path, cache) {
  const parts = path.split('/');
  let dir = root;
  let note = null;
  for (let i = 0; i < parts.length; i++) {
    const want = parts[i];
    const last = i === parts.length - 1;
    const kind = last ? 'file' : 'directory';
    const key = parts.slice(0, i).join('/');
    let list;
    try { list = await listDir(dir, key, cache); }
    catch (e) { return { status: 'unreadable', detail: errName(e) }; }
    let handle = null;
    if (list === null) {
      try { handle = await (last ? dir.getFileHandle(want, { create: false }) : dir.getDirectoryHandle(want, { create: false })); }
      catch (e) {
        if (errName(e) === 'NotFoundError') return { status: 'missing' };
        if (errName(e) === 'TypeMismatchError') return { status: 'not_file', detail: errName(e) };
        return { status: 'unreadable', detail: errName(e) };
      }
    } else {
      const lowerWant = asciiLower(want);
      const same = list.filter(([n]) => asciiLower(n) === lowerWant);
      const ofKind = same.filter(([, h]) => h?.kind === kind);
      const exact = ofKind.find(([n]) => n === want);
      if (exact) {
        handle = exact[1];
        if (ofKind.length > 1) note = `варианты имени: ${ofKind.map(([n]) => n).sort().join(', ')}`;
      } else if (ofKind.length === 1) {
        handle = ofKind[0][1];
      } else if (ofKind.length > 1) {
        return { status: 'ambiguous', detail: ofKind.map(([n]) => n).sort().join(', ') };
      } else if (same.length) {
        return { status: 'not_file', detail: `${want} имеет другой тип` };
      } else {
        // An exact-case sibling was followed but the rest is absent while other spellings
        // exist: the guest may have picked one of those, so this is not a proven absence.
        return note ? { status: 'ambiguous', detail: note } : { status: 'missing' };
      }
    }
    if (last) return { handle, note };
    dir = handle;
  }
  return { status: 'missing' };
}

async function inspectItem(root, rootError, item, ctx) {
  const base = { path: item.path, cls: item.cls, why: item.why };
  if (!root) return { ...base, result: rootError === 'NotFoundError' ? 'missing' : 'unreadable', detail: rootError };
  const r = await resolvePath(root, item.path, ctx.cache);
  if (!r.handle) return { ...base, result: r.status, detail: r.detail ?? null };
  if (item.listOnly) return { ...base, result: 'ok', verified: 'presence', detail: r.note ?? null, ...(r.note ? { aliases: true } : {}) };   // без getFile
  let file;
  try { file = await r.handle.getFile(); }
  catch (e) {
    const n = errName(e);
    return { ...base, result: n === 'NotFoundError' ? 'missing' : n === 'TypeMismatchError' ? 'not_file' : 'unreadable', detail: n };
  }
  const out = { ...base, result: 'ok', actualSize: file.size, detail: r.note ?? null };
  if (r.note) out.aliases = true;
  if (typeof item.verify === 'function') {
    // содержимое небольшого файла, от которого зависит язык (language.ini слоя): проверяется независимо от манифеста
    if (file.size > MAX_VERIFY_BYTES) { out.result = 'content'; out.detail = `размер ${file.size} не похож на этот файл`; return out; }
    let raw;
    try { raw = new Uint8Array(await file.arrayBuffer()); }
    catch (e) { return { ...out, result: 'unreadable', detail: errName(e) }; }
    const problem = item.verify(raw);
    if (problem) { out.result = 'content'; out.detail = problem; return out; }
  }
  if (item.gm) {
    // GEOMETRY.dll бросает исключение при версии заголовка не "50.1" и при файле короче заголовка (GM_MAGIC): проверяется
    // независимо от манифеста, поэтому и в presence-only. Читаются только первые 4 байта.
    let bad = null;
    if (file.size < GM_HEADER_BYTES) bad = `размер ${file.size} < ${GM_HEADER_BYTES}`;
    else if (typeof file.slice === 'function') {
      let head;
      try { head = new Uint8Array(await file.slice(0, 4).arrayBuffer()); }
      catch (e) { return { ...out, result: 'unreadable', detail: errName(e) }; }
      const got = String.fromCharCode(...head);
      if (got !== GM_MAGIC) bad = `версия заголовка ${JSON.stringify(got)} вместо ${JSON.stringify(GM_MAGIC)}`;
    }
    if (bad) { out.result = 'header'; out.detail = bad; return out; }
  }
  const exp = item.expected;
  if (!exp || item.mutable) { out.verified = 'presence'; return out; }
  if (file.size !== exp.size) { out.result = 'size'; out.expectedSize = exp.size; return out; }
  if (item.sizeOnly) { out.verified = 'size'; return out; }   // музыка: десятки МБ, содержимое не читается
  const sha = typeof exp.sha256 === 'string' && HEX64.test(exp.sha256) ? exp.sha256 : null;
  if (!sha) { out.verified = 'size'; out.detail = exp.sha256 === undefined ? null : 'sha256 записи манифеста неверного формата'; return out; }
  if (file.size > LIMITS.maxHashFileBytes || ctx.hashed + file.size > LIMITS.maxHashTotalBytes) { out.verified = 'size'; ctx.skippedHash++; return out; }
  let bytes;
  try { bytes = await file.arrayBuffer(); }
  catch (e) { return { ...out, result: 'unreadable', detail: errName(e) }; }
  if (bytes.byteLength !== file.size) return { ...out, result: 'changed' };
  let digest;
  try { digest = await ctx.sha256(bytes); }
  catch { ctx.noHash = true; out.verified = 'size'; return out; }
  ctx.hashed += file.size; ctx.hashedFiles++;
  if (digest !== sha) { out.result = 'hash'; out.expectedSize = exp.size; return out; }
  out.verified = 'hash';
  return out;
}

const RESULT_CODE = {
  missing: CODES.RES_MISSING, unreadable: CODES.RES_UNREADABLE, not_file: CODES.RES_NOT_FILE,
  size: CODES.RES_SIZE_MISMATCH, hash: CODES.RES_HASH_MISMATCH, changed: CODES.RES_CHANGED,
  ambiguous: CODES.RES_AMBIGUOUS_CASE, header: CODES.RES_BAD_HEADER, content: CODES.RES_BAD_CONTENT,
};
const MAX_VERIFY_BYTES = 64 * 1024;
// What stops the start: only "the game cannot open this file" in the fatal class (a .gm with a header GEOMETRY.dll rejects counts too).
const BLOCKING_RESULTS = new Set(['missing', 'unreadable', 'not_file', 'header']);

/** Основная проверка. `openGameDir()` возвращает корень игры (FileSystemDirectoryHandle)
 * и обязан открывать его без create. Возвращает структурированный отчёт; исключения
 * бросает только при неверных аргументах программиста. */
export async function preflightResources(opts = {}) {
  const { openGameDir, manifest = null, installedVersion = null, exe = 'ENGINE.exe', required = [] } = opts;
  if (typeof openGameDir !== 'function') throw new TypeError('openGameDir обязателен');
  const sha256 = typeof opts.sha256 === 'function' ? opts.sha256 : defaultSha256;
  const sha1 = typeof opts.sha1 === 'function' ? opts.sha1 : defaultSha1;
  const t0 = typeof performance !== 'undefined' ? performance.now() : 0;
  const findings = [];
  let warnDropped = 0;
  let warnKept = 0;
  const push = (f) => {
    if (f.severity === 'warn') {
      if (warnKept >= LIMITS.maxWarnFindings) { warnDropped++; return; }
      warnKept++;
    }
    findings.push(f);
  };
  const add = (severity, code, path, detail) => push({ severity, code, path: path ?? null, detail: detail ?? null });
  const trust = await assessManifest(manifest, installedVersion, add, sha1);
  const plan = buildPlan({ manifest: trust, exe, required, add });
  let root = null, rootError = null;
  try { root = await openGameDir(); } catch (e) { rootError = errName(e); }
  if (root === undefined || root === null) { root = null; rootError ??= 'NotFoundError'; }
  const ctx = { cache: new Map(), hashed: 0, hashedFiles: 0, skippedHash: 0, noHash: false, sha256 };
  const items = [];
  const counts = { planned: plan.length, fatalClass: plan.filter((p) => p.cls === 'fatal').length };
  let ok = 0;
  for (const item of plan) {
    let r;
    try { r = await inspectItem(root, rootError, item, ctx); }
    catch (e) { r = { path: item.path, cls: item.cls, why: item.why, result: 'unreadable', detail: errName(e) }; }
    items.push(r);
    if (r.result === 'ok') {
      ok++;
      if (r.aliases) add('warn', CODES.RES_AMBIGUOUS_CASE, r.path, r.detail);
      continue;
    }
    const severity = item.cls === 'fatal' && (item.blocking ?? BLOCKING_RESULTS).has(r.result) ? 'fatal' : 'warn';
    const f = { severity, code: RESULT_CODE[r.result], path: r.path, detail: r.detail ?? null, why: item.why };
    if (r.expectedSize !== undefined) { f.expectedSize = r.expectedSize; f.actualSize = r.actualSize; }
    if (item.inManifest === false) f.inManifest = false;
    push(f);
  }
  if (ctx.noHash) add('warn', CODES.PF_NO_HASH, null, 'WebCrypto недоступен: хеши не проверены, только размеры');
  counts.ok = ok;
  counts.fatal = findings.filter((f) => f.severity === 'fatal').length;
  counts.warn = findings.filter((f) => f.severity === 'warn').length + warnDropped;
  counts.hashedFiles = ctx.hashedFiles;
  counts.hashedBytes = ctx.hashed;
  const status = findings.some((f) => f.severity === 'fatal') ? 'blocked'
    : findings.some((f) => f.severity === 'warn') || warnDropped ? 'warn' : 'ok';
  return {
    schema: 1,
    status,
    mode: trust.usable ? 'verified' : 'presence-only',
    trust: { level: trust.level, manifestVersion: trust.version, installedVersion: installedVersion ?? null },
    counts,
    findings,
    warningsDropped: warnDropped,
    items,
    stats: { elapsedMs: typeof performance !== 'undefined' ? Math.round(performance.now() - t0) : 0,
      skippedHashFiles: ctx.skippedHash },
  };
}

// ---------------------------------------------------------------- user message

const RES_TEXT = {
  RES_MISSING: 'файл не найден',
  RES_UNREADABLE: 'файл не удалось открыть или прочитать',
  RES_NOT_FILE: 'на месте файла находится каталог',
  RES_SIZE_MISMATCH: 'размер не совпадает с манифестом установки (файл мог быть обрезан)',
  RES_HASH_MISMATCH: 'содержимое не совпадает с манифестом установки',
  RES_CHANGED: 'файл изменился во время проверки',
  RES_AMBIGUOUS_CASE: 'в каталоге есть несколько файлов, различающихся только регистром имени',
  RES_BAD_HEADER: 'файл модели повреждён: заголовок не распознан (пустой, обрезанный или другой формат)',
  RES_BAD_CONTENT: 'содержимое файла не то, что нужно этому режиму',
  PF_NO_MANIFEST: 'манифест установки недоступен',
  PF_MANIFEST_INVALID: 'манифест установки повреждён',
  PF_MANIFEST_INCONSISTENT: 'манифест установки не согласован со своей версией',
  PF_MANIFEST_UNVERIFIED: 'согласованность манифеста не проверена',
  PF_MANIFEST_AMBIGUOUS: 'неоднозначная запись манифеста',
  PF_MANIFEST_ENTRY_INVALID: 'в манифесте есть записи неверного формата',
  PF_VERSION_MISMATCH: 'версия установки не совпадает с манифестом',
  PF_NO_HASH: 'хеши недоступны',
  PF_LIMITS: 'превышен предел проверки',
  PF_INTERNAL: 'проверка ресурсов завершилась внутренней ошибкой',
};
const SAVE_NOTE = 'Сохранения и настройки не затронуты: проверка только читает файлы.';
const REPAIR_NOTE = 'Автоматического восстановления файлов пока нет: скачайте сохранения на главном экране ' +
  '(«Скачать сохранения») и переустановите игровые файлы. Очистка данных сайта удалит и сохранения.';

/** Короткий русский текст и решение для интерфейса. */
export function describeReport(report) {
  const fatal = report.findings.filter((f) => f.severity === 'fatal');
  const warns = report.findings.filter((f) => f.severity === 'warn');
  const line = (f) => `${f.path ? f.path + ': ' : ''}${RES_TEXT[f.code] || f.code} (${f.code})`;
  const log = report.findings.map((f) => `[preflight] ${f.severity} ${f.code}${f.path ? ' ' + f.path : ''}${f.detail ? ' — ' + f.detail : ''}`);
  if (fatal.length) {
    const f = fatal[0];
    const why = f.why === 'crash-known' ? 'Без этого файла игра аварийно завершается (проверено на этой модели).'
      : f.why === 'crash-gm' ? 'Без этой модели игра аварийно завершается при её загрузке (загрузчик моделей бросает исключение для любого отсутствующего или повреждённого файла .gm; проверено на моделях этого класса).'
      : f.why === 'crash-music' ? 'Без этого музыкального файла игра аварийно завершается при открытии музыки (проверено для Coridor.ogg, остальные открываются тем же кодом).'
      : 'Этот файл необходим для запуска игры.';
    const more = fatal.length > 1 ? ` Всего проблемных обязательных файлов: ${fatal.length}.` : '';
    return { block: true, level: 'blocked', code: f.code,
      message: `Игра не запущена: ${f.path} — ${RES_TEXT[f.code] || f.code} (код ${f.code}). ${why}${more} ${SAVE_NOTE} ${REPAIR_NOTE}`,
      details: fatal.map(line), warnings: warns.map(line), log };
  }
  if (report.status === 'warn') {
    const codes = [...new Set(warns.map((f) => f.code))];
    const n = warns.length + report.warningsDropped;
    return { block: false, level: 'warn', code: codes[0] ?? null,
      message: `Проверка ресурсов: предупреждений ${n} (${codes.join(', ')}). Игра будет запущена; ` +
        'если она аварийно завершится, сообщите эти коды.',
      details: [], warnings: warns.map(line), log };
  }
  return { block: false, level: 'ok', code: null, message: '', details: [], warnings: [], log };
}

/** Единственная точка входа для port.js: никогда не бросает, при собственном сбое
 * не блокирует запуск. */
export async function checkResourcesBeforeRun(opts) {
  try {
    const report = await preflightResources(opts);
    return { ...describeReport(report), report };
  } catch (e) {
    const report = { schema: 1, status: 'error', mode: 'presence-only', trust: { level: 'absent', manifestVersion: null, installedVersion: null },
      counts: {}, findings: [{ severity: 'warn', code: CODES.PF_INTERNAL, path: null, detail: errName(e) }], warningsDropped: 0, items: [], stats: {} };
    return { block: false, level: 'error', code: CODES.PF_INTERNAL, message: '', details: [],
      warnings: [], log: [`[preflight] warn ${CODES.PF_INTERNAL} — ${errName(e)}`], report };
  }
}

// ---------------------------------------------------------------- английский слой (E5)

/** Файл слоя, который переключает язык игры (STRSERVICE читает его при старте). */
export const LANGUAGE_INI_PATH = 'RESOURCE/INI/TEXTS/language.ini';
/** Результаты, которые для ОБЯЗАТЕЛЬНОГО файла слоя означают отказ запуска английского режима: файла нет, он нечитаем, это не файл,
 * размер/SHA/содержимое не те (слой повреждён: игра получила бы смесь языков или скрипт, который не соберётся). Регистровая неоднозначность
 * в каталоге слоя (его пишет только страница, точными именами) — предупреждение. */
export const OVERLAY_BLOCKING = new Set(['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed', 'content']);

/** language.ini слоя обязан давать английский: активные (не закомментированные) строки `defaultLanguage = ...` есть и все говорят English.
 * Иначе игра осталась бы русской под английской надписью (это единственный переключатель STRSERVICE). null = годится. */
export function languageIniProblem(bytes) {
  let text;
  try { text = new TextDecoder('latin1').decode(bytes); } catch { return 'файл не читается как текст'; }
  const values = [...text.matchAll(/^[ \t]*defaultLanguage[ \t]*=[ \t]*([^\r\n;]*)/gim)].map((m) => m[1].trim());
  if (!values.length) return 'нет активной строки defaultLanguage';
  const other = values.find((v) => v.toLowerCase() !== 'english');
  if (other !== undefined) return values.length > 1 ? 'активные строки defaultLanguage противоречат друг другу' : `активный defaultLanguage = ${other || '(пусто)'}, а не English: игра осталась бы русской`;
  return null;
}

function buildOverlayPlan({ manifest, required, recommended, baseRecommended }) {
  const byLower = new Map();
  if (manifest.usable) for (const e of manifest.files) if (safePath(e.path)) byLower.set(asciiLower(e.path), e);
  const plan = [];
  const seen = new Set();
  const push = (path, props) => {
    if (typeof path !== 'string' || !safePath(path)) return;
    const lower = asciiLower(path);
    if (seen.has(lower + '|' + props.where)) return;
    seen.add(lower + '|' + props.where);
    const found = props.where === 'overlay' ? byLower.get(lower) : null;
    plan.push({ path: found?.path ?? path, mutable: false, expected: found ?? null,
      inManifest: props.where === 'overlay' && manifest.usable ? !!found : null, ...props });
  };
  for (const p of required || []) {
    push(p, { where: 'overlay', cls: 'fatal', why: 'overlay-required', blocking: OVERLAY_BLOCKING,
      ...(asciiLower(p) === asciiLower(LANGUAGE_INI_PATH) ? { verify: languageIniProblem } : {}) });
  }
  for (const p of recommended || []) push(p, { where: 'overlay', cls: 'check', why: 'overlay-recommended' });
  for (const p of baseRecommended || []) push(p, { where: 'base', cls: 'check', why: 'base-for-english' });
  return plan;
}

/** Проверка английского слоя. Аргументы: openOverlayDir() — корень слоя (FileSystemDirectoryHandle, без create), openGameDir() — корень базы
 * (для файлов базы, нужных английскому; необязательно), files — список слоя [{path,size,sha256}] (валидированный манифест или метка), version
 * и installedVersion — версия этого списка и версия слоя на диске (метка), required/recommended/baseRecommended — списки из overlay-required.json.
 * Только чтение. Возвращает отчёт той же формы, что preflightResources (schema 1, status, findings, items). */
export async function preflightOverlay(opts = {}) {
  const { openOverlayDir, openGameDir = null, files = null, version = null, installedVersion = null,
    required = [], recommended = [], baseRecommended = [] } = opts;
  if (typeof openOverlayDir !== 'function') throw new TypeError('openOverlayDir обязателен');
  const sha256 = typeof opts.sha256 === 'function' ? opts.sha256 : defaultSha256;
  const sha1 = typeof opts.sha1 === 'function' ? opts.sha1 : defaultSha1;
  const t0 = typeof performance !== 'undefined' ? performance.now() : 0;
  const findings = [];
  const add = (severity, code, path, detail) => findings.push({ severity, code, path: path ?? null, detail: detail ?? null });
  const trust = await assessManifest(files && version ? { version, files } : null, installedVersion, add, sha1);
  const plan = buildOverlayPlan({ manifest: trust, required, recommended, baseRecommended })
    .filter((item) => item.where !== 'base' || typeof openGameDir === 'function');   // без корня базы её файлы не проверяются
  let root = null, rootError = null, baseRoot = null, baseError = null;
  try { root = await openOverlayDir(); } catch (e) { rootError = errName(e); }
  if (root === undefined || root === null) { root = null; rootError ??= 'NotFoundError'; }
  if (typeof openGameDir === 'function') {
    try { baseRoot = await openGameDir(); } catch (e) { baseError = errName(e); }
    if (baseRoot === undefined || baseRoot === null) { baseRoot = null; baseError ??= 'NotFoundError'; }
  }
  const ctx = { cache: new Map(), baseCache: new Map(), hashed: 0, hashedFiles: 0, skippedHash: 0, noHash: false, sha256 };
  const items = [];
  let ok = 0;
  for (const item of plan) {
    let r;
    try {
      r = item.where === 'base'
        ? await inspectItem(baseRoot, baseError, item, { ...ctx, cache: ctx.baseCache })
        : await inspectItem(root, rootError, item, ctx);
    } catch (e) { r = { path: item.path, cls: item.cls, why: item.why, result: 'unreadable', detail: errName(e) }; }
    items.push({ ...r, where: item.where });
    if (r.result === 'ok') { ok++; continue; }
    const severity = item.cls === 'fatal' && (item.blocking ?? BLOCKING_RESULTS).has(r.result) ? 'fatal' : 'warn';
    const f = { severity, code: RESULT_CODE[r.result], path: r.path, detail: r.detail ?? null, why: item.why, where: item.where };
    if (r.expectedSize !== undefined) { f.expectedSize = r.expectedSize; f.actualSize = r.actualSize; }
    findings.push(f);
  }
  if (ctx.noHash) add('warn', CODES.PF_NO_HASH, null, 'WebCrypto недоступен: хеши не проверены, только размеры');
  const fatal = findings.filter((f) => f.severity === 'fatal').length;
  const warn = findings.filter((f) => f.severity === 'warn').length;
  return {
    schema: 1, kind: 'overlay',
    status: fatal ? 'blocked' : warn ? 'warn' : 'ok',
    mode: trust.usable ? 'verified' : 'presence-only',
    trust: { level: trust.level, manifestVersion: trust.version, installedVersion: installedVersion ?? null },
    counts: { planned: plan.length, ok, fatal, warn, hashedFiles: ctx.hashedFiles, hashedBytes: ctx.hashed },
    findings, items,
    stats: { elapsedMs: typeof performance !== 'undefined' ? Math.round(performance.now() - t0) : 0, skippedHashFiles: ctx.skippedHash },
  };
}

const OVERLAY_REFUSAL_NOTE = 'Английский режим не запущен; русская установка и сохранения не затронуты (проверка только читает файлы). ' +
  'Нажмите «Вернуться к русскому» или переустановите английский слой.';

/** Короткий русский текст и решение для интерфейса (форма как у describeReport). */
export function describeOverlayReport(report) {
  const fatal = report.findings.filter((f) => f.severity === 'fatal');
  const warns = report.findings.filter((f) => f.severity === 'warn');
  const line = (f) => `${f.path ? f.path + ': ' : ''}${RES_TEXT[f.code] || f.code} (${f.code})${f.detail ? ' — ' + f.detail : ''}`;
  const log = report.findings.map((f) => `[preflight-en] ${f.severity} ${f.code}${f.path ? ' ' + f.path : ''}${f.detail ? ' — ' + f.detail : ''}`);
  if (fatal.length) {
    const f = fatal[0];
    const why = f.code === CODES.RES_BAD_CONTENT && f.path && asciiLower(f.path) === asciiLower(LANGUAGE_INI_PATH)
      ? 'Игра осталась бы русской под английской надписью.'
      : 'Без этого файла английского слоя игра получила бы смесь языков или не собрала бы скрипты.';
    const more = fatal.length > 1 ? ` Всего проблемных обязательных файлов слоя: ${fatal.length}.` : '';
    return { block: true, level: 'blocked', code: f.code,
      message: `Английский слой не прошёл проверку: ${f.path} — ${RES_TEXT[f.code] || f.code} (код ${f.code}${f.detail ? ': ' + f.detail : ''}). ${why}${more} ${OVERLAY_REFUSAL_NOTE}`,
      details: fatal.map(line), warnings: warns.map(line), log };
  }
  if (report.status === 'warn') {
    const codes = [...new Set(warns.map((f) => f.code))];
    return { block: false, level: 'warn', code: codes[0] ?? null,
      message: `Проверка английского слоя: предупреждений ${warns.length} (${codes.join(', ')}). Игра будет запущена; часть текстов или озвучки может остаться русской.`,
      details: [], warnings: warns.map(line), log };
  }
  return { block: false, level: 'ok', code: null, message: '', details: [], warnings: [], log };
}

/** Единственная точка входа для port.js в английском режиме: никогда не бросает, при собственном сбое не блокирует запуск. */
export async function checkOverlayBeforeRun(opts) {
  try {
    const report = await preflightOverlay(opts);
    return { ...describeOverlayReport(report), report };
  } catch (e) {
    const report = { schema: 1, kind: 'overlay', status: 'error', mode: 'presence-only', trust: { level: 'absent', manifestVersion: null, installedVersion: null },
      counts: {}, findings: [{ severity: 'warn', code: CODES.PF_INTERNAL, path: null, detail: errName(e) }], items: [], stats: {} };
    return { block: false, level: 'error', code: CODES.PF_INTERNAL, message: '', details: [], warnings: [],
      log: [`[preflight-en] warn ${CODES.PF_INTERNAL} — ${errName(e)}`], report };
  }
}
