/* Native launcher: loads the game executable's image, wires up the Windows API layer and runs the game's
 * real entry point (the MSVC C runtime startup, which then calls WinMain).
 *
 * Usage: game [game-folder]      (default: ./game)
 * Env:   PORT_LOG=1          host-side log (files, registry, threads, ...)
 *        PORT_LOG_IMPORTS=1  every Windows call the game makes
 *        PORT_LOG_D3D=1|2    Direct3D object creation (1) or every Direct3D call (2)
 *        PORT_LOG_FPS=1      frames per second
 *        PORT_HEADLESS=1     no window (rendering skipped, Present paced at 60 Hz)
 *        PORT_NO_AUDIO=1     mute
 */
#include "win32.h"
#include "render.h"
#include "port_modules.h"

#include <limits.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

static LoadedImage g_img;
static CPU g_cpu;
/* port_modules.h (generated) provides: static const PortModule port_modules[]; PORT_NMODULES */

/* PORT_WATCHDOG=secs: periodically print the game thread's guest call stack (return addresses found
   on its stack), to see where it is when it seems stuck. */
static void *watchdog(void *arg) {
    int secs = (int)(intptr_t)arg;
    for (;;) {
        sleep((unsigned)secs);
        if (deterministic()) {   /* a stuck game thread that doesn't move these spins on memory */
            extern uint32_t g_det_reads, g_det_sleeps, g_det_waits;
            extern uint64_t g_vtime_us;
            fprintf(stderr, "[watchdog] virtual time %.6f s, game thread: clock reads %u, sleeps %u, waits %u\n",
                    g_vtime_us * 1e-6, g_det_reads, g_det_sleeps, g_det_waits);
        }
        extern GuestThread *g_all_threads[64];
        extern int g_nthreads;
        for (int t = -1; t < g_nthreads && t < 64; t++) {
            CPU *c = t < 0 ? &g_cpu : &g_all_threads[t]->cpu;
            fprintf(stderr, "[watchdog] %s %x esp=%08x stack:", t < 0 ? "game thread" : "thread", t < 0 ? 0x100 : g_all_threads[t]->id,
                    c->esp);
            for (int k = 0, n = 0; k < 2048 && n < 16; k++) {
                uint32_t v = R32(c->esp + 4 * k);
                if (looks_like_code(v)) { fprintf(stderr, " %08x", v); n++; }
            }
            fprintf(stderr, "\n");
        }
    }
    return NULL;
}

static void *game_main(void *arg) {
    (void)arg;
    CPU *c = &g_cpu;
    thread_main_init(c);
    sched_main_init();
    t_self->cpu = *c;            /* keep the thread record consistent with the main CPU */
    fpu_sync_rounding(c);
    GuestFn entry = lookup_function(g_img.entry);
    if (!entry) { fprintf(stderr, "entry point %08x was not recompiled\n", g_img.entry); exit(1); }
    fprintf(stderr, "starting game at %08x\n", g_img.entry);
    PUSH32(c, GUEST_RETURN_SENTINEL);
    entry(c);
    fprintf(stderr, "game returned %d\n", (int)c->eax);
    exit((int)c->eax);
}

#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
#include <emscripten/wasmfs.h>
#endif

#define _XOPEN_SOURCE 1
#include <signal.h>
#include <ucontext.h>
extern CPU g_cpu;
static void segv_report(int sig, siginfo_t *si, void *uc) {
    ucontext_t *u = (ucontext_t *)uc;
    fprintf(stderr, "\n*** HOST %s at addr %p, pc %llx\n", sig == SIGSEGV ? "SIGSEGV" : "SIGBUS",
            si->si_addr, (unsigned long long)u->uc_mcontext->__ss.__pc);
    fprintf(stderr, "    guest: esp %08x ebp %08x edi %08x esi %08x edx %08x ecx %08x\n",
            g_cpu.esp, g_cpu.ebp, g_cpu.edi, g_cpu.esi, g_cpu.edx, g_cpu.ecx);
    fprintf(stderr, "    guest stack:");
    for (int i = 0; i < 24; i++) fprintf(stderr, " [%d]%08x", i, R32(g_cpu.esp + 4 * i));
    fprintf(stderr, "\n");
    {   /* the engine-interface object modules get from DMAInterface: dump its dispatch table */
        uint32_t ifc = R32(0x475a10);
        if (ifc) {
            uint32_t t = R32(ifc);
            fprintf(stderr, "    [ifc] 475a10=%08x table=%08x slots:", ifc, t);
            for (int i = 0; i < 8; i++) fprintf(stderr, " %08x", R32(t + 4 * i));
            fprintf(stderr, "\n");
        }
    }
    _exit(139);
}

int main(int argc, char **argv) {
    struct sigaction sa = { .sa_sigaction = segv_report, .sa_flags = SA_SIGINFO };
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGBUS, &sa, NULL);
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    /* browser: the page copied the player's game folder into OPFS; reach it through /opfs */
    wasmfs_create_directory("/opfs", 0777, wasmfs_create_opfs_backend());
#endif
    const char *game = argc > 1 ? argv[1] : "game";
    if (!realpath(game, g_game_root)) { perror(game); return 1; }
    /* PORT_USERDATA: another folder for saves and settings (e.g. a fresh copy per test run) */
    if (getenv("PORT_USERDATA")) snprintf(g_user_root, sizeof g_user_root, "%s", getenv("PORT_USERDATA"));
    else snprintf(g_user_root, sizeof g_user_root, "%s/../userdata", g_game_root);
    mkdir(g_user_root, 0755);
    g_log = getenv("PORT_LOG") != NULL;
    extern int g_log_d3d;
    g_log_d3d = getenv("PORT_LOG_D3D") ? atoi(getenv("PORT_LOG_D3D")) : 0;

    static ImportHandler all[1024];
    uint32_t n = 0;
    const ImportTable *tables[] = { &kernel32_imports, &user32_imports, &gdi32_imports, &advapi32_imports,
                                    &winmm_imports, &directx_imports, &shell_imports };
    for (size_t t = 0; t < sizeof tables / sizeof tables[0]; t++)
        for (uint32_t i = 0; i < tables[t]->count; i++) all[n++] = tables[t]->list[i];
    set_import_handlers(all, n);

    runtime_init(&g_cpu);
    vclock_init();
    char exe[1100];
    snprintf(exe, sizeof exe, "%s/%s", g_game_root, PORT_EXE);
    if (load_image(exe, 0, &g_img)) return 1;
    /* The engine LoadLibrarys its module DLLs at run time, but translated code bakes in the final
       bases configure.mjs chose — so map every module now; LoadLibraryA just resolves the name. */
    for (size_t i = 0; i < PORT_NMODULES; i++) {
        char mp[1100];
        snprintf(mp, sizeof mp, "%s/%s", g_game_root, port_modules[i].name);
        for (char *p = mp; *p; p++) if (*p == '\\') *p = '/';
        LoadedImage mi;
        if (load_image(mp, port_modules[i].base, &mi)) return 1;
        module_set_name(mi.image_base, port_modules[i].name);
    }
    register_all_functions();
    /* DLL_PROCESS_ATTACH for every module: runs their CRT startup / C++ constructors (the interface
       objects the engine fetches with GetProcAddress live in module .data and need them). */
    /* DllMain (CRT init) runs on the loader thread on Windows: give the attach phase a thread
       record so TLS/critical-section handlers behave (t_self is otherwise NULL here). */
    thread_main_init(&g_cpu);
    for (size_t i = 0; i < PORT_NMODULES; i++) guest_module_attach(port_modules[i].base, &g_cpu);
    if (getenv("PORT_WATCH_ADDR")) {   /* native debugging: catch the first write near the address */
        extern void watch_arm(uint32_t addr);
        uint32_t wa = (uint32_t)strtoul(getenv("PORT_WATCH_ADDR"), NULL, 16);
        fprintf(stderr, "[watch-arm] arming %08x\n", wa);
        watch_arm(wa);
    }
    fprintf(stderr, "loaded %s + %zu module images: %u imports, %u of them implemented\n", exe,
            PORT_NMODULES, g_img.num_imports, n);

    /* The window and its event loop must live on the main thread (macOS); the game gets its own
       thread. PORT_HEADLESS=1 runs without a window (no rendering, 60 Hz pacing). */
    int headless = getenv("PORT_HEADLESS") != NULL;
    extern int window_create(const char *title);
    extern void window_event_loop(void);
#ifdef __EMSCRIPTEN__
    /* browser: the page owns the canvas and replays our frames; this thread just waits for the game */
    if (!headless) g_render = &g_render_gpu;
    headless = 1;
#else
    if (!headless && window_create(PORT_NAME)) g_render = &g_render_gpu;
    else headless = 1;
#endif

    /* Recompiled code nests one host frame per guest call, so give the game a generous host stack. */
    pthread_attr_t at;
    pthread_attr_init(&at);
    pthread_attr_setstacksize(&at, 256u << 20);
    pthread_t th;
    pthread_create(&th, &at, game_main, NULL);
    if (getenv("PORT_WATCHDOG")) {
        pthread_t wd;
        pthread_create(&wd, NULL, watchdog, (void *)(intptr_t)atoi(getenv("PORT_WATCHDOG")));
    }
    if (headless) pthread_join(th, NULL);
    else window_event_loop();  /* never returns; closing the window exits */
    return 0;
}
