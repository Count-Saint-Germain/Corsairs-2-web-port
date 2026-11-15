#!/usr/bin/env node
/* Read-only HTTP smoke test of a packaged distribution. This uses an independent
 * reference static server that applies the dist's Cloudflare Pages _headers.
 * It verifies files and protocol behavior locally, not a deployed host.
 *
 * node recomp/tests/test_dist_http_smoke.mjs [DIST]
 * KORSARY_SMOKE_DIST=DIST node recomp/tests/test_dist_http_smoke.mjs
 */
import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import http from 'node:http';
import {createHash} from 'node:crypto';
import {gunzipSync,brotliDecompressSync} from 'node:zlib';
import {buildFixture} from './overlay_fixture.mjs';

const MIME={'.wasm':'application/wasm','.js':'text/javascript','.mjs':'text/javascript','.json':'application/json','.html':'text/html','.mp4':'video/mp4','.txt':'text/plain'};
const isolation={'cross-origin-opener-policy':'same-origin','cross-origin-embedder-policy':'require-corp','cross-origin-resource-policy':'same-origin'};
const sha=b=>createHash('sha256').update(b).digest('hex');
const gameUrl=p=>'/game/'+p.split('/').map(encodeURIComponent).join('/');
function parseHeaders(text){const rules=[];for(const raw of text.split(/\r?\n/)){const line=raw.trim();if(!line||line.startsWith('#'))continue;if(/^\s/.test(raw)){const i=line.indexOf(':');if(rules.length&&i>=0)rules.at(-1).headers[line.slice(0,i).trim()]=line.slice(i+1).trim();}else rules.push({pattern:line,headers:{}});}return rules;}
function headersFor(p,rules){const out={};for(const {pattern,headers} of rules){const expr='^'+pattern.split('*').map(x=>x.replace(/[.*+?^${}()|[\]\\]/g,'\\$&')).join('.*')+'$';if(new RegExp(expr).test(p))Object.assign(out,headers);}return out;}
function rangeHeader(spec,size){const m=/^bytes=(\d*)-(\d*)(?:,.*)?$/.exec(spec);if(!m||(!m[1]&&!m[2])||size===0)return null;let a=m[1]?Number(m[1]):Math.max(0,size-Number(m[2])),b=m[1]&&m[2]?Math.min(Number(m[2]),size-1):size-1;if(!Number.isSafeInteger(a)||!Number.isSafeInteger(b)||a<0||a>=size||a>b)return null;return [a,b];}
async function startServer(root,rules){root=path.resolve(root);const server=http.createServer((req,res)=>{const raw=(req.url??'/').split('?')[0];let decoded;try{decoded=decodeURIComponent(raw);}catch{decoded='';}Object.entries(headersFor(raw||'/',rules)).forEach(([k,v])=>res.setHeader(k,v));
  const fail=code=>{res.statusCode=code;res.end();};
  if(!decoded||decoded.includes('\\')||decoded.split('/').some(p=>p==='..'))return fail(404);
  let file=path.resolve(root,'.'+decoded),rel=path.relative(root,file);if(rel==='..'||rel.startsWith('..'+path.sep)||path.isAbsolute(rel))return fail(404);
  try{let st=fs.statSync(file);if(st.isDirectory()){file=path.join(file,'index.html');st=fs.statSync(file);}if(!st.isFile())return fail(404);
    res.setHeader('Content-Type',MIME[path.extname(file).toLowerCase()]??'application/octet-stream');let start=0,end=st.size-1;
    if(req.headers.range?.startsWith('bytes=')){const range=rangeHeader(req.headers.range,st.size);if(!range){res.setHeader('Content-Range','bytes */'+st.size);res.setHeader('Content-Length','0');return fail(416);} [start,end]=range;res.statusCode=206;res.setHeader('Content-Range','bytes '+start+'-'+end+'/'+st.size);}
    res.setHeader('Content-Length',Math.max(0,end-start+1));if(req.method==='HEAD'||st.size===0)return res.end();
    fs.createReadStream(file,{start,end}).on('error',()=>res.destroy()).pipe(res);
  }catch(e){if(e.code==='ENOENT'||e.code==='ENOTDIR')return fail(404);fail(500);}});
  await new Promise((ok,reject)=>{server.once('error',reject);server.listen(0,'127.0.0.1',ok);});return {server,port:server.address().port};
}
function request(port,p,headers={}){return new Promise((ok,reject)=>{const req=http.request({host:'127.0.0.1',port,path:p,headers,timeout:10000},res=>{const chunks=[];res.on('data',b=>chunks.push(b));res.on('end',()=>ok({status:res.statusCode,headers:res.headers,body:Buffer.concat(chunks)}));res.on('error',reject);});req.on('timeout',()=>req.destroy(new Error('HTTP request timed out')));req.on('error',reject);req.end();});}
function findVideos(root,dir='videos'){const base=path.join(root,dir);if(!fs.existsSync(base))return [];const result=[];for(const e of fs.readdirSync(base,{withFileTypes:true})){const rel=path.posix.join(dir,e.name);if(e.isDirectory())result.push(...findVideos(root,rel));else if(e.name.endsWith('.mp4'))result.push(rel);}return result.sort();}
function wire(manifest,e){if(e.pack!=null){const p=manifest.packs[e.pack];return [p.path,p.size];}return e.enc?[e.path+({gzip:'.gz',br:'.br'}[e.enc]??''),e.csize]:[e.path,e.size];}
function plain(e,body){if(e.pack!=null)body=body.subarray(e.offset,e.offset+e.csize);return e.enc==='gzip'?gunzipSync(body,{maxOutputLength:e.size+1}):e.enc==='br'?brotliDecompressSync(body,{maxOutputLength:e.size+1}):body;}
function isolated(headers,label){for(const [k,v] of Object.entries(isolation))assert.equal(headers[k],v,label+' '+k);}

async function verify(root,port){
  const get=(p,h)=>request(port,p,h),index=await get('/');assert.equal(index.status,200);assert.match(index.body.toString(),/<script src="port.js">/);assert.match(index.body.toString(),/port-config\.js/);isolated(index.headers,'index');assert.equal(index.headers['x-robots-tag'],'noindex');assert.equal(index.headers['cache-control'],'no-cache');
  for(const e of fs.readdirSync(root,{withFileTypes:true})){if(e.isFile()&&['.js','.mjs','.json','.html'].includes(path.extname(e.name))){const r=await get('/'+encodeURIComponent(e.name));assert.equal(r.status,200,e.name);assert.equal(r.headers['cache-control'],'no-cache',e.name);}}
  let r=await get('/build/game.js');assert.equal(r.status,200);assert.match(r.body.toString(),/_port_video_poll/);assert.equal(r.headers['cache-control'],'no-cache');
  r=await get('/build/game.wasm');assert.equal(r.status,200);assert.deepEqual(r.body.subarray(0,4),Buffer.from([0,97,115,109]));assert.ok(Number(r.headers['content-length'])>8);assert.equal(r.headers['content-type'],'application/wasm');
  r=await get('/game/manifest.json');assert.equal(r.status,200);assert.equal(r.headers['content-type'],'application/json');assert.equal(r.headers['cache-control'],'no-cache');const m=JSON.parse(r.body);assert.ok(m.version&&m.files.length);
  const files=[...m.files].sort((a,b)=>a.size-b.size),first=files.find(e=>e.size>=64);assert.ok(first);let [name,n]=wire(m,first);r=await get(gameUrl(name));assert.equal(r.status,200);assert.equal(Number(r.headers['content-length']),n);assert.equal(r.body.length,n);assert.equal(plain(first,r.body).length,first.size);
  assert.equal((await get('/this/does/not/exist')).status,404);r=await get('/robots.txt');assert.equal(r.status,200);assert.match(r.body.toString(),/User-agent: \*/);assert.match(r.body.toString(),/Disallow: \//);
  const nonempty=files.find(e=>wire(m,e)[1]>0);assert.ok(nonempty);const gp=gameUrl(wire(m,nonempty)[0]);for(const [p,h] of [['/',{}],['/port.js',{}],['/video-player.mjs',{}],['/build/game.js',{}],['/build/game.wasm',{}],['/game/manifest.json',{}],['/robots.txt',{}],['/this/does/not/exist',{}],[gp,{}],[gp,{Range:'bytes=0-0'}]]){const got=await get(p,h);isolated(got.headers,p);if(p===gp)assert.equal(got.status,h.Range?206:200);}
  assert.match((await get('/video-player.mjs')).headers['content-type'],/^text\/javascript/);assert.match((await get('/port.js')).headers['content-type'],/^text\/javascript/);
  const videos=findVideos(root);assert.ok(videos.length,'the dist packages no videos');for(const v of videos){const vp='/'+v.split('/').map(encodeURIComponent).join('/'),data=fs.readFileSync(path.join(root,v)),size=data.length;let q=await get(vp,{Range:'bytes=0-11'});assert.equal(q.status,206);assert.equal(q.headers['content-type'],'video/mp4');assert.equal(q.body.subarray(4,8).toString(),'ftyp');assert.equal(q.headers['content-range'],'bytes 0-11/'+size);isolated(q.headers,v);q=await get(vp,{Range:'bytes=-4'});assert.equal(q.status,206);assert.deepEqual(q.body,data.subarray(-4));assert.equal((await get(vp,{Range:'bytes='+size+'-'})).status,416);q=await get(vp,{Range:'bytes=0-'+(size+1000)});assert.equal(q.status,206);assert.equal(q.body.length,size);}
  const picks=new Map([files[0],files[Math.floor(files.length/2)],files.at(-1),...files.filter(x=>x.path==='options')].map(x=>[x.path,x]));for(const e of picks.values()){if(e.size>80*1024*1024)continue;const [p,size]=wire(m,e),q=await get(gameUrl(p));assert.equal(q.status,200,e.path);assert.equal(q.body.length,size,e.path);const data=plain(e,q.body);assert.equal(data.length,e.size,e.path);assert.equal(sha(data),e.sha256,e.path);}
  const [big,bigSize]=wire(m,files.at(-1)),mid=Math.floor(bigSize/2),q=await get(gameUrl(big),{Range:'bytes='+mid+'-'+(mid+15)});assert.equal(q.status,206);assert.equal(q.headers['content-range'],'bytes '+mid+'-'+(mid+15)+'/'+bigSize);const fd=fs.openSync(path.join(root,'game',big),'r');try{const b=Buffer.alloc(16),read=fs.readSync(fd,b,0,16,mid);assert.deepEqual(q.body,b.subarray(0,read));}finally{fs.closeSync(fd);}
  for(const e of m.files.filter(x=>x.enc&&x.pack==null)){const [p]=wire(m,e),full=await get(gameUrl(p));assert.equal(full.status,200);assert.equal(full.headers['content-encoding'],undefined);assert.equal(full.body.length,e.csize);assert.equal(sha(plain(e,full.body)),e.sha256);assert.equal((await get(gameUrl(e.path))).status,404);const half=Math.floor(e.csize/2),part=await get(gameUrl(p),{Range:'bytes='+half+'-'});assert.equal(part.status,206);assert.deepEqual(part.body,full.body.subarray(half));}
  for(const [i,pack] of (m.packs??[]).slice(0,6).entries()){const members=m.files.filter(x=>x.pack===i),full=await get(gameUrl(pack.path));assert.equal(full.status,200);assert.equal(full.headers['content-encoding'],undefined);assert.equal(full.body.length,pack.size);for(const e of members.slice(0,50)){const data=plain(e,full.body);assert.equal(data.length,e.size);assert.equal(sha(data),e.sha256);assert.equal((await get(gameUrl(e.path))).status,404);}const e=members.reduce((a,b)=>a.csize>b.csize?a:b);if(e.csize){const a=e.offset,b=a+e.csize-1,part=await get(gameUrl(pack.path),{Range:'bytes='+a+'-'+b});assert.equal(part.status,206);assert.equal(part.headers['content-range'],'bytes '+a+'-'+b+'/'+pack.size);assert.deepEqual(part.body,full.body.subarray(a,b+1));}}
  for(const e of m.files)assert.ok(!['save','save_meta'].includes(e.path.split('/')[0].toLowerCase()));for(const p of ['/game/SAVE/slot','/game/save','/game/SAVE_META/slot.time','/game/SAVE_META/slot.lang','/SAVE'])assert.equal((await get(p)).status,404);
  r=await get('/build/game.wasm',{Range:'bytes=999999999999-'});assert.equal(r.status,416);assert.equal(r.body.length,0);assert.match(r.headers['content-range'],/^bytes \*\//);
}
async function run(root){const rules=parseHeaders(fs.readFileSync(path.join(root,'_headers'),'utf8'));const {server,port}=await startServer(root,rules);try{await verify(root,port);}finally{await new Promise(ok=>server.close(ok));}}
const requested=process.argv.slice(2).find(x=>!x.startsWith('-'))||process.env.KORSARY_SMOKE_DIST;
if(requested){test('real distribution over HTTP',async()=>run(path.resolve(requested)));}
else for(const layout of ['plain','d1','d1br','pack','pack-raw','brpack'])test('synthetic distribution over HTTP: '+layout,async()=>{const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-dist-http-'));try{const {dist}=await buildFixture(dir,{layout,overlay:false});fs.mkdirSync(path.join(dist,'videos'),{recursive:true});fs.writeFileSync(path.join(dist,'videos/Trailer.mp4'),Buffer.concat([Buffer.from([0,0,0,20]),Buffer.from('ftyp'),Buffer.alloc(20)]));await run(dist);}finally{fs.rmSync(dir,{recursive:true,force:true});}});
test('URL encoding and traversal cannot expose files outside the root',async()=>{const dir=fs.mkdtempSync(path.join(os.tmpdir(),'k2-http-url-')),root=path.join(dir,'dist'),raw='RESOURCE/space %?#/корабль.bin',data=Buffer.from('object path encoding and range verification');fs.mkdirSync(path.join(root,'game',path.dirname(raw)),{recursive:true});fs.writeFileSync(path.join(root,'game',raw),data);fs.writeFileSync(path.join(dir,'smoke-secret.txt'),'SECRET OUTSIDE THE DIST');const {server,port}=await startServer(root,[]);try{const p=gameUrl(raw);assert.match(p,/space%20%25%3F%23/);assert.match(p,/%D0%BA/);let r=await request(port,p);assert.equal(r.status,200);assert.deepEqual(r.body,data);r=await request(port,p,{Range:'bytes=2-9'});assert.equal(r.status,206);assert.deepEqual(r.body,data.subarray(2,10));assert.equal(r.headers['content-range'],'bytes 2-9/'+data.length);for(const p of ['/../smoke-secret.txt','/..%2fsmoke-secret.txt','/%2e%2e/smoke-secret.txt','/..%5csmoke-secret.txt','/%2e%2e%2f%2e%2e%2fsmoke-secret.txt'])assert.ok(!(await request(port,p)).body.includes('SECRET OUTSIDE THE DIST'),p);}finally{await new Promise(ok=>server.close(ok));fs.rmSync(dir,{recursive:true,force:true});}});
