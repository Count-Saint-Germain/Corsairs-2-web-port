> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

> **Status as of 2026-11-12:** the ddraw/video sections (§3, “credits”) have been superseded by the `CAviPlayer` hook and video bridge; the rest (module loading, `engine.dll`/`data1.dat`, registry) has been confirmed. See `historical log (removed)`, §3.7.

# Storm 2 bring-up notes (Sea Dogs II / Pirates of the Caribbean v1.03, 1C repack)

Static analysis of `game/ENGINE.exe` (1,212,479 B, unprotected PE32, version info: "Akella ENGINE" 1.0.0.1, ProductName "Akella ENGINE") and `game/MODULES/*.dll` (45 DLLs). Companion file: `import-gaps.md`.

## 1. How the engine loads MODULES/*.dll

Mechanism: **directory scan driven by `engine.ini`**, not a hardcoded module list. Evidence (strings from `ENGINE.exe`, source paths are original `C:\PROJECTS\DRIVE_V2\ENGINE\SOURCES\...`):

- `Core.cpp` strings: `no 'engine.ini' file`, `modules path`, `No 'modules path' key in engine.ini`, `program_directory`, `controls`, `fail to create program`, `fail to run program`, `initializing complete`.
- `modules_table.cpp` strings: `Loading modules...`, `Scanning current directory`, `Scanning %s`, `*.dll`, `Module [ %s ] skipped`, `Loaded %d`, `Class with name '%s' already declared` (s_classtab.cpp).
- `engine.ini` line 1: `modules path = modules\` — the scanned directory.
- The scan is `FindFirstFileA/FindNextFileA` with pattern `*.dll` over `modules path`; load order is therefore **directory enumeration order (alphabetical for this layout)**: Animation.dll, animals.dll, artifact.dll, BallSplash.dll, battle_interface.dll, blade.dll, Blot.dll, COLLIDE.dll, CameraDialog.dll, DIALOG.dll, DUMMY.dll, DUMMY2.dll, DX8RENDER.dll, GEOMETRY.dll, ISLAND.dll, Lighter.dll, Location.dll, MAST.dll, MODEL.dll, PARTICLES.dll, PCS_CONTROLS.dll, PC_CONTROLS.dll, PEOPLES_ON_SHIP.dll, rigging.dll, SCRIPT_LIBRIARY.dll, sea.dll, SeaCreatures.dll, sea_ai.dll, SEA_CAMERAS.dll, SEA_OPERATOR.dll, seafoam.dll, shadow.dll, ship.dll, sink_effect.dll, SOUND.dll, SoundService.dll, telescope.dll, Teleport.dll, touch.dll, Tornado.dll, WEATHER.dll, WaterRings.dll, WorldMap.dll, XINTERFACE.dll.
- Each DLL is `LoadLibraryA`-ed and resolved via **`GetProcAddress(dll, "DMAInterface")`** (every one of the 45 DLLs exports exactly `DMAInterface`; XINTERFACE.dll additionally exports the mangled `?SFLB_DoControl@XINTERFACE@@IAAXXZ`). ENGINE.exe strings confirm: `DMAInterface`, `interface function not found`. On failure the DLL is unloaded with `Module [ %s ] skipped`.
- `DMAInterface` returns an object that registers engine classes into the class table (`s_classtab.cpp`); `CTP_MODULE_INTERFACE` / `CTP_MODULE_INTAPI` / `CTP_MODULE_CREATE_CLASS` are class-table interface keys in ENGINE.exe, not export names. The `offclass` ini key (engine.ini line 19, commented: `;offclass = soundservice`) disables a class.
- Scripts never reference DLLs. `PROGRAM/*.c` create entities by class name: `CreateEntity(&Particles,"particles")`, `CreateEntity(&Sound,"Sound")`, etc. (43 distinct lowercase class names found: sea, sea_ai, weather, particles, blast, fader, sail, rope, flag, rain, sky, sunglow, lightning, island, locator, lighter, telescope, tornado, touch, seafoam, sharks, animals, sea_operator, sea_cameras, sinkeffect, ballsplash, aiballs, aifort, aiseagoods, people_on_ship, ship_camera, deck_camera, free_camera, ilogandactions, iboardingstatus, scriptscreen, widescreen, vant, modelr, sealocatorshow, env, sound, characteranimationkipper).
- Other engine.ini keys consumed: `program_directory = PROGRAM`, `run = seadogs.c` (Core.cpp compiles/runs the script program from `PROGRAM\seadogs.c`), `controls = pcs_controls` (selects the controls class; both PCS_CONTROLS.dll and PC_CONTROLS.dll are on disk — PC_CONTROLS.dll imports `dinput8.dll!DirectInput8Create`, PCS_CONTROLS.dll does not and uses plain Win32 input). `MODULES\Techniques\*.sha` are D3DX shader-assembler sources (`DX8RENDER.dll` string: `D3DX8 Shader Assembler Version 0.91`).
- Port implication: implement `LoadLibraryA/GetProcAddress/FreeLibrary/FindFirstFileA/FindNextFileA` (already implemented in template) and route module DLLs to recompiled code objects that export a `DMAInterface` symbol.

## 2. engine.dll (StarForce shell) — needed?

**Not referenced anywhere.** Grep for `engine.dll` across strings of ENGINE.exe, all 45 MODULES DLLs, `engine.ini`, all `PROGRAM/**`, and `RESOURCE/INI/*.ini`: **zero hits**. ENGINE.exe itself carries no StarForce signatures (survey: no protection detected; sections/imports clean). `engine.dll` (3,926,840 B) is the DRM shell used to wrap the original protected ENGINE.exe; the game bootstraps purely from ENGINE.exe + `modules path`. The game can boot without it — **exclude engine.dll from the port**.

## 3. ddraw usage in XINTERFACE.dll

Import table (parsed PE imports; full list: KERNEL32.dll 85, USER32.dll 3, ole32.dll 3, DDRAW.dll 1):

- `DDRAW.dll`: **`DirectDrawCreate` only** — no surfaces, no blit, no EnumDisplayModes imports.
- `ole32.dll`: `CoInitialize`, `CoUninitialize`, `CoCreateInstance`.
- `USER32.dll`: `ShowCursor`, `SetCursorPos`, `GetWindowRect`.

Verdict: **real but narrow runtime usage — AVI video playback**, not rendering. XINTERFACE.dll strings (aviplayer.cpp context):

```
CAviPlayer, iVideo, midVideo, videoTexture, videoName, videoFile, videoToBack, VIDEORECTANGLE
Video Error!!! Can`t create interface AMMultiMediaStream
Video Error!!! Can`t initialize interface AMMultiMediaStream
Video Error!!! Can`t query interface DirectDrawMediaStream
Video Error!!! Can`t SetCooperativeLevel for DirectDraw
Video Error!!! Can`t create DirectDraw interface
Video Error!!! Can`t create surface for video imaging
Video Error!!! Can`t create texture for this video
resource\videos
```

So the flow is DirectShow `AMMultiMediaStream` → `DirectDrawMediaStream` → DirectDraw object/surface, rendered into a D3D texture (`videoTexture`) for in-engine video (intro/menu videos from `RESOURCE\VIDEOS`). Port it as an HTML5 `<video>`/canvas-backed AVI source with the `IDirectDraw*` calls stubbed to return success; no DirectDraw emulation layer needed. `resource\videos` path string confirms lookup dir.

## 4. Registry predictions (virtual registry seeds)

Findings from scanning ENGINE.exe + all 45 MODULES + Config.exe:

- ENGINE.exe imports `RegOpenKeyExA`, `RegQueryValueExA`, `RegCreateKeyA`, `RegSetValueExA`, `RegCloseKey` (all 5 missing in template), but **contains no plaintext registry key/value strings** — keys are built at runtime or the calls are dead/debug leftovers. The game's real settings persistence is the plain-text file `options` (volumes, cameramode, arcademode, per-mode key bindings — read/written by the script UI `PROGRAM/INTERFACE/option_sl.c`, `mainmenu.c` and by SoundService.dll, which has `volume` strings).
- The only game-side registry strings anywhere are the statically linked D3DX8 runtime keys in `DX8RENDER.dll`, `sea.dll`, `Animation.dll`, `WEATHER.dll`: `SOFTWARE\Microsoft\Direct3D` with value names `DisableMMX`, `DisableD3DXPSGP`, `DisablePSGP` (read-only tuning probes; absent values = defaults). Sea.dll/Animation.dll/WEATHER.dll import `RegOpenKeyA/RegQueryValueExA/RegCloseKey` for this.
- `Config.exe` is only the settings launcher (version info "Pirates of the Caribbean setup"); `decode.exe` references `SOFTWARE\Classes\CLSID\{D27CDB6E-...}\InprocServer32` (Flash) — both are repack/distribution extras, not needed to boot.

Virtual-registry recommendation: provide `HKLM\SOFTWARE\Microsoft\Direct3D` (empty), make all RegOpen/Query return "not found" gracefully, and optionally seed `HKCU\Software\Akella\Pirates of the Caribbean` defensively (no evidence the runtime reads it — do not depend on it).

## 5. data1.dat

- Size 6,540,372 B; dated 2003-10-09, same day as `engine.dll` (StarForce build date). Header starts `87 44 c0 06 71 f2 da 98 ...`; entropy **8.000 bits/byte over the whole file** — fully encrypted, no recognizable header, no plaintext strings (only noise).
- Referenced nowhere: grep for `data1` in ENGINE.exe strings, all MODULES DLL strings, `engine.ini`, `PROGRAM/**`, `RESOURCE/**`, and the *.txt/*.bat files returns nothing (the `.data1` hits in four DLLs are PE section names, not file references).
- Conclusion: StarForce DRM support data tied to the protected original. **Exclude from the port.** Also exclude: `engine.dll`, `decode.exe`, `depack.exe`, `7z.dll`, `setup-1.bin` (repacker artifacts, 2009–2011 dates).

## 6. Expected boot sequence (for native bring-up)

1. **Process start**: CRT init (kernel32 heap/TL Studio imports), `GetStartupInfoA`, `GetModuleFileNameA`, `GetCommandLineA`. `GetVersion`/`GetVersionExA` called by every module DLL (46/46 images import them).
2. **Window**: ENGINE.exe `gdi_display.cpp` — `RegisterClassExA` with class/title string `Storm Engine 2` (4 occurrences in strings), `CreateWindowExA`, `LoadIconA`/`LoadCursorA` (resources `IDI_ICON1`, `NULL_CURSOR`), `ShowWindow`, `ClipCursor`, menu bar only in debug builds (`DEBUGMENU`, `View`, `Source Viewer`, `Attribute Viewer`, `Options`, `Break on Error`).
3. **engine.ini read** (file_service.cpp ini service): `modules path = modules\`, `program_directory = PROGRAM`, `run = seadogs.c`, `controls = pcs_controls`, plus renderer keys. Missing file ⇒ fatal strings `no 'engine.ini' file` / `No 'modules path' key in engine.ini`.
4. **Module scan**: `Loading modules...` → `Scanning modules\` with `*.dll` → `LoadLibraryA` + `GetProcAddress("DMAInterface")` per DLL, in alphabetical order; classes registered into the class table (`Loaded %d`).
5. **Script program**: compile `PROGRAM\seadogs.c` (the script compiler uses `compile.log` / `error.log`, `[script]` ini section: `debuginfo=1`, `codefiles=0`, `runtimelog=0`); `fail to create program` / `fail to run program` on error. `break_on_error` read from ini file named `options` for the debugger.
6. **Entity creation from scripts**: first entities per PROGRAM init (`CreateEntity(&Particles,"particles")`, `CreateEntity(&Sound,"Sound")`, sea, weather, interface screens...). DX8RENDER.dll creates the D3D8 device at this point: strings `Direct3DCreate8 error : InitDevice::Direct3DCreate8`, `InitDevice::CreateDevice`, `InitDevice::SetViewport`, ini keys `screen_x`, `screen_y`, `screen_bpp`, `full_screen` (engine.ini: 800x600, windowed, `D3DFMT_X8R8G8B8`), `lockable_back_buffer`, `texture_degradation`.
7. **Per-frame**: message pump (`PeekMessageA/GetMessageA/DispatchMessageA`), timer via kernel32 (no winmm import anywhere — expect `QueryPerformanceCounter`/`GetTickCount`), controls via PCS_CONTROLS (Win32) or PC_CONTROLS (`DirectInput8Create`), audio via SoundService.dll (`dsound.dll` by ordinal only: **ord#11 = DirectSoundCreate8, ord#2 = DirectSoundEnumerateA** per the standard dsound export table, cross-checked against [dsoal's mingw.def](https://github.com/kcat/dsoal/blob/master/mingw.def) — implement both in the dsound shim), text/language via XINTERFACE reading `resource\ini\TEXTS\language.ini` (`defaultLanguage = russian`, `[DIRECTORY] English=english / Russian=russian`, strings from `resource\ini\TEXTS\%s\%s`).
8. **Registry**: only D3DX8's `Software\Microsoft\Direct3D` probes (read-only, tolerate absence). Anything else: return key-not-found; the game must not require registry writes to boot.
9. **Log/exit**: `compile.log`, `error.log`, runtime log gated by `tracefilesoff = 0`; memory profile to `memory.mp` (`mem_profile` ini key); shutdown strings `Unloading`, `One or more exception(s) occuried on Run`, `Memory leak detected`, `System exit and cleanup`, `FATAL EXCEPTION : System halted`.

Host-layer gaps that matter most for first boot (from import-gaps.md): `GetEnvironmentVariableA`, `GetVersion` (all 46 images), `DisableThreadLibraryCalls` (6 DLLs), `user32!wsprintfA`, `GetWindowRect`, `ClipCursor`, `GetDC/ReleaseDC` (DX8RENDER), `kernel32!GetFileAttributesA`, `GlobalMemoryStatus` (DX8RENDER), and advapi32 Reg\* stubs. Everything else on the gap list is debugger-UI-only.
