/** Regression test for preservation of FVF texture coordinates; requires clang. */
import test, {before, after} from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {execFileSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '../korsary2-next/recomp');
let tmp, exe;
before(() => {
  tmp = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-fvf-'));
  const source = path.join(tmp, 'fvf.c'); exe = path.join(tmp, 'fvf');
  fs.writeFileSync(source, `
#include <stdio.h>
#include <stdlib.h>
#include "render_rec.c"
int main(int argc, char **argv) {
    if (argc != 2) return 2;
    unsigned dim = (unsigned)strtoul(argv[1], 0, 10);
    unsigned sizebits = dim == 2 ? 0u : dim == 3 ? 1u : 2u;
    unsigned fvf = 0x002u | 0x100u | (sizebits << 16);
    float input[] = {1, 2, 3, 0.25f, 0.5f, 0.75f, 0.875f};
    FvfLayout layout; CVert out;
    fvf_layout(fvf, &layout);
    convert_vertex((const unsigned char *)input, &layout, &out);
    printf("%.6f %.6f %.6f %.6f\\n", out.tc[0][0], out.tc[0][1], out.tc[0][2], out.tc[0][3]);
    return 0;
}`);
  const linker = process.platform === 'darwin' ? '-Wl,-dead_strip' : '-Wl,--gc-sections';
  execFileSync('clang',['-std=gnu11','-ffunction-sections','-fdata-sections',linker,'-I',path.join(root,'host'),'-I',path.join(root,'runtime'),source,'-lm','-o',exe],{stdio:'pipe'});
});
after(() => { if (tmp) fs.rmSync(tmp,{recursive:true,force:true}); });
function coordinates(dimensions) {return execFileSync(exe,[String(dimensions)],{encoding:'utf8'}).trim().split(/\s+/).map(Number);}
test('existing 2D coordinates are passed through',()=>assert.deepEqual(coordinates(2),[0.25,0.5,0,1]));
test('3D coordinates preserve the third component',()=>assert.deepEqual(coordinates(3).slice(0,3),[0.25,0.5,0.75]));
test('4D coordinates preserve all four components',()=>assert.deepEqual(coordinates(4),[0.25,0.5,0.75,0.875]));
