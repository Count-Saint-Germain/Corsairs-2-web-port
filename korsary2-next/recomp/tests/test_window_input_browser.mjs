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
let browser;
try {
  await new Promise((ok, fail) => { server.once('error', fail); server.listen(0, '127.0.0.1', ok); });
  const executablePath = process.env.K2_TEST_BROWSER;
  browser = await chromium.launch({ headless: true, ...(executablePath ? { executablePath } : { channel: 'chromium' }), args: ['--enable-unsafe-webgpu'] });
  const context = await browser.newContext({ viewport: { width: 1280, height: 720 }, deviceScaleFactor: 2 });
  const page = await context.newPage(), errors = [];
  let menuOpens = 0, cabin = false, options = false;
  page.on('pageerror', error => errors.push(error.message));
  page.on('console', msg => {
    const line = msg.text();
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
  await page.goto(`http://127.0.0.1:${server.address().port}/?log&mute`);
  await page.locator('#play').waitFor({ state: 'visible', timeout: 120000 }); await page.locator('#play').click();
  await waitUntil(() => menuOpens > 0, 'main menu'); await waitFrame(c => c.blue > 0.35 && c.brown < 0.3, 'main menu');
  await page.keyboard.press('Enter');
  await page.waitForFunction(() => getComputedStyle(document.getElementById('canvas')).cursor === 'progress',
    null, { timeout: 30000 });
  await waitUntil(() => cabin, 'opening cabin');
  await waitFrame(c => c.brown > 0.5, 'opening cabin');
  await page.waitForFunction(() => getComputedStyle(document.getElementById('canvas')).cursor === 'none');
  // The cabin can render before the engine finishes activating its input.
  await page.waitForTimeout(4000);
  await page.evaluate(() => {
    window.testButtons = [];
    const original = window.port._input_mouse_button;
    window.port._input_mouse_button = (...args) => { window.testButtons.push(args); return original(...args); };
  });
  await page.mouse.click(600, 300);
  assert.equal(await page.evaluate(() => document.pointerLockElement), null, 'windowed game click must not capture pointer');
  await page.mouse.move(200, 610);
  const previousMenuOpens = menuOpens;
  await page.keyboard.down('Escape'); await page.waitForTimeout(150); await page.keyboard.up('Escape');
  await waitUntil(() => menuOpens > previousMenuOpens, 'main menu after Esc');
  await waitFrame(c => c.blue > 0.35 && c.brown < 0.3, 'game menu after Esc');
  await page.mouse.move(600, 320, { steps: 5 }); await page.mouse.click(600, 320);
  assert.equal(await page.evaluate(() => document.pointerLockElement), null, 'menu click must not capture pointer');
  const buttons = await page.evaluate(() => window.testButtons);
  assert.ok(buttons.filter(([b, down]) => b === 0 && down === 1).length >= 2, 'game and menu clicks reach guest');
  assert.ok(buttons.filter(([b, down]) => b === 0 && down === 0).length >= 2, 'clicks are released');
  // The menu starts with its own cursor center. Advance directly to the
  // visible Settings button even when the OS pointer began far from center.
  await page.mouse.move(652, 449);
  await page.waitForTimeout(350);
  await page.mouse.click(652, 449, { delay: 100 });
  await waitUntil(() => options, 'settings selected by its window coordinates', 15000);
  assert.deepEqual(errors, []);
  console.log(`Windowed game: clicks, Esc, absolute Settings selection and no pointer lock PASS (${browser.version()})`);
} finally {
  await browser?.close();
  if (server.listening) await new Promise(ok => server.close(ok));
}
