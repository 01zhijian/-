#include <iostream>
#include <Windows.h>
#include "MyThread.h"

using namespace std;

int main()
{
    TestThread();

    cout << "Ö÷Ïß³Ì == " << GetCurrentThreadId() << endl;

    system("pause");
    return 0;
}