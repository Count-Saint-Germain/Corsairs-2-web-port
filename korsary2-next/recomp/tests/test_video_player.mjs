/* Жизненный цикл видеомоста (recomp/web/video-player.mjs) на моках <video>, window и Module.
   Моки воспроизводят то, что важно для корректности: порядок capture/bubble и
   stopImmediatePropagation на window, обещания play() с управляемым исходом, часы и таймеры
   как внедряемые зависимости. Что мок НЕ проверяет (настоящий декодер, автоплей-политику,
   BFCache, звук) — живая приёмка. */
import { test } from 'node:test';
import assert from 'node:assert/strict';
import { existsSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import {
  createVideoPlayer, resolveRequest, videoFile, normalizeLang, VIDEO_FILES, VIDEO_FILES_EN, EN_SKIP, STALL_MS,
} from '../web/video-player.mjs';

/* ---------- моки ---------- */

function makeTarget() {
  const l = [];   // { type, fn, capture }
  return {
    l,
    addEventListener(type, fn, capture = false) { l.push({ type, fn, capture: !!capture }); },
    removeEventListener(type, fn, capture = false) {
      const i = l.findIndex((x) => x.type === type && x.fn === fn && x.capture === !!capture);
      if (i >= 0) l.splice(i, 1);
    },
    count(type) { return l.filter((x) => x.type === type).length; },
    /* порядок как в браузере для цели window: сначала capture-слушатели в порядке регистрации,
       затем bubble; stopImmediatePropagation прекращает всё. */
    dispatch(type, init = {}) {
      let stopped = false, prevented = false;
      const e = { type, repeat: false, key: 'a', ...init,
        stopImmediatePropagation() { stopped = true; }, preventDefault() { prevented = true; } };
      for (const phase of [true, false])
        for (const x of [...l]) {
          if (stopped) break;
          if (x.type === type && x.capture === phase) x.fn(e);
        }
      return { stopped, prevented };
    },
  };
}

function makeEl() {
  const t = makeTarget();
  const el = Object.assign(t, {
    className: '', textContent: '', playsInline: false, muted: false, src: undefined, paused: true,
    children: [],
    classes: new Set(['hidden']),
    plays: [], loads: 0, pauses: 0,
    /* сценарий play(): 'ok' | 'reject-once' | 'reject' | 'throw' | 'manual' */
    playMode: 'ok', throwOnPause: false,
    classList: { add(c) { el.classes.add(c); }, remove(c) { el.classes.delete(c); } },
    appendChild(c) { el.children.push(c); },
    removeAttribute(n) { delete el[n]; },
    load() { el.loads++; },
    pause() { el.pauses++; if (el.throwOnPause) throw new Error('pause failed'); el.paused = true; },
    play() {
      const rec = { muted: el.muted };
      el.plays.push(rec);
      if (el.playMode === 'throw') throw new Error('play failed');
      const first = el.plays.length === 1;
      if (el.playMode === 'manual') {
        return new Promise((resolve, reject) => { rec.resolve = resolve; rec.reject = reject; });
      }
      if (el.playMode === 'reject' || (el.playMode === 'reject-once' && first)) {
        return Promise.reject(Object.assign(new Error('blocked'), { name: 'NotAllowedError' }));
      }
      el.paused = false;
      return Promise.resolve();
    },
  });
  return el;
}

function makeDoc() {
  const t = makeTarget();
  t.hidden = false;
  t.createElement = () => makeEl();
  return t;
}

const flush = () => new Promise((r) => setImmediate(r));

/* Module-мок: хост-состояние (один запрос), как у host/video.c. */
function fakeM(name = 'trailer', buf = new ArrayBuffer(256)) {
  const m = {
    wasmMemory: { buffer: buf }, done: [], pending: name !== null, polls: 0,
    _port_video_name_buf() { return 0; },
    _port_video_poll(out, cap) {
      m.polls++;
      if (!m.pending) return 0;
      const bytes = new TextEncoder().encode(m.name ?? name);
      new Uint8Array(buf).set(bytes);
      return bytes.length;
    },
    _port_video_done(code) { m.done.push(code); m.pending = false; },
  };
  return m;
}

function fresh(opts = {}) {
  const win = makeTarget();
  const doc = makeDoc();
  const video = makeEl();
  const clock = { t: 1_000_000 };
  const timers = [];
  const padState = { down: false };
  const activeLog = [];
  const player = createVideoPlayer({
    mount: null, video, doc, win,
    now: () => clock.t,
    pads: () => (padState.down ? [{ connected: true, buttons: [{ pressed: true, value: 1 }] }] : [{ connected: true, buttons: [{ pressed: false, value: 0 }] }]),
    setTimer: (fn, ms) => { const id = { fn, ms, cleared: false }; timers.push(id); return id; },
    clearTimer: (id) => { id.cleared = true; },
    onActive: (on) => { activeLog.push(on); if (opts.hookThrows) throw new Error('hook failed'); },
    ...('lang' in opts ? { lang: opts.lang } : {}),
  });
  const tick = () => timers.filter((x) => !x.cleared).forEach((x) => x.fn());
  return { win, doc, video, clock, player, timers, padState, tick, activeLog };
}

const game = (win) => {   // «игра»: bubble-слушатели window, зарегистрированные раньше плеера
  const seen = { keydown: 0, keyup: 0, mousedown: 0 };
  for (const type of Object.keys(seen)) win.addEventListener(type, () => { seen[type]++; }, false);
  return seen;
};

const listenerTotal = ({ win, doc, video }) =>
  win.l.length + doc.l.length + video.l.length;

/* ---------- сопоставление запроса с роликом ---------- */

test('shared wasm memory: декодер, запрещающий shared views, получает копию и воспроизведение работает', () => {
  const NativeTextDecoder = globalThis.TextDecoder;
  let decodeCalls = 0;
  globalThis.TextDecoder = class extends NativeTextDecoder {
    decode(input, options) {
      if (input?.buffer instanceof SharedArrayBuffer)
        throw new TypeError('shared views are not accepted');
      decodeCalls++;
      return super.decode(input, options);
    }
  };
  try {
    const trailer = fresh({ lang: 'en' });
    const m = fakeM('trailer', new SharedArrayBuffer(256));
    trailer.player.poll(m);
    assert.equal(trailer.player.active, 'trailer');
    assert.equal(trailer.video.src, 'videos/Trailer.mp4');
    assert.deepEqual(m.done, []);
    trailer.video.dispatch('ended');
    assert.deepEqual(m.done, [0]);

    const invasion = fresh({ lang: 'en' });
    const m2 = fakeM('invasion', new SharedArrayBuffer(256));
    invasion.player.poll(m2);
    assert.equal(invasion.video.src, 'videos/English/Invasion.mp4');
    invasion.player.abort();
    assert.deepEqual(m2.done, [1]);

    const skipped = fresh({ lang: 'en' });
    const m3 = fakeM('waltdisneylogo', new SharedArrayBuffer(256));
    skipped.player.poll(m3);
    assert.equal(skipped.player.active, null);
    assert.deepEqual(m3.done, [1]);
    assert.equal(decodeCalls, 3);
  } finally {
    globalThis.TextDecoder = NativeTextDecoder;
  }
});

test('resolveRequest: настоящие имена роликов из скриптов игры; регистр и лишнее не принимаются', () => {
  // имена в том виде, в каком хост (host/video.c) отдаёт базовое имя файла: нижний регистр, без расширения
  for (const n of ['trailer', 'temple', 'blackpearl', 'artefact', 'ending', 'storm', 'idol', 'invasion',
    'skeleton_on_beach', 'undersea', 'blaze_land_dead', 'blaze_mutiny_dead']) assert.equal(resolveRequest(n), n, n);
  // нет файла на диске игры (credits.wmv, логотипы, sunrise, intro) и прежнее имя схемы с отказом VM
  for (const n of ['credits', 'sunrise', 'intro', 'waltdisneylogo', 'bethesdalogo', 'akellalogo', 'blaze_grasses_dead',
    'StartPostVideo', 'Trailer', 'trailer ', 'trailerx', '', 'constructor', '__proto__', 'toString']) assert.equal(resolveRequest(n), null, n);
});

test('карта роликов: все 12 файлов videos-web, пути под /videos/ (одна подпапка), только mp4', () => {
  assert.equal(Object.keys(VIDEO_FILES).length, 12);
  for (const [name, rel] of Object.entries(VIDEO_FILES)) {
    assert.match(rel, /^videos\/(?:Russian\/)?[A-Za-z0-9_.\-]+\.mp4$/, rel);
    assert.equal(rel.toLowerCase().endsWith('/' + name + '.mp4'), true, `${name} -> ${rel}`);   // имя файла = имя запроса
    if (existsSync(new URL('../../../videos-web/', import.meta.url)))
      assert.ok(existsSync(fileURLToPath(new URL('../../../videos-web/' + rel.slice('videos/'.length), import.meta.url))), rel);
  }
});

/* ---------- язык (E3): английский режим ---------- */

test('normalizeLang: en/EN/en-US/English — английский, всё остальное и сбой функции — русский', () => {
  for (const v of ['en', 'EN', 'en-US', 'English', ' en ']) assert.equal(normalizeLang(v), 'en', String(v));
  for (const v of ['ru', 'RU', 'russian', '', 'de', 'fr', undefined, null, 0, {}, ['en']]) assert.equal(normalizeLang(v), 'ru', String(v));
  assert.equal(normalizeLang(() => 'en'), 'en');
  assert.equal(normalizeLang(() => 'ru'), 'ru');
  assert.equal(normalizeLang(() => { throw new Error('boom'); }), 'ru');
});

test('resolveRequest/videoFile: русский — как раньше; английский — Invasion по-английски, логотипы и Credits пропускаются', () => {
  // обратная совместимость: один аргумент и 'ru' дают прежний результат
  for (const n of Object.keys(VIDEO_FILES)) { assert.equal(resolveRequest(n, 'ru'), n); assert.equal(videoFile(n), VIDEO_FILES[n]); assert.equal(videoFile(n, 'ru'), VIDEO_FILES[n]); }
  assert.equal(videoFile('invasion', 'ru'), 'videos/Russian/Invasion.mp4');
  assert.equal(videoFile('invasion', 'en'), 'videos/English/Invasion.mp4');
  assert.equal(videoFile('invasion', 'EN-us'), 'videos/English/Invasion.mp4');
  // остальные 11 роликов в образах побайтно равны: те же файлы в обоих языках
  for (const n of Object.keys(VIDEO_FILES).filter((x) => x !== 'invasion')) { assert.equal(resolveRequest(n, 'en'), n, n); assert.equal(videoFile(n, 'en'), VIDEO_FILES[n], n); }
  assert.deepEqual(Object.keys(VIDEO_FILES_EN), ['invasion']);
  assert.match(VIDEO_FILES_EN.invasion, /^videos\/English\/Invasion\.mp4$/);
  assert.deepEqual([...EN_SKIP].sort(), ['akellalogo', 'bethesdalogo', 'credits', 'waltdisneylogo']);
  for (const n of EN_SKIP) { assert.equal(resolveRequest(n, 'en'), null, n); assert.equal(resolveRequest(n, 'ru'), null, n); }   // файла нет и в русском
});

test('EN_SKIP сильнее карты роликов: если файл логотипа/Credits появится в VIDEO_FILES, английский режим его всё равно не покажет', () => {
  VIDEO_FILES.credits = 'videos/Credits.mp4';
  VIDEO_FILES.bethesdalogo = 'videos/BethesdaLogo.mp4';
  try {
    assert.equal(resolveRequest('credits', 'en'), null);
    assert.equal(resolveRequest('bethesdalogo', 'en'), null);
    assert.equal(resolveRequest('credits', 'ru'), 'credits');            // русский режим не затронут
    assert.equal(resolveRequest('credits'), 'credits');
    const { player } = fresh({ lang: 'en' });
    const m = fakeM('bethesdalogo');
    player.poll(m);
    assert.deepEqual(m.done, [1]);
    assert.equal(player.active, null);
  } finally {
    delete VIDEO_FILES.credits;
    delete VIDEO_FILES.bethesdalogo;
  }
  assert.equal(Object.keys(VIDEO_FILES).length, 12);
});

test('плеер: язык по умолчанию русский; английский Invasion, логотипы/Credits — немедленное done(1); язык читается на каждый запрос', () => {
  let { player, video } = fresh();                                       // без lang: прежнее поведение
  let m = fakeM('invasion');
  player.poll(m);
  assert.equal(video.src, 'videos/Russian/Invasion.mp4');
  ({ player, video } = fresh({ lang: 'ru' }));
  m = fakeM('invasion');
  player.poll(m);
  assert.equal(video.src, 'videos/Russian/Invasion.mp4');
  ({ player, video } = fresh({ lang: 'en' }));
  m = fakeM('invasion');
  player.poll(m);
  assert.equal(player.active, 'invasion');
  assert.equal(video.src, 'videos/English/Invasion.mp4');
  video.dispatch('ended');
  assert.deepEqual(m.done, [0]);
  for (const n of ['credits', 'waltdisneylogo', 'bethesdalogo', 'akellalogo']) {
    ({ player, video } = fresh({ lang: 'en' }));
    m = fakeM(n);
    player.poll(m);
    assert.equal(player.active, null, n);
    assert.deepEqual(m.done, [1], n);
    assert.equal(video.src, undefined, n);
  }
  ({ player, video } = fresh({ lang: 'en' }));                           // общий ролик: тот же файл
  m = fakeM('trailer');
  player.poll(m);
  assert.equal(video.src, 'videos/Trailer.mp4');
  // функция языка: страница может определить язык позже создания плеера
  let cur = 'ru';
  ({ player, video } = fresh({ lang: () => cur }));
  m = fakeM('invasion');
  player.poll(m);
  assert.equal(video.src, 'videos/Russian/Invasion.mp4');
  player.abort(1);
  cur = 'en';
  m = fakeM('invasion');
  player.poll(m);
  assert.equal(video.src, 'videos/English/Invasion.mp4');
  // сбой функции языка не ломает кадровый цикл: русский
  ({ player, video } = fresh({ lang: () => { throw new Error('lang failed'); } }));
  m = fakeM('invasion');
  player.poll(m);
  assert.equal(video.src, 'videos/Russian/Invasion.mp4');
});

/* ---------- основной цикл ---------- */

test('запрос после долгого простоя играет trailer и завершается done(0), оверлей и слушатели снимаются', () => {
  const ctx = fresh();
  const { video, player, activeLog } = ctx;
  const m = fakeM();
  const before = listenerTotal(ctx);
  player.poll(m, 60000);
  assert.equal(player.active, 'trailer');
  assert.equal(video.src, 'videos/Trailer.mp4');
  assert.equal(video.muted, false);
  assert.equal(player.overlay.classes.has('hidden'), false, 'оверлей показан');
  assert.equal(m.done.length, 0);
  assert.deepEqual(activeLog, [true]);
  video.dispatch('ended');
  assert.deepEqual(m.done, [0]);
  assert.equal(player.active, null);
  assert.equal(video.src, undefined);
  assert.deepEqual(activeLog, [true, false]);
  assert.equal(player.overlay.classes.has('hidden'), true, 'оверлей снят');
  assert.equal(listenerTotal(ctx), before, 'после завершения не остаётся слушателей');
  assert.ok(ctx.timers.every((x) => x.cleared), 'сторожевой таймер остановлен');
});

test('ролик без файла (credits, логотипы) — немедленное done(1); известный играет при любом времени простоя', () => {
  let { player } = fresh();
  let m = fakeM('credits');
  player.poll(m, 1500);
  assert.equal(player.active, null);
  assert.deepEqual(m.done, [1]);
  for (const idle of [0, 1500, 44500, 99999, undefined]) {
    ({ player } = fresh());
    m = fakeM('trailer');
    player.poll(m, idle);
    assert.equal(player.active, 'trailer', String(idle));
  }
  ({ player } = fresh());
  m = fakeM('invasion');
  player.poll(m);
  assert.equal(player.active, 'invasion');
});

test('пока ролик идёт, страница только сообщает хосту «жив» (poll без буфера) и не берёт второй запрос', () => {
  const { player } = fresh();
  const calls = [];
  const m = fakeM('trailer');
  const inner = m._port_video_poll;
  m._port_video_poll = (out, cap) => { calls.push([out, cap]); return inner(out, cap); };
  player.poll(m);
  assert.deepEqual(calls, [[0, 64]]);                // взяли запрос: буфер + ёмкость
  calls.length = 0;
  player.poll(m); player.poll(m);
  assert.deepEqual(calls, [[0, 0], [0, 0]]);         // heartbeat: ни буфера, ни ёмкости -> хост не считает это «забрал»
  assert.equal(player.active, 'trailer');
});

test('ошибка загрузки завершает done(1) ровно один раз; поздние события не дают второго ответа', () => {
  const { video, player } = fresh();
  const m = fakeM();
  player.poll(m, 60000);
  video.dispatch('error');
  video.dispatch('error');
  video.dispatch('ended');
  assert.deepEqual(m.done, [1]);
  assert.equal(player.active, null);
});

test('неизвестное имя, слишком длинное имя и отсутствие экспортов не запускают ролик', () => {
  let { player } = fresh();
  let m = fakeM(); m.name = 'SomethingElse';
  player.poll(m, 0);
  assert.deepEqual(m.done, [1]);
  ({ player } = fresh());
  m = fakeM(); m.name = 'trailer' + 'x'.repeat(60);
  m._port_video_poll = () => 74;                   // полная длина больше буфера: усечённое имя ничего не значит
  player.poll(m, 99999);
  assert.deepEqual(m.done, [1]);
  assert.equal(player.active, null);
  ({ player } = fresh());
  const bare = { done: [] };
  player.poll(bare, 99999);                        // чужая/старая сборка без экспортов
  player.poll(undefined, 99999);
  assert.deepEqual(bare.done, []);
  const m2 = fakeM(); delete m2._port_video_done;
  player.poll(m2, 99999);
  assert.equal(player.active, null);
});

test('повторный запрос после done работает, параллельные poll — ровно один активный; слушатели не копятся', () => {
  const ctx = fresh();
  const { video, player } = ctx;
  const base = listenerTotal(ctx);
  for (let i = 0; i < 3; i++) {
    const m = fakeM();
    player.poll(m, 60000);
    player.poll(m, 60000);                         // второй poll при активном — игнор
    assert.equal(player.active, 'trailer');
    assert.equal(video.plays.length, i + 1);
    assert.ok(listenerTotal(ctx) > base);
    video.dispatch('ended');
    assert.deepEqual(m.done, [0]);
    assert.equal(listenerTotal(ctx), base, `цикл ${i}: утечки слушателей`);
  }
  assert.equal(ctx.timers.length, 3);
  assert.ok(ctx.timers.every((x) => x.cleared));
});

/* ---------- пропуск ---------- */

test('пропуск клавишей: событие не доходит до игры, keyup доходит; ответ done(1)', () => {
  const { win, player } = fresh();
  const seen = game(win);
  // «игра» должна быть зарегистрирована ДО плеера в реальной странице; порядок capture/bubble решает всё
  const m = fakeM();
  player.poll(m, 60000);
  const r = win.dispatch('keydown', { key: 'Enter' });
  assert.deepEqual(m.done, [1]);
  assert.equal(seen.keydown, 0);
  assert.equal(r.stopped, true);
  assert.equal(r.prevented, true);
  win.dispatch('keyup', { key: 'Enter' });
  assert.equal(seen.keyup, 1, 'отпускание клавиши игра видеть обязана (иначе залипание)');
  win.dispatch('keydown', { key: 'x' });
  assert.equal(seen.keydown, 1, 'после ролика ввод снова у игры');
});

test('чистый модификатор не пропускает ролик, повтор клавиши не пропускает, Ctrl+R оставлен браузеру', () => {
  const { win, player } = fresh();
  const seen = game(win);
  const m = fakeM();
  player.poll(m, 60000);
  win.dispatch('keydown', { key: 'Shift' });
  win.dispatch('keydown', { key: 'a', repeat: true });
  assert.equal(player.active, 'trailer');
  assert.deepEqual(m.done, []);
  assert.equal(seen.keydown, 0, 'пока ролик идёт, игра клавиш не видит');
  const r = win.dispatch('keydown', { key: 'r', ctrlKey: true });
  assert.equal(r.prevented, false, 'сочетание браузера не отменяется');
  assert.deepEqual(m.done, [1]);
});

test('пропуск кликом: mousedown не доходит до игры', () => {
  const { win, player } = fresh();
  const seen = game(win);
  const m = fakeM();
  player.poll(m, 60000);
  win.dispatch('mousedown', { button: 0 });
  assert.deepEqual(m.done, [1]);
  assert.equal(seen.mousedown, 0);
});

test('кнопка геймпада закрывает ролик; пока её держат, игре ввод закрыт; уже удержанная не пропускает повторно', () => {
  const ctx = fresh();
  const { player, padState } = ctx;
  const m = fakeM();
  player.poll(m, 60000);
  assert.equal(player.active, 'trailer');
  assert.equal(player.blocksInput, true);
  player.poll(m, 60000);
  assert.equal(player.active, 'trailer');
  padState.down = true; player.poll(m, 60000);     // нажатие
  assert.deepEqual(m.done, [1]);
  assert.equal(player.active, null);
  assert.equal(player.blocksInput, true, 'нажатие, закрывшее ролик, не должно попасть в меню');
  player.poll(m, 60000);
  assert.equal(player.blocksInput, true);
  padState.down = false; player.poll(m, 60000);
  assert.equal(player.blocksInput, false);
});

test('ролик закрыт клавишей, кнопка геймпада в это время не удерживалась: блокировки ввода нет', () => {
  const { win, player } = fresh();
  player.poll(fakeM(), 60000);
  win.dispatch('keydown', { key: 'Enter' });
  assert.equal(player.blocksInput, false);
});

/* ---------- автоплей ---------- */

test('подсказка и предупреждение о звуке учитывают язык каждого запроса', async () => {
  let language = 'ru';
  const { video, player } = fresh({ lang: () => language });
  const first = fakeM('trailer');
  player.poll(first);
  assert.match(player.overlay.children.at(-1).textContent, /^Пропустить/);
  video.dispatch('ended');

  language = 'en';
  video.plays.length = 0; // make the next play the first call in the fake's reject-once scenario
  video.playMode = 'reject-once';
  const second = fakeM('trailer');
  player.poll(second);
  assert.match(player.overlay.children.at(-1).textContent, /^Skip/);
  await flush();
  assert.match(player.overlay.children.at(-1).textContent, /^Sound was muted by the browser\. Skip/);
  video.dispatch('ended');
  assert.equal(player.overlay.children.at(-1).textContent, 'Skip — press any key, click, or press a gamepad button');
  assert.deepEqual(second.done, [0]);

  language = 'ru';
  const third = fakeM('trailer');
  player.poll(third);
  assert.match(player.overlay.children.at(-1).textContent, /^Пропустить/);
  video.dispatch('ended');
});

test('автоплей отклонён: повтор без звука, подсказка об этом; второй отказ — done(1)', async () => {
  const { video, player } = fresh();
  video.playMode = 'reject-once';
  const m = fakeM();
  player.poll(m, 60000);
  await flush();
  assert.equal(video.plays.length, 2);
  assert.equal(video.plays[0].muted, false);
  assert.equal(video.plays[1].muted, true);
  assert.equal(player.active, 'trailer');
  assert.match(player.overlay.children.at(-1).textContent, /Звук отключён/);
  video.dispatch('ended');
  assert.deepEqual(m.done, [0]);
  assert.doesNotMatch(player.overlay.children.at(-1).textContent, /Звук отключён/, 'подсказка возвращается к обычной');

  const b = fresh();
  b.video.playMode = 'reject';
  const m2 = fakeM();
  b.player.poll(m2, 60000);
  await flush();
  assert.deepEqual(m2.done, [1]);
  assert.equal(b.player.active, null);
});

test('play() бросает синхронно — fail-open done(1), оверлей не остаётся', () => {
  const ctx = fresh();
  ctx.video.playMode = 'throw';
  const m = fakeM();
  assert.doesNotThrow(() => ctx.player.poll(m, 60000));
  assert.deepEqual(m.done, [1]);
  assert.equal(ctx.player.active, null);
  assert.deepEqual(ctx.activeLog, [true, false]);
});

test('устаревшее отклонение play() прошлого ролика не трогает следующий', async () => {
  const ctx = fresh();
  const { video, player, win } = ctx;
  video.playMode = 'manual';
  const a = fakeM();
  player.poll(a, 60000);
  const first = video.plays[0];
  win.dispatch('keydown', { key: 'a' });           // пропуск до решения браузера по автоплею
  assert.deepEqual(a.done, [1]);
  const b = fakeM();
  player.poll(b, 60000);                           // новый запрос, новый play()
  assert.equal(player.active, 'trailer');
  first.reject(Object.assign(new Error('aborted'), { name: 'AbortError' }));
  await flush();
  assert.equal(player.active, 'trailer', 'новый ролик не должен снять чужой отказ');
  assert.equal(video.muted, false);
  assert.deepEqual(b.done, []);
  video.plays[1].resolve();
});

/* ---------- сторожевые условия ---------- */

test('сторож: нет прогресса дольше STALL_MS — done(1); прогресс продлевает срок', () => {
  const ctx = fresh();
  const { video, player, clock } = ctx;
  const m = fakeM();
  player.poll(m, 60000);
  clock.t += STALL_MS - 1; ctx.tick();
  assert.equal(player.active, 'trailer');
  video.dispatch('timeupdate');                    // прогресс
  clock.t += STALL_MS - 1; ctx.tick();
  assert.equal(player.active, 'trailer');
  clock.t += 2; ctx.tick();                        // теперь дольше срока без прогресса
  assert.deepEqual(m.done, [1]);
  assert.equal(player.active, null);
  assert.ok(ctx.timers.every((x) => x.cleared));
});

test('скрытая вкладка: ролик ставится на паузу, сторож молчит; возврат — продолжение', () => {
  const ctx = fresh();
  const { video, player, doc, clock } = ctx;
  const m = fakeM();
  player.poll(m, 60000);
  doc.hidden = true; doc.dispatch('visibilitychange');
  assert.equal(video.paused, true);
  clock.t += STALL_MS * 4; ctx.tick();
  assert.equal(player.active, 'trailer', 'пока вкладка скрыта, сторож не снимает ролик');
  doc.hidden = false; doc.dispatch('visibilitychange');
  assert.equal(video.paused, false);
  assert.equal(video.plays.length, 2);
  clock.t += STALL_MS - 1; ctx.tick();
  assert.equal(player.active, 'trailer', 'отсчёт сторожа начат заново после возврата');
});

test('pagehide (уход/BFCache) снимает ролик и отвечает игре done(1)', () => {
  const { win, player, video } = fresh();
  const m = fakeM();
  player.poll(m, 60000);
  win.dispatch('pagehide');
  assert.deepEqual(m.done, [1]);
  assert.equal(player.active, null);
  assert.equal(video.src, undefined);
});

test('abort() снимает активный ролик; без ролика ничего не делает', () => {
  const { player } = fresh();
  player.abort();
  const m = fakeM();
  player.poll(m, 60000);
  player.abort(1);
  assert.deepEqual(m.done, [1]);
  player.abort(1);
  assert.deepEqual(m.done, [1]);
});

/* ---------- отказоустойчивость ---------- */

test('сбои <video>, done и хука onActive не мешают ответу игре и снятию оверлея', () => {
  const ctx = fresh({ hookThrows: true });
  const { video, player } = ctx;
  video.throwOnPause = true;
  const m = fakeM();
  player.poll(m, 60000);
  assert.equal(player.active, 'trailer');
  video.dispatch('ended');
  assert.deepEqual(m.done, [0]);
  assert.equal(player.active, null);

  const c2 = fresh();
  const m2 = fakeM();
  m2._port_video_done = () => { throw new Error('host gone'); };
  c2.player.poll(m2, 60000);
  assert.doesNotThrow(() => c2.video.dispatch('ended'));
  assert.equal(c2.player.active, null);
});

test('исключение внутри poll не выходит в кадровый цикл страницы (fail-open)', () => {
  const ctx = fresh();
  const m = fakeM();
  delete m.wasmMemory;                             // чтение имени бросит
  assert.doesNotThrow(() => ctx.player.poll(m, 60000));
  assert.deepEqual(m.done, [1], 'запрос закрыт, игра не ждёт');
  assert.equal(ctx.player.active, null);

  const m2 = fakeM();
  m2._port_video_poll = () => { throw new Error('boom'); };
  m2._port_video_done = (c) => { m2.done.push(c); throw new Error('boom again'); };
  assert.doesNotThrow(() => ctx.player.poll(m2, 60000));
  assert.doesNotThrow(() => ctx.player.poll(m2, 60000));
});

test('нет активного запроса: poll ничего не делает', () => {
  const { player } = fresh();
  const m = fakeM(null);
  player.poll(m, 0);
  assert.deepEqual(m.done, []);
  assert.equal(player.blocksInput, false);
});
