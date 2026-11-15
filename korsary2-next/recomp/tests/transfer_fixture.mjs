// Deterministic distribution fixtures, built by the same Node packer as releases.
import fs from 'node:fs';
import path from 'node:path';
import {PythonRandom} from './python_random.mjs';
import {writeGame} from '../web/make_dist.mjs';
import {manifestFor} from '../web/gamefiles.mjs';

export async function transferFixture(tmp,{brotli=false}={}) {
  const src=path.join(tmp,'src'),files=new Map(),r=new PythonRandom(5);
  const put=(rel,data)=>{const p=path.join(src,rel);fs.mkdirSync(path.dirname(p),{recursive:true});fs.writeFileSync(p,data);files.set(rel,p);};
  const words=Array.from({length:64},()=>Buffer.from(Array.from({length:40},()=>r.range(256))));
  const texty=n=>{const out=Buffer.alloc(n);for(let i=0;i<n;i+=40)words[r.below(words.length)].copy(out,i,0,Math.min(40,n-i));return out;};
  const periodic=(n,period,seed)=>{const b=new PythonRandom(seed).bytes(period),out=Buffer.alloc(n);for(let i=0;i<n;i+=period)b.copy(out,i);return out;};
  const noise=n=>Buffer.from(Array.from({length:n},()=>r.range(256)));
  if(brotli){
    put('RESOURCE/Models/Locations/a.gm',periodic(3_000_000,700_000,1));
    put('RESOURCE/Models/Locations/b.gm',periodic(1_200_000,300_000,2));
    put('RESOURCE/Textures/a.tx',texty(2_000_000));
    for(let i=0;i<6;i++)put('RESOURCE/Models/mid'+i+'.gm',periodic(150_000,40_000+2_000*i,300+i));
    for(let i=0;i<30;i++)put('RESOURCE/Models/small'+String(i).padStart(2,'0')+'.gm',i%2?periodic(20_000+700*i,9_000+150*i,100+i):texty(20_000+700*i));
  }else{
    put('RESOURCE/Textures/a.tx',texty(3_000_000));put('RESOURCE/Models/Locations/b.gm',texty(1_500_000));put('RESOURCE/Models/c.an',texty(700_000));
  }
  put('RESOURCE/Sounds/noise.wav',noise(300_000));put('RESOURCE/Sounds/x.ogg',texty(50_000));put('PROGRAM/s.c',Buffer.from('// small script\n'.repeat(10)));
  if(!brotli)put('PROGRAM/big.c',texty(40_000));put('engine.ini',texty(5000));put('options',Buffer.from('options-bytes'.repeat(20)));
  async function build(name,opts){
    const out=path.join(tmp,name,'game');fs.mkdirSync(out,{recursive:true});
    const [packed,packs,hashes]=await writeGame(files,out,opts);
    const effective=new Map([...files].map(([rel,source])=>[rel,packed.has(rel)?source:path.join(out,rel)]));
    const manifest=manifestFor(effective,packed,packs,hashes);fs.writeFileSync(path.join(out,'manifest.json'),JSON.stringify(manifest));return {manifest,packed};
  }
  if(!brotli){const {packed}=await build('fixture',{pack:false});return {packed:[...packed.keys()].sort(),raw:[...files.keys()].filter(x=>!packed.has(x)).sort()};}
  const flat=(await build('flat',{codec:'br',quality:5,pack:false})).manifest;
  const packs=(await build('packs',{codec:'br',quality:5,pack:true,maxFile:100_000,target:400_000})).manifest;
  const gz=(await build('gz',{codec:'gzip',pack:false})).manifest;
  const count=(m,e)=>m.files.filter(x=>x.enc===e).length,wire=m=>m.files.reduce((a,x)=>a+(x.csize??x.size),0);
  return {flat:[count(flat,'br'),count(flat,'gzip')],packs:[count(packs,'br'),count(packs,'gzip'),packs.packs.length],gz:[count(gz,'br'),count(gz,'gzip')],versions:[flat.version,packs.version,gz.version],wire:[wire(flat),wire(packs),wire(gz)],raw:flat.files.reduce((a,x)=>a+x.size,0)};
}
