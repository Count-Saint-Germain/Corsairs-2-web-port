import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import zlib from 'node:zlib';
import { Tree, Bulk, read_dir_tree, read_dir_bulk, read_iso_sources, Manual, Leftovers, Result, check_protected, classify_left, check_anchors, sha256, Fail } from '../../tools/prepare_english_core.mjs';
const write=(root,rel,data)=>{const p=path.join(root,rel);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,data);return p;};
function fixture(t){const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-en-core-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));return dir;}
const metadata=(root,name,entries)=>write(root,name,JSON.stringify({format:1,entries}));
test('tree is case-insensitive, deterministic, and rejects case collisions',()=>{
 const t=new Tree();t.add('Program/A.c',Buffer.from('a'));t.add('PROGRAM/B.c',Buffer.from('b'));
 assert.equal(t.get('program/a.c').toString(),'a');assert.equal(t.name('program/a.c'),'Program/A.c');assert.equal(t.digest().length,64);
 assert.deepEqual(t.keys(),['PROGRAM/A.C','PROGRAM/B.C']);assert.throws(()=>t.add('program/a.C',Buffer.from('other')),/case/);
});
test('directory readers select only text/bulk paths and do not read user data',(t)=>{
 const root=fixture(t);write(root,'program/test.c','script');write(root,'resource/INI/TEXTS/RUSSIAN/common.ini','text');write(root,'resource/INI/fonts.ini','fonts');
 write(root,'RESOURCE/Textures/Loading/a.tx','texture');write(root,'RESOURCE/Sounds/VOICE/x.wav','voice');write(root,'SAVE/private.sav','save');
 const tree=read_dir_tree(root),bulk=read_dir_bulk(root);assert.deepEqual(tree.paths().map((p)=>p.toLowerCase()),['program/test.c','resource/ini/fonts.ini','resource/ini/texts/russian/common.ini']);
 assert.equal(tree.get('SAVE/private.sav'),null);assert.equal(bulk.read('resource/textures/loading/A.tx').toString(),'texture');assert.equal(bulk.has('SAVE/private.sav'),false);
});
test('bulk loads lazily, caches, drops cache and validates sizes',()=>{
 const b=new Bulk();let n=0;b.add('RESOURCE/Sounds/VOICE/A.wav',3,()=>{n++;return Buffer.from('abc');});b.add('RESOURCE/Sounds/VOICE/Sub/B.wav',1,()=>Buffer.from('b'));
 assert.equal(n,0);assert.equal(b.read('resource/sounds/voice/a.wav').toString(),'abc');b.read('RESOURCE/Sounds/VOICE/A.wav');assert.equal(n,1);
 b.drop('resource/sounds/voice/A.wav');b.read('resource/sounds/voice/A.wav');assert.equal(n,2);
 assert.deepEqual(b.under('RESOURCE/Sounds/VOICE',true),['RESOURCE/Sounds/VOICE/A.wav']);assert.equal(b.dir_spelling('resource/sounds/voice'),'RESOURCE/Sounds/VOICE');
 b.add('x',2,()=>Buffer.from('x'));assert.throws(()=>b.read('x'),/size mismatch/);assert.throws(()=>b.add('X',1,()=>Buffer.from('x')),/case/);
});
test('manual layer validates entries, duplicates, indices and ASCII',(t)=>{
 const dir=fixture(t),hash='a'.repeat(64),file=metadata(dir,'manual.json',[{kind:'literal',file:'PROGRAM/a.c',index:1,ru_sha256:hash,en:'Hello'}, {kind:'quest',file:'QUESTS',key:'q#1',ru_sha256:hash,en:'Quest'}, {kind:'pairs',file:'PROGRAM/b.h',map:{0:2,1:null},ru_literals:2,us_literals:3}]);
 const m=new Manual(file);assert.equal(m.count(),3);assert.equal(m.lit.get('PROGRAM/A.C').get(1)[0].toString(),'Hello');assert.deepEqual([...m.pairs.get('PROGRAM/B.H')[0]],[[0,2],[1,null]]);
 for(const entries of [
  [{kind:'literal',file:'a',index:-1,ru_sha256:hash,en:'x'}],
  [{kind:'literal',file:'a',index:1,ru_sha256:hash,en:'é'}],
  [{kind:'literal',file:'a',index:1,ru_sha256:hash,en:'x'},{kind:'literal',file:'A',index:1,ru_sha256:hash,en:'y'}],
 ]){metadata(dir,'bad.json',entries);assert.throws(()=>new Manual(path.join(dir,'bad.json')),Fail);}
});
test('leftover classification protects literals and rejects unknown, drift and unused entries',(t)=>{
 const dir=fixture(t),raw=Buffer.from('x="russian";'),literal=Buffer.from('russian'),hash=sha256(literal),file=metadata(dir,'left.json',[{file:'PROGRAM/a.c',index:0,ru_sha256:hash,class:'identifier',why:'used as key'}]);
 const l=new Leftovers(file),prot=l.lit.get('PROGRAM/A.C');check_protected('PROGRAM/a.c',raw,[[2,11]],prot,new Map());
 assert.throws(()=>check_protected('PROGRAM/a.c',raw,[[2,11]],prot,new Map([[0,'x']])),/protected/);
 assert.throws(()=>check_protected('PROGRAM/a.c',Buffer.from('x="changed";'),[[2,11]],prot,new Map()),/drift/);
 const result=new Result();result.left.push({file:'PROGRAM/a.c',index:0,ru_sha256:hash});classify_left(result,l);assert.equal(result.left[0].class,'identifier');
 const missing=new Leftovers(file);assert.throws(()=>classify_left(new Result(),missing),/do not match/);
 const unknown=new Result();unknown.left.push({file:'PROGRAM/other.c',index:0,ru_sha256:hash});assert.throws(()=>classify_left(unknown,new Leftovers(file)),/unclassified/);
 metadata(dir,'bad.json',[{file:'a',index:0,key:'x',ru_sha256:hash,class:'debug',why:'reason'}]);assert.throws(()=>new Leftovers(path.join(dir,'bad.json')),Fail);
});
test('anchor thresholds refuse questionable alignments',()=>{check_anchors('a',[19,0]);check_anchors('a',[100,99]);assert.throws(()=>check_anchors('a',[100,98]),/questionable/);});
