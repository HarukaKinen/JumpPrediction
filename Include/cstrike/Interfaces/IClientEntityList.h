#pragma once

class IClientEntity;
class IClientNetworkable;
class IClientUnknown;

class IClientEntityList
{
public:
    virtual IClientNetworkable* GetClientNetworkable( int entindex ) = 0;
    virtual IClientNetworkable* GetClientNetworkableFromHandle( CBaseHandle handle ) = 0;
    virtual IClientUnknown* GetClientUnknownFromHandle( CBaseHandle handle ) = 0;
    virtual IClientEntity* GetClientEntity( int entindex ) = 0;
    virtual IClientEntity* GetClientEntityFromHandle( CBaseHandle handle ) = 0;
    virtual int NumberOfEntities( bool include_non_networkable ) = 0;
    virtual int GetHighestEntityIndex( void ) = 0;
    virtual void SetMaxEntities( int max_entities ) = 0;
    virtual int GetMaxEntities() = 0;
};

extern IClientEntityList* entitylist;
