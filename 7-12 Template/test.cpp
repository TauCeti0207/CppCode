#include <iostream>
using namespace std;

//template <class T = char>
//T* func(int n)
//{
//	return new T[n];
//}
//int main()
//{
//	int* p1 = func<int>(10);
//	double* p2 = func<double>(10);
//	char* p3 = func('a');
//	return 0;
//}

//#include "template.hpp"
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//
//	Vector<int> v1;
//	Vector<double> v2;
//
//	v1.PushBack(1);
//	v1.PushBack(2);
//
//	return 0;
//}


//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//// 模板调用，有现成匹配函数，绝对不去实例化模板
//// 有更匹配的，优先匹配类型最合适的
//int main()
//{
//	Add(1, 2);     // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0);   // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	//这里生成了2个模板
//	return 0;
//}

template<class K, class V>
void Func(const K& key, const V& value)
{
	cout << key << "->" << value << endl;
}


// 半缺省
template<class K, class V = char>
void Func2()
{
	cout << sizeof(K) << endl;
	cout << sizeof(V) << endl;
}

//int main()
//{
//	Func(1, 1);
//	Func(1, 1.2);
//	Func('a', 1.2);
//	Func<int, char>(1, 'b');
//}

int main()
{
	Func2<int, int>();// 4 4
	Func2<int>();// 4 1
}