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
const doc = new Target();
const canvas = new Target();
canvas.getBoundingClientRect = () => ({left: 0, top: 0, width: 960, height: 540});
canvas.width = 1920;
canvas.height = 1080;
const fallback = new Target();
const timers = new Map();
let nextTimer = 0;
let fakeNow = 0;
const setFakeTimeout = fn => { const id = ++nextTimer; timers.set(id, fn); return id; };
const clearFakeTimeout = id => timers.delete(id);
const events = [];
const module = {
  _input_key_hid: (...args) => events.push(['key', ...args]),
  _input_mouse_button: (...args) => events.push(['button', ...args]),
  _input_mouse_move: () => {},
};
const stage = {classList: {contains: () => true}};
const hookInput = runInNewContext(`(${source.slice(start, end)})`, {
  window: win, document: doc, $: id => id === 'esc-fallback' ? fallback : id === 'stage' ? stage : canvas, params: new URLSearchParams(), HID: { KeyF: 9, KeyW: 26, ShiftLeft: 225, Escape: 41, Backquote: 53, F10: 67 }, noteGameInput: () => {}, setTimeout: setFakeTimeout, clearTimeout: clearFakeTimeout, Date: {now: () => fakeNow},
});
const controls = await hookInput(module, false);
let lockRequests = 0;
canvas.requestPointerLock = () => { lockRequests++; };
canvas.emit('mousedown', { button: 0 }); win.emit('mouseup', { button: 0 });
assert.equal(lockRequests, 0, 'a windowed click must not capture the pointer or reserve Escape');
events.length = 0;
doc.fullscreenElement = canvas;
canvas.emit('mousedown', { button: 0 }); win.emit('mouseup', { button: 0 });
assert.equal(lockRequests, 1, 'fullscreen can still capture the pointer');
doc.fullscreenElement = null;
events.length = 0;
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
// Esc may release pointer lock without a window blur or a matching mouseup.
// Release the guest button once; the next click must still work.
doc.pointerLockElement = canvas; doc.emit('pointerlockchange');
canvas.emit('mousedown', { button: 0 });
doc.pointerLockElement = null; doc.emit('pointerlockchange');
win.emit('mouseup', { button: 0 });
canvas.emit('mousedown', { button: 0 }); win.emit('mouseup', { button: 0 });
assert.deepEqual(events.slice(-4), [
  ['button', 0, 1], ['button', 0, 0], ['button', 0, 1], ['button', 0, 0],
]);
// A capture requested in fullscreen may complete after fullscreen exits.
let lateReleases = 0;
doc.exitPointerLock = () => { lateReleases++; doc.pointerLockElement = null; };
doc.pointerLockElement = canvas; doc.emit('pointerlockchange');
assert.equal(lateReleases, 1, 'late capture must be released in a window');
doc.emit('pointerlockchange');
win.emit('keydown', { code: 'KeyW' }); canvas.emit('mousedown', { button: 2 });
doc.hidden = true; doc.emit('visibilitychange');
doc.emit('visibilitychange'); win.emit('mouseup', { button: 2 });
assert.deepEqual(events.slice(-4), [
  ['key', 26, 1], ['button', 1, 1], ['key', 26, 0], ['button', 1, 0],
]);
doc.hidden = false;
doc.emit('visibilitychange');
for (const [type, fullscreenElement] of [['fullscreenchange', canvas], ['webkitfullscreenchange', null]]) {
  win.emit('keydown', { code: 'KeyW' });
  canvas.emit('mousedown', { button: 0 });
  doc.fullscreenElement = fullscreenElement;
  doc.emit(type);
  win.emit('keyup', { code: 'KeyW' });
  win.emit('mouseup', { button: 0 });
  assert.deepEqual(events.slice(-4), [
    ['key', 26, 1], ['button', 0, 1], ['key', 26, 0], ['button', 0, 0],
  ], `fullscreen transition (${type}) must release even without blur or pointer unlock`);
}
// The game still receives Escape, but this input bridge must not prevent the
// browser's default exit behavior when fullscreen keyboard lock was denied.
let prevented = false;
win.emit('keydown', { code: 'Escape', preventDefault() { prevented = true; } });
win.emit('keyup', { code: 'Escape', preventDefault() { prevented = true; } });
assert.equal(prevented, false);
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
const beforeBrowserFullscreen = events.length;
win.emit('keydown', { code: 'KeyF', ctrlKey: true, metaKey: true, preventDefault() { prevented = true; } });
win.emit('keyup', { code: 'KeyF' });
assert.equal(prevented, false, 'Control+Command+F remains available to the browser');
assert.equal(events.length, beforeBrowserFullscreen);
win.emit('keydown', { code: 'KeyF' }); win.emit('keyup', { code: 'KeyF' });
assert.deepEqual(events.slice(-2), [['key', 9, 1], ['key', 9, 0]], 'plain F reaches the game');
// Backquote keeps its original binding in a window. Fullscreen uses it as Esc,
// even if Keyboard Lock has hidden the fallback button.
win.emit('keydown', { code: 'Backquote' }); win.emit('keyup', { code: 'Backquote' });
assert.deepEqual(events.slice(-2), [['key', 53, 1], ['key', 53, 0]]);
doc.fullscreenElement = canvas;
win.emit('keydown', { code: 'F10' }); win.emit('keyup', { code: 'F10' });
assert.deepEqual(events.slice(-2), [['key', 67, 1], ['key', 67, 0]]);
const beforeModifiedQuote = events.length;
win.emit('keydown', { code: 'Backquote', metaKey: true, preventDefault() { prevented = true; } });
win.emit('keyup', { code: 'Backquote', metaKey: true });
assert.equal(prevented, false, 'Command+Backquote remains available to macOS');
assert.equal(events.length, beforeModifiedQuote);
win.emit('keydown', { code: 'Backquote', key: 'ё' }); win.emit('keydown', { code: 'Escape' });
win.emit('keyup', { code: 'Backquote' });
assert.deepEqual(events.slice(-1), [['key', 41, 1]], 'overlapping physical Escape must stay held');
win.emit('keyup', { code: 'Escape' });
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
fallback.emit('click');
assert.deepEqual(events.slice(-1), [['key', 41, 1]]);
for (const fn of timers.values()) fn(); timers.clear();
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
win.emit('keydown', { code: 'Backquote' }); doc.fullscreenElement = null;
win.emit('keyup', { code: 'Backquote' });
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]], 'release survives fullscreen change');
doc.pointerLockElement = canvas;
win.emit('keydown', { code: 'Backquote' }); win.emit('blur');
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]], 'blur releases fallback');
doc.pointerLockElement = null;
module._input_mouse_position = (...args) => events.push(['position', ...args]);
module._input_mouse_move = (...args) => events.push(['move', ...args]);
events.length = 0;
canvas.emit('mouseenter', {clientX: 120, clientY: 135});
canvas.emit('mousemove', {clientX: 300, clientY: 140, movementX: 180, movementY: 5, buttons: 0});
canvas.emit('mousedown', {clientX: 480, clientY: 270, button: 0});
win.emit('mouseup', {button: 4});
canvas.emit('mousemove', {clientX: 480, clientY: 270, movementX: 0, movementY: 0, buttons: 0});
canvas.emit('mousedown', {clientX: 480, clientY: 270, button: 4});
assert.deepEqual(events, [
  ['position', 0, 0.25], ['position', 0.25, 140 / 540], ['move', 180, 5],
  ['position', 0.5, 0.5], ['button', 0, 1],
  ['button', 0, 0], ['position', 0.5, 0.5],
], 'absolute menu position matches the letterboxed picture and precedes the click');
canvas.width /= 2; canvas.height /= 2;
canvas.emit('mouseenter', {clientX: 300, clientY: 140});
canvas.width = 1440; canvas.height = 1080;
canvas.emit('mouseenter', {clientX: 300, clientY: 140});
assert.deepEqual(events.slice(-2), [
  ['position', 0.25, 140 / 540], ['position', 300 / 960, 140 / 540],
], 'pixel ratio cancels and fill mode covers the entire CSS canvas');
doc.pointerLockElement = canvas;
canvas.emit('mousemove', {clientX: 480, clientY: 270, movementX: 9, movementY: 2, buttons: 0});
assert.deepEqual(events.slice(-2), [['position', -1, -1], ['move', 9, 2]]);
doc.pointerLockElement = null;

// A modern build can capture the pointer in a window only while the guest is
// in the 3D scene. Menus release it and retain absolute cursor positioning.
let menuActive = 0, sceneLocks = 0;
module._port_menu_mouse_active = () => menuActive;
doc.fullscreenElement = null; doc.hidden = false;
canvas.requestPointerLock = () => { sceneLocks++; doc.pointerLockElement = canvas; doc.emit('pointerlockchange'); };
doc.exitPointerLock = () => { doc.pointerLockElement = null; doc.emit('pointerlockchange'); };
canvas.emit('mousedown', {button: 0, clientX: 480, clientY: 270}); win.emit('mouseup', {button: 0});
assert.equal(sceneLocks, 1, 'a scene click captures the pointer');
assert.equal(doc.pointerLockElement, canvas);
menuActive = 1; controls.syncPointerLock();
assert.equal(doc.pointerLockElement, null, 'opening a menu releases windowed capture');
assert.equal(timers.size, 0, 'a menu-triggered unlock must not synthesize Escape');
canvas.emit('mousedown', {button: 0, clientX: 480, clientY: 270}); win.emit('mouseup', {button: 0});
assert.equal(sceneLocks, 1, 'menu clicks leave the pointer free');

// When the browser consumes Escape to unlock, the game receives one Escape.
menuActive = 0; fakeNow = 1000; timers.clear(); events.length = 0;
canvas.emit('mousedown', {button: 0, clientX: 480, clientY: 270}); win.emit('mouseup', {button: 0});
doc.exitPointerLock();
let pendingTimers = [...timers.values()]; timers.clear(); for (const fn of pendingTimers) fn();
assert.deepEqual(events.slice(-1), [['key', 41, 1]], 'consumed Escape opens the game menu');
pendingTimers = [...timers.values()]; timers.clear(); for (const fn of pendingTimers) fn();
assert.deepEqual(events.slice(-2), [['key', 41, 1], ['key', 41, 0]]);
// When the browser does deliver the key, unlocking must not generate a
// second Escape (which would immediately close the newly opened menu).
fakeNow = 2000; events.length = 0;
canvas.emit('mousedown', {button: 0, clientX: 480, clientY: 270}); win.emit('mouseup', {button: 0});
win.emit('keydown', {code: 'Escape'}); doc.exitPointerLock(); win.emit('keyup', {code: 'Escape'});
pendingTimers = [...timers.values()]; timers.clear(); for (const fn of pendingTimers) fn();
assert.deepEqual(events.filter(([type]) => type === 'key'), [['key', 41, 1], ['key', 41, 0]]);

const netWin = new Target(), netDoc = new Target(), netCanvas = new Target(), netFallback = new Target();
netDoc.fullscreenElement = netCanvas;
const netContext = { window: netWin, document: netDoc, $: id => id === 'esc-fallback' ? netFallback : netCanvas,
  NET_KEYS: {Escape: 9}, netKeyBits: 0, netKeyPressed: 0, noteGameInput: () => {}, setTimeout: setFakeTimeout, clearTimeout: clearFakeTimeout };
const netHook = runInNewContext(`(${source.slice(start, end)})`, netContext);
await netHook(module, true);
netWin.emit('keydown', {code: 'Backquote'});
assert.equal(netContext.netKeyBits, 1 << 9); assert.equal(netContext.netKeyPressed, 1 << 9);
netWin.emit('keydown', {code: 'Escape'}); netWin.emit('keyup', {code: 'Backquote'});
assert.equal(netContext.netKeyBits, 1 << 9, 'the other netplay source keeps Start held');
netWin.emit('keyup', {code: 'Escape'}); assert.equal(netContext.netKeyBits, 0);
netFallback.emit('click'); assert.equal(netContext.netKeyBits, 1 << 9);
for (const fn of timers.values()) fn(); timers.clear();
assert.equal(netContext.netKeyBits, 0);
for (const [target, type] of [[netWin, 'blur'], [netDoc, 'visibilitychange'], [netDoc, 'fullscreenchange']]) {
  netWin.emit('keydown', { code: 'Backquote' });
  netDoc.hidden = true;
  target.emit(type);
  assert.equal(netContext.netKeyBits, 0, `release held netplay input on ${type}`);
  assert.equal(netContext.netKeyPressed, 0, `discard unpolled netplay presses on ${type}`);
}
console.log('browser input blur: PASS');
