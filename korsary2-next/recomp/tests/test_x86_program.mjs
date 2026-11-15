/** Pointer discovery and fragmented CFG regressions for the experimental Node Program. */
import test from 'node:test';import assert from 'node:assert/strict';
import fs from 'node:fs';import path from 'node:path';import os from 'node:os';import {spawnSync} from 'node:child_process';import {fileURLToPath} from 'node:url';
import {createX86Decoder} from '../translator/x86_decoder.mjs';
import {Program} from '../translator/x86_program.mjs';
import {FunctionTranslator} from '../translator/x86_translate.mjs';

function makeProgram(decoder,base,{pointerReloc=true,mode='pointer'}={}) {
 const preferred=0x1000,size=mode==='pointer'?0x100:0x80,image=Buffer.alloc(size,mode==='pointer'?0x90:0);
 const relocations=[];let functions;
 if(mode==='pointer') {
  image[0]=0xc3;Buffer.from('eb0e','hex').copy(image,0x10);image[0x20]=0x68;image.writeUInt32LE(preferred+0x60,0x21);image[0x25]=0x90;
  Buffer.from('e855000000c3','hex').copy(image,0x26);image[0x18]=0x68;image.writeUInt32LE(preferred+0xa0,0x19);
  for(const off of [0x60,0x80,0xa0])Buffer.from('8bffc3','hex').copy(image,off);
  relocations.push({rva:0x19,type:3});if(pointerReloc)relocations.push({rva:0x21,type:3});
  functions=[{entry:preferred,name:'root',ranges:[[preferred,preferred+1]]}];
 }else{
  Buffer.from('eb1ec3','hex').copy(image,0);Buffer.from('e83b000000c3','hex').copy(image,0x20);image[0x40]=0xc3;
  Buffer.from('8d54240cc3','hex').copy(image,0x60);
  functions=[{entry:preferred,name:'fragmented',ranges:[[preferred,preferred+2],[preferred+0x40,preferred+0x41]]}];
 }
 const pe={imageBase:preferred,imageSize:size,entryPoint:0,sections:[{name:'.text',virtualAddress:0,virtualSize:size}],image,exports:[],imports:[],relocations};
 return new Program(pe,{functions,jumptables:[]},decoder,{base});
}

test('finds reachable callbacks and direct calls but not skipped embedded constants',async()=>{
 const d=await createX86Decoder();try {for(const base of [0x1000,0x21000]){
  const p=makeProgram(d,base);p.addPointerEntries();assert.ok(p.entries.has(base+0x10));assert.ok(p.entries.has(base+0x60));assert.ok(p.entries.has(base+0x80));assert.equal(p.entries.has(base+0xa0),false);
 }}finally{d.close()}
});

test('nonrelocated immediates are not discovered as callbacks',async()=>{
 const d=await createX86Decoder();try{
  const p=makeProgram(d,0x1000,{pointerReloc:false});p.addPointerEntries();assert.equal(p.entries.has(0x1060),false);assert.ok(p.entries.has(0x1080));
 }finally{d.close()}
});

test('finds direct call in reachable Ghidra range gap with nonstandard callee',async()=>{
 const d=await createX86Decoder();try{for(const base of [0x1000,0x21000]){
  const p=makeProgram(d,base,{mode:'fragment'});assert.equal(p.plausibleEntry(base+0x60),false);p.addPointerEntries();assert.ok(p.entries.has(base+0x60));
  const body=new FunctionTranslator(p,p.functions.get(base)).translate();assert.deepEqual(body.unsupported,[]);assert.ok(body.source.includes(`f_${(base+0x60).toString(16).padStart(8,'0')}(c)`));
  assert.ok(body.source.includes(`PUSH32(c, 0x${(base+0x25).toString(16).padStart(8,'0')}u)`));
  const callee=new FunctionTranslator(p,p.functions.get(base+0x60)).translate();assert.deepEqual(callee.unsupported,[]);assert.ok(callee.source.includes('c->esp + 0xcu'));assert.ok(callee.source.includes('c->esp += 4; return;'));
 }}finally{d.close()}
});

test('relocated AND register callback is found; memory destinations and nonrelocated constants are not',async()=>{
 const d=await createX86Decoder();try{
  for(const base of [0x1000,0x21000]){
   const p=makeProgram(d,base);p.image[0x20]=0x25;p.image.writeUInt32LE(0x1060,0x21);p.image[0x25]=0xc3;
   p.image[0x18]=0x25;p.image.writeUInt32LE(0x10a0,0x19);p.addPointerEntries();
   assert.ok(p.entries.has(base+0x60));assert.equal(p.entries.has(base+0xa0),false);
   const fn={entry:base+0x20,name:'mask',ranges:[[base+0x20,base+0x26]]};
   const generated=new FunctionTranslator(p,fn).translate();assert.deepEqual(generated.unsupported,[]);
   const address=(base+0x20).toString(16).padStart(8,'0'),target=(base+0x60).toString(16);
   const source='#include <stdint.h>\ntypedef struct { uint32_t eax, esp; } CPU;\n#define PREEMPT_POLL(c) ((void)0)\nstatic uint32_t logic32(CPU *c,uint32_t v) { (void)c; return v; }\n'+generated.source+`\nint main(void) { CPU zero={.eax=0},one={.eax=0xffffffffu}; f_${address}(&zero); f_${address}(&one); return zero.eax!=0 || one.eax!=0x${target}u; }\n`;
   const tmp=fs.mkdtempSync(path.join(os.tmpdir(),'k2-mask-'));try {
    const src=path.join(tmp,'mask.c'),bin=path.join(tmp,'mask');fs.writeFileSync(src,source);
    const cc=spawnSync('cc',['-std=c99','-Wall','-Werror',src,'-o',bin],{encoding:'utf8'});assert.equal(cc.status,0,cc.stderr);
    const run=spawnSync(bin,[],{encoding:'utf8'});assert.equal(run.status,0,run.stderr);
   }finally{fs.rmSync(tmp,{recursive:true,force:true});}
  }
  for(const mode of ['no_relocation','memory_destination']){
   const p=makeProgram(d,0x1000);
   if(mode==='no_relocation'){p.image[0x20]=0x25;p.image.writeUInt32LE(0x1060,0x21);p.image[0x25]=0xc3;p.relocations.delete(0x1021);}
   else{Buffer.from('81242460100000c3','hex').copy(p.image,0x20);p.relocations=new Set([0x1023]);}
   p.addPointerEntries();assert.equal(p.entries.has(0x1060),false,mode);
  }
 }finally{d.close()}
});

// Golden counts independently produced by the current Python Program implementation.
const projectRoot=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../../..');
for(const [image,functions,base,entries,pointers,gaps] of [
 ['ENGINE.exe','functions.json',0x400000,2399,574,310],
 ['MODULES/DX8RENDER.dll','functions.MODULES_DX8RENDER.json',0x690000,1243,615,155],
]) {
 const exe=path.join(projectRoot,'korsary2-work/game',image),info=path.join(projectRoot,'korsary2-next/recomp/data',functions);
 test(`real pointer-discovery parity: ${image}`,{skip:!fs.existsSync(exe)||!fs.existsSync(info),timeout:30000},async()=>{
  const d=await createX86Decoder();try {
   const p=Program.fromFiles(exe,info,d,{base});p.addPointerEntries();
   assert.deepEqual([p.entries.size,p.pointerEntries,p.gapEntries],[entries,pointers,gaps]);
  }finally{d.close()}
 });
}
