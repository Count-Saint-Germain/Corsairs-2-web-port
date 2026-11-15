#!/usr/bin/env node
// Compile the real loader with fault-injected I/O and a synthetic PE image.
import { mkdtempSync, mkdirSync, rmSync } from 'node:fs';
import { dirname, join, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import { spawnSync } from 'node:child_process';

const root = resolve(dirname(fileURLToPath(import.meta.url)), '..');
const project = resolve(root, '..');
const mode = process.argv.length === 3 ? process.argv[2] : '';
if (!['native', 'wasm'].includes(mode)) {
  console.error('usage: run_image_io.mjs native|wasm');
  process.exit(2);
}
const temp = mkdtempSync(join(root, 'tests', 'korsary-image-io-'));
try {
  const env = { ...process.env };
  let cc, flags, gc, out;
  if (mode === 'native') {
    cc = env.CC || 'clang';
    flags = ['-fsanitize=address,undefined'];
    gc = process.platform === 'darwin' ? '-Wl,-dead_strip' : '-Wl,--gc-sections';
    out = join(temp, 'test');
  } else {
    const sdk = join(project, 'third_party', 'emsdk');
    for (const name of ['tmp', 'cache', 'ports', 'xdg']) mkdirSync(join(temp, name));
    Object.assign(env, { EM_CONFIG: join(sdk, '.emscripten'), EM_CACHE: join(temp, 'cache'),
      EM_PORTS: join(temp, 'ports'), TMPDIR: join(temp, 'tmp'), XDG_CACHE_HOME: join(temp, 'xdg') });
    cc = join(sdk, 'upstream', 'emscripten', 'emcc');
    flags = ['-pthread', '-sNODERAWFS=1', '-sINITIAL_MEMORY=67108864'];
    gc = '-Wl,--gc-sections';
    out = join(temp, 'test.js');
  }
  function run(command, args) {
    const result = spawnSync(command, args, { env, stdio: 'inherit' });
    if (result.error) throw result.error;
    if (result.status !== 0) throw new Error(`${command} exited with ${result.status ?? result.signal}`);
  }
  run(cc, ['-std=gnu11', '-O1', ...flags, '-ffunction-sections', '-fdata-sections',
    '-DPORT_TEST_IMAGE_IO', '-I' + join(root, 'runtime'), '-I' + join(root, 'host'),
    join(root, 'runtime', 'runtime.c'), join(root, 'tests', 'test_image_io.c'), gc, '-pthread', '-lm', '-o', out]);
  run(mode === 'native' ? out : process.execPath,
    [...(mode === 'wasm' ? [out] : []), join(temp, 'image.bin')]);
} finally {
  rmSync(temp, { recursive: true, force: true });
}
