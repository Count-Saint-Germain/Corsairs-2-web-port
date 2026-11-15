import assert from 'node:assert/strict';
import { createInputMux, mountTouchControls } from '../web/touch-controls.mjs';

const calls = [];
const mux = createInputMux({ key: (c, d) => calls.push(['key', c, d]),
  button: (c, d) => calls.push(['button', c, d]), move: (x, y) => calls.push(['move', x, y]) });
// A physical key and touch can overlap; either release order must leave the
// bridge down until the final source lets go.
mux.key(0, 26, 1); mux.key(1, 26, 1); mux.key(0, 26, 0); mux.key(1, 26, 0);
assert.deepEqual(calls.splice(0), [['key', 26, 1], ['key', 26, 0]]);
mux.button(1, 1, 1); mux.button(0, 1, 1); mux.button(1, 1, 0); mux.button(0, 1, 0);
assert.deepEqual(calls.splice(0), [['button', 1, 1], ['button', 1, 0]]);

class Target {
  constructor(dataset = {}, attrs = []) { this.dataset = dataset; this.attrs = new Set(attrs); this.listeners = {}; this.hidden = false;
    const values = new Set(); this.classList = { add: s => values.add(s), remove: s => values.delete(s),
      toggle: (s, on) => on ? values.add(s) : values.delete(s), contains: s => values.has(s) }; }
  addEventListener(n, fn) { (this.listeners[n] ||= []).push(fn); }
  emit(n, fields = {}) { const e = { button: 0, clientX: 0, clientY: 0, pointerId: 1, key: '', repeat: false,
    defaultPrevented: false, stopped: false, preventDefault() { this.defaultPrevented = true; },
    stopPropagation() { this.stopped = true; }, ...fields }; for (const fn of this.listeners[n] || []) fn(e); return e; }
  hasAttribute(n) { return this.attrs.has(n); }
  setPointerCapture() {}
  setAttribute(n, v) { this[n] = v; }
}
const win = new Target(), doc = new Target(), main = new Target();
const panel = new Target(), toggle = new Target();
const landTab = new Target({ touchTab: 'land' }), seaTab = new Target({ touchTab: 'sea' });
const land = new Target({ touchGroup: 'land' }), sea = new Target({ touchGroup: 'sea' });
const w1 = new Target({ touchKey: '26' }, ['data-touch-key']);
const w2 = new Target({ touchKey: '26' }, ['data-touch-key']);
const right = new Target({ touchMouse: '1' }, ['data-touch-mouse']);
const pad = new Target({}, ['data-touch-pad']);
const root = new Target(); root.hidden = true;
root.querySelector = s => s === '[data-touch-panel]' ? panel : toggle;
root.querySelectorAll = s => s === '[data-touch-tab]' ? [landTab, seaTab] :
  s === '[data-touch-group]' ? [land, sea] : s === '[data-ru][data-en]' ? [] : [w1, w2, right, pad];
root.closest = () => main;
let activity = 0, consumeNext = false;
const ui = mountTouchControls({ root, win, doc, consumePress: () => { const result = consumeNext; consumeNext = false; return result; }, activity: () => activity++, input: {
  key: (c, d) => mux.key(1, c, d), button: (c, d) => mux.button(1, c, d), move: (x, y) => mux.move(x, y),
} });
assert.equal(root.hidden, false);
assert.equal(main.classList.contains('touch-playing'), true);
// When the video consumes the pointer press, no game input is emitted and
// its eventual release is harmless. Ordinary input still works afterwards.
consumeNext = true;
w1.emit('pointerdown', { pointerId: 9 }); win.emit('pointerup', { pointerId: 9 });
assert.deepEqual(calls, []);
root.emit('pointerdown', { pointerId: 10 });
root.emit('pointermove', { pointerId: 10 }); // no active gameplay gesture
assert.equal(activity, 1);
// Multi-touch on the same key yields one down and one final up.
w1.emit('pointerdown', { pointerId: 11 }); w2.emit('pointerdown', { pointerId: 12 });
win.emit('pointerup', { pointerId: 11 }); assert.deepEqual(calls, [['key', 26, 1]]);
win.emit('pointerup', { pointerId: 12 }); assert.deepEqual(calls.splice(0), [['key', 26, 1], ['key', 26, 0]]);
// Touch key and mouse can coexist; cancel and backgrounding release each.
w1.emit('pointerdown', { pointerId: 21 }); right.emit('pointerdown', { pointerId: 22 });
win.emit('pointercancel', { pointerId: 21 }); doc.hidden = true; doc.emit('visibilitychange');
assert.deepEqual(calls.splice(0), [['key', 26, 1], ['button', 1, 1], ['key', 26, 0], ['button', 1, 0]]);
// Drag uses relative mouse deltas; tap produces one click; cancellation does not.
pad.emit('pointerdown', { pointerId: 31, clientX: 50, clientY: 50 });
root.emit('pointermove', { pointerId: 31 }); assert.equal(activity, 2);
pad.emit('pointermove', { pointerId: 31, clientX: 56, clientY: 47 }); win.emit('pointerup', { pointerId: 31 });
pad.emit('pointerdown', { pointerId: 32 }); win.emit('pointerup', { pointerId: 32 });
pad.emit('pointerdown', { pointerId: 33 }); win.emit('pointercancel', { pointerId: 33 });
assert.deepEqual(calls.splice(0), [['move', 6, -3], ['button', 0, 1], ['button', 0, 0]]);
// Layout switches, hiding, lost capture, window blur and keyboard activation release held inputs.
w1.emit('pointerdown', { pointerId: 41 }); seaTab.emit('click');
assert.equal(land.hidden, true); assert.equal(sea.hidden, false); assert.equal(seaTab['aria-pressed'], 'true');
right.emit('pointerdown', { pointerId: 42 }); right.emit('lostpointercapture', { pointerId: 42 });
w1.emit('keydown', { key: 'Enter' }); win.emit('blur');
w1.emit('pointerdown', { pointerId: 43 }); toggle.emit('click');
assert.equal(panel.hidden, true); assert.equal(main.classList.contains('touch-playing'), false);
assert.deepEqual(calls.splice(0), [['key', 26, 1], ['key', 26, 0], ['button', 1, 1], ['button', 1, 0],
  ['key', 26, 1], ['key', 26, 0], ['key', 26, 1], ['key', 26, 0]]);
ui.releaseAll(); assert.deepEqual(calls, []);
// Enter/Space activate panel UI without reaching the game; native click must
// remain enabled. Other keys are not intercepted.
for (const [control, key, code] of [[landTab, 'Enter', 'Enter'], [toggle, ' ', 'Space']]) {
  const down = control.emit('keydown', { key, code });
  const up = control.emit('keyup', { key, code });
  assert.equal(down.stopped, true); assert.equal(up.stopped, true);
  assert.equal(down.defaultPrevented, false); assert.equal(up.defaultPrevented, false);
}
assert.equal(landTab.emit('keydown', { key: 'a', code: 'KeyA' }).stopped, false);
assert.equal(landTab.emit('keyup', { key: 'a', code: 'KeyA' }).stopped, false);
assert.deepEqual(calls, []);
// If a game key was held before focus moved onto a panel button, its keyup
// must still reach the physical source and release it, including repeats.
mux.key(0, 44, 1);
toggle.emit('keydown', { key: ' ', code: 'Space', repeat: true });
const heldUp = toggle.emit('keyup', { key: ' ', code: 'Space' });
assert.equal(heldUp.stopped, false);
if (!heldUp.stopped) mux.key(0, 44, 0);
assert.deepEqual(calls.splice(0), [['key', 44, 1], ['key', 44, 0]]);
// The same physical-to-panel focus change must not swallow releases on an
// actual gameplay touch button. Test both activation keys and repeat.
for (const [key, code, usage] of [['Enter', 'Enter', 40], [' ', 'Space', 44]]) {
  mux.key(0, usage, 1);
  right.emit('keydown', { key, code, repeat: true });
  const up = right.emit('keyup', { key, code });
  assert.equal(up.stopped, false); assert.equal(up.defaultPrevented, false);
  if (!up.stopped) mux.key(0, usage, 0);
  assert.deepEqual(calls.splice(0), [['key', usage, 1], ['key', usage, 0]]);
}
// A touch-button press belongs to its actual activation key, not any keyup.
right.emit('keydown', { key: 'Enter', code: 'Enter' });
assert.equal(right.emit('keyup', { key: ' ', code: 'Space' }).stopped, false);
assert.deepEqual(calls, [['button', 1, 1]]);
assert.equal(right.emit('keyup', { key: 'Enter', code: 'Enter' }).stopped, true);
assert.deepEqual(calls.splice(0), [['button', 1, 1], ['button', 1, 0]]);
// A UI press whose release goes to another element is forgotten at window;
// the unmatched keyup cannot release a game key it never pressed.
landTab.emit('keydown', { key: 'Enter', code: 'Enter' });
win.emit('keyup', { key: 'Enter', code: 'Enter' }); mux.key(0, 40, 0);
assert.deepEqual(calls, []);
assert.equal(landTab.emit('keyup', { key: 'Enter', code: 'Enter' }).stopped, false);
console.log('touch controls: input aggregation, multitouch, drag, click and release paths PASS');
