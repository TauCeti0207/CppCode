/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-06 21:35:01
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-13 13:23:23
 */
// main.cpp
#include "Person.h"
#include "Stack.h"
#include "Date.h"
#include <assert.h>
#include <sstream>
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

// 测试函数
void testDateClass()
{
	std::cout << "--------------------- Starting Date class tests ---------------------" << std::endl;

	// 测试构造函数
	try
	{
		std::cout << "Testing constructor...";
		Date date1(2024, 5, 15);
		std::cout << "Constructed date1: ";
		date1.print();
		assert(date1.getYear() == 2024);
		assert(date1.getMonth() == 5);
		assert(date1.getDay() == 15);
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试拷贝构造函数
	try
	{
		std::cout << "Testing copy constructor...";
		Date date1(2024, 5, 15);
		Date date2(date1);
		std::cout << "Original date1: ";
		date1.print();
		std::cout << "Copied date2: ";
		date2.print();
		assert(date2 == date1);
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试赋值运算符
	try
	{
		std::cout << "Testing assignment operator...";
		Date date1(2024, 5, 15);
		Date date2(2023, 10, 20);
		std::cout << "Before assignment, date2: ";
		date2.print();
		date2 = date1;
		std::cout << "After assignment, date2: ";
		date2.print();
		assert(date2 == date1);
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试日期比较运算符
	try
	{
		std::cout << "Testing comparison operators...";
		Date date1(2024, 5, 15);
		Date date2(2024, 5, 20);
		std::cout << "date1: ";
		date1.print();
		std::cout << "date2: ";
		date2.print();
		assert(date1 < date2);
		assert(date1 <= date2);
		assert(date2 > date1);
		assert(date2 >= date1);
		assert(date1 != date2);
		Date date3(2024, 5, 15);
		std::cout << "date3: ";
		date3.print();
		assert(date1 == date3);
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试自增自减运算符
	try
	{
		std::cout << "Testing increment and decrement operators...";
		Date date1(2024, 5, 31);
		std::cout << "Before increment, date1: ";
		date1.print();
		Date date2 = date1++;
		std::cout << "After increment (postfix), date1: ";
		date1.print();
		std::cout << "date2: ";
		date2.print();
		assert(date2 == Date(2024, 5, 31));
		assert(date1 == Date(2024, 6, 1));
		Date date3 = --date1;
		std::cout << "After decrement (prefix), date1: ";
		date1.print();
		std::cout << "date3: ";
		date3.print();
		assert(date3 == Date(2024, 5, 31));
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试日期加减天数运算符
	try
	{
		std::cout << "Testing date addition and subtraction operators...";
		Date date1(2024, 5, 15);
		std::cout << "Before addition, date1: ";
		date1.print();
		Date date2 = date1 + 10;
		std::cout << "After addition, date2: ";
		date2.print();
		assert(date2 == Date(2024, 5, 25));
		Date date3 = date1 - 5;
		std::cout << "After subtraction, date3: ";
		date3.print();
		assert(date3 == Date(2024, 5, 10));
		date1 += 20;
		std::cout << "After += 20, date1: ";
		date1.print();
		assert(date1 == Date(2024, 6, 4));
		date1 -= 15;
		std::cout << "After -= 15, date1: ";
		date1.print();
		assert(date1 == Date(2024, 5, 20));
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试日期差值计算
	try
	{
		std::cout << "Testing date difference calculation...";
		Date date1(2024, 5, 15);
		Date date2(2024, 5, 25);
		std::cout << "date1: ";
		date1.print();
		std::cout << "date2: ";
		date2.print();
		assert(date2 - date1 == 10);
		assert(date1 - date2 == -10);
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试输入输出运算符
	try
	{
		std::cout << "Testing input and output operators...";
		std::ostringstream oss;
		Date date1(2024, 5, 15);
		std::cout << "Before output, date1: ";
		date1.print();
		oss << date1;
		std::string output = oss.str();
		assert(output == "2024-5-15");

		std::istringstream iss("2024 6 20");
		Date date2(2023, 10, 20);
		std::cout << "Before input, date2: ";
		date2.print();
		iss >> date2;
		std::cout << "After input, date2: ";
		date2.print();
		assert(date2 == Date(2024, 6, 20));
		std::cout << " Passed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	// 测试异常处理
	try
	{
		std::cout << "Testing exception handling...";
		try
		{
			Date invalidDate(2024, 2, 30);
			assert(false); // 如果没有抛出异常，测试失败
		}
		catch (const std::invalid_argument &e)
		{
			std::cout << " Passed" << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed: " << e.what() << std::endl;
	}

	std::cout << "--------------------- All tests completed ---------------------" << std::endl;
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

void funCopy(Stack<int> st)
{
	std::cout << "funCopy" << std::endl;
}
void testStackCopy()
{
	Stack<int> st1;
	// 这里是浅拷贝，同一块空间析构两次，err
	// funCopy(st); err

	Stack<int> st2(st1);
}

class Date6
{
public:
	Date6(int year = 2000, int month = 0, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// d1.Equal(d2)  d1传给了this d2传给了d
	bool Equal(Date6 d) // 隐含了一个this指针,因此只需要一个参数即可比较
	// 如果写成全局函数,那就需要2个参数了,但又不能访问私有成员变量
	{
		return _year == d._day && _month == d._month && _day == d._day;
	}

	void Print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void testDate6()
{
	Date6 d1(2024, 10, 1);
	Date6 d2(2024, 10, 10);
	Date6 d3(2024, 10, 1);
	// 输出 d1 d2 d3
	std::cout << "d1: ";
	d1.Print();
	std::cout << "d2: ";
	d2.Print();
	std::cout << "d3: ";
	d3.Print();

	if (d1.Equal(d2))
	{
		std::cout << "d1 and d2 are equal" << std::endl;
	}
	else
	{
		std::cout << "d1 and d2 are not equal" << std::endl;
	}
}

void testDate01()
{
	Date d1(2023, 7, 27);
	d1 -= 20000;
	d1.print();
	Date d2(d1);
	d2 += -200;
	d2.print();
	d2 -= -200;
	d2.print();

	Date d3(2023, 7, 27);
	d3.print();
	d3++;
	d3.print();
	--d3;
	d3.print();

	int ret1 = d3 - d1;
	std::cout << "diffd3_d1 = " << ret1 << std::endl;

	std::cout << "d3: " << d3 << std::endl
			  << "d2: " << d2 << std::endl;
	std::cin >> d3;
	std::cout << "d3: " << d3 << std::endl;
}

#if 0
class A
{
public:
	A(int x = 0) // 有默认构造函数
	{
		std::cout << "A(int x = 0)" << std::endl;
		_x = x;
	}

private:
	int _x;
};

#endif

#if 0
class Date2
{
public:
	// 一个对象的单个成员变量，在初始化列表是它的定义的阶段
	Date2(int year = 0, int month = 1, int day = 1)
		: _year(year),
		  _month(month), // 这里的_year _month _day 定义时可以不初始化
		  _n(10),
		  _ref(year)
	{
		_day = day;
	}

private:
	// 这里仅仅是成员变量的声明
	int _year;
	int _month;
	int _day;

	// 它们必须在定义的时候初始化
	const int _n;
	int &_ref;
	A _a; // 自定义类型，会自动调用它的默认构造函数，因此初始化列表里不写也行
};

void testDate2()
{
	Date2 d1;
	Date2 d2(2024, 5, 20);
}
#endif

#if 0

class A
{
public:
	A()
	{
		++totalCreated;
		++activeInstances;
		std::cout << "构造函数调用，当前活跃对象: " << activeInstances << std::endl;
	}

	A(const A &a)
	{
		++totalCreated;
		++activeInstances;
		std::cout << "拷贝构造函数调用，当前活跃对象: " << activeInstances << std::endl;
	}

	~A()
	{
		--activeInstances;
		std::cout << "析构函数调用，当前活跃对象: " << activeInstances << std::endl;
	}

	static int getTotalCreated()
	{
		return totalCreated;
	}

	// 静态成员函数，没有 this 指针
	static int getActiveInstances()
	{
		return activeInstances;
	}

private:
	// 静态成员变量声明
	static int totalCreated;	// 累计创建的对象总数
	static int activeInstances; // 当前活跃的对象数量
};

// 静态成员变量定义和初始化
int A::totalCreated = 0;
int A::activeInstances = 0;

A f(A a)
{
	std::cout << "进入f函数，参数传递后活跃对象: " << A().getActiveInstances() << std::endl;
	return a;
}

#if 0
void testStaticMember()
{
	std::cout << "=== 开始测试 ===" << std::endl;

	// 创建a1和a2
	A a1;
	A a2;
	std::cout << "创建a1和a2后，活跃对象: " << A::activeInstances << std::endl;

	// 临时对象
	{
		A();
		std::cout << "临时对象析构后，活跃对象: " << A::activeInstances << std::endl;
	}

	// 函数调用测试
	std::cout << "=== 测试f(a1) ===" << std::endl;
	// a1 传给 f的形参拷贝构造一次，f 函数传值返回又有一次拷贝构造
	f(a1);
	std::cout << "f(a1)调用结束后，活跃对象: " << A::activeInstances << std::endl;

	// 输出各种信息
	std::cout << "\n=== 最终统计 ===" << std::endl;
	std::cout << "类A的大小: " << sizeof(A) << std::endl;
	std::cout << "累计创建对象总数: " << A::totalCreated << std::endl;
	std::cout << "a1对象访问totalCreated: " << a1.totalCreated << std::endl;
	std::cout << "a2对象访问totalCreated: " << a2.totalCreated << std::endl;

	// 临时对象测试
	std::cout << "\n=== 临时对象测试 ===" << std::endl;
	std::cout << "创建临时对象，其totalCreated值: " << A().totalCreated << std::endl;
	std::cout << "临时对象析构后，活跃对象: " << A::activeInstances << std::endl;

	std::cout << "=== 测试结束 ===" << std::endl;
}
#endif

void testStaticMember2()
{
	A a1;
	A a2;
	// 对象调用
	std::cout << "a1: " << a1.getTotalCreated() << std::endl;
	std::cout << "a2: " << a2.getTotalCreated() << std::endl;
	// 类域调用
	std::cout << "A::" << A::getTotalCreated() << std::endl;
	// 匿名对象调用
	std::cout << "A()" << A().getTotalCreated() << std::endl;
}

#endif

#if 1

class A
{
public:
	// 普通构造函数
	A(int a = 0)
		: _a(a)
	{
		std::cout << "普通构造函数被调用" << std::endl;
	}

	// 拷贝构造函数
	A(const A &other) : _a(other._a)
	{
		std::cout << "拷贝构造函数被调用" << std::endl;
	}

	// 析构函数
	~A()
	{
		std::cout << "析构函数被调用，_a = " << _a << std::endl;
	}

	// Print必须加const，不然const对象不能不能调用 非const成员函数
	void Print() const
	{
		std::cout << "Print->" << _a << std::endl;
	}

private:
	int _a;
};

void f1(const A &aa)
{
	// 使用引用传参，只是给已存在的对象起了一个别名，而不是创建一个新的对象，所以不会调用拷贝构造函数
	aa.Print();
}

A f2()
{
	return 1;
	// 正常是要用 1 去构造，然后再拷贝构造给临时对象，
}

void test()
{
	// 调用普通构造函数创建对象aa1
	A aa1;
	f1(aa1);
	std::cout << "=======================" << std::endl;

	// 调用普通构造函数创建匿名对象，由于 f1 形参是 const & ，减少了一次拷贝构造
	// 既构造又拷贝构造，编译器直接优化成了构造
	f1(A(1));
	std::cout << "=======================" << std::endl;

	// 这里会发生隐式类型转换，int类型的2通过A的普通构造函数转换为A类型的临时对象
	// 由于const & ，减少了一次拷贝构造
	// 隐式类型转换，先构造，再拷贝构造，会被编译器优化成一次构造
	f1(2);
	std::cout << "=======================" << std::endl;

	// const引用会延迟匿名对象生命周期
	const A &ref = A(3);
	f1(ref);
	std::cout << "=======================" << std::endl;
}

void test2()
{
	A aa1 = f2(); // 临时对象再拷贝构造给 aa1 的
	std::cout << "=======================" << std::endl;
	A aa2 = 1;
	std::cout << "=======================" << std::endl;
	A aa3 = A(3);
}

#endif

int main()
{

	// testPerson();
	// testStack();
	// testDateClass();
	// testClassMemory();
	// testStackCopy();
	// testDate6();
	// testDate01();
	// testDate2();
	// testStaticMember2();

	test2();

	return 0;
}
