/** Shared read-only helpers for audits of legacy CP1251 game text. */
import fs from 'node:fs';
import path from 'node:path';
const decoder=new TextDecoder('windows-1251');
export function decode1251(bytes){return decoder.decode(bytes).replace(/\u0098/g,'\ufffd');}
export function readText(file){return decode1251(fs.readFileSync(file));}
export function* walkFiles(root){if(!fs.existsSync(root))return;for(const e of fs.readdirSync(root,{withFileTypes:true})){const full=path.join(root,e.name);if(e.isDirectory())yield* walkFiles(full);else if(e.isFile()||e.isSymbolicLink())yield full;}}
export function walkMap(root){const out=new Map();for(const p of walkFiles(root)){const rel=path.relative(root,p).split(path.sep).join('/');out.set(rel.toLowerCase(),[rel,p]);}return out;}
export function stripComments(text){let out='',i=0;while(i<text.length){const c=text[i];if(c==='"'){let j=i+1;while(j<text.length&&text[j]!=='"'&&text[j]!=='\n')j+=text[j]==='\\'?2:1;out+=text.slice(i,j+1);i=j+1;}else if(c==='/'&&text[i+1]==='/'){while(i<text.length&&text[i]!=='\n')i++;}else if(c==='/'&&text[i+1]==='*'){const j=text.indexOf('*/',i+2);i=j<0?text.length:j+2;}else{out+=c;i++;}}return out;}
export function literals(text){return [...text.matchAll(/"(?:[^"\\\n]|\\.)*"/g)].map(m=>m[0]);}
