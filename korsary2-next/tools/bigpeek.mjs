#!/usr/bin/env node
/** Preview representative BIG archive entries without writing extracted files. */
import fs from 'node:fs';
import path from 'node:path';
import {readBig} from './bigls.mjs';
const args=process.argv.slice(2),file=args.at(-1);
if(!file){console.error('Usage: node bigpeek.mjs [legacy-tools-dir] FILE');process.exitCode=2;}
else try {
 const {entries}=readBig(file);if(!entries)throw Error('not a BIG archive');const fd=fs.openSync(file,'r');
 try{for(const ext of ['o','exe','dff','txd','xml','fsh','big','ffn','english','bvh','ash','rsg']){
  console.log(`\\.${ext}$`);
  for(const e of entries.filter(x=>x.name.toLowerCase().endsWith(`.${ext}`)).slice(0,3)){
   const buf=Buffer.alloc(Math.min(48, fs.fstatSync(fd).size-e.offset));fs.readSync(fd,buf,0,buf.length,e.offset);
   const hex=[...buf.subarray(0,16)].map(n=>n.toString(16).padStart(2,'0')).join(' ');
   const display=[...buf].map(n=>n===10?'\\n':n===13?'\\r':n===9?'\\t':n===92?'\\\\':n>=32&&n<=126?String.fromCharCode(n):`\\x${n.toString(16).padStart(2,'0')}`).join('').slice(0,60);
   console.log(`  ${e.name} (${e.size} B): ${hex} | ${display}`);
  }
 }}finally{fs.closeSync(fd);}
}catch(e){console.error(e.message);process.exitCode=1;}
