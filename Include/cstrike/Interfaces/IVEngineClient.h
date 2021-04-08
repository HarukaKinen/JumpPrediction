#pragma once

template < typename Fn = void* >
Fn GetVirtualFunction(void* baseclass, size_t index)
{
    return reinterpret_cast<Fn>(*reinterpret_cast<void***>(baseclass)[index]);
}

class IVEngineClient
{
public:
    int GetLocalPlayer()
    {
        return GetVirtualFunction<int(__thiscall*)( IVEngineClient* )>( this, 12 )( this );
    }
};

extern IVEngineClient* engine;
