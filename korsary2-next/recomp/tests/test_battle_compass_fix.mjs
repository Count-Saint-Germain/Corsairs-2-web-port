import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import { fileURLToPath } from 'node:url';
import { fixFunction } from '../translator/fix_battle_compass.mjs';

const file = fileURLToPath(new URL('../out_all/MODULES_battle_interface_000.c', import.meta.url));
const source = fs.readFileSync(file, 'utf8');
const match = source.match(/^void f_00b6cab0\(CPU \*c\) \{[^\n]*\n[\s\S]*?^\}/m);
const original = '    { uint32_t v_ = 0x390u; PUSH32(c, v_); } /* push 0x390 */';
const fixed = '    { uint32_t v_ = 0x3a8u; PUSH32(c, v_); } /* sea HUD: 39 vertices, 24 bytes each */';

test('sea HUD allocation covers the last vertex writes and fix is idempotent', () => {
  assert.ok(match);
  const fn = match[0];
  assert.ok(source.includes('WF32((uint32_t)(c->edx + 0x3a4u)'));
  assert.equal(0x3a4 + 4, 39 * 24);
  const unpatched = fn.replace(fixed, original);
  assert.notEqual(unpatched, fn);
  assert.equal(fixFunction(unpatched), fn);
  assert.equal(fixFunction(fn), fn);
  assert.throws(() => fixFunction(unpatched.replace('0x390u', '0x391u')), /unexpected/);
});
