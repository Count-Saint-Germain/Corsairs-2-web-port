/* Exercises the actual guest wrapper on an owned synthetic file. */
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
static int inject_error,inject_size;
static uint64_t synthetic_size;
static int test_fstat(int fd,struct stat *st){
    if(inject_error){int e=inject_error;inject_error=0;errno=e;return -1;}
    if(inject_size){inject_size=0;memset(st,0,sizeof *st);st->st_size=(off_t)synthetic_size;return 0;}
    return fstat(fd,st);
}
#include "../host/core.c"
#define fstat test_fstat
#include "../host/kernel32.c"
#undef fstat
uint8_t *g_mem;
static void size_call(CPU *c,uint32_t h,uint32_t high){
    c->esp=0x1000;W32(0x1000,0);W32(0x1004,h);W32(0x1008,high);w_GetFileSize(c);
}
int main(void){
    g_mem=calloc(1,65536);assert(g_mem);GuestThread thread={0};t_self=&thread;CPU c={0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs",0777,wasmfs_create_opfs_backend()));
    char dir[]="/opfs/korsary-size-XXXXXX";assert(mkdtemp(dir));
    char name[160];assert(snprintf(name,sizeof name,"%s/file-XXXXXX",dir)>0);
#else
    char name[]="/tmp/korsary-size-XXXXXX";
#endif
    int fd=mkstemp(name);assert(fd>=0 && write(fd,"DATA",4)==4);
    uint32_t h=handle_new(H_FILE);WinHandle *file=handle_get(h,H_FILE);assert(file);file->fd=fd;
    W32(0x2000,0x12345678);thread.last_error=0x1234;size_call(&c,0xdeadbeecu,0x2000);
    assert(c.eax==0xffffffffu && thread.last_error==ERROR_INVALID_HANDLE && R32(0x2000)==0x12345678);
    size_call(&c,h,0x2000);assert(c.eax==4 && R32(0x2000)==0);
    W32(0x2000,0x12345678);inject_error=EIO;size_call(&c,h,0x2000);
    assert(c.eax==0xffffffffu && thread.last_error==30 && R32(0x2000)==0x12345678);
    inject_error=EBADF;size_call(&c,h,0);assert(c.eax==0xffffffffu && thread.last_error==ERROR_INVALID_HANDLE);
    inject_size=1;synthetic_size=UINT32_MAX;thread.last_error=0x1234;size_call(&c,h,0x2000);
    assert(c.eax==0xffffffffu && R32(0x2000)==0 && thread.last_error==0);
    inject_size=1;synthetic_size=UINT64_C(0x100000002);size_call(&c,h,0x2000);
    assert(c.eax==2 && R32(0x2000)==1);
    handle_close(h);assert(!unlink(name));free(g_mem);puts("GetFileSize: validation and error handling PASS");
}
