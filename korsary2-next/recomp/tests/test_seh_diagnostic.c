#include "seh_diagnostic.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
/* Граничные случаи только-чтения seh_diag_*: диагностика печатает имя типа C++-исключения
   перед терминальным trap RaiseException и не принимает решений об обработке исключения.
   Тест проверяет, что повреждённая гостевая metadata не приводит к чтению за пределами
   буфера, не изменяет память и не возвращает неограниченную строку. */
static unsigned char mem[1024];
static unsigned char pristine[1024];
static void w(unsigned p,unsigned v) { for(unsigned i=0;i<4;i++) mem[p+i]=(unsigned char)(v>>(8*i)); }
/* args=0x100 -> info=0x200 -> array=0x20c -> {count=0x240, type=0x244} -> descriptor 0x284 -> name at 0x308 */
static void good(const char *name) {
    memset(mem,0,sizeof mem);
    w(0x108,0x200); w(0x20c,0x240); w(0x240,1);
    w(0x244,0x280); w(0x284,0x300); memcpy(mem+0x308,name,strlen(name)+1);
}
int main(void) {
    char name[32];
    good(".PAD");
    memcpy(pristine,mem,sizeof mem);
    assert(seh_diag_type(mem,sizeof mem,0x100,name,sizeof name) && !strcmp(name,".PAD"));
    assert(!memcmp(mem,pristine,sizeof mem));                          /* read-only */
    assert(!seh_diag_type(mem,sizeof mem,0,name,sizeof name));
    assert(!seh_diag_type(mem,sizeof mem,UINT32_MAX-1,name,sizeof name));
    assert(!seh_diag_type(mem,sizeof mem,UINT32_MAX-7,name,sizeof name));   /* args+8 переполняет uint32 */
    assert(!seh_diag_type(mem,sizeof mem,sizeof mem-8,name,sizeof name));   /* поле info за пределами */
    assert(!seh_diag_type(NULL,sizeof mem,0x100,name,sizeof name));
    assert(!seh_diag_type(mem,sizeof mem,0x100,NULL,sizeof name));
    assert(!seh_diag_type(mem,sizeof mem,0x100,name,0));
    assert(!seh_diag_type(mem,sizeof mem,0x100,name,1));
    assert(!seh_diag_type(mem,0,0x100,name,sizeof name));
    /* каждое звено цепочки args->info->array->type->descriptor по отдельности */
    w(0x108,0); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name)); w(0x108,0x200);
    w(0x20c,0); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name)); w(0x20c,0x240);
    w(0x240,0); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));
    w(0x240,129); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));
    w(0x240,128); assert(seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));
    w(0x240,1);
    w(0x244,0); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name)); w(0x244,0x280);
    w(0x284,0); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));
    w(0x284,UINT32_MAX); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));
    w(0x284,UINT32_MAX-7); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));   /* descriptor+8 == UINT32_MAX */
    w(0x284,sizeof mem); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));     /* имя за концом памяти */
    w(0x284,0x300);
    /* указатели вне памяти на каждом уровне */
    w(0x108,sizeof mem); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name)); w(0x108,0x200);
    w(0x20c,sizeof mem-8); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name)); w(0x20c,0x240);
    w(0x244,sizeof mem); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name)); w(0x244,0x280);
    /* границы буфера имени: влезает ровно с терминатором / не влезает */
    good("abcdefg");  /* 7 символов */
    assert(seh_diag_type(mem,sizeof mem,0x100,name,8) && !strcmp(name,"abcdefg") && name[7]==0);
    assert(!seh_diag_type(mem,sizeof mem,0x100,name,7));
    good(""); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));                /* пустое имя — не тип */
    memset(mem+0x308,'X',32); assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));/* нет терминатора */
    /* имя, упирающееся в конец памяти: терминатор в последнем байте принимается, без него — отказ */
    good(".PAD"); w(0x284,sizeof mem-9); mem[sizeof mem-1]=0;
    assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));                          /* первый же байт — терминатор */
    w(0x284,sizeof mem-10); mem[sizeof mem-2]='A'; mem[sizeof mem-1]=0;
    assert(seh_diag_type(mem,sizeof mem,0x100,name,sizeof name) && !strcmp(name,"A"));
    mem[sizeof mem-1]='B';
    assert(!seh_diag_type(mem,sizeof mem,0x100,name,sizeof name));                          /* терминатора нет до конца памяти */
    /* seh_diag_word / seh_diag_field */
    uint32_t v = 0xdeadbeef;
    assert(!seh_diag_word(NULL,sizeof mem,0,&v) && !seh_diag_word(mem,sizeof mem,0,NULL));
    assert(seh_diag_word(mem,sizeof mem,sizeof mem-4,&v));
    assert(!seh_diag_word(mem,sizeof mem,sizeof mem-3,&v));
    assert(!seh_diag_word(mem,sizeof mem,UINT32_MAX,&v));
    assert(!seh_diag_field(mem,sizeof mem,UINT32_MAX-3,8,&v));
    assert(!seh_diag_field(mem,sizeof mem,UINT32_MAX,UINT32_MAX,&v));
    puts("SEH diagnostic: bounded metadata and type name passed");
}
