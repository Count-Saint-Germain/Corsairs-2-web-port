#!/usr/bin/env node
/** Restore missing canonical PCM WAVs from the repack's Ogg files. */
import fs from 'node:fs';
import { promises as fsp } from 'node:fs';
import path from 'node:path';
import { spawnSync } from 'node:child_process';
import { pipeline } from 'node:stream/promises';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { randomBytes } from 'node:crypto';

const PORT_ROOT = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
function within(root, child) {
  const relative = path.relative(root, child);
  return relative === '' || (!path.isAbsolute(relative) && relative !== '..' && !relative.startsWith(`..${path.sep}`));
}
function run(command, args) {
  const result = spawnSync(command, args, {encoding: 'utf8', maxBuffer: 4 * 1024 * 1024});
  if (result.error) throw result.error;
  if (result.status !== 0) throw new Error(`${command} failed: ${(result.stderr || '').trim()}`);
  return result.stdout;
}
async function filesRecursively(dir) {
  const result = [];
  for (const entry of await fsp.readdir(dir, {withFileTypes:true})) {
    const name = path.join(dir, entry.name);
    if (entry.isDirectory()) result.push(...await filesRecursively(name));
    else if ((entry.isFile() || entry.isSymbolicLink()) && (await fsp.stat(name)).isFile()) result.push(name);
  }
  return result;
}
function waveHeader(bytes, sampleRate, channels) {
  if (bytes > 0xffffffff - 36) throw new Error('PCM stream is too large for a standard WAV');
  const h = Buffer.alloc(44);
  h.write('RIFF', 0); h.writeUInt32LE(bytes + 36, 4); h.write('WAVEfmt ', 8);
  h.writeUInt32LE(16,16); h.writeUInt16LE(1,20); h.writeUInt16LE(channels,22);
  h.writeUInt32LE(sampleRate,24); h.writeUInt32LE(sampleRate * channels * 2,28);
  h.writeUInt16LE(channels * 2,32); h.writeUInt16LE(16,34);
  h.write('data',36); h.writeUInt32LE(bytes,40);
  return h;
}

export async function restoreVoice(gamePath, {effects = false} = {}) {
  const game = await fsp.realpath(gamePath);
  if (!within(PORT_ROOT, game) || game === PORT_ROOT) throw new Error('game must be a separate copy inside web-port');
  const sounds = await fsp.realpath(path.join(game, 'RESOURCE', 'Sounds'));
  if (!within(game, sounds)) throw new Error('sound directory must remain inside the game copy');
  let voice, russian, sources;
  if (effects) {
    sources = (await filesRecursively(sounds)).filter(p => {
      const first = path.relative(sounds, p).split(path.sep)[0].toLowerCase();
      return path.extname(p).toLowerCase() === '.ogg' && !['voice','music'].includes(first);
    });
  } else {
    voice = await fsp.realpath(path.join(sounds, 'VOICE'));
    russian = await fsp.realpath(path.join(voice, 'RUSSIAN'));
    if (!within(sounds, voice) || !within(voice, russian)) throw new Error('voice directories must remain inside the game copy');
    sources = (await fsp.readdir(russian, {withFileTypes:true})).filter(e => e.isFile() || e.isSymbolicLink()).map(e => path.join(russian,e.name)).filter(p => path.extname(p).toLowerCase() === '.ogg');
  }
  sources.sort();
  if (!sources.length) throw new Error(`no matching Ogg files in ${sounds}`);
  let created = 0, skipped = 0;
  for (const source of sources) {
    const realSource = await fsp.realpath(source);
    if (!within(sounds, realSource)) throw new Error(`source escapes the sound directory: ${source}`);
    if (!(await fsp.stat(realSource)).isFile()) continue;
    const basename = path.basename(source, path.extname(source));
    const destinations = effects ? [path.join(path.dirname(source), `${basename}.wav`)] : [path.join(russian, `${basename}.wav`), path.join(voice, `${basename}.wav`)];
    const missing = [];
    for (const dest of destinations) {
      try { await fsp.stat(dest); skipped++; }
      catch (e) { if (e.code !== 'ENOENT') throw e; missing.push(dest); }
    }
    if (!missing.length) continue;
    const probe = JSON.parse(run('ffprobe',['-v','error','-select_streams','a:0','-show_entries','stream=sample_rate,channels','-of','json',source]));
    const sampleRate = Number(probe.streams?.[0]?.sample_rate), channels = Number(probe.streams?.[0]?.channels);
    if (!Number.isInteger(sampleRate) || sampleRate <= 0 || !Number.isInteger(channels) || channels <= 0 || channels > 0xffff / 2) throw new Error(`invalid audio stream: ${source}`);
    const scratch = await fsp.mkdtemp(path.join(sounds,'.sound-'));
    try {
      const pcm = path.join(scratch,'audio.pcm'), wav = path.join(scratch,'audio.wav');
      run('ffmpeg',['-v','error','-nostdin','-y','-i',source,'-map','0:a:0','-c:a','pcm_s16le','-f','s16le',pcm]);
      const bytes = (await fsp.stat(pcm)).size;
      if (bytes % (channels * 2)) throw new Error(`incomplete PCM frame in ${source}`);
      await fsp.writeFile(wav, waveHeader(bytes,sampleRate,channels), {flag:'wx', mode:0o600});
      await pipeline(fs.createReadStream(pcm), fs.createWriteStream(wav,{flags:'a'}));
      for (const dest of missing) {
        const parent = await fsp.realpath(path.dirname(dest));
        if (!within(sounds, parent)) throw new Error(`destination escapes the sound directory: ${dest}`);
        const temporary = path.join(parent, `.voice-${randomBytes(12).toString('hex')}.wav`);
        try {
          await fsp.copyFile(wav, temporary, fs.constants.COPYFILE_EXCL);
          try { await fsp.link(temporary, dest); created++; }
          catch (e) { if (e.code !== 'EEXIST') throw e; skipped++; }
        } finally { await fsp.rm(temporary,{force:true}); }
      }
    } finally { await fsp.rm(scratch,{recursive:true,force:true}); }
  }
  return {game, sources:sources.length, created, skipped};
}

async function main(args) {
  if (args.includes('--help') || args.includes('-h')) {
    console.log('Usage: node scripts/restore_russian_voice.mjs [--effects] PATH_TO_GAME_COPY'); return;
  }
  const effects = args.includes('--effects'), positional = args.filter(x => x !== '--effects');
  if (positional.length !== 1 || positional[0].startsWith('-')) throw new Error('usage: node scripts/restore_russian_voice.mjs [--effects] PATH_TO_GAME_COPY');
  const result = await restoreVoice(positional[0], {effects});
  console.log(`${result.game}: ${result.sources} source files; created ${result.created} WAVs, kept ${result.skipped} existing WAVs`);
}
if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) main(process.argv.slice(2)).catch(e=>{console.error(e.message);process.exitCode=1;});
