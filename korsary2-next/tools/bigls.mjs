#!/usr/bin/env node
/** List BIGF/BIG4/BIGH archive entries without extracting them. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
export function readBig(file){
 const buffer=fs.readFileSync(file),magic=buffer.subarray(0,4).toString('latin1');
 if(!['BIGF','BIG4','BIGH'].includes(magic))return {magic,entries:null};
 if(buffer.length<16)throw Error('truncated BIG header');
 const count=buffer.readUInt32BE(8),entries=[];let pos=16;
 for(let i=0;i<count;i++){
  if(pos+8>buffer.length)throw Error('truncated BIG entry');
  const offset=buffer.readUInt32BE(pos),size=buffer.readUInt32BE(pos+4);pos+=8;
  const end=buffer.indexOf(0,pos);if(end<0)throw Error('unterminated BIG name');
  const name=buffer.subarray(pos,end).toString('latin1');pos=end+1;
  if(offset+size>buffer.length)throw Error(`BIG entry exceeds archive: ${name}`);
  entries.push({name,offset,size});
 }
 return {magic,entries};
}
export function main(args){for(const file of args){const {magic,entries}=readBig(file);console.log('='.repeat(60));console.log(path.basename(file),`b'${magic}'`);if(!entries)continue;
 const byExt=new Map();for(const e of entries){const ext=path.extname(e.name).toLowerCase()||'(none)',v=byExt.get(ext)||{count:0,size:0};v.count++;v.size+=e.size;byExt.set(ext,v);}
 console.log(`${entries.length} files`);for(const [ext,v] of [...byExt].sort((a,b)=>b[1].size-a[1].size).slice(0,25))console.log(`  ${ext.padEnd(10)} ${String(v.count).padStart(6)} files ${(v.size/1e6).toFixed(1).padStart(9)} MB`);
 if(process.env.SHOW)for(const e of entries.slice(0,Number(process.env.SHOW)))console.log('   ',e.name,e.size);
 }}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
