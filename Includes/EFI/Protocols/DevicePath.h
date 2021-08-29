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

#include "../Types.h"

#include <stdint.h>

const static EFI_GUID EFI_Protocol_Device_Path_GUID = { 0x09576e91, 0x6d3f, 0x11d2, { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } };

#define EFI_HARDWARE_DEVICE_PATH                0x01
#define EFI_ACPI_DEVICE_PATH                    0x02
#define EFI_MESSAGING_DEVICE_PATH               0x03
#define EFI_MEDIA_DEVICE_PATH                   0x04
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_PATH 0x05
#define EFI_END_OF_HARDWARE_DEVICE_PATH         0x7f

typedef struct EFI_Protocol_Device_Path
{
    uint8_t type;
    uint8_t sub_type;
    uint8_t length[2];
} EFI_Protocol_Device_Path;
