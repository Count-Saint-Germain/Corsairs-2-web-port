/* Cloudflare Worker (web/cloudflare/worker.js) отдаёт Content-Type по расширению ключа в R2.
   Без записи .mjs модули страницы приходят как application/octet-stream и браузер их не грузит;
   без .mp4 ролик идёт как octet-stream. Проверяем таблицу из реального исходника Worker'а. */
import { test } from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';

const src = readFileSync(fileURLToPath(new URL('../web/cloudflare/worker.js', import.meta.url)), 'utf8');
const TYPES = new Function(`${/const TYPES = (\{[\s\S]*?\n\});/.exec(src)[1].replace(/^/, 'return ')}`)();

test('Worker знает типы всех расширений, которые кладёт make_dist', () => {
  assert.match(TYPES.mjs, /^text\/javascript/);
  assert.match(TYPES.js, /^text\/javascript/);
  assert.equal(TYPES.mp4, 'video/mp4');
  assert.equal(TYPES.wasm, 'application/wasm');
  assert.match(TYPES.html, /^text\/html/);
  assert.equal(TYPES.json, 'application/json');
});

test('Worker отдаёт Accept-Ranges и 206 для Range (видео и докачка)', () => {
  assert.match(src, /Accept-Ranges',\s*'bytes'/);
  assert.match(src, /status = 206/);
});
