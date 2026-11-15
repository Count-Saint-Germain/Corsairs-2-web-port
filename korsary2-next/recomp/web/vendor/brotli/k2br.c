/* k2br: потоковый декодер brotli для WebAssembly без импортов (D1b, docs/compression-d1b.md).

   Это НЕ часть Google brotli: тонкая обёртка и крошечный распределитель памяти, чтобы собрать официальный декодер
   (c/dec, c/common из brotli 1.2.1, файлы не изменены) в один автономный .wasm, у которого нет ни одного импорта,
   нет libc, нет eval и нет JS-обвязки. Сборка: build.sh (clang из emsdk, без emcc).

   Модель: один «контекст» на один поток brotli. JS кладёт сжатые байты в буфер ввода (k2br_in_ptr), вызывает
   k2br_feed(n) и k2br_run() по кругу, забирая распакованные байты из буфера вывода (k2br_out_ptr, k2br_produced)
   до результата NEEDS_INPUT/SUCCESS/ERROR. Ограничение размера вывода и распаковки «бомбы» — на стороне JS
   (brotli-decoder.mjs): за один вызов k2br_run выводится не больше out_cap байт.

   Память: куча растёт memory.grow до K2BR_HEAP_MAX; сверх лимита распределитель возвращает NULL, и декодер
   останавливается с ошибкой BROTLI_DECODER_ERROR_ALLOC_*: поток с окном больше разрешённого не может занять память. */
#include <stddef.h>
#include <stdint.h>
#include <brotli/decode.h>

#define K2BR_EXPORT __attribute__((used, visibility("default")))
#ifndef K2BR_HEAP_MAX
#define K2BR_HEAP_MAX (96u << 20)          /* жёсткий предел кучи, байт */
#endif
#define PAGE 65536u

/* ---- memcpy/memmove/memset/memcmp: clang и brotli вызывают их по имени; без libc определяем сами
   (с bulk-memory компилятор сам ставит memory.copy/memory.fill, эти циклы тогда почти не используются) ---- */
void* memcpy(void* restrict d, const void* restrict s, size_t n) {
  unsigned char* a = d; const unsigned char* b = s;
  while (n--) *a++ = *b++;
  return d;
}
void* memmove(void* d, const void* s, size_t n) {
  unsigned char* a = d; const unsigned char* b = s;
  if (a < b) { while (n--) *a++ = *b++; }
  else { a += n; b += n; while (n--) *--a = *--b; }
  return d;
}
void* memset(void* d, int c, size_t n) {
  unsigned char* a = d;
  while (n--) *a++ = (unsigned char)c;
  return d;
}
int memcmp(const void* x, const void* y, size_t n) {
  const unsigned char* a = x; const unsigned char* b = y;
  for (; n; n--, a++, b++) if (*a != *b) return *a < *b ? -1 : 1;
  return 0;
}

/* ---- распределитель: неявный список блоков, first-fit, слияние соседних свободных при обходе ----
   Блок: 16-байтный заголовок {uint32 размер блока вместе с заголовком; uint32 флаг занят; 8 байт запас до
   выравнивания в 16}; данные идут сразу за заголовком, выровнены на 16. */
typedef struct Blk { uint32_t size; uint32_t used; uint32_t pad0, pad1; } Blk;
extern unsigned char __heap_base;
static uint8_t* heap_lo;
static uint32_t heap_len;                   /* занято под блоки (обходится от heap_lo) */
static uint32_t heap_cap;                   /* сколько байт кучи уже есть в памяти */

static int heap_grow_to(uint32_t need) {
  if (need <= heap_cap) return 1;
  if (need > K2BR_HEAP_MAX) return 0;
  uint32_t have_pages = (uint32_t)__builtin_wasm_memory_size(0);
  uint32_t lo = (uint32_t)(uintptr_t)heap_lo;
  uint32_t want_pages = (lo + need + PAGE - 1) / PAGE;
  if (want_pages > have_pages && __builtin_wasm_memory_grow(0, want_pages - have_pages) == (size_t)-1) return 0;
  heap_cap = want_pages * PAGE - lo;
  if (heap_cap > K2BR_HEAP_MAX) heap_cap = K2BR_HEAP_MAX;
  return need <= heap_cap;
}

void* malloc(size_t n) {
  if (!heap_lo) {
    uintptr_t lo = ((uintptr_t)&__heap_base + 15u) & ~(uintptr_t)15u;
    heap_lo = (uint8_t*)lo;
    uint32_t have = (uint32_t)__builtin_wasm_memory_size(0) * PAGE;
    heap_cap = have > lo ? have - (uint32_t)lo : 0;
  }
  if (n == 0) n = 1;
  if (n > K2BR_HEAP_MAX) return 0;
  uint32_t need = (((uint32_t)n + 15u) & ~15u) + (uint32_t)sizeof(Blk);
  uint32_t pos = 0;
  Blk* tail = 0;                            /* последний блок кучи, если он свободен: растянем его, а не оставим дыру */
  while (pos < heap_len) {
    Blk* b = (Blk*)(heap_lo + pos);
    if (!b->used) {
      while (pos + b->size < heap_len && !((Blk*)(heap_lo + pos + b->size))->used) b->size += ((Blk*)(heap_lo + pos + b->size))->size;
      if (b->size >= need) {
        if (b->size >= need + (uint32_t)sizeof(Blk) + 16u) {
          Blk* rest = (Blk*)(heap_lo + pos + need);
          rest->size = b->size - need; rest->used = 0;
          b->size = need;
        }
        b->used = 1;
        return (uint8_t*)b + sizeof(Blk);
      }
      if (pos + b->size == heap_len) tail = b;
    }
    pos += b->size;
  }
  if (tail) {
    uint32_t extra = need - tail->size;
    if (!heap_grow_to(heap_len + extra)) return 0;
    tail->size = need; tail->used = 1;
    heap_len += extra;
    return (uint8_t*)tail + sizeof(Blk);
  }
  if (!heap_grow_to(heap_len + need)) return 0;
  Blk* b = (Blk*)(heap_lo + heap_len);
  b->size = need; b->used = 1;
  heap_len += need;
  return (uint8_t*)b + sizeof(Blk);
}

void free(void* p) {
  if (!p) return;
  Blk* b = (Blk*)((uint8_t*)p - sizeof(Blk));
  b->used = 0;
}

/* ---- контекст потока ---- */
typedef struct {
  BrotliDecoderState* st;
  uint8_t* in;
  uint8_t* out;
  uint32_t in_cap, out_cap;
  const uint8_t* next_in;
  size_t avail_in;
  size_t produced;
  int32_t err;
} Ctx;

K2BR_EXPORT Ctx* k2br_open(uint32_t in_cap, uint32_t out_cap) {
  if (in_cap == 0 || out_cap == 0 || in_cap > (4u << 20) || out_cap > (4u << 20)) return 0;
  Ctx* c = (Ctx*)malloc(sizeof(Ctx));
  if (!c) return 0;
  c->st = BrotliDecoderCreateInstance(0, 0, 0);
  c->in = (uint8_t*)malloc(in_cap);
  c->out = (uint8_t*)malloc(out_cap);
  if (!c->st || !c->in || !c->out) {
    if (c->st) BrotliDecoderDestroyInstance(c->st);
    free(c->in); free(c->out); free(c);
    return 0;
  }
  c->in_cap = in_cap; c->out_cap = out_cap;
  c->next_in = c->in; c->avail_in = 0; c->produced = 0; c->err = 0;
  return c;
}

K2BR_EXPORT void k2br_close(Ctx* c) {
  if (!c) return;
  BrotliDecoderDestroyInstance(c->st);
  free(c->in); free(c->out); free(c);
}

K2BR_EXPORT uint8_t* k2br_in_ptr(Ctx* c) { return c->in; }
K2BR_EXPORT uint8_t* k2br_out_ptr(Ctx* c) { return c->out; }

/* n байт в буфере ввода готовы к распаковке (n <= in_cap); возвращает 1, иначе 0 */
K2BR_EXPORT uint32_t k2br_feed(Ctx* c, uint32_t n) {
  if (n > c->in_cap) return 0;
  c->next_in = c->in; c->avail_in = n;
  return 1;
}

/* Один вызов декодера: 0 ошибка, 1 конец потока (успех), 2 нужен ещё ввод, 3 буфер вывода заполнен (вызвать снова) */
K2BR_EXPORT uint32_t k2br_run(Ctx* c) {
  size_t avail_out = c->out_cap;
  uint8_t* next_out = c->out;
  BrotliDecoderResult r = BrotliDecoderDecompressStream(c->st, &c->avail_in, &c->next_in, &avail_out, &next_out, 0);
  c->produced = (size_t)(next_out - c->out);
  if (r == BROTLI_DECODER_RESULT_ERROR) c->err = (int32_t)BrotliDecoderGetErrorCode(c->st);
  return (uint32_t)r;
}

K2BR_EXPORT uint32_t k2br_produced(Ctx* c) { return (uint32_t)c->produced; }
K2BR_EXPORT uint32_t k2br_avail_in(Ctx* c) { return (uint32_t)c->avail_in; }
K2BR_EXPORT int32_t k2br_error(Ctx* c) { return c->err; }
K2BR_EXPORT uint32_t k2br_heap_used(void) { return heap_len; }
K2BR_EXPORT uint32_t k2br_version(void) { return BrotliDecoderVersion(); }
