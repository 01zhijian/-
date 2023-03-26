#include "�����ķ��������.h"
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdlib> // qsort��bsearch��NULL
#include <iostream>

using namespace std;

constexpr int SIZE = 100000;

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}

void test_array()
{
	std::cout << "test_array()......\n";

	std::array<long, SIZE> c;
	clock_t tStart = std::clock();	// clock �ǳ������п�ʼ�����ڵ�ʱ�䣬��λ����

	for (long i = 0; i < SIZE; ++i)
	{
		// ��ֵһ�������
		c[i] = std::rand();
	}

	 //���� array ���ú���
	std::cout << "init milli = " << (std::clock() - tStart) << '\n';
	std::cout << "size = " << c.size() << '\n';
	std::cout << "front = " << c.front() << '\n';
	std::cout << "back = " << c.back() << '\n';
	std::cout << "data = " << c.data() << '\n';

	// ������ɲ���Ŀ��
	long target = std::rand();

	// ����
	tStart = std::clock();
	qsort(c.data(), SIZE, sizeof(long), compareLongs);
	std::cout << "qsort = " << std::clock() - tStart << '\n';

	// ���ң����ֲ��ң�
	tStart = clock();
	long* pItem = (long*)std::bsearch(&target, c.data(), SIZE, sizeof(long), compareLongs);
	std::cout << "bsearch = " << std::clock() - tStart << '\n';
	if (pItem != nullptr)
		std::cout << "target = " << *pItem << std::endl;
	else
		std::cout << target << " = not found!" << std::endl;
}

void test_vector()
{
	cout << "\ntest_vector()...................\n";

	vector<int> v;
	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		v.push_back(rand());
	}

	// ������Ϣ
	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << v.size() << endl;
	cout << "max_size = " << v.max_size() << endl;
	cout << "front = " << v.front() << endl;
	cout << "back = " << v.back() << endl;
	cout << "data = " << v.data() << endl;
	cout << "capacity = " << v.capacity() << endl;
	
	int target = rand();

	// ����
	tStart = clock();

	auto iter = ::find(v.begin(), v.end(), target);	// ˳�����
	cout << "::find, milli = " << clock() - tStart << endl;

	if (iter != v.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;

	// ����
	tStart = clock();
	sort(v.begin(), v.end());
	cout << "sort milli = " << clock() - tStart << endl;
}

void test_list()
{
	cout << "\ntest_list................\n";

	list<int> c;
	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.push_back(rand());
	}
	
	// ������Ϣ
	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;
	cout << "front = " << c.front() << endl;
	cout << "back = " << c.back() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = std::find(c.begin(), c.end(), target);
	cout << "find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;

	// ����
	tStart = clock();
	c.sort();
	cout << "�ֲ� sort milli = " << clock() - tStart << endl;
}

// �����б�
void test_forward_list()
{
	cout << "\ntest_forward_list................\n";

	forward_list<int> c;
	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.push_front(rand());
	}

	// ������Ϣ
	cout << "init milli = " << clock() - tStart << endl;
	//cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;
	cout << "front = " << c.front() << endl;
	//cout << "back = " << c.back() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = std::find(c.begin(), c.end(), target);
	cout << "find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;

	// ����
	tStart = clock();
	c.sort();
	cout << "�ֲ� sort milli = " << clock() - tStart << endl;
}

void test_deque()
{
	cout << "\ntest_deque................\n";

	deque<int> c;
	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.push_back(rand());
	}

	// ������Ϣ
	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;
	cout << "front = " << c.front() << endl;
	cout << "back = " << c.back() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = std::find(c.begin(), c.end(), target);
	cout << "find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;

	// ����
	tStart = clock();
	sort(c.begin(), c.end());
	cout << "sort milli = " << clock() - tStart << endl;
}

void test_stack()
{
	// stack �ǻ��� deque ����������
	cout << "\ntest_deque................\n";

	stack<int> c;
	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.push(rand());
	}

	// ������Ϣ
	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "top = " << c.top() << endl;
	c.pop();
	cout << "size = " << c.size() << endl;
	cout << "top = " << c.top() << endl;
	//cout << "max_size = " << c.max_size() << endl;
	//cout << "front = " << c.front() << endl;
	//cout << "back = " << c.back() << endl;
}

void test_queue()
{
	// queue �ǻ��� deque ����������
	cout << "\ntest_deque................\n";

	queue<int> c;
	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.push(rand());
	}

	// ������Ϣ
	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	//cout << "max_size = " << c.max_size() << endl;
	cout << "front = " << c.front() << endl;
	cout << "back = " << c.back() << endl;
	c.pop();
	cout << "size = " << c.size() << endl;
	//cout << "max_size = " << c.max_size() << endl;
	cout << "front = " << c.front() << endl;
	cout << "back = " << c.back() << endl;
}

void test_multiset()
{
	cout << "\ntest_multiset....................\n";
	multiset<int> c;

	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.insert(rand());
	}

	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = std::find(c.begin(), c.end(), target);
	cout << "std::find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;

	tStart = clock();
	iter = c.find(target);
	cout << "c.find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;
}

void test_multimap()
{
	cout << "\ntest_multimap....................\n";
	multimap<int, int> c;

	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.insert(pair<int, int>(i, rand()));
	}

	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = c.find(target);
	cout << "c.find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "first = " << iter->first << " second = " << iter->second << endl;
	else
		cout << target << " not found" << endl;
}

void test_set()
{
	cout << "\ntest_set....................\n";
	set<int> c;

	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		c.insert(rand());
	}

	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = std::find(c.begin(), c.end(), target);
	cout << "std::find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;

	tStart = clock();
	iter = c.find(target);
	cout << "c.find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "found = " << *iter << endl;
	else
		cout << target << " not found" << endl;
}

void test_map()
{
	cout << "\ntest_map....................\n";
	map<int, int> c;

	clock_t tStart = clock();
	for (int i = 0; i < SIZE; ++i)
	{
		//c.insert(pair<int, int>(i, rand()));
		c[i] = rand();
	}

	cout << "init milli = " << clock() - tStart << endl;
	cout << "size = " << c.size() << endl;
	cout << "max_size = " << c.max_size() << endl;

	// ����
	int target = rand();
	tStart = clock();
	auto iter = c.find(target);
	cout << "c.find milli = " << clock() - tStart << endl;

	if (iter != c.end())
		cout << "first = " << iter->first << " second = " << iter->second << endl;
	else
		cout << target << " not found" << endl;
}

int main4()
{
	// �������������
	std::srand(unsigned int(std::time(nullptr)));

	//test_array();
	//test_vector();
	//test_list();
	//test_forward_list();
	//test_deque();
	//test_stack();
	//test_queue();
	//test_multiset();
	//test_multimap();
	//test_set();
	test_map();
	return 0;
}