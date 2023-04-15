#pragma once
class MyString
{
public:
	MyString(const char* str = nullptr);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString operator+(const MyString& other);

	bool operator==(const MyString& other);
	bool operator>(const MyString& other);
	bool operator<(const MyString& other);
	char& operator[](int index);

	void dis();

	virtual ~MyString();

private:
	char* _str;
};

