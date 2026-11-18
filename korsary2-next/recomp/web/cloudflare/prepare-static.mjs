#!/usr/bin/env node
// Prepare an isolated Workers Static Assets deployment from an existing build.
import { constants } from 'node:fs';
import { cp, mkdir, readFile, readdir, realpath, stat, unlink, writeFile } from 'node:fs/promises';
import path from 'node:path';
import { gzip } from 'node:zlib';
import { promisify } from 'node:util';

const [sourceArg, outputArg] = process.argv.slice(2);
if (!sourceArg || !outputArg || process.argv.length !== 4) throw Error('Usage: node prepare-static.mjs DISTRIBUTION NEW_OUTPUT_DIRECTORY');
const source = await realpath(sourceArg), output = path.resolve(outputArg);
const parent = await realpath(path.dirname(output));
const target = path.join(parent, path.basename(output));
const contains = (a,b) => a === b || b.startsWith(a + path.sep);
if (contains(source,target) || contains(target,source)) throw Error('Input and output must not overlap');
// Never copy or delete a user's saves, and fail before creating an output directory.
async function check(dir) {
  for (const entry of await readdir(dir,{withFileTypes:true})) {
    if (entry.isSymbolicLink()) throw Error(`Symlink in distribution: ${entry.name}`);
    if (entry.isDirectory()) {
      if (/^save(?:_meta|_tx)?$/i.test(entry.name)) throw Error(`Save directory in distribution: ${entry.name}`);
      await check(path.join(dir,entry.name));
    }
  }
}
await check(source);
const wasm = await readFile(path.join(source,'build/game.wasm'));
const compressed = await promisify(gzip)(wasm,{level:6});
if (compressed.length > 25 * 1024 * 1024) throw Error('Compressed WebAssembly exceeds the 25 MiB asset limit');
const pagePath = path.join(source,'port.js');
const page = await readFile(pagePath,'utf8');
const glue = await readFile(path.join(source,'build/game.js'),'utf8');
const binaryDeclaration='var wasmBinary;';
const binaryLoader='async function getWasmBinary(binaryFile) {';
if(glue.split(binaryDeclaration).length!==2 || glue.split(binaryLoader).length!==2)
  throw Error('Unexpected game.js runtime; refusing to patch');
const patchedGlue=glue.replace(binaryDeclaration,'var wasmBinary = Module["wasmBinary"];')
  .replace(binaryLoader,binaryLoader+'\n  if (wasmBinary) return wasmBinary;');
const anchor = '      const M = await createPort({\n';
if (page.split(anchor).length !== 2) throw Error('Unexpected port.js runtime; refusing to patch');
const binary = `      const wasmResponse = await fetch('build/game.wasm.gz.bin');\n      if (!wasmResponse.ok || !wasmResponse.body) throw new Error('WebAssembly download failed: HTTP ' + wasmResponse.status);\n      if (!globalThis.DecompressionStream) throw new Error('This browser cannot decompress the game runtime.');\n      const wasmBinary = new Uint8Array(await new Response(wasmResponse.body.pipeThrough(new DecompressionStream('gzip'))).arrayBuffer());\n`;
const patched = page.replace(anchor, binary + anchor + '        wasmBinary,\n')
  .replace("fetch('build/game.wasm', { method: 'HEAD' })", "fetch('build/game.wasm.gz.bin', { method: 'HEAD' })");
await mkdir(target); // exclusive: never overwrite an existing output
await cp(source,target,{recursive:true,mode:constants.COPYFILE_FICLONE,errorOnExist:true});
await writeFile(path.join(target,'port.js'),patched);
await writeFile(path.join(target,'build/game.js'),patchedGlue);
await unlink(path.join(target,'build/game.wasm'));
await writeFile(path.join(target,'build/game.wasm.gz.bin'),compressed,{flag:'wx'});
let count=0;
const sizes={};
async function validate(dir) {
  for(const e of await readdir(dir,{withFileTypes:true})) {
    const name=path.join(dir,e.name);
    if(e.isDirectory()) await validate(name);
    else if(e.isFile()) {
      count++;
      const size=(await stat(name)).size, relative=path.relative(target,name).split(path.sep).join('/');
      if(size>25*1024*1024) throw Error(`Asset exceeds 25 MiB: ${name}`);
      if (/^(?:game|game-en)\/_k2pack\//.test(relative) || relative.startsWith('videos/')) sizes['/'+relative]=size;
    }
  }
}
await validate(target);
if(count+1>20000) throw Error(`Too many static assets: ${count+1}`);
await writeFile(path.join(target,'_asset-sizes.json'),JSON.stringify(sizes),{flag:'wx'});
console.log(`Prepared ${count+1} static assets; WebAssembly ${(compressed.length/1e6).toFixed(1)} MB. Output: ${target}`);
