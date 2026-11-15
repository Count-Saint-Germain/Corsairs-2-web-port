import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { brotliCompressSync, constants as zc } from 'node:zlib';
import { writeGame } from '../web/make_dist.mjs';
import { manifestFor } from '../web/gamefiles.mjs';
import { checkManifest } from './verify_dist_manifest.mjs';
import { manifestVersion } from './verify_dist_core.mjs';
async function fixture(t,{pack=true,codec='gzip'}={}){
 const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-verify-manifest-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));const src=path.join(dir,'source'),game=path.join(dir,'dist/game');fs.mkdirSync(src,{recursive:true});fs.mkdirSync(game,{recursive:true});
 const files=new Map();for(const [name,data] of [['ENGINE.exe','engine'],['options','settings'],['PROGRAM/a.c','A'.repeat(4000)],['RESOURCE/raw.ogg','ogg'],['RESOURCE/other.c','B'.repeat(4000)]]){const p=path.join(src,name);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,data);files.set(name,p);}
 fs.writeFileSync(path.join(dir,'dist/game-transfer.mjs'),'module');fs.writeFileSync(path.join(dir,'dist/brotli-decoder.mjs'),fs.readFileSync('distribution/brotli-decoder.mjs'));fs.mkdirSync(path.join(dir,'dist/vendor/brotli'),{recursive:true});fs.copyFileSync('distribution/vendor/brotli/k2br.wasm',path.join(dir,'dist/vendor/brotli/k2br.wasm'));
 const [packed,packs,hashes]=await writeGame(files,game,{pack,codec,quality:5});const sources=new Map([...files].map(([n,p])=>[n,packed.has(n)?p:path.join(game,n)]));const m=manifestFor(sources,packed,packs,hashes),manifest=path.join(game,'manifest.json');
 const save=()=>fs.writeFileSync(manifest,JSON.stringify(m));save();return {dir,game,m,save,verify:()=>checkManifest(path.join(dir,'dist'),{fullHash:true})};
}
test('independent manifest block validates packed, loose gzip and Brotli',async t=>{
 for(const options of [{},{pack:false},{codec:'br'}]){const f=await fixture(t,options);const b=f.verify();assert.ok(b.passed,b.failures().join('\n'));}
});
test('manifest detects missing and damaged packed objects',async t=>{
 const f=await fixture(t);const pack=path.join(f.game,f.m.packs[0].path),original=fs.readFileSync(pack);
 fs.unlinkSync(pack);assert.equal(f.verify().passed,false);fs.writeFileSync(pack,original.subarray(0,-1));assert.equal(f.verify().passed,false);
 const corrupted=Buffer.from(original);corrupted[Math.floor(corrupted.length/2)]^=1;fs.writeFileSync(pack,corrupted);assert.equal(f.verify().passed,false);
});
test('manifest detects bad paths, duplicates, save leaks, offsets, hashes and stale version',async t=>{
 const f=await fixture(t),snapshot=JSON.stringify(f.m),cases=[
  m=>{m.files[0].path='../escape';},m=>{m.files.push({...m.files[0]});},m=>{m.files.push({...m.files[0],path:m.files[0].path.toLowerCase()});},
  m=>{m.files[0].path='SAVE/slot';},m=>{m.files.find(e=>e.pack!==undefined).offset++;},m=>{m.files.find(e=>e.pack!==undefined).csize++;},
  m=>{m.files[0].sha256='0'.repeat(64);},m=>{m.files[0].size=-1;},m=>{m.files[0].enc='unsupported';},m=>{m.version='stale';},
 ];
 for(const mutate of cases){Object.assign(f.m,JSON.parse(snapshot));mutate(f.m);f.save();assert.equal(f.verify().passed,false,mutate.toString());}
});
test('manifest detects extra objects and stale relocation rules',async t=>{
 const f=await fixture(t);fs.writeFileSync(path.join(f.game,'extra'),'unexpected');assert.equal(f.verify().passed,false);fs.unlinkSync(path.join(f.game,'extra'));
 const e=f.m.files.find(e=>e.path==='RESOURCE/raw.ogg');e.path='RESOURCE/Textures/Loading/Russian/x.tx';f.m.version=manifestVersion(f.m.files);f.save();
 const b=checkManifest(path.join(f.dir,'dist'),{fullHash:true,relocateRules:[{from:'RESOURCE/Textures/Loading/Russian',to:'RESOURCE/Textures/Loading'}]});assert.equal(b.passed,false);
});

test('Brotli verification rejects corruption, oversize output, wide windows and missing decoder',async t=>{
 const f=await fixture(t,{pack:false,codec:'br'}),entry=f.m.files.find(e=>e.enc==='br');assert.ok(entry,'fixture must contain Brotli data');
 const object=path.join(f.game,entry.path+'.br'),original=fs.readFileSync(object),manifest=JSON.stringify(f.m),decoder=path.join(f.dir,'dist/brotli-decoder.mjs'),wasm=path.join(f.dir,'dist/vendor/brotli/k2br.wasm'),decoderBytes=fs.readFileSync(decoder),wasmBytes=fs.readFileSync(wasm);
 const corrupt=Buffer.from(original);corrupt[Math.floor(corrupt.length/2)]^=255;
 const cases=[
  ['corrupt',()=>fs.writeFileSync(object,corrupt)],['truncated',()=>fs.writeFileSync(object,original.subarray(0,-1))],['trailing bytes',()=>fs.writeFileSync(object,Buffer.concat([original,Buffer.from('junk')]))],
  ['decompression bomb',()=>{const bytes=brotliCompressSync(Buffer.alloc(8*1024*1024,65));fs.writeFileSync(object,bytes);entry.csize=bytes.length;}],
  ['wide window',()=>{const bytes=brotliCompressSync(Buffer.alloc(entry.size,65),{params:{[zc.BROTLI_PARAM_LGWIN]:24}});fs.writeFileSync(object,bytes);entry.csize=bytes.length;}],
  ['additional gzip object',()=>fs.writeFileSync(path.join(f.game,entry.path+'.gz'),'x')],['additional raw object',()=>fs.writeFileSync(path.join(f.game,entry.path),'x')],
  ['missing decoder',()=>fs.unlinkSync(decoder)],['missing wasm',()=>fs.unlinkSync(wasm)],['different wasm',()=>fs.appendFileSync(wasm,'bad')],
  ['wrong csize',()=>{entry.csize=1;}],['wrong raw size',()=>{entry.size--;}],['unknown encoding',()=>{entry.enc='zstd';}],['options compressed',()=>{const e=f.m.files.find(x=>x.path==='options');e.enc='br';e.csize=1;}],
 ];
 for(const [name,mutate] of cases){Object.assign(f.m,JSON.parse(manifest));const active=f.m.files.find(e=>e.path===entry.path);Object.assign(entry,active);f.m.files[f.m.files.indexOf(active)]=entry;
  fs.writeFileSync(object,original);fs.writeFileSync(decoder,decoderBytes);fs.writeFileSync(wasm,wasmBytes);fs.rmSync(path.join(f.game,entry.path+'.gz'),{force:true});fs.rmSync(path.join(f.game,entry.path),{force:true});mutate();f.save();assert.equal(f.verify().passed,false,name);
 }
});
test('Brotli record corruption inside a pack is detected',async t=>{
 const f=await fixture(t,{codec:'br'}),e=f.m.files.find(item=>item.enc==='br'&&item.pack!==undefined);assert.ok(e);const file=path.join(f.game,f.m.packs[e.pack].path),bytes=fs.readFileSync(file);bytes[e.offset+Math.floor(e.csize/2)]^=255;fs.writeFileSync(file,bytes);assert.equal(f.verify().passed,false);
});
test('gzip verification rejects damaged objects, impossible metadata and missing transfer module',async t=>{
 const f=await fixture(t,{pack:false}),entry=f.m.files.find(e=>e.enc==='gzip');assert.ok(entry);const name=entry.path,object=path.join(f.game,name+'.gz'),original=fs.readFileSync(object),snapshot=JSON.stringify(f.m),transfer=path.join(f.dir,'dist/game-transfer.mjs'),transferBytes=fs.readFileSync(transfer);
 const corrupt=Buffer.from(original);corrupt[Math.floor(corrupt.length/2)]^=255;
 const cases=[['corrupt',e=>fs.writeFileSync(object,corrupt)],['truncated',e=>fs.writeFileSync(object,original.subarray(0,-1))],['junk',e=>fs.writeFileSync(object,Buffer.concat([original,Buffer.from('junk')]))],['extra raw copy',e=>fs.writeFileSync(path.join(f.game,name),'extra')],['missing gzip',e=>fs.unlinkSync(object)],['wrong csize',e=>{e.csize=1;}],['missing csize',e=>{delete e.csize;}],['wrong size',e=>{e.size=1;}],['unknown encoding',e=>{e.enc='zstd';}],['packed options',()=>{const e=f.m.files.find(x=>x.path==='options');e.enc='gzip';e.csize=1;}],['missing transfer module',()=>fs.unlinkSync(transfer)]];
 for(const [name,mutate] of cases){Object.assign(f.m,JSON.parse(snapshot));fs.writeFileSync(object,original);fs.writeFileSync(transfer,transferBytes);fs.rmSync(path.join(f.game,entry.path),{force:true});mutate(f.m.files.find(e=>e.path===entry.path));f.save();assert.equal(f.verify().passed,false,name);}
 fs.writeFileSync(object,original.subarray(0,-1));Object.assign(f.m,JSON.parse(snapshot));f.save();assert.equal(checkManifest(path.join(f.dir,'dist'),{fullHash:false,minHashes:0,targetHashes:0}).passed,false,'size mismatch is checked without sampling');
});

test('packed layout detects the full range of object and manifest damage',async t=>{
 const f=await fixture(t),snapshot=JSON.stringify(f.m),pack=path.join(f.game,f.m.packs[0].path),original=fs.readFileSync(pack),transfer=path.join(f.dir,'dist/game-transfer.mjs'),transferBytes=fs.readFileSync(transfer);
 const packed=m=>m.files.filter(e=>e.pack===0),rec=(m,pred)=>{const e=packed(m).find(pred);assert.ok(e);return e;};
 const extra=path.join(f.game,'_k2pack/unlisted.pack'),loose=path.join(f.game,'PROGRAM/a.c');
 const flip=(m,pred)=>{const e=rec(m,pred),b=Buffer.from(original);b[e.offset+Math.floor(e.csize/2)]^=255;fs.writeFileSync(pack,b);};
 const cases=[['gzip corruption',m=>flip(m,e=>e.enc==='gzip')],['raw corruption',m=>flip(m,e=>!e.enc&&e.csize>0)],['truncated pack',()=>fs.writeFileSync(pack,original.subarray(0,-1))],['trailing pack bytes',()=>fs.writeFileSync(pack,Buffer.concat([original,Buffer.from('junk')]))],['missing pack',()=>fs.unlinkSync(pack)],['extra pack',()=>fs.writeFileSync(extra,'x')],['unlisted loose copy',()=>{fs.mkdirSync(path.dirname(loose),{recursive:true});fs.writeFileSync(loose,'x');}],['gap',m=>{rec(m,e=>e.offset>0).offset++;}],['overlap',m=>{rec(m,e=>e.offset>0).offset--;}],['record beyond pack',m=>{rec(m,()=>true).csize+=1e6;}],['bad pack index',m=>{rec(m,()=>true).pack=99;}],['missing packs list',m=>{delete m.packs;}],['wrong pack size',m=>{m.packs[0].size++;}],['wrong member count',m=>{m.packs[0].files++;}],['raw compressed size',m=>{rec(m,e=>!e.enc&&e.csize>0).csize--;}],['packed options',m=>{const e=m.files.find(x=>x.path==='options');Object.assign(e,{pack:0,offset:0,csize:e.size});}],['reserved folder',m=>{m.files.push({path:'_k2pack/x',size:1,sha256:'0'.repeat(64)});}],['bad pack path',m=>{m.packs[0].path='elsewhere/pack';}],['wrong hash',m=>{rec(m,()=>true).sha256='0'.repeat(64);}],['missing transfer',()=>fs.unlinkSync(transfer)]];
 for(const [name,mutate] of cases){Object.assign(f.m,JSON.parse(snapshot));fs.writeFileSync(pack,original);fs.writeFileSync(transfer,transferBytes);fs.rmSync(extra,{force:true});fs.rmSync(loose,{force:true});mutate(f.m);f.save();assert.equal(f.verify().passed,false,name);}
});
