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

#include <stdint.h>

#define EFI_MEMORY_DESCRIPTOR_VERSION 1

enum EFI_Memory_Attributes
{
    EFI_Memory_Attributes_Uncacheable               = 0x0000000000000001,
    EFI_Memory_Attributes_Write_Combine             = 0x0000000000000002,
    EFI_Memory_Attributes_Write_Through             = 0x0000000000000004,
    EFI_Memory_Attributes_Write_Back                = 0x0000000000000008,
    EFI_Memory_Attributes_Uncacheable_Exportable    = 0x0000000000000010,
    EFI_Memory_Attributes_Write_Protected           = 0x0000000000001000,
    EFI_Memory_Attributes_Read_Protected            = 0x0000000000002000,
    EFI_Memory_Attributes_Restricted_Execution      = 0x0000000000004000,
    EFI_Memory_Attributes_Persistent                = 0x0000000000008000,
    EFI_Memory_Attributes_More_Reliable             = 0x0000000000010000,
    EFI_Memory_Attributes_Read_Only                 = 0x0000000000020000,
    EFI_Memory_Attributes_Special_Purpose           = 0x0000000000040000,
    EFI_Memory_Attributes_CPU_Crypto                = 0x0000000000080000,
    EFI_Memory_Attributes_Runtime                   = 0x8000000000000000
};

typedef struct EFI_Memory_Descriptor
{
    uint32_t type;
    uint64_t start_physical;
    uint64_t start_virtual;
    uint64_t count_pages;
    uint64_t attributes;
} EFI_Memory_Descriptor;
