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

## Cloudflare Workers Static Assets

The static-assets option does not require R2. It compresses the WebAssembly
runtime to fit Cloudflare's 25 MiB per-asset limit, and uses a Worker to serve
byte ranges for transfer packs and videos. Saves remain in each player's
browser. The current deployment is for solo play; netplay is not configured.
To return a byte range, the Worker reads the full static asset internally and
sends only the requested bytes to the browser. This uses Worker memory and CPU;
large numbers of concurrent requests have not been load-tested.

Install a supported Node.js version for Wrangler (22.12 or newer for the
version below), review the account plan, and authenticate. Check that the
Worker name in `wrangler-static.toml` is unused before deploying: deployment
to an existing name replaces that Worker. From the repository root:

```sh
node korsary2-next/recomp/web/cloudflare/prepare-static.mjs distribution cloudflare-static
npx --yes wrangler@4.164.0 login
npx --yes wrangler@4.164.0 deploy --config korsary2-next/recomp/web/cloudflare/wrangler-static.toml
```

`prepare-static.mjs` creates a new output directory and refuses to overwrite
one. To rebuild it, remove only your own generated `cloudflare-static/`
directory first. It rejects save directories and symlinks in the input.
Cloudflare Workers Free currently allows 100,000 Worker invocations per day;
pack and video requests count towards that limit, and receive HTTP 429 after
it is reached. Static assets are otherwise served without a storage charge.
Static files and the generated size index must be
deployed together. Test game startup, location streaming, and saving and
loading on the published HTTPS origin; local browser saves on other origins
do not automatically move to that origin. See
[Workers limits](https://developers.cloudflare.com/workers/platform/limits/)
and [static assets billing](https://developers.cloudflare.com/workers/static-assets/billing-and-limitations/).

## Cloudflare R2 and Worker

The Worker serves the whole distribution from a private R2 bucket, adds the
isolation headers, and supports byte ranges. The `workers.dev` hostname is
sufficient; a custom domain is optional. A public site is deliberately enabled
only at the final deploy. The current game configuration exposes solo play;
netplay is not validated for this deployment. Do not enable public R2 bucket
access: serve files through the Worker so its headers apply.

The game server and uploader run on Node.js 18.20.8 or newer. The separately
installed Wrangler 4.164.0 requires Node.js 22.12.0 or newer and a compatible
OS. These deployment examples use a POSIX shell and run from the repository
root. No account credentials or upload tokens belong in Git.

1. Create or select a Cloudflare account, activate R2 in the dashboard, and
   review the free-tier limits and billing settings. Choose an unused Worker
   name and bucket name: `korsary2-web` is only the default in
   `korsary2-next/recomp/web/cloudflare/wrangler.toml`. Check the account
   before creating resources; do not overwrite an existing Worker or bucket.
2. Authenticate in the browser and confirm the target account:

   ```sh
   npx --yes wrangler@4.164.0 login
   npx --yes wrangler@4.164.0 whoami
   ```

3. Create a **Standard** R2 bucket matching `bucket_name` in the Wrangler
   configuration. Enable a `workers.dev` subdomain if Cloudflare asks.

   ```sh
   npx --yes wrangler@4.164.0 r2 bucket create korsary2-web --storage-class Standard
   ```

4. Deploy the Worker closed to public reads, then create a temporary upload
   token locally. Use the same shell for the uploader. This token authorizes
   writes to the bucket through the Worker; never share it or put it in Git.

   ```sh
   npx --yes wrangler@4.164.0 deploy --config korsary2-next/recomp/web/cloudflare/wrangler.toml
   export PORT_UPLOAD_TOKEN="$(node -e "console.log(require('node:crypto').randomBytes(32).toString('hex'))")"
   printf '%s' "$PORT_UPLOAD_TOKEN" | npx --yes wrangler@4.164.0 secret put UPLOAD_TOKEN --config korsary2-next/recomp/web/cloudflare/wrangler.toml
   ```

   By default, if no `PASSWORD` secret and no `ALLOW_PUBLIC=1` variable
   are set, reads return 401. Uploads require `UPLOAD_TOKEN`. If reusing an
   existing Worker, audit its settings and secrets first; `PASSWORD` takes
   precedence over `ALLOW_PUBLIC` and still requires authentication.

5. Set the HTTPS URL printed by Wrangler, inspect the plan, then upload:

   ```sh
   export K2_WORKER_URL='https://your-worker.your-subdomain.workers.dev'
   node korsary2-next/recomp/web/cloudflare/upload.mjs "$K2_WORKER_URL" --dist distribution --dry-run
   node korsary2-next/recomp/web/cloudflare/upload.mjs "$K2_WORKER_URL" --dist distribution
   ```

   The dry run queries R2 through the Worker and may consume read operations;
   it does not upload. The uploader rejects missing or malformed manifests,
   missing referenced objects, symlinks, and save directories before requests.
   It uploads manifests last, and skips immutable objects only when size and
   SHA-256 match. Uploads never remove old objects: unused versions can consume
   storage over time. Check references and arrange a separate, careful cleanup
   when appropriate. On a multipart failure the uploader attempts to abort its
   own incomplete upload; if the abort request also fails, R2 will eventually
   expire it. If an upload fails, rerun it before opening the site.

6. Publish intentionally, then remove the local token from this shell:

   ```sh
   npx --yes wrangler@4.164.0 deploy --config korsary2-next/recomp/web/cloudflare/wrangler.toml --var ALLOW_PUBLIC:1
   unset PORT_UPLOAD_TOKEN
   ```

   Repeat `--var ALLOW_PUBLIC:1` on future deploys that should be public;
   the versioned default stays closed. After the upload, remove or rotate
   `UPLOAD_TOKEN` in Cloudflare when no more uploads are needed; a later
   upload will need a new matching secret. Never delete the R2 bucket to
   reset a player: game saves are stored in each player's browser by origin.

For the public site, check the deployed URL using the commands below, then test
startup, loading a new location, creating a save and loading it. The Worker and
R2 were tested together only in a local Cloudflare emulator; production billing,
network behaviour, custom domains, and the actual deployed hostname have not
been verified. Monitor Worker requests and R2 operations and storage: the free
allowances are not a guarantee of a zero bill. See
[Workers pricing](https://developers.cloudflare.com/workers/platform/pricing/)
and [R2 pricing](https://developers.cloudflare.com/r2/pricing/).

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
