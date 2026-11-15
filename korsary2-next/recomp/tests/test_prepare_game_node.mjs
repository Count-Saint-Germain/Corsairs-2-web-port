#!/usr/bin/env node
/** Node migration regression tests; all game files here are synthetic fixtures. */
import { test, before, after } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { main, oggToWavBytes } from '../../tools/prepare_game.mjs';
import { listFiles, listingFingerprint, sha256File } from '../../tools/prepare_game_core.mjs';

const DIR = path.dirname(fileURLToPath(import.meta.url)), AUDIO = path.join(DIR,'fixtures','prepare-game-audio');
const command = (name) => { const r=spawnSync(name,['-version'],{encoding:'utf8'}); return r.status===0 ? name : null; };
const ffmpeg=command('ffmpeg'), ffprobe=command('ffprobe'), hasAudio=Boolean(ffmpeg && ffprobe);
const has7z=['7zz','7z','7za','7zr'].find((name)=>spawnSync(name,[],{stdio:'ignore'}).status!==null);
let root,repack,work,patches,music,manifest;
function write(base,rel,data) { const file=path.join(base,rel); fs.mkdirSync(path.dirname(file),{recursive:true}); fs.writeFileSync(file,data); }
function read(base,rel) { return fs.readFileSync(path.join(base,rel)); }
function patch(rel,before,after,line) {
  const hash=(b)=>importHash(b);
  return `# path: ${rel}\n# sha256-before: ${hash(before)}\n# sha256-after: ${hash(after)}\n# eol-before: crlf\n# eol-after: crlf\n# final-newline: yes\n--- a/${rel}\n+++ b/${rel}\n@@ -${line} +${line} @@\n-x=1\n+x=2\n`;
}
import crypto from 'node:crypto';
const importHash=(b)=>crypto.createHash('sha256').update(b).digest('hex');
function run(out,...extra) { return main(['--repack',repack,'--out',out,'--patches-dir',patches,'--music-from',music,'--no-clone',...extra]); }
function child(t) { const p=fs.mkdtempSync(path.join(os.tmpdir(),'k2-game-out-')); t.after(()=>fs.rmSync(p,{recursive:true,force:true})); return path.join(p,'out'); }
function snapshot(dir) {
 const out={};
 function walk(base) { for(const e of fs.readdirSync(base,{withFileTypes:true})) { const p=path.join(base,e.name), rel=path.relative(dir,p); if(e.isDirectory()){out[rel+'/']='dir';walk(p);}else out[rel]=sha256File(p); } }
 walk(dir); return out;
}
before(async()=>{
 root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-game-fixture-')); repack=path.join(root,'repack');work=path.join(root,'work');patches=path.join(root,'patches');music=path.join(root,'music');
 const src={
  'ENGINE.exe':Buffer.from('MZ-engine'),'engine.dll':Buffer.from('synthetic protected 1'),'data1.dat':Buffer.from('synthetic protected 2'),
  'engine.ini':Buffer.from('[engine]\r\n'),'options':Buffer.from('[opts]\r\n'),'setup-1.bin':Buffer.from('placeholder archive'),
  'PROGRAM/Dialog.c':Buffer.from([47,47,32,0xcf,0xf0,0xe8,0xe2,0xe5,0xf2,13,10,120,61,49,13,10]),
  'PROGRAM/Untouched.c':Buffer.from('untouched\r\n'),
  'RESOURCE/MODELS/Ammo/blade1.gm':Buffer.from('ammo1'),'RESOURCE/MODELS/Ammo/blade2.gm':Buffer.from('ammo2'),
  'RESOURCE/MODELS/Items/blade1.gm':Buffer.from('existing1'),
  'RESOURCE/Textures/Ammo/blade6.tga.tx':Buffer.from('texture6'),'RESOURCE/Textures/Items/existing.tx':Buffer.from('existing-texture'),
  'RESOURCE/MODELS/Heads/h_Offic_eng.gm':Buffer.from('head'),
  'RESOURCE/animation/Heads/h_Offic_eng.ani':Buffer.from('animation = Heads\\AN\\h_Offic_eng.an\r\n'),
  'RESOURCE/Sounds/dsstdfx.bin':Buffer.from('binary'),'SAVE/.keep':Buffer.alloc(0),
 };
 for(const [rel,data] of Object.entries(src))write(repack,rel,data);
 const audio=[['VOICE/RUSSIAN/v1.ogg','voice-v1.ogg'],['VOICE/RUSSIAN/V2.ogg','voice-v2.ogg'],['AMBIENT/CAVE/drop.ogg','effect-drop.ogg'],['trep/t.ogg','effect-t.ogg']];
 for(const [rel,name] of audio)write(repack,`RESOURCE/Sounds/${rel}`,read(AUDIO,name));
 write(music,'RESOURCE/Sounds/MUSIC/Coridor.ogg',Buffer.from('synthetic-music-1'));
 write(music,'RESOURCE/Sounds/MUSIC/Main_theme.ogg',Buffer.from('synthetic-music-2'));
 fs.cpSync(repack,work,{recursive:true}); fs.rmSync(path.join(work,'engine.dll'));fs.rmSync(path.join(work,'data1.dat'));
 const before=read(work,'PROGRAM/Dialog.c'), after=Buffer.from(before); after[after.length-3]=50;
 write(work,'PROGRAM/Dialog.c',after);
 fs.mkdirSync(patches); write(patches,'01.patch',patch('PROGRAM/Dialog.c',before,after,2));
 for(const [srcRel,dstRel] of [
  ['RESOURCE/MODELS/Ammo/blade2.gm','RESOURCE/MODELS/Items/blade2.gm'],
  ['RESOURCE/Textures/Ammo/blade6.tga.tx','RESOURCE/Textures/Items/Blade6.tga.tx'],
  ['RESOURCE/MODELS/Heads/h_Offic_eng.gm','RESOURCE/MODELS/Heads/h_Offic_hol.gm'],
  ['RESOURCE/animation/Heads/h_Offic_eng.ani','RESOURCE/animation/Heads/h_Offic_hol.ani']])write(work,dstRel,read(repack,srcRel));
 for(const name of ['Coridor.ogg','Main_theme.ogg'])write(work,`RESOURCE/Sounds/MUSIC/${name}`,read(music,`RESOURCE/Sounds/MUSIC/${name}`));
 if(hasAudio) for(const [rel] of audio) {
  const source=path.join(repack,'RESOURCE/Sounds',rel), wav=await oggToWavBytes(ffmpeg,ffprobe,source), target=`RESOURCE/Sounds/${rel.slice(0,-4)}.wav`;
  write(work,target,wav); if(rel.startsWith('VOICE/RUSSIAN/'))write(work,`RESOURCE/Sounds/VOICE/${path.basename(rel,'.ogg')}.wav`,wav);
 }
 const rl=listFiles(repack), wl=listFiles(work), original=Object.fromEntries(Object.entries(rl).filter(([n])=>!['engine.dll','data1.dat'].includes(n.toLowerCase())));
 const modified=[{path:'PROGRAM/Dialog.c',size_before:before.length,size_after:after.length,sha256_before:importHash(before),sha256_after:importHash(after)}];
 const added=Object.keys(wl).filter((n)=>!(n in rl)).sort().map((n)=>({path:n,size:wl[n],sha256:sha256File(path.join(work,n)),kind:n.startsWith('RESOURCE/Sounds/MUSIC/')?'music':n.endsWith('.wav')?'wav':n.includes('/Models/Items/')?'items_model':'content_fix'}));
 manifest={format:1,source:{repack_listing_sha256:listingFingerprint(rl)},tooling:{ffmpeg_version_line:hasAudio?spawnSync(ffmpeg,['-version'],{encoding:'utf8'}).stdout.split('\n')[0]:''},counts:{repack_files:Object.keys(rl).length,protected_files_excluded:2,added_total:added.length},modified,added};
 write(patches,'expected-manifest.json',JSON.stringify(manifest));
});
after(()=>fs.rmSync(root,{recursive:true,force:true}));

test('full preparation reproduces expected synthetic game and deep SHA', {skip:!hasAudio}, async(t)=>{
 const out=child(t); assert.equal(await run(out,'--deep'),0); assert.deepEqual(snapshot(out),snapshot(work));
 const wav=read(out,'RESOURCE/Sounds/VOICE/RUSSIAN/v1.wav'); assert.equal(wav.subarray(0,4).toString(),'RIFF'); assert.equal(wav.subarray(8,12).toString(),'WAVE'); assert.equal(wav.subarray(36,40).toString(),'data');
 const pcm=spawnSync(ffmpeg,['-v','error','-nostdin','-i',path.join(repack,'RESOURCE/Sounds/VOICE/RUSSIAN/v1.ogg'),'-map','0:a:0','-c:a','pcm_s16le','-f','s16le','-'],{maxBuffer:16*1024*1024}); assert.equal(pcm.status,0);assert.deepEqual(wav.subarray(44),pcm.stdout);
});
test('force rerun is idempotent; existing data is preserved',{skip:!hasAudio},async(t)=>{
 const out=child(t);assert.equal(await run(out),0);const saved=snapshot(out);assert.equal(await run(out,'--force'),0);assert.deepEqual(snapshot(out),saved);
});
test('refuses nonempty output, file output, repack overlap and out inside repack',async(t)=>{
 const out=child(t);fs.mkdirSync(out);write(out,'user','keep');assert.equal(await run(out),1);assert.equal(read(out,'user').toString(),'keep');
 const f=path.join(path.dirname(out),'file');fs.writeFileSync(f,'keep');assert.equal(await run(f),1);
 assert.equal(await run(repack),1);assert.equal(await run(path.join(repack,'nested')),1);
});
test('dry-run does not write; protected files are excluded; skip-wav warns',async(t)=>{
 const out=child(t);assert.equal(await run(out,'--dry-run'),0);assert.equal(fs.existsSync(out),false);
 assert.equal(await run(out,'--skip-wav'),0);assert.equal(fs.existsSync(path.join(out,'engine.dll')),false);assert.equal(fs.existsSync(path.join(out,'data1.dat')),false);assert.equal(fs.existsSync(path.join(out,'RESOURCE/Sounds/VOICE/v1.wav')),false);
});
test('check mode detects missing, extra, modified and deep changes without writing',{skip:!hasAudio},async(t)=>{
 const out=child(t);assert.equal(await run(out),0);assert.equal(await run(out,'--check','--deep'),0);
 const script=path.join(out,'PROGRAM/Dialog.c'), before=fs.readFileSync(script);fs.writeFileSync(script,'broken');assert.equal(await run(out,'--check'),3);fs.writeFileSync(script,before);
 const untouched=path.join(out,'PROGRAM/Untouched.c'), original=fs.readFileSync(untouched);fs.writeFileSync(untouched,Buffer.alloc(original.length,33));assert.equal(await run(out,'--check','--deep'),3);fs.writeFileSync(untouched,original);
 fs.rmSync(path.join(out,'ENGINE.exe'));assert.equal(await run(out,'--check'),3);write(out,'ENGINE.exe',read(repack,'ENGINE.exe'));write(out,'unexpected','x');assert.equal(await run(out,'--check'),3);
});
test('preflight checks space and does not modify original repack',async(t)=>{
 const out=child(t), before=snapshot(repack);assert.equal(await run(out,'--min-free-mb','999999999'),1);assert.equal(fs.existsSync(out),false);assert.deepEqual(snapshot(repack),before);
});
test('bad patch hash and dangerous symlink are rejected',async(t)=>{
 const out=child(t), custom=path.join(path.dirname(out),'patches');fs.cpSync(patches,custom,{recursive:true});
 const p=path.join(custom,'01.patch');fs.writeFileSync(p,fs.readFileSync(p,'utf8').replace(/sha256-before: [0-9a-f]{64}/u,`sha256-before: ${'0'.repeat(64)}`));
 assert.equal(await main(['--repack',repack,'--out',out,'--patches-dir',custom,'--music-from',music,'--no-clone','--skip-wav']),1);
 assert.deepEqual(read(out,'PROGRAM/Dialog.c'),read(repack,'PROGRAM/Dialog.c'));
 const evil=child(t), outside=path.join(path.dirname(evil),'outside');fs.mkdirSync(evil);fs.mkdirSync(outside);fs.symlinkSync(outside,path.join(evil,'RESOURCE'));
 assert.equal(await run(evil,'--force','--skip-wav'),1);assert.deepEqual(fs.readdirSync(outside),[]);
});
test('music hash, missing and extra are rejected before music is written',async(t)=>{
 const out=child(t), bad=path.join(path.dirname(out),'bad');fs.cpSync(music,bad,{recursive:true});write(bad,'RESOURCE/Sounds/MUSIC/extra.ogg','x');
 assert.equal(await main(['--repack',repack,'--out',out,'--patches-dir',patches,'--music-from',bad,'--no-clone','--skip-wav']),1);
 assert.equal(fs.existsSync(path.join(out,'RESOURCE/Sounds/MUSIC/Coridor.ogg')),false);
});

test('accepts an existing empty output; protects originals and emits a report',async(t)=>{
 const out=child(t), report=path.join(path.dirname(out),'report.json'), original=snapshot(repack);fs.mkdirSync(out);
 assert.equal(await run(out,'--skip-wav','--report',report),0);assert.deepEqual(snapshot(repack),original);
 const info=JSON.parse(fs.readFileSync(report,'utf8'));assert.equal(info.errors.length,0);assert.ok(info.steps.clone);assert.ok(info.steps.patches);
});
test('modified existing item is preserved and verification reports mismatch',async(t)=>{
 const out=child(t);assert.equal(await run(out,'--skip-wav'),0);
 const file=path.join(out,'RESOURCE/MODELS/Items/blade2.gm');fs.writeFileSync(file,'my edit');
 assert.equal(await run(out,'--skip-wav','--force'),3);assert.equal(fs.readFileSync(file,'utf8'),'my edit');
});
test('modified existing WAV is preserved and verification reports mismatch',{skip:!hasAudio},async(t)=>{
 const out=child(t);assert.equal(await run(out),0);const file=path.join(out,'RESOURCE/Sounds/trep/t.wav');fs.writeFileSync(file,'my sound');
 assert.equal(await run(out,'--force'),3);assert.equal(fs.readFileSync(file,'utf8'),'my sound');
});
test('flat music source works; bad and missing music fail before any music output',async(t)=>{
 const base=path.dirname(child(t)), source=path.join(music,'RESOURCE/Sounds/MUSIC'), flat=path.join(base,'flat');fs.cpSync(source,flat,{recursive:true});
 const out=path.join(base,'flat-out');assert.equal(await run(out,'--skip-wav','--music-from',flat),0);
 for(const issue of ['bad','missing']) {
  const bad=path.join(base,issue);fs.cpSync(source,bad,{recursive:true});
  if(issue==='bad')fs.writeFileSync(path.join(bad,'Coridor.ogg'),'corrupt');else fs.unlinkSync(path.join(bad,'Coridor.ogg'));
  const target=path.join(base,`${issue}-out`);assert.equal(await run(target,'--skip-wav','--music-from',bad),1);
  assert.equal(fs.existsSync(path.join(target,'RESOURCE/Sounds/MUSIC/Coridor.ogg')),false);
 }
});
test('extracts MUSIC from an actual 7z archive and removes scratch data',{skip:!has7z},async(t)=>{
 const out=child(t), base=path.dirname(out), copy=path.join(base,'repack');fs.cpSync(repack,copy,{recursive:true});
 fs.rmSync(path.join(copy,'setup-1.bin'));
 const r=spawnSync(has7z,['a','-t7z','-mx=0','-bd',path.join(copy,'setup-1.bin'),'RESOURCE/Sounds/MUSIC'],{cwd:music,encoding:'utf8'});
 assert.equal(r.status,0,r.stderr);
 assert.equal(await main(['--repack',copy,'--out',out,'--patches-dir',patches,'--no-clone','--skip-wav']),0);
 assert.deepEqual(read(out,'RESOURCE/Sounds/MUSIC/Coridor.ogg'),read(music,'RESOURCE/Sounds/MUSIC/Coridor.ogg'));
 assert.equal(fs.readdirSync(base).some((n)=>n.startsWith('.prepare-music-')),false);
});
test('rejects output symlink and protected working-game paths',async(t)=>{
 const out=child(t), base=path.dirname(out), external=path.join(base,'external');fs.mkdirSync(external);fs.symlinkSync(external,out);
 assert.equal(await run(out,'--skip-wav'),1);assert.deepEqual(fs.readdirSync(external),[]);
 const actual=path.resolve(DIR,'../../..','korsary2-work/game');
 assert.equal(await run(path.join(actual,'must-not-create'),'--skip-wav'),1);assert.equal(fs.existsSync(path.join(actual,'must-not-create')),false);
});
test('cloned and copied modes produce the same data',async(t)=>{
 const a=child(t), b=child(t);assert.equal(await run(a,'--skip-wav'),0);
 assert.equal(await main(['--repack',repack,'--out',b,'--patches-dir',patches,'--music-from',music,'--skip-wav']),0);
 assert.deepEqual(snapshot(a),snapshot(b));
});
