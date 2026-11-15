// Page half of SAVE_TX (web/save-tx.mjs) on hand-written journals over a real temp directory behind an OPFS-shaped
// API (save_tx_fixture.mjs), with a Web Lock model. Synthetic: no browser, no OPFS, no game. The end-to-end
// crash matrix against the real native host is test_save_tx_matrix.mjs.
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import {
  parseJournal, buildTransactions, recoverSaveTx, recoverSaveTxLocked, resolveSaveTxConflict, saveTxRequested,
  SAVE_TX_HISTORY_KEEP, SAVE_TX_COMPACT_BYTES,
} from '../web/save-tx.mjs';
import { runExclusiveForPageLifetime } from '../web/save-owner.mjs';
import { opfsRoot, makeCtx, Locks, holding, snapshot, sameSnapshot, tmpRoot, walk, sha, memRoot, jline, hex, txId, priorName, metaHex } from './save_tx_fixture.mjs';

const here = path.dirname(fileURLToPath(import.meta.url));
const BASE = process.env.SAVE_TX_TMP ?? path.join(here, '..', 'web_toolchain', 'tmp', 'save-tx-unit');
const ROOT = 'korsary2-game';
fs.rmSync(BASE, { recursive: true, force: true });
const B = (s) => new TextEncoder().encode(s);
const META_OLD = Uint8Array.of(1, 2, 3, 4, 5, 6, 7, 8), META_NEW = Uint8Array.of(9, 9, 9, 9, 9, 9, 9, 9);
const NOW = Date.UTC(2026, 10, 12, 12, 0, 0);
const ft = (ms) => (BigInt(ms) + 11644473600000n) * 10000n;
const OLDER = ft(NOW - 60 * 60 * 1000), FRESH = ft(NOW - 1000);

function world(name) {
  const base = tmpRoot(`${name}-`, BASE), game = path.join(base, ROOT);
  for (const d of ['', 'SAVE', 'SAVE_META', 'SAVE_TX']) fs.mkdirSync(path.join(game, d), { recursive: true });
  const w = {
    base, game,
    put: (rel, bytes) => { fs.mkdirSync(path.dirname(path.join(game, rel)), { recursive: true }); fs.writeFileSync(path.join(game, rel), bytes); },
    get: (rel) => (fs.existsSync(path.join(game, rel)) ? new Uint8Array(fs.readFileSync(path.join(game, rel))) : null),
    has: (rel) => fs.existsSync(path.join(game, rel)),
    list: (dir) => (fs.existsSync(path.join(game, dir)) ? fs.readdirSync(path.join(game, dir)).sort() : []),
    journal: (...lines) => fs.appendFileSync(path.join(game, 'SAVE_TX/journal.log'), lines.join('')),
    snap: () => snapshot(base),
    // a protected slot: prior copy + arm record
    arm(tx, slot, kind, bytes, meta, n = 1, ts = FRESH, lang = null) {   // lang (E5): 'en' | 'ru' | null (no label: the field is absent, as the host writes it)
      this.put(`SAVE_TX/${priorName(tx, n)}`, bytes);
      return jline('arm', tx, { kind, slot: hex(slot), prior: priorName(tx, n), size: bytes.length, sha: sha(bytes), meta: meta ? metaHex(meta) : '-',
        ...(lang ? { lang: metaHex(B(lang)) } : {}) }, ts);
    },
    recover: (opts = {}) => recoverSaveTx({ root: opfsRoot(base, opts.ctx), rootName: ROOT, locks: opts.locks ?? new Locks(), now: () => NOW, ...opts }),
  };
  return w;
}
const same = Uint8Array.prototype.every;
void same;
const eq = (a, b) => Buffer.compare(Buffer.from(a), Buffer.from(b)) === 0;
const cyc = (tx, target, n, errors = 0, bytes = 100, ts = FRESH) => jline('cycle', tx, { target: hex(target), n, writes: 3, errors, bytes }, ts);
const OLD = B('OLD slot bytes'), NEW = B('NEW slot bytes, fully written'), PART = B('par');
const tx1 = txId(1), tx2 = txId(2), tx3 = txId(3);

// ---------------------------------------------------------------- 1. parsing
{
  const good = jline('arm', tx1, { kind: 'delete', slot: hex('A'), prior: priorName(tx1), size: 3, sha: sha(B('abc')), meta: '-' });
  let p = parseJournal(good + 'v1 cycle tx=00000000000000000001 ts=1 tar');   // torn final record, no newline
  assert.equal(p.events.length, 1); assert.equal(p.tornTail, true); assert.equal(p.warnings.length, 0);
  p = parseJournal(good.replace('size=3', 'size=4') + good);                 // damaged line is skipped with a warning
  assert.equal(p.events.length, 1); assert.equal(p.warnings.length, 1); assert.match(p.warnings[0].reason, /контрольная сумма/);
  p = parseJournal(jline('arm', tx1, { kind: 'delete', slot: hex('A/B'), prior: priorName(tx1), size: 3, sha: sha(B('abc')), meta: '-' }));
  assert.equal(p.events.length, 0); assert.equal(p.warnings.length, 1);     // path traversal / bad name never becomes an event
  p = parseJournal(jline('arm', tx1, { kind: 'delete', slot: hex('A'), prior: '../x', size: 3, sha: sha(B('abc')), meta: '-' }));
  assert.equal(p.events.length, 0);
  p = parseJournal(good.replace('v1 arm', 'v2 arm').replace(/ crc=.*/, '') .trimEnd() + ' crc=00000000\n');
  assert.equal(p.events.length, 0);                                         // wrong crc first: damaged, not "unsupported"
  p = parseJournal('v2 arm tx=x crc=' + '0'.repeat(8) + '\n'); assert.equal(p.unsupported, null);
  const v2 = (() => { const body = 'v2 arm tx=00000000000000000001 ts=1'; return body; })();
  void v2;
  const txs = buildTransactions(parseJournal(good + cyc(tx1, 'B', 1)).events);
  assert.equal(txs.length, 1); assert.equal(txs[0].arms.length, 1); assert.equal(txs[0].anomaly, true);   // cycle without a create
}

// ---------------------------------------------------------------- 2. committed transaction accepted only when the fixture matches
{
  const w = world('commit');
  w.put('SAVE/Oxbay 2', NEW); w.put('SAVE_META/Oxbay 2.time', META_NEW);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD),
    jline('create', tx1, { target: hex('Oxbay 2'), fresh: 1 }), cyc(tx1, 'Oxbay 2', 1), cyc(tx1, 'Oxbay 2', 2),
    jline('commit', tx1, { target: hex('Oxbay 2'), size: NEW.length, sha: sha(NEW) }));
  const r = await w.recover();
  assert.equal(r.status, 'recovered'); assert.equal(r.txs[0].outcome, 'accepted');
  assert(eq(w.get('SAVE/Oxbay 2'), NEW)); assert(eq(w.get('SAVE_META/Oxbay 2.time'), META_NEW)); assert(!w.has('SAVE/Oxbay'));
  assert(w.has(`SAVE_TX/${priorName(tx1)}`), 'the replaced slot stays recoverable as history');
  assert.equal((await w.recover()).status, 'clean');
}
{   // same fixture, but the slot's bytes changed after the commit: never accepted, never touched, copy in quarantine
  const w = world('commit-mismatch');
  const other = B('NEW slot bytes, fully written!');
  w.put('SAVE/Oxbay', other);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }),
    cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2), jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) }));
  const r = await w.recover();
  assert.equal(r.status, 'quarantined'); assert.equal(r.txs[0].outcome, 'quarantined');
  assert(eq(w.get('SAVE/Oxbay'), other));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.current/Oxbay`), other));
  assert.equal((await w.recover()).status, 'clean');
  // explicit later decision: bring back the previous completed version, current bytes already safe in quarantine
  const back = await resolveSaveTxConflict({ root: opfsRoot(w.base), rootName: ROOT, locks: await heldLocks(), tx: tx1, choice: 'restore-prior', now: () => NOW });
  assert.equal(back.status, 'rolled-back');
  assert(eq(w.get('SAVE/Oxbay'), OLD)); assert(eq(w.get('SAVE_META/Oxbay.time'), META_OLD));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/Oxbay`), other));
  assert.equal((await w.recover()).status, 'clean');
}
async function heldLocks() { const l = new Locks(); l.held.set(`${ROOT}:save-backup`, 'exclusive'); return l; }

// ---------------------------------------------------------------- 3. the host's commit claim is re-validated
for (const [label, lines] of [
  ['one cycle only', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) })]],
  ['cycle with errors', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2, 1), jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) })]],
  ['empty cycle', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2, 0, 0), jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) })]],
  ['anomaly before commit', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), jline('anomaly', tx1, { what: 'overlap' }), cyc(tx1, 'Oxbay', 2), jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) })]],
  ['commit for another target', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2), jline('commit', tx1, { target: hex('Other'), size: NEW.length, sha: sha(NEW) })]],
  ['fail line', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), jline('fail', tx1, { reason: 'io-errors' })]],
  ['no commit', (a, c) => [a, c, cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2)]],
]) {
  const w = world('claim');
  w.put('SAVE/Oxbay', NEW);   // the bytes even match the would-be fixture: the claim itself is what fails
  w.journal(...lines(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 })));
  const r = await w.recover();
  assert.equal(r.status, 'rolled-back', label);
  assert(eq(w.get('SAVE/Oxbay'), OLD), `${label}: previous version restored`);
  assert(eq(w.get('SAVE_META/Oxbay.time'), META_OLD), `${label}: record restored`);
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/Oxbay`), NEW), `${label}: the unconfirmed snapshot is kept`);
}

// ---------------------------------------------------------------- 4. rollback details
{   // rename: the deleted slot returns, the partial new slot (+ its record) goes, both copied first; other slots untouched
  const w = world('rename');
  w.put('SAVE/Keep', B('keep')); w.put('SAVE_META/Keep.time', META_OLD);
  w.put('SAVE/Oxbay 2', PART); w.put('SAVE_META/Oxbay 2.time', META_NEW);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay 2'), fresh: 1 }), cyc(tx1, 'Oxbay 2', 1));
  const r = await w.recover();
  assert.equal(r.status, 'rolled-back');
  assert(eq(w.get('SAVE/Oxbay'), OLD) && eq(w.get('SAVE_META/Oxbay.time'), META_OLD));
  assert(!w.has('SAVE/Oxbay 2') && !w.has('SAVE_META/Oxbay 2.time'));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/Oxbay 2`), PART));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.meta/Oxbay 2.time`), META_NEW));
  assert(eq(w.get('SAVE/Keep'), B('keep')) && eq(w.get('SAVE_META/Keep.time'), META_OLD));
  assert.deepEqual(w.list('SAVE'), ['Keep', 'Oxbay']);
}
{   // a legacy slot (no record before): rollback leaves no record, the stamp of the partial goes to quarantine
  const w = world('legacy');
  w.put('SAVE/Oxbay', PART); w.put('SAVE_META/Oxbay.time', META_NEW);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, null), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
  assert.equal((await w.recover()).status, 'rolled-back');
  assert(eq(w.get('SAVE/Oxbay'), OLD)); assert(!w.has('SAVE_META/Oxbay.time'));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.meta/Oxbay.time`), META_NEW));
}
{   // overwrite without a previous slot: only a partial new slot exists
  const w = world('fresh');
  w.put('SAVE/New', PART); w.put('SAVE_META/New.time', META_NEW);
  w.journal(jline('create', tx1, { target: hex('New'), fresh: 1 }), cyc(tx1, 'New', 1));
  assert.equal((await w.recover()).status, 'rolled-back');
  assert(!w.has('SAVE/New') && !w.has('SAVE_META/New.time')); assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/New`), PART));
  // a create that failed before anything was written is simply nothing
  const v = world('fresh-fail');
  v.journal(jline('create', tx1, { target: hex('New'), fresh: 1 }), jline('create-fail', tx1, { target: hex('New'), err: 28 }));
  const rv = await v.recover(); assert.equal(rv.status, 'clean'); assert.deepEqual(rv.txs.map(t => t.outcome), ['noop']);
}
{   // overwrite in place (open of an existing slot, no delete): the truncated slot gets its bytes back
  const w = world('trunc');
  w.put('SAVE/Oxbay', PART); w.put('SAVE_META/Oxbay.time', META_OLD);
  w.journal(w.arm(tx1, 'Oxbay', 'trunc', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 0 }), cyc(tx1, 'Oxbay', 1));
  assert.equal((await w.recover()).status, 'rolled-back');
  assert(eq(w.get('SAVE/Oxbay'), OLD) && eq(w.get('SAVE_META/Oxbay.time'), META_OLD));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/Oxbay`), PART));
  // the open itself failed: the slot was never touched, "restoring" changes nothing
  const v = world('trunc-fail');
  v.put('SAVE/Oxbay', OLD); v.put('SAVE_META/Oxbay.time', META_OLD);
  v.journal(v.arm(tx1, 'Oxbay', 'trunc', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 0 }), jline('create-fail', tx1, { target: hex('Oxbay'), err: 13 }));
  const before = v.snap();
  const rv = await v.recover(); assert.equal(rv.status, 'rolled-back'); assert(eq(v.get('SAVE/Oxbay'), OLD));
  assert(!v.list('SAVE_TX').includes('quarantine'), 'nothing to quarantine when nothing changed');
  void before;
}
{   // a delete that did not happen (abort): nothing to do, the arm is cancelled
  const w = world('abort');
  w.put('SAVE/Oxbay', OLD);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('abort', tx1, { slot: hex('Oxbay'), prior: priorName(tx1) }));
  const r = await w.recover(); assert.equal(r.status, 'clean'); assert(eq(w.get('SAVE/Oxbay'), OLD));
}

// ---------------------------------------------------------------- 5. refusal and conflicts, never a silent loss
{   // prior copy missing or corrupt: refuse, touch nothing, offer keep-current
  for (const damage of ['missing', 'corrupt']) {
    const w = world(`prior-${damage}`);
    w.put('SAVE/Oxbay', PART);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
    if (damage === 'missing') fs.rmSync(path.join(w.game, 'SAVE_TX', priorName(tx1)));
    else w.put(`SAVE_TX/${priorName(tx1)}`, B('tampered'));
    const before = w.snap();
    const r = await w.recover();
    assert.equal(r.status, 'refused'); assert.equal(r.txs[0].reason, damage === 'missing' ? 'prior-missing' : 'prior-corrupt');
    assert(sameSnapshot(before, w.snap()), `${damage}: a refusal changes nothing`);
    assert.equal((await w.recover()).status, 'refused', 'and keeps refusing until decided');
    const kept = await resolveSaveTxConflict({ root: opfsRoot(w.base), rootName: ROOT, locks: await heldLocks(), tx: tx1, choice: 'keep-current', now: () => NOW });
    assert.equal(kept.status, 'recovered'); assert(eq(w.get('SAVE/Oxbay'), PART));
    assert.equal((await w.recover()).status, 'clean');
    assert.rejects(() => resolveSaveTxConflict({ root: opfsRoot(w.base), rootName: ROOT, locks: new Locks(), tx: 'zz', choice: 'keep-current' }), /Некорректное решение/);
    assert.rejects(() => resolveSaveTxConflict({ root: opfsRoot(w.base), rootName: ROOT, locks: new Locks(), tx: tx1, choice: 'bogus' }), /Некорректное решение/);
  }
  // restore-prior on a refused transaction whose prior is gone stays refused (nothing to restore)
  const w = world('prior-gone-restore');
  w.put('SAVE/Oxbay', PART);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
  fs.rmSync(path.join(w.game, 'SAVE_TX', priorName(tx1)));
  const r = await resolveSaveTxConflict({ root: opfsRoot(w.base), rootName: ROOT, locks: await heldLocks(), tx: tx1, choice: 'restore-prior', now: () => NOW });
  assert.equal(r.status, 'refused'); assert(eq(w.get('SAVE/Oxbay'), PART));
}
{   // somebody else wrote the slot (not the transaction's target): left alone, copied to quarantine, prior kept
  const w = world('conflict');
  const theirs = B('bytes of an unjournaled writer');
  w.put('SAVE/Oxbay', theirs); w.put('SAVE/Oxbay 2', PART);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay 2'), fresh: 1 }), cyc(tx1, 'Oxbay 2', 1));
  const r = await w.recover();
  assert.equal(r.status, 'quarantined');
  assert(eq(w.get('SAVE/Oxbay'), theirs), 'the foreign bytes were not replaced');
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.current/Oxbay`), theirs));
  assert(w.has(`SAVE_TX/${priorName(tx1)}`));
  // the history pruning never removes the priors of a conflict
  for (let i = 10; i < 30; i++) w.journal(w.arm(txId(i), `X${i}`, 'delete', B(`bytes ${i}`), null), jline('settle', txId(i), {}));
  await w.recover({ explicitMinAgeMs: 0, keep: 2 });
  assert(w.has(`SAVE_TX/${priorName(tx1)}`), 'conflict prior is protected');
  const back = await resolveSaveTxConflict({ root: opfsRoot(w.base), rootName: ROOT, locks: await heldLocks(), tx: tx1, choice: 'restore-prior', now: () => NOW });
  assert.equal(back.status, 'rolled-back'); assert(eq(w.get('SAVE/Oxbay'), OLD)); assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/Oxbay`), theirs));
}
{   // the host recorded an arm but its record for the target was lost: a pre-existing target cannot be rolled back blindly
  const w = world('arm-missing');
  w.put('SAVE/Oxbay', PART);
  w.journal(jline('create', tx1, { target: hex('Oxbay'), fresh: 0 }), cyc(tx1, 'Oxbay', 1));
  const before = w.snap();
  const r = await w.recover();
  assert.equal(r.status, 'refused'); assert.equal(r.txs[0].reason, 'arm-missing'); assert(sameSnapshot(before, w.snap()));
}
{   // an unreadable journal version: refuse the whole recovery, data untouched
  const w = world('v2');
  w.put('SAVE/Oxbay', OLD);
  const body = 'v2 arm tx=00000000000000000001 ts=1';
  const crc = (await import('../web/save-export.mjs')).crc32(B(body)).toString(16).padStart(8, '0');
  w.journal(`${body} crc=${crc}\n`);
  const before = w.snap();
  const r = await w.recover(); assert.equal(r.status, 'refused'); assert.equal(r.reason, 'unsupported-journal'); assert(sameSnapshot(before, w.snap()));
}

// ---------------------------------------------------------------- 6. explicit delete versus interrupted overwrite
{
  for (const [label, opts, ts, extra, expected] of [
    ['fresh delete', {}, FRESH, '', 'rolled-back'],
    ['old delete', {}, OLDER, '', 'explicit-delete'],
    ['settled delete', {}, FRESH, jline('settle', tx1, {}), 'explicit-delete'],
    ['clock in the future', {}, ft(NOW + 24 * 3600 * 1000), '', 'rolled-back'],
    ['old delete but a create failed after it', {}, OLDER, jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }) + jline('create-fail', tx1, { target: hex('Oxbay'), err: 28 }), 'rolled-back'],
    ['old delete with a fail line', {}, OLDER, jline('fail', tx1, { reason: 'unprotected-create' }), 'rolled-back'],
    ['threshold override', { explicitMinAgeMs: 500 }, FRESH, '', 'explicit-delete'],
  ]) {
    const w = world('explicit');
    w.put('SAVE/Keep', B('k'));
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD, 1, ts), extra);
    const r = await w.recover(opts);
    assert.equal(r.txs[0].outcome, expected, label);
    if (expected === 'explicit-delete') { assert(!w.has('SAVE/Oxbay'), label); assert(w.has(`SAVE_TX/${priorName(tx1)}`), `${label}: copy kept`); }
    else { assert(eq(w.get('SAVE/Oxbay'), OLD) && eq(w.get('SAVE_META/Oxbay.time'), META_OLD), label); }
    assert(eq(w.get('SAVE/Keep'), B('k')));
  }
  // an orphan sidecar record of an explicitly deleted slot is cleaned up (copied first)
  const w = world('explicit-orphan');
  w.put('SAVE_META/Oxbay.time', META_OLD);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD, 1, OLDER));
  assert.equal((await w.recover()).txs[0].outcome, 'explicit-delete');
  assert(!w.has('SAVE_META/Oxbay.time')); assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.meta/Oxbay.time`), META_OLD));
}

// ---------------------------------------------------------------- 7. several transactions: newest first
{   // failed after failed: the very first prior wins, nothing is lost on the way
  const w = world('chain');
  const P1 = B('partial of tx1');
  w.put('SAVE/Oxbay', B('partial of tx2'));
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1),
    w.arm(tx2, 'Oxbay', 'trunc', P1, null), jline('create', tx2, { target: hex('Oxbay'), fresh: 0 }), cyc(tx2, 'Oxbay', 1));
  const r = await w.recover();
  assert.equal(r.status, 'rolled-back'); assert(eq(w.get('SAVE/Oxbay'), OLD)); assert(eq(w.get('SAVE_META/Oxbay.time'), META_OLD));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx2}.partial/Oxbay`), B('partial of tx2')));
  assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.partial/Oxbay`), P1));
}
{   // committed, then a later failed overwrite: the failed one returns the committed bytes, which then verify
  const w = world('commit-then-fail');
  w.put('SAVE/Oxbay', B('partial of tx2'));
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2),
    jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) }),
    w.arm(tx2, 'Oxbay', 'trunc', NEW, META_NEW), jline('create', tx2, { target: hex('Oxbay'), fresh: 0 }), cyc(tx2, 'Oxbay', 1));
  const r = await w.recover();
  assert.deepEqual(r.txs.map(t => t.outcome), ['accepted', 'rolled-back']);
  assert(eq(w.get('SAVE/Oxbay'), NEW)); assert(eq(w.get('SAVE_META/Oxbay.time'), META_NEW));
}
{   // two commits on one slot: the newer is verified, the older is superseded (not flagged for bytes it no longer has)
  const w = world('two-commits');
  const NEWER = B('the newer completed save');
  w.put('SAVE/Oxbay', NEWER);
  const commit = (tx, bytes, armed) => [armed, jline('create', tx, { target: hex('Oxbay'), fresh: armed ? 1 : 0 }), cyc(tx, 'Oxbay', 1), cyc(tx, 'Oxbay', 2),
    jline('commit', tx, { target: hex('Oxbay'), size: bytes.length, sha: sha(bytes) })];
  w.journal(...commit(tx1, NEW, w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD)), ...commit(tx2, NEWER, w.arm(tx2, 'Oxbay', 'trunc', NEW, META_NEW)));
  const r = await w.recover();
  assert.deepEqual(r.txs.map(t => t.outcome), ['superseded', 'accepted']); assert.equal(r.status, 'recovered'); assert(eq(w.get('SAVE/Oxbay'), NEWER));
}
{   // a refused newer transaction freezes its slots against older ones
  const w = world('frozen');
  w.put('SAVE/Oxbay', PART);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1),
    w.arm(tx2, 'Oxbay', 'trunc', PART, null), jline('create', tx2, { target: hex('Oxbay'), fresh: 0 }), cyc(tx2, 'Oxbay', 1));
  fs.rmSync(path.join(w.game, 'SAVE_TX', priorName(tx2)));
  const before = w.snap();
  const r = await w.recover();
  assert.equal(r.status, 'refused'); assert.deepEqual(r.txs.map(t => [t.outcome, t.reason]), [['refused', 'blocked'], ['refused', 'prior-missing']]);
  assert(sameSnapshot(before, w.snap()));
}

// ---------------------------------------------------------------- 8. journal damage, housekeeping
{   // a torn tail (the normal crash signature) is dropped with a copy; a damaged middle line is quarantined and reported
  const w = world('damage');
  w.put('SAVE/Oxbay', NEW);
  const mk = (x) => [x.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1), cyc(tx1, 'Oxbay', 2),
    jline('commit', tx1, { target: hex('Oxbay'), size: NEW.length, sha: sha(NEW) })];
  w.journal(...mk(w), 'v1 cycle tx=deadbeefdead');
  const r = await w.recover();
  assert.equal(r.status, 'recovered'); assert.equal(r.tornTail, true);
  assert(!new TextDecoder().decode(w.get('SAVE_TX/journal.log')).includes('tx=deadbeefdead'), 'the torn tail is gone from the journal');
  const q = w.list('SAVE_TX/quarantine').find(n => n.endsWith('.damaged'));
  assert(q && new TextDecoder().decode(w.get(`SAVE_TX/quarantine/${q}/journal.log`)).includes('tx=deadbeefdead'), 'and kept in quarantine');
  assert.equal((await w.recover()).status, 'clean'); assert.equal((await w.recover()).warnings.length, 0);
  const v = world('damage-mid');
  v.put('SAVE/Oxbay', NEW);
  const okv = mk(v);
  v.journal(okv[0], okv[1].replace('fresh=1', 'fresh=0'), okv[2], okv[3], okv[4]);   // the create line is damaged (crc no longer matches)
  const rv = await v.recover();
  assert.equal(rv.status, 'quarantined'); assert(rv.warnings.length >= 1);
  assert.equal((await v.recover()).status, 'clean');
}
{   // history pruning keeps the newest priors, reports orphans, and compaction keeps only the journal of what is left
  const w = world('history');
  const total = SAVE_TX_HISTORY_KEEP + 3;
  for (let i = 1; i <= total; i++) w.journal(w.arm(txId(i), `S${i}`, 'delete', B(`slot ${i} bytes`), null, 1, OLDER), jline('settle', txId(i), {}, OLDER));
  w.put('SAVE_TX/prior-ffffffffffffffffffff-1', B('unreferenced'));
  const r = await w.recover();
  assert.equal(r.status, 'recovered');
  const priors = w.list('SAVE_TX').filter(n => n.startsWith('prior-'));
  assert.equal(priors.length, SAVE_TX_HISTORY_KEEP + 1, 'newest priors + the orphan');
  assert(priors.includes(priorName(txId(total))) && !priors.includes(priorName(txId(1))));
  assert.deepEqual(r.orphans, ['prior-ffffffffffffffffffff-1']); assert(w.has('SAVE_TX/prior-ffffffffffffffffffff-1'), 'orphans are never auto-deleted');
  // compaction
  const c = world('compact');
  const big = [];
  for (let i = 1; i <= 800; i++) big.push(jline('settle', txId(i), {}, OLDER).replace(' crc=', ' pad=' + 'x'.repeat(300) + ' crc='));
  // the padded lines have wrong crcs: use real lines with long hex names instead
  big.length = 0;
  const longName = 'n'.repeat(200);
  for (let i = 1; i <= 400; i++) big.push(c.arm(txId(i), `${longName}${i}`, 'delete', B(`b${i}`), null, 1, OLDER), jline('settle', txId(i), {}, OLDER));
  c.journal(...big);
  assert(c.get('SAVE_TX/journal.log').length > SAVE_TX_COMPACT_BYTES);
  const cr = await c.recover();
  assert.equal(cr.compacted, true);
  assert(c.get('SAVE_TX/journal.log').length < SAVE_TX_COMPACT_BYTES / 4);
  assert.equal(c.list('SAVE_TX').filter(n => n.startsWith('prior-')).length, SAVE_TX_HISTORY_KEEP);
  assert.equal((await c.recover()).status, 'clean');
}

// ---------------------------------------------------------------- 9. ownership, concurrency, storage errors
{
  const w = world('own');
  w.put('SAVE/Oxbay', PART);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
  const before = w.snap();
  // the core entry point without any held lock refuses (cannot guarantee sole ownership), also without query()
  for (const locks of [new Locks(), {}, { query: async () => { throw new Error('boom'); } }, undefined]) {
    const r = await recoverSaveTxLocked({ root: opfsRoot(w.base), rootName: ROOT, locks, now: () => NOW });
    assert.equal(r.status, 'refused'); assert.equal(r.reason, 'no-lock-ownership');
  }
  assert(sameSnapshot(before, w.snap()));
  // busy: another page owns the lock, recovery does not wait and changes nothing
  const locks = new Locks();
  const results = [];
  await holding(locks, ROOT, async () => { results.push(await recoverSaveTx({ root: opfsRoot(w.base), rootName: ROOT, locks, now: () => NOW })); });
  assert.equal(results[0].status, 'refused'); assert.equal(results[0].reason, 'busy'); assert(sameSnapshot(before, w.snap()));
  // two tabs racing: exactly one recovers, the other is told it is busy; the outcome is a single clean rollback
  const [a, b] = await Promise.all([w.recover({ locks }), w.recover({ locks })]);
  assert.deepEqual([a.status, b.status].sort(), ['refused', 'rolled-back']);
  assert(eq(w.get('SAVE/Oxbay'), OLD));
  // the real page flow: the lock is taken by runExclusiveForPageLifetime, recovery runs inside it, then the game starts
  const w2 = world('flow');
  w2.put('SAVE/Oxbay', PART);
  w2.journal(w2.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
  const pageLocks = new Locks(), order = [];
  await runExclusiveForPageLifetime({ locks: pageLocks, gameRoot: ROOT,
    beforeStart: async () => { const r = await recoverSaveTxLocked({ root: opfsRoot(w2.base), rootName: ROOT, locks: pageLocks, now: () => NOW }); order.push(r.status); },
    startRuntime: async () => { order.push('start'); } });
  assert.deepEqual(order, ['rolled-back', 'start']); assert(eq(w2.get('SAVE/Oxbay'), OLD));
  // a refusal before the game: locks released again, the runtime never starts
  const locks3 = new Locks(); let started = 0;
  await assert.rejects(() => runExclusiveForPageLifetime({ locks: locks3, gameRoot: ROOT, beforeStart: async () => { throw Object.assign(new Error('needs a decision'), { saveTxRefused: true }); },
    startRuntime: async () => { started++; } }), /needs a decision/);
  assert.equal(started, 0); assert.equal(locks3.held.size, 0);
  // without beforeStart the flow is exactly the old one
  const locks4 = new Locks();
  assert.equal(await runExclusiveForPageLifetime({ locks: locks4, gameRoot: ROOT, startRuntime: async () => 7 }), 7);
  await assert.rejects(() => runExclusiveForPageLifetime({ locks: new Locks(), gameRoot: ROOT, beforeStart: 5, startRuntime: async () => {} }), /Некорректные параметры/);
}
{   // a storage error (quota, I/O) at any single mutation of recovery: status refused/io-error, the rerun completes it
  const make = () => {
    const w = world('io');
    w.put('SAVE/Keep', B('keep')); w.put('SAVE/Oxbay 2', PART); w.put('SAVE_META/Oxbay 2.time', META_NEW);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay 2'), fresh: 1 }), cyc(tx1, 'Oxbay 2', 1));
    return w;
  };
  const probe = makeCtx(); await make().recover({ ctx: probe });
  assert(probe.mutations >= 6);
  for (let at = 0; at < probe.mutations; at++) {
    const w = make(), ctx = makeCtx(); ctx.failAt = at;
    const first = await w.recover({ ctx });
    assert.equal(first.status, 'refused', `failure at ${at}`); assert.equal(first.reason, 'io-error');
    const before = new Set([...walk(w.base)].filter(([k, v]) => v.length && !k.endsWith('journal.log')).map(([, v]) => sha(v)));
    const second = await w.recover();
    assert.notEqual(second.status, 'refused', `rerun after failure ${at}: ${JSON.stringify(second)}`);
    assert(eq(w.get('SAVE/Oxbay'), OLD) && eq(w.get('SAVE_META/Oxbay.time'), META_OLD) && !w.has('SAVE/Oxbay 2'));
    const after = new Set([...walk(w.base)].filter(([k, v]) => v.length && !k.endsWith('journal.log')).map(([, v]) => sha(v)));
    for (const s of before) assert(after.has(s), `failure at ${at}: content lost`);
    assert.equal((await w.recover()).status, 'clean');
  }
}

// ---------------------------------------------------------------- 10. nothing to do / compatibility
{
  const w = world('empty');
  fs.rmSync(path.join(w.game, 'SAVE_TX'), { recursive: true });
  w.put('SAVE/Oxbay', OLD);
  const before = w.snap();
  const r = await w.recover(); assert.equal(r.status, 'clean'); assert(sameSnapshot(before, w.snap()), 'no SAVE_TX is created by a recovery of a game that never used the flag');
  const v = world('no-game'); fs.rmSync(v.game, { recursive: true });
  const rv = await v.recover(); assert.equal(rv.status, 'clean'); assert.deepEqual(fs.readdirSync(v.base), []);
  const x = world('empty-journal'); x.put('SAVE_TX/journal.log', '');
  assert.equal((await x.recover()).status, 'clean');
}
{   // names that differ only in case: the OPFS entry keeps its case, no twin is created; real twins are refused
  const w = world('case');
  w.put('SAVE/oxbay', PART);
  w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
  assert.equal((await w.recover()).status, 'rolled-back');
  assert.deepEqual(w.list('SAVE'), ['oxbay']); assert(eq(w.get('SAVE/oxbay'), OLD));
  // real twins (OPFS is case-sensitive; temp directories here may not be, so this one runs on an in-memory OPFS)
  const mem = memRoot();
  mem.put(`${ROOT}/SAVE/oxbay`, PART); mem.put(`${ROOT}/SAVE/OXBAY`, PART);
  const armTx = jline('arm', tx1, { kind: 'delete', slot: hex('Oxbay'), prior: priorName(tx1), size: OLD.length, sha: sha(OLD), meta: '-' });
  mem.put(`${ROOT}/SAVE_TX/${priorName(tx1)}`, OLD);
  mem.put(`${ROOT}/SAVE_TX/journal.log`, B(armTx + jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }) + cyc(tx1, 'Oxbay', 1)));
  const rv = await recoverSaveTx({ root: mem, rootName: ROOT, locks: new Locks(), now: () => NOW });
  assert.equal(rv.status, 'refused'); assert.equal(rv.reason, 'io-error'); assert.match(rv.error, /регистр/);
  assert(eq(mem.read(`${ROOT}/SAVE/oxbay`), PART) && eq(mem.read(`${ROOT}/SAVE/OXBAY`), PART));
}
{   // SAVE_TX is player data: never an installable game asset (case-insensitive, like SAVE and SAVE_META)
  const { selectGameAssets } = await import('../web/save-protection.mjs');
  const kept = selectGameAssets([{ path: 'SAVE_TX/journal.log' }, { path: 'save_tx/prior-x' }, { path: 'SAVE/slot' }, { path: 'SAVE_META/a.time' }, { path: 'SAVE_META/a.lang' }, { path: 'PROGRAM/x.c' }, { path: 'save_txt/a' }], f => f.path);
  assert.deepEqual(kept.map(f => f.path), ['PROGRAM/x.c', 'save_txt/a']);
}
{   // the switch
  assert.equal(saveTxRequested(new URLSearchParams('saveTx=1')), true);
  assert.equal(saveTxRequested(new URLSearchParams('')), false);
  assert.equal(saveTxRequested(new URLSearchParams('saveTx=0')), false);
  assert.equal(saveTxRequested(new URLSearchParams('saveTx=true')), false);
  assert.equal(saveTxRequested(new URLSearchParams('saveTx=1'), { you: 0 }), false, 'never online');
  assert.equal(saveTxRequested(undefined), false);
}

// ---------------------------------------------------------------- E5: the language label SAVE_META/<slot>.lang
{
  const EN = B('en'), RU = B('ru');
  // parsing: the optional lang field takes exactly 656e / 7275; anything else makes the line damaged (skipped with a warning)
  const arm = (extra) => jline('arm', tx1, { kind: 'delete', slot: hex('A'), prior: priorName(tx1), size: 3, sha: sha(B('abc')), meta: '-', ...extra });
  let p = parseJournal(arm({ lang: '656e' }));
  assert.equal(p.events.length, 1); assert.equal(p.events[0].lang, '656e');
  assert.deepEqual(buildTransactions(p.events)[0].arms[0].lang, EN);
  assert.deepEqual(buildTransactions(parseJournal(arm({ lang: '7275' })).events)[0].arms[0].lang, RU);
  assert.equal(buildTransactions(parseJournal(arm({})).events)[0].arms[0].lang, null, 'no field = no label (every journal of the Russian mode)');
  for (const bad of ['', '656', '656e00', '6566', 'EN', '656E', '7a7a', '-', '../x']) {
    p = parseJournal(arm({ lang: bad }));
    assert.equal(p.events.length, 0, `lang=${bad}`); assert.equal(p.warnings.length, 1, `lang=${bad}`);
  }
  // rollback returns the label with the slot and its time record; a label that the failed attempt left on the partial slot goes (copied first)
  {
    const w = world('lang-rename');
    w.put('SAVE/Oxbay 2', PART); w.put('SAVE_META/Oxbay 2.time', META_NEW); w.put('SAVE_META/Oxbay 2.lang', EN);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD, 1, FRESH, 'ru'), jline('create', tx1, { target: hex('Oxbay 2'), fresh: 1 }), cyc(tx1, 'Oxbay 2', 1));
    assert.equal((await w.recover()).status, 'rolled-back');
    assert(eq(w.get('SAVE/Oxbay'), OLD) && eq(w.get('SAVE_META/Oxbay.time'), META_OLD) && eq(w.get('SAVE_META/Oxbay.lang'), RU));
    assert(!w.has('SAVE/Oxbay 2') && !w.has('SAVE_META/Oxbay 2.time') && !w.has('SAVE_META/Oxbay 2.lang'));
    assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.lang/Oxbay 2.lang`), EN), 'the partial slot\'s label is kept in quarantine');
    assert.equal((await w.recover()).status, 'clean');
  }
  {   // the prior had a label, the attempt replaced it: the old value is back, the new one in quarantine
    const w = world('lang-replaced');
    w.put('SAVE/Oxbay', PART); w.put('SAVE_META/Oxbay.time', META_NEW); w.put('SAVE_META/Oxbay.lang', EN);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD, 1, FRESH, 'ru'), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
    assert.equal((await w.recover()).status, 'rolled-back');
    assert(eq(w.get('SAVE/Oxbay'), OLD) && eq(w.get('SAVE_META/Oxbay.lang'), RU));
    assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.lang/Oxbay.lang`), EN));
  }
  {   // the prior had NO label (Russian mode, or a legacy slot): the arm has no lang field, rollback leaves no label
    const w = world('lang-none');
    w.put('SAVE/Oxbay', PART); w.put('SAVE_META/Oxbay.time', META_NEW); w.put('SAVE_META/Oxbay.lang', EN);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
    assert.equal((await w.recover()).status, 'rolled-back');
    assert(eq(w.get('SAVE/Oxbay'), OLD) && !w.has('SAVE_META/Oxbay.lang'));
    assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.lang/Oxbay.lang`), EN));
  }
  {   // a label already equal to the prior's: nothing is rewritten or quarantined; a rerun is clean
    const w = world('lang-same');
    w.put('SAVE/Oxbay', OLD); w.put('SAVE_META/Oxbay.time', META_OLD); w.put('SAVE_META/Oxbay.lang', EN);
    w.journal(w.arm(tx1, 'Oxbay', 'trunc', OLD, META_OLD, 1, FRESH, 'en'), jline('create', tx1, { target: hex('Oxbay'), fresh: 0 }), jline('fail', tx1, { reason: 'io-errors' }));
    assert.equal((await w.recover()).status, 'rolled-back');
    assert(eq(w.get('SAVE_META/Oxbay.lang'), EN)); assert(!w.has(`SAVE_TX/quarantine/${tx1}.lang/Oxbay.lang`));
    assert.equal((await w.recover()).status, 'clean');
  }
  {   // an explicit delete cut between the slot's unlink and its records' unlink leaves orphans: both records are dropped (copied first)
    const w = world('lang-orphan');
    w.put('SAVE_META/Oxbay.time', META_OLD); w.put('SAVE_META/Oxbay.lang', EN);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, META_OLD, 1, OLDER, 'en'), jline('settle', tx1, {}, OLDER));
    const r = await w.recover();
    assert.equal(r.txs[0].outcome, 'explicit-delete');
    assert(!w.has('SAVE_META/Oxbay.time') && !w.has('SAVE_META/Oxbay.lang'));
    assert(eq(w.get(`SAVE_TX/quarantine/${tx1}.lang/Oxbay.lang`), EN));
  }
  {   // case: the label is found under another letter case of its name (as the time record is)
    const w = world('lang-case');
    w.put('SAVE/Oxbay', PART); w.put('SAVE_META/oxbay.lang', EN);
    w.journal(w.arm(tx1, 'Oxbay', 'delete', OLD, null), jline('create', tx1, { target: hex('Oxbay'), fresh: 1 }), cyc(tx1, 'Oxbay', 1));
    assert.equal((await w.recover()).status, 'rolled-back');
    assert(!w.has('SAVE_META/oxbay.lang') && !w.has('SAVE_META/Oxbay.lang'));
  }
}

fs.rmSync(BASE, { recursive: true, force: true });
console.log('save-tx.mjs (journal parsing, claim re-validation, rollback, quarantine, refusal/resolution, explicit delete, ' +
  'chains, damage, history, ownership, storage errors, compatibility): PASS');
