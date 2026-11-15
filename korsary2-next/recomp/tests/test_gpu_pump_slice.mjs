// Compile the real browser queue executor against a deterministic clock/GPU shim.
import { test } from 'node:test';
import { readFile, mkdtemp, writeFile, rm } from 'node:fs/promises';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import { execFileSync } from 'node:child_process';

test('GPU pump yields, resumes in order, and preserves frame and readback boundaries', async () => {
  const source = await readFile(new URL('../host/render_wgpu.c', import.meta.url), 'utf8');
  const begin = source.indexOf('static int run_chunk(Chunk *ch, double deadline_ms)');
  const end = source.indexOf('EMSCRIPTEN_KEEPALIVE void port_set_canvas_size', begin);
  if (begin < 0 || end < 0) throw new Error('Cannot locate the browser GPU pump');
  const dir = await mkdtemp(join(tmpdir(), 'corsairs-pump-test-'));
  const prelude = String.raw`
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#define EMSCRIPTEN_KEEPALIVE
enum { CMD_TARGET=1, CMD_CLEAR, CMD_DRAW, CMD_UPLOAD_TEX, CMD_DESTROY_TEX,
       CMD_UPLOAD_SURF, CMD_DESTROY_SURF, CMD_READBACK, CMD_PRESENT,
       CMD_COPY_CUBE_RT, CMD_UPLOAD_TEX_REGION };
typedef struct { uint32_t type, size, id; } CmdHdr;
typedef CmdHdr CmdTarget, CmdClear, CmdDraw, CmdUploadTex, CmdUploadTexRegion,
  CmdCopyCubeRT, CmdDestroy, CmdUploadSurf, CmdPresent, CmdReadback;
typedef struct Chunk { uint8_t *buf; size_t len, off; int ends_frame; struct Chunk *next; } Chunk;
static Chunk *g_q_head, *g_q_tail;
static int g_q_chunks, g_q_frames, g_ready=1, g_rb_pending;
static pthread_mutex_t g_q_lock=PTHREAD_MUTEX_INITIALIZER;
static double now_ms;
static unsigned seen[256], count;
static double emscripten_get_now(void) { return now_ms; }
static void record(const CmdHdr *c) { seen[count++]=c->id; now_ms+=1.5; }
#define EXEC(name, type) static void name(const type *c) { record(c); }
EXEC(exec_target, CmdTarget) EXEC(exec_clear, CmdClear) EXEC(exec_draw, CmdDraw)
EXEC(exec_upload_tex, CmdUploadTex) EXEC(exec_upload_tex_region, CmdUploadTexRegion)
EXEC(exec_copy_cube_rt, CmdCopyCubeRT) EXEC(exec_upload_surf, CmdUploadSurf)
EXEC(exec_present, CmdPresent)
static void exec_destroy(uint32_t id, int surface) { (void)surface; seen[count++]=id; now_ms+=1.5; }
typedef void *WGPUBuffer;
typedef struct { int mode; void (*callback)(void); } WGPUBufferMapCallbackInfo;
#define WGPU_BUFFER_MAP_CALLBACK_INFO_INIT {0}
#define WGPUCallbackMode_AllowSpontaneous 1
#define WGPUMapMode_Read 1
static int g_rb_gw, g_rb_gh, g_rb_stride;
static CmdReadback g_rb_cmd;
static WGPUBuffer g_rb_buf;
static void on_rb_mapped(void) {}
static WGPUBuffer start_readback(const CmdReadback *c, int *w, int *h, int *stride, int *status) {
  (void)c; *w=*h=*stride=1; *status=1; return (void *)1;
}
static void finish_readback(const CmdReadback *c, int ok) { (void)c; (void)ok; }
static void wgpuBufferMapAsync(WGPUBuffer b, int mode, int off, uint64_t size, WGPUBufferMapCallbackInfo cb) {
  (void)b; (void)mode; (void)off; (void)size; (void)cb;
}
`;
  const checks = String.raw`
static void queue(unsigned n, int frame, unsigned base, int readback) {
  Chunk *c=calloc(1,sizeof *c); c->len=n*sizeof(CmdHdr); c->ends_frame=frame;
  c->buf=calloc(n,sizeof(CmdHdr)); CmdHdr *cmd=(CmdHdr *)c->buf;
  for (unsigned i=0;i<n;i++) cmd[i]=(CmdHdr){(readback && i==1)?CMD_READBACK:CMD_DRAW,sizeof(CmdHdr),base+i};
  if (g_q_tail) g_q_tail->next=c; else g_q_head=c;
  g_q_tail=c; g_q_chunks++; g_q_frames+=frame;
}
int main(void) {
  queue(15,0,0,0);
  assert(port_gpu_pump(0)==0 && g_q_head && g_q_head->off>0 && g_q_head->off<g_q_head->len);
  for (int i=0;g_q_head && i<20;i++) port_gpu_pump(0);
  assert(!g_q_head && !g_q_tail && !g_q_chunks && count==15);
  for (unsigned i=0;i<15;i++) assert(seen[i]==i);
  count=0; now_ms=0;
  for (unsigned i=0;i<12;i++) queue(1,0,i,0);
  port_gpu_pump(0); assert(g_q_head && count>0 && count<12);
  for (int i=0;g_q_head && i<20;i++) port_gpu_pump(0);
  assert(!g_q_head && count==12);
  for (unsigned i=0;i<12;i++) assert(seen[i]==i);
  count=0; now_ms=0; queue(10,1,0,0);
  assert(!port_gpu_pump(0) && count==0 && g_q_frames==1);
  assert(port_gpu_pump(1)==1 && count==10 && !g_q_head && !g_q_frames);
  count=0; now_ms=0; queue(3,0,0,1);
  port_gpu_pump(0); assert(g_rb_pending && count==1 && g_q_head);
  port_gpu_pump(0); assert(count==1 && g_q_head);
  g_rb_pending=0; port_gpu_pump(0);
  assert(!g_q_head && count==2 && seen[0]==0 && seen[1]==2);
  return 0;
}
`;
  try {
    const file = join(dir, 'pump.c');
    await writeFile(file, prelude + source.slice(begin, end) + checks);
    execFileSync(process.env.CC || 'cc', ['-std=c11', '-Wall', '-Wextra', '-pthread', file, '-o', join(dir, 'pump')], { stdio: 'pipe' });
    execFileSync(join(dir, 'pump'), { stdio: 'pipe' });
  } finally {
    await rm(dir, { recursive: true, force: true });
  }
});
