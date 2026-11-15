/* Synthetic files only: a refused move must never overwrite either path.
   Browser/WasmFS builds stay fail-closed ERROR_NOT_SUPPORTED; native and Node/NODERAWFS
   implement atomic no-replace (ERROR_ALREADY_EXISTS on an existing destination), see
   test_move_file_noreplace.c. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef TEST_OPFS
#include <emscripten/wasmfs.h>
#endif
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;
static void put(const char *path,const char *value){FILE *f=fopen(path,"wb");assert(f && fputs(value,f)>=0 && !fclose(f));}
static void has(const char *path,const char *value){char b[64]={0};FILE *f=fopen(path,"rb");assert(f);size_t n=fread(b,1,sizeof b,f);assert(!fclose(f));assert(n==strlen(value) && !memcmp(b,value,n));}
static void move_call(CPU *c,const char *a,const char *b){
    strcpy((char*)HP(0x2000),a);strcpy((char*)HP(0x2400),b);c->esp=0x1000;
    W32(0x1000,0);W32(0x1004,0x2000);W32(0x1008,0x2400);w_MoveFileA(c);
}
int main(void){
    g_mem=calloc(1,65536);assert(g_mem);GuestThread thread={0};t_self=&thread;CPU c={0};
#ifdef TEST_OPFS
    assert(!wasmfs_create_directory("/opfs",0777,wasmfs_create_opfs_backend()));
    char root[]="/opfs/korsary-move-safe-XXXXXX";
#else
    char root[]="/tmp/korsary-move-safe-XXXXXX";
#endif
    assert(mkdtemp(root));snprintf(g_game_root,sizeof g_game_root,"%s",root);
    char a[256],b[256],newname[256];snprintf(a,sizeof a,"%s/source",root);
    snprintf(b,sizeof b,"%s/existing",root);snprintf(newname,sizeof newname,"%s/absent",root);
    put(a,"SOURCE");put(b,"KEEP");
#if defined(__EMSCRIPTEN__) && !defined(PORT_NODE_BUILD)
    move_call(&c,"source","existing");assert(!c.eax && thread.last_error==50);has(a,"SOURCE");has(b,"KEEP");
    move_call(&c,"source","absent");assert(!c.eax && thread.last_error==50);has(a,"SOURCE");assert(access(newname,F_OK));
    c.esp=0x1000;W32(0x1004,0xffffffffu);W32(0x1008,0xffffffffu);
    w_MoveFileA(&c);assert(!c.eax && thread.last_error==50);has(a,"SOURCE");has(b,"KEEP");
    assert(!unlink(a));
#else
    /* An existing destination refuses without touching either file. */
    move_call(&c,"source","existing");assert(!c.eax && thread.last_error==ERROR_ALREADY_EXISTS);has(a,"SOURCE");has(b,"KEEP");
#ifdef __EMSCRIPTEN__   /* Node build: GUEST_SPACE rejects top-of-space pointers before any deref.
                           Natively any 32-bit pointer sits inside the 4 GiB reservation, so this
                           check is vacuous there and the 64 KiB test allocation cannot host it. */
    c.esp=0x1000;W32(0x1004,0xffffffffu);W32(0x1008,0xffffffffu);
    w_MoveFileA(&c);assert(!c.eax && thread.last_error==87);has(a,"SOURCE");has(b,"KEEP");
#endif
    /* An absent destination moves (covered in depth by test_move_file_noreplace.c). */
    move_call(&c,"source","absent");assert(c.eax==1);has(newname,"SOURCE");assert(access(a,F_OK));
    assert(!unlink(newname));
#endif
    assert(!unlink(b));
#ifndef TEST_OPFS
    assert(!rmdir(root));
#endif
    free(g_mem);puts("MoveFileA: destination never overwritten PASS");
}
