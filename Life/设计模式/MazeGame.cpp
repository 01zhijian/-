#include "MazeGame.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

#include "MazeFactory.h"

MazeGame::MazeGame()
{
}

/* ------------------------------ 学习笔记 ------------------------------ *

                    *********************
                    *         *         *
                    *   房间1 | 房间2   *
                    *         |         *
                    *         *         *
                    *********************


    房间、门和墙都可以看作是构件。

*/



Maze* MazeGame::CreateMaze()
{
    Maze* aMaze = new Maze();
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall);
    r1->SetSide(South, theDoor);
    r1->SetSide(East, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(West, theDoor);
    
    return nullptr;
}

Maze* MazeGame::CreateMaze(MazeFactory& factory)
{
    Maze* aMaze = factory.MakeMaze();
    Room* r1 = factory.MakeRoom(1);
    Room* r2 = factory.MakeRoom(2);
    Door* aDoor = factory.MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, factory.MakeWall());
    r1->SetSide(South, aDoor);
    r1->SetSide(East, factory.MakeWall());
    r1->SetSide(West, factory.MakeWall());

    r2->SetSide(North,factory.MakeWall());
    r2->SetSide(South,factory.MakeWall());
    r2->SetSide(East, factory.MakeWall());
    r2->SetSide(West, aDoor);

    return nullptr;
}
