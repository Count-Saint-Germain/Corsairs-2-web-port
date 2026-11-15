import test from 'node:test';import assert from 'node:assert/strict';import fs from 'node:fs';import os from 'node:os';import path from 'node:path';import {compareScripts} from '../english-audit/compare_scripts.mjs';
test('classifies identical bytes, text-only changes, code changes, and unpaired files',t=>{
 const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-scripts-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));const ru=path.join(root,'ru'),us=path.join(root,'us');fs.mkdirSync(ru);fs.mkdirSync(us);
 const w=(dir,n,s)=>fs.writeFileSync(path.join(dir,n),s);w(ru,'same.c','same');w(us,'same.c','same');w(ru,'text.c','say("hello"); // old');w(us,'text.c','say("world"); // new');w(ru,'code.c','a=1;\nb=2;\n');w(us,'code.c','a=1;\nb=3;\n');w(ru,'ru.c','x');w(us,'us.c','y');
 const rows=compareScripts(ru,us).rows;assert.deepEqual(rows.map(r=>[r[1],r[2]]),[['code.c','CODE_DIFF'],['ru.c','RU_ONLY'],['same.c','BYTES_EQ'],['text.c','TEXT_ONLY'],['us.c','US_ONLY']]);assert.equal(rows[0].at(-1),'0/1');assert.equal(rows[3].at(-1),'1/0');
});
