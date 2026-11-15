// Isolated OPFS: fresh installations use the packaged sound defaults, while
// an update preserves customised settings and a synthetic save byte-for-byte.
import assert from 'node:assert/strict';
import http from 'node:http';
import {readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {createRequire} from 'node:module';
import {dirname,join,resolve} from 'node:path';
import {fileURLToPath} from 'node:url';
import {createStaticHandler} from '../../../scripts/serve_distribution.mjs';

const site=resolve(process.env.K2_TEST_DIST || 'distribution');
const profile=process.env.K2_TEST_PROFILE;
if(!profile) throw new Error('K2_TEST_PROFILE must name a separate retained test profile');
const options=await readFile(join(site,'game/options'));
const fresh=options.toString('latin1');
assert.match(fresh,/^volume\.sound=0\.1000\r?$/m);
assert.match(fresh,/^volume\.dialog=0\.9000\r?$/m);
const previous=Buffer.from(fresh.replace('volume.sound=0.1000','volume.sound=0.9900').replace('volume.dialog=0.9000','volume.dialog=0.5090'),'latin1');
const manifest=JSON.parse(await readFile(join(site,'game/manifest.json'),'utf8'));
const old={...manifest,version:manifest.version+'-old-sound-test',files:manifest.files.map(x=>x.path==='options'?{...x,size:previous.length,sha256:createHash('sha256').update(previous).digest('hex')}:x)};
const handler=await createStaticHandler(site,{requireIndex:true});let updated=false;
function server(){return http.createServer((req,res)=>{
  const p=(req.url||'').split('?',1)[0];
  if(p==='/game/manifest.json'||p==='/game/options'){
    const body=p.endsWith('manifest.json')?Buffer.from(JSON.stringify(updated?manifest:old)):updated?options:previous;
    res.writeHead(200,{'Content-Type':p.endsWith('.json')?'application/json':'application/octet-stream','Content-Length':body.length,
      'Cross-Origin-Opener-Policy':'same-origin','Cross-Origin-Embedder-Policy':'require-corp','Cache-Control':'no-store'});res.end(body);return;
  }
  handler(req,res).catch(e=>{if(!res.headersSent)res.writeHead(500);res.end(String(e));});
});}
const first=server(),second=server();
const here=dirname(fileURLToPath(import.meta.url)),pw=resolve(here,'../../third_party/playwright');
process.env.PLAYWRIGHT_BROWSERS_PATH ||= join(pw,'browsers');
const {chromium}=createRequire(join(pw,'package.json'))('playwright');let context;
try {
  for(const s of [first,second]) await new Promise((ok,fail)=>{s.once('error',fail);s.listen(0,'127.0.0.1',ok);});
  context=await chromium.launchPersistentContext(profile,{headless:true,...(process.env.K2_TEST_BROWSER?{executablePath:process.env.K2_TEST_BROWSER}:{channel:'chromium'}),args:['--enable-unsafe-webgpu']});
  const page=context.pages()[0]||await context.newPage();
  const url=s=>`http://127.0.0.1:${s.address().port}/?lazy=1&mute`;
  await page.goto(url(first));await page.locator('#play').waitFor({state:'visible',timeout:120000});
  const customised=await page.evaluate(async()=>{
    const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');
    const fh=await game.getFileHandle('options'),old=await(await fh.getFile()).text();
    const modified=old.replace('volume.sound=0.9900','volume.sound=0.3300').replace('volume.dialog=0.5090','volume.dialog=0.7700');
    const w=await fh.createWritable();await w.write(modified);await w.close();
    const save=await game.getDirectoryHandle('SAVE',{create:true}),saveFile=await save.getFileHandle('sound-test-sentinel',{create:true}),sw=await saveFile.createWritable();
    await sw.write('retain synthetic save');await sw.close();return modified;
  });
  assert.match(customised,/volume\.sound=0\.3300/);
  updated=true;await page.reload();await page.locator('#play').waitFor({state:'visible',timeout:120000});
  const preserved=await page.evaluate(async()=>{
    const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment'),save=await game.getDirectoryHandle('SAVE');
    return {options:await(await(await game.getFileHandle('options')).getFile()).text(),save:await(await(await save.getFileHandle('sound-test-sentinel')).getFile()).text()};
  });
  assert.equal(preserved.options,customised);assert.equal(preserved.save,'retain synthetic save');
  await page.goto(url(second));await page.locator('#play').waitFor({state:'visible',timeout:120000});
  const installed=await page.evaluate(async()=>{const root=await navigator.storage.getDirectory(),game=await root.getDirectoryHandle('korsary2-game-lazy-experiment');return await(await(await game.getFileHandle('options')).getFile()).text();});
  assert.equal(installed,fresh);
  console.log('Fresh sound defaults and preservation of existing settings and SAVE: PASS');
} finally {await context?.close();for(const s of [first,second])await new Promise(ok=>s.close(ok));}
