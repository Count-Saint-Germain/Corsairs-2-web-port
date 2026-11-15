/* K3: нагрузочный тест кучи гостя на реальных host/core.c + com.c + dsound.c с -DPORT_HEAP_STATS.
   Паттерн по наблюдениям Node-прогона игры ([dsstats]): пачки из 2-5 вторичных буферов DirectSound по 100-470 KB
   (создание, дубликаты, освобождение в произвольном порядке) на фоне долгоживущих блоков движка и
   временных D3D-блоков 112 912 байт. Проверяет: (1) после освобождения всего счётчики возвращаются
   в ноль (нет утечки хранилищ PCM и блоков), (2) в процессе протяжённость кучи ограничена по отношению
   к живым байтам (регресс-защита от неограниченной фрагментации), (3) обход [heapstats] не находит битых
   заголовков. Печатает пиковые значения. Это тест кода хоста, а не воспроизведение аварии из браузера. */
#define PORT_HEAP_STATS 1
#include <assert.h>
#include <stdatomic.h>
#include "../host/core.c"
#include "../host/com.c"
#include "../host/dsound.c"

uint8_t *g_mem;
__thread uint32_t g_import_target;

void kernel_set_event(uint32_t h) { (void)h; }
uint32_t add_dynamic_import(const char *name, GuestFn fn) {
    static uint32_t next;
    (void)name; (void)fn;
    return IMPORT_BASE + 16 * next++;
}
void guest_trap(CPU *c, uint32_t addr, const char *msg) { (void)c; (void)addr; (void)msg; abort(); }
void *sched_new(const char *name, int (*start)(void *), void *arg) { (void)name; (void)start; (void)arg; return NULL; }
void sched_enter(void *p) { (void)p; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline, uint64_t (*fn)(void)) {
    (void)pred; (void)arg; (void)deadline; (void)fn; return 0;
}

static void args(CPU *c, uint32_t self, uint32_t a, uint32_t b, uint32_t d) {
    memset(c, 0, sizeof *c);
    c->esp = 64;
    W32(68, self); W32(72, a); W32(76, b); W32(80, d);
}
static uint32_t ds_create(uint32_t size) {
    W32(0x1004, 0); W32(0x1008, size); W32(0x1010, 0);
    return new_buffer(0x1000, 1);
}
static void ds_release(uint32_t p) { CPU c; args(&c, p, 0, 0, 0); sound_Release(&c); }
static uint32_t ds_duplicate(uint32_t p) {
    CPU c; args(&c, 0, p, 0x2000, 0); ds_DuplicateSoundBuffer(&c);
    assert(c.eax == S_OK); return R32(0x2000);
}

static uint32_t rng_state = 12345;
static uint32_t rnd(void) { rng_state = rng_state * 1664525u + 1013904223u; return rng_state >> 8; }

#define BG 300
#define MAXDS 8
static uint32_t bg[BG], ds[MAXDS], ds_n;
static uint32_t pick_size(void) {   /* в основном мелочь движка, изредка крупные блоки */
    uint32_t r = rnd() % 100;
    if (r < 80) return 16 + rnd() % 2000;
    if (r < 97) return 2048 + rnd() % 30000;
    return 60000 + rnd() % 200000;
}

int main(void) {
    g_mem = calloc(1, (size_t)GUEST_HEAP_BASE + (96u << 20));
    assert(g_mem);
    for (int i = 0; i < BG; i++) bg[i] = heap_alloc(pick_size(), 0);
    uint32_t peak_extent = 0; uint64_t peak_live = 0;
    GuestHeapStats s;
    for (int it = 0; it < 120000; it++) {
        /* фон: заменяем несколько случайных блоков */
        for (int k = 0; k < 2; k++) { int i = (int)(rnd() % BG); heap_free(bg[i]); bg[i] = heap_alloc(pick_size(), 0); }
        /* DirectSound: пачка буферов, освобождаются в произвольном порядке */
        if (ds_n < MAXDS && rnd() % 3 == 0) {
            uint32_t b = ds_create(100000 + rnd() % 380000);
            assert(b);
            ds[ds_n++] = b;
            if (ds_n < MAXDS && rnd() % 2) ds[ds_n++] = ds_duplicate(b);
        }
        if (ds_n && rnd() % 3 == 0) { uint32_t i = rnd() % ds_n; ds_release(ds[i]); ds[i] = ds[--ds_n]; }
        /* временный блок D3D (поверхность/буфер 112 896 + 16) */
        if (it % 7 == 0) { uint32_t t = heap_alloc(112896 + 16, 1); heap_free(t); }
        if (it % 2000 == 0) {
            guest_heap_walk_stats(&s);
            assert(s.bad == 0);
            if (s.extent > peak_extent) peak_extent = s.extent;
            if (s.live_capacity > peak_live) peak_live = s.live_capacity;
        }
    }
    dsound_stats_log();
    guest_heap_stats_log();
    uint64_t ratio_x100 = (uint64_t)peak_extent * 100 / peak_live;
    printf("churn: peak extent %u KB, peak live %llu KB, peak extent/peak live %llu.%02llu\n", peak_extent >> 10,
           (unsigned long long)(peak_live >> 10), (unsigned long long)ratio_x100 / 100, (unsigned long long)ratio_x100 % 100);
    /* Измерено 2,89 (первое-подходящее по LIFO-списку крупных блоков; best-fit на том же паттерне даёт 1,41).
       Порог 4,0 — защита от неограниченного роста, а не цель: паттерн синтетический и намеренно жёсткий. */
    assert(ratio_x100 < 400);
    /* всё освободить: нет утечки */
    for (uint32_t i = 0; i < ds_n; i++) ds_release(ds[i]);
    assert(!g_bufs);
    for (int i = 0; i < BG; i++) heap_free(bg[i]);
    guest_heap_walk_stats(&s);
    /* остаются только таблицы виртуальных методов COM интерфейсов (строятся один раз, не освобождаются) */
    printf("after release: live %u blocks %llu bytes (vtables), free-inside %u blocks\n", s.live_blocks, (unsigned long long)s.live_capacity, s.free_blocks);
    assert(s.bad == 0 && s.live_blocks <= 4 && s.live_capacity <= 1024);
    free(g_mem);
    puts("heap churn test PASS");
    return 0;
}
