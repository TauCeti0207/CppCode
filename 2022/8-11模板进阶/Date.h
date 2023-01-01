#pragma once
#include <iostream>
#include <assert.h>
// 项目中最好不要改命名空间 using namespace std；只需展开常用的就行
using std::cout;
using std::cin;
using std::endl;
class Date
{
    friend std::ostream& operator<<(std::ostream& out, const Date& d);
    friend std::istream& operator>>(std::istream& in, Date& d);
private:
    int _year;
    int _month;
    int _day;
public:
    bool IsLeapYear(int year)
    {
        // 4年一润且百年不润，或者400年润
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    int GetMonthDay(int year, int month);
    //构造函数
    Date(int year = 1, int month = 1, int day = 1);
    void Print() const;
    //析构，拷贝构造，赋值重载不需要写，默认生成就够用了
    //Date(const Date& d)
    //{
    //    _year = d._year;
    //    _month = d._month;
    //    _day = d._day;
    //}

    //Date& operator=(const Date& d)
    //{
    //    if (this != &d)
    //    {
    //        _year = d._year;
    //        _month = d._month;
    //        _day = d._day;
    //    }
    //    return *this;
    //}
    //d += 100
    Date& operator+=(int day); // +=会修改this指向的内容，不能加const
    Date operator+(int day) const;
    //d -= 100
    Date& operator-=(int day);
    Date operator-(int day) const;
    Date& operator++();//前置++
    Date operator++(int);//后置++
    Date& operator--();//前置--
    Date operator--(int);//后置--
    bool operator==(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator!=(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator<(const Date& d) const;
    //日期相减
    int operator-(const Date& d) const;
};