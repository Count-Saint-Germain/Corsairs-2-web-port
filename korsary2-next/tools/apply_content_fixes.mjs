#!/usr/bin/env node
/** Apply missing game-data fixes without replacing existing files. */
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import { fileURLToPath } from 'node:url';
import { assertNoSymlink } from './prepare_game_core.mjs';

export const FIXES = [
  { name: 'h_offic_hol', src: 'RESOURCE/MODELS/Heads/h_Offic_eng.gm', dst: 'RESOURCE/MODELS/Heads/h_Offic_hol.gm' },
  { name: 'h_offic_hol_ani', src: 'RESOURCE/animation/Heads/h_Offic_eng.ani', dst: 'RESOURCE/animation/Heads/h_Offic_hol.ani' },
];
export function ciExists(root, rel) {
  let current = root;
  for (const part of rel.split('/')) {
    let names;
    try { names = fs.readdirSync(current); }
    catch (error) { if (['ENOENT', 'ENOTDIR'].includes(error.code)) return null; throw error; }
    const hit = names.find((name) => name.toLowerCase() === part.toLowerCase());
    if (hit === undefined) return null;
    current = path.join(current, hit);
  }
  return current;
}
function sha(file) {
  const digest = crypto.createHash('sha256'), buffer = Buffer.allocUnsafe(1024 * 1024), fd = fs.openSync(file, 'r');
  try { for (;;) { const n = fs.readSync(fd, buffer, 0, buffer.length, null); if (!n) break; digest.update(buffer.subarray(0, n)); } }
  finally { fs.closeSync(fd); }
  return digest.digest('hex');
}
export function applyFixes(game, { dryRun = false, logger = console.log } = {}) {
  let rc = 0;
  for (const fix of FIXES) {
    const src = ciExists(game, fix.src);
    if (!src) { logger(`${fix.name}: SKIP, source ${fix.src} is missing`); rc = 1; continue; }
    if (ciExists(game, fix.dst)) { logger(`${fix.name}: already present`); continue; }
    const dst = path.join(path.dirname(src), path.posix.basename(fix.dst));
    assertNoSymlink(game, src); assertNoSymlink(game, dst);
    logger(`${fix.name}: add ${fix.dst} (copy of ${fix.src}, sha256 ${sha(src).slice(0, 12)})`);
    if (!dryRun) fs.copyFileSync(src, dst, fs.constants.COPYFILE_EXCL);
  }
  return rc;
}
export function main(argv = process.argv.slice(2)) {
  let game = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..', 'game'), dryRun = false;
  for (let i = 0; i < argv.length; i++) {
    if (argv[i] === '--dry-run') dryRun = true;
    else if (argv[i] === '--game' && i + 1 < argv.length) game = argv[++i];
    else if (argv[i] === '--help' || argv[i] === '-h') { console.log('usage: node apply_content_fixes.mjs [--game DIR] [--dry-run]'); return 0; }
    else throw new Error(`unknown or incomplete argument: ${argv[i]}`);
  }
  return applyFixes(path.resolve(game), { dryRun });
}
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  try { process.exitCode = main(); } catch (error) { console.error(error.message); process.exitCode = 1; }
}
