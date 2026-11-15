/** SSE C emission for the x86 static recompiler. */
import {Unsupported} from './x86_operands.mjs';
const packed={addps:'+',subps:'-',mulps:'*',divps:'/'};
const scalar={addss:'+',subss:'-',mulss:'*',divss:'/'};
const predicates={eq:'a_ == b_',lt:'a_ < b_',le:'a_ <= b_',unord:'(a_ != a_ || b_ != b_)',
 neq:'!(a_ == b_)',nlt:'!(a_ < b_)',nle:'!(a_ <= b_)',ord:'(a_ == a_ && b_ == b_)'};
export function emitSse(ins,e,decoder) {
 const m=ins.mnemonic,o=ins.operands,{REG,MEM}=decoder.constants;
 const xmm=op=>{const name=op.type===REG?decoder.regName(op.reg):null;if(!name?.startsWith('xmm')) throw new Unsupported('MMX/non-XMM operand');return `c->xmm[${name.slice(3)}]`;};
 if(Object.hasOwn(packed,m)||Object.hasOwn(scalar,m)) {
  const d=xmm(o[0]),n=Object.hasOwn(packed,m)?4:1,op=(packed[m]||scalar[m]);
  const src=o[1].type===MEM ? k=>`RF32(${e.address(o[1])} + ${4*k})` : k=>`${xmm(o[1])}.f[${k}]`;
  const loads=Array.from({length:n},(_,k)=>`float s${k}_ = ${src(k)};`).join(' ');
  const body=Array.from({length:n},(_,k)=>`${d}.f[${k}] = ${d}.f[${k}] ${op} s${k}_;`).join(' ');
  return `{ ${loads} ${body} }`;
 }
 if(['movaps','movups','movdqa','movdqu','movapd','movupd'].includes(m)) {
  if(o[0].type===MEM)return `memcpy(HP(${e.address(o[0])}), ${xmm(o[1])}.b, 16);`;
  if(o[1].type===MEM)return `memcpy(${xmm(o[0])}.b, HP(${e.address(o[1])}), 16);`;
  return `${xmm(o[0])} = ${xmm(o[1])};`;
 }
 if(m==='movss') {
  if(o[0].type===MEM)return `WF32(${e.address(o[0])}, ${xmm(o[1])}.f[0]);`;
  if(o[1].type===MEM){const d=xmm(o[0]);return `${d}.f[0] = RF32(${e.address(o[1])}); ${d}.u[1] = ${d}.u[2] = ${d}.u[3] = 0;`;}
  return `${xmm(o[0])}.f[0] = ${xmm(o[1])}.f[0];`;
 }
 if(m==='movlps'||m==='movhps') {
  const k=m==='movlps'?0:1;
  if(o[0].type===MEM)return `W64(${e.address(o[0])}, ${xmm(o[1])}.q[${k}]);`;
  return `${xmm(o[0])}.q[${k}] = R64(${e.address(o[1])});`;
 }
 if(m==='movhlps')return `${xmm(o[0])}.q[0] = ${xmm(o[1])}.q[1];`;
 if(m==='movlhps')return `${xmm(o[0])}.q[1] = ${xmm(o[1])}.q[0];`;
 if(['andps','andnps','orps','xorps'].includes(m)) {
  const d=xmm(o[0]),src=o[1].type===MEM?k=>`R32(${e.address(o[1])} + ${4*k})`:k=>`${xmm(o[1])}.u[${k}]`;
  const expr=(a,b)=>({andps:`${a} & ${b}`,andnps:`~${a} & ${b}`,orps:`${a} | ${b}`,xorps:`${a} ^ ${b}`})[m];
  const loads=Array.from({length:4},(_,k)=>`uint32_t s${k}_ = ${src(k)};`).join(' ');
  const body=Array.from({length:4},(_,k)=>`${d}.u[${k}] = ${expr(`${d}.u[${k}]`,`s${k}_`)};`).join(' ');
  return `{ ${loads} ${body} }`;
 }
 if(m==='shufps') {
  const d=xmm(o[0]),imm=Number(o[2].imm),sel=Array.from({length:4},(_,k)=>(imm>>(2*k))&3);
  const src=o[1].type===MEM?k=>`RF32(${e.address(o[1])} + ${4*k})`:k=>`${xmm(o[1])}.f[${k}]`;
  return `{ XMM t_ = ${d}; ${d}.f[0] = t_.f[${sel[0]}]; ${d}.f[1] = t_.f[${sel[1]}]; ${d}.f[2] = ${src(sel[2])}; ${d}.f[3] = ${src(sel[3])}; }`;
 }
 if(m==='unpcklps'||m==='unpckhps') {
  const d=xmm(o[0]),s=xmm(o[1]),b=m==='unpcklps'?0:2;
  return `{ XMM a_ = ${d}, b_ = ${s}; ${d}.f[0] = a_.f[${b}]; ${d}.f[1] = b_.f[${b}]; ${d}.f[2] = a_.f[${b+1}]; ${d}.f[3] = b_.f[${b+1}]; }`;
 }
 const sfn={sqrtss:x=>`sqrtf(${x})`,rsqrtss:x=>`1.0f / sqrtf(${x})`,rcpss:x=>`1.0f / ${x}`};
 const pfn={sqrtps:x=>`sqrtf(${x})`,rsqrtps:x=>`1.0f / sqrtf(${x})`,rcpps:x=>`1.0f / ${x}`};
 if(Object.hasOwn(sfn,m)) {
  const d=xmm(o[0]),v=o[1].type===MEM?`RF32(${e.address(o[1])})`:`${xmm(o[1])}.f[0]`;
  return `${d}.f[0] = ${sfn[m](v)};`;
 }
 if(Object.hasOwn(pfn,m)) {
  const d=xmm(o[0]),s=xmm(o[1]);return '{ XMM s_ = '+s+'; '+Array.from({length:4},(_,k)=>`${d}.f[${k}] = ${pfn[m](`s_.f[${k}]`)};`).join(' ')+' }';
 }
 if(['minss','maxss','minps','maxps'].includes(m)) {
  const d=xmm(o[0]),n=m.endsWith('ss')?1:4,cmp=m.startsWith('min')?'<':'>';
  const src=o[1].type===MEM?k=>`RF32(${e.address(o[1])} + ${4*k})`:k=>`${xmm(o[1])}.f[${k}]`;
  return '{ '+Array.from({length:n},(_,k)=>`float s${k}_ = ${src(k)}; ${d}.f[${k}] = ${d}.f[${k}] ${cmp} s${k}_ ? ${d}.f[${k}] : s${k}_;`).join(' ')+' }';
 }
 if(m==='comiss'||m==='ucomiss') {
  const s=o[1].type===MEM?`RF32(${e.address(o[1])})`:`${xmm(o[1])}.f[0]`;return `FCOMI(c, ${xmm(o[0])}.f[0], ${s});`;
 }
 if(m==='cvtsi2ss')return `${xmm(o[0])}.f[0] = (float)(int32_t)${e.read(o[1],4)};`;
 if(m==='cvttss2si'||m==='cvtss2si') {
  const s=o[1].type===MEM?`RF32(${e.address(o[1])})`:`${xmm(o[1])}.f[0]`,conv=m==='cvttss2si'?`(int32_t)${s}`:`(int32_t)nearbyintf(${s})`;
  return e.write(o[0],`(uint32_t)${conv}`);
 }
 if(m==='movd') {
  if(o[0].type===REG && decoder.regName(o[0].reg).startsWith('xmm')) {const d=xmm(o[0]);return `${d}.u[0] = ${e.read(o[1],4)}; ${d}.u[1] = ${d}.u[2] = ${d}.u[3] = 0;`;}
  return e.write(o[0],`${xmm(o[1])}.u[0]`,4);
 }
 if(m.startsWith('cmp') && ['ps','ss'].includes(m.slice(-2)) && Object.hasOwn(predicates,m.slice(3,-2))) {
  const d=xmm(o[0]),n=m.endsWith('ps')?4:1,src=o[1].type===MEM?k=>`RF32(${e.address(o[1])} + ${4*k})`:k=>`${xmm(o[1])}.f[${k}]`,predicate=predicates[m.slice(3,-2)];
  return '{ '+Array.from({length:n},(_,k)=>`{ float a_ = ${d}.f[${k}], b_ = ${src(k)}; ${d}.u[${k}] = (${predicate}) ? 0xffffffffu : 0; }`).join(' ')+' }';
 }
 if(['pxor','pand','por','pandn'].includes(m)&&decoder.regName(o[0].reg).startsWith('xmm')) {
  const d=xmm(o[0]),src=o[1].type===MEM?k=>`R64(${e.address(o[1])} + ${8*k})`:k=>`${xmm(o[1])}.q[${k}]`;
  const expr=(a,b)=>({pxor:`${a} ^ ${b}`,pand:`${a} & ${b}`,por:`${a} | ${b}`,pandn:`~${a} & ${b}`})[m];
  return '{ '+Array.from({length:2},(_,k)=>`uint64_t s${k}_ = ${src(k)};`).join(' ')+' '+Array.from({length:2},(_,k)=>`${d}.q[${k}] = ${expr(`${d}.q[${k}]`,`s${k}_`)};`).join(' ')+' }';
 }
 if(m==='movq'&&o.every(op=>op.type===MEM || decoder.regName(op.reg).startsWith('xmm'))) {
  if(o[0].type===MEM)return `W64(${e.address(o[0])}, ${xmm(o[1])}.q[0]);`;
  const d=xmm(o[0]),v=o[1].type===MEM?`R64(${e.address(o[1])})`:`${xmm(o[1])}.q[0]`;
  return `{ uint64_t v_ = ${v}; ${d}.q[0] = v_; ${d}.q[1] = 0; }`;
 }
 if(m==='cvtpi2ps' && o[1].type===MEM) {const d=xmm(o[0]),a=e.address(o[1]);return `${d}.f[0] = (float)(int32_t)R32(${a}); ${d}.f[1] = (float)(int32_t)R32(${a} + 4);`;}
 if(m==='cvtps2pd') {
  const d=xmm(o[0]);if(o[1].type===MEM){const a=e.address(o[1]);return `{ float x_ = RF32(${a}), y_ = RF32(${a} + 4); ${d}.d[0] = x_; ${d}.d[1] = y_; }`;}
  const s=xmm(o[1]);return `{ float x_ = ${s}.f[0], y_ = ${s}.f[1]; ${d}.d[0] = x_; ${d}.d[1] = y_; }`;
 }
 if(m==='ldmxcsr')return `c->mxcsr = R32(${e.address(o[0])});`;
 if(m==='stmxcsr')return `W32(${e.address(o[0])}, c->mxcsr);`;
 if(['prefetchnta','prefetcht0','prefetcht1','prefetcht2','emms','sfence','lfence','mfence'].includes(m))return ';';
 throw new Unsupported(m);
}
