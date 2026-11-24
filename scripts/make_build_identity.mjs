#!/usr/bin/env node
// Build identity (docs/defensive-lifetime-plan.md, layer 1): hash the shipped runtime
// and record the manifest versions plus the git state, so any crash report is pinned
// to the exact build that produced it. Regenerate after every engine rebuild:
//
//   node scripts/make_build_identity.mjs                       # -> distribution/build/identity.json
//   node scripts/make_build_identity.mjs --build <dir>         # another output build dir
//
// The file is served as a normal static asset; a missing or stale one must degrade to
// "unknown" in the launcher, never to a guessed version (tests/test_build_identity.mjs
// verifies the file against the actual bytes).
import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { execFile } from 'node:child_process';
import { promisify } from 'node:util';
import { fileURLToPath } from 'node:url';

const execFileAsync = promisify(execFile);
const HERE = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(HERE, '..');

export function sha256(file) {
  return new Promise((resolve, reject) => {
    const hash = createHash('sha256');
    fs.createReadStream(file)
      .on('data', (chunk) => hash.update(chunk))
      .on('end', () => resolve(hash.digest('hex')))
      .on('error', reject);
  });
}

async function gitState() {
  try {
    const { stdout: commit } = await execFileAsync('git', ['rev-parse', 'HEAD'], { cwd: ROOT });
    const { stdout: dirty } = await execFileAsync('git', ['status', '--porcelain'], { cwd: ROOT });
    return { gitCommit: commit.trim(), gitDirty: dirty.trim().length > 0 };
  } catch {
    return { gitCommit: null, gitDirty: null };   // e.g. an exported archive: say so, never guess
  }
}

async function manifestVersion(file) {
  try {
    const parsed = JSON.parse(await fs.promises.readFile(file, 'utf8'));
    return typeof parsed.version === 'string' ? parsed.version : null;
  } catch {
    return null;   // no English layer / no manifest: the field stays null, not invented
  }
}

export async function computeIdentity({ buildDir, root = ROOT, git = true } = {}) {
  const build = path.resolve(buildDir);
  const wasm = path.join(build, 'game.wasm');
  const glue = path.join(build, 'game.js');
  const [gameWasmSha256, gameJsSha256, gameManifestVersion, gameEnManifestVersion, gitStateOut] =
    await Promise.all([
      sha256(wasm),
      sha256(glue),
      manifestVersion(path.join(root, 'distribution', 'game', 'manifest.json')),
      manifestVersion(path.join(root, 'distribution', 'game-en', 'manifest.json')),
      git ? gitState() : { gitCommit: null, gitDirty: null },
    ]);
  return {
    schema: 1,
    gameWasmSha256,
    gameJsSha256,
    gameManifestVersion,
    gameEnManifestVersion,
    gitCommit: gitStateOut.gitCommit,
    gitDirty: gitStateOut.gitDirty,
    generatedAt: new Date().toISOString(),
  };
}

export async function writeIdentity(options = {}) {
  const buildDir = options.buildDir ?? path.join(ROOT, 'distribution', 'build');
  const identity = await computeIdentity({ ...options, buildDir });
  const target = path.join(buildDir, 'identity.json');
  const tmp = target + '.tmp';
  await fs.promises.writeFile(tmp, JSON.stringify(identity, null, 2) + '\n');
  await fs.promises.rename(tmp, target);   // atomic enough for a static asset
  return { identity, target };
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  const argv = process.argv.slice(2);
  const buildDirFlag = argv.indexOf('--build');
  const buildDir = buildDirFlag >= 0 ? argv[buildDirFlag + 1] : path.join(ROOT, 'distribution', 'build');
  writeIdentity({ buildDir })
    .then(({ identity, target }) => {
      console.log(`${target}: wasm ${identity.gameWasmSha256.slice(0, 12)}, manifest ${identity.gameManifestVersion}, commit ${identity.gitCommit ?? 'unknown'}${identity.gitDirty ? ' (dirty)' : ''}`);
    })
    .catch((e) => { console.error('make_build_identity failed:', e.message); process.exit(1); });
}
