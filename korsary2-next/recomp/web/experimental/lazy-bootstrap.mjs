/* Experimental, isolated lazy boot plan. This never marks a full installation. */
import { validateManifestFiles, sha256GameFile } from '../save-protection.mjs';
import { validateManifestPacks } from '../game-transfer.mjs';

const mutable = path => ['save', 'save_meta', 'save_tx', 'options', 'engine.ini', 'experimental-lazy.json', 'experimental-version.json'].includes(path.split('/')[0].toLowerCase());
const bootstrap = path => /^(engine\.exe|engine\.ini|options)$/i.test(path) || /^(modules|program|resource\/ini)\//i.test(path);

export function planLazyBootstrap(manifest) {
  if (typeof manifest?.version !== 'string' || !manifest.version || /[\x00-\x1f]/.test(manifest.version)) throw new Error('Invalid lazy manifest version');
  const files = validateManifestFiles(manifest.files);
  validateManifestPacks(files, manifest.packs);
  const seen = new Set();
  for (const {path} of files) {
    const folded = path.toLowerCase();
    if (seen.has(folded)) throw new Error(`Ambiguous lazy manifest path: ${path}`);
    if (new TextEncoder().encode(path).length >= 1024) throw new Error(`Lazy manifest path too long: ${path}`);
    seen.add(folded);
  }
  for (const {path} of files) {
    const parts = path.toLowerCase().split('/');
    for (let i = 1; i < parts.length; i++) if (seen.has(parts.slice(0, i).join('/'))) throw new Error(`Lazy manifest file/directory conflict: ${path}`);
  }
  for (const required of ['engine.exe', 'engine.ini', 'options']) if (!seen.has(required)) throw new Error(`Missing lazy bootstrap file: ${required}`);
  const initial = files.filter(f => bootstrap(f.path));
  if (!initial.some(f => /^modules\//i.test(f.path)) || !initial.some(f => /^program\//i.test(f.path))) throw new Error('Missing lazy bootstrap modules or scripts');
  const index = files.filter(f => !mutable(f.path)).map(f => `${f.path}\t${f.size}\n`).join('');
  return { files, initial, index, version: `lazy-bootstrap-v1:${manifest.version}`, packs: manifest.packs };
}
export function lazyMutable(path) { return mutable(path); }

/** Bind an interrupted install to the exact validated manifest and pack layout,
 * even if a server accidentally reuses the same manifest version string. */
export async function bindLazyIdentity(plan, subtle = globalThis.crypto?.subtle) {
  if (!subtle?.digest) throw new Error('WebCrypto is required for the experimental installation');
  const data = new TextEncoder().encode(JSON.stringify({files:plan.files,packs:plan.packs ?? null}));
  const digest = new Uint8Array(await subtle.digest('SHA-256', data));
  plan.version += ':' + [...digest].map(b=>b.toString(16).padStart(2,'0')).join('');
  return plan;
}

/** The version identity is written before the first asset, under the caller's save lock.
 * An interrupted install cannot later resume against a different manifest. */
export async function ensureLazyIdentity(root, rootName, version) {
  const dir = await root.getDirectoryHandle(rootName, {create:true});
  let file;
  try { file = await dir.getFileHandle('experimental-version.json'); }
  catch (e) {
    if (e.name !== 'NotFoundError') throw e;
    for await (const _ of dir.entries()) throw new Error('Unidentified experimental directory is not empty; nothing was modified.');
    file = await dir.getFileHandle('experimental-version.json', {create:true});
    const writer = await file.createWritable();
    try { await writer.write(JSON.stringify({version})); await writer.close(); }
    catch (error) { try { await writer.abort(); } catch {} throw error; }
    return;
  }
  let existing;
  try { existing = JSON.parse(await (await file.getFile()).text()); }
  catch { throw new Error('Experimental version identity is unreadable; nothing was modified.'); }
  if (existing?.version !== version) throw new Error('The experimental installation belongs to a different game version; nothing was modified.');
}

/** Verify only cached immutable manifest files, before a runtime can start.
 * OPFS creates an empty placeholder before its writable stream commits; a
 * browser crash can leave it behind. Unknown files and mutable roots (notably
 * SAVE and options) are never opened, repaired, or deleted. */
export async function verifyLazyCache(dir, plan, hashFile = sha256GameFile) {
  const entries = new Map(plan.files.filter(f => !mutable(f.path)).map(f => [f.path.toLowerCase(), f]));
  const directories = new Set();
  for (const path of entries.keys()) {
    const parts = path.split('/');
    for (let i = 1; i < parts.length; i++) directories.add(parts.slice(0,i).join('/'));
  }
  const seen = new Set(), stack = [[dir, '']];
  while (stack.length) {
    const [current, prefix] = stack.pop();
    for await (const [name, handle] of current.entries()) {
      const path = prefix ? `${prefix}/${name}` : name, low = path.toLowerCase();
      if (mutable(path)) continue;
      const entry = entries.get(low), isDirectory = directories.has(low);
      if (handle.kind === 'directory') {
        if (entry) throw new Error(`Experimental cached file is a directory: ${path}`);
        if (isDirectory) stack.push([handle,path]);
      } else if (handle.kind === 'file') {
        if (isDirectory) throw new Error(`Experimental cached directory is a file: ${path}`);
        if (!entry) continue;
        if (seen.has(low)) throw new Error(`Ambiguous experimental cached path: ${path}`);
        seen.add(low);
        const file = await handle.getFile();
        if (file.size !== entry.size || (await hashFile(dir,path)) !== entry.sha256.toLowerCase())
          throw new Error(`Experimental cached resource is incomplete or damaged: ${path}. No files were changed.`);
      }
    }
  }
  for (const entry of plan.initial) {
    if (!mutable(entry.path) && !seen.has(entry.path.toLowerCase()))
      throw new Error(`Experimental bootstrap resource is missing: ${entry.path}. No files were changed.`);
  }
  return {verified: seen.size};
}
