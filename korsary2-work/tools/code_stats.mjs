#!/usr/bin/env node
import {main} from '../../korsary2-next/tools/code_stats.mjs';
main(process.argv.slice(2)).catch(error=>{console.error(error.message);process.exitCode=1;});
