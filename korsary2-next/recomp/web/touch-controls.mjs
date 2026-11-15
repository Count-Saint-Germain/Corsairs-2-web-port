/* Optional solo touch controls. These send the same input bridge events as the
 * keyboard and mouse. The game and the player's bindings remain authoritative. */

// Aggregate independent physical and touch sources: releasing one must never
// release a key or mouse button still held by the other.
export function createInputMux(bridge) {
  const keys = [new Set(), new Set()], buttons = [new Set(), new Set()];
  function set(collection, source, code, down, output) {
    const mine = collection[source], other = collection[1 - source];
    if (down === mine.has(code)) return;
    if (down) { mine.add(code); if (!other.has(code)) output(code, 1); }
    else { mine.delete(code); if (!other.has(code)) output(code, 0); }
  }
  return {
    key: (source, code, down) => set(keys, source, code, !!down, bridge.key),
    button: (source, code, down) => set(buttons, source, code, !!down, bridge.button),
    move: (x, y) => bridge.move(x, y),
  };
}

export function mountTouchControls({ root, win = window, doc = document, input, lang = 'ru', activity = () => {}, consumePress = () => false }) {
  if (!root || !input) throw new TypeError('touch controls require a root and input bridge');
  const en = lang === 'en';
  if (root.hasAttribute('data-aria-ru') && root.hasAttribute('data-aria-en')) root.setAttribute('aria-label', root.dataset[en ? 'ariaEn' : 'ariaRu']);
  root.querySelectorAll('[data-ru][data-en]').forEach(el => { el.textContent = el.dataset[en ? 'en' : 'ru']; });
  root.querySelectorAll('[data-aria-ru][data-aria-en]').forEach(el => el.setAttribute('aria-label', el.dataset[en ? 'ariaEn' : 'ariaRu']));
  const panel = root.querySelector('[data-touch-panel]');
  const toggle = root.querySelector('[data-touch-toggle]');
  const tabs = [...root.querySelectorAll('[data-touch-tab]')];
  const groups = [...root.querySelectorAll('[data-touch-group]')];
  const active = new Map(), counts = new Map();
  // Only suppress releases whose press was consumed by a panel button. A
  // keyup can otherwise belong to a game key pressed before focus moved here.
  const uiKeys = new Set();
  let sequence = 0;
  const listen = (target, type, fn, options) => target.addEventListener(type, fn, options);
  // preventDefault suppresses the browser's compatibility mouse event. Count
  // the actual touch, including tab/toggle taps, for the game's idle timer.
  listen(root, 'pointerdown', activity, true);
  listen(root, 'pointermove', e => { if (active.has(e.pointerId)) activity(); }, true);
  function send(kind, code, down) { if (kind === 'key') input.key(code, down); else input.button(code, down); }
  function change(kind, code, delta) {
    const id = `${kind}:${code}`, old = counts.get(id) || 0, next = old + delta;
    if (next < 0) return;
    if (!old && next) send(kind, code, 1);
    if (old && !next) send(kind, code, 0);
    if (next) counts.set(id, next); else counts.delete(id);
  }
  function release(id, allowTap = false) {
    const a = active.get(id); if (!a) return;
    active.delete(id);
    if (a.kind === 'pad') {
      if (allowTap && !a.moved) { change('button', 0, 1); change('button', 0, -1); }
    } else change(a.kind, a.code, -1);
    if (![...active.values()].some(other => other.el === a.el)) a.el.classList?.remove('touch-pressed');
  }
  function releaseAll() { for (const id of [...active.keys()]) release(id); }
  for (const el of root.querySelectorAll('[data-touch-key], [data-touch-mouse], [data-touch-pad]')) {
    const isPad = el.hasAttribute('data-touch-pad');
    const kind = isPad ? 'pad' : el.hasAttribute('data-touch-key') ? 'key' : 'button';
    const code = Number(kind === 'key' ? el.dataset.touchKey : el.dataset.touchMouse);
    const keyPrefix = `kbd:${++sequence}:`;
    const elementKeyId = e => keyPrefix + (e.code || e.key);
    function press(id, x, y) {
      if (active.has(id)) return;
      active.set(id, { kind, code, x, y, moved: false, el });
      if (!isPad) change(kind, code, 1);
      el.classList?.add('touch-pressed');
    }
    listen(el, 'pointerdown', e => {
      if (e.button !== 0 || active.has(e.pointerId)) return;
      e.preventDefault(); e.stopPropagation();
      // A touch that skips a video must not also activate the game beneath it.
      if (consumePress()) return;
      press(e.pointerId, e.clientX, e.clientY);
      try { el.setPointerCapture(e.pointerId); } catch { /* pointer may already be gone */ }
    });
    listen(el, 'pointermove', e => {
      const a = active.get(e.pointerId); if (!a || a.el !== el || a.kind !== 'pad') return;
      e.preventDefault(); e.stopPropagation();
      const dx = Math.round(e.clientX - a.x), dy = Math.round(e.clientY - a.y);
      a.x = e.clientX; a.y = e.clientY;
      if (Math.abs(dx) + Math.abs(dy) > 0) { a.moved = true; input.move(dx, dy); }
    });
    listen(el, 'lostpointercapture', e => release(e.pointerId));
    if (!isPad) {
      listen(el, 'keydown', e => { if ((e.key === ' ' || e.key === 'Enter') && !e.repeat) { e.preventDefault(); e.stopPropagation(); activity(); press(elementKeyId(e)); } });
      listen(el, 'keyup', e => {
        const id = elementKeyId(e);
        if ((e.key === ' ' || e.key === 'Enter') && active.has(id)) { e.preventDefault(); e.stopPropagation(); release(id); }
      });
      listen(el, 'blur', () => { for (const id of [...active.keys()]) if (typeof id === 'string' && id.startsWith(keyPrefix)) release(id); });
    }
  }
  listen(win, 'pointerup', e => release(e.pointerId, true));
  listen(win, 'pointercancel', e => release(e.pointerId));
  listen(win, 'blur', () => { uiKeys.clear(); releaseAll(); });
  listen(doc, 'visibilitychange', () => { if (doc.hidden) { uiKeys.clear(); releaseAll(); } });
  const activationKey = e => e.key === 'Enter' || e.key === ' ';
  const keyId = e => e.code || e.key;
  for (const control of [toggle, ...tabs]) {
    listen(control, 'keydown', e => {
      if (!activationKey(e)) return;
      if (!e.repeat) uiKeys.add(keyId(e));
      e.stopPropagation(); // preserve the button's native default action
      activity();
    });
    listen(control, 'keyup', e => {
      if (activationKey(e) && uiKeys.delete(keyId(e))) e.stopPropagation();
    });
  }
  // If focus moved away between UI keydown and keyup, forget the consumed
  // press. The input mux ignores an unmatched physical release.
  listen(win, 'keyup', e => { if (activationKey(e)) uiKeys.delete(keyId(e)); });
  toggle.addEventListener('click', () => {
    releaseAll(); panel.hidden = !panel.hidden;
    root.closest('main')?.classList.toggle('touch-playing', !panel.hidden);
    toggle.textContent = panel.hidden ? (en ? 'Show touch controls' : 'Показать управление') : (en ? 'Hide touch controls' : 'Скрыть управление');
    toggle.setAttribute('aria-expanded', String(!panel.hidden));
  });
  for (const tab of tabs) tab.addEventListener('click', () => {
    releaseAll();
    for (const group of groups) group.hidden = group.dataset.touchGroup !== tab.dataset.touchTab;
    for (const t of tabs) t.setAttribute('aria-pressed', String(t === tab));
  });
  root.hidden = false;
  root.closest('main')?.classList.add('touch-playing');
  return { releaseAll };
}
