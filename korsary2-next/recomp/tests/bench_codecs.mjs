// D1b: измерение кодеков передачи на реальной игре (потоково, ничего не пишется на диск).
//   node tests/bench_codecs.mjs sizes FILES.json OUT.json [--variants gz,br9w22,br9w24,br11w22,br11w24,zstd19]
//   node tests/bench_codecs.mjs decode FILES.json [--mb 24] [--types tx,gm,col,an,wav]
//     скорость распаковки (МБ/с распакованных байт) на выборке реальных файлов по типам: WebAssembly-декодер brotli
//     (web/brotli-decoder.mjs, потоком по 64 КиБ), родной brotli и gzip Node, DecompressionStream('gzip') как в браузере,
//     и SHA-256 страницы (save-protection.mjs sha256Update) — то, с чем сравнивается стоимость распаковки
// FILES.json: [{path, src, size, eligible}] (его делает make_dist.py / gamefiles.packable_set); OUT.json: длины потоков по файлам.
// Сжатие — Node zlib (gzip как в gamefiles.gzip_pass: raw deflate -6 + 18 байт; brotli и zstd — встроенные в Node).
import fs from 'node:fs';
import zlib from 'node:zlib';
import { promisify } from 'node:util';
process.env.UV_THREADPOOL_SIZE ||= '10';
const C = zlib.constants;
const deflateRaw = promisify(zlib.deflateRaw), brotli = promisify(zlib.brotliCompress), zstd = zlib.zstdCompress ? promisify(zlib.zstdCompress) : null;

const VARIANTS = {
  gz: (b) => deflateRaw(b, { level: 6 }).then((o) => o.length + 18),
  br9w22: (b) => br(b, 9, 22), br9w24: (b) => br(b, 9, 24),
  br10w24: (b) => br(b, 10, 24),
  br11w22: (b) => br(b, 11, 22), br11w24: (b) => br(b, 11, 24),
  zstd19: (b) => zstd(b, { params: { [C.ZSTD_c_compressionLevel]: 19 } }).then((o) => o.length),
  zstd3: (b) => zstd(b, { params: { [C.ZSTD_c_compressionLevel]: 3 } }).then((o) => o.length),
};
function br(b, q, w) {
  return brotli(b, { params: { [C.BROTLI_PARAM_QUALITY]: q, [C.BROTLI_PARAM_LGWIN]: w, [C.BROTLI_PARAM_SIZE_HINT]: b.length } }).then((o) => o.length);
}

async function decodeBench(listPath, rest) {
  const { loadBrotliDecoder } = await import('../web/brotli-decoder.mjs');
  const { sha256Init, sha256Update, sha256Hex } = await import('../web/save-protection.mjs');
  const crypto = await import('node:crypto');
  const arg = (name, dflt) => { const i = rest.indexOf(name); return i >= 0 ? rest[i + 1] : dflt; };
  const mb = Number(arg('--mb', 24)), types = arg('--types', 'tx,gm,col,an,wav').split(',');
  const list = JSON.parse(fs.readFileSync(listPath, 'utf8'));
  const dec = await loadBrotliDecoder();
  const CH = 64 * 1024;
  const streamed = async (make, comp, raw) => {          // сжатые байты нарезаются по 64 КиБ, как приходят из сети
    const t0 = process.hrtime.bigint();
    const ts = make(), w = ts.writable.getWriter(), r = ts.readable.getReader();
    let out = 0;
    const pump = (async () => { for (;;) { const { done, value } = await r.read(); if (done) break; out += value.length; } })();
    for (let i = 0; i < comp.length; i += CH) await w.write(comp.subarray(i, i + CH));
    await w.close(); await pump;
    const ms = Number(process.hrtime.bigint() - t0) / 1e6;
    if (out !== raw.length) throw new Error('decoded length mismatch');
    return ms;
  };
  const time = (fn) => { const t0 = process.hrtime.bigint(); fn(); return Number(process.hrtime.bigint() - t0) / 1e6; };
  const best = async (fn, n = 3) => { let m = Infinity; for (let i = 0; i < n; i++) m = Math.min(m, await fn()); return m; };
  console.log('type   files    raw MB | gzip DS | gzip nat | br wasm q9 | br wasm q11 | br nat q11 | sha256 JS | sha256 nat    (MB/s of unpacked bytes, best of 3)');
  for (const ext of types) {
    const pick = list.filter((f) => f.eligible && f.path.toLowerCase().endsWith('.' + ext)).sort((a, b) => a.path.localeCompare(b.path));
    const sample = []; let tot = 0;
    for (const f of pick) { if (tot >= mb * 1e6) break; if (f.size > 8e6 && tot > 0) continue; sample.push(f); tot += f.size; }
    const raws = sample.map((f) => fs.readFileSync(f.src));
    const gzs = raws.map((r) => zlib.gzipSync(r, { level: 6 }));
    const b9 = await Promise.all(raws.map((r) => brotli(r, { params: { [C.BROTLI_PARAM_QUALITY]: 9, [C.BROTLI_PARAM_LGWIN]: 22, [C.BROTLI_PARAM_SIZE_HINT]: r.length } })));
    const b11 = await Promise.all(raws.map((r) => brotli(r, { params: { [C.BROTLI_PARAM_QUALITY]: 11, [C.BROTLI_PARAM_LGWIN]: 22, [C.BROTLI_PARAM_SIZE_HINT]: r.length } })));
    const sum = (a) => a.reduce((n, x) => n + x.length, 0);
    const rawN = sum(raws);
    const over = async (fn) => { let t = 0; for (let i = 0; i < raws.length; i++) t += await fn(i); return t; };
    const mbps = (ms) => (rawN / 1e6 / (ms / 1000)).toFixed(0).padStart(6);
    const tGzDS = await best(() => over((i) => streamed(() => new DecompressionStream('gzip'), gzs[i], raws[i])));
    const tGzNat = await best(() => Promise.resolve(time(() => gzs.forEach((g) => zlib.gunzipSync(g)))));
    const tB9 = await best(() => over((i) => streamed(() => dec.createStream({ maxOutput: raws[i].length }), b9[i], raws[i])));
    const tB11 = await best(() => over((i) => streamed(() => dec.createStream({ maxOutput: raws[i].length }), b11[i], raws[i])));
    const tBNat = await best(() => Promise.resolve(time(() => b11.forEach((b) => zlib.brotliDecompressSync(b)))));
    const tShaJs = await best(() => Promise.resolve(time(() => raws.forEach((r) => { const st = sha256Init(); for (let i = 0; i < r.length; i += CH) sha256Update(st, r.subarray(i, i + CH)); sha256Hex(st); }))));
    const tShaNat = await best(() => Promise.resolve(time(() => raws.forEach((r) => crypto.createHash('sha256').update(r).digest('hex')))));
    console.log(`${('.' + ext).padEnd(6)} ${String(sample.length).padStart(5)} ${(rawN / 1e6).toFixed(1).padStart(8)} | ${mbps(tGzDS)} | ${mbps(tGzNat)}  | ${mbps(tB9)}     | ${mbps(tB11)}      | ${mbps(tBNat)}    | ${mbps(tShaJs)}   | ${mbps(tShaNat)}`
      + `   gz ${(100 * sum(gzs) / rawN).toFixed(1)}% br9 ${(100 * sum(b9) / rawN).toFixed(1)}% br11 ${(100 * sum(b11) / rawN).toFixed(1)}%`);
  }
  console.log('wasm heap after the run:', (dec.heapUsed() / 1048576).toFixed(1), 'MiB used, memory', (dec.memory.buffer.byteLength / 1048576).toFixed(1), 'MiB');
}

async function main() {
  if (process.argv[2] === 'decode') return decodeBench(process.argv[3], process.argv.slice(4));
  const [cmd, listPath, outPath, ...rest] = process.argv.slice(2);
  if (cmd !== 'sizes') throw new Error('usage: bench_codecs.mjs sizes FILES.json OUT.json [--variants a,b]');
  const vi = rest.indexOf('--variants');
  const names = vi >= 0 ? rest[vi + 1].split(',') : ['gz', 'br9w22', 'br9w24', 'br11w24', 'zstd19'];
  const list = JSON.parse(fs.readFileSync(listPath, 'utf8'));
  const out = [];
  let next = 0, done = 0, bytes = 0;
  const t0 = Date.now();
  async function worker() {
    for (;;) {
      const i = next++;
      if (i >= list.length) return;
      const f = list[i];
      const row = { path: f.path, size: f.size, eligible: f.eligible };
      if (f.eligible) {
        const buf = fs.readFileSync(f.src);
        for (const n of names) row[n] = await VARIANTS[n](buf);
      }
      out[i] = row;
      bytes += f.size; done++;
      if (done % 500 === 0) console.error(`${done}/${list.length} ${(bytes / 1e6).toFixed(0)} MB ${((Date.now() - t0) / 1000).toFixed(0)} s`);
    }
  }
  await Promise.all(Array.from({ length: 10 }, worker));
  fs.writeFileSync(outPath, JSON.stringify(out));
  console.error(`done in ${((Date.now() - t0) / 1000).toFixed(0)} s`);
}
main();
