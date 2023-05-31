#pragma once

class Maze;
class MazeFactory;

class MazeGame
{
public:
    MazeGame();

    Maze* CreateMaze();
    Maze* CreateMaze(MazeFactory& factory);
};

