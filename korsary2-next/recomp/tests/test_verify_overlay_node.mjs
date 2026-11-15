import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import {createHash} from 'node:crypto';
import {writeGame} from '../web/make_dist.mjs';
import {overlayManifestFor} from '../web/gamefiles.mjs';
import {checkOverlay,checkOverlayExpected,canonicalOverlayJson,overlayPathProblem,readOverlayRequired} from './verify_dist_overlay.mjs';
import {manifestVersion} from './verify_dist_core.mjs';
const sha=b=>createHash('sha256').update(b).digest('hex');
async function fixture(t){
 const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-overlay-check-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));
 const dist=path.join(root,'dist'),src=path.join(root,'src'),game=path.join(dist,'game'),ov=path.join(dist,'game-en');fs.mkdirSync(path.join(src,'PROGRAM'),{recursive:true});fs.mkdirSync(game,{recursive:true});fs.mkdirSync(ov,{recursive:true});
 const source=path.join(src,'PROGRAM/a.c'),data=Buffer.from('Hello '.repeat(1000));fs.writeFileSync(source,data);const baseSha=sha('base content');
 fs.writeFileSync(path.join(game,'manifest.json'),JSON.stringify({files:[{path:'PROGRAM/a.c',size:12,sha256:baseSha}],version:'v'}));
 const meta={format:1,language:'English',base:{'PROGRAM/a.c':baseSha}},files=new Map([['PROGRAM/a.c',source]]),[packed,packs,hashes]=await writeGame(files,ov);
 const m=overlayManifestFor(files,packed,packs,hashes,meta),mPath=path.join(ov,'manifest.json'),save=()=>fs.writeFileSync(mPath,JSON.stringify(m));save();
 fs.writeFileSync(path.join(dist,'overlay-required.json'),JSON.stringify({format:1,required:['PROGRAM/a.c']}));
 fs.writeFileSync(path.join(dist,'_headers'),'/*\n  Cross-Origin-Opener-Policy: same-origin\n  Cross-Origin-Embedder-Policy: require-corp\n  Cross-Origin-Resource-Policy: same-origin\n  X-Robots-Tag: noindex\n  Cache-Control: no-cache\n');
 const bytes=canonicalOverlayJson(meta),ref={format:1,files:[{path:'OVERLAY.json',cls:'meta',size:bytes.length,sha256:sha(bytes)},{path:'PROGRAM/a.c',cls:'manual',size:data.length,sha256:sha(data),base_sha256:baseSha}],totals:{by_class:{manual:{files:1}},bytes_by_class:{}},resources:{}},refPath=path.join(root,'expected.json');fs.writeFileSync(refPath,JSON.stringify(ref));
 return {root,dist,game,ov,m,mPath,meta,ref,refPath,save,verify:()=>checkOverlay(dist,{required:['PROGRAM/a.c'],fullHash:true,mustExist:true})};
}
test('overlay reference, metadata, hashes and base compatibility pass',async t=>{
 const f=await fixture(t),b=f.verify();assert.ok(b.passed,b.failures().join('\n'));const r=checkOverlayExpected(f.dist,f.refPath);assert.ok(r.passed,r.failures().join('\n'));
 assert.deepEqual(readOverlayRequired(path.join(f.dist,'overlay-required.json')),[['PROGRAM/a.c'],[],[]]);
});
test('missing, corrupt, duplicate and forbidden overlay data are rejected',async t=>{
 const f=await fixture(t),original=JSON.stringify(f.m),cases=[m=>m.files.push({...m.files[0]}),m=>{m.files[0].path='SAVE/private';},m=>{m.files[0].path='PROGRAM/../secret';},m=>{m.files[0].size=-1;},m=>{m.files[0].sha256='x';},m=>{m.files[0].offset+=100000;},m=>{m.version='stale';},m=>{m.overlay.base['PROGRAM/a.c']='0'.repeat(64);}];
 for(const mutate of cases){const m=JSON.parse(original);mutate(m);fs.writeFileSync(f.mPath,JSON.stringify(m));assert.equal(f.verify().passed,false,mutate.toString());}
 fs.writeFileSync(f.mPath,original);const pack=path.join(f.ov,f.m.packs[0].path),bytes=fs.readFileSync(pack);bytes[Math.floor(bytes.length/2)]^=1;fs.writeFileSync(pack,bytes);assert.equal(f.verify().passed,false);
});
test('required page contract and reference detect mismatches',async t=>{
 const f=await fixture(t);fs.writeFileSync(path.join(f.dist,'overlay-required.json'),JSON.stringify({format:1,required:['PROGRAM/other.c']}));assert.equal(f.verify().passed,false);
 f.ref.files[1].sha256='0'.repeat(64);fs.writeFileSync(f.refPath,JSON.stringify(f.ref));assert.equal(checkOverlayExpected(f.dist,f.refPath).passed,false);
 for(const p of ['../x','SAVE/x','PROGRAM/../x','PROGRAM/NUL.txt','program/x','PROGRAM/.hidden','RESOURCE/a\\b'])assert.ok(overlayPathProblem(p));
});
