#pragma once
#include <iostream>

using namespace std;

class 类型转换
{
public:
    类型转换(int a) : a(a){}
    struct A
    {
        A()
        {

        }

        A(const A&)
        {

        }

        A(int)
        {

        }

    };

    void TestA()
    {
        A a1{};
        //A a2(); 这会被认为是函数声明
        A a3(1);
        A a4(a1);

        // 显示地调用构造函数进行直接初始化实际上是显示类型转换的一种

        // 引用绑定问题
        int a5 = 10;
        //long& a6 = a5;
        // 隐式类型转换产生的通常是右值

        // 数组退化问题（使用std::array解决）

        // 两步转换问题

        // 建议：尽量不要去依赖隐式类型转换，多用 explicit 和各种显示转换，少想当然
    }

    static void Test()
    {
        int a = 10;
        long b = a;
        int c = b;

        shared_ptr<int> ptr = nullptr;
        if (ptr) // 这里会从 shared_ptr 转换成 bool
        {

        }
    }

private:
    int& a;
};

class Person
{
public:
    Person()
    {
        cout << "普通构造" << endl;
    }

    Person(const Person& person)
    {
        cout << "拷贝构造" << endl;
    }

    void Test()
    {
        //int (*pf)(int, int) = Add;
    }
};

