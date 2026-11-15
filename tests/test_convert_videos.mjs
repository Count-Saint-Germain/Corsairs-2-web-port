/** Synthetic checks for the video converter; no real media or ffmpeg needed. */
import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {spawnSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
const original = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '../scripts/convert_videos.sh');
function fixture(t) {
  const tmp=fs.mkdtempSync(path.join(os.tmpdir(),'k2-convert-test-'));
  t.after(()=>fs.rmSync(tmp,{recursive:true,force:true}));
  const root=path.join(tmp,'workspace (тест)'), scripts=path.join(root,'web-port','scripts');
  fs.mkdirSync(scripts,{recursive:true});
  const script=path.join(scripts,'convert_videos.sh');fs.copyFileSync(original,script);fs.copyFileSync(path.join(path.dirname(original),'unicode_casefold.mjs'),path.join(scripts,'unicode_casefold.mjs'));fs.chmodSync(script,0o755);
  const source=path.join(root,'game','RESOURCE','VIDEOS'), out=path.join(root,'web-port','videos-web'), bin=path.join(root,'mock bin'), calls=path.join(root,'ffmpeg-calls');
  fs.mkdirSync(bin,{recursive:true});
  fs.symlinkSync(process.execPath,path.join(bin,'node'));
  function mock(name,contents){const f=path.join(bin,name);fs.writeFileSync(f,contents);fs.chmodSync(f,0o755);}
  mock('ffmpeg',`#!/bin/sh
printf 'call\\n' >> "$K2_TEST_CALLS"
for arg do last=$arg; done
case "\${K2_FFMPEG_MODE:-ok}" in
  fail) printf partial > "$last"; exit 7 ;;
  empty) : > "$last"; exit 0 ;;
  *) printf synthetic > "$last" ;;
esac
`);
  mock('ffprobe','#!/bin/sh\nprintf "0\\n"\n');
  const env={...process.env,PATH:`${bin}:/usr/bin:/bin`,K2_TEST_CALLS:calls,LC_ALL:'C'};
  function run(args=[],override={}){return spawnSync(script,args.map(String),{cwd:tmp,env:{...env,...override},encoding:'utf8'});}
  function video(rel='clip.wmv'){const f=path.join(source,rel);fs.mkdirSync(path.dirname(f),{recursive:true});fs.writeFileSync(f,'fake source');const time=new Date(Date.now()-10000);fs.utimesSync(f,time,time);return f;}
  function oldOutput(rel='clip.mp4'){const f=path.join(out,rel);fs.mkdirSync(path.dirname(f),{recursive:true});fs.writeFileSync(f,'old output');const time=new Date(Date.now()-20000);fs.utimesSync(f,time,time);return f;}
  function assertNoTemporaries(){if (!fs.existsSync(out)) return; const walk=dir=>fs.readdirSync(dir,{withFileTypes:true}).flatMap(e=>e.isDirectory()?walk(path.join(dir,e.name)):[e.name]);assert.ok(!walk(out).some(x=>x.startsWith('.k2-video.')));}
  return {tmp,root,source,out,calls,run,mock,video,oldOutput,assertNoTemporaries};
}
test('missing source and invalid arguments fail safely',t=>{
 const f=fixture(t), result=f.run();assert.notEqual(result.status,0);assert.match(result.stderr,/source video directory is missing/);assert.equal(fs.existsSync(f.out),false);
 assert.equal(f.run(['--help']).status,0);assert.equal(f.run(['--source-dir']).status,2);assert.equal(f.run(['--bad']).status,2);
});
test('handles paths, input formats and up-to-date files',t=>{
 const f=fixture(t);for(const name of ['intro file.WMV','Russian (test)/тест.avi','clip.mpg'])f.video(name);fs.writeFileSync(path.join(f.source,'ignore.txt'),'not video');
 let r=f.run();assert.equal(r.status,0,r.stderr);for(const name of ['intro file.mp4','Russian (test)/тест.mp4','clip.mp4'])assert.equal(fs.readFileSync(path.join(f.out,name),'utf8'),'synthetic');
 assert.equal(fs.readFileSync(f.calls,'utf8').trim().split('\n').length,3);r=f.run();assert.equal(r.status,0,r.stderr);assert.equal((r.stdout.match(/SKIP/g)||[]).length,3);assert.equal(fs.readFileSync(f.calls,'utf8').trim().split('\n').length,3);
 const other=path.join(f.root,'custom output');r=f.run(['--source-dir',f.source,'--output-dir',other]);assert.equal(r.status,0,r.stderr);assert.equal(fs.readFileSync(path.join(other,'Russian (test)/тест.mp4'),'utf8'),'synthetic');f.assertNoTemporaries();
});
test('failed and empty conversions preserve prior output',t=>{
 const f=fixture(t);f.video();const old=f.oldOutput();for(const mode of ['fail','empty']){const r=f.run([],{K2_FFMPEG_MODE:mode});assert.notEqual(r.status,0);assert.equal(fs.readFileSync(old,'utf8'),'old output');f.assertNoTemporaries();}
});
test('successful conversion replaces prior output',t=>{
 const f=fixture(t);f.video();const old=f.oldOutput();const r=f.run();assert.equal(r.status,0,r.stderr);assert.equal(fs.readFileSync(old,'utf8'),'synthetic');f.assertNoTemporaries();
});
test('rename failure preserves prior output',t=>{
 const f=fixture(t);f.video();const old=f.oldOutput();f.mock('mv','#!/bin/sh\nexit 9\n');const r=f.run();assert.notEqual(r.status,0);assert.equal(fs.readFileSync(old,'utf8'),'old output');f.assertNoTemporaries();
});
test('case-insensitive output collisions fail before conversion',t=>{
 const f=fixture(t);f.video('Film.wmv');f.video('film.avi');const old=f.oldOutput('film.mp4');const r=f.run();assert.notEqual(r.status,0);assert.match(r.stderr,/multiple videos map to the same output/);assert.equal(fs.existsSync(f.calls),false);assert.equal(fs.readFileSync(old,'utf8'),'old output');
});
test('Unicode and normalization collisions fail before conversion',t=>{
 const f=fixture(t);for(const [one,two] of [['ТЕСТ.wmv','тест.avi'],['é.wmv','e\u0301.avi']]){f.video(one);f.video(two);const r=f.run();assert.notEqual(r.status,0);assert.match(r.stderr,/multiple videos map to the same output/);assert.equal(fs.existsSync(f.calls),false);assert.equal(fs.existsSync(f.out),false);for(const name of fs.readdirSync(f.source))fs.unlinkSync(path.join(f.source,name));}
});
test('enumeration failure never converts partial results',t=>{
 const f=fixture(t);f.video();f.mock('find','#!/bin/sh\n/usr/bin/find "$@"\nexit 9\n');const r=f.run();assert.notEqual(r.status,0);assert.match(r.stderr,/could not enumerate/);assert.equal(fs.existsSync(f.calls),false);assert.equal(fs.existsSync(f.out),false);
});
test('existing output symlink is never followed',t=>{
 const f=fixture(t);f.video();const target=path.join(f.root,'outside file');fs.writeFileSync(target,'protected');fs.mkdirSync(f.out,{recursive:true});fs.symlinkSync(target,path.join(f.out,'clip.mp4'));const r=f.run();assert.notEqual(r.status,0);assert.equal(fs.readFileSync(target,'utf8'),'protected');assert.equal(fs.existsSync(f.calls),false);
});
test('symlinks in output parent components are rejected',t=>{
 const f=fixture(t);f.video('one/two/clip.wmv');const outside=path.join(f.root,'outside directory');fs.mkdirSync(outside);const protectedFile=path.join(outside,'clip.mp4');fs.writeFileSync(protectedFile,'protected');fs.mkdirSync(f.out,{recursive:true});const one=path.join(f.out,'one');
 for(const component of ['one','two']){if(component==='one')fs.symlinkSync(outside,one,'dir');else{fs.mkdirSync(one);fs.symlinkSync(outside,path.join(one,'two'),'dir');}const r=f.run();assert.notEqual(r.status,0);assert.match(r.stderr,/output parent is unsafe/);assert.equal(fs.readFileSync(protectedFile,'utf8'),'protected');assert.equal(fs.existsSync(f.calls),false);if(component==='one')fs.unlinkSync(one);else{fs.unlinkSync(path.join(one,'two'));fs.rmdirSync(one);}}
});
