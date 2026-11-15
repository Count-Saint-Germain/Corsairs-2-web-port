/** Byte-preserving English text overlay helpers for CP1251 game scripts. */
import crypto from 'node:crypto';
import { scan as scanAudit, alignLines } from '../../english-audit/align_overlay.mjs';

export class TextError extends Error {}
export const sha256 = (b) => crypto.createHash('sha256').update(b).digest('hex');
const B=(x)=>Buffer.isBuffer(x)?x:Buffer.from(x);
const asLatin=(x)=>B(x).toString('latin1');
const bytes=(s)=>Buffer.from(s,'latin1');
const eq=(a,b)=>B(a).equals(B(b));
const trim=(s)=>s.replace(/^[\x09-\x0d\x20]+|[\x09-\x0d\x20]+$/gu,'');
const REF=/DLG_TEXT[\x09-\x0d\x20]*\[[\x09-\x0d\x20]*(\d+)[\x09-\x0d\x20]*\]/gu;
const H_START=/DLG_TEXT[\x09-\x0d\x20]*\[[\x09-\x0d\x20]*\d+[\x09-\x0d\x20]*\][\x09-\x0d\x20]*=[\x09-\x0d\x20]*\{/u;
const cp1251=new TextDecoder('windows-1251'), cp1252=new TextDecoder('windows-1252');
const entries=(v)=>v instanceof Map?[...v.entries()]:Object.entries(v||{});
const numericEntries=(v)=>entries(v).map(([k,x])=>[Number(k),x]).sort(([a],[b])=>a-b);
export function has_cyr(raw){return /[\xc0-\xff\xa8\xb8]/u.test(asLatin(raw));}
export function us_is_russian(raw){return /[\xc0-\xff\xa8\xb8]{2,}/u.test(asLatin(raw));}
export function scan(raw){
  let pos=0;return scanAudit(B(raw)).map(({skel,lits,line})=>{const row=[bytes(skel),lits.map(([a,b])=>[pos+a,pos+b])];pos+=line.length;return row;});
}
export function literal_spans(raw,lines=null){return (lines||scan(raw)).flatMap(([,spans])=>spans);}
export function h_region_spans(raw,lines=null){
  const parsed=lines||scan(raw), rows=scanAudit(B(raw));let started=false;const out=[];
  for(let i=0;i<parsed.length;i++){
    const [skel,spans]=parsed[i],line=rows[i].line;
    if(!started){if(H_START.test(line))started=true;continue;}
    if(asLatin(skel).includes('};'))break;
    out.push(...spans);
  }
  return out;
}
export function outside(raw,spans){
  raw=B(raw);const out=[];let pos=0;for(const [s,e] of spans){out.push(raw.subarray(pos,s),Buffer.from([0]));pos=e;}out.push(raw.subarray(pos));return Buffer.concat(out);
}
export function splice(raw,spans,repl){
  raw=B(raw);const replacements=new Map(numericEntries(repl)),out=[];let pos=0;
  spans.forEach(([s,e],i)=>{if(replacements.has(i)){out.push(raw.subarray(pos,s),B(replacements.get(i)));pos=e;}});
  out.push(raw.subarray(pos));return Buffer.concat(out);
}
export const inner=(lit)=>B(lit).subarray(1,-1);
export const quote=(b)=>Buffer.concat([Buffer.from('"'),B(b),Buffer.from('"')]);
export function align_pairs(a,b,ref_norm=false){
  return alignLines(a.map(([skel])=>({skel:asLatin(skel)})),b.map(([skel])=>({skel:asLatin(skel)})),ref_norm);
}
function refs(s){return [...s.matchAll(REF)].map((m)=>Number(m[1]));}
export function h_index_map(ruH,usH,ruC=null,usC=null){
  const rs=h_region_spans(ruH),us=h_region_spans(usH);
  if(rs.length===us.length)return [new Map(rs.map((_,i)=>[i,i])),'by_index',rs.length,us.length];
  if(ruC!==null&&usC!==null){
    const ra=scan(ruC),ua=scan(usC),rr=scanAudit(B(ruC)),ur=scanAudit(B(usC)),map=new Map();
    for(const [i,j] of align_pairs(ra,ua,true)){
      const x=refs(rr[i].line),y=refs(ur[j].line);
      if(x.length===y.length)for(let k=0;k<x.length;k++)if(!map.has(x[k]))map.set(x[k],y[k]);
    }
    return [new Map([...map].filter(([i,j])=>i<rs.length&&j<us.length)),'by_c_alignment',rs.length,us.length];
  }
  return [new Map(),'unmapped',rs.length,us.length];
}
export function line_literal_map(ruRaw,usRaw){
  const ra=scan(ruRaw),ua=scan(usRaw);
  const firsts=(rows)=>{let n=0;return rows.map(([,sp])=>{const first=n;n+=sp.length;return first;});};
  const fr=firsts(ra),fu=firsts(ua),map=new Map();
  for(const [i,j] of align_pairs(ra,ua)){const a=ra[i][1],b=ua[j][1];if(a.length!==b.length)continue;for(let k=0;k<a.length;k++)map.set(fr[i]+k,fu[j]+k);}
  return map;
}
const PUNCT=new Map([[0x80,'EUR'],[0x82,','],[0x85,'...'],[0x88,'^'],[0x89,'%'],[0x8b,'<'],[0x91,"'"],[0x92,"'"],[0x95,'*'],[0x96,'-'],[0x97,'-'],[0x98,'~'],[0x99,'TM'],[0x9b,'>'],[0xa0,' '],[0xa6,'|'],[0xa9,'(c)'],[0xab,'<<'],[0xad,'-'],[0xae,'(r)'],[0xb4,"'"],[0xb7,'.'],[0xbb,'>>'],[0xbd,'1/2'],[0xbc,'1/4'],[0xbe,'3/4'],[0xd7,'x'],[0xf7,'/']]);
const LIGA=new Map(Object.entries({'ß':'ss','æ':'ae','Æ':'AE','œ':'oe','Œ':'OE','ø':'o','Ø':'O','ð':'d','Ð':'D','þ':'th','Þ':'Th'}));
const DQUOTES=new Set([0x93,0x94,0x84]),UNDEFINED_1252=new Set([0x81,0x8d,0x8f,0x90,0x9d]);
export function to_game_ascii(raw,c_literal=true){
  raw=B(raw);if(!raw.some((x)=>x>=0x80))return raw;
  let out='';for(const x of raw){
    if(x<0x80)out+=String.fromCharCode(x);
    else if(DQUOTES.has(x))out+=c_literal?'\\"':"'";
    else if(PUNCT.has(x))out+=PUNCT.get(x);
    else {
      if(UNDEFINED_1252.has(x))throw new TextError(`byte 0x${x.toString(16)} has no safe ASCII replacement`);
      const ch=cp1252.decode(Uint8Array.of(x));
      if(LIGA.has(ch)){out+=LIGA.get(ch);continue;}
      const decomposed=ch.normalize('NFKD').replace(/\p{M}/gu,'');
      if(!decomposed||/[^\x00-\x7f]/u.test(decomposed)||ch==='\ufffd')throw new TextError(`byte 0x${x.toString(16)} has no safe ASCII replacement`);
      out+=decomposed;
    }
  }
  return Buffer.from(out,'ascii');
}
export function spec_tokens(raw,with_newlines=false){
  const s=asLatin(raw),tokens=[...s.matchAll(/%[-+#0]*\d*(?:\.\d+)?[sdfxXcuoeEgG%]|\{[^{}]*\}|#[A-Za-z_]+#/gu)].map((m)=>m[0]);
  if(with_newlines)tokens.push(...[...s.matchAll(/\\n/gu)].map(()=>String.raw`\n`));
  return tokens.sort().map(bytes);
}
export const is_ascii=(b)=>!B(b).some((x)=>x>=0x80);
const specEqual=(a,b,newlines=false)=>JSON.stringify(spec_tokens(a,newlines).map(asLatin))===JSON.stringify(spec_tokens(b,newlines).map(asLatin));
export function anchor_stats(ruRaw,usRaw,map){
  const rs=literal_spans(ruRaw),us=literal_spans(usRaw);let total=0,equal=0;
  for(const [i,j] of entries(map).map(([x,y])=>[Number(x),y])){
    if(i>=rs.length||j>=us.length)continue;
    const a=B(ruRaw).subarray(...rs[i]),b=B(usRaw).subarray(...us[j]);
    if(!has_cyr(a)&&!has_cyr(b)){total++;if(eq(a,b))equal++;}
  }
  return [total,equal];
}
export class FilePlan {
  constructor(rel){this.rel=rel;this.mode=null;this.n_lit=0;this.cyr_total=0;this.auto=new Map();this.manual=new Map();this.skipped=new Map();this.same=new Set();this.left_ru=[];this.nl_diff=0;this.anchors=[0,0];}
  changes(){return new Map([...this.auto,...this.manual]);}
}
export function plan_literals(rel,ruRaw,usRaw,{is_h=false,ru_c=null,us_c=null,manual=null,pair_overrides=null}={}){
  ruRaw=B(ruRaw);usRaw=usRaw===null?null:B(usRaw);
  const plan=new FilePlan(rel),spans=is_h?h_region_spans(ruRaw):literal_spans(ruRaw),rl=spans.map(([s,e])=>ruRaw.subarray(s,e));
  plan.n_lit=spans.length;plan.cyr_total=rl.filter(has_cyr).length;
  if(usRaw!==null){
    let map,usSpans;
    if(is_h){
      [map,plan.mode]=h_index_map(ruRaw,usRaw,ru_c,us_c);usSpans=h_region_spans(usRaw);
      for(const [i,j] of numericEntries(pair_overrides)){if(j===null)map.delete(i);else map.set(i,j);plan.mode+='+pairs';}
    }else{map=line_literal_map(ruRaw,usRaw);plan.mode='by_line_alignment';usSpans=literal_spans(usRaw);plan.anchors=anchor_stats(ruRaw,usRaw,map);}
    for(const [i,j] of [...map].sort(([a],[b])=>a-b)){
      if(i>=rl.length||j>=usSpans.length||!has_cyr(rl[i]))continue;
      const ul=usRaw.subarray(...usSpans[j]);
      if(eq(ul,rl[i])){plan.same.add(i);continue;}
      if(us_is_russian(ul)){plan.skipped.set(i,'us_russian');continue;}
      let next;try{next=quote(to_game_ascii(inner(ul)));}catch(e){if(!(e instanceof TextError))throw e;plan.skipped.set(i,'unsafe_text');continue;}
      if(!specEqual(inner(next),inner(rl[i]))){plan.skipped.set(i,'spec');continue;}
      if(!specEqual(inner(next),inner(rl[i]),true))plan.nl_diff++;
      plan.auto.set(i,next);
    }
  }else plan.mode='manual_only';
  for(const [i,[en,override]] of numericEntries(manual)){
    const value=B(en);if(i<0||i>=rl.length)throw new TextError(`${rel}: manual literal index ${i} out of range (${rl.length})`);
    if(plan.auto.has(i)&&!override)throw new TextError(`${rel}[${i}]: manual literal overrides automatic match without override`);
    if(!is_ascii(value))throw new TextError(`${rel}[${i}]: manual literal is not ASCII`);
    if(asLatin(value).replace(/\\./gsu,'').includes('"')||value.includes(10)||value.includes(13))throw new TextError(`${rel}[${i}]: manual literal contains an unescaped quote or newline`);
    if(!specEqual(value,inner(rl[i]),true))throw new TextError(`${rel}[${i}]: manual format specifiers do not match`);
    plan.manual.set(i,quote(value));plan.auto.delete(i);plan.skipped.delete(i);
  }
  const changes=plan.changes();plan.left_ru=rl.map((x,i)=>has_cyr(x)&&!changes.has(i)?i:-1).filter((i)=>i>=0);
  return plan;
}
export function render_literals(rel,ruRaw,plan,{is_h=false,check=true}={}){
  const spans=is_h?h_region_spans(ruRaw):literal_spans(ruRaw),changes=plan.changes(),out=splice(ruRaw,spans,changes);
  if(check)verify_skeleton(rel,ruRaw,out,{is_h,changed:changes});return out;
}
export function verify_skeleton(rel,ruRaw,newRaw,{is_h=false,changed=null}={}){
  ruRaw=B(ruRaw);newRaw=B(newRaw);
  const rs=is_h?h_region_spans(ruRaw):literal_spans(ruRaw),ns=is_h?h_region_spans(newRaw):literal_spans(newRaw);
  if(rs.length!==ns.length)throw new TextError(`${rel}: literal count changed (${rs.length} -> ${ns.length})`);
  const ra=literal_spans(ruRaw),na=literal_spans(newRaw);
  if(ra.length!==na.length)throw new TextError(`${rel}: total literal count changed`);
  if(!eq(outside(ruRaw,ra),outside(newRaw,na)))throw new TextError(`${rel}: code skeleton changed`);
  const changes=new Map(numericEntries(changed));
  for(let i=0;i<rs.length;i++){
    const a=ruRaw.subarray(...rs[i]),b=newRaw.subarray(...ns[i]);
    if(changes.has(i)){if(!eq(b,changes.get(i)))throw new TextError(`${rel}[${i}]: result differs from planned literal`);if(!is_ascii(b))throw new TextError(`${rel}[${i}]: replaced literal is not ASCII`);}
    else if(!eq(a,b))throw new TextError(`${rel}[${i}]: unplanned literal change`);
  }
  const row=(raw)=>scan(raw).map(([skel])=>asLatin(skel));
  if(JSON.stringify(row(ruRaw))!==JSON.stringify(row(newRaw)))throw new TextError(`${rel}: line skeleton changed`);
  return true;
}
export function verify_names_file(ruRaw,usRaw){
  const distinct=(raw)=>[...new Set(scan(raw).map(([skel])=>asLatin(skel)).filter(Boolean))],a=distinct(ruRaw),b=distinct(usRaw);
  const extra=b.filter((x)=>!a.includes(x)&&!/^Trace\(""\);$/u.test(x)),missing=a.filter((x)=>!b.includes(x));
  if(extra.length||missing.length)throw new TextError(`Characters_names.c: US code structure differs: ${extra.length} extra, ${missing.length} missing`);
  for(const [s,e] of literal_spans(usRaw))if(!is_ascii(B(usRaw).subarray(s,e)))throw new TextError('Characters_names.c: non-ASCII literal after normalization');
  return true;
}
export function normalize_names_file(raw){
  raw=B(raw);const spans=literal_spans(raw),repl=new Map();
  spans.forEach(([s,e],i)=>{const lit=raw.subarray(s,e);if(!is_ascii(lit)){if(us_is_russian(lit))throw new TextError('Characters_names.c: Russian text in US source');repl.set(i,quote(to_game_ascii(inner(lit))));}});
  return splice(raw,spans,repl);
}

export function parse_quests(raw){
  const text=asLatin(raw),eol=text.includes('\r\n')?Buffer.from('\r\n'):Buffer.from('\n'),lines=text.split('\n'),records=[];
  let current=null,quest=null;
  for(const line of lines){
    const s=line.endsWith('\r')?line.slice(0,-1):line;
    if(s.startsWith('#QUEST')){quest=bytes(trim(s.slice(6)));current={kind:'Q',quest,n:0,head:bytes(s),body:[]};records.push(current);}
    else if(s.startsWith('#TEXT')){
      const m=/^#TEXT[\x09-\x0d\x20]+(\d+)/u.exec(s);
      if(!m||quest===null)throw new TextError(`QUESTSTEXT: invalid header ${JSON.stringify(s.slice(0,40))}`);
      current={kind:'T',quest,n:Number(m[1]),head:bytes(s),body:[]};records.push(current);
    }else{if(current===null)throw new TextError('QUESTSTEXT: text before first header');current.body.push(bytes(s));}
  }
  return [records,eol];
}
export function quest_body(record){
  const body=[...record.body];while(body.length&&!trim(asLatin(body.at(-1))))body.pop();
  return Buffer.from(body.map(asLatin).join('\r\n'),'latin1');
}
export function quest_key(record){return `${cp1251.decode(B(record.quest))}#${record.n}`;}
export function build_quests(ruRaw,usRaw,manual=null){
  const pending=new Map(entries(manual)),[rr,eol]=parse_quests(ruRaw),ur=usRaw===null?[]:parse_quests(usRaw)[0];
  const key=(r)=>`${asLatin(r.quest)}\0${r.n}`,usMap=new Map(ur.map((r)=>[key(r),r]));
  const stats={records:rr.length,auto:0,manual:0,left_ru:[],skipped:{},nl_diff:0},out=[];
  for(const record of rr){
    const name=quest_key(record),old=quest_body(record),match=usMap.get(key(record));let next=null;
    if(match&&has_cyr(old)){
      const us=quest_body(match);
      if(us.length&&!eq(us,old)){
        if(us_is_russian(us))stats.skipped[name]='us_russian';
        else {
          let candidate=null;try{candidate=to_game_ascii(us,false);}catch(e){if(!(e instanceof TextError))throw e;stats.skipped[name]='unsafe_text';}
          if(candidate!==null){if(!specEqual(candidate,old))stats.skipped[name]='spec';else{next=candidate;stats.auto++;}}
        }
      }
    }
    if(pending.has(name)){
      const [en,override]=pending.get(name),value=B(en);pending.delete(name);
      if(next!==null&&!override)throw new TextError(`QUESTSTEXT ${name}: manual text overrides automatic match without override`);
      if(!is_ascii(value)||value.includes(13))throw new TextError(`QUESTSTEXT ${name}: manual text is not ASCII or contains CR`);
      if(!specEqual(value,old))throw new TextError(`QUESTSTEXT ${name}: manual format specifiers differ`);
      if(next!==null)stats.auto--;stats.manual++;next=value;
    }
    let body;
    if(next===null){if(has_cyr(old))stats.left_ru.push(name);body=record.body;}
    else {const s=asLatin(next),lines=s.includes('\r\n')?s.split('\r\n'):s.split('\n');body=lines.map(bytes);}
    out.push(record.head,...body);
  }
  if(pending.size)throw new TextError(`QUESTSTEXT: unused manual keys: ${[...pending.keys()].sort().join(', ')}`);
  return [Buffer.from(out.map(asLatin).join(asLatin(eol)),'latin1'),stats];
}
export function parse_text_entries(raw,is_ini){
  const s=asLatin(raw),out=[];
  if(is_ini){
    const re=/^(?<pre>[ \t]*string[ \t]*=[ \t]*)(?<key>[^,\r\n]+?)(?<mid>[ \t]*,[ \t]*")(?<val>.*?)(?<post>"[ \t]*)(?=\r?$)/gdmu;
    for(const m of s.matchAll(re))out.push([bytes(trim(m.groups.key)),m.indices.groups.val]);
    return out;
  }
  const re=/(?<key>[^\r\n{}]+?)[ \t]*\r?\n?[ \t]*\{(?<val>[^{}]*)\}/gdu;let pos=0;
  for(const m of s.matchAll(re)){
    const gap=s.slice(pos,m.index);if(trim(gap))throw new TextError(`TEXTS: unparsed fragment ${JSON.stringify(gap.slice(0,40))}`);
    pos=m.index+m[0].length;out.push([bytes(trim(m.groups.key)),m.indices.groups.val]);
  }
  if(trim(s.slice(pos)))throw new TextError(`TEXTS: unparsed tail ${JSON.stringify(s.slice(pos,pos+40))}`);
  return out;
}
function occurrenceKeys(ents){
  const count=new Map();return ents.map(([key,span])=>{const str=asLatin(key),n=count.get(str)||0;count.set(str,n+1);return [[key,n],span];});
}
export function build_text_file(rel,ruRaw,usRaw,{renames=null,manual=null}={}){
  ruRaw=B(ruRaw);usRaw=B(usRaw);
  const renameMap=new Map(entries(renames).map(([k,v])=>[Buffer.isBuffer(k)?asLatin(k):k,Buffer.isBuffer(v)?asLatin(v):v])),pending=new Map(entries(manual));
  const re=occurrenceKeys(parse_text_entries(ruRaw,rel.toLowerCase().endsWith('.ini'))),us=new Map();
  const occ=([k,n])=>`${asLatin(k)}\0${n}`;
  for(const [[key,n],[s,e]] of occurrenceKeys(parse_text_entries(usRaw,rel.toLowerCase().endsWith('.ini'))))us.set(occ([key,n]),usRaw.subarray(s,e));
  const stats={entries:re.length,auto:0,manual:0,renamed:0,same:0,len_ratio_hi:[]},out=[];let pos=0;
  for(const [[key,n],[s,e]] of re){
    const ruValue=ruRaw.subarray(s,e),name=cp1251.decode(key),oldKey=asLatin(key),usKey=us.has(occ([key,n]))?oldKey:(renameMap.get(oldKey)||oldKey);
    let next=us.get(`${usKey}\0${n}`)??null;
    if(next!==null&&usKey!==oldKey)stats.renamed++;
    if(pending.has(name)){
      const [en,override]=pending.get(name);pending.delete(name);
      if(next!==null&&!override)throw new TextError(`${rel} ${name}: manual text overrides US value without override`);
      next=B(en);if(!is_ascii(next))throw new TextError(`${rel} ${name}: manual text is not ASCII`);stats.manual++;
    }else if(next!==null&&has_cyr(ruValue)){next=to_game_ascii(next,false);stats.auto++;}
    else next=null;
    if(next===null){if(has_cyr(ruValue))throw new TextError(`${rel}: key ${JSON.stringify(name)} has no English pair or manual value`);next=ruValue;}
    if(!specEqual(next,ruValue))throw new TextError(`${rel} ${name}: format specifiers differ`);
    if(has_cyr(next))throw new TextError(`${rel} ${name}: Russian bytes in English value`);
    if(next.length>30&&next.length/Math.max(ruValue.length,1)>1.6)stats.len_ratio_hi.push(name);
    out.push(ruRaw.subarray(pos,s),next);pos=e;
  }
  out.push(ruRaw.subarray(pos));if(pending.size)throw new TextError(`${rel}: unused manual keys: ${[...pending.keys()].sort().join(', ')}`);
  return [Buffer.concat(out),stats];
}
