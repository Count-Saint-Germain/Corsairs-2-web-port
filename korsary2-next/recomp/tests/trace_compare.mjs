#!/usr/bin/env node
// Compare per-instruction Unicorn and TRACE=1 native recompiler traces.
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {createRequire} from 'node:module';
import {Tester,NAMES,setupState,FPU_CW} from './difftest.mjs';
import {PythonRandom} from './python_random.mjs';
const require=createRequire(new URL('../translator/package.json',import.meta.url)),koffi=require('koffi');
const here=path.dirname(fileURLToPath(import.meta.url)),project=path.resolve(here,'../..');
const hex=n=>(n>>>0).toString(16).padStart(8,'0');
export function st0(u,uc){const top=(uc.reg_read_i32(u.X86_REG_FPSW)>>>11)&7,b=Buffer.from(uc.reg_read(u.X86_REG_FP0+top,16));const mant=b.readBigUInt64LE(),exp=b.readUInt16LE(8),e=exp&0x7fff;let v;if(e===0&&mant===0n)v=0;else if(e===0x7fff)v=(mant<<1n)&0xffffffffffffffffn?NaN:Infinity;else v=Number(mant)*2**(e-16383-63);return exp&0x8000?-v:v;}
export async function main(argv){let args=argv.slice(),pos=[],seed=1,sane=false,max=2_000_000,exe='',lib='';while(args.length){let a=args.shift();if(a==='--seed')seed=Number(args.shift());else if(a==='--sane')sane=true;else if(a==='--max')max=Number(args.shift());else if(a==='--exe')exe=args.shift();else if(a==='--lib')lib=args.shift();else if(a.startsWith('-'))throw new Error(`Unknown option ${a}`);else pos.push(a);}if(pos.length<1||pos.length>2||!Number.isInteger(max)||max<1)throw new Error('Usage: trace_compare.mjs <0xFUNC> [trial] [--sane] [--max N] [--exe PATH] [--lib PATH]');const entry=parseInt(pos[0],16),trial=Number(pos[1]??0);
  const config=JSON.parse(fs.readFileSync(path.join(project,'port.json'),'utf8'));const t=await Tester.create(exe||path.join(project,'game',config.exe),lib||path.join(project,'recomp/build/libporttrace.dylib'));
  try{const state=setupState(new PythonRandom(BigInt(seed)*1000003n+BigInt(entry)*31n+BigInt(trial)+(sane?7777n:0n)),sane),utrace=[],cache=new Map();
    const dis=a=>t.decoder.disasm(t.image.subarray(a-t.base,a-t.base+16),a,1)[0];
    const rep=a=>{if(!cache.has(a))cache.set(a,!!dis(a)?.mnemonic.startsWith('rep'));return cache.get(a);};
    const run=t.runUnicorn(entry,state,(uc,a)=>{if(utrace.length&&utrace.at(-1)[0]===a&&rep(a))return;if(utrace.length<max)utrace.push([a,t.regs().map(r=>uc.reg_read_i32(r)>>>0),st0(t.u,uc)]);});
    try{console.log(`unicorn: ${run.err??'returned'} (${utrace.length} instructions)`);t.resetC(state,run.demand);
      const start=t.lib.func('void dt_trace_start(uint32_t)'),len=t.lib.func('uint32_t dt_trace_len()'),buf=t.lib.func('void *dt_trace_buf()');start(max);const cregs=new Uint32Array(state.regs),rc=t.dtRun(entry,cregs,FPU_CW),n=len(),ptr=buf(),raw=Buffer.from(koffi.view(ptr,n*56)),ctrace=[];
      // Native TraceRec ABI: u32 address, eight u32 registers, aligned double, u32 top.
      for(let i=0;i<n;i++){const o=i*56;ctrace.push([raw.readUInt32LE(o),Array.from({length:8},(_,j)=>raw.readUInt32LE(o+4+j*4)),raw.readDoubleLE(o+40)]);}
      console.log(`recomp: rc ${rc} (${n} instructions) ${rc===1?t.dtTrap():''}`);
      for(let i=0;i<Math.min(utrace.length,ctrace.length);i++){const [ua,ur,us]=utrace[i],[ca,cr,cs]=ctrace[i],same=us===cs||(Number.isNaN(us)&&Number.isNaN(cs))||Math.abs(us-cs)<=Math.abs(us)*1e-15;if(ua!==ca||ur.some((x,j)=>x!==cr[j])||(i>0&&!same&&!rep(ua))){console.log(`\nfirst divergence at step ${i}:`);for(let j=Math.max(0,i-6);j<=i;j++){const a=utrace[j][0],ins=dis(a);console.log(`  step ${j}: ${hex(a)}  ${ins?`${ins.mnemonic} ${ins.op_str}`:'?'}`);}console.log(`  -> unicorn at ${hex(ua)}, recomp at ${hex(ca)}`);ur.forEach((v,j)=>{if(v!==cr[j])console.log(`     ${NAMES[j]}: unicorn ${hex(v)}  recomp ${hex(cr[j])}`);});if(!same)console.log(`     st0: unicorn ${us}  recomp ${cs}`);console.log(`  (registers are captured before each step, so the culprit is step ${i-1})`);return;}}
      console.log('no divergence in the common prefix'+(utrace.length===ctrace.length?'':`; lengths differ (${utrace.length} vs ${ctrace.length})`));
    }finally{run.dispose();}
  }finally{t.close();}}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url))main(process.argv.slice(2)).catch(e=>{console.error(e);process.exitCode=1;});
