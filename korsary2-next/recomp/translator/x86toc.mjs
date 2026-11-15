#!/usr/bin/env node
/** Static x86-to-C recompiler for the game executable and guest modules. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {createX86Decoder} from './x86_decoder.mjs';
import {Program} from './x86_program.mjs';
import {FunctionTranslator} from './x86_translate.mjs';

const hex8=n=>Number(n).toString(16).padStart(8,'0');
const numeric=(a,b)=>a-b;
const json=value=>JSON.stringify(value,null,1);
function parseArgs(args) {
 const o={roots:'',all:false,perFile:400,trace:false},pos=[];
 for(let i=0;i<args.length;i++) {
  const a=args[i];
  if(a==='--help'||a==='-h'){o.help=true;continue;}
  if(a==='--all'){o.all=true;continue;}
  if(a==='--trace'){o.trace=true;continue;}
  if(['--manifest','--roots','--per-file'].includes(a)) {
   if(++i>=args.length)throw new Error(`missing value for ${a}`);
   if(a==='--manifest')o.manifest=args[i];else if(a==='--roots')o.roots=args[i];else o.perFile=Number(args[i]);
  } else if(a.startsWith('-'))throw new Error(`unknown argument: ${a}`);
  else pos.push(a);
 }
 if(o.help)return o;
 if(!Number.isInteger(o.perFile)||o.perFile<1)throw new Error('--per-file must be a positive integer');
 if(o.manifest) {if(pos.length!==1)throw new Error('manifest mode requires <outdir>');o.outdir=pos[0];}
 else {if(pos.length!==3)throw new Error('give <exe> <functions.json> <outdir>, or --manifest <images.json> <outdir>');[o.exe,o.functions,o.outdir]=pos;}
 return o;
}

/** Translate images with the experimental Node implementation. */
export async function translateImages(options) {
 let images;
 if(options.manifest) {
  const manifest=fs.realpathSync(options.manifest),dir=path.dirname(manifest);
  images=JSON.parse(fs.readFileSync(manifest,'utf8')).images;
  if(!Array.isArray(images))throw new Error('manifest must contain an images array');
  images=images.map(x=>({...x,...(x.path!=null?{path:path.resolve(dir,x.path)}:{}),...(x.functions!=null?{functions:path.resolve(dir,x.functions)}:{})}));
 } else images=[{path:options.exe,functions:options.functions,tag:'recomp',base:null,required:true}];
 const decoder=await createX86Decoder();
 try {
  const progs=[];
  for(const img of images) {
   const p=Program.fromFiles(img.path,img.functions,decoder,{base:img.base,required:img.required??true,tag:img.tag||'recomp'});
   p.addPointerEntries();p.trace=options.trace;p.guest=img.guest||path.basename(img.path);progs.push(p);
   console.error(`${img.path}: final base 0x${p.base.toString(16)} (preferred 0x${p.prefBase.toString(16)}), ${p.entries.size} entries`);
  }
  const allEntries=[...new Set(progs.flatMap(p=>[...p.entries]))].sort(numeric),stats={},unsupported=new Map(),badFunctions=[],missing=new Set(),perImage=[];
  fs.mkdirSync(options.outdir,{recursive:true});
  for(const old of fs.readdirSync(options.outdir))if(old.endsWith('.c'))fs.unlinkSync(path.join(options.outdir,old));
  const increment=(key,n)=>{stats[key]=(stats[key]||0)+n;};
  for(const p of progs) {
   const roots=options.roots ? options.roots.split(',').filter(Boolean).map(x=>{if(!/^(?:0x)?[0-9a-f]+$/i.test(x))throw new Error(`invalid root: ${x}`);return parseInt(x,16);}) : [];
   const chosen=options.all?new Set(p.entries):p.closure(roots),ordered=[...chosen].sort(numeric),chunks=[];let current=[],nFuncs=0,nInsns=0,nUnsup=0;
   for(const e of ordered) {
    let source,uns,count;
    try {({source,unsupported:uns,count}=new FunctionTranslator(p,p.functions.get(e)).translate());}
    catch(error) {source=`void f_${hex8(e)}(CPU *c) { guest_trap(c, 0x${hex8(e)}u, "translator failed: ${error.name}"); }\n`;uns=[`translator crash: ${error.name}: ${error.message}`];count=0;}
    nFuncs++;nInsns+=count;
    if(uns.length){nUnsup++;increment('unsupported_instructions',uns.length);badFunctions.push(e);for(const u of uns){const name=u.split(' (')[0];unsupported.set(name,(unsupported.get(name)||0)+1);}}
    current.push(source);if(current.length>=options.perFile){chunks.push(current);current=[];}
   }
   if(current.length)chunks.push(current);
   for(let i=0;i<chunks.length;i++)fs.writeFileSync(path.join(options.outdir,`${p.tag}_${String(i).padStart(3,'0')}.c`),'#include "recomp.h"\n\n'+chunks[i].join('\n'));
   increment('functions',nFuncs);increment('instructions',nInsns);increment('functions_with_unsupported',nUnsup);
   for(const e of p.entries)if(!chosen.has(e))missing.add(e);
   perImage.push({tag:p.tag,guest:p.guest,base:p.base,preferred:p.prefBase,functions:nFuncs,files:chunks.length,instructions:nInsns});
  }
  const hdr=['#include "runtime.h"','#include "simd.h"','#include <math.h>','',...allEntries.map(e=>`void f_${hex8(e)}(CPU *c);`)];
  fs.writeFileSync(path.join(options.outdir,'recomp.h'),'#ifndef RECOMP_H\n#define RECOMP_H\n'+hdr.join('\n')+'\n#endif\n');
  let stubs='#include "recomp.h"\n\n';for(const e of [...missing].sort(numeric))stubs+=`void f_${hex8(e)}(CPU *c) { guest_trap(c, 0x${hex8(e)}u, "function not recompiled"); }\n`;
  stubs+='\nvoid register_all_functions(void) {\n';for(const e of allEntries)stubs+=`    register_function(0x${hex8(e)}u, f_${hex8(e)});\n`;stubs+='}\n';
  fs.writeFileSync(path.join(options.outdir,'recomp_stubs.c'),stubs);
  fs.writeFileSync(path.join(options.outdir,'modules.json'),json({modules:progs.map(p=>({tag:p.tag,base:p.base,preferred:p.prefBase,size:p.size,entries:p.entries.size,exports:[...p.exports].sort((a,b)=>a.ordinal-b.ordinal).map(x=>({name:x.name,ordinal:x.ordinal,address:x.address}))}))}));
  stats.files=perImage.reduce((n,p)=>n+p.files,0);stats.images=progs.length;stats.pointer_entries=progs.reduce((n,p)=>n+(p.pointerEntries||0),0);stats.gap_entries=progs.reduce((n,p)=>n+(p.gapEntries||0),0);
  const orderedUnsupported=[...unsupported].sort((a,b)=>b[1]-a[1]);
  fs.writeFileSync(path.join(options.outdir,'translate_report.json'),json({stats,unsupported:orderedUnsupported,functions_with_unsupported:badFunctions.map(e=>`0x${hex8(e)}`),images:perImage}));
  console.log(JSON.stringify(stats));if(orderedUnsupported.length)console.log('unsupported by mnemonic:',orderedUnsupported.slice(0,25));
  return {stats,unsupported:orderedUnsupported};
 } finally {decoder.close();}
}
export async function runCli(args) {
 const o=parseArgs(args);
 if(o.help)console.log('Usage: node x86toc.mjs <exe> <functions.json> <outdir> [--all] or --manifest <images.json> <outdir>');
 else await translateImages(o);
}
if(process.argv[1] && import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){
 try {await runCli(process.argv.slice(2));}
 catch(error){console.error(`translation failed: ${error.message}`);process.exitCode=1;}
}
