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
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//// ģ����ã����ֳ�ƥ�亯�������Բ�ȥʵ����ģ��
//// �и�ƥ��ģ�����ƥ����������ʵ�
//int main()
//{
//	Add(1, 2);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	//����������2��ģ��
//	return 0;
//}

template<class K, class V>
void Func(const K& key, const V& value)
{
	cout << key << "->" << value << endl;
}


// ��ȱʡ
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