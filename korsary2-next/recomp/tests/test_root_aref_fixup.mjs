/** Regression tests for the fail-closed generated-code fixup. Run: node --test test_root_aref_fixup.mjs */
import assert from 'node:assert/strict';
import { spawnSync } from 'node:child_process';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import test from 'node:test';
import { applyFixup, digest, fixFunction, FIXED, ORIGINAL } from '../translator/fix_root_aref.mjs';

const recomp = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const generated = fs.readFileSync(path.join(recomp, 'out_all/recomp_000.c'), 'utf8');
const match = generated.match(/^void f_0040eefd\(CPU \*c\) \{[^\n]*\n[\s\S]*?^\}/m);
assert.ok(match, 'expected translated restore function in real generated source');
const original = match[0].replace(FIXED, ORIGINAL);
const temp = () => fs.mkdtempSync(path.join(os.tmpdir(), 'k2-aref-test-'));

function fixture() {
  const root = temp();
  const data = path.join(root, 'project/recomp/data');
  const game = path.join(root, 'project/game');
  const out = path.join(root, 'out');
  for (const dir of [data, game, out]) fs.mkdirSync(dir, {recursive:true});
  const engine = path.join(game, 'ENGINE.exe');
  fs.writeFileSync(engine, 'test engine');
  const manifest = path.join(data, 'images.json');
  fs.writeFileSync(manifest, JSON.stringify({images:[{guest:'ENGINE.exe', tag:'recomp', base:0x400000, path:'../../game/ENGINE.exe'}]}));
  const target = path.join(out, 'recomp_021.c');
  fs.writeFileSync(target, original);
  return {root, out, target, manifest, engineHash: digest(fs.readFileSync(engine))};
}

const cleanup = root => fs.rmSync(root, {recursive:true, force:true});

test('exact original and trace variants are fixed once, preserving nested resolver', () => {
  for (const traced of [false, true]) {
    const source = traced ? original.replace('L_0040f5cf:;\n', 'L_0040f5cf:;\n    trace_insn(c, 0x40f5cfu);\n') : original;
    const fixed = fixFunction(source);
    assert.equal(fixed.changed, true);
    assert.equal(fixed.source.replace(FIXED, ORIGINAL), source);
    assert.deepEqual(fixFunction(fixed.source), {source:fixed.source, changed:false});
    assert.ok(fixed.source.indexOf('L_0040f523:;') < fixed.source.indexOf('L_0040f5cf:;'));
    assert.ok(fixed.source.indexOf('mov dword ptr [eax + 0x4c], ecx') < fixed.source.indexOf(FIXED));
    assert.ok(fixed.source.indexOf(FIXED) < fixed.source.indexOf('call 0x412bb0'));
  }
});

test('manifest-relative engine path, atomic fix, permissions and idempotence', () => {
  const f = fixture();
  try {
    fs.chmodSync(f.target, 0o640);
    const result = applyFixup(f.out, f.manifest, {engineSha256:f.engineHash});
    assert.equal(result.changed, true);
    assert.equal(fs.statSync(f.target).mode & 0o777, 0o640);
    assert.equal(applyFixup(f.out, f.manifest, {engineSha256:f.engineHash}).changed, false);
    assert.equal(fs.readdirSync(f.out).length, 1);
  } finally { cleanup(f.root); }
});

test('wrong engine, modified function, duplicate and symlink refuse without altering input', () => {
  const f = fixture();
  try {
    assert.throws(() => applyFixup(f.out, f.manifest), /SHA-256/);
    assert.equal(fs.readFileSync(f.target, 'utf8'), original);
    const damaged = original.replace('call 0x412bb0', 'call changed');
    fs.writeFileSync(f.target, damaged);
    assert.throws(() => applyFixup(f.out, f.manifest, {engineSha256:f.engineHash}), /unexpected|unknown/);
    assert.equal(fs.readFileSync(f.target, 'utf8'), damaged);
    fs.writeFileSync(f.target, original);
    const duplicate = path.join(f.out, 'recomp_022.c');
    fs.writeFileSync(duplicate, original);
    assert.throws(() => applyFixup(f.out, f.manifest, {engineSha256:f.engineHash}), /found 2/);
    assert.equal(fs.readFileSync(f.target, 'utf8'), original);
    fs.unlinkSync(duplicate);
    const saved = path.join(f.out, 'saved.txt');
    fs.renameSync(f.target, saved);
    fs.symlinkSync(saved, f.target);
    assert.throws(() => applyFixup(f.out, f.manifest, {engineSha256:f.engineHash}), /regular file/);
    assert.equal(fs.readFileSync(saved, 'utf8'), original);
  } finally { cleanup(f.root); }
});

test('translated branch passes selected root and retains nested resolver', () => {
  const fixed = fixFunction(original).source;
  const start = fixed.indexOf('L_0040f5cf:;');
  const end = fixed.indexOf('L_0040f627:;', start);
  assert.ok(start >= 0 && end > start);
  const branch = fixed.slice(start, end);
  const harness = String.raw`
#include <stdint.h>
#include <string.h>
typedef struct { uint32_t ebp,esp,eax,ecx,edx,zf; } CPU;
static uint8_t mem[65536];
static uint32_t selected, resolver_calls, resolver_root, resolver_path;
static uint32_t R32(uint32_t a) { uint32_t x; memcpy(&x, mem+a, 4); return x; }
static void W32(uint32_t a, uint32_t x) { memcpy(mem+a, &x, 4); }
static uint32_t sub32(CPU *c,uint32_t a,uint32_t b) { uint32_t r=a-b; c->zf=(r==0); return r; }
static uint32_t add32(CPU *c,uint32_t a,uint32_t b) { uint32_t r=a+b; c->zf=(r==0); return r; }
#define PUSH32(c,x) do { (c)->esp-=4; W32((c)->esp,(x)); } while(0)
static void f_00412bb0(CPU *c) {
    resolver_calls++; resolver_root=R32(c->esp+4); resolver_path=R32(c->esp+8);
    c->eax=0x5678; c->esp+=12;
}
static void f_0043b0c6(CPU *c) { c->esp+=4; }
static void call_indirect(CPU *c,uint32_t f) { (void)f; selected=R32(c->esp+4); c->esp+=8; }
static void run(CPU *c) { goto L_0040f5cf;
` + branch + String.raw`
}
static int one(uint32_t root,uint32_t pathname,uint32_t expected) {
    CPU c={0}; memset(mem,0,sizeof(mem)); selected=resolver_calls=0;
    c.ebp=0x1000; c.esp=0x8000;
    W32(c.ebp-0x58,pathname); W32(c.ebp-0x88,0x2000); W32(0x2000+0x4c,root);
    W32(c.ebp-0x8c,0x2100); W32(0x2100,0x2200); W32(0x2200+0xc,0x9999);
    W32(c.ebp-0x84,0xdeadbeef); run(&c);
    if (selected!=expected || c.esp!=0x8000) return 0;
    return pathname ? (resolver_calls==1 && resolver_root==root && resolver_path==pathname) : resolver_calls==0;
}
int main(void) { return !(one(0x3100,0,0x3100) && one(0x3200,0,0x3200) &&
                           one(0x3300,0x600,0x5678)); }
`;
  const root = temp();
  try {
    const src = path.join(root, 'branch.c'), binary = path.join(root, 'branch');
    fs.writeFileSync(src, harness);
    const cc = spawnSync('cc', ['-std=c99', '-Wall', '-Werror', src, '-o', binary], {encoding:'utf8'});
    assert.equal(cc.status, 0, cc.stderr);
    const run = spawnSync(binary, [], {encoding:'utf8'});
    assert.equal(run.status, 0, run.stderr);
  } finally { cleanup(root); }
});
