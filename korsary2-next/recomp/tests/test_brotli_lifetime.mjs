import test from 'node:test';
import assert from 'node:assert/strict';
import { spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { brotliCompressSync } from 'node:zlib';
import { loadBrotliDecoder } from '../web/brotli-decoder.mjs';

const deadline = (promise, message) => Promise.race([
  promise,
  new Promise((_, reject) => { const timer = setTimeout(() => reject(new Error(message)), 2000); timer.unref(); }),
]);
const yieldTurn = () => new Promise(resolve => setTimeout(resolve, 15));

async function verifyLifetime() {
  const decoder = await loadBrotliDecoder();
  // The incomplete first part keeps a real decoder context open across GC.
  const bytes = Buffer.alloc(700000);
  for (let i=0;i<bytes.length;i++) bytes[i]=(i*17+(i>>8))&255;
  const compressed = brotliCompressSync(bytes);
  // heapUsed is the allocator high-water mark, not the amount currently live.
  const warm=decoder.createStream({maxOutput:bytes.length});
  const warmWriter=warm.writable.getWriter(),warmReader=warm.readable.getReader();
  const warmDone=(async()=>{await warmWriter.write(compressed);await warmWriter.close();})();
  while (!(await warmReader.read()).done) {}
  await warmDone;
  const baseline=decoder.heapUsed();
  let stream = decoder.createStream({maxOutput: bytes.length});
  const writer=stream.writable.getWriter(), reader=stream.readable.getReader();
  stream=null;
  const initialWrite=writer.write(compressed.subarray(0,Math.ceil(compressed.length/2)));
  const first=await deadline(reader.read(),'initial read blocked');
  assert.equal(first.done,false);
  await deadline(initialWrite,'initial write blocked');
  assert.ok(decoder.heapUsed()>=baseline, 'the partial stream must allocate a context');
  for(let i=0;i<20;i++) { global.gc(); await yieldTurn(); }
  assert.ok(decoder.heapUsed()>=baseline,'allocator mark must stay valid while the stream is live');
  const chunks=[Buffer.from(first.value)];
  const finish=(async()=>{await writer.write(compressed.subarray(Math.ceil(compressed.length/2)));await writer.close();})();
  for(;;) { const r=await deadline(reader.read(),'remaining read blocked');if(r.done)break;chunks.push(Buffer.from(r.value)); }
  await deadline(finish,'stream close blocked');
  assert.deepEqual(Buffer.concat(chunks),bytes);
  assert.equal(decoder.heapUsed(),baseline,'normal close must not grow the warmed allocator');

  // A blocked write must not prevent an explicit abort or readable cancellation.
  for(const mode of ['abort','cancel']) {
    const s=decoder.createStream({maxOutput: bytes.length}),w=s.writable.getWriter(),r=s.readable.getReader();
    const pending=w.write(compressed).then(()=>null,e=>e);
    await yieldTurn(); // let the write reach readable backpressure
    if(mode==='abort') await deadline(w.abort('stop'),'abort blocked behind pending write');
    else await deadline(r.cancel('stop'),'cancel blocked behind pending write');
    assert.ok(await deadline(pending,'pending write did not settle'));
    await deadline(w.abort('again'),'repeated abort blocked');
    assert.equal(decoder.heapUsed(),baseline,`${mode} must release the context`);
  }

  // A very small compressed input expands to many blocks: the write must stay
  // pending until the consumer reads, instead of queuing the whole 32 MiB.
  const zeros = Buffer.alloc(32 * 1024 * 1024), tiny = brotliCompressSync(zeros);
  assert.ok(tiny.length < 128);
  for (const cancelAfterFirst of [false, true]) {
    const s=decoder.createStream({maxOutput:zeros.length}), w=s.writable.getWriter(), r=s.readable.getReader();
    let settled=false;
    const pending=w.write(tiny).then(() => {settled=true;return null;}, e => {settled=true;return e;});
    const first=await deadline(r.read(),'backpressure first read blocked');
    assert.equal(first.value.length,256 * 1024);
    await yieldTurn();
    assert.equal(settled,false,'compressed write completed before the consumer accepted remaining output');
    if (cancelAfterFirst) {
      await deadline(r.cancel('stop'),'cancel of backpressured output blocked');
      assert.ok(await deadline(pending,'write did not stop after backpressured cancel'));
      await deadline(w.abort('again'),'abort after cancel blocked');
    } else {
      const finish=pending.then(e=>{if(e)throw e;return w.close();});
      let count=first.value.length;
      for (;;) {const part=await deadline(r.read(),'backpressure read blocked');if(part.done)break;count+=part.value.length;assert.ok(part.value.every(b=>b===0));}
      await deadline(finish,'backpressure stream close blocked');
      assert.equal(count,zeros.length);
    }
  }
}
if (process.env.K2_BROTLI_GC_CHILD === '1') {
  await verifyLifetime();
} else {
  test('Brotli preserves live contexts, backpressure and abort/cancel', () => {
    const run=spawnSync(process.execPath,['--expose-gc',fileURLToPath(import.meta.url)],{
      env:{...process.env,K2_BROTLI_GC_CHILD:'1'},encoding:'utf8',timeout:20000,
    });
    assert.equal(run.status,0,run.stderr||run.error?.message||run.stdout);
  });
}
