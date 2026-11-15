# Multi-module guest implementation (Session 2)

The engine scans `modules\` for `*.dll` (FindFirstFileA/FindNextFileA, alphabetical), `LoadLibraryA`s
each one and calls `GetProcAddress(dll, "DMAInterface")`; every module exports exactly that (XINTERFACE.dll
also exports `?SFLB_DoControl@XINTERFACE@@IAAXXZ`), and the returned object registers the engine
classes. So the port must translate **all 45 module DLLs** besides ENGINE.exe and make LoadLibrary /
GetProcAddress resolve guest exports. (Excluded on purpose: `game/engine.dll` is StarForce DRM and
never referenced by the game; Config.exe / decode.exe / depack.exe / 7z.dll / setup-1.bin / data1.dat
are DRM-related and unused.)

## Design

Translated C bakes in absolute guest addresses, so final image bases are chosen once, at configure
time, and the runtime maps every image at exactly that base:

1. `tools/configure.mjs` reads `port.json` `"modules"` (all 45, exact name case) and picks a final
   64 KiB-aligned base per image: the exe keeps its preferred base (0x400000); each module prefers
   0x10000000 (all Storm 2 modules do), which collides with the guest heap, so it takes the next free
   slot above the previous image, always below the heap (0x10000000). Result: `recomp/data/images.json`
   (the manifest, DX8RENDER.dll @ 0x690000 ... touch.dll @ 0xd00000) and `recomp/host/port_modules.h`
   (the {name, base} table). Bases are deterministic from port.json.
2. `node recomp/translator/x86toc.mjs --manifest recomp/data/images.json <outdir>` translates every image in
   one run (chunk files `<tag>_NNN.c`, one shared `recomp.h`). When an image's final base differs from
   its preferred ImageBase:
   - every address read from the image file (jump-table entries, pointer/gap-entry seeds, jumptables,
     function entries/ranges) shifts by the delta where it points inside that image (`Program.to_final`);
   - relative branch targets need no shift: disassembly runs at final addresses, so capstone computes
     them in final space already;
   - absolute address constants in instructions shift **only where .reloc lists the field** — exactly
     the fields the runtime loader rewrites, so translated code and loaded memory agree. Capstone's
     operand `imm`/`mem` properties are read-only; the fix writes the underlying ctypes union
     (`op.value.imm`, `op.value.mem.disp`).
   - Every export address (plus the PE entry point) is seeded as a function entry even when the image
     has no functions.json, so `GetProcAddress` results are always translated code.
   - Output `out_all/modules.json`: per-image tag/base/size/exports — the map of what was translated.
3. `recomp/runtime/runtime.c` loads every image at startup:
   - `load_image(path, base, out)` (base 0 = preferred base) maps at the final base and applies base
     relocations (HIGH/HIGHLOW/LOW) when final ≠ preferred;
   - code/writable ranges of all images are unioned into `g_code_lo/hi`, `g_data_lo/hi`
     (`looks_like_code`, determinism hashing still work unchanged); per-image spans are kept in a
     module registry (`GuestModule`).
   - Each image's export directory is parsed from guest memory once (name table → funcs index,
     ordinal base + count; forwarded exports are skipped — they point at other DLLs we don't model);
   - `module_set_name`/`guest_module_base` resolve LoadLibraryA names (case-insensitive, `\`/`/`
     normalized, full path or bare file name) to a guest base; `guest_export_lookup(base, name,
     ordinal, &addr)` resolves exports of a loaded image.
   - `recomp/host/main.c` maps ENGINE.exe then the whole `PORT_MODULE_TABLE` before starting the game;
     module IATs resolve through the same magic-import dispatch as the exe's.
4. `recomp/host/kernel32.c`:
   - `LoadLibraryA`/`GetModuleHandleA`: guest module names resolve to the image base (already mapped);
     system DLLs keep the FAKE_MODULE path; unknown → 0 + error 126;
   - `GetProcAddress`: a guest base → `guest_export_lookup` (by name or ordinal) returns the real
     translated address; a FAKE_MODULE → the host handler lookup as before, now **with ordinal
     support** (`"DSOUND.DLL!#11"` style), which is how SoundService.dll's by-ordinal dsound imports
     also resolve at load time.
5. New/extended host handlers (found by surveying every import of all 46 images):
   - `dsound.c`: `IDirectSound8` (IDirectSound + VerifyCertification) via `DSOUND.DLL!#11`
     (DirectSoundCreate8), `DirectSoundEnumerateA` via `DSOUND.DLL!#2` (one "Primary Sound Driver"
     device);
   - `dinput.c`: `DINPUT8.DLL!DirectInput8Create` with a full 12-method `IDirectInput8A`
     (PC_CONTROLS.dll enters here);
   - `misc.c`: new `shell_imports` table — `COMCTL32.DLL!InitCommonControlsEx`,
     `COMDLG32.DLL!GetOpenFileNameA` (returns cancelled), `SHELL32.DLL!SHBrowseForFolderA` /
     `SHGetPathFromIDListA` (cancelled), `OLE32.DLL!CoInitialize`/`CoUninitialize` (S_OK) /
     `CoCreateInstance` (REGDB_E_CLASSNOTREG — XINTERFACE.dll wants DirectShow for AVI playback;
     there is no DirectShow, so videos are skipped, same fallback as the DDRAW E_FAIL stub).

## Per-module analysis (optional, improves naming/switches)

```
re/analyze_module.sh MODULES/DX8RENDER.dll     # → recomp/data/functions.MODULES_DX8RENDER.json
```
Same passes as `re/analyze.sh` (assert names, RTTI, ExportFunctions.java) but in its own Ghidra
project (`re/ghidra_modules/<tag>/`), so it can run while the exe analysis is open. The tag comes from
`node tools/configure.mjs --tag-for MODULES/DX8RENDER.dll`. Not run yet for any module: without a
functions file the translator falls back to exports + code scan (see results below). Per-module files
are consumed automatically by the manifest when present.

## Build & run

```
sh recomp/build.sh        # translates the full manifest, builds build/libportrecomp.dylib + build/game
./recomp/build/game game  # first run belongs to the main session
```

## Validation (2026-11-04)

- Translator full manifest run: **46 images, 43,928 functions, 984,706 instructions, 166 C files**;
  ENGINE.exe 2,390 functions at 0x400000 unchanged; modules 371–2,262 functions each at their final
  bases. `functions.json` (exe) present from the Ghidra analysis; no module functions files yet.
- Unsupported instructions: 360 functions of 43,928 contain something unsupported, almost entirely
  **AMD 3DNow!** (pfmul/pfadd/pfsub/pfacc/pfrcp… — Storm 2 ships 3DNow math paths in some modules;
  CPUID reports no 3DNow!, so the exe's dispatchers should avoid them, and a reached one traps with
  its address rather than misbehaving). The rest are noise from the code scan (push/pop in
  data-mistaken-for-code gap entries) and a few `lock dec/inc`, `fnstenv`, `in`.
- Native build output: `build/game`.
- Runtime load path (relocs at final bases, export lookup, LoadLibraryA → guest base) is compiled in
  but **not yet exercised** — the first run of the game is the main session's job.

## Bring-up status (2026-11-05, Session 4)

Working: all 45 modules LoadLibrary → final bases; GetProcAddress("DMAInterface") → guest exports
(45/45); DLL_PROCESS_ATTACH runs CRT init (needs thread_main_init first — TLS handlers use t_self);
core init completes ("initializing complete"); the script compiler parses the whole PROGRAM tree.

Runtime loader fixes landed this session (all verified with small harnesses):
- reloc pass read data directory [2] instead of [5], and read blocks from `file + rel_rva` (breaks
  when .reloc rawptr ≠ RVA, e.g. BallSplash). Now parses dir[5] from mapped guest memory.
- export directory field offsets were off by 4 (IMAGE_EXPORT_DIRECTORY: Name@12, Base@16,
  NumberOfFunctions@20, NumberOfNames@24, tables@28/32/36).
- x86toc: union Ghidra jumptables with recover_table targets (script lexer's 12-way dispatch at
  0x456a44 was incomplete in the Ghidra export → "indirect jump to unknown target").

Current frontier: script compile fails at the first native binding — battle_interface\utils.c:245
"function DeleteOneSailHole(args:0) doesnt accept 5 arguments" (engine writes game/error.log). Per
the open-source storm-engine compiler.cpp: `native` decls create the FuncTab entry with args:0; the
module binds args + IMPORTED segment via core.SetScriptFunction, and the call-site arg check is
SKIPPED for IMPORTED-segment functions. In our run SetScriptFunction (ENGINE.exe 0x4105aa) is never
called (PORT_TRACE_CALL shows 0 hits), so the entry stays args:0 in the default segment → error.
"Loaded 0" in system.log appears to be an Akella logging bug (the counter is never incremented).
Next: guest-trace the decl parser over utils.c:4 (why the param loop records nothing) and compare
with locations.c natives; check whether the 2003 binary's SetScriptFunction is reached via a
different entry (the engine may dispatch it through the core vtable before our trace point).

## Untested / risks

- Module `.reloc` application: verified in code, not yet observed at runtime (every module is
  relocated since all prefer 0x10000000).
- 3DNow! functions inside modules would trap if dispatched (see above).
- `GetModuleFileNameA` on a module handle still returns the exe path (game hasn't been observed
  asking for it).
- Module-internal vtables/call tables rely on the pointer-entry scan finding function starts; without
  Ghidra functions files there may be missed entries — an indirect call to an unseeded address traps
  with the address, and `re/analyze_module.sh` for that DLL is the fix.
