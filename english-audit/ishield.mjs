#!/usr/bin/env node
/** Read InstallShield 6 data1.hdr/dataN.cab archives directly from ISO images. */
import fs from 'node:fs';
import path from 'node:path';
import zlib from 'node:zlib';
import {pathToFileURL} from 'node:url';
import {Iso} from './isoread.mjs';

const cp1252 = new TextDecoder('windows-1252');
function safeNumber(value, name){if(value>BigInt(Number.MAX_SAFE_INTEGER))throw new Error(`${name} exceeds safe integer range`);return Number(value);}
function within(root, child){const rel=path.relative(root,child);return rel===''||(!path.isAbsolute(rel)&&rel!=='..'&&!rel.startsWith(`..${path.sep}`));}
export class Vol {
  constructor(iso, entry){this.iso=iso;this.e=entry;this.size=entry.size;}
  pread(off,n){if(!Number.isSafeInteger(off)||off<0||!Number.isSafeInteger(n)||n<0)throw new Error('invalid archive offset');n=Math.min(n,this.size-off);if(n<=0)return Buffer.alloc(0);const first=Math.floor(off/2048),last=Math.floor((off+n-1)/2048),data=this.iso.sector(this.e.lba+first,last-first+1),start=off-first*2048;return data.subarray(start,start+n);}
}
export class IS {
  constructor(paths){
    this.isos=[];this.vols=new Map();
    try {for(const p of paths)this.isos.push(new Iso(p));const hdr=this._find('data1.hdr');if(!hdr)throw new Error('data1.hdr not found');this.hdr=hdr.iso.readFile(hdr.entry);this._parse();}
    catch(e){this.close();throw e;}
  }
  close(){for(const iso of this.isos)iso.close();}
  _find(name){for(const iso of this.isos){const entry=iso.lookup(name);if(entry)return {iso,entry};}return null;}
  vol(index){if(!this.vols.has(index)){const found=this._find(`data${index}.cab`);if(!found){const e=new Error(`data${index}.cab`);e.code='ENOENT';throw e;}this.vols.set(index,new Vol(found.iso,found.entry));}return this.vols.get(index);}
  _parse(){
    const h=this.hdr;if(h.length<20)throw new Error('truncated InstallShield header');
    const sig=h.readUInt32LE(0),ver=h.readUInt32LE(4),cdo=h.readUInt32LE(12);
    if(sig!==0x28635349)throw new Error(`invalid InstallShield signature: ${sig.toString(16)}`);
    this.version=ver;this.major=(ver>>>24)===1?(ver>>>12)&15:Math.floor((ver&0xffff)/100);
    let p=cdo+0x0c;const fto=h.readUInt32LE(p),dc=h.readUInt32LE(p+16);p+=28;
    const fc=h.readUInt32LE(p),fto2=h.readUInt32LE(p+4),base=cdo+fto;
    this.cdo=cdo;this.fto=fto;this.dc=dc;this.fc=fc;
    function cstr(off){if(off<0||off>=h.length)throw new Error('invalid InstallShield string offset');const end=h.indexOf(0,off);if(end<0)throw new Error('unterminated InstallShield string');return cp1252.decode(h.subarray(off,end)).replace(/[\u0081\u008d\u008f\u0090\u009d]/g, '\ufffd');}
    this.dirs=[];for(let i=0;i<dc;i++)this.dirs.push(cstr(base+h.readUInt32LE(base+i*4)));
    this.files=[];
    for(let i=0;i<fc;i++){
      const o=base+fto2+i*0x57;let nameOff,dirIdx,flags,exp,comp,off,vol;
      if(this.major<=5){nameOff=h.readUInt32LE(o);dirIdx=h.readUInt32LE(o+4);flags=h.readUInt16LE(o+8);exp=h.readUInt32LE(o+10);comp=h.readUInt32LE(o+14);off=h.readUInt32LE(o+0x12+0x14);vol=1;}
      else {flags=h.readUInt16LE(o);exp=safeNumber(h.readBigUInt64LE(o+2),'expanded size');comp=safeNumber(h.readBigUInt64LE(o+10),'compressed size');off=safeNumber(h.readBigUInt64LE(o+18),'offset');nameOff=h.readUInt32LE(o+58);dirIdx=h.readUInt16LE(o+62);vol=h.readUInt16LE(o+85);}
      this.files.push({i,name:cstr(base+nameOff),dir:this.dirs[dirIdx]??'',flags,exp,comp,off,vol});
    }
  }
  path(file){return `${file.dir.replace(/^\\+|\\+$/g,'')}\\${file.name}`.replace(/^\\+|\\+$/g,'');}
  readFile(file){
    if(file.flags&8)return Buffer.alloc(0);
    const volume=this.vol(file.vol);let pos=file.off,left=file.comp;
    if(!(file.flags&4))return volume.pread(pos,file.exp);
    const chunks=[];
    while(left>0){
      if(pos>=volume.size||left<2)throw new Error(`split or truncated file beyond volume (not supported): ${this.path(file)}`);
      const length=volume.pread(pos,2);if(length.length!==2)throw new Error('truncated InstallShield chunk length');
      const n=length.readUInt16LE(0);pos+=2;left-=2;
      if(n>left||pos+n>volume.size)throw new Error(`split or truncated file beyond volume (not supported): ${this.path(file)}`);
      const blob=volume.pread(pos,n);pos+=n;left-=n;
      chunks.push(zlib.inflateRawSync(Buffer.concat([blob,Buffer.from([0,0,255,255])]),{finishFlush:zlib.constants.Z_SYNC_FLUSH}));
    }
    return Buffer.concat(chunks);
  }
}
function safeOutput(root,relative){
  const parts=relative.replaceAll('\\','/').split('/');if(parts.some(x=>!x||x==='.'||x==='..'||x.includes('\0')))throw new Error(`unsafe archive path: ${relative}`);
  let parent=root;
  for(const part of parts.slice(0,-1)){parent=path.join(parent,part);try{fs.mkdirSync(parent);}catch(e){if(e.code!=='EEXIST')throw e;}parent=fs.realpathSync(parent);if(!within(root,parent)||!fs.statSync(parent).isDirectory())throw new Error(`unsafe archive directory: ${relative}`);}
  const target=path.join(parent,parts.at(-1));if(!within(root,target))throw new Error(`unsafe archive path: ${relative}`);return target;
}
function main(args){
 if(args.length<2||args.includes('--help')){console.log('Usage: node english-audit/ishield.mjs LIST ISO... | EXTRACT OUTDIR REGEX ISO...');return args.includes('--help')?0:2;}
 const [command,...rest]=args;
 if(command==='LIST') {const archive=new IS(rest);try{for(const f of archive.files)console.log(`${f.i}\t${f.vol}\t${f.exp}\t${archive.path(f)}`);}finally{archive.close();}return 0;}
 if(command==='EXTRACT'&&rest.length>=3){const [out,pattern,...images]=rest;const regex=new RegExp(pattern,'i'),archive=new IS(images);try{fs.mkdirSync(out,{recursive:true});const root=fs.realpathSync(out);for(const f of archive.files){const relative=archive.path(f);if(!regex.test(relative))continue;const target=safeOutput(root,relative),data=archive.readFile(f);if(data.length!==f.exp)console.error(`WARN size ${relative}: ${data.length} != ${f.exp}`);try{fs.writeFileSync(target,data,{flag:'wx',mode:0o600});}catch(e){if(e.code!=='EEXIST')throw e;const existing=fs.lstatSync(target);if(!existing.isFile()||existing.isSymbolicLink()||!fs.readFileSync(target).equals(data))throw new Error(`refusing to overwrite: ${target}`);}}}finally{archive.close();}return 0;}
 throw new Error(`invalid command: ${command}`);
}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{process.exitCode=main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
