/* Exercise the real allocator, COM registry and sound implementation together. */
#include <assert.h>
#include <stdatomic.h>
#include "../host/core.c"
#include "../host/com.c"
#include "../host/dsound.c"

uint8_t *g_mem;
__thread uint32_t g_import_target;

/* Only the external services needed to link the production vtables are stubbed. */
void kernel_set_event(uint32_t h) { (void)h; }
uint32_t add_dynamic_import(const char *name, GuestFn fn) {
    static uint32_t next;
    (void)name; (void)fn;
    return IMPORT_BASE + 16 * next++;
}
void guest_trap(CPU *c, uint32_t addr, const char *msg) {
    (void)c; (void)addr; (void)msg; abort();
}
void *sched_new(const char *name, int (*start)(void *), void *arg) {
    (void)name; (void)start; (void)arg; return NULL;
}
void sched_enter(void *p) { (void)p; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline, uint64_t (*fn)(void)) {
    (void)pred; (void)arg; (void)deadline; (void)fn; return 0;
}

static void args(CPU *c, uint32_t self, uint32_t a, uint32_t b, uint32_t d) {
    memset(c, 0, sizeof *c);
    c->esp = 64;
    W32(68, self); W32(72, a); W32(76, b); W32(80, d);
}
static uint32_t create(uint32_t size) {
    W32(0x1004, 0); W32(0x1008, size); W32(0x1010, 0);
    return new_buffer(0x1000, 1);
}
static uint32_t release(uint32_t p) {
    CPU c; args(&c, p, 0, 0, 0); sound_Release(&c); return c.eax;
}
static uint32_t addref(uint32_t p) {
    CPU c; args(&c, p, 0, 0, 0); sound_AddRef(&c); return c.eax;
}
static uint32_t duplicate(uint32_t p) {
    CPU c; args(&c, 0, p, 0x2000, 0); ds_DuplicateSoundBuffer(&c);
    assert(c.eax == S_OK); return R32(0x2000);
}
static uint32_t query(uint32_t p, const uint8_t iid[16]) {
    CPU c; memcpy(HP(0x2100), iid, 16); args(&c, p, 0x2100, 0x2200, 0);
    b_QueryInterface(&c); assert(c.eax == S_OK); return R32(0x2200);
}

static void test_allocation_refusal(void) {
    CPU c;
    W32(0x1004, 0); W32(0x1008, UINT32_MAX); W32(0x1010, 0);
    args(&c, 0, 0x1000, 0x2000, 0); ds_CreateSoundBuffer(&c);
    assert(c.eax == 0x8007000eu && R32(0x2000) == 0 && !g_bufs);
    uint32_t old_top = g_heap_top;
    g_heap_top = HEAP_HI - 16;
    W32(0x1008, 112896);
    args(&c, 0, 0x1000, 0x2000, 0); ds_CreateSoundBuffer(&c);
    assert(c.eax == 0x8007000eu && R32(0x2000) == 0 && !g_bufs);
    g_heap_top = old_top;
}

static void test_shared_storage(void) {
    uint32_t original = create(112896), copy = duplicate(original);
    SBuf *a = com_data(original), *b = com_data(copy);
    assert(a && b && a != b && a->mem == b->mem && a->storage->refs == 2);
    uint32_t mem = b->mem;
    assert(heap_size(mem) == 112912);
    W8(a->mem + 4, 0x5a);
    assert(R8(b->mem + 4) == 0x5a);
    assert(!release(original));
    assert(b->storage->refs == 1 && heap_size(mem) == 112912);
    assert(R8(b->mem + 4) == 0x5a);
    W8(b->mem + 5, 0x7b); assert(R8(mem + 5) == 0x7b);
    assert(!release(copy));
    assert(heap_size(mem) == UINT32_MAX && !g_bufs);
}

static void test_interface_lifetime(void) {
    const uint8_t notify[16] = { 0x83, 0x07, 0x21, 0xb0, 0xcd, 0x89, 0xd0, 0x11,
                                 0xaf, 8, 0, 0xa0, 0xc9, 0x25, 0xcd, 0x16 };
    const uint8_t listener[16] = { 0x84, 0xfa, 0x9a, 0x27, 0x81, 0x49, 0xce, 0x11,
                                   0xa5, 0x21, 0, 0x20, 0xaf, 0x0b, 0xe5, 0x60 };
    const uint8_t iunknown[16] = {0,0,0,0,0,0,0,0,0xc0,0,0,0,0,0,0,0x46};
    const uint8_t buffer[16] = {0x85,0xfa,0x9a,0x27,0x81,0x49,0xce,0x11,
                                0xa5,0x21,0,0x20,0xaf,0x0b,0xe5,0x60};
    const uint8_t buffer3d[16] = {0x86,0xfa,0x9a,0x27,0x81,0x49,0xce,0x11,
                                  0xa5,0x21,0,0x20,0xaf,0x0b,0xe5,0x60};
    uint32_t original = create(1024);
    SBuf *b = com_data(original);
    uint32_t n = query(original, notify), l = query(n, listener), d = query(l, buffer3d);
    assert(n != original && l != original && d != original && b->refs == 4);
    uint32_t identity1 = query(n, iunknown), identity2 = query(d, iunknown);
    uint32_t from_child = query(l, buffer), same = query(l, listener);
    assert(identity1 == original && identity2 == original && from_child == original && same == l);
    assert(release(identity1) && release(identity2) && release(from_child));
    assert(release(same) == 1);
    assert(addref(original) == 5 && release(original) == 4);
    assert(release(original) == 3 && com_data(n) == b);
    assert(!release(n) && com_data(l) == b);
    assert(!release(l) && com_data(d) == b);
    assert(!release(d) && !g_bufs);

    const uint8_t unknown[16] = {0};
    original = create(1024);
    CPU c; memcpy(HP(0x2100), unknown, 16);
    args(&c, original, 0x2100, 0x2200, 0); b_QueryInterface(&c);
    assert(c.eax == E_NOINTERFACE && R32(0x2200) == 0);
    assert(!release(original) && !g_bufs);
}

static uint32_t create_from_device(uint32_t device, uint32_t flags) {
    CPU c;
    W32(0x1004, flags); W32(0x1008, 1024); W32(0x1010, 0);
    args(&c, device, 0x1000, 0x2000, 0); ds_CreateSoundBuffer(&c);
    assert(c.eax == S_OK); return R32(0x2000);
}
static uint32_t make_device(int version8) {
    CPU c;
    W32(0x2000, 0);
    args(&c, 0, 0x2000, 0, 0);
    if (version8) w_DirectSoundCreate8(&c); else w_DirectSoundCreate(&c);
    assert(c.eax == S_OK && c.esp == 80);
    return R32(0x2000);
}
static uint32_t device_query(uint32_t device, const uint8_t iid[16], uint32_t expected) {
    CPU c;
    memcpy(HP(0x2100), iid, 16);
    W32(0x2200, 0xdeadbeefu);
    args(&c, device, 0x2100, 0x2200, 0);
    g_import_target = R32(R32(device));
    com_dispatch(&c);
    assert(c.eax == expected && c.esp == 80);
    return R32(0x2200);
}
static void test_device_interfaces(void) {
    const uint8_t unknown[16] = {0,0,0,0,0,0,0,0,0xc0,0,0,0,0,0,0,0x46};
    const uint8_t iid[16] = {0x83,0xfa,0x9a,0x27,0x81,0x49,0xce,0x11,
                             0xa5,0x21,0,0x20,0xaf,0x0b,0xe5,0x60};
    const uint8_t iid8[16] = {0x93,0x7e,0x0a,0xc5,0x95,0xf3,0x34,0x48,
                              0x9e,0xf6,0x7f,0xa9,0x9d,0xe5,0x09,0x66};
    const uint8_t unsupported[16] = {0};
    uint32_t legacy = make_device(0), modern = make_device(1);
    assert(com_get(legacy)->iface == &IDirectSound_i);
    assert(com_get(modern)->iface == &IDirectSound8_i);
    assert(IDirectSound_i.count == 11 && IDirectSound8_i.count == 12);
    assert(device_query(legacy, iid8, E_NOINTERFACE) == 0);
    assert(device_query(legacy, unsupported, E_NOINTERFACE) == 0);
    assert(device_query(legacy, unknown, S_OK) == legacy);
    assert(device_query(legacy, iid, S_OK) == legacy);
    assert(release(legacy) == 2 && release(legacy) == 1);
    assert(device_query(modern, iid8, S_OK) == modern);
    assert(device_query(modern, iid, S_OK) == modern);
    assert(device_query(modern, unknown, S_OK) == modern);
    assert(device_query(modern, unsupported, E_NOINTERFACE) == 0);
    assert(release(modern) == 3 && release(modern) == 2 && release(modern) == 1);

    /* An IDirectSound8 queried as its base still creates Buffer8-capable buffers. */
    uint32_t alias = device_query(modern, iid, S_OK);
    uint32_t base = create_from_device(alias, 0);
    assert(com_data(base) && ((SBuf *)com_data(base))->supports_buffer8);
    assert(!release(base));
    assert(release(alias) == 1);
    release(legacy); release(modern); /* Device objects retain legacy singleton behavior. */
}

static void test_buffer8(void) {
    const uint8_t iid8[16] = {0x49,0xa4,0x25,0x68,0x24,0x75,0x82,0x4d,
                              0x92,0x0f,0x50,0xe3,0x6a,0xb3,0xab,0x1e};
    const uint8_t unknown[16] = {0,0,0,0,0,0,0,0,0xc0,0,0,0,0,0,0,0x46};
    const uint8_t notify[16] = {0x83,0x07,0x21,0xb0,0xcd,0x89,0xd0,0x11,
                                0xaf,0x08,0,0xa0,0xc9,0x25,0xcd,0x16};
    uint32_t device8 = com_new(&IDirectSound8_i, 0, NULL);
    uint32_t legacy = com_new(&IDirectSound_i, 0, NULL);
    uint32_t base = create_from_device(device8, 0), dup8 = duplicate(base);
    uint32_t primary = create_from_device(device8, 1), old = create_from_device(legacy, 0);
    CPU c;
    for (int i = 0; i < 2; i++) {
        uint32_t denied = i ? old : primary;
        memcpy(HP(0x2100), iid8, 16); args(&c, denied, 0x2100, 0x2200, 0);
        b_QueryInterface(&c); assert(c.eax == E_NOINTERFACE && !R32(0x2200));
    }
    uint32_t iface8 = query(base, iid8), copy8 = query(dup8, iid8);
    assert(iface8 != base && copy8 != dup8 && com_data(iface8) == com_data(base));
    assert(query(iface8, unknown) == base);
    assert(release(base) >= 1); /* Drop IUnknown obtained above. */
    uint32_t n = query(iface8, notify), back8 = query(n, iid8);
    assert(com_data(back8) == com_data(base));
    assert(IDirectSoundBuffer8_i.count == 24);
    for (int i = 0; i < 21; i++) {
        assert(buf8_methods[i].impl == buf_methods[i].impl);
        assert(buf8_methods[i].nargs == buf_methods[i].nargs);
        assert(R32(R32(iface8) + 4u * (unsigned)i) != 0);
    }
    for (int slot = 21; slot <= 23; slot++) {
        W32(0x2300, 0xa5a5a5a5u);
        args(&c, iface8, 0, 0, 0);
        W32(84, 0x2300); /* Fourth argument for GetObjectInPath. */
        g_import_target = R32(R32(iface8) + 4u * (unsigned)slot);
        com_dispatch(&c);
        assert(c.esp == 64u + (slot == 23 ? 24u : 20u));
        if (slot == 23) assert(c.eax == DSERR_OBJECTNOTFOUND && R32(0x2300) == 0);
        else assert(c.eax == DSERR_CONTROLUNAVAIL);
    }
    args(&c, iface8, 0, 0, 0); W32(84, 0);
    g_import_target = R32(R32(iface8) + 4u * 23u); com_dispatch(&c);
    assert(c.eax == DSERR_INVALIDPARAM && c.esp == 88);
    assert(release(base) >= 1);
    assert(!release(iface8)); assert(!release(n)); assert(!release(back8));
    assert(release(dup8) == 1); assert(!release(copy8));
    assert(!release(primary)); assert(!release(old)); assert(!g_bufs);
}

typedef struct { uint32_t guest, stack; } RefJob;
static void *ref_worker(void *arg) {
    RefJob *j = arg;
    CPU c = {0};
    for (int i = 0; i < 10000; i++) {
        c.esp = j->stack; W32(j->stack + 4, j->guest); sound_AddRef(&c);
        assert(c.eax >= 2);
        c.esp = j->stack; sound_Release(&c); assert(c.eax >= 1);
    }
    c.esp = j->stack; sound_Release(&c);
    return NULL;
}
static void test_concurrent_references(void) {
    uint32_t original = create(64);
    RefJob jobs[8]; pthread_t refs[8];
    for (int i = 0; i < 8; i++) {
        assert(addref(original) >= 2);
        jobs[i] = (RefJob){ original, 0x3000 + 64u * (unsigned)i };
        assert(!pthread_create(&refs[i], NULL, ref_worker, &jobs[i]));
    }
    for (int i = 0; i < 8; i++) pthread_join(refs[i], NULL);
    assert(!release(original) && !g_bufs);
}

static atomic_int done;
static void *mixer(void *arg) {
    (void)arg; float out[32];
    while (!atomic_load(&done)) mix_frames(out, 16);
    return NULL;
}
static void *setter_worker(void *arg) {
    RefJob *j = arg;
    CPU c = {0};
    W32(j->stack + 4, j->guest);
    for (int i = 0; i < 10000; i++) {
        c.esp = j->stack; W32(j->stack + 8, (uint32_t)(i % 100)); b_SetVolume(&c);
        c.esp = j->stack; b_SetPan(&c);
        c.esp = j->stack; W32(j->stack + 8, 22050u + (unsigned)i % 1000); b_SetFrequency(&c);
        c.esp = j->stack; W32(j->stack + 8, 0x6000); b_GetStatus(&c);
    }
    return NULL;
}
static void test_mix_and_duplicate_setters(void) {
    uint32_t original = create(1024);
    SBuf *b = com_data(original);
    pthread_mutex_lock(&g_snd_lock);
    b->playing = 1; b->looping = 1;
    pthread_mutex_unlock(&g_snd_lock);
    RefJob job = {original, 0x5000}; pthread_t setter, mixing;
    atomic_store(&done, 0);
    assert(!pthread_create(&mixing, NULL, mixer, NULL));
    assert(!pthread_create(&setter, NULL, setter_worker, &job));
    for (int i = 0; i < 1000; i++) { uint32_t p = duplicate(original); assert(!release(p)); }
    pthread_join(setter, NULL);
    atomic_store(&done, 1); pthread_join(mixing, NULL);
    assert(!release(original) && !g_bufs);
    atomic_store(&done, 0);
}

static void test_mixer_lifetime(void) {
    pthread_t thread;
    assert(!pthread_create(&thread, NULL, mixer, NULL));
    for (int i = 0; i < 4000; i++) {
        uint32_t original = create(1024), copy = duplicate(original);
        SBuf *b = com_data(copy);
        pthread_mutex_lock(&g_snd_lock);
        b->playing = 1; b->looping = 1;
        pthread_mutex_unlock(&g_snd_lock);
        if (i % 2) { release(original); release(copy); }
        else { release(copy); release(original); }
    }
    atomic_store(&done, 1);
    pthread_join(thread, NULL);
    assert(!g_bufs);
}

int main(void) {
    g_mem = calloc(1, (size_t)GUEST_HEAP_BASE + (32u << 20));
    assert(g_mem);
    test_allocation_refusal();
    test_shared_storage();
    test_interface_lifetime();
    test_buffer8();
    test_device_interfaces();
    test_concurrent_references();
    test_mix_and_duplicate_setters();
    test_mixer_lifetime();
    puts("sound lifetime test PASS");
    free(g_mem);
    return 0;
}
