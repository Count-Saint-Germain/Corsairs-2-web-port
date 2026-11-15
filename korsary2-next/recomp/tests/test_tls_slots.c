#include "tls_slots.h"
#include <assert.h>
#include <pthread.h>
#include <stdint.h>

static PortTlsTable table = PORT_TLS_TABLE_INIT;
static uint32_t slots[64];

static void *worker(void *arg) {
    uintptr_t n = (uintptr_t)arg;
    PortTlsValues values = {0};
    for (uint32_t i = 0; i < 8; i++) {
        uint32_t slot = port_tls_alloc(&table), value = 0;
        assert(slot < 64);
        slots[n * 8 + i] = slot;
        assert(port_tls_get(&table, &values, slot, &value) && value == 0);
        assert(port_tls_set(&table, &values, slot, (uint32_t)n + 1));
        assert(port_tls_get(&table, &values, slot, &value) && value == n + 1);
    }
    return NULL;
}

int main(void) {
    pthread_t threads[8];
    for (uintptr_t i = 0; i < 8; i++) assert(!pthread_create(&threads[i], NULL, worker, (void *)i));
    for (int i = 0; i < 8; i++) assert(!pthread_join(threads[i], NULL));
    uint64_t seen = 0;
    for (int i = 0; i < 64; i++) {
        uint64_t bit = UINT64_C(1) << slots[i];
        assert(!(seen & bit));
        seen |= bit;
    }
    assert(seen == UINT64_MAX && port_tls_alloc(&table) == UINT32_MAX);

    PortTlsValues a = {0}, b = {0};
    uint32_t out;
    assert(port_tls_set(&table, &a, 63, 123));
    assert(port_tls_get(&table, &a, 63, &out) && out == 123);
    assert(port_tls_get(&table, &b, 63, &out) && out == 0);
    assert(port_tls_set(&table, &b, 63, 456));
    assert(port_tls_free(&table, 63));
    /* Windows' first 64 slots are range checked even if not allocated. */
    assert(port_tls_get(&table, &a, 63, &out) && out == 123);
    assert(port_tls_set(&table, &a, 63, 999));
    assert(!port_tls_free(&table, 63));
    assert(port_tls_alloc(&table) == 63);
    assert(port_tls_get(&table, &a, 63, &out) && out == 0);
    assert(port_tls_get(&table, &b, 63, &out) && out == 0);
    assert(port_tls_set(&table, &a, 0, 7));
    assert(port_tls_get(&table, &a, 0, &out) && out == 7);
    assert(!port_tls_get(&table, &a, 64, &out));
    assert(!port_tls_set(&table, &a, 64, 1));
    assert(!port_tls_free(&table, 64));
    return 0;
}
