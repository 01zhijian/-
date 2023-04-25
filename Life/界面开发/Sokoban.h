#pragma once

class IMAGE;

struct PropPosition
{
    PropPosition() : m_x(0), m_y(0) {}

    int m_x;  // С�����ڵ���
    int m_y;  // С�����ڵ���
};

enum PropIcon
{
    PropWall = 0,       // ǽ
    PropFloor,          // �ذ�
    PropDes,            // Ŀ��λ��
    PropMan,            // ��
    PropBox,            // ����
    PropHIT,            // ��������Ŀ��

    ALL
};

enum MoveDirection
{
    Up = 'w',
    Down = 's',
    Left = 'a',
    Right = 'd',

    Quit = 'q'   // ֹͣ��Ϸ
};

class Sokoban
{
public:
    Sokoban();
    
    /*
    * ������Ϸ
    */
    void Run();
    
private:
    /*
    * �����˵��ƶ�
    * @param move ���ƶ��ķ���
    */
    void GameControl(MoveDirection move);

    /*
    * ���µ�ͼ
    * @param man ��
    */
    void UpdateCell(const PropPosition& pos, PropIcon prop);

    /*
    * �ж��ƶ��Ƿ���Ч
    * @param pos ��һ��λ��
    */
    bool IsValid(const PropPosition& pos);

    /*
    * �ж���Ϸ�Ƿ����
    * @return true - ��Ϸ����   false - ��Ϸ����
    */
    bool IsGameOver();

    /*
    * ��Ϸ����֮�����Ĳ���
    */
    void GameOverComplete(IMAGE* pImage);

private:
    PropPosition m_PropMan;
};


