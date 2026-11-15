#!/usr/bin/env node
/** Assemble an independently hostable browser distribution using Node.js. */
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { gameFiles, overlayFiles, overlayMissingRequired, overlayBaseMismatches, manifestFor, overlayManifestFor,
  fileSha256, packableSet, analyseFiles, planPacks, packObjectName, writePack, verifyPack, codecPass, unpackCheck,
  packedKey, PACK_LEVEL, PACK_ENC, PACK_MAX_FILE, PACK_TARGET, BR_QUALITY } from './gamefiles.mjs';
import { requestSizes, histogram, simulate } from './install_model.mjs';

const HERE=path.dirname(fileURLToPath(import.meta.url));
const BUILD=path.resolve(HERE,'../build_web/www');
const DEFAULT_VIDEOS=path.resolve(HERE,'../../../videos-web');
const HEADERS='/*\n  Cross-Origin-Opener-Policy: same-origin\n  Cross-Origin-Embedder-Policy: require-corp\n  Cross-Origin-Resource-Policy: same-origin\n  X-Robots-Tag: noindex\n  Cache-Control: no-cache\n';
const order=(a,b)=>a<b?-1:a>b?1:0;

/** Follow literal page imports, including inline module imports. */
export function pageAssets(root=HERE) {
  const out=['index.html','port.js','port-config.js','netplay.js','audio-worklet.js','vendor/brotli/k2br.wasm'];
  const pending=['index.html','port.js','port-config.js','netplay.js','audio-worklet.js'], seen=new Set(out);
  while(pending.length) {
    const name=pending.pop(),source=fs.readFileSync(path.join(root,name),'utf8');
    const imports=[...source.matchAll(/(?:\bfrom\s*|\bimport\s*(?:\(\s*)?)["']\.\/([^"']+)["']/g)].map(m=>m[1]);
    if(name==='index.html')for(const m of source.matchAll(/<script\b[^>]*\bsrc\s*=\s*["']([^"']+)["']/gi))if(!/^(https?:\/\/|\/\/|\/)/.test(m[1]))imports.push(m[1].replace(/^\.\//,''));
    for(const ref of imports){const target=path.posix.normalize(path.posix.join(path.posix.dirname(name),ref));
      if(target==='..'||target.startsWith('../'))throw new Error(`page import leaves web root: ${name}: ${ref}`);
      if(!seen.has(target)){seen.add(target);out.push(target);if(/\.(mjs|js)$/.test(target))pending.push(target);}
    }
  }
  return out.sort(order);
}
export function parseSize(value) {
  const m=/^\s*(\d+)\s*([kKmM]?)[iI]?[bB]?\s*$/.exec(String(value));if(!m)throw new Error(`not a size: ${value}`);
  const n=Number(m[1])*({k:1024,m:1048576}[m[2].toLowerCase()]??1);if(!Number.isSafeInteger(n))throw new Error(`size too large: ${value}`);return n;
}
export function overlayDirName(name){if(!/^[a-z]{2,8}$/.test(name??''))throw new Error(`--overlay-name must be 2 to 8 lowercase letters, got ${name}`);return `game-${name}`;}
function inside(a,b){const r=path.relative(b,a);return r===''||(!path.isAbsolute(r)&&r!=='..'&&!r.startsWith(`..${path.sep}`));}
/** Resolve a not-yet-created output through the nearest existing ancestor. */
function realDestination(p){let current=path.resolve(p), tail=[];for(;;){try{return path.join(fs.realpathSync(current),...tail);}catch(e){if(e.code!=='ENOENT')throw e;const parent=path.dirname(current);if(parent===current)throw e;tail.unshift(path.basename(current));current=parent;}}}
export function requireEmptyOutput(out) {
  let st;try{st=fs.lstatSync(out);}catch(e){if(e.code==='ENOENT')return;throw e;}
  if(st.isSymbolicLink()||!st.isDirectory())throw new Error('output must be a new or empty non-symlink directory');
  if(fs.readdirSync(out).length)throw new Error('output is not empty; choose a clean output directory');
}
function copy(src,dst){
  fs.mkdirSync(path.dirname(dst),{recursive:true});let input,output;
  try {input=fs.openSync(src,fs.constants.O_RDONLY|(fs.constants.O_NOFOLLOW??0));const s=fs.fstatSync(input);if(!s.isFile()||s.nlink!==1)throw new Error(`input must be a singly linked regular file: ${src}`);
    output=fs.openSync(dst,'wx');const buf=Buffer.alloc(1<<20);for(;;){const n=fs.readSync(input,buf,0,buf.length,null);if(!n)break;let pos=0;while(pos<n)pos+=fs.writeSync(output,buf,pos,n-pos);}
  }finally{if(input!==undefined)fs.closeSync(input);if(output!==undefined)fs.closeSync(output);}
}
export function videoFiles(root) {
  const out=new Map();if(!root||!fs.existsSync(root))return out;const base=path.resolve(root);
  function visit(dir,depth){for(const e of fs.readdirSync(dir,{withFileTypes:true}).sort((a,b)=>order(a.name,b.name))){const src=path.join(dir,e.name),s=fs.lstatSync(src);
    if(s.isSymbolicLink())throw new Error(`videos directory contains a symlink: ${src}`);
    if(s.isDirectory()){if(depth>=1)throw new Error(`videos directory nests deeper than one level: ${src}`);visit(src,depth+1);}
    else if(e.name.toLowerCase().endsWith('.mp4')){if(!s.isFile()||s.nlink!==1)throw new Error(`videos directory holds a hard-linked or special file: ${src}`);out.set('videos/'+path.relative(base,src).split(path.sep).join('/'),src);}
  }}visit(base,0);return out;
}
function videoTargets(table='VIDEO_FILES'){const source=fs.readFileSync(path.join(HERE,'video-player.mjs'),'utf8'),m=new RegExp(table+'\\s*=\\s*\\{([^}]*)\\}').exec(source);return m?[...m[1].matchAll(/["'](videos\/[^"']+)["']/g)].map(x=>x[1]):[];}
async function writeSingle(rel,src,out,info) {
  const stat=fs.lstatSync(src);if(!stat.isFile()||stat.nlink!==1)throw new Error(`input must be a singly linked regular file: ${src}`);
  if(info.enc){const dest=path.join(out,packedKey(rel,info.enc));await fs.promises.mkdir(path.dirname(dest),{recursive:true});const fh=await fs.promises.open(dest,'wx');
    async function sink(bytes){let n=0;while(n<bytes.length){const r=await fh.write(bytes,n,bytes.length-n,null);if(!r.bytesWritten)throw new Error('short write');n+=r.bytesWritten;}}
    let result;try{result=await codecPass(info.enc,src,sink,PACK_LEVEL,info.quality??BR_QUALITY);}finally{await fh.close();}
    if(result[0]!==info.size||result[1]!==info.sha256||result[2]!==info.csize)throw new Error(`${rel}: the file changed while the dist was built`);
    if(!unpackCheck(info.enc,dest,info.size,info.sha256))throw new Error(`${rel}: packed copy does not unpack to source content`);
    return {enc:info.enc,csize:info.csize};
  }
  copy(src,path.join(out,rel));return null;
}
/** Write packed and/or separate game objects. Returns [packed, packs, hashes]. */
export async function writeGame(files,out,{compress=true,pack=true,maxFile=PACK_MAX_FILE,target=PACK_TARGET,codec=PACK_ENC,quality=BR_QUALITY,workers=4}={}) {
  const eligible=compress?packableSet(files,codec==='br'?['gzip','br']:['gzip']):new Set();
  const info=await analyseFiles(files,eligible,PACK_LEVEL,workers,codec,quality), packed=new Map(),packs=[],hashes=new Map();
  if(!pack){for(const [p,src] of files){const got=await writeSingle(p,src,out,{...info.get(p),quality});if(got)packed.set(p,got);}return [packed,packs,hashes];}
  const [plan,loose]=planPacks(new Map([...files.keys()].map(p=>[p,info.get(p).csize])),maxFile,target);
  for(const p of [...loose].sort(order)){const got=await writeSingle(p,files.get(p),out,{...info.get(p),quality});if(got)packed.set(p,got);}
  for(let index=0;index<plan.length;index++){
    const members=plan[index].map(p=>({path:p,src:files.get(p),...info.get(p)})),name=packObjectName(index,members),file=path.join(out,name);
    const spans=await writePack(file,members,PACK_LEVEL,quality);
    const entries=members.map((m,i)=>({offset:spans[i][0],csize:spans[i][1],enc:m.enc,size:m.size,sha256:m.sha256}));
    if(!await verifyPack(file,entries,spans.reduce((a,s)=>a+s[1],0)))throw new Error(`${name}: pack does not read back as its source files`);
    for(let i=0;i<members.length;i++){const m=members[i],[offset,csize]=spans[i],record={pack:index,offset,csize};if(m.enc)record.enc=m.enc;packed.set(m.path,record);hashes.set(m.path,m.sha256);}
    packs.push({path:name,size:spans.reduce((a,s)=>a+s[1],0),files:members.length});
  }
  return [packed,packs,hashes];
}
export async function estimate(files,{codec=PACK_ENC,quality=BR_QUALITY,workers=4,maxFile=PACK_MAX_FILE,target=PACK_TARGET,out=console.log}={}){
  const eligible=packableSet(files,codec==='br'?['gzip','br']:['gzip']);const info=await analyseFiles(files,eligible,PACK_LEVEL,workers,codec,quality);
  const gzipInfo=codec==='br'?await analyseFiles(files,eligible,PACK_LEVEL,workers,'gzip',quality):info;
  const table=new Map();for(const [p,i] of info){const ext=path.posix.extname(p).toLowerCase()||'(none)',r=table.get(ext)??{files:0,raw:0,shipped:0,packed:0,br:0,gzip_only:0};r.files++;r.raw+=i.size;r.shipped+=i.csize;r.packed+=Number(!!i.enc);r.br+=Number(i.enc==='br');r.gzip_only+=gzipInfo.get(p).csize;table.set(ext,r);}
  const total={files:0,raw:0,shipped:0,packed:0,br:0,gzip_only:0};for(const row of table.values())for(const key of Object.keys(total))total[key]+=row[key];
  const br=total.br>0,pad=(value,n)=>String(value).padStart(n);out('ext'.padEnd(8)+pad('files',7)+pad('packed',8)+(br?pad('as br',7):'')+pad('raw MB',10)+pad('shipped MB',12)+pad('ratio',8)+(br?pad('gzip MB',10)+pad('saved',8):''));
  const line=(name,r)=>out(name.padEnd(8)+pad(r.files,7)+pad(r.packed,8)+(br?pad(r.br,7):'')+pad((r.raw/1e6).toFixed(1),10)+pad((r.shipped/1e6).toFixed(1),12)+pad((r.raw?100*r.shipped/r.raw:100).toFixed(1),7)+'%'+(br?pad((r.gzip_only/1e6).toFixed(1),10)+pad(((r.gzip_only-r.shipped)/1e6).toFixed(1),8):''));
  for(const [ext,row] of [...table].sort((a,b)=>b[1].raw-a[1].raw))line(ext,row);line('TOTAL',total);
  const rows=[...info].map(([p,i])=>[p,i.size,i.csize]);const hist=histogram(rows.map(r=>r[2]));
  out('requests by shipped size (one request per file):');
  for(const [label,n,bytes] of hist)out(`${label}: ${n} files, ${(bytes/1e6).toFixed(1)} MB`);
  const whole=requestSizes(rows),packed=requestSizes(rows,[maxFile,target]);out(`requests: ${whole.length} file by file; ${packed.length} with packs`);
  out('modelled network time, seconds (page CPU floor ~30 s; installation takes about the larger):');
  for(const [mbit,rtt] of [[20,.05],[100,.05],[100,.1],[100,.2],[300,.1]])out(`${mbit} Mbit/s, RTT ${rtt*1000} ms: ${simulate(whole,rtt,mbit*1e6/8,1).toFixed(0)} s (1), ${simulate(whole,rtt,mbit*1e6/8,6).toFixed(0)} s (6), ${simulate(packed,rtt,mbit*1e6/8,1).toFixed(0)} s (packs 1), ${simulate(packed,rtt,mbit*1e6/8,6).toFixed(0)} s (packs 6)`);
  return info;
}
export async function buildDistribution(options) {
  const {game,out='dist',videos,overlayDir,overlayName='en',overlayNoRequiredCheck=false,overlaySkipBaseCheck=false,
    noCompress=false,noPack=false,codec='gzip',quality=BR_QUALITY,maxFile=PACK_MAX_FILE,target=PACK_TARGET,estimateOnly=false,buildDir=BUILD} = options;
  if(!game)throw new Error('--game is required');if(!['gzip','br'].includes(codec))throw new Error(`unknown codec: ${codec}`);
  if(!Number.isInteger(quality)||quality<0||quality>11||!Number.isSafeInteger(maxFile)||maxFile<0||!Number.isSafeInteger(target)||target<0)throw new Error('invalid compression or pack options');
  let ovFiles=null,ovMeta=null,ovName=null;
  if(overlayDir){ovName=overlayDirName(overlayName);[ovFiles,ovMeta]=overlayFiles(path.resolve(overlayDir));const missing=overlayNoRequiredCheck?[]:overlayMissingRequired(ovFiles);
    if(missing.length)throw new Error(`overlay: required files are missing: ${missing.join(', ')}`);
    const a=fs.realpathSync(overlayDir),b=fs.realpathSync(game);if(inside(a,b)||inside(b,a))throw new Error('overlay folder and game folder must not contain each other');
  }
  const files=gameFiles(path.resolve(game));
  if(estimateOnly){await estimate(files,{codec,quality,maxFile,target});if(ovFiles)await estimate(ovFiles,{codec,quality,maxFile,target});return null;}
  for(const f of ['game.js','game.wasm'])if(!fs.existsSync(path.join(buildDir,f)))throw new Error(`missing ${buildDir}/${f}: run recomp/build_web.sh first`);
  const output=path.resolve(out);requireEmptyOutput(output);const gameRoot=fs.realpathSync(game),targetRoot=realDestination(output);
  if(inside(targetRoot,gameRoot))throw new Error('output must not be inside the input game directory');
  if(overlayDir){const source=fs.realpathSync(overlayDir);if(inside(source,targetRoot)||inside(targetRoot,source))throw new Error('output and the overlay folder must not contain each other');}
  const videoRoot=videos??(fs.existsSync(DEFAULT_VIDEOS)?DEFAULT_VIDEOS:null);
  for(const [label,source] of [['game',gameRoot],['web',fs.realpathSync(HERE)],['build',fs.realpathSync(buildDir)],...(videoRoot&&fs.existsSync(videoRoot)?[['videos',fs.realpathSync(videoRoot)]]:[])])
    if(inside(targetRoot,source)||inside(source,targetRoot))throw new Error(`output overlaps the ${label} input directory`);
  const vids=videoFiles(videoRoot);
  if(ovMeta&&!overlaySkipBaseCheck){const needed=Object.keys(ovMeta.base??{}),byLow=new Map([...files].map(([p,src])=>[p.toLowerCase(),src])),base={files:needed.filter(p=>byLow.has(p.toLowerCase())).map(p=>({path:p,sha256:fileSha256(byLow.get(p.toLowerCase()))}))},wrong=overlayBaseMismatches(ovMeta,base);if(wrong.length)throw new Error(`overlay: built on another Russian distribution, SHA-256 differs from the game for: ${wrong.slice(0,5).join(', ')}`);}
  for(const f of pageAssets())copy(path.join(HERE,f),path.join(output,f));
  for(const f of ['game.js','game.wasm'])copy(path.join(buildDir,f),path.join(output,'build',f));
  const args={compress:!noCompress,pack:!noPack,maxFile,target,codec,quality},gameOut=path.join(output,'game');
  const [packed,packs,hashes]=await writeGame(files,gameOut,args);
  let ovResult=null;if(ovFiles){const ovOut=path.join(output,ovName),[ovPacked,ovPacks,ovHashes]=await writeGame(ovFiles,ovOut,args);ovResult=[ovOut,ovPacked,ovPacks,ovHashes];}
  for(const [p,src] of vids)copy(src,path.join(output,p));
  for(const targetName of videoTargets())if(vids.size&&!vids.has(targetName))console.warn(`WARNING: video-player requests ${targetName}, missing from package`);
  if(ovFiles)for(const targetName of videoTargets('VIDEO_FILES_EN'))if(!vids.has(targetName))console.warn(`WARNING: English video ${targetName} missing from package`);
  const gameSources=new Map([...files].map(([p,src])=>[p,packed.has(p)?src:path.join(gameOut,p)]));
  const manifest=manifestFor(gameSources,packed,packs,hashes);fs.mkdirSync(gameOut,{recursive:true});fs.writeFileSync(path.join(gameOut,'manifest.json'),JSON.stringify(manifest),{flag:'wx'});
  let ovManifest=null;if(ovResult){const [ovOut,ovPacked,ovPacks,ovHashes]=ovResult,sources=new Map([...ovFiles].map(([p,src])=>[p,ovPacked.has(p)?src:path.join(ovOut,p)]));ovManifest=overlayManifestFor(sources,ovPacked,ovPacks,ovHashes,ovMeta);fs.mkdirSync(ovOut,{recursive:true});fs.writeFileSync(path.join(ovOut,'manifest.json'),JSON.stringify(ovManifest),{flag:'wx'});}
  fs.writeFileSync(path.join(output,'_headers'),HEADERS,{flag:'wx'});fs.writeFileSync(path.join(output,'robots.txt'),'User-agent: *\nDisallow: /\n',{flag:'wx'});
  const raw=manifest.files.reduce((n,e)=>n+e.size,0),wire=manifest.files.reduce((n,e)=>n+(e.csize??e.size),0);
  console.log(`${output}: page + build + ${files.size} game files (${(raw/1e6).toFixed(0)} MB; ${(wire/1e6).toFixed(0)} MB to download), ${packs.length} packs, manifest ${manifest.version}, ${vids.size} videos`);
  if(ovManifest)console.log(`${ovName}: ${ovManifest.files.length} overlay files, manifest ${ovManifest.version}`);
  return {manifest,overlay:ovManifest};
}
function parseArgs(args){const o={};const values={'--game':'game','--out':'out','--videos':'videos','--overlay-dir':'overlayDir','--overlay-name':'overlayName','--codec':'codec','--br-quality':'quality','--pack-max-file':'maxFile','--pack-size':'target','--build-dir':'buildDir'};const flags={'--no-compress':'noCompress','--no-pack':'noPack','--estimate':'estimateOnly','--overlay-no-required-check':'overlayNoRequiredCheck','--overlay-skip-base-check':'overlaySkipBaseCheck'};
  for(let i=0;i<args.length;i++){const a=args[i];if(a==='--help'||a==='-h'){console.log('Usage: node make_dist.mjs --game DIR [--out DIR] [--videos DIR] [--no-compress] [--no-pack] [--codec gzip|br] [--overlay-dir DIR] [--estimate]');return null;}if(flags[a]){o[flags[a]]=true;continue;}const eq=a.indexOf('='),key=eq<0?a:a.slice(0,eq),value=eq<0?args[++i]:a.slice(eq+1);if(!values[key]||value===undefined||value==='')throw new Error(`invalid option: ${a}`);o[values[key]]=['maxFile','target'].includes(values[key])?parseSize(value):values[key]==='quality'?Number(value):value;}return o;
}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{const o=parseArgs(process.argv.slice(2));if(o)await buildDistribution(o);}catch(e){console.error(e.message);process.exitCode=1;}}
