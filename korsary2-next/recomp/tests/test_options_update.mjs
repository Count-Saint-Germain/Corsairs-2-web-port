import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import {planOptionsUpdate} from '../web/save-protection.mjs';

const manifest = [{path:'PROGRAM/test.c'}, {path:'options'}];
function file(value) {
  return {kind:'file', value, async getFile() { return new Blob([this.value]); }};
}
function directory(entries, failure) {
  return {async *entries() {
    if (failure) throw failure;
    for (const entry of entries) yield entry;
  }};
}

// Fresh install gets the source file only when none exists.
assert.equal(await planOptionsUpdate(directory([]), manifest, false), 'install');
await assert.rejects(() => planOptionsUpdate(directory([]), manifest, true), /отсутствует файл настроек/);
const defaults = 'default options';
const hash = createHash('sha256').update(defaults).digest('hex');
assert.equal(await planOptionsUpdate(directory([['options', file(defaults)]]), [{path:'options', size:defaults.length, sha256:hash}], false), 'preserve');
await assert.rejects(() => planOptionsUpdate(directory([['options', file(defaults.slice(0, 5))]]), [{path:'options', size:defaults.length, sha256:hash}], false), /без подтверждения установки/);

// A completed installation keeps the user's exact existing bytes, including
// on a subsequent changed-manifest update. Uppercase aliases are recognized.
for (const name of ['options', 'OPTIONS']) {
  const custom = file('controls.primaryland.bifastcommand=key_g\n');
  const root = directory([[name, custom], ['PROGRAM', {kind:'directory'}]]);
  assert.equal(await planOptionsUpdate(root, manifest, true), 'preserve');
  assert.equal(await planOptionsUpdate(root, manifest, true), 'preserve');
  assert.equal(custom.value, 'controls.primaryland.bifastcommand=key_g\n');
}

// A damaged/missing marker with an existing file is ambiguous: never overwrite.
const existing = file('user or incomplete settings');
await assert.rejects(() => planOptionsUpdate(directory([['options', existing]]), manifest, false), /без подтверждения установки/);
assert.equal(existing.value, 'user or incomplete settings');

// No fallback to overwriting when listing or reading fails, or aliases collide.
await assert.rejects(() => planOptionsUpdate(directory([], Error('listing denied')), manifest, true), /listing denied/);
await assert.rejects(() => planOptionsUpdate(directory([['options', {kind:'file', async getFile(){throw Error('read denied');}}]]), manifest, true), /read denied/);
await assert.rejects(() => planOptionsUpdate(directory([['options', file('a')], ['OPTIONS', file('b')]]), manifest, true), /Неоднозначный/);
await assert.rejects(() => planOptionsUpdate(directory([['options', {kind:'directory'}]]), manifest, true), /Неоднозначный/);
await assert.rejects(() => planOptionsUpdate(directory([]), [{path:'OPTIONS'}], false), /манифесте/);
await assert.rejects(() => planOptionsUpdate(directory([]), [{path:'options'}, {path:'options'}], false), /манифесте/);
assert.equal(await planOptionsUpdate(directory([]), [{path:'PROGRAM/test.c'}], false), 'not-listed');
console.log('options update: fresh, preserve, ambiguous install, access errors, aliases PASS');
