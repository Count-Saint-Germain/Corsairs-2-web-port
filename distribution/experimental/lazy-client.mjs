/* Experimental bridge consumer; never loaded by the regular launcher.
 * `files` must already have been validated with validateManifestFiles and
 * validateManifestPacks. `install` must use the isolated, page-locked root,
 * verify size and SHA-256 against this exact manifest, and never overwrite an
 * existing file. Saves and other mutable files are never accepted here. */
const CAP = 1024;
const mutable = /^(?:save|save_meta|save_tx|options|engine\.ini)(?:\/|$)/i;

// Retry transient transport failures, never integrity, storage, or cancellation
// errors. The transfer functions include the HTTP status in their error text.
export function isTransientLazyError(error) {
  if (!error || ['AbortError','QuotaExceededError','TransferIntegrityError'].includes(error.name)) return false;
  if (/\bHTTP\s+(?:408|429|5\d\d)\b/i.test(String(error.message))) return true;
  return error.name === 'NetworkError' || (error.name === 'TypeError' && /(?:failed to fetch|network\s*error|load failed)/i.test(String(error.message)));
}

export function startLazyClient({ M, files, install, onError = console.error, onResult = () => {}, onStart = () => {}, onRetry = () => {},
  onExhausted, onExpired = () => {}, intervalMs = 20, retryDelaysMs = [500, 1500, 3000], timers = globalThis } = {}) {
  if (!M?.wasmMemory?.buffer || typeof M._malloc !== 'function' || typeof M._free !== 'function' ||
      typeof M._port_lazy_poll !== 'function' || typeof M._port_lazy_current !== 'function' ||
      typeof M._port_lazy_finish !== 'function' || !Array.isArray(files) || typeof install !== 'function' ||
      !Array.isArray(retryDelaysMs) || retryDelaysMs.some(n => !Number.isFinite(n) || n < 0) ||
      (onExhausted !== undefined && typeof onExhausted !== 'function') || typeof onExpired !== 'function')
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
      const accepted = M._port_lazy_finish(token, success);
      if (accepted !== -1) return accepted !== 0;
      await new Promise(resolve => timers.setTimeout(resolve, 1));
    }
    return false;
  };
  const retryDelay = (ms, signal) => new Promise((resolve, reject) => {
    if (signal.aborted) { reject(Object.assign(new Error('Lazy request aborted'), {name:'AbortError'})); return; }
    let timer;
    const abort = () => { timers.clearTimeout(timer); signal.removeEventListener('abort', abort); reject(Object.assign(new Error('Lazy request aborted'), {name:'AbortError'})); };
    signal.addEventListener('abort', abort, {once:true});
    timer = timers.setTimeout(() => { signal.removeEventListener('abort', abort); resolve(); }, ms);
  });
  // Keep the guest's existing request pending while the player decides. The
  // guest owns the deadline; its watchdog aborts this prompt and prevents an
  // old choice from completing a newer request.
  const askToRetry = (entry, error, task) => new Promise((resolve, reject) => {
    const signal = task.controller.signal;
    let settled = false;
    const complete = (retry) => {
      if (settled) return false;
      settled = true;
      signal.removeEventListener('abort', abort);
      retry ? resolve() : reject(error);
      return true;
    };
    const abort = () => complete(false);
    if (signal.aborted) { abort(); return; }
    signal.addEventListener('abort', abort, {once:true});
    try { onExhausted({entry, error, retry:()=>complete(true), cancel:()=>complete(false)}); }
    catch { complete(false); }
  });
  const installWithRetry = async (entry, task) => {
    for (let attempt = 0;; attempt++) {
      if (stopped || task.controller.signal.aborted || !M._port_lazy_current(task.token))
        throw Object.assign(new Error('Lazy request aborted'), {name:'AbortError'});
      try { await install(entry, {signal:task.controller.signal}); return; }
      catch (error) {
        if (!isTransientLazyError(error) || task.controller.signal.aborted || stopped || !M._port_lazy_current(task.token)) throw error;
        if (attempt >= retryDelaysMs.length) {
          if (!onExhausted) throw error;
          await askToRetry(entry, error, task);
          // Restart the bounded automatic attempts, without changing the guest
          // token or its original deadline.
          attempt = -1;
          continue;
        }
        try { onRetry({entry, error, attempt:attempt+1, maxAttempts:retryDelaysMs.length+1, delayMs:retryDelaysMs[attempt]}); } catch {}
        await retryDelay(retryDelaysMs[attempt], task.controller.signal);
      }
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
      try { onStart({entry, stats}); } catch {}
      task.watchdog = timers.setInterval(() => {
        if (stopped || !M._port_lazy_current(token)) controller.abort();
      }, Math.max(20, intervalMs));
      Promise.resolve().then(() => installWithRetry(entry, task)).then(async () => {
        // A completed download is safe to retain, but it must not make a
        // guest request that timed out appear to have resumed successfully.
        if (stopped) return;
        if (!await finish(token, 1)) {
          try { onResult({status:'failed', entry, stats}); } catch {}
          try { onExpired({entry, error:new Error('Lazy request expired')}); } catch {}
          return;
        }
        stats.installed++;
        stats.unpackedBytes += entry.size || 0;
        stats.recordBytes += entry.csize ?? entry.size ?? 0;
        try { onResult({status:'installed', entry, stats}); } catch {}
      }, async (err) => {
        stats.failed++;
        try { onResult({status:'failed', entry, error:err, stats}); } catch {}
        if (!stopped && M._port_lazy_current(token)) { report(err); await finish(token, 0); }
        else if (!stopped) { try { onExpired({entry, error:err}); } catch {} }
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
