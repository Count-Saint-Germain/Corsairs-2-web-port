// SAVE_TX и страничное восстановление при включённом слое имён CP1251 <-> UTF-8 (PORT_NAME_CP1251): НАСТОЯЩИЕ
// обработчики kernel32.c (test_name_cp1251.c --tx, нативная сборка с -DPORT_SAVE_META=1 -DPORT_SAVE_TX=1, слой включён)
// пишут журнал SAVE_TX и sidecar для слота с КИРИЛЛИЧЕСКИМ именем («Оксбей порт 12-11-2026», байты CP1251 у гостя,
// UTF-8 на хосте); НАСТОЯЩИЙ web/save-tx.mjs восстанавливает получившийся каталог. Проверяется:
//   * каждое имя в журнале (slot=/target=, hex) декодируется строгим UTF-8 страничным hexToName/validateName и равно ожидаемому;
//   * после нормального завершения слот в итоге содержит NEW-2, после убийства процесса между стадиями откатывается
//     к OLD-VERSION вместе с sidecar-записью, под тем же UTF-8 именем; повторное восстановление чистое и ничего не меняет;
//   * ни один байт, бывший на диске до восстановления, не потерян.
// Это синтетика: «убийство» это _exit(), OPFS заменён каталогом (см. save_tx_fixture.mjs), игра не запускалась.
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { recoverSaveTx, parseJournal } from '../web/save-tx.mjs';
import { validateName } from '../web/save-export.mjs';
import { opfsRoot, makeCtx, Locks, tmpRoot, walk, sha, snapshot, sameSnapshot, jline, txId, priorName, metaHex } from './save_tx_fixture.mjs';

const BIN = process.env.NAME_TX_BIN;
if (!BIN) { console.error('NAME_TX_BIN is not set (use run_name_cp1251.sh savetx)'); process.exit(2); }
const here = path.dirname(new URL(import.meta.url).pathname);
const BASE = process.env.NAME_TX_TMP ?? path.join(here, '..', 'web_toolchain', 'tmp', 'name-cp1251-tx');
const ROOT_NAME = 'korsary2-game';
const SLOT = 'Оксбей порт 12-11-2026';          // как его видит хост: UTF-8
const run = (args) => spawnSync(BIN, ['--tx', ...args], { encoding: 'utf8' });
const read = (p) => fs.readFileSync(p);
const slotPath = (game, name) => path.join(game, 'SAVE', name);
const metaPath = (game, name) => path.join(game, 'SAVE_META', `${name}.time`);

function hexNames(game) {   // every slot=/target= value of the journal, decoded the way save-tx.mjs does
  const j = path.join(game, 'SAVE_TX', 'journal.log');
  if (!fs.existsSync(j)) return [];
  const names = [];
  for (const line of read(j).toString('utf8').split('\n')) {
    for (const m of line.matchAll(/ (?:slot|target)=([0-9a-f]+)/g)) {
      const bytes = Buffer.from(m[1], 'hex');
      const name = new TextDecoder('utf-8', { fatal: true }).decode(bytes);   // throws when the host wrote a non-UTF-8 name
      validateName(name);
      names.push(name);
    }
  }
  return names;
}
async function recover(root) {
  return recoverSaveTx({ root: opfsRoot(root, makeCtx()), rootName: ROOT_NAME, locks: new Locks() });
}
const treeShas = (root) => new Set([...walk(path.join(root, ROOT_NAME))].filter(([k, v]) => !k.endsWith('journal.log') && v.length).map(([, v]) => sha(v)));

// Контроль (то, из-за чего слой нужен): журнал с именем слота в CP1251 («Тест», d2e5f1f2: не UTF-8) страница отвергает как
// «недопустимое значение поля»; запись пропадает, откат этого слота не опирается на неё. С включённым слоем имена UTF-8.
{
  const line = jline('arm', txId(1), { kind: 'delete', slot: 'd2e5f1f2', prior: priorName(txId(1)), size: 1, sha: '0'.repeat(64), meta: metaHex(new Uint8Array(8)) });
  const parsed = parseJournal(line);
  assert.equal(parsed.events.length, 0, 'CP1251-hex slot name is not accepted by the page parser');
  assert.equal(parsed.warnings.length, 1);
  const ok = parseJournal(jline('arm', txId(1), { kind: 'delete', slot: Buffer.from('Тест', 'utf8').toString('hex'), prior: priorName(txId(1)), size: 1, sha: '0'.repeat(64), meta: metaHex(new Uint8Array(8)) }));
  assert.equal(ok.events.length, 1, 'the same name as UTF-8 hex is accepted');
  console.log('control: journal name d2e5f1f2 (CP1251) is rejected by parseJournal, the UTF-8 spelling of the same name is accepted: PASS');
}

fs.rmSync(BASE, { recursive: true, force: true });
const scenarios = [
  // [scenario, name of the slot that must hold the bytes at the end, expected bytes]
  ['overwrite', SLOT, 'NEW-2', 0],
  ['rename', `${SLOT} 2`, 'NEW-2', 0],
  ['kill-after-delete', SLOT, 'OLD-VERSION', 77],
  ['kill-after-stage1', SLOT, 'OLD-VERSION', 77],
  ['delete', SLOT, 'OLD-VERSION', 0],
];
for (const [sc, finalName, finalBytes, code] of scenarios) {
  const root = tmpRoot(`${sc}-`, BASE);
  const game = path.join(root, ROOT_NAME);
  fs.mkdirSync(game);
  assert.equal(run([game, 'seed']).status, 0, `${sc}: seed`);
  assert.ok(fs.existsSync(slotPath(game, SLOT)), `${sc}: the seed slot is stored under the UTF-8 name`);
  assert.ok(fs.existsSync(metaPath(game, SLOT)) && read(metaPath(game, SLOT)).length === 8, `${sc}: sidecar is named by the UTF-8 slot`);
  const r = run([game, sc]);
  assert.equal(r.status, code, `${sc}: host exit ${r.status}\n${r.stdout}${r.stderr}`);
  // journal names: strict UTF-8, the Cyrillic slot (and the renamed target)
  const names = hexNames(game);
  assert.ok(names.includes(SLOT), `${sc}: the journal names the slot in UTF-8 (${JSON.stringify(names)})`);
  if (sc === 'rename') assert.ok(names.includes(`${SLOT} 2`), `${sc}: the journal names the new target`);
  const before = treeShas(root);
  const result = await recover(root);
  assert.notEqual(result.status, 'refused', `${sc}: recovery refused: ${JSON.stringify(result)}`);
  const fp = slotPath(game, finalName);
  assert.ok(fs.existsSync(fp), `${sc}: slot ${finalName} exists after recovery (${JSON.stringify(result.txs)})`);
  assert.equal(read(fp).toString(), finalBytes, `${sc}: final bytes of ${finalName}`);
  assert.ok(fs.existsSync(metaPath(game, finalName)) && read(metaPath(game, finalName)).length === 8, `${sc}: sidecar record of ${finalName}`);
  assert.equal(read(slotPath(game, 'Keep')).toString(), 'KEEP', `${sc}: the neighbour slot is untouched`);
  const after = treeShas(root);
  for (const s of before) assert.ok(after.has(s), `${sc}: content ${s.slice(0, 12)} was lost`);
  // no mangled-name twin: every entry of SAVE and SAVE_META is valid UTF-8 and nothing with U+FFFD
  for (const dir of ['SAVE', 'SAVE_META'])
    for (const n of fs.readdirSync(path.join(game, dir))) {
      const bytes = Buffer.from(n, 'utf8');
      assert.ok(!n.includes('�') && bytes.toString('utf8') === n, `${sc}: ${dir}/${n}`);
    }
  const settled = snapshot(root);
  const again = await recover(root);
  assert.equal(again.status, 'clean', `${sc}: second recovery ${again.status}`);
  assert.ok(sameSnapshot(settled, snapshot(root)), `${sc}: second recovery changed the tree`);
  console.log(`${sc}: journal names ${JSON.stringify(names.filter((v, i, a) => a.indexOf(v) === i))}, recovery ${result.status} ${JSON.stringify(result.txs.map((t) => t.outcome))}, final ${finalName} = ${finalBytes}: PASS`);
  fs.rmSync(root, { recursive: true, force: true });
}
console.log('NAME-CP1251-SAVE-TX-DONE');
