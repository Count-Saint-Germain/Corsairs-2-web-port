// A real game on a fresh, temporary browser origin. No existing profiles or saves.
import assert from 'node:assert/strict';
import http from 'node:http';
import { createRequire } from 'node:module';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { createStaticHandler } from '../../../scripts/serve_distribution.mjs';

const here = dirname(fileURLToPath(import.meta.url));
const playwrightDir = resolve(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');
const serve = await createStaticHandler(resolve(process.env.K2_TEST_DIST || 'distribution'), { requireIndex: true });
const server = http.createServer((req, res) => serve(req, res).catch(error => {
  if (!res.headersSent) res.writeHead(500); res.end(String(error));
}));
let browser, context;
try {
  const externalUrl = process.env.K2_TEST_URL;
  if (!externalUrl) await new Promise((ok, fail) => { server.once('error', fail); server.listen(0, '127.0.0.1', ok); });
  const executablePath = process.env.K2_TEST_BROWSER;
  const launch = { headless: true, ...(executablePath ? { executablePath } : { channel: 'chromium' }), args: ['--enable-unsafe-webgpu'] };
  const viewport = { viewport: { width: 1280, height: 720 }, deviceScaleFactor: 2 };
  if (process.env.K2_TEST_PROFILE) context = await chromium.launchPersistentContext(process.env.K2_TEST_PROFILE, {...launch, ...viewport});
  else { browser = await chromium.launch(launch); context = await browser.newContext(viewport); }
  const page = context.pages()[0] || await context.newPage(), errors = [];
  let menuOpens = 0, cabin = false, options = false;
  page.on('pageerror', error => errors.push(error.message));
  page.on('console', msg => {
    const line = msg.text();
    if (process.env.K2_TEST_DEBUG && msg.type() === 'error') console.error('[browser]', line);
    if (/CreateFileA\(RESOURCE\\INI\\INTERFACES\\mainmenu\.ini\) snapshot/i.test(line)) menuOpens++;
    if (/CreateFileA\(RESOURCE\\INI\\INTERFACES\\option_screen\.ini\) snapshot/i.test(line)) options = true;
    if (line.includes('tut_deck.gm')) cabin = true;
  });
  const waitUntil = async (predicate, label, timeout = 120000) => {
    const deadline = Date.now() + timeout;
    while (!predicate() && Date.now() < deadline) await page.waitForTimeout(200);
    assert.ok(predicate(), `${label} did not load`);
  };
  const frameColours = async () => {
    const image = (await page.screenshot()).toString('base64');
    return page.evaluate(async encoded => {
      const bitmap = await createImageBitmap(await (await fetch(`data:image/png;base64,${encoded}`)).blob());
      const c = document.createElement('canvas'); c.width = 56; c.height = 20;
      const ctx = c.getContext('2d', { willReadFrequently: true }); ctx.drawImage(bitmap, 0, 0, c.width, c.height); bitmap.close();
      const data = ctx.getImageData(0, 0, c.width, c.height).data; let blue = 0, brown = 0;
      for (let i = 0; i < data.length; i += 4) {
        const [r, g, b] = [data[i], data[i + 1], data[i + 2]];
        if (b > 12 && b > r * 1.12 && b > g * 1.08) blue++;
        if (r > 12 && r > g * 1.12 && g > b * 1.08) brown++;
      }
      return { blue: blue / (data.length / 4), brown: brown / (data.length / 4) };
    }, image);
  };
  const waitFrame = async (predicate, label) => {
    const deadline = Date.now() + 60000; let colours;
    do { colours = await frameColours(); if (predicate(colours)) return; await page.waitForTimeout(400); } while (Date.now() < deadline);
    assert.fail(`${label} not rendered: ${JSON.stringify(colours)}`);
  };
  const introDialogVisible = async () => {
    const image = (await page.screenshot()).toString('base64');
    return page.evaluate(async encoded => {
      const bitmap = await createImageBitmap(await (await fetch(`data:image/png;base64,${encoded}`)).blob());
      const c = document.createElement('canvas'); c.width = 40; c.height = 1;
      const ctx = c.getContext('2d', {willReadFrequently: true}); ctx.imageSmoothingEnabled = false;
      ctx.drawImage(bitmap, 0, Math.floor(bitmap.height * .04), bitmap.width, 1, 0, 0, 40, 1); bitmap.close();
      const data = ctx.getImageData(0, 0, 40, 1).data; let gold = 0;
      for (let i = 0; i < data.length; i += 4) {
        const [r, g, b] = [data[i], data[i + 1], data[i + 2]];
        if (r > 110 && g > 65 && b < 80 && r > g * 1.1 && g > b * 1.5) gold++;
      }
      return gold >= 22;
    }, image);
  };
  const url = new URL(externalUrl || `http://127.0.0.1:${server.address().port}/`);
  url.searchParams.set('log', ''); url.searchParams.set('mute', '');
  await page.goto(url.href);
  await page.locator('#play').waitFor({ state: 'visible', timeout: 120000 });
  await page.waitForFunction(() => !document.getElementById('play').disabled, null, {timeout: 180000});
  await page.locator('#play').click();
  await waitUntil(() => menuOpens > 0, 'main menu'); await waitFrame(c => c.blue > 0.35 && c.brown < 0.3, 'main menu');
  await page.waitForFunction(() => window.port?._port_menu_mouse_active?.() === 1, null, {timeout: 10000});
  await page.keyboard.press('Enter');
  await page.waitForFunction(() => getComputedStyle(document.getElementById('canvas')).cursor === 'progress',
    null, { timeout: 30000 });
  await waitUntil(() => cabin, 'opening cabin');
  await waitFrame(c => c.brown > 0.5, 'opening cabin');
  await page.waitForFunction(() => getComputedStyle(document.getElementById('canvas')).cursor === 'none');
  // The cabin can render before the engine finishes activating its input.
  await page.waitForTimeout(4000);
  // Advance only while the opening dialogue frame is visible; extra action
  // presses can immediately start a new conversation with the nearby NPC.
  const dialogDeadline = Date.now() + 10000;
  while (!await introDialogVisible() && Date.now() < dialogDeadline) await page.waitForTimeout(300);
  for (let i = 0; i < 15 && await introDialogVisible(); i++) {
    await page.keyboard.down('Space'); await page.waitForTimeout(150); await page.keyboard.up('Space');
    await page.waitForTimeout(550);
  }
  assert.equal(await introDialogVisible(), false, 'opening conversation should be closed');
  await page.keyboard.down('KeyS'); await page.waitForTimeout(2000); await page.keyboard.up('KeyS');
  assert.equal(await page.evaluate(() => window.port._port_menu_mouse_active()), 0, 'the cabin is not a menu');
  await page.evaluate(() => {
    window.testButtons = [];
    window.testMoves = [];
    window.testKeys = [];
    window.testInputEvents = [];
    window.testLockErrors = [];
    const canvas = document.getElementById('canvas');
    const originalLock = canvas.requestPointerLock.bind(canvas);
    canvas.requestPointerLock = (...args) => {
      try {
        const result = originalLock(...args);
        result?.catch?.(error => window.testLockErrors.push(error.name + ': ' + error.message));
        return result;
      } catch (error) { window.testLockErrors.push(error.name + ': ' + error.message); throw error; }
    };
    document.addEventListener('pointerlockerror', () => window.testLockErrors.push('pointerlockerror'));
    const original = window.port._input_mouse_button;
    window.port._input_mouse_button = (...args) => { window.testButtons.push(args); return original(...args); };
    const originalMove = window.port._input_mouse_move;
    window.port._input_mouse_move = (...args) => { window.testMoves.push(args); return originalMove(...args); };
    const originalKey = window.port._input_key_hid;
    window.port._input_key_hid = (...args) => { window.testKeys.push(args); return originalKey(...args); };
    document.addEventListener('pointerlockchange', () => window.testInputEvents.push(['lock', !!document.pointerLockElement]));
    window.addEventListener('keydown', e => { if (e.code === 'Escape') window.testInputEvents.push(['keydown', e.code]); });
    window.addEventListener('keyup', e => { if (e.code === 'Escape') window.testInputEvents.push(['keyup', e.code]); });
  });
  await page.bringToFront();
  await page.locator('#canvas').focus();
  // Left click is the contextual action and can immediately reopen a nearby
  // conversation. Right click exercises the same capture path without doing so.
  await page.mouse.click(600, 300, {button: 'right'});
  try { await page.waitForFunction(() => document.pointerLockElement === document.getElementById('canvas'), null, {timeout: 10000}); }
  catch (error) {
    if (process.env.K2_TEST_DEBUG) console.log('Capture trace:', await page.evaluate(() => ({errors: window.testLockErrors,
      events: window.testInputEvents, menu: window.port._port_menu_mouse_active(), loading: document.getElementById('canvas').className,
      focused: document.hasFocus()})));
    if (process.env.K2_TEST_CAPTURE) await page.screenshot({path: process.env.K2_TEST_CAPTURE});
    throw error;
  }
  await page.mouse.move(1200, 300, {steps: 3});
  await page.mouse.move(1278, 300);
  await page.mouse.move(1500, 300);
  assert.ok(await page.evaluate(() => window.testMoves.some(([dx]) => dx !== 0)), 'relative mouse motion reaches the game while captured');
  assert.equal(await page.evaluate(() => document.pointerLockElement?.id), 'canvas', 'windowed gameplay keeps the pointer captured at the edge');
  const previousMenuOpens = menuOpens;
  await page.keyboard.down('Escape'); await page.waitForTimeout(150); await page.keyboard.up('Escape');
  if (process.env.K2_TEST_DEBUG) {
    await page.waitForTimeout(2000);
    console.log('Escape trace:', await page.evaluate(() => ({keys: window.testKeys, events: window.testInputEvents,
      menu: window.port._port_menu_mouse_active(), locked: !!document.pointerLockElement})));
    if (process.env.K2_TEST_CAPTURE) await page.screenshot({path: process.env.K2_TEST_CAPTURE});
  }
  await waitUntil(() => menuOpens > previousMenuOpens, 'main menu after Esc', 20000);
  await waitFrame(c => c.blue > 0.35 && c.brown < 0.3, 'game menu after Esc');
  await page.waitForFunction(() => window.port?._port_menu_mouse_active?.() === 1, null, {timeout: 10000});
  await page.waitForFunction(() => document.pointerLockElement === null, null, {timeout: 10000});
  await page.mouse.move(600, 320, { steps: 5 }); await page.mouse.click(600, 320);
  assert.equal(await page.evaluate(() => document.pointerLockElement), null, 'menu click must not capture pointer');
  const buttons = await page.evaluate(() => window.testButtons);
  assert.ok(buttons.some(([b, down]) => b === 1 && down === 1), 'game click reaches guest');
  assert.ok(buttons.some(([b, down]) => b === 1 && down === 0), 'game click is released');
  assert.ok(buttons.some(([b, down]) => b === 0 && down === 1), 'menu click reaches guest');
  assert.ok(buttons.some(([b, down]) => b === 0 && down === 0), 'menu click is released');
  // The menu starts with its own cursor center. Advance directly to the
  // visible Settings button even when the OS pointer began far from center.
  await page.mouse.move(652, 449);
  await page.waitForTimeout(350);
  if (process.env.K2_TEST_CAPTURE) await page.screenshot({path: process.env.K2_TEST_CAPTURE});
  await page.mouse.click(652, 449, { delay: 100 });
  try { await waitUntil(() => options, 'settings selected by its window coordinates', 30000); }
  catch (error) {
    if (process.env.K2_TEST_DEBUG) console.log('Settings trace:', await page.evaluate(() => ({buttons: window.testButtons, menu: window.port._port_menu_mouse_active(), locked: !!document.pointerLockElement})));
    if (process.env.K2_TEST_CAPTURE) await page.screenshot({path: process.env.K2_TEST_CAPTURE});
    throw error;
  }
  assert.deepEqual(errors, []);
  const browserVersion = browser?.version() || await page.evaluate(() => navigator.userAgent);
  console.log(`Windowed game: capture, edge motion, Esc, menu release and Settings selection PASS (${browserVersion})`);
} finally {
  await context?.close(); await browser?.close();
  if (server.listening) await new Promise(ok => server.close(ok));
}
