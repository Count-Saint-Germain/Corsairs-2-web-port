#!/usr/bin/env node
import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import crypto from 'node:crypto';
import zlib from 'node:zlib';
import { stageArchive, extractZip, URL } from '../../tools/stage_emdawn.mjs';

function crc32(buf) {
  let crc = 0xffffffff;
  for (const byte of buf) { crc ^= byte; for (let i = 0; i < 8; i++) crc = (crc >>> 1) ^ (0xedb88320 & -(crc & 1)); }
  return (crc ^ 0xffffffff) >>> 0;
}
function zip(entries) {
  const local = [], central = []; let offset = 0;
  for (const entry of entries) {
    const name = Buffer.from(entry.name), data = Buffer.from(entry.data ?? ''), compressed = entry.method === 8 ? zlib.deflateRawSync(data) : data;
    const crc = crc32(data), l = Buffer.alloc(30), c = Buffer.alloc(46);
    l.writeUInt32LE(0x04034b50); l.writeUInt16LE(20, 4); l.writeUInt16LE(entry.method ?? 0, 8); l.writeUInt32LE(crc, 14); l.writeUInt32LE(compressed.length, 18); l.writeUInt32LE(data.length, 22); l.writeUInt16LE(name.length, 26);
    c.writeUInt32LE(0x02014b50); c.writeUInt16LE(0x0314, 4); c.writeUInt16LE(20, 6); c.writeUInt16LE(entry.method ?? 0, 10); c.writeUInt32LE(crc, 16); c.writeUInt32LE(compressed.length, 20); c.writeUInt32LE(data.length, 24); c.writeUInt16LE(name.length, 28); c.writeUInt32LE(((entry.mode ?? 0o100644) << 16) >>> 0, 38); c.writeUInt32LE(offset, 42);
    local.push(l, name, compressed); central.push(c, name); offset += l.length + name.length + compressed.length;
  }
  const table = Buffer.concat(central), end = Buffer.alloc(22);
  end.writeUInt32LE(0x06054b50); end.writeUInt16LE(entries.length, 8); end.writeUInt16LE(entries.length, 10); end.writeUInt32LE(table.length, 12); end.writeUInt32LE(offset, 16);
  return Buffer.concat([...local, table, end]);
}
function fixture(t, entries = [{ name: 'emdawnwebgpu_pkg/emdawnwebgpu.port.py', data: 'port contents', method: 8 }]) {
  const temp = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-dawn-')); t.after(() => fs.rmSync(temp, { recursive: true, force: true }));
  const archive = path.join(temp, 'dawn.zip'), bytes = zip(entries), ports = path.join(temp, 'ports');
  fs.writeFileSync(archive, bytes);
  const expectedHash = crypto.createHash('sha512').update(bytes).digest('hex');
  return { temp, archive, bytes, ports, expectedHash };
}
test('installs a verified compressed package and exact Emscripten URL', (t) => {
  const x = fixture(t), target = stageArchive(x.archive, x);
  assert.equal(fs.readFileSync(path.join(target, 'emdawnwebgpu_pkg/emdawnwebgpu.port.py'), 'utf8'), 'port contents');
  assert.equal(fs.readFileSync(path.join(target, '.emscripten_url'), 'utf8'), `${URL}\n`);
});
test('rejects a checksum mismatch without creating the target', (t) => {
  const x = fixture(t);
  assert.throws(() => stageArchive(x.archive, { ports: x.ports, expectedHash: '0'.repeat(128) }), /SHA-512 mismatch/);
  assert.equal(fs.existsSync(x.ports), false);
});
test('rejects traversal and absolute and Windows paths', (t) => {
  const x = fixture(t);
  for (const name of ['../escape', '/absolute', 'a/../../escape', 'C:/escape', 'a\\b']) {
    assert.throws(() => extractZip(zip([{ name, data: 'bad' }]), x.temp), /unsafe archive member/);
  }
  assert.equal(fs.existsSync(path.join(x.temp, 'escape')), false);
});
test('rejects symlink entries and symlink target', (t) => {
  const x = fixture(t);
  assert.throws(() => extractZip(zip([{ name: 'outside', data: 'target', mode: 0o120777 }]), x.temp), /unsafe archive member/);
  fs.mkdirSync(x.ports); fs.symlinkSync(x.temp, path.join(x.ports, 'emdawnwebgpu'));
  assert.throws(() => stageArchive(x.archive, x), /refusing to replace symlink/);
  assert.equal(fs.lstatSync(path.join(x.ports, 'emdawnwebgpu')).isSymbolicLink(), true);
});
test('rejects corrupted CRC, duplicate entries and truncated archive', (t) => {
  const x = fixture(t), bytes = Buffer.from(x.bytes);
  bytes[30 + Buffer.byteLength('emdawnwebgpu_pkg/emdawnwebgpu.port.py')] ^= 0x01;
  assert.throws(() => extractZip(bytes, x.temp));
  assert.throws(() => extractZip(zip([{ name: 'A', data: '1' }, { name: 'a', data: '2' }]), x.temp), /duplicate/);
  assert.throws(() => extractZip(bytes.subarray(0, bytes.length - 5), x.temp), /ZIP/);
});
test('replaces only the previous staged package after successful validation', (t) => {
  const x = fixture(t); fs.mkdirSync(path.join(x.ports, 'emdawnwebgpu'), { recursive: true });
  fs.writeFileSync(path.join(x.ports, 'emdawnwebgpu', 'old'), 'old');
  const target = stageArchive(x.archive, x);
  assert.equal(fs.existsSync(path.join(target, 'old')), false);
  assert.equal(fs.existsSync(path.join(target, 'emdawnwebgpu_pkg/emdawnwebgpu.port.py')), true);
});
