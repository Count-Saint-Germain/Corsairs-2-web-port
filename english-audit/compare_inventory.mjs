#!/usr/bin/env node
/** Compare a game directory with InstallShield inventory without extracting game data. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {IS} from './ishield.mjs';
function* walk(dir){for(const e of fs.readdirSync(dir,{withFileTypes:true})){const p=path.join(dir,e.name);if(e.isDirectory())yield* walk(p);else if(e.isFile()||e.isSymbolicLink())yield p;}}
export function topGroup(p){const parts=p.split('/');if(parts.length>=3&&parts[0].toLowerCase()==='resource'){if(['sounds','textures','models','animation','ini','videos'].includes(parts[1].toLowerCase()))return `RESOURCE/${parts[1]}${parts.length>3?'/'+parts[2]:''}`;return `RESOURCE/${parts[1]}`;}return parts.length>1?parts[0]:'(root)';}
export function compareInventory(root,archive){
 const us=new Map(),ru=new Map();for(const f of archive.files){const p=archive.path(f).replaceAll('\\','/');us.set(p.toLowerCase(),[p,f.exp]);}
 for(const full of walk(root)){const rel=path.relative(root,full).split(path.sep).join('/');ru.set(rel.toLowerCase(),[rel,fs.statSync(full).size]);}
 const onlyUs=[...us.keys()].filter(k=>!ru.has(k)).sort(),onlyRu=[...ru.keys()].filter(k=>!us.has(k)).sort(),both=[...us.keys()].filter(k=>ru.has(k)).sort(),diff=both.filter(k=>us.get(k)[1]!==ru.get(k)[1]),diffSet=new Set(diff),same=both.filter(k=>!diffSet.has(k));
 const groups=new Map();for(const [kind,keys] of [['us_only',onlyUs],['ru_only',onlyRu],['size_diff',diff],['same_size',same]])for(const k of keys){const src=kind==='ru_only'?ru:us,entry=src.get(k),group=topGroup(entry[0]),map=groups.get(group)||new Map(),v=map.get(kind)||[0,0];v[0]++;v[1]+=entry[1];map.set(kind,v);groups.set(group,map);}
 return {us,ru,onlyUs,onlyRu,both,diff,same,groups};
}
function main(args){const idx=args.indexOf('--out');if(idx<0||idx===args.length-1||idx<2)throw Error('Usage: node english-audit/compare_inventory.mjs RU_GAME ISO... --out DIR');const root=args[0],images=args.slice(1,idx),out=args[idx+1],archive=new IS(images);try{const r=compareInventory(root,archive);fs.mkdirSync(out,{recursive:true});
 const write=(name,rows)=>fs.writeFileSync(path.join(out,name),rows.map(row=>row.join('\t')+'\n').join(''));
 write('us_only.tsv',r.onlyUs.map(k=>r.us.get(k)));write('ru_only.tsv',r.onlyRu.map(k=>r.ru.get(k)));write('size_diff.tsv',r.diff.map(k=>[r.ru.get(k)[0],r.ru.get(k)[1],r.us.get(k)[1]]));
 write('groups.tsv',[...r.groups].sort(([a],[b])=>a<b?-1:a>b?1:0).flatMap(([g,m])=>[...m].sort(([a],[b])=>a<b?-1:a>b?1:0).map(([k,v])=>[g,k,...v])));
 console.log(`US files: ${r.us.size}, RU files: ${r.ru.size}; common names: ${r.both.length} (same size: ${r.same.length}, different: ${r.diff.length}); US only: ${r.onlyUs.length}; RU only: ${r.onlyRu.length}`);
 }finally{archive.close();}}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
