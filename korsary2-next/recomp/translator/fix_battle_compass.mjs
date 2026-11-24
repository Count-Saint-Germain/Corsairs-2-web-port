#!/usr/bin/env node
// The sea HUD writes 39 vertices (24 bytes each) into a 38-vertex buffer.
// Fix this one translated allocation, without changing other D3D buffers.
import { createHash } from 'node:crypto';
import fs from 'node:fs';
import path from 'node:path';
import { pathToFileURL } from 'node:url';

const dllHash = '2558e32bcdc1a6e7e07194b5f2a61e5790c2f4c42da897d2b24668d09949eea0';
const functionHash = 'c11ebea6771646fe2a27fae1fb80cf23e7df344f0f8acafa83c1b3ecdf35242e';
const original = '    { uint32_t v_ = 0x390u; PUSH32(c, v_); } /* push 0x390 */';
const fixed = '    { uint32_t v_ = 0x3a8u; PUSH32(c, v_); } /* sea HUD: 39 vertices, 24 bytes each */';
const hash = s => createHash('sha256').update(s).digest('hex');
const functionPattern = /^void f_00b6cab0\(CPU \*c\) \{[^\n]*\n[\s\S]*?^\}/gm;

export function fixFunction(fn) {
  const normal = fn.replace(/^    trace_insn\(c, 0x[0-9a-f]+u\);\n/gm, '');
  const isFixed = normal.includes(fixed);
  const unpatched = isFixed ? normal.replace(fixed, original) : normal;
  if (hash(unpatched) !== functionHash || unpatched.split(original).length !== 2 ||
      (isFixed && (normal.split(fixed).length !== 2 || normal.includes(original)))) {
    throw new Error('unexpected sea HUD allocation function');
  }
  return isFixed ? fn : fn.replace(original, fixed);
}

export function applyFix(outDir, manifestPath) {
  const manifest = path.resolve(manifestPath);
  const images = JSON.parse(fs.readFileSync(manifest, 'utf8')).images;
  const modules = images.filter(i => i.guest?.toLowerCase() === 'modules/battle_interface.dll');
  if (modules.length !== 1 || modules[0].base !== 0xb60000 || modules[0].tag !== 'MODULES_battle_interface' ||
      hash(fs.readFileSync(path.resolve(path.dirname(manifest), modules[0].path))) !== dllHash) {
    throw new Error('unsupported battle interface DLL');
  }
  const matches = [];
  for (const name of fs.readdirSync(outDir).filter(n => n.endsWith('.c'))) {
    const file = path.join(outDir, name), text = fs.readFileSync(file, 'utf8');
    for (const match of text.matchAll(functionPattern)) matches.push({file, text, match});
  }
  if (matches.length !== 1) throw new Error(`expected one sea HUD function, found ${matches.length}`);
  const {file, text, match} = matches[0];
  if (!fs.lstatSync(file).isFile() || fs.lstatSync(file).isSymbolicLink()) throw new Error('expected regular generated source');
  const newFunction = fixFunction(match[0]);
  if (newFunction !== match[0]) fs.writeFileSync(file, text.slice(0, match.index) + newFunction + text.slice(match.index + match[0].length));
  return newFunction !== match[0];
}

if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) {
  try {
    const args = process.argv.slice(2);
    if (args.length !== 4 || args[0] !== '--manifest' || args[2] !== '--out') throw new Error('usage: --manifest images.json --out directory');
    console.log(`sea HUD vertex allocation: ${applyFix(args[3], args[1]) ? 'fixed' : 'already fixed'}`);
  } catch (err) { console.error(`sea HUD fixup refused: ${err.message}`); process.exitCode = 1; }
}
