# Hosting the ready build

The `distribution/` directory contains a standalone static build: the page,
WebAssembly, game data, the English layer, and videos. Publish all of its
contents while preserving the directory structure. Player saves are not part
of the build: the browser stores them in its own local storage.

To run a local check from the repository root:

```sh
node scripts/serve_distribution.mjs
```

Open `http://127.0.0.1:8000/`. The server is intended for local development,
requires only Node.js 18.20.8 or newer, and stops with Ctrl+C. If needed, specify `--port 8001`
or `--directory /path/to/distribution`. For public hosting, use HTTPS and a
static host with configurable headers and Range request support. The game needs
a browser with working WebGPU.

## Verifying the build

From the repository root:

```sh
node korsary2-next/recomp/tests/verify_dist.mjs --dist distribution \
  --full-hash --require-overlay --no-freshness --no-videos-web
node korsary2-next/recomp/tests/test_dist_http_smoke.mjs distribution
```

The first command verifies the file inventory and hashes; the second starts a
local test server and checks HTTP delivery. They check local files and do not
verify the configuration of the chosen external host. For rebuilding, see the
[developer instructions](BUILD_FROM_CLONE.md).

## Uploading through the Cloudflare Worker

For a Worker configured with the upload endpoint and its secret, use the Node.js
uploader. It checks that manifest objects exist, uploads immutable files using
size and SHA-256 to resume, and sends manifests last:

```sh
export PORT_UPLOAD_TOKEN='<upload-token>'
node korsary2-next/recomp/web/cloudflare/upload.mjs https://example.workers.dev --dist distribution --dry-run
```

Review the dry run before omitting `--dry-run` for an actual upload. The uploader
never deletes previously uploaded objects. Do not commit the token.

## Configuring the host

Responses must include these headers:

```http
Cross-Origin-Opener-Policy: same-origin
Cross-Origin-Embedder-Policy: require-corp
Cross-Origin-Resource-Policy: same-origin
```

They are needed on the page and its resources, including WebAssembly, scripts,
videos, and error responses. The first two enable `crossOriginIsolated`, which
is required for WebAssembly threads. `distribution/_headers` defines the rules
in Cloudflare Pages format; on another host, configure them using the server's
own mechanisms. Avoid sending the same header more than once with different
values.

Check MIME types: `.wasm` — `application/wasm`, `.js` and `.mjs` —
`text/javascript`, `.mp4` — `video/mp4`. The server must support single
`Range: bytes=...` requests for videos and files in `game/_k2pack/`, return
`206`, and provide correct `Content-Range` and `Content-Length` headers. Do not
enable automatic recompression of prepared files: packed data must be returned
without changing its bytes.

## Checking the published address

Substitute your deployment address for `https://example.org`:

```sh
curl -sI https://example.org/
curl -sI https://example.org/build/game.wasm
curl -si -H 'Range: bytes=0-3' https://example.org/videos/Trailer.mp4
```

Check the isolation headers, WebAssembly MIME type, and `206` response with
`Content-Range`. Then open the game over HTTPS, confirm `crossOriginIsolated`
in the browser console, install the game on a new origin, start it, and check
saving and loading. To check a range inside a game pack, use a path from `packs`
in `game/manifest.json`. Changing the domain or scheme creates separate browser
storage, so ask players to export their saves before a move.

The current verification status and known limitations are described in the
[readiness report](PUBLICATION_READINESS_2026-11-15_RELEASE.md).
