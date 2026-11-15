#ifndef K2_LAZY_BRIDGE_H
#define K2_LAZY_BRIDGE_H

#include <stdint.h>

/* Experimental transport only: not connected to the game or installer.
 * `path` is the canonical UTF-8, slash-separated manifest path. Call only
 * after looking it up in the current validated manifest; this module never
 * reads or writes the filesystem. A positive timeout is mandatory. */
enum { PORT_LAZY_PATH_CAP = 1024 };
int port_lazy_request(const char *path, unsigned timeout_ms);

/* Page side: poll claims one request and copies its path; 0 means none.
 * A nonzero token is valid only while current(token) is true. The requester
 * returns 1 after finish(token, 1), and 0 for every failure or timeout.
 * finish returns -1 if the mutex is momentarily busy (the page MUST retry),
 * 1 if accepted, or 0 if stale. It never waits on the browser main thread. */
uint32_t port_lazy_poll(char *path, uint32_t capacity);
int port_lazy_current(uint32_t token);
int port_lazy_finish(uint32_t token, int success);

#endif
