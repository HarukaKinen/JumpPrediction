#include "Hooks/Hooks.h"

IVEngineClient* engine = nullptr;
IClientEntityList* entitylist = nullptr;
IPrediction* prediction = nullptr;

void WINAPI basehook_init( LPVOID dll_instance )
{
    // Get interfaces from game libraries using partial version strings.
    engine = GetInterface<IVEngineClient>( "engine.dll", "VEngineClient0" );
    entitylist = GetInterface<IClientEntityList>( "client.dll", "VClientEntityList0" );
    prediction = GetInterface<IPrediction>( "client.dll", "VClientPrediction0" );

    // Hook 'RunCommand' from IPrediction.
    prediction_hook = std::make_unique<VMTHook>( prediction );
    prediction_hook->HookFunction( Hooks::RunCommand, 17 );
}

bool WINAPI DllMain( HINSTANCE dll_instance, DWORD call_reason, LPVOID reserved )
{
    if ( call_reason == DLL_PROCESS_ATTACH )
        CreateThread( nullptr, 0, LPTHREAD_START_ROUTINE( basehook_init ), dll_instance, 0, nullptr );

    return true;
}
