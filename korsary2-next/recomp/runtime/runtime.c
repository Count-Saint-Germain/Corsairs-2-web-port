/* Runtime for recompiled code: guest memory, PE image loading, function dispatch, traps. */
#include "runtime.h"
#include "sea_hook.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/mman.h>

uint8_t *g_mem;

/* ------------------------------------------------------------------ function table */

typedef struct { uint32_t addr; GuestFn fn; } FnEntry;
static FnEntry *g_fns;
static uint32_t g_fn_cap;  /* power of two */

void register_function(uint32_t addr, GuestFn fn) {
    if (!g_fns) {
        g_fn_cap = 1u << 16;
        g_fns = calloc(g_fn_cap, sizeof *g_fns);
    }
    uint32_t i = (addr * 2654435761u) & (g_fn_cap - 1);
    while (g_fns[i].fn && g_fns[i].addr != addr) i = (i + 1) & (g_fn_cap - 1);
    g_fns[i].addr = addr;
    g_fns[i].fn = fn;
}

GuestFn lookup_function(uint32_t addr) {
    if (!g_fns) return NULL;
    uint32_t i = (addr * 2654435761u) & (g_fn_cap - 1);
    while (g_fns[i].fn) {
        if (g_fns[i].addr == addr) return g_fns[i].fn;
        i = (i + 1) & (g_fn_cap - 1);
    }
    return NULL;
}

static void unimplemented_import(CPU *c);
static int g_log_imports = -1;
__thread uint32_t g_import_target;  /* which host slot the current import call came through */

static uint32_t g_trace_call = 1;   /* PORT_TRACE_CALL=addr: log indirect calls to that function */

#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
void port_menu_mouse_control(CPU *c, uint32_t result);
#endif

#if !defined(PORT_NODE_BUILD)
/* Video bridge (browser builds): host/video.c turns the engine's CAviPlayer open call (the one place every
 * video request passes with its file name, see host/video.c) into a page-visible request, and logs the
 * script VM's unknown-function traces. Weak here so links without host/video.c (and the Node build, which
 * compiles the calls out below) keep today's byte-for-byte behavior. */
void port_video_call_site(const CPU *c);
void port_video_open_site(const CPU *c);
__attribute__((weak)) void port_video_call_site(const CPU *c) { (void)c; }
__attribute__((weak)) void port_video_open_site(const CPU *c) { (void)c; }
#endif

static int g_ss_trace = -1;
void call_indirect(CPU *c, uint32_t target) {
    SeaCapsProbe sea_probe={0};
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    uint32_t menu_control_result = 0;
#endif
#ifndef PORT_NODE_BUILD
    /* Video bridge: CAviPlayer's open call (0xae77fd) and ExecuteFunction's unknown-function trace calls
     * (three return addresses, diagnostic) are forwarded; the single guarded load keeps the hot path cheap. */
    if ((uint64_t)c->esp+32u<=GUEST_SPACE) {
        uint32_t ra = R32(c->esp);
        if (ra==0x00ae77fdu) port_video_open_site(c);
        else if (ra==0x0040a3cfu || ra==0x0040b977u || ra==0x0040a456u) port_video_call_site(c);
#if defined(__EMSCRIPTEN__)
        /* XINTERFACE's second mouse-axis GetControlState call. Read its
           result pointer before the callee pops the guest arguments. */
        else if (ra == 0x00ae2381u) menu_control_result = R32(c->esp + 8u);
#endif
    }
#endif
    /* Only the verified sea caps call is eligible for the opt-in fallback. */
    if ((uint64_t)c->esp+4u<=GUEST_SPACE && R32(c->esp)==SEA_CAPS_RETURN)
        sea_probe=sea_caps_probe_before(c,target);
    if (g_ss_trace == -1) g_ss_trace = getenv("PORT_TRACE_SS") != NULL;
    if (g_ss_trace) {
        uint32_t from = R32(c->esp);
        if (target >= 0xbd0000 && target < 0xbf0000)
            fprintf(stderr, "[ssci] %08x -> rigging %08x\n", from, target);
    }
    if (g_trace_call == 1) g_trace_call = getenv("PORT_TRACE_CALL") ? (uint32_t)strtoul(getenv("PORT_TRACE_CALL"), NULL, 16) : 0;
    uint32_t traced_this = 0;
    if (g_trace_call && target == g_trace_call) {
        static int n;
        if (n++ < 40) {
            fprintf(stderr, "[call] %08x from %08x ecx=%08x args %08x %08x %08x %08x\n", target, R32(c->esp), c->ecx,
                    R32(c->esp + 4), R32(c->esp + 8), R32(c->esp + 12), R32(c->esp + 16));
            traced_this = c->ecx;
        }
    }
    GuestFn fn = lookup_function(target);
    if (traced_this && fn) {
        fn(c);
        sea_caps_probe_after(c,&sea_probe);
        /* debugging the lighting instance: +0xc0 multipliers, +0x140 blend, config(+0x10) +0x70..+0x8c */
        uint32_t o = traced_this, cfg = R32(o + 0x10);
        float f[4], t, a[8];
        memcpy(f, HP(o + 0xc0), 16); memcpy(&t, HP(o + 0x140), 4);
        if (cfg) memcpy(a, HP(cfg + 0x70), 32); else memset(a, 0, sizeof a);
        fprintf(stderr, "[call]   -> mult %g %g %g %g  t %g  cfg %08x lo %g %g %g %g hi %g %g %g %g\n", f[0], f[1], f[2], f[3], t,
                cfg, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
        return;
    }
    if (!fn && dyncode_contains(target)) { interp_call(c, target); sea_caps_probe_after(c,&sea_probe); return; }
    if (!fn) {
        static char msg[96];
        snprintf(msg, sizeof msg, "indirect call to unknown function (return address %08x)", R32(c->esp));
        guest_trap(c, target, msg);
    }
    if (target >= IMPORT_BASE) {
        const char *name = import_name(target);
        if (g_log_imports < 0) g_log_imports = getenv("PORT_LOG_IMPORTS") != NULL;
        if (g_log_imports && name)
            fprintf(stderr, "[import] %-40s from %08x  args %08x %08x %08x %08x\n", name, R32(c->esp),
                    R32(c->esp + 4), R32(c->esp + 8), R32(c->esp + 12), R32(c->esp + 16));
        g_import_target = target;
        if (fn == unimplemented_import) {
            static char msg[160];
            snprintf(msg, sizeof msg, "unimplemented Windows import %s (called from %08x)",
                     name ? name : "?", R32(c->esp));
            guest_trap(c, target, msg);
        }
    }
    fn(c);
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    if (menu_control_result) port_menu_mouse_control(c, menu_control_result);
#endif
    sea_caps_probe_after(c,&sea_probe);
}

void jump_indirect(CPU *c, uint32_t target, uint32_t from) {
    /* A tail jump already has its caller's return address on the stack. Route it
       through the same dispatcher as a call, without pushing another address:
       COM/import handlers need g_import_target set to the actual target. */
    if (!lookup_function(target) && !dyncode_contains(target)) {
        fprintf(stderr, "indirect jump from %08x\n", from);
        guest_trap(c, target, "indirect jump to unknown target");
        return;
    }
    call_indirect(c, target);
}

void guest_bounds_fail(uint32_t a, int n) {
    fprintf(stderr, "\n*** guest write of %d bytes at %08x is outside guest memory\n", n, a);
    __builtin_trap();   /* the engine's stack trace names the recompiled function */
}

volatile uint8_t g_guest_lock;

jmp_buf *g_trap_jmp;        /* when set (tests), traps longjmp here instead of aborting */
char g_trap_msg[256];

void guest_trap(CPU *c, uint32_t addr, const char *why) {
    if (g_trap_jmp) {
        snprintf(g_trap_msg, sizeof g_trap_msg, "%08x: %s", addr, why);
        longjmp(*g_trap_jmp, 1);
    }
    fprintf(stderr, "\n*** guest trap at %08x: %s\n", addr, why);
    if (addr == 0x44dc4a) {   /* TEMP DEBUG: dump compiler FuncTab entries */
        uint32_t ftab = 0x476A04u;
        uint32_t cnt = R32(ftab + 4), arr = R32(ftab + 8);
        fprintf(stderr, "    [ftab] count %u arr %08x\n", cnt, arr);
        uint32_t nfound = 0;
        for (uint32_t n = 0; n < cnt && n < 400; n++) {
            uint32_t ent = arr + 0x48 * n;
            int isdel = 0; uint32_t namep = 0;
            for (int d = 0; d < 18; d++) {
                uint32_t p = R32(ent + 4 * d);
                if (p >= 0x400000) {
                    char c0 = (char)R8(p), c1 = (char)R8(p + 1);
                    if (c0 == 'D' && c1 == 'e' && (char)R8(p+2) == 'l') { isdel = 1; namep = p; }
                }
            }
            if (isdel || n < 3) {
                fprintf(stderr, "    [ftab] %3u ent %08x segid %08x : dwords", n, ent, R32(ent + 0x10));
                for (int d = 0; d < 18; d++) fprintf(stderr, " %08x", R32(ent + 4 * d));
                fprintf(stderr, "\n");
                if (namep) {
                    char tx[32]; int ci;
                    for (ci = 0; ci < 31; ci++) { char ch = (char)R8(namep + ci); if (!ch) break; tx[ci] = ch; }
                    tx[ci] = 0;
                    fprintf(stderr, "      name '%s'\n", tx);
                }
                nfound++;
                if (nfound > 400) break;
            }
        }
    }
    if (addr == 0) {   /* TEMP DEBUG: walk the guest heap blocks around the faulting object */
        uint32_t magic = 0xC07A11C8u, b = 0x10000010;
        while (b < 0x104dd000) {
            uint32_t m = R32(b - 12);
            if (m == magic) {
                uint32_t sz = R32(b - 16), freed = (R32(b - 12) == 0);
                if (b + sz > 0x104dc5b0)
                    fprintf(stderr, "    [heap] block %08x size %x free-mark %08x [0]=%08x\n",
                            b, sz, m, R32(b));
                b += 16 + sz;
            } else b += 16;
        }
    }
    fprintf(stderr, "    eax=%08x ecx=%08x edx=%08x ebx=%08x esp=%08x ebp=%08x esi=%08x edi=%08x\n",
            c->eax, c->ecx, c->edx, c->ebx, c->esp, c->ebp, c->esi, c->edi);
    /* Stack words that look like return addresses into .text, plus the memory eax/ecx point at. */
    fprintf(stderr, "    stack:");
    for (int i = 0; i < 64; i++) {
        uint32_t v = R32(c->esp + 4 * i);
        if (looks_like_code(v)) fprintf(stderr, " [%d]%08x", i, v);
    }
    fprintf(stderr, "\n");
    uint32_t regs[2] = { c->eax, c->ecx };
    for (int r = 0; r < 2; r++) {
        if (regs[r] < GUEST_HEAP_BASE || regs[r] >= GUEST_HEAP_HI) continue;
        fprintf(stderr, "    [%s]:", r ? "ecx" : "eax");
        for (int i = -4; i < 12; i++) fprintf(stderr, " %08x", R32(regs[r] + 4 * i));
        fprintf(stderr, "\n");
    }
    if (addr >= GUEST_HEAP_BASE && addr < GUEST_VALLOC_HI) {
        fprintf(stderr, "    code at %08x:", addr);
        for (int i = 0; i < 64; i++) fprintf(stderr, "%s%02x", i % 32 ? "" : "\n      ", R8(addr + i));
        fprintf(stderr, "\n");
    }
    abort();
}

/* ------------------------------------------------------------------ tracing (--trace builds) */

TraceRec *g_trace;
uint32_t g_trace_len, g_trace_cap;

void trace_insn(CPU *c, uint32_t addr) {
    if (!g_trace || g_trace_len >= g_trace_cap) return;
    TraceRec *r = &g_trace[g_trace_len++];
    r->addr = addr;
    r->regs[0] = c->eax; r->regs[1] = c->ecx; r->regs[2] = c->edx; r->regs[3] = c->ebx;
    r->regs[4] = c->esp; r->regs[5] = c->ebp; r->regs[6] = c->esi; r->regs[7] = c->edi;
    r->st0 = c->st[c->top];
    r->top = (uint32_t)c->top;
}

/* ------------------------------------------------------------------ x87 helpers */

static double round_mode(CPU *c, double v) {
    switch ((c->fpu_cw >> 10) & 3) {
    case 0: return nearbyint(v); /* host default mode is round-to-nearest-even */
    case 1: return floor(v);
    case 2: return ceil(v);
    default: return trunc(v);
    }
}

int32_t fpu_to_int32(CPU *c, double v) {
    double r = round_mode(c, v);
    if (!(r >= -2147483648.0 && r <= 2147483647.0)) return INT32_MIN; /* "integer indefinite" */
    return (int32_t)r;
}

int64_t fpu_to_int64(CPU *c, double v) {
    double r = round_mode(c, v);
    if (!(r >= -9223372036854775808.0 && r < 9223372036854775808.0)) return INT64_MIN;
    return (int64_t)r;
}

double fpu_round(CPU *c, double v) { return round_mode(c, v); }

#include <fenv.h>
void fpu_sync_rounding(CPU *c) {
    static const int modes[4] = { FE_TONEAREST, FE_DOWNWARD, FE_UPWARD, FE_TOWARDZERO };
    static __thread int current = -1;  /* MSVC's _ftol switches modes twice per conversion: skip no-ops */
    int rc = (c->fpu_cw >> 10) & 3;
    if (rc != current) { fesetround(modes[rc]); current = rc; }
}

double RF80(uint32_t a) {
    uint64_t mant = R64(a);
    uint16_t se = R16(a + 8);
    int sign = se >> 15, exp = se & 0x7fff;
    double v;
    if (exp == 0 && mant == 0) v = 0.0;
    else if (exp == 0x7fff) v = (mant << 1) ? NAN : INFINITY;
    else v = ldexp((double)mant, exp - 16383 - 63);
    return sign ? -v : v;
}

void WF80(uint32_t a, double v) {
    uint16_t se = signbit(v) ? 0x8000 : 0;
    uint64_t mant = 0;
    v = fabs(v);
    if (isnan(v)) { se |= 0x7fff; mant = 0xc000000000000000ull; }
    else if (isinf(v)) { se |= 0x7fff; mant = 0x8000000000000000ull; }
    else if (v != 0) {
        int e;
        double m = frexp(v, &e);           /* v = m * 2^e, 0.5 <= m < 1 */
        mant = (uint64_t)ldexp(m, 64);      /* explicit integer bit at bit 63 */
        se |= (uint16_t)(e - 1 + 16383);
    }
    W64(a, mant);
    W16(a + 8, se);
}

/* ------------------------------------------------------------------ CPUID / RDTSC */

void cpuid(CPU *c) {
    switch (c->eax) {
    case 0:  /* max standard leaf 1, "GenuineIntel" */
        c->eax = 1; c->ebx = 0x756e6547; c->edx = 0x49656e69; c->ecx = 0x6c65746e; break;
    case 1:  /* family 6, model 8; FPU, TSC, CX8, CMOV only: deliberately no MMX (bit 23) or SSE (25/26) */
        c->eax = 0x00000683; c->ebx = 0; c->ecx = 0; c->edx = (1u << 0) | (1u << 4) | (1u << 8) | (1u << 15); break;
    case 0x80000000u:  /* no extended leaves, so no 3DNow! */
        c->eax = 0x80000000u; c->ebx = c->ecx = c->edx = 0; break;
    default:
        c->eax = c->ebx = c->ecx = c->edx = 0;
    }
}

#include <time.h>
/* A 2 GHz timestamp counter, consistent with the CPU speed reported through the registry. */
uint64_t (*g_rdtsc_hook)(void);   /* set by the host for deterministic runs */
int g_preempt_on;
void (*g_preempt_fn)(void);       /* the deterministic scheduler's yield */
void guest_preempt(CPU *c) { c->preempt_ticks = 0; if (g_preempt_fn) g_preempt_fn(); }
void rdtsc(CPU *c) {
    if (g_rdtsc_hook) { uint64_t t = g_rdtsc_hook(); c->eax = (uint32_t)t; c->edx = (uint32_t)(t >> 32); return; }
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    uint64_t t = (uint64_t)ts.tv_sec * 2000000000ull + (uint64_t)ts.tv_nsec * 2ull;
    c->eax = (uint32_t)t; c->edx = (uint32_t)(t >> 32);
}

/* ------------------------------------------------------------------ imports */

typedef struct { char name[96]; GuestFn fn; } ImportSlot;
static ImportSlot g_imports[4096];  /* PE imports + GetProcAddress results + COM method slots */
static uint32_t g_nimports;

static void unimplemented_import(CPU *c) {
    /* The return address on the stack identifies the caller; the slot is found from the IAT
       value the caller used, which call_indirect passed as the target. */
    guest_trap(c, R32(c->esp), "call to an unimplemented Windows import");
}

static ImportHandler *g_import_handlers;
static uint32_t g_nhandlers;

void set_import_handlers(ImportHandler *h, uint32_t n) { g_import_handlers = h; g_nhandlers = n; }

static GuestFn find_handler(const char *name) {
    for (uint32_t i = 0; i < g_nhandlers; i++)
        if (!strcmp(g_import_handlers[i].name, name)) return g_import_handlers[i].fn;
    return NULL;
}

uint32_t add_dynamic_import(const char *name, GuestFn fn) {
    ImportSlot *sl = &g_imports[g_nimports];
    snprintf(sl->name, sizeof sl->name, "%s", name);
    sl->fn = fn;
    uint32_t magic = IMPORT_BASE + g_nimports * 16;
    register_function(magic, fn);
    g_nimports++;
    return magic;
}

GuestFn find_import_handler(const char *name) { return find_handler(name); }

const char *import_name(uint32_t addr) {
    if (addr < IMPORT_BASE || addr >= IMPORT_BASE + g_nimports * 16) return NULL;
    return g_imports[(addr - IMPORT_BASE) / 16].name;
}

/* ------------------------------------------------------------------ PE loading */

static uint16_t rd16(const uint8_t *p) { return (uint16_t)(p[0] | p[1] << 8); }
static uint32_t rd32(const uint8_t *p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }

/* Union of every loaded image's code and writable-data ranges (see runtime.h). */
uint32_t g_code_lo = 0x401000, g_code_hi = 0x401000, g_data_lo, g_data_hi;

/* ------------------------------------------------------------------ guest module registry
 *
 * One record per loaded image: the LoadLibraryA name it answers to and its export directory, parsed
 * once from guest memory after mapping (GetProcAddress resolves guest-module handles through it).
 * Translated code addresses ARE the export addresses: no trampoline is needed. */

typedef struct {
    uint32_t base, size, entry;
    uint32_t code_lo, code_hi, data_lo, data_hi;
    char name[128];                    /* normalized (lower-case, backslashes) */
    int attached;                      /* DLL_PROCESS_ATTACH entry has run */
    uint32_t ord_base, nfuncs, nnames;
    uint32_t *funcs;                   /* guest address per exported ordinal */
    char **names;                      /* name-table entry per exported name (NULL: forwarder) */
    uint32_t *name_fn;                 /* funcs index the name resolves to */
} GuestModule;

static GuestModule *g_mods;
static uint32_t g_nmods, g_mod_cap;

static void norm_name(char *dst, size_t n, const char *src) {
    size_t k = 0;
    for (const char *p = src; *p && k < n - 1; p++)
        dst[k++] = (char)(*p == '/' ? '\\' : tolower((unsigned char)*p));
    dst[k] = 0;
}

void module_set_name(uint32_t base, const char *name) {
    for (uint32_t i = 0; i < g_nmods; i++)
        if (g_mods[i].base == base) { norm_name(g_mods[i].name, sizeof g_mods[i].name, name); return; }
}

static GuestModule *module_at(uint32_t base) {
    for (uint32_t i = 0; i < g_nmods; i++)
        if (g_mods[i].base == base) return &g_mods[i];
    return NULL;
}

uint32_t guest_module_base(const char *name) {
    if (!name) return 0;
    char q[128];
    norm_name(q, sizeof q, name);
    const char *qb = strrchr(q, '\\');
    qb = qb ? qb + 1 : q;
    for (uint32_t i = 0; i < g_nmods; i++) {       /* full path first, then bare file name */
        if (!strcmp(g_mods[i].name, q)) return g_mods[i].base;
        const char *mb = strrchr(g_mods[i].name, '\\');
        mb = mb ? mb + 1 : g_mods[i].name;
        if (!strcmp(mb, qb)) return g_mods[i].base;
    }
    return 0;
}

int guest_module_attach(uint32_t base, CPU *c) {
    GuestModule *m = module_at(base);
    if (!m || m->attached) return 0;
    m->attached = 1;
    if (m->entry == m->base) return 0;   /* no entry point */
    GuestFn fn = lookup_function(m->entry);
    if (!fn) return 0;
    uint32_t args[3] = { base, 1 /* DLL_PROCESS_ATTACH */, 0 };
    guest_call(c, fn, 3, args);
    return 1;
}

int guest_export_lookup(uint32_t base, const char *name, uint32_t ordinal, uint32_t *addr) {
    GuestModule *m = module_at(base);
    if (!m || !m->nfuncs) return 0;
    if (name) {
        for (uint32_t i = 0; i < m->nnames; i++)
            if (m->names[i] && !strcmp(m->names[i], name)) {
                uint32_t k = m->name_fn[i];
                if (k >= m->nfuncs || !m->funcs[k]) return 0;
                *addr = m->funcs[k];
                return 1;
            }
        return 0;
    }
    if (ordinal < m->ord_base || ordinal - m->ord_base >= m->nfuncs) return 0;
    uint32_t a = m->funcs[ordinal - m->ord_base];
    if (!a) return 0;
    *addr = a;
    return 1;
}

/* Parse the export directory of the just-mapped image at `base`. Forwarded exports (their RVA names
   a string instead of code) resolve to other DLLs, which we don't model: they stay unresolvable. */
static void parse_exports(uint32_t base, uint32_t exp_rva, uint32_t exp_size) {
    GuestModule *m = &g_mods[g_nmods - 1];
    const uint8_t *e = HP(base + exp_rva);
    /* IMAGE_EXPORT_DIRECTORY: Name@12, Base@16, NumFunctions@20, NumberOfNames@24, tables@28/32/36 */
    m->ord_base = rd32(e + 16);
    m->nfuncs = rd32(e + 20);
    m->nnames = rd32(e + 24);
    uint32_t fn_rva = rd32(e + 28), nm_rva = rd32(e + 32), no_rva = rd32(e + 36);
    if (!m->nfuncs || m->nfuncs > 0xffff) { m->nfuncs = m->nnames = 0; return; }
    m->funcs = calloc(m->nfuncs, sizeof *m->funcs);
    for (uint32_t i = 0; i < m->nfuncs; i++) {
        uint32_t rva = rd32(HP(base + fn_rva + 4 * i));
        m->funcs[i] = rva && !(rva >= exp_rva && rva < exp_rva + exp_size) ? base + rva : 0;
    }
    if (m->nnames && m->nnames <= m->nfuncs + 0xffff) {
        m->names = calloc(m->nnames, sizeof *m->names);
        m->name_fn = calloc(m->nnames, sizeof *m->name_fn);
        for (uint32_t i = 0; i < m->nnames; i++) {
            const char *s = (const char *)HP(base + rd32(HP(base + nm_rva + 4 * i)));
            m->names[i] = strdup(s);
            m->name_fn[i] = rd16(HP(base + no_rva + 2 * i));
        }
    }
}

#ifdef PORT_TEST_IMAGE_IO
/* Fault injection is scoped to the loader; ordinary builds use libc directly. */
extern int image_test_fseek(FILE *, long, int);
extern long image_test_ftell(FILE *);
extern void *image_test_malloc(size_t);
extern size_t image_test_fread(void *, size_t, size_t, FILE *);
extern int image_test_fclose(FILE *);
#define fseek image_test_fseek
#define ftell image_test_ftell
#define malloc image_test_malloc
#define fread image_test_fread
#define fclose image_test_fclose
#endif
int load_image(const char *path, uint32_t base, LoadedImage *out) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return -1; }
    if (fseek(f, 0, SEEK_END)) { fclose(f); return -1; }
    long size = ftell(f);
    if (size <= 0 || fseek(f, 0, SEEK_SET)) { fclose(f); return -1; }
    uint8_t *file = malloc((size_t)size);
    if (!file) { fclose(f); return -1; }
    if (fread(file, 1, (size_t)size, f) != (size_t)size) { free(file); fclose(f); return -1; }
    if (fclose(f)) { free(file); return -1; }

    const uint8_t *pe = file + rd32(file + 0x3c);
    uint16_t nsec = rd16(pe + 6);
    uint16_t optsz = rd16(pe + 20);
    const uint8_t *opt = pe + 24;
    uint32_t pref_base = rd32(opt + 28);
    uint32_t final_base = base ? base : pref_base;
    uint32_t image_size = rd32(opt + 56);
    uint32_t entry = rd32(opt + 16);
    uint32_t hdr_size = rd32(opt + 60);
    uint32_t imp_rva = rd32(opt + 96 + 8);
    int32_t delta = (int32_t)(final_base - pref_base);
    uint32_t exp_rva = rd32(opt + 96 + 0), exp_size = rd32(opt + 96 + 4);

    if (g_nmods == g_mod_cap) {
        g_mod_cap = g_mod_cap ? g_mod_cap * 2 : 8;
        g_mods = realloc(g_mods, g_mod_cap * sizeof *g_mods);
        memset(g_mods + g_nmods, 0, (g_mod_cap - g_nmods) * sizeof *g_mods);
    }
    GuestModule *m = &g_mods[g_nmods++];
    memset(m, 0, sizeof *m);
    m->base = final_base;
    m->size = image_size;
    m->entry = final_base + entry;
    m->code_lo = m->code_hi = m->data_lo = m->data_hi = 0;

    memcpy(HP(final_base), file, hdr_size);
    const uint8_t *sec = opt + optsz;
    for (int i = 0; i < nsec; i++, sec += 40) {
        uint32_t vsize = rd32(sec + 8), va = rd32(sec + 12), rawsz = rd32(sec + 16), rawptr = rd32(sec + 20);
        uint32_t n = rawsz < vsize ? rawsz : vsize;
        memset(HP(final_base + va), 0, vsize);
        memcpy(HP(final_base + va), file + rawptr, n);
        uint32_t flags = rd32(sec + 36), lo = final_base + va, hi = lo + vsize;
        if (flags & 0x20000000u) {   /* IMAGE_SCN_MEM_EXECUTE */
            m->code_lo = m->code_lo ? m->code_lo : lo;
            if (hi > m->code_hi) m->code_hi = hi;
            if (g_code_hi == 0x401000 || lo < g_code_lo) g_code_lo = lo;
            if (hi > g_code_hi) g_code_hi = hi;
        } else if (flags & 0x80000000u) {   /* IMAGE_SCN_MEM_WRITE: .data, .data1, ... */
            if (!m->data_lo) m->data_lo = lo;
            if (hi > m->data_hi) m->data_hi = hi;
            if (!g_data_lo || lo < g_data_lo) g_data_lo = lo;
            if (hi > g_data_hi) g_data_hi = hi;
        }
    }
    if (m->data_lo) { m->data_lo &= ~7u; m->data_hi = (m->data_hi + 7) & ~7u; }
    g_data_lo = g_data_lo ? (g_data_lo & ~7u) : g_data_lo;
    g_data_hi = (g_data_hi + 7) & ~7u;

    /* Base relocations: the translator baked final addresses into the code, so when final != the
       preferred ImageBase every pointer the .reloc table lists shifts by the same delta. */
    if (delta) {
        uint32_t rel_rva = rd32(opt + 96 + 5 * 8), rel_size = rd32(opt + 96 + 5 * 8 + 4);   /* dir[5] */
        /* blocks are read from the mapped .reloc section: its file offset is not its RVA in general */
        for (uint32_t off = 0; rel_rva && off + 8 <= rel_size; ) {
            uint32_t page = R32(final_base + rel_rva + off), block = R32(final_base + rel_rva + off + 4);
            off += 8;
            if (!block) break;
            for (uint32_t e = 0; e + 2 <= block - 8 && off + 2 <= rel_size; e += 2, off += 2) {
                uint16_t t = rd16(HP(final_base + rel_rva + off)), h = t >> 12;
                uint32_t va = final_base + page + (t & 0xfff), v = R32(va);
                if (h == 1) W32(va, v + (((uint32_t)delta >> 16) << 16));          /* HIGH: 16-bit field */
                else if (h == 2) W32(va, (v & 0xffff0000) | (((v & 0xffff) + (uint32_t)delta) & 0xffff));
                else if (h == 3) W32(va, v + (uint32_t)delta);                     /* HIGHLOW */
            }
        }
    }

    if (exp_rva && exp_size) parse_exports(final_base, exp_rva, exp_size);

    /* Resolve imports: each IAT slot gets a magic address that dispatches to a host handler. */
    for (uint32_t d = final_base + imp_rva; R32(d + 12); d += 20) {
        const char *dll = (const char *)HP(final_base + R32(d + 12));
        uint32_t ilt = R32(d) ? R32(d) : R32(d + 16), iat = R32(d + 16);
        for (uint32_t k = 0;; k++) {
            uint32_t thunk = R32(final_base + ilt + 4 * k);
            if (!thunk) break;
            ImportSlot *s = &g_imports[g_nimports];
            if (thunk & 0x80000000u)
                snprintf(s->name, sizeof s->name, "%s!#%u", dll, thunk & 0xffff);
            else
                snprintf(s->name, sizeof s->name, "%s!%s", dll, (const char *)HP(final_base + thunk + 2));
            for (char *p = s->name; *p && *p != '!'; p++) *p = (char)toupper((unsigned char)*p);
            GuestFn fn = find_handler(s->name);
            s->fn = fn ? fn : unimplemented_import;
            uint32_t magic = IMPORT_BASE + g_nimports * 16;
            W32(final_base + iat + 4 * k, magic);
            register_function(magic, s->fn);
            g_nimports++;
        }
    }
    free(file);
    out->image_base = final_base;
    out->entry = final_base + entry;
    out->num_imports = g_nimports;
    return 0;
}
#ifdef PORT_TEST_IMAGE_IO
#undef fseek
#undef ftell
#undef malloc
#undef fread
#undef fclose
#endif

/* ------------------------------------------------------------------ memory + CPU setup */

void runtime_init(CPU *c) {
    /* +64 KiB so multi-byte accesses straddling 0xFFFFFFFF stay inside the mapping */
#ifdef __EMSCRIPTEN__
    g_mem = calloc(1, (size_t)GUEST_SPACE + 0x10000);
    if (!g_mem) { fprintf(stderr, "cannot allocate guest memory\n"); exit(1); }
#else
    g_mem = mmap(NULL, GUEST_SPACE + 0x10000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON | MAP_NORESERVE, -1, 0);
    if (g_mem == MAP_FAILED) { perror("mmap 4GiB guest space"); exit(1); }
#endif
    memset(c, 0, sizeof *c);
    c->esp = GUEST_STACK_TOP;
    c->fpu_cw = 0x027f; /* MSVC default: 53-bit precision, round to nearest, exceptions masked */
    fpu_sync_rounding(c);
    c->mxcsr = 0x1f80;
    c->fs_base = GUEST_TIB;
    W32(GUEST_TIB + 0x00, 0xffffffffu);    /* empty SEH chain */
    W32(GUEST_TIB + 0x18, GUEST_TIB);       /* self pointer */
    W32(GUEST_TIB + 0x04, GUEST_STACK_TOP); /* stack base */
    W32(GUEST_TIB + 0x08, GUEST_STACK_TOP - GUEST_STACK_SIZE);
}

uint32_t g_heap_next = GUEST_HEAP_BASE;

uint32_t guest_alloc(uint32_t size) {
    uint32_t a = (g_heap_next + 15) & ~15u;
    g_heap_next = a + size;
    return a;
}

/* Calls a recompiled function the way the original would be called: arguments are pushed
   right-to-left and a sentinel return address is pushed. The callee pops what its convention says. */
void guest_call(CPU *c, GuestFn fn, int nargs, const uint32_t *args) {
    for (int i = nargs - 1; i >= 0; i--) PUSH32(c, args[i]);
    PUSH32(c, GUEST_RETURN_SENTINEL);
    fn(c);
}
