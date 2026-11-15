#!/usr/bin/env node
/** Align quest text blocks by (quest, #TEXT number), preserving source bytes. */
import fs from 'node:fs';import path from 'node:path';import {pathToFileURL} from 'node:url';
const trimBytes=s=>s.replace(/^[\x09-\x0d\x20]+|[\x09-\x0d\x20]+$/g,'');
export function parseQuests(file){const raw=fs.readFileSync(file).toString('latin1'),lines=raw.split('\n'),records=[];let cur=null,quest=null;
 for(const line of lines){const s=line.replace(/\r+$/,'');if(s.startsWith('#QUEST')){quest=trimBytes(s.slice(6));cur={kind:'Q',quest,n:0,lines:[]};records.push(cur);}
  else if(s.startsWith('#TEXT')){const m=/^#TEXT[\x09-\x0d\x20]+(\d+)/.exec(s);if(!m)throw Error('invalid #TEXT marker');cur={kind:'T',quest,n:Number(m[1]),lines:[]};records.push(cur);}
  else if(cur===null){cur={kind:'H',quest:null,n:0,lines:[line]};records.push(cur);}else cur.lines.push(line);
 }return {records,raw};}
export function overlayQuests(ru,us){const a=parseQuests(ru).records,b=parseQuests(us).records,usMap=new Map(b.filter(r=>r.kind==='Q'||r.kind==='T').map(r=>[JSON.stringify([r.quest,r.n]),r]));let replaced=0,unmapped=0,multiline=0,placeholders=0,ruRecords=0;const out=[];
 for(const original of a){let r=original;if(r.kind==='Q'||r.kind==='T'){ruRecords++;if(r.lines.filter(x=>trimBytes(x)).length>1)multiline++;const match=usMap.get(JSON.stringify([r.quest,r.n]));
  if(match){const x=r.lines.join('\n').match(/%[A-Za-z0-9_]/g)||[],y=match.lines.join('\n').match(/%[A-Za-z0-9_]/g)||[];if(JSON.stringify(x)!==JSON.stringify(y))placeholders++;r={...r,lines:match.lines};replaced++;}else unmapped++;}
  out.push(r);
 }
 const lines=[];for(const r of out){if(r.kind==='Q')lines.push(`#QUEST\t${r.quest}`);else if(r.kind==='T')lines.push(`#TEXT\t${r.n}`);lines.push(...r.lines);}
 return {ruRecords,replaced,unmapped,multiline,placeholders,bytes:Buffer.from(lines.join('\n'),'latin1')};}
function main(args){if(args.length<2||args.includes('--help')){console.log('Usage: node english-audit/overlay_quests.mjs RU_QUESTS US_QUESTS [--emit FILE]');return args.includes('--help')?0:2;}
 const r=overlayQuests(args[0],args[1]);console.log(`RU records: ${r.ruRecords}, replaced by US: ${r.replaced}, no pair (stay Russian): ${r.unmapped}, multi-line RU blocks: ${r.multiline}, placeholder mismatches: ${r.placeholders}`);
 const i=args.indexOf('--emit');if(i>=0){if(!args[i+1])throw Error('missing --emit file');fs.writeFileSync(args[i+1],r.bytes);}return 0;}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{process.exitCode=main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
