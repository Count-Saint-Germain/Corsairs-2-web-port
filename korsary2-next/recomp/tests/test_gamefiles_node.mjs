import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { createHash, webcrypto } from 'node:crypto';
import { gzipSync, gunzipSync, brotliCompressSync, constants as zc } from 'node:zlib';
import { parseSiblingRules, redundantSiblings, parseRelocateRules, relocations, wanted, gameFiles, planPacks, packObjectName, manifestFor, overlayPathProblem, overlayFiles, overlayMetaBlock, overlayBaseMismatches, overlayMissingRequired } from '../web/gamefiles.mjs';
// Node 18 exposes Web Crypto via node:crypto; browsers expose it globally.
if (!globalThis.crypto) globalThis.crypto = webcrypto;
const sha = x=>createHash('sha256').update(x).digest('hex');
function temp(t){const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-gamefiles-node-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));return root;}
function write(root,p,body='x'){const file=path.join(root,p);fs.mkdirSync(path.dirname(file),{recursive:true});fs.writeFileSync(file,body);return file;}
function minimalGame(root){for(const f of ['ENGINE.exe','engine.ini','options','PROGRAM/seadogs.c','PROGRAM/CONTROLS/controls.c','PROGRAM/CONTROLS/init_pc.c','MODULES/XINTERFACE.dll','MODULES/DX8RENDER.dll','MODULES/SOUND.dll','MODULES/PCS_CONTROLS.dll','RESOURCE/INI/TEXTS/language.ini'])write(root,f);}
test('sibling rules validate chains and retain files without an adequate sibling',()=>{
  const rules=parseSiblingRules([{path:'RESOURCE/Sounds',extension:'.ogg',sibling_extension:'.wav',min_sibling_bytes:45}]);
  assert.deepEqual([...redundantSiblings([['RESOURCE/Sounds/a.ogg',3],['RESOURCE/Sounds/A.WAV',45],['RESOURCE/Sounds/b.ogg',2],['RESOURCE/Sounds/b.wav',44]],rules)],['RESOURCE/Sounds/a.ogg']);
  assert.throws(()=>parseSiblingRules([{extension:'.ogg',sibling_extension:'.wav'},{extension:'.wav',sibling_extension:'.ogg'}]));
  assert.throws(()=>parseSiblingRules([{extension:'.ogg',sibling_extension:'.ogg'}]));
});
test('relocation preserves existing destination and is idempotent',()=>{
  const rules=parseRelocateRules([{from:'RESOURCE/Loading/Russian',to:'RESOURCE/Loading'}]);
  const files=['RESOURCE/Loading/Russian/A.tx','RESOURCE/Loading/Russian/B.tx','RESOURCE/Loading/a.tx'];
  const moves=relocations(files,rules);assert.deepEqual([...moves],[['RESOURCE/Loading/Russian/B.tx','RESOURCE/Loading/B.tx']]);
  assert.equal(relocations(files.map(p=>moves.get(p)??p),rules).size,0);
  assert.throws(()=>parseRelocateRules([{from:'a',to:'a/b'}]));
  assert.throws(()=>parseRelocateRules([{from:'a',to:'b'},{from:'b',to:'c'}]));
});
test('inventory keeps required data and omits player saves and duplicate audio',t=>{
  const root=temp(t);minimalGame(root);write(root,'SAVE/slot','private');write(root,'sAvE_mEtA/a','private');write(root,'SAVE_TX/a','private');
  write(root,'RESOURCE/Sounds/a.ogg','ogg');write(root,'RESOURCE/Sounds/a.wav','x'.repeat(45));
  write(root,'RESOURCE/Textures/Loading/Russian/A.tx','translated');
  const files=gameFiles(root);
  assert.ok(![...files.keys()].some(p=>p.toLowerCase().startsWith('save/')));assert.ok(!files.has('RESOURCE/Sounds/a.ogg'));
  assert.ok(files.has('RESOURCE/Textures/Loading/A.tx'));assert.equal(wanted('RESOURCE/VIDEOS/a.wmv'),null);
  fs.symlinkSync(path.join(root,'engine.ini'),path.join(root,'PROGRAM/link.c'));assert.throws(()=>gameFiles(root),/symlink/);
});
test('manifest version, pack planning and pack object names are deterministic',t=>{
  const root=temp(t),a=write(root,'a','AAA'),b=write(root,'b','BBBB');
  const files=new Map([['b',b],['a',a]]),m=manifestFor(files);
  const version=createHash('sha1').update(`a:3:${sha('AAA')};b:4:${sha('BBBB')};`).digest('hex').slice(0,12);
  assert.equal(m.version,version);assert.deepEqual(m.files.map(e=>e.path),['a','b']);
  const packed=manifestFor(files,new Map([['a',{pack:0,offset:0,csize:3}]]),[{path:'_k2pack/a.pack',size:3,files:1}]);
  assert.equal(packed.version,version);assert.equal(packed.files[0].pack,0);
  const [packs,loose]=planPacks(new Map([['b',4],['a',3],['options',1],['large',20]]),10,5);
  assert.deepEqual(packs,[['a'],['b']]);assert.deepEqual([...loose].sort(),['large','options']);
  assert.throws(()=>planPacks({'_K2PACK/x':1}));
  assert.match(packObjectName(1,[{path:'a',size:3,sha256:sha('AAA'),csize:3}]),/^_k2pack\/0001-[0-9a-f]{12}\.pack$/);
});
test('overlay paths and metadata reject unsafe input',()=>{
  for(const p of ['', '../a','PROGRAM/../x','PROGRAM/CON.txt','PROGRAM/.hidden','program/x','RESOURCE/a\\x','SAVE/slot','ENGINE.exe']) assert.ok(overlayPathProblem(p),p);
  assert.equal(overlayPathProblem('PROGRAM/dialog.c'),null);
  const files=new Map([['PROGRAM/dialog.c','x']]);const h=sha('base');
  assert.deepEqual(overlayMetaBlock({format:1,base:{'PROGRAM/dialog.c':h}},files),{format:1,base:{'PROGRAM/dialog.c':h}});
  assert.throws(()=>overlayMetaBlock({format:1,base:null},files));assert.throws(()=>overlayMetaBlock({format:1,base:{'PROGRAM/other':h}},files));
  assert.deepEqual(overlayBaseMismatches({base:{'PROGRAM/dialog.c':h}}, {files:[{path:'PROGRAM/dialog.c',sha256:sha('other')}]}),['PROGRAM/dialog.c']);
  assert.deepEqual(overlayMissingRequired(files,['PROGRAM/dialog.c','RESOURCE/required']),['RESOURCE/required']);
});
test('overlay rejects symlinks, hardlinks, case duplicates and forbidden top-level data',t=>{
  const root=temp(t);write(root,'PROGRAM/a.c');let [files]=overlayFiles(root);assert.equal(files.size,1);
  fs.symlinkSync('/does-not-exist',path.join(root,'RESOURCE'));assert.throws(()=>overlayFiles(root),/directory/);fs.unlinkSync(path.join(root,'RESOURCE'));
  fs.linkSync(path.join(root,'PROGRAM/a.c'),path.join(root,'PROGRAM/b.c'));assert.throws(()=>overlayFiles(root),/linked/);fs.unlinkSync(path.join(root,'PROGRAM/b.c'));
  write(root,'SAVE/x');assert.throws(()=>overlayFiles(root),/forbidden/);
});

test('gzip/br encoding and strict decoding reject truncated, modified, and trailing bytes', async t=>{
  const { gzipPass, brotliPass, unpackRecord, unpackCheck, packedKey, packable, worthPacking } = await import('../web/gamefiles.mjs');
  const root=temp(t), source=write(root,'raw','text data '.repeat(400)), input=fs.readFileSync(source);
  for(const enc of ['gzip','br']) {
    const chunks=[];const [size,hash,csize]=await (enc==='gzip'?gzipPass(source,b=>chunks.push(Buffer.from(b))):brotliPass(source,b=>chunks.push(Buffer.from(b)),5));
    const wire=Buffer.concat(chunks);assert.equal(size,input.length);assert.equal(hash,sha(input));assert.equal(csize,wire.length);
    const [plain,ok]=unpackRecord(enc,wire,input.length);assert.ok(ok);assert.deepEqual(plain,input);
    assert.equal(unpackRecord(enc,wire.subarray(0,-1),input.length)[1],false);
    assert.equal(unpackRecord(enc,Buffer.concat([wire,Buffer.from('garbage')]),input.length)[1],false);
    assert.equal(unpackRecord(enc,wire,1)[1],false);
    const output=write(root,`x.${enc}`,wire);assert.ok(unpackCheck(enc,output,input.length,sha(input)));
    assert.ok(!unpackCheck(enc,output,input.length,sha('wrong')));
  }
  assert.equal(packedKey('a','gzip'),'a.gz');assert.equal(packable('x.ogg',5000),false);assert.equal(packable('x.c',2000),true);assert.ok(worthPacking(2000,1500));
});
test('pack writer verifies content and reader detects truncation, corruption, gaps', async t=>{
  const { gzipPass, writePack, verifyPack } = await import('../web/gamefiles.mjs');
  const root=temp(t),a=write(root,'a','xyz'.repeat(500)),b=write(root,'b','hello');
  const gzip=[];const [size,hash,csize]=await gzipPass(a,bytes=>gzip.push(Buffer.from(bytes)));
  const members=[{path:'a',src:a,size,sha256:hash,csize,enc:'gzip'}, {path:'b',src:b,size:5,sha256:sha('hello'),csize:5,enc:null}];
  const pack=path.join(root,'output','x.pack');const offsets=await writePack(pack,members);assert.deepEqual(offsets,[[0,csize],[csize,5]]);
  const entries=members.map((m,i)=>({...m,offset:offsets[i][0]}));assert.ok(await verifyPack(pack,entries));
  assert.equal(await verifyPack(pack,entries,0),false);
  assert.equal(await verifyPack(pack,[{...entries[0],offset:1},entries[1]]),false);
  const bytes=fs.readFileSync(pack);bytes[bytes.length-1]^=1;fs.writeFileSync(pack,bytes);assert.equal(await verifyPack(pack,entries),false);
  const bad=path.join(root,'output','bad.pack');await assert.rejects(writePack(bad,[{...members[1],sha256:'bad'}]),/changed/);
});

test('analysis chooses only worthwhile compression and guards packed-name collisions', async t=>{
  const {analyseFiles,packableSet} = await import('../web/gamefiles.mjs');
  const root=temp(t), compressible=write(root,'compressible','A'.repeat(4000)), tiny=write(root,'tiny','a');
  const rows=new Map([['data.c',compressible],['tiny.c',tiny]]),eligible=packableSet(rows);
  assert.ok(eligible.has('data.c'));assert.ok(!eligible.has('tiny.c'));
  const analysed=await analyseFiles(rows,eligible);assert.equal(analysed.get('data.c').enc,'gzip');assert.equal(analysed.get('tiny.c').enc,null);
  assert.equal(analysed.get('data.c').sha256,sha('A'.repeat(4000)));
  const collision=new Map([...rows,['DATA.C.GZ',tiny]]);assert.ok(!packableSet(collision).has('data.c'));
});

test('Brotli selection independently compares gzip, Brotli and source sizes',async t=>{
 const {analyseFiles,packableSet}=await import('../web/gamefiles.mjs'),root=temp(t),data=Buffer.alloc(8000);let state=1234567;for(let i=0;i<data.length;i++){state^=state<<13;state^=state>>>17;state^=state<<5;data[i]=state&255;}
 const files=new Map([['RESOURCE/model.gm',write(root,'model.gm','ABCD'.repeat(10000))],['RESOURCE/noise.wav',write(root,'noise.wav',data)],['PROGRAM/small.c',write(root,'small.c','small')],['options',write(root,'options','O'.repeat(4000))],['RESOURCE/collision.gm',write(root,'collision.gm','C'.repeat(4000))],['RESOURCE/collision.gm.br',write(root,'collision.gm.br','real object')]]);
 const eligible=packableSet(files,['gzip','br']);assert.ok(!eligible.has('RESOURCE/collision.gm'));assert.ok(packableSet(files,['gzip']).has('RESOURCE/collision.gm'));
 const both=await analyseFiles(files,eligible,6,4,'br',5),gzip=await analyseFiles(files,eligible,6,4,'gzip',5);
 for(const [name,file] of files){const raw=fs.readFileSync(file),i=both.get(name);assert.equal(i.size,raw.length);assert.equal(i.sha256,sha(raw));assert.equal(i.size,gzip.get(name).size);assert.equal(i.sha256,gzip.get(name).sha256);
  if(!eligible.has(name)){assert.equal(i.enc,null);continue;}const gz=gzipSync(raw,{level:6}).length,br=brotliCompressSync(raw,{params:{[zc.BROTLI_PARAM_QUALITY]:5,[zc.BROTLI_PARAM_LGWIN]:22}}).length,best=gz<=raw.length*.95?gz:raw.length;
  if(br<=raw.length*.95&&br<=best*.95){assert.equal(i.enc,'br',name);assert.equal(i.csize,br,name);}else{assert.notEqual(i.enc,'br',name);assert.equal(i.csize,gzip.get(name).csize,name);}
 }
 assert.equal(both.get('RESOURCE/noise.wav').enc,null);assert.equal(both.get('options').enc,null);assert.equal(both.get('RESOURCE/model.gm').enc,'br');
});

test('mixed Brotli, gzip and raw pack records are reproducible and detect damage',async t=>{
 const {codecPass,writePack,verifyPack}=await import('../web/gamefiles.mjs'),root=temp(t),members=[];
 for(const [name,enc,data] of [['a.gm','br','ABCD'.repeat(10000)],['b.tx','gzip','XYZ'.repeat(5000)],['c.bin',null,'plain record']]){const src=write(root,name,data),bytes=Buffer.from(data),info=enc?await codecPass(enc,src,null,6,5):[bytes.length,sha(bytes),bytes.length];members.push({path:name,src,size:info[0],sha256:info[1],csize:info[2],enc});}
 const a=path.join(root,'a.pack'),b=path.join(root,'b.pack'),spans=await writePack(a,members,6,5);await writePack(b,members,6,5);assert.deepEqual(fs.readFileSync(a),fs.readFileSync(b));
 const entries=members.map((m,i)=>({...m,offset:spans[i][0]}));assert.ok(await verifyPack(a,entries));const bytes=fs.readFileSync(a);bytes[Math.floor(spans[0][1]/2)]^=255;fs.writeFileSync(a,bytes);assert.equal(await verifyPack(a,entries),false);
});
test('gzip output is deterministic with fixed headers and rejects non-exact streams',async t=>{
 const {gzipPass,gunzipCheck,packable,worthPacking}=await import('../web/gamefiles.mjs'),root=temp(t);
 for(const data of [Buffer.alloc(0),Buffer.from('x'),Buffer.from('text'.repeat(750000))]){const src=write(root,'input',data),make=async()=>{const chunks=[];const [size,digest,count]=await gzipPass(src,b=>chunks.push(Buffer.from(b)));const stream=Buffer.concat(chunks);assert.equal(size,data.length);assert.equal(digest,sha(data));assert.equal(count,stream.length);return stream;},stream=await make();assert.deepEqual(stream,await make());assert.deepEqual(gunzipSync(stream),data);assert.deepEqual(stream.subarray(0,10),Buffer.from([31,139,8,0,0,0,0,0,0,255]));
  const gz=write(root,'test.gz',stream);assert.ok(gunzipCheck(gz,data.length,sha(data)));assert.equal(gunzipCheck(gz,data.length+1,sha(data)),false);assert.equal(gunzipCheck(gz,data.length,sha('other')),false);
  for(const bytes of [stream.subarray(0,-1),Buffer.concat([stream,Buffer.from('junk')]),Buffer.concat([stream,gzipSync(Buffer.from('second'))]),Buffer.alloc(0),Buffer.from('not gzip')])assert.equal(gunzipCheck(write(root,'bad.gz',bytes),data.length,sha(data)),false);
 }
 for(const [name,size,want] of [['a.GM',1024,true],['a.gm',1023,false],['a.OGG',1e6,false],['options',5000,false],['PROGRAM/options.c',5000,true],['x.mp4',1e6,false],['x.gz',1e6,false]])assert.equal(packable(name,size),want,name);
 assert.ok(worthPacking(1000,940));assert.equal(worthPacking(1000,960),false);
});
test('page and packager compute the same manifest version for compressed entries',async t=>{
 const {manifestVersionDigest}=await import('../web/missing-resource-preflight.mjs'),root=temp(t),files=new Map([['PROGRAM/a.c',write(root,'a','A'.repeat(4000))],['options',write(root,'options','settings')]]),plain=manifestFor(files),compressed=manifestFor(files,new Map([['PROGRAM/a.c',{enc:'gzip',csize:50}]]));
 assert.equal(plain.version,compressed.version);assert.equal(await manifestVersionDigest(compressed.files),compressed.version);assert.deepEqual(Object.keys(plain.files[0]).sort(),['path','sha256','size']);
});
test('pack planning is deterministic, covers each file once and preserves zero-size records',async t=>{
 const sizes=new Map(Array.from({length:500},(_,i)=>[`d${i%9}/f${i}`,[0,10,5000,300000,2000000][(i*17)%5]]));sizes.set('options',10);
 const [packs,loose]=planPacks(sizes,1<<20,4<<20),[reverse,reverseLoose]=planPacks(new Map([...sizes].reverse()),1<<20,4<<20);assert.deepEqual(packs,reverse);assert.deepEqual([...loose].sort(),[...reverseLoose].sort());const all=[...packs.flat(),...loose];assert.equal(all.length,sizes.size);assert.equal(new Set(all).size,sizes.size);assert.ok(loose.has('options'));for(const pack of packs)assert.ok(pack.every(p=>sizes.get(p)<=1<<20));
 assert.deepEqual(planPacks({}),[[],new Set()]);assert.deepEqual(planPacks({x:900,y:900},1000,500)[0],[['x'],['y']]);
 const m={path:'a',size:1,sha256:'0'.repeat(64),enc:null,csize:1},name=packObjectName(3,[m]);for(const change of [{path:'b'},{size:2},{sha256:'1'.repeat(64)},{enc:'gzip'},{csize:2}])assert.notEqual(packObjectName(3,[{...m,...change}]),name);
 const {writePack,verifyPack}=await import('../web/gamefiles.mjs'),root=temp(t),src=write(root,'empty',''),file=path.join(root,'zero.pack'),entry={path:'empty',src,size:0,csize:0,sha256:sha(''),enc:null,offset:0};assert.deepEqual(await writePack(file,[entry]),[[0,0]]);assert.ok(await verifyPack(file,[entry]));assert.equal(await verifyPack(path.join(root,'missing'),[entry]),false);fs.writeFileSync(file,'x');assert.equal(await verifyPack(file,[entry]),false);
});
