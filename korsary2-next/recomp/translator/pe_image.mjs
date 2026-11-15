/**
 * Experimental, bounds-checked PE32 reader for the Node recompiler migration.
 * Parses the image, sections, exports, imports and base relocations used by
 * x86toc. This alone is not a complete translator or general PE parser.
 */
import fs from 'node:fs';

const MAX_IMAGE_SIZE = 512 * 1024 * 1024;
const MAX_SECTIONS = 96;
const MAX_TABLE_ENTRIES = 1_000_000;

function bounded(buffer, offset, size, description) {
  if (!Number.isSafeInteger(offset) || !Number.isSafeInteger(size) || offset < 0 || size < 0 || offset > buffer.length - size) {
    throw new Error(`Invalid PE ${description}: out of bounds`);
  }
}
function u16(buffer, offset, description) { bounded(buffer,offset,2,description); return buffer.readUInt16LE(offset); }
function u32(buffer, offset, description) { bounded(buffer,offset,4,description); return buffer.readUInt32LE(offset); }
function cstring(buffer, offset, description) {
  bounded(buffer,offset,1,description);
  const end=buffer.indexOf(0,offset);
  if (end<0 || end-offset>65535) throw new Error(`Invalid PE ${description}: unterminated string`);
  return buffer.subarray(offset,end).toString('utf8');
}
function checkedCount(n, description) {
  if (n>MAX_TABLE_ENTRIES) throw new Error(`Invalid PE ${description}: too many entries`);
  return n;
}

/** Parse a PE32/i386 image without modifying the source Buffer. */
export function parsePeImage(input) {
  if (!Buffer.isBuffer(input)) throw new TypeError('PE input must be a Buffer');
  if (u16(input,0,'DOS header') !== 0x5a4d) throw new Error('Invalid PE DOS signature');
  const pe=u32(input,0x3c,'PE offset');
  if (u32(input,pe,'PE signature') !== 0x00004550) throw new Error('Invalid PE signature');
  const coff=pe+4;
  if (u16(input,coff,'machine') !== 0x14c) throw new Error('Unsupported PE machine: expected x86');
  const sectionCount=u16(input,coff+2,'section count');
  if (!sectionCount || sectionCount>MAX_SECTIONS) throw new Error('Invalid PE section count');
  const optionalSize=u16(input,coff+16,'optional header size');
  const optional=coff+20;
  bounded(input,optional,optionalSize,'optional header');
  if (optionalSize<96 || u16(input,optional,'optional magic')!==0x10b) throw new Error('Unsupported PE optional header: expected PE32');
  const imageBase=u32(input,optional+28,'image base');
  const imageSize=u32(input,optional+56,'image size');
  const headerSize=u32(input,optional+60,'header size');
  const entryPoint=u32(input,optional+16,'entry point');
  if (!imageSize || imageSize>MAX_IMAGE_SIZE || headerSize>imageSize || headerSize>input.length) throw new Error('Invalid PE image/header size');
  const declaredDirectories=u32(input,optional+92,'directory count');
  const directoryCount=Math.min(declaredDirectories,Math.floor((optionalSize-96)/8));
  const directories=[];
  for (let i=0;i<directoryCount;i++) directories.push({rva:u32(input,optional+96+i*8,'directory RVA'),size:u32(input,optional+100+i*8,'directory size')});
  const image=Buffer.alloc(imageSize);
  input.copy(image,0,0,headerSize);
  const sections=[];
  const sectionTable=optional+optionalSize;
  bounded(input,sectionTable,sectionCount*40,'section table');
  for (let i=0;i<sectionCount;i++) {
    const p=sectionTable+i*40;
    const name=input.subarray(p,p+8).toString('utf8').replace(/\0.*$/,'');
    const virtualSize=u32(input,p+8,'section virtual size');
    const virtualAddress=u32(input,p+12,'section RVA');
    const rawSize=u32(input,p+16,'section raw size');
    const rawOffset=u32(input,p+20,'section raw offset');
    if (virtualSize) bounded(image,virtualAddress,virtualSize,'section virtual range');
    if (rawSize) {
      bounded(input,rawOffset,rawSize,'section raw range');
      bounded(image,virtualAddress,rawSize,'section mapped range');
      input.copy(image,virtualAddress,rawOffset,rawOffset+rawSize);
    }
    sections.push({name,virtualAddress,virtualSize,rawOffset,rawSize});
  }
  function directory(index) {
    const d=directories[index];
    if (!d || !d.rva || !d.size) return null;
    bounded(image,d.rva,d.size,`directory ${index}`);
    return d;
  }
  const exports=[];
  const ed=directory(0);
  if (ed) {
    bounded(image,ed.rva,40,'export directory');
    const base=u32(image,ed.rva+16,'export base');
    const functionCount=checkedCount(u32(image,ed.rva+20,'export function count'),'exports');
    const nameCount=checkedCount(u32(image,ed.rva+24,'export name count'),'export names');
    const functions=u32(image,ed.rva+28,'export address table');
    const names=u32(image,ed.rva+32,'export name table');
    const ordinals=u32(image,ed.rva+36,'export ordinal table');
    bounded(image,functions,functionCount*4,'export addresses');
    if (nameCount) { bounded(image,names,nameCount*4,'export names'); bounded(image,ordinals,nameCount*2,'export ordinals'); }
    const named=new Map();
    for(let i=0;i<nameCount;i++) {
      const ord=u16(image,ordinals+i*2,'export ordinal');
      if (ord>=functionCount) throw new Error('Invalid PE export ordinal');
      const name=cstring(image,u32(image,names+i*4,'export name RVA'),'export name');
      if (!named.has(ord)) named.set(ord,[]);
      named.get(ord).push(name);
    }
    for(let i=0;i<functionCount;i++) {
      const address=u32(image,functions+i*4,'export address');
      if (!address) continue;
      const forwarder=address>=ed.rva && address<ed.rva+ed.size ? cstring(image,address,'export forwarder') : null;
      const labels=named.get(i) || [null];
      for(const name of labels) exports.push({name,ordinal:base+i,address,forwarder});
    }
  }
  const imports=[];
  const id=directory(1);
  if (id) {
    // Directory length covers descriptors; some linkers omit the final null
    // descriptor from the advertised length, so permit it within the image.
    for(let i=0;i<MAX_TABLE_ENTRIES;i++) {
      const p=id.rva+i*20;
      bounded(image,p,20,'import descriptor');
      const originalFirstThunk=u32(image,p,'import lookup table');
      const nameRva=u32(image,p+12,'import DLL name');
      const firstThunk=u32(image,p+16,'import address table');
      if (!originalFirstThunk && !nameRva && !firstThunk && !u32(image,p+4,'timestamp') && !u32(image,p+8,'forwarder chain')) break;
      if (!firstThunk || !nameRva) throw new Error('Invalid PE import descriptor');
      const library=cstring(image,nameRva,'import DLL name');
      const thunk=originalFirstThunk || firstThunk;
      const entries=[];
      for(let j=0;j<MAX_TABLE_ENTRIES;j++) {
        const value=u32(image,thunk+j*4,'import thunk');
        if (!value) break;
        const ordinal=value & 0x80000000 ? value & 0xffff : null;
        const name=ordinal===null ? cstring(image,value+2,'import name') : null;
        bounded(image,firstThunk+j*4,4,'import address slot');
        entries.push({name,ordinal,slotRva:firstThunk+j*4});
        if (j===MAX_TABLE_ENTRIES-1) throw new Error('Invalid PE import table: no terminator');
      }
      imports.push({library,firstThunk,entries});
      if (i===MAX_TABLE_ENTRIES-1) throw new Error('Invalid PE imports: no terminator');
    }
  }
  const relocations=[];
  const rd=directory(5);
  if (rd) {
    let cursor=rd.rva, end=rd.rva+rd.size;
    while(cursor<end) {
      if(end-cursor<8) throw new Error('Invalid PE relocation block');
      const page=u32(image,cursor,'relocation page');
      const blockSize=u32(image,cursor+4,'relocation block size');
      if (!page && !blockSize) break;
      if (blockSize<8 || blockSize%2 || blockSize>end-cursor) throw new Error('Invalid PE relocation block size');
      for(let p=cursor+8;p<cursor+blockSize;p+=2) {
        const value=u16(image,p,'relocation entry');
        const type=value>>>12;
        if(type) relocations.push({rva:page+(value&0xfff),type});
      }
      cursor+=blockSize;
    }
  }
  return {imageBase,imageSize,entryPoint,sections,image,exports,imports,relocations};
}
export const readPeImage = file => parsePeImage(fs.readFileSync(file));
