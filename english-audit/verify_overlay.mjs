#!/usr/bin/env node
/** Verify emitted overlays preserve code skeletons and literal counts. */
import fs from 'node:fs';import path from 'node:path';import {pathToFileURL} from 'node:url';
import {walkFiles} from './text_utils.mjs';import {scan} from './align_overlay.mjs';
const CYR=/[\xc0-\xff\xa8\xb8]{2,}/;
export function verifyOverlay(ru,emit){const rows=[];let badCode=0,badCount=0,cyrLeft=0,pairs=0,outliers=0;
 for(const file of walkFiles(emit)){const rel=path.relative(emit,file).split(path.sep).join('/'),a=scan(fs.readFileSync(path.join(ru,rel))),b=scan(fs.readFileSync(file));
  const codeOk=JSON.stringify(a.map(x=>x.skel))===JSON.stringify(b.map(x=>x.skel)),left=a.flatMap(x=>x.lits.map(([s,e])=>x.line.slice(s,e))),right=b.flatMap(x=>x.lits.map(([s,e])=>x.line.slice(s,e))),countOk=left.length===right.length;
  if(!codeOk)badCode++;if(!countOk)badCount++;const cyr=right.filter(x=>CYR.test(x)).length;let changed=0,outside=0;
  if(countOk)for(let i=0;i<left.length;i++)if(left[i]!==right[i]&&left[i].length>25){changed++;const ratio=right[i].length/Math.max(left[i].length,1);if(ratio<0.35||ratio>3)outside++;}
  cyrLeft+=cyr;pairs+=changed;outliers+=outside;rows.push([rel,codeOk,countOk,cyr,changed,outside]);
 }
 rows.sort((a,b)=>a[0]<b[0]?-1:a[0]>b[0]?1:0);return {rows,badCode,badCount,cyrLeft,pairs,outliers};}
function main(args){const i=args.indexOf('--out');if(i!==3||!args[i+1])throw Error('Usage: node english-audit/verify_overlay.mjs RU_PROGRAM US_PROGRAM EMIT_DIR --out DIR');const [ru,,emit]=args,out=args[i+1],r=verifyOverlay(ru,emit);fs.mkdirSync(out,{recursive:true});
 fs.writeFileSync(path.join(out,'verify.tsv'),'file\tcode_unchanged\tliteral_count_same\tcyrillic_literals_left\tchanged_pairs_len>25\tlength_ratio_outliers\n'+r.rows.map(row=>row.map(x=>typeof x==='boolean'?(x?'True':'False'):x).join('\t')+'\n').join(''));
 const summary=`files=${r.rows.length} code_changed=${r.badCode} literal_count_changed=${r.badCount} cyrillic_left=${r.cyrLeft} pairs=${r.pairs} ratio_outliers=${r.outliers}\n`;fs.writeFileSync(path.join(out,'summary.txt'),summary);console.log(summary);}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
