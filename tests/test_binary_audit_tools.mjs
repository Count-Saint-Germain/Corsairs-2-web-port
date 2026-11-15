import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {readBig} from '../korsary2-next/tools/bigls.mjs';
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
function run(file,args){return spawnSync(process.execPath,[path.join(root,file),...args],{encoding:'utf8'});}
function fixture(t){const d=fs.mkdtempSync(path.join(os.tmpdir(),'k2-big-'));t.after(()=>fs.rmSync(d,{recursive:true,force:true}));return d;}
function archive(file){const name=Buffer.from('Data/file.xml\0'),header=Buffer.alloc(16),entry=Buffer.alloc(8);header.write('BIGF');header.writeUInt32BE(1,8);const content=Buffer.from('<hello>ABC</hello>');entry.writeUInt32BE(16+8+name.length,0);entry.writeUInt32BE(content.length,4);fs.writeFileSync(file,Buffer.concat([header,entry,name,content]));return content;}
test('BIG directory and previews preserve offsets and data',t=>{const dir=fixture(t),file=path.join(dir,'sample.big');const data=archive(file),result=readBig(file);assert.equal(result.magic,'BIGF');assert.equal(result.entries[0].name,'Data/file.xml');assert.equal(result.entries[0].size,data.length);for(const tool of ['korsary2-next/tools','korsary2-work/tools']){const listing=run(`${tool}/bigls.mjs`,[file]);assert.equal(listing.status,0,listing.stderr);assert.match(listing.stdout,/1 files/);const peek=run(`${tool}/bigpeek.mjs`,[file]);assert.equal(peek.status,0,peek.stderr);assert.match(peek.stdout,/<hello>ABC<\/hello>/);}});
test('truncated and out-of-bounds BIG entries are rejected',t=>{const dir=fixture(t),file=path.join(dir,'bad.big');archive(file);const data=fs.readFileSync(file);data.writeUInt32BE(999999,16);fs.writeFileSync(file,data);assert.throws(()=>readBig(file),/exceeds archive/);});
test('ASCII strings in binary data are returned with configurable minimum length',t=>{const dir=fixture(t),file=path.join(dir,'bin');fs.writeFileSync(file,Buffer.from([0,65,66,67,0,104,101,108,108,111,33,255]));for(const tool of ['korsary2-next/tools','korsary2-work/tools']){let r=run(`${tool}/pystrings.mjs`,[file]);assert.equal(r.status,0);assert.equal(r.stdout,'hello!\n');r=run(`${tool}/pystrings.mjs`,[file,'3']);assert.equal(r.stdout,'ABC\nhello!\n');}});
