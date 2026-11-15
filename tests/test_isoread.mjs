import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {Iso} from '../english-audit/isoread.mjs';
const script=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../english-audit/isoread.mjs');
function rec(name,lba,size,dir=false){
 const bytes=Buffer.isBuffer(name)?name:Buffer.from(name,'latin1');
 const len=33+bytes.length+(bytes.length%2===0?1:0), out=Buffer.alloc(len);
 out[0]=len;out.writeUInt32LE(lba,2);out.writeUInt32BE(lba,6);out.writeUInt32LE(size,10);out.writeUInt32BE(size,14);out[25]=dir?2:0;out[32]=bytes.length;bytes.copy(out,33);return out;
}
function image({joliet=false, raw=0, badName=false}={}) {
 const sector=2048, data=Buffer.alloc(26*sector), directory=20, file=22;
 function descriptor(n,type){const d=data.subarray(n*sector,(n+1)*sector);d[0]=type;d.write('CD001',1);d[6]=1;Buffer.from('TEST DISC').copy(d,40);rec(Buffer.from([0]),directory,sector,true).copy(d,156);return d;}
 descriptor(16,1);
 if(joliet){const d=descriptor(17,2);d.write('%/E',88);descriptor(18,255);} else descriptor(17,255);
 let name=badName?'../escape':joliet?'Тест.txt;1':'HELLO.TXT;1';
 const bytes=joliet?(()=>{const b=Buffer.from(name,'utf16le');b.swap16();return b;})():Buffer.from(name);
 const entries=[rec(Buffer.from([0]),directory,sector,true),rec(Buffer.from([1]),directory,sector,true),rec(bytes,file,6)];
 let offset=directory*sector;for(const e of entries){e.copy(data,offset);offset+=e.length;}
 data.write('hello!',file*sector);
 if(!raw)return data;
 const out=Buffer.alloc(26*2352);for(let i=0;i<26;i++){const at=i*2352;Buffer.from('00ffffffffffffffffffff00','hex').copy(out,at);out[at+15]=raw;data.copy(out,at+(raw===1?16:24),i*sector,(i+1)*sector);}return out;
}
function fixture(t, options){const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-iso-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));const file=path.join(dir,'disc.iso');fs.writeFileSync(file,image(options));return {dir,file};}
for(const [name,opts] of [['ISO9660',{}],['raw Mode 1',{raw:1}],['raw Mode 2',{raw:2}],['Joliet',{joliet:true}]]) test(`reads ${name} names and file bytes`,t=>{
 const {file}=fixture(t,opts),iso=new Iso(file);t.after(()=>iso.close());const name=opts.joliet?'тест.txt':'hello.txt';
 assert.equal(iso.joliet,Boolean(opts.joliet));assert.equal(iso.readFile(iso.lookup(name)).toString(),'hello!');assert.equal([...iso.walk()][0][1],6);assert.equal(iso.lookup('missing'),null);
});
test('extract does not overwrite an existing file',t=>{
 const {file,dir}=fixture(t,{});const out=path.join(dir,'out');fs.mkdirSync(out);fs.writeFileSync(path.join(out,'HELLO.TXT'),'protected');
 const r=spawnSync(process.execPath,[script,file,'extract','hello.txt',out],{encoding:'utf8'});assert.notEqual(r.status,0);assert.equal(fs.readFileSync(path.join(out,'HELLO.TXT'),'utf8'),'protected');
});
test('malformed and truncated images are rejected',t=>{const {file}=fixture(t,{});fs.writeFileSync(file,Buffer.alloc(10));assert.throws(()=>new Iso(file),/no ISO9660/);});
