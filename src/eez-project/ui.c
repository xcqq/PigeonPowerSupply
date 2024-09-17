#if defined(EEZ_FOR_LVGL)
#include <eez/core/vars.h>
#endif

#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"

// ASSETS DEFINITION
const uint8_t assets[1633] = {
    0x7E, 0x65, 0x65, 0x7A, 0x03, 0x00, 0x06, 0x00, 0x58, 0x10, 0x00, 0x00, 0x6E, 0x24, 0x00, 0x00,
    0x00, 0x24, 0x00, 0x01, 0x00, 0x17, 0x20, 0x0C, 0x00, 0x53, 0x40, 0x01, 0xF0, 0x00, 0x01, 0x28,
    0x00, 0x13, 0x02, 0x1C, 0x00, 0xF3, 0x02, 0x04, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x12,
    0x00, 0x00, 0x00, 0x5C, 0x0E, 0x00, 0x00, 0x0D, 0x10, 0x00, 0x11, 0x4C, 0x32, 0x00, 0xF0, 0x0C,
    0xFF, 0xFF, 0x50, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00, 0xBC, 0x00,
    0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xEC, 0x00, 0x00, 0x00, 0xF8, 0x3C, 0x00, 0xF0, 0x02, 0x01,
    0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x1C, 0x01, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00, 0x34, 0x01,
    0x64, 0x00, 0xF2, 0x05, 0x00, 0x00, 0x4C, 0x01, 0x00, 0x00, 0x58, 0x01, 0x00, 0x00, 0x64, 0x01,
    0x00, 0x00, 0x70, 0x01, 0x00, 0x00, 0x7C, 0x01, 0x70, 0x00, 0x00, 0x08, 0x00, 0x71, 0x13, 0x00,
    0x00, 0x00, 0x78, 0x01, 0x00, 0x88, 0x00, 0x13, 0xBC, 0x18, 0x00, 0x3F, 0x2C, 0x0E, 0x00, 0x01,
    0x00, 0x26, 0x13, 0x08, 0x50, 0x00, 0x04, 0x01, 0x00, 0x10, 0x07, 0xA4, 0x00, 0x1F, 0x0D, 0x28,
    0x00, 0x03, 0x1B, 0x70, 0x28, 0x00, 0x2E, 0xC0, 0x0D, 0x28, 0x00, 0x1F, 0x07, 0x10, 0x00, 0x3C,
    0x1F, 0x02, 0x20, 0x00, 0x14, 0x1B, 0x01, 0x20, 0x00, 0x1B, 0x0A, 0x10, 0x00, 0x1B, 0x05, 0x10,
    0x00, 0x2A, 0x30, 0x75, 0x10, 0x00, 0x2F, 0x88, 0x13, 0x60, 0x00, 0x03, 0xF3, 0x0A, 0x64, 0x65,
    0x66, 0x61, 0x75, 0x6C, 0x74, 0x00, 0xFF, 0xFF, 0x08, 0x42, 0x90, 0x00, 0x00, 0x00, 0xAC, 0x00,
    0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0xE4, 0x75, 0x00, 0x00, 0xBC, 0x01, 0x53, 0x38, 0x01, 0x00,
    0x00, 0x54, 0xAC, 0x01, 0xF6, 0x5F, 0x8C, 0x01, 0x00, 0x00, 0xA8, 0x01, 0x00, 0x00, 0xC4, 0x01,
    0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0xFC, 0x01, 0x00, 0x00, 0x18, 0x02, 0x00, 0x00, 0x34, 0x02,
    0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 0x6C, 0x02, 0x00, 0x00, 0x88, 0x02, 0x00, 0x00, 0xA8, 0x02,
    0x00, 0x00, 0xB4, 0x02, 0x00, 0x00, 0xD8, 0x02, 0x00, 0x00, 0xFC, 0x02, 0x00, 0x00, 0x20, 0x03,
    0x00, 0x00, 0x44, 0x03, 0x00, 0x00, 0x68, 0x03, 0x00, 0x00, 0x8C, 0x03, 0x00, 0x00, 0xB0, 0x03,
    0x00, 0x00, 0xD0, 0x03, 0x00, 0x00, 0xF4, 0x03, 0x00, 0x00, 0x18, 0x04, 0x00, 0x00, 0x3C, 0x04,
    0x00, 0x00, 0x60, 0x04, 0x00, 0x00, 0x84, 0x04, 0x00, 0x00, 0xA8, 0x04, 0x00, 0x00, 0xCC, 0x04,
    0x00, 0x00, 0x20, 0x4E, 0xA8, 0x00, 0x00, 0x88, 0x02, 0x26, 0xDC, 0x04, 0x10, 0x00, 0x57, 0xFF,
    0xFF, 0x00, 0x00, 0x21, 0x20, 0x00, 0x22, 0x03, 0x00, 0x34, 0x00, 0x08, 0x20, 0x00, 0x0C, 0x40,
    0x00, 0x1F, 0xB8, 0x20, 0x00, 0x0C, 0x1F, 0xA8, 0x20, 0x00, 0x0C, 0x1F, 0x98, 0x20, 0x00, 0x08,
    0x10, 0x05, 0x64, 0x01, 0x0F, 0x20, 0x00, 0x0C, 0x1F, 0x7C, 0x60, 0x00, 0x0C, 0x1F, 0x70, 0x20,
    0x00, 0x0C, 0x1B, 0x60, 0x20, 0x00, 0x17, 0x22, 0x20, 0x00, 0x5E, 0x06, 0x00, 0x00, 0x00, 0x50,
    0x20, 0x00, 0x09, 0x58, 0x02, 0x1E, 0x48, 0x60, 0x00, 0x09, 0x40, 0x01, 0x1F, 0x44, 0xC0, 0x00,
    0x0C, 0x1F, 0x30, 0x20, 0x00, 0x0C, 0x1F, 0x24, 0x60, 0x00, 0x0C, 0x1B, 0x18, 0x20, 0x00, 0x1B,
    0x23, 0x20, 0x00, 0x1B, 0x04, 0x20, 0x00, 0x22, 0xF6, 0x03, 0xF8, 0x02, 0x13, 0xF8, 0x08, 0x00,
    0x13, 0xF4, 0x08, 0x00, 0x22, 0xF0, 0x03, 0x20, 0x00, 0x2E, 0xE9, 0x03, 0xA0, 0x03, 0x00, 0x20,
    0x00, 0x13, 0xD4, 0x20, 0x00, 0x13, 0xF5, 0x30, 0x00, 0x2A, 0xC8, 0x03, 0x20, 0x00, 0x13, 0xBC,
    0x20, 0x00, 0x2E, 0x05, 0x00, 0x10, 0x03, 0x13, 0xEF, 0x34, 0x00, 0x1B, 0x9C, 0x34, 0x00, 0x13,
    0x90, 0x34, 0x00, 0x10, 0x01, 0xE8, 0x01, 0x12, 0x03, 0x84, 0x00, 0x00, 0x0C, 0x00, 0x2A, 0x80,
    0x03, 0xC4, 0x00, 0x13, 0x74, 0x28, 0x00, 0x13, 0x02, 0x0C, 0x00, 0x04, 0x50, 0x00, 0x1B, 0x70,
    0x50, 0x00, 0x17, 0x64, 0x50, 0x00, 0x53, 0x5C, 0x03, 0x00, 0x00, 0xF1, 0x28, 0x00, 0x22, 0x54,
    0x03, 0x48, 0x00, 0x13, 0x50, 0x08, 0x00, 0x14, 0x54, 0x28, 0x00, 0x74, 0x60, 0x0B, 0x60, 0x0D,
    0xC0, 0x00, 0xE0, 0x50, 0x00, 0x1B, 0x48, 0x50, 0x00, 0x17, 0x3C, 0x50, 0x00, 0x17, 0x34, 0x50,
    0x00, 0x13, 0x2C, 0x48, 0x00, 0x13, 0x28, 0x08, 0x00, 0x13, 0x2C, 0x28, 0x00, 0x39, 0x00, 0x60,
    0x0A, 0x50, 0x00, 0x1B, 0x20, 0x50, 0x00, 0x17, 0x14, 0x50, 0x00, 0x5F, 0x0C, 0x03, 0x00, 0x00,
    0xEB, 0x6C, 0x01, 0x04, 0x23, 0xF4, 0x02, 0x50, 0x00, 0x07, 0x3C, 0x01, 0x2A, 0xE4, 0x02, 0x24,
    0x00, 0x26, 0xD8, 0x02, 0x4C, 0x00, 0x20, 0xD0, 0x02, 0x3C, 0x01, 0x12, 0x01, 0x98, 0x01, 0x1A,
    0x02, 0x3C, 0x01, 0x26, 0xBC, 0x02, 0x3C, 0x01, 0x26, 0xBC, 0x02, 0x50, 0x00, 0x1B, 0xB8, 0x50,
    0x00, 0x17, 0xAC, 0x50, 0x00, 0x26, 0xA4, 0x02, 0xEC, 0x00, 0x22, 0x9C, 0x02, 0x48, 0x00, 0x13,
    0x98, 0x08, 0x00, 0x2F, 0x9C, 0x02, 0x3C, 0x01, 0x03, 0x1B, 0x90, 0x50, 0x00, 0x17, 0x84, 0x50,
    0x00, 0x17, 0x7C, 0x50, 0x00, 0x13, 0x74, 0x48, 0x00, 0x23, 0x70, 0x02, 0xDC, 0x01, 0x1F, 0x02,
    0x3C, 0x01, 0x03, 0x1B, 0x68, 0x50, 0x00, 0x17, 0x5C, 0x50, 0x00, 0x2F, 0x54, 0x02, 0x3C, 0x01,
    0x07, 0x17, 0x3C, 0x3C, 0x01, 0x2A, 0x34, 0x02, 0x04, 0x00, 0x1F, 0x38, 0x04, 0x00, 0x08, 0x1B,
    0x3C, 0x04, 0x00, 0x1B, 0x40, 0x04, 0x00, 0x1B, 0x44, 0x04, 0x00, 0x13, 0x48, 0x9C, 0x05, 0x08,
    0x04, 0x00, 0x00, 0x98, 0x00, 0x1B, 0x5C, 0x04, 0x00, 0x1B, 0x6C, 0x04, 0x00, 0x1B, 0x74, 0x04,
    0x00, 0x22, 0x78, 0x02, 0x20, 0x01, 0x1B, 0x80, 0x04, 0x00, 0x13, 0x84, 0xF4, 0x05, 0x22, 0x8C,
    0x02, 0x5C, 0x01, 0x0F, 0x04, 0x00, 0x05, 0x22, 0x94, 0x02, 0x94, 0x01, 0x08, 0x04, 0x00, 0x22,
    0xA0, 0x02, 0xD0, 0x01, 0x0E, 0x04, 0x00, 0x02, 0x18, 0x01, 0x13, 0xA8, 0x4C, 0x06, 0x22, 0xB0,
    0x02, 0x34, 0x01, 0x13, 0xB4, 0x18, 0x00, 0x00, 0x14, 0x02, 0x22, 0xC0, 0x02, 0x2C, 0x02, 0x22,
    0xC0, 0x02, 0x4C, 0x02, 0x13, 0xD0, 0x70, 0x06, 0x13, 0xE0, 0xB0, 0x01, 0x00, 0x88, 0x02, 0x13,
    0xEC, 0x38, 0x00, 0x2A, 0xEC, 0x02, 0x04, 0x00, 0x13, 0xF4, 0x98, 0x06, 0x13, 0x05, 0x7D, 0x02,
    0x22, 0x08, 0x03, 0x64, 0x05, 0x2A, 0x08, 0x03, 0x04, 0x00, 0x10, 0x10, 0xA0, 0x06, 0x12, 0x03,
    0x60, 0x05, 0x62, 0x1C, 0x03, 0x00, 0x00, 0x24, 0x03, 0x4C, 0x03, 0x13, 0x00, 0x4C, 0x03, 0x00,
    0x6C, 0x03, 0x13, 0x02, 0x74, 0x03, 0x13, 0x3C, 0xE4, 0x06, 0x26, 0x4C, 0x03, 0xC8, 0x03, 0x53,
    0x58, 0x03, 0x00, 0x00, 0x60, 0x28, 0x02, 0x2A, 0x60, 0x03, 0x04, 0x00, 0x22, 0x68, 0x03, 0x18,
    0x04, 0x13, 0x05, 0x2C, 0x04, 0x13, 0x7C, 0x84, 0x00, 0x2A, 0x7C, 0x03, 0x04, 0x00, 0x13, 0x84,
    0x34, 0x07, 0x13, 0x06, 0x88, 0x04, 0x23, 0x98, 0x03, 0xA0, 0x04, 0x16, 0xE0, 0x04, 0x00, 0x88,
    0x0C, 0x60, 0x02, 0x00, 0x0A, 0xC0, 0x00, 0xE0, 0x14, 0x00, 0x0A, 0x20, 0x00, 0x1D, 0x03, 0x20,
    0x00, 0x4C, 0x07, 0x60, 0x15, 0xC0, 0x28, 0x00, 0x0F, 0x14, 0x00, 0x09, 0x9F, 0x03, 0x60, 0x05,
    0x00, 0x03, 0xC0, 0x04, 0x00, 0x4F, 0x48, 0x00, 0x04, 0x1F, 0x02, 0x20, 0x00, 0x04, 0x90, 0x06,
    0x00, 0x04, 0x60, 0x08, 0x00, 0x03, 0xC0, 0x07, 0x1A, 0x00, 0x4B, 0xC0, 0x09, 0x00, 0x00, 0x20,
    0x00, 0x7D, 0x0A, 0x00, 0x06, 0x60, 0x00, 0xC0, 0x0B, 0x18, 0x00, 0x04, 0xD4, 0x00, 0x41, 0x08,
    0x60, 0x00, 0xF0, 0xA8, 0x05, 0x04, 0x08, 0x00, 0x09, 0x24, 0x00, 0x28, 0x15, 0xC0, 0xE0, 0x00,
    0x04, 0x2C, 0x00, 0x1E, 0x01, 0x2C, 0x00, 0x0E, 0xD4, 0x00, 0x01, 0x08, 0x00, 0x5D, 0x0C, 0x00,
    0x0D, 0x00, 0x16, 0xF4, 0x00, 0x80, 0x05, 0x60, 0x0E, 0x00, 0x0B, 0xC0, 0x00, 0xE0, 0x08, 0x00,
    0x5E, 0x0A, 0xC0, 0x0F, 0x00, 0x10, 0x24, 0x00, 0x09, 0x04, 0x00, 0x21, 0x09, 0x60, 0x0F, 0x09,
    0x23, 0x00, 0x10, 0x70, 0x02, 0x10, 0x01, 0x4C, 0x02, 0x07, 0x0C, 0x00, 0x17, 0x00, 0x0C, 0x00,
    0x23, 0xF8, 0x01, 0x3C, 0x05, 0x12, 0x01, 0x0C, 0x00, 0x08, 0x14, 0x04, 0x01, 0xAC, 0x02, 0x16,
    0x01, 0x10, 0x00, 0x17, 0xE4, 0x0C, 0x00, 0x13, 0xDC, 0x74, 0x09, 0x17, 0x02, 0x0C, 0x00, 0x04,
    0x18, 0x00, 0x01, 0x68, 0x05, 0x13, 0x01, 0x0C, 0x00, 0x53, 0x60, 0x00, 0xE0, 0x0B, 0x60, 0x4C,
    0x01, 0x0B, 0x5C, 0x00, 0x17, 0xC4, 0x70, 0x00, 0x0E, 0x94, 0x04, 0x02, 0xDC, 0x09, 0x21, 0xAC,
    0x01, 0x6C, 0x01, 0x2F, 0xE0, 0x0A, 0x44, 0x00, 0x04, 0x1F, 0x90, 0x44, 0x00, 0x0C, 0x26, 0x74,
    0x01, 0xC4, 0x0B, 0x26, 0x74, 0x01, 0x38, 0x00, 0x23, 0x6C, 0x01, 0x30, 0x05, 0x12, 0x01, 0x0C,
    0x00, 0x0C, 0x58, 0x00, 0x17, 0x60, 0xEC, 0x00, 0x17, 0x58, 0x0C, 0x00, 0x13, 0x50, 0x80, 0x0A,
    0x17, 0x02, 0x0C, 0x00, 0x04, 0x18, 0x00, 0x22, 0x01, 0x00, 0x50, 0x0C, 0x1F, 0x50, 0xF8, 0x00,
    0x0C, 0x1F, 0x38, 0xB4, 0x00, 0x0C, 0x00, 0xE8, 0x0A, 0x1F, 0x20, 0xF8, 0x00, 0x0C, 0x1F, 0x04,
    0x44, 0x00, 0x0C, 0x13, 0xE8, 0xFC, 0x0C, 0x04, 0x0C, 0x00, 0x01, 0xC0, 0x01, 0x0B, 0x04, 0x00,
    0x15, 0x01, 0xA0, 0x02, 0x20, 0x08, 0x60, 0xF0, 0x02, 0x10, 0xD4, 0xB0, 0x08, 0x00, 0x1F, 0x02,
    0x12, 0x20, 0xC0, 0x02, 0x10, 0x11, 0xBF, 0x04, 0x25, 0x20, 0x02, 0x0C, 0x00, 0x18, 0xBC, 0xF8,
    0x02, 0x03, 0x34, 0x00, 0x17, 0xAC, 0x48, 0x00, 0x00, 0xF0, 0x00, 0x17, 0xA0, 0x24, 0x00, 0x00,
    0xBC, 0x00, 0x5B, 0x94, 0x00, 0x00, 0x00, 0x94, 0x6C, 0x00, 0x50, 0x01, 0xC0, 0x00, 0xE0, 0x84,
    0xEC, 0x06, 0x0F, 0x6C, 0x00, 0x08, 0x1B, 0x6C, 0x6C, 0x00, 0x00, 0x34, 0x00, 0x1B, 0x5C, 0x6C,
    0x00, 0x1B, 0x50, 0x6C, 0x00, 0x11, 0x44, 0x1C, 0x0E, 0x11, 0x01, 0x04, 0x00, 0x11, 0x10, 0x4B,
    0x05, 0x13, 0x01, 0xB8, 0x0C, 0xFF, 0x02, 0x03, 0x00, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x05,
    0x00, 0x06, 0x00, 0x06, 0x00, 0x01, 0x00, 0x02, 0x1C, 0x00, 0x0A, 0x10, 0x60, 0x20, 0x02, 0x00,
    0xAC, 0x0D, 0x03, 0xA4, 0x00, 0x10, 0x90, 0xC0, 0x07, 0x00, 0x90, 0x02, 0x00, 0xF4, 0x05, 0x00,
    0xE4, 0x05, 0x00, 0xE0, 0x0B, 0x00, 0xE4, 0x02, 0x03, 0x48, 0x01, 0x50, 0xF0, 0x00, 0x00, 0x00,
    0xFC, 0x64, 0x03, 0x43, 0x01, 0x00, 0x00, 0x14, 0xBC, 0x01, 0x10, 0x2C, 0x04, 0x02, 0xA5, 0x01,
    0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x08, 0x00, 0x0F, 0xB0, 0x01, 0x05, 0x0F,
    0xA8, 0x0D, 0x11, 0x04, 0x28, 0x00, 0x04, 0x83, 0x0E, 0x1B, 0xD8, 0x20, 0x00, 0x2A, 0xE8, 0x03,
    0x20, 0x00, 0x1B, 0xC0, 0x30, 0x00, 0x1B, 0xB8, 0x30, 0x00, 0x1B, 0x64, 0x20, 0x00, 0x1B, 0xA0,
    0x10, 0x00, 0x1B, 0x94, 0x10, 0x00, 0x1B, 0x8C, 0x10, 0x00, 0x1B, 0x80, 0x10, 0x00, 0x1B, 0x74,
    0x60, 0x00, 0x1B, 0x02, 0x20, 0x00, 0x1B, 0x58, 0x10, 0x00, 0x1F, 0x4C, 0x58, 0x0E, 0x04, 0xC4,
    0x25, 0x30, 0x32, 0x2E, 0x33, 0x66, 0x00, 0x00, 0x56, 0x49, 0x4E, 0x3A, 0x10, 0x00, 0x10, 0x32,
    0x10, 0x00, 0x00, 0xC4, 0x08, 0x30, 0x65, 0x6D, 0x70, 0x15, 0x00, 0xF0, 0x05, 0x27, 0x43, 0x00,
    0x00, 0x4F, 0x4E, 0x00, 0x00, 0x4F, 0x46, 0x46, 0x00, 0x43, 0x43, 0x00, 0x00, 0x43, 0x56, 0x00,
    0x00
};

native_var_t native_vars[] = {
    { NATIVE_VAR_TYPE_NONE, 0, 0 },
};


ActionExecFunc actions[] = {
    action_update_power_module_status,
};


#if defined(EEZ_FOR_LVGL)

void ui_init() {
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
}

void ui_tick() {
    eez_flow_tick();
    tick_screen(g_currentScreen);
}

#else

static int16_t currentScreen = -1;

static lv_obj_t *getLvglObjectFromIndex(int32_t index) {
    if (index == -1) {
        return 0;
    }
    return ((lv_obj_t **)&objects)[index];
}

static const void *getLvglImageByName(const char *name) {
    for (size_t imageIndex = 0; imageIndex < sizeof(images) / sizeof(ext_img_desc_t); imageIndex++) {
        if (strcmp(images[imageIndex].name, name) == 0) {
            return images[imageIndex].img_dsc;
        }
    }
    return 0;
}

void loadScreen(enum ScreensEnum screenId) {
    currentScreen = screenId - 1;
    lv_obj_t *screen = getLvglObjectFromIndex(currentScreen);
    lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false);
}

void ui_init() {
    create_screens();
    loadScreen(SCREEN_ID_MAIN);
}

void ui_tick() {
    tick_screen(currentScreen);
}

#endif