#include <iostream>
#include "软件开发.h"
#include "List.h"
#include "Stack2.h"

using namespace std;

int main()
{
    //cout << "Hello World" << endl;

    Stack2<int, 128> intStack;

    int arr[] = { 45, 64, 68, 77, 84, 90, 96 };
    bool found = false;
    int mid = 0;

    BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 96, found, mid);

    //cout << mid << endl;

    // --- 测试 List 类的程序
    List intList;
    cout << "Constructing intList\n";

    // 测试 empty 并输出空列表
    if (intList.empty())
    {
        cout << "Empty List: \n"
            << intList << endl;
    }

    // 测试 insert
    for (int i = 0; i < 9; ++i)
    {
        cout << "Inserting " << i << " at position " << i / 2 << endl;
        intList.insert(i, i / 2);

        // 测试输出
        cout << intList << endl;
    }

    cout << "List empty? " << (intList.empty() ? "Yse" : "No") << endl;

    cout << "\nTry to insert at position -1" << endl;
    intList.insert(0, -1);
    cout << "\nTry to insert at position 10" << endl;
    intList.insert(0, 10);

    // 测试 erase
    int index = 0;
    cout << endl;

    while (!intList.empty())
    {
        cout << "Give an index of a list element to remove: ";
        cin >> index;
        intList.erase(index);
        cout << intList << endl;
    }

    cout << "\nInserting " << CAPACITY << " integers\n";
    for (int i = 0; i < CAPACITY; ++i)
    {
        intList.insert(i, i);
    }
    cout << "Attempting to insert one more integer:\n";
    intList.insert(-1, 0);

    return 0;
}