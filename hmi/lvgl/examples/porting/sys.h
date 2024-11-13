#ifndef _SYS_H
#define _SYS_H

#include <stdio.h>
#include "lvgl/lvgl.h"


#define     SCREEN_WIDTH        320
#define     SCREEN_HIGTH        240


#define ENABLE_DEBUG        1    

#define TRANCE_DEBUG(fmt, ...) do  { \
    if (ENABLE_DEBUG) printf("%s Line%d,%s "fmt"\r\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
} while (0)


inline lv_color_t pcs_hmi_color(uint8_t R, uint8_t G, uint8_t B)
{
    uint8_t r,g,b;

    r = 255 - R; g = 255 - G; b = 255 -B;
    return lv_color_make(r,g,b);
}


inline uint8_t color_negation(uint8_t true_color)
{
    return (255 - true_color);
}











#endif
