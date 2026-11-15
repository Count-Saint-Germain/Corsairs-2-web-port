/** Operand emission primitives for the x86 static recompiler. */
export class Unsupported extends Error {}
const gp32 = new Set(['eax','ecx','edx','ebx','esp','ebp','esi','edi']);
const gp16 = {ax:'eax',cx:'ecx',dx:'edx',bx:'ebx',sp:'esp',bp:'ebp',si:'esi',di:'edi'};
const gp8l = {al:'eax',cl:'ecx',dl:'edx',bl:'ebx'};
const gp8h = {ah:'eax',ch:'ecx',dh:'edx',bh:'ebx'};
const ut = {1:'uint8_t',2:'uint16_t',4:'uint32_t',8:'uint64_t'};
const bits = {1:8,2:16,4:32};

export class OperandEmitter {
  constructor(decoder) { this.decoder = decoder; }
  regRead(name) {
    if (gp32.has(name)) return `c->${name}`;
    if (Object.hasOwn(gp16,name)) return `((uint16_t)c->${gp16[name]})`;
    if (Object.hasOwn(gp8l,name)) return `((uint8_t)c->${gp8l[name]})`;
    if (Object.hasOwn(gp8h,name)) return `((uint8_t)(c->${gp8h[name]} >> 8))`;
    if (name.startsWith('xmm')) return `c->xmm[${name.slice(3)}]`;
    throw new Unsupported(`register ${name}`);
  }
  regWrite(name, val) {
    if (gp32.has(name)) return `c->${name} = (uint32_t)(${val});`;
    if (Object.hasOwn(gp16,name)) { const r=gp16[name]; return `c->${r} = (c->${r} & 0xffff0000u) | (uint16_t)(${val});`; }
    if (Object.hasOwn(gp8l,name)) { const r=gp8l[name]; return `c->${r} = (c->${r} & 0xffffff00u) | (uint8_t)(${val});`; }
    if (Object.hasOwn(gp8h,name)) { const r=gp8h[name]; return `c->${r} = (c->${r} & 0xffff00ffu) | ((uint32_t)(uint8_t)(${val}) << 8);`; }
    throw new Unsupported(`register write ${name}`);
  }
  address(op) {
    const m=op.mem, parts=[];
    if (m.base) parts.push(this.regRead(this.decoder.regName(m.base)));
    if (m.index) {
      const idx=this.regRead(this.decoder.regName(m.index));
      parts.push(m.scale !== 1 ? `${idx} * ${m.scale}` : idx);
    }
    if (m.disp || !parts.length) parts.push(`0x${BigInt.asUintN(32,BigInt(m.disp)).toString(16)}u`);
    if (m.segment && this.decoder.regName(m.segment) === 'fs') parts.push('c->fs_base');
    return `(uint32_t)(${parts.join(' + ')})`;
  }
  read(op, requestedSize) {
    const size=requestedSize || op.size, {REG,IMM,MEM}=this.decoder.constants;
    if (op.type === REG) return this.regRead(this.decoder.regName(op.reg));
    if (op.type === IMM && ut[size]) return `(${ut[size]})0x${BigInt.asUintN(size*8,BigInt(op.imm)).toString(16)}u`;
    if (op.type === MEM && bits[size]) return `R${bits[size]}(${this.address(op)})`;
    throw new Unsupported('operand');
  }
  write(op, val, requestedSize) {
    const size=requestedSize || op.size, {REG,MEM}=this.decoder.constants;
    if (op.type === REG) return this.regWrite(this.decoder.regName(op.reg),val);
    if (op.type === MEM && bits[size] && ut[size]) return `W${bits[size]}(${this.address(op)}, (${ut[size]})(${val}));`;
    throw new Unsupported('write operand');
  }
  rmw(op, expression) {
    const size=op.size;
    if (op.type === this.decoder.constants.MEM && bits[size] && ut[size]) {
      return `{ uint32_t a_ = ${this.address(op)}; W${bits[size]}(a_, (${ut[size]})(${expression(`R${bits[size]}(a_)`)})); }`;
    }
    return this.write(op,expression(this.read(op)));
  }
}
