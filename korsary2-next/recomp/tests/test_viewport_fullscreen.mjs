import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import vm from 'node:vm';

const source=readFileSync(new URL('../web/port.js',import.meta.url),'utf8');
const between=(start,end)=>{const a=source.indexOf(start),b=source.indexOf(end,a);assert(a>=0&&b>a,`${start} / ${end}`);return source.slice(a,b);};
class Target {
  constructor(){this.handlers=new Map();this.attrs={};this.textContent='';this.hidden=false;const set=new Set();this.classList={add:x=>set.add(x),remove:x=>set.delete(x),contains:x=>set.has(x),toggle:(x,on)=>{if(on===undefined)on=!set.has(x);on?set.add(x):set.delete(x);return on;}};}
  addEventListener(type, fn){const list=this.handlers.get(type)||[];list.push(fn);this.handlers.set(type,list);}
  async emit(type,properties={}){const e={type,code:'',repeat:false,altKey:false,defaultPrevented:false,stopped:false,preventDefault(){this.defaultPrevented=true;},stopImmediatePropagation(){this.stopped=true;},...properties};for(const fn of this.handlers.get(type)||[])await fn(e);return e;}
  setAttribute(name,value){this.attrs[name]=value;}
  focus(){this.focused=true;}
}
function fixture({fullscreen=true,keyboard='none'}={}){
  const stage=new Target(),canvas=new Target(),main=new Target(),fs=new Target(),aspect=new Target(),escape=new Target(),icon=new Target(),tip=new Target(),touch=new Target();touch.hidden=true;canvas.closest=()=>main;
  canvas.getBoundingClientRect=()=>({width:1600,height:900});
  const win=new Target(),doc=new Target(),store=new Map();doc.fullscreenElement=null;
  if(fullscreen){stage.requestFullscreen=async()=>{doc.fullscreenElement=stage;};doc.exitFullscreen=async()=>{doc.fullscreenElement=null;};}
  let resizeCalls=0, unlocks=0, lockCalls=[];
  const nav={};if(keyboard!=='none')nav.keyboard={lock:async(keys)=>{lockCalls.push([...keys]);if(keyboard==='deny')throw new Error('denied');},unlock:()=>{unlocks++;}};
  const elements={stage,canvas,fs,aspect,'esc-fallback':escape,'fs-icon':icon,'fs-notice':tip,'touch-controls':touch};
  const ctx={window:win,document:doc,navigator:nav,PORT:{id:'korsary2'},$:id=>elements[id],uiText:(ru)=>ru,
    safeLocalStorage:()=>({getItem:k=>store.get(k)??null,setItem:(k,v)=>store.set(k,v)}),resizeGameCanvas:()=>{resizeCalls++;},
    setTimeout:()=>1,clearTimeout:()=>{}};
  const script=between('function setupFullscreen() {','\n// once the game starts:');vm.runInNewContext(script+'\nsetupFullscreen();',ctx);
  return {stage,canvas,main,fs,aspect,escape,icon,tip,win,doc,nav,store,get resizeCalls(){return resizeCalls;},get unlocks(){return unlocks;},lockCalls};
}

test('viewport stretches the 4:3 backing buffer; the 4:3 choice restores letterboxing',()=>{
  const f=fixture();f.win.devicePixelRatio=1;const c={window:f.win,$:id=>({canvas:f.canvas,stage:f.stage}[id])};
  const script=between('function sizeCanvas() {','\n// Per-slot netplay userdata');vm.runInNewContext(script+'\nsizeCanvas();',c);
  assert.equal(f.canvas.width,1200);assert.equal(f.canvas.height,900);
  f.aspect.onclick();assert.equal(f.stage.classList.contains('aspect-preserve'),true);assert.equal(f.aspect.attrs['aria-pressed'],'true');assert.equal(f.store.get('korsary2-display-aspect'),'4:3');assert.equal(f.resizeCalls,1);
  vm.runInNewContext(script+'\nsizeCanvas();',c);assert.equal(f.canvas.width,1600);assert.equal(f.canvas.height,900);
  f.aspect.onclick();assert.equal(f.aspect.attrs['aria-pressed'],'false');assert.equal(f.store.get('korsary2-display-aspect'),'fill');
  f.main.classList.add('touch-playing');vm.runInNewContext(script+'\nsizeCanvas();',c);assert.equal(f.canvas.width,1600,'touch layout uses the actual 4:3 stage bounds');
});
test('unavailable fullscreen leaves browser shortcuts untouched and 4:3 control works',async()=>{
  const f=fixture({fullscreen:false});assert.equal(f.fs.classList.contains('hidden'),true);
  const esc=await f.win.emit('keydown',{code:'Escape'});assert.equal(esc.defaultPrevented,false);
  const alt=await f.win.emit('keydown',{code:'Enter',altKey:true});assert.equal(alt.defaultPrevented,false);
  f.aspect.onclick();assert.equal(f.aspect.attrs['aria-pressed'],'true');
});
test('denied keyboard lock does not intercept Escape and explains the fallback',async()=>{
  const f=fixture({keyboard:'deny'});await f.fs.onclick();await f.doc.emit('fullscreenchange');
  const esc=await f.win.emit('keydown',{code:'Escape'});assert.equal(esc.defaultPrevented,false);assert.match(f.tip.textContent,/Esc/);
  assert.equal(f.escape.classList.contains('hidden'),false);assert.equal(f.win.escapeFallbackActive(),true);
  assert.deepEqual(f.lockCalls,[['Escape']]);
});
test('granted keyboard lock forwards Escape and releases on exit',async()=>{
  const f=fixture({keyboard:'allow'});await f.fs.onclick();await f.doc.emit('fullscreenchange');
  const esc=await f.win.emit('keydown',{code:'Escape'});assert.equal(esc.defaultPrevented,true);assert.equal(esc.stopped,false,'the game must receive Escape');
  assert.equal(f.escape.classList.contains('hidden'),true);assert.equal(f.win.escapeFallbackActive(),false);
  assert.match(f.fs.title,/Esc/);f.doc.fullscreenElement=null;await f.doc.emit('fullscreenchange');assert.equal(f.unlocks,1);
  const after=await f.win.emit('keydown',{code:'Escape'});assert.equal(after.defaultPrevented,false);
});
test('double Escape exits only with a granted lock; the first press reaches the game',async()=>{
  const f=fixture({keyboard:'allow'});await f.fs.onclick();await f.doc.emit('fullscreenchange');
  const first=await f.win.emit('keydown',{code:'Escape',timeStamp:100});
  const release=await f.win.emit('keyup',{code:'Escape',timeStamp:140});
  assert.equal(first.defaultPrevented,true);assert.equal(first.stopped,false);
  assert.equal(release.stopped,false);assert.ok(f.doc.fullscreenElement);
  const second=await f.win.emit('keydown',{code:'Escape',timeStamp:250});
  assert.equal(second.defaultPrevented,true);assert.equal(second.stopped,true);
  assert.equal(f.doc.fullscreenElement,null);
  const secondRelease=await f.win.emit('keyup',{code:'Escape',timeStamp:300});
  assert.equal(secondRelease.stopped,false,'keyup must not be trapped after fullscreen exit');
});
test('held, repeated, slow or unfocused Escape does not accidentally exit',async()=>{
  const f=fixture({keyboard:'allow'});await f.fs.onclick();await f.doc.emit('fullscreenchange');
  await f.win.emit('keydown',{code:'Escape',timeStamp:100});
  const repeat=await f.win.emit('keydown',{code:'Escape',timeStamp:200,repeat:true});
  assert.equal(repeat.stopped,false);assert.ok(f.doc.fullscreenElement);
  await f.win.emit('keyup',{code:'Escape',timeStamp:220});
  const slow=await f.win.emit('keydown',{code:'Escape',timeStamp:900});
  assert.equal(slow.stopped,false);assert.ok(f.doc.fullscreenElement);
  await f.win.emit('keyup',{code:'Escape',timeStamp:920});
  await f.win.emit('blur');
  const afterBlur=await f.win.emit('keydown',{code:'Escape',timeStamp:950});
  assert.equal(afterBlur.stopped,false);assert.ok(f.doc.fullscreenElement);
});
test('double Escape never interferes when Keyboard Lock is unavailable',async()=>{
  const f=fixture({keyboard:'deny'});await f.fs.onclick();await f.doc.emit('fullscreenchange');
  const first=await f.win.emit('keydown',{code:'Escape',timeStamp:100});
  await f.win.emit('keyup',{code:'Escape',timeStamp:150});
  const second=await f.win.emit('keydown',{code:'Escape',timeStamp:250});
  assert.equal(first.defaultPrevented,false);assert.equal(second.defaultPrevented,false);
  assert.equal(second.stopped,false);assert.ok(f.doc.fullscreenElement);
});
test('leaving fullscreen releases any remaining pointer lock',async()=>{
  const f=fixture({keyboard:'allow'});let releases=0;
  f.doc.exitPointerLock=()=>{releases++;f.doc.pointerLockElement=null;};
  await f.fs.onclick();await f.doc.emit('fullscreenchange');
  f.doc.pointerLockElement=f.canvas;f.doc.fullscreenElement=null;
  await f.doc.emit('fullscreenchange');
  assert.equal(releases,1);assert.equal(f.doc.pointerLockElement,null);
});
test('pointer lock offers an Escape alternative in the regular viewport',async()=>{
  const f=fixture();assert.equal(f.escape.classList.contains('hidden'),true);
  f.doc.pointerLockElement=f.canvas;await f.doc.emit('pointerlockchange');
  assert.equal(f.win.escapeFallbackActive(),true);assert.equal(f.escape.classList.contains('hidden'),false);
  f.doc.pointerLockElement=null;await f.doc.emit('pointerlockchange');
  assert.equal(f.win.escapeFallbackActive(),false);assert.equal(f.escape.classList.contains('hidden'),true);
});
test('relative pointer movement tracks the stretched image without losing small movements',()=>{
  const f=fixture();const a=source.indexOf('  function createMouseMotionMapper('),b=source.indexOf('\n  const mapMouseMotion',a);assert(a>=0&&b>a);
  const mapper=vm.runInNewContext(source.slice(a,b)+'\ncreateMouseMotionMapper',{})(f.canvas,f.stage);
  let x=0;for(let i=0;i<8;i++)x+=mapper(1,0)[0];assert.equal(x,6);
  let y=0;for(let i=0;i<8;i++)y+=mapper(0,0.25)[1];assert.equal(y,2,'subpixel vertical motion must reach the integer input bridge');
  y=0;for(let i=0;i<4;i++)y+=mapper(0,-0.5)[1];assert.equal(y,-2,'negative fractional motion is preserved too');
  f.stage.classList.add('aspect-preserve');assert.equal(mapper(4,2)[0],4);
  f.stage.classList.remove('aspect-preserve');f.main.classList.add('touch-playing');assert.equal(mapper(4,2)[0],4);
});
