// The actual launcher must offer read-only export when an old experimental
// identity cannot be upgraded safely. Synthetic SAVE, isolated OPFS origin.
import assert from 'node:assert/strict';
import http from 'node:http';
import {createRequire} from 'node:module';
import {dirname,join,resolve} from 'node:path';
import {fileURLToPath} from 'node:url';
import {createStaticHandler} from '../../../scripts/serve_distribution.mjs';
const site=process.env.K2_LAZY_SITE;
if(!site)throw Error('Set K2_LAZY_SITE to a prepared disposable streaming site.');
const here=dirname(fileURLToPath(import.meta.url)),pw=resolve(here,'../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(pw,'browsers');
const {chromium}=createRequire(join(pw,'package.json'))('playwright');
const serve=await createStaticHandler(site,{requireIndex:true});
let offlineManifest=false;
const server=http.createServer((req,res)=>{
  if(offlineManifest && (req.url||'').split('?')[0]==='/game/manifest.json'){
    res.writeHead(503,{'Cross-Origin-Opener-Policy':'same-origin','Cross-Origin-Embedder-Policy':'require-corp'});res.end();return;
  }
  serve(req,res).catch(e=>{if(!res.headersSent)res.writeHead(500);res.end(String(e));});
});
let browser;
try{
  await new Promise((ok,fail)=>{server.once('error',fail);server.listen(0,'127.0.0.1',ok);});
  browser=await chromium.launch({headless:true,channel:'chromium',args:['--enable-unsafe-webgpu']});
  const context=await browser.newContext({viewport:{width:1280,height:720},acceptDownloads:true}),page=await context.newPage();
  await page.goto(`http://127.0.0.1:${server.address().port}/?lazy=1&mute`,{waitUntil:'domcontentloaded'});
  await page.locator('#play').waitFor({state:'visible',timeout:120000});
  await page.evaluate(async()=>{
    const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const write=async(dir,name,data)=>{const h=await dir.getFileHandle(name,{create:true}),w=await h.createWritable();await w.write(data);await w.close();};
    const save=await game.getDirectoryHandle('SAVE',{create:true});
    await write(save,'legacy-test.sav','KEEP LEGACY SAVE');
    await write(game,'experimental-version.json',JSON.stringify({version:'legacy-v1'}));
    await write(game,'experimental-lazy.json',JSON.stringify({version:'legacy-v1'}));
  });
  await page.reload({waitUntil:'domcontentloaded'});
  await page.locator('#view-home:not(.hidden)').waitFor({state:'visible',timeout:120000});
  assert.match(await page.locator('#home-tagline').innerText(),/no resource inventory/i);
  for(const id of ['play','go-online','restore-saves','copy-classic-saves','restore-file','folder'])assert.equal(await page.locator('#'+id).isDisabled(),true,id);
  assert.equal(await page.locator('#backup-saves').isDisabled(),false);
  const snapshot=()=>page.evaluate(async()=>{
    const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const read=async(dir,name)=>await(await(await dir.getFileHandle(name)).getFile()).text();
    return {identity:await read(game,'experimental-version.json'),marker:await read(game,'experimental-lazy.json'),
      settings:await read(game,'engine.ini'),save:await read(await game.getDirectoryHandle('SAVE'),'legacy-test.sav')};
  });
  const before=await snapshot();
  await page.locator('#backup-saves').click();
  await page.locator('#backup-download:not(.hidden)').waitFor({state:'visible',timeout:30000});
  const entries=await page.evaluate(async()=>{
    const {decodeBackup}=await import('/save-export.mjs');
    const bytes=new Uint8Array(await(await fetch(document.querySelector('#backup-download').href)).arrayBuffer());
    return decodeBackup(bytes).entries.map(e=>({name:e.name,data:new TextDecoder().decode(e.bytes)}));
  });
  assert.deepEqual(entries,[{name:'legacy-test.sav',data:'KEEP LEGACY SAVE'}]);
  assert.deepEqual(await snapshot(),before);
  for(const id of ['play','go-online','restore-saves','copy-classic-saves','restore-file','folder'])assert.equal(await page.locator('#'+id).isDisabled(),true,id);
  // The launcher and modules remain available, but the manifest endpoint is
  // down. Export must still work without attempting installation or writes.
  offlineManifest=true;
  await page.reload({waitUntil:'domcontentloaded'});
  await page.locator('#view-home:not(.hidden)').waitFor({state:'visible',timeout:30000});
  assert.match(await page.locator('#home-tagline').innerText(),/манифест игры недоступен|game manifest is unavailable/i);
  await page.locator('#backup-saves').click();
  await page.locator('#backup-download:not(.hidden)').waitFor({state:'visible',timeout:30000});
  const offlineEntries=await page.evaluate(async()=>{
    const {decodeBackup}=await import('/save-export.mjs');
    const bytes=new Uint8Array(await(await fetch(document.querySelector('#backup-download').href)).arrayBuffer());
    return decodeBackup(bytes).entries.map(e=>({name:e.name,data:new TextDecoder().decode(e.bytes)}));
  });
  assert.deepEqual(offlineEntries,entries);assert.deepEqual(await snapshot(),before);
  for(const id of ['play','go-online','restore-saves','copy-classic-saves','restore-file','folder'])assert.equal(await page.locator('#'+id).isDisabled(),true,id);
  console.log('Legacy update refusal and unavailable manifest offer ZIP export without changing SAVE/config/identity: PASS');
}finally{await browser?.close();await new Promise(ok=>server.close(ok));}
