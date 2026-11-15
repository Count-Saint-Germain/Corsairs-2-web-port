/** Build the English texture and voice overlay from the original resources. */
import fs from 'node:fs';
import crypto from 'node:crypto';
import * as ea from './english_assets.mjs';
import {Fail,sha256} from './prepare_english_core.mjs';
import {refresh_meta} from './prepare_english_text.mjs';
export const LOADING_DIR='RESOURCE/Textures/Loading', WORLDMAP_DIR='RESOURCE/Textures/WorldMap/reload', VOICE_DIR='RESOURCE/Sounds/VOICE', ALIASES_DIR='RESOURCE/INI/ALIASES', GREETINGS='RESOURCE/INI/ALIASES/GREETINGS_ALIAS.INI', US_VIDEO='RESOURCE/VIDEOS/INVASION.WMV';
const cmp=(a,b)=>a<b?-1:a>b?1:0, sortUpper=(a,b)=>cmp(a.toUpperCase(),b.toUpperCase());
const eq=(a,b)=>a!==null&&b!==null&&a.equals(b);
const union=(...sets)=>new Set(sets.flatMap((s)=>[...s]));
const fmt=(i)=>`${i.fmt_name} ${i.width}x${i.height} mips=${i.mips}`;
export class ResOpts {
  constructor({skip_loading=false,skip_voice=false,voice_scope='referenced',keep_ru_greetings=false,voice_russian_dir=false,rules=null}={}){
    if(!['referenced','all'].includes(voice_scope))throw new Fail('--voice-scope: referenced or all');
    Object.assign(this,{skip_loading,skip_voice,voice_scope,keep_ru_greetings,voice_russian_dir,rules:rules??ea.DEFAULT_RELOCATE});
  }
}
export function load_rules(file){if(!file||!fs.existsSync(file)||!fs.statSync(file).isFile())return ea.DEFAULT_RELOCATE;try{return ea.parse_relocate_rules(JSON.parse(fs.readFileSync(file,'utf8'))?.files?.relocate_if_absent??[]);}catch(e){throw new Fail(`port.json cannot be read (${file}): ${e.message}`);}}
export function published_view(bulk,rules,prefix){const rels=bulk.under(prefix),mv=ea.relocations(rels,rules),pub=new Map();for(const r of rels){const pr=mv[r]??r;pub.set(pr.toLowerCase(),[pr,r]);}return pub;}
function digest(items){const h=crypto.createHash('sha256');for(const [k,size,hex] of items)h.update(`${k.toUpperCase()}\t${size}\t${hex}\n`);return h.digest('hex');}
export function bulk_digest(bulk,rels){return digest([...rels].sort(sortUpper).map((r)=>[r,bulk.size(r),sha256(bulk.read(r))]));}
export function listing_digest(bulk,rels){return digest([...rels].sort(sortUpper).map((r)=>[r,bulk.size(r),'-']));}
export function build_texture_dir(res,cls,base,base_bulk,us_bulk,us_dir,rules,ref_subdir=null){
 const list=us_bulk.under(us_dir);if(!list.length){res.notes.push(`${cls}: US source lacks ${us_dir}`);return null;}
 const pub=published_view(base_bulk,rules,us_dir),dir=base_bulk.dir_spelling(us_dir)||us_dir,st={us_files:list.length,overlay:0,same:0,new_only:0,bytes:0,formats:{}},taken=new Set(Object.keys(res.files).map((r)=>r.toUpperCase()));
 for(const urel of list){const name=urel.slice(us_dir.length+1);if(name.includes('/')||!name.toLowerCase().endsWith('.tx'))throw new Fail(`${urel}: unexpected file in ${us_dir}`);
  const usb=us_bulk.read(urel);let ui;try{ui=ea.parse_tx(usb);}catch(e){throw new Fail(`${urel}: ${e.message}`);}
  const ent=pub.get((us_dir+'/'+name).toLowerCase());let ref=null,bb=null;
  try{if(ent){bb=base_bulk.read(ent[1]);ref=ea.parse_tx(bb);}else if(ref_subdir){const rr=base_bulk.name(`${us_dir}/${ref_subdir}/${name}`);if(rr)ref=ea.parse_tx(base_bulk.read(rr));}}catch(e){throw new Fail(`base texture ${name}: ${e.message}`);}
  if(ref&&!ea.same_layout(ui,ref))throw new Fail(`${name}: texture layout mismatch (${fmt(ui)} / ${fmt(ref)})`);
  if(ent&&eq(bb,usb)){st.same++;continue;}
  const rel=ent?ent[0]:dir+'/'+name;if(taken.has(rel.toUpperCase()))throw new Fail(`duplicate overlay path: ${rel}`);taken.add(rel.toUpperCase());
  res.files[rel]=usb;res.info[rel]={cls,base_sha256:ent?sha256(bb):null,us_name:name,layout:fmt(ui),kind:ent?'replace':'add'};
  st.overlay++;if(!ent)st.new_only++;st.bytes+=usb.length;st.formats[fmt(ui)]=(st.formats[fmt(ui)]||0)+1;
 }
 st.us_digest=bulk_digest(us_bulk,list);st.base_digest=listing_digest(base_bulk,base_bulk.under(us_dir));return [st,pub];
}
export function build_loading(res,base,bb,ub,opts){const r=build_texture_dir(res,'loading',base,bb,ub,LOADING_DIR,opts.rules);if(!r)return;const [st,pub]=r,req=new Set();for(const k of base.keys())if(k.startsWith('PROGRAM/'))for(const n of ea.script_loading_names(base.f.get(k)[1]))req.add(n);let en=0;const rest=[];for(const n of [...req].sort()){if(ub.has(`${LOADING_DIR}/${n}.tga.tx`)){en++;continue;}const ent=pub.get(`${LOADING_DIR.toLowerCase()}/${n}.tga.tx`);rest.push({name:n,base:!ent?'nowhere':ent[1].toLowerCase().includes('/russian/')?'Russian':'top'});}Object.assign(st,{requested:req.size,requested_english:en,requested_without_us:rest});res.stats.loading=st;}
export function build_worldmap(res,base,bb,ub,opts){const r=build_texture_dir(res,'worldmap',base,bb,ub,WORLDMAP_DIR,opts.rules,'Russian');if(!r)return;const [st]=r,req=new Set();for(const k of base.keys())if(k.startsWith('PROGRAM/'))for(const m of base.f.get(k)[1].toString('latin1').matchAll(/worldmap[\\/]+reload[\\/]+([A-Za-z0-9_-]+)\.tga/gi))req.add(m[1].toLowerCase());st.requested=[...req].sort();st.requested_missing_us=st.requested.filter((n)=>!ub.has(`${WORLDMAP_DIR}/${n}.tga.tx`));res.stats.worldmap=st;}
function voice_cover(names,us,bb){let en=0;const left=[],silent=[];for(const n of [...names].sort()){if(us.has(n))en++;else if(bb.has(`${VOICE_DIR}/${n}`))left.push(n);else silent.push(n);}return [en,left,silent];}
export function build_voice(res,base,bb,ub,opts){
 const list=ub.under(VOICE_DIR,true);if(!list.length){res.notes.push(`voice: US source lacks ${VOICE_DIR}`);return;}const bad=list.find((r)=>!r.toLowerCase().endsWith('.wav'));if(bad)throw new Fail(`US voice must be .wav: ${bad}`);
 const ba=new Map(bb.under(ALIASES_DIR,true).filter((r)=>r.toLowerCase().endsWith('.ini')).map((r)=>[r,bb.read(r)])),ua=new Map(ub.under(ALIASES_DIR,true).filter((r)=>r.toLowerCase().endsWith('.ini')).map((r)=>[r,ub.read(r)]));
 const refs_base=union(...[...ba.values()].map(ea.alias_voice_names)),refs_us=union(...[...ua.values()].map(ea.alias_voice_names)),refs_script=new Set();for(const k of base.keys())if(k.startsWith('PROGRAM/'))for(const n of ea.script_voice_names(base.f.get(k)[1]))refs_script.add(n);
 const refs=union(refs_base,refs_us,refs_script),us=new Map(list.map((r)=>[r.slice(VOICE_DIR.length+1).toLowerCase(),r])),vdir=bb.dir_spelling(VOICE_DIR)||VOICE_DIR;
 const st={us_files:list.length,us_bytes:list.reduce((n,r)=>n+ub.size(r),0),scope:opts.voice_scope,referenced:[...us.keys()].filter((n)=>refs.has(n)).length,selected:0,selected_bytes:0,replaced:0,added:0,same:0,unreferenced_skipped:0,unreferenced_skipped_bytes:0,format_mismatch:[],russian_dir:0},taken=new Set(Object.keys(res.files).map((r)=>r.toUpperCase()));
 function put(rel,data,base_sha256,extra){if(taken.has(rel.toUpperCase()))throw new Fail(`duplicate overlay path: ${rel}`);taken.add(rel.toUpperCase());res.files[rel]=data;res.info[rel]={cls:'voice',base_sha256,...extra};}
 for(const n of [...us.keys()].sort()){const rel=us.get(n);if(opts.voice_scope==='referenced'&&!refs.has(n)){st.unreferenced_skipped++;st.unreferenced_skipped_bytes+=ub.size(rel);continue;}const data=ub.read(rel);let wav;try{wav=ea.parse_wav(data);}catch(e){throw new Fail(`${rel}: ${e.message}`);}st.selected++;st.selected_bytes+=data.length;const br=bb.name(`${VOICE_DIR}/${n}`);let old=null;if(br){old=bb.read(br);let bw;try{bw=ea.parse_wav(old);}catch(e){throw new Fail(`base ${br}: ${e.message}`);}if(bw.channels!==wav.channels||bw.rate!==wav.rate)st.format_mismatch.push(n);}
  const us_name=rel.slice(VOICE_DIR.length+1);if(eq(old,data))st.same++;else{put(br||`${vdir}/${us_name}`,data,old?sha256(old):null,{us_name,kind:old?'replace':'add',rate:wav.rate,channels:wav.channels});st[old?'replaced':'added']++;}
  if(opts.voice_russian_dir){const rr=bb.name(`${VOICE_DIR}/RUSSIAN/${n}`);if(rr){const rb=bb.read(rr);if(!eq(rb,data)){put(rr,data,sha256(rb),{us_name,kind:'replace_russian_dir',rate:wav.rate,channels:wav.channels});st.russian_dir++;}}}
 }
 st.greetings='ru';let greet=null;if(!opts.keep_ru_greetings&&ub.has(GREETINGS)&&bb.has(GREETINGS)){const b=bb.read(GREETINGS),u=ub.read(GREETINGS),probs=ea.alias_compat(b,u);if(probs.length)throw new Fail('Greetings_alias.ini: '+probs.slice(0,3).join('; '));st.greetings='us';greet=ea.alias_voice_names(u);if(!eq(b,u)){const bd=ea.alias_sections(b)[1],ud=ea.alias_sections(u)[1],rel=bb.name(GREETINGS);if(taken.has(rel.toUpperCase()))throw new Fail(`duplicate path: ${rel}`);res.files[rel]=u;res.info[rel]={cls:'aliases',base_sha256:sha256(b),sections:Object.keys(bd).length,remapped:Object.keys(bd).filter((k)=>JSON.stringify(bd[k])!==JSON.stringify(ud[k])).length};}}
 const other=union(...[...ba].filter(([r])=>r.toUpperCase()!==GREETINGS).map(([,b])=>ea.alias_voice_names(b))),gn=bb.name(GREETINGS),ru=ba.has(gn)?ea.alias_voice_names(ba.get(gn)):new Set(),eff=union(other,refs_script,greet??ru);
 const coverage=(names)=>{const [english,left_russian,silent]=voice_cover(names,us,bb);return {alias_names:names.size,english,left_russian,silent};};st.coverage=coverage(eff);if(greet!==null)st.coverage_if_ru_greetings=coverage(union(other,refs_script,ru));
 const root=bb.under(VOICE_DIR,true).filter((r)=>r.toLowerCase().endsWith('.wav')),only=root.map((r)=>r.slice(VOICE_DIR.length+1)).filter((n)=>!us.has(n.toLowerCase()));st.base_wav_files=root.length;st.base_only_wav=only.length;st.base_only_referenced=only.filter((n)=>eff.has(n.toLowerCase())).length;st.format_mismatch.sort();st.us_digest=bulk_digest(ub,[...list,...ua.keys()]);st.base_digest=listing_digest(bb,[...root,...ba.keys()]);res.stats.voice=st;
}
export function build_resources(res,base,bb,ub,opts=new ResOpts()){if(!opts.skip_loading){build_loading(res,base,bb,ub,opts);build_worldmap(res,base,bb,ub,opts);}if(!opts.skip_voice)build_voice(res,base,bb,ub,opts);refresh_meta(res);}
