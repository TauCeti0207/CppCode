//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <iostream>
////#include <assert.h>
//#include <cassert> // cpp包含到命名空间
//using namespace std;


//int main(int argc, char const* argv[])
//{
//	cout << "hello world" << endl;
//	// 对比C语言printf scanf 优势: 自动识别类型
//	int a = 10;
//	int* p = &a;
//	// 自动识别类型原理：函数重载+运算符重载
//	cout << a << "," << p << endl;
//	char str[10];
//
//	// >>流提取运算符
//	cin >> a;
//	cin >> str;
//
//	// <<流插入运算符
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

//// 多种调用方式
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
//	//假设知道栈里面存100个数据
//	StackInit(&st1, 100);
//
//	struct Stack st2;
//	//假设知道栈里面存10个数据
//	StackInit(&st1, 10);
//
//	struct Stack st3;
//	//假设不知道栈里可能要存多少数据
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
//	printf("%d\n", a); // 局部优先 1
//	printf("%d\n", ::a); // 默认访问全局 0
//	return 0;
//}

//#include <stdio.h>
//int main(int argc, char const* argv[])
//{
//	//命名冲突
//	//c语言库里面，有2个函数用了scanf 和strlen名称
//	int scanf = 0;
//	int strlen = 10;
//	//变量定义时能通过，但下面调用scanf时就不行，调用scanf是就近读取
//	//C语言解决不了这个冲突问题
//	scanf("%d ", &scanf);
//	return 0;
//}


//#include "Queue.h"
//// 编译时 .h 在此处展开了
//
//int main()
//{
//	// 声明时没给缺省值，定义时给了。
//	// 链接时才去找函数地址，上面只有一个没有缺省值的QueueInit函数的声明
//	// 就必须得传参数
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