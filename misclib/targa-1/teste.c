#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#include "targa.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define errfail(wut) { printf(#wut " fail (line #%03i): (%i) %s\n", __LINE__, errno, strerror(errno)); return errno; }
#define errtga(wut) { printf(#wut " fail (line #%03i): (%i) %s\n", __LINE__, res, tga_error(res)); return 1; }

int main()
{
    FILE* f = fopen("testimage.bin", "rb");
    if(f <= 0) errfail(fopen);
    
    u32 imgbuf[400][240];
    
    int csize;
    u8 csbuf[400 * 256 * 4];
    
    fread(imgbuf, 1 << 2, sizeof(imgbuf) >> 2, f);
    
    fclose(f);
    
    tga_result res;
    tga_image img;
    
    init_tga_image(&img, (u8*)imgbuf, 240, 400, 32);
    img.image_type = TGA_IMAGE_TYPE_BGR_RLE;
    
    tga_swap_red_blue(&img);
    
    int depth = 32;
    
    char namebuf[32];
    
    wri:
    
    res = tga_write_to_FILE(csbuf, &img, &csize);
    if(res) errtga(write_to_FILE);
    
    snprintf(namebuf, 32, "testimage%i.tga", depth);
    f = fopen(namebuf, "wb");
    if(f <= 0) errfail(fopen);
    
    fwrite(csbuf, 1, csize, f);
    fflush(f);
    fclose(f);
    
    if(depth != 8)
    {
        depth -= 8;
        res = tga_convert_depth(&img, depth);
        if(res) errtga(convert_depth);
        goto wri;
    }
    
    return 0;
} 
