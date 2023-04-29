#include "MyThread.h"

#include <iostream>
#include <Windows.h>

#include <process.h>

using namespace std;



unsigned __stdcall ThreadMartin(void* arg)
{
    int nCount = *((int*)arg);
    for (int i = 0; i < nCount; ++i)
    {
        Sleep(1000);
        cout << "ThreadMartin == " << GetCurrentThreadId() << endl;
    }

    return 0;
}

unsigned __stdcall ThreadRock(void* arg)
{
    int nCount = *((int*)arg);
    for (int i = 0; i < nCount; ++i)
    {
        Sleep(1000);
        cout << "ThreadRock == " << GetCurrentThreadId() << endl;
    }

    return 0;
}

unsigned __stdcall ThreadXiXi(void* arg)
{
    int nCount = *((int*)arg);
    for (int i = 0; i < nCount; ++i)
    {
        Sleep(1000);
        cout << "ThreadXiXi == " << GetCurrentThreadId() << endl;
    }

    return 0;
}

void TestThread()
{
    int martin = 50;
    int rock = 50;
    int xixi = 50;

    unsigned int martin_id;
    unsigned int rock_id;
    unsigned int xixi_id;

    _beginthreadex(nullptr, 0, ThreadMartin, &martin, 0, &martin_id);
    _beginthreadex(nullptr, 0, ThreadRock, &rock, 0, &rock_id);
    _beginthreadex(nullptr, 0, ThreadXiXi, &xixi, 0, &xixi_id);

    cout << martin_id << " ---- " << rock_id << " ---- " << xixi_id << endl;
}