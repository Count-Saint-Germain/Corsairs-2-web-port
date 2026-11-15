import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';import os from 'node:os';import path from 'node:path';
import {compareDialogs,parseCode,parseHeader} from '../english-audit/compare_dialogs.mjs';
test('classifies matching dialogue code and differing literal counts',t=>{
 const tmp=fs.mkdtempSync(path.join(os.tmpdir(),'k2-dialog-'));t.after(()=>fs.rmSync(tmp,{recursive:true,force:true}));
 for(const side of ['ru','us'])fs.mkdirSync(path.join(tmp,side,'DIALOGS'),{recursive:true});
 const write=(side,n,s)=>fs.writeFileSync(path.join(tmp,side,'DIALOGS',n),s);
 write('ru','npc.h','string DLG_TEXT[2] = {"one", "two"};');write('us','NPC.h','string DLG_TEXT[2] = {"uno", "dos"};');
 write('ru','npc.c','// comment\nchar *x="Node"; Show(DLG_TEXT[0]);');write('us','NPC.c','/* comment */\nchar *x="Node"; Show(DLG_TEXT[0]);');
 write('ru','only.h','string DLG_TEXT[1] = {"x"};');
 const h=parseHeader(path.join(tmp,'ru','DIALOGS','npc.h'));assert.equal(h.declared,2);assert.equal(h.count,2);
 assert.deepEqual(parseCode(path.join(tmp,'ru','DIALOGS','npc.c')).refs,[0]);
 const r=compareDialogs(path.join(tmp,'ru'),path.join(tmp,'us'));assert.deepEqual(r.rows.map(x=>x.at(-1)),['IDENT','RU_ONLY']);assert.equal(r.totalRu,3);assert.equal(r.totalUs,2);
});
