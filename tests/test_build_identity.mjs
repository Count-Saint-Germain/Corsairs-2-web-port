// Build identity (docs/defensive-lifetime-plan.md, layer 1): the committed
// distribution/build/identity.json must describe the actual shipped bytes. A stale
// file fails here loudly — regenerate with:
//
//   node scripts/make_build_identity.mjs
//
import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { fileURLToPath } from 'node:url';
import { computeIdentity } from '../scripts/make_build_identity.mjs';

const ROOT = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const BUILD = path.join(ROOT, 'distribution', 'build');

const sha = (file) => createHash('sha256').update(fs.readFileSync(file)).digest('hex');

test('distribution/build/identity.json exists and matches the shipped bytes', async () => {
  const identity = JSON.parse(await fs.promises.readFile(path.join(BUILD, 'identity.json'), 'utf8'));
  assert.equal(identity.schema, 1);
  assert.equal(identity.gameWasmSha256, sha(path.join(BUILD, 'game.wasm')), 'game.wasm hash is stale — run node scripts/make_build_identity.mjs');
  assert.equal(identity.gameJsSha256, sha(path.join(BUILD, 'game.js')), 'game.js hash is stale — run node scripts/make_build_identity.mjs');
  assert.match(identity.gameWasmSha256, /^[0-9a-f]{64}$/);
  assert.match(identity.gameJsSha256, /^[0-9a-f]{64}$/);
  const gameManifest = JSON.parse(await fs.promises.readFile(path.join(ROOT, 'distribution', 'game', 'manifest.json'), 'utf8'));
  assert.equal(identity.gameManifestVersion, gameManifest.version);
  assert.ok(identity.gitCommit === null || /^[0-9a-f]{40,64}$/.test(identity.gitCommit));
  assert.ok(typeof identity.generatedAt === 'string' && !Number.isNaN(Date.parse(identity.generatedAt)));
});

test('computeIdentity recomputes the same values as the committed file', async () => {
  const fresh = await computeIdentity({ buildDir: BUILD });
  const committed = JSON.parse(await fs.promises.readFile(path.join(BUILD, 'identity.json'), 'utf8'));
  for (const key of ['gameWasmSha256', 'gameJsSha256', 'gameManifestVersion', 'gameEnManifestVersion']) {
    assert.equal(committed[key], fresh[key], `${key} differs — regenerate identity.json`);
  }
});

test('the launcher treats a missing identity as unknown, never as a guess', async () => {
  // contract of crash-report.mjs fetchIdentity: a failed fetch yields {error}, not data
  const { createCrashReporter } = await import('../korsary2-next/recomp/web/crash-report.mjs');
  const reporter = createCrashReporter({
    win: null, doc: null, storage: null,
    fetchImpl: async () => { throw new Error('offline'); },
  });
  const identity = await reporter.fetchIdentity();
  assert.equal(identity.error, 'unavailable: offline');
  assert.equal(identity.gameWasmSha256, undefined);
});
