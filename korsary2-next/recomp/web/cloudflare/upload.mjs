#!/usr/bin/env node
/** Upload a distribution to the Worker's R2 endpoint; never deletes bucket objects. */
import fs from 'node:fs';
import { promises as fsp } from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { pathToFileURL } from 'node:url';

export const PART = 48 * 1024 * 1024;
export const SINGLE_MAX = 64 * 1024 * 1024;
export const TREES = ['game/', 'game-en/'];
export const MANIFESTS = TREES.map(tree => `${tree}manifest.json`);

export async function call(base, token, key, { method = 'GET', query, body, headers = {}, fetchImpl = fetch } = {}) {
  const encodedKey = key.split('/').map(encodeURIComponent).join('/');
  const params = query ? `?${new URLSearchParams(Object.entries(query).map(([k,v]) => [k, String(v)]))}` : '';
  const response = await fetchImpl(`${base.replace(/\/$/, '')}/_upload/${encodedKey}${params}`, {
    method, body, headers: { 'X-Upload-Token': token, 'User-Agent': 'port-upload/1', ...headers },
    signal: AbortSignal.timeout(600_000),
  });
  if (!response.ok) {
    const error = new Error(`Upload endpoint returned HTTP ${response.status}`);
    error.status = response.status;
    throw error;
  }
  const data = await response.text();
  return data ? JSON.parse(data) : null;
}

export async function fileSha256(file) {
  const h = createHash('sha256');
  for await (const chunk of fs.createReadStream(file)) h.update(chunk);
  return h.digest('hex');
}

export async function remoteInfo(base, token, key, transport = call) {
  let info;
  try { info = await transport(base, token, key, { query: { head: '1' } }); }
  catch (e) { if (e.status === 404) return null; throw e; }
  return { size: info.size, sha256: typeof info.sha256 === 'string' ? info.sha256.toLowerCase() : null };
}
export async function remoteSize(base, token, key, transport = call) {
  return (await remoteInfo(base, token, key, transport))?.size ?? -1;
}
export function decide(info, size, localSha, trustSize = false) {
  if (info === null) return [true, 'absent'];
  if (info.size !== size) return [true, 'size differs'];
  if (info.sha256) return info.sha256 === localSha ? [false, 'same size and sha256'] : [true, 'same size, different content'];
  if (trustSize) return [false, 'same size (bucket has no recorded hash; --trust-size)'];
  return [true, 'same size, bucket has no recorded hash'];
}

export async function uploadFile(base, token, key, file, sha256 = null, { transport = call, singleMax = SINGLE_MAX, partSize = PART, out = console.log } = {}) {
  const { size } = await fsp.stat(file);
  const headers = sha256 ? { 'X-Content-SHA256': sha256 } : {};
  if (size <= singleMax) return transport(base, token, key, { method: 'PUT', body: await fsp.readFile(file), headers });
  const { uploadId } = await transport(base, token, key, { method: 'POST', query: { mpu: 'create' }, headers });
  const parts = [], handle = await fsp.open(file, 'r');
  try {
    let offset = 0, n = 0;
    while (offset < size) {
      const buf = Buffer.alloc(Math.min(partSize, size - offset));
      // Read may be short even before EOF; fill each part unless the source changed.
      let filled = 0;
      while (filled < buf.length) {
        const { bytesRead } = await handle.read(buf, filled, buf.length - filled, offset + filled);
        if (!bytesRead) throw new Error(`File changed while uploading: ${file}`);
        filled += bytesRead;
      }
      n++;
      let answer;
      for (let attempt = 0; attempt < 4; attempt++) {
        try { answer = await transport(base, token, key, { method: 'PUT', query: { uploadId, part: n }, body: buf }); break; }
        catch (e) { if (attempt === 3) throw e; }
      }
      parts.push(answer); offset += filled;
      out(`    part ${n} (${(offset / 1e6).toFixed(0)}/${(size / 1e6).toFixed(0)} MB)`);
    }
  } finally { await handle.close(); }
  return transport(base, token, key, { method: 'POST', query: { uploadId, complete: '1' }, body: JSON.stringify(parts), headers });
}

export async function collect(dist) {
  const files = [];
  async function walk(dir) {
    for (const entry of await fsp.readdir(dir, { withFileTypes: true })) {
      const full = path.join(dir, entry.name);
      if (entry.isSymbolicLink()) throw new Error(`distribution contains a symlink: ${full}`);
      if (entry.isDirectory()) await walk(full);
      else if (entry.isFile()) {
        const key = path.relative(dist, full).split(path.sep).join('/');
        if (key !== '_headers') files.push([key, full, (await fsp.stat(full)).size]);
      }
    }
  }
  await walk(dist);
  files.sort((a,b) => Number(MANIFESTS.includes(a[0])) - Number(MANIFESTS.includes(b[0])) || a[2]-b[2] || (a[0]<b[0]?-1:a[0]>b[0]?1:0));
  return files.map(([key, full]) => [key, full]);
}

export async function manifestProblems(dist, keys) {
  const available = new Set(keys), missing = [];
  for (const tree of TREES) {
    let wanted;
    try {
      const manifest = JSON.parse(await fsp.readFile(path.join(dist, tree, 'manifest.json'), 'utf8'));
      if (!Array.isArray(manifest.files) || (manifest.packs && !Array.isArray(manifest.packs))) continue;
      wanted = manifest.files.map(e => {
        if (e.pack != null) {
          if (!Number.isInteger(e.pack) || e.pack < 0 || !manifest.packs?.[e.pack] || typeof manifest.packs[e.pack].path !== 'string') throw new Error('invalid pack index');
          return tree + manifest.packs[e.pack].path;
        }
        if (typeof e.path !== 'string') throw new Error('invalid path');
        return tree + e.path + ({ gzip: '.gz', br: '.br' }[e.enc] ?? '');
      });
    } catch { continue; }
    for (const key of new Set(wanted)) if (!available.has(key)) missing.push(key);
  }
  return missing;
}

export async function run(base, token, dist, { trustSize = false, dryRun = false, out = console.log, transport = call, partSize = PART, singleMax = SINGLE_MAX } = {}) {
  const files = await collect(dist);
  const absent = await manifestProblems(dist, files.map(([key]) => key));
  if (absent.length) throw new Error(`a manifest (game/ or game-en/) lists ${absent.length} objects that are not in ${dist}: ${absent.slice(0,5).join(', ')}; nothing was uploaded`);
  const sizes = await Promise.all(files.map(([, file]) => fsp.stat(file).then(s => s.size)));
  const total = sizes.reduce((a,b) => a+b, 0);
  let done = 0;
  const sent = [], skipped = [], unverified = [];
  for (let i=0; i<files.length; i++) {
    const [key, full] = files[i], size = sizes[i];
    const immutable = TREES.some(tree => key.startsWith(tree)) && !MANIFESTS.includes(key);
    let sha = null, why = 'always sent';
    if (immutable) {
      const info = await remoteInfo(base, token, key, transport);
      if (info?.size === size) sha = await fileSha256(full);
      let upload; [upload, why] = decide(info, size, sha, trustSize);
      if (!upload) { skipped.push(key); done += size; continue; }
      if (!sha) sha = await fileSha256(full);
    }
    out(`${key} (${(size/1e6).toFixed(1)} MB) [${why}]${dryRun ? ' (dry run)' : ''}`);
    if (!dryRun) {
      const answer = await uploadFile(base, token, key, full, sha, { transport, partSize, singleMax, out });
      if (sha) {
        if (answer?.sha256 == null) unverified.push(key);
        else if (typeof answer.sha256 !== 'string' || answer.sha256.toLowerCase() !== sha) throw new Error(`${key}: the bucket recorded sha256 ${answer.sha256}, expected ${sha}`);
      }
    }
    sent.push(key); done += size;
    out(`  ${(done/1e6).toFixed(0)}/${(total/1e6).toFixed(0)} MB ${dryRun ? 'planned' : 'uploaded'}`);
  }
  if (unverified.length) out(`WARNING: the Worker did not record hashes for ${unverified.length} files; redeploy worker.js, otherwise every run uploads all game files again`);
  out(`done: ${files.length} files, ${(total/1e6).toFixed(0)} MB; ${sent.length} ${dryRun ? 'to send' : 'sent'}, ${skipped.length} already in the bucket with matching size and sha256`);
  return [sent, skipped];
}

async function main() {
  let base, dist = 'dist', trustSize = false, dryRun = false;
  const args = process.argv.slice(2);
  for (let i=0; i<args.length; i++) {
    const arg = args[i];
    if (arg === '--help' || arg === '-h') { console.log('Usage: node upload.mjs URL [--dist PATH] [--trust-size] [--dry-run]'); return; }
    if (arg === '--trust-size') trustSize = true;
    else if (arg === '--dry-run') dryRun = true;
    else if (arg === '--dist' || arg.startsWith('--dist=')) { dist = arg === '--dist' ? args[++i] : arg.slice('--dist='.length); if (!dist) throw new Error('--dist requires a path'); }
    else if (arg.startsWith('-') || base) throw new Error(`unexpected argument: ${arg}`);
    else base = arg;
  }
  if (!base) throw new Error('Worker URL is required');
  const token = process.env.PORT_UPLOAD_TOKEN;
  if (!token) throw new Error("set PORT_UPLOAD_TOKEN to the Worker's UPLOAD_TOKEN secret");
  await run(base.replace(/\/$/, ''), token, dist, { trustSize, dryRun });
}
if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) main().catch(e => { console.error(e.message); process.exitCode = 1; });
