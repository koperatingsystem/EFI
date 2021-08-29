// Copyright (c) 2021 The kOS authors.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software.
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <stdbool.h>
#include <stdint.h>

#define EFI_TIMEZONE_UNSPECIFIED 0x07ff

enum EFI_Time_DST_Flags
{
    EFI_Time_DST_Flags_Adjust_for_DST   = 0x01,
    EFI_Time_DST_Flags_Is_in_DST        = 0x02
};

typedef struct EFI_Time
{
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     minute;
    uint8_t     second;
    uint8_t     padding_1;
    uint32_t    nanosecond;
    int16_t     timezone;
    uint8_t     flags_dst;
    uint8_t     padding_2;
} EFI_Time;

typedef struct EFI_Time_Capabilities
{
    uint32_t    resolution;
    uint32_t    accuracy;
    bool        sets_to_zero;
} EFI_Time_Capabilities;
