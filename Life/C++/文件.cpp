#include "文件.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void RunOut()
{
    string strName;
    string strAge;

    ofstream ofs;
    ofs.seekp(12);  // 从指定位置开始输出

    ofs.open("as.txt");
    if (!ofs.is_open())
    {
        cerr << "文件打开失败" << endl;
        return;
    }

    for (;;)
    {
        cout << "请输入姓名：" << endl;
        cin >> strName;
        if (cin.eof())
            break;

        ofs << strName << endl;

        cout << "请输入年龄：" << endl;
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
        cerr << "文件打开失败" << endl;
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

void Run_文件定位()
{
    ifstream ifs;
    ifs.open("a.txt");
    if (!ifs.is_open())
        return;

    ifs.seekg(-50, ifs.end);    // 定位从那个位置开始读取
    ifs.tellg();    // 输出当前位置距起始位置的偏移量

    ifs.close();
}

//int main()
//{
//    //RunOut();
//    //RunIn();
//    std::cout << "Hello World" << std::endl;
//    return 0;
//}
