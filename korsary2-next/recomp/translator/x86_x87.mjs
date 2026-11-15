/** x87 C emission for the x86 static recompiler. */
import {Unsupported} from './x86_operands.mjs';
const signed={2:'int16_t',4:'int32_t',8:'int64_t'};
const binary={fadd:(a,b)=>`${a} + ${b}`,fmul:(a,b)=>`${a} * ${b}`,
 fsub:(a,b)=>`${a} - ${b}`,fsubr:(a,b)=>`${b} - ${a}`,
 fdiv:(a,b)=>`FDIV(c, ${a}, ${b})`,fdivr:(a,b)=>`FDIV(c, ${b}, ${a})`};
const constants={fld1:'1.0',fldz:'0.0',fldpi:'M_PI',fldl2e:'M_LOG2E',fldln2:'M_LN2',fldlg2:'0.30102999566398119521',fldl2t:'3.32192809488736234787'};
const unary={fchs:'-ST(0)',fabs:'fabs(ST(0))',fsqrt:'FPRES(c, sqrt(ST(0)))',fsin:'FTRIG(c, ST(0), sin)',fcos:'FTRIG(c, ST(0), cos)',frndint:'fpu_round(c, ST(0))',f2xm1:'(exp2(ST(0)) - 1.0)'};
const fcmov={fcmovb:'c->cf',fcmove:'c->zf',fcmovbe:'(c->cf || c->zf)',fcmovu:'PF(c)',fcmovnb:'!c->cf',fcmovne:'!c->zf',fcmovnbe:'(!c->cf && !c->zf)',fcmovnu:'!PF(c)'};

export function emitX87(ins, emitter, decoder) {
 let m=ins.mnemonic;const o=ins.operands,{MEM,REG}=decoder.constants;
 const st=op=>{const n=decoder.regName(op.reg);if(!n || !n.startsWith('st')) throw new Unsupported(`x87 reg ${n}`);return n.includes('(') ? Number(n[3]) : 0;};
 const fmem=(op,integer=false)=>{
  const a=emitter.address(op),s=op.size;
  if(integer && s===2)return `(double)(int16_t)R16(${a})`;
  if(integer && s===4)return `(double)(int32_t)R32(${a})`;
  if(integer && s===8)return `(double)(int64_t)R64(${a})`;
  if(!integer && s===4)return `(double)RF32(${a})`;
  if(!integer && s===8)return `RF64(${a})`;
  if(!integer && s===10)return `RF80(${a})`;
  throw new Unsupported(`x87 memory size ${s}`);
 };
 if(['fiadd','fisub','fisubr','fimul','fidiv','fidivr'].includes(m)) {
  const expression=binary['f'+m.slice(2)]('ST(0)',fmem(o[0],true));return `ST(0) = FPRES(c, ${expression});`;
 }
 const base=['fsubp','fdivp','faddp','fmulp','fsubrp','fdivrp'].includes(m) ? m.slice(0,-1) : m.replace(/p+$/,'');
 if(Object.hasOwn(binary,base)) {
  const expr=binary[base],pop=m.endsWith('p') && m!=='fsubr' && m!=='fsub';
  if(!o.length) return `ST(1) = FPRES(c, ${expr('ST(1)','ST(0)')}); FPOP(c);`;
  if(o[0].type===MEM) return `ST(0) = FPRES(c, ${expr('ST(0)',fmem(o[0]))});`;
  if(o.length===1) {const i=st(o[0]);return pop ? `ST(${i}) = FPRES(c, ${expr(`ST(${i})`,'ST(0)')}); FPOP(c);` : `ST(0) = FPRES(c, ${expr('ST(0)',`ST(${i})`)});`;}
  const dst=st(o[0]),src=st(o[1]);return `ST(${dst}) = FPRES(c, ${expr(`ST(${dst})`,`ST(${src})`)});`+(pop?' FPOP(c);':'');
 }
 if(m==='fld') return o[0].type===MEM ? `FPUSH(c, ${fmem(o[0])});` : `{ double v_ = ST(${st(o[0])}); FPUSH(c, v_); }`;
 if(m==='fild') return `FPUSH(c, ${fmem(o[0],true)});`;
 if(m==='fst' || m==='fstp') {
  const pop=m==='fstp'?' FPOP(c);':'';
  if(o[0].type===MEM) {
   const a=emitter.address(o[0]),s=o[0].size;
   if(s===4)return `WF32(${a}, (float)ST(0));`+pop;
   if(s===8)return `WF64(${a}, ST(0));`+pop;
   if(s===10)return `WF80(${a}, ST(0));`+pop;
   throw new Unsupported(`x87 memory size ${s}`);
  }
  return `ST(${st(o[0])}) = ST(0);`+pop;
 }
 if(['fist','fistp','fisttp'].includes(m)) {
  const a=emitter.address(o[0]),s=o[0].size,conv=s===8?'fpu_to_int64':'fpu_to_int32';
  const value=m==='fisttp' ? `(${signed[s]})trunc(ST(0))` : `${conv}(c, ST(0))`;
  const writes={2:`W16(${a}, (uint16_t)(int16_t)${value});`,4:`W32(${a}, (uint32_t)${value});`,8:`W64(${a}, (uint64_t)${value});`};
  if(!Object.hasOwn(writes,s)) throw new Unsupported(`x87 integer size ${s}`);
  return writes[s]+(m!=='fist'?' FPOP(c);':'');
 }
 if(m==='fxch') {const i=o.length?st(o.at(-1)):1;return `{ double t_ = ST(0); ST(0) = ST(${i}); ST(${i}) = t_; }`;}
 if(Object.hasOwn(constants,m))return `FPUSH(c, ${constants[m]});`;
 if(Object.hasOwn(unary,m))return `ST(0) = ${unary[m]};`;
 if(m==='fsincos')return '{ double v_ = ST(0); if (fabs(v_) >= 9223372036854775808.0) c->fpu_sw |= 0x0400; '
  +'else { c->fpu_sw &= ~0x0400; ST(0) = sin(v_); FPUSH(c, cos(v_)); } }';
 if(m==='fptan')return '{ double v_ = ST(0); if (fabs(v_) >= 9223372036854775808.0) c->fpu_sw |= 0x0400; '
  +'else { c->fpu_sw &= ~0x0400; ST(0) = tan(v_); FPUSH(c, 1.0); } }';
 if(m==='fpatan')return 'ST(1) = atan2(ST(1), ST(0)); FPOP(c);';
 if(m==='fyl2x')return 'ST(1) = ST(1) * log2(ST(0)); FPOP(c);';
 if(m==='fscale')return 'ST(0) = ldexp(ST(0), (int)trunc(ST(1)));';
 if(m==='fprem' || m==='fprem1')return `ST(0) = ${m==='fprem'?'fmod':'remainder'}(ST(0), ST(1)); c->fpu_sw &= ~0x0400;`;
 if(['fcom','fcomp','fucom','fucomp','ficom','ficomp'].includes(m)) {
  const b=!o.length?'ST(1)':o[0].type===MEM?fmem(o[0],m.startsWith('fi')):`ST(${st(o.at(-1))})`;
  return `FCOM(c, ST(0), ${b});`+(m.endsWith('p')?' FPOP(c);':'');
 }
 if(m==='fcompp'||m==='fucompp')return 'FCOM(c, ST(0), ST(1)); FPOP(c); FPOP(c);';
 if(m==='fcompi'||m==='fucompi')m=m.slice(0,-2)+'ip';
 if(['fcomi','fucomi','fcomip','fucomip'].includes(m))return `FCOMI(c, ST(0), ST(${st(o.at(-1))}));`+(m.endsWith('p')?' FPOP(c);':'');
 if(Object.hasOwn(fcmov,m))return `if (${fcmov[m]}) ST(0) = ST(${st(o.at(-1))});`;
 if(m==='ftst')return 'FCOM(c, ST(0), 0.0);';
 if(m==='fxam')return '{ double v_ = ST(0); uint16_t sw_ = c->fpu_sw & ~0x4700; if (signbit(v_)) sw_ |= 0x0200; '
  +'if (isnan(v_)) sw_ |= 0x0100; else if (isinf(v_)) sw_ |= 0x0500; else if (v_ == 0) sw_ |= 0x4000; '
  +'else sw_ |= 0x0400; c->fpu_sw = sw_; }';
 if(m==='fnstsw'||m==='fstsw')return o.length && o[0].type===REG ? emitter.regWrite('ax','FNSTSW(c)') : `W16(${emitter.address(o[0])}, FNSTSW(c));`;
 if(m==='fnstcw'||m==='fstcw')return `W16(${emitter.address(o[0])}, c->fpu_cw);`;
 if(m==='fldcw')return `c->fpu_cw = R16(${emitter.address(o[0])}); fpu_sync_rounding(c);`;
 if(m==='fnclex'||m==='fclex')return 'c->fpu_sw &= 0x7f00;';
 if(m==='fninit'||m==='finit')return 'c->fpu_cw = 0x037f; c->fpu_sw = 0; c->top = 0; fpu_sync_rounding(c);';
 if(m==='ffree')return ';';
 if(m==='fincstp')return 'c->top = (c->top + 1) & 7;';
 if(m==='fdecstp')return 'c->top = (c->top - 1) & 7;';
 throw new Unsupported(m);
}
