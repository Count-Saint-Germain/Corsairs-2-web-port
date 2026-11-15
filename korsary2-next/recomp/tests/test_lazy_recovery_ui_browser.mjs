// Exercise the real launcher recovery UI and lazy client in an ephemeral browser.
// Synthetic requests and an isolated OPFS SAVE are the only game data used.
import assert from 'node:assert/strict';
import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { readFileSync } from 'node:fs';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const here = dirname(fileURLToPath(import.meta.url)), web = resolve(here, '../web');
const third = resolve(here, '../../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(third, 'browsers');
const { chromium } = createRequire(join(third, 'package.json'))('playwright');
const index = readFileSync(join(web, 'index.html'), 'utf8');
const source = readFileSync(join(web, 'port.js'), 'utf8');
const elementStart = index.indexOf('    <div id="lazy-recovery"');
const elementEnd = index.indexOf('    <button id="aspect"', elementStart);
const codeStart = source.indexOf("        const lazyStatus = $('netstatus');");
const codeEnd = source.indexOf('        window.lazyStats = lazyClient.stats;', codeStart);
assert.ok(elementStart >= 0 && elementEnd > elementStart && codeStart >= 0 && codeEnd > codeStart);
const markup = index.slice(elementStart, elementEnd);
const code = source.slice(codeStart, codeEnd).replace('startLazyClient({ M, files:', 'startLazyClient({ retryDelaysMs:[], intervalMs:1, M, files:');
assert.ok(code.includes('retryDelaysMs:[]'), 'test must keep retry timing bounded');
const html = `<!doctype html><style>.hidden{display:none}</style><button id="enter-fullscreen">Fullscreen</button><div id="stage">
<div id="netstatus" class="hidden"></div>${markup}</div><script type="module">
import { startLazyClient } from '/lazy-client.mjs';
const $ = id => document.getElementById(id);
const file = {path:'RESOURCE/a', size:1, sha256:'a'.repeat(64)};
const lazyPlan = {files:[file]}, memory = new WebAssembly.Memory({initial:1,maximum:1,shared:true});
let pending=null, current=0;
window.completions=[]; window.gameKeys=[];
window.addEventListener('keydown', e => gameKeys.push(e.code));
window.request=(token)=>{pending=token;}; window.expire=()=>{current=0;};
const M={wasmMemory:memory,_malloc:()=>16,_free:()=>{},
  _port_lazy_poll(ptr){if(!pending)return 0; current=pending;pending=0;
    new Uint8Array(memory.buffer,ptr).set(new TextEncoder().encode(file.path+'\\0'));return current;},
  _port_lazy_current(token){return token===current;},
  _port_lazy_finish(token,status){if(token!==current)return 0;completions.push([token,status]);current=0;return 1;}};
window.allow=false; window.errorMode='network';
document.querySelector('#enter-fullscreen').onclick=()=>document.querySelector('#stage').requestFullscreen();
const install=async()=>{
  if(errorMode==='integrity')throw Object.assign(new Error('SHA mismatch'),{name:'TransferIntegrityError'});
  if(errorMode==='quota')throw Object.assign(new Error('Storage full'),{name:'QuotaExceededError'});
  const r=await fetch('/asset?ok='+allow);if(!r.ok)throw new Error('HTTP '+r.status);
};
const root=await navigator.storage.getDirectory(), dir=await root.getDirectoryHandle('recovery-test',{create:true});
const save=await dir.getFileHandle('SAVE-slot',{create:true}), writer=await save.createWritable();
await writer.write('KEEP TEST SAVE');await writer.close();window.readSave=async()=> (await save.getFile()).text();
${code}
window.client=lazyClient; window.ready=true;
</script>`;
const server = createServer((req,res) => {
  const u = new URL(req.url, 'http://localhost');
  res.setHeader('Cross-Origin-Opener-Policy','same-origin');
  res.setHeader('Cross-Origin-Embedder-Policy','require-corp');
  if (u.pathname === '/') { res.setHeader('Content-Type','text/html; charset=utf-8');res.end(html); }
  else if (u.pathname === '/lazy-client.mjs') { res.setHeader('Content-Type','text/javascript');res.end(readFileSync(join(web,'experimental/lazy-client.mjs'))); }
  else if (u.pathname === '/asset') { res.statusCode = u.searchParams.get('ok') === 'true' ? 200 : 503;res.end('x'); }
  else {res.statusCode=404;res.end();}
});
await new Promise((ok,fail)=>{server.once('error',fail);server.listen(0,'127.0.0.1',ok);});
let browser;
try {
  browser=await chromium.launch({headless:true});
  const page=await browser.newPage(), errors=[];
  page.on('pageerror',e=>errors.push(e.message));
  await page.goto(`http://127.0.0.1:${server.address().port}/`);
  await page.waitForFunction(()=>window.ready);
  await page.locator('#enter-fullscreen').click();
  await page.waitForFunction(()=>document.fullscreenElement?.id==='stage');
  await page.evaluate(()=>request(1));
  await page.locator('#lazy-retry').waitFor({state:'visible'});
  assert.equal(await page.locator('#lazy-recovery').evaluate(e=>document.fullscreenElement.contains(e)),true);
  assert.match(await page.locator('#lazy-recovery-message').textContent(),/двух минут/i);
  assert.equal(await page.locator('#lazy-retry').evaluate(e=>document.activeElement===e),true);
  await page.evaluate(()=>{allow=true;});
  await page.keyboard.press('Enter');
  await page.waitForFunction(()=>completions.length===1);
  assert.deepEqual(await page.evaluate(()=>completions),[[1,1]]);
  assert.deepEqual(await page.evaluate(()=>gameKeys),[],'dialog key must not reach the game');
  assert.equal(await page.locator('#lazy-recovery').isVisible(),false);
  await page.evaluate(()=>{allow=false;request(2);});
  await page.locator('#lazy-cancel').waitFor({state:'visible'});
  await page.locator('#lazy-cancel').click();
  await page.locator('#lazy-reload').waitFor({state:'visible'});
  assert.deepEqual(await page.evaluate(()=>completions),[[1,1],[2,0]]);
  assert.match(await page.locator('#lazy-recovery-message').textContent(),/несохранённый прогресс/i);
  // A token expiry replaces a still-open prompt with the reload action.
  await page.evaluate(()=>{document.querySelector('#lazy-recovery').classList.add('hidden');request(3);});
  await page.locator('#lazy-retry').waitFor({state:'visible'});
  await page.evaluate(()=>expire());
  await page.locator('#lazy-reload').waitFor({state:'visible'});
  assert.deepEqual(await page.evaluate(()=>completions),[[1,1],[2,0]]);
  for (const [token, mode] of [[4,'integrity'],[5,'quota']]) {
    await page.evaluate(({token,mode})=>{document.querySelector('#lazy-recovery').classList.add('hidden');errorMode=mode;request(token);},{token,mode});
    await page.locator('#lazy-reload').waitFor({state:'visible'});
    assert.equal(await page.locator('#lazy-retry').isVisible(),false,`${mode} must not offer retry`);
    await page.waitForFunction(token=>completions.some(([t])=>t===token),token);
  }
  assert.equal(await page.evaluate(()=>readSave()),'KEEP TEST SAVE');
  assert.deepEqual(errors,[]);
  console.log('PASS: recovery dialog retry, cancellation, expiry and saved data');
} finally { await browser?.close();server.closeAllConnections?.();await new Promise(ok=>server.close(ok)); }
