/** Portable manifest and generated-output smoke tests for the experimental Node translator. */
import test from 'node:test';import assert from 'node:assert/strict';
import {spawnSync} from 'node:child_process';import fs from 'node:fs';import os from 'node:os';import path from 'node:path';import {fileURLToPath} from 'node:url';
const script=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../translator/x86toc.mjs');
function fixture() {
 const root=fs.mkdtempSync(path.join(os.tmpdir(),'k2-translator path-')),data=path.join(root,'project/recomp/data'),game=path.join(root,'project/game');
 fs.mkdirSync(data,{recursive:true});fs.mkdirSync(game,{recursive:true});
 const b=Buffer.alloc(0x400),p=0x80,opt=p+24,sec=opt+224;
 b.writeUInt16LE(0x5a4d,0);b.writeUInt32LE(p,0x3c);b.writeUInt32LE(0x4550,p);b.writeUInt16LE(0x14c,p+4);b.writeUInt16LE(1,p+6);b.writeUInt16LE(224,p+20);
 b.writeUInt16LE(0x10b,opt);b.writeUInt32LE(0x1000,opt+16);b.writeUInt32LE(0x400000,opt+28);b.writeUInt32LE(0x2000,opt+56);b.writeUInt32LE(0x200,opt+60);b.writeUInt32LE(16,opt+92);
 b.write('.text',sec);b.writeUInt32LE(0x200,sec+8);b.writeUInt32LE(0x1000,sec+12);b.writeUInt32LE(0x200,sec+16);b.writeUInt32LE(0x200,sec+20);
 Buffer.from('b807000000c3','hex').copy(b,0x200);
 fs.writeFileSync(path.join(game,'ENGINE.exe'),b);
 fs.writeFileSync(path.join(data,'functions.json'),JSON.stringify({functions:[{entry:0x401000,name:'test',ranges:[[0x401000,0x401006]]}],jumptables:[]}));
 const image={path:'../../game/ENGINE.exe',functions:'functions.json',guest:'ENGINE.exe',tag:'recomp',base:0x400000,required:true};
 const relative=path.join(data,'relative.json'),absolute=path.join(data,'absolute.json');
 fs.writeFileSync(relative,JSON.stringify({images:[image]}));
 fs.writeFileSync(absolute,JSON.stringify({images:[{...image,path:path.resolve(data,image.path),functions:path.resolve(data,image.functions)}]}));
 return {root,data,game,relative,absolute};
}

test('relative and absolute manifest paths generate identical C and metadata from another cwd',()=>{
 const f=fixture();try{
  for(const [name,manifest] of [['relative',f.relative],['absolute',f.absolute]]) {
   const out=path.join(f.root,name),run=spawnSync(process.execPath,[script,'--manifest',path.relative(f.root,manifest),out,'--all','--per-file','300'],{cwd:f.root,encoding:'utf8'});
   assert.equal(run.status,0,run.stderr);
  }
  const one=path.join(f.root,'relative'),two=path.join(f.root,'absolute');
  const files=fs.readdirSync(one).sort();assert.deepEqual(files,fs.readdirSync(two).sort());
  for(const file of files)assert.deepEqual(fs.readFileSync(path.join(one,file)),fs.readFileSync(path.join(two,file)),file);
  assert.match(fs.readFileSync(path.join(one,'recomp_000.c'),'utf8'),/c->eax = \(uint32_t\)\(\(uint32_t\)0x7u\);/);
  const report=JSON.parse(fs.readFileSync(path.join(one,'translate_report.json'),'utf8'));assert.equal(report.stats.functions,1);assert.equal(report.stats.instructions,2);
 }finally{fs.rmSync(f.root,{recursive:true,force:true})}
});

test('invalid CLI arguments fail before creating output',()=>{
 const f=fixture();try{
  const out=path.join(f.root,'must-not-exist');
  const run=spawnSync(process.execPath,[script,'--manifest',f.relative,out,'--per-file','0'],{cwd:f.root,encoding:'utf8'});
  assert.notEqual(run.status,0);assert.match(run.stderr,/positive integer/);assert.equal(fs.existsSync(out),false);
 }finally{fs.rmSync(f.root,{recursive:true,force:true})}
});

 test('missing optional functions still translates module exports and warns',()=>{
 const f=fixture();try{
  fs.copyFileSync(path.join(f.game,'ENGINE.exe'),path.join(f.game,'Module.dll'));
  const base=JSON.parse(fs.readFileSync(f.relative,'utf8'));base.images.push({path:'../../game/Module.dll',functions:'missing-optional.json',guest:'MODULES/Module.dll',tag:'MODULES_Module',base:0x500000,required:false});
  const manifest=path.join(f.data,'optional.json');fs.writeFileSync(manifest,JSON.stringify(base));
  const out=path.join(f.root,'out'),run=spawnSync(process.execPath,[script,'--manifest',manifest,out,'--all'],{cwd:f.root,encoding:'utf8'});
  assert.equal(run.status,0,run.stderr);assert.match(run.stderr,/missing.*exports and a code scan only/);
  const modules=JSON.parse(fs.readFileSync(path.join(out,'modules.json'),'utf8')).modules;assert.equal(modules.length,2);assert.equal(modules[1].base,0x500000);assert.ok(modules[1].entries>0);
 }finally{fs.rmSync(f.root,{recursive:true,force:true})}
});
