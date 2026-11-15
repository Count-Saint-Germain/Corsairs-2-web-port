import test from 'node:test';
import assert from 'node:assert/strict';
import { buildInput, summarize } from './heap_scenario.mjs';

test('idle and reload scenarios preserve their input sequence', () => {
  assert.match(buildInput('idle', 20000, 4000), /^300:key=1c,700:key=39/);
  assert.match(buildInput('reload', 9000, 4000, true), /4000:key=3b,4300:key=1c/);
  assert.throws(() => buildInput('reload', 9000, 0), /positive/);
});
test('heap and other statistics are associated with the latest frame', () => {
  const rows = summarize('[fps] 60.0 (frame 123, x\n[heapstats] extent=100 KB (high-water 110 KB) live=12 blocks 90 KB (requested 80 KB, high-water 100 KB) free-inside=3 blocks 10 KB largest-free=8 KB bad=0\n[dsstats] buffers=1 (high-water 2) secondary=3 playing=4 pcm-storages=5 pcm=6 KB (high-water 7 KB)\n');
  assert.equal(rows.length, 1); assert.equal(rows[0].frame, 123); assert.equal(rows[0].largest, 8); assert.equal(rows[0].ds_pcm, 6);
});
