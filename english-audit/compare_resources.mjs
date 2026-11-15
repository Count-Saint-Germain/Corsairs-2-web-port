#!/usr/bin/env node
/** Compare common RESOURCE files with an InstallShield image, read-only. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {IS} from './ishield.mjs';
function* walk(dir){for(const e of fs.readdirSync(dir,{withFileTypes:true})){const p=path.join(dir,e.name);if(e.isDirectory())yield* walk(p);else if(e.isFile()||e.isSymbolicLink())yield p;}}
export function compareResources(root,archive){const ru=new Map(),rows=[];let total=0;for(const p of walk(root)){const rel=path.relative(root,p).split(path.sep).join('/');ru.set(rel.toLowerCase(),[rel,p]);}
 for(const f of archive.files){const rel=archive.path(f).replaceAll('\\','/'),key=rel.toLowerCase();if(!key.startsWith('resource/')||!ru.has(key)||['/models/','/lighting/','resource/animation'].some(x=>key.includes(x)))continue;total++;
  let data;try{data=archive.readFile(f);}catch(e){if(e.code==='ENOENT'||/split or truncated file beyond volume/.test(e.message)){rows.push([rel,f.exp,fs.statSync(ru.get(key)[1]).size,'SPLIT']);continue;}throw e;}
  const local=fs.readFileSync(ru.get(key)[1]);if(!data.equals(local))rows.push([rel,data.length,local.length,'DIFF']);}
 rows.sort((a,b)=>a[0].toLowerCase()<b[0].toLowerCase()?-1:a[0].toLowerCase()>b[0].toLowerCase()?1:0);return {rows,total};}
function main(args){const idx=args.indexOf('--out');if(idx<2||idx===args.length-1)throw Error('Usage: node english-audit/compare_resources.mjs RU_GAME ISO... --out DIR');const root=args[0],archive=new IS(args.slice(1,idx));try{const {rows,total}=compareResources(root,archive),out=args[idx+1];fs.mkdirSync(out,{recursive:true});fs.writeFileSync(path.join(out,'resource_diff.tsv'),rows.map(r=>r.join('\t')+'\n').join(''));console.log(`common files ${total}, different ${rows.length} (DIFF ${rows.filter(r=>r[3]==='DIFF').length}, SPLIT ${rows.filter(r=>r[3]==='SPLIT').length})`);}finally{archive.close();}}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
