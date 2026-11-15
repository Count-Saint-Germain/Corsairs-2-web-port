/** Node inventory, manifest, codecs, packing and overlay rules for the browser distribution. */
import fs from 'node:fs';
import { createHash } from 'node:crypto';
import { once } from 'node:events';
import { createDeflateRaw, inflateRawSync, brotliCompressSync, brotliDecompressSync, constants as zc } from 'node:zlib';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
export const CFG = JSON.parse(fs.readFileSync(path.resolve(here, '../../port.json'), 'utf8'));
export const EXE = CFG.exe;
const INCLUDE = (CFG.files?.include ?? []).map(x=>x.toLowerCase());
const REQUIRED = CFG.files?.required ?? [];
const EXCLUDE_EXTENSIONS = (CFG.files?.exclude_extensions ?? []).map(x=>x.toLowerCase());
const EXCLUDE_PATHS = (CFG.files?.exclude_paths ?? []).map(x=>x.toLowerCase().replace(/^\/+|\/+$/g,''));
const PLAYER_DIRS = new Set(['save','save_meta','save_tx']);
const SKIP = ['uninst','setup.exe','autorun.inf','unins000','directx/','redist/','_setup/'];
const lower = s => s.toLowerCase();
const fold = s => lower(s).replaceAll('ß','ss').replaceAll('ς','σ');
const order = (a,b) => a < b ? -1 : a > b ? 1 : 0;
const foldedOrder = (a,b) => order(fold(a),fold(b)) || order(a,b);
const bad = (kind,r) => { throw new Error(`port.json files.${kind}: bad rule ${JSON.stringify(r)}`); };

export function parseSiblingRules(raw = []) {
  if (!Array.isArray(raw)) bad('exclude_if_sibling',raw);
  const rules = raw.map(r => {
    if (!r || typeof r !== 'object' || Array.isArray(r) || Object.keys(r).some(k=>!['path','extension','sibling_extension','min_sibling_bytes'].includes(k))) bad('exclude_if_sibling',r);
    const ext = String(r.extension ?? '').toLowerCase(), sib = String(r.sibling_extension ?? '').toLowerCase(), floor = r.min_sibling_bytes ?? 1;
    if (!ext.startsWith('.') || !sib.startsWith('.') || ext.length<=1 || sib.length<=1 || ext===sib || (ext+sib).includes('/') || !Number.isInteger(floor) || floor<1) bad('exclude_if_sibling',r);
    return {path:String(r.path ?? '').toLowerCase().replace(/^\/+|\/+$/g,''), extension:ext, sibling_extension:sib, min_sibling_bytes:floor};
  });
  const dropped = new Set(rules.map(r=>r.extension));
  if (rules.some(r=>dropped.has(r.sibling_extension))) throw new Error('port.json files.exclude_if_sibling: chained or circular rules are not supported');
  return rules;
}
export const SIBLING_RULES = parseSiblingRules(CFG.files?.exclude_if_sibling ?? []);
export function redundantSiblings(entries, rules = SIBLING_RULES) {
  const sizes = new Map(entries.map(([p,size])=>[lower(p),size])), drop = new Set();
  for (const [p] of entries) for (const r of rules) {
    const low=lower(p);
    if ((!r.path || low.startsWith(r.path+'/')) && low.endsWith(r.extension)) {
      const sibling=low.slice(0,-r.extension.length)+r.sibling_extension;
      if ((sizes.get(sibling) ?? 0)>=r.min_sibling_bytes) { drop.add(p); break; }
    }
  }
  return drop;
}
export function parseRelocateRules(raw = []) {
  if (!Array.isArray(raw)) bad('relocate_if_absent',raw);
  const rules=raw.map(r=>{
    if (!r || typeof r!=='object' || Array.isArray(r) || Object.keys(r).sort().join(',')!=='from,to' || typeof r.from!=='string' || typeof r.to!=='string') bad('relocate_if_absent',r);
    const from=r.from.replace(/^\/+|\/+$/g,''), to=r.to.replace(/^\/+|\/+$/g,'');
    if ((from+'/'+to).split('/').some(p=>!p || p==='.' || p==='..' || p.includes('\\')) || lower(from)===lower(to) || lower(to).startsWith(lower(from)+'/')) bad('relocate_if_absent',r);
    return {from,to};
  });
  if (rules.some(a=>rules.some(b=>lower(a.to)===lower(b.from)))) throw new Error('port.json files.relocate_if_absent: chained or circular rules are not supported');
  return rules;
}
export const RELOCATE_RULES = parseRelocateRules(CFG.files?.relocate_if_absent ?? []);
export function relocations(paths, rules = RELOCATE_RULES) {
  const sorted=[...paths].sort(order), taken=new Set(sorted.map(lower)), dirs=new Set(), moves=new Map();
  for (const p of taken) { const parts=p.split('/'); for(let i=1;i<parts.length;i++) dirs.add(parts.slice(0,i).join('/')); }
  for (const r of rules) for (const p of sorted) {
    const src=lower(r.from), dst=lower(r.to);
    if (!lower(p).startsWith(src+'/') || p.slice(src.length+1).includes('/')) continue;
    const target=(src.startsWith(dst+'/') ? p.slice(0,dst.length) : r.to)+'/'+p.slice(src.length+1), low=lower(target);
    if (taken.has(low) || dirs.has(low)) continue;
    taken.add(low); moves.set(p,target);
  }
  return moves;
}
export function wanted(rel) {
  const low=lower(rel);
  if (low===lower(EXE)) return EXE;
  if (low.split('/').some(p=>!p || p==='.' || p==='..' || p.startsWith('.'))) return null;
  if (SKIP.some(s=>low.includes(s)) || EXCLUDE_EXTENSIONS.some(s=>low.endsWith(s))) return null;
  if (EXCLUDE_PATHS.some(p=>low===p || low.startsWith(p+'/'))) return null;
  if (!INCLUDE.length || INCLUDE.some(p=>low===p.replace(/\/$/,'') || low.startsWith(p.replace(/\/$/,'')+'/'))) return rel;
  return null;
}
/** Reject inventories that the browser cannot install safely. */
export function validatePublishedPaths(paths) {
  const names=new Map();
  for(const p of paths){
    if(/[\\\x00-\x1f\x7f]/.test(p) || p.split('/').some(part=>!part || part==='.' || part==='..')) throw new Error(`game inventory contains a browser-unsafe path: ${JSON.stringify(p)}`);
    if(lower(p.split('/')[0])==='options' && p!=='options')throw new Error(`game settings must be spelled options and cannot contain files: ${p}`);
    const key=lower(p),previous=names.get(key);if(previous!==undefined)throw new Error(`game paths differ only by case: ${previous} / ${p}`);names.set(key,p);
  }
}
/** Published path -> source path, without player data or linked files. */
export function gameFiles(root) {
  const out=new Map(), sizes=new Map();
  function visit(dir, rel='') {
    for (const entry of fs.readdirSync(dir,{withFileTypes:true})) {
      const next=rel ? rel+'/'+entry.name : entry.name, full=path.join(dir,entry.name);
      if (PLAYER_DIRS.has(fold(next.split('/')[0]))) continue;
      if (entry.isDirectory()) visit(full,next);
      else if (entry.isSymbolicLink()) {
        if (wanted(next)) throw new Error(`game inventory contains a symlink: ${next}`);
      } else {
        const dest=wanted(next); if (!dest) continue;
        const stat=fs.lstatSync(full);
        if (!stat.isFile() || stat.nlink!==1) throw new Error(`game inventory contains a linked or non-regular file: ${next}`);
        if(out.has(dest))throw new Error(`game paths resolve to the same published name: ${dest}`);
        out.set(dest,full); sizes.set(dest,stat.size);
      }
    }
  }
  visit(root);
  for(const p of redundantSiblings([...sizes])) out.delete(p);
  for(const [from,to] of relocations(out.keys())) { const src=out.get(from); out.delete(from); out.set(to,src); }
  validatePublishedPaths(out.keys());
  if (!out.has(EXE)) throw new Error(`${root}: no ${EXE} (port.json 'exe')`);
  for(const r of REQUIRED) if (![...out.keys()].some(k=>lower(k)===lower(r))) throw new Error(`${root}: no ${r} (port.json files.required)`);
  return out;
}
export const PACK_DIR='_k2pack', PACK_TARGET=8<<20, PACK_MAX_FILE=1<<20;
export function planPacks(csizes, maxFile=PACK_MAX_FILE, target=PACK_TARGET) {
  const entries=csizes instanceof Map ? [...csizes] : Object.entries(csizes), paths=entries.map(([p])=>p);
  const clash=paths.filter(p=>fold(p).startsWith(fold(PACK_DIR)+'/')).sort(order);
  if(clash.length) throw new Error(`game file ${clash[0]} lives in reserved folder ${PACK_DIR}/`);
  const sizes=new Map(entries), packs=[], loose=new Set(); let current=[], used=0;
  for(const p of paths.sort(foldedOrder)) { const n=sizes.get(p); if(lower(p)==='options'||n>maxFile){loose.add(p);continue;}
    if(current.length && used+n>target){packs.push(current);current=[];used=0;} current.push(p);used+=n; }
  if(current.length) packs.push(current);
  return [packs,loose];
}
export function packObjectName(index,members) {
  const h=createHash('sha256');
  for(const m of members) h.update(`${m.path}\0${m.size}\0${m.sha256}\0${m.enc||''}\0${m.csize}\n`);
  return `${PACK_DIR}/${String(index).padStart(4,'0')}-${h.digest('hex').slice(0,12)}.pack`;
}
export function fileSha256(src) {
  const h=createHash('sha256'), fd=fs.openSync(src,'r'), buffer=Buffer.alloc(1<<20);
  try { for(;;){const n=fs.readSync(fd,buffer,0,buffer.length,null);if(!n)break;h.update(buffer.subarray(0,n));} }
  finally {fs.closeSync(fd);} return h.digest('hex');
}
export function manifestFor(files, packed=new Map(), packs=[], hashes=new Map()) {
  files=files instanceof Map?files:new Map(Object.entries(files));
  packed=packed instanceof Map?packed:new Map(Object.entries(packed));
  hashes=hashes instanceof Map?hashes:new Map(Object.entries(hashes));
  const entries=[];
  for(const [p,src] of files){
    const e={path:p,size:fs.statSync(src).size,sha256:hashes.get(p)||fileSha256(src)},info=packed.get(p);
    if(info){const enc=('pack' in info)?info.enc:(info.enc??'gzip');if(enc)e.enc=enc;if(info.csize!=null)e.csize=info.csize;if('pack' in info){e.pack=info.pack;e.offset=info.offset;}}
    entries.push(e);
  }
  entries.sort((a,b)=>order(a.path,b.path));
  const h=createHash('sha1');for(const e of entries)h.update(`${e.path}:${e.size}:${e.sha256};`);
  const m={version:h.digest('hex').slice(0,12),files:entries};if(packs.length)m.packs=packs;return m;
}

const TOPS=['PROGRAM','RESOURCE'], FORBIDDEN={save:'player saves',save_meta:'save time records',save_tx:'save journal',options:'player settings','engine.ini':'engine settings','engine.exe':'the executable',modules:'game modules'};
const DEVICE=new Set(['con','prn','aux','nul',...Array.from({length:9},(_,i)=>`com${i+1}`),...Array.from({length:9},(_,i)=>`lpt${i+1}`)]);
const JUNK=new Set(['thumbs.db','desktop.ini']);
export function overlayPathProblem(p) {
  if(typeof p!=='string'||!p)return 'not a path';
  if(Buffer.byteLength(p)>240)return 'path too long';
  if(p.startsWith('/'))return 'absolute path';
  if(/[\\:*?"<>|\x00-\x1f\x7f]/.test(p))return 'backslash, colon, wildcard or control character in the path';
  const parts=p.split('/');if(parts.some(x=>!x))return 'empty path component';
  if(parts.includes('.'))return '"." component';if(parts.includes('..'))return '".." component (leaves the overlay root)';
  if(parts.length>20)return 'path too deep';const top=lower(parts[0]);if(top in FORBIDDEN)return `${FORBIDDEN[top]} (${parts[0]}) is not part of an overlay`;
  if(!TOPS.includes(parts[0]))return ['program','resource'].includes(top)?'top folder must be spelled PROGRAM or RESOURCE':'outside PROGRAM/ and RESOURCE/';
  if(parts.length<2)return 'a file must live inside PROGRAM/ or RESOURCE/';
  for(const p of parts){if(p.startsWith('.'))return `hidden name ${JSON.stringify(p)}`;if(/[. ]$/.test(p))return `name ${JSON.stringify(p)} ends with a dot or a space`;if(DEVICE.has(lower(p).split('.')[0]))return `reserved name ${JSON.stringify(p)}`;if(JUNK.has(lower(p)))return `junk name ${JSON.stringify(p)}`;}
  return null;
}
export function overlayMetaBlock(raw,files) {
  if(raw===null)return null;if(!raw||typeof raw!=='object'||Array.isArray(raw))throw new Error('OVERLAY.json: not an object');
  if(raw.format!==1)throw new Error('OVERLAY.json: unsupported format');if('language' in raw && typeof raw.language!=='string')throw new Error('OVERLAY.json: language is not a string');
  const base=('base' in raw) ? raw.base : {};if(!base||typeof base!=='object'||Array.isArray(base))throw new Error('OVERLAY.json: base is not an object');
  const known=new Set([...files.keys()].map(lower));
  for(const [p,sha] of Object.entries(base)){if(overlayPathProblem(p)||!known.has(lower(p)))throw new Error(`OVERLAY.json: base[${p}] is not a file of the overlay`);if(typeof sha!=='string'||!/^[a-f0-9]{64}$/i.test(sha))throw new Error(`OVERLAY.json: base[${p}] is not a SHA-256`);}
  return raw;
}
export function overlayFiles(root) {
  const rootInfo=fs.lstatSync(root);if(!rootInfo.isDirectory()||rootInfo.isSymbolicLink())throw new Error('overlay folder is not a plain directory');
  const out=new Map(), sizes=new Map(), dirs=new Set();let meta=null;
  for(const name of fs.readdirSync(root).sort(order)){
    const p=path.join(root,name),low=lower(name);
    if(name==='OVERLAY.json'){const s=fs.lstatSync(p);if(!s.isFile()||s.nlink!==1)throw new Error('OVERLAY.json is not a singly linked regular file');meta=JSON.parse(fs.readFileSync(p,'utf8'));}
    else if(low in FORBIDDEN)throw new Error(`overlay folder holds forbidden ${name}`);
    else if(!TOPS.includes(name))throw new Error(`overlay folder holds ${name}: only PROGRAM/ and RESOURCE/ allowed`);
  }
  function visit(dir,rel){for(const e of fs.readdirSync(dir,{withFileTypes:true})){
    const p=path.join(dir,e.name),r=rel+'/'+e.name,s=fs.lstatSync(p);
    if(s.isSymbolicLink())throw new Error(`overlay holds a symlink: ${r}`);
    if(s.isDirectory()){const why=overlayPathProblem(r+'/x');if(why)throw new Error(`${r}: ${why}`);dirs.add(lower(r));visit(p,r);}
    else {if(!s.isFile()||s.nlink!==1)throw new Error(`overlay holds a linked or non-regular file: ${r}`);const why=overlayPathProblem(r);if(why)throw new Error(`${r}: ${why}`);if(sizes.has(lower(r)))throw new Error(`overlay paths differ only by case: ${r}`);out.set(r,p);sizes.set(lower(r),s.size);}
  }}
  for(const top of TOPS){const p=path.join(root,top);let s;try{s=fs.lstatSync(p);}catch(e){if(e.code==='ENOENT')continue;throw e;}if(!s.isDirectory()||s.isSymbolicLink())throw new Error(`${top} is not a plain directory`);visit(p,top);}
  if(!out.size)throw new Error('the overlay folder holds no files');
  if(out.size>20000||[...sizes.values()].reduce((a,b)=>a+b,0)>4*1024**3)throw new Error('the overlay is larger than the page accepts');
  for(const p of sizes.keys()){if(dirs.has(p))throw new Error(`${p} is both a file and a folder`);const parts=p.split('/');for(let i=1;i<parts.length;i++)if(sizes.has(parts.slice(0,i).join('/')))throw new Error(`${p}: a file is used as a folder`);}
  return [out,overlayMetaBlock(meta,out)];
}
const lists=JSON.parse(fs.readFileSync(path.join(here,'overlay-required.json'),'utf8'));
if(lists.format!==1 || !Array.isArray(lists.required) || !lists.required.length || ['required','recommended','base_recommended'].some(k => {const v=lists[k] ?? (k==='required'?null:[]);return !Array.isArray(v)||v.some(p=>typeof p!=='string'||!p)||new Set(v.map(lower)).size!==v.length;})) throw new Error('invalid required overlay list');
export const OVERLAY_REQUIRED=lists.required;
export function overlayMissingRequired(files, required=OVERLAY_REQUIRED) {const have=new Set([...files.keys()].map(lower));return required.filter(x=>!have.has(lower(x)));}
export function overlayManifestFor(files,packed,packs,hashes,meta=null){const m=manifestFor(files,packed,packs,hashes);if(meta!==null)m.overlay=meta;return m;}
export function overlayBaseMismatches(meta,base){if(!meta)return [];const have=new Map(base.files.map(e=>[lower(e.path),lower(e.sha256)]));return Object.entries(meta.base??{}).filter(([p,sha])=>have.get(lower(p))!==lower(sha)).map(([p])=>p).sort(order);}


// Wire compression is deterministic: raw deflate with a fixed gzip header and trailer.
export const PACK_ENC='gzip', PACK_LEVEL=6, PACK_MIN_BYTES=1024, PACK_MIN_SAVING=.05;
export const PACK_SUFFIX={gzip:'.gz',br:'.br'}, BR_QUALITY=11, BR_LGWIN=22, BR_MIN_GAIN=.05, BR_MAX_INPUT=256<<20;
const NEVER_PACK_EXTENSIONS=['.ogg','.mp4','.webm','.png','.jpg','.jpeg','.gif','.gz','.zip','.7z','.rar','.bik','.wmv','.mp3'];
const GZIP_HEADER=Buffer.from([0x1f,0x8b,8,0,0,0,0,0,0,0xff]);
const CRC_TABLE=Uint32Array.from({length:256},(_,n)=>{for(let i=0;i<8;i++)n=(n&1)?(0xedb88320^(n>>>1)):(n>>>1);return n>>>0;});
function crc32(data, crc=0) {crc=(crc^0xffffffff)>>>0;for(const b of data)crc=(CRC_TABLE[(crc^b)&255]^(crc>>>8))>>>0;return (crc^0xffffffff)>>>0;}
export function packedKey(p,enc=PACK_ENC) {if(!(enc in PACK_SUFFIX))throw new Error(`unknown encoding: ${enc}`);return p+PACK_SUFFIX[enc];}
export function packable(p,size) {const low=lower(p);return low!=='options' && size>=PACK_MIN_BYTES && !NEVER_PACK_EXTENSIONS.some(x=>low.endsWith(x));}
export function worthPacking(size,csize) {return csize<=size*(1-PACK_MIN_SAVING);}
export function packableSet(files,encs=[PACK_ENC]) {
  const rows=files instanceof Map?[...files]:Object.entries(files),taken=new Set(rows.map(([p])=>fold(p)));
  return new Set(rows.filter(([p,src])=>packable(p,fs.statSync(src).size)&&!encs.some(enc=>taken.has(fold(packedKey(p,enc))))).map(([p])=>p));
}
export async function gzipPass(src,sink=null,level=PACK_LEVEL) {
  const h=createHash('sha256'), encoder=createDeflateRaw({level});let size=0,csize=0,crc=0;
  async function out(bytes){if(!bytes.length)return;csize+=bytes.length;if(sink)await sink(bytes);}
  await out(GZIP_HEADER);
  const producer=(async()=>{try{for await(const data of fs.createReadStream(src,{highWaterMark:1<<20})){size+=data.length;crc=crc32(data,crc);h.update(data);if(!encoder.write(data))await once(encoder,'drain');}encoder.end();}catch(e){encoder.destroy(e);throw e;}})();
  const consumer=(async()=>{try{for await(const bytes of encoder)await out(bytes);}catch(e){encoder.destroy(e);throw e;}})();
  await Promise.all([producer,consumer]);
  const trailer=Buffer.alloc(8);trailer.writeUInt32LE(crc,0);trailer.writeUInt32LE(size>>>0,4);await out(trailer);
  return [size,h.digest('hex'),csize];
}
export async function brotliPass(src,sink=null,quality=BR_QUALITY,lgwin=BR_LGWIN) {
  const s=fs.statSync(src);if(s.size>BR_MAX_INPUT)throw new Error(`brotli input exceeds ${BR_MAX_INPUT} bytes`);
  const data=fs.readFileSync(src),packed=brotliCompressSync(data,{params:{[zc.BROTLI_PARAM_QUALITY]:quality,[zc.BROTLI_PARAM_LGWIN]:lgwin}});
  if(sink)await sink(packed);return [data.length,createHash('sha256').update(data).digest('hex'),packed.length];
}
export async function codecPass(enc,src,sink=null,level=PACK_LEVEL,quality=BR_QUALITY) {
  if(enc==='gzip')return gzipPass(src,sink,level);if(enc==='br')return brotliPass(src,sink,quality);throw new Error(`unknown encoding: ${enc}`);
}
/** Decode one record with a strict output limit and reject trailing bytes. */
export function unpackRecord(enc,raw,limit) {
  try {
    if(!Buffer.isBuffer(raw))raw=Buffer.from(raw);
    if(!Number.isSafeInteger(limit)||limit<0)return [Buffer.alloc(0),false];
    if(enc==='br'){
      const result=brotliDecompressSync(raw,{info:true,maxOutputLength:Math.max(1,limit)});
      return [result.buffer,result.engine.bytesWritten===raw.length&&result.buffer.length<=limit];
    }
    if(enc!=='gzip'||raw.length<18||!raw.subarray(0,3).equals(GZIP_HEADER.subarray(0,3)))return [Buffer.alloc(0),false];
    const flags=raw[3];if(flags&0xe0)return [Buffer.alloc(0),false];let i=10;
    if(flags&4){if(i+2>raw.length)return [Buffer.alloc(0),false];const n=raw.readUInt16LE(i);i+=2+n;}
    for(const flag of [8,16])if(flags&flag){while(i<raw.length&&raw[i]!==0)i++;i++;}
    if(flags&2){if(i+2>raw.length||raw.readUInt16LE(i)!==(crc32(raw.subarray(0,i))&0xffff))return [Buffer.alloc(0),false];i+=2;}if(i>raw.length-8)return [Buffer.alloc(0),false];
    const result=inflateRawSync(raw.subarray(i),{info:true,maxOutputLength:Math.max(1,limit)}),data=result.buffer,end=i+result.engine.bytesWritten;
    if(end+8!==raw.length||data.length>limit||raw.readUInt32LE(end)!==crc32(data)||raw.readUInt32LE(end+4)!==(data.length>>>0))return [Buffer.alloc(0),false];
    return [data,true];
  } catch {return [Buffer.alloc(0),false];}
}
export function unpackCheck(enc,p,size,sha){try{const [data,ok]=unpackRecord(enc,fs.readFileSync(p),size);return ok&&data.length===size&&createHash('sha256').update(data).digest('hex')===sha;}catch{return false;}}
export function gunzipCheck(p,size,sha){return unpackCheck('gzip',p,size,sha);}
export async function writePack(target,members,level=PACK_LEVEL,quality=BR_QUALITY) {
  await fs.promises.mkdir(path.dirname(target),{recursive:true});const fh=await fs.promises.open(target,'wx');const out=[];let pos=0;
  try {for(const m of members){let size,sha,csize;
    async function sink(bytes){let written=0;while(written<bytes.length){const result=await fh.write(bytes,written,bytes.length-written,null);if(!result.bytesWritten)throw new Error('short pack write');written+=result.bytesWritten;}}
    if(m.enc in PACK_SUFFIX)[size,sha,csize]=await codecPass(m.enc,m.src,sink,level,quality);
    else{const h=createHash('sha256');size=0;for await(const bytes of fs.createReadStream(m.src)){h.update(bytes);size+=bytes.length;await sink(bytes);}sha=h.digest('hex');csize=size;}
    if(size!==m.size||sha!==m.sha256||csize!==m.csize)throw new Error(`${m.path}: the file changed while the pack was built`);
    out.push([pos,csize]);pos+=csize;
  }}finally{await fh.close();}return out;
}
export async function verifyPack(p,entries,packSize=null) {
  let fh;try{const stat=await fs.promises.stat(p);if(packSize!==null&&stat.size!==packSize)return false;fh=await fs.promises.open(p,'r');let pos=0;
    for(const e of [...entries].sort((a,b)=>a.offset-b.offset||a.csize-b.csize)){
      if(!Number.isSafeInteger(e.offset)||!Number.isSafeInteger(e.csize)||e.offset!==pos||e.csize<0||e.csize>stat.size-pos)return false;
      const raw=Buffer.alloc(e.csize);let n=0;while(n<raw.length){const {bytesRead}=await fh.read(raw,n,raw.length-n,e.offset+n);if(!bytesRead)return false;n+=bytesRead;}
      const [data,ok]=e.enc?unpackRecord(e.enc,raw,e.size):[raw,true];if(!ok||data.length!==e.size||createHash('sha256').update(data).digest('hex')!==e.sha256)return false;pos+=e.csize;
    }return pos===stat.size;
  }catch{return false;}finally{if(fh)await fh.close();}
}

/** Decide transfer encodings without writing output; returns a path-keyed Map. */
export async function analyseFiles(files, eligible, level=PACK_LEVEL, workers=4, codec=PACK_ENC, quality=BR_QUALITY) {
  if(!['gzip','br'].includes(codec))throw new Error(`unknown codec: ${codec}`);
  const rows=files instanceof Map?[...files]:Object.entries(files), results=new Array(rows.length);let next=0;
  const count=Math.min(rows.length,Math.max(1,Number.isInteger(workers)?workers:4));
  await Promise.all(Array.from({length:count},async()=>{for(;;){const i=next++;if(i>=rows.length)return;const [p,src]=rows[i];let size,sha,csize,enc=null;
    if(eligible.has(p)){
      const gz=await gzipPass(src,null,level);[size,sha,csize]=gz;if(!worthPacking(size,csize))csize=size;else enc='gzip';
      if(codec==='br') {const [, , brsize]=await brotliPass(src,null,quality);if(worthPacking(size,brsize)&&brsize<=csize*(1-BR_MIN_GAIN)){enc='br';csize=brsize;}}
    } else {size=fs.statSync(src).size;sha=fileSha256(src);csize=size;}
    results[i]=[p,{size,sha256:sha,csize,enc}];
  }}));
  return new Map(results);
}
