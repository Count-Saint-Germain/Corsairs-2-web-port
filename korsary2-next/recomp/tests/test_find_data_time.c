/* Ф4.2 slot time metadata: find_next fills WIN32_FIND_DATAA FILETIMEs from real
   stat data on native/Node builds (and stays honestly zero on the browser
   WasmFS/OPFS build, whose backend does not persist times across reloads), and
   FileTimeToLocalFileTime/FileTimeToSystemTime convert safely. Runs with
   TZ=Europe/Warsaw so the winter/summer offsets are asserted exactly. */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

#if !defined(__EMSCRIPTEN__) || defined(PORT_NODE_BUILD)
#define HAVE_REAL_TIMES 1
#endif

static void args(CPU *c, uint32_t a0, uint32_t a1) {
    c->esp = 0x1000; W32(c->esp, 0xdeadbeef); W32(c->esp + 4, a0); W32(c->esp + 8, a1);
}
/* FILETIME for a known Unix second, bypassing the host helper so the browser
   build (which does not compile it) can still test the converters. */
static uint64_t ft_of_unix(time_t sec) { return (uint64_t)((int64_t)sec + 11644473600ll) * 10000000ull; }

int main(void) {
    g_mem = calloc(1, 65536); assert(g_mem);
    char dir[] = "/tmp/korsary-find-data-XXXXXX"; assert(mkdtemp(dir));
    char path[512]; snprintf(path, sizeof path, "%s/save.tmp", dir);
    int fd = open(path, O_CREAT | O_WRONLY, 0600); assert(fd >= 0);
    assert(write(fd, "s", 1) == 1); assert(close(fd) == 0);
    struct stat st; assert(stat(path, &st) == 0);

    /* find_next: name, size and, where stat is trustworthy, all three FILETIMEs */
    FindState fs = {0}; snprintf(fs.dir, sizeof fs.dir, "%s", dir);
    snprintf(fs.pattern, sizeof fs.pattern, "save.tmp"); fs.d = opendir(dir); assert(fs.d);
    uint32_t out = 0x2000;
    assert(find_next(&fs, out)); closedir(fs.d);
    assert(!strcmp((char *)HP(out + 44), "save.tmp"));
    assert(R32(out) == 0x80 && R32(out + 32) == 1);
#ifdef HAVE_REAL_TIMES
#if defined(__APPLE__)
    assert(R64(out + 4) == filetime_from_timespec(st.st_birthtimespec.tv_sec, st.st_birthtimespec.tv_nsec));
    assert(R64(out + 12) == filetime_from_timespec(st.st_atimespec.tv_sec, st.st_atimespec.tv_nsec));
    assert(R64(out + 20) == filetime_from_timespec(st.st_mtimespec.tv_sec, st.st_mtimespec.tv_nsec));
#else
    assert(R64(out + 4) == filetime_from_timespec(st.st_mtim.tv_sec, st.st_mtim.tv_nsec));
    assert(R64(out + 12) == filetime_from_timespec(st.st_atim.tv_sec, st.st_atim.tv_nsec));
    assert(R64(out + 20) == filetime_from_timespec(st.st_mtim.tv_sec, st.st_mtim.tv_nsec));
#endif
    assert(R64(out + 4) != 0 && R64(out + 20) != 0);
    /* helper guards: pre-1601 seconds and invalid nanoseconds are "unknown" */
    assert(filetime_from_timespec(-11644473601ll, 0) == 0);
    assert(filetime_from_timespec(0, 1000000000l) == 0);
    assert(filetime_from_timespec(1704067200, 123456700) == ft_of_unix(1704067200) + 123456700 / 100);
#else
    /* browser gate: times stay zero, the save list keeps today's stable 00:00 */
    assert(R64(out + 4) == 0 && R64(out + 12) == 0 && R64(out + 20) == 0);
#endif

    CPU c = {0}; tzset();
    /* FILETIME 0 (1601-01-01 UTC) converts, and unknown stays unknown locally */
    W64(0x4000, 0); args(&c, 0x4000, 0x4020); w_FileTimeToSystemTime(&c);
    assert(c.eax == 1);
    assert(R16(0x4020) == 1601 && R16(0x4022) == 1 && R16(0x4028) == 0 && R16(0x402a) == 0);
    args(&c, 0x4000, 0x4040); w_FileTimeToLocalFileTime(&c);
    assert(c.eax == 1 && R64(0x4040) == 0);   /* zero passes through unchanged, no TZ shift */

    /* Europe/Warsaw winter/summer: 2024-01-01 and 2024-07-01 00:00 UTC are 01:00 and 02:00 local */
    struct { time_t sec; unsigned month, hour; } cases[] = {
        { 1704067200, 1, 1 }, { 1719792000, 7, 2 },
    };
    for (unsigned i = 0; i < sizeof cases / sizeof cases[0]; i++) {
        W64(0x4000, ft_of_unix(cases[i].sec));
        args(&c, 0x4000, 0x4040); w_FileTimeToLocalFileTime(&c); assert(c.eax == 1);
        args(&c, 0x4040, 0x4020); w_FileTimeToSystemTime(&c); assert(c.eax == 1);
        assert(R16(0x4022) == cases[i].month && R16(0x4028) == cases[i].hour && R16(0x402e) == 0);
    }

    assert(unlink(path) == 0 && rmdir(dir) == 0);
    free(g_mem);
    puts("find_data FILETIMEs and DST-correct local time conversion: PASS");
    return 0;
}
