import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import crypto from 'node:crypto';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {PythonRandom} from './python_random.mjs';
import {Tester,setupState,pickFunctions,nanWord,SENTINEL} from './difftest.mjs';
import {createX86Decoder} from '../translator/x86_decoder.mjs';
import {st0} from './trace_compare.mjs';
const here=path.dirname(fileURLToPath(import.meta.url)),project=path.resolve(here,'../..'),exe=path.join(project,'game/ENGINE.exe');

test('Python-compatible random inputs reproduce old trials',()=>{
  const r=new PythonRandom(1234567890123);assert.equal(r.bytes(21).toString('hex'),'ca6f91d20c3898bda5c6b3337b767a9f0dc8cda2ed');assert.equal(r.random(),0.4340654355058259);assert.equal(r.range(65536),22200);assert.equal(r.bits(23),1259086);
  for(const [sane,hash,stack] of [[false,'2072d21291a1f6d40bd136707bf669bc9ef20127a75b2a077b5f748f3b67bd02','efbeaddee858002010000000c4d70020d853002080b9002001000000ff0000001f000000'],[true,'f129702d4917c5df7c3dc29142deaa0d2d8025bbf37af3f2952d636dac13c512','efbeadde904700209893002070b10020f4320020405e0020030000003cdf0020742c0020']]){const s=setupState(new PythonRandom(1000003+0x401055*31),sane);assert.equal(crypto.createHash('sha256').update(s.scratch).digest('hex'),hash);assert.equal(s.stack.toString('hex'),stack);}
});
test('NaN matching accepts NaN pairs and rejects ordinary numbers',()=>{const a=Buffer.from('007fc07f','hex'),b=Buffer.from('00ffc07f','hex');assert.equal(nanWord(a,b,2),true);assert.equal(nanWord(a,Buffer.alloc(4),2),false);});
test('function selection rejects indirect jumps, calls, and MMX',async()=>{const d=await createX86Decoder({registerAccess:true});try{const image=Buffer.from('9090c3e800000000c3ffe090c30f6fc090c3','hex'),f=[{entry:0x1000,ranges:[[0x1000,0x1003]]},{entry:0x1003,ranges:[[0x1003,0x1009]]},{entry:0x1009,ranges:[[0x1009,0x100d]]},{entry:0x100d,ranges:[[0x100d,0x1012]]}];assert.deepEqual(pickFunctions(d,image,0x1000,f,new Set()).map(x=>x.entry),[0x1000]);}finally{d.close();}});

test('synthetic x86 runs end-to-end through Unicorn, native library, and trace', {skip:!fs.existsSync(exe)}, async()=>{
 const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-difftest-')),source=path.join(dir,'fixture.c'),lib=path.join(dir,'fixture.dylib'),manifest=path.join(dir,'functions.json');
 try{
 const code=[
 '#include <stdint.h>','#include <stdlib.h>','#include <string.h>','#include <sys/mman.h>',
 'typedef struct {uint32_t addr,regs[8]; double st0; uint32_t top;} TraceRec;',
 'static unsigned char *mem; static TraceRec *trace; static uint32_t cap,n;',
 'int dt_init(const char *p){(void)p;mem=mmap(0,0x100000000ULL,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0); if(mem==MAP_FAILED)return -1; unsigned char code[]={0xb8,0x2a,0,0,0,0xc3}; memcpy(mem+0x401000,code,sizeof(code));return 0;}',
 'void *dt_mem(void){return mem;}',
 'const char *dt_trap_msg(void){return "trap";}',
 'void dt_trace_start(uint32_t c){free(trace);trace=calloc(c,sizeof(*trace));cap=c;n=0;}',
 'uint32_t dt_trace_len(void){return n;}',
 'void *dt_trace_buf(void){return trace;}',
 'int dt_run(uint32_t entry,uint32_t *regs,uint16_t cw){(void)cw;if(entry!=0x401000)return 2;if(n<cap){trace[n].addr=entry;memcpy(trace[n].regs,regs,32);if(getenv("K2_TRACE_MISMATCH"))trace[n].regs[0]^=1;n++;}regs[0]=getenv("K2_DIFF_MISMATCH")?43:42;if(n<cap){trace[n].addr=entry+5;memcpy(trace[n++].regs,regs,32);}regs[4]+=4;return 0;}'
 ].join('\n');
 fs.writeFileSync(source,code);
 let cc=spawnSync('clang',[process.platform==='darwin'?'-dynamiclib':'-shared','-fPIC','-O2',source,'-o',lib],{encoding:'utf8'});assert.equal(cc.status,0,cc.stderr);
 fs.writeFileSync(manifest,JSON.stringify({functions:[{entry:0x401000,name:'fixture',ranges:[[0x401000,0x401006]]}],jumptables:[]}));
 let run=spawnSync(process.execPath,[path.join(here,'difftest.mjs'),exe,manifest,lib,'--only','0x401000','--trials','2'],{encoding:'utf8'});assert.equal(run.status,0,run.stderr);assert.match(run.stdout,/pass=1 nan=0 fp_range=0 fpu_flags=0 fail=0 skip=0/);
 run=spawnSync(process.execPath,[path.join(here,'trace_compare.mjs'),'0x401000','--exe',exe,'--lib',lib,'--max','10'],{encoding:'utf8'});assert.equal(run.status,0,run.stderr);assert.match(run.stdout,/no divergence in the common prefix/);assert.match(run.stdout,/2 instructions/);
 run=spawnSync(process.execPath,[path.join(here,'trace_compare.mjs'),'0x401000','--exe',exe,'--lib',lib,'--max','10'],{encoding:'utf8',env:{...process.env,K2_TRACE_MISMATCH:'1'}});assert.equal(run.status,0,run.stderr);assert.match(run.stdout,/first divergence at step 0/);
 run=spawnSync(process.execPath,[path.join(here,'difftest.mjs'),exe,manifest,lib,'--only','0x401000','--trials','1'],{encoding:'utf8',env:{...process.env,K2_DIFF_MISMATCH:'1'}});assert.equal(run.status,0,run.stderr);assert.match(run.stdout,/FAIL 0x00401000 fixture: trial 0: eax unicorn=0000002a recomp=0000002b/);
 const work=path.resolve(project,'../korsary2-work/recomp/tests');
 run=spawnSync(process.execPath,[path.join(work,'difftest.mjs'),exe,manifest,lib,'--only','0x401000','--trials','1'],{encoding:'utf8'});assert.equal(run.status,0,run.stderr);assert.match(run.stdout,/pass=1/);
 run=spawnSync(process.execPath,[path.join(work,'trace_compare.mjs'),'0x401000','--exe',exe,'--lib',lib,'--max','10'],{encoding:'utf8'});assert.equal(run.status,0,run.stderr);assert.match(run.stdout,/no divergence in the common prefix/);
 const t=await Tester.create(exe,lib);try{const state=setupState(new PythonRandom(1));for(const [leaf,want] of [[0,[1,0x756e6547,0x6c65746e,0x49656e69]],[1,[0x683,0,0,0x8111]],[0x80000000,[0x80000000,0,0,0]],[17,[0,0,0,0]]]){t.image.set([0x0f,0xa2,0xc3],0x1000);state.regs[0]=leaf;const r=t.runUnicorn(0x401000,state);try{assert.equal(r.err,null);assert.deepEqual([t.u.X86_REG_EAX,t.u.X86_REG_EBX,t.u.X86_REG_ECX,t.u.X86_REG_EDX].map(x=>r.uc.reg_read_i32(x)>>>0),want);assert.equal(r.uc.reg_read_i32(t.u.X86_REG_EIP)>>>0,SENTINEL);}finally{r.dispose();}}
 t.image.set([0xd9,0xe8,0x90,0xc3],0x1000);const fp=[];const runFp=t.runUnicorn(0x401000,state,(uc)=>fp.push(st0(t.u,uc)));try{assert.equal(runFp.err,null);assert.equal(fp[1],1);}finally{runFp.dispose();}
 }finally{t.close();}
 }finally{fs.rmSync(dir,{recursive:true,force:true});}
});
