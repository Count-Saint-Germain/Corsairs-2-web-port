import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { createHash } from 'node:crypto';
import vm from 'node:vm';
import * as transfer from '../web/game-transfer.mjs';
import * as saveProtection from '../web/save-protection.mjs';
import * as lazyBootstrap from '../web/experimental/lazy-bootstrap.mjs';

// Exercise the actual page's OPFS routines with deterministic write failures.
// port.js is a classic browser script, so load only its standalone functions.
const source = readFileSync(new URL('../web/port.js', import.meta.url), 'utf8');
const start = source.indexOf('async function fileHandle(');
const end = source.indexOf('// Downloads whatever the manifest lists', start);
assert.ok(start >= 0 && end > start, 'page download helpers must be present');
const functions = source.slice(start, end)
  .replaceAll("import('./game-transfer.mjs')", 'Promise.resolve(transfer)')
  .replaceAll("import('./save-protection.mjs')", 'Promise.resolve(protection)');
const lazyStart = source.indexOf('async function downloadLazyResource(');
const lazyEnd = source.indexOf('\n// Per-slot netplay userdata', lazyStart);
assert.ok(lazyStart >= 0 && lazyEnd > lazyStart, 'experimental repair helper must be present');
const lazyHelper = source.slice(lazyStart, lazyEnd)
  .replaceAll("import('./experimental/lazy-bootstrap.mjs')", 'Promise.resolve(lazyBootstrap)');
const quota = () => Object.assign(new Error('full'), { name: 'QuotaExceededError' });
const missing = () => Object.assign(new Error('missing'), { name: 'NotFoundError' });

function fixture({ old, failAt, chunks = [Buffer.from('new')], status = 200 } = {}) {
  const files = new Map();
  if (old !== undefined) files.set('options', Buffer.from(old));
  let canceled = false;
  const root = {
    async getDirectoryHandle(name) {
      return directory(name);
    },
    async getFileHandle(name, {create = false} = {}) { return file(name, create); },
    async removeEntry(name) { if (!files.delete(name)) throw missing(); },
  };
  function directory(prefix) {
    return {
      async getDirectoryHandle(name) { return directory(prefix + '/' + name); },
      async getFileHandle(name, {create = false} = {}) { return file(prefix + '/' + name, create); },
      async removeEntry(name) { if (!files.delete(prefix + '/' + name)) throw missing(); },
    };
  }
  function file(name, create) {
    if (!files.has(name)) { if (!create) throw missing(); files.set(name, Buffer.alloc(0)); }
    return {
      async getFile() { return new Blob([files.get(name)]); },
      async createWritable(opts = {}) {
        if (failAt === 'open') throw quota();
        let data = opts.keepExistingData ? Buffer.from(files.get(name)) : Buffer.alloc(0), pos = 0;
        return {
          async seek(n) { pos = n; },
          async truncate(n) { data = data.subarray(0, n); },
          async write(value) {
            if (failAt === 'write') throw quota();
            const v = Buffer.from(value), result = Buffer.alloc(Math.max(data.length, pos + v.length));
            data.copy(result); v.copy(result, pos); data = result; pos += v.length;
          },
          async close() { if (failAt === 'close') throw quota(); files.set(name, data); },
          async abort() {},
        };
      },
    };
  }
  const fetch = async () => ({ok:true, status, body:{getReader(){let i=0;return {
    async read(){return i < chunks.length ? {done:false, value:chunks[i++]} : {done:true};},
    async cancel(){canceled=true;},
  };}}});
  const protection = { ...saveProtection, async fetchVerifiedOptions() { return Buffer.from('new'); } };
  const ctx = vm.createContext({transfer, protection, lazyBootstrap, fetch, GAME_BASE:'http://local/game/', Map, Promise, Error, Object});
  vm.runInContext(functions + '\nlet lazyPlan = null;\n' + lazyHelper +
    '\nglobalThis.exposed = {downloadFile, downloadOptionsFile, downloadLazyResource, setLazyPlan: plan => { lazyPlan = plan; }};', ctx,
    {filename:fileURLToPath(new URL('../web/port.js', import.meta.url))});
  return {root, files, page:ctx.exposed, get canceled(){return canceled;}};
}

for (const kind of ['options', 'raw']) {
  for (const failAt of ['open', 'write', 'close']) {
    for (const existing of [false, true]) test(`${kind}: ${failAt} failure ${existing ? 'preserves the previous file' : 'removes a new placeholder'}`, async () => {
      const f = fixture({old:existing ? 'previous' : undefined, failAt});
      const run = kind === 'options'
        ? () => f.page.downloadOptionsFile(f.root, {path:'options'}, () => {})
        : () => f.page.downloadFile('http://local/', f.root, 'options', 3, 0, () => {}, {path:'options'}, {});
      await assert.rejects(run, e => e.name === 'QuotaExceededError');
      if (existing) assert.equal(f.files.get('options').toString(), 'previous');
      else assert.equal(f.files.has('options'), false);
    });
  }
}

test('raw short and oversized responses do not overwrite the existing file', async () => {
  for (const chunks of [[Buffer.from('no')], [Buffer.from('toolong')]]) {
    const f = fixture({old:'previous', chunks});
    await assert.rejects(() => f.page.downloadFile('http://local/', f.root, 'options', 3, 0, () => {}, {path:'options'}, {}), /got/);
    assert.equal(f.files.get('options').toString(), 'previous');
    assert.equal(f.canceled, true);
  }
});

test('successful raw and options writes commit their contents', async () => {
  for (const kind of ['options', 'raw']) {
    const f = fixture();
    if (kind === 'options') await f.page.downloadOptionsFile(f.root, {path:'options'}, () => {});
    else await f.page.downloadFile('http://local/', f.root, 'options', 3, 0, () => {}, {path:'options'}, {});
    assert.equal(f.files.get('options').toString(), 'new');
  }
});

const sha = data => createHash('sha256').update(data).digest('hex');

test('lazy cache repair publishes only a verified immutable manifest entry', async () => {
  const entry = {path:'RESOURCE/missing.bin', size:3, sha256:sha('new')};
  const f = fixture({chunks:[Buffer.from('new')]});
  f.files.set(entry.path, Buffer.from('broken old bytes'));
  f.files.set('SAVE/Captain', Buffer.from('save-unchanged'));
  f.page.setLazyPlan({files:[entry], packs:[]});
  await f.page.downloadLazyResource(f.root, entry);
  assert.equal(f.files.get(entry.path).toString(), 'new');
  assert.equal(f.files.get('SAVE/Captain').toString(), 'save-unchanged');
  await assert.rejects(() => f.page.downloadLazyResource(f.root, {...entry, path:'SAVE/Captain'}), /refused/);
  await assert.rejects(() => f.page.downloadLazyResource(f.root, {...entry}), /refused/);
  assert.equal(f.files.get('SAVE/Captain').toString(), 'save-unchanged');
});

test('failed lazy cache repair keeps the existing resource and save intact', async () => {
  const entry = {path:'RESOURCE/missing.bin', size:3, sha256:sha('new')};
  const f = fixture({chunks:[Buffer.from('bad')]});
  f.files.set(entry.path, Buffer.from('broken old bytes'));
  f.files.set('SAVE/Captain', Buffer.from('save-unchanged'));
  f.page.setLazyPlan({files:[entry], packs:[]});
  await assert.rejects(() => f.page.downloadLazyResource(f.root, entry), /SHA-256/);
  assert.equal(f.files.get(entry.path).toString(), 'broken old bytes');
  assert.equal(f.files.get('SAVE/Captain').toString(), 'save-unchanged');
});

test('raw overlay SHA mismatch preserves old data and removes new placeholders', async () => {
  for (const existing of [false, true]) {
    const f = fixture({old:existing ? 'previous' : undefined, chunks:[Buffer.from('bad')]});
    await assert.rejects(() => f.page.downloadFile('http://local/', f.root, 'options', 3, 0, () => {},
      {path:'options', sha256:sha('new')}, {verifySha:true}), /SHA-256/);
    if (existing) assert.equal(f.files.get('options').toString(), 'previous');
    else assert.equal(f.files.has('options'), false);
  }
});

test('resumed raw overlay hashes its existing prefix before committing', async () => {
  for (const expected of ['prefix', 'preBAD']) {
    const f = fixture({old:'pre', chunks:[Buffer.from('fix')], status:206});
    const run = () => f.page.downloadFile('http://local/', f.root, 'options', 6, 3, () => {},
      {path:'options', sha256:sha(expected)}, {verifySha:true});
    if (expected === 'prefix') {
      await run();
      assert.equal(f.files.get('options').toString(), 'prefix');
    } else {
      await assert.rejects(run, /SHA-256/);
      assert.equal(f.files.get('options').toString(), 'pre');
    }
  }
});

test('resumed ordinary game file still appends without overlay hashing', async () => {
  const f = fixture({old:'pre', chunks:[Buffer.from('fix')], status:206});
  await f.page.downloadFile('http://local/', f.root, 'options', 6, 3, () => {}, {path:'options'}, {});
  assert.equal(f.files.get('options').toString(), 'prefix');
});
