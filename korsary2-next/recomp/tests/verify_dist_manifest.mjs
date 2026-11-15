/** Independent manifest verifier. It intentionally does not import the packager. */
import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { Block } from './verify_dist_checks.mjs';
import { scanTree, safeRelpath, diskName, sha256File, openRegular, unpackRecord, readPackRecord, manifestVersion, brotliWindowBits } from './verify_dist_core.mjs';
const SHA=/^[a-f0-9]{64}$/,SHA_ANY=/^[a-f0-9]{64}$/i;
const PLAYER=new Set(['save','save_meta','save_tx']),PACK_DIR='_k2pack';
const SUFFIX={gzip:'.gz',br:'.br'};
const fold=p=>p.toLowerCase().replaceAll('ß','ss').replaceAll('ς','σ');
function manifestRead(root){const p=path.join(root,'manifest.json');const m=JSON.parse(fs.readFileSync(p,'utf8'));if(!m||!Array.isArray(m.files)||typeof m.version!=='string'||m.files.some(e=>!e||typeof e.path!=='string'))throw new Error('invalid manifest shape');return m;}
function readRegular(p){const fd=openRegular(p);try{return fs.readFileSync(fd);}finally{fs.closeSync(fd);}}
function readHead(p,offset){const fd=openRegular(p);try{const b=Buffer.alloc(1);return fs.readSync(fd,b,0,1,offset)===1?b[0]:null;}finally{fs.closeSync(fd);}}
function packedEntry(e){return e.pack!==undefined&&e.pack!==null;}
function compressed(e){return e.enc==='gzip'||e.enc==='br';}
function natural(n){return Number.isSafeInteger(n)&&n>=0;}
function sortedUnique(xs){return [...new Set(xs)].sort();}
function redundant(entries,rules){const sizes=new Map(entries.map(([p,n])=>[fold(p),n])),out=[];
 for(const [p] of entries){const low=fold(p);for(const r of rules){const under=fold(String(r.path??'')).replace(/^\/+|\/+$/g,''),ext=fold(String(r.extension)),sib=fold(String(r.sibling_extension));
  if((!under||low.startsWith(under+'/'))&&low.endsWith(ext)&&(sizes.get(low.slice(0,-ext.length)+sib)??0)>=Number(r.min_sibling_bytes??1)){out.push(p);break;}}}return sortedUnique(out);}
function pendingRelocations(paths,rules){const taken=new Set(paths.map(fold)),dirs=new Set(),found=[];
 for(const p of taken){const parts=p.split('/');for(let i=1;i<parts.length;i++)dirs.add(parts.slice(0,i).join('/'));}
 for(const r of rules){const src=fold(String(r.from)).replace(/^\/+|\/+$/g,''),dst=fold(String(r.to)).replace(/^\/+|\/+$/g,'');for(const p of paths){const low=fold(p);if(!low.startsWith(src+'/')||low.slice(src.length+1).includes('/'))continue;const target=dst+'/'+low.slice(src.length+1);if(!taken.has(target)&&!dirs.has(target))found.push(p);}}return sortedUnique(found);}
/** Verify every manifest entry's layout, policy and either all or a deterministic sample of bytes. */
export function checkManifest(dist,{minHashes=20,targetHashes=50,fullHash=false,required=[],excluded=['RESOURCE/VIDEOS'],siblingRules=[],relocateRules=[]}={}){
 const b=new Block('manifest'),root=path.join(dist,'game');let m;
 try{m=manifestRead(root);}catch(e){b.ok(false,`manifest.json is not readable: ${e.message}`);return b;}
 let disk;try{disk=scanTree(root);}catch(e){b.ok(false,`game inventory unreadable: ${e.message}`);return b;}
 b.ok(!disk.problems.length,`game/ contains no links or special files: ${disk.problems.slice(0,4).join('; ')}`);
 const entries=m.files,listed=new Map(entries.map(e=>[e.path,e])),onDisk=new Set([...disk.files.keys()].filter(p=>p!=='manifest.json'));
 const sizesOk=entries.every(e=>natural(e.size)&&typeof e.sha256==='string'&&SHA.test(e.sha256));
 b.ok(sizesOk,'every entry has a nonnegative integer size and lowercase SHA-256');
 b.ok(listed.size===entries.length,'no duplicate manifest paths');
 const lowered=entries.map(e=>fold(e.path));b.ok(new Set(lowered).size===lowered.length,'no case-colliding manifest paths');
 b.ok(entries.every(e=>safeRelpath(e.path)),'all manifest paths are safe relative paths');
 b.ok(entries.every(e=>[undefined,null,'identity','gzip','br'].includes(e.enc)),'every encoding is absent or supported');
 const packed=new Map(entries.filter(e=>compressed(e)&&!packedEntry(e)).map(e=>[e.path,e])),inPack=new Map(entries.filter(packedEntry).map(e=>[e.path,e]));
 b.ok([...packed.values()].every(e=>natural(e.csize)&&natural(e.size)&&e.csize<e.size),'each compressed loose entry has a valid smaller csize');
 b.ok(![...packed.keys(),...inPack.keys()].some(p=>p.toLowerCase()==='options'),'options is never packed');
 let packs=m.packs??[];const packsOk=Array.isArray(packs)&&packs.every(x=>x&&typeof x.path==='string'&&natural(x.size));b.ok(packsOk,'packs is a list of {path, size}');if(!packsOk)packs=[];
 const packNames=packs.map(x=>x.path);b.ok(new Set(packNames).size===packNames.length&&packNames.every(p=>safeRelpath(p)&&p.startsWith(PACK_DIR+'/')),'pack names are unique and under _k2pack');
 b.ok(!entries.some(e=>fold(e.path).startsWith(PACK_DIR+'/')),'no game file path lives under _k2pack');
 const badPack=[...inPack.values()].filter(e=>!natural(e.pack)||e.pack>=packs.length||!natural(e.offset)||!natural(e.csize)||!natural(e.size)||e.offset+e.csize>packs[e.pack].size||(e.enc?( !compressed(e)||e.csize>=e.size ):e.csize!==e.size));
 b.ok(!badPack.length,`pack spans are valid (${badPack.length} bad)`);
 if(!badPack.length){let tiling=true;for(let i=0;i<packs.length;i++){const rows=[...inPack.values()].filter(e=>e.pack===i).sort((a,b)=>a.offset-b.offset||a.csize-b.csize);let pos=0;for(const e of rows){if(e.offset!==pos){tiling=false;break;}pos+=e.csize;}if(pos!==packs[i].size||('files' in packs[i]&&packs[i].files!==rows.length))tiling=false;}b.ok(tiling,'pack records tile each pack exactly');}
 if(packed.size||inPack.size)b.ok(fs.existsSync(path.join(dist,'game-transfer.mjs')),'game-transfer.mjs packaged');
 const diskOf=new Map(entries.filter(e=>!packedEntry(e)).map(e=>[e.path,diskName(e)]));
 const missing=[...diskOf.values(),...packNames].filter(p=>!onDisk.has(p));b.ok(!missing.length,`every object exists (${missing.length} missing)`);
 const expected=new Set([...diskOf.values(),...packNames]),extra=[...onDisk].filter(p=>!expected.has(p));b.ok(!extra.length,`game/ has no unlisted objects (${extra.length} extra)`);
 const badSize=[];for(const [p,diskName] of diskOf){const e=listed.get(p),f=disk.files.get(diskName);if(f&&fs.statSync(f).size!==(packed.has(p)?e.csize:e.size))badSize.push(p);}
 for(const p of packs){const f=disk.files.get(p.path);if(f&&fs.statSync(f).size!==p.size)badSize.push(p.path);}b.ok(!badSize.length,`object sizes match (${badSize.length} mismatched)`);
 const published=[...diskOf.values(),...packNames].map(fold);b.ok(new Set(published).size===published.length,'no case-colliding published object names');
 const br=entries.filter(e=>e.enc==='br');if(br.length){const decoder=path.join(dist,'brotli-decoder.mjs'),wasm=path.join(dist,'vendor/brotli/k2br.wasm');b.ok(fs.existsSync(decoder),'brotli-decoder.mjs present');
  const pin=fs.existsSync(decoder)?/K2BR_WASM_SHA256\s*=\s*'([0-9a-f]{64})'/.exec(fs.readFileSync(decoder,'utf8')):null;let pinned=false;try{pinned=!!pin&&sha256File(wasm)===pin[1];}catch{}b.ok(pinned,'Brotli decoder wasm matches pinned SHA-256');
  const bad=[];for(const e of br){try{const file=packedEntry(e)?disk.files.get(packs[e.pack]?.path):disk.files.get(diskOf.get(e.path));if(!file)continue;const first=readHead(file,packedEntry(e)?e.offset:0),window=first===null?0:brotliWindowBits(first);if(window<10||window>22)bad.push(e.path);}catch{bad.push(e.path);}}b.ok(!bad.length,`Brotli windows are at most 4 MiB (${bad.length} invalid)`);
 }
 const reverseDisk=new Map([...diskOf].map(([logical,disk])=>[disk,logical]));
 const logical=[...onDisk].filter(p=>!packNames.includes(p)).map(p=>reverseDisk.get(p)??p).concat([...inPack.keys()]);
 b.ok(!entries.some(e=>PLAYER.has(fold(e.path.split('/')[0])))&&!logical.some(p=>PLAYER.has(fold(p.split('/')[0]))),'no top-level player data');
 b.ok(!entries.some(e=>e.path==='videos'||e.path.startsWith('videos/')),'no videos in game manifest');
 const prefixes=excluded.map(p=>fold(p).replace(/^\/+|\/+$/g,'')),isExcluded=p=>prefixes.some(x=>fold(p)===x||fold(p).startsWith(x+'/'));
 b.ok(!entries.some(e=>isExcluded(e.path))&&!logical.some(isExcluded),'excluded folders absent');
 const knownSizes=entries.filter(e=>natural(e.size)).map(e=>[e.path,e.size]);
 b.ok(!redundant(knownSizes,siblingRules).length&&!redundant(logical.map(p=>[p,listed.get(p)?.size??(disk.files.has(p)?fs.statSync(disk.files.get(p)).size:0)]),siblingRules).length,'redundant sibling files absent');
 b.ok(!pendingRelocations([...listed.keys()],relocateRules).length&&!pendingRelocations(logical,relocateRules).length,'no relocations left pending');
 const opts=entries.filter(e=>e.path.toLowerCase()==='options');b.ok(opts.length<=1&&opts.every(e=>e.path==='options'&&natural(e.size)&&e.size<=1024*1024),'options entry is unique, exact and <= 1 MiB');
 const existing=new Set(entries.map(e=>e.path.toLowerCase())),absent=required.filter(p=>!existing.has(p.toLowerCase()));if(required.length)b.ok(!absent.length,`required files listed: ${absent.slice(0,5).join(', ')}`);else b.warn('port.json not found: required game files were not checked');
 if(sizesOk)b.ok(manifestVersion(entries)===m.version,'manifest version is consistent');else return b;
 const ordered=[...entries].sort((a,b)=>b.size-a.size||(a.path<b.path?-1:a.path>b.path?1:0));let selected;
 if(fullHash)selected=ordered;else{const first=ordered.slice(0,Math.min(minHashes,ordered.length)),seen=new Set(first.map(e=>e.path)),rest=ordered.filter(e=>!seen.has(e.path));selected=[...first];if(rest.length&&selected.length<targetHashes){const step=Math.max(1,Math.floor(rest.length/(targetHashes-selected.length)));for(let i=0;i<rest.length;i+=step)selected.push(rest[i]);}}
 const failures=[];let hashedBytes=0;
 for(const e of selected){try{let size,hash;if(packedEntry(e)){if(badPack.length||!disk.files.has(packs[e.pack]?.path))continue;({size,sha256:hash}=readPackRecord(disk.files.get(packs[e.pack].path),e));}
  else{const f=disk.files.get(diskOf.get(e.path));if(!f)continue;if(compressed(e)){const raw=readRegular(f),data=unpackRecord(e.enc,raw,e.size);size=data.length;hash=createHash('sha256').update(data).digest('hex');}else{size=e.size;hash=sha256File(f);}}
  hashedBytes+=e.size;if(size!==e.size||hash!==e.sha256)failures.push(e.path);
 }catch(err){failures.push(`${e.path}: ${err.message}`);}}
 b.ok(!failures.length,`SHA-256 matches (${failures.length} mismatches: ${failures.slice(0,5).join('; ')})`);
 if(!fullHash&&selected.length<entries.length)b.warn(`only ${selected.length} of ${entries.length} files hashed; use --full-hash before publishing`);
 if(!fullHash&&inPack.size)b.warn(`${inPack.size} packed records were sampled, not fully hashed`);
 if(!fullHash&&packed.size)b.warn(`${packed.size} loose compressed entries were sampled, not fully hashed`);
 b.counts=`${entries.length} entries (${packed.size} compressed, ${inPack.size} in ${packs.length} packs), version ${m.version}, ${selected.length} sha256 checked (${(hashedBytes/1e6).toFixed(0)} MB)${fullHash?' [full]':''}`;return b;
}
export {manifestRead,readRegular,readHead,packedEntry,compressed,natural,SHA_ANY,SUFFIX,redundant,pendingRelocations};
