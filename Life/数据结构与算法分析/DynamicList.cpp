#include "DynamicList.h"
#include <cassert>

/* DynamciList.cpp 
    这个文件包含 List 成员函数的实现
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
    // 为复制获取新数组
    myArray = new (std::nothrow) ElementType[myCapacity];
    if (myArray != nullptr) // 检查是否有可用内存
    {
        // 将 origList 的元素复制到这个新数组中
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
    if (this == &rightHandSide) // 确认不是自我复制
        return *this;

    // 如果需要，分配一个新数组
    if (myCapacity != rightHandSide.myCapacity)
    {
        delete[] myArray;
        myCapacity = rightHandSide.myCapacity;
        myArray = new (std::nothrow) ElementType[myCapacity];

        if (myArray == nullptr) // 检查是否有可用内存
        {
            std::cerr << "*** Inadequate memory to allocate storage for list ***\n";
            exit(1);
        }
    }

    // 将 rightHandSide 的列表元素复制到这个新数组中
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

    // 首先向右移动数组元素为 item 腾出空间
    for (int i = mySize; i > pos; --i)
    {
        myArray[i] = myArray[i - 1];
    }

    // 现在将 item 插入到位置 pos 处并递增列表大小
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

    // 向左移动数组元素以消除间隔
    for (int i = pos; i < mySize; ++i)
    {
        myArray[i] = myArray[i + 1];
    }

    // 递减列表大小
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
