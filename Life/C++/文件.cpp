#include "�ļ�.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void RunOut()
{
    string strName;
    string strAge;

    ofstream ofs;
    ofs.seekp(12);  // ��ָ��λ�ÿ�ʼ���

    ofs.open("as.txt");
    if (!ofs.is_open())
    {
        cerr << "�ļ���ʧ��" << endl;
        return;
    }

    for (;;)
    {
        cout << "������������" << endl;
        cin >> strName;
        if (cin.eof())
            break;

        ofs << strName << endl;

        cout << "���������䣺" << endl;
        cin >> strAge;
        ofs << strAge << endl;
    }

    ofs.close();
}

void RunIn()
{
    string name;
    int age = 0;

    ifstream ifs;
    ifs.open("ae.txt");
    if (!ifs.is_open())
    {
        cerr << "�ļ���ʧ��" << endl;
        return;
    }

    //ifs.good();
    //ifs.fail();
    //ifs.bad();
    ifs.clear();

    ifs >> name;
    ifs >> age;

    cout << name << " : " << age << endl;
    
    ifs >> name;
    ifs >> age;

    cout << name << " : " << age << endl;

    ifs.close();
}

void Run_�ļ���λ()
{
    ifstream ifs;
    ifs.open("a.txt");
    if (!ifs.is_open())
        return;

    ifs.seekg(-50, ifs.end);    // ��λ���Ǹ�λ�ÿ�ʼ��ȡ
    ifs.tellg();    // �����ǰλ�þ���ʼλ�õ�ƫ����

    ifs.close();
}

//int main()
//{
//    //RunOut();
//    //RunIn();
//    std::cout << "Hello World" << std::endl;
//    return 0;
//}
