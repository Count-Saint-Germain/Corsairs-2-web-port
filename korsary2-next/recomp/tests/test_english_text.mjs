import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import * as et from '../../tools/english_text.mjs';
const cpDecoder=new TextDecoder('windows-1251');
const cpMap=new Map(Array.from({length:256},(_,i)=>[cpDecoder.decode(Uint8Array.of(i)),i]));
function ru(text){const bytes=[];for(const c of text.replace(/\r?\n/g,'\r\n')){const n=cpMap.get(c);if(n===undefined)throw Error(`cannot encode CP1251: ${c}`);bytes.push(n);}return Buffer.from(bytes);}
function us(text){const bytes=[];for(const c of text.replace(/\r?\n/g,'\r\n')){const n=c.codePointAt(0);if(n<256)bytes.push(n);else if(cpMap.has(c))bytes.push(cpMap.get(c));else throw Error(`cannot encode: ${c}`);}return Buffer.from(bytes);}
const str=(b)=>b.toString('latin1');
const hru='string DLG_TEXT[4] = {\n"Да.",\n"Нет.",\n"Дополнительно раз.",\n"Дополнительно два."\n};\n';
const hus='string DLG_TEXT[2] = {\n"Yes.",\n"No."\n};\n';
const cru='void ProcessDialogEvent()\n{\n\tlink.l1 = DLG_TEXT[0];\n\tlink.l2 = DLG_TEXT[1];\n\tswitch (x)\n\t{\n\t\tcase "extra":\n\t\t\tlink.l3 = DLG_TEXT[2];\n\t\t\tlink.l4 = DLG_TEXT[3];\n\t\tbreak;\n\t}\n}\n';
const cus='void ProcessDialogEvent()\n{\n\tlink.l1 = DLG_TEXT[0];\n\tlink.l2 = DLG_TEXT[1];\n\tswitch (x)\n\t{\n\t}\n}\n';
test('scanner skips comments, handles escapes and retains byte offsets',()=>{
 const raw=ru('a = "Привет"; // "не строка"\n/* "и это" */ b = "x\\"y";\nc = "незакрытая\n');
 assert.deepEqual(et.literal_spans(raw).map(([s,e])=>raw.subarray(s,e)),[ru('"Привет"'),Buffer.from('"x\\"y"')]);
});
test('normalizes CP1252 to safe ASCII and rejects unsupported bytes',()=>{
 assert.equal(str(et.to_game_ascii(Buffer.from("Don\x92t \x85 ok \x96 caf\xe9 Fran\xe7ois Pe\xf1a",'latin1'))),"Don't ... ok - cafe Francois Pena");
 assert.equal(str(et.to_game_ascii(Buffer.from('\x93hi\x94','latin1'))),'\\"hi\\"');
 assert.equal(str(et.to_game_ascii(Buffer.from('\x93hi\x94','latin1'),false)),"'hi'");
 assert.throws(()=>et.to_game_ascii(Buffer.from([0xa4])),et.TextError);
});
test('extracts format tokens and escaped newlines without treating percentages as tokens',()=>{
 const tokens=(v,n=false)=>et.spec_tokens(Buffer.from(v),n).map(str);
 assert.deepEqual(tokens('a %s b %d %%'),['%%','%d','%s']);assert.deepEqual(tokens('25% chance, 5% bonus'),[]);
 assert.deepEqual(tokens('x #ddmg_min# {hp}'),['#ddmg_min#','{hp}']);assert.deepEqual(tokens(String.raw`a\nb`,true),[String.raw`\n`]);
});
test('verifies skeleton and rejects code changes, extra and non-ASCII literals',()=>{
 const raw=ru('x = foo("Привет");\ny = 1;\n'), span=et.literal_spans(raw)[0], good=et.splice(raw,[span],new Map([[0,Buffer.from('"Hi"')]]));
 assert.ok(et.verify_skeleton('f.c',raw,good,{changed:new Map([[0,Buffer.from('"Hi"')]])}));
 assert.throws(()=>et.verify_skeleton('f.c',raw,Buffer.from(good.toString('latin1').replace('y = 1','y = 2'),'latin1'),{changed:new Map([[0,Buffer.from('"Hi"')]])}),et.TextError);
 assert.throws(()=>et.verify_skeleton('f.c',raw,Buffer.concat([good,Buffer.from('z = "q";\n')]),{changed:new Map([[0,Buffer.from('"Hi"')]])}),et.TextError);
 const bad=ru('"Привёт"');assert.throws(()=>et.verify_skeleton('f.c',raw,et.splice(raw,[span],new Map([[0,bad]])),{changed:new Map([[0,bad]])}),et.TextError);
});
test('plans substitutions, preserves Russian matches and enforces format tokens',()=>{
 const rb=ru('a = "Всё %s";\nb = "Ещё";\nc = "Ничего";\nd = "Просто";\n');
 const ub=us('a = "All %d";\nb = "Ещё";\nc = "Ничего";\nd = "Simply";\n');
 const p=et.plan_literals('f.c',rb,ub);assert.deepEqual([...p.auto.keys()],[3]);assert.deepEqual([...p.skipped],[[0,'spec']]);assert.deepEqual([...p.same],[1,2]);assert.deepEqual(p.left_ru,[0,1,2]);
 const out=et.render_literals('f.c',rb,p);assert.ok(str(out).includes('d = "Simply";'));
 const p2=et.plan_literals('f.c',ru('a = "Привет";\n'),ru('a = "Здравствуй";\n'));assert.deepEqual([...p2.skipped],[[0,'us_russian']]);
});
test('manual literal replacement enforces override, ASCII, escaping and specifiers',()=>{
 const r=ru('x = "Привет %s";\n'), u=us('x = "Hello %s";\n');
 assert.throws(()=>et.plan_literals('f.c',r,u,{manual:new Map([[0,[Buffer.from('Hi %s'),false]]])}),/override/);
 const p=et.plan_literals('f.c',r,u,{manual:new Map([[0,[Buffer.from('Hi %s'),true]]])});assert.ok(str(et.render_literals('f.c',r,p)).includes('Hi %s'));
 for(const value of [Buffer.from('Hi %d'),Buffer.from('Hi "you" %s'),Buffer.from([0xff])])assert.throws(()=>et.plan_literals('f.c',r,null,{manual:new Map([[0,[value,false]]])}),et.TextError);
});
test('aligns header indexes through .c references without inventing pairs',()=>{
 const [map,mode,nr,nu]=et.h_index_map(ru(hru),us(hus),ru(cru),us(cus));assert.equal(mode,'by_c_alignment');assert.equal(nr,4);assert.equal(nu,2);assert.deepEqual([...map],[[0,0],[1,1]]);
});
test('quest replacement keeps Russian headers and uses manual fallbacks',()=>{
 const rr=ru('#QUEST\tq1\nЗаголовок один\n#TEXT\t1\nТекст один\n#QUEST\tq2\nНовый\n#TEXT\t1\nТекст %s\n');
 const uu=us('#QUEST\tq1\nTitle one\n#TEXT\t1\nText one\n\n\n');
 const [out,stats]=et.build_quests(rr,uu,new Map([['q2#0',[Buffer.from('New'),false]],['q2#1',[Buffer.from('Text %s'),false]]]));
 assert.deepEqual(out.toString('latin1').split('\r\n').slice(0,2),['#QUEST\tq1','Title one']);assert.equal(stats.auto,2);assert.equal(stats.manual,2);assert.deepEqual(stats.left_ru,[]);
});
test('text file matches duplicate keys, renames and manual values',()=>{
 const r=ru('; ini file\nstring = titleA,"ЗАГОЛОВОК"\nstring = Brightness, "Яркость"\nstring = Hello,"Привет %s"\nstring = Dup,"Один"\nstring = Dup,"Два"\n');
 const u=us('; ini file\nstring = titleA,"TITLE"\nstring = Hello,"Hello %s"\nstring = Dup,"One"\nstring = Dup,"Two"\n');
 const [out]=et.build_text_file('common.ini',r,u,{manual:new Map([['Brightness',[Buffer.from('Brightness'),false]]])});const text=str(out);
 for(const fragment of ['string = Dup,"One"','string = Dup,"Two"','string = Hello,"Hello %s"'])assert.ok(text.includes(fragment));
 const [out2,stats]=et.build_text_file('ItemsDescribe.txt',ru('youve_got {Добавился предмет}\n'),us("you've_got {You found}\n"),{renames:new Map([[Buffer.from('youve_got'),Buffer.from("you've_got")]])});
 assert.ok(str(out2).includes('youve_got {You found}'));assert.equal(stats.renamed,1);
 assert.throws(()=>et.build_text_file('common.ini',r,u),et.TextError);
});
test('stored save confirmation overrides build correctly',()=>{
 const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..'),doc=JSON.parse(fs.readFileSync(path.join(root,'english-layer/manual-strings.json'),'utf8'));
 const expected=new Map([['Delete savefile confirm','Are you sure you want to delete this saved game?'],['Overwrite savefile confirm','Are you sure you want to overwrite this saved game?'],['Load game confirm','Are you sure you want to load this game?'],['New game confirm','Are you sure you want to start a new game?'],['Low storage and unable save create','There is not enough storage space to create a save in this slot.']]);
 const entries=doc.entries.filter((e)=>e.file==='RESOURCE/INI/TEXTS/ENGLISH/interface_strings.txt'&&expected.has(e.key));assert.equal(entries.length,5);
 const russian=ru([...expected.keys()].map((k)=>`${k}{Тест}\n`).join('')),english=us([...expected.keys()].map((k)=>`${k}{old value}\n`).join(''));
 const [out,stats]=et.build_text_file('interface_strings.txt',russian,english,{manual:new Map(entries.map((e)=>[e.key,[Buffer.from(e.en),e.override]]))});
 for(const [k,v] of expected)assert.ok(str(out).includes(`${k}{${v}}`));assert.equal(stats.manual,5);
});
