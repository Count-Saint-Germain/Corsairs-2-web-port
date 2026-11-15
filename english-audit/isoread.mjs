#!/usr/bin/env node
/** Read ISO9660/Joliet images without mounting or executing them. */
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath, pathToFileURL} from 'node:url';

const SECTOR = 2048;
function inside(root, candidate) {
  const rel=path.relative(root,candidate);
  return rel === '' || (!path.isAbsolute(rel) && rel !== '..' && !rel.startsWith(`..${path.sep}`));
}
export class Iso {
  constructor(imagePath) {
    this.path=path.resolve(imagePath);
    this.fd=fs.openSync(this.path,'r');
    try {
      this.size=fs.fstatSync(this.fd).size;
      const head=Buffer.alloc(16); fs.readSync(this.fd,head,0,16,0);
      if (head.subarray(0,12).equals(Buffer.from('00ffffffffffffffffffff00','hex'))) {
        this.stride=2352; this.off=head[15]===1?16:24;
      } else {this.stride=SECTOR;this.off=0;}
      this._readVolume();
    } catch (error) {fs.closeSync(this.fd);this.fd=null;throw error;}
  }
  close(){if(this.fd!==null){fs.closeSync(this.fd);this.fd=null;}}
  sector(n,count=1) {
    if (!Number.isSafeInteger(n)||n<0||!Number.isSafeInteger(count)||count<0) throw new Error('invalid ISO sector');
    const out=Buffer.alloc(count*SECTOR);
    for (let i=0;i<count;i++) {
      const bytes=fs.readSync(this.fd,out,i*SECTOR,SECTOR,(n+i)*this.stride+this.off);
      if(bytes!==SECTOR) throw new Error(`truncated ISO sector ${n+i}`);
    }
    return out;
  }
  _readVolume() {
    this.root=null;this.joliet=false;let n=16,pvd=null;
    while (n*this.stride+this.off+SECTOR<=this.size) {
      const d=this.sector(n++),t=d[0];if(d.subarray(1,6).toString('ascii')!=='CD001')break;
      if(t===1 && pvd===null)pvd=d;
      if(t===2 && ['%/@','%/C','%/E'].includes(d.subarray(88,91).toString('ascii'))){pvd=d;this.joliet=true;break;}
      if(t===255)break;
    }
    if(!pvd)throw new Error('no ISO9660 primary volume descriptor');
    this.label=pvd.subarray(40,72).toString('latin1').trim();this.root=this._record(pvd.subarray(156,190));
  }
  _record(record) {
    if(record.length<34||record[0]>record.length||33+record[32]>record.length)throw new Error('invalid ISO directory record');
    const lba=record.readUInt32LE(2),size=record.readUInt32LE(10),flags=record[25],raw=record.subarray(33,33+record[32]);
    let name;
    if(raw.length===1&&raw[0]===0)name='.';
    else if(raw.length===1&&raw[0]===1)name='..';
    else if(this.joliet){const pair=Buffer.from(raw);pair.swap16();name=pair.toString('utf16le').split(';',1)[0];}
    else {name=raw.toString('latin1').split(';',1)[0];if(name.endsWith('.')&&name.length>1)name=name.slice(0,-1);}
    return {name,lba,size,dir:Boolean(flags&2)};
  }
  readExtent(lba,size){return this.sector(lba,Math.ceil(size/SECTOR)).subarray(0,size);}
  listdir(entry){
    if(!entry?.dir)throw new Error('ISO directory not found');
    const data=this.readExtent(entry.lba,entry.size),out=[];
    for(let p=0;p<data.length;){const len=data[p];if(!len){p=(Math.floor(p/SECTOR)+1)*SECTOR;continue;}const e=this._record(data.subarray(p,p+len));p+=len;if(e.name!=='.'&&e.name!=='..')out.push(e);}
    return out;
  }
  lookup(value){let cur=this.root;for(const part of value.replaceAll('\\','/').split('/').filter(Boolean)){if(!cur.dir)return null;cur=this.listdir(cur).find(e=>e.name.toLowerCase()===part.toLowerCase());if(!cur)return null;}return cur;}
  *walk(entry=this.root,prefix='') {for(const e of this.listdir(entry).sort((a,b)=>a.name.toLowerCase()<b.name.toLowerCase()?-1:a.name.toLowerCase()>b.name.toLowerCase()?1:0)){const p=prefix+e.name;if(e.dir){yield [p+'/',0];yield* this.walk(e,p+'/');}else yield [p,e.size];}}
  *readFileChunks(entry,chunk=1<<22){if(!entry||entry.dir)throw new Error('ISO file not found');if(!Number.isSafeInteger(chunk)||chunk<=0||chunk%SECTOR!==0)throw new Error('chunk must be a positive multiple of 2048');let left=entry.size,lba=entry.lba;while(left>0){const n=Math.min(left,chunk),nsec=Math.ceil(n/SECTOR);yield this.sector(lba,nsec).subarray(0,n);lba+=nsec;left-=n;}}
  readFile(entry){return Buffer.concat([...this.readFileChunks(entry)]);}
}
function safeName(name){return name && name!=='.' && name!=='..' && !/[\\/\0]/.test(name);}
function extract(iso,entry,outDir){
  if(!entry||!safeName(entry.name))throw new Error('invalid or missing ISO entry');
  const outputRoot=path.resolve(outDir);fs.mkdirSync(outputRoot,{recursive:true});
  const root=fs.realpathSync(outputRoot);
  function put(e,dst){
    if(!safeName(e.name)||!inside(root,dst))throw new Error(`unsafe ISO output path: ${e.name}`);
    if(e.dir){
      try{fs.mkdirSync(dst);}catch(error){if(error.code!=='EEXIST')throw error;}
      const actual=fs.realpathSync(dst);if(!inside(root,actual)||!fs.statSync(actual).isDirectory())throw new Error('unsafe ISO output directory');
      for(const child of iso.listdir(e))put(child,path.join(actual,child.name));
    } else {
      const fd=fs.openSync(dst,'wx',0o600);
      try{for(const chunk of iso.readFileChunks(e))fs.writeSync(fd,chunk);}finally{fs.closeSync(fd);}
    }
  }
  put(entry,path.join(root,entry.name));
}
function main(args){
  if(args.length<2||args.includes('--help')){console.log('Usage: node english-audit/isoread.mjs IMAGE [ls|tree|cat PATH|extract PATH OUTDIR]');return args.includes('--help')?0:2;}
  const [file,cmd,arg='',out]=args,iso=new Iso(file);
  try{
    if(cmd==='ls'){for(const e of iso.listdir(arg?iso.lookup(arg):iso.root))console.log(`${e.name}${e.dir?'/':''}\t${e.size}`);}
    else if(cmd==='tree'){for(const [p,size] of iso.walk(arg?iso.lookup(arg):iso.root))console.log(`${p}\t${size}`);}
    else if(cmd==='cat'){for(const c of iso.readFileChunks(iso.lookup(arg)))process.stdout.write(c);}
    else if(cmd==='extract'&&out)extract(iso,iso.lookup(arg),out);
    else throw new Error(`invalid command: ${cmd}`);
    return 0;
  }finally{iso.close();}
}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{process.exitCode=main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
