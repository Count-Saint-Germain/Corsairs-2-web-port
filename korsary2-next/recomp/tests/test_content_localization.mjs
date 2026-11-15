import { test } from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parsePatch } from '../../tools/prepare_game_core.mjs';
const NEXT=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..');
const decode=new TextDecoder('windows-1251');
test('Russian command labels are patched without changing identifiers',()=>{
 const expected=new Set([
  'sea_Map {Map}\0sea_Map {Карта}', 'sea_SailTo {SailTo}\0sea_SailTo {Плыть к}',
  'sea_Charge {Reload}\0sea_Charge {Перезарядка}', 'sea_Speed {Sails}\0sea_Speed {Паруса}',
  'sea_Ability {UseAbility}\0sea_Ability {Способности}', 'land_FastReload {FastTravel}\0land_FastReload {Быстрый переход}',
  'land_DialogStart {Talk}\0land_DialogStart {Говорить}', 'land_OutDoor {Open}\0land_OutDoor {Открыть}',
  'go_store {store}\0go_store {Магазин}', 'go_shipyard {shipyard}\0go_shipyard {Верфь}',
  'go_tavern {tavern}\0go_tavern {Таверна}', 'go_port {port}\0go_port {Порт}',
 ]);
 const manifest=JSON.parse(fs.readFileSync(path.join(NEXT,'content-patches/expected-manifest.json'),'utf8'));
 const {meta,hunks}=parsePatch(fs.readFileSync(path.join(NEXT,'content-patches/12-commands_name.txt.patch')));
 const reference=manifest.modified.find((e)=>e.path===meta.path);
 assert.equal(meta.path,'RESOURCE/INI/TEXTS/RUSSIAN/commands_name.txt');
 assert.equal(meta['sha256-before'],reference.sha256_before);assert.equal(meta['sha256-after'],reference.sha256_after);
 assert.equal(meta['eol-before'],'crlf');assert.equal(meta['eol-after'],'crlf');
 const pairs=[];let byteDiff=0;
 for(const {before,after} of hunks){
  assert.equal(before.length,after.length);
  for(let i=0;i<before.length;i++){
   const a=Buffer.from(before[i],'latin1'),b=Buffer.from(after[i],'latin1');
   pairs.push(`${decode.decode(a)}\0${decode.decode(b)}`);byteDiff+=b.length-a.length;
  }
 }
 assert.deepEqual(new Set(pairs),expected);assert.equal(pairs.length,expected.size);
 for(const pair of pairs){const [a,b]=pair.split('\0');assert.equal(a.split(' {')[0],b.split(' {')[0]);}
 assert.equal(reference.size_after-reference.size_before,byteDiff);
});
