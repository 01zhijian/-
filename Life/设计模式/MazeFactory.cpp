#include "MazeFactory.h"
#include "Maze.h"
#include "Door.h"
#include "Room.h"
#include "Wall.h"

MazeFactory::MazeFactory()
{
}

Maze* MazeFactory::MakeMaze() const
{
    return new Maze;
}

Wall* MazeFactory::MakeWall() const
{
    return new Wall;
}

Door* MazeFactory::MakeDoor(Room* r1, Room* r2) const
{
    return new Door(r1, r2);
}

Room* MazeFactory::MakeRoom(int n) const
{
    return new Room(n);
}
