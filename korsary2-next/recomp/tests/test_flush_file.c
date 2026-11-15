/* Exercises the real Win32 wrapper with actual temporary files and a
   controllable fsync wrapper. No game file or browser is touched. */
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
static int sync_calls, injected_errno, remaining_failures;
static int test_fsync(int fd) {
    sync_calls++;
    if (remaining_failures) { remaining_failures--; errno=injected_errno; return -1; }
    return fsync(fd);
}
#include "../host/core.c"
#define fsync test_fsync
#include "../host/kernel32.c"
#undef fsync
uint8_t *g_mem;
static void arg(CPU *c,uint32_t h) { c->esp=0x1000; W32(0x1000,0xfeedbeef); W32(0x1004,h); }
int main(void) {
    g_mem=calloc(1,65536); assert(g_mem);
    GuestThread thread={0}; t_self=&thread;
    CPU c={0}; arg(&c,0xdeadbeef); w_FlushFileBuffers(&c);
    assert(c.eax==0 && c.esp==0x1008 && thread.last_error==ERROR_INVALID_HANDLE && sync_calls==0);
    char name[]="/tmp/korsary-flush-XXXXXX"; int fd=mkstemp(name); assert(fd>=0);
    assert(write(fd,"save data",9)==9);
    uint32_t h=handle_new(H_FILE); WinHandle *x=handle_get(h,H_FILE); assert(x); x->fd=fd;
    thread.last_error=0x1234; arg(&c,h); w_FlushFileBuffers(&c);
    assert(c.eax==1 && c.esp==0x1008 && sync_calls==1 && thread.last_error==0x1234);
    injected_errno=EINTR; remaining_failures=1; arg(&c,h); w_FlushFileBuffers(&c);
    assert(c.eax==1 && sync_calls==3);
    injected_errno=ENOSPC; remaining_failures=1; arg(&c,h); w_FlushFileBuffers(&c);
    assert(c.eax==0 && thread.last_error==112);
    injected_errno=EIO; remaining_failures=1; arg(&c,h); w_FlushFileBuffers(&c);
    assert(c.eax==0 && thread.last_error==29);
    assert(close(fd)==0); arg(&c,h); w_FlushFileBuffers(&c);
    assert(c.eax==0 && thread.last_error==ERROR_INVALID_HANDLE);
    x->fd=-1; handle_close(h); assert(!unlink(name)); free(g_mem);
    puts("FlushFileBuffers: file fsync, retry, handle/error propagation passed");
}
