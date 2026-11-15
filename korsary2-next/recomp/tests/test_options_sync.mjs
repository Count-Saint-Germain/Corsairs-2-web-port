import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import {syncManifestFiles, updateUnderSaveLock, fetchVerifiedOptions} from '../web/save-protection.mjs';

const missing = () => Object.assign(new Error('missing'), {name:'NotFoundError'});
const sha = s => createHash('sha256').update(s).digest('hex');
const entry = (path, data) => ({path, size:Buffer.byteLength(data), sha256:sha(data)});
class Game {
  constructor() {this.files = new Map(); this.error = null;}
  async *entries() {
    if (this.error) throw this.error;
    for (const [name] of this.files) yield [name, await this.getFileHandle(name)];
  }
  async getFileHandle(name) {
    if (!this.files.has(name)) throw missing();
    const self=this;
    return {kind:'file', async getFile() {return new Blob([self.files.get(name)]);}};
  }
  async getDirectoryHandle() {throw missing();}
}
function harness(game, initialMarker=null) {
  const root={async getDirectoryHandle(name){if(name!=='test-game') throw missing(); return game;}};
  const locks={async request(name, options, fn){return fn({name});}};
  let marker=initialMarker, markerWrites=0, downloads=[], progress=[], optionsFetches=0;
  const existingSize=async (dir,path) => dir.files.has(path) ? Buffer.byteLength(dir.files.get(path)) : -1;
  async function update(manifest, payloads) {
    return updateUnderSaveLock({root,locks,rootName:'test-game',version:manifest.version,
      readMarker:async()=>marker,
      sync:()=>syncManifestFiles({dir:game, files:manifest.files, hadMarker:!!marker?.version, version:manifest.version,
        existingSize,
        async downloadFile(dir,path,size,from,onBytes) {
          downloads.push(path); const data=payloads[path];
          assert.equal(from,0); assert.equal(Buffer.byteLength(data),size);
          dir.files.set(path,data); onBytes(size);
        },
        async downloadOptionsFile(dir, entry, onBytes) {
          const data=payloads.options; optionsFetches++;
          const bytes=await fetchVerifiedOptions('https://example.test/options',entry,async()=>new Response(data));
          downloads.push('options'); dir.files.set('options',new TextDecoder().decode(bytes)); onBytes(bytes.length);
        },
        async writeMarker(version){marker={version}; markerWrites++;},
        show(done){progress.push(done);}, async sleep(){},
      })});
  }
  return {update, get marker(){return marker;}, get markerWrites(){return markerWrites;}, get downloads(){return downloads;}, get progress(){return progress;}, get optionsFetches(){return optionsFetches;}};
}
const source={options:'default', 'data.c':'one'};
const first={version:'v1',files:[entry('data.c',source['data.c']),entry('SAVE/private','not an asset'),entry('options',source.options)]};
const game=new Game(), h=harness(game);
await h.update(first,source);
assert.deepEqual(h.downloads,['data.c','options']); assert.equal(h.marker.version,'v1');
assert.equal(game.files.get('options'),'default'); assert.equal(h.progress.at(-1),10);
assert.equal(game.files.has('SAVE/private'),false);

// The same actual locked update loop keeps mutable settings when another
// manifest asset changes, rather than downloading or hashing options again.
game.files.set('options','controls=key_g');
const second={version:'v2',files:[entry('data.c','two'),entry('sAvE/private','not an asset'),entry('options',source.options)]};
await h.update(second,{...source,'data.c':'two'});
assert.equal(game.files.get('options'),'controls=key_g'); assert.equal(game.files.get('data.c'),'two');
assert.equal(game.files.has('sAvE/private'),false);
assert.deepEqual(h.downloads,['data.c','options','data.c']); assert.equal(h.marker.version,'v2');
assert.equal(h.optionsFetches,1); // update never fetched replacement options

// Loss of marker after complete default options was downloaded: verify exact
// bytes, keep them and finish installation without writing options a second time.
const unfinished=new Game(); unfinished.files.set('options','default');
const resumed=harness(unfinished);
await resumed.update(first,source);
assert.deepEqual(resumed.downloads,['data.c']); assert.equal(unfinished.files.get('options'),'default');
assert.equal(resumed.marker.version,'v1');

// A missing marker and modified/partial options is ambiguous. Fail before any
// asset download or marker write, regardless of manifest order.
const ambiguous=new Game(); ambiguous.files.set('options','user or incomplete');
const blocked=harness(ambiguous);
await assert.rejects(()=>blocked.update(first,source),/без подтверждения установки/);
assert.equal(ambiguous.files.get('options'),'user or incomplete');
assert.deepEqual(blocked.downloads,[]); assert.equal(blocked.markerWrites,0);

// Reject nested options even when no root options is listed; never create the
// directory or write preceding valid assets. Directory read errors fail closed.
for (const bad of ['OPTIONS/child','options/child']) {
  const d=new Game(), x=harness(d, {version:'old'});
  await assert.rejects(()=>x.update({version:'v2',files:[entry('data.c','two'),entry(bad,'bad')]},{'data.c':'two',[bad]:'bad'}),/Вложенные/);
  assert.equal(d.files.size,0); assert.equal(x.marker.version,'old'); assert.deepEqual(x.downloads,[]);
}
const failed=new Game(); failed.error=Error('access denied'); const denied=harness(failed,{version:'old'});
await assert.rejects(()=>denied.update(second,source),/access denied/);
assert.equal(failed.files.size,0); assert.equal(denied.marker.version,'old');
// A same-size incorrect fresh-install reply is rejected before the destination
// exists; with an old marker and no settings, the update refuses even earlier.
for (const initialMarker of [null,{version:'old'}]) {
  const d=new Game(), x=harness(d,initialMarker);
  const m={version:'bad-v',files:[entry('options','default')]};
  await assert.rejects(()=>x.update(m,{options:'wrong!!'}), initialMarker ? /отсутствует файл настроек/ : /SHA-256/);
  assert.equal(d.files.has('options'),false); assert.equal(x.markerWrites,0);
  assert.deepEqual(x.marker,initialMarker); assert.deepEqual(x.downloads,[]);
  assert.equal(x.optionsFetches,initialMarker ? 0 : 4);
}
const nohash=new Game(), nh=harness(nohash,{version:'old'});
await assert.rejects(()=>nh.update({version:'v2',files:[{path:'options',size:7}]},{options:'default'}),/манифесте/);
assert.equal(nohash.files.size,0); assert.equal(nh.markerWrites,0);
console.log('locked manifest sync: initial install, update, resume, integrity failure and nested paths PASS');
