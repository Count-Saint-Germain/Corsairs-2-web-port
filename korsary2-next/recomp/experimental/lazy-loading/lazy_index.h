/* Experimental manifest namespace for a future on-demand loader. It does not
 * access storage, fetch data, or change the currently shipped filesystem. */
#ifndef PORT_LAZY_INDEX_H
#define PORT_LAZY_INDEX_H
#include <stddef.h>
#include <stdint.h>

typedef struct LazyIndex LazyIndex;
typedef struct LazyNode LazyNode;

LazyIndex *lazy_index_new(void);
void lazy_index_free(LazyIndex *index);
/* Add one UTF-8 manifest path and its uncompressed size. 1 = added,
 * 0 = intentionally excluded mutable root, -1 = invalid, ambiguous or OOM.
 * Discard the whole index on any error; partial indices must not be used. */
int lazy_index_add(LazyIndex *index, const char *path, uint64_t size);
/* Parse UTF-8 path<TAB>size<LF> records. On error discard the entire index. */
int lazy_index_load(LazyIndex *index, const char *filename);
const LazyNode *lazy_index_root(const LazyIndex *index);
/* `component` is one guest path component, not a path. cp1251 selects the
 * same guest conversion/folding as map_path's opt-in CP1251 mode. */
const LazyNode *lazy_index_child(const LazyNode *dir, const char *component, int cp1251);
/* Name from a host directory entry is already UTF-8; no guest decoding. */
const LazyNode *lazy_index_host_child(const LazyNode *dir, const char *name, int cp1251);
size_t lazy_index_count(const LazyNode *dir);
const LazyNode *lazy_index_entry(const LazyNode *dir, size_t position);
const char *lazy_index_name(const LazyNode *node);
int lazy_index_is_dir(const LazyNode *node);
uint64_t lazy_index_size(const LazyNode *node);
const LazyNode *lazy_index_parent(const LazyNode *node);
int lazy_index_path(const LazyNode *node, char *out, size_t capacity);
#endif
