/* An immutable, in-memory view of a validated manifest, separate from OPFS.
 * Callers build it before worker threads start and retain it until they stop.
 * It is metadata only: never use membership to permit a write or overwrite
 * saves/options, and never infer a file has been fetched from membership. */
#include "lazy_index.h"
#include "win32.h" /* name_guest_to_host and overlay_name_key */
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>

struct LazyNode {
    char *name, *key_raw, *key_cp;
    struct LazyNode *parent;
    struct LazyNode **children;
    size_t count, capacity;
    uint64_t size;
    int directory;
};
struct LazyIndex { LazyNode root; };

static void node_clear(LazyNode *n) {
    for (size_t i = 0; i < n->count; i++) { node_clear(n->children[i]); free(n->children[i]); }
    free(n->children); free(n->name); free(n->key_raw); free(n->key_cp);
}
LazyIndex *lazy_index_new(void) {
    LazyIndex *index = calloc(1, sizeof *index);
    if (index) index->root.directory = 1;
    return index;
}
void lazy_index_free(LazyIndex *index) { if (index) { node_clear(&index->root); free(index); } }
const LazyNode *lazy_index_root(const LazyIndex *index) { return index ? &index->root : NULL; }
size_t lazy_index_count(const LazyNode *n) { return n && n->directory ? n->count : 0; }
const LazyNode *lazy_index_entry(const LazyNode *n, size_t i) { return n && n->directory && i < n->count ? n->children[i] : NULL; }
const char *lazy_index_name(const LazyNode *n) { return n && n->name ? n->name : ""; }
int lazy_index_is_dir(const LazyNode *n) { return n && n->directory; }
uint64_t lazy_index_size(const LazyNode *n) { return n && !n->directory ? n->size : 0; }
const LazyNode *lazy_index_parent(const LazyNode *n) { return n ? n->parent : NULL; }
int lazy_index_path(const LazyNode *n, char *out, size_t cap) {
    if (!out || !cap) return 0;
    out[0] = 0;
    const LazyNode *parts[512]; size_t count = 0, len = 0;
    while (n && n->parent) {
        if (count == 512) return 0;
        parts[count++] = n; n = n->parent;
    }
    while (count) {
        const char *name = parts[--count]->name; size_t nlen = strlen(name);
        if (len + nlen + (len ? 1 : 0) >= cap) { out[0] = 0; return 0; }
        if (len) out[len++] = '/';
        memcpy(out + len, name, nlen); len += nlen; out[len] = 0;
    }
    return 1;
}

/* Existing overlay folding is deliberately reused; JS Unicode case-folding
 * is not guaranteed to match the guest's Windows-1251 filename rules. */
static char *key_for(const char *name, int cp) {
    size_t n = strlen(name);
    if (n > 511) return NULL;
    char *key = malloc(n * 4 + 1);
    if (key) overlay_name_key(name, cp, key, n * 4 + 1);
    return key;
}
static LazyNode *find_key(const LazyNode *dir, const char *key, int cp) {
    if (!dir || !dir->directory) return NULL;
    for (size_t i = 0; i < dir->count; i++) {
        LazyNode *n = dir->children[i];
        if (!strcmp(cp ? n->key_cp : n->key_raw, key)) return n;
    }
    return NULL;
}
const LazyNode *lazy_index_child(const LazyNode *dir, const char *component, int cp1251) {
    if (!component || !*component || strchr(component, '/') || strchr(component, '\\')) return NULL;
    char utf8[2048];
    const char *name = component;
    if (cp1251 && !name_guest_to_host(component, utf8, sizeof utf8)) return NULL;
    if (cp1251) name = utf8;
    char *key = key_for(name, cp1251);
    if (!key) return NULL;
    LazyNode *found = find_key(dir, key, cp1251);
    free(key);
    return found;
}
const LazyNode *lazy_index_host_child(const LazyNode *dir, const char *name, int cp1251) {
    if (!name || !*name || strchr(name, '/') || strchr(name, '\\')) return NULL;
    char *key = key_for(name, cp1251);
    if (!key) return NULL;
    LazyNode *found = find_key(dir, key, cp1251);
    free(key);
    return found;
}
static int mutable_root(const char *s) {
    return !strcasecmp(s, "SAVE") || !strcasecmp(s, "SAVE_META") ||
           !strcasecmp(s, "SAVE_TX") || !strcasecmp(s, "options") || !strcasecmp(s, "engine.ini");
}
int lazy_index_add(LazyIndex *index, const char *path, uint64_t size) {
    if (!index || !path || !*path || strlen(path) >= 1024 || *path == '/') return -1;
    LazyNode *dir = &index->root;
    const char *p = path;
    for (;;) {
        const char *slash = strchr(p, '/');
        size_t len = slash ? (size_t)(slash - p) : strlen(p);
        if (!len || len > 255) return -1;
        char part[256]; memcpy(part, p, len); part[len] = 0;
        if (!strcmp(part, ".") || !strcmp(part, "..") || strchr(part, '\\')) return -1;
        for (size_t i = 0; i < len; i++) if ((unsigned char)part[i] < 32 || part[i] == ':') return -1;
        if (dir == &index->root && mutable_root(part)) return 0;
        char *raw = key_for(part, 0), *cp = key_for(part, 1);
        if (!raw || !cp) { free(raw); free(cp); return -1; }
        LazyNode *n = find_key(dir, cp, 1);
        if (n) {
            free(raw); free(cp);
            /* Reject ambiguous/colliding spellings and duplicate files rather
             * than silently choosing an asset different from the manifest. */
            if (strcmp(n->name, part) || !slash || !n->directory) return -1;
        } else {
            n = calloc(1, sizeof *n);
            if (!n) { free(raw); free(cp); return -1; }
            n->name = strdup(part); n->key_raw = raw; n->key_cp = cp;
            n->parent = dir;
            n->directory = slash != NULL; n->size = slash ? 0 : size;
            if (!n->name) { node_clear(n); free(n); return -1; }
            if (dir->count == dir->capacity) {
                size_t cap = dir->capacity ? dir->capacity * 2 : 8;
                LazyNode **children = realloc(dir->children, cap * sizeof *children);
                if (!children) { node_clear(n); free(n); return -1; }
                dir->children = children; dir->capacity = cap;
            }
            dir->children[dir->count++] = n;
        }
        if (!slash) return 1;
        dir = n; p = slash + 1;
    }
}

int lazy_index_load(LazyIndex *index, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return 0;
    char *line = NULL; size_t cap = 0; ssize_t len; int ok = 1;
    while ((len = getline(&line, &cap, f)) != -1) {
        if (len < 3 || line[len - 1] != '\n' || memchr(line, '\0', (size_t)len)) { ok = 0; break; }
        line[--len] = 0;
        char *tab = strchr(line, '\t');
        if (!tab || !tab[1] || strchr(tab + 1, '\t')) { ok = 0; break; }
        *tab++ = 0;
        for (char *s = tab; *s; s++) if (*s < '0' || *s > '9') { ok = 0; break; }
        if (!ok) break;
        errno = 0; char *end = NULL;
        unsigned long long size = strtoull(tab, &end, 10);
        if (errno || !end || *end || lazy_index_add(index, line, size) < 0) { ok = 0; break; }
    }
    if (ferror(f)) ok = 0;
    free(line); fclose(f);
    return ok;
}
