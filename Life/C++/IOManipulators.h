#pragma once
#include <iostream>
#include <iomanip>


/* ------------------------------ 学习笔记 ------------------------------ *
    学习参数化操作头文件


*/


using namespace std;

class IOManipulators
{
public:
    static void Testsetiosflags()
    {
        cout << hex;
        cout << setiosflags(ios::showbase | ios::uppercase);
        cout << 100 << endl;

        cout << 100 << endl;
    }
};

