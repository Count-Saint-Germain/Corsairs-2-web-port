import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { applyFixes, ciExists, FIXES } from '../../tools/apply_content_fixes.mjs';

function setup(t) {
  const dir = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-fixes-'));
  t.after(() => fs.rmSync(dir, { recursive: true, force: true }));
  for (const fix of FIXES) { const src = path.join(dir, fix.src); fs.mkdirSync(path.dirname(src), { recursive: true }); fs.writeFileSync(src, `content:${fix.name}`); }
  return dir;
}
test('copies only missing files and repeat run preserves changes', (t) => {
  const root = setup(t); assert.equal(applyFixes(root), 0);
  for (const fix of FIXES) assert.deepEqual(fs.readFileSync(path.join(root, fix.dst)), fs.readFileSync(path.join(root, fix.src)));
  const dst = path.join(root, FIXES[0].dst); fs.writeFileSync(dst, 'user content');
  assert.equal(applyFixes(root), 0); assert.equal(fs.readFileSync(dst, 'utf8'), 'user content');
});
test('dry-run and absent source do not write', (t) => {
  const root = setup(t); assert.equal(applyFixes(root, { dryRun: true }), 0);
  assert.equal(fs.existsSync(path.join(root, FIXES[0].dst)), false);
  fs.unlinkSync(path.join(root, FIXES[0].src)); assert.equal(applyFixes(root, { dryRun: true }), 1);
  assert.equal(fs.existsSync(path.join(root, FIXES[0].dst)), false);
});
test('case-insensitive search works without overwriting case variants', (t) => {
  const root = setup(t), variant = path.join(root, 'RESOURCE/MODELS/Heads/H_OFFIC_HOL.GM');
  fs.writeFileSync(variant, 'keep'); assert.equal(applyFixes(root), 0);
  assert.equal(fs.readFileSync(variant, 'utf8'), 'keep');
  assert.equal(ciExists(root, 'resource/models/heads/h_offic_hol.gm'), variant);
  assert.equal(fs.readdirSync(path.dirname(variant)).filter((name) => name.toLowerCase() === 'h_offic_hol.gm').length, 1);
});
