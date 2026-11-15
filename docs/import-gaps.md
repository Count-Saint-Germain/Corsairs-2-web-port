> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

> **Status as of 2026-11-12:** all 65 imports listed here have been implemented in the host layer (some as stubs); this document is historical. See `historical log (removed)`, §3.4.

# Import gaps: ENGINE.exe + 45 MODULES/*.dll vs template host layer

Generated 2026-11-04 with `survey.py --json` (template: retro-port `port-pc-game-to-browser` host layer).
Scope: `game/ENGINE.exe` + all 45 `game/MODULES/*.dll` (46 PE32 x86 images, none packed/protected).
`game/engine.dll` (StarForce shell) excluded. `game/data1.dat`, `Config.exe`, `decode.exe`, `depack.exe`, `7z.dll` not surveyed.

**Executive summary.** 65 unique Windows functions are imported but not yet implemented in the template host layer (172 image×function import slots total across the 46 images).
The top 10 (ClipCursor, CompareFileTime, DisableThreadLibraryCalls, GetDC, GetEnvironmentVariableA, GetFileAttributesA, GetVersion, GetWindowRect, ReleaseDC, wsprintfA) cover 117 slots = 68% of all missing imports;
most of the long tail is 1–3 importers deep. Almost all ENGINE.exe-only gaps (menus, clipboard, GDI text/paths, shell dialogs, GetOpenFileNameA) belong to the built-in script-debugger UI (`s_debug.cpp`, "SDebug - %s", "Source View", "Select Dialog Folder") and are not needed for gameplay; they can be stubbed.
Only 9 system DLLs are involved: kernel32, user32, gdi32, ole32, advapi32, shell32, comctl32, comdlg32, dinput8 — plus ddraw.dll imports in XINTERFACE.dll (see bringup-notes.md, task 3).
Direct3D 8 itself is imported only by DX8RENDER.dll and is already template-supported.

Per-image totals (imports / implemented / missing):

| image | imports | implemented | missing |
|---|---|---|---|
| Animation.dll | 60 | 58 | 2 |
| BallSplash.dll | 55 | 53 | 2 |
| Blot.dll | 60 | 58 | 2 |
| COLLIDE.dll | 42 | 39 | 3 |
| CameraDialog.dll | 42 | 39 | 3 |
| DIALOG.dll | 58 | 55 | 3 |
| DUMMY.dll | 55 | 53 | 2 |
| DUMMY2.dll | 55 | 53 | 2 |
| DX8RENDER.dll | 86 | 78 | 8 |
| ENGINE.exe | 160 | 108 | 52 |
| GEOMETRY.dll | 52 | 49 | 3 |
| ISLAND.dll | 61 | 59 | 2 |
| Lighter.dll | 68 | 65 | 3 |
| Location.dll | 63 | 61 | 2 |
| MAST.dll | 61 | 58 | 3 |
| MODEL.dll | 47 | 44 | 3 |
| PARTICLES.dll | 56 | 54 | 2 |
| PCS_CONTROLS.dll | 59 | 56 | 3 |
| PC_CONTROLS.dll | 58 | 53 | 5 |
| PEOPLES_ON_SHIP.dll | 61 | 59 | 2 |
| SCRIPT_LIBRIARY.dll | 51 | 49 | 2 |
| SEA_CAMERAS.dll | 56 | 54 | 2 |
| SEA_OPERATOR.dll | 78 | 75 | 3 |
| SOUND.dll | 55 | 53 | 2 |
| SeaCreatures.dll | 57 | 55 | 2 |
| SoundService.dll | 67 | 65 | 2 |
| Teleport.dll | 61 | 59 | 2 |
| Tornado.dll | 57 | 55 | 2 |
| WEATHER.dll | 65 | 63 | 2 |
| WaterRings.dll | 56 | 54 | 2 |
| WorldMap.dll | 62 | 60 | 2 |
| XINTERFACE.dll | 92 | 83 | 9 |
| animals.dll | 56 | 54 | 2 |
| artifact.dll | 56 | 54 | 2 |
| battle_interface.dll | 61 | 59 | 2 |
| blade.dll | 56 | 54 | 2 |
| locator.dll | 60 | 57 | 3 |
| rigging.dll | 62 | 59 | 3 |
| sea.dll | 65 | 63 | 2 |
| sea_ai.dll | 62 | 60 | 2 |
| seafoam.dll | 56 | 54 | 2 |
| shadow.dll | 42 | 39 | 3 |
| ship.dll | 47 | 43 | 4 |
| sink_effect.dll | 56 | 54 | 2 |
| telescope.dll | 55 | 53 | 2 |
| touch.dll | 55 | 53 | 2 |

## Gaps grouped by exporting DLL

### user32.dll

| function | importers | notable importers |
|---|---|---|
| GetWindowRect | 4 | ENGINE.exe, PCS_CONTROLS.dll, PC_CONTROLS.dll, XINTERFACE.dll |
| wsprintfA | 4 | DIALOG.dll, DX8RENDER.dll, ENGINE.exe, locator.dll |
| ClipCursor | 2 | ENGINE.exe, PC_CONTROLS.dll |
| GetDC | 2 | DX8RENDER.dll, ENGINE.exe |
| ReleaseDC | 2 | DX8RENDER.dll, ENGINE.exe |
| CheckMenuItem | 1 | ENGINE.exe |
| CloseClipboard | 1 | ENGINE.exe |
| DestroyMenu | 1 | ENGINE.exe |
| EmptyClipboard | 1 | ENGINE.exe |
| FillRect | 1 | ENGINE.exe |
| GetMenu | 1 | ENGINE.exe |
| GetMenuItemCount | 1 | ENGINE.exe |
| GetMenuItemID | 1 | ENGINE.exe |
| GetMenuItemInfoA | 1 | ENGINE.exe |
| GetSubMenu | 1 | ENGINE.exe |
| GetTabbedTextExtentA | 1 | ENGINE.exe |
| InsertMenuItemA | 1 | ENGINE.exe |
| InvalidateRect | 1 | ENGINE.exe |
| LoadBitmapA | 1 | ENGINE.exe |
| OffsetRect | 1 | ENGINE.exe |
| OpenClipboard | 1 | ENGINE.exe |
| SetClipboardData | 1 | ENGINE.exe |
| SetMenuItemInfoA | 1 | ENGINE.exe |
| SetScrollInfo | 1 | ENGINE.exe |
| TabbedTextOutA | 1 | ENGINE.exe |

### kernel32.dll

| function | importers | notable importers |
|---|---|---|
| GetEnvironmentVariableA | 46 | all 45 MODULES dlls + ENGINE.exe |
| GetVersion | 46 | all 45 MODULES dlls + ENGINE.exe |
| DisableThreadLibraryCalls | 6 | COLLIDE.dll, CameraDialog.dll, GEOMETRY.dll, MODEL.dll, shadow.dll, ship.dll |
| CompareFileTime | 3 | MAST.dll, XINTERFACE.dll, rigging.dll |
| GetFileAttributesA | 2 | DX8RENDER.dll, Lighter.dll |
| Beep | 1 | ship.dll |
| CopyFileA | 1 | ENGINE.exe |
| GetDiskFreeSpaceExA | 1 | ENGINE.exe |
| GetLocalTime | 1 | XINTERFACE.dll |
| GlobalLock | 1 | ENGINE.exe |
| GlobalMemoryStatus | 1 | DX8RENDER.dll |
| GlobalUnlock | 1 | ENGINE.exe |
| HeapValidate | 1 | SEA_OPERATOR.dll |
| SetErrorMode | 1 | XINTERFACE.dll |
| SetFileAttributesA | 1 | ENGINE.exe |
| lstrcatA | 1 | ENGINE.exe |
| lstrlenA | 1 | ENGINE.exe |

### gdi32.dll

| function | importers | notable importers |
|---|---|---|
| BeginPath | 1 | ENGINE.exe |
| CreateSolidBrush | 1 | ENGINE.exe |
| DPtoLP | 1 | ENGINE.exe |
| EndPath | 1 | ENGINE.exe |
| GetMapMode | 1 | ENGINE.exe |
| GetObjectA | 1 | ENGINE.exe |
| GetRgnBox | 1 | ENGINE.exe |
| LineTo | 1 | ENGINE.exe |
| MoveToEx | 1 | ENGINE.exe |
| PathToRegion | 1 | ENGINE.exe |
| SetMapMode | 1 | ENGINE.exe |
| SetPixel | 1 | DX8RENDER.dll |
| TextOutA | 1 | ENGINE.exe |

### ole32.dll

| function | importers | notable importers |
|---|---|---|
| CoCreateInstance | 1 | XINTERFACE.dll |
| CoInitialize | 1 | XINTERFACE.dll |
| CoUninitialize | 1 | XINTERFACE.dll |

### advapi32.dll

| function | importers | notable importers |
|---|---|---|
| RegCreateKeyA | 1 | ENGINE.exe |
| RegSetValueExA | 1 | ENGINE.exe |

### shell32.dll

| function | importers | notable importers |
|---|---|---|
| SHBrowseForFolderA | 1 | ENGINE.exe |
| SHGetPathFromIDListA | 1 | ENGINE.exe |

### comctl32.dll

| function | importers | notable importers |
|---|---|---|
| InitCommonControlsEx | 1 | ENGINE.exe |

### comdlg32.dll

| function | importers | notable importers |
|---|---|---|
| GetOpenFileNameA | 1 | ENGINE.exe |

### dinput8.dll

| function | importers | notable importers |
|---|---|---|
| DirectInput8Create | 1 | PC_CONTROLS.dll |
