// Optional English-overlay + lazy integration smoke test. K2_LAZY_SITE points
// to a prepared disposable site. The default browser context is ephemeral.
// To create and reload a real save, set K2_ENGLISH_SAVE_TEST=1 and give
// K2_ENGLISH_PROFILE a dedicated profile path which will be retained.
import assert from 'node:assert/strict';
import http from 'node:http';
import { access } from 'node:fs/promises';
import { createRequire } from 'node:module';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { createStaticHandler } from '../../../scripts/serve_distribution.mjs';

const site = process.env.K2_LAZY_SITE;
if (!site) throw new Error('Set K2_LAZY_SITE to the prepared streaming site.');
for (const name of ['index.html','build/game.js','build/game.wasm','experimental/lazy-client.mjs','game/manifest.json','game-en/manifest.json']) await access(join(site,name));
const here=dirname(fileURLToPath(import.meta.url)), playwrightDir=resolve(here,'../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir,'browsers');
const {chromium}=createRequire(join(playwrightDir,'package.json'))('playwright');
const serve=await createStaticHandler(site,{requireIndex:true});
const server=http.createServer((req,res)=>serve(req,res).catch(error=>{if(!res.headersSent)res.writeHead(500);res.end(String(error));}));
let browser, context;
try {
  await new Promise((ok,fail)=>{server.once('error',fail);server.listen(0,'127.0.0.1',ok);});
  if (process.env.K2_ENGLISH_PROFILE) {
    context=await chromium.launchPersistentContext(process.env.K2_ENGLISH_PROFILE,{headless:true,channel:'chromium',args:['--enable-unsafe-webgpu'],viewport:{width:1280,height:720}});
  } else {
    browser=await chromium.launch({headless:true,channel:'chromium',args:['--enable-unsafe-webgpu']});
    context=await browser.newContext({viewport:{width:1280,height:720}});
  }
  const page=context.pages()[0]||await context.newPage(), errors=[], log=[], resources=new Set();
  page.on('pageerror',e=>errors.push(e.message));
  page.on('console',m=>{const s=m.text();if(s.startsWith('[lang]')||s.startsWith('[lazy-result]')||s.includes('[overlay]')||(s.includes('[file]')&&s.includes('SAVE')))log.push(s);if(s.startsWith('[lazy-result] '))try{resources.add(JSON.parse(s.slice('[lazy-result] '.length)).path);}catch{}});
  const waitFrame=async predicate=>{
    const deadline=Date.now()+90000;let result;
    do {
      const image=(await page.screenshot()).toString('base64');
      result=await page.evaluate(async encoded=>{
        const bitmap=await createImageBitmap(await(await fetch('data:image/png;base64,'+encoded)).blob());
        const c=document.createElement('canvas');c.width=56;c.height=20;const x=c.getContext('2d',{willReadFrequently:true});x.drawImage(bitmap,0,0,c.width,c.height);bitmap.close();
        const d=x.getImageData(0,0,c.width,c.height).data;let blue=0,brown=0;
        for(let i=0;i<d.length;i+=4){const [r,g,b]=[d[i],d[i+1],d[i+2]];if(b>12&&b>r*1.12&&b>g*1.08)blue++;if(r>12&&r>g*1.12&&g>b*1.08)brown++;}
        return {blue:blue/(d.length/4),brown:brown/(d.length/4)};
      },image);
      if(predicate(result))return;
      await page.waitForTimeout(500);
    }while(Date.now()<deadline);
    throw Error('Timed out waiting for game frame '+JSON.stringify(result));
  };
  await page.goto(`http://127.0.0.1:${server.address().port}/?lazy=1&lang=en&log&mute`,{waitUntil:'domcontentloaded'});
  await page.waitForFunction(()=>window.langInfo?.lang==='en'&&window.langInfo?.overlay==='ready'&&!document.querySelector('#play').disabled,null,{timeout:180000});
  assert.equal(await page.evaluate(()=>window.langInfo.installed),'installed');
  await page.locator('#play').click();
  await page.waitForFunction(()=>window.lazyStats?.installed>=25,null,{timeout:120000});
  await waitFrame(c=>c.blue>.35&&c.brown<.3);
  await page.keyboard.press('Enter');
  const cabinDeadline=Date.now()+90000;
  while(!resources.has('RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck.gm')&&Date.now()<cabinDeadline)await page.waitForTimeout(500);
  assert.ok(resources.has('RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck.gm'),'new game must request the cabin geometry');
  await page.waitForTimeout(12000);
  await waitFrame(c=>c.brown>.5);
  if (process.env.K2_ENGLISH_CAPTURE) await page.screenshot({path:process.env.K2_ENGLISH_CAPTURE});
  const saveTest = process.env.K2_ENGLISH_SAVE_TEST === '1';
  if (saveTest || process.env.K2_ENGLISH_MENU_CAPTURE) {
    for(let i=0;i<12;i++){await page.keyboard.press('Space');await page.waitForTimeout(500);}
    await page.keyboard.press('Escape');await page.waitForTimeout(3000);
    if(process.env.K2_ENGLISH_MENU_CAPTURE)await page.screenshot({path:process.env.K2_ENGLISH_MENU_CAPTURE});
    if (saveTest || process.env.K2_ENGLISH_SAVE_CAPTURE) {
      for(let i=0;i<2;i++){await page.keyboard.press('ArrowDown');await page.waitForTimeout(400);}
      await page.keyboard.press('Enter');await page.waitForTimeout(2000);
      if(process.env.K2_ENGLISH_SAVE_CAPTURE)await page.screenshot({path:process.env.K2_ENGLISH_SAVE_CAPTURE});
      if (saveTest || process.env.K2_ENGLISH_DO_SAVE) {
        if (!process.env.K2_ENGLISH_PROFILE) throw Error('A retained K2_ENGLISH_PROFILE is required for the save test');
        await page.keyboard.press('Enter');await page.waitForTimeout(600);
        await page.keyboard.press('Enter');await page.waitForTimeout(3500);
        const files=await page.evaluate(async()=>{
          const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
          try{const save=await game.getDirectoryHandle('SAVE');const names=[];for await(const [name,h] of save.entries())if(h.kind==='file')names.push(name);return names;}
          catch(e){if(e.name==='NotFoundError')return [];throw e;}
        });
        assert.ok(files.length>0,'a new game save must be present in the retained profile');
        console.log('English test save files:',JSON.stringify(files));
        if(process.env.K2_ENGLISH_DO_SAVE)await page.screenshot({path:process.env.K2_ENGLISH_DO_SAVE});
        if (saveTest || process.env.K2_ENGLISH_LOAD_CAPTURE) {
          await page.reload({waitUntil:'domcontentloaded'});
          await page.waitForFunction(()=>window.langInfo?.overlay==='ready'&&!document.querySelector('#play').disabled,null,{timeout:180000});
          await page.locator('#play').click();await waitFrame(c=>c.blue>.35&&c.brown<.3);
          await page.waitForTimeout(5000);
          if(process.env.K2_ENGLISH_RESTART_CAPTURE)await page.screenshot({path:process.env.K2_ENGLISH_RESTART_CAPTURE});
          const loadLogStart=log.length;
          await page.keyboard.press('Enter');await page.waitForTimeout(2200);
          if(process.env.K2_ENGLISH_LOAD_MENU_CAPTURE)await page.screenshot({path:process.env.K2_ENGLISH_LOAD_MENU_CAPTURE});
          await page.keyboard.press('Enter');await page.waitForTimeout(700);
          await page.keyboard.press('Enter');await page.waitForTimeout(700);
          await page.keyboard.press('ArrowRight');await page.waitForTimeout(400);
          const confirmedAt=log.length;
          await page.keyboard.press('Enter');await page.waitForTimeout(12000);
          await waitFrame(c=>c.brown>.5);
          if(process.env.K2_ENGLISH_LOAD_CAPTURE)await page.screenshot({path:process.env.K2_ENGLISH_LOAD_CAPTURE});
          assert.ok(log.slice(Math.max(loadLogStart,confirmedAt)).some(s=>s.includes('[file] CreateFileA(')&&s.includes('Tutorial Deck')&&s.includes('disp 3')),
            'the game must open the English save after restarting');
        }
      }
    }
  }
  const stats=await page.evaluate(()=>({lazy:window.lazyStats,lang:window.langInfo}));
  assert.equal(stats.lang.lang,'en');
  assert.equal(stats.lang.launched.hostState,1);
  assert.equal(stats.lazy.failed,0);
  assert.deepEqual(errors,[]);
  console.log(`English overlay + streaming cabin PASS: ${stats.lazy.installed} resources, overlay active`);
} finally {
  await context?.close();
  await browser?.close();
  await new Promise(ok=>server.close(ok));
}
