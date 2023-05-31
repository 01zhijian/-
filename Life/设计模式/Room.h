#pragma once
#include "Core.h"
#include "MapSite.h"

class Room : public MapSite
{
public:
    Room(int roomNo);

    virtual void Enter() override;

    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);

private:
    MapSite*    _pSideList[DirectionNumber];
    int         _nRoomNumber;
};

