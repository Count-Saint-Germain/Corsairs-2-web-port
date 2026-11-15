import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import { promises as fsp } from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import { restoreVoice } from '../scripts/restore_russian_voice.mjs';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const ffmpeg = spawnSync('ffmpeg', ['-version'], {stdio:'ignore'}).status === 0;
const ffprobe = spawnSync('ffprobe', ['-version'], {stdio:'ignore'}).status === 0;
async function fixture(t) {
  const dir = await fsp.mkdtemp(path.join(root, 'tests', '.voice-fixture-'));
  t.after(() => fsp.rm(dir,{recursive:true,force:true}));
  const sounds = path.join(dir, 'RESOURCE', 'Sounds');
  await fsp.mkdir(path.join(sounds,'VOICE','RUSSIAN'), {recursive:true});
  return {dir, sounds};
}
function makeOgg(file) {
  const result = spawnSync('ffmpeg',['-v','error','-f','lavfi','-i','sine=frequency=440:sample_rate=16000:duration=0.03','-ac','2','-c:a','vorbis','-strict','experimental','-y',file],{encoding:'utf8'});
  assert.equal(result.status,0,result.stderr);
}

test('restores canonical PCM WAV to both locations and preserves existing data', {skip:!ffmpeg||!ffprobe}, async t => {
  const {dir,sounds}=await fixture(t);
  const russian=path.join(sounds,'VOICE','RUSSIAN');
  makeOgg(path.join(russian,'line.ogg'));
  const sentinel=Buffer.from('existing data');
  await fsp.writeFile(path.join(sounds,'VOICE','line.wav'),sentinel);
  assert.deepEqual(await restoreVoice(dir),{game:await fsp.realpath(dir),sources:1,created:1,skipped:1});
  const wav=await fsp.readFile(path.join(russian,'line.wav'));
  assert.equal(wav.toString('ascii',0,4),'RIFF');
  assert.equal(wav.toString('ascii',8,16),'WAVEfmt ');
  assert.equal(wav.toString('ascii',36,40),'data');
  assert.equal(wav.readUInt32LE(40),wav.length-44);
  assert.equal(wav.readUInt32LE(24),16000);
  assert.deepEqual(await fsp.readFile(path.join(sounds,'VOICE','line.wav')),sentinel);
  assert.equal((await restoreVoice(dir)).skipped,2);
  assert.ok(!(await fsp.readdir(sounds)).some(x=>x.startsWith('.sound-')));
});

test('effects mode skips voice and music and restores nested effects', {skip:!ffmpeg||!ffprobe}, async t => {
  const {dir,sounds}=await fixture(t);
  await fsp.mkdir(path.join(sounds,'EFFECTS','NESTED'),{recursive:true});
  await fsp.mkdir(path.join(sounds,'MUSIC'),{recursive:true});
  makeOgg(path.join(sounds,'EFFECTS','NESTED','tone.ogg'));
  makeOgg(path.join(sounds,'MUSIC','song.ogg'));
  const result=await restoreVoice(dir,{effects:true});
  assert.equal(result.sources,1); assert.equal(result.created,1);
  assert.ok(fs.existsSync(path.join(sounds,'EFFECTS','NESTED','tone.wav')));
  assert.ok(!fs.existsSync(path.join(sounds,'MUSIC','song.wav')));
});

test('rejects game directories and sound symlinks outside the project copy', async t => {
  const outside=await fsp.mkdtemp(path.join(os.tmpdir(),'k2-voice-outside-'));
  t.after(()=>fsp.rm(outside,{recursive:true,force:true}));
  await assert.rejects(restoreVoice(outside),/inside web-port/);
  const {dir,sounds}=await fixture(t);
  const external=path.join(outside,'outside.ogg');
  await fsp.writeFile(external,'not audio');
  await fsp.symlink(external,path.join(sounds,'VOICE','RUSSIAN','link.ogg'));
  await assert.rejects(restoreVoice(dir),/escapes the sound directory/);
  assert.equal(await fsp.readFile(external,'utf8'),'not audio');
});
