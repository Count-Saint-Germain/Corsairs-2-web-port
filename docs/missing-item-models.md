> Historical technical document: intermediate diagnostic runs were removed. Their snapshots and command examples are unavailable; the current instructions are in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md).

> **Correction 12 November 2026:** Items models HAVE BEEN substituted from Ammo (there are 50 `.gm` files in `game/RESOURCE/MODELS/Items`); older statements to the contrary here and in `historical log (removed)` (around line 1006) no longer apply.

# Missing item models during the transition to Oxbay

Investigation on 5 November 2026. During the transition after the conversation at the start of the game, the browser may terminate at `RaiseException` at `0x006e4697`. An isolated Node/WASM run with logging reproduced the same stack: `0x006e4697 → 0x006e3b3e → 0x006e1e04`, immediately preceded by a failure to open `resource\models\items\blade6.gm`.

When a model cannot be opened, `GEOMETRY.dll` throws a C++ exception with the message `can't open geometry file`. A missing optional `.col` is handled separately. The port does not yet implement guest C++/SEH exception execution, so such an exception terminates the port.

The original code's handler for this case was found in the MSVC tables:

- Function `0x006e3860` registers SEH handler `0x006ec430` and sets state 0 before calling the geometry loader. The handler points to `FuncInfo` at `0x006ed998`: state 0 has a `try` block.
- The first of two `catch` handlers has type `.PAD` (`char *`), the type actually thrown, and address `0x006e39fa`; the second, `0x006e3a1e`, is a catch-all. Both return continuation `0x006e3a3e`, which restores registers and the SEH chain and returns NULL to the caller.
- Intermediate frames also have cleanup functions during unwinding: `0x006ec3f0` for `0x006e1d70` and `0x006ec3d0` for `0x006e1cf0`. Jumping directly to catch without unwinding and restoring the guest/host stack is therefore insufficient and may corrupt state.

Normal continuation after a missing file is supported here by analysis of the handler and tables; executing it in the port remains to be implemented and tested.

## Distribution inspection

`PROGRAM/ITEMS/initItems.c` declares models in the `items` directory that are absent from the unpacked game:

- `blade2`–`blade7`, `blade9`, `blade10`, `blade13`–`blade20`, `blade22`;
- `pistol1`–`pistol3`, `pistol5`.

There are 21 models in total. Files with the same names are present in `RESOURCE/MODELS/Ammo`, but this does not prove interchangeability: for example, the existing `Items/blade1.gm` and `Ammo/blade1.gm` differ in content and size. No substitution was performed.

All six volumes, `game-1.bin` … `game-6.bin`, were listed using the FreeArc command `unarc l --noarcext` and an unpacker built locally in `/tmp`. `game-1.bin` contains `RESOURCE/MODELS/Ammo/blade6.gm`, but not `RESOURCE/MODELS/Items/blade6.gm`; its `MODELS/Items` entries match the unpacked directory. `setup-1.bin` inside the unpacked game contains music files, while the ISO contains the same installation volumes and no separate model directory. The archive listings from this check are `/tmp/korsary-freearc/list1.log` … `list6.log`.

## Reproduction and limits of the conclusion

With an isolated game copy, Node/WASM using `PORT_LOG=1`, `PORT_HEADLESS=1`, `PORT_NO_AUDIO=1`, and the following `PORT_INPUT` reached Oxbay and crashed on `items/blade6.gm`:

```text
300:key=1c,700:key=39,760:key=d0,770:key=39,850:key=39,930:key=39,1010:key=39,1090:key=39,1170:key=39,1250:key=39,1330:key=39,1410:key=39,1490:key=39,1570:key=39
```

The log is `/tmp/korsary-geometry-trace/node.log`. The same headless run of the native build loaded the port models and continued: items are selected randomly, so a successful run alone does not rule out the defect with other random values. A repeated transition in the browser also succeeded. A missing `OXBAY_PORT.TGA.tx` was observed separately and did not cause this crash in the native run.

Addressing the cause requires verified original Items models from another installation available to the user or a correct implementation of the original exception handler identified above. Data from unverified sources and Ammo models were not substituted.

## Dynamic unwind test

For a repeatable test, only `Items/blade1.gm` was removed from a separate temporary game copy; the remaining game files and main build were unchanged. An auxiliary instrumented WASM build reproduced the exception with `object=0x002fe3e4`, `ThrowInfo=0x006ed8fc`, and a pointer to the string `can't open geometry file`. The guest registration chain found in `FS:[0]` was:

| Order | Registration | Handler | State |
|---|---:|---:|---:|
| 1 | `0x002fe41c` | `0x006ec3f8` | 0 |
| 2 | `0x002fe440` | `0x006ec3e4` | 0 |
| 3 | `0x002fe6a8` | `0x006ec430` | 0 |

The first two registrations lead to the cleanup functions above; the third leads to the handler with a matching `catch (char *)`. `ThrowInfo` has no destructor; the first `CatchableType` entry contains type `.PAD`, size 4, and the simple-type flag. The exception object contains a 32-bit guest pointer that must be placed in the handler's local variable at relative offset `+0xc`. Isolated-test log: `/tmp/korsary-seh-study/forced.log`.

A general implementation must separately validate metadata and find a matching handler, then perform intermediate cleanups from inner to outer, bind the catch object, and restore guest and host stacks before transferring control to the continuation. Calling the catch function alone is insufficient: translated guest functions are nested within the ordinary host C stack. MSVC tables, other type variants, nested exceptions, and unknown handlers need testing; unsupported cases must not silently be considered handled.

## Isolated prototype: handler selection and cleanup plan

A separate prototype for parsing a limited subset of Visual C++ 6 C++ EH tables (`0x19930520`) was created in `historical diagnostic materials (removed)`. It is not connected to the main build, does not modify the game, and does not yet execute the handler. A synthetic table without game addresses tested typed-catch selection by type name with different RTTI addresses, fallback to catch-all, inner-to-outer ordering of two cleanups, and passing a four-byte catch value. Corrupted offsets, unwind cycles, and rejection of unverified formats are checked, including an object with a destructor and nested try blocks. The test passed natively with AddressSanitizer/UndefinedBehaviorSanitizer and in Node/WASM with pthread.

The prototype deliberately does not claim complete SEH support: registration records are still supplied by a prevalidated adapter; C-stack transfer and cleanup/catch execution are not implemented. It therefore does not yet fix the reproduced game exception. Next, decoding must be tested against real GEOMETRY tables, and correct control transfer through nested translated functions and state restoration during cleanup must be established separately.

### Tests on real tables and control transfer

An additional local test applied PE relocations from the user's `GEOMETRY.dll` to the guest base and supplied its real tables to the same generic planner. The result matched the trace: two cleanups, `0x006ec3f0` and `0x006ec3d0`, followed by matching handler `0x006e39fa` and a four-byte catch object. Game addresses appear only in the test fixture, not in the planner itself. The prepared image `/tmp/korsary-seh-study/geometry-guest.bin` contains game files and is intended only for local testing; it must not be published.

A separate synthetic test checked `setjmp`/`longjmp` transfer across two nested functions: simulated cleanups ran in the expected order, control reached the boundary, and did not return to discarded functions. It passed with ASan/UBSan on macOS and in Node/WASM with pthread. This tests the mechanism, not execution of generated game functions: a per-thread boundary registry model, nested-exception safety, guest ABI, execution of real funclets, correct guest-stack restoration, and integration into the translator have yet to be proven. The test does not establish that SEH works in the game.

### Boundary registry: synthetic integration

A per-thread registry of live `setjmp` boundaries was added to the isolated prototype. It requires separate plan validation before cleanup; boundaries of discarded host frames are removed before transfer to the target. In the test, two threads simultaneously register identical guest addresses and transfer control independently; it also checks rejection of unknown boundaries, side-effect-free preflight, cleanup order, catch binding, and a prohibition on redispatch during unwind. The test passed on macOS with ASan/UBSan and in Node/WASM with pthread.

This is still a synthetic adapter: it simulates funclets and register setup. If a callback fails after cleanup starts, state may already have changed; the caller must treat such an error as fatal. Execution of real funclets, access to the saved guest stack, and compatibility with generated functions still require separate verification. The code has not been added to the main build.

### Work stopped

The investigation was stopped at the user's request. Before stopping, an isolated Node run recorded a guest-stack snapshot at `/tmp/korsary-seh-study/guest-stack.bin`; it had not been checked at the time work stopped. A later check is described below. The snapshot and other temporary files may contain game data and are not intended for publication. The run was interrupted; the main build was unchanged, and the SEH prototype remains a separate experiment that does not fix the game.

### Continuation on 6 November: fatal error during unwind

In the isolated `seh_boundary.c`, a cleanup, finish-frame, or bind failure now permanently marks the current thread's registry as poisoned: subsequent push/pop, dispatch, and resume are rejected. There is no rollback of side effects, and the embedding runtime must terminate the affected guest thread. Both error paths and thread isolation passed native ASan/UBSan and Node/WASM pthread tests. This guards against accidental reuse of the prototype; it does not implement game SEH.

The generated GEOMETRY contains real cleanup and catch functions. For the observed frame, its prologue sets `EBP=registration+12` and saves the working ESP at `[EBP-0x10]`; catch returns the continuation address in EAX, and the continuation restores FS, registers, and stack. These facts apply to the inspected code; the ABI has not been proven general.

The planner also had its signed catch-slot offset relative to EBP and validation of termination of both RTTI names on mismatch corrected. Tests were added for negative and out-of-range offsets and a corrupt name. Synthetic tests passed native ASan/UBSan and Node/WASM; the real GEOMETRY table test passed natively again.

For the inspected GEOMETRY, `f_006e520c` performs the current frame's actions, then writes the final state to `registration+8`, including when there were no actions. The planner now preserves the original and final state and cleanup range for each frame; the synthetic dispatcher calls `finish_frame` after its cleanup. Invalid ranges are rejected before changes; a callback error poisons the thread. Multiple states, a frame without cleanup, callback order, a negative grouping test, and three failure types passed native ASan/UBSan, Node/WASM, and the real GEOMETRY tables. The callback remains synthetic: writing to the real guest stack and other unwind details remain untested, and integration into the game has not been performed.

**Order correction:** rechecking `f_006e52c0` revealed an error in the old plan: the target frame unwinds to `tryLow`, not `tryLow-1`; before catch, `tryHigh+1` is written to its state. In this code, catch object binding occurs before the global unwind. The plan and synthetic dispatcher were corrected: bind → cleanup/finish by frame → enter-catch → control transfer. Failure of any of the four callbacks poisons the thread. Native ASan/UBSan, Node/WASM for the dispatcher, and the real GEOMETRY table test passed. Real integration remains untested; nested exceptions are unsupported.

In a separate test, two real translated cleanup functions are invoked through a prototype boundary on controlled guest memory; the destructor call, argument to a stub free service, and state writes were checked. Another test executes a real typed catch and continuation: arguments to the stub logging service, continuation address in EAX, and restoration of registers, ESP, and FS were checked. Both passed native ASan/UBSan and Node/WASM pthread. The test prepares the frame itself and substitutes external services, so it does not test the normal in-game call or full guest/host unwind.

An isolated `seh_walk.c` was added: it walks x86 SEH registrations within specified stack bounds, requires alignment and strictly increasing addresses, checks a limit, and passes handler recognition to a required validating callback. No partial list is returned for an unknown handler or malformed chain. Synthetic checks passed native ASan/UBSan and Node/WASM. Real TIB bounds and handler-signature verification have not yet been connected; this is not a game adapter.

The isolated `seh_resolver.c` validates the narrow VC6 pattern `mov eax, FuncInfo; jmp dispatcher`, the jump address, code and data bounds, FuncInfo magic, and a specified dispatcher signature. Synthetic negative tests passed native ASan/UBSan and Node/WASM. For the local GEOMETRY fixture the full chain was tested: synthetic registrations → real relocated bytes of three handlers → real tables → the previous cleanup/catch plan. The caller's adapter must reliably authenticate the entire module version and dispatcher before use: a short signature alone does not prove identity. Live stack, other versions, and runtime integration remain untested.

The previously saved 64 KiB stack snapshot from the interrupted forced throw has now been matched against the relocated GEOMETRY image. Walking to the observed target registration recognized three handlers and the real exception object and built a plan for two cleanups and a typed catch; the test passed native ASan/UBSan. A full walk does not return a partial success: unsupported ENGINE handlers follow the target frame. Limiting the walk to the target boundary must not skip a matching catch in inner frames. When stopping at the target frame, its outer-frame link is still checked for order, alignment, and stack bounds; the negative test passed native and Node/WASM. The snapshot tests parsing recorded data, not execution of unwind in the running game. The added `seh_tib_stack` reads bounds and chain head from the x86 TIB and validates ESP and the first registration; synthetic tests passed native ASan/UBSan and Node/WASM. In the snapshot test, TIB fields were reconstructed from the log; the adapter must verify that the TIB belongs to the current thread. Local command (both files contain game data and are not intended for publication):

```sh
historical diagnostic materials (removed) /tmp/korsary-seh-study/geometry-guest.bin /tmp/korsary-seh-study/guest-stack.bin
```

In the main host, diagnostic printing of the `RaiseException` type now uses bounded guest-memory reads; corrupt metadata must not cause an out-of-bounds access merely while printing the name. Invalid pointers and a missing terminator were tested with native ASan/UBSan and Node/WASM. This is not exception handling: an unfamiliar or any other throw still traps. On the local exception snapshot, bounded reading also returned the actual name `.PAD` (native ASan/UBSan). Boundary integration conditions are described in `historical diagnostic materials (removed)`.

The dispatcher additionally validates target-frame index, state order, catch-state, and ascending frame addresses before any callbacks; tests for invalid target/catch-state passed native ASan/UBSan and Node/WASM.

The isolated end-to-end harness `run_geometry_boundary_live.sh` temporarily instruments a local copy of generated GEOMETRY after the real target-function prologue. Real translated functions create three live registrations; a stub open initiates the translated C++ throw, a plan is built from real tables, two real cleanups run, control transfers to a host boundary, and real catch and continuation execute. Stack/registers, three alternating normal/throw repetitions, and rejection before side effects for an incorrect funclet or unknown boundary were checked. Native ASan/UBSan and Node/WASM pthread passed. Open, allocator, and logging are replaced with stubs; FS is switched by the test before catch, and the exact order of removing intermediate registrations and safety of real host frames are unproven. This is not integration or an in-game test.

The isolated registry gained a `seh_host_guard_enter/leave` model: a boundary records the depth of marked host frames, and dispatch refuses to cross one. An unbalanced guard after a callback poisons the thread. Rejection before side effects, nested boundaries, and guard leaks passed native ASan/UBSan and Node/WASM. The model protects only explicitly marked calls; an audit and instrumentation of all real host frames has not been performed, so game-integration safety is unproven. Recursive dispatch during preflight is also prohibited; the negative test passed native ASan/UBSan and Node/WASM. The end-to-end GEOMETRY harness passed again in both environments after guards were added; it does not instrument real game host frames.

A gap after `seh_boundary_resume` was fixed: before the catch boundary is removed, new dispatch and creation of a nested boundary are now prohibited. Thus an as-yet-unsupported nested exception will not be mistakenly accepted by the dispatcher. Negative tests and the repeated end-to-end GEOMETRY harness passed native ASan/UBSan and Node/WASM pthread.

The end-to-end test was then refined: rather than directly calling two cleanup functions, it calls the real translated `006e520c` and `__CallSettingFrame` and checks temporary SEH registration within cleanup. After each intermediate handler, the test removes one frame in the order described by [Wine RtlUnwind for x86](https://github.com/wine-mirror/wine/blob/master/dlls/ntdll/signal_i386.c) and [Wine MSVCRT for x86](https://github.com/wine-mirror/wine/blob/master/dlls/msvcrt/except_i386.c). Native ASan/UBSan and Node/WASM pthread passed. Wine-like wrapper/catch registrations remain synthetic; actual Windows XP and nested-exception behavior are unproven. This refinement replaces the earlier model in which the test left the original FS head in place until entering catch.

For a future host-guard audit, `historical diagnostic materials (removed)` identified specific `guest_stdcall`, thread entry, module attach, interpreter, and `call_indirect` debug paths that have post-call work or their own lifetime. This is static research, not a proven complete callback list or guard instrumentation in the game build.

For further experimental integration, a separate port, `historical diagnostic materials (removed)`, was prepared with an independent `game` directory. Its data may be modified for reproducible local tests; the copy itself is not a verified or main port.

Experimental host-guard instrumentation under `PORT_EXPERIMENTAL_SEH_GUARDS` began in this copy. A native ASan/UBSan test of the real dispatcher checked that imports, the interpreter, `guest_call`, and the trace branch do not allow transfer across an active host frame, while a direct guest call can transfer to a live boundary. The same test passed Node/WASM pthread. All imports, including RaiseException itself, are still guarded: a safe terminal path has not yet been created, so a guest throw is not considered supported. `guest_stdcall`, thread entry, additional callbacks, and game integration still need testing. The current guard has only a depth counter, with no host-frame owner token: removing one boundary inside `RaiseException` is unsafe without proof that it is the terminal call's own boundary.

The test was extended with real `guest_stdcall`: transfer across the callback was rejected and the normal ESP restored; native ASan/UBSan and Node/WASM passed. A read-only `seh_adapter` was also created in the diagnostic copy; it can only output a diagnostic plan and does not authorize dispatch. Synthetic rejection cases and relocated GEOMETRY metadata with a synthetic stack passed native ASan/UBSan and Node/WASM pthread. The real ThrowInfo contains two CatchableType entries. The adapter result does not authorize execution of the plan; the opt-in translator profile is still being tested. An additional adapter run on a recorded guest stack and relocated GEOMETRY metadata passed native ASan/UBSan: the plan and saved ESP matched and memory did not change; Node/WASM pthread also passed. TIB and attestation callbacks remain test-only.

Host-guard owner tokens with an atomic generation were applied in the diagnostic copy. Wrong/stale tokens, address reuse, counter exhaustion, two threads, and the exact test import slot, including name and function substitution, were tested. After terminal consume, erroneous dispatch or a normal return leads to poison/trap. Native ASan/UBSan and Node/WASM pthread passed; the previous Node trace run did not set the variable in Emscripten libc, which was fixed in the new run. The real RaiseException is not connected. Attestation of the full path and unmarked host frames was not performed; the old raw depth API remains available for prototype tests. After the guard change, the read-only adapter again passed native ASan/UBSan and Node/WASM with real relocated GEOMETRY metadata and a synthetic stack; the recorded game stack was not used in this last run.

A subsequent test permits nested owned guards inside synchronous preflight/cleanup when removed before return; the lower boundary is frozen, and the complete token and pending-token snapshot is checked after the callback. Test cleanup performed an import via real `call_indirect`; leaks, redispatch, and substitution of the lower owner's generation result in poison. Native ASan/UBSan and Node/WASM passed. These are test callbacks, not an audit of actual game host services.

An audit of the locally recorded stack showed common guest-heap ownership of the two cleanups: the first retrieves the same object through `reg0-0x10` and changes its vtable; the second passes it for release through `reg1-4`. The earlier harness uses stub allocator and free functions, so the actual owner and real virtual-free path are unconfirmed. This observation applies to the specific snapshot, not all exceptions.

In the current runtime, a child `GuestThread` stores a TIB address but not independent host-trusted stack bounds; trusting only editable guest TIB fields is insufficient. The main thread runs `g_cpu`, while `t_self->cpu` holds a copy, so the main CPU cannot be authenticated by equality with `&t_self->cpu`.

To address this part, a separate host-owned TLS binding was developed: `historical diagnostic materials (removed)`. Loader→game handoff between threads, concurrent claim, stale tokens, CPU/fs_base/phase, and overlaps of complete TIB/stack ranges passed native ASan/UBSan and Node/WASM pthread. Real runtime, guest-memory allocation, and guest TIB/FS validation are not connected; unbind while a boundary is live is not yet blocked. This is not game attestation. Offer is a cooperative bearer token and does not authenticate a preassigned host thread; recipient authorization and prohibiting offer while a boundary is live remain obligations of future integration.

In the diagnostic copy, `seh_bound_adapter` connected a host-owned lease and real CPU type to read-only analysis: bounds come from the registry and lease/CPU are rechecked after analysis. Synthetic native ASan/UBSan and Node/WASM pthread checks for wrong CPU/thread/TIB/bounds, stale lease, and CPU changes passed. This is not yet real runtime binding, protection from concurrent guest-memory changes, or authorization to dispatch. Commands: `historical diagnostic materials (removed)`.

The loader and game host thread use one main record/TIB in different phases; this does not authenticate the current owner. In addition, `SehAdapterAnalysis` still loses each frame's `funcinfo`, which real GEOMETRY local unwind needs. The current interface issues a callback for each cleanup, while local unwind itself executes all actions in one frame. Directly combining them with multiple actions may repeat cleanup: a separate verified grouped ABI is needed. Detailed audit: `historical diagnostic materials (removed)`.

A separate prototype, `historical diagnostic materials (removed)`, preserves `funcinfo` without changing the old ABI and calls the supplied local-unwind callback once per frame. Three actions in one frame, empty frames, and negative cases passed native ASan/UBSan and Node/WASM; the old suite with a local fixture also passed. Callbacks and observer in these checks are trusted; real `006e520c`, FS, and observer on a real gateway have not yet been tested, and this API is not connected to the game.

Clarification: a later separate gateway harness in the diagnostic copy `historical diagnostic materials (removed)` tested real translated `006e520c` and `__CallSettingFrame` on synthetic metadata with three funclets in a frame. The observer is temporarily inserted immediately before `call_indirect` and checks target/registration; an incorrect action is not started, and already executed actions are not rolled back. Native ASan/UBSan and Node/WASM passed. Funclet, FS, and terminal abort are test doubles; the real game gateway and Windows XP were not tested.

An audit of the opt-in translator profile found that the early check ran after the guest prologue, and a successful callback could restore only FS while leaving incorrect registers. Pre-prologue checks and validation of attested postconditions were added in the diagnostic copy; mismatches trap. The previous registration cannot overlap the current frame and arguments. All 12 native/Node tests and four independent native ASan/UBSan tests passed after the changes. Bounds from guest TIB do not attest memory allocation or TIB ownership; `PREEMPT_POLL` remains before the check. Even matching registers do not prove execution of real cleanup/catch. The profile is not enabled in the game.

The end-to-end local harness `historical diagnostic materials (removed)` connects an automatically generated boundary, read-only adapter, owned terminal guard, real dispatcher, and translated cleanup/catch/continuation. Native ASan/UBSan and Node/WASM passed, including negative tests for exception code and attempts to transfer before terminal token confirmation. Stub RaiseException, open, allocator/free/logging, FS callbacks, and attestation are used: this is not a test of the real game path or memory owners.

The next diagnostic harness, `historical diagnostic materials (removed)`, connects the grouped dispatcher to the read-only bound adapter, terminal guard, and real translated GEOMETRY cleanup/catch. Native ASan/UBSan and Node/WASM passed; three actions in one frame were tested separately with synthetic callbacks, whereas the real two cleanups belong to different frames. Real RaiseException is not connected, while attestation, open, allocator/free, and FS remain test doubles. `seh_boundary_quiescent()` checks only the current host thread and is not an atomic or authorized cross-thread handoff.

In the diagnostic copy, `PORT_DIAG_SEH=1` binds loader/game to a host-owned lease and connects read-only analysis to the real RaiseException, but the certifier always refuses. In Node/WASM with `Items/blade1.gm` temporarily absent, the bound loader/game, `denied_cert_kind=4`, absence of a live boundary, and then the original trap were observed; the file was restored with matching SHA-256. Worker/timer activity was not observed on the short game path. Build and native tests passed. Neither real catch nor exception handling is implemented by this: see `historical diagnostic materials (removed)`.
