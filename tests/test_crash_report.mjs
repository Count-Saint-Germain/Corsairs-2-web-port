// Crash reporter unit tests (korsary2-next/recomp/web/crash-report.mjs): ring bounds,
// error hooks, the fatal latch, watchdog states, report privacy and storage. Everything
// runs on injected fakes with a settable clock — no browser, no real fetch, no real
// storage.
import test from 'node:test';
import assert from 'node:assert/strict';
import { createCrashReporter } from '../korsary2-next/recomp/web/crash-report.mjs';

function makeWin() {
  const listeners = {};
  return {
    listeners,
    location: { href: 'http://127.0.0.1:8007/?lazy=1&join=ABCD12' },
    navigator: { userAgent: 'TestBrowser/1', language: 'ru' },
    addEventListener(name, fn) { (listeners[name] ??= []).push(fn); },
    emit(name, event) { for (const fn of listeners[name] ?? []) fn(event); },
  };
}

function fakeStorage() {
  const map = new Map();
  let failNext = false;
  return {
    setItem(k, v) { if (failNext) { failNext = false; const e = new Error('quota'); e.name = 'QuotaExceededError'; throw e; } map.set(k, String(v)); },
    getItem(k) { return map.has(k) ? map.get(k) : null; },
    removeItem(k) { map.delete(k); },
    failNextSet() { failNext = true; },
  };
}

// A settable clock: `t` only moves when a test moves it, so ticks are exact.
function makeBase({ win = makeWin(), doc, storage = fakeStorage(), fetchImpl } = {}) {
  const clock = { t: 1_000_000 };
  const intervalHandlers = [];
  const c = createCrashReporter({
    win,
    doc: doc ?? { hidden: false, createElement() { return { click() {}, remove() {} }; } },
    storage,
    fetchImpl: fetchImpl ?? (async () => ({ ok: false, status: 404 })),
    now: () => clock.t,
    intervalFn: (fn) => { intervalHandlers.push(fn); return intervalHandlers.length; },
    ringLimit: 5,
    lineLimit: 20,
    watchdogMs: 10000,
    watchIntervalMs: 5000,
  });
  return { c, clock, intervalHandlers, win, storage };
}

test('ring keeps the newest lines within the limit and clips long ones', async () => {
  const { c, clock } = makeBase();
  clock.t += 1000; c.note('line-1');
  clock.t += 1000; c.note('line-2');
  for (let i = 3; i <= 8; i++) { clock.t += 1000; c.note(`line-${i}`); }
  c.note('y'.repeat(100));
  const report = await c.buildReport('test');
  assert.equal(report.console.length, 5);                       // ringLimit
  assert.match(report.console.at(-1), /\+8s y{20}…$/);          // clipped to the cap
  assert.ok(!report.console.some((l) => l.includes('line-3 ')), 'oldest lines dropped');
});

test('global hooks: before runtime start errors are recorded, after — fatal fires once', async () => {
  const { c, win } = makeBase();
  const fatal = [];
  c.onFatal((reason, detail) => fatal.push([reason, detail]));
  c.installGlobalHooks();
  win.emit('error', { message: 'boom', error: new Error('boom') });
  assert.equal(fatal.length, 0);                     // startup errors are the launcher's own UI
  const report = await c.buildReport('test');
  assert.ok(report.console.some((l) => l.includes('[error]')));
  c.setRuntimeStarted(true);
  win.emit('unhandledrejection', { reason: new Error('late failure') });
  assert.equal(fatal.length, 1);
  assert.equal(fatal[0][0], 'page error');
  win.emit('error', { message: 'second boom' });
  assert.equal(fatal.length, 1);                     // latched: one readable dead-end per incident
});

test('notifyFatal ignores aborts before the runtime started', () => {
  const { c } = makeBase();
  const fatal = [];
  c.onFatal((r) => fatal.push(r));
  c.notifyFatal('wasm abort', 'x');
  assert.equal(fatal.length, 0);
  c.setRuntimeStarted(true);
  c.notifyFatal('wasm abort', 'x');
  assert.deepEqual(fatal, ['wasm abort']);
});

test('watchdog: fires only after the whole threshold of an active loading screen', () => {
  const { c, clock, intervalHandlers } = makeBase();
  const fired = [];
  c.onWatchdog((info) => fired.push(info));
  c.setRuntimeStarted(true);
  c.armWatchdog({ loadingActive: () => true });
  const tick = intervalHandlers.at(-1);
  assert.ok(tick, 'armWatchdog registers one interval');
  clock.t += 5000; tick();                           // 5 s: window opens
  clock.t += 4000; tick();                           // 4 s since the window opened: below
  assert.equal(fired.length, 0);
  clock.t += 6000; tick();                           // 10 s since it opened: past the threshold
  assert.equal(fired.length, 1);
  assert.ok(fired[0].activeMs >= 10000);
  assert.equal(c.getStoredReport(), null);           // the caller stores reports, not the watchdog
});

test('watchdog: rendered frames, a visible recovery dialog and dismiss reset it', () => {
  const { c, clock, intervalHandlers } = makeBase();
  const fired = [];
  c.onWatchdog(() => fired.push(1));
  let loading = true, busy = false;
  c.setRuntimeStarted(true);
  c.armWatchdog({ loadingActive: () => loading, busy: () => busy });
  const tick = intervalHandlers.at(-1);
  const step = (ms = 4000) => { clock.t += ms; tick(); };
  step(); step();                                    // 8 s of loading: window open, below threshold
  assert.equal(fired.length, 0);
  loading = false; c.progressSeen();                 // a rendered frame clears the window
  step(11000);                                       // no loading: nothing accumulates
  assert.equal(fired.length, 0);
  loading = true; busy = true;                       // lazy-recovery dialog owns the wait
  step(); step(); step(); step(2000);                // busy time does not count toward suspicion
  assert.equal(fired.length, 0);
  busy = false; c.progressSeen();                    // the wait is over; the window starts fresh
  step(); step(); step(); step(2000);                // 10 s since it opened: fires
  assert.equal(fired.length, 1);
  c.dismissWatchdog();                               // "keep waiting": quiet for this episode
  fired.length = 0;
  for (let i = 0; i < 4; i++) step();
  assert.equal(fired.length, 0);
  loading = false; c.progressSeen();                 // the screen finally ended…
  loading = true;                                    // …and a new one arms a fresh window
  step(); step(4000); step(4000); step(2000);        // open + 10 s: fires again
  assert.equal(fired.length, 1);
});

test('report strips the private join code and reports identity honestly', async () => {
  const { c } = makeBase({ fetchImpl: async (url) => url.endsWith('identity.json')
    ? { ok: true, json: async () => ({ gameWasmSha256: 'a'.repeat(64), gameManifestVersion: '76201461179e' }) }
    : { ok: false, status: 404 } });
  c.setVersions({ manifestVersion: '76201461179e', gameEnManifestVersion: null });
  const report = await c.buildReport('wasm abort', 'guest trap');
  assert.ok(!report.origin.includes('ABCD12'), 'invite code must not reach the report');
  assert.ok(report.origin.includes('lazy=1'));
  assert.equal(report.identity.error, null);
  assert.equal(report.identity.gameWasmSha256, 'a'.repeat(64));
  assert.equal(report.manifestVersion, '76201461179e');
  assert.equal(report.gameEnManifestVersion, null);
  assert.equal(report.reason, 'wasm abort');
});

test('identity unavailable stays unknown instead of being guessed', async () => {
  const { c } = makeBase();   // the fake fetch answers 404
  const report = await c.buildReport('test');
  assert.equal(report.identity.error, 'unavailable: identity HTTP 404');
});

test('saveReport stores in localStorage and survives quota by trimming the console', async () => {
  const storage = fakeStorage();
  storage.failNextSet();
  const { c, clock } = makeBase({ storage });
  clock.t += 4000; c.note('something happened');
  const report = await c.saveReport('page error', 'x');
  assert.ok(report.console.length > 0);
  const stored = c.getStoredReport();
  assert.ok(stored);
  assert.equal(stored.reason, 'page error');
  assert.ok(stored.console.length <= 60, 'the quota fallback trims the console tail');
  c.clearStoredReport();
  assert.equal(c.getStoredReport(), null);
});

test('download report clicks an anchor with a json filename', async () => {
  const clicks = [];
  const doc = {
    body: { appendChild() {} },
    createElement(tag) {
      assert.equal(tag, 'a');
      const el = { download: '', click() { clicks.push(el.download); }, remove() {} };
      return el;
    },
  };
  const { c } = makeBase({ doc });
  const report = await c.buildReport('test');
  c.downloadReport(report);
  assert.deepEqual(clicks, [`corsairs2-crash-${report.at.replace(/[:.]/g, '-')}.json`]);
});
