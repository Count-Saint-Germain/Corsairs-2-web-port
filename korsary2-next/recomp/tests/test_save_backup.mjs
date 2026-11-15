import assert from 'node:assert/strict';
import { decodeBackup, encodeBackup } from '../web/save-export.mjs';
import { BACKUP_KEEP, backupFileName, planRetention, backupSavesBeforeUpdate, writeSaveBackupLocked }
  from '../web/save-protection.mjs';
import { importBackupZip } from '../web/save-import.mjs';

const enc = new TextEncoder();
const bytes = (s) => enc.encode(s);

// ---- a small in-memory OPFS mock: only what the modules use ----
class MockFile {
  constructor(bytes) { this.bytes = bytes; }
  async arrayBuffer() { return this.bytes.slice().buffer; }
  get size() { return this.bytes.length; }
}
const nf = () => { const e = new Error('NotFoundError'); e.name = 'NotFoundError'; return e; };
class MockDir {
  constructor(name = '') { this.name = name; this.files = new Map(); this.dirs = new Map(); this.failCreateFile = false; }
  // OPFS is case-sensitive: 'Slot1' and 'slot1' are different files there, exactly
  // like the replace flow relies on (write the new name, remove the old-case one).
  async getDirectoryHandle(n, { create } = {}) {
    const k = n;
    if (!this.dirs.has(k)) {
      if (!create) throw nf();
      this.dirs.set(k, new MockDir(n));
    }
    return this.dirs.get(k);
  }
  fileHandleOf(rec) {
    return {
      kind: 'file',
      async getFile() { return new MockFile(rec.bytes); },
      async createWritable() {
        const chunks = [];
        return {
          async write(c) { chunks.push(c instanceof Uint8Array ? c : new Uint8Array(await c.arrayBuffer())); },
          async close() {
            let out;
            if (chunks.length === 1) out = chunks[0];
            else {
              out = new Uint8Array(chunks.reduce((s, c) => s + c.length, 0));
              let o = 0;
              for (const c of chunks) { out.set(c, o); o += c.length; }
            }
            rec.bytes = out;
          },
        };
      },
    };
  }
  async getFileHandle(n, { create } = {}) {
    const k = n;
    if (!this.files.has(k)) {
      if (!create || this.failCreateFile) throw nf();
      this.files.set(k, { name: n, bytes: new Uint8Array(0) });
    }
    return this.fileHandleOf(this.files.get(k));
  }
  async removeEntry(n) {
    const k = n;
    if (this.files.has(k)) { this.files.delete(k); return; }
    if (this.dirs.has(k)) { this.dirs.delete(k); return; }
    throw nf();
  }
  async *entries() {
    for (const rec of [...this.files.values()]) yield [rec.name, this.fileHandleOf(rec)];
    for (const d of [...this.dirs.values()]) yield [d.name, d];
  }
  async seedFile(n, b) { this.files.set(n, { name: n, bytes: b }); }
  names() { return [...this.files.values()].map((f) => f.name).sort(); }
}
// cooperating Web Locks mock; `busy` simulates another tab holding the lock
const locks = { busy: false, request(name, opts, fn) { return fn(this.busy ? null : {}); } };

const root = new MockDir();
const openGame = (create) => root.getDirectoryHandle('korsary2-game', { create });
const backups = async () => {
  try { return await root.getDirectoryHandle('korsary2-game-backups', { create: false }); }
  catch (e) { if (e.name === 'NotFoundError') return null; throw e; }
};

// ---- pure helpers ----
assert.match(backupFileName('pre-update', new Date(1794337512456)), /^pre-update-\d{4}-\d{2}-\d{2}T\d{2}-\d{2}-\d{2}\.\d{3}Z\.zip$/);
assert.throws(() => backupFileName('a/b'), /метка/);
assert.throws(() => backupFileName(''), /метка/);
assert.throws(() => backupFileName('x'.repeat(41)), /метка/);
{
  const r = planRetention(['pre-update-2026-01-01T00-00-00-000Z.zip', 'pre-update-2026-03-01T00-00-00-000Z.zip',
                           'pre-update-2026-02-01T00-00-00-000Z.zip'], 2);
  assert.deepEqual(r.keep, ['pre-update-2026-02-01T00-00-00-000Z.zip', 'pre-update-2026-03-01T00-00-00-000Z.zip']);
  assert.deepEqual(r.remove, ['pre-update-2026-01-01T00-00-00-000Z.zip']);
  assert.deepEqual(planRetention([], 5), { keep: [], remove: [] });
  assert.deepEqual(planRetention(['a.zip'], 5), { keep: ['a.zip'], remove: [] });
  assert.throws(() => planRetention(['a.zip'], 0), /предел/);
}

// ---- backupSavesBeforeUpdate: nothing to protect is not an error ----
assert.deepEqual(await backupSavesBeforeUpdate(root, locks, 'korsary2-game'), { skipped: 'no-saves' });
await openGame(true);   // game root exists, SAVE still missing
assert.deepEqual(await backupSavesBeforeUpdate(root, locks, 'korsary2-game'), { skipped: 'no-saves' });
await (await openGame(true)).getDirectoryHandle('SAVE', { create: true });
assert.deepEqual(await backupSavesBeforeUpdate(root, locks, 'korsary2-game'), { skipped: 'empty' });

// a busy save lock refuses honestly
locks.busy = true;
await assert.rejects(() => backupSavesBeforeUpdate(root, locks, 'korsary2-game'), /заняты/);
locks.busy = false;

// ---- two saves: the archive lands in the sibling folder and decodes back ----
{
  const save = await (await openGame(true)).getDirectoryHandle('SAVE', { create: true });
  await (await save.getFileHandle('Slot1', { create: true })).createWritable()
    .then(async (w) => { await w.write(bytes('slot one data')); await w.close(); });
  await (await save.getFileHandle('Тест.sav', { create: true })).createWritable()
    .then(async (w) => { await w.write(new Uint8Array([1, 2, 3])); await w.close(); });
}
const r1 = await backupSavesBeforeUpdate(root, locks, 'korsary2-game');
assert.match(r1.backup, /^pre-update-\d{4}-\d{2}-\d{2}T\d{2}-\d{2}-\d{2}\.\d{3}Z\.zip$/);
assert.equal(r1.entries, 2);
assert.deepEqual(r1.warnings, []);
const bdir = await backups();
assert.ok(bdir);
const archived = decodeBackup(new Uint8Array(await (await (await bdir.getFileHandle(r1.backup, { create: false })).getFile()).arrayBuffer()));
assert.deepEqual(archived.entries.map((e) => e.name).sort(), ['Slot1', 'Тест.sav']);
assert.deepEqual(archived.entries.find((e) => e.name === 'Slot1').bytes, bytes('slot one data'));

// ---- retention: only BACKUP_KEEP newest archives survive ----
for (let i = 1; i <= 12; i++)
  await bdir.seedFile(`pre-update-2020-01-01T00-00-${String(i).padStart(2, '0')}-000Z.zip`, bytes('old'));
const r2 = await backupSavesBeforeUpdate(root, locks, 'korsary2-game');
assert.match(r2.backup, /^pre-update( \(\d+\))?-\d{4}/);   // same ms as r1 dedups with " (2)"
assert.equal(bdir.names().length, BACKUP_KEEP);
assert.equal(bdir.names().includes('pre-update-2020-01-01T00-00-01-000Z.zip'), false);   // oldest pruned
assert.ok(bdir.names().includes(r2.backup));

// ---- writeSaveBackupLocked guards ----
await assert.rejects(() => writeSaveBackupLocked(root, 'korsary2-game', [], 'x'), /Нет файлов/);   // encodeBackup limits
await assert.rejects(() => writeSaveBackupLocked(null, 'korsary2-game', [{ name: 'a', bytes: bytes('1') }], 'x'), /OPFS/);

// Brave can report a fixed 2 GiB quota even after usage has exceeded it.
// A backup and save import must still work; a real quota failure must leave saves unchanged.
{
  const oldNavigator = Object.getOwnPropertyDescriptor(globalThis, 'navigator');
  const setNavigator = (value) => Object.defineProperty(globalThis, 'navigator', { value, configurable: true });
  try {
    setNavigator({ brave: { isBrave: async () => true }, storage: { estimate: async () => ({quota: 2 ** 31, usage: 2400 * 1e6}) } });
    const safeRoot = new MockDir();
    const safeOpen = (create) => safeRoot.getDirectoryHandle('korsary2-game', {create});
    const save = await (await safeOpen(true)).getDirectoryHandle('SAVE', {create:true});
    await save.seedFile('existing', bytes('unchanged'));
    const result = await backupSavesBeforeUpdate(safeRoot, locks, 'korsary2-game');
    assert.ok(result.backup, 'privacy-capped quota does not block a real successful backup');
    const imported = await importBackupZip(safeOpen, locks, 'korsary2-game', encodeBackup([{name:'new', bytes:bytes('new-save')}]), 'skip', {root:safeRoot});
    assert.deepEqual(imported.restored, ['new']);
    assert.deepEqual(save.files.get('existing').bytes, bytes('unchanged'));
    assert.deepEqual(save.files.get('new').bytes, bytes('new-save'));
    setNavigator({ storage: { estimate: async () => ({quota: 2 ** 31, usage: 2400 * 1e6}) } });
    await assert.rejects(() => backupSavesBeforeUpdate(safeRoot, locks, 'korsary2-game'), /недостаточно места/);
    setNavigator({ brave: { isBrave: async () => true }, storage: { estimate: async () => ({quota: 2 ** 31, usage: 2400 * 1e6}) } });
    const badRoot = new MockDir(), badBackup = await badRoot.getDirectoryHandle('korsary2-game-backups', {create:true});
    const originalFileHandle = badBackup.getFileHandle.bind(badBackup);
    badBackup.getFileHandle = async (name, opts) => {
      const h = await originalFileHandle(name, opts);
      if (!opts?.create) return h;
      return {...h, async createWritable() { return { async write() { throw Object.assign(new Error('full'), {name:'QuotaExceededError'}); }, async abort() {} }; }};
    };
    await assert.rejects(() => writeSaveBackupLocked(badRoot, 'korsary2-game', [{name:'x',bytes:bytes('data')}], 'pre-update'), e => e.name === 'QuotaExceededError');
    assert.deepEqual(badBackup.names(), [], 'failed backup is cleaned up');
    assert.deepEqual(save.files.get('existing').bytes, bytes('unchanged'));
    // Real OPFS write failure must keep an existing slot and remove a new empty placeholder.
    const getSaveFile = save.getFileHandle.bind(save);
    save.getFileHandle = async (name, opts) => {
      const h = await getSaveFile(name, opts);
      if (!['blocked-new','existing'].includes(name)) return h;
      return {...h, async createWritable() { return { async write() { throw Object.assign(new Error('full'), {name:'QuotaExceededError'}); }, async abort() {} }; }};
    };
    await assert.rejects(() => importBackupZip(safeOpen, locks, 'korsary2-game', encodeBackup([{name:'blocked-new',bytes:bytes('new')}]), 'skip', {root:safeRoot}), e => e.name === 'QuotaExceededError');
    assert.equal(save.files.has('blocked-new'), false, 'failed new save is removed');
    await assert.rejects(() => importBackupZip(safeOpen, locks, 'korsary2-game', encodeBackup([{name:'existing',bytes:bytes('replacement')}]), 'replace', {root:safeRoot}), e => e.name === 'QuotaExceededError');
    assert.deepEqual(save.files.get('existing').bytes, bytes('unchanged'), 'failed replacement preserves existing save');
  } finally {
    if (oldNavigator) Object.defineProperty(globalThis, 'navigator', oldNavigator);
    else delete globalThis.navigator;
  }
}

// ---- importBackupZip replace path backs up the old bytes first ----
const oldBytes = bytes('ORIGINAL slot bytes');
{
  const save = await (await openGame(true)).getDirectoryHandle('SAVE', { create: false });
  // the slot exists on disk under a different letter case than the archive's name,
  // exactly the flow the browser session verified: conflict by key, new name written,
  // old-case file removed once the new bytes are in place
  await (await save.getFileHandle('Slot1', { create: false })).createWritable()
    .then(async (w) => { await w.write(oldBytes); await w.close(); });
}
const archive = encodeBackup([{ name: 'slot1', bytes: bytes('NEW slot bytes') }]);
const rep = await importBackupZip(openGame, locks, 'korsary2-game', archive, 'replace', { root });
assert.equal(rep.needsDecision, false);
assert.equal(rep.backupSkipped.length, 0);
assert.match(rep.backup, /^replace-import-\d{4}/);
const back = decodeBackup(new Uint8Array(await (await (await bdir.getFileHandle(rep.backup, { create: false })).getFile()).arrayBuffer()));
assert.deepEqual(back.entries, [{ name: 'Slot1', bytes: oldBytes }]);   // old bytes, under the on-disk name
{
  const save = await (await openGame(false)).getDirectoryHandle('SAVE', { create: false });
  const f = await (await save.getFileHandle('slot1', { create: false })).getFile();
  assert.deepEqual(new Uint8Array(await f.arrayBuffer()), bytes('NEW slot bytes'));
}

// skip and root-less imports create no restore point
const skip = await importBackupZip(openGame, locks, 'korsary2-game', encodeBackup([{ name: 'fresh', bytes: bytes('f') }]), 'skip', { root });
assert.equal(skip.backup, null);
assert.ok(!skip.warnings.length);
const noRoot = await importBackupZip(openGame, locks, 'korsary2-game', encodeBackup([{ name: 'fresh2', bytes: bytes('f') }]));
assert.equal(noRoot.backup, null);

// unreadable existing file: replaced without backup, reported
{
  const save = await (await openGame(false)).getDirectoryHandle('SAVE', { create: false });
  await (await save.getFileHandle('broken', { create: true })).createWritable()
    .then(async (w) => { await w.write(bytes('x')); await w.close(); });
  const origGetFile = MockFile.prototype.arrayBuffer;
  MockFile.prototype.arrayBuffer = async function () {
    if (this.bytes.length === 1 && this.bytes[0] === 120) throw new Error('io');   // the 'broken' file ("x")
    return origGetFile.call(this);
  };
  const rep2 = await importBackupZip(openGame, locks, 'korsary2-game', encodeBackup([{ name: 'broken', bytes: bytes('fixed') }]), 'replace', { root });
  MockFile.prototype.arrayBuffer = origGetFile;
  assert.deepEqual(rep2.backupSkipped, ['broken']);
  assert.equal(rep2.backup, null);   // nothing readable to back up
  const f = await (await save.getFileHandle('broken', { create: false })).getFile();
  assert.deepEqual(new Uint8Array(await f.arrayBuffer()), bytes('fixed'));
}

// replace with a broken backups folder fails closed and leaves SAVE untouched
{
  const badRoot = new MockDir();
  const save = await (await badRoot.getDirectoryHandle('korsary2-game', { create: true })).getDirectoryHandle('SAVE', { create: true });
  await (await save.getFileHandle('slot1', { create: true })).createWritable()
    .then(async (w) => { await w.write(oldBytes); await w.close(); });
  (await badRoot.getDirectoryHandle('korsary2-game-backups', { create: true })).failCreateFile = true;   // backup write fails
  const openBad = (create) => badRoot.getDirectoryHandle('korsary2-game', { create });
  await assert.rejects(() => importBackupZip(openBad, locks, 'korsary2-game', archive, 'replace', { root: badRoot }));
  const f = await (await save.getFileHandle('slot1', { create: false })).getFile();
  assert.deepEqual(new Uint8Array(await f.arrayBuffer()), oldBytes);   // fail closed: untouched
}

// ---- SAVE_META time records travel with the slot's write decision ----
{
  const meta = (name) => new Uint8Array([1, 2, 3, 4, 5, 6, 7, name.length]);
  const game = await (await openGame(true));
  const save = await game.getDirectoryHandle('SAVE', { create: true });
  const metaDir = await game.getDirectoryHandle('SAVE_META', { create: true });
  const recordOf = async (n) => {
    try { return new Uint8Array(await (await (await metaDir.getFileHandle(n, { create: false })).getFile()).arrayBuffer()); }
    catch (e) { if (e.name === 'NotFoundError') return null; throw e; }
  };
  // restore: a fresh slot with an archive record gets that record on disk
  const restore = await importBackupZip(openGame, locks, 'korsary2-game',
    encodeBackup([{ name: 'timed', bytes: bytes('t'), meta: meta('timed') }]));
  assert.equal(restore.metaWritten, 1);
  assert.deepEqual(await recordOf('timed.time'), meta('timed'));
  assert.deepEqual(restore.warnings, []);
  // replace across letter case: the archive record lands under the new spelling
  // and the old-case record is removed; identical slots keep theirs untouched
  await (await save.getFileHandle('Slot1', { create: true })).createWritable()
    .then(async (w) => { await w.write(bytes('old again')); await w.close(); });
  await metaDir.seedFile('Slot1.time', meta('Slot1'));
  await metaDir.seedFile('untouched.time', meta('x'));
  const repMeta = await importBackupZip(openGame, locks, 'korsary2-game',
    encodeBackup([
      { name: 'slot1', bytes: bytes('brand new'), meta: meta('slot1') },
      { name: 'timed', bytes: bytes('t') },   // identical slot, archive without a record
    ]), 'replace', { root });
  assert.equal(repMeta.needsDecision, false);
  assert.equal(repMeta.metaWritten, 1);
  assert.equal(await recordOf('Slot1.time'), null);   // old-case record replaced by the new spelling
  assert.deepEqual(await recordOf('slot1.time'), meta('slot1'));
  assert.deepEqual(await recordOf('untouched.time'), meta('x'));
  // replaced without any archive record: the stale record must go
  const repNoMeta = await importBackupZip(openGame, locks, 'korsary2-game',
    encodeBackup([{ name: 'slot1', bytes: bytes('third version') }]), 'replace', { root });
  assert.equal(repNoMeta.metaWritten, 0);
  assert.equal(await recordOf('slot1.time'), null);   // no time may claim the new bytes
  assert.deepEqual(await recordOf('untouched.time'), meta('x'));
  // unpaired record (its slot is not in the archive) is ignored, not restored
  const orphan = await importBackupZip(openGame, locks, 'korsary2-game',
    encodeBackup([{ name: 'fresh3', bytes: bytes('f') }, { name: 'ghost', bytes: bytes('g') }])
  );
  assert.ok(orphan.ignored.includes('SAVE_META/ghost.time') === false);   // nothing meta-like was in this archive
  assert.deepEqual(orphan.ignored, []);
}

// ---- E5: SAVE_META language labels (<slot>.lang) travel with the slot: backup, restore, replace, stale labels ----
{
  const en = bytes('en'), ru = bytes('ru');
  const game = await openGame(true);
  const save = await game.getDirectoryHandle('SAVE', { create: true });
  const metaDir = await game.getDirectoryHandle('SAVE_META', { create: true });
  const labelOf = async (n) => {
    try { return new Uint8Array(await (await (await metaDir.getFileHandle(n, { create: false })).getFile()).arrayBuffer()); }
    catch (e) { if (e.name === 'NotFoundError') return null; throw e; }
  };
  const put = async (n, b) => { await (await save.getFileHandle(n, { create: true })).createWritable().then(async (w) => { await w.write(b); await w.close(); }); };
  const time = (n) => new Uint8Array([9, 8, 7, 6, 5, 4, 3, n.length]);
  for (const n of ['lang1', 'lang2', 'nolang']) await put(n, bytes('data ' + n));
  await metaDir.seedFile('lang1.lang', en); await metaDir.seedFile('lang2.lang', ru); await metaDir.seedFile('lang1.time', time('lang1'));
  await metaDir.seedFile('nolang.lang', bytes('xx'));   // an invalid label is no label: it is not archived
  // a pre-update backup carries the labels (and still the time records)
  const b = await backupSavesBeforeUpdate(root, locks, 'korsary2-game');
  const dec = decodeBackup(new Uint8Array(await (await (await (await backups()).getFileHandle(b.backup, { create: false })).getFile()).arrayBuffer()));
  assert.deepEqual(dec.lang.map((m) => [m.name, new TextDecoder().decode(m.bytes)]).sort(), [['lang1', 'en'], ['lang2', 'ru']]);
  assert.ok(dec.meta.some((m) => m.name === 'lang1'));
  // restore into a fresh slot: the label lands, nothing else is written for it
  const restored = await importBackupZip(openGame, locks, 'korsary2-game', encodeBackup([{ name: 'fresh-en', bytes: bytes('f'), lang: en }, { name: 'fresh-plain', bytes: bytes('p') }]));
  assert.deepEqual([restored.metaWritten, restored.langWritten, restored.warnings], [0, 1, []]);
  assert.deepEqual(await labelOf('fresh-en.lang'), en); assert.equal(await labelOf('fresh-plain.lang'), null);
  // replace: a slot whose archive has no label loses the stale one; with a label it gets the new one (an old-case record goes); the restore point keeps the old label
  await put('Cased', bytes('old cased')); await metaDir.seedFile('Cased.lang', en);
  const rep = await importBackupZip(openGame, locks, 'korsary2-game',
    encodeBackup([{ name: 'lang1', bytes: bytes('new lang1') }, { name: 'cased', bytes: bytes('new cased'), lang: ru }, { name: 'lang2', bytes: bytes('data lang2'), lang: en }]), 'replace', { root });
  assert.equal(rep.needsDecision, false);
  assert.equal(await labelOf('lang1.lang'), null, 'no stale label may claim the replaced bytes');
  assert.equal(await labelOf('Cased.lang'), null); assert.deepEqual(await labelOf('cased.lang'), ru);
  assert.deepEqual(await labelOf('lang2.lang'), ru, 'an identical slot keeps the label it has (the archive label is not applied)');
  assert.equal(rep.langWritten, 1); assert.deepEqual(rep.identical, ['lang2']);
  const rp = decodeBackup(new Uint8Array(await (await (await (await backups()).getFileHandle(rep.backup, { create: false })).getFile()).arrayBuffer()));
  assert.deepEqual(rp.lang.map((m) => [m.name, new TextDecoder().decode(m.bytes)]).sort(), [['Cased', 'en'], ['lang1', 'en']], 'the restore point keeps the old labels');
  assert.ok(rp.meta.some((m) => m.name === 'lang1'), 'and the old time record');
  // a new slot restored with 'skip' gets its own label; an identical slot with an archive label is left alone (its own label stays)
  const skipped = await importBackupZip(openGame, locks, 'korsary2-game', encodeBackup([{ name: 'brand-new', bytes: bytes('g'), lang: en }, { name: 'lang2', bytes: bytes('data lang2'), lang: en }]), 'skip', { root });
  assert.deepEqual(await labelOf('brand-new.lang'), en); assert.deepEqual(await labelOf('lang2.lang'), ru); assert.equal(skipped.langWritten, 1);
}

// A failed sidecar write after replacing a slot must not leave the old label
// or time attached to the new bytes. The restore point still has the original.
for (const suffix of ['.lang', '.time']) for (const phase of ['open','write','close']) {
  const r = new MockDir(), go = create => r.getDirectoryHandle('game', {create});
  const game=await go(true), save=await game.getDirectoryHandle('SAVE',{create:true}), meta=await game.getDirectoryHandle('SAVE_META',{create:true});
  const oldTime=new Uint8Array([1,2,3,4,5,6,7,8]), newTime=new Uint8Array([8,7,6,5,4,3,2,1]);
  await save.seedFile('slot',bytes('old-save')); await meta.seedFile('slot.lang',bytes('ru')); await meta.seedFile('slot.time',oldTime);
  await meta.seedFile('other.lang',bytes('en'));
  const getMeta=meta.getFileHandle.bind(meta); let aborts=0;
  meta.getFileHandle=async(name,opts)=>{
    const h=await getMeta(name,opts);
    if(name!=='slot'+suffix || !opts?.create) return h;
    return {...h, async createWritable() {
      if(phase==='open') throw Object.assign(new Error('full'),{name:'QuotaExceededError'});
      const w=await h.createWritable();
      return {...w, async write(data) { if(phase==='write') throw Object.assign(new Error('full'),{name:'QuotaExceededError'}); await w.write(data); },
        async close() { if(phase==='close') throw Object.assign(new Error('full'),{name:'QuotaExceededError'}); await w.close(); },
        async abort() { aborts++; await w.abort?.(); }};
    }};
  };
  const result=await importBackupZip(go,locks,'game',encodeBackup([{name:'slot',bytes:bytes('new-save'),lang:bytes('en'),meta:newTime}]),'replace',{root:r});
  assert.equal(result.written,1); assert.equal(result.warnings.length,1); assert.match(result.warnings[0],/Не удалось записать/);
  assert.deepEqual(save.files.get('slot').bytes,bytes('new-save'));
  assert.equal(meta.files.has('slot'+suffix),false, 'old sidecar must not be attributed to the new slot');
  assert.deepEqual(meta.files.get('other.lang').bytes,bytes('en'));
  if(phase!=='open') assert.equal(aborts,1);
  const backupDir=await r.getDirectoryHandle('game-backups',{create:false});
  const backup=decodeBackup(backupDir.files.get(result.backup).bytes);
  assert.deepEqual(backup.entries[0].bytes,bytes('old-save'));
  assert.deepEqual(backup.lang[0].bytes,bytes('ru')); assert.deepEqual(backup.meta[0].bytes,oldTime);
}

// If the browser also refuses the cleanup, do not conceal the stale label:
// report it and retain a backup with the old slot and its metadata.
{
  const r=new MockDir(), go=create=>r.getDirectoryHandle('game',{create}), game=await go(true);
  const save=await game.getDirectoryHandle('SAVE',{create:true}), meta=await game.getDirectoryHandle('SAVE_META',{create:true});
  await save.seedFile('slot',bytes('old')); await meta.seedFile('slot.lang',bytes('ru'));
  const get=meta.getFileHandle.bind(meta), remove=meta.removeEntry.bind(meta);
  meta.getFileHandle=async(name,opts)=> { const h=await get(name,opts); return name==='slot.lang' && opts?.create ? {...h,createWritable:async()=>{throw Object.assign(new Error('full'),{name:'QuotaExceededError'});}} : h; };
  meta.removeEntry=async name=> {if(name==='slot.lang')throw new Error('permission denied');return remove(name);};
  const result=await importBackupZip(go,locks,'game',encodeBackup([{name:'slot',bytes:bytes('new'),lang:bytes('en')}]),'replace',{root:r});
  assert.equal(result.warnings.length,2); assert.match(result.warnings[0],/Не удалось убрать устаревшую запись языка/);
  const backup=decodeBackup((await r.getDirectoryHandle('game-backups',{create:false})).files.get(result.backup).bytes);
  assert.deepEqual(backup.entries[0].bytes,bytes('old')); assert.deepEqual(backup.lang[0].bytes,bytes('ru'));
}

console.log('save backup/restore points (pre-update + replace-import) + retention: PASS');
