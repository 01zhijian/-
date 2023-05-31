#pragma once

class Maze;
class Wall;
class Door;
class Room;

class MazeFactory
{
public:
    MazeFactory();

    virtual Maze* MakeMaze() const;
    virtual Wall* MakeWall() const;
    virtual Door* MakeDoor(Room* r1, Room* r2) const;
    virtual Room* MakeRoom(int n) const;
};

