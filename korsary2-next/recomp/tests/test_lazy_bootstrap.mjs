import test from 'node:test';
import assert from 'node:assert/strict';
import {planLazyBootstrap, lazyMutable, ensureLazyIdentity, bindLazyIdentity, verifyLazyCache} from '../web/experimental/lazy-bootstrap.mjs';
import {webcrypto} from 'node:crypto';
const file = path => ({path,size:3,sha256:'a'.repeat(64)});
const manifest = () => ({version:'x1',files:['ENGINE.exe','engine.ini','options','MODULES/a.dll','PROGRAM/init.c','RESOURCE/INI/a.ini','RESOURCE/MODELS/ship.gm','SAVE/user','SAVE_META/time','SAVE_TX/pending'].map(file)});

test('only startup data is selected, manifest index excludes all mutable paths',()=>{
  const p=planLazyBootstrap(manifest());
  assert.equal(p.version,'lazy-bootstrap-v1:x1');
  assert.deepEqual(p.initial.map(x=>x.path),['ENGINE.exe','engine.ini','options','MODULES/a.dll','PROGRAM/init.c','RESOURCE/INI/a.ini']);
  assert.match(p.index,/RESOURCE\/MODELS\/ship\.gm\t3\n/);
  assert.doesNotMatch(p.index,/(^|\n)(?:SAVE|SAVE_META|SAVE_TX|options|engine\.ini)(?:\/|\t)/i);
  for(const name of ['SAVE/a','Save_Meta/x','SAVE_TX/a','options','ENGINE.INI'])assert.equal(lazyMutable(name),true);
});
test('identity protects interrupted installs and never removes unrecognized files or saves', async()=>{
  const contents = new Map();
  const dir = {
    async *entries(){for(const item of contents)yield item;},
    async getFileHandle(name,opts={}){
      if (!contents.has(name) && !opts.create) throw Object.assign(new Error('missing'),{name:'NotFoundError'});
      if (!contents.has(name)) contents.set(name,'');
      return {getFile:async()=>({text:async()=>contents.get(name)}),createWritable:async()=>({write:async text=>contents.set(name,text),close:async()=>{},abort:async()=>{}})};
    },
  };
  const root={getDirectoryHandle:async()=>dir};
  await ensureLazyIdentity(root,'separate-root','lazy-bootstrap-v1:a');
  await ensureLazyIdentity(root,'separate-root','lazy-bootstrap-v1:a');
  contents.set('SAVE','do not touch');
  await assert.rejects(ensureLazyIdentity(root,'separate-root','lazy-bootstrap-v1:b'),/different game version/);
  assert.equal(contents.get('SAVE'),'do not touch');
  contents.delete('experimental-version.json');
  await assert.rejects(ensureLazyIdentity(root,'separate-root','lazy-bootstrap-v1:b'),/not empty/);
  assert.equal(contents.get('SAVE'),'do not touch');
});
test('invalid or ambiguous manifests fail before writing',()=>{
  for(const alter of [m=>m.files.push(file('../SAVE/x')),m=>m.files.push(file('resource/models/SHIP.gm')),m=>m.files.push(file('bad\tpath')),m=>m.files=m.files.filter(f=>f.path!=='ENGINE.exe'),m=>m.files=m.files.filter(f=>!f.path.startsWith('MODULES/'))]){
    const m=manifest(); alter(m); assert.throws(()=>planLazyBootstrap(m));
  }
});
test('identity changes when files change even if the server reuses a version',async()=>{
  const a=manifest(),b=manifest();b.files.find(f=>f.path.includes('ship.gm')).sha256='b'.repeat(64);
  const p=await bindLazyIdentity(planLazyBootstrap(a),webcrypto.subtle),q=await bindLazyIdentity(planLazyBootstrap(b),webcrypto.subtle);
  assert.notEqual(p.version,q.version);
  await assert.rejects(bindLazyIdentity(planLazyBootstrap(a),{}),/WebCrypto/);
});

test('cache verification refuses crash placeholders without reading or deleting saves',async()=>{
  const p=planLazyBootstrap(manifest()), files=new Map();
  const directory=()=>({kind:'directory', children:new Map(), async *entries(){yield* this.children;}});
  const root=directory();
  function put(path,size) {
    const parts=path.split('/');let dir=root;
    for(const part of parts.slice(0,-1)) {if(!dir.children.has(part))dir.children.set(part,directory());dir=dir.children.get(part);}
    const item={kind:'file',size,async getFile(){return {size:this.size};}};
    dir.children.set(parts.at(-1),item);files.set(path,item);
  }
  for(const e of p.initial.filter(e=>!lazyMutable(e.path))) put(e.path,e.size);
  put('RESOURCE/MODELS/ship.gm',3);
  root.children.set('SAVE',{kind:'directory',async *entries(){throw new Error('SAVE was read');}});
  const hash=async(_dir,path)=>p.files.find(e=>e.path.toLowerCase()===path.toLowerCase()).sha256;
  assert.equal((await verifyLazyCache(root,p,hash)).verified,5);
  files.get('RESOURCE/MODELS/ship.gm').size=0;
  await assert.rejects(verifyLazyCache(root,p,hash),/incomplete or damaged/);
  assert.equal(files.get('RESOURCE/MODELS/ship.gm').size,0);
  assert.ok(root.children.has('SAVE'));
  files.get('RESOURCE/MODELS/ship.gm').size=3;
  await assert.rejects(verifyLazyCache(root,p,async()=> 'b'.repeat(64)),/incomplete or damaged/);
  root.children.get('MODULES').children.delete('a.dll');
  await assert.rejects(verifyLazyCache(root,p,hash),/bootstrap resource is missing/);
  assert.ok(root.children.has('SAVE'));
});
