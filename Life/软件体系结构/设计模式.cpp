#include "设计模式.h"

#include <iostream>

using namespace std;

int main()
{
	try
	{
		throw -1;
	}
	catch (int x)
	{
		cerr << "We caught an int exception with value: " << x << endl;
	}

	return 0;
}