#pragma once
class Room;

class Maze
{
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const;

private:
    // 
};

