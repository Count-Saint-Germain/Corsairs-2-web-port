// Shared synthetic fixtures for the SAVE_TX tests: an OPFS-shaped directory
// API over a REAL temp directory (so the page code recovers exactly what the
// native host wrote), with deterministic crash/fault injection, and a Web Lock
// model with query(). Nothing here touches player data or a browser.
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';

export class Crash extends Error { constructor(n) { super(`injected crash at mutation ${n}`); this.name = 'Crash'; } }
const domError = (name, message) => Object.assign(new Error(message), { name });

/** ctx = { mutations: 0, crashAt: Infinity, failAt: Infinity, log: [] } counts every namespace/content mutation
 * (mkdir, atomic content commit, remove). crashAt throws Crash BEFORE the n-th mutation takes effect;
 * failAt throws an ordinary QuotaExceededError there instead (a handled I/O failure). */
export function makeCtx() { return { mutations: 0, crashAt: Infinity, failAt: Infinity, log: [] }; }
function mutate(ctx, what) {
  const n = ctx.mutations++;
  ctx.log.push(what);
  if (n === ctx.crashAt) throw new Crash(n);
  if (n === ctx.failAt) throw domError('QuotaExceededError', `injected quota failure at mutation ${n}`);
}

class FileHandle {
  constructor(p, name, ctx) { this.kind = 'file'; this.p = p; this.name = name; this.ctx = ctx; }
  async getFile() {
    let st;
    try { st = fs.statSync(this.p); } catch { throw domError('NotFoundError', this.name); }
    const p = this.p;
    return { size: st.size, name: this.name, async arrayBuffer() { const b = fs.readFileSync(p); return b.buffer.slice(b.byteOffset, b.byteOffset + b.length); } };
  }
  async createWritable() {
    const chunks = [], { p, ctx, name } = this;
    return {
      async write(data) { chunks.push(Buffer.from(data instanceof Uint8Array ? data : new Uint8Array(data))); },
      async close() {   // atomic swap on close, like Chromium's swap-file based writable
        mutate(ctx, `write ${name}`);
        const tmp = `${p}.swap-${process.pid}`;
        fs.writeFileSync(tmp, Buffer.concat(chunks));
        fs.renameSync(tmp, p);
      },
      async abort() { chunks.length = 0; },
    };
  }
}
class DirHandle {
  constructor(p, name, ctx) { this.kind = 'directory'; this.p = p; this.name = name; this.ctx = ctx; }
  #stat(n) { try { return fs.statSync(path.join(this.p, n)); } catch { return null; } }
  async getDirectoryHandle(n, { create } = {}) {
    const st = this.#stat(n);
    if (st && !st.isDirectory()) throw domError('TypeMismatchError', n);
    if (!st) {
      if (!create) throw domError('NotFoundError', n);
      mutate(this.ctx, `mkdir ${n}`);
      fs.mkdirSync(path.join(this.p, n));
    }
    return new DirHandle(path.join(this.p, n), n, this.ctx);
  }
  async getFileHandle(n, { create } = {}) {
    const st = this.#stat(n);
    if (st && st.isDirectory()) throw domError('TypeMismatchError', n);
    if (!st) {
      if (!create) throw domError('NotFoundError', n);
      mutate(this.ctx, `create ${n}`);
      fs.writeFileSync(path.join(this.p, n), '');
    }
    return new FileHandle(path.join(this.p, n), n, this.ctx);
  }
  async removeEntry(n, { recursive } = {}) {
    const st = this.#stat(n);
    if (!st) throw domError('NotFoundError', n);
    mutate(this.ctx, `remove ${n}`);
    fs.rmSync(path.join(this.p, n), { recursive: !!recursive });
  }
  async *entries() {
    for (const n of fs.readdirSync(this.p).sort()) {
      const full = path.join(this.p, n);
      if (n.includes('.swap-')) continue;
      yield [n, fs.statSync(full).isDirectory() ? new DirHandle(full, n, this.ctx) : new FileHandle(full, n, this.ctx)];
    }
  }
}
/** The OPFS root: `root/<rootName>` is the game directory. */
export function opfsRoot(dir, ctx = makeCtx()) { return new DirHandle(dir, '', ctx); }

/** Cooperative Web Locks model with query(); exclusive + ifAvailable only. */
export class Locks {
  held = new Map();
  async request(name, opts, fn) {
    if (opts?.mode !== 'exclusive' || opts?.ifAvailable !== true) throw new Error('mock supports exclusive ifAvailable only');
    if (this.held.has(name)) return fn(null);
    this.held.set(name, 'exclusive');
    try { return await fn({ name, mode: 'exclusive' }); } finally { this.held.delete(name); }
  }
  async query() { return { held: [...this.held].map(([name, mode]) => ({ name, mode, clientId: 'page' })), pending: [] }; }
}
/** A locks model whose lock is held for the caller's whole use (what the page does). */
export async function holding(locks, rootName, fn) {
  return locks.request(`${rootName}:save-backup`, { mode: 'exclusive', ifAvailable: true }, async (lock) => { if (!lock) throw new Error('busy'); return fn(); });
}

// ---------------------------------------------------------------- tree helpers
export const sha = (b) => crypto.createHash('sha256').update(b).digest('hex');
export function walk(dir, rel = '') {
  const out = new Map();
  if (!fs.existsSync(dir)) return out;
  for (const n of fs.readdirSync(dir).sort()) {
    const full = path.join(dir, n), r = rel ? `${rel}/${n}` : n;
    if (n.includes('.swap-')) continue;
    if (fs.statSync(full).isDirectory()) for (const [k, v] of walk(full, r)) out.set(k, v);
    else out.set(r, fs.readFileSync(full));
  }
  return out;
}
/** relative path -> sha256 for the whole tree */
export const snapshot = (dir) => new Map([...walk(dir)].map(([k, v]) => [k, sha(v)]));
export function sameSnapshot(a, b) {
  if (a.size !== b.size) return false;
  for (const [k, v] of a) if (b.get(k) !== v) return false;
  return true;
}
export function copyTree(from, to) { fs.cpSync(from, to, { recursive: true }); }
export function tmpRoot(prefix, base) {
  fs.mkdirSync(base, { recursive: true });
  return fs.mkdtempSync(path.join(base, prefix));
}

// ---------------------------------------------------------------- journal builders
import { crc32 } from '../web/save-export.mjs';
const enc = new TextEncoder();
export const hex = (s) => Buffer.from(s, 'utf8').toString('hex');
export function jline(event, tx, fields = {}, ts = 133000000000000000n) {
  const body = `v1 ${event} tx=${tx} ts=${ts}` + Object.entries(fields).map(([k, v]) => ` ${k}=${v}`).join('');
  return `${body} crc=${crc32(enc.encode(body)).toString(16).padStart(8, '0')}\n`;
}
export const txId = (n) => n.toString(16).padStart(20, '0');
export const priorName = (tx, n = 1) => `prior-${tx}-${n}`;
export const metaHex = (b) => Buffer.from(b).toString('hex');

// ---------------------------------------------------------------- case-sensitive in-memory OPFS (macOS/Windows temp
// directories are case-insensitive, real OPFS is not: names that differ only in case need this one)
class MemFile {
  constructor(node, name) { this.kind = 'file'; this.node = node; this.name = name; }
  async getFile() { const b = this.node.bytes; return { size: b.length, name: this.name, async arrayBuffer() { return b.slice().buffer; } }; }
  async createWritable() {
    const chunks = [], node = this.node;
    return { async write(d) { chunks.push(Buffer.from(d)); }, async close() { node.bytes = new Uint8Array(Buffer.concat(chunks)); }, async abort() {} };
  }
}
class MemDir {
  constructor(name = '') { this.kind = 'directory'; this.name = name; this.kids = new Map(); }
  async getDirectoryHandle(n, { create } = {}) {
    const k = this.kids.get(n);
    if (k && k.kind !== 'directory') throw domError('TypeMismatchError', n);
    if (k) return k;
    if (!create) throw domError('NotFoundError', n);
    const d = new MemDir(n); this.kids.set(n, d); return d;
  }
  async getFileHandle(n, { create } = {}) {
    const k = this.kids.get(n);
    if (k && k.kind !== 'file') throw domError('TypeMismatchError', n);
    if (k) return new MemFile(k, n);
    if (!create) throw domError('NotFoundError', n);
    const node = { kind: 'file', bytes: new Uint8Array(0) }; this.kids.set(n, node); return new MemFile(node, n);
  }
  async removeEntry(n) { if (!this.kids.delete(n)) throw domError('NotFoundError', n); }
  async *entries() { for (const [n, k] of [...this.kids].sort()) yield [n, k.kind === 'directory' ? k : new MemFile(k, n)]; }
  put(rel, bytes) {   // test helper: create dirs on the way
    const parts = rel.split('/'); let d = this;
    for (const p of parts.slice(0, -1)) { if (!d.kids.has(p)) d.kids.set(p, new MemDir(p)); d = d.kids.get(p); }
    d.kids.set(parts.at(-1), { kind: 'file', bytes: new Uint8Array(bytes) });
  }
  read(rel) {
    let d = this;
    for (const p of rel.split('/')) { d = d?.kids?.get(p); if (!d) return null; }
    return d.bytes ?? null;
  }
}
export const memRoot = () => new MemDir();
