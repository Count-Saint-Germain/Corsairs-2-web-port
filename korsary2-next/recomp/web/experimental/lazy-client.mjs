/* Experimental bridge consumer; never loaded by the regular launcher.
 * `files` must already have been validated with validateManifestFiles and
 * validateManifestPacks. `install` must use the isolated, page-locked root,
 * verify size and SHA-256 against this exact manifest, and never overwrite an
 * existing file. Saves and other mutable files are never accepted here. */
const CAP = 1024;
const mutable = /^(?:save|save_meta|save_tx|options|engine\.ini)(?:\/|$)/i;

export function startLazyClient({ M, files, install, onError = console.error, onResult = () => {},
  intervalMs = 20, timers = globalThis } = {}) {
  if (!M?.wasmMemory?.buffer || typeof M._malloc !== 'function' || typeof M._free !== 'function' ||
      typeof M._port_lazy_poll !== 'function' || typeof M._port_lazy_current !== 'function' ||
      typeof M._port_lazy_finish !== 'function' || !Array.isArray(files) || typeof install !== 'function')
    throw new TypeError('lazy client requires a compatible experimental build and validated manifest');
  const byPath = new Map();
  for (const f of files) {
    if (!f || typeof f.path !== 'string' || !f.path || byPath.has(f.path))
      throw new TypeError('invalid or duplicate manifest path');
    if (!mutable.test(f.path)) byPath.set(f.path, f);
  }
  const ptr = M._malloc(CAP);
  if (!ptr) throw new Error('cannot allocate lazy request buffer');
  let stopped = false, active = null;
  const stats = { requested: 0, installed: 0, failed: 0, unpackedBytes: 0, recordBytes: 0 };
  const decoder = new TextDecoder('utf-8', { fatal: true });
  const report = (err) => { try { onError(err); } catch { /* reporting cannot block completion */ } };
  // The game thread may momentarily own the request mutex. Never block the
  // browser main thread and never drop a completion because of contention.
  const finish = async (token, success) => {
    while (M._port_lazy_current(token)) {
      if (M._port_lazy_finish(token, success) !== -1) return;
      await new Promise(resolve => timers.setTimeout(resolve, 1));
    }
  };
  const poll = () => {
    if (stopped || active) return;
    let token = 0;
    try {
      token = M._port_lazy_poll(ptr, CAP) >>> 0;
      if (!token) return;
      // TextDecoder rejects SharedArrayBuffer views in some browsers; slice
      // copies the NUL-terminated path out of shared WebAssembly memory.
      const bytes = new Uint8Array(M.wasmMemory.buffer, ptr, CAP);
      const end = bytes.indexOf(0);
      if (end < 0) throw new Error('unterminated lazy request');
      const path = decoder.decode(bytes.slice(0, end));
      const entry = byPath.get(path);
      if (!entry) throw new Error(`lazy request is not an immutable manifest entry: ${path}`);
      if (!M._port_lazy_current(token)) return;
      const controller = new AbortController();
      const task = { token, controller, watchdog: null };
      active = task;
      stats.requested++;
      task.watchdog = timers.setInterval(() => {
        if (stopped || !M._port_lazy_current(token)) controller.abort();
      }, Math.max(20, intervalMs));
      Promise.resolve().then(() => install(entry, { signal: controller.signal })).then(async () => {
        stats.installed++;
        stats.unpackedBytes += entry.size || 0;
        stats.recordBytes += entry.csize ?? entry.size ?? 0;
        try { onResult({status:'installed', entry, stats}); } catch {}
        if (!stopped) await finish(token, 1);
      }, async (err) => {
        stats.failed++;
        try { onResult({status:'failed', entry, error:err, stats}); } catch {}
        if (!stopped && M._port_lazy_current(token)) { report(err); await finish(token, 0); }
      }).finally(() => {
        timers.clearInterval(task.watchdog);
        if (active === task) active = null;
      });
    } catch (err) {
      report(err);
      if (token) void finish(token, 0);
    }
  };
  const timer = timers.setInterval(poll, Math.max(1, intervalMs));
  return {
    stats,
    stop() {
      if (stopped) return;
      stopped = true;
      timers.clearInterval(timer);
      if (active) {
        timers.clearInterval(active.watchdog);
        active.controller.abort();
        void finish(active.token, 0);
      }
      M._free(ptr);
    },
  };
}
