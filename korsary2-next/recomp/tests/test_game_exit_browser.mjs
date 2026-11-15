// Real-game regression: quitting the main menu must return control to the
// launcher and release the save lock. Runs only on a fresh, isolated origin.
import assert from 'node:assert/strict';
import http from 'node:http';
import { createRequire } from 'node:module';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { createStaticHandler } from '../../../scripts/serve_distribution.mjs';

const site = resolve(process.env.K2_TEST_DIST || 'distribution');
const here = dirname(fileURLToPath(import.meta.url));
const playwrightDir = resolve(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');
const serve = await createStaticHandler(site, {requireIndex:true});
const server = http.createServer((req,res) => serve(req,res).catch(e => { if (!res.headersSent) res.writeHead(500); res.end(String(e)); }));
let browser, context;
try {
  const externalUrl=process.env.K2_TEST_URL;
  if (!externalUrl) await new Promise((ok,fail) => { server.once('error',fail); server.listen(0,'127.0.0.1',ok); });
  const executablePath = process.env.K2_TEST_BROWSER;
  const launchOptions = {headless:true, ...(executablePath ? {executablePath} : {channel:'chromium'}), args:['--enable-unsafe-webgpu']};
  const profile = process.env.K2_TEST_PROFILE;
  if (process.env.K2_EXIT_SEED_SAVE && !profile) throw new Error('K2_TEST_PROFILE is required to retain the synthetic save.');
  if (profile) context = await chromium.launchPersistentContext(profile, {...launchOptions,viewport:{width:1280,height:720}});
  else { browser = await chromium.launch(launchOptions); context = await browser.newContext({viewport:{width:1280,height:720}}); }
  const page = context.pages()[0] || await context.newPage(), errors = [], lines = [];
  let menuLoaded = false;
  page.on('pageerror', e => errors.push(e.message));
  page.on('console', m => { const line=m.text(); if (/CreateFileA\(RESOURCE\\INI\\INTERFACES\\mainmenu\.ini\) snapshot/i.test(line)) menuLoaded=true; lines.push(line); if (lines.length > 100) lines.shift(); });
  const autoplay = process.env.K2_EXIT_AUTOPLAY === '1';
  const url=new URL(externalUrl||`http://127.0.0.1:${server.address().port}/`);
  url.searchParams.set('log','');url.searchParams.set('mute','');if(autoplay)url.searchParams.set('autoplay','');
  await page.goto(url.href);
  if (!autoplay) {
    await page.locator('#play').waitFor({state:'visible',timeout:120000});
    await page.locator('#play').click();
  }
  await page.waitForFunction(() => window.lazyStats?.installed >= 25, null, {timeout:120000});
  // Bootstrap completion does not mean the menu or an introductory video has
  // finished. Wait for the actual menu resource before sending game input.
  const deadline=Date.now()+60000;
  while(!menuLoaded && Date.now()<deadline) await page.waitForTimeout(200);
  assert.ok(menuLoaded,'the main menu must finish loading before the exit test');
  await page.waitForTimeout(2000);
  if (process.env.K2_EXIT_SEED_SAVE) await page.evaluate(async () => {
    const root = await navigator.storage.getDirectory();
    const game = await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const save = await game.getDirectoryHandle('SAVE', {create:true});
    const writer = await (await save.getFileHandle('exit-test-sentinel', {create:true})).createWritable();
    await writer.write('isolated test save - keep'); await writer.close();
  });
  await page.keyboard.press('ArrowUp');
  await page.waitForTimeout(400);
  if (process.env.K2_EXIT_CAPTURE) await page.screenshot({path:process.env.K2_EXIT_CAPTURE});
  await page.keyboard.press('Enter');
  if (process.env.K2_EXIT_DIAG) {
    await page.waitForTimeout(6000);
    if (process.env.K2_EXIT_CAPTURE) await page.screenshot({path:process.env.K2_EXIT_CAPTURE.replace(/\.png$/, '-after.png')});
    console.log('exit diagnostic:', JSON.stringify({url:page.url(), lines, errors,
      panelHidden:await page.locator('#panel').evaluate(e => e.classList.contains('hidden'))}));
  }
  await page.waitForFunction(() => !document.querySelector('#view-home').classList.contains('hidden') &&
    !document.querySelector('#panel').classList.contains('hidden'), null, {timeout:30000});
  assert.equal(await page.evaluate(() => document.pointerLockElement), null, 'quit must release the pointer');
  assert.equal(new URL(page.url()).searchParams.has('autoplay'), false, 'quit must not automatically restart the game');
  assert.equal(await page.evaluate(async () => navigator.locks.request('korsary2-game-lazy-experiment:save-backup',
    {ifAvailable:true}, lock => !!lock)), true, 'the page-lifetime save lock must be released');
  if (process.env.K2_EXIT_SEED_SAVE) assert.equal(await page.evaluate(async () => {
    const root = await navigator.storage.getDirectory();
    const game = await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const save = await game.getDirectoryHandle('SAVE');
    return (await (await save.getFileHandle('exit-test-sentinel')).getFile()).text();
  }), 'isolated test save - keep');
  await page.locator('#play').click();
  await page.waitForFunction(() => !!window.port && document.querySelector('#panel').classList.contains('hidden'), null, {timeout:120000});
  assert.deepEqual(errors, []);
  console.log('Main-menu exit, lock release and subsequent start: PASS');
} finally {
  await context?.close();
  await browser?.close();
  if(server.listening) await new Promise(ok=>server.close(ok));
}
