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
#include "../Types.h"

#include "../Protocols/DevicePath.h"

#include <stdbool.h>
#include <stdint.h>

enum EFI_Boot_Event
{
    EFI_Boot_Event_Timer                    = 0x80000000,
    EFI_Boot_Event_Runtime                  = 0x40000000,
    EFI_Boot_Event_Notify_Wait              = 0x00000100,
    EFI_Boot_Event_Notify_Signal            = 0x00000200,
    EFI_Boot_Event_Exit_Boot_Services       = 0x00000201,
    EFI_Boot_Event_Virtual_Address_Change   = 0x00000202
};

enum EFI_Priority_Level
{
    EFI_Priority_Level_Application  = 4,
    EFI_Priority_Level_Callback     = 8,
    EFI_Priority_Level_Notify       = 16,
    EFI_Priority_Level_High_Level   = 31
};

enum EFI_Open_Protocol_Type
{
    EFI_Open_Protocol_Type_By_Handle            = 1 << 0,
    EFI_Open_Protocol_Type_Get_Protocol         = 1 << 1,
    EFI_Open_Protocol_Type_Test_Protocol        = 1 << 2,
    EFI_Open_Protocol_Type_By_Child_Controller  = 1 << 3,
    EFI_Open_Protocol_Type_Driver               = 1 << 4,
    EFI_Open_Protocol_Type_Exclusive            = 1 << 5
};

enum EFI_Memory_Usage_Type
{
    EFI_Memory_Usage_Type_Reserved,
    EFI_Memory_Usage_Type_Loader_Code,
    EFI_Memory_Usage_Type_Loader_Data,
    EFI_Memory_Usage_Type_Boot_Services_Code,
    EFI_Memory_Usage_Type_Boot_Services_Data,
    EFI_Memory_Usage_Type_Runtime_Services_Code,
    EFI_Memory_Usage_Type_Runtime_Services_Data,
    EFI_Memory_Usage_Type_Conventional_Memory,
    EFI_Memory_Usage_Type_Unusable_Memory,
    EFI_Memory_Usage_Type_ACPI_Reclaim_Memory,
    EFI_Memory_Usage_Type_ACPI_Memory_Firmware,
    EFI_Memory_Usage_Type_Memory_Mapped_IO,
    EFI_Memory_Usage_Type_Memory_Mapped_IO_Port_Space,
    EFI_Memory_Usage_Type_Processor_Code,
    EFI_Memory_Usage_Type_Persistent_Memory,
    EFI_Memory_Usage_Type_Maximum
};

typedef void (*EFI_Notify_Event_Callback)(EFI_Event event, void* context);

typedef enum EFI_Timer_Type
{
    EFI_Timer_Type_Cancel,
    EFI_Timer_Type_Periodic,
    EFI_Timer_Type_Relative
} EFI_Timer_Type;

typedef enum EFI_Allocation_Type
{
    EFI_Allocation_Type_Allocate_Any_Page,
    EFI_Allocation_Type_Max_Address,
    EFI_Allocation_Type_Allocate_Address,
    EFI_Allocation_Type_Maximum
} EFI_Allocation_Type;

typedef enum EFI_Interface_Type
{
    EFI_Interface_Type_Native
} EFI_Interface_Type;

typedef enum EFI_Locate_Search_Type
{
    EFI_Locate_Search_Type_All_Handles,
    EFI_Locate_Search_Type_By_Register_Notify,
    EFI_Locate_Search_Type_By_Protocol
} EFI_Locate_Search_Type;

typedef struct EFI_Open_Protocol_Entry
{
    EFI_Handle  handle_agent;
    EFI_Handle  handle_controller;
    uint32_t    attributes;
    uint32_t    open_count;
} EFI_Open_Protocol_Entry;

typedef EFI_Status (*EFI_Raise_TPL)(uint64_t priority);
typedef EFI_Status (*EFI_Restore_TPL)(uint64_t priority);
typedef EFI_Status (*EFI_Allocate_Pages)(EFI_Allocation_Type type_allocation, uint64_t type_memory, uint64_t pages, uint64_t* memory);
typedef EFI_Status (*EFI_Free_Pages)(uint64_t memory, uint64_t pages);
typedef EFI_Status (*EFI_Get_Memory_Map)(uint64_t* size_map, EFI_Memory_Descriptor* map, uint64_t* key, uint64_t* size_descriptor, uint32_t* version_descriptor);
typedef EFI_Status (*EFI_Allocate_Pool)(uint64_t type_pool, uint64_t size, void** buffer);
typedef EFI_Status (*EFI_Free_Pool)(void* buffer);
typedef EFI_Status (*EFI_Create_Event)(uint32_t event_type, uint64_t notify_priority, EFI_Notify_Event_Callback notify_function, void* notify_contest, EFI_GUID* event_group, EFI_Event* event);
typedef EFI_Status (*EFI_Set_Timer)(EFI_Event event, EFI_Timer_Type type_delay, uint64_t time_trigger);
typedef EFI_Status (*EFI_Wait_For_Event)(uint64_t count_events, EFI_Event* event, uint64_t* index);
typedef EFI_Status (*EFI_Signal_Event)(EFI_Event event);
typedef EFI_Status (*EFI_Close_Event)(EFI_Event event);
typedef EFI_Status (*EFI_Check_Event)(EFI_Event event);
typedef EFI_Status (*EFI_Protocol_Interface_Install)(EFI_Handle* handle, EFI_GUID* protocol, EFI_Interface_Type type, void* interface);
typedef EFI_Status (*EFI_Protocol_Interface_Reinstall)(EFI_Handle handle, EFI_GUID* protocol, void* old, void* new);
typedef EFI_Status (*EFI_Protocol_Interface_Uninstall)(EFI_Handle handle, EFI_GUID* protocol, void* interface);
typedef EFI_Status (*EFI_Protocol_Handle)(EFI_Handle handle, EFI_GUID* protocol, void** interface);
typedef EFI_Status (*EFI_Register_Protocol_Notify)(EFI_GUID* protocol, EFI_Event event, void** registration);
typedef EFI_Status (*EFI_Locate_Handle)(EFI_Locate_Search_Type type, EFI_GUID* protocol, void* key, uint64_t* size, EFI_Handle* buffer);
typedef EFI_Status (*EFI_Locate_Device_Path)(EFI_GUID* protocol, EFI_Protocol_Device_Path** path, EFI_Handle* dvice);
typedef EFI_Status (*EFI_Install_Configuration_Table)(EFI_GUID* id, void* table);
typedef EFI_Status (*EFI_Image_Load)(bool policy, EFI_Handle parent_handle, EFI_Protocol_Device_Path* path, void* buffer, uint64_t size, EFI_Handle* handle);
typedef EFI_Status (*EFI_Image_Start)(EFI_Handle handle, uint64_t* size, uint16_t** data);
typedef EFI_Status (*EFI_Exit)(EFI_Handle handle, EFI_Status status, uint64_t size, uint16_t* data);
typedef EFI_Status (*EFI_Image_Unload)(EFI_Handle handle);
typedef EFI_Status (*EFI_Exit_Boot_Services)(EFI_Handle handle, uint64_t map_key);
typedef EFI_Status (*EFI_Get_Next_Monotonic_Count)(uint64_t* count);
typedef EFI_Status (*EFI_Stall)(uint64_t microseconds);
typedef EFI_Status (*EFI_Set_Watchdog_Timer)(uint64_t timeout, uint64_t code, uint64_t size, uint16_t* data);
typedef EFI_Status (*EFI_Connect_Controller)(EFI_Handle handle, EFI_Handle* driver_image_handle, EFI_Protocol_Device_Path* path, bool recursive);
typedef EFI_Status (*EFI_Disconnect_Controller)(EFI_Handle handle, EFI_Handle driver_image_handle, EFI_Handle child_handle);
typedef EFI_Status (*EFI_Open_Protocol)(EFI_Handle handle, EFI_GUID* protocol, void** interface, EFI_Handle agent_handle, EFI_Handle controller_handle, uint32_t attributes);
typedef EFI_Status (*EFI_Close_Protocol)(EFI_Handle handle, EFI_GUID* protocol, EFI_Handle agent_handle, EFI_Handle controller_handle);
typedef EFI_Status (*EFI_Open_Protocol_Information)(EFI_Handle handle, EFI_GUID* protocol, EFI_Open_Protocol_Entry** buffer, uint64_t* count);
typedef EFI_Status (*EFI_Protocols_Per_Handle)(EFI_Handle handle, EFI_GUID*** buffer, uint64_t* count);
typedef EFI_Status (*EFI_Locate_Handle_Buffer)(EFI_Locate_Search_Type type, EFI_GUID* protocol, void* key, uint64_t* count, EFI_Handle** buffer);
typedef EFI_Status (*EFI_Locate_Protocol)(EFI_GUID* protocol, void* registration, void** interface);
typedef EFI_Status (*EFI_Install_Multiple_Protocol_Interfaces)(EFI_Handle* handle, ...);
typedef EFI_Status (*EFI_Uninstall_Multiple_Protocol_Interfaces)(EFI_Handle* handle, ...);
typedef EFI_Status (*EFI_Calculate_CRC32)(void* data, uint64_t size, uint32_t* crc32);
typedef EFI_Status (*EFI_Copy_Memory)(void* destination, void* source, uint64_t length);
typedef EFI_Status (*EFI_Set_Memory)(void* buffer, uint64_t size, uint8_t value);
typedef EFI_Status (*EFI_Create_Event_Ex)(uint32_t type, uint64_t tpl, EFI_Notify_Event_Callback function, void* context, EFI_GUID* event_group, EFI_Event* event);

typedef struct EFI_Service_Boot
{
    EFI_Table_Header                            header;
    EFI_Raise_TPL                               raise_tpl;
    EFI_Restore_TPL                             restore_tpl;
    EFI_Allocate_Pages                          allocate_pages;
    EFI_Free_Pages                              free_pages;
    EFI_Get_Memory_Map                          get_memory_map;
    EFI_Allocate_Pool                           allocate_pool;
    EFI_Free_Pool                               free_pool;
    EFI_Create_Event                            create_event;
    EFI_Set_Timer                               set_timer;
    EFI_Wait_For_Event                          wait_for_event;
    EFI_Signal_Event                            signal_event;
    EFI_Close_Event                             close_event;
    EFI_Check_Event                             check_event;
    EFI_Protocol_Interface_Install              install_protocol_interface;
    EFI_Protocol_Interface_Reinstall            reinstall_protocol_interface;
    EFI_Protocol_Interface_Uninstall            uninstall_protocol_interface;
    EFI_Protocol_Handle                         handle_protocol;
    void*                                       reserved;
    EFI_Register_Protocol_Notify                register_protocol_notify;
    EFI_Locate_Handle                           locate_handle;
    EFI_Locate_Device_Path                      locate_device_path;
    EFI_Install_Configuration_Table             install_configuration_table;
    EFI_Image_Load                              load_image;
    EFI_Image_Start                             start_image;
    EFI_Exit                                    exit;
    EFI_Image_Unload                            unload_image;
    EFI_Exit_Boot_Services                      exit_boot_services;
    EFI_Get_Next_Monotonic_Count                get_next_monotonic_count;
    EFI_Stall                                   stall;
    EFI_Set_Watchdog_Timer                      set_watchdog_timer;
    EFI_Connect_Controller                      connect_controller;
    EFI_Disconnect_Controller                   disconnect_controller;
    EFI_Open_Protocol                           open_protocol;
    EFI_Close_Protocol                          close_protocol;
    EFI_Open_Protocol_Information               open_protocol_information;
    EFI_Protocols_Per_Handle                    protocols_per_handle;
    EFI_Locate_Handle_Buffer                    locate_handle_buffer;
    EFI_Locate_Protocol                         locate_protocol;
    EFI_Install_Multiple_Protocol_Interfaces    install_multiple_protocol_interfaces;
    EFI_Uninstall_Multiple_Protocol_Interfaces  uninstall_multiple_protocol_interfaces;
    EFI_Calculate_CRC32                         calculate_crc32;
    EFI_Copy_Memory                             copy_memory;
    EFI_Set_Memory                              set_memory;
    EFI_Create_Event_Ex                         create_event_ex;
} EFI_Service_Boot;
