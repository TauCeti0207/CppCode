#pragma once
#include <iostream>
#include <assert.h>
//项目中最好不要改命名空间 using namespace std；只需展开常用的就行
using std::cout;
using std::cin;
using std::endl;
class Date
{
private:
    int _year;
    int _month;
    int _day;
public:
    Date(int year = 0, int month = 1, int day = 1);
    void Print();
    //析构，拷贝构造，赋值重载不需要写，默认生成就够用了

    //d += 100
    Date& operator+=(int day);
    Date operator+(int day);
    //d -= 100
    Date& operator-=(int day);
    Date operator-(int day);
    Date& operator++();//前置++
    Date operator++(int);//后置++
    Date& operator--();//前置--
    Date operator--(int);//后置--
    bool operator==(const Date& d);
    bool operator>=(const Date& d);
    bool operator<=(const Date& d);
    bool operator!=(const Date& d);
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    //日期相减
    int operator-(const Date& d);
};




