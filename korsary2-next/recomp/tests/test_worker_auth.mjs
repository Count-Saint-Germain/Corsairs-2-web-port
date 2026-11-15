/* N2: Cloudflare Worker читает данные игры только при заданном PASSWORD; пустой секрет = закрыто (fail-closed),
   открытый режим — только явным ALLOW_PUBLIC=1; билеты netplay не выдаются/не принимаются без секрета.
     node tests/test_worker_auth.mjs */
import assert from 'node:assert/strict';
import worker from '../web/cloudflare/worker.js';

const bucket = { async get(key) { return key === 'game/manifest.json' ? { size: 2, httpEtag: '"e"', body: new Response('{}').body, writeHttpMetadata() {} } : null; } };
const req = (path, headers = {}) => new Request('https://h.example' + path, { headers });
const basic = (pw) => ({ Authorization: 'Basic ' + Buffer.from('u:' + pw).toString('base64') });

// без секрета и без ALLOW_PUBLIC — закрыто для всего
for (const env of [{ BUCKET: bucket }, { PASSWORD: '', BUCKET: bucket }, { PASSWORD: undefined, ALLOW_PUBLIC: '0', BUCKET: bucket }, { ALLOW_PUBLIC: 'true', BUCKET: bucket }]) {
  for (const p of ['/game/manifest.json', '/index.html', '/']) {
    const r = await worker.fetch(req(p), env);
    assert.equal(r.status, 401, `${JSON.stringify(Object.keys(env))} ${p}: ожидалось 401, получено ${r.status}`);
  }
  assert.equal((await worker.fetch(req('/_netplay_ticket', basic('')), env)).status, 401);
}
// явное открытие
{ const r = await worker.fetch(req('/game/manifest.json'), { ALLOW_PUBLIC: '1', BUCKET: bucket }); assert.equal(r.status, 200); }
// ALLOW_PUBLIC без пароля не выдаёт билетов netplay (пустой HMAC-ключ)
{ const r = await worker.fetch(req('/_netplay_ticket'), { ALLOW_PUBLIC: '1', BUCKET: bucket }); assert.equal(r.status, 403); }
// с паролем: верный — 200, неверный/пустой — 401, ALLOW_PUBLIC на пароль не влияет
const env = { PASSWORD: 's3cret', BUCKET: bucket };
assert.equal((await worker.fetch(req('/game/manifest.json', basic('s3cret')), env)).status, 200);
assert.equal((await worker.fetch(req('/game/manifest.json', basic('wrong')), env)).status, 401);
assert.equal((await worker.fetch(req('/game/manifest.json', basic('')), env)).status, 401);
assert.equal((await worker.fetch(req('/game/manifest.json'), { ...env, ALLOW_PUBLIC: '1' })).status, 401);
// upload по-прежнему требует токен
assert.equal((await worker.fetch(new Request('https://h.example/_upload/x', { method: 'PUT' }), { ...env })).status, 403);
console.log('worker auth: fail-closed PASS');
