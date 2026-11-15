#!/usr/bin/env node
/** Compare script skeletons and literal counts without writing game text. */
import fs from 'node:fs';import path from 'node:path';import {pathToFileURL} from 'node:url';
import {readText,stripComments,literals,walkMap} from './text_utils.mjs';
import {SequenceMatcher} from './sequence_matcher.mjs';
const STR=/"(?:[^"\\\n]|\\.)*"/g,CYR=/[\u0400-\u04ff]/;
function skeleton(text){return text.replace(STR,'""').replace(/\s+/g,' ').trim();}
function splitLines(text){const lines=text.split(/\r\n|[\n\r\v\f\x1c-\x1e\x85\u2028\u2029]/);if(lines.length>1&&lines.at(-1)==='')lines.pop();return lines;}
export function compareScripts(ru,us){const R=walkMap(ru),U=walkMap(us),rows=[],stats=new Map();
 for(const k of [...new Set([...R.keys(),...U.keys()])].sort()){
  const group=k.includes('/')?k.split('/')[0]:'(root)';let cls,extra;
  if(!U.has(k)){cls='RU_ONLY';extra=['','','',''];}else if(!R.has(k)){cls='US_ONLY';extra=['','','',''];}else{
   const rb=fs.readFileSync(R.get(k)[1]),ub=fs.readFileSync(U.get(k)[1]);
   if(rb.equals(ub)){cls='BYTES_EQ';extra=['','','',''];}else{
    const rt=stripComments(readText(R.get(k)[1])),ut=stripComments(readText(U.get(k)[1])),rs=skeleton(rt),usSkeleton=skeleton(ut),rl=literals(rt),ul=literals(ut),cyr=rl.filter(x=>CYR.test(x)).length;
    const ndiff=rl.length===ul.length?rl.reduce((n,x,i)=>n+Number(x!==ul[i]),0):'';let changed;
    if(rs===usSkeleton){cls='TEXT_ONLY';changed=0;}else{cls='CODE_DIFF';const a=splitLines(rt).map(skeleton),b=splitLines(ut).map(skeleton);changed=new SequenceMatcher(a,b,{autojunk:false}).opcodes().filter(op=>op[0]!=='equal').reduce((sum,op)=>sum+Math.max(op[2]-op[1],op[4]-op[3]),0);}
    extra=[rl.length,ul.length,cyr,`${ndiff}/${changed}`];
   }
  }
  rows.push([group,(R.get(k)||U.get(k))[0],cls,...extra]);const key=JSON.stringify([group,cls]);stats.set(key,(stats.get(key)||0)+1);
 }
 return {rows,stats};}
function main(args){const i=args.indexOf('--out');if(i!==2||!args[i+1])throw Error('Usage: node english-audit/compare_scripts.mjs RU_PROGRAM US_PROGRAM --out DIR');const out=args[i+1],r=compareScripts(args[0],args[1]);fs.mkdirSync(out,{recursive:true});
 fs.writeFileSync(path.join(out,'scripts.tsv'),'group\tfile\tclass\tru_literals\tus_literals\tru_cyr_literals\tdiff_literals/changed_skeleton_lines\n'+r.rows.map(row=>row.join('\t')+'\n').join(''));
 const entries=[...r.stats].map(([k,v])=>[...JSON.parse(k),v]).sort((a,b)=>a[0]<b[0]?-1:a[0]>b[0]?1:a[1]<b[1]?-1:a[1]>b[1]?1:0);
 const summary='group\tclass\tfiles\n'+entries.map(e=>e.join('\t')+'\n').join('');fs.writeFileSync(path.join(out,'summary.txt'),summary);console.log(summary);}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
