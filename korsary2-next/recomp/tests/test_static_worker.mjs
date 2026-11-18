import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { test } from 'node:test';

const source=await readFile(new URL('../web/cloudflare/static-worker.js',import.meta.url),'utf8');
const worker=(await import('data:text/javascript;base64,'+Buffer.from(source).toString('base64'))).default;
const asset=Uint8Array.from({length:20},(_,i)=>i);
const env={ASSETS:{fetch:async()=>new Response(asset,{headers:{'Content-Length':String(asset.length),'Content-Type':'application/octet-stream'}})}};
async function get(range) {return worker.fetch(new Request('https://example.test/game/x.pack',{headers:range?{Range:range}:{}}),env);}
test('returns the requested interval and preserves representation headers',async()=>{
  const r=await get('bytes=4-8');
  assert.equal(r.status,206);assert.equal(r.headers.get('Content-Range'),'bytes 4-8/20');
  assert.equal(r.headers.get('Content-Length'),'5');assert.deepEqual([...new Uint8Array(await r.arrayBuffer())],[4,5,6,7,8]);
});
test('supports suffix and open-ended ranges',async()=>{
  let r=await get('bytes=-3');assert.deepEqual([...new Uint8Array(await r.arrayBuffer())],[17,18,19]);
  r=await get('bytes=18-');assert.deepEqual([...new Uint8Array(await r.arrayBuffer())],[18,19]);
});
test('rejects unsatisfiable ranges and ignores invalid or absent ranges',async()=>{
  let r=await get('bytes=30-');assert.equal(r.status,416);assert.equal(r.headers.get('Content-Range'),'bytes */20');
  r=await get('bytes=1-2,4-5');assert.equal(r.status,200);assert.equal((await r.arrayBuffer()).byteLength,20);
  r=await get();assert.equal(r.status,200);
});
test('uses the generated size index when static assets omit Content-Length',async()=>{
  const noLength={ASSETS:{fetch:async(req)=>new URL(req.url).pathname==='/_asset-sizes.json'
    ? Response.json({'/game/x.pack':20}) : new Response(asset)}};
  const r=await worker.fetch(new Request('https://example.test/game/x.pack',{headers:{Range:'bytes=5-9'}}),noLength);
  assert.equal(r.status,206);assert.equal(r.headers.get('Content-Range'),'bytes 5-9/20');
  assert.deepEqual([...new Uint8Array(await r.arrayBuffer())],[5,6,7,8,9]);
});
test('does not forward Range to the asset service before slicing',async()=>{
  const sensitive={ASSETS:{fetch:async(req)=>{
    assert.equal(req.headers.get('Range'),null);
    return new Response(asset,{headers:{'Content-Length':'20'}});
  }}};
  const r=await worker.fetch(new Request('https://example.test/game/x.pack',{headers:{Range:'bytes=5-9'}}),sensitive);
  assert.deepEqual([...new Uint8Array(await r.arrayBuffer())],[5,6,7,8,9]);
});
test('rejects an incomplete upstream asset instead of sending a truncated range',async()=>{
  const truncated={ASSETS:{fetch:async()=>new Response(asset.subarray(0,10),{headers:{'Content-Length':'20'}})}};
  const r=await worker.fetch(new Request('https://example.test/game/x.pack',{headers:{Range:'bytes=5-9'}}),truncated);
  assert.equal(r.status,502);
});
