#ifndef PORT_RUNTIME_H
#define PORT_RUNTIME_H

#include "cpu.h"
#include <ctype.h>
#include <setjmp.h>

extern jmp_buf *g_trap_jmp;
extern char g_trap_msg[256];

/* Guest address-space layout (the image normally sits at 0x00400000 and up). */
#define GUEST_TIB              0x00010000u
#define GUEST_STACK_TOP        0x00300000u
#define GUEST_STACK_SIZE       0x00200000u
#define GUEST_HEAP_BASE        0x10000000u
/* Natively the guest gets a full 4 GiB reservation. In the browser (wasm32) it must share a 4 GiB
   memory with everything else, so the heap and VirtualAlloc ranges are compacted: the game peaks at
   ~125 MB of heap and ~580 MB of virtual allocations (mostly mapped archives). */
#ifdef __EMSCRIPTEN__
#define GUEST_SPACE            0x50000000ull
#define GUEST_HEAP_HI          0x20000000u
#define GUEST_VALLOC_LO        0x20000000u
#define GUEST_VALLOC_HI        0x50000000u
#else
#define GUEST_SPACE            0x100000000ull
#define GUEST_HEAP_HI          0x60000000u
#define GUEST_VALLOC_LO        0x60000000u
#define GUEST_VALLOC_HI        0xE0000000u
#endif
#define GUEST_RETURN_SENTINEL  0xDEADBEEFu

typedef struct { const char *name; GuestFn fn; } ImportHandler;  /* name like "KERNEL32.DLL!GetTickCount" */
typedef struct { uint32_t image_base, entry, num_imports; } LoadedImage;
/* Filled by load_image for every image it maps: the code sections (the exe and each guest module) and
   the writable sections (global data, hashed by the determinism checks) — the union over all images. */
extern uint32_t g_code_lo, g_code_hi, g_data_lo, g_data_hi;
static inline int looks_like_code(uint32_t v) { return v >= g_code_lo && v < g_code_hi; }

void runtime_init(CPU *c);
void set_import_handlers(ImportHandler *h, uint32_t n);  /* call before load_image */
/* base 0 maps at the image's preferred ImageBase; otherwise the image is placed exactly there and its
   .reloc entries are rewritten when that differs from the preferred base (translated code bakes in
   final addresses, so the loader must use the base the translator was told). */
int load_image(const char *path, uint32_t base, LoadedImage *out);
/* LoadLibraryA/GetModuleHandleA resolve against these names ("MODULES\\X.dll"); a loaded guest module
   is identified by its image base, since every module is mapped at startup. */
void module_set_name(uint32_t base, const char *name);
uint32_t guest_module_base(const char *name);            /* 0 when unknown */
/* Run the image's entry point with DLL_PROCESS_ATTACH (CRT init, C++ constructors), once per module.
   Windows does this when LoadLibrary maps the DLL; without it module globals stay uninitialized. */
int guest_module_attach(uint32_t base, CPU *c);
/* One export of the image at `base`, by name or ordinal (Windows ordinals are 1-based; name = NULL
   means ordinal). Returns 1 and sets *addr when found. */
int guest_export_lookup(uint32_t base, const char *name, uint32_t ordinal, uint32_t *addr);
GuestFn lookup_function(uint32_t addr);
const char *import_name(uint32_t addr);
uint32_t add_dynamic_import(const char *name, GuestFn fn);   /* for GetProcAddress */
GuestFn find_import_handler(const char *name);
extern __thread uint32_t g_import_target;  /* host slot selected by indirect call or tail jump */
uint32_t guest_alloc(uint32_t size);
void guest_call(CPU *c, GuestFn fn, int nargs, const uint32_t *args);
void register_all_functions(void);  /* generated */

/* Code created at run time (AEMS sound modules): interpreted, see interp.c */
void dyncode_register(uint32_t addr, uint32_t len);
int dyncode_contains(uint32_t addr);
void interp_call(CPU *c, uint32_t eip);   /* return address already pushed */

typedef struct { uint32_t addr; uint32_t regs[8]; double st0; uint32_t top; } TraceRec;
extern TraceRec *g_trace;          /* set by a test harness to record every instruction */
extern uint32_t g_trace_len, g_trace_cap;

#endif
