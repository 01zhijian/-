#pragma once

/* ------------------------------ 学习笔记 ------------------------------ *
Queue.h 包含类 Queue 的声明
基本操作：
    构造函数：创建一个空队列
    empty：检查队列是否为空
    enqueue：通过在队尾添加一个值来改变队列
    front：访问队首的值，并且保持队列不变
    dequeue：通过删除队首的值来改变一个队列
    display：从前端到后端显示队列元素
*/
#include <iostream>

const int QUEUE_CAPACITY = 128;
typedef int ElementType;

class Queue
{
public:
    /* 函数成员 */
    /* 构造函数 */
    Queue();
    /*
        创建一个 Queue 对象
        前置条件：无
        后置条件：创建了一个空 Queue 对象；myFront 和 myBack 被初始化为 -1，myArray 是一个有 QUEUE_CAPACITY
                个 ElementType 类型元素的数组
    */

    // 判空操作
    bool empty() const;
    /*
        检查队列是否为空
        前置条件：无
        后置条件：如果队列为空，返回 true，否则返回 false
    */

    // 入队操作
    void enqueue(const ElementType& value);
    /*
        添加一个值到队列中
        前置条件：value 是要被添加到这个队列的值
        后置条件：如果队列中有空间，value 被添加到队列的尾部；否则，显示一条队列满的消息，执行被终止
    */

    // 出队操作
    void dequeue();
    /*
        删除队列前端的值
        前置条件：队列非空
        后置条件：当队列非空时，队列前端的值被删除；否则，显示一条错误消息
    */

    // 获取队列前端的值
    ElementType front() const;
    /*
        获取前端的值
        前置条件：队列非空
        后置条件：当队列非空时，返回队列前端的值；否则，显示一条错误消息，并返回一个“垃圾值”
    */

    // 打印操作
    void display(std::ostream& out) const;
    /*
        输出存储在队列中的值
        前置条件：ostream out 已经被打开
        后置条件：队列中的内容，从前端到后端输出到 out
    */

private:
    /* 数据成员 */
    int myFront;
    int myBack;
    ElementType myArray[QUEUE_CAPACITY];
};

