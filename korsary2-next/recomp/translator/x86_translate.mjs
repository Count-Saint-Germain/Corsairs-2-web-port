/**
 * x86-to-C function emission. Unsupported opcodes emit guest_trap, matching
 * the existing recompiler behaviour.
 */
import {OperandEmitter, Unsupported} from './x86_operands.mjs';
import {decodeFunction,isLocked,isTerminator} from './x86_cfg.mjs';
import {emitX87} from './x86_x87.mjs';
import {emitVector} from './x86_vector.mjs';
import {emitSse} from './x86_sse.mjs';

const cond={o:'c->of',no:'!c->of',b:'c->cf',ae:'!c->cf',e:'c->zf',ne:'!c->zf',
  be:'(c->cf || c->zf)',a:'(!c->cf && !c->zf)',s:'c->sf',ns:'!c->sf',
  p:'PF(c)',np:'!PF(c)',l:'(c->sf != c->of)',ge:'(c->sf == c->of)',
  le:'(c->zf || c->sf != c->of)',g:'(!c->zf && c->sf == c->of)'};
const types={1:'uint8_t',2:'uint16_t',4:'uint32_t',8:'uint64_t'};
const signed={1:'int8_t',2:'int16_t',4:'int32_t',8:'int64_t'};
const bits={1:8,2:16,4:32};
const hex=value=>Number(BigInt.asUintN(32,BigInt(value))).toString(16);
const hex8=value=>hex(value).padStart(8,'0');

export class FunctionTranslator {
  constructor(program, fn) {
    this.p=program;this.fn=fn;this.entry=Number(fn.entry);this.labels=new Set();
    this.emitter=new OperandEmitter(program.decoder);
  }
  targetStmt(value) {
    const target=Number(value);
    if(this.instructionAddresses.has(target)) {this.labels.add(target);return `goto L_${hex8(target)};`;}
    if(this.p.entries.has(target)) return `{ f_${hex8(target)}(c); return; }`;
    return `{ jump_indirect(c, 0x${hex8(target)}u, 0x${hex8(this.current)}u); return; }`;
  }
  callStmt(ins,targetExpr,directTarget) {
    const ret=Number(ins.address)+ins.size;
    if(directTarget!==undefined) {
      const t=Number(directTarget);
      if(this.p.entries.has(t)) return `PUSH32(c, 0x${hex8(ret)}u); f_${hex8(t)}(c);`;
      return `PUSH32(c, 0x${hex8(ret)}u); call_indirect(c, 0x${hex8(t)}u);`;
    }
    return `{ uint32_t t_ = ${targetExpr}; PUSH32(c, 0x${hex8(ret)}u); call_indirect(c, t_); }`;
  }
  arith(o,fn,store=true) {
    const e=this.emitter,s=o[0].size,b=e.read(o[1],s);
    if(!bits[s]) throw new Unsupported(`arithmetic width ${s}`);
    if(!store) return `(void)${fn}${bits[s]}(c, ${e.read(o[0])}, ${b});`;
    return e.rmw(o[0],a=>`${fn}${bits[s]}(c, ${a}, ${b})`);
  }
  logic(o,op,store=true) {
    const e=this.emitter,s=o[0].size,{REG}=this.p.decoder.constants;
    if(!bits[s]) throw new Unsupported(`logic width ${s}`);
    if(store && op==='^' && o[0].type===REG && o[1].type===REG && o[0].reg===o[1].reg)
      return e.write(o[0],`logic${bits[s]}(c, 0)`);
    const b=e.read(o[1],s);
    if(!store) return `(void)logic${bits[s]}(c, (${types[s]})(${e.read(o[0])} ${op} ${b}));`;
    return e.rmw(o[0],a=>`logic${bits[s]}(c, (${types[s]})(${a} ${op} ${b}))`);
  }
  stringOp(m, rep) {
    const e=this.emitter,size={b:1,w:2,d:4}[m.at(-1)],base=m.slice(0,-1);
    if(!size) throw new Unsupported(m);
    const n=bits[size], type=types[size],step=`(c->df ? -${size} : ${size})`,acc={1:'al',2:'ax',4:'eax'}[size];
    let one;
    if(base==='movs') one=`W${n}(c->edi, R${n}(c->esi)); c->esi += ${step}; c->edi += ${step};`;
    else if(base==='stos') one=`W${n}(c->edi, (${type})${e.regRead(acc)}); c->edi += ${step};`;
    else if(base==='lods') one=e.regWrite(acc,`R${n}(c->esi)`)+` c->esi += ${step};`;
    else if(base==='scas') one=`(void)sub${n}(c, ${e.regRead(acc)}, R${n}(c->edi)); c->edi += ${step};`;
    else if(base==='cmps') one=`(void)sub${n}(c, R${n}(c->esi), R${n}(c->edi)); c->esi += ${step}; c->edi += ${step};`;
    else throw new Unsupported(m);
    if(!rep) return one;
    if(['movs','stos','lods'].includes(base)) {
      if(base==='movs' && size===4) return 'if (!c->df && (c->edi - c->esi >= c->ecx * 4u || c->edi <= c->esi)) { '
        +'memmove(HP(c->edi), HP(c->esi), (size_t)c->ecx * 4); '
        +'c->esi += c->ecx * 4; c->edi += c->ecx * 4; c->ecx = 0; } '
        +`else while (c->ecx) { ${one} c->ecx--; }`;
      return `while (c->ecx) { ${one} c->ecx--; }`;
    }
    const stop=['rep','repe','repz'].includes(rep) ? '!c->zf' : 'c->zf';
    return `while (c->ecx) { ${one} c->ecx--; if (${stop}) break; }`;
  }
  instruction(ins) {
    const o=ins.operands,m=ins.mnemonic,e=this.emitter,{REG,IMM,MEM}=this.p.decoder.constants;
    const rep=ins.prefix.includes(0xf3)||ins.prefix.includes(0xf2);
    if(m.startsWith('rep ')||m.startsWith('repne ')||m.startsWith('repe ')) {
      const [prefix,op]=m.split(' ');return this.stringOp(op,prefix);
    }
    if(['movsb','movsw','stosb','stosw','stosd','lodsb','lodsw','lodsd','scasb','scasw','scasd','cmpsb','cmpsw','cmpsd'].includes(m)
        || (m==='movsd' && o.length===2 && o[0].type===MEM && o[1].type===MEM)) return this.stringOp(m,rep?'rep':null);
    if(m==='mov') return e.write(o[0],e.read(o[1],o[0].size));
    if(m==='movzx') return e.write(o[0],`(uint32_t)${e.read(o[1])}`);
    if(m==='movsx') return e.write(o[0],`(uint32_t)(int32_t)(${signed[o[1].size]})${e.read(o[1])}`);
    if(m==='lea') return e.write(o[0],e.address(o[1]).replace(' + c->fs_base',''));
    if(m==='xchg') {
      const s=o[0].size;
      if(o[0].type===REG && o[1].type===REG && o[0].reg===o[1].reg) return ';';
      const a=e.read(o[0]),b=e.read(o[1]);
      return `{ ${types[s]} t0_ = ${a}, t1_ = ${b}; ${e.write(o[0],'t1_')} ${e.write(o[1],'t0_')} }`;
    }
    if(m==='push') {
      if(o[0].size===2) return `c->esp -= 2; W16(c->esp, ${e.read(o[0])});`;
      const value=o[0].type===IMM ? `0x${hex(o[0].imm)}u` : e.read(o[0],4);
      return `{ uint32_t v_ = ${value}; PUSH32(c, v_); }`;
    }
    if(m==='pop') return o[0].type===MEM
      ? `{ uint32_t v_ = R32(c->esp); c->esp += 4; ${e.write(o[0],'v_')} }`
      : `{ uint32_t v_ = POP32(c); ${e.write(o[0],'v_')} }`;
    if(m==='pushal') return '{ uint32_t s_ = c->esp; PUSH32(c, c->eax); PUSH32(c, c->ecx); PUSH32(c, c->edx); '
      +'PUSH32(c, c->ebx); PUSH32(c, s_); PUSH32(c, c->ebp); PUSH32(c, c->esi); PUSH32(c, c->edi); }';
    if(m==='popal') return 'c->edi = POP32(c); c->esi = POP32(c); c->ebp = POP32(c); c->esp += 4; '
      +'c->ebx = POP32(c); c->edx = POP32(c); c->ecx = POP32(c); c->eax = POP32(c);';
    const flags='((uint32_t)c->cf | (PF(c) << 2) | ((uint32_t)c->zf << 6) | ((uint32_t)c->sf << 7) | '
      +'((uint32_t)c->df << 10) | ((uint32_t)c->of << 11) | ((uint32_t)c->idf << 21) | 0x202u)';
    if(m==='pushfd') return `PUSH32(c, ${flags});`;
    if(m==='popfd') return '{ uint32_t f_ = POP32(c); c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; '
      +'c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; c->df = (f_ >> 10) & 1; c->of = (f_ >> 11) & 1; '
      +'c->idf = (f_ >> 21) & 1; }';
    if(m==='lahf') return e.regWrite('ah','(c->cf | (PF(c) << 2) | 2 | (c->zf << 6) | (c->sf << 7))');
    if(m==='sahf') return '{ uint32_t f_ = (c->eax >> 8) & 0xff; c->cf = f_ & 1; c->pf_byte = (f_ >> 2) & 1 ? 0 : 1; '
      +'c->zf = (f_ >> 6) & 1; c->sf = (f_ >> 7) & 1; }';
    if(m==='cdq') return 'c->edx = (uint32_t)((int32_t)c->eax >> 31);';
    if(m==='cwde') return 'c->eax = (uint32_t)(int32_t)(int16_t)c->eax;';
    if(m==='cbw') return e.regWrite('ax','(uint16_t)(int16_t)(int8_t)c->eax');
    if(m==='cwd') return e.regWrite('dx','((int16_t)c->eax < 0) ? 0xffff : 0');
    if(m==='bswap') return e.write(o[0],`__builtin_bswap32(${e.read(o[0])})`);
    if(m==='xlatb') return e.regWrite('al','R8(c->ebx + (uint8_t)c->eax)');
    if(m==='cpuid') return 'cpuid(c);';
    if(m==='rdtsc') return 'rdtsc(c);';
    const arithmetic={add:'add',adc:'adc',sub:'sub',sbb:'sbb',cmp:'sub'};
    if(Object.hasOwn(arithmetic,m)) return this.arith(o,arithmetic[m],m!=='cmp');
    const logic={and:'&',or:'|',xor:'^',test:'&'};
    if(Object.hasOwn(logic,m)) return this.logic(o,logic[m],m!=='test');
    if(m==='not') return e.rmw(o[0],a=>`(${types[o[0].size]})~${a}`);
    if(['inc','dec','neg'].includes(m)) return e.rmw(o[0],a=>`${m}${bits[o[0].size]}(c, ${a})`);
    const shifts={shl:'shl',sal:'shl',shr:'shr',sar:'sar',rol:'rol',ror:'ror',rcl:'rcl',rcr:'rcr'};
    if(Object.hasOwn(shifts,m)) {
      const n=o.length===1 ? '1' : o[1].type===IMM ? String(o[1].imm) : '(c->ecx & 0xff)';
      return e.rmw(o[0],a=>`${shifts[m]}${bits[o[0].size]}(c, ${a}, ${n})`);
    }
    if(m==='shld' || m==='shrd') {
      const n=o[2].type===IMM ? String(o[2].imm) : '(c->ecx & 0xff)',src=e.read(o[1]);
      if(m==='shld') return e.rmw(o[0],a=>`({ unsigned n_ = ${n} & 31; uint32_t r_ = n_ ? ((${a} << n_) | (${src} >> (32 - n_))) : ${a}; `
        +`if (n_) { c->cf = (${a} >> (32 - n_)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })`);
      return e.rmw(o[0],a=>`({ unsigned n_ = ${n} & 31; uint32_t r_ = n_ ? ((${a} >> n_) | (${src} << (32 - n_))) : ${a}; `
        +`if (n_) { c->cf = (${a} >> (n_ - 1)) & 1; c->zf = r_ == 0; c->sf = (int32_t)r_ < 0; c->pf_byte = (uint8_t)r_; } r_; })`);
    }
    if(m==='mul') {
      const s=o[0].size, v=e.read(o[0]);
      if(s===4)return '{ uint64_t r_ = (uint64_t)c->eax * '+v+'; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = c->edx != 0; }';
      if(s===2)return '{ uint32_t r_ = (uint32_t)(uint16_t)c->eax * '+v+'; '+e.regWrite('ax','r_')+' '+e.regWrite('dx','r_ >> 16')+' c->cf = c->of = (r_ >> 16) != 0; }';
      return '{ uint16_t r_ = (uint16_t)((uint8_t)c->eax * '+v+'); '+e.regWrite('ax','r_')+' c->cf = c->of = (r_ >> 8) != 0; }';
    }
    if(m==='div' || m==='idiv') {
      const s=o[0].size,d=e.read(o[0]), trap=`if (!d_) guest_trap(c, 0x${hex8(ins.address)}u, "divide by zero"); `;
      if(m==='div') {
        if(s===4)return '{ uint32_t d_ = '+d+'; uint64_t n_ = ((uint64_t)c->edx << 32) | c->eax; '+trap+'c->eax = (uint32_t)(n_ / d_); c->edx = (uint32_t)(n_ % d_); }';
        if(s===2)return '{ uint32_t d_ = '+d+'; uint32_t n_ = ((c->edx & 0xffff) << 16) | (c->eax & 0xffff); '+trap+e.regWrite('ax','n_ / d_')+' '+e.regWrite('dx','n_ % d_')+' }';
        return '{ uint32_t d_ = '+d+'; uint32_t n_ = c->eax & 0xffff; '+trap+e.regWrite('al','n_ / d_')+' '+e.regWrite('ah','n_ % d_')+' }';
      }
      if(s===4)return '{ int32_t d_ = (int32_t)'+d+'; int64_t n_ = (int64_t)(((uint64_t)c->edx << 32) | c->eax); '+trap+'c->eax = (uint32_t)(int32_t)(n_ / d_); c->edx = (uint32_t)(int32_t)(n_ % d_); }';
      if(s===2)return '{ int32_t d_ = (int16_t)'+d+'; int32_t n_ = (int32_t)(((c->edx & 0xffff) << 16) | (c->eax & 0xffff)); '+trap+e.regWrite('ax','n_ / d_')+' '+e.regWrite('dx','n_ % d_')+' }';
      return '{ int32_t d_ = (int8_t)'+d+'; int32_t n_ = (int16_t)c->eax; '+trap+e.regWrite('al','n_ / d_')+' '+e.regWrite('ah','n_ % d_')+' }';
    }
    if(['bt','bts','btr','btc'].includes(m)) {
      const size=o[0].size;
      if(!bits[size] || !types[size]) throw new Unsupported(`bit width ${size}`);
      const b=o[1].type===IMM ? `${((o[1].imm%BigInt(bits[size]))+BigInt(bits[size]))%BigInt(bits[size])}u` : `(${e.read(o[1])})`;
      if(o[1].type!==IMM && o[0].type===MEM) {
        const addr=e.address(o[0]), updates={bt:'',bts:' W32(a_, v_ | (1u << k_));',btr:' W32(a_, v_ & ~(1u << k_));',btc:' W32(a_, v_ ^ (1u << k_));'};
        return `{ int32_t b_ = (int32_t)${b}; uint32_t a_ = ${addr} + (uint32_t)((b_ >> 3) & ~3); unsigned k_ = b_ & 31; uint32_t v_ = R32(a_); c->cf = (v_ >> k_) & 1;`+updates[m]+' }';
      }
      const k=`(${b} % ${bits[size]})`,cf=`c->cf = (${e.read(o[0])} >> ${k}) & 1;`;
      if(m==='bt')return cf;
      const op={bts:'|',btr:'& ~',btc:'^'}[m];
      return '{ '+cf+' '+e.rmw(o[0],a=>`(${types[size]})(${a} ${op} (((${types[size]})1) << ${k}))`)+' }';
    }
    if(m==='imul') {
      if(o.length===1) {
        const s=o[0].size;
        if(s===4) return '{ int64_t r_ = (int64_t)(int32_t)c->eax * (int32_t)'+e.read(o[0])+'; c->eax = (uint32_t)r_; c->edx = (uint32_t)(r_ >> 32); c->cf = c->of = r_ != (int32_t)r_; }';
        if(s===2) return '{ int32_t r_ = (int16_t)c->eax * (int16_t)'+e.read(o[0])+'; '+e.regWrite('ax','r_')+' '+e.regWrite('dx','r_ >> 16')+' c->cf = c->of = r_ != (int16_t)r_; }';
        return '{ int16_t r_ = (int8_t)c->eax * (int8_t)'+e.read(o[0])+'; '+e.regWrite('ax','r_')+' c->cf = c->of = r_ != (int8_t)r_; }';
      }
      const s=o[0].size,a=o.length===2 ? e.read(o[0]) : e.read(o[1]),b=o.length===2 ? e.read(o[1]) : e.read(o[2],s);
      return '{ int64_t r_ = (int64_t)('+signed[s]+')'+a+' * ('+signed[s]+')'+b+'; '+e.write(o[0],'r_')+` c->cf = c->of = r_ != (${signed[s]})r_; }`;
    }
    if(['nop','fwait','wait'].includes(m)) return ';';
    if(['clc','stc','cmc','cld','std'].includes(m)) return {clc:'c->cf = 0;',stc:'c->cf = 1;',cmc:'c->cf ^= 1;',cld:'c->df = 0;',std:'c->df = 1;'}[m];
    if(['int3','hlt','ud2'].includes(m)) return `guest_trap(c, 0x${hex8(ins.address)}u, "${m}");`;
    if(m==='int') return `guest_trap(c, 0x${hex8(ins.address)}u, "int ${ins.op_str}");`;
    if(m==='jmp') {
      if(o[0].type===IMM) return this.targetStmt(o[0].imm);
      const v=e.read(o[0],4),targets=this.p.jumpTables.get(Number(ins.address)) || [];
      const included=[...new Set(targets)].sort((a,b)=>a-b).filter(t=>this.instructionAddresses.has(t));
      for(const target of included) this.labels.add(target);
      const cases=included.map(t=>`case 0x${hex8(t)}u: goto L_${hex8(t)};`).join(' ');
      return `{ uint32_t t_ = ${v}; switch (t_) { ${cases} default: jump_indirect(c, t_, 0x${hex8(ins.address)}u); return; } }`;
    }
    if(m==='call') return o[0].type===IMM ? this.callStmt(ins,null,o[0].imm) : this.callStmt(ins,e.read(o[0],4));
    if(m==='ret' || m==='retn') return `c->esp += ${4+(o.length ? Number(o[0].imm) : 0)}; return;`;
    if(m==='leave') return 'c->esp = c->ebp; c->ebp = POP32(c);';
    if(m==='jecxz') return `if (c->ecx == 0) ${this.targetStmt(o[0].imm)}`;
    if(m==='jcxz') return `if ((c->ecx & 0xffff) == 0) ${this.targetStmt(o[0].imm)}`;
    if(m==='loop') return `if (--c->ecx != 0) ${this.targetStmt(o[0].imm)}`;
    if(m.startsWith('j') && Object.hasOwn(cond,m.slice(1))) return `if (${cond[m.slice(1)]}) ${this.targetStmt(o[0].imm)}`;
    if(m.startsWith('set') && Object.hasOwn(cond,m.slice(3))) return e.write(o[0],`${cond[m.slice(3)]} ? 1 : 0`);
    if(m.startsWith('cmov') && Object.hasOwn(cond,m.slice(4))) return `if (${cond[m.slice(4)]}) ${e.write(o[0],e.read(o[1]))}`;
    if(m.startsWith('f') && m!=='femms') return emitX87(ins,e,this.p.decoder);
    const vector=emitVector(ins,e,this.p.decoder);
    if(vector!==null) return vector;
    return emitSse(ins,e,this.p.decoder);
  }
  translate() {
    const insns=decodeFunction(this.p,this.fn);
    this.instructionAddresses=new Set(insns.map(i=>Number(i.address)));
    const body=[],unsupported=[];
    for(let k=0;k<insns.length;k++) {
      const ins=insns[k];this.current=Number(ins.address);
      let stmt;
      try {stmt=this.instruction(ins)}
      catch(err) {
        if(!(err instanceof Unsupported)) throw err;
        unsupported.push(`${ins.mnemonic} (${err.message})`);
        stmt=`guest_trap(c, 0x${hex8(ins.address)}u, "unsupported: ${ins.mnemonic} ${ins.op_str}");`;
      }
      if(isLocked(ins,this.p.decoder.constants)) stmt=`{ guest_lock(); ${stmt} guest_unlock(); }`;
      body.push([ins,stmt]);
      const next=Number(ins.address)+ins.size, following=k+1<insns.length ? Number(insns[k+1].address) : null;
      if(following!==next && !isTerminator(ins)) body.push([null,this.targetStmt(next)]);
    }
    const lines=[`void f_${hex8(this.entry)}(CPU *c) { /* ${this.fn.name} */`,'    PREEMPT_POLL(c);'];
    if(insns.length && Number(insns[0].address)!==this.entry){this.labels.add(this.entry);lines.push(`    goto L_${hex8(this.entry)};`);}
    for(const [ins,stmt] of body) {
      if(ins) {
        if(this.labels.has(Number(ins.address))) lines.push(`L_${hex8(ins.address)}:;`);
        if(this.p.trace) lines.push(`    trace_insn(c, 0x${hex8(ins.address)}u);`);
        lines.push(`    ${stmt} /* ${ins.mnemonic} ${ins.op_str} */`);
      } else lines.push(`    ${stmt}`);
    }
    lines.push('}');
    return {source:lines.join('\n')+'\n',unsupported,count:insns.length};
  }
}
