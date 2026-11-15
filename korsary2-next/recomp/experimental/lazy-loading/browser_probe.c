#include <emscripten/wasmfs.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <emscripten.h>
#include "lazy_bridge.h"

static void probe(const char *phase) {
  struct stat s;
  errno = 0;
  int result = stat("/opfs/lazytest/sub/LiveFile.txt", &s);
  int e = errno;
  FILE *f = fopen("/opfs/lazytest/sub/LiveFile.txt", "rb");
  char buf[16] = {0};
  int n = f ? fread(buf, 1, sizeof(buf)-1, f) : -1;
  if(f) fclose(f);
  DIR *d = opendir("/opfs/lazytest/sub");
  int found = 0;
  if(d) { struct dirent *entry; while((entry = readdir(d))) if(!strcmp(entry->d_name,"LiveFile.txt")) found=1; closedir(d); }
  printf("PROBE %s stat=%d errno=%d read=%d bytes=%s listed=%d\n", phase,result,e,n,buf,found);
  fflush(stdout);
}
int main(void) {
  wasmfs_create_directory("/opfs", 0777, wasmfs_create_opfs_backend());
  probe("before");
  if(!port_lazy_request("RESOURCE/sub/LiveFile.txt",10000)) {puts("PROBE request failed");return 1;}
  probe("after");
  return 0;
}
