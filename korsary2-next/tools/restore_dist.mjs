#!/usr/bin/env node
/** Restore development data from a packed distribution without overwriting edits. */
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import zlib from 'node:zlib';
import { Readable } from 'node:stream';
import { fileURLToPath } from 'node:url';

const CHUNK = 1024 * 1024;
const exists = (p) => { try { return fs.lstatSync(p); } catch (e) { if (e.code === 'ENOENT') return null; throw e; } };
function safeRelative(value) {
  if (typeof value !== 'string' || !value || value.startsWith('/') || /[\\\0:]/u.test(value) ||
      value.split('/').some((part) => ['', '.', '..'].includes(part))) {
    throw new Error(`unsafe path: ${JSON.stringify(value)}`);
  }
  return value;
}
function within(base, candidate) {
  const relative = path.relative(base, candidate);
  return relative === '' || (!relative.startsWith(`..${path.sep}`) && relative !== '..' && !path.isAbsolute(relative));
}
function sourcePath(root, value) {
  const name = safeRelative(value);
  const full = path.join(root, ...name.split('/'));
  let real;
  try { real = fs.realpathSync(full); }
  catch (e) { if (e.code === 'ENOENT') throw new Error(`missing source: ${JSON.stringify(value)}`); throw e; }
  if (!within(fs.realpathSync(root), real)) throw new Error(`source escapes distribution: ${JSON.stringify(value)}`);
  return full;
}
function nonnegative(value, label) {
  if (!Number.isSafeInteger(value) || value < 0) throw new Error(`invalid ${label}: ${JSON.stringify(value)}`);
  return value;
}
function casefold(value) {
  // Catch common Unicode case-fold collisions as well as ASCII/CP1251 names.
  return value.normalize('NFC').toLowerCase().replaceAll('ß', 'ss').replaceAll('ς', 'σ');
}
export function loadManifest(root, overlay = false) {
  const manifest = JSON.parse(fs.readFileSync(path.join(root, 'manifest.json'), 'utf8'));
  if (!manifest || Array.isArray(manifest) || typeof manifest !== 'object' || !Array.isArray(manifest.files)) throw new Error('invalid manifest files');
  const packs = manifest.packs ?? [];
  if (!Array.isArray(packs)) throw new Error('invalid manifest packs');
  const packPaths = packs.map((pack) => {
    if (!pack || Array.isArray(pack) || typeof pack !== 'object') throw new Error('invalid pack entry');
    return sourcePath(root, pack.path);
  });
  const seen = new Set();
  const entries = manifest.files.map((entry) => {
    if (!entry || Array.isArray(entry) || typeof entry !== 'object') throw new Error('invalid file entry');
    const name = safeRelative(entry.path), key = casefold(name);
    if (seen.has(key) || (overlay && key === 'overlay.json')) throw new Error(`duplicate or reserved path: ${JSON.stringify(name)}`);
    seen.add(key);
    const size = nonnegative(entry.size, 'size');
    if (typeof entry.sha256 !== 'string' || !/^[0-9a-f]{64}$/iu.test(entry.sha256)) throw new Error(`invalid SHA-256 for ${JSON.stringify(name)}`);
    const encoding = entry.enc ?? null;
    if (encoding !== null && encoding !== 'gzip') throw new Error(`unsupported encoding ${JSON.stringify(encoding)} for ${JSON.stringify(name)}`);
    let source, offset, length;
    if (Object.hasOwn(entry, 'pack')) {
      const index = nonnegative(entry.pack, 'pack index');
      if (index >= packPaths.length) throw new Error(`pack index out of range for ${JSON.stringify(name)}`);
      source = packPaths[index];
      offset = nonnegative(entry.offset, 'offset');
      length = nonnegative(entry.csize, 'compressed size');
    } else {
      source = sourcePath(root, name + (encoding === 'gzip' ? '.gz' : ''));
      offset = 0;
      length = encoding ? nonnegative(entry.csize, 'compressed size') : size;
    }
    const st = fs.statSync(source);
    if (!st.isFile() || !Number.isSafeInteger(offset + length) || offset + length > st.size) throw new Error(`missing or truncated source for ${JSON.stringify(name)}`);
    return { name, source, offset, length, encoding, size, sha: entry.sha256.toLowerCase() };
  });
  if (overlay && (!manifest.overlay || Array.isArray(manifest.overlay) || typeof manifest.overlay !== 'object')) throw new Error('English overlay metadata is missing');
  return { entries, metadata: manifest.overlay };
}
function destination(output, rel) {
  let current = output;
  if (exists(current)?.isSymbolicLink()) throw new Error(`output is a symlink: ${current}`);
  for (const part of rel.split('/')) {
    current = path.join(current, part);
    if (exists(current)?.isSymbolicLink()) throw new Error(`output path is a symlink: ${current}`);
  }
  return current;
}
function hashFile(file) {
  const digest = crypto.createHash('sha256');
  const fd = fs.openSync(file, 'r');
  try {
    const buffer = Buffer.allocUnsafe(CHUNK);
    for (;;) {
      const count = fs.readSync(fd, buffer, 0, buffer.length, null);
      if (!count) break;
      digest.update(buffer.subarray(0, count));
    }
    return digest.digest('hex');
  } finally { fs.closeSync(fd); }
}
function sameFile(file, size, sha) {
  const st = fs.statSync(file);
  return st.isFile() && st.size === size && hashFile(file) === sha;
}
function deepSort(v) {
  if (Array.isArray(v)) return v.map(deepSort);
  if (v && typeof v === 'object') return Object.fromEntries(Object.keys(v).sort().map((k) => [k, deepSort(v[k])]));
  return v;
}
function sameMetadata(file, metadata) {
  try { return JSON.stringify(deepSort(JSON.parse(fs.readFileSync(file, 'utf8')))) === JSON.stringify(deepSort(metadata)); }
  catch (e) { if (e instanceof SyntaxError || e.code === 'EISDIR') return false; throw e; }
}
async function writeEntry(entry, file) {
  const { source, offset, length, encoding, size, sha, name } = entry;
  const fd = fs.openSync(file, 'wx');
  let written = 0;
  const digest = crypto.createHash('sha256');
  const sourceStream = length ? fs.createReadStream(source, { start: offset, end: offset + length - 1, highWaterMark: CHUNK }) : Readable.from([]);
  const dataStream = encoding === 'gzip' ? sourceStream.pipe(zlib.createGunzip()) : sourceStream;
  if (dataStream !== sourceStream) sourceStream.on('error', (error) => dataStream.destroy(error));
  try {
    for await (const data of dataStream) {
      written += data.length;
      if (written > size) throw new Error(`${name}: decompressed size exceeds manifest`);
      digest.update(data);
      let at = 0;
      while (at < data.length) at += fs.writeSync(fd, data, at, data.length - at);
    }
    if (written !== size || digest.digest('hex') !== sha) throw new Error(`${name}: size or SHA-256 mismatch`);
  } finally {
    sourceStream.destroy();
    dataStream.destroy();
    fs.closeSync(fd);
  }
}
export async function restore(root, output, overlay = false) {
  const { entries, metadata } = loadManifest(root, overlay);
  const out = exists(output);
  if (out && (out.isSymbolicLink() || !out.isDirectory())) throw new Error(`output is not a real directory: ${output}`);
  // Check every existing destination before writing any files.
  for (const entry of entries) {
    const dest = destination(output, entry.name);
    if (exists(dest) && !sameFile(dest, entry.size, entry.sha)) throw new Error(`existing file differs; refusing to overwrite: ${dest}`);
  }
  if (overlay) {
    const dest = destination(output, 'OVERLAY.json');
    if (exists(dest) && !sameMetadata(dest, metadata)) throw new Error(`existing overlay metadata differs; refusing to overwrite: ${dest}`);
  }
  if (!out) fs.mkdirSync(output, { recursive: false });
  let skipped = 0;
  for (const entry of entries) {
    const dest = destination(output, entry.name);
    if (exists(dest)) {
      if (!sameFile(dest, entry.size, entry.sha)) throw new Error(`existing file differs; refusing to overwrite: ${dest}`);
      skipped++;
      continue;
    }
    fs.mkdirSync(path.dirname(dest), { recursive: true });
    // Recheck after mkdir; exclusive creation never replaces an existing file.
    await writeEntry(entry, destination(output, entry.name));
  }
  if (overlay && !exists(path.join(output, 'OVERLAY.json'))) {
    fs.writeFileSync(destination(output, 'OVERLAY.json'), `${JSON.stringify(deepSort(metadata), null, 2)}\n`, { flag: 'wx' });
  }
  console.log(`Restored ${entries.length - skipped} files to ${output}; kept ${skipped} identical files`);
  return { restored: entries.length - skipped, skipped };
}
export async function main(argv = process.argv.slice(2)) {
  const args = {};
  for (let i = 0; i < argv.length; i++) {
    const key = argv[i];
    if (key === '--help' || key === '-h') {
      console.log('Usage: node restore_dist.mjs --dist DIR [--game-out DIR] [--overlay-out DIR]\nExisting different files and symlinks are rejected; identical files are kept.');
      return;
    }
    if (!['--dist', '--game-out', '--overlay-out'].includes(key) || i + 1 >= argv.length) throw new Error(`unknown or incomplete argument: ${key}`);
    args[key] = argv[++i];
  }
  if (!args['--dist']) throw new Error('--dist is required');
  const outputs = [args['--game-out'], args['--overlay-out']].filter(Boolean);
  if (!outputs.length) throw new Error('specify --game-out and/or --overlay-out');
  if (outputs.length === 2 && path.resolve(outputs[0]) === path.resolve(outputs[1])) throw new Error('output directories must be different');
  for (const output of outputs) if (!fs.statSync(path.dirname(path.resolve(output))).isDirectory()) throw new Error(`output parent does not exist: ${path.dirname(output)}`);
  if (args['--game-out']) await restore(path.join(args['--dist'], 'game'), args['--game-out']);
  if (args['--overlay-out']) await restore(path.join(args['--dist'], 'game-en'), args['--overlay-out'], true);
}
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  main().catch((e) => { console.error(`restore failed: ${e.message}`); process.exitCode = 1; });
}
