import test from 'node:test';
import assert from 'node:assert/strict';
import {updateUnderSaveLock} from '../web/save-protection.mjs';
import {runExclusiveForPageLifetime} from '../web/save-owner.mjs';
class Locks {
  held=new Set();
  async request(name, options, callback) {
    assert.deepEqual(options,{mode:'exclusive',ifAvailable:true});
    if(this.held.has(name)) return callback(null);
    this.held.add(name);try{return await callback({name});}finally{this.held.delete(name);}
  }
}
const deferred=()=>{let resolve; const promise=new Promise(r=>resolve=r);return {promise,resolve};};

test('bootstrap, index and runtime share one lock; isolated userdata has a second lifetime lock',async()=>{
  const locks=new Locks(), entered=deferred(), finish=deferred(), writes=[];
  const rootName='game-lazy-experiment', userdata=rootName+'-userdata';
  const root={getDirectoryHandle:async()=>{throw Object.assign(new Error('missing'),{name:'NotFoundError'});}};
  let marker=null;
  const args={root,locks,rootName,version:'lazy-v1',readMarker:async()=>marker,sync:async()=>{
    writes.push('bootstrap');entered.resolve();await finish.promise;marker={version:'lazy-v1'};
  }};
  const installing=updateUnderSaveLock(args);
  await entered.promise;
  await assert.rejects(runExclusiveForPageLifetime({locks,gameRoot:rootName,netRoot:userdata,beforeStart:async()=>writes.push('index'),startRuntime:async()=>writes.push('run')}),/заняты/);
  assert.deepEqual(writes,['bootstrap']);
  finish.resolve();await installing;
  await runExclusiveForPageLifetime({locks,gameRoot:rootName,netRoot:userdata,clearNet:async()=>{},beforeStart:async()=>{
    assert.equal(locks.held.has(rootName+':save-backup'),true);
    assert.equal(locks.held.has(userdata+':save-backup'),true);
    writes.push('index');
  },startRuntime:async()=>writes.push('run')});
  assert.deepEqual(writes,['bootstrap','index','run']);
  await assert.rejects(updateUnderSaveLock(args),/заняты/);
  assert.deepEqual(writes,['bootstrap','index','run']);
});
