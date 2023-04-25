#pragma once
class C20230418
{
public:
    C20230418();
    ~C20230418();

    void Run();

    // 测试绘图设备相关函数
    void TestRenderDevice();

    // 测试颜色模型
    void TestColorModel();

    // 使用 Bresenham 画圆法
    void Circle_Bresenham(int x, int y, int r, int color);
};

