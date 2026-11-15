/**
 * x86-32 decoder adapter for the Node static recompiler.
 *
 * @alexaltea/capstone-js 5.0.9 bundles Capstone 5 but its JS Instruction
 * wrapper still reads the older cs_detail layout (x86 offset 80 instead of 96).
 * Decode the pinned WASM32 ABI directly, including encoding offsets used by
 * relocation handling. The pinned adapter is validated against native Capstone.
 */
import createCapstone from '@alexaltea/capstone-js';

const CS_DETAIL_X86 = 96;
const X86_OPERANDS = 72;
const X86_OPERAND_SIZE = 48;
const X86_ENCODING = 456;

/** Create an independent Capstone instance; callers must call close(). */
export async function createX86Decoder({skipData = false, detail: includeDetail = true, registerAccess = false} = {}) {
  const cs = await createCapstone();
  if (cs.version() !== 0x0500) throw new Error('Unsupported Capstone WASM ABI: expected version 5.0');
  const read8 = p => cs.getValue(p, 'i8') & 0xff;
  const read32 = p => cs.getValue(p, 'i32');
  const read64 = p => cs.getValue(p, 'i64');
  // capstone-js's Capstone.disasm invokes Module.Instruction before freeing
  // cs_insn. Override its outdated layout without patching node_modules.
  cs.Instruction = function (ptr, arch) {
    if (arch !== cs.ARCH_X86) throw new Error('x86 decoder used with wrong architecture');
    this.id = read32(ptr);
    this.address = read64(ptr + 8);
    this.size = cs.getValue(ptr + 16, 'i16') & 0xffff;
    this.bytes = Array.from({length: this.size}, (_, i) => read8(ptr + 18 + i));
    this.mnemonic = cs.UTF8ToString(ptr + 42);
    this.op_str = cs.UTF8ToString(ptr + 74);
    const detail = read32(ptr + 236);
    if (!detail && (!includeDetail || (skipData && this.id === 0))) {
      this.prefix = [0, 0, 0, 0]; this.operands = [];
      this.imm_offset = this.imm_size = this.disp_offset = this.disp_size = 0;
      return;
    }
    if (!detail) throw new Error('Capstone x86 detail is missing');
    if (registerAccess) Object.assign(this, engine.regs_access(ptr));
    const x86 = detail + CS_DETAIL_X86;
    this.prefix = Array.from({length: 4}, (_, i) => read8(x86 + i));
    const count = read8(x86 + 64);
    if (count > 8) throw new Error(`Invalid Capstone x86 operand count: ${count}`);
    this.operands = [];
    for (let i = 0; i < count; i++) {
      const p = x86 + X86_OPERANDS + i * X86_OPERAND_SIZE;
      const op = {type: read32(p), size: read8(p + 32), access: read8(p + 33)};
      if (op.type === cs.X86_OP_REG) op.reg = read32(p + 8);
      else if (op.type === cs.X86_OP_IMM) op.imm = read64(p + 8);
      else if (op.type === cs.X86_OP_MEM) op.mem = {
        segment: read32(p + 8), base: read32(p + 12), index: read32(p + 16),
        scale: read32(p + 20), disp: read64(p + 24),
      };
      else throw new Error(`Unknown Capstone x86 operand type: ${op.type}`);
      this.operands.push(op);
    }
    this.imm_offset = read8(x86 + X86_ENCODING + 3);
    this.imm_size = read8(x86 + X86_ENCODING + 4);
    // Capstone 5 leaves imm_size uninitialized for far calls/jumps. The
    // recompiler only treats exactly four-byte values as relocation sites.
    // Values outside the maximum x86 immediate width are never valid.
    if (this.imm_size > 8 || this.mnemonic === 'ljmp' || this.mnemonic === 'lcall') this.imm_size = 0;
    this.disp_offset = read8(x86 + X86_ENCODING + 1);
    this.disp_size = read8(x86 + X86_ENCODING + 2);
  };
  const engine = new cs.Capstone(cs.ARCH_X86, cs.MODE_32);
  if (includeDetail) engine.option(cs.OPT_DETAIL, cs.OPT_ON);
  if (skipData) engine.option(cs.OPT_SKIPDATA, cs.OPT_ON);
  return {
    constants: {REG: cs.X86_OP_REG, IMM: cs.X86_OP_IMM, MEM: cs.X86_OP_MEM},
    regName(reg) { return engine.reg_name(reg); },
    disasm(bytes, address, max = 0) {
      try { return engine.disasm(Array.from(bytes), address, max); }
      catch (err) {
        // The wrapper throws on valid input that decodes to zero instructions;
        // native Capstone's errno remains CS_ERR_OK in this case.
        if (engine.errno() === cs.ERR_OK && String(err).startsWith('Capstone.js: Function cs_disasm failed with code 0:')) return [];
        throw err;
      }
    },
    close() { engine.close(); },
  };
}
