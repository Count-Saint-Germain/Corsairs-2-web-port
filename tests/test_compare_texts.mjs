import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {parseText,compareSets,parseQuests} from '../english-audit/compare_texts.mjs';
import {decode1251,stripComments} from '../english-audit/text_utils.mjs';
function fixture(t){const d=fs.mkdtempSync(path.join(os.tmpdir(),'k2-texts-'));t.after(()=>fs.rmSync(d,{recursive:true,force:true}));return d;}
test('decodes legacy CP1251 and preserves strings when removing comments',()=>{assert.equal(decode1251(Buffer.from([0xcf,0xf0,0xe8,0xe2,0xe5,0xf2])),'Привет');assert.equal(stripComments('x="//literal"; //comment\ny=1; /*skip*/ z=2;'),'x="//literal"; \ny=1;  z=2;');});
test('compares resource keys, ordering and placeholders',t=>{const root=fixture(t),a=path.join(root,'a'),b=path.join(root,'b');fs.mkdirSync(a);fs.mkdirSync(b);fs.writeFileSync(path.join(a,'common.ini'),'string = greeting,"Hello %s"\nstring = item,"Gold"\n');fs.writeFileSync(path.join(b,'COMMON.INI'),'string = item,"Gold"\nstring = greeting,"Hi %d"\n');const r=compareSets('sample',a,b);assert.equal(r.tot.files,1);assert.equal(r.tot.same_keys,1);assert.equal(r.tot.ph_mismatch,1);assert.match(r.rows[0][7],/order=diff/);});
test('parses brace entries and quest text identifiers',t=>{const root=fixture(t),file=path.join(root,'dialog.txt'),quest=path.join(root,'quests.txt');fs.writeFileSync(file,'hello { first }\nhello { second }\n');fs.writeFileSync(quest,'#QUEST A\n#TEXT 1\nbody\n#TEXT 2\n');const p=parseText(file);assert.equal(p.entries.get('hello'),'first');assert.equal(p.entries.get('hello#dup'),'second');assert.deepEqual([...parseQuests(quest)],[JSON.stringify(['A',0]),JSON.stringify(['A',1]),JSON.stringify(['A',2])]);});
