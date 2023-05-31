#include "Comment.h"

Comment::Comment()
    : m_key(0), m_value(0)
{
}

Comment::~Comment()
{
}

int Comment::BinarySearch(int* arr, int minSub, int maxSub, int num)
{
    if (minSub > maxSub)
    {
        return -1;
    }

    int mid = (minSub + maxSub) / 2;
    if (arr[mid] == num)
    {
        return mid;
    }
    else if (arr[mid] < num)
    {
        minSub = mid + 1;
    }
    else
    {
        maxSub = mid - 1;
    }

    return BinarySearch(arr, minSub, maxSub, num);
}
