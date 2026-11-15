#!/usr/bin/env node
/** Reproducibly prepare a game working copy from a read-only repack. */
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { spawn, spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { ciResolve, listFiles, isProtected, sha256File, installNew, stepPatches, verify, assertNoSymlink } from './prepare_game_core.mjs';
import { applyFixes } from './apply_content_fixes.mjs';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const NEXT = path.dirname(HERE), DEFAULT_PATCH_DIR = path.join(NEXT, 'content-patches');
const WORK_GAME = path.resolve(NEXT, '..', 'korsary2-work', 'game');
const MB = 1024 * 1024;
const ITEMS_PAIRS = [['RESOURCE/MODELS/Ammo', 'RESOURCE/MODELS/Items'], ['RESOURCE/Textures/Ammo', 'RESOURCE/Textures/Items']];
const has = (p) => { try { return fs.lstatSync(p); } catch (e) { if (e.code === 'ENOENT') return null; throw e; } };
const log = (text) => console.log(text);
const fmtMB = (n) => `${Math.round(n / MB)} MB`;
function inside(parent, child) {
  const rel = path.relative(parent, child);
  return rel === '' || (rel !== '..' && !rel.startsWith(`..${path.sep}`) && !path.isAbsolute(rel));
}
function realEvenMissing(file) {
  let p = path.resolve(file), rest = [];
  while (!has(p)) { const next = path.dirname(p); if (next === p) throw new Error(`cannot resolve path: ${file}`); rest.unshift(path.basename(p)); p = next; }
  return path.join(fs.realpathSync(p), ...rest);
}
function executable(name) {
  const extensions = process.platform === 'win32' ? (process.env.PATHEXT || '.EXE;.CMD;.BAT').split(';') : [''];
  for (const dir of (process.env.PATH || '').split(path.delimiter)) for (const ext of extensions) {
    const full = path.join(dir || '.', name + ext);
    try { fs.accessSync(full, fs.constants.X_OK); if (fs.statSync(full).isFile()) return full; } catch { /* try next */ }
  }
  return null;
}
function version(exe) {
  if (!exe) return '';
  const result = spawnSync(exe, ['-version'], { encoding: 'utf8', timeout: 30000 });
  return (result.stdout || '').split('\n')[0];
}
function run(binary, args, { binaryOutput = false } = {}) {
  return new Promise((resolve, reject) => {
    const p = spawn(binary, args, { stdio: ['ignore', 'pipe', 'pipe'] });
    const output = [], errors = []; let length = 0;
    p.stdout.on('data', (b) => { length += b.length; if (length > 256 * MB) p.kill(); else output.push(b); });
    p.stderr.on('data', (b) => errors.push(b));
    p.once('error', reject);
    p.once('close', (code, signal) => {
      if (code !== 0 || signal) return reject(new Error(`${binary} failed (${signal || code}): ${Buffer.concat(errors).toString('utf8').slice(-400)}`));
      const buf = Buffer.concat(output); resolve(binaryOutput ? buf : buf.toString('utf8'));
    });
  });
}
export async function oggToWavBytes(ffmpeg, ffprobe, source) {
  const info = JSON.parse(await run(ffprobe, ['-v', 'error', '-select_streams', 'a:0', '-show_entries', 'stream=sample_rate,channels', '-of', 'json', source]));
  const stream = info.streams[0], rate = Number(stream.sample_rate), channels = Number(stream.channels);
  if (!Number.isInteger(rate) || !Number.isInteger(channels) || rate <= 0 || channels <= 0 || channels > 0xffff) throw new Error(`invalid audio format: ${source}`);
  const pcm = await run(ffmpeg, ['-v', 'error', '-nostdin', '-y', '-i', source, '-map', '0:a:0', '-c:a', 'pcm_s16le', '-f', 's16le', '-'], { binaryOutput: true });
  if (pcm.length % (channels * 2)) throw new Error(`incomplete PCM frame: ${source}`);
  const header = Buffer.alloc(44);
  header.write('RIFF', 0); header.writeUInt32LE(pcm.length + 36, 4); header.write('WAVEfmt ', 8); header.writeUInt32LE(16, 16); header.writeUInt16LE(1, 20); header.writeUInt16LE(channels, 22);
  header.writeUInt32LE(rate, 24); header.writeUInt32LE(rate * channels * 2, 28); header.writeUInt16LE(channels * 2, 32); header.writeUInt16LE(16, 34); header.write('data', 36); header.writeUInt32LE(pcm.length, 40);
  return Buffer.concat([header, pcm]);
}
export function stepItems(out, dry = false) {
  const result = { copied: [], present: 0 };
  for (const [srcRel, dstRel] of ITEMS_PAIRS) {
    const src = ciResolve(out, srcRel), dst = ciResolve(out, dstRel);
    if (!src || !dst) throw new Error(`missing directory: ${!src ? srcRel : dstRel}`);
    assertNoSymlink(out, src); assertNoSymlink(out, dst);
    const have = new Set(fs.readdirSync(dst).map((n) => n.toLowerCase()));
    for (const name of fs.readdirSync(src).sort()) {
      const source = path.join(src, name);
      if (name.toLowerCase() === '.ds_store' || !fs.statSync(source).isFile()) continue;
      const outputName = name.toLowerCase() === 'blade6.tga.tx' ? 'Blade6.tga.tx' : name;
      if (have.has(outputName.toLowerCase())) { result.present++; continue; }
      const target = path.join(dst, outputName);
      if (!dry && !installNew(target, { source })) { result.present++; continue; }
      result.copied.push(path.relative(out, target).split(path.sep).join('/'));
    }
  }
  log(`  Items from Ammo: copied ${result.copied.length}, already present ${result.present}`);
  return result;
}
export function wavJobs(out) {
  const sounds = ciResolve(out, 'RESOURCE/Sounds');
  if (!sounds) throw new Error('missing RESOURCE/Sounds');
  assertNoSymlink(out, sounds);
  const jobs = [], voice = ciResolve(sounds, 'VOICE'), russian = ciResolve(sounds, 'VOICE/RUSSIAN');
  if (voice) assertNoSymlink(out, voice);
  if (russian) assertNoSymlink(out, russian);
  if (voice && russian) for (const name of fs.readdirSync(russian).sort()) {
    const source = path.join(russian, name);
    if (name.toLowerCase().endsWith('.ogg') && fs.statSync(source).isFile()) jobs.push([source, [path.join(russian, `${name.slice(0,-4)}.wav`), path.join(voice, `${name.slice(0,-4)}.wav`)]]);
  }
  function walk(dir, top = false) {
    for (const e of fs.readdirSync(dir, { withFileTypes: true }).sort((a,b)=>a.name<b.name?-1:a.name>b.name?1:0)) {
      const full = path.join(dir, e.name);
      if (e.isDirectory()) { if (!(top && ['voice','music'].includes(e.name.toLowerCase()))) walk(full); }
      else if (e.name.toLowerCase().endsWith('.ogg')) jobs.push([full, [path.join(dir, `${e.name.slice(0,-4)}.wav`)]]);
    }
  }
  walk(sounds, true);
  return jobs;
}
export async function stepWav(out, dry = false, workers = Math.min(8, os.cpus().length || 2)) {
  const ffmpeg = executable('ffmpeg'), ffprobe = executable('ffprobe');
  if (!ffmpeg || !ffprobe) throw new Error('ffmpeg and ffprobe are required for WAV (or --skip-wav, which leaves the game silent)');
  const jobs = wavJobs(out), todo = jobs.map(([s, ds]) => [s, ds.filter((d) => !has(d))]).filter(([, ds]) => ds.length);
  const res = { created: 0, kept: jobs.reduce((a, [, ds]) => a + ds.length, 0) - todo.reduce((a, [, ds]) => a + ds.length, 0), sources: jobs.length, ffmpeg: version(ffmpeg) };
  if (dry) res.created = todo.reduce((a, [, ds]) => a + ds.length, 0);
  else {
    // Bounded pool: write in deterministic order, never overwrite a destination.
    const pending = new Map(); let next = 0;
    function start() { while (next < todo.length && pending.size < workers) { const i = next++; pending.set(i, oggToWavBytes(ffmpeg, ffprobe, todo[i][0]).then((value) => ({ value }), (error) => ({ error }))); } }
    start();
    for (let i = 0; i < todo.length; i++) {
      const result = await pending.get(i); pending.delete(i);
      if (result.error) throw result.error;
      const bytes = result.value; start();
      for (const dest of todo[i][1]) { if (installNew(dest, { data: bytes })) res.created++; else res.kept++; }
    }
  }
  log(`  WAV: ${res.sources} OGG sources, ${res.created} created, ${res.kept} already present (${res.ffmpeg})`);
  return res;
}
function locateMusic(base) {
  for (const rel of ['RESOURCE/Sounds/MUSIC','Sounds/MUSIC','MUSIC','music','.']) {
    const p = ciResolve(base, rel);
    if (p && fs.statSync(p).isDirectory() && fs.readdirSync(p).some((n) => n.toLowerCase().endsWith('.ogg'))) return p;
  }
  return null;
}
export function stepMusic(out, repack, manifest, musicFrom, dry = false) {
  const expected = new Map(manifest.added.filter((e) => e.kind === 'music').map((e) => [path.posix.basename(e.path), e]));
  if (!expected.size) return { copied: 0, present: 0 };
  const sounds = ciResolve(out, 'RESOURCE/Sounds');
  if (!sounds) throw new Error('missing RESOURCE/Sounds');
  const existing = ciResolve(out, 'RESOURCE/Sounds/MUSIC'), destDir = existing || path.join(sounds, 'MUSIC');
  assertNoSymlink(out, sounds); assertNoSymlink(out, destDir);
  let temp = null;
  try {
    let srcDir, origin;
    if (musicFrom) {
      srcDir = locateMusic(path.resolve(musicFrom));
      if (!srcDir) throw new Error(`--music-from ${musicFrom}: no OGG files found`);
      origin = `--music-from ${srcDir}`;
    } else {
      const archive = path.join(repack, 'setup-1.bin');
      const needExtract = !(existing && [...expected.keys()].every((n) => fs.existsSync(path.join(existing,n)) && fs.statSync(path.join(existing,n)).isFile()));
      if (!needExtract) { srcDir = existing; origin = 'already present'; }
      else {
        const exe = ['7zz','7z','7za','7zr'].map(executable).find(Boolean);
        if (!fs.existsSync(archive)) throw new Error(`missing ${archive}; supply --music-from DIR`);
        if (!exe) throw new Error('7zz/7z required for setup-1.bin or supply --music-from DIR');
        temp = fs.mkdtempSync(path.join(path.dirname(path.resolve(out)), '.prepare-music-'));
        if (!dry) {
          const result = spawnSync(exe, ['x','-y','-bd',`-o${temp}`,archive,'RESOURCE/Sounds/MUSIC/*'], { encoding:'utf8' });
          if (result.status !== 0) throw new Error(`${path.basename(exe)} failed (${result.status}): ${(result.stdout || '').slice(-400)}${(result.stderr || '').slice(-400)}`);
        }
        srcDir = dry ? null : locateMusic(temp); origin = `${path.basename(exe)} x setup-1.bin`;
        if (!dry && !srcDir) throw new Error('setup-1.bin contains no RESOURCE/Sounds/MUSIC/*.ogg');
      }
    }
    const res = { copied: 0, present: 0, origin };
    if (dry) { log(`  MUSIC: ${expected.size} files from ${origin} (dry-run)`); return res; }
    const names = fs.readdirSync(srcDir), missing = [...expected.keys()].filter((n) => !names.includes(n)).sort();
    const extra = names.filter((n) => n.toLowerCase().endsWith('.ogg') && !expected.has(n)).sort();
    if (missing.length) throw new Error(`MUSIC: missing files ${missing.slice(0,5).join(', ')}`);
    if (extra.length) throw new Error(`MUSIC: unexpected OGG files ${extra.slice(0,5).join(', ')}`);
    for (const [name, e] of [...expected].sort(([a],[b]) => a<b?-1:a>b?1:0)) {
      const src = path.join(srcDir, name);
      if (fs.statSync(src).size !== e.size || sha256File(src) !== e.sha256) throw new Error(`MUSIC/${name}: size or SHA-256 differs from reference`);
    }
    for (const [name, e] of [...expected].sort(([a],[b]) => a<b?-1:a>b?1:0)) {
      const dst = path.join(destDir, name);
      if (has(dst)) { if (sha256File(dst) !== e.sha256) throw new Error(`${dst}: existing content differs; refusing to overwrite`); res.present++; }
      else if (installNew(dst, { source: path.join(srcDir,name) })) res.copied++;
    }
    log(`  MUSIC: ${origin}; copied ${res.copied}, already present ${res.present} of ${expected.size}`);
    return res;
  } finally { if (temp) fs.rmSync(temp, { recursive:true, force:true }); }
}
function cloneTree(src, dest, useClone, stats) {
  if (has(dest)) {
    const srcSt = fs.lstatSync(src), dstSt = fs.lstatSync(dest);
    if (srcSt.isDirectory() && !srcSt.isSymbolicLink() && dstSt.isDirectory() && !dstSt.isSymbolicLink()) {
      for (const name of fs.readdirSync(src).sort()) cloneTree(path.join(src,name),path.join(dest,name),useClone,stats);
    } else stats.kept++;
    return;
  }
  if (useClone) {
    const r = spawnSync('cp',['-c','-R','-p',src,dest],{encoding:'utf8'});
    if (r.status !== 0) throw new Error(`cp -c ${src}: ${r.stderr}`);
    stats.cloned++;
  } else {
    fs.cpSync(src,dest,{recursive:true,force:false,errorOnExist:true,preserveTimestamps:true,verbatimSymlinks:true});
    stats.copied++;
  }
}
export function stepClone(repack,out,useClone,dry=false) {
  const stats = { cloned:0, copied:0, kept:0 };
  if (!dry) fs.mkdirSync(out,{recursive:true});
  for (const name of fs.readdirSync(repack).sort()) {
    if (isProtected(name)) { log(`  skipped protected file ${name}`); continue; }
    if (!dry) cloneTree(path.join(repack,name),path.join(out,name),useClone,stats);
  }
  log(`  ${useClone ? 'APFS clone' : 'copy'}: ${stats.cloned+stats.copied} top-level entries, ${stats.kept} kept`);
  return stats;
}
function loadManifest(file) {
  const m=JSON.parse(fs.readFileSync(file,'utf8'));
  if (m.format!==1) throw new Error(`unknown reference manifest format: ${file}`);
  return m;
}
export function estimate(repack, manifest, skipWav = false) {
  const listing=listFiles(repack), base=Object.entries(listing).filter(([p])=>!isProtected(p)).reduce((a,[,s])=>a+s,0);
  const added=manifest.added.filter((e)=>!(skipWav&&e.kind==='wav')).reduce((a,e)=>a+e.size,0);
  const music=manifest.added.filter((e)=>e.kind==='music').reduce((a,e)=>a+e.size,0), modified=manifest.modified.reduce((a,e)=>a+e.size_after,0);
  const extra=added+music+modified;
  return { copy_total:base+extra, clone_total:extra, base, added };
}
function nearestExisting(file) { let p=path.resolve(file); while (!fs.existsSync(p)) { const n=path.dirname(p); if(n===p) break; p=n; } return p; }
function canClone(source, probeDir) {
  if (process.platform !== 'darwin' || !executable('cp')) return false;
  const probe=path.join(probeDir,`.prepare-clone-probe-${process.pid}`);
  try { return spawnSync('cp',['-c',source,probe],{stdio:'ignore'}).status===0; }
  finally { try { fs.unlinkSync(probe); } catch {} }
}
function freeBytes(file) {
  if (typeof fs.statfsSync === 'function') { const s=fs.statfsSync(file); return Number(s.bavail)*Number(s.bsize); }
  const r=spawnSync('df',['-Pk',file],{encoding:'utf8'});
  if (r.status!==0) throw new Error('cannot determine free disk space');
  return Number(r.stdout.trim().split('\n').at(-1).trim().split(/\s+/u)[3])*1024;
}
function parseArgs(argv) {
  const opt={force:false,check:false,dryRun:false,skipWav:false,noClone:false,deep:false,patchesDir:DEFAULT_PATCH_DIR,minFreeMB:256};
  const flags={'--force':'force','--check':'check','--dry-run':'dryRun','--skip-wav':'skipWav','--no-clone':'noClone','--deep':'deep'};
  const values={'--repack':'repack','--out':'out','--music-from':'musicFrom','--patches-dir':'patchesDir','--manifest':'manifest','--report':'report','--min-free-mb':'minFreeMB'};
  for(let i=0;i<argv.length;i++) {
    const a=argv[i];
    if(a==='--help'||a==='-h') { opt.help=true; continue; }
    if(flags[a]) opt[flags[a]]=true;
    else if(values[a] && i+1<argv.length) opt[values[a]]=argv[++i];
    else throw new Error(`unknown or incomplete argument: ${a}`);
  }
  if(opt.help)return opt;
  if(!opt.repack||!opt.out) throw new Error('--repack and --out are required');
  opt.minFreeMB=Number(opt.minFreeMB);
  if(!Number.isInteger(opt.minFreeMB)||opt.minFreeMB<0)throw new Error('--min-free-mb must be nonnegative');
  return opt;
}
function writeReport(report, opt) { if(opt.report) fs.writeFileSync(opt.report,JSON.stringify(report,null,1)); }
function finish(report, result, opt) {
  for (const w of result.warnings) log(`  WARNING: ${w}`);
  for (const e of result.errors.slice(0,50)) log(`  MISMATCH: ${e}`);
  if (result.errors.length>50) log(`  ...and ${result.errors.length-50} more`);
  report.errors=result.errors; report.warnings=result.warnings; writeReport(report,opt);
  if(result.errors.length){log(`VERIFICATION FAILED: ${result.errors.length} differences`);return 3;}
  log(`VERIFICATION PASSED: contents and SHA-256 match${opt.skipWav?' (except WAV: --skip-wav)':''}`); return 0;
}
export async function main(argv=process.argv.slice(2)) {
  const opt=parseArgs(argv);
  if(opt.help) { log('Usage: node prepare_game.mjs --repack DIR --out DIR [--force] [--check] [--dry-run] [--skip-wav] [--music-from DIR] [--no-clone] [--deep] [--patches-dir DIR] [--manifest FILE] [--report FILE] [--min-free-mb N]'); return 0; }
  const repack=realEvenMissing(opt.repack), out=path.resolve(opt.out), outReal=realEvenMissing(out);
  const manifestFile=opt.manifest||path.join(opt.patchesDir,'expected-manifest.json'), report={repack,out,steps:{}};
  let started=false;
  try {
    log('== 0. Preflight');
    if(!fs.statSync(repack).isDirectory()||!ciResolve(repack,'RESOURCE')||!ciResolve(repack,'PROGRAM'))throw new Error(`--repack ${repack} is not a game directory`);
    const manifest=loadManifest(manifestFile);
    if(opt.check) {
      if(!fs.statSync(out).isDirectory())throw new Error(`--out ${out} is not a directory`);
      return finish(report,verify(out,repack,manifest,{skipWav:opt.skipWav,deep:opt.deep,patchDir:opt.patchesDir}),opt);
    }
    const workReal=realEvenMissing(WORK_GAME);
    if(inside(repack,outReal)||inside(workReal,outReal))throw new Error('--out is the repack or working game, or lies inside it');
    if(inside(outReal,repack))throw new Error('--repack lies inside --out');
    const existing=has(out);
    if(existing&&(!existing.isDirectory()||existing.isSymbolicLink()))throw new Error(`--out ${out} exists and is not a real directory`);
    if(existing&&fs.readdirSync(out).length&&!opt.force)throw new Error('--out is not empty; use a new directory or --force');
    let useClone=false;
    if(!opt.noClone) {
      let src=path.join(repack,'engine.ini');
      if(!fs.existsSync(src)) src=fs.readdirSync(repack).sort().map((n)=>path.join(repack,n)).find((p)=>fs.statSync(p).isFile()&&!isProtected(path.basename(p)));
      if(src)useClone=canClone(src,nearestExisting(out));
    }
    const est=estimate(repack,manifest,opt.skipWav), need=useClone?est.clone_total:est.copy_total, free=freeBytes(nearestExisting(out));
    log(`  repack: ${fmtMB(est.base)}; ${useClone?'APFS clone':'copy'}; need ~${fmtMB(need)} + ${opt.minFreeMB} MB reserve, free ${fmtMB(free)}`);
    if(free<need+opt.minFreeMB*MB)throw new Error('insufficient free space');
    if(opt.skipWav)log('  WARNING: --skip-wav leaves the game silent');
    log('== 1. Clone repack'); started=true;
    report.steps.clone=stepClone(repack,out,useClone,opt.dryRun);
    if(opt.dryRun){ log('dry-run: remaining steps require a clone and were skipped'); return 0; }
    log('== 2. Patches'); report.steps.patches=stepPatches(out,opt.patchesDir);
    log('== 3. Items from Ammo'); report.steps.items=stepItems(out);
    log('== 4. WAV from OGG'); report.steps.wav=opt.skipWav?{skipped:true}:await stepWav(out);
    const expectedVersion=manifest.tooling?.ffmpeg_version_line;
    if(!opt.skipWav && expectedVersion && report.steps.wav.ffmpeg!==expectedVersion)log(`  WARNING: reference ffmpeg ${expectedVersion}; current ${report.steps.wav.ffmpeg}; WAV hashes may differ`);
    log('== 5. MUSIC'); report.steps.music=stepMusic(out,repack,manifest,opt.musicFrom);
    log('== 6. Content fixes');
    const fixOutput=[]; const fixCode=applyFixes(out,{logger:(line)=>{fixOutput.push(line);log(`  apply_content_fixes: ${line}`);}});
    if(fixCode!==0)throw new Error('content fixes failed'); report.steps.content_fixes={output:fixOutput};
    log('== 7. Verify'); return finish(report,verify(out,repack,manifest,{skipWav:opt.skipWav,deep:opt.deep,patchDir:opt.patchesDir}),opt);
  } catch(e) {
    log(`ERROR: ${e.message}`);
    if(started)log(`  partially prepared ${out} was left unchanged for inspection`);
    report.error=e.message; writeReport(report,opt); return 1;
  }
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)) {
  main().then((code)=>{process.exitCode=code;}).catch((error)=>{console.error(`ERROR: ${error.message}`);process.exitCode=1;});
}
