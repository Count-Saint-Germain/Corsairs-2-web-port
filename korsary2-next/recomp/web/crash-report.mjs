/* Crash reporting for the launcher:
 * a bounded console ring, a bounded ring of runtime markers, global error hooks, a
 * loading-screen watchdog and one report bundle that turns an emergency into evidence.
 *
 * The module never touches game state and never reloads the page on its own: it only
 * records, and hands decisions to the caller (port.js shows the overlay with
 * "Download report" / "Reload" / "Keep waiting" buttons). If this module fails to
 * load, the launcher works exactly as before (port.js guards every call with `?.`).
 *
 * Everything is injectable (doc/win/storage/fetchImpl/now/timers) so tests can drive
 * it in Node without a browser. Console tails and markers live in memory only; the
 * only persistent trace is the latest report under localStorage (key below), which
 * the player can download after a reload — nothing is ever sent anywhere.
 */

const STORAGE_KEY = 'korsary2.crash-report';
const SCHEMA = 1;

export function createCrashReporter({
  doc = globalThis.document,
  win = globalThis.window,
  storage = win?.localStorage ?? null,
  fetchImpl = (url) => fetch(url),
  now = () => Date.now(),
  intervalFn = (fn, ms) => win?.setInterval?.bind(win)?.(fn, ms) ?? null,
  clearIntervalFn = (h) => win?.clearInterval?.bind(win)?.(h),
  ringLimit = 250,       // console lines kept for the report
  lineLimit = 2000,      // per-line character cap
  markerLimit = 60,      // runtime markers kept for the report
  watchIntervalMs = 5000,
  watchdogMs = 180000,   // loading screen alone for this long raises suspicion
  identityUrl = 'build/identity.json',
} = {}) {
  const start = now();
  const ring = [];       // "[+ms] line" strings, oldest dropped first
  const markers = [];    // {t, kind, detail} bounded ring
  let versions = { manifestVersion: null, gameEnManifestVersion: null };
  let runtimeStarted = false;
  let fatalCb = null, watchdogCb = null;
  let fatalFired = false, hooksInstalled = false;
  let identityPromise = null;
  const watch = { timer: null, loadingSince: null, fired: false, loadingActive: null, busy: null };

  const stamp = () => `+${(now() - start) / 1000 | 0}s`;
  const clip = (s) => (s.length > lineLimit ? s.slice(0, lineLimit) + '…' : s);
  const note = (line) => {
    ring.push(`${stamp()} ${clip(String(line))}`);
    if (ring.length > ringLimit) ring.splice(0, ring.length - ringLimit);
  };
  const mark = (kind, detail = '') => {
    markers.push({ t: stamp(), kind, detail: clip(String(detail)).slice(0, 300) });
    if (markers.length > markerLimit) markers.splice(0, markers.length - markerLimit);
    note(`[marker] ${kind}${detail ? ': ' + detail : ''}`);
  };

  async function fetchIdentity() {
    if (!identityPromise) {
      identityPromise = (async () => {
        try {
          const r = await fetchImpl(identityUrl, { cache: 'no-store' });
          if (!r.ok) throw new Error(`identity HTTP ${r.status}`);
          const j = await r.json();
          if (!j || typeof j !== 'object') throw new Error('identity is not an object');
          return { ...j, error: null };
        } catch (e) {
          return { error: `unavailable: ${e?.message || e}` };   // never fabricate a version
        }
      })();
    }
    return identityPromise;
  }

  /* The launcher strips ?join= before building this URL: invite codes are private. */
  function cleanLocation() {
    try {
      const u = new URL(win.location.href);
      u.searchParams.delete('join');
      return u.href;
    } catch { return String(win?.location?.href ?? ''); }
  }

  async function buildReport(reason, detail = '') {
    const identity = await fetchIdentity();
    return {
      schema: SCHEMA,
      reason: String(reason),
      detail: clip(String(detail)).slice(0, 1000),
      at: new Date(now()).toISOString(),
      origin: cleanLocation(),
      userAgent: win?.navigator?.userAgent ?? '',
      language: win?.navigator?.language ?? '',
      manifestVersion: versions.manifestVersion,
      gameEnManifestVersion: versions.gameEnManifestVersion,
      identity,
      runtimeStarted,
      watchdog: { thresholdMs: watchdogMs, suspicionLatched: watch.fired },
      markers: markers.slice(),
      console: ring.slice(),
    };
  }

  function reportFileName(report) {
    return `corsairs2-crash-${String(report.at).replace(/[:.]/g, '-')}.json`;
  }

  function downloadReport(report) {
    const a = doc.createElement('a');
    a.href = URL.createObjectURL(new Blob([JSON.stringify(report, null, 2)], { type: 'application/json' }));
    a.download = reportFileName(report);
    doc.body?.appendChild(a);
    a.click();
    a.remove();
    setTimeout(() => URL.revokeObjectURL(a.href), 5000);
  }

  function storeReport(report) {
    if (!storage) return false;
    let text = JSON.stringify(report);
    try {
      try { storage.setItem(STORAGE_KEY, text); }
      catch (e) {   // quota: keep the newest evidence, trim the bulk
        text = JSON.stringify({ ...report, console: report.console.slice(-60) });
        storage.setItem(STORAGE_KEY, text);
      }
      return true;
    } catch { return false; }   // storage unavailable: the download path still works
  }

  function getStoredReport() {
    if (!storage) return null;
    try {
      const text = storage.getItem(STORAGE_KEY);
      if (!text) return null;
      const parsed = JSON.parse(text);
      return parsed && typeof parsed === 'object' ? parsed : null;
    } catch { return null; }
  }

  function clearStoredReport() {
    try { storage?.removeItem(STORAGE_KEY); } catch { /* nothing to clear */ }
  }

  function fireFatal(reason, detail) {
    mark('fatal', reason);
    if (!fatalFired) {
      fatalFired = true;
      try { fatalCb?.(reason, detail); } catch { /* reporting must not throw */ }
    }
  }

  return {
    note, mark,
    setVersions(v = {}) { versions = { ...versions, ...v }; },
    setRuntimeStarted(on) {
      if (on && !runtimeStarted) mark('runtime-started');
      runtimeStarted = !!on;
    },
    installGlobalHooks() {
      if (hooksInstalled || !win?.addEventListener) return;
      hooksInstalled = true;
      const onError = (e) => {
        const line = e?.error?.stack || e?.message || String(e?.reason ?? e ?? 'error');
        note(`[error] ${clip(String(line))}`);
        if (runtimeStarted) fireFatal('page error', String(e?.message ?? e ?? 'error'));
      };
      win.addEventListener('error', (e) => onError(e));
      win.addEventListener('unhandledrejection', (e) => onError({ error: e?.reason, message: e?.reason ? String(e.reason) : 'unhandled rejection' }));
    },
    onFatal(cb) { fatalCb = cb; },
    onWatchdog(cb) { watchdogCb = cb; },
    notifyFatal(reason, detail = '') {
      if (!runtimeStarted) { mark('abort-before-start', reason); return; }
      fireFatal(reason, detail);
    },
    progressSeen() {           // a rendered frame without the loading screen: the game answers
      watch.loadingSince = null;
      watch.fired = false;
    },
    armWatchdog({ loadingActive, busy = null } = {}) {
      watch.loadingActive = loadingActive ?? (() => false);
      watch.busy = busy;
      if (!watch.timer && intervalFn) watch.timer = intervalFn(() => {
        if (watch.fired || doc?.hidden) return;
        if (!watch.loadingActive()) { watch.loadingSince = null; return; }
        const t = now();
        if (watch.loadingSince == null) { watch.loadingSince = t; return; }
        if (watch.busy?.()) { watch.loadingSince = null; return; }   // a visible dialog explains the wait; it does not count
        if (t - watch.loadingSince >= watchdogMs) {
          watch.fired = true;
          mark('watchdog', `loading screen active for ${Math.round(watchdogMs / 1000)}s`);
          try { watchdogCb?.({ activeMs: t - watch.loadingSince }); } catch { /* never throws */ }
        }
      }, watchIntervalMs);
    },
    dismissWatchdog() {        // "keep waiting": quiet for this loading episode; progressSeen re-arms
      watch.loadingSince = null;
    },
    buildReport, saveReport: async (reason, detail = '') => {
      const report = await buildReport(reason, detail);
      storeReport(report);
      return report;
    },
    downloadReport, reportFileName, getStoredReport, clearStoredReport, fetchIdentity,
    STORAGE_KEY,
  };
}
