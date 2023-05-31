#pragma once
#include "MapSite.h"

class Room;

class Door : public MapSite
{
public:
    Door(Room* = nullptr, Room* = nullptr);

    virtual void Enter() override;

    bool IsOpen();

private:
    Room*   _pRoomLeft;
    Room*   _pRoomRight;
    bool    _isOpen;
};

