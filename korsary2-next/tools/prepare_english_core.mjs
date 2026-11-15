/** Read-only English-overlay sources and validation of manual/leftover metadata. */
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import { IS } from '../../english-audit/ishield.mjs';
import * as et from './english_text.mjs';

export class Fail extends Error {}
export const sha256=(data)=>crypto.createHash('sha256').update(data).digest('hex');
export const LEFT_CLASSES=['identifier','debug','ambiguous'];
export const BULK_DIRS=['RESOURCE/Textures/Loading','RESOURCE/Textures/WorldMap/reload','RESOURCE/Sounds/VOICE','RESOURCE/INI/ALIASES','RESOURCE/VIDEOS'];
export const PREFIXES=['PROGRAM/','RESOURCE/INI/TEXTS/','RESOURCE/INI/fonts.ini','RESOURCE/QUESTSTEXT/'];
export const US_IMAGE_PINS={
  'data1.hdr':'16f169f127a487b273d617834606bee511f04e655f60ed97a504f3c1a4166a1c',
  'data1.cab':'38c7ee8af5d682240576154f6b744500387633a41d041b5238bca14194dc4423',
  'data2.cab':'4663f82d9fd56adba4365f50602fb92ae966dc7fccfdc926988701e980316b5c',
  'data3.cab':'b17e47bfdee789581f2f6a036d03410299b00213a7782f8163aeb950c4968e88',
};
export function wanted(rel){const u=rel.toUpperCase();return PREFIXES.some((p)=>u.startsWith(p.toUpperCase()));}
export class Tree {
  constructor(){this.f=new Map();}
  add(rel,data){const key=rel.toUpperCase();if(this.f.has(key))throw new Fail(`files differ only by case: ${this.f.get(key)[0]} / ${rel}`);this.f.set(key,[rel,Buffer.from(data)]);}
  get(rel){return this.f.get(rel.toUpperCase())?.[1]??null;}
  name(rel){return this.f.get(rel.toUpperCase())?.[0]??null;}
  keys(){return [...this.f.keys()].sort();}
  paths(){return this.keys().map((k)=>this.f.get(k)[0]);}
  digest(){const h=crypto.createHash('sha256');for(const k of this.keys()){const d=this.f.get(k)[1];h.update(`${k}\t${d.length}\t${sha256(d)}\n`,'utf8');}return h.digest('hex');}
}
function subDir(root,parts){
  let current=root;
  for(const part of parts){
    const hit=fs.readdirSync(current).sort().find((n)=>{
      if(n.toLowerCase()!==part.toLowerCase())return false;
      try{return fs.statSync(path.join(current,n)).isDirectory();}catch(error){if(error.code==='ENOENT')return false;throw error;}
    });
    if(hit===undefined)return null;current=path.join(current,hit);
  }
  return current;
}
function walk(root,start,visitor){
  function visit(dir){for(const item of fs.readdirSync(dir,{withFileTypes:true}).sort((a,b)=>a.name<b.name?-1:a.name>b.name?1:0)){
    if(item.name==='.DS_Store')continue;
    const file=path.join(dir,item.name),rel=path.relative(root,file).split(path.sep).join('/');
    if(item.isDirectory())visit(file);
    else {let stat;try{stat=fs.statSync(file);}catch(error){if(error.code==='ENOENT')continue;throw error;}if(stat.isFile())visitor(file,rel);}
  }}
  visit(start);
}
export function read_dir_tree(input){
  const tree=new Tree(),root=path.resolve(input);
  for(const top of ['PROGRAM','RESOURCE/INI','RESOURCE/QUESTSTEXT']){
    const dir=subDir(root,top.split('/'));if(dir)walk(root,dir,(file,rel)=>{if(wanted(rel))tree.add(rel,fs.readFileSync(file));});
  }
  return tree;
}
export class Bulk {
  constructor(){this.f=new Map();this.cache=new Map();}
  add(rel,size,reader){const key=rel.toUpperCase();if(this.f.has(key))throw new Fail(`resources differ only by case: ${this.f.get(key)[0]} / ${rel}`);this.f.set(key,[rel,size,reader]);}
  has(rel){return this.f.has(rel.toUpperCase());}
  name(rel){return this.f.get(rel.toUpperCase())?.[0]??null;}
  size(rel){return this.f.get(rel.toUpperCase())?.[1]??null;}
  read(rel){
    const key=rel.toUpperCase();if(this.cache.has(key))return this.cache.get(key);
    const row=this.f.get(key);if(!row)return null;
    const data=Buffer.from(row[2]());if(data.length!==row[1])throw new Fail(`resource size mismatch: ${row[0]} (${data.length} != ${row[1]})`);
    this.cache.set(key,data);return data;
  }
  under(prefix,direct=false){const p=prefix.toUpperCase().replace(/\/+$/u,'')+'/';return [...this.f.keys()].sort().filter((k)=>k.startsWith(p)&&!(direct&&k.slice(p.length).includes('/'))).map((k)=>this.f.get(k)[0]);}
  dir_spelling(prefix){const p=prefix.toUpperCase().replace(/\/+$/u,'')+'/',n=prefix.replace(/\/+$/u,'').length;for(const k of [...this.f.keys()].sort())if(k.startsWith(p))return this.f.get(k)[0].slice(0,n);return null;}
  drop(rel){this.cache.delete(rel.toUpperCase());}
}
export function read_dir_bulk(input){
  const bulk=new Bulk(),root=path.resolve(input);
  for(const top of BULK_DIRS){const dir=subDir(root,top.split('/'));if(dir)walk(root,dir,(file,rel)=>{const size=fs.statSync(file).size;bulk.add(rel,size,()=>fs.readFileSync(file));});}
  return bulk;
}
export class IsoSources {
  constructor(){this.text=new Tree();this.bulk=new Bulk();this.pins={};this._s=null;}
  close(){if(this._s){this._s.close();this._s=null;}}
}
export function read_iso_sources(isos,verify_images=true){
  for(const file of isos)if(!fs.existsSync(file)||!fs.statSync(file).isFile())throw new Fail(`missing image: ${file}`);
  let archive;try{archive=new IS(isos);}catch(e){throw new Fail(`image cannot be read as ISO9660 + InstallShield (${e.message})`);}
  const src=new IsoSources();src._s=archive;
  try {
    if(verify_images)for(const [name,want] of Object.entries(US_IMAGE_PINS)){
      const entry=archive._find(name);if(!entry)throw new Fail(`image missing ${name} (Disc 1 + Disc 2 or single image required)`);
      const digest=crypto.createHash('sha256');for(const chunk of entry.iso.readFileChunks(entry.entry))digest.update(chunk);
      src.pins[name]=digest.digest('hex');if(src.pins[name]!==want)throw new Fail(`wrong image: SHA-256 ${name} = ${src.pins[name]}, expected ${want}`);
    }
    const prefixes=BULK_DIRS.map((d)=>d.toUpperCase()+'/');
    for(const file of archive.files){
      const rel=archive.path(file).replaceAll('\\','/');
      if(wanted(rel)){const data=archive.readFile(file);if(data.length!==file.exp)throw new Fail(`image file size mismatch: ${rel} (${data.length} != ${file.exp})`);src.text.add(rel,data);}
      else if(prefixes.some((p)=>rel.toUpperCase().startsWith(p)))src.bulk.add(rel,file.exp,()=>archive.readFile(file));
    }
    return src;
  }catch(e){src.close();throw e;}
}
export function read_iso_tree(isos,verify_images=true){const src=read_iso_sources(isos,verify_images);try{return [src.text,src.pins];}finally{src.close();}}
function parseDoc(file,label){
  let raw,doc;try{raw=fs.readFileSync(file);doc=JSON.parse(raw.toString('utf8'));}catch(e){throw new Fail(`${label} is unreadable (${file}): ${e.message}`);}
  if(!doc||typeof doc!=='object'||Array.isArray(doc)||doc.format!==1||!Array.isArray(doc.entries))throw new Fail(`${label}: unknown format`);
  return [raw,doc];
}
function table(map,key){if(!map.has(key))map.set(key,new Map());return map.get(key);}
function validIndex(value){if((typeof value!=='number'&&typeof value!=='string')||!/^\d+$/u.test(String(value)))throw new Error('invalid index');const n=Number(value);if(!Number.isSafeInteger(n))throw new Error('invalid index');return n;}
export class Manual {
  constructor(file){
    const [raw,doc]=parseDoc(file,'manual layer');this.path=file;this.sha=sha256(raw);this.entries=doc.entries;
    this.lit=new Map();this.quest=new Map();this.text=new Map();this.pairs=new Map();this.used=new Set();
    for(const [n,e] of this.entries.entries())try{
      if(e.kind==='pairs'){
        if(typeof e.file!=='string'||!e.map||typeof e.map!=='object'||Array.isArray(e.map))throw new Error('fields');
        const key=e.file.toUpperCase();if(this.pairs.has(key))throw new Error('duplicate');
        const pairs=new Map(Object.entries(e.map).map(([k,v])=>[validIndex(k),v===null?null:validIndex(v)]));
        this.pairs.set(key,[pairs,validIndex(e.ru_literals),validIndex(e.us_literals),n]);continue;
      }
      const {kind,file,ru_sha256:sha,en}=e;
      if(typeof file!=='string'||typeof sha!=='string'||!(/^[0-9a-f]{64}$/u.test(sha))||typeof en!=='string'||!en||/[^\x00-\x7f]/u.test(en))throw new Error('fields or non-ASCII text');
      const override=Boolean(e.override);let dest,key;
      if(kind==='literal'){dest=table(this.lit,file.toUpperCase());key=validIndex(e.index);}
      else if(kind==='quest'){dest=this.quest;key=e.key;}
      else if(kind==='text_key'){dest=table(this.text,file.toUpperCase());key=e.key;}
      else throw new Error('kind');
      if(key===undefined||dest.has(key))throw new Error('missing key or duplicate');
      dest.set(key,[Buffer.from(en,'ascii'),override,sha,n]);
    }catch(e){throw new Fail(`manual layer: invalid entry ${n} (${e.message})`);}
  }
  count(){return this.entries.length;}
}
export class Leftovers {
  constructor(file){
    const [raw,doc]=parseDoc(file,'leftover classification');this.path=file;this.sha=sha256(raw);this.entries=doc.entries;
    this.lit=new Map();this.key=new Map();this.used=new Set();
    for(const [n,e] of this.entries.entries())try{
      const {file,ru_sha256:sha,class:cls,why}=e;
      if(typeof file!=='string'||typeof sha!=='string'||!(/^[0-9a-f]{64}$/u.test(sha))||!LEFT_CLASSES.includes(cls)||typeof why!=='string'||!why.trim())throw new Error('fields');
      if(Object.hasOwn(e,'index')===Object.hasOwn(e,'key'))throw new Error('exactly one of index or key is required');
      const dest=table(Object.hasOwn(e,'index')?this.lit:this.key,file.toUpperCase()),key=Object.hasOwn(e,'index')?validIndex(e.index):e.key;
      if(dest.has(key))throw new Error('duplicate');dest.set(key,[cls,sha,n]);
    }catch(e){throw new Fail(`leftover classification: invalid entry ${n} (${e.message})`);}
  }
  count(){return this.entries.length;}
}
export function drift(what,got,want){throw new Fail(`drift: Russian source changed (${what}): SHA-256 ${got.slice(0,12)}, expected ${want.slice(0,12)}`);}
export function check_protected(rel,raw,spans,protectedEntries,manual){
  for(const [idx,[cls,sha]] of [...protectedEntries].sort(([a],[b])=>a-b)){
    if(idx<0||idx>=spans.length)throw new Fail(`leftover classification: ${rel}: index ${idx} out of range (${spans.length} literals)`);
    const [s,e]=spans[idx],got=et.sha256(raw.subarray(s+1,e-1));if(got!==sha)drift(`${rel}[${idx}] (leftover classification)`,got,sha);
    if(manual.has(idx))throw new Fail(`manual layer: ${rel}[${idx}] is protected class ${cls}`);
  }
}
export function classify_left(result,leftovers){
  if(!leftovers)return;
  const unknown=[];
  for(const entry of result.left){
    const index=Object.hasOwn(entry,'index'),key=index?entry.index:entry.key,found=(index?leftovers.lit:leftovers.key).get(entry.file.toUpperCase())?.get(key);
    if(!found){unknown.push(`${entry.file}:${key}`);continue;}
    if(found[1]!==entry.ru_sha256)drift(`${entry.file}:${key} (leftover classification)`,entry.ru_sha256,found[1]);
    entry.class=found[0];leftovers.used.add(found[2]);
  }
  if(unknown.length)throw new Fail(`unclassified Russian literals: ${unknown.length}, first: ${unknown.slice(0,5).join(', ')}`);
  const unused=leftovers.entries.filter((_,n)=>!leftovers.used.has(n));
  if(unused.length)throw new Fail(`${unused.length} leftover classification entries do not match any remaining literal: ${unused.slice(0,5).map((e)=>`${e.file}:${e.index??e.key}`).join(', ')}`);
}
export class Result { constructor(){this.files={};this.info={};this.left=[];this.warnings=[];this.skipped={};this.notes=[];this.stats={};this.video=null;} }
export function check_anchors(rel,[total,equal]){if(total>=20&&equal/total<0.99)throw new Fail(`${rel}: questionable alignment: only ${equal} of ${total} anchor pairs match`);}
