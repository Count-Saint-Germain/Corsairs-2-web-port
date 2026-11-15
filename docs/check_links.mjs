#!/usr/bin/env node
/** Check local Markdown links and report heuristic path mentions. */
import fs from 'node:fs';
import path from 'node:path';
import { execFileSync } from 'node:child_process';
import { fileURLToPath, pathToFileURL } from 'node:url';

const defaultRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const skipTop = new Set(['third_party', 'korsary2-work', 'archive', '.playwright-profile', 'node_modules', '.git']);
const knownSub = new Set(['recomp','tools','re','content-patches','english-layer','docs','tests','scripts','korsary2-next','korsary2-work','third_party','videos-web']);
const extraBases = ['', 'korsary2-next', 'korsary2-next/recomp', 'korsary2-next/recomp/web', 'korsary2-next/recomp/tests', 'korsary2-next/recomp/host', 'korsary2-next/tools'];
const ignoreFirst = new Set(['game','userdata','node-game','node-port-game','tmp','var','usr','opt','Users','etc','home','PROGRAM','RESOURCE','MODULES','SAVE','SAVE_META','VIDEOS','build_web','www','node','dist','out','build','cache','ports','overlay','English','Russian','TEXTS','INTERFACE','DX8','a','b','src','lib','bin','www-dist']);
const linkPattern = /\[[^\]\n]*\]\(\s*<?([^)\s>]+)>?(?:\s+"[^"]*")?\s*\)/g;
const codePattern = /`([^`\n]+)`/g;
const pathish = /^[\p{L}\p{N}_@.+\-/()~]+$/u;

function exists(p) { try { fs.lstatSync(p); return true; } catch (err) { if (err.code === 'ENOENT' || err.code === 'ENOTDIR') return false; throw err; } }
function listMarkdown(root) {
  try {
    return execFileSync('git', ['-C', root, 'ls-files', '-co', '--exclude-standard', '-z', '*.md'], {encoding:'utf8'}).split('\0').filter(Boolean);
  } catch {
    const files = [];
    const walk = (dir) => {
      for (const entry of fs.readdirSync(dir, {withFileTypes:true})) {
        if (entry.isSymbolicLink() || skipTop.has(entry.name)) continue;
        const child = path.join(dir, entry.name);
        if (entry.isDirectory()) walk(child);
        else if (entry.name.endsWith('.md')) files.push(path.relative(root, child));
      }
    };
    walk(root);
    return files;
  }
}
function cleanMention(token) {
  let value = token.trim().replace(/[.,;:]+$/, '').replace(/:\d+(?:[-,]\d+)*$/, '').replace(/#.*$/, '');
  if (value.startsWith('web-port/')) value = value.slice('web-port/'.length);
  return value;
}
function candidates(root, mdDir, token) {
  const result = [];
  let dir = mdDir;
  while (true) {
    result.push(path.join(dir, token));
    if (dir === root || dir.length <= root.length) break;
    dir = path.dirname(dir);
  }
  for (const base of extraBases) result.push(path.join(root, base, token));
  return result;
}

export function checkLinks({root = defaultRoot, files = null, linksOnly = false} = {}) {
  root = path.resolve(root);
  files ??= listMarkdown(root);
  const badLinks = [], badMentions = [];
  let linkCount = 0, mentionCount = 0;
  const topNames = new Set(fs.readdirSync(root));
  for (const rel of [...new Set(files)].sort()) {
    if (skipTop.has(rel.split('/')[0])) continue;
    const file = path.resolve(root, rel);
    if (!exists(file) || !fs.statSync(file).isFile()) continue;
    let inFence = false;
    for (const [index, line] of fs.readFileSync(file, 'utf8').split('\n').entries()) {
      if (line.trimStart().startsWith('```')) { inFence = !inFence; continue; }
      if (inFence) continue;
      for (const match of line.matchAll(linkPattern)) {
        const target = match[1];
        if (/^(?:[a-z][a-z0-9+.-]*:|#|\/)/i.test(target)) continue;
        linkCount++;
        let targetPath;
        try { targetPath = decodeURIComponent(target.replace(/[#?].*$/, '')); }
        catch { badLinks.push([rel,index+1,target]); continue; }
        if (targetPath && !exists(path.resolve(path.dirname(file), targetPath))) badLinks.push([rel,index+1,target]);
      }
      if (linksOnly) continue;
      for (const match of line.matchAll(codePattern)) {
        const value = cleanMention(match[1]);
        if (!value.includes('/') || !pathish.test(value) || /^(?:\/|~|http|\$|\.\/\/)/.test(value)) continue;
        const parts = value.split('/').filter(x => x && x !== '.');
        if (!parts.length || ignoreFirst.has(parts[0]) || parts.slice(1).includes('..')) continue;
        if (!(topNames.has(parts[0]) || knownSub.has(parts[0]) || value.startsWith('../'))) continue;
        mentionCount++;
        if (!candidates(root, path.dirname(file), value).some(exists)) badMentions.push([rel,index+1,value]);
      }
    }
  }
  return {files: files.length, links: linkCount, mentions: mentionCount, badLinks, badMentions};
}

export function main(args = process.argv.slice(2)) {
  const linksOnly = args.includes('--links');
  const showAll = args.includes('--all');
  const given = args.filter(x => !x.startsWith('--'));
  const files = given.length ? given.map(x => path.relative(defaultRoot, path.resolve(x))) : null;
  const result = checkLinks({files, linksOnly});
  console.log(`Markdown files: ${result.files}; Markdown links: ${result.links}; path mentions: ${result.mentions}`);
  console.log(`Broken Markdown links: ${result.badLinks.length}`);
  for (const [file,line,target] of result.badLinks) console.log(`  ${file}:${line}: (${target})`);
  if (!linksOnly) {
    console.log(`Broken path mentions (heuristic, may include false positives): ${result.badMentions.length}`);
    const grouped = new Map();
    for (const [file,line,target] of result.badMentions) {
      if (!grouped.has(file)) grouped.set(file, []);
      grouped.get(file).push([line,target]);
    }
    for (const [file, values] of [...grouped.entries()].sort((a,b)=>b[1].length-a[1].length)) {
      console.log(`  ${String(values.length).padStart(4)}  ${file}`);
      if (showAll) for (const [line,target] of values) console.log(`        ${line}: ${target}`);
    }
  }
  return result.badLinks.length ? 1 : 0;
}
if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) process.exitCode = main();
