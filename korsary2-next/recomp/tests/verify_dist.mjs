#!/usr/bin/env node
/** Independently verify a static browser distribution, manifests, assets, and packaging. */
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath,pathToFileURL } from 'node:url';
import { spawnSync } from 'node:child_process';
import { scanTree,fingerprint } from './verify_dist_core.mjs';
import { checkStructure,checkPageModules,checkBuild,checkVideos,checkFreshness,checkSourceGame,checkStability } from './verify_dist_checks.mjs';
import { checkManifest } from './verify_dist_manifest.mjs';
import { checkOverlay,checkOverlayExpected,readOverlayRequired } from './verify_dist_overlay.mjs';

const HERE=path.dirname(fileURLToPath(import.meta.url)),RECOMP=path.resolve(HERE,'..'),PORT=path.resolve(RECOMP,'..');
const DEFAULT_WEB=path.join(RECOMP,'web'),DEFAULT_BUILD=path.join(RECOMP,'build_web/streaming'),DEFAULT_VIDEOS=path.resolve(PORT,'../videos-web'),DEFAULT_PORT_JSON=path.join(PORT,'port.json'),DEFAULT_EXPECTED=path.join(PORT,'english-layer/expected-overlay.json');
const EXCLUDED=['RESOURCE/VIDEOS'];
const SIBLINGS=[{path:'RESOURCE/Sounds',extension:'.ogg',sibling_extension:'.wav',min_sibling_bytes:45}];
const RELOCATIONS=[{from:'RESOURCE/Textures/Loading/Russian',to:'RESOURCE/Textures/Loading'},{from:'RESOURCE/Textures/WorldMap/reload/Russian',to:'RESOURCE/Textures/WorldMap/reload'}];
const directory=p=>{try{return fs.statSync(p).isDirectory();}catch{return false;}};
function settings(p){try{const files=JSON.parse(fs.readFileSync(p,'utf8')).files??{};return {required:Array.isArray(files.required)?files.required:[],excluded:Array.isArray(files.exclude_paths)?files.exclude_paths:EXCLUDED,siblingRules:Array.isArray(files.exclude_if_sibling)&&files.exclude_if_sibling.every(r=>r&&typeof r==='object'&&'extension' in r&&'sibling_extension' in r)?files.exclude_if_sibling:SIBLINGS,relocateRules:Array.isArray(files.relocate_if_absent)&&files.relocate_if_absent.every(r=>r&&typeof r.from==='string'&&typeof r.to==='string')?files.relocate_if_absent:RELOCATIONS};}catch{return {required:[],excluded:EXCLUDED,siblingRules:SIBLINGS,relocateRules:RELOCATIONS};}}
/** Run independent verification blocks and return their checks, warnings and overall status. */
export function verify(dist,options={}){
 const {fullHash=false,minHashes=20,targetHashes=50,sourceGame=null,webSrc=DEFAULT_WEB,buildSrc=DEFAULT_BUILD,requireFresh=false,requireOverlay=false,overlayExpected=null,portJson=DEFAULT_PORT_JSON}=options;
 const videoRoot=options.videosWeb===undefined?(directory(DEFAULT_VIDEOS)?DEFAULT_VIDEOS:null):options.videosWeb,config=settings(portJson);
 const before=fingerprint(dist),files=scanTree(dist).files;
 const blocks=[checkStructure(dist,files),checkManifest(dist,{fullHash,minHashes,targetHashes,...config}),checkVideos(dist,videoRoot),checkPageModules(dist,files),checkBuild(dist)];
 if(requireOverlay||overlayExpected||fs.existsSync(path.join(dist,'game-en'))){let required;try{[required]=readOverlayRequired(path.join(DEFAULT_WEB,'overlay-required.json'));}catch(e){throw new Error(`cannot read required overlay data: ${e.message}`);}
  blocks.splice(2,0,checkOverlay(dist,{required,minHashes,targetHashes,fullHash,mustExist:requireOverlay||!!overlayExpected}));if(overlayExpected)blocks.splice(3,0,checkOverlayExpected(dist,overlayExpected));}
 if(sourceGame)blocks.push(checkSourceGame(dist,sourceGame,fullHash,config.relocateRules));if(webSrc)blocks.push(checkFreshness(dist,webSrc,buildSrc,requireFresh));blocks.push(checkStability(before,fingerprint(dist)));
 return {blocks,ok:blocks.every(b=>b.passed)};
}
export function report(blocks){const lines=[];for(const b of blocks){lines.push(`${b.name.padEnd(13)} ${b.passed?'PASS':'FAIL'}  ${b.counts}`);for(const e of b.failures())lines.push(`    FAIL: ${e}`);for(const w of b.warnings)lines.push(`    WARN: ${w}`);}lines.push(`RESULT: ${blocks.every(b=>b.passed)?'PASS':'FAIL'}`);lines.push('NOTE: snapshot only; does not prevent files changing later and does not test a real host.');return lines.join('\n');}
function parseArgs(argv){const o={};const values={'--dist':'dist','--videos-web':'videosWeb','--min-hashes':'minHashes','--target-hashes':'targetHashes','--source-game':'sourceGame','--port-json':'portJson','--web-src':'webSrc'},flags={'--full-hash':'fullHash','--require-fresh':'requireFresh','--require-overlay':'requireOverlay','--selftest':'selftest'};
 for(let i=0;i<argv.length;i++){const a=argv[i];if(a==='--help'||a==='-h'){console.log('Usage: node verify_dist.mjs --dist DIR [--full-hash] [--source-game DIR] [--require-fresh] [--require-overlay] [--overlay [REFERENCE]] [--no-freshness] [--no-videos-web]');return null;}
  if(a==='--no-freshness'){o.webSrc=null;continue;}if(a==='--no-videos-web'){o.videosWeb=null;continue;}if(a==='--overlay'){o.overlayExpected=argv[i+1]&&!argv[i+1].startsWith('-')?argv[++i]:DEFAULT_EXPECTED;continue;}if(a.startsWith('--overlay=')){o.overlayExpected=a.slice(10);continue;}
  if(flags[a]){o[flags[a]]=true;continue;}const eq=a.indexOf('='),key=eq<0?a:a.slice(0,eq),value=eq<0?argv[++i]:a.slice(eq+1);if(!values[key]||value===undefined||value==='')throw new Error(`invalid option: ${a}`);o[values[key]]=['minHashes','targetHashes'].includes(values[key])?Number(value):value;
 }
 if(!o.selftest&&!o.dist)throw new Error('--dist is required');for(const k of ['minHashes','targetHashes'])if(o[k]!==undefined&&(!Number.isSafeInteger(o[k])||o[k]<0))throw new Error(`${k} must be a nonnegative integer`);return o;}
async function main(){const o=parseArgs(process.argv.slice(2));if(!o)return;if(o.selftest){const tests=['test_verify_dist_core.mjs','test_verify_manifest_node.mjs','test_verify_overlay_node.mjs'].map(p=>path.join(HERE,p));const r=spawnSync(process.execPath,['--test',...tests],{stdio:'inherit'});process.exitCode=r.status??1;return;}
 if(!directory(o.dist)){console.error(`no such directory: ${o.dist}`);process.exitCode=2;return;}const {blocks,ok}=verify(o.dist,o);console.log(report(blocks));process.exitCode=ok?0:1;}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href)main().catch(e=>{console.error(e.message);process.exitCode=1;});
