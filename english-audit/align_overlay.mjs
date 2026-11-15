#!/usr/bin/env node
/** Align localized script literals while retaining the Russian code skeleton. */
import fs from 'node:fs';import path from 'node:path';import {pathToFileURL} from 'node:url';
import {walkMap} from './text_utils.mjs';import {SequenceMatcher} from './sequence_matcher.mjs';
const CYR=/[\xc0-\xff\xa8\xb8]{2,}/,REF=/DLG_TEXT[\x09-\x0d\x20]*\[[\x09-\x0d\x20]*(\d+)[\x09-\x0d\x20]*\]/g;
function splitBytes(value){const text=Buffer.isBuffer(value)?value.toString('latin1'):value,lines=[];let p=0;for(let i=0;i<text.length;i++){if(text[i]==='\r'||text[i]==='\n'){if(text[i]==='\r'&&text[i+1]==='\n')i++;lines.push(text.slice(p,i+1));p=i+1;}}if(p<text.length)lines.push(text.slice(p));return lines;}
export function scan(raw){const lines=splitBytes(raw),out=[];let inBlock=false;
 for(const line of lines){let skel='',lits=[],i=0;while(i<line.length){const c=line[i];
  if(inBlock){const j=line.indexOf('*/',i);if(j<0)i=line.length;else{inBlock=false;i=j+2;}continue;}
  if(c==='"'){let j=i+1;while(j<line.length&&line[j]!=='"'&&line[j]!=='\n'&&line[j]!=='\r')j+=line[j]==='\\'?2:1;if(j<line.length&&line[j]==='"'){lits.push([i,j+1]);skel+='""';i=j+1;}else{skel+=line.slice(i,j);i=j;}}
  else if(line.slice(i,i+2)==='//')i=line.length;else if(line.slice(i,i+2)==='/*'){inBlock=true;i+=2;}else{skel+=c;i++;}}
  out.push({skel:skel.replace(/[\x09-\x0d\x20]+/g,' ').replace(/^ +| +$/g,''),lits,line});}
 return out;}
export function alignLines(a,b,refNorm=false){const key=x=>refNorm?x.skel.replace(REF,'DLG_TEXT[#]'):x.skel,ka=a.map(key),kb=b.map(key),pairs=[];
 for(const [tag,i1,i2,j1,j2] of new SequenceMatcher(ka,kb,{autojunk:false}).opcodes()){
  if(tag==='equal')for(let k=0;k<i2-i1;k++)pairs.push([i1+k,j1+k]);
  else if(tag==='replace'&&i2-i1===j2-j1)for(let k=0;k<i2-i1;k++)if(new SequenceMatcher(ka[i1+k],kb[j1+k]).ratio()>=0.7)pairs.push([i1+k,j1+k]);
 }return pairs;}
export function headerLiterals(raw){const lines=scan(raw),out=[];let started=false;for(const {skel,lits,line} of lines){if(!started){if(/DLG_TEXT[\x09-\x0d\x20]*\[[\x09-\x0d\x20]*\d+[\x09-\x0d\x20]*\][\x09-\x0d\x20]*=[\x09-\x0d\x20]*\{/.test(line))started=true;continue;}if(skel.includes('};'))break;for(const [s,e] of lits)out.push(line.slice(s,e));}return out;}
export function replaceHeader(raw,replacements){let started=false,index=0,out='';for(const {skel,lits,line} of scan(raw)){if(!started){out+=line;if(/DLG_TEXT[\x09-\x0d\x20]*\[[\x09-\x0d\x20]*\d+[\x09-\x0d\x20]*\][\x09-\x0d\x20]*=[\x09-\x0d\x20]*\{/.test(line))started=true;continue;}if(skel.includes('};')){started=false;out+=line;continue;}if(!lits.length){out+=line;continue;}let pos=0;for(const [s,e] of lits){out+=line.slice(pos,s)+(replacements.get(index)??line.slice(s,e));index++;pos=e;}out+=line.slice(pos);}return Buffer.from(out,'latin1');}
function refs(line){return [...line.matchAll(REF)].map(m=>Number(m[1]));}
export function alignOverlay(ru,us,{emit=null}={}){
 const R=walkMap(ru),U=walkMap(us),rows=[],totals={files:0,cyr_total:0,cyr_mapped:0,cyr_unmapped:0,cyr_same_in_us:0,changed_files:0};
 for(const key of [...R.keys()].sort()){
  if(!U.has(key))continue;const [rel,rp]=R.get(key),up=U.get(key)[1],rb=fs.readFileSync(rp),ub=fs.readFileSync(up);if(rb.equals(ub))continue;
  const isHeader=key.startsWith('dialogs/')&&key.endsWith('.h');let newb=rb,mode,cyrTotal=0,cyrMapped=0,unmapped=0,same=0;
  if(isHeader){const rl=headerLiterals(rb),ul=headerLiterals(ub);if(!rl.length)continue;const base=key.slice(0,-2),rc=R.get(base+'.c'),uc=U.get(base+'.c'),mapping=new Map();
   if(rl.length===ul.length){for(let i=0;i<rl.length;i++)mapping.set(i,i);mode='by_index';}
   else if(rc&&uc){const ra=scan(fs.readFileSync(rc[1])),ua=scan(fs.readFileSync(uc[1]));for(const [ia,ib] of alignLines(ra,ua,true)){const a=refs(ra[ia].line),b=refs(ua[ib].line);if(a.length===b.length)for(let i=0;i<a.length;i++)if(!mapping.has(a[i]))mapping.set(a[i],b[i]);}mode='by_c_alignment';}
   else mode='unmapped';
   cyrTotal=rl.filter(x=>CYR.test(x)).length;const valid=new Map([...mapping].filter(([i,j])=>i<rl.length&&j<ul.length)),replacements=new Map([...valid].filter(([i,j])=>rl[i]!==ul[j]).map(([i,j])=>[i,ul[j]]));
   cyrMapped=[...replacements.keys()].filter(i=>CYR.test(rl[i])).length;unmapped=rl.filter((x,i)=>CYR.test(x)&&!valid.has(i)).length;same=[...valid].filter(([i,j])=>CYR.test(rl[i])&&rl[i]===ul[j]).length;
   if(emit&&replacements.size)newb=replaceHeader(rb,replacements);
  }else{
   const ra=scan(rb),ua=scan(ub);cyrTotal=ra.reduce((n,x)=>n+x.lits.filter(([s,e])=>CYR.test(x.line.slice(s,e))).length,0);if(!cyrTotal)continue;
   const mapped=new Set(),edits=new Map();for(const [ia,ib] of alignLines(ra,ua)){
    const la=ra[ia].lits,lb=ua[ib].lits;if(la.length!==lb.length)continue;
    for(let i=0;i<la.length;i++){const [s,e]=la[i],[s2,e2]=lb[i],tr=ra[ia].line.slice(s,e),tu=ua[ib].line.slice(s2,e2);if(CYR.test(tr)){mapped.add(`${ia}:${s}`);if(tr===tu)same++;else{cyrMapped++;if(!edits.has(ia))edits.set(ia,[]);edits.get(ia).push([s,e,tu]);}}}
   }unmapped=cyrTotal-mapped.size;mode='by_line_alignment';
   if(emit&&edits.size){let out='';for(let i=0;i<ra.length;i++){const line=ra[i].line;if(!edits.has(i)){out+=line;continue;}let pos=0;for(const [s,e,text] of edits.get(i).sort((a,b)=>a[0]-b[0])){out+=line.slice(pos,s)+text;pos=e;}out+=line.slice(pos);}newb=Buffer.from(out,'latin1');}
  }
  rows.push([rel,mode,cyrTotal,cyrMapped,unmapped,same]);totals.files++;totals.cyr_total+=cyrTotal;totals.cyr_mapped+=cyrMapped;totals.cyr_unmapped+=unmapped;totals.cyr_same_in_us+=same;
  if(emit&&!newb.equals(rb)){const dst=path.join(emit,rel);fs.mkdirSync(path.dirname(dst),{recursive:true});fs.writeFileSync(dst,newb);totals.changed_files++;}
 }
 return {rows,totals};
}
function main(args){const outIndex=args.indexOf('--out'),emitIndex=args.indexOf('--emit');if(outIndex!==2||!args[outIndex+1])throw Error('Usage: node english-audit/align_overlay.mjs RU_PROGRAM US_PROGRAM --out DIR [--emit DIR]');const out=args[outIndex+1],emit=emitIndex>=0?args[emitIndex+1]:null;if(emitIndex>=0&&!emit)throw Error('missing --emit directory');fs.mkdirSync(out,{recursive:true});const r=alignOverlay(args[0],args[1],{emit});
 fs.writeFileSync(path.join(out,'align.tsv'),'file\tmode\tru_cyrillic_literals\treplaced_by_us\tcyrillic_without_pair\tcyrillic_same_in_us\n'+r.rows.map(row=>row.join('\t')+'\n').join(''));
 const summary=Object.entries(r.totals).map(([k,v])=>`${k}\t${v}\n`).join('');fs.writeFileSync(path.join(out,'summary.txt'),summary);console.log(summary);}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
