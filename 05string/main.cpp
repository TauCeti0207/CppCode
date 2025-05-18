/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-18 13:23:58
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <string>
#include <list>

void test1()
{
	std::string str = "abcdefg";
	for (auto c : str)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	std::cout << str << std::endl;

	// std::cin >> str;
	std::cout << str << std::endl;

	std::string str2 = str;
	str2 += str;
	std::cout << str2 << std::endl;

	std::cout << str + str2 << std::endl;
}

void test2()
{
	std::string str = "hello world";
	std::string::iterator it = str.begin();
	// while(it < str.end()) // 这里可以这么用但不建议，不通用，这只适合底层是连续物理空间的容器
	while (it != str.end())
	{
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	// 可读可写，修改迭代器指向的元素
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		*it += 1;
	}
	std::cout << str << std::endl;
}

void test3()
{
	std::string str = "hello";
	std::string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		std::cout << *rit << " "; // o l l e h
		++rit;
	}
	std::cout << std::endl;
}

void StringTest9(const std::string &rs)
{
	std::string::const_reverse_iterator rit = rs.rbegin();
	// 这种太长的类型，其实就可以用auto自动推导类型
	auto rit2 = rs.rbegin();
	while (rit != rs.rend())
	{
		// (*rit) += 1; // err 不能修改常量迭代器指向的元素
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
}

void test4()
{
	std::string s1 = "hello world";
	StringTest9(s1);
}

void printVec(const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printList(const std::list<int> &lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test5()
{
	std::vector<int> vec = {1, 2, 3};
	std::list<int> lst = {4, 5, 6};
	printVec(vec);
	printList(lst);
}

int main()
{
	test5();
	return 0;
}