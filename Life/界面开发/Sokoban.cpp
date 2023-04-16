#include "Sokoban.h"

#include <graphics.h>

constexpr int GameMap_Row = 9;
constexpr int GameMap_Column = 12;

// ��Ϸ��ͼ��С
constexpr int GameMap_Size_X = 960;
constexpr int GameMap_Size_Y = 720;

// ��Ϸ��ͼƫ����
constexpr int GameMap_Offset_X = 120;
constexpr int GameMap_Offset_Y = 90;

// ͼ���С
constexpr int IconSize = 61;

// ��������
IMAGE propIcon[ALL];

// ��Ϸ��ͼ
int GameMap[GameMap_Row][GameMap_Column] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0},
    {0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Sokoban::Sokoban()
{
}

void Sokoban::Run()
{
    // ���̨
    initgraph(GameMap_Size_X, GameMap_Size_Y);
    IMAGE bgImage;
    loadimage(&bgImage, _T("blackground.bmp"));
    putimage(0, 0, &bgImage);

    // ���ص���ͼ��
    loadimage(&propIcon[PropWall], _T("wall.bmp"));
    loadimage(&propIcon[PropFloor], _T("floor.bmp"));
    loadimage(&propIcon[PropDes], _T("des.bmp"));
    loadimage(&propIcon[PropMan], _T("man.bmp"));
    loadimage(&propIcon[PropBox], _T("box.bmp"));
    loadimage(&propIcon[PropHIT], _T("box.bmp"));

    // ������Դ
    for (int i = 0; i < GameMap_Row; ++i)
    {
        for (int j = 0; j < GameMap_Column; ++j)
        {
            if (GameMap[i][j] == PropMan)
            {
                m_PropMan.m_x = i;
                m_PropMan.m_y = j;
            }
            putimage(j * IconSize + GameMap_Offset_X, i * IconSize + GameMap_Offset_Y, &propIcon[GameMap[i][j]]);
        }
    }

    // ��Ϸ����
    bool quit = false;

    while (wint_t ch = _gettch())
    {
        switch (ch)
        {
        case Up:    GameControl(Up);        break;
        case Down:  GameControl(Down);      break;
        case Left:  GameControl(Left);      break;
        case Right: GameControl(Right);     break;
        case Quit: quit = true; break;
        default: break;
        }

        // �˳���Ϸ
        if (quit)
            break;

        // �ж���Ϸ�Ƿ����
        if (IsGameOver())
        {
            GameOverComplete(&bgImage);
            _gettch();
            break;
        }
    }

    // ��Ϸ�������ͷ���Դ
    closegraph();

}

void Sokoban::GameControl(MoveDirection move)
{
    // ���µ�λ��
    PropPosition newMan = m_PropMan;

    // �����µ�λ��
    PropPosition newBox = m_PropMan;

    switch (move)
    {
    case Up:
    {
        newMan.m_x--;
        newBox.m_x -= 2;
        break;
    }
    case Down:
    {
        newMan.m_x++;
        newBox.m_x += 2;
        break;
    }
    case Left:
    {
        newMan.m_y--;
        newBox.m_y -= 2;
        break;
    }
    case Right:
    {
        newMan.m_y++;
        newBox.m_y += 2;
        break;
    }
    default: break;
    }

    if (!IsValid(newMan))
        return;

    if (GameMap[newMan.m_x][newMan.m_y] == PropFloor)
    {
        UpdateCell(newMan, PropMan);
        UpdateCell(m_PropMan, PropFloor);

        m_PropMan = newMan;
    }
    else if (GameMap[newMan.m_x][newMan.m_y] == PropBox)
    {
        if (!IsValid(newBox))
            return;

        // �������������ǰ���ǵذ���������ӵ�Ŀ�ĵ�
        if (GameMap[newBox.m_x][newBox.m_y] == PropFloor)
        {
            UpdateCell(newBox, PropBox);
            UpdateCell(newMan, PropMan);
            UpdateCell(m_PropMan, PropFloor);

            m_PropMan = newMan;
        }
        else if (GameMap[newBox.m_x][newBox.m_y] == PropDes)
        {
            UpdateCell(newBox, PropHIT);
            UpdateCell(newMan, PropMan);
            UpdateCell(m_PropMan, PropFloor);

            m_PropMan = newMan;
        }
    }
}

void Sokoban::UpdateCell(const PropPosition& pos, PropIcon prop)
{
    GameMap[pos.m_x][pos.m_y] = prop;
    putimage(pos.m_y * IconSize + GameMap_Offset_X, pos.m_x * IconSize + GameMap_Offset_Y, &propIcon[GameMap[pos.m_x][pos.m_y]]);
}

bool Sokoban::IsValid(const PropPosition& pos)
{
    if (pos.m_x < 0 || pos.m_x > GameMap_Row || pos.m_y < 0 || pos.m_y > GameMap_Column)
        return false;

    return true;
}

bool Sokoban::IsGameOver()
{
    for (int i = 0; i < GameMap_Row; ++i)
    {
        for (int j = 0; j < GameMap_Column; ++j)
        {
            if (GameMap[i][j] == PropDes)
                return false;
        }
    }

    return true;
}

void Sokoban::GameOverComplete(IMAGE* pImage)
{
    putimage(0, 0, pImage);

    settextcolor(WHITE);

    RECT rect = { 0, 0, GameMap_Size_X, GameMap_Size_Y };
    settextstyle(20, 0, _T("����"));
    drawtext(_T("ͨ��"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}