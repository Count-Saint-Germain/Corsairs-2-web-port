// The game in the browser: gets the game files into OPFS (downloaded from next to the page on first
// visit, or imported from a local folder), starts the recompiled game (build/game.js), replays its
// frames with WebGPU and feeds it input and audio.
//
// Game files: if game/manifest.json exists next to the page (see make_dist.sh), the files it lists are
// downloaded on the first visit (resuming where an earlier attempt stopped) and reused afterwards.
// Without a manifest the player picks their game folder instead.
//
// URL options: ?mute (no audio) ?fps (frame rate in the console) ?log (host log) ?autoplay
//              ?game=<url> (where manifest.json and the files live; default "game/") ?join=<room code>
//              ?saveTx=1 (opt-in, default off, solo only: logical save transaction + recovery, see save-tx.mjs)
//              ?lang=ru|en (game language; default Russian, the choice is remembered in localStorage `korsary2.lang`; English is an
//              optional read-only overlay in its own OPFS folder installed from game-en/, see overlay.mjs and PORT_SPECIFICATION.md)
//              ?gameEn=<url> (where game-en/manifest.json and the overlay files live; default "game-en/")
//
// Online play (netplay.js, host/netplay.c): players meet in a room on the Worker; when the host starts,
// every page boots the game in deterministic lockstep mode with fresh saves, and only pad inputs travel.
// Each player's keyboard and first gamepad merge into one local pad; mouse and raw keys are off.
'use strict';

const $ = (id) => document.getElementById(id);
const params = new URLSearchParams(location.search);
const PORT = window.PORT;   // port-config.js, generated from port.json by tools/configure.mjs
// Partial installs are never written to the regular game or its saves.
const EXPERIMENTAL_LAZY = params.get('lazy') !== '0';
const OPFS_DIR = PORT.id + (EXPERIMENTAL_LAZY ? '-game-lazy-experiment' : '-game');
// The restore module must use the same root and save lock as this launcher.
// In particular an experimental import must never write into normal saves.
window.getPortSaveRoot = () => OPFS_DIR;
const LAZY_INDEX_NAME = PORT.id + '-lazy-experiment-index.tsv';
const LAZY_USERDATA = OPFS_DIR + '-userdata';
let lazyPlan = null;
let backupUrl = null; // local in-memory Blob URL; never uploaded
let installedManifest = null; // manifest the install was synced against (set by boot); null = offline / picker install
const EXE = PORT.exe;
const MARKER = EXPERIMENTAL_LAZY ? 'experimental-lazy.json' : 'installed.json';   // Full-install marker is never written by the experiment.
// Chromium refuses to open dot-names in OPFS without create:true, which silently disabled
// readMarker and forced a full hash verification of every game file on every start
const GAME_BASE = new URL(params.get('game') || 'game/', location.href).href.replace(/\/?$/, '/');
// Language overlay (E1, overlay.mjs): a second OPFS folder next to the game's, with its own manifest and install marker. Everything that
// installs files takes a target; the default target is the game itself, exactly as before.
const OVERLAY_DIR = OPFS_DIR + '-en';
const OVERLAY_MARKER = 'installed-en.json';
const GAME_EN_BASE = new URL(params.get('gameEn') || 'game-en/', location.href).href.replace(/\/?$/, '/');
const BASE_TARGET = { dirName: OPFS_DIR, marker: MARKER, url: GAME_BASE };
const OVERLAY_TARGET = { dirName: OVERLAY_DIR, marker: OVERLAY_MARKER, url: GAME_EN_BASE };
const status = (t) => { $('status').textContent = t; };
// the launcher's screens (index.html): loading, home, online, lobby
const show = (view) => { for (const v of document.querySelectorAll('#panel .view')) v.classList.toggle('hidden', v.id !== 'view-' + view); };
const fail = (e) => { status('Error: ' + e.message); $('panel').classList.remove('hidden'); show('loading'); };
// Startup failures reach the player as readable messages, never a stack. A busy
// refusal means another tab of this browser owns the saves; retrying is fine
// once it is closed. Once the runtime has started, its locks are held until the
// document goes away, so "try again" must never be offered then.
const startFailed = (e) => {
  if (EXPERIMENTAL_LAZY) console.error('Streaming game start failed:', e);
  if (e?.name === 'SaveLockBusy')
    status(uiText('Игра уже запущена в другой вкладке или окне этого браузера, и её блокировка защищает сохранения. Закройте ту вкладку и попробуйте снова.', 'The game is already running in another tab or window of this browser. Close it and try again; the save lock protects your saves.'));
  else if (e?.saveTxRefused)   // SAVE_TX recovery needs a decision; nothing was changed and the game did not start
    status(e.message);
  else if (e?.overlayRefused) {   // English start refused (overlay incomplete or changed): nothing was started or held, Russian stays available
    langState.overlay = 'error'; langState.error = uiText(e.message + ' Вернитесь к русскому языку или повторите установку английского слоя.', 'English language files are incomplete or changed. Return to Russian or reinstall the English files.');
    langLog('start refused', e.message);
    renderLang();
    $('panel').classList.remove('hidden');
    show('home');   // the home screen carries the message and the way back to Russian; the shared tail below would show the loading screen
    return;
  }
  else if (e?.runtimeStarted)
    status(EXPERIMENTAL_LAZY ? uiText(`Потоковый запуск не завершён: ${e?.message || String(e)}. Перезагрузите страницу.`, `Streaming game did not finish starting: ${e?.message || String(e)}. Reload the page.`)
      : uiText('Игра не смогла запуститься до конца; блокировка сохранений ещё удерживается. Обновите страницу и попробуйте снова.', 'The game did not finish starting and still holds the save lock. Reload the page and try again.'));
  else return fail(e);
  $('panel').classList.remove('hidden');
  show('loading');
};
const mb = (n) => (n / 1e6).toFixed(0);

// ------------------------------------------------------------------ game files in OPFS

async function targetDir(target, create) {
  const root = await navigator.storage.getDirectory();
  return root.getDirectoryHandle(target.dirName, { create });
}
async function gameDir(create) { return targetDir(BASE_TARGET, create); }

async function readMarker(target = BASE_TARGET) {
  let f;
  try {
    f = await (await (await targetDir(target, false)).getFileHandle(target.marker)).getFile();
  } catch (e) {
    if (e.name === 'NotFoundError') return null;
    throw e; // I/O and permission errors must not masquerade as first install
  }
  const contents = await f.text();
  try { return JSON.parse(contents); }
  catch (e) { if (e instanceof SyntaxError) return null; throw e; }
}

async function writeMarker(version, target = BASE_TARGET, extra = null) {
  const fh = await (await targetDir(target, true)).getFileHandle(target.marker, { create: true });
  const w = await fh.createWritable();
  await w.write(JSON.stringify({ version, at: new Date().toISOString(), ...extra }));
  await w.close();
}

async function fileHandle(dir, relPath, create) {
  const parts = relPath.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create });
  return dir.getFileHandle(parts[parts.length - 1], { create });
}

async function existingSize(dir, relPath) {
  try { return (await (await fileHandle(dir, relPath, false)).getFile()).size; } catch { return -1; }
}

async function removeFile(dir, rel) {
  const parts = rel.split('/');
  let d = dir;
  for (const p of parts.slice(0, -1)) d = await d.getDirectoryHandle(p, { create: false });
  await d.removeEntry(parts[parts.length - 1]);
}

// Streams one file into OPFS. With `from` > 0 it asks for the rest only (HTTP Range) and appends; a
// server that ignores ranges gets the whole file written from scratch.
// A manifest entry with `enc` (D1, game-transfer.mjs) is a gzip object `<path>.gz` on the server: it is
// unpacked while streaming, checked for size and SHA-256 AFTER unpacking, and always written from scratch
// (a packed stream cannot be resumed mid-file). Failed writes abort their temporary data: existing files
// remain intact and newly created placeholders are removed. `ctx.signal` (D3) cancels the request and write.
async function downloadFile(baseUrl, dir, rel, size, from, onBytes, entry, ctx) {
  const signal = ctx?.signal;
  if (entry?.enc) {
    const { createSafeWriteTarget, downloadPackedFile, remotePath } = await import('./game-transfer.mjs');
    const target = createSafeWriteTarget({ getFile: (create) => fileHandle(dir, rel, create), removeFile: () => removeFile(dir, rel) });
    if (from > 0) onBytes(-from);   // syncManifestFiles counted a resumed prefix; this write starts over
    return downloadPackedFile({
      entry, url: baseUrl + remotePath(entry).split('/').map(encodeURIComponent).join('/'), fetchImpl: fetch, onBytes, signal,
      ...target,
    });
  }
  const headers = from > 0 ? { Range: `bytes=${from}-` } : {};
  const res = await fetch(baseUrl + rel.split('/').map(encodeURIComponent).join('/'), { headers, cache: 'no-store', signal });
  if (!res.ok) throw new Error(`${rel}: HTTP ${res.status}`);
  const append = from > 0 && res.status === 206;
  const { createSafeWriteTarget } = await import('./game-transfer.mjs');
  const target = createSafeWriteTarget({ getFile: (create) => fileHandle(dir, rel, create), removeFile: () => removeFile(dir, rel) });
  let w, reader;
  try {
    const verify = ctx?.verifySha && entry?.sha256;
    let hash, sha256Update, sha256Hex;
    if (verify) {
      const sha = await import('./save-protection.mjs');
      hash = sha.sha256Init(); sha256Update = sha.sha256Update; sha256Hex = sha.sha256Hex;
      if (append) {
        const existing = await (await fileHandle(dir, rel, false)).getFile();
        if (existing.size !== from) throw new Error(`${rel}: existing prefix changed before resume`);
        for (let off = 0; off < from; off += 1 << 20)
          sha256Update(hash, new Uint8Array(await existing.slice(off, Math.min(off + (1 << 20), from)).arrayBuffer()));
      }
    }
    w = await target.openWritable({ keepExistingData: append });
    if (append) await w.seek(from); else { await w.truncate(0); onBytes(-Math.max(from, 0)); }
    reader = res.body.getReader();
    let written = append ? from : 0;
    for (;;) {
      const { done, value } = await reader.read();
      if (done) break;
      written += value.length;
      if (written > size) throw new Error(`${rel}: got more than ${size} bytes`);
      await w.write(value);
      if (verify) sha256Update(hash, value);
      onBytes(value.length);
    }
    if (written !== size) throw new Error(`${rel}: got ${written} of ${size} bytes`);
    if (verify && sha256Hex(hash) !== entry.sha256.toLowerCase())
      throw new Error(`${rel}: SHA-256 не совпадает с манифестом`);
    await w.close();
  } catch (err) {
    try { if (reader) await reader.cancel(err); else await res.body?.cancel?.(err); } catch { /* the original error wins */ }
    try { await w?.abort(); } catch { /* the original error wins */ }
    try { await target.discard(); } catch { /* the original error wins */ }
    throw err;
  }
  const got = await existingSize(dir, rel);
  if (got !== size) throw new Error(`${rel}: got ${got} of ${size} bytes`);
}

// D3: one range of a transfer pack = one request for many small files (game-transfer.mjs downloadPackRun).
async function downloadPackRange(baseUrl, dir, pack, entries, onBytes, onFile, ctx) {
  const { createSafeWriteTarget, downloadPackRun } = await import('./game-transfer.mjs');
  const targets = new Map();
  const targetFor = (e) => {
    if (!targets.has(e.path)) targets.set(e.path, createSafeWriteTarget({
      getFile: (create) => fileHandle(dir, e.path, create), removeFile: () => removeFile(dir, e.path),
    }));
    return targets.get(e.path);
  };
  return downloadPackRun({
    pack, entries, url: baseUrl + pack.path.split('/').map(encodeURIComponent).join('/'), fetchImpl: fetch,
    onBytes, onFile, signal: ctx?.signal,
    openWritable: (e) => targetFor(e).openWritable(),
    discard: (e) => targetFor(e).discard(),
  });
}

// Hash the downloaded defaults before touching OPFS. A failed initial write
// must not leave an empty options file that a later install would preserve.
async function downloadOptionsFile(dest, entry, onBytes, overlay = false) {
  if (overlay) throw new Error('options не входит в английский слой');
  const [{ fetchVerifiedOptions }, { createSafeWriteTarget }] = await Promise.all([
    import('./save-protection.mjs'), import('./game-transfer.mjs'),
  ]);
  const bytes = await fetchVerifiedOptions(GAME_BASE + 'options', entry, fetch);
  const target = createSafeWriteTarget({ getFile: (create) => fileHandle(dest, 'options', create), removeFile: () => removeFile(dest, 'options') });
  let w;
  try { w = await target.openWritable(); await w.write(bytes); await w.close(); }
  catch (err) {
    try { await w?.abort(); } catch { /* the original error wins */ }
    try { await target.discard(); } catch { /* the original error wins */ }
    throw err;
  }
  onBytes(bytes.length);
}

// The progress bar counts unpacked bytes written to OPFS, not network traffic.
function formatInstallProgress(done, total, { overlay = false, networkBytes = null, lang = 'ru', name = '' } = {}) {
  const amount = n => (n / 1e6).toFixed(overlay ? 1 : 0);
  const en = lang === 'en';
  const title = overlay ? (en ? 'Installing English files' : 'Установка английских файлов')
    : (en ? 'Installing game files' : 'Установка игровых файлов');
  const unit = en ? 'MB unpacked' : 'МБ распаковано';
  const network = Number.isFinite(networkBytes) && networkBytes > 0
    ? (en ? `; about ${amount(networkBytes)} MB over network` : `; по сети около ${amount(networkBytes)} МБ`)
    : '';
  return `${title}: ${amount(done)} / ${amount(total)} ${unit}${network}${name ? ' (' + name + ')' : ''}`;
}

// Downloads whatever the manifest lists that OPFS doesn't already hold in full. `target` is the game itself (the default) or the
// language overlay (E1): the overlay has its own folder, marker and server folder, a STRICTER manifest check (overlay.mjs) and reports
// into `ui` ({status, progress}) instead of the launcher's loading screen.
async function syncFromServer(manifest, target = BASE_TARGET, ui = null) {
  const overlay = target !== BASE_TARGET;
  const say = ui?.status || status;
  const bar = ui?.progress || $('progress');
  const { validateManifestFiles, syncManifestFiles, checkStorageForSync, installConcurrency } =
    await import('./save-protection.mjs');
  const files = overlay ? (await import('./overlay.mjs')).validateOverlayManifest(manifest, { baseManifest: installedManifest }).files
    : validateManifestFiles(manifest.files);
  const { unsupportedEncodings, validateManifestPacks, prepareDecoders } = await import('./game-transfer.mjs');
  validateManifestPacks(files, manifest.packs);   // pack ranges and sizes, before anything is written
  // how many files/packs are fetched at once (D3); ?installConcurrency=N for experiments (1..16, default 6)
  const concurrency = installConcurrency(params.get('installConcurrency'));
  const noDecoder = unsupportedEncodings(files);
  if (noDecoder.length)   // before anything is written: the files on the server only exist packed
    throw new Error(`this browser cannot unpack ${noDecoder.join(', ')} (DecompressionStream / WebAssembly); update the browser`);
  await prepareDecoders(files);   // D1b: loads the WebAssembly brotli decoder, only when the manifest has `enc: "br"`; fails before any write
  const total = files.reduce((s, f) => s + f.size, 0);
  // A marker from a finished install means an existing file with a different size
  // is old content (the server changed it): appending the new tail after the old
  // bytes would corrupt the file, so such files are rewritten from scratch.
  // Only a partial download of the current install may be resumed.
  const hadMarker = !!(await readMarker(target))?.version;
  // Space check before anything is written, from what actually has to be downloaded or replaced
  // (installed files whose size matches cost nothing), see save-protection.mjs planStorageNeed. The
  // game folder is only opened, never created here (a leftover empty folder would block a picker
  // import). An unavailable or nonsensical navigator.storage.estimate() never blocks the download.
  let existing = null;
  try { existing = await targetDir(target, false); } catch (e) { if (e.name !== 'NotFoundError') throw e; }
  const space = await checkStorageForSync({ dir: existing, files, hadMarker, existingSize, concurrency,
    estimate: () => navigator.storage?.estimate?.() });
  window[overlay ? 'overlayStoragePreflight' : 'storagePreflight'] = { status: space.status, free: space.free, plan: space.plan };
  if (space.status === 'insufficient') throw new Error(space.message);
  if (space.message) { console.warn('storage preflight:', space.message); say(space.message); }
  await navigator.storage.persist?.();   // ask the browser not to evict ~1 GB of game files
  const dir = await targetDir(target, true);
  // Estimate first-install transfer from manifest record sizes. Range handling
  // and retries may increase traffic. Updates can discover more changed files
  // during hash checks, so omit the estimate in that case.
  const networkBytes = space.plan?.fresh ? space.plan.transferBytes : null;
  const show = (done, name) => {
    say(formatInstallProgress(done, total, { overlay, networkBytes, lang: langState.lang, name }));
    bar.value = total ? done / total : 1;
  };
  bar.classList.remove('hidden');
  const t0 = performance.now();
  await syncManifestFiles({dir, files, hadMarker, version: manifest.version,
    existingSize, downloadOptionsFile: (d, e, onBytes) => downloadOptionsFile(d, e, onBytes, overlay), show,
    downloadFile: (d, rel, size, from, onBytes, entry, ctx) => downloadFile(target.url, d, rel, size, from, onBytes, entry, overlay || EXPERIMENTAL_LAZY ? { ...ctx, verifySha: true } : ctx),
    // the overlay's marker also keeps its file list (path, size, sha256): with no network the installed layer can still be checked and run
    writeMarker: (version) => writeMarker(version, target, overlay ? { files: files.map((f) => [f.path, f.size, f.sha256]) } : null),
    packs: manifest.packs, concurrency,
    downloadPackRun: (d, pack, entries, onBytes, onFile, ctx) => downloadPackRange(target.url, d, pack, entries, onBytes, onFile, ctx),
    sleep: (ms, path, err, signal) => {
      say(`Retrying ${path} (${err.message})`);
      return new Promise((r) => {
        const timer = setTimeout(r, ms);
        signal?.addEventListener('abort', () => { clearTimeout(timer); r(); }, { once: true });
      });
    },
  });
  const stats = { seconds: (performance.now() - t0) / 1000, concurrency, files: files.length, packs: manifest.packs?.length || 0 };
  window[overlay ? 'overlayInstallStats' : 'installStats'] = stats;
  console.info(overlay ? '[install-en]' : '[install]', JSON.stringify(stats));
  bar.classList.add('hidden');
}

async function fetchManifest() {
  try {
    const res = await fetch(GAME_BASE + 'manifest.json', { cache: 'no-store' });
    if (!res.ok) return null;
    const m = await res.json();
    return Array.isArray(m) ? { version: String(m.length), files: m } : m;
  } catch { return null; }
}

// ---- local folder import (used when there is no manifest next to the page)

// which files to keep from the chosen folder: the executable and the paths port.json includes (all if none)
function wanted(rel) {
  const l = rel.toLowerCase();
  if (l === EXE.toLowerCase()) return EXE;
  if (l.split('/').some((p) => !p || p === '.' || p === '..' || p.startsWith('.'))) return null;
  const skip = ['uninst', 'setup.exe', 'autorun.inf', 'unins000', 'directx/', 'redist/', '_setup/'];
  if (skip.some((s) => l.includes(s)) || (PORT.files.exclude_extensions || []).some((s) => l.endsWith(s.toLowerCase()))) return null;
  // whole folders the browser build never reads (port.json files.exclude_paths; same rule as gamefiles.py)
  if ((PORT.files.exclude_paths || []).some((p) => { const x = p.toLowerCase().replace(/\/+$/, ''); return l === x || l.startsWith(x + '/'); })) return null;
  const inc = PORT.files.include || [];
  return !inc.length || inc.some((p) => {
    const prefix = p.toLowerCase().replace(/\/+$/, '');
    return l === prefix || l.startsWith(prefix + '/');
  }) ? rel : null;
}

async function importFromPicker(fileList) {
  const { selectGameAssets, dropSiblingDuplicates, relocateIfAbsent, withFreshGameDirectory } = await import('./save-protection.mjs');
  const selected = [...fileList].map((f) => ({ f, dest: wanted(f.webkitRelativePath.split('/').slice(1).join('/')) }))
    .filter((e) => e.dest);
  // port.json files.exclude_if_sibling (same rule as gamefiles.py): e.g. a RESOURCE/Sounds .ogg is not copied
  // when its .wav, the file the engine opens, is in the chosen folder too
  const kept = dropSiblingDuplicates(selectGameAssets(selected, e => e.dest), e => e.dest, e => e.f.size,
    PORT.files.exclude_if_sibling);
  // port.json files.relocate_if_absent (same rule as gamefiles.py): the Russian loading screens of
  // RESOURCE/Textures/Loading/Russian are copied as RESOURCE/Textures/Loading/<name>, where the engine opens them,
  // unless that folder has a file of the same name; the file's own bytes, only the destination changes
  const list = relocateIfAbsent(kept, e => e.dest, (e, dest) => ({ ...e, dest }), PORT.files.relocate_if_absent);
  if (!list.some((e) => e.dest === EXE)) throw new Error(`No ${EXE} in that folder.`);
  for (const r of PORT.files.required || [])
    if (!list.some((e) => e.dest.toLowerCase() === r.toLowerCase())) throw new Error(`No ${r} in that folder.`);
  const root = await navigator.storage.getDirectory();
  await withFreshGameDirectory(root, navigator.locks, OPFS_DIR, async dir => {
  await navigator.storage.persist?.();
  const total = list.reduce((s, e) => s + e.f.size, 0);
  let done = 0;
  $('progress').classList.remove('hidden');
  for (const e of list) {
    status(`Copying ${e.dest} (${mb(done)} / ${mb(total)} MB)`);
    const w = await (await fileHandle(dir, e.dest, true)).createWritable();
    await w.write(e.f);
    await w.close();
    done += e.f.size;
    $('progress').value = done / total;
  }
  await writeMarker('local');
  $('progress').classList.add('hidden');
  });
}

// ------------------------------------------------------------------ language (E1)

// Game language: Russian (default, the base install as it always was) or English, an optional READ-ONLY overlay of PROGRAM/ and RESOURCE/
// files in its own OPFS folder (korsary2-game-en) that the host lays over the base (PORT_OVERLAY, host/core.c). The choice comes from
// ?lang=ru|en, else localStorage `korsary2.lang`, else Russian. English installs the overlay from game-en/manifest.json ONLY when it is
// chosen (own marker installed-en.json, same save lock and download machinery as the base, overlay.mjs); the Russian install is neither
// touched nor re-downloaded. Starting English is refused, with a way back to Russian, while the overlay is missing, incomplete or not
// built for this Russian install. Diagnostics: window.langInfo and the console lines starting with [lang].
const initialLangChoice = (() => {
  let stored = null;
  try { stored = window.localStorage.getItem('korsary2.lang')?.trim().toLowerCase(); } catch {}
  const requested = params.get('lang')?.trim().toLowerCase();
  if (requested === 'ru' || requested === 'en') return { lang: requested, chosen: true };
  if (stored === 'ru' || stored === 'en') return { lang: stored, chosen: true };
  return { lang: 'ru', chosen: false };
})();
// This is set before asynchronous capability checks, not only once the
// language selector becomes available, so assistive technology uses the right language.
document.documentElement.lang = initialLangChoice.lang;
const langState = {
  lang: initialLangChoice.lang, source: 'default', stored: null, urlInvalid: false, storageError: null,
  overlay: 'unknown',      // unknown | unavailable (no game-en/) | absent | installing | ready | error
  version: null, files: 0, bytes: 0, error: null, manifest: null, validated: null, installed: null, launched: null,
  hostPath: '/opfs/' + OVERLAY_DIR, dir: OVERLAY_DIR, marker: OVERLAY_MARKER, url: GAME_EN_BASE,
};
const publishLangInfo = () => {
  const { manifest, validated, ...pub } = langState;
  window.langInfo = { ...pub, overlayManifestLoaded: !!manifest };
};
const uiText = (ru, en) => langState.lang === 'en' ? en : ru;
// Compatibility checks run before the language selector is available. On the
// first visit label each language separately for screen readers. Use textContent
// rather than HTML so a diagnostic message cannot introduce markup.
const startupStatus = (ru, en) => {
  if (initialLangChoice.chosen) return status(uiText(ru, en));
  const russian = document.createElement('span'), english = document.createElement('span');
  russian.lang = 'ru'; russian.textContent = ru;
  english.lang = 'en'; english.textContent = en;
  $('status').replaceChildren(russian, document.createTextNode('\n\n'), english);
};
if (initialLangChoice.chosen) status(uiText('Проверяем ваш браузер…', 'Checking your browser…'));
window.launcherText = uiText;
// Keep messages as render functions so a language switch updates visible save feedback.
let backupMessage = null;
window.setBackupMessage = (render) => {
  backupMessage = typeof render === 'function' ? render : () => render;
  $('backup-status').textContent = backupMessage();
};
const langLog = (...a) => console.info('[lang]', ...a);
const safeLocalStorage = () => { try { return window.localStorage; } catch { return null; } };

// is there a game-en/ in this dist? HEAD (no body) first; some hosts refuse HEAD, then GET. A page of the app's own HTML in place of
// a missing file (a fallback route) is not a manifest.
async function probeOverlay() {
  const url = GAME_EN_BASE + 'manifest.json';
  try {
    let res = await fetch(url, { method: 'HEAD', cache: 'no-store' });
    if (res.status === 405 || res.status === 501) res = await fetch(url, { cache: 'no-store' });
    return res.ok && !/html/i.test(res.headers.get('content-type') || '');
  } catch { return false; }
}

async function fetchOverlayManifest() {
  let res;
  try { res = await fetch(GAME_EN_BASE + 'manifest.json', { cache: 'no-store' }); }
  catch (e) { throw Object.assign(new Error(`не удалось получить манифест английского слоя (${e.message})`), { network: true }); }
  // a missing manifest (404, or a page of the app's own HTML standing in for it) means this dist has no overlay: not an install failure
  if (res.status === 404 || (res.ok && /html/i.test(res.headers.get('content-type') || '')))
    throw Object.assign(new Error('в этой раздаче нет английского слоя'), { overlayNotFound: true });
  if (!res.ok) throw new Error(`манифест английского слоя недоступен (HTTP ${res.status})`);
  try { return await res.json(); } catch { throw new Error('манифест английского слоя не разобрать (не JSON)'); }
}

const langUi = {
  ru: () => $('lang-ru'), en: () => $('lang-en'), status: () => $('lang-status'), note: () => $('lang-note'),
  progress: () => $('lang-progress'), back: () => $('lang-back-ru'),
};
function renderLang() {
  if (!$('lang-box')) return;
  const en = langState.lang === 'en';
  document.documentElement.lang = en ? 'en' : 'ru';
  const texts = {
    'home-tagline': ['Выберите режим игры.', 'Pick how you want to play.'],
    'play-label': ['Одиночная игра', 'Play Solo'],
    'play-description': ['Без сети, на этом устройстве.', 'Offline, on this device.'],
    'online-label': ['Сетевая игра', 'Play Multiplayer'],
    'online-description': ['Игра 1 на 1 с другом через сеть.', 'Online 1v1 with a friend, wherever they are.'],
    'fullscreen-prefix': ['Полный экран:', 'Fullscreen:'],
    'fullscreen-suffix': ['на Mac) или кнопка в углу.', 'on Mac) or the button in the corner.'],
    'fstip-prefix': ['Нажмите', 'Press'],
    'fstip-suffix': ['для полного экрана', 'for fullscreen'],
    'save-read-label': ['Чтение сохранения…', 'Loading save…'],
    'backup-saves': ['Скачать сохранения', 'Download saves'],
    'restore-saves': ['Восстановить сохранения', 'Restore saves'],
    'copy-classic-saves': ['Скопировать сохранения обычной версии', 'Copy saves from the classic version'],
    'backup-download': ['Скачать готовый архив', 'Download prepared archive'],
    'restore-skip': ['Пропустить всё', 'Skip all'],
    'restore-replace': ['Заменить всё', 'Replace all'],
    'restore-cancel': ['Отмена', 'Cancel'],
    'lang-back-ru': ['Вернуться к русскому', 'Return to Russian'],
    'lang-label': ['Язык игры / Game language', 'Game language'],
    'save-help': ['Перед архивированием или восстановлением закройте все другие вкладки с запущенной игрой: иначе последние изменения сохранений могут потеряться. Существующие сохранения с другими именами не трогаются, а совпадающие имена требуют вашего выбора.', 'Before exporting or restoring saves, close all other tabs running the game, or recent save changes may be lost. Saves with different names are left untouched; matching names require your choice.'],
  };
  for (const [id, [ru, english]] of Object.entries(texts)) $(id).textContent = en ? english : ru;
  $('fs').title = en ? 'Fullscreen (Alt+Enter)' : 'Полный экран (Alt+Enter)';
  $('fs').setAttribute('aria-label', en ? 'Toggle fullscreen' : 'Переключить полный экран');
  window.updateViewportControls?.();
  $('controls').textContent = en && PORT.id === 'korsary2' ? 'Example bindings in the supplied profile: right mouse button — move forward; left mouse button — action and cannon fire; Space — quick action; A/D — steer the ship; W/S — sails; Tab — camera; Shift — run; E — combat; Ctrl — block and spyglass; Q — pistol; Z — dodge; 1–4 — ammunition; Enter/Esc/F1/F2 — interface; R — time; B — skip encounter. Bindings can be viewed and changed in the game controls.' : PORT.controls;
  const blocked = en && langState.overlay !== 'ready';
  const unavailable = langState.overlay === 'unavailable';
  langUi.ru().setAttribute('aria-pressed', String(!en));
  langUi.en().setAttribute('aria-pressed', String(en));
  langUi.en().disabled = unavailable || langState.overlay === 'installing';
  langUi.ru().disabled = langState.overlay === 'installing';
  langUi.en().title = unavailable ? 'В этой раздаче нет английского слоя (нет game-en/).' : '';
  langUi.back().classList.toggle('hidden', !(en && langState.overlay === 'error'));
  // Play is blocked while English is chosen and its overlay is not ready; Russian never is
  for (const id of ['play', 'go-online']) {   // only ever undo what this block did (the saves buttons manage their own busy state)
    const el = $(id);
    if (!el) continue;
    if (blocked) { el.disabled = true; el.dataset.langBlocked = '1'; }
    else if (el.dataset.langBlocked) { el.disabled = id === 'go-online' && EXPERIMENTAL_LAZY; delete el.dataset.langBlocked; }
  }
  const msg = langState.overlay === 'installing' ? $('lang-status').textContent
    : unavailable ? 'Английский слой не опубликован в этой раздаче; игра идёт на русском.'
    : en && langState.overlay === 'error' ? langState.error
    : en && langState.overlay === 'ready' ? 'English language files are installed.'
    : en ? 'Checking English language files…' : '';
  $('lang-status').textContent = msg;
  langUi.note().textContent = uiText('Язык применяется при запуске игры: в уже запущенной игре (в том числе в другой вкладке) он не меняется. Сохранения общие для обоих языков; имена, заданные при создании игры, остаются на языке создания.', 'The language is applied when the game starts; it does not change a game already running, including in another tab. Saves are shared between languages; names retain the language in which the game was created.');
  if (backupMessage) $('backup-status').textContent = backupMessage();
  window.refreshRestoreDecision?.();
  publishLangInfo();
}

// Makes the overlay installed and complete. Never throws: the outcome is langState.overlay ('ready' or 'error'/'unavailable').
// `ui` ({status, progress}) shows the progress; the launcher's loading screen is used at start, the language box afterwards.
async function ensureOverlay(ui) {
  const O = await import('./overlay.mjs');
  const say = ui.status;
  try {
    say('Checking English language files…');
    langState.overlay = 'installing'; langState.error = null; renderLang();
    let manifest = langState.manifest;
    let offline = null;
    if (!manifest) {
      try { manifest = await fetchOverlayManifest(); }
      catch (e) {
        // no network: an overlay that is installed (its marker keeps the file list) is still checked and used; nothing can be installed
        const m = e?.network ? await readMarker(OVERLAY_TARGET).catch(() => null) : null;
        if (!m?.version || !Array.isArray(m.files) || !m.files.length) throw e;
        offline = m;
      }
    }
    langState.manifest = manifest || null;
    let result;
    if (offline) {
      langState.validated = { files: offline.files.map(([path, size, sha256]) => ({ path, size, sha256 })), totalBytes: offline.files.reduce((t, f) => t + f[1], 0) };
      langState.version = offline.version;
      result = { skipped: 'offline' };
      langLog('manifest unreachable: checking the installed overlay against its own marker');
    } else {
      // the strict check comes first and writes nothing: only PROGRAM/ and RESOURCE/, SHA-256 on every entry, built for this Russian install
      langState.validated = O.validateOverlayManifest(manifest, { baseManifest: installedManifest });
      langState.version = manifest.version;
    }
    langState.files = langState.validated.files.length; langState.bytes = langState.validated.totalBytes;
    const rootName = OPFS_DIR;   // the SAVE lock of the base install: one lock, one order (base first, overlay second, never nested)
    if (!offline) result = await O.installOverlayUnderSaveLock({
      locks: navigator.locks, rootName, version: manifest.version,
      readMarker: () => readMarker(OVERLAY_TARGET),
      sync: () => syncFromServer(manifest, OVERLAY_TARGET, ui),
    });
    // the marker only says "finished once": check that every file is really there before English may start
    let check = await verifyOverlay();
    if (!check.ok && result.skipped && !offline) {   // a current marker over missing files: repair under the lock (syncManifestFiles re-checks every file)
      say('English language files are incomplete; repairing…');
      const { withSaveLock } = await import('./save-export.mjs');
      await withSaveLock(navigator.locks, rootName, () => syncFromServer(manifest, OVERLAY_TARGET, ui));
      check = await verifyOverlay();
    }
    if (!check.ok) throw new Error(O.incompleteOverlayMessage(check));
    langState.overlay = 'ready'; langState.installed = offline ? 'offline' : result.skipped ? 'current' : 'installed';
    langLog('overlay ready', JSON.stringify({ version: langState.version, files: langState.files, how: langState.installed }));
  } catch (e) {
    if (e?.overlayNotFound) {   // no game-en/ on this server: English is not offered, Russian runs (a stored English choice stays stored)
      langState.overlay = 'unavailable'; langState.error = null; langState.manifest = null;
      if (langState.lang === 'en') { langState.lang = 'ru'; langState.source += '+unavailable'; }
      langLog('overlay unavailable on this server');
      renderLang();
      return false;
    }
    ui.progress?.classList.add('hidden');
    langState.overlay = 'error';
    const busy = /заняты другой операцией/.test(e?.message || '') || e?.name === 'SaveLockBusy';
    langState.error = (busy ? 'Игра запущена в другой вкладке этого браузера, и её блокировка защищает сохранения: английский слой сейчас нельзя установить. ' : '') +
      (/[А-Яа-яЁё]/.test(e?.message || '') ? e.message : `Не удалось установить английский слой (${e?.message || e}).`) + (/вернитесь к русскому/i.test(e?.message || '') ? '' : ' Английский режим не запущен; русская установка не затронута: вернитесь к русскому языку или повторите позже.');
    if (langState.lang === 'en') langState.error = busy ? 'Another game tab is using this browser’s save lock. Close it and try installing English again, or return to Russian.' : 'Could not install or verify the English language files. Return to Russian or try again; see the browser console for details.';
    langLog('overlay error', e?.message || e);
  }
  renderLang();
  return langState.overlay === 'ready';
}

// complete = every manifest file of the overlay is in its folder with the size the manifest says (no hashing: the install checked those)
async function verifyOverlay() {
  const O = await import('./overlay.mjs');
  let dir;
  try { dir = await targetDir(OVERLAY_TARGET, false); }
  catch (e) { if (e.name === 'NotFoundError') return { ok: false, missing: ['(каталог английского слоя)'], wrongSize: [], checked: 0 }; throw e; }
  return O.verifyOverlayFiles({ dir, files: langState.validated.files, existingSize });
}

async function selectLang(next, fromUser) {
  const O = await import('./overlay.mjs');
  if (next === 'en' && langState.overlay === 'unavailable') return;
  langState.lang = next;
  if (fromUser) { langState.source = 'user'; langState.stored = O.rememberLang(safeLocalStorage(), next) ? next : langState.stored; }
  langLog('language', next, '(' + langState.source + ')');
  renderLang();
  if (next === 'en' && langState.overlay !== 'ready') {
    const ui = { status: (t) => { $('lang-status').textContent = t; }, progress: langUi.progress() };
    await ensureOverlay(ui);
  }
  renderLang();
  updateSlotLanguageNote();   // the "other language" depends on the choice
}

// Non-blocking notice (E5): the SAVE slots are shared by both languages, but names inside a slot stay in the language it was created in (the
// host marks a slot made in the English mode with SAVE_META/<slot>.lang). Says so when slots of the other language exist; nothing is
// ever blocked or written, and any failure is silent. Re-run when the language choice changes.
async function updateSlotLanguageNote() {
  const el = $('slot-lang-note');
  if (!el) return;
  try {
    const O = await import('./overlay.mjs');
    let info = { slots: [], labels: new Map() };
    try { info = await O.readSlotLanguages(await gameDir(false)); } catch { /* no game folder yet: no slots */ }
    const s = O.summarizeSlotLanguages(info, langState.lang);
    el.textContent = s.message || '';
    el.classList.toggle('hidden', !s.message);
    window.slotLanguages = s;
    if (s.message) langLog('slots of another language or without a mark', JSON.stringify({ lang: s.lang, total: s.total, other: s.other, unmarked: s.unmarked }));
  } catch (e) { el.classList.add('hidden'); console.warn('[lang] slot language note unavailable:', e); }
}

// at the launcher's home screen; resolves when the language choice is settled (English: installed or refused). Never throws.
async function initLanguage() {
  try {
    const O = await import('./overlay.mjs');
    const chosen = O.chooseLang({ search: location.search, storage: safeLocalStorage() });
    Object.assign(langState, { lang: chosen.lang, source: chosen.source, stored: chosen.stored, urlInvalid: chosen.urlInvalid, storageError: chosen.storageError });
    langLog('language', langState.lang, '(' + langState.source + ')', chosen.urlInvalid ? 'invalid ?lang ignored' : '', chosen.storageError ? 'localStorage unavailable: ' + chosen.storageError : '');
    if (!$('lang-box')) { publishLangInfo(); return; }
    langUi.ru().onclick = () => { selectLang('ru', true).catch((e) => console.warn('[lang]', e)); };
    langUi.en().onclick = () => { selectLang('en', true).catch((e) => console.warn('[lang]', e)); };
    langUi.back().onclick = () => { selectLang('ru', true).catch((e) => console.warn('[lang]', e)); };
    if (langState.lang === 'en') {   // English wanted: the manifest GET inside ensureOverlay is the probe (a 404 there means no overlay on this server)
      langState.overlay = 'absent';
      await ensureOverlay({ status: (t) => { $('lang-status').textContent = t; }, progress: langUi.progress() });
    } else if (!(await probeOverlay())) {   // Russian: one HEAD, only to know whether to offer English
      langState.overlay = 'unavailable';
    } else langState.overlay = 'absent';
    renderLang();
    updateSlotLanguageNote();
  } catch (e) { console.warn('[lang] language selection unavailable:', e); }
}

// before the game starts, under the page-lifetime save lock: English only runs on a complete overlay (see run())
async function overlayLaunchCheck() {
  const O = await import('./overlay.mjs');
  const marker = await readMarker(OVERLAY_TARGET);
  if (!langState.validated || marker?.version !== langState.version)
    throw Object.assign(new Error('Английский слой не установлен полностью. Английский режим не запущен; русская установка не затронута. Вернитесь к русскому языку.'), { overlayRefused: true });
  const check = await verifyOverlay();
  if (!check.ok) throw Object.assign(new Error(O.incompleteOverlayMessage(check)), { overlayRefused: true });
  // a game build older than E1 ignores PORT_OVERLAY and would run in Russian under an English label: its glue does not export port_overlay_state
  let glue = '';
  try { glue = await (await fetch('build/game.js', { cache: 'no-cache' })).text(); } catch { /* the script tag will fail the start itself */ }
  if (glue && !/_port_overlay_state\b/.test(glue))
    throw Object.assign(new Error('Эта сборка игры не поддерживает английский слой (нужна сборка с PORT_OVERLAY). Английский режим не запущен; вернитесь к русскому языку.'), { overlayRefused: true });
  langState.launched = { lang: 'en', version: langState.version, hostPath: langState.hostPath, at: new Date().toISOString() };
  publishLangInfo();
}

// ------------------------------------------------------------------ input

// KeyboardEvent.code -> USB HID usage (what host/input.c's key table uses)
const HID = {};
for (let i = 0; i < 26; i++) HID['Key' + String.fromCharCode(65 + i)] = 4 + i;
for (let i = 1; i <= 9; i++) HID['Digit' + i] = 29 + i;
HID.Digit0 = 39;
Object.assign(HID, {
  Enter: 40, Escape: 41, Backspace: 42, Tab: 43, Space: 44, Minus: 45, Equal: 46, BracketLeft: 47, BracketRight: 48,
  Backslash: 49, Semicolon: 51, Quote: 52, Backquote: 53, Comma: 54, Period: 55, Slash: 56, CapsLock: 57,
  PrintScreen: 70, ScrollLock: 71, Pause: 72, Insert: 73, Home: 74, PageUp: 75, Delete: 76, End: 77, PageDown: 78,
  ArrowRight: 79, ArrowLeft: 80, ArrowDown: 81, ArrowUp: 82, NumLock: 83, NumpadDivide: 84, NumpadMultiply: 85,
  NumpadSubtract: 86, NumpadAdd: 87, NumpadEnter: 88, Numpad0: 98, NumpadDecimal: 99,
  ControlLeft: 224, ShiftLeft: 225, AltLeft: 226, MetaLeft: 227, ControlRight: 228, ShiftRight: 229, AltRight: 230, MetaRight: 231,
});
for (let i = 1; i <= 12; i++) HID['F' + i] = 57 + i;
for (let i = 1; i <= 9; i++) HID['Numpad' + i] = 88 + i;

// Netplay: the keyboard drives this player's pad (the game itself gets no keys or mouse, which would desync).
// Online the keyboard drives the player's virtual pad, so this map must cover every key the game's own
// keyboard controls use, modifiers included: map each to the pad button the game uses for the same action
// (see netplay.md, "Inputs"). Shift -> LB (L1) is Cricket 07's lofted-shot modifier; Esc -> Start because
// Esc pauses in solo play and Start is the pad's pause (Backspace stays B, back in menus).
const NET_KEYS = {   // KeyboardEvent.code -> standard-gamepad bit
  Enter: 0, Space: 0, KeyS: 0, Escape: 9, Backspace: 1, KeyD: 1, KeyA: 2, KeyW: 3, KeyQ: 4, KeyE: 5,
  ShiftLeft: 4, ShiftRight: 4,
  Digit1: 6, Digit3: 7, Tab: 8, KeyP: 9, ArrowUp: 12, ArrowDown: 13, ArrowLeft: 14, ArrowRight: 15,
};
let netKeyBits = 0;
let netKeyPressed = 0;   // keys pressed since the last poll, so a tap shorter than a frame still counts

// Для видеомоста (video-player.mjs): время последнего ввода отличает щелчок по «Credits»
// (сразу после ввода) от режима привлечения с «trailer» после 45 с бездействия.
let lastGameInputAt = 0;
const noteGameInput = () => { lastGameInputAt = performance.now(); };

async function hookInput(M, net, consumeTouchPress = () => false) {
  const canvas = $('canvas');
  window.addEventListener('keydown', noteGameInput, true);
  window.addEventListener('mousedown', noteGameInput, true);
  // A mouse-accessible alternative complements F10 when the browser reserves Esc.
  // An actual pointer lock hides the OS pointer, so F10 also works while locked.
  let pulseEscape = () => {};
  $('esc-fallback')?.addEventListener('click', () => pulseEscape());
  if (net) {
    const held = new Map();
    const set = (source, bit, down) => {
      if (down) { held.set(source, bit); netKeyPressed |= 1 << bit; }
      else held.delete(source);
      netKeyBits = 0;
      for (const value of held.values()) netKeyBits |= 1 << value;
    };
    let pulseTimer;
    pulseEscape = () => { clearTimeout(pulseTimer); set('fallback-button', 9, true); pulseTimer = setTimeout(() => set('fallback-button', 9, false), 100); };
    const key = (down) => (e) => {
      const bit = down ? (e.code === 'F10' && window.escapeFallbackActive?.() ? 9 : NET_KEYS[e.code]) : held.get(e.code);
      if (bit === undefined) return;
      if (e.code !== 'Escape') e.preventDefault();
      if (!e.repeat) set(e.code, bit, down);
    };
    window.addEventListener('keydown', key(true));
    window.addEventListener('keyup', key(false));
    window.addEventListener('blur', () => { clearTimeout(pulseTimer); held.clear(); netKeyBits = 0; });
    canvas.addEventListener('contextmenu', (e) => e.preventDefault());
    return;
  }
  // The touch panel uses the same bridge as keyboard/mouse, and is never
  // enabled for netplay. The explicit parameter permits desktop QA.
  let touchMux = null, touchControls = null;
  const wantsTouch = params.get('touch') === '1' || (params.get('touch') !== '0' &&
    window.matchMedia?.('(pointer: coarse)').matches);
  if (wantsTouch) {
    try {
      const { createInputMux, mountTouchControls } = await import('./touch-controls.mjs');
      touchMux = createInputMux({ key: (u, d) => M._input_key_hid(u, d),
        button: (b, d) => M._input_mouse_button(b, d), move: (x, y) => M._input_mouse_move(x, y) });
      touchControls = mountTouchControls({ root: $('touch-controls'), lang: langState.lang, activity: noteGameInput, consumePress: consumeTouchPress, input: {
        key: (u, d) => touchMux.key(1, u, d), button: (b, d) => touchMux.button(1, b, d),
        move: (x, y) => touchMux.move(x, y),
      } });
    } catch (e) { console.warn('Touch controls unavailable:', e); touchMux = null; }
  }
  const sendKey = (u, down) => touchMux ? touchMux.key(0, u, down) : M._input_key_hid(u, down);
  const sendButton = (b, down) => touchMux ? touchMux.button(0, b, down) : M._input_mouse_button(b, down);
  // A keyup or mouseup may happen in another tab or application. Release only
  // inputs this page pressed when focus leaves, otherwise movement can stick.
  const heldKeys = new Map(), heldKeySources = new Map();
  const heldButtons = new Set();
  const setKey = (u, source, down) => {
    const sources = heldKeySources.get(u) || new Set(), wasDown = sources.size > 0;
    if (down) sources.add(source); else sources.delete(source);
    if (sources.size) heldKeySources.set(u, sources); else heldKeySources.delete(u);
    if (wasDown !== (sources.size > 0)) sendKey(u, down ? 1 : 0);
  };
  let pulseTimer;
  pulseEscape = () => { clearTimeout(pulseTimer); setKey(41, 'fallback-button', true); pulseTimer = setTimeout(() => setKey(41, 'fallback-button', false), 100); };
  const key = (down) => (e) => {
    const u = down ? (e.code === 'F10' && window.escapeFallbackActive?.() ? 41 : HID[e.code]) : heldKeys.get(e.code);
    if (u === undefined || e.repeat) return;
    // Escape remains available to the browser when Keyboard Lock is absent or denied.
    // A granted lock is handled by the fullscreen listener before this handler.
    if (e.code !== 'Escape' && !(e.metaKey && !down)) e.preventDefault();
    if (down) heldKeys.set(e.code, u); else heldKeys.delete(e.code);
    setKey(u, e.code, down);
  };
  window.addEventListener('keydown', key(true));
  window.addEventListener('keyup', key(false));
  const releaseButtons = () => {
    for (const b of heldButtons) sendButton(b, 0);
    heldButtons.clear();
  };
  const releaseHeldInput = () => {
    clearTimeout(pulseTimer);
    for (const u of heldKeySources.keys()) sendKey(u, 0);
    releaseButtons();
    heldKeys.clear();
    heldKeySources.clear();
  };
  window.addEventListener('blur', releaseHeldInput);
  document.addEventListener('visibilitychange', () => {
    if (document.hidden) releaseHeldInput();
  });
  // Esc can release Pointer Lock without blurring the page. A mouseup outside
  // the canvas may then never arrive, leaving a button held in the guest.
  let hadPointerLock = document.pointerLockElement === canvas;
  document.addEventListener('pointerlockchange', () => {
    const hasPointerLock = document.pointerLockElement === canvas;
    if (hadPointerLock && !hasPointerLock) releaseButtons();
    hadPointerLock = hasPointerLock;
    // A pending fullscreen capture may resolve after fullscreen has ended.
    if (hasPointerLock && !(document.fullscreenElement || document.webkitFullscreenElement)) {
      try { document.exitPointerLock?.(); } catch {}
    }
  });
  // In a normal window pointer lock gives Escape to the browser instead of
  // the game. Use ordinary relative motion there. Fullscreen can capture the
  // pointer so camera movement is not constrained by screen edges.
  canvas.addEventListener('mousedown', (e) => {
    if ((document.fullscreenElement || document.webkitFullscreenElement) && document.pointerLockElement !== canvas) {
      const p = canvas.requestPointerLock?.();
      if (p && p.catch) p.catch(() => {});
    }
    const b = [0, 2, 1][e.button] ?? 0;
    heldButtons.add(b);
    sendButton(b, 1);
  });
  window.addEventListener('mouseup', (e) => {
    const b = [0, 2, 1][e.button] ?? 0;
    if (heldButtons.delete(b)) sendButton(b, 0);
  });
  // Relative movement is adjusted for the visible horizontal stretch so the
  // game's cursor travels the same distance as the pointer in viewport mode.
  function createMouseMotionMapper(canvas, stage) {
    let fractionalX = 0, fractionalY = 0;
    return (movementX, movementY) => {
      const r = canvas.getBoundingClientRect();
      const stretched = !stage.classList.contains('aspect-preserve') &&
        !canvas.closest('main')?.classList.contains('touch-playing');
      const scaleX = stretched && r.width > 0 && r.height > 0 ? (r.height * 4 / 3) / r.width : 1;
      const x = movementX * scaleX + fractionalX, dx = Math.trunc(x);
      fractionalX = x - dx;
      // The bridge takes int32 values. Preserve subpixel motion on both axes
      // instead of silently discarding small vertical trackpad movements.
      const y = movementY + fractionalY, dy = Math.trunc(y);
      fractionalY = y - dy;
      return [dx, dy];
    };
  }
  const mapMouseMotion = createMouseMotionMapper(canvas, $('stage'));
  canvas.addEventListener('mousemove', (e) => {
    const [dx, dy] = mapMouseMotion(e.movementX, e.movementY);
    M._input_mouse_move(dx, dy);
  });
  canvas.addEventListener('contextmenu', (e) => e.preventDefault());
  return touchControls;
}

// Gamepads (Gamepad API, polled every animation frame). Browsers only expose a pad after a button press
// on it. The game sees each pad as a DirectInput "Logitech Dual Action USB" (host/dinput.c); ?pads=N exposes
// N of them (default 1, at most 4). Like the native feeder (host/window.c), slots are DirectInput pad
// numbers handed out in connection order, not the browser's gamepad.index (which can start above 0, e.g.
// after a reconnect), and a pad keeps its slot until it is unplugged.
// With mapping 'standard' buttons and axes are already in the layout input_gamepad() takes. Other pads
// (older DirectInput-era ones such as the Logitech Precision) report buttons in HID order, as Windows
// DirectInput presents them and as the game's controltypes.csv expects; their axes are indexed by HID
// usage (X Y Z Rx Ry Rz ...), so the right stick is Z/Rz and Chrome puts the hat switch at axes[9].
const PAD_SLOTS = 4;
const padLast = Array.from({ length: PAD_SLOTS }, () => '');
const padSlotIndex = Array(PAD_SLOTS).fill(-1);   // slot -> gamepad.index
const padHats = new Set();   // gamepad.index of pads whose axes[9] is a hat switch
// raw button n -> standard-layout bit that host/dinput.c turns back into DirectInput button n
const STD_FOR_RAW = [2, 0, 1, 3, 4, 5, 6, 7, 9, 8, 10, 11];
// Chrome's hat axis: -1 = up, then clockwise in steps of 2/7; anything outside [-1, 1] is centred
const HAT_DIRS = [1 << 12, (1 << 12) | (1 << 15), 1 << 15, (1 << 13) | (1 << 15), 1 << 13, (1 << 13) | (1 << 14), 1 << 14, (1 << 12) | (1 << 14)];
const axis16 = (v) => Math.round(Math.max(-1, Math.min(1, v || 0)) * 32767);

function readPad(g) {
  let buttons = 0;
  if (g.mapping === 'standard') {
    g.buttons.forEach((b, i) => { if (i < 17 && (b.pressed || b.value > 0.3)) buttons |= 1 << i; });
    return { buttons, ax: [0, 1, 2, 3].map((i) => axis16(g.axes[i])) };
  }
  g.buttons.forEach((b, i) => { if (i < STD_FOR_RAW.length && (b.pressed || b.value > 0.3)) buttons |= 1 << STD_FOR_RAW[i]; });
  // axes[9] is only taken as a hat once it has shown the centred value, so a plain axis resting at 0 isn't
  // read as d-pad down
  const hat = g.axes[9];
  if (hat > 1.1) padHats.add(g.index);
  else if (padHats.has(g.index) && hat >= -1.01) buttons |= HAT_DIRS[Math.round((hat + 1) * 3.5) % 8];
  const ry = g.axes.length > 5 ? g.axes[5] : g.axes[3];
  return { buttons, ax: [axis16(g.axes[0]), axis16(g.axes[1]), axis16(g.axes[2]), axis16(ry)] };
}

// Netplay: one local pad, the first connected gamepad merged with the keyboard (host/netplay.c sends it).
let netLast = '';
function pollLocalPad(M) {
  const g = (navigator.getGamepads ? [...navigator.getGamepads()] : []).find((p) => p && p.connected);
  const { buttons, ax } = g ? readPad(g) : { buttons: 0, ax: [0, 0, 0, 0] };
  const b = buttons | netKeyBits | netKeyPressed;
  netKeyPressed = 0;
  const key = `${b}:${ax.join(',')}`;
  if (key === netLast) return;
  netLast = key;
  M._input_gamepad(0, 1, b, ax[0], ax[1], ax[2], ax[3]);
}

function pollGamepads(M) {
  const pads = navigator.getGamepads ? [...navigator.getGamepads()].filter((g) => g && g.connected) : [];
  // free the slots of unplugged pads, then give new pads the lowest free slot
  for (let s = 0; s < PAD_SLOTS; s++)
    if (padSlotIndex[s] >= 0 && !pads.some((g) => g.index === padSlotIndex[s])) { padHats.delete(padSlotIndex[s]); padSlotIndex[s] = -1; }
  for (const g of pads) {
    if (padSlotIndex.includes(g.index)) continue;
    const s = padSlotIndex.indexOf(-1);
    if (s < 0) break;
    padSlotIndex[s] = g.index;
    console.log(`gamepad ${g.index} -> pad ${s}: ${g.id} (${g.mapping || 'non-standard'} mapping, ${g.buttons.length} buttons, ${g.axes.length} axes)`);
  }
  for (let slot = 0; slot < PAD_SLOTS; slot++) {
    const g = pads.find((p) => p.index === padSlotIndex[slot]);
    const { buttons, ax } = g ? readPad(g) : { buttons: 0, ax: [0, 0, 0, 0] };
    const connected = g ? 1 : 0;
    const key = `${connected}:${buttons}:${ax.join(',')}`;
    if (key === padLast[slot]) continue;
    padLast[slot] = key;
    M._input_gamepad(slot, connected, buttons, ax[0], ax[1], ax[2], ax[3]);
  }
}

// ------------------------------------------------------------------ audio

// Приглушение звука игры на время ролика видеомоста (video-player.mjs, onActive): игра под оверлеем
// продолжает работать, и без этого её музыка играла бы поверх звука ролика. Ring при этом
// вычитывается как обычно (громкость 0), поэтому после ролика нет «хвоста» старого звука.
let audioDuck = null;
async function startAudio(M) {
  if (params.has('mute')) return;
  const ctx = new AudioContext({ sampleRate: 44100, latencyHint: 'interactive' });
  await ctx.audioWorklet.addModule('audio-worklet.js');
  const node = new AudioWorkletNode(ctx, 'port-ring', { outputChannelCount: [2] });
  node.port.postMessage({ memory: M.wasmMemory, ring: M._port_audio_ring() });
  audioDuck = ctx.createGain();
  node.connect(audioDuck);
  audioDuck.connect(ctx.destination);
  const resume = () => ctx.resume();
  // Touch controls stop pointer events from bubbling into game handlers.
  // Observe the real gesture during capture so suspended audio can resume.
  window.addEventListener('pointerdown', resume, true);
  window.addEventListener('keydown', resume, true);
}

// ------------------------------------------------------------------ run

// Replaced once the renderer has started; the aspect button can resize it immediately.
let resizeGameCanvas = () => {};
function sizeCanvas() {
  const canvas = $('canvas');
  const r = canvas.getBoundingClientRect(), dpr = Math.min(window.devicePixelRatio || 1, 2);
  const h = Math.max(480, Math.round(r.height * dpr));
  const stretch = !$('stage').classList.contains('aspect-preserve') &&
    !canvas.closest('main')?.classList.contains('touch-playing');
  // A 4:3 drawing buffer fills the CSS viewport without the renderer's
  // letterboxing. Its content is visibly stretched on a widescreen display.
  canvas.width = stretch ? Math.max(640, Math.round(h * 4 / 3)) : Math.max(640, Math.round(r.width * dpr));
  canvas.height = h;
}

// Only an immutable, validated entry from this page's fixed manifest can be
// repaired or fetched on demand. Both paths use the normal atomic write and
// SHA-256 checks, so an unsuccessful repair leaves an existing file intact.
async function downloadLazyResource(dir, entry, {signal} = {}) {
  const { lazyMutable } = await import('./experimental/lazy-bootstrap.mjs');
  if (!lazyPlan?.files.includes(entry) || lazyMutable(entry.path))
    throw new Error('Lazy request refused: path is not an immutable manifest entry.');
  const progress = () => {};
  if (entry.pack !== undefined && entry.pack !== null)
    await downloadPackRange(GAME_BASE, dir, lazyPlan.packs[entry.pack], [entry], progress, () => {}, {signal});
  else await downloadFile(GAME_BASE, dir, entry.path, entry.size, 0, progress, entry, {signal, verifySha: true});
  return fileHandle(dir, entry.path, false);
}

// Per-slot netplay userdata for paths outside GUEST_ROOT. This does not isolate
// SAVE paths under GUEST_ROOT: map_path still resolves those against the shared
// game root. The runtime holds both save locks for its whole page lifetime
// (runExclusiveForPageLifetime below), which blocks cooperating save flows in
// other tabs but proves nothing about non-cooperating writers.
const netSaves = (session) => `${PORT.id}-netplay-${session.you}`;
async function clearNetSaves(session) {
  const root = await navigator.storage.getDirectory();
  try { await root.removeEntry(netSaves(session), { recursive: true }); } catch { /* not there yet */ }
}

function showNetStatus(M, session) {
  const el = $('netstatus');
  el.classList.remove('hidden');
  let lastFrame = 0, lastT = performance.now();
  setInterval(() => {
    const frame = M._netplay_status(0), desync = M._netplay_status(2);
    const now = performance.now();
    // the game thread always idles until the next frame's inputs arrive; it's only "waiting" when that
    // holds the game below full speed
    const fps = ((frame - lastFrame) * 1000) / Math.max(1, now - lastT);
    lastFrame = frame; lastT = now;
    el.classList.toggle('bad', !!desync);
    el.textContent = desync ? `Out of sync since frame ${desync}: restart the session`
      : `Online · player ${session.you + 1} of ${session.players} · delay ${session.delay}` +
        ` · ${session.client.direct().length ? 'direct' : 'relayed'}` +
        (session.reconnecting ? ' · reconnecting…' : frame > 300 && fps < 50 ? ' · waiting for players' : '') +
        (session.left?.size ? ` · ${session.left.size} left` : '');
  }, 1000);
}

// Read-only resource preflight (missing-resource-preflight.mjs, Ф3.1). Runs before the save locks are
// taken and before any runtime worker exists, so a refusal leaves nothing started or held. It only
// reads game files: no writes to OPFS, SAVE, options or the install marker. Returns false when the
// start must be refused (a file the game cannot run without is missing or unreadable); warnings only
// go to the console and window.resourcePreflight. The check never blocks on its own failure.
async function resourceGate() {
  let v;
  try {
    const { checkResourcesBeforeRun } = await import('./missing-resource-preflight.mjs');
    v = await checkResourcesBeforeRun({
      openGameDir: () => gameDir(false),
      manifest: installedManifest,
      installedVersion: (await readMarker())?.version ?? null,
      exe: EXE,
      required: PORT.files?.required || [],
    });
  } catch (e) { console.warn('resource preflight unavailable:', e); return true; }
  window.resourcePreflight = v.report;
  for (const line of v.log) console.warn(line);
  if (!v.block) return true;
  // stay on the home screen: saves can still be downloaded from there
  status(v.message);
  const el = $('resource-status') || $('backup-status');
  if (el) el.textContent = v.message;
  $('panel').classList.remove('hidden');
  return false;
}

// English only (E5): the same read-only preflight over the overlay folder (missing-resource-preflight.mjs checkOverlayBeforeRun), before
// the save locks and any runtime worker. A refusal is the overlay's problem (a required file missing or damaged, a language.ini that would
// leave the game Russian under an English label): the page returns to the language box with the reason and "back to Russian", nothing was
// started or held. Anything else (recommended files, base files English needs) is a warning in the console and window.overlayPreflight.
// The check never blocks on its own failure; Russian never gets here.
async function overlayResourceGate() {
  let v;
  try {
    const { checkOverlayBeforeRun } = await import('./missing-resource-preflight.mjs');
    if (typeof checkOverlayBeforeRun !== 'function') return true;
    const O = await import('./overlay.mjs');
    v = await checkOverlayBeforeRun({
      openOverlayDir: () => targetDir(OVERLAY_TARGET, false),
      openGameDir: () => gameDir(false),
      files: langState.validated?.files ?? null,
      version: langState.version,
      installedVersion: (await readMarker(OVERLAY_TARGET))?.version ?? null,
      required: O.OVERLAY_REQUIRED, recommended: O.OVERLAY_RECOMMENDED, baseRecommended: O.OVERLAY_BASE_RECOMMENDED,
    });
  } catch (e) { console.warn('overlay preflight unavailable:', e); return true; }
  window.overlayPreflight = v.report;
  for (const line of v.log) console.warn(line);
  if (!v.block) return true;
  langLog('overlay preflight refused', v.code);
  langState.overlay = 'error'; langState.error = uiText(v.message, 'Required English language files are missing or unreadable. Reinstall them or return to Russian; see the browser console for details.');   // Play stays blocked and "back to Russian" is shown until the layer is repaired
  renderLang();
  $('panel').classList.remove('hidden');
  return false;
}

// Every game start owns its save locks for the page's whole lifetime
// (save-owner.mjs): solo owns the game root, online also owns the netplay
// userdata root, and clearNetSaves runs only after both are captured. Other
// cooperating tabs then refuse backup/import/export fast instead of racing
// the running game. A busy refusal leaves nothing held and may be retried; a
// failure after the runtime started keeps the locks held on purpose and can
// only be cleared by reloading the page.
async function run(session) {
  // E1: the language is fixed for this start (a later click cannot change it); English needs a complete overlay, checked below under the lock
  const english = langState.lang === 'en';
  if (EXPERIMENTAL_LAZY && (session || !lazyPlan)) throw new Error('Streaming mode currently supports solo play only.');
  if (english && langState.overlay !== 'ready') {
    renderLang();
    $('lang-status').textContent = langState.error || uiText('Английский слой не готов. Английский режим не запущен; вернитесь к русскому языку.', 'English language files are not ready. The game has not started; return to Russian.');
    return;
  }
  if (!EXPERIMENTAL_LAZY && !(await resourceGate())) return;
  if (english && !(await overlayResourceGate())) return;
  const { runExclusiveForPageLifetime } = await import('./save-owner.mjs');
  // Logical save transaction (Ф4.2), OFF unless the URL has saveTx=1 (and never online): the module is not even
  // loaded otherwise, so the default start is exactly what it was.
  const saveTxMod = !EXPERIMENTAL_LAZY && params.get('saveTx') === '1' && !session ? await import('./save-tx.mjs') : null;
  const saveTx = saveTxMod && saveTxMod.saveTxRequested(params, session) ? saveTxMod : null;
  // recovery of an interrupted overwrite, under the page-lifetime lock, before the game can write (null without saveTx)
  const saveTxStep = saveTx && (async () => {
    status('Проверка журнала сохранений…');
      const opts = { root: await navigator.storage.getDirectory(), rootName: OPFS_DIR, locks: navigator.locks };
      const [rtx, rchoice] = (params.get('saveTxResolve') || '').split(':');
      const result = rtx ? await saveTx.resolveSaveTxConflict({ ...opts, tx: rtx, choice: rchoice })
        : await saveTx.recoverSaveTxLocked(opts);
      if (result.status !== 'clean') console.info('[save-tx]', result);
      if (result.status === 'refused') {
        const open = (result.txs || []).filter(t => t.outcome === 'refused').map(t => t.tx);
        throw Object.assign(new Error('Журнал сохранений требует решения, игра не запущена; данные не изменены. ' +
          (result.message || '') + (open.length ? ` Чтобы оставить текущее содержимое, откройте страницу с &saveTxResolve=${open[0]}:keep-current,` +
          ` чтобы вернуть прежнюю версию - ${open[0]}:restore-prior. Либо уберите saveTx=1.` : '')), { saveTxRefused: result });
      }
      if (result.status !== 'clean' && result.message) status(result.message);
  });
  await runExclusiveForPageLifetime({
    locks: navigator.locks,
    gameRoot: OPFS_DIR,
    netRoot: session ? netSaves(session) : EXPERIMENTAL_LAZY ? LAZY_USERDATA : null,
    clearNet: session ? () => clearNetSaves(session) : async () => {},
    // English: the overlay is re-checked under the page-lifetime lock (nothing can change it between the check and the start);
    // without English and without saveTx this stays null, exactly as before
    beforeStart: EXPERIMENTAL_LAZY ? async () => {
      status('Проверка игровых файлов и восстановление повреждённых…');
      show('loading');
      const { verifyLazyCache, assertLazyIdentity } = await import('./experimental/lazy-bootstrap.mjs');
      if ((await readMarker())?.version !== lazyPlan.version)
        throw new Error(uiText('Игровая версия изменилась в другой вкладке. Перезагрузите страницу перед запуском.', 'The installed game version changed in another tab. Reload this page before playing.'));
      await assertLazyIdentity(await navigator.storage.getDirectory(), OPFS_DIR, lazyPlan);
      const dir = await gameDir(false);
      const verification = await verifyLazyCache(dir, lazyPlan, undefined, {
        repair: (entry) => downloadLazyResource(dir, entry),
      });
      console.info('[lazy] verified cached files:', verification.verified, 'repaired:', verification.repaired);
      if (english) await overlayLaunchCheck();
      // A sibling OPFS file is visible after main.c mounts /opfs. It is not in
      // either the production game root or its SAVE tree. The lock protects
      // another experimental page from changing the index while this one runs.
      const root = await navigator.storage.getDirectory();
      const fh = await root.getFileHandle(LAZY_INDEX_NAME, { create: true });
      const writer = await fh.createWritable();
      try { await writer.write(lazyPlan.index); await writer.close(); }
      catch (e) { try { await writer.abort(); } catch {} throw e; }
    } : english ? async () => { await overlayLaunchCheck(); if (saveTxStep) await saveTxStep(); } : saveTxStep,
    startRuntime: async () => {
      $('panel').classList.add('hidden');
      fullscreenTip();
      sizeCanvas();
      const script = document.createElement('script');
      script.src = 'build/game.js';
      await new Promise((ok, fail) => { script.onload = ok; script.onerror = fail; document.head.appendChild(script); });
      const M = await createPort({
        arguments: ['/opfs/' + OPFS_DIR],
        print: (t) => console.log(t),
        printErr: (t) => console.log(t),
        preRun: [(m) => {
          if (params.has('mute')) m.ENV.PORT_NO_AUDIO = '1';
          if (params.has('log')) m.ENV.PORT_LOG = '1';
          if (EXPERIMENTAL_LAZY) m.ENV.PORT_LAZY_INDEX = '/opfs/' + LAZY_INDEX_NAME;
          if (EXPERIMENTAL_LAZY) m.ENV.PORT_USERDATA = '/opfs/' + LAZY_USERDATA;
          if (saveTx) m.ENV.PORT_SAVE_TX = '1';   // opt-in logical save transaction (host/kernel32.c SAVE_TX)
          // E1: the English overlay folder as the host sees it (OPFS root is mounted at /opfs, host/main.c); never set for Russian,
          // so the host's overlay code does not run then
          if (english) m.ENV.PORT_OVERLAY = langState.hostPath;
          if (params.get('strictShare') === '1' && !session) m.ENV.PORT_STRICT_FILE_SHARE = '1';   // opt-in strict file sharing (F32_AUDIT.md); never on by default
          if (params.get('sea_fallback') === '1') m.ENV.PORT_SEA_FALLBACK = '1';
          // Real cube sampling is the browser default; keep an explicit A/B fallback.
          m.ENV.PORT_CUBE_RENDER = params.get('cube_render') === '0' ? '0' : '1';
          if (params.has('cap')) m.ENV.PORT_CAPTURE = params.get('cap');   // log every draw of frame <cap>
          if (params.has('pads')) m.ENV.PORT_PADS = params.get('pads');
          if (session) Object.assign(m.ENV, PortNetplay.gameEnv(session), { PORT_USERDATA: '/opfs/' + netSaves(session) });
          m.ENV.PORT_LOG_FPS = params.has('fps') ? '1' : '';
          if (!params.has('fps')) delete m.ENV.PORT_LOG_FPS;
        }],
      });
      if (EXPERIMENTAL_LAZY) {
        const { startLazyClient } = await import('./experimental/lazy-client.mjs');
        const { lazyMutable } = await import('./experimental/lazy-bootstrap.mjs');
        const dir = await gameDir(false);
        const install = async (entry, {signal} = {}) => {
          if (!lazyPlan.files.includes(entry) || lazyMutable(entry.path))
            throw new Error('Lazy request refused: path is not an immutable manifest entry.');
          let exists = true;
          try { await fileHandle(dir, entry.path, false); }
          catch (e) { if (e.name === 'NotFoundError') exists = false; else throw e; }
          if (exists) throw new Error(`Lazy request refused: ${entry.path} already exists.`);
          await downloadLazyResource(dir, entry, {signal});
        };
        const lazyStatus = $('netstatus');
        const recovery = $('lazy-recovery'), recoveryMessage = $('lazy-recovery-message');
        const retryButton = $('lazy-retry'), cancelButton = $('lazy-cancel'), reloadButton = $('lazy-reload');
        // Keep keyboard input in the dialog, not the paused game; release the
        // captured mouse so the player can choose an action in fullscreen too.
        for (const type of ['keydown', 'keyup']) recovery.addEventListener(type, e => e.stopPropagation());
        reloadButton.addEventListener('click', () => location.reload());
        const hideRecovery = () => { recovery.classList.add('hidden'); retryButton.onclick = cancelButton.onclick = null; };
        const showRecovery = ({retry, cancel} = {}) => {
          const canRetry = typeof retry === 'function' && typeof cancel === 'function';
          recoveryMessage.textContent = canRetry
            ? 'Проверьте соединение и повторите загрузку. Игра ждёт не более двух минут с начала запроса файла; сохранения не удаляются.'
            : 'Проверьте сеть и место в браузере, затем перезагрузите страницу. Сохранения не удаляются; несохранённый прогресс может быть потерян.';
          retryButton.classList.toggle('hidden', !canRetry); cancelButton.classList.toggle('hidden', !canRetry);
          reloadButton.classList.toggle('hidden', canRetry);
          retryButton.onclick = canRetry ? () => { if (retry()) { hideRecovery(); lazyStatus.textContent = 'Загрузка игровых файлов…'; } } : null;
          cancelButton.onclick = canRetry ? () => cancel() : null;
          try { if (document.pointerLockElement) document.exitPointerLock(); } catch {}
          recovery.classList.remove('hidden');
          (canRetry ? retryButton : reloadButton).focus();
        };
        let loadingTimer;
        const lazyClient = startLazyClient({ M, files: lazyPlan.files, install, onStart: () => {
          clearTimeout(loadingTimer);
          loadingTimer = setTimeout(() => {
            lazyStatus.classList.remove('hidden', 'bad');
            lazyStatus.textContent = 'Загрузка игровых файлов…';
          }, 400);
        }, onRetry: ({attempt, maxAttempts}) => {
          clearTimeout(loadingTimer);
          lazyStatus.classList.remove('hidden', 'bad');
          lazyStatus.textContent = `Нет связи с игровыми файлами. Повторяем загрузку (${attempt + 1}/${maxAttempts})…`;
        }, onResult: ({status, entry, stats}) => {
          clearTimeout(loadingTimer);
          hideRecovery();
          lazyStatus.classList.add('hidden');
          console.debug('[lazy-result]', JSON.stringify({status, path: entry.path, ...stats}));
        }, onExhausted: ({retry, cancel}) => {
          clearTimeout(loadingTimer);
          lazyStatus.classList.add('hidden');
          showRecovery({retry, cancel});
        }, onExpired: ({error}) => {
          console.error('[lazy] resource request expired:', error);
          showRecovery();
        }, onError: (e) => {
          console.error('[lazy] resource download failed:', e);
          showRecovery();
        } });
        window.lazyStats = lazyClient.stats;
      }
      const canvas = $('canvas');
      M._port_gpu_init(canvas.width, canvas.height);
      resizeGameCanvas = () => { sizeCanvas(); M._port_set_canvas_size(canvas.width, canvas.height); };
      new ResizeObserver(resizeGameCanvas).observe(canvas);
      let touchVideo = null;
      const touchControls = await hookInput(M, !!session, () => {
        if (!touchVideo?.active) return false;
        touchVideo.abort();
        return true;
      });
      try {
        const { installSaveReadIndicator } = await import('./save-read-indicator.mjs');
        if (typeof M._port_save_read_count === 'function')
          installSaveReadIndicator($('save-read-activity'), () => M._port_save_read_count());
      } catch (e) { console.warn('save read indicator unavailable:', e); }
      // Видеомост: опрос запросов StartPostVideo в общем цикле кадров (video-player.mjs).
      let pollVideo = () => {};
      let videoBlocksInput = () => false;   // ролик идёт (или закрывшая его кнопка геймпада удержана): ввод игре не отдаём
      try {
        const { createVideoPlayer } = await import('./video-player.mjs');
        const player = createVideoPlayer({
          mount: $('stage'),
          lang: english ? 'en' : 'ru',   // E3: English plays videos/English/Invasion.mp4 and skips the logos/credits (video-player.mjs)
          onActive: (on) => { if (on) touchControls?.releaseAll(); if (audioDuck) audioDuck.gain.value = on ? 0 : 1; },
        });
        touchVideo = player;
        pollVideo = () => player.poll(M, performance.now() - lastGameInputAt);
        videoBlocksInput = () => player.blocksInput;
      } catch (e) { console.warn('video bridge unavailable:', e); }
      if (session) { session.client.attach(M); showNetStatus(M, session); }
      startAudio(M).catch((e) => console.warn('audio unavailable:', e));
      const poll = session ? pollLocalPad : pollGamepads;
      let exiting = false;
      const exitRequested = () => {
        if (exiting) return true;
        if (!M._port_take_close_request?.()) return false;
        exiting = true;
        try { if (document.pointerLockElement) document.exitPointerLock(); } catch { /* navigation also releases capture */ }
        // Navigation destroys the runtime and releases its page-lifetime save
        // locks. Suppress autoplay so an explicit exit stays at the launcher.
        const destination = new URL(location.href);
        destination.searchParams.delete('autoplay');
        location.replace(destination.href);
        return true;
      };
      const frame = () => { if (exitRequested()) return; if (!videoBlocksInput()) poll(M); pollVideo(); M._port_gpu_pump(1); requestAnimationFrame(frame); };
      requestAnimationFrame(frame);
      setInterval(() => { if (!exitRequested()) M._port_gpu_pump(0); }, 1);   // readbacks mid-frame are answered without waiting for vsync
      // Online, a hidden tab still has to present frames (browsers pause requestAnimationFrame there), or the
      // lockstep would freeze every other player with it.
      if (session) setInterval(() => { if (document.hidden) { poll(M); M._port_gpu_pump(1); } }, 16);
      canvas.focus();
      window.port = M;
      if (english && typeof M._port_overlay_state === 'function') {   // what the host made of PORT_OVERLAY: 1 on, 2 refused (then it would not have started)
        langState.launched = { ...langState.launched, hostState: M._port_overlay_state() };
        langLog('host overlay state', langState.launched.hostState);
        publishLangInfo();
      }
    },
  });
}

// the launcher shows this game's name and controls, and offers online play only when port.json says so
function brand() {
  document.title = PORT.name;
  for (const el of document.querySelectorAll('.game-name')) el.textContent = PORT.name;
  $('controls').textContent = PORT.controls;
  if (!PORT.online) { $('go-online').classList.add('hidden'); document.querySelector('.choices').classList.add('single'); }
}

async function boot() {
  brand();
  if (!crossOriginIsolated) { startupStatus('Игра не может запуститься: сервер не настроил изоляцию страницы. Сообщите об этом владельцу сайта.', 'The game cannot start because this site has not enabled cross-origin isolation. Please tell the site owner.'); return; }
  if (!navigator.gpu) { startupStatus('В этом браузере недоступен WebGPU. Попробуйте актуальную версию Chrome, Edge или Safari.', 'This browser has no WebGPU. Try a current version of Chrome, Edge or Safari.'); return; }
  // navigator.gpu can exist with no usable adapter (GPU or driver blocklisted, hardware acceleration off,
  // Remote Desktop / VM): say so instead of starting a game that can only show a black screen
  const adapter = await navigator.gpu.requestAdapter({ powerPreference: 'high-performance' }).catch(() => null) ||
    await navigator.gpu.requestAdapter().catch(() => null) ||
    await navigator.gpu.requestAdapter({ forceFallbackAdapter: true }).catch(() => null);
  if (!adapter) {
    const firefox = /Firefox\//.test(navigator.userAgent);
    startupStatus(
      'WebGPU доступен, но подходящий графический адаптер не найден. ' +
        (firefox ? 'В Firefox поддержка зависит от видеокарты и драйвера (см. about:support, «WebGPU»); попробуйте Chrome или Edge. '
          : 'Проверьте аппаратное ускорение в настройках браузера и обновите видеодрайвер. ') +
        'В удалённом рабочем столе и виртуальных машинах доступ к видеокарте может отсутствовать.',
      'WebGPU is switched on in this browser but it found no usable graphics adapter. ' +
        (firefox ? 'Firefox only enables WebGPU for some GPUs and drivers (see about:support, "WebGPU"); Chrome or Edge usually work. '
          : 'Check that hardware acceleration is on in the browser settings and the graphics driver is up to date. ') +
        'Remote Desktop and virtual machines often have no GPU for the browser.');
    return;
  }
  if (adapter.isFallbackAdapter || adapter.info?.isFallbackAdapter)
    console.warn('WebGPU: only a software (fallback) adapter is available; the game will be slow');
  if (!navigator.storage?.getDirectory) { startupStatus('Браузер не поддерживает необходимое локальное хранилище файлов (OPFS). Попробуйте обновить браузер или открыть игру в другом.', 'This browser does not support the required local file storage (OPFS). Update the browser or try another one.'); return; }
  if (EXPERIMENTAL_LAZY) {
    // Never install a partial tree if the running Wasm cannot fetch missing assets.
    try {
      const glue = await fetch('build/game.js', {cache:'no-store'});
      if (!glue.ok) throw new Error('missing game glue');
      const text = await glue.text();
      if (!text.includes('_port_lazy_poll') || !text.includes('_port_lazy_finish')) throw new Error('streaming Wasm is not installed');
      await import('./experimental/lazy-client.mjs');
    } catch (e) {
      status(uiText('Сборка потоковой загрузки отсутствует или неполна. Сохранения не изменены.', 'The streaming build is missing or incomplete. Saves were not changed.'));
      console.warn('[lazy] disabled:', e);
      return;
    }
  }
  let onlineReady = false;
  const goOnline = () => {
    if (!onlineReady) { setupOnline(); onlineReady = true; }
    show('online');
    ($('np-code').value ? $('np-join') : $('np-name')).focus();
  };
  const ready = async () => {
    show('home');
    if (EXPERIMENTAL_LAZY) {
      await initLanguage();
      $('go-online').disabled = true;
      $('backup-status').textContent = uiText('Игра загружает файлы по мере необходимости. Для сетевой игры откройте страницу с параметром ?lazy=0.', 'The game downloads resources as needed. For multiplayer, open this page with ?lazy=0.');
    } else await initLanguage();   // E1: language choice; English installs/checks its overlay here.
    if (!EXPERIMENTAL_LAZY && params.get('join')) goOnline();   // an invite link goes straight to joining
    if (params.has('autoplay')) $('play').click();
  };
  $('play').onclick = () => run().catch(startFailed);
  $('go-online').onclick = goOnline;
  $('backup-saves').onclick = async () => {
    const buttons = [$('backup-saves'), $('copy-classic-saves'), $('play'), $('go-online')];
    const disabled = buttons.map((button) => button.disabled);
    buttons.forEach((button) => { button.disabled = true; });
    const message = window.setBackupMessage;
    try {
      if (backupUrl) URL.revokeObjectURL(backupUrl);
      backupUrl = null;
      $('backup-download').classList.add('hidden');
      $('backup-download').removeAttribute('href');
      message(() => uiText('Подготовка архива…', 'Preparing save archive…'));
      const { openSaveDirectory, readSaveDirectory, encodeBackup, withSaveLock } = await import('./save-export.mjs');
      await withSaveLock(navigator.locks, OPFS_DIR, async () => {
        const dir = await openSaveDirectory(gameDir);
        const archive = encodeBackup(await readSaveDirectory(dir, await gameDir(false)));
        backupUrl = URL.createObjectURL(new Blob([archive], { type: 'application/zip' }));
        const link = $('backup-download');
        link.href = backupUrl; link.classList.remove('hidden'); link.click();
        message(() => uiText('Архив подготовлен. Проверьте загрузки браузера или нажмите ссылку ниже.', 'Archive ready. Check your browser downloads or use the link below.'));
      });
    } catch (error) { console.warn('Save export failed:', error); message(() => uiText(error.message || 'Не удалось создать архив сохранений.', error?.name === 'SaveLockBusy' ? 'Another game tab holds the save lock. Close it and try again.' : 'Could not create the save archive. See the browser console for details.')); }
    finally { buttons.forEach((button, i) => { button.disabled = disabled[i]; }); }
  };
  for (const b of document.querySelectorAll('[data-go]')) b.onclick = () => show(b.dataset.go);
  $('folder').onchange = async (e) => {
    $('pick').classList.add('hidden');
    try { await importFromPicker(e.target.files); await ready(); }
    catch (err) { status(err.message); $('pick').classList.remove('hidden'); }
  };
  const showPicker = (msg) => {
    status(msg);
    $('pick').classList.remove('hidden');
    $('help').classList.remove('hidden');
  };
  // An update can refuse a legacy or damaged installation before the normal
  // home screen is shown. Keep the existing export operation available under
  // its save lock, but do not start the game or permit imports/copies until a
  // later successful boot has validated the installation.
  const showSaveRecovery = (reason) => {
    $('panel').classList.remove('hidden');
    renderLang();
    $('lang-box').classList.add('hidden');
    $('restore-decision').classList.add('hidden');
    for (const id of ['play','go-online','restore-saves','copy-classic-saves','restore-file','folder']) $(id).disabled = true;
    $('home-tagline').textContent = uiText(
      `Не удалось подготовить игру: ${reason}. Можно скачать архив сохранений; для повторной попытки обновите страницу.`,
      `The game could not be prepared: ${reason}. You can download your save archive; reload the page to try again.`);
    show('home');
  };

  const marker = await readMarker();
  const manifest = await fetchManifest();
  if (manifest) {
    // Serialize the entire backup and sync with cooperating save operations
    // and picker installs. The marker must be re-read under that same lock.
    try {
      const { updateUnderSaveLock, validateManifestFiles } = await import('./save-protection.mjs');
      // Validate before even creating an update backup, including on a current
      // marker; malformed paths are never passed to any write operation.
      (await import('./game-transfer.mjs')).validateManifestPacks(validateManifestFiles(manifest.files), manifest.packs);
      if (EXPERIMENTAL_LAZY) {
        const { planLazyBootstrap, bindLazyIdentity } = await import('./experimental/lazy-bootstrap.mjs');
        lazyPlan = await bindLazyIdentity(planLazyBootstrap(manifest));
      }
      const expectedVersion = lazyPlan?.version || manifest.version;
      const readExpectedMarker = async () => {
        const existing = await readMarker();
        if (EXPERIMENTAL_LAZY && existing?.version === expectedVersion) {
          const { reconcileLazyIdentity } = await import('./experimental/lazy-bootstrap.mjs');
          await reconcileLazyIdentity(await navigator.storage.getDirectory(), OPFS_DIR, lazyPlan, {
            repair: async entry => downloadLazyResource(await gameDir(false), entry),
            inventoryOnly: true,
          });
        }
        return existing;
      };
      await updateUnderSaveLock({
        root: await navigator.storage.getDirectory(), locks: navigator.locks, rootName: OPFS_DIR,
        version: expectedVersion, readMarker: readExpectedMarker,
        sync: async () => {
          if (!lazyPlan) return syncFromServer(manifest);
          const { reconcileLazyIdentity, lazyBootstrapForSync } = await import('./experimental/lazy-bootstrap.mjs');
          await reconcileLazyIdentity(await navigator.storage.getDirectory(), OPFS_DIR, lazyPlan, {
            repair: async entry => downloadLazyResource(await gameDir(false), entry),
          });
          return syncFromServer(await lazyBootstrapForSync(await gameDir(false), lazyPlan));
        },
        onBackup: saved => { if (!saved.skipped) status('Save backup: ' + saved.backup); },
      });
      installedManifest = manifest;
    } catch (err) {
      $('progress').classList.add('hidden');
      console.warn('Game update failed:', err);
      if (EXPERIMENTAL_LAZY) {
        showSaveRecovery(err?.name === 'QuotaExceededError'
          ? uiText('недостаточно места в хранилище', 'browser storage is full')
          : err?.message || String(err));
        return;
      }
      if (err?.name === 'QuotaExceededError') {
        status(uiText('Браузер не смог записать игровые файлы: закончилось место или достигнут лимит хранилища. Освободите место и перезагрузите страницу; сохранения не удалены.', 'The browser could not write the game files because storage is full or its quota was reached. Free space and reload; your saves were not deleted.'));
        return;
      }
      const detail = langState.lang === 'en' && /[А-Яа-яЁё]/.test(err.message || '') ? 'see browser console for details' : err.message;
      status('Update failed (' + detail + '). Close other game tabs or free space, then reload.');
      return;
    }
  } else if (EXPERIMENTAL_LAZY) {
    showSaveRecovery(uiText('манифест игры недоступен', 'the game manifest is unavailable'));
    return;
  } else if (!manifest && !marker) {
    showPicker(`Choose your ${PORT.name} game folder to start.`);
    return;
  }
  await ready();
}

// ------------------------------------------------------------------ fullscreen

// The stage (game + overlays) fills fullscreen; the aspect control optionally restores 4:3.
// Alt+Enter (Option+Enter on a Mac) toggles it, as in PC games of the time; it is caught
// before the game's own key handling so Enter doesn't also reach a menu.
function setupFullscreen() {
  const stage = $('stage'), aspect = $('aspect'), canvas = $('canvas');
  const active = () => document.fullscreenElement || document.webkitFullscreenElement;
  const aspectKey = `${PORT.id}-display-aspect`;
  try { stage.classList.toggle('aspect-preserve', safeLocalStorage()?.getItem(aspectKey) === '4:3'); } catch { /* storage is optional */ }
  let keyboardLocked = false, generation = 0, noticeTimer;
  // A double press is a convenience only while the browser has granted
  // Keyboard Lock. Esc is otherwise reserved by the browser itself.
  let escapeDown = false, escapeReleasedAt = null;
  const resetEscapeSequence = () => { escapeDown = false; escapeReleasedAt = null; };
  window.escapeFallbackActive = () => active() ? !keyboardLocked : document.pointerLockElement === canvas;
  const notice = (text) => {
    const el = $('fs-notice'); if (!el) return;
    clearTimeout(noticeTimer); $('fstip')?.classList.add('hidden'); el.textContent = text; el.classList.remove('hidden');
    noticeTimer = setTimeout(() => el.classList.add('hidden'), 7000);
  };
  const labels = () => {
    const preserve = stage.classList.contains('aspect-preserve');
    aspect.textContent = preserve ? '↔' : '4:3';
    aspect.setAttribute('aria-pressed', String(preserve));
    const description = preserve
      ? uiText('Заполнить окно: изображение будет растянуто по ширине.', 'Fill the window: the image will be stretched horizontally.')
      : uiText('Вернуть оригинальные пропорции 4:3; сейчас изображение растянуто по ширине.', 'Restore original 4:3 proportions; the image is currently stretched horizontally.');
    aspect.title = description; aspect.setAttribute('aria-label', description);
    $('fs-icon').setAttribute('d', active() ? 'M9 4v5H4M15 4v5h5M9 20v-5H4M15 20v-5h5' : 'M4 9V4h5M20 9V4h-5M4 15v5h5M20 15v5h-5');
    $('fs').title = active()
      ? (keyboardLocked ? uiText('Выйти: двойное Esc, удержание Esc или Alt+Enter', 'Exit: double Esc, hold Esc or Alt+Enter') : uiText('Выйти: Alt+Enter или Esc', 'Exit: Alt+Enter or Esc'))
      : uiText('Полный экран (Alt+Enter)', 'Fullscreen (Alt+Enter)');
    const escapeButton = $('esc-fallback');
    if (escapeButton) {
      escapeButton.classList.toggle('hidden', !window.escapeFallbackActive());
      const description = uiText('Игровая клавиша Esc (также F10; на Mac — Fn+F10)', 'Game Escape key (also F10; on Mac use Fn+F10)');
      escapeButton.title = description; escapeButton.setAttribute('aria-label', description);
    }
  };
  window.updateViewportControls = labels;
  aspect.onclick = () => {
    const preserve = !stage.classList.contains('aspect-preserve');
    stage.classList.toggle('aspect-preserve', preserve);
    try { safeLocalStorage()?.setItem(aspectKey, preserve ? '4:3' : 'fill'); } catch { /* private browsing may block storage */ }
    labels(); resizeGameCanvas(); canvas.focus();
  };
  const toggle = () => {
    if (active()) (document.exitFullscreen || document.webkitExitFullscreen)?.call(document)?.catch?.(() => {});
    else {
      // Keep the optional touch panel inside fullscreen rather than hiding it.
      const target = $('touch-controls') && !$('touch-controls').hidden ? $('touch-controls').closest('main') : stage;
      (target.requestFullscreen || target.webkitRequestFullscreen)?.call(target)?.catch?.(() => {});
    }
    canvas.focus();
  };
  const fullscreenAvailable = !!(stage.requestFullscreen || stage.webkitRequestFullscreen);
  if (!fullscreenAvailable) $('fs').classList.add('hidden');
  else $('fs').onclick = toggle;
  const swallow = (e) => {
    // Only a granted Keyboard Lock permits an Escape to be forwarded without
    // exiting native fullscreen. Never interfere with the browser otherwise.
    if (e.code === 'Escape' && active() && keyboardLocked) {
      e.preventDefault();
      // A complete keyup is required between presses, so autorepeat or a
      // held key cannot accidentally leave fullscreen. Forward the first
      // press/release to the game and consume only the second press.
      if (e.type === 'keyup') {
        if (escapeDown) { escapeDown = false; escapeReleasedAt = e.timeStamp; }
      } else if (!e.repeat && !escapeDown) {
        const elapsed = e.timeStamp - escapeReleasedAt;
        if (escapeReleasedAt !== null && elapsed >= 0 && elapsed <= 600) {
          resetEscapeSequence(); e.stopImmediatePropagation();
          (document.exitFullscreen || document.webkitExitFullscreen)?.call(document)?.catch?.(() => {});
        } else { escapeDown = true; escapeReleasedAt = null; }
      }
      return;
    }
    if (!fullscreenAvailable || (e.code !== 'Enter' && e.code !== 'NumpadEnter') || !e.altKey) return;
    e.preventDefault(); e.stopImmediatePropagation();
    if (e.type === 'keydown' && !e.repeat) toggle();
  };
  window.addEventListener('keydown', swallow, true);
  window.addEventListener('keyup', swallow, true);
  window.addEventListener('blur', resetEscapeSequence);
  const sync = async () => {
    const serial = ++generation;
    resetEscapeSequence();
    keyboardLocked = false; labels();
    if (!active()) {
      try { navigator.keyboard?.unlock?.(); } catch {}
      // Some browsers can keep pointer lock after leaving fullscreen. Do not
      // reserve Escape or confine the pointer in the ordinary window.
      if (document.pointerLockElement === canvas) { try { document.exitPointerLock?.(); } catch {} }
      return;
    }
    // Chromium requires the site's keyboard-lock permission. A denial or an
    // unsupported browser leaves its normal Escape-to-exit behavior intact.
    try {
      if (!navigator.keyboard?.lock) throw new Error('unsupported');
      await navigator.keyboard.lock(['Escape']);
      if (!active()) { try { navigator.keyboard?.unlock?.(); } catch {} return; }
      if (serial !== generation) return; // A newer fullscreen request owns the lock.
      keyboardLocked = true; labels();
    } catch {
      if (serial === generation && active()) notice(uiText(
        'Браузер не разрешил использовать Esc в полноэкранном режиме. Для меню игры используйте F10 (на Mac — Fn+F10) или кнопку Esc.',
        'The browser did not allow Escape in fullscreen. Use F10 (Fn+F10 on Mac) or the Esc button for the game menu.'));
    }
  };
  document.addEventListener('fullscreenchange', sync);
  document.addEventListener('webkitfullscreenchange', sync);
  document.addEventListener('pointerlockchange', labels);
  // Show the controls while the mouse moves, then fade them out.
  let idle;
  const wake = () => { stage.classList.add('awake'); clearTimeout(idle); idle = setTimeout(() => stage.classList.remove('awake'), 2500); };
  stage.addEventListener('mousemove', wake);
  stage.addEventListener('mouseleave', () => stage.classList.remove('awake'));
  labels(); wake();
}

// once the game starts: a short hint, so players learn the shortcut
function fullscreenTip() {
  const tip = $('fstip');
  if (document.fullscreenElement || document.webkitFullscreenElement || $('fs').classList.contains('hidden')) return;
  tip.classList.remove('hidden');
  tip.style.opacity = '1';
  setTimeout(() => { tip.style.opacity = '0'; }, 5000);
  setTimeout(() => tip.classList.add('hidden'), 5500);
}

// ------------------------------------------------------------------ online lobby

async function buildVersion() {
  // peers must run the same build and game files, or their simulations diverge
  const manifest = await fetchManifest();
  const wasm = await fetch('build/game.wasm', { method: 'HEAD' }).catch(() => null);
  // the ETag comes back weak (W/"...") when the response is compressed: compare only its value
  const etag = (wasm?.headers.get('ETag') || '').replace(/^W\//, '').replace(/"/g, '');
  // English peers must have the same overlay too (their scripts and texts differ from the Russian ones): the version says so, and for
  // Russian it stays exactly what it was
  const en = langState.lang === 'en' && langState.version ? `:en-${langState.version}` : '';
  return `${manifest?.version || 'local'}:${etag || wasm?.headers.get('Content-Length') || '?'}${en}`;
}

function setupOnline() {
  const msg = (t) => { $('np-msg').textContent = t; $('np-lobbymsg').textContent = t; };
  try {
    $('np-name').value = localStorage.getItem('port-name') || '';
    const region = localStorage.getItem('port-region');
    if ([...$('np-region').options].some((o) => o.value === region)) $('np-region').value = region;
  } catch { /* storage blocked */ }
  if (params.get('join')) $('np-code').value = params.get('join').toUpperCase();
  let client = null;
  let lastPlayers = [];

  // create: the host's first connection, which places the room in `region` (the Worker's location hint)
  async function enter(code, create) {
    if (client) return;
    const name = $('np-name').value.trim() || 'Player';
    try { localStorage.setItem('port-name', name); localStorage.setItem('port-region', $('np-region').value); } catch { /* storage blocked */ }
    msg('Connecting…');
    let iceServers;   // from the first ticket (TURN credentials last a day)
    const roomUrl = async () => {   // a fresh ticket each time (they expire after an hour)
      const res = await fetch('_netplay_ticket', { cache: 'no-store' });
      if (!res.ok) throw new Error('Online play is not available on this server.');
      const { ticket, iceServers: ice } = await res.json();
      iceServers ??= ice;
      const url = new URL(`netplay/${code}?ticket=${encodeURIComponent(ticket)}`, location.href);
      if (create) { url.searchParams.set('create', '1'); url.searchParams.set('region', $('np-region').value); create = false; }
      url.protocol = url.protocol === 'https:' ? 'wss:' : 'ws:';
      return url.href;
    };
    let url;
    try { url = await roomUrl(); } catch (e) { msg(e.message); return; }
    const invite = new URL(location.href);
    invite.search = `?join=${code}`;
    $('np-room').textContent = code;
    $('invite').textContent = invite.href;
    const version = await buildVersion();
    let session = null;
    const left = new Set();
    const me = client = PortNetplay.connect({
      url, name, version, reconnectUrl: roomUrl, iceServers, relayOnly: params.get('turn') === 'only',
      onReconnect(state) { if (session) session.reconnecting = state === 'connecting'; },
      onLobby(l) {
        if (client !== me) return;   // a room this page already left
        if (l.started) { msg('That game has already started.'); leave(); return; }
        if ($('view-lobby').classList.contains('hidden')) { msg(''); show('lobby'); }
        $('np-colo').textContent = l.colo ? `Server in ${l.colo}` : '';
        $('np-players').innerHTML = '';
        const mine = l.players.find((p) => p.slot === l.you);
        const el = (tag, cls, text) => { const e = document.createElement(tag); if (cls) e.className = cls; if (text != null) e.textContent = text; return e; };
        for (const p of l.players) {
          const li = el('li');
          const direct = p.slot === l.you ? 0 : Math.max(mine?.p2p?.[p.slot] || 0, p.p2p?.[l.you] || 0);
          const link = p.slot === l.you ? (p.rtt ? `${p.rtt} ms to the room` : 'Connected')
            : direct ? `Direct connection · ${direct} ms` : 'Connected through the room';
          const who = el('div', 'who');
          who.append(el('b', null, p.name), el('small', null, link));
          li.append(el('div', 'avatar', (p.name || '?').trim().charAt(0).toUpperCase() || '?'), who);
          if (p.slot === 0) li.append(el('span', 'tag', 'Host'));
          if (p.slot === l.you) li.append(el('span', 'tag', 'You'));
          $('np-players').appendChild(li);
        }
        if (l.players.length < 2) {
          const li = el('li', 'empty');
          li.append(el('div', 'avatar', '?'), el('div', 'who', 'Waiting for your friend to join…'));
          $('np-players').appendChild(li);
        }
        $('np-hostctl').classList.toggle('hidden', !l.host);
        $('np-start').disabled = l.players.length !== 2;
        if (l.players.length > 2) msg('This is a 1v1 game: only two players can be in the room.');
        lastPlayers = l.players;
        const auto = PortNetplay.autoDelay(l.players);
        $('np-delay').options[0].textContent = `Auto (${auto} frames, ${Math.round(auto * 1000 / 60)} ms)`;
        $('np-wait').classList.toggle('hidden', l.host);
      },
      onStart(s) {
        session = { ...s, client, left };
        run(session).catch(startFailed);
      },
      onLeft(slot) { left.add(slot); },
      onError(e) { msg(e); setTimeout(() => { if ($('np-msg').textContent === e) msg(''); }, 8000); },
      onClose() { if (!session && client === me) { client = null; show('online'); msg('Disconnected from the room.'); } },
    });
  }
  function leave() {
    const c = client;
    client = null;
    c?.close();
    show('online');
  }
  $('np-leave').onclick = () => { leave(); msg(''); };
  $('np-copy').onclick = async () => {
    const b = $('np-copy');
    try { await navigator.clipboard.writeText($('invite').textContent); b.textContent = 'Link copied'; }
    catch { b.textContent = 'Copy failed: share the code instead'; }
    setTimeout(() => { b.textContent = 'Copy invite link'; }, 2000);
  };

  const code5 = () => Array.from(crypto.getRandomValues(new Uint8Array(5)), (b) => 'ABCDEFGHJKLMNPQRSTUVWXYZ23456789'[b % 32]).join('');
  $('np-host').onclick = () => enter(code5(), true).catch((e) => msg(e.message));
  $('np-join').onclick = () => {
    const code = $('np-code').value.trim().toUpperCase();
    if (!/^[A-Z0-9]{4,12}$/.test(code)) { msg('Enter the room code from the host.'); return; }
    enter(code).catch((e) => msg(e.message));
  };
  $('np-start').onclick = () => {
    const v = $('np-delay').value;
    client?.start(v === 'auto' ? PortNetplay.autoDelay(lastPlayers) : Number(v));
  };
}

setupFullscreen();
boot().catch(fail);
