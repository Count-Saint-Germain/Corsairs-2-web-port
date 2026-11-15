/** Binary-safe game-data preparation primitives shared by the Node migration. */
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import crypto from 'node:crypto';

const HASH_BLOCK = 1024 * 1024;
export const PROTECTED_TOP = ['engine.dll', 'data1.dat'];
export const RUNTIME_EXTRAS_TOP = ['system.log', 'compile.log'];
export const EOLS = { crlf: '\r\n', lf: '\n' };
const hash = (value) => crypto.createHash('sha256').update(value).digest('hex');
export function sha256File(file) {
  const h = crypto.createHash('sha256'), fd = fs.openSync(file, 'r'), block = Buffer.allocUnsafe(HASH_BLOCK);
  try { for (;;) { const n = fs.readSync(fd, block, 0, block.length, null); if (!n) break; h.update(block.subarray(0, n)); } }
  finally { fs.closeSync(fd); }
  return h.digest('hex');
}
export function ciResolve(root, relative) {
  let current = root;
  for (const part of relative.split('/')) {
    if (!part || part === '.') continue;
    let names;
    try { names = fs.readdirSync(current); }
    catch (e) { if (['ENOENT', 'ENOTDIR', 'EACCES'].includes(e.code)) return null; throw e; }
    const hit = names.includes(part) ? part : names.sort().find((name) => name.toLowerCase() === part.toLowerCase());
    if (hit === undefined) return null;
    current = path.join(current, hit);
  }
  return current;
}
export function listFiles(root) {
  const out = {};
  function walk(dir) {
    for (const item of fs.readdirSync(dir, { withFileTypes: true }).sort((a, b) => a.name.localeCompare(b.name, 'en'))) {
      const full = path.join(dir, item.name);
      if (item.isDirectory()) walk(full);
      else if (item.isSymbolicLink()) {
        // os.walk(followlinks=False) skips directory links but lists file links.
        let isDirectory = false;
        try { isDirectory = fs.statSync(full).isDirectory(); } catch (error) { if (error.code !== 'ENOENT') throw error; }
        if (!isDirectory && item.name.toLowerCase() !== '.ds_store') out[path.relative(root, full).split(path.sep).join('/')] = fs.lstatSync(full).size;
      } else if (item.name.toLowerCase() !== '.ds_store') out[path.relative(root, full).split(path.sep).join('/')] = fs.lstatSync(full).size;
    }
  }
  walk(root);
  return out;
}
export function isProtected(rel) { return !rel.includes('/') && PROTECTED_TOP.includes(rel.toLowerCase()); }
export function listingFingerprint(listing) {
  return hash(Object.keys(listing).sort().map((name) => `${name}\t${listing[name]}\n`).join(''));
}
export function assertNoSymlink(root, target) {
  const base = path.resolve(root), full = path.resolve(target), rel = path.relative(base, full);
  if (rel === '..' || rel.startsWith(`..${path.sep}`) || path.isAbsolute(rel)) throw new Error(`path escapes working directory: ${target}`);
  let current = base;
  for (const component of rel.split(path.sep).filter(Boolean)) {
    current = path.join(current, component);
    let stat;
    try { stat = fs.lstatSync(current); } catch (error) { if (error.code === 'ENOENT') continue; throw error; }
    if (stat.isSymbolicLink()) throw new Error(`working path traverses symlink: ${current}`);
  }
}
export function safeRel(rel) {
  if (typeof rel !== 'string' || !rel || rel.startsWith('/') || (/[\\\0:]/u.test(rel)) || rel.split('/').some((p) => ['', '.', '..'].includes(p))) throw new Error(`unsafe relative path: ${JSON.stringify(rel)}`);
  return rel;
}
export function parsePatch(data) {
  const lines = Buffer.from(data).toString('latin1').split('\n');
  if (lines.at(-1) === '') lines.pop();
  const meta = {}; let i = 0;
  while (i < lines.length && lines[i].startsWith('# ')) {
    const m = /^# ([^:]+): (.*)$/u.exec(lines[i++]);
    if (!m) throw new Error('invalid patch metadata');
    meta[m[1]] = Buffer.from(m[2], 'latin1').toString('utf8');
  }
  for (const key of ['path', 'sha256-before', 'sha256-after', 'eol-before', 'eol-after', 'final-newline']) {
    if (!(key in meta)) throw new Error(`patch missing ${key}`);
  }
  if (!(meta['eol-before'] in EOLS) || !(meta['eol-after'] in EOLS) || !['yes', 'no'].includes(meta['final-newline'])) throw new Error(`patch ${meta.path}: invalid EOL metadata`);
  if (!lines[i]?.startsWith('--- ') || !lines[i + 1]?.startsWith('+++ ')) throw new Error(`patch ${meta.path}: missing --- / +++ headers`);
  i += 2;
  const hunks = [];
  while (i < lines.length) {
    const m = /^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@/u.exec(lines[i]);
    if (!m) throw new Error(`patch ${meta.path}: expected hunk at line ${i + 1}`);
    const oldStart = Number(m[1]), oldLength = m[2] === undefined ? 1 : Number(m[2]), newLength = m[4] === undefined ? 1 : Number(m[4]);
    const before = [], after = []; i++;
    while (i < lines.length && (before.length < oldLength || after.length < newLength)) {
      const tag = lines[i][0], value = lines[i].slice(1);
      if (tag === ' ') { before.push(value); after.push(value); }
      else if (tag === '-') before.push(value);
      else if (tag === '+') after.push(value);
      else throw new Error(`patch ${meta.path}: invalid hunk line ${i + 1}`);
      i++;
    }
    if (before.length !== oldLength || after.length !== newLength) throw new Error(`patch ${meta.path}: hunk counts do not match`);
    hunks.push({ oldStart, before, after });
  }
  return { meta, hunks };
}
export function applyPatchBytes(meta, hunks, input) {
  const data = Buffer.from(input).toString('latin1'), eb = EOLS[meta['eol-before']], ea = EOLS[meta['eol-after']], final = meta['final-newline'] === 'yes';
  if (final !== data.endsWith(eb)) throw new Error(`${meta.path}: final newline does not match patch`);
  const lines = (final ? data.slice(0, -eb.length) : data).split(eb);
  if (lines.some((line) => line.includes('\n') || line.includes('\r'))) throw new Error(`${meta.path}: mixed line endings`);
  const output = []; let pos = 0;
  for (const hunk of hunks) {
    const start = hunk.before.length ? hunk.oldStart - 1 : hunk.oldStart;
    if (start < pos || start < 0 || start > lines.length || hunk.before.some((line, i) => lines[start + i] !== line)) throw new Error(`${meta.path}: hunk -${hunk.oldStart} does not match; no changes made`);
    output.push(...lines.slice(pos, start), ...hunk.after); pos = start + hunk.before.length;
  }
  output.push(...lines.slice(pos));
  return Buffer.from(output.join(ea) + (final ? ea : ''), 'latin1');
}
export function loadPatches(dir) {
  return fs.readdirSync(dir).filter((name) => name.endsWith('.patch')).sort().map((name) => ({ name, ...parsePatch(fs.readFileSync(path.join(dir, name))) }));
}
function tempFile(dir) {
  for (let i = 0; i < 100; i++) {
    const name = path.join(dir, `.prepare-${process.pid}-${crypto.randomBytes(8).toString('hex')}`);
    try { return [name, fs.openSync(name, 'wx', 0o600)]; } catch (e) { if (e.code !== 'EEXIST') throw e; }
  }
  throw new Error('unable to create temporary file');
}
export function replaceFile(dest, data) {
  const [temp, fd] = tempFile(path.dirname(dest));
  try {
    fs.writeFileSync(fd, data); fs.closeSync(fd);
    try { fs.chmodSync(temp, fs.statSync(dest).mode & 0o777); } catch { /* best effort */ }
    fs.renameSync(temp, dest);
  } catch (e) { try { fs.closeSync(fd); } catch {} try { fs.unlinkSync(temp); } catch {} throw e; }
}
export function installNew(dest, { data, source } = {}) {
  fs.mkdirSync(path.dirname(dest), { recursive: true });
  const [temp, fd] = tempFile(path.dirname(dest));
  try {
    if (data !== undefined) fs.writeFileSync(fd, data); else fs.writeFileSync(fd, fs.readFileSync(source));
    fs.closeSync(fd); fs.chmodSync(temp, 0o644);
    try { fs.linkSync(temp, dest); return true; }
    catch (e) { if (e.code === 'EEXIST') return false; throw e; }
  } finally { try { fs.closeSync(fd); } catch {} try { fs.unlinkSync(temp); } catch {} }
}
export function stepPatches(out, patchDir, dry = false) {
  const result = { applied: [], already: [] };
  for (const { name, meta, hunks } of loadPatches(patchDir)) {
    const rel = safeRel(meta.path), file = ciResolve(out, rel);
    if (!file) throw new Error(`patch ${name}: missing ${rel}`);
    let part = out;
    for (const component of path.relative(out, file).split(path.sep)) {
      part = path.join(part, component);
      if (fs.lstatSync(part).isSymbolicLink()) throw new Error(`patch ${name}: ${rel} traverses a symlink`);
    }
    const data = fs.readFileSync(file), before = hash(data);
    if (before === meta['sha256-after']) { result.already.push(rel); continue; }
    if (before !== meta['sha256-before']) throw new Error(`patch ${name}: SHA-256 does not match before or after`);
    const changed = applyPatchBytes(meta, hunks, data);
    if (hash(changed) !== meta['sha256-after']) throw new Error(`patch ${name}: SHA-256 after patch does not match`);
    if (!dry) replaceFile(file, changed);
    result.applied.push(rel);
  }
  return result;
}
export function verify(out, repack, manifest, { skipWav = false, deep = false, patchDir = null } = {}) {
  const errors = [], warnings = [], listing = listFiles(repack), original = {};
  if (listingFingerprint(listing) !== manifest.source.repack_listing_sha256) warnings.push('repack listing differs from reference');
  for (const [name, size] of Object.entries(listing)) if (!isProtected(name)) original[name] = size;
  const added = Object.fromEntries(manifest.added.map((e) => [e.path, e])), modified = Object.fromEntries(manifest.modified.map((e) => [e.path, e]));
  const expected = { ...original };
  for (const e of manifest.added) { if (Object.hasOwn(expected, e.path)) errors.push(`reference: ${e.path} exists in repack and added`); expected[e.path] = e.size; }
  for (const e of manifest.modified) { if (!Object.hasOwn(original, e.path)) errors.push(`reference: modified ${e.path} missing from repack`); expected[e.path] = e.size_after; }
  const actual = listFiles(out), skipped = [];
  for (const name of Object.keys(expected).sort()) {
    if (!Object.hasOwn(actual, name)) {
      if (skipWav && added[name]?.kind === 'wav') skipped.push(name); else errors.push(`missing: ${name}`);
    } else if (actual[name] !== expected[name]) errors.push(`size ${name}: ${actual[name]}, expected ${expected[name]}`);
  }
  for (const name of Object.keys(actual).sort()) if (!Object.hasOwn(expected, name)) {
    if (name.split('/')[0].toUpperCase() === 'SAVE' || RUNTIME_EXTRAS_TOP.includes(name.toLowerCase())) warnings.push(`runtime/player extra: ${name}`);
    else errors.push(`unexpected file: ${name}`);
  }
  for (const [name, entry] of Object.entries({ ...added, ...modified }).sort(([a], [b]) => a.localeCompare(b, 'en'))) {
    if (Object.hasOwn(actual, name) && sha256File(path.join(out, name)) !== (entry.sha256 || entry.sha256_after)) errors.push(`SHA-256 mismatch: ${name}`);
  }
  if (deep) for (const name of Object.keys(original).sort()) {
    if (!Object.hasOwn(actual, name) || Object.hasOwn(modified, name) || expected[name] !== actual[name]) continue;
    if (sha256File(path.join(out, name)) !== sha256File(path.join(repack, name))) errors.push(`content differs from repack: ${name}`);
  }
  if (patchDir) for (const { name, meta } of loadPatches(patchDir)) {
    const entry = modified[meta.path];
    if (!entry || entry.sha256_before !== meta['sha256-before'] || entry.sha256_after !== meta['sha256-after']) errors.push(`patch ${name} does not match reference`);
  }
  const c = manifest.counts, total = c.repack_files - c.protected_files_excluded + c.added_total;
  if (Object.keys(expected).length !== total) errors.push(`reference counts do not match (${Object.keys(expected).length} != ${total})`);
  if (skipped.length) warnings.push(`--skip-wav: ${skipped.length} .wav not created; game will be silent`);
  return { errors, warnings };
}
