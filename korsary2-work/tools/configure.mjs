#!/usr/bin/env node
import path from 'node:path';import {fileURLToPath} from 'node:url';import {main} from '../../korsary2-next/tools/configure.mjs';
const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
try{main(process.argv.slice(2),root);}catch(e){console.error(e.message);process.exitCode=1;}
