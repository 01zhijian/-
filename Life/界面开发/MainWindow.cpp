#include "MainWindow.h"

#include <graphics.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

MainWindow::MainWindow()
{
    initgraph(640, 480);

    loadimage(nullptr, _T("bg.jpg"));
    DWORD ret = mciSendString(_T("test.mp3 repeat"), 0, 0, 0);

    // 设置背景色
    //setbkcolor(RGB(64, 128, 128));
    //cleardevice();

    // 设置笔的样式
    setlinecolor(RED);
    setlinestyle(PS_SOLID, 10);

    // 文本样式
    settextcolor(YELLOW);
    settextstyle(100, 0, _T("微软雅黑"));

    circle(320, 240, 200);
    outtextxy(170, 190, _T("无码高清"));
    line(460, 100, 180, 380);

    wint_t i = _gettch();
    closegraph();

    
}
