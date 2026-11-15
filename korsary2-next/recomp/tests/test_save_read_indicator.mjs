import { test } from 'node:test';
import assert from 'node:assert/strict';
import { createSaveReadIndicatorState, installSaveReadIndicator } from '../web/save-read-indicator.mjs';

test('shows sustained completed reads and hides after inactivity', () => {
  const step = createSaveReadIndicatorState();
  assert.equal(step(0), false);
  assert.equal(step(31), false);
  assert.equal(step(63), false);
  assert.equal(step(95), true);
  assert.equal(step(96), true);
  assert.equal(step(96), false);
  assert.equal(step(128), false);
  assert.equal(step(160), true);
});
test('counter wrap and installation keep the indicator non-interactive', () => {
  const step = createSaveReadIndicatorState();
  step(0xfffffff0);
  assert.equal(step(0x10), false);
  assert.equal(step(0x30), true);
  let callback, period, hidden = true, count = 0;
  const element = {classList: {toggle(name, value) { assert.equal(name, 'hidden'); hidden = value; }}};
  installSaveReadIndicator(element, () => count, (fn, ms) => { callback = fn; period = ms; });
  assert.equal(period, 1000);
  count = 32; callback(); assert.equal(hidden, true);
  count = 64; callback(); assert.equal(hidden, false);
  callback(); callback(); assert.equal(hidden, true);
});
