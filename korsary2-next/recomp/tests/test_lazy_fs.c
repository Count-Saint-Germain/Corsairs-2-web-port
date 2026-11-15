/* End-to-end tests of the experimental metadata and CreateFile hooks with a
 * fake downloader. Works on a private temporary tree and never opens saves. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdatomic.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t t, uint64_t (*f)(void)) {
    (void)pred; (void)arg; (void)t; (void)f; return 0;
}
static char testroot[1024];
static int fetches, failures;
static int list_files(const char *, char [][260], unsigned *);
static int named(char [][260], unsigned *, int, const char *, unsigned);
#ifdef PORT_LAZY_EXPERIMENT
static pthread_mutex_t gate_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t gate_cond = PTHREAD_COND_INITIALIZER;
static int race_mode, request_started, request_release;
static void pending_download(void) {
    pthread_mutex_lock(&gate_lock);
    request_started = 1; pthread_cond_broadcast(&gate_cond);
    while (!request_release) pthread_cond_wait(&gate_cond, &gate_lock);
    pthread_mutex_unlock(&gate_lock);
}
int port_lazy_request(const char *name, unsigned ms) {
    assert(ms);
    if (!strcmp(name, "RESOURCE/Textures/Fail.dat")) {
        failures++;
        char pending[1200]; snprintf(pending, sizeof pending, "%s/%s", testroot, name);
        FILE *f = fopen(pending, "wb"); assert(f); fclose(f); /* async cleanup has not yet run */
        if (race_mode) pending_download();
        return 0;
    }
    assert(!strcmp(name, "RESOURCE/Textures/Only.dat")); fetches++;
    char path[1200]; snprintf(path, sizeof path, "%s/%s", testroot, name);
    FILE *f = fopen(path, "wb"); assert(f); fclose(f); /* visible placeholder */
    if (race_mode) pending_download();
    f = fopen(path, "wb"); assert(f); assert(fwrite("FETCH!", 1, 6, f) == 6); fclose(f);
    return 1;
}
typedef struct { const char *name; uint32_t base; atomic_int started, done; int success; off_t size; } OpenJob;
static void *parallel_open(void *arg) {
    OpenJob *job = arg; CPU c = {0}; GuestThread thread = {0}; t_self = &thread;
    c.esp = job->base; W32(c.esp, 0); strcpy((char *)HP(job->base + 0x100), job->name);
    W32(c.esp + 4, job->base + 0x100); W32(c.esp + 8, 0x80000000u); W32(c.esp + 12, 1);
    W32(c.esp + 16, 0); W32(c.esp + 20, 3); W32(c.esp + 24, 0); W32(c.esp + 28, 0);
    atomic_store(&job->started, 1); w_CreateFileA(&c);
    job->success = c.eax != 0xffffffffu;
    if (job->success) {
        WinHandle *h = handle_get(c.eax, H_FILE); assert(h); struct stat st;
        assert(!fstat(h->fd, &st)); job->size = st.st_size;
        uint32_t handle = c.eax; c.esp = job->base; W32(c.esp + 4, handle); w_CloseHandle(&c);
    }
    atomic_store(&job->done, 1); return NULL;
}
static void test_parallel_open(const char *name, int expected_success) {
    OpenJob first = {.name=name, .base=0x4000}, second = {.name=name, .base=0x5000};
    request_started = request_release = 0; race_mode = 1;
    pthread_t a, b; assert(!pthread_create(&a, NULL, parallel_open, &first));
    pthread_mutex_lock(&gate_lock);
    while (!request_started) pthread_cond_wait(&gate_cond, &gate_lock);
    pthread_mutex_unlock(&gate_lock);
    assert(!pthread_create(&b, NULL, parallel_open, &second));
    while (!atomic_load(&second.started)) sched_yield();
    struct timespec delay = {.tv_nsec = 50000000}; nanosleep(&delay, NULL);
    assert(!atomic_load(&first.done) && !atomic_load(&second.done)); /* never open placeholder */
    char names[16][260]; unsigned sizes[16];
    int n = list_files("RESOURCE/Textures/*.dat", names, sizes);
    const char *visible = expected_success ? "Only.dat" : "Fail.dat";
    assert(named(names, sizes, n, visible, expected_success ? 6 : 9) == 1); /* logical size, not placeholder 0 */
    pthread_mutex_lock(&gate_lock); request_release = 1; pthread_cond_broadcast(&gate_cond); pthread_mutex_unlock(&gate_lock);
    pthread_join(a, NULL); pthread_join(b, NULL); race_mode = 0;
    assert(first.success == expected_success && second.success == expected_success);
    if (expected_success) assert(first.size == 6 && second.size == 6);
}
#endif
static void makedir(const char *p) { assert(!mkdir(p, 0700)); }
static void put(const char *path, const char *data) { FILE *f = fopen(path, "wb"); assert(f); fputs(data, f); fclose(f); }
static uint32_t call(void (*fn)(CPU *), int n, const uint32_t *args) {
    static GuestThread thread; CPU c = {0}; t_self = &thread;
    c.esp = 0x100; W32(c.esp, 0);
    for (int i = 0; i < n; i++) W32(c.esp + 4 + i * 4, args[i]);
    fn(&c); return c.eax;
}
static uint32_t str(uint32_t p, const char *s) { strcpy((char *)HP(p), s); return p; }
static uint32_t attr(const char *p) { uint32_t a[] = { str(0x1000, p) }; return call(w_GetFileAttributesA, 1, a); }
static int list_files(const char *spec, char names[][260], unsigned *sizes) {
    uint32_t a[] = { str(0x1000, spec), 0x2000 }; int count = 0;
    uint32_t h = call(w_FindFirstFileA, 2, a);
    if (h == 0xffffffffu) return 0;
    do {
        const char *name = (const char *)HP(0x2000 + 44);
        if (strcmp(name, ".") && strcmp(name, "..")) {
            assert(count < 16); snprintf(names[count], 260, "%s", name);
            sizes[count++] = R32(0x2000 + 32);
        }
        uint32_t next[] = { h, 0x2000 };
        if (!call(w_FindNextFileA, 2, next)) break;
    } while (1);
    uint32_t close[] = { h }; call(w_FindClose, 1, close);
    return count;
}
static int named(char names[][260], unsigned *sizes, int n, const char *name, unsigned sz) {
    int found = 0; for (int i = 0; i < n; i++) if (!strcmp(names[i], name)) { assert(sizes[i] == sz); found++; }
    return found;
}
int main(int argc, char **argv) {
    assert(argc == 2); snprintf(testroot, sizeof testroot, "%s/game", argv[1]); makedir(testroot);
    snprintf(g_game_root, sizeof g_game_root, "%s", testroot);
    snprintf(g_user_root, sizeof g_user_root, "%s/user", argv[1]); makedir(g_user_root);
    char p[1500]; snprintf(p, sizeof p, "%s/RESOURCE", testroot); makedir(p);
    snprintf(p, sizeof p, "%s/RESOURCE/Textures", testroot); makedir(p);
    snprintf(p, sizeof p, "%s/RESOURCE/Textures/EXISTING.DAT", testroot); put(p, "base");
    snprintf(p, sizeof p, "%s/RESOURCE/PhysicalFile", testroot); put(p, "physical-file");
    snprintf(p, sizeof p, "%s/SAVE", testroot); makedir(p);
    snprintf(p, sizeof p, "%s/SAVE/slot", testroot); put(p, "saved");
    snprintf(p, sizeof p, "%s/SAVE/copy", testroot); put(p, "keep");
    snprintf(p, sizeof p, "%s/options", testroot); put(p, "user options");
    snprintf(p, sizeof p, "%s/engine.ini", testroot); put(p, "engine");
    char overlay[1200]; snprintf(overlay, sizeof overlay, "%s/overlay", argv[1]); makedir(overlay);
    snprintf(p, sizeof p, "%s/RESOURCE", overlay); makedir(p);
    snprintf(p, sizeof p, "%s/RESOURCE/Textures", overlay); makedir(p);
    snprintf(p, sizeof p, "%s/RESOURCE/Textures/Both.txt", overlay); put(p, "OVERLAY");
    snprintf(p, sizeof p, "%s/RESOURCE/Blocked", overlay); put(p, "overlay-file");
    snprintf(p, sizeof p, "%s/index.tsv", argv[1]);
    put(p, "RESOURCE/Textures/existing.dat\t99\nRESOURCE/Textures/Only.dat\t6\n"
           "RESOURCE/Textures/Fail.dat\t9\nRESOURCE/Textures/Both.txt\t66\n"
           "RESOURCE/Virtual/\xD0\x81\xD0\xB6.txt\t5\nRESOURCE/Virtual/Sub/Thing.dat\t8\n"
           "RESOURCE/Blocked/Sub/file.txt\t1\nRESOURCE/PhysicalFile/Sub/file.txt\t1\n"
           "SAVE/ignore\t3\noptions\t1\nengine.ini\t1\n");
    setenv("PORT_LAZY_INDEX", p, 1); setenv("PORT_OVERLAY", overlay, 1);
    assert(overlay_init_from_env() == 0); g_mem = calloc(1, 0x100000); assert(g_mem);
    guest_set_cwd(GUEST_ROOT); name_cp1251_set(1);
    char names[16][260]; unsigned sizes[16];
    int n = list_files("RESOURCE/Textures/*", names, sizes);
    assert(named(names, sizes, n, "EXISTING.DAT", 4) == 1);
    assert(named(names, sizes, n, "Both.txt", 7) == 1);
#ifdef PORT_LAZY_EXPERIMENT
    assert(n == 4 && named(names, sizes, n, "Only.dat", 6) == 1 && named(names, sizes, n, "Fail.dat", 9) == 1);
    assert(attr("resource/virtual") == 0x10);
    assert(attr("resource/virtual/\xB8\xE6.TXT") == 0x20); /* ёж, CP1251 */
    assert(attr("SAVE/ignore") == 0xffffffffu && attr("options") == 0x20 && attr("engine.ini") == 0x20);
    assert(attr("RESOURCE/Virtual/Sub") == 0x10 && attr("RESOURCE/Virtual/Sub/Thing.dat") == 0x20);
    assert(attr("RESOURCE/Virtual/Missing/../Sub/Thing.dat") == 0x20);
    assert(attr("RESOURCE/Blocked") == 0x20 && attr("RESOURCE/Blocked/Sub/file.txt") == 0xffffffffu);
    assert(attr("RESOURCE/PhysicalFile") == 0x20 && attr("RESOURCE/PhysicalFile/Sub/file.txt") == 0xffffffffu);
    assert(attr("RESOURCE/Blocked/Sub/../../Virtual/Sub/Thing.dat") == 0x20);
    assert(list_files("RESOURCE/Blocked/*", names, sizes) == 0);
    assert(list_files("RESOURCE/PhysicalFile/*", names, sizes) == 0);
    char mapped[1024]; assert(!map_path("resource/textures/only.DAT", mapped, sizeof mapped));
    assert(strstr(mapped, "/RESOURCE/Textures/Only.dat"));
    assert(!lazy_guest_node("RESOURCE/../SAVE/ignore"));
    assert(!lazy_guest_node("C:/outside/RESOURCE/Textures/Only.dat"));
    n = list_files("RESOURCE/Textures/*.dat", names, sizes);
    assert(n == 3 && named(names, sizes, n, "Only.dat", 6) == 1);
    n = list_files("RESOURCE/Virtual/*", names, sizes);
    assert(n == 2 && named(names, sizes, n, "\xA8\xE6.txt", 5) == 1); /* Ёж, CP1251 */
    n = list_files("RESOURCE/Virtual/Sub/*.dat", names, sizes);
    assert(n == 1 && named(names, sizes, n, "Thing.dat", 8) == 1);
    uint32_t missing[] = { str(0x1000, "resource/textures/not-in-manifest.dat"), 0x80000000u, 1, 0, 3, 0, 0 };
    assert(call(w_CreateFileA, 7, missing) == 0xffffffffu && !fetches && !failures);
    uint32_t overlayopen[] = { str(0x1000, "resource/textures/both.txt"), 0x80000000u, 1, 0, 3, 0, 0 };
    uint32_t oh = call(w_CreateFileA, 7, overlayopen); assert(oh != 0xffffffffu && !fetches);
    WinHandle *overhandle = handle_get(oh, H_FILE); assert(overhandle);
    char buf[8] = {0}; assert(read(overhandle->fd, buf, 7) == 7 && !strcmp(buf, "OVERLAY"));
    uint32_t oc[] = { oh }; call(w_CloseHandle, 1, oc);
    uint32_t ow[] = { str(0x1000, "resource/textures/only.dat"), 0x40000000u, 1, 0, 2, 0, 0 };
    assert(call(w_CreateFileA, 7, ow) == 0xffffffffu && !fetches);
    uint32_t so[] = { str(0x1000, "RESOURCE/../SAVE/slot"), 0x80000000u, 1, 0, 3, 0, 0 };
    uint32_t sh = call(w_CreateFileA, 7, so); assert(sh != 0xffffffffu && !fetches);
    uint32_t sc[] = { sh }; call(w_CloseHandle, 1, sc);
    uint32_t userwrite[] = { str(0x1000, "SAVE/../options"), 0x40000000u, 1, 0, 2, 0, 0 };
    uint32_t uh = call(w_CreateFileA, 7, userwrite); assert(uh != 0xffffffffu && !fetches);
    uint32_t uc[] = { uh }; call(w_CloseHandle, 1, uc);
    test_parallel_open("resource/textures/only.dat", 1);
    assert(fetches == 1);
    uint32_t a[] = { str(0x1000, "resource/textures/only.dat"), 0x80000000u, 1, 0, 3, 0, 0 };
    uint32_t h = call(w_CreateFileA, 7, a); assert(h != 0xffffffffu && fetches == 1);
    uint32_t cl[] = { h }; call(w_CloseHandle, 1, cl);
    h = call(w_CreateFileA, 7, a); assert(h != 0xffffffffu && fetches == 1);
    cl[0] = h; call(w_CloseHandle, 1, cl);
    ow[0] = str(0x1000, "resource/textures/only.dat");
    assert(call(w_CreateFileA, 7, ow) == 0xffffffffu);
    snprintf(p, sizeof p, "%s/RESOURCE/Textures/Only.dat", testroot);
    struct stat st; assert(stat(p, &st) == 0 && st.st_size == 6);
    uint32_t cp[] = { str(0x1000, "resource/textures/only.dat"), str(0x1400, "SAVE/copy"), 0 };
    assert(call(w_CopyFileA, 3, cp) == 1 && fetches == 1);
    snprintf(p, sizeof p, "%s/SAVE/copy", testroot); FILE *copied = fopen(p, "rb"); assert(copied);
    char copybytes[8] = {0}; assert(fread(copybytes, 1, 6, copied) == 6 && !strcmp(copybytes, "FETCH!")); fclose(copied);
    uint32_t protectcopy[] = { str(0x1000, "SAVE/slot"), str(0x1400, "RESOURCE/Textures/Only.dat"), 0 };
    assert(call(w_CopyFileA, 3, protectcopy) == 0);
    uint32_t del[] = { str(0x1000, "RESOURCE/Textures/Only.dat") };
    assert(call(w_DeleteFileA, 1, del) == 0);
    uint32_t move[] = { str(0x1000, "SAVE/slot"), str(0x1400, "RESOURCE/Textures/Only.dat") };
    assert(call(w_MoveFileA, 2, move) == 0);
    uint32_t mk[] = { str(0x1000, "RESOURCE/Virtual/Sub"), 0 };
    assert(call(w_CreateDirectoryA, 2, mk) == 0);
    assert(call(w_RemoveDirectoryA, 1, mk) == 0);
    snprintf(p, sizeof p, "%s/SAVE/slot", testroot); copied = fopen(p, "rb"); assert(copied);
    memset(copybytes, 0, sizeof copybytes); assert(fread(copybytes, 1, 5, copied) == 5 && !strcmp(copybytes, "saved")); fclose(copied);
    test_parallel_open("resource/textures/FAIL.dat", 0);
    assert(failures == 1 && fetches == 1);
    uint32_t fail[] = { str(0x1000, "resource/textures/FAIL.dat"), 0x80000000u, 1, 0, 3, 0, 0 };
    snprintf(p, sizeof p, "%s/RESOURCE/Textures/Fail.dat", testroot); assert(access(p, F_OK) == 0);
    n = list_files("RESOURCE/Textures/*.dat", names, sizes);
    assert(named(names, sizes, n, "Fail.dat", 9) == 1); /* failed request has not cleaned placeholder yet */
    assert(call(w_CreateFileA, 7, fail) == 0xffffffffu && failures == 1); /* leftover placeholder rejected */
    uint32_t copy_fail[] = { str(0x1000, "resource/textures/FAIL.dat"), str(0x1400, "SAVE/copy"), 0 };
    assert(call(w_CopyFileA, 3, copy_fail) == 0 && failures == 1);
    snprintf(p, sizeof p, "%s/SAVE/copy", testroot); copied = fopen(p, "rb"); assert(copied);
    memset(copybytes, 0, sizeof copybytes); assert(fread(copybytes, 1, 6, copied) == 6 && !strcmp(copybytes, "FETCH!")); fclose(copied);
    a[0] = str(0x1000, "resource/textures/only.dat");
    assert(call(w_CreateFileA, 7, a) == 0xffffffffu && fetches == 1); /* process is poisoned */
    so[0] = str(0x1000, "SAVE/slot"); sh = call(w_CreateFileA, 7, so);
    assert(sh != 0xffffffffu); sc[0] = sh; call(w_CloseHandle, 1, sc); /* user saves unaffected */
#else
    assert(n == 2 && attr("resource/virtual") == 0xffffffffu);
    assert(fetches == 0);
#endif
    free(g_mem); puts("experimental lazy filesystem: PASS");
}
