/** Validate overlay text structure, resource formats, and source bindings. */
import * as et from './english_text.mjs';
import * as ea from './english_assets.mjs';
import {Tree,sha256} from './prepare_english_core.mjs';
import {NAMES_FILE,QUESTS,TEXTS_EN,TEXTS_RU,LANG_INI,FONTS_INI} from './prepare_english_text.mjs';
import {LOADING_DIR,WORLDMAP_DIR,VOICE_DIR,GREETINGS,published_view} from './prepare_english_resources.mjs';
const same=(a,b)=>Buffer.from(a).equals(Buffer.from(b)),equal=(a,b)=>JSON.stringify(a)===JSON.stringify(b);
export function verify_resources(base,files,bulk=null,rules=ea.DEFAULT_RELOCATE){
 const problems=[],pubs=new Map();function pub(p){if(!pubs.has(p))pubs.set(p,published_view(bulk,rules,p));return pubs.get(p);}
 function base_file(rel){const n=base.name(rel);if(n!==null)return [n,base.get(rel)];if(!bulk)return null;for(const d of [LOADING_DIR,WORLDMAP_DIR])if(rel.toUpperCase().startsWith(d.toUpperCase()+'/')){const e=pub(d).get(rel.toLowerCase());return e?[e[0],bulk.read(e[1])]:null;}const b=bulk.name(rel);return b?[b,bulk.read(b)]:null;}
 for(const [rel,data] of Object.entries(files).sort(([a],[b])=>a<b?-1:a>b?1:0)){if(rel==='OVERLAY.json')continue;const u=rel.toUpperCase(),parts=rel.split('/');if(!['PROGRAM','RESOURCE'].includes(parts[0].toUpperCase())||parts.includes('..')||parts.includes('')||rel.includes('\\')){problems.push(`unsafe path: ${rel}`);continue;}
  try{if(u.startsWith('RESOURCE/TEXTURES/')&&u.endsWith('.TX')){const ui=ea.parse_tx(data);let bf=bulk?base_file(rel):null;if(!bf&&bulk&&u.startsWith(WORLDMAP_DIR.toUpperCase()+'/')){const rr=bulk.name(`${WORLDMAP_DIR}/Russian/${parts.at(-1)}`);if(rr)bf=[null,bulk.read(rr)];}if(bf){if(bf[0]!==null&&bf[0]!==rel)problems.push(`path spelling differs: ${rel} / ${bf[0]}`);if(!ea.same_layout(ui,ea.parse_tx(bf[1])))problems.push(`texture layout differs: ${rel}`);}}
   else if(u.startsWith(VOICE_DIR.toUpperCase()+'/')&&u.endsWith('.WAV')){ea.parse_wav(data);const bf=bulk?base_file(rel):null;if(bf&&bf[0]!==rel)problems.push(`path spelling differs: ${rel} / ${bf[0]}`);}
   else if(u===GREETINGS&&bulk?.has(GREETINGS))for(const p of ea.alias_compat(bulk.read(GREETINGS),data))problems.push(`${rel}: ${p}`);
  }catch(e){if(e instanceof ea.AssetError)problems.push(`${rel}: ${e.message}`);else throw e;}
 }
 if(Object.hasOwn(files,'OVERLAY.json'))try{const meta=JSON.parse(files['OVERLAY.json'].toString('utf8'));if(!meta.base||typeof meta.base!=='object'||Array.isArray(meta.base))throw Error('missing base bindings');for(const [rel,h] of Object.entries(meta.base)){if(!Object.hasOwn(files,rel)){problems.push(`OVERLAY.json: missing overlay file ${rel}`);continue;}const bf=base_file(rel);if(bf&&sha256(bf[1])!==h)problems.push(`OVERLAY.json: invalid base hash for ${rel}`);}for(const rel of Object.keys(files).sort())if(rel!=='OVERLAY.json'&&!Object.hasOwn(meta.base,rel)&&base_file(rel))problems.push(`OVERLAY.json: missing base hash for ${rel}`);}catch(e){problems.push(`OVERLAY.json cannot be read: ${e.message}`);}
 return problems;
}
export function verify_payload(base,files,bulk=null,rules=ea.DEFAULT_RELOCATE){
 const problems=[],tree=new Tree();for(const [rel,data] of Object.entries(files))if(rel!=='OVERLAY.json')tree.add(rel,data);
 for(const k of tree.keys()){const [rel,data]=tree.f.get(k);try{if(data.subarray(0,3).equals(Buffer.from([0xef,0xbb,0xbf])))throw new et.TextError('unexpected UTF-8 BOM');const rb=base.get(rel);
  if(k.startsWith('PROGRAM/')){if(rb===null)continue;if(k===NAMES_FILE)et.verify_names_file(rb,data);else{const ns=et.literal_spans(data),rs=et.literal_spans(rb),changed=new Map();for(let i=0;i<Math.min(ns.length,rs.length);i++){const d=data.subarray(...ns[i]),r=rb.subarray(...rs[i]);if(!same(d,r))changed.set(i,d);}et.verify_skeleton(rel,rb,data,{changed});for(const [i,d] of changed)if(!equal(et.spec_tokens(et.inner(d)),et.spec_tokens(et.inner(rb.subarray(...rs[i])))))throw new et.TextError(`${rel}: format specifiers changed`);}
   const count=(b,n)=>b.toString('latin1').split(n).length-1;if(count(data,'\n')&&count(data,'\r\n')!==count(data,'\n')&&count(rb,'\r\n')===count(rb,'\n'))throw new et.TextError(`${rel}: line endings changed`);
  }else if(k===QUESTS){const rr=et.parse_quests(rb)[0],nr=et.parse_quests(data)[0];if(!equal(rr.map((x)=>[x.head.toString('hex'),x.quest.toString('hex'),x.n]),nr.map((x)=>[x.head.toString('hex'),x.quest.toString('hex'),x.n])))throw new et.TextError('QUESTSTEXT: headers changed');for(let i=0;i<rr.length;i++){const a=et.quest_body(rr[i]),b=et.quest_body(nr[i]);if(!same(a,b)&&(!et.is_ascii(b)||!equal(et.spec_tokens(a),et.spec_tokens(b))))throw new et.TextError(`QUESTSTEXT ${et.quest_key(rr[i])}: non-ASCII or changed specifiers`);}}
  else if(k.startsWith(TEXTS_EN)){const sub=rel.slice(TEXTS_EN.length),raw=base.get(TEXTS_RU+sub);if(raw===null)continue;const ini=sub.toLowerCase().endsWith('.ini'),a=et.parse_text_entries(raw,ini),b=et.parse_text_entries(data,ini);if(!equal(a.map(([x])=>x.toString('hex')),b.map(([x])=>x.toString('hex'))))throw new et.TextError(`${sub}: keys changed`);for(let i=0;i<a.length;i++){const x=raw.subarray(...a[i][1]),y=data.subarray(...b[i][1]);if(et.has_cyr(y)||!equal(et.spec_tokens(x),et.spec_tokens(y)))throw new et.TextError(`${sub}: Cyrillic or changed specifiers`);}}
  else if(k===LANG_INI){const s=data.toString('latin1');if(!/^defaultLanguage\s*=\s*English\s*$/m.test(s)||/^defaultLanguage\s*=\s*russian/im.test(s))throw new et.TextError('language.ini: English is not active');}
  else if(k===FONTS_INI&&rb!==null&&data.length!==rb.length+Buffer.byteLength('menu font.tga')-Buffer.byteLength('menu font rus.tga'))throw new et.TextError('fonts.ini: size mismatch');
 }catch(e){if(e instanceof et.TextError)problems.push(e.message);else throw e;}}
 return problems.concat(verify_resources(base,files,bulk,rules));
}
