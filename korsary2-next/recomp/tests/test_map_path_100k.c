/* E1: map_path with the overlay OFF must give, for every input, exactly what the old map_path gave. This program builds a fixed
   synthetic tree, generates N pseudo-random guest paths (random and boundary: case, / and \, ".", "..", doubled separators, drive
   forms, relative paths against several working directories, names with bytes >= 0x80 in UTF-8 and CP1251 form, 255/256-byte
   components, paths past 1024 bytes, outside the game folder) and prints one line per path: exists flag and the host path (the
   temp root removed). run_overlay.sh diff compiles THIS FILE against the old copy of recomp/host (which has no map_path_ov and no
   overlay) and against the current tree, with PORT_OVERLAY unset / "0" / "" (and with an overlay folder that holds only files the
   overlay never looks at), and compares the outputs byte for byte. With the argument "ov" it also calls map_path_ov and checks it
   agrees with map_path whenever the overlay holds nothing (kind 0): same host path, same existence.
   Usage: test scratch-dir [N] [unset|0|empty|decoys] [cp1251] [ov] */
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
uint8_t *g_mem;
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) { (void)pred; (void)arg; (void)deadline_us; (void)deadline_fn; return 0; }

static char root[1024], uroot[1024];
static void put(const char *base, const char *rel) {
    char p[1500];
    snprintf(p, sizeof p, "%s/%s", base, rel);
    for (char *q = p + strlen(base) + 1; *q; q++) if (*q == '/') { *q = 0; mkdir(p, 0755); *q = '/'; }
    FILE *f = fopen(p, "wb");
    if (f) { fputs("x", f); fclose(f); }
}
static uint64_t rng = 0x9E3779B97F4A7C15ull;
static uint32_t rnd(void) { rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return (uint32_t)(rng >> 16); }

int main(int argc, char **argv) {
    const char *scratch = argc > 1 ? argv[1] : "/tmp";
    long n = argc > 2 ? atol(argv[2]) : 100000;
    const char *ovmode = argc > 3 ? argv[3] : "unset";
    int cp = argc > 4 && !strcmp(argv[4], "cp1251");
    int check_ov = argc > 5 && !strcmp(argv[5], "ov");
    unsetenv("PORT_NAME_CP1251");
    if (!strcmp(ovmode, "unset")) unsetenv("PORT_OVERLAY");
    else if (!strcmp(ovmode, "empty")) setenv("PORT_OVERLAY", "", 1);
    else if (!strcmp(ovmode, "decoys")) {
        char od[1500];
        snprintf(od, sizeof od, "%s/korsary-mp-overlay-XXXXXX", scratch);
        assert(mkdtemp(od));
        static const char *names[] = { "data", "Data", "SAVE/s1", "SAVE_META/m", "options", "engine.ini", "ENGINE.exe", "MODULES/a.dll", "x/y/z", "stray", NULL };
        for (int i = 0; names[i]; i++) put(od, names[i]);
        setenv("PORT_OVERLAY", od, 1);
    } else setenv("PORT_OVERLAY", ovmode, 1);
    snprintf(root, sizeof root, "%s/korsary-mp-XXXXXX", scratch);
    assert(mkdtemp(root));
    char real[1100];
    assert(realpath(root, real));
    snprintf(root, sizeof root, "%s", real);
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    snprintf(uroot, sizeof uroot, "%s-user", root);
    assert(mkdir(uroot, 0755) == 0);
    snprintf(g_user_root, sizeof g_user_root, "%s", uroot);
    if (cp) name_cp1251_set(1);
    static const char *files[] = {
        "ENGINE.exe", "options", "engine.ini", "PROGRAM/DIALOGS/a.h", "PROGRAM/DIALOGS/B.h", "PROGRAM/seadogs.c", "RESOURCE/INI/TEXTS/language.ini",
        "RESOURCE/INI/fonts.ini", "RESOURCE/Sounds/VOICE/Eng_001.wav", "RESOURCE/Sounds/VOICE/eng_002.WAV", "RESOURCE/Textures/Loading/a.tga.tx",
        "SAVE/slot1", "SAVE/Slot Two", "SAVE_META/slot1.time", "MODULES/m.dll", "a/b/c/d/e/f/g/h.txt", "dir with space/file name.txt",
        "RESOURCE/INI/\xD0\x81\xD0\xB6.txt", "RESOURCE/INI/\xD1\x91\xD0\xB6.txt", "RESOURCE/\xD0\xA2\xD0\xB5\xD1\x81\xD1\x82/f.txt", "RESOURCE/INI/ascii.txt",
        "RESOURCE/INI/\xD2\xE5\xF1\xF2.txt", "RESOURCE/INI/\xA8\xE6.txt", NULL };
    for (int i = 0; files[i]; i++) put(root, files[i]);
    put(uroot, "profile/p.dat"); put(uroot, "Temp/t.tmp");
    static const char *names[] = {
        "PROGRAM", "program", "Program", "RESOURCE", "resource", "SAVE", "save", "Save", "SAVE_META", "MODULES", "DIALOGS", "dialogs", "a.h", "A.H", "B.h", "b.H",
        "seadogs.c", "INI", "ini", "TEXTS", "texts", "language.ini", "LANGUAGE.INI", "fonts.ini", "Sounds", "VOICE", "voice", "Eng_001.wav", "ENG_002.wav", "Textures",
        "Loading", "a.tga.tx", "slot1", "Slot Two", "slot1.time", "options", "OPTIONS", "engine.ini", "ENGINE.EXE", "m.dll", "a", "b", "c", "d", "e", "f", "g", "h.txt",
        "dir with space", "file name.txt", "nosuch", "x", "..", "..", "..", ".", ".", "", "...", "a.", " a", "C:", "c:", "D:", "Games", "Korsary2", "korsary2", "GAMES",
        "profile", "p.dat", "Temp", "t.tmp", "\xD0\x81\xD0\xB6.txt", "\xD1\x91\xD0\xB6.txt", "\xD0\xA2\xD0\xB5\xD1\x81\xD1\x82", "f.txt", "\xD2\xE5\xF1\xF2.txt", "\xD2\xE5\xF1\xF2",
        "\xA8\xE6.txt", "\xB8\xE6.TXT", "\xC8\xE3\xF0\xE0", "ascii.txt", "ASCII.TXT", "?", "*", "a*b", "con", "nul", "A:B", NULL };
    int nn = 0;
    while (names[nn]) nn++;
    static const char *prefixes[] = {
        "", "", "", "C:\\Games\\Korsary2\\", "C:\\GAMES\\KORSARY2\\", "c:/games/korsary2/", "C:\\Games\\Korsary2", "C:\\Games\\Korsary2\\\\", "C:\\Games\\Korsary23\\",
        "\\", "/", "\\\\", "C:", "C:\\", "C:\\Games\\", "D:\\", "d:\\x\\", "C:\\Games\\Korsary2\\..\\", "C:\\Games\\Korsary2\\.\\", ".\\", "..\\", "..\\..\\", "\\\\?\\C:\\Games\\Korsary2\\",
        "C:\\Games\\Korsary2\\PROGRAM\\", "C:\\Games\\Korsary2\\RESOURCE\\", "C:\\Games\\Korsary2\\SAVE\\", NULL };
    int np = 0;
    while (prefixes[np]) np++;
    static const char *cwds[] = { "C:\\Games\\Korsary2", "C:\\Games\\Korsary2\\PROGRAM", "C:\\Games\\Korsary2\\RESOURCE\\INI", "C:\\Games\\Korsary2\\SAVE", "C:\\Windows", "D:\\", "C:\\", NULL };
    int nc = 0;
    while (cwds[nc]) nc++;
    long mism = 0;
    for (long i = 0; i < n; i++) {
        char guest[3000];
        if (i % 1000 == 0) guest_set_cwd(cwds[rnd() % (uint32_t)nc]);
        guest[0] = 0;
        strcat(guest, prefixes[rnd() % (uint32_t)np]);
        int depth = (int)(rnd() % 10);
        for (int k = 0; k < depth; k++) {
            if (rnd() % 97 == 0) {   /* boundary: components of 254..257 bytes, and a path past 1024 bytes */
                int len = 254 + (int)(rnd() % 4);
                size_t at = strlen(guest);
                for (int j = 0; j < len && at + 2 < sizeof guest; j++) guest[at++] = (char)('a' + (rnd() % 3));
                guest[at] = 0;
            } else strncat(guest, names[rnd() % (uint32_t)nn], sizeof guest - strlen(guest) - 1);
            strncat(guest, (rnd() % 5 == 0) ? "/" : "\\", sizeof guest - strlen(guest) - 1);
            if (rnd() % 31 == 0) strncat(guest, (rnd() % 2) ? "\\" : "/", sizeof guest - strlen(guest) - 1);
        }
        if (rnd() % 3 == 0 && guest[0]) guest[strlen(guest) - 1] = 0;
        if (i < 64) {   /* a few fixed cases first */
            static const char *fixed[] = { "", ".", "..", "\\", "C:\\Games\\Korsary2", "C:\\Games\\Korsary2\\", "ENGINE.exe", "c:\\GAMES\\korsary2\\engine.EXE", "SAVE\\slot1",
                "save\\SLOT1", "PROGRAM\\DIALOGS\\A.H", "..\\..\\..\\..\\etc\\passwd", "PROGRAM\\..\\..\\..\\SAVE\\slot1", "RESOURCE\\INI\\\xD0\x81\xD0\xB6.txt", "RESOURCE\\INI\\\xA8\xE6.txt", "C:\\Games\\Korsary2\\RESOURCE\\INI\\\xB8\xE6.TXT" };
            const int nf = (int)(sizeof fixed / sizeof *fixed);
            snprintf(guest, sizeof guest, "%s", fixed[i % nf]);
        }
        char host[1024];
        int ex = map_path(guest, host, sizeof host);
        const char *shown = host;
        size_t rl = strlen(root), ul = strlen(uroot);
        char rel[1100];
        if (!strncmp(host, root, rl) && (host[rl] == '/' || host[rl] == 0)) { snprintf(rel, sizeof rel, "G:%s", host + rl); shown = rel; }
        else if (!strncmp(host, uroot, ul) && (host[ul] == '/' || host[ul] == 0)) { snprintf(rel, sizeof rel, "U:%s", host + ul); shown = rel; }
        else { snprintf(rel, sizeof rel, "?:%s", host); shown = rel; }
        printf("%ld %d %s\n", i, ex, shown);
#ifdef OVERLAY_API
        if (check_ov) {
            OvHit ov;
            char h2[1024];
            int e2 = map_path_ov(guest, h2, sizeof h2, &ov);
            if (ov.kind || e2 != ex || strcmp(h2, host)) { fprintf(stderr, "map_path_ov disagrees with map_path at %ld: '%s' ex %d/%d '%s' vs '%s' kind %d\n", i, guest, ex, e2, host, h2, ov.kind); mism++; }
        }
#else
        (void)check_ov;
#endif
    }
    (void)mism;
    fprintf(stderr, "map_path %ld paths done\n", n);
    return (int)(mism ? 1 : 0);
}
