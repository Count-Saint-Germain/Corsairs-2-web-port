import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { spawnSync } from 'node:child_process';
import { buildDistribution, estimate, parseSize, pageAssets, requireEmptyOutput, videoFiles } from '../web/make_dist.mjs';
import { gameFiles, unpackRecord } from '../web/gamefiles.mjs';
function fixture(t){const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-node-dist-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));const game=path.join(root,'game'),build=path.join(root,'build');
 const put=(base,p,body)=>{const dest=path.join(base,p);fs.mkdirSync(path.dirname(dest),{recursive:true});fs.writeFileSync(dest,body);};
 for(const f of ['ENGINE.exe','engine.ini','options','PROGRAM/seadogs.c','PROGRAM/CONTROLS/controls.c','PROGRAM/CONTROLS/init_pc.c','MODULES/XINTERFACE.dll','MODULES/DX8RENDER.dll','MODULES/SOUND.dll','MODULES/PCS_CONTROLS.dll','RESOURCE/INI/TEXTS/language.ini'])put(game,f,`fixture ${f}`);
 put(game,'RESOURCE/large.txt','ABCD'.repeat(5000));put(game,'SAVE/user','private');
 put(build,'game.js',"var _port_video_poll=1, _port_video_done=2, _port_video_name_buf=3;var x='game.wasm';");
 put(build,'game.wasm',Buffer.concat([Buffer.from([0,97,115,109,1,0,0,0]),Buffer.alloc(64),Buffer.from('port_video_poll\0port_video_done\0port_video_name_buf\0')]));
 const videos=path.join(root,'videos');fs.mkdirSync(videos);
 const names=['Trailer.mp4','Artefact.mp4','BlackPearl.mp4','Blaze_land_dead.mp4','Blaze_mutiny_dead.mp4','Ending.mp4','Idol.mp4','Russian/Invasion.mp4','Skeleton_on_beach.mp4','Storm.mp4','Temple.mp4','Undersea.mp4','English/Invasion.mp4'];
 for(const name of names)put(videos,name,Buffer.from([0,0,0,8,102,116,121,112]));return {root,game,build,videos,put};}
function object(dist,e,m){if(e.pack!==undefined){const p=fs.readFileSync(path.join(dist,'game',m.packs[e.pack].path)),record=p.subarray(e.offset,e.offset+e.csize);return e.enc?unpackRecord(e.enc,record,e.size)[0]:record;}
 const file=path.join(dist,'game',e.path+(e.enc==='gzip'?'.gz':e.enc==='br'?'.br':'')),raw=fs.readFileSync(file);return e.enc?unpackRecord(e.enc,raw,e.size)[0]:raw;}
test('Node packager builds flat, compressed, packed and Brotli layouts with identical manifest version',async t=>{
 const {root,game,build,videos}=fixture(t), versions=[];
 for(const [name,opts] of [['plain',{noCompress:true,noPack:true}],['flat',{noPack:true}],['packs',{}],['brotli',{codec:'br',quality:5}]]){
  const out=path.join(root,name),result=await buildDistribution({game,out,videos,buildDir:build,...opts});versions.push(result.manifest.version);
  assert.ok(result.manifest.files.length>=12);assert.ok(!result.manifest.files.some(e=>e.path.startsWith('SAVE/')));
  const entry=result.manifest.files.find(e=>e.path==='RESOURCE/large.txt');assert.equal(object(out,entry,result.manifest).toString(),'ABCD'.repeat(5000));
  const verification=spawnSync(process.execPath,['korsary2-next/recomp/tests/verify_dist.mjs','--dist',out,'--full-hash','--no-freshness','--no-videos-web'],{encoding:'utf8'});
  assert.equal(verification.status,0,verification.stdout+'\n'+verification.stderr);
 }
 assert.equal(new Set(versions).size,1);
});
test('overlay metadata, required-file override, and base compatibility',async t=>{
 const {root,game,build,videos,put}=fixture(t),overlay=path.join(root,'overlay'),out=path.join(root,'dist');
 put(overlay,'PROGRAM/seadogs.c','English');put(overlay,'OVERLAY.json',JSON.stringify({format:1,language:'English',base:{}}));
 const result=await buildDistribution({game,out,videos,buildDir:build,overlayDir:overlay,overlayNoRequiredCheck:true});
 assert.equal(result.overlay.files.length,1);assert.equal(result.overlay.overlay.language,'English');
 assert.ok(fs.existsSync(path.join(out,'game-en/manifest.json')));
 await assert.rejects(buildDistribution({game,out:path.join(root,'bad'),videos,buildDir:build,overlayDir:overlay}),/required files/);
});
test('output and video checks reject unsafe input without overwrites',async t=>{
 const {root,game,build,videos}=fixture(t);
 await assert.rejects(buildDistribution({game,out:path.join(game,'dist'),videos,buildDir:build}),/inside the input/);
 const existing=path.join(root,'existing');fs.mkdirSync(existing);fs.writeFileSync(path.join(existing,'keep'),'mine');assert.throws(()=>requireEmptyOutput(existing),/not empty/);
 fs.symlinkSync(game,path.join(videos,'link'));assert.throws(()=>videoFiles(videos),/symlink/);
 assert.equal(parseSize('1 MiB'),1048576);assert.equal(parseSize('512K'),524288);assert.throws(()=>parseSize('2G'));
 assert.ok(pageAssets().includes('save-import.mjs'));
});
test('estimate reports per-extension and total sizes matching the built layouts without writing',async t=>{
 const {root,game,build,videos}=fixture(t),files=gameFiles(game);
 for(const codec of ['gzip','br']){
  const lines=[],before=fs.readdirSync(root),info=await estimate(files,{codec,quality:5,out:line=>lines.push(line)});assert.deepEqual(fs.readdirSync(root),before);
  assert.match(lines[0],/ext\s+files\s+packed/);assert.ok(lines.some(line=>line.startsWith('.txt')));const total=lines.find(line=>line.startsWith('TOTAL'));assert.ok(total);assert.match(lines.join('\n'),/requests:.*file by file/);assert.match(lines.join('\n'),/modelled network time/);
  const result=await buildDistribution({game,out:path.join(root,'estimate-check-'+codec),videos,buildDir:build,noPack:true,codec,quality:5});
  assert.equal(info.size,result.manifest.files.length);for(const entry of result.manifest.files){const measured=info.get(entry.path);assert.equal(measured.size,entry.size);assert.equal(measured.csize,entry.csize??entry.size);assert.equal(measured.enc,entry.enc??null);}
  const match=total.match(/^TOTAL\s+(\d+)\s+(\d+)/);assert.equal(Number(match[1]),result.manifest.files.length);assert.equal(Number(match[2]),result.manifest.files.filter(e=>e.enc).length);
  if(result.manifest.files.some(e=>e.enc==='br'))assert.match(lines[0],/as br.*gzip MB.*saved/);
 }
});
test('Brotli build keeps large compressed objects loose and packs smaller mixed records',async t=>{
 const {root,game,build,videos,put}=fixture(t),block=Buffer.alloc(4096);let state=55;for(let i=0;i<block.length;i++){state^=state<<13;state^=state>>>17;state^=state<<5;block[i]=state&255;}
 const largeData=Buffer.concat(Array.from(block.subarray(0,512),byte=>Buffer.alloc(20,byte)));put(game,'RESOURCE/big.gm',largeData);put(game,'RESOURCE/collision.gm','C'.repeat(4000));put(game,'RESOURCE/collision.gm.br','real asset');
 const out=path.join(root,'br-layout'),{manifest:m}=await buildDistribution({game,out,videos,buildDir:build,codec:'br',quality:5,maxFile:100,target:1024});
 const large=m.files.find(e=>e.path==='RESOURCE/big.gm'),collision=m.files.find(e=>e.path==='RESOURCE/collision.gm'),asset=m.files.find(e=>e.path==='RESOURCE/collision.gm.br');assert.equal(large.enc,'br');assert.equal(large.pack,undefined);assert.equal(collision.enc,undefined);assert.equal(object(out,asset,m).toString(),'real asset');
 assert.ok(m.files.some(e=>e.pack!==undefined&&e.enc==='br'));assert.ok(m.files.some(e=>e.pack!==undefined&&!e.enc));assert.deepEqual(object(out,large,m),largeData);
 const result=spawnSync(process.execPath,['korsary2-next/recomp/tests/verify_dist.mjs','--dist',out,'--full-hash','--no-freshness','--no-videos-web'],{encoding:'utf8'});assert.equal(result.status,0,result.stdout+'\n'+result.stderr);
});
test('packed builds are reproducible and ship the same bytes in fewer objects',async t=>{
 const {root,game,build,videos,put}=fixture(t);put(game,'PROGRAM/empty.c','');for(let i=0;i<20;i++)put(game,`RESOURCE/file${i}.c`,'payload '.repeat(500));
 const out1=path.join(root,'pack1'),out2=path.join(root,'pack2'),flat=path.join(root,'flat');const one=await buildDistribution({game,out:out1,videos,buildDir:build}),two=await buildDistribution({game,out:out2,videos,buildDir:build}),individual=await buildDistribution({game,out:flat,videos,buildDir:build,noPack:true});
 const entries=dir=>fs.readdirSync(dir,{recursive:true}).filter(p=>fs.statSync(path.join(dir,p)).isFile()).sort();const files=entries(path.join(out1,'game'));assert.deepEqual(files,entries(path.join(out2,'game')));for(const p of files)assert.deepEqual(fs.readFileSync(path.join(out1,'game',p)),fs.readFileSync(path.join(out2,'game',p)),p);
 assert.ok(files.length<entries(path.join(flat,'game')).length/3);assert.equal(one.manifest.version,two.manifest.version);assert.equal(one.manifest.version,individual.manifest.version);assert.equal(one.manifest.files.reduce((n,e)=>n+(e.csize??e.size),0),individual.manifest.files.reduce((n,e)=>n+(e.csize??e.size),0));
 const empty=one.manifest.files.find(e=>e.path==='PROGRAM/empty.c');assert.equal(empty.size,0);assert.equal(empty.csize,0);assert.equal(empty.enc,undefined);assert.deepEqual(object(out1,empty,one.manifest),Buffer.alloc(0));
});
