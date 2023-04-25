#include "C20230418.h"

// ����ͼ�ο�
#include <graphics.h>

constexpr int WindowWidth   = 600;
constexpr int WindowHeight  = 600;

C20230418::C20230418()
{
    // ��ʼ����ͼ����
    initgraph(WindowWidth, WindowHeight);

    // ����
    Run();

    // ��ֹ���ڹر�
    wint_t ch = _gettch();
}

C20230418::~C20230418()
{
    // �رջ�ͼ����
    closegraph();
}

void C20230418::Run()
{  
    // ���û�ͼ�豸��غ���
    TestRenderDevice();
}

void C20230418::TestRenderDevice()
{
    // ��������ԭ��
    //setorigin(100, 100);

    float xasp = 0;
    float yasp = 0;

    //setaspectratio(1, 2);

    // ��ȡ��ǰ��������
    getaspectratio(&xasp, &yasp);

    // ������ͼ����ǰ�㡢��ͼɫ������ɫ�����Ρ������ʽ������ΪĬ��ֵ
    //graphdefaults();

    // ����һ����������
    HRGN hrgn = CreateRectRgn(100, 100, 200, 200);

    // ���þ�����������Ϊ�ü���
    setcliprgn(hrgn);

    // ���� rgn ռ�õ�ϵͳ��Դ
    DeleteObject(hrgn);

    // ��Բ���ܲü���Ӱ�죬ֻ��ʾ���Ķ�Բ��
    //circle(150, 150, 60);

    // ȡ��֮ǰ�Ĳü���
    setcliprgn(nullptr);

    // ��Բ�������ܲü���Ӱ�죬��ʾ��һ��������Բ
    //circle(150, 150, 60);

    // ���Ի�Բ
    Circle_Bresenham(320, 240, 200, RED);
}

void C20230418::TestColorModel()
{
    
}


// ʹ�� Bresenham ��Բ��
void C20230418::Circle_Bresenham(int x, int y, int r, int color)
{
    int tx = 0, ty = r, d = 3 - 2 * r;

    while (tx <= ty)
    {
        // ����Բ�İ˷ֶԳ��Ի���
        putpixel(x + tx, y + ty, color);
        putpixel(x + tx, y - ty, color);
        putpixel(x - tx, y + ty, color);
        putpixel(x - tx, y - ty, color);
        putpixel(x + ty, y + tx, color);
        putpixel(x + ty, y - tx, color);
        putpixel(x - ty, y + tx, color);
        putpixel(x - ty, y - tx, color);

        if (d < 0)		// ȡ����ĵ�
            d += 4 * tx + 6;
        else			// ȡ����ĵ�
            d += 4 * (tx - ty) + 10, ty--;

        tx++;
    }
}