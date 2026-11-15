/* Потоковый декодер brotli (D1b, PORT_SPECIFICATION.md): WebAssembly-сборка официального декодера Google brotli 1.2.1
   (MIT, web/vendor/brotli: исходники, LICENSE, build.sh, k2br.wasm). У .wasm нет импортов, он не использует eval и сеть.

   `DecompressionStream` браузера brotli не умеет (Chromium 158: TypeError), поэтому страница подгружает этот модуль
   ЛЕНИВО и только если манифест содержит `enc: "br"` (game-transfer.mjs prepareDecoders). Модуль выдаёт
   TransformStream: байты brotli на входе, распакованные байты на выходе — так же, как DecompressionStream.

   Защита (поток приходит от сервера, ему не доверяют так же, как манифесту):
   - `maxOutput` (размер файла из манифеста): как только распакованных байт больше, поток обрывается ошибкой (до
     передачи лишнего потребителю); за один вызов декодера выводится не больше OUT_CHUNK байт, поэтому «бомба» не
     занимает ни память, ни время сверх предела;
   - окно (`maxWindowBits`, по умолчанию 22 = 4 МиБ) читается из первого байта потока (RFC 7932, раздел 9.1) и сверх
     предела отвергается ДО распаковки: память декодера не растёт от потока (куча wasm ограничена и сама, 96 МиБ);
   - конец потока обязателен (усечённый поток = ошибка), байты после конца потока = ошибка;
   - файл .wasm сверяется с SHA-256, зашитым ниже (повреждённый или подменённый декодер не запускается);
   - детерминизм: декодер — чистая функция входа; общего состояния между потоками нет (контекст на поток). */
import { sha256Init, sha256Update, sha256Hex } from './save-protection.mjs';

/** SHA-256 файла vendor/brotli/k2br.wasm (меняется только вместе с пересборкой: `bash web/vendor/brotli/build.sh`). */
export const K2BR_WASM_SHA256 = '612c079c1c7157deebfe63993376d060e425b6fe09c967dec13db6ec14d61bd7';
export const K2BR_WASM_PATH = './vendor/brotli/k2br.wasm';
export const IN_CHUNK = 64 * 1024;
export const OUT_CHUNK = 256 * 1024;
export const DEFAULT_MAX_WINDOW_BITS = 22;

const RESULT_ERROR = 0, RESULT_SUCCESS = 1, RESULT_NEEDS_INPUT = 2;
// BrotliDecoderErrorCode (decode.h): -1..-17 формат потока (испорчен), -21..-30 нехватка памяти, остальное служебное
const describeError = (code) => code <= -1 && code >= -17 ? 'неверный формат потока (код ' + code + ')'
  : code <= -21 && code >= -30 ? 'не хватило памяти декодера (код ' + code + ')' : 'код ' + code;

/** Ошибка распаковки: поток испорчен, усечён, больше манифеста или требует слишком большого окна. */
export class BrotliDecodeError extends Error {
  constructor(message) { super(message); this.name = 'BrotliDecodeError'; }
}

/** Окно потока brotli (lgwin) по первым битам: RFC 7932, 9.1. Возвращает число 10..24 или 0 для «большого окна»
 *  (расширение, которое этот декодер не включает: такой поток отвергается). */
export function brotliWindowBits(firstByte) {
  if ((firstByte & 1) === 0) return 16;
  const n = (firstByte >> 1) & 7;
  if (n !== 0) return 17 + n;
  const m = (firstByte >> 4) & 7;
  if (m === 0) return 17;
  if (m === 1) return 0;
  return 8 + m;
}

/** Читает файл .wasm по умолчанию: fetch рядом с модулем в браузере, fs в Node. */
export async function defaultLoadWasm(url = new URL(K2BR_WASM_PATH, import.meta.url)) {
  if (url.protocol === 'file:') {
    const fs = await import('node:fs/promises');
    return new Uint8Array(await fs.readFile(url));
  }
  const res = await fetch(url, { cache: 'no-cache' });
  if (!res.ok) throw new Error(`декодер brotli: HTTP ${res.status} (${url.pathname})`);
  return new Uint8Array(await res.arrayBuffer());
}

/** Загружает и проверяет декодер: `loadWasm()` -> Uint8Array. Возвращает объект с `createStream`. */
export async function loadBrotliDecoder({ loadWasm = defaultLoadWasm, expectedSha256 = K2BR_WASM_SHA256 } = {}) {
  if (typeof WebAssembly !== 'object' || typeof WebAssembly.instantiate !== 'function')
    throw new Error('браузер без WebAssembly: декодер brotli недоступен');
  const bytes = await loadWasm();
  const st = sha256Init();
  sha256Update(st, bytes);
  if (sha256Hex(st) !== expectedSha256) throw new Error('декодер brotli: SHA-256 файла .wasm не совпадает; обновите страницу игры');
  const { instance } = await WebAssembly.instantiate(bytes, {});     // у модуля нет импортов
  return makeDecoder(instance.exports);
}

function makeDecoder(x) {
  const registry = typeof FinalizationRegistry === 'function'
    ? new FinalizationRegistry((holder) => { if (holder.ctx) { x.k2br_close(holder.ctx); holder.ctx = 0; } }) : null;

  /** TransformStream brotli -> байты. Опции: maxOutput (байт; по умолчанию без предела — задавайте всегда),
   *  maxWindowBits (по умолчанию 22). Контекст декодера создаётся при первом чанке и освобождается при конце потока,
   *  ошибке и отмене. */
  function createStream({ maxOutput = Infinity, maxWindowBits = DEFAULT_MAX_WINDOW_BITS } = {}) {
    const holder = { ctx: 0 };
    // Retained by both stream algorithms, even if callers only retain readers/writers.
    const lifetime = { active: true };
    let total = 0, started = false, finished = false, stopped = false;
    let resumeOutput = null;
    const resume = () => { const resolve = resumeOutput; resumeOutput = null; resolve?.(); };
    const close = () => { if (holder.ctx) { x.k2br_close(holder.ctx); holder.ctx = 0; } };
    const fail = (msg) => { close(); throw new BrotliDecodeError(msg); };
    const mem = (ptr, n) => new Uint8Array(x.memory.buffer, ptr, n);    // буфер может смениться при росте памяти
    function open() {
      holder.ctx = x.k2br_open(IN_CHUNK, OUT_CHUNK);
      if (!holder.ctx) throw new BrotliDecodeError('декодер brotli: не удалось выделить память');
    }
    const ts = new TransformStream({
      async transform(chunk, controller) {
        if (!lifetime.active) throw new BrotliDecodeError('поток brotli недоступен');
        if (stopped) throw new BrotliDecodeError('поток brotli отменён');
        if (finished) { if (chunk.length) fail('после конца потока brotli есть лишние байты'); return; }
        if (!chunk.length) return;
        if (!started) {
          started = true;
          const bits = brotliWindowBits(chunk[0]);
          if (bits === 0 || bits > maxWindowBits) fail(`окно потока brotli больше допустимого (${bits || 'большое'} бит, максимум ${maxWindowBits})`);
          open();
        }
        for (let off = 0; off < chunk.length;) {
          const n = Math.min(IN_CHUNK, chunk.length - off);
          mem(x.k2br_in_ptr(holder.ctx), n).set(chunk.subarray(off, off + n));
          x.k2br_feed(holder.ctx, n);
          for (;;) {
            const r = x.k2br_run(holder.ctx);
            const produced = x.k2br_produced(holder.ctx);
            if (produced) {
              total += produced;
              if (total > maxOutput) fail(`распакованные данные длиннее ожидаемого (${maxOutput} байт)`);
              // Do not inflate a whole compressed chunk into an unbounded queue.
              // A single output block is handed to the consumer before decoding more.
              const ready = new Promise((resolve) => { resumeOutput = resolve; });
              controller.enqueue(mem(x.k2br_out_ptr(holder.ctx), produced).slice());
              await ready;
              if (stopped) throw new BrotliDecodeError('поток brotli отменён');
            }
            if (r === RESULT_ERROR) {
              const code = x.k2br_error(holder.ctx);
              fail(`поток brotli испорчен: ${describeError(code)}`);
            }
            if (r === RESULT_SUCCESS) {
              finished = true;
              if (x.k2br_avail_in(holder.ctx) > 0 || off + n < chunk.length) fail('после конца потока brotli есть лишние байты');
              close();
              break;
            }
            if (r === RESULT_NEEDS_INPUT) break;
          }
          off += n;
        }
      },
      flush() {
        if (!finished) { close(); throw new BrotliDecodeError('поток brotli оборван раньше конца'); }
      },
      cancel() { close(); },
    });
    // Some Streams implementations (including Node 18) do not invoke the
    // transformer's cancel hook. Intercept both ends so native decoder memory
    // is released immediately on cancellation or abort, without waiting for GC.
    const input = ts.writable.getWriter();
    const output = ts.readable.getReader();
    let outputController;
    const writable = new WritableStream({
      start(controller) {
        // AbortSignal fires immediately, even if an input.write is blocked on
        // readable backpressure; cancelling output releases that write.
        controller.signal?.addEventListener('abort', () => {
          stopped = true;
          close();
          resume();
          outputController?.error(controller.signal.reason);
          output.cancel(controller.signal.reason).catch(() => {});
        }, { once: true });
      },
      async write(chunk) { if (!lifetime.active) throw new BrotliDecodeError('поток brotli недоступен'); try { await input.write(chunk); } catch (e) { close(); throw e; } },
      async close() { try { await input.close(); } catch (e) { close(); throw e; } },
      async abort(reason) { stopped = true; close(); resume(); await input.abort(reason); },
    });
    const readable = new ReadableStream({
      start(controller) { outputController = controller; },
      async pull(controller) {
        if (!lifetime.active) throw new BrotliDecodeError('поток brotli недоступен');
        try {
          const result = await output.read();
          if (result.done) controller.close(); else { controller.enqueue(result.value); resume(); }
        } catch (e) { close(); throw e; }
      },
      async cancel(reason) { stopped = true; close(); resume(); await output.cancel(reason); },
    }, { highWaterMark: 0 });
    // Stream algorithms keep lifetime reachable until both ends are abandoned.
    registry?.register(lifetime, holder);
    return { readable, writable };
  }
  return { createStream, version: x.k2br_version(), heapUsed: () => x.k2br_heap_used(), memory: x.memory };
}
