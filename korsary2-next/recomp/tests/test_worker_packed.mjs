/* D1/D3: Cloudflare Worker (web/cloudflare/worker.js) отдаёт game/<path>.gz и пакеты передачи
   game/_k2pack/*.pack как непрозрачные байты: без Content-Encoding (даже если R2-объект хранит такое поле),
   с no-transform, Content-Length и Range по байтам ОБЪЕКТА (для пакета — диапазон записей внутри него). Настоящий код serve() из worker.js с поддельным R2-бакетом; сети и Cloudflare нет.
     node tests/test_worker_packed.mjs */
import assert from 'node:assert/strict';
import { brotliCompressSync, gzipSync } from 'node:zlib';
import worker from '../web/cloudflare/worker.js';

const objects = new Map();
const gz = gzipSync(Buffer.alloc(50_000, 'abc'));
objects.set('game/RESOURCE/a.tx.gz', { data: gz, encodingMeta: 'gzip' });     // метаданные R2 с Content-Encoding (ошибка загрузки)
const brBytes = brotliCompressSync(Buffer.alloc(50_000, 'abcdef'));
objects.set('game/RESOURCE/c.gm.br', { data: brBytes, encodingMeta: 'br' });      // D1b: тоже с ошибочным Content-Encoding в метаданных
objects.set('game/RESOURCE/b.wav', { data: Buffer.from('plain'), encodingMeta: null });
const pack = Buffer.from(Array.from({ length: 5000 }, (_, i) => (i * 7) & 255));
objects.set('game/_k2pack/0000-0123456789ab.pack', { data: pack, encodingMeta: 'gzip' });   // даже с ошибочным полем в метаданных
objects.set('game/manifest.json', { data: Buffer.from('{}'), encodingMeta: null });
const env = { PASSWORD: '', ALLOW_PUBLIC: '1', BUCKET: {
  async get(key, opts) {
    const o = objects.get(key); if (!o) return null;
    const r = opts?.range && opts.range.get?.('Range');
    let offset = 0, length = o.data.length;
    const m = /^bytes=(\d*)-(\d*)$/.exec(r || '');
    if (m && m[1] !== '') { offset = +m[1]; length = (m[2] === '' ? o.data.length : +m[2] + 1) - offset; }
    else if (m) { length = +m[2]; offset = o.data.length - length; }
    const slice = o.data.subarray(offset, offset + length);
    return { size: o.data.length, httpEtag: '"e"', range: m ? (m[1] === '' ? { suffix: length } : { offset, length }) : undefined,
      body: new Response(slice).body, writeHttpMetadata(h) { if (o.encodingMeta) h.set('Content-Encoding', o.encodingMeta); } };
  } } };
const get = (path, headers = {}, method = 'GET') => worker.fetch(new Request('https://h.example' + path, { headers, method }), env);

{
  const r = await get('/game/RESOURCE/a.tx.gz');
  assert.equal(r.status, 200);
  assert.equal(r.headers.get('Content-Encoding'), null, 'Content-Encoding снимается: браузер не должен распаковывать дважды');
  assert.equal(r.headers.get('Content-Type'), 'application/octet-stream');
  assert.match(r.headers.get('Cache-Control'), /max-age=86400/);
  assert.match(r.headers.get('Cache-Control'), /no-transform/);
  assert.equal(r.headers.get('Content-Length'), String(gz.length));
  assert.equal(r.headers.get('Accept-Ranges'), 'bytes');
  assert.equal(r.headers.get('Cross-Origin-Embedder-Policy'), 'require-corp');
  assert.deepEqual(Buffer.from(await r.arrayBuffer()), gz);
  console.log('ok - .gz: без Content-Encoding, no-transform, Content-Length = длина сжатого объекта');
}
{
  const r = await get('/game/RESOURCE/a.tx.gz', { Range: 'bytes=10-29' });
  assert.equal(r.status, 206);
  assert.equal(r.headers.get('Content-Range'), `bytes 10-29/${gz.length}`);
  assert.equal(r.headers.get('Content-Length'), '20');
  assert.deepEqual(Buffer.from(await r.arrayBuffer()), gz.subarray(10, 30));
  console.log('ok - Range по сжатым байтам: 206, Content-Range с длиной сжатого');
}
{
  const r = await get('/game/RESOURCE/b.wav');
  assert.equal(r.headers.get('Cache-Control'), 'private, max-age=86400', 'обычные файлы: как раньше');
  const m = await get('/game/manifest.json');
  assert.equal(m.headers.get('Cache-Control'), 'no-cache');
  assert.equal((await get('/game/RESOURCE/b.wav', {}, 'HEAD')).status, 200);
  assert.equal((await get('/game/RESOURCE/none.gz')).status, 404);
  console.log('ok - несжатые файлы и манифест: заголовки без изменений');
}
{
  const name = '/game/_k2pack/0000-0123456789ab.pack';
  const r = await get(name);
  assert.equal(r.status, 200);
  assert.equal(r.headers.get('Content-Encoding'), null);
  assert.equal(r.headers.get('Content-Type'), 'application/octet-stream');
  assert.match(r.headers.get('Cache-Control'), /max-age=86400/); assert.match(r.headers.get('Cache-Control'), /no-transform/);
  assert.equal(r.headers.get('Content-Length'), String(pack.length)); assert.equal(r.headers.get('Accept-Ranges'), 'bytes');
  assert.deepEqual(Buffer.from(await r.arrayBuffer()), pack);
  // диапазон записи внутри пакета: 206 и Content-Range с длиной ПАКЕТА
  const part = await get(name, { Range: 'bytes=1200-2399' });
  assert.equal(part.status, 206); assert.equal(part.headers.get('Content-Range'), `bytes 1200-2399/${pack.length}`);
  assert.equal(part.headers.get('Content-Length'), '1200'); assert.equal(part.headers.get('Content-Encoding'), null);
  assert.deepEqual(Buffer.from(await part.arrayBuffer()), pack.subarray(1200, 2400));
  const tail = await get(name, { Range: 'bytes=4000-' });
  assert.equal(tail.status, 206); assert.equal(tail.headers.get('Content-Range'), `bytes 4000-4999/${pack.length}`);
  assert.deepEqual(Buffer.from(await tail.arrayBuffer()), pack.subarray(4000));
  assert.equal((await get(name, {}, 'HEAD')).headers.get('Content-Length'), String(pack.length));
  assert.equal((await get('/game/_k2pack/9999-000000000000.pack')).status, 404);
  console.log('ok - пакет передачи: непрозрачные байты, no-transform, Range внутри пакета (206 + Content-Range с длиной пакета)');
}
{
  // D1b: game/<path>.br — brotli-поток, который страница распаковывает сама: тот же режим, что у .gz
  const r = await get('/game/RESOURCE/c.gm.br');
  assert.equal(r.status, 200);
  assert.equal(r.headers.get('Content-Encoding'), null, 'Content-Encoding снимается и у .br: иначе браузер распакует brotli сам, а страница ждёт поток');
  assert.equal(r.headers.get('Content-Type'), 'application/octet-stream');
  assert.match(r.headers.get('Cache-Control'), /max-age=86400/); assert.match(r.headers.get('Cache-Control'), /no-transform/);
  assert.equal(r.headers.get('Content-Length'), String(brBytes.length));
  assert.deepEqual(Buffer.from(await r.arrayBuffer()), brBytes);
  const part = await get('/game/RESOURCE/c.gm.br', { Range: 'bytes=3-12' });
  assert.equal(part.status, 206); assert.equal(part.headers.get('Content-Range'), `bytes 3-12/${brBytes.length}`);
  // декодер brotli и его .wasm — обычные файлы страницы: правильный MIME, без no-transform
  objects.set('brotli-decoder.mjs', { data: Buffer.from('export {}'), encodingMeta: null });
  objects.set('vendor/brotli/k2br.wasm', { data: Buffer.from([0, 0x61, 0x73, 0x6d]), encodingMeta: null });
  assert.match((await get('/brotli-decoder.mjs')).headers.get('Content-Type'), /javascript/);
  const w = await get('/vendor/brotli/k2br.wasm');
  assert.equal(w.headers.get('Content-Type'), 'application/wasm');
  assert.equal(w.headers.get('Cache-Control'), 'no-cache');
  console.log('ok - .br: непрозрачные байты, без Content-Encoding, no-transform, Range; k2br.wasm отдаётся как application/wasm');
}
console.log('worker (game/*.gz, game/*.br, game/_k2pack/*.pack): PASS');
