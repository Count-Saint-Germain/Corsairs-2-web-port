import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { SAVE_MENU_PATCH, DEFAULT_OPTIONS_PATCH, patchedResourceSource, applyResourceOverrides } from '../web/resource-overrides.mjs';
import { checkSourceGame } from './verify_dist_checks.mjs';
import { createDevServer } from '../web/serve.mjs';
import { gunzipSync } from 'node:zlib';
import { CFG, EXE } from '../web/gamefiles.mjs';

const hash = b => createHash('sha256').update(b).digest('hex');
test('fresh-install sound defaults change only the two requested settings', t => {
  const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-options-patch-'));
  t.after(()=>fs.rmSync(root,{recursive:true,force:true}));
  const patched=fs.readFileSync(DEFAULT_OPTIONS_PATCH.file);
  const original=Buffer.from(patched.toString('latin1').replace('volume.sound=0.1000','volume.sound=0.9900').replace('volume.dialog=0.9000','volume.dialog=0.5090'),'latin1');
  assert.equal(hash(patched),DEFAULT_OPTIONS_PATCH.patchedHash);
  assert.equal(hash(original),DEFAULT_OPTIONS_PATCH.originalHash);
  const source=path.join(root,'options');
  for (const input of [original,patched]) {
    fs.writeFileSync(source,input);
    assert.equal(patchedResourceSource('options',source),DEFAULT_OPTIONS_PATCH.file);
    assert.deepEqual(fs.readFileSync(source),input);
  }
  fs.writeFileSync(source,'volume.sound=0.33');
  assert.equal(patchedResourceSource('options',source),source);
});
function fixture(t) {
  const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-resource-patch-'));
  t.after(()=>fs.rmSync(root,{recursive:true,force:true}));
  const patched=fs.readFileSync(SAVE_MENU_PATCH.file), text=patched.toString('latin1');
  let count=0;
  const original=Buffer.from(text.replace(/event:(SavePress|LoadPress|exitCancel),delay:30/g,(_,event)=>{count++;return `event:${event},delay:150`;}),'latin1');
  assert.equal(count,6);assert.equal(hash(patched),SAVE_MENU_PATCH.patchedHash);assert.equal(hash(original),SAVE_MENU_PATCH.originalHash);
  assert.match(text,/event:DelYes,delay:150/);
  return {root,patched,original};
}

test('the menu patch applies only to known original or already-patched content',t=>{
  const {root,patched,original}=fixture(t),source=path.join(root,'source.ini');
  fs.writeFileSync(source,original);
  assert.equal(patchedResourceSource(SAVE_MENU_PATCH.path,source),SAVE_MENU_PATCH.file);
  assert.deepEqual(fs.readFileSync(source),original);
  assert.equal(applyResourceOverrides(new Map([[SAVE_MENU_PATCH.path,source]])).get(SAVE_MENU_PATCH.path),SAVE_MENU_PATCH.file);
  fs.writeFileSync(source,patched);
  assert.equal(patchedResourceSource(SAVE_MENU_PATCH.path,source),SAVE_MENU_PATCH.file);
  fs.writeFileSync(source,Buffer.from('locally modified'));
  assert.throws(()=>patchedResourceSource(SAVE_MENU_PATCH.path,source),/unknown source content/);
  assert.equal(patchedResourceSource('SAVE/slot',source),source);
});

test('distribution source comparison accepts both known inputs and rejects changes',t=>{
  const {root,patched,original}=fixture(t),source=path.join(root,'game'),dist=path.join(root,'dist');
  const file=path.join(source,...SAVE_MENU_PATCH.path.split('/'));
  fs.mkdirSync(path.dirname(file),{recursive:true});fs.mkdirSync(path.join(dist,'game'),{recursive:true});
  fs.writeFileSync(path.join(dist,'game','manifest.json'),JSON.stringify({files:[{path:SAVE_MENU_PATCH.path,size:patched.length,sha256:SAVE_MENU_PATCH.patchedHash}]}));
  for(const data of [original,patched]){fs.writeFileSync(file,data);assert.equal(checkSourceGame(dist,source,true).passed,true);}
  fs.writeFileSync(file,Buffer.from('modified'));assert.equal(checkSourceGame(dist,source,true).passed,false);
  assert.equal(checkSourceGame(dist,source,false).passed,false);
});

test('development server serves the same verified bytes and rejects changed source',async t=>{
  const {root,patched,original}=fixture(t),source=path.join(root,'game'),web=path.join(root,'web'),build=path.join(root,'build');
  const file=path.join(source,...SAVE_MENU_PATCH.path.split('/'));
  fs.mkdirSync(path.dirname(file),{recursive:true});fs.mkdirSync(web);fs.mkdirSync(build);fs.writeFileSync(file,original);
  for(const name of [EXE,...CFG.files.required]){const f=path.join(source,...name.split('/'));fs.mkdirSync(path.dirname(f),{recursive:true});fs.writeFileSync(f,'fixture');}
  for(const pack of [false,true]){
    const {server,cleanup}=await createDevServer({game:source,web,build,videos:null,pack});
    try{
      await new Promise((resolve,reject)=>{server.once('error',reject);server.listen(0,'127.0.0.1',()=>{server.off('error',reject);resolve();});});
      const url=`http://127.0.0.1:${server.address().port}/game/`;
      const manifest=await(await fetch(url+'manifest.json')).json(),entry=manifest.files.find(e=>e.path===SAVE_MENU_PATCH.path);
      assert.equal(entry.sha256,SAVE_MENU_PATCH.patchedHash);assert.equal(entry.size,patched.length);
      let bytes;if(pack){const record=manifest.packs[entry.pack],response=await fetch(url+record.path),data=Buffer.from(await response.arrayBuffer());
        const segment=data.subarray(entry.offset,entry.offset+entry.csize);bytes=entry.enc==='gzip'?gunzipSync(segment):segment;
      }else bytes=Buffer.from(await(await fetch(url+entry.path)).arrayBuffer());
      assert.deepEqual(bytes,patched);assert.deepEqual(fs.readFileSync(file),original);
      fs.writeFileSync(file,Buffer.from('modified'));
      assert.equal((await fetch(url+'manifest.json')).status,409);
      assert.equal((await fetch(url+entry.path)).status,404);
      fs.writeFileSync(file,original);
    }finally{await new Promise(resolve=>server.close(resolve));cleanup();}
  }
});
