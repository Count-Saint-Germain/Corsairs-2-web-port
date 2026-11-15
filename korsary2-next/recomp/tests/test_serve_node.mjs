import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import http from 'node:http';
import { once } from 'node:events';
import { createHash } from 'node:crypto';
import { createDevServer,checkedAsset,validateGameLayout } from '../web/serve.mjs';
import { gameFiles, manifestFor, unpackRecord } from '../web/gamefiles.mjs';
import { writeGame } from '../web/make_dist.mjs';
import { buildFixture } from './overlay_fixture.mjs';
function fixture(t){const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-node-serve-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));const game=path.join(root,'game'),web=path.join(root,'web'),build=path.join(root,'build'),videos=path.join(root,'videos'),overlay=path.join(root,'overlay');
 const put=(base,p,data)=>{const target=path.join(base,p);fs.mkdirSync(path.dirname(target),{recursive:true});fs.writeFileSync(target,data);return target;};
 for(const f of ['ENGINE.exe','engine.ini','options','PROGRAM/seadogs.c','PROGRAM/CONTROLS/controls.c','PROGRAM/CONTROLS/init_pc.c','MODULES/XINTERFACE.dll','MODULES/DX8RENDER.dll','MODULES/SOUND.dll','MODULES/PCS_CONTROLS.dll','RESOURCE/INI/TEXTS/language.ini'])put(game,f,`test ${f}`);
 put(game,'RESOURCE/large.c','abc123'.repeat(1000));put(game,'SAVE/secret','private');put(web,'index.html','page');put(web,'port.js','js');put(build,'game.wasm','wasm');put(videos,'Trailer.mp4','0123456789');
 put(overlay,'PROGRAM/seadogs.c','English');put(overlay,'OVERLAY.json',JSON.stringify({format:1,language:'English',base:{}}));return {root,game,web,build,videos,overlay,put};}
async function start(t,options){const result=await createDevServer(options);result.server.listen(0,'127.0.0.1');await once(result.server,'listening');t.after(async()=>{result.server.close();result.server.closeAllConnections();await once(result.server,'close');result.cleanup();});return {...result,url:`http://127.0.0.1:${result.server.address().port}`};}
async function get(url,rel,options={}){return new Promise((resolve,reject)=>{const u=new URL(url);const r=http.request({hostname:u.hostname,port:u.port,path:rel,...options},res=>{const chunks=[];res.on('data',c=>chunks.push(c));res.on('end',()=>resolve({status:res.statusCode,headers:res.headers,body:Buffer.concat(chunks)}));});r.on('error',reject);r.end();});}
test('raw dev serving, authentication, video ranges and isolation',async t=>{
 const f=fixture(t),s=await start(t,{...f,password:'secret'});let r=await get(s.url,'/');assert.equal(r.status,401);assert.match(r.headers['www-authenticate'],/Basic/);
 const headers={authorization:'Basic '+Buffer.from('user:secret').toString('base64')};r=await get(s.url,'/',{headers});assert.equal(r.status,200);assert.equal(r.body.toString(),'page');assert.equal(r.headers['cache-control'],'no-store');assert.equal(r.headers['cross-origin-embedder-policy'],'require-corp');
 r=await get(s.url,'/game/manifest.json',{headers});const m=JSON.parse(r.body);assert.ok(m.files.some(x=>x.path==='ENGINE.exe'));assert.ok(!m.files.some(x=>x.path.startsWith('SAVE/')));
 r=await get(s.url,'/game/SAVE/secret',{headers});assert.equal(r.status,404);
 r=await get(s.url,'/videos/Trailer.mp4',{headers:{...headers,range:'bytes=2-5'}});assert.equal(r.status,206);assert.equal(r.body.toString(),'2345');
 r=await get(s.url,'/%2e%2e/secret',{headers});assert.equal(r.status,404);
});
test('on-demand gzip serves manifest entries and restores source bytes',async t=>{
 const f=fixture(t),s=await start(t,{...f,compress:true});const m=JSON.parse((await get(s.url,'/game/manifest.json')).body),e=m.files.find(x=>x.path==='RESOURCE/large.c');assert.equal(e.enc,'gzip');
 const r=await get(s.url,'/game/RESOURCE/large.c.gz');assert.equal(r.status,200);const [plain,ok]=unpackRecord('gzip',r.body,e.size);assert.ok(ok);assert.equal(plain.toString(),'abc123'.repeat(1000));
});
test('pack requests are verified and source changes invalidate the layout',async t=>{
 const f=fixture(t),s=await start(t,{...f,pack:true}),m=JSON.parse((await get(s.url,'/game/manifest.json')).body);assert.ok(m.packs.length);
 const e=m.files.find(x=>x.path==='RESOURCE/large.c');assert.notEqual(e.pack,undefined);const packPath='/game/'+m.packs[e.pack].path;
 const [a,b]=await Promise.all([get(s.url,packPath),get(s.url,packPath)]);assert.equal(a.status,200);assert.deepEqual(a.body,b.body);
 const raw=a.body.subarray(e.offset,e.offset+e.csize),[plain,ok]=e.enc?unpackRecord(e.enc,raw,e.size):[raw,true];assert.ok(ok);assert.equal(plain.length,e.size);
 fs.writeFileSync(path.join(f.game,'RESOURCE/large.c'),'changed');assert.equal((await get(s.url,'/game/manifest.json')).status,409);assert.equal((await get(s.url,packPath)).status,404);
});
test('overlay manifests support HEAD and refuse replaced source files',async t=>{
 const f=fixture(t),s=await start(t,{...f,overlayDir:f.overlay,overlayNoRequiredCheck:true});let r=await get(s.url,'/game-en/manifest.json',{method:'HEAD'});assert.equal(r.status,200);assert.equal(r.body.length,0);
 r=await get(s.url,'/game-en/manifest.json');assert.equal(JSON.parse(r.body).overlay.language,'English');
 fs.unlinkSync(path.join(f.overlay,'PROGRAM/seadogs.c'));fs.symlinkSync(path.join(f.game,'engine.ini'),path.join(f.overlay,'PROGRAM/seadogs.c'));
 assert.equal((await get(s.url,'/game-en/manifest.json')).status,409);assert.equal((await get(s.url,'/game-en/PROGRAM/seadogs.c')).status,404);
});
test('root overlap and symlinks are rejected',async t=>{
 const f=fixture(t);assert.throws(()=>validateGameLayout(f.game,f.game,null,f.web,f.build),/overlaps/);
 await assert.rejects(createDevServer({...f,overlayDir:f.game,overlayNoRequiredCheck:true}),/overlay|PROGRAM|forbidden/i);
 assert.equal(checkedAsset(path.join(f.game,'../web/index.html'),f.game),null);
});

test('Brotli on-demand and packed routes preserve manifest content',async t=>{
 const f=fixture(t);
 for(const pack of [false,true]){
  const s=await start(t,{...f,compress:true,pack,codec:'br',quality:5});
  const m=JSON.parse((await get(s.url,'/game/manifest.json')).body),e=m.files.find(x=>x.path==='RESOURCE/large.c');
  const rel=e.pack===undefined?'/game/'+e.path+(e.enc==='br'?'.br':'.gz'):'/game/'+m.packs[e.pack].path;
  const res=await get(s.url,rel);assert.equal(res.status,200);
  const raw=e.pack===undefined?res.body:res.body.subarray(e.offset,e.offset+e.csize),[plain,ok]=e.enc?unpackRecord(e.enc,raw,e.size):[raw,true];
  assert.ok(ok);assert.equal(plain.toString(),'abc123'.repeat(1000));
 }
});

test('all HTTP methods reject path traversal and symlink leaks after inventory',async t=>{
 const f=fixture(t),outside=f.put(f.root,'outside/secret','PRIVATE');f.put(f.game,'SAVE_META/slot.time','PRIVATE');f.put(f.game,'SAVE_TX/journal','PRIVATE');
 const s=await start(t,{...f});fs.symlinkSync(outside,path.join(f.web,'leak'));fs.symlinkSync(outside,path.join(f.build,'leak'));
 const victim=path.join(f.game,'PROGRAM/seadogs.c');fs.unlinkSync(victim);fs.symlinkSync(outside,victim);
 for(const url of ['/%2e%2e/game/SAVE/secret','/build/%2e%2e/game/SAVE/secret','/game/SAVE/secret','/game/SAVE_META/slot.time','/game/SAVE_TX/journal','/leak','/build/leak','/game/PROGRAM/seadogs.c']){
  for(const [method,headers] of [['GET',{}],['HEAD',{}],['GET',{range:'bytes=0-3'}],['HEAD',{range:'bytes=0-3'}]]){const r=await get(s.url,url,{method,headers});assert.equal(r.status,404,`${method} ${url}`);assert.ok(!r.body.toString().includes('PRIVATE'));}
 }
 assert.equal((await get(s.url,'/game/manifest.json')).status,409);
});
test('video source excludes WMV, duplicate OGG, and relocates Russian loading textures',async t=>{
 const f=fixture(t);f.put(f.game,'RESOURCE/VIDEOS/private.wmv','movie');f.put(f.game,'RESOURCE/Sounds/PEOPLE/step.ogg','ogg');f.put(f.game,'RESOURCE/Sounds/PEOPLE/step.wav','W'.repeat(100));
 f.put(f.game,'RESOURCE/Textures/Loading/Russian/Sea.tga.tx','russian');f.put(f.game,'RESOURCE/Textures/Loading/start_loading.tga.tx','english');f.put(f.game,'RESOURCE/Textures/Loading/Russian/start_loading.tga.tx','russian fallback');
 const s=await start(t,{...f}),m=JSON.parse((await get(s.url,'/game/manifest.json')).body),names=m.files.map(e=>e.path);
 assert.ok(!names.includes('RESOURCE/VIDEOS/private.wmv'));assert.ok(!names.includes('RESOURCE/Sounds/PEOPLE/step.ogg'));assert.ok(names.includes('RESOURCE/Sounds/PEOPLE/step.wav'));
 assert.ok(names.includes('RESOURCE/Textures/Loading/Sea.tga.tx'));assert.ok(!names.includes('RESOURCE/Textures/Loading/Russian/Sea.tga.tx'));
 assert.equal((await get(s.url,'/game/RESOURCE/Textures/Loading/Sea.tga.tx')).body.toString(),'russian');
 assert.equal((await get(s.url,'/game/RESOURCE/Textures/Loading/start_loading.tga.tx')).body.toString(),'english');
 assert.equal((await get(s.url,'/game/RESOURCE/Textures/Loading/Russian/start_loading.tga.tx')).body.toString(),'russian fallback');
 for(const p of ['/game/RESOURCE/VIDEOS/private.wmv','/game/RESOURCE/Sounds/PEOPLE/step.ogg','/game/RESOURCE/Textures/Loading/Russian/Sea.tga.tx'])assert.equal((await get(s.url,p)).status,404);
});
test('video route permits only non-linked MP4 and disjoint game/static roots',async t=>{
 const f=fixture(t);f.put(f.videos,'plain.txt','private');fs.symlinkSync(path.join(f.game,'engine.ini'),path.join(f.videos,'leak.mp4'));
 const s=await start(t,{...f});assert.equal((await get(s.url,'/videos/plain.txt')).status,404);assert.equal((await get(s.url,'/videos/leak.mp4')).status,404);
 assert.equal((await get(s.url,'/videos/%2e%2e/game/engine.ini')).status,404);
 await assert.rejects(createDevServer({...f,game:f.web}),/overlaps/);
 await assert.rejects(createDevServer({...f,videos:f.game}),/overlaps/);
});

test('video responses preserve headers, HEAD and range behavior',async t=>{
 const f=fixture(t),clip=Buffer.from(Array.from({length:200},(_,i)=>i));f.put(f.videos,'Trailer.mp4',clip);
 const s=await start(t,{...f});
 const isolation=r=>{assert.equal(r.headers['cross-origin-opener-policy'],'same-origin');assert.equal(r.headers['cross-origin-embedder-policy'],'require-corp');assert.equal(r.headers['cross-origin-resource-policy'],'same-origin');};
 let r=await get(s.url,'/videos/Trailer.mp4');assert.equal(r.status,200);assert.deepEqual(r.body,clip);assert.equal(r.headers['content-type'],'video/mp4');assert.equal(r.headers['content-length'],'200');assert.equal(r.headers['accept-ranges'],'bytes');assert.equal(r.headers['cache-control'],'no-store');isolation(r);
 r=await get(s.url,'/videos/Trailer.mp4',{method:'HEAD'});assert.equal(r.status,200);assert.equal(r.body.length,0);assert.equal(r.headers['content-length'],'200');isolation(r);
 for(const name of ['Missing.mp4','notes.txt']){r=await get(s.url,'/videos/'+name);assert.equal(r.status,404);isolation(r);}
 for(const [range,start,end] of [['bytes=2-5',2,5],['bytes=190-',190,199],['bytes=-3',197,199],['bytes=0-99999',0,199],['bytes=0-0',0,0],['bytes=0-1,10-11',0,1]]){
  r=await get(s.url,'/videos/Trailer.mp4',{headers:{range}});assert.equal(r.status,206,range);assert.deepEqual(r.body,clip.subarray(start,end+1),range);assert.equal(r.headers['content-range'],`bytes ${start}-${end}/200`);assert.equal(r.headers['content-length'],String(end-start+1));isolation(r);
 }
 for(const range of ['bytes=200-','bytes=300-400','bytes=5-3','bytes=abc','bytes=-0','bytes=--5']){r=await get(s.url,'/videos/Trailer.mp4',{headers:{range}});assert.equal(r.status,416,range);assert.equal(r.headers['content-range'],'bytes */200');assert.equal(r.body.length,0);}
 r=await get(s.url,'/videos/Trailer.mp4',{headers:{range:'items=0-3'}});assert.equal(r.status,200);assert.deepEqual(r.body,clip);
});

test('video alias rejects encoded traversal, inappropriate names and linked files',async t=>{
 const f=fixture(t),outside=f.put(f.root,'outside/secret.mp4','OUTSIDE SECRET');f.put(f.videos,'Russian/Invasion.mp4','NESTED');f.put(f.videos,'LOUD.MP4','UPPER');f.put(f.videos,'notes.txt','not a video');fs.mkdirSync(path.join(f.videos,'dir.mp4'));
 fs.symlinkSync(outside,path.join(f.videos,'link.mp4'));fs.symlinkSync(path.dirname(outside),path.join(f.videos,'linkdir'));fs.linkSync(outside,path.join(f.videos,'hard.mp4'));
 const s=await start(t,{...f});
 for(const [url,body] of [['/videos/Russian/Invasion.mp4','NESTED'],['/videos/LOUD.MP4','UPPER'],['/videos/Trailer.mp4?download=1','0123456789']]){const r=await get(s.url,url);assert.equal(r.status,200,url);assert.equal(r.body.toString(),body);}
 for(const url of ['/videos/notes.txt','/videos/Trailer.mp4.txt','/videos/Trailer.txt?x=.mp4','/videos/Trailer.mp4%00.txt','/videos/Trailer.mp4%00','/videos/Trailer.mp4/','/videos/dir.mp4','/videos/dir.mp4/','/videos/%2e%2e/game/SAVE/slot.mp4','/videos/..%2f..%2fgame%2fSAVE%2fslot.mp4','/videos/Russian/../Trailer.mp4','/videos/Russian/%2e%2e/Trailer.mp4','/videos/%5cTrailer.mp4','/videos/Russian%5cInvasion.mp4','/videos//Trailer.mp4','/videos/%2fetc%2fhosts.mp4','/videos/Trailer.mp4%0d%0aX:%20y','/videos/%ff.mp4','/videos/','/videos','/Videos/Trailer.mp4','/videos/.mp4','/videos/link.mp4','/videos/hard.mp4','/videos/linkdir/secret.mp4']){
  for(const [method,headers] of [['GET',{}],['HEAD',{}],['GET',{range:'bytes=0-3'}]]){const r=await get(s.url,url,{method,headers});assert.equal(r.status,404,`${method} ${url}`);assert.ok(!r.body.toString().includes('OUTSIDE SECRET'));}
 }
 const off=await start(t,{...f,videos:null});assert.equal((await get(off.url,'/videos/Trailer.mp4')).status,404);
});

test('video requests require authentication for GET, HEAD and byte ranges',async t=>{
 const f=fixture(t),s=await start(t,{...f,password:'pw'}),good={authorization:'Basic '+Buffer.from('any:pw').toString('base64')},bad={authorization:'Basic '+Buffer.from('any:nope').toString('base64')};
 for(const [method,extra] of [['GET',{}],['HEAD',{}],['GET',{range:'bytes=0-3'}]])for(const auth of [{},bad])assert.equal((await get(s.url,'/videos/Trailer.mp4',{method,headers:{...extra,...auth}})).status,401);
 let r=await get(s.url,'/videos/Trailer.mp4',{headers:{...good,range:'bytes=0-3'}});assert.equal(r.status,206);assert.equal(r.body.toString(),'0123');r=await get(s.url,'/videos/Trailer.mp4',{headers:good});assert.equal(r.status,200);
});

test('compressed dev objects support range resume, refresh cache, and reject unpublished names',async t=>{
 const f=fixture(t),cache=path.join(f.root,'cache');f.put(f.game,'RESOURCE/Textures/Loading/Russian/Sea.tga.tx','SEA'.repeat(10000));f.put(f.game,'RESOURCE/c.tx','A'.repeat(4000));f.put(f.game,'RESOURCE/c.tx.gz','real gz collision');
 const plain=await start(t,{...f}),s=await start(t,{...f,compress:true,packCache:cache}),m=JSON.parse((await get(s.url,'/game/manifest.json')).body),raw=JSON.parse((await get(plain.url,'/game/manifest.json')).body);assert.equal(m.version,raw.version);
 const name='/game/RESOURCE/large.c.gz';let r=await get(s.url,name);assert.equal(r.status,200);const first=r.body;assert.equal(r.headers['content-type'],'application/octet-stream');assert.equal(r.headers['content-encoding'],undefined);assert.equal(Number(r.headers['content-length']),first.length);
 r=await get(s.url,name,{method:'HEAD'});assert.equal(r.status,200);assert.equal(r.body.length,0);assert.equal(Number(r.headers['content-length']),first.length);
 const half=Math.floor(first.length/2),a=await get(s.url,name,{headers:{range:`bytes=0-${half-1}`}}),b=await get(s.url,name,{headers:{range:`bytes=${half}-`}});assert.equal(a.status,206);assert.equal(b.status,206);assert.deepEqual(Buffer.concat([a.body,b.body]),first);
 r=await get(s.url,name,{headers:{range:`bytes=${first.length}-`}});assert.equal(r.status,416);assert.equal(r.headers['content-range'],`bytes */${first.length}`);
 for(const url of ['/game/options.gz','/game/nothing.gz','/game/SAVE/secret.gz','/game/RESOURCE/c.tx.gz.gz','/game/RESOURCE/Textures/Loading/Russian/Sea.tga.tx.gz'])assert.equal((await get(s.url,url)).status,404,url);
 assert.equal((await get(s.url,'/game/RESOURCE/c.tx.gz')).body.toString(),'real gz collision');
 const relocated='/game/RESOURCE/Textures/Loading/Sea.tga.tx.gz';r=await get(s.url,relocated);assert.equal(r.status,200);assert.equal(unpackRecord('gzip',r.body,30000)[0].toString(),'SEA'.repeat(10000));
 const source=path.join(f.game,'RESOURCE/large.c');fs.writeFileSync(source,'changed'.repeat(900));r=await get(s.url,name);assert.notDeepEqual(r.body,first);assert.equal(unpackRecord('gzip',r.body,6300)[0].toString(),'changed'.repeat(900));assert.ok(fs.readdirSync(cache).filter(x=>x.endsWith('.k2gz')).length>=3);assert.ok(!fs.readdirSync(cache).some(x=>x.endsWith('.part')));
});

test('concurrent packed reads use one cache object and honor byte ranges',async t=>{
 const f=fixture(t),cache=path.join(f.root,'cache'),s=await start(t,{...f,pack:true,packCache:cache}),m=JSON.parse((await get(s.url,'/game/manifest.json')).body),p='/game/'+m.packs[0].path;
 const results=await Promise.all(Array.from({length:6},()=>get(s.url,p)));assert.ok(results.every(r=>r.status===200&&r.body.equals(results[0].body)));assert.equal(results[0].body.length,m.packs[0].size);
 const e=m.files.find(item=>item.pack===0&&item.csize>0),r=await get(s.url,p,{headers:{range:`bytes=${e.offset}-${e.offset+e.csize-1}`}});assert.equal(r.status,206);assert.deepEqual(r.body,results[0].body.subarray(e.offset,e.offset+e.csize));assert.equal(r.headers['content-range'],`bytes ${e.offset}-${e.offset+e.csize-1}/${m.packs[0].size}`);
 assert.equal(fs.readdirSync(cache).length,1);assert.equal((await get(s.url,'/game/_k2pack/0000-000000000000.pack')).status,404);
});

test('on-demand pack layout and bytes agree with the offline builder',async t=>{
 const f=fixture(t),out=path.join(f.root,'objects'),files=gameFiles(f.game),opts={pack:true,maxFile:4096,target:8192};fs.mkdirSync(out);
 const [packed,packs,hashes]=await writeGame(files,out,opts),sources=new Map([...files].map(([p,src])=>[p,packed.has(p)?src:path.join(out,p)])),expected=manifestFor(sources,packed,packs,hashes);
 const s=await start(t,{...f,...opts}),served=JSON.parse((await get(s.url,'/game/manifest.json')).body);assert.deepEqual(served.packs,expected.packs);assert.deepEqual(served.files,expected.files);assert.equal(served.version,expected.version);
 for(const pack of packs){const r=await get(s.url,'/game/'+pack.path);assert.equal(r.status,200);assert.deepEqual(r.body,fs.readFileSync(path.join(out,pack.path)));}
});

test('Brotli development serving handles loose objects, ranges and name collisions',async t=>{
 const f=fixture(t);f.put(f.game,'RESOURCE/collision.gm','C'.repeat(4000));f.put(f.game,'RESOURCE/collision.gm.br','real asset');
 const br=await start(t,{...f,compress:true,codec:'br',quality:5}),gz=await start(t,{...f,compress:true}),plain=JSON.parse((await get(gz.url,'/game/manifest.json')).body),m=JSON.parse((await get(br.url,'/game/manifest.json')).body),e=m.files.find(x=>x.path==='RESOURCE/large.c');
 assert.equal(m.version,plain.version);assert.equal(e.enc,'br');assert.equal(e.csize,undefined);assert.ok(plain.files.every(x=>!x.enc||x.enc==='gzip'));
 let r=await get(br.url,'/game/RESOURCE/large.c.br');assert.equal(r.status,200);assert.equal(r.headers['content-encoding'],undefined);assert.equal(unpackRecord('br',r.body,e.size)[0].toString(),'abc123'.repeat(1000));
 const bytes=r.body;r=await get(br.url,'/game/RESOURCE/large.c.br',{headers:{range:'bytes=5-24'}});assert.equal(r.status,206);assert.deepEqual(r.body,bytes.subarray(5,25));
 assert.equal((await get(br.url,'/game/RESOURCE/large.c.gz')).status,404);assert.equal((await get(gz.url,'/game/RESOURCE/large.c.br')).status,404);
 assert.equal((await get(br.url,'/game/RESOURCE/collision.gm.br')).body.toString(),'real asset');assert.equal(m.files.find(x=>x.path==='RESOURCE/collision.gm').enc,undefined);
});

test('overlay dev server serves all records in plain, gzip, packed and Brotli layouts',async t=>{
 const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-serve-overlay-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));const f=await buildFixture(path.join(root,'fixture'),{layout:'plain'}),web=path.join(root,'web'),build=path.join(root,'build');fs.mkdirSync(web);fs.mkdirSync(build);
 for(const opts of [{},{compress:true},{pack:true},{pack:true,codec:'br',quality:5}]){const s=await start(t,{game:f.game_src,overlayDir:f.overlay_src,web,build,videos:null,...opts}),r=await get(s.url,'/game-en/manifest.json'),m=JSON.parse(r.body);assert.equal(r.status,200);assert.equal(m.overlay.format,1);const h=await get(s.url,'/game-en/manifest.json',{method:'HEAD'});assert.equal(h.status,200);assert.equal(Number(h.headers['content-length']),r.body.length);assert.equal(h.body.length,0);
  for(const e of m.files){const uri=e.pack===undefined?'/game-en/'+e.path+(e.enc==='br'?'.br':e.enc==='gzip'?'.gz':''):'/game-en/'+m.packs[e.pack].path,headers=e.pack===undefined?{}:{range:`bytes=${e.offset}-${e.offset+e.csize-1}`},got=await get(s.url,uri,{headers});assert.equal(got.status,e.pack===undefined?200:206,uri);const [data,ok]=e.enc?unpackRecord(e.enc,got.body,e.size):[got.body,true];assert.ok(ok);assert.equal(data.length,e.size);assert.equal(createHash('sha256').update(data).digest('hex'),e.sha256);}
  for(const bad of ['/game-en/SAVE/slot','/game-en/options','/game-en/../game/options','/game-en/%2e%2e/game/options','/game-en/OVERLAY.json','/game-en/RESOURCE/missing','/game-en//etc/hosts'])for(const method of ['GET','HEAD'])assert.equal((await get(s.url,bad,{method})).status,404,`${method} ${bad}`);
  assert.equal((await get(s.url,'/game/options')).status,200);assert.equal(JSON.parse((await get(s.url,'/game/manifest.json')).body).overlay,undefined);
 }
 const noOverlay=await start(t,{game:f.game_src,web,build,videos:null});assert.equal((await get(noOverlay.url,'/game-en/manifest.json')).status,404);
 fs.mkdirSync(path.join(f.overlay_src,'SAVE'));fs.writeFileSync(path.join(f.overlay_src,'SAVE/slot'),'private');await assert.rejects(createDevServer({game:f.game_src,overlayDir:f.overlay_src,web,build,videos:null}));
});
