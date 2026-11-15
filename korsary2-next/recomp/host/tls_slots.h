/* Windows-style process-wide TLS indexes, with per-thread values. */
#ifndef PORT_TLS_SLOTS_H
#define PORT_TLS_SLOTS_H

#include <pthread.h>
#include <stdint.h>

enum { PORT_TLS_SLOTS = 64 };
typedef struct {
    pthread_mutex_t mutex;
    uint64_t used;
    uint64_t generation[PORT_TLS_SLOTS];
} PortTlsTable;

typedef struct {
    uint32_t value[PORT_TLS_SLOTS];
    uint64_t generation[PORT_TLS_SLOTS];
} PortTlsValues;

#define PORT_TLS_TABLE_INIT { .mutex = PTHREAD_MUTEX_INITIALIZER }

static inline uint32_t port_tls_alloc(PortTlsTable *t) {
    pthread_mutex_lock(&t->mutex);
    for (uint32_t i = 0; i < PORT_TLS_SLOTS; i++) {
        uint64_t bit = UINT64_C(1) << i;
        if (!(t->used & bit)) {
            t->used |= bit;
            if (++t->generation[i] == 0) ++t->generation[i];
            pthread_mutex_unlock(&t->mutex);
            return i;
        }
    }
    pthread_mutex_unlock(&t->mutex);
    return UINT32_MAX;
}

static inline int port_tls_free(PortTlsTable *t, uint32_t i) {
    if (i >= PORT_TLS_SLOTS) return 0;
    pthread_mutex_lock(&t->mutex);
    uint64_t bit = UINT64_C(1) << i;
    int ok = (t->used & bit) != 0;
    t->used &= ~bit;
    pthread_mutex_unlock(&t->mutex);
    return ok;
}

static inline int port_tls_get(PortTlsTable *t, PortTlsValues *v, uint32_t i, uint32_t *out) {
    if (i >= PORT_TLS_SLOTS || !v) return 0;
    pthread_mutex_lock(&t->mutex);
    /* The first 64 indexes are range-checked but not allocation-checked by
       Windows' fast TlsGetValue/TlsSetValue paths. */
    *out = v->generation[i] == t->generation[i] ? v->value[i] : 0;
    pthread_mutex_unlock(&t->mutex);
    return 1;
}

static inline int port_tls_set(PortTlsTable *t, PortTlsValues *v, uint32_t i, uint32_t value) {
    if (i >= PORT_TLS_SLOTS || !v) return 0;
    pthread_mutex_lock(&t->mutex);
    v->value[i] = value; v->generation[i] = t->generation[i];
    pthread_mutex_unlock(&t->mutex);
    return 1;
}
#endif
