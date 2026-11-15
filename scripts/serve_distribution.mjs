#!/usr/bin/env node
/** Serve the finished static distribution locally using Node's standard library. */
import http from 'node:http';
import fs from 'node:fs';
import { promises as fsp } from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const DEFAULT_DIRECTORY = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '../distribution');
const MIME = new Map(Object.entries({
  '.html': 'text/html; charset=utf-8', '.htm': 'text/html; charset=utf-8',
  '.css': 'text/css; charset=utf-8', '.js': 'text/javascript', '.mjs': 'text/javascript',
  '.wasm': 'application/wasm', '.json': 'application/json', '.mp4': 'video/mp4',
  '.svg': 'image/svg+xml', '.png': 'image/png', '.jpg': 'image/jpeg', '.jpeg': 'image/jpeg',
  '.gif': 'image/gif', '.webp': 'image/webp', '.txt': 'text/plain; charset=utf-8',
  '.gz': 'application/gzip', '.ogg': 'audio/ogg', '.wav': 'audio/wav',
}));

function within(root, candidate) {
  const relative = path.relative(root, candidate);
  return relative === '' || (!path.isAbsolute(relative) && relative !== '..' && !relative.startsWith(`..${path.sep}`));
}

function headers(res, cacheControl = 'no-cache') {
  res.setHeader('Cross-Origin-Opener-Policy', 'same-origin');
  res.setHeader('Cross-Origin-Embedder-Policy', 'require-corp');
  res.setHeader('Cross-Origin-Resource-Policy', 'same-origin');
  res.setHeader('X-Robots-Tag', 'noindex');
  res.setHeader('Cache-Control', cacheControl);
  res.setHeader('Accept-Ranges', 'bytes');
  res.setHeader('X-Content-Type-Options', 'nosniff');
}

function fail(res, status, message, head = false) {
  const body = Buffer.from(`${message}\n`);
  res.writeHead(status, { 'Content-Type': 'text/plain; charset=utf-8', 'Content-Length': body.length });
  res.end(head ? undefined : body);
}

// Match the old server: a single byte range is supported, while a multi-range
// request is ignored and receives the full file.
function byteRange(value, size) {
  if (!value?.startsWith('bytes=') || value.includes(',')) return null;
  const m = /^bytes=(\d*)-(\d*)$/.exec(value);
  if (!m) return false;
  let start, end;
  if (m[1]) {
    start = Number(m[1]);
    end = m[2] ? Math.min(Number(m[2]), size - 1) : size - 1;
  } else if (m[2] && Number(m[2]) > 0) {
    start = Math.max(size - Number(m[2]), 0);
    end = size - 1;
  } else return false;
  return Number.isSafeInteger(start) && Number.isSafeInteger(end) && start >= 0 && start < size && end >= start
    ? { start, end } : false;
}

/** Return an unbound HTTP server. Reject paths and symlinks outside root. */
export async function createStaticHandler(directory, { requireIndex = false, cacheControl = 'no-cache' } = {}) {
  const root = await fsp.realpath(directory);
  if (requireIndex) {
    const index = await fsp.stat(path.join(root, 'index.html')).catch(() => null);
    if (!index?.isFile()) throw new Error(`no index.html in distribution directory: ${root}`);
  }
  return async (req, res) => {
    headers(res, cacheControl);
    const head = req.method === 'HEAD';
    if (req.method !== 'GET' && !head) return fail(res, 405, 'Method not allowed', head);
    let raw;
    try {
      raw = decodeURIComponent((req.url || '/').split('?', 1)[0]);
    } catch {
      return fail(res, 400, 'Invalid URL encoding', head);
    }
    // Windows separators must not be interpreted as URL path separators on any platform.
    if (raw.includes('\0') || raw.includes('\\') || raw.split('/').some(p => p === '..'))
      return fail(res, 404, 'Not found', head);
    let target = path.resolve(root, `.${raw.startsWith('/') ? raw : `/${raw}`}`);
    if (!within(root, target)) return fail(res, 404, 'Not found', head);
    try {
      target = await fsp.realpath(target);
      if (!within(root, target)) return fail(res, 404, 'Not found', head);
      let stat = await fsp.stat(target);
      if (stat.isDirectory()) {
        if (!raw.endsWith('/')) {
          res.writeHead(301, { Location: `${raw}/${req.url?.includes('?') ? `?${req.url.split('?').slice(1).join('?')}` : ''}`, 'Content-Length': '0' });
          return res.end();
        }
        target = await fsp.realpath(path.join(target, 'index.html'));
        if (!within(root, target)) return fail(res, 404, 'Not found', head);
        stat = await fsp.stat(target);
      }
      if (!stat.isFile()) return fail(res, 404, 'Not found', head);
      const range = byteRange(req.headers.range, stat.size);
      if (range === false) {
        res.writeHead(416, { 'Content-Range': `bytes */${stat.size}`, 'Content-Length': '0' });
        return res.end();
      }
      const contentHeaders = {
        'Content-Type': MIME.get(path.extname(target).toLowerCase()) || 'application/octet-stream',
        'Last-Modified': stat.mtime.toUTCString(),
      };
      if (!range && !req.headers['if-none-match'] && req.headers['if-modified-since']) {
        const since = Date.parse(req.headers['if-modified-since']);
        if (Number.isFinite(since) && Math.floor(stat.mtimeMs / 1000) <= Math.floor(since / 1000)) {
          res.writeHead(304, contentHeaders);
          return res.end();
        }
      }
      if (range) {
        contentHeaders['Content-Range'] = `bytes ${range.start}-${range.end}/${stat.size}`;
        contentHeaders['Content-Length'] = range.end - range.start + 1;
      } else contentHeaders['Content-Length'] = stat.size;
      // Open before sending headers so inaccessible resources get an ordinary 404.
      const stream = head ? null : fs.createReadStream(target, range || undefined);
      if (stream) {
        stream.once('error', () => res.headersSent ? res.destroy() : fail(res, 404, 'Not found'));
        stream.once('open', () => {
          res.writeHead(range ? 206 : 200, contentHeaders);
          stream.pipe(res);
        });
        res.once('close', () => stream.destroy());
      } else {
        res.writeHead(range ? 206 : 200, contentHeaders);
        res.end();
      }
    } catch {
      if (!res.headersSent) fail(res, 404, 'Not found', head);
      else res.destroy();
    }
  };
}

export async function createDistributionServer(directory = DEFAULT_DIRECTORY) {
  return http.createServer(await createStaticHandler(directory, { requireIndex: true }));
}

function parseArgs(args) {
  let directory = DEFAULT_DIRECTORY, host = '127.0.0.1', port = 8000;
  for (let i = 0; i < args.length; i++) {
    if (args[i] === '--help' || args[i] === '-h') {
      console.log('Usage: node scripts/serve_distribution.mjs [--directory PATH] [--host ADDRESS] [--port PORT]');
      return null;
    }
    const equal = args[i].indexOf('=');
    const option = equal < 0 ? args[i] : args[i].slice(0, equal);
    const inline = equal < 0 ? undefined : args[i].slice(equal + 1);
    if (!['--directory', '--host', '--port'].includes(option)) throw new Error(`unknown argument: ${args[i]}`);
    const value = inline ?? args[++i];
    if (value === undefined || value === '') throw new Error(`missing value for ${option}`);
    if (option === '--directory') directory = value;
    else if (option === '--host') host = value;
    else {
      if (!/^\d+$/.test(value) || Number(value) > 65535) throw new Error(`invalid port: ${value}`);
      port = Number(value);
    }
  }
  return { directory, host, port };
}

async function main() {
  const args = parseArgs(process.argv.slice(2));
  if (!args) return;
  const server = await createDistributionServer(args.directory);
  server.on('error', error => { console.error(`Server error: ${error.message}`); process.exitCode = 1; });
  server.listen(args.port, args.host, () => {
    const { address, port } = server.address();
    const displayAddress = address.includes(':') ? `[${address}]` : address;
    console.log(`Serving ${path.resolve(args.directory)} at http://${displayAddress}:${port}/ (Ctrl+C to stop)`);
  });
}

if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) {
  main().catch(error => { console.error(error.message); process.exitCode = 1; });
}
