/* Диагностический проход по куче гостя (core.c, только с -DPORT_HEAP_STATS): точные счётчики
   живых/свободных блоков на известной раскладке, повреждённый заголовок, только-чтение,
   параллельный обход при работающем аллокаторе. Это тест счётчика, а не причины аварии
   "guest heap exhausted". */
#define PORT_HEAP_STATS 1
#include "../host/core.c"

#include <assert.h>

uint8_t *g_mem;

static void reset_heap(void) {
    g_heap_top = HEAP_LO;
    g_heap_last = 0;
    memset(g_free, 0, sizeof g_free);
}

static void test_layout(void) {
    reset_heap();
    uint32_t a = heap_alloc(100, 0), b = heap_alloc(1000, 0), c = heap_alloc(5000, 0), guard = heap_alloc(32, 0);
    GuestHeapStats s;
    guest_heap_walk_stats(&s);
    assert(s.bad == 0 && s.live_blocks == 4 && s.free_blocks == 0);
    assert(s.live_capacity == 112u + 1008u + 5008u + 32u);
    assert(s.live_requested == 100u + 1000u + 5000u + 32u);
    assert(s.extent == s.live_capacity + 4u * 16u);
    heap_free(b);   /* свободный блок внутри кучи: фрагментация, а не конец */
    guest_heap_walk_stats(&s);
    assert(s.bad == 0 && s.live_blocks == 3 && s.free_blocks == 1);
    assert(s.free_capacity == 1008u && s.largest_free == 1008u);
    assert(s.live_capacity == 112u + 5008u + 32u && s.live_requested == 100u + 5000u + 32u);
    assert(s.extent == 112u + 1008u + 5008u + 32u + 4u * 16u);   /* протяжённость не уменьшилась */
    assert(s.live_by_log2[6] == 1 && s.live_by_log2[12] == 1 && s.live_by_log2[5] == 1);
    heap_free(a);   /* сливается с соседним свободным */
    guest_heap_walk_stats(&s);
    assert(s.free_blocks == 1 && s.free_capacity == 112u + 16u + 1008u && s.live_blocks == 2);
    heap_free(c); heap_free(guard);
    guest_heap_walk_stats(&s);
    assert(s.extent == 0 && s.live_blocks == 0 && s.free_blocks == 0 && s.bad == 0 && s.live_capacity == 0);
    guest_heap_stats_log();   /* печать не падает на пустой куче */
}

static void test_read_only_and_corruption(void) {
    reset_heap();
    uint32_t a = heap_alloc(64, 1), b = heap_alloc(64, 1), c = heap_alloc(64, 1), guard = heap_alloc(16, 0);
    size_t n = (size_t)g_heap_top - HEAP_LO;
    uint8_t *before = malloc(n);
    memcpy(before, g_mem + HEAP_LO, n);
    GuestHeapStats s;
    guest_heap_walk_stats(&s);
    guest_heap_stats_log();
    assert(!memcmp(before, g_mem + HEAP_LO, n) && s.bad == 0 && s.live_blocks == 4);
    uint32_t save = R32(b - 12);
    W32(b - 12, 0x12345678u);   /* повреждённый magic: проход останавливается, не выходя за границы */
    guest_heap_walk_stats(&s);
    assert(s.bad == 1 && s.live_blocks == 1);
    W32(b - 12, save);
    uint32_t cap = R32(c - 16);
    W32(c - 16, 0xffffff00u);   /* ёмкость за пределами кучи */
    guest_heap_walk_stats(&s);
    assert(s.bad == 1 && s.live_blocks == 2);
    W32(c - 16, 7);             /* не кратна 16 */
    guest_heap_walk_stats(&s);
    assert(s.bad == 1);
    W32(c - 16, 0);             /* нулевая ёмкость — иначе бесконечный цикл */
    guest_heap_walk_stats(&s);
    assert(s.bad == 1);
    W32(c - 16, cap);
    guest_heap_walk_stats(&s);
    assert(s.bad == 0 && s.live_blocks == 4);
    heap_free(a); heap_free(b); heap_free(c); heap_free(guard);
    free(before);
}

static volatile int g_stop;
static void *churn(void *arg) {
    uint32_t state = (uint32_t)(uintptr_t)arg + 7;
    uint32_t keep[64] = {0};
    while (!g_stop) {
        state = state * 1664525u + 1013904223u;
        unsigned i = (state >> 8) % 64;
        if (keep[i]) { heap_free(keep[i]); keep[i] = 0; }
        else keep[i] = heap_alloc(16 + state % 8192, 0);
    }
    for (int i = 0; i < 64; i++) heap_free(keep[i]);
    return NULL;
}

static void test_concurrent_walk(void) {
    reset_heap();
    pthread_t t[4];
    for (uintptr_t i = 0; i < 4; i++) assert(!pthread_create(&t[i], NULL, churn, (void *)i));
    for (int i = 0; i < 300; i++) {
        GuestHeapStats s;
        guest_heap_walk_stats(&s);
        assert(s.bad == 0 && s.live_capacity + s.free_capacity + 16ull * (s.live_blocks + s.free_blocks) == s.extent);
    }
    g_stop = 1;
    for (int i = 0; i < 4; i++) assert(!pthread_join(t[i], NULL));
    GuestHeapStats s;
    guest_heap_walk_stats(&s);
    assert(s.live_blocks == 0 && s.extent == 0);
}

/* Порог-предупреждение и снимок при отказе выделения (K3): чистая функция яруса и безопасность печати. */
static void test_warn_tier_and_failure_log(void) {
    const uint32_t H = 100u << 20;   /* кратно 100: пороги в процентах точны */
    assert(guest_heap_warn_tier(0, H, 70) == 0);
    assert(guest_heap_warn_tier(H / 100 * 69, H, 70) == 0);          /* ниже порога */
    assert(guest_heap_warn_tier(H / 100 * 70, H, 70) == 1);          /* ровно порог */
    assert(guest_heap_warn_tier(H / 100 * 74, H, 70) == 1);
    assert(guest_heap_warn_tier(H / 100 * 75, H, 70) == 2);          /* +5 п.п. — следующий ярус */
    assert(guest_heap_warn_tier(H, H, 70) == 1 + 30 / 5);            /* 100 % */
    assert(guest_heap_warn_tier(100, 0, 70) == 0);                   /* нулевой размер кучи не делит на ноль */
    assert(heap_warn_pct() == 70);                                   /* по умолчанию */

    /* Failure diagnostics under PORT_HEAP_STATS also must not wait on the lock. */
    GuestHeapStats busy;
    assert(!pthread_mutex_lock(&g_heap_lock));
    assert(!guest_heap_walk_stats_impl(&busy, 1));
    guest_heap_failure_log(112912, 1);
    assert(!pthread_mutex_unlock(&g_heap_lock));

    reset_heap();
    uint32_t a = heap_alloc(4096, 0), b = heap_alloc(64, 0), c = heap_alloc(8192, 0), guard = heap_alloc(32, 0);
    heap_free(a);                                                    /* свободный блок внутри */
    heap_free(c);
    GuestHeapStats s;
    guest_heap_walk_stats(&s);
    assert(s.free_blocks == 2 && s.live_blocks == 2);
    guest_heap_failure_log(112912, 0);                               /* только печать: куча не меняется */
    guest_heap_failure_log(112912, 1);                               /* fatal-вариант печатает, abort вызывает вызывающий */
    GuestHeapStats t;
    guest_heap_walk_stats(&t);
    assert(!memcmp(&s, &t, sizeof s));
    guest_heap_stats_log();                                          /* включает проверку порога, не падает */
    heap_free(b); heap_free(guard);
}

int main(void) {
    g_mem = calloc(1, (size_t)HEAP_LO + (32u << 20));
    assert(g_mem);
    test_layout();
    test_read_only_and_corruption();
    test_concurrent_walk();
    test_warn_tier_and_failure_log();
    free(g_mem);
    puts("guest heap stats tests passed");
}
