import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {Tree,sha256} from '../../tools/prepare_english_core.mjs';
import * as et from '../../tools/english_text.mjs';
const dec=new TextDecoder('windows-1251'),map=new Map(Array.from({length:256},(_,i)=>[dec.decode(Uint8Array.of(i)),i]));
function ru(s){const out=[];for(const c of s.replace(/\r?\n/g,'\r\n')){if(!map.has(c))throw Error(`cannot encode ${c}`);out.push(map.get(c));}return Buffer.from(out);}
function us(s){const out=[];for(const c of s.replace(/\r?\n/g,'\r\n')){if(c.codePointAt(0)<256)out.push(c.codePointAt(0));else if(map.has(c))out.push(map.get(c));else throw Error(`cannot encode ${c}`);}return Buffer.from(out);}
export function setup(t){
 const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-en-text-'));t.after(()=>fs.rmSync(dir,{recursive:true,force:true}));const base=new Tree(),en=new Tree();
 const alphaRu='string DLG_TEXT[5] = {\n"Привет, ",\n"друг!\\nКак дела? %s",\n"Отлично.",\n"Ёлки-палки!",\n"..."\n};\n';
 const alphaUs='string DLG_TEXT[5] = {\n"Hello, ",\n"friend!\\nHow are you? %s",\n"Fine.",\n"Don\x92t worry!",\n"..."\n};\n';
 const alphaC='#include "DIALOGS\\Alpha_dialog.h"\nvoid ProcessDialogEvent()\n{\n link.l1 = DLG_TEXT[0];\n link.l2 = DLG_TEXT[1];\n link.l3 = DLG_TEXT[2];\n link.l4 = DLG_TEXT[3];\n link.l5 = DLG_TEXT[4];\n}\n';
 const betaRu='string DLG_TEXT[4] = {\n"Да.",\n"Нет.",\n"Дополнительно раз.",\n"Дополнительно два."\n};\n';
 const betaUs='string DLG_TEXT[2] = {\n"Yes.",\n"No."\n};\n';
 const betaC='void ProcessDialogEvent()\n{\n link.l1 = DLG_TEXT[0];\n link.l2 = DLG_TEXT[1];\n}\n';
 const betaCRu=betaC.replace('}\n',' link.l3 = DLG_TEXT[2];\n link.l4 = DLG_TEXT[3];\n}\n');
 const namesRu='void InitCharactersNames()\n{\n int n;\n n = AddStr2Array(&sEnManNames, n, "Абель,Адам");\n}\n';
 const namesUs='void InitCharactersNames()\n{\n int n;\n n = AddStr2Array(&sEnManNames, n, "Abel,Adam");\n n = AddStr2Array(&sEnManNames, n, "Fran\xe7ois,Bart");\n Trace("Init complete.");\n}\n';
 const langRu=';\n[COMMON]\n;defaultLanguage = English\ndefaultLanguage = russian\n[LANGUAGE]\nEnglish = common.ini\nRussian = common.ini\n';
 const langUs=';\n[COMMON]\ndefaultLanguage = English\n;defaultLanguage = russian\n[LANGUAGE]\nEnglish = common.ini\nRussian = common.ini\n';
 const fontsRu='[NORMAL]\nTexture = fonts\\normal rus.tga\nHeight = 26\npcscale = 0.7\n\n[INTERFACE_TITLE]\nTexture = fonts\\menu font rus.tga\nHeight = 30\n';
 const fontsUs='[NORMAL]\nTexture = fonts\\normal rus.tga\nHeight = 26\n\n[INTERFACE_TITLE]\nTexture = fonts\\menu font.tga\nHeight = 30\n';
 const commonRu='; ini\nstring = titleA,"ЗАГОЛОВОК"\nstring = Brightness,"Яркость"\nstring = Hello,"Привет %s"\n';
 const commonUs='; ini\nstring = titleA,"TITLE"\nstring = Hello,"Hello %s"\n';
 const questsRu='#QUEST\tq1\nЗаголовок\n#TEXT\t1\nТекст один\n#QUEST\tq2\nНовый\n#TEXT\t1\nТекст %s\n';
 const questsUs='#QUEST\tq1\nTitle\n#TEXT\t1\nText one\n\n\n';
 const itemsRu='youve_got {Добавился предмет}\n\nitmname_gold {Золото}\n';
 const itemsUs="you've_got {You found}\n\nitmname_gold {Gold}\n";
 const data={
  'PROGRAM/DIALOGS/Alpha_dialog.h':[ru(alphaRu),us(alphaUs)],'PROGRAM/DIALOGS/Alpha_dialog.c':[ru(alphaC),us(alphaC)],
  'PROGRAM/DIALOGS/Beta_dialog.h':[ru(betaRu),us(betaUs)],'PROGRAM/DIALOGS/Beta_dialog.c':[ru(betaCRu),us(betaC)],
  'PROGRAM/Only_ru.c':[ru('void Only()\n{\n string s = "Только по-русски";\n string k = "key";\n}\n'),null],
  'PROGRAM/Characters/Characters_names.c':[ru(namesRu),us(namesUs)],
  'RESOURCE/INI/TEXTS/language.ini':[ru(langRu),us(langUs)],'RESOURCE/INI/fonts.ini':[ru(fontsRu),us(fontsUs)],
  'RESOURCE/INI/TEXTS/RUSSIAN/common.ini':[ru(commonRu),null],'RESOURCE/INI/TEXTS/ENGLISH/common.ini':[us(commonUs),us(commonUs)],
  'RESOURCE/INI/TEXTS/RUSSIAN/ItemsDescribe.txt':[ru(itemsRu),null],'RESOURCE/INI/TEXTS/ENGLISH/ItemsDescribe.txt':[us(itemsUs),us(itemsUs)],
  'RESOURCE/QUESTSTEXT/quests_texts.txt':[ru(questsRu),us(questsUs)],
 };
 for(const [name,[r,u]] of Object.entries(data)){base.add(name,r);if(u)en.add(name,u);}
 const litsha=(file,index,header=false)=>{const raw=base.get(file),spans=header?et.h_region_spans(raw):et.literal_spans(raw),[s,e]=spans[index];return sha256(raw.subarray(s+1,e-1));};
 const questRecords=new Map(et.parse_quests(base.get('RESOURCE/QUESTSTEXT/quests_texts.txt'))[0].map((r)=>[et.quest_key(r),et.quest_body(r)]));
 const common=base.get('RESOURCE/INI/TEXTS/RUSSIAN/common.ini');const brightness=et.parse_text_entries(common,true).find(([key])=>key.toString()==='Brightness')[1];
 const manual=[
  {file:'PROGRAM/DIALOGS/Beta_dialog.h',kind:'literal',index:2,ru_sha256:litsha('PROGRAM/DIALOGS/Beta_dialog.h',2,true),en:'Extra one.'},
  {file:'PROGRAM/DIALOGS/Beta_dialog.h',kind:'literal',index:3,ru_sha256:litsha('PROGRAM/DIALOGS/Beta_dialog.h',3,true),en:'Extra two.'},
  {file:'PROGRAM/Only_ru.c',kind:'literal',index:0,ru_sha256:litsha('PROGRAM/Only_ru.c',0),en:'Russian only'},
  {file:'RESOURCE/QUESTSTEXT/quests_texts.txt',kind:'quest',key:'q2#0',ru_sha256:sha256(questRecords.get('q2#0')),en:'New'},
  {file:'RESOURCE/QUESTSTEXT/quests_texts.txt',kind:'quest',key:'q2#1',ru_sha256:sha256(questRecords.get('q2#1')),en:'Text %s'},
  {file:'RESOURCE/INI/TEXTS/ENGLISH/common.ini',kind:'text_key',key:'Brightness',ru_sha256:sha256(common.subarray(...brightness)),en:'Brightness'},
 ];
 const manualPath=path.join(dir,'manual.json'),writeManual=()=>fs.writeFileSync(manualPath,JSON.stringify({format:1,entries:manual}));writeManual();
 return {base,en,manual,manualPath,writeManual,dir};
}
