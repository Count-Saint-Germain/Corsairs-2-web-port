/* Ф4.2: page half of the logical save transaction (SAVE_TX), default OFF.
 *
 * With PORT_SAVE_TX set for the guest, the host (recomp/host/kernel32.c, the
 * "logical save transaction" section) journals every overwrite of a SAVE slot
 * in <game root>/SAVE_TX/journal.log and keeps the previous slot bytes in
 * SAVE_TX/prior-* BEFORE any destructive step. The game keeps writing the real
 * slot files exactly as before. This module is what makes use of that journal:
 * at the next start, under the page-lifetime SAVE lock and before the runtime
 * starts, it
 *   - accepts a transaction the host marked committed ONLY when the bytes on
 *     disk still match the journaled size and SHA-256, and re-checks the other
 *     completion conditions itself (two clean write cycles of the same target);
 *   - rolls an interrupted or failed transaction back to the previous
 *     completed version: slot bytes AND the SAVE_META time record;
 *   - quarantines whatever it cannot accept (copy first, verified by re-read,
 *     then — only then — anything is removed or replaced);
 *   - refuses (leaves everything untouched) when a safe decision is missing,
 *     and offers an explicit, loss-free resolution.
 * Every outcome is reported as data (never only a log line): the result of
 * recoverSaveTx* carries status 'clean' | 'recovered' | 'rolled-back' |
 * 'quarantined' | 'refused' and per-transaction detail for the UI.
 *
 * Journal format v1 (written by the host). One event per line, every line
 * ends with " crc=<8 hex>", the CRC-32 (ZIP polynomial, crc32() of
 * save-export.mjs) of the line text before that suffix. Tokens never contain
 * spaces; slot names are hex-encoded UTF-8. Events (all carry tx=<20 hex> and
 * ts=<FILETIME 100 ns>):
 *   arm        kind=delete|trunc slot=<hex> prior=<prior-TX-N> size sha meta [lang]
 *              a slot about to be deleted / opened for write was preserved;
 *              meta is its 8-byte SAVE_META record as 16 hex, or "-";
 *              lang (E5, optional) is its 2-byte SAVE_META language label as 4 hex
 *              (656e "en", 7275 "ru"); the field is absent when the slot had none
 *   create     target=<hex> fresh=0|1     a write open of the target began
 *   create-fail target=<hex> err=<errno>  that open failed
 *   cycle      target n writes errors bytes   one write cycle (open..close)
 *   fail       reason=<token>             the host gave up on the transaction
 *   anomaly    what=<token>               the two-stage model did not hold
 *   commit     target size sha            both cycles clean, fixture re-read
 *   abort      slot prior                 the protected delete did not happen
 *   settle     a delete stood alone (no create within the bind window)
 *   resolved   outcome=<token>            (page only) the recovery decision
 * A final line without its newline is a torn record and is ignored; an
 * earlier line with a bad checksum is skipped with a warning. A line that
 * announces another journal version makes the whole recovery refuse.
 *
 * What this does NOT prove: that the game state serialized into the committed
 * bytes is semantically valid (the engine gives no such signal); that nothing
 * else wrote the slots (older pages and non-cooperating tools do not take the
 * SAVE lock); durability across a power loss (fsync of OPFS files is the
 * backend's, directory entries have none). */
import { crc32, key, validateName, saveLockName } from './save-export.mjs';
import { sha256Init, sha256Update, sha256Hex } from './save-protection.mjs';

export const SAVE_TX_DIR = 'SAVE_TX';
export const SAVE_TX_JOURNAL = 'journal.log';
export const SAVE_TX_QUARANTINE = 'quarantine';
/** A lone delete older than this is an explicit user delete (younger ones are rolled back: the lossless direction). */
export const EXPLICIT_DELETE_MIN_AGE_MS = 5 * 60 * 1000;
/** Priors of resolved transactions kept for manual recovery; older ones are pruned (the host keeps the same number). */
export const SAVE_TX_HISTORY_KEEP = 4;
/** Resolved journals above this size are compacted to the transactions that still own files. */
export const SAVE_TX_COMPACT_BYTES = 256 * 1024;

const FILETIME_UNIX_MS = 11644473600000n;
const TX_RE = /^[0-9a-f]{20}$/;
const PRIOR_RE = /^prior-[0-9a-f]{20}-[0-9a-f]{1,4}$/;
const SHA_RE = /^[0-9a-f]{64}$/;
const META_RE = /^(?:[0-9a-f]{16}|-)$/;
const LANG_RE = /^(?:656e|7275)$/;
const NUM_RE = /^[0-9]{1,16}$/;
const TS_RE = /^[0-9]{1,20}$/;
const TOKEN_RE = /^[a-z0-9-]{1,40}$/;
const encoder = new TextEncoder();
const decoder = new TextDecoder('utf-8');

const fail = (message) => { throw new Error(message); };

/** The one switch of the page: ?saveTx=1, solo play only (online runs are deterministic lockstep with
 * throwaway saves, and the host journal must not touch them). Anything else, including a missing
 * parameter, is OFF. */
export function saveTxRequested(params, session = null) {
  return !session && typeof params?.get === 'function' && params.get('saveTx') === '1';
}
const notFound = (e) => e?.name === 'NotFoundError';

/* ------------------------------------------------------------------ parsing */

function hexToName(hex) {
  if (typeof hex !== 'string' || !hex || hex.length % 2 || !/^[0-9a-f]+$/.test(hex)) return null;
  const bytes = new Uint8Array(hex.length / 2);
  for (let i = 0; i < bytes.length; i++) bytes[i] = parseInt(hex.slice(2 * i, 2 * i + 2), 16);
  try {
    const name = new TextDecoder('utf-8', { fatal: true }).decode(bytes);
    return validateName(name);
  } catch { return null; }
}
const hexToMeta = (hex) => {
  if (hex === '-') return null;
  const b = new Uint8Array(8);
  for (let i = 0; i < 8; i++) b[i] = parseInt(hex.slice(2 * i, 2 * i + 2), 16);
  return b;
};
const hexToLang = (hex) => (hex === undefined ? null : new Uint8Array([parseInt(hex.slice(0, 2), 16), parseInt(hex.slice(2, 4), 16)]));
const bytesEqual = (a, b) => a.length === b.length && a.every((v, i) => v === b[i]);

/** Parse the journal text. Returns { events, warnings, tornTail, unsupported }. */
export function parseJournal(text) {
  const events = [], warnings = [];
  let unsupported = null, tornTail = false;
  const parts = text.split('\n');
  const tail = parts.pop();   // text after the last newline: a torn record, or '' for a clean end
  if (tail !== '') tornTail = true;
  const keep = [];   // complete lines that parsed (for rewriting a journal that carried damage)
  parts.forEach((line, index) => {
    if (line === '') return;
    const at = line.lastIndexOf(' crc=');
    const bad = (reason) => warnings.push({ line: index + 1, reason, text: line });
    if (at < 0) return bad('нет контрольной суммы');
    const body = line.slice(0, at), crcText = line.slice(at + 5);
    if (!/^[0-9a-f]{8}$/.test(crcText) || crc32(encoder.encode(body)) !== parseInt(crcText, 16))
      return bad('контрольная сумма не совпала');
    const fields = body.split(' ');
    const version = fields[0], event = fields[1];
    if (!/^v[0-9]+$/.test(version)) return bad('нет версии журнала');
    if (version !== 'v1') { unsupported ??= version; return; }
    const record = { event, line: index + 1 };
    for (const field of fields.slice(2)) {
      const eq = field.indexOf('=');
      if (eq <= 0) return bad('неразборчивое поле');
      record[field.slice(0, eq)] = field.slice(eq + 1);
    }
    const ok = TX_RE.test(record.tx ?? '') && TS_RE.test(record.ts ?? '') &&
      (record.slot === undefined || hexToName(record.slot)) &&
      (record.target === undefined || hexToName(record.target)) &&
      (record.prior === undefined || PRIOR_RE.test(record.prior)) &&
      (record.sha === undefined || SHA_RE.test(record.sha)) &&
      (record.meta === undefined || META_RE.test(record.meta)) &&
      (record.lang === undefined || LANG_RE.test(record.lang)) &&
      ['size', 'n', 'writes', 'errors', 'bytes', 'err'].every(k => record[k] === undefined || NUM_RE.test(record[k])) &&
      ['reason', 'what', 'outcome', 'kind'].every(k => record[k] === undefined || TOKEN_RE.test(record[k]));
    if (!ok) return bad('недопустимое значение поля');
    record.ts = BigInt(record.ts);
    if (record.slot) record.slotName = hexToName(record.slot);
    if (record.target) record.targetName = hexToName(record.target);
    events.push(record);
    keep.push(line);
  });
  return { events, warnings, tornTail, tail, unsupported, keep };
}

/** Fold the events into transactions in journal order. */
export function buildTransactions(events) {
  const byId = new Map(), order = [];
  const get = (tx) => {
    let t = byId.get(tx);
    if (!t) { t = { id: tx, arms: [], attempts: [], attempt: null, anomaly: false, failed: false, commit: null,
      commitValid: false, settled: false, resolved: null, firstTs: null, lastTs: null, lines: [] }; byId.set(tx, t); order.push(t); }
    return t;
  };
  for (const e of events) {
    const t = get(e.tx);
    t.firstTs ??= e.ts; t.lastTs = e.ts;
    t.lines.push(e.line);
    switch (e.event) {
      case 'arm':
        if (e.slotName && e.prior && e.size !== undefined && e.sha && e.meta && (e.kind === 'delete' || e.kind === 'trunc'))
          t.arms.push({ slot: e.slotName, kind: e.kind, prior: e.prior, size: Number(e.size), sha: e.sha,
            meta: hexToMeta(e.meta), lang: hexToLang(e.lang), aborted: false });
        break;
      case 'abort': {
        const a = t.arms.find(x => !x.aborted && x.prior === e.prior);
        if (a) a.aborted = true;
        break;
      }
      case 'create':
        t.attempt = { target: e.targetName, fresh: e.fresh === '1', cycles: [], failed: false, createFailed: false };
        t.attempts.push(t.attempt);
        break;
      case 'create-fail':
        if (t.attempt && t.attempt.target === e.targetName) t.attempt.createFailed = true;
        break;
      case 'cycle':
        if (t.attempt && t.attempt.target === e.targetName)
          t.attempt.cycles.push({ n: Number(e.n), writes: Number(e.writes), errors: Number(e.errors), bytes: Number(e.bytes) });
        else t.anomaly = true;   // a cycle without its create: the record is incomplete
        break;
      case 'fail':
        if (t.attempt) t.attempt.failed = true; else t.failed = true;
        break;
      case 'anomaly': t.anomaly = true; break;
      case 'commit': {
        const a = t.attempt;
        t.commit = { target: e.targetName, size: Number(e.size), sha: e.sha };
        // the host's claim is re-validated here against its own cycle records
        t.commitValid = !!(a && !a.failed && !a.createFailed && !t.anomaly && a.target === e.targetName &&
          a.cycles.length === 2 && a.cycles[0].n === 1 && a.cycles[1].n === 2 &&
          a.cycles.every(c => c.errors === 0 && c.bytes > 0) && e.sha && e.size !== undefined);
        break;
      }
      case 'settle': t.settled = true; break;
      case 'resolved': t.resolved = e.outcome ?? 'resolved'; break;
      default: break;   // unknown v1 event: ignored, journal readers must stay forward tolerant
    }
  }
  return order;
}

/* ------------------------------------------------------------------ storage helpers */

async function digest(bytes) {
  const subtle = globalThis.crypto?.subtle;
  if (subtle?.digest) {
    const out = new Uint8Array(await subtle.digest('SHA-256', bytes));
    return [...out].map(b => b.toString(16).padStart(2, '0')).join('');
  }
  return sha256Hex(sha256Update(sha256Init(), bytes));
}
async function dirOf(parent, name, create = false) {
  try { return await parent.getDirectoryHandle(name, { create }); }
  catch (e) { if (notFound(e) && !create) return null; throw e; }
}
async function entriesOf(dir) {
  const list = [];
  if (dir) for await (const [name, handle] of dir.entries()) list.push({ name, handle });
  return list;
}
/** Exact name first, then one case-insensitive match (the guest compares
 * names without case, OPFS stores them with it). Ambiguity is an error. */
async function findFile(dir, name) {
  if (!dir) return null;
  const all = await entriesOf(dir);
  const exact = all.find(e => e.name === name);
  if (exact) return exact.handle.kind === 'file' ? exact : fail(`${name}: не файл`);
  const wanted = key(name), twins = all.filter(e => key(e.name) === wanted);
  if (twins.length > 1) fail(`${name}: имена различаются только регистром`);
  return twins[0] ?? null;
}
async function readEntry(entry) {
  if (!entry) return null;
  const file = await entry.handle.getFile();
  const bytes = new Uint8Array(await file.arrayBuffer());
  if (bytes.length !== file.size) fail(`${entry.name}: прочитан не полностью`);
  return bytes;
}
async function writeVerified(dir, name, bytes) {
  const handle = await dir.getFileHandle(name, { create: true });
  const w = await handle.createWritable();
  try { await w.write(bytes); await w.close(); }
  catch (e) { try { await w.abort?.(); } catch { /* the original error wins */ } throw e; }
  const back = new Uint8Array(await (await handle.getFile()).arrayBuffer());
  if (!bytesEqual(back, bytes)) fail(`${name}: запись не подтверждена чтением`);
}

/** One recovery run's view of the game root. */
class Store {
  constructor(game, now) { this.game = game; this.now = now; this.cache = {}; this.actions = []; }
  async dir(name, create = false) {
    if (!this.cache[name] || create) this.cache[name] = await dirOf(this.game, name, create);
    return this.cache[name];
  }
  async slot(name) { return findFile(await this.dir('SAVE'), name); }
  async meta(name) { return findFile(await this.dir('SAVE_META'), `${name}.time`); }
  async lang(name) { return findFile(await this.dir('SAVE_META'), `${name}.lang`); }
  async txDir(create = false) { return this.dir(SAVE_TX_DIR, create); }
  async readJournal() {
    const dir = await this.txDir();
    const entry = await findFile(dir, SAVE_TX_JOURNAL);
    return entry ? await readEntry(entry) : null;
  }
  async writeJournal(bytes) { await writeVerified(await this.txDir(true), SAVE_TX_JOURNAL, bytes); }
  async appendResolved(txId, outcome, extra = '') {
    const old = (await this.readJournal()) ?? new Uint8Array(0);
    const lead = old.length && old[old.length - 1] !== 10 ? '\n' : '';
    const body = `v1 resolved tx=${txId} ts=${(BigInt(this.now()) + FILETIME_UNIX_MS) * 10000n} outcome=${outcome}${extra}`;
    const line = `${lead}${body} crc=${crc32(encoder.encode(body)).toString(16).padStart(8, '0')}\n`;
    const add = encoder.encode(line), out = new Uint8Array(old.length + add.length);
    out.set(old); out.set(add, old.length);
    await this.writeJournal(out);
  }
  /** Copy `bytes` into quarantine/<tx>.<kind>/<name>, verified, deterministic
   * (a rerun finds the identical copy and reuses it). Returns the path. */
  async quarantine(label, kind, name, bytes) {
    const qroot = await dirOf(await this.txDir(true), SAVE_TX_QUARANTINE, true);
    for (let n = 1; ; n++) {
      const folder = `${label}.${kind}${n > 1 ? `.${n}` : ''}`;
      const d = await dirOf(qroot, folder, true);
      const existing = await findFile(d, name);
      if (existing) {
        const have = await readEntry(existing);
        if (bytesEqual(have, bytes)) return `${SAVE_TX_DIR}/${SAVE_TX_QUARANTINE}/${folder}/${existing.name}`;
        if (have.length) continue;   // a different earlier copy: keep it, use the next folder
        // empty: an earlier run was cut right after creating the entry; finish that copy
        await writeVerified(d, existing.name, bytes);
        return `${SAVE_TX_DIR}/${SAVE_TX_QUARANTINE}/${folder}/${existing.name}`;
      }
      await writeVerified(d, name, bytes);
      return `${SAVE_TX_DIR}/${SAVE_TX_QUARANTINE}/${folder}/${name}`;
    }
  }
  async removeFrom(dirName, entry) { await (await this.dir(dirName)).removeEntry(entry.name); }
}

/* ------------------------------------------------------------------ recovery */

const ftNow = (now) => (BigInt(now) + FILETIME_UNIX_MS) * 10000n;

async function currentState(store, slot) {
  const entry = await store.slot(slot);
  if (!entry) return { entry: null, bytes: null };
  return { entry, bytes: await readEntry(entry) };
}
/** Set the slot's SAVE_META record to `meta` (8 bytes) or to "none". Anything
 * replaced or removed is quarantined first. */
async function restoreMeta(store, tx, slot, meta) {
  const entry = await store.meta(slot);
  const have = entry ? await readEntry(entry) : null;
  if (meta) {
    if (have && bytesEqual(have, meta)) return;
    if (have) await store.quarantine(tx, 'meta', `${slot}.time`, have);
    const dir = await store.dir('SAVE_META', true);
    await writeVerified(dir, entry ? entry.name : `${slot}.time`, meta);
  } else if (entry) {
    await store.quarantine(tx, 'meta', `${slot}.time`, have);
    await store.removeFrom('SAVE_META', entry);
  }
}

/** Set the slot's SAVE_META language label (E5) to `lang` (2 bytes) or to "none"; same rules as restoreMeta: anything replaced or removed is
 * quarantined first. A journal without a lang field (every journal of the Russian mode) means "no label": a label the failed attempt left goes. */
async function restoreLang(store, tx, slot, lang) {
  const entry = await store.lang(slot);
  const have = entry ? await readEntry(entry) : null;
  if (lang) {
    if (have && bytesEqual(have, lang)) return;
    if (have) await store.quarantine(tx, 'lang', `${slot}.lang`, have);
    const dir = await store.dir('SAVE_META', true);
    await writeVerified(dir, entry ? entry.name : `${slot}.lang`, lang);
  } else if (entry) {
    await store.quarantine(tx, 'lang', `${slot}.lang`, have);
    await store.removeFrom('SAVE_META', entry);
  }
}

/** Roll one failed transaction back. `force` resolves conflicts in favor of
 * the prior (current bytes are quarantined first). Returns a result record. */
async function rollBack(store, t, frozen, pinned, force) {
  const arms = t.arms.filter(a => !a.aborted);
  const last = t.attempt && !(t.attempt.createFailed && !t.attempt.cycles.length) ? t.attempt : null;
  const result = { tx: t.id, outcome: 'rolled-back', slots: [], quarantined: [], detail: [] };
  const touched = [...arms.map(a => a.slot), ...(last ? [last.target] : [])];
  const blocker = touched.find(s => frozen.has(key(s)));
  if (blocker !== undefined) return { ...result, outcome: 'refused', reason: 'blocked', detail: [`слот «${blocker}» заморожен более новой нерешённой транзакцией`] };
  // preflight: no mutation before every prior is proven readable and intact
  const live = [];
  for (const a of arms) {
    if (pinned.has(key(a.slot))) { result.detail.push(`слот «${a.slot}» заменён более новым завершённым сохранением`); continue; }
    const entry = await findFile(await store.txDir(), a.prior);
    const bytes = entry ? await readEntry(entry) : null;
    if (!bytes) return { ...result, outcome: 'refused', reason: 'prior-missing', detail: [`нет копии ${a.prior} слота «${a.slot}»`] };
    if (bytes.length !== a.size || await digest(bytes) !== a.sha)
      return { ...result, outcome: 'refused', reason: 'prior-corrupt', detail: [`копия ${a.prior} слота «${a.slot}» повреждена`] };
    live.push({ arm: a, bytes });
  }
  if (last && !last.fresh && !arms.some(a => key(a.slot) === key(last.target)) && !pinned.has(key(last.target)))
    return { ...result, outcome: 'refused', reason: 'arm-missing',
      detail: [`слот «${last.target}» существовал до записи, но запись о его копии потеряна`] };
  const targetKey = last ? key(last.target) : null;
  const plan = [];   // decide everything first (reads only)
  let conflict = false;
  for (const { arm, bytes } of live.slice().reverse()) {
    const cur = await currentState(store, arm.slot);
    const isTarget = key(arm.slot) === targetKey;
    if (cur.bytes && bytesEqual(cur.bytes, bytes)) plan.push({ arm, bytes, op: 'keep', cur });
    // an empty file is what a restore leaves when it was cut between creating the OPFS entry and committing
    // its content (and no valid slot is ever empty): it counts as absent, so a rerun completes the restore
    else if (!cur.bytes || !cur.bytes.length) plan.push({ arm, bytes, op: 'write', cur });
    else if (isTarget || force) plan.push({ arm, bytes, op: 'overwrite', cur });
    else { plan.push({ arm, bytes, op: 'conflict', cur }); conflict = true; }
  }
  let targetPlan = null;
  if (last && !pinned.has(targetKey) && !arms.some(a => key(a.slot) === targetKey)) {
    const cur = await currentState(store, last.target);
    if (cur.bytes) targetPlan = { cur };
  }
  // execute: copies first, then replacements, then removals
  for (const p of plan) {
    if (p.op === 'overwrite') result.quarantined.push(await store.quarantine(t.id, 'partial', p.cur.entry.name, p.cur.bytes));
    if (p.op === 'conflict') {
      result.quarantined.push(await store.quarantine(t.id, 'current', p.cur.entry.name, p.cur.bytes));
      result.detail.push(`слот «${p.arm.slot}» изменён кем-то ещё; оставлен как есть, копия в карантине`);
    }
  }
  if (targetPlan) result.quarantined.push(await store.quarantine(t.id, 'partial', targetPlan.cur.entry.name, targetPlan.cur.bytes));
  for (const p of plan) {
    if (p.op === 'write' || p.op === 'overwrite') {
      const dir = await store.dir('SAVE', true);
      await writeVerified(dir, p.cur.entry ? p.cur.entry.name : p.arm.slot, p.bytes);
      result.slots.push({ slot: p.arm.slot, action: 'restored' });
    } else if (p.op === 'keep') result.slots.push({ slot: p.arm.slot, action: 'already-restored' });
    if (p.op !== 'conflict') {
      await restoreMeta(store, t.id, p.arm.slot, p.arm.meta);
      await restoreLang(store, t.id, p.arm.slot, p.arm.lang);
    }
  }
  if (targetPlan) {
    const slotName = targetPlan.cur.entry.name;
    await restoreMeta(store, t.id, slotName, null);   // quarantines the partial's record, then drops it
    await restoreLang(store, t.id, slotName, null);
    await store.removeFrom('SAVE', targetPlan.cur.entry);
    result.slots.push({ slot: slotName, action: 'removed-partial' });
  }
  if (conflict) result.outcome = 'quarantined';
  else if (!live.length && !targetPlan) result.outcome = result.detail.length ? 'superseded' : 'noop';
  return result;
}

function classify(t, now, minAgeMs) {
  const liveArms = t.arms.filter(a => !a.aborted);
  const last = t.attempt;
  const noEffect = !last || (last.createFailed && !last.cycles.length);
  if (t.commitValid) return 'committed';
  if (!liveArms.length && noEffect && !t.commit && !t.anomaly && !t.failed) return 'noop';
  if (liveArms.length && liveArms.every(a => a.kind === 'delete') && !t.attempts.length &&
      !t.failed && !t.anomaly && !t.commit) {
    const age = ftNow(now) - t.lastTs;
    const credible = t.lastTs <= ftNow(now) + 36000000000n;   // not more than an hour in the future
    if (t.settled || (credible && age >= BigInt(minAgeMs) * 10000n)) return 'explicit-delete';
  }
  return 'failed';
}

async function pruneHistory(store, txs, keep, result) {
  const txDir = await store.txDir();
  if (!txDir) return;
  const referenced = new Set(txs.flatMap(t => t.arms.map(a => a.prior)));
  const protectedPriors = new Set(), history = [];
  for (const t of [...txs].reverse()) {   // newest first
    for (const a of t.arms) {
      if (t.keepPriors) protectedPriors.add(a.prior); else history.push(a.prior);
    }
  }
  const present = new Set((await entriesOf(txDir)).map(e => e.name));
  const doomed = history.slice(keep).filter(p => !protectedPriors.has(p) && present.has(p));
  for (const name of doomed) {
    const entry = await findFile(txDir, name);
    if (entry) { await txDir.removeEntry(entry.name); result.pruned.push(name); }
  }
  for (const name of present) if (PRIOR_RE.test(name) && !referenced.has(name)) result.orphans.push(name);
}

async function compactJournal(store, txs, bytes, result) {
  if (bytes.length <= SAVE_TX_COMPACT_BYTES) return;
  const txDir = await store.txDir();
  const present = new Set((await entriesOf(txDir)).map(e => e.name));
  const keepIds = new Set(txs.filter(t => t.arms.some(a => present.has(a.prior))).map(t => t.id));
  const lines = decoder.decode(bytes).split('\n').filter(l => l && keepIds.has(/ tx=([0-9a-f]{20}) /.exec(l)?.[1]));
  await store.writeJournal(encoder.encode(lines.length ? lines.join('\n') + '\n' : ''));
  result.compacted = true;
}

// decisions that fix a slot's content against OLDER transactions; a rollback does not (it hands the slot to the
// older transaction's prior, which is what a chain of failed overwrites needs)
const PINNING = new Set(['accepted', 'explicit-delete', 'kept-current', 'restored-prior']);
const KEEP_PRIORS = new Set(['quarantined', 'kept-current']);
const RANK = { clean: 0, recovered: 1, 'rolled-back': 2, quarantined: 3, refused: 4 };
const worst = (a, b) => (RANK[b] > RANK[a] ? b : a);
const STATUS_OF = { accepted: 'recovered', 'explicit-delete': 'recovered', superseded: 'recovered', 'kept-current': 'recovered', noop: 'clean',
  'rolled-back': 'rolled-back', quarantined: 'quarantined', refused: 'refused' };

/** Does a lock manager show an exclusive hold on this root's SAVE lock? A
 * proof of "somebody holds it", used as a guard against calling recovery
 * without having taken the lock; ownership itself is by construction (the
 * caller took it). Without query() nothing can be verified: refuse. */
async function lockIsHeld(locks, rootName) {
  if (typeof locks?.query !== 'function') return false;
  try {
    const state = await locks.query();
    return (state?.held ?? []).some(l => l.name === saveLockName(rootName) && l.mode === 'exclusive');
  } catch { return false; }
}

/** Core: the caller already holds the `${rootName}:save-backup` lock (the page
 * does, from the moment the game start is requested). Never throws for a
 * domain refusal; an unexpected storage error stops the run with status
 * 'refused' and reason 'io-error' — nothing is retried and the caller must not
 * start the game on top of an unfinished recovery.
 * opts: { root, rootName, locks, now(), explicitMinAgeMs, keep, resolve:{tx,choice} } */
export async function recoverSaveTxLocked(opts) {
  const { root, rootName, locks } = opts;
  const now = opts.now ?? (() => Date.now());
  const minAge = opts.explicitMinAgeMs ?? EXPLICIT_DELETE_MIN_AGE_MS;
  const keep = opts.keep ?? SAVE_TX_HISTORY_KEEP;
  const result = { status: 'clean', txs: [], warnings: [], pruned: [], orphans: [], tornTail: false, compacted: false };
  if (!root?.getDirectoryHandle || typeof rootName !== 'string' || !rootName) fail('Некорректные параметры восстановления SAVE_TX.');
  if (!(await lockIsHeld(locks, rootName))) {
    return { ...result, status: 'refused', reason: 'no-lock-ownership',
      message: 'Не удалось убедиться, что эта страница единолично владеет сохранениями; восстановление не выполнялось.' };
  }
  try {
    const game = await dirOf(root, rootName);
    if (!game) return result;
    const store = new Store(game, now);
    const raw = await store.readJournal();
    if (!raw) return result;
    const parsed = parseJournal(decoder.decode(raw));
    result.warnings.push(...parsed.warnings.map(w => `журнал, строка ${w.line}: ${w.reason}`));
    result.tornTail = parsed.tornTail;
    if (parsed.unsupported) {
      return { ...result, status: 'refused', reason: 'unsupported-journal',
        message: `Журнал SAVE_TX написан другой версией (${parsed.unsupported}); данные не тронуты.` };
    }
    if (parsed.tornTail || parsed.warnings.length) {
      // Damage never stays in the journal: the whole original is copied to quarantine, then the journal is
      // rewritten with only the intact lines. A torn final record is the normal signature of a crash; a damaged
      // line in the middle is not (it bumps the status), and what it described can only be found as orphans.
      await store.quarantine(`journal-${Number(now())}`, 'damaged', SAVE_TX_JOURNAL, raw);
      await store.writeJournal(encoder.encode(parsed.keep.length ? parsed.keep.join('\n') + '\n' : ''));
      if (parsed.warnings.length) result.status = worst(result.status, 'quarantined');
    }
    const txs = buildTransactions(parsed.events);
    const pinned = new Set(), frozen = new Set();
    const resolve = opts.resolve;
    if (resolve && !txs.some(t => t.id === resolve.tx)) result.warnings.push(`транзакция ${resolve.tx} не найдена в журнале`);
    for (const t of [...txs].reverse()) {   // newest first: an older failed intent never overrides a newer finished one
      const choice = resolve?.tx === t.id ? resolve.choice : null;
      // a quarantined / kept-current decision can be revisited explicitly: its priors were protected for that
      const reopened = !!t.resolved && choice === 'restore-prior' && KEEP_PRIORS.has(t.resolved);
      if (t.resolved && !reopened) {
        // an already decided transaction still pins its slots against older ones
        if (PINNING.has(t.resolved))
          for (const s of [...t.arms.map(a => a.slot), t.commit?.target].filter(Boolean)) pinned.add(key(s));
        t.keepPriors = KEEP_PRIORS.has(t.resolved);
        continue;
      }
      const kind = reopened ? 'failed' : classify(t, now(), minAge);
      let r;
      if (kind === 'noop') r = { tx: t.id, outcome: 'noop', slots: [], quarantined: [], detail: [] };
      else if (kind === 'committed') {
        const target = t.commit.target;
        if (pinned.has(key(target)) || frozen.has(key(target)))
          r = { tx: t.id, outcome: 'superseded', slots: [], quarantined: [], detail: [`слот «${target}» заменён более новой записью`] };
        else {
          const cur = await currentState(store, target);
          if (cur.bytes && cur.bytes.length === t.commit.size && await digest(cur.bytes) === t.commit.sha)
            r = { tx: t.id, outcome: 'accepted', slots: [{ slot: target, action: 'verified' }], quarantined: [], detail: [] };
          else {
            const q = cur.bytes ? [await store.quarantine(t.id, 'current', cur.entry.name, cur.bytes)] : [];
            r = { tx: t.id, outcome: 'quarantined', slots: [{ slot: target, action: cur.bytes ? 'differs-from-fixture' : 'missing' }],
              quarantined: q, detail: [`слот «${target}» не совпал с зафиксированным SHA-256; оставлен как есть`] };
          }
        }
        for (const a of t.arms) pinned.add(key(a.slot));
        pinned.add(key(target));
      } else if (kind === 'explicit-delete') {
        r = { tx: t.id, outcome: 'explicit-delete', slots: t.arms.filter(a => !a.aborted).map(a => ({ slot: a.slot, action: 'stays-deleted' })),
          quarantined: [], detail: ['явное удаление; копия оставлена в SAVE_TX'] };
        // a cut between the slot's unlink and its record's unlink leaves an orphan SAVE_META record: drop it (copied first)
        for (const a of t.arms.filter(x => !x.aborted))
          if (!(await store.slot(a.slot)) && !pinned.has(key(a.slot))) { await restoreMeta(store, t.id, a.slot, null); await restoreLang(store, t.id, a.slot, null); }
        for (const a of t.arms) pinned.add(key(a.slot));
      } else if (choice === 'keep-current') {
        r = { tx: t.id, outcome: 'kept-current', slots: [], quarantined: [], detail: ['оставлено текущее содержимое по выбору пользователя'] };
        for (const s of [...t.arms.map(a => a.slot), t.attempt?.target].filter(Boolean)) pinned.add(key(s));
      } else {
        r = await rollBack(store, t, frozen, pinned, choice === 'restore-prior');
        if (r.outcome === 'refused')
          for (const s of [...t.arms.map(a => a.slot), t.attempt?.target].filter(Boolean)) frozen.add(key(s));
        else if (choice === 'restore-prior')   // an explicit decision is final against older transactions
          for (const s of [...t.arms.map(a => a.slot), t.attempt?.target].filter(Boolean)) pinned.add(key(s));
      }
      t.keepPriors = r.outcome === 'refused' || KEEP_PRIORS.has(r.outcome);
      result.txs.push(r);
      result.status = worst(result.status, STATUS_OF[r.outcome] ?? 'quarantined');
      if (r.outcome !== 'refused') {
        await store.appendResolved(t.id, choice === 'restore-prior' && r.outcome === 'rolled-back' ? 'restored-prior' : r.outcome);
        t.resolved = r.outcome;
      }
    }
    // housekeeping only when every transaction is decided
    if (result.status !== 'refused') {
      await pruneHistory(store, txs, keep, result);
      const after = await store.readJournal();
      if (after) await compactJournal(store, txs, after, result);
    } else {
      const referenced = new Set(txs.flatMap(t => t.arms.map(a => a.prior)));
      const txDir = await store.txDir();
      for (const e of await entriesOf(txDir)) if (PRIOR_RE.test(e.name) && !referenced.has(e.name)) result.orphans.push(e.name);
    }
    result.txs.reverse();   // chronological for readers
    result.message = describeResult(result);
    return result;
  } catch (error) {
    return { ...result, status: 'refused', reason: 'io-error', error: String(error?.message ?? error),
      message: `Восстановление SAVE_TX остановлено из-за ошибки хранилища: ${error?.message ?? error}. Игра не должна стартовать поверх незавершённого восстановления.` };
  }
}

/** Fail-fast under the page's own SAVE lock (for callers that do not hold it,
 * e.g. tests and tools): a busy lock is a 'refused'/'busy' result, never a wait. */
export async function recoverSaveTx(opts) {
  const { locks, rootName } = opts;
  if (!locks?.request) return { status: 'refused', reason: 'no-locks', txs: [], warnings: [], message: 'Браузер не поддерживает блокировку сохранений.' };
  return locks.request(saveLockName(rootName), { mode: 'exclusive', ifAvailable: true }, async (lock) => {
    if (!lock) return { status: 'refused', reason: 'busy', txs: [], warnings: [], message: 'Сохранения сейчас заняты другой вкладкой или операцией; восстановление не выполнялось.' };
    return recoverSaveTxLocked(opts);
  });
}

/** Explicit, loss-free resolution of one refused transaction (under the lock):
 * 'keep-current' accepts what is on disk now (nothing changes; the prior stays
 * in SAVE_TX), 'restore-prior' quarantines the current bytes and restores the
 * previous completed version. Then the normal recovery runs for the rest. */
export async function resolveSaveTxConflict(opts) {
  const { tx, choice } = opts;
  if (!TX_RE.test(tx ?? '') || !['keep-current', 'restore-prior'].includes(choice)) fail('Некорректное решение по транзакции SAVE_TX.');
  return recoverSaveTxLocked({ ...opts, resolve: { tx, choice } });
}

export function describeResult(result) {
  const lines = [];
  for (const t of result.txs) {
    const slots = t.slots?.map(s => `«${s.slot}»`).join(', ');
    switch (t.outcome) {
      case 'accepted': lines.push(`Сохранение ${slots} подтверждено (SHA-256 совпал).`); break;
      case 'rolled-back': lines.push(`Незавершённое сохранение отменено: слот возвращён к прежней версии${slots ? ` (${slots})` : ''}.`); break;
      case 'explicit-delete': lines.push(`Удаление слота ${slots} подтверждено; копия сохранена в SAVE_TX.`); break;
      case 'quarantined': lines.push(`Часть данных помещена в карантин (${t.quarantined?.length ?? 0} копий): ${t.detail?.join('; ') ?? ''}`); break;
      case 'refused': lines.push(`Требуется решение по транзакции ${t.tx}: ${t.detail?.join('; ') ?? t.reason}.`); break;
      default: break;
    }
  }
  return lines.join(' ');
}
