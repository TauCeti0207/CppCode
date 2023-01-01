#pragma once
#include <iostream>
#include <assert.h>
//��Ŀ����ò�Ҫ�������ռ� using namespace std��ֻ��չ�����õľ���
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
    //�������������죬��ֵ���ز���Ҫд��Ĭ�����ɾ͹�����

    //d += 100
    Date& operator+=(int day);
    Date operator+(int day);
    //d -= 100
    Date& operator-=(int day);
    Date operator-(int day);
    Date& operator++();//ǰ��++
    Date operator++(int);//����++
    Date& operator--();//ǰ��--
    Date operator--(int);//����--
    bool operator==(const Date& d);
    bool operator>=(const Date& d);
    bool operator<=(const Date& d);
    bool operator!=(const Date& d);
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    //�������
    int operator-(const Date& d);
};




