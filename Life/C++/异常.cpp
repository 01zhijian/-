#include "�쳣.h"

#include <cmath>
#include <exception>

void test_exception()
{
	throw - 1;
}

double mySqrt(double x)
{
	// ����û�������һ��С��������֣���ʱһ�ִ�������
	if (x < 0.0)
		throw "Can not take sqrt of negative number";

	return std::sqrt(x);
}