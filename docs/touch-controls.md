# Touch controls

In single-player mode the touch panel appears after the game starts on a device
with a primary touch pointer (`pointer: coarse`). To check it with a mouse or
screen-size emulation, explicitly enable it with `?touch=1`; `?touch=0` disables
it. The panel is not enabled in multiplayer. On a normal PC without the parameter,
keyboard and mouse behaviour is unchanged.

The “Берег” (Land), “Море и карта” (Sea and map), “Меню” (Menu), and “Ещё”
(More) tabs contain buttons for the original keys and mouse buttons; F1 opens
the game menu, which contains save and load. The quick potion is in “Берег”;
less common camera, time, and dialogue keys are in “Ещё”. During a video,
pressing a game touch button skips the video without passing that same press to
the game underneath. Touching the panel can also resume an audio context paused
by the browser; audibility has not been checked. The area beneath the buttons
works as a relative trackpad for the camera and cursor; a short stationary tap
corresponds to the left mouse button. The panel can be hidden and reopened.
Hints correspond to the supplied profile and may differ if the player has
remapped the controls in the game.

If the panel does not fit on screen, swipe up or down in the “Прокрутка ↕”
(Scroll ↕) area at its top. It remains visible while scrolling. Gestures on game
buttons are intended for control and do not scroll the panel.

Simultaneous presses of different buttons are supported; held buttons are
released when a touch is cancelled, the tab is hidden, focus is lost, the layout
changes, or the panel is hidden. Touch and physical input should not release one
another. Checks: `node korsary2-next/recomp/tests/test_touch_controls.mjs` and
`node korsary2-next/recomp/tests/test_browser_input_blur.mjs`, plus the browser
test `node korsary2-next/recomp/tests/test_touch_video_audio_browser.mjs` on its
own local test server. Screen-size and touch emulation in a desktop browser
does not establish behaviour on a real iPhone: Safari, a particular device,
system gestures, and control usability need a separate device test.

On 15.11.2026, the browser test
`node korsary2-next/recomp/tests/test_touch_mobile_scroll_browser.mjs` checked
the isolated real panel module and styles in Chromium emulation with touch
events at 320×568 and 568×320: scrolling to the end and back, absence of game
input from scrolling, and a subsequent “Пробел” (Space) press. At 393×852 and
852×393 across four layouts, it checked that the header does not overlap buttons
in the initial position and that the trackpad is reachable; while scrolling,
the header may cover elements moving upwards, which become accessible again when
scrolling back. The game engine is replaced by an input-recording bridge in this
test; it is not a game launch or an iPhone/Safari test.
