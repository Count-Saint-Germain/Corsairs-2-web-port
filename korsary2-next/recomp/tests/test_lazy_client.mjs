import test from 'node:test';
import assert from 'node:assert/strict';
import { startLazyClient, isTransientLazyError } from '../web/experimental/lazy-client.mjs';

function fixture() {
  const memory = new WebAssembly.Memory({initial: 1, maximum: 1, shared: true});
  let pending = null, current = 0, freed = 0;
  const completed = [];
  const M = { wasmMemory: memory, _malloc: () => 16, _free: () => { freed++; },
    _port_lazy_poll(ptr) {
      if (!pending) return 0;
      const { token, path } = pending; pending = null; current = token;
      const bytes = new TextEncoder().encode(path + '\0');
      new Uint8Array(memory.buffer, ptr, bytes.length).set(bytes);
      return token;
    },
    _port_lazy_current: token => token === current,
    _port_lazy_finish(token, status) { if (token === current) { completed.push([token, status]); current = 0; } },
  };
  return { M, completed, set(path, token=1) { pending = {path, token}; }, expire() { current = 0; }, get freed() { return freed; } };
}
async function waitFor(predicate) {
  const end = Date.now() + 2000;
  while (!predicate()) {
    if (Date.now() >= end) throw new Error('timed out');
    await new Promise(resolve => setTimeout(resolve, 5));
  }
}
const file = {path:'RESOURCE/Textures/test.tx', size:2, sha256:'a'.repeat(64)};

test('a canonical immutable manifest entry is installed before signalling completion', async () => {
  const f=fixture(), seen=[]; f.set(file.path);
  const c=startLazyClient({M:f.M, files:[file], install:async(entry,{signal})=>{seen.push([entry,signal.aborted]);}, intervalMs:1});
  try { await waitFor(()=>f.completed.length); assert.deepEqual(seen, [[file,false]]); assert.deepEqual(f.completed,[[1,1]]);
    assert.deepEqual(c.stats,{requested:1,installed:1,failed:0,unpackedBytes:2,recordBytes:2}); }
  finally { c.stop(); c.stop(); }
  assert.equal(f.freed,1);
});
test('unknown and mutable paths never reach the installer', async () => {
  for (const path of ['SAVE/slot','OPTIONS','RESOURCE/Textures/unknown.tx']) {
    const f=fixture(), errors=[]; let calls=0; f.set(path);
    const c=startLazyClient({M:f.M, files:[file,{path:'SAVE/slot'},{path:'options'}], install:async()=>calls++, onError:e=>errors.push(e), intervalMs:1});
    try { await waitFor(()=>f.completed.length); assert.equal(calls,0); assert.deepEqual(f.completed,[[1,0]]); assert.equal(errors.length,1); }
    finally { c.stop(); }
  }
});
test('an expired token aborts outstanding transfer and never completes a newer request', async () => {
  const f=fixture(); f.set(file.path); let signal;
  const c=startLazyClient({M:f.M, files:[file], intervalMs:1, install:(_,{signal:s})=>new Promise((resolve,reject)=>{
    signal=s; s.addEventListener('abort',()=>reject(new Error('aborted')), {once:true});
  })});
  try { await waitFor(()=>signal); f.expire(); await waitFor(()=>signal.aborted); assert.deepEqual(f.completed,[]); }
  finally { c.stop(); }
});
test('a late successful transfer cannot hide an expired guest request',async()=>{
  const f=fixture();f.set(file.path);let complete,expired=0,results=[];
  const c=startLazyClient({M:f.M,files:[file],intervalMs:1,
    install:()=>new Promise(resolve=>{complete=resolve;}),onExpired:()=>expired++,onResult:r=>results.push(r.status)});
  try {await waitFor(()=>complete);f.expire();complete();await waitFor(()=>expired);
    assert.deepEqual(f.completed,[]);assert.deepEqual(results,['failed']);assert.equal(c.stats.installed,0);}
  finally {c.stop();}
});
test('stopping during a transfer rejects the current request and releases memory', async () => {
  const f=fixture(); f.set(file.path); let signal;
  const c=startLazyClient({M:f.M,files:[file],intervalMs:1,install:(_,{signal:s})=>new Promise((resolve,reject)=>{
    signal=s; s.addEventListener('abort',()=>reject(new Error('aborted')), {once:true});
  })});
  await waitFor(()=>signal); c.stop(); await waitFor(()=>signal.aborted);
  assert.deepEqual(f.completed,[[1,0]]); assert.equal(f.freed,1);
});
test('a busy native mutex retries the completion without blocking or losing it', async () => {
  const f=fixture();f.set(file.path);let tries=0;
  const complete=f.M._port_lazy_finish;
  f.M._port_lazy_finish=(token,status)=>{if(++tries<4)return -1;return complete(token,status);};
  const c=startLazyClient({M:f.M,files:[file],intervalMs:1,install:async()=>{}});
  try { await waitFor(()=>f.completed.length); assert.deepEqual(f.completed,[[1,1]]); assert.equal(tries,4); }
  finally { c.stop(); }
});
test('integrity errors fail the request, are reported, and permit a later retry', async () => {
  for (const message of ['HTTP 404', 'SHA-256 mismatch']) {
    const f=fixture(), errors=[];f.set(file.path);let attempts=0;
    const c=startLazyClient({M:f.M, files:[file], intervalMs:1, onError:e=>errors.push(e.message),
      install:async()=>{if(++attempts===1)throw new Error(message);}});
    try {
      await waitFor(()=>f.completed.length===1);
      assert.deepEqual(f.completed,[[1,0]]);assert.deepEqual(errors,[message]);
      f.set(file.path,2);await waitFor(()=>f.completed.length===2);
      assert.deepEqual(f.completed,[[1,0],[2,1]]);
      assert.equal(c.stats.failed,1);assert.equal(c.stats.installed,1);
    } finally { c.stop(); }
  }
});

test('transient network and server errors retry before reporting completion',async()=>{
  for (const first of [new TypeError('Failed to fetch'), new Error('pack: HTTP 503')]) {
    const f=fixture(), retries=[], errors=[], events=[];f.set(file.path);let attempts=0;
    const c=startLazyClient({M:f.M,files:[file],intervalMs:1,retryDelaysMs:[1,1],
      onStart:()=>{events.push('start');throw new Error('UI error');},
      onRetry:r=>{events.push('retry');retries.push(r);},onResult:()=>events.push('result'),onError:e=>errors.push(e),
      install:async()=>{if(++attempts===1)throw first;}});
    try {
      await waitFor(()=>f.completed.length);assert.equal(attempts,2);assert.deepEqual(f.completed,[[1,1]]);
      assert.equal(retries.length,1);assert.equal(retries[0].attempt,1);assert.equal(retries[0].maxAttempts,3);
      assert.deepEqual(events,['start','retry','result']);assert.equal(errors.length,0);assert.equal(c.stats.failed,0);
    } finally {c.stop();}
  }
});

test('retry attempts are bounded, while integrity and quota failures do not retry',async()=>{
  for(const [error,expected] of [[new Error('HTTP 503'),3],
    [Object.assign(new Error('SHA-256 mismatch'),{name:'TransferIntegrityError'}),1],
    [Object.assign(new Error('full'),{name:'QuotaExceededError'}),1], [new Error('HTTP 404'),1]]) {
    const f=fixture(), errors=[];f.set(file.path);let attempts=0;
    const c=startLazyClient({M:f.M,files:[file],intervalMs:1,retryDelaysMs:[1,1],onError:e=>errors.push(e),install:async()=>{attempts++;throw error;}});
    try {await waitFor(()=>f.completed.length);assert.equal(attempts,expected);assert.equal(errors.length,1);assert.deepEqual(f.completed,[[1,0]]);}
    finally {c.stop();}
  }
});

test('expired token cancels pending backoff without another network request',async()=>{
  const f=fixture();f.set(file.path);let attempts=0,retries=0;
  const c=startLazyClient({M:f.M,files:[file],intervalMs:1,retryDelaysMs:[200],onRetry:()=>retries++,onError:()=>{},
    install:async()=>{attempts++;throw new Error('HTTP 503');}});
  try {await waitFor(()=>retries===1);f.expire();await new Promise(resolve=>setTimeout(resolve,60));assert.equal(attempts,1);assert.deepEqual(f.completed,[]);}
  finally {c.stop();}
});

test('exhausted transient failure stays pending and explicit retry resumes the same request',async()=>{
  const f=fixture();f.set(file.path);let attempts=0,prompt,expired=0;
  const c=startLazyClient({M:f.M,files:[file],intervalMs:1,retryDelaysMs:[1],
    install:async()=>{if(++attempts<=2)throw new Error('HTTP 503');},
    onExhausted:choice=>{prompt=choice;},onExpired:()=>expired++,onError:e=>{throw e;}});
  try {
    await waitFor(()=>prompt);assert.equal(attempts,2);assert.deepEqual(f.completed,[]);
    assert.equal(prompt.retry(),true);assert.equal(prompt.retry(),false);assert.equal(prompt.cancel(),false);
    await waitFor(()=>f.completed.length);assert.deepEqual(f.completed,[[1,1]]);assert.equal(attempts,3);
    assert.equal(expired,0);assert.equal(c.stats.failed,0);
  } finally {c.stop();}
});

test('cancel or an expired token ends a prompt without a stale retry',async()=>{
  for (const cancel of [true,false]) {
    const f=fixture();f.set(file.path);let prompt,attempts=0,errors=0,expired=0;
    const c=startLazyClient({M:f.M,files:[file],intervalMs:1,retryDelaysMs:[],
      install:async()=>{attempts++;throw new Error('HTTP 503');},onExhausted:p=>{prompt=p;},
      onError:()=>errors++,onExpired:()=>expired++});
    try {
      await waitFor(()=>prompt);
      if (cancel) {prompt.cancel();await waitFor(()=>f.completed.length);assert.deepEqual(f.completed,[[1,0]]);assert.equal(errors,1);}
      else {f.expire();await waitFor(()=>expired);assert.deepEqual(f.completed,[]);assert.equal(errors,0);}
      assert.equal(prompt.retry(),false);assert.equal(attempts,1);
    } finally {c.stop();}
  }
});

test('fatal integrity or quota errors never offer a retry prompt',async()=>{
  for (const name of ['TransferIntegrityError','QuotaExceededError']) {
    const f=fixture();f.set(file.path);let prompts=0;
    const c=startLazyClient({M:f.M,files:[file],intervalMs:1,retryDelaysMs:[],onError:()=>{},
      onExhausted:()=>prompts++,install:async()=>{throw Object.assign(new Error('HTTP 503'),{name});}});
    try {await waitFor(()=>f.completed.length);assert.equal(prompts,0);assert.deepEqual(f.completed,[[1,0]]);}
    finally {c.stop();}
  }
});

test('transient classification excludes cancellation, storage and integrity errors',()=>{
  assert.equal(isTransientLazyError(new Error('HTTP 503')),true);
  assert.equal(isTransientLazyError(new TypeError('Failed to fetch')),true);
  for(const error of [Object.assign(new Error('HTTP 503'),{name:'AbortError'}),Object.assign(new Error('HTTP 503'),{name:'QuotaExceededError'}),
    Object.assign(new Error('HTTP 503'),{name:'TransferIntegrityError'}),new TypeError('unexpected undefined'),new Error('HTTP 404')])
    assert.equal(isTransientLazyError(error),false);
});
