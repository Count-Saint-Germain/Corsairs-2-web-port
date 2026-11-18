import test from 'node:test';
import assert from 'node:assert/strict';
import { promises as fs } from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { createHash } from 'node:crypto';
import { run, call, remoteInfo, remoteSize, decide, manifestProblems } from '../web/cloudflare/upload.mjs';
const sha = bytes => createHash('sha256').update(bytes).digest('hex');

class FakeBucket {
  constructor(old = false) { this.objects = new Map(); this.puts = []; this.parts = new Map(); this.aborts = []; this.old = old; this.corrupt = false; }
  put(key, data, digest = null) { this.objects.set(key, {size: data.length, sha256: digest}); }
  async transport(base, token, key, {method='GET', query={}, body, headers={}}={}) {
    const digest = headers['X-Content-SHA256'] ?? null;
    if (query.head) {
      const object = this.objects.get(key);
      if (!object) { const e = new Error('not found'); e.status = 404; throw e; }
      return this.old ? {size: object.size} : object;
    }
    if (query.mpu === 'create') { this.parts.set('id', {key, lengths: [], digest}); return {uploadId:'id'}; }
    if (query.uploadId) {
      const object = this.parts.get(query.uploadId);
      if (query.abort) { this.aborts.push(object.key); this.parts.delete(query.uploadId); return {aborted:true}; }
      if (query.part) { object.lengths.push(body.length); return {partNumber: query.part, etag: 'e'}; }
      const size = object.lengths.reduce((a,b)=>a+b,0), stored = this.old ? null : object.digest;
      this.puts.push([key,size,digest]); this.objects.set(key,{size,sha256:stored});
      return this.old ? {size} : {size,sha256:this.corrupt ? '0'.repeat(64) : stored};
    }
    if (method === 'PUT') {
      const size = Buffer.byteLength(body), stored = this.old ? null : digest;
      this.puts.push([key,size,digest]); this.objects.set(key,{size,sha256:stored});
      return this.old ? {size} : {size,sha256:this.corrupt ? '0'.repeat(64) : stored};
    }
    throw new Error(`Unexpected transport call ${method} ${key}`);
  }
}
async function fixture(t) {
  const root = await fs.mkdtemp(path.join(os.tmpdir(),'k2-upload-node-'));
  t.after(() => fs.rm(root,{recursive:true,force:true}));
  const write = async (key, body) => { const p=path.join(root,key); await fs.mkdir(path.dirname(p),{recursive:true}); await fs.writeFile(p,body); return Buffer.from(body); };
  await write('index.html','<html>'); await write('game/manifest.json','{"version":"v","files":[]}'); await write('_headers','/*');
  const data=await write('game/PROGRAM/a.c','AAAA original');
  const bucket = new FakeBucket(), log=[];
  const upload = (opts={}) => run('https://worker.invalid','token',root,{transport:bucket.transport.bind(bucket),out:s=>log.push(s),...opts});
  return {root,write,data,bucket,log,upload};
}

test('immutable objects require both matching size and hash', async t => {
  const {write,data,bucket,upload}=await fixture(t);
  bucket.put('game/PROGRAM/a.c',data,sha(data));
  let [sent,skipped]=await upload(); assert.deepEqual(skipped,['game/PROGRAM/a.c']); assert.equal(sent.at(-1),'game/manifest.json');
  const changed=await write('game/PROGRAM/a.c','BBBB original'); assert.equal(changed.length,data.length);
  [sent,skipped]=await upload(); assert.ok(sent.includes('game/PROGRAM/a.c')); assert.ok(!skipped.includes('game/PROGRAM/a.c'));
  assert.equal(bucket.objects.get('game/PROGRAM/a.c').sha256,sha(changed));
  assert.ok(!sent.includes('_headers'));
});

test('hashless objects are reuploaded unless size-only migration is requested', async t => {
  const {data,bucket,upload}=await fixture(t); bucket.put('game/PROGRAM/a.c',data,null);
  let [sent,skipped]=await upload({trustSize:true}); assert.ok(skipped.includes('game/PROGRAM/a.c'));
  [sent,skipped]=await upload(); assert.ok(sent.includes('game/PROGRAM/a.c'));
  [sent,skipped]=await upload(); assert.ok(skipped.includes('game/PROGRAM/a.c'));
  bucket.put('game/PROGRAM/a.c',data,sha('different'));
  [sent]=await upload({trustSize:true}); assert.ok(sent.includes('game/PROGRAM/a.c'));
});

test('dry-run sends nothing, missing manifest objects fail before any request', async t => {
  const {root,write,bucket,upload}=await fixture(t);
  const [sent]=await upload({dryRun:true}); assert.ok(sent.includes('game/PROGRAM/a.c')); assert.equal(bucket.puts.length,0);
  await write('game/manifest.json',JSON.stringify({files:[{path:'nope',enc:'gzip'}]}));
  assert.deepEqual(await manifestProblems(root, ['game/manifest.json']),['game/nope.gz']);
  await assert.rejects(upload(),/nothing was uploaded/); assert.equal(bucket.puts.length,0);
});

test('multipart uploads preserve hash and manifest is uploaded last', async t => {
  const {write,bucket,upload}=await fixture(t);
  const large=await write('game/RESOURCE/big.dat',Buffer.alloc(10_000,7));
  const [sent]=await upload({singleMax:4096,partSize:4096});
  assert.equal(sent.at(-1),'game/manifest.json');
  assert.equal(bucket.objects.get('game/RESOURCE/big.dat').sha256,sha(large));
  assert.equal(bucket.puts.find(x=>x[0]==='game/RESOURCE/big.dat')[1],large.length);
  assert.equal(bucket.puts.find(x=>x[0]==='index.html')[2],null);
  assert.equal(bucket.puts.at(-1)[0],'game/manifest.json');
});

test('legacy worker warning and incorrect saved hashes', async t => {
  const {root,bucket,log}=await fixture(t); const old=new FakeBucket(true);
  await run('x','y',root,{transport:old.transport.bind(old),out:s=>log.push(s)});
  assert.ok(log.some(s=>s.includes('redeploy worker.js')));
  bucket.corrupt=true;
  await assert.rejects(run('x','y',root,{transport:bucket.transport.bind(bucket),out:()=>{}}),/recorded sha256/);
});

test('remote metadata, transport headers and decision table', async () => {
  const b=new FakeBucket(), transport=b.transport.bind(b);
  assert.equal(await remoteInfo('x','y','game/x',transport),null); assert.equal(await remoteSize('x','y','game/x',transport),-1);
  b.put('game/x',Buffer.from('abc'),sha('abc').toUpperCase()); assert.deepEqual(await remoteInfo('x','y','game/x',transport),{size:3,sha256:sha('abc')});
  assert.deepEqual(decide({size:3,sha256:sha('abc')},3,sha('abc')),[false,'same size and sha256']);
  let observed;
  const fetchImpl=async (url,options) => {observed={url,...options}; return {ok:true,text:async()=>'{"size":1}'};};
  assert.deepEqual(await call('https://w','tok','game/a b',{method:'PUT',body:'1',headers:{'X-Content-SHA256':'ab'},fetchImpl}),{size:1});
  assert.equal(observed.url,'https://w/_upload/game/a%20b'); assert.equal(observed.headers['X-Upload-Token'],'tok'); assert.equal(observed.headers['X-Content-SHA256'],'ab');
});

test('manifest validation supports packed, gzip, Brotli and English overlay objects', async t=>{
 const {root,write}=await fixture(t);
 await write('game/manifest.json', JSON.stringify({files:[{path:'PROGRAM/a.c'},{path:'x',enc:'gzip'},{path:'br',enc:'br'},{path:'p',pack:0}],packs:[{path:'_k2pack/0000.pack'}]}));
 await write('game-en/manifest.json',JSON.stringify({files:[{path:'PROGRAM/en.c'}]}));
 assert.deepEqual((await manifestProblems(root,['game/PROGRAM/a.c','game/x.gz','game/br.br'])).sort(),['game-en/PROGRAM/en.c','game/_k2pack/0000.pack']);
});
test('multipart retries transient errors and fails after four unsuccessful attempts',async t=>{
 const {write,bucket,upload}=await fixture(t);await write('game/big',Buffer.alloc(10000,3));
 const orig=bucket.transport.bind(bucket);let attempts=0;
 const transport=async (...args)=>{const opts=args[3]??{};if(opts.query?.part===1&&attempts++<3)throw new Error('temporary network failure');return orig(...args);};
 await upload({singleMax:4096,partSize:4096,transport});assert.equal(attempts,4);
 const alwaysFail=async (...args)=>{if(args[3]?.query?.part)throw new Error('offline');return orig(...args);};
 await write('game/big',Buffer.alloc(11000,4));
 await assert.rejects(upload({singleMax:4096,partSize:4096,transport:alwaysFail}),/offline/);
 assert.deepEqual(bucket.aborts,['game/big']);
});

test('real HTTP transport sends token and uploads objects before the manifest',async t=>{
 const http=await import('node:http'), {once}=await import('node:events');const {root}=await fixture(t), bucket=new FakeBucket();
 const server=http.createServer(async(req,res)=>{
  try{
   assert.equal(req.headers['x-upload-token'],'local-token');const url=new URL(req.url,'http://localhost');
   const key=decodeURIComponent(url.pathname.slice('/_upload/'.length)),query=Object.fromEntries(url.searchParams),chunks=[];
   for await(const chunk of req)chunks.push(chunk);const body=Buffer.concat(chunks),headers={};if(req.headers['x-content-sha256'])headers['X-Content-SHA256']=req.headers['x-content-sha256'];
   const result=await bucket.transport('','',key,{method:req.method,query,body,headers});res.writeHead(200,{'Content-Type':'application/json'});res.end(JSON.stringify(result));
  }catch(e){res.writeHead(e.status||500);res.end('{}');}
 });
 server.listen(0,'127.0.0.1');await once(server,'listening');t.after(()=>new Promise(resolve=>server.close(resolve)));
 const [sent]=await run(`http://127.0.0.1:${server.address().port}`,'local-token',root,{out:()=>{}});
 assert.equal(sent.at(-1),'game/manifest.json');assert.equal(bucket.puts.at(-1)[0],'game/manifest.json');
});

test('decision table handles all metadata combinations and HTTP failures propagate',async()=>{
 const h='a'.repeat(64),different='b'.repeat(64),cases=[
  [null,5,h,false,true],[{size:4,sha256:h},5,h,false,true],[{size:5,sha256:h},5,h,false,false],
  [{size:5,sha256:different},5,h,false,true],[{size:5,sha256:null},5,h,false,true],
  [{size:5,sha256:null},5,h,true,false],[{size:5,sha256:different},5,h,true,true],
 ];
 for(const [info,size,local,trust,expected] of cases)assert.equal(decide(info,size,local,trust)[0],expected);
 await assert.rejects(remoteInfo('u','t','game/x',async()=>{const e=new Error('HTTP 500');e.status=500;throw e;}),/500/);
});

test('rejects save directories and invalid manifests before contacting the Worker', async t => {
  const { root, write, upload } = await fixture(t);
  let calls = 0;
  const noNetwork = async () => { calls++; throw new Error('unexpected network request'); };
  await write('game/SAVE/test-slot', 'private save');
  await assert.rejects(upload({ transport: noNetwork }), /protected save directory/);
  assert.equal(calls, 0);
  assert.equal(await fs.readFile(path.join(root, 'game/SAVE/test-slot'), 'utf8'), 'private save');
  await fs.rm(path.join(root, 'game/SAVE'), { recursive: true }); // fixture only
  for (const bad of [
    '{', '{}', JSON.stringify({ files: [{ path: '../secret' }] }),
    JSON.stringify({ files: [{ path: 'x', pack: 4 }], packs: [] }),
    JSON.stringify({ files: [{ path: 'x', enc: 'unknown' }] }),
  ]) {
    await write('game/manifest.json', bad);
    await assert.rejects(upload({ transport: noNetwork }), /nothing was uploaded/);
    assert.equal(calls, 0);
  }
  await fs.rm(path.join(root, 'game/manifest.json'));
  await assert.rejects(upload({ transport: noNetwork }), /missing game\/manifest.json/);
  assert.equal(calls, 0);
});
