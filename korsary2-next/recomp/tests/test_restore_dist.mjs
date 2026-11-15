#!/usr/bin/env node
import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import zlib from 'node:zlib';
import crypto from 'node:crypto';
import { restore } from '../../tools/restore_dist.mjs';

const digest = (data) => crypto.createHash('sha256').update(data).digest('hex');
const entry = (name, data, extra = {}) => ({ path: name, size: data.length, sha256: digest(data), ...extra });
function fixture(t) {
  const temp = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-restore-'));
  t.after(() => fs.rmSync(temp, { recursive: true, force: true }));
  const root = path.join(temp, 'game'), out = path.join(temp, 'out');
  fs.mkdirSync(root);
  const data = Buffer.from('packed original game data');
  const packed = zlib.gzipSync(data);
  fs.writeFileSync(path.join(root, 'data.pack'), Buffer.concat([Buffer.from('prefix'), packed, Buffer.from('suffix')]));
  fs.writeFileSync(path.join(root, 'loose'), 'raw');
  const manifest = { files: [entry('PROGRAM/first.c', data, { enc: 'gzip', csize: packed.length, pack: 0, offset: 6 }), entry('loose', Buffer.from('raw'))], packs: [{ path: 'data.pack' }] };
  const save = () => fs.writeFileSync(path.join(root, 'manifest.json'), JSON.stringify(manifest));
  save();
  return { temp, root, out, data, manifest, save };
}

test('restores packed and loose files, preserves user data and is idempotent', async (t) => {
  const { root, out, data } = fixture(t);
  fs.mkdirSync(out); fs.writeFileSync(path.join(out, 'loose'), 'raw'); fs.writeFileSync(path.join(out, 'user-save'), 'keep');
  assert.deepEqual(await restore(root, out), { restored: 1, skipped: 1 });
  assert.deepEqual(fs.readFileSync(path.join(out, 'PROGRAM', 'first.c')), data);
  assert.equal(fs.readFileSync(path.join(out, 'user-save'), 'utf8'), 'keep');
  assert.deepEqual(await restore(root, out), { restored: 0, skipped: 2 });
});
test('checks conflicts before writing anything', async (t) => {
  const { root, out } = fixture(t);
  fs.mkdirSync(out); fs.writeFileSync(path.join(out, 'loose'), 'changed');
  await assert.rejects(restore(root, out), /refusing to overwrite/);
  assert.equal(fs.readFileSync(path.join(out, 'loose'), 'utf8'), 'changed');
  assert.equal(fs.existsSync(path.join(out, 'PROGRAM')), false);
});
test('rejects destination and source traversal', async (t) => {
  const { root, out, manifest, save } = fixture(t);
  for (const bad of ['../outside', '/outside', 'PROGRAM//a', 'PROGRAM\\a', 'C:/outside', 'a/./b']) {
    manifest.files[0].path = bad; save();
    await assert.rejects(restore(root, out), /unsafe path/);
  }
  manifest.files[0].path = 'first'; manifest.packs[0].path = '../outside'; save();
  await assert.rejects(restore(root, out), /unsafe path/);
  assert.equal(fs.existsSync(out), false);
});
test('rejects destination and source symlinks that escape', async (t) => {
  const { temp, root, out, manifest, save } = fixture(t);
  fs.mkdirSync(out); fs.symlinkSync(temp, path.join(out, 'PROGRAM'));
  await assert.rejects(restore(root, out), /symlink/);
  fs.unlinkSync(path.join(out, 'PROGRAM'));
  fs.symlinkSync(path.join(temp, 'outside'), path.join(root, 'escape'));
  fs.writeFileSync(path.join(temp, 'outside'), 'x');
  manifest.packs[0].path = 'escape'; save();
  await assert.rejects(restore(root, out), /escapes distribution/);
});
test('rejects bad hash, truncated source and case-insensitive duplicates', async (t) => {
  const { root, out, manifest, save } = fixture(t);
  manifest.files[0].sha256 = '0'.repeat(64); save();
  await assert.rejects(restore(root, out), /SHA-256 mismatch/);
  fs.rmSync(out, { recursive: true });
  manifest.files[0].csize = 100000; save();
  await assert.rejects(restore(root, out), /truncated source/);
  manifest.files[0].csize = 2; manifest.files.push({ ...manifest.files[0], path: 'program/FIRST.c' }); save();
  await assert.rejects(restore(root, out), /duplicate/);
});
test('validates overlay metadata and rejects reserved names', async (t) => {
  const { root, out, manifest, save } = fixture(t);
  manifest.overlay = { format: 1, language: 'en', base: {} }; save();
  await restore(root, out, true);
  assert.deepEqual(JSON.parse(fs.readFileSync(path.join(out, 'OVERLAY.json'), 'utf8')), manifest.overlay);
  await restore(root, out, true);
  fs.writeFileSync(path.join(out, 'OVERLAY.json'), '{}');
  await assert.rejects(restore(root, out, true), /refusing to overwrite/);
  manifest.files.push({ ...manifest.files[1], path: 'overlay.JSON' }); save();
  await assert.rejects(restore(root, out, true), /reserved/);
});
test('rejects gzip expansion larger than advertised', async (t) => {
  const { root, out, manifest, save } = fixture(t);
  manifest.files[0].size = 1; save();
  await assert.rejects(restore(root, out), /decompressed size exceeds manifest/);
});
