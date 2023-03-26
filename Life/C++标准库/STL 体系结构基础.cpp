#include "STL 体系结构基础.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main1()
{
	int iArr[6] = { 27, 210, 12, 47, 109, 83 };
	std::vector<int, std::allocator<int>> vArr(iArr, iArr + 6);

	for (auto elem : vArr)
	{
		std::cout << elem << " ";
	}
	std::cout << '\n';

	std::cout << std::count_if(vArr.begin(), vArr.end(),
		std::not1(std::bind2nd(std::less<int>(), 40)));

	std::cout << '\n';

	auto iter = std::find(vArr.begin(), vArr.end(), 27);
	if (iter != vArr.end())
	{
		std::cout << "元素被找到了：" << *iter << '\n';
	}


	return 0;
}