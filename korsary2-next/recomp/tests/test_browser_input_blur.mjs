import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { runInNewContext } from 'node:vm';

// Exercise the launcher's actual event handlers with a minimal fake DOM.
const source = readFileSync(new URL('../web/port.js', import.meta.url), 'utf8');
const start = source.indexOf('async function hookInput(');
const end = source.indexOf('\n// Gamepads (', start);
assert(start >= 0 && end > start, 'cannot find browser input handler');
class Target {
  handlers = new Map();
  addEventListener(type, handler) { this.handlers.set(type, handler); }
  emit(type, props = {}) {
    this.handlers.get(type)?.({ preventDefault() {}, repeat: false, metaKey: false, ...props });
  }
}
const win = new Target();
const canvas = new Target();
const fallback = new Target();
const timers = new Map();
let nextTimer = 0;
const setFakeTimeout = fn => { const id = ++nextTimer; timers.set(id, fn); return id; };
const clearFakeTimeout = id => timers.delete(id);
const events = [];
const module = {
  _input_key_hid: (...args) => events.push(['key', ...args]),
  _input_mouse_button: (...args) => events.push(['button', ...args]),
  _input_mouse_move: () => {},
};
const hookInput = runInNewContext(`(${source.slice(start, end)})`, {
  window: win, document: {}, $: id => id === 'esc-fallback' ? fallback : canvas, params: new URLSearchParams(), HID: { KeyW: 26, ShiftLeft: 225, Escape: 41, F10: 67 }, noteGameInput: () => {}, setTimeout: setFakeTimeout, clearTimeout: clearFakeTimeout,
});
await hookInput(module, false);
win.emit('keydown', { code: 'KeyW' });
win.emit('keydown', { code: 'ShiftLeft' });
win.emit('keyup', { code: 'ShiftLeft' });
canvas.emit('mousedown', { button: 2 });
win.emit('blur');
win.emit('blur');
assert.deepEqual(events, [
  ['key', 26, 1], ['key', 225, 1], ['key', 225, 0],
  ['button', 1, 1], ['key', 26, 0], ['button', 1, 0],
]);
// After refocusing the same inputs can be pressed and released normally.
win.emit('keydown', { code: 'KeyW' });
win.emit('keyup', { code: 'KeyW' });
canvas.emit('mousedown', { button: 0 });
win.emit('mouseup', { button: 0 });
win.emit('blur');
assert.deepEqual(events.slice(6), [
  ['key', 26, 1], ['key', 26, 0], ['button', 0, 1], ['button', 0, 0],
]);
// The game still receives Escape, but this input bridge must not prevent the
// browser's default exit behavior when fullscreen keyboard lock was denied.
let prevented = false;
win.emit('keydown', { code: 'Escape', preventDefault() { prevented = true; } });
win.emit('keyup', { code: 'Escape', preventDefault() { prevented = true; } });
assert.equal(prevented, false);
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
// F10 stays the game's normal key unless the browser reserves Escape.
win.emit('keydown', { code: 'F10' }); win.emit('keyup', { code: 'F10' });
assert.deepEqual(events.slice(-2), [['key', 67, 1], ['key', 67, 0]]);
win.escapeFallbackActive = () => true;
win.emit('keydown', { code: 'F10' }); win.emit('keydown', { code: 'Escape' });
win.emit('keyup', { code: 'F10' });
assert.deepEqual(events.slice(-1), [['key', 41, 1]], 'overlapping physical Escape must stay held');
win.emit('keyup', { code: 'Escape' });
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
fallback.emit('click');
assert.deepEqual(events.slice(-1), [['key', 41, 1]]);
for (const fn of timers.values()) fn(); timers.clear();
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
win.emit('keydown', { code: 'F10' }); win.escapeFallbackActive = () => false;
win.emit('keyup', { code: 'F10' });
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]], 'release survives fullscreen change');
win.escapeFallbackActive = () => true;
win.emit('keydown', { code: 'F10' }); win.emit('blur');
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]], 'blur releases fallback');
const netWin = new Target(), netCanvas = new Target(), netFallback = new Target();
netWin.escapeFallbackActive = () => true;
const netContext = { window: netWin, document: {}, $: id => id === 'esc-fallback' ? netFallback : netCanvas,
  NET_KEYS: {Escape: 9}, netKeyBits: 0, netKeyPressed: 0, noteGameInput: () => {}, setTimeout: setFakeTimeout, clearTimeout: clearFakeTimeout };
const netHook = runInNewContext(`(${source.slice(start, end)})`, netContext);
await netHook(module, true);
netWin.emit('keydown', {code: 'F10'});
assert.equal(netContext.netKeyBits, 1 << 9); assert.equal(netContext.netKeyPressed, 1 << 9);
netWin.emit('keydown', {code: 'Escape'}); netWin.emit('keyup', {code: 'F10'});
assert.equal(netContext.netKeyBits, 1 << 9, 'the other netplay source keeps Start held');
netWin.emit('keyup', {code: 'Escape'}); assert.equal(netContext.netKeyBits, 0);
netFallback.emit('click'); assert.equal(netContext.netKeyBits, 1 << 9);
for (const fn of timers.values()) fn(); timers.clear();
assert.equal(netContext.netKeyBits, 0);
netWin.emit('keydown', {code: 'F10'}); netWin.emit('blur'); assert.equal(netContext.netKeyBits, 0);
console.log('browser input blur: PASS');
