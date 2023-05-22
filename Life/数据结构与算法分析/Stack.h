#pragma once

/* Stack.h
这个头文件定义了一个 Stack 数据类型
基本操作：
    构造函数：   创建一个空栈
    empty：      检查栈是否为空
    push：       通过在栈顶添加一个元素来修改栈
    top：        提取栈顶的值，保持栈不被改变
    pop：        通过删除栈顶的值来修改栈
    display：    显示所有的栈元素

类不变式：
    1.栈元素（如果有）被存储在 myArray 的 0、1、2...、myTop 等位置
    2.-1 <= myTop < STACK_CAPACITY
*/
#include <iostream>

const int STACK_CAPACITY = 128;
typedef int ElementType;

class Stack
{
public:
    /* 函数成员 */

    // 构造函数
    Stack();
    /*
    创建一个 Stack 对象
        前置条件：无
        后置条件：创建了一个空 Stack 对象（myTop 被初始化为 -1，myArray 是一个具有 STACK_CAPACITY 个 ElementType 类型元素的数组）
    */

    // 判空操作
    bool empty() const;
    /*
    检查栈是否为空
        前置条件：无
        后置条件：如果栈为空则返回 true，否则返回 false
    */

    // 入栈操作
    void push(const ElementType& value);
    /*
    添加一个值到栈中
        前置条件：value 是将被添加到这个栈中的值
        后置条件：如果栈中还有空间，值 value 被添加到栈顶；否则，显示一条栈满消息，执行被终止
    */

    // 出栈操作
    void pop();
    /*
    移除栈顶的值
        前置条件：栈非空
        后置条件：如果栈非空，则移除栈顶的值；否则，显示一条错误信息，执行可以继续下去
    */

    // 获取栈顶的值
    ElementType top() const;
    /*
    提取栈顶的值
        前置条件：栈非空
        后置条件：如果栈非空，则返回栈顶的值；否则，显示一条错误消息，并返回一个“垃圾值”
    */

    // 显示操作
    void display(std::ostream& out);
    /*
    显示栈中存储的值
        前置条件：ostream out 已经被打开
        后置条件：栈中的内容被从栈顶到栈底输出到 out
    */

private:
    /* 数据成员 */
    ElementType myArray[STACK_CAPACITY];
    int myTop;
};

