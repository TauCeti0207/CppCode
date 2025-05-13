/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-13 16:49:06
 */
#include <iostream>
#include "Stack.h"
void test1()
{
	// 多个对象
	int *p1 = (int *)malloc(sizeof(int) * 10);
	int *p2 = new int[10]; // new是操作符，默认用 0 初始化
	free(p1);
	delete[] p2;
	int *p5 = new int[10]{10}; // new十个int对象，初始化第一个对象为10，剩下的都是0
	delete[] p5;
	// 单个对象
	int *p3 = (int *)malloc(sizeof(int));
	int *p4 = new int;
	free(p3);
	delete p4;
	int *p6 = new int(10); // new一个int对象，初始化为10
}

struct ListNode
{
	ListNode *_next;
	ListNode *_prev;
	int _val;

	ListNode(int val = 0) // 构造函数
		: _next(nullptr), _prev(nullptr), _val(val)
	{
		std::cout << "ListNode(int val = 0) //构造函数" << std::endl;
	}
	~ListNode()
	{
		std::cout << "~ListNode()" << std::endl;
	}
};

void test2()
{
	// c malloc只是开空间 free 仅仅是释放空间
	struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	free(n1);

	// C++ new 针对自定义类型 开空间+调用构造函数完成初始化
	// delete 针对自定义类型，先析构 再释放空间
	ListNode *n2 = new ListNode;
	ListNode *n3 = new ListNode(1);
	delete n2;
	delete n3;
}

void test3()
{
	ListNode a1(1);
	ListNode a2(2);
	// 有名对象初始化
	ListNode *arr1 = new ListNode[4]{a1, a2};
	// 匿名对象初始化
	ListNode *arr2 = new ListNode[4]{ListNode(3), ListNode(4)}; // 如果不足4个，后面的就会用0补充
	// 隐式类型转换初始化
	ListNode *arr3 = new ListNode[4]{5, 6, 7, 8};

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	// delete arr3; // 这样写就不匹配，会崩溃
}

void test5()
{
	void *p3 = malloc(0xffffffff);
	if (p3 == NULL)
	{
		std::cout << "malloc fail" << std::endl;
	}
	else
	{
		std::cout << "malloc success" << std::endl;
	}

	try
	{
		void *p4 = operator new(0xffffffff);
		std::cout << "operator new success" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		std::cout << "A():" << this << std::endl;
	}

	~A()
	{
		std::cout << "~A():" << this << std::endl;
	}

private:
	int _a;
};

void test6()
{
	A *p = (A *)operator new(sizeof(A)); // 这里只是将开辟的空间强转成A*
	// new (p) A;
	new (p) A(3); // 定位new，placement-new，显示调用构造函数初始化这块对象空间
	// 等价于A* p = new A(3)

	// 等价于 delete p
	p->~A(); // 析构函数可以显示调用
	operator delete(p);
}

int main()
{
	test6();
	return 0;
}