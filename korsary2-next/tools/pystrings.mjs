#!/usr/bin/env node
/** Print consecutive ASCII strings from a binary file. */
import fs from 'node:fs';
const [file,minString='5']=process.argv.slice(2), minimum=Number(minString);
if(!file||!Number.isSafeInteger(minimum)||minimum<1){console.error('Usage: node pystrings.mjs FILE [MIN_LENGTH]');process.exitCode=2;}
else try {const data=fs.readFileSync(file);let start=-1;for(let i=0;i<=data.length;i++){const printable=i<data.length&&data[i]>=32&&data[i]<=126;if(printable&&start<0)start=i;if(!printable&&start>=0){if(i-start>=minimum)console.log(data.toString('ascii',start,i));start=-1;}}}
catch(e){console.error(e.message);process.exitCode=1;}
