// Exercise launcher language selection and save messages without a browser or OPFS.
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { runInNewContext } from 'node:vm';

const source = readFileSync(new URL('../web/port.js', import.meta.url), 'utf8')
  .replace(/setupFullscreen\(\);\s*boot\(\)\.catch\(fail\);\s*$/, '');
const html = readFileSync(new URL('../web/index.html', import.meta.url), 'utf8');
const portConfig = JSON.parse(readFileSync(new URL('../../port.json', import.meta.url), 'utf8'));
assert.equal(portConfig.name, 'Corsairs 2');
assert.equal(portConfig.id, 'korsary2', 'changing the display name must not move existing saves');
for (const configPath of ['../web/port-config.js', '../../../distribution/port-config.js']) {
  const configWindow = {};
  runInNewContext(readFileSync(new URL(configPath, import.meta.url), 'utf8'), { window: configWindow });
  assert.equal(configWindow.PORT.name, portConfig.name, configPath);
  assert.equal(configWindow.PORT.id, portConfig.id, configPath);
}
const restore = html.split('<script type="module">')[1].split('</script>')[0];
assert.match(html, /<html lang="ru">/);
assert.match(html, /<p id="status" role="status"><span lang="ru">[^<]+<\/span><br><span lang="en">[^<]+<\/span><\/p>/);

function page(search, stored, capabilities = {}) {
  const elements = new Map();
  const node = () => ({ childNodes: [], _text: '',
    set textContent(value) { this._text = value; this.childNodes = []; },
    get textContent() { return this.childNodes.length ? this.childNodes.map(child => child.textContent).join('') : this._text; },
    replaceChildren(...children) { this._text = ''; this.childNodes = children; },
  });
  const element = (id) => {
    if (!elements.has(id)) elements.set(id, Object.assign(node(), { id, disabled: false, dataset: {},
      classList: { toggle() {}, add() {}, remove() {} }, setAttribute() {}, click() {} }));
    return elements.get(id);
  };
  const brandNames = [node(), node()];
  const window = { PORT: { id: portConfig.id, name: portConfig.name, exe: 'ENGINE.exe', controls: 'Русское управление', online: true },
    localStorage: { getItem: () => { if (stored === undefined) throw new Error('storage denied'); return stored; } } };
  const document = { documentElement: {}, getElementById: element, querySelectorAll: selector => selector === '.game-name' ? brandNames : [],
    createElement: node, createTextNode: text => ({ textContent: text }) };
  const location = { search, href: `http://localhost/${search}` };
  const context = { window, document, location, URL, URLSearchParams, console,
    crossOriginIsolated: capabilities.isolated ?? true, navigator: capabilities.navigator ?? {} };
  runInNewContext(source + '\nwindow.testApi = { langState, renderLang, startFailed, boot, formatInstallProgress };', context);
  // The restore module has its own lexical scope in HTML.
  runInNewContext(`{ ${restore}\nwindow.restoreTest = { showDecision, report, rootName }; }`, context);
  return { window, document, element, brandNames };
}

// Save backup and restore must target exactly the current mode's own root.
for (const [search, expected] of [['', 'korsary2-game-lazy-experiment'], ['?lazy=1', 'korsary2-game-lazy-experiment'], ['?lazy=0', 'korsary2-game']]) {
  const { window } = page(search, null);
  assert.equal(window.getPortSaveRoot(), expected);
  assert.equal(window.restoreTest.rootName, expected, 'restore must use the same root and lock as backup');
}

// A language install may temporarily block both launch buttons. Once it
// finishes, streaming must not accidentally enable unsupported multiplayer.
{
  const { window, element } = page('?lang=en', null);
  window.testApi.langState.overlay = 'installing'; window.testApi.renderLang();
  assert.equal(element('go-online').disabled, true);
  window.testApi.langState.overlay = 'ready'; window.testApi.renderLang();
  assert.equal(element('go-online').disabled, true);
  assert.equal(element('play').disabled, false);
}

// Installation progress counts unpacked storage, while network bytes are
// independently estimated only for a fresh install.
{
  const { window } = page('?lang=ru', null);
  const format = window.testApi.formatInstallProgress;
  assert.match(format(300e6, 2351e6, { networkBytes: 1223e6, lang: 'ru' }),
    /Установка игровых файлов: 300 \/ 2351 МБ распаковано; по сети около 1223 МБ/);
  assert.match(format(0, 124.9e6, { overlay: true, networkBytes: 74.8e6, lang: 'en' }),
    /Installing English files: 0.0 \/ 124.9 MB unpacked; about 74.8 MB over network/);
  assert.doesNotMatch(format(300e6, 2351e6, { lang: 'en' }), /over network/);
  assert.match(format(1e6, 3e6, { lang: 'ru', name: 'RESOURCE/a' }), /\(RESOURCE\/a\)$/);
}

// Capability checks happen before the language picker exists. First-time
// players must get both languages; a saved or explicit choice must win.
for (const [search, stored, expected] of [
  ['', null, 'both'], ['', undefined, 'both'], ['?lang=unknown', null, 'both'],
  ['?lang=ru', 'en', 'ru'], ['?lang=en', 'ru', 'en'],
  ['?lang=en', undefined, 'en'], ['?lang=unknown', 'en', 'en'], ['', 'ru', 'ru'], ['', 'en', 'en'],
]) {
  const checks = [
    [{ isolated: false }, /изоляц/i, /isolation/i],
    [{ navigator: {} }, /недоступен WebGPU/i, /no WebGPU/i],
    [{ navigator: { gpu: { requestAdapter: async () => null }, userAgent: 'Firefox/123' } }, /графический адаптер/i, /graphics adapter/i],
    [{ navigator: { gpu: { requestAdapter: async () => ({}) } } }, /хранилище файлов/i, /local file storage/i],
  ];
  for (const [capabilities, russian, english] of checks) {
    const { window, document, element, brandNames } = page(search, stored, capabilities);
    assert.equal(document.documentElement.lang, expected === 'en' ? 'en' : 'ru', 'language set before boot');
    if (expected !== 'both') assert.match(element('status').textContent, expected === 'ru' ? /Проверяем/ : /Checking/);
    await window.testApi.boot();
    assert.equal(document.title, 'Corsairs 2');
    assert.deepEqual(brandNames.map(el => el.textContent), ['Corsairs 2', 'Corsairs 2']);
    const message = element('status').textContent;
    if (expected === 'both') assert.deepEqual(element('status').childNodes.filter(child => child.lang).map(child => child.lang), ['ru', 'en']);
    if (expected !== 'en') assert.match(message, russian);
    else assert.doesNotMatch(message, russian);
    if (expected !== 'ru') assert.match(message, english);
    else assert.doesNotMatch(message, english);
  }
}

for (const [search, stored, expected] of [['?lang=en', 'ru', 'en'], ['?lang= EN ', 'ru', 'en'], ['', 'ru', 'ru'], ['', 'en', 'en']]) {
  const { window, document, element } = page(search, stored);
  const { langState, renderLang, startFailed } = window.testApi;
  assert.equal(langState.lang, expected);
  langState.overlay = 'ready'; renderLang();
  assert.equal(document.documentElement.lang, expected);
  assert.equal(element('backup-saves').textContent, expected === 'en' ? 'Download saves' : 'Скачать сохранения');
  assert.equal(element('home-tagline').textContent, expected === 'en' ? 'Pick how you want to play.' : 'Выберите режим игры.');
  assert.equal(element('play-label').textContent, expected === 'en' ? 'Play Solo' : 'Одиночная игра');
  assert.equal(element('fullscreen-prefix').textContent, expected === 'en' ? 'Fullscreen:' : 'Полный экран:');
  assert.equal(element('save-read-label').textContent, expected === 'en' ? 'Loading save…' : 'Чтение сохранения…');
  assert.equal(element('controls').textContent.includes('Русское управление'), expected === 'ru');
  assert.equal(/[А-Яа-яЁё]/.test(element('lang-note').textContent), expected === 'ru');
  if (expected === 'en') {
    window.restoreTest.showDecision({ conflicts: [{ name: 'my slot' }] });
    assert.match(element('restore-conflicts').textContent, /Replace all/);
    assert.doesNotMatch(element('restore-conflicts').textContent, /[А-Яа-яЁё]/);
    window.restoreTest.report({ restored: ['a'], metaWritten: 0, replaced: [], skippedConflicts: [], identical: [], ignored: [] });
    assert.match(element('backup-status').textContent, /new files restored: 1/);
    startFailed({ name: 'SaveLockBusy' });
    assert.match(element('status').textContent, /save lock/);
  }
}
// Switching language updates the open conflict and current save result without changing it.
{
  const { window, element } = page('?lang=ru', null);
  const { langState, renderLang } = window.testApi;
  langState.overlay = 'ready';
  window.restoreTest.showDecision({ conflicts: [{ name: 'slot1' }] });
  window.restoreTest.report({ restored: ['slot2'], metaWritten: 0, replaced: [], skippedConflicts: [], identical: [], ignored: [] });
  renderLang();
  assert.match(element('restore-conflicts').textContent, /Заменить всё/);
  assert.match(element('backup-status').textContent, /восстановлено новых файлов: 1/);
  langState.lang = 'en'; renderLang();
  assert.match(element('restore-conflicts').textContent, /Replace all/);
  assert.match(element('restore-conflicts').textContent, /slot1/);
  assert.match(element('backup-status').textContent, /new files restored: 1/);
  langState.lang = 'ru'; renderLang();
  assert.match(element('restore-conflicts').textContent, /Заменить всё/);
  assert.match(element('backup-status').textContent, /восстановлено новых файлов: 1/);
  window.setBackupMessage(() => window.launcherText('Архив готов', 'Archive ready'));
  langState.lang = 'en'; renderLang();
  assert.equal(element('backup-status').textContent, 'Archive ready');
  element('restore-cancel').onclick();
  assert.match(element('backup-status').textContent, /Restore cancelled/);
  langState.lang = 'ru'; renderLang();
  assert.match(element('backup-status').textContent, /Восстановление отменено/);
}

console.log('Launcher localization and save messages: PASS');
