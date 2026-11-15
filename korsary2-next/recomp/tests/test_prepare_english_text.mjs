/** End-to-end synthetic E2 text overlay checks, with no original game data. */
import {test} from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {Tree,Manual,Leftovers,sha256,Fail} from '../../tools/prepare_english_core.mjs';
import {build_overlay,build_language_ini,build_fonts_ini} from '../../tools/prepare_english_text.mjs';
import * as et from '../../tools/english_text.mjs';
import {setup} from './prepare_english_fixture.mjs';
test('builds text classes with unchanged code skeleton and base hash metadata',(t)=>{
 const x=setup(t),res=build_overlay(x.base,x.en,new Manual(x.manualPath));
 const alpha=res.files['PROGRAM/DIALOGS/Alpha_dialog.h'];assert.ok(alpha.includes(Buffer.from('Hello, ')));assert.ok(alpha.includes(Buffer.from("Don't worry!")));
 assert.ok(res.files['PROGRAM/Only_ru.c'].includes(Buffer.from('Russian only')));
 const info=res.info['PROGRAM/DIALOGS/Alpha_dialog.h'];assert.equal(info.cls,'align');assert.equal(info.base_sha256,sha256(x.base.get('PROGRAM/DIALOGS/Alpha_dialog.h')));
 const meta=JSON.parse(res.files['OVERLAY.json']);assert.equal(meta.format,1);assert.equal(meta.language,'English');assert.equal(meta.base['PROGRAM/DIALOGS/Alpha_dialog.h'],info.base_sha256);
});
test('retains original Russian keys while applying US text and manual values',(t)=>{
 const x=setup(t),res=build_overlay(x.base,x.en,new Manual(x.manualPath));
 const common=res.files['RESOURCE/INI/TEXTS/ENGLISH/common.ini'].toString('latin1');assert.ok(common.includes('string = Brightness,"Brightness"'));assert.ok(common.includes('Hello %s'));
 const items=res.files['RESOURCE/INI/TEXTS/ENGLISH/ItemsDescribe.txt'].toString('latin1');assert.ok(items.includes('youve_got {You found}'));
 const quests=res.files['RESOURCE/QUESTSTEXT/quests_texts.txt'].toString('latin1');assert.ok(quests.includes('#QUEST\tq2\r\nNew\r\n#TEXT\t1\r\nText %s'));
});
test('rejects changed manual source SHA, duplicate or unused manual entry',(t)=>{
 const x=setup(t);x.manual[0].ru_sha256='0'.repeat(64);x.writeManual();assert.throws(()=>build_overlay(x.base,x.en,new Manual(x.manualPath)),/drift/);
 x.manual[0].ru_sha256='a'.repeat(64);x.manual.push({...x.manual[0]});x.writeManual();assert.throws(()=>new Manual(x.manualPath),/duplicate/);
});
test('rejects wrong manual format specifiers and missing override',(t)=>{
 const x=setup(t);x.manual.find((e)=>e.key==='q2#1').en='Text %d';x.writeManual();assert.throws(()=>build_overlay(x.base,x.en,new Manual(x.manualPath)),/specifier/);
});
test('rejects missing language/font data and an incompatible title font',(t)=>{
 const x=setup(t),base=new Tree(),usTree=new Tree(),res={files:{},info:{}};
 assert.throws(()=>build_language_ini(base,usTree,res),Fail);assert.throws(()=>build_fonts_ini(base,usTree,res),Fail);
 const font='RESOURCE/INI/fonts.ini';base.add(font,x.base.get(font));usTree.add(font,Buffer.from('[INTERFACE_TITLE]\r\nTexture = bad.tga\r\n'));assert.throws(()=>build_fonts_ini(base,usTree,res),/unexpected/);
});
test('metadata JSON uses Python-compatible ASCII escaping for unusual paths',async(t)=>{
 const {refresh_meta}=await import('../../tools/prepare_english_text.mjs');const r={files:{'PROGRAM/Тест😀.c':Buffer.from('x')},info:{'PROGRAM/Тест😀.c':{base_sha256:'f'.repeat(64)}}};refresh_meta(r);
 assert.ok([...r.files['OVERLAY.json']].every((x)=>x<128));assert.equal(JSON.parse(r.files['OVERLAY.json']).base['PROGRAM/Тест😀.c'],'f'.repeat(64));
});
test('unmatched Russian literals must be classified and source hash protected',(t)=>{
 const x=setup(t);x.manual.splice(x.manual.findIndex(e=>e.file==='PROGRAM/Only_ru.c'),1);x.writeManual();const without=build_overlay(x.base,x.en,new Manual(x.manualPath));const target=without.left.find(e=>e.file==='PROGRAM/Only_ru.c');assert.ok(target);const entries=without.left.map(e=>({file:e.file,...(Object.hasOwn(e,'index')?{index:e.index}:{key:e.key}),ru_sha256:e.ru_sha256,class:'identifier',why:'used as a key'}));const lp=path.join(x.dir,'leftover-classes.json');const write=()=>fs.writeFileSync(lp,JSON.stringify({format:1,entries}));write();const correct=build_overlay(x.base,x.en,new Manual(x.manualPath),new Leftovers(lp));assert.ok(correct.left.every(e=>e.class==='identifier'));entries[0].ru_sha256='0'.repeat(64);write();assert.throws(()=>build_overlay(x.base,x.en,new Manual(x.manualPath),new Leftovers(lp)),/drift/);entries.pop();write();assert.throws(()=>build_overlay(x.base,x.en,new Manual(x.manualPath),new Leftovers(lp)),/unclassified|drift/);
});
test('manual drift and unused entries fail before output is produced',(t)=>{
 const x=setup(t);x.manual.find(e=>e.kind==='quest').ru_sha256='0'.repeat(64);x.writeManual();assert.throws(()=>build_overlay(x.base,x.en,new Manual(x.manualPath)),/drift/);
 const y=setup(t);y.manual.push({file:'PROGRAM/missing.c',kind:'literal',index:0,ru_sha256:'f'.repeat(64),en:'unused'});y.writeManual();assert.throws(()=>build_overlay(y.base,y.en,new Manual(y.manualPath)),/unused|not used|do not match/);
});
test('build is deterministic with all text output bound to source hashes',(t)=>{
 const x=setup(t),a=build_overlay(x.base,x.en,new Manual(x.manualPath)),b=build_overlay(x.base,x.en,new Manual(x.manualPath));assert.deepEqual(a.files,b.files);const meta=JSON.parse(a.files['OVERLAY.json']);for(const [rel,hash] of Object.entries(meta.base)){const base=x.base.get(rel);assert.ok(base);assert.equal(hash,sha256(base));}for(const data of Object.values(a.files))assert.notDeepEqual(data.subarray(0,3),Buffer.from([0xef,0xbb,0xbf]));
});
