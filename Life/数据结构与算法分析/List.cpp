/* List.cpp 
    这个文件中给出了 List 成员函数的实现
*/
#include "List.h"

List::List()
    : mySize{0}
{
}

bool List::empty() const
{
    return mySize == 0;
}

void List::insert(ElementType item, int pos)
{
    if (mySize == CAPACITY)
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

void List::erase(int pos)
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

void List::display(std::ostream& out) const
{
    for (int i = 0; i < mySize; ++i)
    {
        out << myArray[i] << " ";
    }
}

std::ostream& operator<<(std::ostream& out, const List& aList)
{
    aList.display(out);
    return out;
}
