/* K1b (tools-dev/file-share-policy-diagnostic/K1B_CREATEFILE_AUDIT.md): the CreateFileA argument combinations the game really passes
   (found statically in ENGINE.exe and MODULES/*.dll), run against the actual kernel32.c handler in the default mode. For each
   combination: the Windows result (documentation of CreateFileA) and what the host returns. Differences that exist but are not
   reached by the game are printed as KNOWN-DIFF and are NOT a contract. Synthetic temp dir only; no game data.
   Usage: test [scratch-dir]. PORT_STRICT_FILE_SHARE must be unset (the default mode is the subject). */
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000;
int sched_active(void) { return 0; }
uint64_t sched_now_us(void) { return 0; }
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void)) { (void)pred; (void)arg; (void)deadline_us; (void)deadline_fn; return 0; }

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); abort(); } } while (0)
#define GR 0x80000000u
#define GW 0x40000000u
#define GRW 0xC0000000u
#define INVALID 0xffffffffu
enum { CREATE_NEW = 1, CREATE_ALWAYS, OPEN_EXISTING, OPEN_ALWAYS, TRUNCATE_EXISTING };
static GuestThread th;
static CPU cpu;
static char root[1024];
static uint32_t call(void (*fn)(CPU *), int n, const uint32_t *a) {
    t_self = &th; th.last_error = 0xdeadu;
    cpu.esp = 0x1000; W32(0x1000, 0);
    for (int i = 0; i < n; i++) W32(0x1004 + 4u * (uint32_t)i, a[i]);
    fn(&cpu);
    return cpu.eax;
}
/* the shape of every game call: (path, access, share, NULL, disposition, flags, NULL) */
static uint32_t cf(const char *name, uint32_t access, uint32_t share, uint32_t disp, uint32_t flags) {
    strcpy((char *)HP(0x2000), name);
    uint32_t a[7] = { 0x2000, access, share, 0, disp, flags, 0 };
    return call(w_CreateFileA, 7, a);
}
static uint32_t err(void) { return th.last_error; }
static void ch(uint32_t h) { uint32_t a[1] = { h }; CHECK(call(w_CloseHandle, 1, a) == 1); }
static uint32_t wr(uint32_t h, const char *s) { memcpy(HP(0x3000), s, strlen(s)); uint32_t a[5] = { h, 0x3000, (uint32_t)strlen(s), 0x2800, 0 }; return call(w_WriteFile, 5, a) ? R32(0x2800) : INVALID; }
static uint32_t rd(uint32_t h, char *out, uint32_t n) { uint32_t a[5] = { h, 0x4000, n, 0x2800, 0 }; if (!call(w_ReadFile, 5, a)) return INVALID; uint32_t g = R32(0x2800); memcpy(out, HP(0x4000), g); out[g] = 0; return g; }
static uint32_t seek_end(uint32_t h) { uint32_t a[4] = { h, 0, 0, 2 }; return call(w_SetFilePointer, 4, a); }
static void put(const char *name, const char *c) { char p[1300]; snprintf(p, sizeof p, "%s/%s", root, name); FILE *f = fopen(p, "wb"); CHECK(f && fputs(c, f) >= 0 && !fclose(f)); }
static void slurp(const char *name, char *out) { char p[1300]; snprintf(p, sizeof p, "%s/%s", root, name); FILE *f = fopen(p, "rb"); if (!f) { strcpy(out, "<absent>"); return; } size_t n = fread(out, 1, 255, f); out[n] = 0; fclose(f); }
static int exists(const char *name) { char p[1300]; struct stat st; snprintf(p, sizeof p, "%s/%s", root, name); return stat(p, &st) == 0; }
static void rm(const char *name) { char p[1300]; snprintf(p, sizeof p, "%s/%s", root, name); unlink(p); }
#define KNOWN(...) do { printf("KNOWN-DIFF "); printf(__VA_ARGS__); printf("\n"); } while (0)

int main(int argc, char **argv) {
    unsetenv("PORT_STRICT_FILE_SHARE");
    CHECK(!strict_share());
    g_mem = calloc(1, 0x10000); CHECK(g_mem);
    snprintf(root, sizeof root, "%s/korsary-gamecombos-XXXXXX", argc > 1 ? argv[1] : "/tmp");
    CHECK(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char b[256];

    /* L1  READ, share READ, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL: every data/ini/model/sound read (fio->_CreateFile sites of ENGINE,
           Animation, CameraDialog, DX8RENDER, GEOMETRY, ISLAND, sea, SoundService, Teleport, XINTERFACE) */
    put("data.bin", "0123456789");
    uint32_t h = cf("data.bin", GR, 1, OPEN_EXISTING, 0x80);
    CHECK(h != INVALID && rd(h, b, 4) == 4 && !strcmp(b, "0123")); ch(h);
    CHECK(cf("nosuch.bin", GR, 1, OPEN_EXISTING, 0x80) == INVALID && err() == 2 /* ERROR_FILE_NOT_FOUND */);
    CHECK(cf("DATA.BIN", GR, 1, OPEN_EXISTING, 0x80) != INVALID);          /* the game's paths differ in case from the files: matched like NTFS */
    CHECK(cf("sub\\..\\data.bin", GR, 1, OPEN_EXISTING, 0x80) != INVALID);  /* backslashes and .. as the game writes them */
    CHECK(cf("nodir\\x.bin", GR, 1, OPEN_EXISTING, 0x80) == INVALID);
    if (err() != 3) KNOWN("OPEN_EXISTING in a missing directory: Windows ERROR_PATH_NOT_FOUND(3), host %u (the game never reads the code: no GetLastError after fio->_CreateFile)", err());
    /* L2  WRITE, share READ, CREATE_ALWAYS: save game (ENGINE 0x4109e7), script natives, ifs, bump.zap, mem_utils */
    h = cf("save1", GW, 1, CREATE_ALWAYS, 0x80);
    CHECK(h != INVALID && err() == 0 && wr(h, "SAVE-A") == 6); ch(h);
    slurp("save1", b); CHECK(!strcmp(b, "SAVE-A"));
    h = cf("save1", GW, 1, CREATE_ALWAYS, 0x80);                            /* existing: truncated, success, ERROR_ALREADY_EXISTS (183) as Windows sets */
    CHECK(h != INVALID && err() == 183); slurp("save1", b); CHECK(!strcmp(b, "")); CHECK(wr(h, "B") == 1); ch(h);
    slurp("save1", b); CHECK(!strcmp(b, "B"));
    h = cf("newdir\\deep\\f.bin", GW, 1, CREATE_ALWAYS, 0x80);
    CHECK(h != INVALID);   /* Windows: ERROR_PATH_NOT_FOUND */
    KNOWN("CREATE_ALWAYS under a missing directory: Windows fails with ERROR_PATH_NOT_FOUND(3); the host creates the parents (kernel32.c: 'files the game writes'); the game's writers target existing folders");
    ch(h);
    /* L3  WRITE, share READ, OPEN_ALWAYS + SetFilePointer(END): the system.log idiom (ENGINE 0x44ab46), compile.log, error.log */
    h = cf("system.log", GW, 1, OPEN_ALWAYS, 0x80);
    CHECK(h != INVALID && err() == 0 && exists("system.log"));              /* created: no error */
    CHECK(seek_end(h) == 0 && wr(h, "line1\n") == 6); ch(h);
    h = cf("system.log", GW, 1, OPEN_ALWAYS, 0x80);
    CHECK(h != INVALID && err() == 183);                                    /* existing: opened, ERROR_ALREADY_EXISTS, content kept */
    CHECK(seek_end(h) == 6 && wr(h, "line2\n") == 6); ch(h);
    slurp("system.log", b); CHECK(!strcmp(b, "line1\nline2\n"));
    /* L4  WRITE, share READ, OPEN_EXISTING (ENGINE 0x4101e0: the save's extension data) */
    put("ext.sav", "HEADER-DATA");
    h = cf("ext.sav", GW, 1, OPEN_EXISTING, 0x80);
    CHECK(h != INVALID && wr(h, "XX") == 2); ch(h);
    slurp("ext.sav", b); CHECK(!strcmp(b, "XXADER-DATA"));
    CHECK(cf("absent.sav", GW, 1, OPEN_EXISTING, 0x80) == INVALID && err() == 2 && !exists("absent.sav"));   /* never creates */
    /* L5  share 0 variants: XINTERFACE text write/read, ENGINE 0x41a9fc (RDWR, CREATE_ALWAYS) */
    h = cf("text.dat", GW, 0, CREATE_ALWAYS, 0x80); CHECK(h != INVALID && wr(h, "TXT") == 3); ch(h);
    h = cf("text.dat", GR, 0, OPEN_EXISTING, 0x80); CHECK(h != INVALID && rd(h, b, 8) == 3 && !strcmp(b, "TXT")); ch(h);
    h = cf("rw.dat", GRW, 0, CREATE_ALWAYS, 0x80); CHECK(h != INVALID && wr(h, "RW") == 2); ch(h);
    /* L6  C runtime fopen of DX8RENDER/GEOMETRY/Lighter ("r+b", "aw", "w+b": _sopen: share READ|WRITE, FILE_ATTRIBUTE_NORMAL) */
    put("texLoad.txt", "T");
    h = cf("texLoad.txt", GRW, 3, OPEN_EXISTING, 0x80); CHECK(h != INVALID); ch(h);               /* "r+b" (texture_log=1 only) */
    h = cf("geoLoad.txt", GW, 3, OPEN_ALWAYS, 0x80); CHECK(h != INVALID && exists("geoLoad.txt")); ch(h);   /* "aw" (geometry_log=1 only) */
    put("lit.col", "OLD");
    h = cf("lit.col", GRW, 3, CREATE_ALWAYS, 0x80); CHECK(h != INVALID); slurp("lit.col", b); CHECK(!strcmp(b, "")); ch(h);   /* "w+b" (Lighter loading=1 only) */
    /* L7  flags: the game passes FILE_ATTRIBUTE_NORMAL (0x80) only, no FILE_FLAG_*; extra flags would be ignored, not rejected */
    h = cf("data.bin", GR, 1, OPEN_EXISTING, 0x80 | 0x08000000 /* FILE_FLAG_SEQUENTIAL_SCAN */); CHECK(h != INVALID); ch(h);

    /* not reached by the game: CREATE_NEW (one site: file-service method +0x64 at 0x42aa04, referenced only by its vtable) */
    rm("cn.bin");
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    CHECK(cf("cn.bin", GW, 0, CREATE_NEW, 0x80) == INVALID && err() == 50 /* ERROR_NOT_SUPPORTED */ && !exists("cn.bin"));
    puts("CREATE_NEW (browser build): refused with ERROR_NOT_SUPPORTED before any host open; the game does not call it");
#else
    h = cf("cn.bin", GW, 0, CREATE_NEW, 0x80); CHECK(h != INVALID && exists("cn.bin")); ch(h);
    CHECK(cf("cn.bin", GW, 0, CREATE_NEW, 0x80) == INVALID && err() == 80 /* ERROR_FILE_EXISTS */);
    puts("CREATE_NEW (native/Node build): creates, then ERROR_FILE_EXISTS on an existing name");
#endif
    /* not reached by the game: TRUNCATE_EXISTING (no site passes 5; fopen modes cannot produce it) */
    put("tr.bin", "ABCDEF");
    h = cf("tr.bin", GW, 1, TRUNCATE_EXISTING, 0x80); CHECK(h != INVALID); ch(h); slurp("tr.bin", b); CHECK(!strcmp(b, ""));
    CHECK(cf("tr.bin", GR, 1, TRUNCATE_EXISTING, 0x80) == INVALID && err() == 5);      /* needs GENERIC_WRITE, as Windows */

    /* differences that exist but are not reached */
    put("sh.bin", "S");
    uint32_t r1 = cf("sh.bin", GR, 1, OPEN_EXISTING, 0x80);
    uint32_t w1 = cf("sh.bin", GW, 1, OPEN_EXISTING, 0x80);
    CHECK(r1 != INVALID);
    if (w1 != INVALID) KNOWN("share mode is not enforced by default: a GENERIC_WRITE open next to a FILE_SHARE_READ reader succeeds (Windows: ERROR_SHARING_VIOLATION). No game call is shown to rely on a share conflict failing (static audit); PORT_STRICT_FILE_SHARE=1 enforces the Windows rule");
    if (w1 != INVALID) ch(w1);
    ch(r1);
    char dp[1300]; snprintf(dp, sizeof dp, "%s/adir", root); CHECK(!mkdir(dp, 0755));
    uint32_t dh = cf("adir", GR, 1, OPEN_EXISTING, 0x80);
    if (dh != INVALID) { KNOWN("CreateFileA on a directory returns a handle (Windows: ERROR_ACCESS_DENIED without FILE_FLAG_BACKUP_SEMANTICS); no game call passes a directory"); ch(dh); }
    rmdir(dp);
    CHECK(cf("data.bin", GR, 1, 0, 0x80) == INVALID && err() == 87 && cf("data.bin", GR, 1, 6, 0x80) == INVALID && err() == 87);   /* invalid disposition: ERROR_INVALID_PARAMETER */
    {   /* leave the scratch dir empty */
        static const char *left[] = { "data.bin", "save1", "system.log", "ext.sav", "text.dat", "rw.dat", "texLoad.txt", "geoLoad.txt", "lit.col", "cn.bin", "tr.bin", "sh.bin", "newdir/deep/f.bin" };
        for (size_t i = 0; i < sizeof left / sizeof *left; i++) rm(left[i]);
        char p[1300]; snprintf(p, sizeof p, "%s/newdir/deep", root); rmdir(p); snprintf(p, sizeof p, "%s/newdir", root); rmdir(p); rmdir(root);
    }
    puts("K1b CreateFileA combinations of the game (read OPEN_EXISTING; write CREATE_ALWAYS / OPEN_ALWAYS / OPEN_EXISTING; share 0; fopen modes; flags) match Windows for the return value and ERROR_ALREADY_EXISTS: PASS");
    free(g_mem);
    return 0;
}
