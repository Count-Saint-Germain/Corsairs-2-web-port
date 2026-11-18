// Optional full-game integration test. K2_LAZY_SITE must point to a prepared
// site. K2_LAZY_TEST_URL may point to an isolated local Worker with a disposable
// bucket; when set, Playwright injects failures before forwarding requests.
// No existing browser profile or save is opened; the context is ephemeral.
import assert from 'node:assert/strict';
import http from 'node:http';
import { access } from 'node:fs/promises';
import { createRequire } from 'node:module';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { createStaticHandler } from '../../../scripts/serve_distribution.mjs';

const site = process.env.K2_LAZY_SITE;
if (!site) throw new Error('Set K2_LAZY_SITE to a prepared experimental site; see docs/BUILD_FROM_CLONE.md.');
for (const name of ['index.html', 'build/game.js', 'build/game.wasm', 'experimental/lazy-client.mjs', 'game/manifest.json'])
  await access(join(site, name));

const here = dirname(fileURLToPath(import.meta.url));
const playwrightDir = resolve(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');
const serve = await createStaticHandler(site, { requireIndex: true });
let armed = false, failedKey = null, failureCount = 0;
const server = http.createServer((req, res) => {
  const path = (req.url || '').split('?', 1)[0];
  const key = req.headers.range && path.startsWith('/game/_k2pack/') ? `${path} ${req.headers.range}` : null;
  if (armed && key && (!failedKey || failedKey === key)) {
    failedKey ||= key;
    failureCount++;
    res.writeHead(503, { 'Content-Type': 'text/plain', 'Cache-Control': 'no-store' });
    return res.end('Injected temporary test failure');
  }
  serve(req, res).catch(error => { if (!res.headersSent) res.writeHead(500); res.end(String(error)); });
});
let browser;
try {
  const externalUrl = process.env.K2_LAZY_TEST_URL;
  if (!externalUrl) await new Promise((ok, fail) => { server.once('error', fail); server.listen(0, '127.0.0.1', ok); });
  browser = await chromium.launch({ headless: true, channel: 'chromium', args: ['--enable-unsafe-webgpu'] });
  const context = await browser.newContext({ viewport: { width: 1280, height: 720 } });
  const page = await context.newPage();
  if (externalUrl) await page.route('**/*', async route => {
    const request = route.request(), url = new URL(request.url());
    const range = request.headers().range;
    const key = range && url.pathname.startsWith('/game/_k2pack/') ? `${url.pathname} ${range}` : null;
    if (armed && key && (!failedKey || failedKey === key)) {
      failedKey ||= key; failureCount++;
      return route.fulfill({ status: 503, contentType: 'text/plain', body: 'Injected temporary test failure' });
    }
    return route.continue();
  });
  // The engine renders to WebGPU rather than accessible DOM nodes. Inspect a
  // downsampled screenshot in memory: the Russian main menu is predominantly
  // blue, whereas the opening cabin is predominantly brown. Ignore dark pixels
  // so the loading screen cannot satisfy the cabin check.
  const frameColours = async () => {
    const image = (await page.screenshot()).toString('base64');
    return page.evaluate(async encoded => {
      const bitmap = await createImageBitmap(await (await fetch(`data:image/png;base64,${encoded}`)).blob());
      const canvas = document.createElement('canvas'); canvas.width = 56; canvas.height = 20;
      const ctx = canvas.getContext('2d', { willReadFrequently: true });
      ctx.drawImage(bitmap, 0, 0, canvas.width, canvas.height); bitmap.close();
      const data = ctx.getImageData(0, 0, canvas.width, canvas.height).data;
      let blue = 0, brown = 0;
      for (let i = 0; i < data.length; i += 4) {
        const r = data[i], g = data[i + 1], b = data[i + 2];
        if (b > 12 && b > r * 1.12 && b > g * 1.08) blue++;
        if (r > 12 && r > g * 1.12 && g > b * 1.08) brown++;
      }
      return { blue: blue / (data.length / 4), brown: brown / (data.length / 4) };
    }, image);
  };
  const waitForFrame = async (predicate, description) => {
    const deadline = Date.now() + 90000;
    let colours;
    do {
      colours = await frameColours();
      if (predicate(colours)) return;
      await page.waitForTimeout(500);
    } while (Date.now() < deadline);
    throw new Error(`Did not render ${description}: ${JSON.stringify(colours)}`);
  };
  const resources = new Set(), pageErrors = [];
  page.on('pageerror', error => pageErrors.push(error.message));
  page.on('console', msg => {
    const line = msg.text();
    if (!line.startsWith('[lazy-result] ')) return;
    try { resources.add(JSON.parse(line.slice('[lazy-result] '.length)).path); } catch {}
  });
  const url = new URL(externalUrl || `http://127.0.0.1:${server.address().port}/`);
  url.searchParams.set('log', ''); url.searchParams.set('mute', '');
  await page.goto(url.href, { waitUntil: 'domcontentloaded' });
  await page.locator('#play').waitFor({ state: 'visible', timeout: 120000 });
  armed = true;
  await page.locator('#play').click();
  await page.locator('#lazy-recovery:not(.hidden) #lazy-retry:not(.hidden)').waitFor({ state: 'visible', timeout: 120000 });
  assert.ok(failedKey && failureCount >= 4, 'the same resource should exhaust its automatic HTTP retries');
  armed = false;
  await page.locator('#lazy-retry').click();
  await page.locator('#lazy-recovery').waitFor({ state: 'hidden', timeout: 20000 });
  await page.waitForFunction(() => window.lazyStats && window.lazyStats.installed >= 25, null, { timeout: 120000 });
  await waitForFrame(colours => colours.blue > 0.35 && colours.brown < 0.3, 'the blue game menu');
  await page.keyboard.press('Enter');
  const until = Date.now() + 90000;
  while (!resources.has('RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck.gm') && Date.now() < until)
    await page.waitForTimeout(500);
  assert.ok(resources.has('RESOURCE/MODELS/Locations/decks/tut_deck/tut_deck.gm'), 'new game must request the cabin after retry');
  await waitForFrame(colours => colours.brown > 0.5, 'the brown opening cabin');
  const stats = await page.evaluate(() => window.lazyStats);
  assert.equal(stats.failed, 0);
  assert.deepEqual(pageErrors, []);
  console.log(`Full-game recovery: PASS (${failureCount} HTTP 503 responses; ${stats.installed} resources installed)`);
} finally {
  await browser?.close();
  if (server.listening) await new Promise(resolveClose => server.close(resolveClose));
}
