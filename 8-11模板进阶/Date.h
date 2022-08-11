#pragma once
#include <iostream>
#include <assert.h>
// ��Ŀ����ò�Ҫ�������ռ� using namespace std��ֻ��չ�����õľ���
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
        // 4��һ���Ұ��겻�󣬻���400����
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    int GetMonthDay(int year, int month);
    //���캯��
    Date(int year = 1, int month = 1, int day = 1);
    void Print() const;
    //�������������죬��ֵ���ز���Ҫд��Ĭ�����ɾ͹�����
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
    Date& operator+=(int day); // +=���޸�thisָ������ݣ����ܼ�const
    Date operator+(int day) const;
    //d -= 100
    Date& operator-=(int day);
    Date operator-(int day) const;
    Date& operator++();//ǰ��++
    Date operator++(int);//����++
    Date& operator--();//ǰ��--
    Date operator--(int);//����--
    bool operator==(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator!=(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator<(const Date& d) const;
    //�������
    int operator-(const Date& d) const;
};