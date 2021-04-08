#pragma once

#include <cstrike/sdk.h>
#include <vmthook/vmthook.h>

extern std::unique_ptr<VMTHook> prediction_hook;

typedef bool (__fastcall *RunCommand_t)( IPrediction*, void*, CBaseEntity*, CUserCmd*, void* );

namespace Hooks
{
    // IPrediction::RunCommand
    void __fastcall RunCommand( IPrediction*, void*, CBaseEntity*, CUserCmd*, void* );
}
