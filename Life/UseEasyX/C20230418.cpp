#include "C20230418.h"

// 引入图形库
#include <graphics.h>

constexpr int WindowWidth   = 600;
constexpr int WindowHeight  = 600;

C20230418::C20230418()
{
    // 初始化绘图窗口
    initgraph(WindowWidth, WindowHeight);

    // 运行
    Run();

    // 阻止窗口关闭
    wint_t ch = _gettch();
}

C20230418::~C20230418()
{
    // 关闭绘图窗口
    closegraph();
}

void C20230418::Run()
{  
    // 调用绘图设备相关函数
    TestRenderDevice();
}

void C20230418::TestRenderDevice()
{
    // 设置坐标原点
    //setorigin(100, 100);

    float xasp = 0;
    float yasp = 0;

    //setaspectratio(1, 2);

    // 获取当前缩放因子
    getaspectratio(&xasp, &yasp);

    // 重置视图、当前点、绘图色、背景色、线形、填充样式、字体为默认值
    //graphdefaults();

    // 创建一个举行区域
    HRGN hrgn = CreateRectRgn(100, 100, 200, 200);

    // 将该矩形区域设置为裁剪区
    setcliprgn(hrgn);

    // 清理 rgn 占用的系统资源
    DeleteObject(hrgn);

    // 画圆，受裁剪区影响，只显示出四段圆弧
    //circle(150, 150, 60);

    // 取消之前的裁剪区
    setcliprgn(nullptr);

    // 画圆，不再受裁剪区影响，显示出一个完整的圆
    //circle(150, 150, 60);

    // 测试画圆
    Circle_Bresenham(320, 240, 200, RED);
}

void C20230418::TestColorModel()
{
    
}


// 使用 Bresenham 画圆法
void C20230418::Circle_Bresenham(int x, int y, int r, int color)
{
    int tx = 0, ty = r, d = 3 - 2 * r;

    while (tx <= ty)
    {
        // 利用圆的八分对称性画点
        putpixel(x + tx, y + ty, color);
        putpixel(x + tx, y - ty, color);
        putpixel(x - tx, y + ty, color);
        putpixel(x - tx, y - ty, color);
        putpixel(x + ty, y + tx, color);
        putpixel(x + ty, y - tx, color);
        putpixel(x - ty, y + tx, color);
        putpixel(x - ty, y - tx, color);

        if (d < 0)		// 取上面的点
            d += 4 * tx + 6;
        else			// 取下面的点
            d += 4 * (tx - ty) + 10, ty--;

        tx++;
    }
}