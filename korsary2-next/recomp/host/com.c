#include "com.h"

#include <pthread.h>

int g_log_d3d;

#define MAX_SLOTS 8192
static struct { ComInterface *it; int idx; } g_slots[MAX_SLOTS];

#define MAX_OBJS 65536
static ComObj g_objs[MAX_OBJS];
static int g_nobjs = 1;
static int g_free_idx[MAX_OBJS], g_nfree;  /* recycled object slots */
static pthread_mutex_t g_com_lock = PTHREAD_MUTEX_INITIALIZER;

static void com_dispatch(CPU *c) {
    uint32_t slot = (g_import_target - IMPORT_BASE) / 16;
    ComInterface *it = slot < MAX_SLOTS ? g_slots[slot].it : NULL;
    if (!it) guest_trap(c, g_import_target, "COM dispatch through an unknown slot");
    const ComMethod *m = &it->methods[g_slots[slot].idx];
    if (g_log_d3d >= 2)
        fprintf(stderr, "[com] %s::%s(this=%08x, %08x %08x %08x %08x)\n", it->name, m->name, ARG(0), ARG(1),
                ARG(2), ARG(3), ARG(4));
    if (m->impl) { m->impl(c); return; }
    static char warned[MAX_SLOTS];
    if (!warned[slot]) {
        warned[slot] = 1;
        fprintf(stderr, "[com] %s::%s not implemented: returning S_OK\n", it->name, m->name);
    }
    c->eax = S_OK;
    c->esp += 4 + 4 * (uint32_t)(m->nargs + 1);
}

static uint32_t build_vtable(ComInterface *it) {
    if (it->vtable) return it->vtable;
    uint32_t vt = heap_alloc(4u * (uint32_t)it->count, 1);
    for (int i = 0; i < it->count; i++) {
        char name[128];
        snprintf(name, sizeof name, "%s::%s", it->name, it->methods[i].name);
        uint32_t magic = add_dynamic_import(name, com_dispatch);
        uint32_t slot = (magic - IMPORT_BASE) / 16;
        g_slots[slot].it = it;
        g_slots[slot].idx = i;
        W32(vt + 4u * (uint32_t)i, magic);
    }
    it->vtable = vt;
    return vt;
}

uint32_t com_new(ComInterface *it, int type, void *data) {
    pthread_mutex_lock(&g_com_lock);
    uint32_t vt = build_vtable(it);
    int idx = g_nfree ? g_free_idx[--g_nfree] : g_nobjs++;
    if (idx >= MAX_OBJS) { fprintf(stderr, "too many live COM objects\n"); abort(); }
    uint32_t g = heap_alloc(16, 1);
    W32(g, vt);
    W32(g + 4, (uint32_t)idx);
    W32(g + 8, 0xC0C0C0C0u);  /* marker so com_get can reject foreign pointers */
    g_objs[idx] = (ComObj){ it, 1, type, data, g };
    pthread_mutex_unlock(&g_com_lock);
    if (g_log_d3d) fprintf(stderr, "[com] new %s %08x\n", it->name, g);
    return g;
}

ComObj *com_get(uint32_t g) {
    if (!g || R32(g + 8) != 0xC0C0C0C0u) return NULL;
    uint32_t idx = R32(g + 4);
    return (idx > 0 && idx < MAX_OBJS && g_objs[idx].guest == g) ? &g_objs[idx] : NULL;
}

void *com_data(uint32_t g) {
    ComObj *o = com_get(g);
    return o ? o->data : NULL;
}

void com_QueryInterface(CPU *c) {
    ComObj *o = com_get(THIS);
    if (ARG(2)) W32(ARG(2), THIS);
    if (o) o->refs++;
    RET(3, S_OK);
}

void com_AddRef(CPU *c) {
    ComObj *o = com_get(THIS);
    RET(1, o ? (uint32_t)++o->refs : 1);
}

uint32_t com_retain_handle(uint32_t guest) {
    ComObj *o=com_get(guest);
    return o ? (uint32_t)++o->refs : 0;
}

uint32_t com_release_handle(uint32_t guest) {
    ComObj *o=com_get(guest);
    if (!o) return 0;
    int32_t r = --o->refs;
    if (r <= 0 && !o->iface->destroy) o->refs = r = 0;  /* singleton */
    else if (r <= 0) {
        o->refs = r = 0;
        if (o->data) {
            o->iface->destroy(o->data);
            o->data = NULL;
        }
        W32(o->guest + 8, 0);
        heap_free(o->guest);
        pthread_mutex_lock(&g_com_lock);
        o->guest = 0;
        g_free_idx[g_nfree++] = (int)(o - g_objs);
        pthread_mutex_unlock(&g_com_lock);
    }
    return (uint32_t)r;
}

void com_Release(CPU *c) {
    uint32_t r=com_release_handle(THIS);
    RET(1,r);
}

#ifdef PORT_HEAP_STATS
/* Диагностика (только с -DPORT_HEAP_STATS): живые COM-объекты по интерфейсам и обход реестра для
   подсчёта ресурсов d3d8 (d3d8.c). Только чтение; под g_com_lock (порядок com -> heap, как в com_new). */
void com_foreach_live(void (*fn)(const ComObj *, void *), void *ctx) {
    pthread_mutex_lock(&g_com_lock);
    for (int i = 1; i < g_nobjs; i++)
        if (g_objs[i].guest && g_objs[i].iface) fn(&g_objs[i], ctx);
    pthread_mutex_unlock(&g_com_lock);
}

void com_stats_log(void) {
    struct { const char *name; unsigned n; } by[64];
    int nby = 0;
    unsigned live = 0, slots;
    static unsigned live_hw;
    pthread_mutex_lock(&g_com_lock);
    slots = (unsigned)g_nobjs - 1u;
    for (int i = 1; i < g_nobjs; i++) {
        if (!g_objs[i].guest || !g_objs[i].iface) continue;
        live++;
        int k = 0;
        while (k < nby && by[k].name != g_objs[i].iface->name) k++;
        if (k == nby && nby < 64) { by[nby].name = g_objs[i].iface->name; by[nby].n = 0; nby++; }
        if (k < nby) by[k].n++;
    }
    pthread_mutex_unlock(&g_com_lock);
    if (live > live_hw) live_hw = live;
    for (int a = 0; a < nby; a++)   /* по убыванию, печатаем крупнейшие */
        for (int b = a + 1; b < nby; b++) if (by[b].n > by[a].n) { typeof(by[0]) t = by[a]; by[a] = by[b]; by[b] = t; }
    fprintf(stderr, "[comstats] live=%u (high-water %u) slots-used=%u of %d:", live, live_hw, slots, MAX_OBJS - 1);
    for (int k = 0; k < nby && k < 10; k++) fprintf(stderr, " %s=%u", by[k].name, by[k].n);
    fprintf(stderr, "\n");
}
#endif
