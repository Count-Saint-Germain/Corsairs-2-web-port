/* E1: Cloudflare Worker (web/cloudflare/worker.js) и оверлей языка game-en/ (docs/overlay-e1.md): объекты игры (`game-en/<path>`, `.gz`/`.br`,
   пакеты `game-en/_k2pack/*.pack`) получают то же кеширование, no-transform, Content-Length и Range, что и `game/`; манифест оверлея — no-cache и
   отвечает на HEAD (страница проверяет им наличие слоя); отсутствующий оверлей — честный 404 (не страница-заглушка). Настоящий serve() из worker.js,
   поддельный R2-бакет; сети и Cloudflare нет.
     node tests/test_worker_overlay.mjs */
import assert from 'node:assert/strict';
import { brotliCompressSync, gzipSync } from 'node:zlib';
import worker from '../web/cloudflare/worker.js';

const objects = new Map();
const gz = gzipSync(Buffer.alloc(40_000, 'en'));
const br = brotliCompressSync(Buffer.alloc(40_000, 'overlay'));
const pack = Buffer.from(Array.from({ length: 3000 }, (_, i) => (i * 13) & 255));
objects.set('game-en/PROGRAM/DIALOGS/a.h.gz', { data: gz, encodingMeta: 'gzip' });
objects.set('game-en/RESOURCE/b.ini.br', { data: br, encodingMeta: 'br' });
objects.set('game-en/RESOURCE/c.txt', { data: Buffer.from('plain'), encodingMeta: null });
objects.set('game-en/_k2pack/0000-abcdefabcdef.pack', { data: pack, encodingMeta: 'gzip' });
objects.set('game-en/manifest.json', { data: Buffer.from('{"version":"x","files":[]}'), encodingMeta: null });
objects.set('game/manifest.json', { data: Buffer.from('{}'), encodingMeta: null });
objects.set('game/RESOURCE/c.txt', { data: Buffer.from('ru'), encodingMeta: null });
objects.set('game/_k2pack/0000-0123456789ab.pack', { data: pack, encodingMeta: null });
objects.set('game-entry/x.gz', { data: Buffer.from('not an overlay object'), encodingMeta: null });   // a name that merely starts like the prefix
const env = { PASSWORD: '', ALLOW_PUBLIC: '1', BUCKET: {
  async get(key, opts) {
    const o = objects.get(key); if (!o) return null;
    const r = opts?.range && opts.range.get?.('Range');
    let offset = 0, length = o.data.length;
    const m = /^bytes=(\d*)-(\d*)$/.exec(r || '');
    if (m && m[1] !== '') { offset = +m[1]; length = (m[2] === '' ? o.data.length : +m[2] + 1) - offset; }
    else if (m) { length = +m[2]; offset = o.data.length - length; }
    return { size: o.data.length, httpEtag: '"e"', range: m ? (m[1] === '' ? { suffix: length } : { offset, length }) : undefined,
      body: new Response(o.data.subarray(offset, offset + length)).body, writeHttpMetadata(h) { if (o.encodingMeta) h.set('Content-Encoding', o.encodingMeta); } };
  } } };
const get = (path, headers = {}, method = 'GET') => worker.fetch(new Request('https://h.example' + path, { headers, method }), env);

{
  const r = await get('/game-en/PROGRAM/DIALOGS/a.h.gz');
  assert.equal(r.status, 200);
  assert.equal(r.headers.get('Content-Encoding'), null);
  assert.match(r.headers.get('Cache-Control'), /max-age=86400/);
  assert.match(r.headers.get('Cache-Control'), /no-transform/);
  assert.equal(r.headers.get('Content-Length'), String(gz.length));
  assert.equal(r.headers.get('Cross-Origin-Embedder-Policy'), 'require-corp');
  assert.deepEqual(Buffer.from(await r.arrayBuffer()), gz);
  const b = await get('/game-en/RESOURCE/b.ini.br');
  assert.equal(b.headers.get('Content-Encoding'), null);
  assert.match(b.headers.get('Cache-Control'), /no-transform/);
  assert.deepEqual(Buffer.from(await b.arrayBuffer()), br);
  console.log('ok - game-en/*.gz и *.br: без Content-Encoding, no-transform, Content-Length сжатого объекта');
}
{
  const r = await get('/game-en/_k2pack/0000-abcdefabcdef.pack', { Range: 'bytes=100-299' });
  assert.equal(r.status, 206);
  assert.equal(r.headers.get('Content-Range'), `bytes 100-299/${pack.length}`);
  assert.equal(r.headers.get('Content-Length'), '200');
  assert.equal(r.headers.get('Content-Encoding'), null);
  assert.match(r.headers.get('Cache-Control'), /max-age=86400, no-transform/);
  assert.deepEqual(Buffer.from(await r.arrayBuffer()), pack.subarray(100, 300));
  console.log('ok - пакет оверлея: Range 206 по байтам объекта, no-transform');
}
{
  const m = await get('/game-en/manifest.json');
  assert.equal(m.status, 200);
  assert.equal(m.headers.get('Cache-Control'), 'no-cache', 'манифест оверлея ревалидируется, как манифест игры');
  assert.equal(m.headers.get('Content-Type'), 'application/json');
  const h = await get('/game-en/manifest.json', {}, 'HEAD');
  assert.equal(h.status, 200);
  assert.equal(h.headers.get('Content-Type'), 'application/json');
  assert.equal(await h.text(), '');
  const plain = await get('/game-en/RESOURCE/c.txt');
  assert.equal(plain.headers.get('Cache-Control'), 'private, max-age=86400');
  console.log('ok - манифест game-en: no-cache, HEAD 200 с application/json; обычный файл оверлея: private, max-age=86400');
}
{
  // оверлея нет: честный 404 (HEAD тоже), а не страница-заглушка; префикс-двойник не считается деревом игры
  objects.delete('game-en/manifest.json');
  assert.equal((await get('/game-en/manifest.json')).status, 404);
  assert.equal((await get('/game-en/manifest.json', {}, 'HEAD')).status, 404);
  const x = await get('/game-entry/x.gz');
  assert.equal(x.status, 200);
  assert.doesNotMatch(x.headers.get('Cache-Control'), /no-transform/);
  assert.equal(x.headers.get('Cache-Control'), 'no-cache', '«game-entry/» — не дерево игры: заголовки как у прочих файлов');
  console.log('ok - без оверлея: 404; «game-entry/» не принимается за дерево игры');
}
{
  // игра как раньше
  const r = await get('/game/RESOURCE/c.txt');
  assert.equal(r.headers.get('Cache-Control'), 'private, max-age=86400');
  const m = await get('/game/manifest.json');
  assert.equal(m.headers.get('Cache-Control'), 'no-cache');
  const p = await get('/game/_k2pack/0000-0123456789ab.pack');
  assert.match(p.headers.get('Cache-Control'), /no-transform/);
  assert.equal(p.headers.get('Content-Encoding'), null);
  console.log('ok - game/: заголовки без изменений');
}
console.log('worker overlay: PASS');
