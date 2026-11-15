/* Общие заготовки тестов D3 (пакеты передачи и параллельная установка): хранилище с семантикой OPFS, «сервер»
   (fetch с Range, Content-Range, нарезкой на чанки, обрывами, счётом одновременных запросов) и сборка манифеста с
   пакетами в том же формате, что пишет make_dist.py (gamefiles.write_pack): склейка записей, запись = файл «как есть»
   или его gzip-поток. Без сети и без браузера. */
import { createHash } from 'node:crypto';
import { brotliCompressSync, constants as Z, gzipSync } from 'node:zlib';

export const sha = (b) => createHash('sha256').update(b).digest('hex');
export const missing = () => Object.assign(new Error('missing'), { name: 'NotFoundError' });
export const concat = (parts) => { const o = new Uint8Array(parts.reduce((n, p) => n + p.length, 0)); let k = 0; for (const p of parts) { o.set(p, k); k += p.length; } return o; };
/** Сжимаемые, но не тривиальные байты. */
export const pseudo = (n, seed = 7) => { const o = new Uint8Array(n); let x = seed; for (let i = 0; i < n; i++) { x = (x * 1103515245 + 12345) >>> 0; o[i] = (x >>> 16) % 23 === 0 ? x >>> 24 : 65 + (i % 7); } return o; };
export const noise = (n, seed = 3) => { const o = new Uint8Array(n); let x = seed; for (let i = 0; i < n; i++) { x = (x * 1664525 + 1013904223) >>> 0; o[i] = x >>> 24; } return o; };
export const sleepMs = (ms) => new Promise((r) => setTimeout(r, ms));

/** Хранилище как OPFS: createWritable пишет в «своп», close фиксирует, abort отбрасывает; частичной записи нет. */
export class Dir {
  dirs = new Map(); files = new Map();
  stats = { writes: 0, commits: 0, aborts: 0, removed: [], openWritables: 0, maxOpen: 0 };
  async getDirectoryHandle(name, { create } = {}) {
    if (!this.dirs.has(name)) { if (!create) throw missing(); const d = new Dir(); d.stats = this.stats; this.dirs.set(name, d); }
    return this.dirs.get(name);
  }
  async getFileHandle(name, { create } = {}) {
    if (!this.files.has(name)) { if (!create) throw missing(); this.files.set(name, { data: new Uint8Array() }); }
    const record = this.files.get(name), stats = this.stats;
    return { kind: 'file', async getFile() { return new Blob([record.data.slice()]); },
      async createWritable() {
        const parts = []; let open = true, total = 0;
        stats.openWritables++; stats.maxOpen = Math.max(stats.maxOpen, stats.openWritables);
        const done = () => { if (open) { open = false; stats.openWritables--; } };
        return { async write(v) {
            stats.writes++; total += v.length;
            if (stats.quota !== undefined) { stats.quota -= v.length; if (stats.quota < 0) throw Object.assign(new Error('The quota has been exceeded.'), { name: 'QuotaExceededError' }); }
            parts.push(v.slice()); },
          async close() { stats.commits++; record.data = concat(parts); done(); },
          async abort() { stats.aborts++; done(); } };
      } };
  }
  async removeEntry(n) { if (!this.files.delete(n)) throw missing(); this.stats.removed.push(n); }
  async *entries() { for (const [n, d] of this.dirs) yield [n, { kind: 'directory', ...d, entries: () => d.entries() }]; for (const n of this.files.keys()) yield [n, { kind: 'file', getFile: async () => new Blob([this.files.get(n).data.slice()]) }]; }
}
export async function put(dir, rel, data) {
  const parts = rel.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create: true });
  await dir.getFileHandle(parts.at(-1), { create: true });
  dir.files.get(parts.at(-1)).data = data;
}
export async function read(dir, rel) {
  const parts = rel.split('/');
  try { for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p); } catch { return null; }
  return dir.files.has(parts.at(-1)) ? dir.files.get(parts.at(-1)).data : null;
}
export const existingSize = async (dir, rel) => { const d = await read(dir, rel); return d ? d.length : -1; };
export async function fileHandle(dir, rel, create) {
  const parts = rel.split('/');
  for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p, { create });
  return dir.getFileHandle(parts.at(-1), { create });
}
export async function removeFile(dir, rel) {
  const parts = rel.split('/');
  try { for (const p of parts.slice(0, -1)) dir = await dir.getDirectoryHandle(p); await dir.removeEntry(parts.at(-1)); } catch { /* absent */ }
}

/** Игра: файлы {path: Uint8Array} -> манифест и объекты сервера. Параметры: packSize (байт записей на пакет), maxFile
 *  (запись больше остаётся отдельным объектом), gz (gzip для записей, где это выгодно). Совпадает по смыслу с
 *  gamefiles.plan_packs / write_pack: порядок путей без учёта регистра, `options` отдельно. */
export function buildGame(files, { packSize = 20000, maxFile = 12000, gz = true, pack = true, br = false } = {}) {
  const info = new Map();
  for (const [path, data] of Object.entries(files)) {
    const g = gz && data.length >= 1024 && path !== 'options' ? gzipSync(data, { level: 6 }) : null;
    const useGz = g && g.length <= data.length * 0.95;
    let rec = useGz ? g : data, enc = useGz ? 'gzip' : null;
    if (br && data.length >= 1024 && path !== 'options') {   // D1b: brotli wins when it is >= 5 % smaller than the best alternative
      const b = brotliCompressSync(data, { params: { [Z.BROTLI_PARAM_QUALITY]: 9, [Z.BROTLI_PARAM_LGWIN]: 22 } });
      if (b.length <= data.length * 0.95 && b.length <= rec.length * 0.95) { rec = b; enc = 'br'; }
    }
    info.set(path, { path, data, rec, enc });
  }
  const objects = {}, entries = [], packs = [];
  const order = [...info.keys()].sort((a, b) => a.toLowerCase().localeCompare(b.toLowerCase()) || (a < b ? -1 : 1));
  let cur = [], used = 0;
  const flush = () => {
    if (!cur.length) return;
    const index = packs.length, blob = Buffer.concat(cur.map((i) => Buffer.from(i.rec)));
    const name = `_k2pack/${String(index).padStart(4, '0')}-${sha(blob).slice(0, 12)}.pack`;
    objects[name] = blob;
    let off = 0;
    for (const i of cur) { entries.push({ path: i.path, size: i.data.length, sha256: sha(i.data), ...(i.enc ? { enc: i.enc } : {}), csize: i.rec.length, pack: index, offset: off }); off += i.rec.length; }
    packs.push({ path: name, size: blob.length, files: cur.length });
    cur = []; used = 0;
  };
  for (const p of order) {
    const i = info.get(p);
    if (!pack || p === 'options' || i.rec.length > maxFile) {
      const key = i.enc === 'br' ? p + '.br' : i.enc ? p + '.gz' : p;
      objects[key] = Buffer.from(i.rec);
      entries.push({ path: p, size: i.data.length, sha256: sha(i.data), ...(i.enc ? { enc: i.enc, csize: i.rec.length } : {}) });
      continue;
    }
    if (cur.length && used + i.rec.length > packSize) flush();
    cur.push(i); used += i.rec.length;
  }
  flush();
  entries.sort((a, b) => (a.path < b.path ? -1 : a.path > b.path ? 1 : 0));
  return { manifest: { version: 'v-test', files: entries, ...(packs.length ? { packs } : {}) }, objects, files };
}

/** «Сервер»: ключ -> байты. Нарезка на чанки, Range (206 + Content-Range или игнорирование Range), счёт запросов и
 *  одновременных запросов, задержка на запрос, внедрение сбоев `fault(info) -> 'cut'|'404'|'500'|undefined|{...}`. */
export function server(objects, { chunk = 1000, delay = 0, honorRange = true, fault = null, headers = {} } = {}) {
  const log = [];
  const state = { inflight: 0, maxInflight: 0, started: 0 };
  const fetchImpl = async (url, init = {}) => {
    const key = decodeURIComponent(new URL(url).pathname.replace(/^\/game\//, ''));
    const rangeHeader = init.headers?.Range ?? null;
    const info = { key, range: rangeHeader, n: ++state.started };
    log.push(info);
    state.inflight++; state.maxInflight = Math.max(state.maxInflight, state.inflight);
    const finish = () => { if (!info.done) { info.done = true; state.inflight--; } };
    try {
      if (init.signal?.aborted) throw init.signal.reason ?? Object.assign(new Error('aborted'), { name: 'AbortError' });
      if (delay) await sleepMs(delay);
      if (init.signal?.aborted) throw init.signal.reason ?? Object.assign(new Error('aborted'), { name: 'AbortError' });
      let body = objects[key];
      const f = fault?.(info);
      if (!body || f === '404') { finish(); return new Response('nope', { status: 404 }); }
      if (f === '500') { finish(); return new Response('boom', { status: 500 }); }
      let status = 200, extra = { ...headers }, start = 0;
      if (rangeHeader && honorRange) {
        const m = /^bytes=(\d+)-(\d*)$/.exec(rangeHeader);
        if (!m) { finish(); return new Response('bad range', { status: 416 }); }
        const a = +m[1], b = m[2] === '' ? body.length - 1 : Math.min(+m[2], body.length - 1);
        if (a >= body.length) { finish(); return new Response('', { status: 416 }); }
        let cr = `bytes ${a}-${b}/${body.length}`;
        if (f && f.contentRange) cr = f.contentRange;
        body = body.subarray(a, b + 1); status = 206; start = a; extra['content-range'] = cr;
      }
      if (f && f.mutate) body = f.mutate(Buffer.from(body), start);   // start: смещение первого байта ответа в объекте
      let off = 0, sent = 0;
      const cutAt = f === 'cut' ? Math.max(1, Math.floor(body.length / 2)) : f && f.cutAt !== undefined ? f.cutAt : null;
      const stream = new ReadableStream({
        async pull(ctl) {
          if (init.signal?.aborted) { finish(); ctl.error(init.signal.reason ?? Object.assign(new Error('aborted'), { name: 'AbortError' })); return; }
          if (cutAt !== null && sent >= cutAt) { finish(); ctl.error(new TypeError('network error (cut)')); return; }
          if (off >= body.length) { finish(); ctl.close(); return; }
          const n = Math.min(chunk, body.length - off, cutAt !== null ? Math.max(1, cutAt - sent) : Infinity);
          ctl.enqueue(new Uint8Array(body.subarray(off, off + n))); off += n; sent += n;
          if (delay && (sent % (chunk * 8)) < chunk) await sleepMs(0);
        },
        cancel() { finish(); },
      });
      return new Response(stream, { status, headers: extra });
    } catch (e) { finish(); throw e; }
  };
  fetchImpl.log = log; fetchImpl.state = state;
  return fetchImpl;
}

/** То же подключение, что у port.js (downloadFile / downloadPackRange) на тестовом хранилище и сервере. */
export function wire(T, { dir, fetchImpl, base = 'http://t/game/', packs = [] }) {
  return {
    async downloadFile(d, rel, size, from, onBytes, entry, ctx) {
      if (entry?.enc) {
        const target = T.createSafeWriteTarget({ getFile: create => fileHandle(d, rel, create), removeFile: () => removeFile(d, rel) });
        return T.downloadPackedFile({ entry, url: base + T.remotePath(entry), fetchImpl, onBytes, signal: ctx?.signal, ...target });
      }
      const res = await fetchImpl(base + rel, { headers: from > 0 ? { Range: `bytes=${from}-` } : {}, cache: 'no-store', signal: ctx?.signal });
      if (!res.ok) throw new Error(`${rel}: HTTP ${res.status}`);
      const w = await (await fileHandle(d, rel, true)).createWritable();
      try {
        const reader = res.body.getReader();
        for (;;) { const { done, value } = await reader.read(); if (done) break; await w.write(value); onBytes(value.length); }
        await w.close();
      } catch (e) { try { await w.abort(); } catch { /* ignore */ } throw e; }
      const got = await existingSize(d, rel);
      if (got !== size) throw new Error(`${rel}: got ${got} of ${size} bytes`);
    },
    async downloadPackRun(d, pack, entries, onBytes, onFile, ctx) {
      const targets = new Map();
      const target = e => { if (!targets.has(e.path)) targets.set(e.path, T.createSafeWriteTarget({ getFile: create => fileHandle(d, e.path, create), removeFile: () => removeFile(d, e.path) })); return targets.get(e.path); };
      return T.downloadPackRun({ pack, entries, url: base + pack.path, fetchImpl, onBytes, onFile, signal: ctx?.signal,
        openWritable: e => target(e).openWritable(), discard: e => target(e).discard() });
    },
  };
}
