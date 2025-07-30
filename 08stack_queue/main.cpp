/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-30 11:47:13
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <time.h>
#include <stack>
#include <queue>
#include "rpn_calculator.hpp"
#include "stack.h"
#include "queue.h"
#include "Date.h"
void test_stack1()
{
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.empty())
	{
		std::cout << s.top() << "-";
		std::cout << s.size() << " ";
		s.pop();
	}
	std::cout << std::endl;
}

void test_queue1()
{
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		std::cout << q.front() << "-";
		std::cout << q.size() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

void test_priority_queue1()
{
	// priority_queue<int> pq;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(2);
	pq.push(5);
	pq.push(1);
	pq.push(6);
	pq.push(8);

	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

void test_stack2()
{
	// yzq::stack<int> s;
	yzq::stack<int, std::vector<int>> s;
	// yzq::stack<int, std::list<int>> s;
	// yzq::stack<int, std::string> s; // string内部是char 可能会发生数据截断
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(128); // 超过127就会截断 -128
	s.push(255); // -1
	s.push(256); // 0

	while (!s.empty())
	{
		std::cout << s.top() << "-";
		std::cout << s.size() << " ";
		s.pop();
	}
	std::cout << std::endl;
}

void testOP()
{
	srand(time(0));
	const int N = 10000000;
	std::vector<int> v;
	v.reserve(N);

	std::deque<int> dq1;
	std::deque<int> dq2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		v.push_back(e);
		dq1.push_back(e);
		dq2.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	sort(dq1.begin(), dq1.end());
	int end2 = clock();

	printf("vector Sort:%d\n", end1 - begin1);
	printf("deque Sort:%d\n", end2 - begin2);
}

void testOP2()
{
	srand(time(0));
	const int N = 10000000;
	std::vector<int> v;
	v.reserve(N);

	std::deque<int> dq1;
	std::deque<int> dq2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		v.push_back(e);
		dq1.push_back(e);
		dq2.push_back(e);
	}

	int begin1 = clock();
	sort(dq1.begin(), dq1.end());
	int end1 = clock();

	int begin2 = clock();
	// 拷贝给vector，排序后再拷贝回来，对比效率
	std::vector<int> copy(dq2.begin(), dq2.end());
	sort(copy.begin(), copy.end());
	dq2.assign(copy.begin(), copy.end());
	int end2 = clock();

	printf("deque Sort:%d\n", end1 - begin1);
	printf("deque copy to vecotr Sort:%d\n", end2 - begin2);
}

void test_queue2()
{
	yzq::queue<int> q;
	// queue<int, list<int>> q;
	// queue<int, vector<int>> q; // 不能用vector适配 没有pop_front
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		std::cout << q.front() << "-";
		std::cout << q.size() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

void test_priority_queue2()
{
	// std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	// std::priority_queue<int> pq; // 默认是less，大堆
	// yzq::priority_queue<int, std::vector<int>, yzq::less<int>> pq; // 默认大堆
	yzq::priority_queue<int, std::vector<int>, yzq::greater<int>> pq; // 小堆
	// yzq::priority_queue<int, std::vector<int>, bool (*)(int, int)> pq(yzq::ComIntGreater);
	pq.push(2);
	pq.push(5);
	pq.push(1);
	pq.push(6);
	pq.push(8);

	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

void test_priority_queue3()
{
	int a[] = {1, 3, 4, 2, 1, 6};
	// 借助优先级队列快速建堆，默认大堆
	// priority_queue<int> pq(a, a + 6);
	yzq::priority_queue<int, std::vector<int>, std::greater<int>> pq(a, a + 6);
	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

// 自定义比较函数（升序逻辑：返回true时a排在b前面）
bool ascending(int a, int b)
{
	return a < b;
}

// 自定义仿函数类（降序逻辑：返回true时a排在b前面）
class Descending
{
public:
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};

void test_sort_functors()
{
	std::vector<int> nums = {32, 71, 12, 45, 26, 80, 53, 33};

	// 原始数据输出
	std::cout << "原始数据: "; // 输出：32 71 12 45 26 80 53 33
	for (int num : nums)
		std::cout << num << " ";
	std::cout << std::endl;

	// 1. 使用普通函数升序排序
	std::sort(nums.begin(), nums.end(), ascending);
	std::cout << "使用普通函数升序排序后: "; // 输出：12 26 32 33 45 53 71 80
	for (int num : nums)
		std::cout << num << " ";
	std::cout << std::endl;

	// 2. 恢复原始数据
	nums = {32, 71, 12, 45, 26, 80, 53, 33};

	// 3. 使用标准库仿函数std::greater降序排序
	std::sort(nums.begin(), nums.end(), std::greater<int>()); // 匿名仿函数对象
	std::cout << "使用标准库仿函数降序排序后: ";			  // 输出：80 71 53 45 33 32 26 12
	for (int num : nums)
		std::cout << num << " ";
	std::cout << std::endl;

	// 4. 恢复原始数据
	nums = {32, 71, 12, 45, 26, 80, 53, 33};

	// 5. 使用自定义仿函数对象降序排序
	std::sort(nums.begin(), nums.end(), Descending());
	std::cout << "使用自定义仿函数对象降序排序后: "; // 输出：80 71 53 45 33 32 26 12
	for (int num : nums)
		std::cout << num << " ";
	std::cout << std::endl;
}

struct PDateCompare
{
	bool operator()(const yzq::Date *p1, const yzq::Date *p2) const
	{
		return *p1 < *p2;
	}
};

void test_Compare_Date()
{
	yzq::priority_queue<yzq::Date> pq1; // 等价于 yzq::priority_queue<yzq::Date, std::vector<yzq::Date>, std::less<yzq::Date>>
	// std::less<yzq::Date>会被实例化，并在内部调用yzq::Date的operator<进行元素比较。
	pq1.push(yzq::Date(2025, 1, 1));
	pq1.push(yzq::Date(2025, 1, 2));
	pq1.push(yzq::Date(2025, 1, 30));
	std::cout << pq1.top() << std::endl;

	// yzq::priority_queue<yzq::Date *, std::vector<yzq::Date *>, PDateCompare> pq2;
	yzq::priority_queue<yzq::Date *> pq2;
	pq2.push(new yzq::Date(2025, 1, 1));
	pq2.push(new yzq::Date(2025, 1, 2));
	pq2.push(new yzq::Date(2025, 1, 30));
	std::cout << *pq2.top() << std::endl;
}

void test_priority_queue4()
{
	std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
	yzq::priority_queue<int> pq1(v.begin(), v.end());

	// 验证堆顶元素是最大值
	assert(pq1.top() == 9);
	std::cout << "testBasicInt() passed!" << std::endl;

	yzq::priority_queue<int, std::vector<int>, yzq::greater<int>> pq2(v.begin(), v.end());

	// 验证堆顶元素是最小值
	assert(pq2.top() == 1);
	std::cout << "testCustomComparator() passed!" << std::endl;

	std::vector<yzq::Date> dates = {
		yzq::Date(2025, 1, 1),
		yzq::Date(2025, 1, 30),
		yzq::Date(2025, 1, 15)};

	yzq::priority_queue<yzq::Date> pq(dates.begin(), dates.end());

	// 验证堆顶元素是最大日期
	assert(pq.top().getYear() == 2025 && pq.top().getMonth() == 1 && pq.top().getDay() == 30);
	std::cout << "testDateClass() passed!" << std::endl;
}

int main(int argc, char const *argv[])
{
	test_Compare_Date();
	return 0;
}
