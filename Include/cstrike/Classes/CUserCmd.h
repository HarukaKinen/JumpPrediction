#pragma once

class CUserCmd
{
private:
    virtual ~CUserCmd()
    {
    };
public:
    int command_number;
    int tick_count;
    float viewangles[3];
    float forwardmove;
    float sidemove;
    float upmove;
    int buttons;
    unsigned char impulse;
    int weaponselect;
    int weaponsubtype;
    int random_seed;
    short mousedx;
    short mousedy;
    bool hasbeenpredicted;
};
