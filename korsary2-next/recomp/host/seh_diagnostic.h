#ifndef PORT_SEH_DIAGNOSTIC_H
#define PORT_SEH_DIAGNOSTIC_H

#include <stddef.h>
#include <stdint.h>

/* Read-only, bounded C++ exception type diagnostic. This never decides that
   an exception was handled. Guest memory is contiguous over `size` bytes. */
static inline int seh_diag_word(const uint8_t *mem, uint64_t size, uint32_t p, uint32_t *out) {
    if (!mem || !out || (uint64_t)p+4>size) return 0;
    *out=(uint32_t)mem[p] | (uint32_t)mem[p+1]<<8 | (uint32_t)mem[p+2]<<16 | (uint32_t)mem[p+3]<<24;
    return 1;
}
static inline int seh_diag_field(const uint8_t *mem, uint64_t size, uint32_t p, uint32_t offset, uint32_t *out) {
    if ((uint64_t)p+offset>UINT32_MAX) return 0;
    return seh_diag_word(mem,size,p+offset,out);
}
static inline int seh_diag_type(const uint8_t *mem, uint64_t size, uint32_t args,
                                char *name, size_t capacity) {
    uint32_t info, array, count, type, descriptor;
    if (!name || capacity<2 || !args || !seh_diag_field(mem,size,args,8,&info) || !info ||
        !seh_diag_field(mem,size,info,12,&array) || !array ||
        !seh_diag_word(mem,size,array,&count) || !count || count>128 ||
        !seh_diag_field(mem,size,array,4,&type) || !type ||
        !seh_diag_field(mem,size,type,4,&descriptor) || !descriptor ||
        (uint64_t)descriptor+8>UINT32_MAX) return 0;
    uint64_t p=(uint64_t)descriptor+8;
    for (size_t i=0;i<capacity;i++,p++) {
        if (p>=size || p>UINT32_MAX) return 0;
        name[i]=(char)mem[p];
        if (!name[i]) return i!=0;
    }
    return 0;
}
#endif
