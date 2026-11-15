/* Видеомост (recomp/host/video.c): состояния poll/done, разбор имени, ожидание страницы и диагностика
   трасс VM на синтезированной гостевой памяти — реальные продакшен-функции, без emcc.
   Кадр точки перехвата собран ровно по переводу XINTERFACE.dll (out_all/MODULES_XINTERFACE_004.c, f_00ae77d0):
   вызов MultiByteToWideChar(0, 0, path, -1, buf, 0x104) с адресом возврата 0xae77fd. Раскладка таблицы
   функций VM проверяется отдельно на ПЕРЕВЕДЁННОМ коде (test_video_vm_layout.c). */
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../host/video.c"

uint8_t *g_mem;
static CPU c;

#define PATH_ADDR 0x2000u
#define STACK 0x1000u

/* Кадр call_indirect(MultiByteToWideChar): [esp]=адрес возврата, затем шесть аргументов stdcall. */
static void open_frame(const char *path) {
    strcpy((char *)HP(PATH_ADDR), path);
    c.esp = STACK;
    W32(STACK + 0x00, AVI_OPEN_MBTOWC_RETURN);
    W32(STACK + 0x04, 0);            /* CP_ACP */
    W32(STACK + 0x08, 0);            /* flags */
    W32(STACK + 0x0c, PATH_ADDR);    /* lpMultiByteStr */
    W32(STACK + 0x10, 0xffffffffu);  /* cbMultiByte = -1 */
    W32(STACK + 0x14, 0x3000u);      /* lpWideCharStr */
    W32(STACK + 0x18, 0x104);        /* cchWideChar */
}

/* Кадр trace-метода VM: [esp]=адрес возврата, [esp+4]=this, [esp+8]=fmt, [esp+0xc]=name */
static void trace_frame(uint32_t ret, uint32_t fmt, const char *name) {
    strcpy((char *)HP(PATH_ADDR), name);
    c.esp = STACK;
    W32(STACK + 0x0, ret);
    W32(STACK + 0x4, 0x475a08u);
    W32(STACK + 0x8, fmt);
    W32(STACK + 0xc, PATH_ADDR);
}

static int idle(void) { return port_video_poll(0, 0) == 0; }
static char g_buf[VIDEO_NAME_CAP];
static void poll_alive(void) { port_video_poll(0, 0); }   /* страница опрашивает кадры: игра видит живой опрос */

/* «Страница»: опрашивает каждые 2 мс, забирает запрос (poll с буфером) и отвечает через delay_ms. */
struct page { int delay_ms; int claim; int answer; volatile int stop; volatile int claimed; };
static void *page_thread(void *arg) {
    struct page *p = arg;
    while (!p->stop) {
        if (p->claim) {
            char out[VIDEO_NAME_CAP];
            if (port_video_poll(out, sizeof out)) {
                p->claimed = 1;
                usleep((useconds_t)p->delay_ms * 1000);
                if (p->answer) port_video_done(0);
                return NULL;
            }
        } else {
            port_video_poll(0, 0);   /* опрашивает, но не забирает */
        }
        usleep(2000);
    }
    return NULL;
}

static int64_t elapsed(int64_t t0) { return now_ms() - t0; }

int main(void) {
    g_mem = calloc(1, 65536);
    assert(g_mem);
    unsetenv("PORT_NO_VIDEO"); unsetenv("PORT_DETERMINISTIC"); unsetenv("PORT_VIDEO_NOWAIT");

    /* 1. Покой */
    assert(port_video_poll(0, 0) == 0);
    assert(port_video_poll((char *)HP(0x3000), 64) == 0);

    /* 2. Диагностические сайты VM никогда не создают запрос, даже с именем StartPostVideo (RE: этой функции
       они не касаются; она скриптовая) */
    setenv("PORT_VIDEO_NOWAIT", "1", 1);
    trace_frame(VM_TRACE_INVALID_FUNCTION, 0x46030cu, "StartPostVideo"); port_video_call_site(&c); assert(idle());
    trace_frame(VM_TRACE_NOT_FOUND, 0x460700u, "StartPostVideo"); port_video_call_site(&c); assert(idle());
    trace_frame(VM_TRACE_IS_IMPORTED, 0x46035cu, "StartPostVideo"); port_video_call_site(&c); assert(idle());

    /* 3. Точка открытия CAviPlayer: имя из пути, регистр и расширение отброшены (режим NOWAIT: без ожидания) */
    open_frame("resource\\videos\\Trailer.wmv");
    port_video_open_site(&c);
    assert(port_video_poll(0, 0) == 7);
    memset(g_buf, 0x7f, sizeof g_buf);
    assert(port_video_poll(g_buf, sizeof g_buf) == 7 && strcmp(g_buf, "trailer") == 0);
    /* маленький буфер: длина полная, копия усечена и завершена нулём */
    memset(g_buf, 0x7f, sizeof g_buf);
    assert(port_video_poll(g_buf, 4) == 7 && memcmp(g_buf, "tra", 3) == 0 && g_buf[3] == 0);
    assert(port_video_poll(NULL, 0) == 7 && port_video_poll(g_buf, 0) == 7);
    /* повторный запрос при активном игнорируется */
    open_frame("resource\\videos\\temple.wmv"); port_video_open_site(&c);
    assert(port_video_poll(g_buf, sizeof g_buf) == 7 && strcmp(g_buf, "trailer") == 0);
    port_video_done(0); assert(idle());
    port_video_done(1); assert(idle());

    /* 4. Разбор имён: как их пишут скрипты (seadogs.c, quests_reaction.c, mainmenu.c) */
    static const struct { const char *path, *name; } ok[] = {
        { "resource\\videos\\skeleton_on_beach.wmv", "skeleton_on_beach" },
        { "resource\\videos\\BlackPearl.wmv", "blackpearl" },
        { "resource\\videos\\Invasion.wmv", "invasion" },
        { "resource\\videos\\credits.wmv", "credits" },
        { "resource\\videos\\WaltDisneyLogo.wmv", "waltdisneylogo" },
        { "Resource/Videos/Idol.XMV", "idol" },
        { "storm", "storm" },
    };
    for (unsigned i = 0; i < sizeof ok / sizeof *ok; i++) {
        open_frame(ok[i].path); port_video_open_site(&c);
        assert(port_video_poll(g_buf, sizeof g_buf) == (int)strlen(ok[i].name) && strcmp(g_buf, ok[i].name) == 0);
        port_video_done(0);
    }
    static const char *const bad[] = { "", "resource\\videos\\", "resource\\videos\\.wmv", "resource\\videos\\a$b.wmv",
                                       "resource\\videos\\..\\..\\x\\\xff.wmv", "resource\\videos\\a\x01" ".wmv" };
    for (unsigned i = 0; i < sizeof bad / sizeof *bad; i++) { open_frame(bad[i]); port_video_open_site(&c); assert(idle()); }
    /* слишком длинное имя файла (>= 64) не принимается; путь длиннее 260 усечён без выхода за буфер */
    {
        char longp[400] = "resource\\videos\\";
        memset(longp + strlen(longp), 'a', 70); strcat(longp, ".wmv");
        open_frame(longp); port_video_open_site(&c); assert(idle());
        memset(longp, 'b', 399); longp[399] = 0;
        open_frame(longp); port_video_open_site(&c); assert(idle());
    }

    /* 5. Кадр не тот: ни один из пяти фиксированных аргументов, ни адрес возврата не подходят -> молчим */
    open_frame("resource\\videos\\trailer.wmv"); W32(STACK + 4, 1); port_video_open_site(&c); assert(idle());
    open_frame("resource\\videos\\trailer.wmv"); W32(STACK + 8, 1); port_video_open_site(&c); assert(idle());
    open_frame("resource\\videos\\trailer.wmv"); W32(STACK + 0x10, 5); port_video_open_site(&c); assert(idle());
    open_frame("resource\\videos\\trailer.wmv"); W32(STACK + 0x18, 0x105); port_video_open_site(&c); assert(idle());
    open_frame("resource\\videos\\trailer.wmv"); W32(STACK, 0x00ae77fcu); port_video_open_site(&c); assert(idle());
    open_frame("resource\\videos\\trailer.wmv"); W32(STACK + 0xc, 0); port_video_open_site(&c); assert(idle());
    open_frame("resource\\videos\\trailer.wmv"); c.esp = 0xfffffff0u; port_video_open_site(&c); assert(idle());
    c.esp = (uint32_t)GUEST_SPACE - 8u; port_video_open_site(&c); assert(idle());

    /* 6. Выключатели */
    setenv("PORT_NO_VIDEO", "1", 1);
    open_frame("resource\\videos\\trailer.wmv"); port_video_open_site(&c); assert(idle());
    unsetenv("PORT_NO_VIDEO");
    setenv("PORT_DETERMINISTIC", "1", 1);
    open_frame("resource\\videos\\trailer.wmv"); port_video_open_site(&c); assert(idle());
    unsetenv("PORT_DETERMINISTIC");

    /* 7. Окно неподтверждённого запроса: poll сам гасит; поллинг без буфера не «забирает» запрос */
    port_video_pending_ms = 0;
    open_frame("resource\\videos\\trailer.wmv"); port_video_open_site(&c);
    assert(port_video_poll(g_buf, sizeof g_buf) == 0 && idle());
    port_video_pending_ms = 15000;
    /* забранный запрос живёт до port_video_max_ms, а не до port_video_pending_ms */
    port_video_pending_ms = 50;
    open_frame("resource\\videos\\trailer.wmv"); port_video_open_site(&c);
    assert(port_video_poll(g_buf, sizeof g_buf) == 7);   /* забрал: срок теперь port_video_max_ms */
    usleep(80 * 1000);
    assert(port_video_poll(0, 0) == 7);                  /* окно 50 мс прошло, запрос жив */
    port_video_pending_ms = 15000;
    /* зависший забранный запрос (страница пропала) вытесняется следующим после срока */
    {
        int64_t save = port_video_max_ms; port_video_max_ms = 0;
        open_frame("resource\\videos\\x.wmv"); port_video_open_site(&c);   /* ещё активен: игнор */
        assert(port_video_poll(0, 0) == 7);
        SET_DEADLINE(now_ms() - 1);                      /* срок вышел */
        open_frame("resource\\videos\\temple.wmv"); port_video_open_site(&c);
        assert(port_video_poll(g_buf, sizeof g_buf) == 6 && strcmp(g_buf, "temple") == 0);
        port_video_max_ms = save;
        port_video_done(0);
    }
    assert(idle());
    unsetenv("PORT_VIDEO_NOWAIT");

    /* 8. Ожидание страницы. (а) страница не опрашивает -> запроса нет, игра не ждёт ни миллисекунды */
    __atomic_store_n(&g_last_poll_ms, 0, __ATOMIC_RELEASE);
    open_frame("resource\\videos\\trailer.wmv");
    int64_t t0 = now_ms(); port_video_open_site(&c);
    assert(elapsed(t0) < 200 && g_video_len == 0);
    /* устаревший опрос (скрытая вкладка) -> то же самое */
    __atomic_store_n(&g_last_poll_ms, now_ms() - 10000, __ATOMIC_RELEASE);
    t0 = now_ms(); port_video_open_site(&c);
    assert(elapsed(t0) < 200 && g_video_len == 0);

    /* (б) живая страница забирает и отвечает через 120 мс: игра ждёт ответа */
    {
        struct page p = { .delay_ms = 120, .claim = 1, .answer = 1 };
        pthread_t th; poll_alive();
        pthread_create(&th, NULL, page_thread, &p);
        t0 = now_ms(); port_video_open_site(&c);
        int64_t dt = elapsed(t0);
        pthread_join(th, NULL);
        assert(p.claimed && dt >= 100 && dt < 1500 && g_video_len == 0);
    }
    /* (в) живая страница опрашивает, но не забирает: игра отпускает через port_video_claim_ms, запрос снят */
    {
        struct page p = { .claim = 0 };
        pthread_t th; poll_alive();
        int64_t sc = port_video_claim_ms; port_video_claim_ms = 150;
        pthread_create(&th, NULL, page_thread, &p);
        t0 = now_ms(); port_video_open_site(&c);
        int64_t dt = elapsed(t0);
        p.stop = 1; pthread_join(th, NULL);
        port_video_claim_ms = sc;
        assert(dt >= 140 && dt < 1500 && g_video_len == 0);
    }
    /* (г) страница забрала, но молчит: игра отпускает по сроку port_video_max_ms */
    {
        struct page p = { .delay_ms = 0, .claim = 1, .answer = 0 };
        pthread_t th; poll_alive();
        int64_t sm = port_video_max_ms; port_video_max_ms = 200;
        pthread_create(&th, NULL, page_thread, &p);
        t0 = now_ms(); port_video_open_site(&c);
        int64_t dt = elapsed(t0);
        pthread_join(th, NULL);
        port_video_max_ms = sm;
        assert(p.claimed && dt >= 190 && dt < 2000 && g_video_len == 0);
    }
    /* (д) NOWAIT: запрос публикуется без проверки живости и игра не ждёт */
    setenv("PORT_VIDEO_NOWAIT", "1", 1);
    __atomic_store_n(&g_last_poll_ms, 0, __ATOMIC_RELEASE);
    open_frame("resource\\videos\\trailer.wmv");
    t0 = now_ms(); port_video_open_site(&c);
    assert(elapsed(t0) < 200 && port_video_poll(0, 0) == 7);
    port_video_done(1);
    unsetenv("PORT_VIDEO_NOWAIT");
    assert(idle());

    /* 9. Диагностика трасс VM: лог ограничен 16 записями и не падает на мусоре; запрос не создаётся */
    {
        enum { EBP = 0x8000, SELF = 0x9000, TBL = 0xa000, NAMES = 0xb000 };
        memset(HP(0x8000), 0, 0x4000);
        c.ebp = EBP; W32(EBP + 8, 3);
        W32(EBP - 0x10c, SELF);
        W32(SELF + 0x8f8 + 4, 8); W32(SELF + 0x8f8 + 8, TBL);
        strcpy((char *)HP(NAMES), "StartPostVideo");
        W32(TBL + 3 * 0x48 + 0xc, NAMES);
        trace_frame(VM_TRACE_INVALID_FUNCTION, 0x46030cu, "x"); W32(STACK + 0xc, 0);
        assert(table_entry_name(&c) == NAMES);
        port_video_call_site(&c); assert(idle());
        W32(EBP + 8, 8); assert(table_entry_name(&c) == 0);            /* индекс вне таблицы */
        W32(EBP + 8, 0xffffffffu); assert(table_entry_name(&c) == 0);
        W32(EBP + 8, 3); W32(SELF + 0x8f8 + 8, 0); assert(table_entry_name(&c) == 0);
        W32(SELF + 0x8f8 + 8, TBL); W32(EBP - 0x10c, 0xfffffff0u); assert(table_entry_name(&c) == 0);
        W32(EBP - 0x10c, SELF); W32(TBL + 3 * 0x48 + 0xc, 0xfffffffeu);
        port_video_call_site(&c); assert(idle());                      /* указатель имени за пределами гостя */
        c.ebp = 0x20; assert(table_entry_name(&c) == 0);
        c.ebp = 0xfffffff8u; assert(table_entry_name(&c) == 0);
        c.ebp = 0;
        trace_frame(VM_TRACE_INVALID_FUNCTION, 0x46030cu, "x"); W32(STACK + 8, 0xdeadbeefu);   /* чужой fmt */
        port_video_call_site(&c); assert(idle());
        W32(STACK + 8, 0x46030cu); W32(STACK + 0xc, (uint32_t)GUEST_SPACE - 4u);                /* имя на краю гостя */
        port_video_call_site(&c); assert(idle());
        for (int i = 0; i < 40; i++) { trace_frame(VM_TRACE_NOT_FOUND, 0x460700u, "x"); port_video_call_site(&c); }
        assert(g_site_logs == 16);
    }

    printf("video bridge: all native checks passed\n");
    free(g_mem);
    return 0;
}
