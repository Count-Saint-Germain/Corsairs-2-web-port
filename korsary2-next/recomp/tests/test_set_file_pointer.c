/* Exercise the actual guest wrapper, using only an owned temporary file. */
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
static int inject_error,inject_boundary;
static off_t test_lseek(int fd,off_t offset,int whence) {
    if(inject_error){int e=inject_error;inject_error=0;errno=e;return -1;}
    if(inject_boundary){inject_boundary=0;return (off_t)UINT32_MAX;}
    return lseek(fd,offset,whence);
}
#include "../host/core.c"
#define lseek test_lseek
#include "../host/kernel32.c"
#undef lseek
uint8_t *g_mem;
static void seek_call(CPU *c,uint32_t h,uint32_t low,uint32_t high,uint32_t method) {
    c->esp=0x1000;W32(0x1000,0);W32(0x1004,h);W32(0x1008,low);W32(0x100c,high);W32(0x1010,method);
    w_SetFilePointer(c);
}
int main(void) {
    g_mem=calloc(1,65536);assert(g_mem);GuestThread thread={0};t_self=&thread;CPU c={0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs",0777,wasmfs_create_opfs_backend()));
    char dir[]="/opfs/korsary-seek-XXXXXX";assert(mkdtemp(dir));
    char name[160];assert(snprintf(name,sizeof name,"%s/file-XXXXXX",dir)>0);
#else
    char name[]="/tmp/korsary-seek-XXXXXX";
#endif
    int fd=mkstemp(name);assert(fd>=0);
    assert(write(fd,"DATA",4)==4 && lseek(fd,2,SEEK_SET)==2);
    uint32_t h=handle_new(H_FILE);WinHandle *file=handle_get(h,H_FILE);assert(file);file->fd=fd;
    W32(0x2000,0);seek_call(&c,h,0,0x2000,3);
    assert(c.eax==0xffffffffu && thread.last_error==87 && R32(0x2000)==0 && lseek(fd,0,SEEK_CUR)==2);
    for(uint32_t method=0;method<=2;method++){
        W32(0x2000,0xffffffffu);seek_call(&c,h,(uint32_t)-5,0x2000,method);
        assert(c.eax==0xffffffffu && thread.last_error==131 && R32(0x2000)==0xffffffffu && lseek(fd,0,SEEK_CUR)==2);
    }
    thread.last_error=0x1234;seek_call(&c,h,3,0,0);
    assert(c.eax==3 && thread.last_error==0x1234 && lseek(fd,0,SEEK_CUR)==3);
    W32(0x2000,0);inject_boundary=1;thread.last_error=0x1234;seek_call(&c,h,0,0x2000,0);
    assert(c.eax==0xffffffffu && thread.last_error==0 && R32(0x2000)==0);
    W32(0x2000,0x12345678);inject_error=EIO;seek_call(&c,h,0,0x2000,0);
    assert(c.eax==0xffffffffu && thread.last_error==30 && R32(0x2000)==0x12345678);
    inject_error=EBADF;seek_call(&c,h,0,0,0);assert(c.eax==0xffffffffu && thread.last_error==ERROR_INVALID_HANDLE);
    seek_call(&c,0xdeadbeecu,0,0,0);assert(c.eax==0xffffffffu && thread.last_error==ERROR_INVALID_HANDLE);
    handle_close(h);assert(!unlink(name));free(g_mem);puts("SetFilePointer: validation and error handling PASS");
}
