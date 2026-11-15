/* Host implementations of the Windows API the game imports.
 *
 * Every import is a GuestFn: the game reached it with `call [IAT]`, so the return address is at
 * [esp] and the arguments follow. Windows API functions are stdcall: the callee pops its arguments.
 */
#ifndef PORT_WIN32_H
#define PORT_WIN32_H

#include "runtime.h"
#include "tls_slots.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARG(i) R32(c->esp + 4 + 4 * (i))
/* return from a stdcall import with `nargs` 32-bit arguments */
#define RET(nargs, value) do { c->eax = (uint32_t)(value); c->esp += 4 + 4 * (nargs); return; } while (0)
/* cdecl (variadic) imports: caller cleans up the arguments */
#define RET_CDECL(value) do { c->eax = (uint32_t)(value); c->esp += 4; return; } while (0)

#define GSTR(a) ((const char *)HP(a))
#define GWSTR(a) ((const uint16_t *)HP(a))

/* Registration: each host module contributes a table of {"DLL!Name", handler}. */
#define IMPORT(dll, name) { dll "!" #name, w_##name }
typedef struct { const ImportHandler *list; uint32_t count; } ImportTable;
extern const ImportTable kernel32_imports, user32_imports, gdi32_imports, advapi32_imports, winmm_imports,
    directx_imports, shell_imports;

/* Logging of host-side events (PORT_LOG=1). */
extern int g_log;
#define MAIN_HWND 0x00010010u   /* the game's one window */
#define LOG(...) do { if (g_log) fprintf(stderr, __VA_ARGS__); } while (0)
#define STUB(...) LOG("[stub] " __VA_ARGS__)

/* ------------------------------------------------------------------ guest memory allocation */

uint32_t heap_alloc(uint32_t size, int zero);
uint32_t heap_try_alloc(uint32_t size, int zero);
void heap_free(uint32_t a);
uint32_t heap_realloc(uint32_t a, uint32_t size, int zero);
uint32_t heap_realloc_ex(uint32_t a, uint32_t size, int zero, int in_place);
uint32_t heap_size(uint32_t a);
uint32_t guest_valloc(uint32_t size);              /* page-granular, zero-filled */
uint32_t guest_strdup(const char *s);

/* ------------------------------------------------------------------ handles */

/* H_RESERVED: a slot that is allocated but not (or no longer) a live handle: an open that has not
   published its handle yet (strict share, kernel32.c), or a close in progress. Never matched by a
   typed handle_get and never closable by a guest; only the strict-share paths create it. */
enum HandleType { H_FREE, H_FILE, H_FIND, H_MAPPING, H_EVENT, H_MUTEX, H_SEMAPHORE, H_THREAD, H_STD, H_MISC, H_RESERVED };
typedef struct {
    int type;            /* FIRST member, accessed atomically (core.c: the table lock and handle_get) */
    int fd;              /* H_FILE */
    int save_read_activity; /* telemetry only: this handle reads a SAVE file */
    int write_open;      /* H_FILE: this handle may write/truncate (blocks snapshots of the path) */
    uint8_t *buf;        /* H_FILE read-only snapshot: file bytes read once at open (kernel32.c) */
    uint64_t buf_size, buf_pos;
    void *ptr;           /* H_FIND: directory search state; sync objects: their host object */
    char path[1024];
} WinHandle;

/* Потокобезопасность и порядок замков: комментарий над таблицей в core.c, PORT_SPECIFICATION.md. handle_get
   без замка (атомарная загрузка типа); перед публикацией типа слот надо подготовить: ptr задаёт handle_new_ptr,
   остальное handle_try_new(H_RESERVED) + заполнение + handle_publish. Заполнять слот ПОСЛЕ handle_new(H_FILE и
   т.п.) нельзя: другой поток уже видит его как живой handle. */
uint32_t handle_new(int type);
uint32_t handle_new_ptr(int type, void *ptr);  /* handle_new with the slot's ptr set before the handle becomes visible */
uint32_t handle_reserve_ptr(void *ptr);        /* H_RESERVED slot with ptr set; fill in, then handle_publish (no half-built handle is visible) */
int handle_snapshot(uint32_t h, void **ptr);   /* type (H_FREE if not live) and ptr of a live handle read once: for waits that must not re-read the slot */
typedef void (*HandleCloseHook)(uint32_t h, int type, void *ptr);
void handle_set_close_hook(HandleCloseHook hook);   /* run once per close, after the slot is claimed and before it is released */
#define HANDLE_PTR(x) __atomic_load_n(&(x)->ptr, __ATOMIC_RELAXED)   /* the slot's ptr (sync objects, find state) */
WinHandle *handle_get(uint32_t h, int type);   /* NULL if not that type; the pointer is not pinned (no refcount) */
void handle_close(uint32_t h);                 /* a closed/free/reserved value is a silent no-op; atomic per handle */
/* Strict-share handle lifecycle (kernel32.c, PORT_STRICT_FILE_SHARE): allocation that can fail instead of
   aborting, a two-step publish so no handle value exists before its open has succeeded, and a close that
   is atomic per handle. handle_new/handle_close above keep their original behavior. */
uint32_t handle_try_new(int type);             /* 0 when the table is full (handle_new aborts) */
WinHandle *handle_reserved(uint32_t h);        /* the H_RESERVED slot of h, else NULL */
void handle_publish(uint32_t h, int type);     /* H_RESERVED -> type (slot fields written before) */
void handle_cancel(uint32_t h);                /* H_RESERVED -> H_FREE */
int handle_close_checked(uint32_t h);          /* 1: this call closed a live handle; 0: invalid/double/in progress */
void handle_set_round_robin(int on);           /* allocate after the last one so a stale value stays invalid longer */
int file_path_write_open(const char *host);    /* an open H_FILE handle on this path may write it */
uint32_t port_load_pacing_active(void);        /* kernel32.c: inside a save-load episode (browser Present may skip the vsync race) */

/* ------------------------------------------------------------------ paths */

extern char g_game_root[1024];   /* host folder holding the game's files */
extern char g_user_root[1024];   /* host folder for files the game writes outside its own folder */
#include "port_config.h"
#define GUEST_ROOT PORT_GUEST_ROOT

/* Maps a Windows path from the game to a host path, matching path components case-insensitively.
   Returns 1 if the host path exists. */
int map_path(const char *guest, char *host, size_t n);
#ifdef PORT_LAZY_EXPERIMENT
#include "../experimental/lazy-loading/lazy_index.h"
const LazyNode *lazy_guest_node(const char *guest);
#endif

/* Language overlay (E1, core.c has the rationale): PORT_OVERLAY=<host dir> lays a read-only tree over PROGRAM/ and RESOURCE/.
   map_path never returns an overlay path. map_path_ov also says what the overlay holds at the path; with the overlay off it is
   map_path plus one flag test (ov->kind 0). */
typedef struct { int kind; /* 0 none, 1 overlay file, 2 overlay directory */ const void *node; char host[1024]; /* overlay physical path */ } OvHit;
int map_path_ov(const char *guest, char *host, size_t n, OvHit *ov);   /* 1 if the path exists in the base OR the overlay */
int overlay_active(void);
int overlay_init_from_env(void);                                        /* main(): -1 = a requested root is unusable, do not start */
void overlay_test_reset(void);                                          /* tests only */
int overlay_dir_entry(const void *dir, uint32_t idx, const char **name, const char **host, int *is_dir);
int overlay_dir_find(const void *dir, const char *host_name, int cp, const char **host, int *is_dir);
void overlay_name_key(const char *name, int cp, char *out, size_t n);

/* Opt-in CP1251 <-> UTF-8 layer for file names (PORT_NAME_CP1251=1; core.c has the rationale). Off: map_path
   and the find calls behave as before. name_host_to_guest returns 0 for a host name that is not well-formed
   UTF-8 or holds a character Windows-1251 lacks; the find calls then hand the guest the host's own bytes. */
int name_cp1251_on(void);
void name_cp1251_set(int on);                                       /* tests only */
int name_guest_to_host(const char *guest, char *out, size_t n);     /* CP1251 -> UTF-8, 0 if it does not fit */
int name_host_to_guest(const char *host, char *out, size_t n);      /* UTF-8 -> CP1251, 0 if not representable */
int name_wild_match(const char *pat_cp1251, const char *name_utf8); /* FindFirstFileA pattern, case folded */
uint32_t name_fold_cp(uint32_t cp);                                 /* Windows case folding of one code point */
int name_utf8_decode(const unsigned char *s, uint32_t *cp);         /* 1..4 bytes, 0 if ill-formed */
int name_has_high(const char *s);                                   /* any byte >= 0x80 */
void name_log(const char *what, const char *bytes);                    /* PORT_LOG line, hex of the bytes, first 40 only */

/* ------------------------------------------------------------------ threads */

typedef struct GuestThread {
    CPU cpu;
    uint32_t id;
    uint32_t tib;
    PortTlsValues tls;
    uint32_t last_error;
} GuestThread;
extern __thread GuestThread *t_self;
GuestThread *thread_main_init(CPU *c);
GuestThread *guest_thread_new(void);                                  /* stack + TIB + CPU state */
uint32_t guest_stdcall(CPU *c, uint32_t fn, int nargs, const uint32_t *args);  /* call into the game */
void post_message(uint32_t hwnd, uint32_t msg, uint32_t wp, uint32_t lp);
extern int g_screen_w, g_screen_h;
extern uint8_t g_keys[256];
void user32_key_touch(uint8_t vk);   /* mark a press; the VK layer holds it MIN_HOLD so a fast tap lands in a frame sample */

/* ------------------------------------------------------------------ misc */

uint64_t host_time_100ns(void);  /* FILETIME units since 1601 */
double host_seconds(void);       /* monotonic */
/* Time the game sees (core.c). Normally host_seconds(); with PORT_DETERMINISTIC=1 a virtual clock that only
   the game's main thread advances (per Present, per Sleep, 1 us per time read), so it is a function of
   that thread's execution rather than of wall time. */
double guest_seconds(void);
uint64_t guest_time_100ns(void); /* FILETIME units since 1601 */
int deterministic(void);
void vclock_frame(void);         /* Present */
void vclock_init(void);          /* main(), before the game starts */
double guest_peek_seconds(void); /* guest_seconds() without advancing the virtual clock */
int on_game_thread(void);         /* the game's main thread (the one that runs WinMain) */
/* sched.c (deterministic mode only; no-ops otherwise) */
void sched_main_init(void);                       /* on the game's thread, before it starts */
void *sched_new(const char *name, int (*start)(void *), void *arg);   /* by the creator; NULL when off */
void sched_enter(void *rec);                      /* first thing on the new host thread */
void sched_exit(void);
void sched_yield_det(void);
int sched_wait(int (*pred)(void *), void *arg, uint64_t deadline_us, uint64_t (*deadline_fn)(void));
int sched_active(void);                           /* the calling thread is scheduled */
uint64_t sched_now_us(void);

#endif
