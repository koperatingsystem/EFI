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

#include "ABI.h"

#include "../Memory.h"
#include "../Status.h"
#include "../Time.h"
#include "../Types.h"

#include <stdbool.h>
#include <stdint.h>

#define EFI_POINTER_OPTIONAL 0x00000001

enum EFI_Capsule_Header_Flags
{
    EFI_Capsule_Header_Flags_Persist                = 1 << 16,
    EFI_Capsule_Header_Flags_Populate_System_Table  = 1 << 17,
    EFI_Capsule_Header_Flags_Initiate_Reset         = 1 << 18
};

enum EFI_Reset_Type
{
    EFI_Reset_Type_Cold,
    EFI_Reset_Type_Warm,
    EFI_Reset_Type_Shutdown,
    EFI_Reset_Type_Platform_Specific
};

typedef struct EFI_Capsule_Block_Descriptor
{
    uint64_t size;
    union
    {
        uint64_t data_block;
        uint64_t pointer_continuation;
    } content;
} EFI_Capsule_Block_Descriptor;

typedef struct EFI_Capsule_Header
{
    EFI_GUID    guid;
    uint32_t    size_header;
    uint32_t    flags;
    uint32_t    size_capsule;
} EFI_Capsule_Header;

typedef EFI_Status (EFIABI * EFI_Get_Time_Function)(EFI_Time* time, EFI_Time_Capabilities* capabilities);
typedef EFI_Status (EFIABI * EFI_Set_Time_Function)(EFI_Time* time);
typedef EFI_Status (EFIABI * EFI_Get_Wake_Up_Time_Function)(bool *Enabled, bool *Pending, EFI_Time *Time);
typedef EFI_Status (EFIABI * EFI_Set_Wakeup_Time_Function)(bool Enable, EFI_Time *Time);
typedef EFI_Status (EFIABI * EFI_Set_Virtual_Address_Map_Function)(uint64_t size_memory_map, uint64_t size_descriptr, uint32_t version_descriptor, EFI_Memory_Descriptor* virtual_map);
typedef EFI_Status (EFIABI * EFI_Convert_Pointer_Function)(uint64_t DebugDisposition, void** Address);
typedef EFI_Status (EFIABI * EFI_Get_Variable_Function)(uint16_t *VariableName, EFI_GUID *VendorGuid, uint32_t *Attributes, uint64_t *DataSize, void* Data);
typedef EFI_Status (EFIABI * EFI_Get_Next_Variable_Name_Function)(uint64_t *VariableNameSize, uint16_t *VariableName, EFI_GUID *VendorGuid);
typedef EFI_Status (EFIABI * EFI_Set_Variable_Function)(uint16_t *VariableName, EFI_GUID *VendorGuid, uint32_t Attributes, uint64_t DataSize, void* Data);
typedef EFI_Status (EFIABI * EFI_Get_Next_High_Monotonic_Count_Function)(uint32_t *HighCount);
typedef EFI_Status (EFIABI * EFI_Reset_System_Function)(uint8_t type, EFI_Status status, uint64_t size, void* data);
typedef EFI_Status (EFIABI * EFI_Update_Capsule)(EFI_Capsule_Header** header_capsules, uint64_t count_capsules, uint64_t list_scatter_gather);
typedef EFI_Status (EFIABI * EFI_Query_Capsule_Capabilities_Function)(EFI_Capsule_Header** header_capsules, uint64_t count_capsules, uint64_t* capsule_size_max, uint8_t* reset_type);
typedef EFI_Status (EFIABI * EFI_Query_Variable_Info_Function)(uint32_t attributes, uint64_t* size_variable_storage_max, uint64_t* size_variable_storage_remaining, uint64_t* size_variable_max);

typedef struct EFI_Service_Runtime
{
    EFI_Table_Header                            header;
    EFI_Get_Time_Function                       time_get;
    EFI_Set_Time_Function                       time_set;
    EFI_Get_Wake_Up_Time_Function               time_get_wakeup;
    EFI_Set_Wakeup_Time_Function                time_set_wakeup;
    EFI_Set_Virtual_Address_Map_Function        vam_set;
    EFI_Convert_Pointer_Function                pointer_convert;
    EFI_Get_Variable_Function                   variables_get;
    EFI_Get_Next_Variable_Name_Function         variables_get_next_name;
    EFI_Set_Variable_Function                   variables_set;
    EFI_Get_Next_High_Monotonic_Count_Function  nhmc_get;
    EFI_Reset_System_Function                   system_reset;
    EFI_Update_Capsule                          capsule_update;
    EFI_Query_Capsule_Capabilities_Function     capsule_query_capabilities;
    EFI_Query_Variable_Info_Function            variables_query_info;
} EFI_Service_Runtime;
