/* Isolated recorder test: exact-size FVF vertices and independent stage routes. */
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../host/render_rec.c"
static unsigned code(unsigned d) { static const unsigned c[]={0,3,0,1,2}; return c[d]; }
static void check(unsigned count, int rhw) {
    const unsigned dim[8]={1,2,3,4,1,2,3,4};
    uint32_t fvf=(rhw?4u:2u)|(count<<8);
    for (unsigned i=0;i<count;i++) fvf|=code(dim[i])<<(16+2*i);
    FvfLayout l; fvf_layout(fvf,&l); uint8_t *data=calloc(1,l.stride); assert(data);
    for(unsigned i=0;i<count;i++) for(unsigned j=0;j<dim[i];j++) {
        float x=10.f*(i+1)+j; memcpy(data+l.off_tex[i]+4*j,&x,4);
    }
    for(unsigned a=0;a<8;a++) for(unsigned b=0;b<8;b++) {
        CVert out, original; convert_vertex(data,&l,&out); original=out;
        route_fvf_texcoords(data,&l,&out,a,b);
        unsigned index[2]={a,b};
        for(unsigned stage=0;stage<2;stage++) for(unsigned j=0;j<4;j++) {
            unsigned k=index[stage];
            float expected=(k<count && j<dim[k])?10.f*(k+1)+j:(j==3?1.f:0.f);
            assert(out.tc[stage][j]==expected);
        }
        assert(!memcmp(out.tc[2],original.tc[2],sizeof out.tc[2]));
        assert(!memcmp(out.tc[3],original.tc[3],sizeof out.tc[3]));
        assert(out.x==original.x && out.w==original.w && out.diffuse==original.diffuse);
    }
    free(data);
}
int main(void) {
    assert(route_fvf_texcoords_enabled(0,0,7,0));
    assert(!route_fvf_texcoords_enabled(1,0,0,1));
    assert(!route_fvf_texcoords_enabled(0,1,0,1));
    assert(!route_fvf_texcoords_enabled(0,0,0x10000,1));
    assert(!route_fvf_texcoords_enabled(0,0,0,8));
    for(unsigned n=0;n<=8;n++) { check(n,0); check(n,1); }
    puts("FVF fixed-stage coordinate routing passed");
}
