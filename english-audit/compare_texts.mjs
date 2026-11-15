#!/usr/bin/env node
/** Compare localized INI and quest text keys without writing dialogue contents. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {readText,walkMap} from './text_utils.mjs';
const PLACE=/%[sdfxc]|#[a-z_]+#|\{[\p{L}\p{N}_]+\}/giu;
export function parseText(file){const text=readText(file),entries=new Map(),order=[];const ini=file.toLowerCase().endsWith('.ini');
 const pattern=ini?/^\s*string\s*=\s*([^,]+?)\s*,\s*"(.*)"\s*$/gm:/^\s*([^\s{};]+)\s*\{(.*?)\}/gms;
 for(const m of text.matchAll(pattern)){let key=m[1];if(!ini&&entries.has(key))key+='#dup';entries.set(key,ini?m[2]:m[2].trim());order.push(key);}return {entries,order};}
export function compareSets(label,rootA,rootB){const A=walkMap(rootA),B=walkMap(rootB),rows=[],names=[...new Set([...A.keys(),...B.keys()])].sort(),tot={files:0,same_keys:0,both:0,only_a:0,only_b:0,ph_mismatch:0,len_ratio_hi:0};
 for(const n of names){if(!A.has(n)||!B.has(n)){rows.push([label,n,A.has(n)?'ONLY_A':'ONLY_B','','','','','','']);continue;}
  const a=parseText(A.get(n)[1]),b=parseText(B.get(n)[1]),ka=new Set(a.entries.keys()),kb=new Set(b.entries.keys()),both=[...ka].filter(k=>kb.has(k)),oa=a.order.filter(k=>kb.has(k)),ob=b.order.filter(k=>ka.has(k));let ph=0,hi=0;
  for(const k of both){const x=(a.entries.get(k).match(PLACE)||[]).sort(),y=(b.entries.get(k).match(PLACE)||[]).sort();if(JSON.stringify(x)!==JSON.stringify(y))ph++;const la=Math.max(a.entries.get(k).length,1),lb=b.entries.get(k).length;if(lb/la>1.6&&lb>30)hi++;}
  const onlyA=[...ka].filter(k=>!kb.has(k)).length,onlyB=[...kb].filter(k=>!ka.has(k)).length,equal=onlyA===0&&onlyB===0;
  rows.push([label,n,equal?'SAME_KEYS':'DIFF_KEYS',ka.size,kb.size,onlyA,onlyB,`order=${JSON.stringify(oa)===JSON.stringify(ob)?'same':'diff'}`,`ph_mismatch=${ph};len>1.6=${hi}`]);
  tot.files++;tot.same_keys+=Number(equal);tot.both+=both.length;tot.only_a+=onlyA;tot.only_b+=onlyB;tot.ph_mismatch+=ph;tot.len_ratio_hi+=hi;
 }return {rows,tot};}
export function parseQuests(file){const result=new Set();let quest=null;for(const line of readText(file).split(/\r\n|[\n\r\v\f\x1c-\x1e\x85\u2028\u2029]/)){const s=line.trim();if(s.startsWith('#QUEST')){quest=s.slice(6).trim();result.add(JSON.stringify([quest,0]));}else if(s.startsWith('#TEXT')){const m=s.match(/^#TEXT\s+(\d+)/);result.add(JSON.stringify([quest,m?Number(m[1]):-1]));}}return result;}
function main(args){const i=args.indexOf('--out');if(i!==2||!args[i+1])throw Error('Usage: node english-audit/compare_texts.mjs RU_RESOURCE US_RESOURCE --out DIR');const [ru,us]=args,out=args[i+1];fs.mkdirSync(out,{recursive:true});const text=(r,n)=>path.join(r,'INI','TEXTS',n),sets=[['A:RU/RUSSIAN~US/ENGLISH',text(ru,'RUSSIAN'),text(us,'ENGLISH')],['B:RU/ENGLISH~US/ENGLISH',text(ru,'ENGLISH'),text(us,'ENGLISH')],['C:RU/RUSSIAN~US/RUSSIAN',text(ru,'RUSSIAN'),text(us,'RUSSIAN')]],results=sets.map(([l,a,b])=>[l,compareSets(l,a,b)]);
 fs.writeFileSync(path.join(out,'texts.tsv'),'set\tfile\tstatus\tkeys_a\tkeys_b\tonly_a\tonly_b\torder\tnotes\n'+results.flatMap(([,r])=>r.rows).map(r=>r.join('\t')+'\n').join(''));
 const a=parseQuests(path.join(ru,'QUESTSTEXT','quests_texts.txt')),b=parseQuests(path.join(us,'QUESTSTEXT','quests_texts.txt')),qa=new Set([...a].map(x=>JSON.parse(x)[0])),qb=new Set([...b].map(x=>JSON.parse(x)[0]));
 let summary=results.map(([label,{tot}])=>`${label}\t${Object.entries(tot).map(([k,v])=>`${k}=${v}`).join(' ')}\n`).join('');
 summary+=`QUESTSTEXT\tru_quests=${qa.size} ru_texts=${a.size} us_quests=${qb.size} us_texts=${b.size} common_texts=${[...a].filter(x=>b.has(x)).length} only_ru_quests=${[...qa].filter(x=>!qb.has(x)).length} only_us_quests=${[...qb].filter(x=>!qa.has(x)).length}\n`;
 summary+=`QUESTSTEXT\tonly_ru_quest_names=${[...qa].filter(x=>!qb.has(x)).sort().slice(0,40).join(',')}\nQUESTSTEXT\tonly_us_quest_names=${[...qb].filter(x=>!qa.has(x)).sort().slice(0,40).join(',')}\n`;
 fs.writeFileSync(path.join(out,'summary.txt'),summary);console.log(summary);
}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
