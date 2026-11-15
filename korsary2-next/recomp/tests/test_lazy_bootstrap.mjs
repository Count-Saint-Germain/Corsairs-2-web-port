import test from 'node:test';
import assert from 'node:assert/strict';
import {planLazyBootstrap, lazyMutable, ensureLazyIdentity, bindLazyIdentity, verifyLazyCache, reconcileLazyIdentity, assertLazyIdentity, lazyBootstrapForSync} from '../web/experimental/lazy-bootstrap.mjs';
import {webcrypto} from 'node:crypto';
const file = path => ({path,size:3,sha256:'a'.repeat(64)});
const manifest = () => ({version:'x1',files:['ENGINE.exe','engine.ini','options','MODULES/a.dll','PROGRAM/init.c','RESOURCE/INI/a.ini','RESOURCE/MODELS/ship.gm','SAVE/user','SAVE_META/time','SAVE_TX/pending'].map(file)});

function memoryRoot() {
  const missing = () => Object.assign(new Error('missing'),{name:'NotFoundError'});
  const directory = () => ({kind:'directory',children:new Map(),
    async *entries(){yield* this.children;},
    async getDirectoryHandle(name,options={}) {
      if (!this.children.has(name) && options.create) this.children.set(name,directory());
      const item=this.children.get(name); if (!item) throw missing(); if (item.kind!=='directory') throw Error('not directory'); return item;
    },
    async getFileHandle(name,options={}) {
      if (!this.children.has(name) && options.create) this.children.set(name,resource('',''));
      const item=this.children.get(name); if (!item) throw missing(); if (item.kind!=='file') throw Error('not file'); return item;
    },
    async removeEntry(name) {if(!this.children.delete(name))throw missing();}
  });
  const resource = (data,hash) => ({kind:'file',data,hash,
    async getFile(){return {size:this.data.length,text:async()=>this.data};},
    async createWritable(){let staged=this.data;return {write:async value=>{staged=String(value);},close:async()=>{this.data=staged;},abort:async()=>{}};}
  });
  const root=directory();
  async function put(path,data,hash) {
    const parts=path.split('/'), name=parts.pop(); let dir=root;
    for(const part of parts)dir=await dir.getDirectoryHandle(part,{create:true});
    const item=resource(data,hash);dir.children.set(name,item);return item;
  }
  async function get(path) {
    const parts=path.split('/'), name=parts.pop();let dir=root;
    for(const part of parts)dir=await dir.getDirectoryHandle(part);
    return dir.getFileHandle(name);
  }
  return {root,put,get};
}

test('stale tabs cannot start against a new or interrupted lazy installation',async()=>{
  const fs=memoryRoot(),parent={getDirectoryHandle:async()=>fs.root}, old=planLazyBootstrap(manifest());
  const repair=async()=>{throw Error('unexpected repair');};
  await reconcileLazyIdentity(parent,'test',old,{repair});
  await assertLazyIdentity(parent,'test',old);
  const newer=planLazyBootstrap({...manifest(),version:'x2'});
  await reconcileLazyIdentity(parent,'test',newer,{repair});
  await assert.rejects(assertLazyIdentity(parent,'test',old),/changed in another tab/);
  await assert.rejects(reconcileLazyIdentity(parent,'test',old,{repair,inventoryOnly:true}),/not current/);
  await assertLazyIdentity(parent,'test',newer);
  const fh=await fs.get('experimental-version.json'),writer=await fh.createWritable();
  const identity=JSON.parse(await (await fh.getFile()).text());identity.pending={version:'x3',files:[]};
  await writer.write(JSON.stringify(identity));await writer.close();
  await assert.rejects(assertLazyIdentity(parent,'test',newer),/changed in another tab/);
  await assert.rejects(reconcileLazyIdentity(parent,'test',newer,{repair,inventoryOnly:true}),/interrupted update/);
});

test('bootstrap updates keep existing engine.ini and reject ambiguous casing',async()=>{
  const fs=memoryRoot(),plan=planLazyBootstrap(manifest());
  assert.ok((await lazyBootstrapForSync(fs.root,plan)).files.some(f=>f.path==='engine.ini'));
  const settings=await fs.put('engine.ini','my-settings','user');
  assert.ok(!(await lazyBootstrapForSync(fs.root,plan)).files.some(f=>f.path==='engine.ini'));
  assert.equal(settings.data,'my-settings');
  await fs.put('ENGINE.INI','other','user');
  await assert.rejects(lazyBootstrapForSync(fs.root,plan),/Ambiguous engine.ini/);
  assert.equal(settings.data,'my-settings');
});

test('lazy manifest update resumes safely and keeps SAVE untouched',async()=>{
  const fs=memoryRoot(), parent={getDirectoryHandle:async()=>fs.root};
  const old=planLazyBootstrap(manifest());
  const newer=manifest();newer.version='x2';
  newer.files=newer.files.filter(f=>f.path!=='RESOURCE/MODELS/ship.gm');
  for(const f of newer.files)if(['MODULES/a.dll','RESOURCE/INI/a.ini'].includes(f.path))f.sha256='b'.repeat(64);
  newer.files.push(file('PROGRAM/extra.c'));
  const next=planLazyBootstrap(newer);
  let repairs=0;
  const hash=async(_dir,path)=>(await fs.get(path)).hash;
  const repair=async entry=>{repairs++;if(repairs===2)throw Error('network interruption');const fh=await fs.get(entry.path);fh.hash=entry.sha256;return fh;};
  assert.equal((await reconcileLazyIdentity(parent,'test',old,{repair,hashFile:hash})).status,'created');
  for(const entry of old.files.filter(f=>!lazyMutable(f.path)))await fs.put(entry.path,'abc',entry.sha256);
  const save=await fs.put('SAVE/slot','my-save','save-hash');
  await assert.rejects(reconcileLazyIdentity(parent,'test',next,{repair,hashFile:hash}),/network interruption/);
  const journal=JSON.parse(await (await (await fs.get('experimental-version.json')).getFile()).text());
  assert.equal(journal.pending.version,next.version);
  assert.equal((await fs.get('MODULES/a.dll')).hash,'b'.repeat(64));
  assert.equal(save.data,'my-save');
  const other=planLazyBootstrap({...newer,version:'x3'});
  await assert.rejects(reconcileLazyIdentity(parent,'test',other,{repair,hashFile:hash}),/different lazy update was interrupted/);
  const resumed=await reconcileLazyIdentity(parent,'test',next,{repair,hashFile:hash});
  assert.equal(resumed.status,'updated');
  await assert.rejects(fs.get('RESOURCE/MODELS/ship.gm'),{name:'NotFoundError'});
  assert.equal((await fs.get('RESOURCE/INI/a.ini')).hash,'b'.repeat(64));
  assert.equal(save.data,'my-save');
  assert.equal((await reconcileLazyIdentity(parent,'test',next,{repair,hashFile:hash})).status,'current');
});

test('legacy identity may acquire an inventory only for its exact original manifest',async()=>{
  const fs=memoryRoot(), parent={getDirectoryHandle:async()=>fs.root}, old=planLazyBootstrap(manifest());
  const repair=async()=>{throw Error('unexpected repair');};
  await ensureLazyIdentity(parent,'test',old.version);
  const saved=await fs.put('SAVE/slot','keep','user-hash');
  const newer=planLazyBootstrap({...manifest(),version:'x2'});
  await assert.rejects(reconcileLazyIdentity(parent,'test',newer,{repair}),/no resource inventory/);
  assert.equal(saved.data,'keep');
  assert.equal((await reconcileLazyIdentity(parent,'test',old,{repair})).status,'inventoried');
  assert.equal((await reconcileLazyIdentity(parent,'test',newer,{repair})).status,'updated');
  assert.equal(saved.data,'keep');
});

test('lazy manifest update refuses unknown and noncanonical resources before modifying anything',async()=>{
  const fs=memoryRoot(), parent={getDirectoryHandle:async()=>fs.root}, old=planLazyBootstrap(manifest());
  const hash=async(_dir,path)=>(await fs.get(path)).hash;
  const repair=async()=>{throw Error('unexpected repair');};
  await reconcileLazyIdentity(parent,'test',old,{repair,hashFile:hash});
  const newer=manifest();newer.version='x2';newer.files.push(file('RESOURCE/MODELS/new.gm'));
  const next=planLazyBootstrap(newer), unknown=await fs.put('RESOURCE/MODELS/new.gm','xxx','user-hash');
  const save=await fs.put('SAVE/slot','my-save','save-hash');
  const identity=await (await (await fs.get('experimental-version.json')).getFile()).text();
  await assert.rejects(reconcileLazyIdentity(parent,'test',next,{repair,hashFile:hash}),/Unrecognized file/);
  assert.equal(await (await (await fs.get('experimental-version.json')).getFile()).text(),identity);
  assert.equal(unknown.data,'xxx');assert.equal(save.data,'my-save');
});

test('lazy update refuses conflicting directory casing before writing a journal',async()=>{
  const fs=memoryRoot(), parent={getDirectoryHandle:async()=>fs.root}, old=planLazyBootstrap(manifest());
  const repair=async()=>{throw Error('unexpected repair');};
  await reconcileLazyIdentity(parent,'test',old,{repair});
  const newer=manifest();newer.version='x2';newer.files.push(file('RESOURCE/MODELS/new.gm'));
  await fs.put('resource/MODELS/new.gm','abc','a'.repeat(64));
  const identity=await (await (await fs.get('experimental-version.json')).getFile()).text();
  await assert.rejects(reconcileLazyIdentity(parent,'test',planLazyBootstrap(newer),{repair}),/Ambiguous lazy update path/);
  assert.equal(await (await (await fs.get('experimental-version.json')).getFile()).text(),identity);
});

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
  for(const alter of [m=>m.files.push(file('../SAVE/x')),m=>m.files.push(file('resource/models/SHIP.gm')),m=>m.files.push(file('resource/models/other.gm')),m=>m.files.push(file('bad\tpath')),m=>m.files.push(file('RESOURCE/'+ 'я'.repeat(128))),m=>m.files=m.files.filter(f=>f.path!=='ENGINE.exe'),m=>m.files=m.files.filter(f=>!f.path.startsWith('MODULES/'))]){
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

test('repair replaces only damaged immutable entries, then verifies them again',async()=>{
  const p=planLazyBootstrap(manifest()), paths=new Map(), reads=[];
  const directory=()=>({kind:'directory',children:new Map(),async *entries(){yield* this.children;}}),root=directory();
  function put(path,size,hash) {
    const parts=path.split('/');let dir=root;
    for(const part of parts.slice(0,-1)) {if(!dir.children.has(part))dir.children.set(part,directory());dir=dir.children.get(part);}
    const h={kind:'file',size,hash,async getFile(){return {size:this.size};}};
    dir.children.set(parts.at(-1),h);paths.set(path,h);return h;
  }
  for(const e of p.initial.filter(e=>!lazyMutable(e.path) && e.path!=='MODULES/a.dll'))put(e.path,e.size,e.sha256);
  const bad=put('RESOURCE/MODELS/ship.gm',0,'old');
  const unknown=put('RESOURCE/MODELS/user-file.dat',4,'mine');
  root.children.set('SAVE',{kind:'directory',async *entries(){throw new Error('SAVE was read');}});
  const hash=async(_dir,path)=>{reads.push(path);return paths.get(path).hash;};
  const calls=[];
  const repair=async(entry,info)=>{
    calls.push([entry.path,info.reason]);
    const h=paths.get(info.path) || put(info.path,0,'');
    h.size=entry.size;h.hash=entry.sha256;return h;
  };
  const result=await verifyLazyCache(root,p,hash,{repair});
  assert.equal(result.repaired,2); assert.deepEqual(calls,[['RESOURCE/MODELS/ship.gm','size'],['MODULES/a.dll','missing']]);
  assert.deepEqual([bad.size,bad.hash],[3,'a'.repeat(64)]);
  assert.deepEqual([unknown.size,unknown.hash],[4,'mine']);assert.ok(root.children.has('SAVE'));
  assert.equal(reads.filter(path=>path==='RESOURCE/MODELS/ship.gm').length,1,'the repaired bytes are rehashed');
  bad.hash='wrong';calls.length=0;
  assert.equal((await verifyLazyCache(root,p,hash,{repair})).repaired,1);
  assert.deepEqual(calls,[['RESOURCE/MODELS/ship.gm','hash']]);
});

test('failed repair or failed verification prevents launch without changing other files',async()=>{
  const p=planLazyBootstrap(manifest()),paths=new Map();
  const directory=()=>({kind:'directory',children:new Map(),async *entries(){yield* this.children;}}),root=directory();
  function put(path,size,hash) {
    const parts=path.split('/');let dir=root;
    for(const part of parts.slice(0,-1)) {if(!dir.children.has(part))dir.children.set(part,directory());dir=dir.children.get(part);}
    const h={kind:'file',size,hash,async getFile(){return {size:this.size};}};dir.children.set(parts.at(-1),h);paths.set(path,h);return h;
  }
  for(const e of p.initial.filter(e=>!lazyMutable(e.path)))put(e.path,e.size,e.sha256);
  const bad=put('RESOURCE/MODELS/ship.gm',0,'old');root.children.set('SAVE',{kind:'directory',async *entries(){throw Error('SAVE read');}});
  const hash=async(_dir,path)=>paths.get(path).hash;
  await assert.rejects(verifyLazyCache(root,p,hash,{repair:async()=>{throw Error('network unavailable');}}),/network unavailable/);
  assert.deepEqual([bad.size,bad.hash],[0,'old']);assert.ok(root.children.has('SAVE'));
  await assert.rejects(verifyLazyCache(root,p,hash,{repair:async()=>bad}),/repair failed verification/);
  assert.deepEqual([bad.size,bad.hash],[0,'old']);assert.ok(root.children.has('SAVE'));
});

test('ambiguous repair paths fail before modifying a resource',async()=>{
  const p=planLazyBootstrap(manifest()),paths=new Map();
  const directory=()=>({kind:'directory',children:new Map(),async *entries(){yield* this.children;}}),root=directory();
  function put(path,size,hash) {
    const parts=path.split('/');let dir=root;
    for(const part of parts.slice(0,-1)) {if(!dir.children.has(part))dir.children.set(part,directory());dir=dir.children.get(part);}
    const h={kind:'file',size,hash,async getFile(){return {size:this.size};}};dir.children.set(parts.at(-1),h);paths.set(path,h);return h;
  }
  for(const e of p.initial.filter(e=>!lazyMutable(e.path)))put(e.path,e.size,e.sha256);
  put('RESOURCE/MODELS/SHIP.gm',0,'old');let calls=0;
  await assert.rejects(verifyLazyCache(root,p,async(_dir,path)=>paths.get(path).hash,{repair:async()=>{calls++;}}),/noncanonical spelling/);
  assert.equal(calls,0);
});
