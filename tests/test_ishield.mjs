import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import zlib from 'node:zlib';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {IS} from '../english-audit/ishield.mjs';
const script=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../english-audit/ishield.mjs');
function rec(name,lba,size,dir=false){const n=Buffer.isBuffer(name)?name:Buffer.from(name,'latin1'),len=33+n.length+(n.length%2===0?1:0),r=Buffer.alloc(len);r[0]=len;r.writeUInt32LE(lba,2);r.writeUInt32BE(lba,6);r.writeUInt32LE(size,10);r.writeUInt32BE(size,14);r[25]=dir?2:0;r[32]=n.length;n.copy(r,33);return r;}
function image({compressed=false, badPath=false, invalid=false}={}){
 const payload=Buffer.from('InstallShield fixture content');
 const blob=compressed?zlib.deflateRawSync(payload,{finishFlush:zlib.constants.Z_SYNC_FLUSH}):payload;
 const cab=compressed?Buffer.concat([Buffer.from([blob.length&255,blob.length>>8]),blob]):blob;
 const hdr=Buffer.alloc(1024),cdo=0x40,base=cdo+0x80,entry=base+0x40;
 hdr.writeUInt32LE(0x28635349,0);hdr.writeUInt32LE(0x01006000,4);hdr.writeUInt32LE(cdo,12);
 hdr.writeUInt32LE(0x80,cdo+12);hdr.writeUInt32LE(1,cdo+12+16);hdr.writeUInt32LE(1,cdo+12+28);hdr.writeUInt32LE(0x40,cdo+12+32);
 hdr.writeUInt32LE(0x110,base);hdr.write(badPath?'..\0':'DATA\0',base+0x110);hdr.write('file.txt\0',base+0x120);
 hdr.writeUInt16LE(invalid?8:compressed?4:0,entry);hdr.writeBigUInt64LE(BigInt(payload.length),entry+2);hdr.writeBigUInt64LE(BigInt(cab.length),entry+10);hdr.writeBigUInt64LE(0n,entry+18);hdr.writeUInt32LE(0x120,entry+58);hdr.writeUInt16LE(0,entry+62);hdr.writeUInt16LE(1,entry+85);
 const data=Buffer.alloc(26*2048),pvd=data.subarray(16*2048,17*2048);pvd[0]=1;pvd.write('CD001',1);pvd[6]=1;rec(Buffer.from([0]),20,2048,true).copy(pvd,156);
 const end=data.subarray(17*2048,18*2048);end[0]=255;end.write('CD001',1);end[6]=1;
 let pos=20*2048;for(const e of [rec(Buffer.from([0]),20,2048,true),rec(Buffer.from([1]),20,2048,true),rec('DATA1.HDR;1',22,hdr.length),rec('DATA1.CAB;1',23,cab.length)]){e.copy(data,pos);pos+=e.length;}
 hdr.copy(data,22*2048);cab.copy(data,23*2048);return {data,payload};
}
function fixture(t,options){const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-is-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));const file=path.join(dir,'disc.iso'),{data,payload}=image(options);fs.writeFileSync(file,data);return {dir,file,payload};}
for(const compressed of [false,true])test(`reads ${compressed?'compressed':'uncompressed'} InstallShield entry`,t=>{
 const {file,payload}=fixture(t,{compressed});const archive=new IS([file]);t.after(()=>archive.close());assert.equal(archive.major,6);assert.equal(archive.files.length,1);assert.equal(archive.path(archive.files[0]),'DATA\\file.txt');assert.deepEqual(archive.readFile(archive.files[0]),payload);
});
test('invalid-file flag returns no contents',t=>{const {file}=fixture(t,{invalid:true});const a=new IS([file]);t.after(()=>a.close());assert.equal(a.readFile(a.files[0]).length,0);});
test('rejects extraction paths outside the selected directory',t=>{const {file,dir}=fixture(t,{badPath:true});const out=path.join(dir,'out');const r=spawnSync(process.execPath,[script,'EXTRACT',out,'.*',file],{encoding:'utf8'});assert.notEqual(r.status,0);assert.match(r.stderr,/unsafe archive path/);assert.equal(fs.existsSync(path.join(dir,'file.txt')),false);});
test('rejects unsupported archive signature',t=>{const {file}=fixture(t,{});const b=fs.readFileSync(file);b.writeUInt32LE(0,22*2048);fs.writeFileSync(file,b);assert.throws(()=>new IS([file]),/invalid InstallShield signature/);});
test('repeated extraction keeps identical files and refuses changed files or symlinks',t=>{
 const {file,dir,payload}=fixture(t,{}),out=path.join(dir,'out');
 const run=()=>spawnSync(process.execPath,[script,'EXTRACT',out,'.*',file],{encoding:'utf8'});
 assert.equal(run().status,0);assert.equal(run().status,0);
 const target=path.join(out,'DATA','file.txt');assert.deepEqual(fs.readFileSync(target),payload);
 fs.writeFileSync(target,'protected');const conflict=run();assert.notEqual(conflict.status,0);assert.match(conflict.stderr,/refusing to overwrite/);assert.equal(fs.readFileSync(target,'utf8'),'protected');
 fs.unlinkSync(target);const other=path.join(dir,'other');fs.writeFileSync(other,payload);fs.symlinkSync(other,target);assert.notEqual(run().status,0);assert.deepEqual(fs.readFileSync(other),payload);
});
