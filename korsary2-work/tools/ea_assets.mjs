#!/usr/bin/env node
import {main} from '../../korsary2-next/tools/ea_assets.mjs';
try{main(process.argv.slice(2));}catch(e){console.error(e.message);process.exitCode=1;}
