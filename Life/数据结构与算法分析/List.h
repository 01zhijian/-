#pragma once
/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
List.h
���ͷ�ļ����������ڴ����б�� List ��������
��������������
    ���캯��
    empty��      ����б��Ƿ�Ϊ��
    insert��     ����һ����
    erase��      ɾ��һ����
    display��    ����б�
    <<��         ���������
*/

#include <iostream>

const int CAPACITY = 1024;
typedef int ElementType;

class List
{
public:
    /* ������Ա */

    /* �๹�캯�� */
    List();
    /*
    * ����һ�� List ����
    * ǰ����������
    * ����������������һ���� List ����mySize Ϊ 0
    */

    /* �пղ��� */
    bool empty() const;
    /*
    * ����б��Ƿ�Ϊ��
    * ǰ����������
    * ��������������б�Ϊ�գ����� true�����򷵻� false
    */

    /* ������� */
    void insert(ElementType item, int pos);
    /*
    * ���б��и���λ�ò���һ��ֵ
    * ǰ��������item �ǽ��������ֵ�����������㹻�ռ䣨mySize < CAPACITY��������
    *           ����λ������ 0 <= pos <= mySize
    * ����������item �����뵽�б����� pos �޶���λ�ã�ǰ�������㹻�ռ䲢 pos ��
    *           һ���Ϸ���λ�ã�
    */

    /* ɾ������ */
    void erase(int pos);
    /*
    * ɾ���б��и���λ�õ�ֵ
    * ǰ���������б�ǿղ�����λ������ 0 <= pos < mySize
    * ������������ pos �޶���λ�ô���Ԫ�ر�ɾ����ǰ���� pos ��һ���Ϸ���λ�ã�
    */

    /* ��� */
    void display(std::ostream& out) const;
    /*
    * ��ʾһ���б�
    * ǰ��������ostream out �Ѿ�����
    * ������������� List ��������ʾ���б����뵽 out ��
    */

private:
    /* ���ݳ�Ա */

    int mySize;                         // ��ǰ�洢�� myArray �е��б�Ĵ�С
    ElementType myArray[CAPACITY];      // �洢�б�Ԫ�ص�����
};  // --- List ����������

// ���������ԭ��
std::ostream& operator<<(std::ostream& out, const List& aList);

