// Workers Static Assets currently ignores Range. Slice the original pack or
// video before sending it; each static asset is limited to 25 MiB.
let sizesPromise;
export default {
  async fetch(request, env) {
    const range = request.headers.get('Range');
    // Always read the full representation. Forwarding Range to the asset
    // service can yield a partial body even when its response is labelled 200.
    let assetRequest = request;
    if (request.method === 'GET' && range) {
      const headers = new Headers(request.headers);
      headers.delete('Range'); headers.delete('If-Range');
      assetRequest = new Request(request,{headers});
    }
    const response = await env.ASSETS.fetch(assetRequest);
    if (request.method !== 'GET' || !range || response.status !== 200 || !response.body) return response;
    const match = /^bytes=(\d*)-(\d*)$/.exec(range);
    const contentLength = response.headers.get('Content-Length');
    let size = contentLength === null ? NaN : Number(contentLength);
    if (!Number.isSafeInteger(size)) {
      // Cloudflare's static asset response may omit Content-Length, including
      // for HEAD. This index is generated from the exact deployed assets.
      sizesPromise ||= env.ASSETS.fetch(new Request(new URL('/_asset-sizes.json',request.url)))
        .then(r => { if (!r.ok) throw Error('Asset size index unavailable'); return r.json(); })
        .catch(e => { sizesPromise = undefined; throw e; });
      try { size = (await sizesPromise)[new URL(request.url).pathname]; } catch { return response; }
    }
    if (!match || (!match[1] && !match[2]) || !Number.isSafeInteger(size) || size < 0) return response;
    let start = match[1] ? Number(match[1]) : Math.max(0, size - Number(match[2]));
    let end = match[1] && match[2] ? Number(match[2]) : size - 1;
    if (!Number.isSafeInteger(start) || !Number.isSafeInteger(end)) return response;
    if (start >= size || end < start || (!match[1] && Number(match[2]) === 0)) {
      await response.body.cancel();
      return new Response(null,{status:416,headers:{'Content-Range':`bytes */${size}`,'Accept-Ranges':'bytes'}});
    }
    end = Math.min(end,size-1);
    const headers = new Headers(response.headers);
    headers.set('Content-Range',`bytes ${start}-${end}/${size}`);
    headers.set('Content-Length',String(end-start+1));
    headers.set('Accept-Ranges','bytes');
    const bytes = await response.arrayBuffer();
    if (bytes.byteLength !== size) return new Response('Static asset size mismatch',{status:502});
    return new Response(bytes.slice(start,end+1),{status:206,headers});
  },
};
