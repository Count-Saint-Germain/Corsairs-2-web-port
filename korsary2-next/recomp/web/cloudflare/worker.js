// Cloudflare Worker serving the browser build of the game from an R2 bucket.
//
// Every response carries COOP/COEP (threads need SharedArrayBuffer). Reads need HTTP basic auth with
// the PASSWORD secret (any user name). Range requests are supported so the page can resume a
// download. Uploads go through /_upload/ with the UPLOAD_TOKEN secret, in parts, because single files
// (Data/data.gob is 341 MB) exceed what a request or `wrangler r2 object put` accepts.
//
// Netplay rooms (/netplay/<code>, WebSocket) are a Durable Object that relays lobby events and lockstep
// inputs between up to 4 peers (see NetplayRoom below and host/netplay.c). Browsers don't reliably send
// basic auth on WebSocket upgrades, so the page first gets a short-lived ticket from /_netplay_ticket
// (behind the password) and presents it on the upgrade.
//
// Bucket layout = the dist/ folder from make_dist.py: index.html, port.js, audio-worklet.js,
// build/game.{js,wasm}, game/manifest.json, game/<files>. With make_dist.py --overlay-dir the language overlay (docs/overlay-e1.md)
// is a second tree of the same shape under game-en/ (game-en/manifest.json, game-en/<files>, game-en/_k2pack/*.pack): its objects get the
// same caching, no-transform and Range handling as game/'s.

// .mjs must be a JavaScript MIME type or the browser refuses to load the page's ES modules
// (save-owner.mjs, video-player.mjs, ...); .mp4 is the video bridge's stream.
const TYPES = {
  html: 'text/html; charset=utf-8', js: 'text/javascript; charset=utf-8', mjs: 'text/javascript; charset=utf-8',
  wasm: 'application/wasm', json: 'application/json', png: 'image/png', txt: 'text/plain; charset=utf-8',
  mp4: 'video/mp4',
};

const ISOLATION = {
  'Cross-Origin-Opener-Policy': 'same-origin',
  'Cross-Origin-Embedder-Policy': 'require-corp',
  'Cross-Origin-Resource-Policy': 'same-origin',
  'X-Robots-Tag': 'noindex',
};

function timingSafeEqual(a, b) {
  const x = new TextEncoder().encode(a), y = new TextEncoder().encode(b);
  if (x.length !== y.length) return false;
  let d = 0;
  for (let i = 0; i < x.length; i++) d |= x[i] ^ y[i];
  return d === 0;
}

function authorized(request, env) {
  // N2 (docs/AUDIT_STATUS_2026-11-12.md): fail-closed. A missing PASSWORD secret used to open the whole game data to
  // everyone; now it closes it. Open access exists only as an explicit opt-in: ALLOW_PUBLIC=1 (a variable, not a secret).
  if (!env.PASSWORD) return env.ALLOW_PUBLIC === '1';
  const h = request.headers.get('Authorization') || '';
  if (!h.startsWith('Basic ')) return false;
  let decoded = '';
  try { decoded = atob(h.slice(6)); } catch { return false; }
  return timingSafeEqual(decoded.slice(decoded.indexOf(':') + 1), env.PASSWORD);
}

function respond(body, status, extra = {}) {
  return new Response(body, { status, headers: { ...ISOLATION, ...extra } });
}

// `game/` and the language overlay's `game-en/` (docs/overlay-e1.md) are both game trees: their objects are content-addressed by the
// manifest next to them. Returns the key relative to its tree, or null for anything else (page, build, videos).
const GAME_TREES = ['game/', 'game-en/'];
function gameTreeKey(key) {
  for (const tree of GAME_TREES) if (key.startsWith(tree)) return key.slice(tree.length);
  return null;
}

async function serve(request, env, url) {
  let key = decodeURIComponent(url.pathname.slice(1));
  if (key === '' || key.endsWith('/')) key += 'index.html';
  if (key === 'robots.txt') return respond('User-agent: *\nDisallow: /\n', 200, { 'Content-Type': TYPES.txt });
  const obj = await env.BUCKET.get(key, { range: request.headers, onlyIf: request.headers });
  if (!obj) return respond('Not found', 404, { 'Content-Type': TYPES.txt });
  const headers = new Headers(ISOLATION);
  obj.writeHttpMetadata(headers);
  headers.set('Content-Type', TYPES[key.split('.').pop()] || 'application/octet-stream');
  headers.set('ETag', obj.httpEtag);
  headers.set('Accept-Ranges', 'bytes');
  // the page and build may change on redeploy: revalidate; game files are content-addressed by the manifest
  const rel = gameTreeKey(key);
  headers.set('Cache-Control', rel !== null && rel !== 'manifest.json' ? 'private, max-age=86400' : 'no-cache');
  // game/<path>.gz objects are gzip streams and game/<path>.br objects brotli streams (D1b, docs/compression-d1b.md) the page
  // unpacks itself (docs/compression-d1.md), and
  // game/_k2pack/*.pack objects are transfer packs the page cuts into files (docs/install-requests-d3.md): both are
  // served as opaque bytes, with no Content-Encoding and with no-transform so no intermediary recompresses them.
  // Packs are named after their content, so the day of private caching is safe; the page reads them with Range
  // (a resync fetches only the byte ranges holding missing files), which this Worker answers with 206.
  if (rel !== null && (key.endsWith('.gz') || key.endsWith('.br') || (rel.startsWith('_k2pack/') && key.endsWith('.pack')))) {
    headers.delete('Content-Encoding');
    headers.set('Cache-Control', headers.get('Cache-Control') + ', no-transform');
  }
  if (!('body' in obj)) return new Response(null, { status: 304, headers });   // onlyIf (If-None-Match) matched
  let status = 200;
  if (obj.range && request.headers.has('Range')) {
    const offset = obj.range.offset ?? (obj.size - obj.range.suffix);
    const length = obj.range.length ?? (obj.size - offset);
    headers.set('Content-Range', `bytes ${offset}-${offset + length - 1}/${obj.size}`);
    headers.set('Content-Length', String(length));
    status = 206;
  } else {
    headers.set('Content-Length', String(obj.size));
  }
  return new Response(request.method === 'HEAD' ? null : obj.body, { status, headers });
}

// /_upload/<key>                         PUT  whole object (small files)
// /_upload/<key>?mpu=create              POST -> { uploadId }
// /_upload/<key>?uploadId=..&part=N      PUT  -> { partNumber, etag }
// /_upload/<key>?uploadId=..&complete=1  POST body [{ partNumber, etag }]
// /_upload/<key>?head=1                  GET  -> { size, sha256 } or 404 (lets the uploader skip finished files;
//                                              sha256 is what the uploader declared when it stored the object, or
//                                              null for objects stored without one)
// A PUT or mpu=create may carry the X-Content-SHA256 header (64 hex): it is stored as the object's custom
// metadata, so the uploader can tell an object with the same size but other content from a finished one.
// A whole-object PUT is also verified by R2 against that hash; multipart parts cannot be, so there the stored
// value is the uploader's declaration (HTTPS protects the transfer).
async function upload(request, env, url) {
  if (!env.UPLOAD_TOKEN || request.headers.get('X-Upload-Token') !== env.UPLOAD_TOKEN) return respond('Forbidden', 403);
  const key = decodeURIComponent(url.pathname.slice('/_upload/'.length));
  const q = url.searchParams;
  const json = (v) => respond(JSON.stringify(v), 200, { 'Content-Type': TYPES.json });
  const declared = request.headers.get('X-Content-SHA256');
  if (declared !== null && !/^[0-9a-f]{64}$/.test(declared)) return respond('Bad X-Content-SHA256', 400);
  const meta = declared ? { customMetadata: { sha256: declared } } : {};
  if (q.has('head')) {
    const h = await env.BUCKET.head(key);
    return h ? json({ size: h.size, sha256: h.customMetadata?.sha256 ?? null }) : respond('Not found', 404);
  }
  if (q.get('mpu') === 'create') {
    const mpu = await env.BUCKET.createMultipartUpload(key, meta);
    return json({ uploadId: mpu.uploadId });
  }
  if (q.has('uploadId')) {
    const mpu = env.BUCKET.resumeMultipartUpload(key, q.get('uploadId'));
    if (q.has('part')) {
      const part = await mpu.uploadPart(Number(q.get('part')), request.body);
      return json({ partNumber: part.partNumber, etag: part.etag });
    }
    if (q.has('complete')) {
      const obj = await mpu.complete(await request.json());
      return json({ size: obj.size, sha256: obj.customMetadata?.sha256 ?? null });
    }
    if (q.has('abort')) { await mpu.abort(); return json({ aborted: true }); }
  }
  if (request.method === 'PUT') {
    const obj = await env.BUCKET.put(key, request.body, declared ? { ...meta, sha256: declared } : undefined);
    return json({ size: obj.size, sha256: obj.customMetadata?.sha256 ?? null });
  }
  return respond('Bad request', 400);
}

// ------------------------------------------------------------------ netplay

const TICKET_SECONDS = 3600;

async function hmac(secret, text) {
  const key = await crypto.subtle.importKey('raw', new TextEncoder().encode(secret), { name: 'HMAC', hash: 'SHA-256' },
    false, ['sign']);
  const sig = await crypto.subtle.sign('HMAC', key, new TextEncoder().encode(text));
  return [...new Uint8Array(sig)].map((b) => b.toString(16).padStart(2, '0')).join('');
}

async function ticketValid(env, ticket) {
  if (!env.PASSWORD) return false;   // an empty HMAC key would let anyone mint tickets
  const [exp, sig] = String(ticket || '').split('.');
  if (!exp || !sig || Number(exp) < Date.now() / 1000) return false;
  return timingSafeEqual(sig, await hmac(env.PASSWORD, `netplay:${exp}`));
}

// ICE servers for the players' direct WebRTC channels: Cloudflare's TURN service (secrets TURN_KEY_ID and
// TURN_KEY_API_TOKEN) relays a direct channel through the data center nearest each player when the two
// can't reach each other directly (symmetric NATs, firewalls), which beats going through the room when the
// room is far away. Credentials last a day, longer than a game.
async function iceServers(env) {
  const stun = [{ urls: 'stun:stun.cloudflare.com:3478' }];
  if (!env.TURN_KEY_ID || !env.TURN_KEY_API_TOKEN) return stun;
  const res = await fetch(`https://rtc.live.cloudflare.com/v1/turn/keys/${env.TURN_KEY_ID}/credentials/generate-ice-servers`, {
    method: 'POST', body: JSON.stringify({ ttl: 86400 }),
    headers: { Authorization: `Bearer ${env.TURN_KEY_API_TOKEN}`, 'Content-Type': 'application/json' },
  });
  if (!res.ok) throw new Error(`TURN credentials: HTTP ${res.status} ${await res.text()}`);
  const { iceServers: servers } = await res.json();
  // browsers block port 53, and trying those addresses only slows ICE down (as Cloudflare's docs advise)
  return [servers].flat().map((s) => ({ ...s, urls: [s.urls].flat().filter((u) => !/:53(\?|$)/.test(u)) }))
    .filter((s) => s.urls.length);
}

const MAX_PLAYERS = 4;
const REJOIN_GRACE_MS = 15000;

// One room: the first peer to join hosts. Peers say hello (name, game build), the host starts the session
// (fixing the player count and input delay), then every input/hash batch a peer sends is relayed to the
// others. Uses WebSocket hibernation; the lobby lives in the sockets' attachments and durable storage.
export class NetplayRoom {
  constructor(ctx) { this.ctx = ctx; }

  async fetch(request) {
    if (request.headers.get('Upgrade') !== 'websocket') return new Response('Expected a WebSocket', { status: 426 });
    const [client, server] = Object.values(new WebSocketPair());
    this.ctx.acceptWebSocket(server);
    // the data center this peer reaches Cloudflare through, shown in the lobby next to the room's own
    server.serializeAttachment({ slot: -1, name: '', version: '', rtt: 0, via: String(request.cf?.colo || '') });
    this.where();
    return new Response(null, { status: 101, webSocket: client });
  }

  // The data center this room runs in (its own outgoing requests leave from there), once per instance.
  where() {
    this.colo ??= fetch('https://cloudflare.com/cdn-cgi/trace').then((r) => r.text())
      .then((t) => /^colo=(\w+)/m.exec(t)?.[1] || '?').catch(() => '?');
    return this.colo;
  }

  peers() {
    return this.ctx.getWebSockets().map((ws) => ({ ws, ...ws.deserializeAttachment() })).filter((p) => p.slot >= 0);
  }

  send(ws, msg) { try { ws.send(JSON.stringify(msg)); } catch { /* closed */ } }

  async lobby() {
    const started = (await this.ctx.storage.get('started')) || null;
    const players = this.peers().map(({ slot, name, version, rtt, p2p, via }) => ({ slot, name, version, rtt, p2p: p2p || {}, via }))
      .sort((a, b) => a.slot - b.slot);
    const colo = await this.where();
    for (const p of this.peers()) this.send(p.ws, { t: 'lobby', you: p.slot, host: p.slot === 0, players, started, colo });
  }

  async webSocketMessage(ws, data) {
    let msg;
    try { msg = JSON.parse(data); } catch { return; }
    const me = ws.deserializeAttachment();
    if (msg.t === 'hello' && me.slot < 0) {
      if (await this.ctx.storage.get('started')) { this.send(ws, { t: 'error', msg: 'This game has already started.' }); ws.close(4000, 'started'); return; }
      const used = new Set(this.peers().map((p) => p.slot));
      let slot = 0;
      while (used.has(slot)) slot++;
      if (slot >= MAX_PLAYERS) { this.send(ws, { t: 'error', msg: 'The room is full.' }); ws.close(4001, 'full'); return; }
      ws.serializeAttachment({ ...me, slot, name: String(msg.name || `Player ${slot + 1}`).slice(0, 24), version: String(msg.version || ''), rtt: 0 });
      await this.lobby();
      return;
    }
    if (msg.t === 'ping') { this.send(ws, { t: 'pong', ts: msg.ts }); return; }
    if (msg.t === 'rejoin' && me.slot < 0) {   // a player of a running game whose connection dropped
      const started = await this.ctx.storage.get('started');
      const slot = Number(msg.slot);
      const away = (await this.ctx.storage.get('away')) || {};
      if (!started || !(slot in away) || this.peers().some((p) => p.slot === slot)) {
        this.send(ws, { t: 'error', msg: 'Could not rejoin the game.' }); ws.close(4002, 'rejoin'); return;
      }
      ws.serializeAttachment({ ...away[slot], slot });
      delete away[slot];
      await this.ctx.storage.put('away', away);
      this.send(ws, { t: 'rejoined', slot });
      return;
    }
    if (me.slot < 0) return;
    if (msg.t === 'rtt') {   // a peer's round trip to this room, shown in the lobby and used for the auto delay
      ws.serializeAttachment({ ...me, rtt: Math.max(0, Math.min(5000, Math.round(Number(msg.ms) || 0))) });
      if (!(await this.ctx.storage.get('started'))) await this.lobby();
      return;
    }
    if (msg.t === 'start' && me.slot === 0 && !(await this.ctx.storage.get('started'))) {
      const peers = this.peers();
      const versions = new Set(peers.map((p) => p.version));
      if (versions.size > 1) { this.send(ws, { t: 'error', msg: 'Players have different game builds or files; everyone must reload the page.' }); return; }
      const slots = peers.map((p) => p.slot).sort((a, b) => a - b);
      if (slots.some((s, i) => s !== i)) { this.send(ws, { t: 'error', msg: 'Waiting for the player list to settle; try again.' }); return; }
      const started = { players: peers.length, delay: Math.max(2, Math.min(30, Number(msg.delay) || 6)) };
      await this.ctx.storage.put('started', started);
      for (const p of peers) this.send(p.ws, { t: 'start', ...started, you: p.slot });
      return;
    }
    if (msg.t === 'sig') {   // WebRTC signaling (offers, answers, ICE candidates) to one peer
      for (const p of this.peers()) if (p.slot === msg.to) this.send(p.ws, { t: 'sig', from: me.slot, data: msg.data });
      return;
    }
    if (msg.t === 'p2p') {   // a peer's direct round trips to the others, for the auto delay
      const p2p = {};
      for (const [k, v] of Object.entries(msg.rtt || {})) p2p[Number(k)] = Math.max(0, Math.min(5000, Math.round(Number(v) || 0)));
      ws.serializeAttachment({ ...me, p2p });
      if (!(await this.ctx.storage.get('started'))) await this.lobby();
      return;
    }
    if (msg.t === 'in') {   // relay as-is to everyone else
      for (const p of this.peers()) if (p.slot !== me.slot) try { p.ws.send(data); } catch { /* closed */ }
    }
  }

  async webSocketClose(ws, code, reason) {
    try { ws.close(code === 1005 || code === 1006 ? 1000 : code, reason); } catch { /* already closed */ }   // complete the handshake
    await this.left(ws);
  }
  async webSocketError(ws) { await this.left(ws); }

  // Lobby: a player who disconnects is gone. In a running game the others are only told after a grace
  // period, so a player whose connection dropped can rejoin (their game keeps its slot meanwhile and the
  // others just wait in lockstep).
  async left(ws) {
    const me = ws.deserializeAttachment();
    if (me.slot < 0) return;
    ws.serializeAttachment({ ...me, slot: -1 });
    const started = await this.ctx.storage.get('started');
    if (!started) {
      for (const p of this.peers()) this.send(p.ws, { t: 'left', slot: me.slot });
      await this.lobby();
      if (this.peers().length === 0) await this.ctx.storage.deleteAll();   // empty room: reusable
      return;
    }
    const away = (await this.ctx.storage.get('away')) || {};
    away[me.slot] = { ...me, at: Date.now() };
    await this.ctx.storage.put('away', away);
    await this.ctx.storage.setAlarm(Date.now() + REJOIN_GRACE_MS);
  }

  async alarm() {
    const away = (await this.ctx.storage.get('away')) || {};
    let next = 0;
    for (const [slot, a] of Object.entries(away)) {
      if (Date.now() - a.at >= REJOIN_GRACE_MS) {
        for (const p of this.peers()) this.send(p.ws, { t: 'left', slot: Number(slot) });
        delete away[slot];
      } else next = Math.max(next, a.at + REJOIN_GRACE_MS);
    }
    await this.ctx.storage.put('away', away);
    if (next) await this.ctx.storage.setAlarm(next);
    else if (this.peers().length === 0) await this.ctx.storage.deleteAll();   // everyone gone: reusable
  }
}

// Durable Object location hints (developers.cloudflare.com/durable-objects/reference/data-location/)
const REGIONS = ['wnam', 'enam', 'sam', 'weur', 'eeur', 'apac', 'apac-ne', 'apac-se', 'oc', 'afr', 'me'];

function nearestRegion(cf) {
  const lon = Number(cf?.longitude);
  switch (cf?.continent) {
    case 'NA': return lon < -100 ? 'wnam' : 'enam';
    case 'SA': return 'sam';
    case 'EU': return lon > 20 ? 'eeur' : 'weur';
    case 'AF': return 'afr';
    case 'OC': return 'oc';
    case 'AS': return cf?.country && ['AE', 'SA', 'QA', 'BH', 'KW', 'OM', 'IL', 'JO', 'TR'].includes(cf.country) ? 'me' : 'apac';
    default: return undefined;
  }
}

async function netplay(request, env, url) {
  const code = url.pathname.slice('/netplay/'.length).toUpperCase();
  if (!/^[A-Z0-9]{4,12}$/.test(code)) return respond('Bad room code', 400);
  if (!(await ticketValid(env, url.searchParams.get('ticket')))) return respond('Forbidden', 403);
  // Lockstep waits for the slowest path, so the room should run near the players. A room's location is
  // fixed by the first request that reaches it, so only the host's creating connection (create=1) asks for
  // one: the region it picked, or by default the one nearest to it. Cloudflare treats the hint as a
  // preference: Durable Objects don't run in Africa or the Middle East, so those land in a nearby region.
  let hint;
  if (url.searchParams.get('create') === '1') {
    const pick = url.searchParams.get('region') || 'auto';
    if (pick !== 'auto' && !REGIONS.includes(pick)) return respond('Bad region', 400);
    hint = pick !== 'auto' ? pick : nearestRegion(request.cf);
  }
  return env.ROOMS.get(env.ROOMS.idFromName(code), hint ? { locationHint: hint } : {}).fetch(request);
}

export default {
  async fetch(request, env) {
    const url = new URL(request.url);
    if (url.pathname.startsWith('/_upload/')) return upload(request, env, url);
    if (url.pathname.startsWith('/netplay/')) return netplay(request, env, url);
    if (request.method !== 'GET' && request.method !== 'HEAD') return respond('Method not allowed', 405);
    if (!authorized(request, env))
      return respond('Password required', 401, { 'WWW-Authenticate': 'Basic realm="Game", charset="UTF-8"' });
    if (url.pathname === '/_netplay_ticket') {
      if (!env.PASSWORD) return respond('Netplay needs the PASSWORD secret', 403);
      const exp = Math.floor(Date.now() / 1000) + TICKET_SECONDS;
      const ticket = `${exp}.${await hmac(env.PASSWORD, `netplay:${exp}`)}`;
      return respond(JSON.stringify({ ticket, iceServers: await iceServers(env) }), 200,
        { 'Content-Type': TYPES.json, 'Cache-Control': 'no-store' });
    }
    return serve(request, env, url);
  },
};
