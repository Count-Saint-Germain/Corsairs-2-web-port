/* Restoring a downloaded saves ZIP into the game's OPFS SAVE folder. Nothing is
 * ever overwritten silently: identical files are skipped, files that differ
 * become conflicts the player resolves in the launcher ("skip all" / explicit
 * "replace all"), and foreign paths were already dropped by decodeBackup. Each
 * restored or replaced slot also carries its SAVE_META creation-time record
 * when the archive has one, and its SAVE_META language label (E5, <slot>.lang);
 * a replaced slot without a record loses its old one, so a stale time or
 * language never claims new bytes. The whole import runs under the same
 * save lock as export and other imports, which a running game holds for its
 * whole page lifetime (save-owner.mjs), so cooperating tabs refuse fast; only
 * non-cooperating writers could still race these writes. */

import { LANG_SUFFIX, MAX_ARCHIVE, META_SUFFIX, decodeBackup, isLangRecord, key, readSaveLang, readSaveMeta, validateName, withSaveLock } from './save-export.mjs';
import { isPrivacyCappedQuota, writeSaveBackupLocked } from './save-protection.mjs';

export { MAX_ARCHIVE };   // the launcher caps the picked file before reading it

const fail=(message)=>{ throw new Error(message); };
const mb=(n)=>(n/1e6).toFixed(0);

/** Constant-time-ish byte comparison; null/foreign input is never "equal". */
export function bytesEqual(a,b) {
  if(!(a instanceof Uint8Array) || !(b instanceof Uint8Array) || a.length!==b.length) return false;
  for(let i=0;i<a.length;i++) if(a[i]!==b[i]) return false;
  return true;
}

/** Pure decision table (no OPFS, unit-tested in Node): what may be written,
 * what needs an explicit player decision, what is already in place. Names match
 * through the same case-insensitive Unicode key the exporter uses, so a backup
 * of "Slot1" over an existing "slot1" is one file, not a second one. An existing
 * entry with null bytes could not be read, which can never prove equality, so
 * the same-named archive file is always a conflict. */
export function planRestore(entries, existing=[]) {
  const current=new Map();
  for(const e of existing) if(typeof e?.name==='string') current.set(key(e.name),e);
  const restore=[], conflicts=[], identical=[]; const seen=new Set();
  for(const entry of entries) {
    if(!entry || typeof entry.name!=='string' || !(entry.bytes instanceof Uint8Array))
      fail('Некорректное содержимое архива сохранений.');
    validateName(entry.name);
    const k=key(entry.name);
    if(seen.has(k)) fail('В архиве повторяются имена сохранений.'); seen.add(k);
    const have=current.get(k);
    if(!have) restore.push({name:entry.name,bytes:entry.bytes});
    else if(bytesEqual(have.bytes,entry.bytes)) identical.push(entry.name);
    else conflicts.push({name:entry.name,existingName:have.name,archiveBytes:entry.bytes,existingBytes:have.bytes??null});
  }
  return {restore,conflicts,identical};
}

/** Best-effort snapshot of the current SAVE folder for planning. A missing game
 * folder or SAVE is an empty list; a file that cannot be read is kept with null
 * bytes so the planner treats any same-named archive file as a conflict.
 * Stray subfolders are not player save files and are ignored, never written to.
 * Each entry also carries `meta` when a whole SAVE_META record exists, so a
 * restore point keeps the old slots' creation times. */
export async function existingSaves(openGame) {
  let game, dir;
  try { game=await openGame(false); dir=await game.getDirectoryHandle('SAVE',{create:false}); }
  catch(error) { if(error.name==='NotFoundError') return []; throw error; }
  const out=[];
  for await (const [name,handle] of dir.entries()) {
    if(handle.kind!=='file') continue;
    let bytes=null;
    try { bytes=new Uint8Array(await (await handle.getFile()).arrayBuffer()); }
    catch { /* unreadable: the planner must not treat it as absent */ }
    const entry={name,bytes};
    if (bytes) {
      const meta=await readSaveMeta(game,name); if (meta) entry.meta=meta;
      const lang=await readSaveLang(game,name); if (lang) entry.lang=lang;
    }
    out.push(entry);
  }
  return out;
}

/** Best-effort list of the SAVE_META record files currently in the game
 * folder: needed to remove stale records (old letter case, replaced slots
 * whose archive carries no time). A missing SAVE_META is simply no records. */
export async function existingMetaNames(openGame) {
  let dir;
  try { dir=await (await openGame(false)).getDirectoryHandle('SAVE_META',{create:false}); }
  catch(error) { if(error.name==='NotFoundError') return []; throw error; }
  const out=[];
  for await (const [name,handle] of dir.entries()) if (handle.kind==='file') out.push(name);
  return out;
}

/** Pure sidecar plan: which archive time records follow their slot's write
 * decision, and which existing record files must go. A slot being written
 * with an archive record gets that record; being written without one strips
 * any local record, so the old time can never claim the new bytes. Identical
 * and skipped slots keep whatever the game folder already has. An existing
 * record under a different letter case than the one being written is removed
 * as well (the game matches names without case, OPFS stores them with). */
export function planMetaRestore(metaRecords, writes, existingNames) {
  return planRecordRestore(metaRecords, writes, existingNames, META_SUFFIX, b=>b.length===8);
}

/** The same plan for the language labels (E5, <slot>.lang): only exactly "en"/"ru" records are put; the rest of the rules are those of the
 * time records (a rewritten slot without an archive label loses its old label; other letter cases of the record's name are removed). */
export function planLangRestore(langRecords, writes, existingNames) {
  return planRecordRestore(langRecords, writes, existingNames, LANG_SUFFIX, isLangRecord);
}

function planRecordRestore(metaRecords, writes, existingNames, SUFFIX, valid) {
  const byKey=new Map();
  for(const m of metaRecords||[])
    if(m && typeof m.name==='string' && m.bytes instanceof Uint8Array && valid(m.bytes))
      byKey.set(key(m.name), m.bytes);
  const writeByName=new Map();
  for(const w of writes||[]) if(w && typeof w.name==='string') writeByName.set(key(w.name), w.name);
  const unrecorded=new Set();
  const put=[];
  for(const [k,name] of writeByName) {
    const bytes=byKey.get(k);
    if(bytes) put.push({name:name+SUFFIX, bytes});
    else unrecorded.add(k);
  }
  const remove=[];
  for(const existing of existingNames||[]) {
    if(typeof existing!=='string' || !existing.endsWith(SUFFIX)) continue;
    const k=key(existing.slice(0,-SUFFIX.length));
    const putName=writeByName.get(k);
    if(putName && (unrecorded.has(k) || existing!==putName+SUFFIX)) remove.push(existing);
  }
  return {put,remove};
}

async function writeSaveFiles(dir,files) {
  for(const {name,bytes} of files) {
    let fh, created=false, w;
    try { fh=await dir.getFileHandle(name,{create:false}); }
    catch(e) { if(e.name!=='NotFoundError') throw e; fh=await dir.getFileHandle(name,{create:true}); created=true; }
    try {
      w=await fh.createWritable();   // default: replace the whole content
      await w.write(bytes);
      await w.close();
    } catch(e) {
      try { await w?.abort?.(); } catch { /* preserve original error */ }
      if(created) try { await dir.removeEntry(name); } catch { /* preserve original error */ }
      throw e;
    }
  }
}

/** Decode `archiveBytes` and, under the same exclusive save lock as export,
 * compare it with the current SAVE folder. Without `choice` nothing is written
 * and the conflicts come back for the launcher to resolve; 'skip' writes only
 * the files SAVE does not have yet; 'replace' also overwrites the conflicting
 * ones — the launcher must only pass 'replace' after the player explicitly
 * asked for it (a separate click on "replace all").
 * `options.root` (the OPFS root handle) is optional: it is only needed by the
 * replace path, which copies the old bytes of every readable conflicting file
 * into a restore-point archive (see save-protection.mjs) BEFORE anything is
 * overwritten. Without it the OPFS root comes from navigator.storage; when
 * that backup cannot be written, the whole replace fails closed — nothing is
 * overwritten without a restore point. Files that could not even be read have
 * no bytes to back up, so they are replaced without one and reported. */
export async function importBackupZip(openGame,locks,rootName,archiveBytes,choice,options) {
  const {entries,meta,lang,ignored}=decodeBackup(archiveBytes);
  return withSaveLock(locks,rootName,async()=>{
    const existing=await existingSaves(openGame);
    const plan=planRestore(entries,existing);
    if(plan.conflicts.length && choice!=='skip' && choice!=='replace')
      return {needsDecision:true,archiveEntries:entries.length,ignored,...plan};
    const write=choice==='replace'
      ? plan.restore.concat(plan.conflicts.map(c=>({name:c.name,bytes:c.archiveBytes})))
      : plan.restore;
    let backup=null, backupSkipped=[];
    if(choice==='replace' && plan.conflicts.length) {
      const backupable=plan.conflicts.filter(c=>c.existingBytes instanceof Uint8Array);
      backupSkipped=plan.conflicts.filter(c=>!(c.existingBytes instanceof Uint8Array)).map(c=>c.name);
      if(backupable.length) {
        const root=options?.root ??
          (typeof navigator!=='undefined'&&navigator.storage?.getDirectory ? await navigator.storage.getDirectory() : null);
        if(!root) fail('Не удалось создать резервную копию заменяемых сохранений; замена отменена, ничего не перезаписано.');
        // the restore point keeps each replaced slot's time record and language label too (existingSaves read them)
        const had=new Map(existing.map(e=>[key(e.name),e]));
        backup=await writeSaveBackupLocked(root,rootName,
          backupable.map(c=>{
            const e=had.get(key(c.existingName??c.name));
            return {name:c.existingName??c.name,bytes:c.existingBytes,...(e?.meta?{meta:e.meta}:{}),...(e?.lang?{lang:e.lang}:{})};
          }),'replace-import');
      }
    }
    const totalBytes=write.reduce((s,e)=>s+e.bytes.length,0);
    const est=typeof navigator!=='undefined' ? await navigator.storage?.estimate?.() : undefined;
    if(est && est.quota!=null && !(await isPrivacyCappedQuota(est)) && est.quota-(est.usage||0)<totalBytes)
      fail(`В хранилище браузера недостаточно места (свободно ${mb(est.quota-(est.usage||0))} МБ, нужно ${mb(totalBytes)} МБ).`);
    const dir=await (await openGame(true)).getDirectoryHandle('SAVE',{create:true});
    await writeSaveFiles(dir,write);
    // replace-all is explicit, so an existing file stored under different letter
    // case (e.g. "slot1" restored as "Slot1") is removed once the new bytes are
    // safely in place; a failed removal is reported, never silent.
    const warnings=[];
    if(choice==='replace')
      for(const c of plan.conflicts)
        if(c.existingName && c.existingName!==c.name)
          try { await dir.removeEntry(c.existingName); }
          catch(error) { warnings.push(`Не удалось убрать старый файл ${c.existingName}: ${error.message}.`); }
    // Time records travel with their slot's write decision (planMetaRestore):
    // restored and replaced slots get the archive's time, replaced slots
    // without one lose any local record, identical and skipped slots keep
    // theirs. Failures are warnings only — a lost time shows as 00:00, and a
    // slot whose time record names a slot absent from the archive is ignored
    // like any other foreign path.
    const slotKeys=new Set(entries.map(e=>key(e.name)));
    for(const m of meta||[])
      if(!slotKeys.has(key(m.name))) ignored.push('SAVE_META/'+m.name+META_SUFFIX);
    for(const m of lang||[])
      if(!slotKeys.has(key(m.name))) ignored.push('SAVE_META/'+m.name+LANG_SUFFIX);
    // The language labels (E5) follow the same decisions as the time records (planLangRestore): a replaced slot whose archive has no label
    // loses its old one, so a stale label never claims new bytes.
    let metaWritten=0, langWritten=0;
    if (meta?.length || lang?.length || write.length) {
      const names=await existingMetaNames(openGame);
      const kinds=[
        {plan:planMetaRestore(meta,write,names), suffix:META_SUFFIX, what:'времени', counter:()=>{ metaWritten++; }},
        {plan:planLangRestore(lang,write,names), suffix:LANG_SUFFIX, what:'языка', counter:()=>{ langWritten++; }},
      ];
      if(kinds.some(k=>k.plan.put.length || k.plan.remove.length)) {
        let metaDir=null;
        try { metaDir=await (await openGame(true)).getDirectoryHandle('SAVE_META',{create:true}); }
        catch(error) { warnings.push(`Не удалось открыть SAVE_META: ${error.message}. Время или язык заменённых сохранений могут относиться к прежней версии.`); }
        if(metaDir) {
          for(const {plan:kp,suffix,what,counter} of kinds) {
            for(const gone of kp.remove)
              try { await metaDir.removeEntry(gone); }
              catch(error) { warnings.push(`Не удалось убрать старую запись ${what} ${gone}: ${error.message}. Она может относиться к прежней версии сохранения.`); }
            for(const {name,bytes} of kp.put) {
              let w;
              try {
                const fh=await metaDir.getFileHandle(name,{create:true});
                w=await fh.createWritable();   // replace the whole record
                await w.write(bytes); await w.close();
                counter();
              } catch(error) {
                try { await w?.abort?.(); } catch { /* preserve the write error */ }
                // The slot was already replaced. A sidecar left from the old
                // slot must not silently claim the new slot's time or language.
                try { await metaDir.removeEntry(name); }
                catch(cleanupError) { if(cleanupError.name !== 'NotFoundError') warnings.push(`Не удалось убрать устаревшую запись ${what} для ${name.slice(0,-suffix.length)}: ${cleanupError.message}. Проверьте восстановленное сохранение.`); }
                warnings.push(`Не удалось записать запись ${what} для ${name.slice(0,-suffix.length)}: ${error.message}.`);
              }
            }
          }
        }
      }
    }
    if(backup) for(const w of backup.warnings) warnings.push(w);
    return {
      needsDecision:false, archiveEntries:entries.length, ignored, warnings,
      backup:backup?.name ?? null,
      backupSkipped,
      written:write.length,
      restored:plan.restore.map(e=>e.name),
      replaced:choice==='replace'?plan.conflicts.map(c=>c.name):[],
      skippedConflicts:choice==='replace'?[]:plan.conflicts.map(c=>c.name),
      identical:plan.identical,
      metaWritten,
      langWritten,
    };
  });
}
