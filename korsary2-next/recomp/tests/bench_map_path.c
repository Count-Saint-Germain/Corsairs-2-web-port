/* E1: what map_path costs per call, old tree vs new tree with the overlay off and on. Synthetic tree: a base RESOURCE/Sounds/VOICE with 1000 files
   (the real one holds 231; the overlay layer adds up to 860) plus the usual script/ini folders. Usage: bench scratch-dir off|empty|full.
   off    PORT_OVERLAY unset
   empty  overlay on, an empty folder (every lookup misses at the first component)
   full   overlay on, 1000 files in the same VOICE folder as the base (every VOICE lookup hits) */
#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "../host/core.c"
uint8_t *g_mem;
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) { (void)pred; (void)arg; (void)deadline_us; (void)deadline_fn; return 0; }

static void put(const char *base, const char *rel) {
    char p[1500];
    snprintf(p, sizeof p, "%s/%s", base, rel);
    for (char *q = p + strlen(base) + 1; *q; q++) if (*q == '/') { *q = 0; mkdir(p, 0755); *q = '/'; }
    FILE *f = fopen(p, "wb");
    if (f) { fputs("x", f); fclose(f); }
}
static double now(void) { struct timespec ts; clock_gettime(CLOCK_MONOTONIC, &ts); return ts.tv_sec + ts.tv_nsec * 1e-9; }

int main(int argc, char **argv) {
    const char *scratch = argc > 1 ? argv[1] : "/tmp";
    const char *mode = argc > 2 ? argv[2] : "off";
    char tmpl[1100], real[1100], b[1200], o[1200], u[1200], f[200];
    snprintf(tmpl, sizeof tmpl, "%s/korsary-bench-XXXXXX", scratch);
    assert(mkdtemp(tmpl) && realpath(tmpl, real));
    snprintf(b, sizeof b, "%s/game", real); snprintf(o, sizeof o, "%s/overlay", real); snprintf(u, sizeof u, "%s/user", real);
    mkdir(b, 0755); mkdir(o, 0755); mkdir(u, 0755);
    snprintf(g_game_root, sizeof g_game_root, "%s", b);
    snprintf(g_user_root, sizeof g_user_root, "%s", u);
    for (int i = 0; i < 1000; i++) { snprintf(f, sizeof f, "RESOURCE/Sounds/VOICE/Eng_%04d.wav", i); put(b, f); if (!strcmp(mode, "full")) put(o, f); }
    for (int i = 0; i < 40; i++) { snprintf(f, sizeof f, "PROGRAM/DIALOGS/d%02d.h", i); put(b, f); if (!strcmp(mode, "full") && i % 2) put(o, f); }
    put(b, "RESOURCE/INI/TEXTS/language.ini"); put(b, "SAVE/slot1"); put(b, "options");
    if (!strcmp(mode, "full")) put(o, "RESOURCE/INI/TEXTS/language.ini");
    if (!strcmp(mode, "off")) unsetenv("PORT_OVERLAY"); else setenv("PORT_OVERLAY", o, 1);
    char guest[300], host[1100];
    long n = 0;
    double t0 = now();
    const int rounds = 400;
    for (int r = 0; r < rounds; r++)
        for (int i = 0; i < 1000; i += 7) {
            snprintf(guest, sizeof guest, "C:\\Games\\Korsary2\\RESOURCE\\Sounds\\VOICE\\Eng_%04d.wav", i);
#ifdef OVERLAY_API
            OvHit ov;
            map_path_ov(guest, host, sizeof host, &ov);
#else
            map_path(guest, host, sizeof host);
#endif
            n++;
        }
    double t1 = now();
    printf("VOICE\\Eng_NNNN.wav (1000 entries per folder): %.2f us per call (%ld calls)\n", (t1 - t0) / (double)n * 1e6, n);
    n = 0; t0 = now();
    for (int r = 0; r < 20000; r++) {
        const char *g = (r % 3 == 0) ? "C:\\Games\\Korsary2\\RESOURCE\\INI\\TEXTS\\language.ini" : (r % 3 == 1) ? "C:\\Games\\Korsary2\\SAVE\\slot1" : "C:\\Games\\Korsary2\\PROGRAM\\DIALOGS\\d07.h";
#ifdef OVERLAY_API
        OvHit ov;
        map_path_ov(g, host, sizeof host, &ov);
#else
        map_path(g, host, sizeof host);
#endif
        n++;
    }
    t1 = now();
    printf("ini / SAVE / script paths: %.2f us per call (%ld calls)\n", (t1 - t0) / (double)n * 1e6, n);
    char cmd[1300];
    snprintf(cmd, sizeof cmd, "rm -rf '%s'", real);
    return system(cmd) != 0;
}
