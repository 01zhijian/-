#include "Base.h"

#include <iostream>
#include <string>

using namespace std;

int Split()
{
	//cout << sizeof(string) << endl;
	
	string str{ "xxxx:yyyy:zzzz:aaaa:bbb" };
	string strList[5];
	str += ':';		// 扩展字符串以方便操作

	int i = 0;
	size_t prepos = -1;
	size_t pos = 0;

	while ((pos = str.find(':', pos + 1)) != string::npos)
	{
		strList[i++] = str.substr(prepos + 1, pos - prepos - 1);
		prepos = pos;
	}

	for (const string& str : strList)
	{
		cout << str << endl;
	}

	return 0;
}

class A
{
public:
	A()
	{
		cout << "构造器" << endl;
	}

	A(const A& other)
	{
		cout << "拷贝构造器" << endl;
	}

	~A()
	{
		cout << "析构器" << endl;
	}
};

//A foo(A& a) { return a; }
//A& foo()
//{
//	A b;
//	return b;
//}

//int main()
//{
//	A a;
//	A t = foo();
//
//	cout << "a address = " << &a << endl;
//	cout << "t address = " << &t << endl;
//
//	return 0;
//}