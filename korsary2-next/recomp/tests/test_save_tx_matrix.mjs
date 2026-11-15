// SAVE_TX end to end, synthetically: the REAL native host handlers (test_save_tx.c: kernel32.c compiled with the
// syscall shim) are killed before every mutating syscall of an overwrite flow (and in the middle of every write),
// and the REAL page recovery (web/save-tx.mjs) recovers the left-over directory. Invariants after recovery:
//   * the slot is the previous completed version OR the new fully written one - never an intermediate snapshot;
//   * the SAVE_META record is consistent with the bytes (restored with them, or the new stamp);
//   * nothing is lost: every file content present at the moment of the crash still exists somewhere
//     (slot, SAVE_META, SAVE_TX prior copy, quarantine);
//   * recovery is idempotent, also when recovery itself is killed at any of its own mutations.
// It is NOT the game: no engine, no browser, no OPFS, the "crash" is _exit() (the OS keeps what was written).
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { spawnSync } from 'node:child_process';
import { recoverSaveTx } from '../web/save-tx.mjs';
import { opfsRoot, makeCtx, Locks, snapshot, sameSnapshot, tmpRoot, walk, sha } from './save_tx_fixture.mjs';

const BIN = process.env.SAVE_TX_BIN;
if (!BIN) { console.error('SAVE_TX_BIN is not set (use run_save_tx.sh matrix)'); process.exit(2); }
const here = path.dirname(fileURLToPath(import.meta.url));
const BASE = process.env.SAVE_TX_TMP ?? path.join(here, '..', 'web_toolchain', 'tmp', 'save-tx-matrix');
const ROOT_NAME = 'korsary2-game';
const stride = Number(process.env.SAVE_TX_STRIDE ?? 1);

const run = (args) => spawnSync(BIN, args, { encoding: 'utf8' });
function view(root) {   // SAVE/* and SAVE_META/* contents
  const out = new Map();
  for (const [k, v] of walk(path.join(root, ROOT_NAME))) if (k.startsWith('SAVE/') || k.startsWith('SAVE_META/')) out.set(k, v);
  return out;
}
const names = (v, dir) => [...v.keys()].filter(k => k.startsWith(`${dir}/`)).sort();
function sameFiles(a, b, dir, { metaLooseFor = [] } = {}) {   // contents equal; listed meta records only length-checked
  const an = names(a, dir), bn = names(b, dir);
  if (an.join('|') !== bn.join('|')) return false;
  return an.every(k => metaLooseFor.includes(k) ? a.get(k).length === 8 : Buffer.compare(a.get(k), b.get(k)) === 0);
}
function seeded(sc) {
  const root = tmpRoot(`${sc}-`, BASE);
  const game = path.join(root, ROOT_NAME);
  fs.mkdirSync(game);
  assert.equal(run(['--seed', game, sc]).status, 0);
  return { root, game };
}
function classify(sc, now, oldV, refV) {
  const newSlot = sc === 'rename' ? 'Oxbay 2' : sc === 'fresh' ? 'Fresh' : 'Oxbay';
  const oldSlots = names(oldV, 'SAVE');
  if (sameFiles(now, oldV, 'SAVE') && sameFiles(now, oldV, 'SAVE_META')) return 'old';
  if (sc !== 'delete' && sameFiles(now, refV, 'SAVE') &&
      sameFiles(now, refV, 'SAVE_META', { metaLooseFor: [`SAVE_META/${newSlot}.time`] })) return 'new';
  if (sc === 'delete') {
    const gone = (v) => new Map([...v].filter(([k]) => !k.startsWith('SAVE/Oxbay') && !k.startsWith('SAVE_META/Oxbay')));
    if (sameFiles(now, gone(oldV), 'SAVE') && sameFiles(now, gone(oldV), 'SAVE_META')) return 'deleted';
  }
  return `other(${names(now, 'SAVE').join(',')}|${names(now, 'SAVE_META').join(',')}; was ${oldSlots.join(',')})`;
}
// empty files (a just-created entry) carry no data; the journal itself is bookkeeping
const treeShas = (root) => new Set([...walk(path.join(root, ROOT_NAME))].filter(([k, v]) => !k.endsWith('journal.log') && v.length).map(([, v]) => sha(v)));
function assertNoLoss(beforeShas, root, label) {
  const after = treeShas(root);
  for (const s of beforeShas) assert(after.has(s), `${label}: content ${s.slice(0, 12)} was lost`);
}
async function recover(root, opts = {}) {
  const ctx = opts.ctx ?? makeCtx();
  const result = await recoverSaveTx({ root: opfsRoot(root, ctx), rootName: ROOT_NAME, locks: new Locks(), ...opts.recover });
  return { result, ctx };
}

const stats = { runs: 0, old: 0, new: 0, deleted: 0, recoveryCrashes: 0, accepted: 0, rolledBack: 0 };
async function checkPoint(sc, label, args, { oldV, refV, allow, recoverOpts = {}, recoveryCrashes = false }) {
  const { root, game } = seeded(sc);
  const killed = run(['--run', game, sc, ...args]);
  assert([0, 77].includes(killed.status), `${label}: host exited ${killed.status}\n${killed.stderr}`);
  const before = treeShas(root);
  const { result } = await recover(root, { recover: recoverOpts });
  assert.notEqual(result.status, 'refused', `${label}: recovery refused: ${JSON.stringify(result)}`);
  const state = classify(sc, view(root), oldV, refV);
  assert(allow.includes(state), `${label}: final state ${state} (allowed ${allow}); result ${JSON.stringify(result.txs)}`);
  assertNoLoss(before, root, label);
  stats.runs++; stats[state] = (stats[state] ?? 0) + 1;
  if (result.txs.some(t => t.outcome === 'accepted')) stats.accepted++;
  if (result.txs.some(t => t.outcome === 'rolled-back')) stats.rolledBack++;
  // idempotency: a second recovery changes nothing and reports clean
  const settled = snapshot(root);
  const again = (await recover(root, { recover: recoverOpts })).result;
  assert.equal(again.status, 'clean', `${label}: second recovery was ${again.status}`);
  assert(sameSnapshot(settled, snapshot(root)), `${label}: second recovery changed the tree`);
  // a recovery that is itself killed at every one of its own mutations heals on the next run
  if (recoveryCrashes) {
    const probe = makeCtx();
    // rebuild the crashed state by re-running the host with the same kill point
    const rebuild = () => {
      const s = seeded(sc);
      assert([0, 77].includes(run(['--run', s.game, sc, ...args]).status));
      return s;
    };
    const m = rebuild();
    await recover(m.root, { ctx: probe, recover: recoverOpts });
    fs.rmSync(m.root, { recursive: true, force: true });
    for (let at = 0; at < probe.mutations; at++) {
      const t = rebuild();
      const beforeT = treeShas(t.root);   // the host stamps wall-clock times: every rebuild has its own bytes
      const cctx = makeCtx(); cctx.crashAt = at;
      const first = (await recover(t.root, { ctx: cctx, recover: recoverOpts })).result;
      assert(first.status === 'refused' || at >= probe.mutations, `${label}: crash ${at} not surfaced`);
      stats.recoveryCrashes++;
      const second = (await recover(t.root, { recover: recoverOpts })).result;
      assert.notEqual(second.status, 'refused', `${label}: rerun after recovery crash ${at}: ${JSON.stringify(second)}`);
      const st = classify(sc, view(t.root), oldV, refV);
      assert(allow.includes(st), `${label}: after recovery crash ${at} the state is ${st}`);
      assertNoLoss(beforeT, t.root, `${label} (recovery crash ${at})`);
      const third = (await recover(t.root, { recover: recoverOpts })).result;
      assert.equal(third.status, 'clean');
      fs.rmSync(t.root, { recursive: true, force: true });
    }
  }
  fs.rmSync(root, { recursive: true, force: true });
}

const scenarios = [
  { sc: 'same', allow: ['old', 'new'] },
  { sc: 'rename', allow: ['old', 'new'] },
  { sc: 'legacy', allow: ['old', 'new'] },
  { sc: 'trunc', allow: ['old', 'new'] },
  { sc: 'fresh', allow: ['old', 'new'] },        // "old" here is: the slot does not exist yet
  { sc: 'delete', allow: ['old'] },              // a fresh lone delete is rolled back (the lossless direction)
];
fs.rmSync(BASE, { recursive: true, force: true });
for (const { sc, allow } of scenarios) {
  const ref = seeded(sc);
  const oldV = view(ref.root);
  const reference = run(['--run', ref.game, sc, 'kill=-2']);
  assert.equal(reference.status, 0);
  const [, opsText, , okText] = reference.stdout.trim().split(' ');
  assert.equal(okText, '1', `${sc}: reference run failed`);
  const ops = Number(opsText);
  assert(ops > 5, `${sc}: suspiciously few mutating syscalls (${ops})`);
  const refV = view(ref.root);
  fs.rmSync(ref.root, { recursive: true, force: true });
  const deepCrash = sc === 'rename' || sc === 'same' || sc === 'fresh';
  for (let k = 0; k <= ops; k += stride) {
    for (const torn of [false, true]) {
      const args = [`kill=${k}`, ...(torn ? ['torn=1'] : [])];
      await checkPoint(sc, `${sc} kill=${k}${torn ? ' torn' : ''}`, args, { oldV, refV, allow, recoveryCrashes: deepCrash && !torn && k % 3 === 0 });
    }
  }
  if (sc === 'delete') {   // the same kill matrix with an old-enough lone delete: honored as an explicit delete
    for (let k = 0; k <= ops; k += stride)
      await checkPoint(sc, `delete(explicit) kill=${k}`, [`kill=${k}`], { oldV, refV, allow: ['old', 'deleted'], recoverOpts: { explicitMinAgeMs: 0, now: () => Date.now() + 10 } });
  }
  console.log(`${sc}: ${ops} mutating syscalls swept (plain + torn)`);
}

// ---- handled I/O failures of the engine's own writes and of the host's helper files (not crashes)
for (const sc of ['same', 'rename']) {
  const ref = seeded(sc);
  const oldV = view(ref.root);
  assert.equal(run(['--run', ref.game, sc, 'kill=-2']).status, 0);
  const refV = view(ref.root);
  fs.rmSync(ref.root, { recursive: true, force: true });
  const SLOT = 1, JOURNAL = 3, PRIOR = 4;
  for (const kind of [1, 2, 3]) for (let nth = 1; nth <= 14; nth++)
    await checkPoint(sc, `${sc} slot-write#${nth} kind${kind}`, [`inject=${SLOT}:${nth}:${kind}`], { oldV, refV, allow: ['old', 'new'] });
  // the quota/IO failure of the prior copy degrades to the flag-off behavior: the new version completes, as before
  await checkPoint(sc, `${sc} prior-copy-fails`, [`inject=${PRIOR}:1:1`], { oldV, refV, allow: ['new'] });
  // a failing journal can only be checked for "nothing lost, nothing misclaimed" (its own gap is the documented one)
  for (let nth = 1; nth <= 9; nth++) {
    const { root, game } = seeded(sc);
    assert.equal(run(['--run', game, sc, `inject=${JOURNAL}:${nth}:1`]).status, 0);
    const before = treeShas(root);
    const { result } = await recover(root);
    assert.notEqual(result.status, 'refused', `${sc} journal-fail#${nth}: ${JSON.stringify(result)}`);
    assertNoLoss(before, root, `${sc} journal-fail#${nth}`);
    assert.equal((await recover(root)).result.status, 'clean');
    fs.rmSync(root, { recursive: true, force: true });
  }
}
fs.rmSync(BASE, { recursive: true, force: true });
console.log(`save tx kill matrix: ${stats.runs} crash points recovered (old=${stats.old ?? 0} new=${stats.new ?? 0} deleted=${stats.deleted ?? 0}; ` +
  `accepted=${stats.accepted} rolled-back=${stats.rolledBack}; ${stats.recoveryCrashes} recovery-crash reruns): PASS`);
