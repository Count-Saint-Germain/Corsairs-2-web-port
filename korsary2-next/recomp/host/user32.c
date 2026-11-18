/* USER32.DLL: windows, messages, input state. For now there is one virtual window; a real host
 * window (and real input) arrives with the renderer. */
#include "win32.h"

#include <pthread.h>
#include <limits.h>
#include <math.h>
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
#include <emscripten.h>
/* The browser owns the window and its page-lifetime save locks. Ask the page
 * to navigate away rather than recursively dispatching the guest's WM_CLOSE. */
static int g_browser_close_requested;
EMSCRIPTEN_KEEPALIVE int port_take_close_request(void) {
    return __atomic_exchange_n(&g_browser_close_requested, 0, __ATOMIC_ACQ_REL);
}
#endif

#define W(name) static void w_##name(CPU *c)

int g_screen_w = 1024, g_screen_h = 768;  /* 4:3, matching the game's 640x480 HUD layout */

static uint32_t g_wndproc;       /* guest WNDPROC of the registered class */
static uint32_t g_window_created;
static uint32_t g_hook_proc;

/* Calls a guest stdcall function from host code on the current thread's CPU. */
uint32_t guest_stdcall(CPU *c, uint32_t fn, int nargs, const uint32_t *args) {
    uint32_t sp = c->esp;
    for (int i = nargs - 1; i >= 0; i--) PUSH32(c, args[i]);
    PUSH32(c, GUEST_RETURN_SENTINEL);
    call_indirect(c, fn);
    if (c->esp != sp) {
        LOG("[user32] callback %08x left esp off by %d\n", fn, (int)(c->esp - sp));
        c->esp = sp;
    }
    return c->eax;
}

static uint32_t send_to_wndproc(CPU *c, uint32_t hwnd, uint32_t msg, uint32_t wp, uint32_t lp) {
    if (!g_wndproc) return 0;
    uint32_t a[4] = { hwnd, msg, wp, lp };
    return guest_stdcall(c, g_wndproc, 4, a);
}

/* ------------------------------------------------------------------ message queue */

typedef struct { uint32_t hwnd, msg, wp, lp; } Msg;
static Msg g_queue[256];
static int g_qhead, g_qtail;
static pthread_mutex_t g_qlock = PTHREAD_MUTEX_INITIALIZER;

void post_message(uint32_t hwnd, uint32_t msg, uint32_t wp, uint32_t lp) {
    pthread_mutex_lock(&g_qlock);
    int next = (g_qtail + 1) % 256;
    if (next != g_qhead) { g_queue[g_qtail] = (Msg){ hwnd, msg, wp, lp }; g_qtail = next; }
    pthread_mutex_unlock(&g_qlock);
}

static int pop_message(Msg *m, int remove) {
    pthread_mutex_lock(&g_qlock);
    int have = g_qhead != g_qtail;
    if (have) { *m = g_queue[g_qhead]; if (remove) g_qhead = (g_qhead + 1) % 256; }
    pthread_mutex_unlock(&g_qlock);
    return have;
}

void (*g_pump_host_events)(void);  /* set by the window backend */

static void write_msg(uint32_t p, const Msg *m) {
    W32(p, m->hwnd); W32(p + 4, m->msg); W32(p + 8, m->wp); W32(p + 12, m->lp);
    W32(p + 16, (uint32_t)(guest_seconds() * 1000)); W32(p + 20, 0); W32(p + 24, 0);
}

W(PeekMessageA) {
    if (g_pump_host_events) g_pump_host_events();
    Msg m;
    if (!pop_message(&m, ARG(4) & 1 /* PM_REMOVE */)) RET(5, 0);
    write_msg(ARG(0), &m);
    RET(5, 1);
}
W(GetMessageA) {
    Msg m;
    while (!pop_message(&m, 1)) {
        if (g_pump_host_events) g_pump_host_events();
        if (sched_active()) { sched_wait(NULL, NULL, sched_now_us() + 2000, NULL); continue; }
        struct timespec ts = { 0, 2000000 };
        nanosleep(&ts, NULL);
    }
    write_msg(ARG(0), &m);
    RET(4, m.msg != 0x12 /* WM_QUIT */);
}
W(TranslateMessage) { RET(1, 0); }
W(DispatchMessageA) {
    uint32_t p = ARG(0);
    uint32_t r = send_to_wndproc(c, R32(p), R32(p + 4), R32(p + 8), R32(p + 12));
    RET(1, r);
}
W(PostMessageA) { post_message(ARG(0), ARG(1), ARG(2), ARG(3)); RET(4, 1); }
W(SendMessageA) {
    LOG("[user32] SendMessageA(msg %x)\n", ARG(1));
    if (ARG(1) == 0x80 /* WM_SETICON */) RET(4, 0);
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    if (ARG(0) == MAIN_HWND && ARG(1) == 0x10 /* WM_CLOSE */) {
        __atomic_store_n(&g_browser_close_requested, 1, __ATOMIC_RELEASE);
        RET(4, 0);
    }
#endif
    uint32_t r = send_to_wndproc(c, ARG(0), ARG(1), ARG(2), ARG(3));
    RET(4, r);
}
W(SendNotifyMessageA) { post_message(ARG(0), ARG(1), ARG(2), ARG(3)); RET(4, 1); }
W(PostQuitMessage) { post_message(MAIN_HWND, 0x12, ARG(0), 0); RET(1, 0); }
W(DefWindowProcA) { RET(4, 0); }

/* ------------------------------------------------------------------ window */

W(RegisterClassA) {
    g_wndproc = R32(ARG(0) + 4);  /* WNDCLASSA.lpfnWndProc */
    LOG("[user32] RegisterClassA(%s) wndproc=%08x\n", GSTR(R32(ARG(0) + 36)), g_wndproc);
    RET(1, 0xC001);
}
W(RegisterClassExA) {
    g_wndproc = R32(ARG(0) + 8);  /* WNDCLASSEXA.lpfnWndProc */
    LOG("[user32] RegisterClassExA wndproc=%08x\n", g_wndproc);
    RET(1, 0xC001);
}
W(UnregisterClassA) { RET(2, 1); }

W(CreateWindowExA) {
    LOG("[user32] CreateWindowExA(class %s, title %s, %dx%d)\n", ARG(1) > 0xffff ? GSTR(ARG(1)) : "#atom",
        ARG(2) ? GSTR(ARG(2)) : "", (int)ARG(6), (int)ARG(7));
    g_window_created = 1;
    /* Deliver the creation messages a real window would get. */
    uint32_t cs = heap_alloc(48, 1);  /* CREATESTRUCTA */
    W32(cs + 28, ARG(6)); W32(cs + 24, ARG(7)); W32(cs + 36, ARG(2)); W32(cs + 40, ARG(1)); W32(cs + 44, ARG(0));
    send_to_wndproc(c, MAIN_HWND, 0x81 /* WM_NCCREATE */, 0, cs);
    send_to_wndproc(c, MAIN_HWND, 0x01 /* WM_CREATE */, 0, cs);
    RET(12, MAIN_HWND);
}
W(DestroyWindow) { RET(1, 1); }
W(ShowWindow) {
    if (ARG(1)) {
        send_to_wndproc(c, MAIN_HWND, 0x18 /* WM_SHOWWINDOW */, 1, 0);
        send_to_wndproc(c, MAIN_HWND, 0x06 /* WM_ACTIVATE */, 1, 0);
        send_to_wndproc(c, MAIN_HWND, 0x07 /* WM_SETFOCUS */, 0, 0);
    }
    RET(2, 0);
}
W(UpdateWindow) { RET(1, 1); }
W(MoveWindow) { RET(6, 1); }
W(SetWindowPos) { RET(7, 1); }
W(SetWindowTextA) { LOG("[user32] SetWindowTextA(%s)\n", GSTR(ARG(1))); RET(2, 1); }
W(GetWindowLongA) {
    int32_t idx = (int32_t)ARG(1);
    RET(2, idx == -16 /* GWL_STYLE */ ? 0x10CF0000u : idx == -4 /* GWL_WNDPROC */ ? g_wndproc : 0);
}
W(FindWindowA) { RET(2, 0); }  /* no other instance running */
W(GetDesktopWindow) { RET(0, 0x00010001u); }
W(GetForegroundWindow) { RET(0, MAIN_HWND); }
W(SetForegroundWindow) { RET(1, 1); }
W(SetActiveWindow) { RET(1, MAIN_HWND); }
W(SetFocus) { RET(1, MAIN_HWND); }
W(IsIconic) { RET(1, 0); }
W(GetClientRect) {
    uint32_t r = ARG(1);
    W32(r, 0); W32(r + 4, 0); W32(r + 8, (uint32_t)g_screen_w); W32(r + 12, (uint32_t)g_screen_h);
    RET(2, 1);
}
W(AdjustWindowRect) { RET(3, 1); }
W(GetWindowRect) {
    uint32_t r = ARG(1);
    W32(r, 0); W32(r + 4, 0); W32(r + 8, (uint32_t)g_screen_w); W32(r + 12, (uint32_t)g_screen_h);
    RET(2, 1);
}

/* wsprintfA: formats straight off the guest stack (fixed args: buf, fmt, then varargs). Like the
   real one, no float support; width/precision only for numbers and %s. */
static uint32_t ws_vformat(char *out, uint32_t fmt_addr, uint32_t args_base) {
    const char *f = GSTR(fmt_addr);
    uint32_t n = 0, argi = 0;
    for (const char *p = f; *p && n < 0x7fff; p++) {
        if (*p != '%') { out[n++] = *p; continue; }
        p++;
        char pad = ' ';
        if (*p == '0') { pad = '0'; p++; }
        int width = 0;
        while (*p >= '0' && *p <= '9') { width = width * 10 + (*p - '0'); p++; }
        int prec = -1;
        if (*p == '.') { prec = 0; p++; while (*p >= '0' && *p <= '9') { prec = prec * 10 + (*p - '0'); p++; } }
        uint32_t a = R32(args_base + 4 * argi++);
        char tmp[32];
        int tl = 0;
        switch (*p) {
        case 'd': case 'i': {
            int32_t v = (int32_t)a;
            uint32_t m = v < 0 ? (uint32_t)-(int64_t)v : (uint32_t)v;
            do { tmp[tl++] = '0' + m % 10; m /= 10; } while (m);
            if (v < 0) tmp[tl++] = '-';
            break;
        }
        case 'u': {
            do { tmp[tl++] = '0' + a % 10; a /= 10; } while (a);
            break;
        }
        case 'x': case 'X': {
            const char *d = *p == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
            do { tmp[tl++] = d[a & 15]; a >>= 4; } while (a);
            break;
        }
        case 'c':
            out[n++] = (char)a;
            continue;
        case 's': {
            const char *sv = a ? GSTR(a) : "(null)";
            int lim = prec >= 0 ? prec : 0x7fff;
            while (*sv && lim-- > 0 && n < 0x7fff) out[n++] = *sv++;
            continue;
        }
        case '%':
            out[n++] = '%';
            continue;
        case 0:
            p--;
            continue;
        default:  /* unknown conversion: emit it verbatim */
            out[n++] = '%';
            out[n++] = *p;
            continue;
        }
        for (int k = 0; k < width - tl && n < 0x7fff; k++) out[n++] = pad;
        while (tl > 0 && n < 0x7fff) out[n++] = tmp[--tl];
    }
    out[n] = 0;
    return n;
}
W(wsprintfA) { RET_CDECL(ws_vformat((char *)HP(ARG(0)), ARG(1), c->esp + 4 + 8)); }

W(ClipCursor) { RET(1, 1); }
W(LoadBitmapA) { RET(3, 0x00050010u); }
W(GetDC) { RET(1, 0x00070001u); }
W(ReleaseDC) { RET(2, 1); }
W(FillRect) { RET(2, 1); }
W(InvalidateRect) { RET(2, 1); }
W(OffsetRect) {
    uint32_t r = ARG(0);
    int32_t dx = (int32_t)ARG(1), dy = (int32_t)ARG(2);
    W32(r, R32(r) + dx); W32(r + 4, R32(r + 4) + dy);
    W32(r + 8, R32(r + 8) + dx); W32(r + 12, R32(r + 12) + dy);
    RET(3, 1);
}
/* the debug build's menu / clipboard / rich-text UI: plausible returns keep it harmless when reached */
W(GetMenu) { RET(1, 0); }
W(GetMenuItemCount) { RET(1, (uint32_t)-1); }
W(GetSubMenu) { RET(2, 0); }
W(GetMenuItemID) { RET(3, (uint32_t)-1); }
W(GetMenuItemInfoA) { RET(3, 0); }
W(InsertMenuItemA) { RET(2, 1); }
W(SetMenuItemInfoA) { RET(3, 1); }
W(CheckMenuItem) { RET(3, 0); }
W(DestroyMenu) { RET(1, 1); }
W(SetScrollInfo) { RET(3, R32(ARG(2) + 12)); }
W(TabbedTextOutA) { RET(8, 0); }
W(GetTabbedTextExtentA) { RET(8, 0x00100008u); }  /* 8 px wide, 16 px tall */
W(OpenClipboard) { RET(1, 1); }
W(CloseClipboard) { RET(1, 1); }
W(EmptyClipboard) { RET(1, 1); }
W(SetClipboardData) { RET(2, 0x00090001u); }
W(AdjustWindowRectEx) { RET(4, 1); }
W(ClientToScreen) { RET(2, 1); }
W(ScreenToClient) { RET(2, 1); }
W(SetRect) {
    uint32_t r = ARG(0);
    W32(r, ARG(1)); W32(r + 4, ARG(2)); W32(r + 8, ARG(3)); W32(r + 12, ARG(4));
    RET(5, 1);
}
W(BeginPaint) { memset(HP(ARG(1)), 0, 64); RET(2, 0x00020001u); }
W(EndPaint) { RET(2, 1); }
W(GetSystemMetrics) {
    switch (ARG(0)) {
    case 0: RET(1, g_screen_w);      /* SM_CXSCREEN */
    case 1: RET(1, g_screen_h);      /* SM_CYSCREEN */
    case 4: RET(1, 19);              /* SM_CYCAPTION */
    case 5: case 6: RET(1, 1);       /* borders */
    case 32: case 33: RET(1, 4);     /* SM_CXFRAME / SM_CYFRAME */
    default: RET(1, 0);
    }
}
W(SystemParametersInfoA) { RET(4, 1); }
W(MessageBoxA) {
    fprintf(stderr, "[MessageBox] %s: %s\n", ARG(2) ? GSTR(ARG(2)) : "", ARG(1) ? GSTR(ARG(1)) : "");
    RET(4, 1 /* IDOK */);
}

/* ------------------------------------------------------------------ cursor, icons */

W(LoadCursorA) { RET(2, 0x00030001u); }
W(LoadIconA) { RET(2, 0x00030002u); }
W(LoadImageA) { RET(6, 0x00030003u); }
W(DestroyIcon) { RET(1, 1); }
W(SetCursor) { RET(1, 0); }
W(ShowCursor) { RET(1, ARG(0) ? 0 : -1); }
static int32_t g_mouse_x = 512, g_mouse_y = 384;
static pthread_mutex_t g_cursor_lock = PTHREAD_MUTEX_INITIALIZER;
/* The PCS_CONTROLS Update routine (rebased to 0x00891910) reads the
   cursor then centers it again. Only the calls in this pair consume motion. */
enum { PCS_CURSOR_READ = 0x00891929u, PCS_CURSOR_RECENTER = 0x008919c6u };
static int32_t cursor_add(int32_t value, int delta) {
    int64_t result=(int64_t)value+(int64_t)delta;
    return result > INT32_MAX ? INT32_MAX : result < INT32_MIN ? INT32_MIN : (int32_t)result;
}
void user32_mouse_move(int dx,int dy) {
    pthread_mutex_lock(&g_cursor_lock);
    g_mouse_x=cursor_add(g_mouse_x,dx); g_mouse_y=cursor_add(g_mouse_y,dy);
    pthread_mutex_unlock(&g_cursor_lock);
}
W(GetCursorPos) {
    pthread_mutex_lock(&g_cursor_lock);
    uint32_t x=(uint32_t)g_mouse_x,y=(uint32_t)g_mouse_y;
    if (R32(c->esp) == PCS_CURSOR_READ) {
        /* Consume at the read, so events arriving before the paired reset
           remain available for the next poll. GetWindowRect is origin-based. */
        g_mouse_x = g_screen_w / 2;
        g_mouse_y = g_screen_h / 2;
    }
    pthread_mutex_unlock(&g_cursor_lock);
    W32(ARG(0),x); W32(ARG(0)+4,y); RET(1,1);
}
W(SetCursorPos) {
    int32_t x = (int32_t)ARG(0), y = (int32_t)ARG(1);
    if (R32(c->esp) == PCS_CURSOR_RECENTER && x == g_screen_w / 2 && y == g_screen_h / 2) RET(2, 1);
    pthread_mutex_lock(&g_cursor_lock);
    g_mouse_x = x;
    g_mouse_y = y;
    pthread_mutex_unlock(&g_cursor_lock);
    RET(2,1);
}

#ifndef PORT_NODE_BUILD
static float g_menu_mouse_x = -1.f, g_menu_mouse_y = -1.f;
static double g_menu_mouse_update_at = -1.0;

int netplay_on(void);
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
int port_menu_mouse_active(void) {
    double now = host_seconds();
    pthread_mutex_lock(&g_cursor_lock);
    double last = g_menu_mouse_update_at;
    pthread_mutex_unlock(&g_cursor_lock);
    /* Allow for slow loading frames without treating an old menu as active. */
    return last >= 0.0 && now >= last && now - last < 0.6;
}
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void input_mouse_position(float x, float y) {
    if (netplay_on()) return;
    pthread_mutex_lock(&g_cursor_lock);
    g_menu_mouse_x = x;
    g_menu_mouse_y = y;
    pthread_mutex_unlock(&g_cursor_lock);
}

/* XINTERFACE's cursor update at guest 0x00ae2340 reads ITurnV and ITurnH
   into adjacent control-state structures before updating the cursor quad
   and hit testing. Replace those two deltas when the page has a position.
   Outside this call site, mouse movement still comes from relative input. */
void port_menu_mouse_control(CPU *c, uint32_t result) {
    uint32_t self = c->esi;
    if (result != c->esp + 0x20u || !self || (uint64_t)self + 0xc4u > GUEST_SPACE ||
        (uint64_t)c->esp + 0x2cu > GUEST_SPACE) return;

    pthread_mutex_lock(&g_cursor_lock);
    g_menu_mouse_update_at = host_seconds();
    float x = g_menu_mouse_x, y = g_menu_mouse_y;
    pthread_mutex_unlock(&g_cursor_lock);
    if (!(x >= 0.f && x <= 1.f && y >= 0.f && y <= 1.f)) return;

    uint32_t width = R32(self + 0x74u), height = R32(self + 0x78u);
    if (!width || !height || width > 16384u || height > 16384u) return;
    float cursor_x = RF32(self + 0xb4u), cursor_y = RF32(self + 0xb8u);
    if (!(cursor_x >= 0.f && cursor_x <= width && cursor_y >= 0.f && cursor_y <= height)) return;
    /* The virtual cursor stores the center of its quad. The INI-defined
       offsets are added to this point before the guest tests a hit. */
    float target_x = x * (float)(width - 1) - (int32_t)R32(self + 0xbcu);
    float target_y = y * (float)(height - 1) - (int32_t)R32(self + 0xc0u);
    target_x = fminf((float)(width - 1), fmaxf(0.f, target_x));
    target_y = fminf((float)(height - 1), fmaxf(0.f, target_y));
    float dx = target_x - cursor_x, dy = cursor_y - target_y;
    WF32(c->esp + 0x18u, dy);
    W32(c->esp + 0x1cu, dy != 0.f);
    WF32(c->esp + 0x24u, dx);
    W32(c->esp + 0x28u, dx != 0.f);
}
#endif

/* ------------------------------------------------------------------ keyboard */

uint8_t g_keys[256];  /* virtual-key state, filled by the window backend */
/* The game samples VK state once per frame, so a tap shorter than a frame would fall
   between two samples (browsers deliver taps of a few ms; Storm 2 polls GetAsyncKeyState).
   A press counts as held for MIN_HOLD, mirroring the DirectInput layer's g_dik_down_at. */
static double g_keys_down_at[256];
void user32_key_touch(uint8_t vk) { g_keys_down_at[vk] = host_seconds(); }
static int vk_down(int vk) {
    return g_keys[vk] || (!deterministic() && host_seconds() - g_keys_down_at[vk] < 0.05);
}
/* PORT_DITRACE: same switch as dinput.c — makes VK-layer reads visible next to DI ones. */
static int vk_trace_down(int vk, const char *api) {
    static int tr = -1;
    if (tr < 0) tr = getenv("PORT_DITRACE") != NULL;
    if (tr && vk_down(vk)) fprintf(stderr, "[ditrace] %s %02x -> down\n", api, vk);
    return tr;
}
W(GetAsyncKeyState) { vk_trace_down(ARG(0) & 0xff, "AsyncKeyState"); RET(1, vk_down(ARG(0) & 0xff) ? 0x8000 : 0); }
W(GetKeyState) { vk_trace_down(ARG(0) & 0xff, "KeyState"); RET(1, vk_down(ARG(0) & 0xff) ? 0xFF80 : 0); }
W(GetKeyboardState) {
    for (int i = 0; i < 256; i++) W8(ARG(0) + i, vk_down(i) ? 0x80 : 0);
    if (vk_trace_down(0, "")) {   /* vk_trace_down returns tr; list every down key once */
        int down = 0;
        for (int i = 0; i < 256; i++) if (vk_down(i)) down++;
        if (down) {
            fprintf(stderr, "[ditrace] KeyboardState down(%d):", down);
            for (int i = 0; i < 256; i++) if (vk_down(i)) fprintf(stderr, " %02x", i);
            fprintf(stderr, "\n");
        }
    }
    RET(1, 1);
}
W(GetKeyboardLayout) { RET(1, 0x08090809u); }
W(MapVirtualKeyExA) { RET(3, ARG(0)); }
W(ToAsciiEx) {
    uint32_t vk = ARG(0);
    if ((vk >= 'A' && vk <= 'Z') || (vk >= '0' && vk <= '9') || vk == ' ') { W16(ARG(3), (uint16_t)vk); RET(6, 1); }
    RET(6, 0);
}
W(keybd_event) { RET(4, 0); }
/* The Russian game passes Windows-1251 bytes to ANSI APIs.  Keep this
 * independent of the host process locale; other byte values remain unchanged. */
static uint8_t char_upper_ansi(uint8_t ch) {
    if (ch >= 'a' && ch <= 'z') return (uint8_t)(ch - ('a' - 'A'));
    if (ch >= 0xe0u) return (uint8_t)(ch - 0x20u); /* а–я */
    if (ch == 0xb8u) return 0xa8u;                  /* ё → Ё */
    return ch;
}
W(CharUpperA) {
    uint32_t p = ARG(0);
    if (p < 0x10000u) RET(1, p <= 0xffu ? char_upper_ansi((uint8_t)p) : p);
    for (uint32_t q = p; R8(q); q++) W8(q, char_upper_ansi(R8(q)));
    RET(1, p);
}
W(SetWindowsHookExA) { g_hook_proc = ARG(1); LOG("[user32] SetWindowsHookExA(%d)\n", (int)ARG(0)); RET(4, 0x00040001u); }
W(UnhookWindowsHookEx) { RET(1, 1); }
W(CallNextHookEx) { RET(4, 0); }

#define U(name) IMPORT("USER32.DLL", name)
static const ImportHandler list[] = {
    U(PeekMessageA), U(GetMessageA), U(TranslateMessage), U(DispatchMessageA), U(PostMessageA), U(SendMessageA),
    U(SendNotifyMessageA), U(PostQuitMessage), U(DefWindowProcA), U(RegisterClassA), U(RegisterClassExA),
    U(UnregisterClassA), U(CreateWindowExA), U(DestroyWindow), U(ShowWindow), U(UpdateWindow), U(MoveWindow),
    U(SetWindowPos), U(SetWindowTextA), U(GetWindowLongA), U(FindWindowA), U(GetDesktopWindow),
    U(GetForegroundWindow), U(SetForegroundWindow), U(SetActiveWindow), U(SetFocus), U(IsIconic),
    U(GetClientRect), U(AdjustWindowRect), U(AdjustWindowRectEx), U(ClientToScreen), U(ScreenToClient),
    U(SetRect), U(BeginPaint), U(EndPaint), U(GetSystemMetrics), U(SystemParametersInfoA), U(MessageBoxA),
    U(LoadCursorA), U(LoadIconA), U(LoadImageA), U(DestroyIcon), U(SetCursor), U(ShowCursor), U(GetCursorPos),
    U(SetCursorPos), U(GetAsyncKeyState), U(GetKeyState), U(GetKeyboardState), U(GetKeyboardLayout),
    U(GetWindowRect), U(wsprintfA), U(ClipCursor), U(LoadBitmapA), U(GetDC), U(ReleaseDC), U(FillRect), U(InvalidateRect),
    U(OffsetRect), U(GetMenu), U(GetMenuItemCount), U(GetSubMenu), U(GetMenuItemID), U(GetMenuItemInfoA),
    U(InsertMenuItemA), U(SetMenuItemInfoA), U(CheckMenuItem), U(DestroyMenu), U(SetScrollInfo),
    U(TabbedTextOutA), U(GetTabbedTextExtentA), U(OpenClipboard), U(CloseClipboard), U(EmptyClipboard),
    U(SetClipboardData),
    U(MapVirtualKeyExA), U(ToAsciiEx), U(keybd_event), U(CharUpperA), U(SetWindowsHookExA),
    U(UnhookWindowsHookEx), U(CallNextHookEx),
};
const ImportTable user32_imports = { list, sizeof list / sizeof list[0] };
