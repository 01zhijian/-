#pragma once

class IMAGE;

struct PropPosition
{
    PropPosition() : m_x(0), m_y(0) {}

    int m_x;  // 小人所在的行
    int m_y;  // 小人所在的列
};

enum PropIcon
{
    PropWall = 0,       // 墙
    PropFloor,          // 地板
    PropDes,            // 目标位置
    PropMan,            // 人
    PropBox,            // 箱子
    PropHIT,            // 箱子命中目标

    ALL
};

enum MoveDirection
{
    Up = 'w',
    Down = 's',
    Left = 'a',
    Right = 'd',

    Quit = 'q'   // 停止游戏
};

class Sokoban
{
public:
    Sokoban();
    
    /*
    * 启动游戏
    */
    void Run();

private:
    /*
    * 控制人的移动
    * @param move 人移动的方向
    */
    void GameControl(MoveDirection move);

    /*
    * 更新地图
    * @param man 人
    */
    void UpdateCell(const PropPosition& pos, PropIcon prop);

    /*
    * 判断移动是否有效
    * @param pos 下一个位置
    */
    bool IsValid(const PropPosition& pos);

    /*
    * 判断游戏是否结束
    * @return true - 游戏结束   false - 游戏继续
    */
    bool IsGameOver();

    /*
    * 游戏结束之后做的操作
    */
    void GameOverComplete(IMAGE* pImage);

private:
    PropPosition m_PropMan;
};


