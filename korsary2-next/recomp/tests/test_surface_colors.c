#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/render_surface_color.h"
static int distance(int a,int b) { return abs(a-b); }
int main(void) {
    const uint8_t rgba[4]={128,64,32,123}; uint8_t v[4],back[4];
    surface_from_rgba(rgba,v,1,0); assert(!memcmp(v,(uint8_t[]){32,64,128,123},4));
    surface_to_bgra(v,back,1,0); assert(!memcmp(back,(uint8_t[]){32,64,128,123},4));
    surface_from_rgba(rgba,v,0,0); assert(!memcmp(v,rgba,4));
    surface_to_bgra(v,back,0,0); assert(!memcmp(back,(uint8_t[]){32,64,128,123},4));
    surface_from_rgba(rgba,v,1,1); assert(!memcmp(v,(uint8_t[]){99,137,188,123},4));
    surface_to_bgra(v,back,1,1); assert(distance(back[0],32)<=1 && distance(back[1],64)<=1 && distance(back[2],128)<=1 && back[3]==123);
    for(int x=0;x<256;x++) for(int bgra=0;bgra<2;bgra++) for(int srgb=0;srgb<2;srgb++) {
        uint8_t input[4]={(uint8_t)x,(uint8_t)(255-x),(uint8_t)((x*73)&255),(uint8_t)(x^0xa5)};
        uint8_t storage[4],out[4]; surface_from_rgba(input,storage,bgra,srgb); surface_to_bgra(storage,out,bgra,srgb);
        assert(distance(out[0],input[2])<=srgb && distance(out[1],input[1])<=srgb && distance(out[2],input[0])<=srgb && out[3]==input[3]);
        /* source/destination can alias on both operations */
        uint8_t alias[4]; memcpy(alias,input,4); surface_from_rgba(alias,alias,bgra,srgb);
        assert(!memcmp(alias,storage,4)); surface_to_bgra(alias,alias,bgra,srgb); assert(!memcmp(alias,out,4));
    }
    puts("surface colors: RGBA/BGRA unorm and sRGB encoding, decoding, alpha and in-place PASS");
}
