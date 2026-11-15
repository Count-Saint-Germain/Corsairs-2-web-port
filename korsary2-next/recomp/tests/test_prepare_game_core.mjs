import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import crypto from 'node:crypto';
import { parsePatch, applyPatchBytes, loadPatches, stepPatches, installNew, listFiles, listingFingerprint, verify } from '../../tools/prepare_game_core.mjs';

const sha = (x) => crypto.createHash('sha256').update(x).digest('hex');
function fixture(t) {
  const root = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-prepare-core-'));
  t.after(() => fs.rmSync(root, { recursive: true, force: true }));
  const repack = path.join(root, 'repack'), out = path.join(root, 'out'), patches = path.join(root, 'patches');
  fs.mkdirSync(path.join(repack, 'PROGRAM'), { recursive: true }); fs.mkdirSync(path.join(out, 'PROGRAM'), { recursive: true }); fs.mkdirSync(patches);
  const before = Buffer.from([0x2f,0x2f,0x20,0xcf,0xf0,0xe8,0xe2,0xe5,0xf2,0x0d,0x0a,0x78,0x3d,0x31,0x0d,0x0a]);
  const after = Buffer.concat([before.subarray(0,11), Buffer.from('x=2\r\n')]);
  fs.writeFileSync(path.join(repack,'PROGRAM/a.c'),before); fs.writeFileSync(path.join(out,'PROGRAM/a.c'),before);
  const text = `# path: PROGRAM/a.c\n# sha256-before: ${sha(before)}\n# sha256-after: ${sha(after)}\n# eol-before: crlf\n# eol-after: crlf\n# final-newline: yes\n--- a/PROGRAM/a.c\n+++ b/PROGRAM/a.c\n@@ -2 +2 @@\n-x=1\n+x=2\n`;
  fs.writeFileSync(path.join(patches,'01.patch'),text);
  return { root,repack,out,patches,before,after,text };
}
test('applies CP1251 patch exactly with CRLF and preserves bytes', (t) => {
  const x=fixture(t), p=parsePatch(Buffer.from(x.text));
  assert.deepEqual(applyPatchBytes(p.meta,p.hunks,x.before),x.after);
  assert.deepEqual(stepPatches(x.out,x.patches),{applied:['PROGRAM/a.c'],already:[]});
  assert.deepEqual(fs.readFileSync(path.join(x.out,'PROGRAM/a.c')),x.after);
  assert.deepEqual(stepPatches(x.out,x.patches),{applied:[],already:['PROGRAM/a.c']});
});
test('rejects wrong hash and mismatched hunk without replacing file', (t) => {
  const x=fixture(t), file=path.join(x.out,'PROGRAM/a.c');
  fs.writeFileSync(file,'different'); assert.throws(()=>stepPatches(x.out,x.patches),/SHA-256/);
  assert.equal(fs.readFileSync(file,'utf8'),'different');
  const p=parsePatch(Buffer.from(x.text.replace('-x=1','-x=9')));
  assert.throws(()=>applyPatchBytes(p.meta,p.hunks,x.before),/does not match/);
});
test('rejects path traversal and any symlink component before modification', (t) => {
  const x=fixture(t), file=path.join(x.patches,'01.patch');
  fs.writeFileSync(file,x.text.replace('path: PROGRAM/a.c','path: ../escape'));
  assert.throws(()=>stepPatches(x.out,x.patches),/unsafe/);
  fs.writeFileSync(file,x.text);
  fs.rmSync(path.join(x.out,'PROGRAM'),{recursive:true}); fs.symlinkSync(path.join(x.repack,'PROGRAM'),path.join(x.out,'PROGRAM'));
  assert.throws(()=>stepPatches(x.out,x.patches),/symlink/);
  assert.deepEqual(fs.readFileSync(path.join(x.repack,'PROGRAM/a.c')),x.before);
});
test('does not overwrite files and dry-run does not modify original', (t) => {
  const x=fixture(t), f=path.join(x.out,'PROGRAM/a.c');
  assert.equal(installNew(f,{data:Buffer.from('changed')}),false);
  assert.deepEqual(fs.readFileSync(f),x.before);
  stepPatches(x.out,x.patches,true); assert.deepEqual(fs.readFileSync(f),x.before);
  const d=path.join(x.out,'created/file'); assert.equal(installNew(d,{data:Buffer.from('new')}),true);
  assert.equal(fs.readFileSync(d,'utf8'),'new');
});
test('checks reference hashes, runtime extras and missing files', (t) => {
  const x=fixture(t); stepPatches(x.out,x.patches);
  const listing=listFiles(x.repack);
  const manifest={source:{repack_listing_sha256:listingFingerprint(listing)},added:[],modified:[{path:'PROGRAM/a.c',size_before:x.before.length,size_after:x.after.length,sha256_before:sha(x.before),sha256_after:sha(x.after)}],counts:{repack_files:1,protected_files_excluded:0,added_total:0}};
  assert.deepEqual(verify(x.out,x.repack,manifest,{deep:true,patchDir:x.patches}),{errors:[],warnings:[]});
  fs.writeFileSync(path.join(x.out,'system.log'),'log'); assert.equal(verify(x.out,x.repack,manifest).warnings.length,1);
  fs.writeFileSync(path.join(x.out,'PROGRAM/a.c'),'broken'); assert.ok(verify(x.out,x.repack,manifest).errors.some((e)=>e.includes('SHA-256')));
});
test('rejects malformed patch metadata and truncated hunks', () => {
  assert.throws(()=>parsePatch(Buffer.from('# path: x\n')),/missing/);
  const s=`# path: a\n# sha256-before: ${'0'.repeat(64)}\n# sha256-after: ${'0'.repeat(64)}\n# eol-before: lf\n# eol-after: lf\n# final-newline: yes\n--- a/a\n+++ b/a\n@@ -1,2 +1,2 @@\n-x\n+y\n`;
  assert.throws(()=>parsePatch(Buffer.from(s)),/counts do not match/);
});
