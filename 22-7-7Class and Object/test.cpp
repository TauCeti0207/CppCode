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
//    //һ������ĵ�����Ա�������ڳ�ʼ���б������Ķ���Ľ׶�
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
//    // ��������ǳ�Ա����������
//    // ����ʱ���Գ�ʼ����Ҳ���Բ���ʼ���������ٸ�ֵ�޸ľ��С�
//    int _year;
//    int _month;
//    int _day;
//
//    //���Ǳ����ڶ����ʱ���ʼ��
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
//// ɶҲ��д�����������Զ�����MyQueu��Ĭ�Ϲ��캯����
//// �������Ͳ��������Զ�������ȥ�����Զ������͵�Ĭ�Ϲ��졣
//class MyQueue
//{
//public:
//	// дһ�����캯������ɶҲ��������Ȼ�Ƕ��������Ͳ��������Զ������͵�������Ĭ�Ϲ���
//	// ��Ϊ��ʼ���б���Ƕ����Ա�����ĵط��������MyQueue�ĳ�ʼ���б�ɶҲû�У�
//	// Ҫ����Զ������Ͷ���Ķ��壬����Ҫ��������Ĭ�Ϲ��캯��
//	MyQueue()
//	{
//
//	}
//private:
//	Stack _st1;
//	Stack _st2;
//	int _size = 0; // ȱʡֵ
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
//    //��ֻ�����������ڹ��캯����ʼ����������ȫ��λ�ó�ʼ��
//    static int _n;
//};
////��̬��Ա��������
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
//        _a = 0; // ��̬��Ա�������ܷ��ʷǾ�̬��Ա��������Ϊû��thisָ��
//        return _n;
//    }
//private:
//    static int _n;
//    int _a;
//};
////��̬��Ա���������ʼ��
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
//    cout << A().GetN() << endl; // ��һ�ε����˹��캯��
//    cout << A::GetN() << endl;
//    return 0;
//}

//class Date; // ǰ������
//class Time
//{
//	// ��ȥǰ����Date�࣬�Ҳ����ͻᱨ����˼�һ��ǰ������
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
//    // 4��һ���Ұ��겻�󣬻���400����
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    assert(year >= 0 && month > 0 && month < 13);
//    const static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    int day = dayArray[month];
//    if (month == 2 && IsLeapYear(year))
//    {
//        //�ж�˳�򽻻�һ�£�ֻ��2�²���Ҫ�ж��Ƿ������꣬���Ч��
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
//    // ��С�Ĳ���++��ֱ���ʹ�����
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
//    // ���������������Ĺ涨����֮�������Ϊ����
//    if (count == 1)
//    {
//        count++;
//    }
//    cout << count + 1 << endl;
//    return 0;
//}


//bool IsLeapYear(int year)
//{
//    // 4��һ���Ұ��겻�󣬻���400����
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    const static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    int day = dayArray[month];
//    if (month == 2 && IsLeapYear(year))
//    {
//        //�ж�˳�򽻻�һ�£�ֻ��2�²���Ҫ�ж��Ƿ������꣬���Ч��
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
// ��������

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
	Weight v(u); // ��������
	Weight w = v;// ��������ʽת������������

	return w;// ��ֵ���أ���������
}

int main()
{
	//Weight x;
	//fun(x); // ��ֵ���Σ��������� �ܹ�4�ο�������

	//fun(Weight());
	//// �����ı�������ѹ��죬�ٿ�������Ĳ���ʡ�ԣ�ֱ�ӹ��졣

	//Weight x;
	//Weight ret = fun(x);
	//// �����Ŀ�������Ҳ�ᱻ�Ż���һ����������

	//Weight x;
	//Weight ret;
	//ret = fun(x);

	Weight x;
	Weight y = fun(fun(x)); // �ܹ�9�Σ��������Ż�����2�Σ�������7��
	return 0;
}

#include<iostream>

using namespace std;

/*

*˼·��

* 1. ͨ��ö��ÿ���µ�1������һ��ĵڼ��죬�Ӷ������ۼ���ͼ��ɣ�����ע������Ĵ���

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