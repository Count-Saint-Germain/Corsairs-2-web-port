/* Video bridge (browser builds only).
 *
 * Where a video request is observable (RE, video-bridge-review/RE_VERDICT.md): StartPostVideo is NOT a
 * native function and it is NOT missing. It is a script function of PROGRAM/INTERFACE/interface.c
 * (StartPostVideo -> event evntPostVideo -> stPostVideo -> StartVideo), part of the main program, and every
 * video of the game goes through StartVideo(), which creates the engine entity "CAviPlayer"
 * (XINTERFACE.dll) and sends it MSG_SET_VIDEO_PLAY (49000) with the file name. The entity's ProcessMessage
 * builds "resource\videos\<name>.wmv" and calls its open routine (guest 0xae77d0); that routine's first act is
 * MultiByteToWideChar(0, 0, path, -1, buf, 0x104), whose return address is 0xae77fd. In this port DirectDraw
 * and DirectShow do not exist, so the open fails, the entity posts "ievntEndVideo" and the script carries on
 * (that is why every run logs three "Video Error!!! Can`t create DirectDraw interface" lines: the three
 * logo videos). That call is the one place where the real video name is visible, in every request, so
 * runtime.c forwards it here (port_video_open_site).
 *
 * The earlier hook sat on ExecuteFunction's "Invalid function: %s" trace (0x40a3cf, 0x40b977, 0x40a456) in the
 * belief that StartPostVideo is a missing native; it never fires for StartPostVideo. Those sites are still
 * forwarded to port_video_call_site, which now only LOGS what the VM traces there (diagnostic, no request).
 *
 * Wait semantics. The script expects the video to be modal: after it ends, "EndVideoPlay" continues the game
 * (main menu, the next logo, a quest step). If the page plays the file while the game already moved on, the
 * quest step / menu fires under the overlay. So while a live page is polling, the game thread parks inside the
 * open call until the page answers (port_video_done), and then the engine's normal failure path runs and posts
 * the end event exactly as it always did. Fail-open on every doubt: no page poller seen within a second (old
 * page, hidden tab, startup), page did not claim the request within port_video_claim_ms, or the hard cap
 * passed -> the game goes on at once, as without the bridge. PORT_NO_VIDEO disables everything, PORT_VIDEO_NOWAIT
 * publishes the request without a live-poller check and never parks the game, PORT_DETERMINISTIC (lockstep)
 * never bridges. The page plays the
 * MP4 through recomp/web/video-player.mjs and answers through port_video_done(). */
#include "runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
#include <emscripten.h>
#define VIDEO_EXPORT EMSCRIPTEN_KEEPALIVE   /* called by the page (video-player.mjs) */
#else
#define VIDEO_EXPORT
#endif

/* Guest addresses (translated code, ENGINE.exe / XINTERFACE.dll at 0xab0000 + RVA). */
enum {
    /* the real video site: return address of the MultiByteToWideChar call in CAviPlayer's open routine */
    AVI_OPEN_MBTOWC_RETURN = 0x00ae77fdu,
    /* ExecuteFunction's unknown-function traces (diagnostic only, see above) */
    VM_TRACE_INVALID_FUNCTION = 0x0040a3cfu,  /* "Invalid function: %s"    (fmt 0x46030c) */
    VM_TRACE_NOT_FOUND = 0x0040b977u,         /* "function '%s' not found" (fmt 0x460700) */
    VM_TRACE_IS_IMPORTED = 0x0040a456u,       /* "Function (%s) is imported" (fmt 0x46035c) */
};
/* The trace call pushes (this, fmt, name), so the arguments sit above the return address. */
#define VM_TRACE_FMT(c) R32((c)->esp + 8u)
#define VM_TRACE_NAME(c) R32((c)->esp + 0xcu)

#define VIDEO_NAME_CAP 64
#define AVI_PATH_CAP 260   /* the open routine converts at most 0x104 characters */

VIDEO_EXPORT void port_video_done(int code);

/* Pending request state. The game thread writes, the page thread reads: the length doubles as the
 * flag, published with release and consumed with acquire (the buffer itself is stable while set). */
static char g_video_name[VIDEO_NAME_CAP];            /* lowercase base name of the video, e.g. "trailer" */
static volatile int g_video_len;                     /* 0 = idle, >0 = name length */
static volatile int g_video_claimed;                 /* the page has read the request (poll with a buffer) */
static volatile int64_t g_last_poll_ms;              /* last port_video_poll call by the page (0 = never) */
/* Non-static so the native test can shrink them instead of sleeping. */
int64_t port_video_pending_ms = 15000;   /* an unclaimed request disappears after this (page never polls) */
int64_t port_video_claim_ms = 2000;      /* the parked game gives up on a page that does not claim within this */
int64_t port_video_max_ms = 600000;      /* hard cap from claim to answer (longest video is ~100 s) */
int64_t port_video_alive_ms = 1500;      /* park the game only if the page polled this recently */
static volatile int64_t g_video_deadline_ms;       /* both threads: read/written with atomics */
#define DEADLINE() __atomic_load_n(&g_video_deadline_ms, __ATOMIC_ACQUIRE)
#define SET_DEADLINE(v) __atomic_store_n(&g_video_deadline_ms, (v), __ATOMIC_RELEASE)

static int64_t now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

/* Bounds check for guest reads: [a, a + n) inside the guest address space. */
static int guest_range(uint64_t a, uint64_t n) { return a + n <= GUEST_SPACE; }

/* ExecuteFunction (0x40a301) frame, derived from its translation AND cross-checked against the ENGINE.exe
 * disassembly: [ebp+8] = function code (index into the VM's function table), [ebp-0x10c] = this; the table
 * header sits at this+0x8f8 (capacity at +0, count at +4, array of 0x48-byte FUNCINFO entries at +8; see
 * f_004473cf at 0x4473cf, which bounds-checks against +4 and copies 0x12 dwords) and an entry's name pointer
 * is at +0xc (the registration routine f_0044749f strcmps it, f_0040a301 passes the dword at info+0xc as the
 * %s argument). Used only to show, in the diagnostic log, which entry a refused lookup was about; returns 0
 * when anything is out of range. */
static uint32_t table_entry_name(const CPU *c) {
    uint32_t ebp = c->ebp;
    if (ebp < 0x10cu || !guest_range((uint64_t)ebp + 12u, 0)) return 0;
    uint32_t code = R32(ebp + 8u), self = R32(ebp - 0x10cu);
    if (!self || !guest_range((uint64_t)self + 0x8f8u + 12u, 0)) return 0;
    uint32_t count = R32(self + 0x8f8u + 4u), base = R32(self + 0x8f8u + 8u);
    if (code >= count || !base) return 0;
    uint64_t entry = (uint64_t)base + (uint64_t)code * 0x48u;
    if (!guest_range(entry + 0xcu, 4)) return 0;
    return R32((uint32_t)entry + 0xcu);
}

static int g_site_logs;   /* trace-site observations logged so far (bounded: other unknown functions hit these sites too) */

/* runtime.c calls this for every indirect call returning to one of ExecuteFunction's unknown-function trace
 * sites. Diagnostic only: StartPostVideo is a script function and never reaches them (RE_VERDICT.md); a line
 * here in a live log means some function the script called was refused, with the name as the VM saw it. */
void port_video_call_site(const CPU *c) {
    if (getenv("PORT_NO_VIDEO")) return;
    uint32_t ra = R32(c->esp), fmt = VM_TRACE_FMT(c), name = VM_TRACE_NAME(c);
    if (fmt != 0x0046030cu && fmt != 0x00460700u && fmt != 0x0046035cu) return;
    if (g_site_logs >= 16) return;
    g_site_logs++;
    uint32_t table_name = (ra == VM_TRACE_INVALID_FUNCTION || ra == VM_TRACE_IS_IMPORTED) ? table_entry_name(c) : 0;
    char shown[24] = "";
    uint32_t src = name ? name : table_name;
    if (src && guest_range(src, sizeof shown - 1)) {
        memcpy(shown, HP(src), sizeof shown - 1);
        shown[sizeof shown - 1] = 0;
        for (char *p = shown; *p; p++) if ((unsigned char)*p < 32 || (unsigned char)*p > 126) *p = '?';
    }
    fprintf(stderr, "[video] VM trace site %08x: name arg %08x, table name %08x ('%s')\n", ra, name, table_name, shown);
}

/* "resource\videos\Trailer.wmv" -> "trailer". Lowercase (the script spells the same video several ways,
 * the files are matched case-insensitively on Windows), extension dropped, only plain file-name characters
 * accepted. Returns the length, 0 if the path is not a video file name. */
static int video_base_name(const char *path, size_t n, char *out, size_t cap) {
    size_t b = 0, e = n;
    for (size_t i = 0; i < n; i++) if (path[i] == '\\' || path[i] == '/') b = i + 1;
    for (size_t i = e; i > b; i--) if (path[i - 1] == '.') { e = i - 1; break; }
    if (e <= b || e - b >= cap) return 0;
    for (size_t i = b; i < e; i++) {
        char ch = path[i];
        if (ch >= 'A' && ch <= 'Z') ch = (char)(ch - 'A' + 'a');
        if (!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '_' || ch == '-' || ch == ' ')) return 0;
        out[i - b] = ch;
    }
    out[e - b] = 0;
    return (int)(e - b);
}

static int g_open_logs;

/* The page has a live poller: it called port_video_poll within port_video_alive_ms. */
static int page_alive(int64_t t) {
    int64_t last = __atomic_load_n(&g_last_poll_ms, __ATOMIC_ACQUIRE);
    return last && t - last <= port_video_alive_ms;
}

/* Park the game thread until the page answers (len back to 0) or a fail-open condition holds. */
static void wait_for_page(int64_t t0) {
    fprintf(stderr, "[video] game waits for the page\n");
    for (;;) {
        if (!__atomic_load_n(&g_video_len, __ATOMIC_ACQUIRE)) {
            fprintf(stderr, "[video] page answered after %lld ms; game continues\n", (long long)(now_ms() - t0));
            return;
        }
        int64_t t = now_ms();
        if (!__atomic_load_n(&g_video_claimed, __ATOMIC_ACQUIRE) && t - t0 >= port_video_claim_ms) {
            fprintf(stderr, "[video] page did not claim the request in %lld ms; game continues (fail-open)\n", (long long)port_video_claim_ms);
            port_video_done(1);
            return;
        }
        if (t >= DEADLINE() && __atomic_load_n(&g_video_len, __ATOMIC_ACQUIRE)) {
            fprintf(stderr, "[video] no answer from the page before the deadline; game continues (fail-open)\n");
            port_video_done(1);
            return;
        }
        struct timespec ts = { 0, 2 * 1000 * 1000 };
        nanosleep(&ts, NULL);
    }
}

/* runtime.c calls this for the indirect call that returns to 0xae77fd, i.e. MultiByteToWideChar inside
 * CAviPlayer's open routine; the hot path in runtime.c only compares the return address. The five fixed
 * arguments of that call (CP_ACP, 0, path, -1, buf, 0x104) double as the check that this really is it. */
void port_video_open_site(const CPU *c) {
    if (getenv("PORT_NO_VIDEO") || getenv("PORT_DETERMINISTIC")) return;
    uint64_t sp = c->esp;
    if (!guest_range(sp, 0x1cu) || R32(sp) != AVI_OPEN_MBTOWC_RETURN) return;
    if (R32(sp + 4) != 0 || R32(sp + 8) != 0 || R32(sp + 0x10) != 0xffffffffu || R32(sp + 0x18) != 0x104u) return;
    uint32_t path = R32(sp + 0xc);
    if (!path || !guest_range(path, 1)) return;
    char buf[AVI_PATH_CAP + 1];
    size_t n = 0;
    while (n < AVI_PATH_CAP && guest_range((uint64_t)path + n, 1) && HP(path)[n]) { buf[n] = (char)HP(path)[n]; n++; }
    buf[n] = 0;
    char name[VIDEO_NAME_CAP];
    int len = video_base_name(buf, n, name, sizeof name);
    if (g_open_logs < 32) {
        g_open_logs++;
        char shown[64];
        snprintf(shown, sizeof shown, "%.60s", buf);
        for (char *p = shown; *p; p++) if ((unsigned char)*p < 32 || (unsigned char)*p > 126) *p = '?';
        fprintf(stderr, "[video] CAviPlayer open: '%s' -> request '%s'\n", shown, len ? name : "(not a video name)");
    }
    if (!len) return;
    int64_t t = now_ms();
    if (__atomic_load_n(&g_video_len, __ATOMIC_ACQUIRE)) {
        if (t < DEADLINE()) {
            fprintf(stderr, "[video] request while one is pending; ignored (fail-open)\n");
            return;   /* exactly one active request: drop the new one, the game continues regardless */
        }
        port_video_done(1);   /* the previous one outlived its deadline: its page is gone */
    }
    int nowait = getenv("PORT_VIDEO_NOWAIT") != NULL;
    if (!nowait && !page_alive(t)) {
        /* old page, hidden tab (no animation frames), startup: nobody would answer, so do not even ask */
        fprintf(stderr, "[video] page is not polling; no request, game continues (fail-open)\n");
        return;
    }
    memcpy(g_video_name, name, (size_t)len + 1);
    SET_DEADLINE(t + port_video_pending_ms);
    __atomic_store_n(&g_video_claimed, 0, __ATOMIC_RELEASE);
    __atomic_store_n(&g_video_len, len, __ATOMIC_RELEASE);
    if (!nowait) wait_for_page(t);
}

/* Page poll: 0 = nothing pending; otherwise the name length (the buffer holds the NUL-terminated name,
 * truncated when cap is small). out == NULL / cap <= 0 queries without copying and without claiming. */
VIDEO_EXPORT int port_video_poll(char *out, int cap) {
    int64_t t = now_ms();
    __atomic_store_n(&g_last_poll_ms, t, __ATOMIC_RELEASE);
    int len = __atomic_load_n(&g_video_len, __ATOMIC_ACQUIRE);
    if (!len) return 0;
    if (t >= DEADLINE()) {
        fprintf(stderr, "[video] pending request expired\n");
        port_video_done(1);
        return 0;
    }
    if (out && cap > 0) {
        int n = len < cap - 1 ? len : cap - 1;
        memcpy(out, g_video_name, (size_t)n);
        out[n] = 0;
        if (!g_video_claimed) {
            SET_DEADLINE(t + port_video_max_ms);   /* claimed: the page now owns the timing */
            __atomic_store_n(&g_video_claimed, 1, __ATOMIC_RELEASE);
        }
    }
    return len;
}

/* Page answer: 0 = played to the end, 1 = error/skip/unknown video; either way the game carries on
 * exactly as it does today without the bridge (the engine's open already fails and ends the video). */
VIDEO_EXPORT void port_video_done(int code) {
    (void)code;
    SET_DEADLINE(0);
    __atomic_store_n(&g_video_claimed, 0, __ATOMIC_RELEASE);
    __atomic_store_n(&g_video_len, 0, __ATOMIC_RELEASE);
}

/* Address of the name buffer for the page (it cannot allocate guest memory itself). */
VIDEO_EXPORT char *port_video_name_buf(void) {
    return g_video_name;
}
