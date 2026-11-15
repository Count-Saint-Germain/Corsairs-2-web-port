#!/usr/bin/env node
/** Development server for a game tree, videos, optional compression and English overlay. */
import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { createHash, timingSafeEqual } from 'node:crypto';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { createStaticHandler } from '../../../scripts/serve_distribution.mjs';
import { gameFiles, manifestFor, overlayFiles, overlayMissingRequired, overlayManifestFor,
  packableSet, analyseFiles, planPacks, packObjectName, writePack, verifyPack, codecPass,
  fileSha256, PACK_LEVEL, PACK_MAX_FILE, PACK_TARGET } from './gamefiles.mjs';
import { applyResourceOverrides, patchedResourceSource, RESOURCE_PATCHES } from './resource-overrides.mjs';

const HERE=path.dirname(fileURLToPath(import.meta.url)),REPO=path.resolve(HERE,'../..');
const BUILD=process.env.PORT_WWW_DIR || path.resolve(HERE,'../build_web/streaming');
const DEFAULT_VIDEOS=path.resolve(REPO,'../videos-web');
const PACK_SUFFIX={gzip:'.gz',br:'.br'};
const sha1=s=>createHash('sha1').update(s).digest('hex');
function real(p){let current=path.resolve(p),tail=[];for(;;){try{return path.join(fs.realpathSync(current),...tail);}catch(e){if(e.code!=='ENOENT')throw e;const parent=path.dirname(current);if(parent===current)throw e;tail.unshift(path.basename(current));current=parent;}}}
export function isWithin(root,candidate){const r=path.relative(real(root),real(candidate));return r===''||(!path.isAbsolute(r)&&r!=='..'&&!r.startsWith(`..${path.sep}`));}
function overlaps(a,b){return isWithin(a,b)||isWithin(b,a);}
export function validateGameLayout(game,videos=null,cache=null,web=HERE,build=BUILD){
  if(cache&&overlaps(game,cache))throw new Error('pack cache overlaps the game directory');
  for(const root of [web,build,...(videos?[videos]:[])])if(overlaps(root,game))throw new Error('game directory overlaps a static serving root');
}
function infoStamp(file){const s=fs.statSync(file,{bigint:true});return `${s.size}:${s.mtimeNs}`;}
/** Reject symlinks at every descendant component, hard links and paths escaping the root. */
export function checkedAsset(asset,root){
  if(!asset)return null;
  try{const rootAbs=path.resolve(root),candidate=path.resolve(asset),r=path.relative(rootAbs,candidate);
    if(path.isAbsolute(r)||r==='..'||r.startsWith(`..${path.sep}`))return null;
    const s=fs.lstatSync(candidate);if(!s.isFile()||s.nlink!==1||!isWithin(rootAbs,candidate))return null;
    let current=rootAbs;for(const component of r.split(path.sep)){current=path.join(current,component);if(fs.lstatSync(current).isSymbolicLink())return null;}
    return candidate;
  }catch{return null;}
}
function isolatedHeaders(res){res.setHeader('Cross-Origin-Opener-Policy','same-origin');res.setHeader('Cross-Origin-Embedder-Policy','require-corp');res.setHeader('Cross-Origin-Resource-Policy','same-origin');res.setHeader('Cache-Control','no-store');res.setHeader('Accept-Ranges','bytes');}
function error(res,status,text,head=false){const body=Buffer.from(text+'\n');res.writeHead(status,{'Content-Type':'text/plain; charset=utf-8','Content-Length':body.length});res.end(head?undefined:body);}
function auth(req,password){if(!password)return true;const header=req.headers.authorization??'';if(!header.startsWith('Basic '))return false;
 try{const decoded=Buffer.from(header.slice(6),'base64').toString('utf8'),idx=decoded.indexOf(':'),given=Buffer.from(idx<0?'':decoded.slice(idx+1)),expected=Buffer.from(password);return given.length===expected.length&&timingSafeEqual(given,expected);}catch{return false;}}
async function layoutFor(files,eligible,{maxFile,target,codec,quality}){
 const info=await analyseFiles(files,eligible,PACK_LEVEL,4,codec,quality),[plan,loose]=planPacks(new Map([...files.keys()].map(p=>[p,info.get(p).csize])),maxFile,target);
 const packs=new Map(),meta=[],packed=new Map(),hashes=new Map(),stamp=new Map([...files].map(([p,src])=>[p,infoStamp(src)]));
 for(let i=0;i<plan.length;i++){
  const members=plan[i].map(p=>({path:p,src:files.get(p),...info.get(p)})),name=packObjectName(i,members);let pos=0;
  for(const m of members){const record={pack:i,offset:pos,csize:m.csize};if(m.enc)record.enc=m.enc;packed.set(m.path,record);hashes.set(m.path,m.sha256);pos+=m.csize;}
  packs.set(name,members);meta.push({path:name,size:pos,files:members.length});
 }
 for(const p of loose){const item=info.get(p);if(item.enc){packed.set(p,{enc:item.enc,csize:item.csize});hashes.set(p,item.sha256);}}
 return {packs,meta,packed,hashes,stamp};
}
async function handlerFor(root){try{return await createStaticHandler(root,{cacheControl:'no-store'});}catch(e){if(e.code==='ENOENT')return null;throw e;}}

/** Returns a server and an explicit cleanup function for an optional private pack cache. */
export async function createDevServer(options={}){
 const {game=null,web=HERE,build=BUILD,host='127.0.0.1',password=null,compress=false,pack=false,codec='gzip',quality=5,
  maxFile=PACK_MAX_FILE,target=PACK_TARGET,overlayDir=null,overlayName='en',overlayNoRequiredCheck=false}=options;
 const videos=options.videos===undefined?(fs.existsSync(DEFAULT_VIDEOS)?DEFAULT_VIDEOS:null):options.videos;
 const compression=compress||pack;
 if(compression&&!game)throw new Error('--compress/--pack needs --game');
 if(!['gzip','br'].includes(codec)||(!compression&&codec==='br'))throw new Error('invalid codec or --codec br without --compress/--pack');
 if(!Number.isInteger(quality)||quality<0||quality>11||!Number.isSafeInteger(maxFile)||maxFile<0||!Number.isSafeInteger(target)||target<0)throw new Error('invalid compression or pack options');
 if(overlayDir&&!/^[a-z]{2,8}$/.test(overlayName))throw new Error('--overlay-name must be 2 to 8 lowercase letters');
 let privateCache=null,cache=null;
 try{
  if(compression){cache=options.packCache?path.resolve(options.packCache):null;if(game&&cache)validateGameLayout(game,videos,cache,web,build);if(!cache){privateCache=fs.mkdtempSync(path.join(os.tmpdir(),'k2-pack-node-'));cache=privateCache;}else fs.mkdirSync(cache,{recursive:true});}
  if(game)validateGameLayout(game,videos,cache,web,build);
  const trees=new Map();
  if(game){const root=path.resolve(game),sourceFiles=gameFiles(root),files=applyResourceOverrides(sourceFiles),eligible=compression?packableSet(files,codec==='br'?['gzip','br']:['gzip']):new Set();
    trees.set('game',{name:'game',root,files,sourceFiles,eligible,meta:null,layout:pack?await layoutFor(files,eligible,{maxFile,target,codec,quality}):null,hashCache:new Map()});}
  if(overlayDir){const root=path.resolve(overlayDir),[files,meta]=overlayFiles(root),missing=overlayNoRequiredCheck?[]:overlayMissingRequired(files);
    if(missing.length)throw new Error(`overlay: required files are missing: ${missing.join(', ')}`);
    if(game&&overlaps(root,game))throw new Error('overlay and game directories must not contain each other');
    for(const other of [web,build,...(videos?[videos]:[]),...(cache?[cache]:[])])if(overlaps(root,other))throw new Error('overlay folder overlaps a static serving root');
    const eligible=compression?packableSet(files,codec==='br'?['gzip','br']:['gzip']):new Set();
    trees.set('game-'+overlayName,{name:'game-'+overlayName,root,files,eligible,meta,layout:pack?await layoutFor(files,eligible,{maxFile,target,codec,quality}):null,hashCache:new Map()});
  }
  const webHandler=await handlerFor(web),buildHandler=await handlerFor(build),videoHandler=videos?await handlerFor(videos):null,cacheHandler=cache?await handlerFor(cache):null;
  const pending=new Map();
  async function cached(name,produce){const dst=path.join(cache,name);if(fs.existsSync(dst))return dst;if(pending.has(dst))return pending.get(dst);
   const promise=(async()=>{const tmp=`${dst}.${process.pid}.${Math.random().toString(16).slice(2)}.part`;try{await produce(tmp);await fs.promises.rename(tmp,dst);return dst;}finally{await fs.promises.rm(tmp,{force:true});}})();pending.set(dst,promise);try{return await promise;}finally{pending.delete(dst);}}
  // Only bundled, hashed patches may reside outside the source tree.
  // Recheck the original path and both hashes on each access.
  function checkedTreeAsset(tree,name){const original=checkedAsset((tree.sourceFiles??tree.files).get(name),tree.root);if(!original)return null;
   const effective=tree.files.get(name);if(effective===original)return original;
   try{if(!RESOURCE_PATCHES.some(p=>p.file===effective)||patchedResourceSource(name,original)!==effective)return null;
    return checkedAsset(effective,path.dirname(effective));}catch{return null;}}
  function checkedFiles(tree,requireStamp=false){const files=new Map(),hashes=new Map();for(const [name] of tree.files){const safe=checkedTreeAsset(tree,name);if(!safe)throw new Error('inventory changed');const stamp=infoStamp(safe);
    if(requireStamp&&tree.layout.stamp.get(name)!==stamp)throw new Error('inventory changed');
    files.set(name,safe);let entry=tree.hashCache.get(name);if(!entry||entry.stamp!==stamp){entry={stamp,sha:fileSha256(safe)};tree.hashCache.set(name,entry);}hashes.set(name,entry.sha);
   }return [files,hashes];}
  async function preparePack(tree,rel){const members=tree.layout?.packs.get(rel);if(!members)return null;
   for(const m of members){const safe=checkedTreeAsset(tree,m.path);if(!safe||infoStamp(safe)!==tree.layout.stamp.get(m.path))return null;}
   const name='pack-'+tree.name+'-'+rel.replaceAll('/','-');return cached(name,async tmp=>{
    const spans=await writePack(tmp,members,PACK_LEVEL,quality),entries=members.map((m,i)=>({offset:spans[i][0],csize:spans[i][1],enc:m.enc,size:m.size,sha256:m.sha256}));
    if(!await verifyPack(tmp,entries,spans.reduce((a,b)=>a+b[1],0)))throw new Error('pack verification failed');
   });
  }
  async function prepareCompressed(tree,rel,enc){const src=checkedTreeAsset(tree,rel);if(!src||!cache)return null;
   const st=fs.statSync(src,{bigint:true}),name=`${sha1(tree.name+':'+rel)}-${st.mtimeNs}-${st.size}`+(enc==='gzip'?'.k2gz':`.k2br${quality}`);
   return cached(name,async tmp=>{const fh=await fs.promises.open(tmp,'wx');try{await codecPass(enc,src,async bytes=>{let n=0;while(n<bytes.length){const r=await fh.write(bytes,n,bytes.length-n,null);if(!r.bytesWritten)throw new Error('short cache write');n+=r.bytesWritten;}},PACK_LEVEL,quality);}finally{await fh.close();}});
  }
  function forward(handler,rel,req,res,query=''){if(!handler)return error(res,404,'Not found',req.method==='HEAD');req.url='/'+rel.split('/').map(encodeURIComponent).join('/')+query;return handler(req,res);}
  const server=http.createServer(async(req,res)=>{isolatedHeaders(res);const head=req.method==='HEAD';
   if(req.method!=='GET'&&!head)return error(res,405,'Method not allowed',head);
   if(!auth(req,password)){res.setHeader('WWW-Authenticate','Basic realm="Game", charset="UTF-8"');res.writeHead(401,{'Content-Length':'0'});return res.end();}
   let pathname;try{pathname=decodeURIComponent((req.url||'/').split('?',1)[0]);}catch{return error(res,404,'Not found',head);}
   if(!pathname.startsWith('/')||/[\\\x00-\x1f\x7f]/.test(pathname)||pathname.slice(1).split('/').some(p=>p==='.'||p==='..'))return error(res,404,'Not found',head);
   const query=req.url?.includes('?')?'?'+req.url.split('?').slice(1).join('?'):'';
   try{
    for(const [name,tree] of trees){const prefix='/'+name+'/';if(!pathname.startsWith(prefix))continue;const rel=pathname.slice(prefix.length);
     if(rel==='manifest.json'){
      try{const [files,computedHashes]=checkedFiles(tree,!!tree.layout),packed=tree.layout?.packed??(compression?new Map([...tree.eligible].map(p=>[p,{enc:codec}])):new Map()),packs=tree.layout?.meta??[],hashes=tree.layout?.hashes??computedHashes;
       const data=Buffer.from(JSON.stringify(name==='game'?manifestFor(files,packed,packs,hashes):overlayManifestFor(files,packed,packs,hashes,tree.meta)));
       res.writeHead(200,{'Content-Type':'application/json','Content-Length':data.length});return res.end(head?undefined:data);
      }catch{return error(res,409,`${name} inventory changed; restart server after inspection`,head);}
     }
     let asset=checkedTreeAsset(tree,rel);
     if(asset){const root=RESOURCE_PATCHES.some(p=>p.file===asset)?path.dirname(asset):tree.root;
      return forward(await handlerFor(root),path.relative(root,asset).split(path.sep).join('/'),req,res,query);}
     if(tree.layout?.packs.has(rel)){asset=await preparePack(tree,rel);if(asset)return forward(cacheHandler,path.basename(asset),req,res,query);}
     if(compression){for(const [enc,suffix] of Object.entries(PACK_SUFFIX))if(rel.endsWith(suffix)){
      const raw=rel.slice(0,-suffix.length),expected=tree.layout?tree.layout.packed.get(raw)?.enc:codec;
      if(tree.eligible.has(raw)&&expected===enc){asset=await prepareCompressed(tree,raw,enc);if(asset)return forward(cacheHandler,path.basename(asset),req,res,query);}
     }}
     return error(res,404,'Not found',head);
    }
    if(pathname.startsWith('/build/'))return forward(buildHandler,pathname.slice(7),req,res,query);
    if(pathname.startsWith('/videos/')){const rel=pathname.slice(8);if(rel.split('/').some(part=>!part)||!rel.toLowerCase().endsWith('.mp4'))return error(res,404,'Not found',head);const safe=videos&&checkedAsset(path.join(videos,rel),videos);if(safe&&req.headers.range?.startsWith('bytes=')&&req.headers.range.includes(','))req.headers.range=req.headers.range.split(',',1)[0];return safe?forward(videoHandler,rel,req,res,query):error(res,404,'Not found',head);}
    return forward(webHandler,pathname==='/'?'index.html':pathname.slice(1),req,res,query);
   }catch{return error(res,500,'Could not serve resource',head);}
  });
  const cleanup=()=>{if(privateCache){fs.rmSync(privateCache,{recursive:true,force:true});privateCache=null;}};
  return {server,cleanup,host,trees,cache};
 }catch(e){if(privateCache)fs.rmSync(privateCache,{recursive:true,force:true});throw e;}
}
function parseArgs(args){const o={port:8007},values={'--port':'port','--game':'game','--videos':'videos','--codec':'codec','--br-quality':'quality','--pack-max-file':'maxFile','--pack-size':'target','--pack-cache':'packCache','--overlay-dir':'overlayDir','--overlay-name':'overlayName','--host':'host','--password':'password'},flags={'--compress':'compress','--pack':'pack','--overlay-no-required-check':'overlayNoRequiredCheck'};
 for(let i=0;i<args.length;i++){const arg=args[i];if(arg==='--help'||arg==='-h'){console.log('Usage: node serve.mjs [--game DIR] [--videos DIR] [--port PORT] [--compress] [--pack] [--codec gzip|br] [--overlay-dir DIR] [--host ADDRESS] [--password PASSWORD]');return null;}if(flags[arg]){o[flags[arg]]=true;continue;}const eq=arg.indexOf('='),key=eq<0?arg:arg.slice(0,eq),value=eq<0?args[++i]:arg.slice(eq+1);if(!values[key]||value===undefined||value==='')throw new Error(`invalid option: ${arg}`);const name=values[key];o[name]=['port','quality','maxFile','target'].includes(name)?Number(value):value;}
 if(!Number.isInteger(o.port)||o.port<0||o.port>65535)throw new Error('invalid port');return o;}
async function main(){const opts=parseArgs(process.argv.slice(2));if(!opts)return;const {server,cleanup,host,trees,cache}=await createDevServer(opts);server.on('error',e=>{console.error(e.message);cleanup();process.exitCode=1;});
 process.once('exit',cleanup);
 for(const sig of ['SIGINT','SIGTERM'])process.once(sig,()=>server.close(()=>{cleanup();process.exit(0);}));
 server.listen(opts.port,host,()=>console.log(`Game: http://${host}:${server.address().port}/ (${trees.get('game')?.files.size??0} game files${cache?`, cache ${cache}`:''})`));}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href)main().catch(e=>{console.error(e.message);process.exitCode=1;});
