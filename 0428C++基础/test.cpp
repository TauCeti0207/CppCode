//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <iostream>
////#include <assert.h>
//#include <cassert> // cpp�����������ռ�
//using namespace std;


//int main(int argc, char const* argv[])
//{
//	cout << "hello world" << endl;
//	// �Ա�C����printf scanf ����: �Զ�ʶ������
//	int a = 10;
//	int* p = &a;
//	// �Զ�ʶ������ԭ����������+���������
//	cout << a << "," << p << endl;
//	char str[10];
//
//	// >>����ȡ�����
//	cin >> a;
//	cin >> str;
//
//	// <<�����������
//	cout << a << str << endl;
//	return 0;
//}

//void TestFun(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl
//		<< endl;
//}

//// ���ֵ��÷�ʽ
//int main(int argc, char const* argv[])
//{
//	TestFun(1, 2, 3);
//	TestFun();
//	TestFun(1);
//	TestFun(1, 2);
//	return 0;
//}

//struct Stack
//{
//	int* a;
//	int size;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps, int InitCapacity = 4)
//{
//	assert(ps);
//	ps->a = (int*)malloc(sizeof(int) * InitCapacity);
//	assert(ps->a);
//	ps->size = 0;
//	ps->capacity = InitCapacity;
//}
//
//int main(int argc, char const* argv[])
//{
//	struct Stack st1;
//	//����֪��ջ�����100������
//	StackInit(&st1, 100);
//
//	struct Stack st2;
//	//����֪��ջ�����10������
//	StackInit(&st1, 10);
//
//	struct Stack st3;
//	//���費֪��ջ�����Ҫ���������
//	StackInit(&st3);
//
//	return 0;
//}

//using std::cout;
//
//
//int main()
//{
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//	cout << "hello world" << std::endl;
//
//	return 0;
//}

//namespace yzq
//{
//	int scanf = 0;
//	int strlen = 10;
//}




//int a = 0;
//int main(int argc, char const* argv[])
//{
//	//namespace ctl
//	//{
//	//	int scanf = 0;
//	//	int strlen = 10;
//	//}
//	int a = 1;
//	printf("%d\n", a); // �ֲ����� 1
//	printf("%d\n", ::a); // Ĭ�Ϸ���ȫ�� 0
//	return 0;
//}

//#include <stdio.h>
//int main(int argc, char const* argv[])
//{
//	//������ͻ
//	//c���Կ����棬��2����������scanf ��strlen����
//	int scanf = 0;
//	int strlen = 10;
//	//��������ʱ��ͨ�������������scanfʱ�Ͳ��У�����scanf�Ǿͽ���ȡ
//	//C���Խ�����������ͻ����
//	scanf("%d ", &scanf);
//	return 0;
//}


//#include "Queue.h"
//// ����ʱ .h �ڴ˴�չ����
//
//int main()
//{
//	// ����ʱû��ȱʡֵ������ʱ���ˡ�
//	// ����ʱ��ȥ�Һ�����ַ������ֻ��һ��û��ȱʡֵ��QueueInit����������
//	// �ͱ���ô�����
//	QueueInit();
//	QueueInit(20);
//	return 0;
//}

//#include <iostream>
//using namespace std;
////void f(double a, int b)
////{
////
////}


//// ���߱�������extern "C" �����ĺ�����C�⣬Ҫ��C�ķ�ʽȥ���á�
//extern "C"
//{
//	#include "../5-4Stack_c/Stack.h"
//}
//
//bool isValid(const char* s) {
//	// ���ȥ�����ַ�����Ҫ��int�ĳ�char
//	Stack st;
//	StackInit(&st);
//	while (*s)
//	{
//		// ��������ջ
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//			++s;
//		}
//		// �����ų�ջ���ж��Ƿ�ƥ��
//		else
//		{
//			// Ϊ�գ�˵��û�������ţ�ֻ��������
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);// ȡ����Ҫpop��
//			if ((top == '[' && *s != ']')
//				|| (top == '(' && *s != ')')
//				|| (top == '{' && *s != '}'))
//			{
//				StackDestroy(&st); // ����֮ǰһ��Ҫ���٣���Ȼ�����ڴ�й¶
//				return false;
//			}
//			// ƥ���˾ͼ����ж�
//			else
//				++s;
//		}
//	}
//	// ���ֻ�������ţ�whileѭ��һֱ�ڵ�һ��if���棬�޷���ѭ������return false ��˵���ѭ�����洦��ֻ�������ţ�Stack��Ϊ�գ����ص���false
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//
//int main()
//{
//	printf("%d\n", isValid("[]{}"));
//	printf("%d\n", isValid("[{]}()"));
//}


//int main()
//{
//	//cout << "hello world" << endl;
//	//f(1.1, 2);
//	return 0;
//}


//// main.cpp
//int main()
//{
//	f(1, 2.222);
//	f(2.222, 1);
//	return 0;
//}
//
//// f.h
//void f(int a, double b);
//void f(double a, int b);
//
//// f.cpp
//void f(int a, double b)
//{
//	printf("int,double\n");
//}
//
//void f(double a, int b)
//{
//	printf("double,int\n");
//}


#include <iostream>
using namespace std;

void Swap(int& r1, int& r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

//int main()
//{
//	int x = 1, y = 2;
//	cout << x << " " << y << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}

void func(const int& x)
{

}
//int main()
//{
//	//int a = 10;
//	//int& b = a;
//
//	//const int x = 20;
//	////int& y = x;
//	//const int& y = x;
//
//	//int c = 30;
//	//const int& d = c; // ���Գɹ�����
//
//	//double d = 2.2;
//	//int f = d; // ����Ҳ�ǰ�d���������ֽضϣ���ֵ��һ����ʱ��������ʱ�����ٸ�ֵ��f
//	//const int& e = d;
//	//// ��������ʽ����ת������d���������ֽس�����һ����ʱ��������ʱ�����ٸ���f������ʱ�������г���
//	//// Ҳ���ǣ�e��ʵ���õ�����ʱ���������Լ�const������������
//	//// Ҳ����˵��e��ʵ����d�����ã�eֻ���Ǹ���ʱ�����ı�����e �� d ��ַ��һ���ġ�
//	int a = 10;
//	int& b = a;
//	const int& c = 20;
//	double d = 2.2;
//	func(a);
//	func(10);
//	func(c);
//	func(d); // ��˽����ת��
//	// ͳͳ������ȥ��������ֻ���ģ����β�ֻ��int& x ��Ŵ�Ȩ�ޣ��βε���const int& x
//	return 0;
//}



//#include <time.h>
//struct A
//{
//	int a[10000];
//};
//
//void TestFunc1(A a)
//{
//
//}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//struct A
//{
//    int a[100000];
//};
//
//A a;//�������ȫ�ֱ���
//
//// ֵ����
//A TestFunc1()
//{
//    return a;
//}
//
//// ���÷���
//A& TestFunc2()
//{
//    return a;
//}
//
//void TestReturnByRefOrValue()
//{
//    // ��ֵ��Ϊ�����ķ���ֵ����
//    size_t begin1 = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        TestFunc1();
//    size_t end1 = clock();
//
//    // ��������Ϊ�����ķ���ֵ����
//    size_t begin2 = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        TestFunc2();
//    size_t end2 = clock();
//
//    // �������������������֮���ʱ��
//    cout << "TestFunc1 time:" << end1 - begin1 << endl;
//    cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//    TestReturnByRefOrValue();
//    // TestFunc1 time:907
//    // TestFunc2 time:0
//    //Ч�ʲ���ͦ��
//    return 0;
//}

// ʵ��ADD��
#define ADD(int x, int y) return x + y;
#define ADD(x, y) return x + y;
#define ADD(x, y) (x + y);
#define ADD(x, y) x + y
#define ADD(x, y) ((x) + (y))

int Count()
{
	static int n = 0;
	n++;
	// ...
	return n;
}

int main()
{
	cout << Count() << endl;
	cout << Count() << endl;
	cout << Count() << endl;
	// ���Ϊ1 1 1 ��̬����ֻ���ʼ��һ��
	return 0;
}

