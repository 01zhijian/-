// C++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "异常.h"
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class ArrayException : public exception
{
public:
    ArrayException(string_view error)
        : m_error{error}
    {

    }

    const char* what() const noexcept override
    {
        return m_error.c_str();
    }

private:
    string m_error{};
};

class IntArray
{
public:
    IntArray(){}

    int getLength() const { return 3; }

    int& operator[](const int index)
    {
        if (index < 0 || index >= getLength())
            throw ArrayException("Invalid index");

        return m_data[index];
    }

private:
    int m_data[3]{};
};

int main_C()
{
    cout << "Enter to number: ";
    double x{};
    cin >> x;

	try
	{
		double d = mySqrt(x);
		cout << "The sqrt of " << x << " is " << d << '\n';
	}
	catch (const char* e)
	{
		cerr << "Error: " << e << endl;
	}


    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    IntArray array;

    try
    {
        int value{ array[5] };
    }
    catch (const ArrayException& e)
    {
        cerr << "An array exception occurred ( " << e.what() << ")\n";
    }
    catch (const exception& e)
    {
        cerr << "Some other exception occurred ( " << e.what() << endl;
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
