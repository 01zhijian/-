#include <iostream>
#include <Windows.h>
#include "MyThread.h"

using namespace std;

int main()
{
    TestThread();

    cout << "���߳� == " << GetCurrentThreadId() << endl;

    system("pause");
    return 0;
}