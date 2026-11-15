/** Packed integer (MMX/SSE2) C emission for the x86 static recompiler. */
import {Unsupported} from './x86_operands.mjs';
const vbin={
 paddb:'v_add(a_, b_, N, 1, 0)',paddw:'v_add(a_, b_, N, 2, 0)',paddd:'v_add(a_, b_, N, 4, 0)',paddq:'v_add(a_, b_, N, 8, 0)',paddsb:'v_add(a_, b_, N, 1, 1)',paddsw:'v_add(a_, b_, N, 2, 1)',paddusb:'v_add(a_, b_, N, 1, 2)',paddusw:'v_add(a_, b_, N, 2, 2)',
 psubb:'v_sub(a_, b_, N, 1, 0)',psubw:'v_sub(a_, b_, N, 2, 0)',psubd:'v_sub(a_, b_, N, 4, 0)',psubq:'v_sub(a_, b_, N, 8, 0)',psubsb:'v_sub(a_, b_, N, 1, 1)',psubsw:'v_sub(a_, b_, N, 2, 1)',psubusb:'v_sub(a_, b_, N, 1, 2)',psubusw:'v_sub(a_, b_, N, 2, 2)',
 pmullw:'v_mulw(a_, b_, N, 0)',pmulhw:'v_mulw(a_, b_, N, 1)',pmulhuw:'v_mulw(a_, b_, N, 2)',pmaddwd:'v_pmaddwd(a_, b_, N)',pmuludq:'v_pmuludq(a_, b_, N)',
 pand:'v_logic(a_, b_, N, 0)',pandn:'v_logic(a_, b_, N, 1)',por:'v_logic(a_, b_, N, 2)',pxor:'v_logic(a_, b_, N, 3)',
 punpcklbw:'v_unpack(a_, b_, N, 1, 0)',punpcklwd:'v_unpack(a_, b_, N, 2, 0)',punpckldq:'v_unpack(a_, b_, N, 4, 0)',punpcklqdq:'v_unpack(a_, b_, N, 8, 0)',
 punpckhbw:'v_unpack(a_, b_, N, 1, 1)',punpckhwd:'v_unpack(a_, b_, N, 2, 1)',punpckhdq:'v_unpack(a_, b_, N, 4, 1)',punpckhqdq:'v_unpack(a_, b_, N, 8, 1)',
 packsswb:'v_pack(a_, b_, N, 2, 1)',packuswb:'v_pack(a_, b_, N, 2, 0)',packssdw:'v_pack(a_, b_, N, 4, 1)',
 pcmpeqb:'v_cmp(a_, b_, N, 1, 0)',pcmpeqw:'v_cmp(a_, b_, N, 2, 0)',pcmpeqd:'v_cmp(a_, b_, N, 4, 0)',pcmpgtb:'v_cmp(a_, b_, N, 1, 1)',pcmpgtw:'v_cmp(a_, b_, N, 2, 1)',pcmpgtd:'v_cmp(a_, b_, N, 4, 1)',
 pmaxsw:'v_minmax(a_, b_, N, 0)',pminsw:'v_minmax(a_, b_, N, 1)',pmaxub:'v_minmax(a_, b_, N, 2)',pminub:'v_minmax(a_, b_, N, 3)',pavgb:'v_minmax(a_, b_, N, 4)',pavgw:'v_minmax(a_, b_, N, 5)',psadbw:'v_psadbw(a_, b_, N)',
};
const vshift={psllw:[2,0],pslld:[4,0],psllq:[8,0],psrlw:[2,1],psrld:[4,1],psrlq:[8,1],psraw:[2,2],psrad:[4,2]};

export function emitVector(ins,e,decoder) {
 const m=ins.mnemonic,o=ins.operands,{REG,IMM,MEM}=decoder.constants;
 if(m==='emms'||m==='femms')return ';';
 if(!o.length)return null;
 const vreg=op=>{
  if(op.type!==REG)return null;const n=decoder.regName(op.reg);
  if(n.startsWith('xmm'))return [`c->xmm[${n.slice(3)}].b`,16];
  if(n.startsWith('mm'))return [`&c->mm[${n.slice(2)}]`,8];
  return null;
 };
 const load=(op,v,n)=>{const r=vreg(op);return r?`memcpy(${v}, ${r[0]}, ${n});`:`memcpy(${v}, HP(${e.address(op)}), ${n});`;};
 const d=vreg(o[0]);
 if(Object.hasOwn(vbin,m)&&d&&o.length===2) {
  const [dst,n]=d;return `{ uint8_t a_[16], b_[16]; memcpy(a_, ${dst}, ${n}); ${load(o[1],'b_',n)} ${vbin[m].replace('N',String(n))}; memcpy(${dst}, a_, ${n}); }`;
 }
 if(Object.hasOwn(vshift,m)&&d) {
  const [dst,n]=d,[lane,kind]=vshift[m],cnt=o[1].type===IMM?`${BigInt.asUintN(8,o[1].imm)}u`:'cnt_';
  const pre=o[1].type===IMM?'':`uint8_t c8_[16]; ${load(o[1],'c8_',8)} uint64_t cnt_; memcpy(&cnt_, c8_, 8); `;
  return `{ uint8_t a_[16]; ${pre}memcpy(a_, ${dst}, ${n}); v_shift(a_, ${cnt}, ${n}, ${lane}, ${kind}); memcpy(${dst}, a_, ${n}); }`;
 }
 if(['pslldq','psrldq'].includes(m)&&d) {const [dst,n]=d;return `{ uint8_t a_[16]; memcpy(a_, ${dst}, ${n}); v_bshift(a_, ${o[1].imm}u, ${n}, ${Number(m==='pslldq')}); memcpy(${dst}, a_, ${n}); }`;}
 if(['pshufw','pshufd','pshuflw','pshufhw'].includes(m)&&d) {
  const [dst,n]=d,[lane,words,base]={pshufw:[2,4,0],pshufd:[4,4,0],pshuflw:[2,4,0],pshufhw:[2,4,8]}[m];
  return `{ uint8_t a_[16], b_[16]; ${load(o[1],'b_',n)} memcpy(a_, b_, ${n}); v_pshufw(a_, b_, ${o[2].imm}u, ${lane}, ${words}, ${base}); memcpy(${dst}, a_, ${n}); }`;
 }
 if(m==='movd') {
  if(d) {const [dst,n]=d;return `{ uint32_t v_ = ${e.read(o[1],4)}; memset(${dst}, 0, ${n}); memcpy(${dst}, &v_, 4); }`;}
  const src=vreg(o[1]);if(src)return `{ uint32_t v_; memcpy(&v_, ${src[0]}, 4); ${e.write(o[0],'v_',4)} }`;
  return null;
 }
 if(['movq','movntq','movq2dq','movdq2q'].includes(m)) {
  const src=vreg(o[1]);
  if(d) {const [dst,n]=d,loadValue=src?`memcpy(&v_, ${src[0]}, 8);`:`v_ = R64(${e.address(o[1])});`;return `{ uint64_t v_; ${loadValue} memset(${dst}, 0, ${n}); memcpy(${dst}, &v_, 8); }`;}
  if(src&&o[0].type===MEM)return `{ uint64_t v_; memcpy(&v_, ${src[0]}, 8); W64(${e.address(o[0])}, v_); }`;
  return null;
 }
 if(m==='pextrw') {const src=vreg(o[1]);if(src)return `{ uint16_t w_; memcpy(&w_, (uint8_t *)${src[0]} + 2 * (${o[2].imm}u % ${src[1]/2}), 2); ${e.write(o[0],'(uint32_t)w_',4)} }`;}
 if(m==='pinsrw'&&d) {const [dst,n]=d,src=o[1].type===REG?e.read(o[1],4):`R16(${e.address(o[1])})`;return `{ uint16_t w_ = (uint16_t)(${src}); memcpy((uint8_t *)${dst} + 2 * (${o[2].imm}u % ${n/2}), &w_, 2); }`;}
 if(m==='pmovmskb') {const src=vreg(o[1]);if(src)return e.write(o[0],`v_movmskb((const uint8_t *)${src[0]}, ${src[1]})`,4);}
 if((d && decoder.regName(o[0].reg).startsWith('mm')) || (o.length>1 && vreg(o[1])?.[1]===8)) throw new Unsupported(`MMX ${m}`);
 return null;
}
