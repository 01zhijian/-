#pragma once
/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
����ָ��ڵ��ָ��
    Node* ptr; ����
    typedef Node* NodePointer;
    NodePointer ptr;

    ��ȡ�� ptr ָ����½ڵ�
    ptr = new Node;
    ptr = new Node(dataVla);
    ptr = new Node(dataVal, linkVar)

    �ͷ� ptr ָ��Ľڵ�
    delete ptr;

    ���� ptr ָ��Ľڵ�����ݲ��ֺ� next ����
    ptr->data �� ptr->next

    �����������֣�����ѭ������˫��������ͷ�ڵ�������


*/

/*
LinkedList.h
���ͷ�ļ����������ڴ����б�� LinkedList ��������
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
    search��     ����ָ����
*/


typedef int ElementType;

class LinkedList
{
    /* �ڵ��� */
private:
    class Node
    {
    public:
        ElementType data;
        Node* next;
    };
    typedef Node* NodePointer;

public:
    /* ������Ա */

private:
    /* ���ݳ�Ա */
    NodePointer first;  // ָ���һ���ڵ��ָ��
    int mySize;         // �ڵ����Ŀ

};

