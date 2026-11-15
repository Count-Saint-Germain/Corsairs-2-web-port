#!/usr/bin/env node
/** Use the canonical recompiler with the working copy's manifest and data. */
import {runCli} from '../../../korsary2-next/recomp/translator/x86toc.mjs';
try {await runCli(process.argv.slice(2));}
catch(error){console.error(`translation failed: ${error.message}`);process.exitCode=1;}
