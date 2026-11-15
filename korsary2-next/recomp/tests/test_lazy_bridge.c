#include "lazy_bridge.h"
#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct { const char *path; unsigned timeout; int result; } Job;
static void *request(void *arg) {
    Job *j = arg;
    j->result = port_lazy_request(j->path, j->timeout);
    return NULL;
}
static void pause_ms(long ms) {
    struct timespec t = { ms / 1000, (ms % 1000) * 1000000L };
    nanosleep(&t, NULL);
}
static void finish(uint32_t token, int result) {
    while (port_lazy_finish(token, result) == -1) pause_ms(1);
}
static uint32_t take(char *path, size_t size) {
    for (int n = 0; n < 2000; ++n) {
        uint32_t t = port_lazy_poll(path, (uint32_t)size);
        if (t) return t;
        pause_ms(1);
    }
    assert(!"request did not arrive");
    return 0;
}
int main(void) {
    const char *bad[] = { "", "/foo", "..", "./x", "a/../b", "a//b", "a\\b",
                          "SAVE/slot", "save_meta/file", "Save_TX/file", "OPTIONS",
                          "engine.ini", "x/", "a\nb" };
    for (size_t i = 0; i < sizeof bad / sizeof bad[0]; ++i) assert(!port_lazy_request(bad[i], 5));
    assert(!port_lazy_request("RESOURCE/test", 0));
    char huge[PORT_LAZY_PATH_CAP + 1]; memset(huge, 'a', sizeof huge); huge[sizeof huge-1] = 0;
    assert(!port_lazy_request(huge, 5));

    char path[PORT_LAZY_PATH_CAP], tiny[1]; pthread_t a, b;
    Job first = { "RESOURCE/Models/Ship.gm", 1000, -1 };
    assert(!pthread_create(&a, NULL, request, &first));
    pause_ms(10);
    assert(port_lazy_poll(tiny, sizeof tiny) == 0); /* too short must not claim */
    uint32_t t1 = take(path, sizeof path);
    assert(!strcmp(path, first.path));
    assert(port_lazy_current(t1));
    assert(port_lazy_poll(path, sizeof path) == 0); /* claim is exclusive */
    finish(t1, 1);
    pthread_join(a, NULL);
    assert(first.result == 1 && !port_lazy_current(t1));

    Job expired = { "RESOURCE/Textures/old.tx", 80, -1 };
    assert(!pthread_create(&a, NULL, request, &expired));
    uint32_t old = take(path, sizeof path);
    pthread_join(a, NULL);
    assert(expired.result == 0 && !port_lazy_current(old));
    Job next = { "RESOURCE/Textures/new.tx", 1000, -1 };
    assert(!pthread_create(&b, NULL, request, &next));
    uint32_t current = take(path, sizeof path);
    assert(current != old && !strcmp(path, next.path));
    finish(old, 1); /* a late response cannot complete a new request */
    assert(port_lazy_current(current));
    finish(current, 0);
    pthread_join(b, NULL);
    assert(next.result == 0);

    Job one = { "RESOURCE/a", 1000, -1 }, two = { "RESOURCE/b", 1000, -1 };
    assert(!pthread_create(&a, NULL, request, &one));
    uint32_t a_token = take(path, sizeof path);
    assert(!pthread_create(&b, NULL, request, &two));
    pause_ms(10);
    assert(port_lazy_poll(path, sizeof path) == 0);
    finish(a_token, 1);
    uint32_t b_token = take(path, sizeof path);
    assert(!strcmp(path, two.path));
    finish(b_token, 1);
    pthread_join(a, NULL); pthread_join(b, NULL);
    assert(one.result == 1 && two.result == 1 && a_token != b_token);
    puts("lazy bridge: validated paths, completion, timeout, stale replies, concurrent requests PASS");
}
