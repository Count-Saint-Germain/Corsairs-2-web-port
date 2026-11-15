/* Local backups of the SAVE folder only: ZIP32, stored files, no network access.
 * decodeBackup parses exactly what encodeBackup writes (nothing else); putting a
 * decoded archive back into OPFS lives in save-import.mjs, under the same locks.
 * Besides every SAVE/<flat name> slot, an archive may carry one
 * SAVE_META/<name>.time record per slot: the 8-byte FILETIME the browser build
 * keeps as the slot's durable creation time (see recomp/host/kernel32.c), and one
 * SAVE_META/<name>.lang record: the 2-byte language label ("en" or "ru", E5) the
 * host writes for a slot created in the English mode. Slots are shared by both
 * languages, but names inside a slot stay in the language it was created in. */
export const LIMITS=Object.freeze({files:512, file:32*1024*1024, total:128*1024*1024, nameBytes:255,
  meta:8, lang:2, entries:1536});   // entries caps every ZIP record: slots + their time and language records + junk
export const MAX_ARCHIVE=LIMITS.total+LIMITS.entries*(2*LIMITS.nameBytes+100)+22;
export const META_SUFFIX='.time';
export const LANG_SUFFIX='.lang';
/** The only language labels a record may hold: exactly these two bytes. */
export const LANG_VALUES=Object.freeze(['en','ru']);
export function isLangRecord(bytes) {
  return bytes instanceof Uint8Array && bytes.length===LIMITS.lang &&
    LANG_VALUES.includes(String.fromCharCode(bytes[0],bytes[1]));
}
const encoder=new TextEncoder();
const decoder=new TextDecoder('utf-8',{fatal:true});
const FLAG_UTF8=0x800;
const fail=(message)=>{ throw new Error(message); };
export function key(name) { return name.normalize('NFC').toLowerCase().normalize('NFC'); }

export function validateName(name) {
  if (typeof name!=='string' || !name || name==='.' || name==='..' ||
      /[\x00-\x1f\x7f<>:"/\\|?*]/u.test(name) || /[. ]$/u.test(name) ||
      /^(con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\.|$)/iu.test(name))
    fail('Недопустимое имя файла сохранения.');
  /* TextEncoder replaces unpaired surrogates; reject rather than rename. */
  const bytes=encoder.encode(name);
  if (bytes.length>LIMITS.nameBytes || decoder.decode(bytes)!==name)
    fail('Имя файла сохранения слишком длинное или содержит неверный Unicode.');
  return name;
}

const crcTable=(()=>{
  const table=new Uint32Array(256);
  for(let n=0;n<256;n++) { let c=n; for(let i=0;i<8;i++) c=(c&1)?0xedb88320^(c>>>1):c>>>1; table[n]=c>>>0; }
  return table;
})();
export function crc32(bytes) {
  let c=0xffffffff;
  for(const byte of bytes) c=crcTable[(c^byte)&255]^(c>>>8);
  return (c^0xffffffff)>>>0;
}
function ensureEntries(entries) {
  if (!Array.isArray(entries) || !entries.length || entries.length>LIMITS.files)
    fail('Нет файлов сохранений или превышено их допустимое число.');
  let total=0; const seen=new Set();
  return entries.map(entry=>{
    const name=validateName(entry?.name); const k=key(name);
    if (seen.has(k)) fail('Найдены повторяющиеся имена сохранений.');
    seen.add(k);
    if (!(entry.bytes instanceof Uint8Array)) fail('Некорректное содержимое файла сохранения.');
    if (entry.bytes.length>LIMITS.file || (total+=entry.bytes.length)>LIMITS.total)
      fail('Размер сохранений превышает допустимый предел.');
    const out={name,bytes:entry.bytes};
    if (entry.meta!=null) {   // optional 8-byte creation-time record for this slot
      if (!(entry.meta instanceof Uint8Array) || entry.meta.length!==LIMITS.meta)
        fail('Некорректная запись времени сохранения.');
      total+=entry.meta.length;
      out.meta=entry.meta;
    }
    if (entry.lang!=null) {   // optional 2-byte language label for this slot
      if (!isLangRecord(entry.lang)) fail('Некорректная запись языка сохранения.');
      total+=entry.lang.length;
      out.lang=entry.lang;
    }
    return out;
  });
}
function view(bytes) { return new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength); }
function write16(v,o,n) { v.setUint16(o,n,true); }
function write32(v,o,n) { v.setUint32(o,n>>>0,true); }

/** Create a standard ZIP32 archive with SAVE/<flat filename> records plus one
 * SAVE_META/<name>.time creation-time record per slot that carries `meta` and one
 * SAVE_META/<name>.lang language label per slot that carries `lang`. */
export function encodeBackup(input) {
  const entries=ensureEntries(input);
  const records=entries.map(e=>({...e,path:encoder.encode('SAVE/'+e.name),crc:crc32(e.bytes)}))
    .concat(entries.filter(e=>e.meta).map(e=>({bytes:e.meta,
      path:encoder.encode('SAVE_META/'+e.name+META_SUFFIX),crc:crc32(e.meta)})))
    .concat(entries.filter(e=>e.lang).map(e=>({bytes:e.lang,
      path:encoder.encode('SAVE_META/'+e.name+LANG_SUFFIX),crc:crc32(e.lang)})));
  let localSize=0,centralSize=0;
  for(const e of records) { localSize+=30+e.path.length+e.bytes.length; centralSize+=46+e.path.length; }
  const length=localSize+centralSize+22;
  if(length>MAX_ARCHIVE || length>0xffffffff) fail('Архив слишком велик.');
  const out=new Uint8Array(length), v=view(out); let off=0;
  for(const e of records) {
    e.offset=off;
    write32(v,off,0x04034b50); write16(v,off+4,20); write16(v,off+6,FLAG_UTF8);
    write16(v,off+8,0); write16(v,off+10,0); write16(v,off+12,0x21);
    write32(v,off+14,e.crc); write32(v,off+18,e.bytes.length); write32(v,off+22,e.bytes.length);
    write16(v,off+26,e.path.length); write16(v,off+28,0);
    out.set(e.path,off+30); out.set(e.bytes,off+30+e.path.length);
    off+=30+e.path.length+e.bytes.length;
  }
  const central=off;
  for(const e of records) {
    write32(v,off,0x02014b50); write16(v,off+4,20); write16(v,off+6,20); write16(v,off+8,FLAG_UTF8);
    write16(v,off+10,0); write16(v,off+12,0); write16(v,off+14,0x21);
    write32(v,off+16,e.crc); write32(v,off+20,e.bytes.length); write32(v,off+24,e.bytes.length);
    write16(v,off+28,e.path.length); write16(v,off+30,0); write16(v,off+32,0);
    write16(v,off+34,0); write16(v,off+36,0); write32(v,off+38,0); write32(v,off+42,e.offset);
    out.set(e.path,off+46); off+=46+e.path.length;
  }
  write32(v,off,0x06054b50); write16(v,off+4,0); write16(v,off+6,0);
  write16(v,off+8,records.length); write16(v,off+10,records.length);
  write32(v,off+12,centralSize); write32(v,off+16,central); write16(v,off+20,0);
  return out;
}

function readName(bytes, what) {
  try { return decoder.decode(bytes); } catch { fail(`Архив сохранений повреждён: ${what} не является корректным UTF-8.`); }
}

/** Inverse of encodeBackup: strictly parses the ZIP32 format it writes (stored
 * files under SAVE/<flat name> plus optional SAVE_META/<name>.time creation
 * records and SAVE_META/<name>.lang language labels, UTF-8 names, no comment).
 * An archive with no entries decodes to an empty list. Returns
 * { entries, meta, lang, ignored } where meta holds the parsed 8-byte time
 * records, lang the 2-byte language labels (exactly "en" or "ru", anything else
 * rejects the archive) and ignored holds paths outside SAVE/ and SAVE_META/
 * (they are dropped, not restored). Anything else — compression, encryption,
 * streaming records, unsafe names, a CRC mismatch, local records disagreeing
 * with the central directory, stray trailing data — fails with a readable
 * message instead of yielding questionable bytes. */
export function decodeBackup(archive) {
  if (!(archive instanceof Uint8Array) || archive.length < 22) fail('Это не архив сохранений.');
  if (archive.length > MAX_ARCHIVE) fail('Архив сохранений слишком велик.');
  const v=view(archive);
  try {
    // end record: scan back for the one whose (empty) comment ends exactly at EOF
    let eocd=-1;
    for(let off=archive.length-22;off>=0 && off>=archive.length-22-0xffff;off--)
      if(v.getUint32(off,true)===0x06054b50 && off+22+v.getUint16(off+20,true)===archive.length) { eocd=off; break; }
    if(eocd<0) fail('Это не архив сохранений или он повреждён.');
    if(v.getUint16(eocd+4,true)!==0 || v.getUint16(eocd+6,true)!==0)
      fail('Многотомные архивы сохранений не поддерживаются.');
    const count=v.getUint16(eocd+8,true);
    if(count!==v.getUint16(eocd+10,true)) fail('Архив сохранений повреждён.');
    if(count>LIMITS.entries) fail('В архиве слишком много файлов сохранений.');
    const cdOff=v.getUint32(eocd+16,true), cdSize=v.getUint32(eocd+12,true);
    if(cdOff+cdSize>eocd) fail('Архив сохранений повреждён.');
    if(count && cdOff+cdSize!==eocd)
      fail('Архив сохранений содержит посторонние данные; поддерживаются только архивы этой игры.');
    const entries=[], meta=[], lang=[], ignored=[]; let off=cdOff; let total=0; const seen=new Set(); const metaSeen=new Set(); const langSeen=new Set();
    for(let i=0;i<count;i++) {
      if(off+46>eocd || v.getUint32(off,true)!==0x02014b50) fail('Архив сохранений повреждён.');
      const flags=v.getUint16(off+8,true), method=v.getUint16(off+10,true);
      if(method!==0) fail('Архив сохранений сжат; поддерживаются только несжатые архивы этой игры.');
      if(flags&~FLAG_UTF8) fail('Архив сохранений зашифрован или записан потоково; такой формат не поддерживается.');
      const crc=v.getUint32(off+16,true), csize=v.getUint32(off+20,true);
      if(csize!==v.getUint32(off+24,true)) fail('Архив сохранений повреждён.');
      const nameLen=v.getUint16(off+28,true), extraLen=v.getUint16(off+30,true), commentLen=v.getUint16(off+32,true);
      const localOff=v.getUint32(off+42,true);
      if(off+46+nameLen+extraLen+commentLen>eocd) fail('Архив сохранений повреждён.');
      const path=readName(archive.subarray(off+46,off+46+nameLen),'имя файла');
      off+=46+nameLen+extraLen+commentLen;
      // whitelist: slot files under SAVE/, time records under SAVE_META/, all
      // names validated with the same rules as export; everything else is junk
      let name;
      if (path.startsWith('SAVE/')) {
        name=path.slice('SAVE/'.length);
        try { validateName(name); } catch { fail(`Архив содержит недопустимое имя сохранения: ${JSON.stringify(path)}.`); }
        if(name.startsWith('.')) fail(`Архив содержит скрытое имя сохранения: ${JSON.stringify(path)}.`);
        const k=key(name);
        if(seen.has(k)) fail('В архиве повторяются имена сохранений.'); seen.add(k);
        if(csize>LIMITS.file || (total+=csize)>LIMITS.total)
          fail('Размер сохранений в архиве превышает допустимый предел.');
        if(entries.length>=LIMITS.files) fail('В архиве слишком много файлов сохранений.');
      } else if (path.startsWith('SAVE_META/') && path.endsWith(META_SUFFIX)) {
        name=path.slice('SAVE_META/'.length,-META_SUFFIX.length);
        try { validateName(name); } catch { fail(`Архив содержит недопустимое имя записи времени: ${JSON.stringify(path)}.`); }
        if(name.startsWith('.')) fail(`Архив содержит скрытое имя записи времени: ${JSON.stringify(path)}.`);
        const k=key(name);
        if(metaSeen.has(k)) fail('В архиве повторяются записи времени.'); metaSeen.add(k);
        if(csize!==LIMITS.meta || (total+=csize)>LIMITS.total)
          fail(`Запись времени сохранения повреждена: ${JSON.stringify(path)}.`);
      } else if (path.startsWith('SAVE_META/') && path.endsWith(LANG_SUFFIX)) {
        name=path.slice('SAVE_META/'.length,-LANG_SUFFIX.length);
        try { validateName(name); } catch { fail(`Архив содержит недопустимое имя записи языка: ${JSON.stringify(path)}.`); }
        if(name.startsWith('.')) fail(`Архив содержит скрытое имя записи языка: ${JSON.stringify(path)}.`);
        const k=key(name);
        if(langSeen.has(k)) fail('В архиве повторяются записи языка.'); langSeen.add(k);
        if(csize!==LIMITS.lang || (total+=csize)>LIMITS.total)
          fail(`Запись языка сохранения повреждена: ${JSON.stringify(path)}.`);
      } else { ignored.push(path); continue; }
      // the local record must describe the same stored file, lying before the central directory
      if(localOff+30>cdOff || v.getUint32(localOff,true)!==0x04034b50 ||
         v.getUint16(localOff+6,true)!==flags || v.getUint16(localOff+8,true)!==method ||
         v.getUint32(localOff+14,true)!==crc || v.getUint32(localOff+18,true)!==csize ||
         v.getUint32(localOff+22,true)!==csize || v.getUint16(localOff+26,true)!==nameLen)
        fail('Архив сохранений повреждён.');
      const dataOff=localOff+30+nameLen+v.getUint16(localOff+28,true);
      if(dataOff+csize>cdOff || readName(archive.subarray(localOff+30,localOff+30+nameLen),'локальная запись')!==path)
        fail('Архив сохранений повреждён.');
      const data=archive.slice(dataOff,dataOff+csize);
      if(data.length!==csize || crc32(data)!==crc)
        fail(`Файл сохранения повреждён: ${JSON.stringify(path)} (не совпала контрольная сумма).`);
      if(path.startsWith('SAVE_META/') && path.endsWith(LANG_SUFFIX) && !isLangRecord(data))
        fail(`Запись языка сохранения повреждена: ${JSON.stringify(path)} (допустимы только «en» и «ru»).`);
      (path.startsWith('SAVE/')?entries:path.endsWith(LANG_SUFFIX)?lang:meta).push({name,bytes:data});
    }
    return {entries,meta,lang,ignored};
  } catch(error) {
    if(error instanceof RangeError) fail('Архив сохранений повреждён.');
    throw error;
  }
}

/** Read flat files only, never any game assets outside the supplied SAVE dir. */
export async function openSaveDirectory(openGame) {
  try { return await (await openGame(false)).getDirectoryHandle('SAVE',{create:false}); }
  catch (error) {
    if(error.name==='NotFoundError') fail('Сохранения не найдены.');
    throw error;
  }
}

/** Best-effort read of one slot's durable creation-time record from the
 * SAVE_META folder beside the game root. Returns exactly 8 bytes when a whole
 * record exists under the exact name; anything else (no record, a short or
 * unreadable file) is null — the time stays unknown, never guessed. */
export async function readSaveMeta(gameRoot, name) {
  try {
    const metaDir=await gameRoot.getDirectoryHandle('SAVE_META',{create:false});
    const file=await (await metaDir.getFileHandle(name+META_SUFFIX,{create:false})).getFile();
    if (file.size!==LIMITS.meta) return null;
    const bytes=new Uint8Array(await file.arrayBuffer());
    return bytes.length===LIMITS.meta ? bytes : null;
  } catch { return null; }   // missing SAVE_META or record is the normal case
}

/** Best-effort read of one slot's language label (SAVE_META/<name>.lang) under its exact name: the 2 bytes when a whole, valid record
 * ("en" or "ru") exists, otherwise null — the slot is simply not marked. */
export async function readSaveLang(gameRoot, name) {
  try {
    const metaDir=await gameRoot.getDirectoryHandle('SAVE_META',{create:false});
    const file=await (await metaDir.getFileHandle(name+LANG_SUFFIX,{create:false})).getFile();
    if (file.size!==LIMITS.lang) return null;
    const bytes=new Uint8Array(await file.arrayBuffer());
    return isLangRecord(bytes) ? bytes : null;
  } catch { return null; }
}

export async function readSaveDirectory(dir, gameRoot) {
  const metadata=[]; let total=0; const names=new Set();
  for await (const [name,handle] of dir.entries()) {
    validateName(name);
    if (handle.kind!=='file') fail('В SAVE найдена вложенная папка; архив не создан.');
    const k=key(name); if(names.has(k)) fail('В SAVE есть имена, совпадающие без учёта регистра.'); names.add(k);
    const file=await handle.getFile();
    if(metadata.length>=LIMITS.files || file.size>LIMITS.file || (total+=file.size)>LIMITS.total)
      fail('Размер или число сохранений превышает допустимый предел.');
    metadata.push({name,file});
  }
  if(!metadata.length) fail('В этой папке нет сохранений.');
  const entries=[];
  for(const {name,file} of metadata) {
    const bytes=new Uint8Array(await file.arrayBuffer());
    if(bytes.length!==file.size) fail('Не удалось полностью прочитать сохранение.');
    const entry={name,bytes};
    if (gameRoot) {   // archive the slot's durable creation time when it exists
      const meta=await readSaveMeta(gameRoot,name);
      if (meta) entry.meta=meta;
      const lang=await readSaveLang(gameRoot,name);   // E5: the language label travels with the slot
      if (lang) entry.lang=lang;
    }
    entries.push(entry);
  }
  return entries;
}

/** The one Web Lock name that serializes every cooperating SAVE operation
 * (export, import, update and picker backups) and that a running game holds
 * exclusively for its whole page lifetime (save-owner.mjs). A single builder
 * keeps those two sides from ever drifting apart. */
export const saveLockName=(rootName)=>rootName+':save-backup';

export async function withSaveLock(lockManager,rootName,fn) {
  if(!lockManager?.request) fail('Браузер не поддерживает блокировку сохранений.');
  return lockManager.request(saveLockName(rootName),{mode:'exclusive',ifAvailable:true},
    async lock=>{ if(!lock) fail('Сохранения сейчас заняты другой операцией.'); return fn(); });
}
