/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-15 00:11:22
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>

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
int main()
{
	test8();
	return 0;
}