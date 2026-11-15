import { test } from 'node:test';
import assert from 'node:assert/strict';
import { spawnSync } from 'node:child_process';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { AssetError, parse_tx, same_layout, parse_wav, alias_sections, alias_voice_names, alias_compat, script_voice_names, script_loading_names, DEFAULT_RELOCATE, parse_relocate_rules, relocations, ffmpeg_cmd, tool_version, probe_video } from '../../tools/english_assets.mjs';

function tx({w=4,h=4,fmt=23,mips=1,size=32}={}) { const b=Buffer.alloc(24+size); [0,w,h,mips,fmt,size].forEach((n,i)=>b.writeUInt32LE(n,i*4));return b; }
function wav(){const b=Buffer.alloc(48); b.write('RIFF',0);b.writeUInt32LE(40,4);b.write('WAVEfmt ',8);b.writeUInt32LE(16,16);b.writeUInt16LE(1,20);b.writeUInt16LE(2,22);b.writeUInt32LE(44100,24);b.writeUInt32LE(176400,28);b.writeUInt16LE(4,32);b.writeUInt16LE(16,34);b.write('data',36);b.writeUInt32LE(4,40);return b;}
test('validates TX texture layouts, dimensions, mip sizes and formats',()=>{
 const a=parse_tx(tx()),b=parse_tx(tx());assert.deepEqual(a,{width:4,height:4,mips:1,fmt:23,fmt_name:'R5G6B5',size:56});assert.ok(same_layout(a,b));assert.ok(!same_layout(a,{...b,width:2}));
 const dxt=tx({fmt:0x31545844,size:8});assert.equal(parse_tx(dxt).fmt_name,'DXT1');
 for(const bad of [Buffer.alloc(23),tx({w:0}),tx({fmt:999}),tx({mips:2}),tx().subarray(0,30)])assert.throws(()=>parse_tx(bad),AssetError);
 const sizeMismatch=tx();sizeMismatch.writeUInt32LE(7,20);assert.throws(()=>parse_tx(sizeMismatch),/first mip size/);
});
test('validates canonical WAV header and rejects corrupt PCM and sizes',()=>{
 assert.deepEqual(parse_wav(wav()),{channels:2,rate:44100,bits:16,data:4});
 for(const mutate of [(b)=>b.write('X',0),(b)=>b.writeUInt16LE(3,20),(b)=>b.writeUInt16LE(8,34),(b)=>b.writeUInt16LE(4,22),(b)=>b.writeUInt32LE(100,40),(b)=>b.writeUInt32LE(100,28)]){const b=wav();mutate(b);assert.throws(()=>parse_wav(b),AssetError);}
 assert.throws(()=>parse_wav(Buffer.alloc(44)),/45 bytes/);
});
test('parses aliases case-insensitively, skips comments, checks parameters and duplicates',()=>{
 const ru=Buffer.from('[First]\r\nname = VOICE\\Ru.WAV\r\nvolume = 2\r\n; name = VOICE\\ignored.wav\r\n[Second]\nname=VOICE\\sub\\bad.wav\n');
 const us=Buffer.from('[first]\nname=voice\\en.wav\nvolume=2\n[SECOND]\nname=voice\\x.wav\n');
 const [order,sections]=alias_sections(ru);assert.deepEqual(order,['first','second']);assert.deepEqual(sections.first,[['name','voice\\ru.wav'],['volume','2']]);
 assert.deepEqual(alias_voice_names(ru),new Set(['ru.wav']));assert.deepEqual(alias_compat(ru,us),[]);
 assert.equal(alias_compat(ru,Buffer.from(us.toString().replace('volume=2','volume=3'))).length,1);
 assert.equal(alias_compat(ru,Buffer.concat([us,Buffer.from('[first]\nname=x\n')])).length,1);
 const proto=alias_sections(Buffer.from('[__proto__]\nname=voice\\safe.wav\n'))[1];assert.deepEqual(proto.__proto__,[['name','voice\\safe.wav']]);
});
test('finds voice and loading script literals using both separators',()=>{
 assert.deepEqual(script_voice_names(Buffer.from('"VOICE\\A.WAV" "voice/sub.wav"')),new Set(['a.wav','sub.wav']));
 assert.deepEqual(script_loading_names(Buffer.from('"Loading\\Sea.TGA" "loading/Tavern_01.tga"')),new Set(['sea','tavern_01']));
});
test('relocates only direct children with case-insensitive file and directory collisions',()=>{
 const rules=parse_relocate_rules(DEFAULT_RELOCATE);assert.equal(rules.length,2);
 assert.deepEqual(relocations(['RESOURCE/Textures/Loading/Russian/Tavern.tx'],rules),{'RESOURCE/Textures/Loading/Russian/Tavern.tx':'RESOURCE/Textures/Loading/Tavern.tx'});
 assert.deepEqual(relocations(['RESOURCE/Textures/Loading/Russian/Tavern.tx','RESOURCE/Textures/Loading/tavern.tx'],rules),{});
 assert.deepEqual(relocations(['RESOURCE/Textures/Loading/Russian/Tavern.tx','RESOURCE/Textures/Loading/Tavern.tx/child'],rules),{});
 assert.deepEqual(relocations(['RESOURCE/Textures/Loading/Russian/nested/x.tx'],rules),{});
 assert.throws(()=>parse_relocate_rules([{from:'a'}]),AssetError);assert.throws(()=>parse_relocate_rules('invalid'),AssetError);
});
test('pinned ffmpeg command retains deterministic audio/video options',()=>{
 const cmd=ffmpeg_cmd('ffmpeg','source.wmv','out.mp4');assert.equal(cmd[0],'ffmpeg');assert.equal(cmd.at(-1),'out.mp4');
 for(const arg of ['+bitexact','libx264','yuv420p','96k','+faststart'])assert.ok(cmd.includes(arg));
 assert.equal(tool_version('k2-nonexistent-binary-23948'),null);
});
test('probes a real bundled video when ffprobe is available',{skip:spawnSync('ffprobe',['-version'],{stdio:'ignore'}).status!==0},()=>{
 const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../../..');
 const result=probe_video('ffprobe',path.join(root,'distribution/videos/English/Invasion.mp4'));
 assert.ok(result.duration>0);assert.equal(result.video[0],'h264');assert.ok(result.video[1]>0&&result.video[2]>0);
});
