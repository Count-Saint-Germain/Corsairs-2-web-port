/** x86 control-flow and relocation primitives for the static recompiler. */
const cond = new Set(['o','no','b','ae','e','ne','be','a','s','ns','p','np','l','ge','le','g']);
const terminators = new Set(['jmp','ret','retn','int3','hlt','ud2']);
const prefixes = new Set([0xf2,0xf3,0x2e,0x36,0x3e,0x26,0x64,0x65,0x66,0x67]);
const uint32 = v => Number(BigInt.asUintN(32, BigInt(v)));

export function toFinal(value, preferredBase, imageSize, delta) {
  const v=uint32(value);
  return preferredBase<=v && v<preferredBase+imageSize ? v+delta : v;
}

/** Relocate only encoded dwords whose exact position is in the relocation set. */
export function shiftInstructionOperands(ins, relocationAddresses, delta, constants) {
  for (let off=0;off<ins.size-3;off++) {
    if (!relocationAddresses.has(Number(ins.address)+off)) continue;
    const value=Buffer.from(ins.bytes.slice(off,off+4)).readUInt32LE();
    for (const op of ins.operands) {
      if (op.type===constants.IMM && uint32(op.imm)===value) { op.imm+=BigInt(delta); break; }
      if (op.type===constants.MEM && uint32(op.mem.disp)===value) { op.mem.disp+=BigInt(delta); break; }
    }
  }
}

export const isTerminator = ins => terminators.has(ins.mnemonic);
export function isLocked(ins, constants) {
  for (const b of ins.bytes) {
    if (b===0xf0) return true;
    if (!prefixes.has(b)) break;
  }
  return ins.mnemonic==='xchg' && ins.operands.some(op=>op.type===constants.MEM);
}

/** Recover in-function targets of `jmp [index*4 + table]`, at most 512. */
export function recoverJumpTable(program, op, inside) {
  const {MEM}=program.decoder.constants;
  if(op.type!==MEM || op.mem.scale!==4 || op.mem.base || !op.mem.index) return [];
  const table=uint32(op.mem.disp), found=[];
  for(let k=0;k<512;k++) {
    const offset=table+4*k-program.base;
    if(offset<0 || offset+4>program.image.length) break;
    const target=program.toFinal(program.image.readUInt32LE(offset));
    if(!inside(target)) break;
    found.push(target);
  }
  return found;
}

/** Decode a function's reachable blocks, including backward and jump-table branches. */
export function decodeFunction(program, fn) {
  if (!fn.ranges?.length) return [];
  const entry=Number(fn.entry);
  const lo=Math.min(...fn.ranges.map(([a])=>a));
  const hi=Math.max(...fn.ranges.map(([,b])=>b),program.nextEntry(entry));
  const inside=t=>lo<=t && t<hi && (t===entry || !program.ghidraEntries.has(t));
  const seen=new Map(), todo=[entry], {IMM}=program.decoder.constants;
  while(todo.length) {
    let address=todo.pop();
    while(!seen.has(address) && inside(address)) {
      const ins=program.decoder.disasm(program.code(address,address+16),address,1)[0];
      if(!ins) break;
      if(program.delta) shiftInstructionOperands(ins,program.relocations,program.delta,program.decoder.constants);
      seen.set(address,ins);
      const m=ins.mnemonic, op=ins.operands[0];
      const direct=m==='jmp' || (m.startsWith('j') && cond.has(m.slice(1))) || ['jecxz','jcxz','loop'].includes(m);
      if(direct && op && op.type===IMM && inside(Number(op.imm))) todo.push(Number(op.imm));
      if(m==='jmp' && op && op.type!==IMM) {
        const known=program.jumpTables.get(address) || [];
        const found=[...new Set([...known,...recoverJumpTable(program,op,inside)])].sort((a,b)=>a-b);
        if(found.length) program.jumpTables.set(address,found);
        todo.push(...(program.jumpTables.get(address) || []).filter(inside));
      }
      if(isTerminator(ins)) break;
      address+=ins.size;
    }
  }
  return [...seen.values()].sort((a,b)=>Number(a.address-b.address));
}
