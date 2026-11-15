#!/usr/bin/env node
import fs from 'node:fs';
import path from 'node:path';
const [mode,arg,count]=process.argv.slice(2);
if(mode==='merge'){
  const n=Number(count);if(!Number.isSafeInteger(n)||n<1)throw new Error('Invalid shard count');
  const result={pass:[],nan:[],fp_range:[],fpu_flags:[],fail:[],skip:[]};
  for(let i=0;i<n;i++){const p=path.join(arg,'shard_'+i+'.json'),part=JSON.parse(fs.readFileSync(p,'utf8'));for(const key of Object.keys(result)){if(!Array.isArray(part[key]))throw new Error('Invalid shard '+p);result[key].push(...part[key]);}}
  fs.writeFileSync(path.join(arg,'merged.json'),JSON.stringify(result,null,1));console.log(Object.entries(result).map(([k,v])=>k+'='+v.length).join('  '));
  for(const row of result.fail.sort((a,b)=>a[0].localeCompare(b[0])))console.log('FAIL',...row);
}else if(mode==='failures'){for(const row of JSON.parse(fs.readFileSync(arg,'utf8')).fail)console.log(row[0]);}
else if(mode==='print'){for(const [k,v] of Object.entries(JSON.parse(fs.readFileSync(arg,'utf8'))))for(const row of v)console.log(k,...row);}
else throw new Error('Usage: difftest_reports.mjs merge DIR N | failures FILE | print FILE');
