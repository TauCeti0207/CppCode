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

//#include <iostream>
//using namespace std;
////void f(double a, int b)
////{
////
////}


//// 告诉编译器，extern "C" 声明的函数是C库，要用C的方式去调用。
//extern "C"
//{
//	#include "../5-4Stack_c/Stack.h"
//}
//
//bool isValid(const char* s) {
//	// 入进去的是字符，需要将int改成char
//	Stack st;
//	StackInit(&st);
//	while (*s)
//	{
//		// 左括号入栈
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//			++s;
//		}
//		// 右括号出栈，判断是否匹配
//		else
//		{
//			// 为空，说明没有左括号，只有右括号
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);// 取完了要pop掉
//			if ((top == '[' && *s != ']')
//				|| (top == '(' && *s != ')')
//				|| (top == '{' && *s != '}'))
//			{
//				StackDestroy(&st); // 返回之前一定要销毁，不然会有内存泄露
//				return false;
//			}
//			// 匹配了就继续判断
//			else
//				++s;
//		}
//	}
//	// 如果只有左括号，while循环一直在第一个if里面，无法在循环里面return false 因此得在循环外面处理，只有左括号，Stack不为空，返回的是false
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
//	//const int& d = c; // 可以成功编译
//
//	//double d = 2.2;
//	//int f = d; // 这里也是把d的整数部分截断，赋值给一个临时变量，临时变量再赋值给f
//	//const int& e = d;
//	//// 发生了隐式类型转换，把d的整数部分截出来给一个临时变量，临时变量再赋给f，而临时变量具有常性
//	//// 也就是，e其实引用的是临时变量，所以加const才能正常引用
//	//// 也就是说，e其实不是d的引用，e只是那个临时变量的别名，e 和 d 地址不一样的。
//	int a = 10;
//	int& b = a;
//	const int& c = 20;
//	double d = 2.2;
//	func(a);
//	func(10);
//	func(c);
//	func(d); // 隐私类型转换
//	// 统统传不过去，常量是只读的，而形参只是int& x 会放大权限，形参得用const int& x
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
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//struct A
//{
//    int a[100000];
//};
//
//A a;//定义的是全局变量
//
//// 值返回
//A TestFunc1()
//{
//    return a;
//}
//
//// 引用返回
//A& TestFunc2()
//{
//    return a;
//}
//
//void TestReturnByRefOrValue()
//{
//    // 以值作为函数的返回值类型
//    size_t begin1 = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        TestFunc1();
//    size_t end1 = clock();
//
//    // 以引用作为函数的返回值类型
//    size_t begin2 = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        TestFunc2();
//    size_t end2 = clock();
//
//    // 计算两个函数运算完成之后的时间
//    cout << "TestFunc1 time:" << end1 - begin1 << endl;
//    cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//    TestReturnByRefOrValue();
//    // TestFunc1 time:907
//    // TestFunc2 time:0
//    //效率差异挺大
//    return 0;
//}

// 实现ADD宏
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
	// 结果为1 1 1 静态变量只会初始化一次
	return 0;
}

