//  ע�������Ҫ���ؾֲ������ĵ�ַ��ջ�����ٵ������ɱ������Զ��ͷ�
//#include<iostream>
//using namespace std;
//int* fun()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = fun();
//	cout << *p << endl;
//	cout << *p << endl;
//	system("pause");
//	return 0;
//}

//////int* func()
//////{
//////	int* a = new int(10);
//////	return a;
//////}
//////int main()
//////{
//////	int* p = func();
//////	cout << *p << endl;
//////	cout << *p << endl;	
//////	cout << *p << endl;
//////	cout << *p << endl;
//////	delete p;
//////	//cout << *p << endl;//�����ͷŵĿռ䲻�ɷ���
//////	system("pause");
//////	return 0;
//////}
////
////
////
//////int main()
//////{
//////	int* arr = new int[100];
//////	for (int i = 0; i < 100; i++)
//////	{
//////		arr[i] = i + 100;
//////	}
//////	for (int i = 0; i < 100; i++)
//////	{
//////		cout << arr[i] << endl;
//////	}
//////	delete[] arr;
//////	//for (int i = 0; i < 100; i++)
//////	//{
//////	//	cout << arr[i] << endl;
//////	//}
//////	system("pause");
//////	return 0;
//////}
////
////
//////void myswap01(int a, int b)
//////{
//////	int temp = a;
//////	a = b;
//////	b = temp;
//////}
//////void myswap02(int* a, int* b)
//////{
//////	int temp = *a;
//////	*a = *b;
//////	*b = temp;
//////}
//////
//////void myswap03(int& a, int& b)
//////{
//////	int temp = a;
//////	a = b;
//////	b = temp;
//////}
//////int main()
//////{
////
//////	int a = 10;
//////	int b = 20;
//////	myswap01(a, b);
//////cout << "a=" << a << endl;
//////cout << "b=" << b << endl;
//////
//////myswap02(&a, &b);
//////cout << "a=" << a << endl;
//////cout << "b=" << b << endl;
//////
//////myswap03(a, b);
//////cout << "a=" << a << endl;
//////cout << "b=" << b << endl;
//////
//////b = 30;
//////a = b;
//////cout << "a=" << a << endl;
//////cout << "b=" << b << endl;
////	//cout << "a=" << a << endl;
////	//cout << "b=" << b << endl;
////	//int a = 10;
////	//int& b = a;
////	//cout << "a=" << a << endl;
////	//cout << "b=" << b << endl;
////	//b = 100;
////	//cout << "a=" << a << endl;
////	//cout << "b=" << b << endl;
////	//int a = 10;
////	//int b = 20;
////	//int& c = a;
////	//cout << "a=" << a << endl;
////	//cout << "b=" << b << endl;
////	//cout << "c=" << c << endl;
////	//c = b;
////	//cout << "c=" << c << endl;
////
//////
//////	system("pause");
//////	return 0;
//////}
//////
//////int& test01()
//////{
//////	int a = 10;
//////	return a;
//////}
//////
//////int& test02()
//////{
//////	static int a = 20;
//////	return a;
//////}
////
//////void func(int& ref)
//////{
//////	ref = 100;
//////
//////}
//////
//////int func(int a, int b = 10, int c = 20)
//////{
//////	return a + b + c;
//////}
////////void showvalue( const int &a)
////////{
////////	//a = 1000;
////////	cout << a << endl;
////////
////////}
//////int main()
//////{
//////	cout << func(20, 20) << endl;
//////	//int a = 10;
//////	////int& ref = a;
//////	//int* const ref = &a;
//////	cout << func(100) << endl;
//////	////ref = 20;
//////	//*ref = 20;
//////
//////	//cout << "a=" << a << endl;
//////	//cout << "b="<<ref << endl;
//////	//////int a = 10;
//////	//////int& ref = a;
//////	//////ref = 20;
//////	//////cout << a << endl;
//////	//////cout << ref << endl;
//////	//////func(a);
//////	//////cout << a << endl;
//////	//////cout << ref << endl;
//////	////////int& ref = test01();
//////	////////cout << ref << endl;
//////	////////cout << ref << endl;
//////	////////int& ref2 = test02();
//////	////////cout << ref2 << endl;
//////	////////cout << ref2 << endl;
//////	////////test02() = 1000;
//////	////////cout << ref2 << endl;
//////	////////cout << ref2 << endl;
//////
//////	////const int& ref = 10;
//////	////ref = 20;
//////	//int a = 10;
//////	//showvalue(a);
//////	//cout << "a=" << a << endl;
//////	system("pause");
//////	return 0;
//////}
//
//void func()
//{
//	cout << "func�ĵ���" << endl;
//
//}
//void func(int a)
//{
//	cout << "func(int a)�ĵ���" << endl;
//}
//
//void func(double a)
//{
//	cout << "func(double a)�ĵ���" << endl;
//}
//
//void func(int a, double b)
//{
//	cout << "func(int a, double b)�ĵ���" << endl;
//}
//
//void func(double b, int a
//)
//{
//	cout << "func(double b, int a	)�ĵ���" << endl;
//}
	/*func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);*/

#include<iostream>
using namespace std;
void func(int& a)
{
	cout << "func(int &a)����" << endl;
}
void func(const int& a)
{
	cout << "func(const int& a)����" << endl;
}
void func2(int a,int b=20 )
{
	cout << "func2(int a, int b = 10) ����" << endl;
}
void func2(int a)
{
	cout << "func2(int a) ����" << endl;
}

int main()
{
	int a = 10;
	func(a); //������const
	func(10);//������const

	//func2(10); //����Ĭ�ϲ����������壬��Ҫ����
	system("pause");
	return 0;

}