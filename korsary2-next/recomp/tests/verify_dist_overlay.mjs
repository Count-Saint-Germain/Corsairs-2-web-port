/** Independent language overlay validation; intentionally does not import the packager. */
import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { Block } from './verify_dist_checks.mjs';
import { scanTree,safeRelpath,diskName,sha256File,unpackRecord,readPackRecord,manifestVersion,parseHeaders,headersForUrl } from './verify_dist_core.mjs';
import { manifestRead,readRegular,packedEntry,compressed,natural,SHA_ANY } from './verify_dist_manifest.mjs';
const BAD=/[\\:*?"<>|\x00-\x1f\x7f]/,FORBIDDEN=new Set(['save','save_meta','save_tx','options','engine.ini','engine.exe','modules']);
const DEVICES=new Set(['con','prn','aux','nul',...Array.from({length:9},(_,i)=>`com${i+1}`),...Array.from({length:9},(_,i)=>`lpt${i+1}`)]);
const file=p=>{try{const s=fs.lstatSync(p);return s.isFile()&&!s.isSymbolicLink();}catch{return false;}};
const dir=p=>{try{return fs.statSync(p).isDirectory();}catch{return false;}};
const text=p=>fs.readFileSync(p,'utf8');
const same=(a,b)=>a.length===b.length&&a.every((x,i)=>x===b[i]);
export function overlayPathProblem(p){
 if(typeof p!=='string'||!p)return 'not a path';if(Buffer.byteLength(p)>240)return 'path too long';if(p.startsWith('/'))return 'absolute path';
 if(BAD.test(p))return 'backslash, colon, wildcard or control character';const parts=p.split('/');if(parts.some(x=>!x))return 'empty component';
 if(parts.includes('.')||parts.includes('..'))return 'dot component';if(parts.length>20)return 'path too deep';
 if(FORBIDDEN.has(parts[0].toLowerCase()))return 'forbidden player data or executable';if(!['PROGRAM','RESOURCE'].includes(parts[0]))return 'outside PROGRAM/ and RESOURCE/';
 if(parts.length<2)return 'file directly at top';for(const part of parts){if(part.startsWith('.'))return 'hidden name';if(/[. ]$/.test(part))return 'trailing dot or space';if(DEVICES.has(part.toLowerCase().split('.')[0]))return 'reserved device name';if(['thumbs.db','desktop.ini'].includes(part.toLowerCase()))return 'junk name';}return null;
}
export function readOverlayRequired(p){const data=JSON.parse(text(p));if(!data||data.format!==1)throw new Error('format is not 1');const out=[];
 for(const [key,must] of [['required',true],['recommended',false],['base_recommended',false]]){const rows=data[key]??(must?null:[]);if(!Array.isArray(rows)||(must&&!rows.length)||rows.some(x=>typeof x!=='string'||!x)||new Set(rows.map(x=>x.toLowerCase())).size!==rows.length)throw new Error(`${key} is not a list of distinct paths`);out.push(rows);}return out;}
function versionOrder(a,b){return b.size-a.size||(a.path<b.path?-1:a.path>b.path?1:0);}
function sample(rows,min,target,full){const order=[...rows].sort(versionOrder);if(full||order.length<=target)return order;const step=Math.max(1,Math.floor((order.length-min)/Math.max(1,target-min)));return order.slice(0,min).concat(order.slice(min).filter((_,i)=>i%step===0));}
/** Check overlay paths, manifest, packed/loose bytes, base independence and page contract. */
export function checkOverlay(dist,{required=[],minHashes=20,targetHashes=50,fullHash=false,mustExist=false}={}){
 const b=new Block('overlay','game-en/ entries vs files, strict paths, hashes and base compatibility'),root=path.join(dist,'game-en');
 if(!fs.existsSync(root)){if(mustExist)b.ok(false,'game-en/ present (--require-overlay)');else b.warn('no game-en/ in this dist: Russian only');return b;}
 if(!b.ok(file(path.join(root,'manifest.json')),'game-en/manifest.json present'))return b;let m;
 try{m=manifestRead(root);if(!m.files.length||!m.version)throw new Error('empty files or version');}catch(e){b.ok(false,`overlay manifest unreadable: ${e.message}`);return b;}
 const entries=m.files,{files:disk,problems}=scanTree(root);b.ok(!problems.length,`overlay has no links or special files: ${problems.slice(0,3).join('; ')}`);b.ok(entries.length<=20000,'at most 20000 entries');
 const badPaths=entries.filter(e=>overlayPathProblem(e.path));b.ok(!badPaths.length,`all overlay paths allowed (${badPaths.length} refused)`);
 const sizesOk=entries.every(e=>natural(e.size)),shaOk=entries.every(e=>typeof e.sha256==='string'&&SHA_ANY.test(e.sha256));b.ok(sizesOk,'all entry sizes are nonnegative integers');b.ok(shaOk,'every entry has SHA-256');if(!sizesOk||!shaOk)return b;
 const lows=entries.map(e=>e.path.toLowerCase()),known=new Set(lows),dirs=new Set();for(const low of lows){const p=low.split('/');for(let i=1;i<p.length;i++)dirs.add(p.slice(0,i).join('/'));}
 b.ok(known.size===entries.length,'no case-insensitive duplicate paths');b.ok(!lows.some(p=>dirs.has(p)),'no file/directory collision');b.ok(!lows.some(p=>p.startsWith('_k2pack/')),'no game file lives under _k2pack');b.ok(manifestVersion(entries)===m.version,'manifest version matches entries');
 const lacking=required.filter(p=>!known.has(p.toLowerCase()));b.ok(!lacking.length,`required overlay files listed: ${lacking.slice(0,3).join(', ')}`);
 const listFile=path.join(dist,'overlay-required.json');if(b.ok(file(listFile),'page overlay-required.json present')){try{const [pageRequired]=readOverlayRequired(listFile),have=new Set(pageRequired.map(p=>p.toLowerCase()));b.ok(required.every(p=>have.has(p.toLowerCase())),'page required list covers verifier requirements');}catch(e){b.ok(false,`page required list invalid: ${e.message}`);}}
 const meta=m.overlay;if(meta!==undefined&&meta!==null){const valid=meta&&typeof meta==='object'&&!Array.isArray(meta)&&meta.format===1&&(!('base' in meta)||(meta.base&&typeof meta.base==='object'&&!Array.isArray(meta.base)))&&Object.entries(meta.base??{}).every(([p,h])=>known.has(p.toLowerCase())&&typeof h==='string'&&SHA_ANY.test(h));b.ok(valid,'overlay block has format 1 and base SHA-256 for listed files');}else b.warn('no overlay block in manifest');
 b.ok(entries.every(e=>[undefined,null,'identity','gzip','br'].includes(e.enc)),'all encodings supported');
 let packs=m.packs??[];const packsOk=Array.isArray(packs)&&packs.every(x=>x&&typeof x.path==='string'&&Number.isInteger(x.size));b.ok(packsOk,'packs is a list of {path,size}');if(!packsOk)packs=[];
 b.ok(packs.every(x=>safeRelpath(x.path)&&x.path.startsWith('_k2pack/')),'all pack paths are under _k2pack');
 const expected=new Set(['manifest.json']);for(const p of packs){expected.add(p.path);const f=disk.get(p.path);b.ok(!!f&&fs.statSync(f).size===p.size,`pack exists with listed size: ${p.path}`);}
 const inPack=entries.filter(packedEntry),badPack=inPack.filter(e=>!natural(e.pack)||e.pack>=packs.length||!natural(e.offset)||!natural(e.csize)||e.offset+e.csize>packs[e.pack].size);
 b.ok(!badPack.length,`all pack records lie in their pack (${badPack.length} invalid)`);
 const loose=[];for(const e of entries.filter(e=>!packedEntry(e))){const name=diskName(e);expected.add(name);const got=disk.get(name);if(!got){b.ok(false,`object missing: ${name}`);continue;}const size=compressed(e)?e.csize:e.size;if(fs.statSync(got).size!==size){b.ok(false,`object size mismatch: ${name}`);continue;}loose.push(e);}
 const extra=[...disk.keys()].filter(p=>!expected.has(p));b.ok(!extra.length,`overlay contains no unlisted objects (${extra.slice(0,4).join(', ')})`);
 b.ok(![...disk.keys()].some(p=>FORBIDDEN.has(p.split('/')[0].toLowerCase())),'no player data, options, engine or modules in overlay');
 const badHash=[];for(const e of sample(loose,minHashes,targetHashes,fullHash)){try{const p=disk.get(diskName(e));let size,sha;if(compressed(e)){const data=unpackRecord(e.enc,readRegular(p),e.size);size=data.length;sha=createHash('sha256').update(data).digest('hex');}else{size=e.size;sha=sha256File(p);}if(size!==e.size||sha!==e.sha256.toLowerCase())badHash.push(e.path);}catch{badHash.push(e.path);}}
 b.ok(!badHash.length,`loose overlay hashes match (${badHash.slice(0,3).join(', ')})`);
 const records=badPack.length?[]:inPack,chosen=fullHash||records.length<=targetHashes?records:[...records].sort(versionOrder).slice(0,targetHashes),badRecords=[];
 for(const e of chosen){try{const r=readPackRecord(disk.get(packs[e.pack].path),e);if(r.size!==e.size||r.sha256!==e.sha256.toLowerCase())badRecords.push(e.path);}catch{badRecords.push(e.path);}}
 b.ok(!badRecords.length,`packed overlay hashes match (${badRecords.slice(0,3).join(', ')})`);
 const baseFile=path.join(dist,'game/manifest.json');if(file(baseFile)){try{const base=JSON.parse(text(baseFile));if(!Array.isArray(base.files))throw new Error('bad files');const have=new Map(base.files.map(e=>[String(e.path).toLowerCase(),String(e.sha256??'').toLowerCase()]));
   if(meta&&typeof meta==='object'&&meta.base&&typeof meta.base==='object')b.ok(Object.entries(meta.base).every(([p,h])=>have.get(p.toLowerCase())===String(h).toLowerCase()),'overlay base matches game hashes');
   b.ok(!('overlay' in base),'base manifest has no overlay block');b.ok(![...have.keys()].some(p=>p.startsWith('game-en/')),'base manifest has no overlay paths');
  }catch(e){b.ok(false,`base manifest unreadable: ${e.message}`);}}
 const game=path.join(dist,'game');if(dir(game))b.ok(!fs.existsSync(path.join(game,'game-en'))&&!fs.readdirSync(game).some(p=>p.toLowerCase().startsWith('game-')),'game/ contains no overlay tree');
 const player=path.join(dist,'video-player.mjs');if(file(player)){const found=/VIDEO_FILES_EN\s*=\s*\{([^}]*)\}/.exec(text(player)),targets=found?[...found[1].matchAll(/["'](videos\/[^"']+)["']/g)].map(m=>m[1]):[];
  if(targets.length&&dir(path.join(dist,'videos')))b.ok(targets.every(p=>file(path.join(dist,p))),'English player videos packaged');else if(targets.length)b.warn('English videos not packaged');}
 const headers=path.join(dist,'_headers'),[rules]=parseHeaders(file(headers)?text(headers):''),got=headersForUrl('/game-en/manifest.json',rules);
 b.ok(same(got['cache-control']??[],['no-cache']),'overlay manifest is not cached');b.ok(same(headersForUrl('/game-en/PROGRAM/x.h',rules)['cache-control']??[],['no-cache']),'overlay files are not cached');
 for(const [k,v] of Object.entries({'cross-origin-opener-policy':'same-origin','cross-origin-embedder-policy':'require-corp','cross-origin-resource-policy':'same-origin','x-robots-tag':'noindex'}))b.ok(same(got[k]??[],[v]),`overlay manifest header ${k}`);
 return b;
}

const TEXT_CLASSES=['align','manual','names','texts','quests'];
export function overlayClassOfPath(p){const low=p.toLowerCase();for(const [cls,prefix] of [['loading','RESOURCE/Textures/Loading/'],['worldmap','RESOURCE/Textures/WorldMap/reload/'],['voice','RESOURCE/Sounds/VOICE/'],['aliases','RESOURCE/INI/ALIASES/']])if(low.startsWith(prefix.toLowerCase()))return cls;return 'text';}
function recursivelySorted(value){return Array.isArray(value)?value.map(recursivelySorted):value&&typeof value==='object'?Object.fromEntries(Object.keys(value).sort().map(k=>[k,recursivelySorted(value[k])])):value;}
export function canonicalOverlayJson(meta){return Buffer.from(JSON.stringify(recursivelySorted(meta),null,1).replace(/[\u007f-\uffff]/g,c=>'\\u'+c.charCodeAt(0).toString(16).padStart(4,'0'))+'\n','ascii');}
/** Verify the expected-overlay reference, class totals, base records and English video. */
export function checkOverlayExpected(dist,expectedPath){
 const b=new Block('overlay-layer','game-en/ vs expected-overlay.json');let exp,ref,refMeta,resources,totals;
 try{exp=JSON.parse(text(expectedPath));if(!exp||exp.format!==1||!Array.isArray(exp.files)||!exp.totals)throw new Error('invalid format');
  ref=new Map(exp.files.filter(e=>e.cls!=='meta').map(e=>[e.path,e]));refMeta=exp.files.find(e=>e.cls==='meta');
  if(!ref.size||[...ref.values()].some(e=>!Number.isInteger(e.size)||typeof e.sha256!=='string'||!/^[a-f0-9]{64}$/.test(e.sha256)))throw new Error('invalid reference files');resources=exp.resources??{};totals=exp.totals;
 }catch(e){b.ok(false,`reference unreadable: ${e.message}`);return b;}
 const manifestFile=path.join(dist,'game-en/manifest.json');if(!b.ok(file(manifestFile),'game-en/manifest.json present'))return b;let manifest,entries;
 try{manifest=JSON.parse(text(manifestFile));if(!Array.isArray(manifest.files))throw new Error('invalid files');entries=new Map(manifest.files.map(e=>[e.path,e]));if(entries.size!==manifest.files.length)throw new Error('duplicate paths');}catch(e){b.ok(false,`overlay manifest unreadable: ${e.message}`);return b;}
 const missing=[...ref.keys()].filter(p=>!entries.has(p)),extra=[...entries.keys()].filter(p=>!ref.has(p));b.ok(!missing.length&&!extra.length,`layer matches exact reference inventory (missing ${missing.length}, extra ${extra.length})`);
 const differ=[...ref].filter(([p,e])=>entries.has(p)&&(entries.get(p).size!==e.size||String(entries.get(p).sha256??'').toLowerCase()!==e.sha256));b.ok(!differ.length,`sizes and hashes match reference (${differ.length} differ)`);
 const wrong=[...ref].filter(([p,e])=>overlayClassOfPath(p)!==(TEXT_CLASSES.includes(e.cls)?'text':e.cls));b.ok(!wrong.length,`file classes match locations (${wrong.length} differ)`);
 const counts={},sizes={};for(const [p,e] of entries){const cls=overlayClassOfPath(p);counts[cls]=(counts[cls]??0)+1;sizes[cls]=(sizes[cls]??0)+(Number.isInteger(e.size)?e.size:0);}
 const byClass=totals.by_class??{},byBytes=totals.bytes_by_class??{};
 for(const c of ['loading','worldmap','voice','aliases']){const n=byClass[c]?.files??0,bytes=byBytes[c]??0;b.ok((counts[c]??0)===n&&(sizes[c]??0)===bytes,`class ${c}: count and bytes match reference`);}
 const textN=TEXT_CLASSES.reduce((n,c)=>n+(byClass[c]?.files??0),0);b.ok((counts.text??0)===textN,'text class count matches reference');
 const base=manifest.overlay&&typeof manifest.overlay==='object'?(manifest.overlay.base??{}):{},hasBase=new Set(Object.keys(base));
 for(const c of ['loading','worldmap']){const r=resources[c];if(!r){b.warn(`reference has no resources.${c}`);continue;}const replaced=[...entries.keys()].filter(p=>overlayClassOfPath(p)===c&&hasBase.has(p)).length;
  b.ok(r.overlay===(counts[c]??0)&&r.bytes===(sizes[c]??0)&&r.new_only===(counts[c]??0)-replaced,`resources.${c} counts and bytes match`);}
 const voice=resources.voice;if(voice){const replaced=[...entries.keys()].filter(p=>overlayClassOfPath(p)==='voice'&&hasBase.has(p)).length;b.ok(voice.selected===(counts.voice??0)&&voice.selected_bytes===(sizes.voice??0)&&voice.replaced===replaced&&voice.added===(counts.voice??0)-replaced,'resources.voice counts and bytes match');}
 const meta=manifest.overlay;if(b.ok(meta&&typeof meta==='object'&&!Array.isArray(meta),'manifest has overlay block')){const raw=canonicalOverlayJson(meta);b.ok(!!refMeta&&raw.length===refMeta.size&&createHash('sha256').update(raw).digest('hex')===refMeta.sha256,'canonical overlay block matches reference metadata');b.ok(meta.language==='English'&&meta.format===1,'overlay block says English and format 1');
  const refBase=Object.fromEntries([...ref].filter(([,e])=>e.base_sha256).map(([p,e])=>[p,e.base_sha256])),actual=Object.fromEntries(Object.entries(meta.base??{}).map(([p,v])=>[p,String(v).toLowerCase()]));
  b.ok(JSON.stringify(recursivelySorted(actual))===JSON.stringify(recursivelySorted(refBase)),'overlay.base matches reference base hashes');}
 const gameFile=path.join(dist,'game/manifest.json');if(file(gameFile)){try{const game=new Set(JSON.parse(text(gameFile)).files.map(e=>e.path.toLowerCase()));b.ok([...entries.keys()].every(p=>!game.has(p.toLowerCase())||hasBase.has(p)),'every overlay file shadowing game has base record');b.ok([...hasBase].every(p=>game.has(p.toLowerCase())),'every base record names a game file');}catch(e){b.ok(false,`base manifest unreadable: ${e.message}`);}}else b.warn('no game manifest: base independence not checked');
 const video=resources.video;if(video&&typeof video.path==='string'){const rel='videos/'+video.path,p=path.join(dist,rel);if(b.ok(file(p),`${rel} present`)){try{if(fs.statSync(p).size!==video.size||sha256File(p)!==video.sha256)b.warn(`${rel} differs from the reference video size/SHA-256`);}catch{b.warn(`${rel} cannot be hashed`);}}}else b.warn('reference has no resources.video');
 b.counts=`${entries.size} files against ${ref.size} in the reference`;return b;
}
