import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { readFileSync } from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import assert from 'node:assert/strict';

// Real OPFS and actual pack/SHA code in a new ephemeral browser profile. This
// creates its own synthetic SAVE/slot; it cannot access a player's origin.
const here = path.dirname(fileURLToPath(import.meta.url));
const web = path.resolve(here, '../web');
const third = path.resolve(here, '../../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH = path.join(third, 'browsers');
const { chromium } = createRequire(path.join(third, 'package.json'))('playwright');
const html = `<!doctype html><meta charset=utf-8><script type="module">
import {planLazyBootstrap,verifyLazyCache,reconcileLazyIdentity} from '/experimental/lazy-bootstrap.mjs';
import {startLazyClient} from '/experimental/lazy-client.mjs';
import {createSafeWriteTarget,downloadPackRun} from '/game-transfer.mjs';
const sha='ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad';
const entry=path=>({path,size:3,sha256:sha});
const files=['ENGINE.exe','engine.ini','options','MODULES/a.dll','PROGRAM/init.c'].map(entry);
const asset={...entry('RESOURCE/MODELS/ship.gm'),pack:0,offset:0,csize:3};
files.push(asset);
const packs=[{path:'pack.bin',size:3}], plan=planLazyBootstrap({version:'1',files,packs});
const root=await navigator.storage.getDirectory(), dir=await root.getDirectoryHandle('isolated-test',{create:true});
async function fileHandle(rel,create=false){let d=dir;const p=rel.split('/');for(const part of p.slice(0,-1))d=await d.getDirectoryHandle(part,{create});return d.getFileHandle(p.at(-1),{create});}
async function removeFile(rel){let d=dir;const p=rel.split('/');for(const part of p.slice(0,-1))d=await d.getDirectoryHandle(part);return d.removeEntry(p.at(-1));}
async function write(rel,data){const h=await fileHandle(rel,true), w=await h.createWritable();await w.write(data);await w.close();}
async function read(rel){return (await (await fileHandle(rel)).getFile()).text();}
for(const f of ['ENGINE.exe','MODULES/a.dll','PROGRAM/init.c'])await write(f,'abc');
await write(asset.path,'');await write('SAVE/slot','KEEP USER DATA');await write('RESOURCE/MODELS/unknown','KEEP UNKNOWN');
let mode='unavailable',calls=0;
async function repair(e){
  calls++;
  const target=createSafeWriteTarget({getFile:create=>fileHandle(e.path,create),removeFile:()=>removeFile(e.path)});
  await downloadPackRun({pack:packs[0],entries:[e],url:'/pack?mode='+mode,fetchImpl:fetch,
    openWritable:()=>target.openWritable(),discard:()=>target.discard()});
  return fileHandle(e.path);
}
async function mustFail(pattern){try{await verifyLazyCache(dir,plan,undefined,{repair});throw Error('unexpected success');}catch(e){if(!pattern.test(e.message))throw e;}}
await mustFail(/HTTP 503/);
if(await read(asset.path)!=='' || await read('SAVE/slot')!=='KEEP USER DATA')throw Error('server failure changed data');
mode='corrupt';await mustFail(/SHA-256/);
if(await read(asset.path)!=='' || await read('SAVE/slot')!=='KEEP USER DATA')throw Error('integrity failure changed data');
mode='good';const result=await verifyLazyCache(dir,plan,undefined,{repair});
if(result.repaired!==1 || await read(asset.path)!=='abc' || await read('SAVE/slot')!=='KEEP USER DATA' ||
   await read('RESOURCE/MODELS/unknown')!=='KEEP UNKNOWN')throw Error('repair or data preservation failed');
const second=await verifyLazyCache(dir,plan,undefined,{repair});
if(second.repaired!==0 || calls!==3)throw Error('repeat should use cached data');
// Exercise an interrupted manifest update against real case-sensitive OPFS.
// Only the separate synthetic origin and its own SAVE are accessed.
const oldPlan=planLazyBootstrap({version:'old',files,packs});
const newSha='cb8379ac2098aa165029e3938a51da0bcecfc008fd6795f401178647f96c5b34'; // SHA-256 of def
const updatedFiles=files.filter(f=>f.path!==asset.path).map(f=>f.path==='MODULES/a.dll'?{...f,sha256:newSha}:f);
const newPlan=planLazyBootstrap({version:'new',files:updatedFiles,packs:[]});
const updateDir=await root.getDirectoryHandle('update-test',{create:true});
async function updateFile(rel,create=false){let d=updateDir;const p=rel.split('/');for(const part of p.slice(0,-1))d=await d.getDirectoryHandle(part,{create});return d.getFileHandle(p.at(-1),{create});}
async function updateWrite(rel,data){const h=await updateFile(rel,true),w=await h.createWritable();await w.write(data);await w.close();}
async function updateRead(rel){return (await (await updateFile(rel)).getFile()).text();}
let failUpdate=true;
async function updateRepair(e){if(failUpdate)throw Error('update disconnected');await updateWrite(e.path,'def');return updateFile(e.path);}
await reconcileLazyIdentity(root,'update-test',oldPlan,{repair:updateRepair});
for(const f of ['ENGINE.exe','MODULES/a.dll','PROGRAM/init.c',asset.path])await updateWrite(f,'abc');
await updateWrite('SAVE/slot','PRESERVE');
try{await reconcileLazyIdentity(root,'update-test',newPlan,{repair:updateRepair});throw Error('unexpected update success');}catch(e){if(!/update disconnected/.test(e.message))throw e;}
if(await updateRead('MODULES/a.dll')!=='abc' || await updateRead('SAVE/slot')!=='PRESERVE')throw Error('interrupted update changed data');
failUpdate=false;await reconcileLazyIdentity(root,'update-test',newPlan,{repair:updateRepair});
if(await updateRead('MODULES/a.dll')!=='def' || await updateRead('SAVE/slot')!=='PRESERVE')throw Error('resumed update failed');
try{await updateFile(asset.path);throw Error('obsolete asset remains');}catch(e){if(e.name!=='NotFoundError')throw e;}
// A real network disconnect is retried; a bad hash or quota error is not.
// The fake guest exposes the same shared-memory request protocol as the real
// game, while the page uses its real network, SHA and OPFS transfer functions.
const memory=new WebAssembly.Memory({initial:1,maximum:1,shared:true});
let pending=null,current=0,finished=[],attempts={},retryEvents=[],started=[],prompt,expired=0;
const M={wasmMemory:memory,_malloc:()=>16,_free:()=>{},
  _port_lazy_poll(ptr){if(!pending)return 0;const p=pending;pending=null;current=p.token;
    new Uint8Array(memory.buffer,ptr).set(new TextEncoder().encode(p.path+'\\0'));return p.token;},
  _port_lazy_current:token=>token===current,
  _port_lazy_finish(token,success){if(token===current){finished.push([token,success]);current=0;return 1;}return 0;}};
const retryFile={...entry('RESOURCE/MODELS/retry.gm'),pack:0,offset:0,csize:3};
const badFile={...entry('RESOURCE/MODELS/badhash.gm'),pack:0,offset:0,csize:3};
const quotaFile={...entry('RESOURCE/MODELS/quota.gm'),pack:0,offset:0,csize:3};
const stallFile={...entry('RESOURCE/MODELS/stall.gm'),pack:0,offset:0,csize:3};
const resumeFile={...entry('RESOURCE/MODELS/resume.gm'),pack:0,offset:0,csize:3};
const expirePromptFile={...entry('RESOURCE/MODELS/expireprompt.gm'),pack:0,offset:0,csize:3};
const waitFor=async(fn)=>{const until=Date.now()+5000;while(!fn()){if(Date.now()>until)throw Error('timeout');await new Promise(r=>setTimeout(r,10));}};
const client=startLazyClient({M,files:[retryFile,badFile,quotaFile,stallFile,resumeFile,expirePromptFile],intervalMs:1,retryDelaysMs:[10,10],
  onStart:({entry:e})=>started.push(e.path),onRetry:r=>retryEvents.push(r.entry.path),onError:()=>{},
  onExhausted:p=>prompt=p,onExpired:()=>expired++,
  install:async(e,{signal})=>{
    attempts[e.path]=(attempts[e.path]||0)+1;
    if(e===quotaFile)throw new DOMException('Synthetic quota exhaustion','QuotaExceededError');
    const t=createSafeWriteTarget({getFile:create=>fileHandle(e.path,create),removeFile:()=>removeFile(e.path)});
    const kind=e===retryFile?'disconnect':e===badFile?'corrupt':e===resumeFile?'resume':e===expirePromptFile?'unavailable':'stall';
    await downloadPackRun({pack:packs[0],entries:[e],url:'/pack?mode='+kind,fetchImpl:fetch,signal,
      openWritable:()=>t.openWritable(),discard:()=>t.discard()});
  }});
pending={token:11,path:retryFile.path};await waitFor(()=>finished.length===1);
if(finished[0][1]!==1 || attempts[retryFile.path]!==2 || retryEvents.length!==1 || await read(retryFile.path)!=='abc')throw Error('disconnect retry failed');
pending={token:12,path:badFile.path};await waitFor(()=>finished.length===2);
if(finished[1][1]!==0 || attempts[badFile.path]!==1 || retryEvents.length!==1)throw Error('bad SHA was retried');
pending={token:13,path:quotaFile.path};await waitFor(()=>finished.length===3);
if(finished[2][1]!==0 || attempts[quotaFile.path]!==1 || retryEvents.length!==1)throw Error('quota was retried');
pending={token:14,path:stallFile.path};await waitFor(()=>attempts[stallFile.path]===1);
// Expire after the server has begun a partial response and OPFS staging starts.
await new Promise(r=>setTimeout(r,100));current=0;
await new Promise(r=>setTimeout(r,150));
if(finished.length!==3 || attempts[stallFile.path]!==1 || retryEvents.length!==1)throw Error('stale request completed or retried');
try {await fileHandle(stallFile.path);throw Error('aborted placeholder remains');}catch(e){if(e.name!=='NotFoundError')throw e;}
pending={token:15,path:resumeFile.path};await waitFor(()=>prompt);
if(attempts[resumeFile.path]!==3 || finished.length!==3 || await read('SAVE/slot')!=='KEEP USER DATA')throw Error('exhaustion did not remain pending safely');
const oldPrompt=prompt;prompt=null;if(!oldPrompt.retry() || oldPrompt.retry())throw Error('retry choice is not one-shot');
await waitFor(()=>finished.length===4);
if(finished[3][0]!==15 || finished[3][1]!==1 || attempts[resumeFile.path]!==4 || await read(resumeFile.path)!=='abc')throw Error('manual retry did not resume');
pending={token:16,path:expirePromptFile.path};await waitFor(()=>prompt);
const expiredBefore=expired;current=0;await waitFor(()=>expired>expiredBefore);
if(prompt.retry() || finished.length!==4 || attempts[expirePromptFile.path]!==3)throw Error('expired prompt accepted a stale retry');
if(started.length!==6 || await read('SAVE/slot')!=='KEEP USER DATA')throw Error('retry changed saved data');
client.stop();
console.log('PASS: actual OPFS recovery, disconnect retry, SHA/quota refusal and expired abort preserve saves');
</script>`;
const allowed = new Set(['/experimental/lazy-bootstrap.mjs','/experimental/lazy-client.mjs','/save-protection.mjs','/save-export.mjs','/game-transfer.mjs']);
let disconnects=0,resumeAttempts=0;
const server = createServer((req,res) => {
  const u=new URL(req.url,'http://127.0.0.1');
  res.setHeader('Cross-Origin-Opener-Policy','same-origin');
  res.setHeader('Cross-Origin-Embedder-Policy','require-corp');
  res.setHeader('Cross-Origin-Resource-Policy','same-origin');
  if(u.pathname==='/'){res.setHeader('Content-Type','text/html');res.end(html);return;}
  if(u.pathname==='/pack'){
    if(u.searchParams.get('mode')==='unavailable'){res.statusCode=503;res.end('unavailable');return;}
    if(u.searchParams.get('mode')==='resume' && resumeAttempts++<3){res.statusCode=503;res.end('unavailable');return;}
    if(u.searchParams.get('mode')==='disconnect' && disconnects++===0){res.writeHead(200,{'Content-Length':'3'});res.write('a');setTimeout(()=>res.destroy(),20);return;}
    if(u.searchParams.get('mode')==='stall'){res.writeHead(200,{'Content-Length':'3'});res.write('a');return;}
    res.end(u.searchParams.get('mode')==='corrupt'?'xyz':'abc');return;
  }
  if(allowed.has(u.pathname)){res.setHeader('Content-Type','text/javascript');res.end(readFileSync(path.join(web,u.pathname)));return;}
  res.statusCode=404;res.end();
});
await new Promise((resolve,reject)=>{server.once('error',reject);server.listen(0,'127.0.0.1',resolve);});
let browser;
try {
  browser=await chromium.launch({headless:true});
  const page=await browser.newPage(), errors=[];
  page.on('pageerror',e=>{errors.push(e.message);console.error('Browser error:',e.message);});
  const done=page.waitForEvent('console',{predicate:m=>m.text().startsWith('PASS:'),timeout:15000});
  await page.goto(`http://127.0.0.1:${server.address().port}/`);await done;
  assert.deepEqual(errors,[]);console.log('PASS: OPFS repair and interrupted downloads preserve saved data');
} finally {await browser?.close();server.closeAllConnections?.();await new Promise(resolve=>server.close(resolve));}
