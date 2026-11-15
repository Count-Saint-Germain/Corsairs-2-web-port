import test from 'node:test';
import assert from 'node:assert/strict';
import { execFileSync } from 'node:child_process';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const git = (args, options = {}) => execFileSync('git', args, { cwd: root, encoding: 'utf8', ...options });

test('Git preserves every tracked game file with automatic CRLF conversion enabled', () => {
  const files = git(['ls-files', '-z', '--', 'korsary2-work/game/']).split('\0').filter(Boolean);
  assert.ok(files.length > 0, 'the repository must contain original game scripts');
  assert.ok(files.every(f => !/[\r\n]/.test(f)), 'stdin-paths requires single-line paths');
  const input = files.join('\n') + '\n';
  const raw = git(['hash-object', '--no-filters', '--stdin-paths'], { input });
  const filtered = git(['-c', 'core.autocrlf=true', '-c', 'core.eol=lf',
    'hash-object', '--stdin-paths'], { input });
  assert.deepEqual(filtered.trimEnd().split('\n'), raw.trimEnd().split('\n'),
    'Git line-ending filters must not modify original game data');
});
