#pragma once
/* ------------------------------ 学习笔记 ------------------------------ *
List.h
这个头文件定义了用于处理列表的 List 数据类型
基本操作包括：
    构造函数
    empty：      检查列表是否为空
    insert：     插入一个项
    erase：      删除一个项
    display：    输出列表
    <<：         输出操作符
*/

#include <iostream>

const int CAPACITY = 1024;
typedef int ElementType;

class List
{
public:
    /* 函数成员 */

    /* 类构造函数 */
    List();
    /*
    * 创建一个 List 对象
    * 前置条件：无
    * 后置条件：创建了一个空 List 对象：mySize 为 0
    */

    /* 判空操作 */
    bool empty() const;
    /*
    * 检查列表是否为空
    * 前置条件：无
    * 后置条件：如果列表为空，返回 true，否则返回 false
    */

    /* 插入操作 */
    void insert(ElementType item, int pos);
    /*
    * 在列表中给定位置插入一个值
    * 前置条件：item 是将被插入的值；数组中有足够空间（mySize < CAPACITY）；并且
    *           插入位置满足 0 <= pos <= mySize
    * 后置条件：item 被插入到列表中由 pos 限定的位置（前提是有足够空间并 pos 是
    *           一个合法的位置）
    */

    /* 删除操作 */
    void erase(int pos);
    /*
    * 删除列表中给定位置的值
    * 前置条件：列表非空并给定位置满足 0 <= pos < mySize
    * 后置条件：由 pos 限定的位置处的元素被删除（前提是 pos 是一个合法的位置）
    */

    /* 输出 */
    void display(std::ostream& out) const;
    /*
    * 显示一个列表
    * 前置条件：ostream out 已经被打开
    * 后置条件：这个 List 对象所表示的列表被插入到 out 中
    */

private:
    /* 数据成员 */

    int mySize;                         // 当前存储在 myArray 中的列表的大小
    ElementType myArray[CAPACITY];      // 存储列表元素的数组
};  // --- List 类声明结束

// 输出操作符原型
std::ostream& operator<<(std::ostream& out, const List& aList);

