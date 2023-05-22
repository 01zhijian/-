#pragma once
/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
DynamicList.h
���ͷ�ļ����������ڴ����б�� DynamicList ��������
��������������
    ���캯��
    ��������
    ���ƹ��캯��
    ��ֵ�����
    empty��      ����б��Ƿ�Ϊ��
    insert��     ����һ����
    erase��      ɾ��һ����
    display��    ����б�
    <<��         ���������
*/

#include <iostream>

typedef int ElementType;

class DynamicList
{
public:
    /* ������Ա */

    /* �๹�캯�� */
    DynamicList(int maxSize = 1024);
    /*
    * ����һ�� List ����
    * ǰ��������maxSize ��һ����������Ĭ��ֵΪ 1024
    * ����������������һ���� List ����myArray ָ������Ϊ myCapacity �Ķ�̬���飻mySize Ϊ 0
    */

    /* ���������� */
    ~DynamicList();
    /*
    * ����һ�� List ����
    * ǰ��������List ��������������Ѿ�����
    * �����������ڹ��캯����Ϊ myArray ָ�����������̬������ڴ�ռ䱻���ظ���
    */

    /* ��ֵ���캯�� */
    DynamicList(const DynamicList& origList);
    /*
    * ���� DynamicList �����һ�ݸ�ֵ
    * ǰ����������Ҫ origList ��һ�ݸ��ƣ�origList ��һ���������β�
    * ���������������� origList ��һ�ݸ���
    */

    /* ��ֵ����� */
    const DynamicList& operator=(const DynamicList& rightHandSide);
    /*
    * �� DynamicList �����һ�ݸ��Ƹ�����ǰ����
    * ǰ����������
    * ����������rightHandSide ��һ�ݸ��Ʊ�������ǰ���󡣷��ص�ǰ�б��һ��������
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
    * ǰ��������item �ǽ��������ֵ�����������㹻�ռ䣨mySize < myCapacity��������
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
    * ������������� DinamicList ��������ʾ���б����뵽 out ��
    */

private:
    /* ���ݳ�Ա */
    int mySize;                     // �洢���б�ĵ�ǰ��С
    int myCapacity;                 // ���������
    ElementType* myArray;           // ָ��̬�����ָ��
}; // --- DynamicList ����������

// ���������ԭ��
std::ostream& operator<<(std::ostream& out, const DynamicList& aList);



