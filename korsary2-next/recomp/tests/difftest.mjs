#!/usr/bin/env node
// Differential tester: Unicorn x86 versus the recompiled native library.
// Unicorn.js cannot use its timeout argument (the WASM build has no QEMU
// threads); use an instruction limit and run this command under an external
// timeout if a strict wall-clock limit is needed.
import fs from 'node:fs';
import path from 'node:path';
import {createRequire} from 'node:module';
import {fileURLToPath} from 'node:url';
import {parsePeImage} from '../translator/pe_image.mjs';
import {createX86Decoder} from '../translator/x86_decoder.mjs';
import {PythonRandom} from './python_random.mjs';
const require = createRequire(new URL('../translator/package.json', import.meta.url));
const createUnicorn = require('@alexaltea/unicorn-js/x86');
const koffi = require('koffi');
export const NAMES=['eax','ecx','edx','ebx','esp','ebp','esi','edi'];
export const PAGE=0x1000, SENTINEL=0xdeadbeef, SCRATCH=0x20000000, SCRATCH_SIZE=0x10000, STACK_LO=0x2f0000, STACK_HI=0x300000, FPU_CW=0x027f, TIB=0x10000, GDT=0x1000;
const hex=(n,w=8)=>n.toString(16).padStart(w,'0');
function gdtEntry(base,limit,access,flags) { const n=BigInt(limit&0xffff)|(BigInt(base&0xffffff)<<16n)|(BigInt(access)<<40n)|(BigInt((limit>>>16)&15)<<48n)|(BigInt(flags)<<52n)|(BigInt(base>>>24)<<56n);const b=Buffer.alloc(8);b.writeBigUInt64LE(n);return b; }
export const GDT_PAGE=Buffer.concat([Buffer.alloc(16),gdtEntry(0,0xfffff,0x93,0xc),gdtEntry(TIB,PAGE-1,0x93,4),Buffer.alloc(PAGE-32)]);
export function setupState(rng,sane=false) {
  let scratch;
  if (sane) { scratch=Buffer.alloc(SCRATCH_SIZE); for(let i=0;i<SCRATCH_SIZE;i+=4) scratch.writeUInt32LE(((rng.bits(1)*0x80000000)|((127+rng.range(-10,11))<<23)|rng.bits(23))>>>0,i); }
  else scratch=rng.bytes(SCRATCH_SIZE);
  const ptr=()=>((SCRATCH+rng.range(0x100,SCRATCH_SIZE-0x1000))&~3)>>>0;
  const small=()=>{const values=[0,1,2,3,4,7,8,16,31,100,255,0x7fffffff,rng.range(1<<16)];return values[rng.below(values.length)];};
  const args=Array.from({length:8},()=>rng.random()<0.5?ptr():small());
  const esp=STACK_HI-0x800,stack=Buffer.alloc(36);stack.writeUInt32LE(SENTINEL,0);args.forEach((a,i)=>stack.writeUInt32LE(a,4+i*4));
  return {scratch,stack,regs:[small(),ptr(),ptr(),small(),esp,ptr(),ptr(),ptr()]};
}
export function nanWord(a,b,i) {
  for(const [size,em,mm] of [[4,0x7f800000n,0x007fffffn],[8,0x7ff0000000000000n,0xfffffffffffffn]])
    for(let j=Math.max(0,i-size+1);j<=i;j++) if(j+size<=a.length) {
      const x=size===4?BigInt(a.readUInt32LE(j)):a.readBigUInt64LE(j),y=size===4?BigInt(b.readUInt32LE(j)):b.readBigUInt64LE(j);
      if((x&em)===em&&(x&mm)!==0n&&(y&em)===em&&(y&mm)!==0n)return true;
    }
  return false;
}
export function pickFunctions(decoder,image,base,funcs,jumptables,allowCalls=false) {
  const out=[];for(const f of funcs){let ok=true,n=0;for(const [a,b] of f.ranges){for(const ins of decoder.disasm(image.subarray(a-base,b-base),a)){
    n++;const m=ins.mnemonic,op=ins.operands[0];if((m==='call'&&!allowCalls)||['int','in ','out','hlt','cpuid','rdtsc'].some(p=>m.startsWith(p)))ok=false;
    if(m==='jmp'&&op&&op.type!==decoder.constants.IMM&&!jumptables.has(Number(ins.address)))ok=false;
    if(m==='jmp'&&!allowCalls&&op?.type===decoder.constants.IMM&&!f.ranges.some(([x,y])=>BigInt(x)<=op.imm&&op.imm<BigInt(y)))ok=false;
    if([...ins.regs_read,...ins.regs_write].some(r=>decoder.regName(r).startsWith('mm')))ok=false;
  }if(!ok)break;}if(ok&&n>=3)out.push(f);}return out;
}
// Unicorn.js registers instruction hooks with a void return type. CPUID needs
// a boolean return to suppress QEMU's default implementation, so register it
// directly with the exact callback ABI instead.
function addCpuid(u,uc) {
  const cb=u.addFunction(()=>{const leaf=uc.reg_read_i32(u.X86_REG_EAX)>>>0;const vals=leaf===0?[1,0x756e6547,0x6c65746e,0x49656e69]:leaf===1?[0x683,0,0,0x8111]:leaf===0x80000000?[0x80000000,0,0,0]:[0,0,0,0];[u.X86_REG_EAX,u.X86_REG_EBX,u.X86_REG_ECX,u.X86_REG_EDX].forEach((r,i)=>uc.reg_write_i32(r,vals[i]));return 1;},'iii');
  const hp=u._malloc(4),vp=u._malloc(8);u.setValue(vp,u.X86_INS_CPUID,'i32');
  const rc=u.ccall('uc_hook_add','number',['pointer','pointer','number','pointer','pointer','number','number','pointer'],[u.getValue(uc.handle_ptr,'*'),hp,u.HOOK_INSN,cb,0,1n,0n,vp]);u._free(vp);
  if(rc!==u.ERR_OK){u.removeFunction(cb);u._free(hp);throw new Error(`Cannot install CPUID hook: ${u.strerror(rc)}`);}u._free(hp);return cb;
}
export class Tester {
  static async create(exe,lib) { const t=new Tester();t.u=await createUnicorn();t.decoder=await createX86Decoder({registerAccess:true});t.lib=koffi.load(lib);
    t.dtInit=t.lib.func('int dt_init(const char *)');t.dtMem=t.lib.func('void *dt_mem()');t.dtRun=t.lib.func('int dt_run(uint32_t, _Inout_ uint32_t *, uint16_t)');t.dtTrap=t.lib.func('const char *dt_trap_msg()');
    if(t.dtInit(exe)!==0)throw new Error('dt_init failed');t.mem=t.dtMem();const pe=parsePeImage(fs.readFileSync(exe));t.base=pe.imageBase;t.size=(pe.imageSize+PAGE-1)&~(PAGE-1);t.image=t.cread(t.base,t.size);t.tib=t.cread(TIB,PAGE);
    t.rdtsc=[];for(let k=t.image.indexOf(Buffer.from([15,49]),0x1000);k>=0&&k<0x385000;k=t.image.indexOf(Buffer.from([15,49]),k+1))t.rdtsc.push(t.base+k);return t; }
  regs(){const u=this.u;return [u.X86_REG_EAX,u.X86_REG_ECX,u.X86_REG_EDX,u.X86_REG_EBX,u.X86_REG_ESP,u.X86_REG_EBP,u.X86_REG_ESI,u.X86_REG_EDI];}
  cwrite(addr,data){Buffer.from(koffi.view(this.mem+BigInt(addr),data.length)).set(data);}
  cread(addr,n){return Buffer.from(Buffer.from(koffi.view(this.mem+BigInt(addr),n)));}
  close(){this.decoder.close();}
  runUnicorn(entry,{scratch,stack,regs},codeHook=null) {
    const u=this.u,uc=new u.Unicorn(u.ARCH_X86,u.MODE_32),demand=[],nondet=[],hooks=[];
    // Reused WASM allocations are not necessarily zero-filled by Unicorn.js.
    // Native Unicorn exposes zeroed pages; explicitly restore that guarantee.
    const map=(a,n,p=u.PROT_ALL)=>{uc.mem_map(a,n,p);uc.mem_write(a,Buffer.alloc(n));};
    if(codeHook)hooks.push(uc.hook_add(u.HOOK_CODE,(c,a,s)=>codeHook(c,Number(a),s)));
    map(this.base,this.size);uc.mem_write(this.base,this.image);map(SCRATCH,SCRATCH_SIZE);uc.mem_write(SCRATCH,scratch);map(STACK_LO,STACK_HI-STACK_LO);uc.mem_write(regs[4],stack);
    map(GDT,PAGE);uc.mem_write(GDT,GDT_PAGE);const gdtr=Buffer.alloc(24);gdtr.writeBigUInt64LE(BigInt(GDT),8);gdtr.writeUInt32LE(PAGE-1,16);uc.reg_write(u.X86_REG_GDTR,gdtr);
    for(const seg of [u.X86_REG_SS,u.X86_REG_DS,u.X86_REG_ES])uc.reg_write_i32(seg,16);uc.reg_write_i32(u.X86_REG_FS,24);map(TIB,PAGE);uc.mem_write(TIB,this.tib);
    hooks.push(uc.hook_add(u.HOOK_MEM_READ_UNMAPPED|u.HOOK_MEM_WRITE_UNMAPPED,(c,access,address,size)=>{const a=Number(address);if(a===SENTINEL)return false;const p=(a&~(PAGE-1))>>>0;map(p,PAGE,u.PROT_READ|u.PROT_WRITE);demand.push(p);if(((((a+size-1)&~(PAGE-1))>>>0))!==p){map(p+PAGE,PAGE,u.PROT_READ|u.PROT_WRITE);demand.push(p+PAGE);}return true;}));
    map(0,PAGE,u.PROT_READ|u.PROT_WRITE);demand.push(0);
    for(const a of this.rdtsc)hooks.push(uc.hook_add(u.HOOK_CODE,()=>{nondet.push(a);uc.emu_stop();},null,a,a));
    const cb=addCpuid(u,uc);this.regs().forEach((r,i)=>uc.reg_write_i32(r,regs[i]));uc.reg_write_i32(u.X86_REG_FPCW,FPU_CW);uc.reg_write_i32(u.X86_REG_EFLAGS,0x202);
    let err=null;try{uc.emu_start(entry,SENTINEL,0,2_000_000);}catch(e){if((uc.reg_read_i32(u.X86_REG_EIP)>>>0)!==SENTINEL)err=`unicorn: ${e} at eip=${hex(uc.reg_read_i32(u.X86_REG_EIP)>>>0)}`;}
    if(!err&&nondet.length)err='unicorn: nondeterministic (rdtsc)';if(!err&&(uc.reg_read_i32(u.X86_REG_EIP)>>>0)!==SENTINEL)err='unicorn: instruction limit';
    return {uc,err,demand,dispose(){for(const hook of hooks)uc.hook_del(hook);uc.close();u.removeFunction(cb);}};
  }
  resetC({scratch,stack,regs},demand){this.cwrite(this.base,this.image);this.cwrite(SCRATCH,scratch);this.cwrite(STACK_LO,Buffer.alloc(STACK_HI-STACK_LO));this.cwrite(TIB,this.tib);this.cwrite(GDT,GDT_PAGE);this.cwrite(regs[4],stack);for(const p of demand)this.cwrite(p,Buffer.alloc(PAGE));}
  usesFp(f){return f.ranges.some(([a,b])=>this.decoder.disasm(this.image.subarray(a-this.base,b-this.base),a).some(i=>i.mnemonic.startsWith('f')||i.mnemonic.endsWith('ss')||i.mnemonic.endsWith('ps')));}
  run(f,trials,seed){let [status,why]=this.runMode(f,trials,seed,false);if(status==='fail'&&this.usesFp(f)&&!why.includes('trap')&&!why.includes('watchdog')){const [s]=this.runMode(f,trials,seed,true);if(s==='pass'||s==='nan')return ['fp_range',why];}return [status,why];}
  runMode(f,trials,seed,sane){let nanOnly=false;for(let trial=0;trial<trials;trial++){
    const state=setupState(new PythonRandom(BigInt(seed)*1000003n+BigInt(f.entry)*31n+BigInt(trial)+(sane?7777n:0n)),sane);const run=this.runUnicorn(f.entry,state);try{
      if(run.err)return ['skip',run.err];this.resetC(state,run.demand);const cregs=new Uint32Array(state.regs),rc=this.dtRun(f.entry,cregs,FPU_CW);
      if(rc===1)return ['fail',`trap ${this.dtTrap()}`];if(rc===2)return ['skip','not recompiled'];if(rc===3)return ['fail',`trial ${trial}: recompiled code did not return (watchdog)`];
      for(let i=0;i<8;i++){const a=run.uc.reg_read_i32(this.regs()[i])>>>0,b=cregs[i];if(a===b)continue;const ab=Buffer.alloc(4),bb=Buffer.alloc(4);ab.writeUInt32LE(a);bb.writeUInt32LE(b);if(nanWord(ab,bb,0)){nanOnly=true;continue;}if(((a^b)&~0x3f)===0&&i===0&&this.usesFp(f))return ['fpu_flags',`trial ${trial}: eax unicorn=${hex(a)} recomp=${hex(b)}`];return ['fail',`trial ${trial}: ${NAMES[i]} unicorn=${hex(a)} recomp=${hex(b)}`];}
      const regions=[[this.base,this.size],[SCRATCH,SCRATCH_SIZE],[STACK_LO,STACK_HI-STACK_LO],[TIB,PAGE],[GDT,PAGE],...run.demand.map(p=>[p,PAGE])];
      for(const [a,n] of regions){const um=Buffer.from(run.uc.mem_read(a,n)),cm=this.cread(a,n);if(um.equals(cm))continue;let nonNan=-1;for(let i=0;i<n;i++)if(um[i]!==cm[i]&&!nanWord(um,cm,i)){nonNan=i;break;}if(nonNan<0){nanOnly=true;continue;}return ['fail',`trial ${trial}: memory differs at ${hex(a+nonNan)} (unicorn ${hex(um[nonNan],2)}, recomp ${hex(cm[nonNan],2)})`];}
    }finally{run.dispose();}}
    return nanOnly?['nan','only NaN bit patterns differ']:['pass',null];
  }
}
export async function main(argv){const args=argv.slice(),pos=[];let max=0,trials=5,seed=1,only='',report='',verbose=false,shard='',allowCalls=false;while(args.length){let a=args.shift();if(a==='--max')max=Number(args.shift());else if(a==='--trials')trials=Number(args.shift());else if(a==='--seed')seed=Number(args.shift());else if(a==='--only')only=args.shift();else if(a==='--report')report=args.shift();else if(a==='--verbose')verbose=true;else if(a==='--shard')shard=args.shift();else if(a==='--allow-calls')allowCalls=true;else if(a.startsWith('-'))throw new Error(`Unknown option ${a}`);else pos.push(a);}if(pos.length!==3)throw new Error('Usage: difftest.mjs <exe> <functions.json> <lib> [--max N] [--trials K] [--only 0xADDR]');
  const t=await Tester.create(pos[0],pos[2]);try{const d=JSON.parse(fs.readFileSync(pos[1],'utf8'));let funcs=d.functions.filter(f=>f.ranges.length);funcs=only?funcs.filter(f=>f.entry===parseInt(only,16)):pickFunctions(t.decoder,t.image,t.base,funcs,new Set(d.jumptables.map(j=>j.at)),allowCalls);if(max)funcs=funcs.slice(0,max);if(shard){const [k,n]=shard.split('/').map(Number);if(!Number.isInteger(k)||!Number.isInteger(n)||k<0||n<=0)throw new Error('Invalid shard');funcs=funcs.filter((_,i)=>i>=k&&(i-k)%n===0);}
  console.log(`testing ${funcs.length} functions x ${trials} trials`);const results={pass:[],nan:[],fp_range:[],fpu_flags:[],fail:[],skip:[]};for(const [i,f] of funcs.entries()){const addr=`0x${hex(f.entry)}`;if(verbose)console.log(`  run ${addr}`);const [status,why]=t.run(f,trials,seed);results[status].push([addr,f.name,why]);if(status==='fail')console.log(`FAIL ${addr} ${f.name}: ${why}`);if((i+1)%500===0)console.log(`  ... ${i+1}: pass=${results.pass.length} fail=${results.fail.length} skip=${results.skip.length}`);}console.log('\n'+Object.entries(results).map(([k,v])=>`${k}=${v.length}`).join(' '));if(report)fs.writeFileSync(report,JSON.stringify(results,null,1));}finally{t.close();}}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url))main(process.argv.slice(2)).catch(e=>{console.error(e);process.exitCode=1;});
