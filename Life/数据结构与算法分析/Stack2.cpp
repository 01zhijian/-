//#include "Stack2.h"
//
///* Stack2.cpp
//这个文件包含 Stack 成员函数的实现
//*/
//
//template <typename ElementType>
//Stack2<ElementType>::Stack2()
//    : myTop(-1)
//{
//}
//
//template <typename ElementType>
//bool Stack2<ElementType>::empty() const
//{
//    return myTop == -1;
//}
//
//template <typename ElementType>
//void Stack2<ElementType>::push(const ElementType& value)
//{
//    if (myTop < STACK_CAPACITY - 1)     // 保持栈不变式
//    {
//        ++myTop;
//        myArray[myTop] = value;
//    }
//    else
//    {
//        std::cerr << "*** Stack full -- can't add new value ***\n"
//            "Must increase value of STACK_CAPACITY in Stack.h\n";
//        exit(1);
//
//        /* ------------------------------ 学习笔记 ------------------------------ *
//        在处理数组满情况时，有多种方法：
//        ·显示一条错误消息并终止执行
//        ·显示一条错误消息，但是允许执行继续下去
//        ·抛出一条异常
//        ·返回一个布尔值来表示操作是成功（true）还是失败（false）了
//        */
//    }
//}
//
//template <typename ElementType>
//void Stack2<ElementType>::pop()
//{
//    if (!empty())
//        --myTop;
//    else
//        std::cerr << "*** Stack is empty -- can't remove a value ***\n";
//}
//
//template <typename ElementType>
//ElementType Stack2<ElementType>::top() const
//{
//    if (!empty())
//        return myArray[myTop];
//    else
//    {
//        std::cerr << "*** Stack is empty -- returning garbage value ***\n";
//        return ElementType();
//    }
//}
//
//template <typename ElementType>
//void Stack2<ElementType>::display(std::ostream& out)
//{
//    for (auto value : myArray)
//    {
//        out << value << " ";
//    }
//    out << std::endl;
//}
