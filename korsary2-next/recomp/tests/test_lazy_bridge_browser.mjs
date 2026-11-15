import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { readFileSync } from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import assert from 'node:assert/strict';
// This is an isolated synthetic WasmFS + OPFS test, not the game or a user's profile.
const dir=process.argv[2];
if (!dir) throw Error('Pass the directory containing the compiled browser probe');
const here=path.dirname(fileURLToPath(import.meta.url));
const third=path.resolve(here,'../../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH=path.join(third,'browsers');
const {chromium}=createRequire(path.join(third,'package.json'))('playwright');
const html=`<!doctype html><meta charset=utf-8><script>
(async()=>{
const root=await navigator.storage.getDirectory();
const parent=await root.getDirectoryHandle('lazytest',{create:true});
const sub=await parent.getDirectoryHandle('sub',{create:true});
const {startLazyClient}=await import('/lazy-client.mjs');
const entry={path:'RESOURCE/sub/LiveFile.txt',size:7,sha256:'73c76d56fd4042001a19cd735382344bc7ecb1adf080796e9096cf26fcc6cdde'};
globalThis.Module={onRuntimeInitialized(){globalThis.client=startLazyClient({M:Module,files:[entry],onError:e=>console.error(e),install:async(f,{signal})=>{
 if(f!==entry)throw Error('bad request path');
 const response=await fetch('/pack',{headers:{Range:'bytes=4-10'},signal});if(response.status!==206)throw Error('range unsupported');
 const data=await response.arrayBuffer();const h=Array.from(new Uint8Array(await crypto.subtle.digest('SHA-256',data)),x=>x.toString(16).padStart(2,'0')).join('');
 if(h!=='73c76d56fd4042001a19cd735382344bc7ecb1adf080796e9096cf26fcc6cdde')throw Error('digest mismatch');
 const fh=await sub.getFileHandle('LiveFile.txt',{create:true});const w=await fh.createWritable();await w.write(data);await w.close();console.log('PAGE WRITE COMPLETE');
 }});}};
const script=document.createElement('script');script.src='/probe.js';document.body.appendChild(script);
})();</script>`;
const server=createServer((req,res)=>{
  const u=new URL(req.url,'http://localhost').pathname;
  res.setHeader('Cross-Origin-Opener-Policy','same-origin');res.setHeader('Cross-Origin-Embedder-Policy','require-corp');res.setHeader('Cross-Origin-Resource-Policy','same-origin');
  if(u==='/'){res.setHeader('Content-Type','text/html');res.end(html);return;}
  if(u==='/lazy-client.mjs'){res.setHeader('Content-Type','text/javascript');res.end(readFileSync(path.resolve(here,'../web/experimental/lazy-client.mjs')));return;}
  if(u==='/pack'){assert.equal(req.headers.range,'bytes=4-10');res.statusCode=206;res.setHeader('Content-Range','bytes 4-10/15');res.end('dynamic');return;}
  if(!['/probe.js','/probe.wasm','/probe.worker.js'].includes(u)){res.statusCode=404;res.end();return;}
  res.setHeader('Content-Type',u.endsWith('.wasm')?'application/wasm':'text/javascript');res.end(readFileSync(path.join(dir,u)));
});
await new Promise(ok=>server.listen(0,'127.0.0.1',ok));
const browser=await chromium.launch({headless:true});
try {
 const page=await browser.newPage();const lines=[],errors=[];
 page.on('console',m=>{lines.push(m.text());console.log(m.text());});
 page.on('pageerror',e=>{errors.push(e.message);console.log('ERROR',e.message);});
 const finished=page.waitForEvent('console',{predicate:m=>m.text().includes('PROBE after'),timeout:20000});
 await page.goto(`http://127.0.0.1:${server.address().port}/`);
 await finished;
 assert(lines.some(x=>x.includes('PROBE before stat=-1')));
 assert(lines.some(x=>x.includes('PAGE WRITE COMPLETE')));
 assert(lines.some(x=>x.includes('PROBE after stat=0')&&x.includes('bytes=dynamic')&&x.includes('listed=1')));
 assert.deepEqual(errors,[]);
 console.log('PASS: WasmFS sees a file created by page after a negative lookup');
} finally {await browser.close();await new Promise(ok=>server.close(ok));}
