/** CFG and relocation regression tests for the experimental Node recompiler. */
import test from 'node:test';
import assert from 'node:assert/strict';
import {createX86Decoder} from '../translator/x86_decoder.mjs';
import {decodeFunction, isLocked, shiftInstructionOperands, toFinal} from '../translator/x86_cfg.mjs';

function makeProgram(decoder, base, image, entries, next, delta=0) {
 return {decoder,base,image,delta,relocations:new Set(),ghidraEntries:new Set(entries),jumpTables:new Map(),
   nextEntry:()=>next,code:(a,b)=>image.subarray(a-base,b-base),
   toFinal:v=>toFinal(v,base-delta,image.length,delta)};
}

test('backward branches and separate Ghidra entries are decoded without changing entry',async()=>{
 const d=await createX86Decoder();try {
  const bytes=Buffer.concat([Buffer.from('b807000000c3','hex'),Buffer.alloc(10),Buffer.from('85c974ecb82a000000c3','hex')]);
  const p=makeProgram(d,0x1000,bytes,[0x1010],0x101a);
  const f={entry:0x1010,ranges:[[0x1000,0x1006],[0x1010,0x101a]]};
  assert.deepEqual(decodeFunction(p,f).map(x=>Number(x.address)),[0x1000,0x1005,0x1010,0x1012,0x1014,0x1019]);
  p.ghidraEntries.add(0x1000);
  assert.deepEqual(decodeFunction(p,f).map(x=>Number(x.address)),[0x1010,0x1012,0x1014,0x1019]);
 } finally {d.close()}
});

test('indirect jump table is recovered only while targets stay inside function',async()=>{
 const d=await createX86Decoder();try {
  const bytes=Buffer.alloc(0x40,0x90);
  Buffer.from('ff248520100000','hex').copy(bytes,0); bytes[0x10]=0xc3;bytes[0x14]=0xc3;
  bytes.writeUInt32LE(0x1010,0x20);bytes.writeUInt32LE(0x1014,0x24);bytes.writeUInt32LE(0x2000,0x28);
  const p=makeProgram(d,0x1000,bytes,[0x1000],0x1020);
  assert.deepEqual(decodeFunction(p,{entry:0x1000,ranges:[[0x1000,0x1020]]}).map(x=>Number(x.address)),[0x1000,0x1010,0x1014]);
  assert.deepEqual(p.jumpTables.get(0x1000),[0x1010,0x1014]);
 } finally {d.close()}
});

test('relocation rewrites only matching encoded operands',async()=>{
 const d=await createX86Decoder();try {
  const delta=0x20000, address=0x21000;
  const ins=d.disasm(Buffer.from('b8301000008b0530100000','hex'),address);
  const reloc=new Set([address+1,address+7]);
  shiftInstructionOperands(ins[0],reloc,delta,d.constants);shiftInstructionOperands(ins[1],reloc,delta,d.constants);
  assert.equal(ins[0].operands[1].imm,0x21030n);assert.equal(ins[1].operands[1].mem.disp,0x21030n);
  assert.equal(toFinal(0x1030,0x1000,0x100,delta),0x21030);
  assert.equal(toFinal(0xff,0x1000,0x100,delta),0xff);
  const untouched=d.disasm(Buffer.from('b830100000','hex'),address)[0];
  shiftInstructionOperands(untouched,new Set([address+2]),delta,d.constants);
  assert.equal(untouched.operands[1].imm,0x1030n);
 } finally {d.close()}
});

test('locked prefix and memory xchg need guest synchronization',async()=>{
 const d=await createX86Decoder();try {
  const ins=d.disasm(Buffer.from('f00108870187c1','hex'),0x1000);
  assert.deepEqual(ins.map(i=>isLocked(i,d.constants)),[true,true,false]);
 } finally {d.close()}
});
