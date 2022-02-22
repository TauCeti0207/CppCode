#include "Date.h"

inline int GetMonthDay(int year, int month)
{
    //数组存储平年每个月天数
    //这个函数会被频繁调用，应定义为inline 且数组放在静态区，避免反复开辟
    static int dayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = dayArray[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) // 4年一润且百年不润，或者400年润
    {
        //判断顺序交换一下，只有2月才需要判断是否是闰年，提高效率
        day = 29;
    }
    return day;
}

//缺省参数一般就写在声明中
Date::Date(int year, int month, int day) //构造函数
{
    //检查日期合法性
    if (year >= 0 && month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month))
    {
        _year = year;
        _month = month;
        _day = day;
    }
    else
    {
        cout << "非法日期" << endl;
        assert(false);
    }
}
void Date::Print()
{
    cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

// d += 100 会改变d
Date &Date::operator+=(int day)
{
    if (day < 0)
    {
        *this -= -day;
    }
    else
    {
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            // 1.天满了，减去当月的天数，月+1
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month > 12)
            {
                // 2.月满了，年+1，月置成1
                ++_year;
                _month = 1;
            }
        }
    }
    return *this; //*this 就是加完的年月日
    //这其实实现的功能是 += 而不是 +
}

// d1 + 10
Date Date::operator+(int day)
{
    //创建临时对象
    Date ret(*this); //调用拷贝构造
    //复用operator+=
    ret += day;
    return ret; //临时对象不能用引用返回，出了作用域，临时对象就销毁了
}
// d1 -= 100  d1 -= -100
Date &Date::operator-=(int day)
{
    //考虑day是负数
    if (day < 0)
    {
        //复用
        *this += -day;
    }
    else
    {
        _day -= day;
        while (_day <= 0)
        {
            --_month;
            if (_month == 0)
            {
                --_year;
                _month = 12;
            }
            //加上上个月的天数
            int preMonthDay = GetMonthDay(_year, _month);
            _day += preMonthDay;
        }
    }
    return *this;
}

Date Date::operator-(int day)
{
    // Date tmp = *this;
    Date tmp(*this);
    tmp -= day;
    return tmp;
}

// ++d & d++
Date &Date::operator++() //前置++ d++ ++d 不同的在于返回值不同
{
    *this += 1;
    return *this; //前置++是先++
}

Date Date::operator++(int) //后置++  C++之父规定的
{
    // int 参数不需要给实参，因为只是为了构成重载，从而区分前置++ 和后置++而已
    Date tmp(*this);
    *this += 1;
    return tmp; //后置++ 先使用d再++ 返回的是++之前的值
}

Date &Date::operator--() //前置--
{
    *this -= 1;
    return *this;
}

Date Date::operator--(int) //后置--
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

//只需要先实现一个> == 剩下的都可以去复用
bool Date::operator==(const Date &d)
{
    if (_year == d._year && _month == d._month && _day == d._day)
    {
        return true;
    }
    return false;
}
bool Date::operator<(const Date &d)
{
    if ((_year < d._year) ||
        (_year == d._year && _month < d._month) ||
        (_year == d._year && _month == d._month && _day < d._day))
        return true;
    return false;
}

bool Date::operator>=(const Date &d)
{
    return !(*this < d);
}
bool Date::operator<=(const Date &d)
{
    return ((*this < d) || (*this == d));
}
bool Date::operator!=(const Date &d)
{
    return !(*this == d);
}
bool Date::operator>(const Date &d)
{
    return !(*this <= d);
}

//d1 - d2
int Date::operator-(const Date &d)
{
    //思路：让小的不断++，直到==max
    Date max = *this;
    Date min = d;
    int flag = 1;
    if (*this < d)
    {
        //判断错误
        max = d;
        min = *this;
        flag = -1;
    }
    int count = 0;
    while (min != max)
    {
        ++min;
        ++count;
    }
    return count*flag;
}