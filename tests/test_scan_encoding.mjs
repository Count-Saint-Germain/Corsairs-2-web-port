import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {scanEncoding} from '../english-audit/scan_encoding.mjs';

test('counts high bytes, literals, line endings, BOMs and UTF-8-like sequences',t=>{
 const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-encoding-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));
 fs.mkdirSync(path.join(root,'PROGRAM'),{recursive:true});
 fs.writeFileSync(path.join(root,'PROGRAM','sample.c'),Buffer.concat([Buffer.from([0xef,0xbb,0xbf]),Buffer.from('"', 'ascii'),Buffer.from([0xc3,0xa9]),Buffer.from('"\r\n','ascii'),Buffer.from([0xc0])]));
 fs.writeFileSync(path.join(root,'PROGRAM','other.c'),Buffer.from([0xc0,0x0a]));
 const r=scanEncoding(root);
 assert.equal(r.bom,1);assert.equal(r.crlf,1);assert.equal(r.lf,1);assert.equal(r.utf8seq,2);
 assert.equal(r.total.get(0xc0),2);assert.equal(r.inLiteral.get(0xc3),1);assert.equal(r.inLiteral.get(0xa9),1);assert.equal(r.inLiteral.get(0xc0),undefined);assert.equal(r.files.get(0xc0).size,2);
});
