/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    driver and application

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_fdddriver,
    0xf4991016,0xfc10,0x43d9,0x8e,0x4c,0x3d,0x31,0x79,0xfa,0x88,0x46);
// {f4991016-fc10-43d9-8e4c-3d3179fa8846}
