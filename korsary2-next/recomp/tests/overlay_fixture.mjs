/** Synthetic game and English overlay for integration tests, built by the real Node packager. */
import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
import { buildDistribution } from '../web/make_dist.mjs';
const sha=b=>createHash('sha256').update(b).digest('hex');
const lang=Buffer.from('[COMMON]\r\ndefaultLanguage = russian\r\n[DIRECTORY]\r\nruss = RUSSIAN\r\neng = ENGLISH\r\n'+'; padding so that the file compresses\r\n'.repeat(20));
function randomGenerator(initial){let s=initial;return ()=>{s^=s<<13;s^=s>>>17;s^=s<<5;return s>>>0;};}
function bytes(seed,n){const rand=randomGenerator(seed),b=Buffer.alloc(n);for(let i=0;i<n;i++)b[i]=rand()&255;return b;}
function text(seed,n){const rand=randomGenerator(seed),words=['sail','cannon','rum','gold','fort','wind','harbour','captain','treasure','island','storm','crew'];let result='';while(result.length<n)result+=words[rand()%words.length]+' ';return Buffer.from(result.slice(0,n));}
function baseFiles(n=24,big=false){const files={
 'ENGINE.exe':Buffer.from(Array.from({length:2048},(_,i)=>i%256)),'options':Buffer.from('options v1\r\n'.repeat(10)),'engine.ini':Buffer.from('[engine]\r\n'.repeat(10)),
 'PROGRAM/seadogs.c':text(1,4000),'PROGRAM/DIALOGS/blaze_dialog.h':text(2,6000),'PROGRAM/DIALOGS/eng_dialog.h':text(3,5000),'PROGRAM/Characters/Characters_names.c':text(4,3000),
 'RESOURCE/INI/TEXTS/language.ini':lang,'RESOURCE/INI/fonts.ini':text(5,1500),'RESOURCE/QUESTSTEXT/quests_texts.txt':text(6,9000),'RESOURCE/INI/TEXTS/ENGLISH/common.ini':text(7,2500),'RESOURCE/INI/TEXTS/ENGLISH/ItemsDescribe.txt':text(8,3500),'RESOURCE/Sounds/VOICE/Eng_m_a_001.wav':bytes(9,3000),'SAVE/slot1':Buffer.from('PLAYER SAVE - never packaged'),
 'PROGRAM/CONTROLS/controls.c':text(13,1200),'PROGRAM/CONTROLS/init_pc.c':text(14,1200)};
 for(const module of ['XINTERFACE','DX8RENDER','SOUND','PCS_CONTROLS'])files[`MODULES/${module}.dll`]=Buffer.concat([Buffer.from('MZ'),Buffer.alloc(300)]);
 for(let i=0;i<n;i++)files[`RESOURCE/Models/loc${String(Math.floor(i/6)).padStart(2,'0')}/obj${String(i).padStart(3,'0')}.gm`]=text(100+i,800+97*i);if(big)files['RESOURCE/Textures/big.tx']=bytes(11,1300000);return files;}
function overlayFilesData(n=40,big=false){const files={
 'RESOURCE/INI/TEXTS/language.ini':Buffer.from(lang.toString().replace('russian','English')),'RESOURCE/INI/fonts.ini':text(55,1500),'RESOURCE/QUESTSTEXT/quests_texts.txt':text(66,8800),'RESOURCE/INI/TEXTS/ENGLISH/common.ini':text(77,2600),'RESOURCE/INI/TEXTS/ENGLISH/ItemsDescribe.txt':text(88,3600),'PROGRAM/Characters/Characters_names.c':text(44,3100),'PROGRAM/DIALOGS/blaze_dialog.h':text(22,5900),'RESOURCE/Sounds/VOICE/Eng_m_a_002.wav':bytes(99,2500)};
 for(let i=0;i<n;i++)files[`PROGRAM/DIALOGS/q${String(i).padStart(3,'0')}_dialog.h`]=text(200+i,700+61*i);if(big)files['RESOURCE/Sounds/VOICE/Eng_long.wav']=bytes(12,1400000);return files;}
function writeTree(root,files){for(const [name,data] of Object.entries(files)){const file=path.join(root,name);fs.mkdirSync(path.dirname(file),{recursive:true});fs.writeFileSync(file,data);}}
export async function buildFixture(out,{layout='pack',overlay=true,nExtra=24,nOverlay=40,big=false,baseOf,mutateOverlay,overlayName='en',overlayNoRequiredCheck=false,overlaySkipBaseCheck=false}={}){
 const gameSrc=path.join(out,'game-src'),overlaySrc=path.join(out,'overlay-src'),dist=path.join(out,'dist'),build=path.join(out,'fake-build'),base=baseFiles(nExtra,big);writeTree(gameSrc,base);fs.mkdirSync(build,{recursive:true});
 fs.writeFileSync(path.join(build,'game.js'),"var _port_video_poll = 1, _port_video_done = 2, _port_video_name_buf = 3; var wasmBinaryFile = 'game.wasm';\n");fs.writeFileSync(path.join(build,'game.wasm'),Buffer.concat([Buffer.from([0,97,115,109,1,0,0,0]),Buffer.alloc(64),Buffer.from('port_video_poll\0port_video_done\0port_video_name_buf\0')]));
 const opts={game:gameSrc,out:dist,videos:path.join(out,'no-videos'),buildDir:build,overlayName,overlayNoRequiredCheck,overlaySkipBaseCheck};if(layout==='d1')opts.noPack=true;else if(layout==='d1br'){opts.noPack=true;opts.codec='br';opts.quality=5;}else if(layout==='pack-raw')opts.noCompress=true;else if(layout==='brpack'){opts.codec='br';opts.quality=5;}else if(layout==='plain'){opts.noCompress=true;opts.noPack=true;}else if(layout!=='pack')throw new Error(`unknown layout ${layout}`);
 let count=0;if(overlay){const files=overlayFilesData(nOverlay,big);writeTree(overlaySrc,files);const both=baseOf??Object.keys(files).filter(p=>p in base),meta={format:1,language:'English',generator:'overlay_fixture',base:Object.fromEntries(both.map(p=>[p,sha(base[p])]))};fs.writeFileSync(path.join(overlaySrc,'OVERLAY.json'),JSON.stringify(meta,null,2)+'\n');if(mutateOverlay)await mutateOverlay(overlaySrc);opts.overlayDir=overlaySrc;count=Object.keys(files).length;}
 const result=await buildDistribution(opts);return {out,dist,game_src:gameSrc,...overlay?{overlay_src:overlaySrc,overlay_files:count,overlay_version:result.overlay.version,overlay_entries:result.overlay.files.length,overlay_packs:result.overlay.packs?.length??0}:{},game_manifest:result.manifest.version};
}
