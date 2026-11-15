import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { gzipSync, brotliCompressSync, constants as zc } from 'node:zlib';
import { safeRelpath,diskName,openRegular,sha256File,scanTree,fingerprint,brotliWindowBits,unpackRecord,readPackRecord,manifestVersion,parseHeaders,headersForUrl,referencedImports } from './verify_dist_core.mjs';
function temp(t){const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-verifier-node-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));return dir;}
const sha=b=>createHash('sha256').update(b).digest('hex');
test('safe paths, encodings and manifest versions',()=>{
 for(const p of ['/abs','a/../b','a//b','a/.hidden','a\\b',''])assert.equal(safeRelpath(p),false,p);
 assert.ok(safeRelpath('RESOURCE/Textures/x.tga.tx'));assert.equal(diskName({path:'x',enc:'gzip'}),'x.gz');assert.equal(diskName({path:'x',enc:'br'}),'x.br');
 const m=JSON.parse(fs.readFileSync('distribution/game/manifest.json'));assert.equal(manifestVersion(m.files),m.version);
});
test('scanning and same-descriptor opens reject symlinks and hardlinks',t=>{
 const dir=temp(t);fs.writeFileSync(path.join(dir,'ordinary'),'123');fs.symlinkSync('ordinary',path.join(dir,'symbolic'));fs.linkSync(path.join(dir,'ordinary'),path.join(dir,'hard'));
 const {files,problems}=scanTree(dir);assert.equal(files.size,0);assert.equal(problems.length,3);
 assert.throws(()=>openRegular(path.join(dir,'symbolic')));assert.throws(()=>openRegular(path.join(dir,'hard')));
 fs.unlinkSync(path.join(dir,'hard'));assert.equal(sha256File(path.join(dir,'ordinary')),sha('123'));
 const before=fingerprint(dir);fs.writeFileSync(path.join(dir,'ordinary'),'changed');assert.notDeepEqual(fingerprint(dir),before);
});
test('gzip and Brotli decode exact bounded streams, refusing corruption and tails',()=>{
 const plain=Buffer.from('chunked content '.repeat(1000));
 for(const [kind,packed] of [['gzip',gzipSync(plain)],['br',brotliCompressSync(plain,{params:{[zc.BROTLI_PARAM_LGWIN]:22}})]]){
  assert.deepEqual(unpackRecord(kind,packed,plain.length),plain);
  assert.throws(()=>unpackRecord(kind,packed.subarray(0,-1),plain.length));
  assert.throws(()=>unpackRecord(kind,Buffer.concat([packed,Buffer.from('garbage')]),plain.length));
  assert.throws(()=>unpackRecord(kind,packed,10));
 }
 const damaged=gzipSync(plain);damaged[damaged.length-8]^=1;assert.throws(()=>unpackRecord('gzip',damaged,plain.length));
 assert.equal(brotliWindowBits(0),16);assert.equal(brotliWindowBits(3),18);
});
test('pack records check spans, length, decoding and digest',t=>{
 const dir=temp(t),a=Buffer.from('abc'.repeat(300)),b=Buffer.from('plain'),z=gzipSync(a),file=path.join(dir,'pack');fs.writeFileSync(file,Buffer.concat([z,b]));
 assert.deepEqual(readPackRecord(file,{offset:0,csize:z.length,enc:'gzip',size:a.length}),{size:a.length,sha256:sha(a)});
 assert.deepEqual(readPackRecord(file,{offset:z.length,csize:b.length,size:b.length}),{size:b.length,sha256:sha(b)});
 assert.throws(()=>readPackRecord(file,{offset:0,csize:z.length+100,enc:'gzip',size:a.length}));
});
test('headers and recursive literal imports are independently validated',t=>{
 const [rules,dup]=parseHeaders('/*\n  Cache-Control: no-cache\n  X-A: 1\n  X-A: 2\n/game/*\n  X-A: 3\n');assert.deepEqual(dup,['/*: x-a']);assert.deepEqual(headersForUrl('/game/x',rules)['x-a'],['2','3']);
 const dir=temp(t);for(const name of ['index.html','port.js','port-config.js','netplay.js','audio-worklet.js'])fs.writeFileSync(path.join(dir,name),'');
 fs.writeFileSync(path.join(dir,'index.html'),'<script type="module">import("./save-import.mjs")</script>');fs.writeFileSync(path.join(dir,'save-import.mjs'),"import './child.mjs';");fs.writeFileSync(path.join(dir,'child.mjs'),'');
 const result=referencedImports(dir);assert.ok(result.referenced.has('save-import.mjs'));assert.ok(result.referenced.has('child.mjs'));assert.deepEqual(result.unreadable,[]);
});

test('high-level blocks detect broken headers, missing imports, damaged WASM and video',async t=>{
 const {checkStructure,checkPageModules,checkBuild,checkVideos}=await import('./verify_dist_checks.mjs');
 const dir=temp(t),source='distribution';
 for(const name of ['index.html','port.js','port-config.js','netplay.js','audio-worklet.js','missing-resource-preflight.mjs','save-export.mjs','save-import.mjs','save-owner.mjs','save-protection.mjs','save-read-indicator.mjs','save-tx.mjs','video-player.mjs','touch-controls.mjs','overlay.mjs','game-transfer.mjs','brotli-decoder.mjs','overlay-required.json','_headers','robots.txt'])fs.copyFileSync(path.join(source,name),path.join(dir,name));
 // The streaming launcher imports modules in subdirectories as well.
 for(const name of referencedImports(source).referenced){const dst=path.join(dir,name);fs.mkdirSync(path.dirname(dst),{recursive:true});fs.copyFileSync(path.join(source,name),dst);}
 fs.mkdirSync(path.join(dir,'vendor/brotli'),{recursive:true});fs.copyFileSync(path.join(source,'vendor/brotli/k2br.wasm'),path.join(dir,'vendor/brotli/k2br.wasm'));
 fs.mkdirSync(path.join(dir,'game'));fs.writeFileSync(path.join(dir,'game/manifest.json'),'{}');fs.mkdirSync(path.join(dir,'build'));
 fs.writeFileSync(path.join(dir,'build/game.js'),"_port_video_poll _port_video_done _port_video_name_buf game.wasm");
 fs.writeFileSync(path.join(dir,'build/game.wasm'),Buffer.concat([Buffer.from([0,97,115,109,1,0,0,0]),Buffer.from('port_video_poll port_video_done port_video_name_buf')]));
 const player=fs.readFileSync(path.join(dir,'video-player.mjs'),'utf8'),list=/VIDEO_FILES\s*=\s*\{([^}]*)\}/.exec(player)[1];
 for(const m of list.matchAll(/["']videos\/([^"']+)["']/g)){const p=path.join(dir,'videos',m[1]);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,Buffer.from([0,0,0,8,102,116,121,112]));}
 let files=scanTree(dir).files;assert.ok(checkStructure(dir,files).passed);assert.ok(checkPageModules(dir,files).passed);assert.ok(checkBuild(dir).passed);assert.ok(checkVideos(dir).passed);
 fs.writeFileSync(path.join(dir,'vendor/extra.js'),'unexpected');assert.ok(!checkStructure(dir,scanTree(dir).files).passed);fs.unlinkSync(path.join(dir,'vendor/extra.js'));
 fs.appendFileSync(path.join(dir,'_headers'),'  Cross-Origin-Opener-Policy: broken\n');assert.ok(!checkStructure(dir,files).passed);
 fs.unlinkSync(path.join(dir,'save-import.mjs'));files=scanTree(dir).files;assert.ok(!checkPageModules(dir,files).passed);
 fs.writeFileSync(path.join(dir,'build/game.wasm'),'bad');assert.ok(!checkBuild(dir).passed);
 fs.writeFileSync(path.join(dir,'videos/Trailer.mp4'),'bad');assert.ok(!checkVideos(dir).passed);
});
