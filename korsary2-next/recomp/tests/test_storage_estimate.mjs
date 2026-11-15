/* Оценка нужного места до загрузки/обновления (save-protection.mjs: planStorageNeed, assessStorage,
   measureDirBytes, checkStorageForSync). Чистые функции и синтетический OPFS в памяти; настоящая
   квота браузера и navigator.storage.estimate() здесь НЕ участвуют — оценка подставляется тестом.

   Что доказано: чистая установка считается по всему манифесту (консервативно); мелкое обновление при
   почти полной квоте не получает отказа (раньше сравнивалось с половиной ВСЕГО манифеста); большое
   обновление отказывает до записи; estimate недоступен/ломается/нулевой/некорректный — загрузку не
   блокируем; временная копия заменяемого файла и запас под архив SAVE входят в расчёт; проверка
   ничего не создаёт и не пишет. */
import assert from 'node:assert/strict';
import { assessStorage, checkStorageForSync, isPrivacyCappedQuota, measureDirBytes, planStorageNeed, STORAGE_LIMITS }
  from '../web/save-protection.mjs';

const MiB = 1024 * 1024;
const missing = () => Object.assign(new Error('missing'), { name: 'NotFoundError' });
// SHA-256 обязателен у каждой записи манифеста (validateManifestFiles, N11); для оценки места значения не важны
const f = (path, size) => ({ path, size, sha256: '0'.repeat(64) });
const have = (obj) => new Map(Object.entries(obj));
const L = STORAGE_LIMITS;

/* ---------- 1. чистая установка: всё из манифеста, ничего не освобождается ---------- */
{
  const files = [f('ENGINE.exe', 30 * MiB), f('RESOURCE/a.dat', 700 * MiB), f('options', 1000)];
  const p = planStorageNeed({ files, haveSizes: new Map(), hadMarker: false });
  const total = 30 * MiB + 700 * MiB + 1000;
  assert.equal(p.fresh, true);
  assert.equal(p.writeBytes, total);
  assert.equal(p.growthBytes, total);
  assert.equal(p.tempBytes, 0);
  assert.equal(p.toDownload, 3);
  assert.equal(p.minBytes, total, 'на чистой установке минимум = весь манифест (не половина)');
  assert.ok(p.totalBytes > p.minBytes, 'запас на архив SAVE и неточность сверх минимума');
  assert.equal(p.backupReserveBytes, L.minBackupReserveBytes);
  assert.equal(p.slackBytes, Math.max(L.minSlackBytes, Math.ceil(total * L.slackRatio)));
  // квота 2 ГиБ, занято 1.5 ГиБ чужими данными: чистая установка на 730 МиБ не помещается
  const a = assessStorage(p, { quota: 2048 * MiB, usage: 1500 * MiB });
  assert.equal(a.status, 'insufficient');
  assert.match(a.message, /Недостаточно места/);
  assert.match(a.message, /установки/);
  assert.match(a.message, /Сохранения не затронуты/);
  // впритык: хватает на минимум, но не на запас -> предупреждение, не отказ
  const t = assessStorage(p, { quota: 800 * MiB + 1, usage: 50 * MiB });
  assert.equal(t.status, 'tight');
  assert.equal(assessStorage(p, { quota: 10_000 * MiB, usage: 0 }).status, 'ok');
  // старое поведение (порог = 50% манифеста) на чистой установке стало строже
  assert.ok(p.minBytes > total * 0.5);
}

/* ---------- 2. мелкое обновление при почти полной квоте не получает отказ ---------- */
{
  const files = [f('ENGINE.exe', 30 * MiB), f('RESOURCE/big1.dat', 900 * MiB), f('RESOURCE/big2.dat', 900 * MiB),
    f('PROGRAM/a.c', 5000), f('PROGRAM/new.c', 7000), f('options', 1000)];
  const installed = have({ 'ENGINE.exe': 30 * MiB, 'RESOURCE/big1.dat': 900 * MiB, 'RESOURCE/big2.dat': 900 * MiB,
    'PROGRAM/a.c': 4000, options: 1000 });   // a.c вырос, new.c новый, остальное совпало по размеру
  const p = planStorageNeed({ files, haveSizes: installed, hadMarker: true, saveBytes: 3 * MiB });
  assert.equal(p.fresh, false);
  assert.equal(p.toDownload, 2);            // a.c (другой размер) и new.c
  assert.equal(p.writeBytes, 5000 + 7000);
  assert.equal(p.growthBytes, 1000 + 7000); // a.c: +1000 после освобождения старой копии
  assert.equal(p.tempBytes, 4000);          // пока пишется swap, старый a.c ещё занят
  assert.equal(p.minBytes, 12000);
  assert.equal(p.backupReserveBytes, L.minBackupReserveBytes);   // SAVE 3 МиБ < минимума
  assert.equal(p.largestVerifyBytes, 900 * MiB);
  // запас учитывает один совпавший по размеру, но возможно изменённый по содержимому файл (с потолком)
  assert.equal(p.slackBytes, L.maxVerifyReserveBytes);
  // квота почти полна: usage уже включает установленные 1830 МиБ, свободно 1 МиБ
  const quota = 1831 * MiB;
  assert.equal(assessStorage(p, { quota, usage: 1830 * MiB }).status, 'tight');
  // старый порог: 50% всего манифеста (~915 МиБ) заблокировал бы это обновление
  const free = quota - 1830 * MiB;
  const oldBlocked = free < files.reduce((s, x) => s + x.size, 0) * 0.5;
  assert.equal(oldBlocked, true, 'пример воспроизводит дефект прежней оценки');
  assert.notEqual(assessStorage(p, { quota, usage: 1830 * MiB }).status, 'insufficient', 'нового отказа нет');
  // минимальный запас хватает на сам прирост -> предупреждение, а при чуть большем свободном — ok
  assert.equal(assessStorage(p, { quota: 1830 * MiB + p.totalBytes, usage: 1830 * MiB }).status, 'ok');
}

/* ---------- 3. большое обновление: отказ до записи, с понятным сообщением ---------- */
{
  const files = [f('RESOURCE/big.dat', 800 * MiB), f('PROGRAM/a.c', 10)];
  const installed = have({ 'RESOURCE/big.dat': 799 * MiB, 'PROGRAM/a.c': 10 });
  const p = planStorageNeed({ files, haveSizes: installed, hadMarker: true });
  assert.equal(p.toDownload, 1);
  assert.equal(p.writeBytes, 800 * MiB);
  assert.equal(p.growthBytes, 1 * MiB);          // старая копия освободится
  assert.equal(p.tempBytes, 799 * MiB);          // но на время записи нужны обе
  assert.equal(p.minBytes, 800 * MiB);
  const a = assessStorage(p, { quota: 3000 * MiB, usage: 2500 * MiB });   // свободно 500 МиБ
  assert.equal(a.status, 'insufficient');
  assert.match(a.message, /обновления/);
  assert.ok(a.message.includes(`${Math.ceil(800 * MiB / 1e6)} МБ`), a.message);
  assert.equal(a.free, 500 * MiB);
  assert.equal(assessStorage(p, { quota: 3000 * MiB, usage: 2190 * MiB }).status, 'tight');   // 810 МиБ: минимум есть, запаса нет
  assert.equal(assessStorage(p, { quota: 3000 * MiB, usage: 2000 * MiB }).status, 'ok');      // 1000 МиБ
  // файл, который уменьшился: прироста нет, но временная копия — не больше нового размера
  const shrink = planStorageNeed({ files: [f('x', 100)], haveSizes: have({ x: 500 }), hadMarker: true });
  assert.equal(shrink.growthBytes, 0);
  assert.equal(shrink.tempBytes, 100);
}

/* ---------- 4. возобновление незавершённой установки: докачивается только хвост ---------- */
{
  const p = planStorageNeed({ files: [f('a', 1000), f('b', 500), f('c', 300)],
    haveSizes: have({ a: 400, b: 500 }), hadMarker: false });
  assert.equal(p.toResume, 1);
  assert.equal(p.unchanged, 1);
  assert.equal(p.toDownload, 1);
  assert.equal(p.writeBytes, 600 + 300);
  assert.equal(p.fresh, false, 'частично установленные файлы: это не чистая установка');
  // тот же частичный файл при завершённой установке — старое содержимое, пишется заново
  const q = planStorageNeed({ files: [f('a', 1000)], haveSizes: have({ a: 400 }), hadMarker: true });
  assert.equal(q.toResume, 0);
  assert.equal(q.writeBytes, 1000);
  assert.equal(q.tempBytes, 400);
}

/* ---------- 5. нечего писать: проверка не нужна, estimate не мешает ---------- */
{
  const files = [f('a', 1000), f('options', 10)];
  const p = planStorageNeed({ files, haveSizes: have({ a: 1000, options: 10 }), hadMarker: true });
  assert.equal(p.writeBytes, 0);
  for (const est of [undefined, null, {}, { quota: 0, usage: 0 }, { quota: 1, usage: 1e12 }]) {
    const a = assessStorage(p, est);
    assert.equal(a.status, 'ok');
    assert.equal(a.message, '');
  }
  // options игрока (даже другого размера) не перезаписывается и места не просит
  const o = planStorageNeed({ files: [f('options', 999)], haveSizes: have({ options: 10 }), hadMarker: true });
  assert.equal(o.writeBytes, 0);
}

/* ---------- 6. estimate недоступен или некорректен: НЕ блокируем ---------- */
{
  const p = planStorageNeed({ files: [f('big', 5000 * MiB)], haveSizes: new Map(), hadMarker: false });
  const bad = [undefined, null, 0, 'x', [], {}, { usage: 5 }, { quota: 0, usage: 0 }, { quota: -1, usage: 0 },
    { quota: NaN, usage: 0 }, { quota: Infinity, usage: 0 }, { quota: '100', usage: 0 }, { quota: null, usage: 1 }];
  for (const est of bad) {
    const a = assessStorage(p, est);
    assert.equal(a.status, 'unknown', JSON.stringify(est));
    assert.match(a.message, /без предварительной проверки/);
    assert.equal(a.free, null);
  }
  // usage неизвестен: если даже вся квота меньше минимума — отказ достоверен; иначе не блокируем
  assert.equal(assessStorage(p, { quota: 100 * MiB }).status, 'insufficient');
  assert.equal(assessStorage(p, { quota: 100 * MiB, usage: undefined }).status, 'insufficient');
  assert.equal(assessStorage(p, { quota: 9000 * MiB }).status, 'unknown');
  assert.equal(assessStorage(p, { quota: 9000 * MiB, usage: -5 }).status, 'unknown');
  assert.equal(assessStorage(p, { quota: 9000 * MiB, usage: NaN }).status, 'unknown');
  // usage > quota: свободного места нет
  const over = assessStorage(p, { quota: 100 * MiB, usage: 300 * MiB });
  assert.equal(over.status, 'insufficient');
  assert.equal(over.free, 0);
  // некорректный план сам по себе не блокирует
  for (const plan of [undefined, null, {}, { minBytes: NaN, totalBytes: 1 }, { minBytes: -1, totalBytes: 1 }])
    assert.equal(assessStorage(plan, { quota: 1, usage: 0 }).status, 'unknown');
}

/* ---------- 7. нулевые и некорректные значения во входных данных ---------- */
{
  assert.throws(() => planStorageNeed({ files: null }), /Некорректный список/);
  assert.throws(() => planStorageNeed(), /Некорректный список/);
  const p = planStorageNeed({
    files: [f('ok', 100), f('neg', -1), f('nan', NaN), f('frac', 1.5), { path: 5, size: 1 }, null, f('zero', 0)],
    haveSizes: have({ ok: 'x', zero: 0 }), hadMarker: false, saveBytes: -7 });
  assert.equal(p.invalid, 5);
  assert.equal(p.writeBytes, 100, 'нулевой по размеру файл, которого нет, ничего не стоит');
  assert.equal(p.unchanged, 1);   // zero: 0 == 0
  assert.equal(p.backupReserveBytes, L.minBackupReserveBytes, 'некорректный размер SAVE -> минимум');
  assert.equal(planStorageNeed({ files: [], haveSizes: new Map() }).writeBytes, 0);
  // haveSizes не Map -> все файлы считаются отсутствующими (консервативно)
  assert.equal(planStorageNeed({ files: [f('a', 10)], haveSizes: { a: 10 }, hadMarker: true }).writeBytes, 10);
  // крупный SAVE увеличивает запас под restore point
  const big = planStorageNeed({ files: [f('a', 10)], haveSizes: new Map(), saveBytes: 50 * MiB });
  assert.equal(big.backupReserveBytes, 50 * MiB);
  assert.equal(assessStorage(planStorageNeed({ files: [f('a', 0)], haveSizes: new Map() }), { quota: 0, usage: 0 }).status,
    'ok', 'пустой файл не занимает места: писать нечего, бессмысленная квота не мешает');
}

/* ---------- 8. checkStorageForSync на синтетическом OPFS ---------- */
class Dir {
  dirs = new Map(); files = new Map(); reads = 0; writes = 0;
  async getDirectoryHandle(name, { create } = {}) {
    if (!this.dirs.has(name)) { if (!create) throw missing(); this.writes++; this.dirs.set(name, new Dir()); }
    return this.dirs.get(name);
  }
  async *entries() {
    for (const [n, data] of this.files) yield [n, { kind: 'file', getFile: async () => new Blob([data]) }];
    for (const [n, d] of this.dirs) yield [n, Object.assign(d, { kind: 'directory' })];
  }
}
const existingSizeOf = (root) => async (dir, rel) => {
  try {
    const parts = rel.split('/');
    let d = dir;
    for (const p of parts.slice(0, -1)) d = await d.getDirectoryHandle(p, { create: false });
    const data = d.files.get(parts.at(-1));
    return data === undefined ? -1 : data.length;
  } catch { return -1; }
};
{
  const game = new Dir();
  game.files.set('ENGINE.exe', new Uint8Array(30));
  const prog = await game.getDirectoryHandle('PROGRAM', { create: true });
  prog.files.set('a.c', new Uint8Array(40));
  const save = await game.getDirectoryHandle('SAVE', { create: true });
  save.files.set('slot1', new Uint8Array(2 * MiB));
  const sub = await save.getDirectoryHandle('slot2', { create: true });
  sub.files.set('shot', new Uint8Array(3 * MiB));
  game.writes = 0;
  assert.equal(await measureDirBytes(save), 5 * MiB);
  assert.equal(await measureDirBytes(null), 0);
  assert.equal(await measureDirBytes({ entries() { throw new Error('boom'); } }), 0);

  const files = [f('ENGINE.exe', 30), f('PROGRAM/a.c', 41)];   // a.c вырос на байт
  const calls = [];
  const r = await checkStorageForSync({ dir: game, files, hadMarker: true, existingSize: existingSizeOf(game),
    estimate: async () => { calls.push(1); return { quota: 100 * MiB, usage: 99 * MiB }; } });
  assert.notEqual(r.status, 'insufficient');
  assert.equal(r.plan.writeBytes, 41);
  assert.equal(r.plan.toDownload, 1);
  assert.equal(r.plan.backupReserveBytes, 8 * MiB, 'SAVE 5 МиБ < минимума 8 МиБ');
  assert.equal(r.free, 1 * MiB);
  assert.equal(calls.length, 1);
  assert.equal(game.writes, 0, 'проверка не создаёт каталоги');

  // тот же манифест, но каталога игры нет (чистая установка), estimate падает -> unknown, не отказ
  const fresh = await checkStorageForSync({ dir: null, files, hadMarker: false, existingSize: existingSizeOf(),
    estimate: async () => { throw new Error('estimate failed'); } });
  assert.equal(fresh.status, 'unknown');
  assert.equal(fresh.plan.fresh, true);
  assert.equal(fresh.plan.writeBytes, 71);
  // estimate вообще нет (старый браузер)
  assert.equal((await checkStorageForSync({ dir: null, files, hadMarker: false, existingSize: existingSizeOf(),
    estimate: undefined })).status, 'unknown');
  // estimate синхронно бросает
  assert.equal((await checkStorageForSync({ dir: null, files, hadMarker: false, existingSize: existingSizeOf(),
    estimate: () => { throw new TypeError('no storage'); } })).status, 'unknown');
  // сбой чтения размеров -> unknown с причиной, загрузку не блокирует
  const broken = await checkStorageForSync({ dir: game, files, hadMarker: true,
    existingSize: async () => { throw new Error('opfs read failed'); }, estimate: async () => ({ quota: 1, usage: 1 }) });
  assert.equal(broken.status, 'unknown');
  assert.match(broken.message, /opfs read failed/);
  // некорректный манифест отвергается так же, как при синхронизации (а не оценивается молча)
  await assert.rejects(() => checkStorageForSync({ dir: game, files: [f('x', -1)], hadMarker: false,
    existingSize: existingSizeOf(), estimate: async () => ({}) }), /Некорректный размер/);
  // пути SAVE в манифесте игнорируются и в оценке
  const withSave = await checkStorageForSync({ dir: null, files: [f('SAVE/slot1', 999), f('a', 5)], hadMarker: false,
    existingSize: existingSizeOf(), estimate: async () => ({ quota: 1e12, usage: 0 }) });
  assert.equal(withSave.plan.writeBytes, 5);
  assert.equal(withSave.status, 'ok');
}

// Brave's fixed privacy quota is an estimate, not proof that the real quota is 2 GiB.
{
  const fake = { quota: 2 ** 31, usage: 0 };
  const brave = { brave: { isBrave: async () => true } };
  const other = { brave: { isBrave: async () => false } };
  assert.equal(await isPrivacyCappedQuota(fake, brave), true);
  assert.equal(await isPrivacyCappedQuota({ quota: 3 * 2 ** 30, usage: 0 }, brave), false);
  assert.equal(await isPrivacyCappedQuota(fake, other), false);
  assert.equal(await isPrivacyCappedQuota(fake, { brave: { isBrave: async () => { throw Error('blocked'); } } }), false);
  const files = [f('RESOURCE/big.dat', 2352 * 1e6)];
  const opts = {dir: null, files, hadMarker: false, existingSize: existingSizeOf(), nav: brave};
  for (const usage of [0, 2 ** 31, 2400 * 1e6]) {
    const result = await checkStorageForSync({ ...opts, estimate: async () => ({ ...fake, usage }) });
    assert.equal(result.status, 'unknown');
    assert.equal(result.free, null, 'the reported quota is not usable to infer free space');
    assert.match(result.message, /скрывает фактическую квоту/);
  }
  const real = await checkStorageForSync({ ...opts, nav: other, estimate: async () => fake });
  assert.equal(real.status, 'insufficient', 'non-Brave genuine low quota still blocks the install');
}

console.log('storage estimate (planStorageNeed / assessStorage / checkStorageForSync): PASS');
