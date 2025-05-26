/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-26 19:40:33
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

int main(int argc, char const *argv[])
{
	test_stack1();
	return 0;
}
