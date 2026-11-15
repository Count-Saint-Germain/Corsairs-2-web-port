import assert from 'node:assert/strict';
import { createHash, randomBytes } from 'node:crypto';
import { planFileUpdate, sha256Init, sha256Update, sha256Hex } from '../web/save-protection.mjs';

// planFileUpdate: the sync decision table.
assert.equal(planFileUpdate(-1, 100, false), 'rewrite');   // absent
assert.equal(planFileUpdate(100, 100, true), 'verify');    // complete: verify when possible
assert.equal(planFileUpdate(100, 100, false), 'verify');
assert.equal(planFileUpdate(40, 100, false), 'resume');    // own partial download
assert.equal(planFileUpdate(40, 100, true), 'rewrite');    // old install: server content changed
assert.equal(planFileUpdate(120, 100, true), 'rewrite');   // larger stale file: never append
assert.equal(planFileUpdate(120, 100, false), 'rewrite');
assert.equal(planFileUpdate(0, 100, true), 'rewrite');
assert.equal(planFileUpdate(0, 100, false), 'rewrite');    // nothing to resume
assert.equal(planFileUpdate(Number.NaN, 1, true), 'rewrite');

// sha256 vs node:crypto on vectors and random chunked input.
function digest(bytes) { return createHash('sha256').update(bytes).digest('hex'); }
assert.equal(sha256Hex(sha256Update(sha256Init(), new Uint8Array(0))), digest(Buffer.alloc(0)));
assert.equal(sha256Hex(sha256Update(sha256Init(), new Uint8Array([0x61]))), digest(Buffer.from('a')));
const abc = sha256Init();
sha256Update(abc, new Uint8Array([0x61, 0x62]));
sha256Update(abc, new Uint8Array([0x63]));
assert.equal(sha256Hex(abc), digest(Buffer.from('abc')));
for (const size of [64, 65, 127, 128, 129, 1000, 65537]) {
  const data = randomBytes(size);
  const st = sha256Init();
  for (let off = 0; off < size; off += 13) sha256Update(st, data.subarray(off, Math.min(size, off + 13)));
  assert.equal(sha256Hex(st), digest(data), `chunked digest mismatch at ${size}`);
}
// The one-million-'a' vector from the spec, fed in odd chunks.
const st = sha256Init();
const block = Buffer.alloc(1000, 0x61);
for (let i = 0; i < 1000; i++) sha256Update(st, new Uint8Array(block));
const million = createHash('sha256').update(Buffer.alloc(1000000, 0x61)).digest('hex');
assert.equal(sha256Hex(st), million);
console.log('planFileUpdate + sha256: PASS');
