/* Real emulated touch against the production panel/CSS with a recording bridge.
 * This does not load the game or use a persistent profile. */
import { readFileSync } from 'node:fs';
import { createRequire } from 'node:module';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';
import assert from 'node:assert/strict';

const here = dirname(fileURLToPath(import.meta.url));
const web = join(here, '../web');
const playwright = join(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwright, 'browsers');
const { chromium, devices } = createRequire(join(playwright, 'package.json'))('playwright');
const html = readFileSync(join(web, 'index.html'), 'utf8');
const style = html.match(/<style>([\s\S]*?)<\/style>/)[0];
const panel = html.match(/<section id="touch-controls"[\s\S]*?<\/section>/)[0];
const moduleUrl = 'data:text/javascript;base64,' + readFileSync(join(web, 'touch-controls.mjs')).toString('base64');
const browser = await chromium.launch({ headless: true });
try {
  for (const viewport of [{ width: 320, height: 568 }, { width: 568, height: 320 }]) {
    const context = await browser.newContext({ ...devices['iPhone 13'], viewport });
    const page = await context.newPage();
    await page.setContent(`<meta name="viewport" content="width=device-width,initial-scale=1">${style}<main><div id="stage"><canvas id="canvas"></canvas></div>${panel}</main>`);
    await page.evaluate(async url => {
      const { mountTouchControls } = await import(url); window.bridge = [];
      mountTouchControls({ root: document.querySelector('#touch-controls'), input: {
        key: (...v) => bridge.push(['key', ...v]), button: (...v) => bridge.push(['button', ...v]), move: (...v) => bridge.push(['move', ...v]),
      } });
    }, moduleUrl);
    const cdp = await context.newCDPSession(page);
    const grip = page.locator('.touch-scroll-grip');
    const position = async () => page.evaluate(() => {
      const root = document.querySelector('#touch-controls');
      return root.scrollHeight > root.clientHeight + 1 ? root.scrollTop : window.scrollY;
    });
    const maximum = async () => page.evaluate(() => {
      const root = document.querySelector('#touch-controls');
      return root.scrollHeight > root.clientHeight + 1 ? root.scrollHeight - root.clientHeight : document.documentElement.scrollHeight - innerHeight;
    });
    const swipe = async direction => {
      const rect = await grip.boundingBox(); assert(rect, 'scroll grip must remain visible');
      const x = Math.round(rect.x + rect.width / 2), y = Math.round(rect.y + rect.height / 2);
      const end = Math.max(1, Math.min(viewport.height - 1, y + direction * 18));
      assert(y >= 0 && y < viewport.height && end !== y, 'scroll grip must stay within the viewport');
      await cdp.send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: [{ x, y, id: 1 }] });
      for (let step = 1; step <= 5; step++) {
        await new Promise(resolve => setTimeout(resolve, 12));
        await cdp.send('Input.dispatchTouchEvent', { type: 'touchMove', touchPoints: [{ x, y: Math.round(y + (end - y) * step / 5), id: 1 }] });
      }
      await cdp.send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
      await new Promise(resolve => setTimeout(resolve, 120));
    };
    const start = await position();
    const limit = await maximum(); assert(limit > 10, 'fixture must need scrolling');
    for (let i = 0; i < 20 && await position() < limit - 2; i++) await swipe(-1);
    assert(await position() >= limit - 2, `swipe down to offscreen controls (${viewport.width}×${viewport.height})`);
    assert.deepEqual(await page.evaluate(() => bridge), [], 'scroll must not send gameplay input');
    for (let i = 0; i < 20 && await position() > start + 2; i++) await swipe(1);
    assert(await position() <= start + 2, 'swipe back to the initial position');
    await page.locator('[data-touch-group="land"] [data-touch-key="44"]').tap();
    assert.deepEqual(await page.evaluate(() => bridge), [['key', 44, 1], ['key', 44, 0]], 'game button still receives touch');
    await context.close();
  }
  // Verify the sticky grip never overlays the initially displayed controls at
  // typical phone sizes, and the pad remains hit-testable in every layout.
  for (const viewport of [{ width: 393, height: 852 }, { width: 852, height: 393 }]) {
    const context = await browser.newContext({ ...devices['iPhone 13'], viewport });
    const page = await context.newPage();
    await page.setContent(`<meta name="viewport" content="width=device-width,initial-scale=1">${style}<main><div id="stage"><canvas id="canvas"></canvas></div>${panel}</main>`);
    await page.evaluate(async url => {
      const { mountTouchControls } = await import(url);
      mountTouchControls({ root: document.querySelector('#touch-controls'), input: { key() {}, button() {}, move() {} } });
    }, moduleUrl);
    for (const group of ['land', 'sea', 'menu', 'extra']) {
      await page.evaluate(() => { document.querySelector('#touch-controls').scrollTop = 0; window.scrollTo(0, 0); });
      await page.locator(`[data-touch-tab="${group}"]`).tap();
      const collisions = await page.evaluate(group => {
        const header = document.querySelector('.touch-header').getBoundingClientRect();
        const overlap = r => r.left < header.right && r.right > header.left && r.top < header.bottom && r.bottom > header.top;
        return [...document.querySelectorAll(`[data-touch-group="${group}"] button, .touch-pad`)].filter(e => overlap(e.getBoundingClientRect())).map(e => e.textContent);
      }, group);
      assert.deepEqual(collisions, [], `sticky header overlaps controls at ${viewport.width}×${viewport.height}, ${group}`);
      const pad = page.locator('.touch-pad'); await pad.scrollIntoViewIfNeeded();
      assert(await pad.evaluate(e => { const r = e.getBoundingClientRect(); return document.elementFromPoint(r.x + r.width / 2, r.y + r.height / 2) === e; }),
        `trackpad must remain reachable at ${viewport.width}×${viewport.height}, ${group}`);
    }
    await context.close();
  }
  console.log('mobile panel scrolling and gameplay touch: PASS (emulated Chromium, synthetic input bridge)');
} finally { await browser.close(); }
