/** Regression coverage for the experimental Node operand emitter. */
import test from 'node:test';
import assert from 'node:assert/strict';
import {createX86Decoder} from '../translator/x86_decoder.mjs';
import {OperandEmitter, Unsupported} from '../translator/x86_operands.mjs';

test('register widths preserve neighboring bits and unsupported registers fail', async () => {
  const d=await createX86Decoder();
  try {
    const e=new OperandEmitter(d);
    assert.equal(e.regRead('eax'),'c->eax');
    assert.equal(e.regRead('ax'),'((uint16_t)c->eax)');
    assert.equal(e.regRead('al'),'((uint8_t)c->eax)');
    assert.equal(e.regRead('ah'),'((uint8_t)(c->eax >> 8))');
    assert.equal(e.regRead('xmm7'),'c->xmm[7]');
    assert.equal(e.regWrite('ax','v'),'c->eax = (c->eax & 0xffff0000u) | (uint16_t)(v);');
    assert.equal(e.regWrite('al','v'),'c->eax = (c->eax & 0xffffff00u) | (uint8_t)(v);');
    assert.equal(e.regWrite('ah','v'),'c->eax = (c->eax & 0xffff00ffu) | ((uint32_t)(uint8_t)(v) << 8);');
    assert.throws(() => e.regRead('st0'), Unsupported);
    assert.throws(() => e.regWrite('xmm0','v'), Unsupported);
  } finally { d.close(); }
});

test('real x86 memory, segment, signed immediate and read-modify-write emission', async () => {
  const d=await createX86Decoder();
  try {
    const e=new OperandEmitter(d);
    const ins=d.disasm(Buffer.from('8b44241064a13000000083c0ff8b4c8dfc','hex'),0x1000);
    assert.equal(e.address(ins[0].operands[1]),'(uint32_t)(c->esp + 0x10u)');
    assert.equal(e.read(ins[0].operands[1]),'R32((uint32_t)(c->esp + 0x10u))');
    assert.equal(e.write(ins[0].operands[1],'v'),'W32((uint32_t)(c->esp + 0x10u), (uint32_t)(v));');
    assert.equal(e.address(ins[1].operands[1]),'(uint32_t)(0x30u + c->fs_base)');
    assert.equal(e.read(ins[2].operands[1]),'(uint32_t)0xffffffffu');
    assert.equal(e.address(ins[3].operands[1]),'(uint32_t)(c->ebp + c->ecx * 4 + 0xfffffffcu)');
    assert.equal(e.rmw(ins[0].operands[1],x=>`(${x} + 1)`),'{ uint32_t a_ = (uint32_t)(c->esp + 0x10u); W32(a_, (uint32_t)((R32(a_) + 1))); }');
    assert.equal(e.rmw(ins[0].operands[0],x=>`(${x} + 1)`),'c->eax = (uint32_t)((c->eax + 1));');
  } finally { d.close(); }
});
