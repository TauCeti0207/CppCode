#include <iostream>
#include <assert.h>
using namespace std;
//class A
//{
//public:
//    A(int x)
//    {
//        cout << "A(int x = 0)" << endl;
//        _x = x;
//    }
//
//private:
//    int _x;
//};
//
//class Date
//{
//public:
//    //一个对象的单个成员变量，在初始化列表是它的定义的阶段
//    Date(int year, int month, int day, int n, int ref, int a)
//        :_n(n)
//        ,_ref(ref)
//        ,_aa(a)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//        A aa(a);
//        _aa = aa;
//    }
//private:
//    // 这里仅仅是成员变量的声明
//    // 定义时可以初始化，也可以不初始化，后面再赋值修改就行。
//    int _year;
//    int _month;
//    int _day;
//
//    //它们必须在定义的时候初始化
//    const int _n;
//    int& _ref;
//    A _aa;
//};
//
//int main()
//{
//    Date d1(2022, 2, 2, 1, 1, 1);
//    return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 0)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		assert(_a);
//		_top = 0;
//		_capacity = capacity;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//// 啥也不写，编译器会自动调用MyQueu的默认构造函数，
//// 内置类型不做处理，自定义类型去调用自定义类型的默认构造。
//class MyQueue
//{
//public:
//	// 写一个构造函数，但啥也不做，依然是对内置类型不做处理，自定义类型调用它的默认构造
//	// 因为初始化列表才是定义成员变量的地方，而这个MyQueue的初始化列表啥也没有，
//	// 要完成自定义类型对象的定义，就需要调用它的默认构造函数
//	MyQueue()
//	{
//
//	}
//private:
//	Stack _st1;
//	Stack _st2;
//	int _size = 0; // 缺省值
//};
//int main()
//{
//	MyQueue mq;
//	return 0;
//}

//class A
//{
//private:
//    int _a;
//
//public:
//    A(int a) 
//        : _a(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//    A(const A& aa) 
//    {
//        cout << " A(const A& aa)" << endl;
//    }
//};
//int main(int argc, char const* argv[])
//{
//    A aa1(1);
//    A aa2(aa1); 
//    const A& aa3 = 2; 
//
//    return 0;
//}

//class A
//{
//public:
//    A()
//    {
//        ++_n;
//    }
//    A(const A& a)
//    {
//        ++_n;
//    }
//    //private:
//    //这只是声明，不在构造函数初始化，在类外全局位置初始化
//    static int _n;
//};
////静态成员变量定义
//int A::_n = 0;
//void f(A a)
//{
//
//}
//int main(int argc, char const* argv[])
//{
//    A a1;
//    A a2;
//    A();
//    f(a1);
//    cout << sizeof(A) << endl;
//    cout << A::_n << endl;
//    cout << a1._n << endl;
//    cout << a2._n << endl;
//    cout << A()._n << endl;
//    return 0;
//}

//class A
//{
//public:
//    A()
//    {
//        ++_n;
//    }
//    A(const A& a)
//    {
//        ++_n;
//    }
//    static int GetN()
//    {
//        _a = 0; // 静态成员函数不能访问非静态成员变量，因为没有this指针
//        return _n;
//    }
//private:
//    static int _n;
//    int _a;
//};
////静态成员变量定义初始化
//int A::_n = 0;
//void f(A a)
//{
//
//}
//int main(int argc, char const* argv[])
//{
//    A a1;
//    A a2;
//    A();
//    f(a1);
//    cout << sizeof(A) << endl;
//    cout << a1.GetN() << endl;
//    cout << a2.GetN() << endl;
//    cout << A().GetN() << endl; // 又一次调用了构造函数
//    cout << A::GetN() << endl;
//    return 0;
//}

//class Date; // 前置声明
//class Time
//{
//	// 会去前面找Date类，找不到就会报错，因此加一个前置声明
//	friend void Func(const Date& d, const Time& t);
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//	friend void Func(const Date& d, const Time& t);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Func(const Date& d, const Time& t)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//	cout << t._hour << "-" << t._minute << "-" << t._second << endl;
//
//}
//int main()
//{
//	Date d1;
//	Time t1;
//	Func(d1, t1);
//	return 0;
//}

//#include <assert.h>
//
//
//bool IsLeapYear(int year)
//{
//    // 4年一润且百年不润，或者400年润
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    assert(year >= 0 && month > 0 && month < 13);
//    const static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    int day = dayArray[month];
//    if (month == 2 && IsLeapYear(year))
//    {
//        //判断顺序交换一下，只有2月才需要判断是否是闰年，提高效率
//        day = 29;
//    }
//    return day;
//}
//int main()
//{
//    int year1, month1, day1;
//    int year2, month2, day2;
//    scanf_s("%4d%2d%2d", &year1, &month1, &day1);
//    scanf_s("%4d%2d%2d", &year2, &month2, &day2);
//    // 让小的不断++，直到和大的相等
//    int maxYear = year1, minYear = year2;
//    int maxMonth = month1, minMonth = month2;
//    int maxDay = day1, minDay = day2;
//    int count = 0;
//    if (year1 < year2
//        || year1 == year2 && month1 < month2
//        || year1 == year2 && month1 == month2 && day1 < day2)
//    {
//        maxYear = year2, maxMonth = month2, maxDay = day2;
//        minYear = year1, minMonth = month1, minDay = day1;
//    }
//
//    while (minYear != maxYear || minMonth != maxMonth || minDay != maxDay)
//    {
//        ++minDay;
//        ++count;
//        if (minDay > GetMonthDay(minYear, minMonth))
//            minMonth++, minDay = 1;
//        if (minMonth > 12)
//            minMonth = 1, minYear++;
//    }
//    // 两个日期是连续的规定他们之间的天数为两天
//    if (count == 1)
//    {
//        count++;
//    }
//    cout << count + 1 << endl;
//    return 0;
//}


//bool IsLeapYear(int year)
//{
//    // 4年一润且百年不润，或者400年润
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    const static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    int day = dayArray[month];
//    if (month == 2 && IsLeapYear(year))
//    {
//        //判断顺序交换一下，只有2月才需要判断是否是闰年，提高效率
//        day = 29;
//    }
//    return day;
//}
//int main()
//{
//    int row;
//    int year, month, day, num;
//    cin >> row;
//    while (row--)
//    {
//        cin >> year >> month >> day >> num;
//        day += num;
//        while (day > GetMonthDay(year, month))
//        {
//            day -= GetMonthDay(year, month);
//            ++month;
//            if (month > 12)
//            {
//                month = 1;
//                ++year;
//            }
//        }
//        printf("%04d-%02d-%02d\n", year, month, day);
//    }
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////
// 匿名对象

class Weight
{
public:
	Weight()
	{
		cout << "Weight()" << endl;
	}
	Weight(const Weight& w)
	{
		cout << "Weight(const Weight& w)" << endl;
	}
	Weight& operator=(const Weight& w)
	{
		cout << "Weight& operator=(const Weight& w)" << endl;
		return *this;
	}
	~Weight()
	{
		cout << "~Weight()" << endl;
	}
};

Weight fun(Weight u)
{
	Weight v(u); // 拷贝构造
	Weight w = v;// 单参数隐式转换，拷贝构造

	return w;// 传值返回，拷贝构造
}

int main()
{
	//Weight x;
	//fun(x); // 传值传参，拷贝构造 总共4次拷贝构造

	//fun(Weight());
	//// 激进的编译器会把构造，再拷贝构造的步骤省略，直接构造。

	//Weight x;
	//Weight ret = fun(x);
	//// 连续的拷贝构造也会被优化成一个拷贝构造

	//Weight x;
	//Weight ret;
	//ret = fun(x);

	Weight x;
	Weight y = fun(fun(x)); // 总共9次，编译器优化掉了2次，最终是7次
	return 0;
}

#include<iostream>

using namespace std;

/*

*思路：

* 1. 通过枚举每个月的1号是这一年的第几天，从而进行累加求和即可，其中注意闰年的处理

*/

int main()

{

	int year, month, day;

	while (cin >> year >> month >> day)

	{

		int monthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

		int nday = monthDays[month - 1] + day;

		if (month > 2 &&

			((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))

		{

			nday += 1;

		}
		cout << nday << endl;
	}
	return 0;

}