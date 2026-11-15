/* Production-mode fatal heap diagnostics: no PORT_HEAP_STATS. */
#define HEAP_FATAL_SCAN_LIMIT 8u
#include "../host/core.c"
#include <assert.h>
#include <signal.h>
#include <stdatomic.h>
#include <sys/resource.h>
#include <sys/wait.h>

uint8_t *g_mem;

static void reset_heap(void) {
    g_heap_top = HEAP_LO; g_heap_last = 0;
    memset(g_free, 0, sizeof g_free);
}

static void test_layout_and_corruption(void) {
    reset_heap();
    uint32_t a = heap_alloc(100, 0), b = heap_alloc(1000, 0);
    uint32_t c = heap_alloc(32, 0);
    heap_free(b);
    uint32_t before = g_heap_top;
    HeapFatalSnapshot s;
    heap_fatal_snapshot(&s);
    assert(!s.bad && !s.truncated && !s.busy && s.extent == 112 + 1008 + 32 + 48);
    assert(s.live_blocks == 2 && s.live_bytes == 144);
    assert(s.free_blocks == 1 && s.free_bytes == 1008 && s.largest_free == 1008);
    assert(g_heap_top == before && heap_size(a) == 100 && heap_size(c) == 32);
    /* The snapshot releases the allocator mutex and is strictly read-only. */
    uint32_t d = heap_try_alloc(16, 0); assert(d);
    heap_free(d);
    W32(b - 12, 0x12345678u);
    heap_fatal_snapshot(&s);
    assert(s.bad == 1 && s.live_blocks == 1 && s.free_blocks == 0);
    W32(b - 12, 0);
    uint32_t cap = R32(b - 16);
    W32(b - 16, UINT32_MAX - 15u);
    heap_fatal_snapshot(&s); assert(s.bad == 1);
    W32(b - 16, cap);
    W32(a - 4, R32(a - 16) + 1);
    heap_fatal_snapshot(&s); assert(s.bad == 1 && s.live_blocks == 0);
    W32(a - 4, 100);
    W32(c - 16, 16); W32(c - 4, 16); /* valid-looking block, followed by a dangling header */
    heap_fatal_snapshot(&s); assert(s.bad == 1 && s.live_blocks == 2);
    W32(c - 16, 32); W32(c - 4, 32);
    g_heap_top = HEAP_HI + 16u;
    heap_fatal_snapshot(&s); assert(s.bad == 1 && s.extent == 0);
    g_heap_top = HEAP_LO + 16u;
    heap_fatal_snapshot(&s); assert(s.bad == 1 && s.extent == 0);
    g_heap_top = before;
    assert(!pthread_mutex_lock(&g_heap_lock));
    heap_fatal_snapshot(&s);
    assert(s.busy == 1 && s.extent == 0 && s.live_blocks == 0);
    assert(!pthread_mutex_unlock(&g_heap_lock));
    heap_free(a); heap_free(c);
    assert(g_heap_top == HEAP_LO);
}

static void test_scan_limit(void) {
    reset_heap();
    uint32_t blocks[9];
    for (unsigned i = 0; i < 9; i++) blocks[i] = heap_alloc(16, 0);
    HeapFatalSnapshot s; heap_fatal_snapshot(&s);
    assert(!s.bad && s.truncated == 1 && s.live_blocks == 8);
    assert(s.live_bytes == 128 && s.extent == 288);
    for (unsigned i = 0; i < 9; i++) heap_free(blocks[i]);
    assert(g_heap_top == HEAP_LO);
}

static atomic_int stop_churn;
static void *churn(void *unused) {
    (void)unused;
    while (!atomic_load(&stop_churn)) {
        uint32_t a = heap_try_alloc(64, 0);
        if (a) heap_free(a);
    }
    return NULL;
}

static void test_concurrent_scan(void) {
    reset_heap(); atomic_store(&stop_churn, 0);
    pthread_t t; assert(!pthread_create(&t, NULL, churn, NULL));
    for (int i = 0; i < 200; i++) {
        HeapFatalSnapshot s; heap_fatal_snapshot(&s);
        assert(!s.bad && !s.truncated);
        if (s.busy) assert(s.extent == 0 && s.live_blocks == 0);
    }
    atomic_store(&stop_churn, 1); assert(!pthread_join(t, NULL));
    assert(g_heap_top == HEAP_LO);
}

static void test_real_fatal_path(void) {
    reset_heap();
    uint32_t a = heap_alloc(64, 0), b = heap_alloc(128, 0), guard = heap_alloc(16, 0);
    heap_free(b);
    int pipefd[2]; assert(!pipe(pipefd));
    pid_t pid = fork(); assert(pid >= 0);
    if (!pid) {
        struct rlimit r = {0, 0}; setrlimit(RLIMIT_CORE, &r);
        close(pipefd[0]); assert(dup2(pipefd[1], STDERR_FILENO) >= 0); close(pipefd[1]);
        heap_alloc(UINT32_MAX, 0); _exit(99);
    }
    close(pipefd[1]);
    char output[1024]; size_t used = 0; ssize_t got;
    while (used < sizeof output - 1 && (got = read(pipefd[0], output + used, sizeof output - 1 - used)) > 0)
        used += (size_t)got;
    close(pipefd[0]); output[used] = '\0';
    int status = 0; assert(waitpid(pid, &status, 0) == pid);
    assert(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT);
    assert(strstr(output, "guest heap exhausted (4294967295 bytes requested by host)"));
    assert(strstr(output, "[heapfail] host allocation: extent_bytes=256 live_blocks=2 live_bytes=80 free_blocks=1 free_bytes=128 largest_free_bytes=128 bad=0 truncated=0 busy=0"));
    heap_free(a); heap_free(guard);
}

int main(void) {
    g_mem = calloc(1, (size_t)HEAP_LO + (1u << 20)); assert(g_mem);
    test_layout_and_corruption(); test_scan_limit(); test_concurrent_scan(); test_real_fatal_path();
    free(g_mem); puts("production fatal heap snapshot: PASS");
}
