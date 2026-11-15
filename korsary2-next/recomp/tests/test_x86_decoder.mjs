/** Contract tests for the experimental Capstone 5 WASM x86-32 adapter. */
import test from 'node:test';
import assert from 'node:assert/strict';
import { createX86Decoder } from '../translator/x86_decoder.mjs';

test('x86 operands and relocation encoding match native Capstone 5', async () => {
  const d = await createX86Decoder();
  try {
    const bytes = Buffer.from('55 89e5 8b442410 64a130000000 b878563412 83c0ff 8d548c10 e805000000 7502 90 c3 0f57c0 f30f100c24 d9ee c3'.replaceAll(' ',''), 'hex');
    const ins = d.disasm(bytes, 0x1000);
    assert.deepEqual(ins.map(x => x.mnemonic), ['push','mov','mov','mov','mov','add','lea','call','jne','nop','ret','xorps','movss','fldz','ret']);
    assert.deepEqual(ins.map(x => Number(x.address)), [0x1000,0x1001,0x1003,0x1007,0x100d,0x1012,0x1015,0x1019,0x101e,0x1020,0x1021,0x1022,0x1025,0x102a,0x102c]);
    const normalize = op => {
      if (op.type === d.constants.REG) return ['reg', op.size, d.regName(op.reg)];
      if (op.type === d.constants.IMM) return ['imm', op.size, op.imm];
      if (op.type === d.constants.MEM) return ['mem', op.size, ...['segment','base','index'].map(k => op.mem[k] ? d.regName(op.mem[k]) : null), op.mem.scale, op.mem.disp];
      throw new Error(`Unexpected operand type ${op.type}`);
    };
    assert.deepEqual(ins[2].operands.map(normalize), [['reg',4,'eax'],['mem',4,null,'esp',null,1,16n]]);
    assert.deepEqual(ins[3].operands.map(normalize), [['reg',4,'eax'],['mem',4,'fs',null,null,1,48n]]);
    assert.deepEqual(ins[4].operands.map(normalize), [['reg',4,'eax'],['imm',4,0x12345678n]]);
    assert.deepEqual(ins[5].operands.map(normalize), [['reg',4,'eax'],['imm',4,-1n]]);
    assert.deepEqual(ins[6].operands.map(normalize), [['reg',4,'edx'],['mem',4,null,'esp','ecx',4,16n]]);
    assert.deepEqual(ins[7].operands.map(normalize), [['imm',4,0x1023n]]);
    assert.deepEqual(ins[8].operands.map(normalize), [['imm',4,0x1022n]]);
    assert.deepEqual(ins[11].operands.map(normalize), [['reg',16,'xmm0'],['reg',16,'xmm0']]);
    assert.deepEqual(ins[12].operands.map(normalize), [['reg',16,'xmm1'],['mem',4,null,'esp',null,1,0n]]);
    assert.deepEqual([ins[2].disp_offset,ins[2].disp_size], [3,1]);
    assert.deepEqual([ins[3].disp_offset,ins[3].disp_size], [2,4]);
    assert.deepEqual([ins[4].imm_offset,ins[4].imm_size], [1,4]);
    assert.deepEqual([ins[5].imm_offset,ins[5].imm_size], [2,1]);
    assert.deepEqual([ins[7].imm_offset,ins[7].imm_size], [1,4]);
    assert.deepEqual([ins[8].imm_offset,ins[8].imm_size], [1,1]);
    assert.deepEqual(ins[3].prefix, [0,0x64,0,0]);
    assert.equal(d.disasm(bytes, 0x1000, 1).length, 1);
    assert.deepEqual(d.disasm(Buffer.from([0x0f]), 0x1000), []);
  } finally { d.close(); }
});

test('skip-data mode advances over undecodable bytes without manufacturing operands', async () => {
  const d = await createX86Decoder({skipData:true});
  try {
    const ins = d.disasm(Buffer.from('900f','hex'),0x1000);
    assert.deepEqual(ins.map(x=>x.mnemonic),['nop','.byte']);
    assert.equal(ins[1].op_str,'0x0f');
    assert.deepEqual(ins[1].operands,[]);
    assert.equal(ins[1].size,1);
  } finally {d.close()}
});

test('detail-free skip-data mode supports lightweight instruction statistics', async () => {
  const d = await createX86Decoder({skipData:true,detail:false});
  try {
    const ins = d.disasm(Buffer.from('900f','hex'),0x1000);
    assert.deepEqual(ins.map(x=>x.mnemonic),['nop','.byte']);
    assert.deepEqual(ins.map(x=>x.operands),[[],[]]);
  } finally {d.close()}
});
