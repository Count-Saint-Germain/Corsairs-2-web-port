import test from 'node:test';import assert from 'node:assert/strict';import fs from 'node:fs';import os from 'node:os';import path from 'node:path';import {verifyOverlay} from '../english-audit/verify_overlay.mjs';
test('detects code changes, literal count changes and untranslated strings',t=>{const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-verify-overlay-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));const ru=path.join(root,'ru'),emit=path.join(root,'emit');fs.mkdirSync(ru);fs.mkdirSync(emit);const rus=Buffer.from([0xcf,0xf0,0xe8,0xe2,0xe5,0xf2]).toString('latin1');
 fs.writeFileSync(path.join(ru,'a.c'),Buffer.from(`say("${rus}");`,'latin1'));fs.writeFileSync(path.join(emit,'a.c'),'say("hello");');
 fs.writeFileSync(path.join(ru,'b.c'),Buffer.from(`say("${rus}");`,'latin1'));fs.writeFileSync(path.join(emit,'b.c'),Buffer.from(`other("${rus}","extra");`,'latin1'));
 const r=verifyOverlay(ru,emit);assert.equal(r.rows.length,2);assert.equal(r.badCode,1);assert.equal(r.badCount,1);assert.equal(r.cyrLeft,1);assert.deepEqual(r.rows.map(x=>x.slice(0,3)),[['a.c',true,true],['b.c',false,false]]);
});
