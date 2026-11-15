/** Gap padding regressions for the x86-to-C translator. */
import test from 'node:test';
import assert from 'node:assert/strict';
import {createX86Decoder} from '../korsary2-next/recomp/translator/x86_decoder.mjs';
import {Program} from '../korsary2-next/recomp/translator/x86_program.mjs';

const BASE=0x1000, TARGET=BASE+0x10;
function syntheticProgram(decoder,tail,{pointer=false,exported=false}={}) {
 const text=Buffer.concat([Buffer.from([0xc3]),Buffer.alloc(15,0xcc),tail]);
 const data=pointer ? Buffer.alloc(4) : Buffer.alloc(0);if(pointer)data.writeUInt32LE(TARGET);
 const sections=[{name:'.text',virtualAddress:0,virtualSize:text.length}];
 if(pointer)sections.push({name:'.data',virtualAddress:text.length,virtualSize:data.length});
 const pe={imageBase:BASE,imageSize:text.length+data.length,entryPoint:0,sections,image:Buffer.concat([text,data]),exports:[],imports:[],relocations:[]};
 const p=new Program(pe,{functions:[{entry:BASE,name:'existing',ranges:[[BASE,BASE+1]]}],jumptables:[]},decoder);
 if(exported)p.seedEntry(TARGET,'EXPORT_test');p.addPointerEntries();return p;
}

test('unreferenced zero/int3 padding creates no candidates',async()=>{
 const d=await createX86Decoder();try{const p=syntheticProgram(d,Buffer.concat([Buffer.alloc(16),Buffer.alloc(16,0xcc),Buffer.alloc(16)]));assert.deepEqual([...p.entries],[BASE]);}finally{d.close()}
});
test('zero prologue followed by executable code is preserved',async()=>{
 const d=await createX86Decoder();try{const p=syntheticProgram(d,Buffer.concat([Buffer.from('000040c3','hex'),Buffer.alloc(12,0xcc)]));assert.ok(p.entries.has(TARGET));}finally{d.close()}
});
test('explicit data pointer into zero tail is preserved',async()=>{
 const d=await createX86Decoder();try{const p=syntheticProgram(d,Buffer.alloc(32),{pointer:true});assert.ok(p.entries.has(TARGET));}finally{d.close()}
});
test('export into zero tail is preserved',async()=>{
 const d=await createX86Decoder();try{const p=syntheticProgram(d,Buffer.alloc(32),{exported:true});assert.ok(p.entries.has(TARGET));assert.equal(p.functions.get(TARGET).name,'EXPORT_test');}finally{d.close()}
});
