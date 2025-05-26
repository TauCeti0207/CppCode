/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-26 17:45:02
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
#include "list.h"

void test_list1()
{
	yzq::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	yzq::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// 范围 for
	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

struct AA
{
	AA(int a1 = 0, int a2 = 0)
		: _a1(a1), _a2(a2)
	{
	}
	int _a1;
	int _a2;
};

void test_list2()
{
	std::list<AA> lt;
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));
	lt.push_back(AA(4, 4));

	std::list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		// err *it返回的是节点的data，data是val，val是T()
		// 也就是这里返回的是AA 自定义类型不支持流操作的
		// cout << *it << " ";

		// 如果我们不想自己去写流操作的重载
		// 因为_a1 _a2都是公有的
		// std::cout << (*it)._a1 << "-" << (*it)._a2 << " ";
		std::cout << it->_a1 << "-" << it->_a2 << " ";
		// 其实本质是operator->()返回的是对象的指针
		// 但是这样写可读性不好，编译器特殊处理，省略了一个->
		std::cout << it.operator->()->_a1 << "-" << it.operator->()->_a2 << " ";
		++it;
	}
	std::cout << std::endl;
}

// template <class T>
template <typename T>
void print_list(const yzq::list<T> &l)
{
	// ✅ 声明 typename，明确yzq::list<T>::const_iterator 是一个类型
	// 没有指定 typename的时候，yzq::list<T>是未实例化的类模板，编译器无法确定const_iterator是内嵌类型是还是静态成员变量等等
	typename yzq::list<T>::const_iterator cit = l.begin();
	while (cit != l.end())
	{
		// *cit = 1; // const对象不允许修改，调用的也是const版本迭代器
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;
}

template <typename Container>
void print_container(const Container &con)
{
	typename Container::const_iterator cit = con.begin();
	while (cit != con.end())
	{
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;
}

void test_list3()
{
	yzq::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	yzq::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		*it += 1;
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	print_list(lt);

	yzq::list<std::string> lt2;
	lt2.push_back("hello");
	lt2.push_back("world");
	print_list(lt2);
}

void test_list4()
{
	yzq::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	print_container(lt);

	yzq::list<std::string> lt2;
	lt2.push_back("list<string> hello");
	lt2.push_back("world");

	print_container(lt2);

	std::vector<std::string> v;
	v.push_back("Vector<string> hello");
	v.push_back("world");
	print_container(v);
}

void test_list5()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	// 要求在偶数前面插入这个数*10
	auto it1 = lt.begin();
	while (it1 != lt.end())
	{
		if (*it1 % 2 == 0)
		{
			lt.insert(it1, *it1 * 10);
		}
		++it1;
	}

	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_list6()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	// 删除所有的偶数
	auto it1 = lt.begin();
	while (it1 != lt.end())
	{
		if (*it1 % 2 == 0)
		{
			it1 = lt.erase(it1);
		}
		else
		{
			++it1;
		}
	}

	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	lt.clear();

	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_list7()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	std::list<int> lt1(lt); // 我们不写，默认生成的完成浅拷贝，指向同一个头，析构时会析构2次，崩溃。

	for (auto e : lt1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::list<int> lt2;
	lt2.push_back(10);
	lt2.push_back(20);

	lt1 = lt2;

	for (auto e : lt2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	for (auto e : lt1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_list8()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	// 正向迭代器
	std::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		*it += 1;
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// 反向迭代器
	std::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		*rit -= 1;
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	// 范围for
	for (auto &e : lt)
	{
		e += 1;
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_list9()
{
	srand(time(0));
	const int N = 1000000;
	std::vector<int> v;
	v.reserve(N);

	std::list<int> lt;

	for (int i = 0; i < N; ++i)
	{
		v.push_back(rand());
		lt.push_back(v[i]);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	// sort(lt.begin(), lt.end()); // err 算法中的sort不支持list
	lt.sort();
	int end2 = clock();

	printf("vector Sort:%d\n", end1 - begin1);
	printf("list Sort:%d\n", end2 - begin2);
}

void test_list10()
{
	srand(time(0));
	const int N = 1000000;
	std::vector<int> v;
	v.reserve(N);

	std::list<int> lt1;
	std::list<int> lt2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt1.push_back(e);
		lt2.push_back(e);
	}

	// 拷贝到vector排序，排完以后再拷贝回来
	int begin1 = clock();
	for (auto e : lt1)
	{
		v.push_back(e);
	}
	sort(v.begin(), v.end());
	size_t i = 0;
	lt1.assign(v.begin(), v.end());
	int end1 = clock();

	// 链表2单独排序，对比效率
	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	printf("vector Sort:%d\n", end1 - begin1);
	printf("list Sort:%d\n", end2 - begin2);
}

#include <iostream>
#include <list>
using namespace std;

void test_list11()
{
	std::list<int> lt1(4, 2);
	std::list<int> lt2(4, 6);
	lt1.splice(lt1.begin(), lt2); // 将容器lt2拼接到容器lt1的开头 lt2 变成 empty 了
	for (auto e : lt1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 6 6 6 6 2 2 2 2
	for (auto e : lt2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // empty

	std::list<int> lt3(4, 2);
	std::list<int> lt4(4, 6);
	lt3.splice(lt3.begin(), lt4, lt4.begin()); // 将容器lt4的第一个数据拼接到容器lt3的开头
	for (auto e : lt3)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 6 2 2 2 2

	for (auto e : lt4)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 6 6 6

	std::list<int> lt5(4, 2);
	std::list<int> lt6(4, 6);
	lt5.splice(lt5.begin(), lt6, lt6.begin(), lt6.end()); // 将容器lt6的指定迭代器区间内的数据拼接到容器lt5的开头
	for (auto e : lt5)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 6 6 6 6 2 2 2 2

	for (auto e : lt6)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // empty
}

void test_list12()
{
	std::list<int> lt;
	lt.push_back(1);
	lt.push_back(4);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl; // 1 4 3 3 2 2 3
	lt.remove(3); // 删除容器当中值为3的元素
	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl; // 1 4 2 2
}

// a predicate implemented as a function:
bool single_digit(const int &value) { return (value < 10); }

// a predicate implemented as a class:
struct is_odd
{
	bool operator()(const int &value) { return (value % 2) == 1; }
};

void test_list13()
{
	int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
	std::list<int> mylist(myints, myints + 8); // 15 36 7 17 20 39 4 1

	mylist.remove_if(single_digit); // 15 36 17 20 39

	std::cout << "mylist contains:";
	for (auto e : mylist)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	mylist.remove_if(is_odd()); // 36 20

	std::cout << "mylist contains:";
	for (auto e : mylist)
	{
		std::cout << ' ' << e;
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	test_list4();
	return 0;
}
