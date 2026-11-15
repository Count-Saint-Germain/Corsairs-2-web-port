/* Real browser events over isolated HTML with the actual touch/video modules and
 * actual launcher handlers. No game, sound output, saved data or user profile. */
import { createServer } from 'node:http';
import { readFileSync } from 'node:fs';
import { createRequire } from 'node:module';
import { fileURLToPath } from 'node:url';
import { dirname, join } from 'node:path';
import assert from 'node:assert/strict';

const here = dirname(fileURLToPath(import.meta.url));
const web = join(here, '../web');
const playwright = join(here, '../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(playwright, 'browsers');
const { chromium } = createRequire(join(playwright, 'package.json'))('playwright');
const html = readFileSync(join(web, 'index.html'), 'utf8');
const source = readFileSync(join(web, 'port.js'), 'utf8');
const hookStart = source.indexOf('async function hookInput(');
const hookEnd = source.indexOf('\n// Gamepads (', hookStart);
const audioStart = source.indexOf('async function startAudio(');
const audioEnd = source.indexOf('\n// ------------------------------------------------------------------ run', audioStart);
assert(hookStart >= 0 && hookEnd > hookStart && audioStart >= 0 && audioEnd > audioStart);
const style = html.match(/<style>([\s\S]*?)<\/style>/)[0];
const panel = html.match(/<section id="touch-controls"[\s\S]*?<\/section>/)[0];
const fixture = `<!doctype html><meta name="viewport" content="width=device-width,initial-scale=1">${style}
<main><div id="stage"><canvas id="canvas" tabindex="0"></canvas></div>${panel}</main>
<script type="module">
import {createVideoPlayer} from '/video-player.mjs';
const params=new URLSearchParams('?touch=1'), langState={lang:'ru'};
const HID={Enter:40,Space:44}, NET_KEYS={}; let netKeyBits=0,netKeyPressed=0,audioDuck=null;
const $=id=>document.getElementById(id), noteGameInput=()=>{};
window.bridge=[]; window.resumes=0; window.done=[];
window.AudioContext=class { constructor(){ this.audioWorklet={addModule:async()=>{}}; this.destination={}; }
  resume(){ resumes++; return Promise.resolve(); } createGain(){return {gain:{value:1},connect(){}};} };
window.AudioWorkletNode=class { constructor(){this.port={postMessage(){}};} connect(){} };
const memory={buffer:new ArrayBuffer(256)};
const M={wasmMemory:memory,_port_audio_ring:()=>0,
  _input_key_hid:(...a)=>bridge.push(['key',...a]),_input_mouse_button:(...a)=>bridge.push(['button',...a]),
  _input_mouse_move:(...a)=>bridge.push(['move',...a]),_port_video_name_buf:()=>0,
  _port_video_poll:(addr,cap)=>{if(!cap)return 0;new Uint8Array(memory.buffer).set(new TextEncoder().encode('trailer'));return 7},
  _port_video_done:code=>done.push(code)};
${source.slice(hookStart, hookEnd)}
${source.slice(audioStart, audioEnd)}
const vid=document.createElement('video'); Object.defineProperty(vid,'src',{configurable:true,get(){return this._src||''},set(v){this._src=v}});
vid.play=()=>Promise.resolve();vid.pause=()=>{};vid.load=()=>{};
let player=null; let controls=await hookInput(M,false,()=>{if(!player?.active)return false;player.abort();return true;});
player=createVideoPlayer({mount:$('stage'),video:vid,onActive:on=>{if(on)controls?.releaseAll();}});
window.videoPlayer=player;window.startVideo=()=>player.poll(M);await startAudio(M);window.ready=true;
</script>`;

const server = createServer((req, res) => {
  const path = new URL(req.url, 'http://localhost').pathname;
  if (path === '/touch-controls.mjs' || path === '/video-player.mjs') {
    res.writeHead(200, { 'Content-Type': 'text/javascript; charset=utf-8' });
    res.end(readFileSync(join(web, path.slice(1))));
  } else { res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' }); res.end(fixture); }
});
await new Promise(resolve => server.listen(0, '127.0.0.1', resolve));
const browser = await chromium.launch({ headless: true });
try {
  const context = await browser.newContext({ viewport: { width: 393, height: 852 }, hasTouch: true, isMobile: true });
  const page = await context.newPage();
  await page.goto(`http://127.0.0.1:${server.address().port}/`);
  await page.waitForFunction(() => window.ready);
  const cdp = await context.newCDPSession(page);
  const position = async (selector, id) => {
    const rect = await page.locator(selector).boundingBox();
    assert(rect, `control not visible: ${selector}`);
    return { x: Math.round(rect.x + rect.width / 2), y: Math.round(rect.y + rect.height / 2), id };
  };
  const down = point => cdp.send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: [point] });
  const up = () => cdp.send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
  const button = '[data-touch-group="land"] [data-touch-key="44"]';
  await down(await position(button, 1)); await up();
  assert.deepEqual(await page.evaluate(() => ({ bridge, resumes })), { bridge: [['key', 44, 1], ['key', 44, 0]], resumes: 1 }, 'the actual touch gesture reaches audio resume');
  // A real keyboard gesture activating the touch button must reach audio too,
  // even though the button stops bubbling to prevent double game input.
  await page.evaluate(() => { bridge.length = 0; });
  await page.locator(button).focus(); await page.keyboard.press('Enter');
  assert.deepEqual(await page.evaluate(() => ({ bridge, resumes })), { bridge: [['key', 44, 1], ['key', 44, 0]], resumes: 2 }, 'keyboard activation reaches audio resume once');
  await page.evaluate(() => { bridge.length = 0; startVideo(); });
  assert.equal(await page.evaluate(() => videoPlayer.active), 'trailer');
  await down(await position(button, 2)); await up();
  assert.deepEqual(await page.evaluate(() => ({ bridge, done, active: videoPlayer.active, resumes })),
    { bridge: [], done: [1], active: null, resumes: 3 }, 'touch skips the video without firing the underlying game key');
  // A key already held when a video appears must be released before the overlay.
  await page.evaluate(() => { bridge.length = 0; });
  await down(await position(button, 3));
  await page.evaluate(() => startVideo());
  assert.deepEqual(await page.evaluate(() => bridge), [['key', 44, 1], ['key', 44, 0]], 'opening a video releases held touch input');
  await up();
  assert.deepEqual(await page.evaluate(() => bridge), [['key', 44, 1], ['key', 44, 0]], 'eventual pointerup does not release twice');
  // Direct taps on the actual video retain compatibility-mouse skip behaviour.
  await down(await position('.video-screen', 4)); await up();
  assert.equal(await page.evaluate(() => videoPlayer.active), null);
  await context.close();
  console.log('touch/video/audio browser events: PASS (synthetic bridge; audio audibility not tested)');
} finally { await browser.close(); await new Promise(resolve => server.close(resolve)); }
