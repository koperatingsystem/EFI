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

#include "../Status.h"
#include "../Types.h"

#include <stdbool.h>
#include <stdint.h>

const static EFI_GUID EFI_Protocol_Text_Input_GUID = { 0x387477c1, 0x69c7, 0x11d2, { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b} };

typedef struct EFI_Protocol_Text_Input_Key
{
    uint16_t scan_code;
    uint16_t unicode_character;
} EFI_Protocol_Text_Input_Key;

typedef struct EFI_ProtocolText_Input EFI_ProtocolText_Input;

typedef EFI_Status (*EFI_Protocol_Text_Input_Reset_Function)(struct EFI_ProtocolText_Input* self, bool extended_verification);
typedef EFI_Status (*EFI_Protocol_Text_Input_Read_Key_Function)(struct EFI_ProtocolText_Input* self, EFI_Protocol_Text_Input_Key* key);

typedef struct EFI_Protocol_Text_Input
{
    EFI_Protocol_Text_Input_Reset_Function      reset;
    EFI_Protocol_Text_Input_Read_Key_Function   read_key;
    EFI_Event                                   wait_for_key;
} EFI_Protocol_Text_Input;
