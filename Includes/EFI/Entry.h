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

#include "ConfigurationTable.h"
#include "Status.h"
#include "Types.h"

#include "Services/Boot.h"
#include "Services/Runtime.h"

#include "Protocols/TextInput.h"
#include "Protocols/TextOutput.h"

typedef struct EFI_System_Table
{
    EFI_Table_Header            header;
    uint16_t*                   firmware_vendor;
    uint32_t                    firmware_revision;
    EFI_Handle                  console_in_handle;
    EFI_Protocol_Text_Input*    console_in;
    EFI_Handle                  console_out_handle;
    EFI_Protocol_Text_Output*   console_out;
    EFI_Handle                  error_out_handle;
    EFI_Protocol_Text_Output*   error_out;
    EFI_Service_Runtime*        service_runtime;
    EFI_Service_Boot*           services_boot;
    uint64_t                    count_configuration_entries;
    EFI_Configuration_Table*    configuration;
} EFI_System_Table;

EFI_Status kOS_EFI_main(EFI_Handle handle, EFI_System_Table* system_table);
