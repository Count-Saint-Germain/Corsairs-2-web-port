/* Видеомост. Все ролики игры идут через скриптовую StartPostVideo/StartVideo (PROGRAM/INTERFACE/interface.c):
 * движок создаёт сущность CAviPlayer и шлёт ей имя файла. В этой сборке DirectShow нет, open сущности
 * отказывает, и именно перед этим вызовом хост (recomp/host/video.c) видит настоящее имя ролика
 * («trailer», «temple», «skeleton_on_beach»…, нижний регистр, без расширения). Страница опрашивает запрос каждый
 * кадр и показывает MP4 поверх canvas. Игра на время ролика ПАРКУЕТСЯ в хосте (скрипт считает ролик модальным:
 * по его концу идёт главное меню, следующий логотип, шаг квеста); отказ ролика, отсутствие файла или пропуск
 * никогда не блокируют игру: ответ _port_video_done(1) просто отпускает её, как раньше. Ввод игре на это время
 * закрыт, звук глушится хуком onActive, если он задан.
 *
 * Роликов без файла на диске (логотипы WaltDisney/Bethesda/Akella, credits, sunrise, intro, blaze_grasses_dead) в
 * VIDEO_FILES нет: страница отвечает done(1) на ближайшем кадре.
 *
 * Язык (E3, PORT_SPECIFICATION.md): createVideoPlayer({ lang }) — 'ru' (по умолчанию, поведение прежнее) или 'en'
 * (значение или функция, читается на каждый запрос). По-английски отличается только Invasion (отдельная английская озвучка:
 * videos/English/Invasion.mp4, VIDEO_FILES_EN); остальные ролики — те же файлы (в образах побайтно равны). Логотипы
 * Bethesda/Disney/Akella и Credits по решению пользователя в английском режиме не показываются никогда (EN_SKIP): мост
 * отвечает done(1), даже если файл когда-нибудь появится в VIDEO_FILES. */

const NAME_CAP = 64;
/* Если ролик не показал прогресса дольше этого срока (404 без события error, зависший
 * поток, замерший декодер), оверлей снимается сам — игра не остаётся под чёрным экраном. */
export const STALL_MS = 15000;
const WATCHDOG_TICK_MS = 1000;
const MODIFIER_KEYS = new Set(['Shift', 'Control', 'Alt', 'Meta', 'AltGraph', 'CapsLock', 'NumLock', 'ScrollLock', 'Fn', 'FnLock']);

/* имя из игры (нижний регистр, без расширения) → файл в videos-web (имена — точные имена из RESOURCE/VIDEOS).
 * «invasion» лежит в подпапке Russian (так в этой раздаче игры); английский — VIDEO_FILES_EN. */
export const VIDEO_FILES = {
  trailer: 'videos/Trailer.mp4',
  artefact: 'videos/Artefact.mp4',
  blackpearl: 'videos/BlackPearl.mp4',
  blaze_land_dead: 'videos/Blaze_land_dead.mp4',
  blaze_mutiny_dead: 'videos/Blaze_mutiny_dead.mp4',
  ending: 'videos/Ending.mp4',
  idol: 'videos/Idol.mp4',
  invasion: 'videos/Russian/Invasion.mp4',
  skeleton_on_beach: 'videos/Skeleton_on_beach.mp4',
  storm: 'videos/Storm.mp4',
  temple: 'videos/Temple.mp4',
  undersea: 'videos/Undersea.mp4',
};

/* Английские версии (путь рядом с videos/Russian/…). Только то, что отличается языком. */
export const VIDEO_FILES_EN = {
  invasion: 'videos/English/Invasion.mp4',
};

/* Имена, которые в английском режиме пропускаются всегда (логотипы издателей и ролик Credits: решение пользователя). */
export const EN_SKIP = new Set(['waltdisneylogo', 'bethesdalogo', 'akellalogo', 'credits']);

/* 'en' для значения, начинающегося с «en» (en, EN, en-US, English); всё остальное (в т. ч. сбой функции) — 'ru'. */
export function normalizeLang(v) {
  try { if (typeof v === 'function') v = v(); } catch { return 'ru'; }
  return typeof v === 'string' && /^en/i.test(v.trim()) ? 'en' : 'ru';
}

export function resolveRequest(name, lang = 'ru') {
  if (normalizeLang(lang) === 'en' && EN_SKIP.has(name)) return null;
  return Object.prototype.hasOwnProperty.call(VIDEO_FILES, name) ? name : null;
}

/* URL файла для имени из resolveRequest: английский вариант, если он есть, иначе общий. */
export function videoFile(name, lang = 'ru') {
  if (normalizeLang(lang) === 'en' && Object.prototype.hasOwnProperty.call(VIDEO_FILES_EN, name)) return VIDEO_FILES_EN[name];
  return VIDEO_FILES[name];
}

const warn = (...a) => { try { console.warn(...a); } catch { /* консоли может не быть */ } };

/* Полноэкранный оверлей внутри #stage. `video`, `doc`, `win`, `now`, `pads`, `setTimer` и
 * `clearTimer` вводятся для тестов. onActive(true|false) вызывается на старте и на снятии
 * оверлея (хук для приглушения звука игры); его сбой игре не мешает. */
export function createVideoPlayer({
  mount, video, doc = globalThis.document, win = globalThis.window, onActive, lang = 'ru',
  now = () => globalThis.performance?.now?.() ?? Date.now(),
  pads = () => (globalThis.navigator?.getGamepads ? globalThis.navigator.getGamepads() : []),
  setTimer = (fn, ms) => globalThis.setInterval(fn, ms),
  clearTimer = (id) => globalThis.clearInterval(id),
} = {}) {
  const el = video ?? doc.createElement('video');
  el.playsInline = true;
  el.preload = 'auto';
  el.className = 'video-screen';

  const overlay = doc.createElement('div');
  overlay.className = 'video-overlay hidden';
  overlay.appendChild(el);
  const hint = doc.createElement('div');
  hint.className = 'video-skip';
  const hints = {
    ru: ['Пропустить — любая клавиша, клик или кнопка геймпада', 'Звук отключён браузером. '],
    en: ['Skip — press any key, click, or press a gamepad button', 'Sound was muted by the browser. '],
  };
  let videoLanguage = 'ru';
  hint.textContent = hints[videoLanguage][0];
  overlay.appendChild(hint);
  if (mount) mount.appendChild(overlay);

  let active = null;        // имя играющего ролика | null
  let finished = null;      // код, который вернёт мост после текущего запроса
  let cleanup = null;
  let generation = 0;       // отличает обещания play() прошлого ролика от текущего
  let padWasDown = false;   // любая кнопка геймпада была нажата на прошлом кадре
  let padHold = false;      // кнопка, закрывшая оверлей, ещё удерживается: игре её не показываем
  let pollFailures = 0;

  const anyPadDown = () => {
    let list;
    try { list = pads() || []; } catch { return false; }
    for (const g of Array.from(list)) {
      if (!g || g.connected === false) continue;
      for (const b of g.buttons || []) if (b && (b.pressed || b.value > 0.5)) return true;
    }
    return false;
  };

  function notifyActive(on) {
    if (typeof onActive !== 'function') return;
    try { onActive(on); } catch (e) { warn('video bridge onActive failed:', e); }
  }

  function finish(code) {
    if (!active) return;
    active = null;
    generation++;
    const done = finished;
    finished = null;
    // Каждый шаг изолирован: что бы ни бросил элемент <video>, ответ игре и снятие оверлея выполнятся.
    try { if (cleanup) cleanup(); } catch (e) { warn('video bridge cleanup failed:', e); }
    cleanup = null;
    try { el.pause(); } catch { /* уже остановлен */ }
    try { el.removeAttribute('src'); } catch { /* нечего снимать */ }
    try { el.load(); } catch { /* уже пусто */ }
    try { overlay.classList.add('hidden'); } catch { /* оверлей уже снят */ }
    hint.textContent = hints[videoLanguage][0];
    padHold = anyPadDown();
    notifyActive(false);
    if (done) {
      try { done(code); }   // сбой страницы не должен ломать игру
      catch (e) { warn('video bridge done failed:', e); }
    }
  }

  const onEnded = () => finish(0);
  const onError = () => finish(1);

  function play(guest, file, done, language) {
    videoLanguage = language;
    hint.textContent = hints[videoLanguage][0];
    const mine = ++generation;
    finished = done;
    active = guest;
    let lastProgressAt = now();
    let hiddenPause = false;
    overlay.classList.remove('hidden');
    notifyActive(true);
    el.muted = false;
    el.src = file;
    const rejected = () => {
      if (generation !== mine || !active) return;   // уже завершён: устаревшее отклонение play() игнорируем
      // После долгого простоя (режим привлечения) жеста пользователя могло не быть:
      // пробуем без звука, иначе продолжаем без ролика — как сегодня.
      el.muted = true;
      hint.textContent = hints[videoLanguage][1] + hints[videoLanguage][0];
      let retried;
      try { retried = el.play(); } catch { finish(1); return; }
      if (retried && retried.catch) retried.catch(() => { if (generation === mine) finish(1); });
    };
    let started;
    try { started = el.play(); } catch { started = null; finish(1); return; }
    if (started && started.catch) started.catch(rejected);

    const progress = () => { lastProgressAt = now(); };
    // Перехват на window (фаза capture): пропуск срабатывает и под pointer lock,
    // и до слушателей игры, так что под роликом меню ничего не нажимает.
    const key = (e) => {
      if (e.repeat) { e.stopImmediatePropagation?.(); return; }
      e.stopImmediatePropagation?.();
      if (MODIFIER_KEYS.has(e.key)) return;   // Shift/Ctrl/Alt/Meta: чаще начало сочетания браузера
      // сочетания с Ctrl/Meta/Alt (перезагрузка, полный экран) оставляем браузеру, ролик при этом пропускается
      if (!(e.ctrlKey || e.metaKey || e.altKey)) e.preventDefault?.();
      finish(1);
    };
    const click = (e) => { e.stopImmediatePropagation?.(); e.preventDefault?.(); finish(1); };
    // Страница уходит в фон / BFCache: ролик не должен остаться висеть под замороженной игрой.
    const hide = () => finish(1);
    const visibility = () => {
      if (generation !== mine || !active) return;
      if (doc.hidden) {
        hiddenPause = true;
        try { el.pause(); } catch { /* уже на паузе */ }
      } else if (hiddenPause) {
        hiddenPause = false;
        progress();
        try { const p = el.play(); if (p && p.catch) p.catch(() => finish(1)); } catch { finish(1); }
      }
    };
    const watchdog = setTimer(() => {
      if (generation !== mine || !active || hiddenPause || doc.hidden) return;
      if (now() - lastProgressAt > STALL_MS) {
        warn('video bridge: no playback progress, skipping the video');
        finish(1);
      }
    }, WATCHDOG_TICK_MS);
    win.addEventListener('keydown', key, true);
    win.addEventListener('mousedown', click, true);
    win.addEventListener('pagehide', hide, true);
    doc.addEventListener?.('visibilitychange', visibility);
    for (const name of ['playing', 'timeupdate', 'loadeddata', 'canplay']) el.addEventListener(name, progress);
    el.addEventListener('ended', onEnded);
    el.addEventListener('error', onError);
    cleanup = () => {
      clearTimer(watchdog);
      win.removeEventListener('keydown', key, true);
      win.removeEventListener('mousedown', click, true);
      win.removeEventListener('pagehide', hide, true);
      doc.removeEventListener?.('visibilitychange', visibility);
      for (const name of ['playing', 'timeupdate', 'loadeddata', 'canplay']) el.removeEventListener(name, progress);
      el.removeEventListener('ended', onEnded);
      el.removeEventListener('error', onError);
    };
  }

  /* Кнопки геймпада: нажатие закрывает ролик, а пока кнопка, закрывшая его, удерживается, игре её
   * не показываем (blocksInput) — иначе то же нажатие активировало бы пункт меню под роликом. */
  function trackPads() {
    const down = anyPadDown();
    if (active && down && !padWasDown) finish(1);
    if (!down) padHold = false;
    padWasDown = down;
  }

  function pollRequest(M) {
    if (typeof M?._port_video_poll !== 'function' || typeof M?._port_video_done !== 'function') return;
    if (active) {
      M._port_video_poll(0, 0);            // только «жив»: хост не паркует игру перед страницей, которая молчит
      return;                              // ровно один активный запрос
    }
    const buf = M._port_video_name_buf();
    const len = M._port_video_poll(buf, NAME_CAP);
    if (!len) return;
    // Shared Wasm memory is rejected by TextDecoder in some browsers; slice copies
    // the bounded name to a regular ArrayBuffer before decoding.
    const bytes = new Uint8Array(M.wasmMemory.buffer, buf, Math.min(len, NAME_CAP - 1)).slice();
    const name = new TextDecoder().decode(bytes);
    const language = normalizeLang(lang);  // читается на каждый запрос: язык задаёт страница
    const guest = len > NAME_CAP - 1 ? null : resolveRequest(name, language);
    if (!guest) {
      M._port_video_done(1);               // неизвестное имя, файла нет или ролик не показывается в этом языке — сразу пропускаем
      return;
    }
    play(guest, videoFile(guest, language), (code) => M._port_video_done(code), language);
  }

  return {
    overlay,
    get active() { return active; },
    /* true, пока игре нельзя отдавать ввод геймпада (ролик идёт или закрывшая его кнопка удержана) */
    get blocksInput() { return !!active || padHold; },
    /* Принудительное снятие (например, при выгрузке страницы): ответ игре done(code). */
    abort(code = 1) { finish(code); },

    /* Один кадр опроса моста. M — Module сборки; отсутствие экспортов
     * (чужая/старая сборка) ничего не ломает. Второй аргумент (время без ввода,
     * наследие прежней схемы) не используется. Любое исключение
     * внутри — fail-open: оверлей снимается, игре отвечаем done(1), а кадровый
     * цикл страницы (где вызван poll) не прерывается. */
    poll(M) {
      try {
        trackPads();
        pollRequest(M);
      } catch (e) {
        if (pollFailures++ < 3) warn('video bridge poll failed:', e);   // кадров много: не засоряем консоль
        if (active) finish(1);
        else {
          try { M?._port_video_done?.(1); } catch { /* хост недоступен: игра и так не ждёт */ }
        }
      }
    },
  };
}
