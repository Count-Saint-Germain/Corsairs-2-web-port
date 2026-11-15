import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import {createHash} from 'node:crypto';
import {spawnSync} from 'node:child_process';
import {buildFixture} from './overlay_fixture.mjs';
import {verify} from './verify_dist.mjs';
import {checkStructure,checkPageModules,checkBuild,checkVideos,checkFreshness,checkSourceGame,checkStability} from './verify_dist_checks.mjs';
import {checkManifest} from './verify_dist_manifest.mjs';
import {scanTree,fingerprint,manifestVersion} from './verify_dist_core.mjs';
const sha=b=>createHash('sha256').update(b).digest('hex');
function temp(t){const d=fs.mkdtempSync(path.join(os.tmpdir(),'k2-verify-integration-'));t.after(()=>fs.rmSync(d,{recursive:true,force:true}));return d;}
async function fixture(t){const root=temp(t),f=await buildFixture(path.join(root,'fixture'),{layout:'plain',overlay:false}),source=fs.readFileSync(path.join(f.dist,'video-player.mjs'),'utf8'),block=/VIDEO_FILES\s*=\s*\{([^}]*)\}/.exec(source)[1];for(const m of block.matchAll(/["'](videos\/[^"']+)["']/g)){const p=path.join(f.dist,m[1]);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,Buffer.from([0,0,0,8,102,116,121,112]));}return {...f,root};}
function readManifest(dist){return JSON.parse(fs.readFileSync(path.join(dist,'game/manifest.json'),'utf8'));}
function saveManifest(dist,m){m.version=manifestVersion(m.files);fs.writeFileSync(path.join(dist,'game/manifest.json'),JSON.stringify(m));}
function put(dist,rel,data,listed=true){const p=path.join(dist,'game',rel);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,data);if(listed){const m=readManifest(dist);m.files.push({path:rel,size:Buffer.byteLength(data),sha256:sha(data)});saveManifest(dist,m);}}
const clone=(f,name)=>{const dest=path.join(f.root,name);fs.cpSync(f.dist,dest,{recursive:true});return dest;};
const run=dist=>verify(dist,{videosWeb:null,webSrc:null,fullHash:true});

test('independent verifier accepts clean fixture and rejects page, header and player-data failures',async t=>{
 const f=await fixture(t),clean=run(f.dist);assert.ok(clean.ok,clean.blocks.flatMap(b=>b.failures()).join('\n'));
 const cases=[
  ['missing inline import',d=>fs.unlinkSync(path.join(d,'save-import.mjs')),'page-modules'],
  ['missing transitive import',d=>fs.writeFileSync(path.join(d,'save-import.mjs'),"import './missing-dependency.mjs';"),'page-modules'],
  ['headers outside global rule',d=>fs.writeFileSync(path.join(d,'_headers'),'/videos/*\n  Cross-Origin-Opener-Policy: same-origin\n'),'structure'],
  ['duplicate matching header',d=>fs.appendFileSync(path.join(d,'_headers'),'\n/game/*\n  Cross-Origin-Embedder-Policy: require-corp\n'),'structure'],
  ['wrong isolation',d=>{const p=path.join(d,'_headers');fs.writeFileSync(p,fs.readFileSync(p,'utf8').replace('require-corp','credentialless'));},'structure'],
  ['missing no-cache',d=>{const p=path.join(d,'_headers');fs.writeFileSync(p,fs.readFileSync(p,'utf8').replace('  Cache-Control: no-cache\n',''));},'structure'],
  ['unexpected top-level player data',d=>{fs.mkdirSync(path.join(d,'SAVE'));fs.writeFileSync(path.join(d,'SAVE/slot'),'private');},'structure'],
  ['player data under game',d=>{fs.mkdirSync(path.join(d,'game/SAVE_meta'));fs.writeFileSync(path.join(d,'game/SAVE_meta/slot.time'),'private');},'structure'],
  ['symlink',d=>fs.symlinkSync('ENGINE.exe',path.join(d,'game/link')),'structure'],
  ['hard link',d=>fs.linkSync(path.join(d,'game/ENGINE.exe'),path.join(d,'game/alias')),'structure'],
 ];
 for(const [name,mutate,block] of cases){const d=clone(f,name.replaceAll(' ','-'));mutate(d);const result=run(d);assert.equal(result.ok,false,name);assert.equal(result.blocks.find(b=>b.name===block).passed,false,name);}
});

test('verification obeys exclusions, duplicate-audio and relocation rules',async t=>{
 const f=await fixture(t),rule={path:'RESOURCE/Sounds',extension:'.ogg',sibling_extension:'.wav',min_sibling_bytes:45},relocations=[{from:'RESOURCE/Textures/Loading/Russian',to:'RESOURCE/Textures/Loading'},{from:'RESOURCE/Textures/WorldMap/reload/Russian',to:'RESOURCE/Textures/WorldMap/reload'}];
 for(const name of ['RESOURCE/VIDEOS/Trailer.wmv','RESOURCE/VIDEOS/Russian/Invasion.wmv']){const d=clone(f,'wmv-'+name.length);put(d,name,'WMV');assert.equal(checkManifest(d).passed,false);assert.ok(checkManifest(d,{excluded:[]}).passed);}
 const allowed=clone(f,'allowed-prefix');put(allowed,'RESOURCE/VIDEOS2/x.dat','x');assert.ok(checkManifest(allowed).passed);
 const duplicate=clone(f,'duplicate');put(duplicate,'RESOURCE/Sounds/INTERFACE/_Abandon0.WAV','W'.repeat(100));put(duplicate,'RESOURCE/Sounds/INTERFACE/_abandon0.ogg','ogg');assert.equal(checkManifest(duplicate,{siblingRules:[rule]}).passed,false);assert.ok(checkManifest(duplicate,{siblingRules:[]}).passed);
 const harmless=clone(f,'unpaired');put(harmless,'RESOURCE/Sounds/MUSIC/theme.ogg','ogg');put(harmless,'RESOURCE/Sounds/trep/tiny.ogg','ogg');put(harmless,'RESOURCE/Sounds/trep/tiny.wav','W'.repeat(44));assert.ok(checkManifest(harmless,{siblingRules:[rule]}).passed);
 for(const [i,r] of relocations.entries()){const d=clone(f,'reloc-'+i);put(d,r.from+'/Sea.tga.tx','image');assert.equal(checkManifest(d,{relocateRules:relocations}).passed,false);assert.ok(checkManifest(d,{relocateRules:[]}).passed);put(d,r.to+'/SEA.TGA.TX','image');assert.ok(checkManifest(d,{relocateRules:relocations}).passed);}
});

test('source verification, freshness and stability detect changes while excluding player saves',async t=>{
 const f=await fixture(t),src=f.game_src;assert.ok(checkSourceGame(f.dist,src,true).passed);const secret=path.join(src,'SAVE/slot1');fs.chmodSync(path.dirname(secret),0);try{assert.ok(checkSourceGame(f.dist,src,true).passed);}finally{fs.chmodSync(path.dirname(secret),0o700);}
 const engine=path.join(src,'ENGINE.exe'),bytes=fs.readFileSync(engine);fs.writeFileSync(engine,'changed');assert.equal(checkSourceGame(f.dist,src,true).passed,false);fs.writeFileSync(engine,bytes);const same=Buffer.from(bytes);same[0]^=1;fs.writeFileSync(engine,same);assert.equal(checkSourceGame(f.dist,src,true).passed,false);fs.unlinkSync(engine);assert.equal(checkSourceGame(f.dist,src,true).passed,false);fs.writeFileSync(engine,bytes);
 const web=path.join(f.root,'web');fs.mkdirSync(web);for(const name of fs.readdirSync(f.dist))if(/\.(mjs|js|html)$/.test(name)&&fs.statSync(path.join(f.dist,name)).isFile())fs.copyFileSync(path.join(f.dist,name),path.join(web,name));assert.ok(checkFreshness(f.dist,web,path.join(f.root,'missing'),true).passed);fs.writeFileSync(path.join(web,'port.js'),'newer');const warn=checkFreshness(f.dist,web,path.join(f.root,'missing'),false);assert.ok(warn.passed);assert.ok(warn.warnings.length);assert.equal(checkFreshness(f.dist,web,path.join(f.root,'missing'),true).passed,false);
 const before=fingerprint(f.dist);fs.appendFileSync(path.join(f.dist,'game/ENGINE.exe'),'x');assert.equal(checkStability(before,fingerprint(f.dist)).passed,false);
});

test('video boxes, bridge exports and requested video names are checked',async t=>{
 const f=await fixture(t);assert.ok(checkVideos(f.dist).passed);assert.ok(checkBuild(f.dist).passed);
 const trailer=path.join(f.dist,'videos/Trailer.mp4'),original=fs.readFileSync(trailer);for(const bytes of [Buffer.alloc(0),Buffer.from('not mp4'),Buffer.concat([Buffer.from([0,0,0,8,102,116,121,112,0,0,0,8,109,100,97,116,0,0,0,8,109,111,111,118])])]){fs.writeFileSync(trailer,bytes);assert.equal(checkVideos(f.dist).passed,false);}fs.unlinkSync(trailer);assert.equal(checkVideos(f.dist).passed,false);fs.writeFileSync(trailer,original);
 const wasm=path.join(f.dist,'build/game.wasm'),wasmBytes=fs.readFileSync(wasm);fs.writeFileSync(wasm,Buffer.concat([Buffer.from([0,97,115,109,1,0,0,0]),Buffer.alloc(64)]));assert.equal(checkBuild(f.dist).passed,false);fs.writeFileSync(wasm,wasmBytes);const js=path.join(f.dist,'build/game.js');fs.writeFileSync(js,"var _port_video_poll = 1; var wasmBinaryFile = 'game.wasm';");assert.equal(checkBuild(f.dist).passed,false);
});

test('verifier selftest CLI executes its corruption checks',()=>{
 const p=spawnSync(process.execPath,['korsary2-next/recomp/tests/verify_dist.mjs','--selftest'],{encoding:'utf8'});assert.equal(p.status,0,p.stdout+'\n'+p.stderr);
});

test('sampling reports its limits and full hashing finds same-size corruption',async t=>{
 const f=await fixture(t),m=readManifest(f.dist);for(let i=0;i<120;i++){const name=`bulk${String(i).padStart(3,'0')}.dat`,data=String(i).padStart(4,'0').repeat(16);fs.writeFileSync(path.join(f.dist,'game',name),data);m.files.push({path:name,size:data.length,sha256:sha(data)});}saveManifest(f.dist,m);assert.ok(checkManifest(f.dist).passed);
 let blind=null;for(let i=0;i<120;i++){const p=path.join(f.dist,'game',`bulk${String(i).padStart(3,'0')}.dat`),original=fs.readFileSync(p),changed=Buffer.from(original);changed[0]^=1;fs.writeFileSync(p,changed);if(checkManifest(f.dist).passed){blind=p;break;}fs.writeFileSync(p,original);}
 assert.ok(blind,'some records are outside the sample');const sampled=checkManifest(f.dist);assert.ok(sampled.passed);assert.ok(sampled.warnings.some(w=>/hashed/.test(w)));assert.equal(checkManifest(f.dist,{fullHash:true}).passed,false);
});

test('source checks find relocated files at the original path',async t=>{
 const f=await fixture(t),rel='RESOURCE/Textures/Loading/Sea.tga.tx',old='RESOURCE/Textures/Loading/Russian/Sea.tga.tx',rules=[{from:'RESOURCE/Textures/Loading/Russian',to:'RESOURCE/Textures/Loading'}];put(f.dist,rel,'RU SEA');const source=path.join(f.game_src,old);fs.mkdirSync(path.dirname(source),{recursive:true});fs.writeFileSync(source,'RU SEA');assert.ok(checkSourceGame(f.dist,f.game_src,true,rules).passed);fs.writeFileSync(source,'wrong');assert.equal(checkSourceGame(f.dist,f.game_src,true,rules).passed,false);fs.unlinkSync(source);assert.equal(checkSourceGame(f.dist,f.game_src,true,rules).passed,false);
});

test('port configuration and safe defaults control verifier rules',async t=>{
 const f=await fixture(t),cfg=path.join(f.root,'port.json'),d=clone(f,'config-check'),runWith=p=>verify(d,{videosWeb:null,webSrc:null,portJson:p}).blocks.find(b=>b.name==='manifest');
 put(d,'RESOURCE/VIDEOS/Trailer.wmv','wmv');assert.equal(runWith(path.join(f.root,'missing.json')).passed,false);fs.writeFileSync(cfg,JSON.stringify({files:{required:[],exclude_paths:[],exclude_if_sibling:[],relocate_if_absent:[]}}));assert.ok(runWith(cfg).passed);fs.writeFileSync(cfg,JSON.stringify({files:{required:[]}}));assert.equal(runWith(cfg).passed,false);
 const clean=clone(f,'config-sibling');put(clean,'RESOURCE/Sounds/a.wav','W'.repeat(100));put(clean,'RESOURCE/Sounds/a.ogg','ogg');const check=p=>verify(clean,{videosWeb:null,webSrc:null,portJson:p}).blocks.find(b=>b.name==='manifest');assert.equal(check(path.join(f.root,'missing.json')).passed,false);fs.writeFileSync(cfg,JSON.stringify({files:{required:[],exclude_if_sibling:[],relocate_if_absent:[]}}));assert.ok(check(cfg).passed);
 const moved=clone(f,'config-relocate');put(moved,'RESOURCE/Textures/Loading/Russian/Sea.tga.tx','image');const testConfig=p=>verify(moved,{videosWeb:null,webSrc:null,portJson:p}).blocks.find(b=>b.name==='manifest');assert.equal(testConfig(path.join(f.root,'missing.json')).passed,false);assert.ok(testConfig(cfg).passed);
});
