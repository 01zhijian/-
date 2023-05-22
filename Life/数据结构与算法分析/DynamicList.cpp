#include "DynamicList.h"
#include <cassert>

/* DynamciList.cpp 
    ����ļ����� List ��Ա������ʵ��
*/

DynamicList::DynamicList(int maxSize)
    : mySize(0), myCapacity(maxSize)
{
    myArray = new (std::nothrow) ElementType[maxSize];
    assert(myArray != nullptr);
}

DynamicList::~DynamicList()
{
    delete[] myArray;
}

DynamicList::DynamicList(const DynamicList& origList)
    : mySize(origList.mySize), myCapacity(origList.myCapacity)
{
    // Ϊ���ƻ�ȡ������
    myArray = new (std::nothrow) ElementType[myCapacity];
    if (myArray != nullptr) // ����Ƿ��п����ڴ�
    {
        // �� origList ��Ԫ�ظ��Ƶ������������
        for (int i = 0; i < mySize; ++i)
        {
            myArray[i] = origList.myArray[i];
        }
    }
    else
    {
        std::cerr << "*** Inadequate memory to allocate storage for list ***\n";
        exit(1);
    }
}

const DynamicList& DynamicList::operator=(const DynamicList& rightHandSide)
{
    if (this == &rightHandSide) // ȷ�ϲ������Ҹ���
        return *this;

    // �����Ҫ������һ��������
    if (myCapacity != rightHandSide.myCapacity)
    {
        delete[] myArray;
        myCapacity = rightHandSide.myCapacity;
        myArray = new (std::nothrow) ElementType[myCapacity];

        if (myArray == nullptr) // ����Ƿ��п����ڴ�
        {
            std::cerr << "*** Inadequate memory to allocate storage for list ***\n";
            exit(1);
        }
    }

    // �� rightHandSide ���б�Ԫ�ظ��Ƶ������������
    mySize = rightHandSide.mySize;
    for (int i = 0; i < mySize; ++i)
    {
        myArray[i] = rightHandSide.myArray[i];
    }

    return *this;
}

bool DynamicList::empty() const
{
    return mySize == 0;
}

void DynamicList::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)
    {
        std::cerr << "*** No space for list element -- terminating execution ***\n";
        exit(1);
    }

    if (pos < 0 || pos > mySize)
    {
        std::cerr << "*** Illegal location to insert -- " << pos << ". List unchanged. ***\n";
        return;
    }

    // ���������ƶ�����Ԫ��Ϊ item �ڳ��ռ�
    for (int i = mySize; i > pos; --i)
    {
        myArray[i] = myArray[i - 1];
    }

    // ���ڽ� item ���뵽λ�� pos ���������б��С
    myArray[pos] = item;
    mySize++;
}

void DynamicList::erase(int pos)
{
    if (mySize == 0)
    {
        std::cerr << "*** List is empty ***\n";
        return;
    }

    if (pos < 0 || pos >= mySize)
    {
        std::cerr << "Illegal location to delete -- " << pos << ". List unchanged. ***\n";
        return;
    }

    // �����ƶ�����Ԫ�����������
    for (int i = pos; i < mySize; ++i)
    {
        myArray[i] = myArray[i + 1];
    }

    // �ݼ��б��С
    mySize--;
}

void DynamicList::display(std::ostream& out) const
{
    for (int i = 0; i < mySize; ++i)
    {
        out << myArray[i] << " ";
    }
}

std::ostream& operator<<(std::ostream& out, const DynamicList& aList)
{
    aList.display(out);
    return out;
}
