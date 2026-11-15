#!/usr/bin/env node
// Headless guest-heap scenario runner and log summarizer. Run with --help for options.
import { createWriteStream, mkdirSync, readFileSync, writeFileSync } from 'node:fs';
import { resolve } from 'node:path';
import { spawn } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { once } from 'node:events';
export function buildInput(scn, frames, period, skipSave = false) {
  let ev = skipSave && scn === 'reload' ? [[300,'key=1c'],[600,'key=1c'],[900,'key=1c'],[1200,'key=cd'],[1500,'key=1c']] : [[300,'key=1c'], ...[700,760,840,920,1000,1080,1160,1240,1320,1400,1480,1560].map(f => [f,'key=39'])];
  if (scn === 'wander') {
    const sticks = ['0:-32768','20000:-20000','0:0','-20000:-20000','0:32768','-32768:0','0:0'], cams = ['40:0','-40:10','0:-20','-30:0'];
    for (let f=2000,i=0; f<frames; f+=240,i++) ev.push([f,'stick='+sticks[i%sticks.length]],[f+100,'move='+cams[i%cams.length]]);
    ev.push([frames,'stick=0:0']);
  } else if (scn === 'reload') {
    if (!skipSave) ev.push([2600,'key=3b'],[2800,'key=d0'],[3000,'key=d0'],[3200,'key=1c'],[3800,'key=1c'],[4200,'key=1c'],[4800,'key=01'],[5400,'key=01']);
    if (period <= 0) throw new Error('--period must be positive');
    for(let f=skipSave?4000:7000; f+1800<frames; f+=period) ev.push([f,'key=3b'],[f+300,'key=1c'],[f+600,'key=1c'],[f+900,'key=1c'],[f+1200,'key=cd'],[f+1500,'key=1c']);
  } else if (scn !== 'idle') throw new Error('unknown scenario '+scn);
  ev.sort((a,b)=>a[0]-b[0] || (a[1] < b[1] ? -1 : a[1] > b[1] ? 1 : 0));
  const seen = new Map(); for (let [f,a] of ev) { while(seen.has(f)) f++; seen.set(f,a); }
  return [...seen].sort((a,b)=>a[0]-b[0]).map(([f,a])=>`${f}:${a}`).join(',');
}
const patterns = {
 fps: /^\[fps\] ([\d.]+)\s+\(frame (\d+),/,
 hs: /^\[heapstats\] extent=(\d+) KB \(high-water (\d+) KB\) live=(\d+) blocks (\d+) KB \(requested (\d+) KB, high-water (\d+) KB\) free-inside=(\d+) blocks (\d+) KB largest-free=(\d+) KB bad=(\d+)/,
 ds: /^\[dsstats\] buffers=(\d+) \(high-water (\d+)\) secondary=(\d+) playing=(\d+) pcm-storages=(\d+) pcm=(\d+) KB \(high-water (\d+) KB\)/,
 d3d: /^\[d3dstats\] surfaces=(\d+) \(own memory (\d+), (\d+) KB\) textures=(\d+) \((\d+) KB\) vertex\/index buffers=(\d+) \((\d+) KB\)/,
 com: /^\[comstats\] live=(\d+) \(high-water (\d+)\) slots-used=(\d+)/,
};
export function summarize(content, csvPath) {
 let rows=[], frame=0, fps=0, cur;
 for(const line of content.split(/\r?\n/)) {
  let m; if((m=patterns.fps.exec(line))) { fps=+m[1]; frame=+m[2]; continue; }
  if((m=patterns.hs.exec(line))) { const g=m.slice(1).map(Number); cur={frame,fps,extent:g[0],live_blocks:g[2],live:g[3],free_blocks:g[6],free:g[7],largest:g[8],bad:g[9]}; rows.push(cur); continue; }
  if(!cur) continue;
  if((m=patterns.ds.exec(line))) { const g=m.slice(1).map(Number); Object.assign(cur,{ds_buffers:g[0],ds_secondary:g[2],ds_storages:g[4],ds_pcm:g[5]}); continue; }
  if((m=patterns.d3d.exec(line))) { const g=m.slice(1).map(Number); Object.assign(cur,{d3d_surfaces:g[0],d3d_surf_kb:g[2],d3d_textures:g[3],d3d_tex_kb:g[4],d3d_buffers:g[5],d3d_buf_kb:g[6]}); continue; }
  if((m=patterns.com.exec(line))) Object.assign(cur,{com_live:+m[1],com_slots:+m[3]});
 }
 if(csvPath && rows.length) { const keys=[...new Set(rows.flatMap(Object.keys))]; writeFileSync(csvPath,keys.join(',')+'\n'+rows.map(r=>keys.map(k=>k==='fps' && Number.isInteger(r[k]) ? r[k].toFixed(1) : r[k]??'').join(',')).join('\n')+'\n'); }
 return rows;
}
export function printTable(rows,n=14) {
 if(!rows.length) { console.log('нет строк [heapstats]'); return; }
 const step=Math.max(1,Math.floor(rows.length/n)), pick=rows.filter((_,i)=>i%step===0); if(pick.at(-1)!==rows.at(-1)) pick.push(rows.at(-1));
 const cols=[['frame',8,'frame'],['extentKB',9,'extent'],['liveKB',8,'live'],['blocks',7,'live_blocks'],['freeKB',7,'free'],['fblk',5,'free_blocks'],['maxfreeKB',9,'largest'],['dsbuf',5,'ds_buffers'],['dsPCM',6,'ds_pcm'],['texKB',7,'d3d_tex_kb'],['bufKB',6,'d3d_buf_kb'],['surfKB',6,'d3d_surf_kb'],['com',5,'com_live'],['fps',6,'fps']];
 console.log(cols.map(([s,w])=>s.padStart(w)).join(' '));
 for(const r of pick) console.log(cols.map(([,w,k])=>String(k==='fps'?r[k].toFixed(1):r[k]??'').padStart(w)).join(' '));
 const a=rows[0],b=rows.at(-1), max=k=>Math.max(...rows.map(r=>r[k]));
 console.log(`\nпервая -> последняя точка: live ${a.live} -> ${b.live} KB, extent ${a.extent} -> ${b.extent} KB, blocks ${a.live_blocks} -> ${b.live_blocks}, free-inside ${a.free} -> ${b.free} KB; max extent ${max('extent')} KB, max live ${max('live')} KB, bad=${max('bad')}`);
}
async function main() {
 const a={scenario:'wander',frames:20000,'max-seconds':3600,period:4000};
 const args=process.argv.slice(2);
 for(let i=0;i<args.length;i++) { let [key,val]=args[i].split(/=(.*)/s,2); if(key==='--help') { console.log('Usage: heap_scenario.mjs --summarize LOG [--csv FILE] | --node-js FILE --game COPY --userdata DIR --log FILE [--scenario idle|wander|reload] [--frames N] [--period N] [--max-seconds N] [--nopace[=FRAME]] [--skip-save]'); return; }
  if(!key.startsWith('--')) throw new Error('unknown argument '+key); key=key.slice(2);
  if(key==='skip-save') a[key]=true; else if(key==='nopace') a[key]=val??(args[i+1]&&!args[i+1].startsWith('--')?args[++i]:'1'); else if(['node-js','game','userdata','scenario','frames','max-seconds','period','log','csv','summarize'].includes(key)) { val??=args[++i]; if(val===undefined) throw new Error('missing value for --'+key); a[key]=['frames','max-seconds','period'].includes(key)?Number(val):val; } else throw new Error('unknown option --'+key);
 }
 if(a.summarize) { printTable(summarize(readFileSync(a.summarize,'utf8'),a.csv)); return; }
 if(!a['node-js']||!a.game||!a.userdata||!a.log) throw new Error('--node-js, --game, --userdata and --log are required');
 for(const k of ['frames','max-seconds','period']) if(!Number.isInteger(a[k])||a[k]<=0) throw new Error('--'+k+' must be a positive integer');
 mkdirSync(a.userdata,{recursive:true}); const env={...process.env,PORT_LOG_FPS:'1',PORT_NO_AUDIO:'1',PORT_USERDATA:resolve(a.userdata),PORT_INPUT:buildInput(a.scenario,a.frames,a.period,a['skip-save'])}; if(a.nopace!==undefined) env.PORT_HL_NOPACE=a.nopace;
 const start=Date.now(), log=createWriteStream(a.log), child=spawn(process.execPath,[a['node-js'],a.game],{env,detached:process.platform!=='win32',stdio:['ignore','pipe','pipe']}); let frame=0, pending='', stopping=false;
 const stop=()=>{ if(stopping)return; stopping=true; try { if(process.platform==='win32') child.kill('SIGTERM'); else process.kill(-child.pid,'SIGTERM'); } catch(e) { if(e.code!=='ESRCH') throw e; } setTimeout(()=>{try { if(process.platform==='win32') child.kill('SIGKILL'); else process.kill(-child.pid,'SIGKILL'); } catch {}},10000).unref(); };
 const timer=setTimeout(stop,a['max-seconds']*1000); timer.unref();
 const onData=chunk=>{log.write(chunk); pending+=chunk.toString('utf8'); let lines=pending.split('\n'); pending=lines.pop(); for(const line of lines) {const m=patterns.fps.exec(line); if(m) frame=+m[2]; if(frame>=a.frames) stop();}};
 child.stdout.on('data',onData); child.stderr.on('data',onData);
 let code; try { [code]=await once(child,'close'); } finally { clearTimeout(timer); log.end(); await once(log,'finish'); }
 console.log(`[${a.scenario}] frame ${frame}, ${Math.round((Date.now()-start)/1000)} s, exit ${code}, лог ${a.log}`); printTable(summarize(readFileSync(a.log,'utf8'),a.csv));
}
if(process.argv[1] && resolve(process.argv[1])===fileURLToPath(import.meta.url)) main().catch(e=>{console.error(e.message);process.exitCode=1;});
