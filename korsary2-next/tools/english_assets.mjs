/** English resource-layer helpers: textures, WAV, aliases, relocations and video. */
import crypto from 'node:crypto';
import { spawnSync } from 'node:child_process';

export class AssetError extends Error {}
export const sha256 = (b) => crypto.createHash('sha256').update(b).digest('hex');
export const FMT_NAMES = {21:'A8R8G8B8',22:'X8R8G8B8',23:'R5G6B5',24:'X1R5G5B5',25:'A1R5G5B5',26:'A4R4G4B4',0x31545844:'DXT1',0x32545844:'DXT2',0x33545844:'DXT3',0x34545844:'DXT4',0x35545844:'DXT5'};
const BPP={21:4,22:4,23:2,24:2,25:2,26:2};
function levelSize(fmt,w,h) {
  if(fmt===0x31545844)return Math.max(1,Math.floor((w+3)/4))*Math.max(1,Math.floor((h+3)/4))*8;
  if([0x32545844,0x33545844,0x34545844,0x35545844].includes(fmt))return Math.max(1,Math.floor((w+3)/4))*Math.max(1,Math.floor((h+3)/4))*16;
  return w*h*BPP[fmt];
}
export function parse_tx(raw) {
  const b=Buffer.from(raw); if(b.length<24)throw new AssetError('.tx shorter than header');
  const [flags,width,height,mips,fmt,size0]=Array.from({length:6},(_,i)=>b.readUInt32LE(i*4));
  if(flags!==0||width<1||width>8192||height<1||height>8192||mips<1||mips>16)throw new AssetError(`.tx: invalid header (flags=${flags} ${width}x${height} mips=${mips})`);
  if(!(fmt in FMT_NAMES))throw new AssetError(`.tx: unknown format ${fmt}`);
  let total=24,w=width,h=height;
  for(let i=0;i<mips;i++) {
    const size=levelSize(fmt,w,h);if(i===0&&size!==size0)throw new AssetError(`.tx: first mip size ${size0}, expected ${size}`);
    total+=size;w=Math.max(1,Math.floor(w/2));h=Math.max(1,Math.floor(h/2));
  }
  if(total!==b.length)throw new AssetError(`.tx: file size ${b.length}, expected ${total}`);
  return {width,height,mips,fmt,fmt_name:FMT_NAMES[fmt],size:total};
}
export function same_layout(a,b) { return ['fmt','width','height','mips'].every((key)=>a[key]===b[key]); }
export function parse_wav(raw) {
  const b=Buffer.from(raw);
  if(b.length<45)throw new AssetError('wav shorter than 45 bytes');
  if(b.subarray(0,4).toString('ascii')!=='RIFF'||b.subarray(8,12).toString('ascii')!=='WAVE'||b.subarray(12,16).toString('ascii')!=='fmt '||b.subarray(36,40).toString('ascii')!=='data')throw new AssetError('wav: not a canonical 44-byte RIFF/WAVE/fmt/data header');
  const riff=b.readUInt32LE(4),fmtLen=b.readUInt32LE(16),tag=b.readUInt16LE(20),channels=b.readUInt16LE(22),rate=b.readUInt32LE(24),byteRate=b.readUInt32LE(28),align=b.readUInt16LE(32),bits=b.readUInt16LE(34),data=b.readUInt32LE(40);
  if(fmtLen!==16||tag!==1)throw new AssetError(`wav: not PCM (format ${tag}, fmt size ${fmtLen})`);
  if(bits!==16||![1,2].includes(channels)||align!==channels*2||byteRate!==rate*align)throw new AssetError(`wav: expected PCM 16-bit mono/stereo (bits ${bits}, channels ${channels})`);
  if(data!==b.length-44||riff!==b.length-8||data%align)throw new AssetError('wav: RIFF/data sizes do not match the file length');
  return {channels,rate,bits,data};
}
const CP1251=new TextDecoder('windows-1251');
export function alias_sections(raw) {
  const order=[],sections=Object.create(null);let current=null;
  for(const line of CP1251.decode(raw).split(/\r\n|\n|\r/u)) {
    const text=line.trim();if(!text||text.startsWith(';'))continue;
    const section=/^\[(.*)\]\s*$/u.exec(text);
    if(section){current=section[1].trim().toLowerCase();order.push(current);sections[current]??=[];continue;}
    const kv=/^([A-Za-z_][\p{L}\p{N}_ ]*?)\s*=\s*(.*)$/u.exec(text);
    if(kv&&current!==null)sections[current].push([kv[1].trim().toLowerCase(),kv[2].trim().toLowerCase()]);
  }
  return [order,sections];
}
export function alias_voice_names(raw) {
  const out=new Set();
  for(const entries of Object.values(alias_sections(raw)[1]))for(const [key,value] of entries){
    if(key==='name'&&value.startsWith('voice\\')&&value.endsWith('.wav')&&!value.slice(6).includes('\\'))out.add(value.slice(6));
  }
  return out;
}
export function alias_compat(ruRaw,usRaw) {
  const [ro,rd]=alias_sections(ruRaw),[uo,ud]=alias_sections(usRaw),a=Object.keys(rd).sort(),b=Object.keys(ud).sort(),problems=[];
  if(JSON.stringify(a)!==JSON.stringify(b)||ro.length!==new Set(ro).size||uo.length!==new Set(uo).size) {
    problems.push(`different section sets (Russian only: ${a.filter((x)=>!Object.hasOwn(ud,x)).length}, US only: ${b.filter((x)=>!Object.hasOwn(rd,x)).length})`);
    return problems;
  }
  for(const name of a)if(JSON.stringify(rd[name].filter(([k])=>k!=='name'))!==JSON.stringify(ud[name].filter(([k])=>k!=='name')))problems.push(`section [${name}]: parameters other than name differ`);
  return problems;
}
export function script_voice_names(raw) {
  return new Set([...Buffer.from(raw).toString('latin1').matchAll(/voice[\\/]+([A-Za-z0-9_\-. ]+\.wav)/giu)].map((m)=>m[1].toLowerCase()));
}
export function script_loading_names(raw) {
  return new Set([...Buffer.from(raw).toString('latin1').matchAll(/loading[\\/]+([A-Za-z0-9_\- ]+)\.tga/giu)].map((m)=>m[1].toLowerCase()));
}
export const DEFAULT_RELOCATE=[{from:'RESOURCE/Textures/Loading/Russian',to:'RESOURCE/Textures/Loading'},{from:'RESOURCE/Textures/WorldMap/reload/Russian',to:'RESOURCE/Textures/WorldMap/reload'}];
export function parse_relocate_rules(raw) {
  if(raw===null||raw===undefined)return [];
  if(!Array.isArray(raw))throw new AssetError('port.json files.relocate_if_absent: expected an array');
  return raw.map((r)=>{
    if(!r||Array.isArray(r)||typeof r!=='object'||Object.keys(r).sort().join(',')!=='from,to'||typeof r.from!=='string'||typeof r.to!=='string')throw new AssetError(`port.json files.relocate_if_absent: unsupported rule ${JSON.stringify(r)}`);
    return {from:r.from.replace(/^\/+|\/+$/gu,''),to:r.to.replace(/^\/+|\/+$/gu,'')};
  });
}
export function relocations(input,rules) {
  const paths=[...input].sort();if(!rules?.length)return {};
  const taken=new Set(paths.map((p)=>p.toLowerCase())),dirs=new Set();
  for(const p of taken){const parts=p.split('/');for(let i=1;i<parts.length;i++)dirs.add(parts.slice(0,i).join('/'));}
  const moves={};
  for(const rule of rules){
    const src=rule.from.toLowerCase(),dst=rule.to.toLowerCase();
    for(const p of paths){
      const low=p.toLowerCase();if(!low.startsWith(`${src}/`)||p.slice(src.length+1).includes('/'))continue;
      const name=p.slice(src.length+1),targetDir=src.startsWith(`${dst}/`)?p.slice(0,dst.length):rule.to,target=`${targetDir}/${name}`;
      if(taken.has(target.toLowerCase())||dirs.has(target.toLowerCase()))continue;
      taken.add(target.toLowerCase());moves[p]=target;
    }
  }
  return moves;
}
export const VIDEO_NAME='English/Invasion.mp4';
export function ffmpeg_cmd(ffmpeg,src,dst) {
  return [ffmpeg,'-hide_banner','-loglevel','error','-nostdin','-y','-threads','1','-fflags','+bitexact','-i',src,'-map','0:v:0','-map','0:a:0?','-map_metadata','-1','-map_chapters','-1','-c:v','libx264','-crf','23','-preset','medium','-pix_fmt','yuv420p','-flags:v','+bitexact','-c:a','aac','-b:a','96k','-flags:a','+bitexact','-movflags','+faststart',dst];
}
export function tool_version(tool) {
  const r=spawnSync(tool,['-version'],{encoding:'utf8',timeout:30000});
  if(r.error||r.status!==0||!r.stdout)return null;
  return r.stdout.split('\n')[0].trim();
}
export function probe_video(ffprobe,file) {
  const r=spawnSync(ffprobe,['-v','error','-show_entries','format=duration:stream=codec_type,codec_name,width,height,sample_rate,channels','-of','json',file],{encoding:'utf8',timeout:120000});
  if(r.error||r.status!==0)throw new AssetError(`ffprobe: ${(r.stderr||r.error?.message||'').trim().slice(0,200)}`);
  const doc=JSON.parse(r.stdout),out={duration:Math.round(Number(doc.format.duration)*100)/100,video:null,audio:null};
  for(const s of doc.streams||[]){
    if(s.codec_type==='video'&&!out.video)out.video=[s.codec_name,s.width,s.height];
    else if(s.codec_type==='audio'&&!out.audio)out.audio=[s.codec_name,Number(s.sample_rate),s.channels];
  }
  return out;
}
