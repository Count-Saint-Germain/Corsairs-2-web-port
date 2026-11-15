import assert from 'node:assert/strict';
import { withSaveLock } from '../web/save-export.mjs';
import { runExclusiveForPageLifetime, SaveLockBusyError } from '../web/save-owner.mjs';

// Cooperative in-memory lock model, exactly like the other save tests: it
// proves the ownership protocol and lock-name agreement, not browser unload,
// BFCache, crashes, pthreads, real OPFS or actual saves.
class Locks {
  held=new Set();
  async request(name,opts,fn) {
    assert.deepEqual(opts,{mode:'exclusive',ifAvailable:true});
    if(this.held.has(name))return fn(null);
    this.held.add(name);
    try{return await fn({name});}finally{this.held.delete(name);}
  }
}

// (a) One start captures the game root and never releases it: not on success,
// and not when the runtime (createPort) rejects after starting — that error
// comes back with runtimeStarted, marking the page as reload-only. Each Locks
// below is one page: a root that is already owned refuses any further start,
// so every case here needs its own fresh page.
let locks=new Locks(), started=0;
assert.equal(await runExclusiveForPageLifetime({locks,gameRoot:'game',
  startRuntime:async()=>{started++;return 42;}}),42);
assert.equal(started,1);
assert.deepEqual([...locks.held],['game:save-backup']);
locks=new Locks();
let portError;
try { await runExclusiveForPageLifetime({locks,gameRoot:'game',
  startRuntime:async()=>{throw Error('port failed');}}); }
catch (error) { portError=error; }
assert.match(portError.message,/port failed/);
assert.equal(portError.runtimeStarted,true);
assert.deepEqual([...locks.held],['game:save-backup']);

// (b) A second start on the same root refuses before its own startRuntime runs.
await assert.rejects(()=>runExclusiveForPageLifetime({locks,gameRoot:'game',
  startRuntime:async()=>{started++;}}),/заняты/);
assert.equal(started,1);

// (c) Netplay: both roots are captured before clearNet runs, and the runtime
// starts only after both captures and clearNet.
locks=new Locks();
const order=[];
await runExclusiveForPageLifetime({locks,gameRoot:'game',netRoot:'net-A',
  clearNet:async()=>order.push(...locks.held),
  startRuntime:async()=>order.push('start')});
assert.deepEqual(order,['game:save-backup','net-A:save-backup','start']);
assert.deepEqual([...locks.held].sort(),['game:save-backup','net-A:save-backup']);

// (d) A busy second capture rolls the first one back and runs neither clearNet
// nor startRuntime; a clearNet failure is likewise a pre-runtime rollback.
locks=new Locks(); started=0; let cleared=false;
const busy=withSaveLock(locks,'net-B',async()=>{ await new Promise(r=>setTimeout(r,0)); });
await assert.rejects(()=>runExclusiveForPageLifetime({locks,gameRoot:'game',netRoot:'net-B',
  clearNet:async()=>{cleared=true;},startRuntime:async()=>{started++;}}),/заняты/);
assert.equal(cleared,false); assert.equal(started,0);
assert.deepEqual([...locks.held],['net-B:save-backup']);   // only the busy holder remains
await busy;
assert.equal(locks.held.size,0);
await assert.rejects(()=>runExclusiveForPageLifetime({locks,gameRoot:'game',netRoot:'net',
  clearNet:async()=>{throw Error('clear failed');},startRuntime:async()=>{started++;}}),/clear failed/);
assert.equal(started,0); assert.equal(locks.held.size,0);

// (e) A busy refusal is a distinct error type, carries no runtimeStarted mark
// (the player may simply retry) and never reaches startRuntime. A fresh page
// is not busy, so the root must be owned first.
locks=new Locks(); started=0;
await runExclusiveForPageLifetime({locks,gameRoot:'game',startRuntime:async()=>{started++;}});
let busyError;
try { await runExclusiveForPageLifetime({locks,gameRoot:'game',startRuntime:async()=>{started++;}}); }
catch (error) { busyError=error; }
assert.ok(busyError instanceof SaveLockBusyError);
assert.equal(busyError.name,'SaveLockBusy');
assert.equal(busyError.runtimeStarted,undefined);
assert.equal(started,1);   // only the owning start ran
assert.deepEqual([...locks.held],['game:save-backup']);
await assert.rejects(()=>runExclusiveForPageLifetime({locks,gameRoot:'game',startRuntime:async()=>{started++;}}),
  e=>e instanceof SaveLockBusyError);
assert.equal(started,1);

// (f) While ownership is held, a real cooperating flow (the same save lock
// withSaveLock takes) refuses instead of racing the running game.
locks=new Locks();
await runExclusiveForPageLifetime({locks,gameRoot:'game',startRuntime:async()=>{}});
await assert.rejects(()=>withSaveLock(locks,'game',()=>{throw Error('must not run');}),/заняты/);

// Malformed arguments fail closed before any capture.
await assert.rejects(()=>runExclusiveForPageLifetime({locks}),/параметры/);
await assert.rejects(()=>runExclusiveForPageLifetime({locks,gameRoot:'game',netRoot:5,startRuntime:async()=>{}}),/параметры/);
await assert.rejects(()=>runExclusiveForPageLifetime({locks,gameRoot:'game'}),/параметры/);

console.log('save owner page-lifetime exclusivity (production module): PASS');
