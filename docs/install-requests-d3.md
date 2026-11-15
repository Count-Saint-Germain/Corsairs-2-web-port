> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

# D3: 9824 requests per installation: parallel downloads, transfer packs, lazy-loading research

Status: implemented and synthetically tested (Node, Python, real OPFS and real `port.js` in ephemeral
headless Chromium 158 against a loopback server with artificial latency). Real dist build, bucket upload and
installation over a real network were NOT performed; the game was not launched. Everything about real hosts, Firefox, Safari and
real networks is a model, estimates and the “Live checks” checklist (section 9). Section 10 (D3-lazy) is research only:
nothing was added to the product.

## 1. Summary

| | Before D3 (D1) | After D3 |
|---|---|---|
| Requests per installation | 9824 (one per file) | **410** (57 packs of ~8 MiB + 353 large files) |
| Concurrent requests | 1 (strictly sequential) | up to 6 (`?installConcurrency=N`, 1..16) |
| Network transfer | ≈1223 MB (gzip) | same ≈1223 MB |
| OPFS space | 2351 MB | 2351 MB (OPFS stores decompressed data, not the pack) |
| Model, 100 Mbit/s, RTT 100 ms | ≈1080 s | **≈98 s** (bandwidth-limited) |
| Bench: real `port.js`, Chromium + OPFS, 2002 files, 80 ms per request | 172 s | **2.6 s** (×66; 6 streams without packs — 28.7 s) |
| Manifest `version` | `sha1(path:size:sha256)` | same (packing does not change it) |

Selected: **(A) bounded concurrency (6 streams)** and **(B) transfer packs** for files whose object is ≤ 1 MiB
(96% of files by count, 38% of network bytes). Both measures work together: concurrency provides the main improvement on any host
(×5–6 on the bench); packs remove remaining overhead where streams are limited (HTTP/1.1, 6 connections) or RTT is high, and reduce
Worker/R2 request count by ≈24×.

## 2. Measurements

Measurements were streaming/metadata only: `make_dist.py --estimate` reads the game (9824 files, `port.json` rules
applied), calculates sizes and gzip lengths (level 6) without writing to disk. Dist was not built (≈19 GB disk).
Command (extended in D3: histogram, request counts with/without packs, time model):

```
node korsary2-next/recomp/web/make_dist.mjs --game korsary2-next/game --estimate
```

### 2.1. Histogram of manifest file sizes

By length of the object actually on the server (compressed if published as `.gz`; `options` included):

| object | files | share of files | MB | share of bytes |
|---|---:|---:|---:|---:|
| < 1 KiB | 2963 | 30,2 % | 1,3 | 0,1 % |
| 1–4 KiB | 1602 | 16,3 % | 3,3 | 0,3 % |
| 4–16 KiB | 1288 | 13,1 % | 11,3 | 0,9 % |
| 16–64 KiB | 1745 | 17,8 % | 61,4 | 5,0 % |
| 64–256 KiB | 1533 | 15,6 % | 210,8 | 17,2 % |
| 256 KiB – 1 MiB | 341 | 3,5 % | 173,8 | 14,2 % |
| 1–4 MiB | 326 | 3,3 % | 627,0 | 51,3 % |
| 4–16 MiB | 26 | 0,3 % | 134,1 | 11,0 % |
| ≥ 16 MiB | 0 | | | |
| **total** | **9824** | | **1223,1** | |

By uncompressed size (what is written to OPFS): <4 KiB — 3387 files (34.5%, 4.9 MB), <64 KiB — 6467 (65.8%, 76.7 MB),
<1 MiB — 9323 (94.9%, 789 MB), 1 MiB or larger — 501 files (5.1%, 1562 MB = 66%). Zero size — 2 files, <1 KiB — 1714.
By type: `.col` 3387 files (2651 <64 KiB), `.gm` 2074 (1662 <64 KiB), `.tx` 1794 (651 <64 KiB), `.wav` 970,
`.c` 502, etc.

Conclusion: **77% of files (7598) are less than 64 KiB on the network and account for 6.3% of bytes**; 9472 files (96%)
are 1 MiB or smaller and account for 462 MB (38%). For these files, request cost (RTT, headers, `createWritable`) exceeds data cost. 353 files larger than
1 MiB — 62% of bytes — remain separate objects: for these, request time is less than transfer time on channels up to
~100 Mbit/s, and parallel downloads smooth the tail.

### 2.2. How the current page downloads (pre-D3 code)

- `syncManifestFiles` (`save-protection.mjs`) traversed the manifest **strictly sequentially**: file → one `fetch` → `createWritable` →
  chunked write → `close` → next. No concurrency (1 request in flight). Retry: 4 attempts per file with 1.5/3/4.5 s pauses.
- Per file: 1 request, 1 open, 1 write, 1 SHA-256 on the main thread (≈220 MB/s).
- Resume: completed file (matching size and SHA-256) is skipped; interrupted compressed files restart from zero; uncompressed files
  resume via Range.
- HTTP: local `serve.py` uses `BaseHTTPRequestHandler` with `HTTP/1.0`: every request opens a NEW TCP connection (two
  RTT delays per request, not one). Typical HTTP/1.1 static host: keep-alive, but browser holds at most 6
  connections per host. Cloudflare (Worker + R2): HTTP/2 (and HTTP/3) — tens of streams per connection (tested on
  local h2 bench: section 2.4, run D).
- Cloudflare cost: each game file is a separate Worker invocation and R2 read. 9824 invocations per
  install (Cloudflare documentation counts limits and pricing by Worker requests and R2 operations; check current figures,
  they were not measured here); ≈410 with packs.

### 2.3. Network time model (`web/install_model.py`)

Fluid model: `slots` requests in flight; each waits `k·RTT` (request + first byte; k=1 with keep-alive and HTTP/2, 2 for
`serve.py`), then transfers bytes, sharing bandwidth equally with the others. Excludes TCP slow start, TLS, server time and page CPU
(the latter is a separate floor, see 2.4; installation takes approximately the maximum of network and CPU, while in the sequential scheme
CPU does not overlap between files and is additive). Input: actual object sizes (section 2.1). Seconds:

| Mbit/s | RTT, ms | D1, 1 stream | D1, 6 streams | D1, 16 streams | packs, 1 stream | **packs, 6 streams** |
|---:|---:|---:|---:|---:|---:|---:|
| 20 | 50 | 980 | 503 | 491 | 510 | 489 |
| 20 | 200 | 2454 | 629 | 508 | 571 | 489 |
| 50 | 50 | 687 | 220 | 199 | 216 | 196 |
| 100 | 20 | 294 | 106 | 99 | 106 | 98 |
| 100 | 50 | 589 | 139 | 103 | 118 | 98 |
| 100 | 100 | 1080 | 211 | 117 | 139 | 98 |
| 100 | 200 | 2063 | 366 | 164 | 180 | 98 |
| 300 | 50 | 524 | 96 | 46 | 53 | 33 |
| 300 | 100 | 1015 | 175 | 73 | 74 | 33 |
| 300 | 200 | 1997 | 336 | 132 | 115 | 36 |

Packs 1 MiB / 8 MiB (410 requests). Bandwidth floor: 489 s at 20 Mbit/s, 98 s at 100, 33 s at 300.
With `serve.py` (k = 2): 100 Mbit/s, RTT 50 ms — D1 1 stream 1080 s, 6 streams 211 s, packs 98 s.

Findings:

- Purely sequential scheme (pre-D3) on any channel with RTT ≥ 50 ms pays 9824 × RTT: 8 minutes at 50 ms on latency alone.
- **Concurrency 6** removes ≈5/6 of those delays, but at RTT ≥ 100 ms and bandwidth ≥ 100 Mbit/s still performs 1.5–11× worse than the floor
  (HTTP/1.1: cannot get more than 6 streams).
- **Packs** reach the bandwidth floor at any RTT (in the model). Their advantage over concurrency grows with RTT and
  throughput: at 20 Mbit/s — ≤8% (bandwidth already saturated), at 100 Mbit/s and 100 ms — ×2.2, at 300 Mbit/s — ×5.
- On HTTP/2, 16 streams without packs approach packs while RTT ≤ 50 ms; at 200 ms the gap returns to ×1.3–3.6.

Pack parameter choice from the model (6 streams, 100 Mbit/s, RTT 100 ms; request count): no packs 211 s (9824); ≤256 KiB / 8 MiB 98 s (729);
**≤1 MiB / 8 MiB 98 s (410)**; ≤4 MiB / 16 MiB 98 s (95). Time is nearly independent of thresholds above ≈256 KiB, so 1 MiB was chosen:
larger files gain nothing from packing (a MiB request costs less than transfer), while all small files fit in packs.

### 2.4. Bench: real `port.js`, Chromium, OPFS, per-request latency

`tests/test_install_requests_browser.mjs`: `index.html` page with real `port.js` (Play is not pressed, `build/game.js`
is not requested, WebGPU is stubbed to pass `boot()`), ephemeral clean context for each run,
loopback server on a free port: DELAY is added to each response (RTT simulation), and some runs limit shared bandwidth.
Data are synthetic, but file sizes come from the real-game histogram (section 2.1); dist is built by real `make_dist.write_game`.
“Before D3” run = sequential scheme with D1 layout (`installConcurrency=1`, one request and write per file): same
request pattern as old code; D3 page has slightly greater CPU cost during inspection (section 5).

Every run is a clean installation in a new context; `window.installStats.seconds` (from synchronization start to install marker). Chromium 158.0.8127.18,
macOS, 8 cores, loopback. Files follow histogram 2.1 (2 MB file-size cap). Run: `D3_FILES=2000 D3_DELAY=80 node tests/test_install_requests_browser.mjs`
(defaults: 500 files and 50 ms; full run ≈4 minutes because of the sequential scheme).

**Main measurement: 2002 files, 356 MB in OPFS, 124 MB over network, 80 ms per request, HTTP/1.1**

| run | layout and streams | requests | concurrent | time | relative to pre-D3 |
|---|---|---:|---:|---:|---:|
| A1 | D1, 1 stream (**before D3**) | 2002 | 1 | **172,4 s** | 1× |
| A2 | D1, 6 streams | 2002 | 6 | 28,7 s | ×6,0 |
| A3 | packs, 1 stream | 33 | 1 | 6,8 s | ×25 |
| A4 | packs, 6 streams | 33 | 6 | **2,6 s** | **×66** |
| B1 | D1, 1 stream, no latency | 2002 | 1 | 9,1 s (39 MB/s) | |
| B2 | packs, 6 streams, no latency | 33 | 5 | 2,4 s (149 MB/s) | |
| C1 | D1, 6 streams, 100 Mbit/s bandwidth | 2002 | 6 | 30,8 s | |
| C2 | packs, 6 streams, 100 Mbit/s bandwidth | 33 | 6 | 10,0 s (bandwidth floor 9,9 s) | |
| D1 | **HTTP/2**, D1, 6 streams | 2002 | 6 | 28,6 s | |
| D2 | **HTTP/2**, D1, 16 streams | 2002 | 16 | 10,8 s | |
| D3 | **HTTP/2**, packs, 6 streams | 33 | 6 | 2,5 s | |
| E1/E2 | packs: server failure halfway, then resume | 17 of 33 | 4 | 2,4 s; no repeat requests for completed packs | |

Same bench, 502 files, 86 MB OPFS, 29 MB network, 50 ms (defaults): A1 27.8 s (502 requests), A2 4.6 s (×6.1), A3 1.4 s (7 requests, ×20), A4 0.8 s (×36),
B1 1.9 s, B2 0.7 s, C1 5.1 s, C2 2.4 s (floor 2.3 s), HTTP/2: 4.6 s (6 streams) / 1.8 s (16) / 0.7 s (packs, 6); resume after failure — 4 requests, 0.6 s.

Bench findings:

- **Concurrency**: 6 streams — ×6 on HTTP/1.1 and HTTP/2 (no protocol difference at 6 streams); HTTP/2 with 16 streams — another ×2.7 (28.6 → 10.8 s) without packs,
  but 6 streams suffice with packs.
- **Packs**: ×25 single-stream and ×66 with concurrency versus pre-D3; at 100 Mbit/s they saturate bandwidth (10.0 vs 9.9 s), while without packs time remains 30.8 s.
- **Model versus measurement** (network only, k = 1): sequential 160.2 / measured 172.4 s (difference ≈ page CPU, 9 s); 6 streams 26.7 / 28.7; 100 Mbit/s — 29.5 / 30.8 (no packs) and 10.0 / 10.0 (packs).
  The model is reliable for network estimation; page CPU must be added.
- **Page CPU per file (no network latency):** 4.6 ms/file in one stream on D1 layout versus 1.2 ms/file with packs and 6 streams; at the real set of 9824 files that is ≈45 s versus ≈12 s
  of CPU/OPFS alone, excluding network. No-network throughput: 39 MB/s (D1, 1 stream) and 149 MB/s (packs, 6 streams), i.e. CPU floor for the entire game ≈16–20 s.
- **Check after each run**: SHA-256 of every OPFS file (WebCrypto, independent of page code) and sizes match manifest, install marker = `version`, request count = object count
  in layout, concurrent requests do not exceed stream count.
- **Failure and resume**: server starts responding 500 halfway through installation: page refuses with `Update failed (…)`, no marker, OPFS contains no incomplete file; after server recovery
  a retry requests only missing data (17 of 33 requests, 46 of 124 MB), third run makes no requests.
- **Corrupt pack record** (changed byte inside gzip record): installation fails (`The compressed data was not valid…`), corrupt file absent from OPFS, files accepted before it (1736 of 2002) intact.

Bench limitations: loopback without packet loss, TCP slow start or TLS; latency constant and equal for all requests; Node server, not Worker/R2; Chromium is the only browser; HTTP/2 uses a self-signed
loopback certificate; synthetic data (but real size histogram); main-thread CPU impact on weak devices unmeasured.


## 3. Decision and rationale

**Implemented:** (A) inspect the manifest and download missing data in N streams (default 6) with common queue, retries,
progress, quota and cancellation; (B) transfer packs: `make_dist.py` concatenates files whose object is ≤1 MiB into ~8 MiB packs in path order;
the page downloads a pack in one request (or needed range), slices by manifest, decompresses and verifies each file.

**Why this design:**

1. Measurement showed requests determine time (section 2.3). Concurrency is inexpensive, does not change the format and works with
   all previous dists; but HTTP/1.1 has a 6-connection ceiling, and per-file overhead remains on any host (`createWritable`, SHA,
   headers): bench 3.8 ms/file at one stream versus 1.4 ms/file with packs at 6 streams.
2. Packs complement concurrency rather than replace it: on HTTP/2 (Cloudflare), concurrency nearly catches packs at low RTT, but
   packs reduce Worker calls and R2 operations ≈24×, bucket object count and upload ≈24×
   (`upload.py` works one object at a time).
3. Each pack record is a separate gzip stream (or raw file): files stay independent, any can be fetched by Range, compression is the same
   as D1 (same `gzip_pass`), and an interrupted pack retains everything already accepted.
4. Large files (>1 MiB, 62% of bytes) are not packed: pack sizes would be uneven and one request per MiB is already cheap.
5. Pack size 8 MiB: ≈1 s at 64 Mbit/s, enough for TCP to accelerate and little to lose on failure (accepted data remains;
   retry requests Range from the first missing record).

**Considered but not implemented:** one archive for the entire game (no per-file Range resume without custom index, all-or-nothing);
one gzip stream per pack (no intra-pack Range: resync downloads entire pack); HTTP/2 push (obsolete, unavailable);
worker `SyncAccessHandle` instead of `createWritable` (faster writes; separate work, see section 8); raising default concurrency above 6
(helps HTTP/2 without packs, unnecessary with packs; `?installConcurrency=` parameter).

## 4. Pack format

Manifest (`game/manifest.json`), additions to D1; old fields and `size`/`sha256` semantics unchanged:

```json
{ "version": "0e50698af2f0",
  "files": [
    { "path": "RESOURCE/Models/Locations/town/a.gm", "size": 12183, "sha256": "…", "enc": "gzip", "csize": 5400, "pack": 3, "offset": 1048576 },
    { "path": "PROGRAM/s.c", "size": 140, "sha256": "…", "csize": 140, "pack": 3, "offset": 1053976 },
    { "path": "RESOURCE/Models/Locations/jungle/big.gm", "size": 12183759, "sha256": "…", "enc": "gzip", "csize": 5400123 },
    { "path": "options", "size": 400, "sha256": "…" } ],
  "packs": [ { "path": "_k2pack/0003-1a2b3c4d5e6f.pack", "size": 8383211, "files": 412 } ] }
```

- `pack` is an index in top-level `packs`; `offset`, `csize` are the record range inside a pack; `enc` as in D1 (`gzip` or absent
  = record is the raw file, `csize == size`). `size` and `sha256` refer to the DECOMPRESSED file, so `version`, quota,
  `missing-resource-preflight.mjs` and installed-file comparison do not depend on packing (test compares Python and Node).
- A pack is **concatenated records without headers or gaps**: record = gzip file stream (same reproducible D1 stream: fixed
  header, deflate level 6, crc32/isize) or raw file. Records are path-ordered (case-insensitive), so neighboring directories
  and locations are adjacent. The page does not require this order (it slices by manifest), but it helps locality and future
  directory-based lazy loading (section 10).
- `_k2pack/<NNNN>-<digest>.pack` name: `digest` is the first 12 hex sha256 of member (path, size, sha256, enc, csize). An object with this
  name is immutable (content determined by members, streams reproducible), so cache and `upload.py` cannot confuse versions.
  `_k2pack/` is reserved: a game file under that path is a build error.
- Not packed: `options` (mutable player data: page reads it directly), entries larger than `--pack-max-file` (1 MiB
  by object length), entries whose `<path>.gz` is occupied by another file (D1 rules). Such files remain separate objects
  (`<path>` or `<path>.gz` with `enc`/`csize`).
- Build options: `--pack-max-file BYTES` (1M), `--pack-size BYTES` (8M), `--no-pack` (D1 layout). Builder checks: each pack
  is read back, each record must decompress to its size and SHA-256.
- Empty files (2 in the game) are records with `csize: 0` and need no network.
- Real set (checked with `serve.py --pack` against `korsary2-next/game`, game read-only, dist not built): 9824 files = 9471 in 57 packs (0.8–8.4 MB) +
  353 separate objects, 410 requests; manifest version `9fbc83ed9cac` matched the unpacked version; packs 0, 30 and 56 and a range inside pack 5 were checked record by record
  (size and SHA-256 after decompression). Manifest grew from ≈1.8 to 2.07 MB (+286 KB for `pack`/`offset`); page reads it on every start (`no-store`), host may serve it compressed
  (ordinary `application/json`, not a game object).

Before writing anything, the page rejects (`validateManifestPacks`): an index outside `packs`, a range outside the pack, overlapping records
within a pack, a raw record with `csize ≠ size`, `options` in a pack, unknown `enc`, duplicate/invalid pack names, a manifest
with packed records but no `packs` list.

## 5. Client

### 5.1. Concurrency and order (`syncManifestFiles`, `save-protection.mjs`)

Two steps: 1) **inspect** every manifest file (exists, size match, SHA-256 of size matches; completed files are no longer
touched, player `options` preserved) — also in N streams; 2) **download missing**: separate files (`downloadFile`, as
before: compressed from zero, uncompressed Range resume) and pack records. Missing records in one pack are merged into ranges
(`planPackRuns`, gap ≤256 KiB between needed records; complete records between them are read and discarded): clean install —
one request per pack without Range; resync — Range only for needed bytes. Tasks are issued in manifest order (path order: locations
in sequence), with no more than N in the pool. Without `concurrency` (default 1) page works as before.

The first unrecoverable task failure stops issuing new tasks, aborts in-flight requests (their writes are not accepted), and after
all tasks finish throws the first error; install marker is written only after ALL tasks succeed. External `AbortSignal` works the same way.

### 5.2. Retries, resume, progress

- Separate file: 4 attempts, pauses 1.5/3/4.5 s (as before). Pack: a retry counts as “unsuccessful” only if no new record was
  accepted; accepted records remain, next attempt requests Range from first missing record (bench verified). Four consecutive unsuccessful
  attempts cause failure.
- A write failure (out of space, tab closed) leaves no accepted or partial files: each file opens a new writable, commits (`close`)
  only after decompressed size and SHA-256 checks; otherwise `abort` and delete.
- Resume after page closure: first step (inspection) skips installed and correct files; fully complete packs are not
  requested at all; missing data uses Range.
- Progress: sum of uncompressed sizes of accepted files and current tasks; display never decreases (a retried task shows
  its highest reached value), reaches sum of `size`.

### 5.3. Quota (`planStorageNeed`)

Space is still calculated from `size` (OPFS stores uncompressed data), network from record `csize` (`transferBytes`). New: OPFS writes
a replaced file through a temporary copy, and N streams can have copies simultaneously, so `tempBytes` is the sum of the largest replaced
files up to the stream count (one stream — largest, as before). The pack itself is not stored in OPFS. A quota failure in one stream
stops installation under the common rule (section 5.1); accepted files remain intact.

### 5.4. CPU and memory

- Memory: network chunk → SHA-256 → write; entire file is not held. Each stream uses a few chunks and `DecompressionStream` buffers; 6
  streams use a few MB. A pack is not loaded into memory.
- CPU: SHA-256 on the main thread (≈220 MB/s in Chromium) remains the main consumer; concurrency does not accelerate it, but overlaps it with network
  and writes. Bench page overhead per file (without network delay): 3.8 ms at one stream on D1 layout versus 1.4 ms with
  packs and 6 streams (throughput rises from ≈45 to ≈120 MB/s uncompressed). CPU floor for the game: ≈2351 MB / 120 MB/s ≈20 s.
- Inspection on a clean install makes 9824 OPFS “file missing” lookups; not noticeable on the bench (fractions of a second for 500–2000 files).

## 6. Changes

| file | change |
|---|---|
| `web/gamefiles.py` | `plan_packs`, `pack_object_name`, `write_pack`, `read_record`, `verify_pack`, `analyse_files`, `packable_set`; `manifest_for(files, packed, packs, hashes)` (version unchanged) |
| `web/make_dist.py` | packs by default (`--no-pack`, `--pack-max-file`, `--pack-size`), `write_game`, self-check of each pack, `--estimate`: histogram, request count, model |
| `web/install_model.py` (new) | fluid network-time model, histogram |
| `web/game-transfer.mjs` | `downloadPackRun`, `planPackRuns`, `validateManifestPacks`, shared `writeVerified` (also used by D1 `downloadPackedFile`), cancellation via `AbortSignal` |
| `web/save-protection.mjs` | `syncManifestFiles`: inspect + pool (`concurrency`, `packs`, `downloadPackRun`, `signal`), `installConcurrency`, pack-record checks in `validateManifestFiles`, `planStorageNeed(concurrency)` |
| `web/port.js` | `downloadFile(…, ctx)` with cancellation and write `abort` on failure, `downloadPackRange`, `?installConcurrency=N`, `window.installStats` |
| `web/serve.py` | `--pack [--pack-max-file --pack-size]`: on-demand packs, Range, 409/404 if source changes |
| `web/cloudflare/worker.js` | `game/_k2pack/*.pack`: no `Content-Encoding`, `no-transform`, Range |
| `web/cloudflare/upload.py` | manifest-object existence check accounts for packs |
| `tests/verify_dist.py` | packs: sizes, dense layout, every record (decompressed size, SHA-256), no extra objects, names; synthetic dist in packed layout |
| `docs/hosting.md` | “Transfer packs and parallel downloads (D3)” section, Range, resync |

## 7. Compatibility

- **Old manifests/dists** (without `pack`/`enc`/`packs`) and D1 manifests: new page reads as before (Node and Chromium tests);
  `concurrency` 1 reproduces previous request order, a higher value simply downloads files in parallel.
- **Old page + packed manifest**: does not work (requests `<path>`, receives 404, installation fails); page and
  manifest are published in one dist, do not cache `index.html`/`port.js`. D1 had the same limitation.
- `version` is independent of packing (checked in Python, compared with Node `manifestVersionDigest`, and between `--no-pack`, D1 and different
  pack parameters). `SAVE`, `SAVE_META`, `SAVE_TX`, `options` unaffected; `port.json` rules (`exclude_*`, `relocate_if_absent`)
  apply to logical paths before packing.
- `--no-pack` produces byte-identical D1 layout (manifest without `pack`/`packs`).
- Host without Range: page gets 200 from start of pack and skips unneeded bytes (tested), but resync then downloads entire packs.

## 8. Risks and limitations

- Firefox and Safari untested: relies on `DecompressionStream('gzip')` (Baseline 2023), `ReadableStream` with async `pull`, `fetch` with
  Range, `createWritable` on main thread (Safari main-thread `createWritable` is a separate risk, predating D3).
- Host re-encodes pack (`Content-Encoding`, `gzip_static`, CDN auto-compression): record ranges then address different bytes. Page
  does not decompress twice (SHA-256 and sizes decide), but with `Content-Encoding` + Range the response may not match the manifest; correct approach:
  prevent re-encoding `game/_k2pack/` (Worker sets `no-transform`).
- A pack is processed sequentially: SHA-256 and OPFS writes run record by record. Six streams give 6 parallel pipelines,
  but all on one main thread; weak devices are CPU-limited (JS SHA-256). Improvement: worker with `SyncAccessHandle` and SHA there (separate work).
- Pack shifts when adding a file: packs are cut in path order; inserting a file in the middle shifts all following packs, and `upload.py`
  reuploads them (client only fetches missing files: comparison is per-file, not per-pack).
- Objects from the old layout remain unused in the bucket (uploader deletes nothing).
- Parallel downloads increase peak temporary-copy space during updates (up to N largest replaced files): included in quota.
- Local `serve.py` HTTP/1.0 doubles request cost; measurement requires a real host.
- “One file error stops the entire installation” is possible: as in D1, persistent record corruption (4 unsuccessful attempts) causes failure
  with a message and no marker; other accepted files remain intact and are skipped next time.

## 9. Live checks

On a TEST origin, clean browser profile, DevTools → Network with throttling:

1. Build and verify the dist, then review the uploader dry run before uploading to a test bucket. Use the current commands in [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) and [hosting.md](hosting.md).
2. `curl` a pack (“Transfer packs” in `hosting.md`): no `Content-Encoding`, `Content-Length` = `packs[].size`, `206` for Range.
3. Clean install in Chrome/Edge: “Fast 4G”/“Slow 4G”, then unthrottled: time (console `[install] {"seconds":…}` and `window.installStats`),
   request count in Network (expected ≈410 + manifest), concurrency, “Downloading game files” status advances, game
   starts, `historical diagnostic materials (removed)` reports no problems. Compare `?installConcurrency=1` (≈previous scheme but with packs), 6, 12 on HTTP/2.
4. Resume: DevTools “Offline” halfway through, restore network, reload: completed files and packs not requested, missing data uses Range.
5. Update: rebuild dist with several changed files: Network shows only Range pack requests and separate files, `SAVE`/`options` unaffected.
6. Firefox, Safari (macOS and iOS): same clean install, especially `createWritable` and progress; insufficient-space quota.
7. On a real network: installation time at 20/100 Mbit/s; compare with model (section 2.3) and bench (2.4).

## 10. D3-lazy: lazy loading research and isolated prototype

Question: can the game start without installing all 2351 MB, fetching files as needed, and is it worthwhile? Nothing in this section
was added to the normal game installation. The original estimates below used existing repository logs and source reading.

On 16 November 2026 an **experimental, isolated** request channel was added under `recomp/experimental/lazy-loading/`, together
with a page-side consumer in `recomp/web/experimental/lazy-client.mjs`. The channel accepts only immutable canonical paths, carries
a request token and bounded timeout, and ignores late replies. Its Node and native tests cover forbidden user-data paths, concurrent
requests and late responses. A synthetic test using the actual Emscripten pthread/WasmFS/OPFS stack and a separate Chromium profile
observed a missing file, fetched one HTTP Range, checked SHA-256, wrote it to OPFS, signalled the game thread, and then read and
enumerated it without restarting the runtime. The test does not use real game data or saves. Run:

```sh
sh korsary2-next/recomp/tests/run_lazy_bridge.sh
node --test korsary2-next/recomp/tests/test_lazy_client.mjs
sh korsary2-next/recomp/tests/run_lazy_bridge_browser.sh
```

The browser test needs the prepared Emscripten cache and Playwright described in the build documentation. A subsequent isolated IAB smoke
test used an experimental build and separate localhost origin: its initial bootstrap reported approximately 13.3 MB unpacked and 4.08 MB of
compressed records, then the real game reached the main menu and the opening cabin while fetching 144 additional files (32,868,189 bytes
unpacked and 15,111,599 bytes of compressed records; zero reported errors). The final smoke test used the two-reader placeholder guard
and the cache integrity check. After reloading the same test origin, the game verified the cached assets and reached the menu without
additional on-demand downloads. These figures do not include the 46.6 MB WebAssembly build, manifest, other
on-demand requests, network overhead, extra bytes from range merging or retry traffic. A reproducible experimental
build can be made from a compatible previously built tree with `sh korsary2-next/recomp/experimental/lazy-loading/build.sh NEW_OUTPUT_DIR`;
this never overwrites the normal build or distribution. The prototype is opt-in, uses separate storage and is not a release feature.

The smoke test does not establish that partial game installation is reliable: many locations and save scenarios, interruption and quota
behaviour, updates, a loading UI, and real-browser compatibility require separate verification.
Concurrent reads of an in-progress resource are serialized; after a timeout or download failure the experimental process fails closed.
Before each launch, existing immutable assets are checked by size and SHA-256 without reading or removing saves. There is no automatic
repair of an incomplete cached file. Network failure while the original engine waits for a missing resource can still crash the game
unless a safe recovery path is added.
The normal installation continues to require the full game and the existing save protection.

### Reproduce the experimental game smoke test

From the repository root, first prepare Emscripten 6.0.13, the pinned Dawn package and a normal WebAssembly build as described in
[BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md). The experiment reuses the normal build's generated object files and expects their default
`-O1` flags. It requires Node.js 18.20.8 or newer, `sh`, `perl`, the prepared SDK cache, and a browser with WebGPU. It does not install
anything into the ready distribution. The following creates a **new local copy** of the distribution and the experimental build:

```sh
K2_LAZY_LAB="$(mktemp -d "${TMPDIR:-/tmp}/corsairs-lazy.XXXXXX")"
sh korsary2-next/recomp/experimental/lazy-loading/build.sh "$K2_LAZY_LAB/wasm"
cp -R distribution "$K2_LAZY_LAB/site"
cp korsary2-next/recomp/web/index.html korsary2-next/recomp/web/port.js "$K2_LAZY_LAB/site/"
mkdir -p "$K2_LAZY_LAB/site/experimental"
cp korsary2-next/recomp/web/experimental/lazy-bootstrap.mjs \
  korsary2-next/recomp/web/experimental/lazy-client.mjs "$K2_LAZY_LAB/site/experimental/"
cp "$K2_LAZY_LAB/wasm/game.js" "$K2_LAZY_LAB/wasm/game.wasm" "$K2_LAZY_LAB/site/build/"
node scripts/serve_distribution.mjs --directory "$K2_LAZY_LAB/site" --port 8028
```

Open `http://127.0.0.1:8028/?lazy=1` and stop the server with Ctrl+C. The directory copy needs about 1.3 GB locally; on macOS with APFS,
`cp -cR distribution "$K2_LAZY_LAB/site"` can make a copy-on-write clone instead. Pick a localhost port not previously used by this
browser profile for a clean test, or use a disposable browser profile. The experiment uses a separate OPFS game root and userdata root,
and does not import normal saves. Do not use this prototype for valuable saves or assume that a partially cached game works offline.
The on-demand counters in `window.lazyStats` count completed records and their manifest sizes; they are not exact HTTP traffic measurements.

### 10.1. What the game actually reads

Sources (both runs already in repository, `PORT_LOG=1`, `[file] CreateFileA(...)` lines):

- `historical diagnostic materials (removed)` — **real browser run** (OPFS, timestamps): startup, main menu,
  loading “Tutorial Deck” save (first tutorial location, deck), F2 in-game menu.
- `historical diagnostic materials (removed)` — Node runs: new game “Tutorial Deck”, F2 menu.

File sizes from `--estimate` against current game (`korsary2-next/game`).

| stage (browser run) | files opened | uncompressed | network (gzip) | share of game bytes / files |
|---|---:|---:|---:|---:|
| startup → main menu (before first `SAVE/` open), 328 files by second 5 | 354 | 9,5 MB | 4,1 MB | 0,4 % / 3,6 % |
| load save: tutorial deck (≈9 s file activity of 23 s to interactivity) | +325 (120 new) | 28,7 MB | 12,3 MB | |
| **entire run** | **474** | **35,1 MB** | **15,6 MB** | **1,5 % (network: 1,3 %) / 4,8 %** |
| Node, new game + F2 menu (3 runs) | 515–537 | 37–41 MB | | 1,6–1,7 % |

Set contents: `PROGRAM/**` — 239 scripts (`.c`/`.h`, 3.8 MB of 761 files and 3.6 MB over network with `MODULES`), `MODULES/Techniques/*.sha`
(62 shaders), `RESOURCE/INI` (27 `.ini`), interface, font, Loading splash, water (`bump_g2mx`, `bump_g3`) and sky textures, deck model
`tut_deck` with `.col`, animations `man.an` (5.2 MB) and `woman.an` (3.3 MB), 2 music `.ogg` (3.8 MB) and 15 `.wav`. Seven opens failed — these are
OPTIONAL files whose existence the engine checks (`project.df`, `memory.mp`, two `.col`, one `.tx`): “not in manifest” must be distinguished from “not yet downloaded”.

Directory enumeration (`FindFirstFileA`): 51 calls per run across ≈25 directories — `MODULES\*.dll`, `MODULES\Techniques\*` (13 shader subdirectories),
`RESOURCE\INI`, `INI\Interfaces`, `INI\Aliases`, `INI\Particles`, `Textures\Interfaces\mainback\*`, `SAVE\*`. Lazy loading must provide
these lists from the manifest (which knows all names), not OPFS.

Absent from logs: sea, other islands and towns, combat, ships, dialogs beyond the deck, event sounds. These involve a few files per event but, by number
and size (models 705 MB, textures 1105 MB), constitute the bulk. How much of 2351 MB is needed in the first hour — NOT measured.

### 10.2. Game file layer (relevant to lazy loading)

- Browser build uses WasmFS + OPFS backend (`host/main.c`: `wasmfs_create_directory("/opfs", …, wasmfs_create_opfs_backend())`), game runs in pthread (`-sPROXY_TO_PTHREAD`).
  OPFS operations are asynchronous, and the game thread already blocks on every `open`/`read`/`stat` until the helper thread responds: synchronous file calls
  on the game thread are normal; waiting there is acceptable.
- `kernel32.c` `CreateFileA` → `map_path` (`core.c`: case-insensitive `opendir`+`readdir`+`strcasecmp` search for each path component, i.e. linear directory scan)
  → `open`. For a read-only `OPEN_EXISTING` file ≤16 MiB (`PORT_FILE_SNAPSHOT_MAX`), the file is **read fully once on open** (`file_snapshot`) and
  then served from memory: the point where “the entire file is needed” coincides with `CreateFileA`. Natural place to “ensure file exists locally”.
- OPFS is case-sensitive, engine is not: host resolves names using actual directory listings. In a lazy install OPFS lacks some names.
- OPFS `Blob` snapshots: `historical diagnostic materials (removed)` and `historical diagnostic materials (removed)` showed overwriting a file open for reading breaks its reads (`NotReadableError`).
  Lazy loading writes ONLY new files atomically (`createWritable` → `close`), never replacing open files, so that race does not apply; but
  WasmFS behavior when a file appears after an earlier “not found” response (dentry cache) was NOT tested and must be measured.

### 10.3. Is on-demand loading possible?

Yes, in principle in three ways; none is ready:

1. **Blocking fetch from the game thread.** In `CreateFileA`, if the manifest table (in wasm: case-insensitive path → size, SHA-256, pack, offset, csize, “local
   presence”) says the file is absent in OPFS, game thread queues a request in `SharedArrayBuffer` and waits (`Atomics.wait`); the page (main thread is free, not the game thread under
   `PROXY_TO_PTHREAD`) does `fetch` (Range for the pack record), writes file to OPFS with size and SHA-256 check (same `downloadPackRun` code) and wakes the thread. “Worker + Atomics
   + fetch” works without Asyncify. This is exactly how the game already blocks on OPFS.
2. **Background prefetcher**: priority queue (current location, neighboring ones, sea, combat), minimizing blocking misses.
3. **Staged installation without on-demand fetch**: first the “core” (menu + tutorial), then launch is allowed while the rest downloads in the background. Without method 1 a miss = “file not found” mid-game,
   so alone it is only suitable as a “please wait, downloading” screen at the core boundary.

### 10.4. Required host changes (files owned elsewhere, outside this task)

- `core.c`/`kernel32.c`: manifest name index (`find_ci`, `FindFirstFileA`, `GetFileAttributes` must see names not yet in OPFS). One OPFS placeholder file per
  name is unsuitable: 9824 `createWritable` ≈30 s (3.8 ms/file on bench). Only directories can be created.
- Distinguish “not in manifest” (truly absent) from “not yet downloaded”.
- `Atomics`/`SharedArrayBuffer` game-thread ↔ page bridge, queue, timeouts and errors (network lost mid-game).
- Page: `missing-resource-preflight.mjs` and install marker assume a full set; manifest updates during partial install; quota and storage eviction
  live longer; `?lazy=1` flag, off by default.
- Online (netplay, lockstep): lazy loading is unacceptable — one player waiting for a file desynchronizes clocks; online requires the full set before start.

### 10.5. Risks (freezes and integrity)

- **RTT blocks the entire game thread.** Sequential per-file fetching for the tutorial deck set (471 files) would freeze the game for 24–53 s (RTT 50–100 ms) —
  faster than full installation (98 s at 100 Mbit/s), but unacceptable inside the game; only known-ahead items can download in parallel. Location → file sets are needed,
  collected with `PORT_LOG` across all locations, islands and ships (unavailable: report covers one scenario), and a batch on first access to a location directory.
- **Combat and sea**: new ship models, first-event sounds (`SoundService` opens `.wav` on first playback), particles (`.ptc`), textures. Game-thread blocking
  during combat means frozen frames and an empty audio ring (AudioWorklet is not fed). Guaranteed prefetch of “everything potentially needed for combat/sea” is required before entry.
- **Case and enumeration**: solved with a manifest index (exact names and directory listings).
- **Packing and on-demand loading**: path-ordered 8 MiB packs do NOT match individual location sets (model, textures and lighting are in different trees). Fetching a whole pack on a miss
  produces ×12–23 overfetch for tutorial (22 packs / 182 MB + 6 separate files instead of 15.6 MB) — fetch must use record Range (manifest already has `offset`/`csize`),
  not whole packs, or a different per-location packing plan is needed.
- **Partial installation**: browser eviction, “clear site data”, quota, manifest version; need honest “core ready / all ready” states and retry of interrupted fetches.
- Integrity: accept a file only after SHA-256 and `close` (as now); if network disappears, file error must let the game stop on a waiting screen rather than crash.

### 10.6. Minimum set “to first frame” and time savings

- Before main menu: **354 files, 9.5 MB (4.1 MB network)**; before first tutorial frame: **474 files, 35 MB (15.6 MB network)** — 1.3–1.5% of bytes and under 5% of files.
- Model download time for this set (`install_model.py`, 6 streams; “Range batches” = records merged into pack ranges with gaps up to 256 KiB; “per file, blocking” = one file at a time):

| Mbit/s, RTT | menu: per file 1 stream | per file 6 streams | Range batches, 6 | tutorial: per file 1 stream | per file 6 streams | Range batches, 6 | full D1 install, 1 stream | full install, packs, 6 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| 20, 100 ms | 36,8 s | 6,9 s | 2,1 s | 53,3 s | 11,7 s | 7,4 s | 1472 s | 489 s |
| 100, 100 ms | 35,5 s | 6,0 s | 0,6 s | 48,3 s | 8,3 s | 1,9 s | 1080 s | 98 s |
| 100, 50 ms | 17,9 s | 3,1 s | 0,5 s | 24,8 s | 4,5 s | 1,6 s | 589 s | 98 s |
| 300, 50 ms | 17,7 s | 3,0 s | 0,3 s | 24,0 s | 4,0 s | 0,8 s | 524 s | 33 s |

  “Range batches”: menu — 25 requests / 5.1 MB, tutorial — 61 requests / 18.3 MB. Add CPU (SHA-256, write: ≈1–3 s for 35 MB).
- Time saved to menu/first frame versus full installation (even packs): ×40–×230 in model (at 100 Mbit/s — 98 s to 0.6–1.9 s; at 20 Mbit/s — 489 s to 2–7 s).
  THIS IS AN UPPER BOUND for one scenario (tutorial deck save). First-session savings depend on how many files the player later requests (islands, sea, combat), and how much
  prefetch can bring before needed; background installation of the remaining ≈1200 MB still runs in parallel (≈98 s…8 min at table bandwidths).

### 10.7. Conclusion: worthwhile and in what form

Worthwhile, but NOT as “blocking per-file fetch from game thread” (24–53 s of freezes on one deck, unacceptable in combat and online). Recommended stages:

0. **Measurement (no product code).** Run Node build with `PORT_LOG=1` through scenarios: menu, new game, tutorial, first town, island, sailing out, sea battle, boarding,
   dialogs, location changes, loading saves from different stages; derive “scenario → files” and first-hour byte share from logs. Analysis scripts (unique opens by directory,
   manifest sizes, Range-batch model) have a ready basis in sections 10.1 and 10.6 (streaming, no dist). In live browser also measure blocking misses and
   latency distribution in stage-2 prototype. Without these data it is too early to make a product decision.
1. **Two-tier installation (cheap, no on-demand fetch).** Manifest labels “core” (menu + tutorial, ≈16 MB network) and “rest”; page installs core first and says “tutorial playable”,
   downloads rest in background; crossing core boundary waits for install completion (waiting screen). Saves new-player time to first launch, no host changes. Boundary policy needed.
2. **Prototype blocking batch fetch** in Node build with artificial latency (D3 bench style): bridge + manifest index; measure miss count and duration for stage-0 scenarios.
3. **Prefetcher + location sets**, record Range fetching; `?lazy=1` mode, off by default, not online; browser checks Chrome/Firefox/Safari, throttling.

**Live measurements before deciding:** (a) file sets during 5–60 minutes of real gameplay (islands, sea, combat, dialogs) and share of bytes the player never opens during a session; (b) count and duration
of blocking-fetch misses at RTT 50/100/200 ms; (c) whether WasmFS behaves correctly when a file previously reported “not found” appears later; (d) host/bucket load (Worker/R2 Range request count
instead of whole packs); (e) AudioWorklet and frame behavior when game thread blocks for 100–500 ms; (f) browser eviction and quota for partial install.


## 11. Tests

| file | coverage |
|---|---|
| `tests/test_install_packs.mjs` (Node, no network) | packed manifest validation; range planner; pack: round-trip under any chunking (1 byte … 1 MiB), Range and server without Range, empty records without request; truncation, corrupt gzip and raw record, wrong Content-Range, 404/500; install: concurrency 1/3/6, at most N requests, order, monotonic progress; persistent error does not corrupt others; mid-pack interruption (Range resume), resume, range resync, cancellation, insufficient space, old manifests, quota by `size`/`csize` and `tempBytes` |
| `tests/test_install_requests_browser.mjs` | bench: real `port.js` + Chromium + OPFS + loopback with latency (HTTP/1.1 and HTTP/2), see section 2.4; WebCrypto SHA-256 of all files, marker, request count, concurrency, relative times, failure and resume, record corruption |
| `tests/test_pack_dist.py` | `plan_packs`, `write_pack`/`verify_pack`, `make_dist` layout (version independent of packing, reproducibility, `--no-pack`), 20 corruption types for `verify_dist`, `serve.py --pack`, `upload.py`, model |
| `tests/test_worker_packed.mjs` | `worker.js` for `.pack`: opaque bytes, `no-transform`, Range |
| existing | `test_game_transfer*.mjs`, `test_resync_preservation`, `test_storage_estimate`, `test_options_sync`, `test_plan_file_update`, `test_save_update_lock`, `test_make_dist_coverage.mjs` (inventory tests now with `--no-pack`), `test_compression_dist.py` (D1 layout, `--no-pack`), `test_verify_dist.py`, `test_serve_path_safety.py`, `test_upload.py`, `test_video_serve.py`, `test_dist_http_smoke.mjs` (+ packed layout) |
