// The counter records completed reads, not total loading work or time remaining.
// Require sustained activity so browsing save thumbnails does not flash a badge.
export function createSaveReadIndicatorState() {
  let last = null, busy = 0, quiet = 0, visible = false;
  return (count) => {
    count = count >>> 0;
    if (last === null) { last = count; return visible; }
    const delta = (count - last) >>> 0;
    last = count;
    if (delta >= 32) { busy++; quiet = 0; }
    else { busy = 0; quiet++; }
    if (!visible && busy >= 2) visible = true;
    if (visible && quiet >= 2) visible = false;
    return visible;
  };
}

export function installSaveReadIndicator(element, readCount, interval = setInterval) {
  const update = createSaveReadIndicatorState();
  update(readCount());
  return interval(() => element.classList.toggle('hidden', !update(readCount())), 1000);
}
