#pragma once

/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
Queue.h ������ Queue ������
����������
    ���캯��������һ���ն���
    empty���������Ƿ�Ϊ��
    enqueue��ͨ���ڶ�β���һ��ֵ���ı����
    front�����ʶ��׵�ֵ�����ұ��ֶ��в���
    dequeue��ͨ��ɾ�����׵�ֵ���ı�һ������
    display����ǰ�˵������ʾ����Ԫ��
*/
#include <iostream>

const int QUEUE_CAPACITY = 128;
typedef int ElementType;

class Queue
{
public:
    /* ������Ա */
    /* ���캯�� */
    Queue();
    /*
        ����һ�� Queue ����
        ǰ����������
        ����������������һ���� Queue ����myFront �� myBack ����ʼ��Ϊ -1��myArray ��һ���� QUEUE_CAPACITY
                �� ElementType ����Ԫ�ص�����
    */

    // �пղ���
    bool empty() const;
    /*
        �������Ƿ�Ϊ��
        ǰ����������
        �����������������Ϊ�գ����� true�����򷵻� false
    */

    // ��Ӳ���
    void enqueue(const ElementType& value);
    /*
        ���һ��ֵ��������
        ǰ��������value ��Ҫ����ӵ�������е�ֵ
        ��������������������пռ䣬value ����ӵ����е�β����������ʾһ������������Ϣ��ִ�б���ֹ
    */

    // ���Ӳ���
    void dequeue();
    /*
        ɾ������ǰ�˵�ֵ
        ǰ�����������зǿ�
        ���������������зǿ�ʱ������ǰ�˵�ֵ��ɾ����������ʾһ��������Ϣ
    */

    // ��ȡ����ǰ�˵�ֵ
    ElementType front() const;
    /*
        ��ȡǰ�˵�ֵ
        ǰ�����������зǿ�
        ���������������зǿ�ʱ�����ض���ǰ�˵�ֵ��������ʾһ��������Ϣ��������һ��������ֵ��
    */

    // ��ӡ����
    void display(std::ostream& out) const;
    /*
        ����洢�ڶ����е�ֵ
        ǰ��������ostream out �Ѿ�����
        ���������������е����ݣ���ǰ�˵��������� out
    */

private:
    /* ���ݳ�Ա */
    int myFront;
    int myBack;
    ElementType myArray[QUEUE_CAPACITY];
};

