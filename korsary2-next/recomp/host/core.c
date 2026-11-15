/* Host services shared by the Windows API layer: guest heap, handles, path mapping, time. */
#include "win32.h"

#include <ctype.h>
#include <dirent.h>
#include <pthread.h>
#include <stddef.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#ifdef PORT_LAZY_EXPERIMENT
#include "../experimental/lazy-loading/lazy_index.c"
#endif

int g_log;
char g_game_root[1024];
char g_user_root[1024];

/* ------------------------------------------------------------------ guest heap
 * 16-byte headers: [payload capacity][allocation magic][previous block span][requested size].
 * Free blocks are linked doubly through their first two payload words. Physical
 * neighbours are coalesced; reusable blocks are split on a 16-byte boundary.
 */

#define HEAP_LO GUEST_HEAP_BASE
#define HEAP_HI GUEST_HEAP_HI
#define HEAP_MAGIC 0xC07A11C8u
#define NCLASS 256
static pthread_mutex_t g_heap_lock = PTHREAD_MUTEX_INITIALIZER;
static uint32_t g_heap_top = HEAP_LO;
static uint32_t g_heap_last;
static uint32_t g_free[NCLASS + 1];
#ifdef PORT_HEAP_STATS
static void guest_heap_failure_log(uint32_t size, int fatal);   /* ниже, диагностика */
/* Нарастающие счётчики операций (под g_heap_lock): число выделений/освобождений/realloc и крупных (>= 64 KB). */
static uint64_t g_hs_alloc, g_hs_free, g_hs_realloc, g_hs_big_alloc, g_hs_alloc_bytes;
#endif

static uint32_t heap_round(uint32_t size) {
    uint64_t n = ((uint64_t)(size ? size : 1) + 15u) & ~(uint64_t)15u;
    if (n > UINT32_MAX) return 0;
    return (uint32_t)n;
}

static uint32_t heap_class(uint32_t sz) { return sz <= NCLASS * 16u ? sz / 16u : 0; }

/* Caller holds g_heap_lock for every metadata operation below. */
static int heap_valid(uint32_t a) {
    if (a < HEAP_LO + 16u || a >= g_heap_top || (a & 15u) || R32(a - 12) != HEAP_MAGIC)
        return 0;
    uint32_t sz = R32(a - 16);
    return sz >= 16 && !(sz & 15u) && (uint64_t)a + sz <= g_heap_top;
}

static void heap_unlink_free(uint32_t a) {
    uint32_t cls = heap_class(R32(a - 16));
    uint32_t next = R32(a), prev = R32(a + 4);
    if (prev) W32(prev, next); else g_free[cls] = next;
    if (next) W32(next + 4, prev);
}

static void heap_link_free(uint32_t a) {
    uint32_t cls = heap_class(R32(a - 16)), next = g_free[cls];
    W32(a, next); W32(a + 4, 0);
    if (next) W32(next + 4, a);
    g_free[cls] = a;
}

/* Update the next physical block's backwards link after changing a's size. */
static void heap_fix_next(uint32_t a) {
    uint32_t span = R32(a - 16) + 16u;
    uint32_t next = a + span;
    if (next - 16u < g_heap_top) W32(next - 8, span);
    else g_heap_last = a;
}

/* a is removed from any free list and marked allocated. */
static void heap_split(uint32_t a, uint32_t want) {
    uint32_t old = R32(a - 16);
    if (old - want >= 32u) {
        uint32_t remainder = a + want + 16u;
        W32(a - 16, want);
        W32(remainder - 16, old - want - 16u);
        W32(remainder - 12, 0);
        W32(remainder - 8, want + 16u);
        W32(remainder - 4, 0);
        if (remainder + R32(remainder - 16) == g_heap_top) {
            g_heap_top = remainder - 16u;
            g_heap_last = a;
        } else {
            heap_fix_next(remainder);
            heap_link_free(remainder);
        }
    } else {
        heap_fix_next(a);
    }
}

/* A bounded, read-only snapshot used only on a fatal host allocation failure.
 * Do not use the allocator, stdio, or heap-backed formatting in this path. The
 * mutex is tried only after heap_try_alloc has released it. Invalid headers
 * or an invalid top stop the scan; counts then describe just the valid prefix.
 * The scan limit also bounds the time spent on a badly fragmented/corrupt heap. */
#ifndef HEAP_FATAL_SCAN_LIMIT
#define HEAP_FATAL_SCAN_LIMIT 1000000u
#endif
typedef struct {
    uint32_t extent, live_blocks, free_blocks, largest_free, bad, truncated, busy;
    uint64_t live_bytes, free_bytes;
} HeapFatalSnapshot;

static void heap_fatal_snapshot(HeapFatalSnapshot *s) {
    *s = (HeapFatalSnapshot){0};
    if (pthread_mutex_trylock(&g_heap_lock) != 0) { s->busy = 1; return; }
    uint32_t top = g_heap_top;
    if (top < HEAP_LO || top > HEAP_HI || (top & 15u) || (top > HEAP_LO && top - HEAP_LO < 32u)) {
        s->bad = 1;
    } else {
        s->extent = top - HEAP_LO;
        uint32_t p = HEAP_LO + 16u, scanned = 0;
        while (p < top) {
            if (scanned == HEAP_FATAL_SCAN_LIMIT) { s->truncated = 1; break; }
            uint32_t cap = R32(p - 16), magic = R32(p - 12);
            if (cap < 16u || (cap & 15u) || (magic != HEAP_MAGIC && magic != 0) ||
                (uint64_t)p + cap > top || (magic == HEAP_MAGIC && R32(p - 4) > cap)) {
                s->bad = 1;
                break;
            }
            if (magic == HEAP_MAGIC) { s->live_blocks++; s->live_bytes += cap; }
            else {
                s->free_blocks++; s->free_bytes += cap;
                if (cap > s->largest_free) s->largest_free = cap;
            }
            scanned++;
            p += cap + 16u;
        }
        /* The last payload ends at top, so the next payload would be top+16.
         * p == top means a dangling header remains after the last valid block. */
        if (top > HEAP_LO && !s->bad && !s->truncated && (uint64_t)p != (uint64_t)top + 16u)
            s->bad = 1;
    }
    pthread_mutex_unlock(&g_heap_lock);
}

/* Fixed-capacity formatting: integer conversion uses stack bytes only. */
static void heap_fatal_text(char *buf, size_t *pos, size_t limit, const char *text) {
    while (*text && *pos < limit) buf[(*pos)++] = *text++;
}
static void heap_fatal_number(char *buf, size_t *pos, size_t limit, uint64_t value) {
    char digits[20]; size_t n = 0;
    do { digits[n++] = (char)('0' + value % 10u); value /= 10u; } while (value);
    while (n && *pos < limit) buf[(*pos)++] = digits[--n];
}
static void heap_fatal_log(uint32_t size) {
    HeapFatalSnapshot s;
    heap_fatal_snapshot(&s);
    char buf[384]; size_t n = 0;
#define FATAL_TEXT(t) heap_fatal_text(buf, &n, sizeof buf, (t))
#define FATAL_NUM(v) heap_fatal_number(buf, &n, sizeof buf, (v))
    FATAL_TEXT("guest heap exhausted ("); FATAL_NUM(size); FATAL_TEXT(" bytes requested by host)\n");
    FATAL_TEXT("[heapfail] host allocation: extent_bytes="); FATAL_NUM(s.extent);
    FATAL_TEXT(" live_blocks="); FATAL_NUM(s.live_blocks); FATAL_TEXT(" live_bytes="); FATAL_NUM(s.live_bytes);
    FATAL_TEXT(" free_blocks="); FATAL_NUM(s.free_blocks); FATAL_TEXT(" free_bytes="); FATAL_NUM(s.free_bytes);
    FATAL_TEXT(" largest_free_bytes="); FATAL_NUM(s.largest_free);
    FATAL_TEXT(" bad="); FATAL_NUM(s.bad); FATAL_TEXT(" truncated="); FATAL_NUM(s.truncated);
    FATAL_TEXT(" busy="); FATAL_NUM(s.busy); FATAL_TEXT("\n");
#undef FATAL_NUM
#undef FATAL_TEXT
    /* One best-effort write; avoid a loop on a broken or blocked descriptor. */
    (void)write(STDERR_FILENO, buf, n);
}

uint32_t heap_try_alloc(uint32_t size, int zero) {
    uint32_t sz = heap_round(size), a = 0;
    if (!sz) return 0;
    pthread_mutex_lock(&g_heap_lock);
    uint32_t cls = heap_class(sz);
    if (cls && g_free[cls]) a = g_free[cls];
    if (!a && cls) {
        for (uint32_t i = cls + 1; i <= NCLASS; i++)
            if (g_free[i]) { a = g_free[i]; break; }
    }
    if (!a) {
        /* Large blocks share one LIFO list. Taking the first fit can split a
           very large hole even when a closer fit is nearby, needlessly
           fragmenting the browser's 256 MiB guest heap. Search at most 32
           entries starting at the first fit, but never stop before finding
           one: a reusable block further down the list must not be missed. */
        uint32_t best = UINT32_MAX, remaining = 32;
        for (uint32_t p = g_free[0]; p; p = R32(p)) {
            uint32_t capacity = R32(p - 16);
            if (capacity >= sz && capacity < best) {
                a = p; best = capacity;
                if (best == sz) break;
            }
            if (a && --remaining == 0) break;
        }
    }
    if (a) {
        heap_unlink_free(a);
        W32(a - 12, HEAP_MAGIC);
        heap_split(a, sz);
    } else {
        if ((uint64_t)g_heap_top + 16u + sz > HEAP_HI) {
            pthread_mutex_unlock(&g_heap_lock);
#ifdef PORT_HEAP_STATS
            guest_heap_failure_log(size, 0);
#endif
            return 0;
        }
        a = g_heap_top + 16u;
        W32(a - 16, sz);
        W32(a - 12, HEAP_MAGIC);
        W32(a - 8, g_heap_last ? R32(g_heap_last - 16) + 16u : 0);
        W32(a - 4, 0);
        g_heap_top = a + sz;
        g_heap_last = a;
    }
    W32(a - 4, size);
    uint32_t allocated = R32(a - 16);
#ifdef PORT_HEAP_STATS
    g_hs_alloc++; g_hs_alloc_bytes += allocated; if (allocated >= 65536u) g_hs_big_alloc++;
#endif
    pthread_mutex_unlock(&g_heap_lock);
    if (zero) memset(HP(a), 0, allocated);
    return a;
}

/* Internal host callers historically require memory and do not all propagate
   allocation errors. Keep their explicit failure rather than dereferencing a
   guest null pointer; Win32 allocation APIs use heap_try_alloc instead. */
uint32_t heap_alloc(uint32_t size, int zero) {
    uint32_t a = heap_try_alloc(size, zero);
    if (!a) {
        heap_fatal_log(size);
#ifdef PORT_HEAP_STATS
        guest_heap_failure_log(size, 1);
#endif
        abort();
    }
    return a;
}

void heap_free(uint32_t a) {
    if (!a) return;
    pthread_mutex_lock(&g_heap_lock);
    if (!heap_valid(a)) {
        pthread_mutex_unlock(&g_heap_lock);
        LOG("[heap] free of non-heap pointer %08x ignored\n", a);
        return;
    }
    W32(a - 12, 0);
#ifdef PORT_HEAP_STATS
    g_hs_free++;
#endif
    uint32_t sz = R32(a - 16), next = a + sz + 16u;
    if (next - 16u < g_heap_top && R32(next - 12) == 0) {
        heap_unlink_free(next);
        sz += 16u + R32(next - 16);
        W32(a - 16, sz);
    }
    uint32_t previous_span = R32(a - 8);
    if (previous_span) {
        uint32_t prev = a - previous_span;
        if (R32(prev - 12) == 0) {
            heap_unlink_free(prev);
            sz += 16u + R32(prev - 16);
            a = prev;
            W32(a - 16, sz);
        }
    }
    if (a + sz == g_heap_top) {
        previous_span = R32(a - 8);
        g_heap_top = a - 16u;
        g_heap_last = previous_span ? a - previous_span : 0;
    } else {
        heap_fix_next(a);
        heap_link_free(a);
    }
    pthread_mutex_unlock(&g_heap_lock);
}

uint32_t heap_size(uint32_t a) {
    pthread_mutex_lock(&g_heap_lock);
    uint32_t size = heap_valid(a) ? R32(a - 4) : UINT32_MAX;
    pthread_mutex_unlock(&g_heap_lock);
    return size;
}

uint32_t heap_realloc_ex(uint32_t a, uint32_t size, int zero, int in_place) {
    if (!a) return in_place ? 0 : heap_try_alloc(size, zero);
    uint32_t sz = heap_round(size);
    if (!sz) return 0;
    pthread_mutex_lock(&g_heap_lock);
    if (!heap_valid(a)) { pthread_mutex_unlock(&g_heap_lock); return 0; }
#ifdef PORT_HEAP_STATS
    g_hs_realloc++;
#endif
    uint32_t old = R32(a - 16), old_requested = R32(a - 4);
    if (sz <= old) {
        if (old - sz >= 32u) {
            uint32_t next = a + old + 16u;
            if (next - 16u < g_heap_top && R32(next - 12) == 0) {
                heap_unlink_free(next);
                W32(a - 16, old + 16u + R32(next - 16));
            }
            heap_split(a, sz);
        }
        W32(a - 4, size);
        pthread_mutex_unlock(&g_heap_lock);
        if (zero && size > old_requested) memset(HP(a + old_requested), 0, size - old_requested);
        return a;
    }
    if (a + old == g_heap_top && (uint64_t)a + sz <= HEAP_HI) {
        W32(a - 16, sz);
        W32(a - 4, size);
        g_heap_top = a + sz;
        pthread_mutex_unlock(&g_heap_lock);
        if (zero && size > old_requested) memset(HP(a + old_requested), 0, size - old_requested);
        return a;
    }
    uint32_t next = a + old + 16u;
    if (next - 16u < g_heap_top && R32(next - 12) == 0 &&
        (uint64_t)old + 16u + R32(next - 16) >= sz) {
        heap_unlink_free(next);
        W32(a - 16, old + 16u + R32(next - 16));
        heap_split(a, sz);
        W32(a - 4, size);
        pthread_mutex_unlock(&g_heap_lock);
        if (zero && size > old_requested) memset(HP(a + old_requested), 0, size - old_requested);
        return a;
    }
    pthread_mutex_unlock(&g_heap_lock);
    if (in_place) return 0;
    uint32_t b = heap_try_alloc(size, 0);
    if (!b) return 0;
    memcpy(HP(b), HP(a), old_requested);
    if (zero && size > old_requested) memset(HP(b + old_requested), 0, size - old_requested);
    heap_free(a);
    return b;
}

uint32_t heap_realloc(uint32_t a, uint32_t size, int zero) {
    return heap_realloc_ex(a, size, zero, 0);
}

#define VALLOC_LO GUEST_VALLOC_LO
#define VALLOC_HI GUEST_VALLOC_HI
static uint32_t g_valloc_top = VALLOC_LO;

uint32_t guest_valloc(uint32_t size) {
    uint64_t rounded = ((uint64_t)size + 0xffffu) & ~(uint64_t)0xffffu;
    if (!rounded || rounded > UINT32_MAX) return 0;
    size = (uint32_t)rounded;  /* Windows allocation granularity */
    pthread_mutex_lock(&g_heap_lock);
    uint32_t a = g_valloc_top;
    if ((uint64_t)a + size > VALLOC_HI) { pthread_mutex_unlock(&g_heap_lock); return 0; }
    g_valloc_top += size;
    pthread_mutex_unlock(&g_heap_lock);
    return a;  /* never handed out before, so still zero */
}

void guest_mem_ranges(uint32_t r[4]) { r[0] = HEAP_LO; r[1] = g_heap_top; r[2] = VALLOC_LO; r[3] = g_valloc_top; }
void guest_mem_stats(uint32_t *heap_used, uint32_t *valloc_used) {
    *heap_used = g_heap_top - HEAP_LO;
    *valloc_used = g_valloc_top - VALLOC_LO;
}

#ifdef PORT_HEAP_STATS
/* Диагностика, только с -DPORT_HEAP_STATS (в обычной сборке кода нет, горячие пути аллокатора
   не затрагиваются). Проход по заголовкам блоков под g_heap_lock считает ЖИВЫЕ блоки отдельно от
   протяжённости кучи: `[mem] guest heap N MB` равно g_heap_top - HEAP_LO и включает свободные
   блоки внутри (фрагментацию), поэтому само по себе не отличает утечку от фрагментации.
   Ничего не изменяет; при повреждённом заголовке проход останавливается и считает `bad`. */
typedef struct {
    uint32_t extent, live_blocks, free_blocks, largest_free, bad;
    uint64_t live_capacity, live_requested, free_capacity;
    uint32_t live_by_log2[32];   /* живые блоки по floor(log2(ёмкость)) */
} GuestHeapStats;

static int guest_heap_walk_stats_impl(GuestHeapStats *s, int nonblocking) {
    memset(s, 0, sizeof *s);
    if (nonblocking) {
        if (pthread_mutex_trylock(&g_heap_lock) != 0) return 0;
    } else pthread_mutex_lock(&g_heap_lock);
    s->extent = g_heap_top - HEAP_LO;
    uint32_t p = HEAP_LO + 16u;
    while (p < g_heap_top) {
        uint32_t cap = R32(p - 16), magic = R32(p - 12);
        if (cap < 16 || (cap & 15u) || (magic != HEAP_MAGIC && magic != 0) || (uint64_t)p + cap > g_heap_top) {
            s->bad++;
            break;
        }
        if (magic == HEAP_MAGIC) {
            s->live_blocks++;
            s->live_capacity += cap;
            s->live_requested += R32(p - 4);
            s->live_by_log2[31 - __builtin_clz(cap)]++;
        } else {
            s->free_blocks++;
            s->free_capacity += cap;
            if (cap > s->largest_free) s->largest_free = cap;
        }
        p += cap + 16u;
    }
    pthread_mutex_unlock(&g_heap_lock);
    return 1;
}

void guest_heap_walk_stats(GuestHeapStats *s) {
    (void)guest_heap_walk_stats_impl(s, 0);
}

/* Порог-предупреждение (только с -DPORT_HEAP_STATS, поведение игры не меняет): строка `[heapwarn]`,
   когда протяжённость кучи впервые превысила PORT_HEAP_WARN_PCT процентов от размера кучи
   (по умолчанию 70) и далее при каждом росте ещё на 5 п.п.; она же показывает, чем занята
   протяжённость: живыми блоками или свободными внутри (фрагментация). */
static uint32_t heap_warn_pct(void) {
    static uint32_t pct;
    if (!pct) {
        const char *e = getenv("PORT_HEAP_WARN_PCT");
        long v = e ? strtol(e, NULL, 10) : 70;
        pct = (v >= 1 && v <= 100) ? (uint32_t)v : 70u;
    }
    return pct;
}

/* Чистая функция порога: возвращает новый «ярус» предупреждения (0 — ниже порога; иначе
   1 + число 5-процентных шагов выше порога); предупреждать, когда он вырос против `last_tier`. */
uint32_t guest_heap_warn_tier(uint32_t extent, uint32_t heap_size, uint32_t warn_pct) {
    if (!heap_size) return 0;
    uint64_t pct10 = (uint64_t)extent * 1000u / heap_size;   /* десятые доли процента */
    if (pct10 < (uint64_t)warn_pct * 10u) return 0;
    return 1u + (uint32_t)((pct10 - (uint64_t)warn_pct * 10u) / 50u);
}

static void guest_heap_warn(const GuestHeapStats *s) {
    static uint32_t last_tier;
    uint32_t tier = guest_heap_warn_tier(s->extent, HEAP_HI - HEAP_LO, heap_warn_pct());
    if (tier > last_tier)
        fprintf(stderr, "[heapwarn] extent %u KB = %u%% of the %u MB guest heap (threshold %u%%): live %llu KB, free-inside %llu KB "
                "in %u blocks, largest-free %u KB\n", s->extent >> 10, (uint32_t)((uint64_t)s->extent * 100u / (HEAP_HI - HEAP_LO)),
                (HEAP_HI - HEAP_LO) >> 20, heap_warn_pct(), (unsigned long long)(s->live_capacity >> 10),
                (unsigned long long)(s->free_capacity >> 10), s->free_blocks, s->largest_free >> 10);
    last_tier = tier;
}

/* Отказ выделения в куче гостя: снимок распределения в момент отказа. fatal=1 — перед abort() из heap_alloc
   (внутренние вызовы хоста); fatal=0 — Win32-вызов получит NULL, печатаются первые 8 отказов. */
static void guest_heap_failure_log(uint32_t size, int fatal) {
    static uint32_t n;
    if (!fatal && __atomic_add_fetch(&n, 1, __ATOMIC_RELAXED) > 8) return;
    GuestHeapStats s;
    /* Failure diagnostics must never wait on an allocator lock held elsewhere. */
    if (!guest_heap_walk_stats_impl(&s, 1)) return;
    fprintf(stderr, "[heapfail] %s of %u bytes failed: extent %u KB of %u MB, live %u blocks %llu KB, free-inside %u blocks "
            "%llu KB, largest-free %u KB, bad=%u\n", fatal ? "host allocation" : "allocation", size, s.extent >> 10,
            (HEAP_HI - HEAP_LO) >> 20, s.live_blocks, (unsigned long long)(s.live_capacity >> 10), s.free_blocks,
            (unsigned long long)(s.free_capacity >> 10), s.largest_free >> 10, s.bad);
    fprintf(stderr, "[heapfail] live blocks by 2^k capacity:");
    for (int k = 4; k < 32; k++) if (s.live_by_log2[k]) fprintf(stderr, " %d:%u", k, s.live_by_log2[k]);
    fprintf(stderr, "\n");
}

void guest_heap_stats_log(void) {
    GuestHeapStats s;
    guest_heap_walk_stats(&s);
    guest_heap_warn(&s);
    static uint64_t live_hw;
    static uint32_t extent_hw;
    if (s.live_capacity > live_hw) live_hw = s.live_capacity;
    if (s.extent > extent_hw) extent_hw = s.extent;
    fprintf(stderr, "[heapstats] extent=%u KB (high-water %u KB) live=%u blocks %llu KB (requested %llu KB, high-water %llu KB) "
            "free-inside=%u blocks %llu KB largest-free=%u KB bad=%u\n",
            s.extent >> 10, extent_hw >> 10, s.live_blocks, (unsigned long long)(s.live_capacity >> 10),
            (unsigned long long)(s.live_requested >> 10), (unsigned long long)(live_hw >> 10),
            s.free_blocks, (unsigned long long)(s.free_capacity >> 10), s.largest_free >> 10, s.bad);
    fprintf(stderr, "[heapstats] live blocks by 2^k capacity:");
    for (int k = 4; k < 32; k++) if (s.live_by_log2[k]) fprintf(stderr, " %d:%u", k, s.live_by_log2[k]);
    fprintf(stderr, "\n");
    pthread_mutex_lock(&g_heap_lock);
    unsigned long long ops[5] = { g_hs_alloc, g_hs_free, g_hs_realloc, g_hs_big_alloc, g_hs_alloc_bytes };
    pthread_mutex_unlock(&g_heap_lock);
    fprintf(stderr, "[heapstats] ops since start: alloc=%llu free=%llu realloc=%llu big-alloc(>=64KB)=%llu allocated=%llu MB\n",
            ops[0], ops[1], ops[2], ops[3], ops[4] >> 20);
}
#endif

uint32_t guest_strdup(const char *s) {
    uint32_t a = heap_alloc((uint32_t)strlen(s) + 1, 0);
    strcpy((char *)HP(a), s);
    return a;
}

/* ------------------------------------------------------------------ handles */

/* Таблица дескрипторов и её блокировка (PORT_SPECIFICATION.md).
 *
 * Игра многопоточна (звук, загрузка, потоки гостя), а handle_get зовут из каждой записи/чтения файла и каждого
 * ожидания на объекте. Поэтому:
 *   - g_handle_lock защищает выдачу слота (выбор свободного, счётчик и флаг round-robin) и просмотр таблицы
 *     file_path_write_open (он не должен видеть слот посреди обнуления при выдаче). Закрытие замка не берёт: слот
 *     занимается одним CAS типа (живой -> RESERVED), им же отсекается второй одновременный close того же handle.
 *     Дальше слотом RESERVED владеет только тот, кто его занял: заполняет, публикует тип (handle_publish, CAS) или
 *     освобождает (handle_cancel, handle_unclaim): без замка. Замок ЛИСТОВОЙ: под ним нет ни вызовов наружу, ни других замков (close(),
 *     free() и т.п. выполняются после снятия). Порядок: g_share_lock -> g_save_tx_lock -> g_handle_lock.
 *   - поле `type` слота читается и пишется только атомарно (acquire/release). handle_get не берёт замок: это
 *     одна атомарная загрузка, то есть цена горячего пути та же, что и без защиты. Релиз-запись `type` публикует
 *     поля слота, заполненные до неё; поэтому объект (ptr/fd/буфер) надо готовить в слоте ДО публикации типа
 *     (handle_new_ptr, handle_try_new(H_RESERVED) + handle_publish), а не после handle_new.
 *   - остальные поля слота принадлежат потоку, который держит значение; другие потоки их не трогают.
 * Чего НЕТ: счётчика ссылок. Поток, получивший указатель handle_get и продолжающий им пользоваться, пока другой
 * поток закрывает ТОТ ЖЕ handle, это ошибка гостя (в Windows так же): таблица остаётся целой, но поля слота
 * (fd, буфер снимка, состояние поиска) в этот момент освобождаются. Закрытый handle после этого не найден
 * (handle_get даёт NULL, ReadFile и т.д. отвечают ERROR_INVALID_HANDLE). Объекты синхронизации (Sync) при
 * закрытии не освобождаются, поэтому устаревший указатель на них безопасен. Ожидания (WaitForSingleObject) берут пару
 * (type, ptr) один раз через handle_snapshot и слот больше не читают; закрытие синхронизационного объекта будит ждущих через
 * хук (handle_set_close_hook: kernel32.c, sync_close_hook), и они возвращают WAIT_FAILED вместо зависания
 * (PORT_SPECIFICATION.md). */
#define MAX_HANDLES 4096
static WinHandle g_handles[MAX_HANDLES];
static pthread_mutex_t g_handle_lock = PTHREAD_MUTEX_INITIALIZER;

#define SLOT_TYPE(x) __atomic_load_n(&(x)->type, __ATOMIC_ACQUIRE)
#define SLOT_SET_TYPE(x, t) __atomic_store_n(&(x)->type, (t), __ATOMIC_RELEASE)

static int g_handle_rr;            /* strict share: round-robin allocation */
static int g_handle_cursor = 16;

void handle_set_round_robin(int on) {
    pthread_mutex_lock(&g_handle_lock);
    g_handle_rr = on;
    pthread_mutex_unlock(&g_handle_lock);
}

/* Slot allocation: all fields except `type` are reset first, `type` is published last (release). */
static uint32_t handle_alloc(int type, void *ptr) {
    pthread_mutex_lock(&g_handle_lock);
    /* Default: lowest free slot (unchanged). Round-robin starts after the previous allocation, so the
       value of a just-closed handle is not handed out again at once and a stale/double CloseHandle of
       it is rejected instead of closing an unrelated new handle. */
    int span = MAX_HANDLES - 16;
    int start = g_handle_rr && g_handle_cursor >= 16 && g_handle_cursor < MAX_HANDLES ? g_handle_cursor : 16;
    for (int k = 0; k < span; k++) {
        int i = g_handle_rr ? 16 + (start - 16 + k) % span : 16 + k;
        WinHandle *x = &g_handles[i];
        if (SLOT_TYPE(x) == H_FREE) {
            /* Reset every field but `type` (the last store) and `ptr` (written once, so a stale reader of the
               previous incarnation never sees a transient NULL where the old and the new object are both valid). */
            size_t after_type = offsetof(WinHandle, type) + sizeof x->type, ptr_end = offsetof(WinHandle, ptr) + sizeof x->ptr;
            memset((char *)x + after_type, 0, offsetof(WinHandle, ptr) - after_type);
            memset((char *)x + ptr_end, 0, sizeof *x - ptr_end);
            x->fd = -1;
            __atomic_store_n(&x->ptr, ptr, __ATOMIC_RELAXED);   /* atomic: a stale reader of the old incarnation may load ptr concurrently */
            SLOT_SET_TYPE(x, type);
            if (g_handle_rr) g_handle_cursor = i + 1;
            pthread_mutex_unlock(&g_handle_lock);
            return 0x1000u + 4u * (uint32_t)i;
        }
    }
    pthread_mutex_unlock(&g_handle_lock);
    return 0;
}

uint32_t handle_try_new(int type) { return handle_alloc(type, NULL); }

uint32_t handle_new(int type) {
    uint32_t h = handle_try_new(type);
    if (h) return h;
    fprintf(stderr, "out of handles\n");
    abort();
}

uint32_t handle_new_ptr(int type, void *ptr) {
    uint32_t h = handle_alloc(type, ptr);
    if (h) return h;
    fprintf(stderr, "out of handles\n");
    abort();
}

/* A RESERVED slot (not a live handle yet) whose ptr is already set: the caller fills in what else it needs (CreateThread:
   the g_threads_by_handle entry) and publishes with handle_publish, so nothing sees a half-built handle. The value is
   the one handle_new_ptr would give. Aborts when the table is full, like handle_new. */
uint32_t handle_reserve_ptr(void *ptr) { return handle_new_ptr(H_RESERVED, ptr); }

/* Called by handle_close / handle_close_checked for the one close that claimed the slot, before the slot is given
   back (so the value cannot be reissued meanwhile). kernel32.c uses it to wake waiters on a closing sync object and to
   drop the thread table entry. No lock of the table is held; the hook must not call back into the table. */
static HandleCloseHook g_close_hook;
void handle_set_close_hook(HandleCloseHook hook) { __atomic_store_n(&g_close_hook, hook, __ATOMIC_RELEASE); }
static void handle_run_close_hook(uint32_t h, int type, void *ptr) {
    HandleCloseHook hook = __atomic_load_n(&g_close_hook, __ATOMIC_ACQUIRE);
    if (hook) hook(h, type, ptr);
}

WinHandle *handle_get(uint32_t h, int type) {
    if (h < 0x1000u || (h & 3)) return NULL;
    uint32_t i = (h - 0x1000u) / 4;
    if (i >= MAX_HANDLES) return NULL;
    WinHandle *x = &g_handles[i];
    int t = SLOT_TYPE(x);
    if (t == H_FREE || t == H_RESERVED) return NULL;
    if (type != -1 && t != type) return NULL;
    return x;
}

/* Slot index of a table-range, aligned handle value, else -1. */
static int handle_index(uint32_t h) {
    if (h < 0x1000u || (h & 3)) return -1;
    uint32_t i = (h - 0x1000u) / 4;
    return i < MAX_HANDLES ? (int)i : -1;
}

/* The type and ptr of a live handle read once, so a waiting thread works on one consistent (type, object) pair instead of
   re-reading the slot (which another thread may close and reissue meanwhile). Returns H_FREE for a value that is not a
   live handle, or when the slot changed under the read (treated as closed). Sync objects are never freed, so a stale
   ptr from a handle closed right after is still a valid object. */
int handle_snapshot(uint32_t h, void **ptr) {
    int i = handle_index(h);
    if (i < 0) return H_FREE;
    WinHandle *x = &g_handles[i];
    int t = SLOT_TYPE(x);
    if (t == H_FREE || t == H_RESERVED) return H_FREE;
    void *p = __atomic_load_n(&x->ptr, __ATOMIC_RELAXED);
    if (SLOT_TYPE(x) != t) return H_FREE;
    *ptr = p;
    return t;
}

/* Claims a live slot (live -> H_RESERVED) with one compare-and-swap of its type; NULL when h is not a live handle. A
   claimed slot is invisible to handle_get and cannot be allocated, so two racing closes of one value cannot both
   release its fd/buffer (exactly one CAS wins), and the slot is not reissued before its resources are released. The
   acquire half of the CAS pairs with the release-store that published the type, so the fields written before the
   publication are visible here. No lock: close is as cheap as before the fix. */
static WinHandle *handle_claim(uint32_t h, int *type, int *fd, uint8_t **buf, void **ptr) {
    int i = handle_index(h);
    if (i < 0) return NULL;
    WinHandle *x = &g_handles[i];
    int t = SLOT_TYPE(x);
    do {
        if (t == H_FREE || t == H_RESERVED) return NULL;
    } while (!__atomic_compare_exchange_n(&x->type, &t, H_RESERVED, 1, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE));
    *type = t; *fd = x->fd; *buf = x->buf; *ptr = __atomic_load_n(&x->ptr, __ATOMIC_RELAXED);
    return x;
}
/* Gives a claimed slot back once its resources are released. Only the claimant touches a RESERVED slot, so the
   release-store of FREE needs no lock: the allocator (under the lock) sees FREE through its acquire-load, and with it
   the fd/buf resets made before. */
static void handle_unclaim(WinHandle *x) {
    x->fd = -1;     /* a stale pointer then fails the fd/buffer paths (EBADF) instead of using freed state */
    x->buf = NULL;
    SLOT_SET_TYPE(x, H_FREE);
}

void handle_close(uint32_t h) {
    int type, fd;
    uint8_t *buf;
    void *ptr;
    WinHandle *x = handle_claim(h, &type, &fd, &buf, &ptr);
    if (!x) {   /* silent for the game (CloseHandle stays TRUE); PORT_LOG shows a double or stale close */
        if (handle_index(h) >= 0) LOG("[handle] close of %x: not a live handle (closed twice, or closed by another thread)\n", h);
        return;
    }
    handle_run_close_hook(h, type, ptr);
    /* A mapping handle owns the dup()ed fd of its file (CreateFileMappingA): closed here too (the strict close always did;
       this one used to leak it: PORT_SPECIFICATION.md). */
    if ((type == H_FILE || type == H_MAPPING) && fd >= 0) close(fd);
    free(buf);   /* read-only snapshot buffer, NULL when the handle never had one */
    if (type == H_FIND && ptr) free(ptr);
    handle_unclaim(x);
}

/* The two-step open (strict share, and the default mode since PORT_SPECIFICATION.md): the owner of a RESERVED slot
   fills it in and publishes the type last (release), or cancels. Nobody else may touch a RESERVED slot (handle_get and
   handle_close skip it), so these need no lock. */
WinHandle *handle_reserved(uint32_t h) {
    int i = handle_index(h);
    return i >= 0 && SLOT_TYPE(&g_handles[i]) == H_RESERVED ? &g_handles[i] : NULL;
}
void handle_publish(uint32_t h, int type) {
    int i = handle_index(h);
    int expect = H_RESERVED;
    if (i >= 0) __atomic_compare_exchange_n(&g_handles[i].type, &expect, type, 0, __ATOMIC_RELEASE, __ATOMIC_RELAXED);
}
void handle_cancel(uint32_t h) {
    WinHandle *x = handle_reserved(h);
    if (x) handle_unclaim(x);
}
/* Atomic per handle (see handle_claim). The fd of a mapping handle (a dup of its file's fd) is closed too. */
int handle_close_checked(uint32_t h) {
    int type, fd;
    uint8_t *buf;
    void *ptr;
    WinHandle *x = handle_claim(h, &type, &fd, &buf, &ptr);
    if (!x) return 0;
    handle_run_close_hook(h, type, ptr);
    if ((type == H_FILE || type == H_MAPPING) && fd >= 0) close(fd);
    free(buf);
    if (type == H_FIND && ptr) free(ptr);
    handle_unclaim(x);
    return 1;
}

/* 1 when an open H_FILE handle on this host path may write or truncate it: a read-only
   snapshot taken next would freeze bytes that the plain fd path would see change.
   Write handles are the only conflict (two readers already share the fd path today). */
int file_path_write_open(const char *host) {
    int found = 0;
    pthread_mutex_lock(&g_handle_lock);
    for (int i = 0; i < MAX_HANDLES && !found; i++)
        if (SLOT_TYPE(&g_handles[i]) == H_FILE && g_handles[i].write_open &&
            !strcmp(g_handles[i].path, host)) found = 1;
    pthread_mutex_unlock(&g_handle_lock);
    return found;
}

/* ------------------------------------------------------------------ names: CP1251 <-> UTF-8 (opt-in)
 *
 * The game is Russian and its code page is CP1251: file names reach the host as one-byte strings, and the
 * host (WasmFS/OPFS, and every Unix) keeps names as UTF-8. Measured (file-share-policy-diagnostic/k2/
 * test-opfs-names.mjs): OPFS does not keep a name that is not well-formed UTF-8, two different CP1251 names
 * ("\xA8\xE6" and "\xB8\xE6") collapse into one file. PORT_NAME_CP1251=1 (page: ?nameCp1251=1) therefore
 * translates names at the guest/host border, and ONLY there:
 *   guest -> host: every component of a guest path (map_path), bytes >= 0x80 read as Windows-1251;
 *   host -> guest: the names FindFirstFileA/FindNextFileA hand to the game.
 * Anything the game keeps (GetCurrentDirectory, GetFullPathName, SetCurrentDirectory) stays in CP1251, the
 * host only ever sees UTF-8. Off by default (unset, "" and "0"): the code below is then not reached for a
 * name made of ASCII, and no byte of an ASCII name changes in either mode.
 * Table: the 0x80..0xFF half of Windows-1251 as TextDecoder("windows-1251") and MultiByteToWideChar(1251)
 * give it. 0x98 has no character in CP1251; both map it to the control U+0098, so that the 256 bytes and
 * their code points stay a bijection (a guest name never loses a byte, UTF-8 of U+0098 is C2 98). */
static const uint16_t g_cp1251_hi[128] = {
    0x0402, 0x0403, 0x201A, 0x0453, 0x201E, 0x2026, 0x2020, 0x2021,
    0x20AC, 0x2030, 0x0409, 0x2039, 0x040A, 0x040C, 0x040B, 0x040F,
    0x0452, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x0098, 0x2122, 0x0459, 0x203A, 0x045A, 0x045C, 0x045B, 0x045F,
    0x00A0, 0x040E, 0x045E, 0x0408, 0x00A4, 0x0490, 0x00A6, 0x00A7,
    0x0401, 0x00A9, 0x0404, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0407,
    0x00B0, 0x00B1, 0x0406, 0x0456, 0x0491, 0x00B5, 0x00B6, 0x00B7,
    0x0451, 0x2116, 0x0454, 0x00BB, 0x0458, 0x0405, 0x0455, 0x0457,
    0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
    0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
    0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
    0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
    0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
    0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
    0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
    0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F,
};

static int g_name_cp1251 = -1;   /* -1: not read yet (value is idempotent, so a racing first read is harmless) */
/* PORT_LOG lines "[name] ...": the first 40 events only (a conversion is rare: names with bytes >= 0x80 do not occur in the game's own files). */
void name_log(const char *what, const char *bytes) {
    static int n;
    if (!g_log || __atomic_add_fetch(&n, 1, __ATOMIC_RELAXED) > 40) return;
    char hx[260];
    size_t k = 0;
    for (const unsigned char *p = (const unsigned char *)bytes; *p && k + 3 < sizeof hx; p++, k += 2) snprintf(hx + k, 3, "%02x", *p);
    hx[k] = 0;
    fprintf(stderr, "[name] %s: hex %s\n", what, hx);
}
int name_cp1251_on(void) {
    int v = __atomic_load_n(&g_name_cp1251, __ATOMIC_RELAXED);
    if (v < 0) {
        const char *e = getenv("PORT_NAME_CP1251");
        v = e && *e && strcmp(e, "0") != 0;
        __atomic_store_n(&g_name_cp1251, v, __ATOMIC_RELAXED);
        if (v && g_log) fprintf(stderr, "[name] PORT_NAME_CP1251 on: guest file names are Windows-1251, host names UTF-8\n");
    }
    return v;
}
void name_cp1251_set(int on) { __atomic_store_n(&g_name_cp1251, on ? 1 : 0, __ATOMIC_RELAXED); }   /* tests */

int name_has_high(const char *s) {
    for (; *s; s++) if ((unsigned char)*s >= 0x80) return 1;
    return 0;
}

/* One well-formed UTF-8 sequence at s: its length (1..4) and *cp, or 0 (overlong, surrogate, > U+10FFFF,
   truncated, stray continuation or a bare 0x80..0xC1/0xF5+ byte). */
int name_utf8_decode(const unsigned char *s, uint32_t *cp) {
    unsigned c = s[0];
    if (c < 0x80) { *cp = c; return 1; }
    if (c >= 0xC2 && c <= 0xDF && (s[1] & 0xC0) == 0x80) { *cp = ((c & 0x1Fu) << 6) | (s[1] & 0x3Fu); return 2; }
    if (c >= 0xE0 && c <= 0xEF && (s[1] & 0xC0) == 0x80 && (s[2] & 0xC0) == 0x80) {
        uint32_t v = ((c & 0x0Fu) << 12) | ((uint32_t)(s[1] & 0x3Fu) << 6) | (s[2] & 0x3Fu);
        if (v < 0x800 || (v >= 0xD800 && v <= 0xDFFF)) return 0;
        *cp = v; return 3;
    }
    if (c >= 0xF0 && c <= 0xF4 && (s[1] & 0xC0) == 0x80 && (s[2] & 0xC0) == 0x80 && (s[3] & 0xC0) == 0x80) {
        uint32_t v = ((c & 0x07u) << 18) | ((uint32_t)(s[1] & 0x3Fu) << 12) | ((uint32_t)(s[2] & 0x3Fu) << 6) | (s[3] & 0x3Fu);
        if (v < 0x10000 || v > 0x10FFFF) return 0;
        *cp = v; return 4;
    }
    return 0;
}

/* The case folding Windows applies to names, for the characters of the game's languages (what the NTFS upcase
   table does to them): ASCII, Latin-1, Latin Extended-A, Greek, Cyrillic (all of CP1251 incl. Ukrainian
   and Serbian letters), Armenian, fullwidth Latin. Same table as share_fold_cp (kernel32.c, strict), which
   test_name_cp1251.c checks code point by code point. Mappings keep the UTF-8 length. */
uint32_t name_fold_cp(uint32_t c) {
    if (c < 0x80) return (c >= 'A' && c <= 'Z') ? c + 32 : c;
    if (c < 0xC0) return c;
    if (c <= 0xDE) return c == 0xD7 ? c : c + 32;
    if (c < 0x100) return c;
    if (c <= 0x137) return (c == 0x130 || c == 0x131 || (c & 1)) ? c : c + 1;
    if (c >= 0x139 && c <= 0x147) return (c & 1) ? c + 1 : c;
    if (c >= 0x14A && c <= 0x177) return (c & 1) ? c : c + 1;
    if (c == 0x178) return 0xFF;
    if (c >= 0x179 && c <= 0x17D) return (c & 1) ? c + 1 : c;
    if (c == 0x386) return 0x3AC;
    if (c >= 0x388 && c <= 0x38A) return c + 37;
    if (c == 0x38C) return 0x3CC;
    if (c == 0x38E || c == 0x38F) return c + 63;
    if ((c >= 0x391 && c <= 0x3A1) || (c >= 0x3A3 && c <= 0x3AB)) return c + 32;
    if (c == 0x3C2) return 0x3C3;
    if (c >= 0x400 && c <= 0x40F) return c + 80;
    if (c >= 0x410 && c <= 0x42F) return c + 32;
    if ((c >= 0x460 && c <= 0x481) || (c >= 0x48A && c <= 0x4BF) || (c >= 0x4D0 && c <= 0x52F)) return (c & 1) ? c : c + 1;
    if (c == 0x4C0) return 0x4CF;
    if (c >= 0x4C1 && c <= 0x4CD) return (c & 1) ? c + 1 : c;
    if (c >= 0x531 && c <= 0x556) return c + 48;
    if ((c >= 0x1E00 && c <= 0x1E95) || (c >= 0x1EA0 && c <= 0x1EFF)) return (c & 1) ? c : c + 1;
    if (c >= 0xFF21 && c <= 0xFF3A) return c + 32;
    return c;
}

/* Guest CP1251 -> host UTF-8. Every byte has a code point, so this only fails when out does not fit (n bytes
   including the NUL); then out holds the truncated-free empty string. */
int name_guest_to_host(const char *guest, char *out, size_t n) {
    size_t o = 0;
    for (const unsigned char *p = (const unsigned char *)guest; *p; p++) {
        uint32_t cp = *p < 0x80 ? *p : g_cp1251_hi[*p - 0x80];
        size_t need = cp < 0x80 ? 1 : cp < 0x800 ? 2 : 3;
        if (o + need + 1 > n) { if (n) out[0] = 0; return 0; }
        if (need == 1) out[o++] = (char)cp;
        else if (need == 2) { out[o++] = (char)(0xC0 | (cp >> 6)); out[o++] = (char)(0x80 | (cp & 0x3F)); }
        else { out[o++] = (char)(0xE0 | (cp >> 12)); out[o++] = (char)(0x80 | ((cp >> 6) & 0x3F)); out[o++] = (char)(0x80 | (cp & 0x3F)); }
    }
    if (n) out[o] = 0;
    return 1;
}

/* Host UTF-8 -> guest CP1251. 1 when the whole name is well-formed UTF-8 made only of characters Windows-1251
   has (and it fits); else 0 and out is empty: the caller decides what to do with such a name. */
int name_host_to_guest(const char *host, char *out, size_t n) {
    size_t o = 0;
    for (const unsigned char *p = (const unsigned char *)host; *p;) {
        uint32_t cp;
        int len = name_utf8_decode(p, &cp);
        int b = -1;
        if (!len) goto fail;
        if (cp < 0x80) b = (int)cp;
        else for (int i = 0; i < 128; i++) if (g_cp1251_hi[i] == cp) { b = 0x80 + i; break; }
        if (b < 0 || o + 2 > n) goto fail;
        out[o++] = (char)b;
        p += len;
    }
    if (n) out[o] = 0;
    return n != 0;
fail:
    if (n) out[0] = 0;
    return 0;
}

/* Same name under Windows rules? a: guest CP1251 bytes, b: host UTF-8 (the directory entry). ASCII-only pairs
   are never sent here by the callers (they keep strcasecmp). */
static int name_fold_eq(const char *guest_utf8, const char *host) {
    const unsigned char *a = (const unsigned char *)guest_utf8, *b = (const unsigned char *)host;
    while (*a && *b) {
        uint32_t ca, cb;
        int la = name_utf8_decode(a, &ca), lb = name_utf8_decode(b, &cb);
        if (!la || !lb) return 0;
        if (name_fold_cp(ca) != name_fold_cp(cb)) return 0;
        a += la; b += lb;
    }
    return !*a && !*b;
}

/* Wildcard match for the find calls, in characters and not in bytes: pat is the guest's pattern (CP1251), name a
   host UTF-8 entry; '*' any run, '?' exactly one character, no other metacharacters (Windows has no [] sets),
   case folded as name_fold_cp. Names or patterns longer than 511 characters do not match. */
int name_wild_match(const char *pat, const char *name) {
    uint32_t p[512], s[512];
    size_t np = 0, ns = 0;
    for (const unsigned char *q = (const unsigned char *)pat; *q; q++) {
        if (np >= 511) return 0;
        p[np++] = *q < 0x80 ? *q : g_cp1251_hi[*q - 0x80];
    }
    for (const unsigned char *q = (const unsigned char *)name; *q;) {
        uint32_t cp;
        int len = name_utf8_decode(q, &cp);
        if (!len || ns >= 511) return 0;
        s[ns++] = cp;
        q += len;
    }
    size_t i = 0, j = 0, star = (size_t)-1, mark = 0;
    while (j < ns) {
        if (i < np && p[i] == '*') { star = i++; mark = j; }
        else if (i < np && (p[i] == '?' || name_fold_cp(p[i]) == name_fold_cp(s[j]))) { i++; j++; }
        else if (star != (size_t)-1) { i = star + 1; j = ++mark; }
        else return 0;
    }
    while (i < np && p[i] == '*') i++;
    return i == np;
}

/* ------------------------------------------------------------------ paths */

/* Finds `name` in directory `dir` ignoring case; writes the real name into `out`. */
static int find_ci(const char *dir, const char *name, char *out, size_t n) {
    DIR *d = opendir(*dir ? dir : ".");
    if (!d) return 0;
    struct dirent *e;
    int found = 0;
    while ((e = readdir(d))) {
        if (!strcasecmp(e->d_name, name)) {
            snprintf(out, n, "%s", e->d_name);
            found = 1;
            break;
        }
    }
    closedir(d);
    return found;
}

/* The same for a UTF-8 name with non-ASCII characters (PORT_NAME_CP1251): entries are compared with the
   Unicode case folding above, so "Ёж" finds "ёж" the way Windows does. */
static int find_ci_fold(const char *dir, const char *name_utf8, char *out, size_t n) {
    DIR *d = opendir(*dir ? dir : ".");
    if (!d) return 0;
    struct dirent *e;
    int found = 0;
    while ((e = readdir(d))) {
        if (name_fold_eq(name_utf8, e->d_name)) {
            snprintf(out, n, "%s", e->d_name);
            found = 1;
            break;
        }
    }
    closedir(d);
    return found;
}

/* ------------------------------------------------------------------ language overlay (E1, PORT_SPECIFICATION.md)
 *
 * PORT_OVERLAY=<absolute host path>: a second, READ-ONLY tree laid over the game folder. Unset, "" and "0" switch it
 * off, and then none of the code below runs: map_path takes its old path and the overlay-aware callers
 * (map_path_ov) fall back to it after one flag test. The tree repeats the game's layout and holds only the files
 * that differ in the other language (english-layer: PROGRAM/**, RESOURCE/**). What the host does with it:
 *   - only PROGRAM and RESOURCE (the first component below the game root, case-insensitively) are ever looked up;
 *     SAVE, SAVE_META, SAVE_TX, options, engine.ini, ENGINE.exe, MODULES and anything outside the game folder are
 *     always the base's, even when the overlay folder holds files of those names (the index does not even list them);
 *   - reads (open without write access, attributes, directory listings, CopyFile's source) find a file in the overlay
 *     first and in the base otherwise; a directory listing is the UNION of both (base order first, then the names
 *     only the overlay has; a name in both: the overlay's data, the base's spelling);
 *   - nothing is ever written, created, deleted or moved in the overlay: map_path itself still only returns BASE
 *     paths, and the callers that change anything refuse a path the overlay holds (ERROR_ACCESS_DENIED /
 *     ERROR_ALREADY_EXISTS, one LOG line); creating a NEW name goes to the base, as before;
 *   - the overlay is addressed through an index built from readdir, never from guest text: a guest "..\\.." cannot
 *     leave it (the walk pops components exactly like the base walk and never goes above the game root), and a symlink
 *     (or anything that is not a regular file or a directory) is not indexed, so it is never followed;
 *   - identity: map_path (the canonical, BASE-rooted host path, spelled with the overlay's real names for components
 *     that exist only in the overlay) is what strict share, SAVE_TX, SAVE_META and the handle table see; an overlay
 *     file and its base twin are ONE guest file. Only the fd of a read open comes from the overlay path.
 * The index is a snapshot taken per directory on first use: the overlay must not change while the game runs (the page
 * holds the save lock and never touches it then). Costs, with the overlay on: one hash lookup per component below
 * PROGRAM/RESOURCE and no system call (directories are listed once, lazily); off: one relaxed atomic load.
 * Refused root (not a directory, inside the game folder, or containing it): PORT_OVERLAY is then NOT silently
 * dropped by main (overlay_init_from_env fails, the host does not start): a half-English game is worse. */
typedef struct OvNode {
    char *name, *host;
    struct OvNode *parent, **kids, **tab;
    uint32_t nkids, capkids, tabsz;
    uint8_t is_dir, loaded;
} OvNode;
static OvNode *g_ov_root;
static int g_ov_state = -1;   /* -1 env not read, 0 off, 1 on, 2 refused */
static char g_ov_path[1024];
static pthread_mutex_t g_ov_lock = PTHREAD_MUTEX_INITIALIZER;
static uint32_t g_ov_hits, g_ov_loads, g_ov_skipped;

static uint32_t ov_hash(const char *s) {   /* FNV-1a over the ASCII-lowercased bytes: the key strcasecmp would equate */
    uint32_t h = 2166136261u;
    for (const unsigned char *p = (const unsigned char *)s; *p; p++) { h ^= (*p >= 'A' && *p <= 'Z') ? *p + 32u : *p; h *= 16777619u; }
    return h;
}
static OvNode *ov_new(OvNode *parent, const char *name, const char *host, int is_dir) {
    OvNode *n = calloc(1, sizeof *n);
    if (!n) return NULL;
    n->name = strdup(name); n->host = strdup(host); n->parent = parent; n->is_dir = (uint8_t)is_dir;
    if (!n->name || !n->host) { free(n->name); free(n->host); free(n); return NULL; }
    return n;
}
static void ov_free(OvNode *n) {
    if (!n) return;
    for (uint32_t i = 0; i < n->nkids; i++) ov_free(n->kids[i]);
    free(n->kids); free(n->tab); free(n->name); free(n->host); free(n);
}
static int ov_top_allowed(const char *name) { return !strcasecmp(name, "PROGRAM") || !strcasecmp(name, "RESOURCE"); }
static OvNode *ov_ascii_find(OvNode *d, const char *name) {
    if (d->tab) {
        uint32_t m = d->tabsz - 1;
        for (uint32_t i = ov_hash(name) & m; d->tab[i]; i = (i + 1) & m)
            if (!strcasecmp(d->tab[i]->name, name)) return d->tab[i];
        return NULL;
    }
    for (uint32_t i = 0; i < d->nkids; i++) if (!strcasecmp(d->kids[i]->name, name)) return d->kids[i];
    return NULL;
}
/* 1 plain file, 2 directory, 0 anything else (symlinks included: lstat, never stat). */
static int ov_entry_type(const struct dirent *e, const char *full) {
#ifdef DT_REG
    if (e->d_type == DT_REG) return 1;
    if (e->d_type == DT_DIR) return 2;
    if (e->d_type != DT_UNKNOWN) return 0;
#else
    (void)e;
#endif
    struct stat st;
    if (lstat(full, &st) != 0) return 0;
    return S_ISREG(st.st_mode) ? 1 : S_ISDIR(st.st_mode) ? 2 : 0;
}
/* Lists directory d once (lazily, under the lock). Entries that are not plain files or directories are skipped, and
   so are names that differ from an earlier one only by case (the first wins, like find_ci's first match). */
static void ov_load(OvNode *d) {
    if (__atomic_load_n(&d->loaded, __ATOMIC_ACQUIRE)) return;
    pthread_mutex_lock(&g_ov_lock);
    if (!d->loaded) {
        DIR *dir = d->is_dir ? opendir(d->host) : NULL;
        struct dirent *e;
        while (dir && (e = readdir(dir))) {
            if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
            if (d == g_ov_root && !ov_top_allowed(e->d_name)) { g_ov_skipped++; continue; }
            char full[1400];
            if (snprintf(full, sizeof full, "%s/%s", d->host, e->d_name) >= (int)sizeof full) { g_ov_skipped++; continue; }
            int type = ov_entry_type(e, full);
            if (!type) { g_ov_skipped++; continue; }   /* a symlink or anything else: never followed */
            int is_dir = type == 2;
            if (d->nkids && ov_ascii_find(d, e->d_name)) { g_ov_skipped++; continue; }
            OvNode *k = ov_new(d, e->d_name, full, is_dir);
            if (!k) continue;
            if (d->nkids == d->capkids) {
                uint32_t nc = d->capkids ? d->capkids * 2 : 8;
                OvNode **nk = realloc(d->kids, nc * sizeof *nk);
                if (!nk) { ov_free(k); continue; }
                d->kids = nk; d->capkids = nc;
            }
            d->kids[d->nkids++] = k;
            if (d->nkids > 8 && d->nkids * 2 > d->tabsz) {   /* (re)build the lookup table at load factor <= 1/2 */
                uint32_t sz = 16;
                while (sz < d->nkids * 4) sz <<= 1;
                OvNode **t = calloc(sz, sizeof *t);
                if (t) {
                    for (uint32_t i = 0; i < d->nkids; i++) {
                        uint32_t j = ov_hash(d->kids[i]->name) & (sz - 1);
                        while (t[j]) j = (j + 1) & (sz - 1);
                        t[j] = d->kids[i];
                    }
                    free(d->tab); d->tab = t; d->tabsz = sz;
                }
            } else if (d->tab) {
                uint32_t j = ov_hash(k->name) & (d->tabsz - 1);
                while (d->tab[j]) j = (j + 1) & (d->tabsz - 1);
                d->tab[j] = k;
            }
        }
        if (dir) closedir(dir);
        g_ov_loads++;
        __atomic_store_n(&d->loaded, 1, __ATOMIC_RELEASE);
    }
    pthread_mutex_unlock(&g_ov_lock);
}
/* The child of directory d the guest component `comp` (CP1251 bytes) names: the same rules as the base walk (find_ci /
   find_ci_fold), against the index. */
static OvNode *ov_find(OvNode *d, const char *comp) {
    if (!d || !d->is_dir) return NULL;
    ov_load(d);
    if (name_has_high(comp) && name_cp1251_on()) {
        char u[1024];
        if (!name_guest_to_host(comp, u, sizeof u)) return NULL;
        for (uint32_t i = 0; i < d->nkids; i++) if (name_fold_eq(u, d->kids[i]->name)) return d->kids[i];
        for (uint32_t i = 0; i < d->nkids; i++) if (!strcasecmp(d->kids[i]->name, comp)) return d->kids[i];   /* legacy: the guest's own bytes */
        return NULL;
    }
    return ov_ascii_find(d, comp);
}
static void ov_reset_locked(void) {
    ov_free(g_ov_root);
    g_ov_root = NULL;
    g_ov_state = -1;
    g_ov_hits = g_ov_loads = g_ov_skipped = 0;
}
/* 1 when path a lies inside b (component boundary) or equals it. */
static int ov_inside(const char *a, const char *b) {
    size_t n = strlen(b);
    return n && !strncmp(a, b, n) && (a[n] == '/' || a[n] == 0);
}
static int ov_state_init(void) {
    pthread_mutex_lock(&g_ov_lock);
    int s = g_ov_state;
    if (s < 0) {
        const char *e = getenv("PORT_OVERLAY");
        s = 0;
        if (e && *e && strcmp(e, "0") != 0) {
            char real[1024];
            struct stat st;
            if (!realpath(e, real) || stat(real, &st) != 0 || !S_ISDIR(st.st_mode)) {
                fprintf(stderr, "[overlay] PORT_OVERLAY=%s is not a readable directory: refused\n", e);
                s = 2;
            } else if (ov_inside(real, g_game_root) || ov_inside(g_game_root, real)) {
                fprintf(stderr, "[overlay] PORT_OVERLAY=%s overlaps the game folder %s: refused (the overlay must stay read-only)\n", real, g_game_root);
                s = 2;
            } else {
                snprintf(g_ov_path, sizeof g_ov_path, "%s", real);
                g_ov_root = ov_new(NULL, "", real, 1);
                if (g_ov_root) {
                    static int announced;
                    s = 1;
                    if (!announced++) fprintf(stderr, "[overlay] on: %s (read-only, PROGRAM/ and RESOURCE/ only)\n", real);   /* once per process */
                } else s = 2;
            }
        }
        __atomic_store_n(&g_ov_state, s, __ATOMIC_RELEASE);
    }
    pthread_mutex_unlock(&g_ov_lock);
    return s;
}
int overlay_active(void) {
    int s = __atomic_load_n(&g_ov_state, __ATOMIC_RELAXED);
    if (__builtin_expect(s < 0, 0)) s = ov_state_init();
    return s == 1;
}
/* main(): read the variable before anything runs. 0 = off or on, -1 = a root that was asked for but cannot be used. */
int overlay_init_from_env(void) {
    int s = __atomic_load_n(&g_ov_state, __ATOMIC_ACQUIRE);
    if (s < 0) s = ov_state_init();
    return s == 2 ? -1 : 0;
}
/* tests: forget the index and the environment's verdict (no open find handle may exist) */
void overlay_test_reset(void) {
    pthread_mutex_lock(&g_ov_lock);
    ov_reset_locked();
    pthread_mutex_unlock(&g_ov_lock);
}
/* browser diagnostics (window.langInfo): 0 off, 1 on, 2 refused; counters of overlay resolutions and directory listings */
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
EMSCRIPTEN_KEEPALIVE
#endif
int port_overlay_state(void) { int s = __atomic_load_n(&g_ov_state, __ATOMIC_RELAXED); return s < 0 ? 0 : s; }
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
uint32_t port_overlay_hits(void) { return __atomic_load_n(&g_ov_hits, __ATOMIC_RELAXED); }

/* Children of a directory node in listing order (the union listing of FindFirstFileA) and lookup by a HOST (UTF-8)
   name; node pointers live until overlay_test_reset. */
int overlay_dir_entry(const void *dir, uint32_t idx, const char **name, const char **host, int *is_dir) {
    OvNode *d = (OvNode *)dir;
    if (!d || !d->is_dir) return 0;
    ov_load(d);
    if (idx >= d->nkids) return 0;
    *name = d->kids[idx]->name; *host = d->kids[idx]->host; *is_dir = d->kids[idx]->is_dir;
    return 1;
}
int overlay_dir_find(const void *dir, const char *host_name, int cp, const char **host, int *is_dir) {
    OvNode *d = (OvNode *)dir;
    if (!d || !d->is_dir) return 0;
    ov_load(d);
    OvNode *k = NULL;
    if (cp && name_has_high(host_name)) {
        for (uint32_t i = 0; i < d->nkids && !k; i++) if (name_fold_eq(host_name, d->kids[i]->name)) k = d->kids[i];
    } else k = ov_ascii_find(d, host_name);
    if (!k) return 0;
    *host = k->host; *is_dir = k->is_dir;
    return 1;
}
/* The key under which two host names are "the same name" for the union listing: Unicode case folding when the CP1251
   layer is on and the name is well-formed UTF-8 with non-ASCII characters, ASCII case folding otherwise. */
void overlay_name_key(const char *name, int cp, char *out, size_t n) {
    size_t o = 0;
    if (cp && name_has_high(name)) {
        int ok = 1;
        for (const unsigned char *p = (const unsigned char *)name; *p && ok;) {
            uint32_t c;
            int len = name_utf8_decode(p, &c);
            if (!len) { ok = 0; break; }
            uint32_t f = name_fold_cp(c);
            size_t need = f < 0x80 ? 1 : f < 0x800 ? 2 : f < 0x10000 ? 3 : 4;
            if (o + need + 1 > n) { ok = 0; break; }
            if (need == 1) out[o++] = (char)f;
            else if (need == 2) { out[o++] = (char)(0xC0 | (f >> 6)); out[o++] = (char)(0x80 | (f & 0x3F)); }
            else if (need == 3) { out[o++] = (char)(0xE0 | (f >> 12)); out[o++] = (char)(0x80 | ((f >> 6) & 0x3F)); out[o++] = (char)(0x80 | (f & 0x3F)); }
            else { out[o++] = (char)(0xF0 | (f >> 18)); out[o++] = (char)(0x80 | ((f >> 12) & 0x3F)); out[o++] = (char)(0x80 | ((f >> 6) & 0x3F)); out[o++] = (char)(0x80 | (f & 0x3F)); }
            p += len;
        }
        if (ok) { out[o] = 0; return; }
        o = 0;
    }
    for (const unsigned char *p = (const unsigned char *)name; *p && o + 1 < n; p++) out[o++] = (char)((*p >= 'A' && *p <= 'Z') ? *p + 32 : *p);
    out[o] = 0;
}

static char g_cwd[1024] = GUEST_ROOT;  /* the game's current directory, in Windows form */

const char *guest_cwd(void) { return g_cwd; }
void guest_set_cwd(const char *p) { snprintf(g_cwd, sizeof g_cwd, "%s", p); }

#ifdef PORT_LAZY_EXPERIMENT
/* Disabled unless both the experimental build flag and an explicit manifest
 * index are present. The immutable tree lives until the worker exits. */
static LazyIndex *g_lazy_index;
static pthread_once_t g_lazy_once = PTHREAD_ONCE_INIT;
static void lazy_init_once(void) {
    const char *file = getenv("PORT_LAZY_INDEX");
    if (!file || !*file) return;
    LazyIndex *index = lazy_index_new();
    if (!index || !lazy_index_load(index, file)) {
        fprintf(stderr, "[lazy] invalid or unreadable namespace index\n");
        lazy_index_free(index); abort();
    }
    g_lazy_index = index;
}
static const LazyNode *lazy_root(void) {
    pthread_once(&g_lazy_once, lazy_init_once);
    return lazy_index_root(g_lazy_index);
}
/* Exactly the same guest root selection as map_path_walk. A stack preserves
 * correct resolution through a missing component followed by '..'. */
const LazyNode *lazy_guest_node(const char *guest) {
    const LazyNode *root = lazy_root();
    if (!root || !guest || !*guest) return NULL;
    char full[1024]; int written;
    if (isalpha((unsigned char)guest[0]) && guest[1] == ':') written = snprintf(full, sizeof full, "%s", guest);
    else if (guest[0] == '\\' || guest[0] == '/') written = snprintf(full, sizeof full, "C:%s", guest);
    else written = snprintf(full, sizeof full, "%s\\%s", g_cwd, guest);
    if (written < 0 || (size_t)written >= sizeof full) return NULL;
    for (char *p = full; *p; p++) if (*p == '/') *p = '\\';
    size_t rl = strlen(GUEST_ROOT);
    if (strncasecmp(full, GUEST_ROOT, rl) || (full[rl] && full[rl] != '\\')) return NULL;
    const LazyNode *stack[512]; const char *parts[512]; size_t lengths[512];
    size_t depth = 0; stack[0] = root;
    const char *p = full + rl;
    while (*p) {
        while (*p == '\\') p++;
        if (!*p) break;
        size_t len = strcspn(p, "\\");
        if (len >= 512) return NULL;
        const char *part = p;
        char comp[512]; memcpy(comp, p, len); comp[len] = 0; p += len;
        if (!strcmp(comp, ".")) continue;
        if (!strcmp(comp, "..")) { if (depth) depth--; continue; }
        if (depth == 511) return NULL;
        parts[depth] = part; lengths[depth] = len;
        stack[depth + 1] = stack[depth] ? lazy_index_child(stack[depth], comp, name_cp1251_on()) : NULL;
        depth++;
    }
    if (!stack[depth]) return NULL;
    /* A physical/overlay file at any ancestor hides indexed descendants.
     * map_path_ov does not call lazy_guest_node, so these probes are safe. */
    char prefix[1024]; size_t used = strlen(GUEST_ROOT);
    memcpy(prefix, GUEST_ROOT, used + 1);
    for (size_t i = 0; i + 1 < depth; i++) {
        if (used + 1 + lengths[i] >= sizeof prefix) return NULL;
        prefix[used++] = '\\'; memcpy(prefix + used, parts[i], lengths[i]);
        used += lengths[i]; prefix[used] = 0;
        char physical[1024]; OvHit ov;
        if (map_path_ov(prefix, physical, sizeof physical, &ov)) {
            if (ov.kind == 1) return NULL;
            if (!ov.kind) { struct stat st; if (!stat(physical, &st) && !S_ISDIR(st.st_mode)) return NULL; }
        }
    }
    return stack[depth];
}
#endif

/* The one walk behind map_path and map_path_ov. With `ovh` NULL it is exactly the original map_path (every overlay
   statement below is behind `ocur`, which stays NULL). With `ovh` it also follows the overlay index in step with the
   base walk and reports what the overlay holds at the final path in *ovh. The returned host path is the BASE one in
   both cases; where a component does not exist in the base but does in the overlay, the overlay's real name is used
   instead of the guest's spelling, so that every spelling of one overlay-only file maps to one canonical host path. */
static int map_path_walk(const char *guest, char *host, size_t n, OvHit *ovh) {
    char full[1024];
    /* make absolute in Windows form */
    if (isalpha((unsigned char)guest[0]) && guest[1] == ':')
        snprintf(full, sizeof full, "%s", guest);
    else if (guest[0] == '\\' || guest[0] == '/')
        snprintf(full, sizeof full, "C:%s", guest);
    else
        snprintf(full, sizeof full, "%s\\%s", g_cwd, guest);
    for (char *p = full; *p; p++) if (*p == '/') *p = '\\';

    const char *rest;
    const char *base;
    OvNode *ocur = NULL;   /* overlay node of the current path (valid while omiss == 0); NULL: no overlay for this path */
    int omiss = 0;         /* components below the deepest node the overlay holds */
#ifdef PORT_LAZY_EXPERIMENT
    const LazyNode *lcur = NULL;
    int lmiss = 0;
#endif
    size_t rl = strlen(GUEST_ROOT);
    if (!strncasecmp(full, GUEST_ROOT, rl) && (full[rl] == '\\' || full[rl] == 0)) {
        base = g_game_root;
        rest = full + rl;
        if (ovh) ocur = g_ov_root;
#ifdef PORT_LAZY_EXPERIMENT
        lcur = lazy_root();
#endif
    } else {
        base = g_user_root;  /* anything outside the game folder: profiles, temp files, ... */
        rest = full + 2;
    }

    char out[1024];
    snprintf(out, sizeof out, "%s", base);
    int exists = 1;
    char comp[512];
    while (*rest) {
        while (*rest == '\\') rest++;
        if (!*rest) break;
        size_t k = 0;
        while (rest[k] && rest[k] != '\\') k++;
        snprintf(comp, sizeof comp, "%.*s", (int)k, rest);
        rest += k;
        if (!strcmp(comp, ".")) continue;
        if (!strcmp(comp, "..")) {
            char *sl = strrchr(out, '/');
            if (sl && sl > out + strlen(base) - 1) {
                *sl = 0;
                if (ocur) { if (omiss) omiss--; else if (ocur->parent) ocur = ocur->parent; }
#ifdef PORT_LAZY_EXPERIMENT
                if (lcur) { if (lmiss) lmiss--; else if (lazy_index_parent(lcur)) lcur = lazy_index_parent(lcur); }
#endif
            }
            continue;
        }
        OvNode *ochild = NULL;
#ifdef PORT_LAZY_EXPERIMENT
        const LazyNode *lchild = NULL;
        if (lcur) {
            if (!lmiss) { lchild = lazy_index_child(lcur, comp, name_cp1251_on()); if (lchild) lcur = lchild; else lmiss = 1; }
            else lmiss++;
        }
#endif
        if (ocur) {
            if (!omiss) { ochild = ov_find(ocur, comp); if (ochild) ocur = ochild; else omiss = 1; }
            else omiss++;
        }
        char real[512];
        /* PORT_NAME_CP1251: the component's bytes >= 0x80 are Windows-1251 and the host name is their UTF-8.
           An existing entry is found with the Unicode case folding; if none is, an entry spelled with exactly
           the guest's bytes (a name an earlier run created with the layer off) still resolves, so nothing the
           player already has becomes unreachable; a new name is created in UTF-8. */
        if (name_has_high(comp) && name_cp1251_on()) {
            char u[1024];
            if (!name_guest_to_host(comp, u, sizeof u)) { exists = 0; snprintf(u, sizeof u, "%s", comp); }
            const char *use = u;
            if (exists && find_ci_fold(out, u, real, sizeof real)) use = real;
            else if (exists && find_ci(out, comp, real, sizeof real)) { use = real; name_log("guest name resolved to an existing entry with the guest's own bytes (legacy)", comp); }
            else { exists = 0; if (ochild) use = ochild->name;
#ifdef PORT_LAZY_EXPERIMENT
                else if (lchild) use = lazy_index_name(lchild);
#endif
            }
            name_log("guest name (CP1251) as UTF-8 on the host", comp);
            size_t L = strlen(out);
            snprintf(out + L, sizeof out - L, "/%s", use);
            continue;
        }
        if (exists && find_ci(out, comp, real, sizeof real)) {
            size_t L = strlen(out);
            snprintf(out + L, sizeof out - L, "/%s", real);
        } else {
            exists = 0;
            size_t L = strlen(out);
            const char *use = ochild ? ochild->name : comp;
#ifdef PORT_LAZY_EXPERIMENT
            if (!ochild && lchild) use = lazy_index_name(lchild);
#endif
            snprintf(out + L, sizeof out - L, "/%s", use);
        }
    }
    snprintf(host, n, "%s", out);
    if (ovh) {
        if (ocur && !omiss && ocur != g_ov_root) {
            ovh->kind = ocur->is_dir ? 2 : 1;
            ovh->node = ocur;
            snprintf(ovh->host, sizeof ovh->host, "%s", ocur->host);
            __atomic_add_fetch(&g_ov_hits, 1, __ATOMIC_RELAXED);
        }
    }
    struct stat st;
    return stat(host, &st) == 0;
}

int map_path(const char *guest, char *host, size_t n) { return map_path_walk(guest, host, n, NULL); }

/* The overlay-aware map_path: *ov says what the overlay holds at this path (kind 0 none, 1 file, 2 directory; host is
   then the overlay's physical path, READ ONLY, node its index entry); `host` is the canonical base-rooted path as map_path
   gives it. The result is 1 when the logical path exists: in the base or in the overlay. */
int map_path_ov(const char *guest, char *host, size_t n, OvHit *ov) {
    ov->kind = 0;
    ov->node = NULL;
    if (__builtin_expect(!overlay_active(), 1)) return map_path_walk(guest, host, n, NULL);
    int exists = map_path_walk(guest, host, n, ov);
    return exists || ov->kind;
}

/* ------------------------------------------------------------------ time */

uint64_t host_time_100ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ((uint64_t)ts.tv_sec + 11644473600ull) * 10000000ull + (uint64_t)ts.tv_nsec / 100;
}

/* Seconds since the process started, plus a minute: like uptime on a freshly booted PC. Games turn
   GetTickCount/timeGetTime into 32-bit floats, so the values must stay small; the raw monotonic clock
   is epoch-based in WebAssembly (~1.8e12 ms) and broke EA's timer scheduling there. */
double host_seconds(void) {
    static double start = -1;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    double now = (double)ts.tv_sec + ts.tv_nsec * 1e-9;
    if (start < 0) start = now;   /* first call happens during startup, before other threads exist */
    return now - start + 60.0;
}

/* ------------------------------------------------------------------ the game's clock */

/* With PORT_DETERMINISTIC=1 the game sees a virtual clock driven by the deterministic scheduler (sched.c):
   it jumps to the next deadline when every thread is blocked, and every read adds 1 us so a spin-wait on
   the clock still makes progress. Present blocks until the next 1/60 s tick (vsync). */
static int g_det = -1;
uint64_t g_vtime_us;             /* virtual microseconds (sched.c advances it) */
uint32_t g_det_sleeps, g_det_waits, g_det_reads;   /* game-thread counters for the hash log */
static GuestThread g_main_thread;

int deterministic(void) {
    if (g_det < 0) g_det = getenv("PORT_DETERMINISTIC") != NULL;
    return g_det;
}
int on_game_thread(void) { return t_self == &g_main_thread; }

double guest_seconds(void) {
    if (!deterministic()) return host_seconds();
    if (on_game_thread()) g_det_reads++;
    return 60.0 + (double)__atomic_add_fetch(&g_vtime_us, 1, __ATOMIC_RELAXED) * 1e-6;
}
double guest_peek_seconds(void) {   /* the game's clock without advancing it */
    if (!deterministic()) return host_seconds();
    return 60.0 + (double)__atomic_load_n(&g_vtime_us, __ATOMIC_RELAXED) * 1e-6;
}
uint64_t guest_time_100ns(void) {
    if (!deterministic()) return host_time_100ns();
    /* 2006-01-01 00:00 UTC in FILETIME units, plus the virtual clock */
    return 127804032000000000ull + (uint64_t)((guest_seconds() - 60.0) * 1e7);
}
/* Present: wait for the next vsync tick (exact multiples of 1/60 s); online, the frame lasts the time the
   host measured for it (netplay.c), counted from the previous frame's boundary. */
void vclock_frame(void) {
    if (!deterministic() || !on_game_thread()) return;
    extern int sched_wait(int (*)(void *), void *, uint64_t, uint64_t (*)(void));
    extern uint32_t netplay_frame_dt_us(void);
    uint64_t now = __atomic_load_n(&g_vtime_us, __ATOMIC_RELAXED);
    uint32_t dt = netplay_frame_dt_us();
    if (dt) {
        static uint64_t boundary;
        boundary += dt;
        if (boundary < now) boundary = now;   /* the frame already took longer in game time (loading) */
        sched_wait(NULL, NULL, boundary, NULL);
        return;
    }
    uint64_t k = now * 60ull / 1000000ull + 1;
    sched_wait(NULL, NULL, (k * 1000000ull + 59ull) / 60ull, NULL);
}
static uint64_t vclock_rdtsc(void) { return (uint64_t)(guest_seconds() * 2e9); }   /* 2 GHz, as the registry says */
/* A thread preempted after a full quantum has used CPU time, so the clock moves on by PORT_DET_PREEMPT_US
   (default 1000) before the next participant is picked. Without it a thread that spins on memory without
   reading the clock (Cricket's loading screen polling its async loader) never lets a timer come due, and
   the timer callback it waits for never runs. */
static void vclock_preempt(void) {
    static int64_t us = -1;
    if (us < 0) { const char *e = getenv("PORT_DET_PREEMPT_US"); us = e ? atoll(e) : 1000; }
    __atomic_add_fetch(&g_vtime_us, (uint64_t)us, __ATOMIC_RELAXED);
    sched_yield_det();
}
void vclock_init(void) {
    extern uint64_t (*g_rdtsc_hook)(void);
    extern int g_preempt_on;
    extern void (*g_preempt_fn)(void);
    if (deterministic()) {
        g_rdtsc_hook = vclock_rdtsc;
        g_preempt_fn = vclock_preempt;
        g_preempt_on = 1;
        fprintf(stderr, "deterministic mode: virtual clock + scheduler\n");
    }
}

/* ------------------------------------------------------------------ threads */

__thread GuestThread *t_self;

GuestThread *thread_main_init(CPU *c) {
    (void)c;
    g_main_thread.id = 0x100;
    g_main_thread.tib = GUEST_TIB;
    t_self = &g_main_thread;
    return t_self;
}
