#pragma once

/* Stack2.h
���ͷ�ļ�������һ�� Stack2 ��������
����������
    ���캯����   ����һ����ջ
    empty��      ���ջ�Ƿ�Ϊ��
    push��       ͨ����ջ�����һ��Ԫ�����޸�ջ
    top��        ��ȡջ����ֵ������ջ�����ı�
    pop��        ͨ��ɾ��ջ����ֵ���޸�ջ
    display��    ��ʾ���е�ջԪ��

�಻��ʽ��
    1.ջԪ�أ�����У����洢�� myArray �� 0��1��2...��myTop ��λ��
    2.-1 <= myTop < STACK_CAPACITY
*/
#include <iostream>

//const int STACK_CAPACITY = 128;
//typedef int ElementType;

template <typename ElementType, const int STACK_CAPACITY>
class Stack2
{
public:
    /* ������Ա */

    // ���캯��
    Stack2()
        : myTop(-1)
    {

    }
    /*
    ����һ�� Stack ����
        ǰ����������
        ����������������һ���� Stack ����myTop ����ʼ��Ϊ -1��myArray ��һ������ STACK_CAPACITY �� ElementType ����Ԫ�ص����飩
    */

    // �пղ���
    bool empty() const
    {
        return myTop == -1;
    }
    /*
    ���ջ�Ƿ�Ϊ��
        ǰ����������
        �������������ջΪ���򷵻� true�����򷵻� false
    */

    // ��ջ����
    void push(const ElementType& value)
    {
        if (myTop < STACK_CAPACITY - 1)     // ����ջ����ʽ
        {
            ++myTop;
            myArray[myTop] = value;
        }
        else
        {
            std::cerr << "*** Stack full -- can't add new value ***\n"
                "Must increase value of STACK_CAPACITY in Stack.h\n";
            exit(1);

            /* ------------------------------ ѧϰ�ʼ� ------------------------------ *
            �ڴ������������ʱ���ж��ַ�����
            ����ʾһ��������Ϣ����ִֹ��
            ����ʾһ��������Ϣ����������ִ�м�����ȥ
            ���׳�һ���쳣
            ������һ������ֵ����ʾ�����ǳɹ���true������ʧ�ܣ�false����
            */
        }
    }
    /*
    ���һ��ֵ��ջ��
        ǰ��������value �ǽ�����ӵ����ջ�е�ֵ
        �������������ջ�л��пռ䣬ֵ value ����ӵ�ջ����������ʾһ��ջ����Ϣ��ִ�б���ֹ
    */

    // ��ջ����
    void pop()
    {
        if (!empty())
            --myTop;
        else
            std::cerr << "*** Stack is empty -- can't remove a value ***\n";
    }
    /*
    �Ƴ�ջ����ֵ
        ǰ��������ջ�ǿ�
        �������������ջ�ǿգ����Ƴ�ջ����ֵ��������ʾһ��������Ϣ��ִ�п��Լ�����ȥ
    */

    // ��ȡջ����ֵ
    ElementType top() const
    {
        if (!empty())
            return myArray[myTop];
        else
        {
            std::cerr << "*** Stack is empty -- returning garbage value ***\n";
            return ElementType();
        }
    }
    /*
    ��ȡջ����ֵ
        ǰ��������ջ�ǿ�
        �������������ջ�ǿգ��򷵻�ջ����ֵ��������ʾһ��������Ϣ��������һ��������ֵ��
    */

    // ��ʾ����
    void display(std::ostream& out)
    {
        for (auto value : myArray)
        {
            out << value << " ";
        }
        out << std::endl;
    }
    /*
    ��ʾջ�д洢��ֵ
        ǰ��������ostream out �Ѿ�����
        ����������ջ�е����ݱ���ջ����ջ������� out
    */

private:
    /* ���ݳ�Ա */
    ElementType myArray[STACK_CAPACITY];
    int myTop;
};