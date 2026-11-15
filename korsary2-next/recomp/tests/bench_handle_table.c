/* Накладные расходы защиты таблицы дескрипторов (PORT_SPECIFICATION.md): наносекунды на операцию, native -O2.
   Собирается и против старого, и против нового recomp/host (только публичный API), поэтому run_handle_table.sh bench
   BASE_DIR печатает обе колонки. Синтетические файлы во временной папке.
   Usage: bench scratch-dir */
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) { (void)pred; (void)arg; (void)deadline_us; (void)deadline_fn; return 0; }

static char root[1024];
typedef struct { CPU c; GuestThread th; uint32_t base; } Eng;
static Eng g_eng[8];
static uint32_t call(Eng *e, void (*fn)(CPU *), int n, const uint32_t *a) {
    t_self = &e->th;
    e->c.esp = e->base + 0x100;
    W32(e->c.esp, 0);
    for (int i = 0; i < n; i++) W32(e->c.esp + 4 + 4u * (uint32_t)i, a[i]);
    fn(&e->c);
    return e->c.eax;
}
static double now(void) { struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t); return (double)t.tv_sec * 1e9 + (double)t.tv_nsec; }
static int cmpd(const void *a, const void *b) { double x = *(const double *)a, y = *(const double *)b; return x < y ? -1 : x > y; }
#define REPS 7
/* runs body REPS times, reports the median ns per iteration */
#define BENCH(name, iters, body) do { \
    double r[REPS]; \
    for (int rep = 0; rep < REPS; rep++) { double t0 = now(); for (long it = 0; it < (iters); it++) { body; BARRIER(); } r[rep] = (now() - t0) / (double)(iters); } \
    qsort(r, REPS, sizeof *r, cmpd); \
    printf("%-46s %9.1f ns/op  (min %.1f)\n", name, r[REPS / 2], r[0]); fflush(stdout); } while (0)

static volatile uintptr_t sink;
typedef struct { Eng *e; uint32_t h, ev; long n; } TArg;
#define BARRIER() __asm__ volatile("" ::: "memory")
static void *thr_get(void *p) {
    TArg *t = p;
    uintptr_t acc = 0;
    for (long i = 0; i < t->n; i++) { acc += (uintptr_t)handle_get(t->h, H_FILE); BARRIER(); }
    sink = acc;
    return NULL;
}
static void *thr_ev(void *p) {
    TArg *t = p;
    uint32_t a[1] = { t->ev };
    for (long i = 0; i < t->n; i++) call(t->e, w_SetEvent, 1, a);
    return NULL;
}
static void *thr_churn(void *p) {   /* new + close of a handle of its own */
    TArg *t = p;
    for (long i = 0; i < t->n; i++) { uint32_t h = handle_new(H_MISC); handle_close(h); }
    return NULL;
}
static double run_threads(void *(*fn)(void *), int nt, long n) {
    pthread_t th[8];
    TArg a[8];
    uint32_t h = handle_new(H_FILE);
    uint32_t ea[4] = { 0, 1, 0, 0 };
    double t0;
    for (int i = 0; i < nt; i++) { a[i] = (TArg){ &g_eng[i], h, call(&g_eng[i], w_CreateEventA, 4, ea), n }; }
    t0 = now();
    for (int i = 0; i < nt; i++) pthread_create(&th[i], NULL, fn, &a[i]);
    for (int i = 0; i < nt; i++) pthread_join(th[i], NULL);
    double dt = now() - t0;
    handle_close(h);
    for (int i = 0; i < nt; i++) handle_close(a[i].ev);
    return dt / (double)n;   /* wall ns per operation of one thread (all threads run concurrently) */
}

int main(int argc, char **argv) {
    g_mem = calloc(1, 0x100000);
    for (int i = 0; i < 8; i++) { memset(&g_eng[i], 0, sizeof g_eng[i]); g_eng[i].base = 0x1000u + (uint32_t)i * 0x8000u; }
    snprintf(root, sizeof root, "%s/korsary-htb-XXXXXX", argc > 1 ? argv[1] : "/tmp");
    if (!mkdtemp(root)) return 1;
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char p[1200];
    snprintf(p, sizeof p, "%s/data.bin", root);
    { FILE *f = fopen(p, "wb"); char z[4096]; memset(z, 'x', sizeof z); fwrite(z, 1, sizeof z, f); fclose(f); }
    Eng *e = &g_eng[0];
    uint32_t nm = e->base + 0x400;
    strcpy((char *)HP(nm), "data.bin");
    uint32_t ca[7] = { nm, 0x80000000u, 1, 0, 3, 0, 0 };
    uint32_t fh = call(e, w_CreateFileA, 7, ca);          /* snapshot handle (the browser default) */
    uint32_t out = e->base + 0x200, data = e->base + 0x3000;
    uint32_t ea[4] = { 0, 1, 0, 0 };
    uint32_t ev = call(e, w_CreateEventA, 4, ea);

    printf("-- single thread\n");
    BENCH("handle_get (live file handle)", 20000000L, sink += (uintptr_t)handle_get(fh, H_FILE));
    BENCH("handle_get (miss: closed value)", 20000000L, sink += (uintptr_t)handle_get(0x1000u + 4u * 3000u, -1));
    BENCH("handle_new + handle_close (H_MISC)", 3000000L, { uint32_t h = handle_new(H_MISC); handle_close(h); });
    { uint32_t a[1] = { ev }; BENCH("w_SetEvent (handle_get + Sync lock)", 3000000L, call(e, w_SetEvent, 1, a)); }
    { uint32_t a[5] = { fh, data, 16, out, 0 }; BENCH("w_ReadFile 16 B (snapshot, handle_get + memcpy)", 3000000L, call(e, w_ReadFile, 5, a)); }
    { uint32_t sf[4] = { fh, 0, 0, 0 }; BENCH("w_SetFilePointer (snapshot)", 3000000L, call(e, w_SetFilePointer, 4, sf)); }
    { uint32_t a[7] = { nm, 0x80000000u, 1, 0, 3, 0, 0 }, c[1];
      BENCH("w_CreateFileA + w_CloseHandle (snapshot 4 KB)", 40000L, { c[0] = call(e, w_CreateFileA, 7, a); call(e, w_CloseHandle, 1, c); }); }
    { uint32_t a[4] = { 0, 1, 0, 0 }, c[1];
      BENCH("w_CreateEventA + w_CloseHandle", 1000000L, { c[0] = call(e, w_CreateEventA, 4, a); call(e, w_CloseHandle, 1, c); }); }
    printf("-- 4 threads on one handle table (wall ns per op of one thread)\n");
    for (int rep = 0; rep < 3; rep++) printf("%-46s %9.1f ns/op\n", "handle_get x4", run_threads(thr_get, 4, 5000000L));
    for (int rep = 0; rep < 3; rep++) printf("%-46s %9.1f ns/op\n", "w_SetEvent x4 (own events)", run_threads(thr_ev, 4, 1000000L));
    for (int rep = 0; rep < 3; rep++) printf("%-46s %9.1f ns/op\n", "handle_new + handle_close x4", run_threads(thr_churn, 4, 500000L));
    uint32_t cl[1] = { fh };
    call(e, w_CloseHandle, 1, cl);
    unlink(p);
    rmdir(root);
    return 0;
}
