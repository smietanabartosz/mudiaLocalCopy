// Copyright (c) 2017-2021, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#include <stdint-gcc.h>

const uint8_t einkBinarizationLUT_2bpp[256] = {
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x30, 0x30, 0x30, 0x33, 0x30, 0x30, 0x30, 0x33, 0x30,
    0x30, 0x30, 0x33, 0x3c, 0x3c, 0x3c, 0x3f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03,
    0x0c, 0x0c, 0x0c, 0x0f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c,
    0x0f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x30, 0x30,
    0x30, 0x33, 0x30, 0x30, 0x30, 0x33, 0x30, 0x30, 0x30, 0x33, 0x3c, 0x3c, 0x3c, 0x3f, 0x00, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03,
    0x00, 0x00, 0x00, 0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x03, 0x0c, 0x0c, 0x0c, 0x0f, 0x30, 0x30, 0x30, 0x33, 0x30, 0x30, 0x30, 0x33, 0x30, 0x30, 0x30, 0x33, 0x3c, 0x3c,
    0x3c, 0x3f, 0xc0, 0xc0, 0xc0, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0xcc, 0xcc, 0xcc, 0xcf, 0xc0,
    0xc0, 0xc0, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0xcc, 0xcc, 0xcc, 0xcf, 0xc0, 0xc0, 0xc0, 0xc3,
    0xc0, 0xc0, 0xc0, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0xcc, 0xcc, 0xcc, 0xcf, 0xf0, 0xf0, 0xf0, 0xf3, 0xf0, 0xf0, 0xf0,
    0xf3, 0xf0, 0xf0, 0xf0, 0xf3, 0xfc, 0xfc, 0xfc, 0xff,
};

const uint8_t einkBinarizationLUT_4bpp[256] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff,
};
