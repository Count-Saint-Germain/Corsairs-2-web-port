import test from 'node:test';
import assert from 'node:assert/strict';
import { spawn, spawnSync } from 'node:child_process';
import { once } from 'node:events';
import os from 'node:os';
import { fileURLToPath } from 'node:url';

const launcher = fileURLToPath(new URL('../play.js', import.meta.url));

test('launcher serves the distribution with isolation headers and byte ranges', async () => {
  // Starting outside the checkout verifies that the distribution path is
  // relative to the script rather than the caller's working directory.
  const child = spawn(process.execPath, [launcher, '--port', '0'], { cwd: os.tmpdir(), stdio: ['ignore', 'pipe', 'pipe'] });
  let output = '';
  try {
    const port = await new Promise((resolve, reject) => {
      const timer = setTimeout(() => reject(new Error(`server did not start: ${output}`)), 15000);
      const finish = (error, value) => { clearTimeout(timer); error ? reject(error) : resolve(value); };
      child.once('error', error => finish(error));
      child.once('exit', code => finish(new Error(`server exited ${code}: ${output}`)));
      child.stderr.on('data', chunk => { output += chunk; });
      child.stdout.on('data', chunk => {
        output += chunk;
        const match = output.match(/http:\/\/127\.0\.0\.1:(\d+)\//);
        if (match) finish(null, Number(match[1]));
      });
    });
    const base = `http://127.0.0.1:${port}`;
    const page = await fetch(base);
    assert.equal(page.status, 200);
    assert.match(await page.text(), /<html/i);
    assert.equal(page.headers.get('cross-origin-opener-policy'), 'same-origin');
    assert.equal(page.headers.get('cross-origin-embedder-policy'), 'require-corp');
    const range = await fetch(`${base}/game/manifest.json`, { headers: { range: 'bytes=0-15' } });
    assert.equal(range.status, 206);
    assert.equal((await range.arrayBuffer()).byteLength, 16);
    assert.match(range.headers.get('content-range'), /^bytes 0-15\//);
  } finally {
    if (child.exitCode === null && child.signalCode === null) {
      const exited = once(child, 'exit'); child.kill(); await exited;
    }
  }
});

test('launcher forwards arguments and rejects an invalid port', () => {
  const help = spawnSync(process.execPath, [launcher, '--help'], { encoding: 'utf8' });
  assert.equal(help.status, 0); assert.match(help.stdout, /--port/);
  const invalid = spawnSync(process.execPath, [launcher, '--port', 'not-a-port'], { encoding: 'utf8' });
  assert.notEqual(invalid.status, 0); assert.match(invalid.stderr, /invalid port/);
});
