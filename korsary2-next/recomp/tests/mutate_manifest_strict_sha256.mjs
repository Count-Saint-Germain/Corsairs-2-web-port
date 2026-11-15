// Мутационная проверка test_manifest_strict_sha256.mjs (N11): каждая мутация web/save-protection.mjs (копия *.mjs во временном
// каталоге, оригинал не трогается) обязана провалить тест; выжившая мутация = дыра в тестах.
//   node korsary2-next/recomp/tests/mutate_manifest_strict_sha256.mjs
import { execFileSync } from 'node:child_process';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const webDir = path.resolve(here, '../web');
const src = fs.readFileSync(path.join(webDir, 'save-protection.mjs'), 'utf8');

// [название, старый текст (ровно одно вхождение), новый текст]
const MUTANTS = [
  ['проверка SHA всех записей удалена', 'if (noSha.length)\n', 'if (false)\n'],
  ['проверяется только первая запись', 'const noSha = files.filter(f => !hasSha256(f));', 'const noSha = files.slice(0, 1).filter(f => !hasSha256(f));'],
  ['проверяется только последняя запись', 'const noSha = files.filter(f => !hasSha256(f));', 'const noSha = files.slice(-1).filter(f => !hasSha256(f));'],
  ['формат sha256 не проверяется (любая строка)', "typeof f?.sha256 === 'string' && HEX64.test(f.sha256)", "typeof f?.sha256 === 'string'"],
  ['sha256 любого типа, лишь бы не пусто', "typeof f?.sha256 === 'string' && HEX64.test(f.sha256)", 'HEX64.test(f?.sha256)'],
  ['длина 63 допустима', 'const HEX64 = /^[0-9a-f]{64}$/i;', 'const HEX64 = /^[0-9a-f]{63,64}$/i;'],
  ['длина 65 допустима (нет конца строки)', 'const HEX64 = /^[0-9a-f]{64}$/i;', 'const HEX64 = /^[0-9a-f]{64}/i;'],
  ['префикс допустим (нет начала строки)', 'const HEX64 = /^[0-9a-f]{64}$/i;', 'const HEX64 = /[0-9a-f]{64}$/i;'],
  ['только нижний регистр hex', 'const HEX64 = /^[0-9a-f]{64}$/i;', 'const HEX64 = /^[0-9a-f]{64}$/;'],
  ['не-hex допустим', 'const HEX64 = /^[0-9a-f]{64}$/i;', 'const HEX64 = /^[0-9a-z]{64}$/i;'],
  ['размер не проверяется', "typeof f !== 'object' || !Number.isSafeInteger(f.size) || f.size < 0)", "typeof f !== 'object')"],
  ['отрицательный размер допустим', "typeof f !== 'object' || !Number.isSafeInteger(f.size) || f.size < 0)", "typeof f !== 'object' || !Number.isSafeInteger(f.size))"],
  ['дробный размер допустим', "typeof f !== 'object' || !Number.isSafeInteger(f.size) || f.size < 0)", "typeof f !== 'object' || !(f.size >= 0))"],
  ['сообщение о размере без имени файла', '(${f?.path}): нужно целое', '(): нужно целое'],
  ['сообщение о SHA без имени файла', '`${noSha[0].path}: в манифесте нет SHA-256', '`в манифесте нет SHA-256'],
  ['SAVE-записи больше не исключаются', "return top!=='save' && top!=='save_meta' && top!=='save_tx';", 'return true;'],
  ['исключаются все пути с префиксом save', "return top!=='save' && top!=='save_meta' && top!=='save_tx';", "return !top.startsWith('save');"],
  ['сверка установленного файла чувствительна к регистру hex', '=== f.sha256.toLowerCase();', '=== f.sha256;'],
  ['сверка установленного файла пропускается', '(await sha256GameFile(dir, f.path)) === f.sha256.toLowerCase();', 'true;'],
  ['checkStorageForSync не валидирует манифест', 'files = validateManifestFiles(files);\n  const haveSizes', 'const haveSizes'],
  ['syncManifestFiles не валидирует манифест', 'files = validateManifestFiles(files);\n  if (files.some(inPackEntry))', 'if (files.some(inPackEntry))'],
  ['validateManifestFiles возвращает без проверок', 'const noSha = files.filter(f => !hasSha256(f));\n  if (noSha.length)', 'const noSha = [];\n  if (noSha.length)'],
];

const tmp = fs.mkdtempSync(path.join(process.env.TMPDIR || os.tmpdir(), 'manifest-mut-'));
let survived = 0;
try {
  for (const f of fs.readdirSync(webDir)) if (f.endsWith('.mjs')) fs.copyFileSync(path.join(webDir, f), path.join(tmp, f));
  for (const [name, from, to] of MUTANTS) {
    const n = src.split(from).length - 1;
    if (n !== 1) { console.error(`SKIP (вхождений ${n}): ${name}`); survived++; continue; }
    fs.writeFileSync(path.join(tmp, 'save-protection.mjs'), src.replace(from, () => to));
    try {
      execFileSync('node', [path.join(here, 'test_manifest_strict_sha256.mjs')], { env: { ...process.env, SAVE_PROTECTION_DIR: tmp }, stdio: 'pipe' });
      console.error(`ВЫЖИЛА: ${name}`); survived++;
    } catch { console.log(`поймана: ${name}`); }
  }
} finally { fs.rmSync(tmp, { recursive: true, force: true }); }
if (survived) { console.error(`выжило/пропущено мутаций: ${survived}`); process.exit(1); }
console.log(`мутации: ${MUTANTS.length}/${MUTANTS.length} пойманы`);
