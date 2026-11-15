#!/usr/bin/env node
/** Verify and install the pinned Emscripten Dawn package from a local ZIP. */
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import zlib from 'node:zlib';
import { fileURLToPath } from 'node:url';

const ROOT = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
export const PORTS = path.join(ROOT, 'recomp', 'web_toolchain', 'ports');
export const VERSION = 'v20260423.175430';
export const URL = `https://github.com/google/dawn/releases/download/${VERSION}/emdawnwebgpu_pkg-${VERSION}.zip`;
export const SHA512 = '42784f70b67197c614322f9fabb0f1dc64228a0de10e88f99941fa9d29bee9ad6683f4651d4eefd5a7a9fbd1f976eb522b190b683219ed1793e9b531c602ffa6';

function inBounds(buffer, offset, length) {
  return Number.isSafeInteger(offset) && Number.isSafeInteger(length) && offset >= 0 && length >= 0 && offset + length <= buffer.length;
}
function checked(buffer, offset, length) {
  if (!inBounds(buffer, offset, length)) throw new Error('truncated ZIP archive');
}
function nameParts(name) {
  const trimmed = name.endsWith('/') ? name.slice(0, -1) : name;
  if (!trimmed || name.startsWith('/') || /[\\\0:]/u.test(name) || trimmed.split('/').some((x) => !x || x === '.' || x === '..')) {
    throw new Error(`unsafe archive member: ${JSON.stringify(name)}`);
  }
  return trimmed.split('/');
}
function crc32(buf) {
  let crc = 0xffffffff;
  for (const byte of buf) {
    crc ^= byte;
    for (let i = 0; i < 8; i++) crc = (crc >>> 1) ^ (0xedb88320 & -(crc & 1));
  }
  return (crc ^ 0xffffffff) >>> 0;
}
/** Parse the central directory and reject unsupported or unsafe members. */
export function readZipEntries(buffer) {
  let eocd = -1;
  for (let i = buffer.length - 22, lower = Math.max(0, buffer.length - 65557); i >= lower; i--) {
    if (buffer.readUInt32LE(i) === 0x06054b50 && inBounds(buffer, i, 22) && i + 22 + buffer.readUInt16LE(i + 20) === buffer.length) { eocd = i; break; }
  }
  if (eocd < 0) throw new Error('missing ZIP end-of-central-directory');
  const disk = buffer.readUInt16LE(eocd + 4), centralDisk = buffer.readUInt16LE(eocd + 6);
  const onDisk = buffer.readUInt16LE(eocd + 8), count = buffer.readUInt16LE(eocd + 10);
  const centralSize = buffer.readUInt32LE(eocd + 12), centralOffset = buffer.readUInt32LE(eocd + 16);
  if (disk || centralDisk || onDisk !== count || count === 0xffff || centralSize === 0xffffffff || centralOffset === 0xffffffff) throw new Error('multi-disk or ZIP64 archive not supported');
  if (!inBounds(buffer, centralOffset, centralSize) || centralOffset + centralSize !== eocd) throw new Error('invalid ZIP central directory');
  const entries = [], seen = new Set();
  let cursor = centralOffset;
  const decode = new TextDecoder('utf-8', { fatal: true });
  for (let n = 0; n < count; n++) {
    checked(buffer, cursor, 46);
    if (buffer.readUInt32LE(cursor) !== 0x02014b50) throw new Error('invalid ZIP central header');
    const flags = buffer.readUInt16LE(cursor + 8), method = buffer.readUInt16LE(cursor + 10);
    const crc = buffer.readUInt32LE(cursor + 16), compressed = buffer.readUInt32LE(cursor + 20), size = buffer.readUInt32LE(cursor + 24);
    const nameLen = buffer.readUInt16LE(cursor + 28), extraLen = buffer.readUInt16LE(cursor + 30), commentLen = buffer.readUInt16LE(cursor + 32);
    const diskStart = buffer.readUInt16LE(cursor + 34), ext = buffer.readUInt32LE(cursor + 38), localOffset = buffer.readUInt32LE(cursor + 42);
    checked(buffer, cursor + 46, nameLen + extraLen + commentLen);
    if (flags & 1 || ![0, 8].includes(method) || diskStart || [compressed, size, localOffset].includes(0xffffffff)) throw new Error('encrypted, ZIP64 or unsupported ZIP member');
    const name = decode.decode(buffer.subarray(cursor + 46, cursor + 46 + nameLen));
    const parts = nameParts(name), directory = name.endsWith('/'), type = (ext >>> 16) & 0o170000;
    if (type === 0o120000 || (type && type !== 0o100000 && type !== 0o040000)) throw new Error(`unsafe archive member: ${name}`);
    if ((type === 0o040000 && !directory) || (type === 0o100000 && directory)) throw new Error(`invalid archive member type: ${name}`);
    const key = parts.join('/').normalize('NFC').toLowerCase();
    if (seen.has(key)) throw new Error(`duplicate archive member: ${name}`);
    seen.add(key);
    checked(buffer, localOffset, 30);
    if (buffer.readUInt32LE(localOffset) !== 0x04034b50) throw new Error(`invalid local ZIP header: ${name}`);
    const localNameLen = buffer.readUInt16LE(localOffset + 26), localExtraLen = buffer.readUInt16LE(localOffset + 28);
    checked(buffer, localOffset + 30, localNameLen + localExtraLen + compressed);
    const localName = decode.decode(buffer.subarray(localOffset + 30, localOffset + 30 + localNameLen));
    if (localName !== name || buffer.readUInt16LE(localOffset + 8) !== method || buffer.readUInt16LE(localOffset + 6) !== flags) throw new Error(`inconsistent ZIP headers: ${name}`);
    if (size > 128 * 1024 * 1024) throw new Error(`archive member too large: ${name}`);
    const offset = localOffset + 30 + localNameLen + localExtraLen;
    if (offset + compressed > centralOffset) throw new Error(`archive member overlaps directory: ${name}`);
    entries.push({ name, parts, directory, method, crc, compressed, size, offset });
    cursor += 46 + nameLen + extraLen + commentLen;
  }
  if (cursor !== centralOffset + centralSize) throw new Error('ZIP central directory size mismatch');
  return entries;
}
export function extractZip(buffer, directory) {
  const entries = readZipEntries(buffer);
  for (const entry of entries) {
    const output = path.join(directory, ...entry.parts);
    if (entry.directory) { fs.mkdirSync(output, { recursive: true }); continue; }
    const packed = buffer.subarray(entry.offset, entry.offset + entry.compressed);
    const content = entry.method === 0 ? packed : zlib.inflateRawSync(packed, { maxOutputLength: Math.max(entry.size, 1) });
    if (content.length !== entry.size || crc32(content) !== entry.crc) throw new Error(`invalid size or CRC: ${entry.name}`);
    fs.mkdirSync(path.dirname(output), { recursive: true });
    fs.writeFileSync(output, content, { flag: 'wx' });
  }
}
/** expectedHash/ports options permit isolated fixture tests; CLI always uses pinned values. */
export function stageArchive(archive, { ports = PORTS, expectedHash = SHA512 } = {}) {
  const bytes = fs.readFileSync(archive);
  const digest = crypto.createHash('sha512').update(bytes).digest('hex');
  if (digest !== expectedHash) throw new Error(`SHA-512 mismatch: ${digest}`);
  fs.mkdirSync(ports, { recursive: true });
  const dir = fs.mkdtempSync(path.join(ports, 'dawn-stage-'));
  try {
    extractZip(bytes, dir);
    if (!fs.statSync(path.join(dir, 'emdawnwebgpu_pkg', 'emdawnwebgpu.port.py')).isFile()) throw new Error('archive does not contain emdawnwebgpu.port.py');
    fs.writeFileSync(path.join(dir, '.emscripten_url'), `${URL}\n`);
    const target = path.join(ports, 'emdawnwebgpu');
    let stat;
    try { stat = fs.lstatSync(target); } catch (e) { if (e.code !== 'ENOENT') throw e; }
    if (stat?.isSymbolicLink()) throw new Error(`refusing to replace symlink: ${target}`);
    if (stat) fs.rmSync(target, { recursive: true });
    fs.renameSync(dir, target);
    console.log(`verified and staged ${target}`);
    return target;
  } finally { fs.rmSync(dir, { recursive: true, force: true }); }
}
export function main(argv = process.argv.slice(2)) {
  if (argv.length !== 1 || argv[0] === '--help' || argv[0] === '-h') {
    console.log('usage: node stage_emdawn.mjs /path/to/emdawnwebgpu.zip');
    if (argv.length !== 1 || !['--help', '-h'].includes(argv[0])) process.exitCode = 1;
    return;
  }
  stageArchive(argv[0]);
}
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  try { main(); } catch (e) { console.error(e.message); process.exitCode = 1; }
}
