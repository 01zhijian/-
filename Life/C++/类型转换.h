#pragma once
#include <iostream>

using namespace std;

class ����ת��
{
public:
    ����ת��(int a) : a(a){}
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
        //A a2(); ��ᱻ��Ϊ�Ǻ�������
        A a3(1);
        A a4(a1);

        // ��ʾ�ص��ù��캯������ֱ�ӳ�ʼ��ʵ��������ʾ����ת����һ��

        // ���ð�����
        int a5 = 10;
        //long& a6 = a5;
        // ��ʽ����ת��������ͨ������ֵ

        // �����˻����⣨ʹ��std::array�����

        // ����ת������

        // ���飺������Ҫȥ������ʽ����ת�������� explicit �͸�����ʾת�������뵱Ȼ
    }

    static void Test()
    {
        int a = 10;
        long b = a;
        int c = b;

        shared_ptr<int> ptr = nullptr;
        if (ptr) // ������ shared_ptr ת���� bool
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
        cout << "��ͨ����" << endl;
    }

    Person(const Person& person)
    {
        cout << "��������" << endl;
    }

    void Test()
    {
        //int (*pf)(int, int) = Add;
    }
};

