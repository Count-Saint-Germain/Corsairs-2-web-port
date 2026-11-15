# Browser port

A port of a 2000s Windows PC game to the browser, made with the `port-pc-game-to-browser` skill.
The game is statically recompiled from its x86 executable to C, compiled natively (for debugging) and
to WebAssembly (to play), with the Windows, Direct3D 8, DirectSound and DirectInput calls it makes
reimplemented in `recomp/host/`.

**Play:** run `./play.sh`, then open the printed localhost address in Codex's
built-in browser. The script does not open a browser itself. Add
`?sea_fallback=1` for the experimental simplified sea.

**Local saves:** saves live in the browser's private storage for the exact
address and port used to play. On the launcher, before starting the game,
choose **Download saves** to download a local `korsary2-saves.zip`.
A running game owns the saves: it holds the save Web Lock for its whole page
lifetime (`recomp/web/save-owner.mjs`), so backup, restore, export and game
updates in other tabs of the same browser fail fast with a saves-in-use message instead of racing its writes. A second game start
in any tab is refused the same way while one is running; a game start that
fails after the runtime came up keeps the locks held and that page must be
reloaded. This protects cooperating tabs of this page version only — tabs from
older builds, tools outside the Web Locks API, browser teardown, BFCache
restore and worker behaviour are not proven. Clearing the site's browser data
also removes its saves; keep a backup. The export has been tested with
synthetic saves, not every possible game save.

The repository includes a ready distribution and the source needed to continue development. See the [root README](../README.md) and [build instructions](../docs/BUILD_FROM_CLONE.md) for restoring game data and installing the toolchain.

| Path | What |
|---|---|
| `port.json` | This game's settings (name, executable, registry values, files, controller, online) |
| `game/` | Your game files |
| `re/` | Ghidra analysis: `re/analyze.sh` exports `recomp/data/functions.json` |
| `recomp/translator/x86toc.mjs` | x86 → C translator |
| `recomp/runtime/` | CPU state, memory, x87/SSE helpers, interpreter for run-time code |
| `recomp/host/` | Windows API layer, Direct3D 8 → WebGPU, audio, input, determinism, netplay |
| `recomp/web/` | The page, browser storage, local server, packaging, Cloudflare hosting |
| `tools/` | Configure step, executable survey and asset tools |

Build: `recomp/build.sh` (native, macOS: `recomp/build/game game`), then
`sh recomp/build_web_local.sh` (browser, with local caches).
Useful run options are listed at the top of `recomp/host/main.c` and in the skill's reference guides.
