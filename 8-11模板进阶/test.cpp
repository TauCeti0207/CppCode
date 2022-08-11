#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include "Date.h"
#include <algorithm>
using namespace std;

template<class T>
void print_list(const list<T>& lt)
{
	// 这是一个虚拟类型 类模板没有实例化的之前，不能去取list<T>里面的内嵌类型
	// 在前面加上typename关键字，告诉编译器后面的list<T>::const_iterator是一个类型
	// 等类模板实例化完成之后再去取
	// 这里是list确定了，但list模板参数还没确定
	//typename list<T>::const_iterator cit = lt.begin();
	auto cit = lt.begin();
	while (cit != lt.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

//void print_list(const list<int>& lt)
//{
//	typename list<int>::const_iterator cit = lt.begin();
//	while (cit != lt.end())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//}

template<class Container>
void print_container(const Container& con)
{
	// 这也是一个虚拟类型，整体都没有确定
	// typename 只是告诉编译器后面一串东西是类型 等实例化完成之后再去找
	typename Container::const_iterator cit = con.begin();
	//auto cit = con.begin();
	while (cit != con.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

void test_template1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	print_list(lt);
	print_container(lt);

	list<string> ltstr;
	ltstr.push_back("aaa");
	ltstr.push_back("bbb");
	ltstr.push_back("ccc");
	ltstr.push_back("ddd");
	//print_list(ltstr);
	print_container(ltstr);
}


// 静态栈
// 利用非类型模板参数
// N是常量，也意味着不可以修改
template<class T, size_t N = 100> // 也是可以给定缺省参数的 
class Stack
{
public:
	void f()
	{
		//N = 20; // err 不允许修改
	}
private:
	T _a[N];
	int _top;
};

void test_template2()
{
	Stack<int, 50> st1; // 存50个
	st1.f();
	Stack<double, 500> st2; // 存500个
}

void test_template3()
{
	// v1数据存在堆上的
	vector<int> v1(100, 0);
	v1[0] = 0;
	v1[1] = 1;
	// ...
	v1[99] = 99;
	cout << sizeof(v1) << endl; // 16  32位平台下


	// 数据存在栈上，没有初始化的话都是随机数据
	// array是C++11新增的 -- 其实就是封装过的原生数组
	// 对比原生数组的优势：operator[] 能严格检查越界
	// 越界读越界写都能检查到
	array<int, 100> a1;
	a1[0] = 0;
	a1[1] = 1;
	// ...
	a1[99] = 99;
	cout << sizeof(a1) << endl; // 400byte
	//a1[200] = 1;
	//cout << a1[200] << endl;

	int a2[100]; // 原生数组 针对越界是抽查，有时检查不到
	//a2[200] = 1;
	//a2[200];
}

//template <class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}

//// 模板特化，针对某些特殊类型特殊化处理
//template <>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//// 为了针对int* int*
//template <class T>
//bool Less(T* left, T* right)
//{
//	return *left < *right;
//}

//void test_template4()
//{
//	cout << Less(1, 2) << endl; // 1 结果正确
//
//	Date d1(2022, 8, 11);
//	Date d2(2022, 8, 12);
//	cout << Less(d1, d2) << endl; // 1 结果正确
//
//	Date* p1 = new Date(2022, 8, 11);
//	Date* p2 = new Date(2022, 8, 10);
//	cout << Less(p1, p2) << endl; // 结果是随机的，无法比较
//	cout << Less(*p1, *p2) << endl; // 正确
//
//}
//
//
//void test_template5()
//{
//	cout << Less(1, 2) << endl; // 1 结果正确  调用原生的
//
//	Date d1(2022, 8, 11);
//	Date d2(2022, 8, 12);
//	cout << Less(d1, d2) << endl; // 1 结果正确 调用原生的
//
//	Date* p1 = new Date(2022, 8, 11);
//	Date* p2 = new Date(2022, 8, 10);
//	cout << Less(p1, p2) << endl; // 模板特化之后，结果就是正确的 调用Date*特化的
//	cout << Less(*p1, *p2) << endl; // 正确 调用原生的
//
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less(p3, p4) << endl; // 正确 调用T*特化的
//}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

// 偏特化
// 1.将模板参数类表中的一部分参数特化。
// 只要第二个参数有double就匹配这个
template<class T1>
class Data<T1, double>
{
public:
	Data() { cout << "Data<T1, double>" << endl; }
private:
	int _d1;
	char _d2;
};

// 偏特化
// 2.参数更进一步限制
// 传2个指针才匹配这个
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	int _d1;
	char _d2;
};

// 传2个引用就匹配
template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "Data<T1&, T2&>" << endl; }
private:
	int _d1;
	char _d2;
};

void test_template6()
{
	Data<int, int> d1; // Data<T1, T2>
	Data<int, char> d2; // Data<int, char>
	Data<int, double> d3; // Data<T1, double>
	Data<double, double> d4; // Data<T1, double>
	Data<int*, double*> d5; // Data<T1*, T2*>
	Data<double*, double*> d6; // Data<T1*, T2*>
	Data<int&, double&> d7; // Data<T1&, T2&>
	Data<int*, void*> d8; // Data<T1*, T2*>
	Data<int*, string*> d9; // Data<T1*, T2*>
	Data<int*, string> d10; // Data<T1, T2>  //只有一个指针，去匹配原生的
}

template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

// 全特化 但是针对其他类型指针就不好用了
//template<>
//struct Less<Date*>
//{
//	bool operator()(Date* x, Date* y) const
//	{
//		return *x < *y;
//	}
//};

// 偏特化
template<class T>
struct Less<T*>
{
	bool operator()(T* x, T* y) const
	{
		return *x < *y;
	}
};

void test_template7()
{
	Date d1(2022, 7, 7);
	Date d2(2022, 7, 6);
	Date d3(2022, 7, 8);

	vector<Date> v1;
	v1.push_back(d1);
	v1.push_back(d2);
	v1.push_back(d3);
	sort(v1.begin(), v1.end(), Less<Date>()); // 日期升序

	vector<Date*> v2;
	v2.push_back(&d1);
	v2.push_back(&d2);
	v2.push_back(&d3);
	sort(v2.begin(), v2.end(), Less<Date*>()); // 利用全特发/偏特化均可

	vector<int*> v3;
	v3.push_back(new int(3));
	v3.push_back(new int(1));
	v3.push_back(new int(2));
	sort(v3.begin(), v3.end(), Less<int*>()); // 利用偏特化
}

int main()
{
	test_template7();
	return 0;
}

