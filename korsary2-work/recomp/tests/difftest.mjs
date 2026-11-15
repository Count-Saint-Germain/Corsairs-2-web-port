#!/usr/bin/env node
import {main} from '../../../korsary2-next/recomp/tests/difftest.mjs';
main(process.argv.slice(2)).catch(e=>{console.error(e);process.exitCode=1;});
