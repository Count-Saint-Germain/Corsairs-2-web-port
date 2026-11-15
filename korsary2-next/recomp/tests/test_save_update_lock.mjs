import assert from 'node:assert/strict';
import { decodeBackup, encodeBackup, withSaveLock } from '../web/save-export.mjs';
import { importBackupZip } from '../web/save-import.mjs';
import { updateUnderSaveLock, withFreshGameDirectory } from '../web/save-protection.mjs';

class Locks {
  held = new Set();
  async request(name, options, fn) {
    assert.deepEqual(options, {mode:'exclusive', ifAvailable:true});
    if (this.held.has(name)) return fn(null);
    this.held.add(name);
    try { return await fn({name}); } finally { this.held.delete(name); }
  }
}
const missing = () => Object.assign(new Error('missing'), {name:'NotFoundError'});
class Dir {
  dirs = new Map(); files = new Map(); failFileCreate = false;
  async getDirectoryHandle(name, {create} = {}) {
    if (!this.dirs.has(name)) { if (!create) throw missing(); this.dirs.set(name, new Dir()); }
    return this.dirs.get(name);
  }
  async getFileHandle(name, {create} = {}) {
    if (create && this.failFileCreate) throw Error('injected storage failure');
    if (!this.files.has(name)) { if (!create) throw missing(); this.files.set(name, {data:new Uint8Array()}); }
    const record = this.files.get(name);
    return {kind:'file', async getFile() {const data=record.data.slice(); return {size:data.length, async arrayBuffer(){return data.buffer;}};},
      async createWritable() {let data; return {async write(v){data=v.slice();}, async close(){record.data=data;}};}};
  }
  async *entries() {for (const n of this.files.keys()) yield [n, await this.getFileHandle(n)];}
  async removeEntry(n) {if (!this.files.delete(n)) throw missing();}
}
const deferred = () => {let resolve; const promise=new Promise(r=>{resolve=r;}); return {promise,resolve};};
const bytes = s => new TextEncoder().encode(s);
const text = b => new TextDecoder().decode(b);
const root=new Dir(), locks=new Locks(), rootName='test-game';
const game=await root.getDirectoryHandle(rootName,{create:true});
const save=await game.getDirectoryHandle('SAVE',{create:true});
save.files.set('slot',{data:bytes('progress')});
let marker=null, calls=0;
const args={root,locks,rootName,version:'new',readMarker:async()=>marker,sync:async()=>{calls++; marker={version:'new'};}};

// A lost marker is not evidence that saves do not exist.
const result=await updateUnderSaveLock(args);
assert.equal(calls,1);
const backups=await root.getDirectoryHandle(rootName+'-backups');
assert.equal(text(decodeBackup(backups.files.get(result.backup.backup).data).entries[0].bytes),'progress');
assert.deepEqual(await updateUnderSaveLock(args),{skipped:'current'});
assert.equal(calls,1);
await assert.rejects(()=>updateUnderSaveLock({...args,version:undefined}),/параметры/);

// A failed backup or marker read must not start the update. A failed sync does
// not leak the lock; it may have partially changed game assets.
marker={version:'old'}; backups.failFileCreate=true;
await assert.rejects(()=>updateUnderSaveLock(args),/injected storage failure/);
assert.equal(calls,1); assert.equal(text(save.files.get('slot').data),'progress');
assert.equal(locks.held.size,0); backups.failFileCreate=false;
await assert.rejects(()=>updateUnderSaveLock({...args,readMarker:async()=>{throw Error('marker failed');}}),/marker failed/);
await assert.rejects(()=>updateUnderSaveLock({...args,sync:async()=>{throw Error('sync failed');}}),/sync failed/);
assert.equal(calls,1); assert.equal(locks.held.size,0);

const emptyRoot=new Dir(); let freshCalls=0;
const fresh={...args,root:emptyRoot,rootName:'fresh',readMarker:async()=>null,sync:async()=>{freshCalls++;}};
assert.deepEqual((await updateUnderSaveLock(fresh)).backup,{skipped:'no-saves'});
await (await emptyRoot.getDirectoryHandle('fresh',{create:true})).getDirectoryHandle('SAVE',{create:true});
assert.deepEqual((await updateUnderSaveLock(fresh)).backup,{skipped:'empty'});
assert.equal(freshCalls,2);

// The marker is re-read while the lock is owned, not trusted from a stale
// pre-lock observation. Stop during real archive reading to test backup time.
let readUnderLock=false;
assert.deepEqual(await updateUnderSaveLock({...args,readMarker:async()=>{
  readUnderLock=locks.held.has(rootName+':save-backup'); return {version:'new'};
}}),{skipped:'current'});
assert.equal(readUnderLock,true);
const reading=deferred(), finishRead=deferred();
const originalEntries=save.entries.bind(save);
save.entries=async function* () {
  for await (const [name,handle] of originalEntries()) {
    const getFile=handle.getFile;
    handle.getFile=async()=>{ reading.resolve(); await finishRead.promise; return getFile(); };
    yield [name,handle];
  }
};
const backingUp=updateUnderSaveLock({...args,sync:async()=>{}});
await reading.promise;
await assert.rejects(()=>withSaveLock(locks,rootName,()=>{}),/заняты/);
finishRead.resolve(); await backingUp; delete save.entries;
assert.equal(locks.held.size,0);

// Hold the actual transaction in sync and probe the real importer, export lock,
// picker and another update. All must refuse before changing storage.
const atSync=deferred(), finish=deferred();
const running=updateUnderSaveLock({...args,sync:async()=>{atSync.resolve(); await finish.promise;}});
await atSync.promise;
await assert.rejects(()=>withSaveLock(locks,rootName,()=>{}),/заняты/);
await assert.rejects(()=>importBackupZip(create=>root.getDirectoryHandle(rootName,{create}),locks,rootName,
  encodeBackup([{name:'slot',bytes:bytes('replace')}]),'replace',{root}),/заняты/);
let picked=false;
await assert.rejects(()=>withFreshGameDirectory(root,locks,rootName,()=>{picked=true;}),/заняты/);
await assert.rejects(()=>updateUnderSaveLock(args),/заняты/);
assert.equal(picked,false); assert.equal(text(save.files.get('slot').data),'progress');
finish.resolve(); await running; assert.equal(locks.held.size,0);

// The reverse direction is also serialized. A failed picker releases both
// locks and never reuses an existing installation.
const pickerRoot=new Dir(), pickerStarted=deferred(), pickerFinish=deferred();
const picker=withFreshGameDirectory(pickerRoot,locks,'picker-game',async()=>{pickerStarted.resolve(); await pickerFinish.promise;});
await pickerStarted.promise;
await assert.rejects(()=>updateUnderSaveLock({...fresh,root:pickerRoot,rootName:'picker-game'}),/заняты/);
pickerFinish.resolve(); await picker;
await assert.rejects(()=>withFreshGameDirectory(pickerRoot,locks,'picker-game',()=>{picked=true;}),/уже существует/);
assert.equal(picked,false); assert.equal(locks.held.size,0);

console.log('SAVE manifest update and picker serialization: PASS');
