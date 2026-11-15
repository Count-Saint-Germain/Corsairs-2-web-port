/* Experimental, isolated lazy boot plan. This never marks a full installation. */
import { validateManifestFiles, sha256GameFile } from '../save-protection.mjs';
import { validateManifestPacks } from '../game-transfer.mjs';

const mutable = path => ['save', 'save_meta', 'save_tx', 'options', 'engine.ini', 'experimental-lazy.json', 'experimental-version.json'].includes(path.split('/')[0].toLowerCase());
const bootstrap = path => /^(engine\.exe|engine\.ini|options)$/i.test(path) || /^(modules|program|resource\/ini)\//i.test(path);

export function planLazyBootstrap(manifest) {
  if (typeof manifest?.version !== 'string' || !manifest.version || /[\x00-\x1f]/.test(manifest.version)) throw new Error('Invalid lazy manifest version');
  const files = validateManifestFiles(manifest.files);
  validateManifestPacks(files, manifest.packs);
  const seen = new Set(), directorySpellings = new Map();
  for (const {path} of files) {
    const folded = path.toLowerCase();
    if (seen.has(folded)) throw new Error(`Ambiguous lazy manifest path: ${path}`);
    if (new TextEncoder().encode(path).length >= 1024) throw new Error(`Lazy manifest path too long: ${path}`);
    seen.add(folded);
    const parts = path.split('/');
    // The native index stores each component in a 256-byte buffer. Reject
    // unsupported manifests before writing an identity or launching Wasm.
    if (parts.some(part => new TextEncoder().encode(part).length > 255))
      throw new Error(`Lazy manifest path component too long: ${path}`);
    for (let i = 1; i < parts.length; i++) {
      const dir = parts.slice(0,i).join('/'), key = dir.toLowerCase(), previous = directorySpellings.get(key);
      if (previous && previous !== dir) throw new Error(`Ambiguous lazy manifest directory: ${dir}`);
      directorySpellings.set(key, dir);
    }
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

// Metadata is deliberately limited to manifest-owned immutable files. In
// particular it must never name SAVE, options, or the installation journal.
function lazyInventory(plan) {
  return plan.files.filter(f => !mutable(f.path)).map(({path,size,sha256}) => ({path,size,sha256:sha256.toLowerCase()}));
}

async function writeLazyIdentity(dir, value) {
  const file = await dir.getFileHandle('experimental-version.json');
  const writer = await file.createWritable();
  try { await writer.write(JSON.stringify(value)); await writer.close(); }
  catch (error) { try { await writer.abort(); } catch {} throw error; }
}

/** Read-only check, called under the page-lifetime save lock immediately
 * before opening any cached files. A stale tab must never repair a newer
 * installation back to its own obsolete manifest. */
export async function assertLazyIdentity(root, rootName, plan) {
  const dir = await root.getDirectoryHandle(rootName);
  let identity;
  try { identity = JSON.parse(await (await (await dir.getFileHandle('experimental-version.json')).getFile()).text()); }
  catch { throw new Error('Lazy version identity is missing or unreadable; reload the page.'); }
  const files = lazyInventory(plan);
  if (identity?.pending || identity?.version !== plan.version || JSON.stringify(identity?.files) !== JSON.stringify(files))
    throw new Error('The game installation changed in another tab; reload the page.');
}

/** Existing engine.ini is mutable, like options: never replace it during a
 * bootstrap update. Reject ambiguous casing/type rather than picking a file. */
export async function lazyBootstrapForSync(dir, plan) {
  const config = plan.initial.find(f => f.path.toLowerCase() === 'engine.ini');
  if (!config) throw new Error('Missing lazy engine.ini bootstrap entry');
  let found = false;
  for await (const [name,handle] of dir.entries()) {
    if (name.toLowerCase() !== 'engine.ini') continue;
    if (found || name !== config.path || handle.kind !== 'file')
      throw new Error('Ambiguous engine.ini; the configuration was not modified.');
    found = true;
  }
  return {version:plan.version, files:found ? plan.initial.filter(f => f !== config) : plan.initial, packs:plan.packs};
}

/** Reconcile an installed manifest under its existing exclusive save lock.
 * `repair(entry)` must atomically install and verify an entry from `plan`.
 * The old inventory is written before any modifications; interrupted updates
 * can be resumed only with the exact same target manifest. Unknown files and
 * mutable paths are never overwritten or removed. Legacy v1 installs can be
 * upgraded in place only while the original identity is still available. */
export async function reconcileLazyIdentity(root, rootName, plan, {repair, hashFile = sha256GameFile, inventoryOnly = false} = {}) {
  if (!plan || typeof plan.version !== 'string' || !Array.isArray(plan.files) || typeof repair !== 'function')
    throw new TypeError('Invalid lazy update arguments');
  const target = {version:plan.version, files:lazyInventory(plan)};
  const dir = await root.getDirectoryHandle(rootName, {create:!inventoryOnly});
  let identity;
  try {
    const fh = await dir.getFileHandle('experimental-version.json');
    identity = JSON.parse(await (await fh.getFile()).text());
  } catch (e) {
    if (e.name !== 'NotFoundError') throw new Error('Experimental version identity is unreadable; nothing was modified.');
    if (inventoryOnly) throw new Error('Lazy version identity is missing; nothing was modified.');
    // Preserve the original rule for unidentified directories.
    await ensureLazyIdentity(root, rootName, plan.version);
    await writeLazyIdentity(dir, target);
    return {status:'created'};
  }
  if (!identity || typeof identity.version !== 'string') throw new Error('Invalid lazy version identity; nothing was modified.');
  if (inventoryOnly && (identity.version !== target.version || identity.pending))
    throw new Error('Lazy identity is not current or has an interrupted update; nothing was modified.');
  if (!identity.files) {
    if (identity.version !== target.version || identity.pending)
      throw new Error('This older installation has no resource inventory; export its saves before installing the new version. Nothing was modified.');
    await writeLazyIdentity(dir, target);
    return {status:'inventoried'};
  }
  const validateInventory = files => {
    if (!Array.isArray(files)) throw new Error('Invalid lazy resource inventory; nothing was modified.');
    const validated = validateManifestFiles(files), seen = new Set();
    if (validated.length !== files.length) throw new Error('Invalid lazy resource inventory; nothing was modified.');
    for (const f of validated) {
      const key = f.path.toLowerCase();
      if (mutable(f.path) || seen.has(key)) throw new Error('Invalid lazy resource inventory; nothing was modified.');
      seen.add(key);
    }
    return validated;
  };
  const oldFiles = validateInventory(identity.files);
  if (identity.pending && (identity.pending.version !== target.version ||
      JSON.stringify(identity.pending.files) !== JSON.stringify(target.files)))
    throw new Error('A different lazy update was interrupted; resume that exact version first. Nothing was modified.');
  if (identity.version === target.version && !identity.pending) {
    if (JSON.stringify(identity.files) !== JSON.stringify(target.files))
      throw new Error('Lazy identity does not match its resource inventory; nothing was modified.');
    return {status:'current'};
  }
  const old = new Map(oldFiles.map(f => [f.path.toLowerCase(), f]));
  const next = new Map(target.files.map(f => [f.path.toLowerCase(), f]));
  const relevant = new Map([...old, ...next]);
  const directories = new Map();
  for (const f of relevant.values()) {
    const parts = f.path.split('/');
    for (let i = 1; i < parts.length; i++) {
      const name = parts.slice(0,i).join('/'), key = name.toLowerCase();
      if ((directories.has(key) && directories.get(key) !== name) || relevant.has(key))
        throw new Error(`Conflicting lazy update path: ${name}. Nothing was modified.`);
      directories.set(key,name);
    }
  }
  for (const [key, prior] of old) {
    const after = next.get(key);
    if (after && prior.path !== after.path) throw new Error(`Noncanonical lazy update path: ${after.path}. Nothing was modified.`);
  }
  const found = new Map(), stack = [[dir,'']];
  while (stack.length) {
    const [current,prefix] = stack.pop();
    for await (const [name,handle] of current.entries()) {
      const path = prefix ? `${prefix}/${name}` : name, key = path.toLowerCase();
      if (mutable(path)) continue;
      const expected = relevant.get(key)?.path || directories.get(key);
      if (!expected) continue;
      if (path !== expected || found.has(key)) throw new Error(`Ambiguous lazy update path: ${path}. Nothing was modified.`);
      found.set(key,handle);
      if (directories.has(key)) {
        if (handle.kind !== 'directory') throw new Error(`Lazy update directory is a file: ${path}. Nothing was modified.`);
        stack.push([handle,path]);
      } else if (handle.kind !== 'file') throw new Error(`Lazy update file is a directory: ${path}. Nothing was modified.`);
    }
  }
  const actions = [];
  for (const [key, after] of next) {
    const before = old.get(key), handle = found.get(key);
    if (!handle || (before && before.size === after.size && before.sha256.toLowerCase() === after.sha256)) continue;
    const actualSize = (await handle.getFile()).size;
    const hash = (await hashFile(dir,after.path)).toLowerCase();
    if (actualSize === after.size && hash === after.sha256) continue; // already installed, including after interruption
    if (!before || actualSize !== before.size || hash !== before.sha256.toLowerCase())
      throw new Error(`Unrecognized file conflicts with lazy update: ${after.path}. Nothing was modified.`);
    actions.push({kind:'replace',entry:plan.files.find(f => f.path === after.path)});
  }
  for (const [key,before] of old) {
    const handle = found.get(key);
    if (next.has(key) || !handle) continue;
    const size = (await handle.getFile()).size, hash = (await hashFile(dir,before.path)).toLowerCase();
    if (size !== before.size || hash !== before.sha256.toLowerCase())
      throw new Error(`Unrecognized file conflicts with lazy update: ${before.path}. Nothing was modified.`);
    actions.push({kind:'remove',entry:before});
  }
  if (!identity.pending) {
    identity.pending = target;
    await writeLazyIdentity(dir,identity);
  }
  for (const action of actions) {
    const entry = action.entry;
    if (action.kind === 'replace') {
      const fh = await repair(entry);
      if (fh?.kind !== 'file' || (await fh.getFile()).size !== entry.size ||
          (await hashFile(dir,entry.path)).toLowerCase() !== entry.sha256.toLowerCase())
        throw new Error(`Lazy update failed verification: ${entry.path}`);
    } else {
      const parts = entry.path.split('/'), name = parts.pop();
      let parent = dir;
      for (const part of parts) parent = await parent.getDirectoryHandle(part);
      await parent.removeEntry(name);
    }
  }
  await writeLazyIdentity(dir,target);
  return {status:'updated', actions:actions.length};
}

/** Verify only cached immutable manifest files, before a runtime can start.
 * Call under the game root's exclusive, page-lifetime lock. The optional
 * repair callback replaces one canonical manifest resource transactionally and
 * returns its FileSystemFileHandle; it must preserve existing data on failure.
 * Unknown files and mutable roots are never opened, repaired, or deleted. */
export async function verifyLazyCache(dir, plan, hashFile = sha256GameFile, {repair} = {}) {
  if (repair !== undefined && typeof repair !== 'function') throw new TypeError('Invalid lazy cache repair callback');
  const entries = new Map(plan.files.filter(f => !mutable(f.path)).map(f => [f.path.toLowerCase(), f]));
  const directories = new Map();
  for (const {path} of entries.values()) {
    const parts = path.split('/');
    for (let i = 1; i < parts.length; i++) {
      const canonical = parts.slice(0,i).join('/');
      directories.set(canonical.toLowerCase(), canonical);
    }
  }
  const seen = new Set(), stack = [[dir, '']], actualDirectories = new Map(), damaged = [];
  while (stack.length) {
    const [current, prefix] = stack.pop();
    for await (const [name, handle] of current.entries()) {
      const path = prefix ? `${prefix}/${name}` : name, low = path.toLowerCase();
      if (mutable(path)) continue;
      const entry = entries.get(low), isDirectory = directories.has(low);
      if (handle.kind === 'directory') {
        if (entry) throw new Error(`Experimental cached file is a directory: ${path}`);
        if (isDirectory) {
          if (actualDirectories.has(low)) throw new Error(`Ambiguous experimental cached directory: ${path}`);
          actualDirectories.set(low, path);
          stack.push([handle,path]);
        }
      } else if (handle.kind === 'file') {
        if (isDirectory) throw new Error(`Experimental cached directory is a file: ${path}`);
        if (!entry) continue;
        if (seen.has(low)) throw new Error(`Ambiguous experimental cached path: ${path}`);
        seen.add(low);
        const file = await handle.getFile();
        const reason = file.size !== entry.size ? 'size' :
          (await hashFile(dir,path)) !== entry.sha256.toLowerCase() ? 'hash' : null;
        if (reason) damaged.push({entry, path, reason, missing:false});
      }
    }
  }
  for (const entry of plan.initial) {
    if (!mutable(entry.path) && !seen.has(entry.path.toLowerCase()))
      damaged.push({entry, path:entry.path, reason:'missing', missing:true});
  }
  // Validate every intended target before touching any file. An alternative
  // spelling of a parent or file can otherwise cause OPFS to create a second
  // case-sensitive entry which Windows treats as the same file.
  for (const item of damaged) {
    if (!repair) throw new Error(item.missing
      ? `Experimental bootstrap resource is missing: ${item.path}. No files were changed.`
      : `Experimental cached resource is incomplete or damaged: ${item.path}. No files were changed.`);
    if (item.path !== item.entry.path) throw new Error(`Experimental cached resource has noncanonical spelling: ${item.path}. No files were changed.`);
    const parts = item.entry.path.split('/');
    for (let i = 1; i < parts.length; i++) {
      const expected = parts.slice(0,i).join('/'), actual = actualDirectories.get(expected.toLowerCase());
      if (actual && actual !== expected) throw new Error(`Experimental cached directory has noncanonical spelling: ${actual}. No files were changed.`);
    }
  }
  for (const item of damaged) {
    const handle = await repair(item.entry, {path:item.path, missing:item.missing, reason:item.reason});
    if (handle?.kind !== 'file' || typeof handle.getFile !== 'function') throw new Error(`Experimental repair did not provide a file: ${item.path}`);
    const file = await handle.getFile();
    if (file.size !== item.entry.size || (await hashFile(dir,item.path)) !== item.entry.sha256.toLowerCase())
      throw new Error(`Experimental repair failed verification: ${item.path}`);
  }
  return {verified: seen.size + damaged.filter(item => item.missing).length, repaired: damaged.length};
}
