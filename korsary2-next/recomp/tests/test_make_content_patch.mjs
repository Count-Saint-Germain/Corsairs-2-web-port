import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { makePatch, detectEol, writePatches, buildManifest, classify } from '../../tools/make_content_patch.mjs';
import { parsePatch, applyPatchBytes, sha256File } from '../../tools/prepare_game_core.mjs';
function setup(t){const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-patch-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));return root;}
function write(root,rel,data){const p=path.join(root,rel);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,data);}
function roundTrip(name,before,after){const patch=makePatch(name,before,after), parsed=parsePatch(patch);assert.deepEqual(applyPatchBytes(parsed.meta,parsed.hunks,before),after);return parsed;}
test('generates exact patch for CP1251 and CRLF to LF',()=>{
 const before=Buffer.from([47,47,32,0xcf,0xf0,0xe8,0xe2,0xe5,0xf2,13,10,120,61,49,13,10]);
 const after=Buffer.concat([before.subarray(0,9),Buffer.from('\nx=2\n')]);
 const {meta}=roundTrip('PROGRAM/Init.c',before,after);assert.equal(meta['eol-before'],'crlf');assert.equal(meta['eol-after'],'lf');
});
test('handles insertion, deletion and missing final newline without fuzz',()=>{
 for(const [before,after] of [['a\nb\n','a\nx\nb\n'],['a\nx\nb\n','a\nb\n'],['abc','xyz'],['','new']])roundTrip('PROGRAM/a.c',Buffer.from(before),Buffer.from(after));
});
test('rejects mixed line endings, mismatched final newline, traversal, or no logical change',()=>{
 assert.throws(()=>detectEol(Buffer.from('a\r\nb\n'),'x'),/mixed/);
 assert.throws(()=>makePatch('x',Buffer.from('a\n'),Buffer.from('a')),/final newline/);
 assert.throws(()=>makePatch('../outside',Buffer.from('a'),Buffer.from('b')),/unsafe/);
 assert.throws(()=>makePatch('x',Buffer.from('a'),Buffer.from('a')),/no logical changes/);
});
test('writes numbered patches and generates matching manifest', (t)=>{
 const root=setup(t),rep=path.join(root,'rep'),work=path.join(root,'work'),patches=path.join(root,'patches');
 write(rep,'PROGRAM/a.c','one\r\ntwo\r\n');write(work,'PROGRAM/a.c','one\r\nTWO\r\n');
 write(rep,'ENGINE.exe','engine');write(work,'ENGINE.exe','engine');write(rep,'engine.dll','synthetic-protected');
 write(rep,'RESOURCE/MODELS/Ammo/b.gm','item');write(work,'RESOURCE/MODELS/Ammo/b.gm','item');
 write(work,'RESOURCE/MODELS/Items/b.gm','item');write(work,'RESOURCE/Sounds/MUSIC/Coridor.ogg','music');write(work,'system.log','runtime');
 writePatches(rep,work,patches,['PROGRAM/a.c']);const m=buildManifest(rep,work,patches);
 assert.equal(m.source.repack_files_total_listing,4);assert.equal(m.counts.protected_files_excluded,1);
 assert.equal(m.counts.modified,1);assert.equal(m.counts.added_total,2);assert.equal(m.counts.unchanged_common,2);
 assert.equal(m.modified[0].sha256_before,sha256File(path.join(rep,'PROGRAM/a.c')));
 assert.equal(m.added.find((e)=>e.kind==='music').from,'setup-1.bin');
 assert.equal(m.added.find((e)=>e.kind==='items_model').from,'RESOURCE/MODELS/Ammo/b.gm');
 assert.equal(fs.readdirSync(patches)[0],'01-a.c.patch');
});
test('rejects unknown additions, missing source files and incomplete patch sets',(t)=>{
 const root=setup(t),rep=path.join(root,'rep'),work=path.join(root,'work'),patches=path.join(root,'patches');
 write(rep,'PROGRAM/a.c','a\n');write(work,'PROGRAM/a.c','b\n');fs.mkdirSync(patches);
 assert.throws(()=>buildManifest(rep,work,patches),/patches do not cover/);
 write(work,'unknown.bin','x');assert.throws(()=>buildManifest(rep,work),/unclassified/);
 fs.rmSync(path.join(work,'unknown.bin'));fs.rmSync(path.join(work,'PROGRAM/a.c'));assert.throws(()=>buildManifest(rep,work),/absent/);
 assert.throws(()=>classify('unknown.bin'),/unclassified/);
});
