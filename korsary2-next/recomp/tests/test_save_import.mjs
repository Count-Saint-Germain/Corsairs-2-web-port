import assert from 'node:assert/strict';
import { crc32, encodeBackup, decodeBackup, key, LIMITS, MAX_ARCHIVE } from '../web/save-export.mjs';
import { bytesEqual, planRestore, planMetaRestore, planLangRestore } from '../web/save-import.mjs';

const enc = new TextEncoder();

// A minimal writer for adversarial archives: same layout as encodeBackup, but
// every field the decoder checks can be broken on purpose.
function buildZip(items, opts = {}) {
  const w16 = (v, o, n) => v.setUint16(o, n, true), w32 = (v, o, n) => v.setUint32(o, n >>> 0, true);
  const recs = items.map((it) => {
    const p = enc.encode(it.localPath ?? it.path), cp = enc.encode(it.centralPath ?? it.path);
    return { ...it, p, cp, crc: it.crc ?? crc32(it.bytes) };
  });
  let local = 0, central = 0;
  for (const r of recs) { local += 30 + r.p.length + r.bytes.length; central += 46 + r.cp.length; }
  const out = new Uint8Array(local + central + 22), v = new DataView(out.buffer);
  let off = 0;
  for (const r of recs) {
    r.offset = off;
    w32(v, off, 0x04034b50); w16(v, off + 4, 20); w16(v, off + 6, r.flags ?? 0x800); w16(v, off + 8, r.method ?? 0);
    w16(v, off + 10, 0); w16(v, off + 12, 0x21); w32(v, off + 14, r.crc); w32(v, off + 18, r.bytes.length);
    w32(v, off + 22, r.bytes.length); w16(v, off + 26, r.p.length); w16(v, off + 28, 0);
    out.set(r.p, off + 30); out.set(r.bytes, off + 30 + r.p.length);
    off += 30 + r.p.length + r.bytes.length;
  }
  const cd = off;
  for (const r of recs) {
    w32(v, off, 0x02014b50); w16(v, off + 4, 20); w16(v, off + 6, 20); w16(v, off + 8, r.flags ?? 0x800);
    w16(v, off + 10, r.method ?? 0); w16(v, off + 12, 0); w16(v, off + 14, 0x21); w32(v, off + 16, r.crc);
    w32(v, off + 20, r.bytes.length); w32(v, off + 24, r.bytes.length); w16(v, off + 28, r.cp.length);
    w16(v, off + 30, 0); w16(v, off + 32, 0); w16(v, off + 34, 0); w16(v, off + 36, 0); w32(v, off + 38, 0);
    w32(v, off + 42, r.offset);
    out.set(r.cp, off + 46); off += 46 + r.cp.length;
  }
  w32(v, off, 0x06054b50); w16(v, off + 4, 0); w16(v, off + 6, 0);
  w16(v, off + 8, recs.length); w16(v, off + 10, recs.length);
  w32(v, off + 12, central); w32(v, off + 16, cd); w16(v, off + 20, 0);
  if (opts.bumpCount) { w16(v, out.length - 22 + 8, opts.bumpCount); w16(v, out.length - 22 + 10, opts.bumpCount); }
  return out;
}
function emptyZip() {
  const out = new Uint8Array(22), v = new DataView(out.buffer);
  v.setUint32(0, 0x06054b50, true);
  return out;
}
const bytes = (s) => enc.encode(s);

// ---- round trip: decode(encode) is the identity on the entry list ----
const fixtures = [
  { name: 'Тест.sav', bytes: bytes('пираты и корсары') },
  { name: 'slot2', bytes: new Uint8Array([0, 1, 255, 128, 0]) },
  { name: 'Sea Dogs II — сохранение 3.sav', bytes: bytes('\x00\x01binary-ish') },
];
const time = new Uint8Array([0x21, 0x43, 0x65, 0x87, 0, 0, 0x10, 0]);
const roundTrip = decodeBackup(encodeBackup(fixtures));
assert.deepEqual(roundTrip.entries, fixtures);
assert.deepEqual(roundTrip.meta, []);
assert.deepEqual(roundTrip.ignored, []);
assert.deepEqual(decodeBackup(buildZip([{ path: 'SAVE/x.sav', bytes: bytes('data') }])).entries,
  [{ name: 'x.sav', bytes: bytes('data') }]);
// one SAVE_META record per slot travels with the slot bytes
const metaArchive = encodeBackup([
  { name: 'slot1', bytes: bytes('one'), meta: time },
  { name: 'plain', bytes: bytes('two') },            // no record: none is written
]);
const metaTrip = decodeBackup(metaArchive);
assert.deepEqual(metaTrip.entries, [{ name: 'slot1', bytes: bytes('one') }, { name: 'plain', bytes: bytes('two') }]);
assert.deepEqual(metaTrip.meta, [{ name: 'slot1', bytes: time }]);
assert.deepEqual(metaTrip.ignored, []);

// ---- empty archive decodes to no entries ----
assert.deepEqual(decodeBackup(emptyZip()), { entries: [], meta: [], lang: [], ignored: [] });

// ---- existing export behaviour is untouched ----
assert.throws(() => encodeBackup([]), /Нет файлов/);
assert.throws(() => encodeBackup([{ name: 'a', bytes: bytes('1') }, { name: 'A', bytes: bytes('2') }]), /повтор/);

// ---- malformed input ----
assert.throws(() => decodeBackup(new Uint8Array(0)), /не архив/);
assert.throws(() => decodeBackup(bytes('not a zip at all, really')), /не архив|поврежд/);
assert.throws(() => decodeBackup(encodeBackup(fixtures).slice(0, encodeBackup(fixtures).length - 10)), /поврежд/);
const valid = encodeBackup(fixtures);
const badData = valid.slice();
badData[30 + 5 + 3] ^= 0xff;   // flip a byte inside the first file's data
assert.throws(() => decodeBackup(badData), /поврежд|контрольн/);
const badCrc = buildZip([{ path: 'SAVE/a', bytes: bytes('abc'), crc: 0xdeadbeef }]);
assert.throws(() => decodeBackup(badCrc), /поврежд|контрольн/);
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('abc'), method: 8 }])), /сжат/);
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('abc'), flags: 0x801 }])), /зашифров|потоково/);
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('abc'), crc: crc32(bytes('xyz')) }])), /поврежд/);
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('abc'), localPath: 'SAVE/b' }])), /поврежд/);
// data that reaches into the central directory (csize lies) must be caught
const lyingSize = buildZip([{ path: 'SAVE/a', bytes: bytes('abc') }]);
{
  const v = new DataView(lyingSize.buffer);
  const csize = v.getUint32(18, true);
  v.setUint32(18, csize + 1000, true);            // local csize
  const eocd = lyingSize.length - 22, cdOff = v.getUint32(eocd + 16, true);
  v.setUint32(cdOff + 20, csize + 1000, true);    // central csize
  const crc = crc32(lyingSize.slice(30, 30 + 3 + 1000));
  v.setUint32(14, crc, true); v.setUint32(cdOff + 16, crc, true);
  assert.throws(() => decodeBackup(lyingSize), /поврежд/);
}
// more entries than LIMITS.entries declared in the end record; also, more SAVE
// slots than LIMITS.files are rejected even inside the total entry bound
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('a') }], { bumpCount: LIMITS.entries + 1 })), /слишком много/);
{
  const many = [];
  for (let i = 0; i < LIMITS.files + 1; i++) many.push({ path: `SAVE/s${i}`, bytes: bytes('a') });
  assert.throws(() => decodeBackup(buildZip(many)), /слишком много/);
  many.pop();
  many.push({ path: 'SAVE_META/s.time', bytes: time });   // records + slots fit together
  assert.deepEqual(decodeBackup(buildZip(many)).meta.length, 1);
}
// bogus UTF-8 in a name
{
  const z = buildZip([{ path: 'SAVE/a', bytes: bytes('a') }]);
  const idx = z.length - 22 - 46 - 5;             // central directory name bytes
  z[idx] = 0xff; z[idx + 1] = 0xfe;
  assert.throws(() => decodeBackup(z), /UTF-8|поврежд/);
}

// ---- junk outside SAVE is ignored, unsafe names inside SAVE are rejected ----
{
  const r = decodeBackup(buildZip([
    { path: 'RESOURCE/INI/evil.ini', bytes: bytes('x') },
    { path: 'ENGINE.exe', bytes: bytes('x') },
    { path: 'SAVE/ok.sav', bytes: bytes('keep') },
  ]));
  assert.deepEqual(r.entries, [{ name: 'ok.sav', bytes: bytes('keep') }]);
  assert.deepEqual(r.ignored, ['RESOURCE/INI/evil.ini', 'ENGINE.exe']);
}
for (const bad of ['SAVE/../evil', 'SAVE/sub/x', 'SAVE/.hidden', 'SAVE/..', 'SAVE/.', 'SAVE/trailing.', 'SAVE/com1',
                   'SAVE/' + 'x'.repeat(LIMITS.nameBytes + 1)])
  assert.throws(() => decodeBackup(buildZip([{ path: bad, bytes: bytes('x') }])), /недопустимое имя|скрытое имя/,
    `expected rejection for ${bad}`);
// duplicate names, including case-insensitive and NFC-equivalent collisions
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('1') }, { path: 'SAVE/a', bytes: bytes('2') }])), /повтор/);
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/A.sav', bytes: bytes('1') }, { path: 'SAVE/a.sav', bytes: bytes('2') }])), /повтор/);
assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE/cafe\u0301', bytes: bytes('1') }, { path: 'SAVE/caf\u00e9', bytes: bytes('2') }])), /повтор/);

// ---- bytesEqual ----
assert.equal(bytesEqual(bytes('same'), bytes('same')), true);
assert.equal(bytesEqual(bytes('same'), bytes('other')), false);
assert.equal(bytesEqual(bytes('same'), bytes('same!')), false);
assert.equal(bytesEqual(null, bytes('x')), false);
assert.equal(bytesEqual(bytes('x'), null), false);

// ---- SAVE_META records are whitelisted exactly like SAVE slots ----
{
  // a record whose slot is absent from the archive still decodes (pairing is
  // the importer's job), and non-.time names under SAVE_META/ are junk
  const r = decodeBackup(buildZip([
    { path: 'SAVE_META/orphan.time', bytes: time },
    { path: 'SAVE_META/not-a-record', bytes: bytes('x') },
    { path: 'SAVE/ok.sav', bytes: bytes('keep') },
  ]));
  assert.deepEqual(r.meta, [{ name: 'orphan', bytes: time }]);
  assert.deepEqual(r.ignored, ['SAVE_META/not-a-record']);
  // malformed record names are rejected with the same name rules as slots
  for (const bad of ['SAVE_META/../evil.time', 'SAVE_META/sub/x.time', 'SAVE_META/.hidden.time',
                     'SAVE_META/com1.time', 'SAVE_META/.time', 'SAVE_META/trailing..time'])
    assert.throws(() => decodeBackup(buildZip([{ path: bad, bytes: time }])), /недопустимое имя|скрытое имя/,
      `expected rejection for ${bad}`);
  // a record must be exactly 8 bytes
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.time', bytes: bytes('1234567') }])), /поврежд/);
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.time', bytes: bytes('123456789') }])), /поврежд/);
  // shared record checks apply: compression, CRC, duplicate names
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.time', bytes: time, method: 8 }])), /сжат/);
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.time', bytes: time, crc: 0xdeadbeef }])), /поврежд|контрольн/);
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.time', bytes: time }, { path: 'SAVE_META/A.time', bytes: time }])), /повтор/);
  // an emptied record (8 zero bytes) is valid data meaning "unknown"
  assert.deepEqual(decodeBackup(buildZip([{ path: 'SAVE_META/z.time', bytes: new Uint8Array(8) }])).meta,
    [{ name: 'z', bytes: new Uint8Array(8) }]);
}

// ---- E5: SAVE_META/<name>.lang language labels: strict names, exactly two bytes, exactly "en" or "ru" ----
{
  const en = bytes('en'), ru = bytes('ru');
  const r = decodeBackup(buildZip([{ path: 'SAVE/a', bytes: bytes('x') }, { path: 'SAVE_META/a.lang', bytes: en }, { path: 'SAVE_META/a.time', bytes: time },
    { path: 'SAVE/b', bytes: bytes('y') }, { path: 'SAVE_META/b.lang', bytes: ru }]));
  assert.deepEqual(r.lang, [{ name: 'a', bytes: en }, { name: 'b', bytes: ru }]); assert.deepEqual(r.meta, [{ name: 'a', bytes: time }]); assert.deepEqual(r.ignored, []);
  for (const bad of ['SAVE_META/../evil.lang', 'SAVE_META/sub/x.lang', 'SAVE_META/.hidden.lang', 'SAVE_META/com1.lang', 'SAVE_META/.lang', 'SAVE_META/trailing..lang'])
    assert.throws(() => decodeBackup(buildZip([{ path: bad, bytes: en }])), /недопустимое имя|скрытое имя/, `expected rejection for ${bad}`);
  for (const badBytes of ['e', 'eng', '', 'xx', 'EN', 'En'])   // a label is exactly two valid bytes
    assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.lang', bytes: bytes(badBytes) }])), /поврежд/, `label ${JSON.stringify(badBytes)}`);
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.lang', bytes: en, method: 8 }])), /сжат/);
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.lang', bytes: en, crc: 0xdeadbeef }])), /поврежд|контрольн/);
  assert.throws(() => decodeBackup(buildZip([{ path: 'SAVE_META/a.lang', bytes: en }, { path: 'SAVE_META/A.lang', bytes: en }])), /повтор/);
  // a label and a time record of the same slot are two records, not duplicates; a label of a slot not in the archive is ignored on import
  assert.equal(decodeBackup(buildZip([{ path: 'SAVE_META/a.lang', bytes: en }, { path: 'SAVE_META/a.time', bytes: time }])).lang.length, 1);
  // 512 slots with a time record and a label each are 1536 ZIP records: inside LIMITS.entries
  const full = [];
  for (let i = 0; i < LIMITS.files; i++) full.push({ path: `SAVE/s${i}`, bytes: bytes('a') }, { path: `SAVE_META/s${i}.time`, bytes: time }, { path: `SAVE_META/s${i}.lang`, bytes: en });
  const big = decodeBackup(buildZip(full));
  assert.deepEqual([big.entries.length, big.meta.length, big.lang.length], [LIMITS.files, LIMITS.files, LIMITS.files]);
  assert.ok(LIMITS.entries >= 3 * LIMITS.files);
  // planLangRestore follows planMetaRestore's rules
  const writes = [{ name: 'Slot', bytes: bytes('n') }, { name: 'Bare', bytes: bytes('n') }];
  const plan = planLangRestore([{ name: 'slot', bytes: en }, { name: 'bad', bytes: bytes('xx') }, { name: 'Bare', bytes: bytes('zz') }], writes,
    ['slot.lang', 'Slot.time', 'Bare.lang', 'other.lang', 'bare.lang']);
  assert.deepEqual(plan.put, [{ name: 'Slot.lang', bytes: en }]);
  assert.deepEqual(plan.remove.sort(), ['Bare.lang', 'bare.lang', 'slot.lang']);   // stale label of a replaced slot with no valid archive label goes; other letter case goes
  assert.deepEqual(planLangRestore([], [], ['a.lang']), { put: [], remove: [] });
  assert.deepEqual(planLangRestore(undefined, undefined, undefined), { put: [], remove: [] });
  assert.deepEqual(planMetaRestore([{ name: 'a', bytes: time }], [{ name: 'a', bytes: bytes('n') }], ['a.lang', 'a.time']), { put: [{ name: 'a.time', bytes: time }], remove: [] },
    'the time plan does not touch label files');
}

// ---- planRestore: the conflict policy on plain arrays ----
const current = [{ name: 'slot1', bytes: bytes('old data') }, { name: 'SAME.SAV', bytes: bytes('identical') }, { name: 'broken', bytes: null }];
{
  const plan = planRestore([
    { name: 'slot1', bytes: bytes('new data') },      // differs -> conflict
    { name: 'same.sav', bytes: bytes('identical') },  // same bytes (case-insensitive key) -> skip
    { name: 'fresh.sav', bytes: bytes('new file') },  // absent -> restore
    { name: 'broken', bytes: bytes('anything') },     // unreadable existing -> conflict, never overwrite
  ], current);
  assert.deepEqual(plan.restore, [{ name: 'fresh.sav', bytes: bytes('new file') }]);
  assert.deepEqual(plan.identical, ['same.sav']);
  assert.equal(plan.conflicts.length, 2);
  assert.deepEqual(plan.conflicts[0], { name: 'slot1', existingName: 'slot1', archiveBytes: bytes('new data'), existingBytes: bytes('old data') });
  assert.equal(plan.conflicts[1].name, 'broken');
  assert.equal(plan.conflicts[1].existingBytes, null);
  // no decision yet: the caller must write nothing
  assert.equal(plan.conflicts.some((c) => c.name === 'slot1' && bytesEqual(c.archiveBytes, bytes('old data'))), false);
}
// empty SAVE: everything is new
assert.deepEqual(planRestore([{ name: 'a', bytes: bytes('1') }], []),
  { restore: [{ name: 'a', bytes: bytes('1') }], conflicts: [], identical: [] });
// duplicate archive entries are rejected here too (decodeBackup already guards)
assert.throws(() => planRestore([{ name: 'a', bytes: bytes('1') }, { name: 'A', bytes: bytes('2') }]), /повтор/);
// archive entry names must pass the same validation as export
assert.throws(() => planRestore([{ name: '../a', bytes: bytes('1') }]), /имя/);
// key() agrees with the exporter on Unicode normalization
assert.equal(key('Caf\u00e9'), key('cafe\u0301'));

// ---- planMetaRestore: records follow their slot's write decision ----
{
  const archiveMeta = [
    { name: 'slot1', bytes: time },                                  // restore target has a record
    { name: 'replaced', bytes: new Uint8Array([1, 1, 1, 1, 1, 1, 1, 1]) },  // conflict target has one
    { name: 'plain', bytes: time },                                  // no such SAVE entry: unpaired
  ];
  const writes = [
    { name: 'slot1', bytes: bytes('new') },                          // restore
    { name: 'replaced', bytes: bytes('new') },                       // replace (choice='replace')
    { name: 'fresh', bytes: bytes('new') },                          // restore without a record
  ];
  const existing = ['slot1.time', 'OLD.time', 'Fresh.time', 'skipped.time', 'sub.time', 'identical.time', 'notarecord'];
  const plan = planMetaRestore(archiveMeta, writes, existing);
  // only slots actually being written get records; identical/skipped keep theirs
  assert.deepEqual(plan.put, [
    { name: 'slot1.time', bytes: time },
    { name: 'replaced.time', bytes: archiveMeta[1].bytes },
  ]);
  // 'fresh' is written without a record: every spelling of its record must go;
  // 'slot1' keeps its exact spelling (the write replaces it in place);
  // 'skipped', 'identical', unwritten 'OLD' and unrelated names are never touched
  assert.deepEqual(plan.remove, ['Fresh.time']);
  // no writes at all (identical-only or empty plan): nothing to do
  assert.deepEqual(planMetaRestore(archiveMeta, [], existing), { put: [], remove: [] });
  // no archive records: every written slot's local record is stripped — the new
  // bytes must never inherit the old time (slot1 is restored, fresh is new,
  // replaced is rewritten)
  assert.deepEqual(planMetaRestore([], writes, existing),
    { put: [], remove: ['slot1.time', 'Fresh.time'] });
  // malformed plan input is ignored, never thrown or restored
  assert.deepEqual(planMetaRestore([null, { name: 42, bytes: time }, { name: 'x', bytes: bytes('7') }], writes, [null, 7]),
    { put: [], remove: [] });
  // a record under a different case than the slot being written is removed too
  assert.deepEqual(planMetaRestore([], [{ name: 'Fresh', bytes: bytes('n') }], ['fresh.time']),
    { put: [], remove: ['fresh.time'] });
}

// MAX_ARCHIVE is the bound the launcher applies before reading a picked file
assert.ok(MAX_ARCHIVE > LIMITS.total);
console.log('decodeBackup round-trip + planRestore conflict policy: PASS');
