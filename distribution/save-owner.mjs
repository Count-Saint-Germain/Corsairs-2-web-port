/* Page ownership of the save locks: from the moment a game start may have
 * launched workers until the document goes away, this page is the only writer.
 * Both save roots (the solo game root and, online, the netplay userdata root)
 * are captured with the exact `${root}:save-backup` exclusive Web Lock that
 * withSaveLock uses, so backup, import, export, update and picker flows in
 * other cooperating tabs of this origin refuse fast instead of racing the
 * running game's writes.
 *
 * What this protects: cooperating pages running this version of the page.
 * What it does not: tabs opened from an older build (they never take this
 * lock), tools outside the Web Locks API, and whatever is not proven here —
 * browser teardown, BFCache restore, worker writes after the lock was handed
 * over, a crashed page. There is deliberately no release path once the runtime
 * has started and no pagehide/unload hook: a failed start keeps the locks held,
 * and only leaving or reloading the document ends the ownership (a BFCache
 * restore must also not find them released, which is why nothing releases on
 * navigation either). */
import { saveLockName } from './save-export.mjs';

const fail=(message)=>{ throw new Error(message); };

/** Fast refusal, not waiting: the save locks belong to another page or to a
 * still-running operation of one. */
export class SaveLockBusyError extends Error {
  constructor(message='Сохранения сейчас заняты другой операцией.') {
    super(message); this.name='SaveLockBusy';
  }
}

// Fail-fast capture of one save lock whose request callback parks until
// release. The returned release is idempotent and awaits the lock manager, so
// a rollback can never finish while the request is still unsettled.
async function acquireSaveLock(locks,rootName) {
  if(!locks?.request) fail('Браузер не поддерживает блокировку сохранений.');
  if(typeof rootName!=='string' || !rootName) fail('Не задано имя хранилища.');
  let releaseGate, held, failed;
  const gate=new Promise(r=>{ releaseGate=r; });
  const acquired=new Promise((resolve,reject)=>{ held=resolve; failed=reject; });
  const request=Promise.resolve().then(()=>locks.request(saveLockName(rootName),
    {mode:'exclusive',ifAvailable:true},async lock=>{
      if(!lock) throw new SaveLockBusyError();
      held(); await gate;
    }));
  request.catch(failed);   // a request may reject before its callback runs
  await acquired;
  let released=false;
  return async()=>{ if(!released){ released=true; releaseGate(); } await request; };
}

/** Own the save locks for the whole page lifetime around one game start.
 * Captures `gameRoot` and, when netplay uses a different root, `netRoot`
 * (fail-fast; a busy refusal throws SaveLockBusyError before startRuntime
 * runs), then runs `clearNet` once for netplay and hands over to
 * `startRuntime`. An optional `beforeStart` (default none: behavior is exactly
 * as before) runs after the captures and clearNet, still before any runtime
 * exists — the place for save recovery (save-tx.mjs), which needs the lock
 * and must finish before the game can write; if it throws, the locks this
 * call took are rolled back like for any other pre-runtime error and the game
 * does not start. An error before startRuntime rolls back only the locks this
 * call took. An error thrown by startRuntime — including a createPort
 * rejection after it began launching workers — is rethrown with
 * `runtimeStarted = true` and its locks deliberately kept: after that point
 * there is no telling what the runtime already touches, so releasing would
 * let other tabs write under a live game. The caller must treat such an error
 * as "reload the page", never as a retryable one. */
export async function runExclusiveForPageLifetime({locks,gameRoot,netRoot=null,
  clearNet=async()=>{},beforeStart=null,startRuntime}) {
  if(typeof gameRoot!=='string' || !gameRoot ||
     (netRoot!==null && (typeof netRoot!=='string' || !netRoot)) ||
     typeof clearNet!=='function' || (beforeStart!==null && typeof beforeStart!=='function') ||
     typeof startRuntime!=='function')
    fail('Некорректные параметры запуска игры.');
  const releases=[];
  try {
    releases.push(await acquireSaveLock(locks,gameRoot));
    if(netRoot && netRoot!==gameRoot) releases.push(await acquireSaveLock(locks,netRoot));
    if(netRoot) await clearNet();
    if(beforeStart) await beforeStart();
  } catch(error) {
    // No runtime has been invoked: roll back our own captures (best effort —
    // the original error is what the caller needs) and let it propagate.
    while(releases.length) try{ await releases.pop()(); } catch { /* keep the original error */ }
    throw error;
  }
  try { return await startRuntime(); }
  catch(error) {
    if(error instanceof Error) error.runtimeStarted=true;
    throw error;
  }
}
