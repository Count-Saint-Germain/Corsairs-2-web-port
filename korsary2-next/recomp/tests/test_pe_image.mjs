/** Regression tests for the experimental PE32 reader. */
import test from 'node:test';
import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {parsePeImage, readPeImage} from '../translator/pe_image.mjs';

function fixture() {
  const b=Buffer.alloc(0x600), p=0x80, opt=p+24, sec=opt+224;
  b.writeUInt16LE(0x5a4d,0); b.writeUInt32LE(p,0x3c); b.writeUInt32LE(0x4550,p);
  b.writeUInt16LE(0x14c,p+4); b.writeUInt16LE(1,p+6); b.writeUInt16LE(224,p+20);
  b.writeUInt16LE(0x10b,opt); b.writeUInt32LE(0x1300,opt+16); b.writeUInt32LE(0x400000,opt+28);
  b.writeUInt32LE(0x2000,opt+56); b.writeUInt32LE(0x200,opt+60); b.writeUInt32LE(16,opt+92);
  const dir=(i,rva,size) => {b.writeUInt32LE(rva,opt+96+i*8);b.writeUInt32LE(size,opt+100+i*8)};
  dir(0,0x1000,0x100); dir(1,0x1100,40); dir(5,0x1200,12);
  b.write('.text',sec); b.writeUInt32LE(0x400,sec+8);b.writeUInt32LE(0x1000,sec+12);
  b.writeUInt32LE(0x400,sec+16);b.writeUInt32LE(0x200,sec+20);
  const o=rva=>0x200+rva-0x1000;
  b.writeUInt32LE(1,o(0x1010));b.writeUInt32LE(2,o(0x1014));b.writeUInt32LE(1,o(0x1018));
  b.writeUInt32LE(0x1040,o(0x101c));b.writeUInt32LE(0x1048,o(0x1020));b.writeUInt32LE(0x104c,o(0x1024));
  b.writeUInt32LE(0x1300,o(0x1040));b.writeUInt32LE(0x1060,o(0x1044));
  b.writeUInt32LE(0x1050,o(0x1048));b.writeUInt16LE(0,o(0x104c));b.write('Exported\0',o(0x1050));b.write('OTHER.Target\0',o(0x1060));
  b.writeUInt32LE(0x1170,o(0x1100));b.writeUInt32LE(0x1160,o(0x110c));b.writeUInt32LE(0x1180,o(0x1110));
  b.write('LIB.dll\0',o(0x1160));b.writeUInt32LE(0x1190,o(0x1170));b.writeUInt32LE(0x80000005,o(0x1174));
  b.writeUInt16LE(0,o(0x1190));b.write('Imported\0',o(0x1192));
  b.writeUInt32LE(0x1000,o(0x1200));b.writeUInt32LE(12,o(0x1204));b.writeUInt16LE(0x3004,o(0x1208));
  return b;
}

test('maps sections, named and forwarded exports, name/ordinal imports and relocations',()=>{
  const input=fixture(), snapshot=Buffer.from(input), p=parsePeImage(input);
  assert.deepEqual(input,snapshot);
  assert.equal(p.imageBase,0x400000);assert.equal(p.imageSize,0x2000);assert.equal(p.entryPoint,0x1300);
  assert.deepEqual(p.sections,[{name:'.text',virtualAddress:0x1000,virtualSize:0x400,rawOffset:0x200,rawSize:0x400}]);
  assert.deepEqual(p.exports,[{name:'Exported',ordinal:1,address:0x1300,forwarder:null},{name:null,ordinal:2,address:0x1060,forwarder:'OTHER.Target'}]);
  assert.deepEqual(p.imports,[{library:'LIB.dll',firstThunk:0x1180,entries:[{name:'Imported',ordinal:null,slotRva:0x1180},{name:null,ordinal:5,slotRva:0x1184}]}]);
  assert.deepEqual(p.relocations,[{rva:0x1004,type:3}]);
  assert.deepEqual(p.image.subarray(0x1000,0x1400),input.subarray(0x200,0x600));
});

test('rejects malformed and unsupported inputs without unsafe reads',()=>{
  for(const mutate of [
    b=>b.writeUInt16LE(0,0), b=>b.writeUInt32LE(0xfffffffe,0x3c), b=>b.writeUInt16LE(0x8664,0x84),
    b=>b.writeUInt32LE(0xffffffff,0x80+24+56), b=>b.writeUInt32LE(0xffffffff,0x178+20),
    b=>b.writeUInt32LE(0xffffffff,0x80+24+96+5*8), b=>b.writeUInt32LE(3,0x200+0x200+4),
  ]) { const b=fixture();mutate(b);assert.throws(()=>parsePeImage(b)); }
  const short=Buffer.alloc(8); short.writeUInt16LE(0x5a4d,0);
  assert.throws(()=>parsePeImage(short),/out of bounds/);
  assert.throws(()=>parsePeImage('not a buffer'),/Buffer/);
});

const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)), '../../../korsary2-work/game');
for(const [name,base,size,entry,sectionCount,exportCount,importCount,relocCount,hash] of [
  ['ENGINE.exe',4194304,1269760,326024,5,0,7,8667,'abfe5ce2c5d6c469857531317974a142e0b61b0b503d6d5e8235d5f33d126951'],
  ['MODULES/DX8RENDER.dll',268435456,290816,130196,5,1,5,5111,'5d487612b561455d9f7bcc7155cf0af64f49a01555541c3c9a526a48fa727a63'],
]) {
  const file=path.join(root,name);
  test(`real image parity: ${name}`,{skip:!fs.existsSync(file)},()=>{
    const p=readPeImage(file);
    assert.deepEqual([p.imageBase,p.imageSize,p.entryPoint,p.sections.length,p.exports.length,p.imports.length,p.relocations.length],
      [base,size,entry,sectionCount,exportCount,importCount,relocCount]);
    assert.equal(createHash('sha256').update(p.image).digest('hex'),hash);
  });
}
