#!/usr/bin/env node
/** Generate exact binary-safe patches and a reference manifest from repack and working trees. */
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import crypto from 'node:crypto';
import { spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { parsePatch, applyPatchBytes, loadPatches, safeRel, listFiles, listingFingerprint, isProtected, sha256File, PROTECTED_TOP, RUNTIME_EXTRAS_TOP } from './prepare_game_core.mjs';

const hash=(b)=>crypto.createHash('sha256').update(b).digest('hex');
export function detectEol(data, rel) {
  const s=Buffer.from(data).toString('latin1');
  const crlf=(s.match(/\r\n/gu)||[]).length, lf=(s.match(/\n/gu)||[]).length;
  if(crlf===lf&&crlf)return 'crlf';
  if(crlf===0) { if(s.includes('\r'))throw new Error(`${rel}: standalone CR`);return 'lf'; }
  throw new Error(`${rel}: mixed line endings (crlf=${crlf}, lf=${lf})`);
}
function logical(data,eol) {
  const s=Buffer.from(data).toString('latin1'), final=s.endsWith(eol);
  return { lines:(final?s.slice(0,-eol.length):s).split(eol), final };
}
export function makePatch(rel,before,after) {
  safeRel(rel);
  const eb=detectEol(before,rel),ea=detectEol(after,rel), lb=logical(before,eb==='crlf'?'\r\n':'\n'),la=logical(after,ea==='crlf'?'\r\n':'\n');
  if(lb.final!==la.final)throw new Error(`${rel}: final newline differs`);
  const temp=fs.mkdtempSync(path.join(os.tmpdir(),'k2-content-diff-'));
  try {
    const a=path.join(temp,'before'),b=path.join(temp,'after');
    fs.writeFileSync(a,Buffer.from(lb.lines.join('\n')+'\n','latin1')); fs.writeFileSync(b,Buffer.from(la.lines.join('\n')+'\n','latin1'));
    const diff=spawnSync('git',['-c','core.autocrlf=false','diff','--no-index','--no-ext-diff','--no-color','--no-textconv','--text','--unified=0','--',a,b],{maxBuffer:128*1024*1024});
    if(diff.error)throw new Error(`git diff failed: ${diff.error.message}`);
    if(diff.status!==1)throw new Error(diff.status===0?`${rel}: no logical changes to produce a patch`:`git diff failed: ${(diff.stderr||Buffer.alloc(0)).toString('utf8')}`);
    const lines=diff.stdout.toString('latin1').split('\n');
    const first=lines.findIndex((line)=>line.startsWith('--- '));
    if(first<0||!lines[first+1]?.startsWith('+++ '))throw new Error(`${rel}: invalid git diff output`);
    lines[first]=`--- a/${rel}`; lines[first+1]=`+++ b/${rel}`;
    const header=[`# path: ${rel}`,`# sha256-before: ${hash(before)}`,`# sha256-after: ${hash(after)}`,`# eol-before: ${eb}`,`# eol-after: ${ea}`,`# final-newline: ${lb.final?'yes':'no'}`];
    const output=Buffer.from([...header,...lines.slice(first)].join('\n'),'latin1');
    const {meta,hunks}=parsePatch(output);
    if(!applyPatchBytes(meta,hunks,before).equals(after))throw new Error(`${rel}: patch self-check failed`);
    return output;
  } finally {fs.rmSync(temp,{recursive:true,force:true});}
}
export function writePatches(repack,work,out,paths) {
  fs.mkdirSync(out,{recursive:true});
  for(const [i,rel] of paths.entries()) {
    safeRel(rel);
    const before=fs.readFileSync(path.join(repack,rel)),after=fs.readFileSync(path.join(work,rel));
    const name=`${String(i+1).padStart(2,'0')}-${path.posix.basename(rel).replaceAll(' ','_')}.patch`;
    const result=makePatch(rel,before,after);fs.writeFileSync(path.join(out,name),result);console.log(`${name}: ${result.length} bytes`);
  }
}
export function classify(rel) {
  const n=rel.toLowerCase();
  if(n.startsWith('resource/sounds/music/')&&n.endsWith('.ogg'))return ['music','setup-1.bin'];
  if(n.startsWith('resource/sounds/')&&n.endsWith('.wav'))return ['wav',null];
  if(n.startsWith('resource/models/items/')&&n.endsWith('.gm'))return ['items_model','RESOURCE/MODELS/Ammo/'];
  if(n.startsWith('resource/textures/items/'))return ['items_texture','RESOURCE/Textures/Ammo/'];
  if(n.startsWith('resource/models/heads/')||n.startsWith('resource/animation/heads/'))return ['content_fix','tools/apply_content_fixes.mjs'];
  throw new Error(`unclassified added file: ${rel}`);
}
function today() { const d=new Date();return `${d.getFullYear()}-${String(d.getMonth()+1).padStart(2,'0')}-${String(d.getDate()).padStart(2,'0')}`; }
export function buildManifest(repack,work,patchesDir=null) {
  const rl=listFiles(repack),wl=listFiles(work),base=Object.fromEntries(Object.entries(rl).filter(([p])=>!isProtected(p)));
  const ignoredExtra=new Set(Object.keys(wl).filter((p)=>RUNTIME_EXTRAS_TOP.includes(p.toLowerCase())||p.split('/')[0].toUpperCase()==='SAVE'));
  const onlyWork=Object.keys(wl).filter((p)=>!Object.hasOwn(rl,p)&&!ignoredExtra.has(p)).sort();
  const onlyRepack=Object.keys(base).filter((p)=>!Object.hasOwn(wl,p)).sort();
  if(onlyRepack.length)throw new Error(`files present in repack but absent in working copy: ${onlyRepack.slice(0,5).join(', ')}`);
  const modified=[];let same=0;
  for(const p of Object.keys(base).sort()) {
    const before=sha256File(path.join(repack,p)),after=sha256File(path.join(work,p));
    if(base[p]===wl[p]&&before===after){same++;continue;}
    modified.push({path:p,sha256_before:before,sha256_after:after,size_before:base[p],size_after:wl[p]});
  }
  const added=onlyWork.map((p)=>{
    const [kind,from]=classify(p),e={path:p,size:wl[p],sha256:sha256File(path.join(work,p)),kind};
    if(from)e.from=from;
    if(['items_model','items_texture'].includes(kind))e.from+=path.posix.basename(p);
    if(kind==='wav')e.from=p.slice(0,-4)+'.ogg';
    return e;
  });
  const kinds={};for(const e of added)kinds[e.kind]=(kinds[e.kind]||0)+1;
  if(patchesDir){
    const names=new Set(modified.map((e)=>e.path)),got=new Set(loadPatches(patchesDir).map((p)=>p.meta.path));
    const different=[...names].filter((x)=>!got.has(x)).concat([...got].filter((x)=>!names.has(x)));
    if(different.length)throw new Error(`patches do not cover modified files: ${different.sort().join(', ')}`);
  }
  const f=spawnSync('ffmpeg',['-version'],{encoding:'utf8',timeout:30000});
  return {
    format:1,generated:today(),
    about:'Reference differences between the working game and repack; full file list is not stored. Generated by make_content_patch.mjs and checked by prepare_game.mjs.',
    source:{repack_listing_sha256:listingFingerprint(rl),repack_files_total_listing:Object.keys(rl).length},
    tooling:{ffmpeg_version_line:(f.stdout||'').split('\n')[0],wav_pipeline:'ffprobe(sample_rate,channels) -> ffmpeg -c:a pcm_s16le -f s16le -> canonical 44-byte WAV header',music_source:'game/setup-1.bin (7z, Copy method, 37 files)'},
    protected_files_excluded:PROTECTED_TOP,ignored_in_verification:['*/.DS_Store'],runtime_files_tolerated:[...RUNTIME_EXTRAS_TOP,'SAVE/**'],
    counts:{repack_files:Object.keys(rl).length,protected_files_excluded:Object.keys(rl).filter(isProtected).length,unchanged_common:same,modified:modified.length,added_total:added.length,added_by_kind:Object.fromEntries(Object.entries(kinds).sort(([a],[b])=>a<b?-1:a>b?1:0)),expected_out_files:Object.keys(base).length+added.length},modified,added,
  };
}
export function main(argv=process.argv.slice(2)) {
  const cmd=argv.shift();
  if(!cmd||['--help','-h'].includes(cmd)){console.log('Usage: node make_content_patch.mjs patches --repack DIR --work DIR --out DIR PATH...\n       node make_content_patch.mjs manifest --repack DIR --work DIR --out FILE [--patches-dir DIR]');return cmd?0:1;}
  if(!['patches','manifest'].includes(cmd))throw new Error(`unknown command ${cmd}`);
  const opt={paths:[]};
  for(let i=0;i<argv.length;i++){
    const a=argv[i];
    if(['--repack','--work','--out','--patches-dir'].includes(a)&&i+1<argv.length)opt[a]=argv[++i];
    else if(a.startsWith('--'))throw new Error(`unknown or incomplete option ${a}`);
    else opt.paths.push(a);
  }
  if(!opt['--repack']||!opt['--work']||!opt['--out'])throw new Error('--repack, --work and --out are required');
  if(cmd==='patches'){
    if(!opt.paths.length)throw new Error('at least one path is required');
    writePatches(opt['--repack'],opt['--work'],opt['--out'],opt.paths);
  } else {
    if(opt.paths.length)throw new Error('manifest takes no positional paths');
    const m=buildManifest(opt['--repack'],opt['--work'],opt['--patches-dir']);
    fs.writeFileSync(opt['--out'],JSON.stringify(m,null,1)+'\n');
    console.log(`${opt['--out']}: modified ${m.modified.length}, added ${m.added.length}, unchanged ${m.counts.unchanged_common}`);
  }
  return 0;
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)) {
  try {process.exitCode=main();}catch(error){console.error(`ERROR: ${error.message}`);process.exitCode=1;}
}
