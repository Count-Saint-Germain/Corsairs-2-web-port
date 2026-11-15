/* Exercise the actual launcher restore button and its packaged dynamic imports.
 * The fixture is a tiny synthetic dist, the ZIP is synthetic, and Chromium
 * uses an ephemeral profile with its own OPFS. No game or user data is read. */
import assert from 'node:assert/strict';
import { createServer } from 'node:http';
import { createRequire } from 'node:module';
import { buildFixture } from './overlay_fixture.mjs';
import { mkdtempSync, readFileSync, rmSync, statSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { dirname, extname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { decodeBackup, encodeBackup } from '../web/save-export.mjs';
import { bindLazyIdentity, planLazyBootstrap } from '../web/experimental/lazy-bootstrap.mjs';
import { webcrypto } from 'node:crypto';

const here = dirname(fileURLToPath(import.meta.url));
const playwrightDir = resolve(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwrightDir, 'browsers');
const { chromium } = createRequire(join(playwrightDir, 'package.json'))('playwright');
const tmp = mkdtempSync(join(tmpdir(), 'k2-restore-launcher-'));
let dist;
const realDist = process.env.K2_TEST_DIST;
const lazy = process.env.K2_TEST_LAZY === '1';
if (lazy && !realDist) throw new Error('Lazy launcher test requires K2_TEST_DIST with an experimental build');
if (realDist) {
  dist = resolve(realDist);
  if (process.env.K2_TEST_OMIT_IMPORT) throw new Error('Negative control can only remove files from the synthetic fixture');
} else {
  try { dist = (await buildFixture(join(tmp, 'fx'), { overlay: false })).dist; }
  catch (error) { rmSync(tmp, { recursive: true, force: true }); throw error; }
}
// Negative control: the same UI scenario must fail when the packaged dynamic
// import is removed. Only the temporary synthetic fixture is changed.
if (process.env.K2_TEST_OMIT_IMPORT === '1') rmSync(join(dist, 'save-import.mjs'));
const headers = { 'Cross-Origin-Opener-Policy': 'same-origin', 'Cross-Origin-Embedder-Policy': 'require-corp',
  'Cross-Origin-Resource-Policy': 'same-origin', 'Cache-Control': 'no-store' };
const mime = { '.html': 'text/html', '.js': 'text/javascript', '.mjs': 'text/javascript', '.json': 'application/json', '.wasm': 'application/wasm' };
const requests = [];
const server = createServer((req, res) => {
  try {
    const path = decodeURIComponent(new URL(req.url, 'http://localhost').pathname);
    requests.push(path);
    if (path === '/__synthetic_setup__') {
      res.writeHead(200, { ...headers, 'Content-Type': 'text/html; charset=utf-8' });
      return res.end('<!doctype html><title>Temporary test setup</title>');
    }
    if (path.includes('..')) { res.writeHead(404, headers); return res.end(); }
    const file = join(dist, path === '/' ? 'index.html' : path.slice(1));
    if (!statSync(file).isFile()) throw new Error('not a file');
    const bytes = readFileSync(file);
    res.writeHead(200, { ...headers, 'Content-Type': mime[extname(file)] || 'application/octet-stream', 'Content-Length': bytes.length });
    res.end(req.method === 'HEAD' ? undefined : bytes);
  } catch { res.writeHead(404, headers); res.end(); }
});
let browser;
try {
  await new Promise((ok, fail) => { server.once('error', fail); server.listen(0, '127.0.0.1', ok); });
  const origin = `http://127.0.0.1:${server.address().port}`;
  browser = await chromium.launch({ headless: true });
  const context = await browser.newContext();
  try {
    const page = await context.newPage();
    const errors = [];
    page.on('pageerror', e => errors.push(e.message));
    // GPU is irrelevant to importing saves: the actual game is never started.
    await page.addInitScript(() => Object.defineProperty(navigator, 'gpu', {
      value: { requestAdapter: async () => ({ info: {}, isFallbackAdapter: false }) }, configurable: true,
    }));
    if (realDist) {
      // Avoid a 2.35 GB install solely for the restore UI check. The marker is
      // created only inside this fresh ephemeral browser profile, and the game
      // is never started. Actual modules and page still come from the dist.
      const manifest = JSON.parse(readFileSync(join(dist, 'game/manifest.json'), 'utf8'));
      const version = lazy ? (await bindLazyIdentity(planLazyBootstrap(manifest), webcrypto.subtle)).version : manifest.version;
      await page.goto(origin + '/__synthetic_setup__');
      await page.evaluate(async ({v,lazy}) => {
        const root = await navigator.storage.getDirectory();
        const normal = await root.getDirectoryHandle('korsary2-game', { create: true });
        if (lazy) {
          const save = await normal.getDirectoryHandle('SAVE', {create:true});
          const sentinel = await save.getFileHandle('Slot1', {create:true});
          const writer = await sentinel.createWritable(); await writer.write('normal-root-unchanged'); await writer.close();
          const extra = await save.getFileHandle('ClassicOnly', {create:true});
          const extraWriter = await extra.createWritable(); await extraWriter.write('classic-only'); await extraWriter.close();
        }
        const game = lazy ? await root.getDirectoryHandle('korsary2-game-lazy-experiment', {create:true}) : normal;
        for (const name of lazy ? ['experimental-version.json', 'experimental-lazy.json'] : ['installed.json']) {
          const file = await game.getFileHandle(name, { create: true });
          const writer = await file.createWritable(); await writer.write(JSON.stringify({ version: v })); await writer.close();
        }
      }, {v:version,lazy});
    }
    await page.goto(origin + (lazy ? '/' : '/?lazy=0'));
    await page.waitForFunction(() => !document.querySelector('#view-home').classList.contains('hidden'), null, { timeout: 30_000 });
    const readSave = async name => page.evaluate(async ({n,lazy}) => {
      const root = await navigator.storage.getDirectory();
      const game = await root.getDirectoryHandle(lazy ? 'korsary2-game-lazy-experiment' : 'korsary2-game');
      const save = await game.getDirectoryHandle('SAVE');
      return (await (await save.getFileHandle(n)).getFile()).text();
    }, {n:name,lazy});
    const pickArchive = async entries => {
      const buffer = Buffer.from(encodeBackup(entries.map(([name, bytes]) => ({ name, bytes: new TextEncoder().encode(bytes) }))));
      const chooser = page.waitForEvent('filechooser');
      await page.click('#restore-saves');
      await (await chooser).setFiles({ name: 'synthetic.zip', mimeType: 'application/zip', buffer });
    };
    const status = page.locator('#backup-status');
    await pickArchive([['Slot1', 'before']]);
    await status.waitFor({ state: 'visible' });
    await page.waitForFunction(() => /восстановлено новых файлов: 1|Failed to fetch|Load failed|Не удалось/.test(document.querySelector('#backup-status').textContent), null, { timeout: 10_000 });
    assert.match(await status.textContent(), /восстановлено новых файлов: 1/, 'restore must succeed, not report a missing import or another failure');
    assert.equal(await readSave('Slot1'), 'before');

    // A conflicting archive must ask; skip preserves old bytes and imports
    // unrelated new slots. The test clicks the production UI, not its module.
    await pickArchive([['Slot1', 'after'], ['Slot2', 'new slot']]);
    await page.waitForFunction(() => !document.querySelector('#restore-decision').classList.contains('hidden'), null, { timeout: 10_000 });
    assert.equal(await readSave('Slot1'), 'before');
    await page.click('#restore-skip');
    await page.waitForFunction(() => document.querySelector('#backup-status').textContent.includes('конфликтных пропущено: 1'), null, { timeout: 10_000 });
    assert.equal(await readSave('Slot1'), 'before');
    assert.equal(await readSave('Slot2'), 'new slot');

    await pickArchive([['Slot1', 'after']]);
    await page.waitForFunction(() => !document.querySelector('#restore-decision').classList.contains('hidden'), null, { timeout: 10_000 });
    await page.click('#restore-replace');
    await page.waitForFunction(() => document.querySelector('#backup-status').textContent.includes('заменено: 1'), null, { timeout: 10_000 });
    assert.equal(await readSave('Slot1'), 'after');
    if (lazy) {
      const normal = await page.evaluate(async () => {
        const root = await navigator.storage.getDirectory();
        const game = await root.getDirectoryHandle('korsary2-game');
        const save = await game.getDirectoryHandle('SAVE');
        return (await (await save.getFileHandle('Slot1')).getFile()).text();
      });
      assert.equal(normal, 'normal-root-unchanged', 'lazy restore must never modify normal saves');
    }
    const download = page.waitForEvent('download');
    await page.click('#backup-saves');
    const archive = decodeBackup(new Uint8Array(readFileSync(await (await download).path())));
    const text = name => new TextDecoder().decode(archive.entries.find(entry => entry.name === name).bytes);
    assert.equal(text('Slot1'), 'after', 'export reads the active mode root');
    assert.equal(text('Slot2'), 'new slot');
    if (lazy) {
      await page.click('#copy-classic-saves');
      await page.waitForFunction(() => !document.querySelector('#restore-decision').classList.contains('hidden'), null, { timeout: 10_000 });
      assert.equal(await readSave('Slot1'), 'after', 'classic copy waits for a conflict decision');
      await page.click('#restore-skip');
      await page.waitForFunction(() => document.querySelector('#backup-status').textContent.includes('конфликтных пропущено: 1'), null, { timeout: 10_000 });
      assert.equal(await readSave('Slot1'), 'after');
      assert.equal(await readSave('ClassicOnly'), 'classic-only');
      // Explicitly choosing Replace copies the conflicting source bytes into
      // the streaming root; it must still never mutate the classic root.
      await page.click('#copy-classic-saves');
      await page.waitForFunction(() => !document.querySelector('#restore-decision').classList.contains('hidden'), null, { timeout: 10_000 });
      assert.equal(await readSave('Slot1'), 'after');
      await page.click('#restore-replace');
      await page.waitForFunction(() => document.querySelector('#backup-status').textContent.includes('заменено: 1'), null, { timeout: 10_000 });
      assert.equal(await readSave('Slot1'), 'normal-root-unchanged');
      const classic = await page.evaluate(async () => {
        const root = await navigator.storage.getDirectory();
        const save = await (await root.getDirectoryHandle('korsary2-game')).getDirectoryHandle('SAVE');
        return Promise.all(['Slot1','ClassicOnly'].map(async n => (await (await save.getFileHandle(n)).getFile()).text()));
      });
      assert.deepEqual(classic, ['normal-root-unchanged', 'classic-only'], 'copy never changes the classic root');
    }
    assert.deepEqual(errors, []);
    if (realDist) assert.deepEqual(requests.filter(p => p.startsWith('/game/') && p !== '/game/manifest.json'), [], 'real game assets must not be downloaded');
    console.log('packaged launcher restore: PASS (synthetic ZIP, real Chromium OPFS; game not started)');
  } finally { await context.close(); }
} finally {
  if (browser) await browser.close();
  await new Promise(resolve => server.close(resolve));
  rmSync(tmp, { recursive: true, force: true });
}
