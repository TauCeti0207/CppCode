/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-13 14:13:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-15 00:10:38
 */
#include <iostream>
#include "Stack.h"
#include <vector>
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

class MemoryPool
{
private:
	// 内存池原理：预先分配大块内存，后续对象分配直接从这块内存中划分，避免频繁系统调用。
	std::vector<char *> blocks; // 存储所有分配的内存块
	size_t blockSize;			// 每个内存块的大小（字节）
	size_t nextFree;			// 当前内存块中下一个可用位置的偏移量

public:
	// 创建一个内存池，初始分配一个大小为 blockSize 的内存块。
	MemoryPool(size_t blockSize)
		: blockSize(blockSize),
		  nextFree(0)
	{
		blocks.push_back(new char[blockSize]); // 初始化第一个内存块
	}

	~MemoryPool()
	{
		for (char *block : blocks)
		{
			delete[] block; // 释放所有分配的内存块
		}
	}

	// 内存分配函数
	void *allocate(size_t size)
	{
		// 检查当前内存块是否有足够空间
		if (nextFree + size > blockSize)
		{
			blocks.push_back(new char[blockSize]); // 分配新内存块
			nextFree = 0;						   // 重置偏移量
		}

		// 计算并返回可用内存地址
		void *result = blocks.back() + nextFree;
		nextFree += size; // 更新偏移量
		return result;
	}

	void deallocate(void *p)
	{
		// 简单内存池不实现释放，实际中需更复杂管理
	}
};

void test6()
{
	// 假设从内存池获取
	A *p = (A *)operator new(sizeof(A)); // 这里只是将开辟的空间强转成A*
	// new (p) A;
	new (p) A(3); // 定位new，placement-new，显示调用构造函数初始化这块对象空间
	// 等价于A* p = new A(3)

	// 等价于 delete p
	p->~A(); // 析构函数可以显示调用
	operator delete(p);
}

void test7()
{
	// 创建可容纳10个A对象的内存池
	MemoryPool pool(sizeof(A) * 10);

	// 1. 从内存池分配内存（未初始化）
	A *p = static_cast<A *>(pool.allocate(sizeof(A)));

	// 2. 使用定位new在已分配内存上构造对象
	new (p) A(3);

	// 3. 显式调用析构函数（销毁对象但不释放内存）
	p->~A();

	// 4. 通知内存池释放内存（当前实现为空）
	pool.deallocate(p);
}

#include <cstring>
#include <cstdlib>

int globalVar = 1;				// 全局变量 -> 静态区
static int staticGlobalVar = 1; // 静态全局变量 -> 静态区

void test8()
{
	static int staticVar = 1;	 // 静态局部变量 -> 静态区
	int localVar = 1;			 // 局部变量 -> 栈区
	int num1[10] = {1, 2, 3, 4}; // 数组 -> 栈区
	// char2 是数组，char2在栈上，*char2也在栈上，在栈上开了个数组，把hello内容拷贝过去了，hello是常量区的内容
	char char2[] = "hello"; // 字符数组 -> 栈区（内容拷贝自常量区）
	// pChar3 是指针，pChar3在栈上，*pChar3在常量区
	const char *pChar3 = "hello";					   // 指针 -> 栈区，指向常量区字符串
	int *ptr1 = (int *)malloc(sizeof(int) * 4);		   // 指针 -> 栈区，指向堆区内存
	int *ptr2 = (int *)calloc(4, sizeof(int));		   // 指针 -> 栈区，指向堆区内存
	int *ptr3 = (int *)realloc(ptr2, sizeof(int) * 4); // 指针 -> 栈区，指向堆区内存

	// 打印各变量的地址和相关信息
	std::cout << "===== 内存地址对比 =====" << std::endl;

	// 栈区变量
	std::cout << "\n[栈区]" << std::endl;
	std::cout << "localVar 地址: " << &localVar << std::endl;
	std::cout << "num1 地址: " << (void *)num1 << std::endl;   // 数组首地址
	std::cout << "char2 地址: " << (void *)char2 << std::endl; // 字符数组首地址
	std::cout << "pChar3 指针地址: " << &pChar3 << std::endl;  // 指针本身的地址
	std::cout << "ptr1 指针地址: " << &ptr1 << std::endl;
	std::cout << "ptr2 指针地址: " << &ptr2 << std::endl;
	std::cout << "ptr3 指针地址: " << &ptr3 << std::endl;

	// 堆区内存
	std::cout << "\n[堆区]" << std::endl;
	std::cout << "ptr1 指向的堆地址: " << ptr1 << std::endl;
	std::cout << "ptr2 指向的堆地址: " << ptr2 << std::endl;
	std::cout << "ptr3 指向的堆地址: " << ptr3 << std::endl;

	// 静态区变量
	std::cout << "\n[静态区]" << std::endl;
	std::cout << "globalVar 地址: " << &globalVar << std::endl;
	std::cout << "staticGlobalVar 地址: " << &staticGlobalVar << std::endl;
	std::cout << "staticVar 地址: " << &staticVar << std::endl;

	// 常量区
	std::cout << "\n[常量区]" << std::endl;
	std::cout << "pChar3 指向的字符串地址: " << (void *)pChar3 << std::endl;

	// 大小信息
	std::cout << "\n===== 大小信息 =====" << std::endl;
	std::cout << "sizeof(num1) = " << sizeof(num1) << " 字节" << std::endl;		// 10个int 40
	std::cout << "sizeof(char2) = " << sizeof(char2) << " 字节" << std::endl;	// 包含'\0' 6
	std::cout << "strlen(char2) = " << strlen(char2) << " 字符" << std::endl;	// 不包含'\0' 5
	std::cout << "sizeof(pChar3) = " << sizeof(pChar3) << " 字节" << std::endl; // 指针大小 8 (64位系统)
	std::cout << "strlen(pChar3) = " << strlen(pChar3) << " 字符" << std::endl; // 不包含'\0' 5
	std::cout << "sizeof(ptr1) = " << sizeof(ptr1) << " 字节" << std::endl;		// 指针大小 8

	free(ptr1);
	// free(ptr2); // 注意不能重复释放 ptr2 空间
	free(ptr3);
}

int main()
{
	test8();
	return 0;
}