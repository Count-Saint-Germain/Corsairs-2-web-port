/* Exercise the real fullscreen handler and Keyboard Lock in Chromium.
 * The page and HTTP server are synthetic; the browser context is ephemeral.
 * No installed game, browser profile or saved game is accessed. */
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const here = dirname(fileURLToPath(import.meta.url));
const playwrightDir = resolve(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');
const script = readFileSync(join(here, '../web/port.js'), 'utf8');
const start = script.indexOf('function setupFullscreen() {');
const end = script.indexOf('\n// once the game starts:', start);
assert.ok(start >= 0 && end > start, 'fullscreen handler must exist');
const handler = script.slice(start, end);
const inputStart = script.indexOf('async function hookInput(');
const inputEnd = script.indexOf('\n// Gamepads (', inputStart);
assert.ok(inputStart >= 0 && inputEnd > inputStart, 'game input handler must exist');
const input = script.slice(inputStart, inputEnd);
const html = `<!doctype html><html><body><main>
  <div id="stage"><canvas id="canvas" tabindex="0"></canvas></div>
  <div id="touch-controls" hidden></div><button id="fs">Fullscreen</button>
  <button id="aspect"></button><svg><path id="fs-icon"></path></svg>
  <div id="fstip"></div><div id="fs-notice"></div><button id="esc-fallback"></button>
  </main><script>
  const $ = id => document.getElementById(id), PORT = {id:'fullscreen-test'};
  const safeLocalStorage = () => localStorage, uiText = (a, b) => b, resizeGameCanvas = () => {};
  const params = new URLSearchParams(location.search), noteGameInput = () => {};
  const HID = {Escape: 41, Backquote: 53};
  if (params.has('without-lock')) Object.defineProperty(navigator, 'keyboard', {value: undefined});
  params.set('touch', '0');
  window.gameKeyEvents = [];
  window.guestKeys = [];
  ${handler}
  ${input}
  setupFullscreen();
  hookInput({_input_key_hid: (...args) => guestKeys.push(args)}, false);
  for (const type of ['keydown', 'keyup']) window.addEventListener(type, event => {
    if (event.code === 'Escape') gameKeyEvents.push({type, prevented:event.defaultPrevented});
  });
  </script></body></html>`;
const server = createServer((req, res) => {
  res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8', 'Cache-Control': 'no-store' });
  res.end(html);
});
let browser;
try {
  await new Promise((ok, fail) => { server.once('error', fail); server.listen(0, '127.0.0.1', ok); });
  const executablePath = process.env.K2_TEST_BROWSER;
  browser = await chromium.launch({ headless: true, ...(executablePath ? { executablePath } : { channel: 'chromium' }) });
  const context = await browser.newContext();
  const page = await context.newPage();
  await page.goto(`http://127.0.0.1:${server.address().port}/`);
  assert.equal(await page.evaluate(() => typeof navigator.keyboard?.lock), 'function', 'Keyboard Lock unavailable');
  await page.click('#fs');
  await page.waitForFunction(() => !!document.fullscreenElement && document.querySelector('#fs').title.includes('double Esc'), null, { timeout: 5000 });
  await page.keyboard.press('Backquote');
  assert.deepEqual(await page.evaluate(() => guestKeys.splice(0)), [[41, 1], [41, 0]], 'grave key reaches the game as Esc');
  assert.equal(await page.evaluate(() => !!document.fullscreenElement), true, 'grave key keeps fullscreen active');
  await page.keyboard.press('Escape');
  const first = await page.evaluate(() => ({ fullscreen: !!document.fullscreenElement, events: gameKeyEvents.slice() }));
  assert.equal(first.fullscreen, true, 'first Esc must leave fullscreen active');
  assert.deepEqual(first.events, [{type:'keydown', prevented:true}, {type:'keyup', prevented:true}], 'first press reaches the game');
  await page.keyboard.press('Escape');
  await page.waitForFunction(() => !document.fullscreenElement, null, { timeout: 5000 });
  const events = await page.evaluate(() => gameKeyEvents.slice());
  assert.equal(events.filter(event => event.type === 'keydown').length, 1, 'second Esc must not reach the game');
  await page.goto(`http://127.0.0.1:${server.address().port}/?without-lock`);
  await page.click('#fs');
  await page.waitForFunction(() => !!document.fullscreenElement && !document.querySelector('#esc-fallback').classList.contains('hidden'));
  await page.keyboard.press('Backquote');
  assert.deepEqual(await page.evaluate(() => guestKeys), [[41, 1], [41, 0]], 'grave key works without Keyboard Lock');
  assert.equal(await page.evaluate(() => !!document.fullscreenElement), true);
  console.log(`Fullscreen Keyboard Lock, double Esc and grave key: PASS (Chromium ${browser.version()})`);
} finally {
  await browser?.close();
  await new Promise(resolveClose => server.close(resolveClose));
}
