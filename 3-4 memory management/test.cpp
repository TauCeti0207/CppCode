#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//void f2()
//{
//	int b = 0;
//	cout << &b << endl;
//}
//void f1()
//{
//	int a = 0;
//	cout << &a << endl;
//	f2();
//}
////int main()
////{
////	f1();
////	return 0;
////}
//
//int main()
//{
//	int* p1 = (int*)malloc(4);
//	int* p2 = (int*)malloc(4);
//	cout << "p1:" << p1 << endl;
//	cout << "p2:" << p2 << endl;
//	return 0;
//}

//int globalVar = 1;//全局变量->静态区
//static int staticGlobalVar = 1;//静态区
//void Test()
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
//}

//int main()
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
//}

struct ListNode
{
	//struct ListNode* _next;//c的写法
	ListNode* _next;//C++写法
	ListNode* _prev;
	int _val;
	
	ListNode(int val = 0)//构造函数
		:_next(nullptr)
		,_prev(nullptr)
		,_val(val)
	{
		cout << "ListNode(int val = 0)//构造函数" << endl;
	}
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}

};

//int main()
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
//}

int main()
{
	//void* p1 = malloc(1024 * 1024 * 1024);//1GB

	void* p1 = malloc(0xffffffff);//4GB

	cout << p1 << endl;
	return 0;
}