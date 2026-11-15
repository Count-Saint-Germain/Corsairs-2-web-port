// CPython's integer-seeded random.Random, for reproducing existing trial inputs.
export class PythonRandom {
  constructor(seed) {
    let n = BigInt(seed); if (n < 0n) n = -n;
    const key = []; do { key.push(Number(n & 0xffffffffn)); n >>= 32n; } while (n);
    this.mt = new Uint32Array(624); this.mt[0] = 19650218;
    for (let i = 1; i < 624; i++) this.mt[i] = (Math.imul(1812433253, this.mt[i-1] ^ (this.mt[i-1] >>> 30)) + i) >>> 0;
    let i = 1, j = 0;
    for (let k = Math.max(624, key.length); k; k--) {
      this.mt[i] = ((this.mt[i] ^ Math.imul(this.mt[i-1] ^ (this.mt[i-1] >>> 30), 1664525)) + key[j] + j) >>> 0;
      if (++i >= 624) { this.mt[0] = this.mt[623]; i = 1; }
      if (++j >= key.length) j = 0;
    }
    for (let k = 623; k; k--) {
      this.mt[i] = ((this.mt[i] ^ Math.imul(this.mt[i-1] ^ (this.mt[i-1] >>> 30), 1566083941)) - i) >>> 0;
      if (++i >= 624) { this.mt[0] = this.mt[623]; i = 1; }
    }
    this.mt[0] = 0x80000000; this.index = 624;
  }
  next() {
    if (this.index >= 624) {
      for (let i = 0; i < 624; i++) {
        const y = (this.mt[i] & 0x80000000) | (this.mt[(i+1)%624] & 0x7fffffff);
        this.mt[i] = (this.mt[(i+397)%624] ^ (y >>> 1) ^ ((y & 1) ? 0x9908b0df : 0)) >>> 0;
      }
      this.index = 0;
    }
    let y = this.mt[this.index++]; y ^= y >>> 11; y ^= (y << 7) & 0x9d2c5680; y ^= (y << 15) & 0xefc60000; y ^= y >>> 18;
    return y >>> 0;
  }
  bits(k) { if (!Number.isInteger(k) || k < 0 || k > 32) throw new RangeError('bits must be 0..32'); return k ? this.next() >>> (32-k) : 0; }
  below(n) { if (!Number.isSafeInteger(n) || n <= 0 || n > 0xffffffff) throw new RangeError('invalid range'); const k = Math.floor(Math.log2(n)) + 1; let r; do { r = this.bits(k); } while (r >= n); return r; }
  range(a, b) { if (b === undefined) { b = a; a = 0; } return a + this.below(b-a); }
  random() { return ((this.next() >>> 5) * 67108864 + (this.next() >>> 6)) / 9007199254740992; }
  bytes(n) { const b = Buffer.alloc(n); let i = 0; while (i + 4 <= n) { b.writeUInt32LE(this.next(), i); i += 4; } if (i < n) { const x = this.bits((n-i)*8); for (let j = 0; i < n; i++, j++) b[i] = x >>> (j*8); } return b; }
}
