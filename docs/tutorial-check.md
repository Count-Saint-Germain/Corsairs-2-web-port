> Historical technical document: intermediate diagnostic runs were deleted. Their screenshots and example commands are unavailable; the current instructions are in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md).

> **Status as of 2026-11-12:** This document is out of date: the land tutorial, combat and equipment were completed on 2026-11-11. The server and tab at port 18723 mentioned below have been closed. See §3.8 of the historical log (deleted).

# Tutorial cabin: check on November 6, 2026

## Main build check after the seek fix

On a separate in-app-browser origin at port 18725, without serving the source
folder, the main build loaded its own sealed slot: the cabin, F2 screen and
Malcolm's dialogue about missing equipment were visible, and the character
moved to another part of the cabin. This confirms a limited smoke test and input
after loading, not acquiring the pistol or telescope, opening the relevant
chest, or combat. The test slot was not overwritten; launch details were in the
historical log (deleted).

After subsequent buffer checks on main, build v4 again loaded its own slot at
port 18725 and opened F2; movement and camera changes worked visually. The item
search was not completed: the pistol, telescope, chest and combat remained
unverified. The slot was not overwritten; the tab and server were closed.

The check was performed only in the Codex in-app browser on a separate origin
`http://127.0.0.1:18723`, using a diagnostic build whose historical materials
were deleted. The game was installed without user SAVE files, using a sealed
Tutorial Deck slot created for the test. This was not the user's tab and did
not test persistence after restart.

- A new game and the tutorial dialogue visually reached Malcolm's request to
  collect belongings. The second pair of comparisons loaded a save created on
  this origin; the character and Malcolm were visible in the cabin.
- `F2 → Up → Space` opened the Items screen, which was empty before collecting
  anything. This disproved the assumption that the screen could not be opened
  at all, but did not explain the earlier failed check in another tab.
- A sabre was visible on the chest beside the tall wardrobe. Approaching it
  displayed a hand icon; `Space` displayed an item-added message. The sabre
  appeared in the item list with its description; selecting Take added a check
  mark and changed the button to Remove. The sabre was also visible on the character.
- The wardrobe interface with the pistol and telescope was not reached.
  Attempts to get around the wardrobe and inspect a second chest did not confirm
  their contents. The pistol, telescope, tutorial combat, hits and scenario
  continuation were not verified.
- The experimental tab was left for handoff. Progress after loading, including
  the collected and equipped sabre, was only in memory: no attempt was made to
  save over the sealed A/B slot. Measurement server PID 27526 was left running;
  its state and the tab needed to be checked before continuing. Closing the tab
  would lose this progress. Origin 8011 was used separately; its tab and server
  were stopped, and its OPFS was not cleared.

The measurements from both load comparisons, build commands, worker-lease and
concurrency limitations were in the historical diagnostic materials (deleted).

### Stopped at the user's request, 2026-11-06

Work and browser checks were stopped. At the last check, server 18723 was still
running; the diagnostic tab had previously held unsaved progress with the sabre
equipped. Automatic review rejected another look at the tab after the request to
stop, so its state at that time was unconfirmed. The chest and Malcolm combat
scenarios remained for continuation; site data was not cleared. See the earlier
historical log entries (deleted).
