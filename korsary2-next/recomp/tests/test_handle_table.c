/* Таблица дескрипторов core.c: многопоточные open/close/get в режиме по умолчанию (permissive) и strict.

   Находка CP1251-агента: handle_close/handle_get писали и читали таблицу без блокировки, TSan показывал
   гонку при открытии/закрытии из двух гостевых потоков. Этот тест воспроизводит её (на старом core.c он
   падает под TSan) и закрепляет исправление: настоящие core.c и kernel32.c, синтетические файлы во
   временной папке, игра не запускается.

   Что проверяется
     A  один поток: значения handles (младший свободный слот, round-robin), недопустимые значения,
        двойное закрытие, H_RESERVED, исчерпание таблицы, закрытие fd/буферов;
     B  N потоков на «сыром» API (handle_new/get/close, reserve/publish/cancel/close_checked): реестр
        владельцев ловит двойную выдачу одного значения, метка в слоте ловит затирание чужим потоком;
     C  N потоков на настоящих обработчиках kernel32 (CreateEvent/Mutex/Semaphore/File/Find, ReadFile,
        CloseHandle ...) плюс «зонд»-потоки: GetFileType/SetEvent по случайным и устаревшим значениям;
     D  handle получен одним потоком, закрыт другим, потом используется: ERROR_INVALID_HANDLE;
     E  (HT_RACY=1, только ASan, не для TSan) гонка «использование во время закрытия» того же handle:
        остаточный риск, не ошибка таблицы;
     F  ожидания (WaitForSingleObject): handle закрыт другим потоком во время ожидания -> WAIT_FAILED/ERROR_INVALID_HANDLE
        без зависания; слот выдан заново под другой объект -> ожидание его не трогает; сигнал до закрытия побеждает;
        ожидание на закрытом/несинхронизационном handle как прежде (WAIT_OBJECT_0); стресс закрытий и ожиданий;
     G  потоки гостя: CloseHandle(thread) очищает g_threads_by_handle, ResumeThread по закрытому значению ничего не
        возобновляет, WaitForSingleObject/GetExitCodeThread по живому handle работают (настоящие потоки: не в wasm);
     H  CreateFileMappingA: CloseHandle маппинга закрывает его dup()-fd (в permissive и strict), нет утечки fd;
     I  снимок против писателя (файл читается снимком, пока открыт писатель): фиксирует текущий контракт, см. docs.
   Usage: test [scratch-dir [unset|1 [threads [iters]]]]. HT_THREADS/HT_ITERS/HT_RAW_ITERS задают то же
   через окружение; HT_RACY=1 включает E. Режим выбирает PORT_STRICT_FILE_SHARE. */
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <sched.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#ifndef __EMSCRIPTEN__
#include <sys/mman.h>
#endif
#include "../host/core.c"
#include "../host/kernel32.c"
#ifdef HT_OLD_TREE   /* the test run against the tree before the wait/thread/mapping fixes (run_handle_table.sh before-tails): same API on top of the old one */
uint32_t handle_reserve_ptr(void *ptr) { uint32_t h = handle_try_new(H_RESERVED); if (h) handle_reserved(h)->ptr = ptr; return h; }   /* handle_try_new/handle_reserved exist in every older tree */
int handle_snapshot(uint32_t h, void **ptr) { WinHandle *x = handle_get(h, -1); if (!x) return H_FREE; *ptr = x->ptr; return x->type; }
#endif
uint8_t *g_mem;
/* WaitForSingleObject lives in kernel32.c; the deterministic scheduler (sched.c) and the code range are not linked here */
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
/* The deterministic scheduler is not linked: sched_active() is off except in part F7, where these stubs stand in for it
   (a parked waiter polls its predicate until the deadline, like the scheduler evaluates can_acquire for a parked thread). */
static int g_sched_on;
static uint32_t g_sched_parked;
static pthread_mutex_t g_fake_baton = PTHREAD_MUTEX_INITIALIZER;   /* the real scheduler evaluates predicates only while no other participant runs: this lock stands for that */
static uint64_t real_now_us(void) { struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t); return (uint64_t)t.tv_sec * 1000000ull + (uint64_t)t.tv_nsec / 1000u; }
int sched_active(void) { return __atomic_load_n(&g_sched_on, __ATOMIC_ACQUIRE); }
uint64_t sched_now_us(void) { return real_now_us(); }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) {
    (void)deadline_fn;
    __atomic_fetch_add(&g_sched_parked, 1, __ATOMIC_RELEASE);
    for (;;) {
        pthread_mutex_lock(&g_fake_baton);
        int ok = pred && pred(arg);
        pthread_mutex_unlock(&g_fake_baton);
        if (ok) return 1;
        if (real_now_us() >= deadline_us) return 0;
        usleep(200);
    }
}
/* W(CreateThread) starts a real host thread that calls into the guest; here "the guest" is this stub: it returns param + 7
   (the exit code), and a start address of 0x777 first waits for g_thr_release (a thread that stays running on demand). */
static volatile int g_thr_release;
static uint32_t g_thr_runs;
void call_indirect(CPU *c, uint32_t target) {
    uint32_t param = R32(c->esp + 4);   /* PUSH32(param), PUSH32(GUEST_RETURN_SENTINEL) */
    __atomic_fetch_add(&g_thr_runs, 1, __ATOMIC_RELAXED);
    if (target == 0x777) while (!__atomic_load_n(&g_thr_release, __ATOMIC_ACQUIRE)) usleep(200);
    c->eax = param + 7;
}
void *sched_new(const char *name, int (*start)(void *), void *arg) { (void)name; (void)start; (void)arg; return NULL; }
void sched_enter(void *rec) { (void)rec; }
void sched_exit(void) {}
void fpu_sync_rounding(CPU *c) { (void)c; }

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)
#define GENERIC_READ 0x80000000u
#define GENERIC_WRITE 0x40000000u
#define INVALID 0xffffffffu
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define FSHARE_R 1
#define FSHARE_RW 3

static int strict;
static char root[1024];
static int g_threads = 8;
static long g_iters = 3000;       /* guest-level operations per thread (part C) */
static long g_raw_iters = 20000;  /* raw table operations per thread (part B) */

/* ---- guest threads: CPU + GuestThread + a private slice of guest memory ---- */
typedef struct { CPU c; GuestThread th; uint32_t base; } Eng;
#define MAXENG 24
#define SLICE 0x8000u
static Eng g_eng[MAXENG];
static __thread uint32_t g_err;
static void eng_init(Eng *e, int idx) { memset(e, 0, sizeof *e); e->base = 0x1000u + (uint32_t)idx * SLICE; }
static uint32_t call(Eng *e, void (*fn)(CPU *), int n, const uint32_t *a) {
    t_self = &e->th;
    e->th.last_error = 0xdeadu;
    e->c.esp = e->base + 0x100;
    W32(e->c.esp, 0);
    for (int i = 0; i < n; i++) W32(e->c.esp + 4 + 4u * (uint32_t)i, a[i]);
    fn(&e->c);
    g_err = e->th.last_error;
    return e->c.eax;
}
static uint32_t gstr(Eng *e, int k, const char *s) {
    uint32_t at = e->base + 0x400u + (uint32_t)k * 0x800u;
    CHECK(strlen(s) < 0x7f0);
    strcpy((char *)HP(at), s);
    return at;
}
static uint32_t cf(Eng *e, const char *name, uint32_t access, uint32_t share, uint32_t disp) {
    uint32_t a[7] = { gstr(e, 0, name), access, share, 0, disp, 0, 0 };
    return call(e, w_CreateFileA, 7, a);
}
static uint32_t ch(Eng *e, uint32_t h) { uint32_t a[1] = { h }; return call(e, w_CloseHandle, 1, a); }
static uint32_t rd(Eng *e, uint32_t h, void *buf, uint32_t n) {
    uint32_t out = e->base + 0x200u, data = e->base + 0x3000u;
    uint32_t a[5] = { h, data, n, out, 0 };
    uint32_t ok = call(e, w_ReadFile, 5, a);
    if (!ok) return INVALID;
    uint32_t got = R32(out);
    memcpy(buf, HP(data), got);
    return got;
}
static uint32_t wr(Eng *e, uint32_t h, const void *buf, uint32_t n) {
    uint32_t out = e->base + 0x200u, data = e->base + 0x3000u;
    memcpy(HP(data), buf, n);
    uint32_t a[5] = { h, data, n, out, 0 };
    return call(e, w_WriteFile, 5, a) ? R32(out) : INVALID;
}
static uint32_t c1(Eng *e, void (*fn)(CPU *), uint32_t a0) { uint32_t a[1] = { a0 }; return call(e, fn, 1, a); }
static uint32_t c2(Eng *e, void (*fn)(CPU *), uint32_t a0, uint32_t a1) { uint32_t a[2] = { a0, a1 }; return call(e, fn, 2, a); }

static int open_fdsrc(void) {   /* a real fd for the raw-table handles (a plain file: WasmFS has no /dev/null guarantee) */
    char p[1200];
    snprintf(p, sizeof p, "%s/fdsrc.bin", root);
    int fd = open(p, O_RDONLY);
    CHECK(fd >= 0);
    return fd;
}
static void put(const char *name, const char *content) {
    char p[1200];
    snprintf(p, sizeof p, "%s/%s", root, name);
    FILE *f = fopen(p, "wb");
    CHECK(f && fputs(content, f) >= 0 && !fclose(f));
}

typedef struct { pthread_mutex_t m; pthread_cond_t cv; int n, arrived, gen; } Barrier;
static void barrier_init(Barrier *b, int n) { pthread_mutex_init(&b->m, NULL); pthread_cond_init(&b->cv, NULL); b->n = n; b->arrived = b->gen = 0; }
static void barrier_wait(Barrier *b) {
    pthread_mutex_lock(&b->m);
    int g = b->gen;
    if (++b->arrived == b->n) { b->arrived = 0; b->gen++; pthread_cond_broadcast(&b->cv); }
    else while (g == b->gen) pthread_cond_wait(&b->cv, &b->m);
    pthread_mutex_unlock(&b->m);
}

static uint32_t rnd(uint32_t *s) { uint32_t x = *s; x ^= x << 13; x ^= x >> 17; x ^= x << 5; return *s = x; }
static int slot_of(uint32_t h) { return (int)((h - 0x1000u) / 4u); }

/* ------------------------------------------------------------------------------------------ */
/* A: single thread                                                                              */
/* ------------------------------------------------------------------------------------------ */
static void t_single(void) {
    /* handle values: the lowest free slot (permissive default) or after the last one (round-robin) */
    handle_set_round_robin(0);
    uint32_t a = handle_new(H_EVENT), b = handle_new(H_MUTEX), c = handle_new(H_MISC);
    CHECK(a == 0x1040u && b == 0x1044u && c == 0x1048u);
    CHECK(handle_get(a, H_EVENT) && handle_get(a, -1) && !handle_get(a, H_MUTEX));
    CHECK(handle_get(b, H_MUTEX) && !handle_get(b, H_EVENT));
    handle_close(b);
    CHECK(!handle_get(b, -1) && !handle_get(b, H_MUTEX));          /* closed: not found, any type */
    handle_close(b);                                                /* double close: silent no-op */
    CHECK(handle_new(H_SEMAPHORE) == 0x1044u);                      /* the lowest free slot again */
    handle_close(0x1044u); handle_close(a); handle_close(c);
    CHECK(!handle_get(a, -1) && !handle_get(c, -1));

    /* values that are never table handles */
    static const uint32_t bad[] = { 0, 1, 3, 0x0fffu, 0x1000u, 0x1001u, 0x103cu, 0x1000u + 4u * 4096u, 0x1000u + 4u * 4097u,
                                    0x1fffffffu, 0xfffffffeu, 0xffffffffu, 0x0f4u };
    for (size_t i = 0; i < sizeof bad / sizeof *bad; i++) {
        CHECK(!handle_get(bad[i], -1) && !handle_reserved(bad[i]));
        handle_close(bad[i]); handle_publish(bad[i], H_FILE); handle_cancel(bad[i]);
        CHECK(handle_close_checked(bad[i]) == 0);
    }

    /* H_RESERVED: allocated but not a handle: invisible to get, closable only by cancel/close_checked of the owner */
    uint32_t r = handle_try_new(H_RESERVED);
    CHECK(r == 0x1040u && !handle_get(r, -1) && !handle_get(r, H_RESERVED) && handle_reserved(r));
    handle_close(r);                                                /* a guest close never touches a reserved slot */
    CHECK(handle_reserved(r));
    CHECK(handle_close_checked(r) == 0);
    handle_publish(r, H_MISC);
    CHECK(handle_get(r, H_MISC) && !handle_reserved(r));
    CHECK(handle_close_checked(r) == 1 && handle_close_checked(r) == 0);
    r = handle_try_new(H_RESERVED);
    handle_cancel(r);
    CHECK(!handle_reserved(r) && !handle_get(r, -1));
    CHECK(handle_try_new(H_RESERVED) == r);                          /* cancel frees the slot */
    handle_cancel(r);

    /* a file handle owns its fd and snapshot buffer: close releases both */
    int fd = open_fdsrc();
    CHECK(fd >= 0);
    uint32_t f = handle_new(H_FILE);
    WinHandle *x = handle_get(f, H_FILE);
    CHECK(x && x->fd == -1);                                         /* a fresh slot is zeroed, fd -1 */
    x->fd = fd; x->buf = malloc(64); x->buf_size = 64;
    handle_close(f);
    CHECK(fcntl(fd, F_GETFD) == -1 && errno == EBADF);               /* the fd was closed */
    uint32_t fi = handle_new(H_FIND);
    handle_get(fi, H_FIND)->ptr = malloc(64);
    handle_close(fi);                                                /* ASan: the FIND state is freed once */

    /* exhaustion: the table holds 4080 handles (slots 16..4095), then 0, never an abort in try_new */
    {
        static uint32_t all[4096];
        int n = 0;
        uint32_t h;
        while ((h = handle_try_new(H_MISC))) all[n++] = h;
        CHECK(n == 4096 - 16);
        CHECK(all[0] == 0x1040u && all[n - 1] == 0x1000u + 4u * 4095u);
        handle_close(all[7]);
        uint32_t again = handle_try_new(H_MISC);
        CHECK(again == all[7]);                                       /* lowest (only) free slot */
        CHECK(handle_try_new(H_MISC) == 0);
        for (int i = 0; i < n; i++) handle_close(all[i]);
        handle_set_round_robin(1);
        CHECK(handle_try_new(H_MISC) != 0);
        for (int i = 0; i < 4096; i++) handle_close(0x1000u + 4u * (uint32_t)i);
        handle_set_round_robin(strict);
    }
    /* round-robin: a closed value is not issued again at once */
    handle_set_round_robin(1);
    uint32_t p = handle_new(H_MISC);
    handle_close(p);
    uint32_t q = handle_new(H_MISC);
    CHECK(q == p + 4u);
    handle_close(q);
    handle_set_round_robin(strict);
    for (int i = 0; i < 4096; i++) handle_close(0x1000u + 4u * (uint32_t)i);   /* clean slate for the next parts */
    puts("A single-thread table semantics: PASS");
}

static void t_single_guest(void) {
    Eng *e = &g_eng[0];
    put("one.txt", "0123456789abcdef");
    uint32_t h = cf(e, "one.txt", GENERIC_READ, FSHARE_R, OPEN_EXISTING);
    CHECK(h != INVALID);
    char b[32];
    CHECK(rd(e, h, b, 16) == 16 && !memcmp(b, "0123456789abcdef", 16));
    CHECK(c1(e, w_GetFileType, h) == 1);
    CHECK(ch(e, h) == 1);
    CHECK(rd(e, h, b, 16) == INVALID && g_err == ERROR_INVALID_HANDLE);  /* use after close */
    CHECK(c1(e, w_GetFileType, h) == 0);
    uint32_t again = ch(e, h);                                             /* double close */
    if (strict) CHECK(again == 0 && g_err == ERROR_INVALID_HANDLE);
    else CHECK(again == 1);                                                /* permissive: always TRUE, as before */
    CHECK(c1(e, w_CloseHandle, INVALID) == 1);                             /* pseudo handle values stay TRUE in strict */
    {   /* events */
        uint32_t a[4] = { 0, 1, 0, 0 };
        uint32_t ev = call(e, w_CreateEventA, 4, a);
        CHECK(ev >= 0x1040u && c1(e, w_SetEvent, ev) == 1 && c1(e, w_ResetEvent, ev) == 1);
        uint32_t w[2] = { ev, 0 };
        CHECK(call(e, w_WaitForSingleObject, 2, w) == 0x102);   /* also warms the one-time getenv in profile_wait (a benign init race otherwise) */
        CHECK(ch(e, ev) == 1);
        CHECK(c1(e, w_SetEvent, ev) == 0 && c1(e, w_ResetEvent, ev) == 0);   /* closed event: FALSE */
    }
    puts("A' guest-level close/use-after-close (kernel32 handlers): PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* B: raw table, N threads                                                                       */
/* ------------------------------------------------------------------------------------------ */
static int g_owner[4096];   /* slot -> (thread id + 1) of the one thread that currently holds the value */
static long g_stat_new, g_stat_close;
typedef struct { uint32_t h; int type; uint64_t tag; int mode; } Live;   /* mode: 0 handle_new, 1 reserve+publish */
typedef struct { int idx; Barrier *bar; int result; } Task;

static void *b_worker(void *p) {
    Task *t = p;
    uint32_t seed = 0x9e3779b9u * (uint32_t)(t->idx + 1);
    enum { K = 6 };
    Live live[K];
    int n = 0;
    uint64_t counter = 0;
    static const int types[] = { H_EVENT, H_MUTEX, H_SEMAPHORE, H_MISC, H_FILE, H_FIND, H_THREAD };
    barrier_wait(t->bar);
    for (long it = 0; it < g_raw_iters; it++) {
        uint32_t r = rnd(&seed);
        if (n < K && ((r & 1) || n == 0)) {
            int type = types[(r >> 4) % (sizeof types / sizeof *types)];
            int mode = (type == H_FILE || (type == H_MISC && (r & 0x100))) ? 1 : 0;
            uint32_t h;
            WinHandle *x;
            if (mode == 0) {
                h = handle_new(type);
                x = handle_get(h, type);
                CHECK(x);
            } else {   /* the strict-share shape: allocate RESERVED, fill in, publish last */
                h = handle_try_new(H_RESERVED);
                CHECK(h);
                CHECK(!handle_get(h, -1));
                x = handle_reserved(h);
                CHECK(x);
            }
            int i = slot_of(h);
            CHECK(i >= 16 && i < 4096);
            int zero = 0;
            CHECK(__atomic_compare_exchange_n(&g_owner[i], &zero, t->idx + 1, 0, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE));   /* never issued twice */
            CHECK(x->fd == -1 && !x->buf && !x->ptr && !x->buf_pos && !x->write_open);                                  /* a fresh slot is clean */
            uint64_t tag = ((uint64_t)(t->idx + 1) << 40) | ++counter;
            x->buf_pos = tag;
            if (type == H_FILE) { x->fd = open_fdsrc(); CHECK(x->fd >= 0); x->buf = malloc(32); x->write_open = 0; snprintf(x->path, sizeof x->path, "/nonexistent/t%d/%d", t->idx, i); }
            if (type == H_FIND) x->ptr = malloc(32);
            if (mode == 1) handle_publish(h, type);
            CHECK(handle_get(h, type) == &g_handles[i]);
            CHECK(!handle_get(h, type == H_MISC ? H_EVENT : H_MISC));
            live[n++] = (Live){ h, type, tag, mode };
            __atomic_fetch_add(&g_stat_new, 1, __ATOMIC_RELAXED);
        } else if (n > 0) {
            int k = (int)((r >> 8) % (uint32_t)n);
            Live l = live[k];
            WinHandle *x = handle_get(l.h, l.type);
            CHECK(x == &g_handles[slot_of(l.h)] && x->buf_pos == l.tag);   /* our slot, our tag */
            __atomic_store_n(&g_owner[slot_of(l.h)], 0, __ATOMIC_RELEASE);
            if (l.mode == 1 && (r & 0x10000)) CHECK(handle_close_checked(l.h) == 1);
            else handle_close(l.h);
            live[k] = live[--n];
            __atomic_fetch_add(&g_stat_close, 1, __ATOMIC_RELAXED);
        }
        if ((it & 63) == 0) for (int k = 0; k < n; k++) {   /* every live handle still ours */
            WinHandle *x = handle_get(live[k].h, live[k].type);
            CHECK(x && x->buf_pos == live[k].tag);
        }
    }
    while (n > 0) {
        Live l = live[--n];
        __atomic_store_n(&g_owner[slot_of(l.h)], 0, __ATOMIC_RELEASE);
        handle_close(l.h);
    }
    return NULL;
}
/* prober: random and stale values; may only look (a returned pointer must be the slot of that value) */
static volatile int g_stop;
static int g_racy;   /* HT_RACY=1: also the checks that are racy by design (ASan only; TSan reports the residual race) */
static void *b_prober(void *p) {
    Task *t = p;
    uint32_t seed = 0x85ebca6bu * (uint32_t)(t->idx + 7);
    barrier_wait(t->bar);
    while (!__atomic_load_n(&g_stop, __ATOMIC_ACQUIRE)) {
        uint32_t v = 0x1000u - 64u + (rnd(&seed) % (4u * 4100u + 128u));
        WinHandle *x = handle_get(v, -1);
        if (x) CHECK(x == &g_handles[slot_of(v)]);
        (void)handle_reserved(v);
        if ((rnd(&seed) & 255) == 0) CHECK(!file_path_write_open("/nonexistent/none"));
    }
    return NULL;
}
/* flips the allocation policy while the others allocate (strict sets it once, lazily, from whichever thread calls
   strict_share() first, while other threads may already be creating handles) */
static void *b_toggler(void *p) {
    Task *t = p;
    barrier_wait(t->bar);
    for (long i = 0; !__atomic_load_n(&g_stop, __ATOMIC_ACQUIRE); i++) { handle_set_round_robin((int)(i & 1)); sched_yield(); }
    return NULL;
}
static void t_raw(void) {
    int nw = g_threads, np = 2;
    int nt = nw + np + 1;
    Barrier bar; barrier_init(&bar, nt);
    pthread_t th[MAXENG];
    Task tk[MAXENG];
    g_stop = 0;
    memset(g_owner, 0, sizeof g_owner);
    for (int i = 0; i < nt; i++) { tk[i] = (Task){ .idx = i, .bar = &bar }; CHECK(!pthread_create(&th[i], NULL, i < nw ? b_worker : i < nw + np ? b_prober : b_toggler, &tk[i])); }
    for (int i = 0; i < nw; i++) CHECK(!pthread_join(th[i], NULL));
    __atomic_store_n(&g_stop, 1, __ATOMIC_RELEASE);
    for (int i = nw; i < nt; i++) CHECK(!pthread_join(th[i], NULL));
    handle_set_round_robin(strict);
    for (int i = 16; i < 4096; i++) CHECK(g_handles[i].type == H_FREE && !g_owner[i]);   /* nothing leaked */
    printf("B raw table, %d threads x %ld ops (+%d probers): %ld new, %ld close: PASS\n", nw, g_raw_iters, np, g_stat_new, g_stat_close);
}

/* B2: several threads close the SAME handle at once: exactly one releases its fd and buffer (a second close of
   the fd could take another thread's fd; a second free of the buffer corrupts the heap) */
typedef struct { Barrier *bar; int idx, rounds, checked; uint32_t *h; int *wins; } CTask;
static void *b2_closer(void *p) {
    CTask *t = p;
    for (int r = 0; r < t->rounds; r++) {
        barrier_wait(t->bar);   /* handle ready */
        uint32_t h = *t->h;
        if (t->checked) { if (handle_close_checked(h)) __atomic_fetch_add(t->wins, 1, __ATOMIC_RELAXED); }
        else handle_close(h);
        barrier_wait(t->bar);   /* all closed */
    }
    return NULL;
}
static void t_double_close(void) {
    enum { N = 4 };
    int rounds = 400;
    for (int checked = 0; checked < 2; checked++) {
        Barrier bar; barrier_init(&bar, N + 1);
        uint32_t h = 0;
        int wins = 0;
        pthread_t th[N];
        CTask tk[N];
        for (int i = 0; i < N; i++) { tk[i] = (CTask){ &bar, i, rounds, checked, &h, &wins }; CHECK(!pthread_create(&th[i], NULL, b2_closer, &tk[i])); }
        for (int r = 0; r < rounds; r++) {
            h = handle_new(r & 1 ? H_FILE : H_FIND);
            WinHandle *x = handle_get(h, -1);
            CHECK(x);
            if (r & 1) { x->fd = open_fdsrc(); x->buf = malloc(64); } else x->ptr = malloc(64);
            wins = 0;
            barrier_wait(&bar);
            barrier_wait(&bar);
            if (checked) CHECK(wins == 1);   /* exactly one close of a live handle succeeded */
            CHECK(!handle_get(h, -1));
        }
        for (int i = 0; i < N; i++) CHECK(!pthread_join(th[i], NULL));
    }
    for (int i = 16; i < 4096; i++) CHECK(g_handles[i].type == H_FREE);
    printf("B2 %d threads close one handle at once (x400, close and close_checked): one release, no double free: PASS\n", 4);
}

/* ------------------------------------------------------------------------------------------ */
/* C: kernel32 handlers, N threads                                                               */
/* ------------------------------------------------------------------------------------------ */
static void *c_worker(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    uint32_t seed = 0x27d4eb2fu * (uint32_t)(t->idx + 3);
    char own[32], buf[64];
    snprintf(own, sizeof own, "own%d.dat", t->idx);
    int mappings = 0;
    barrier_wait(t->bar);
    for (long it = 0; it < g_iters; it++) {
        switch (rnd(&seed) % 7) {
        case 0: {   /* manual-reset event: set, test, close */
            uint32_t a[4] = { 0, 1, 0, 0 };
            uint32_t h = call(e, w_CreateEventA, 4, a);
            CHECK(h >= 0x1040u);
            CHECK(c1(e, w_SetEvent, h) == 1);
            uint32_t w[2] = { h, 0 };
            CHECK(call(e, w_WaitForSingleObject, 2, w) == 0);
            CHECK(ch(e, h) == 1);
            break; }
        case 1: {
            uint32_t a[3] = { 0, 1, 0 };
            uint32_t h = call(e, w_CreateMutexA, 3, a);   /* created owned */
            CHECK(h >= 0x1040u && c1(e, w_ReleaseMutex, h) == 1);
            CHECK(ch(e, h) == 1);
            break; }
        case 2: {
            uint32_t a[4] = { 0, 1, 4, 0 };
            uint32_t h = call(e, w_CreateSemaphoreA, 4, a);
            uint32_t rel[3] = { h, 1, 0 };
            CHECK(h >= 0x1040u && call(e, w_ReleaseSemaphore, 3, rel) == 1);
            uint32_t w[2] = { h, 0 };
            CHECK(call(e, w_WaitForSingleObject, 2, w) == 0);
            CHECK(ch(e, h) == 1);
            break; }
        case 3: {   /* shared read-only file (snapshot path in the default mode) */
            uint32_t h = cf(e, "shared.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
            CHECK(h != INVALID);
            CHECK(rd(e, h, buf, 16) == 16 && !memcmp(buf, "SHARED-0123456789", 16));
            CHECK(c1(e, w_GetFileType, h) == 1);
            uint32_t sf[4] = { h, 4, 0, 0 };
            CHECK(call(e, w_SetFilePointer, 4, sf) == 4);
            CHECK(rd(e, h, buf, 4) == 4 && !memcmp(buf, "ED-0", 4));
            CHECK(c2(e, w_GetFileSize, h, 0) == 64);
            CHECK(ch(e, h) == 1);
            break; }
        case 4: {   /* own file: write handle */
            uint32_t h = cf(e, own, GENERIC_WRITE, 0, CREATE_ALWAYS);
            CHECK(h != INVALID);
            CHECK(wr(e, h, own, (uint32_t)strlen(own)) == strlen(own));
            CHECK(ch(e, h) == 1);
            break; }
        case 5: {   /* directory search */
            uint32_t out = e->base + 0x4000u;
            uint32_t a[2] = { gstr(e, 0, "*.dat"), out };
            uint32_t h = call(e, w_FindFirstFileA, 2, a);
            CHECK(h != INVALID && h >= 0x1040u);
            uint32_t nn[2] = { h, out };
            for (int k = 0; k < 3 && call(e, w_FindNextFileA, 2, nn); k++) {}
            CHECK(c1(e, w_FindClose, h) == 1);
            break; }
        case 6: {
            if (mappings < 2 && !(rnd(&seed) & 127)) {   /* CreateFileMapping dup()s the fd; permissive CloseHandle leaks it: kept tiny */
                uint32_t f = cf(e, "shared.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
                CHECK(f != INVALID);
                uint32_t a[6] = { f, 0, 2, 0, 0, 0 };
                uint32_t m = call(e, w_CreateFileMappingA, 6, a);
                CHECK(m >= 0x1040u);
                CHECK(ch(e, m) == 1);
                CHECK(ch(e, f) == 1);
                mappings++;
            } else {   /* lookup of our own just-closed value: the value may already be reused by another thread, so only the
                          lookup (GetFileType: handle_get and nothing else) is safe here, never a ReadFile that would
                          consume another thread's snapshot */
                uint32_t h = cf(e, "shared.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
                CHECK(h != INVALID && ch(e, h) == 1);
                (void)c1(e, w_GetFileType, h);
            }
            break; }
        }
    }
    return NULL;
}
static void *c_prober(void *p) {
    Task *t = p;
    Eng *e = &g_eng[t->idx];
    uint32_t seed = 0x165667b1u * (uint32_t)(t->idx + 11);
    barrier_wait(t->bar);
    while (!__atomic_load_n(&g_stop, __ATOMIC_ACQUIRE)) {
        uint32_t v = 0x1000u + 4u * (16u + rnd(&seed) % 80u);   /* the low slots, where every thread allocates */
        (void)c1(e, w_GetFileType, v);                           /* looks the value up, never touches the slot's fields */
        if (g_racy) {   /* HT_RACY: SetEvent / DirectSound's kernel_set_event on a random or stale value (a guest bug) */
            kernel_set_event(v);
            (void)c1(e, w_SetEvent, v);
        }
    }
    return NULL;
}
static void t_guest(void) {
    {   /* 64 bytes exactly */
        char big[65]; memset(big, '.', 64); memcpy(big, "SHARED-0123456789", 17); big[64] = 0; put("shared.dat", big);
    }
    int nw = g_threads, np = 2;
    CHECK(nw + np <= MAXENG);
    Barrier bar; barrier_init(&bar, nw + np);
    pthread_t th[MAXENG];
    Task tk[MAXENG];
    g_stop = 0;
    for (int i = 0; i < nw + np; i++) { tk[i] = (Task){ .idx = i, .bar = &bar }; CHECK(!pthread_create(&th[i], NULL, i < nw ? c_worker : c_prober, &tk[i])); }
    for (int i = 0; i < nw; i++) CHECK(!pthread_join(th[i], NULL));
    __atomic_store_n(&g_stop, 1, __ATOMIC_RELEASE);
    for (int i = nw; i < nw + np; i++) CHECK(!pthread_join(th[i], NULL));
    int live = 0;
    for (int i = 16; i < 4096; i++) if (g_handles[i].type != H_FREE) live++;
    CHECK(live == 0);   /* every handle closed: nothing leaked, nothing stuck in H_RESERVED */
    printf("C kernel32 handlers, %d threads x %ld ops (+%d probers): PASS\n", nw, g_iters, np);
}

/* ------------------------------------------------------------------------------------------ */
/* D: handle taken in one thread, closed in another, then used                                   */
/* ------------------------------------------------------------------------------------------ */
typedef struct { Barrier *bar; uint32_t h; Eng *open_e, *close_e; } DTask;
static void *d_opener(void *p) {
    DTask *t = p;
    Eng *e = t->open_e;
    uint32_t h = cf(e, "shared.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
    CHECK(h != INVALID);
    char b[16];
    CHECK(rd(e, h, b, 8) == 8);
    t->h = h;
    barrier_wait(t->bar);   /* 1: opened */
    barrier_wait(t->bar);   /* 2: the other thread has closed it */
    CHECK(rd(e, h, b, 8) == INVALID && g_err == ERROR_INVALID_HANDLE);
    uint32_t sf[4] = { h, 0, 0, 0 };
    CHECK(call(e, w_SetFilePointer, 4, sf) == INVALID && g_err == ERROR_INVALID_HANDLE);
    CHECK(c2(e, w_GetFileSize, h, 0) == INVALID && g_err == ERROR_INVALID_HANDLE);
    uint32_t second = ch(e, h);   /* a late close of the same value: strict reports it, permissive stays TRUE */
    if (strict) CHECK(second == 0 && g_err == ERROR_INVALID_HANDLE); else CHECK(second == 1);
    return NULL;
}
static void *d_closer(void *p) {
    DTask *t = p;
    barrier_wait(t->bar);
    CHECK(ch(t->close_e, t->h) == 1);   /* the handle belongs to the process, any thread may close it */
    barrier_wait(t->bar);
    return NULL;
}
static void t_cross_close(void) {
    Barrier bar; barrier_init(&bar, 2);
    DTask t = { .bar = &bar, .open_e = &g_eng[0], .close_e = &g_eng[1] };
    pthread_t a, b;
    CHECK(!pthread_create(&a, NULL, d_opener, &t));
    CHECK(!pthread_create(&b, NULL, d_closer, &t));
    CHECK(!pthread_join(a, NULL) && !pthread_join(b, NULL));
    for (int i = 16; i < 4096; i++) CHECK(g_handles[i].type == H_FREE);
    puts("D handle opened in one thread, closed in another, used again: ERROR_INVALID_HANDLE: PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* E: use racing with close of the SAME handle (residual risk, ASan only)                        */
/* ------------------------------------------------------------------------------------------ */
typedef struct { uint32_t h; Eng *e; volatile int go, stop; } RTask;
static void *e_reader(void *p) {
    RTask *t = p;
    char b[8];
    while (!__atomic_load_n(&t->go, __ATOMIC_ACQUIRE)) {}
    while (!__atomic_load_n(&t->stop, __ATOMIC_ACQUIRE)) (void)rd(t->e, t->h, b, 4);
    return NULL;
}
static void t_racy_use(void) {
    int rounds = getenv("HT_RACY_ROUNDS") ? atoi(getenv("HT_RACY_ROUNDS")) : 200;
    for (int round = 0; round < rounds; round++) {
        RTask t = { .e = &g_eng[0] };
        t.h = cf(&g_eng[1], "shared.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
        CHECK(t.h != INVALID);
        pthread_t a;
        CHECK(!pthread_create(&a, NULL, e_reader, &t));
        __atomic_store_n(&t.go, 1, __ATOMIC_RELEASE);
        sched_yield();
        (void)ch(&g_eng[1], t.h);
        __atomic_store_n(&t.stop, 1, __ATOMIC_RELEASE);
        pthread_join(a, NULL);
    }
    puts("E racy use-during-close (residual): survived");
}

/* ------------------------------------------------------------------------------------------ */
/* F: waits on a handle that another thread closes                                               */
/* ------------------------------------------------------------------------------------------ */
#define WAIT_FAILED_VAL 0xffffffffu
static double now_s(void) { struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t); return (double)t.tv_sec + (double)t.tv_nsec * 1e-9; }
typedef struct { Eng *e; uint32_t h, ms, r, err; double took; volatile int started; } WTask;
static void *f_waiter(void *p) {
    WTask *t = p;
    uint32_t a[2] = { t->h, t->ms };
    __atomic_store_n(&t->started, 1, __ATOMIC_RELEASE);
    double t0 = now_s();
    t->r = call(t->e, w_WaitForSingleObject, 2, a);
    t->err = g_err;
    t->took = now_s() - t0;
    return NULL;
}
/* blocks until n threads sit in the cond-wait of the sync object behind h (polls under the object's own lock) */
static void wait_blocked(uint32_t h, int n) {
    void *obj = NULL;
    CHECK(handle_snapshot(h, &obj) != H_FREE && obj);
    Sync *s = obj;
    for (int i = 0; i < 20000; i++) {
        pthread_mutex_lock(&s->m);
        int w = s->waiters;
        pthread_mutex_unlock(&s->m);
        if (w >= n) return;
        usleep(250);
    }
    CHECK(!"waiter never blocked");
}
static uint32_t mk_event(Eng *e, int manual, int initial) { uint32_t a[4] = { 0, (uint32_t)manual, (uint32_t)initial, 0 }; uint32_t h = call(e, w_CreateEventA, 4, a); CHECK(h >= 0x1040u); return h; }
static uint32_t mk_sem(Eng *e, int init, int max) { uint32_t a[4] = { 0, (uint32_t)init, (uint32_t)max, 0 }; uint32_t h = call(e, w_CreateSemaphoreA, 4, a); CHECK(h >= 0x1040u); return h; }
static uint32_t mk_mutex(Eng *e, int owned) { uint32_t a[3] = { 0, (uint32_t)owned, 0 }; uint32_t h = call(e, w_CreateMutexA, 3, a); CHECK(h >= 0x1040u); return h; }
static uint32_t wfso(Eng *e, uint32_t h, uint32_t ms) { uint32_t a[2] = { h, ms }; return call(e, w_WaitForSingleObject, 2, a); }
/* a handle to a thread that never starts: the same slot/table shape CreateThread publishes, for platforms without real threads */
static uint32_t mk_fake_thread(ThreadStart **tsout) {
    ThreadStart *ts = calloc(1, sizeof *ts);
    ts->sync = sync_new(); ts->suspended = 1;
    pthread_mutex_init(&ts->go_m, NULL); pthread_cond_init(&ts->go_cv, NULL);
    uint32_t h = handle_reserve_ptr(ts->sync);
    __atomic_store_n(&g_threads_by_handle[slot_of(h)], ts, __ATOMIC_RELEASE);
    handle_publish(h, H_THREAD);
    if (tsout) *tsout = ts;
    return h;
}

static void t_wait_close(void) {
    Eng *e = &g_eng[0], *ec = &g_eng[1];
    handle_set_round_robin(0);   /* the slot-reuse case below needs the same value back; the policy is restored at the end */
    const char *kind[] = { "event", "semaphore", "mutex (owned by another thread)", "thread (not finished)" };
    for (int k = 0; k < 4; k++) {
        uint32_t h = k == 0 ? mk_event(ec, 0, 0) : k == 1 ? mk_sem(ec, 0, 4) : k == 2 ? mk_mutex(ec, 1) : mk_fake_thread(NULL);
        WTask t = { .e = e, .h = h, .ms = 5000 };
        pthread_t th;
        CHECK(!pthread_create(&th, NULL, f_waiter, &t));
        wait_blocked(h, 1);
        double t0 = now_s();
        CHECK(ch(ec, h) == 1);
        CHECK(!pthread_join(th, NULL));
        /* old code: nothing woke the waiter; it hung until the timeout and then read the slot again */
        CHECK(t.r == WAIT_FAILED_VAL && t.err == ERROR_INVALID_HANDLE);
        CHECK(now_s() - t0 < 3.0 && t.took < 4.0);   /* woken by the close, not by the 5 s timeout */
        CHECK(!handle_get(h, -1));
        (void)kind[k];
    }
    puts("F1 close during wait (event, semaphore, mutex, thread): WAIT_FAILED + ERROR_INVALID_HANDLE, no hang: PASS");

    /* the slot is reissued to another event while the first wait is blocked: the wait must neither read nor consume the new object
       (x100: whether a wait that re-reads the slot after waking sees the new event depends on a few microseconds) */
    for (int round = 0; round < 100; round++) {
        uint32_t h1 = mk_event(ec, 0, 0);
        WTask t = { .e = e, .h = h1, .ms = 5000 };
        pthread_t th;
        CHECK(!pthread_create(&th, NULL, f_waiter, &t));
        wait_blocked(h1, 1);
        CHECK(ch(ec, h1) == 1);
        uint32_t h2 = mk_event(ec, 0, 1);   /* auto-reset, signaled; lowest free slot: the same value in this policy */
        CHECK(!pthread_join(th, NULL));
        CHECK(h2 == h1);                    /* the reuse really happened */
        CHECK(t.r == WAIT_FAILED_VAL);
        CHECK(wfso(ec, h2, 0) == 0);        /* the signal of the new object is still there: the old wait did not eat it */
        CHECK(wfso(ec, h2, 0) == 0x102);    /* and it is consumed once, as an auto-reset event */
        CHECK(ch(ec, h2) == 1);
    }
    puts("F2 slot reissued during the wait: the new object is left alone (x100): PASS");

    /* a signal that arrived before the close wins over the close (an auto-reset event is consumed by the waiter) */
    for (int round = 0; round < 50; round++) {
        uint32_t h = mk_event(ec, 0, 0);
        WTask t = { .e = e, .h = h, .ms = 5000 };
        pthread_t th;
        CHECK(!pthread_create(&th, NULL, f_waiter, &t));
        wait_blocked(h, 1);
        CHECK(c1(ec, w_SetEvent, h) == 1);
        CHECK(ch(ec, h) == 1);
        CHECK(!pthread_join(th, NULL));
        CHECK(t.r == 0);
    }
    puts("F3 SetEvent then CloseHandle: the blocked waiter acquires (x50): PASS");

    /* several waiters on one object: all of them fail */
    {
        enum { NW = 4 };
        uint32_t h = mk_event(ec, 1, 0);
        WTask t[NW];
        pthread_t th[NW];
        for (int i = 0; i < NW; i++) { t[i] = (WTask){ .e = &g_eng[2 + i], .h = h, .ms = 5000 }; CHECK(!pthread_create(&th[i], NULL, f_waiter, &t[i])); }
        wait_blocked(h, NW);
        CHECK(ch(ec, h) == 1);
        for (int i = 0; i < NW; i++) { CHECK(!pthread_join(th[i], NULL)); CHECK(t[i].r == WAIT_FAILED_VAL); }
    }
    puts("F4 four waiters on one closed event: all return WAIT_FAILED: PASS");

    /* unchanged behaviour: a wait on a value that is not a live handle, or not a sync object, counts as signaled */
    {
        uint32_t h = mk_event(ec, 1, 0);
        CHECK(ch(ec, h) == 1);
        CHECK(wfso(e, h, 0) == 0 && wfso(e, h, 50) == 0);   /* closed before the wait: as before (the port's historical rule) */
        CHECK(wfso(e, 0, 0) == 0 && wfso(e, 0xffffffffu, 10) == 0 && wfso(e, 0x1004u, 10) == 0);
        /* a find handle's ptr is directory-search state, not a Sync: it used to be locked as one */
        char name[1200];
        snprintf(name, sizeof name, "%s/one.txt", root);
        uint32_t out = e->base + 0x4000u;
        uint32_t a[2] = { gstr(e, 0, "*.txt"), out };
        uint32_t fh = call(e, w_FindFirstFileA, 2, a);
        CHECK(fh != INVALID && fh >= 0x1040u);
        CHECK(wfso(e, fh, 10) == 0);
        CHECK(c1(e, w_FindClose, fh) == 1);
        uint32_t f = cf(e, "one.txt", GENERIC_READ, FSHARE_R, OPEN_EXISTING);
        CHECK(f != INVALID && wfso(e, f, 10) == 0);
        CHECK(ch(e, f) == 1);
        (void)name;
    }
    puts("F5 wait on closed / invalid / find / file handles: WAIT_OBJECT_0 as before: PASS");
    /* the deterministic-scheduler path (wait_one_det / can_acquire) takes the same pair and the same closed flag */
    {
        __atomic_store_n(&g_sched_on, 1, __ATOMIC_RELEASE);
        uint32_t h = mk_event(ec, 0, 0);
        uint32_t parked0 = __atomic_load_n(&g_sched_parked, __ATOMIC_ACQUIRE);
        WTask t = { .e = e, .h = h, .ms = 5000 };
        pthread_t th;
        CHECK(!pthread_create(&th, NULL, f_waiter, &t));
        for (int i = 0; i < 20000 && __atomic_load_n(&g_sched_parked, __ATOMIC_ACQUIRE) == parked0; i++) usleep(250);
        CHECK(__atomic_load_n(&g_sched_parked, __ATOMIC_ACQUIRE) > parked0);
        pthread_mutex_lock(&g_fake_baton);   /* the closer runs only while the parked waiter is not evaluated, as under the real baton */
        CHECK(ch(ec, h) == 1);
        pthread_mutex_unlock(&g_fake_baton);
        CHECK(!pthread_join(th, NULL));
        CHECK(t.r == WAIT_FAILED_VAL && t.err == ERROR_INVALID_HANDLE && t.took < 4.0);
        h = mk_event(ec, 1, 1);
        CHECK(wfso(e, h, 0) == 0 && wfso(e, h, 50) == 0);                     /* signaled: acquired */
        CHECK(c1(ec, w_ResetEvent, h) == 1 && wfso(e, h, 30) == 0x102);        /* not signaled: times out as before */
        CHECK(ch(ec, h) == 1 && wfso(e, h, 30) == 0);                          /* closed before the wait: signaled, as before */
        __atomic_store_n(&g_sched_on, 0, __ATOMIC_RELEASE);
    }
    puts("F7 deterministic-scheduler path: close during wait -> WAIT_FAILED, timeout and signal as before: PASS");
    handle_set_round_robin(strict);
}

/* stress: waiters with short timeouts on the current event while others set, close and reissue it; every wait must end with
   0, WAIT_TIMEOUT or WAIT_FAILED, and TSan must see no access to a slot that is being reissued */
static volatile uint32_t g_cur_h;
typedef struct { Eng *e; Barrier *bar; long iters; uint32_t seed; long ok, to, failed; } SWork;
static void *f_stress_waiter(void *p) {
    SWork *w = p;
    barrier_wait(w->bar);
    for (long i = 0; i < w->iters; i++) {
        uint32_t h = __atomic_load_n(&g_cur_h, __ATOMIC_ACQUIRE);
        uint32_t r = wfso(w->e, h, rnd(&w->seed) % 3);
        if (r == 0) w->ok++; else if (r == 0x102) w->to++; else { CHECK(r == WAIT_FAILED_VAL && g_err == ERROR_INVALID_HANDLE); w->failed++; }
    }
    return NULL;
}
static void *f_stress_churn(void *p) {
    SWork *w = p;
    barrier_wait(w->bar);
    while (!__atomic_load_n(&g_stop, __ATOMIC_ACQUIRE)) {
        uint32_t r = rnd(&w->seed);
        uint32_t h = (r & 3) == 0 ? mk_sem(w->e, 0, 2) : mk_event(w->e, (int)((r >> 4) & 1), 0);
        __atomic_store_n(&g_cur_h, h, __ATOMIC_RELEASE);
        if (r & 0x100) usleep(r % 200);
        if (r & 0x200) { if ((r & 3) == 0) { uint32_t a[3] = { h, 1, 0 }; (void)call(w->e, w_ReleaseSemaphore, 3, a); } else (void)c1(w->e, w_SetEvent, h); }
        if (r & 0x400) sched_yield();
        CHECK(ch(w->e, h) == 1);
    }
    return NULL;
}
static void t_wait_stress(void) {
    enum { NWAIT = 4, NCH = 2 };
    long iters = g_iters * 2;
    Barrier bar; barrier_init(&bar, NWAIT + NCH);
    pthread_t th[NWAIT + NCH];
    SWork w[NWAIT + NCH];
    g_stop = 0;
    __atomic_store_n(&g_cur_h, mk_event(&g_eng[NWAIT + NCH], 1, 1), __ATOMIC_RELEASE);
    uint32_t first = g_cur_h;
    for (int i = 0; i < NWAIT + NCH; i++) {
        w[i] = (SWork){ .e = &g_eng[i], .bar = &bar, .iters = iters, .seed = 0x2545f491u * (uint32_t)(i + 1) };
        CHECK(!pthread_create(&th[i], NULL, i < NWAIT ? f_stress_waiter : f_stress_churn, &w[i]));
    }
    long ok = 0, to = 0, failed = 0;
    for (int i = 0; i < NWAIT; i++) { CHECK(!pthread_join(th[i], NULL)); ok += w[i].ok; to += w[i].to; failed += w[i].failed; }
    __atomic_store_n(&g_stop, 1, __ATOMIC_RELEASE);
    for (int i = NWAIT; i < NWAIT + NCH; i++) CHECK(!pthread_join(th[i], NULL));
    CHECK(ch(&g_eng[NWAIT + NCH], first) == 1);
    int live = 0;
    for (int i = 16; i < 4096; i++) if (g_handles[i].type != H_FREE) live++;
    CHECK(live == 0);
    printf("F6 %d waiters x %ld waits against %d churners (set / close / reissue): %ld signaled, %ld timeouts, %ld WAIT_FAILED: PASS\n", NWAIT, iters, NCH, ok, to, failed);
}

/* ------------------------------------------------------------------------------------------ */
/* G: thread handles                                                                             */
/* ------------------------------------------------------------------------------------------ */
static uint32_t mk_thread(Eng *e, uint32_t start, uint32_t param, int suspended) {
    uint32_t tid = e->base + 0x300u;
    uint32_t a[6] = { 0, 0, start, param, suspended ? 4u : 0u, tid };
    uint32_t h = call(e, w_CreateThread, 6, a);
    CHECK(h >= 0x1040u);
    return h;
}
static void t_threads_fake(void) {
    Eng *e = &g_eng[0];
    ThreadStart *ts;
    handle_set_round_robin(0);   /* the lowest free slot, so the reissue below returns the same value in both modes; restored at the end */
    uint32_t h = mk_fake_thread(&ts);
    CHECK(__atomic_load_n(&g_threads_by_handle[slot_of(h)], __ATOMIC_ACQUIRE) == ts);
    CHECK(c1(e, w_ResumeThread, h) == 1 && !ts->suspended);          /* a live handle: ResumeThread reaches its thread (returns the previous state) */
    uint32_t x = e->base + 0x200u;
    uint32_t a[2] = { h, x };
    CHECK(call(e, w_GetExitCodeThread, 2, a) == 1 && R32(x) == 259u);   /* STILL_ACTIVE */
    pthread_mutex_lock(&ts->sync->m); ts->sync->finished = 1; ts->sync->exit_code = 42; pthread_cond_broadcast(&ts->sync->cv); pthread_mutex_unlock(&ts->sync->m);
    CHECK(wfso(e, h, 100) == 0);                                      /* WaitForSingleObject(thread) and GetExitCodeThread through the handle's Sync */
    CHECK(call(e, w_GetExitCodeThread, 2, a) == 1 && R32(x) == 42u);
    ts->suspended = 1;
    CHECK(ch(e, h) == 1);
    CHECK(__atomic_load_n(&g_threads_by_handle[slot_of(h)], __ATOMIC_ACQUIRE) == NULL);   /* the entry is gone with the handle (it used to stay) */
    CHECK(c1(e, w_ResumeThread, h) == 0 && ts->suspended == 1);       /* the closed value resumes nothing */
    W32(x, 1);
    CHECK(call(e, w_GetExitCodeThread, 2, a) == 1 && R32(x) == 259u); /* closed: as before */
    /* strict: the value is not reissued at once; permissive: the next thread on the reissued slot starts clean */
    ThreadStart *ts2;
    uint32_t h2 = mk_fake_thread(&ts2);
    CHECK(h2 == h && __atomic_load_n(&g_threads_by_handle[slot_of(h2)], __ATOMIC_ACQUIRE) == ts2);
    CHECK(ch(e, h2) == 1 && g_threads_by_handle[slot_of(h2)] == NULL);
    handle_set_round_robin(strict);
    pthread_mutex_destroy(&ts->go_m); pthread_cond_destroy(&ts->go_cv); free(ts);   /* the fakes have no thread: free them */
    pthread_mutex_destroy(&ts2->go_m); pthread_cond_destroy(&ts2->go_cv); free(ts2);
    for (int i = 0; i < 4096; i++) CHECK(!g_threads_by_handle[i]);
    puts("G1 thread handle close clears its table entry; ResumeThread / GetExitCodeThread / wait on it behave: PASS");
}
#ifndef __EMSCRIPTEN__
static void wait_finished(ThreadStart *ts) {
    for (int i = 0; i < 20000; i++) {
        pthread_mutex_lock(&ts->sync->m);
        int f = ts->sync->finished;
        pthread_mutex_unlock(&ts->sync->m);
        if (f) return;
        usleep(250);
    }
    CHECK(!"thread never finished");
}
static void t_threads_real(void) {
    Eng *e = &g_eng[0], *e2 = &g_eng[1];
    uint32_t x = e->base + 0x200u;
    handle_set_round_robin(0);
    {   /* a running thread: wait, exit code, close, table entry */
        uint32_t h = mk_thread(e, 0x401000, 5, 0);
        CHECK(wfso(e, h, 8000) == 0);
        uint32_t a[2] = { h, x };
        CHECK(call(e, w_GetExitCodeThread, 2, a) == 1 && R32(x) == 12u);
        ThreadStart *ts = g_threads_by_handle[slot_of(h)];
        CHECK(ts && ts->sync == handle_get(h, H_THREAD)->ptr);
        CHECK(ch(e, h) == 1);
        CHECK(g_threads_by_handle[slot_of(h)] == NULL && c1(e, w_ResumeThread, h) == 0);
    }
    {   /* CREATE_SUSPENDED: the thread waits for ResumeThread */
        uint32_t before = __atomic_load_n(&g_thr_runs, __ATOMIC_RELAXED);
        uint32_t h = mk_thread(e, 0x401000, 100, 1);
        usleep(20000);
        CHECK(__atomic_load_n(&g_thr_runs, __ATOMIC_RELAXED) == before);   /* not started */
        CHECK(c1(e, w_ResumeThread, h) == 1);
        CHECK(wfso(e, h, 8000) == 0);
        uint32_t a[2] = { h, x };
        CHECK(call(e, w_GetExitCodeThread, 2, a) == 1 && R32(x) == 107u);
        CHECK(ch(e, h) == 1 && g_threads_by_handle[slot_of(h)] == NULL);
    }
    {   /* suspended thread whose handle is closed before the resume: ResumeThread by that value must not start it */
        uint32_t before = __atomic_load_n(&g_thr_runs, __ATOMIC_RELAXED);
        uint32_t h = mk_thread(e, 0x401000, 1, 1);
        ThreadStart *ts = g_threads_by_handle[slot_of(h)];
        CHECK(ts && ts->suspended);
        CHECK(ch(e, h) == 1);
        CHECK(g_threads_by_handle[slot_of(h)] == NULL);
        CHECK(c1(e, w_ResumeThread, h) == 0);
        usleep(20000);
        CHECK(ts->suspended == 1 && __atomic_load_n(&g_thr_runs, __ATOMIC_RELAXED) == before);   /* still parked: the stale entry used to resume it */
        pthread_mutex_lock(&ts->go_m); ts->suspended = 0; pthread_cond_broadcast(&ts->go_cv); pthread_mutex_unlock(&ts->go_m);   /* release it for cleanup */
        wait_finished(ts);
    }
    {   /* the thread handle is closed while another thread waits for the (still running) thread */
        __atomic_store_n(&g_thr_release, 0, __ATOMIC_RELEASE);
        uint32_t h = mk_thread(e, 0x777, 3, 0);
        ThreadStart *ts = g_threads_by_handle[slot_of(h)];
        WTask t = { .e = e2, .h = h, .ms = 5000 };
        pthread_t th;
        CHECK(!pthread_create(&th, NULL, f_waiter, &t));
        wait_blocked(h, 1);
        CHECK(ch(e, h) == 1);
        CHECK(!pthread_join(th, NULL));
        CHECK(t.r == WAIT_FAILED_VAL && t.err == ERROR_INVALID_HANDLE && t.took < 4.0);
        __atomic_store_n(&g_thr_release, 1, __ATOMIC_RELEASE);
        wait_finished(ts);
        CHECK(ts->sync->exit_code == 10u);
    }
    handle_set_round_robin(strict);
    for (int i = 16; i < 4096; i++) CHECK(g_handles[i].type == H_FREE && !g_threads_by_handle[i]);
    puts("G2 real threads (CreateThread, suspended, resume, close before resume, close during wait on a running thread): PASS");
}
#endif

/* ------------------------------------------------------------------------------------------ */
/* H: CreateFileMappingA keeps a dup()ed fd of its file; CloseHandle(mapping) must close it     */
/* ------------------------------------------------------------------------------------------ */
static void t_mapping_fd(void) {
    Eng *e = &g_eng[0];
    put("map.dat", "0123456789abcdef");
    uint32_t f = cf(e, "map.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
    CHECK(f != INVALID);
    uint32_t a[6] = { f, 0, 2, 0, 0, 0 };
    uint32_t m = call(e, w_CreateFileMappingA, 6, a);
    WinHandle *mx = handle_get(m, H_MAPPING);
    CHECK(mx && mx->fd >= 0);
    int mfd = mx->fd;
    CHECK(fcntl(mfd, F_GETFD) != -1);            /* open while the mapping handle lives */
    CHECK(ch(e, m) == 1);
    CHECK(fcntl(mfd, F_GETFD) == -1 && errno == EBADF);   /* closed with it (permissive used to leak it) */
    CHECK(c1(e, w_MapViewOfFile, m) == 0);       /* a closed mapping maps nothing */
    CHECK(ch(e, f) == 1);
    /* no growth of the fd table: the next open() gets the same number before and after many mappings */
    int probe = open(root, O_RDONLY); CHECK(probe >= 0); close(probe);
    for (int i = 0; i < 300; i++) {
        uint32_t ff = cf(e, "map.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
        CHECK(ff != INVALID);
        uint32_t b[6] = { ff, 0, 2, 0, 0, 0 };
        uint32_t mm = call(e, w_CreateFileMappingA, 6, b);
        CHECK(ch(e, mm) == 1 && ch(e, ff) == 1);
    }
    int probe2 = open(root, O_RDONLY); CHECK(probe2 >= 0); close(probe2);
    CHECK(probe2 == probe);
    /* a mapping that outlives its file handle keeps working until it is closed itself */
    f = cf(e, "map.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
    uint32_t c[6] = { f, 0, 2, 0, 0, 0 };
    m = call(e, w_CreateFileMappingA, 6, c);
    mx = handle_get(m, H_MAPPING);
    mfd = mx->fd;
    CHECK(ch(e, f) == 1 && fcntl(mfd, F_GETFD) != -1);
    CHECK(ch(e, m) == 1 && fcntl(mfd, F_GETFD) == -1);
    puts("H CloseHandle(mapping) closes its dup()ed fd; 300 map/close cycles leak none: PASS");
}

/* ------------------------------------------------------------------------------------------ */
/* I: read snapshot against a writer on the same path (the contract the snapshot has today)      */
/* ------------------------------------------------------------------------------------------ */
static void t_snapshot_writer(void) {
    Eng *e = &g_eng[0];
    if (strict) { puts("I snapshot against a writer: permissive-mode contract, skipped in strict"); return; }
    put("snap.dat", "AAAAAAAAAAAAAAAA");
    char b[32];
    /* a reader that opened first holds a point-in-time copy: it does not see a writer that opens later (inherent to the
       one-shot snapshot, documented in kernel32.c; the same is true for a writer that opens one microsecond after the reader's
       scan, which is why the scan/snapshot pair does not need to be atomic with a writer's open) */
    uint32_t r = cf(e, "snap.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
    CHECK(r != INVALID && handle_get(r, H_FILE)->buf);
    uint32_t w = cf(e, "snap.dat", GENERIC_WRITE, FSHARE_RW, OPEN_EXISTING);
    CHECK(w != INVALID && handle_get(w, H_FILE)->write_open);
    CHECK(wr(e, w, "BBBB", 4) == 4);
    CHECK(rd(e, r, b, 8) == 8 && !memcmp(b, "AAAAAAAA", 8));   /* KNOWN-LIMIT: stale for a reader that opened before the writer */
    CHECK(ch(e, w) == 1 && ch(e, r) == 1);
    /* a writer that is open (published) when the reader opens: no snapshot, the reader reads the live file */
    w = cf(e, "snap.dat", GENERIC_WRITE, FSHARE_RW, OPEN_EXISTING);
    CHECK(w != INVALID);
    r = cf(e, "snap.dat", GENERIC_READ, FSHARE_RW, OPEN_EXISTING);
    CHECK(r != INVALID && !handle_get(r, H_FILE)->buf);
    CHECK(wr(e, w, "CCCC", 4) == 4);
    CHECK(rd(e, r, b, 8) == 8 && !memcmp(b, "CCCCAAAA", 8));   /* sees the writer's data */
    CHECK(ch(e, w) == 1 && ch(e, r) == 1);
    puts("I snapshot vs writer: reader-first is a point-in-time copy (KNOWN-LIMIT), writer-first reads live data: PASS");
}

static int want_part(char c) { const char *o = getenv("HT_ONLY"); return !o || strchr(o, c); }
int main(int argc, char **argv) {
    if (argc > 2) {
        if (!strcmp(argv[2], "unset")) unsetenv("PORT_STRICT_FILE_SHARE");
        else CHECK(!setenv("PORT_STRICT_FILE_SHARE", !strcmp(argv[2], "empty") ? "" : argv[2], 1));
    }
    if (argc > 3) g_threads = atoi(argv[3]);
    if (argc > 4) { g_iters = atol(argv[4]); g_raw_iters = g_iters * 5; }
    if (getenv("HT_THREADS")) g_threads = atoi(getenv("HT_THREADS"));
    if (getenv("HT_ITERS")) g_iters = atol(getenv("HT_ITERS"));
    if (getenv("HT_RAW_ITERS")) g_raw_iters = atol(getenv("HT_RAW_ITERS"));
    CHECK(g_threads >= 1 && g_threads + 3 <= MAXENG);
    g_racy = getenv("HT_RACY") != NULL;
    const char *v = getenv("PORT_STRICT_FILE_SHARE");
    strict = v && *v && strcmp(v, "0") != 0;
    CHECK(strict_share() == strict);
    if (!getenv("PORT_FILE_SNAPSHOT")) CHECK(!setenv("PORT_FILE_SNAPSHOT", "1", 1));   /* the default: read-only opens take a snapshot */
    printf("-- PORT_STRICT_FILE_SHARE=%s, %d threads, %ld guest ops, %ld raw ops\n", v ? (*v ? v : "(empty)") : "(unset)", g_threads, g_iters, g_raw_iters);
#ifndef __EMSCRIPTEN__
    /* CreateThread allocates the thread's stack and TIB with guest_valloc (a high guest address): reserve the whole guest space
       (sparse, untouched pages cost nothing), as the real runtime does */
    g_mem = mmap(NULL, (size_t)GUEST_SPACE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON | MAP_NORESERVE, -1, 0);
    CHECK(g_mem != MAP_FAILED);
#else
    g_mem = calloc(1, 0x200000);
    CHECK(g_mem);
#endif
    for (int i = 0; i < MAXENG; i++) eng_init(&g_eng[i], i);
    /* first-use initializers that are not thread-safe by themselves in kernel32.c/core.c */
    (void)snapshot_enabled(); (void)snapshot_max(); (void)host_seconds();
    snprintf(root, sizeof root, "%s/korsary-ht-XXXXXX", argc > 1 ? argv[1] : "/tmp");
    CHECK(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);

    put("fdsrc.bin", "x");
    t_single();
    t_single_guest();
    t_raw();
    t_double_close();
    t_guest();
    t_cross_close();
    /* HT_ONLY=FSGHI restricts the new parts (F waits, S wait stress, G threads, H mapping fd, I snapshot): run against the old tree */
    if (want_part('F')) t_wait_close();
    if (want_part('S')) t_wait_stress();
    if (want_part('G')) t_threads_fake();
#ifndef __EMSCRIPTEN__
    if (want_part('G')) t_threads_real();
#endif
    if (want_part('H')) t_mapping_fd();
    if (want_part('I')) t_snapshot_writer();
    if (g_racy) t_racy_use();

    DIR *d = opendir(root);
    struct dirent *de;
    while (d && (de = readdir(d))) {
        if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, "..")) continue;
        char p[1200];
        snprintf(p, sizeof p, "%s/%s", root, de->d_name);
        unlink(p);
    }
    if (d) closedir(d);
    rmdir(root);
#ifndef __EMSCRIPTEN__
    munmap(g_mem, (size_t)GUEST_SPACE);
#else
    free(g_mem);
#endif
    return 0;
}
