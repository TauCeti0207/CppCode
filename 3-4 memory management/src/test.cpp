#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
// void f2()
//{
//	int b = 0;
//	cout << &b << endl;
// }
// void f1()
//{
//	int a = 0;
//	cout << &a << endl;
//	f2();
// }
////int main()
////{
////	f1();
////	return 0;
////}
//
// int main()
//{
//	int* p1 = (int*)malloc(4);
//	int* p2 = (int*)malloc(4);
//	cout << "p1:" << p1 << endl;
//	cout << "p2:" << p2 << endl;
//	return 0;
//}

// int globalVar = 1;//全局变量->静态区
// static int staticGlobalVar = 1;//静态区
// void Test()
//{
//	static int staticVar = 1;//静态区
//	int localVar = 1;//栈区
//	int num1[10] = { 1,2,3,4 };//栈区
//	char char2[] = "hello";//char2在栈，*char2也在栈上，在栈上开了个数组，把hello内容都拷贝过去了,hello是常量区的内容
//	const char* pChar3 = "hello";//pChar3在栈区，*pChar3在常量区
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1在栈区，指向开辟的空间在堆区
//	int* ptr2 = (int*)calloc(4, sizeof(int));//
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//
//	free(ptr1);
//	free(ptr3);
// }

// int main()
//{
//	//多个对象
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];//new是操作符
//	free(p1);
//	delete
//	//单个对象
//	int* p3 = (int*)malloc(sizeof(int));
//
//	return 0;
// }

// struct ListNode
// {
// 	// struct ListNode* _next;//c的写法
// 	ListNode *_next; // C++写法
// 	ListNode *_prev;
// 	int _val;

// 	ListNode(int val = 0) //构造函数
// 		: _next(nullptr), _prev(nullptr), _val(val)
// 	{
// 		cout << "ListNode(int val = 0)//构造函数" << endl;
// 	}
// 	~ListNode()
// 	{
// 		cout << "~ListNode()" << endl;
// 	}
// };

// int main()
//{
//	//c malloc只是开空间 free 仅仅是释放空间
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	free(n1);
//
//
//	//C++ new 针对自定义类型 开空间+构造函数完成初始化
//	//delete 针对自定义类型，先析构 再释放空间
//	ListNode* n2 = new ListNode;
//	delete n2;
//
//	struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode)*4);
//	free(arr3);
//
//	ListNode* arr4 = new ListNode[4];//开辟4个对象就调用4次构造函数
//	delete[] arr4;//delete时也析构4次
//	//delete arr4;// 这样写就不匹配，会崩溃
//	return 0;
// }

// int main()
// {
// 	//void* p1 = malloc(1024 * 1024 * 1024);//1GB

// 	void* p1 = malloc(0xffffffff);//4GB

// 	cout << p1 << endl;
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	ListNode *p1 = (ListNode *)malloc(sizeof(ListNode));
// 	free(p1);

// 	//用法与malloc free一样
// 	ListNode *p2 = (ListNode *)operator new(sizeof(ListNode));
// 	operator delete(p2);

// 	void *p3 = malloc(0xffffffff);
// 	if (p3 == NULL)
// 	{
// 		cout << "malloc fail" << endl;
// 	}

// 	try
// 	{
// 		void *p4 = operator new(0xffffffff);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	system("pause");
// 	return 0;
// }

// int globalVar = 1;				//全局变量->静态区
// static int staticGlobalVar = 1; //静态区
// void Test()
// {
// 	static int staticVar = 1;						   //静态区
// 	int localVar = 1;								   //栈区
// 	int num1[10] = {1, 2, 3, 4};					   //栈区
// 	char char2[] = "hello";							   // char2在栈，*char2也在栈上，在栈上开了个数组，把hello内容都拷贝过去了,hello是常量区的内容
// 	const char *pChar3 = "hello";					   // pChar3在栈区，*pChar3在常量区
// 	int *ptr1 = (int *)malloc(sizeof(int) * 4);		   // ptr1在栈区，指向开辟的空间在堆区
// 	int *ptr2 = (int *)calloc(4, sizeof(int));		   //
// 	int *ptr3 = (int *)realloc(ptr2, sizeof(int) * 4); //
// 	free(ptr1);
// 	free(ptr3);
// }

// class Stack
// {
// public:
// 	Stack()
// 		: num(new int[10]), top(0), capacity(10)
// 	{
// 	}
// 	~Stack()
// 	{
// 		delete[] num;
// 		top = capacity = 0;
// 	}

// private:
// 	int *num;
// 	int top;
// 	int capacity;
// };

// int main()
// {
// 	Stack stack;
// 	return 0;
// }

// struct ListNode
// {
// 	ListNode *_next; // C++写法
// 	ListNode *_prev;
// 	int _val;

// 	//类中重载专属的operator new
// 	void *operator new(size_t n)
// 	{
// 		void *p = nullptr;
// 		p = allocator<ListNode>().allocate(1); // STL中的空间配置器，其实就是一个简单的内存池
// 		cout << "memory pool allocate" << endl;
// 		return p;
// 	}
// 	void operator delete(void *p)
// 	{
// 		allocator<ListNode>().deallocate((ListNode *)p, 1);
// 		cout << "memory pool deallocate" << endl;
// 	}
// 	ListNode(int val = 0) //构造函数
// 		: _next(nullptr), _prev(nullptr), _val(val)
// 	{
// 		cout << "ListNode(int val = 0)//构造函数" << endl;
// 	}
// 	~ListNode()
// 	{
// 		cout << "~ListNode()" << endl;
// 	}
// };
// int main(int argc, char const *argv[])
// {
// 	ListNode *p = new ListNode(1);
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	A* p = (A*)malloc(sizeof(A));
// 	return 0;
// }

// class A
// {
// public:
// 	A(int a = 0)
// 		: _a(a)
// 	{
// 		cout << "A():" << this << endl;
// 	}

// 	~A()
// 	{
// 		cout << "~A():" << this << endl;
// 	}

// private:
// 	int _a;
// };

// int main()
// {
// 	// A* p = (A*)malloc(sizeof(A));

// 	// 等价于直接用A* p = new A
// 	A *p = (A *)operator new(sizeof(A));
// 	new (p) A; // new(p)A(3);  // 定位new，placement-new，显示调用构造函数初始化这块对象空间

// 	// 等于 delete p
// 	p->~A(); // 析构函数可以显示调用
// 	operator delete(p);

// 	return 0;
// }

// void MemoryLeaks()
// {
// 	// 1.内存申请了忘记释放
// 	int *p1 = (int *)malloc(sizeof(int));
// 	int *p2 = new int;

// 	// 2.异常安全问题
// 	int *p3 = new int[10];

// 	Func(); //这里Func函数抛异常导致 delete[] p3 未执行 p3没释放
// 	delete[] p3;
// }

#include <stdio.h>
#include <assert.h>

// // 计算阶乘递归Fac的时间复杂度？
// long long Fac(size_t N)
// {
// 	if (0 == N)
// 		return 1;

// 	for (size_t i = 0; i < N; ++i)
// 	{
// 		printf("%d", i);
// 	}
// 	printf("\n");

// 	return Fac(N - 1) * N;
// }

// // 计算斐波那契递归Fib的时间复杂度？
// long long Fib(size_t N)
// {
// 	if (N < 3)
// 		return 1;

// 	return Fib(N - 1) + Fib(N - 2);
// }
int BinarySearch(int *a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d\n", BinarySearch(a, 10, i));
	}
	system("pause");
	return 0;
}