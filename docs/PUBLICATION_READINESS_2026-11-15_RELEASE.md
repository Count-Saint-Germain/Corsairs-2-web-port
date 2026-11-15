# Project status

Last reviewed: 17 November 2026. This is a short record of the current build's
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

- **Mouse input in Brave and Vivaldi:** a player reports slow menu cursor movement
  in windowed mode, while fullscreen feels responsive, and previously reported
  intermittent left-click failures. Windowed clicks no longer request Pointer
  Lock, so Escape is available to the game; fullscreen may still capture the
  pointer. An isolated automated game run exercised menu clicking and Escape,
  but did not measure latency with a physical mouse. The reported slowdown and
  intermittent left-click issue need confirmation in the player's browsers.
- **Fullscreen Escape:** double Escape requires a granted Keyboard Lock. An
  isolated Brave run did not expose that API with its default protections; in
  such a browser the first Escape remains under browser control. Chromium with
  the API granted passed the single- and double-Escape browser test.
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
- Hosting tests, extended play and listening to audio were outside the agreed
  scope. The ready build has not been verified on a public deployment.

Because the reported mouse issue remains unresolved, publication readiness is
not yet established. See the [hosting guide](hosting.md) for deployment
requirements and the [architecture](../PORT_SPECIFICATION.md) for implementation
and storage boundaries.
