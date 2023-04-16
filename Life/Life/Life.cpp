// Life.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRTDBUG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#define new DBG_NEW
#endif
#endif

#pragma comment(lib, "MyStaticLib")

#include <iostream>
#include "pch.h"

using namespace std;

int main()
{
    const char* p1 = "Hello World";
    const char* p2 = "Hello World";
    int* p = new int{ 4 };
    p = nullptr;

    cout << &p1 << endl;
    cout << &p2 << endl;

    printf("%p\n", p1);
    printf("%p\n", p2);

    _CrtDumpMemoryLeaks();
}
