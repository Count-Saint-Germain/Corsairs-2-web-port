/** Independent high-level verification blocks. The Python verifier remains authoritative until all blocks are ported. */
import fs from 'node:fs';
import path from 'node:path';
import { scanTree,sha256File,parseHeaders,headersForUrl,referencedImports,safeRelpath } from './verify_dist_core.mjs';
import { RESOURCE_PATCHES, patchedResourceSource } from '../web/resource-overrides.mjs';
const PAGE_FILES=['index.html','port.js','port-config.js','netplay.js','audio-worklet.js'];
const PAGE_MODULES=['missing-resource-preflight.mjs','save-export.mjs','save-import.mjs','save-owner.mjs','save-protection.mjs','save-read-indicator.mjs','save-tx.mjs','video-player.mjs','touch-controls.mjs'];
const REQUIRED_HEADERS={'cross-origin-opener-policy':'same-origin','cross-origin-embedder-policy':'require-corp','cross-origin-resource-policy':'same-origin','x-robots-tag':'noindex'};
const SAMPLE_URLS=['/','/index.html','/port.js','/build/game.js','/build/game.wasm','/game/manifest.json','/game/PROGRAM/seadogs.c','/videos/Trailer.mp4','/videos/Russian/Invasion.mp4','/no-such-file'];
const NO_CACHE_URLS=['/','/index.html','/port.js','/port-config.js','/overlay.mjs','/overlay-required.json','/build/game.js','/game/manifest.json','/game/PROGRAM/seadogs.c','/game-en/manifest.json','/videos/Trailer.mp4'];
const ALLOWED_TOP=new Set([...PAGE_FILES,...PAGE_MODULES,'build','game','game-en','videos','_headers','robots.txt','vendor']);
const VIDEO_EXPORTS=['port_video_poll','port_video_done','port_video_name_buf'];
const PLAYER=new Set(['save','save_meta','save_tx']);
const text=p=>fs.readFileSync(p,'utf8');
const file=p=>{try{const s=fs.lstatSync(p);return s.isFile()&&!s.isSymbolicLink();}catch{return false;}};
const dir=p=>{try{return fs.statSync(p).isDirectory();}catch{return false;}};
const sameArray=(a,b)=>a.length===b.length&&a.every((x,i)=>x===b[i]);
export class Block {
 constructor(name,counts=''){this.name=name;this.counts=counts;this.checks=[];this.warnings=[];}
 ok(condition,message){this.checks.push([!!condition,message]);return !!condition;}
 warn(message){this.warnings.push(message);}
 get passed(){return this.checks.every(([v])=>v);}
 failures(){return this.checks.filter(([v])=>!v).map(([,m])=>m);}
}
export function checkStructure(dist,files){
 const b=new Block('structure',`${PAGE_FILES.length+PAGE_MODULES.length} required files, ${files.size} files scanned`),headerFile=path.join(dist,'_headers');
 b.ok(!fs.existsSync(headerFile)||!fs.lstatSync(headerFile).isSymbolicLink(),'_headers is not a symlink');
 for(const name of [...PAGE_FILES,'build/game.js','build/game.wasm','game/manifest.json',...PAGE_MODULES])b.ok(file(path.join(dist,name)),`required file present: ${name}`);
 b.ok(file(headerFile),'_headers present');const [rules,duplicates]=parseHeaders(file(headerFile)?text(headerFile):'');
 const star=rules.find(([p])=>p==='/*')?.[1]??{};b.ok(Object.keys(star).length>0,'_headers has a /* rule');
 for(const [key,value] of Object.entries(REQUIRED_HEADERS))b.ok(star[key]===value,`_headers /* sets ${key}: ${value}`);
 b.ok(!duplicates.length,`no repeated header in a rule: ${duplicates.slice(0,5).join(', ')}`);
 for(const url of SAMPLE_URLS){const got=headersForUrl(url,rules);b.ok(!Object.values(got).some(values=>values.length>1),`${url}: no duplicate headers`);b.ok(Object.entries(REQUIRED_HEADERS).every(([k,v])=>sameArray(got[k]??[],[v])),`${url}: required headers present`);}
 for(const url of NO_CACHE_URLS)b.ok(sameArray(headersForUrl(url,rules)['cache-control']??[],['no-cache']),`${url}: Cache-Control: no-cache`);
 const imports=referencedImports(dist).referenced;
 const moduleDirs=new Set([...imports].filter(p=>p.includes('/')).map(p=>p.split('/')[0]));
 const unexpected=fs.readdirSync(dist).filter(x=>!ALLOWED_TOP.has(x)&&!imports.has(x)&&!moduleDirs.has(x));b.ok(!unexpected.length,`nothing unexpected at dist root: ${unexpected.slice(0,6).join(', ')}`);
 for(const root of moduleDirs){
  if(ALLOWED_TOP.has(root)||!dir(path.join(dist,root)))continue;
  const extra=[...scanTree(path.join(dist,root)).files.keys()].map(p=>`${root}/${p}`).filter(p=>!imports.has(p));
  b.ok(!extra.length,`${root}/ contains only referenced modules: ${extra.slice(0,4).join(', ')}`);
 }
 const vendor=path.join(dist,'vendor');if(dir(vendor)){const {files:vendored}=scanTree(vendor);b.ok([...vendored.keys()].every(x=>x==='brotli/k2br.wasm'),'vendor contains only the Brotli decoder');}
 const robots=path.join(dist,'robots.txt');if(b.ok(file(robots),'robots.txt present')){const s=text(robots).toLowerCase().replace(/\s+/g,' ');b.ok(s.includes('user-agent: *')&&s.includes('disallow: /'),'robots.txt disallows everything');}
 const game=path.join(dist,'game');if(b.ok(dir(game),'game/ directory present'))b.ok(!fs.readdirSync(game).some(x=>PLAYER.has(x.toLowerCase())),'game/ contains no player data directories');
 const problems=scanTree(dist).problems;b.ok(!problems.length,`no symlinks or special files in dist: ${problems.slice(0,5).join('; ')}`);return b;
}
export function checkPageModules(dist,files){
 const b=new Block('page-modules'),{seen,referenced,unreadable}=referencedImports(dist);
 b.ok(!unreadable.length,`all modules readable: ${unreadable.slice(0,5).join(', ')}`);const absent=[...referenced].filter(x=>!files.has(x));b.ok(!absent.length,`all imported files packaged: ${absent.slice(0,5).join(', ')}`);
 b.ok(referenced.has('save-owner.mjs')&&files.has('save-owner.mjs'),'save-owner.mjs remains referenced and packaged');for(const name of PAGE_MODULES)b.ok(files.has(name),`page module packaged: ${name}`);
 if(b.ok(file(path.join(dist,'index.html')),'index.html present')){const html=text(path.join(dist,'index.html'));const local=[...html.matchAll(/<script\b[^>]*\bsrc\s*=\s*["']([^"']+)["']/gi)].map(x=>x[1]).filter(x=>!/^(https?:\/\/|\/\/|\/)/.test(x)).map(x=>path.posix.normalize(x.replace(/^\.\//,'')));b.ok(local.every(x=>files.has(x)),'all HTML script sources packaged');}
 b.counts=`${referenced.size} referenced imports, ${seen.size} modules scanned`;return b;
}
export function checkBuild(dist){
 const b=new Block('build'),js=path.join(dist,'build/game.js'),wasm=path.join(dist,'build/game.wasm');
 if(b.ok(file(js)&&file(wasm),'game.js and game.wasm present')){const source=text(js),bytes=fs.readFileSync(wasm);b.ok(source.includes('_port_video_poll'),'video bridge marker in game.js');b.ok(source.includes('game.wasm'),'game.js references game.wasm');b.ok(VIDEO_EXPORTS.every(x=>source.includes('_'+x)),'game.js exposes video bridge exports');b.ok(bytes.subarray(0,4).equals(Buffer.from([0,97,115,109])),'wasm magic present');b.ok(bytes.length>8,'wasm payload present');b.ok(VIDEO_EXPORTS.every(x=>bytes.includes(Buffer.from(x))),'wasm contains video bridge export names');b.ok(source.length>0,'game.js not empty');b.counts=`wasm ${bytes.length} bytes, js ${Buffer.byteLength(source)} bytes`;}
 const owner=path.join(dist,'save-owner.mjs');if(b.ok(file(owner),'save-owner.mjs present'))b.ok(text(owner).includes('save-backup'),'page lifetime save lock marker present');return b;
}
function mp4Problem(p){try{const fd=fs.openSync(p,fs.constants.O_RDONLY|(fs.constants.O_NOFOLLOW??0));try{const info=fs.fstatSync(fd);if(!info.isFile()||info.nlink!==1)throw new Error('not a singly linked regular file');const size=info.size,seen=[];let pos=0;while(pos<size&&seen.length<12){const h=Buffer.alloc(8);if(fs.readSync(fd,h,0,8,pos)<8)break;let n=h.readUInt32BE(0);const kind=h.toString('ascii',4,8);seen.push(kind);if(n===1){const ext=Buffer.alloc(8);if(fs.readSync(fd,ext,0,8,pos+8)<8)return 'truncated box';n=Number(ext.readBigUInt64BE());}if(n<8&&n!==0)return 'corrupt box size';if(n===0)break;pos+=n;}if(!seen.length||seen[0]!=='ftyp')return 'does not start with an ftyp box';if(seen.includes('mdat')&&(!seen.includes('moov')||seen.indexOf('mdat')<seen.indexOf('moov')))return 'mdat before moov';return null;}finally{fs.closeSync(fd);}}catch(e){return e.message;}}
export function checkVideos(dist,videosWeb=null){
 const b=new Block('videos'),root=path.join(dist,'videos');if(!b.ok(dir(root),'videos/ directory present'))return b;const {files,problems}=scanTree(root);b.ok(!problems.length,'videos contain no links or special files');
 b.ok(![...files.keys()].some(p=>p.split('/').length>2),'no video nesting deeper than one subdirectory');b.ok([...files.keys()].every(p=>p.toLowerCase().endsWith('.mp4')),'only MP4 files in videos/');b.ok(files.size>0,'at least one video packaged');
 const invalid=[...files].map(([p,f])=>[p,mp4Problem(f)]).filter(([,reason])=>reason);b.ok(!invalid.length,`video MP4 boxes are streamable: ${JSON.stringify(invalid.slice(0,3))}`);
 const player=path.join(dist,'video-player.mjs');if(file(player)){const block=/VIDEO_FILES\s*=\s*\{([^}]*)\}/.exec(text(player)),targets=block?[...block[1].matchAll(/["'](videos\/[^"']+)["']/g)].map(m=>m[1]):[];b.ok(targets.length>0,'video player declares VIDEO_FILES');b.ok(targets.every(t=>files.has(t.slice('videos/'.length))),'every requested video is packaged');}
 if(videosWeb&&dir(videosWeb)){const expected=new Set([...scanTree(videosWeb).files.keys()].filter(x=>x.toLowerCase().endsWith('.mp4'))),actual=new Set(files.keys());b.ok(expected.size===actual.size&&[...expected].every(x=>actual.has(x)),'video names match videos-web');}else b.warn('videos-web not available: name comparison skipped');b.counts=`${files.size} mp4`;return b;
}
export function checkFreshness(dist,webSrc,buildSrc,require=false){const b=new Block('freshness');if(!dir(webSrc)){b.warn(`${webSrc} not found: freshness not checked`);return b;}let n=0;const problems=[];
 for(const name of fs.readdirSync(dist).sort()){const p=path.join(dist,name),src=path.join(webSrc,name);if(file(p)&&/\.(js|mjs|html)$/.test(name)&&file(src)){n++;if(!fs.readFileSync(p).equals(fs.readFileSync(src)))problems.push(name);}}
 for(const name of ['game.js','game.wasm']){const src=path.join(buildSrc,name),p=path.join(dist,'build',name);if(file(src)){n++;try{if(fs.statSync(p).size!==fs.statSync(src).size||sha256File(p)!==sha256File(src))problems.push('build/'+name);}catch{problems.push('build/'+name);}}}
 const msg=`${n} files compared; ${problems.length?'differ: '+problems.join(', '):'all identical'}`;if(require)b.ok(!problems.length,msg);else if(problems.length)b.warn(msg);else b.ok(true,msg);b.counts=`${n} files compared`;return b;}
export function checkStability(before,after){const b=new Block('stability',`${before.size} entries fingerprinted`),keys=new Set([...before.keys(),...after.keys()]),changed=[...keys].filter(k=>before.get(k)!==after.get(k));b.ok(!changed.length,`file fingerprints unchanged (${changed.length} changed: ${changed.slice(0,4).join(', ')})`);return b;}
export function sourceCandidates(p,rules){const out=[p],low=p.toLowerCase();for(const r of rules){const src=String(r.from).replace(/^\/+|\/+$/g,''),dst=String(r.to).replace(/^\/+|\/+$/g,'');if(low.startsWith(dst.toLowerCase()+'/')&&!p.slice(dst.length+1).includes('/')){const name=p.slice(dst.length+1),head=src.toLowerCase().startsWith(dst.toLowerCase()+'/')?p.slice(0,dst.length):dst;out.push((src.toLowerCase().startsWith(dst.toLowerCase()+'/')?head+src.slice(dst.length):src)+'/'+name);}}return out;}
export function checkSourceGame(dist,source,fullHash=false,relocateRules=[]){const b=new Block('source-game');if(!b.ok(dir(source),'source game directory exists'))return b;let entries;try{entries=JSON.parse(text(path.join(dist,'game/manifest.json'))).files;if(!Array.isArray(entries))throw new Error('bad files');}catch(e){b.ok(false,`manifest unreadable: ${e.message}`);return b;}
 const missing=[],sizeBad=[],hashBad=[];for(const e of entries){const p=e.path;if(typeof p!=='string'||PLAYER.has(p.split('/')[0].toLowerCase())||!safeRelpath(p))continue;let src,info;for(const c of sourceCandidates(p,relocateRules)){try{src=path.join(source,c);info=fs.lstatSync(src);break;}catch{src=null;}}
  if(!src){missing.push(p);continue;}if(!info.isFile()){sizeBad.push(p);continue;}
  // Known pristine sources are packaged with verified bundled overrides.
  // Already-patched inputs also work.
  const patch=RESOURCE_PATCHES.find(x=>p.toLowerCase()===x.path.toLowerCase()&&e.sha256===x.patchedHash);
  if(patch){try{src=patchedResourceSource(p,src);if(src!==patch.file)throw new Error('unknown override');info=fs.lstatSync(src);}catch{hashBad.push(p);continue;}}
  if(!info.isFile()||info.size!==e.size)sizeBad.push(p);else if(fullHash){try{if(sha256File(src)!==e.sha256)hashBad.push(p);}catch{hashBad.push(p);}}
 }
 b.ok(!missing.length,`every manifest file exists in source (${missing.length} missing: ${missing.slice(0,4).join(', ')})`);b.ok(!sizeBad.length,`source sizes match (${sizeBad.length} differ)`);if(fullHash)b.ok(!hashBad.length,`source hashes match (${hashBad.length} differ)`);else {b.ok(!hashBad.length,`resource overrides verified (${hashBad.length} invalid)`);b.warn('source comparison is by size only, except verified resource overrides');}b.counts=`${entries.length} entries compared${fullHash?' (sizes + sha256)':' (sizes)'}`;return b;}
