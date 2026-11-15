/** Assemble the English text overlay while preserving the Russian code skeleton. */
import * as et from './english_text.mjs';
import { Fail, Result, sha256, drift, check_protected, classify_left, check_anchors } from './prepare_english_core.mjs';

export const GENERATOR='prepare_english.py/1'; // stable on-disk format identifier
export const NAMES_FILE='PROGRAM/CHARACTERS/CHARACTERS_NAMES.C';
export const LANG_INI='RESOURCE/INI/TEXTS/LANGUAGE.INI';
export const FONTS_INI='RESOURCE/INI/FONTS.INI';
export const QUESTS='RESOURCE/QUESTSTEXT/QUESTS_TEXTS.TXT';
export const TEXTS_RU='RESOURCE/INI/TEXTS/RUSSIAN/';
export const TEXTS_EN='RESOURCE/INI/TEXTS/ENGLISH/';
export const TEXT_KEY_RENAMES=new Map([
 ['youve_got',"you've_got"],['itmname_satanist_amulet','itmname_animists_amulet'],['itmdescr_satanist_amulet','itmdescr_animists_amulet'],['itmdescr_blade2r','itmdescr_blade2'],['itmname_blade22','itmnameblade22'],
]);
const latin=(b)=>Buffer.from(b).toString('latin1'), buf=(s)=>Buffer.from(s,'latin1');
const strip=(s)=>s.replace(/^[\x09-\x0d\x20]+|[\x09-\x0d\x20]+$/gu,'');
const cp1251=new TextDecoder('windows-1251');
const same=(a,b)=>a!==null&&b!==null&&Buffer.from(a).equals(Buffer.from(b));
export function build_program_files(base,us,manual,res,leftovers=null){
  for(const k of base.keys()){
    if(!k.startsWith('PROGRAM/')||k===NAMES_FILE)continue;
    const [rel,rb]=base.f.get(k),is_h=k.startsWith('PROGRAM/DIALOGS/')&&k.endsWith('.H'),man=manual.lit.get(k)||new Map();
    if(!man.size&&!et.has_cyr(rb))continue;
    const spans=is_h?et.h_region_spans(rb):et.literal_spans(rb);
    if(!man.size&&!spans.some(([s,e])=>et.has_cyr(rb.subarray(s,e))))continue;
    const ub=us.get(rel);let ruc=null,usc=null;
    if(is_h&&ub!==null){const c=rel.slice(0,-2)+'.c';ruc=base.get(c);usc=us.get(c);}
    const mdict=new Map();
    for(const [idx,[en,ov,sha,n]] of man){
      if(idx<0||idx>=spans.length)throw new Fail(`manual layer: ${rel}: index ${idx} out of range (${spans.length})`);
      const [s,e]=spans[idx],got=et.sha256(rb.subarray(s+1,e-1));if(got!==sha)drift(`${rel}[${idx}]`,got,sha);
      mdict.set(idx,[en,ov]);manual.used.add(n);
    }
    const prot=leftovers?.lit.get(k)||new Map();check_protected(rel,rb,spans,prot,man);
    let pairs=null;
    if(manual.pairs.has(k)){
      const [map,nRu,nUs,n]=manual.pairs.get(k);
      if(spans.length!==nRu||ub===null||et.h_region_spans(ub).length!==nUs)throw new Fail(`manual pairs no longer match ${rel} literal counts`);
      pairs=map;manual.used.add(n);
    }
    let plan,next;try{
      plan=et.plan_literals(rel,rb,ub,{is_h,ru_c:ruc,us_c:usc,manual:mdict,pair_overrides:pairs});
      next=et.render_literals(rel,rb,plan,{is_h});
    }catch(e){if(e instanceof et.TextError)throw new Fail(e.message);throw e;}
    for(const idx of prot.keys())if(plan.changes().has(idx))throw new Fail(`${rel}[${idx}]: protected literal was replaced by automatic pair`);
    check_anchors(rel,plan.anchors);
    for(const i of plan.left_ru){
      const reason=plan.same.has(i)?'same_in_us':plan.skipped.get(i)==='us_russian'?'us_russian':plan.skipped.has(i)?`skipped_${plan.skipped.get(i)}`:'no_pair';
      const [s,e]=spans[i];res.left.push({file:rel,index:i,reason,ru_sha256:et.sha256(rb.subarray(s+1,e-1))});
    }
    if(same(next,rb))continue;
    res.files[rel]=next;res.info[rel]={cls:plan.mode==='manual_only'?'manual':'align',base_sha256:sha256(rb),mode:plan.mode,literals:plan.n_lit,ru_cyrillic:plan.cyr_total,auto:plan.auto.size,manual:plan.manual.size,left_ru:plan.left_ru.length,skipped:plan.skipped.size,anchors:[...plan.anchors]};
  }
}
export function build_names(base,us,res){
  const rel=base.name(NAMES_FILE),rb=base.get(NAMES_FILE),ub=us.get(NAMES_FILE);
  if(rel===null)throw new Fail('base copy missing Characters_names.c');
  if(ub===null)throw new Fail('US game missing Characters_names.c');
  let next;try{next=et.normalize_names_file(ub);et.verify_names_file(rb,next);}catch(e){if(e instanceof et.TextError)throw new Fail(e.message);throw e;}
  res.files[rel]=next;const count=et.literal_spans(next).length;res.info[rel]={cls:'names',base_sha256:sha256(rb),literals:count,auto:count,manual:0,left_ru:0};
}
function sectionSplit(raw){
  const text=latin(raw),parts=text.split(/(?=^\[)/mu),sections=[];
  if(text.startsWith('['))parts.unshift('');
  for(const text of parts.slice(1))sections.push([strip(text.split('\r')[0].split('\n')[0]),text]);
  return [parts[0],sections];
}
export function build_language_ini(base,us,res){
  const rel=base.name(LANG_INI),rb=base.get(LANG_INI);if(rb===null)throw new Fail('base copy missing language.ini');
  let seen=false;
  const lines=latin(rb).split('\n').map((line)=>{
    const m=/^(;?)([\x09-\x0d\x20]*defaultLanguage[\x09-\x0d\x20]*=[\x09-\x0d\x20]*)([^\x09-\x0d\x20]+)(.*)$/su.exec(line);
    if(!m)return line;seen=true;return `${strip(m[3]).toLowerCase()==='english'?'':';'}${m[2]}${m[3]}${m[4]}`;
  });
  if(!seen)throw new Fail('language.ini: no defaultLanguage lines');
  const next=buf(lines.join('\n')),ub=us.get(LANG_INI);
  if(ub!==null&&!same(ub,next))throw new Fail('language.ini: result differs from US file');
  if(same(next,rb))return;
  res.files[rel]=next;res.info[rel]={cls:'texts',base_sha256:sha256(rb),note:'language.ini: defaultLanguage = English'};
}
export function build_fonts_ini(base,us,res){
  const rel=base.name(FONTS_INI),rb=base.get(FONTS_INI),ub=us.get(FONTS_INI);
  if(rb===null||ub===null)throw new Fail('fonts.ini missing in base or US game');
  const [preB,secB]=sectionSplit(rb),[,secU]=sectionSplit(ub),um=new Map(secU);let next=preB;
  for(const [name,orig] of secB){
    let text=orig;
    if(name==='[INTERFACE_TITLE]'&&um.has(name)){
      const re=/^Texture[ \t]*=[ \t]*([^\r\n]*)/dmu,tb=re.exec(text),tu=re.exec(um.get(name));
      if(!tb||!tu)throw new Fail('fonts.ini: missing Texture in [INTERFACE_TITLE]');
      if(!strip(tu[1]).toLowerCase().endsWith('menu font.tga'))throw new Fail('fonts.ini: unexpected US title font texture');
      const [start,end]=tb.indices[1];text=text.slice(0,start)+tu[1]+text.slice(end);
    }
    next+=text;
  }
  const norm=(s)=>s.split('\n').filter((x)=>strip(x)&&!/^[\x09-\x0d\x20]*(?:pcscale|;)/u.test(x)).map((x)=>x.replace(/[\x09-\x0d\x20]+$/u,''));
  const nm=new Map(sectionSplit(buf(next))[1]);
  for(const [name,text] of secU){
    if(!nm.has(name))throw new Fail(`fonts.ini: US section ${name} absent from base`);
    if(JSON.stringify(norm(text))!==JSON.stringify(norm(nm.get(name))))throw new Fail(`fonts.ini: section ${name} differs from US beyond pcscale/comments`);
  }
  const result=buf(next);if(same(result,rb))return;
  res.files[rel]=result;res.info[rel]={cls:'texts',base_sha256:sha256(rb),note:'fonts.ini: база 1.03 + [INTERFACE_TITLE] Texture = menu font.tga'};
}
export function build_texts(base,us,manual,res){
  for(const k of base.keys()){
    if(!k.startsWith(TEXTS_RU))continue;
    const [baseRel,ruRaw]=base.f.get(k),sub=baseRel.slice(TEXTS_RU.length),isIni=sub.toLowerCase().endsWith('.ini');
    let usRaw=us.get(TEXTS_EN+sub);const baseEnRel=base.name(TEXTS_EN+sub),outRel=baseEnRel||(base.name(TEXTS_EN.replace(/\/$/u,''))||'RESOURCE/INI/TEXTS/ENGLISH')+'/'+sub;
    if(usRaw===null){if(baseEnRel===null)throw new Fail(`missing English TEXTS file: ${sub}`);usRaw=base.get(TEXTS_EN+sub);}
    let ruEntries,enEntries;try{ruEntries=et.parse_text_entries(ruRaw,isIni);enEntries=et.parse_text_entries(usRaw,isIni);}catch(e){if(e instanceof et.TextError)throw new Fail(`${sub}: ${e.message}`);throw e;}
    const ruKeys=ruEntries.map(([x])=>x.toString('hex')),enKeys=enEntries.map(([x])=>x.toString('hex')),mt=manual.text.get((TEXTS_EN+sub).toUpperCase())||new Map();
    if(JSON.stringify(ruKeys)===JSON.stringify(enKeys)&&!mt.size){
      if(et.us_is_russian(usRaw))throw new Fail(`${sub}: Russian text in English file`);
      let next;try{next=et.to_game_ascii(usRaw,false);}catch(e){if(e instanceof et.TextError)throw new Fail(`${sub}: ${e.message}`);throw e;}
      const baseEn=base.get(TEXTS_EN+sub),high=[];
      for(let i=0;i<ruEntries.length;i++){
        const [key,[a,b]]=ruEntries[i],[,[c,d]]=enEntries[i],ruLen=b-a,enLen=d-c;
        if(enLen>30&&enLen/Math.max(ruLen,1)>1.6)high.push(cp1251.decode(key));
      }
      if(high.length)res.warnings.push([sub,high.sort()]);
      if(!same(next,baseEn)){res.files[outRel]=next;res.info[outRel]={cls:'texts',base_sha256:baseEn?.length?sha256(baseEn):null,entries:ruKeys.length,auto:ruKeys.length,manual:0,note:'американский файл с нормализацией символов'};}
      continue;
    }
    const mdict=new Map();
    for(const [key,[en,ov,sha,n]] of mt){
      const hits=ruEntries.filter(([k])=>cp1251.decode(k)===key).map(([,span])=>span);
      if(hits.length!==1)throw new Fail(`manual layer: ${sub}: key ${key} found ${hits.length} times`);
      const [s,e]=hits[0],got=et.sha256(ruRaw.subarray(s,e));if(got!==sha)drift(`${sub} ${key}`,got,sha);
      mdict.set(key,[en,ov]);manual.used.add(n);
    }
    let next,stats;try{[next,stats]=et.build_text_file(sub,ruRaw,usRaw,{renames:TEXT_KEY_RENAMES,manual:mdict});}catch(e){if(e instanceof et.TextError)throw new Fail(e.message);throw e;}
    res.files[outRel]=next;res.info[outRel]={cls:'texts',base_sha256:baseEnRel?sha256(base.get(TEXTS_EN+sub)):null,entries:stats.entries,auto:stats.auto,manual:stats.manual,renamed:stats.renamed};
    if(stats.len_ratio_hi.length)res.warnings.push([sub,[...stats.len_ratio_hi].sort()]);
  }
}
export function build_quests(base,us,manual,res){
  const rel=base.name(QUESTS),rb=base.get(QUESTS),ub=us.get(QUESTS);if(rb===null||ub===null)throw new Fail('QUESTSTEXT missing from base or US game');
  const mq=new Map(),records=new Map(et.parse_quests(rb)[0].map((r)=>[et.quest_key(r),et.quest_body(r)]));
  for(const [key,[en,ov,sha,n]] of manual.quest){
    if(!records.has(key))throw new Fail(`manual layer: QUESTSTEXT missing ${key}`);
    const got=et.sha256(records.get(key));if(got!==sha)drift(`QUESTSTEXT ${key}`,got,sha);
    mq.set(key,[en,ov]);manual.used.add(n);
  }
  let next,stats;try{[next,stats]=et.build_quests(rb,ub,mq);}catch(e){if(e instanceof et.TextError)throw new Fail(e.message);throw e;}
  res.files[rel]=next;res.info[rel]={cls:'quests',base_sha256:sha256(rb),entries:stats.records,auto:stats.auto,manual:stats.manual,left_ru:stats.left_ru.length,skipped:Object.keys(stats.skipped).length};
  for(const key of stats.left_ru)res.left.push({file:rel,key,reason:'no_pair',ru_sha256:et.sha256(records.get(key))});
}
function asciiJson(value){return JSON.stringify(value,null,1).replace(/[^\x00-\x7e]/g,(c)=>`\\u${c.charCodeAt(0).toString(16).padStart(4,'0')}`);}
export function refresh_meta(res){
  const base={};for(const rel of Object.keys(res.files).sort())if(rel!=='OVERLAY.json'&&res.info[rel].base_sha256)base[rel]=res.info[rel].base_sha256;
  const meta={base,format:1,generator:GENERATOR,language:'English'};
  res.files['OVERLAY.json']=Buffer.from(asciiJson(meta)+'\n','ascii');res.info['OVERLAY.json']={cls:'meta'};
}
export function build_overlay(base,us,manual,leftovers=null){
  const res=new Result();build_program_files(base,us,manual,res,leftovers);build_names(base,us,res);build_language_ini(base,us,res);build_fonts_ini(base,us,res);build_texts(base,us,manual,res);build_quests(base,us,manual,res);
  const unused=manual.entries.filter((_,i)=>!manual.used.has(i));if(unused.length)throw new Fail(`manual layer: ${unused.length} entries unused: ${unused.slice(0,5).map((e)=>`${e.file}:${e.index??e.key}`).join(', ')}`);
  classify_left(res,leftovers);refresh_meta(res);return res;
}
