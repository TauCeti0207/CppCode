/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-06-03 12:40:45
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <array>
#include "Date.h"

// 函数模板
template <class T> // Type
void Swap(T &x1, T &x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
void test1()
{
	int a = 10, b = 20;
	double c = 1.2, d = 3.4;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	Swap(a, b); // 编译器通过实参推形参，这种是隐式实例化
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "c = " << c << ", d = " << d << std::endl;
	Swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	// Swap(a, c); //这样是不可以的，类型不匹配
}

// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}

// 通用加法函数
template <class T>
T Add(const T &x1, const T &x2)
{
	return x1 + x2;
}
void test2()
{
	int a = 10, b = 20;
	double c = 1.2, d = 3.4;
	Add(a, b);
	Add(c, d);

	// std::cout << Add(a, c) << std::endl; // err 模板中只有一个T，但是我们传了两个类型，编译器根据模板将不知道T应该是啥类型
	//  不让编译器推演类型，显示指定类型
	//  显示实例化
	std::cout << Add<int>(a, c) << std::endl; // 11
	// c是double，隐式类型转换成int传过去
	std::cout << Add<double>(a, c) << std::endl; // 11.2
}

void test3()
{
	std::cout << Add(1, 2) << std::endl;	  // 与非模板函数匹配，调用普通函数
	std::cout << Add<int>(1, 2) << std::endl; // 显示调用模板的Add
}

// 模板调用，有现成匹配函数，绝对不去实例化模板
// 有更匹配的，优先匹配类型最合适的
void test5()
{
	Add(1, 2);	 // 与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
}

template <class T>
T *func(int n)
{
	return new T[n];
}
void test7()
{
	// int *p = func(10); // err 函数模板没法推导
	int *p1 = func<int>(10);
	double *p2 = func<double>(10);
}

namespace yzq
{
	template <class T>
	class vector
	{
	public:
		vector()
			: _a(nullptr), _size(0), _capacity(0)
		{
		}
		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}
		void push_back(const T &x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T *tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}
			_a[_size] = x;
			++_size;
		}
		T &operator[](size_t pos) // 传引用返回可以修改值也能减少拷贝
		{
			assert(pos < _size); // 越界检查
			return _a[pos];
		}

		size_t size()
		{
			return _size;
		}

	private:
		T *_a;
		int _size;
		int _capacity;
	};

}
void test8()
{
	yzq::vector<int> v1; // int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i] *= 2;
	}

	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	// 等价 v1.operator[](3);
	std::cout << v1[3] << std::endl;
	std::vector<double> v2; // double
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(2.2);
	v2.push_back(2.2);
}

void test9()
{
	std::vector<int> v1;
	v1.push_back(1);
}

// 静态栈
// 利用非类型模板参数
// N是常量，也意味着不可以修改
template <class T, size_t N = 100> // 也是可以给定缺省参数的
class Stack
{
public:
	void f()
	{
		// N = 20; // err 不允许修改
	}
	// 默认构造函数（值初始化）
	Stack()
		: _top(0)
	{
		for (size_t i = 0; i < N; i++)
		{
			_a[i] = T();
		}
	}

	// 带初始值的构造函数
	Stack(const T &initial_value)
		: _top(N)
	{
		for (size_t i = 0; i < N; ++i)
		{
			_a[i] = initial_value;
		}
	}
	size_t size() const
	{
		return _top;
	}
	size_t capacity() const
	{
		return N;
	}

private:
	T _a[N];
	size_t _top;
};

void test10()
{
	Stack<int, 50> st1(10); // 存50个
	st1.f();
	Stack<double, 500> st2; // 存500个
	std::cout << st1.capacity() << std::endl;
	std::cout << st2.capacity() << std::endl;
}

void test_template3()
{
	// v1数据存在堆上的
	std::vector<int> v1(100, 0);
	v1[0] = 0;
	v1[1] = 1;
	// ...
	v1[99] = 99;
	std::cout << sizeof(v1) << std::endl; // 16  32位平台下 4个指针

	// 数据存在栈上，没有初始化的话都是随机数据
	// array是C++11新增的 -- 其实就是封装过的原生数组
	// 对比原生数组的优势：operator[] 能严格检查越界
	// 越界读越界写都能检查到
	std::array<int, 100> a1;
	a1[0] = 0;
	a1[1] = 1;
	// ...
	a1[99] = 99;
	std::cout << sizeof(a1) << std::endl; // 400byte
	// a1[200] = 1;
	// cout << a1[200] << endl;

	int a2[100]; // 原生数组 针对越界是抽查，有时检查不到
				 // a2[110] = 1; //可能检查不到越界
}

template <class T>
bool Less(T left, T right)
{
	std::cout << "Less(T left, T right)" << std::endl;
	return left < right;
}

// 模板特化，针对某些特殊类型特殊化处理
template <>
bool Less<yzq::Date *>(yzq::Date *left, yzq::Date *right)
{
	std::cout << "Less<yzq::Date *>(yzq::Date *left, yzq::Date *right)" << std::endl;
	return *left < *right;
}

// 直接给出函数
bool Less(yzq::Date *left, yzq::Date *right)
{
	std::cout << "Less(yzq::Date *left, yzq::Date *right)" << std::endl;
	return *left < *right;
}

// 为了针对int* int*
template <class T>
bool Less(T *left, T *right)
{
	std::cout << "Less(T *left, T *right)" << std::endl;
	return *left < *right;
}
// 这几个可以同时存在

void test_template5()
{
	std::cout << Less(1, 2) << std::endl; // 1 结果正确  调用原生的

	yzq::Date d1(2022, 8, 11);
	yzq::Date d2(2022, 8, 12);
	std::cout << Less(d1, d2) << std::endl; // 1 结果正确 调用原生的

	yzq::Date *p1 = new yzq::Date(2022, 8, 10);
	yzq::Date *p2 = new yzq::Date(2022, 8, 11);
	std::cout << Less(p1, p2) << std::endl;	  // 模板特化之后，结果就是正确的 调用Date*特化的
	std::cout << Less(*p1, *p2) << std::endl; // 正确 调用原生的

	int *p3 = new int(1);
	int *p4 = new int(2);
	std::cout << Less(p3, p4) << std::endl; // 正确 调用T*特化的
}

int main()
{
	test_template5();
	return 0;
}