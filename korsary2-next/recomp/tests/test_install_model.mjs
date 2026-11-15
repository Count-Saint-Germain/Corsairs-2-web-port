import test from 'node:test';
import assert from 'node:assert/strict';
import { simulate, requestSizes, histogram } from '../web/install_model.mjs';

const close = (a, b) => assert.ok(Math.abs(a - b) < 1e-8, `${a} != ${b}`);
test('network model matches closed forms and handles empty requests', () => {
  const mb = 1_000_000;
  close(simulate(Array(10).fill(mb), .1, mb), 11);
  close(simulate(Array(10).fill(mb), .1, mb, 10), 10.1);
  close(simulate(Array(10).fill(mb), .1, mb, 5), 10.2);
  close(simulate(Array(10).fill(0), .1, mb, 2), .5);
  close(simulate([mb], .1, mb, 4, 2), 1.2);
  assert.equal(simulate([], .1, mb, 3), 0);
  const sizes = Array.from({length: 200}, (_, i) => ((i * 3779) % 899000) + 1000);
  const times = [1,2,4,8,16].map(n => simulate(sizes, .08, 3*mb, n));
  assert.deepEqual(times, [...times].sort((a,b) => b-a));
  for (const bad of [() => simulate([1], .1, 0), () => simulate([1], .1, mb, 0), () => simulate([-1], .1, mb)]) assert.throws(bad, RangeError);
});
test('request order and packs match publisher rules', () => {
  const rows = [['a/1',10,4],['a/2',10,5],['options',5,5],['b/3',99,50],['c/4',99,90]];
  assert.deepEqual(requestSizes(rows), [4,5,50,90,5]);
  assert.deepEqual(requestSizes(rows, [60,100]).sort((a,b)=>a-b), [5,59,90]);
});
test('histogram boundaries cover the entire input once', () => {
  const sizes = [0,5000,70000,5<<20,30<<20];
  const h = histogram(sizes);
  assert.equal(h.reduce((a,r)=>a+r[1],0), sizes.length);
  assert.equal(h.reduce((a,r)=>a+r[2],0), sizes.reduce((a,b)=>a+b,0));
  assert.deepEqual(h[0], ['0 KiB..<1 KiB',1,0]);
  assert.deepEqual(h.at(-1), ['16 MiB..inf',1,30<<20]);
});
