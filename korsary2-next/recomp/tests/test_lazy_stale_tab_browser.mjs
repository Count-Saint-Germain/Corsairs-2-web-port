// Two actual launcher tabs share an isolated Chromium OPFS origin. A prepares
// the old manifest, B installs a different identity, then A must not run or
// repair anything with its obsolete manifest. No user profile is opened.
import assert from 'node:assert/strict';
import http from 'node:http';
import {readFile} from 'node:fs/promises';
import {createRequire} from 'node:module';
import {dirname,join,resolve} from 'node:path';
import {fileURLToPath} from 'node:url';
import {createStaticHandler} from '../../../scripts/serve_distribution.mjs';
const site=process.env.K2_LAZY_SITE;
if(!site)throw Error('Set K2_LAZY_SITE to a disposable prepared streaming site.');
const oldManifest=JSON.parse(await readFile(join(site,'game/manifest.json'),'utf8'));
const newManifest={...oldManifest,version:oldManifest.version+'-stale-tab-test'};
const chosen=oldManifest.files.find(f=>f.path.startsWith('PROGRAM/')&&f.size>0);
assert.ok(chosen,'test needs an initial PROGRAM resource');
const here=dirname(fileURLToPath(import.meta.url)), playwrightDir=resolve(here,'../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir,'browsers');
const {chromium}=createRequire(join(playwrightDir,'package.json'))('playwright');
const serve=await createStaticHandler(site,{requireIndex:true});let update=false;
const server=http.createServer((req,res)=>{
  if((req.url||'').split('?')[0]==='/game/manifest.json'){
    const body=JSON.stringify(update?newManifest:oldManifest);
    res.writeHead(200,{'Content-Type':'application/json','Cross-Origin-Opener-Policy':'same-origin','Cross-Origin-Embedder-Policy':'require-corp','Cache-Control':'no-store'});res.end(body);return;
  }
  serve(req,res).catch(error=>{if(!res.headersSent)res.writeHead(500);res.end(String(error));});
});
let browser;
try{
  await new Promise((ok,fail)=>{server.once('error',fail);server.listen(0,'127.0.0.1',ok);});
  browser=await chromium.launch({headless:true,channel:'chromium',args:['--enable-unsafe-webgpu']});
  const context=await browser.newContext({viewport:{width:1280,height:720}}), a=await context.newPage();
  const base=`http://127.0.0.1:${server.address().port}/?lazy=1&mute`;
  await a.goto(base,{waitUntil:'domcontentloaded'});
  await a.locator('#play').waitFor({state:'visible',timeout:120000});
  await a.evaluate(async()=>{
    const root=await navigator.storage.getDirectory(), game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const save=await game.getDirectoryHandle('SAVE',{create:true}), fh=await save.getFileHandle('stale-test.sav',{create:true}), w=await fh.createWritable();
    await w.write('KEEP TEST SAVE');await w.close();
  });
  update=true;
  const b=await context.newPage();await b.goto(base,{waitUntil:'domcontentloaded'});
  await b.locator('#play').waitFor({state:'visible',timeout:120000});
  // Damage one cached immutable asset only after B installed the newer
  // version. A's stale repair must not rewrite it, even though a normal
  // verifyLazyCache would detect it as damaged.
  const evidence=await b.evaluate(async path=>{
    const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const parts=path.split('/'), name=parts.pop();let dir=game;
    for(const p of parts)dir=await dir.getDirectoryHandle(p);
    const fh=await dir.getFileHandle(name),w=await fh.createWritable();await w.write('DO NOT REPAIR');await w.close();
    const marker=JSON.parse(await(await(await game.getFileHandle('experimental-lazy.json')).getFile()).text());
    const identity=JSON.parse(await(await(await game.getFileHandle('experimental-version.json')).getFile()).text());
    return {marker,identity};
  },chosen.path);
  assert.match(evidence.marker.version,/-stale-tab-test/);
  assert.equal(evidence.marker.version,evidence.identity.version);
  let runtimeRequests=0;
  a.on('request',req=>{if(new URL(req.url()).pathname==='/build/game.js')runtimeRequests++;});
  await a.locator('#play').click();
  await a.waitForFunction(()=>/changed in another tab|изменилась в другой вкладке/i.test(document.querySelector('#status')?.textContent||''),null,{timeout:30000});
  assert.equal(runtimeRequests,0,'stale tab must refuse before requesting runtime');
  const after=await b.evaluate(async path=>{
    const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const parts=path.split('/'),name=parts.pop();let dir=game;for(const p of parts)dir=await dir.getDirectoryHandle(p);
    const resource=await(await(await dir.getFileHandle(name)).getFile()).text();
    const save=await game.getDirectoryHandle('SAVE');
    return {resource,save:await(await(await save.getFileHandle('stale-test.sav')).getFile()).text(),
      marker:JSON.parse(await(await(await game.getFileHandle('experimental-lazy.json')).getFile()).text()),
      identity:JSON.parse(await(await(await game.getFileHandle('experimental-version.json')).getFile()).text())};
  },chosen.path);
  assert.equal(after.resource,'DO NOT REPAIR');assert.equal(after.save,'KEEP TEST SAVE');
  assert.deepEqual(after.marker,evidence.marker);assert.deepEqual(after.identity,evidence.identity);
  console.log('Stale launcher tab refused before runtime or repair; new identity and test SAVE preserved: PASS');
}finally{await browser?.close();await new Promise(ok=>server.close(ok));}
