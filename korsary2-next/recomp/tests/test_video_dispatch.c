/* Видеомост: реальный диспетчер call_indirect (runtime/runtime.c) вызывает host/video.c на адресе возврата
   0xae77fd (MultiByteToWideChar в open-методе CAviPlayer) и на трёх диагностических адресах ExecuteFunction,
   и не меняет само исполнение вызова. Без PORT_NODE_BUILD (браузерная сборка) хук обязан сработать; с
   PORT_NODE_BUILD он вырезан — запроса нет. Кадр точки перехвата собран по переводу f_00ae77d0. */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../host/video.c"

int dyncode_contains(uint32_t a) { (void)a; return 0; }
void interp_call(CPU *c, uint32_t a) { (void)c; (void)a; abort(); }

static int target_runs, target_esp;
static void target(CPU *c) { target_runs++; target_esp = (int)c->esp; c->esp += 4; }   /* как ret */

#define TARGET 0x00500000u
#define STACK 0x1000u
#define NAME 0x2000u
static void open_frame(CPU *c, uint32_t ret, const char *path) {
    memset(c, 0, sizeof *c);
    strcpy((char *)HP(NAME), path);
    c->esp = STACK;
    W32(STACK + 0x00, ret);
    W32(STACK + 0x04, 0); W32(STACK + 0x08, 0); W32(STACK + 0x0c, NAME);
    W32(STACK + 0x10, 0xffffffffu); W32(STACK + 0x14, 0x3000u); W32(STACK + 0x18, 0x104);
}
static void trace_frame(CPU *c, uint32_t ret, uint32_t fmt, const char *name) {
    memset(c, 0, sizeof *c);
    strcpy((char *)HP(NAME), name);
    c->esp = STACK;
    W32(STACK + 0, ret); W32(STACK + 4, 0x475a08u); W32(STACK + 8, fmt); W32(STACK + 12, NAME);
}

int main(void) {
    g_mem = calloc(1, 0x100000);
    assert(g_mem);
    register_function(TARGET, target);
    setenv("PORT_VIDEO_NOWAIT", "1", 1);   /* без живой страницы игру не паркуем; ожидание проверено в test_video_bridge */
    CPU c;
#ifdef PORT_NODE_BUILD
    const int bridged = 0;
#else
    const int bridged = 1;
#endif
    /* 1. Реальная точка: MultiByteToWideChar внутри open-метода CAviPlayer */
    int before = target_runs;
    open_frame(&c, AVI_OPEN_MBTOWC_RETURN, "resource\\videos\\Trailer.wmv");
    call_indirect(&c, TARGET);
    assert(target_runs == before + 1 && target_esp == STACK);   /* вызов исполнился ровно один раз, стек как был */
    assert(c.esp == STACK + 4);
    assert((port_video_poll(0, 0) != 0) == bridged);
    if (bridged) {
        char name[VIDEO_NAME_CAP];
        assert(port_video_poll(name, sizeof name) == 7 && strcmp(name, "trailer") == 0);
    }
    port_video_done(1);

    /* 2. Диагностические адреса VM (старый хук): вызов исполняется, запроса нет даже с именем StartPostVideo */
    static const struct { uint32_t ra, fmt; } sites[] = {
        { VM_TRACE_INVALID_FUNCTION, 0x46030cu }, { VM_TRACE_NOT_FOUND, 0x460700u }, { VM_TRACE_IS_IMPORTED, 0x46035cu },
    };
    for (unsigned i = 0; i < 3; i++) {
        before = target_runs;
        trace_frame(&c, sites[i].ra, sites[i].fmt, "StartPostVideo");
        call_indirect(&c, TARGET);
        assert(target_runs == before + 1 && target_esp == STACK && c.esp == STACK + 4);
        assert(port_video_poll(0, 0) == 0);
    }
    /* 3. Посторонний адрес возврата с тем же кадром: хук не вызывается */
    open_frame(&c, 0x00401000u, "resource\\videos\\trailer.wmv");
    call_indirect(&c, TARGET);
    assert(port_video_poll(0, 0) == 0);
    /* 4. Адрес возврата точки, но кадр не про видео (не те аргументы или не файл): запроса нет, вызов исполняется */
    before = target_runs;
    open_frame(&c, AVI_OPEN_MBTOWC_RETURN, "resource\\videos\\trailer.wmv"); W32(STACK + 0x18, 0x80);
    call_indirect(&c, TARGET);
    open_frame(&c, AVI_OPEN_MBTOWC_RETURN, "SomeText$");
    call_indirect(&c, TARGET);
    assert(port_video_poll(0, 0) == 0 && target_runs == before + 2);
    printf("video dispatch (%s): ok\n", bridged ? "browser hook active" : "node hook compiled out");
    free(g_mem);
    return 0;
}
