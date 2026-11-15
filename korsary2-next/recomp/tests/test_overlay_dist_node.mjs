import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import {createHash} from 'node:crypto';
import {buildFixture} from './overlay_fixture.mjs';
import {buildDistribution} from '../web/make_dist.mjs';
import {checkOverlay,checkOverlayExpected,canonicalOverlayJson,readOverlayRequired} from './verify_dist_overlay.mjs';
import {manifestVersion} from './verify_dist_core.mjs';
const sha=b=>createHash('sha256').update(b).digest('hex');
function temp(t){const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-overlay-node-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));return dir;}
function read(file){return JSON.parse(fs.readFileSync(file,'utf8'));}
function write(file,object){fs.writeFileSync(file,JSON.stringify(object));}
const required=read('korsary2-next/recomp/web/overlay-required.json').required;
function verify(dist){return checkOverlay(dist,{required,fullHash:true,mustExist:true});}

test('synthetic overlay is built and independently verified in all four layouts',async t=>{
 const root=temp(t),versions=[];
 for(const layout of ['plain','d1','pack','brpack']){const f=await buildFixture(path.join(root,layout),{layout}),game=read(path.join(f.dist,'game/manifest.json')),m=read(path.join(f.dist,'game-en/manifest.json')),b=verify(f.dist);assert.ok(b.passed,b.failures().join('\n'));assert.equal(m.overlay.language,'English');assert.equal(m.overlay.format,1);assert.ok(Object.keys(m.overlay.base).length);assert.equal(m.version,manifestVersion(m.files));versions.push(m.version);
  const sourceFiles=fs.readdirSync(f.overlay_src,{recursive:true}).filter(p=>fs.statSync(path.join(f.overlay_src,p)).isFile()&&p!=='OVERLAY.json').sort();assert.deepEqual(m.files.map(e=>e.path).sort(),sourceFiles);
  for(const e of m.files){const data=fs.readFileSync(path.join(f.overlay_src,e.path));assert.equal(e.size,data.length);assert.equal(e.sha256,sha(data));}
  if(layout==='plain')assert.ok(m.files.every(e=>!e.enc&&e.pack===undefined));if(layout==='d1'){assert.ok(m.files.some(e=>e.enc==='gzip'));assert.ok(!m.packs);}if(layout==='pack'||layout==='brpack')assert.ok(m.packs?.length);if(layout==='brpack')assert.ok(m.files.some(e=>e.enc==='br'));assert.ok(!game.overlay);
 }
 assert.equal(new Set(versions).size,1);
});

test('invalid overlay inputs are rejected before output is created',async t=>{
 const root=temp(t),f=await buildFixture(path.join(root,'source')),game=f.game_src,overlay=f.overlay_src,buildDir=path.join(root,'source/fake-build'),out=path.join(root,'invalid-output'),base={game,out,buildDir,overlayDir:overlay,videos:path.join(root,'no-videos')};
 for(const rel of ['SAVE/slot','save/slot','SAVE_META/x','SAVE_TX/x','options','engine.ini','ENGINE.exe','MODULES/x.dll','README.txt','Other/x','RESOURCE/.hidden','RESOURCE/CON.txt','RESOURCE/Thumbs.db','RESOURCE/a:b','RESOURCE/bad*name','RESOURCE/trailing.']){const file=path.join(overlay,rel);fs.mkdirSync(path.dirname(file),{recursive:true});fs.writeFileSync(file,'x');await assert.rejects(buildDistribution(base),undefined,rel);assert.equal(fs.existsSync(out),false,rel);fs.rmSync(file);const first=rel.split('/')[0];if(!['PROGRAM','RESOURCE'].includes(first)&&fs.existsSync(path.join(overlay,first)))fs.rmSync(path.join(overlay,first),{recursive:true,force:true});}
 const link=path.join(overlay,'RESOURCE/link');fs.symlinkSync(path.join(game,'engine.ini'),link);await assert.rejects(buildDistribution(base));assert.equal(fs.existsSync(out),false);fs.unlinkSync(link);
 const metaFile=path.join(overlay,'OVERLAY.json'),original=fs.readFileSync(metaFile,'utf8');for(const mutate of [m=>{m.format=2;},m=>{m.base=[];},m=>{m.base['RESOURCE/nope']='0'.repeat(64);},m=>{m.base['RESOURCE/INI/fonts.ini']='invalid';},m=>{m.base['RESOURCE/INI/fonts.ini']='1'.repeat(64);}]){const meta=JSON.parse(original);mutate(meta);write(metaFile,meta);await assert.rejects(buildDistribution(base));assert.equal(fs.existsSync(out),false);}fs.writeFileSync(metaFile,original);
 await assert.rejects(buildDistribution({...base,out:path.join(overlay,'dist')}),/contain/);await assert.rejects(buildDistribution({...base,overlayName:'EN'}),/overlay-name/);
});

test('overlay verifier catches malformed manifests, base changes and damaged objects',async t=>{
 const root=temp(t),f=await buildFixture(path.join(root,'source')),manifestPath=path.join(f.dist,'game-en/manifest.json'),original=fs.readFileSync(manifestPath,'utf8'),basePath=path.join(f.dist,'game/manifest.json'),baseOriginal=fs.readFileSync(basePath,'utf8');assert.ok(verify(f.dist).passed);
 const cases=[m=>m.files.push({path:'SAVE/x',size:1,sha256:'0'.repeat(64)}),m=>m.files.push({path:'MODULES/x',size:1,sha256:'0'.repeat(64)}),m=>m.files.push({path:'RESOURCE/../x',size:1,sha256:'0'.repeat(64)}),m=>{delete m.files[0].sha256;},m=>{m.files[0].sha256='z'.repeat(64);},m=>m.files.push({...m.files[0]}),m=>m.files.push({...m.files[0],path:m.files[0].path.toLowerCase()}),m=>{m.files=m.files.filter(e=>e.path!=='RESOURCE/INI/TEXTS/language.ini');},m=>{m.overlay.format=2;},m=>{m.overlay.base['RESOURCE/INI/fonts.ini']='2'.repeat(64);},m=>{m.overlay.base['RESOURCE/nope']='2'.repeat(64);},m=>{m.version='deadbeef0000';}];
 for(const mutate of cases){const m=JSON.parse(original);mutate(m);write(manifestPath,m);assert.equal(verify(f.dist).passed,false,mutate.toString());}fs.writeFileSync(manifestPath,original);
 const gm=JSON.parse(baseOriginal);gm.overlay={format:1};write(basePath,gm);assert.equal(verify(f.dist).passed,false);fs.writeFileSync(basePath,baseOriginal);const gm2=JSON.parse(baseOriginal);gm2.files.find(e=>e.path==='RESOURCE/INI/fonts.ini').sha256='9'.repeat(64);write(basePath,gm2);assert.equal(verify(f.dist).passed,false);fs.writeFileSync(basePath,baseOriginal);
 const m=JSON.parse(original),pack=path.join(f.dist,'game-en',m.packs[0].path),bytes=fs.readFileSync(pack),damaged=Buffer.from(bytes);damaged[Math.floor(damaged.length/2)]^=1;fs.writeFileSync(pack,damaged);assert.equal(verify(f.dist).passed,false);fs.writeFileSync(pack,bytes);
 const extra=path.join(f.dist,'game-en/extra.bin');fs.writeFileSync(extra,'x');assert.equal(verify(f.dist).passed,false);fs.unlinkSync(extra);fs.symlinkSync('/etc/hosts',extra);assert.equal(verify(f.dist).passed,false);fs.unlinkSync(extra);
 fs.rmSync(path.join(f.dist,'game-en'),{recursive:true});assert.equal(checkOverlay(f.dist,{required,mustExist:true}).passed,false);assert.ok(checkOverlay(f.dist,{required,mustExist:false}).passed);
});

test('required overlay list rejects malformed and duplicate data',t=>{
 const root=temp(t),p=path.join(root,'required.json');for(const bad of ['not json','{}','{"format":2,"required":["PROGRAM/a"]}','{"format":1,"required":[]}','{"format":1,"required":["PROGRAM/a","program/A"]}','{"format":1,"required":[1]}','{"format":1,"required":["PROGRAM/a"],"recommended":"x"}']){fs.writeFileSync(p,bad);assert.throws(()=>readOverlayRequired(p),undefined,bad);}
});

test('expected overlay reference checks inventory, metadata, classes, base and video',async t=>{
 const root=temp(t),f=await buildFixture(path.join(root,'source')),manifest=read(path.join(f.dist,'game-en/manifest.json')),meta=canonicalOverlayJson(manifest.overlay),files=manifest.files.map(e=>({path:e.path,size:e.size,sha256:e.sha256,cls:e.path.startsWith('RESOURCE/Sounds/VOICE/')?'voice':'align',...(manifest.overlay.base[e.path]?{base_sha256:manifest.overlay.base[e.path]}:{})})),voice=files.filter(e=>e.cls==='voice'),voiceBytes=voice.reduce((n,e)=>n+e.size,0),replaced=voice.filter(e=>e.base_sha256).length;
 files.push({path:'OVERLAY.json',size:meta.length,sha256:sha(meta),cls:'meta'});const ref={format:1,files,totals:{by_class:{align:{files:files.filter(e=>e.cls==='align').length},voice:{files:voice.length}},bytes_by_class:{voice:voiceBytes}},resources:{voice:{selected:voice.length,selected_bytes:voiceBytes,replaced,added:voice.length-replaced}}},p=path.join(root,'reference.json');write(p,ref);let b=checkOverlayExpected(f.dist,p);assert.ok(b.passed,b.failures().join('\n'));
 const cases=[x=>x.files.push({path:'PROGRAM/not-in-dist.h',size:1,sha256:'0'.repeat(64),cls:'align'}),x=>x.files.splice(0,1),x=>{x.files[0].sha256='1'.repeat(64);},x=>{x.files[0].size++;},x=>{x.resources.voice.replaced++;},x=>{x.totals.bytes_by_class.voice++;},x=>{x.totals.by_class.loading={files:3};},x=>{x.files.find(e=>e.cls==='meta').sha256='2'.repeat(64);},x=>{x.files.find(e=>e.base_sha256).base_sha256='3'.repeat(64);},x=>{x.files.find(e=>e.cls==='voice').cls='loading';},x=>{x.format=2;}];
 for(const mutate of cases){const item=structuredClone(ref);mutate(item);write(p,item);assert.equal(checkOverlayExpected(f.dist,p).passed,false,mutate.toString());}
 const withVideo=structuredClone(ref);withVideo.resources.video={path:'English/Invasion.mp4',size:12,sha256:'4'.repeat(64)};write(p,withVideo);assert.equal(checkOverlayExpected(f.dist,p).passed,false);const target=path.join(f.dist,'videos/English/Invasion.mp4');fs.mkdirSync(path.dirname(target),{recursive:true});fs.writeFileSync(target,Buffer.alloc(12,120));b=checkOverlayExpected(f.dist,p);assert.ok(b.passed);assert.ok(b.warnings.length);withVideo.resources.video.sha256=sha(Buffer.alloc(12,120));write(p,withVideo);assert.ok(checkOverlayExpected(f.dist,p).passed);
});

test('overlay options control required checks and language directory without changing base build',async t=>{
 const root=temp(t),a=await buildFixture(path.join(root,'a'),{overlay:false}),b=await buildFixture(path.join(root,'b')),c=await buildFixture(path.join(root,'c'),{overlayName:'de'});assert.ok(fs.existsSync(path.join(c.dist,'game-de/manifest.json')));assert.ok(!fs.existsSync(path.join(c.dist,'game-en')));
 const files=dir=>fs.readdirSync(dir,{recursive:true}).filter(p=>fs.statSync(path.join(dir,p)).isFile()&&!p.startsWith('game-en/')).sort();assert.deepEqual(files(a.dist),files(b.dist));for(const p of files(a.dist))assert.deepEqual(fs.readFileSync(path.join(a.dist,p)),fs.readFileSync(path.join(b.dist,p)),p);
 const metaPath=path.join(b.overlay_src,'OVERLAY.json'),meta=read(metaPath),removed=required[0];fs.unlinkSync(path.join(b.overlay_src,removed));delete meta.base[removed];write(metaPath,meta);const args={game:b.game_src,buildDir:path.join(root,'b/fake-build'),videos:path.join(root,'no-videos'),overlayDir:b.overlay_src};await assert.rejects(buildDistribution({...args,out:path.join(root,'required-fail')}),/required/);await buildDistribution({...args,out:path.join(root,'required-skip'),overlayNoRequiredCheck:true});
 meta.base['RESOURCE/INI/fonts.ini']='1'.repeat(64);write(metaPath,meta);await assert.rejects(buildDistribution({...args,out:path.join(root,'base-fail'),overlayNoRequiredCheck:true}),/another Russian/);await buildDistribution({...args,out:path.join(root,'base-skip'),overlayNoRequiredCheck:true,overlaySkipBaseCheck:true});
});

test('overlay upload verifies objects and sends both manifests after immutable packs',async t=>{
 const {run}=await import('../web/cloudflare/upload.mjs'),root=temp(t),f=await buildFixture(path.join(root,'fixture')),objects=new Map(),puts=[];
 const transport=async(base,token,key,{method='GET',query={},body,headers={}}={})=>{if(query.head){if(!objects.has(key)){const e=new Error('missing');e.status=404;throw e;}return objects.get(key);}if(method==='PUT'){const obj={size:body.length,sha256:headers['X-Content-SHA256']??null};objects.set(key,obj);puts.push(key);return obj;}throw new Error('unexpected upload');};
 const upload=()=>run('https://worker.invalid','token',f.dist,{transport,out:()=>{}}),[sent]=await upload();assert.deepEqual(sent.slice(-2).sort(),['game-en/manifest.json','game/manifest.json']);assert.ok(sent.some(k=>k.startsWith('game-en/_k2pack/')));
 const [sentAgain,skipped]=await upload();assert.ok(skipped.some(k=>k.startsWith('game-en/_k2pack/')));assert.ok(sentAgain.includes('game-en/manifest.json'));assert.ok(!sentAgain.some(k=>k.startsWith('game-en/_k2pack/')));
 const manifest=read(path.join(f.dist,'game-en/manifest.json'));fs.unlinkSync(path.join(f.dist,'game-en',manifest.packs[0].path));const before=puts.length;await assert.rejects(upload(),/nothing was uploaded/);assert.equal(puts.length,before);
});

test('overlay page list and English video targets remain enforced',async t=>{
 const root=temp(t),f=await buildFixture(path.join(root,'fixture')),list=path.join(f.dist,'overlay-required.json'),raw=fs.readFileSync(list),short=JSON.parse(raw);short.required=short.required.slice(0,2);write(list,short);assert.equal(verify(f.dist).passed,false);fs.unlinkSync(list);assert.equal(verify(f.dist).passed,false);fs.writeFileSync(list,raw);
 assert.ok(verify(f.dist).passed);const videos=path.join(f.dist,'videos/English');fs.mkdirSync(videos,{recursive:true});assert.equal(verify(f.dist).passed,false);fs.writeFileSync(path.join(videos,'Invasion.mp4'),'video');assert.ok(verify(f.dist).passed);
});
