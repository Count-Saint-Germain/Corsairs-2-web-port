/** Independent low-level distribution validation primitives. No packager imports. */
import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { inflateRawSync, brotliDecompressSync } from 'node:zlib';

const SUFFIX={gzip:'.gz',br:'.br'};
const CRC_TABLE=Uint32Array.from({length:256},(_,n)=>{for(let i=0;i<8;i++)n=n&1?(n>>>1)^0xedb88320:n>>>1;return n>>>0;});
function crc32(buf){let n=0xffffffff;for(const b of buf)n=(CRC_TABLE[(n^b)&255]^(n>>>8))>>>0;return (n^0xffffffff)>>>0;}
export function safeRelpath(p){return typeof p==='string'&&!p.startsWith('/')&&!p.includes('\\')&&p.split('/').every(x=>x!==''&&x!=='.'&&x!=='..'&&!x.startsWith('.'));}
export function diskName(entry){return entry.path+(SUFFIX[entry.enc]??'');}
export function openRegular(p){
 const fd=fs.openSync(p,fs.constants.O_RDONLY|(fs.constants.O_NOFOLLOW??0));
 try{const info=fs.fstatSync(fd);if(!info.isFile()||info.nlink!==1)throw new Error(`not a singly linked regular file: ${p}`);return fd;}
 catch(e){fs.closeSync(fd);throw e;}
}
export function sha256File(p){const fd=openRegular(p),h=createHash('sha256'),buf=Buffer.alloc(1<<20);try{for(;;){const n=fs.readSync(fd,buf,0,buf.length,null);if(!n)break;h.update(buf.subarray(0,n));}return h.digest('hex');}finally{fs.closeSync(fd);}}
export function scanTree(root){
 const files=new Map(),problems=[];
 function walk(dir,rel=''){for(const e of fs.readdirSync(dir,{withFileTypes:true})){const name=rel?rel+'/'+e.name:e.name,full=path.join(dir,e.name),s=fs.lstatSync(full);
  if(s.isSymbolicLink())problems.push(`symlink: ${name}`);else if(s.isDirectory())walk(full,name);else if(!s.isFile())problems.push(`not a regular file: ${name}`);else if(s.nlink!==1)problems.push(`hard-linked file: ${name}`);else files.set(name,full);
 }}walk(root);return {files,problems};
}
export function fingerprint(root){const entries=new Map();function walk(dir,rel=''){for(const e of fs.readdirSync(dir,{withFileTypes:true})){const name=rel?rel+'/'+e.name:e.name,full=path.join(dir,e.name),s=fs.lstatSync(full,{bigint:true});entries.set(name,[s.size,s.mtimeNs,s.ino,s.mode].map(String).join(':'));if(s.isDirectory())walk(full,name);}}walk(root);return entries;}
export function brotliWindowBits(byte){if((byte&1)===0)return 16;const n=(byte>>1)&7;if(n)return 17+n;const m=(byte>>4)&7;return m===0?17:m===1?0:8+m;}
/** Decode exactly one complete stream with an output cap, rejecting all trailing bytes. */
export function unpackRecord(enc,raw,limit){
 if(!Buffer.isBuffer(raw))raw=Buffer.from(raw);
 if(!Number.isSafeInteger(limit)||limit<0)throw new Error('invalid output limit');
 if(enc==='br'){
  if(!raw.length||brotliWindowBits(raw[0])<10||brotliWindowBits(raw[0])>22)throw new Error('invalid or unsupported Brotli window');
  const d=brotliDecompressSync(raw,{info:true,maxOutputLength:Math.max(1,limit)});
  if(d.buffer.length>limit||d.engine.bytesWritten!==raw.length)throw new Error('trailing or excessive Brotli data');return d.buffer;
 }
 if(enc!=='gzip')throw new Error(`unsupported encoding ${enc}`);
 if(raw.length<18||raw[0]!==0x1f||raw[1]!==0x8b||raw[2]!==8||(raw[3]&0xe0))throw new Error('invalid gzip header');
 const flags=raw[3];let i=10;
 if(flags&4){if(i+2>raw.length)throw new Error('truncated gzip header');i+=2+raw.readUInt16LE(i);}
 for(const flag of [8,16])if(flags&flag){while(i<raw.length&&raw[i]!==0)i++;i++;}
 if(flags&2){if(i+2>raw.length||raw.readUInt16LE(i)!==(crc32(raw.subarray(0,i))&0xffff))throw new Error('gzip header CRC mismatch');i+=2;}
 if(i>raw.length-8)throw new Error('truncated gzip header');
 const d=inflateRawSync(raw.subarray(i),{info:true,maxOutputLength:Math.max(1,limit)}),end=i+d.engine.bytesWritten;
 if(end+8!==raw.length||d.buffer.length>limit)throw new Error('truncated, trailing or excessive gzip data');
 if(raw.readUInt32LE(end)!==crc32(d.buffer)||raw.readUInt32LE(end+4)!==(d.buffer.length>>>0))throw new Error('gzip trailer mismatch');
 return d.buffer;
}
export function readPackRecord(p,entry){
 const fd=openRegular(p);try{
  if(!Number.isSafeInteger(entry.offset)||entry.offset<0||!Number.isSafeInteger(entry.csize)||entry.csize<0)throw new Error('invalid pack span');
  const fileSize=fs.fstatSync(fd).size;if(entry.offset+entry.csize>fileSize)throw new Error('the pack ends inside the record');
  const raw=Buffer.alloc(entry.csize);let n=0;while(n<raw.length){const read=fs.readSync(fd,raw,n,raw.length-n,entry.offset+n);if(!read)throw new Error('the pack ends inside the record');n+=read;}
  const data=entry.enc in SUFFIX?unpackRecord(entry.enc,raw,entry.size):raw;
  return {size:data.length,sha256:createHash('sha256').update(data).digest('hex')};
 }finally{fs.closeSync(fd);}
}
export function manifestVersion(entries){const h=createHash('sha1');for(const e of [...entries].sort((a,b)=>a.path<b.path?-1:a.path>b.path?1:0))h.update(`${e.path}:${e.size}:${e.sha256};`);return h.digest('hex').slice(0,12);}

/** Parse Cloudflare Pages _headers rules and report repeated keys within a rule. */
export function parseHeaders(text){
 const rules=[],duplicates=[];
 for(const line of text.split(/\r?\n/)){
  if(!line.trim()||line.trimStart().startsWith('#'))continue;
  if(/^\s/.test(line)){
   if(!rules.length)continue;const i=line.indexOf(':');if(i<0)continue;
   const key=line.slice(0,i).trim().toLowerCase(),value=line.slice(i+1).trim(),headers=rules.at(-1)[1];if(key in headers)duplicates.push(`${rules.at(-1)[0]}: ${key}`);headers[key]=value;
  }else rules.push([line.trim(),{}]);
 }
 return [rules,duplicates];
}
function globRegex(pattern){let out='^';for(let i=0;i<pattern.length;i++){const c=pattern[i];if(c==='*')out+='.*';else if(c==='?')out+='.';else if(c==='['){const j=pattern.indexOf(']',i+1);if(j<0)out+='\\[';else{let cls=pattern.slice(i+1,j);if(cls.startsWith('!'))cls='^'+cls.slice(1);out+='['+cls.replaceAll('\\','\\\\')+']';i=j;}}else out+=c.replace(/[\\^$.*+?()[\]{}|]/g,'\\$&');}return new RegExp(out+'$');}
export function headersForUrl(url,rules){const out={};for(const [pattern,headers] of rules)if(globRegex(pattern).test(url))for(const [k,v] of Object.entries(headers))(out[k]??=[]).push(v);return out;}
export function referencedImports(dist){
 const roots=['index.html','port.js','port-config.js','netplay.js','audio-worklet.js'],pending=[...roots],seen=new Set(roots),referenced=new Set(),unreadable=[];
 while(pending.length){const name=pending.pop();let text;try{text=fs.readFileSync(path.join(dist,name),'utf8');}catch{unreadable.push(name);continue;}
  const imports=[...text.matchAll(/(?:\bfrom\s*|\bimport\s*(?:\(\s*)?)["']\.\/([^"']+)["']/g)].map(m=>m[1]);
  if(name==='index.html')for(const m of text.matchAll(/<script\b[^>]*\bsrc\s*=\s*["']([^"']+)["']/gi))if(!/^(https?:\/\/|\/\/|\/)/.test(m[1]))imports.push(m[1].replace(/^\.\//,''));
  for(const ref of imports){const target=path.posix.normalize(path.posix.join(path.posix.dirname(name),ref));if(target==='..'||target.startsWith('../')){unreadable.push(`${name}: import outside dist: ${ref}`);continue;}referenced.add(target);if(!seen.has(target)){seen.add(target);if(/\.(js|mjs)$/.test(target))pending.push(target);}}
 }
 return {seen,referenced,unreadable};
}
