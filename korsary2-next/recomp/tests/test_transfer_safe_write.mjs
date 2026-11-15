import test from 'node:test';
import assert from 'node:assert/strict';
import { createSafeWriteTarget, downloadPackedFile, downloadPackRun, remotePath } from '../web/game-transfer.mjs';
import { Dir, buildGame, fileHandle, put, read, removeFile, server } from './pack_fixture.mjs';

const original = new TextEncoder().encode('old game asset');
const saved = new TextEncoder().encode('player save');
const data = new Uint8Array(4096).fill(65);
const raw = new Uint8Array([1, 2, 3, 4]);
const filename = 'RESOURCE/test.dat';
const standalone = buildGame({[filename]: data}, {pack:false});
const packed = buildGame({[filename]: data, 'RESOURCE/raw.bin': raw}, {pack:true});

function safeTarget(dir, name, fault) {
  return createSafeWriteTarget({
    getFile: async create => {
      const handle = await fileHandle(dir, name, create);
      return { ...handle, async createWritable(opts) {
        if (fault === 'open') throw Object.assign(new Error('quota open'), {name:'QuotaExceededError'});
        const w = await handle.createWritable(opts);
        return { ...w,
          async write(chunk) { if (fault === 'write') throw Object.assign(new Error('quota write'), {name:'QuotaExceededError'}); return w.write(chunk); },
          async close() { if (fault === 'close') throw Object.assign(new Error('quota close'), {name:'QuotaExceededError'}); return w.close(); },
        };
      }};
    },
    removeFile: () => removeFile(dir, name),
  });
}
async function scenario({kind, existed, fault}) {
  const dir = new Dir();
  if (existed) await put(dir, filename, original);
  await put(dir, 'SAVE/slot1', saved);
  const target = safeTarget(dir, filename, fault);
  let entry, run;
  if (kind === 'gzip') {
    entry = {...standalone.manifest.files[0]};
    if (fault === 'digest') entry.sha256 = '0'.repeat(64);
    run = () => downloadPackedFile({entry, url:'http://t/game/'+remotePath(entry), fetchImpl:server(standalone.objects), ...target});
  } else {
    entry = {...packed.manifest.files.find(e => e.path === filename)};
    if (kind === 'pack-raw') entry = {...packed.manifest.files.find(e => e.path === 'RESOURCE/raw.bin'), path:filename};
    if (fault === 'digest') entry.sha256 = '0'.repeat(64);
    const pack = packed.manifest.packs[entry.pack];
    run = () => downloadPackRun({pack, entries:[entry], url:'http://t/game/'+pack.path, fetchImpl:server(packed.objects),
      openWritable: () => target.openWritable(), discard: () => target.discard()});
  }
  if (fault) await assert.rejects(run);
  else await run();
  if (fault) assert.deepEqual(await read(dir, filename), existed ? original : null, `${kind}/${fault}: retain existing only`);
  else assert.deepEqual(await read(dir, filename), kind === 'pack-raw' ? raw : data);
  assert.deepEqual(await read(dir, 'SAVE/slot1'), saved, 'saves remain unchanged');
}
for (const kind of ['gzip', 'pack-gzip', 'pack-raw']) for (const existed of [false, true]) {
  test(`${kind}: ${existed ? 'existing file' : 'new file'} handles failures atomically`, async () => {
    for (const fault of ['open', 'write', 'close', 'digest']) await scenario({kind, existed, fault});
    await scenario({kind, existed, fault:null});
  });
}
test('the target never turns non-NotFound read errors into a creation', async () => {
  let created = false;
  const t = createSafeWriteTarget({getFile: async create => { if (create) created = true; throw new Error('denied'); }, removeFile: async () => { throw new Error('must not remove'); }});
  await assert.rejects(t.openWritable(), /denied/); await t.discard(); assert.equal(created, false);
});
