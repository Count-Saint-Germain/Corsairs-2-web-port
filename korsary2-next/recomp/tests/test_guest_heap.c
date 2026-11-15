/* Standalone allocator regression: compile with function sections/dead strip. */
#include "../host/core.c"

#include <assert.h>

uint8_t *g_mem;

static void reset_heap(void) {
    g_heap_top = HEAP_LO;
    g_heap_last = 0;
    memset(g_free, 0, sizeof g_free);
}

static void test_coalesce_and_split(void) {
    reset_heap();
    uint32_t left = heap_alloc(65536, 0), middle = heap_alloc(65536, 0);
    uint32_t right = heap_alloc(65536, 0), guard = heap_alloc(32, 0);
    uint32_t top = g_heap_top;
    heap_free(middle);
    heap_free(left);
    heap_free(right);
    uint32_t merged = heap_alloc(120000, 0);
    assert(merged == left && g_heap_top == top);
    uint32_t rest = heap_alloc(32000, 0);
    assert(rest > merged && rest < guard && g_heap_top == top);
    heap_free(merged);
    heap_free(rest);
    heap_free(guard);
    assert(g_heap_top == HEAP_LO && !g_heap_last);
}

static void test_realloc(void) {
    reset_heap();
    uint32_t a = heap_alloc(256, 0), neighbour = heap_alloc(256, 0);
    uint32_t guard = heap_alloc(32, 0);
    memset(HP(a), 0xa5, 256);
    heap_free(neighbour);
    assert(heap_realloc(a, 384, 1) == a);
    for (int i = 0; i < 256; i++) assert(R8(a + i) == 0xa5);
    for (int i = 256; i < 384; i++) assert(R8(a + i) == 0);
    uint32_t moved = heap_realloc(a, 4096, 0);
    assert(moved && moved != a && heap_size(moved) >= 4096);
    for (int i = 0; i < 256; i++) assert(R8(moved + i) == 0xa5);
    heap_free(guard);
    assert(heap_realloc(moved, 8192, 1) == moved); /* last block grows in place */
    for (int i = 4096; i < 8192; i++) assert(R8(moved + i) == 0);
    heap_free(moved);
    assert(g_heap_top == HEAP_LO && !g_heap_last);
}

static void test_small_reuse_and_requested_size(void) {
    reset_heap();
    uint32_t a = heap_alloc(64, 0), guard = heap_alloc(16, 0), top = g_heap_top;
    heap_free(a);
    uint32_t b = heap_alloc(32, 0);
    assert(b == a && g_heap_top == top && heap_size(b) == 32);
    heap_free(b); heap_free(guard);

    a = heap_alloc(256, 0);
    memset(HP(a), 0xa5, 256);
    assert(heap_realloc(a, 32, 0) == a && heap_size(a) == 32);
    assert(heap_realloc(a, 128, 1) == a && heap_size(a) == 128);
    for (int i = 0; i < 32; i++) assert(R8(a + i) == 0xa5);
    for (int i = 32; i < 128; i++) assert(R8(a + i) == 0);
    assert(heap_realloc(a, 129, 1) == a && R8(a + 128) == 0);
    heap_free(a);

    a = heap_alloc(256, 0);
    uint32_t neighbour = heap_alloc(128, 0);
    guard = heap_alloc(16, 0);
    heap_free(neighbour);
    assert(heap_realloc(a, 32, 0) == a);
    b = heap_alloc(300, 0); /* shrink remainder coalesces with old neighbour */
    assert(b == a + 32 + 16);
    heap_free(b); heap_free(a); heap_free(guard);
    assert(g_heap_top == HEAP_LO && !g_heap_last);
}

static void test_large_fit_and_full_scan(void) {
    reset_heap();
    uint32_t large = heap_alloc(65536, 0), large_guard = heap_alloc(16, 0);
    uint32_t near = heap_alloc(50000, 0), near_guard = heap_alloc(16, 0);
    uint32_t top = g_heap_top;
    heap_free(near); heap_free(large); /* the larger, poorer fit is first */
    uint32_t smaller_request = heap_alloc(48000, 0);
    assert(smaller_request == near && g_heap_top == top);
    uint32_t larger_request = heap_alloc(64000, 0);
    assert(larger_request == large && g_heap_top == top);
    heap_free(smaller_request); heap_free(larger_request);
    heap_free(large_guard); heap_free(near_guard);
    assert(g_heap_top == HEAP_LO);

    /* The bounded best-fit search must not miss the first suitable entry,
       even when more than 32 earlier free blocks are too small. */
    uint32_t far = heap_alloc(16000, 0), far_guard = heap_alloc(16, 0);
    uint32_t blocks[48], guards[48];
    for (int i = 0; i < 48; i++) {
        blocks[i] = heap_alloc(5000, 0); guards[i] = heap_alloc(16, 0);
    }
    top = g_heap_top;
    heap_free(far);
    for (int i = 0; i < 48; i++) heap_free(blocks[i]);
    assert(heap_alloc(12000, 0) == far && g_heap_top == top);
    heap_free(far); heap_free(far_guard);
    for (int i = 0; i < 48; i++) heap_free(guards[i]);
    assert(g_heap_top == HEAP_LO);
}

static void test_large_fit_search_bound(void) {
    reset_heap();
    uint32_t blocks[33], guards[33];
    for (int i = 0; i < 33; i++) {
        uint32_t size = i == 0 ? 4512 : i == 1 ? 4704 : 8192;
        blocks[i] = heap_alloc(size, 0); guards[i] = heap_alloc(16, 0);
    }
    uint32_t top = g_heap_top;
    for (int i = 0; i < 33; i++) heap_free(blocks[i]);
    /* LIFO order: indices 32..2 occupy entries 1..31, then 1 is entry 32,
       and the exact fit 0 is entry 33, just outside the search window. */
    uint32_t first = heap_alloc(4500, 0);
    assert(first == blocks[1] && g_heap_top == top);
    /* With entry 32 removed, the former entry 33 is now inside the window. */
    uint32_t second = heap_alloc(4500, 0);
    assert(second == blocks[0] && g_heap_top == top);
    heap_free(first); heap_free(second);
    for (int i = 0; i < 33; i++) heap_free(guards[i]);
    assert(g_heap_top == HEAP_LO);
}

static void test_in_place_and_exhaustion(void) {
    reset_heap();
    uint32_t a = heap_alloc(32, 0), guard = heap_alloc(32, 0);
    W8(a, 0x91);
    assert(!heap_realloc_ex(a, 128, 0, 1));
    assert(heap_size(a) == 32 && R8(a) == 0x91);
    heap_free(guard);
    assert(heap_realloc_ex(a, 128, 0, 1) == a);
    assert(!heap_realloc(a, UINT32_MAX, 0));
    assert(heap_size(a) == 128 && R8(a) == 0x91);
    heap_free(a);
    assert(heap_size(a) == UINT32_MAX);
    assert(!heap_try_alloc(UINT32_MAX, 0));
    g_heap_top = HEAP_HI - 16;
    assert(!heap_try_alloc(32, 0));
    reset_heap();
    g_valloc_top = VALLOC_LO;
    assert(!guest_valloc(UINT32_MAX));
    assert(guest_valloc(1) == VALLOC_LO);
    assert(!guest_valloc(UINT32_MAX - 65535u));
    assert(g_valloc_top == VALLOC_LO + 65536u);
}

static void *stress(void *arg) {
    uint32_t state = (uint32_t)(uintptr_t)arg + 1;
    for (int i = 0; i < 4000; i++) {
        state = state * 1664525u + 1013904223u;
        uint32_t n = 1 + state % 4096, a = heap_alloc(n, 1);
        assert(!(a & 15u) && heap_size(a) >= n);
        for (uint32_t j = 0; j < n; j++) assert(R8(a + j) == 0);
        memset(HP(a), (int)(state & 255), n);
        uint32_t grown = n + 1 + (state >> 16) % 4096;
        uint32_t b = heap_realloc(a, grown, 1);
        assert(b && !(b & 15u) && heap_size(b) >= grown);
        for (uint32_t j = 0; j < n; j++) assert(R8(b + j) == (uint8_t)state);
        for (uint32_t j = (n + 15u) & ~15u; j < grown; j++) assert(R8(b + j) == 0);
        heap_free(b);
    }
    return NULL;
}

int main(void) {
    g_mem = calloc(1, (size_t)HEAP_LO + (32u << 20));
    assert(g_mem);
    test_coalesce_and_split();
    test_realloc();
    test_small_reuse_and_requested_size();
    test_large_fit_and_full_scan();
    test_large_fit_search_bound();
    test_in_place_and_exhaustion();
    reset_heap();
    pthread_t threads[8];
    for (uintptr_t i = 0; i < 8; i++) assert(!pthread_create(&threads[i], NULL, stress, (void *)i));
    for (int i = 0; i < 8; i++) assert(!pthread_join(threads[i], NULL));
    assert(g_heap_top == HEAP_LO && !g_heap_last);
    free(g_mem);
    puts("guest heap tests passed");
}
