#!/usr/bin/env node
/** Decode Sea Dogs .tx textures to PNG for visual inspection. */
import fs from 'node:fs';import path from 'node:path';import zlib from 'node:zlib';import {pathToFileURL} from 'node:url';
const FMT=new Map([[21,'A8R8G8B8'],[22,'X8R8G8B8'],[23,'R5G6B5'],[24,'X1R5G5B5'],[25,'A1R5G5B5'],[26,'A4R4G4B4'],[0x31545844,'DXT1'],[0x32545844,'DXT2'],[0x33545844,'DXT3'],[0x34545844,'DXT4'],[0x35545844,'DXT5']]), BPP=new Map([[21,4],[22,4],[23,2],[24,2],[25,2],[26,2]]);
export function levelSize(fmt,w,h){if(fmt===0x31545844)return Math.max(1,Math.ceil(w/4))*Math.max(1,Math.ceil(h/4))*8;if([0x32545844,0x33545844,0x34545844,0x35545844].includes(fmt))return Math.max(1,Math.ceil(w/4))*Math.max(1,Math.ceil(h/4))*16;return BPP.has(fmt)?w*h*BPP.get(fmt):null;}
export function parseTx(bytes){if(bytes.length<24)throw Error('shorter than the 24-byte header');const flags=bytes.readUInt32LE(0),width=bytes.readUInt32LE(4),height=bytes.readUInt32LE(8),mips=bytes.readUInt32LE(12),fmt=bytes.readUInt32LE(16),size0=bytes.readUInt32LE(20);
 if(flags!==0||width<1||width>8192||height<1||height>8192||mips<1||mips>16)throw Error(`unexpected header: flags=${flags} ${width}x${height} mips=${mips}`);if(!FMT.has(fmt))throw Error(`unknown format ${fmt}`);
 const levels=[];let offset=24,w=width,h=height;for(let i=0;i<mips;i++){const size=levelSize(fmt,w,h);levels.push([w,h,offset,size]);offset+=size;w=Math.max(1,Math.floor(w/2));h=Math.max(1,Math.floor(h/2));}
 if(levels[0][3]!==size0)throw Error(`level 0 size ${size0} does not match format size ${levels[0][3]}`);if(offset!==bytes.length)throw Error(`file size ${bytes.length} does not match header size ${offset}`);return {width,height,mips,fmt,fmt_name:FMT.get(fmt),size0,levels,size:offset};}
function c565(v){return [Math.floor(((v>>>11)&31)*255/31),Math.floor(((v>>>5)&63)*255/63),Math.floor((v&31)*255/31)];}
function dxt(bytes,offset,w,h,fmt){const out=Buffer.alloc(w*h*4),bs=fmt===0x31545844?8:16,bw=Math.ceil(w/4),bh=Math.ceil(h/4);
 for(let by=0;by<bh;by++)for(let bx=0;bx<bw;bx++){
  const start=offset+(by*bw+bx)*bs,block=bytes.subarray(start,start+bs),cb=bs===8?block:block.subarray(8),c0=cb.readUInt16LE(0),c1=cb.readUInt16LE(2),p0=c565(c0),p1=c565(c1);let palette;
  if(c0>c1||bs===16)palette=[[...p0,255],[...p1,255],...[[2,1],[1,2]].map(([a,b])=>[...p0.map((v,k)=>Math.floor((a*v+b*p1[k])/3)),255])];
  else palette=[[...p0,255],[...p1,255],[...p0.map((v,k)=>Math.floor((v+p1[k])/2)),255],[0,0,0,0]];
  const indices=cb.readUInt32LE(4);let alpha=null;
  if(fmt===0x32545844||fmt===0x33545844)alpha=Array.from({length:16},(_,i)=>((block[Math.floor(i/2)]>>>(4*(i&1)))&15)*17);
  else if(fmt===0x34545844||fmt===0x35545844){const a0=block[0],a1=block[1],ap=[a0,a1];if(a0>a1)for(let i=1;i<=6;i++)ap.push(Math.floor(((7-i)*a0+i*a1)/7));else{for(let i=1;i<=4;i++)ap.push(Math.floor(((5-i)*a0+i*a1)/5));ap.push(0,255);}const bits=BigInt(block.readUIntLE(2,6));alpha=Array.from({length:16},(_,i)=>ap[Number((bits>>BigInt(3*i))&7n)]);}
  for(let i=0;i<16;i++){const x=bx*4+(i&3),y=by*4+(i>>>2);if(x<w&&y<h){const color=palette[(indices>>>(2*i))&3],pos=(y*w+x)*4;out[pos]=color[0];out[pos+1]=color[1];out[pos+2]=color[2];out[pos+3]=alpha?alpha[i]:color[3];}}
 }return out;}
export function decodeLevel0(info,bytes){const [w,h,offset]=info.levels[0],fmt=info.fmt;if(fmt>=0x31545844&&fmt<=0x35545844)return {width:w,height:h,rgba:dxt(bytes,offset,w,h,fmt)};
 const out=Buffer.alloc(w*h*4);for(let i=0;i<w*h;i++){
  if(fmt===21||fmt===22){const o=offset+4*i;out[4*i]=bytes[o+2];out[4*i+1]=bytes[o+1];out[4*i+2]=bytes[o];out[4*i+3]=fmt===21?bytes[o+3]:255;continue;}
  const v=bytes.readUInt16LE(offset+2*i);let r,g,b,a;if(fmt===23){[r,g,b]=c565(v);a=255;}else if(fmt===24||fmt===25){r=Math.floor(((v>>>10)&31)*255/31);g=Math.floor(((v>>>5)&31)*255/31);b=Math.floor((v&31)*255/31);a=(v>>>15)||fmt===24?255:0;}else{r=((v>>>8)&15)*17;g=((v>>>4)&15)*17;b=(v&15)*17;a=(v>>>12)*17;}out.set([r,g,b,a],i*4);
 }return {width:w,height:h,rgba:out};}
const crcTable=Array.from({length:256},(_,n)=>{let c=n;for(let k=0;k<8;k++)c=(c&1)?(0xedb88320^(c>>>1)):(c>>>1);return c>>>0;});
function crc32(bytes){let c=0xffffffff;for(const b of bytes)c=crcTable[(c^b)&255]^(c>>>8);return (c^0xffffffff)>>>0;}
function chunk(type,data){const t=Buffer.from(type),out=Buffer.alloc(12+data.length);out.writeUInt32BE(data.length,0);t.copy(out,4);data.copy(out,8);out.writeUInt32BE(crc32(Buffer.concat([t,data])),8+data.length);return out;}
export function pngBytes(width,height,rgba,scale=1){if(!Number.isInteger(scale)||scale<1)throw Error('scale must be a positive integer');if(rgba.length!==width*height*4)throw Error('invalid RGBA data');let w=width,h=height,pixels=rgba;
 if(scale>1){w=Math.floor(width/scale);h=Math.floor(height/scale);if(!w||!h)throw Error('scale is larger than image dimensions');pixels=Buffer.alloc(w*h*4);for(let y=0;y<h;y++)for(let x=0;x<w;x++)rgba.copy(pixels,(y*w+x)*4,(y*scale*width+x*scale)*4,(y*scale*width+x*scale)*4+4);}
 const raw=Buffer.alloc((w*4+1)*h);for(let y=0;y<h;y++)pixels.copy(raw,y*(w*4+1)+1,y*w*4,(y+1)*w*4);
 const header=Buffer.alloc(13);header.writeUInt32BE(w,0);header.writeUInt32BE(h,4);header[8]=8;header[9]=6;
 return Buffer.concat([Buffer.from('89504e470d0a1a0a','hex'),chunk('IHDR',header),chunk('IDAT',zlib.deflateSync(raw,{level:6})),chunk('IEND',Buffer.alloc(0))]);}
function main(args){if(args.includes('--help')||!args.length){console.log('Usage: node english-audit/tx2png.mjs INPUT.tx OUTPUT.png [--scale N] | --header INPUT.tx...');return args.includes('--help')?0:2;}
 const header=args.includes('--header'),i=args.indexOf('--scale'),scale=i<0?1:Number(args[i+1]),files=args.filter((_,n)=>(i<0||n!==i&&n!==i+1)&&args[n]!=='--header');
 if(header){for(const p of files){try{const x=parseTx(fs.readFileSync(p));console.log(`${p}\t${x.width}x${x.height}\tmips=${x.mips}\t${x.fmt_name}\t${x.size}`);}catch(e){console.log(`${p}\tERROR: ${e.message}`);}}return 0;}
 if(files.length!==2)throw Error('expected INPUT.tx and OUTPUT.png');const bytes=fs.readFileSync(files[0]),info=parseTx(bytes),pixels=decodeLevel0(info,bytes);fs.writeFileSync(files[1],pngBytes(pixels.width,pixels.height,pixels.rgba,scale));return 0;}
if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){try{process.exitCode=main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}}
