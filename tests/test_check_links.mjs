import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {checkLinks} from '../docs/check_links.mjs';

test('checks local Markdown links, ignoring fenced code and external links', t => {
  const root = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-links-'));
  t.after(() => fs.rmSync(root, {recursive: true, force: true}));
  fs.mkdirSync(path.join(root, 'docs'));
  fs.writeFileSync(path.join(root, 'docs', 'target file.md'), 'target');
  fs.writeFileSync(path.join(root, 'docs', 'guide.md'), [
    '[valid](target%20file.md#heading)', '[missing](missing.md)',
    '[outside](https://example.com/)', '[anchor](#local)',
    '```', '[ignored](not-present.md)', '```',
  ].join('\n'));
  const result = checkLinks({root, files:['docs/guide.md'], linksOnly:true});
  assert.equal(result.links, 2);
  assert.deepEqual(result.badLinks, [['docs/guide.md', 2, 'missing.md']]);
});

test('reports missing repository path mentions without treating them as broken links', t => {
  const root = fs.mkdtempSync(path.join(os.tmpdir(), 'k2-mentions-'));
  t.after(() => fs.rmSync(root, {recursive: true, force: true}));
  fs.mkdirSync(path.join(root, 'docs'));
  fs.mkdirSync(path.join(root, 'scripts'));
  fs.writeFileSync(path.join(root, 'scripts', 'ok.sh'), '');
  fs.writeFileSync(path.join(root, 'docs', 'guide.md'), '`scripts/ok.sh` and `scripts/missing.sh`');
  const result = checkLinks({root, files:['docs/guide.md']});
  assert.equal(result.mentions, 2);
  assert.deepEqual(result.badLinks, []);
  assert.deepEqual(result.badMentions, [['docs/guide.md', 1, 'scripts/missing.sh']]);
});
