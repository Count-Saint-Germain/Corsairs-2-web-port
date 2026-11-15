/** Exact, reproducible game-data fixes applied while packaging, never to saves. */
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { createHash } from 'node:crypto';

const here = path.dirname(fileURLToPath(import.meta.url));
export const SAVE_MENU_PATCH = Object.freeze({
  path: 'RESOURCE/INI/INTERFACES/save_load.ini',
  originalHash: 'fbfad29060904b201cc10ff77456e768c5966f2def991a7389a83a68eceba91d',
  patchedHash: 'e93ffadd959b862469728b99f01f7172a2eb03aa385f5808774eff3e983c7c51',
  file: path.resolve(here, '../patches/save_load.ini'),
});
export const DEFAULT_OPTIONS_PATCH = Object.freeze({
  path: 'options',
  originalHash: '5ce8b1fcd088da6e251de3fe3787bc302d6b866dc0dcf5bbe91e52ab56a9843e',
  patchedHash: 'de07592c1ed8b7bd0b3f7e023cf91eb9e27de5e18d82d869fd70e6469a1ebfaf',
  file: path.resolve(here, '../patches/default-options'),
  preserveUnknown: true,
});
export const RESOURCE_PATCHES = Object.freeze([SAVE_MENU_PATCH, DEFAULT_OPTIONS_PATCH]);
const hash = p => createHash('sha256').update(fs.readFileSync(p)).digest('hex');

/** Return an alternate source only for the exact known file and version.
 * A reconstructed game already contains the patch; accepting it is essential
 * for building repeatedly from a clean checkout. Unknown menu modifications
 * fail closed; an unknown options file is preserved as a local preference. */
export function patchedResourceSource(relative, source) {
  const patch = RESOURCE_PATCHES.find(p => relative.toLowerCase() === p.path.toLowerCase());
  if (!patch) return source;
  if (hash(patch.file) !== patch.patchedHash) throw new Error(`bundled ${relative} patch failed SHA-256 verification`);
  const inputHash = hash(source);
  if (inputHash !== patch.originalHash && inputHash !== patch.patchedHash && patch.preserveUnknown) return source;
  if (inputHash !== patch.originalHash && inputHash !== patch.patchedHash)
    throw new Error(`${relative}: unknown source content; refusing to replace a modified game file`);
  return patch.file;
}

export function applyResourceOverrides(files) {
  return new Map([...files].map(([relative, source]) => [relative, patchedResourceSource(relative, source)]));
}
