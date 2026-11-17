/* Exercise activity and render pacing through the actual CreateFileA/ReadFile wrappers. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../host/core.c"
#include "../host/kernel32.c"
uint8_t *g_mem;

static uint32_t open_read(CPU *c, const char *name, uint32_t fs_caller) {
    strcpy((char *)HP(0x2000), name); c->esp = 0x1000;
    c->ebp = 0x1100; W32(c->ebp + 4, fs_caller);
    W32(0x1000, 0x0042a763); W32(0x1004, 0x2000); W32(0x1008, 0x80000000u);
    W32(0x100c, 1); W32(0x1010, 0); W32(0x1014, 3); W32(0x1018, 0); W32(0x101c, 0);
    w_CreateFileA(c); return c->eax;
}
static uint32_t read_n(CPU *c, uint32_t h, uint32_t n) {
    c->esp = 0x1000; W32(0x1000, 0); W32(0x1004, h); W32(0x1008, 0x3000);
    W32(0x100c, n); W32(0x1010, 0x4000); W32(0x1014, 0);
    w_ReadFile(c); assert(c->eax); return R32(0x4000);
}
int main(void) {
    g_mem = calloc(1, 65536); assert(g_mem); GuestThread thread = {0}; t_self = &thread; CPU c = {0};
    char root[] = "/tmp/korsary-save-activity-XXXXXX"; assert(mkdtemp(root));
    snprintf(g_game_root, sizeof g_game_root, "%s", root);
    char dir[256], save[256], other[256];
    snprintf(dir, sizeof dir, "%s/SAVE", root); assert(!mkdir(dir, 0755));
    snprintf(save, sizeof save, "%s/SAVE/slot", root);
    snprintf(other, sizeof other, "%s/SAVEFILE", root);
    FILE *f = fopen(save, "wb"); assert(f && fputs("DATA", f) >= 0 && !fclose(f));
    f = fopen(other, "wb"); assert(f && fputs("OTHER", f) >= 0 && !fclose(f));
    uint32_t before = port_save_read_count();
    uint32_t h = open_read(&c, "SAVEFILE", 0x0041b7b3); assert(h != 0xffffffffu);
    assert(!port_load_pacing_active());
    assert(read_n(&c, h, 2) == 2); handle_close(h); assert(port_save_read_count() == before);
    h = open_read(&c, "save/slot", 0x00410328); assert(h != 0xffffffffu);
    assert(!port_load_pacing_active());
    assert(read_n(&c, h, 0) == 0 && port_save_read_count() == before);
    assert(read_n(&c, h, 2) == 2 && port_save_read_count() == before + 1);
    assert(read_n(&c, h, 8) == 2 && port_save_read_count() == before + 2);
    assert(read_n(&c, h, 1) == 0 && port_save_read_count() == before + 2);
    handle_close(h);
    assert(!port_load_pacing_active());
    h = open_read(&c, "save/missing", 0x0041b7b3); assert(h == 0xffffffffu);
    assert(!port_load_pacing_active());
    h = open_read(&c, "save/slot", 0x0041b7b3); assert(h != 0xffffffffu);
    assert(port_load_pacing_active());
    handle_close(h);
    assert(!unlink(save) && !unlink(other) && !rmdir(dir) && !rmdir(root));
    free(g_mem); puts("Save read activity and load pacing: actual wrapper PASS");
}
