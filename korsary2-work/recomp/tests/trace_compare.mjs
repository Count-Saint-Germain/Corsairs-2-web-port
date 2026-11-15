#!/usr/bin/env node
import fs from 'node:fs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {main} from '../../../korsary2-next/recomp/tests/trace_compare.mjs';
const project=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'../..');
const config=JSON.parse(fs.readFileSync(path.join(project,'port.json'),'utf8'));
const args=process.argv.slice(2);
if(!args.includes('--exe'))args.push('--exe',path.join(project,'game',config.exe));
if(!args.includes('--lib'))args.push('--lib',path.join(project,'recomp/build/libporttrace.dylib'));
main(args).catch(e=>{console.error(e);process.exitCode=1;});
