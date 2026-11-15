#!/usr/bin/env node
/** Repair ENGINE's empty-path aref restore in generated C, with strict version checks. */
import { createHash, randomBytes } from 'node:crypto';
import * as fs from 'node:fs';
import * as path from 'node:path';
import { pathToFileURL } from 'node:url';

export const ENGINE_SHA256 = 'b57015514e19b6c1ea9411df7c010306d074abad367dedb43757924ceca83daa';
export const FUNCTION_SHA256 = '8f9f52921464ebb76c096f18d4591dad458150fd7e680f2d1613b98ef8c8495f';
export const ORIGINAL = '    if (c->zf) goto L_0040f60f; /* je 0x40f60f */';
export const FIXED = '    if (c->zf) { W32((uint32_t)(c->ebp + 0xffffff7cu), '
  + 'R32((uint32_t)(R32((uint32_t)(c->ebp + 0xffffff78u)) + 0x4cu))); '
  + 'goto L_0040f60f; } /* empty aref path: restore selected root */';
const functionPattern = /^void f_0040eefd\(CPU \*c\) \{[^\n]*\n[\s\S]*?^\}/gm;
const tracePattern = /^    trace_insn\(c, 0x[0-9a-f]+u\);\n/gm;
const count = (source, substring) => source.split(substring).length - 1;
export const digest = data => createHash('sha256').update(data).digest('hex');

/** Verify the entire known function, permitting instruction tracing only. */
export function fixFunction(source) {
  const normal = source.replace(tracePattern, '');
  if (count(normal, ORIGINAL) === 1) {
    if (digest(normal) !== FUNCTION_SHA256 || count(source, FIXED)) {
      throw new Error('unexpected unpatched aref restore function');
    }
    return { source: source.replace(ORIGINAL, FIXED), changed: true };
  }
  if (count(normal, FIXED) === 1) {
    const original = normal.replace(FIXED, ORIGINAL);
    if (digest(original) === FUNCTION_SHA256 && !count(source, ORIGINAL)) {
      return { source, changed: false };
    }
  }
  throw new Error('unknown or partially patched aref restore function');
}

/** Apply the verified fix to one regular C file using an atomic replacement. */
export function applyFixup(outDir, manifestPath, {engineSha256 = ENGINE_SHA256} = {}) {
  const resolvedManifest = fs.realpathSync(manifestPath);
  const data = JSON.parse(fs.readFileSync(resolvedManifest, 'utf8'));
  if (!Array.isArray(data.images)) throw new Error('manifest must contain an images array');
  const engines = data.images.filter(img => typeof img.guest === 'string' && img.guest.toLowerCase() === 'engine.exe');
  if (engines.length !== 1 || engines[0].tag !== 'recomp' || engines[0].base !== 0x400000 || typeof engines[0].path !== 'string') {
    throw new Error('ENGINE manifest identity or base differs');
  }
  const enginePath = path.resolve(path.dirname(resolvedManifest), engines[0].path);
  if (digest(fs.readFileSync(enginePath)) !== engineSha256) throw new Error('unsupported ENGINE.exe SHA-256');
  const found = [];
  for (const name of fs.readdirSync(outDir).filter(name => name.endsWith('.c')).sort()) {
    const file = path.join(outDir, name);
    const text = fs.readFileSync(file, 'utf8');
    for (const match of text.matchAll(functionPattern)) found.push({file, text, match});
  }
  if (found.length !== 1) throw new Error(`expected one translated aref restore function, found ${found.length}`);
  const {file, text, match} = found[0];
  const info = fs.lstatSync(file);
  if (!info.isFile() || info.isSymbolicLink()) throw new Error('translated aref restore source must be a regular file');
  const fixed = fixFunction(match[0]);
  if (fixed.changed) {
    const temp = path.join(path.dirname(file), `.${path.basename(file)}.aref-${randomBytes(12).toString('hex')}.tmp`);
    let fd;
    try {
      fd = fs.openSync(temp, 'wx', info.mode & 0o7777);
      fs.fchmodSync(fd, info.mode & 0o7777);
      fs.writeFileSync(fd, text.slice(0, match.index) + fixed.source + text.slice(match.index + match[0].length), 'utf8');
      fs.closeSync(fd);
      fd = undefined;
      fs.renameSync(temp, file);
    } finally {
      if (fd !== undefined) fs.closeSync(fd);
      try { fs.unlinkSync(temp); } catch (err) { if (err.code !== 'ENOENT') throw err; }
    }
  }
  return {file, changed: fixed.changed};
}

function main(args) {
  let out, manifest;
  for (let i = 0; i < args.length; i++) {
    if (args[i] === '--help' || args[i] === '-h') {
      console.log('Usage: node fix_root_aref.mjs --out <directory> --manifest <images.json>');
      return;
    }
    if ((args[i] === '--out' || args[i] === '--manifest') && i + 1 < args.length) {
      if (args[i++] === '--out') out = args[i]; else manifest = args[i];
    } else throw new Error(`unknown or incomplete argument: ${args[i]}`);
  }
  if (!out || !manifest) throw new Error('both --out and --manifest are required');
  const {file, changed} = applyFixup(out, manifest);
  console.log(`aref root restore: ${changed ? 'fixed' : 'already fixed'} (${file})`);
}

if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) {
  try { main(process.argv.slice(2)); }
  catch (err) { console.error(`aref fixup refused: ${err.message}`); process.exitCode = 1; }
}
