// #include <iostream>
// using namespace std;

// // int main(int argc, char const *argv[])
// // {

// //     return 0;
// // }

// typedef int STDataType;

// // // c语言
// // // 数据
// // struct Stack
// // {
// // 	STDataType* a;
// // 	int size;
// // 	int capacity;
// // };
// // // 函数方法 -- 数据和方法是分离的，重点关注的是过程-》函数方法
// // void StackPush(struct Stack* ps, STDataType x);

// // C++
// // 类  -定义出一个新的类型
// // 类由两部分构成：1、成员变量 (属性) 2、成员函数 (做的行为)
// // C++中的struct兼容C的所有用法，同时C++中把struct升级成类
// // struct Stack
// // {
// // 	void Init(int initSize = 4)
// // 	{
// // 		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
// // 		size = 0;
// // 		capacity = initSize;
// // 	}

// // 	void Push(STDataType x)
// // 	{
// // 		// ...
// // 		a[size] = x;
// // 		size++;
// // 	}

// // 	// ...

// // 	STDataType* a;
// // 	int size;
// // 	int capacity;
// // };

// // int main()
// // {
// // 	//struct Stack st;
// // 	Stack st;
// // 	st.Init();
// // 	st.Push(1);
// // 	st.Push(2);
// // 	st.Push(3);

// // 	return 0;
// // }

// class Stack
// {
// public:
// 	void Init(int initSize = 4);
// 	void Push(STDataType x);

// 	// ...
// private:
// 	STDataType *a;
// 	int size;
// 	int capacity;
// };
// void Stack::Init(int initSize)
// {
// 	a = (STDataType *)malloc(sizeof(STDataType) * initSize);
// 	size = 0;
// 	capacity = initSize;
// }

// void Stack::Push(STDataType x)
// {
// 	// ...
// 	a[size] = x;
// 	size++;
// }

// void test()
// {
// 	// struct Stack st;
// 	Stack st;
// 	st.Init();
// 	st.Push(1);
// 	st.Push(2);
// 	st.Push(3);

// 	Stack st2;
// 	cout << sizeof(st) << endl;	 // 16
// 	cout << sizeof(st2) << endl; // 16 64位环境下
// }

// //空类
// class A2
// {
// };
// //类中仅有成员函数
// class A3
// {
// public:
// 	void f2()
// 	{
// 	}
// };
// void test2()
// {
// 	A2 a2;
// 	A3 a3;
// 	cout << sizeof(a2) << endl; // 1
// 	cout << sizeof(a3) << endl; // 1
// }

// class Date9
// {
// private:
// 	//凡是成员变量,建议区分命名风格
// 	int _year;
// 	int _month;
// 	int _day;

// public:
// 	//编译器会增加一个隐含的参数void Init(Date* this, int year,int month, int day)
// 	// 1.this指针是隐含的,我们不能显性的在调用和函数定义中加
// 	// 2.但我们可以在成员函数总使用this指针
// 	// 3.this是形参,一般是存在栈上的,不同的编译器不同,vs是使用ecx寄存器存储,传参
// 	void Init(int year, int month, int day)
// 	{
// 		//检查日期合法性
// 		//...
// 		//不写this,编译器也会自动加上
// 		// _year = year;
// 		// _month = month;
// 		// _day = day;
// 		//编译器会处理成:
// 		this->_year = year;
// 		this->_month = month;
// 		this->_day = day;
// 		cout << "this:" << this << endl;
// 	}
// };

// void test3()
// {
// 	Date d1;
// 	d1.Init(2021, 2, 21); //编译器会处理成 d1.Init(&d1, 2021, 2, 21)
// 	cout << "d1:" << &d1 << endl;
// 	Date d2;
// 	d2.Init(2021, 2, 22); //编译器会处理成 d2.Init(&d2, 2021, 2, 22)
// 	cout << "d2:" << &d2 << endl;
// }

// // int main()
// // {
// // 	test3();
// // 	return 0;
// // }

// // 1.下面程序能编译通过吗？
// // 2.下面程序会崩溃吗？在哪里崩溃
// // class A
// // {
// // public:
// // 	void PrintA()
// // 	{
// // 		cout << _a << endl;
// // 	}

// // 	void Show()
// // 	{
// // 		cout << "Show()" << endl;
// // 	}
// // private:
// // 	int _a;
// // };

// // int main()
// // {
// // 	A* p = nullptr;
// // 	// p->PrintA(); // 空指针
// // 	p->Show();     // 正常运行
// // }

// // 1.构造函数 --> 对象初始化 顶替Init()
// //我们有时可能会忘记初始化对象,就去使用它,C++为了解决这个缺陷,引入了构造函数
// //
// class Date2
// {
// private:
// 	int _year;
// 	int _month;
// 	int _day;

// public:
// 	//构造函数 对象实例化的时候自动调用,保证对象的初始化
// 	//一般情况,对象初始化分为默认值初始化和给定值初始化
// 	//利用全缺省参数,将2者合二为一
// 	Date2(int year = 2020, int month = 1, int day = 1)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}
// 	// Date2(int year, int month, int day)
// 	// {
// 	// 	_year = year;
// 	// 	_month = month;
// 	// 	_day = day;
// 	// }
// 	// //Date2重载
// 	// Date2()
// 	// {
// 	// 	_year = 2000;
// 	// 	_month = 1;
// 	// 	_day = 1;
// 	// }
// 	void Print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}
// };

// void test4()
// {
// 	Date2 d1(2022, 2, 21);
// 	d1.Print(); // 2022-2-21

// 	Date2 d2(2022);
// 	d2.Print(); // 2022-1-1

// 	Date2 d3;
// 	d3.Print(); // 2000-1-1
// }
// // int main(int argc, char const *argv[])
// // {
// // 	test4();
// // 	return 0;
// // }

// class A
// {
// public:
// 	A(int a = 0)
// 	{
// 		cout << "A(int a = 0)构造函数" << endl;
// 		_a = a;
// 	}

// 	void Print()
// 	{
// 		cout << _a << endl;
// 	}

// private:
// 	int _a;
// };

// class Date4
// {
// public:
// 	// 我们不写，编译器会生成一个构造函数，我们写了编译器就不会生成了。所以说构造函数叫默认成员函数

// 	void Print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 		_aa.Print();
// 	}

// private:
// 	int _year;
// 	int _month;
// 	int _day;

// 	A _aa;
// };

// // int main()
// // {
// // 	Date4 d2;
// // 	d2.Print();

// // 	return 0;
// // }
// class Stack2
// {
// private:
// 	int *_a;
// 	int _size;
// 	int _capacity;

// public:
// 	Stack2(int capacity = 4);
// 	~Stack2();
// 	void Push(int x)
// 	{
// 	}
// };

// Stack2::Stack2(int capacity)
// {
// 	_a = (int *)malloc(sizeof(int) * capacity);
// 	_size = 0;
// 	_capacity = capacity;
// }

// Stack2::~Stack2()
// {
// 	cout << "Stack2::~Stack2() 析构函数" << endl;
// 	free(_a);
// 	_a = nullptr;
// 	_size = _capacity = 0;
// }
// // int main(int argc, char const *argv[])
// // {
// // 	Stack2 st1;
// // 	st1.Push(1);
// // 	st1.Push(2);
// // 	st1.Push(3);

// // 	Stack2 st2;
// // 	st2.Push(1);
// // 	st2.Push(2);
// // 	st2.Push(3);
// // 	return 0;
// // }//运行到这里,也就是对象的生命周期结束之后才自动调用析构函数的
// // //调试时只能看到当前作用域的变量,因此可以借助this指针观察

// class Date5
// {
// public:
// private:
// 	int _year;
// 	int _month;
// 	int _day;

// 	Stack2 _st;
// };

// // int main(int argc, char const *argv[])
// // {
// // 	Date5 d;//Stack2::~Stack2() 析构函数
// // 	return 0;
// // }
// // class Date6
// // {
// // public:
// // 	Date6(int year = 2000, int month = 0, int day = 0)
// // 	{
// // 		_year = year;
// // 		_month = month;
// // 		_day = day;
// // 	}

// // 	//d1.Equal(d2)  d1传给了this d2传给了d
// // 	bool Equal(Date6 d) //隐含了一个this指针,因此只需要一个参数即可比较
// // 	//如果写成全局函数,那就需要2个参数了,但又不能访问私有成员变量
// // 	{
// // 		return _year == d._day && _month == d._month && _day == d._day;
// // 	}

// // private:
// // 	int _year;
// // 	int _month;
// // 	int _day;
// // };

// // int main(int argc, char const *argv[])
// // {
// // 	Date6 d1(2022, 2, 22);
// // 	Date6 d2(2022, 2, 21);
// // 	cout << d1.Equal(d2) << endl;//0
// // 	return 0;
// // }

// class Date6
// {
// public:
// 	Date6(int year = 2000, int month = 0, int day = 0)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}

// 	bool operator==(Date6 d) //隐含了一个this指针,因此只需要一个参数即可比较
// 	//如果写成全局函数,那就需要2个参数了,但又不能访问私有成员变量
// 	{
// 		return _year == d._day && _month == d._month && _day == d._day;
// 	}
// 	bool operator<(Date6 d)
// 	{
// 		if (_year < d._year)
// 		{
// 			return true;
// 		}
// 		else if (_year == d._year)
// 		{
// 			if (_month < d._month)
// 			{
// 				return true;
// 			}
// 			else if (_month == d._month)
// 			{
// 				if (_day < d._day)
// 				{
// 					return true;
// 				}
// 			}
// 		}
// 		return false;
// 	}
// 	// d1 - 100
//
// 	// d1 + 100

// 	// d1 - d2
// 	int operator-(Date6 d)
// 	{
// 	}

// private:
// 	int _year;
// 	int _month;
// 	int _day;
// };

// class Array
// {
// private:
// 	int _a[10];

// public:
// 	Array()
// 	{
// 		for (size_t i = 0; i < 10; i++)
// 		{
// 			_a[i] = i * 10;
// 		}
// 	}
// 	int &operator[](size_t pos)
// 	{
// 		return _a[pos]; //返回的是别名(引用)
// 	}
// };

// // int main(int argc, char const *argv[])
// // {
// // 	Date6 d1(2022, 2, 22);
// // 	Date6 d2(2022, 2, 21);
// // 	cout << d1.operator==(d2) << endl; // 0
// // 	//编译器会把 d1.operator==(d2) 转换成 d1.operator==(&d1, d2)
// // 	int tmp = d1 == d2;
// // 	//编译器会把 d1==d2 转换成 d1.operator==(&d1, d2)
// // 	cout << tmp << endl;	   // 0
// // 	cout << (d1 < d2) << endl; // 0

// // 	Array ay;
// // 	cout << ay[0] << endl;//转换成 ay.operator[](&ay, 0);
// // 	cout << ay[1] << endl;
// // 	cout << ay[2] << endl;
// // 	cout << ay[3] << endl;

// // 	//修改 -- 赋值给了返回对象的别名
// // 	ay[0] = 100;
// // 	ay[1] = 200;
// // 	ay[2] = 300;
// // 	ay[3] = 400;

// // 	cout << ay[0] << endl;//转换成 ay.operator[](&ay, 0);
// // 	cout << ay[1] << endl;
// // 	cout << ay[2] << endl;
// // 	cout << ay[3] << endl;
// // 	return 0;
// // }

// // class Date7
// // {
// // public:
// // 	// 我们不写，编译器会生成一个构造函数，我们写了编译器就不会生成了。所以说构造函数叫默认成员函数
// // 	Date7(int year = 2000, int month = 1, int day = 1)
// // 	{
// // 		_year = year;
// // 		_month = month;
// // 		_day = day;
// // 	}
// // 	void Print()
// // 	{
// // 		cout << _year << "-" << _month << "-" << _day << endl;
// // 	}
// // 	//Date7 d4(d1);  拷贝构造函数
// // 	// Date7(Date7& d)//d4 传给this d1传给d
// // 	// {
// // 	// 	_year = d._year;
// // 	// 	_month = d._month;
// // 	// 	_day = d._day;
// // 	// }

// // private:
// // 	int _year;
// // 	int _month;
// // 	int _day;

// // 	A4 _aa;
// // };
// // void f1(Date7 d)
// // {

// // }

// // void f2(Date7& d)
// // {

// // }
// class A4
// {
// public:
// 	A4(int a = 1)
// 	{
// 		cout << "A(int a = 1)构造函数" << endl;
// 		_a = a;
// 	}
// 	A4(const A4 &a)
// 	{
// 		cout << "A4(const A4& a) 拷贝构造" << endl;
// 		_a = a._a;
// 	}
// 	~A4()
// 	{
// 		cout << "~A4() 析构函数" << endl;
// 	}

// private:
// 	int _a;
// };
// class Date7
// {
// public:
// 	// 我们不写，编译器会生成一个构造函数，我们写了编译器就不会生成了。所以说构造函数叫默认成员函数
// 	Date7(int year = 2000, int month = 1, int day = 1)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}
// 	void Print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}
// 	// Date7 d4(d1);  拷贝构造函数
// 	//  Date7(Date7& d)//d4 传给this d1传给d
// 	//  {
// 	//  	_year = d._year;
// 	//  	_month = d._month;
// 	//  	_day = d._day;
// 	//  }

// 	// d1 = d2 传引用就无需再去调用拷贝构造
// 	//  Date7 operator=(const Date7& d) // void operator=(Date7* this, const Date7& d)
// 	//  {
// 	//  	_year = d._year;
// 	//  	_month = d._month;
// 	//  	_day = d._day;
// 	//  	return *this;
// 	//  }

// private:
// 	int _year;
// 	int _month;
// 	int _day;

// 	A4 _aa;
// };
// // int main(int argc, char const *argv[])
// // {
// // 	//  Date7 d1(2022,2,21);
// // 	// Date7 d2;
// // 	// //Date7 d3();  不能这样写，这样变成了函数声明，并没有去构造对象

// // 	// //如果想复制d1的值
// // 	// Date7 d4(d1);//拷贝构造

// // 	// d1.Print();//2022-2-21
// // 	// d2.Print();//2000-1-1
// // 	// d4.Print();//2022-2-21
// // 	// Date7 d1(2022,2,21);
// // 	// f1(d1);
// // 	// f2(d1);

// // 	// Date7 d4(d1);//拷贝构造
// // 	// d1.Print();
// // 	// d4.Print();

// // 	Date7 d1(2022, 2, 21);
// // 	Date7 d2;

// // 	//这样也是拷贝行为，但不一样的是，拷贝构造是创建一个对象时，拿同类对象初始化的拷贝
// // 	//这里的复制拷贝时，两个对象已经存在，都被初始化过了，现在是想把一个对象，复制拷贝给另一个对象
// // 	d2 = d1;
// // 	d1.Print(); // 2000-1-1
// // 	d2.Print(); // 2000-1-1
// // 	system("pause");
// // 	return 0;
// // }

#include "Date.h"
void Test1()
{
	Date d(2021, 0, 29);
	d.Print();
	Date d2(2021, 0, 29);
	d2.Print();
}
void Test2()
{
	Date d1(2022,2,22);
	d1.Print();
	d1 += 3;
	d1.Print();
	Date d2 = d1 + 1;
	d2.Print();//2-26
	Date d3 = d2++;//2-26 d2已经变成2-27了
	d2.Print();
	d3.Print();
	Date d4 = ++d2;
	d4.Print();//2-28
	d4 -= 2;
	d4.Print();
	d4 -= 26;
	d4.Print();
	Date d5(2021,5,27);
	d5 -= -100;
	d5.Print();
}
void Test3()
{
	Date d1(2022,2,22);
	Date d2(2023,1,1);
	cout << d1-d2 << endl;
}
int main(int argc, char const *argv[])
{
	Test3();
	system("pause");
	return 0;
}
