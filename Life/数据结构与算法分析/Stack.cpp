#include "Stack.h"

/* Stack.cpp
����ļ����� Stack ��Ա������ʵ��
*/

Stack::Stack()
    : myTop(-1)
{
}

bool Stack::empty() const
{
    return myTop == -1;
}

void Stack::push(const ElementType& value)
{
    if (myTop < STACK_CAPACITY - 1)     // ����ջ����ʽ
    {
        ++myTop;
        myArray[myTop] = value;
    }
    else
    {
        std::cerr << "*** Stack full -- can't add new value ***\n"
            "Must increase value of STACK_CAPACITY in Stack.h\n";
        exit(1);

        /* ------------------------------ ѧϰ�ʼ� ------------------------------ *
        �ڴ������������ʱ���ж��ַ�����
        ����ʾһ��������Ϣ����ִֹ��
        ����ʾһ��������Ϣ����������ִ�м�����ȥ
        ���׳�һ���쳣
        ������һ������ֵ����ʾ�����ǳɹ���true������ʧ�ܣ�false����
        */
    }
}

void Stack::pop()
{
    if (!empty())
        --myTop;
    else
        std::cerr << "*** Stack is empty -- can't remove a value ***\n";
}

ElementType Stack::top() const
{
    if (!empty())
        return myArray[myTop];
    else
    {
        std::cerr << "*** Stack is empty -- returning garbage value ***\n";
        return ElementType();
    }
}

void Stack::display(std::ostream& out)
{
    for (auto value : myArray)
    {
        out << value << " ";
    }
    out << std::endl;
}
