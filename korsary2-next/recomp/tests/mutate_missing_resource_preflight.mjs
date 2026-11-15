// Мутационная проверка тестов web/missing-resource-preflight.mjs: каждая мутация модуля (копия во временном каталоге) обязана
// провалить test_missing_resource_preflight.mjs; выжившая мутация = дыра в тестах. Игровые данные не читаются (PREFLIGHT_FAST=1).
//   node korsary2-next/recomp/tests/mutate_missing_resource_preflight.mjs
import { execFileSync } from 'node:child_process';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const modPath = path.resolve(here, '../web/missing-resource-preflight.mjs');
const src = fs.readFileSync(modPath, 'utf8');
const tmp = fs.mkdtempSync(path.join(process.env.PREFLIGHT_TEST_TMP || os.tmpdir(), 'preflight-mut-'));

// [название, старый текст (ровно одно вхождение), новый текст]
const MUTANTS = [
  ['Items/Ammo/старт .gm не попадают в фатальные', "for (const p of KNOWN_GM_PATHS) fatalSpecs.push({ path: p, why: 'crash-gm', gm: true });", 'for (const p of []) fatalSpecs.push({ path: p, why: "crash-gm", gm: true });'],
  ['KNOWN_GM_PATHS без Items', '[...KNOWN_ITEM_MODELS, ...KNOWN_AMMO_MODELS, ...KNOWN_STARTUP_MODELS]', '[...KNOWN_AMMO_MODELS, ...KNOWN_STARTUP_MODELS]'],
  ['KNOWN_GM_PATHS без Ammo', '[...KNOWN_ITEM_MODELS, ...KNOWN_AMMO_MODELS, ...KNOWN_STARTUP_MODELS]', '[...KNOWN_ITEM_MODELS, ...KNOWN_STARTUP_MODELS]'],
  ['KNOWN_GM_PATHS без старта игры', '[...KNOWN_ITEM_MODELS, ...KNOWN_AMMO_MODELS, ...KNOWN_STARTUP_MODELS]', '[...KNOWN_ITEM_MODELS, ...KNOWN_AMMO_MODELS]'],
  ['версия заголовка 50.2', "export const GM_MAGIC = '50.1';", "export const GM_MAGIC = '50.2';"],
  ['размер заголовка 0x40', 'export const GM_HEADER_BYTES = 0x48;', 'export const GM_HEADER_BYTES = 0x40;'],
  ['нет проверки размера < заголовка', 'if (file.size < GM_HEADER_BYTES) bad =', 'if (false) bad ='],
  ['сравнивается лишь начало версии', 'if (got !== GM_MAGIC) bad =', 'if (got.slice(0, 2) !== GM_MAGIC.slice(0, 2)) bad ='],
  ['заголовок не блокирует', "const BLOCKING_RESULTS = new Set(['missing', 'unreadable', 'not_file', 'header']);", "const BLOCKING_RESULTS = new Set(['missing', 'unreadable', 'not_file']);"],
  ['заголовок проверяется только с манифестом', 'if (item.gm) {\n    // GEOMETRY.dll', 'if (item.gm && item.expected) {\n    // GEOMETRY.dll'],
  ['заголовок читается в 8 байт', 'file.slice(0, 4).arrayBuffer()', 'file.slice(0, 8).arrayBuffer()'],
  ['сбой чтения заголовка не блокирует: ошибка проглочена', "catch (e) { return { ...out, result: 'unreadable', detail: errName(e) }; }\n      const got", "catch (e) { head = new Uint8Array([53, 48, 46, 49]); }\n      const got"],
  ['прочие модели читаются (getFile)', "if (item.listOnly) return { ...base, result: 'ok', verified: 'presence', detail: r.note ?? null, ...(r.note ? { aliases: true } : {}) };", ''],
  ['правило прочих моделей удалено', "  Object.freeze({ prefix: 'resource/models/', suffix: '.gm', label: 'model', listOnly: true }),\n", ''],
  ['правило прочих моделей раньше Items', "  Object.freeze({ prefix: 'resource/models/items/', suffix: '.gm', label: 'item-model' }),\n", ''],
  ['listOnly не передаётся в план', "...(rule.listOnly ? { listOnly: true } : {}) });", '});'],
  ['прочие модели становятся фатальными', "const severity = item.cls === 'fatal' && (item.blocking ?? BLOCKING_RESULTS).has(r.result) ? 'fatal' : 'warn';\n    const f = { severity, code: RESULT_CODE[r.result], path: r.path, detail: r.detail ?? null, why: item.why };", "const severity = (item.cls === 'fatal' || item.why === 'model') && (item.blocking ?? BLOCKING_RESULTS).has(r.result) ? 'fatal' : 'warn';\n    const f = { severity, code: RESULT_CODE[r.result], path: r.path, detail: r.detail ?? null, why: item.why };"],
  ['размер/хеш .gm не сверяются', "if (file.size !== exp.size) { out.result = 'size';", "if (false) { out.result = 'size';"],
  ['gm-флаг не ставится', "if (spec.gm) item.gm = true;", ''],
  ['why crash-gm теряется', "{ path: p, why: 'crash-gm', gm: true }", "{ path: p, why: 'required', gm: true }"],
  ['код RES_BAD_HEADER подменён', "header: CODES.RES_BAD_HEADER", "header: CODES.RES_SIZE_MISMATCH"],
  // ---- английский слой (E5)
  ['E5: language.ini слоя любой язык годен', "if (other !== undefined) return", "if (false) return"],
  ['E5: язык сравнивается с учётом регистра', "const other = values.find((v) => v.toLowerCase() !== 'english');", "const other = values.find((v) => v !== 'English');"],
  ['E5: закомментированные строки считаются', "/^[ \\t]*defaultLanguage[ \\t]*=[ \\t]*([^\\r\\n;]*)/gim", "/[ \\t]*defaultLanguage[ \\t]*=[ \\t]*([^\\r\\n;]*)/gim"],
  ['E5: противоречащие активные строки допустимы', "values.length > 1 ? 'активные строки defaultLanguage противоречат друг другу' : `активный", "false ? 'активные строки defaultLanguage противоречат друг другу' : `активный"],
  ['E5: language.ini слоя не проверяется по содержимому', "...(asciiLower(p) === asciiLower(LANGUAGE_INI_PATH) ? { verify: languageIniProblem } : {}) });", "});"],
  ['E5: содержимое не блокирует', "['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed', 'content']", "['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed']"],
  ['E5: размер обязательного файла не блокирует', "['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed', 'content']", "['missing', 'unreadable', 'not_file', 'hash', 'changed', 'content']"],
  ['E5: SHA обязательного файла не блокирует', "['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed', 'content']", "['missing', 'unreadable', 'not_file', 'size', 'changed', 'content']"],
  ['E5: отсутствие обязательного файла не блокирует', "['missing', 'unreadable', 'not_file', 'size', 'hash', 'changed', 'content']", "['unreadable', 'not_file', 'size', 'hash', 'changed', 'content']"],
  ['E5: обязательные файлы слоя не фатальны', "cls: 'fatal', why: 'overlay-required', blocking: OVERLAY_BLOCKING,", "cls: 'check', why: 'overlay-required', blocking: OVERLAY_BLOCKING,"],
  ['E5: рекомендуемые файлы слоя фатальны', "{ where: 'overlay', cls: 'check', why: 'overlay-recommended' }", "{ where: 'overlay', cls: 'fatal', why: 'overlay-recommended', blocking: OVERLAY_BLOCKING }"],
  ['E5: файлы базы для английского фатальны', "{ where: 'base', cls: 'check', why: 'base-for-english' }", "{ where: 'base', cls: 'fatal', why: 'base-for-english', blocking: OVERLAY_BLOCKING }"],
  ['E5: собственный сбой проверки слоя блокирует запуск', "return { block: false, level: 'error', code: CODES.PF_INTERNAL, message: '', details: [], warnings: [],", "return { block: true, level: 'error', code: CODES.PF_INTERNAL, message: '', details: [], warnings: [],"],
  ['E5: файлы базы ищутся в слое', "? await inspectItem(baseRoot, baseError, item, { ...ctx, cache: ctx.baseCache })", "? await inspectItem(root, rootError, item, ctx)"],
  ['E5: без корня базы её файлы всё равно в плане', ".filter((item) => item.where !== 'base' || typeof openGameDir === 'function');", ";"],
  ['E5: список слоя не используется (нет хешей)', "assessManifest(files && version ? { version, files } : null", "assessManifest(null"],
  ['E5: размер файла language.ini не ограничен', "if (file.size > MAX_VERIFY_BYTES) { out.result = 'content';", "if (false) { out.result = 'content';"],
  ['E5: отказ описан как неблокирующий', "if (fatal.length) {\n    const f = fatal[0];\n    const why = f.code === CODES.RES_BAD_CONTENT", "if (false) {\n    const f = fatal[0];\n    const why = f.code === CODES.RES_BAD_CONTENT"],
];

let survived = 0;
try {
  for (const [name, from, to] of MUTANTS) {
    const n = src.split(from).length - 1;
    if (n !== 1) { console.error(`SKIP (вхождений ${n}): ${name}`); survived++; continue; }
    const mp = path.join(tmp, 'mutant.mjs');
    fs.writeFileSync(mp, src.replace(from, to));
    try {
      execFileSync('node', [path.join(here, 'test_missing_resource_preflight.mjs')], { env: { ...process.env, PREFLIGHT_MODULE: mp, PREFLIGHT_FAST: '1' }, stdio: 'pipe' });
      console.error(`ВЫЖИЛА: ${name}`); survived++;
    } catch { console.log(`поймана: ${name}`); }
  }
} finally { fs.rmSync(tmp, { recursive: true, force: true }); }
if (survived) { console.error(`выжило/пропущено мутаций: ${survived}`); process.exit(1); }
console.log(`мутации: ${MUTANTS.length}/${MUTANTS.length} пойманы`);
