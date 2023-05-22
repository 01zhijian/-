#pragma once

/* Stack.h
���ͷ�ļ�������һ�� Stack ��������
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

const int STACK_CAPACITY = 128;
typedef int ElementType;

class Stack
{
public:
    /* ������Ա */

    // ���캯��
    Stack();
    /*
    ����һ�� Stack ����
        ǰ����������
        ����������������һ���� Stack ����myTop ����ʼ��Ϊ -1��myArray ��һ������ STACK_CAPACITY �� ElementType ����Ԫ�ص����飩
    */

    // �пղ���
    bool empty() const;
    /*
    ���ջ�Ƿ�Ϊ��
        ǰ����������
        �������������ջΪ���򷵻� true�����򷵻� false
    */

    // ��ջ����
    void push(const ElementType& value);
    /*
    ���һ��ֵ��ջ��
        ǰ��������value �ǽ�����ӵ����ջ�е�ֵ
        �������������ջ�л��пռ䣬ֵ value ����ӵ�ջ����������ʾһ��ջ����Ϣ��ִ�б���ֹ
    */

    // ��ջ����
    void pop();
    /*
    �Ƴ�ջ����ֵ
        ǰ��������ջ�ǿ�
        �������������ջ�ǿգ����Ƴ�ջ����ֵ��������ʾһ��������Ϣ��ִ�п��Լ�����ȥ
    */

    // ��ȡջ����ֵ
    ElementType top() const;
    /*
    ��ȡջ����ֵ
        ǰ��������ջ�ǿ�
        �������������ջ�ǿգ��򷵻�ջ����ֵ��������ʾһ��������Ϣ��������һ��������ֵ��
    */

    // ��ʾ����
    void display(std::ostream& out);
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

