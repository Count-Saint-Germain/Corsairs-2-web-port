> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

# Handle table race in default mode (`host/core.c`)

Status: fixed in `korsary2-next/recomp/host`, not committed. No live browser check was performed (see section 10).

Finding source: `historical diagnostic materials (removed)`, “Risks” section: the handle table is read and written without locking in permissive mode; TSan shows a race while two guest threads open/close files. This predates F3.2 (the strict path added `handle_try_new`/`handle_close_checked`, but ordinary `handle_get`/`handle_close`/`handle_new` stayed unchanged).

## 1. What was wrong

`g_handles[4096]` (`WinHandle`, ~1.1 KB per slot) was protected by `g_handle_lock` only in `handle_try_new` and strict functions (`handle_reserved/publish/cancel/close_checked`, `file_path_write_open`). The following remained unlocked:

| Location | Unprotected behavior |
|---|---|
| `handle_get` | read a slot `type` while another thread zeroed it (`memset`) during allocation |
| `handle_close` (permissive `CloseHandle`, `FindClose`) | read and changed `type`, `fd`, `buf`, `ptr`; two concurrent closes of one value both closed fd and called `free(buf)` (double free) |
| `handle_try_new` | scanned every slot `type` under lock while `handle_close` wrote `type = H_FREE` without lock: a normal data race |
| `CreateEventA/CreateMutexA/CreateSemaphoreA/CreateThread/FindFirstFileA` | `handle_new(type)` published a slot as live before writing `ptr`; a thread with a stale/guessed value (DirectSound: `kernel_set_event(h)` on a closed event) could read `ptr == NULL` and crash in `pthread_mutex_lock(&s->m)` (SIGSEGV inside `pthread_mutex_lock` in the pre-fix TSan run) |
| `CreateFileA`, permissive | `handle_new(H_FILE)` published a handle, then filled `fd`, `path`, `write_open`, `buf` without locking while another thread’s `file_path_write_open` read `write_open`/`path` of every `H_FILE` slot: it could observe a partially constructed handle |
| `g_threads_by_handle[]` | written in `CreateThread`, read in `ResumeThread`, without atomicity |

This is more than a TSan warning: double `free(buf)` and reading an incompletely initialized `ptr` are real when two guest threads race (audio, loading, guest threads).

## 2. Reproduction BEFORE the fix

`tests/test_handle_table.c` (real `core.c` and `kernel32.c`, synthetic files) was built with TSan against a pre-change `host/` copy (`run_handle_table.sh before BASE_DIR`). Four threads, 2000 kernel32-level and 20000 “raw” table operations per thread (warning counts vary: other runs produced 19 and 35, but always more than zero):

| Mode | TSan warnings before fix | After |
|---|---|---|
| permissive (default) | 157 | 0 |
| strict (`PORT_STRICT_FILE_SHARE=1`) | 23 | 0 |

Pre-fix distribution, permissive (`SUMMARY`): `handle_try_new` core.c:424 and :422 (81), `handle_close` core.c:454/456 (14), `handle_get` core.c:445 (12), `file_snapshot` kernel32.c:1479-1481 (13: slot fields filled after publication), `file_path_write_open` core.c:522 (8), `w_FindFirstFileA`/`w_CreateEventA`/`w_CreateMutexA`/`w_CreateSemaphoreA`/`w_CreateFileA` (`ptr`/field writes after publication). Strict was not clean either: `handle_get` versus slot `memset` and `file_path_write_open`.

First report (permissive), also the main race:

```
WARNING: ThreadSanitizer: data race
  Write of size 4 at ... by thread T2:
    #0 handle_close core.c:456              <- x->type = H_FREE, without lock
    #1 b_worker test_handle_table.c:296
  Previous read of size 4 at ... by thread T1 (mutexes: write M0):
    #0 handle_try_new core.c:422            <- if (g_handles[i].type == H_FREE), under lock
    #1 handle_new core.c:436
SUMMARY: ThreadSanitizer: data race core.c:456 in handle_close
```

The “before” run also crashes without TSan: a probe thread calling `SetEvent`/`kernel_set_event` on random values (`HT_RACY=1`) produced `SIGSEGV` in `pthread_mutex_lock` in the old tree (read `ptr == NULL` on a newly allocated event). Historical logs of that run were removed.

For completeness: under ASan/UBSan without TSan, the old tree passes the same test (the race does not corrupt values during the run), so TSan is the detector here; the test’s logical checks (value owner, slot marker, double close) catch mutations without TSan (section 7), important for wasm where TSan is unavailable.

## 3. Fix design

Choice: **atomic `type` field + leaf lock only for slot allocation and table scans + CAS on close**. Neither a single global mutex for all operations nor a lock per slot.

Hot-path rationale:

- `handle_get` is called by ReadFile/WriteFile/SetFilePointer/GetFileSize (tens or hundreds of thousands of calls when loading a save: 586k `ReadFile` per slot), SetEvent/ReleaseMutex/WaitForSingleObject (EA audio code locks and releases a mutex in a tight loop), `GetFileType` and `kernel_set_event` from the audio thread. A global mutex on every `handle_get` would serialize these threads unnecessarily, while a per-slot lock is unnecessary: the slot belongs to its owner. Thus `handle_get` takes no lock: one atomic acquire load of `type` (`ldar` on arm64, ordinary `mov` on x86, ordinary load in wasm).
- Allocation and close are rare (tens per second, not millions): allocation under lock, close by one CAS without lock.

Rules (contract comment above the table in `core.c`):

1. `type` is read and written atomically only (`SLOT_TYPE` acquire, `SLOT_SET_TYPE` release). Writing `type` publishes the slot fields populated before it.
2. `g_handle_lock` protects slot allocation (`handle_alloc`: free-slot selection, `g_handle_cursor`, round-robin flag; slot fields are zeroed, `type` written last) and the `file_path_write_open` scan (it must not observe a slot while being zeroed). These are the only places taking the lock (plus `handle_set_round_robin`).
3. Close (`handle_close`, `handle_close_checked`) claims the slot with one `compare_exchange` `type: live -> H_RESERVED` (`handle_claim`). Exactly one concurrent closer wins; others see `H_RESERVED` and return as for an already closed handle. Resources (`close(fd)`, `free(buf)`, `free(find-state)`) are freed after claiming, outside the lock; then `handle_unclaim` resets `fd = -1`, `buf = NULL` and writes `H_FREE` (release). The slot cannot be reallocated until resources are freed.
4. `H_RESERVED`: the slot is allocated but is not a live handle (an open that has not published its value, or a close in progress). Its claimer owns it: `handle_reserved/publish (CAS)/cancel` without a lock. Both permissive `CreateFileA` and `CreateFileMappingA` now use two-phase opening (reserve, populate, publish last); events, mutexes, semaphores, threads and file searches put the object into the slot before publication: `handle_new_ptr(type, ptr)`.
5. Handle values did not change: `handle_alloc` returns the same slot (lowest free; in strict, after the last one), and permissive `handle_new(H_RESERVED)` claims the same slot as `handle_new(H_FILE)`.

What did NOT change (verified by trace, section 6): handle values, F3.2 round-robin order, error codes, permissive `CloseHandle` always returns TRUE and repeated close is silent; strict returns `ERROR_INVALID_HANDLE` on repeated/foreign close.

A small accompanying hardening: `SetEvent/ResetEvent/ReleaseMutex/ReleaseSemaphore/kernel_set_event` check `ptr != NULL` (previously only the slot). `Sync` objects are not freed on close (by design: leak instead of use-after-free for waiters), so stale pointers to them are safe; `ptr` is now written once on allocation and not zeroed, so a reader from an earlier slot generation does not see an intermediate `NULL`.

## 4. Lock order

```
g_share_lock (strict)  ->  g_save_tx_lock  ->  g_handle_lock
```

`g_handle_lock` is a leaf: no external calls or other locks under it; `close()`, `free()`, `fprintf` run after release. This was checked by reading every occurrence: `handle_alloc`, `handle_set_round_robin`, `file_path_write_open` (only `strcmp` on slots). Consequences:

- Strict `CloseHandle`: `g_share_lock` → `handle_close_checked` (takes no lock) → `share_release`; the `g_share_lock` → `g_save_tx_lock` order is untouched.
- `save_tx_close_hook` is called by `W(CloseHandle)` BEFORE close under its own `g_save_tx_lock` and calls `handle_get(h, H_FILE)`: `handle_get` is lock-free, so deadlock is impossible by design; in the hook handle_get still sees a live handle, as before.
- Strict `CreateFileA`: `g_share_lock` → `handle_try_new` (`g_handle_lock`); publication under `g_share_lock` via CAS, without `g_handle_lock`.
- `kernel_set_event` from audio thread: `handle_get` (no lock), then `Sync`’s own lock.

## 5. All `handle_*` callers (grep over `host/*.c`)

Other `host/` files (`com.c`, `dsound.c`, `dinput.c`, `sched.c`, `input.c`, `window.c`, `user32.c`...) do not directly touch the table: the only link is `dsound.c` → `kernel_set_event(h)` (kernel32.c:697), now hardened with a `ptr` check.

| Call in `kernel32.c` | Behavior | Use-after-close |
|---|---|---|
| `GetFileType` (236) | `handle_get(h, H_FILE)` | closed: 0 (as before) |
| `CreateEventA/MutexA/SemaphoreA` (693, 721, 744) | `handle_new_ptr` | n/a |
| `kernel_set_event`, `SetEvent`, `ResetEvent`, `ReleaseMutex`, `ReleaseSemaphore` | `handle_get` + `Sync` | closed: FALSE/nothing; `Sync` is not freed: no UAF |
| `wait_one` (835), `try_acquire`/`can_acquire` | `handle_get(h, -1)`, then reread `x->type/x->ptr` in the wait loop | closing the same handle while waiting: guest error, residual risk (section 9) |
| `CreateThread` (964), `GetExitCodeThread` (1002), `ResumeThread` | `handle_new_ptr(H_THREAD, sync)`; `g_threads_by_handle` table now uses atomic publication | `ts` and `Sync` are not freed |
| `DuplicateHandle` (1014) | strict: `handle_get(ARG(1), H_FILE)` | unchanged |
| `CloseHandle` (1521/1533) | strict: `handle_close_checked`; otherwise `handle_close` | see section 3 |
| `save_tx_close_hook` (2285) | `handle_get(h, H_FILE)`, `fsync(x->fd)` | called before close |
| `CreateFileA` (2521-2598) | strict: `handle_try_new(H_RESERVED)`/`cancel`; permissive: `handle_new(H_RESERVED)`; both: `handle_reserved` → populate → `handle_publish` | n/a |
| `ReadFile/WriteFile/SetFilePointer/GetFileSize/FlushFileBuffers/SetEndOfFile` (2622-2742) | `handle_get(h, H_FILE)` | closed handle: `ERROR_INVALID_HANDLE` (tested, part D) |
| `FindFirstFileA/FindNextFileA/FindClose` (3096-3107) | `handle_new_ptr(H_FIND, fs)`, `handle_get`, `handle_close` | `FindNextFileA` after `FindClose`: `ERROR_NO_MORE_FILES` (as before) |
| `CreateFileMappingA/MapViewOfFile` (3165-3173) | reservation, `fd` from `dup`, publication | closed: `MapViewOfFile` returns 0 |

## 6. Expected and guaranteed use-after-close behavior

Windows: a closed handle becomes invalid, and an operation returns `ERROR_INVALID_HANDLE` (unless the value has already been reassigned to another object, in which case the operation targets the new object: strict allocation therefore uses round-robin to extend the value’s lifetime). In the port:

- **Guaranteed** (test part D, both modes): thread A gets a handle, thread B closes it, then A calls `ReadFile/SetFilePointer/GetFileSize/CloseHandle`: `ERROR_INVALID_HANDLE`; permissive `CloseHandle` remains TRUE (as before), strict: FALSE + `ERROR_INVALID_HANDLE`. The table remains intact: `type` is atomic, a value is not allocated twice, and double close frees resources once.
- **Not guaranteed** (no reference counting): a thread has already obtained a `handle_get` pointer and continues reading `x->fd`/`x->buf` in the same microsecond that another thread closes the SAME handle. Slot fields are freed on close, so a read from a closed/reused fd or freed snapshot buffer is possible. This is a guest error (likewise undefined in Windows); `handle_unclaim` resets `fd`/`buf` so a late reader is more likely to receive `EBADF` than freed memory. Full reference counting would require get/put pairs in every handler and was not implemented. Test E (`HT_RACY=1`, 30k rounds, ASan) did not reproduce such a crash, but TSan honestly reports the residual race.

## 7. Tests

New `tests/test_handle_table.c` + `tests/run_handle_table.sh`:

| Part | What it checks |
|---|---|
| A | single thread: values (lowest free slot, round-robin), invalid values (0, misaligned, outside table, `0xFFFFFFFF`), double close, `H_RESERVED`, exhaustion (4080 handles), fd/buffer close |
| A' | kernel32 layer: use-after-close, double `CloseHandle`, events |
| B | N threads on “raw” API (all types, reserve/publish/cancel/close_checked) + 2 probes + round-robin toggler; owner registry catches duplicate allocation, slot marker catches clobbering, final check confirms slots are free |
| B2 | 4 threads close ONE handle concurrently (x400; `handle_close` and `handle_close_checked`): exactly one free |
| C | N threads on real handlers (Event/Mutex/Semaphore/File read and write/Find/Mapping/ReadFile/SetFilePointer/GetFileSize) + 2 probes (`GetFileType` on random values), snapshots enabled, content checks |
| D | handle opened by one thread, closed by another, then used: `ERROR_INVALID_HANDLE` |
| E | `HT_RACY=1`: use during close + `SetEvent`/`kernel_set_event` on stale values; ASan only |

Modes: `native` (ASan/UBSan, env unset/0/empty/1), `tsan` (permissive and strict), `stress` (16 threads x 100000 raw operations and 16 x 100000 kernel32 operations under ASan, 16 x 20000 under TSan), `wasm`/`node` (emcc, threads), `before BASE` (old tree must show a race), `mutate`, `bench`.

Extended trace `test_file_share_default_trace.c` (91 → 277 lines: events/mutexes/semaphores/search/mappings, handle values and results after close, low-slot reuse, 64 consecutive opens) and a second variant with snapshots enabled (`snap`); `run_file_share_semantics.sh diff` compares both with a pre-change `host/` copy: **byte-identical**.

Mutations (`tests/mutate_handle_table.{py,sh}`): each removes exactly one protection in a `host/` copy; the test must catch it. Result: 10 of 10, control without mutation clean.

| Mutation | TSan | ASan/UBSan and test’s own checks |
|---|---|---|
| `alloc-no-lock`: allocate slot without lock | caught | caught (duplicate value allocation) |
| `round-robin-flag-no-lock` | caught | no |
| `claim-not-one-cas`: close not by one CAS | caught | caught (`double-free`) |
| `write-open-scan-no-lock` | caught | no |
| `type-load-not-atomic` | caught | no |
| `type-store-not-atomic` | caught | no |
| `publish-not-atomic` | caught | no |
| `close-without-claim`: old `handle_close` | caught | caught (`double-free`) |
| `close-checked-without-claim` | caught | caught (`FAIL`: not exactly one close) |
| `createfile-publishes-before-fill`: old permissive `CreateFileA` order | caught | not every run (test check catches it in some runs but not others): only TSan is reliable |

Candidly: memory-model mutations (atomicity of `type` load/store, publication CAS, scan lock, round-robin flag lock) and publication order in `CreateFileA` are reliably detected only by TSan; logical checks (value owner, slot marker, B2) catch four mutations: allocation without lock, close not by one CAS, old `handle_close`, and `close_checked` without claim. wasm has no TSan, so wasm runs check logic (owners, markers, B2), not the memory model; native TSan runs check the memory model.

Regression results, before/after (all run after changes; “before” was not rerun for unchanged suites because the `diff` trace reports identical behavior):

All runs on final code (after the last `core.c` change), exit code 0:

| Suite | Mode | Result |
|---|---|---|
| `run_file_share.sh` | native | PASS |
| `run_file_share_semantics.sh` | native, tsan, savetx | PASS |
| `run_file_share_semantics.sh diff <pre-change host copy>` | permissive trace (277 lines) and snapshot variant, env `0`/empty as unset, `PORT_NAME_CP1251` 0/empty | **identical** to old tree |
| `run_save_tx.sh` | all, wasm, node | PASS |
| `run_save_meta_time.sh` | native | PASS |
| `run_k1_dir_copy.sh` | native | PASS |
| `run_name_cp1251.sh` | all (native, tsan, savetx); wasm; node | PASS (`tsan` now exercises 8 threads in permissive too: those threads were previously skipped precisely because of this race) |
| `run_heap_stats.sh`, `run_heap_churn.sh` | native | PASS |
| `run_dsound_lifetime.sh` | asan, tsan | PASS |
| `run_com_ownership.sh` | native | PASS |
| `run_file_share_semantics.sh`, `run_file_share.sh` | wasm, node | PASS |
| `run_handle_table.sh` | native (unset/0/empty/1), tsan (permissive, strict) | PASS |
| `run_handle_table.sh stress` | ASan 16 x 100000 (raw operations and kernel32) in permissive and strict; TSan 16 x 100000 raw and 16 x 20000 kernel32 | PASS |
| `run_handle_table.sh wasm`, `node` | emcc, 8 threads (under emcc lock) | PASS |
| `run_handle_table.sh mutate` | 10 mutations | 10/10 caught |
| `run_handle_table.sh before <pre-change host copy>` | TSan, old tree | **fails as expected**: 19 warnings (permissive), 35 (strict) in this run (count varies between runs); see section 2 |
| SEH: `run_seh_lifecycle.sh wasm` (diagnostic tree) | emcc | PASS (previously: compilation error), see `historical diagnostic materials (removed)` section 9 |

No failures. One mistake during the work: when interrupting my run, `pkill` may have interrupted another agent’s `test_save_tx_matrix.mjs` (it was running in parallel in the same test directory); its owner should rerun it.


## 8. Overhead

`tests/bench_handle_table.c`, native -O2, Apple M4, loaded machine (load average ~10-20 from other processes; median of 7 runs, old/new builds interleaved in one `run_handle_table.sh bench BASE` invocation). Nanoseconds per operation, old / new:

| Operation | Before | After | Difference |
|---|---|---|---|
| `handle_get` on live handle | 0,5 | 0,5 | 0 |
| `handle_get` miss | 0,9 | 0,9 | 0 |
| `w_ReadFile` 16 B from snapshot | 3,6 | 3,5 | within noise |
| `w_SetFilePointer` | 2,9 | 3,0 | within noise |
| `w_SetEvent` | 5,1 | 5,1 | 0 |
| `w_CreateFileA` + `w_CloseHandle` (4 KB snapshot, real `open`/`read`) | 26610 | 26717 | +0,4% |
| `handle_new` + `handle_close` (bare pair) | 12,8 | 14,3 | +1.5 ns (+12%) |
| `w_CreateEventA` + `w_CloseHandle` (`calloc` + `pthread_mutex_init` in `Sync`, bare pair) | 30,3 | 34,3 | +4 ns (+13%) |
| 4 threads: `handle_get` | 1,2 | 1,2 | 0 |
| 4 threads: `w_SetEvent` (own events) | 23 | 21 | 0 |
| 4 threads: `handle_new` + `handle_close` | 175 | 183 | +4% |

Hot operations (`handle_get`, `ReadFile`, `SetFilePointer`, `SetEvent`) did not change because the new code replaced an ordinary load with an atomic acquire load on this path. Only allocation/close of bare pairs is more expensive (+1.5…4 ns: one CAS on close and release type store), indistinguishable in a real operation (`CreateFileA` with `open` and snapshot: 26.6 μs). This fits “≤ a few percent per handle operation” for all operations doing real work; relative +12–13% applies only to synthetic pairs measured in single-digit nanoseconds, absolute increase 1.5–4 ns.

## 9. Residual risks

1. **No reference counting** (section 6): use of a handle while another thread closes THAT SAME handle. Not characteristic of the real game, not reproduced; consequence: `EBADF`, reading freed snapshot buffer (rare UAF), for `H_FIND` double `closedir` on two simultaneous `FindClose` calls.
2. **(closed, section 12.1)** **Wait on a handle being closed**: `wait_one`/`try_acquire` reread `x->type`/`x->ptr` from the slot in the wait loop; if the handle is closed and the slot reallocated to another object, the waiter can read another `Sync`’s state without its lock. Waiting on a handle being closed is a guest error (undefined behavior in Windows). Possible hardening: capture `type`/`Sync*` once before the loop (no behavioral change for correct programs).
3. **(assessed, not changed, section 12.4)** `file_path_write_open` + `file_snapshot`: the “no writer on this path” check and snapshot are not atomic relative to each other (two concurrent opens of one path, one for writing and one for reading). Pre-existing, a logical race, not a data race; TSan cannot see it.
4. **(closed, section 12.2)** `CreateFileMappingA` in permissive: `fd` obtained by `dup` is not closed by `CloseHandle` (strict closes it); one fd leaks per mapping. Behavior was intentionally unchanged; fixable with one line in `handle_close` (`type == H_MAPPING`) if the game creates these mappings.
5. `profile_wait` (`kernel32.c:808`): unprotected lazy initialization of `static int on` (idempotent race on the first `WaitForSingleObject` from two threads); TSan reports it until first called by one thread. Not part of the table; test warms it up; harmless.
6. **(closed, section 12.3)** `g_threads_by_handle[]`: thread entry is not cleared on `CloseHandle(thread)` until the next `CreateThread` overwrites the slot at the same value; `ResumeThread` on a closed value can resume an already-started `ts` (nothing freed, no UAF).
7. Tested only on native (macOS arm64, ASan/UBSan/TSan) and wasm/Node (logic); no TSan in wasm.

## 10. Live-agent checks

TSan lines do not apply to a live browser session; signs of problems here differ:

1. A long session with multiple threads (audio, save load, transition to sea and back) with `?log=1` (`PORT_LOG=1`): look for `out of handles` (slot leak; 4080-handle table); `[file] CloseHandle(...) rejected: not a live handle` (only with `strictShare=1`: repeated or foreign close); `[handle] close of ... not a live handle` (permissive, added to `handle_close` by this fix, printed only with `PORT_LOG=1`; isolated lines are acceptable, a stream of identical values indicates double close in the game).
2. Occupied slot count: after loading a save and exiting to menu it should return to baseline (handle leak = slot never becomes `H_FREE`). Log metric: each `CloseHandle` with `[file]` log has an open/close pair; compare counts of `CreateFileA ... = ok` and successful closes over the session.
3. Byte-for-byte “load slot / save / exit” regression: save-file hash before and after (file-path behavior unchanged; `diff` trace identical).
4. If the game crashes with `SIGSEGV`/`RuntimeError: memory access out of bounds` during audio in `pthread_mutex_lock` (`kernel32.c`), this would indicate a `Sync` reader using a stale handle (should be blocked by the `ptr` check).
5. None of this requires running the game in this report; I did not run it.

## 11. Files for commit

Changed: `recomp/host/core.c`, `recomp/host/kernel32.c`, `recomp/host/win32.h`, `recomp/tests/test_file_share_default_trace.c`, `recomp/tests/run_file_share_semantics.sh`, `recomp/tests/run_name_cp1251.sh` (permissive threads now also under TSan).
New: `recomp/tests/test_handle_table.c`, `recomp/tests/run_handle_table.sh`, `recomp/tests/bench_handle_table.c`, `recomp/tests/mutate_handle_table.mjs`, `recomp/tests/mutate_handle_table.sh`, `docs/handle-table-race.md`.
Separately (diagnostic tree): `historical diagnostic materials (removed)`, `historical diagnostic materials (removed)`.

## 12. Closed follow-ups (2026-11-12, second wave)

Status: fixed in `recomp/host/core.c`, `kernel32.c`, `win32.h`, not committed; no live browser test
(section 12.8). The “before changes” baseline was stored as a `host/` copy (scratchpad; not committed).

### 12.1 (a) Waits: capture `type`/`Sync*` once, close while waiting

What the code did (HEAD `8232967`): `wait_one` called `handle_get(h, -1)`, then `try_acquire(x, ...)`/`can_acquire` reread
slot `x->type` and `x->ptr` on EVERY iteration. Consequences if another thread closed the same handle during a wait (all three
confirmed by test `F` on old tree, `run_handle_table.sh before-tails`):

| Scenario | Old code |
|---|---|
| `INFINITE` wait on an event that is closed | hung forever (close wakes nobody; slot `type` in `try_acquire` is checked only after wakeup) |
| same, with timeout | on timeout `try_acquire` read the slot: `H_FREE` fell into `default: return 1`, so wait returned `WAIT_OBJECT_0` instead of `WAIT_TIMEOUT` |
| slot reallocated to another event | slot `x->ptr` now pointed to NEW `Sync`: a waiter holding the old lock read and consumed the other event’s state (TSan: `kernel32.c:762 in try_acquire`) |
| wait on `H_FIND` (search handle) | search-state `ptr` was treated as `Sync` and locked as a mutex (UB; previously never checked) |

What the code does now (`kernel32.c`):

- `wait_one` reads the table ONCE: `handle_snapshot(h, &obj)` (core.c: atomic type and `ptr`, recheck type; if slot changed,
  the value is considered closed) and then uses a stack `WaitTarget { type, Sync* }` pair; the slot is no longer read. `Sync` is not
  freed, so its pointer remains valid. `can_acquire`/`wait_one_det` (deterministic mode) use the same pair.
- Closing a synchronization-object handle (`H_EVENT/H_MUTEX/H_SEMAPHORE/H_THREAD`) invokes a hook (`handle_set_close_hook`, registered
  in `sync_new`): under the object lock, `closed = 1` and `broadcast`. The hook runs from `handle_close`/`handle_close_checked` AFTER claiming
  the slot (one CAS, so exactly once per handle) and BEFORE freeing it: the handle value cannot be reallocated until the hook completes.
  The hook does not take `g_handle_lock` (leaf lock preserved), the `g_share_lock -> g_save_tx_lock -> g_handle_lock` order is unchanged;
  it takes only the `Sync` object’s lock, which is never held when acquiring the locks above.
- A waiter that did not acquire the object returns `WAIT_FAILED` (0xFFFFFFFF) and `ERROR_INVALID_HANDLE`. A signal received BEFORE close
  wins (`try_acquire` is checked before the flag): “SetEvent and immediately CloseHandle” wakes the waiter successfully (test `F3`, 50 rounds).
  This is Windows-like in that “waiting on a closed handle is not successful”: Windows documentation calls close-during-wait behavior
  undefined, while the kernel keeps the object alive during the wait; the port chose `WAIT_FAILED` because `Sync` has
  no other owners (`DuplicateHandle` returns the same value) and there is nothing else to wait for.
- What did NOT change (observable result in normal scenarios): waiting on a handle already closed, invalid or non-synchronization
  at call time (file, mapping, search, `0`, `0xFFFFFFFF`) still returns `WAIT_OBJECT_0` (“unknown
  objects are considered signaled”: historical port decision; changing it would be trace-visible). The sole change for
  non-synchronization types: `H_FIND` with non-null `ptr` now also returns `WAIT_OBJECT_0` instead of UB.
- Minor detail: slot `ptr` is now written and read atomically (relaxed) in `handle_alloc`, `handle_claim`, `HANDLE_PTR(x)` in all
  synchronization handlers (previously plain write versus plain read of stale value: TSan race on old tree
  `core.c:455`, `:512`).

### 12.2 (b) `CreateFileMappingA` did not close dup-fd in default mode

`W(CreateFileMappingA)` performs `dup(fd)` on the file; permissive `handle_close` (`CloseHandle`) closed fd only for `H_FILE`, whereas strict
`handle_close_checked` also closed `H_MAPPING`. One fd leaked per mapping (confirmed: test `H` on old tree, next `open` number rises
by 300). Fixed with one condition in `handle_close` (`type == H_FILE || type == H_MAPPING`). `MapViewOfFile` behavior is unchanged: the view
is copied on mapping (`pread`); closing the mapping afterward does not affect it; `MapViewOfFile` on a closed handle still
returns 0. The game does not import `CreateFileMappingA` (ENGINE and 45 module import tables), so this is a hygiene fix.

### 12.3 (c) `g_threads_by_handle[]` cleared on `CloseHandle(thread)`

The close hook (12.1) for `H_THREAD` writes `NULL` into the slot entry (release) BEFORE freeing the slot, so delayed cleanup cannot erase
a new thread entry for the same value. `CreateThread` now publishes the handle in three steps: `handle_reserve_ptr(sync)` (slot
`H_RESERVED`, `ptr` already set), write `g_threads_by_handle`, `handle_publish(h, H_THREAD)`; handle value is the same as
`handle_new_ptr` produced. Previously the handle was visible before the table write: closing in that window would leave a closed-value entry.
`ThreadStart` and `Sync` are still not freed (the thread owns `ts`); `WaitForSingleObject(thread)` and `GetExitCodeThread` use the handle’s `ptr`
(`Sync`), not this table, so are unaffected (test `G`). Observable change: `ResumeThread` on a closed value now
returns 0 and resumes nothing (previously it could resume a `CREATE_SUSPENDED` thread via a stale entry; in Windows
this is a guest error and `ResumeThread` would return -1).

### 12.4 (d) `file_path_write_open` + `file_snapshot`: assessed, no fix needed

Window: a read-only open checks `file_path_write_open` and then reads a snapshot; a writer on this path can open between them
(in permissive mode the writer slot is published after `open()`, so scanning cannot see it before publication). Conclusion: **do not change**.

- Either race outcome matches one of the sequential orders: snapshot before writer (reader gets a copy at open time) or
  live fd path. A reader opened before the writer cannot see its writes anyway (one-time copy, intended snapshot behavior,
  `kernel32.c` before `snapshot_enabled`), and a writer opened a microsecond after scanning is no different from one
  opened a second later. Test `I` fixes the contract: reader-first sees old data (`KNOWN-LIMIT`), writer-first
  disables the snapshot and reader sees live data.
- A writer with `O_TRUNC` in the window yields an empty (`st_size <= 0`) or short (read returns less than `fstat`) snapshot: both are discarded and the fd path remains.
- Full atomicity would require a lock covering the writer’s `open()` and the reader’s entire snapshot read (up to 16 MB), with no new
  guaranteed result: it adds write-open latency on all paths to impose an already valid order. TSan cannot see this race
  (logical, not a data race). A `kernel32.c` comment at `file_snapshot` records the decision.

### 12.5 Tests

`tests/test_handle_table.c` extended (after section 7); `run_handle_table.sh` gained `before-tails` mode:

| Part | What it checks |
|---|---|
| F1 | close during wait: event, semaphore, mutex (held by another thread), thread (unfinished): `WAIT_FAILED` + `ERROR_INVALID_HANDLE`, faster than timeout (5 s) |
| F2 | slot reallocated to another event while first wait blocked (x100): wait ends `WAIT_FAILED`, new event’s signal intact |
| F3 | `SetEvent`, then `CloseHandle`: blocked waiter succeeds (x50) |
| F4 | four waiters on one closed event: all `WAIT_FAILED` |
| F5 | wait on closed, invalid, search and file handles: `WAIT_OBJECT_0`, as before |
| F6 | 4 waiters, 2 x `HT_ITERS` waits each (default 6000), against 2 “create/set/close/reallocate” threads; result always in {0, `WAIT_TIMEOUT`, `WAIT_FAILED`}, TSan clean |
| F7 | deterministic scheduler path (`wait_one_det`/`can_acquire`, `sched_*` stubs): close -> `WAIT_FAILED`, signal and timeout as before |
| G1 | thread table entry cleared; `ResumeThread` on closed value resumes nothing; `GetExitCodeThread`/wait on live handle; slot reallocation (all platforms) |
| G2 | real `CreateThread` (`call_indirect` stub): ordinary, `CREATE_SUSPENDED`, close before `ResumeThread` (thread stays parked), close running thread while waiting on it (not wasm: sparse guest memory needed) |
| H | closing a mapping closes its fd; 300 mapping cycles do not change the next fd number |
| I | snapshot versus writer contract (12.4) |

Old tree (`run_handle_table.sh before-tails BASE`, `BASE/host` = pre-change copy): F (`ожидание закрытого события вернуло не WAIT_FAILED` — “wait on closed event did not return WAIT_FAILED”
after 5 s), G (thread table entry remained), H (fd not closed) FAIL, S under TSan reports a race (`try_acquire`, `handle_alloc`,
`handle_claim`), I passes (same snapshot contract). The original table race still reproduces on the pre-`8232967` tree
(`run_handle_table.sh before <pre-8232967 host copy>`): 30 TSan warnings in strict, parts A–E.

Mutations (`mutate_handle_table.mjs`): 6 added, total 16 of 16 caught; new ones caught by the test’s own checks (without TSan: important for wasm):
`close-hook-no-wakeup` (flag without `broadcast`), `close-hook-not-run`, `thread-table-not-cleared`, `mapping-fd-not-closed`,
`wait-ignores-closed-flag`, `wait-rereads-slot` (wait rereads slot in the loop).

Default-mode trace (`test_file_share_default_trace.c`): expanded from 277 to 313 lines (waits on live events/semaphores/mutexes/
thread and search handles, closed, invalid and non-synchronization values, closed mapping and `MapViewOfFile`); `run_file_share_semantics.sh
diff <pre-change host copy>`: **byte-identical** to old tree (and snapshot variant), as are `0`/empty environment variable.

### 12.6 Overhead

`run_handle_table.sh bench <pre-change host copy>`, native -O2 (Apple M4, loaded machine), nanoseconds per operation, before / after:

| Operation | Before | After |
|---|---|---|
| `handle_get` live / miss | 0,5 / 0,8 | 0,5 / 0,8 |
| `w_SetEvent`, `w_SetFilePointer` | 5,0 / 3,0 | 5,0 / 3,0 |
| `w_ReadFile` 16 B from snapshot | 3,2 | 3,6 (noise: min 3,4) |
| `handle_new` + `handle_close` (bare pair) | 15,2 | 15,1 |
| `w_CreateFileA` + `w_CloseHandle` (4 KB snapshot) | 26352 | 25955 |
| `w_CreateEventA` + `w_CloseHandle` | 32,6 | 36,8 (+4 ns: close hook locks `Sync`, wakes waiters) |
| 4 threads: `w_SetEvent` (own events) | 19,4 | 14,7 |
| 4 threads: `handle_new` + `handle_close` | 215 | 220 |

One methodological caveat: after the first build, 4-thread `w_SetEvent` measured 16 -> 23 ns. The cause was not path code: the `closed` field increased `sizeof(Sync)`
from 160 to 168 bytes, and neighboring events allocated consecutively by one thread shared cache lines differently (false sharing, visible only in this synthetic
benchmark). `finished` and `closed` are now 16 bits each, size is 160 again, and measurement returned to normal. Hot operations (`handle_get`, `ReadFile`, `SetFilePointer`,
`SetEvent`) did not change.

### 12.7 Regression results

All runs on final code (exit code 0). “Before” = `host/` copy at HEAD `8232967`+; native suites were also run before changes (all PASS,
`baseline.log` in scratchpad), then the same list was rerun and expanded after changes.

| Suite | Mode | Before | After |
|---|---|---|---|
| `run_handle_table.sh` | native (unset/0/empty/1) | PASS | PASS (with parts F, G, H, I) |
| | tsan (permissive, strict) | PASS | PASS (TSan clean, including F6, F7, G) |
| | stress (ASan 16 x 100000; TSan 16 x 20000) | PASS | PASS |
| | wasm, node (emcc, 8 threads; parts F, G1, H, I) | PASS (previous wave) | PASS |
| | mutate | 10/10 | 16/16 |
| | before (pre-8232967 tree) | reproduces race | reproduces (30 warnings) |
| | before-tails (tree before follow-up fixes) | n/a | F, G, H fail, S reports TSan, I passes |
| `run_file_share.sh` | native, wasm, node | PASS | PASS |
| `run_file_share_semantics.sh` | native, tsan, savetx, wasm, node | PASS | PASS |
| | diff (pre-change host copy) | identical (277 lines) | identical (313 lines, trace expanded in both trees) |
| `run_save_tx.sh` | all, wasm, node | PASS | PASS |
| `run_save_meta_time.sh` | native | PASS | PASS |
| `run_k1_dir_copy.sh` | native | PASS | PASS |
| `run_name_cp1251.sh` | all, tsan, wasm, node | PASS | PASS |
| `run_heap_stats.sh`, `run_heap_churn.sh` | native | PASS | PASS |
| `run_dsound_lifetime.sh` | asan, tsan | PASS | PASS |
| `run_com_ownership.sh` | native | PASS | PASS |
| `run_createfile_game_combos.sh` (K1b, new) | native, wasm, node | n/a | PASS |
| `run_create_always.sh`, `run_create_file_safety.sh` | native, wasm, node | PASS (previous wave) | PASS |

No failures in final runs. During work: test code `F7` initially produced a TSan warning from the scheduler stub (predicate read without lock
by `sched.c` design: “all others are parked”); stub now serializes predicate and close with a shared lock, as the real scheduler does. Host code
was unchanged here: `can_acquire` in the real scheduler is called with the other participants stopped (comment at start of `sched.c`).

### 12.8 Residual risks after this wave

1. No reference counting (section 9, item 1): use of a handle while another thread closes THAT SAME handle (read freed snapshot buffer,
   double `closedir` on two `FindClose` calls). Waits are unaffected: they hold `(type, Sync*)`, and `Sync` is not freed.
2. `Sync` objects remain unfreed: one `calloc` leak per created event/mutex/semaphore/thread (tens to hundreds per game; necessary cost of
   avoiding UAF).
3. Wait on a handle already invalid/closed before the call remains `WAIT_OBJECT_0` (not `WAIT_FAILED`): historical port decision; changing it
   would be visible to the game and requires separate justification.
4. Deterministic scheduler path (`PORT_DETERMINISTIC=1`) tested only using `sched_*` stubs; `sched.c` itself is not linked in the test.
5. `profile_wait` (section 9, item 5): lazy `static int on` remains unprotected (idempotent; test warms up).
6. TSan is native only (macOS arm64); wasm checks logic, part G2 (real threads with guest memory) does not run in wasm.
7. No live test performed. Log signs with `?log=1` for live agent: isolated `[handle] close of ... not a live handle` lines are acceptable;
   no dedicated `WAIT_FAILED` log line: a thread that previously hung forever on a closed object now receives `WAIT_FAILED` and
   `ERROR_INVALID_HANDLE` (sign: hang disappears when exiting to menu and from sea; if game behavior changes, identify which object
   is closed during wait).

### 12.9 Files for commit

Changed: `recomp/host/core.c`, `recomp/host/kernel32.c`, `recomp/host/win32.h`, `recomp/tests/test_handle_table.c`, `recomp/tests/run_handle_table.sh`,
`recomp/tests/mutate_handle_table.mjs`, `recomp/tests/test_file_share_default_trace.c`, `docs/handle-table-race.md`.
New (K1b): `recomp/tests/test_create_file_game_combos.c`, `recomp/tests/run_createfile_game_combos.sh`, `historical diagnostic materials (removed)`.

