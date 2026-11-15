/* Actual synchronous guest wrappers with an owned synthetic file. */
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
static int read_error,write_error,read_fail_after=-1,short_read;
static ssize_t probe_read(int fd,void *buffer,size_t size){
    if(read_error){int e=read_error;read_error=0;errno=e;return -1;}
    if(read_fail_after==0){read_fail_after=-1;errno=EIO;return -1;}
    if(read_fail_after>0)read_fail_after--;
    if(short_read && size>(size_t)short_read)size=(size_t)short_read;
    return read(fd,buffer,size);
}
static ssize_t probe_write(int fd,const void *buffer,size_t size){
    if(write_error){int e=write_error;write_error=0;errno=e;return -1;}
    return write(fd,buffer,size);
}
#include "../host/core.c"
#define read probe_read
#define write probe_write
#include "../host/kernel32.c"
#undef read
#undef write
uint8_t *g_mem;
static void args(CPU *c,uint32_t h,uint32_t count){
    c->esp=0x1000;W32(0x1000,0);W32(0x1004,h);W32(0x1008,0x3000);
    W32(0x100c,count);W32(0x1010,0x2000);W32(0x1014,0);
}
int main(void){
    g_mem=calloc(1,65536);assert(g_mem);GuestThread thread={0};t_self=&thread;CPU c={0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs",0777,wasmfs_create_opfs_backend()));
    char dir[]="/opfs/korsary-rw-XXXXXX";assert(mkdtemp(dir));
    char name[160];assert(snprintf(name,sizeof name,"%s/file-XXXXXX",dir)>0);
#else
    char name[]="/tmp/korsary-rw-XXXXXX";
#endif
    int fd=mkstemp(name);assert(fd>=0 && write(fd,"DATA",4)==4 && lseek(fd,0,SEEK_SET)==0);
    uint32_t h=handle_new(H_FILE);WinHandle *file=handle_get(h,H_FILE);assert(file);file->fd=fd;
    W32(0x2000,0x12345678);args(&c,0xdeadbeecu,1);w_ReadFile(&c);
    assert(!c.eax && thread.last_error==ERROR_INVALID_HANDLE && R32(0x2000)==0);
    W32(0x2000,0x12345678);args(&c,0xdeadbeecu,1);w_WriteFile(&c);
    assert(!c.eax && thread.last_error==ERROR_INVALID_HANDLE && R32(0x2000)==0);
    args(&c,h,1);W32(0x1010,0xffffffffu);w_ReadFile(&c);assert(!c.eax && thread.last_error==998);
    args(&c,h,1);W32(0x1010,0xffffffffu);w_WriteFile(&c);assert(!c.eax && thread.last_error==998);
    args(&c,h,2);W32(0x1008,(uint32_t)(GUEST_SPACE-1));w_ReadFile(&c);
    assert(!c.eax && thread.last_error==998 && R32(0x2000)==0);
    args(&c,h,2);W32(0x1008,(uint32_t)(GUEST_SPACE-1));w_WriteFile(&c);
    assert(!c.eax && thread.last_error==998 && R32(0x2000)==0);
    args(&c,h,1);W32(0x1008,0);w_ReadFile(&c);assert(!c.eax && thread.last_error==998 && R32(0x2000)==0);
    args(&c,h,1);W32(0x1008,0);w_WriteFile(&c);assert(!c.eax && thread.last_error==998 && R32(0x2000)==0);
    args(&c,STD_OUT,2);W32(0x1008,(uint32_t)(GUEST_SPACE-1));w_WriteFile(&c);
    assert(!c.eax && thread.last_error==998 && R32(0x2000)==0);
    read_error=EINTR;short_read=2;args(&c,h,6);w_ReadFile(&c);
    assert(c.eax==1 && R32(0x2000)==4 && !memcmp(HP(0x3000),"DATA",4));
    args(&c,h,1);w_ReadFile(&c);assert(c.eax==1 && R32(0x2000)==0); /* EOF */
    assert(lseek(fd,0,SEEK_SET)==0);read_fail_after=1;args(&c,h,4);w_ReadFile(&c);
    assert(!c.eax && R32(0x2000)==2 && thread.last_error==30);
    short_read=0;assert(lseek(fd,0,SEEK_SET)==0);memcpy(HP(0x3000),"NEW!",4);
    write_error=EINTR;args(&c,h,4);w_WriteFile(&c);assert(c.eax==1 && R32(0x2000)==4);
    write_error=ENOSPC;args(&c,h,1);w_WriteFile(&c);assert(!c.eax && thread.last_error==ERROR_DISK_FULL && R32(0x2000)==0);
    write_error=EBADF;args(&c,h,1);w_WriteFile(&c);assert(!c.eax && thread.last_error==ERROR_INVALID_HANDLE && R32(0x2000)==0);
    handle_close(h);assert(!unlink(name));free(g_mem);puts("ReadFile/WriteFile: synchronous errors and EOF PASS");
}
