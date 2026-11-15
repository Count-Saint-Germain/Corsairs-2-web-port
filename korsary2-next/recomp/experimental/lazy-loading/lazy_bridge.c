/* Experimental synchronous game-thread -> asynchronous page request channel.
 * It is deliberately not wired into CreateFileA or the production build.
 * The page must verify the file against the manifest before publishing it and
 * protect against existing or user-owned files; the channel itself only
 * exchanges a path, a generation token, and completion status. */
#include "lazy_bridge.h"

#include <pthread.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#define LAZY_EXPORT EMSCRIPTEN_KEEPALIVE
#else
#define LAZY_EXPORT
#endif

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t changed = PTHREAD_COND_INITIALIZER;
/* The page only reads this atomic: it never waits for a game-thread mutex. */
static uint32_t published_token;
static struct {
    char path[PORT_LAZY_PATH_CAP];
    uint32_t next, token;
    int active, claimed, done, success;
} slot;

static int ascii_equal(const char *s, size_t n, const char *word) {
    size_t i = 0;
    for (; i < n && word[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (c >= 'A' && c <= 'Z') c = (unsigned char)(c + ('a' - 'A'));
        if (c != (unsigned char)word[i]) return 0;
    }
    return i == n && !word[i];
}

/* Additional guard at the boundary. The caller must still validate the manifest
 * and match it exactly; in particular this is not a general path normalizer. */
static int eligible(const char *path) {
    if (!path || !*path || *path == '/') return 0;
    size_t n = strnlen(path, PORT_LAZY_PATH_CAP);
    if (n == PORT_LAZY_PATH_CAP) return 0;
    size_t part = 0;
    for (size_t i = 0; i <= n; ++i) {
        unsigned char c = (unsigned char)path[i];
        if ((c && c < 32) || c == 127 || c == '\\') return 0;
        if (c && c != '/') continue;
        size_t len = i - part;
        if (!len || (len == 1 && path[part] == '.') ||
            (len == 2 && path[part] == '.' && path[part+1] == '.')) return 0;
        if (!part && (ascii_equal(path, len, "save") || ascii_equal(path, len, "save_meta") ||
                      ascii_equal(path, len, "save_tx") || ascii_equal(path, len, "options") ||
                      ascii_equal(path, len, "engine.ini"))) return 0;
        part = i + 1;
    }
    return 1;
}

static struct timespec deadline(unsigned timeout_ms) {
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    t.tv_sec += timeout_ms / 1000;
    t.tv_nsec += (long)(timeout_ms % 1000) * 1000000L;
    if (t.tv_nsec >= 1000000000L) { t.tv_sec++; t.tv_nsec -= 1000000000L; }
    return t;
}

int port_lazy_request(const char *path, unsigned timeout_ms) {
    if (!eligible(path) || !timeout_ms) return 0;
    const struct timespec until = deadline(timeout_ms);
    pthread_mutex_lock(&lock);
    while (slot.active) {
        if (pthread_cond_timedwait(&changed, &lock, &until)) {
            pthread_mutex_unlock(&lock);
            return 0;
        }
    }
    if (++slot.next == 0) ++slot.next;
    slot.token = slot.next;
    slot.active = 1; slot.claimed = slot.done = slot.success = 0;
    memcpy(slot.path, path, strlen(path) + 1);
    __atomic_store_n(&published_token, slot.token, __ATOMIC_RELEASE);
    pthread_cond_broadcast(&changed);
    while (!slot.done) {
        if (pthread_cond_timedwait(&changed, &lock, &until)) break;
    }
    int success = slot.done && slot.success;
    __atomic_store_n(&published_token, 0, __ATOMIC_RELEASE);
    slot.active = 0;
    pthread_cond_broadcast(&changed);
    pthread_mutex_unlock(&lock);
    return success;
}

LAZY_EXPORT uint32_t port_lazy_poll(char *path, uint32_t capacity) {
    uint32_t token = 0;
    if (pthread_mutex_trylock(&lock)) return 0;
    if (slot.active && !slot.claimed && !slot.done && path && capacity > strlen(slot.path)) {
        memcpy(path, slot.path, strlen(slot.path) + 1);
        slot.claimed = 1;
        token = slot.token;
    }
    pthread_mutex_unlock(&lock);
    return token;
}

LAZY_EXPORT int port_lazy_current(uint32_t token) {
    return token && __atomic_load_n(&published_token, __ATOMIC_ACQUIRE) == token;
}

LAZY_EXPORT int port_lazy_finish(uint32_t token, int success) {
    if (pthread_mutex_trylock(&lock)) return -1;
    int accepted = 0;
    if (token && slot.active && !slot.done && slot.claimed && slot.token == token) {
        slot.done = 1; slot.success = !!success;
        __atomic_store_n(&published_token, 0, __ATOMIC_RELEASE);
        pthread_cond_broadcast(&changed);
        accepted = 1;
    }
    pthread_mutex_unlock(&lock);
    return accepted;
}
