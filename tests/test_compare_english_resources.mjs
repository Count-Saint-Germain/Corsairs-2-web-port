import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {compareInventory,topGroup} from '../english-audit/compare_inventory.mjs';
import {compareResources} from '../english-audit/compare_resources.mjs';
function fixture(t){const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-resource-'));t.after(()=>fs.rmSync(root,{recursive:true,force:true}));for(const [name,data] of [['RESOURCE/Textures/Foo.tx','old'],['RESOURCE/Textures/Same.tx','same'],['RESOURCE/Models/Ship.gm','model'],['PROGRAM/a.c','local']]){const f=path.join(root,name);fs.mkdirSync(path.dirname(f),{recursive:true});fs.writeFileSync(f,data);}return root;}
function archive(){const files=[{rel:'resource/textures/foo.tx',exp:3,data:Buffer.from('new')},{rel:'RESOURCE/TEXTURES/SAME.tx',exp:4,data:Buffer.from('same')},{rel:'RESOURCE/Textures/only.tx',exp:8,data:Buffer.from('onlynew!')},{rel:'RESOURCE/Models/Ship.gm',exp:5,data:Buffer.from('other')},{rel:'PROGRAM/a.c',exp:10,data:Buffer.from('long local')}];return {files,path:f=>f.rel,readFile:f=>f.data};}
test('inventory compares paths case-insensitively and groups sizes',t=>{const root=fixture(t),r=compareInventory(root,archive());assert.deepEqual(r.onlyUs,['resource/textures/only.tx']);assert.equal(r.onlyRu.length,0);assert.deepEqual(r.diff,['program/a.c']);assert.equal(r.same.length,3);assert.equal(topGroup('RESOURCE/Textures/Foo.tx'),'RESOURCE/Textures');assert.equal(topGroup('foo.bin'),'(root)');});
test('resource comparison detects content changes and excludes models',t=>{const root=fixture(t),r=compareResources(root,archive());assert.equal(r.total,2);assert.deepEqual(r.rows,[['resource/textures/foo.tx',3,3,'DIFF']]);});
test('unavailable split resources are reported without losing other comparisons',t=>{const root=fixture(t),a=archive();a.readFile=f=>{if(f.rel.includes('foo.tx'))throw Error('split or truncated file beyond volume');return f.data;};const r=compareResources(root,a);assert.deepEqual(r.rows,[['resource/textures/foo.tx',3,3,'SPLIT']]);});
