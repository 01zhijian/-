#pragma once
#include <iostream>
#include <iomanip>


/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
    ѧϰ����������ͷ�ļ�


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

