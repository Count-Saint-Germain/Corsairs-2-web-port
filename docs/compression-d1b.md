> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

# D1b: brotli through a custom WebAssembly decoder

Status: estimation was performed on real data (streaming, without writing a dist); the decision to implement it was made and implemented compatibly with older versions, but it is **disabled by default**: `make_dist.py` still builds the D1/D3 gzip layout, and brotli is enabled with `--codec br`. Enabling it by default awaits live acceptance (section 8). A real dist build, bucket upload, and installation over a real network were NOT performed; the game was not launched; the browser (ephemeral headless Chromium 158) was started only for synthetic pages. Everything regarding Firefox, Safari, weak devices, and real hosts is an estimate and checklist.

## 1. Summary

| | gzip-6 (D1+D3, current) | brotli q11, 4 MiB window (`--codec br`) | brotli q9 |
|---|---|---|---|
| Network transfer (9824 files, `port.json` rules applied) | 1223.1 MB (52.0% of 2351 MB) | **942.6 MB (40.1%)** | 1059.3 MB (45.1%) |
| Savings versus gzip | — | **−280.4 MB (−22.9% traffic; −11.9 percentage points of original)** | −163.8 MB (−13.4%; −7.0 percentage points) |
| Objects: separate files + packs | 353 + 57 | ≈266 + 56 (`--estimate` estimate) | |
| Installation requests | 410 | ≈322 | |
| Decoder size | — (browser) | 170,029-byte `.wasm` (43 KB in brotli) + 9 KB JS | |
| Dist build time | ≈10 s estimate / minutes to write | ≈11 min to estimate and ≈2× that to write (q11 ≈0.5–0.7 MB/s per core; machine busy with other tasks) | ≈10× faster |
| Page CPU to decompress entire game | ≈5.8 s (DecompressionStream) | ≈12.9 s (WebAssembly) | ≈9.3 s |
| SHA-256 in JS (still required) | ≈9.4 s | ≈9.4 s | ≈9.4 s |

The D1 estimate (“≈−7 percentage points versus gzip”) referred to brotli q9 and was confirmed (−7.0 points), but **quality 11 delivers the main gain**: q11 yields twice q9's gain (−11.9 points), not only for `.gm` but also `.tx` (−113 MB), `.wav` (−14 MB), and `.col`. A 16 MiB window instead of 4 MiB would save only another 10 MB (1.1%) at four times the decoder memory, so the window is fixed at 4 MiB (22 bits).

**Decision: implement** (22.9% saving against an ≈5% threshold; CPU +7 s for the whole installation on a desktop core). Format: brotli, not zstd (section 3); decoder: official Google brotli 1.2.1 (MIT), built into `web/vendor/brotli/k2br.wasm`.

## 2. Measurements

### 2.1. Sizes: real D1+D3 layout, streaming

`tests/bench_codecs.mjs sizes` (Node 26 `zlib`: raw deflate -6 as in `gamefiles.gzip_pass`, brotli, zstd; all game files, nothing written) and `make_dist.py --estimate --codec br --br-quality 11` (Python, `brotli` command; same rules: files <1 KiB, `.ogg`, etc. are not tried) gave the same result: **942.6 MB (Node) and 942.7 MB (make_dist)**, versus gzip at 1223.1 MB as in D1. The per-file selection rule is the same for all columns: a codec is used only if it is ≥5% smaller than the best alternative (gzip or the original file) and ≥5% smaller than the file.

| type | files | original MB | gzip-6 MB | brotli q9, window 22: MB (saving) | brotli q11, window 22: MB (saving) | brotli q11, window 24 | zstd 19: MB (saving) |
|---|---:|---:|---:|---|---|---|---|
| `.tx` | 1794 | 1105.5 | 618.4 | 572.3 (−46.0) | **505.0 (−113.3)** | 504.8 | 536.4 (−81.9) |
| `.gm` | 2074 | 705.5 | 366.6 | 255.8 (−110.8) | **228.7 (−137.9)** | 218.9 | 241.6 (−124.9) |
| `.col` | 3387 | 156.0 | 36.6 | 34.5 (−2.1) | **28.6 (−8.0)** | 28.6 | 31.8 (−4.9) |
| `.wav` | 970 | 119.4 | 106.8 | 106.4 (−0.4) | **93.3 (−13.6)** | 93.3 | 106.5 (−0.3) |
| `.an` | 143 | 112.1 | 22.0 | 19.5 (−2.5) | 18.7 (−3.4) | 18.7 | 20.8 (−1.2) |
| `.ptc` | 136 | 45.4 | 7.6 | 6.3 (−1.3) | 5.4 (−2.2) | 5.4 | 5.9 (−1.7) |
| `.ogg` (not tried) | 37 | 49.1 | 49.1 | 49.1 | 49.1 | 49.1 | 49.1 |
| other | ≈3200 | ≈58 | ≈16 | ≈14 | ≈12 | | ≈13 |
| **total** | **9824** | **2351.0** | **1223.1** | **1059.3 (−163.8; 13.4%)** | **942.6 (−280.4; 22.9%)** | 932.7 (−290.4) | 1007.3 (−215.8; 17.6%) |
| files as brotli/zstd | | | | 4538 | 7746 | 7746 | 5311 |

Brotli q11 outperforms zstd 19 by 65 MB (zstd without long-window mode); q9 makes sense only for build speed; gzip and q9 barely compress `.wav`, whereas q11 finds noticeable redundancy in it. Window 24 saves 1% at the cost of a 16 MiB ring buffer per concurrent stream, so it was not chosen.

### 2.2. Decompression speed (WebAssembly decoder), MB/s of decompressed bytes

Node 26 (same V8 as Chromium), a sample of ≈40 MB of each type from real files, 64 KiB chunks, best of three; **the machine was busy with other tasks (load average 8–35), variation ±30%**. `tests/bench_codecs.mjs decode`:

| type | gzip `DecompressionStream` | native gzip | brotli wasm q9 | **brotli wasm q11** | native Node brotli q11 | page JS SHA-256 | native SHA-256 |
|---|---:|---:|---:|---:|---:|---:|---:|
| `.tx` | 367 | 575 | 227 | **158** | 210 | 255 | 3053 |
| `.gm` | 404 | 668 | 249 | **183** | 246 | 254 | 3029 |
| `.col` | 476 | 926 | 330 | **301** | 442 | 246 | 2910 |
| `.an` | 771 | 1826 | 621 | **453** | 596 | 247 | 3006 |
| `.wav` | 326 | 507 | 206 | **127** | 170 | 253 | 3002 |

The WebAssembly decoder runs at 75–100% of native Node brotli speed. In real Chromium 158 (`tests/test_brotli_browser.mjs`, 24 MB of synthetic data compressed to gzip 56%, br9 49%, br11 39%): `DecompressionStream('gzip')` 482, brotli wasm q9 186 and q11 210, page SHA-256 236, WebCrypto 2500; the complete fetch + decompression + JS SHA-256 + OPFS write pipeline: gzip 113 MB/s, brotli 94 MB/s. The slowest 64 KiB chunk written to the decoder (main-thread blocking) took 1.1–15.8 ms in two runs.

Bottleneck comparison: **JS SHA-256 (≈250 MB/s) remains the slowest pipeline step for both gzip and brotli**. Estimated CPU time for full installation (2351 MB, weighted by type): SHA ≈9.4 s; gzip decompression ≈5.8 s, brotli q11 ≈12.9 s. Thus the computational installation “ceiling” rises from ≈15 to ≈22 s (+7 s, +47%) on a desktop core, while network transfer falls by 280 MB. Installation takes approximately max(network, CPU): the break-even point is ≈320 Mbit/s; below that brotli wins overall, above it loses ≈7 s.

D3 network model (packs, 6 streams), `make_dist.py --estimate --codec br`, network seconds only: 20 Mbit/s 50 ms — 377 s (gzip 489 s); 100 Mbit/s 50 ms — 75 s (98 s); 300 Mbit/s 100 ms — 26 s (33 s).

### 2.3. CPU and battery impact (estimated, not measured on devices)

+7 s on one desktop-class core for the entire installation, ≈3–5× on a weak phone: +20–35 s on one core versus 280 MB of radio traffic that need not be received (at 20 Mbit/s this is ≈112 s of radio operation). Installation happens once; the decoder is not used during gameplay. Decoding takes place on the main thread, like SHA-256 and writing (one call takes ≈1–16 ms while the page shows progress); moving it to a Worker is possible but not needed for the responsiveness threshold. Memory: WebAssembly heaps ≈5–7 MiB per stream (4 MiB window ring buffer + tables + 320 KiB buffers), six parallel streams <64 MiB (hard heap limit 96 MiB); after retries, errors, and cancellations the heap does not grow (test).

## 3. Options and decision

| | brotli (selected) | zstd | npm packages |
|---|---|---|---|
| Savings versus gzip on this data | −280 MB (q11, 4 MiB window) | −216 MB (19) | as for the selected format |
| Decoder | Google brotli 1.2.1, MIT, sources downloaded, archive SHA-256 checked against the Homebrew formula; 170 KB wasm | zstd BSD/GPLv2 (dual license), ≈100–150 KB | explicit license and provenance verification required; not used |
| Decompression speed | ≈130–450 MB/s in wasm (measured) | usually 2–3× faster than brotli (not measured: no zstd decoder in project) | — |
| Dist build tools | `brotli` module or `brotli` command | `zstandard`/`zstd` | — |
| Conclusion | 65 MB smaller, one decoder | faster, but SHA-256 still limits to 250 MB/s | — |

Brotli was selected for greater savings, an MIT license without qualifications, and a mature, repeatedly fuzzed decoder implementation. Zstd wins only on decompression speed, which is not the bottleneck (JS SHA-256 is slower than both). Prebuilt npm packages and CDN scripts were not used: the decoder was built from source and is in the repository (`web/vendor/brotli`); the page fetches only its own files from the network.

## 4. Decoder: provenance, license, build

| | |
|---|---|
| Source | https://github.com/google/brotli, tag `v1.2.1` (`historical diagnostic materials (removed)`), archive SHA-256 `98d35d11a78dc453aebb7d10c3748f3f73ff78c8267c0dc697b8631f67bf7e8f` matches the Homebrew formula pin (independent check) |
| License | **MIT**, “Copyright (c) 2009, 2010, 2013-2016 by the Brotli Authors”; `web/vendor/brotli/LICENSE` is copied from the archive; the license text must accompany source and build |
| Copied | Decoder only: `c/dec/*`, `c/common/{constants,context,dictionary,dictionary_inc.h,platform,shared_dictionary,static_init.h,transform,version}`, four `c/include/brotli` headers; 31 files, byte-identical to archive (checked with `cmp`) |
| Written | `k2br.c` (wrapper: stream context, chunked input/output, allocator with 96 MiB heap limit, own `memcpy/memmove/memset/memcmp`), `build.sh` |
| Build | `bash web/vendor/brotli/build.sh`: clang and wasm-ld from `third_party/emsdk` (emcc is unnecessary, so `emcc.lock` was not needed), `-O2 -ffreestanding --target=wasm32 -mbulk-memory`, then `wasm-opt -O3`; two successive builds produce identical bytes; `k2br.wasm` matches a rebuild of current sources |
| Result | `k2br.wasm` 170,029 bytes (gzip -9: 77.5 KB; brotli q11: 43.3 KB), SHA-256 `612c079c…d61bd7` (pinned in `brotli-decoder.mjs`, stored in `k2br.wasm.sha256`) |
| Properties | **No imports**, no eval, no network, no libc; exports `k2br_*` and `memory`; requires WebAssembly and bulk-memory (Chrome 75+, Firefox 79+, Safari 15+) |
| Loading | `import()` + `fetch` alongside module, SHA-256 verification, `WebAssembly.instantiate`; ≈20 ms cold, ≈2 ms repeated (Node); file ≈170 KB (always stored in the bucket/on disk, transferred only for `enc: "br"`) |
| `SOURCE.txt` | In `web/vendor/brotli`: provenance, contents, update procedure |

## 5. Format and compatibility

Manifest (`game/manifest.json`): a file entry or an entry in a pack may have `enc: "br"`; everything else follows D1/D3:

```json
{ "path": "RESOURCE/Models/Locations/a.gm", "size": 12183759, "sha256": "…", "enc": "br", "csize": 3100123 }
{ "path": "RESOURCE/Models/Locations/b.gm", "size": 91000, "sha256": "…", "enc": "br", "csize": 20100, "pack": 3, "offset": 1048576 }
```

- Separate file object: `game/<path>.br` (one brotli stream, no `Content-Encoding`). A pack record uses the same stream; records in one pack can have different `enc` values (gzip, br, or none).
- `size`/`sha256` always refer to the decompressed file; manifest `version` is codec-independent (a test compares Python and Node).
- **Per-file selection** (`gamefiles.analyse_files`): gzip is always tried; `--codec br` also tries brotli. Brotli wins only if ≥5% smaller than the best alternative (gzip or the original file) and ≥5% smaller than the file. Files whose `<path>.gz` or `<path>.br` name is occupied by another file are not packed.
- **Old clients and dist**: the new page reads old manifests (without `enc`, with `enc: gzip`, and with packs) unchanged; the decoder is not loaded. An old dist's page rejects `enc: "br"` BEFORE writing (“unsupported encoding …; reload the game page”; this is D1 behavior and is tested). Page and manifest are still published as one dist.
- The page rejects unknown `enc` (such as `zstd`) BEFORE writing; a missing decoder (no WebAssembly, `.wasm` unavailable, or SHA-256 mismatch) is also rejected BEFORE writing (`prepareDecoders` in `syncFromServer`).
- The decoder loads lazily, once, only if the manifest contains `br`.
- `serve.py --compress --codec br [--br-quality N]` (with `--pack`, according to packer rules), `upload.py` (manifest object check: `.br`), `worker.js` (`game/*.br`: no `Content-Encoding`, `no-transform`), and `verify_dist.py` (below) understand `br`.

## 6. Security

- **Output limit** = manifest entry `size`: the decoder errors and aborts the stream as soon as more is decompressed, before passing excess bytes to the consumer; one call outputs ≤256 KiB. A “bomb” of 256 MiB of zeroes (405 bytes) is stopped within milliseconds; the consumer receives ≤ the limit (test), with at most two chunks in storage. The previous post-decompression size and SHA-256 check is retained as a second line of defense, also catching substituted data that yields a valid stream.
- **Window**: read from the first byte (RFC 7932, 9.1); >4 MiB (22 bits) and “large window” are rejected BEFORE decompression; the wasm heap is limited to 96 MiB and returns NULL.
- End of stream is mandatory (a truncated stream is an error); bytes after the end are an error whether in the same chunk, a separate chunk, or small chunks.
- Decoder integrity: `.wasm` SHA-256 is checked against the pinned hash; substitution is rejected before the first write (Chromium and Node test). `verify_dist` verifies that the `.wasm` in the dist is the same file and `vendor/` contains nothing extra.
- Wasm has no imports (nothing can call JS), no eval/`new Function`, and no network from the decoder; one context per stream, no shared state across streams (determinism: a pure function of input). Context leaks are excluded on success, error, cancellation (`cancel`), and, as a fallback, `FinalizationRegistry` (test: 65 cycles, occupied heap blocks stay constant).
- If a host adds `Content-Encoding: br` to `.br`, `fetch` has already decompressed it and the page detects this, as with gzip. Size and SHA checks remain, but traffic will not decrease.

## 7. Changes (in the working tree, uncommitted)

| File | Change |
|---|---|
| `web/vendor/brotli/*` (new) | Decoder sources (31 unchanged files), `LICENSE`, `SOURCE.txt`, `k2br.c`, `build.sh`, `k2br.wasm`, `k2br.wasm.sha256` |
| `web/brotli-decoder.mjs` (new) | `loadBrotliDecoder` (SHA pin), brotli `TransformStream` with output and window limits and end-of-stream check; `brotliWindowBits` |
| `web/game-transfer.mjs` | `ENCODINGS.br`, `prepareDecoders` (lazy loading), `decompressor`; `downloadPackedFile` / `downloadPackRun` select the decompression stream by `enc` |
| `web/save-protection.mjs` | `KNOWN_ENCODINGS` += `br` |
| `web/port.js` | Installation only: `await prepareDecoders(files)` before writing, error text |
| `web/gamefiles.py` | `brotli_compress/brotli_unpack/brotli_pass/codec_pass/unpack_record/unpack_check`, `packable_set(files, encs)`, `analyse_files(..., codec, quality)`, `read_record(..., limit)`, `write_pack(..., quality)`; gzip remains default as before |
| `web/make_dist.py` | `--codec gzip\|br` (gzip default), `--br-quality`, `--estimate --codec br` (table columns “as br”, “gzip MB”, “saved”), `write_game_file(..., decided)` (no repeated measurement), decoder in `page_assets` |
| `web/serve.py` | `--codec br`, `--br-quality` |
| `web/cloudflare/{worker.js,upload.py}` | `.br` as opaque bytes; manifest object validation |
| `tests/verify_dist.py` | Read `br` (`brotli` module or command), window ≤4 MiB, output limit, decoder and its SHA in dist, `vendor/` containing only `k2br.wasm`; synthetic dist `packed='br'`/`'pack-br'` |
| `tests/` (new) | `test_brotli_transfer.mjs`, `test_brotli_browser.mjs`, `test_brotli_dist.py`, `bench_codecs.mjs`; changes: `pack_fixture.mjs` (`buildGame(..., {br})`), `test_game_transfer.mjs`, `test_install_packs.mjs`, `test_compression_dist.py` (`br` is now known: the “unknown” encoding in tests is `zstd`), `test_worker_packed.mjs`, `test_dist_http_smoke.mjs` (br variants), `test_install_requests_browser.mjs` (scenario G with real `port.js`) |
| `docs/hosting.md` | “Brotli instead of gzip (D1b)” section |

## 8. Tests and their limits

Node: `test_brotli_transfer.mjs` (11 groups: SHA and `.wasm` structure, window, 228 combinations of data × quality × window × chunking down to 1 byte against native Node brotli, 13 MB with multiple metablocks, truncation at 60 points, 80 corrupted bits, extra bytes, bomb, windows 23/24, leaks and six parallel streams, lazy loading and rejection before writing, separate files with nine types of corruption, mixed gzip/br/raw packs with Range resume, corruption, truncation, and false `size`); `test_brotli_browser.mjs` (ephemeral Chromium 158, real OPFS: br installation in flat and packed layouts, lazy loading with no `.wasm` requests without br, substituted `.wasm`, corruption/truncation/garbage/bomb in br object and pack record, speed); `test_install_requests_browser.mjs` (real `port.js`, scenario G); `test_worker_packed.mjs`. Python (`-I`): `test_brotli_dist.py` (19 tests: formats, selection rule, `make_dist --codec br` in flat and packed layouts, `verify_dist` with 15 types of corruption, `--estimate`, `serve.py`, `upload.py`; pass with either the `brotli` command or `brotli` module in a separate venv); existing suites have no regressions. Differential check on real files: ≈670 MB (q5/q9/q11, 2370 files) through the wasm decoder — zero SHA-256 mismatches.

Synthetic only (not proven): Firefox, Safari (macOS/iOS), Edge; weak devices; real host (Cloudflare Worker/R2: `Content-Encoding` on `.br`, cache, Range); installation time over a real network; battery use; real dist (full q11 build, `verify_dist --full-hash`); speed on data different from the samples (≈±30% due to machine load).

## 9. Risks

- Building a q11 dist is slow (≈20 minutes on 10 cores when the machine is not busy with other work): compression is computed twice (measurement + write). Mitigation: `--br-quality 9` (10× faster, half the savings) or a stream cache (not implemented).
- Browsers without bulk-memory (Safari <15) cannot run `.wasm`; `prepareDecoders` refuses before writing with a clear error. This does not apply to gzip dist.
- CPU +7 s on a desktop core, ≈20–35 s on a weak phone (estimate); above ≈320 Mbit/s, brotli installation is a few seconds slower than gzip.
- Main thread: decoder step up to 16 ms per 64 KiB chunk; if needed, the decoder can be moved to a Worker without changing the format.
- Intermediate CDNs may add `Content-Encoding: br` to `.br` (traffic will not decrease, data remains correct) or ignore `no-transform` (response changes, caught by size and SHA checks).
- Build-machine encoder dependency: `brotli` module or `brotli` command. Without one, `--codec br` and `verify_dist` for br entries refuse with a clear message rather than silently falling back.
- Decoder updates are a deliberate procedure (`SOURCE.txt`): new archive, rebuild, new SHA in `brotli-decoder.mjs`.

## 10. Live checks (before enabling by default)

1. Build a dist: `node korsary2-next/recomp/web/make_dist.mjs --game korsary2-next/game --out dist-br --codec br` (≈20 min, ≈1.0 GB free required: 942.6 MB + build + video), then `node korsary2-next/recomp/tests/verify_dist.mjs --dist dist-br --full-hash --source-game korsary2-next/game` and `node korsary2-next/recomp/tests/test_dist_http_smoke.mjs dist-br`; compare final size with the estimate (942.7 MB) and `version` with gzip-dist (it should match).
2. Test origin, clean profile: `curl -sI https://HOST/game/RESOURCE/INI/TEXTS/language.ini.br`: no `Content-Encoding`, `Content-Length` = `csize`, `no-transform`; `curl -sI https://HOST/vendor/brotli/k2br.wasm`: `application/wasm`.
3. Clean installation in Chrome/Edge, Firefox, and Safari (macOS and iOS): traffic ≈0.94 GB instead of 1.22 GB (DevTools Network), time at 50 and 200 Mbit/s, progress bar, game starts, preflight “verified”; `window.installStats`.
4. Weak device (phone/laptop on battery): total installation time, core utilization, heat; compare gzip-dist and br-dist on the same connection; move the decoder to a Worker if needed.
5. Resume: interrupt the network during installation, restore it, and reload (completed files skipped, interrupted `.br` downloaded again, final SHA matches); update an old installed dist with the new one.
6. Old page (cached/old dist) + new manifest: expect “unsupported encoding” rejection without a single write.
7. If all is well, change the default `--codec` value to `br` in `make_dist.py` (one line) and redeploy the Worker (`worker.js` changed: `.br`).
