/** Program and pointer-discovery logic for the x86-to-C recompiler. */
import fs from 'node:fs';
import {readPeImage} from './pe_image.mjs';
import {decodeFunction,toFinal} from './x86_cfg.mjs';

const conditions=new Set(['o','no','b','ae','e','ne','be','a','s','ns','p','np','l','ge','le','g']);
const u32=v=>Number(BigInt.asUintN(32,BigInt(v)));
const sortNum=(a,b)=>a-b;
function bisectRight(a,value) {let lo=0,hi=a.length;while(lo<hi){const mid=(lo+hi)>>>1;if(value<a[mid])hi=mid;else lo=mid+1;}return lo;}

export class Program {
 constructor(pe,data,decoder,{base,tag='recomp'}={}) {
  this.prefBase=pe.imageBase;this.size=pe.imageSize;this.base=base||this.prefBase;this.delta=this.base-this.prefBase;this.tag=tag;this.image=pe.image;this.decoder=decoder;this.trace=false;
  this.secs=new Map(pe.sections.map(s=>[s.name,[this.base+s.virtualAddress,this.base+s.virtualAddress+s.virtualSize]]));
  this.textHi=this.secs.get('.text')?.[1] ?? this.base;
  this.functions=new Map();for(const f of data.functions||[])if(f.ranges?.length){const e=f.entry+this.delta;this.functions.set(e,{...f,entry:e,ranges:f.ranges.map(([a,b])=>[a+this.delta,b+this.delta])});}
  this.entries=new Set(this.functions.keys());this.ghidraEntries=new Set(this.entries);
  this.jumpTables=new Map((data.jumptables||[]).map(j=>[j.at+this.delta,j.targets.map(t=>t+this.delta)]));
  this.relocations=new Set(pe.relocations.map(r=>this.base+r.rva));
  for(const table of pe.imports)for(const item of table.entries)this.relocations.add(this.base+item.slotRva);
  this.exports=[];
  for(const symbol of pe.exports) {
   if(symbol.forwarder!==null)continue;
   const address=this.base+symbol.address,name=symbol.name||null;
   this.exports.push({name,ordinal:symbol.ordinal,address});this.seedEntry(address,`EXPORT_${name||symbol.ordinal}`);
  }
  if(pe.entryPoint)this.seedEntry(this.base+pe.entryPoint,'LOADER_ENTRY');
 }
 static fromFiles(exe,functions,decoder,{base,required=true,tag='recomp'}={}) {
  const pe=readPeImage(exe);let data={functions:[],jumptables:[]};
  if(functions) {
   if(fs.existsSync(functions))data=JSON.parse(fs.readFileSync(functions,'utf8'));
   else if(required)throw new Error(`${functions} is missing: run the Ghidra analysis for this image first`);
   else console.error(`warning: ${functions} missing; ${exe} is translated from its exports and a code scan only`);
  }
  return new Program(pe,data,decoder,{base,tag});
 }
 code(a,b) {return this.image.subarray(a-this.base,b-this.base);}
 toFinal(v) {return toFinal(v,this.prefBase,this.size,this.delta);}
 nextEntry(entry) {
  if(!this._sortedEntries)this._sortedEntries=[...this.ghidraEntries].sort(sortNum);
  const k=bisectRight(this._sortedEntries,entry);
  return k<this._sortedEntries.length?this._sortedEntries[k]:entry;
 }
 seedEntry(address,name) {
  if(this.entries.has(address))return;
  let next=this.nextEntry(address);if(next<=address)next=this.textHi;
  this.functions.set(address,{entry:address,name,ranges:[[address,next]]});this.entries.add(address);
 }
 plausibleEntry(address) {
  const b=this.code(address,address+3);if(!b.length)return false;
  if([0x55,0x56,0x53,0x57,0x6a,0xe9,0xb8,0x81,0x83,0xe8].includes(b[0]))return true;
  return (b[0]===0x8b && b.length>=3 && [0x44,0x4c,0x54,0x5c,0x64,0x74].includes(b[1])) || (b[0]===0x64 && b.length>=2 && b[1]===0xa1);
 }
 addPointerEntries() {
  if(!this.secs.has('.text')){this.pointerEntries=this.gapEntries=0;return;}
  const [tlo,thi]=this.secs.get('.text'),dataSecs=['.rdata','.data','.data1','.idata'].filter(n=>this.secs.has(n)).map(n=>this.secs.get(n));
  const jumpTargets=new Set([...this.jumpTables.values()].flat());
  const plausible=t=>{
   if(!(tlo<=t && t<thi)||this.entries.has(t)||jumpTargets.has(t))return false;
   const previous=this.image[t-this.base-1], previous3=this.image[t-this.base-3];
   return [0xcc,0x90,0xc3].includes(previous) || previous3===0xc2;
  };
  const {IMM,REG}=this.decoder.constants,starts=new Set(),immediates=new Set(),cross=new Set(),orderedG=[...this.entries].sort(sortNum);
  const decode=(a,b,max=0)=>this.decoder.disasm(this.code(a,b),a,max);
  for(const fn of [...this.functions.values()]) {
   const entry=fn.entry,k=bisectRight(orderedG,entry),spanEnd=k<orderedG.length?orderedG[k]:thi;
   for(const [a,b] of fn.ranges)for(const ins of decode(a,b)) {
    starts.add(Number(ins.address));const op=ins.operands.at(-1);
    if(['push','mov','lea'].includes(ins.mnemonic)&&op?.type===IMM)immediates.add(this.toFinal(op.imm));
    if((ins.mnemonic==='jmp'||(ins.mnemonic.startsWith('j')&&conditions.has(ins.mnemonic.slice(1)))) && ins.operands[0]?.type===IMM) {
     const t=this.toFinal(ins.operands[0].imm);if(tlo<=t&&t<thi && !(entry<=t&&t<spanEnd) && !this.entries.has(t))cross.add(t);
    }
   }
  }
  const accept=t=>plausible(t)||(starts.has(t)&&!this.entries.has(t)&&!jumpTargets.has(t));
  const spans=[...this.functions.values()].flatMap(fn=>fn.ranges).sort((a,b)=>a[0]-b[0]||a[1]-b[1]);
  const spanStarts=spans.map(x=>x[0]);
  const unowned=t=>{
   if(!(tlo<=t&&t<thi)||this.entries.has(t))return false;
   const k=bisectRight(spanStarts,t)-1;
   if(k>=0 && spans[k][0]<=t && t<spans[k][1])return false;
   return decode(t,t+32,3).length===3;
  };
  const candidates=new Set([...immediates].filter(accept));for(const t of cross)candidates.add(t);
  for(const [a,b] of dataSecs)for(let va=a;va<b-3;va+=4) {
   const v=this.toFinal(this.image.readUInt32LE(va-this.base));
   if(accept(v)||unowned(v))candidates.add(v);
  }
  const rd=va=>{
   const bytes=this.image.subarray(va-this.base,va-this.base+4);
   let value=0;for(let i=0;i<bytes.length;i++)value+=bytes[i]*(2**(8*i));
   return this.toFinal(value);
  };
  let gaps=0,previousEnd=tlo;
  for(const [a,b] of [...spans,[thi,thi]]) {
   if(a>previousEnd) {
    let g=previousEnd;
    while(g<a && [0xcc,0x90].includes(this.image[g-this.base]))g++;
    while(g+4<=a && tlo<=rd(g) && rd(g)<thi)g+=4;
    while(g<a && [0xcc,0x90].includes(this.image[g-this.base]))g++;
    let paddingStart=a;while(paddingStart>g && [0x00,0xcc].includes(this.image[paddingStart-this.base-1]))paddingStart--;
    if(g<paddingStart && !this.entries.has(g)) {
     const ins=decode(g,a,4);if(ins.length>=3 || (ins.length&&['ret','jmp'].includes(ins.at(-1).mnemonic))){candidates.add(g);gaps++;}
    }
    for(let x=(g+15)&~15;x<a;x+=16) {
     if(x<paddingStart && this.image[x-1-this.base]===0xcc && ![0xcc,0x90].includes(this.image[x-this.base]) && !this.entries.has(x) && !candidates.has(x)) {
      const ins=decode(x,a,4);if(ins.length>=3 || (ins.length&&['ret','jmp'].includes(ins.at(-1).mnemonic))){candidates.add(x);gaps++;}
     }
    }
   }
   previousEnd=Math.max(previousEnd,b);
  }
  this.gapEntries=gaps;
  for(let va=tlo;va<thi-3;va+=4) {
   const v=rd(va);if(!(tlo<=v&&v<thi))continue;
   const inTable=(tlo<=rd(va-4)&&rd(va-4)<thi)||(va+8<=thi&&tlo<=rd(va+4)&&rd(va+4)<thi);
   if(accept(v)||(inTable&&unowned(v)))candidates.add(v);
  }
  const ordered=[...this.entries].sort(sortNum),todo=[...candidates],seen=new Set(candidates);
  for(const fn of [...this.functions.values()])for(const [a,b] of fn.ranges)for(const ins of decode(a,b)) {
   if(ins.mnemonic==='call'&&ins.operands[0]?.type===IMM) {
    const t=this.toFinal(ins.operands[0].imm);if(tlo<=t&&t<thi&&!this.entries.has(t)&&!seen.has(t)){candidates.add(t);seen.add(t);todo.push(t);}
   }
  }
  const seenCand=new Set();
  for(const fn of [...this.functions.values()]) {
   const ranges=[...fn.ranges].sort((a,b)=>a[0]-b[0]||a[1]-b[1]);
   for(let k=0;k<ranges.length-1;k++) {
    const [,b1]=ranges[k],[a2]=ranges[k+1];let a=(b1+15)&~15;
    while(a<a2) {
     let step=0;
     for(const ins of decode(a,Math.min(a2,a+256))) {
      step=ins.size;
      if(ins.mnemonic==='call'&&ins.operands[0]?.type===IMM) {
       const t=this.toFinal(ins.operands[0].imm);
       if(tlo<=t&&t<thi&&!this.entries.has(t)&&!seen.has(t)&&!seenCand.has(t)&&this.plausibleEntry(t)){candidates.add(t);seen.add(t);seenCand.add(t);todo.push(t);}
      }
     }
     a+=step||1;
    }
   }
  }
  for(const fn of [...this.functions.values()]) {
   if(fn.ranges.length<2)continue;
   for(const ins of decodeFunction(this,fn)) {
    if(ins.mnemonic!=='call'||ins.operands[0]?.type!==IMM)continue;
    const t=u32(ins.operands[0].imm);
    if(tlo<=t&&t<thi&&!this.entries.has(t)&&!seen.has(t)){candidates.add(t);seen.add(t);todo.push(t);}
   }
  }
  while(todo.length) {
   const entry=todo.pop(),k=bisectRight(ordered,entry),spanEnd=k<ordered.length?ordered[k]:thi;
   for(const ins of decode(entry,spanEnd)) {
    const m=ins.mnemonic,last=ins.operands.at(-1),first=ins.operands[0];
    if(['push','mov','lea'].includes(m)&&last?.type===IMM) {
     const v=this.toFinal(last.imm);
     if(tlo<=v&&v<thi&&!this.entries.has(v)&&!seen.has(v)&&!jumpTargets.has(v) && decode(v,v+16,1).length) {candidates.add(v);seen.add(v);todo.push(v);}
    }
    if((m==='jmp'||m==='call'||(m.startsWith('j')&&conditions.has(m.slice(1))))&&first?.type===IMM) {
     const t=this.toFinal(first.imm),outside=!(entry<=t&&t<spanEnd)||m==='call';
     if(tlo<=t&&t<thi&&outside&&!this.entries.has(t)&&!seen.has(t)){candidates.add(t);seen.add(t);todo.push(t);}
    }
    if(['ret','retn','jmp','int3'].includes(m))break;
   }
   for(const ins of decodeFunction(this,{entry,ranges:[[entry,spanEnd]]})) {
    const last=ins.operands.at(-1);if(!last||last.type!==IMM)continue;
    const t=u32(last.imm);if(this.entries.has(t)||seen.has(t))continue;
    const relocated=ins.imm_size===4 && this.relocations.has(Number(ins.address)+ins.imm_offset);
    const masked=ins.mnemonic==='and'&&ins.operands.length===2&&ins.operands[0].type===REG;
    if((['push','mov','lea'].includes(ins.mnemonic)||masked)&&relocated&&tlo<=t&&t<thi&&!jumpTargets.has(t)&&(accept(t)||unowned(t))) {candidates.add(t);seen.add(t);todo.push(t);}
    else if(ins.mnemonic==='call'&&tlo<=t&&t<thi){candidates.add(t);seen.add(t);todo.push(t);}
   }
  }
  const all=[...new Set([...this.entries,...candidates])].sort(sortNum);
  for(const t of candidates) {
   const k=bisectRight(all,t),next=k<all.length?all[k]:thi;
   this.functions.set(t,{entry:t,name:`PTR_${t.toString(16).padStart(8,'0')}`,ranges:[[t,next]]});
  }
  for(const t of candidates)this.entries.add(t);
  this.pointerEntries=candidates.size;
 }
 directCallees(fn) {
  const out=new Set(),{IMM,MEM}=this.decoder.constants;
  for(const [a,b] of fn.ranges)for(const ins of this.decoder.disasm(this.code(a,b),a))for(const op of ins.operands) {
   const value=op.type===IMM?op.imm:op.type===MEM?BigInt(u32(op.mem.disp)):null;
   if(value!==null){const v=this.toFinal(value);if(this.entries.has(v)&&v!==fn.entry)out.add(v);}
  }
  return out;
 }
 closure(roots) {
  const todo=[...roots],seen=new Set();while(todo.length){const e=todo.pop();if(seen.has(e)||!this.functions.has(e))continue;seen.add(e);todo.push(...this.directCallees(this.functions.get(e)));}return seen;
 }
}
