/* Видеомост: проверка на ПЕРЕВЕДЁННОМ коде (а не на собственной раскладке теста).
   run_video_bridge.sh вырезает из recomp/out_all/*.c тексты реальных переведённых функций в extracted.inc:
     f_004473cf   ENGINE.exe 0x4473cf  — поиск записи в таблице функций VM по индексу (FUNCINFO, 0x48 байт)
     f_00ae7700   XINTERFACE.dll 0x10037700 — CAviPlayer::ProcessMessage (MSG_SET_VIDEO_PLAY = 49000)
     f_00ae77d0   XINTERFACE.dll 0x100377d0 — open-метод CAviPlayer (MultiByteToWideChar на 0xae77fd)
     f_00ab1578   переходник на open
   и этот тест исполняет их с настоящим call_indirect из runtime/runtime.c и хуком host/video.c.
   Вокруг них стоят только заглушки внешнего мира (vtable сообщения, sprintf, события, импорт Windows).
   Часть 1: таблица функций. Реальный f_004473cf на трёх отказах (индекс вне таблицы, импортированная запись
   без указателя, offset == -1) НИЧЕГО не копирует -> обнулённый FUNCINFO сохраняет name == 0, то есть
   аргумент трассы «Invalid function: %s» пуст; запасное чтение имени из таблицы (table_entry_name) даёт ту же
   запись, что реальный код копирует при успехе.
   Часть 2: реальный ProcessMessage -> open -> call_indirect(MultiByteToWideChar): хук видит имя ролика,
   а при отказе open движок отправляет "ievntEndVideo" (реальный путь без DirectShow). */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../out_all/recomp.h"
#include "../host/video.c"
#include "extracted.inc"

int dyncode_contains(uint32_t a) { (void)a; return 0; }
void interp_call(CPU *c, uint32_t a) { (void)c; (void)a; abort(); }

#define STACK_TOP 0x00700000u

/* ---- заглушки внешнего мира для части 2 ---- */
enum { FN_GETCODE = 0x600000, FN_GETSTRING, FN_EVENT, FN_MBTOWC, FN_TRACE };
static char g_msg_string[64] = "trailer.wmv";
static char g_event_name[64];
static int g_events, g_mbtowc_calls;
static uint32_t g_mbtowc_path;
static char g_mbtowc_seen[300];

static void fn_getcode(CPU *c) { c->eax = 49000; c->esp += 4; }                        /* MESSAGE::GetCode(), thiscall */
static void fn_getstring(CPU *c) {                                                      /* MESSAGE::String(0xff, buf), ret 8 */
    assert(R32(c->esp + 4) == 0xffu);
    strcpy((char *)HP(R32(c->esp + 8)), g_msg_string);
    c->esp += 12;
}
static void fn_event(CPU *c) {                                                          /* API::Event(name, 1, 0), caller cleans */
    strncpy(g_event_name, (const char *)HP(R32(c->esp + 8)), sizeof g_event_name - 1);
    assert(R32(c->esp + 0xc) == 1u && R32(c->esp + 0x10) == 0u);
    g_events++;
    c->esp += 4;
}
static void fn_mbtowc(CPU *c) {                                                         /* MultiByteToWideChar, stdcall 6 args */
    g_mbtowc_calls++;
    g_mbtowc_path = R32(c->esp + 0xc);
    strncpy(g_mbtowc_seen, (const char *)HP(g_mbtowc_path), sizeof g_mbtowc_seen - 1);
    c->eax = 0;
    c->esp += 4 + 0x18;
}
/* CRT sprintf(buf, "%s\\%s", a, b), cdecl: переведённый ProcessMessage сам чистит стек */
void f_00aef269(CPU *c) {
    uint32_t buf = R32(c->esp + 4), fmt = R32(c->esp + 8), a = R32(c->esp + 0xc), b = R32(c->esp + 0x10);
    assert(fmt == 0xb0dba8u && a == 0xb0f598u);   /* форматная строка XINTERFACE.dll 0x1005dba8 и префикс 0x1005f598 */
    snprintf((char *)HP(buf), 260, "%s\\%s", (const char *)HP(a), (const char *)HP(b));
    c->esp += 4;
}
void f_00ab1073(CPU *c) { (void)c; abort(); }   /* успешная ветка open (DirectShow открыл файл): тест туда не заходит */
void f_00aef084(CPU *c) { (void)c; abort(); }   /* __ftol той же ветки */
void f_00ab1794(CPU *c) { c->esp += 4; }   /* очистка DirectShow-объектов CAviPlayer: в тесте нечего чистить */

static void fn_other(CPU *c);
static void part1_function_table(void) {
    enum { SELF = 0x00100000, ARR = 0x00110000, NAMES = 0x00120000, INFO = 0x00130000, EBP = 0x00140000 };
    uint32_t hdr = SELF + 0x8f8;
    memset(HP(SELF), 0, 0x1000); memset(HP(ARR), 0, 0x1000);
    W32(hdr + 0, 0x400); W32(hdr + 4, 5); W32(hdr + 8, ARR);   /* capacity, count, array */
    strcpy((char *)HP(NAMES), "StartPostVideo");
    strcpy((char *)HP(NAMES + 0x20), "ImportedNative");
    strcpy((char *)HP(NAMES + 0x40), "NeverDefined");
    strcpy((char *)HP(NAMES + 0x60), "ImportedResolved");
    /* [1] обычная скриптовая функция: тип 1, offset 5 */
    W32(ARR + 1 * 0x48 + 0, 1); W32(ARR + 1 * 0x48 + 4, 5); W32(ARR + 1 * 0x48 + 0xc, NAMES);
    /* [2] импортированная запись без указателя: тип -2, +0x3c == 0 -> отказ */
    W32(ARR + 2 * 0x48 + 0, 0xfffffffeu); W32(ARR + 2 * 0x48 + 4, 7); W32(ARR + 2 * 0x48 + 0xc, NAMES + 0x20);
    /* [3] объявлена, но не определена: offset == -1 -> отказ */
    W32(ARR + 3 * 0x48 + 0, 1); W32(ARR + 3 * 0x48 + 4, 0xffffffffu); W32(ARR + 3 * 0x48 + 0xc, NAMES + 0x40);
    /* [4] импортированная запись с указателем +0x3c: копируется */
    W32(ARR + 4 * 0x48 + 0, 0xfffffffeu); W32(ARR + 4 * 0x48 + 4, 9); W32(ARR + 4 * 0x48 + 0xc, NAMES + 0x60);
    W32(ARR + 4 * 0x48 + 0x3c, 0x1234u);

    CPU c; memset(&c, 0, sizeof c);
    /* кадр ExecuteFunction: [ebp+8] = код, [ebp-0x10c] = this */
    c.ebp = EBP;
    W32(EBP - 0x10c, SELF);
    static const struct { uint32_t code; int ok; uint32_t expect_name; } cases[] = {
        { 0, 0, 0 },            /* запись 0 нулевая: тип 0, offset 0 -> копируется пустая запись (имя 0) */
        { 1, 1, NAMES },
        { 2, 0, NAMES + 0x20 },
        { 3, 0, NAMES + 0x40 },
        { 4, 1, NAMES + 0x60 },
        { 5, 0, 0 },            /* индекс == count: вне таблицы */
        { 0xffffffffu, 0, 0 },
    };
    for (unsigned i = 0; i < sizeof cases / sizeof *cases; i++) {
        W32(EBP + 8, cases[i].code);
        memset(HP(INFO), 0, 0x48);                    /* memset(&info, 0, 0x48) в 0x40a373 */
        c.esp = STACK_TOP; c.ecx = hdr;
        PUSH32(&c, cases[i].code); PUSH32(&c, INFO); PUSH32(&c, 0x0040a3acu);
        f_004473cf(&c);
        int ok = (int)(c.eax & 0xff);
        assert(c.esp == STACK_TOP);                   /* ret 8 */
        uint32_t copied = R32(INFO + 0xc);
        if (cases[i].code == 0) { assert(ok == 1 && copied == 0); }       /* пустая, но валидная запись */
        else if (cases[i].ok) { assert(ok == 1 && copied == cases[i].expect_name); }
        else { assert(ok == 0 && copied == 0); }       /* отказ: ничего не скопировано, name == NULL */
        uint32_t fallback = table_entry_name(&c);
        if (cases[i].code == 5 || cases[i].code == 0xffffffffu) assert(fallback == 0);   /* вне таблицы: имени нет */
        else assert(fallback == cases[i].expect_name);                                   /* то же имя, что при успехе */
        if (cases[i].ok) assert(fallback == copied);
    }
    /* 0x40a3cf: отказ -> trace-метод получает (this, fmt, name == 0); запасное имя из таблицы — «StartPostVideo» */
    W32(EBP + 8, 1);
    c.esp = STACK_TOP;
    PUSH32(&c, 0); PUSH32(&c, 0x46030cu); PUSH32(&c, SELF); PUSH32(&c, 0x0040a3cfu);
    assert(R32(c.esp) == 0x0040a3cfu && VM_TRACE_NAME(&c) == 0);
    assert(guest_range(table_entry_name(&c), 15) && strcmp((char *)HP(table_entry_name(&c)), "StartPostVideo") == 0);
    printf("video layout: real f_004473cf refusals leave FUNCINFO.name == 0; table fallback matches\n");
}

static void part2_avi_open(void) {
    enum { MSG = 0x00200000, MSGVT = 0x00200100, API = 0x00200200, APIVT = 0x00200300, THIS = 0x00200400 };
    strcpy((char *)HP(0xb0f598), "resource\\videos");     /* XINTERFACE.dll 0x1005f598 */
    strcpy((char *)HP(0xb0dba8), "%s\\%s");               /* 0x1005dba8 */
    strcpy((char *)HP(0xb0f578), "ievntEndVideo");        /* 0x1005f578 */
    register_function(FN_GETCODE, fn_getcode); register_function(FN_GETSTRING, fn_getstring);
    register_function(FN_EVENT, fn_event); register_function(FN_MBTOWC, fn_mbtowc);
    W32(MSG, MSGVT); W32(MSGVT + 0xc, FN_GETCODE); W32(MSGVT + 0x30, FN_GETSTRING);
    W32(0xb14784, API); W32(API, APIVT); W32(APIVT + 0xf0, FN_EVENT);   /* глобальный указатель на API ядра, +0xf0 = Event */
    W32(0xb17310, FN_MBTOWC);                                          /* IAT: MultiByteToWideChar */
    memset(HP(THIS), 0, 0x100);                                         /* this+0x34 == 0: DirectShow не создан (DirectDrawCreate отказал) */

    setenv("PORT_VIDEO_NOWAIT", "1", 1);
    CPU c; memset(&c, 0, sizeof c);
    c.esp = STACK_TOP;
    PUSH32(&c, MSG); PUSH32(&c, THIS); PUSH32(&c, 0xdeadc0deu);
    f_00ae7700(&c);   /* реальный ProcessMessage (vtable[4] CAviPlayer, cdecl: [esp+4] = this, [esp+8] = MESSAGE&) */
    assert(c.esp == STACK_TOP - 8 && c.eax == 0);   /* cdecl: this и сообщение остаются на стороне вызывающего */
    assert(g_mbtowc_calls == 1 && strcmp(g_mbtowc_seen, "resource\\videos\\trailer.wmv") == 0);
    assert(g_events == 1 && strcmp(g_event_name, "ievntEndVideo") == 0);   /* штатный путь отказа: событие конца видео */
    char name[VIDEO_NAME_CAP];
    int len = port_video_poll(name, sizeof name);
#ifdef PORT_NODE_BUILD
    assert(len == 0);   /* хук в Node-сборке вырезан */
#else
    assert(len == 7 && strcmp(name, "trailer") == 0);   /* хук получил имя из настоящего кадра переведённого open */
#endif
    port_video_done(0);
    /* другое сообщение (не MSG_SET_VIDEO_PLAY): ни open, ни события */
    int calls = g_mbtowc_calls, events = g_events;
    register_function(FN_TRACE, fn_other);
    W32(MSGVT + 0xc, FN_TRACE);
    c.esp = STACK_TOP; PUSH32(&c, MSG); PUSH32(&c, THIS); PUSH32(&c, 0xdeadc0deu);
    f_00ae7700(&c);
    assert(g_mbtowc_calls == calls && g_events == events && port_video_poll(0, 0) == 0);
    /* имя с другим регистром и без расширения, как у скриптов («Invasion», «blackpearl») */
    W32(MSGVT + 0xc, FN_GETCODE);
    strcpy(g_msg_string, "BlackPearl.wmv");
    c.esp = STACK_TOP; PUSH32(&c, MSG); PUSH32(&c, THIS); PUSH32(&c, 0xdeadc0deu);
    f_00ae7700(&c);
#ifndef PORT_NODE_BUILD
    assert(port_video_poll(name, sizeof name) == 10 && strcmp(name, "blackpearl") == 0);
#endif
    port_video_done(0);
    printf("video layout: real ProcessMessage -> open -> hook sees the video name\n");
}
static void fn_other(CPU *c) { c->eax = 12345; c->esp += 4; }

int main(void) {
    g_mem = calloc(1, 0xb20000);   /* до адресов данных XINTERFACE.dll (0xb17310): под wasm память фиксирована */
    assert(g_mem);
    unsetenv("PORT_NO_VIDEO"); unsetenv("PORT_DETERMINISTIC");
    part1_function_table();
    part2_avi_open();
    free(g_mem);
    return 0;
}
