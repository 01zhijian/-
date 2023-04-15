#include "Base.h"

#include <iostream>
#include <string>

using namespace std;

int Split()
{
	//cout << sizeof(string) << endl;
	
	string str{ "xxxx:yyyy:zzzz:aaaa:bbb" };
	string strList[5];
	str += ':';		// ��չ�ַ����Է������

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
		cout << "������" << endl;
	}

	A(const A& other)
	{
		cout << "����������" << endl;
	}

	~A()
	{
		cout << "������" << endl;
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