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

#define EFI_STATUS_MASK 0x8000000000000000

typedef uint64_t EFI_Status;

enum
{
    EFI_Status_Success,
    EFI_Status_Load_Error             = (EFI_STATUS_MASK | 0x01),
    EFI_Status_Invalid_Parameter      = (EFI_STATUS_MASK | 0x02),
    EFI_Status_Unsupported            = (EFI_STATUS_MASK | 0x03),
    EFI_Status_Invalid_Buffer_Size    = (EFI_STATUS_MASK | 0x04),
    EFI_Status_Buffer_Too_Small       = (EFI_STATUS_MASK | 0x05),
    EFI_Status_Not_Ready              = (EFI_STATUS_MASK | 0x06),
    EFI_Status_Device_Fault           = (EFI_STATUS_MASK | 0x07),
    EFI_Status_Write_Protected        = (EFI_STATUS_MASK | 0x08),
    EFI_Status_Out_Of_Resources       = (EFI_STATUS_MASK | 0x09),
    EFI_Status_Volume_Corrupted       = (EFI_STATUS_MASK | 0x0a),
    EFI_Status_Volume_Full            = (EFI_STATUS_MASK | 0x0b),
    EFI_Status_No_Media               = (EFI_STATUS_MASK | 0x0c),
    EFI_Status_Media_Changed          = (EFI_STATUS_MASK | 0x0d),
    EFI_Status_Not_Found              = (EFI_STATUS_MASK | 0x0e),
    EFI_Status_Access_Denied          = (EFI_STATUS_MASK | 0x0f),
    EFI_Status_No_Response            = (EFI_STATUS_MASK | 0x10),
    EFI_Status_No_Mapping             = (EFI_STATUS_MASK | 0x11),
    EFI_Status_Timeout                = (EFI_STATUS_MASK | 0x12),
    EFI_Status_Not_Started            = (EFI_STATUS_MASK | 0x13),
    EFI_Status_Already_Started        = (EFI_STATUS_MASK | 0x14),
    EFI_Status_Cancelled              = (EFI_STATUS_MASK | 0x15),
    EFI_Status_ICMP_Error             = (EFI_STATUS_MASK | 0x16),
    EFI_Status_TFTP_Error             = (EFI_STATUS_MASK | 0x17),
    EFI_Status_Protocol_Error         = (EFI_STATUS_MASK | 0x18),
    EFI_Status_Incompatible_Version   = (EFI_STATUS_MASK | 0x19),
    EFI_Status_Security_Violation     = (EFI_STATUS_MASK | 0x1a),
    EFI_Status_CRC_Error              = (EFI_STATUS_MASK | 0x1b),
    EFI_Status_End_Of_Media           = (EFI_STATUS_MASK | 0x1c),
    EFI_Status_End_Of_File            = (EFI_STATUS_MASK | 0x1f),
    EFI_Status_Invalid_Language       = (EFI_STATUS_MASK | 0x20),
    EFI_Status_Compromised_Data       = (EFI_STATUS_MASK | 0x21),
    EFI_Status_IP_Address_Conflict    = (EFI_STATUS_MASK | 0x22),
    EFI_Status_HTTP_Error             = (EFI_STATUS_MASK | 0x23),
};
