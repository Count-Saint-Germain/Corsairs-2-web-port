#!/usr/bin/env node
/** List PE32 imported libraries and symbols. */
import {readPeImage} from '../recomp/translator/pe_image.mjs';
const file=process.argv[2];if(!file){console.error('Usage: node tools/imports.mjs FILE');process.exitCode=2;}
else try{const pe=readPeImage(file);for(const group of pe.imports){const names=group.entries.map(e=>e.name??`#${e.ordinal}`).sort();console.log(`${group.library} : ${names.join(', ')}`);}}catch(e){console.error(e.message);process.exitCode=1;}
