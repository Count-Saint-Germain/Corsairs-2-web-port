/** End-to-end test for explicitly experimental, incomplete Node x86 translation. */
import test from 'node:test';
import assert from 'node:assert/strict';
import {spawnSync} from 'node:child_process';
import fs from 'node:fs';import os from 'node:os';import path from 'node:path';
import {createX86Decoder} from '../translator/x86_decoder.mjs';
import {FunctionTranslator} from '../translator/x86_translate.mjs';

function program(decoder,bytes) {
 const image=Buffer.from(bytes,'hex'),base=0x1000,entries=new Set([0x1010]);
 return {decoder,base,image,delta:0,entries,ghidraEntries:new Set(entries),jumpTables:new Map(),relocations:new Set(),trace:false,
   nextEntry:()=>0x101a,code:(a,b)=>image.subarray(a-base,b-base),toFinal:v=>Number(v)};
}

test('backward branch emits correct entry and compiled C executes both paths',async()=>{
 const d=await createX86Decoder();try {
  const p=program(d,'b807000000c30000000000000000000085c974ecb82a000000c3');
  const fn={entry:0x1010,name:'test',ranges:[[0x1000,0x1006],[0x1010,0x101a]]};
  const result=new FunctionTranslator(p,fn).translate();
  assert.deepEqual(result.unsupported,[]);assert.ok(result.source.includes('goto L_00001010;'));
  const harness=`#include <stdint.h>\ntypedef struct { uint32_t eax, ecx, esp, zf; } CPU;\n#define PREEMPT_POLL(c) ((void)0)\nstatic uint32_t logic32(CPU *c,uint32_t v) { c->zf=v==0; return v; }\n`+result.source+`\nint main(void) { CPU a={.ecx=0},b={.ecx=1}; f_00001010(&a); f_00001010(&b); return !(a.eax==7 && b.eax==42 && a.esp==4 && b.esp==4); }\n`;
  const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-x86-partial-'));try {
   const src=path.join(root,'entry.c'),bin=path.join(root,'entry');fs.writeFileSync(src,harness);
   const cc=spawnSync('cc',['-std=c99','-Wall','-Werror',src,'-o',bin],{encoding:'utf8'});assert.equal(cc.status,0,cc.stderr);
   const run=spawnSync(bin,[],{encoding:'utf8'});assert.equal(run.status,0,run.stderr);
  }finally{fs.rmSync(root,{recursive:true,force:true})}
 }finally{d.close()}
});

test('unsupported opcodes are reported and emit a guest trap',async()=>{
 const d=await createX86Decoder();try {
  const p=program(d,'00000000000000000000000000000000dd30c3');p.entries=new Set([0x1010]);p.ghidraEntries=new Set([0x1010]);p.nextEntry=()=>0x1013;
  const result=new FunctionTranslator(p,{entry:0x1010,name:'unsupported',ranges:[[0x1010,0x1013]]}).translate();
  assert.equal(result.unsupported.length,1);assert.match(result.source,/guest_trap\(c, 0x00001010u, "unsupported: fnsave dword ptr \[eax\]"\)/);
 }finally{d.close()}
});

test('integer, shift, multiply and REP string operations emit supported C',async()=>{
 const d=await createX86Decoder();try {
  const p=program(d,'00000000000000000000000000000000f3a540496bc103d1e099c3');p.nextEntry=()=>0x101b;
  const result=new FunctionTranslator(p,{entry:0x1010,name:'common',ranges:[[0x1010,0x101b]]}).translate();
  assert.deepEqual(result.unsupported,[]);
  assert.match(result.source,/memmove\(HP\(c->edi\), HP\(c->esi\)/);
  assert.match(result.source,/inc32\(c, c->eax\)/);
  assert.match(result.source,/dec32\(c, c->ecx\)/);
  assert.match(result.source,/int64_t r_ = \(int64_t\)/);
  assert.match(result.source,/shl32\(c, c->eax, 1\)/);
  assert.match(result.source,/c->edx = \(uint32_t\)\(\(int32_t\)c->eax >> 31\)/);
 }finally{d.close()}
});

test('SSE, MMX and x87 samples emit the same runtime helpers as the Python translator',async()=>{
 const d=await createX86Decoder();try {
  const p=program(d,'000000000000000000000000000000000f10d80f59d80f6f000f62c1d9e8dd5c2408c3');p.nextEntry=()=>0x1024;
  const result=new FunctionTranslator(p,{entry:0x1010,name:'vector',ranges:[[0x1010,0x1024]]}).translate();
  assert.deepEqual(result.unsupported,[]);
  assert.match(result.source,/c->xmm\[3\] = c->xmm\[0\];/);
  assert.match(result.source,/c->xmm\[3\]\.f\[0\] = c->xmm\[3\]\.f\[0\] \* s0_/);
  assert.match(result.source,/memset\(&c->mm\[0\], 0, 8\)/);
  assert.match(result.source,/v_unpack\(a_, b_, 8, 4, 0\)/);
  assert.match(result.source,/FPUSH\(c, 1\.0\)/);
  assert.match(result.source,/WF64\(\(uint32_t\)\(c->esp \+ 0x8u\), ST\(0\)\); FPOP\(c\)/);
 }finally{d.close()}
});
