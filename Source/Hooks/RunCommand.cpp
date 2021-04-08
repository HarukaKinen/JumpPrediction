#include "Hooks.h"

std::unique_ptr<VMTHook> prediction_hook;

void __fastcall Hooks::RunCommand( IPrediction* ecx, void* edx, CBaseEntity* player, CUserCmd* cmd, void* move_helper )
{
    auto original = prediction_hook->GetOriginalFunction<RunCommand_t>( 17 );

    auto* local = reinterpret_cast<CBaseEntity*>( entitylist->GetClientEntity( engine->GetLocalPlayer() ) );

    if ( cmd->buttons & IN_JUMP && local->GetMoveType() == MOVETYPE_WALK && local->GetWaterLevel() < WL_Waist && local->GetHealth() > 0 && !( local->GetFlags() & FL_ONGROUND ) )
    {
        cmd->buttons &= ~IN_JUMP;
    }

    original( ecx, edx, player, cmd, move_helper );
}
