#!/usr/bin/env node
// Mutate copies of kernel32.c and require the save-language tests to detect each change.
import { cpSync, mkdtempSync, mkdirSync, readFileSync, rmSync, writeFileSync } from 'node:fs';
import { dirname, join, resolve } from 'node:path';
import { tmpdir } from 'node:os';
import { fileURLToPath } from 'node:url';
import { spawnSync } from 'node:child_process';
const tests = dirname(fileURLToPath(import.meta.url)), recomp = resolve(tests, '..');
const src = readFileSync(join(recomp, 'host', 'kernel32.c'), 'utf8');
const arm = 'lang[0] ? " kind=%s slot=%s prior=%s size=%llu sha=%s meta=%s lang=%s" :';
const mutants = [
  ['no label on a genuine creation', '        save_meta_write(slot, guest_time_100ns());\n        save_lang_on_create(slot);', '        save_meta_write(slot, guest_time_100ns());', 'meta'],
  ['label even in the Russian mode', '    if (overlay_active()) save_lang_write(slot, "en");', '    if (1) save_lang_write(slot, "en");', 'meta'],
  ['delete keeps the label', '    save_lang_delete(slot);   /* the language label goes with the slot, whatever mode deletes it */', '', 'meta'],
  ['move keeps the label', '            if (save_lang_locate(ssl, sp, sizeof sp)) {   /* the language label moves with its slot */', '            if (0 && save_lang_locate(ssl, sp, sizeof sp)) {', 'meta'],
  ['any two bytes are a label', "    return (b[0] == 'e' && b[1] == 'n') || (b[0] == 'r' && b[1] == 'u');", '    return 1;', 'meta'],
  ['a stale label claims the new slot', '        if (stat(path, &st) == 0) unlink(path);', '        (void)st;', 'meta'],
  ['an in-place rewrite relabels', '    } else if ((disp == 2 || disp == 5) && existed && !save_meta_exists(slot))\n        save_meta_write(slot, guest_time_100ns());   /* legacy slot without a record */', '    } else if ((disp == 2 || disp == 5) && existed && !save_meta_exists(slot)) {\n        save_meta_write(slot, guest_time_100ns());\n    }\n    if ((disp == 2 || disp == 5) && existed && overlay_active()) save_lang_write(slot, "en");', 'meta'],
  ['SAVE_TX arm never carries the label', arm, '0 ? ' + arm.slice('lang[0] ? '.length), 'tx'],
  ['SAVE_TX arm always carries lang=', arm, '1 ? ' + arm.slice('lang[0] ? '.length), 'tx'],
];
let survived = 0;
const temp = mkdtempSync(join(tmpdir(), 'mutate-save-lang-'));
try {
  for (const [name, old, replacement, which] of mutants) {
    const count = src.split(old).length - 1;
    if (count !== 1) { console.log(`SKIP (occurrences ${count}): ${name}`); survived++; continue; }
    const d = join(temp, 'm'); rmSync(d, { recursive: true, force: true }); mkdirSync(join(d, 'tests'), { recursive: true });
    cpSync(join(recomp, 'host'), join(d, 'host'), { recursive: true });
    writeFileSync(join(d, 'host', 'kernel32.c'), src.replace(old, replacement));
    const test = which === 'meta' ? 'test_save_meta_time.c' : 'test_save_tx.c';
    cpSync(join(tests, test), join(d, 'tests', test));
    const exe = join(d, 't'), flags = ['-DPORT_SAVE_META=1', ...(which === 'tx' ? ['-DPORT_SAVE_TX=1'] : [])];
    const gc = process.platform === 'darwin' ? '-Wl,-dead_strip' : '-Wl,--gc-sections';
    const built = spawnSync('clang', ['-O1', '-g', '-w', '-fsanitize=address,undefined', ...flags, '-I' + join(d, 'host'), '-I' + join(recomp, 'runtime'), join(d, 'tests', test), gc, '-pthread', '-o', exe], { encoding: 'utf8' });
    if (built.error || built.status !== 0) { console.log(`BUILD FAILED: ${name}: ${(built.stderr || built.error?.message || '').slice(0,200)}`); survived++; continue; }
    const run = spawnSync(exe, [], { encoding: 'utf8', timeout: 300000 });
    if (run.error) { console.log(`ERROR: ${name}: ${run.error.message}`); survived++; }
    else if (run.status !== 0) console.log(`killed:   ${name}`);
    else { console.log(`SURVIVED: ${name}`); survived++; }
  }
} finally { rmSync(temp, { recursive: true, force: true }); }
console.log(survived ? `${survived} mutant(s) survived or were skipped` : 'all mutants killed');
if (survived) process.exitCode = 1;
