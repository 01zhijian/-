#pragma once
/* ------------------------------ 学习笔记 ------------------------------ *
声明指向节点的指针
    Node* ptr; 或者
    typedef Node* NodePointer;
    NodePointer ptr;

    获取由 ptr 指向的新节点
    ptr = new Node;
    ptr = new Node(dataVla);
    ptr = new Node(dataVal, linkVar)

    释放 ptr 指向的节点
    delete ptr;

    访问 ptr 指向的节点的数据部分和 next 部分
    ptr->data 和 ptr->next

    链表有许多变种，例如循环链表、双向链表、带头节点的链表等


*/

/*
LinkedList.h
这个头文件定义了用于处理列表的 LinkedList 数据类型
基本操作包括：
    构造函数
    析构函数
    复制构造函数
    赋值运算符
    empty：      检查列表是否为空
    insert：     插入一个项
    erase：      删除一个项
    display：    输出列表
    <<：         输出操作符
    search：     查找指定项
*/


typedef int ElementType;

class LinkedList
{
    /* 节点类 */
private:
    class Node
    {
    public:
        ElementType data;
        Node* next;
    };
    typedef Node* NodePointer;

public:
    /* 函数成员 */

private:
    /* 数据成员 */
    NodePointer first;  // 指向第一个节点的指针
    int mySize;         // 节点的数目

};

