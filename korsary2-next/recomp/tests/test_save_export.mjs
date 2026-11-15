import test from 'node:test';
import assert from 'node:assert/strict';
import { spawnSync } from 'node:child_process';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { crc32, encodeBackup, decodeBackup, openSaveDirectory, readSaveDirectory, readSaveMeta, readSaveLang, isLangRecord, withSaveLock, LIMITS, LANG_SUFFIX } from '../web/save-export.mjs';

// Inspect the central directory independently and ask the system unzip to verify CRCs.
function inspectStandardZip(archive, metadata = false) {
  const tmp=fs.mkdtempSync(path.join(os.tmpdir(),'k2-save-zip-'));
  try {
    const name=path.join(tmp,'backup.zip'); fs.writeFileSync(name,archive);
    const checked=spawnSync('unzip',['-tqq',name],{encoding:'utf8'}); assert.equal(checked.status,0,checked.stderr || checked.stdout);
    const b=Buffer.from(archive), end=b.length-22; assert.equal(b.readUInt32LE(end),0x06054b50);
    const out=spawnSync('unzip',['-p',name],{encoding:null}); assert.equal(out.status,0,out.stderr?.toString());
    let offset=0, p=b.readUInt32LE(end+16); const count=b.readUInt16LE(end+10), result=[];
    for(let i=0;i<count;i++) {
      assert.equal(b.readUInt32LE(p),0x02014b50);
      const flags=b.readUInt16LE(p+8), method=b.readUInt16LE(p+10), n=b.readUInt16LE(p+28), extra=b.readUInt16LE(p+30), comment=b.readUInt16LE(p+32);
      const filename=b.subarray(p+46,p+46+n).toString('utf8');
      const size=b.readUInt32LE(p+24), bytes=out.stdout.subarray(offset,offset+size); offset+=size;
      result.push(metadata ? [filename,bytes.toString('base64'),flags,method] : [filename,bytes.toString('base64')]);
      p+=46+n+extra+comment;
    }
    return result;
  } finally { fs.rmSync(tmp,{recursive:true,force:true}); }
}

const text=new TextEncoder();
function file(bytes,size=bytes.length) {
  return {kind:'file',async getFile(){ return {size,async arrayBuffer(){ return bytes.slice().buffer; }}; }};
}
function dir(entries) { return {async *entries(){ yield* entries; }}; }
function missing() { const e=new Error('not found'); e.name='NotFoundError'; return e; }

test('exports valid standard ZIP with only SAVE, Unicode and exact bytes',async()=>{
  const data=await readSaveDirectory(dir([['Тест.sav',file(text.encode('пираты'))],['slot2',file(new Uint8Array([0,1,255]))]]));
  const archive=encodeBackup(data);
  assert.equal(crc32(text.encode('123456789')),0xcbf43926);
  const listedZip=inspectStandardZip(archive, true);
  assert.deepEqual(listedZip,[
    ['SAVE/Тест.sav',Buffer.from('пираты').toString('base64'),2048,0],
    ['SAVE/slot2',Buffer.from([0,1,255]).toString('base64'),2048,0],
  ]);
});

test('a game root adds each slot\'s SAVE_META record as SAVE_META/<name>.time',async()=>{
  const time=new Uint8Array([1,2,3,4,5,6,7,8]);
  let calls=[];
  const gameRoot={
    getDirectoryHandle:async(name,opts)=>{ calls.push([name,opts]);
      if(name!=='SAVE_META') throw missing();
      return {getFileHandle:async(n,opts)=>{ calls.push([n,opts]);
        if(n==='slot1.time') return {getFile:async()=>({size:8,arrayBuffer:async()=>time.slice().buffer})};
        if(n==='odd.time') return {getFile:async()=>({size:3,arrayBuffer:async()=>text.encode('abc').slice().buffer})};
        throw missing(); }}; } };
  const data=await readSaveDirectory(dir([['slot1',file(text.encode('one'))],['slot2',file(text.encode('two'))],['odd',file(text.encode('o'))]]),gameRoot);
  assert.deepEqual(calls,[   // per slot: its time record, then (E5) its language label
    ['SAVE_META',{create:false}],['slot1.time',{create:false}],['SAVE_META',{create:false}],['slot1.lang',{create:false}],
    ['SAVE_META',{create:false}],['slot2.time',{create:false}],['SAVE_META',{create:false}],['slot2.lang',{create:false}],
    ['SAVE_META',{create:false}],['odd.time',{create:false}],['SAVE_META',{create:false}],['odd.lang',{create:false}],
  ]);
  assert.deepEqual(data.map(e=>e.name),['slot1','slot2','odd']);
  assert.deepEqual(data[0].meta,time);
  assert.equal(data[1].meta,undefined);   // no record: time stays unknown
  assert.equal(data[2].meta,undefined);   // a short record is not a time
  // without a game root no SAVE_META lookups happen at all
  calls=[];
  const plain=await readSaveDirectory(dir([['slot1',file(text.encode('one'))]]));
  assert.deepEqual(plain,[{name:'slot1',bytes:text.encode('one')}]);
  assert.deepEqual(calls,[]);
  // readSaveMeta directly: whole record only
  assert.deepEqual(await readSaveMeta(gameRoot,'slot1'),time);
  assert.equal(await readSaveMeta(gameRoot,'absent'),null);
});

test('slot time records survive a real ZIP round trip',async()=>{
  const time=new Uint8Array([0x10,0x27,0,0,0,0,1,0]);
  const archive=encodeBackup([{name:'Slot1',bytes:text.encode('data'),meta:time}]);
  const listedZip=inspectStandardZip(archive, false);
  assert.deepEqual(listedZip,[
    ['SAVE/Slot1',Buffer.from('data').toString('base64')],
    ['SAVE_META/Slot1.time',Buffer.from(time).toString('base64')],
  ]);
});

test('E5: a game root adds each slot\'s SAVE_META language label as SAVE_META/<name>.lang (exactly "en" or "ru")',async()=>{
  const lang={slot1:text.encode('en'),slot2:text.encode('ru'),bad1:text.encode('xx'),bad2:text.encode('eng'),bad3:text.encode('e'),bad4:text.encode('EN')};
  const gameRoot={getDirectoryHandle:async(name)=>{ if(name!=='SAVE_META') throw missing();
    return {getFileHandle:async(n)=>{ const slot=n.endsWith('.lang')?n.slice(0,-5):null;
      if(slot && lang[slot]) return {getFile:async()=>({size:lang[slot].length,arrayBuffer:async()=>lang[slot].slice().buffer})};
      throw missing(); }}; } };
  const names=['slot1','slot2','bad1','bad2','bad3','bad4','none'];
  const data=await readSaveDirectory(dir(names.map(n=>[n,file(text.encode(n))])),gameRoot);
  assert.deepEqual(data.map(e=>e.lang),[lang.slot1,lang.slot2,undefined,undefined,undefined,undefined,undefined]);
  assert.equal(LANG_SUFFIX,'.lang');
  assert.deepEqual(await readSaveLang(gameRoot,'slot1'),lang.slot1);
  assert.equal(await readSaveLang(gameRoot,'bad1'),null);
  assert.equal(await readSaveLang(gameRoot,'absent'),null);
  assert.equal(await readSaveLang({getDirectoryHandle:async()=>{ throw missing(); }},'slot1'),null);
  assert.deepEqual(['en','ru','xx','EN','',' en'].map(s=>isLangRecord(text.encode(s))),[true,true,false,false,false,false]);
  assert.equal(isLangRecord(null),false); assert.equal(isLangRecord([101,110]),false);
  // without a game root no lookups at all (the plain export is unchanged)
  assert.deepEqual(await readSaveDirectory(dir([['s',file(text.encode('x'))]])),[{name:'s',bytes:text.encode('x')}]);
});

test('E5: a language label survives a real ZIP round trip; a malformed label is refused on encode and on decode',async()=>{
  const time=new Uint8Array([0x10,0x27,0,0,0,0,1,0]);
  const archive=encodeBackup([{name:'Slot1',bytes:text.encode('data'),meta:time,lang:text.encode('en')},{name:'Slot2',bytes:text.encode('d2'),lang:text.encode('ru')},{name:'Slot3',bytes:text.encode('d3')}]);
  const listedZip=inspectStandardZip(archive, false);
  const listed=listedZip;
  assert.deepEqual(listed.map(x=>x[0]),['SAVE/Slot1','SAVE/Slot2','SAVE/Slot3','SAVE_META/Slot1.time','SAVE_META/Slot1.lang','SAVE_META/Slot2.lang']);
  assert.equal(Buffer.from(listed[4][1],'base64').toString(),'en'); assert.equal(Buffer.from(listed[5][1],'base64').toString(),'ru');
  const back=decodeBackup(archive);
  assert.deepEqual(back.lang,[{name:'Slot1',bytes:text.encode('en')},{name:'Slot2',bytes:text.encode('ru')}]);
  assert.deepEqual(back.meta,[{name:'Slot1',bytes:time}]);
  assert.deepEqual(back.ignored,[]);
  for(const bad of [text.encode('xx'),text.encode('eng'),text.encode('e'),text.encode(''),text.encode('EN'),new Uint8Array(2),[101,110],'en'])
    assert.throws(()=>encodeBackup([{name:'a',bytes:text.encode('1'),lang:bad}]),/запись языка/,`encode ${String(bad)}`);
  // no label, no record: a backup of unmarked slots is byte-for-byte what it was before labels existed
  const plain=encodeBackup([{name:'a',bytes:text.encode('1')}]);
  assert.deepEqual(decodeBackup(plain).lang,[]);
  assert.equal(plain.length,30+'SAVE/a'.length+1+46+'SAVE/a'.length+22);
});

test('opens only existing game root and SAVE without creating them',async()=>{
  const calls=[], save=dir([]);
  const open=async create=>{ calls.push(['game',create]); return {getDirectoryHandle:async(name,opts)=>{calls.push([name,opts]);return save;}}; };
  assert.equal(await openSaveDirectory(open),save);
  assert.deepEqual(calls,[['game',false],['SAVE',{create:false}]]);
  await assert.rejects(openSaveDirectory(async()=>{throw missing();}),/не найдены/);
  await assert.rejects(openSaveDirectory(async()=>({getDirectoryHandle:async()=>{throw missing();}})),/не найдены/);
  await assert.rejects(readSaveDirectory(save),/нет сохранений/);
});

test('refuses nested directories, invalid or colliding names and oversized files',async()=>{
  await assert.rejects(readSaveDirectory(dir([['subdir',{kind:'directory'}]])),/вложенная папка/);
  await assert.rejects(readSaveDirectory(dir([['bad/name',file(new Uint8Array())]])),/имя/);
  await assert.rejects(readSaveDirectory(dir([['СОХР',file(new Uint8Array())],['сохр',file(new Uint8Array())]])),/совпадающ/);
  await assert.rejects(readSaveDirectory(dir([['huge',file(new Uint8Array(),LIMITS.file+1)]])),/превышает/);
});

test('locks serialize cooperating exports and failure is closed',async()=>{
  let invoked=false;
  await assert.rejects(withSaveLock(null,'game',()=>{invoked=true;}),/блокировку/);
  await assert.rejects(withSaveLock({request:async(_name,_opts,cb)=>cb(null)},'game',()=>{invoked=true;}),/заняты/);
  assert.equal(invoked,false);
  const locks={request:async(name,opts,cb)=>{assert.equal(name,'game:save-backup');assert.deepEqual(opts,{mode:'exclusive',ifAvailable:true});return cb({});}};
  assert.equal(await withSaveLock(locks,'game',()=>17),17);
});
