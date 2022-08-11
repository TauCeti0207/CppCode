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
	// ����һ���������� ��ģ��û��ʵ������֮ǰ������ȥȡlist<T>�������Ƕ����
	// ��ǰ�����typename�ؼ��֣����߱����������list<T>::const_iterator��һ������
	// ����ģ��ʵ�������֮����ȥȡ
	// ������listȷ���ˣ���listģ�������ûȷ��
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
	// ��Ҳ��һ���������ͣ����嶼û��ȷ��
	// typename ֻ�Ǹ��߱���������һ������������ ��ʵ�������֮����ȥ��
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


// ��̬ջ
// ���÷�����ģ�����
// N�ǳ�����Ҳ��ζ�Ų������޸�
template<class T, size_t N = 100> // Ҳ�ǿ��Ը���ȱʡ������ 
class Stack
{
public:
	void f()
	{
		//N = 20; // err �������޸�
	}
private:
	T _a[N];
	int _top;
};

void test_template2()
{
	Stack<int, 50> st1; // ��50��
	st1.f();
	Stack<double, 500> st2; // ��500��
}

void test_template3()
{
	// v1���ݴ��ڶ��ϵ�
	vector<int> v1(100, 0);
	v1[0] = 0;
	v1[1] = 1;
	// ...
	v1[99] = 99;
	cout << sizeof(v1) << endl; // 16  32λƽ̨��


	// ���ݴ���ջ�ϣ�û�г�ʼ���Ļ������������
	// array��C++11������ -- ��ʵ���Ƿ�װ����ԭ������
	// �Ա�ԭ����������ƣ�operator[] ���ϸ���Խ��
	// Խ���Խ��д���ܼ�鵽
	array<int, 100> a1;
	a1[0] = 0;
	a1[1] = 1;
	// ...
	a1[99] = 99;
	cout << sizeof(a1) << endl; // 400byte
	//a1[200] = 1;
	//cout << a1[200] << endl;

	int a2[100]; // ԭ������ ���Խ���ǳ�飬��ʱ��鲻��
	//a2[200] = 1;
	//a2[200];
}

//template <class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}

//// ģ���ػ������ĳЩ�����������⻯����
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
//// Ϊ�����int* int*
//template <class T>
//bool Less(T* left, T* right)
//{
//	return *left < *right;
//}

//void test_template4()
//{
//	cout << Less(1, 2) << endl; // 1 �����ȷ
//
//	Date d1(2022, 8, 11);
//	Date d2(2022, 8, 12);
//	cout << Less(d1, d2) << endl; // 1 �����ȷ
//
//	Date* p1 = new Date(2022, 8, 11);
//	Date* p2 = new Date(2022, 8, 10);
//	cout << Less(p1, p2) << endl; // ���������ģ��޷��Ƚ�
//	cout << Less(*p1, *p2) << endl; // ��ȷ
//
//}
//
//
//void test_template5()
//{
//	cout << Less(1, 2) << endl; // 1 �����ȷ  ����ԭ����
//
//	Date d1(2022, 8, 11);
//	Date d2(2022, 8, 12);
//	cout << Less(d1, d2) << endl; // 1 �����ȷ ����ԭ����
//
//	Date* p1 = new Date(2022, 8, 11);
//	Date* p2 = new Date(2022, 8, 10);
//	cout << Less(p1, p2) << endl; // ģ���ػ�֮�󣬽��������ȷ�� ����Date*�ػ���
//	cout << Less(*p1, *p2) << endl; // ��ȷ ����ԭ����
//
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less(p3, p4) << endl; // ��ȷ ����T*�ػ���
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

// ȫ�ػ�
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

// ƫ�ػ�
// 1.��ģ���������е�һ���ֲ����ػ���
// ֻҪ�ڶ���������double��ƥ�����
template<class T1>
class Data<T1, double>
{
public:
	Data() { cout << "Data<T1, double>" << endl; }
private:
	int _d1;
	char _d2;
};

// ƫ�ػ�
// 2.��������һ������
// ��2��ָ���ƥ�����
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	int _d1;
	char _d2;
};

// ��2�����þ�ƥ��
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
	Data<int*, string> d10; // Data<T1, T2>  //ֻ��һ��ָ�룬ȥƥ��ԭ����
}

template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

// ȫ�ػ� ���������������ָ��Ͳ�������
//template<>
//struct Less<Date*>
//{
//	bool operator()(Date* x, Date* y) const
//	{
//		return *x < *y;
//	}
//};

// ƫ�ػ�
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
	sort(v1.begin(), v1.end(), Less<Date>()); // ��������

	vector<Date*> v2;
	v2.push_back(&d1);
	v2.push_back(&d2);
	v2.push_back(&d3);
	sort(v2.begin(), v2.end(), Less<Date*>()); // ����ȫ�ط�/ƫ�ػ�����

	vector<int*> v3;
	v3.push_back(new int(3));
	v3.push_back(new int(1));
	v3.push_back(new int(2));
	sort(v3.begin(), v3.end(), Less<int*>()); // ����ƫ�ػ�
}

int main()
{
	test_template7();
	return 0;
}

