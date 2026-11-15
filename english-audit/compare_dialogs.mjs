#!/usr/bin/env node
/** Compare dialogue structure and literal counts without writing dialogue text. */
import fs from 'node:fs';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {readText,stripComments,literals} from './text_utils.mjs';
const STR=/"(?:[^"\\\n]|\\.)*"/g;
export function parseHeader(file){const text=stripComments(readText(file)),m=/DLG_TEXT\s*\[\s*(\d+)\s*\]\s*=\s*\{/.exec(text);if(!m)return null;let body=text.slice(m.index+m[0].length),end=body.indexOf('};');if(end>=0)body=body.slice(0,end);const values=literals(body);return {declared:Number(m[1]),count:values.length,values};}
export function parseCode(file){const text=stripComments(readText(file)),ascii=literals(text).filter(x=>[...x].every(c=>c.codePointAt(0)<128)),skeleton=text.replace(STR,'""').replace(/\s+/g,' '),refs=[...text.matchAll(/DLG_TEXT\s*\[\s*(\d+)\s*\]/g)].map(m=>Number(m[1]));return {skeleton,ascii,refs};}
export function compareDialogs(ru,us){const rd=path.join(ru,'DIALOGS'),ud=path.join(us,'DIALOGS');const listing=d=>new Map(fs.readdirSync(d).map(n=>[n.toLowerCase(),n]));const R=listing(rd),U=listing(ud),bases=[...new Set([...R.keys(),...U.keys()].filter(k=>k.endsWith('.h')).map(k=>k.slice(0,-2)))].sort(),rows=[],stats=new Map();let totalRu=0,totalUs=0;
 for(const base of bases){const rh=R.has(base+'.h')?parseHeader(path.join(rd,R.get(base+'.h'))):null,uh=U.has(base+'.h')?parseHeader(path.join(ud,U.get(base+'.h'))):null,rc=R.has(base+'.c')?parseCode(path.join(rd,R.get(base+'.c'))):null,uc=U.has(base+'.c')?parseCode(path.join(ud,U.get(base+'.c'))):null,nr=rh?.count??0,nu=uh?.count??0;totalRu+=nr;totalUs+=nu;let cls;
  if(!rh)cls='US_ONLY';else if(!uh)cls='RU_ONLY';else if(nr!==nu)cls='COUNT_NE';else if(!rc&&!uc)cls='H_ONLY_EQ';else if(rc&&uc&&rc.skeleton===uc.skeleton)cls=JSON.stringify(rc.ascii)===JSON.stringify(uc.ascii)?'IDENT':'IDENT_LIT';else cls='COUNT_EQ';
  const refs=rc?[...new Set(rc.refs)].sort((a,b)=>a-b):[],inRange=refs.filter(x=>uh&&x<nu).length;
  rows.push([base,nr,nu,rh?.declared??'',uh?.declared??'',refs.length,inRange,rc?.ascii.length??'',uc?.ascii.length??'',cls]);const v=stats.get(cls)||[0,0,0];v[0]++;v[1]+=nr;v[2]+=nu;stats.set(cls,v);
 }
 return {rows,stats,totalRu,totalUs};}
function main(args){const i=args.indexOf('--out');if(i!==2||!args[i+1])throw Error('Usage: node english-audit/compare_dialogs.mjs RU_PROGRAM US_PROGRAM --out DIR');const out=args[i+1],r=compareDialogs(args[0],args[1]);fs.mkdirSync(out,{recursive:true});fs.writeFileSync(path.join(out,'dialogs.tsv'),'file\tru_lines\tus_lines\tru_declared\tus_declared\tru_refs\tru_refs_in_us_range\tru_ascii_lits\tus_ascii_lits\tclass\n'+r.rows.map(row=>row.join('\t')+'\n').join(''));
 const summary='class\tfiles\tru_lines\tus_lines\n'+[...r.stats].sort(([a],[b])=>a<b?-1:a>b?1:0).map(([k,v])=>[k,...v].join('\t')+'\n').join('')+`TOTAL\t${r.rows.length}\t${r.totalRu}\t${r.totalUs}\n`;fs.writeFileSync(path.join(out,'summary.txt'),summary);console.log(summary);}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
