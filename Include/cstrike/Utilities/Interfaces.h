#pragma once

#include <string>

typedef void* (*InstantiateInterfaceFn)();

class InterfaceReg
{
public:
    InstantiateInterfaceFn m_CreateFn;
    const char* m_pName;
    InterfaceReg* m_pNext;
};

inline const InterfaceReg* GetInterfaceList( const char* library )
{
    // Get the address to the exported 'CreateInterface' procedure.
    uintptr_t createinterface_addr = uintptr_t( GetProcAddress( GetModuleHandleA( library ), "CreateInterface" ) );

    // Get the jump displacement to the 'CreateInterfaceInternal' function.
    uintptr_t jump_instruction = static_cast<uintptr_t>( createinterface_addr ) + 4;
    int32_t jump_displacement = *reinterpret_cast<int32_t*>( jump_instruction + 1 );

    // Calculate the absolute jump address relative to the next instruction.
    uintptr_t createinterfaceinternal_addr = ( jump_instruction + 5 ) + jump_displacement;

    // Read the address to the 'InterfaceReg::s_pInterfaceRegs' linked list from 6 bytes in.
    uintptr_t interface_list = *reinterpret_cast<uintptr_t*>( createinterfaceinternal_addr + 6 );

    return *reinterpret_cast<InterfaceReg**>( interface_list );
}

template < typename T = void* >
T* GetInterface( const char* library, const char* partial_version )
{
    for ( const InterfaceReg* current = GetInterfaceList( library ); current; current = current->m_pNext )
        if ( std::string( current->m_pName ).find( partial_version ) != std::string::npos )
            return reinterpret_cast<T*>( current->m_CreateFn() );

    return nullptr;
}
