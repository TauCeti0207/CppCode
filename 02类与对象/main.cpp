/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-06 21:35:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-07 16:05:23
 */
// main.cpp
#include "Person.h"
#include "Stack.h"
#include "Date.h"
void testPerson()
{
	Person p1("张三", "男", 20);
	p1.show();

	Person p2(p1);
	p2.show();

	Person p3;
	p3 = p1;
	p3.show();
}

void testStack()
{
	Stack<int> stack;
	try
	{
		stack.push(10);
		stack.push(20);
		stack.push(30);

		std::cout << "Stack size: " << stack.size() << std::endl;
		std::cout << "Top element: " << stack.peek() << std::endl;

		std::cout << "Popped element: " << stack.pop() << std::endl;
		std::cout << "Stack size after pop: " << stack.size() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testDate()
{
	try
	{
		Date d1(2024, 10, 1);
		Date d2(2024, 10, 10);
		std::cout << "d1_day: " << d1.getDay() << std::endl;

		std::cout << "Date 1: " << d1 << std::endl;
		std::cout << "Date 2: " << d2 << std::endl;

		if (d1 < d2)
		{
			std::cout << d1 << " is earlier than " << d2 << std::endl;
		}

		Date d3 = d1 + 5;
		std::cout << d1 << " + 5 days is " << d3 << std::endl;

		int diff = d2 - d1;
		std::cout << "Difference between " << d2 << " and " << d1 << " is " << diff << " days" << std::endl;

		++d1;
		std::cout << "After incrementing d1: " << d1 << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

// 类 A1 的定义
class A1
{
public:
	void f1() {}

private:
	int _a;	 // 占了 0~3
	char _x; // char 最小对齐是 1，占用 4
			 // VS 默认对齐是 8，结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍
			 // 最大对齐数为 8，现在空间占用了 5，补齐到 8，因此总的大小就是 8
};

// 空类
class A2
{
};

// 类中仅有成员函数
class A3
{
public:
	void f2() {}
};

// 测试函数
void testClassMemory()
{
	A1 a1;
	A2 a2;
	A3 a3;

	std::cout << "sizeof(A1): " << sizeof(A1) << std::endl; // 8 注意内存对齐：VS 默认对齐为 8
	std::cout << "sizeof(a1): " << sizeof(a1) << std::endl; // 8
	std::cout << "sizeof(A2): " << sizeof(A2) << std::endl; // 1
	std::cout << "sizeof(A3): " << sizeof(A3) << std::endl; // 1
	std::cout << "sizeof(a2): " << sizeof(a2) << std::endl; // 1
	std::cout << "sizeof(a3): " << sizeof(a3) << std::endl; // 1

	// 不同对象地址不同
	std::cout << "&a1: " << &a1 << std::endl;
	std::cout << "&a2: " << &a2 << std::endl;
	std::cout << "&a3: " << &a3 << std::endl;
}

int main()
{

	// testPerson();
	// testStack();
	testDate();
	// testClassMemory();
	return 0;
}