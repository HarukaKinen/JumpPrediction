#pragma once
// Buttons
#define IN_ATTACK (1 << 0)
#define IN_JUMP (1 << 1)
#define IN_DUCK (1 << 2)
#define IN_FORWARD (1 << 3)
#define IN_BACK (1 << 4)
#define IN_USE (1 << 5)
#define IN_CANCEL (1 << 6)
#define IN_LEFT (1 << 7)
#define IN_RIGHT (1 << 8)
#define IN_MOVELEFT (1 << 9)
#define IN_MOVERIGHT (1 << 10)
#define IN_ATTACK2 (1 << 11)
#define IN_RUN (1 << 12)
#define IN_RELOAD (1 << 13)
#define IN_ALT1 (1 << 14)
#define IN_ALT2 (1 << 15)
#define IN_SCORE (1 << 16)
#define IN_SPEED (1 << 17)
#define IN_WALK (1 << 18)
#define IN_ZOOM (1 << 19)
#define IN_WEAPON1 (1 << 20)
#define IN_WEAPON2 (1 << 21)
#define IN_BULLRUSH (1 << 22)
#define IN_GRENADE1 (1 << 23)
#define IN_GRENADE2 (1 << 24)
#define	IN_ATTACK3 (1 << 25)

// Flag condition
#define	FL_ONGROUND (1 << 0)
#define FL_DUCKING (1 << 1)
#define	FL_WATERJUMP (1 << 3)
#define FL_ONTRAIN (1 << 4)
#define FL_INRAIN (1 << 5)
#define FL_FROZEN (1 << 6)
#define FL_ATCONTROLS (1 << 7)
#define	FL_CLIENT (1 << 8)
#define FL_FAKECLIENT (1 << 9)
#define	FL_INWATER (1 << 10)
#define	FL_FLY (1 << 11)
#define	FL_SWIM (1 << 12)
#define	FL_CONVEYOR (1 << 13)
#define	FL_NPC (1 << 14)
#define	FL_GODMODE (1 << 15)
#define	FL_NOTARGET (1 << 16)
#define	FL_AIMTARGET (1 << 17)
#define	FL_PARTIALGROUND (1 << 18)
#define FL_STATICPROP (1 << 19)
#define FL_GRAPHED (1 << 20)
#define FL_GRENADE (1 << 21)
#define FL_STEPMOVEMENT (1 << 22)
#define FL_DONTTOUCH (1 << 23)
#define FL_BASEVELOCITY (1 << 24)
#define FL_WORLDBRUSH (1 << 25)
#define FL_OBJECT (1 << 26)
#define FL_KILLME (1 << 27)
#define FL_ONFIRE (1 << 28)
#define FL_DISSOLVING (1 << 29)
#define FL_TRANSRAGDOLL (1 << 30)
#define FL_UNBLOCKABLE_BY_PLAYER (1 << 31)

// Movetype
enum
{
    MOVETYPE_NONE = 0,
    // never moves
    MOVETYPE_ISOMETRIC,
    // For players -- in TF2 commander view, etc.
    MOVETYPE_WALK,
    // player only - moving on the ground
    MOVETYPE_STEP,
    // gravity, special edge handling -- monsters use this
    MOVETYPE_FLY,
    // No gravity, but still collides with stuff
    MOVETYPE_FLYGRAVITY,
    // flies through the air + is affected by gravity
    MOVETYPE_VPHYSICS,
    // uses VPHYSICS for simulation
    MOVETYPE_PUSH,
    // no clip to world, push and crush
    MOVETYPE_NOCLIP,
    // No gravity, no collisions, still do velocity/avelocity
    MOVETYPE_LADDER,
    // Used by players only when going onto a ladder
    MOVETYPE_OBSERVER,
    // Observer movement, depends on player's observer mode
    MOVETYPE_CUSTOM,
    // Allows the entity to describe its own physics
    MOVETYPE_LAST = MOVETYPE_CUSTOM,
    // should always be defined as the last item in the list
    MOVETYPE_MAX_BITS = 4
};

// Waterlevel
enum
{
    WL_NotInWater = 0,
    WL_Feet,
    WL_Waist,
    WL_Eyes
};
