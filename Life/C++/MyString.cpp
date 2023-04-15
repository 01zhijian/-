#include "MyString.h"
#include <string>
#include <iostream>

using namespace std;

MyString::MyString(const char* str)
{
	if (str == nullptr)
	{
		_str = new char[1];
		*_str = '\0';
	}
	else
	{
		size_t len = strlen(str);
		_str = new char[len + 1];
		strcpy(_str, str);
	}
}

MyString::MyString(const MyString& other)
{
	size_t len = strlen(other._str);
	_str = new char[len + 1];
	strcpy(_str, other._str);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other)
		return *this;
	
	delete[] _str;
	size_t len = strlen(other._str);
	_str = new char[len + 1];
	strcpy(_str, other._str);

	return *this;
}

MyString MyString::operator+(const MyString& other)
{
	size_t len = strlen(_str) + strlen(other._str);

	MyString str;
	delete[] str._str;

	str._str = new char[len + 1];
	memset(str._str, 0, len + 1);

	strcat(str._str, _str);
	strcat(str._str, other._str);

	return str;
}

bool MyString::operator==(const MyString& other)
{
	return strcmp(_str, other._str) == 0;
}

bool MyString::operator>(const MyString& other)
{
	return strcmp(_str, other._str) > 0;
}

bool MyString::operator<(const MyString& other)
{
	return strcmp(_str, other._str) < 0;
}

char& MyString::operator[](int index)
{
	return _str[index];
}

void MyString::dis()
{
	cout << _str << endl;
}

MyString::~MyString()
{
	delete[] _str;
}


int main_MyString()
{
	MyString str1;
	str1.dis();

	MyString str2("china2");
	str2.dis();

	MyString str3(str2);
	str3.dis();

	MyString str4;
	str4 = str3 = str2;
	str4.dis();

	str4 = "china3";
	str4.dis();

	return 0;
}