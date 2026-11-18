# Project status

Last reviewed: 18 November 2026. This is a short record of the current build's
coverage and remaining issues, not a guarantee that every game situation works.

## Current build

- `main` uses progressive loading for solo play. Uncached resources require a
  working connection to the server; cached resources are reused. The previous
  full-install build is preserved on `classic-full-install`. Multiplayer
  requires full-install mode (`?lazy=0`).
- Russian and English solo play, browser-local saves, backup and restoration
  are supported. The streaming and full-install stores are separate, with an
  explicit copy option. The game does not allow saving during a sea battle.
- A clean checkout restored the game data and English layer from the ready
  distribution, passed full-hash verification and rebuilt the WebAssembly
  outputs. The project was checked with Node.js 18.20.8 on macOS ARM64; the
  Emscripten SDK used its own Node.js runtime. See the
  [build guide](BUILD_FROM_CLONE.md) for dependencies and commands.
- Short local browser checks covered starting the game, saves and loading,
  locations including Oxbay, Douwesen and Redmond, sailing, boarding, and
  recovery from an injected resource-download failure. Automated checks also
  cover storage integrity and save preservation. These checks are not a full
  playthrough or proof of all game states.

## Open issues and limits

- **Mouse and menus:** with the pointer free, menus use its position in the
  rendered picture at either aspect setting. The previous relative conversion
  made cursor speed depend on window height and could leave the game cursor
  offset after opening a menu. Camera input stays relative. The host now
  preserves motion that arrives during a game cursor recenter, and the browser
  releases held input on fullscreen and focus transitions. Automated Brave
  opened Settings and Save from the pause menu and exercised the F2 interface.
  In windowed gameplay, a scene click now captures the pointer so the camera
  can turn past the window edge; menus release it. Chromium and Brave checks
  covered capture, Escape, menu release and selecting Settings by its window
  coordinates. Physical mouse testing is still needed.
- **Loading:** in isolated macOS Retina windows, Brave and Vivaldi submitted
  about 120 game frames/s at the start menu and 11–12 frames/s while loading the
  opening cabin. The browser animation callback kept running at about 120 Hz.
  The browser now shows its progress cursor on loading frames while the pointer
  is free. The save list keeps ordinary presentation pacing, and an actual
  restore still enables the faster loading path. A fresh save and restore passed
  in Chromium.
- **Fullscreen Escape:** Chromium passed the single- and double-Escape test
  with Keyboard Lock active. The API was absent in Brave 1.98.63 with its
  default protections. In a private window of Vivaldi 8.3.4191.44 on macOS, the
  API was exposed, but all three fullscreen lock requests failed with
  `InvalidStateError`. The browser exited fullscreen on the first Escape.
  The grave/tilde key opened and closed the game menu while staying in
  fullscreen, including closing it with the pointer captured. Keyboard Lock
  in a regular Vivaldi profile still needs verification. A minimal page also
  reproduced the rejection after the fullscreen transition and on a fresh
  click. In Vivaldi's own fullscreen window, Escape opened and closed the
  game menu. The game lets Control+Command+F reach the browser so it can
  enter and leave that mode.
- **Input coverage:** the macOS measurements used scripted input. Physical
  mouse latency and the reported intermittent left-click problem across a
  fight, a conversation and a door transition remain open.
- **Guest heap exhaustion:** the original cause was not established. A change
  improved a synthetic fragmentation case, but does not prove the error is
  eliminated. The runtime can emit a diagnostic snapshot if it recurs.
- **Rendering:** fixes for character shadows and the world-map date were
  visually checked in limited scenes. They do not establish correctness on
  every surface, graphics driver or unsupported texture-transform mode.
- **Mobile:** the touch controls were tested in desktop browser emulation;
  a real iPhone and Safari have not been tested.
- The supplied game data lacks two voice files reported by the engine log;
  their audible effect has not been assessed.
- **Hosting:** the R2 Worker and a disposable local R2 emulator received
  the complete distribution (458 files, about 1.40 GB). An isolated browser
  installed the English layer, loaded the cabin on demand, created a save and
  loaded it after restart. Another run recovered after four injected HTTP 503
  responses. A second Worker serves the game through Cloudflare Static Assets
  on the Free plan without R2. On the public site, ranges were compared with
  the original files and an isolated Chromium session loaded the opening cabin,
  created a save and loaded it after restarting. A separate Russian-language
  browser run recovered from four injected HTTP 503 responses. Static range
  responses read the full asset inside the Worker, so heavy concurrent use
  remains untested.
  Extended play and listening to audio were not performed.

Publication readiness still needs physical mouse and target-browser checks.
See the [hosting guide](hosting.md) for deployment requirements and the
[architecture](../PORT_SPECIFICATION.md) for implementation and storage boundaries.
