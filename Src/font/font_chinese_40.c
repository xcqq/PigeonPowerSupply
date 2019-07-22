#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 40 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifndef FONT_CHINESE_40
#define FONT_CHINESE_40 1
#endif

#if FONT_CHINESE_40

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+4E8E "于" */
    0x1, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x40, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x1, 0x55, 0x55, 0x55, 0x7f,
    0x55, 0x55, 0x55, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x0, 0x0, 0x55, 0x55, 0x55,
    0x55, 0xbf, 0x55, 0x55, 0x55, 0x55, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x15, 0x55, 0x55, 0x55, 0x7f, 0x55, 0x55, 0x55,
    0x54, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0x90, 0x0, 0x0,
    0x0, 0x0,

    /* U+4EF6 "件" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xb, 0xd0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xf0, 0x4, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x1, 0xfc, 0x3,
    0xf0, 0xf, 0xc0, 0x0, 0x0, 0x0, 0x0, 0xbd,
    0x0, 0xfc, 0x3, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x7e, 0x0, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0x80, 0x2f, 0x40, 0x3f, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xc0, 0xf, 0xc0, 0xf, 0xc0,
    0x0, 0x0, 0x0, 0xb, 0xe0, 0x3, 0xf0, 0x3,
    0xf0, 0x0, 0x0, 0x0, 0x7, 0xf0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x40, 0x3, 0xfc, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x2, 0xff,
    0x0, 0x3f, 0xaa, 0xaf, 0xea, 0xaa, 0xa0, 0x1,
    0xff, 0xc0, 0x2f, 0x40, 0x3, 0xf0, 0x0, 0x0,
    0x0, 0xff, 0xf0, 0xf, 0xc0, 0x0, 0xfc, 0x0,
    0x0, 0x0, 0xff, 0xfc, 0xb, 0xe0, 0x0, 0x3f,
    0x0, 0x0, 0x0, 0xbf, 0xbf, 0x7, 0xf0, 0x0,
    0xf, 0xc0, 0x0, 0x0, 0x7f, 0x9f, 0xc0, 0xf8,
    0x0, 0x3, 0xf0, 0x0, 0x0, 0xf, 0xc7, 0xf0,
    0x4, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x1, 0xc1,
    0xfc, 0x0, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0,
    0x0, 0x0, 0x1f, 0xc0, 0xaa, 0xaa, 0xab, 0xfa,
    0xaa, 0xaa, 0x80, 0x7, 0xf0, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x1, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x7f, 0x1,
    0x55, 0x55, 0x5f, 0xd5, 0x55, 0x55, 0x0, 0x1f,
    0xc0, 0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0x0,
    0x7, 0xf0, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x0,
    0x0, 0x1, 0xfc, 0x0, 0x0, 0x0, 0x3f, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0xf,
    0xc0, 0x0, 0x0, 0x0, 0x1f, 0xc0, 0x0, 0x0,
    0x3, 0xf0, 0x0, 0x0, 0x0, 0x7, 0xf0, 0x0,
    0x0, 0x0, 0xfc, 0x0, 0x0, 0x0, 0x1, 0xfc,
    0x0, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0,
    0x0, 0x1f, 0xc0, 0x0, 0x0, 0x3, 0xf0, 0x0,
    0x0, 0x0, 0x7, 0xf0, 0x0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x0, 0xf, 0xc0, 0x0, 0x0, 0x0, 0x1f, 0xc0,
    0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0x0,

    /* U+5173 "关" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x70, 0x0, 0x0, 0x0, 0xf,
    0x80, 0x0, 0x0, 0x2, 0xf8, 0x0, 0x0, 0x0,
    0x1f, 0xc0, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0,
    0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x7f, 0x0,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0x80, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xc0, 0x0, 0x2, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xb, 0xe0, 0x0, 0x3, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0x40, 0x0, 0xb, 0xe0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x3, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xbf, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xfb, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf2, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xd0, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xc0,
    0x7f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0x0, 0x2f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfc, 0x0, 0xb, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0xf0, 0x0, 0x2, 0xff, 0x40, 0x0, 0x0,
    0x7, 0xff, 0xc0, 0x0, 0x0, 0xbf, 0xe4, 0x0,
    0x0, 0x6f, 0xfe, 0x0, 0x0, 0x0, 0x1f, 0xfe,
    0x40, 0x7, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xf9, 0xbf, 0xff, 0x40, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0x3f, 0xe4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xfc, 0xe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x24,

    /* U+51C6 "准" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xe4, 0x2, 0xd0,
    0x0, 0x0, 0x8, 0x0, 0x0, 0x2, 0xf4, 0x7,
    0xf0, 0x0, 0x0, 0xbe, 0x0, 0x0, 0x3, 0xf0,
    0x3, 0xf4, 0x0, 0x0, 0x7f, 0x40, 0x0, 0xb,
    0xe0, 0x1, 0xfc, 0x0, 0x0, 0x2f, 0xc0, 0x0,
    0xf, 0xc0, 0x0, 0xfe, 0x0, 0x0, 0xf, 0xe0,
    0x0, 0x2f, 0x80, 0x0, 0x7e, 0x0, 0x0, 0x7,
    0xf0, 0x0, 0x3f, 0x40, 0x0, 0x34, 0x0, 0x0,
    0x3, 0xf8, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x0, 0xfd, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0x0, 0xbf, 0x2, 0xfe, 0x55, 0x55,
    0xfd, 0x55, 0x54, 0x0, 0x3d, 0x7, 0xfe, 0x0,
    0x1, 0xfc, 0x0, 0x0, 0x0, 0x10, 0xf, 0xfe,
    0x0, 0x1, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xfe, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0x7e, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x0,
    0x1, 0xfd, 0x7e, 0x55, 0x56, 0xfd, 0x55, 0x54,
    0x0, 0x7, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x2, 0xf0, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xf8, 0x0, 0x0, 0x80, 0x7e, 0x55, 0x55,
    0xfd, 0x55, 0x50, 0x0, 0x0, 0x0, 0x7e, 0x0,
    0x1, 0xfc, 0x0, 0x0, 0x0, 0x4, 0x0, 0x7e,
    0x0, 0x1, 0xfc, 0x0, 0x0, 0x0, 0x1f, 0x40,
    0x7e, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x0, 0x2f,
    0x80, 0x7e, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x0,
    0x3f, 0x0, 0x7e, 0x55, 0x56, 0xfd, 0x55, 0x50,
    0x0, 0xbf, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xf4, 0x0, 0xfd, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xf4, 0x1, 0xfc, 0x0, 0x7e, 0x0, 0x1,
    0xfc, 0x0, 0x0, 0x3, 0xf8, 0x0, 0x7e, 0x0,
    0x1, 0xfc, 0x0, 0x0, 0x7, 0xf0, 0x0, 0x7e,
    0x0, 0x1, 0xfc, 0x0, 0x0, 0xb, 0xe0, 0x0,
    0x7e, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x1f, 0xd0,
    0x0, 0x7e, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x2f,
    0xc0, 0x0, 0x7e, 0x55, 0x56, 0xfd, 0x55, 0x55,
    0x7f, 0x40, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xbf, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x1d, 0x0, 0x0, 0x7e, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x0, 0x0, 0x0, 0x7e, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+5347 "升" */
    0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x2a, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xc0, 0xf,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xbf, 0xfc,
    0x3, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x1b, 0xff,
    0xf4, 0x0, 0xfd, 0x0, 0x0, 0x0, 0x1, 0xbf,
    0xff, 0x80, 0x0, 0x3f, 0x40, 0x0, 0x0, 0x1f,
    0xff, 0xf9, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x1,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x3, 0xf4, 0x0,
    0x0, 0x3f, 0xe4, 0x3f, 0x0, 0x0, 0x0, 0xfd,
    0x0, 0x0, 0x5, 0x0, 0xf, 0xc0, 0x0, 0x0,
    0x3f, 0x40, 0x0, 0x0, 0x0, 0x3, 0xf0, 0x0,
    0x0, 0xf, 0xd0, 0x0, 0x0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0x3, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xc0, 0x0, 0x0, 0x3f, 0x40, 0x0,
    0x0, 0x0, 0x3, 0xf0, 0x0, 0x0, 0xf, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x3,
    0xf4, 0x0, 0x0, 0x55, 0x55, 0x7f, 0x55, 0x55,
    0x55, 0xfe, 0x55, 0x55, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xaa,
    0xaa, 0xfe, 0xaa, 0xaa, 0xab, 0xfa, 0xaa, 0xa8,
    0x0, 0x0, 0x3f, 0x0, 0x0, 0x0, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0, 0x3f,
    0x40, 0x0, 0x0, 0x0, 0x7, 0xf0, 0x0, 0x0,
    0xf, 0xd0, 0x0, 0x0, 0x0, 0x1, 0xf8, 0x0,
    0x0, 0x3, 0xf4, 0x0, 0x0, 0x0, 0x0, 0xbd,
    0x0, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0, 0x0,
    0x0, 0x1f, 0xc0, 0x0, 0x0, 0xf, 0xd0, 0x0,
    0x0, 0x0, 0xb, 0xe0, 0x0, 0x0, 0x3, 0xf4,
    0x0, 0x0, 0x0, 0x7, 0xf0, 0x0, 0x0, 0x0,
    0xfd, 0x0, 0x0, 0x0, 0x3, 0xf8, 0x0, 0x0,
    0x0, 0x3f, 0x40, 0x0, 0x0, 0x2, 0xfc, 0x0,
    0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x2, 0xfd,
    0x0, 0x0, 0x0, 0x3, 0xf4, 0x0, 0x0, 0x2,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0,
    0x3, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x40,
    0x0, 0x7, 0xfe, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xd0, 0x0, 0x2, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xf4, 0x0, 0x0, 0x2c, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xfd, 0x0, 0x0,

    /* U+538B "压" */
    0x0, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x40, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x7, 0xe5, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x1, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0x80, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0,
    0x0, 0x7, 0xe0, 0x0, 0x0, 0x3, 0xf4, 0x0,
    0x0, 0x0, 0x1, 0xf8, 0x0, 0x0, 0x0, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x0,
    0x3f, 0x40, 0x0, 0x0, 0x0, 0x1f, 0x80, 0x0,
    0x0, 0xf, 0xd0, 0x0, 0x0, 0x0, 0x7, 0xe0,
    0x0, 0x0, 0x3, 0xf4, 0x0, 0x0, 0x0, 0x1,
    0xf8, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0,
    0x0, 0x0, 0x1f, 0x82, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x7, 0xe0, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x1, 0xf8, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x7e, 0x0,
    0x0, 0x0, 0x3f, 0x40, 0x0, 0x0, 0x0, 0x1f,
    0x80, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x0,
    0xb, 0xd0, 0x0, 0x0, 0x3, 0xf4, 0x0, 0x0,
    0x0, 0x2, 0xf4, 0x0, 0x0, 0x0, 0xfd, 0x2,
    0xd0, 0x0, 0x0, 0xbd, 0x0, 0x0, 0x0, 0x3f,
    0x41, 0xfd, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x0,
    0xf, 0xd0, 0x1f, 0xd0, 0x0, 0xf, 0xc0, 0x0,
    0x0, 0x3, 0xf4, 0x1, 0xfd, 0x0, 0x3, 0xf0,
    0x0, 0x0, 0x0, 0xfd, 0x0, 0x1f, 0xd0, 0x0,
    0xfc, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x2, 0xfc,
    0x0, 0x7e, 0x0, 0x0, 0x0, 0xf, 0xd0, 0x0,
    0x3c, 0x0, 0x2f, 0x40, 0x0, 0x0, 0x3, 0xf4,
    0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0, 0x0,
    0xfd, 0x0, 0x0, 0x0, 0x3, 0xf0, 0x0, 0x0,
    0x0, 0x3f, 0x40, 0x0, 0x0, 0x1, 0xf8, 0x15,
    0x55, 0x55, 0x5f, 0xe5, 0x55, 0x55, 0x54, 0xbd,
    0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x3f, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0x80, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0xaa, 0xa0, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+56FA "固" */
    0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x57, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe7, 0xf5, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0xfe, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xe7, 0xf0, 0x0, 0x0, 0x2f, 0x80,
    0x0, 0x0, 0xfe, 0x7f, 0x0, 0x0, 0x2, 0xf8,
    0x0, 0x0, 0xf, 0xe7, 0xf0, 0x0, 0x0, 0x2f,
    0x80, 0x0, 0x0, 0xfe, 0x7f, 0x0, 0x0, 0x2,
    0xf8, 0x0, 0x0, 0xf, 0xe7, 0xf0, 0x55, 0x55,
    0x6f, 0x95, 0x55, 0x50, 0xfe, 0x7f, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x4f, 0xe7, 0xf0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0xfe, 0x7f, 0x0,
    0x0, 0x2, 0xf8, 0x0, 0x0, 0xf, 0xe7, 0xf0,
    0x0, 0x0, 0x2f, 0x80, 0x0, 0x0, 0xfe, 0x7f,
    0x0, 0x0, 0x2, 0xf8, 0x0, 0x0, 0xf, 0xe7,
    0xf0, 0x0, 0x0, 0x2f, 0x80, 0x0, 0x0, 0xfe,
    0x7f, 0x0, 0x15, 0x56, 0xf9, 0x55, 0x50, 0xf,
    0xe7, 0xf0, 0x7, 0xff, 0xff, 0xff, 0xff, 0x0,
    0xfe, 0x7f, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xf0,
    0xf, 0xe7, 0xf0, 0x7, 0xe0, 0x0, 0x0, 0x3f,
    0x0, 0xfe, 0x7f, 0x0, 0x7e, 0x0, 0x0, 0x3,
    0xf0, 0xf, 0xe7, 0xf0, 0x7, 0xe0, 0x0, 0x0,
    0x3f, 0x0, 0xfe, 0x7f, 0x0, 0x7e, 0x0, 0x0,
    0x3, 0xf0, 0xf, 0xe7, 0xf0, 0x7, 0xe0, 0x0,
    0x0, 0x3f, 0x0, 0xfe, 0x7f, 0x0, 0x7e, 0x55,
    0x55, 0x57, 0xf0, 0xf, 0xe7, 0xf0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0x0, 0xfe, 0x7f, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xf0, 0xf, 0xe7, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0x7f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xe7, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0x7f,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x5f, 0xe7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe7, 0xf5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0xfe, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xe1, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x14,

    /* U+5FEB "快" */
    0x0, 0x5, 0x40, 0x0, 0x0, 0x5, 0x40, 0x0,
    0x0, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x0, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x0,
    0xf, 0xd0, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x0,
    0x0, 0x0, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xc0, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0xfc, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xc0, 0x0, 0x0, 0xf, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0xfd, 0xd0, 0xbf, 0xff,
    0xff, 0xff, 0xff, 0x0, 0xa, 0x4f, 0xff, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0xf8, 0xfd,
    0xf4, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x0, 0xf,
    0x4f, 0xcf, 0x80, 0x0, 0xf, 0xd0, 0x3, 0xf0,
    0x0, 0xf4, 0xfc, 0x7c, 0x0, 0x0, 0xfd, 0x0,
    0x3f, 0x0, 0x1f, 0xf, 0xc3, 0xe0, 0x0, 0xf,
    0xd0, 0x3, 0xf0, 0x1, 0xf0, 0xfc, 0x2f, 0x0,
    0x0, 0xfd, 0x0, 0x3f, 0x0, 0x2f, 0xf, 0xc1,
    0xe0, 0x0, 0xf, 0xd0, 0x3, 0xf0, 0x3, 0xe0,
    0xfc, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x3f, 0x0,
    0x3d, 0xf, 0xc0, 0x0, 0x0, 0xf, 0xc0, 0x3,
    0xf0, 0x7, 0xc0, 0xfc, 0x0, 0x0, 0x0, 0xfc,
    0x0, 0x3f, 0x0, 0x7c, 0xf, 0xc0, 0x0, 0x0,
    0xf, 0xc0, 0x3, 0xf0, 0x0, 0x0, 0xfc, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0xf,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0x0, 0xfc, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x0, 0xf, 0xc0, 0x0, 0x0, 0x2f, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x0, 0x3,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0,
    0x0, 0x3f, 0xbe, 0x0, 0x0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0xb, 0xe3, 0xf0, 0x0, 0x0, 0x0,
    0xf, 0xc0, 0x0, 0x0, 0xfc, 0x2f, 0x80, 0x0,
    0x0, 0x0, 0xfc, 0x0, 0x0, 0x2f, 0x80, 0xfd,
    0x0, 0x0, 0x0, 0xf, 0xc0, 0x0, 0x7, 0xf0,
    0xb, 0xf0, 0x0, 0x0, 0x0, 0xfc, 0x0, 0x0,
    0xfe, 0x0, 0x3f, 0xc0, 0x0, 0x0, 0xf, 0xc0,
    0x0, 0x3f, 0xc0, 0x1, 0xfe, 0x0, 0x0, 0x0,
    0xfc, 0x0, 0xf, 0xf0, 0x0, 0xb, 0xf8, 0x0,
    0x0, 0xf, 0xc0, 0x7, 0xfc, 0x0, 0x0, 0x2f,
    0xf4, 0x0, 0x0, 0xfc, 0x2, 0xff, 0x0, 0x0,
    0x0, 0xff, 0xe0, 0x0, 0xf, 0xc1, 0xff, 0xc0,
    0x0, 0x0, 0x2, 0xff, 0xd0, 0x0, 0xfc, 0x1f,
    0xe0, 0x0, 0x0, 0x0, 0x7, 0xfc, 0x0, 0xf,
    0xc0, 0xb4, 0x0, 0x0, 0x0, 0x0, 0xb, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+6377 "捷" */
    0x0, 0x5, 0x40, 0x0, 0x0, 0x1, 0x50, 0x0,
    0x0, 0x0, 0x1, 0xf8, 0x0, 0x0, 0x0, 0x3f,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0x80, 0x0, 0x0,
    0x3, 0xf0, 0x0, 0x0, 0x0, 0x1, 0xf8, 0x0,
    0x0, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0x80, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x1, 0xf8, 0x2, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x1f, 0x80, 0x1a, 0xaa, 0xab, 0xfa,
    0xaa, 0xaa, 0x40, 0x1, 0xf8, 0x0, 0x0, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0x15, 0x6f, 0x95, 0x40,
    0x0, 0x3, 0xf0, 0x0, 0x0, 0x7, 0xff, 0xff,
    0xfc, 0x2a, 0xaa, 0xbf, 0xaa, 0xaa, 0x80, 0x7f,
    0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x1, 0x55, 0xf9, 0x54, 0x1a, 0xaa, 0xbf, 0xaa,
    0xaf, 0xc0, 0x0, 0x1f, 0x80, 0x0, 0x0, 0x3,
    0xf0, 0x0, 0xfc, 0x0, 0x1, 0xf8, 0x0, 0x0,
    0x0, 0x3f, 0x0, 0xf, 0xc0, 0x0, 0x1f, 0x80,
    0x15, 0x55, 0x57, 0xf5, 0x55, 0xfd, 0x50, 0x1,
    0xf8, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0x1f, 0x80, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0x1, 0xf8, 0x14, 0x0, 0x0, 0x3f,
    0x0, 0xf, 0xc0, 0x0, 0x1f, 0xaf, 0xc0, 0x0,
    0x3, 0xf0, 0x0, 0xfc, 0x0, 0x2, 0xff, 0xfc,
    0x0, 0x0, 0x3f, 0x0, 0xf, 0xc0, 0xb, 0xff,
    0xfe, 0x1, 0x55, 0x57, 0xf5, 0x55, 0xfc, 0xb,
    0xff, 0xfc, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xc0, 0x7f, 0xef, 0x80, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xf8, 0x3, 0x81, 0xf8, 0x0, 0x15, 0x0,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x80, 0x2,
    0xf4, 0x3, 0xf0, 0x0, 0x0, 0x0, 0x1, 0xf8,
    0x0, 0x3f, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0x80, 0x3, 0xf0, 0x3, 0xff, 0xff, 0xfd,
    0x0, 0x1, 0xf8, 0x0, 0x3f, 0x0, 0x3f, 0xff,
    0xff, 0xd0, 0x0, 0x1f, 0x80, 0xb, 0xf0, 0x3,
    0xfa, 0xaa, 0xa8, 0x0, 0x1, 0xf8, 0x0, 0xff,
    0x80, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x80,
    0x1f, 0xfd, 0x3, 0xf0, 0x0, 0x0, 0x0, 0x1,
    0xf8, 0x3, 0xf7, 0xf4, 0x3f, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0x80, 0x7f, 0x1f, 0xe3, 0xf0, 0x0,
    0x0, 0x0, 0x1, 0xf8, 0xf, 0xd0, 0x7f, 0xff,
    0x0, 0x0, 0x0, 0x1a, 0xbf, 0x83, 0xf8, 0x0,
    0xff, 0xff, 0xea, 0xaa, 0x90, 0xff, 0xf0, 0xbf,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xfc, 0xf, 0xf9,
    0x2, 0xc0, 0x0, 0x0, 0x6b, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+6821 "校" */
    0x0, 0x1, 0x50, 0x0, 0x0, 0x1, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x0, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xe0, 0x0, 0x0,
    0x3, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x0,
    0x0, 0x0, 0x2f, 0xc0, 0x0, 0x0, 0x0, 0x7,
    0xe0, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x0, 0x7, 0xd0, 0x0,
    0x0, 0x0, 0x7, 0xe0, 0x1, 0x55, 0x55, 0x65,
    0x55, 0x55, 0x40, 0x0, 0x7e, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x7, 0xe0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff,
    0xff, 0x15, 0x55, 0x55, 0x55, 0x55, 0x50, 0x1f,
    0xff, 0xff, 0xf0, 0x0, 0x90, 0x0, 0x34, 0x0,
    0x0, 0xff, 0xff, 0xff, 0x0, 0x1f, 0xc0, 0xf,
    0xd0, 0x0, 0x0, 0xf, 0xe0, 0x0, 0x3, 0xf4,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0xfe, 0x0, 0x0,
    0xbe, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x1f, 0xf4,
    0x0, 0x1f, 0xc0, 0x0, 0xb, 0xf0, 0x0, 0x2,
    0xff, 0xc0, 0x7, 0xf4, 0x0, 0x0, 0x2f, 0xc0,
    0x0, 0x3f, 0xfe, 0x0, 0xfd, 0x0, 0x0, 0x0,
    0xfe, 0x0, 0x7, 0xff, 0xf0, 0x3f, 0x94, 0x0,
    0x2, 0x43, 0xf4, 0x0, 0xbf, 0xef, 0x8f, 0xeb,
    0xc0, 0x0, 0x3f, 0x1f, 0x40, 0xf, 0xbe, 0x7d,
    0x38, 0x7e, 0x0, 0x7, 0xe0, 0x90, 0x1, 0xf7,
    0xe3, 0xf0, 0x3, 0xf0, 0x0, 0xfd, 0x0, 0x0,
    0x2e, 0x7e, 0x1f, 0x0, 0x1f, 0x80, 0x1f, 0xc0,
    0x0, 0x7, 0xd7, 0xe0, 0xc0, 0x0, 0xfc, 0x2,
    0xf8, 0x0, 0x0, 0xbc, 0x7e, 0x0, 0x0, 0x7,
    0xe0, 0x7f, 0x0, 0x0, 0x1f, 0x87, 0xe0, 0x0,
    0x0, 0x3f, 0x4f, 0xe0, 0x0, 0x2, 0xf0, 0x7e,
    0x0, 0x0, 0x1, 0xfe, 0xfc, 0x0, 0x0, 0x7e,
    0x7, 0xe0, 0x0, 0x0, 0xb, 0xff, 0x40, 0x0,
    0x7, 0xc0, 0x7e, 0x0, 0x0, 0x0, 0x3f, 0xe0,
    0x0, 0x0, 0x28, 0x7, 0xe0, 0x0, 0x0, 0x3,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x0, 0x0,
    0x0, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x7, 0xe0,
    0x0, 0x0, 0x7f, 0xef, 0xf4, 0x0, 0x0, 0x0,
    0x7e, 0x0, 0x0, 0x2f, 0xf0, 0x3f, 0xe0, 0x0,
    0x0, 0x7, 0xe0, 0x0, 0x1f, 0xfc, 0x0, 0xff,
    0xd0, 0x0, 0x0, 0x7e, 0x0, 0xb, 0xfe, 0x0,
    0x2, 0xff, 0xe0, 0x0, 0x7, 0xe0, 0xb, 0xff,
    0x40, 0x0, 0x7, 0xff, 0xc0, 0x0, 0x7e, 0x0,
    0xff, 0x80, 0x0, 0x0, 0xb, 0xf4, 0x0, 0x7,
    0xe0, 0x3, 0x80, 0x0, 0x0, 0x0, 0x6, 0x0,

    /* U+6D41 "流" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x2, 0xf8,
    0x0, 0x0, 0x0, 0x3, 0xf8, 0x0, 0x0, 0x0,
    0xf, 0xc0, 0x0, 0x0, 0x0, 0x3f, 0xf0, 0x0,
    0x0, 0x0, 0xbd, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xd0, 0x0, 0x0, 0x7, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x80, 0x0, 0x0, 0x3f, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xf9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0xb, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0xaa,
    0xab, 0xfe, 0xaa, 0xaa, 0xaa, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0x0, 0x6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xd0, 0x1, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xf8, 0x0, 0xb,
    0xf0, 0x0, 0xe, 0x0, 0x0, 0x0, 0xbf, 0x0,
    0x0, 0x2f, 0xc0, 0x3, 0xfe, 0x0, 0x0, 0x2f,
    0xc0, 0x0, 0x0, 0xfe, 0x0, 0x2f, 0xfd, 0x0,
    0xb, 0xf5, 0x56, 0xab, 0xff, 0xf4, 0x0, 0x2f,
    0xfc, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0,
    0x0, 0x2f, 0xd0, 0x7f, 0xff, 0xff, 0xff, 0xaa,
    0xbf, 0x0, 0x0, 0x78, 0x3, 0xe9, 0x54, 0x0,
    0x0, 0x3, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xe, 0x0, 0x0, 0x0, 0x0,
    0x15, 0x0, 0x54, 0x1, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xf0, 0xf, 0xc0, 0x3f, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0x0, 0xfc, 0x3, 0xf0,
    0x0, 0x0, 0x0, 0x30, 0x3, 0xf0, 0xf, 0xc0,
    0x3f, 0x0, 0x0, 0x0, 0xb, 0xd0, 0x3f, 0x0,
    0xfc, 0x3, 0xf0, 0x0, 0x0, 0x0, 0xfc, 0x3,
    0xf0, 0xf, 0xc0, 0x3f, 0x0, 0x0, 0x0, 0x2f,
    0x80, 0x3f, 0x0, 0xfc, 0x3, 0xf0, 0x0, 0x0,
    0x7, 0xf0, 0x7, 0xe0, 0xf, 0xc0, 0x3f, 0x0,
    0x0, 0x0, 0xfe, 0x0, 0x7e, 0x0, 0xfc, 0x3,
    0xf0, 0x0, 0x0, 0x1f, 0xc0, 0xb, 0xd0, 0xf,
    0xc0, 0x3f, 0x0, 0x0, 0x3, 0xf4, 0x0, 0xfc,
    0x0, 0xfc, 0x3, 0xf0, 0x38, 0x0, 0xbf, 0x0,
    0x1f, 0x80, 0xf, 0xc0, 0x3f, 0x3, 0xd0, 0x1f,
    0xd0, 0x3, 0xf4, 0x0, 0xfc, 0x3, 0xf0, 0x3d,
    0x3, 0xf8, 0x0, 0xbf, 0x0, 0xf, 0xc0, 0x3f,
    0x3, 0xd0, 0xbf, 0x0, 0x2f, 0xc0, 0x0, 0xfc,
    0x3, 0xf0, 0x3d, 0xf, 0xe0, 0xb, 0xf4, 0x0,
    0xf, 0xc0, 0x2f, 0xff, 0xc0, 0x3c, 0x0, 0xbd,
    0x0, 0x0, 0x50, 0x1, 0xff, 0xf4, 0x0, 0x0,
    0x2, 0x40, 0x0, 0x0, 0x0, 0x1, 0x54, 0x0,

    /* U+7535 "电" */
    0x0, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xf4, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0xaa, 0xaa, 0xaa, 0xbf, 0xea,
    0xaa, 0xaa, 0x90, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xf, 0xd5, 0x55, 0x57,
    0xf5, 0x55, 0x55, 0xbe, 0x0, 0xfd, 0x0, 0x0,
    0x3f, 0x40, 0x0, 0xb, 0xe0, 0xf, 0xd0, 0x0,
    0x3, 0xf4, 0x0, 0x0, 0xbe, 0x0, 0xfd, 0x0,
    0x0, 0x3f, 0x40, 0x0, 0xb, 0xe0, 0xf, 0xd0,
    0x0, 0x3, 0xf4, 0x0, 0x0, 0xbe, 0x0, 0xfd,
    0x0, 0x0, 0x3f, 0x40, 0x0, 0xb, 0xe0, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0xfd, 0x0, 0x0, 0x3f, 0x40, 0x0, 0xb,
    0xe0, 0xf, 0xd0, 0x0, 0x3, 0xf4, 0x0, 0x0,
    0xbe, 0x0, 0xfd, 0x0, 0x0, 0x3f, 0x40, 0x0,
    0xb, 0xe0, 0xf, 0xd0, 0x0, 0x3, 0xf4, 0x0,
    0x0, 0xbe, 0x0, 0xfd, 0x0, 0x0, 0x3f, 0x40,
    0x0, 0xb, 0xe0, 0xf, 0xe5, 0x55, 0x57, 0xf9,
    0x55, 0x55, 0xbe, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0xfd, 0x55, 0x55,
    0x7f, 0x55, 0x55, 0x55, 0x40, 0xf, 0xd0, 0x0,
    0x3, 0xf4, 0x0, 0x0, 0x0, 0x90, 0xbc, 0x0,
    0x0, 0x3f, 0x40, 0x0, 0x0, 0xf, 0xc0, 0x0,
    0x0, 0x3, 0xf4, 0x0, 0x0, 0x0, 0xfd, 0x0,
    0x0, 0x0, 0x3f, 0x40, 0x0, 0x0, 0xf, 0xc0,
    0x0, 0x0, 0x3, 0xf4, 0x0, 0x0, 0x0, 0xfc,
    0x0, 0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x2f,
    0x80, 0x0, 0x0, 0x2, 0xff, 0x95, 0x55, 0x6f,
    0xf4, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x15, 0x55,
    0x55, 0x40, 0x0,

    /* U+7EA7 "级" */
    0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0x40, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x40,
    0x3f, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x0, 0x7,
    0xf0, 0x3, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0xbd, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x1f, 0xc0, 0x0, 0x2, 0xf4, 0x0,
    0x7e, 0x0, 0x0, 0x2, 0xf4, 0x0, 0x0, 0x2f,
    0x40, 0xb, 0xd0, 0x0, 0x0, 0x7f, 0x0, 0x0,
    0x3, 0xf4, 0x0, 0xfc, 0x0, 0x0, 0xf, 0xc0,
    0xd, 0x0, 0x3f, 0x40, 0xf, 0x80, 0x0, 0x1,
    0xf8, 0x2, 0xf8, 0x3, 0xf0, 0x1, 0xf4, 0x0,
    0x0, 0x3f, 0x0, 0x7f, 0x0, 0x3f, 0x0, 0x3f,
    0x0, 0x0, 0xb, 0xd0, 0xf, 0xd0, 0x3, 0xf0,
    0x3, 0xf0, 0x0, 0x2, 0xf8, 0x5b, 0xfc, 0x0,
    0x3f, 0x0, 0x7e, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0x0, 0x3, 0xf0, 0xb, 0xff, 0xfd, 0x3, 0xff,
    0xff, 0xd0, 0x0, 0x3f, 0x40, 0xff, 0xff, 0xe0,
    0x3e, 0x51, 0xfc, 0x0, 0x7, 0xf8, 0xa, 0xaa,
    0xfd, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x7f, 0xc0,
    0x0, 0xf, 0xc0, 0x0, 0xf, 0xd0, 0x0, 0xb,
    0xfe, 0x0, 0x0, 0xfc, 0x0, 0x2, 0xf8, 0x0,
    0x0, 0xbf, 0xf0, 0x0, 0x1f, 0x80, 0x0, 0x7f,
    0x0, 0x74, 0xf, 0xef, 0x40, 0x3, 0xf0, 0x0,
    0x1f, 0xc6, 0xff, 0x40, 0xfc, 0xfc, 0x0, 0x7f,
    0x0, 0x3, 0xff, 0xff, 0xf4, 0x1f, 0x8b, 0xe0,
    0xb, 0xd0, 0x1, 0xff, 0xff, 0x90, 0x1, 0xf8,
    0x3f, 0x1, 0xfc, 0x0, 0x3f, 0xfe, 0x40, 0x0,
    0x2f, 0x42, 0xf8, 0x2f, 0x40, 0x3, 0xf9, 0x0,
    0x0, 0x3, 0xf0, 0xf, 0xd7, 0xf0, 0x0, 0x14,
    0x0, 0x0, 0x0, 0x3e, 0x0, 0x7f, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x7, 0x8b, 0xd0, 0x2, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x1b, 0xfc, 0xfc, 0x0,
    0xf, 0xf0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0x9f,
    0xc0, 0x2, 0xff, 0x80, 0x0, 0x1, 0xbf, 0xff,
    0x42, 0xf4, 0x0, 0xbf, 0xfe, 0x0, 0x2, 0xff,
    0xfe, 0x0, 0x7f, 0x0, 0x2f, 0xdb, 0xf8, 0x0,
    0x3f, 0xf9, 0x0, 0xb, 0xe0, 0x1f, 0xf4, 0x2f,
    0xf0, 0x2, 0xf4, 0x0, 0x1, 0xfc, 0xb, 0xfd,
    0x0, 0xbf, 0xd0, 0x10, 0x0, 0x0, 0x3f, 0x87,
    0xff, 0x0, 0x1, 0xff, 0xc0, 0x0, 0x0, 0x7,
    0xf0, 0x7f, 0x80, 0x0, 0x3, 0xf8, 0x0, 0x0,
    0x0, 0xd, 0x2, 0xd0, 0x0, 0x0, 0xb, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_h = 0, .box_w = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 640, .box_h = 34, .box_w = 36, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 306, .adv_w = 640, .box_h = 37, .box_w = 37, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 649, .adv_w = 640, .box_h = 37, .box_w = 36, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 982, .adv_w = 640, .box_h = 37, .box_w = 36, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1315, .adv_w = 640, .box_h = 36, .box_w = 37, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1648, .adv_w = 640, .box_h = 35, .box_w = 37, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1972, .adv_w = 640, .box_h = 36, .box_w = 34, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 2278, .adv_w = 640, .box_h = 38, .box_w = 38, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 2639, .adv_w = 640, .box_h = 38, .box_w = 38, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 3000, .adv_w = 640, .box_h = 37, .box_w = 38, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 3352, .adv_w = 640, .box_h = 37, .box_w = 38, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 3704, .adv_w = 640, .box_h = 37, .box_w = 34, .ofs_x = 5, .ofs_y = -3},
    {.bitmap_index = 4019, .adv_w = 640, .box_h = 38, .box_w = 38, .ofs_x = 1, .ofs_y = -4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static uint16_t unicode_list_0[] = {
    0x0, 0x68, 0x2e5, 0x338, 0x4b9, 0x4fd, 0x86c, 0x115d,
    0x14e9, 0x1993, 0x1eb3, 0x26a7, 0x3019
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 20110, .range_length = 12314, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY,
        .glyph_id_start = 1, .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 13
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .cmap_num = 1,
    .bpp = 2,

    .kern_scale = 0,
    .kern_dsc = NULL,
    .kern_classes = 0,
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t font_chinese_40 = {
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .line_height = 38,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
};

#endif /*#if FONT_CHINESE_40*/

