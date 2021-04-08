#pragma once

typedef unsigned long CBaseHandle;

enum ShouldTransmitState_t;
enum DataUpdateType_t;

class ICollideable;
class IClientRenderable;
class IClientEntity;
class C_BaseEntity;
class IClientThinkable;
class IClientNetworkable;
class Vector;
class QAngle;

class IHandleEntity
{
public:
    virtual ~IHandleEntity()
    {
    };
    virtual void SetRefEHandle( const CBaseHandle& Handle ) = 0;
    virtual const CBaseHandle& GetRefEHandle() const = 0;
};

class IClientUnknown : public IHandleEntity
{
public:
    virtual ICollideable* GetCollideable() = 0;
    virtual IClientNetworkable* GetClientNetworkable() = 0;
    virtual IClientRenderable* GetClientRenderable() = 0;
    virtual IClientEntity* GetIClientEntity() = 0;
    virtual C_BaseEntity* GetBaseEntity() = 0;
    virtual IClientThinkable* GetClientThinkable() = 0;
};

class IClientRenderable
{
public:
    virtual IClientUnknown* GetIClientUnknown() = 0;
    virtual Vector const& GetRenderOrigin( void ) = 0;
    virtual QAngle const& GetRenderAngles( void ) = 0;
};

class IClientNetworkable
{
public:
    virtual IClientUnknown* GetIClientUnknown() = 0;
    virtual void Release() = 0;
    virtual void* GetClientClass() = 0;
    virtual void NotifyShouldTransmit( ShouldTransmitState_t state ) = 0;
    virtual void OnPreDataChanged( DataUpdateType_t type ) = 0;
    virtual void OnDataChanged( DataUpdateType_t type ) = 0;
    virtual void PreDataUpdate( DataUpdateType_t type ) = 0;
    virtual void PostDataUpdate( DataUpdateType_t type ) = 0;
    virtual bool IsDormant( void ) = 0;
    virtual int GetIndex( void ) const = 0;
};

class IClientThinkable
{
public:
    virtual IClientUnknown* GetIClientUnknown() = 0;
};

class IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
    void Release( void ) override = 0;
    virtual const Vector& GetAbsOrigin( void ) const = 0;
    virtual const QAngle& GetAbsAngles( void ) const = 0;
};

class CBaseEntity : public IClientEntity
{
public:
    int GetMoveType()
    {
        return *reinterpret_cast<int*>( reinterpret_cast<uintptr_t>( this ) + 0x178 );
    }

    int GetHealth()
    {
        return *reinterpret_cast<int*>( reinterpret_cast<uintptr_t>( this ) + 0x0094 );
    }

    char GetWaterLevel()
    {
        return *reinterpret_cast<char*>( reinterpret_cast<uintptr_t>( this ) + 0x017C );
    }

    int GetFlags()
    {
        return *reinterpret_cast<int*>( reinterpret_cast<uintptr_t>( this ) + 0x0350 );
    }
};
