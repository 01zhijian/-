#include "MainWindow.h"

#include <graphics.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

MainWindow::MainWindow()
{
    initgraph(640, 480);

    loadimage(nullptr, _T("bg.jpg"));
    DWORD ret = mciSendString(_T("test.mp3 repeat"), 0, 0, 0);

    // ���ñ���ɫ
    //setbkcolor(RGB(64, 128, 128));
    //cleardevice();

    // ���ñʵ���ʽ
    setlinecolor(RED);
    setlinestyle(PS_SOLID, 10);

    // �ı���ʽ
    settextcolor(YELLOW);
    settextstyle(100, 0, _T("΢���ź�"));

    circle(320, 240, 200);
    outtextxy(170, 190, _T("�������"));
    line(460, 100, 180, 380);

    wint_t i = _gettch();
    closegraph();

    
}
