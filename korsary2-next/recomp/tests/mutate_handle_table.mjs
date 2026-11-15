#!/usr/bin/env node
// Mutate a copy of the host to check that the handle-table tests detect regressions.
import { cpSync, readFileSync, writeFileSync } from 'node:fs';
import { join } from 'node:path';
const LOCK = /[ \t]*pthread_mutex_(?:un)?lock\(&g_handle_lock\);\n/g;
function span(src, header) {
  const i = src.indexOf(header), end = src.indexOf('\n}\n', i);
  if (i < 0 || end < 0) throw new Error(`function not found: ${header}`);
  return [i, end + 3];
}
function strip(src, header) {
  const [i, j] = span(src, header), body = src.slice(i, j).replace(LOCK, '');
  if (body === src.slice(i, j)) throw new Error(`lock not found: ${header}`);
  return src.slice(0, i) + body + src.slice(j);
}
function sub(src, old, replacement) {
  if (!src.includes(old)) throw new Error(`mutation target not found: ${old}`);
  return src.replace(old, replacement);
}
function replaceFunction(src, header, body) {
  const [i, j] = span(src, header); return src.slice(0, i) + body + src.slice(j);
}
const mutations = {
  'alloc-no-lock': (c,k) => [strip(c, 'static uint32_t handle_alloc(int type, void *ptr) {'),k],
  'round-robin-flag-no-lock': (c,k) => [strip(c, 'void handle_set_round_robin(int on) {'),k],
  'claim-not-one-cas': (c,k) => [sub(c, '    } while (!__atomic_compare_exchange_n(&x->type, &t, H_RESERVED, 1, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE));', '    } while (0);\n    sched_yield();   /* MUTATION: check and set are no longer one atomic step */\n    SLOT_SET_TYPE(x, H_RESERVED);'),k],
  'write-open-scan-no-lock': (c,k) => [strip(c, 'int file_path_write_open(const char *host) {'),k],
  'type-load-not-atomic': (c,k) => [sub(c, '#define SLOT_TYPE(x) __atomic_load_n(&(x)->type, __ATOMIC_ACQUIRE)', '#define SLOT_TYPE(x) ((x)->type)'),k],
  'type-store-not-atomic': (c,k) => [sub(c, '#define SLOT_SET_TYPE(x, t) __atomic_store_n(&(x)->type, (t), __ATOMIC_RELEASE)', '#define SLOT_SET_TYPE(x, t) ((x)->type = (t))'),k],
  'publish-not-atomic': (c,k) => [sub(c, 'if (i >= 0) __atomic_compare_exchange_n(&g_handles[i].type, &expect, type, 0, __ATOMIC_RELEASE, __ATOMIC_RELAXED);', 'if (i >= 0 && g_handles[i].type == expect) g_handles[i].type = type;'),k],
  'close-without-claim': (c,k) => [replaceFunction(c, 'void handle_close(uint32_t h) {', `void handle_close(uint32_t h) {   /* MUTATION: the pre-fix close, no claim */
    WinHandle *x = handle_get(h, -1);
    if (!x) return;
    if (x->type == H_FILE && x->fd >= 0) close(x->fd);
    free(x->buf);
    if (x->type == H_FIND && x->ptr) free(x->ptr);
    x->type = H_FREE;
}
`),k],
  'close-checked-without-claim': (c,k) => [replaceFunction(c, 'int handle_close_checked(uint32_t h) {', `int handle_close_checked(uint32_t h) {   /* MUTATION: no claim, the check is not atomic with the release */
    WinHandle *x = handle_get(h, -1);
    if (!x) return 0;
    int type = x->type, fd = x->fd;
    uint8_t *buf = x->buf;
    sched_yield();
    if ((type == H_FILE || type == H_MAPPING) && fd >= 0) close(fd);
    free(buf);
    x->fd = -1; x->buf = NULL;
    SLOT_SET_TYPE(x, H_FREE);
    return 1;
}
`),k],
  'createfile-publishes-before-fill': (c,k) => [c, sub(sub(k, '    uint32_t h = strict ? hpre : handle_new(H_RESERVED);\n    WinHandle *x = handle_reserved(h);', '    uint32_t h = strict ? hpre : handle_new(H_FILE);\n    WinHandle *x = strict ? handle_reserved(h) : handle_get(h, H_FILE);'), '    } else handle_publish(h, H_FILE);', '    }')],
  'close-hook-no-wakeup': (c,k) => [c,sub(k, '    s->closed = 1;\n    pthread_cond_broadcast(&s->cv);\n', '    s->closed = 1;\n')],
  'close-hook-not-run': (c,k) => [sub(c, '    if (hook) hook(h, type, ptr);', '    (void)hook; (void)h; (void)type; (void)ptr;'),k],
  'thread-table-not-cleared': (c,k) => [c,sub(k, '    if (type == H_THREAD && h >= 0x1000u && (h - 0x1000u) / 4 < 4096)\n        __atomic_store_n(&g_threads_by_handle[(h - 0x1000u) / 4], NULL, __ATOMIC_RELEASE);\n', '')],
  'mapping-fd-not-closed': (c,k) => [sub(c, '    if ((type == H_FILE || type == H_MAPPING) && fd >= 0) close(fd);\n    free(buf);   /* read-only snapshot', '    if (type == H_FILE && fd >= 0) close(fd);\n    free(buf);   /* read-only snapshot'),k],
  'wait-ignores-closed-flag': (c,k) => [c,sub(k, '        if (s->closed) { r = WAIT_FAILED_; break; }\n', '')],
  'wait-rereads-slot': (c,k) => [c,sub(k, '    while (!try_acquire(&t, waited)) {\n        if (s->closed)', '    while (({ void *o2; int t2 = handle_snapshot(h, &o2); if (t2 != H_FREE && o2) { t.type = t2; t.s = o2; } 0; }) || !try_acquire(&t, waited)) {\n        if (s->closed)')],
};
const [name, src, dst] = process.argv.slice(2);
if (name === 'list' && process.argv.length === 3) console.log(Object.keys(mutations).join('\n'));
else if (!mutations[name] || !src || !dst || process.argv.length !== 5) {
  console.error('usage: mutate_handle_table.mjs list | NAME SRC DST'); process.exitCode = 2;
} else {
  cpSync(src, dst, { recursive: true, errorOnExist: true, force: false });
  const core = join(dst, 'core.c'), k32 = join(dst, 'kernel32.c');
  const [c, k] = mutations[name](readFileSync(core, 'utf8'), readFileSync(k32, 'utf8'));
  writeFileSync(core, c); writeFileSync(k32, k);
}
