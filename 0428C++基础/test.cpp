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

#include <iostream>
using namespace std;
void f(double a, int b)
{

}

int main()
{
	cout << "hello world" << endl;
	f(1.1, 2);
	return 0;
}


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