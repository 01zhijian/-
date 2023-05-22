/* List.cpp 
    ����ļ��и����� List ��Ա������ʵ��
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
        
    // ���������ƶ�����Ԫ��Ϊ item �ڳ��ռ�
    for (int i = mySize; i > pos; --i)
    {
        myArray[i] = myArray[i - 1];
    }

    // ���ڽ� item ���뵽λ�� pos ���������б��С
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

    // �����ƶ�����Ԫ�����������
    for (int i = pos; i < mySize; ++i)
    {
        myArray[i] = myArray[i + 1];
    }

    // �ݼ��б��С
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
