> Historical technical document: intermediate diagnostic runs have been removed. Their screenshots and example commands are unavailable; see [BUILD_FROM_CLONE.md](BUILD_FROM_CLONE.md) for current instructions.

# D1: compression of game data in transit

Status: implemented and tested synthetically (Node, Python, real OPFS + `DecompressionStream` in ephemeral
headless Chromium 158). A real dist build, bucket upload and network installation were NOT performed. All claims
about Firefox, Safari, real hosts and installation time over an actual network are estimates and the
“Live checks” checklist (section 8).

## 1. Summary

| | Before | After |
|---|---|---|
| Files installed | 9824 | 9824 (same set; `exclude_paths`/`exclude_if_sibling` rules unchanged) |
| Uncompressed size (OPFS, quota) | 2351.0 MB | 2351.0 MB (OPFS stores decompressed data) |
| Network transfer (excluding video and build) | 2351.0 MB | **≈1223 MB (52.0%, −48.0%)** from streaming measurements on real data |
| Files published as `.gz` | — | 8002 of 9824 |
| Disk space for dist at build time | ≈2.4 GB | ≈1.3 GB (1223 MB + build ~46 MB + video ~40 MB) |

Selected **option (B): precompressed `game/<path>.gz` files (gzip level 6) + client-side streaming
decompression to OPFS via `DecompressionStream('gzip')`**, with post-decompression size and SHA-256 checks. The target of ≈ −50%
is nearly met (−48.0%): the remaining difference to −50% requires a format unavailable in native
`DecompressionStream` (brotli/zstd, section 3), and is deferred to a possible D1b stage.

## 2. Measurements

### 2.1. Compression by type (gzip/brotli/zstd)

Measurements with Node 26 (`zlib`: gzip, brotli, zstd) on samples (≈80 MB of random files per type, reproducible
order), then streaming over ALL files in the game directory (2418 MB without `port.json` filters, without writing to disk):

| type | files | MB | gzip -6 | gzip -9 | brotli q5 | brotli q9 | zstd 3 | zstd 19 |
|---|---|---|---|---|---|---|---|---|
| `.tx` (textures) | 1794 | 1105,5 | 55,9 % | 58,5 %* | 56,0 %* | 51,5 % | 58,4 %* | 48,3 % |
| `.gm` (models) | 2074 | 705,5 | 52,0 % | 50,0 %* | 38,4 %* | 35,0 % | 44,1 %* | 33,9 % |
| `.col` | 3387 | 156,0 | 23,4 % | 23,7 %* | 23,4 %* | 21,8 % | 25,7 %* | 20,2 % |
| `.wav` | 970 | 119,4 | 89,2 % | 89,2 %* | 88,1 %* | 88,1 % | 89,8 %* | 88,1 % |
| `.an` (animations) | 143 | 112,1 | 19,7 % | 19,5 %* | 17,3 %* | 17,4 % | 19,1 %* | 18,5 % |
| `.ogg` | 776 | 64,3 | 98,4 % | 98,4 %* | 98,3 %* | 98,2 % | 99,1 %* | 98,2 % |
| `.ptc` | 136 | 45,4 | 16,8 % | 16,0 %* | 14,3 %* | 13,9 % | 16,9 %* | 13,0 % |
| **total (entire set)** | | **2417,9** | **53,2 %** | | | **45,8 %** | | **43,9 %** |

`*` indicates sample measurements (percentages of the sample, not the full type); unstarred values cover the complete set.
Findings:

- gzip -6 → -9 saves ≤0.8% (usually ≤0.3%) at ×3–4 compression time: level 6 was chosen.
- brotli q9 and zstd 19 beat gzip by ≈7.4 and ≈9.3 percentage points (≈180–225 MB), mainly for `.gm` (35% vs 52%)
  and `.tx` (48–51% vs 56%). `.wav` and `.ogg` barely compress under any format (`.ogg` is excluded by type).
- Exact estimate on the real set (`make_dist.py --estimate`, gzip 6, `port.json` rules applied, 8 cores, ≈9 s,
  no writes): **9824 files, 2351.0 MB → 1223.1 MB (52.0%)**; `.tx` 1105.5 → 618.4; `.gm` 705.5 → 366.6;
  `.col` 156.0 → 36.6; `.wav` 119.4 → 106.8; `.an` 112.1 → 22.0; `.ptc` 45.4 → 7.6; `.ogg` (37 remaining) 49.1 → 49.1.
  The earlier “gzip -3: ≈ −50%” estimate was optimistic by 2 points.

### 2.2. Browser capabilities

`new DecompressionStream(format)` in bundled Chromium 158.0.8127.18 (Playwright): `gzip`, `deflate`, `deflate-raw`
are supported; `brotli`, `zstd` (also `br`, `zlib`) raise `TypeError: Unsupported compression format`. Documentation
and compatibility summaries disagree (MDN lists `brotli` among formats; caniuse says `zstd` in
`DecompressionStream` is unsupported by any major browser); Chromium 158 actually supports neither.
`gzip`/`deflate` in `DecompressionStream` are Baseline 2023 (Chrome 80, Firefox 113, Safari 16.4 per documentation;
NOT tested on Firefox or Safari). Thus only gzip/deflate are available natively across the target browsers without a third-party decoder.

## 3. Options and decision

| Criterion | (A) host `Content-Encoding` | **(B) precompressed `.gz` + `DecompressionStream`** | (C) custom block format | (D) precompressed `.br` + `Content-Encoding: br` from Worker |
|---|---|---|---|---|
| Savings | host-dependent: on-the-fly gzip/br only for “text” types; not guaranteed for binary/`application/octet-stream` (not tested on real Cloudflare) | −48.0% (measured) | as (B) + resume within a file | ≈ −55% (brotli q9 estimate on an approximate set) |
| Control | none: depends on host and CDN, cannot be verified with tests | full: bytes are in dist and bucket | full | requires a host that can set `Content-Encoding` (Worker can, Pages/static cannot) |
| `Range` resume | with `Content-Encoding`, ranges address compressed bytes while the page counts uncompressed sizes | cannot resume within a file, but the largest file is ≈13 MB: restarting it is cheap | possible | same issue as (A) |
| Traffic/progress | `fetch` hides compressed bytes | `csize` is known; progress is in uncompressed bytes | — | as (A) |
| Chrome/Edge/Firefox/Safari | yes (on HTTPS) | gzip — yes (Safari 16.4+) | custom decoder needed (JS/WASM) | brotli as HTTP encoding — yes, but usually not on `http://` (browsers offer `br` only in a secure context; untested): local `serve.py` needs a fallback |
| Post-decompression size and SHA check | automatic (client sees decompressed data) | added to the client, SHA is calculated over decompressed bytes | yes | automatic |
| local `serve.py`, `make_dist`, `upload.py`, Worker, `verify_dist` | `serve.py` would need encoding negotiation | all five updated (sections 4–5) | rewrite everything | as (A) |
| Old manifests | work | work (without `enc`) | transition period needed | work |
| Risk | high (cannot verify without a real host) | low | high (custom format and decoder) | medium |

**Decision: (B).** The only option that delivers meaningful savings, can be fully verified by tests without a network,
does not depend on the host and works on `http://localhost`, in Worker/R2 and on any static host.
(A) and (D) remain possible follow-ups if hosting shows that it compresses `octet-stream` with brotli:
check with one command (section 8). (C) is unnecessary: files are ≤13.2 MB and redownloading a whole file is cheap.

Brotli WASM decoder option (D1b): ≈ −55% instead of −48%, an additional third-party dependency (≈100–200 KB),
CPU cost ≈ gzip or higher, and brotli q9–q11 compression is significantly slower than gzip. The `enc`/`ENCODINGS` design supports
adding `"br"`: a new suffix, new `ENCODINGS` entry, and known encoding list in `validateManifestFiles`.

## 4. Format

Manifest entry (`game/manifest.json`); `enc` and `csize` are optional:

```json
{ "path": "RESOURCE/Models/Locations/outside/Jungle_1/jungle01.gm", "size": 12183759, "sha256": "…",
  "enc": "gzip", "csize": 5400123 }
```

- `size` and `sha256` ALWAYS refer to uncompressed content. Quota (`planStorageNeed`), installed-file checks
  (`verify`), `missing-resource-preflight.mjs` and manifest `version` do not depend on compression.
- `enc: "gzip"` — the object is at `game/<path>.gz`; the page rejects unknown `enc` (e.g. a newer `"br"`)
  BEFORE writing anything: “unsupported encoding … reload the game page”.
- `csize` — exact `.gz` length (written by `make_dist`; required by `verify_dist`; not written by `serve.py --compress`,
  so the page checks only uncompressed size and SHA when absent).
- An entry without `enc` (or `"identity"`) is the file as-is under the old `game/<path>` name: this is how all old
  manifests and incompressible files appear.
- `version` is the same `sha1(path:size:sha256;…)[:12]` (`gamefiles.manifest_for`, `verify_dist.manifest_version`,
  `missing-resource-preflight.mjs manifestVersionDigest`); a test compares Python and Node on an `enc` manifest.
- Stream: one complete gzip member without name or time (header `1f 8b 08 00 00000000 00 ff`), raw level-6 deflate +
  crc32/isize, assembled manually: the same input produces the same bytes on any platform (otherwise `upload.py` would
  upload files again).
- Excluded from compression: `options` (mutable player data), `.ogg/.mp4/.webm/.png/.jpg/.gif/.gz/.zip/.7z/.rar/.bik/.wmv/.mp3`,
  files <1 KiB, files reduced by less than 5% by gzip, and files whose `<path>.gz` name is occupied by another file.
  `SAVE`, `SAVE_META`, `SAVE_TX` remain excluded from dist.

## 5. Changes

| File | Change |
|---|---|
| `web/gamefiles.py` | `gzip_pass`, `gunzip_check`, `packable`, `worth_packing`, `packed_key`; `manifest_for(files, packed=None)` (version unchanged) |
| `web/make_dist.py` | writes `.gz` + `enc`/`csize` by default, self-checks every `.gz` by decompression, `--no-compress`, `--estimate` (estimate without writing or building) |
| `web/game-transfer.mjs` (new) | streamed download: fetch → `DecompressionStream` → SHA-256 calculation → write; commit (`close`) only after checks; any failure causes `abort` + file deletion |
| `web/save-protection.mjs` | `validateManifestFiles` (enc/csize), `planFileUpdate(…, packed)` (partial compressed files are not resumed), `planStorageNeed` (+`transferBytes`, quota by `size`), `syncManifestFiles` passes the entry to `downloadFile`; **`sha256Update` accelerated ≈4×** (51 → 224 MB/s in Chromium) |
| `web/port.js` | `downloadFile(…, entry)`; checks `DecompressionStream` support before writing |
| `web/serve.py` | `--compress [--pack-cache DIR]` (compress on first request, Content-Length and Range in compressed bytes, no `Content-Encoding`), unchanged by default; K3 `PORT_WWW_DIR` fix retained |
| `web/cloudflare/worker.js` | for `game/*.gz`: no `Content-Encoding`, `Cache-Control: …, no-transform` |
| `web/cloudflare/upload.py` | verifies each manifest object exists in dist before upload |
| `tests/verify_dist.py` | checks `enc` entries against `<path>.gz` and the decompressed stream (size, SHA-256), `csize` = file length, no adjacent uncompressed copy, `options` uncompressed, `game-transfer.mjs` present |
| `tests/test_dist_http_smoke.mjs` | understands `.gz` entries; includes a packed synthetic fixture |
| `docs/hosting.md` | “Compression in transit (D1)” section |

## 6. Client behavior and resume

- Each file is downloaded in full (`Range` is not used for `.gz`), decompressed as a stream, and written in chunks (in tests, chunks are at most ¼ of the file; the entire file is never held in memory). SHA-256 is calculated over decompressed bytes as they pass. The write is committed only if decompressed size = `size`, SHA-256 = `sha256`, compressed stream length = `csize` (when provided), and the decompressor finishes without error. Otherwise: `abort` the write, delete the file, and return an error.
- Retries (four attempts) and skipping completed files use the existing `syncManifestFiles`: a completed file with matching size and SHA-256 is not downloaded; an interrupted compressed file restarts from zero; uncompressed files resume with Range as before.
- Progress uses decompressed bytes (the sum of `size`), so the progress bar is correct; the MB displayed in the status is the decompressed amount. Network volume appears only in the insufficient-space warning (`transferBytes`).
- Quota is based on decompressed size plus a reserve, as before; the message says “approximately N MB over the network.”
- If a file loses its write, an error is shown on the installation screen and `fail` is returned, as with any download error.

## 7. CPU and time impact (estimates)

Measured in headless Chromium 158 on this machine, localhost, with no network throttling:

- Synthetic 48 MB (compresses to 1%): fetch + gunzip + SHA-256 + OPFS write: 151 MB/s (before SHA optimization it was 45 MB/s; `DecompressionStream` itself is ≈5 GB/s and OPFS write ≈430 MB/s).
- 571 real game files (`.tx/.gm/.an/.col`, 162 MB → 80 MB transferred, ×0.49): 2.07 s = **79 MB/s** decompressed (many small files make per-file overhead noticeable).
- Full installation (2351 MB): ≈30 s of CPU time distributed over the download, on the main thread.
- Downloading 1223 MB instead of 2351 MB: at 100 Mbit/s, ≈98 s instead of ≈188 s; at 50 Mbit/s, ≈195 s instead of ≈376 s. On very fast connections (>≈600 Mbit/s), compressed installation becomes CPU-bound (≈30 s) and will be 10–15 s slower than uncompressed; this is the only regression.
- Side benefit: `sha256Update` in `save-protection.mjs` is ≈4× faster (51 → 224 MB/s in Chromium), accelerating the existing SHA-256 check of installed files during updates.
- Not measured or changed in D1: downloading was file by file, so on high-latency connections the number of requests (9824), rather than volume, dominates. D3 addressed this with parallel downloads and transfer packs: `docs/install-requests-d3.md`.

## 8. Live checks

Use a TEST origin, not the real one, and a clean browser profile:

1. Build and verify the dist using the Node.js commands below. Review the `upload.mjs --dry-run` output before uploading to a test bucket.
2. `curl -sI https://HOST/game/<any-compressible-path>.gz`: no `Content-Encoding`, `Content-Length` equals the manifest's `csize`, and `no-transform` is present. If `Content-Encoding` is present, traffic will not decrease (the page will tolerate it).
3. Clean Chrome/Edge installation: check time and traffic (DevTools Network: ≈1.22 GB total instead of 2.35 GB), progress bar (smooth, reaches 100%), game launch, and that preflight (`historical diagnostic materials (removed)`) reports no errors.
4. Resume: interrupt the network halfway through installation (DevTools offline), restore it, and reload. Completed files are skipped, the interrupted file downloads again, installation completes, and final SHA matches (preflight “verified”).
5. Firefox and Safari (macOS and iOS if needed): the same clean install; expect `DecompressionStream('gzip')` and `createWritable` to work. Safari's `createWritable` on the main thread is a separate risk predating D1.
6. Update after a manifest-version change (old installed dist → new): SAVE/options are untouched and a backup is created; the mechanism is unchanged.
7. Check in one command whether the host itself compresses binary content (option A): `curl -sI -H 'Accept-Encoding: br, gzip' https://HOST/game/<uncompressed-path>`. If `Content-Encoding: br` is returned for an uncompressed file, this would save ≈55% without client changes and D1b could be reconsidered.
8. On a real network, measure installation time at 50 and 200 Mbit/s.

## 9. Risks

- Firefox/Safari were not tested; conclusions rely on documentation (`DecompressionStream('gzip')` is Baseline 2023).
- A host may add `Content-Encoding` or transcode `.gz` (Apache `AddEncoding`, nginx `gzip_static`, CDN). The page detects response `Content-Encoding` and avoids a second decompression; SHA/size remain valid, but the savings disappear. The Worker strips `Content-Encoding` and sets `no-transform`; Cloudflare Pages `_headers` was NOT changed (Pages is already unsuitable because of file size, see `hosting.md`).
- SHA-256 runs on the main thread in pure JS (≈220 MB/s in Chromium); on weaker devices such as phones, the impact is more noticeable.
- Compressed files cannot resume midway (files are ≤13.2 MB). This is a minor drawback; a block format is not justified.
- Reproducibility of compressed bytes depends on the zlib version (changing libraries can change `.gz` hashes and cause `upload.py` to upload files again; content and manifest `version` remain unchanged).
- Old pages (`port.js` before D1) cannot read a compressed manifest: they request the uncompressed name and receive 404. The page and manifest are published as one dist; do not cache `index.html`/`port.js` longer than the deployment.
- Previously uploaded uncompressed objects remain unused in the bucket (≈2.4 GB of storage); `upload.py` deletes nothing.
- `serve.py --compress` compresses on the first request for a file (≈0.3 s delay on large files); cached copies are in a temporary directory removed on exit, or in `--pack-cache`.

## 10. Compatibility

- Old manifest without `enc`: the page works unchanged (the `old manifest` test).
- Mixed manifest: some files are `.gz`, others ordinary files (Node and Chromium tests).
- `--no-compress` produces the old dist format (manifest keys match the previous version byte for byte).
- `SAVE`, `SAVE_META`, `SAVE_TX`, and `options` are untouched; `options` is never compressed and never gets `enc`.
- `exclude_paths` and `exclude_if_sibling` operate on logical paths before compression; `verify_dist` checks them by logical name.

## 11. Build and verification procedure (the real build was NOT run)

```
# Estimate without writing (streaming, ≈10 s on 8 cores):
node korsary2-next/recomp/web/make_dist.mjs --game korsary2-next/game --estimate

# Build (needs ≈1.3 GB free rather than 2.4 GB; requires build_web/www/game.{js,wasm}):
node korsary2-next/recomp/web/make_dist.mjs --game korsary2-next/game --out dist-d1
node korsary2-next/recomp/tests/verify_dist.mjs --dist dist-d1 --full-hash --source-game korsary2-next/game
node korsary2-next/recomp/tests/test_dist_http_smoke.mjs dist-d1

# Upload (plan, then for real):
PORT_UPLOAD_TOKEN=… node korsary2-next/recomp/web/cloudflare/upload.mjs https://<worker> --dist dist-d1 --dry-run
```

The Worker must be redeployed (`worker.js` changed: `game/*.gz`). From the repository root, the local equivalent is `node korsary2-next/recomp/web/serve.mjs --game korsary2-next/game --compress`.

## 12. Tests

| File | Coverage |
|---|---|
| `tests/test_game_transfer.mjs` (Node, no network) | Chunked round trip, empty files, SHA-256 after decompression (refusal, file deleted, `close` not called), truncated and corrupted streams, wrong size/csize, trailing garbage, non-gzip response, HTTP 404, host with `Content-Encoding`, network interruption + retry via real `syncManifestFiles`, resume, mixed and old manifests, unknown `enc`, quota based on decompressed size, page SHA = `crypto` for any chunking |
| `tests/test_game_transfer_browser.mjs` | Real OPFS and `DecompressionStream` (ephemeral headless Chromium, free loopback port, clean context): clean mixed-manifest installation with independent SHA check via WebCrypto, connection interruption, corruption/truncation/garbage, `Content-Encoding` on `.gz`, speed |
| `tests/test_compression_dist.py` | Format and reproducibility, policy, compression-independent `version` (and comparison with Node), `make_dist` (layout, `--no-compress`, `--estimate`), `verify_dist` (11 corruption types), `serve.py --compress` (Content-Length, Range, HEAD, cache, first-request race), `upload.py` (manifest verification) |
| `tests/test_worker_packed.mjs` | Real `worker.js` code with an R2 mock: `.gz` without `Content-Encoding`, `no-transform`, Range over compressed bytes |
| Existing tests | `test_resync_preservation.mjs`, `test_storage_estimate.mjs`, `test_make_dist_coverage.mjs`, `test_verify_dist.py`, `test_serve_path_safety.py`, `test_upload.py`, `test_video_serve.py`, `test_options_*`, `test_plan_file_update`, `test_save_update_lock`, `test_missing_resource_preflight`, `test_dist_http_smoke.mjs`: no regressions |
