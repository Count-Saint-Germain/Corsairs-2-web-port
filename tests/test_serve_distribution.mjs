import test, { before, after } from 'node:test';
import assert from 'node:assert/strict';
import { promises as fs } from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import http from 'node:http';
import { once } from 'node:events';
import { createDistributionServer } from '../scripts/serve_distribution.mjs';

let directory, outside, server, base;
before(async () => {
  directory = await fs.mkdtemp(path.join(os.tmpdir(), 'k2-distribution-test-'));
  outside = await fs.mkdtemp(path.join(os.tmpdir(), 'k2-outside-test-'));
  await Promise.all([
    fs.writeFile(path.join(directory, 'index.html'), 'ready'),
    fs.writeFile(path.join(directory, 'test.wasm'), '0123456789'),
    fs.writeFile(path.join(directory, 'test.mjs'), 'export {}'),
    fs.writeFile(path.join(directory, 'test.mp4'), 'video'),
    fs.writeFile(path.join(directory, 'empty'), ''),
    fs.writeFile(path.join(outside, 'secret'), 'outside'),
  ]);
  await fs.symlink(path.join(outside, 'secret'), path.join(directory, 'outside-link'));
  server = await createDistributionServer(directory);
  server.listen(0, '127.0.0.1');
  await once(server, 'listening');
  base = `http://127.0.0.1:${server.address().port}`;
});
after(async () => {
  if (server) { server.close(); await once(server, 'close'); }
  if (directory) await fs.rm(directory, { recursive: true, force: true });
  if (outside) await fs.rm(outside, { recursive: true, force: true });
});

function rawRequest(requestPath, options = {}) {
  return new Promise((resolve, reject) => {
    const u = new URL(base);
    const req = http.request({ hostname: u.hostname, port: u.port, path: requestPath, ...options }, res => {
      const chunks = [];
      res.on('data', c => chunks.push(c));
      res.on('end', () => resolve({ status: res.statusCode, headers: res.headers, body: Buffer.concat(chunks).toString() }));
    });
    req.on('error', reject); req.end();
  });
}

test('serves index and correct headers and MIME types', async () => {
  const index = await rawRequest('/');
  assert.equal(index.status, 200); assert.equal(index.body, 'ready');
  for (const [file, mime] of [['test.wasm', 'application/wasm'], ['test.mjs', 'text/javascript'], ['test.mp4', 'video/mp4']]) {
    const res = await rawRequest('/' + file);
    assert.equal(res.headers['content-type'], mime);
    assert.equal(res.headers['cross-origin-opener-policy'], 'same-origin');
    assert.equal(res.headers['cross-origin-embedder-policy'], 'require-corp');
    assert.equal(res.headers['cross-origin-resource-policy'], 'same-origin');
    assert.equal(res.headers['accept-ranges'], 'bytes');
  }
});

test('single ranges, suffix and open-ended ranges, and HEAD', async () => {
  for (const [range, body, contentRange] of [['bytes=2-5', '2345', 'bytes 2-5/10'], ['bytes=7-', '789', 'bytes 7-9/10'], ['bytes=-3', '789', 'bytes 7-9/10']]) {
    const r = await rawRequest('/test.wasm', { headers: { range } });
    assert.equal(r.status, 206); assert.equal(r.body, body); assert.equal(r.headers['content-range'], contentRange);
    const h = await rawRequest('/test.wasm', { method: 'HEAD', headers: { range } });
    assert.equal(h.status, 206); assert.equal(h.headers['content-length'], String(body.length)); assert.equal(h.body, '');
  }
  for (const range of ['bytes=20-', 'bytes=-0', 'bytes=9-3', 'bytes=foo']) {
    const r = await rawRequest('/test.wasm', { headers: { range } });
    assert.equal(r.status, 416); assert.equal(r.headers['content-range'], 'bytes */10');
  }
  assert.equal((await rawRequest('/empty', { headers: { range: 'bytes=0-' } })).status, 416);
  const multi = await rawRequest('/test.wasm', { headers: { range: 'bytes=0-1,4-5' } });
  assert.equal(multi.status, 200); assert.equal(multi.body, '0123456789');
});

test('404 and malformed paths retain isolation and do not expose external files', async () => {
  for (const name of ['/missing', '/outside-link', '/%2e%2e/secret', '/%5coutside-link', '/%00', '/%ff']) {
    const r = await rawRequest(name);
    assert.ok(r.status >= 400, `${name} unexpectedly returned ${r.status}`);
    assert.equal(r.headers['cross-origin-opener-policy'], 'same-origin');
    assert.equal(r.headers['cross-origin-embedder-policy'], 'require-corp');
    assert.notEqual(r.body, 'outside');
  }
});

test('HEAD, conditional GET and method handling', async () => {
  const r = await rawRequest('/test.wasm');
  const h = await rawRequest('/test.wasm', { method: 'HEAD' });
  assert.equal(h.status, 200); assert.equal(h.headers['content-length'], '10'); assert.equal(h.body, '');
  const notModified = await rawRequest('/test.wasm', { headers: { 'if-modified-since': r.headers['last-modified'] } });
  assert.equal(notModified.status, 304); assert.equal(notModified.body, '');
  const badMethod = await rawRequest('/test.wasm', { method: 'POST' });
  assert.equal(badMethod.status, 405); assert.equal(badMethod.headers['cross-origin-opener-policy'], 'same-origin');
});
