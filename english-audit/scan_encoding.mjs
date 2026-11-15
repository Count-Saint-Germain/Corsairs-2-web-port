#!/usr/bin/env node
/** Count high bytes, string literals, BOMs and UTF-8-like sequences in game texts. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
function* walk(dir){if(!fs.existsSync(dir))return;for(const e of fs.readdirSync(dir,{withFileTypes:true})){const p=path.join(dir,e.name);if(e.isDirectory())yield* walk(p);else if(e.isFile())yield p;}}
export function scanEncoding(root){
 const total=new Map(),inLiteral=new Map(),files=new Map();let utf8seq=0,bom=0,crlf=0,lf=0;
 for(const sub of ['PROGRAM','RESOURCE/INI/TEXTS','RESOURCE/QUESTSTEXT']) for(const p of walk(path.join(root,sub))){
  const bytes=fs.readFileSync(p), text=bytes.toString('latin1'),rel=path.relative(root,p);
  if(bytes.subarray(0,3).equals(Buffer.from([0xef,0xbb,0xbf])))bom++;
  if(text.includes('\r\n'))crlf++;else lf++;
  if(text.includes('\xc3')||text.includes('\xe2'))utf8seq+=(text.match(/[\xc2-\xf4][\x80-\xbf]+/g)||[]).length;
  for(const byte of bytes)if(byte>=128){total.set(byte,(total.get(byte)||0)+1);if(!files.has(byte))files.set(byte,new Set());files.get(byte).add(rel);}
  for(const match of text.matchAll(/"(?:[^"\\\n]|\\.)*"/g))for(const char of match[0]){const byte=char.charCodeAt(0);if(byte>=128)inLiteral.set(byte,(inLiteral.get(byte)||0)+1);}
 }
 return {total,inLiteral,files,utf8seq,bom,crlf,lf};
}
function main(args){if(!args.length||args.includes('--help')){console.log('Usage: node english-audit/scan_encoding.mjs GAME_DIR [--literals-only]');return args.includes('--help')?0:2;}
 const result=scanEncoding(args[0]);console.log(`files CRLF=${result.crlf} LF-only=${result.lf}; UTF-8 BOM files=${result.bom}; UTF-8-like sequences=${result.utf8seq}`);console.log('byte\ttotal\tin_string_literals\tfiles');
 for(const n of [...result.total.keys()].sort((a,b)=>a-b))console.log(`0x${n.toString(16).toUpperCase().padStart(2,'0')}\t${result.total.get(n)}\t${result.inLiteral.get(n)||0}\t${result.files.get(n).size}`);return 0;}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{process.exitCode=main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
