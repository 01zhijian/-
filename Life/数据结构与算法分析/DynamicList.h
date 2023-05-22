#pragma once
/* ------------------------------ 学习笔记 ------------------------------ *
DynamicList.h
这个头文件定义了用于处理列表的 DynamicList 数据类型
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
*/

#include <iostream>

typedef int ElementType;

class DynamicList
{
public:
    /* 函数成员 */

    /* 类构造函数 */
    DynamicList(int maxSize = 1024);
    /*
    * 创建一个 List 对象
    * 前置条件：maxSize 是一个正整数，默认值为 1024
    * 后置条件：创建了一个空 List 对象；myArray 指向容量为 myCapacity 的动态数组；mySize 为 0
    */

    /* 类析构函数 */
    ~DynamicList();
    /*
    * 销毁一个 List 对象
    * 前置条件：List 对象的生命周期已经结束
    * 后置条件：在构造函数中为 myArray 指向的数组所动态分配的内存空间被返回给堆
    */

    /* 赋值构造函数 */
    DynamicList(const DynamicList& origList);
    /*
    * 创建 DynamicList 对象的一份赋值
    * 前置条件：需要 origList 的一份复制；origList 是一个常引用形参
    * 后置条件：创建了 origList 的一份复制
    */

    /* 赋值运算符 */
    const DynamicList& operator=(const DynamicList& rightHandSide);
    /*
    * 将 DynamicList 对象的一份复制赋给当前对象
    * 前置条件：无
    * 后置条件：rightHandSide 的一份复制被赋给当前对象。返回当前列表的一个常引用
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
    * 前置条件：item 是将被插入的值；数组中有足够空间（mySize < myCapacity）；并且
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
    * 后置条件：这个 DinamicList 对象所表示的列表被插入到 out 中
    */

private:
    /* 数据成员 */
    int mySize;                     // 存储的列表的当前大小
    int myCapacity;                 // 数组的容量
    ElementType* myArray;           // 指向动态数组的指针
}; // --- DynamicList 类声明结束

// 输出操作符原型
std::ostream& operator<<(std::ostream& out, const DynamicList& aList);



