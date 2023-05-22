//#include "Stack2.h"
//
///* Stack2.cpp
//����ļ����� Stack ��Ա������ʵ��
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
//    if (myTop < STACK_CAPACITY - 1)     // ����ջ����ʽ
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
//        /* ------------------------------ ѧϰ�ʼ� ------------------------------ *
//        �ڴ������������ʱ���ж��ַ�����
//        ����ʾһ��������Ϣ����ִֹ��
//        ����ʾһ��������Ϣ����������ִ�м�����ȥ
//        ���׳�һ���쳣
//        ������һ������ֵ����ʾ�����ǳɹ���true������ʧ�ܣ�false����
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
