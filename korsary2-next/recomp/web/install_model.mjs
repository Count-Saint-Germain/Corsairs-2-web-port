/** Fluid model of concurrent file requests; times are seconds, bandwidth is bytes/s.
 * Latency and payload bandwidth are modelled; CPU, slow start and TLS are not. */
class MinHeap {
  constructor() { this.items = []; }
  get length() { return this.items.length; }
  peek() { return this.items[0]; }
  push(entry) {
    const a = this.items; let i = a.length; a.push(entry);
    while (i) {
      const p = (i - 1) >> 1;
      if (a[p][0] < entry[0] || (a[p][0] === entry[0] && a[p][1] <= entry[1])) break;
      a[i] = a[p]; i = p;
    }
    a[i] = entry;
  }
  pop() {
    const a = this.items, first = a[0], last = a.pop();
    if (a.length) {
      let i = 0;
      while (i * 2 + 1 < a.length) {
        let j = i * 2 + 1;
        if (j + 1 < a.length && (a[j + 1][0] < a[j][0] || (a[j + 1][0] === a[j][0] && a[j + 1][1] < a[j][1]))) j++;
        if (last[0] < a[j][0] || (last[0] === a[j][0] && last[1] <= a[j][1])) break;
        a[i] = a[j]; i = j;
      }
      a[i] = last;
    }
    return first;
  }
}

export function simulate(sizes, rtt, bandwidth, slots = 1, k = 1.0) {
  if (!Array.isArray(sizes) || sizes.some(n => !Number.isFinite(n) || n < 0) ||
      !Number.isFinite(rtt) || rtt < 0 || !Number.isFinite(k) || k < 0 ||
      !Number.isFinite(bandwidth) || bandwidth <= 0 || !Number.isInteger(slots) || slots < 1) {
    throw new RangeError('sizes, RTT, bandwidth, slots and round trips must be valid non-negative values');
  }
  let t = 0, work = 0, next = 0, active = 0;
  const waiting = new MinHeap(), flowing = new MinHeap();
  function dispatch() {
    while (next < sizes.length && active < slots) {
      waiting.push([t + k * rtt, next++]); active++;
    }
  }
  dispatch();
  while (waiting.length || flowing.length) {
    const tWait = waiting.length ? waiting.peek()[0] : Infinity;
    const tFlow = flowing.length ? t + (flowing.peek()[0] - work) * flowing.length / bandwidth : Infinity;
    if (tFlow <= tWait) {
      work = flowing.peek()[0]; t = tFlow; flowing.pop(); active--;
    } else {
      if (flowing.length) work += (tWait - t) * bandwidth / flowing.length;
      t = tWait;
      const [, i] = waiting.pop();
      if (sizes[i] > 0) flowing.push([work + sizes[i], i]);
      else active--;
    }
    dispatch();
  }
  return t;
}

function fold(value) {
  return value.toLowerCase().replaceAll('ß', 'ss').replaceAll('ς', 'σ');
}
function comparePaths(a, b) {
  const x = fold(a[0]), y = fold(b[0]);
  return x < y ? -1 : x > y ? 1 : a[0] < b[0] ? -1 : a[0] > b[0] ? 1 : 0;
}

/** Wire sizes in dispatch order; packs first, then unpaired large files/options. */
export function requestSizes(rows, pack = null) {
  const sorted = [...rows].sort(comparePaths);
  if (pack === null) return sorted.map(r => r[2]);
  const [maxFile, target] = pack, loose = [], packs = [];
  let current = 0;
  for (const [name, , n] of sorted) {
    if (name.toLowerCase() === 'options' || n > maxFile) { loose.push(n); continue; }
    if (current && current + n > target) { packs.push(current); current = 0; }
    current += n;
  }
  if (current) packs.push(current);
  return packs.concat(loose);
}

export const SIZE_BUCKETS = Object.freeze([1 << 10, 4 << 10, 16 << 10, 64 << 10, 256 << 10, 1 << 20, 4 << 20, 16 << 20]);
export function histogram(sizes) {
  const edges = [0, ...SIZE_BUCKETS, Infinity];
  const name = n => n >= 1 << 20 ? `${n / (1 << 20)} MiB` : `${n / (1 << 10)} KiB`;
  return edges.slice(0, -1).map((lo, i) => {
    const hi = edges[i + 1], selected = sizes.filter(n => n >= lo && n < hi);
    return [`${name(lo)}..${hi === Infinity ? 'inf' : `<${name(hi)}`}`, selected.length, selected.reduce((a, b) => a + b, 0)];
  });
}
