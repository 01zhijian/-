#include "异常.h"

#include <cmath>
#include <exception>

void test_exception()
{
	throw - 1;
}

double mySqrt(double x)
{
	// 如果用户输入了一个小于零的数字，这时一种错误的情况
	if (x < 0.0)
		throw "Can not take sqrt of negative number";

	return std::sqrt(x);
}