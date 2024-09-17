/*******************************************************************************
 * Size: 20 px
 * Bpp: 2
 * Opts: --user-data-dir=/Users/xczhang/Library/Application Support/eezstudio --app-path=/Applications/EEZ Studio.app/Contents/Resources/app.asar --no-sandbox --no-zygote --node-integration-in-worker --lang=zh-CN --num-raster-threads=4 --enable-zero-copy --enable-gpu-memory-buffer-compositor-resources --enable-main-frame-before-activation --renderer-client-id=5 --time-ticks-at-unix-epoch=-1726346829551826 --launch-time-ticks=232410675802 --shared-files --field-trial-handle=1718379636,r,3096376243392545519,5127449384929056755,262144 --enable-features=kWebSQLAccess --disable-features=SpareRendererForSitePerProcess --variations-seed-version
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef UI_FONT_LCD_FONT_20
#define UI_FONT_LCD_FONT_20 1
#endif

#if UI_FONT_LCD_FONT_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x0, 0x83, 0x4d, 0x34, 0xd2, 0x40, 0x34, 0xd3,
    0x40, 0x10, 0xd0,

    /* U+0022 "\"" */
    0x34, 0xd3, 0x4d, 0x34, 0xd1, 0x4,

    /* U+0023 "#" */
    0x0, 0x0, 0x0, 0xc7, 0x0, 0x31, 0xc0, 0xf3,
    0x8e, 0x7, 0x5d, 0x0, 0xc7, 0x3, 0xce, 0x38,
    0x1d, 0x74, 0x3, 0x1c, 0x0, 0x0, 0x0,

    /* U+0024 "$" */
    0x0, 0x0, 0x0, 0x24, 0x0, 0x5, 0x0, 0xff,
    0xfd, 0x29, 0x55, 0xd, 0x38, 0x3, 0x4e, 0x0,
    0xd3, 0x80, 0x30, 0x50, 0x7, 0xff, 0x80, 0x19,
    0x68, 0x3, 0x8e, 0x0, 0xe3, 0x80, 0x38, 0xe0,
    0x55, 0x78, 0xff, 0xf9, 0x0, 0x50, 0x0, 0x24,
    0x0, 0x0, 0x0,

    /* U+0025 "%" */
    0x3f, 0x81, 0xc2, 0x9d, 0x3c, 0x34, 0xd7, 0x43,
    0xbc, 0xf0, 0x1, 0x1d, 0x0, 0x1, 0xc0, 0x0,
    0x0, 0x0, 0xd, 0x0, 0x1, 0xc0, 0x0, 0x3c,
    0xfb, 0x7, 0x59, 0xb0, 0xf1, 0xda, 0xd, 0xb,
    0xe0,

    /* U+0026 "&" */
    0x0, 0x0, 0x0, 0xff, 0xa0, 0x19, 0x5b, 0x1,
    0xc0, 0xb0, 0x1c, 0xb, 0x0, 0x40, 0x10, 0xf,
    0xfe, 0x3, 0x55, 0x68, 0x34, 0x3, 0x83, 0x40,
    0x38, 0x34, 0x3, 0x82, 0x95, 0x64, 0x3f, 0xff,
    0xc0, 0x0, 0x14, 0x0, 0x0, 0x40,

    /* U+0027 "'" */
    0x34, 0xd3, 0x44,

    /* U+0028 "(" */
    0xb, 0xc2, 0x54, 0x34, 0x3, 0x40, 0x34, 0x3,
    0x0, 0x0, 0x3, 0x0, 0x34, 0x3, 0x40, 0x34,
    0x3, 0x54, 0xb, 0xc0,

    /* U+0029 ")" */
    0x3f, 0x1, 0x5c, 0x0, 0xd0, 0xd, 0x0, 0xd0,
    0x9, 0x0, 0x0, 0x9, 0x0, 0xd0, 0xd, 0x0,
    0xd1, 0x5c, 0x3f, 0x0,

    /* U+002A "*" */
    0x1, 0x40, 0x4e, 0x53, 0xff, 0x83, 0xfc, 0x3f,
    0xf8, 0x4e, 0x50, 0x14, 0x0,

    /* U+002B "+" */
    0x0, 0x0, 0x2, 0x80, 0x3, 0xc0, 0x3f, 0xfc,
    0x7, 0xd0, 0x2, 0x80, 0x0, 0x0,

    /* U+002C "," */
    0x34, 0xd3, 0x44,

    /* U+002D "-" */
    0x0, 0x0, 0x3f, 0xfc, 0x5, 0x50,

    /* U+002E "." */
    0x10, 0xd0,

    /* U+002F "/" */
    0x0, 0x3, 0x40, 0x2, 0xc0, 0x0, 0xe0, 0x0,
    0xb0, 0x0, 0x38, 0x0, 0xc, 0x0, 0x1, 0x0,
    0xa, 0x0, 0x3, 0x40, 0x2, 0xc0, 0x0, 0xe0,
    0x0, 0xb0, 0x0, 0x28, 0x0, 0x0,

    /* U+0030 "0" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0031 "1" */
    0x20, 0xd3, 0x4d, 0x34, 0xd0, 0xd, 0x34, 0xd3,
    0x4d, 0x20,

    /* U+0032 "2" */
    0x3f, 0xfe, 0x41, 0x55, 0xe0, 0x0, 0x38, 0x0,
    0xe, 0x0, 0x3, 0x80, 0x0, 0xa0, 0xff, 0xe0,
    0xd5, 0x50, 0x34, 0x0, 0xd, 0x0, 0x3, 0x40,
    0x0, 0xa5, 0x50, 0x3f, 0xfe, 0x0,

    /* U+0033 "3" */
    0x3f, 0xfe, 0x41, 0x55, 0xe0, 0x0, 0x38, 0x0,
    0xe, 0x0, 0x3, 0x80, 0x0, 0xa0, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0034 "4" */
    0x0, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x0, 0xe, 0x0, 0x2, 0x40, 0x0, 0x0,

    /* U+0035 "5" */
    0x3f, 0xfe, 0xa, 0x55, 0x3, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xd, 0x0, 0x1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0036 "6" */
    0x3f, 0xfe, 0xa, 0x55, 0x3, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xd, 0x0, 0x1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0037 "7" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0x0, 0xa, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x0, 0xe, 0x0, 0x2, 0x40,

    /* U+0038 "8" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0039 "9" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+003A ":" */
    0x0, 0xd1, 0x0, 0x0, 0x0, 0xd, 0x10,

    /* U+003B ";" */
    0x0, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x83,
    0x4d, 0x20,

    /* U+003C "<" */
    0x0, 0x50, 0x2d, 0xb, 0x42, 0xd0, 0x28, 0x0,
    0xf0, 0x3, 0xc0, 0xe,

    /* U+003D "=" */
    0x0, 0x0, 0x3f, 0xfc, 0x5, 0x50, 0x0, 0x0,
    0x3f, 0xfc, 0x5, 0x50,

    /* U+003E ">" */
    0x14, 0x2, 0xd0, 0xb, 0x40, 0x2d, 0x1, 0x90,
    0x78, 0x1e, 0x3, 0x80,

    /* U+003F "?" */
    0x3f, 0xfe, 0x41, 0x55, 0xe0, 0x0, 0x38, 0x0,
    0xe, 0x0, 0x3, 0x80, 0x0, 0xa0, 0xff, 0xe0,
    0xd5, 0x50, 0x34, 0x0, 0xd, 0x0, 0x0, 0x0,
    0x0, 0x40, 0x0, 0x34, 0x0, 0x0,

    /* U+0040 "@" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd3,
    0xee, 0x34, 0x93, 0x8c, 0x30, 0xa0, 0x0, 0x0,
    0xc3, 0x6, 0x34, 0xd3, 0x8d, 0x3f, 0x93, 0x41,
    0x40, 0xa5, 0x50, 0x3f, 0xfc, 0x0,

    /* U+0041 "A" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+0042 "B" */
    0x3f, 0xfc, 0xa, 0x55, 0xc3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5d, 0x3f, 0xfc, 0x0,

    /* U+0043 "C" */
    0x3f, 0xfe, 0x29, 0x54, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x30, 0x0, 0x0, 0x0, 0x30, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x29, 0x54,
    0x3f, 0xfe,

    /* U+0044 "D" */
    0x3f, 0xfc, 0xa, 0x55, 0xd3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5d, 0x3f, 0xfc, 0x0,

    /* U+0045 "E" */
    0x3f, 0xfe, 0x29, 0x54, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x1f, 0xfe, 0x35, 0x54,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x29, 0x54,
    0x3f, 0xfe,

    /* U+0046 "F" */
    0x3f, 0xfe, 0x29, 0x54, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x1f, 0xfe, 0x35, 0x54,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x34, 0x0,
    0x30, 0x0, 0x0, 0x0,

    /* U+0047 "G" */
    0x3f, 0xfe, 0xa, 0x55, 0x3, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xc, 0x0, 0x0, 0x3, 0xe0,
    0xc0, 0x1a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0048 "H" */
    0x10, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+0049 "I" */
    0x20, 0xd3, 0x4d, 0x34, 0xd0, 0xd, 0x34, 0xd3,
    0x4d, 0x10,

    /* U+004A "J" */
    0x0, 0x2, 0x40, 0x0, 0xe0, 0x0, 0x38, 0x0,
    0xe, 0x0, 0x3, 0x80, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+004B "K" */
    0x20, 0x7, 0x4d, 0x7, 0x83, 0x47, 0xc0, 0xd7,
    0xc0, 0x3b, 0xc0, 0xd, 0x80, 0x1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+004C "L" */
    0x20, 0x0, 0xd, 0x0, 0x3, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xc, 0x0, 0x0, 0x0, 0x0,
    0xc0, 0x0, 0x34, 0x0, 0xd, 0x0, 0x3, 0x40,
    0x0, 0xd5, 0x54, 0x2b, 0xff, 0x40,

    /* U+004D "M" */
    0x3f, 0xfe, 0x49, 0x65, 0xe3, 0x4d, 0x38, 0xd3,
    0x4e, 0x34, 0xd3, 0x8c, 0x34, 0xa0, 0x8, 0x0,
    0xc0, 0x6, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+004E "N" */
    0x0, 0x0, 0xc, 0x0, 0x93, 0xb4, 0x38, 0xdf,
    0x4e, 0x34, 0xf3, 0x8d, 0xe, 0xe3, 0x0, 0x18,
    0x40, 0x1, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x3, 0x84, 0x0, 0x0,

    /* U+004F "O" */
    0xb, 0xfc, 0x9, 0x55, 0xd3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd5, 0x5d, 0xb, 0xfc, 0x0,

    /* U+0050 "P" */
    0x3f, 0xfc, 0xa, 0x55, 0xc3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x50, 0x34, 0x0, 0xd, 0x0, 0x3, 0x40,
    0x0, 0xd0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0,

    /* U+0051 "Q" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x42,
    0xe8, 0xa5, 0x7d, 0x3f, 0xfb, 0x80,

    /* U+0052 "R" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd9, 0x50, 0x3b, 0x80, 0xd, 0x78, 0x3, 0x47,
    0x80, 0xd0, 0x78, 0x20, 0x7, 0x40,

    /* U+0053 "S" */
    0x3f, 0xff, 0x4a, 0x55, 0x43, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xd, 0x0, 0x1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0054 "T" */
    0x3f, 0xff, 0x41, 0x65, 0x40, 0xd, 0x0, 0x3,
    0x40, 0x0, 0xd0, 0x0, 0x34, 0x0, 0x0, 0x0,
    0x3, 0x40, 0x0, 0xd0, 0x0, 0x34, 0x0, 0xd,
    0x0, 0x3, 0x40, 0x0, 0x90, 0x0, 0x0, 0x0,

    /* U+0055 "U" */
    0x20, 0x2, 0x4d, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa1, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0056 "V" */
    0x20, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0x6, 0x3c, 0x7, 0x43, 0x83, 0x80, 0x77,
    0xc0, 0xa, 0xc0, 0x0, 0x50, 0x0,

    /* U+0057 "W" */
    0x0, 0x0, 0xc, 0x0, 0x93, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x0, 0x18,
    0x2, 0x0, 0x30, 0xd2, 0x8d, 0x34, 0xe3, 0x4d,
    0x38, 0xd3, 0x4e, 0x25, 0x57, 0x8f, 0xff, 0x90,

    /* U+0058 "X" */
    0x28, 0x3, 0x4b, 0x2, 0xc0, 0xe0, 0xe0, 0x2c,
    0xb0, 0x3, 0xb8, 0x0, 0xac, 0x0, 0x6, 0x0,
    0xa, 0xc0, 0x3, 0xb8, 0x2, 0xcb, 0x0, 0xe0,
    0xe0, 0xb0, 0x2c, 0x28, 0x3, 0x40,

    /* U+0059 "Y" */
    0x0, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+005A "Z" */
    0x3f, 0xfb, 0x41, 0x56, 0xc0, 0x0, 0xe0, 0x0,
    0x70, 0x0, 0x38, 0x0, 0x1c, 0x0, 0x5, 0x0,
    0xb, 0x0, 0x3, 0x80, 0x2, 0xc0, 0x0, 0xe0,
    0x0, 0xb5, 0x50, 0x2b, 0xfe, 0x0,

    /* U+005B "[" */
    0x3f, 0x4a, 0x43, 0x40, 0xd0, 0x34, 0xc, 0x0,
    0x0, 0xc0, 0x34, 0xd, 0x3, 0x40, 0xa4, 0x3f,
    0x40,

    /* U+005C "\\" */
    0x28, 0x0, 0xb, 0x0, 0x0, 0xe0, 0x0, 0x2c,
    0x0, 0x3, 0x40, 0x0, 0xa0, 0x0, 0x0, 0x0,
    0x0, 0xc0, 0x0, 0x38, 0x0, 0xb, 0x0, 0x0,
    0xe0, 0x0, 0x2c, 0x0, 0x3, 0x40,

    /* U+005D "]" */
    0x3e, 0x41, 0xa0, 0x28, 0xa, 0x2, 0x80, 0x60,
    0x0, 0x6, 0x2, 0x80, 0xa0, 0x28, 0x1a, 0x3e,
    0x40,

    /* U+005E "^" */
    0x0, 0x50, 0x0, 0xed, 0x0, 0xf2, 0xd0, 0xf0,
    0x2d, 0x20, 0x2, 0x40,

    /* U+005F "_" */
    0x0, 0x0, 0xf, 0xff, 0xd0, 0x55, 0x50,

    /* U+0060 "`" */
    0x34, 0x7, 0x40, 0x70, 0x0,

    /* U+0061 "a" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+0062 "b" */
    0x3f, 0xfc, 0xa, 0x55, 0xc3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5d, 0x3f, 0xfc, 0x0,

    /* U+0063 "c" */
    0x3f, 0xfe, 0x29, 0x54, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x30, 0x0, 0x0, 0x0, 0x30, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x29, 0x54,
    0x3f, 0xfe,

    /* U+0064 "d" */
    0x3f, 0xfc, 0xa, 0x55, 0xd3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5d, 0x3f, 0xfc, 0x0,

    /* U+0065 "e" */
    0x3f, 0xfe, 0x29, 0x54, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x1f, 0xfe, 0x35, 0x54,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x29, 0x54,
    0x3f, 0xfe,

    /* U+0066 "f" */
    0x3f, 0xfe, 0x29, 0x54, 0x34, 0x0, 0x34, 0x0,
    0x34, 0x0, 0x34, 0x0, 0x1f, 0xfe, 0x35, 0x54,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x34, 0x0,
    0x30, 0x0, 0x0, 0x0,

    /* U+0067 "g" */
    0x3f, 0xfe, 0xa, 0x55, 0x3, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xc, 0x0, 0x0, 0x3, 0xe0,
    0xc0, 0x1a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0068 "h" */
    0x10, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+0069 "i" */
    0x20, 0xd3, 0x4d, 0x34, 0xd0, 0xd, 0x34, 0xd3,
    0x4d, 0x10,

    /* U+006A "j" */
    0x0, 0x2, 0x40, 0x0, 0xe0, 0x0, 0x38, 0x0,
    0xe, 0x0, 0x3, 0x80, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+006B "k" */
    0x20, 0x7, 0x4d, 0x7, 0x83, 0x47, 0xc0, 0xd7,
    0xc0, 0x3b, 0xc0, 0xd, 0x80, 0x1, 0xff, 0xe0,
    0xd5, 0x5a, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+006C "l" */
    0x20, 0x0, 0xd, 0x0, 0x3, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xc, 0x0, 0x0, 0x0, 0x0,
    0xc0, 0x0, 0x34, 0x0, 0xd, 0x0, 0x3, 0x40,
    0x0, 0xd5, 0x54, 0x2b, 0xff, 0x40,

    /* U+006D "m" */
    0x3f, 0xfe, 0x49, 0x65, 0xe3, 0x4d, 0x38, 0xd3,
    0x4e, 0x34, 0xd3, 0x8c, 0x34, 0xa0, 0x8, 0x0,
    0xc0, 0x6, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x2, 0x40, 0x0, 0x0,

    /* U+006E "n" */
    0x0, 0x0, 0xc, 0x0, 0x93, 0xb4, 0x38, 0xdf,
    0x4e, 0x34, 0xf3, 0x8d, 0xe, 0xe3, 0x0, 0x18,
    0x40, 0x1, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd0, 0xe, 0x30, 0x3, 0x84, 0x0, 0x0,

    /* U+006F "o" */
    0xb, 0xfc, 0x9, 0x55, 0xd3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xd5, 0x5d, 0xb, 0xfc, 0x0,

    /* U+0070 "p" */
    0x3f, 0xfc, 0xa, 0x55, 0xc3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd5, 0x50, 0x34, 0x0, 0xd, 0x0, 0x3, 0x40,
    0x0, 0xd0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0,

    /* U+0071 "q" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x42,
    0xe8, 0xa5, 0x7d, 0x3f, 0xfb, 0x80,

    /* U+0072 "r" */
    0x3f, 0xfe, 0x4a, 0x55, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0xd9, 0x50, 0x3b, 0x80, 0xd, 0x78, 0x3, 0x47,
    0x80, 0xd0, 0x78, 0x20, 0x7, 0x40,

    /* U+0073 "s" */
    0x3f, 0xff, 0x4a, 0x55, 0x43, 0x40, 0x0, 0xd0,
    0x0, 0x34, 0x0, 0xd, 0x0, 0x1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0074 "t" */
    0x3f, 0xff, 0x41, 0x65, 0x40, 0xd, 0x0, 0x3,
    0x40, 0x0, 0xd0, 0x0, 0x34, 0x0, 0x0, 0x0,
    0x3, 0x40, 0x0, 0xd0, 0x0, 0x34, 0x0, 0xd,
    0x0, 0x3, 0x40, 0x0, 0x90, 0x0, 0x0, 0x0,

    /* U+0075 "u" */
    0x20, 0x2, 0x4d, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa1, 0x0, 0x0,
    0xc0, 0xa, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x40,
    0x38, 0xa5, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+0076 "v" */
    0x20, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8c, 0x0, 0xa0, 0x0, 0x0,
    0xc0, 0x6, 0x3c, 0x7, 0x43, 0x83, 0x80, 0x77,
    0xc0, 0xa, 0xc0, 0x0, 0x50, 0x0,

    /* U+0077 "w" */
    0x0, 0x0, 0xc, 0x0, 0x93, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xe3, 0x0, 0x18,
    0x2, 0x0, 0x30, 0xd2, 0x8d, 0x34, 0xe3, 0x4d,
    0x38, 0xd3, 0x4e, 0x25, 0x57, 0x8f, 0xff, 0x90,

    /* U+0078 "x" */
    0x28, 0x3, 0x4b, 0x2, 0xc0, 0xe0, 0xe0, 0x2c,
    0xb0, 0x3, 0xb8, 0x0, 0xac, 0x0, 0x6, 0x0,
    0xa, 0xc0, 0x3, 0xb8, 0x2, 0xcb, 0x0, 0xe0,
    0xe0, 0xb0, 0x2c, 0x28, 0x3, 0x40,

    /* U+0079 "y" */
    0x0, 0x1, 0xd, 0x0, 0xe3, 0x40, 0x38, 0xd0,
    0xe, 0x34, 0x3, 0x8d, 0x0, 0xa1, 0xff, 0xe0,
    0x5, 0x5a, 0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,
    0x38, 0x15, 0x5e, 0x3f, 0xfe, 0x40,

    /* U+007A "z" */
    0x3f, 0xfb, 0x41, 0x56, 0xc0, 0x0, 0xe0, 0x0,
    0x70, 0x0, 0x38, 0x0, 0x1c, 0x0, 0x5, 0x0,
    0xb, 0x0, 0x3, 0x80, 0x2, 0xc0, 0x0, 0xe0,
    0x0, 0xb5, 0x50, 0x2b, 0xfe, 0x0,

    /* U+007B "{" */
    0x2, 0xf8, 0xa, 0x40, 0x38, 0x0, 0xe0, 0x3,
    0x80, 0xa, 0x3, 0xd0, 0x1, 0xa0, 0x3, 0x80,
    0xe, 0x0, 0x38, 0x0, 0xa4, 0x2, 0xf8,

    /* U+007C "|" */
    0x20, 0xd3, 0x4d, 0x34, 0xd3, 0x4d, 0x34, 0xd3,
    0x4d, 0x20,

    /* U+007D "}" */
    0x3f, 0x40, 0x19, 0x0, 0x28, 0x0, 0xa0, 0x2,
    0x80, 0xa, 0x0, 0xb, 0x80, 0x94, 0x2, 0x80,
    0xa, 0x0, 0x28, 0x1, 0x90, 0x3f, 0x40,

    /* U+007E "~" */
    0x0, 0x0, 0x1, 0xd0, 0x3, 0xde, 0x38, 0x0,
    0xb4, 0x0, 0x4, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 87, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 52, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 99, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 17, .adv_w = 157, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 40, .adv_w = 151, .box_w = 9, .box_h = 19, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 83, .adv_w = 175, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 163, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 154, .adv_w = 52, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 157, .adv_w = 102, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 102, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 125, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 210, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 224, .adv_w = 52, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 227, .adv_w = 128, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 233, .adv_w = 52, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 52, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 397, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 52, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 554, .adv_w = 52, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 564, .adv_w = 108, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 576, .adv_w = 128, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 588, .adv_w = 108, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 600, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 630, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 692, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 722, .adv_w = 140, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 778, .adv_w = 140, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 804, .adv_w = 140, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 832, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 862, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 894, .adv_w = 52, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 904, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 966, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 996, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1028, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1060, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1090, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1122, .adv_w = 154, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1152, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1182, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1212, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1244, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1274, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1304, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1336, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1366, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1396, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1426, .adv_w = 90, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1443, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1473, .adv_w = 90, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1490, .adv_w = 151, .box_w = 9, .box_h = 5, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 1502, .adv_w = 151, .box_w = 9, .box_h = 3, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1509, .adv_w = 81, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 1514, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1546, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1576, .adv_w = 140, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1602, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1632, .adv_w = 140, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1658, .adv_w = 140, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1686, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1716, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1748, .adv_w = 52, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1758, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1788, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1820, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1850, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1882, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1914, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1944, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1976, .adv_w = 154, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2006, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2036, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2066, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2098, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2128, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2158, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2190, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2220, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2250, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2280, .adv_w = 125, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2303, .adv_w = 52, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2313, .adv_w = 125, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2336, .adv_w = 157, .box_w = 9, .box_h = 5, .ofs_x = 0, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_lcd_font_20 = {
#else
lv_font_t ui_font_lcd_font_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if UI_FONT_LCD_FONT_20*/

