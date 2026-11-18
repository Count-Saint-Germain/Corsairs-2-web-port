import assert from 'node:assert/strict';
import { mkdtemp, mkdir, readFile, rm, writeFile } from 'node:fs/promises';
import os from 'node:os';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { gunzipSync } from 'node:zlib';
import { test } from 'node:test';
import { fileURLToPath } from 'node:url';

const script=fileURLToPath(new URL('../web/cloudflare/prepare-static.mjs',import.meta.url));
test('prepares compressed runtime and size index without changing the source',async()=>{
  const temp=await mkdtemp(path.join(os.tmpdir(),'k2-static-test-'));
  try {
    const src=path.join(temp,'src'), out=path.join(temp,'out');
    await mkdir(path.join(src,'build'),{recursive:true});
    await mkdir(path.join(src,'game/_k2pack'),{recursive:true});
    await writeFile(path.join(src,'build/game.wasm'),Buffer.from('runtime'));
    await writeFile(path.join(src,'build/game.js'),'var wasmBinary;\nasync function getWasmBinary(binaryFile) {}');
    await writeFile(path.join(src,'port.js'),"      const M = await createPort({\nfetch('build/game.wasm', { method: 'HEAD' })");
    await writeFile(path.join(src,'game/_k2pack/a.pack'),'12345');
    const run=()=>spawnSync(process.execPath,[script,src,out],{encoding:'utf8'});
    const result=run(); assert.equal(result.status,0,result.stderr);
    assert.equal(gunzipSync(await readFile(path.join(out,'build/game.wasm.gz.bin'))).toString(),'runtime');
    assert.equal((await readFile(path.join(src,'build/game.wasm'))).toString(),'runtime');
    assert.equal(JSON.parse(await readFile(path.join(out,'_asset-sizes.json'),'utf8'))['/game/_k2pack/a.pack'],5);
    assert.match(await readFile(path.join(out,'build/game.js'),'utf8'),/Module\["wasmBinary"\]/);
    assert.match(await readFile(path.join(out,'port.js'),'utf8'),/DecompressionStream/);
    assert.notEqual(run().status,0,'existing output must never be overwritten');
  } finally { await rm(temp,{recursive:true,force:true}); }
});
test('rejects a save directory before creating the output',async()=>{
  const temp=await mkdtemp(path.join(os.tmpdir(),'k2-static-save-test-'));
  try {
    const src=path.join(temp,'src'),out=path.join(temp,'out');await mkdir(path.join(src,'SAVE'),{recursive:true});
    const result=spawnSync(process.execPath,[script,src,out],{encoding:'utf8'});
    assert.notEqual(result.status,0);assert.match(result.stderr,/Save directory/);
  } finally { await rm(temp,{recursive:true,force:true}); }
});
