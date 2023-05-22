#include "软件开发.h"

void BinarySearch(int arr[], int n, int item, bool& found, int& mid)
{
    int first = 0;
    int last = n - 1;

    found = false;
    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (item < arr[mid])
            last = mid - 1;
        else if (item > arr[mid])
            first = mid + 1;
        else
            found = true;
    }
}

void recBinarySearch(int a[], int first, int last, int item, bool& found, int& loc)
{
    if (first > last)
    {
        found = false;
    }
    else
    {
        loc = (first + last) / 2;
        if (item < a[loc])
            recBinarySearch(a, first, loc - 1, item, found, loc);
        else if (item > a[loc])
            recBinarySearch(a, loc + 1, last, item, found, loc);
        else
            found = true;
    }
}

#include <cmath>

bool HuiWenNumber(int number, int numDigits)
{
    if (numDigits <= 1)
        return true;
    else
    {
        int firstDigit = number / std::pow(10, numDigits - 1);
        int lastDigit = number % 10;
        if (firstDigit == lastDigit)    // 删除第一个与最后一个数字
            return HuiWenNumber((number % (int)std::pow(10, numDigits - 1)) / 10, numDigits - 1);
        else
            return false;
    }
}
