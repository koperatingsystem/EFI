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
#include "../Status.h"

#include <stdbool.h>
#include <stdint.h>

const static EFI_GUID EFI_Protocol_Text_Output_GUID = { 0x387477c2, 0x69c7, 0x11d2, { 0x82, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } };

typedef struct EFI_Protocol_Text_Output_Mode
{
    int32_t mode_max;
    int32_t mode_current;
    int32_t attribute;
    int32_t cursor_column;
    int32_t cursor_row;
    bool    cursor_visible;
} EFI_Protocol_Text_Output_Mode;

typedef struct EFI_Protocol_Text_Output EFI_Protocol_Text_Output;

typedef EFI_Status (*EFI_Protocol_Text_Output_Reset_Function)(EFI_Protocol_Text_Output* self, bool extended_verification);
typedef EFI_Status (*EFI_Protocol_Text_Output_String_Function)(EFI_Protocol_Text_Output* self, uint16_t* string);
typedef EFI_Status (*EFI_Protocol_Text_Output_Test_Function)(EFI_Protocol_Text_Output* self, uint16_t* string);
typedef EFI_Status (*EFI_Protocol_Text_Output_Query_Mode_Function)(EFI_Protocol_Text_Output* self, uint64_t mode_number, uint64_t* columns, uint64_t* rows);
typedef EFI_Status (*EFI_Protocol_Text_Output_Set_Mode_Function)(EFI_Protocol_Text_Output* self, uint64_t mode_number);
typedef EFI_Status (*EFI_Protocol_Text_Output_Set_Attribute_Function)(EFI_Protocol_Text_Output* self, uint64_t attribute);
typedef EFI_Status (*EFI_Protocol_Text_Output_Screen_Clear_Function)(EFI_Protocol_Text_Output* self);
typedef EFI_Status (*EFI_Protocol_Text_Output_Cursor_Set_Position_Function)(EFI_Protocol_Text_Output* self, uint64_t column, uint64_t row);
typedef EFI_Status (*EFI_Protocol_Text_Output_Cursor_Enable_Function)(EFI_Protocol_Text_Output* self, bool visible);

typedef struct EFI_Protocol_Text_Output
{
    EFI_Protocol_Text_Output_Reset_Function                 reset;
    EFI_Protocol_Text_Output_String_Function                string_output;
    EFI_Protocol_Text_Output_Test_Function                  string_test;
    EFI_Protocol_Text_Output_Query_Mode_Function            mode_query;
    EFI_Protocol_Text_Output_Set_Mode_Function              mode_set;
    EFI_Protocol_Text_Output_Set_Attribute_Function         attribute_set;
    EFI_Protocol_Text_Output_Screen_Clear_Function          screen_clear;
    EFI_Protocol_Text_Output_Cursor_Set_Position_Function   cursor_set_position;
    EFI_Protocol_Text_Output_Cursor_Enable_Function         cursor_enable;
    EFI_Protocol_Text_Output_Mode*                          mode;
} EFI_Protocol_Text_Output;
